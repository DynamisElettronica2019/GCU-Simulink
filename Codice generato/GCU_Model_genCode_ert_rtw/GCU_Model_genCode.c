/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GCU_Model_genCode.c
 *
 * Code generated for Simulink model 'GCU_Model_genCode'.
 *
 * Model version                  : 1.127
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Thu May 16 09:29:38 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "GCU_Model_genCode.h"

/* Named constants for Chart: '<S3>/MessageEvaluation1' */
#define AAC_CLUTCH_NOISE_LEVEL         ((uint8_T)30U)
#define EEPROM_READ_ID                 ((uint16_T)601U)
#define EEPROM_WRITE_ID                ((uint16_T)600U)
#define EFI_GEAR_RPM_TPS_APPS_ID       ((uint16_T)773U)
#define EFI_TRACTION_CONTROL_ID        ((uint16_T)774U)
#define GEAR_COMMAND_DOWN              ((uint16_T)200U)
#define GEAR_COMMAND_NEUTRAL_DOWN      ((uint16_T)100U)
#define GEAR_COMMAND_NEUTRAL_UP        ((uint16_T)50U)
#define STOP_COM                       ((uint16_T)0U)
#define SW_ACCELERATION_GCU_ID         ((uint16_T)514U)
#define SW_CLUTCH_TARGET_GCU_ID        ((uint16_T)513U)
#define SW_FIRE_GCU_ID                 ((uint16_T)516U)
#define SW_GEARSHIFT_ID                (512.0)
#define SW_MAP_ID                      ((uint16_T)602U)
#define SW_MODE_ID                     ((uint16_T)1000U)
#define SW_TRACTION_CONTROL_GCU_ID     ((uint16_T)515U)

/* Named constants for Chart: '<S4>/GCULogic' */
#define AAC_WORK_RATE_ms               ((uint16_T)25U)
#define ACC_CODE                       ((uint16_T)1U)
#define ACC_MODE                       ((uint16_T)3U)
#define AUTOCROSS_MODE                 ((uint16_T)0U)
#define ENDURANCE_MODE                 ((uint16_T)2U)
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
#define IN_Default_i                   ((uint8_T)2U)
#define IN_IDLE                        ((uint8_T)3U)
#define IN_INIT                        ((uint8_T)2U)
#define IN_INIT_k                      ((uint8_T)4U)
#define IN_MANUAL_MODES                ((uint8_T)3U)
#define IN_NEUTRAL                     ((uint8_T)1U)
#define IN_NO_NEUTRAL                  ((uint8_T)2U)
#define IN_NotReady                    ((uint8_T)2U)
#define IN_READY                       ((uint8_T)1U)
#define IN_RELEASING                   ((uint8_T)2U)
#define IN_RUNNING                     ((uint8_T)3U)
#define IN_SET_NEUTRAL                 ((uint8_T)3U)
#define IN_START                       ((uint8_T)4U)
#define IN_START_RELEASE               ((uint8_T)5U)
#define IN_START_l                     ((uint8_T)1U)
#define IN_STOP                        ((uint8_T)2U)
#define IN_STOPPING                    ((uint8_T)2U)
#define IN_SettingNeutral              ((uint8_T)2U)
#define IN_SettingNeutral_l            ((uint8_T)3U)
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

/* Named constants for Chart: '<S6>/AccelerationRoutine' */
#define IN_ActivateAac                 ((uint8_T)1U)
#define IN_CHANGE_MODE                 ((uint8_T)2U)
#define IN_DajeDeGas                   ((uint8_T)3U)
#define IN_EXIT                        ((uint8_T)4U)
#define IN_EnterAcceleration           ((uint8_T)5U)
#define IN_InsertGear                  ((uint8_T)6U)
#define IN_Ready                       ((uint8_T)7U)
#define IN_Wait                        ((uint8_T)8U)
#define IN_delay                       ((uint8_T)9U)
#include "solver_zc.h"
#include "zero_crossing_types.h"
#ifndef slZcHadEvent
#define slZcHadEvent(ev, zcsDir)       (((ev) & (zcsDir)) != 0x00 )
#endif

#ifndef slZcUnAliasEvents
#define slZcUnAliasEvents(evL, evR)    ((((slZcHadEvent((evL), (SL_ZCS_EVENT_N2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2P))) || (slZcHadEvent((evL), (SL_ZCS_EVENT_P2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2N)))) ? (SL_ZCS_EVENT_NUL) : (evR)))
#endif

const uint16_T GCU_Model_genCode_U16GND = 0U;/* uint16_T ground */

/* Block signals and states (default storage) */
DW rtDW;

/* Previous zero-crossings (trigger) states */
PrevZCX rtPrevZCX;

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

  extern void writeValueEEPROM_Start_wrapper(void);
  extern void writeValueEEPROM_Outputs_wrapper(const uint32_T *address,
    const uint16_T *value);
  extern void writeValueEEPROM_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

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

  extern void update_ADC_data_Start_wrapper(void);
  extern void update_ADC_data_Outputs_wrapper(const uint32_T *adc_buffer,
    uint32_T *adc_data_vector);
  extern void update_ADC_data_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void PackCANMsg_Start_wrapper(void);
  extern void PackCANMsg_Outputs_wrapper(const uint16_T *firstInt,
    const uint16_T *secondInt,
    const uint16_T *thirdInt,
    const uint16_T *fourthInt,
    uint8_T *dataArray);
  extern void PackCANMsg_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void sendCAN_Start_wrapper(void);
  extern void sendCAN_Outputs_wrapper(const uint16_T *id,
    const uint8_T *dataArray);
  extern void sendCAN_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Read_oil_sensor_Start_wrapper(void);
  extern void Read_oil_sensor_Outputs_wrapper(uint16_T *l_oil);
  extern void Read_oil_sensor_Terminate_wrapper(void);

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

  extern void Efi_init_Start_wrapper(void);
  extern void Efi_init_Outputs_wrapper(void);
  extern void Efi_init_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Efi_setCut_Start_wrapper(void);
  extern void Efi_setCut_Outputs_wrapper(uint8_T *upCut_pin);
  extern void Efi_setCut_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Efi_unsetCut_Start_wrapper(void);
  extern void Efi_unsetCut_Outputs_wrapper(uint8_T *upCut_pin);
  extern void Efi_unsetCut_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void GearMotor_release_Start_wrapper(void);
  extern void GearMotor_release_Outputs_wrapper(uint8_T *GearMotor_INH);
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
    uint8_T *GearMotor_INH);
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
    uint8_T *GearMotor_INH);
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
    uint8_T *GearMotor_INH);
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

#ifdef __cplusplus

extern "C" {

#endif

  extern void load_accParameters_Start_wrapper(void);
  extern void load_accParameters_Outputs_wrapper(int32_T *accParameters);
  extern void load_accParameters_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void load_default_timings_Start_wrapper(void);
  extern void load_default_timings_Outputs_wrapper(int32_T *timings);
  extern void load_default_timings_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void CAN_Start_Start_wrapper(void);
  extern void CAN_Start_Outputs_wrapper(void);
  extern void CAN_Start_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void GearMotor_init_Start_wrapper(void);
  extern void GearMotor_init_Outputs_wrapper(void);
  extern void GearMotor_init_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void InitADC_Start_wrapper(void);
  extern void InitADC_Outputs_wrapper(void);
  extern void InitADC_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void InitTimer_Start_wrapper(void);
  extern void InitTimer_Outputs_wrapper(void);
  extern void InitTimer_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void InitUART_Start_wrapper(void);
  extern void InitUART_Outputs_wrapper(void);
  extern void InitUART_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

static void Efi_setRpmLimiter(uint8_T *rty_rpmLimiter_pin, DW_Efi_setRpmLimiter *
  localDW);
static void Efi_unsetRpmLimiter(uint8_T *rty_rpmLimiter_pin,
  DW_Efi_unsetRpmLimiter *localDW);
static void AAC_ExternalValues(uint16_T rtu_Value, uint16_T rtu_Index, uint16_T
  rty_Values[3], DW_AAC_ExternalValues *localDW);
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
static void updateData(void);
static void checkGear(void);
static void sendModeCommand(uint16_T com);
static void sendAacCommand(uint16_T com);
static void sendClutchCommand(uint16_T com);
static void sendShiftCommand(uint16_T com);
static void sendStartEngCommand(void);
extern ZCEventType rt_I32ZCFcn(ZCDirection zcDir, ZCSigState *prevZc, int32_T
  currValue);

/* Detect zero crossings events. */
ZCEventType rt_I32ZCFcn(ZCDirection zcDir, ZCSigState *prevZc, int32_T currValue)
{
  slZcEventType zcsDir;
  slZcEventType tempEv;
  ZCEventType zcEvent = NO_ZCEVENT;    /* assume */

  /* zcEvent matrix */
  static const slZcEventType eventMatrix[4][4] = {
    /*          ZER              POS              NEG              UNK */
    { SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_Z2P, SL_ZCS_EVENT_Z2N, SL_ZCS_EVENT_NUL },/* ZER */

    { SL_ZCS_EVENT_P2Z, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_P2N, SL_ZCS_EVENT_NUL },/* POS */

    { SL_ZCS_EVENT_N2Z, SL_ZCS_EVENT_N2P, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL },/* NEG */

    { SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL }/* UNK */
  };

  /* get prevZcEvent and prevZcSign from prevZc */
  slZcEventType prevEv = (slZcEventType)(((uint8_T)(*prevZc)) >> 2);
  slZcSignalSignType prevSign = (slZcSignalSignType)(((uint8_T)(*prevZc)) &
    (uint8_T)0x03);

  /* get current zcSignal sign from current zcSignal value */
  slZcSignalSignType currSign = (slZcSignalSignType)((currValue) > 0 ?
    SL_ZCS_SIGN_POS :
    ((currValue) < 0 ? SL_ZCS_SIGN_NEG : SL_ZCS_SIGN_ZERO));

  /* get current zcEvent based on prev and current zcSignal value */
  slZcEventType currEv = eventMatrix[prevSign][currSign];

  /* get slZcEventType from ZCDirection */
  switch (zcDir) {
   case ANY_ZERO_CROSSING:
    zcsDir = SL_ZCS_EVENT_ALL;
    break;

   case FALLING_ZERO_CROSSING:
    zcsDir = SL_ZCS_EVENT_ALL_DN;
    break;

   case RISING_ZERO_CROSSING:
    zcsDir = SL_ZCS_EVENT_ALL_UP;
    break;

   default:
    zcsDir = SL_ZCS_EVENT_NUL;
    break;
  }

  /*had event, check if double zc happend remove double detection. */
  if (slZcHadEvent(currEv, zcsDir)) {
    currEv = (slZcEventType)(slZcUnAliasEvents(prevEv, currEv));
  } else {
    currEv = SL_ZCS_EVENT_NUL;
  }

  /* Update prevZc */
  tempEv = (slZcEventType)(currEv << 2);/* shift left by 2 bits */
  *prevZc = (ZCSigState)((currSign) | (tempEv));
  if ((currEv & SL_ZCS_EVENT_ALL_DN) != 0) {
    zcEvent = FALLING_ZCEVENT;
  } else if ((currEv & SL_ZCS_EVENT_ALL_UP) != 0) {
    zcEvent = RISING_ZCEVENT;
  } else {
    zcEvent = NO_ZCEVENT;
  }

  return zcEvent;
}                                      /* end rt_I32ZCFcn */

/*
 * Output and update for function-call system:
 *    '<S24>/Efi_setRpmLimiter'
 *    '<S29>/SetRPMLimiter'
 */
static void Efi_setRpmLimiter(uint8_T *rty_rpmLimiter_pin, DW_Efi_setRpmLimiter *
  localDW)
{
  /* S-Function (Efi_setRPMLimiter): '<S26>/Efi SetRPMLimiter' */
  Efi_setRPMLimiter_Outputs_wrapper(&localDW->EfiSetRPMLimiter);

  /* SignalConversion: '<S26>/OutportBufferForrpmLimiter_pin' */
  *rty_rpmLimiter_pin = localDW->EfiSetRPMLimiter;
}

/*
 * Output and update for function-call system:
 *    '<S24>/Efi_unsetRpmLimiter'
 *    '<S29>/UnsetRPMLimiter'
 */
static void Efi_unsetRpmLimiter(uint8_T *rty_rpmLimiter_pin,
  DW_Efi_unsetRpmLimiter *localDW)
{
  /* S-Function (Efi_unsetRPMLimiter): '<S27>/Efi UnSetRPMLimiter' */
  Efi_unsetRPMLimiter_Outputs_wrapper(&localDW->EfiUnSetRPMLimiter);

  /* SignalConversion: '<S27>/OutportBufferForrpmLimiter_pin' */
  *rty_rpmLimiter_pin = localDW->EfiUnSetRPMLimiter;
}

/* Output and update for function-call system: '<S3>/AAC_ExternalValues' */
static void AAC_ExternalValues(uint16_T rtu_Value, uint16_T rtu_Index, uint16_T
  rty_Values[3], DW_AAC_ExternalValues *localDW)
{
  /* Assignment: '<S23>/Assignment' incorporates:
   *  UnitDelay: '<S23>/Unit Delay'
   */
  rty_Values[0] = localDW->UnitDelay_DSTATE[0];
  rty_Values[1] = localDW->UnitDelay_DSTATE[1];
  rty_Values[2] = localDW->UnitDelay_DSTATE[2];
  rty_Values[rtu_Index] = rtu_Value;

  /* Update for UnitDelay: '<S23>/Unit Delay' */
  localDW->UnitDelay_DSTATE[0] = rty_Values[0];
  localDW->UnitDelay_DSTATE[1] = rty_Values[1];
  localDW->UnitDelay_DSTATE[2] = rty_Values[2];
}

/* Output and update for function-call system: '<S32>/Gearmotor_release' */
static void Gearmotor_release(void)
{
  /* S-Function (GearMotor_release): '<S44>/GearMotor Release' */
  GearMotor_release_Outputs_wrapper(&rtDW.GearMotorRelease);

  /* SignalConversion: '<S44>/OutportBufferForPin H' */
  rtDW.Pin_H = rtDW.GearMotorRelease;
}

/* Output and update for function-call system: '<S32>/Gearmotor_turnRight' */
static void Gearmotor_turnRight(uint8_T *rty_Pin_In1, uint8_T *rty_Pin_In2,
  uint8_T *rty_Pin_H, DW_Gearmotor_turnRight *localDW)
{
  /* S-Function (GearMotor_turnRight): '<S46>/GearMotor Turn Right' */
  GearMotor_turnRight_Outputs_wrapper(&localDW->GearMotorTurnRight_o1,
    &localDW->GearMotorTurnRight_o2, &localDW->GearMotorTurnRight_o3);

  /* SignalConversion: '<S46>/OutportBufferForPin_H' */
  *rty_Pin_H = localDW->GearMotorTurnRight_o3;

  /* SignalConversion: '<S46>/OutportBufferForPin_In1' */
  *rty_Pin_In1 = localDW->GearMotorTurnRight_o1;

  /* SignalConversion: '<S46>/OutportBufferForPin_In2' */
  *rty_Pin_In2 = localDW->GearMotorTurnRight_o2;
}

/* Output and update for function-call system: '<S32>/Gearmotor_brake' */
static void Gearmotor_brake(uint8_T *rty_Pin_In1, uint8_T *rty_Pin_In2, uint8_T *
  rty_Pin_H, DW_Gearmotor_brake *localDW)
{
  /* S-Function (GearMotor_brake): '<S43>/GearMotor Brake' */
  GearMotor_brake_Outputs_wrapper(&localDW->GearMotorBrake_o1,
    &localDW->GearMotorBrake_o2, &localDW->GearMotorBrake_o3);

  /* SignalConversion: '<S43>/OutportBufferForPin_H' */
  *rty_Pin_H = localDW->GearMotorBrake_o3;

  /* SignalConversion: '<S43>/OutportBufferForPin_In1' */
  *rty_Pin_In1 = localDW->GearMotorBrake_o1;

  /* SignalConversion: '<S43>/OutportBufferForPin_In2' */
  *rty_Pin_In2 = localDW->GearMotorBrake_o2;
}

/* Output and update for function-call system: '<S30>/EngineControl_Start' */
static void EngineControl_Start(uint8_T *rty_engine_starter,
  DW_EngineControl_Start *localDW)
{
  /* S-Function (EngineControl_start): '<S40>/EngineControl Start' */
  EngineControl_start_Outputs_wrapper(&localDW->EngineControlStart);

  /* SignalConversion: '<S40>/OutportBufferForengine_starter' */
  *rty_engine_starter = localDW->EngineControlStart;
}

/* Output and update for function-call system: '<S31>/sendUpdatesSW' */
static void sendUpdatesSW(uint16_T rtu_valCode, uint16_T rtu_value,
  DW_sendUpdatesSW *localDW)
{
  /* S-Function (PackCanUART): '<S42>/PackCanUart' incorporates:
   *  Constant: '<S42>/GCU_FEEDBACK_ID'
   */
  PackCanUART_Outputs_wrapper(&rtConstP.GCU_FEEDBACK_ID_Value, &rtu_valCode,
    &rtu_value, (uint16_T*)&GCU_Model_genCode_U16GND, (uint16_T*)
    &GCU_Model_genCode_U16GND, &localDW->PackCanUart[0]);
}

/* Function for Chart: '<S4>/GCULogic' */
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

/* Function for Chart: '<S4>/GCULogic' */
static int32_T Gearshift_getTime(void)
{
  int32_T time;
  if (rtDW.is_UPSHIFTING == IN_UP_START) {
    if (rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) {
      time = rtDW.Merge_m[(int32_T)DEFAULT_NT_CLUTCH_DELAY];
    } else {
      time = rtDW.Merge_m[(int32_T)DELAY];
    }
  } else if (rtDW.is_UPSHIFTING == IN_UP_PUSH) {
    if (rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) {
      time = rtDW.Merge_m[(int32_T)NT_CLUTCH_DELAY];
    } else {
      switch (rtDW.RateTransition) {
       case 1:
        time = rtDW.Merge_m[(int32_T)UP_PUSH_1_2];
        break;

       case 2:
        time = rtDW.Merge_m[(int32_T)UP_PUSH_2_3];
        break;

       case 3:
        time = rtDW.Merge_m[(int32_T)UP_PUSH_3_4];
        break;

       case 4:
        time = rtDW.Merge_m[(int32_T)UP_PUSH_4_5];
        break;

       default:
        time = rtDW.Merge_m[(int32_T)UP_PUSH_2_3];
        break;
      }
    }
  } else if (rtDW.is_UPSHIFTING == IN_UP_REBOUND) {
    if (rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) {
      time = rtDW.Merge_m[(int32_T)NT_REBOUND_1_N];
    } else {
      time = rtDW.Merge_m[(int32_T)UP_REBOUND];
    }
  } else if (rtDW.is_UPSHIFTING == IN_UP_BRAKE) {
    if (rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) {
      time = rtDW.Merge_m[(int32_T)NT_BRAKE_1_N];
    } else {
      time = rtDW.Merge_m[(int32_T)UP_BRAKE];
    }
  } else if (rtDW.is_DOWNSHIFTING == IN_DOWN_START) {
    time = rtDW.Merge_m[(int32_T)CLUTCH];
  } else if (rtDW.is_DOWNSHIFTING == IN_DOWN_PUSH) {
    time = rtDW.Merge_m[(int32_T)DN_PUSH];
  } else if (rtDW.is_DOWNSHIFTING == IN_DOWN_REBOUND) {
    time = rtDW.Merge_m[(int32_T)DN_REBOUND];
  } else {
    time = rtDW.Merge_m[(int32_T)DN_BRAKE];
  }

  return time;
}

/* Function for Chart: '<S4>/GCULogic' */
static void Clutch_setValue(uint8_T setValue)
{
  uint8_T tmp;
  rtDW.clutchCurrVal = setValue;

  /* Outputs for Function Call SubSystem: '<S28>/ClutchMotor SetPosition ' */
  /* Saturate: '<S34>/Saturation' */
  if (rtDW.clutchCurrVal < 100) {
    tmp = rtDW.clutchCurrVal;
  } else {
    tmp = 100U;
  }

  /* End of Saturate: '<S34>/Saturation' */

  /* Sum: '<S34>/Minus' incorporates:
   *  Constant: '<S34>/Constant'
   */
  rtDW.Minus = (uint8_T)(100 - tmp);

  /* S-Function (ClutchMotor_setPosition): '<S34>/ClutchMotor SetPosition' */
  ClutchMotor_setPosition_Outputs_wrapper(&rtDW.Minus);

  /* End of Outputs for SubSystem: '<S28>/ClutchMotor SetPosition ' */
}

/* Function for Chart: '<S4>/GCULogic' */
static void GEARSHIFT(void)
{
  switch (rtDW.is_GEARSHIFT) {
   case IN_DOWNSHIFTING:
    switch (rtDW.is_DOWNSHIFTING) {
     case IN_DOWN_BRAKE:
      if (rtDW.ticksCounter == 1) {
        rtDW.is_DOWN_BRAKE = 0;
        rtDW.is_DOWNSHIFTING = 0;
        rtDW.is_GEARSHIFT = 0;
        if (rtDW.is_GEARSHIFT != IN_DOWN_END) {
          rtDW.is_GEARSHIFT = IN_DOWN_END;

          /* Outputs for Function Call SubSystem: '<S32>/Gearmotor_release' */
          Gearmotor_release();

          /* End of Outputs for SubSystem: '<S32>/Gearmotor_release' */
        }
      } else if (rtDW.ticksCounter < -2147483647) {
        rtDW.ticksCounter = MIN_int32_T;
      } else {
        rtDW.ticksCounter--;
      }
      break;

     case IN_DOWN_PUSH:
      if (rtDW.ticksCounter == 1) {
        rtDW.is_DOWNSHIFTING = 0;
        if (rtDW.is_DOWNSHIFTING != IN_DOWN_REBOUND) {
          rtDW.is_DOWNSHIFTING = IN_DOWN_REBOUND;
          rtDW.ticksCounter = Gearshift_getTime();

          /* Outputs for Function Call SubSystem: '<S32>/Gearmotor_release' */
          Gearmotor_release();

          /* End of Outputs for SubSystem: '<S32>/Gearmotor_release' */
        }
      } else if (rtDW.ticksCounter < -2147483647) {
        rtDW.ticksCounter = MIN_int32_T;
      } else {
        rtDW.ticksCounter--;
      }
      break;

     case IN_DOWN_REBOUND:
      if (rtDW.ticksCounter == 1) {
        rtDW.is_DOWNSHIFTING = 0;
        if (rtDW.is_DOWNSHIFTING != IN_DOWN_BRAKE) {
          rtDW.is_DOWNSHIFTING = IN_DOWN_BRAKE;
          rtDW.ticksCounter = Gearshift_getTime();
        }

        if (rtDW.clutchCurrVal < 81) {
          if (rtDW.is_DOWN_BRAKE != IN_ChangeClutch) {
            rtDW.is_DOWN_BRAKE = IN_ChangeClutch;
            Clutch_setValue(80);

            /* Outputs for Function Call SubSystem: '<S32>/Gearmotor_brake' */
            Gearmotor_brake(&rtDW.Pin_In1, &rtDW.Pin_In2, &rtDW.Pin_H,
                            &rtDW.Gearmotor_brake_c);

            /* End of Outputs for SubSystem: '<S32>/Gearmotor_brake' */
          }
        } else {
          if (rtDW.is_DOWN_BRAKE != IN_Default_i) {
            rtDW.is_DOWN_BRAKE = IN_Default_i;

            /* Outputs for Function Call SubSystem: '<S32>/Gearmotor_brake' */
            Gearmotor_brake(&rtDW.Pin_In1, &rtDW.Pin_In2, &rtDW.Pin_H,
                            &rtDW.Gearmotor_brake_c);

            /* End of Outputs for SubSystem: '<S32>/Gearmotor_brake' */
          }
        }
      } else if (rtDW.ticksCounter < -2147483647) {
        rtDW.ticksCounter = MIN_int32_T;
      } else {
        rtDW.ticksCounter--;
      }
      break;

     case IN_DOWN_START:
      if (rtDW.ticksCounter == 1) {
        rtDW.is_DOWN_START = 0;
        rtDW.is_DOWNSHIFTING = 0;
        if (rtDW.is_DOWNSHIFTING != IN_DOWN_PUSH) {
          rtDW.is_DOWNSHIFTING = IN_DOWN_PUSH;
          rtDW.ticksCounter = Gearshift_getTime();

          /* Outputs for Function Call SubSystem: '<S32>/Gearmotor_turnLeft' */
          /* S-Function (GearMotor_turnLeft): '<S45>/GearMotor Turn Left' */
          GearMotor_turnLeft_Outputs_wrapper(&rtDW.GearMotorTurnLeft_o1,
            &rtDW.GearMotorTurnLeft_o2, &rtDW.GearMotorTurnLeft_o3);

          /* SignalConversion: '<S45>/OutportBufferForPin_H' */
          rtDW.Pin_H = rtDW.GearMotorTurnLeft_o3;

          /* SignalConversion: '<S45>/OutportBufferForPin_In1' */
          rtDW.Pin_In1 = rtDW.GearMotorTurnLeft_o1;

          /* SignalConversion: '<S45>/OutportBufferForPin_In2' */
          rtDW.Pin_In2 = rtDW.GearMotorTurnLeft_o2;

          /* End of Outputs for SubSystem: '<S32>/Gearmotor_turnLeft' */
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
    if ((rtDW.sfEvent == event_GearshiftUp) && (rtDW.RateTransition < 5)) {
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

          /* Outputs for Function Call SubSystem: '<S29>/SetCut' */

          /* S-Function (Efi_setCut): '<S36>/Efi SetCut' */
          Efi_setCut_Outputs_wrapper(&rtDW.EfiSetCut);

          /* End of Outputs for SubSystem: '<S29>/SetCut' */
        }
      }
    } else {
      if (rtDW.sfEvent == event_GearshiftDown) {
        rtDW.is_GEARSHIFT = IN_DOWNSHIFTING;
        if (rtDW.is_DOWNSHIFTING != IN_DOWN_START) {
          rtDW.is_DOWNSHIFTING = IN_DOWN_START;
          rtDW.ticksCounter = Gearshift_getTime();
        }

        if ((rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) && (rtDW.clutchCurrVal <=
             80)) {
          if (rtDW.is_DOWN_START != IN_SettingNeutral_l) {
            rtDW.is_DOWN_START = IN_SettingNeutral_l;
            Clutch_setValue(80);
          }
        } else if ((!(rtDW.is_NEUTRAL_STATE == IN_UNSET_NEUTRAL)) &&
                   (rtDW.clutchCurrVal <= 60)) {
          if (rtDW.is_DOWN_START != IN_ChangeClutch) {
            rtDW.is_DOWN_START = IN_ChangeClutch;
            Clutch_setValue(60);
          }
        } else {
          rtDW.is_DOWN_START = IN_Default_i;
        }
      }
    }
    break;

   case IN_INIT_k:
    rtDW.is_GEARSHIFT = IN_IDLE;
    break;

   case IN_UPSHIFTING:
    switch (rtDW.is_UPSHIFTING) {
     case IN_UP_BRAKE:
      if (rtDW.ticksCounter == 1) {
        rtDW.is_UPSHIFTING = 0;
        rtDW.is_GEARSHIFT = 0;
        if (rtDW.is_GEARSHIFT != IN_UP_END) {
          rtDW.is_GEARSHIFT = IN_UP_END;

          /* Outputs for Function Call SubSystem: '<S32>/Gearmotor_release' */
          Gearmotor_release();

          /* End of Outputs for SubSystem: '<S32>/Gearmotor_release' */
        }
      } else if (rtDW.ticksCounter < -2147483647) {
        rtDW.ticksCounter = MIN_int32_T;
      } else {
        rtDW.ticksCounter--;
      }
      break;

     case IN_UP_PUSH:
      if (rtDW.ticksCounter == 1) {
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

            /* Outputs for Function Call SubSystem: '<S32>/Gearmotor_release' */
            Gearmotor_release();

            /* End of Outputs for SubSystem: '<S32>/Gearmotor_release' */
          }
        } else {
          if (rtDW.is_UP_REBOUND != IN_Default) {
            rtDW.is_UP_REBOUND = IN_Default;

            /* Outputs for Function Call SubSystem: '<S32>/Gearmotor_release' */
            Gearmotor_release();

            /* End of Outputs for SubSystem: '<S32>/Gearmotor_release' */
          }
        }
      } else if (rtDW.ticksCounter < -2147483647) {
        rtDW.ticksCounter = MIN_int32_T;
      } else {
        rtDW.ticksCounter--;
      }
      break;

     case IN_UP_REBOUND:
      if (rtDW.ticksCounter == 1) {
        rtDW.is_UP_REBOUND = 0;
        rtDW.is_UPSHIFTING = 0;
        if (rtDW.is_UPSHIFTING != IN_UP_BRAKE) {
          rtDW.is_UPSHIFTING = IN_UP_BRAKE;
          rtDW.ticksCounter = Gearshift_getTime();

          /* Outputs for Function Call SubSystem: '<S32>/Gearmotor_brake' */
          Gearmotor_brake(&rtDW.Pin_In1, &rtDW.Pin_In2, &rtDW.Pin_H,
                          &rtDW.Gearmotor_brake_c);

          /* End of Outputs for SubSystem: '<S32>/Gearmotor_brake' */
        }
      } else if (rtDW.ticksCounter < -2147483647) {
        rtDW.ticksCounter = MIN_int32_T;
      } else {
        rtDW.ticksCounter--;
      }
      break;

     case IN_UP_START:
      if (rtDW.ticksCounter == 1) {
        rtDW.is_UP_START = 0;
        rtDW.is_UPSHIFTING = 0;
        if (rtDW.is_UPSHIFTING != IN_UP_PUSH) {
          rtDW.is_UPSHIFTING = IN_UP_PUSH;
          rtDW.ticksCounter = Gearshift_getTime();
        }

        if (!(rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL)) {
          if (rtDW.is_UP_PUSH != IN_CutOff) {
            rtDW.is_UP_PUSH = IN_CutOff;

            /* Outputs for Function Call SubSystem: '<S29>/UnsetCut' */

            /* S-Function (Efi_unsetCut): '<S38>/Efi UnSetCut' */
            Efi_unsetCut_Outputs_wrapper(&rtDW.EfiUnSetCut);

            /* End of Outputs for SubSystem: '<S29>/UnsetCut' */

            /* Outputs for Function Call SubSystem: '<S32>/Gearmotor_turnRight' */
            Gearmotor_turnRight(&rtDW.Pin_In1, &rtDW.Pin_In2, &rtDW.Pin_H,
                                &rtDW.Gearmotor_turnRight_f);

            /* End of Outputs for SubSystem: '<S32>/Gearmotor_turnRight' */
          }
        } else {
          if (rtDW.is_UP_PUSH != IN_Default_i) {
            rtDW.is_UP_PUSH = IN_Default_i;

            /* Outputs for Function Call SubSystem: '<S32>/Gearmotor_turnRight' */
            Gearmotor_turnRight(&rtDW.Pin_In1, &rtDW.Pin_In2, &rtDW.Pin_H,
                                &rtDW.Gearmotor_turnRight_f);

            /* End of Outputs for SubSystem: '<S32>/Gearmotor_turnRight' */
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

/* Function for Chart: '<S4>/GCULogic' */
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

/* Function for Chart: '<S4>/GCULogic' */
static int32_T getAacParam(aac_params b_index)
{
  return rtDW.Merge[b_index];
}

/* Function for Chart: '<S4>/GCULogic' */
static void aacCheckShift(void)
{
  int32_T b_previousEvent;
  if ((rtDW.lastShift == rtDW.RateTransition) && (rtDW.RateTransition1[RPM] >=
       rtDW.Merge[((int32_T)RPM_LIMIT_1_2 + rtDW.RateTransition) - 1]) &&
      (rtDW.RateTransition1[WHEEL_SPEED] >= rtDW.Merge[((int32_T)SPEED_LIMIT_1_2
        + rtDW.RateTransition) - 1])) {
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
}

/* Function for Chart: '<S4>/GCULogic' */
static void checkClutch(void)
{
  if ((rtDW.RateTransition5[0] != rtDW.lastClutchCom) && (((!(rtDW.is_GEARSHIFT ==
          IN_DOWNSHIFTING)) && (!(rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL))) ||
       (rtDW.is_NEUTRAL_STATE == IN_UNSET_NEUTRAL))) {
    rtDW.lastClutchCom = rtDW.RateTransition5[0];
    Clutch_setValue(rtDW.RateTransition5[1]);
  }
}

/* Function for Chart: '<S4>/GCULogic' */
static void enter_atomic_MANUAL_MODES(void)
{
  rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
  rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
  checkShift();
  checkClutch();
}

/* Function for Chart: '<S4>/GCULogic' */
static void ACCELERATION(void)
{
  int32_T q0;
  int32_T q1;
  int64_T tmp;
  uint8_T tmp_0;
  if ((rtDW.RateTransition8[0] != rtDW.lastModeCom[0]) && (rtDW.RateTransition8
       [1] != rtDW.lastModeCom[1])) {
    /* Outputs for Function Call SubSystem: '<S29>/UnsetRPMLimiter' */
    Efi_unsetRpmLimiter(&rtDW.Merge2, &rtDW.UnsetRPMLimiter_c);

    /* End of Outputs for SubSystem: '<S29>/UnsetRPMLimiter' */
    rtDW.accFb = 0U;
    Clutch_setValue(0);
    if (rtDW.RateTransition8[1] == AUTOCROSS_MODE) {
      rtDW.is_ACTIVE = 0;
      rtDW.is_AAC = 0;
      rtDW.is_ACCELERATION = 0;
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        enter_atomic_MANUAL_MODES();
      }
    } else if (rtDW.RateTransition8[1] == ENDURANCE_MODE) {
      rtDW.is_ACTIVE = 0;
      rtDW.is_AAC = 0;
      rtDW.is_ACCELERATION = 0;
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
        rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
        checkShift();
        checkClutch();
      }
    } else if (rtDW.RateTransition8[1] == SKIDPAD_MODE) {
      rtDW.is_ACTIVE = 0;
      rtDW.is_AAC = 0;
      rtDW.is_ACCELERATION = 0;
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
        rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
        checkShift();
        checkClutch();
      }
    } else if (rtDW.RateTransition8[1] == ACC_MODE) {
      rtDW.is_ACTIVE = 0;
      rtDW.is_AAC = 0;
      rtDW.is_ACCELERATION = 0;
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_ACCELERATION) {
        rtDW.is_MODES = IN_ACCELERATION;
        rtDW.lastAacCom = rtDW.RateTransition4[0];
        rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
        rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
      }

      if (rtDW.is_ACCELERATION != IN_NotReady) {
        rtDW.is_ACCELERATION = IN_NotReady;
        rtDW.accFb = 1U;
        checkShift();
        checkClutch();
      }
    } else {
      rtDW.is_ACTIVE = 0;
      rtDW.is_AAC = 0;
      rtDW.is_ACCELERATION = 0;
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
        rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
        checkShift();
        checkClutch();
      }
    }
  } else {
    switch (rtDW.is_ACCELERATION) {
     case IN_AAC:
      switch (rtDW.is_AAC) {
       case IN_ACTIVE:
        if ((rtDW.RateTransition4[0] != rtDW.lastAacCom) &&
            (rtDW.RateTransition4[1] == STOP_AAC_COM)) {
          rtDW.lastAacCom = rtDW.RateTransition4[0];
          rtDW.is_ACTIVE = 0;
          rtDW.is_AAC = 0;
          if (rtDW.is_AAC != IN_STOPPING) {
            rtDW.is_AAC = IN_STOPPING;

            /* Outputs for Function Call SubSystem: '<S29>/UnsetRPMLimiter' */
            Efi_unsetRpmLimiter(&rtDW.Merge2, &rtDW.UnsetRPMLimiter_c);

            /* End of Outputs for SubSystem: '<S29>/UnsetRPMLimiter' */
            Clutch_setValue(0);

            /* sendUpdatesSW(ACC_CODE, uint16(0)); */
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

                  /* Outputs for Function Call SubSystem: '<S31>/sendUpdatesSW' */
                  sendUpdatesSW(rtDW.valCode, rtDW.value, &rtDW.sendUpdatesSW_e);

                  /* End of Outputs for SubSystem: '<S31>/sendUpdatesSW' */
                }
              } else {
                rtDW.is_ACTIVE = 0;
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

                /* Outputs for Function Call SubSystem: '<S29>/UnsetRPMLimiter' */
                Efi_unsetRpmLimiter(&rtDW.Merge2, &rtDW.UnsetRPMLimiter_c);

                /* End of Outputs for SubSystem: '<S29>/UnsetRPMLimiter' */
                rtDW.is_ACTIVE = 0;
                if (rtDW.is_ACTIVE != IN_RUNNING) {
                  rtDW.is_ACTIVE = IN_RUNNING;
                  rtDW.aacCounter = AAC_WORK_RATE_ms;
                  rtDW.lastShift = rtDW.RateTransition;
                  aacCheckShift();
                }
              } else {
                rtDW.is_ACTIVE = 0;
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
            if (rtDW.RateTransition == 5) {
              rtDW.is_ACTIVE = 0;
              rtDW.is_AAC = 0;
              if (rtDW.is_AAC != IN_STOPPING) {
                rtDW.is_AAC = IN_STOPPING;

                /* Outputs for Function Call SubSystem: '<S29>/UnsetRPMLimiter' */
                Efi_unsetRpmLimiter(&rtDW.Merge2, &rtDW.UnsetRPMLimiter_c);

                /* End of Outputs for SubSystem: '<S29>/UnsetRPMLimiter' */
                Clutch_setValue(0);

                /* sendUpdatesSW(ACC_CODE, uint16(0)); */
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
              rtDW.is_ACTIVE = 0;
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
        rtDW.is_AAC = 0;
        rtDW.is_ACCELERATION = 0;
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
      if ((rtDW.RateTransition4[0] != rtDW.lastAacCom) && (rtDW.RateTransition4
           [1] == START_AAC_COM)) {
        rtDW.lastAacCom = rtDW.RateTransition4[0];
        rtDW.is_ACCELERATION = IN_AAC;
        rtDW.aacCounter = 0U;
        rtDW.aac_clutchValue = 0.0;
        rtDW.aac_clutchStep = 0.0;
        rtDW.aac_dtRelease = 0;
        rtDW.is_AAC = IN_ACTIVE;
        if (rtDW.is_ACTIVE != IN_START) {
          rtDW.is_ACTIVE = IN_START;
          rtDW.accFb = 2U;
          rtDW.aacCounter = AAC_WORK_RATE_ms;

          /* Outputs for Function Call SubSystem: '<S29>/SetRPMLimiter' */
          Efi_setRpmLimiter(&rtDW.Merge2, &rtDW.SetRPMLimiter_e);

          /* End of Outputs for SubSystem: '<S29>/SetRPMLimiter' */
          Clutch_setValue(100);
          rtDW.valCode = ACC_CODE;
          rtDW.value = 1U;

          /* Outputs for Function Call SubSystem: '<S31>/sendUpdatesSW' */
          sendUpdatesSW(rtDW.valCode, rtDW.value, &rtDW.sendUpdatesSW_e);

          /* End of Outputs for SubSystem: '<S31>/sendUpdatesSW' */
        }
      } else {
        rtDW.accFb = 1U;
        checkShift();
        checkClutch();
      }
      break;
    }
  }
}

/* Function for Chart: '<S4>/GCULogic' */
static void MODES(void)
{
  switch (rtDW.is_MODES) {
   case IN_ACCELERATION:
    ACCELERATION();
    break;

   case IN_INIT:
    if (rtDW.RateTransition8[1] == AUTOCROSS_MODE) {
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
        rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
        checkShift();
        checkClutch();
      }
    } else if (rtDW.RateTransition8[1] == ENDURANCE_MODE) {
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
        rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
        checkShift();
        checkClutch();
      }
    } else if (rtDW.RateTransition8[1] == SKIDPAD_MODE) {
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
        rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
        checkShift();
        checkClutch();
      }
    } else if (rtDW.RateTransition8[1] == ACC_MODE) {
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_ACCELERATION) {
        rtDW.is_MODES = IN_ACCELERATION;
        rtDW.lastAacCom = rtDW.RateTransition4[0];
        rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
        rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
      }

      if (rtDW.is_ACCELERATION != IN_NotReady) {
        rtDW.is_ACCELERATION = IN_NotReady;
        rtDW.accFb = 1U;
        checkShift();
        checkClutch();
      }
    } else {
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
        rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
        checkShift();
        checkClutch();
      }
    }
    break;

   case IN_MANUAL_MODES:
    if ((rtDW.RateTransition8[0] != rtDW.lastModeCom[0]) &&
        (rtDW.RateTransition8[1] != rtDW.lastModeCom[1])) {
      if (rtDW.RateTransition8[1] == AUTOCROSS_MODE) {
        rtDW.is_MODES = 0;
        if (rtDW.is_MODES != IN_MANUAL_MODES) {
          rtDW.is_MODES = IN_MANUAL_MODES;
          rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
          rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
          checkShift();
          checkClutch();
        }
      } else if (rtDW.RateTransition8[1] == ENDURANCE_MODE) {
        rtDW.is_MODES = 0;
        if (rtDW.is_MODES != IN_MANUAL_MODES) {
          rtDW.is_MODES = IN_MANUAL_MODES;
          rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
          rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
          checkShift();
          checkClutch();
        }
      } else if (rtDW.RateTransition8[1] == SKIDPAD_MODE) {
        rtDW.is_MODES = 0;
        if (rtDW.is_MODES != IN_MANUAL_MODES) {
          rtDW.is_MODES = IN_MANUAL_MODES;
          rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
          rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
          checkShift();
          checkClutch();
        }
      } else if (rtDW.RateTransition8[1] == ACC_MODE) {
        rtDW.is_MODES = 0;
        if (rtDW.is_MODES != IN_ACCELERATION) {
          rtDW.is_MODES = IN_ACCELERATION;
          rtDW.lastAacCom = rtDW.RateTransition4[0];
          rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
          rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
        }

        if (rtDW.is_ACCELERATION != IN_NotReady) {
          rtDW.is_ACCELERATION = IN_NotReady;
          rtDW.accFb = 1U;
          checkShift();
          checkClutch();
        }
      } else {
        rtDW.is_MODES = 0;
        if (rtDW.is_MODES != IN_MANUAL_MODES) {
          rtDW.is_MODES = IN_MANUAL_MODES;
          rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
          rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
          checkShift();
          checkClutch();
        }
      }
    } else {
      checkShift();
      checkClutch();
    }
    break;
  }
}

/* Function for Chart: '<S6>/AccelerationRoutine' */
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

/* Function for Chart: '<S6>/AccelerationRoutine' */
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

/* Function for Chart: '<S3>/MessageEvaluation1' */
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

/* Function for Chart: '<S3>/MessageEvaluation1' */
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

/* Function for Chart: '<S3>/MessageEvaluation1' */
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

/* Function for Chart: '<S3>/MessageEvaluation1' */
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
  if ((rtDW.RateTransition6 != 100) && ((com == GEAR_COMMAND_NEUTRAL_UP) || (com
        == GEAR_COMMAND_NEUTRAL_DOWN) || (com == GEAR_COMMAND_DOWN))) {
    sendAacCommand(STOP_COM);
  }
}

/* Function for Chart: '<S3>/MessageEvaluation1' */
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

/* Model step function for TID0 */
void GCU_Model_genCode_step0(void)     /* Sample time: [0.00020000000000000009s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void GCU_Model_genCode_step1(void)     /* Sample time: [0.001s, 0.0s] */
{
  ZCEventType zcEvent[23];
  ZCEventType zcEvent_0[11];
  int32_T rtb_RateTransition1;
  int32_T rtb_RateTransition;
  uint8_T Merge_b;
  int32_T i;
  boolean_T tmp;
  ZCEventType zcEvent_idx_0;
  ZCEventType zcEvent_idx_1;

  /* Outputs for Triggered SubSystem: '<S18>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S22>/Trigger'
   */
  for (i = 0; i < 23; i++) {
    zcEvent[i] = rt_I32ZCFcn(ANY_ZERO_CROSSING,
      &rtPrevZCX.TriggeredSubsystem_Trig_ZCE[i],
      (rtDW.load_default_timings[i]));
  }

  tmp = false;
  for (i = 0; i < 23; i++) {
    tmp = (tmp || (zcEvent[i] != NO_ZCEVENT));
  }

  if (tmp) {
    /* Inport: '<S22>/In1' */
    memcpy(&rtDW.Merge_m[0], &rtDW.load_default_timings[0], 23U * sizeof(int32_T));
  }

  /* End of Outputs for SubSystem: '<S18>/Triggered Subsystem' */

  /* Outputs for Triggered SubSystem: '<S17>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S20>/Trigger'
   */
  for (i = 0; i < 11; i++) {
    zcEvent_0[i] = rt_I32ZCFcn(ANY_ZERO_CROSSING,
      &rtPrevZCX.TriggeredSubsystem_Trig_ZCE_j[i],
      (rtDW.load_accParameters[i]));
  }

  tmp = false;
  for (i = 0; i < 11; i++) {
    tmp = (tmp || (zcEvent_0[i] != NO_ZCEVENT));
  }

  if (tmp) {
    /* Inport: '<S20>/In1' */
    for (i = 0; i < 11; i++) {
      rtDW.Merge[i] = rtDW.load_accParameters[i];
    }

    /* End of Inport: '<S20>/In1' */
  }

  /* End of Outputs for SubSystem: '<S17>/Triggered Subsystem' */

  /* RateTransition: '<S17>/Rate Transition1' */
  rtb_RateTransition1 = rtDW.RateTransition1_Buffer0;

  /* RateTransition: '<S17>/Rate Transition' */
  rtb_RateTransition = rtDW.RateTransition_Buffer0;

  /* Outputs for Triggered SubSystem: '<S17>/ ' incorporates:
   *  TriggerPort: '<S19>/Trigger'
   */
  zcEvent_idx_0 = rt_I32ZCFcn(ANY_ZERO_CROSSING,&rtPrevZCX._Trig_ZCE_i[0],
    (rtb_RateTransition1));
  zcEvent_idx_1 = rt_I32ZCFcn(ANY_ZERO_CROSSING,&rtPrevZCX._Trig_ZCE_i[1],
    (rtb_RateTransition));
  if ((zcEvent_idx_0 != NO_ZCEVENT) || (zcEvent_idx_1 != NO_ZCEVENT)) {
    /* DataTypeConversion: '<S19>/Cast' */
    rtDW.Cast_m = (uint32_T)rtb_RateTransition1;

    /* DataTypeConversion: '<S19>/Cast1' */
    rtDW.Cast1_m = (uint16_T)rtb_RateTransition;

    /* S-Function (writeValueEEPROM): '<S19>/writeValueEEPROM' */
    writeValueEEPROM_Outputs_wrapper(&rtDW.Cast_m, &rtDW.Cast1_m);

    /* Assignment: '<S19>/Assignment' incorporates:
     *  UnitDelay: '<S17>/Unit Delay'
     */
    for (i = 0; i < 11; i++) {
      rtDW.Merge[i] = rtDW.UnitDelay_DSTATE_j[i];
    }

    rtDW.Merge[rtb_RateTransition1] = rtb_RateTransition;

    /* End of Assignment: '<S19>/Assignment' */
  }

  /* End of Outputs for SubSystem: '<S17>/ ' */

  /* RateTransition: '<S18>/Rate Transition1' */
  rtb_RateTransition1 = rtDW.RateTransition1_Buffer0_m;

  /* RateTransition: '<S18>/Rate Transition' */
  rtb_RateTransition = rtDW.RateTransition_Buffer0_e;

  /* Outputs for Triggered SubSystem: '<S18>/ ' incorporates:
   *  TriggerPort: '<S21>/Trigger'
   */
  zcEvent_idx_0 = rt_I32ZCFcn(ANY_ZERO_CROSSING,&rtPrevZCX._Trig_ZCE[0],
    (rtb_RateTransition1));
  zcEvent_idx_1 = rt_I32ZCFcn(ANY_ZERO_CROSSING,&rtPrevZCX._Trig_ZCE[1],
    (rtb_RateTransition));
  if ((zcEvent_idx_0 != NO_ZCEVENT) || (zcEvent_idx_1 != NO_ZCEVENT)) {
    /* DataTypeConversion: '<S21>/Cast' */
    rtDW.Cast = (uint32_T)rtb_RateTransition1;

    /* DataTypeConversion: '<S21>/Cast1' */
    rtDW.Cast1_i = (uint16_T)rtb_RateTransition;

    /* S-Function (writeValueEEPROM): '<S21>/writeValueEEPROM' */
    writeValueEEPROM_Outputs_wrapper(&rtDW.Cast, &rtDW.Cast1_i);

    /* Assignment: '<S21>/Assignment' incorporates:
     *  UnitDelay: '<S18>/Unit Delay'
     */
    memcpy(&rtDW.Merge_m[0], &rtDW.UnitDelay_DSTATE[0], 23U * sizeof(int32_T));
    rtDW.Merge_m[rtb_RateTransition1] = rtb_RateTransition;
  }

  /* End of Outputs for SubSystem: '<S18>/ ' */

  /* RateTransition: '<Root>/Rate Transition' */
  rtDW.RateTransition = rtDW.RateTransition_Buffer0_b;

  /* RateTransition: '<Root>/Rate Transition1' */
  i = rtDW.RateTransition1_ActiveBufIdx * 3;
  rtDW.RateTransition1[0] = rtDW.RateTransition1_Buffer[i];
  rtDW.RateTransition1[1] = rtDW.RateTransition1_Buffer[1 + i];
  rtDW.RateTransition1[2] = rtDW.RateTransition1_Buffer[2 + i];

  /* RateTransition: '<Root>/Rate Transition2' */
  i = rtDW.RateTransition2_ActiveBufIdx << 1;
  rtDW.RateTransition2[0] = rtDW.RateTransition2_Buffer[i];
  rtDW.RateTransition2[1] = rtDW.RateTransition2_Buffer[1 + i];

  /* RateTransition: '<Root>/Rate Transition3' */
  rtDW.RateTransition3 = rtDW.RateTransition3_Buffer0;

  /* RateTransition: '<Root>/Rate Transition4' */
  i = rtDW.RateTransition4_ActiveBufIdx << 1;
  rtDW.RateTransition4[0] = rtDW.RateTransition4_Buffer[i];
  rtDW.RateTransition4[1] = rtDW.RateTransition4_Buffer[1 + i];

  /* RateTransition: '<Root>/Rate Transition5' */
  i = rtDW.RateTransition5_ActiveBufIdx << 1;
  rtDW.RateTransition5[0] = rtDW.RateTransition5_Buffer[i];
  rtDW.RateTransition5[1] = rtDW.RateTransition5_Buffer[1 + i];

  /* RateTransition: '<Root>/Rate Transition8' */
  i = rtDW.RateTransition8_ActiveBufIdx << 1;
  rtDW.RateTransition8[0] = rtDW.RateTransition8_Buffer[i];
  rtDW.RateTransition8[1] = rtDW.RateTransition8_Buffer[1 + i];

  /* Outputs for Atomic SubSystem: '<Root>/GCU_timer' */
  /* Chart: '<S4>/GCULogic' */
  rtDW.sfEvent = -1;
  if (rtDW.is_active_c1_GCU_Model_genCode == 0U) {
    rtDW.is_active_c1_GCU_Model_genCode = 1U;
    rtDW.is_active_MODES = 1U;
    rtDW.lastAacCom = 0U;
    rtDW.lastShiftCom = 0U;
    rtDW.lastClutchCom = 0U;
    rtDW.is_MODES = IN_INIT;
    rtDW.is_active_NEUTRAL_STATE = 1U;
    rtDW.is_NEUTRAL_STATE = IN_NEUTRAL;
    rtDW.is_active_GEARSHIFT = 1U;
    rtDW.ticksCounter = 0;
    if (rtDW.is_GEARSHIFT != IN_INIT_k) {
      rtDW.is_GEARSHIFT = IN_INIT_k;
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
       case IN_START_l:
        if (rtDW.startCounter <= 0) {
          rtDW.is_START_ENGINE = 0;
          if (rtDW.is_START_ENGINE != IN_STOP) {
            rtDW.is_START_ENGINE = IN_STOP;

            /* Outputs for Function Call SubSystem: '<S30>/EngineControl_Stop' */

            /* S-Function (EngineControl_stop): '<S41>/EngineControl Stop' */
            EngineControl_stop_Outputs_wrapper(&rtDW.EngineControlStop);

            /* End of Outputs for SubSystem: '<S30>/EngineControl_Stop' */
          }
        } else if (rtDW.RateTransition3 != rtDW.lastCom) {
          rtDW.is_START_ENGINE = 0;
          if (rtDW.is_START_ENGINE != IN_START_l) {
            rtDW.is_START_ENGINE = IN_START_l;

            /* Outputs for Function Call SubSystem: '<S30>/EngineControl_Start' */
            EngineControl_Start(&Merge_b, &rtDW.EngineControl_Start_h);

            /* End of Outputs for SubSystem: '<S30>/EngineControl_Start' */
            rtDW.lastCom = rtDW.RateTransition3;
            rtDW.startCounter = 100U;
          }
        } else {
          i = rtDW.startCounter - 1;
          if (i < 0) {
            i = 0;
          }

          rtDW.startCounter = (uint8_T)i;
        }
        break;

       case IN_STOP:
        if (rtDW.RateTransition3 != rtDW.lastCom) {
          rtDW.is_START_ENGINE = 0;
          if (rtDW.is_START_ENGINE != IN_START_l) {
            rtDW.is_START_ENGINE = IN_START_l;

            /* Outputs for Function Call SubSystem: '<S30>/EngineControl_Start' */
            EngineControl_Start(&Merge_b, &rtDW.EngineControl_Start_h);

            /* End of Outputs for SubSystem: '<S30>/EngineControl_Start' */
            rtDW.lastCom = rtDW.RateTransition3;
            rtDW.startCounter = 100U;
          }
        }
        break;

       case IN_WAIT:
        if (rtDW.RateTransition3 != rtDW.lastCom) {
          rtDW.is_START_ENGINE = 0;
          if (rtDW.is_START_ENGINE != IN_START_l) {
            rtDW.is_START_ENGINE = IN_START_l;

            /* Outputs for Function Call SubSystem: '<S30>/EngineControl_Start' */
            EngineControl_Start(&Merge_b, &rtDW.EngineControl_Start_h);

            /* End of Outputs for SubSystem: '<S30>/EngineControl_Start' */
            rtDW.lastCom = rtDW.RateTransition3;
            rtDW.startCounter = 100U;
          }
        }
        break;
      }
    }
  }

  /* End of Chart: '<S4>/GCULogic' */
  /* End of Outputs for SubSystem: '<Root>/GCU_timer' */

  /* Outputs for Triggered SubSystem: '<S9>/Triggered_Subsystem' incorporates:
   *  TriggerPort: '<S48>/Trigger'
   */
  if (((rtDW.Merge2 > 0) != (rtPrevZCX.Triggered_Subsystem_Trig_ZCE == POS_ZCSIG))
      && (rtPrevZCX.Triggered_Subsystem_Trig_ZCE != UNINITIALIZED_ZCSIG)) {
    /* Inport: '<S48>/In1' */
    rtDW.Merge_j = rtDW.Merge2;
  }

  rtPrevZCX.Triggered_Subsystem_Trig_ZCE = (ZCSigState)(rtDW.Merge2 > 0);

  /* End of Outputs for SubSystem: '<S9>/Triggered_Subsystem' */

  /* Outputs for Triggered SubSystem: '<S9>/Triggered_Subsystem1' incorporates:
   *  TriggerPort: '<S49>/Trigger'
   */
  /* RateTransition: '<S9>/Rate Transition' incorporates:
   *  Inport: '<S49>/In1'
   */
  if (((rtDW.RateTransition_Buffer0_g > 0) !=
       (rtPrevZCX.Triggered_Subsystem1_Trig_ZCE == POS_ZCSIG)) &&
      (rtPrevZCX.Triggered_Subsystem1_Trig_ZCE != UNINITIALIZED_ZCSIG)) {
    rtDW.Merge_j = rtDW.RateTransition_Buffer0_g;
  }

  rtPrevZCX.Triggered_Subsystem1_Trig_ZCE = (ZCSigState)
    (rtDW.RateTransition_Buffer0_g > 0);

  /* End of RateTransition: '<S9>/Rate Transition' */
  /* End of Outputs for SubSystem: '<S9>/Triggered_Subsystem1' */

  /* Update for UnitDelay: '<S18>/Unit Delay' */
  memcpy(&rtDW.UnitDelay_DSTATE[0], &rtDW.Merge_m[0], 23U * sizeof(int32_T));

  /* Update for UnitDelay: '<S17>/Unit Delay' */
  for (i = 0; i < 11; i++) {
    rtDW.UnitDelay_DSTATE_j[i] = rtDW.Merge[i];
  }

  /* End of Update for UnitDelay: '<S17>/Unit Delay' */
}

/* Model step function for TID2 */
void GCU_Model_genCode_step2(void)     /* Sample time: [0.001s, 0.0002s] */
{
  uint8_T clutchSetVal;
  int32_T rtb_Cast1;
  int32_T rtb_Cast_h;
  int32_T rtb_Cast1_i;
  int32_T i;

  /* RateTransition: '<Root>/Rate Transition7' */
  rtDW.RateTransition7 = rtDW.Pin_In1;

  /* Outputs for Atomic SubSystem: '<Root>/Simulink_Debug' */
  /* Chart: '<S6>/AccelerationRoutine' */
  switch (rtDW.is_c3_GCU_Model_genCode) {
   case IN_ActivateAac:
    rtDW.is_c3_GCU_Model_genCode = IN_InsertGear;
    rtDW.id = 512U;
    rtDW.firstInt = 400U;
    break;

   case IN_CHANGE_MODE:
   case IN_EXIT:
    break;

   case IN_DajeDeGas:
    if (rtDW.currGear_m == 4) {
      rtDW.is_c3_GCU_Model_genCode = IN_CHANGE_MODE;
      rtDW.id = 1000U;
      rtDW.firstInt = 2U;
    } else {
      updateData();
    }
    break;

   case IN_EnterAcceleration:
    rtDW.is_c3_GCU_Model_genCode = IN_ActivateAac;
    rtDW.id = 514U;
    rtDW.firstInt = 1U;
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
    rtDW.count = 0.0;
    break;

   default:
    if (rtDW.count == 10.0) {
      rtDW.is_c3_GCU_Model_genCode = IN_EnterAcceleration;
      rtDW.id = 1000U;
      rtDW.firstInt = 3U;
    } else {
      rtDW.count++;
    }
    break;
  }

  /* End of Chart: '<S6>/AccelerationRoutine' */

  /* S-Function (PackCanUART): '<S6>/PackCanUart' */
  PackCanUART_Outputs_wrapper(&rtDW.id, &rtDW.firstInt, &rtDW.secondInt,
    (uint16_T*)&GCU_Model_genCode_U16GND, (uint16_T*)&GCU_Model_genCode_U16GND,
    &rtDW.PackCanUart[0]);

  /* End of Outputs for SubSystem: '<Root>/Simulink_Debug' */

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  Inport: '<Root>/CAN'
   *  Inport: '<Root>/SelectMode'
   *  Inport: '<Root>/UART_debug'
   */
  switch ((int32_T)rtU.SelectMode) {
   case 1:
    for (i = 0; i < 10; i++) {
      rtDW.MultiportSwitch[i] = rtU.UART_debug[i];
    }
    break;

   case 2:
    for (i = 0; i < 10; i++) {
      rtDW.MultiportSwitch[i] = rtU.CAN[i];
    }
    break;

   default:
    for (i = 0; i < 10; i++) {
      rtDW.MultiportSwitch[i] = rtDW.PackCanUart[i];
    }
    break;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

  /* RateTransition: '<Root>/Rate Transition6' */
  rtDW.RateTransition6 = rtDW.clutchCurrVal;

  /* Outputs for Atomic SubSystem: '<Root>/GCU_CAN_Read' */
  /* S-Function (UnpackCanUART): '<S3>/UnpackCanUart' */
  UnpackCanUART_Outputs_wrapper(&rtDW.MultiportSwitch[0], &rtDW.UnpackCanUart_o1,
    &rtDW.UnpackCanUart_o2, &rtDW.UnpackCanUart_o3, &rtDW.UnpackCanUart_o4,
    &rtDW.UnpackCanUart_o5);

  /* Chart: '<S3>/MessageEvaluation1' */
  if (rtDW.UnpackCanUart_o1 == EFI_GEAR_RPM_TPS_APPS_ID) {
    rtDW.currGear = rtDW.UnpackCanUart_o2;

    /* Outputs for Function Call SubSystem: '<S3>/AAC_ExternalValues' */
    AAC_ExternalValues(rtDW.UnpackCanUart_o3, (uint16_T)RPM, rtDW.Assignment,
                       &rtDW.AAC_ExternalValues_f);

    /* End of Outputs for SubSystem: '<S3>/AAC_ExternalValues' */
  } else if (rtDW.UnpackCanUart_o1 == SW_FIRE_GCU_ID) {
    sendStartEngCommand();
  } else if (rtDW.UnpackCanUart_o1 == (int32_T)SW_GEARSHIFT_ID) {
    sendShiftCommand(rtDW.UnpackCanUart_o2);
  } else if (rtDW.UnpackCanUart_o1 == EFI_TRACTION_CONTROL_ID) {
    /* Outputs for Function Call SubSystem: '<S3>/AAC_ExternalValues' */
    AAC_ExternalValues((uint16_T)(rtDW.UnpackCanUart_o2 / 10U), (uint16_T)
                       WHEEL_SPEED, rtDW.Assignment, &rtDW.AAC_ExternalValues_f);

    /* End of Outputs for SubSystem: '<S3>/AAC_ExternalValues' */
  } else if (rtDW.UnpackCanUart_o1 == SW_CLUTCH_TARGET_GCU_ID) {
    clutchSetVal = (uint8_T)(rtDW.UnpackCanUart_o2 >> 8);
    if (clutchSetVal > AAC_CLUTCH_NOISE_LEVEL) {
      sendAacCommand(STOP_COM);
    }

    sendClutchCommand((uint16_T)clutchSetVal);
  } else if (rtDW.UnpackCanUart_o1 == SW_ACCELERATION_GCU_ID) {
    sendAacCommand(rtDW.UnpackCanUart_o2);
    if (rtDW.aacCommand[1] == STOP_COM) {
      sendClutchCommand(0);
    }
  } else if (rtDW.UnpackCanUart_o1 == SW_TRACTION_CONTROL_GCU_ID) {
    i = rtDW.UnpackCanUart_o2 * 100;
    if (i > 65535) {
      i = 65535;
    }

    rtDW.tractionValue = (uint16_T)i;
  } else if (rtDW.UnpackCanUart_o1 == SW_MAP_ID) {
    rtDW.mapValue = rtDW.UnpackCanUart_o2;
  } else if (rtDW.UnpackCanUart_o1 == SW_MODE_ID) {
    sendModeCommand(rtDW.UnpackCanUart_o2);
  } else {
    if (!((rtDW.UnpackCanUart_o1 == EEPROM_READ_ID) || (!(rtDW.UnpackCanUart_o1 ==
           EEPROM_WRITE_ID)))) {
      rtDW.accParametersIndex = rtDW.UnpackCanUart_o2;
      rtDW.accParametersValue = rtDW.UnpackCanUart_o3;
      rtDW.timingsIndex = rtDW.UnpackCanUart_o4;
      rtDW.timingsValue = rtDW.UnpackCanUart_o5;
    }
  }

  /* End of Chart: '<S3>/MessageEvaluation1' */
  /* End of Outputs for SubSystem: '<Root>/GCU_CAN_Read' */

  /* RateTransition: '<Root>/Rate Transition14' */
  if (!(rtDW.RateTransition14_semaphoreTaken != 0)) {
    rtDW.RateTransition14_Buffer0[0] = rtDW.Assignment[0];
    rtDW.RateTransition14_Buffer0[1] = rtDW.Assignment[1];
    rtDW.RateTransition14_Buffer0[2] = rtDW.Assignment[2];
  }

  /* End of RateTransition: '<Root>/Rate Transition14' */

  /* DataTypeConversion: '<S17>/Cast' */
  i = rtDW.accParametersIndex;

  /* DataTypeConversion: '<S17>/Cast1' */
  rtb_Cast1 = rtDW.accParametersValue;

  /* DataTypeConversion: '<S18>/Cast' */
  rtb_Cast_h = rtDW.timingsIndex;

  /* DataTypeConversion: '<S18>/Cast1' */
  rtb_Cast1_i = rtDW.timingsValue;

  /* Update for RateTransition: '<S17>/Rate Transition1' */
  rtDW.RateTransition1_Buffer0 = i;

  /* Update for RateTransition: '<S17>/Rate Transition' */
  rtDW.RateTransition_Buffer0 = rtb_Cast1;

  /* Update for RateTransition: '<S18>/Rate Transition1' */
  rtDW.RateTransition1_Buffer0_m = rtb_Cast_h;

  /* Update for RateTransition: '<S18>/Rate Transition' */
  rtDW.RateTransition_Buffer0_e = rtb_Cast1_i;

  /* Update for RateTransition: '<Root>/Rate Transition' incorporates:
   *  DataTypeConversion: '<Root>/Cast'
   */
  rtDW.RateTransition_Buffer0_b = (uint8_T)rtDW.currGear;

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

  /* Update for RateTransition: '<Root>/Rate Transition8' */
  rtDW.RateTransition8_Buffer[(rtDW.RateTransition8_ActiveBufIdx == 0) << 1] =
    rtDW.modeCommand[0];
  rtDW.RateTransition8_Buffer[1 + ((rtDW.RateTransition8_ActiveBufIdx == 0) << 1)]
    = rtDW.modeCommand[1];
  rtDW.RateTransition8_ActiveBufIdx = (int8_T)(rtDW.RateTransition8_ActiveBufIdx
    == 0);

  /* Update for RateTransition: '<S9>/Rate Transition' */
  rtDW.RateTransition_Buffer0_g = rtDW.Merge_i;
}

/* Model step function for TID3 */
void GCU_Model_genCode_step3(void)     /* Sample time: [0.001s, 0.0004s] */
{
  uint16_T rtb_RateTransition12;
  uint16_T rtb_RateTransition25;
  uint8_T rtb_RateTransition11;
  uint16_T rtb_RateTransition16;
  uint16_T rtb_RateTransition13;
  uint8_T rtb_RateTransition15;
  uint8_T rtb_RateTransition17;
  uint8_T rtb_RateTransition24;
  uint16_T rtb_RateTransition27;
  uint32_T rtb_RateTransition9[9];
  uint8_T rtb_RateTransition10;
  uint16_T rtb_RateTransition14[3];
  uint16_T Cast_n[9];
  int32_T i;
  int32_T i_0;
  uint16_T Cast_n_0;

  /* RateTransition: '<Root>/Rate Transition14' */
  rtDW.RateTransition14_semaphoreTaken = 1;
  rtb_RateTransition14[0] = rtDW.RateTransition14_Buffer0[0];
  rtb_RateTransition14[1] = rtDW.RateTransition14_Buffer0[1];
  rtb_RateTransition14[2] = rtDW.RateTransition14_Buffer0[2];
  rtDW.RateTransition14_semaphoreTaken = 0;

  /* RateTransition: '<Root>/Rate Transition12' */
  rtb_RateTransition12 = rtDW.tractionValue;

  /* RateTransition: '<Root>/Rate Transition25' */
  rtb_RateTransition25 = rtDW.mapValue;

  /* RateTransition: '<Root>/Rate Transition11' */
  rtb_RateTransition11 = rtDW.clutchCurrVal;

  /* RateTransition: '<Root>/Rate Transition16' */
  rtb_RateTransition16 = rtDW.accFb;

  /* RateTransition: '<Root>/Rate Transition13' */
  rtb_RateTransition13 = rtDW.lastModeCom[1];

  /* RateTransition: '<Root>/Rate Transition15' */
  rtb_RateTransition15 = rtDW.Pin_In1;

  /* RateTransition: '<Root>/Rate Transition17' */
  rtb_RateTransition17 = rtDW.Pin_In2;

  /* RateTransition: '<Root>/Rate Transition24' */
  rtb_RateTransition24 = rtDW.Pin_H;

  /* RateTransition: '<Root>/Rate Transition27' */
  rtb_RateTransition27 = rtDW.RateTransition27_Buffer0;

  /* RateTransition: '<Root>/Rate Transition9' */
  i = rtDW.RateTransition9_ActiveBufIdx * 9;
  for (i_0 = 0; i_0 < 9; i_0++) {
    rtb_RateTransition9[i_0] = rtDW.RateTransition9_Buffer[i_0 + i];
  }

  /* End of RateTransition: '<Root>/Rate Transition9' */

  /* RateTransition: '<Root>/Rate Transition10' */
  rtb_RateTransition10 = rtDW.Merge_j;

  /* S-Function (fcncallgen): '<Root>/Function_Call_Generator' incorporates:
   *  SubSystem: '<Root>/debugUART'
   */
  for (i = 0; i < 9; i++) {
    /* DataTypeConversion: '<S8>/Cast' */
    Cast_n_0 = (uint16_T)rtb_RateTransition9[i];

    /* SignalConversion: '<S8>/TmpSignal ConversionAtPack_Uart_MessageInport1' */
    rtDW.TmpSignalConversionAtPack_Uart_[i] = Cast_n_0;

    /* DataTypeConversion: '<S8>/Cast' */
    Cast_n[i] = Cast_n_0;
  }

  /* SignalConversion: '<S8>/TmpSignal ConversionAtPack_Uart_MessageInport1' incorporates:
   *  DataTypeConversion: '<S8>/Cast1'
   *  DataTypeConversion: '<S8>/Cast10'
   *  DataTypeConversion: '<S8>/Cast11'
   *  DataTypeConversion: '<S8>/Cast2'
   *  DataTypeConversion: '<S8>/Cast3'
   *  DataTypeConversion: '<S8>/Cast4'
   *  DataTypeConversion: '<S8>/Cast5'
   *  DataTypeConversion: '<S8>/Cast6'
   *  DataTypeConversion: '<S8>/Cast7'
   *  DataTypeConversion: '<S8>/Cast8'
   *  DataTypeConversion: '<S8>/Cast9'
   */
  rtDW.TmpSignalConversionAtPack_Uart_[9] = rtb_RateTransition27;
  rtDW.TmpSignalConversionAtPack_Uart_[10] = rtb_RateTransition10;
  rtDW.TmpSignalConversionAtPack_Uart_[11] = rtb_RateTransition11;
  rtDW.TmpSignalConversionAtPack_Uart_[12] = rtb_RateTransition16;
  rtDW.TmpSignalConversionAtPack_Uart_[13] = rtb_RateTransition12;
  rtDW.TmpSignalConversionAtPack_Uart_[14] = rtb_RateTransition13;
  rtDW.TmpSignalConversionAtPack_Uart_[15] = rtb_RateTransition25;
  rtDW.TmpSignalConversionAtPack_Uart_[16] = rtb_RateTransition14[1];
  rtDW.TmpSignalConversionAtPack_Uart_[17] = rtb_RateTransition15;
  rtDW.TmpSignalConversionAtPack_Uart_[18] = rtb_RateTransition17;
  rtDW.TmpSignalConversionAtPack_Uart_[19] = rtb_RateTransition24;

  /* S-Function (PackUARTMsg): '<S8>/Pack_Uart_Message' */
  PackUARTMsg_Outputs_wrapper(&rtDW.TmpSignalConversionAtPack_Uart_[0],
    &rtDW.Pack_Uart_Message[0]);

  /* S-Function (sendUART): '<S8>/SendUART' */
  sendUART_Outputs_wrapper(&rtDW.Pack_Uart_Message[0]);

  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function_Call_Generator' */

  /* Outport: '<Root>/debugValues  ' incorporates:
   *  DataTypeConversion: '<S8>/Cast1'
   *  DataTypeConversion: '<S8>/Cast10'
   *  DataTypeConversion: '<S8>/Cast11'
   *  DataTypeConversion: '<S8>/Cast2'
   *  DataTypeConversion: '<S8>/Cast3'
   *  DataTypeConversion: '<S8>/Cast4'
   *  DataTypeConversion: '<S8>/Cast5'
   *  DataTypeConversion: '<S8>/Cast6'
   *  DataTypeConversion: '<S8>/Cast7'
   *  DataTypeConversion: '<S8>/Cast8'
   *  DataTypeConversion: '<S8>/Cast9'
   */
  for (i = 0; i < 9; i++) {
    rtY.debugValues[i] = Cast_n[i];
  }

  /* S-Function (fcncallgen): '<Root>/Function_Call_Generator' incorporates:
   *  SubSystem: '<Root>/debugUART'
   */
  rtY.debugValues[9] = rtb_RateTransition27;
  rtY.debugValues[10] = rtb_RateTransition10;
  rtY.debugValues[11] = rtb_RateTransition11;
  rtY.debugValues[12] = rtb_RateTransition16;
  rtY.debugValues[13] = rtb_RateTransition12;
  rtY.debugValues[14] = rtb_RateTransition13;
  rtY.debugValues[15] = rtb_RateTransition25;
  rtY.debugValues[16] = rtb_RateTransition14[1];
  rtY.debugValues[17] = rtb_RateTransition15;
  rtY.debugValues[18] = rtb_RateTransition17;
  rtY.debugValues[19] = rtb_RateTransition24;

  /* End of Outport: '<Root>/debugValues  ' */
  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function_Call_Generator' */
}

/* Model step function for TID4 */
void GCU_Model_genCode_step4(void)     /* Sample time: [0.001s, 0.0006s] */
{
  uint32_T Multiply[9];
  int32_T i;

  /* S-Function (fcncallgen): '<Root>/Function_Call_Generator1' incorporates:
   *  SubSystem: '<Root>/update_ADC_data'
   */
  /* S-Function (update_ADC_data): '<S10>/update_ADC_data' incorporates:
   *  Inport: '<Root>/adc_buffer'
   */
  update_ADC_data_Outputs_wrapper(&rtU.adc_buffer[0], &rtDW.update_ADC_data[0]);

  /* Product: '<S10>/Multiply' */
  for (i = 0; i < 9; i++) {
    Multiply[i] = rtDW.update_ADC_data[i];
  }

  /* End of Product: '<S10>/Multiply' */
  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function_Call_Generator1' */

  /* RateTransition: '<Root>/Rate Transition18' */
  if (!(rtDW.RateTransition18_semaphoreTaken != 0)) {
    for (i = 0; i < 9; i++) {
      rtDW.RateTransition18_Buffer0[i] = Multiply[i];
    }
  }

  /* End of RateTransition: '<Root>/Rate Transition18' */

  /* Outport: '<Root>/adc_data_vector' */
  for (i = 0; i < 9; i++) {
    rtY.adc_data_vector[i] = Multiply[i];
  }

  /* End of Outport: '<Root>/adc_data_vector' */

  /* Update for RateTransition: '<Root>/Rate Transition9' */
  for (i = 0; i < 9; i++) {
    rtDW.RateTransition9_Buffer[i + (rtDW.RateTransition9_ActiveBufIdx == 0) * 9]
      = Multiply[i];
  }

  rtDW.RateTransition9_ActiveBufIdx = (int8_T)(rtDW.RateTransition9_ActiveBufIdx
    == 0);

  /* End of Update for RateTransition: '<Root>/Rate Transition9' */
}

/* Model step function for TID5 */
void GCU_Model_genCode_step5(void)     /* Sample time: [0.001s, 0.0008s] */
{
  uint16_T rtb_RateTransition22;
  uint8_T rtb_RateTransition20;
  uint32_T rtb_RateTransition18[9];
  uint8_T rtb_RateTransition19;
  int32_T i;

  /* RateTransition: '<Root>/Rate Transition22' */
  rtb_RateTransition22 = rtDW.tractionValue;

  /* RateTransition: '<Root>/Rate Transition26' */
  rtDW.RateTransition26 = rtDW.mapValue;

  /* RateTransition: '<Root>/Rate Transition20' */
  rtb_RateTransition20 = rtDW.clutchCurrVal;

  /* RateTransition: '<Root>/Rate Transition21' */
  rtDW.RateTransition21 = rtDW.accFb;

  /* RateTransition: '<Root>/Rate Transition23' */
  rtDW.RateTransition23 = rtDW.lastModeCom[1];

  /* RateTransition: '<Root>/Rate Transition18' */
  rtDW.RateTransition18_semaphoreTaken = 1;
  for (i = 0; i < 9; i++) {
    rtb_RateTransition18[i] = rtDW.RateTransition18_Buffer0[i];
  }

  rtDW.RateTransition18_semaphoreTaken = 0;

  /* End of RateTransition: '<Root>/Rate Transition18' */

  /* RateTransition: '<Root>/Rate Transition19' */
  rtb_RateTransition19 = rtDW.Merge_j;

  /* S-Function (fcncallgen): '<Root>/Function_Call_Generator2' incorporates:
   *  SubSystem: '<Root>/CAN_Send'
   */
  /* DataTypeConversion: '<S11>/Cast' */
  rtDW.Cast_o = (uint16_T)rtb_RateTransition18[0];

  /* DataTypeConversion: '<S11>/Cast1' */
  rtDW.Cast1 = (uint16_T)rtb_RateTransition18[1];

  /* DataTypeConversion: '<S11>/Cast2' */
  rtDW.Cast2 = (uint16_T)rtb_RateTransition18[2];

  /* DataTypeConversion: '<S11>/Cast3' */
  rtDW.Cast3 = (uint16_T)rtb_RateTransition18[3];

  /* S-Function (PackCANMsg): '<S11>/PackCANMsg' */
  PackCANMsg_Outputs_wrapper(&rtDW.Cast_o, &rtDW.Cast1, &rtDW.Cast2, &rtDW.Cast3,
    &rtDW.PackCANMsg[0]);

  /* S-Function (sendCAN): '<S11>/sendCAN' incorporates:
   *  Constant: '<S1>/ADC_data1_ID'
   */
  sendCAN_Outputs_wrapper(&rtConstP.pooled3, &rtDW.PackCANMsg[0]);

  /* DataTypeConversion: '<S12>/Cast' */
  rtDW.Cast_l = (uint16_T)rtb_RateTransition18[4];

  /* DataTypeConversion: '<S12>/Cast1' */
  rtDW.Cast1_e = (uint16_T)rtb_RateTransition18[5];

  /* DataTypeConversion: '<S12>/Cast2' */
  rtDW.Cast2_a = (uint16_T)rtb_RateTransition18[6];

  /* DataTypeConversion: '<S12>/Cast3' */
  rtDW.Cast3_o = (uint16_T)rtb_RateTransition18[7];

  /* S-Function (PackCANMsg): '<S12>/PackCANMsg' */
  PackCANMsg_Outputs_wrapper(&rtDW.Cast_l, &rtDW.Cast1_e, &rtDW.Cast2_a,
    &rtDW.Cast3_o, &rtDW.PackCANMsg_m[0]);

  /* S-Function (sendCAN): '<S12>/sendCAN' incorporates:
   *  Constant: '<S1>/ADC_data2_ID'
   */
  sendCAN_Outputs_wrapper(&rtConstP.pooled3, &rtDW.PackCANMsg_m[0]);

  /* DataTypeConversion: '<S13>/Cast' */
  rtDW.Cast_k = (uint16_T)rtb_RateTransition18[8];

  /* S-Function (Read_oil_sensor): '<S1>/Read_oil_sensor' */
  Read_oil_sensor_Outputs_wrapper(&rtDW.Read_oil_sensor);

  /* S-Function (PackCANMsg): '<S13>/PackCANMsg' incorporates:
   *  Constant: '<S1>/Constant'
   */
  PackCANMsg_Outputs_wrapper(&rtDW.Cast_k, &rtDW.Read_oil_sensor,
    &rtConstP.pooled4, &rtConstP.pooled4, &rtDW.PackCANMsg_i[0]);

  /* S-Function (sendCAN): '<S13>/sendCAN' incorporates:
   *  Constant: '<S13>/ADC_data1_ID'
   */
  sendCAN_Outputs_wrapper(&rtConstP.pooled3, &rtDW.PackCANMsg_i[0]);

  /* Product: '<S1>/Divide' */
  rtDW.Divide = (uint16_T)(rtb_RateTransition22 / 100U);

  /* DataTypeConversion: '<S14>/Cast1' */
  rtDW.Cast1_c = rtb_RateTransition19;

  /* S-Function (PackCANMsg): '<S14>/PackCANMsg' incorporates:
   *  Constant: '<S1>/Constant2'
   */
  PackCANMsg_Outputs_wrapper(&rtDW.Divide, &rtDW.Cast1_c, &rtDW.RateTransition26,
    &rtConstP.pooled4, &rtDW.PackCANMsg_b[0]);

  /* S-Function (sendCAN): '<S14>/sendCAN' incorporates:
   *  Constant: '<S1>/UPDATES1_SW_ID'
   */
  sendCAN_Outputs_wrapper(&rtConstP.pooled3, &rtDW.PackCANMsg_b[0]);

  /* DataTypeConversion: '<S16>/Cast1' */
  rtDW.Cast1_o = rtb_RateTransition19;

  /* S-Function (PackCANMsg): '<S16>/PackCANMsg' incorporates:
   *  Constant: '<S1>/Constant3'
   */
  PackCANMsg_Outputs_wrapper(&rtDW.Divide, &rtDW.Cast1_o, &rtDW.RateTransition26,
    &rtConstP.pooled4, &rtDW.PackCANMsg_b5[0]);

  /* S-Function (sendCAN): '<S16>/sendCAN' incorporates:
   *  Constant: '<S1>/UPDATES_EFI_ID'
   */
  sendCAN_Outputs_wrapper(&rtConstP.pooled3, &rtDW.PackCANMsg_b5[0]);

  /* DataTypeConversion: '<S15>/Cast' */
  rtDW.Cast_e = rtb_RateTransition20;

  /* S-Function (PackCANMsg): '<S15>/PackCANMsg' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  PackCANMsg_Outputs_wrapper(&rtDW.Cast_e, &rtDW.RateTransition21,
    &rtDW.RateTransition23, &rtConstP.pooled4, &rtDW.PackCANMsg_ig[0]);

  /* S-Function (sendCAN): '<S15>/sendCAN' incorporates:
   *  Constant: '<S1>/UPDATES2_SW_ID'
   */
  sendCAN_Outputs_wrapper(&rtConstP.pooled3, &rtDW.PackCANMsg_ig[0]);

  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function_Call_Generator2' */

  /* Update for RateTransition: '<Root>/Rate Transition27' */
  rtDW.RateTransition27_Buffer0 = rtDW.Read_oil_sensor;
}

/* Model initialize function */
void GCU_Model_genCode_initialize(void)
{
  /* Registration code */

  /* initialize sample time offsets */
  /* initialize sample time offsets */
  /* initialize sample time offsets */
  /* initialize sample time offsets */
  {
    int32_T i;
    rtPrevZCX._Trig_ZCE_i[0] = UNINITIALIZED_ZCSIG;
    rtPrevZCX._Trig_ZCE[0] = UNINITIALIZED_ZCSIG;
    rtPrevZCX._Trig_ZCE_i[1] = UNINITIALIZED_ZCSIG;
    rtPrevZCX._Trig_ZCE[1] = UNINITIALIZED_ZCSIG;
    rtPrevZCX.Triggered_Subsystem_Trig_ZCE = UNINITIALIZED_ZCSIG;
    rtPrevZCX.Triggered_Subsystem1_Trig_ZCE = UNINITIALIZED_ZCSIG;

    /* SystemInitialize for Triggered SubSystem: '<S18>/Triggered Subsystem' */
    for (i = 0; i < 23; i++) {
      rtPrevZCX.TriggeredSubsystem_Trig_ZCE[i] = ZERO_ZCSIG;
    }

    /* End of SystemInitialize for SubSystem: '<S18>/Triggered Subsystem' */

    /* SystemInitialize for Triggered SubSystem: '<S17>/Triggered Subsystem' */
    /* SystemInitialize for Merge: '<S17>/Merge' */
    for (i = 0; i < 11; i++) {
      rtPrevZCX.TriggeredSubsystem_Trig_ZCE_j[i] = ZERO_ZCSIG;
    }

    /* End of SystemInitialize for Merge: '<S17>/Merge' */
    /* End of SystemInitialize for SubSystem: '<S17>/Triggered Subsystem' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/GCU_timer' */
    /* SystemInitialize for Chart: '<S4>/GCULogic' */
    rtDW.sfEvent = -1;

    /* End of SystemInitialize for SubSystem: '<Root>/GCU_timer' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Simulink_Debug' */
    /* Chart: '<S6>/AccelerationRoutine' */
    rtDW.is_c3_GCU_Model_genCode = IN_Wait;

    /* End of SystemInitialize for SubSystem: '<Root>/Simulink_Debug' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/InitializeFunction' */

    /* S-Function (load_accParameters): '<S5>/load_accParameters' */
    load_accParameters_Outputs_wrapper(&rtDW.load_accParameters[0]);

    /* S-Function (load_default_timings): '<S5>/load_default_timings' */
    load_default_timings_Outputs_wrapper(&rtDW.load_default_timings[0]);

    /* S-Function (CAN_Start): '<S5>/CAN_Start' */
    CAN_Start_Outputs_wrapper();

    /* S-Function (ClutchMotor_init): '<S5>/ClutchMotor Init' */
    ClutchMotor_init_Outputs_wrapper();

    /* S-Function (Efi_init): '<S5>/Efi Init' */
    Efi_init_Outputs_wrapper();

    /* S-Function (GearMotor_init): '<S5>/GearMotor Init' */
    GearMotor_init_Outputs_wrapper();

    /* S-Function (InitADC): '<S5>/InitADC' */
    InitADC_Outputs_wrapper();

    /* S-Function (InitTimer): '<S5>/InitTimer' */
    InitTimer_Outputs_wrapper();

    /* S-Function (InitUART): '<S5>/InitUART' */
    InitUART_Outputs_wrapper();

    /* End of SystemInitialize for SubSystem: '<Root>/InitializeFunction' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
