
/* File generated by gen_cfile.py. Should not be modified. */

#ifndef WIN32TEST_H
#define WIN32TEST_H

#include <canfestival/data.h>

/* Prototypes of function provided by object dictionnary */
UNS32 win32test_valueRangeTest (UNS8 typeValue, void * value);
const indextable * win32test_scanIndexOD (UNS16 wIndex, UNS32 * errorCode, ODCallback_t **callbacks);

/* Master node data struct */
extern CO_Data win32test_Data;

#endif // WIN32TEST_H
