/*
This file is part of CanFestival, a library implementing CanOpen Stack.

Copyright (C): Edouard TISSERANT and Francis DUPIN
Win32 Port Leonid Tochinski

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
#ifndef __CANFESTIVAL__
#define __CANFESTIVAL__

#ifdef __cplusplus
extern "C" {
#endif

#include <canfestival/timerscfg.h>
#include <canfestival/can_driver.h>
#include <canfestival/data.h>
#include <canfestival/timers_driver.h>

#ifdef _WIN32

	#include <windows.h>

	typedef HINSTANCE LIB_HANDLE;

	//LIB_HANDLE LoadCanDriver(LPCSTR driver_name);
	
#else

	#ifndef __KERNEL__
	#include <dlfcn.h>
	#endif

	typedef void* LIB_HANDLE;
#endif

/** @defgroup userapi User API */

/** @defgroup can CAN management
 *  @ingroup userapi
 */

/**
 * @ingroup can
 * @brief Unload CAN driver interface
 * @param handle The library handle
 * @return
 *       -  0 is returned upon success.
 *       - -1 is returned if the CAN driver interface can't be unloaded.
 */
UNS8 UnLoadCanDriver(LIB_HANDLE handle);

/**
 * @ingroup can
 * @brief Load CAN driver interface.
 * @param *driver_name The location of the library to load
 * @return
 *       - handle of the CAN driver interface is returned upon success.
 *       - NULL is returned if the CAN driver interface can't be loaded.
 */
LIB_HANDLE LoadCanDriver(const char *driver_name);

/**
 * @brief Send a CAN message
 * @param port CanFestival file descriptor
 * @param *m The CAN message to send
 * @return 0 if succes
 */
UNS8 canSend(CAN_PORT port, Message *m);

/**
 * @ingroup can
 * @brief Open a CANOpen device
 * @param *board Pointer to the board structure that contains busname and baudrate 
 * @param *d Pointer to the CAN object data structure
 * @return
 *       - CanFestival file descriptor is returned upon success.
 *       - NULL is returned if the CANOpen board can't be opened.
 */
CAN_PORT canOpen(s_BOARD *board, CO_Data *d);

/**
 * @ingroup can
 * @brief Close a CANOpen device
 * @param *d Pointer to the CAN object data structure
 * @return
 *       - 0 is returned upon success.
 *       - errorcode if error. (if implemented)  
 */
int canClose(CO_Data *d);

/**
 * @ingroup can
 * @brief Change the CANOpen device baudrate 
 * @param port CanFestival file descriptor 
 * @param *baud The new baudrate to assign
 * @return
 *       - 0 is returned upon success or if not supported by the CAN driver.
 *       - errorcode from the CAN driver is returned if an error occurs. (if implemented in the CAN driver)
 */
UNS8 canChangeBaudRate(CAN_PORT port, char *baud);

#ifdef __cplusplus
};
#endif

#endif
