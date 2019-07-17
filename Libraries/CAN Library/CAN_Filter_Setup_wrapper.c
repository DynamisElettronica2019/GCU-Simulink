
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
#if !defined(MATLAB_MEX_FILE)
extern CAN_HandleTypeDef hcan_active;
extern CAN_FilterTypeDef CAN_Filter_Config;
#endif
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void CAN_Filter_Setup_Outputs_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#if !defined(MATLAB_MEX_FILE)

  CAN_Filter_Config.FilterBank = 14;
  CAN_Filter_Config.FilterMode = CAN_FILTERMODE_IDMASK;
  CAN_Filter_Config.FilterScale = CAN_FILTERSCALE_32BIT;
  CAN_Filter_Config.FilterIdHigh = (0x304 << 5);
  CAN_Filter_Config.FilterIdLow = 0x0000;
  CAN_Filter_Config.FilterMaskIdHigh = (0x3FC << 5);//(0x7F0  << 5);
  CAN_Filter_Config.FilterMaskIdLow = 0x0000;
  CAN_Filter_Config.FilterFIFOAssignment = CAN_RX_FIFO0;
  CAN_Filter_Config.FilterActivation = ENABLE;	
  CAN_Filter_Config.SlaveStartFilterBank = 14;
  
  HAL_CAN_ConfigFilter(&hcan_active, &CAN_Filter_Config);
  
  CAN_Filter_Config.FilterBank = 15;
  CAN_Filter_Config.FilterMode = CAN_FILTERMODE_IDMASK;
  CAN_Filter_Config.FilterScale = CAN_FILTERSCALE_32BIT;
  CAN_Filter_Config.FilterIdHigh = (0x30C << 5);
  CAN_Filter_Config.FilterIdLow = 0x0000;
  CAN_Filter_Config.FilterMaskIdHigh = (0x3FC << 5);//(0x7F0  << 5);
  CAN_Filter_Config.FilterMaskIdLow = 0x0000;
  CAN_Filter_Config.FilterFIFOAssignment = CAN_RX_FIFO0;
  CAN_Filter_Config.FilterActivation = ENABLE;	
  CAN_Filter_Config.SlaveStartFilterBank = 14;
  
  HAL_CAN_ConfigFilter(&hcan_active, &CAN_Filter_Config);
   
  CAN_Filter_Config.FilterBank = 16;
  CAN_Filter_Config.FilterMode = CAN_FILTERMODE_IDMASK;
  CAN_Filter_Config.FilterScale = CAN_FILTERSCALE_32BIT;
  CAN_Filter_Config.FilterIdHigh = (0x200 << 5);
  CAN_Filter_Config.FilterIdLow = 0x0000;
  CAN_Filter_Config.FilterMaskIdHigh = (0x3FC << 5);//(0x7F0  << 5);
  CAN_Filter_Config.FilterMaskIdLow = 0x0000;
  CAN_Filter_Config.FilterFIFOAssignment = CAN_RX_FIFO0;
  CAN_Filter_Config.FilterActivation = ENABLE;	
  CAN_Filter_Config.SlaveStartFilterBank = 14;
  
  HAL_CAN_ConfigFilter(&hcan_active, &CAN_Filter_Config);
  
  CAN_Filter_Config.FilterBank = 17;
  CAN_Filter_Config.FilterMode = CAN_FILTERMODE_IDMASK;
  CAN_Filter_Config.FilterScale = CAN_FILTERSCALE_32BIT;
  CAN_Filter_Config.FilterIdHigh = (0x200 << 5);
  CAN_Filter_Config.FilterIdLow = 0x0000;
  CAN_Filter_Config.FilterMaskIdHigh = (0x3FC << 5);//(0x7F0  << 5);
  CAN_Filter_Config.FilterMaskIdLow = 0x0000;
  CAN_Filter_Config.FilterFIFOAssignment = CAN_RX_FIFO0;
  CAN_Filter_Config.FilterActivation = ENABLE;	
  CAN_Filter_Config.SlaveStartFilterBank = 14;
  
  HAL_CAN_ConfigFilter(&hcan_active, &CAN_Filter_Config);
  
  CAN_Filter_Config.FilterBank = 18;
  CAN_Filter_Config.FilterMode = CAN_FILTERMODE_IDMASK;
  CAN_Filter_Config.FilterScale = CAN_FILTERSCALE_32BIT;
  CAN_Filter_Config.FilterIdHigh = (0x400 << 5);
  CAN_Filter_Config.FilterIdLow = 0x0000;
  CAN_Filter_Config.FilterMaskIdHigh = (0x3FE << 5);//(0x7F0  << 5);
  CAN_Filter_Config.FilterMaskIdLow = 0x0000;
  CAN_Filter_Config.FilterFIFOAssignment = CAN_RX_FIFO0;
  CAN_Filter_Config.FilterActivation = ENABLE;	
  CAN_Filter_Config.SlaveStartFilterBank = 14;
  
  HAL_CAN_ConfigFilter(&hcan_active, &CAN_Filter_Config);
  
  CAN_Filter_Config.FilterBank = 19;
  CAN_Filter_Config.FilterMode = CAN_FILTERMODE_IDMASK;
  CAN_Filter_Config.FilterScale = CAN_FILTERSCALE_32BIT;
  CAN_Filter_Config.FilterIdHigh = (0x204 << 5);
  CAN_Filter_Config.FilterIdLow = 0x0000;
  CAN_Filter_Config.FilterMaskIdHigh = (0x3FF << 5);//(0x7F0  << 5);
  CAN_Filter_Config.FilterMaskIdLow = 0x0000;
  CAN_Filter_Config.FilterFIFOAssignment = CAN_RX_FIFO0;
  CAN_Filter_Config.FilterActivation = ENABLE;	
  CAN_Filter_Config.SlaveStartFilterBank = 14;
  
  HAL_CAN_ConfigFilter(&hcan_active, &CAN_Filter_Config);
  
  CAN_Filter_Config.FilterBank = 20;
  CAN_Filter_Config.FilterMode = CAN_FILTERMODE_IDMASK;
  CAN_Filter_Config.FilterScale = CAN_FILTERSCALE_32BIT;
  CAN_Filter_Config.FilterIdHigh = (0x207 << 5);
  CAN_Filter_Config.FilterIdLow = 0x0000;
  CAN_Filter_Config.FilterMaskIdHigh = (0x3FF << 5);//(0x7F0  << 5);
  CAN_Filter_Config.FilterMaskIdLow = 0x0000;
  CAN_Filter_Config.FilterFIFOAssignment = CAN_RX_FIFO0;
  CAN_Filter_Config.FilterActivation = ENABLE;	
  CAN_Filter_Config.SlaveStartFilterBank = 14;
  
  HAL_CAN_ConfigFilter(&hcan_active, &CAN_Filter_Config);
  
  CAN_Filter_Config.FilterBank = 21;
  CAN_Filter_Config.FilterMode = CAN_FILTERMODE_IDMASK;
  CAN_Filter_Config.FilterScale = CAN_FILTERSCALE_32BIT;
  CAN_Filter_Config.FilterIdHigh = (0x700 << 5);
  CAN_Filter_Config.FilterIdLow = 0x0000;
  CAN_Filter_Config.FilterMaskIdHigh = (0x3FF << 5);//(0x7F0  << 5);
  CAN_Filter_Config.FilterMaskIdLow = 0x0000;
  CAN_Filter_Config.FilterFIFOAssignment = CAN_RX_FIFO0;
  CAN_Filter_Config.FilterActivation = ENABLE;	
  CAN_Filter_Config.SlaveStartFilterBank = 14;
  
  HAL_CAN_ConfigFilter(&hcan_active, &CAN_Filter_Config);
  
  #endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


