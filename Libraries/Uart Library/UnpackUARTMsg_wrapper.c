
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
/*#if !defined(MATLAB_MEX_FILE)
#include "stm32f7xx_hal.h"
#include "pin_defines.h"
#endif*/

#define MAX_LENGTH 10
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 20
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/*#if !defined(MATLAB_MEX_FILE)
extern UART_HandleTypeDef huartDebug;
#endif*/
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void UnpackUARTMsg_Outputs_wrapper(const uint8_T *msgArray,
			uint16_T *dataArray)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/*#if !defined(MATLAB_MEX_FILE)
HAL_UART_Transmit(&huart3, (uint8_t *) &u0, 1, 50);
#endif*/
int i = 0;

for(i=0; i<MAX_LENGTH; i++)
{
  dataArray[i] = (msgArray[2*i] << 8) | msgArray[2*i+1];
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


