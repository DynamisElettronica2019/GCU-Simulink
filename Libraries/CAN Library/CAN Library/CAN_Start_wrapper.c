
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
#include "pin_defines.h"
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
extern void CAN_Filter_Setup_Outputs_wrapper(void);

#if !defined(MATLAB_MEX_FILE)
extern CAN_HandleTypeDef hcan_active;
#endif
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void CAN_Start_Outputs_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
  CAN_Filter_Setup_Outputs_wrapper();
    
  #if !defined(MATLAB_MEX_FILE)
  
  HAL_CAN_ActivateNotification(&hcan_active, CAN_IT_TX_MAILBOX_EMPTY);
  HAL_CAN_ActivateNotification(&hcan_active, CAN_IT_RX_FIFO0_MSG_PENDING);
  HAL_CAN_ActivateNotification(&hcan_active, CAN_IT_RX_FIFO1_MSG_PENDING);
  HAL_CAN_Start(&hcan_active);
  
  #endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


