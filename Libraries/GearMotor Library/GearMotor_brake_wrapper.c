
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
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
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
void GearMotor_brake_Outputs_wrapper(uint8_T *GearMotor_In1,
			uint8_T *GearMotor_In2,
			uint8_T *GearMotor_INH)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
*GearMotor_In1 = 0;
*GearMotor_In2 = 0;
*GearMotor_INH = 1;

#if !defined(MATLAB_MEX_FILE)
HAL_GPIO_WritePin(GPIO_GEAR_MOTOR, GEAR_MOTOR_IN1, GPIO_PIN_RESET);
HAL_GPIO_WritePin(GPIO_GEAR_MOTOR_B, GEAR_MOTOR_IN2, GPIO_PIN_RESET);
HAL_GPIO_WritePin(GPIO_GEAR_MOTOR, GEAR_MOTOR_INHIBIT, GPIO_PIN_SET);
#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


