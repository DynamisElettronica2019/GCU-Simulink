
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
 
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 10
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void UnpackCanUART_Outputs_wrapper(const uint8_T *serialMsg,
			uint16_T *identifier,
			uint16_T *firstInt,
			uint16_T *secondInt,
			uint16_T *thirdInt,
			uint16_T *fourthInt)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
*identifier = (serialMsg[0]<<8) | serialMsg[1];

*firstInt = (serialMsg[2]<<8) | serialMsg[3];
*secondInt = (serialMsg[4]<<8) | serialMsg[5];
*thirdInt = (serialMsg[6]<<8) | serialMsg[7];
*fourthInt = (serialMsg[8]<<8) | serialMsg[9];
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


