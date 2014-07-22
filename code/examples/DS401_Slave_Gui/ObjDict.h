
/* File generated by gen_cfile.py. Should not be modified. */

#ifndef OBJDICT_H
#define OBJDICT_H

#include <canfestival/data.h>

/* Prototypes of function provided by object dictionnary */
UNS32 ObjDict_valueRangeTest (UNS8 typeValue, void * value);
const indextable * ObjDict_scanIndexOD (UNS16 wIndex, UNS32 * errorCode, ODCallback_t **callbacks);

/* Master node data struct */
extern CO_Data ObjDict_Data;
extern UNS8 Read_Inputs_8_Bit[1];		/* Mapped at index 0x6000, subindex 0x01 - 0x01 */
extern UNS8 Polarity_Input_8_Bit[1];		/* Mapped at index 0x6002, subindex 0x01 - 0x01 */
extern UNS8 Write_Outputs_8_Bit[1];		/* Mapped at index 0x6200, subindex 0x01 - 0x01 */
extern UNS8 Change_Polarity_Outputs_8_Bit[1];		/* Mapped at index 0x6202, subindex 0x01 - 0x01 */
extern UNS8 Error_Mode_Outputs_8_Bit[1];		/* Mapped at index 0x6206, subindex 0x01 - 0x01 */
extern UNS8 Error_Value_Outputs_8_Bit[1];		/* Mapped at index 0x6207, subindex 0x01 - 0x01 */
extern INTEGER16 Read_Analogue_Input_16_Bit[8];		/* Mapped at index 0x6401, subindex 0x01 - 0x08 */
extern INTEGER16 Write_Analogue_Output_16_Bit[4];		/* Mapped at index 0x6411, subindex 0x01 - 0x04 */
extern UNS8 Analogue_Input_Global_Interrupt_Enable;		/* Mapped at index 0x6423, subindex 0x00*/
extern UNS32 Analogue_Input_Interrupt_Delta_Unsigned[8];		/* Mapped at index 0x6426, subindex 0x01 - 0x08 */
extern UNS8 Analogue_Output_Error_Mode[4];		/* Mapped at index 0x6443, subindex 0x01 - 0x04 */
extern INTEGER32 Analogue_Output_Error_Value_Integer[4];		/* Mapped at index 0x6444, subindex 0x01 - 0x04 */

#endif // OBJDICT_H
