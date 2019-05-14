
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
#define u_width 40

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
#if !defined(MATLAB_MEX_FILE)
extern UART_HandleTypeDef huartDebug;
extern uint8_t tempMsg[UART_SENT_DATA_WIDTH+4];
#endif
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void sendUART_Outputs_wrapper(const uint8_T *msg)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#if !defined(MATLAB_MEX_FILE)

  uint8_t header[3] = "hdr", terminator[2] = "\r";
	
  tempMsg[0] = header[0];
  tempMsg[1] = header[1];
  tempMsg[2] = header[2];
	
  for(int i = 0; i<UART_SENT_DATA_WIDTH; i++)
		tempMsg[3+i] = msg[i];
	
  tempMsg[UART_SENT_DATA_WIDTH+3] = (uint8_t) '\r';

  HAL_UART_Transmit_DMA(&huartDebug, tempMsg, UART_SENT_DATA_WIDTH+4);	
#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


