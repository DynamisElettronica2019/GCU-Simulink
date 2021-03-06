/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GCU_Model_genCode.c
 *
 * Code generated for Simulink model 'GCU_Model_genCode'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Sun Feb 24 14:02:14 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "GCU_Model_genCode.h"

/* Named constants for Chart: '<Root>/AccelerationRoutine' */
#define IN_ActivateAac                 ((uint8_T)1U)
#define IN_DajeDeGas                   ((uint8_T)2U)
#define IN_EXIT                        ((uint8_T)3U)
#define IN_InsertGear                  ((uint8_T)4U)
#define IN_Ready                       ((uint8_T)5U)
#define IN_Wait                        ((uint8_T)6U)
#define IN_delay                       ((uint8_T)7U)

/* Named constants for Chart: '<S4>/MessageEvaluation' */
#define AAC_CLUTCH_NOISE_LEVEL         ((uint8_T)30U)
#define EFI_GEAR_RPM_TPS_APPS_ID       ((uint16_T)773U)
#define EFI_TRACTION_CONTROL_ID        ((uint16_T)774U)
#define IN_AAC_COM                     ((uint8_T)1U)
#define IN_GEAR_RPM_UPDATE             ((uint8_T)2U)
#define IN_IDLE                        ((uint8_T)3U)
#define IN_SET_CLUTCH                  ((uint8_T)4U)
#define IN_SET_TRACTION                ((uint8_T)5U)
#define IN_START_ENGINE                ((uint8_T)6U)
#define IN_SW_GEARSHIFT                ((uint8_T)7U)
#define IN_WHEEL_SPEED_UPDATE          ((uint8_T)8U)
#define RPM_LIMITER_OFF                ((uint16_T)160U)
#define RPM_LIMITER_ON                 ((uint16_T)150U)
#define STOP_COM                       ((uint16_T)0U)
#define SW_ACCELERATION_GCU_ID         ((uint16_T)514U)
#define SW_CLUTCH_TARGET_GCU_ID        ((uint16_T)513U)
#define SW_FIRE_GCU_ID                 ((uint16_T)516U)
#define SW_GEARSHIFT_ID                ((uint16_T)512U)
#define SW_TRACTION_CONTROL_GCU_ID     ((uint16_T)515U)

/* Named constants for Chart: '<S5>/GCULogic' */
#define AAC_WORK_RATE_ms               ((uint16_T)25U)
#define ACC_CODE                       ((uint16_T)1U)
#define GEAR_COMMAND_DOWN              ((uint16_T)200U)
#define GEAR_COMMAND_NEUTRAL_DOWN      ((uint16_T)100U)
#define GEAR_COMMAND_NEUTRAL_UP        ((uint16_T)50U)
#define GEAR_COMMAND_UP                ((uint16_T)400U)
#define IN_AAC                         ((uint8_T)1U)
#define IN_ACTIVE                      ((uint8_T)1U)
#define IN_AUTOCROSS                   ((uint8_T)2U)
#define IN_ChangeClutch                ((uint8_T)1U)
#define IN_CutOff                      ((uint8_T)1U)
#define IN_DOWNSHIFTING                ((uint8_T)1U)
#define IN_DOWN_BRAKE                  ((uint8_T)1U)
#define IN_DOWN_END                    ((uint8_T)2U)
#define IN_DOWN_PUSH                   ((uint8_T)2U)
#define IN_DOWN_REBOUND                ((uint8_T)3U)
#define IN_DOWN_START                  ((uint8_T)4U)
#define IN_Default                     ((uint8_T)1U)
#define IN_Default_p                   ((uint8_T)2U)
#define IN_ENDURANCE                   ((uint8_T)3U)
#define IN_INIT                        ((uint8_T)4U)
#define IN_NEUTRAL                     ((uint8_T)1U)
#define IN_NO_NEUTRAL                  ((uint8_T)2U)
#define IN_READY                       ((uint8_T)1U)
#define IN_RELEASING                   ((uint8_T)2U)
#define IN_RUNNING                     ((uint8_T)3U)
#define IN_SET_NEUTRAL                 ((uint8_T)3U)
#define IN_SKIDPAD                     ((uint8_T)5U)
#define IN_START                       ((uint8_T)4U)
#define IN_START_RELEASE               ((uint8_T)5U)
#define IN_START_o                     ((uint8_T)1U)
#define IN_STOP                        ((uint8_T)2U)
#define IN_STOPPING                    ((uint8_T)2U)
#define IN_SettingNeutral              ((uint8_T)2U)
#define IN_SettingNeutral_i            ((uint8_T)3U)
#define IN_UNSET_NEUTRAL               ((uint8_T)4U)
#define IN_UPSHIFTING                  ((uint8_T)5U)
#define IN_UP_BRAKE                    ((uint8_T)1U)
#define IN_UP_END                      ((uint8_T)6U)
#define IN_UP_PUSH                     ((uint8_T)2U)
#define IN_UP_REBOUND                  ((uint8_T)3U)
#define IN_UP_START                    ((uint8_T)4U)
#define IN_WAIT                        ((uint8_T)3U)
#define RELEASE_AAC_COM                ((uint16_T)2U)
#define START_AAC_COM                  ((uint16_T)1U)
#define STOP_AAC_COM                   ((uint16_T)0U)
#define event_GearshiftDown            (0)
#define event_GearshiftSetNeutral      (1)
#define event_GearshiftUp              (2)

const uint16_T GCU_Model_genCode_U16GND = 0U;/* uint16_T ground */

/* Block signals and states (default storage) */
DW rtDW;

/* Previous zero-crossings (trigger) states */
PrevZCX rtPrevZCX;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

#ifdef __cplusplus

extern "C" {

#endif

  extern void Efi_init_Start_wrapper(void);
  extern void Efi_init_Outputs_wrapper(void);
  extern void Efi_init_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void PackCanUART_Start_wrapper(void);
  extern void PackCanUART_Outputs_wrapper(const uint16_T *id,
    const uint16_T *firstInt,
    const uint16_T *secondInt,
    const uint16_T *thirdInt,
    const uint16_T *fourthInt,
    uint8_T *message);
  extern void PackCanUART_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Efi_setRPMLimiter_Start_wrapper(void);
  extern void Efi_setRPMLimiter_Outputs_wrapper(uint8_T *rpmLimiter_pin);
  extern void Efi_setRPMLimiter_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Efi_unsetRPMLimiter_Start_wrapper(void);
  extern void Efi_unsetRPMLimiter_Outputs_wrapper(uint8_T *rpmLimiter_pin);
  extern void Efi_unsetRPMLimiter_Terminate_wrapper(void);

#ifdef __cplusplus

}
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

#ifdef __cplusplus

extern "C" {

#endif

  extern void ClutchMotor_init_Start_wrapper(void);
  extern void ClutchMotor_init_Outputs_wrapper(void);
  extern void ClutchMotor_init_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void ClutchMotor_setPosition_Start_wrapper(void);
  extern void ClutchMotor_setPosition_Outputs_wrapper(const uint8_T *percentage);
  extern void ClutchMotor_setPosition_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Efi_setBlip_Start_wrapper(void);
  extern void Efi_setBlip_Outputs_wrapper(uint8_T *downCut_pin);
  extern void Efi_setBlip_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Efi_unsetBlip_Start_wrapper(void);
  extern void Efi_unsetBlip_Outputs_wrapper(uint8_T *downCut_pin);
  extern void Efi_unsetBlip_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void GearMotor_release_Start_wrapper(void);
  extern void GearMotor_release_Outputs_wrapper(uint8_T *GearMotor_H);
  extern void GearMotor_release_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void GearMotor_turnRight_Start_wrapper(void);
  extern void GearMotor_turnRight_Outputs_wrapper(uint8_T *GearMotor_In1,
    uint8_T *GearMotor_In2,
    uint8_T *GearMotor_H);
  extern void GearMotor_turnRight_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void GearMotor_turnLeft_Start_wrapper(void);
  extern void GearMotor_turnLeft_Outputs_wrapper(uint8_T *GearMotor_In1,
    uint8_T *GearMotor_In2,
    uint8_T *GearMotor_H);
  extern void GearMotor_turnLeft_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void GearMotor_brake_Start_wrapper(void);
  extern void GearMotor_brake_Outputs_wrapper(uint8_T *GearMotor_In1,
    uint8_T *GearMotor_In2,
    uint8_T *GearMotor_H);
  extern void GearMotor_brake_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void EngineControl_start_Start_wrapper(void);
  extern void EngineControl_start_Outputs_wrapper(uint8_T *engine_starter);
  extern void EngineControl_start_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void EngineControl_stop_Start_wrapper(void);
  extern void EngineControl_stop_Outputs_wrapper(uint8_T *engine_starter);
  extern void EngineControl_stop_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

extern real_T rt_roundd_snf(real_T u);
static void TractionValue(uint16_T rtu_Value, uint16_T *rty_tractionValue,
  DW_TractionValue *localDW);
static void Efi_setRpmLimiter(uint8_T *rty_rpmLimiter_pin, DW_Efi_setRpmLimiter *
  localDW);
static void Efi_unsetRpmLimiter(uint8_T *rty_rpmLimiter_pin,
  DW_Efi_unsetRpmLimiter *localDW);
static void AAC_ExternalValues(uint16_T rtu_Value, uint16_T rtu_Index, uint16_T
  rty_Values[3], DW_AAC_ExternalValues *localDW);
static void SetCut(uint8_T *rty_downCut_pin, DW_SetCut *localDW);
static void UnsetCut(uint8_T *rty_downCut_pin, DW_UnsetCut *localDW);
static void Gearmotor_turnRight(uint8_T *rty_Pin_In1, uint8_T *rty_Pin_In2,
  uint8_T *rty_Pin_H, DW_Gearmotor_turnRight *localDW);
static void Gearmotor_brake(uint8_T *rty_Pin_In1, uint8_T *rty_Pin_In2, uint8_T *
  rty_Pin_H, DW_Gearmotor_brake *localDW);
static void EngineControl_Start(uint8_T *rty_engine_starter,
  DW_EngineControl_Start *localDW);
static void sendUpdatesSW(uint16_T rtu_valCode, uint16_T rtu_value,
  DW_sendUpdatesSW *localDW);
static void Gearmotor_release(void);

/* Forward declaration for local functions */
static void NEUTRAL_STATE(void);
static int32_T Gearshift_getTime(void);
static void Clutch_setValue(uint8_T setValue);
static void GEARSHIFT(void);
static void checkShift(void);
static int32_T getAacParam(aac_params b_index);
static void aacCheckShift(void);
static void ACTIVE(void);
static void checkClutch(void);
static void updateData(void);
static void checkGear(void);
static void sendAacCommand(uint16_T com);
static void sendClutchCommand(uint8_T com);
static void sendShiftCommand(uint16_T com);
static void sendStartEngCommand(void);
static void WHEEL_SPEED_UPDATE(uint16_T *tractionValue, uint16_T
  *aac_externValues_index, uint16_T *aac_externValue, uint16_T *Assignment_b);
static void AAC_COM(uint16_T *tractionValue, uint16_T *aac_externValues_index,
                    uint16_T *aac_externValue, uint16_T *Assignment_b);
static void GEAR_RPM_UPDATE(uint16_T *tractionValue, uint16_T
  *aac_externValues_index, uint16_T *aac_externValue, uint16_T *Assignment_b);

/* Output and update for function-call system: '<S4>/TractionValue' */
static void TractionValue(uint16_T rtu_Value, uint16_T *rty_tractionValue,
  DW_TractionValue *localDW)
{
  /* Assignment: '<S10>/Assignment' incorporates:
   *  UnitDelay: '<S10>/Unit Delay'
   */
  *rty_tractionValue = localDW->UnitDelay_DSTATE;
  *rty_tractionValue = rtu_Value;

  /* S-Function (PackCanUART): '<S13>/PackCanUart' incorporates:
   *  Constant: '<S13>/GCU_TRACTION_CONTROL_EFI_ID'
   */
  PackCanUART_Outputs_wrapper(&rtConstP.GCU_TRACTION_CONTROL_EFI_ID_Val,
    rty_tractionValue, (uint16_T*)&GCU_Model_genCode_U16GND, (uint16_T*)
    &GCU_Model_genCode_U16GND, (uint16_T*)&GCU_Model_genCode_U16GND,
    &localDW->PackCanUart[0]);

  /* Product: '<S10>/Divide' */
  localDW->Divide = (uint16_T)(*rty_tractionValue / 100U);

  /* S-Function (PackCanUART): '<S14>/PackCanUart' incorporates:
   *  Constant: '<S10>/TRACTION_CODE'
   *  Constant: '<S14>/GCU_FEEDBACK_ID'
   */
  PackCanUART_Outputs_wrapper(&rtConstP.pooled1, &rtConstP.TRACTION_CODE_Value,
    &localDW->Divide, (uint16_T*)&GCU_Model_genCode_U16GND, (uint16_T*)
    &GCU_Model_genCode_U16GND, &localDW->PackCanUart_c[0]);

  /* Update for UnitDelay: '<S10>/Unit Delay' */
  localDW->UnitDelay_DSTATE = *rty_tractionValue;
}

/* Output and update for function-call system: '<S8>/Efi_setRpmLimiter' */
static void Efi_setRpmLimiter(uint8_T *rty_rpmLimiter_pin, DW_Efi_setRpmLimiter *
  localDW)
{
  /* S-Function (Efi_setRPMLimiter): '<S11>/Efi SetRPMLimiter' */
  Efi_setRPMLimiter_Outputs_wrapper(&localDW->EfiSetRPMLimiter);

  /* SignalConversion: '<S11>/OutportBufferForrpmLimiter_pin' */
  *rty_rpmLimiter_pin = localDW->EfiSetRPMLimiter;
}

/* Output and update for function-call system: '<S8>/Efi_unsetRpmLimiter' */
static void Efi_unsetRpmLimiter(uint8_T *rty_rpmLimiter_pin,
  DW_Efi_unsetRpmLimiter *localDW)
{
  /* S-Function (Efi_unsetRPMLimiter): '<S12>/Efi UnSetRPMLimiter' */
  Efi_unsetRPMLimiter_Outputs_wrapper(&localDW->EfiUnSetRPMLimiter);

  /* SignalConversion: '<S12>/OutportBufferForrpmLimiter_pin' */
  *rty_rpmLimiter_pin = localDW->EfiUnSetRPMLimiter;
}

/* Output and update for function-call system: '<S4>/AAC_ExternalValues' */
static void AAC_ExternalValues(uint16_T rtu_Value, uint16_T rtu_Index, uint16_T
  rty_Values[3], DW_AAC_ExternalValues *localDW)
{
  /* Assignment: '<S7>/Assignment' incorporates:
   *  UnitDelay: '<S7>/Unit Delay'
   */
  rty_Values[0] = localDW->UnitDelay_DSTATE[0];
  rty_Values[1] = localDW->UnitDelay_DSTATE[1];
  rty_Values[2] = localDW->UnitDelay_DSTATE[2];
  rty_Values[rtu_Index] = rtu_Value;

  /* Update for UnitDelay: '<S7>/Unit Delay' */
  localDW->UnitDelay_DSTATE[0] = rty_Values[0];
  localDW->UnitDelay_DSTATE[1] = rty_Values[1];
  localDW->UnitDelay_DSTATE[2] = rty_Values[2];
}

/*
 * Output and update for function-call system:
 *    '<S16>/SetCut'
 *    '<S16>/SetRPMLimiter'
 */
static void SetCut(uint8_T *rty_downCut_pin, DW_SetCut *localDW)
{
  /* S-Function (Efi_setBlip): '<S23>/Efi SetBlip' */
  Efi_setBlip_Outputs_wrapper(&localDW->EfiSetBlip);

  /* SignalConversion: '<S23>/OutportBufferFordownCut_pin' */
  *rty_downCut_pin = localDW->EfiSetBlip;
}

/*
 * Output and update for function-call system:
 *    '<S16>/UnsetCut'
 *    '<S16>/UnsetRPMLimiter'
 */
static void UnsetCut(uint8_T *rty_downCut_pin, DW_UnsetCut *localDW)
{
  /* S-Function (Efi_unsetBlip): '<S25>/Efi UnSetBlip' */
  Efi_unsetBlip_Outputs_wrapper(&localDW->EfiUnSetBlip);

  /* SignalConversion: '<S25>/OutportBufferFordownCut_pin' */
  *rty_downCut_pin = localDW->EfiUnSetBlip;
}

/* Output and update for function-call system: '<S19>/Gearmotor_release' */
static void Gearmotor_release(void)
{
  /* S-Function (GearMotor_release): '<S31>/GearMotor Release' */
  GearMotor_release_Outputs_wrapper(&rtDW.GearMotorRelease);

  /* SignalConversion: '<S31>/OutportBufferForPin H' */
  rtDW.Pin_H = rtDW.GearMotorRelease;
}

/* Output and update for function-call system: '<S19>/Gearmotor_turnRight' */
static void Gearmotor_turnRight(uint8_T *rty_Pin_In1, uint8_T *rty_Pin_In2,
  uint8_T *rty_Pin_H, DW_Gearmotor_turnRight *localDW)
{
  /* S-Function (GearMotor_turnRight): '<S33>/GearMotor Turn Right' */
  GearMotor_turnRight_Outputs_wrapper(&localDW->GearMotorTurnRight_o1,
    &localDW->GearMotorTurnRight_o2, &localDW->GearMotorTurnRight_o3);

  /* SignalConversion: '<S33>/OutportBufferForPin_H' */
  *rty_Pin_H = localDW->GearMotorTurnRight_o3;

  /* SignalConversion: '<S33>/OutportBufferForPin_In1' */
  *rty_Pin_In1 = localDW->GearMotorTurnRight_o1;

  /* SignalConversion: '<S33>/OutportBufferForPin_In2' */
  *rty_Pin_In2 = localDW->GearMotorTurnRight_o2;
}

/* Output and update for function-call system: '<S19>/Gearmotor_brake' */
static void Gearmotor_brake(uint8_T *rty_Pin_In1, uint8_T *rty_Pin_In2, uint8_T *
  rty_Pin_H, DW_Gearmotor_brake *localDW)
{
  /* S-Function (GearMotor_brake): '<S30>/GearMotor Brake' */
  GearMotor_brake_Outputs_wrapper(&localDW->GearMotorBrake_o1,
    &localDW->GearMotorBrake_o2, &localDW->GearMotorBrake_o3);

  /* SignalConversion: '<S30>/OutportBufferForPin_H' */
  *rty_Pin_H = localDW->GearMotorBrake_o3;

  /* SignalConversion: '<S30>/OutportBufferForPin_In1' */
  *rty_Pin_In1 = localDW->GearMotorBrake_o1;

  /* SignalConversion: '<S30>/OutportBufferForPin_In2' */
  *rty_Pin_In2 = localDW->GearMotorBrake_o2;
}

/* Output and update for function-call system: '<S17>/EngineControl_Start' */
static void EngineControl_Start(uint8_T *rty_engine_starter,
  DW_EngineControl_Start *localDW)
{
  /* S-Function (EngineControl_start): '<S27>/EngineControl Start' */
  EngineControl_start_Outputs_wrapper(&localDW->EngineControlStart);

  /* SignalConversion: '<S27>/OutportBufferForengine_starter' */
  *rty_engine_starter = localDW->EngineControlStart;
}

/* Output and update for function-call system: '<S18>/sendUpdatesSW' */
static void sendUpdatesSW(uint16_T rtu_valCode, uint16_T rtu_value,
  DW_sendUpdatesSW *localDW)
{
  /* S-Function (PackCanUART): '<S29>/PackCanUart' incorporates:
   *  Constant: '<S29>/GCU_FEEDBACK_ID'
   */
  PackCanUART_Outputs_wrapper(&rtConstP.pooled1, &rtu_valCode, &rtu_value,
    (uint16_T*)&GCU_Model_genCode_U16GND, (uint16_T*)&GCU_Model_genCode_U16GND,
    &localDW->PackCanUart[0]);
}

/* Function for Chart: '<S5>/GCULogic' */
static void NEUTRAL_STATE(void)
{
  switch (rtDW.is_NEUTRAL_STATE) {
   case IN_NEUTRAL:
    if ((rtDW.sfEvent == event_GearshiftUp) || (rtDW.sfEvent ==
         event_GearshiftDown)) {
      rtDW.is_NEUTRAL_STATE = IN_UNSET_NEUTRAL;
    }
    break;

   case IN_NO_NEUTRAL:
    if (rtDW.sfEvent == event_GearshiftSetNeutral) {
      rtDW.is_NEUTRAL_STATE = IN_SET_NEUTRAL;
    }
    break;

   case IN_SET_NEUTRAL:
    if ((rtDW.is_GEARSHIFT == IN_DOWN_END) || (rtDW.is_GEARSHIFT == IN_UP_END))
    {
      rtDW.is_NEUTRAL_STATE = IN_NEUTRAL;
    }
    break;

   case IN_UNSET_NEUTRAL:
    if ((rtDW.is_GEARSHIFT == IN_DOWN_END) || (rtDW.is_GEARSHIFT == IN_UP_END))
    {
      rtDW.is_NEUTRAL_STATE = IN_NO_NEUTRAL;
    }
    break;
  }
}

/* Function for Chart: '<S5>/GCULogic' */
static int32_T Gearshift_getTime(void)
{
  int32_T time;
  if (rtDW.is_UPSHIFTING == IN_UP_START) {
    if (rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) {
      time = DEFAULT_NT_CLUTCH_DELAY;
    } else {
      time = DEFAULT_DELAY;
    }
  } else if (rtDW.is_UPSHIFTING == IN_UP_PUSH) {
    if (rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) {
      time = DEFAULT_NT_CLUTCH_DELAY;
    } else {
      /* Outport: '<Root>/currGear' */
      switch (rtY.currGear) {
       case 1:
        time = DEFAULT_UP_PUSH_1_2;
        break;

       case 2:
        time = DEFAULT_UP_PUSH_2_3;
        break;

       case 3:
        time = DEFAULT_UP_PUSH_3_4;
        break;

       case 4:
        time = DEFAULT_UP_PUSH_4_5;
        break;

       default:
        time = DEFAULT_UP_PUSH_2_3;
        break;
      }

      /* End of Outport: '<Root>/currGear' */
    }
  } else if (rtDW.is_UPSHIFTING == IN_UP_REBOUND) {
    if (rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) {
      time = DEFAULT_NT_REBOUND_1_N;
    } else {
      time = DEFAULT_UP_REBOUND;
    }
  } else if (rtDW.is_UPSHIFTING == IN_UP_BRAKE) {
    if (rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) {
      time = DEFAULT_NT_BRAKE_1_N;
    } else {
      time = DEFAULT_UP_BRAKE;
    }
  } else if (rtDW.is_DOWNSHIFTING == IN_DOWN_START) {
    time = DEFAULT_CLUTCH;
  } else if (rtDW.is_DOWNSHIFTING == IN_DOWN_PUSH) {
    time = DEFAULT_DN_PUSH;
  } else if (rtDW.is_DOWNSHIFTING == IN_DOWN_REBOUND) {
    time = DEFAULT_DN_REBOUND;
  } else {
    time = DEFAULT_DN_BRAKE;
  }

  return time;
}

/* Function for Chart: '<S5>/GCULogic' */
static void Clutch_setValue(uint8_T setValue)
{
  rtDW.clutchCurrVal = setValue;

  /* Outputs for Function Call SubSystem: '<S15>/ClutchMotor SetPosition ' */
  /* Sum: '<S21>/Minus' incorporates:
   *  Constant: '<S21>/Constant'
   */
  rtDW.Minus = (uint8_T)(100 - rtDW.clutchCurrVal);

  /* S-Function (ClutchMotor_setPosition): '<S21>/ClutchMotor SetPosition' */
  ClutchMotor_setPosition_Outputs_wrapper(&rtDW.Minus);

  /* End of Outputs for SubSystem: '<S15>/ClutchMotor SetPosition ' */
}

/* Function for Chart: '<S5>/GCULogic' */
static void GEARSHIFT(void)
{
  uint8_T Pin_In2;
  switch (rtDW.is_GEARSHIFT) {
   case IN_DOWNSHIFTING:
    switch (rtDW.is_DOWNSHIFTING) {
     case IN_DOWN_BRAKE:
      if (rtDW.ticksCounter == 0) {
        rtDW.is_DOWN_BRAKE = 0;
        rtDW.is_DOWNSHIFTING = 0;
        rtDW.is_GEARSHIFT = 0;
        if (rtDW.is_GEARSHIFT != IN_DOWN_END) {
          rtDW.is_GEARSHIFT = IN_DOWN_END;

          /* Outputs for Function Call SubSystem: '<S19>/Gearmotor_release' */
          Gearmotor_release();

          /* End of Outputs for SubSystem: '<S19>/Gearmotor_release' */
        }
      } else if (rtDW.ticksCounter < -2147483647) {
        rtDW.ticksCounter = MIN_int32_T;
      } else {
        rtDW.ticksCounter--;
      }
      break;

     case IN_DOWN_PUSH:
      if (rtDW.ticksCounter == 0) {
        rtDW.is_DOWNSHIFTING = 0;
        if (rtDW.is_DOWNSHIFTING != IN_DOWN_REBOUND) {
          rtDW.is_DOWNSHIFTING = IN_DOWN_REBOUND;
          rtDW.ticksCounter = Gearshift_getTime();

          /* Outputs for Function Call SubSystem: '<S19>/Gearmotor_release' */
          Gearmotor_release();

          /* End of Outputs for SubSystem: '<S19>/Gearmotor_release' */
        }
      } else if (rtDW.ticksCounter < -2147483647) {
        rtDW.ticksCounter = MIN_int32_T;
      } else {
        rtDW.ticksCounter--;
      }
      break;

     case IN_DOWN_REBOUND:
      if (rtDW.ticksCounter == 0) {
        rtDW.is_DOWNSHIFTING = 0;
        if (rtDW.is_DOWNSHIFTING != IN_DOWN_BRAKE) {
          rtDW.is_DOWNSHIFTING = IN_DOWN_BRAKE;
          rtDW.ticksCounter = Gearshift_getTime();
        }

        if (rtDW.clutchCurrVal < 81) {
          if (rtDW.is_DOWN_BRAKE != IN_ChangeClutch) {
            rtDW.is_DOWN_BRAKE = IN_ChangeClutch;
            Clutch_setValue(80);

            /* Outputs for Function Call SubSystem: '<S19>/Gearmotor_brake' */
            Gearmotor_brake(&rtDW.Pin_In1, &Pin_In2, &rtDW.Pin_H,
                            &rtDW.Gearmotor_brake_e);

            /* End of Outputs for SubSystem: '<S19>/Gearmotor_brake' */
          }
        } else {
          if (rtDW.is_DOWN_BRAKE != IN_Default_p) {
            rtDW.is_DOWN_BRAKE = IN_Default_p;

            /* Outputs for Function Call SubSystem: '<S19>/Gearmotor_brake' */
            Gearmotor_brake(&rtDW.Pin_In1, &Pin_In2, &rtDW.Pin_H,
                            &rtDW.Gearmotor_brake_e);

            /* End of Outputs for SubSystem: '<S19>/Gearmotor_brake' */
          }
        }
      } else if (rtDW.ticksCounter < -2147483647) {
        rtDW.ticksCounter = MIN_int32_T;
      } else {
        rtDW.ticksCounter--;
      }
      break;

     case IN_DOWN_START:
      if (rtDW.ticksCounter == 0) {
        rtDW.is_DOWN_START = 0;
        rtDW.is_DOWNSHIFTING = 0;
        if (rtDW.is_DOWNSHIFTING != IN_DOWN_PUSH) {
          rtDW.is_DOWNSHIFTING = IN_DOWN_PUSH;
          rtDW.ticksCounter = Gearshift_getTime();

          /* Outputs for Function Call SubSystem: '<S19>/Gearmotor_turnLeft' */
          /* S-Function (GearMotor_turnLeft): '<S32>/GearMotor Turn Left' */
          GearMotor_turnLeft_Outputs_wrapper(&rtDW.GearMotorTurnLeft_o1,
            &rtDW.GearMotorTurnLeft_o2, &rtDW.GearMotorTurnLeft_o3);

          /* SignalConversion: '<S32>/OutportBufferForPin_H' */
          rtDW.Pin_H = rtDW.GearMotorTurnLeft_o3;

          /* SignalConversion: '<S32>/OutportBufferForPin_In1' */
          rtDW.Pin_In1 = rtDW.GearMotorTurnLeft_o1;

          /* End of Outputs for SubSystem: '<S19>/Gearmotor_turnLeft' */
        }
      } else if (rtDW.ticksCounter < -2147483647) {
        rtDW.ticksCounter = MIN_int32_T;
      } else {
        rtDW.ticksCounter--;
      }
      break;
    }
    break;

   case IN_DOWN_END:
    rtDW.is_GEARSHIFT = 0;
    if (rtDW.is_GEARSHIFT != IN_IDLE) {
      rtDW.is_GEARSHIFT = IN_IDLE;
    }
    break;

   case IN_IDLE:
    switch (rtDW.sfEvent) {
     case event_GearshiftUp:
      rtDW.is_GEARSHIFT = IN_UPSHIFTING;
      if (rtDW.is_UPSHIFTING != IN_UP_START) {
        rtDW.is_UPSHIFTING = IN_UP_START;
        rtDW.ticksCounter = Gearshift_getTime();
      }

      if (rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) {
        if (rtDW.is_UP_START != IN_SettingNeutral) {
          rtDW.is_UP_START = IN_SettingNeutral;
          Clutch_setValue(80);
        }
      } else {
        if (rtDW.is_UP_START != IN_Default) {
          rtDW.is_UP_START = IN_Default;

          /* Outputs for Function Call SubSystem: '<S16>/SetCut' */
          SetCut(&Pin_In2, &rtDW.SetCut_h);

          /* End of Outputs for SubSystem: '<S16>/SetCut' */
        }
      }
      break;

     case event_GearshiftDown:
      rtDW.is_GEARSHIFT = IN_DOWNSHIFTING;
      if (rtDW.is_DOWNSHIFTING != IN_DOWN_START) {
        rtDW.is_DOWNSHIFTING = IN_DOWN_START;
        rtDW.ticksCounter = Gearshift_getTime();
      }

      if ((rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) && (rtDW.clutchCurrVal <= 80))
      {
        if (rtDW.is_DOWN_START != IN_SettingNeutral_i) {
          rtDW.is_DOWN_START = IN_SettingNeutral_i;
          Clutch_setValue(80);
        }
      } else if ((!(rtDW.is_NEUTRAL_STATE == IN_UNSET_NEUTRAL)) &&
                 (rtDW.clutchCurrVal <= 60)) {
        if (rtDW.is_DOWN_START != IN_ChangeClutch) {
          rtDW.is_DOWN_START = IN_ChangeClutch;
          Clutch_setValue(60);
        }
      } else {
        rtDW.is_DOWN_START = IN_Default_p;
      }
      break;
    }
    break;

   case IN_INIT:
    rtDW.is_GEARSHIFT = 0;
    if (rtDW.is_GEARSHIFT != IN_IDLE) {
      rtDW.is_GEARSHIFT = IN_IDLE;
    }
    break;

   case IN_UPSHIFTING:
    switch (rtDW.is_UPSHIFTING) {
     case IN_UP_BRAKE:
      if (rtDW.ticksCounter == 0) {
        rtDW.is_UPSHIFTING = 0;
        rtDW.is_GEARSHIFT = 0;
        if (rtDW.is_GEARSHIFT != IN_UP_END) {
          rtDW.is_GEARSHIFT = IN_UP_END;

          /* Outputs for Function Call SubSystem: '<S19>/Gearmotor_release' */
          Gearmotor_release();

          /* End of Outputs for SubSystem: '<S19>/Gearmotor_release' */
        }
      } else if (rtDW.ticksCounter < -2147483647) {
        rtDW.ticksCounter = MIN_int32_T;
      } else {
        rtDW.ticksCounter--;
      }
      break;

     case IN_UP_PUSH:
      if (rtDW.ticksCounter == 0) {
        rtDW.is_UP_PUSH = 0;
        rtDW.is_UPSHIFTING = 0;
        if (rtDW.is_UPSHIFTING != IN_UP_REBOUND) {
          rtDW.is_UPSHIFTING = IN_UP_REBOUND;
          rtDW.ticksCounter = Gearshift_getTime();
        }

        if (rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) {
          if (rtDW.is_UP_REBOUND != IN_SettingNeutral) {
            rtDW.is_UP_REBOUND = IN_SettingNeutral;
            Clutch_setValue(0);

            /* Outputs for Function Call SubSystem: '<S19>/Gearmotor_release' */
            Gearmotor_release();

            /* End of Outputs for SubSystem: '<S19>/Gearmotor_release' */
          }
        } else {
          if (rtDW.is_UP_REBOUND != IN_Default) {
            rtDW.is_UP_REBOUND = IN_Default;

            /* Outputs for Function Call SubSystem: '<S19>/Gearmotor_release' */
            Gearmotor_release();

            /* End of Outputs for SubSystem: '<S19>/Gearmotor_release' */
          }
        }
      } else if (rtDW.ticksCounter < -2147483647) {
        rtDW.ticksCounter = MIN_int32_T;
      } else {
        rtDW.ticksCounter--;
      }
      break;

     case IN_UP_REBOUND:
      if (rtDW.ticksCounter == 0) {
        rtDW.is_UP_REBOUND = 0;
        rtDW.is_UPSHIFTING = 0;
        if (rtDW.is_UPSHIFTING != IN_UP_BRAKE) {
          rtDW.is_UPSHIFTING = IN_UP_BRAKE;
          rtDW.ticksCounter = Gearshift_getTime();

          /* Outputs for Function Call SubSystem: '<S19>/Gearmotor_brake' */
          Gearmotor_brake(&rtDW.Pin_In1, &Pin_In2, &rtDW.Pin_H,
                          &rtDW.Gearmotor_brake_e);

          /* End of Outputs for SubSystem: '<S19>/Gearmotor_brake' */
        }
      } else if (rtDW.ticksCounter < -2147483647) {
        rtDW.ticksCounter = MIN_int32_T;
      } else {
        rtDW.ticksCounter--;
      }
      break;

     case IN_UP_START:
      if (rtDW.ticksCounter == 0) {
        rtDW.is_UP_START = 0;
        rtDW.is_UPSHIFTING = 0;
        if (rtDW.is_UPSHIFTING != IN_UP_PUSH) {
          rtDW.is_UPSHIFTING = IN_UP_PUSH;
          rtDW.ticksCounter = Gearshift_getTime();
        }

        if (!(rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL)) {
          if (rtDW.is_UP_PUSH != IN_CutOff) {
            rtDW.is_UP_PUSH = IN_CutOff;

            /* Outputs for Function Call SubSystem: '<S16>/UnsetCut' */
            UnsetCut(&Pin_In2, &rtDW.UnsetCut_f);

            /* End of Outputs for SubSystem: '<S16>/UnsetCut' */

            /* Outputs for Function Call SubSystem: '<S19>/Gearmotor_turnRight' */
            Gearmotor_turnRight(&rtDW.Pin_In1, &Pin_In2, &rtDW.Pin_H,
                                &rtDW.Gearmotor_turnRight_a);

            /* End of Outputs for SubSystem: '<S19>/Gearmotor_turnRight' */
          }
        } else {
          if (rtDW.is_UP_PUSH != IN_Default_p) {
            rtDW.is_UP_PUSH = IN_Default_p;

            /* Outputs for Function Call SubSystem: '<S19>/Gearmotor_turnRight' */
            Gearmotor_turnRight(&rtDW.Pin_In1, &Pin_In2, &rtDW.Pin_H,
                                &rtDW.Gearmotor_turnRight_a);

            /* End of Outputs for SubSystem: '<S19>/Gearmotor_turnRight' */
          }
        }
      } else if (rtDW.ticksCounter < -2147483647) {
        rtDW.ticksCounter = MIN_int32_T;
      } else {
        rtDW.ticksCounter--;
      }
      break;
    }
    break;

   case IN_UP_END:
    rtDW.is_GEARSHIFT = 0;
    if (rtDW.is_GEARSHIFT != IN_IDLE) {
      rtDW.is_GEARSHIFT = IN_IDLE;
    }
    break;
  }
}

/* Function for Chart: '<S5>/GCULogic' */
static void checkShift(void)
{
  int32_T b_previousEvent;
  if (rtDW.RateTransition2[0] != rtDW.lastShiftCom) {
    rtDW.lastShiftCom = rtDW.RateTransition2[0];
    if (rtDW.RateTransition2[1] == GEAR_COMMAND_UP) {
      b_previousEvent = rtDW.sfEvent;
      rtDW.sfEvent = event_GearshiftUp;
      if (rtDW.is_active_NEUTRAL_STATE != 0U) {
        NEUTRAL_STATE();
      }

      rtDW.sfEvent = b_previousEvent;
      b_previousEvent = rtDW.sfEvent;
      rtDW.sfEvent = event_GearshiftUp;
      if (rtDW.is_active_GEARSHIFT != 0U) {
        GEARSHIFT();
      }

      rtDW.sfEvent = b_previousEvent;
    } else if (rtDW.RateTransition2[1] == GEAR_COMMAND_DOWN) {
      b_previousEvent = rtDW.sfEvent;
      rtDW.sfEvent = event_GearshiftDown;
      if (rtDW.is_active_NEUTRAL_STATE != 0U) {
        NEUTRAL_STATE();
      }

      rtDW.sfEvent = b_previousEvent;
      b_previousEvent = rtDW.sfEvent;
      rtDW.sfEvent = event_GearshiftDown;
      if (rtDW.is_active_GEARSHIFT != 0U) {
        GEARSHIFT();
      }

      rtDW.sfEvent = b_previousEvent;
    } else if (rtDW.RateTransition2[1] == GEAR_COMMAND_NEUTRAL_UP) {
      b_previousEvent = rtDW.sfEvent;
      rtDW.sfEvent = event_GearshiftSetNeutral;
      if (rtDW.is_active_NEUTRAL_STATE != 0U) {
        NEUTRAL_STATE();
      }

      rtDW.sfEvent = b_previousEvent;
      b_previousEvent = rtDW.sfEvent;
      rtDW.sfEvent = event_GearshiftUp;
      if (rtDW.is_active_GEARSHIFT != 0U) {
        GEARSHIFT();
      }

      rtDW.sfEvent = b_previousEvent;
    } else {
      if (rtDW.RateTransition2[1] == GEAR_COMMAND_NEUTRAL_DOWN) {
        b_previousEvent = rtDW.sfEvent;
        rtDW.sfEvent = event_GearshiftSetNeutral;
        if (rtDW.is_active_NEUTRAL_STATE != 0U) {
          NEUTRAL_STATE();
        }

        rtDW.sfEvent = b_previousEvent;
        b_previousEvent = rtDW.sfEvent;
        rtDW.sfEvent = event_GearshiftDown;
        if (rtDW.is_active_GEARSHIFT != 0U) {
          GEARSHIFT();
        }

        rtDW.sfEvent = b_previousEvent;
      }
    }
  }
}

/* Function for Chart: '<S5>/GCULogic' */
static int32_T getAacParam(aac_params b_index)
{
  int32_T q0;
  q0 = b_index;
  if (q0 > 2147483646) {
    q0 = MAX_int32_T;
  } else {
    q0++;
  }

  return rtDW.aac_parameters[q0 - 1];
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for Chart: '<S5>/GCULogic' */
static void aacCheckShift(void)
{
  int32_T b_previousEvent;

  /* Outport: '<Root>/currGear' */
  if (rtDW.lastShift == rtY.currGear) {
    b_previousEvent = (int32_T)((uint32_T)RPM_LIMIT_1_2 + rtY.currGear);
    if ((uint32_T)b_previousEvent > 255U) {
      b_previousEvent = 255;
    }

    if (rtDW.RateTransition1[0] >= rtDW.aac_parameters[b_previousEvent - 1]) {
      b_previousEvent = (int32_T)((uint32_T)SPEED_LIMIT_1_2 + rtY.currGear);
      if ((uint32_T)b_previousEvent > 255U) {
        b_previousEvent = 255;
      }

      if (rtDW.RateTransition1[1] >= rtDW.aac_parameters[b_previousEvent - 1]) {
        b_previousEvent = rtDW.sfEvent;
        rtDW.sfEvent = event_GearshiftUp;
        if (rtDW.is_active_GEARSHIFT != 0U) {
          GEARSHIFT();
        }

        rtDW.sfEvent = b_previousEvent;
        b_previousEvent = (int32_T)(rtDW.lastShift + 1U);
        if ((uint32_T)b_previousEvent > 255U) {
          b_previousEvent = 255;
        }

        rtDW.lastShift = (uint8_T)b_previousEvent;
      }
    }
  }

  /* End of Outport: '<Root>/currGear' */
}

/* Function for Chart: '<S5>/GCULogic' */
static void ACTIVE(void)
{
  int32_T A;
  uint32_T q;
  boolean_T c_sf_internal_predicateOutput;
  int32_T q1;
  int64_T tmp;
  real_T tmp_0;
  uint32_T qY;
  uint8_T tmp_1;
  if ((rtDW.RateTransition4[0] != rtDW.lastAacCom) && (rtDW.RateTransition4[1] ==
       STOP_AAC_COM)) {
    rtDW.lastAacCom = rtDW.RateTransition4[0];
    rtDW.is_ACTIVE = 0;
    rtDW.is_AAC = 0;
    if (rtDW.is_AAC != IN_STOPPING) {
      rtDW.is_AAC = IN_STOPPING;

      /* Outputs for Function Call SubSystem: '<S16>/UnsetRPMLimiter' */
      UnsetCut(&rtDW.Merge2, &rtDW.UnsetRPMLimiter_o);

      /* End of Outputs for SubSystem: '<S16>/UnsetRPMLimiter' */
      rtDW.valCode = ACC_CODE;
      rtDW.value = 0U;

      /* Outputs for Function Call SubSystem: '<S18>/sendUpdatesSW' */
      sendUpdatesSW(rtDW.valCode, rtDW.value, &rtDW.sendUpdatesSW_g);

      /* End of Outputs for SubSystem: '<S18>/sendUpdatesSW' */
    }
  } else {
    switch (rtDW.is_ACTIVE) {
     case IN_READY:
      if (rtDW.aacCounter <= 1) {
        if ((rtDW.RateTransition4[0] != rtDW.lastAacCom) &&
            (rtDW.RateTransition4[1] == RELEASE_AAC_COM)) {
          rtDW.lastAacCom = rtDW.RateTransition4[0];
          rtDW.is_ACTIVE = 0;
          if (rtDW.is_ACTIVE != IN_START_RELEASE) {
            rtDW.is_ACTIVE = IN_START_RELEASE;
            rtDW.aac_clutchValue = getAacParam(RAMP_START);
            tmp_0 = rt_roundd_snf(rtDW.aac_clutchValue);
            if (tmp_0 < 256.0) {
              if (tmp_0 >= 0.0) {
                tmp_1 = (uint8_T)tmp_0;
              } else {
                tmp_1 = 0U;
              }
            } else {
              tmp_1 = MAX_uint8_T;
            }

            Clutch_setValue(tmp_1);
            A = getAacParam(RAMP_TIME);
            if (A >= 0) {
              qY = (uint32_T)A;
            } else if (A == MIN_int32_T) {
              qY = 2147483648U;
            } else {
              qY = (uint32_T)-A;
            }

            q = qY / 25U;
            qY -= q * 25U;
            if ((qY > 0U) && (qY >= 13U)) {
              q++;
            }

            rtDW.aac_dtRelease = (int32_T)q;
            if (A < 0) {
              rtDW.aac_dtRelease = -rtDW.aac_dtRelease;
            }

            A = getAacParam(RAMP_START);
            q1 = getAacParam(RAMP_END);
            if ((A >= 0) && (q1 < A - MAX_int32_T)) {
              A = MAX_int32_T;
            } else if ((A < 0) && (q1 > A - MIN_int32_T)) {
              A = MIN_int32_T;
            } else {
              A -= q1;
            }

            tmp = (int64_T)A * AAC_WORK_RATE_ms;
            if (tmp > 2147483647LL) {
              tmp = 2147483647LL;
            } else {
              if (tmp < -2147483648LL) {
                tmp = -2147483648LL;
              }
            }

            A = getAacParam(RAMP_TIME);
            rtDW.aac_clutchStep = (real_T)(int32_T)tmp / (real_T)A;
            rtDW.aacCounter = AAC_WORK_RATE_ms;
            rtDW.valCode = ACC_CODE;
            rtDW.value = 2U;

            /* Outputs for Function Call SubSystem: '<S18>/sendUpdatesSW' */
            sendUpdatesSW(rtDW.valCode, rtDW.value, &rtDW.sendUpdatesSW_g);

            /* End of Outputs for SubSystem: '<S18>/sendUpdatesSW' */
          }
        } else {
          rtDW.is_ACTIVE = 0;
          if (rtDW.is_ACTIVE != IN_READY) {
            rtDW.is_ACTIVE = IN_READY;
            rtDW.aacCounter = AAC_WORK_RATE_ms;
            Clutch_setValue(100);
            checkShift();
          }
        }
      } else {
        qY = rtDW.aacCounter - /*MW:OvSatOk*/ 1U;
        if (qY > rtDW.aacCounter) {
          qY = 0U;
        }

        rtDW.aacCounter = (uint16_T)qY;
        checkShift();
      }
      break;

     case IN_RELEASING:
      if (rtDW.aacCounter <= 1) {
        c_sf_internal_predicateOutput = ((rtDW.aac_dtRelease <= 0) ||
          (rtDW.clutchCurrVal <= getAacParam(RAMP_END)));
        if (c_sf_internal_predicateOutput) {
          Clutch_setValue(0);

          /* Outputs for Function Call SubSystem: '<S16>/UnsetRPMLimiter' */
          UnsetCut(&rtDW.Merge2, &rtDW.UnsetRPMLimiter_o);

          /* End of Outputs for SubSystem: '<S16>/UnsetRPMLimiter' */
          rtDW.is_ACTIVE = 0;
          if (rtDW.is_ACTIVE != IN_RUNNING) {
            rtDW.is_ACTIVE = IN_RUNNING;
            rtDW.aacCounter = AAC_WORK_RATE_ms;

            /* Outport: '<Root>/currGear' */
            rtDW.lastShift = rtY.currGear;
            aacCheckShift();
          }
        } else {
          rtDW.is_ACTIVE = 0;
          if (rtDW.is_ACTIVE != IN_RELEASING) {
            rtDW.is_ACTIVE = IN_RELEASING;
            rtDW.aac_clutchValue -= rtDW.aac_clutchStep;
            tmp_0 = rt_roundd_snf(rtDW.aac_clutchValue);
            if (tmp_0 < 256.0) {
              if (tmp_0 >= 0.0) {
                tmp_1 = (uint8_T)tmp_0;
              } else {
                tmp_1 = 0U;
              }
            } else {
              tmp_1 = MAX_uint8_T;
            }

            Clutch_setValue(tmp_1);
            if (rtDW.aac_dtRelease < -2147483647) {
              rtDW.aac_dtRelease = MIN_int32_T;
            } else {
              rtDW.aac_dtRelease--;
            }

            rtDW.aacCounter = AAC_WORK_RATE_ms;
          }
        }
      } else {
        qY = rtDW.aacCounter - /*MW:OvSatOk*/ 1U;
        if (qY > rtDW.aacCounter) {
          qY = 0U;
        }

        rtDW.aacCounter = (uint16_T)qY;
      }
      break;

     case IN_RUNNING:
      /* Outport: '<Root>/currGear' */
      if (rtY.currGear == 3) {
        rtDW.is_ACTIVE = 0;
        rtDW.is_AAC = 0;
        if (rtDW.is_AAC != IN_STOPPING) {
          rtDW.is_AAC = IN_STOPPING;

          /* Outputs for Function Call SubSystem: '<S16>/UnsetRPMLimiter' */
          UnsetCut(&rtDW.Merge2, &rtDW.UnsetRPMLimiter_o);

          /* End of Outputs for SubSystem: '<S16>/UnsetRPMLimiter' */
          rtDW.valCode = ACC_CODE;
          rtDW.value = 0U;

          /* Outputs for Function Call SubSystem: '<S18>/sendUpdatesSW' */
          sendUpdatesSW(rtDW.valCode, rtDW.value, &rtDW.sendUpdatesSW_g);

          /* End of Outputs for SubSystem: '<S18>/sendUpdatesSW' */
        }
      } else {
        aacCheckShift();
      }
      break;

     case IN_START:
      if (rtDW.aacCounter <= 1) {
        rtDW.is_ACTIVE = 0;
        if (rtDW.is_ACTIVE != IN_READY) {
          rtDW.is_ACTIVE = IN_READY;
          rtDW.aacCounter = AAC_WORK_RATE_ms;
          Clutch_setValue(100);
          checkShift();
        }
      } else {
        qY = rtDW.aacCounter - /*MW:OvSatOk*/ 1U;
        if (qY > rtDW.aacCounter) {
          qY = 0U;
        }

        rtDW.aacCounter = (uint16_T)qY;
      }
      break;

     case IN_START_RELEASE:
      if (rtDW.aacCounter <= 1) {
        rtDW.is_ACTIVE = 0;
        if (rtDW.is_ACTIVE != IN_RELEASING) {
          rtDW.is_ACTIVE = IN_RELEASING;
          rtDW.aac_clutchValue -= rtDW.aac_clutchStep;
          tmp_0 = rt_roundd_snf(rtDW.aac_clutchValue);
          if (tmp_0 < 256.0) {
            if (tmp_0 >= 0.0) {
              tmp_1 = (uint8_T)tmp_0;
            } else {
              tmp_1 = 0U;
            }
          } else {
            tmp_1 = MAX_uint8_T;
          }

          Clutch_setValue(tmp_1);
          if (rtDW.aac_dtRelease < -2147483647) {
            rtDW.aac_dtRelease = MIN_int32_T;
          } else {
            rtDW.aac_dtRelease--;
          }

          rtDW.aacCounter = AAC_WORK_RATE_ms;
        }
      } else {
        qY = rtDW.aacCounter - /*MW:OvSatOk*/ 1U;
        if (qY > rtDW.aacCounter) {
          qY = 0U;
        }

        rtDW.aacCounter = (uint16_T)qY;
      }
      break;
    }
  }
}

/* Function for Chart: '<S5>/GCULogic' */
static void checkClutch(void)
{
  if ((rtDW.RateTransition5[0] != rtDW.lastClutchCom) && (((!(rtDW.is_GEARSHIFT ==
          IN_DOWNSHIFTING)) && (!(rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL))) ||
       (rtDW.is_NEUTRAL_STATE == IN_UNSET_NEUTRAL))) {
    rtDW.lastClutchCom = rtDW.RateTransition5[0];
    Clutch_setValue(rtDW.RateTransition5[1]);
  }
}

/* Function for Chart: '<Root>/AccelerationRoutine' */
static void updateData(void)
{
  uint32_T tmp;
  boolean_T guard1 = false;
  if ((rtDW.RateTransition7 == 0) && (rtDW.lastGearPin == 1)) {
    tmp = rtDW.currGear_m + 1U;
    if (tmp > 65535U) {
      tmp = 65535U;
    }

    rtDW.currGear_m = (uint16_T)tmp;
  } else {
    guard1 = false;
    if (rtDW.RateTransition7 == 1) {
      rtDW.rpm = 0U;
      rtDW.wheelSpeed = 0U;
      guard1 = true;
    } else {
      tmp = rtDW.rpm + 150U;
      if (tmp > 65535U) {
        tmp = 65535U;
      }

      rtDW.rpm = (uint16_T)tmp;
      tmp = rtDW.wheelSpeed + 5U;
      if (tmp > 65535U) {
        tmp = 65535U;
      }

      rtDW.wheelSpeed = (uint16_T)tmp;
      if (rtDW.message == 0.0) {
        guard1 = true;
      } else {
        rtDW.message = 0.0;
        rtDW.id = 774U;
        rtDW.firstInt = rtDW.wheelSpeed;
      }
    }

    if (guard1) {
      rtDW.message = 1.0;
      rtDW.id = 773U;
      rtDW.firstInt = rtDW.currGear_m;
      rtDW.secondInt = rtDW.rpm;
    }
  }

  rtDW.lastGearPin = rtDW.RateTransition7;
}

/* Function for Chart: '<Root>/AccelerationRoutine' */
static void checkGear(void)
{
  uint32_T tmp;
  if ((rtDW.RateTransition7 == 0) && (rtDW.lastGearPin == 1)) {
    tmp = rtDW.currGear_m + 1U;
    if (tmp > 65535U) {
      tmp = 65535U;
    }

    rtDW.currGear_m = (uint16_T)tmp;
  }

  rtDW.lastGearPin = rtDW.RateTransition7;
}

/* Function for Chart: '<S4>/MessageEvaluation' */
static void sendAacCommand(uint16_T com)
{
  uint32_T tmp;
  if (rtDW.aacCommand[0] >= 255) {
    rtDW.aacCommand[0] = 0U;
  } else {
    tmp = rtDW.aacCommand[0] + 1U;
    if (tmp > 65535U) {
      tmp = 65535U;
    }

    rtDW.aacCommand[0] = (uint16_T)tmp;
  }

  rtDW.aacCommand[1] = com;
}

/* Function for Chart: '<S4>/MessageEvaluation' */
static void sendClutchCommand(uint8_T com)
{
  int32_T tmp;
  if (rtDW.clutchCommand[0] >= 255) {
    rtDW.clutchCommand[0] = 0U;
  } else {
    tmp = (int32_T)(rtDW.clutchCommand[0] + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    rtDW.clutchCommand[0] = (uint8_T)tmp;
  }

  rtDW.clutchCommand[1] = com;
}

/* Function for Chart: '<S4>/MessageEvaluation' */
static void sendShiftCommand(uint16_T com)
{
  uint32_T tmp;
  if (rtDW.shiftCommand[0] >= 255) {
    rtDW.shiftCommand[0] = 0U;
  } else {
    tmp = rtDW.shiftCommand[0] + 1U;
    if (tmp > 65535U) {
      tmp = 65535U;
    }

    rtDW.shiftCommand[0] = (uint16_T)tmp;
  }

  rtDW.shiftCommand[1] = com;
  if (rtDW.RateTransition6 != 100) {
    sendAacCommand(STOP_COM);
  }
}

/* Function for Chart: '<S4>/MessageEvaluation' */
static void sendStartEngCommand(void)
{
  int32_T tmp;
  if (rtDW.startEngCommand >= 255) {
    rtDW.startEngCommand = 0U;
  } else {
    tmp = (int32_T)(rtDW.startEngCommand + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    rtDW.startEngCommand = (uint8_T)tmp;
  }
}

/* Function for Chart: '<S4>/MessageEvaluation' */
static void WHEEL_SPEED_UPDATE(uint16_T *tractionValue, uint16_T
  *aac_externValues_index, uint16_T *aac_externValue, uint16_T *Assignment_b)
{
  uint8_T clutchSetVal;
  uint32_T tmp;
  *aac_externValues_index = (uint16_T)WHEEL_SPEED;
  if (rtDW.UnpackCanUart_o1 == EFI_GEAR_RPM_TPS_APPS_ID) {
    rtDW.is_c1_GCU_Model_genCode = IN_GEAR_RPM_UPDATE;
    rtDW.currGear = rtDW.UnpackCanUart_o2;
    *aac_externValues_index = (uint16_T)RPM;
    *aac_externValue = rtDW.UnpackCanUart_o3;

    /* Outputs for Function Call SubSystem: '<S4>/AAC_ExternalValues' */
    AAC_ExternalValues(*aac_externValue, *aac_externValues_index,
                       rtDW.Assignment, &rtDW.AAC_ExternalValues_j);

    /* End of Outputs for SubSystem: '<S4>/AAC_ExternalValues' */
  } else if (rtDW.UnpackCanUart_o1 == SW_FIRE_GCU_ID) {
    rtDW.is_c1_GCU_Model_genCode = IN_START_ENGINE;
    sendStartEngCommand();
  } else if (rtDW.UnpackCanUart_o1 == SW_GEARSHIFT_ID) {
    rtDW.is_c1_GCU_Model_genCode = IN_SW_GEARSHIFT;
    if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_ON) {
      /* Outputs for Function Call SubSystem: '<S8>/Efi_setRpmLimiter' */
      Efi_setRpmLimiter(&rtDW.Merge_o, &rtDW.Efi_setRpmLimiter_e);

      /* End of Outputs for SubSystem: '<S8>/Efi_setRpmLimiter' */
    } else if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_OFF) {
      /* Outputs for Function Call SubSystem: '<S8>/Efi_unsetRpmLimiter' */
      Efi_unsetRpmLimiter(&rtDW.Merge_o, &rtDW.Efi_unsetRpmLimiter_o);

      /* End of Outputs for SubSystem: '<S8>/Efi_unsetRpmLimiter' */
    } else {
      sendShiftCommand(rtDW.UnpackCanUart_o2);
    }
  } else if (rtDW.UnpackCanUart_o1 == EFI_TRACTION_CONTROL_ID) {
    rtDW.is_c1_GCU_Model_genCode = IN_WHEEL_SPEED_UPDATE;
    *aac_externValues_index = (uint16_T)WHEEL_SPEED;
    *aac_externValue = (uint16_T)rt_roundd_snf((real_T)rtDW.UnpackCanUart_o2 /
      10.0);

    /* Outputs for Function Call SubSystem: '<S4>/AAC_ExternalValues' */
    AAC_ExternalValues(*aac_externValue, *aac_externValues_index,
                       rtDW.Assignment, &rtDW.AAC_ExternalValues_j);

    /* End of Outputs for SubSystem: '<S4>/AAC_ExternalValues' */
  } else if (rtDW.UnpackCanUart_o1 == SW_CLUTCH_TARGET_GCU_ID) {
    rtDW.is_c1_GCU_Model_genCode = IN_SET_CLUTCH;
    clutchSetVal = (uint8_T)((uint32_T)rtDW.UnpackCanUart_o2 >> 8);
    if (clutchSetVal > AAC_CLUTCH_NOISE_LEVEL) {
      sendAacCommand(STOP_COM);
    }

    sendClutchCommand(clutchSetVal);
  } else if (rtDW.UnpackCanUart_o1 == SW_ACCELERATION_GCU_ID) {
    rtDW.is_c1_GCU_Model_genCode = IN_AAC_COM;
    sendAacCommand(rtDW.UnpackCanUart_o2);
    if (rtDW.aacCommand[1] == STOP_COM) {
      sendClutchCommand(0);
    }
  } else if (rtDW.UnpackCanUart_o1 == SW_TRACTION_CONTROL_GCU_ID) {
    rtDW.is_c1_GCU_Model_genCode = IN_SET_TRACTION;
    tmp = rtDW.UnpackCanUart_o2 * 100U;
    if (tmp > 65535U) {
      tmp = 65535U;
    }

    *tractionValue = (uint16_T)tmp;

    /* Outputs for Function Call SubSystem: '<S4>/TractionValue' */
    TractionValue(*tractionValue, Assignment_b, &rtDW.TractionValue_f);

    /* End of Outputs for SubSystem: '<S4>/TractionValue' */
  } else {
    rtDW.is_c1_GCU_Model_genCode = IN_IDLE;
  }
}

/* Function for Chart: '<S4>/MessageEvaluation' */
static void AAC_COM(uint16_T *tractionValue, uint16_T *aac_externValues_index,
                    uint16_T *aac_externValue, uint16_T *Assignment_b)
{
  uint8_T clutchSetVal;
  uint32_T tmp;
  if (rtDW.UnpackCanUart_o1 == EFI_GEAR_RPM_TPS_APPS_ID) {
    rtDW.is_c1_GCU_Model_genCode = IN_GEAR_RPM_UPDATE;
    rtDW.currGear = rtDW.UnpackCanUart_o2;
    *aac_externValues_index = (uint16_T)RPM;
    *aac_externValue = rtDW.UnpackCanUart_o3;

    /* Outputs for Function Call SubSystem: '<S4>/AAC_ExternalValues' */
    AAC_ExternalValues(*aac_externValue, *aac_externValues_index,
                       rtDW.Assignment, &rtDW.AAC_ExternalValues_j);

    /* End of Outputs for SubSystem: '<S4>/AAC_ExternalValues' */
  } else if (rtDW.UnpackCanUart_o1 == SW_FIRE_GCU_ID) {
    rtDW.is_c1_GCU_Model_genCode = IN_START_ENGINE;
    sendStartEngCommand();
  } else if (rtDW.UnpackCanUart_o1 == SW_GEARSHIFT_ID) {
    rtDW.is_c1_GCU_Model_genCode = IN_SW_GEARSHIFT;
    if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_ON) {
      /* Outputs for Function Call SubSystem: '<S8>/Efi_setRpmLimiter' */
      Efi_setRpmLimiter(&rtDW.Merge_o, &rtDW.Efi_setRpmLimiter_e);

      /* End of Outputs for SubSystem: '<S8>/Efi_setRpmLimiter' */
    } else if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_OFF) {
      /* Outputs for Function Call SubSystem: '<S8>/Efi_unsetRpmLimiter' */
      Efi_unsetRpmLimiter(&rtDW.Merge_o, &rtDW.Efi_unsetRpmLimiter_o);

      /* End of Outputs for SubSystem: '<S8>/Efi_unsetRpmLimiter' */
    } else {
      sendShiftCommand(rtDW.UnpackCanUart_o2);
    }
  } else if (rtDW.UnpackCanUart_o1 == EFI_TRACTION_CONTROL_ID) {
    rtDW.is_c1_GCU_Model_genCode = IN_WHEEL_SPEED_UPDATE;
    *aac_externValues_index = (uint16_T)WHEEL_SPEED;
    *aac_externValue = (uint16_T)rt_roundd_snf((real_T)rtDW.UnpackCanUart_o2 /
      10.0);

    /* Outputs for Function Call SubSystem: '<S4>/AAC_ExternalValues' */
    AAC_ExternalValues(*aac_externValue, *aac_externValues_index,
                       rtDW.Assignment, &rtDW.AAC_ExternalValues_j);

    /* End of Outputs for SubSystem: '<S4>/AAC_ExternalValues' */
  } else if (rtDW.UnpackCanUart_o1 == SW_CLUTCH_TARGET_GCU_ID) {
    rtDW.is_c1_GCU_Model_genCode = IN_SET_CLUTCH;
    clutchSetVal = (uint8_T)((uint32_T)rtDW.UnpackCanUart_o2 >> 8);
    if (clutchSetVal > AAC_CLUTCH_NOISE_LEVEL) {
      sendAacCommand(STOP_COM);
    }

    sendClutchCommand(clutchSetVal);
  } else if (rtDW.UnpackCanUart_o1 == SW_ACCELERATION_GCU_ID) {
    rtDW.is_c1_GCU_Model_genCode = IN_AAC_COM;
    sendAacCommand(rtDW.UnpackCanUart_o2);
    if (rtDW.aacCommand[1] == STOP_COM) {
      sendClutchCommand(0);
    }
  } else if (rtDW.UnpackCanUart_o1 == SW_TRACTION_CONTROL_GCU_ID) {
    rtDW.is_c1_GCU_Model_genCode = IN_SET_TRACTION;
    tmp = rtDW.UnpackCanUart_o2 * 100U;
    if (tmp > 65535U) {
      tmp = 65535U;
    }

    *tractionValue = (uint16_T)tmp;

    /* Outputs for Function Call SubSystem: '<S4>/TractionValue' */
    TractionValue(*tractionValue, Assignment_b, &rtDW.TractionValue_f);

    /* End of Outputs for SubSystem: '<S4>/TractionValue' */
  } else {
    rtDW.is_c1_GCU_Model_genCode = IN_IDLE;
  }
}

/* Function for Chart: '<S4>/MessageEvaluation' */
static void GEAR_RPM_UPDATE(uint16_T *tractionValue, uint16_T
  *aac_externValues_index, uint16_T *aac_externValue, uint16_T *Assignment_b)
{
  uint8_T clutchSetVal;
  uint32_T tmp;
  *aac_externValues_index = (uint16_T)RPM;
  if (rtDW.UnpackCanUart_o1 == EFI_GEAR_RPM_TPS_APPS_ID) {
    rtDW.is_c1_GCU_Model_genCode = IN_GEAR_RPM_UPDATE;
    rtDW.currGear = rtDW.UnpackCanUart_o2;
    *aac_externValues_index = (uint16_T)RPM;
    *aac_externValue = rtDW.UnpackCanUart_o3;

    /* Outputs for Function Call SubSystem: '<S4>/AAC_ExternalValues' */
    AAC_ExternalValues(*aac_externValue, *aac_externValues_index,
                       rtDW.Assignment, &rtDW.AAC_ExternalValues_j);

    /* End of Outputs for SubSystem: '<S4>/AAC_ExternalValues' */
  } else if (rtDW.UnpackCanUart_o1 == SW_FIRE_GCU_ID) {
    rtDW.is_c1_GCU_Model_genCode = IN_START_ENGINE;
    sendStartEngCommand();
  } else if (rtDW.UnpackCanUart_o1 == SW_GEARSHIFT_ID) {
    rtDW.is_c1_GCU_Model_genCode = IN_SW_GEARSHIFT;
    if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_ON) {
      /* Outputs for Function Call SubSystem: '<S8>/Efi_setRpmLimiter' */
      Efi_setRpmLimiter(&rtDW.Merge_o, &rtDW.Efi_setRpmLimiter_e);

      /* End of Outputs for SubSystem: '<S8>/Efi_setRpmLimiter' */
    } else if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_OFF) {
      /* Outputs for Function Call SubSystem: '<S8>/Efi_unsetRpmLimiter' */
      Efi_unsetRpmLimiter(&rtDW.Merge_o, &rtDW.Efi_unsetRpmLimiter_o);

      /* End of Outputs for SubSystem: '<S8>/Efi_unsetRpmLimiter' */
    } else {
      sendShiftCommand(rtDW.UnpackCanUart_o2);
    }
  } else if (rtDW.UnpackCanUart_o1 == EFI_TRACTION_CONTROL_ID) {
    rtDW.is_c1_GCU_Model_genCode = IN_WHEEL_SPEED_UPDATE;
    *aac_externValues_index = (uint16_T)WHEEL_SPEED;
    *aac_externValue = (uint16_T)rt_roundd_snf((real_T)rtDW.UnpackCanUart_o2 /
      10.0);

    /* Outputs for Function Call SubSystem: '<S4>/AAC_ExternalValues' */
    AAC_ExternalValues(*aac_externValue, *aac_externValues_index,
                       rtDW.Assignment, &rtDW.AAC_ExternalValues_j);

    /* End of Outputs for SubSystem: '<S4>/AAC_ExternalValues' */
  } else if (rtDW.UnpackCanUart_o1 == SW_CLUTCH_TARGET_GCU_ID) {
    rtDW.is_c1_GCU_Model_genCode = IN_SET_CLUTCH;
    clutchSetVal = (uint8_T)((uint32_T)rtDW.UnpackCanUart_o2 >> 8);
    if (clutchSetVal > AAC_CLUTCH_NOISE_LEVEL) {
      sendAacCommand(STOP_COM);
    }

    sendClutchCommand(clutchSetVal);
  } else if (rtDW.UnpackCanUart_o1 == SW_ACCELERATION_GCU_ID) {
    rtDW.is_c1_GCU_Model_genCode = IN_AAC_COM;
    sendAacCommand(rtDW.UnpackCanUart_o2);
    if (rtDW.aacCommand[1] == STOP_COM) {
      sendClutchCommand(0);
    }
  } else if (rtDW.UnpackCanUart_o1 == SW_TRACTION_CONTROL_GCU_ID) {
    rtDW.is_c1_GCU_Model_genCode = IN_SET_TRACTION;
    tmp = rtDW.UnpackCanUart_o2 * 100U;
    if (tmp > 65535U) {
      tmp = 65535U;
    }

    *tractionValue = (uint16_T)tmp;

    /* Outputs for Function Call SubSystem: '<S4>/TractionValue' */
    TractionValue(*tractionValue, Assignment_b, &rtDW.TractionValue_f);

    /* End of Outputs for SubSystem: '<S4>/TractionValue' */
  } else {
    rtDW.is_c1_GCU_Model_genCode = IN_IDLE;
  }
}

/* Model step function for TID0 */
void GCU_Model_genCode_step0(void)     /* Sample time: [0.001s, 0.0s] */
{
  uint8_T Merge_m;
  int32_T tmp;
  uint32_T qY;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.001s, 0.0s] to Sample time: [0.01s, 0.0s]  */
  (rtM->Timing.RateInteraction.TID0_1)++;
  if ((rtM->Timing.RateInteraction.TID0_1) > 9) {
    rtM->Timing.RateInteraction.TID0_1 = 0;
  }

  /* Outport: '<Root>/currGear' incorporates:
   *  RateTransition: '<Root>/Rate Transition'
   */
  rtY.currGear = rtDW.RateTransition_Buffer0;

  /* RateTransition: '<Root>/Rate Transition1' */
  tmp = rtDW.RateTransition1_ActiveBufIdx * 3;
  rtDW.RateTransition1[0] = rtDW.RateTransition1_Buffer[tmp];
  rtDW.RateTransition1[1] = rtDW.RateTransition1_Buffer[1 + tmp];
  rtDW.RateTransition1[2] = rtDW.RateTransition1_Buffer[2 + tmp];

  /* RateTransition: '<Root>/Rate Transition2' */
  tmp = rtDW.RateTransition2_ActiveBufIdx << 1;
  rtDW.RateTransition2[0] = rtDW.RateTransition2_Buffer[tmp];
  rtDW.RateTransition2[1] = rtDW.RateTransition2_Buffer[1 + tmp];

  /* RateTransition: '<Root>/Rate Transition3' */
  rtDW.RateTransition3 = rtDW.RateTransition3_Buffer0;

  /* RateTransition: '<Root>/Rate Transition4' */
  tmp = rtDW.RateTransition4_ActiveBufIdx << 1;
  rtDW.RateTransition4[0] = rtDW.RateTransition4_Buffer[tmp];
  rtDW.RateTransition4[1] = rtDW.RateTransition4_Buffer[1 + tmp];

  /* RateTransition: '<Root>/Rate Transition5' */
  tmp = rtDW.RateTransition5_ActiveBufIdx << 1;
  rtDW.RateTransition5[0] = rtDW.RateTransition5_Buffer[tmp];
  rtDW.RateTransition5[1] = rtDW.RateTransition5_Buffer[1 + tmp];

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem1' */
  /* Chart: '<S5>/GCULogic' */
  rtDW.sfEvent = -1;
  if (rtDW.is_active_c2_GCU_Model_genCode == 0U) {
    rtDW.is_active_c2_GCU_Model_genCode = 1U;
    rtDW.is_active_MODES = 1U;
    rtDW.lastAacCom = 0U;
    rtDW.lastShiftCom = 0U;
    rtDW.lastClutchCom = 0U;
    rtDW.is_MODES = IN_INIT;
    rtDW.is_active_NEUTRAL_STATE = 1U;
    rtDW.is_NEUTRAL_STATE = IN_NEUTRAL;
    if (rtDW.is_active_GEARSHIFT != 1U) {
      rtDW.is_active_GEARSHIFT = 1U;
    }

    if (rtDW.is_GEARSHIFT != IN_INIT) {
      rtDW.is_GEARSHIFT = IN_INIT;
      rtDW.ticksCounter = 0;
    }

    rtDW.is_active_START_ENGINE = 1U;
    rtDW.lastCom = 0U;
    if (rtDW.is_START_ENGINE != IN_WAIT) {
      rtDW.is_START_ENGINE = IN_WAIT;
    }
  } else {
    if (rtDW.is_active_MODES != 0U) {
      switch (rtDW.is_MODES) {
       case IN_AAC:
        switch (rtDW.is_AAC) {
         case IN_ACTIVE:
          ACTIVE();
          break;

         case IN_STOPPING:
          rtDW.is_AAC = 0;
          rtDW.is_MODES = 0;
          if (rtDW.is_MODES != IN_AUTOCROSS) {
            rtDW.is_MODES = IN_AUTOCROSS;
            qY = rtDW.alive + /*MW:OvSatOk*/ 1U;
            if (qY < rtDW.alive) {
              qY = MAX_uint32_T;
            }

            rtDW.alive = qY;
            checkShift();
            checkClutch();
          }
          break;
        }
        break;

       case IN_AUTOCROSS:
        if ((rtDW.RateTransition4[0] != rtDW.lastAacCom) &&
            (rtDW.RateTransition4[1] == START_AAC_COM)) {
          rtDW.lastAacCom = rtDW.RateTransition4[0];
          rtDW.is_MODES = IN_AAC;
          rtDW.aac_parameters[0] = 50;
          rtDW.aac_parameters[1] = 0;
          rtDW.aac_parameters[2] = 250;
          rtDW.aac_parameters[3] = 11000;
          rtDW.aac_parameters[4] = 11000;
          rtDW.aac_parameters[5] = 11000;
          rtDW.aac_parameters[6] = 11000;
          rtDW.aac_parameters[7] = 46;
          rtDW.aac_parameters[8] = 61;
          rtDW.aac_parameters[9] = 77;
          rtDW.aac_parameters[10] = 113;
          rtDW.aac_clutchValue = 0.0;
          rtDW.is_AAC = IN_ACTIVE;
          if (rtDW.is_ACTIVE != IN_START) {
            rtDW.is_ACTIVE = IN_START;
            rtDW.aacCounter = AAC_WORK_RATE_ms;

            /* Outputs for Function Call SubSystem: '<S16>/SetRPMLimiter' */
            SetCut(&rtDW.Merge2, &rtDW.SetRPMLimiter_o);

            /* End of Outputs for SubSystem: '<S16>/SetRPMLimiter' */
            Clutch_setValue(100);
            rtDW.valCode = ACC_CODE;
            rtDW.value = 1U;

            /* Outputs for Function Call SubSystem: '<S18>/sendUpdatesSW' */
            sendUpdatesSW(rtDW.valCode, rtDW.value, &rtDW.sendUpdatesSW_g);

            /* End of Outputs for SubSystem: '<S18>/sendUpdatesSW' */
          }
        } else {
          qY = rtDW.alive + /*MW:OvSatOk*/ 1U;
          if (qY < rtDW.alive) {
            qY = MAX_uint32_T;
          }

          rtDW.alive = qY;
          checkShift();
          checkClutch();
        }
        break;

       case IN_ENDURANCE:
        qY = rtDW.alive + /*MW:OvSatOk*/ 1U;
        if (qY < rtDW.alive) {
          qY = MAX_uint32_T;
        }

        rtDW.alive = qY;
        checkShift();
        checkClutch();
        break;

       case IN_INIT:
        rtDW.is_MODES = 0;
        if (rtDW.is_MODES != IN_AUTOCROSS) {
          rtDW.is_MODES = IN_AUTOCROSS;
          qY = rtDW.alive + /*MW:OvSatOk*/ 1U;
          if (qY < rtDW.alive) {
            qY = MAX_uint32_T;
          }

          rtDW.alive = qY;
          checkShift();
          checkClutch();
        }
        break;

       case IN_SKIDPAD:
        qY = rtDW.alive + /*MW:OvSatOk*/ 1U;
        if (qY < rtDW.alive) {
          qY = MAX_uint32_T;
        }

        rtDW.alive = qY;
        checkShift();
        checkClutch();
        break;
      }
    }

    if (rtDW.is_active_NEUTRAL_STATE != 0U) {
      NEUTRAL_STATE();
    }

    if (rtDW.is_active_GEARSHIFT != 0U) {
      GEARSHIFT();
    }

    if (rtDW.is_active_START_ENGINE != 0U) {
      switch (rtDW.is_START_ENGINE) {
       case IN_START_o:
        if (rtDW.startCounter == 0) {
          rtDW.is_START_ENGINE = 0;
          if (rtDW.is_START_ENGINE != IN_STOP) {
            rtDW.is_START_ENGINE = IN_STOP;

            /* Outputs for Function Call SubSystem: '<S17>/EngineControl_Stop' */

            /* S-Function (EngineControl_stop): '<S28>/EngineControl Stop' */
            EngineControl_stop_Outputs_wrapper(&rtDW.EngineControlStop);

            /* End of Outputs for SubSystem: '<S17>/EngineControl_Stop' */
          }
        } else {
          qY = rtDW.startCounter - /*MW:OvSatOk*/ 1U;
          if (qY > rtDW.startCounter) {
            qY = 0U;
          }

          rtDW.startCounter = (uint8_T)qY;
        }
        break;

       case IN_STOP:
        if (rtDW.RateTransition3 != rtDW.lastCom) {
          rtDW.is_START_ENGINE = 0;
          if (rtDW.is_START_ENGINE != IN_START_o) {
            rtDW.is_START_ENGINE = IN_START_o;

            /* Outputs for Function Call SubSystem: '<S17>/EngineControl_Start' */
            EngineControl_Start(&Merge_m, &rtDW.EngineControl_Start_k);

            /* End of Outputs for SubSystem: '<S17>/EngineControl_Start' */
            rtDW.lastCom = rtDW.RateTransition3;
            rtDW.startCounter = 100U;
          }
        }
        break;

       case IN_WAIT:
        if (rtDW.RateTransition3 != rtDW.lastCom) {
          rtDW.is_START_ENGINE = 0;
          if (rtDW.is_START_ENGINE != IN_START_o) {
            rtDW.is_START_ENGINE = IN_START_o;

            /* Outputs for Function Call SubSystem: '<S17>/EngineControl_Start' */
            EngineControl_Start(&Merge_m, &rtDW.EngineControl_Start_k);

            /* End of Outputs for SubSystem: '<S17>/EngineControl_Start' */
            rtDW.lastCom = rtDW.RateTransition3;
            rtDW.startCounter = 100U;
          }
        }
        break;
      }
    }
  }

  /* End of Chart: '<S5>/GCULogic' */
  /* End of Outputs for SubSystem: '<Root>/Subsystem1' */

  /* Outputs for Triggered SubSystem: '<S6>/Triggered_Subsystem' incorporates:
   *  TriggerPort: '<S34>/Trigger'
   */
  rtPrevZCX.Triggered_Subsystem_Trig_ZCE = (ZCSigState)(rtDW.Merge2 > 0);

  /* End of Outputs for SubSystem: '<S6>/Triggered_Subsystem' */

  /* RateTransition: '<S6>/Rate Transition' */
  if (rtM->Timing.RateInteraction.TID0_1 == 1) {
    rtDW.RateTransition_k = rtDW.RateTransition_Buffer0_m;
  }

  /* End of RateTransition: '<S6>/Rate Transition' */

  /* Outputs for Triggered SubSystem: '<S6>/Triggered_Subsystem1' incorporates:
   *  TriggerPort: '<S35>/Trigger'
   */
  rtPrevZCX.Triggered_Subsystem1_Trig_ZCE = (ZCSigState)(rtDW.RateTransition_k >
    0);

  /* End of Outputs for SubSystem: '<S6>/Triggered_Subsystem1' */
}

/* Model step function for TID1 */
void GCU_Model_genCode_step1(void)     /* Sample time: [0.01s, 0.0s] */
{
  uint8_T clutchSetVal;
  uint16_T tractionValue;
  uint16_T aac_externValues_index;
  uint16_T aac_externValue;
  uint16_T Assignment_b;
  uint32_T tmp;

  /* RateTransition: '<Root>/Rate Transition7' */
  rtDW.RateTransition7 = rtDW.Pin_In1;

  /* Chart: '<Root>/AccelerationRoutine' */
  switch (rtDW.is_c3_GCU_Model_genCode) {
   case IN_ActivateAac:
    rtDW.is_c3_GCU_Model_genCode = IN_InsertGear;
    rtDW.id = 512U;
    rtDW.firstInt = 400U;
    break;

   case IN_DajeDeGas:
    if (rtDW.currGear_m == 2) {
      rtDW.is_c3_GCU_Model_genCode = IN_EXIT;
      rtDW.id = 513U;
      rtDW.firstInt = 25600U;
    } else {
      updateData();
    }
    break;

   case IN_EXIT:
    break;

   case IN_InsertGear:
    if (rtDW.currGear_m == 1) {
      rtDW.is_c3_GCU_Model_genCode = IN_Ready;
      rtDW.id = 514U;
      rtDW.firstInt = 2U;
    } else {
      checkGear();
    }
    break;

   case IN_Ready:
    rtDW.is_c3_GCU_Model_genCode = IN_DajeDeGas;
    rtDW.id = 0U;
    rtDW.rpm = 0U;
    rtDW.wheelSpeed = 0U;
    break;

   case IN_Wait:
    rtDW.is_c3_GCU_Model_genCode = IN_delay;
    break;

   default:
    rtDW.is_c3_GCU_Model_genCode = IN_ActivateAac;
    rtDW.id = 514U;
    rtDW.firstInt = 1U;
    break;
  }

  /* End of Chart: '<Root>/AccelerationRoutine' */

  /* S-Function (PackCanUART): '<Root>/PackCanUart' */
  PackCanUART_Outputs_wrapper(&rtDW.id, &rtDW.firstInt, &rtDW.secondInt,
    (uint16_T*)&GCU_Model_genCode_U16GND, (uint16_T*)&GCU_Model_genCode_U16GND,
    &rtDW.PackCanUart[0]);

  /* RateTransition: '<Root>/Rate Transition6' */
  rtDW.RateTransition6 = rtDW.clutchCurrVal;

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* S-Function (UnpackCanUART): '<S4>/UnpackCanUart' */
  UnpackCanUART_Outputs_wrapper(&rtDW.PackCanUart[0], &rtDW.UnpackCanUart_o1,
    &rtDW.UnpackCanUart_o2, &rtDW.UnpackCanUart_o3, &rtDW.UnpackCanUart_o4,
    &rtDW.UnpackCanUart_o5);

  /* Chart: '<S4>/MessageEvaluation' */
  if (rtDW.is_active_c1_GCU_Model_genCode == 0U) {
    rtDW.is_active_c1_GCU_Model_genCode = 1U;
    rtDW.is_c1_GCU_Model_genCode = IN_IDLE;
  } else {
    switch (rtDW.is_c1_GCU_Model_genCode) {
     case IN_AAC_COM:
      AAC_COM(&tractionValue, &aac_externValues_index, &aac_externValue,
              &Assignment_b);
      break;

     case IN_GEAR_RPM_UPDATE:
      GEAR_RPM_UPDATE(&tractionValue, &aac_externValues_index, &aac_externValue,
                      &Assignment_b);
      break;

     case IN_IDLE:
      if (rtDW.UnpackCanUart_o1 == EFI_GEAR_RPM_TPS_APPS_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_GEAR_RPM_UPDATE;
        rtDW.currGear = rtDW.UnpackCanUart_o2;

        /* Outputs for Function Call SubSystem: '<S4>/AAC_ExternalValues' */
        AAC_ExternalValues(rtDW.UnpackCanUart_o3, (uint16_T)RPM, rtDW.Assignment,
                           &rtDW.AAC_ExternalValues_j);

        /* End of Outputs for SubSystem: '<S4>/AAC_ExternalValues' */
      } else if (rtDW.UnpackCanUart_o1 == SW_FIRE_GCU_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_START_ENGINE;
        sendStartEngCommand();
      } else if (rtDW.UnpackCanUart_o1 == SW_GEARSHIFT_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_SW_GEARSHIFT;
        if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_ON) {
          /* Outputs for Function Call SubSystem: '<S8>/Efi_setRpmLimiter' */
          Efi_setRpmLimiter(&rtDW.Merge_o, &rtDW.Efi_setRpmLimiter_e);

          /* End of Outputs for SubSystem: '<S8>/Efi_setRpmLimiter' */
        } else if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_OFF) {
          /* Outputs for Function Call SubSystem: '<S8>/Efi_unsetRpmLimiter' */
          Efi_unsetRpmLimiter(&rtDW.Merge_o, &rtDW.Efi_unsetRpmLimiter_o);

          /* End of Outputs for SubSystem: '<S8>/Efi_unsetRpmLimiter' */
        } else {
          sendShiftCommand(rtDW.UnpackCanUart_o2);
        }
      } else if (rtDW.UnpackCanUart_o1 == EFI_TRACTION_CONTROL_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_WHEEL_SPEED_UPDATE;

        /* Outputs for Function Call SubSystem: '<S4>/AAC_ExternalValues' */
        AAC_ExternalValues((uint16_T)rt_roundd_snf((real_T)rtDW.UnpackCanUart_o2
          / 10.0), (uint16_T)WHEEL_SPEED, rtDW.Assignment,
                           &rtDW.AAC_ExternalValues_j);

        /* End of Outputs for SubSystem: '<S4>/AAC_ExternalValues' */
      } else if (rtDW.UnpackCanUart_o1 == SW_CLUTCH_TARGET_GCU_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_SET_CLUTCH;
        clutchSetVal = (uint8_T)((uint32_T)rtDW.UnpackCanUart_o2 >> 8);
        if (clutchSetVal > AAC_CLUTCH_NOISE_LEVEL) {
          sendAacCommand(STOP_COM);
        }

        sendClutchCommand(clutchSetVal);
      } else if (rtDW.UnpackCanUart_o1 == SW_ACCELERATION_GCU_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_AAC_COM;
        sendAacCommand(rtDW.UnpackCanUart_o2);
        if (rtDW.aacCommand[1] == STOP_COM) {
          sendClutchCommand(0);
        }
      } else if (rtDW.UnpackCanUart_o1 == SW_TRACTION_CONTROL_GCU_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_SET_TRACTION;
        tmp = rtDW.UnpackCanUart_o2 * 100U;
        if (tmp > 65535U) {
          tmp = 65535U;
        }

        /* Outputs for Function Call SubSystem: '<S4>/TractionValue' */
        TractionValue((uint16_T)tmp, &Assignment_b, &rtDW.TractionValue_f);

        /* End of Outputs for SubSystem: '<S4>/TractionValue' */
      } else {
        rtDW.is_c1_GCU_Model_genCode = IN_IDLE;
      }
      break;

     case IN_SET_CLUTCH:
      if (rtDW.UnpackCanUart_o1 == EFI_GEAR_RPM_TPS_APPS_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_GEAR_RPM_UPDATE;
        rtDW.currGear = rtDW.UnpackCanUart_o2;

        /* Outputs for Function Call SubSystem: '<S4>/AAC_ExternalValues' */
        AAC_ExternalValues(rtDW.UnpackCanUart_o3, (uint16_T)RPM, rtDW.Assignment,
                           &rtDW.AAC_ExternalValues_j);

        /* End of Outputs for SubSystem: '<S4>/AAC_ExternalValues' */
      } else if (rtDW.UnpackCanUart_o1 == SW_FIRE_GCU_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_START_ENGINE;
        sendStartEngCommand();
      } else if (rtDW.UnpackCanUart_o1 == SW_GEARSHIFT_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_SW_GEARSHIFT;
        if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_ON) {
          /* Outputs for Function Call SubSystem: '<S8>/Efi_setRpmLimiter' */
          Efi_setRpmLimiter(&rtDW.Merge_o, &rtDW.Efi_setRpmLimiter_e);

          /* End of Outputs for SubSystem: '<S8>/Efi_setRpmLimiter' */
        } else if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_OFF) {
          /* Outputs for Function Call SubSystem: '<S8>/Efi_unsetRpmLimiter' */
          Efi_unsetRpmLimiter(&rtDW.Merge_o, &rtDW.Efi_unsetRpmLimiter_o);

          /* End of Outputs for SubSystem: '<S8>/Efi_unsetRpmLimiter' */
        } else {
          sendShiftCommand(rtDW.UnpackCanUart_o2);
        }
      } else if (rtDW.UnpackCanUart_o1 == EFI_TRACTION_CONTROL_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_WHEEL_SPEED_UPDATE;

        /* Outputs for Function Call SubSystem: '<S4>/AAC_ExternalValues' */
        AAC_ExternalValues((uint16_T)rt_roundd_snf((real_T)rtDW.UnpackCanUart_o2
          / 10.0), (uint16_T)WHEEL_SPEED, rtDW.Assignment,
                           &rtDW.AAC_ExternalValues_j);

        /* End of Outputs for SubSystem: '<S4>/AAC_ExternalValues' */
      } else if (rtDW.UnpackCanUart_o1 == SW_CLUTCH_TARGET_GCU_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_SET_CLUTCH;
        clutchSetVal = (uint8_T)((uint32_T)rtDW.UnpackCanUart_o2 >> 8);
        if (clutchSetVal > AAC_CLUTCH_NOISE_LEVEL) {
          sendAacCommand(STOP_COM);
        }

        sendClutchCommand(clutchSetVal);
      } else if (rtDW.UnpackCanUart_o1 == SW_ACCELERATION_GCU_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_AAC_COM;
        sendAacCommand(rtDW.UnpackCanUart_o2);
        if (rtDW.aacCommand[1] == STOP_COM) {
          sendClutchCommand(0);
        }
      } else if (rtDW.UnpackCanUart_o1 == SW_TRACTION_CONTROL_GCU_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_SET_TRACTION;
        tmp = rtDW.UnpackCanUart_o2 * 100U;
        if (tmp > 65535U) {
          tmp = 65535U;
        }

        /* Outputs for Function Call SubSystem: '<S4>/TractionValue' */
        TractionValue((uint16_T)tmp, &Assignment_b, &rtDW.TractionValue_f);

        /* End of Outputs for SubSystem: '<S4>/TractionValue' */
      } else {
        rtDW.is_c1_GCU_Model_genCode = IN_IDLE;
      }
      break;

     case IN_SET_TRACTION:
      if (rtDW.UnpackCanUart_o1 == EFI_GEAR_RPM_TPS_APPS_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_GEAR_RPM_UPDATE;
        rtDW.currGear = rtDW.UnpackCanUart_o2;

        /* Outputs for Function Call SubSystem: '<S4>/AAC_ExternalValues' */
        AAC_ExternalValues(rtDW.UnpackCanUart_o3, (uint16_T)RPM, rtDW.Assignment,
                           &rtDW.AAC_ExternalValues_j);

        /* End of Outputs for SubSystem: '<S4>/AAC_ExternalValues' */
      } else if (rtDW.UnpackCanUart_o1 == SW_FIRE_GCU_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_START_ENGINE;
        sendStartEngCommand();
      } else if (rtDW.UnpackCanUart_o1 == SW_GEARSHIFT_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_SW_GEARSHIFT;
        if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_ON) {
          /* Outputs for Function Call SubSystem: '<S8>/Efi_setRpmLimiter' */
          Efi_setRpmLimiter(&rtDW.Merge_o, &rtDW.Efi_setRpmLimiter_e);

          /* End of Outputs for SubSystem: '<S8>/Efi_setRpmLimiter' */
        } else if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_OFF) {
          /* Outputs for Function Call SubSystem: '<S8>/Efi_unsetRpmLimiter' */
          Efi_unsetRpmLimiter(&rtDW.Merge_o, &rtDW.Efi_unsetRpmLimiter_o);

          /* End of Outputs for SubSystem: '<S8>/Efi_unsetRpmLimiter' */
        } else {
          sendShiftCommand(rtDW.UnpackCanUart_o2);
        }
      } else if (rtDW.UnpackCanUart_o1 == EFI_TRACTION_CONTROL_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_WHEEL_SPEED_UPDATE;

        /* Outputs for Function Call SubSystem: '<S4>/AAC_ExternalValues' */
        AAC_ExternalValues((uint16_T)rt_roundd_snf((real_T)rtDW.UnpackCanUart_o2
          / 10.0), (uint16_T)WHEEL_SPEED, rtDW.Assignment,
                           &rtDW.AAC_ExternalValues_j);

        /* End of Outputs for SubSystem: '<S4>/AAC_ExternalValues' */
      } else if (rtDW.UnpackCanUart_o1 == SW_CLUTCH_TARGET_GCU_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_SET_CLUTCH;
        clutchSetVal = (uint8_T)((uint32_T)rtDW.UnpackCanUart_o2 >> 8);
        if (clutchSetVal > AAC_CLUTCH_NOISE_LEVEL) {
          sendAacCommand(STOP_COM);
        }

        sendClutchCommand(clutchSetVal);
      } else if (rtDW.UnpackCanUart_o1 == SW_ACCELERATION_GCU_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_AAC_COM;
        sendAacCommand(rtDW.UnpackCanUart_o2);
        if (rtDW.aacCommand[1] == STOP_COM) {
          sendClutchCommand(0);
        }
      } else if (rtDW.UnpackCanUart_o1 == SW_TRACTION_CONTROL_GCU_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_SET_TRACTION;
        tmp = rtDW.UnpackCanUart_o2 * 100U;
        if (tmp > 65535U) {
          tmp = 65535U;
        }

        /* Outputs for Function Call SubSystem: '<S4>/TractionValue' */
        TractionValue((uint16_T)tmp, &Assignment_b, &rtDW.TractionValue_f);

        /* End of Outputs for SubSystem: '<S4>/TractionValue' */
      } else {
        rtDW.is_c1_GCU_Model_genCode = IN_IDLE;
      }
      break;

     case IN_START_ENGINE:
      if (rtDW.UnpackCanUart_o1 == EFI_GEAR_RPM_TPS_APPS_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_GEAR_RPM_UPDATE;
        rtDW.currGear = rtDW.UnpackCanUart_o2;

        /* Outputs for Function Call SubSystem: '<S4>/AAC_ExternalValues' */
        AAC_ExternalValues(rtDW.UnpackCanUart_o3, (uint16_T)RPM, rtDW.Assignment,
                           &rtDW.AAC_ExternalValues_j);

        /* End of Outputs for SubSystem: '<S4>/AAC_ExternalValues' */
      } else if (rtDW.UnpackCanUart_o1 == SW_FIRE_GCU_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_START_ENGINE;
        sendStartEngCommand();
      } else if (rtDW.UnpackCanUart_o1 == SW_GEARSHIFT_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_SW_GEARSHIFT;
        if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_ON) {
          /* Outputs for Function Call SubSystem: '<S8>/Efi_setRpmLimiter' */
          Efi_setRpmLimiter(&rtDW.Merge_o, &rtDW.Efi_setRpmLimiter_e);

          /* End of Outputs for SubSystem: '<S8>/Efi_setRpmLimiter' */
        } else if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_OFF) {
          /* Outputs for Function Call SubSystem: '<S8>/Efi_unsetRpmLimiter' */
          Efi_unsetRpmLimiter(&rtDW.Merge_o, &rtDW.Efi_unsetRpmLimiter_o);

          /* End of Outputs for SubSystem: '<S8>/Efi_unsetRpmLimiter' */
        } else {
          sendShiftCommand(rtDW.UnpackCanUart_o2);
        }
      } else if (rtDW.UnpackCanUart_o1 == EFI_TRACTION_CONTROL_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_WHEEL_SPEED_UPDATE;

        /* Outputs for Function Call SubSystem: '<S4>/AAC_ExternalValues' */
        AAC_ExternalValues((uint16_T)rt_roundd_snf((real_T)rtDW.UnpackCanUart_o2
          / 10.0), (uint16_T)WHEEL_SPEED, rtDW.Assignment,
                           &rtDW.AAC_ExternalValues_j);

        /* End of Outputs for SubSystem: '<S4>/AAC_ExternalValues' */
      } else if (rtDW.UnpackCanUart_o1 == SW_CLUTCH_TARGET_GCU_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_SET_CLUTCH;
        clutchSetVal = (uint8_T)((uint32_T)rtDW.UnpackCanUart_o2 >> 8);
        if (clutchSetVal > AAC_CLUTCH_NOISE_LEVEL) {
          sendAacCommand(STOP_COM);
        }

        sendClutchCommand(clutchSetVal);
      } else if (rtDW.UnpackCanUart_o1 == SW_ACCELERATION_GCU_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_AAC_COM;
        sendAacCommand(rtDW.UnpackCanUart_o2);
        if (rtDW.aacCommand[1] == STOP_COM) {
          sendClutchCommand(0);
        }
      } else if (rtDW.UnpackCanUart_o1 == SW_TRACTION_CONTROL_GCU_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_SET_TRACTION;
        tmp = rtDW.UnpackCanUart_o2 * 100U;
        if (tmp > 65535U) {
          tmp = 65535U;
        }

        /* Outputs for Function Call SubSystem: '<S4>/TractionValue' */
        TractionValue((uint16_T)tmp, &Assignment_b, &rtDW.TractionValue_f);

        /* End of Outputs for SubSystem: '<S4>/TractionValue' */
      } else {
        rtDW.is_c1_GCU_Model_genCode = IN_IDLE;
      }
      break;

     case IN_SW_GEARSHIFT:
      if (rtDW.UnpackCanUart_o1 == EFI_GEAR_RPM_TPS_APPS_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_GEAR_RPM_UPDATE;
        rtDW.currGear = rtDW.UnpackCanUart_o2;

        /* Outputs for Function Call SubSystem: '<S4>/AAC_ExternalValues' */
        AAC_ExternalValues(rtDW.UnpackCanUart_o3, (uint16_T)RPM, rtDW.Assignment,
                           &rtDW.AAC_ExternalValues_j);

        /* End of Outputs for SubSystem: '<S4>/AAC_ExternalValues' */
      } else if (rtDW.UnpackCanUart_o1 == SW_FIRE_GCU_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_START_ENGINE;
        sendStartEngCommand();
      } else if (rtDW.UnpackCanUart_o1 == SW_GEARSHIFT_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_SW_GEARSHIFT;
        if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_ON) {
          /* Outputs for Function Call SubSystem: '<S8>/Efi_setRpmLimiter' */
          Efi_setRpmLimiter(&rtDW.Merge_o, &rtDW.Efi_setRpmLimiter_e);

          /* End of Outputs for SubSystem: '<S8>/Efi_setRpmLimiter' */
        } else if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_OFF) {
          /* Outputs for Function Call SubSystem: '<S8>/Efi_unsetRpmLimiter' */
          Efi_unsetRpmLimiter(&rtDW.Merge_o, &rtDW.Efi_unsetRpmLimiter_o);

          /* End of Outputs for SubSystem: '<S8>/Efi_unsetRpmLimiter' */
        } else {
          sendShiftCommand(rtDW.UnpackCanUart_o2);
        }
      } else if (rtDW.UnpackCanUart_o1 == EFI_TRACTION_CONTROL_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_WHEEL_SPEED_UPDATE;

        /* Outputs for Function Call SubSystem: '<S4>/AAC_ExternalValues' */
        AAC_ExternalValues((uint16_T)rt_roundd_snf((real_T)rtDW.UnpackCanUart_o2
          / 10.0), (uint16_T)WHEEL_SPEED, rtDW.Assignment,
                           &rtDW.AAC_ExternalValues_j);

        /* End of Outputs for SubSystem: '<S4>/AAC_ExternalValues' */
      } else if (rtDW.UnpackCanUart_o1 == SW_CLUTCH_TARGET_GCU_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_SET_CLUTCH;
        clutchSetVal = (uint8_T)((uint32_T)rtDW.UnpackCanUart_o2 >> 8);
        if (clutchSetVal > AAC_CLUTCH_NOISE_LEVEL) {
          sendAacCommand(STOP_COM);
        }

        sendClutchCommand(clutchSetVal);
      } else if (rtDW.UnpackCanUart_o1 == SW_ACCELERATION_GCU_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_AAC_COM;
        sendAacCommand(rtDW.UnpackCanUart_o2);
        if (rtDW.aacCommand[1] == STOP_COM) {
          sendClutchCommand(0);
        }
      } else if (rtDW.UnpackCanUart_o1 == SW_TRACTION_CONTROL_GCU_ID) {
        rtDW.is_c1_GCU_Model_genCode = IN_SET_TRACTION;
        tmp = rtDW.UnpackCanUart_o2 * 100U;
        if (tmp > 65535U) {
          tmp = 65535U;
        }

        /* Outputs for Function Call SubSystem: '<S4>/TractionValue' */
        TractionValue((uint16_T)tmp, &Assignment_b, &rtDW.TractionValue_f);

        /* End of Outputs for SubSystem: '<S4>/TractionValue' */
      } else {
        rtDW.is_c1_GCU_Model_genCode = IN_IDLE;
      }
      break;

     default:
      WHEEL_SPEED_UPDATE(&tractionValue, &aac_externValues_index,
                         &aac_externValue, &Assignment_b);
      break;
    }
  }

  /* End of Chart: '<S4>/MessageEvaluation' */
  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* Update for RateTransition: '<Root>/Rate Transition' incorporates:
   *  DataTypeConversion: '<Root>/Cast'
   */
  rtDW.RateTransition_Buffer0 = (uint8_T)rtDW.currGear;

  /* Update for RateTransition: '<Root>/Rate Transition1' */
  rtDW.RateTransition1_Buffer[(rtDW.RateTransition1_ActiveBufIdx == 0) * 3] =
    rtDW.Assignment[0];
  rtDW.RateTransition1_Buffer[1 + (rtDW.RateTransition1_ActiveBufIdx == 0) * 3] =
    rtDW.Assignment[1];
  rtDW.RateTransition1_Buffer[2 + (rtDW.RateTransition1_ActiveBufIdx == 0) * 3] =
    rtDW.Assignment[2];
  rtDW.RateTransition1_ActiveBufIdx = (int8_T)(rtDW.RateTransition1_ActiveBufIdx
    == 0);

  /* Update for RateTransition: '<Root>/Rate Transition2' */
  rtDW.RateTransition2_Buffer[(rtDW.RateTransition2_ActiveBufIdx == 0) << 1] =
    rtDW.shiftCommand[0];
  rtDW.RateTransition2_Buffer[1 + ((rtDW.RateTransition2_ActiveBufIdx == 0) << 1)]
    = rtDW.shiftCommand[1];
  rtDW.RateTransition2_ActiveBufIdx = (int8_T)(rtDW.RateTransition2_ActiveBufIdx
    == 0);

  /* Update for RateTransition: '<Root>/Rate Transition3' */
  rtDW.RateTransition3_Buffer0 = rtDW.startEngCommand;

  /* Update for RateTransition: '<Root>/Rate Transition4' */
  rtDW.RateTransition4_Buffer[(rtDW.RateTransition4_ActiveBufIdx == 0) << 1] =
    rtDW.aacCommand[0];
  rtDW.RateTransition4_Buffer[1 + ((rtDW.RateTransition4_ActiveBufIdx == 0) << 1)]
    = rtDW.aacCommand[1];
  rtDW.RateTransition4_ActiveBufIdx = (int8_T)(rtDW.RateTransition4_ActiveBufIdx
    == 0);

  /* Update for RateTransition: '<Root>/Rate Transition5' */
  rtDW.RateTransition5_Buffer[(rtDW.RateTransition5_ActiveBufIdx == 0) << 1] =
    rtDW.clutchCommand[0];
  rtDW.RateTransition5_Buffer[1 + ((rtDW.RateTransition5_ActiveBufIdx == 0) << 1)]
    = rtDW.clutchCommand[1];
  rtDW.RateTransition5_ActiveBufIdx = (int8_T)(rtDW.RateTransition5_ActiveBufIdx
    == 0);

  /* Update for RateTransition: '<S6>/Rate Transition' */
  rtDW.RateTransition_Buffer0_m = rtDW.Merge_o;
}

/* Model initialize function */
void GCU_Model_genCode_initialize(void)
{
  rtPrevZCX.Triggered_Subsystem_Trig_ZCE = UNINITIALIZED_ZCSIG;
  rtPrevZCX.Triggered_Subsystem1_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subsystem1' */
  /* SystemInitialize for Chart: '<S5>/GCULogic' */
  rtDW.sfEvent = -1;
  rtDW.aac_parameters[0] = 50;
  rtDW.aac_parameters[1] = 0;
  rtDW.aac_parameters[2] = 250;
  rtDW.aac_parameters[3] = 11000;
  rtDW.aac_parameters[4] = 11000;
  rtDW.aac_parameters[5] = 11000;
  rtDW.aac_parameters[6] = 11000;
  rtDW.aac_parameters[7] = 46;
  rtDW.aac_parameters[8] = 61;
  rtDW.aac_parameters[9] = 77;
  rtDW.aac_parameters[10] = 113;

  /* End of SystemInitialize for SubSystem: '<Root>/Subsystem1' */

  /* Chart: '<Root>/AccelerationRoutine' */
  rtDW.is_c3_GCU_Model_genCode = IN_Wait;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Initialize Function' */

  /* S-Function (Efi_init): '<S2>/Efi Init' */
  Efi_init_Outputs_wrapper();

  /* End of SystemInitialize for SubSystem: '<Root>/Initialize Function' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
