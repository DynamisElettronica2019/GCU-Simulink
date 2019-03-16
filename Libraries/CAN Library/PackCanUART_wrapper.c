
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
#include <math.h>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
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
void PackCanUART_Outputs_wrapper(const uint16_T *id,
			const uint16_T *firstInt,
			const uint16_T *secondInt,
			const uint16_T *thirdInt,
			const uint16_T *fourthInt,
			uint8_T *message)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
message[0] = *id >> 8;
message[1] = *id;
message[2] = *firstInt>>8;
message[3] = *firstInt;
message[4] = *secondInt>>8;
message[5] = *secondInt;
message[6] = *thirdInt>>8;
message[7] = *thirdInt;
message[8] = *fourthInt>>8;
message[9] = *fourthInt;
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


