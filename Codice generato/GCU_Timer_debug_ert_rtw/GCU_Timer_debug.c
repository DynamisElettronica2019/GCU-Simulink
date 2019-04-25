/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GCU_Timer_debug.c
 *
 * Code generated for Simulink model 'GCU_Timer_debug'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Mon Apr  1 11:11:56 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "GCU_Timer_debug.h"

/* Named constants for Chart: '<Root>/GCULogic' */
#define AAC_WORK_RATE_ms               ((uint16_T)25U)
#define ACC_CODE                       ((uint16_T)1U)
#define ACC_MODE                       ((uint16_T)3U)
#define AUTOCROSS_MODE                 ((uint16_T)0U)
#define CALL_EVENT                     (-1)
#define ENDURANCE_MODE                 ((uint16_T)2U)
#define GEAR_COMMAND_DOWN              ((uint16_T)200U)
#define GEAR_COMMAND_NEUTRAL_DOWN      ((uint16_T)100U)
#define GEAR_COMMAND_NEUTRAL_UP        ((uint16_T)50U)
#define GEAR_COMMAND_UP                ((uint16_T)400U)
#define IN_AAC                         ((uint8_T)1U)
#define IN_ACCELERATION                ((uint8_T)1U)
#define IN_ACTIVE                      ((uint8_T)1U)
#define IN_ChangeClutch                ((uint8_T)1U)
#define IN_CutOff                      ((uint8_T)1U)
#define IN_DOWNSHIFTING                ((uint8_T)1U)
#define IN_DOWN_BRAKE                  ((uint8_T)1U)
#define IN_DOWN_END                    ((uint8_T)2U)
#define IN_DOWN_PUSH                   ((uint8_T)2U)
#define IN_DOWN_REBOUND                ((uint8_T)3U)
#define IN_DOWN_START                  ((uint8_T)4U)
#define IN_Default                     ((uint8_T)1U)
#define IN_Default_m                   ((uint8_T)2U)
#define IN_IDLE                        ((uint8_T)3U)
#define IN_INIT                        ((uint8_T)2U)
#define IN_INIT_f                      ((uint8_T)4U)
#define IN_MANUAL_MODES                ((uint8_T)3U)
#define IN_NEUTRAL                     ((uint8_T)1U)
#define IN_NO_ACTIVE_CHILD             ((uint8_T)0U)
#define IN_NO_NEUTRAL                  ((uint8_T)2U)
#define IN_NotReady                    ((uint8_T)2U)
#define IN_READY                       ((uint8_T)1U)
#define IN_RELEASING                   ((uint8_T)2U)
#define IN_RUNNING                     ((uint8_T)3U)
#define IN_SET_NEUTRAL                 ((uint8_T)3U)
#define IN_START                       ((uint8_T)4U)
#define IN_START_RELEASE               ((uint8_T)5U)
#define IN_START_o                     ((uint8_T)1U)
#define IN_STOP                        ((uint8_T)2U)
#define IN_STOPPING                    ((uint8_T)2U)
#define IN_SettingNeutral              ((uint8_T)2U)
#define IN_SettingNeutral_k            ((uint8_T)3U)
#define IN_UNSET_NEUTRAL               ((uint8_T)4U)
#define IN_UPSHIFTING                  ((uint8_T)5U)
#define IN_UP_BRAKE                    ((uint8_T)1U)
#define IN_UP_END                      ((uint8_T)6U)
#define IN_UP_PUSH                     ((uint8_T)2U)
#define IN_UP_REBOUND                  ((uint8_T)3U)
#define IN_UP_START                    ((uint8_T)4U)
#define IN_WAIT                        ((uint8_T)3U)
#define RELEASE_AAC_COM                ((uint16_T)2U)
#define SKIDPAD_MODE                   ((uint16_T)1U)
#define START_AAC_COM                  ((uint16_T)1U)
#define STOP_AAC_COM                   ((uint16_T)0U)
#define event_GearshiftDown            (0)
#define event_GearshiftSetNeutral      (1)
#define event_GearshiftUp              (2)

const uint16_T GCU_Timer_debug_U16GND = 0U;/* uint16_T ground */

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

#ifdef __cplusplus

extern "C" {

#endif

  extern void PackUARTMsg_Start_wrapper(void);
  extern void PackUARTMsg_Outputs_wrapper(const uint16_T *dataArray,
    uint8_T *msgArray);
  extern void PackUARTMsg_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void sendUART_Start_wrapper(void);
  extern void sendUART_Outputs_wrapper(const uint8_T *msg);
  extern void sendUART_Terminate_wrapper(void);

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
static void checkClutch(void);
static void enter_atomic_MANUAL_MODES(void);
static void ACCELERATION(void);
static void MODES(void);

/*
 * Output and update for function-call system:
 *    '<S3>/SetCut'
 *    '<S3>/SetRPMLimiter'
 */
static void SetCut(uint8_T *rty_downCut_pin, DW_SetCut *localDW)
{
  /* S-Function (Efi_setBlip): '<S10>/Efi SetBlip' */
  Efi_setBlip_Outputs_wrapper(&localDW->EfiSetBlip);

  /* SignalConversion: '<S10>/OutportBufferFordownCut_pin' */
  *rty_downCut_pin = localDW->EfiSetBlip;
}

/*
 * Output and update for function-call system:
 *    '<S3>/UnsetCut'
 *    '<S3>/UnsetRPMLimiter'
 */
static void UnsetCut(uint8_T *rty_downCut_pin, DW_UnsetCut *localDW)
{
  /* S-Function (Efi_unsetBlip): '<S12>/Efi UnSetBlip' */
  Efi_unsetBlip_Outputs_wrapper(&localDW->EfiUnSetBlip);

  /* SignalConversion: '<S12>/OutportBufferFordownCut_pin' */
  *rty_downCut_pin = localDW->EfiUnSetBlip;
}

/* Output and update for function-call system: '<S6>/Gearmotor_release' */
static void Gearmotor_release(void)
{
  /* S-Function (GearMotor_release): '<S18>/GearMotor Release' */
  GearMotor_release_Outputs_wrapper(&rtDW.GearMotorRelease);

  /* SignalConversion: '<S18>/OutportBufferForPin H' */
  rtDW.Pin_H = rtDW.GearMotorRelease;
}

/* Output and update for function-call system: '<S6>/Gearmotor_turnRight' */
static void Gearmotor_turnRight(uint8_T *rty_Pin_In1, uint8_T *rty_Pin_In2,
  uint8_T *rty_Pin_H, DW_Gearmotor_turnRight *localDW)
{
  /* S-Function (GearMotor_turnRight): '<S20>/GearMotor Turn Right' */
  GearMotor_turnRight_Outputs_wrapper(&localDW->GearMotorTurnRight_o1,
    &localDW->GearMotorTurnRight_o2, &localDW->GearMotorTurnRight_o3);

  /* SignalConversion: '<S20>/OutportBufferForPin_H' */
  *rty_Pin_H = localDW->GearMotorTurnRight_o3;

  /* SignalConversion: '<S20>/OutportBufferForPin_In1' */
  *rty_Pin_In1 = localDW->GearMotorTurnRight_o1;

  /* SignalConversion: '<S20>/OutportBufferForPin_In2' */
  *rty_Pin_In2 = localDW->GearMotorTurnRight_o2;
}

/* Output and update for function-call system: '<S6>/Gearmotor_brake' */
static void Gearmotor_brake(uint8_T *rty_Pin_In1, uint8_T *rty_Pin_In2, uint8_T *
  rty_Pin_H, DW_Gearmotor_brake *localDW)
{
  /* S-Function (GearMotor_brake): '<S17>/GearMotor Brake' */
  GearMotor_brake_Outputs_wrapper(&localDW->GearMotorBrake_o1,
    &localDW->GearMotorBrake_o2, &localDW->GearMotorBrake_o3);

  /* SignalConversion: '<S17>/OutportBufferForPin_H' */
  *rty_Pin_H = localDW->GearMotorBrake_o3;

  /* SignalConversion: '<S17>/OutportBufferForPin_In1' */
  *rty_Pin_In1 = localDW->GearMotorBrake_o1;

  /* SignalConversion: '<S17>/OutportBufferForPin_In2' */
  *rty_Pin_In2 = localDW->GearMotorBrake_o2;
}

/* Output and update for function-call system: '<S4>/EngineControl_Start' */
static void EngineControl_Start(uint8_T *rty_engine_starter,
  DW_EngineControl_Start *localDW)
{
  /* S-Function (EngineControl_start): '<S14>/EngineControl Start' */
  EngineControl_start_Outputs_wrapper(&localDW->EngineControlStart);

  /* SignalConversion: '<S14>/OutportBufferForengine_starter' */
  *rty_engine_starter = localDW->EngineControlStart;
}

/* Output and update for function-call system: '<S5>/sendUpdatesSW' */
static void sendUpdatesSW(uint16_T rtu_valCode, uint16_T rtu_value,
  DW_sendUpdatesSW *localDW)
{
  /* S-Function (PackCanUART): '<S16>/PackCanUart' incorporates:
   *  Constant: '<S16>/GCU_FEEDBACK_ID'
   */
  PackCanUART_Outputs_wrapper(&rtConstP.GCU_FEEDBACK_ID_Value, &rtu_valCode,
    &rtu_value, (uint16_T*)&GCU_Timer_debug_U16GND, (uint16_T*)
    &GCU_Timer_debug_U16GND, &localDW->PackCanUart[0]);
}

/* Function for Chart: '<Root>/GCULogic' */
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

/* Function for Chart: '<Root>/GCULogic' */
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
      /* Inport: '<Root>/currentGear' */
      switch (rtU.currentGear) {
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

      /* End of Inport: '<Root>/currentGear' */
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

/* Function for Chart: '<Root>/GCULogic' */
static void Clutch_setValue(uint8_T setValue)
{
  rtDW.clutchCurrVal = setValue;

  /* Outputs for Function Call SubSystem: '<S1>/ClutchMotor SetPosition ' */
  /* Sum: '<S8>/Minus' incorporates:
   *  Constant: '<S8>/Constant'
   */
  rtDW.Minus = (uint8_T)(100 - rtDW.clutchCurrVal);

  /* S-Function (ClutchMotor_setPosition): '<S8>/ClutchMotor SetPosition' */
  ClutchMotor_setPosition_Outputs_wrapper(&rtDW.Minus);

  /* End of Outputs for SubSystem: '<S1>/ClutchMotor SetPosition ' */
}

/* Function for Chart: '<Root>/GCULogic' */
static void GEARSHIFT(void)
{
  switch (rtDW.is_GEARSHIFT) {
   case IN_DOWNSHIFTING:
    switch (rtDW.is_DOWNSHIFTING) {
     case IN_DOWN_BRAKE:
      if (rtDW.ticksCounter == 0) {
        rtDW.is_DOWN_BRAKE = IN_NO_ACTIVE_CHILD;
        rtDW.is_DOWNSHIFTING = IN_NO_ACTIVE_CHILD;
        rtDW.is_GEARSHIFT = IN_NO_ACTIVE_CHILD;
        if (rtDW.is_GEARSHIFT != IN_DOWN_END) {
          rtDW.is_GEARSHIFT = IN_DOWN_END;

          /* Outputs for Function Call SubSystem: '<S6>/Gearmotor_release' */
          Gearmotor_release();

          /* End of Outputs for SubSystem: '<S6>/Gearmotor_release' */
        }
      } else if (rtDW.ticksCounter < -2147483647) {
        rtDW.ticksCounter = MIN_int32_T;
      } else {
        rtDW.ticksCounter--;
      }
      break;

     case IN_DOWN_PUSH:
      if (rtDW.ticksCounter == 0) {
        rtDW.is_DOWNSHIFTING = IN_NO_ACTIVE_CHILD;
        if (rtDW.is_DOWNSHIFTING != IN_DOWN_REBOUND) {
          rtDW.is_DOWNSHIFTING = IN_DOWN_REBOUND;
          rtDW.ticksCounter = Gearshift_getTime();

          /* Outputs for Function Call SubSystem: '<S6>/Gearmotor_release' */
          Gearmotor_release();

          /* End of Outputs for SubSystem: '<S6>/Gearmotor_release' */
        }
      } else if (rtDW.ticksCounter < -2147483647) {
        rtDW.ticksCounter = MIN_int32_T;
      } else {
        rtDW.ticksCounter--;
      }
      break;

     case IN_DOWN_REBOUND:
      if (rtDW.ticksCounter == 0) {
        rtDW.is_DOWNSHIFTING = IN_NO_ACTIVE_CHILD;
        if (rtDW.is_DOWNSHIFTING != IN_DOWN_BRAKE) {
          rtDW.is_DOWNSHIFTING = IN_DOWN_BRAKE;
          rtDW.ticksCounter = Gearshift_getTime();
        }

        if (rtDW.clutchCurrVal < 81) {
          if (rtDW.is_DOWN_BRAKE != IN_ChangeClutch) {
            rtDW.is_DOWN_BRAKE = IN_ChangeClutch;
            Clutch_setValue(80);

            /* Outputs for Function Call SubSystem: '<S6>/Gearmotor_brake' */
            Gearmotor_brake(&rtDW.Pin_In1, &rtDW.Pin_In2, &rtDW.Pin_H,
                            &rtDW.Gearmotor_brake_e);

            /* End of Outputs for SubSystem: '<S6>/Gearmotor_brake' */
          }
        } else {
          if (rtDW.is_DOWN_BRAKE != IN_Default_m) {
            rtDW.is_DOWN_BRAKE = IN_Default_m;

            /* Outputs for Function Call SubSystem: '<S6>/Gearmotor_brake' */
            Gearmotor_brake(&rtDW.Pin_In1, &rtDW.Pin_In2, &rtDW.Pin_H,
                            &rtDW.Gearmotor_brake_e);

            /* End of Outputs for SubSystem: '<S6>/Gearmotor_brake' */
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
        rtDW.is_DOWN_START = IN_NO_ACTIVE_CHILD;
        rtDW.is_DOWNSHIFTING = IN_NO_ACTIVE_CHILD;
        if (rtDW.is_DOWNSHIFTING != IN_DOWN_PUSH) {
          rtDW.is_DOWNSHIFTING = IN_DOWN_PUSH;
          rtDW.ticksCounter = Gearshift_getTime();

          /* Outputs for Function Call SubSystem: '<S6>/Gearmotor_turnLeft' */
          /* S-Function (GearMotor_turnLeft): '<S19>/GearMotor Turn Left' */
          GearMotor_turnLeft_Outputs_wrapper(&rtDW.GearMotorTurnLeft_o1,
            &rtDW.GearMotorTurnLeft_o2, &rtDW.GearMotorTurnLeft_o3);

          /* SignalConversion: '<S19>/OutportBufferForPin_H' */
          rtDW.Pin_H = rtDW.GearMotorTurnLeft_o3;

          /* SignalConversion: '<S19>/OutportBufferForPin_In1' */
          rtDW.Pin_In1 = rtDW.GearMotorTurnLeft_o1;

          /* SignalConversion: '<S19>/OutportBufferForPin_In2' */
          rtDW.Pin_In2 = rtDW.GearMotorTurnLeft_o2;

          /* End of Outputs for SubSystem: '<S6>/Gearmotor_turnLeft' */
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
    rtDW.is_GEARSHIFT = IN_IDLE;
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

          /* Outputs for Function Call SubSystem: '<S3>/SetCut' */
          SetCut(&rtDW.Merge1, &rtDW.SetCut_b);

          /* End of Outputs for SubSystem: '<S3>/SetCut' */
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
        if (rtDW.is_DOWN_START != IN_SettingNeutral_k) {
          rtDW.is_DOWN_START = IN_SettingNeutral_k;
          Clutch_setValue(80);
        }
      } else if ((!(rtDW.is_NEUTRAL_STATE == IN_UNSET_NEUTRAL)) &&
                 (rtDW.clutchCurrVal <= 60)) {
        if (rtDW.is_DOWN_START != IN_ChangeClutch) {
          rtDW.is_DOWN_START = IN_ChangeClutch;
          Clutch_setValue(60);
        }
      } else {
        rtDW.is_DOWN_START = IN_Default_m;
      }
      break;
    }
    break;

   case IN_INIT_f:
    rtDW.is_GEARSHIFT = IN_IDLE;
    break;

   case IN_UPSHIFTING:
    switch (rtDW.is_UPSHIFTING) {
     case IN_UP_BRAKE:
      if (rtDW.ticksCounter == 0) {
        rtDW.is_UPSHIFTING = IN_NO_ACTIVE_CHILD;
        rtDW.is_GEARSHIFT = IN_NO_ACTIVE_CHILD;
        if (rtDW.is_GEARSHIFT != IN_UP_END) {
          rtDW.is_GEARSHIFT = IN_UP_END;

          /* Outputs for Function Call SubSystem: '<S6>/Gearmotor_release' */
          Gearmotor_release();

          /* End of Outputs for SubSystem: '<S6>/Gearmotor_release' */
        }
      } else if (rtDW.ticksCounter < -2147483647) {
        rtDW.ticksCounter = MIN_int32_T;
      } else {
        rtDW.ticksCounter--;
      }
      break;

     case IN_UP_PUSH:
      if (rtDW.ticksCounter == 0) {
        rtDW.is_UP_PUSH = IN_NO_ACTIVE_CHILD;
        rtDW.is_UPSHIFTING = IN_NO_ACTIVE_CHILD;
        if (rtDW.is_UPSHIFTING != IN_UP_REBOUND) {
          rtDW.is_UPSHIFTING = IN_UP_REBOUND;
          rtDW.ticksCounter = Gearshift_getTime();
        }

        if (rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) {
          if (rtDW.is_UP_REBOUND != IN_SettingNeutral) {
            rtDW.is_UP_REBOUND = IN_SettingNeutral;
            Clutch_setValue(0);

            /* Outputs for Function Call SubSystem: '<S6>/Gearmotor_release' */
            Gearmotor_release();

            /* End of Outputs for SubSystem: '<S6>/Gearmotor_release' */
          }
        } else {
          if (rtDW.is_UP_REBOUND != IN_Default) {
            rtDW.is_UP_REBOUND = IN_Default;

            /* Outputs for Function Call SubSystem: '<S6>/Gearmotor_release' */
            Gearmotor_release();

            /* End of Outputs for SubSystem: '<S6>/Gearmotor_release' */
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
        rtDW.is_UP_REBOUND = IN_NO_ACTIVE_CHILD;
        rtDW.is_UPSHIFTING = IN_NO_ACTIVE_CHILD;
        if (rtDW.is_UPSHIFTING != IN_UP_BRAKE) {
          rtDW.is_UPSHIFTING = IN_UP_BRAKE;
          rtDW.ticksCounter = Gearshift_getTime();

          /* Outputs for Function Call SubSystem: '<S6>/Gearmotor_brake' */
          Gearmotor_brake(&rtDW.Pin_In1, &rtDW.Pin_In2, &rtDW.Pin_H,
                          &rtDW.Gearmotor_brake_e);

          /* End of Outputs for SubSystem: '<S6>/Gearmotor_brake' */
        }
      } else if (rtDW.ticksCounter < -2147483647) {
        rtDW.ticksCounter = MIN_int32_T;
      } else {
        rtDW.ticksCounter--;
      }
      break;

     case IN_UP_START:
      if (rtDW.ticksCounter == 0) {
        rtDW.is_UP_START = IN_NO_ACTIVE_CHILD;
        rtDW.is_UPSHIFTING = IN_NO_ACTIVE_CHILD;
        if (rtDW.is_UPSHIFTING != IN_UP_PUSH) {
          rtDW.is_UPSHIFTING = IN_UP_PUSH;
          rtDW.ticksCounter = Gearshift_getTime();
        }

        if (!(rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL)) {
          if (rtDW.is_UP_PUSH != IN_CutOff) {
            rtDW.is_UP_PUSH = IN_CutOff;

            /* Outputs for Function Call SubSystem: '<S3>/UnsetCut' */
            UnsetCut(&rtDW.Merge1, &rtDW.UnsetCut_g);

            /* End of Outputs for SubSystem: '<S3>/UnsetCut' */

            /* Outputs for Function Call SubSystem: '<S6>/Gearmotor_turnRight' */
            Gearmotor_turnRight(&rtDW.Pin_In1, &rtDW.Pin_In2, &rtDW.Pin_H,
                                &rtDW.Gearmotor_turnRight_o);

            /* End of Outputs for SubSystem: '<S6>/Gearmotor_turnRight' */
          }
        } else {
          if (rtDW.is_UP_PUSH != IN_Default_m) {
            rtDW.is_UP_PUSH = IN_Default_m;

            /* Outputs for Function Call SubSystem: '<S6>/Gearmotor_turnRight' */
            Gearmotor_turnRight(&rtDW.Pin_In1, &rtDW.Pin_In2, &rtDW.Pin_H,
                                &rtDW.Gearmotor_turnRight_o);

            /* End of Outputs for SubSystem: '<S6>/Gearmotor_turnRight' */
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
    rtDW.is_GEARSHIFT = IN_IDLE;
    break;
  }
}

/* Function for Chart: '<Root>/GCULogic' */
static void checkShift(void)
{
  int32_T b_previousEvent;

  /* Inport: '<Root>/shiftCom' */
  if (rtU.shiftCom[0] != rtDW.lastShiftCom) {
    rtDW.lastShiftCom = rtU.shiftCom[0];
    if (rtU.shiftCom[1] == GEAR_COMMAND_UP) {
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
    } else if (rtU.shiftCom[1] == GEAR_COMMAND_DOWN) {
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
    } else if (rtU.shiftCom[1] == GEAR_COMMAND_NEUTRAL_UP) {
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
      if (rtU.shiftCom[1] == GEAR_COMMAND_NEUTRAL_DOWN) {
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

  /* End of Inport: '<Root>/shiftCom' */
}

/* Function for Chart: '<Root>/GCULogic' */
static int32_T getAacParam(aac_params b_index)
{
  return rtDW.aac_parameters[b_index];
}

/* Function for Chart: '<Root>/GCULogic' */
static void aacCheckShift(void)
{
  int32_T b_previousEvent;

  /* Inport: '<Root>/currentGear' incorporates:
   *  Inport: '<Root>/aac_externValues'
   */
  if ((rtDW.lastShift == rtU.currentGear) && (rtU.aac_externValues[RPM] >=
       rtDW.aac_parameters[((int32_T)RPM_LIMIT_1_2 + rtU.currentGear) - 1]) &&
      (rtU.aac_externValues[WHEEL_SPEED] >= rtDW.aac_parameters[((int32_T)
        SPEED_LIMIT_1_2 + rtU.currentGear) - 1])) {
    b_previousEvent = rtDW.sfEvent;
    rtDW.sfEvent = event_GearshiftUp;
    if (rtDW.is_active_GEARSHIFT != 0U) {
      GEARSHIFT();
    }

    rtDW.sfEvent = b_previousEvent;
    b_previousEvent = rtDW.lastShift + 1;
    if (b_previousEvent > 255) {
      b_previousEvent = 255;
    }

    rtDW.lastShift = (uint8_T)b_previousEvent;
  }

  /* End of Inport: '<Root>/currentGear' */
}

/* Function for Chart: '<Root>/GCULogic' */
static void checkClutch(void)
{
  /* Inport: '<Root>/clutchCom' */
  if ((rtU.clutchCom[0] != rtDW.lastClutchCom) && (((!(rtDW.is_GEARSHIFT ==
          IN_DOWNSHIFTING)) && (!(rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL))) ||
       (rtDW.is_NEUTRAL_STATE == IN_UNSET_NEUTRAL))) {
    rtDW.lastClutchCom = rtU.clutchCom[0];
    Clutch_setValue(rtU.clutchCom[1]);
  }

  /* End of Inport: '<Root>/clutchCom' */
}

/* Function for Chart: '<Root>/GCULogic' */
static void enter_atomic_MANUAL_MODES(void)
{
  uint32_T qY;

  /* Inport: '<Root>/modeCom' */
  rtDW.lastModeCom = rtU.modeCom[0];
  qY = rtDW.alive + /*MW:OvSatOk*/ 1U;
  if (qY < rtDW.alive) {
    qY = MAX_uint32_T;
  }

  rtDW.alive = qY;
  checkShift();
  checkClutch();
}

/* Function for Chart: '<Root>/GCULogic' */
static void ACCELERATION(void)
{
  uint32_T qY;
  int32_T q0;
  int32_T q1;
  int64_T tmp;
  uint8_T tmp_0;

  /* Inport: '<Root>/modeCom' */
  if (rtU.modeCom[0] != rtDW.lastModeCom) {
    /* Outputs for Function Call SubSystem: '<S3>/UnsetRPMLimiter' */
    UnsetCut(&rtDW.Merge2, &rtDW.UnsetRPMLimiter_k);

    /* End of Outputs for SubSystem: '<S3>/UnsetRPMLimiter' */
    if (rtU.modeCom[1] == AUTOCROSS_MODE) {
      rtDW.is_ACTIVE = IN_NO_ACTIVE_CHILD;
      rtDW.is_AAC = IN_NO_ACTIVE_CHILD;
      rtDW.is_ACCELERATION = IN_NO_ACTIVE_CHILD;
      rtDW.is_MODES = IN_NO_ACTIVE_CHILD;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        enter_atomic_MANUAL_MODES();
      }
    } else if (rtU.modeCom[1] == ENDURANCE_MODE) {
      rtDW.is_ACTIVE = IN_NO_ACTIVE_CHILD;
      rtDW.is_AAC = IN_NO_ACTIVE_CHILD;
      rtDW.is_ACCELERATION = IN_NO_ACTIVE_CHILD;
      rtDW.is_MODES = IN_NO_ACTIVE_CHILD;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        enter_atomic_MANUAL_MODES();
      }
    } else if (rtU.modeCom[1] == SKIDPAD_MODE) {
      rtDW.is_ACTIVE = IN_NO_ACTIVE_CHILD;
      rtDW.is_AAC = IN_NO_ACTIVE_CHILD;
      rtDW.is_ACCELERATION = IN_NO_ACTIVE_CHILD;
      rtDW.is_MODES = IN_NO_ACTIVE_CHILD;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        enter_atomic_MANUAL_MODES();
      }
    } else if (rtU.modeCom[1] == ACC_MODE) {
      rtDW.is_ACTIVE = IN_NO_ACTIVE_CHILD;
      rtDW.is_AAC = IN_NO_ACTIVE_CHILD;
      rtDW.is_ACCELERATION = IN_NO_ACTIVE_CHILD;
      rtDW.is_MODES = IN_NO_ACTIVE_CHILD;
      if (rtDW.is_MODES != IN_ACCELERATION) {
        rtDW.is_MODES = IN_ACCELERATION;
        rtDW.lastModeCom = rtU.modeCom[0];
      }

      if (rtDW.is_ACCELERATION != IN_NotReady) {
        rtDW.is_ACCELERATION = IN_NotReady;
        rtDW.accFb = 1U;
        checkShift();
        checkClutch();
      }
    } else {
      rtDW.is_ACTIVE = IN_NO_ACTIVE_CHILD;
      rtDW.is_AAC = IN_NO_ACTIVE_CHILD;
      rtDW.is_ACCELERATION = IN_NO_ACTIVE_CHILD;
      rtDW.is_MODES = IN_NO_ACTIVE_CHILD;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        rtDW.lastModeCom = rtU.modeCom[0];
        qY = rtDW.alive + /*MW:OvSatOk*/ 1U;
        if (qY < rtDW.alive) {
          qY = MAX_uint32_T;
        }

        rtDW.alive = qY;
        checkShift();
        checkClutch();
      }
    }
  } else {
    switch (rtDW.is_ACCELERATION) {
     case IN_AAC:
      switch (rtDW.is_AAC) {
       case IN_ACTIVE:
        /* Inport: '<Root>/aacCom' */
        if ((rtU.aacCom[0] != rtDW.lastAacCom) && (rtU.aacCom[1] == STOP_AAC_COM))
        {
          rtDW.lastAacCom = rtU.aacCom[0];
          rtDW.is_ACTIVE = IN_NO_ACTIVE_CHILD;
          rtDW.is_AAC = IN_NO_ACTIVE_CHILD;
          if (rtDW.is_AAC != IN_STOPPING) {
            rtDW.is_AAC = IN_STOPPING;

            /* Outputs for Function Call SubSystem: '<S3>/UnsetRPMLimiter' */
            UnsetCut(&rtDW.Merge2, &rtDW.UnsetRPMLimiter_k);

            /* End of Outputs for SubSystem: '<S3>/UnsetRPMLimiter' */
            rtDW.valCode = ACC_CODE;
            rtDW.value = 0U;

            /* Outputs for Function Call SubSystem: '<S5>/sendUpdatesSW' */
            sendUpdatesSW(rtDW.valCode, rtDW.value, &rtDW.sendUpdatesSW_b);

            /* End of Outputs for SubSystem: '<S5>/sendUpdatesSW' */
          }
        } else {
          switch (rtDW.is_ACTIVE) {
           case IN_READY:
            if (rtDW.aacCounter <= 1) {
              if ((rtU.aacCom[0] != rtDW.lastAacCom) && (rtU.aacCom[1] ==
                   RELEASE_AAC_COM)) {
                rtDW.lastAacCom = rtU.aacCom[0];
                rtDW.is_ACTIVE = IN_NO_ACTIVE_CHILD;
                if (rtDW.is_ACTIVE != IN_START_RELEASE) {
                  rtDW.is_ACTIVE = IN_START_RELEASE;
                  rtDW.aac_clutchValue = getAacParam(RAMP_START);
                  if (rtDW.aac_clutchValue < 256.0) {
                    if (rtDW.aac_clutchValue >= 0.0) {
                      tmp_0 = (uint8_T)rtDW.aac_clutchValue;
                    } else {
                      tmp_0 = 0U;
                    }
                  } else {
                    tmp_0 = MAX_uint8_T;
                  }

                  Clutch_setValue(tmp_0);
                  rtDW.aac_dtRelease = getAacParam(RAMP_TIME) / AAC_WORK_RATE_ms;
                  q0 = getAacParam(RAMP_START);
                  q1 = getAacParam(RAMP_END);
                  if ((q0 >= 0) && (q1 < q0 - MAX_int32_T)) {
                    q0 = MAX_int32_T;
                  } else if ((q0 < 0) && (q1 > q0 - MIN_int32_T)) {
                    q0 = MIN_int32_T;
                  } else {
                    q0 -= q1;
                  }

                  tmp = (int64_T)q0 * AAC_WORK_RATE_ms;
                  if (tmp > 2147483647LL) {
                    tmp = 2147483647LL;
                  } else {
                    if (tmp < -2147483648LL) {
                      tmp = -2147483648LL;
                    }
                  }

                  rtDW.aac_clutchStep = (real_T)(int32_T)tmp / (real_T)
                    getAacParam(RAMP_TIME);
                  rtDW.aacCounter = AAC_WORK_RATE_ms;
                  rtDW.valCode = ACC_CODE;
                  rtDW.value = 2U;

                  /* Outputs for Function Call SubSystem: '<S5>/sendUpdatesSW' */
                  sendUpdatesSW(rtDW.valCode, rtDW.value, &rtDW.sendUpdatesSW_b);

                  /* End of Outputs for SubSystem: '<S5>/sendUpdatesSW' */
                }
              } else {
                rtDW.is_ACTIVE = IN_NO_ACTIVE_CHILD;
                if (rtDW.is_ACTIVE != IN_READY) {
                  rtDW.is_ACTIVE = IN_READY;
                  rtDW.accFb = 3U;
                  rtDW.aacCounter = AAC_WORK_RATE_ms;
                  Clutch_setValue(100);
                  checkShift();
                }
              }
            } else {
              q0 = rtDW.aacCounter - 1;
              if (q0 < 0) {
                q0 = 0;
              }

              rtDW.aacCounter = (uint16_T)q0;
              checkShift();
            }
            break;

           case IN_RELEASING:
            if (rtDW.aacCounter <= 1) {
              if ((rtDW.aac_dtRelease <= 0) || (rtDW.clutchCurrVal <=
                   getAacParam(RAMP_END))) {
                Clutch_setValue(0);

                /* Outputs for Function Call SubSystem: '<S3>/UnsetRPMLimiter' */
                UnsetCut(&rtDW.Merge2, &rtDW.UnsetRPMLimiter_k);

                /* End of Outputs for SubSystem: '<S3>/UnsetRPMLimiter' */
                rtDW.is_ACTIVE = IN_NO_ACTIVE_CHILD;
                if (rtDW.is_ACTIVE != IN_RUNNING) {
                  rtDW.is_ACTIVE = IN_RUNNING;
                  rtDW.aacCounter = AAC_WORK_RATE_ms;

                  /* Inport: '<Root>/currentGear' */
                  rtDW.lastShift = rtU.currentGear;
                  aacCheckShift();
                }
              } else {
                rtDW.is_ACTIVE = IN_NO_ACTIVE_CHILD;
                if (rtDW.is_ACTIVE != IN_RELEASING) {
                  rtDW.is_ACTIVE = IN_RELEASING;
                  rtDW.aac_clutchValue -= rtDW.aac_clutchStep;
                  if (rtDW.aac_clutchValue < 256.0) {
                    if (rtDW.aac_clutchValue >= 0.0) {
                      tmp_0 = (uint8_T)rtDW.aac_clutchValue;
                    } else {
                      tmp_0 = 0U;
                    }
                  } else {
                    tmp_0 = MAX_uint8_T;
                  }

                  Clutch_setValue(tmp_0);
                  if (rtDW.aac_dtRelease < -2147483647) {
                    rtDW.aac_dtRelease = MIN_int32_T;
                  } else {
                    rtDW.aac_dtRelease--;
                  }

                  rtDW.aacCounter = AAC_WORK_RATE_ms;
                }
              }
            } else {
              q0 = rtDW.aacCounter - 1;
              if (q0 < 0) {
                q0 = 0;
              }

              rtDW.aacCounter = (uint16_T)q0;
            }
            break;

           case IN_RUNNING:
            /* Inport: '<Root>/currentGear' */
            if (rtU.currentGear == 5) {
              rtDW.is_ACTIVE = IN_NO_ACTIVE_CHILD;
              rtDW.is_AAC = IN_NO_ACTIVE_CHILD;
              if (rtDW.is_AAC != IN_STOPPING) {
                rtDW.is_AAC = IN_STOPPING;

                /* Outputs for Function Call SubSystem: '<S3>/UnsetRPMLimiter' */
                UnsetCut(&rtDW.Merge2, &rtDW.UnsetRPMLimiter_k);

                /* End of Outputs for SubSystem: '<S3>/UnsetRPMLimiter' */
                rtDW.valCode = ACC_CODE;
                rtDW.value = 0U;

                /* Outputs for Function Call SubSystem: '<S5>/sendUpdatesSW' */
                sendUpdatesSW(rtDW.valCode, rtDW.value, &rtDW.sendUpdatesSW_b);

                /* End of Outputs for SubSystem: '<S5>/sendUpdatesSW' */
              }
            } else {
              aacCheckShift();
            }
            break;

           case IN_START:
            if (rtDW.aacCounter <= 1) {
              rtDW.is_ACTIVE = IN_NO_ACTIVE_CHILD;
              if (rtDW.is_ACTIVE != IN_READY) {
                rtDW.is_ACTIVE = IN_READY;
                rtDW.accFb = 3U;
                rtDW.aacCounter = AAC_WORK_RATE_ms;
                Clutch_setValue(100);
                checkShift();
              }
            } else {
              q0 = rtDW.aacCounter - 1;
              if (q0 < 0) {
                q0 = 0;
              }

              rtDW.aacCounter = (uint16_T)q0;
            }
            break;

           case IN_START_RELEASE:
            if (rtDW.aacCounter <= 1) {
              rtDW.is_ACTIVE = IN_NO_ACTIVE_CHILD;
              if (rtDW.is_ACTIVE != IN_RELEASING) {
                rtDW.is_ACTIVE = IN_RELEASING;
                rtDW.aac_clutchValue -= rtDW.aac_clutchStep;
                if (rtDW.aac_clutchValue < 256.0) {
                  if (rtDW.aac_clutchValue >= 0.0) {
                    tmp_0 = (uint8_T)rtDW.aac_clutchValue;
                  } else {
                    tmp_0 = 0U;
                  }
                } else {
                  tmp_0 = MAX_uint8_T;
                }

                Clutch_setValue(tmp_0);
                if (rtDW.aac_dtRelease < -2147483647) {
                  rtDW.aac_dtRelease = MIN_int32_T;
                } else {
                  rtDW.aac_dtRelease--;
                }

                rtDW.aacCounter = AAC_WORK_RATE_ms;
              }
            } else {
              q0 = rtDW.aacCounter - 1;
              if (q0 < 0) {
                q0 = 0;
              }

              rtDW.aacCounter = (uint16_T)q0;
            }
            break;
          }
        }
        break;

       case IN_STOPPING:
        rtDW.is_AAC = IN_NO_ACTIVE_CHILD;
        rtDW.is_ACCELERATION = IN_NO_ACTIVE_CHILD;
        if (rtDW.is_ACCELERATION != IN_NotReady) {
          rtDW.is_ACCELERATION = IN_NotReady;
          rtDW.accFb = 1U;
          checkShift();
          checkClutch();
        }
        break;
      }
      break;

     case IN_NotReady:
      /* Inport: '<Root>/aacCom' */
      if ((rtU.aacCom[0] != rtDW.lastAacCom) && (rtU.aacCom[1] == START_AAC_COM))
      {
        rtDW.lastAacCom = rtU.aacCom[0];
        rtDW.is_ACCELERATION = IN_AAC;
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
        rtDW.aacCounter = 0U;
        rtDW.aac_clutchValue = 0.0;
        rtDW.aac_clutchStep = 0.0;
        rtDW.aac_dtRelease = 0;
        rtDW.is_AAC = IN_ACTIVE;
        if (rtDW.is_ACTIVE != IN_START) {
          rtDW.is_ACTIVE = IN_START;
          rtDW.accFb = 2U;
          rtDW.aacCounter = AAC_WORK_RATE_ms;

          /* Outputs for Function Call SubSystem: '<S3>/SetRPMLimiter' */
          SetCut(&rtDW.Merge2, &rtDW.SetRPMLimiter_n);

          /* End of Outputs for SubSystem: '<S3>/SetRPMLimiter' */
          Clutch_setValue(100);
          rtDW.valCode = ACC_CODE;
          rtDW.value = 1U;

          /* Outputs for Function Call SubSystem: '<S5>/sendUpdatesSW' */
          sendUpdatesSW(rtDW.valCode, rtDW.value, &rtDW.sendUpdatesSW_b);

          /* End of Outputs for SubSystem: '<S5>/sendUpdatesSW' */
        }
      } else {
        rtDW.accFb = 1U;
        checkShift();
        checkClutch();
      }
      break;
    }
  }

  /* End of Inport: '<Root>/modeCom' */
}

/* Function for Chart: '<Root>/GCULogic' */
static void MODES(void)
{
  uint32_T qY;
  switch (rtDW.is_MODES) {
   case IN_ACCELERATION:
    ACCELERATION();
    break;

   case IN_INIT:
    /* Inport: '<Root>/modeCom' */
    if (rtU.modeCom[1] == AUTOCROSS_MODE) {
      rtDW.is_MODES = IN_NO_ACTIVE_CHILD;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        rtDW.lastModeCom = rtU.modeCom[0];
        qY = rtDW.alive + /*MW:OvSatOk*/ 1U;
        if (qY < rtDW.alive) {
          qY = MAX_uint32_T;
        }

        rtDW.alive = qY;
        checkShift();
        checkClutch();
      }
    } else if (rtU.modeCom[1] == ENDURANCE_MODE) {
      rtDW.is_MODES = IN_NO_ACTIVE_CHILD;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        rtDW.lastModeCom = rtU.modeCom[0];
        qY = rtDW.alive + /*MW:OvSatOk*/ 1U;
        if (qY < rtDW.alive) {
          qY = MAX_uint32_T;
        }

        rtDW.alive = qY;
        checkShift();
        checkClutch();
      }
    } else if (rtU.modeCom[1] == SKIDPAD_MODE) {
      rtDW.is_MODES = IN_NO_ACTIVE_CHILD;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        rtDW.lastModeCom = rtU.modeCom[0];
        qY = rtDW.alive + /*MW:OvSatOk*/ 1U;
        if (qY < rtDW.alive) {
          qY = MAX_uint32_T;
        }

        rtDW.alive = qY;
        checkShift();
        checkClutch();
      }
    } else if (rtU.modeCom[1] == ACC_MODE) {
      rtDW.is_MODES = IN_NO_ACTIVE_CHILD;
      if (rtDW.is_MODES != IN_ACCELERATION) {
        rtDW.is_MODES = IN_ACCELERATION;
        rtDW.lastModeCom = rtU.modeCom[0];
      }

      if (rtDW.is_ACCELERATION != IN_NotReady) {
        rtDW.is_ACCELERATION = IN_NotReady;
        rtDW.accFb = 1U;
        checkShift();
        checkClutch();
      }
    } else {
      rtDW.is_MODES = IN_NO_ACTIVE_CHILD;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        rtDW.lastModeCom = rtU.modeCom[0];
        qY = rtDW.alive + /*MW:OvSatOk*/ 1U;
        if (qY < rtDW.alive) {
          qY = MAX_uint32_T;
        }

        rtDW.alive = qY;
        checkShift();
        checkClutch();
      }
    }
    break;

   case IN_MANUAL_MODES:
    /* Inport: '<Root>/modeCom' */
    if (rtU.modeCom[0] != rtDW.lastModeCom) {
      if (rtU.modeCom[1] == AUTOCROSS_MODE) {
        rtDW.is_MODES = IN_NO_ACTIVE_CHILD;
        if (rtDW.is_MODES != IN_MANUAL_MODES) {
          rtDW.is_MODES = IN_MANUAL_MODES;
          rtDW.lastModeCom = rtU.modeCom[0];
          qY = rtDW.alive + /*MW:OvSatOk*/ 1U;
          if (qY < rtDW.alive) {
            qY = MAX_uint32_T;
          }

          rtDW.alive = qY;
          checkShift();
          checkClutch();
        }
      } else if (rtU.modeCom[1] == ENDURANCE_MODE) {
        rtDW.is_MODES = IN_NO_ACTIVE_CHILD;
        if (rtDW.is_MODES != IN_MANUAL_MODES) {
          rtDW.is_MODES = IN_MANUAL_MODES;
          rtDW.lastModeCom = rtU.modeCom[0];
          qY = rtDW.alive + /*MW:OvSatOk*/ 1U;
          if (qY < rtDW.alive) {
            qY = MAX_uint32_T;
          }

          rtDW.alive = qY;
          checkShift();
          checkClutch();
        }
      } else if (rtU.modeCom[1] == SKIDPAD_MODE) {
        rtDW.is_MODES = IN_NO_ACTIVE_CHILD;
        if (rtDW.is_MODES != IN_MANUAL_MODES) {
          rtDW.is_MODES = IN_MANUAL_MODES;
          rtDW.lastModeCom = rtU.modeCom[0];
          qY = rtDW.alive + /*MW:OvSatOk*/ 1U;
          if (qY < rtDW.alive) {
            qY = MAX_uint32_T;
          }

          rtDW.alive = qY;
          checkShift();
          checkClutch();
        }
      } else if (rtU.modeCom[1] == ACC_MODE) {
        rtDW.is_MODES = IN_NO_ACTIVE_CHILD;
        if (rtDW.is_MODES != IN_ACCELERATION) {
          rtDW.is_MODES = IN_ACCELERATION;
          rtDW.lastModeCom = rtU.modeCom[0];
        }

        if (rtDW.is_ACCELERATION != IN_NotReady) {
          rtDW.is_ACCELERATION = IN_NotReady;
          rtDW.accFb = 1U;
          checkShift();
          checkClutch();
        }
      } else {
        rtDW.is_MODES = IN_NO_ACTIVE_CHILD;
        if (rtDW.is_MODES != IN_MANUAL_MODES) {
          rtDW.is_MODES = IN_MANUAL_MODES;
          rtDW.lastModeCom = rtU.modeCom[0];
          qY = rtDW.alive + /*MW:OvSatOk*/ 1U;
          if (qY < rtDW.alive) {
            qY = MAX_uint32_T;
          }

          rtDW.alive = qY;
          checkShift();
          checkClutch();
        }
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
  }
}

/* Model step function for TID0 */
void GCU_Timer_debug_step0(void)       /* Sample time: [0.0002s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void GCU_Timer_debug_step1(void)       /* Sample time: [0.001s, 0.0s] */
{
  int32_T tmp;

  /* Chart: '<Root>/GCULogic' incorporates:
   *  Inport: '<Root>/startEngCom'
   */
  rtDW.sfEvent = CALL_EVENT;
  if (rtDW.is_active_c1_GCU_Timer_debug == 0U) {
    rtDW.is_active_c1_GCU_Timer_debug = 1U;
    rtDW.is_active_MODES = 1U;
    rtDW.lastAacCom = 0U;
    rtDW.lastShiftCom = 0U;
    rtDW.lastClutchCom = 0U;
    rtDW.lastModeCom = 0U;
    rtDW.is_MODES = IN_INIT;
    rtDW.is_active_NEUTRAL_STATE = 1U;
    rtDW.is_NEUTRAL_STATE = IN_NEUTRAL;
    rtDW.is_active_GEARSHIFT = 1U;
    rtDW.ticksCounter = 0;
    if (rtDW.is_GEARSHIFT != IN_INIT_f) {
      rtDW.is_GEARSHIFT = IN_INIT_f;
      rtDW.ticksCounter = 0;
    }

    rtDW.is_active_START_ENGINE = 1U;
    rtDW.lastCom = 0U;
    rtDW.startCounter = 0U;
    rtDW.is_START_ENGINE = IN_WAIT;
  } else {
    if (rtDW.is_active_MODES != 0U) {
      MODES();
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
          rtDW.is_START_ENGINE = IN_NO_ACTIVE_CHILD;
          if (rtDW.is_START_ENGINE != IN_STOP) {
            rtDW.is_START_ENGINE = IN_STOP;

            /* Outputs for Function Call SubSystem: '<S4>/EngineControl_Stop' */
            /* S-Function (EngineControl_stop): '<S15>/EngineControl Stop' */
            EngineControl_stop_Outputs_wrapper(&rtDW.EngineControlStop);

            /* SignalConversion: '<S15>/OutportBufferForengine_starter' */
            rtDW.Merge = rtDW.EngineControlStop;

            /* End of Outputs for SubSystem: '<S4>/EngineControl_Stop' */
          }
        } else {
          tmp = rtDW.startCounter - 1;
          if (tmp < 0) {
            tmp = 0;
          }

          rtDW.startCounter = (uint8_T)tmp;
        }
        break;

       case IN_STOP:
        if (rtU.startEngCom != rtDW.lastCom) {
          rtDW.is_START_ENGINE = IN_NO_ACTIVE_CHILD;
          if (rtDW.is_START_ENGINE != IN_START_o) {
            rtDW.is_START_ENGINE = IN_START_o;

            /* Outputs for Function Call SubSystem: '<S4>/EngineControl_Start' */
            EngineControl_Start(&rtDW.Merge, &rtDW.EngineControl_Start_c);

            /* End of Outputs for SubSystem: '<S4>/EngineControl_Start' */
            rtDW.lastCom = rtU.startEngCom;
            rtDW.startCounter = 100U;
          }
        }
        break;

       case IN_WAIT:
        if (rtU.startEngCom != rtDW.lastCom) {
          rtDW.is_START_ENGINE = IN_NO_ACTIVE_CHILD;
          if (rtDW.is_START_ENGINE != IN_START_o) {
            rtDW.is_START_ENGINE = IN_START_o;

            /* Outputs for Function Call SubSystem: '<S4>/EngineControl_Start' */
            EngineControl_Start(&rtDW.Merge, &rtDW.EngineControl_Start_c);

            /* End of Outputs for SubSystem: '<S4>/EngineControl_Start' */
            rtDW.lastCom = rtU.startEngCom;
            rtDW.startCounter = 100U;
          }
        }
        break;
      }
    }
  }

  /* End of Chart: '<Root>/GCULogic' */

  /* Outport: '<Root>/Alive' */
  rtY.Alive = rtDW.alive;

  /* Outport: '<Root>/clutchCurrVal' */
  rtY.clutchCurrVal = rtDW.clutchCurrVal;

  /* Outport: '<Root>/upCut_Pin' */
  rtY.upCut_Pin = rtDW.Merge1;

  /* Outport: '<Root>/rpmLimiter_Pin' */
  rtY.rpmLimiter_Pin = rtDW.Merge2;

  /* Outport: '<Root>/PinIn1' */
  rtY.PinIn1 = rtDW.Pin_In1;

  /* Outport: '<Root>/PinIn2' */
  rtY.PinIn2 = rtDW.Pin_In2;

  /* Outport: '<Root>/PinH' */
  rtY.PinH = rtDW.Pin_H;

  /* Outport: '<Root>/engineStarter_pin' */
  rtY.engineStarter_pin = rtDW.Merge;

  /* Outport: '<Root>/accFb' */
  rtY.accFb = rtDW.accFb;
}

/* Model step function for TID2 */
void GCU_Timer_debug_step2(void)       /* Sample time: [0.001s, 0.0002s] */
{
  uint8_T rtb_RateTransition9;
  uint16_T rtb_RateTransition10;
  uint8_T rtb_RateTransition1;
  uint8_T rtb_RateTransition11;
  uint32_T rtb_RateTransition2;
  uint16_T Cast4;

  /* RateTransition: '<Root>/Rate Transition9' */
  rtb_RateTransition9 = rtDW.clutchCurrVal;

  /* RateTransition: '<Root>/Rate Transition10' */
  rtb_RateTransition10 = rtDW.accFb;

  /* RateTransition: '<Root>/Rate Transition1' */
  rtb_RateTransition1 = rtDW.Pin_In1;

  /* RateTransition: '<Root>/Rate Transition11' */
  rtb_RateTransition11 = rtDW.Pin_H;

  /* RateTransition: '<Root>/Rate Transition2' */
  rtb_RateTransition2 = rtDW.alive;

  /* S-Function (fcncallgen): '<Root>/Function_Call_Generator' incorporates:
   *  SubSystem: '<Root>/Debug '
   */
  /* DataTypeConversion: '<S2>/Cast4' */
  Cast4 = (uint16_T)rtb_RateTransition2;

  /* SignalConversion: '<S2>/TmpSignal ConversionAtPack_Uart_Message1Inport1' incorporates:
   *  DataTypeConversion: '<S2>/Cast'
   *  DataTypeConversion: '<S2>/Cast1'
   *  DataTypeConversion: '<S2>/Cast2'
   *  DataTypeConversion: '<S2>/Cast3'
   *  DataTypeConversion: '<S2>/Cast5'
   *  DataTypeConversion: '<S2>/Cast6'
   *  DataTypeConversion: '<S2>/Cast7'
   *  DataTypeConversion: '<S2>/Cast8'
   *  DataTypeConversion: '<S2>/Cast9'
   */
  rtDW.TmpSignalConversionAtPack_Uart_[0] = rtb_RateTransition9;
  rtDW.TmpSignalConversionAtPack_Uart_[1] = rtb_RateTransition10;
  rtDW.TmpSignalConversionAtPack_Uart_[2] = rtb_RateTransition1;
  rtDW.TmpSignalConversionAtPack_Uart_[3] = rtb_RateTransition11;
  rtDW.TmpSignalConversionAtPack_Uart_[4] = Cast4;
  rtDW.TmpSignalConversionAtPack_Uart_[5] = 0U;
  rtDW.TmpSignalConversionAtPack_Uart_[6] = 0U;
  rtDW.TmpSignalConversionAtPack_Uart_[7] = 0U;
  rtDW.TmpSignalConversionAtPack_Uart_[8] = 0U;
  rtDW.TmpSignalConversionAtPack_Uart_[9] = 0U;

  /* S-Function (PackUARTMsg): '<S2>/Pack_Uart_Message1' */
  PackUARTMsg_Outputs_wrapper(&rtDW.TmpSignalConversionAtPack_Uart_[0],
    &rtDW.Pack_Uart_Message1[0]);

  /* S-Function (sendUART): '<S2>/SendUART' */
  sendUART_Outputs_wrapper(&rtDW.Pack_Uart_Message1[0]);

  /* Outport: '<Root>/debugValues  ' incorporates:
   *  DataTypeConversion: '<S2>/Cast'
   *  DataTypeConversion: '<S2>/Cast1'
   *  DataTypeConversion: '<S2>/Cast2'
   *  DataTypeConversion: '<S2>/Cast3'
   *  DataTypeConversion: '<S2>/Cast5'
   *  DataTypeConversion: '<S2>/Cast6'
   *  DataTypeConversion: '<S2>/Cast7'
   *  DataTypeConversion: '<S2>/Cast8'
   *  DataTypeConversion: '<S2>/Cast9'
   */
  rtY.debugValues[0] = rtb_RateTransition9;
  rtY.debugValues[1] = rtb_RateTransition10;
  rtY.debugValues[2] = rtb_RateTransition1;
  rtY.debugValues[3] = rtb_RateTransition11;

  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function_Call_Generator' */
  rtY.debugValues[4] = Cast4;

  /* S-Function (fcncallgen): '<Root>/Function_Call_Generator' incorporates:
   *  SubSystem: '<Root>/Debug '
   */
  rtY.debugValues[5] = 0U;
  rtY.debugValues[6] = 0U;
  rtY.debugValues[7] = 0U;
  rtY.debugValues[8] = 0U;
  rtY.debugValues[9] = 0U;

  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function_Call_Generator' */
}

/* Model initialize function */
void GCU_Timer_debug_initialize(void)
{
  /* Registration code */

  /* initialize sample time offsets */

  /* SystemInitialize for Chart: '<Root>/GCULogic' */
  rtDW.sfEvent = CALL_EVENT;
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
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
