
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
#include "C_includes\timings.h"
#else
#include "timings.h"
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
void load_default_timings_Outputs_wrapper(int32_T *timings)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
timings[DELAY] = DEFAULT_DELAY;
timings[UP_REBOUND] = DEFAULT_UP_REBOUND;
timings[UP_BRAKE] = DEFAULT_UP_BRAKE;
timings[UP_PUSH_1_2] = DEFAULT_UP_PUSH_1_2;
timings[UP_PUSH_2_3] = DEFAULT_UP_PUSH_2_3;
timings[UP_PUSH_3_4] = DEFAULT_UP_PUSH_3_4;
timings[UP_PUSH_4_5] = DEFAULT_UP_PUSH_4_5;
//down
timings[CLUTCH] = DEFAULT_CLUTCH;
timings[DN_PUSH] = DEFAULT_DN_PUSH;
timings[DN_BRAKE] = DEFAULT_DN_BRAKE;
timings[DN_REBOUND] = DEFAULT_DN_REBOUND;
//neutral
timings[NT_CLUTCH_DELAY] = DEFAULT_NT_CLUTCH_DELAY;
timings[NT_REBOUND_1_N] = DEFAULT_NT_REBOUND_1_N;
timings[NT_REBOUND_2_N] = DEFAULT_NT_REBOUND_2_N;
timings[NT_BRAKE_1_N] = DEFAULT_NT_BRAKE_1_N;
timings[NT_BRAKE_2_N] = DEFAULT_NT_BRAKE_2_N;
timings[NT_PUSH_1_N] = DEFAULT_NT_PUSH_1_N;
timings[NT_PUSH_2_N] = DEFAULT_NT_PUSH_2_N;
timings[NT_CLUTCH_1_N] = DEFAULT_NT_CLUTCH_1_N;
timings[NT_CLUTCH_2_N] = DEFAULT_NT_CLUTCH_2_N;

//Multiple tries
timings[DOWN_TIME_CHECK] = DEFAULT_DOWN_TIME_CHECK;
timings[UP_TIME_CHECK] = DEFAULT_UP_TIME_CHECK;
timings[MAX_TRIES] = DEFAULT_MAX_TRIES;
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


