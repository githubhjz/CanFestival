/*
This file is part of CanFestival, a library implementing CanOpen Stack.

Copyright (C): 

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

#ifndef __CANFESTIVAL_SYSDEP__
#define __CANFESTIVAL_SYSDEP__

#include <canfestival/config.h>

#ifdef CANOPEN_BIG_ENDIAN

/* Warning: the argument must not update pointers, e.g. *p++ */

#define UNS16_LE(v)  ((((UNS16)(v) & 0xff00) >> 8) | \
		      (((UNS16)(v) & 0x00ff) << 8))

#define UNS32_LE(v)  ((((UNS32)(v) & 0xff000000) >> 24) |	\
		      (((UNS32)(v) & 0x00ff0000) >> 8)  |	\
		      (((UNS32)(v) & 0x0000ff00) << 8)  |	\
		      (((UNS32)(v) & 0x000000ff) << 24))

#else

#define UNS16_LE(v)  (v)
#define UNS32_LE(v)  (v)

#endif

#endif
