/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GCU_timer.c
 *
 * Code generated for Simulink model 'GCU_timer'.
 *
 * Model version                  : 1.144
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Mon Feb 18 22:26:27 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "GCU_timer.h"
#include "rt_roundd.h"

/* Named constants for Chart: '<Root>/GCULogic' */
#define GCU_t_GEAR_COMMAND_NEUTRAL_DOWN ((uint16_T)100U)
#define GCU_t_event_GearshiftSetNeutral (1)
#define GCU_tim_GEAR_COMMAND_NEUTRAL_UP ((uint16_T)50U)
#define GCU_timer_AAC_WORK_RATE_ms     ((uint16_T)25U)
#define GCU_timer_CALL_EVENT           (-1)
#define GCU_timer_GEAR_COMMAND_DOWN    ((uint16_T)200U)
#define GCU_timer_GEAR_COMMAND_UP      ((uint16_T)400U)
#define GCU_timer_IN_AAC               ((uint8_T)1U)
#define GCU_timer_IN_ACTIVE            ((uint8_T)1U)
#define GCU_timer_IN_ChangeClutch      ((uint8_T)1U)
#define GCU_timer_IN_CutOff            ((uint8_T)1U)
#define GCU_timer_IN_DOWNSHIFTING      ((uint8_T)1U)
#define GCU_timer_IN_DOWN_BRAKE        ((uint8_T)1U)
#define GCU_timer_IN_DOWN_END          ((uint8_T)2U)
#define GCU_timer_IN_DOWN_PUSH         ((uint8_T)2U)
#define GCU_timer_IN_DOWN_REBOUND      ((uint8_T)3U)
#define GCU_timer_IN_DOWN_START        ((uint8_T)4U)
#define GCU_timer_IN_Default           ((uint8_T)1U)
#define GCU_timer_IN_Default_n         ((uint8_T)2U)
#define GCU_timer_IN_IDLE              ((uint8_T)3U)
#define GCU_timer_IN_INIT              ((uint8_T)2U)
#define GCU_timer_IN_INIT_f            ((uint8_T)4U)
#define GCU_timer_IN_NEUTRAL           ((uint8_T)1U)
#define GCU_timer_IN_NORMAL            ((uint8_T)3U)
#define GCU_timer_IN_NO_ACTIVE_CHILD   ((uint8_T)0U)
#define GCU_timer_IN_NO_NEUTRAL        ((uint8_T)2U)
#define GCU_timer_IN_READY             ((uint8_T)1U)
#define GCU_timer_IN_RELEASING         ((uint8_T)2U)
#define GCU_timer_IN_RUNNING           ((uint8_T)3U)
#define GCU_timer_IN_SET_NEUTRAL       ((uint8_T)3U)
#define GCU_timer_IN_START             ((uint8_T)4U)
#define GCU_timer_IN_START_RELEASE     ((uint8_T)5U)
#define GCU_timer_IN_START_b           ((uint8_T)1U)
#define GCU_timer_IN_STOP              ((uint8_T)2U)
#define GCU_timer_IN_STOPPING          ((uint8_T)2U)
#define GCU_timer_IN_SettingNeutral    ((uint8_T)2U)
#define GCU_timer_IN_SettingNeutral_j  ((uint8_T)3U)
#define GCU_timer_IN_UNSET_NEUTRAL     ((uint8_T)4U)
#define GCU_timer_IN_UPSHIFTING        ((uint8_T)5U)
#define GCU_timer_IN_UP_BRAKE          ((uint8_T)1U)
#define GCU_timer_IN_UP_END            ((uint8_T)6U)
#define GCU_timer_IN_UP_PUSH           ((uint8_T)2U)
#define GCU_timer_IN_UP_REBOUND        ((uint8_T)3U)
#define GCU_timer_IN_UP_START          ((uint8_T)4U)
#define GCU_timer_IN_WAIT              ((uint8_T)3U)
#define GCU_timer_RELEASE_AAC_COM      ((uint16_T)2U)
#define GCU_timer_START_AAC_COM        ((uint16_T)1U)
#define GCU_timer_STOP_AAC_COM         ((uint16_T)0U)
#define GCU_timer_event_GearshiftDown  (0)
#define GCU_timer_event_GearshiftUp    (2)

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       ((rtmGetSimTimeStep((rtm))) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       ((rtmGetSimTimeStep((rtm))) == MINOR_TIME_STEP)
#endif

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

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        (*((rtm)->Timing.simTimeStep))
#endif

#ifndef rtmGetSimTimeStepPointer
# define rtmGetSimTimeStepPointer(rtm) (rtm)->Timing.simTimeStep
#endif

#ifndef rtmSetSimTimeStepPointer
# define rtmSetSimTimeStepPointer(rtm, val) ((rtm)->Timing.simTimeStep = (val))
#endif

MdlrefDW_GCU_timer_T GCU_timer_MdlrefDW;

/* Block states (default storage) */
DW_GCU_timer_f_T GCU_timer_DW;

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

  extern void Efi_init_Start_wrapper(void);
  extern void Efi_init_Outputs_wrapper(void);
  extern void Efi_init_Terminate_wrapper(void);

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

/* Forward declaration for local functions */
static void GCU_timer_NEUTRAL_STATE(void);
static int32_T GCU_timer_getAacParam(aac_params b_index);
static int32_T GCU_timer_Gearshift_getTime(const uint8_T *rtu_currentGear);
static void GCU_timer_Clutch_setValue(uint8_T setValue, uint8_T
  *rty_clutchCurrVal);
static void GCU_timer_GEARSHIFT(const uint8_T *rtu_currentGear, uint8_T
  *rty_clutchCurrVal, uint8_T *rty_upCut_Pin, uint8_T *rty_PinIn1, uint8_T
  *rty_PinIn2, uint8_T *rty_PinH);
static void GCU_timer_aacCheckShift(const uint8_T *rtu_currentGear, const
  uint16_T rtu_aac_externValues[3], uint8_T *rty_clutchCurrVal, uint8_T
  *rty_upCut_Pin, uint8_T *rty_PinIn1, uint8_T *rty_PinIn2, uint8_T *rty_PinH);
static void GCU_timer_checkShift(const uint8_T *rtu_currentGear, const uint16_T
  rtu_shiftCom[2], uint8_T *rty_clutchCurrVal, uint8_T *rty_upCut_Pin, uint8_T
  *rty_PinIn1, uint8_T *rty_PinIn2, uint8_T *rty_PinH);
static void GCU_timer_ACTIVE(const uint8_T *rtu_currentGear, const uint16_T
  rtu_aac_externValues[3], const uint16_T rtu_shiftCom[2], const uint16_T
  rtu_aacCom[2], uint8_T *rty_clutchCurrVal, uint8_T *rty_upCut_Pin, uint8_T
  *rty_rpmLimiter_Pin, uint8_T *rty_PinIn1, uint8_T *rty_PinIn2, uint8_T
  *rty_PinH);
static void GCU_timer_checkClutch(const uint8_T rtu_clutchCom[2], uint8_T
  *rty_clutchCurrVal);

/* Declare global variables for system: model 'GCU_timer' */
const uint8_T *GCU_timer_rtu_currentGear;/* '<Root>/currentGear' */
const uint16_T *GCU_timer_rtu_aac_externValues;/* '<Root>/aac_externValues' */
const uint16_T *GCU_timer_rtu_shiftCom;/* '<Root>/shiftCom' */
const uint16_T *GCU_timer_rtu_aacCom;  /* '<Root>/aacCom' */
const uint8_T *GCU_timer_rtu_clutchCom;/* '<Root>/clutchCom' */
uint8_T *GCU_timer_rty_clutchCurrVal;  /* '<Root>/clutchCurrVal' */
uint8_T *GCU_timer_rty_upCut_Pin;      /* '<Root>/upCut_Pin' */
uint8_T *GCU_timer_rty_rpmLimiter_Pin; /* '<Root>/rpmLimiter_Pin' */
uint8_T *GCU_timer_rty_PinIn1;         /* '<Root>/PinIn1' */
uint8_T *GCU_timer_rty_PinIn2;         /* '<Root>/PinIn2' */
uint8_T *GCU_timer_rty_PinH;           /* '<Root>/PinH' */

/*
 * Output and update for function-call system:
 *    '<S2>/SetCut'
 *    '<S2>/SetRPMLimiter'
 */
void GCU_timer_SetCut(uint8_T *rty_downCut_pin, DW_SetCut_GCU_timer_T *localDW)
{
  /* S-Function (Efi_setBlip): '<S12>/Efi SetBlip' */
  Efi_setBlip_Outputs_wrapper(&localDW->EfiSetBlip);

  /* SignalConversion: '<S12>/OutportBufferFordownCut_pin' */
  *rty_downCut_pin = localDW->EfiSetBlip;
}

/*
 * Output and update for function-call system:
 *    '<S2>/UnsetCut'
 *    '<S2>/UnsetRPMLimiter'
 */
void GCU_timer_UnsetCut(uint8_T *rty_downCut_pin, DW_UnsetCut_GCU_timer_T
  *localDW)
{
  /* S-Function (Efi_unsetBlip): '<S14>/Efi UnSetBlip' */
  Efi_unsetBlip_Outputs_wrapper(&localDW->EfiUnSetBlip);

  /* SignalConversion: '<S14>/OutportBufferFordownCut_pin' */
  *rty_downCut_pin = localDW->EfiUnSetBlip;
}

/* Output and update for function-call system: '<S5>/Gearmotor_release' */
void GCU_timer_Gearmotor_release(void)
{
  /* S-Function (GearMotor_release): '<S19>/GearMotor Release' */
  GearMotor_release_Outputs_wrapper(&GCU_timer_DW.GearMotorRelease);

  /* SignalConversion: '<S19>/OutportBufferForPin H' */
  *GCU_timer_rty_PinH = GCU_timer_DW.GearMotorRelease;
}

/* Output and update for function-call system: '<S5>/Gearmotor_turnRight' */
void GCU_timer_Gearmotor_turnRight(uint8_T *rty_Pin_In1, uint8_T *rty_Pin_In2,
  uint8_T *rty_Pin_H, DW_Gearmotor_turnRight_GCU_ti_T *localDW)
{
  /* S-Function (GearMotor_turnRight): '<S21>/GearMotor Turn Right' */
  GearMotor_turnRight_Outputs_wrapper(&localDW->GearMotorTurnRight_o1,
    &localDW->GearMotorTurnRight_o2, &localDW->GearMotorTurnRight_o3);

  /* SignalConversion: '<S21>/OutportBufferForPin_H' */
  *rty_Pin_H = localDW->GearMotorTurnRight_o3;

  /* SignalConversion: '<S21>/OutportBufferForPin_In1' */
  *rty_Pin_In1 = localDW->GearMotorTurnRight_o1;

  /* SignalConversion: '<S21>/OutportBufferForPin_In2' */
  *rty_Pin_In2 = localDW->GearMotorTurnRight_o2;
}

/* Output and update for function-call system: '<S5>/Gearmotor_brake' */
void GCU_timer_Gearmotor_brake(uint8_T *rty_Pin_In1, uint8_T *rty_Pin_In2,
  uint8_T *rty_Pin_H, DW_Gearmotor_brake_GCU_timer_T *localDW)
{
  /* S-Function (GearMotor_brake): '<S18>/GearMotor Brake' */
  GearMotor_brake_Outputs_wrapper(&localDW->GearMotorBrake_o1,
    &localDW->GearMotorBrake_o2, &localDW->GearMotorBrake_o3);

  /* SignalConversion: '<S18>/OutportBufferForPin_H' */
  *rty_Pin_H = localDW->GearMotorBrake_o3;

  /* SignalConversion: '<S18>/OutportBufferForPin_In1' */
  *rty_Pin_In1 = localDW->GearMotorBrake_o1;

  /* SignalConversion: '<S18>/OutportBufferForPin_In2' */
  *rty_Pin_In2 = localDW->GearMotorBrake_o2;
}

/* Output and update for function-call system: '<S3>/EngineControl_Start' */
void GCU_timer_EngineControl_Start(uint8_T *rty_engine_starter,
  DW_EngineControl_Start_GCU_ti_T *localDW)
{
  /* S-Function (EngineControl_start): '<S16>/EngineControl Start' */
  EngineControl_start_Outputs_wrapper(&localDW->EngineControlStart);

  /* SignalConversion: '<S16>/OutportBufferForengine_starter' */
  *rty_engine_starter = localDW->EngineControlStart;
}

/* Function for Chart: '<Root>/GCULogic' */
static void GCU_timer_NEUTRAL_STATE(void)
{
  switch (GCU_timer_DW.is_NEUTRAL_STATE) {
   case GCU_timer_IN_NEUTRAL:
    if ((GCU_timer_DW.sfEvent == GCU_timer_event_GearshiftUp) ||
        (GCU_timer_DW.sfEvent == GCU_timer_event_GearshiftDown)) {
      GCU_timer_DW.is_NEUTRAL_STATE = GCU_timer_IN_UNSET_NEUTRAL;
    }
    break;

   case GCU_timer_IN_NO_NEUTRAL:
    if (GCU_timer_DW.sfEvent == GCU_t_event_GearshiftSetNeutral) {
      GCU_timer_DW.is_NEUTRAL_STATE = GCU_timer_IN_SET_NEUTRAL;
    }
    break;

   case GCU_timer_IN_SET_NEUTRAL:
    if ((GCU_timer_DW.is_GEARSHIFT == GCU_timer_IN_DOWN_END) ||
        (GCU_timer_DW.is_GEARSHIFT == GCU_timer_IN_UP_END)) {
      GCU_timer_DW.is_NEUTRAL_STATE = GCU_timer_IN_NEUTRAL;
    }
    break;

   case GCU_timer_IN_UNSET_NEUTRAL:
    if ((GCU_timer_DW.is_GEARSHIFT == GCU_timer_IN_DOWN_END) ||
        (GCU_timer_DW.is_GEARSHIFT == GCU_timer_IN_UP_END)) {
      GCU_timer_DW.is_NEUTRAL_STATE = GCU_timer_IN_NO_NEUTRAL;
    }
    break;
  }
}

/* Function for Chart: '<Root>/GCULogic' */
static int32_T GCU_timer_getAacParam(aac_params b_index)
{
  int32_T q0;
  q0 = b_index;
  if (q0 > 2147483646) {
    q0 = MAX_int32_T;
  } else {
    q0++;
  }

  return GCU_timer_DW.aac_parameters[q0 - 1];
}

/* Function for Chart: '<Root>/GCULogic' */
static int32_T GCU_timer_Gearshift_getTime(const uint8_T *rtu_currentGear)
{
  int32_T time;
  if (GCU_timer_DW.is_UPSHIFTING == GCU_timer_IN_UP_START) {
    if (GCU_timer_DW.is_NEUTRAL_STATE == GCU_timer_IN_SET_NEUTRAL) {
      time = DEFAULT_NT_CLUTCH_DELAY;
    } else {
      time = DEFAULT_DELAY;
    }
  } else if (GCU_timer_DW.is_UPSHIFTING == GCU_timer_IN_UP_PUSH) {
    if (GCU_timer_DW.is_NEUTRAL_STATE == GCU_timer_IN_SET_NEUTRAL) {
      time = DEFAULT_NT_CLUTCH_DELAY;
    } else {
      switch (*rtu_currentGear) {
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
    }
  } else if (GCU_timer_DW.is_UPSHIFTING == GCU_timer_IN_UP_REBOUND) {
    if (GCU_timer_DW.is_NEUTRAL_STATE == GCU_timer_IN_SET_NEUTRAL) {
      time = DEFAULT_NT_REBOUND_1_N;
    } else {
      time = DEFAULT_UP_REBOUND;
    }
  } else if (GCU_timer_DW.is_UPSHIFTING == GCU_timer_IN_UP_BRAKE) {
    if (GCU_timer_DW.is_NEUTRAL_STATE == GCU_timer_IN_SET_NEUTRAL) {
      time = DEFAULT_NT_BRAKE_1_N;
    } else {
      time = DEFAULT_UP_BRAKE;
    }
  } else if (GCU_timer_DW.is_DOWNSHIFTING == GCU_timer_IN_DOWN_START) {
    time = DEFAULT_CLUTCH;
  } else if (GCU_timer_DW.is_DOWNSHIFTING == GCU_timer_IN_DOWN_PUSH) {
    time = DEFAULT_DN_PUSH;
  } else if (GCU_timer_DW.is_DOWNSHIFTING == GCU_timer_IN_DOWN_REBOUND) {
    time = DEFAULT_DN_REBOUND;
  } else {
    time = DEFAULT_DN_BRAKE;
  }

  return time;
}

/* Function for Chart: '<Root>/GCULogic' */
static void GCU_timer_Clutch_setValue(uint8_T setValue, uint8_T
  *rty_clutchCurrVal)
{
  *rty_clutchCurrVal = setValue;

  /* Outputs for Function Call SubSystem: '<S1>/ClutchMotor SetPosition ' */
  /* Sum: '<S10>/Minus' incorporates:
   *  Constant: '<S10>/Constant'
   */
  GCU_timer_DW.Minus = (uint8_T)(100 - *rty_clutchCurrVal);

  /* S-Function (ClutchMotor_setPosition): '<S10>/ClutchMotor SetPosition' */
  ClutchMotor_setPosition_Outputs_wrapper(&GCU_timer_DW.Minus);

  /* End of Outputs for SubSystem: '<S1>/ClutchMotor SetPosition ' */
}

/* Function for Chart: '<Root>/GCULogic' */
static void GCU_timer_GEARSHIFT(const uint8_T *rtu_currentGear, uint8_T
  *rty_clutchCurrVal, uint8_T *rty_upCut_Pin, uint8_T *rty_PinIn1, uint8_T
  *rty_PinIn2, uint8_T *rty_PinH)
{
  switch (GCU_timer_DW.is_GEARSHIFT) {
   case GCU_timer_IN_DOWNSHIFTING:
    switch (GCU_timer_DW.is_DOWNSHIFTING) {
     case GCU_timer_IN_DOWN_BRAKE:
      if (GCU_timer_DW.ticksCounter == 0) {
        GCU_timer_DW.is_DOWN_BRAKE = GCU_timer_IN_NO_ACTIVE_CHILD;
        GCU_timer_DW.is_DOWNSHIFTING = GCU_timer_IN_NO_ACTIVE_CHILD;
        GCU_timer_DW.is_GEARSHIFT = GCU_timer_IN_NO_ACTIVE_CHILD;
        if (GCU_timer_DW.is_GEARSHIFT != GCU_timer_IN_DOWN_END) {
          GCU_timer_DW.is_GEARSHIFT = GCU_timer_IN_DOWN_END;

          /* Outputs for Function Call SubSystem: '<S5>/Gearmotor_release' */
          GCU_timer_Gearmotor_release();

          /* End of Outputs for SubSystem: '<S5>/Gearmotor_release' */
        }
      } else if (GCU_timer_DW.ticksCounter < -2147483647) {
        GCU_timer_DW.ticksCounter = MIN_int32_T;
      } else {
        GCU_timer_DW.ticksCounter--;
      }
      break;

     case GCU_timer_IN_DOWN_PUSH:
      if (GCU_timer_DW.ticksCounter == 0) {
        GCU_timer_DW.is_DOWNSHIFTING = GCU_timer_IN_NO_ACTIVE_CHILD;
        if (GCU_timer_DW.is_DOWNSHIFTING != GCU_timer_IN_DOWN_REBOUND) {
          GCU_timer_DW.is_DOWNSHIFTING = GCU_timer_IN_DOWN_REBOUND;
          GCU_timer_DW.ticksCounter = GCU_timer_Gearshift_getTime
            (rtu_currentGear);

          /* Outputs for Function Call SubSystem: '<S5>/Gearmotor_release' */
          GCU_timer_Gearmotor_release();

          /* End of Outputs for SubSystem: '<S5>/Gearmotor_release' */
        }
      } else if (GCU_timer_DW.ticksCounter < -2147483647) {
        GCU_timer_DW.ticksCounter = MIN_int32_T;
      } else {
        GCU_timer_DW.ticksCounter--;
      }
      break;

     case GCU_timer_IN_DOWN_REBOUND:
      if (GCU_timer_DW.ticksCounter == 0) {
        GCU_timer_DW.is_DOWNSHIFTING = GCU_timer_IN_NO_ACTIVE_CHILD;
        if (GCU_timer_DW.is_DOWNSHIFTING != GCU_timer_IN_DOWN_BRAKE) {
          GCU_timer_DW.is_DOWNSHIFTING = GCU_timer_IN_DOWN_BRAKE;
          GCU_timer_DW.ticksCounter = GCU_timer_Gearshift_getTime
            (rtu_currentGear);
        }

        if (*rty_clutchCurrVal < 81) {
          if (GCU_timer_DW.is_DOWN_BRAKE != GCU_timer_IN_ChangeClutch) {
            GCU_timer_DW.is_DOWN_BRAKE = GCU_timer_IN_ChangeClutch;
            GCU_timer_Clutch_setValue(80, rty_clutchCurrVal);

            /* Outputs for Function Call SubSystem: '<S5>/Gearmotor_brake' */
            GCU_timer_Gearmotor_brake(rty_PinIn1, rty_PinIn2, rty_PinH,
              &GCU_timer_DW.Gearmotor_brake);

            /* End of Outputs for SubSystem: '<S5>/Gearmotor_brake' */
          }
        } else {
          if (GCU_timer_DW.is_DOWN_BRAKE != GCU_timer_IN_Default_n) {
            GCU_timer_DW.is_DOWN_BRAKE = GCU_timer_IN_Default_n;

            /* Outputs for Function Call SubSystem: '<S5>/Gearmotor_brake' */
            GCU_timer_Gearmotor_brake(rty_PinIn1, rty_PinIn2, rty_PinH,
              &GCU_timer_DW.Gearmotor_brake);

            /* End of Outputs for SubSystem: '<S5>/Gearmotor_brake' */
          }
        }
      } else if (GCU_timer_DW.ticksCounter < -2147483647) {
        GCU_timer_DW.ticksCounter = MIN_int32_T;
      } else {
        GCU_timer_DW.ticksCounter--;
      }
      break;

     case GCU_timer_IN_DOWN_START:
      if (GCU_timer_DW.ticksCounter == 0) {
        GCU_timer_DW.is_DOWN_START = GCU_timer_IN_NO_ACTIVE_CHILD;
        GCU_timer_DW.is_DOWNSHIFTING = GCU_timer_IN_NO_ACTIVE_CHILD;
        if (GCU_timer_DW.is_DOWNSHIFTING != GCU_timer_IN_DOWN_PUSH) {
          GCU_timer_DW.is_DOWNSHIFTING = GCU_timer_IN_DOWN_PUSH;
          GCU_timer_DW.ticksCounter = GCU_timer_Gearshift_getTime
            (rtu_currentGear);

          /* Outputs for Function Call SubSystem: '<S5>/Gearmotor_turnLeft' */
          /* S-Function (GearMotor_turnLeft): '<S20>/GearMotor Turn Left' */
          GearMotor_turnLeft_Outputs_wrapper(&GCU_timer_DW.GearMotorTurnLeft_o1,
            &GCU_timer_DW.GearMotorTurnLeft_o2,
            &GCU_timer_DW.GearMotorTurnLeft_o3);

          /* SignalConversion: '<S20>/OutportBufferForPin_H' */
          *rty_PinH = GCU_timer_DW.GearMotorTurnLeft_o3;

          /* SignalConversion: '<S20>/OutportBufferForPin_In1' */
          *rty_PinIn1 = GCU_timer_DW.GearMotorTurnLeft_o1;

          /* SignalConversion: '<S20>/OutportBufferForPin_In2' */
          *rty_PinIn2 = GCU_timer_DW.GearMotorTurnLeft_o2;

          /* End of Outputs for SubSystem: '<S5>/Gearmotor_turnLeft' */
        }
      } else if (GCU_timer_DW.ticksCounter < -2147483647) {
        GCU_timer_DW.ticksCounter = MIN_int32_T;
      } else {
        GCU_timer_DW.ticksCounter--;
      }
      break;
    }
    break;

   case GCU_timer_IN_DOWN_END:
    GCU_timer_DW.is_GEARSHIFT = GCU_timer_IN_NO_ACTIVE_CHILD;
    if (GCU_timer_DW.is_GEARSHIFT != GCU_timer_IN_IDLE) {
      GCU_timer_DW.is_GEARSHIFT = GCU_timer_IN_IDLE;
    }
    break;

   case GCU_timer_IN_IDLE:
    switch (GCU_timer_DW.sfEvent) {
     case GCU_timer_event_GearshiftUp:
      GCU_timer_DW.is_GEARSHIFT = GCU_timer_IN_UPSHIFTING;
      if (GCU_timer_DW.is_UPSHIFTING != GCU_timer_IN_UP_START) {
        GCU_timer_DW.is_UPSHIFTING = GCU_timer_IN_UP_START;
        GCU_timer_DW.ticksCounter = GCU_timer_Gearshift_getTime(rtu_currentGear);
      }

      if (GCU_timer_DW.is_NEUTRAL_STATE == GCU_timer_IN_SET_NEUTRAL) {
        if (GCU_timer_DW.is_UP_START != GCU_timer_IN_SettingNeutral) {
          GCU_timer_DW.is_UP_START = GCU_timer_IN_SettingNeutral;
          GCU_timer_Clutch_setValue(80, rty_clutchCurrVal);
        }
      } else {
        if (GCU_timer_DW.is_UP_START != GCU_timer_IN_Default) {
          GCU_timer_DW.is_UP_START = GCU_timer_IN_Default;

          /* Outputs for Function Call SubSystem: '<S2>/SetCut' */
          GCU_timer_SetCut(rty_upCut_Pin, &GCU_timer_DW.SetCut);

          /* End of Outputs for SubSystem: '<S2>/SetCut' */
        }
      }
      break;

     case GCU_timer_event_GearshiftDown:
      GCU_timer_DW.is_GEARSHIFT = GCU_timer_IN_DOWNSHIFTING;
      if (GCU_timer_DW.is_DOWNSHIFTING != GCU_timer_IN_DOWN_START) {
        GCU_timer_DW.is_DOWNSHIFTING = GCU_timer_IN_DOWN_START;
        GCU_timer_DW.ticksCounter = GCU_timer_Gearshift_getTime(rtu_currentGear);
      }

      if ((GCU_timer_DW.is_NEUTRAL_STATE == GCU_timer_IN_SET_NEUTRAL) &&
          (*rty_clutchCurrVal <= 80)) {
        if (GCU_timer_DW.is_DOWN_START != GCU_timer_IN_SettingNeutral_j) {
          GCU_timer_DW.is_DOWN_START = GCU_timer_IN_SettingNeutral_j;
          GCU_timer_Clutch_setValue(80, rty_clutchCurrVal);
        }
      } else if ((!(GCU_timer_DW.is_NEUTRAL_STATE == GCU_timer_IN_UNSET_NEUTRAL))
                 && (*rty_clutchCurrVal <= 60)) {
        if (GCU_timer_DW.is_DOWN_START != GCU_timer_IN_ChangeClutch) {
          GCU_timer_DW.is_DOWN_START = GCU_timer_IN_ChangeClutch;
          GCU_timer_Clutch_setValue(60, rty_clutchCurrVal);
        }
      } else {
        GCU_timer_DW.is_DOWN_START = GCU_timer_IN_Default_n;
      }
      break;
    }
    break;

   case GCU_timer_IN_INIT_f:
    GCU_timer_DW.is_GEARSHIFT = GCU_timer_IN_NO_ACTIVE_CHILD;
    if (GCU_timer_DW.is_GEARSHIFT != GCU_timer_IN_IDLE) {
      GCU_timer_DW.is_GEARSHIFT = GCU_timer_IN_IDLE;
    }
    break;

   case GCU_timer_IN_UPSHIFTING:
    switch (GCU_timer_DW.is_UPSHIFTING) {
     case GCU_timer_IN_UP_BRAKE:
      if (GCU_timer_DW.ticksCounter == 0) {
        GCU_timer_DW.is_UPSHIFTING = GCU_timer_IN_NO_ACTIVE_CHILD;
        GCU_timer_DW.is_GEARSHIFT = GCU_timer_IN_NO_ACTIVE_CHILD;
        if (GCU_timer_DW.is_GEARSHIFT != GCU_timer_IN_UP_END) {
          GCU_timer_DW.is_GEARSHIFT = GCU_timer_IN_UP_END;

          /* Outputs for Function Call SubSystem: '<S5>/Gearmotor_release' */
          GCU_timer_Gearmotor_release();

          /* End of Outputs for SubSystem: '<S5>/Gearmotor_release' */
        }
      } else if (GCU_timer_DW.ticksCounter < -2147483647) {
        GCU_timer_DW.ticksCounter = MIN_int32_T;
      } else {
        GCU_timer_DW.ticksCounter--;
      }
      break;

     case GCU_timer_IN_UP_PUSH:
      if (GCU_timer_DW.ticksCounter == 0) {
        GCU_timer_DW.is_UP_PUSH = GCU_timer_IN_NO_ACTIVE_CHILD;
        GCU_timer_DW.is_UPSHIFTING = GCU_timer_IN_NO_ACTIVE_CHILD;
        if (GCU_timer_DW.is_UPSHIFTING != GCU_timer_IN_UP_REBOUND) {
          GCU_timer_DW.is_UPSHIFTING = GCU_timer_IN_UP_REBOUND;
          GCU_timer_DW.ticksCounter = GCU_timer_Gearshift_getTime
            (rtu_currentGear);
        }

        if (GCU_timer_DW.is_NEUTRAL_STATE == GCU_timer_IN_SET_NEUTRAL) {
          if (GCU_timer_DW.is_UP_REBOUND != GCU_timer_IN_SettingNeutral) {
            GCU_timer_DW.is_UP_REBOUND = GCU_timer_IN_SettingNeutral;
            GCU_timer_Clutch_setValue(0, rty_clutchCurrVal);

            /* Outputs for Function Call SubSystem: '<S5>/Gearmotor_release' */
            GCU_timer_Gearmotor_release();

            /* End of Outputs for SubSystem: '<S5>/Gearmotor_release' */
          }
        } else {
          if (GCU_timer_DW.is_UP_REBOUND != GCU_timer_IN_Default) {
            GCU_timer_DW.is_UP_REBOUND = GCU_timer_IN_Default;

            /* Outputs for Function Call SubSystem: '<S5>/Gearmotor_release' */
            GCU_timer_Gearmotor_release();

            /* End of Outputs for SubSystem: '<S5>/Gearmotor_release' */
          }
        }
      } else if (GCU_timer_DW.ticksCounter < -2147483647) {
        GCU_timer_DW.ticksCounter = MIN_int32_T;
      } else {
        GCU_timer_DW.ticksCounter--;
      }
      break;

     case GCU_timer_IN_UP_REBOUND:
      if (GCU_timer_DW.ticksCounter == 0) {
        GCU_timer_DW.is_UP_REBOUND = GCU_timer_IN_NO_ACTIVE_CHILD;
        GCU_timer_DW.is_UPSHIFTING = GCU_timer_IN_NO_ACTIVE_CHILD;
        if (GCU_timer_DW.is_UPSHIFTING != GCU_timer_IN_UP_BRAKE) {
          GCU_timer_DW.is_UPSHIFTING = GCU_timer_IN_UP_BRAKE;
          GCU_timer_DW.ticksCounter = GCU_timer_Gearshift_getTime
            (rtu_currentGear);

          /* Outputs for Function Call SubSystem: '<S5>/Gearmotor_brake' */
          GCU_timer_Gearmotor_brake(rty_PinIn1, rty_PinIn2, rty_PinH,
            &GCU_timer_DW.Gearmotor_brake);

          /* End of Outputs for SubSystem: '<S5>/Gearmotor_brake' */
        }
      } else if (GCU_timer_DW.ticksCounter < -2147483647) {
        GCU_timer_DW.ticksCounter = MIN_int32_T;
      } else {
        GCU_timer_DW.ticksCounter--;
      }
      break;

     case GCU_timer_IN_UP_START:
      if (GCU_timer_DW.ticksCounter == 0) {
        GCU_timer_DW.is_UP_START = GCU_timer_IN_NO_ACTIVE_CHILD;
        GCU_timer_DW.is_UPSHIFTING = GCU_timer_IN_NO_ACTIVE_CHILD;
        if (GCU_timer_DW.is_UPSHIFTING != GCU_timer_IN_UP_PUSH) {
          GCU_timer_DW.is_UPSHIFTING = GCU_timer_IN_UP_PUSH;
          GCU_timer_DW.ticksCounter = GCU_timer_Gearshift_getTime
            (rtu_currentGear);
        }

        if (!(GCU_timer_DW.is_NEUTRAL_STATE == GCU_timer_IN_SET_NEUTRAL)) {
          if (GCU_timer_DW.is_UP_PUSH != GCU_timer_IN_CutOff) {
            GCU_timer_DW.is_UP_PUSH = GCU_timer_IN_CutOff;

            /* Outputs for Function Call SubSystem: '<S2>/UnsetCut' */
            GCU_timer_UnsetCut(rty_upCut_Pin, &GCU_timer_DW.UnsetCut);

            /* End of Outputs for SubSystem: '<S2>/UnsetCut' */

            /* Outputs for Function Call SubSystem: '<S5>/Gearmotor_turnRight' */
            GCU_timer_Gearmotor_turnRight(rty_PinIn1, rty_PinIn2, rty_PinH,
              &GCU_timer_DW.Gearmotor_turnRight);

            /* End of Outputs for SubSystem: '<S5>/Gearmotor_turnRight' */
          }
        } else {
          if (GCU_timer_DW.is_UP_PUSH != GCU_timer_IN_Default_n) {
            GCU_timer_DW.is_UP_PUSH = GCU_timer_IN_Default_n;

            /* Outputs for Function Call SubSystem: '<S5>/Gearmotor_turnRight' */
            GCU_timer_Gearmotor_turnRight(rty_PinIn1, rty_PinIn2, rty_PinH,
              &GCU_timer_DW.Gearmotor_turnRight);

            /* End of Outputs for SubSystem: '<S5>/Gearmotor_turnRight' */
          }
        }
      } else if (GCU_timer_DW.ticksCounter < -2147483647) {
        GCU_timer_DW.ticksCounter = MIN_int32_T;
      } else {
        GCU_timer_DW.ticksCounter--;
      }
      break;
    }
    break;

   case GCU_timer_IN_UP_END:
    GCU_timer_DW.is_GEARSHIFT = GCU_timer_IN_NO_ACTIVE_CHILD;
    if (GCU_timer_DW.is_GEARSHIFT != GCU_timer_IN_IDLE) {
      GCU_timer_DW.is_GEARSHIFT = GCU_timer_IN_IDLE;
    }
    break;
  }
}

/* Function for Chart: '<Root>/GCULogic' */
static void GCU_timer_aacCheckShift(const uint8_T *rtu_currentGear, const
  uint16_T rtu_aac_externValues[3], uint8_T *rty_clutchCurrVal, uint8_T
  *rty_upCut_Pin, uint8_T *rty_PinIn1, uint8_T *rty_PinIn2, uint8_T *rty_PinH)
{
  int32_T b_previousEvent;
  if (GCU_timer_DW.lastShift == *rtu_currentGear) {
    b_previousEvent = (int32_T)((uint32_T)RPM_LIMIT_1_2 + *rtu_currentGear);
    if ((uint32_T)b_previousEvent > 255U) {
      b_previousEvent = 255;
    }

    if (rtu_aac_externValues[0] >= GCU_timer_DW.aac_parameters[b_previousEvent -
        1]) {
      b_previousEvent = (int32_T)((uint32_T)SPEED_LIMIT_1_2 + *rtu_currentGear);
      if ((uint32_T)b_previousEvent > 255U) {
        b_previousEvent = 255;
      }

      if (rtu_aac_externValues[1] >= GCU_timer_DW.aac_parameters[b_previousEvent
          - 1]) {
        b_previousEvent = GCU_timer_DW.sfEvent;
        GCU_timer_DW.sfEvent = GCU_timer_event_GearshiftUp;
        if (GCU_timer_DW.is_active_GEARSHIFT != 0U) {
          GCU_timer_GEARSHIFT(rtu_currentGear, rty_clutchCurrVal, rty_upCut_Pin,
                              rty_PinIn1, rty_PinIn2, rty_PinH);
        }

        GCU_timer_DW.sfEvent = b_previousEvent;
        b_previousEvent = (int32_T)(GCU_timer_DW.lastShift + 1U);
        if ((uint32_T)b_previousEvent > 255U) {
          b_previousEvent = 255;
        }

        GCU_timer_DW.lastShift = (uint8_T)b_previousEvent;
      }
    }
  }
}

/* Function for Chart: '<Root>/GCULogic' */
static void GCU_timer_checkShift(const uint8_T *rtu_currentGear, const uint16_T
  rtu_shiftCom[2], uint8_T *rty_clutchCurrVal, uint8_T *rty_upCut_Pin, uint8_T
  *rty_PinIn1, uint8_T *rty_PinIn2, uint8_T *rty_PinH)
{
  int32_T b_previousEvent;
  if (rtu_shiftCom[0] != GCU_timer_DW.lastShiftCom) {
    GCU_timer_DW.lastShiftCom = rtu_shiftCom[0];
    if (rtu_shiftCom[1] == GCU_timer_GEAR_COMMAND_UP) {
      b_previousEvent = GCU_timer_DW.sfEvent;
      GCU_timer_DW.sfEvent = GCU_timer_event_GearshiftUp;
      if (GCU_timer_DW.is_active_NEUTRAL_STATE != 0U) {
        GCU_timer_NEUTRAL_STATE();
      }

      GCU_timer_DW.sfEvent = b_previousEvent;
      b_previousEvent = GCU_timer_DW.sfEvent;
      GCU_timer_DW.sfEvent = GCU_timer_event_GearshiftUp;
      if (GCU_timer_DW.is_active_GEARSHIFT != 0U) {
        GCU_timer_GEARSHIFT(rtu_currentGear, rty_clutchCurrVal, rty_upCut_Pin,
                            rty_PinIn1, rty_PinIn2, rty_PinH);
      }

      GCU_timer_DW.sfEvent = b_previousEvent;
    } else if (rtu_shiftCom[1] == GCU_timer_GEAR_COMMAND_DOWN) {
      b_previousEvent = GCU_timer_DW.sfEvent;
      GCU_timer_DW.sfEvent = GCU_timer_event_GearshiftDown;
      if (GCU_timer_DW.is_active_NEUTRAL_STATE != 0U) {
        GCU_timer_NEUTRAL_STATE();
      }

      GCU_timer_DW.sfEvent = b_previousEvent;
      b_previousEvent = GCU_timer_DW.sfEvent;
      GCU_timer_DW.sfEvent = GCU_timer_event_GearshiftDown;
      if (GCU_timer_DW.is_active_GEARSHIFT != 0U) {
        GCU_timer_GEARSHIFT(rtu_currentGear, rty_clutchCurrVal, rty_upCut_Pin,
                            rty_PinIn1, rty_PinIn2, rty_PinH);
      }

      GCU_timer_DW.sfEvent = b_previousEvent;
    } else if (rtu_shiftCom[1] == GCU_tim_GEAR_COMMAND_NEUTRAL_UP) {
      b_previousEvent = GCU_timer_DW.sfEvent;
      GCU_timer_DW.sfEvent = GCU_t_event_GearshiftSetNeutral;
      if (GCU_timer_DW.is_active_NEUTRAL_STATE != 0U) {
        GCU_timer_NEUTRAL_STATE();
      }

      GCU_timer_DW.sfEvent = b_previousEvent;
      b_previousEvent = GCU_timer_DW.sfEvent;
      GCU_timer_DW.sfEvent = GCU_timer_event_GearshiftUp;
      if (GCU_timer_DW.is_active_GEARSHIFT != 0U) {
        GCU_timer_GEARSHIFT(rtu_currentGear, rty_clutchCurrVal, rty_upCut_Pin,
                            rty_PinIn1, rty_PinIn2, rty_PinH);
      }

      GCU_timer_DW.sfEvent = b_previousEvent;
    } else {
      if (rtu_shiftCom[1] == GCU_t_GEAR_COMMAND_NEUTRAL_DOWN) {
        b_previousEvent = GCU_timer_DW.sfEvent;
        GCU_timer_DW.sfEvent = GCU_t_event_GearshiftSetNeutral;
        if (GCU_timer_DW.is_active_NEUTRAL_STATE != 0U) {
          GCU_timer_NEUTRAL_STATE();
        }

        GCU_timer_DW.sfEvent = b_previousEvent;
        b_previousEvent = GCU_timer_DW.sfEvent;
        GCU_timer_DW.sfEvent = GCU_timer_event_GearshiftDown;
        if (GCU_timer_DW.is_active_GEARSHIFT != 0U) {
          GCU_timer_GEARSHIFT(rtu_currentGear, rty_clutchCurrVal, rty_upCut_Pin,
                              rty_PinIn1, rty_PinIn2, rty_PinH);
        }

        GCU_timer_DW.sfEvent = b_previousEvent;
      }
    }
  }
}

/* Function for Chart: '<Root>/GCULogic' */
static void GCU_timer_ACTIVE(const uint8_T *rtu_currentGear, const uint16_T
  rtu_aac_externValues[3], const uint16_T rtu_shiftCom[2], const uint16_T
  rtu_aacCom[2], uint8_T *rty_clutchCurrVal, uint8_T *rty_upCut_Pin, uint8_T
  *rty_rpmLimiter_Pin, uint8_T *rty_PinIn1, uint8_T *rty_PinIn2, uint8_T
  *rty_PinH)
{
  int32_T A;
  uint32_T q;
  boolean_T c_sf_internal_predicateOutput;
  int32_T q1;
  int64_T tmp;
  real_T tmp_0;
  uint32_T qY;
  uint8_T tmp_1;

  /* Chart: '<Root>/GCULogic' */
  if ((rtu_aacCom[0] != GCU_timer_DW.lastAacCom) && (rtu_aacCom[1] ==
       GCU_timer_STOP_AAC_COM)) {
    GCU_timer_DW.lastAacCom = rtu_aacCom[0];
    GCU_timer_DW.is_ACTIVE = GCU_timer_IN_NO_ACTIVE_CHILD;
    GCU_timer_DW.is_AAC = GCU_timer_IN_NO_ACTIVE_CHILD;
    if (GCU_timer_DW.is_AAC != GCU_timer_IN_STOPPING) {
      GCU_timer_DW.is_AAC = GCU_timer_IN_STOPPING;

      /* Outputs for Function Call SubSystem: '<S2>/UnsetRPMLimiter' */
      GCU_timer_UnsetCut(rty_rpmLimiter_Pin, &GCU_timer_DW.UnsetRPMLimiter_p);

      /* End of Outputs for SubSystem: '<S2>/UnsetRPMLimiter' */
    }
  } else {
    switch (GCU_timer_DW.is_ACTIVE) {
     case GCU_timer_IN_READY:
      if (GCU_timer_DW.aacCounter <= 1) {
        if ((rtu_aacCom[0] != GCU_timer_DW.lastAacCom) && (rtu_aacCom[1] ==
             GCU_timer_RELEASE_AAC_COM)) {
          GCU_timer_DW.lastAacCom = rtu_aacCom[0];
          GCU_timer_DW.is_ACTIVE = GCU_timer_IN_NO_ACTIVE_CHILD;
          if (GCU_timer_DW.is_ACTIVE != GCU_timer_IN_START_RELEASE) {
            GCU_timer_DW.is_ACTIVE = GCU_timer_IN_START_RELEASE;
            GCU_timer_DW.aac_clutchValue = GCU_timer_getAacParam(RAMP_START);
            tmp_0 = rt_roundd(GCU_timer_DW.aac_clutchValue);
            if (tmp_0 < 256.0) {
              if (tmp_0 >= 0.0) {
                tmp_1 = (uint8_T)tmp_0;
              } else {
                tmp_1 = 0U;
              }
            } else {
              tmp_1 = MAX_uint8_T;
            }

            GCU_timer_Clutch_setValue(tmp_1, rty_clutchCurrVal);
            A = GCU_timer_getAacParam(RAMP_TIME);
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

            GCU_timer_DW.aac_dtRelease = (int32_T)q;
            if (A < 0) {
              GCU_timer_DW.aac_dtRelease = -GCU_timer_DW.aac_dtRelease;
            }

            A = GCU_timer_getAacParam(RAMP_START);
            q1 = GCU_timer_getAacParam(RAMP_END);
            if ((A >= 0) && (q1 < A - MAX_int32_T)) {
              A = MAX_int32_T;
            } else if ((A < 0) && (q1 > A - MIN_int32_T)) {
              A = MIN_int32_T;
            } else {
              A -= q1;
            }

            tmp = (int64_T)A * GCU_timer_AAC_WORK_RATE_ms;
            if (tmp > 2147483647LL) {
              tmp = 2147483647LL;
            } else {
              if (tmp < -2147483648LL) {
                tmp = -2147483648LL;
              }
            }

            A = GCU_timer_getAacParam(RAMP_TIME);
            GCU_timer_DW.aac_clutchStep = (real_T)(int32_T)tmp / (real_T)A;
            GCU_timer_DW.aacCounter = GCU_timer_AAC_WORK_RATE_ms;
          }
        } else {
          GCU_timer_DW.is_ACTIVE = GCU_timer_IN_NO_ACTIVE_CHILD;
          if (GCU_timer_DW.is_ACTIVE != GCU_timer_IN_READY) {
            GCU_timer_DW.is_ACTIVE = GCU_timer_IN_READY;
            GCU_timer_DW.aacCounter = GCU_timer_AAC_WORK_RATE_ms;
            GCU_timer_Clutch_setValue(100, rty_clutchCurrVal);
            GCU_timer_checkShift(rtu_currentGear, rtu_shiftCom,
                                 rty_clutchCurrVal, rty_upCut_Pin, rty_PinIn1,
                                 rty_PinIn2, rty_PinH);
          }
        }
      } else {
        qY = GCU_timer_DW.aacCounter - /*MW:OvSatOk*/ 1U;
        if (qY > GCU_timer_DW.aacCounter) {
          qY = 0U;
        }

        GCU_timer_DW.aacCounter = (uint16_T)qY;
        GCU_timer_checkShift(rtu_currentGear, rtu_shiftCom, rty_clutchCurrVal,
                             rty_upCut_Pin, rty_PinIn1, rty_PinIn2, rty_PinH);
      }
      break;

     case GCU_timer_IN_RELEASING:
      if (GCU_timer_DW.aacCounter <= 1) {
        c_sf_internal_predicateOutput = ((GCU_timer_DW.aac_dtRelease <= 0) ||
          (*rty_clutchCurrVal <= GCU_timer_getAacParam(RAMP_END)));
        if (c_sf_internal_predicateOutput) {
          GCU_timer_Clutch_setValue(0, rty_clutchCurrVal);

          /* Outputs for Function Call SubSystem: '<S2>/UnsetRPMLimiter' */
          GCU_timer_UnsetCut(rty_rpmLimiter_Pin, &GCU_timer_DW.UnsetRPMLimiter_p);

          /* End of Outputs for SubSystem: '<S2>/UnsetRPMLimiter' */
          GCU_timer_DW.is_ACTIVE = GCU_timer_IN_NO_ACTIVE_CHILD;
          if (GCU_timer_DW.is_ACTIVE != GCU_timer_IN_RUNNING) {
            GCU_timer_DW.is_ACTIVE = GCU_timer_IN_RUNNING;
            GCU_timer_DW.aacCounter = GCU_timer_AAC_WORK_RATE_ms;
            GCU_timer_DW.lastShift = *rtu_currentGear;
            GCU_timer_aacCheckShift(rtu_currentGear, rtu_aac_externValues,
              rty_clutchCurrVal, rty_upCut_Pin, rty_PinIn1, rty_PinIn2, rty_PinH);
          }
        } else {
          GCU_timer_DW.is_ACTIVE = GCU_timer_IN_NO_ACTIVE_CHILD;
          if (GCU_timer_DW.is_ACTIVE != GCU_timer_IN_RELEASING) {
            GCU_timer_DW.is_ACTIVE = GCU_timer_IN_RELEASING;
            GCU_timer_DW.aac_clutchValue -= GCU_timer_DW.aac_clutchStep;
            tmp_0 = rt_roundd(GCU_timer_DW.aac_clutchValue);
            if (tmp_0 < 256.0) {
              if (tmp_0 >= 0.0) {
                tmp_1 = (uint8_T)tmp_0;
              } else {
                tmp_1 = 0U;
              }
            } else {
              tmp_1 = MAX_uint8_T;
            }

            GCU_timer_Clutch_setValue(tmp_1, rty_clutchCurrVal);
            if (GCU_timer_DW.aac_dtRelease < -2147483647) {
              GCU_timer_DW.aac_dtRelease = MIN_int32_T;
            } else {
              GCU_timer_DW.aac_dtRelease--;
            }

            GCU_timer_DW.aacCounter = GCU_timer_AAC_WORK_RATE_ms;
          }
        }
      } else {
        qY = GCU_timer_DW.aacCounter - /*MW:OvSatOk*/ 1U;
        if (qY > GCU_timer_DW.aacCounter) {
          qY = 0U;
        }

        GCU_timer_DW.aacCounter = (uint16_T)qY;
      }
      break;

     case GCU_timer_IN_RUNNING:
      if (*rtu_currentGear == 3) {
        GCU_timer_DW.is_ACTIVE = GCU_timer_IN_NO_ACTIVE_CHILD;
        GCU_timer_DW.is_AAC = GCU_timer_IN_NO_ACTIVE_CHILD;
        if (GCU_timer_DW.is_AAC != GCU_timer_IN_STOPPING) {
          GCU_timer_DW.is_AAC = GCU_timer_IN_STOPPING;

          /* Outputs for Function Call SubSystem: '<S2>/UnsetRPMLimiter' */
          GCU_timer_UnsetCut(rty_rpmLimiter_Pin, &GCU_timer_DW.UnsetRPMLimiter_p);

          /* End of Outputs for SubSystem: '<S2>/UnsetRPMLimiter' */
        }
      } else {
        GCU_timer_aacCheckShift(rtu_currentGear, rtu_aac_externValues,
          rty_clutchCurrVal, rty_upCut_Pin, rty_PinIn1, rty_PinIn2, rty_PinH);
      }
      break;

     case GCU_timer_IN_START:
      if (GCU_timer_DW.aacCounter <= 1) {
        GCU_timer_DW.is_ACTIVE = GCU_timer_IN_NO_ACTIVE_CHILD;
        if (GCU_timer_DW.is_ACTIVE != GCU_timer_IN_READY) {
          GCU_timer_DW.is_ACTIVE = GCU_timer_IN_READY;
          GCU_timer_DW.aacCounter = GCU_timer_AAC_WORK_RATE_ms;
          GCU_timer_Clutch_setValue(100, rty_clutchCurrVal);
          GCU_timer_checkShift(rtu_currentGear, rtu_shiftCom, rty_clutchCurrVal,
                               rty_upCut_Pin, rty_PinIn1, rty_PinIn2, rty_PinH);
        }
      } else {
        qY = GCU_timer_DW.aacCounter - /*MW:OvSatOk*/ 1U;
        if (qY > GCU_timer_DW.aacCounter) {
          qY = 0U;
        }

        GCU_timer_DW.aacCounter = (uint16_T)qY;
      }
      break;

     case GCU_timer_IN_START_RELEASE:
      if (GCU_timer_DW.aacCounter <= 1) {
        GCU_timer_DW.is_ACTIVE = GCU_timer_IN_NO_ACTIVE_CHILD;
        if (GCU_timer_DW.is_ACTIVE != GCU_timer_IN_RELEASING) {
          GCU_timer_DW.is_ACTIVE = GCU_timer_IN_RELEASING;
          GCU_timer_DW.aac_clutchValue -= GCU_timer_DW.aac_clutchStep;
          tmp_0 = rt_roundd(GCU_timer_DW.aac_clutchValue);
          if (tmp_0 < 256.0) {
            if (tmp_0 >= 0.0) {
              tmp_1 = (uint8_T)tmp_0;
            } else {
              tmp_1 = 0U;
            }
          } else {
            tmp_1 = MAX_uint8_T;
          }

          GCU_timer_Clutch_setValue(tmp_1, rty_clutchCurrVal);
          if (GCU_timer_DW.aac_dtRelease < -2147483647) {
            GCU_timer_DW.aac_dtRelease = MIN_int32_T;
          } else {
            GCU_timer_DW.aac_dtRelease--;
          }

          GCU_timer_DW.aacCounter = GCU_timer_AAC_WORK_RATE_ms;
        }
      } else {
        qY = GCU_timer_DW.aacCounter - /*MW:OvSatOk*/ 1U;
        if (qY > GCU_timer_DW.aacCounter) {
          qY = 0U;
        }

        GCU_timer_DW.aacCounter = (uint16_T)qY;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/GCULogic' */
}

/* Function for Chart: '<Root>/GCULogic' */
static void GCU_timer_checkClutch(const uint8_T rtu_clutchCom[2], uint8_T
  *rty_clutchCurrVal)
{
  /* Chart: '<Root>/GCULogic' */
  if ((rtu_clutchCom[0] != GCU_timer_DW.lastClutchCom) &&
      (((!(GCU_timer_DW.is_GEARSHIFT == GCU_timer_IN_DOWNSHIFTING)) &&
        (!(GCU_timer_DW.is_NEUTRAL_STATE == GCU_timer_IN_SET_NEUTRAL))) ||
       (GCU_timer_DW.is_NEUTRAL_STATE == GCU_timer_IN_UNSET_NEUTRAL))) {
    GCU_timer_DW.lastClutchCom = rtu_clutchCom[0];
    GCU_timer_Clutch_setValue(rtu_clutchCom[1], rty_clutchCurrVal);
  }

  /* End of Chart: '<Root>/GCULogic' */
}

/* System initialize for referenced model: 'GCU_timer' */
void GCU_timer_Init(void)
{
  /* SystemInitialize for Chart: '<Root>/GCULogic' */
  GCU_timer_DW.sfEvent = GCU_timer_CALL_EVENT;
  GCU_timer_DW.aac_parameters[0] = 50;
  GCU_timer_DW.aac_parameters[1] = 0;
  GCU_timer_DW.aac_parameters[2] = 250;
  GCU_timer_DW.aac_parameters[3] = 11000;
  GCU_timer_DW.aac_parameters[4] = 11000;
  GCU_timer_DW.aac_parameters[5] = 11000;
  GCU_timer_DW.aac_parameters[6] = 11000;
  GCU_timer_DW.aac_parameters[7] = 46;
  GCU_timer_DW.aac_parameters[8] = 61;
  GCU_timer_DW.aac_parameters[9] = 77;
  GCU_timer_DW.aac_parameters[10] = 113;
}

/* Output and update for referenced model: 'GCU_timer' */
void GCU_timer(const uint8_T *rtu_currentGear, const uint16_T
               rtu_aac_externValues[3], const uint16_T rtu_shiftCom[2], const
               uint8_T *rtu_startEngCom, const uint16_T rtu_aacCom[2], const
               uint8_T rtu_clutchCom[2], uint32_T *rty_Alive, uint8_T
               *rty_clutchCurrVal, uint8_T *rty_upCut_Pin, uint8_T
               *rty_rpmLimiter_Pin, uint8_T *rty_PinIn1, uint8_T *rty_PinIn2,
               uint8_T *rty_PinH, uint8_T *rty_engineStarter_pin)
{
  RT_MODEL_GCU_timer_T *const GCU_timer_M = &(GCU_timer_MdlrefDW.rtm);
  uint32_T qY;
  GCU_timer_rtu_currentGear = rtu_currentGear;
  GCU_timer_rtu_aac_externValues = rtu_aac_externValues;
  GCU_timer_rtu_shiftCom = rtu_shiftCom;
  GCU_timer_rtu_aacCom = rtu_aacCom;
  GCU_timer_rtu_clutchCom = rtu_clutchCom;
  GCU_timer_rty_clutchCurrVal = rty_clutchCurrVal;
  GCU_timer_rty_upCut_Pin = rty_upCut_Pin;
  GCU_timer_rty_rpmLimiter_Pin = rty_rpmLimiter_Pin;
  GCU_timer_rty_PinIn1 = rty_PinIn1;
  GCU_timer_rty_PinIn2 = rty_PinIn2;
  GCU_timer_rty_PinH = rty_PinH;
  if (rtmIsMajorTimeStep(GCU_timer_M)) {
    /* Chart: '<Root>/GCULogic' */
    GCU_timer_DW.sfEvent = GCU_timer_CALL_EVENT;
    if (GCU_timer_DW.is_active_c3_GCU_timer == 0U) {
      GCU_timer_DW.is_active_c3_GCU_timer = 1U;
      GCU_timer_DW.is_active_MODES = 1U;
      GCU_timer_DW.lastAacCom = 0U;
      GCU_timer_DW.lastShiftCom = 0U;
      GCU_timer_DW.lastClutchCom = 0U;
      GCU_timer_DW.is_MODES = GCU_timer_IN_INIT;
      GCU_timer_DW.is_active_NEUTRAL_STATE = 1U;
      GCU_timer_DW.is_NEUTRAL_STATE = GCU_timer_IN_NEUTRAL;
      if (GCU_timer_DW.is_active_GEARSHIFT != 1U) {
        GCU_timer_DW.is_active_GEARSHIFT = 1U;
      }

      if (GCU_timer_DW.is_GEARSHIFT != GCU_timer_IN_INIT_f) {
        GCU_timer_DW.is_GEARSHIFT = GCU_timer_IN_INIT_f;
        GCU_timer_DW.ticksCounter = 0;
      }

      GCU_timer_DW.is_active_START_ENGINE = 1U;
      GCU_timer_DW.lastCom = 0U;
      GCU_timer_DW.is_START_ENGINE = GCU_timer_IN_WAIT;
    } else {
      if (GCU_timer_DW.is_active_MODES != 0U) {
        switch (GCU_timer_DW.is_MODES) {
         case GCU_timer_IN_AAC:
          switch (GCU_timer_DW.is_AAC) {
           case GCU_timer_IN_ACTIVE:
            GCU_timer_ACTIVE(rtu_currentGear, rtu_aac_externValues, rtu_shiftCom,
                             rtu_aacCom, rty_clutchCurrVal, rty_upCut_Pin,
                             rty_rpmLimiter_Pin, rty_PinIn1, rty_PinIn2,
                             rty_PinH);
            break;

           case GCU_timer_IN_STOPPING:
            GCU_timer_DW.is_AAC = GCU_timer_IN_NO_ACTIVE_CHILD;
            GCU_timer_DW.is_MODES = GCU_timer_IN_NO_ACTIVE_CHILD;
            if (GCU_timer_DW.is_MODES != GCU_timer_IN_NORMAL) {
              GCU_timer_DW.is_MODES = GCU_timer_IN_NORMAL;
              qY = *rty_Alive + /*MW:OvSatOk*/ 1U;
              if (qY < *rty_Alive) {
                qY = MAX_uint32_T;
              }

              *rty_Alive = qY;
              GCU_timer_checkShift(rtu_currentGear, rtu_shiftCom,
                                   rty_clutchCurrVal, rty_upCut_Pin, rty_PinIn1,
                                   rty_PinIn2, rty_PinH);
              GCU_timer_checkClutch(rtu_clutchCom, rty_clutchCurrVal);
            }
            break;
          }
          break;

         case GCU_timer_IN_INIT:
          GCU_timer_DW.is_MODES = GCU_timer_IN_NO_ACTIVE_CHILD;
          if (GCU_timer_DW.is_MODES != GCU_timer_IN_NORMAL) {
            GCU_timer_DW.is_MODES = GCU_timer_IN_NORMAL;
            qY = *rty_Alive + /*MW:OvSatOk*/ 1U;
            if (qY < *rty_Alive) {
              qY = MAX_uint32_T;
            }

            *rty_Alive = qY;
            GCU_timer_checkShift(rtu_currentGear, rtu_shiftCom,
                                 rty_clutchCurrVal, rty_upCut_Pin, rty_PinIn1,
                                 rty_PinIn2, rty_PinH);
            GCU_timer_checkClutch(rtu_clutchCom, rty_clutchCurrVal);
          }
          break;

         case GCU_timer_IN_NORMAL:
          if ((rtu_aacCom[0] != GCU_timer_DW.lastAacCom) && (rtu_aacCom[1] ==
               GCU_timer_START_AAC_COM)) {
            GCU_timer_DW.lastAacCom = rtu_aacCom[0];
            GCU_timer_DW.is_MODES = GCU_timer_IN_AAC;
            GCU_timer_DW.aac_parameters[0] = 50;
            GCU_timer_DW.aac_parameters[1] = 0;
            GCU_timer_DW.aac_parameters[2] = 250;
            GCU_timer_DW.aac_parameters[3] = 11000;
            GCU_timer_DW.aac_parameters[4] = 11000;
            GCU_timer_DW.aac_parameters[5] = 11000;
            GCU_timer_DW.aac_parameters[6] = 11000;
            GCU_timer_DW.aac_parameters[7] = 46;
            GCU_timer_DW.aac_parameters[8] = 61;
            GCU_timer_DW.aac_parameters[9] = 77;
            GCU_timer_DW.aac_parameters[10] = 113;
            GCU_timer_DW.aac_clutchValue = 0.0;
            GCU_timer_DW.is_AAC = GCU_timer_IN_ACTIVE;
            if (GCU_timer_DW.is_ACTIVE != GCU_timer_IN_START) {
              GCU_timer_DW.is_ACTIVE = GCU_timer_IN_START;
              GCU_timer_DW.aacCounter = GCU_timer_AAC_WORK_RATE_ms;

              /* Outputs for Function Call SubSystem: '<S2>/SetRPMLimiter' */
              GCU_timer_SetCut(rty_rpmLimiter_Pin, &GCU_timer_DW.SetRPMLimiter_o);

              /* End of Outputs for SubSystem: '<S2>/SetRPMLimiter' */
              GCU_timer_Clutch_setValue(100, rty_clutchCurrVal);
            }
          } else {
            qY = *rty_Alive + /*MW:OvSatOk*/ 1U;
            if (qY < *rty_Alive) {
              qY = MAX_uint32_T;
            }

            *rty_Alive = qY;
            GCU_timer_checkShift(rtu_currentGear, rtu_shiftCom,
                                 rty_clutchCurrVal, rty_upCut_Pin, rty_PinIn1,
                                 rty_PinIn2, rty_PinH);
            GCU_timer_checkClutch(rtu_clutchCom, rty_clutchCurrVal);
          }
          break;
        }
      }

      if (GCU_timer_DW.is_active_NEUTRAL_STATE != 0U) {
        GCU_timer_NEUTRAL_STATE();
      }

      if (GCU_timer_DW.is_active_GEARSHIFT != 0U) {
        GCU_timer_GEARSHIFT(rtu_currentGear, rty_clutchCurrVal, rty_upCut_Pin,
                            rty_PinIn1, rty_PinIn2, rty_PinH);
      }

      if (GCU_timer_DW.is_active_START_ENGINE != 0U) {
        switch (GCU_timer_DW.is_START_ENGINE) {
         case GCU_timer_IN_START_b:
          if (GCU_timer_DW.startCounter == 0) {
            GCU_timer_DW.is_START_ENGINE = GCU_timer_IN_NO_ACTIVE_CHILD;
            if (GCU_timer_DW.is_START_ENGINE != GCU_timer_IN_STOP) {
              GCU_timer_DW.is_START_ENGINE = GCU_timer_IN_STOP;

              /* Outputs for Function Call SubSystem: '<S3>/EngineControl_Stop' */
              /* S-Function (EngineControl_stop): '<S17>/EngineControl Stop' */
              EngineControl_stop_Outputs_wrapper(&GCU_timer_DW.EngineControlStop);

              /* SignalConversion: '<S17>/OutportBufferForengine_starter' */
              *rty_engineStarter_pin = GCU_timer_DW.EngineControlStop;

              /* End of Outputs for SubSystem: '<S3>/EngineControl_Stop' */
            }
          } else {
            qY = GCU_timer_DW.startCounter - /*MW:OvSatOk*/ 1U;
            if (qY > GCU_timer_DW.startCounter) {
              qY = 0U;
            }

            GCU_timer_DW.startCounter = (uint8_T)qY;
          }
          break;

         case GCU_timer_IN_STOP:
          if (*rtu_startEngCom != GCU_timer_DW.lastCom) {
            GCU_timer_DW.is_START_ENGINE = GCU_timer_IN_NO_ACTIVE_CHILD;
            if (GCU_timer_DW.is_START_ENGINE != GCU_timer_IN_START_b) {
              GCU_timer_DW.is_START_ENGINE = GCU_timer_IN_START_b;

              /* Outputs for Function Call SubSystem: '<S3>/EngineControl_Start' */
              GCU_timer_EngineControl_Start(rty_engineStarter_pin,
                &GCU_timer_DW.EngineControl_Start);

              /* End of Outputs for SubSystem: '<S3>/EngineControl_Start' */
              GCU_timer_DW.lastCom = *rtu_startEngCom;
              GCU_timer_DW.startCounter = 100U;
            }
          }
          break;

         case GCU_timer_IN_WAIT:
          if (*rtu_startEngCom != GCU_timer_DW.lastCom) {
            GCU_timer_DW.is_START_ENGINE = GCU_timer_IN_NO_ACTIVE_CHILD;
            if (GCU_timer_DW.is_START_ENGINE != GCU_timer_IN_START_b) {
              GCU_timer_DW.is_START_ENGINE = GCU_timer_IN_START_b;

              /* Outputs for Function Call SubSystem: '<S3>/EngineControl_Start' */
              GCU_timer_EngineControl_Start(rty_engineStarter_pin,
                &GCU_timer_DW.EngineControl_Start);

              /* End of Outputs for SubSystem: '<S3>/EngineControl_Start' */
              GCU_timer_DW.lastCom = *rtu_startEngCom;
              GCU_timer_DW.startCounter = 100U;
            }
          }
          break;
        }
      }
    }

    /* End of Chart: '<Root>/GCULogic' */
  }
}

/* Model initialize function */
void GCU_timer_initialize(const char_T **rt_errorStatus, RTWSolverInfo
  *rt_solverInfo)
{
  RT_MODEL_GCU_timer_T *const GCU_timer_M = &(GCU_timer_MdlrefDW.rtm);

  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(GCU_timer_M, rt_errorStatus);

  /* initialize RTWSolverInfo */
  GCU_timer_M->solverInfo = (rt_solverInfo);

  /* Set the Timing fields to the appropriate data in the RTWSolverInfo */
  rtmSetSimTimeStepPointer(GCU_timer_M, rtsiGetSimTimeStepPtr
    (GCU_timer_M->solverInfo));
  GCU_timer_M->Timing.stepSize0 = (rtsiGetStepSize(GCU_timer_M->solverInfo));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
