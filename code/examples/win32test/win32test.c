
/* File generated by gen_cfile.py. Should not be modified. */

#include "win32test.h"

/**************************************************************************/
/* Declaration of mapped variables                                        */
/**************************************************************************/

/**************************************************************************/
/* Declaration of value range types                                       */
/**************************************************************************/

#define valueRange_EMC 0x9F /* Type for index 0x1003 subindex 0x00 (only set of value 0 is possible) */
UNS32 win32test_valueRangeTest (UNS8 typeValue, void * value)
{
  switch (typeValue) {
    case valueRange_EMC:
      if (*(UNS8*)value != (UNS8)0) return OD_VALUE_RANGE_EXCEEDED;
      break;
  }
  return 0;
}

/**************************************************************************/
/* The node id                                                            */
/**************************************************************************/
/* node_id default value.*/
UNS8 win32test_bDeviceNodeId = 0x00;

/**************************************************************************/
/* Array of message processing information */

const UNS8 win32test_iam_a_slave = 0;

TIMER_HANDLE win32test_heartBeatTimers[1];

/*
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

                               OBJECT DICTIONARY

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*/

/* index 0x1000 :   Device Type. */
                    UNS32 win32test_obj1000 = 0x12D;	/* 301 */
                    subindex win32test_Index1000[] = 
                     {
                       { RO, uint32, sizeof (UNS32), (void*)&win32test_obj1000 }
                     };

/* index 0x1001 :   Error Register. */
                    UNS8 win32test_obj1001 = 0x0;	/* 0 */
                    subindex win32test_Index1001[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&win32test_obj1001 }
                     };

/* index 0x1003 :   Pre-defined Error Field */
                    UNS8 win32test_highestSubIndex_obj1003 = 0; /* number of subindex - 1*/
                    UNS32 win32test_obj1003[] = 
                    {
                      0x0	/* 0 */
                    };
                    ODCallback_t win32test_Index1003_callbacks[] = 
                     {
                       NULL,
                       NULL,
                     };
                    subindex win32test_Index1003[] = 
                     {
                       { RW, valueRange_EMC, sizeof (UNS8), (void*)&win32test_highestSubIndex_obj1003 },
                       { RO, uint32, sizeof (UNS32), (void*)&win32test_obj1003[0] }
                     };

/* index 0x1005 :   SYNC COB ID. */
                    UNS32 win32test_obj1005 = 0x0;	/* 0 */
                    ODCallback_t win32test_Index1005_callbacks[] = 
                     {
                       NULL,
                     };
                    subindex win32test_Index1005[] = 
                     {
                       { RW, uint32, sizeof (UNS32), (void*)&win32test_obj1005 }
                     };

/* index 0x1006 :   Communication / Cycle Period */
                    UNS32 win32test_obj1006 = 0x0;   /* 0 */

					/* index 0x100C :   Guard Time */
					UNS16 win32test_obj100C = 0x0;   /* 0 */

					/* index 0x100D :   Life Time Factor */
					UNS8 win32test_obj100D = 0x0;   /* 0 */

/* index 0x1014 :   Emergency COB ID */
                    UNS32 win32test_obj1014 = 0x80 + 0x00;   /* 128 + NodeID */

/* index 0x1016 :   Consumer Heartbeat Time */
                    UNS8 win32test_highestSubIndex_obj1016 = 0;
                    UNS32 win32test_obj1016[]={0};

/* index 0x1017 :   Producer Heartbeat Time */ 
                    UNS16 win32test_obj1017 = 0x0;   /* 0 */

/* index 0x1018 :   Identity. */
                    UNS8 win32test_highestSubIndex_obj1018 = 4; /* number of subindex - 1*/
                    UNS32 win32test_obj1018_Vendor_ID = 0x0;	/* 0 */
                    UNS32 win32test_obj1018_Product_Code = 0x0;	/* 0 */
                    UNS32 win32test_obj1018_Revision_Number = 0x0;	/* 0 */
                    UNS32 win32test_obj1018_Serial_Number = 0x0;	/* 0 */
                    subindex win32test_Index1018[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&win32test_highestSubIndex_obj1018 },
                       { RO, uint32, sizeof (UNS32), (void*)&win32test_obj1018_Vendor_ID },
                       { RO, uint32, sizeof (UNS32), (void*)&win32test_obj1018_Product_Code },
                       { RO, uint32, sizeof (UNS32), (void*)&win32test_obj1018_Revision_Number },
                       { RO, uint32, sizeof (UNS32), (void*)&win32test_obj1018_Serial_Number }
                     };

/* index 0x1280 :   Client SDO 1 Parameter. */
                    UNS8 win32test_highestSubIndex_obj1280 = 3; /* number of subindex - 1*/
                    UNS32 win32test_obj1280_COB_ID_Client_to_Server_Transmit_SDO = 0x0;	/* 0 */
                    UNS32 win32test_obj1280_COB_ID_Server_to_Client_Receive_SDO = 0x0;	/* 0 */
                    UNS8 win32test_obj1280_Node_ID_of_the_SDO_Server = 0x0;	/* 0 */
                    subindex win32test_Index1280[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&win32test_highestSubIndex_obj1280 },
                       { RW, uint32, sizeof (UNS32), (void*)&win32test_obj1280_COB_ID_Client_to_Server_Transmit_SDO },
                       { RW, uint32, sizeof (UNS32), (void*)&win32test_obj1280_COB_ID_Server_to_Client_Receive_SDO },
                       { RW, uint8, sizeof (UNS8), (void*)&win32test_obj1280_Node_ID_of_the_SDO_Server }
                     };

/**************************************************************************/
/* Declaration of pointed variables                                       */
/**************************************************************************/

const indextable win32test_objdict[] = 
{
  { (subindex*)win32test_Index1000,sizeof(win32test_Index1000)/sizeof(win32test_Index1000[0]), 0x1000},
  { (subindex*)win32test_Index1001,sizeof(win32test_Index1001)/sizeof(win32test_Index1001[0]), 0x1001},
  { (subindex*)win32test_Index1005,sizeof(win32test_Index1005)/sizeof(win32test_Index1005[0]), 0x1005},
  { (subindex*)win32test_Index1018,sizeof(win32test_Index1018)/sizeof(win32test_Index1018[0]), 0x1018},
  { (subindex*)win32test_Index1280,sizeof(win32test_Index1280)/sizeof(win32test_Index1280[0]), 0x1280},
};

const indextable * win32test_scanIndexOD (UNS16 wIndex, UNS32 * errorCode, ODCallback_t **callbacks)
{
	int i;
	*callbacks = NULL;
	switch(wIndex){
		case 0x1000: i = 0;break;
		case 0x1001: i = 1;break;
		case 0x1005: i = 2;*callbacks = win32test_Index1005_callbacks; break;
		case 0x1018: i = 3;break;
		case 0x1280: i = 4;break;
		default:
			*errorCode = OD_NO_SUCH_OBJECT;
			return NULL;
	}
	*errorCode = OD_SUCCESSFUL;
	return &win32test_objdict[i];
}

/* 
 * To count at which received SYNC a PDO must be sent.
 * Even if no pdoTransmit are defined, at least one entry is computed
 * for compilations issues.
 */
s_PDO_status win32test_PDO_status[1] = {s_PDO_status_Initializer};

const quick_index win32test_firstIndex = {
  0, /* SDO_SVR */
  4, /* SDO_CLT */
  0, /* PDO_RCV */
  0, /* PDO_RCV_MAP */
  0, /* PDO_TRS */
  0 /* PDO_TRS_MAP */
};

const quick_index win32test_lastIndex = {
  0, /* SDO_SVR */
  4, /* SDO_CLT */
  0, /* PDO_RCV */
  0, /* PDO_RCV_MAP */
  0, /* PDO_TRS */
  0 /* PDO_TRS_MAP */
};

const UNS16 win32test_ObjdictSize = sizeof(win32test_objdict)/sizeof(win32test_objdict[0]); 

CO_Data win32test_Data = CANOPEN_NODE_DATA_INITIALIZER(win32test);

