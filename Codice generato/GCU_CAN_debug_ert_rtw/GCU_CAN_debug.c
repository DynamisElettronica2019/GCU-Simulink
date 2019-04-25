/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GCU_CAN_debug.c
 *
 * Code generated for Simulink model 'GCU_CAN_debug'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Sat Mar 30 12:39:19 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "GCU_CAN_debug.h"

/* Named constants for Chart: '<Root>/MessageEvaluation' */
#define AAC_CLUTCH_NOISE_LEVEL         ((uint8_T)30U)
#define EFI_GEAR_RPM_TPS_APPS_ID       ((uint16_T)773U)
#define EFI_TRACTION_CONTROL_ID        ((uint16_T)774U)
#define GEAR_COMMAND_DOWN              ((uint16_T)200U)
#define GEAR_COMMAND_NEUTRAL_DOWN      ((uint16_T)100U)
#define GEAR_COMMAND_NEUTRAL_UP        ((uint16_T)50U)
#define IN_AAC_COM                     ((uint8_T)1U)
#define IN_GEAR_RPM_UPDATE             ((uint8_T)2U)
#define IN_IDLE                        ((uint8_T)3U)
#define IN_SET_CLUTCH                  ((uint8_T)4U)
#define IN_SET_TRACTION                ((uint8_T)5U)
#define IN_START_ENGINE                ((uint8_T)6U)
#define IN_SW_CHANGE_MODE              ((uint8_T)7U)
#define IN_SW_GEARSHIFT                ((uint8_T)8U)
#define IN_WHEEL_SPEED_UPDATE          ((uint8_T)9U)
#define RPM_LIMITER_OFF                ((uint16_T)160U)
#define RPM_LIMITER_ON                 ((uint16_T)150U)
#define STOP_COM                       ((uint16_T)0U)
#define SW_ACCELERATION_GCU_ID         ((uint16_T)514U)
#define SW_CLUTCH_TARGET_GCU_ID        ((uint16_T)513U)
#define SW_FIRE_GCU_ID                 ((uint16_T)516U)
#define SW_GEARSHIFT_ID                (512.0)
#define SW_MODE_ID                     ((uint16_T)1000U)
#define SW_TRACTION_CONTROL_GCU_ID     ((uint16_T)515U)

const uint16_T GCU_CAN_debug_U16GND = 0U;/* uint16_T ground */

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

static void TractionValue(uint16_T rtu_Value, uint16_T *rty_tractionValue,
  DW_TractionValue *localDW);
static void Efi_setRpmLimiter(uint8_T *rty_rpmLimiter_pin, DW_Efi_setRpmLimiter *
  localDW);
static void Efi_unsetRpmLimiter(uint8_T *rty_rpmLimiter_pin,
  DW_Efi_unsetRpmLimiter *localDW);
static void AAC_ExternalValues(uint16_T rtu_Value, uint16_T rtu_Index, uint16_T
  rty_Values[3], DW_AAC_ExternalValues *localDW);

/* Forward declaration for local functions */
static void sendModeCommand(uint16_T com);
static void sendAacCommand(uint16_T com);
static void sendClutchCommand(uint16_T com);
static void sendShiftCommand(uint16_T com);
static void sendStartEngCommand(void);
static void WHEEL_SPEED_UPDATE(uint16_T *tractionValue, uint16_T
  *aac_externValues_index, uint16_T *aac_externValue);
static void AAC_COM(uint16_T *tractionValue, uint16_T *aac_externValues_index,
                    uint16_T *aac_externValue);
static void GEAR_RPM_UPDATE(uint16_T *tractionValue, uint16_T
  *aac_externValues_index, uint16_T *aac_externValue);
static void IDLE(uint16_T *tractionValue, uint16_T *aac_externValues_index,
                 uint16_T *aac_externValue);
static void SET_CLUTCH(uint16_T *tractionValue, uint16_T *aac_externValues_index,
  uint16_T *aac_externValue);

/* Output and update for function-call system: '<Root>/TractionValue' */
static void TractionValue(uint16_T rtu_Value, uint16_T *rty_tractionValue,
  DW_TractionValue *localDW)
{
  /* Assignment: '<S5>/Assignment' incorporates:
   *  UnitDelay: '<S5>/Unit Delay'
   */
  *rty_tractionValue = localDW->UnitDelay_DSTATE;
  *rty_tractionValue = rtu_Value;

  /* S-Function (PackCanUART): '<S8>/PackCanUart' incorporates:
   *  Constant: '<S8>/GCU_TRACTION_CONTROL_EFI_ID'
   */
  PackCanUART_Outputs_wrapper(&rtConstP.GCU_TRACTION_CONTROL_EFI_ID_Val,
    rty_tractionValue, (uint16_T*)&GCU_CAN_debug_U16GND, (uint16_T*)
    &GCU_CAN_debug_U16GND, (uint16_T*)&GCU_CAN_debug_U16GND,
    &localDW->PackCanUart[0]);

  /* Product: '<S5>/Divide' */
  localDW->Divide = (uint16_T)(*rty_tractionValue / 100U);

  /* S-Function (PackCanUART): '<S9>/PackCanUart' incorporates:
   *  Constant: '<S5>/TRACTION_CODE'
   *  Constant: '<S9>/GCU_FEEDBACK_ID'
   */
  PackCanUART_Outputs_wrapper(&rtConstP.GCU_FEEDBACK_ID_Value,
    &rtConstP.TRACTION_CODE_Value, &localDW->Divide, (uint16_T*)
    &GCU_CAN_debug_U16GND, (uint16_T*)&GCU_CAN_debug_U16GND,
    &localDW->PackCanUart_n[0]);

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  localDW->UnitDelay_DSTATE = *rty_tractionValue;
}

/* Output and update for function-call system: '<S3>/Efi_setRpmLimiter' */
static void Efi_setRpmLimiter(uint8_T *rty_rpmLimiter_pin, DW_Efi_setRpmLimiter *
  localDW)
{
  /* S-Function (Efi_setRPMLimiter): '<S6>/Efi SetRPMLimiter' */
  Efi_setRPMLimiter_Outputs_wrapper(&localDW->EfiSetRPMLimiter);

  /* SignalConversion: '<S6>/OutportBufferForrpmLimiter_pin' */
  *rty_rpmLimiter_pin = localDW->EfiSetRPMLimiter;
}

/* Output and update for function-call system: '<S3>/Efi_unsetRpmLimiter' */
static void Efi_unsetRpmLimiter(uint8_T *rty_rpmLimiter_pin,
  DW_Efi_unsetRpmLimiter *localDW)
{
  /* S-Function (Efi_unsetRPMLimiter): '<S7>/Efi UnSetRPMLimiter' */
  Efi_unsetRPMLimiter_Outputs_wrapper(&localDW->EfiUnSetRPMLimiter);

  /* SignalConversion: '<S7>/OutportBufferForrpmLimiter_pin' */
  *rty_rpmLimiter_pin = localDW->EfiUnSetRPMLimiter;
}

/* Output and update for function-call system: '<Root>/AAC_ExternalValues' */
static void AAC_ExternalValues(uint16_T rtu_Value, uint16_T rtu_Index, uint16_T
  rty_Values[3], DW_AAC_ExternalValues *localDW)
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
static void sendModeCommand(uint16_T com)
{
  int32_T tmp;
  if (rtDW.modeCommand[0] >= 255) {
    rtDW.modeCommand[0] = 0U;
  } else {
    tmp = rtDW.modeCommand[0] + 1;
    if (tmp > 65535) {
      tmp = 65535;
    }

    rtDW.modeCommand[0] = (uint16_T)tmp;
  }

  rtDW.modeCommand[1] = com;
}

/* Function for Chart: '<Root>/MessageEvaluation' */
static void sendAacCommand(uint16_T com)
{
  int32_T tmp;
  if (rtDW.aacCommand[0] >= 255) {
    rtDW.aacCommand[0] = 0U;
  } else {
    tmp = rtDW.aacCommand[0] + 1;
    if (tmp > 65535) {
      tmp = 65535;
    }

    rtDW.aacCommand[0] = (uint16_T)tmp;
  }

  rtDW.aacCommand[1] = com;
}

/* Function for Chart: '<Root>/MessageEvaluation' */
static void sendClutchCommand(uint16_T com)
{
  uint16_T tmp;
  int32_T tmp_0;
  if (rtDW.clutchCommand[0] >= 255) {
    rtDW.clutchCommand[0] = 0U;
  } else {
    tmp_0 = rtDW.clutchCommand[0] + 1;
    if (tmp_0 > 255) {
      tmp_0 = 255;
    }

    rtDW.clutchCommand[0] = (uint8_T)tmp_0;
  }

  tmp = com;
  if (com > 255) {
    tmp = 255U;
  }

  rtDW.clutchCommand[1] = (uint8_T)tmp;
}

/* Function for Chart: '<Root>/MessageEvaluation' */
static void sendShiftCommand(uint16_T com)
{
  int32_T tmp;
  if (rtDW.shiftCommand[0] >= 255) {
    rtDW.shiftCommand[0] = 0U;
  } else {
    tmp = rtDW.shiftCommand[0] + 1;
    if (tmp > 65535) {
      tmp = 65535;
    }

    rtDW.shiftCommand[0] = (uint16_T)tmp;
  }

  rtDW.shiftCommand[1] = com;

  /* Inport: '<Root>/clutchCurrVal' */
  if ((rtU.clutchCurrVal != 100) && ((com == GEAR_COMMAND_NEUTRAL_UP) || (com ==
        GEAR_COMMAND_NEUTRAL_DOWN) || (com == GEAR_COMMAND_DOWN))) {
    sendAacCommand(STOP_COM);
  }

  /* End of Inport: '<Root>/clutchCurrVal' */
}

/* Function for Chart: '<Root>/MessageEvaluation' */
static void sendStartEngCommand(void)
{
  int32_T tmp;
  if (rtDW.startEngCommand >= 255) {
    rtDW.startEngCommand = 0U;
  } else {
    tmp = rtDW.startEngCommand + 1;
    if (tmp > 255) {
      tmp = 255;
    }

    rtDW.startEngCommand = (uint8_T)tmp;
  }
}

/* Function for Chart: '<Root>/MessageEvaluation' */
static void WHEEL_SPEED_UPDATE(uint16_T *tractionValue, uint16_T
  *aac_externValues_index, uint16_T *aac_externValue)
{
  uint8_T clutchSetVal;
  int32_T tmp;
  *aac_externValues_index = (uint16_T)WHEEL_SPEED;
  if (rtDW.UnpackCanUart_o1 == EFI_GEAR_RPM_TPS_APPS_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_GEAR_RPM_UPDATE;
    rtDW.currGear = rtDW.UnpackCanUart_o2;
    *aac_externValues_index = (uint16_T)RPM;
    *aac_externValue = rtDW.UnpackCanUart_o3;

    /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
    AAC_ExternalValues(*aac_externValue, *aac_externValues_index,
                       rtDW.Assignment, &rtDW.AAC_ExternalValues_p);

    /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
  } else if (rtDW.UnpackCanUart_o1 == SW_FIRE_GCU_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_START_ENGINE;
    sendStartEngCommand();
  } else if (rtDW.UnpackCanUart_o1 == (int32_T)SW_GEARSHIFT_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_SW_GEARSHIFT;
    if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_ON) {
      /* Outputs for Function Call SubSystem: '<S3>/Efi_setRpmLimiter' */
      Efi_setRpmLimiter(&rtDW.Merge, &rtDW.Efi_setRpmLimiter_c);

      /* End of Outputs for SubSystem: '<S3>/Efi_setRpmLimiter' */
    } else if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_OFF) {
      /* Outputs for Function Call SubSystem: '<S3>/Efi_unsetRpmLimiter' */
      Efi_unsetRpmLimiter(&rtDW.Merge, &rtDW.Efi_unsetRpmLimiter_a);

      /* End of Outputs for SubSystem: '<S3>/Efi_unsetRpmLimiter' */
    } else {
      sendShiftCommand(rtDW.UnpackCanUart_o2);
    }
  } else if (rtDW.UnpackCanUart_o1 == EFI_TRACTION_CONTROL_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_WHEEL_SPEED_UPDATE;
    *aac_externValues_index = (uint16_T)WHEEL_SPEED;
    *aac_externValue = (uint16_T)(rtDW.UnpackCanUart_o2 / 10U);

    /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
    AAC_ExternalValues(*aac_externValue, *aac_externValues_index,
                       rtDW.Assignment, &rtDW.AAC_ExternalValues_p);

    /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
  } else if (rtDW.UnpackCanUart_o1 == SW_CLUTCH_TARGET_GCU_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_SET_CLUTCH;
    clutchSetVal = (uint8_T)(rtDW.UnpackCanUart_o2 >> 8);
    if (clutchSetVal > AAC_CLUTCH_NOISE_LEVEL) {
      sendAacCommand(STOP_COM);
    }

    sendClutchCommand((uint16_T)clutchSetVal);
  } else if (rtDW.UnpackCanUart_o1 == SW_ACCELERATION_GCU_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_AAC_COM;
    sendAacCommand(rtDW.UnpackCanUart_o2);
    if (rtDW.aacCommand[1] == STOP_COM) {
      sendClutchCommand(0);
    }
  } else if (rtDW.UnpackCanUart_o1 == SW_TRACTION_CONTROL_GCU_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_SET_TRACTION;
    tmp = rtDW.UnpackCanUart_o2 * 100;
    if (tmp > 65535) {
      tmp = 65535;
    }

    *tractionValue = (uint16_T)tmp;

    /* Outputs for Function Call SubSystem: '<Root>/TractionValue' */
    TractionValue(*tractionValue, &rtDW.Assignment_e, &rtDW.TractionValue_h);

    /* End of Outputs for SubSystem: '<Root>/TractionValue' */
  } else if (rtDW.UnpackCanUart_o1 == SW_MODE_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_SW_CHANGE_MODE;
    sendModeCommand(rtDW.UnpackCanUart_o2);
  } else {
    rtDW.is_c2_GCU_CAN_debug = IN_IDLE;
  }
}

/* Function for Chart: '<Root>/MessageEvaluation' */
static void AAC_COM(uint16_T *tractionValue, uint16_T *aac_externValues_index,
                    uint16_T *aac_externValue)
{
  uint8_T clutchSetVal;
  int32_T tmp;
  if (rtDW.UnpackCanUart_o1 == EFI_GEAR_RPM_TPS_APPS_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_GEAR_RPM_UPDATE;
    rtDW.currGear = rtDW.UnpackCanUart_o2;
    *aac_externValues_index = (uint16_T)RPM;
    *aac_externValue = rtDW.UnpackCanUart_o3;

    /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
    AAC_ExternalValues(*aac_externValue, *aac_externValues_index,
                       rtDW.Assignment, &rtDW.AAC_ExternalValues_p);

    /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
  } else if (rtDW.UnpackCanUart_o1 == SW_FIRE_GCU_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_START_ENGINE;
    sendStartEngCommand();
  } else if (rtDW.UnpackCanUart_o1 == (int32_T)SW_GEARSHIFT_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_SW_GEARSHIFT;
    if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_ON) {
      /* Outputs for Function Call SubSystem: '<S3>/Efi_setRpmLimiter' */
      Efi_setRpmLimiter(&rtDW.Merge, &rtDW.Efi_setRpmLimiter_c);

      /* End of Outputs for SubSystem: '<S3>/Efi_setRpmLimiter' */
    } else if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_OFF) {
      /* Outputs for Function Call SubSystem: '<S3>/Efi_unsetRpmLimiter' */
      Efi_unsetRpmLimiter(&rtDW.Merge, &rtDW.Efi_unsetRpmLimiter_a);

      /* End of Outputs for SubSystem: '<S3>/Efi_unsetRpmLimiter' */
    } else {
      sendShiftCommand(rtDW.UnpackCanUart_o2);
    }
  } else if (rtDW.UnpackCanUart_o1 == EFI_TRACTION_CONTROL_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_WHEEL_SPEED_UPDATE;
    *aac_externValues_index = (uint16_T)WHEEL_SPEED;
    *aac_externValue = (uint16_T)(rtDW.UnpackCanUart_o2 / 10U);

    /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
    AAC_ExternalValues(*aac_externValue, *aac_externValues_index,
                       rtDW.Assignment, &rtDW.AAC_ExternalValues_p);

    /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
  } else if (rtDW.UnpackCanUart_o1 == SW_CLUTCH_TARGET_GCU_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_SET_CLUTCH;
    clutchSetVal = (uint8_T)(rtDW.UnpackCanUart_o2 >> 8);
    if (clutchSetVal > AAC_CLUTCH_NOISE_LEVEL) {
      sendAacCommand(STOP_COM);
    }

    sendClutchCommand((uint16_T)clutchSetVal);
  } else if (rtDW.UnpackCanUart_o1 == SW_ACCELERATION_GCU_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_AAC_COM;
    sendAacCommand(rtDW.UnpackCanUart_o2);
    if (rtDW.aacCommand[1] == STOP_COM) {
      sendClutchCommand(0);
    }
  } else if (rtDW.UnpackCanUart_o1 == SW_TRACTION_CONTROL_GCU_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_SET_TRACTION;
    tmp = rtDW.UnpackCanUart_o2 * 100;
    if (tmp > 65535) {
      tmp = 65535;
    }

    *tractionValue = (uint16_T)tmp;

    /* Outputs for Function Call SubSystem: '<Root>/TractionValue' */
    TractionValue(*tractionValue, &rtDW.Assignment_e, &rtDW.TractionValue_h);

    /* End of Outputs for SubSystem: '<Root>/TractionValue' */
  } else if (rtDW.UnpackCanUart_o1 == SW_MODE_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_SW_CHANGE_MODE;
    sendModeCommand(rtDW.UnpackCanUart_o2);
  } else {
    rtDW.is_c2_GCU_CAN_debug = IN_IDLE;
  }
}

/* Function for Chart: '<Root>/MessageEvaluation' */
static void GEAR_RPM_UPDATE(uint16_T *tractionValue, uint16_T
  *aac_externValues_index, uint16_T *aac_externValue)
{
  uint8_T clutchSetVal;
  int32_T tmp;
  *aac_externValues_index = (uint16_T)RPM;
  if (rtDW.UnpackCanUart_o1 == EFI_GEAR_RPM_TPS_APPS_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_GEAR_RPM_UPDATE;
    rtDW.currGear = rtDW.UnpackCanUart_o2;
    *aac_externValues_index = (uint16_T)RPM;
    *aac_externValue = rtDW.UnpackCanUart_o3;

    /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
    AAC_ExternalValues(*aac_externValue, *aac_externValues_index,
                       rtDW.Assignment, &rtDW.AAC_ExternalValues_p);

    /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
  } else if (rtDW.UnpackCanUart_o1 == SW_FIRE_GCU_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_START_ENGINE;
    sendStartEngCommand();
  } else if (rtDW.UnpackCanUart_o1 == (int32_T)SW_GEARSHIFT_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_SW_GEARSHIFT;
    if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_ON) {
      /* Outputs for Function Call SubSystem: '<S3>/Efi_setRpmLimiter' */
      Efi_setRpmLimiter(&rtDW.Merge, &rtDW.Efi_setRpmLimiter_c);

      /* End of Outputs for SubSystem: '<S3>/Efi_setRpmLimiter' */
    } else if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_OFF) {
      /* Outputs for Function Call SubSystem: '<S3>/Efi_unsetRpmLimiter' */
      Efi_unsetRpmLimiter(&rtDW.Merge, &rtDW.Efi_unsetRpmLimiter_a);

      /* End of Outputs for SubSystem: '<S3>/Efi_unsetRpmLimiter' */
    } else {
      sendShiftCommand(rtDW.UnpackCanUart_o2);
    }
  } else if (rtDW.UnpackCanUart_o1 == EFI_TRACTION_CONTROL_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_WHEEL_SPEED_UPDATE;
    *aac_externValues_index = (uint16_T)WHEEL_SPEED;
    *aac_externValue = (uint16_T)(rtDW.UnpackCanUart_o2 / 10U);

    /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
    AAC_ExternalValues(*aac_externValue, *aac_externValues_index,
                       rtDW.Assignment, &rtDW.AAC_ExternalValues_p);

    /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
  } else if (rtDW.UnpackCanUart_o1 == SW_CLUTCH_TARGET_GCU_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_SET_CLUTCH;
    clutchSetVal = (uint8_T)(rtDW.UnpackCanUart_o2 >> 8);
    if (clutchSetVal > AAC_CLUTCH_NOISE_LEVEL) {
      sendAacCommand(STOP_COM);
    }

    sendClutchCommand((uint16_T)clutchSetVal);
  } else if (rtDW.UnpackCanUart_o1 == SW_ACCELERATION_GCU_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_AAC_COM;
    sendAacCommand(rtDW.UnpackCanUart_o2);
    if (rtDW.aacCommand[1] == STOP_COM) {
      sendClutchCommand(0);
    }
  } else if (rtDW.UnpackCanUart_o1 == SW_TRACTION_CONTROL_GCU_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_SET_TRACTION;
    tmp = rtDW.UnpackCanUart_o2 * 100;
    if (tmp > 65535) {
      tmp = 65535;
    }

    *tractionValue = (uint16_T)tmp;

    /* Outputs for Function Call SubSystem: '<Root>/TractionValue' */
    TractionValue(*tractionValue, &rtDW.Assignment_e, &rtDW.TractionValue_h);

    /* End of Outputs for SubSystem: '<Root>/TractionValue' */
  } else if (rtDW.UnpackCanUart_o1 == SW_MODE_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_SW_CHANGE_MODE;
    sendModeCommand(rtDW.UnpackCanUart_o2);
  } else {
    rtDW.is_c2_GCU_CAN_debug = IN_IDLE;
  }
}

/* Function for Chart: '<Root>/MessageEvaluation' */
static void IDLE(uint16_T *tractionValue, uint16_T *aac_externValues_index,
                 uint16_T *aac_externValue)
{
  uint8_T clutchSetVal;
  int32_T tmp;
  if (rtDW.UnpackCanUart_o1 == EFI_GEAR_RPM_TPS_APPS_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_GEAR_RPM_UPDATE;
    rtDW.currGear = rtDW.UnpackCanUart_o2;
    *aac_externValues_index = (uint16_T)RPM;
    *aac_externValue = rtDW.UnpackCanUart_o3;

    /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
    AAC_ExternalValues(*aac_externValue, *aac_externValues_index,
                       rtDW.Assignment, &rtDW.AAC_ExternalValues_p);

    /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
  } else if (rtDW.UnpackCanUart_o1 == SW_FIRE_GCU_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_START_ENGINE;
    sendStartEngCommand();
  } else if (rtDW.UnpackCanUart_o1 == (int32_T)SW_GEARSHIFT_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_SW_GEARSHIFT;
    if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_ON) {
      /* Outputs for Function Call SubSystem: '<S3>/Efi_setRpmLimiter' */
      Efi_setRpmLimiter(&rtDW.Merge, &rtDW.Efi_setRpmLimiter_c);

      /* End of Outputs for SubSystem: '<S3>/Efi_setRpmLimiter' */
    } else if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_OFF) {
      /* Outputs for Function Call SubSystem: '<S3>/Efi_unsetRpmLimiter' */
      Efi_unsetRpmLimiter(&rtDW.Merge, &rtDW.Efi_unsetRpmLimiter_a);

      /* End of Outputs for SubSystem: '<S3>/Efi_unsetRpmLimiter' */
    } else {
      sendShiftCommand(rtDW.UnpackCanUart_o2);
    }
  } else if (rtDW.UnpackCanUart_o1 == EFI_TRACTION_CONTROL_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_WHEEL_SPEED_UPDATE;
    *aac_externValues_index = (uint16_T)WHEEL_SPEED;
    *aac_externValue = (uint16_T)(rtDW.UnpackCanUart_o2 / 10U);

    /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
    AAC_ExternalValues(*aac_externValue, *aac_externValues_index,
                       rtDW.Assignment, &rtDW.AAC_ExternalValues_p);

    /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
  } else if (rtDW.UnpackCanUart_o1 == SW_CLUTCH_TARGET_GCU_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_SET_CLUTCH;
    clutchSetVal = (uint8_T)(rtDW.UnpackCanUart_o2 >> 8);
    if (clutchSetVal > AAC_CLUTCH_NOISE_LEVEL) {
      sendAacCommand(STOP_COM);
    }

    sendClutchCommand((uint16_T)clutchSetVal);
  } else if (rtDW.UnpackCanUart_o1 == SW_ACCELERATION_GCU_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_AAC_COM;
    sendAacCommand(rtDW.UnpackCanUart_o2);
    if (rtDW.aacCommand[1] == STOP_COM) {
      sendClutchCommand(0);
    }
  } else if (rtDW.UnpackCanUart_o1 == SW_TRACTION_CONTROL_GCU_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_SET_TRACTION;
    tmp = rtDW.UnpackCanUart_o2 * 100;
    if (tmp > 65535) {
      tmp = 65535;
    }

    *tractionValue = (uint16_T)tmp;

    /* Outputs for Function Call SubSystem: '<Root>/TractionValue' */
    TractionValue(*tractionValue, &rtDW.Assignment_e, &rtDW.TractionValue_h);

    /* End of Outputs for SubSystem: '<Root>/TractionValue' */
  } else if (rtDW.UnpackCanUart_o1 == SW_MODE_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_SW_CHANGE_MODE;
    sendModeCommand(rtDW.UnpackCanUart_o2);
  } else {
    rtDW.is_c2_GCU_CAN_debug = IN_IDLE;
  }
}

/* Function for Chart: '<Root>/MessageEvaluation' */
static void SET_CLUTCH(uint16_T *tractionValue, uint16_T *aac_externValues_index,
  uint16_T *aac_externValue)
{
  uint8_T clutchSetVal;
  int32_T tmp;
  if (rtDW.UnpackCanUart_o1 == EFI_GEAR_RPM_TPS_APPS_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_GEAR_RPM_UPDATE;
    rtDW.currGear = rtDW.UnpackCanUart_o2;
    *aac_externValues_index = (uint16_T)RPM;
    *aac_externValue = rtDW.UnpackCanUart_o3;

    /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
    AAC_ExternalValues(*aac_externValue, *aac_externValues_index,
                       rtDW.Assignment, &rtDW.AAC_ExternalValues_p);

    /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
  } else if (rtDW.UnpackCanUart_o1 == SW_FIRE_GCU_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_START_ENGINE;
    sendStartEngCommand();
  } else if (rtDW.UnpackCanUart_o1 == (int32_T)SW_GEARSHIFT_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_SW_GEARSHIFT;
    if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_ON) {
      /* Outputs for Function Call SubSystem: '<S3>/Efi_setRpmLimiter' */
      Efi_setRpmLimiter(&rtDW.Merge, &rtDW.Efi_setRpmLimiter_c);

      /* End of Outputs for SubSystem: '<S3>/Efi_setRpmLimiter' */
    } else if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_OFF) {
      /* Outputs for Function Call SubSystem: '<S3>/Efi_unsetRpmLimiter' */
      Efi_unsetRpmLimiter(&rtDW.Merge, &rtDW.Efi_unsetRpmLimiter_a);

      /* End of Outputs for SubSystem: '<S3>/Efi_unsetRpmLimiter' */
    } else {
      sendShiftCommand(rtDW.UnpackCanUart_o2);
    }
  } else if (rtDW.UnpackCanUart_o1 == EFI_TRACTION_CONTROL_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_WHEEL_SPEED_UPDATE;
    *aac_externValues_index = (uint16_T)WHEEL_SPEED;
    *aac_externValue = (uint16_T)(rtDW.UnpackCanUart_o2 / 10U);

    /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
    AAC_ExternalValues(*aac_externValue, *aac_externValues_index,
                       rtDW.Assignment, &rtDW.AAC_ExternalValues_p);

    /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
  } else if (rtDW.UnpackCanUart_o1 == SW_CLUTCH_TARGET_GCU_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_SET_CLUTCH;
    clutchSetVal = (uint8_T)(rtDW.UnpackCanUart_o2 >> 8);
    if (clutchSetVal > AAC_CLUTCH_NOISE_LEVEL) {
      sendAacCommand(STOP_COM);
    }

    sendClutchCommand((uint16_T)clutchSetVal);
  } else if (rtDW.UnpackCanUart_o1 == SW_ACCELERATION_GCU_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_AAC_COM;
    sendAacCommand(rtDW.UnpackCanUart_o2);
    if (rtDW.aacCommand[1] == STOP_COM) {
      sendClutchCommand(0);
    }
  } else if (rtDW.UnpackCanUart_o1 == SW_TRACTION_CONTROL_GCU_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_SET_TRACTION;
    tmp = rtDW.UnpackCanUart_o2 * 100;
    if (tmp > 65535) {
      tmp = 65535;
    }

    *tractionValue = (uint16_T)tmp;

    /* Outputs for Function Call SubSystem: '<Root>/TractionValue' */
    TractionValue(*tractionValue, &rtDW.Assignment_e, &rtDW.TractionValue_h);

    /* End of Outputs for SubSystem: '<Root>/TractionValue' */
  } else if (rtDW.UnpackCanUart_o1 == SW_MODE_ID) {
    rtDW.is_c2_GCU_CAN_debug = IN_SW_CHANGE_MODE;
    sendModeCommand(rtDW.UnpackCanUart_o2);
  } else {
    rtDW.is_c2_GCU_CAN_debug = IN_IDLE;
  }
}

/* Model step function for TID0 */
void GCU_CAN_debug_step0(void)         /* Sample time: [0.01s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void GCU_CAN_debug_step1(void)         /* Sample time: [0.02s, 0.0s] */
{
  uint8_T clutchSetVal;
  uint16_T tractionValue;
  uint16_T aac_externValues_index;
  uint16_T aac_externValue;
  int32_T tmp;

  /* S-Function (UnpackCanUART): '<Root>/UnpackCanUart' incorporates:
   *  Inport: '<Root>/dataBuffer'
   */
  UnpackCanUART_Outputs_wrapper(&rtU.dataBuffer[0], &rtDW.UnpackCanUart_o1,
    &rtDW.UnpackCanUart_o2, &rtDW.UnpackCanUart_o3, &rtDW.UnpackCanUart_o4,
    &rtDW.UnpackCanUart_o5);

  /* Chart: '<Root>/MessageEvaluation' */
  if (rtDW.is_active_c2_GCU_CAN_debug == 0U) {
    rtDW.is_active_c2_GCU_CAN_debug = 1U;
    rtDW.is_c2_GCU_CAN_debug = IN_IDLE;
  } else {
    switch (rtDW.is_c2_GCU_CAN_debug) {
     case IN_AAC_COM:
      AAC_COM(&tractionValue, &aac_externValues_index, &aac_externValue);
      break;

     case IN_GEAR_RPM_UPDATE:
      GEAR_RPM_UPDATE(&tractionValue, &aac_externValues_index, &aac_externValue);
      break;

     case IN_IDLE:
      IDLE(&tractionValue, &aac_externValues_index, &aac_externValue);
      break;

     case IN_SET_CLUTCH:
      SET_CLUTCH(&tractionValue, &aac_externValues_index, &aac_externValue);
      break;

     case IN_SET_TRACTION:
      if (rtDW.UnpackCanUart_o1 == EFI_GEAR_RPM_TPS_APPS_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_GEAR_RPM_UPDATE;
        rtDW.currGear = rtDW.UnpackCanUart_o2;

        /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
        AAC_ExternalValues(rtDW.UnpackCanUart_o3, (uint16_T)RPM, rtDW.Assignment,
                           &rtDW.AAC_ExternalValues_p);

        /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
      } else if (rtDW.UnpackCanUart_o1 == SW_FIRE_GCU_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_START_ENGINE;
        sendStartEngCommand();
      } else if (rtDW.UnpackCanUart_o1 == (int32_T)SW_GEARSHIFT_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_SW_GEARSHIFT;
        if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_ON) {
          /* Outputs for Function Call SubSystem: '<S3>/Efi_setRpmLimiter' */
          Efi_setRpmLimiter(&rtDW.Merge, &rtDW.Efi_setRpmLimiter_c);

          /* End of Outputs for SubSystem: '<S3>/Efi_setRpmLimiter' */
        } else if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_OFF) {
          /* Outputs for Function Call SubSystem: '<S3>/Efi_unsetRpmLimiter' */
          Efi_unsetRpmLimiter(&rtDW.Merge, &rtDW.Efi_unsetRpmLimiter_a);

          /* End of Outputs for SubSystem: '<S3>/Efi_unsetRpmLimiter' */
        } else {
          sendShiftCommand(rtDW.UnpackCanUart_o2);
        }
      } else if (rtDW.UnpackCanUart_o1 == EFI_TRACTION_CONTROL_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_WHEEL_SPEED_UPDATE;

        /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
        AAC_ExternalValues((uint16_T)(rtDW.UnpackCanUart_o2 / 10U), (uint16_T)
                           WHEEL_SPEED, rtDW.Assignment,
                           &rtDW.AAC_ExternalValues_p);

        /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
      } else if (rtDW.UnpackCanUart_o1 == SW_CLUTCH_TARGET_GCU_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_SET_CLUTCH;
        clutchSetVal = (uint8_T)(rtDW.UnpackCanUart_o2 >> 8);
        if (clutchSetVal > AAC_CLUTCH_NOISE_LEVEL) {
          sendAacCommand(STOP_COM);
        }

        sendClutchCommand((uint16_T)clutchSetVal);
      } else if (rtDW.UnpackCanUart_o1 == SW_ACCELERATION_GCU_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_AAC_COM;
        sendAacCommand(rtDW.UnpackCanUart_o2);
        if (rtDW.aacCommand[1] == STOP_COM) {
          sendClutchCommand(0);
        }
      } else if (rtDW.UnpackCanUart_o1 == SW_TRACTION_CONTROL_GCU_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_SET_TRACTION;
        tmp = rtDW.UnpackCanUart_o2 * 100;
        if (tmp > 65535) {
          tmp = 65535;
        }

        /* Outputs for Function Call SubSystem: '<Root>/TractionValue' */
        TractionValue((uint16_T)tmp, &rtDW.Assignment_e, &rtDW.TractionValue_h);

        /* End of Outputs for SubSystem: '<Root>/TractionValue' */
      } else if (rtDW.UnpackCanUart_o1 == SW_MODE_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_SW_CHANGE_MODE;
        sendModeCommand(rtDW.UnpackCanUart_o2);
      } else {
        rtDW.is_c2_GCU_CAN_debug = IN_IDLE;
      }
      break;

     case IN_START_ENGINE:
      if (rtDW.UnpackCanUart_o1 == EFI_GEAR_RPM_TPS_APPS_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_GEAR_RPM_UPDATE;
        rtDW.currGear = rtDW.UnpackCanUart_o2;

        /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
        AAC_ExternalValues(rtDW.UnpackCanUart_o3, (uint16_T)RPM, rtDW.Assignment,
                           &rtDW.AAC_ExternalValues_p);

        /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
      } else if (rtDW.UnpackCanUart_o1 == SW_FIRE_GCU_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_START_ENGINE;
        sendStartEngCommand();
      } else if (rtDW.UnpackCanUart_o1 == (int32_T)SW_GEARSHIFT_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_SW_GEARSHIFT;
        if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_ON) {
          /* Outputs for Function Call SubSystem: '<S3>/Efi_setRpmLimiter' */
          Efi_setRpmLimiter(&rtDW.Merge, &rtDW.Efi_setRpmLimiter_c);

          /* End of Outputs for SubSystem: '<S3>/Efi_setRpmLimiter' */
        } else if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_OFF) {
          /* Outputs for Function Call SubSystem: '<S3>/Efi_unsetRpmLimiter' */
          Efi_unsetRpmLimiter(&rtDW.Merge, &rtDW.Efi_unsetRpmLimiter_a);

          /* End of Outputs for SubSystem: '<S3>/Efi_unsetRpmLimiter' */
        } else {
          sendShiftCommand(rtDW.UnpackCanUart_o2);
        }
      } else if (rtDW.UnpackCanUart_o1 == EFI_TRACTION_CONTROL_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_WHEEL_SPEED_UPDATE;

        /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
        AAC_ExternalValues((uint16_T)(rtDW.UnpackCanUart_o2 / 10U), (uint16_T)
                           WHEEL_SPEED, rtDW.Assignment,
                           &rtDW.AAC_ExternalValues_p);

        /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
      } else if (rtDW.UnpackCanUart_o1 == SW_CLUTCH_TARGET_GCU_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_SET_CLUTCH;
        clutchSetVal = (uint8_T)(rtDW.UnpackCanUart_o2 >> 8);
        if (clutchSetVal > AAC_CLUTCH_NOISE_LEVEL) {
          sendAacCommand(STOP_COM);
        }

        sendClutchCommand((uint16_T)clutchSetVal);
      } else if (rtDW.UnpackCanUart_o1 == SW_ACCELERATION_GCU_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_AAC_COM;
        sendAacCommand(rtDW.UnpackCanUart_o2);
        if (rtDW.aacCommand[1] == STOP_COM) {
          sendClutchCommand(0);
        }
      } else if (rtDW.UnpackCanUart_o1 == SW_TRACTION_CONTROL_GCU_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_SET_TRACTION;
        tmp = rtDW.UnpackCanUart_o2 * 100;
        if (tmp > 65535) {
          tmp = 65535;
        }

        /* Outputs for Function Call SubSystem: '<Root>/TractionValue' */
        TractionValue((uint16_T)tmp, &rtDW.Assignment_e, &rtDW.TractionValue_h);

        /* End of Outputs for SubSystem: '<Root>/TractionValue' */
      } else if (rtDW.UnpackCanUart_o1 == SW_MODE_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_SW_CHANGE_MODE;
        sendModeCommand(rtDW.UnpackCanUart_o2);
      } else {
        rtDW.is_c2_GCU_CAN_debug = IN_IDLE;
      }
      break;

     case IN_SW_CHANGE_MODE:
      if (rtDW.UnpackCanUart_o1 == EFI_GEAR_RPM_TPS_APPS_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_GEAR_RPM_UPDATE;
        rtDW.currGear = rtDW.UnpackCanUart_o2;

        /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
        AAC_ExternalValues(rtDW.UnpackCanUart_o3, (uint16_T)RPM, rtDW.Assignment,
                           &rtDW.AAC_ExternalValues_p);

        /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
      } else if (rtDW.UnpackCanUart_o1 == SW_FIRE_GCU_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_START_ENGINE;
        sendStartEngCommand();
      } else if (rtDW.UnpackCanUart_o1 == (int32_T)SW_GEARSHIFT_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_SW_GEARSHIFT;
        if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_ON) {
          /* Outputs for Function Call SubSystem: '<S3>/Efi_setRpmLimiter' */
          Efi_setRpmLimiter(&rtDW.Merge, &rtDW.Efi_setRpmLimiter_c);

          /* End of Outputs for SubSystem: '<S3>/Efi_setRpmLimiter' */
        } else if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_OFF) {
          /* Outputs for Function Call SubSystem: '<S3>/Efi_unsetRpmLimiter' */
          Efi_unsetRpmLimiter(&rtDW.Merge, &rtDW.Efi_unsetRpmLimiter_a);

          /* End of Outputs for SubSystem: '<S3>/Efi_unsetRpmLimiter' */
        } else {
          sendShiftCommand(rtDW.UnpackCanUart_o2);
        }
      } else if (rtDW.UnpackCanUart_o1 == EFI_TRACTION_CONTROL_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_WHEEL_SPEED_UPDATE;

        /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
        AAC_ExternalValues((uint16_T)(rtDW.UnpackCanUart_o2 / 10U), (uint16_T)
                           WHEEL_SPEED, rtDW.Assignment,
                           &rtDW.AAC_ExternalValues_p);

        /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
      } else if (rtDW.UnpackCanUart_o1 == SW_CLUTCH_TARGET_GCU_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_SET_CLUTCH;
        clutchSetVal = (uint8_T)(rtDW.UnpackCanUart_o2 >> 8);
        if (clutchSetVal > AAC_CLUTCH_NOISE_LEVEL) {
          sendAacCommand(STOP_COM);
        }

        sendClutchCommand((uint16_T)clutchSetVal);
      } else if (rtDW.UnpackCanUart_o1 == SW_ACCELERATION_GCU_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_AAC_COM;
        sendAacCommand(rtDW.UnpackCanUart_o2);
        if (rtDW.aacCommand[1] == STOP_COM) {
          sendClutchCommand(0);
        }
      } else if (rtDW.UnpackCanUart_o1 == SW_TRACTION_CONTROL_GCU_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_SET_TRACTION;
        tmp = rtDW.UnpackCanUart_o2 * 100;
        if (tmp > 65535) {
          tmp = 65535;
        }

        /* Outputs for Function Call SubSystem: '<Root>/TractionValue' */
        TractionValue((uint16_T)tmp, &rtDW.Assignment_e, &rtDW.TractionValue_h);

        /* End of Outputs for SubSystem: '<Root>/TractionValue' */
      } else if (rtDW.UnpackCanUart_o1 == SW_MODE_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_SW_CHANGE_MODE;
        sendModeCommand(rtDW.UnpackCanUart_o2);
      } else {
        rtDW.is_c2_GCU_CAN_debug = IN_IDLE;
      }
      break;

     case IN_SW_GEARSHIFT:
      if (rtDW.UnpackCanUart_o1 == EFI_GEAR_RPM_TPS_APPS_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_GEAR_RPM_UPDATE;
        rtDW.currGear = rtDW.UnpackCanUart_o2;

        /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
        AAC_ExternalValues(rtDW.UnpackCanUart_o3, (uint16_T)RPM, rtDW.Assignment,
                           &rtDW.AAC_ExternalValues_p);

        /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
      } else if (rtDW.UnpackCanUart_o1 == SW_FIRE_GCU_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_START_ENGINE;
        sendStartEngCommand();
      } else if (rtDW.UnpackCanUart_o1 == (int32_T)SW_GEARSHIFT_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_SW_GEARSHIFT;
        if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_ON) {
          /* Outputs for Function Call SubSystem: '<S3>/Efi_setRpmLimiter' */
          Efi_setRpmLimiter(&rtDW.Merge, &rtDW.Efi_setRpmLimiter_c);

          /* End of Outputs for SubSystem: '<S3>/Efi_setRpmLimiter' */
        } else if (rtDW.UnpackCanUart_o2 == RPM_LIMITER_OFF) {
          /* Outputs for Function Call SubSystem: '<S3>/Efi_unsetRpmLimiter' */
          Efi_unsetRpmLimiter(&rtDW.Merge, &rtDW.Efi_unsetRpmLimiter_a);

          /* End of Outputs for SubSystem: '<S3>/Efi_unsetRpmLimiter' */
        } else {
          sendShiftCommand(rtDW.UnpackCanUart_o2);
        }
      } else if (rtDW.UnpackCanUart_o1 == EFI_TRACTION_CONTROL_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_WHEEL_SPEED_UPDATE;

        /* Outputs for Function Call SubSystem: '<Root>/AAC_ExternalValues' */
        AAC_ExternalValues((uint16_T)(rtDW.UnpackCanUart_o2 / 10U), (uint16_T)
                           WHEEL_SPEED, rtDW.Assignment,
                           &rtDW.AAC_ExternalValues_p);

        /* End of Outputs for SubSystem: '<Root>/AAC_ExternalValues' */
      } else if (rtDW.UnpackCanUart_o1 == SW_CLUTCH_TARGET_GCU_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_SET_CLUTCH;
        clutchSetVal = (uint8_T)(rtDW.UnpackCanUart_o2 >> 8);
        if (clutchSetVal > AAC_CLUTCH_NOISE_LEVEL) {
          sendAacCommand(STOP_COM);
        }

        sendClutchCommand((uint16_T)clutchSetVal);
      } else if (rtDW.UnpackCanUart_o1 == SW_ACCELERATION_GCU_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_AAC_COM;
        sendAacCommand(rtDW.UnpackCanUart_o2);
        if (rtDW.aacCommand[1] == STOP_COM) {
          sendClutchCommand(0);
        }
      } else if (rtDW.UnpackCanUart_o1 == SW_TRACTION_CONTROL_GCU_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_SET_TRACTION;
        tmp = rtDW.UnpackCanUart_o2 * 100;
        if (tmp > 65535) {
          tmp = 65535;
        }

        /* Outputs for Function Call SubSystem: '<Root>/TractionValue' */
        TractionValue((uint16_T)tmp, &rtDW.Assignment_e, &rtDW.TractionValue_h);

        /* End of Outputs for SubSystem: '<Root>/TractionValue' */
      } else if (rtDW.UnpackCanUart_o1 == SW_MODE_ID) {
        rtDW.is_c2_GCU_CAN_debug = IN_SW_CHANGE_MODE;
        sendModeCommand(rtDW.UnpackCanUart_o2);
      } else {
        rtDW.is_c2_GCU_CAN_debug = IN_IDLE;
      }
      break;

     default:
      WHEEL_SPEED_UPDATE(&tractionValue, &aac_externValues_index,
                         &aac_externValue);
      break;
    }
  }

  /* End of Chart: '<Root>/MessageEvaluation' */

  /* Outport: '<Root>/id' */
  rtY.id = rtDW.UnpackCanUart_o1;

  /* Outport: '<Root>/firstInt' */
  rtY.firstInt = rtDW.UnpackCanUart_o2;

  /* Outport: '<Root>/secondInt' */
  rtY.secondInt = rtDW.UnpackCanUart_o3;

  /* Outport: '<Root>/thirdInt' */
  rtY.thirdInt = rtDW.UnpackCanUart_o4;

  /* Outport: '<Root>/fourthInt' */
  rtY.fourthInt = rtDW.UnpackCanUart_o5;

  /* RateTransition: '<Root>/Rate Transition1' */
  if (!(rtDW.RateTransition1_semaphoreTaken != 0)) {
    rtDW.RateTransition1_Buffer0[0] = rtDW.shiftCommand[0];
    rtDW.RateTransition1_Buffer0[1] = rtDW.shiftCommand[1];
  }

  /* End of RateTransition: '<Root>/Rate Transition1' */

  /* RateTransition: '<Root>/Rate Transition11' */
  if (!(rtDW.RateTransition11_semaphoreTaken != 0)) {
    rtDW.RateTransition11_Buffer0[0] = rtDW.Assignment[0];
    rtDW.RateTransition11_Buffer0[1] = rtDW.Assignment[1];
    rtDW.RateTransition11_Buffer0[2] = rtDW.Assignment[2];
  }

  /* End of RateTransition: '<Root>/Rate Transition11' */

  /* RateTransition: '<Root>/Rate Transition2' */
  if (!(rtDW.RateTransition2_semaphoreTaken != 0)) {
    rtDW.RateTransition2_Buffer0[0] = rtDW.aacCommand[0];
    rtDW.RateTransition2_Buffer0[1] = rtDW.aacCommand[1];
  }

  /* End of RateTransition: '<Root>/Rate Transition2' */

  /* RateTransition: '<Root>/Rate Transition3' */
  if (!(rtDW.RateTransition3_semaphoreTaken != 0)) {
    rtDW.RateTransition3_Buffer0[0] = rtDW.modeCommand[0];
    rtDW.RateTransition3_Buffer0[1] = rtDW.modeCommand[1];
  }

  /* End of RateTransition: '<Root>/Rate Transition3' */

  /* RateTransition: '<Root>/Rate Transition15' */
  if (!(rtDW.RateTransition15_semaphoreTaken != 0)) {
    rtDW.RateTransition15_Buffer0[0] = rtDW.clutchCommand[0];
    rtDW.RateTransition15_Buffer0[1] = rtDW.clutchCommand[1];
  }

  /* End of RateTransition: '<Root>/Rate Transition15' */

  /* Outport: '<Root>/currGear' */
  rtY.currGear = rtDW.currGear;

  /* Outport: '<Root>/aac_externValue' */
  rtY.aac_externValue[0] = rtDW.Assignment[0];
  rtY.aac_externValue[1] = rtDW.Assignment[1];
  rtY.aac_externValue[2] = rtDW.Assignment[2];

  /* Outport: '<Root>/startEngCommand' */
  rtY.startEngCommand = rtDW.startEngCommand;

  /* Outport: '<Root>/shiftCommand' */
  rtY.shiftCommand[0] = rtDW.shiftCommand[0];

  /* Outport: '<Root>/aacCommand' */
  rtY.aacCommand[0] = rtDW.aacCommand[0];

  /* Outport: '<Root>/clutchCommand' */
  rtY.clutchCommand[0] = rtDW.clutchCommand[0];

  /* Outport: '<Root>/modeCommand' */
  rtY.modeCommand[0] = rtDW.modeCommand[0];

  /* Outport: '<Root>/shiftCommand' */
  rtY.shiftCommand[1] = rtDW.shiftCommand[1];

  /* Outport: '<Root>/aacCommand' */
  rtY.aacCommand[1] = rtDW.aacCommand[1];

  /* Outport: '<Root>/clutchCommand' */
  rtY.clutchCommand[1] = rtDW.clutchCommand[1];

  /* Outport: '<Root>/modeCommand' */
  rtY.modeCommand[1] = rtDW.modeCommand[1];

  /* Outport: '<Root>/tractionValue' */
  rtY.tractionValue = rtDW.Assignment_e;

  /* Outport: '<Root>/rpmLimiter_pin' */
  rtY.rpmLimiter_pin = rtDW.Merge;
}

/* Model step function for TID2 */
void GCU_CAN_debug_step2(void)         /* Sample time: [0.02s, 0.01s] */
{
  uint16_T rtb_RateTransition9;
  uint16_T rtb_RateTransition10;
  uint16_T rtb_RateTransition11[3];
  uint16_T rtb_RateTransition1[2];
  uint16_T rtb_RateTransition2[2];
  uint16_T rtb_RateTransition3[2];
  uint8_T rtb_RateTransition15[2];

  /* RateTransition: '<Root>/Rate Transition9' */
  rtb_RateTransition9 = rtDW.UnpackCanUart_o1;

  /* RateTransition: '<Root>/Rate Transition10' */
  rtb_RateTransition10 = rtDW.currGear;

  /* RateTransition: '<Root>/Rate Transition1' */
  rtDW.RateTransition1_semaphoreTaken = 1;
  rtb_RateTransition1[0] = rtDW.RateTransition1_Buffer0[0];
  rtb_RateTransition1[1] = rtDW.RateTransition1_Buffer0[1];
  rtDW.RateTransition1_semaphoreTaken = 0;

  /* RateTransition: '<Root>/Rate Transition11' */
  rtDW.RateTransition11_semaphoreTaken = 1;
  rtb_RateTransition11[0] = rtDW.RateTransition11_Buffer0[0];
  rtb_RateTransition11[1] = rtDW.RateTransition11_Buffer0[1];
  rtb_RateTransition11[2] = rtDW.RateTransition11_Buffer0[2];
  rtDW.RateTransition11_semaphoreTaken = 0;

  /* RateTransition: '<Root>/Rate Transition2' */
  rtDW.RateTransition2_semaphoreTaken = 1;
  rtb_RateTransition2[0] = rtDW.RateTransition2_Buffer0[0];
  rtb_RateTransition2[1] = rtDW.RateTransition2_Buffer0[1];
  rtDW.RateTransition2_semaphoreTaken = 0;

  /* RateTransition: '<Root>/Rate Transition3' */
  rtDW.RateTransition3_semaphoreTaken = 1;
  rtb_RateTransition3[0] = rtDW.RateTransition3_Buffer0[0];
  rtb_RateTransition3[1] = rtDW.RateTransition3_Buffer0[1];
  rtDW.RateTransition3_semaphoreTaken = 0;

  /* RateTransition: '<Root>/Rate Transition15' */
  rtDW.RateTransition15_semaphoreTaken = 1;
  rtb_RateTransition15[0] = rtDW.RateTransition15_Buffer0[0];
  rtb_RateTransition15[1] = rtDW.RateTransition15_Buffer0[1];
  rtDW.RateTransition15_semaphoreTaken = 0;

  /* S-Function (fcncallgen): '<Root>/Function_Call_Generator' incorporates:
   *  SubSystem: '<Root>/Debug '
   */
  /* SignalConversion: '<S2>/TmpSignal ConversionAtPack_Uart_Message1Inport1' incorporates:
   *  DataTypeConversion: '<S2>/Cast'
   *  DataTypeConversion: '<S2>/Cast1'
   *  DataTypeConversion: '<S2>/Cast2'
   *  DataTypeConversion: '<S2>/Cast3'
   *  DataTypeConversion: '<S2>/Cast4'
   *  DataTypeConversion: '<S2>/Cast5'
   *  DataTypeConversion: '<S2>/Cast6'
   *  DataTypeConversion: '<S2>/Cast7'
   *  DataTypeConversion: '<S2>/Cast8'
   *  DataTypeConversion: '<S2>/Cast9'
   */
  rtDW.TmpSignalConversionAtPack_Uart_[0] = rtb_RateTransition9;
  rtDW.TmpSignalConversionAtPack_Uart_[1] = rtb_RateTransition10;
  rtDW.TmpSignalConversionAtPack_Uart_[2] = rtb_RateTransition1[0];
  rtDW.TmpSignalConversionAtPack_Uart_[3] = rtb_RateTransition1[1];
  rtDW.TmpSignalConversionAtPack_Uart_[4] = rtb_RateTransition11[1];
  rtDW.TmpSignalConversionAtPack_Uart_[5] = rtb_RateTransition2[0];
  rtDW.TmpSignalConversionAtPack_Uart_[6] = rtb_RateTransition2[1];
  rtDW.TmpSignalConversionAtPack_Uart_[7] = rtb_RateTransition3[0];
  rtDW.TmpSignalConversionAtPack_Uart_[8] = rtb_RateTransition3[1];
  rtDW.TmpSignalConversionAtPack_Uart_[9] = rtb_RateTransition15[1];

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
   *  DataTypeConversion: '<S2>/Cast4'
   *  DataTypeConversion: '<S2>/Cast5'
   *  DataTypeConversion: '<S2>/Cast6'
   *  DataTypeConversion: '<S2>/Cast7'
   *  DataTypeConversion: '<S2>/Cast8'
   *  DataTypeConversion: '<S2>/Cast9'
   */
  rtY.debugValues[0] = rtb_RateTransition9;
  rtY.debugValues[1] = rtb_RateTransition10;
  rtY.debugValues[2] = rtb_RateTransition1[0];
  rtY.debugValues[3] = rtb_RateTransition1[1];
  rtY.debugValues[4] = rtb_RateTransition11[1];
  rtY.debugValues[5] = rtb_RateTransition2[0];
  rtY.debugValues[6] = rtb_RateTransition2[1];
  rtY.debugValues[7] = rtb_RateTransition3[0];
  rtY.debugValues[8] = rtb_RateTransition3[1];
  rtY.debugValues[9] = rtb_RateTransition15[1];

  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function_Call_Generator' */
}

/* Model initialize function */
void GCU_CAN_debug_initialize(void)
{
  /* Registration code */

  /* initialize sample time offsets */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
