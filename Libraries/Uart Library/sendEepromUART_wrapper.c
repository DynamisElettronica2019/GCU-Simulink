
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#if !defined(MATLAB_MEX_FILE)
#include "constant_defines.h"
#include "pin_defines.h"
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 19

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
#if !defined(MATLAB_MEX_FILE)
extern UART_HandleTypeDef huartDebug;
extern uint8_t tempEepromUartMsg[UART_SENT_EEPROM_DATA_WIDTH+3];
#endif
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void sendEepromUART_Outputs_wrapper(const uint8_T *msg)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#if !defined(MATLAB_MEX_FILE)

  uint8_t header[3] = "epr";// terminator[2] = "\r";
	
  tempEepromUartMsg[0] = header[0];
  tempEepromUartMsg[1] = header[1];
  tempEepromUartMsg[2] = header[2];
	
  for(int i = 0; i<UART_SENT_EEPROM_DATA_WIDTH; i++)
		tempEepromUartMsg[3+i] = msg[i];
	
  //tempMsg[UART_SENT_DATA_WIDTH+3] = (uint8_t) '\r';

  HAL_UART_Transmit_DMA(&huartDebug, tempEepromUartMsg, UART_SENT_EEPROM_DATA_WIDTH+3);	
#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


