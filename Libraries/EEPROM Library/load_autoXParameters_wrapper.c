
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
#include "..\..\C_includes\def_autoX_parameters.h"
#else
#include "def_autoX_parameters.h"
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
void load_autoXParameters_Outputs_wrapper(int32_T *autoXParameters)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
autoXParameters[0] = DEF_AUTOX_RAMP_START;
autoXParameters[1] = DEF_AUTOX_RAMP_END; 
autoXParameters[2] = DEF_AUTOX_RAMP_TIME;
autoXParameters[3] = DEF_AUTOX_RPM_LIMIT_1_2;
autoXParameters[4] = DEF_AUTOX_RPM_LIMIT_2_3;
autoXParameters[5] = DEF_AUTOX_RPM_LIMIT_3_4;
autoXParameters[6] = DEF_AUTOX_RPM_LIMIT_4_5;
autoXParameters[7] = DEF_AUTOX_SPEED_LIMIT_1_2;
autoXParameters[8] = DEF_AUTOX_SPEED_LIMIT_2_3;
autoXParameters[9] = DEF_AUTOX_SPEED_LIMIT_3_4;
autoXParameters[10] = DEF_AUTOX_SPEED_LIMIT_4_5;
autoXParameters[11] = DEF_AUTOX_TPS_START_LIMIT;
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


