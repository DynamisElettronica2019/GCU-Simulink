
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
//#include "stm32f7xx_hal.h"
#include "pin_defines.h"
#endif
#define WIDTH 20
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 20

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
#if !defined(MATLAB_MEX_FILE)
extern UART_HandleTypeDef huartDebug;
extern uint8_t tempMsg[24];
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
	
  //uint8_t tempMsg[24];
	
  tempMsg[0] = header[0];
  tempMsg[1] = header[1];
  tempMsg[2] = header[2];
	
  for(int i = 0; i<20; i++)
		tempMsg[3+i] = msg[i];
	
  tempMsg[23] = '\r';

	
  //HAL_UART_Transmit(&huart3, header, 3, 1);	
  HAL_UART_Transmit_DMA(&huartDebug, tempMsg, 24);
  //HAL_UART_Transmit(&huart3, terminator, 1, 1);
	
  /*char tempMsg[25];
	
	
	
	tempMsg[0] = header[0];
	tempMsg[1] = header[1];
	tempMsg[2] = header[2];
	
  for(int i = 0; i<20; i++)
		tempMsg[3+i] = msg[i];
	
	tempMsg[23] = '\r';
	tempMsg[24] = '\n'; 
		
	HAL_UART_Transmit_IT(&huart3, (uint8_t*) tempMsg, 25);*/
	
#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


