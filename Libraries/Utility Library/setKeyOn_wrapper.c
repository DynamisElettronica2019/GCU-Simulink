
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
#if defined(MATLAB_MEX_FILE)
#include "..\..\C_includes\constant_defines.h"
#else
#include "constant_defines.h"
#include "pin_defines.h"
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
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
void setKeyOn_Outputs_wrapper(uint8_T *keyOn)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#if !defined(MATLAB_MEX_FILE)
  HAL_GPIO_WritePin(KEY_ON_GPIO_Port, KEY_ON_Pin, KEY_ON_SET);
#endif
  
  *keyOn = KEY_ON_SET;
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


