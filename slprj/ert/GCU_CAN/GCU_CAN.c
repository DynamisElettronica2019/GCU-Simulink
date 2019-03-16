/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GCU_CAN.c
 *
 * Code generated for Simulink model 'GCU_CAN'.
 *
 * Model version                  : 1.40
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Sat Feb 16 15:33:52 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "GCU_CAN.h"
#include "rt_roundd.h"

/* Named constants for Chart: '<Root>/MessageEvaluation' */
#define GCU_CAN_AAC_CLUTCH_NOISE_LEVEL ((uint8_T)30U)
#define GCU_CAN_EFI_TRACTION_CONTROL_ID ((uint16_T)774U)
#define GCU_CAN_IN_AAC_COM             ((uint8_T)1U)
#define GCU_CAN_IN_GEAR_RPM_UPDATE     ((uint8_T)2U)
#define GCU_CAN_IN_IDLE                ((uint8_T)3U)
#define GCU_CAN_IN_SET_CLUTCH          ((uint8_T)4U)
#define GCU_CAN_IN_SET_TRACTION        ((uint8_T)5U)
#define GCU_CAN_IN_START_ENGINE        ((uint8_T)6U)
#define GCU_CAN_IN_SW_GEARSHIFT        ((uint8_T)7U)
#define GCU_CAN_IN_WHEEL_SPEED_UPDATE  ((uint8_T)8U)
#define GCU_CAN_RPM_LIMITER_OFF        ((uint16_T)160U)
#define GCU_CAN_RPM_LIMITER_ON         ((uint16_T)150U)
#define GCU_CAN_STOP_COM               ((uint16_T)0U)
#define GCU_CAN_SW_ACCELERATION_GCU_ID ((uint16_T)514U)
#define GCU_CAN_SW_CLUTCH_TARGET_GCU_ID ((uint16_T)513U)
#define GCU_CAN_SW_FIRE_GCU_ID         ((uint16_T)516U)
#define GCU_CAN_SW_GEARSHIFT_ID        ((uint16_T)512U)
#define GCU_CA_EFI_GEAR_RPM_TPS_APPS_ID ((uint16_T)773U)
#define GCU__SW_TRACTION_CONTROL_GCU_ID ((uint16_T)515U)

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
# define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void UnpackCanUART_Start_wrapper(void);
  extern void UnpackCanUART_Outputs_wrapper(const uint8_T *serialMsg,
    uint16_T *identifier,
    uint16_T *firstInt,
    uint16_T *secondInt,
    uint16_T *thirdInt,
    uint16_T *fourthInt);
  extern void UnpackCanUART_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

/* Forward declaration for local functions */
static void GCU_CAN_sendStartEngCommand(uint8_T *rty_startEngCommand);
static void GCU_CAN_sendAacCommand(uint16_T com, uint16_T rty_aacCommand[2]);
static void GCU_CAN_sendShiftCommand(uint16_T com, const uint8_T
  *rtu_clutchCurrVal, uint16_T rty_shiftCommand[2], uint16_T rty_aacCommand[2]);
static void GCU_CAN_sendClutchCommand(uint8_T com, uint8_T rty_clutchCommand[2]);
static void GCU_CAN_WHEEL_SPEED_UPDATE(uint16_T *aac_externValue, uint16_T
  *aac_externValues_index, uint32_T *tractionValue, const uint8_T
  *rtu_clutchCurrVal, uint16_T *rty_currGear, uint16_T rty_aac_externValue[3],
  uint16_T rty_shiftCommand[2], uint8_T *rty_startEngCommand, uint16_T
  rty_aacCommand[2], uint8_T rty_clutchCommand[2], uint32_T *rty_tractionValue,
  DW_GCU_CAN_f_T *localDW);
static void GCU_CAN_AAC_COM(uint16_T *aac_externValue, uint16_T
  *aac_externValues_index, uint32_T *tractionValue, const uint8_T
  *rtu_clutchCurrVal, uint16_T *rty_currGear, uint16_T rty_aac_externValue[3],
  uint16_T rty_shiftCommand[2], uint8_T *rty_startEngCommand, uint16_T
  rty_aacCommand[2], uint8_T rty_clutchCommand[2], uint32_T *rty_tractionValue,
  DW_GCU_CAN_f_T *localDW);
static void GCU_CAN_GEAR_RPM_UPDATE(uint16_T *aac_externValue, uint16_T
  *aac_externValues_index, uint32_T *tractionValue, const uint8_T
  *rtu_clutchCurrVal, uint16_T *rty_currGear, uint16_T rty_aac_externValue[3],
  uint16_T rty_shiftCommand[2], uint8_T *rty_startEngCommand, uint16_T
  rty_aacCommand[2], uint8_T rty_clutchCommand[2], uint32_T *rty_tractionValue,
  DW_GCU_CAN_f_T *localDW);

/* Output and update for function-call system: '<Root>/TractionValue' */
void GCU_CAN_TractionValue(uint32_T rtu_Value, uint32_T *rty_tractionValue,
  DW_TractionValue_GCU_CAN_T *localDW)
{
  /* Assignment: '<S3>/Assignment' incorporates:
   *  UnitDelay: '<S3>/Unit Delay'
   */
  *rty_tractionValue = localDW->UnitDelay_DSTATE;
  *rty_tractionValue = rtu_Value;

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  localDW->UnitDelay_DSTATE = *rty_tractionValue;
}

/* Output and update for function-call system: '<Root>/AAC_ExternalValues' */
void GCU_CAN_AAC_ExternalValues(uint16_T rtu_Value, uint16_T rtu_Index, uint16_T
  rty_Values[3], DW_AAC_ExternalValues_GCU_CAN_T *localDW)
{
  /* Assignment: '<S1>/Assignment' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rty_Values[0] = localDW->UnitDelay_DSTATE[0];
  rty_Values[1] = localDW->UnitDelay_DSTATE[1];
  rty_Values[2] = localDW->UnitDelay_DSTATE[2];
  rty_Values[rtu_Index] = rtu_Value;

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  localDW->UnitDelay_DSTATE[0] = rty_Values[0];
  localDW->UnitDelay_DSTATE[1] = rty_Values[1];
  localDW->UnitDelay_DSTATE[2] = rty_Values[2];
}

/* Function for Chart: '<Root>/MessageEvaluation' */
static void GCU_CAN_sendStartEngCommand(uint8_T *rty_startEngCommand)
{
  int32_T tmp;
  if (*rty_startEngCommand >= 255) {
    *rty_startEngCommand = 0U;
  } else {
    tmp = (int32_T)(*rty_startEngCommand + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    *rty_startEngCommand = (uint8_T)tmp;
  }
}

/* Function for Chart: '<Root>/MessageEvaluation' */
static void GCU_CAN_sendAacCommand(uint16_T com, uint16_T rty_aacCommand[2])
{
  uint32_T tmp;
  if (rty_aacCommand[0] >= 255) {
    rty_aacCommand[0] = 0U;
  } else {
    tmp = rty_aacCommand[0] + 1U;
    if (tmp > 65535U) {
      tmp = 65535U;
    }

    rty_aacCommand[0] = (uint16_T)tmp;
  }

  rty_aacCommand[1] = com;
}

/* Function for Chart: '<Root>/MessageEvaluation' */
static void GCU_CAN_sendShiftCommand(uint16_T com, const uint8_T
  *rtu_clutchCurrVal, uint16_T rty_shiftCommand[2], uint16_T rty_aacCommand[2])
{
  uint32_T tmp;
  if (rty_shiftCommand[0] >= 255) {
    rty_shiftCommand[0] = 0U;
  } else {
    tmp = rty_shiftCommand[0] + 1U;
    if (tmp > 65535U) {
      tmp = 65535U;
    }

    rty_shiftCommand[0] = (uint16_T)tmp;
  }

  rty_shiftCommand[1] = com;
  if (*rtu_clutchCurrVal != 100) {
    GCU_CAN_sendAacCommand(GCU_CAN_STOP_COM, rty_aacCommand);
  }
}

/* Function for Chart: '<Root>/MessageEvaluation' */
static void GCU_CAN_sendClutchCommand(uint8_T com, uint8_T rty_clutchCommand[2])
{
  int32_T tmp;
  if (rty_clutchCommand[0] >= 255) {
    rty_clutchCommand[0] = 0U;
  } else {
    tmp = (int32_T)(rty_clutchCommand[0] + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    rty_clutchCommand[0] = (uint8_T)tmp;
  }

  rty_clutchCommand[1] = com;
}

/* Function for Chart: '<Root>/MessageEvaluation' */
static void GCU_CAN_WHEEL_SPEED_UPDATE(uint16_T *aac_externValue, uint16_T
  *aac_externValues_index, uint32_T *tractionValue, const uint8_T
  *rtu_clutchCurrVal, uint16_T *rty_currGear, uint16_T rty_aac_externValue[3],
  uint16_T rty_shiftCommand[2], uint8_T *rty_startEngCommand, uint16_T
  rty_aacCommand[2], uint8_T rty_clutchCommand[2], uint32_T *rty_tractionValue,
  DW_GCU_CAN_f_T *localDW)
{
  uint8_T clutchSetVal;
  *aac_externValues_index = (uint16_T)WHEEL_SPEED;
  if (localDW->UnpackCanUart_o1 == GCU_CA_EFI_GEAR_RPM_TPS_APPS_ID) {
    localDW->is_c3_GCU_CAN = GCU_CAN_IN_GEAR_RPM_UPDATE;
    *rty_currGear = localDW->UnpackCanUart_o2;
    *aac_externValues_index = (uint16_T)RPM;
    *aac_externValue = localDW->UnpackCanUart_o3;

    /* Chart: '<Root>/MessageEvaluation' incorporates:
     *  SubSystem: '<Root>/AAC_ExternalValues'
     */
    GCU_CAN_AAC_ExternalValues(*aac_externValue, *aac_externValues_index,
      rty_aac_externValue, &localDW->AAC_ExternalValues);
  } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_FIRE_GCU_ID) {
    localDW->is_c3_GCU_CAN = GCU_CAN_IN_START_ENGINE;
    GCU_CAN_sendStartEngCommand(rty_startEngCommand);
  } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_GEARSHIFT_ID) {
    localDW->is_c3_GCU_CAN = GCU_CAN_IN_SW_GEARSHIFT;
    if ((localDW->UnpackCanUart_o2 != GCU_CAN_RPM_LIMITER_ON) &&
        (localDW->UnpackCanUart_o2 != GCU_CAN_RPM_LIMITER_OFF)) {
      GCU_CAN_sendShiftCommand(localDW->UnpackCanUart_o2, rtu_clutchCurrVal,
        rty_shiftCommand, rty_aacCommand);
    }
  } else if (localDW->UnpackCanUart_o1 == GCU_CAN_EFI_TRACTION_CONTROL_ID) {
    localDW->is_c3_GCU_CAN = GCU_CAN_IN_WHEEL_SPEED_UPDATE;
    *aac_externValues_index = (uint16_T)WHEEL_SPEED;
    *aac_externValue = (uint16_T)rt_roundd((real_T)localDW->UnpackCanUart_o2 /
      10.0);

    /* Chart: '<Root>/MessageEvaluation' incorporates:
     *  SubSystem: '<Root>/AAC_ExternalValues'
     */
    GCU_CAN_AAC_ExternalValues(*aac_externValue, *aac_externValues_index,
      rty_aac_externValue, &localDW->AAC_ExternalValues);
  } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_CLUTCH_TARGET_GCU_ID) {
    localDW->is_c3_GCU_CAN = GCU_CAN_IN_SET_CLUTCH;
    clutchSetVal = (uint8_T)((uint32_T)localDW->UnpackCanUart_o2 >> 8);
    if (clutchSetVal > GCU_CAN_AAC_CLUTCH_NOISE_LEVEL) {
      GCU_CAN_sendAacCommand(GCU_CAN_STOP_COM, rty_aacCommand);
    }

    GCU_CAN_sendClutchCommand(clutchSetVal, rty_clutchCommand);
  } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_ACCELERATION_GCU_ID) {
    localDW->is_c3_GCU_CAN = GCU_CAN_IN_AAC_COM;
    GCU_CAN_sendAacCommand(localDW->UnpackCanUart_o2, rty_aacCommand);
    if (rty_aacCommand[1] == GCU_CAN_STOP_COM) {
      GCU_CAN_sendClutchCommand(0, rty_clutchCommand);
    }
  } else if (localDW->UnpackCanUart_o1 == GCU__SW_TRACTION_CONTROL_GCU_ID) {
    localDW->is_c3_GCU_CAN = GCU_CAN_IN_SET_TRACTION;
    *tractionValue = localDW->UnpackCanUart_o2 * 100U;

    /* Chart: '<Root>/MessageEvaluation' incorporates:
     *  SubSystem: '<Root>/TractionValue'
     */
    GCU_CAN_TractionValue(*tractionValue, rty_tractionValue,
                          &localDW->TractionValue);
  } else {
    localDW->is_c3_GCU_CAN = GCU_CAN_IN_IDLE;
  }
}

/* Function for Chart: '<Root>/MessageEvaluation' */
static void GCU_CAN_AAC_COM(uint16_T *aac_externValue, uint16_T
  *aac_externValues_index, uint32_T *tractionValue, const uint8_T
  *rtu_clutchCurrVal, uint16_T *rty_currGear, uint16_T rty_aac_externValue[3],
  uint16_T rty_shiftCommand[2], uint8_T *rty_startEngCommand, uint16_T
  rty_aacCommand[2], uint8_T rty_clutchCommand[2], uint32_T *rty_tractionValue,
  DW_GCU_CAN_f_T *localDW)
{
  uint8_T clutchSetVal;
  if (localDW->UnpackCanUart_o1 == GCU_CA_EFI_GEAR_RPM_TPS_APPS_ID) {
    localDW->is_c3_GCU_CAN = GCU_CAN_IN_GEAR_RPM_UPDATE;
    *rty_currGear = localDW->UnpackCanUart_o2;
    *aac_externValues_index = (uint16_T)RPM;
    *aac_externValue = localDW->UnpackCanUart_o3;

    /* Chart: '<Root>/MessageEvaluation' incorporates:
     *  SubSystem: '<Root>/AAC_ExternalValues'
     */
    GCU_CAN_AAC_ExternalValues(*aac_externValue, *aac_externValues_index,
      rty_aac_externValue, &localDW->AAC_ExternalValues);
  } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_FIRE_GCU_ID) {
    localDW->is_c3_GCU_CAN = GCU_CAN_IN_START_ENGINE;
    GCU_CAN_sendStartEngCommand(rty_startEngCommand);
  } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_GEARSHIFT_ID) {
    localDW->is_c3_GCU_CAN = GCU_CAN_IN_SW_GEARSHIFT;
    if ((localDW->UnpackCanUart_o2 != GCU_CAN_RPM_LIMITER_ON) &&
        (localDW->UnpackCanUart_o2 != GCU_CAN_RPM_LIMITER_OFF)) {
      GCU_CAN_sendShiftCommand(localDW->UnpackCanUart_o2, rtu_clutchCurrVal,
        rty_shiftCommand, rty_aacCommand);
    }
  } else if (localDW->UnpackCanUart_o1 == GCU_CAN_EFI_TRACTION_CONTROL_ID) {
    localDW->is_c3_GCU_CAN = GCU_CAN_IN_WHEEL_SPEED_UPDATE;
    *aac_externValues_index = (uint16_T)WHEEL_SPEED;
    *aac_externValue = (uint16_T)rt_roundd((real_T)localDW->UnpackCanUart_o2 /
      10.0);

    /* Chart: '<Root>/MessageEvaluation' incorporates:
     *  SubSystem: '<Root>/AAC_ExternalValues'
     */
    GCU_CAN_AAC_ExternalValues(*aac_externValue, *aac_externValues_index,
      rty_aac_externValue, &localDW->AAC_ExternalValues);
  } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_CLUTCH_TARGET_GCU_ID) {
    localDW->is_c3_GCU_CAN = GCU_CAN_IN_SET_CLUTCH;
    clutchSetVal = (uint8_T)((uint32_T)localDW->UnpackCanUart_o2 >> 8);
    if (clutchSetVal > GCU_CAN_AAC_CLUTCH_NOISE_LEVEL) {
      GCU_CAN_sendAacCommand(GCU_CAN_STOP_COM, rty_aacCommand);
    }

    GCU_CAN_sendClutchCommand(clutchSetVal, rty_clutchCommand);
  } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_ACCELERATION_GCU_ID) {
    localDW->is_c3_GCU_CAN = GCU_CAN_IN_AAC_COM;
    GCU_CAN_sendAacCommand(localDW->UnpackCanUart_o2, rty_aacCommand);
    if (rty_aacCommand[1] == GCU_CAN_STOP_COM) {
      GCU_CAN_sendClutchCommand(0, rty_clutchCommand);
    }
  } else if (localDW->UnpackCanUart_o1 == GCU__SW_TRACTION_CONTROL_GCU_ID) {
    localDW->is_c3_GCU_CAN = GCU_CAN_IN_SET_TRACTION;
    *tractionValue = localDW->UnpackCanUart_o2 * 100U;

    /* Chart: '<Root>/MessageEvaluation' incorporates:
     *  SubSystem: '<Root>/TractionValue'
     */
    GCU_CAN_TractionValue(*tractionValue, rty_tractionValue,
                          &localDW->TractionValue);
  } else {
    localDW->is_c3_GCU_CAN = GCU_CAN_IN_IDLE;
  }
}

/* Function for Chart: '<Root>/MessageEvaluation' */
static void GCU_CAN_GEAR_RPM_UPDATE(uint16_T *aac_externValue, uint16_T
  *aac_externValues_index, uint32_T *tractionValue, const uint8_T
  *rtu_clutchCurrVal, uint16_T *rty_currGear, uint16_T rty_aac_externValue[3],
  uint16_T rty_shiftCommand[2], uint8_T *rty_startEngCommand, uint16_T
  rty_aacCommand[2], uint8_T rty_clutchCommand[2], uint32_T *rty_tractionValue,
  DW_GCU_CAN_f_T *localDW)
{
  uint8_T clutchSetVal;
  *aac_externValues_index = (uint16_T)RPM;
  if (localDW->UnpackCanUart_o1 == GCU_CA_EFI_GEAR_RPM_TPS_APPS_ID) {
    localDW->is_c3_GCU_CAN = GCU_CAN_IN_GEAR_RPM_UPDATE;
    *rty_currGear = localDW->UnpackCanUart_o2;
    *aac_externValues_index = (uint16_T)RPM;
    *aac_externValue = localDW->UnpackCanUart_o3;

    /* Chart: '<Root>/MessageEvaluation' incorporates:
     *  SubSystem: '<Root>/AAC_ExternalValues'
     */
    GCU_CAN_AAC_ExternalValues(*aac_externValue, *aac_externValues_index,
      rty_aac_externValue, &localDW->AAC_ExternalValues);
  } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_FIRE_GCU_ID) {
    localDW->is_c3_GCU_CAN = GCU_CAN_IN_START_ENGINE;
    GCU_CAN_sendStartEngCommand(rty_startEngCommand);
  } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_GEARSHIFT_ID) {
    localDW->is_c3_GCU_CAN = GCU_CAN_IN_SW_GEARSHIFT;
    if ((localDW->UnpackCanUart_o2 != GCU_CAN_RPM_LIMITER_ON) &&
        (localDW->UnpackCanUart_o2 != GCU_CAN_RPM_LIMITER_OFF)) {
      GCU_CAN_sendShiftCommand(localDW->UnpackCanUart_o2, rtu_clutchCurrVal,
        rty_shiftCommand, rty_aacCommand);
    }
  } else if (localDW->UnpackCanUart_o1 == GCU_CAN_EFI_TRACTION_CONTROL_ID) {
    localDW->is_c3_GCU_CAN = GCU_CAN_IN_WHEEL_SPEED_UPDATE;
    *aac_externValues_index = (uint16_T)WHEEL_SPEED;
    *aac_externValue = (uint16_T)rt_roundd((real_T)localDW->UnpackCanUart_o2 /
      10.0);

    /* Chart: '<Root>/MessageEvaluation' incorporates:
     *  SubSystem: '<Root>/AAC_ExternalValues'
     */
    GCU_CAN_AAC_ExternalValues(*aac_externValue, *aac_externValues_index,
      rty_aac_externValue, &localDW->AAC_ExternalValues);
  } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_CLUTCH_TARGET_GCU_ID) {
    localDW->is_c3_GCU_CAN = GCU_CAN_IN_SET_CLUTCH;
    clutchSetVal = (uint8_T)((uint32_T)localDW->UnpackCanUart_o2 >> 8);
    if (clutchSetVal > GCU_CAN_AAC_CLUTCH_NOISE_LEVEL) {
      GCU_CAN_sendAacCommand(GCU_CAN_STOP_COM, rty_aacCommand);
    }

    GCU_CAN_sendClutchCommand(clutchSetVal, rty_clutchCommand);
  } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_ACCELERATION_GCU_ID) {
    localDW->is_c3_GCU_CAN = GCU_CAN_IN_AAC_COM;
    GCU_CAN_sendAacCommand(localDW->UnpackCanUart_o2, rty_aacCommand);
    if (rty_aacCommand[1] == GCU_CAN_STOP_COM) {
      GCU_CAN_sendClutchCommand(0, rty_clutchCommand);
    }
  } else if (localDW->UnpackCanUart_o1 == GCU__SW_TRACTION_CONTROL_GCU_ID) {
    localDW->is_c3_GCU_CAN = GCU_CAN_IN_SET_TRACTION;
    *tractionValue = localDW->UnpackCanUart_o2 * 100U;

    /* Chart: '<Root>/MessageEvaluation' incorporates:
     *  SubSystem: '<Root>/TractionValue'
     */
    GCU_CAN_TractionValue(*tractionValue, rty_tractionValue,
                          &localDW->TractionValue);
  } else {
    localDW->is_c3_GCU_CAN = GCU_CAN_IN_IDLE;
  }
}

/* System initialize for referenced model: 'GCU_CAN' */
void GCU_CAN_Init(uint16_T rty_shiftCommand[2], uint16_T rty_aacCommand[2],
                  uint8_T rty_clutchCommand[2])
{
  /* SystemInitialize for Chart: '<Root>/MessageEvaluation' */
  rty_shiftCommand[0] = 0U;
  rty_shiftCommand[1] = 0U;
  rty_aacCommand[0] = 0U;
  rty_aacCommand[1] = 0U;
  rty_clutchCommand[0] = 0U;
  rty_clutchCommand[1] = 0U;
}

/* Output and update for referenced model: 'GCU_CAN' */
void GCU_CAN(const uint8_T *rtu_clutchCurrVal, const uint8_T rtu_dataBuffer[10],
             uint16_T *rty_currGear, uint16_T rty_aac_externValue[3], uint16_T
             rty_shiftCommand[2], uint8_T *rty_startEngCommand, uint16_T
             rty_aacCommand[2], uint8_T rty_clutchCommand[2], uint32_T
             *rty_tractionValue, DW_GCU_CAN_f_T *localDW)
{
  uint8_T clutchSetVal;
  uint16_T aac_externValue;
  uint16_T aac_externValues_index;
  uint32_T tractionValue;

  /* S-Function (UnpackCanUART): '<Root>/UnpackCanUart' */
  UnpackCanUART_Outputs_wrapper(&rtu_dataBuffer[0], &localDW->UnpackCanUart_o1,
    &localDW->UnpackCanUart_o2, &localDW->UnpackCanUart_o3,
    &localDW->UnpackCanUart_o4, &localDW->UnpackCanUart_o5);

  /* Chart: '<Root>/MessageEvaluation' */
  if (localDW->is_active_c3_GCU_CAN == 0U) {
    localDW->is_active_c3_GCU_CAN = 1U;
    localDW->is_c3_GCU_CAN = GCU_CAN_IN_IDLE;
  } else {
    switch (localDW->is_c3_GCU_CAN) {
     case GCU_CAN_IN_AAC_COM:
      GCU_CAN_AAC_COM(&aac_externValue, &aac_externValues_index, &tractionValue,
                      rtu_clutchCurrVal, rty_currGear, rty_aac_externValue,
                      rty_shiftCommand, rty_startEngCommand, rty_aacCommand,
                      rty_clutchCommand, rty_tractionValue, localDW);
      break;

     case GCU_CAN_IN_GEAR_RPM_UPDATE:
      GCU_CAN_GEAR_RPM_UPDATE(&aac_externValue, &aac_externValues_index,
        &tractionValue, rtu_clutchCurrVal, rty_currGear, rty_aac_externValue,
        rty_shiftCommand, rty_startEngCommand, rty_aacCommand, rty_clutchCommand,
        rty_tractionValue, localDW);
      break;

     case GCU_CAN_IN_IDLE:
      if (localDW->UnpackCanUart_o1 == GCU_CA_EFI_GEAR_RPM_TPS_APPS_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_GEAR_RPM_UPDATE;
        *rty_currGear = localDW->UnpackCanUart_o2;

        /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
        GCU_CAN_AAC_ExternalValues(localDW->UnpackCanUart_o3, (uint16_T)RPM,
          rty_aac_externValue, &localDW->AAC_ExternalValues);

        /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
      } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_FIRE_GCU_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_START_ENGINE;
        GCU_CAN_sendStartEngCommand(rty_startEngCommand);
      } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_GEARSHIFT_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_SW_GEARSHIFT;
        if ((localDW->UnpackCanUart_o2 != GCU_CAN_RPM_LIMITER_ON) &&
            (localDW->UnpackCanUart_o2 != GCU_CAN_RPM_LIMITER_OFF)) {
          GCU_CAN_sendShiftCommand(localDW->UnpackCanUart_o2, rtu_clutchCurrVal,
            rty_shiftCommand, rty_aacCommand);
        }
      } else if (localDW->UnpackCanUart_o1 == GCU_CAN_EFI_TRACTION_CONTROL_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_WHEEL_SPEED_UPDATE;

        /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
        GCU_CAN_AAC_ExternalValues((uint16_T)rt_roundd((real_T)
          localDW->UnpackCanUart_o2 / 10.0), (uint16_T)WHEEL_SPEED,
          rty_aac_externValue, &localDW->AAC_ExternalValues);

        /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
      } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_CLUTCH_TARGET_GCU_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_SET_CLUTCH;
        clutchSetVal = (uint8_T)((uint32_T)localDW->UnpackCanUart_o2 >> 8);
        if (clutchSetVal > GCU_CAN_AAC_CLUTCH_NOISE_LEVEL) {
          GCU_CAN_sendAacCommand(GCU_CAN_STOP_COM, rty_aacCommand);
        }

        GCU_CAN_sendClutchCommand(clutchSetVal, rty_clutchCommand);
      } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_ACCELERATION_GCU_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_AAC_COM;
        GCU_CAN_sendAacCommand(localDW->UnpackCanUart_o2, rty_aacCommand);
        if (rty_aacCommand[1] == GCU_CAN_STOP_COM) {
          GCU_CAN_sendClutchCommand(0, rty_clutchCommand);
        }
      } else if (localDW->UnpackCanUart_o1 == GCU__SW_TRACTION_CONTROL_GCU_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_SET_TRACTION;

        /* Outputs for Function Call SubSystem: '<Root>/TractionValue' */
        GCU_CAN_TractionValue(localDW->UnpackCanUart_o2 * 100U,
                              rty_tractionValue, &localDW->TractionValue);

        /* End of Outputs for SubSystem: '<Root>/TractionValue' */
      } else {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_IDLE;
      }
      break;

     case GCU_CAN_IN_SET_CLUTCH:
      if (localDW->UnpackCanUart_o1 == GCU_CA_EFI_GEAR_RPM_TPS_APPS_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_GEAR_RPM_UPDATE;
        *rty_currGear = localDW->UnpackCanUart_o2;

        /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
        GCU_CAN_AAC_ExternalValues(localDW->UnpackCanUart_o3, (uint16_T)RPM,
          rty_aac_externValue, &localDW->AAC_ExternalValues);

        /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
      } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_FIRE_GCU_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_START_ENGINE;
        GCU_CAN_sendStartEngCommand(rty_startEngCommand);
      } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_GEARSHIFT_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_SW_GEARSHIFT;
        if ((localDW->UnpackCanUart_o2 != GCU_CAN_RPM_LIMITER_ON) &&
            (localDW->UnpackCanUart_o2 != GCU_CAN_RPM_LIMITER_OFF)) {
          GCU_CAN_sendShiftCommand(localDW->UnpackCanUart_o2, rtu_clutchCurrVal,
            rty_shiftCommand, rty_aacCommand);
        }
      } else if (localDW->UnpackCanUart_o1 == GCU_CAN_EFI_TRACTION_CONTROL_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_WHEEL_SPEED_UPDATE;

        /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
        GCU_CAN_AAC_ExternalValues((uint16_T)rt_roundd((real_T)
          localDW->UnpackCanUart_o2 / 10.0), (uint16_T)WHEEL_SPEED,
          rty_aac_externValue, &localDW->AAC_ExternalValues);

        /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
      } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_CLUTCH_TARGET_GCU_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_SET_CLUTCH;
        clutchSetVal = (uint8_T)((uint32_T)localDW->UnpackCanUart_o2 >> 8);
        if (clutchSetVal > GCU_CAN_AAC_CLUTCH_NOISE_LEVEL) {
          GCU_CAN_sendAacCommand(GCU_CAN_STOP_COM, rty_aacCommand);
        }

        GCU_CAN_sendClutchCommand(clutchSetVal, rty_clutchCommand);
      } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_ACCELERATION_GCU_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_AAC_COM;
        GCU_CAN_sendAacCommand(localDW->UnpackCanUart_o2, rty_aacCommand);
        if (rty_aacCommand[1] == GCU_CAN_STOP_COM) {
          GCU_CAN_sendClutchCommand(0, rty_clutchCommand);
        }
      } else if (localDW->UnpackCanUart_o1 == GCU__SW_TRACTION_CONTROL_GCU_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_SET_TRACTION;

        /* Outputs for Function Call SubSystem: '<Root>/TractionValue' */
        GCU_CAN_TractionValue(localDW->UnpackCanUart_o2 * 100U,
                              rty_tractionValue, &localDW->TractionValue);

        /* End of Outputs for SubSystem: '<Root>/TractionValue' */
      } else {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_IDLE;
      }
      break;

     case GCU_CAN_IN_SET_TRACTION:
      if (localDW->UnpackCanUart_o1 == GCU_CA_EFI_GEAR_RPM_TPS_APPS_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_GEAR_RPM_UPDATE;
        *rty_currGear = localDW->UnpackCanUart_o2;

        /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
        GCU_CAN_AAC_ExternalValues(localDW->UnpackCanUart_o3, (uint16_T)RPM,
          rty_aac_externValue, &localDW->AAC_ExternalValues);

        /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
      } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_FIRE_GCU_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_START_ENGINE;
        GCU_CAN_sendStartEngCommand(rty_startEngCommand);
      } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_GEARSHIFT_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_SW_GEARSHIFT;
        if ((localDW->UnpackCanUart_o2 != GCU_CAN_RPM_LIMITER_ON) &&
            (localDW->UnpackCanUart_o2 != GCU_CAN_RPM_LIMITER_OFF)) {
          GCU_CAN_sendShiftCommand(localDW->UnpackCanUart_o2, rtu_clutchCurrVal,
            rty_shiftCommand, rty_aacCommand);
        }
      } else if (localDW->UnpackCanUart_o1 == GCU_CAN_EFI_TRACTION_CONTROL_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_WHEEL_SPEED_UPDATE;

        /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
        GCU_CAN_AAC_ExternalValues((uint16_T)rt_roundd((real_T)
          localDW->UnpackCanUart_o2 / 10.0), (uint16_T)WHEEL_SPEED,
          rty_aac_externValue, &localDW->AAC_ExternalValues);

        /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
      } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_CLUTCH_TARGET_GCU_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_SET_CLUTCH;
        clutchSetVal = (uint8_T)((uint32_T)localDW->UnpackCanUart_o2 >> 8);
        if (clutchSetVal > GCU_CAN_AAC_CLUTCH_NOISE_LEVEL) {
          GCU_CAN_sendAacCommand(GCU_CAN_STOP_COM, rty_aacCommand);
        }

        GCU_CAN_sendClutchCommand(clutchSetVal, rty_clutchCommand);
      } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_ACCELERATION_GCU_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_AAC_COM;
        GCU_CAN_sendAacCommand(localDW->UnpackCanUart_o2, rty_aacCommand);
        if (rty_aacCommand[1] == GCU_CAN_STOP_COM) {
          GCU_CAN_sendClutchCommand(0, rty_clutchCommand);
        }
      } else if (localDW->UnpackCanUart_o1 == GCU__SW_TRACTION_CONTROL_GCU_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_SET_TRACTION;

        /* Outputs for Function Call SubSystem: '<Root>/TractionValue' */
        GCU_CAN_TractionValue(localDW->UnpackCanUart_o2 * 100U,
                              rty_tractionValue, &localDW->TractionValue);

        /* End of Outputs for SubSystem: '<Root>/TractionValue' */
      } else {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_IDLE;
      }
      break;

     case GCU_CAN_IN_START_ENGINE:
      if (localDW->UnpackCanUart_o1 == GCU_CA_EFI_GEAR_RPM_TPS_APPS_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_GEAR_RPM_UPDATE;
        *rty_currGear = localDW->UnpackCanUart_o2;

        /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
        GCU_CAN_AAC_ExternalValues(localDW->UnpackCanUart_o3, (uint16_T)RPM,
          rty_aac_externValue, &localDW->AAC_ExternalValues);

        /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
      } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_FIRE_GCU_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_START_ENGINE;
        GCU_CAN_sendStartEngCommand(rty_startEngCommand);
      } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_GEARSHIFT_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_SW_GEARSHIFT;
        if ((localDW->UnpackCanUart_o2 != GCU_CAN_RPM_LIMITER_ON) &&
            (localDW->UnpackCanUart_o2 != GCU_CAN_RPM_LIMITER_OFF)) {
          GCU_CAN_sendShiftCommand(localDW->UnpackCanUart_o2, rtu_clutchCurrVal,
            rty_shiftCommand, rty_aacCommand);
        }
      } else if (localDW->UnpackCanUart_o1 == GCU_CAN_EFI_TRACTION_CONTROL_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_WHEEL_SPEED_UPDATE;

        /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
        GCU_CAN_AAC_ExternalValues((uint16_T)rt_roundd((real_T)
          localDW->UnpackCanUart_o2 / 10.0), (uint16_T)WHEEL_SPEED,
          rty_aac_externValue, &localDW->AAC_ExternalValues);

        /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
      } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_CLUTCH_TARGET_GCU_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_SET_CLUTCH;
        clutchSetVal = (uint8_T)((uint32_T)localDW->UnpackCanUart_o2 >> 8);
        if (clutchSetVal > GCU_CAN_AAC_CLUTCH_NOISE_LEVEL) {
          GCU_CAN_sendAacCommand(GCU_CAN_STOP_COM, rty_aacCommand);
        }

        GCU_CAN_sendClutchCommand(clutchSetVal, rty_clutchCommand);
      } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_ACCELERATION_GCU_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_AAC_COM;
        GCU_CAN_sendAacCommand(localDW->UnpackCanUart_o2, rty_aacCommand);
        if (rty_aacCommand[1] == GCU_CAN_STOP_COM) {
          GCU_CAN_sendClutchCommand(0, rty_clutchCommand);
        }
      } else if (localDW->UnpackCanUart_o1 == GCU__SW_TRACTION_CONTROL_GCU_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_SET_TRACTION;

        /* Outputs for Function Call SubSystem: '<Root>/TractionValue' */
        GCU_CAN_TractionValue(localDW->UnpackCanUart_o2 * 100U,
                              rty_tractionValue, &localDW->TractionValue);

        /* End of Outputs for SubSystem: '<Root>/TractionValue' */
      } else {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_IDLE;
      }
      break;

     case GCU_CAN_IN_SW_GEARSHIFT:
      if (localDW->UnpackCanUart_o1 == GCU_CA_EFI_GEAR_RPM_TPS_APPS_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_GEAR_RPM_UPDATE;
        *rty_currGear = localDW->UnpackCanUart_o2;

        /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
        GCU_CAN_AAC_ExternalValues(localDW->UnpackCanUart_o3, (uint16_T)RPM,
          rty_aac_externValue, &localDW->AAC_ExternalValues);

        /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
      } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_FIRE_GCU_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_START_ENGINE;
        GCU_CAN_sendStartEngCommand(rty_startEngCommand);
      } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_GEARSHIFT_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_SW_GEARSHIFT;
        if ((localDW->UnpackCanUart_o2 != GCU_CAN_RPM_LIMITER_ON) &&
            (localDW->UnpackCanUart_o2 != GCU_CAN_RPM_LIMITER_OFF)) {
          GCU_CAN_sendShiftCommand(localDW->UnpackCanUart_o2, rtu_clutchCurrVal,
            rty_shiftCommand, rty_aacCommand);
        }
      } else if (localDW->UnpackCanUart_o1 == GCU_CAN_EFI_TRACTION_CONTROL_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_WHEEL_SPEED_UPDATE;

        /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
        GCU_CAN_AAC_ExternalValues((uint16_T)rt_roundd((real_T)
          localDW->UnpackCanUart_o2 / 10.0), (uint16_T)WHEEL_SPEED,
          rty_aac_externValue, &localDW->AAC_ExternalValues);

        /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
      } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_CLUTCH_TARGET_GCU_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_SET_CLUTCH;
        clutchSetVal = (uint8_T)((uint32_T)localDW->UnpackCanUart_o2 >> 8);
        if (clutchSetVal > GCU_CAN_AAC_CLUTCH_NOISE_LEVEL) {
          GCU_CAN_sendAacCommand(GCU_CAN_STOP_COM, rty_aacCommand);
        }

        GCU_CAN_sendClutchCommand(clutchSetVal, rty_clutchCommand);
      } else if (localDW->UnpackCanUart_o1 == GCU_CAN_SW_ACCELERATION_GCU_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_AAC_COM;
        GCU_CAN_sendAacCommand(localDW->UnpackCanUart_o2, rty_aacCommand);
        if (rty_aacCommand[1] == GCU_CAN_STOP_COM) {
          GCU_CAN_sendClutchCommand(0, rty_clutchCommand);
        }
      } else if (localDW->UnpackCanUart_o1 == GCU__SW_TRACTION_CONTROL_GCU_ID) {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_SET_TRACTION;

        /* Outputs for Function Call SubSystem: '<Root>/TractionValue' */
        GCU_CAN_TractionValue(localDW->UnpackCanUart_o2 * 100U,
                              rty_tractionValue, &localDW->TractionValue);

        /* End of Outputs for SubSystem: '<Root>/TractionValue' */
      } else {
        localDW->is_c3_GCU_CAN = GCU_CAN_IN_IDLE;
      }
      break;

     default:
      GCU_CAN_WHEEL_SPEED_UPDATE(&aac_externValue, &aac_externValues_index,
        &tractionValue, rtu_clutchCurrVal, rty_currGear, rty_aac_externValue,
        rty_shiftCommand, rty_startEngCommand, rty_aacCommand, rty_clutchCommand,
        rty_tractionValue, localDW);
      break;
    }
  }

  /* End of Chart: '<Root>/MessageEvaluation' */
}

/* Model initialize function */
void GCU_CAN_initialize(const char_T **rt_errorStatus, RT_MODEL_GCU_CAN_T *const
  GCU_CAN_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(GCU_CAN_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
