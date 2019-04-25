
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
#define u_width 1
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
 
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void PackCANMsg_Outputs_wrapper(const uint16_T *firstInt,
			const uint16_T *secondInt,
			const uint16_T *thirdInt,
			const uint16_T *fourthInt,
			uint8_T *dataArray)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
dataArray[0] = *firstInt >> 8;
dataArray[1] = *firstInt;
dataArray[2] = *secondInt >> 8;
dataArray[3] = *secondInt;
dataArray[4] = *thirdInt >> 8;
dataArray[5] = *thirdInt;
dataArray[6] = *fourthInt >> 8;
dataArray[7] = *fourthInt;

/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


