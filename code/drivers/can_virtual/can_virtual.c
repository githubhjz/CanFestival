/*
This file is part of CanFestival, a library implementing CanOpen Stack. 

Copyright (C): Edouard TISSERANT and Francis DUPIN

See COPYING file for copyrights details.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/*
	Virtual CAN driver.
*/

#include <stdio.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define NEED_PRINT_MESSAGE
#include "can_driver.h"
#include "def.h"

#define MAX_NB_CAN_PIPES 16

typedef struct {
  char used;
#ifdef _WIN32
  PHANDLE pipe[2];
#else
  int pipe[2];
#endif
} CANPipe;

CANPipe canpipes[MAX_NB_CAN_PIPES] = {{0,},{0,},{0,},{0,},{0,},{0,},{0,},{0,},{0,},{0,},{0,},{0,},{0,},{0,},{0,},{0,},};

/*********functions which permit to communicate with the board****************/
UNS8 LIBAPI canReceive_driver(CAN_HANDLE fd0, Message *m)
{
#ifdef _WIN32
	DWORD bytesRead = 0;
	ReadFile(((CANPipe*)fd0)->pipe[0], m, sizeof(Message), &bytesRead, NULL);

	if (bytesRead != sizeof(Message))
	{
		return 1;
	}

#else
	ssize_t bytesRead = read(((CANPipe*)fd0)->pipe[0], m, sizeof(Message));
	if(bytesRead != (ssize_t)sizeof(Message))
	{
		return 1;
	}
#endif
	return 0;
}

/***************************************************************************/
UNS8 LIBAPI canSend_driver(CAN_HANDLE fd0, Message const *m)
{
	int i;

	printf("%lx->[ ", (CANPipe*)fd0 - &canpipes[0]);

	for(i = 0; i < MAX_NB_CAN_PIPES; i++)
	{
		if(canpipes[i].used && &canpipes[i] != (CANPipe*)fd0)
		{
			printf("%x ",i);
		}
	}

	printf(" ]");	
	print_message(m);

	// Send to all readers, except myself
	for (i = 0; i < MAX_NB_CAN_PIPES; i++)
	{
		if (canpipes[i].used && &canpipes[i] != (CANPipe*)fd0)
		{
#ifdef _WIN32
			DWORD bytesWritten;
			WriteFile(canpipes[i].pipe[1], m, sizeof(Message), &bytesWritten, NULL);
#else
			write(canpipes[i].pipe[1], m, sizeof(Message));
#endif
		}
	}

	return 0;
}

/***************************************************************************/
int TranslateBaudRate(char* optarg){
	if(!strcmp( optarg, "1M")) return (int)1000;
	if(!strcmp( optarg, "500K")) return (int)500;
	if(!strcmp( optarg, "250K")) return (int)250;
	if(!strcmp( optarg, "125K")) return (int)125;
	if(!strcmp( optarg, "100K")) return (int)100;
	if(!strcmp( optarg, "50K")) return (int)50;
	if(!strcmp( optarg, "20K")) return (int)20;
	if(!strcmp( optarg, "10K")) return (int)10;
	if(!strcmp( optarg, "5K")) return (int)5;
	if(!strcmp( optarg, "none")) return 0;
	return 0x0000;
}

UNS8 LIBAPI canChangeBaudRate_driver(CAN_HANDLE fd0, char* baud)
{
    printf("%lx-> changing to baud rate %s[%d]\n", (CANPipe*)fd0 - &canpipes[0],baud,TranslateBaudRate(baud)); 
    return 0;
}

/*!	\brief Opens a pipe, if a slot if still available
 *	\return NULL if all slots are filled
 */
CAN_HANDLE LIBAPI canOpen_driver(s_BOARD *board)
{
	int i;  
	for (i = 0; i < MAX_NB_CAN_PIPES; i++)
	{
		if (!canpipes[i].used)
		{
			break;
		}
	}

	/* Create the pipe.  */
	if (i == MAX_NB_CAN_PIPES)
	{
#ifdef _WIN32
		char result = CreatePipe(canpipes[i].pipe[0], canpipes[i].pipe[1], NULL, 0);
#else
		char result = (pipe(canpipes[i].pipe) == 0);
#endif
		if (!result)
		{
			fprintf(stderr, "Open failed.\n");
			return (CAN_HANDLE)NULL;
		}
	}

	canpipes[i].used = 1;
	return (CAN_HANDLE) &canpipes[i];
}

/*!	\brief Closes the pipe handle
 */
int LIBAPI canClose_driver(CAN_HANDLE fd0)
{
	CANPipe* pipeInfo = (CANPipe*)fd0;

#ifdef _WIN32
	CloseHandle(pipeInfo->pipe[0]);
	CloseHandle(pipeInfo->pipe[1]);
#else
	close(pipeInfo->pipe[0]);
	close(pipeInfo->pipe[1]);
#endif

	pipeInfo->used = 0;
	return 0;
}
