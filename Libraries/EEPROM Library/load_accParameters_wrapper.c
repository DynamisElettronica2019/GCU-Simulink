
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
#include "..\..\C_includes\def_acc_parameters.h"
#else
#include "def_acc_parameters.h"
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
void load_accParameters_Outputs_wrapper(int32_T *accParameters)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
accParameters[0] = DEF_RAMP_START;
accParameters[1] = DEF_RAMP_END; 
accParameters[2] = DEF_RAMP_TIME;
accParameters[3] = DEF_RPM_LIMIT_1_2;
accParameters[4] = DEF_RPM_LIMIT_2_3;
accParameters[5] = DEF_RPM_LIMIT_3_4;
accParameters[6] = DEF_RPM_LIMIT_4_5;
accParameters[7] = DEF_SPEED_LIMIT_1_2;
accParameters[8] = DEF_SPEED_LIMIT_2_3;
accParameters[9] = DEF_SPEED_LIMIT_3_4;
accParameters[10] = DEF_SPEED_LIMIT_4_5;
accParameters[11] = DEF_TPS_START_LIMIT;
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


