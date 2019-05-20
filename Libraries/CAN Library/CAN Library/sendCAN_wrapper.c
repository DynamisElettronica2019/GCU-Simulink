
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
#include "constant_defines.h"
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
#if !defined(MATLAB_MEX_FILE)
extern CAN_HandleTypeDef hcan_active;
extern uint8_t GCU_Packet_Data[8];
extern CAN_TxHeaderTypeDef GCU_Packet_Header;
#endif
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void sendCAN_Outputs_wrapper(const uint16_T *id,
			const uint8_T *dataArray)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
  #if !defined(MATLAB_MEX_FILE)

  uint32_t GCU_Packet_Mailbox;
  
  GCU_Packet_Header.StdId = *id;
  GCU_Packet_Header.RTR = CAN_RTR_DATA;
  GCU_Packet_Header.IDE = CAN_ID_STD;
  GCU_Packet_Header.DLC = 8;
  GCU_Packet_Header.TransmitGlobalTime = DISABLE;
  
  for(int i=0; i<CAN_SENT_DATA_WIDTH; i++)
    GCU_Packet_Data[i] = dataArray[i];    
	
  HAL_CAN_AddTxMessage(&hcan_active, &GCU_Packet_Header, GCU_Packet_Data, &GCU_Packet_Mailbox);
  #endif
  
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


