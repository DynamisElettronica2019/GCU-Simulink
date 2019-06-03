/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GCU_Model_genCode.c
 *
 * Code generated for Simulink model 'GCU_Model_genCode'.
 *
 * Model version                  : 1.265
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Mon Jun  3 16:54:39 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "GCU_Model_genCode.h"

/* Named constants for Chart: '<S4>/MessageEvaluation1' */
#define ACC_CLUTCH_NOISE_LEVEL         ((uint8_T)30U)
#define GEAR_COMMAND_DOWN              ((uint16_T)200U)
#define GEAR_COMMAND_NEUTRAL_DOWN      ((uint16_T)100U)
#define GEAR_COMMAND_NEUTRAL_UP        ((uint16_T)50U)
#define STOP_COM                       ((uint16_T)0U)

/* Named constants for Chart: '<S2>/EEPROM_OutputRequest' */
#define IN_ACC_PARAMETERS              ((uint8_T)1U)
#define IN_AUTOX_PARAMETERS            ((uint8_T)2U)
#define IN_ERROR                       ((uint8_T)1U)
#define IN_EVALUATE_SERIAL             ((uint8_T)5U)
#define IN_FIRST_BYTE                  ((uint8_T)3U)
#define IN_GEARSHIFT_TIMINGS           ((uint8_T)4U)
#define IN_GEARSHIFT_TIMINGS_j         ((uint8_T)3U)
#define IN_INIT                        ((uint8_T)2U)
#define IN_LOAD_FROM_EEPROM            ((uint8_T)3U)
#define IN_LOAD_TO_EEPROM              ((uint8_T)4U)
#define IN_RELOAD                      ((uint8_T)6U)

/* Named constants for Chart: '<S5>/GCULogic' */
#define AAC_WORK_RATE_ms               ((uint16_T)25U)
#define AUTOX_WORK_RATE_ms             ((uint16_T)25U)
#define GEAR_COMMAND_UP                ((uint16_T)400U)
#define IN_ACC                         ((uint8_T)1U)
#define IN_ACCELERATION                ((uint8_T)1U)
#define IN_ACTIVE                      ((uint8_T)1U)
#define IN_AUTOCROSS                   ((uint8_T)2U)
#define IN_ChangeClutch                ((uint8_T)1U)
#define IN_CutOff                      ((uint8_T)1U)
#define IN_DEFAULT                     ((uint8_T)2U)
#define IN_DEFAULT_e                   ((uint8_T)1U)
#define IN_DOWNSHIFTING                ((uint8_T)1U)
#define IN_DOWN_BRAKE                  ((uint8_T)1U)
#define IN_DOWN_END                    ((uint8_T)2U)
#define IN_DOWN_PUSH                   ((uint8_T)2U)
#define IN_DOWN_REBOUND                ((uint8_T)3U)
#define IN_DOWN_START                  ((uint8_T)4U)
#define IN_Default                     ((uint8_T)1U)
#define IN_Default_o                   ((uint8_T)2U)
#define IN_IDLE                        ((uint8_T)3U)
#define IN_INIT_j                      ((uint8_T)3U)
#define IN_INIT_jf                     ((uint8_T)4U)
#define IN_LAUNCH                      ((uint8_T)2U)
#define IN_MANUAL_MODES                ((uint8_T)4U)
#define IN_NEUTRAL                     ((uint8_T)1U)
#define IN_NO_NEUTRAL                  ((uint8_T)2U)
#define IN_READY                       ((uint8_T)1U)
#define IN_RELEASING                   ((uint8_T)2U)
#define IN_RUNNING                     ((uint8_T)3U)
#define IN_SCAN                        ((uint8_T)1U)
#define IN_SEND                        ((uint8_T)1U)
#define IN_SET_NEUTRAL                 ((uint8_T)3U)
#define IN_START                       ((uint8_T)4U)
#define IN_START_RELEASE               ((uint8_T)5U)
#define IN_START_e                     ((uint8_T)1U)
#define IN_STOP                        ((uint8_T)2U)
#define IN_STOPPING                    ((uint8_T)2U)
#define IN_SettingNeutral              ((uint8_T)2U)
#define IN_SettingNeutral_b            ((uint8_T)3U)
#define IN_UNSET_NEUTRAL               ((uint8_T)4U)
#define IN_UPSHIFTING                  ((uint8_T)5U)
#define IN_UP_BRAKE                    ((uint8_T)1U)
#define IN_UP_END                      ((uint8_T)6U)
#define IN_UP_PUSH                     ((uint8_T)2U)
#define IN_UP_REBOUND                  ((uint8_T)3U)
#define IN_UP_START                    ((uint8_T)4U)
#define IN_WAIT                        ((uint8_T)2U)
#define IN_WAIT_e                      ((uint8_T)3U)
#define event_GearshiftDown            (0)
#define event_GearshiftSetNeutral      (1)
#define event_GearshiftUp              (2)

/* Named constants for Chart: '<S7>/AccelerationRoutine' */
#define IN_ActivateAac                 ((uint8_T)1U)
#define IN_CHANGE_MODE                 ((uint8_T)2U)
#define IN_DajeDeGas                   ((uint8_T)3U)
#define IN_EXIT                        ((uint8_T)4U)
#define IN_EnterAcceleration           ((uint8_T)5U)
#define IN_InsertGear                  ((uint8_T)6U)
#define IN_Ready                       ((uint8_T)7U)
#define IN_TPS_On                      ((uint8_T)8U)
#define IN_Wait                        ((uint8_T)9U)
#define IN_delay                       ((uint8_T)10U)
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */
const uint16_T GCU_Model_genCode_U16GND = 0U;/* uint16_T ground */

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

  extern void Read_oil_sensor_Start_wrapper(void);
  extern void Read_oil_sensor_Outputs_wrapper(uint16_T *l_oil);
  extern void Read_oil_sensor_Terminate_wrapper(void);

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

  extern void Eeprom_write_Start_wrapper(void);
  extern void Eeprom_write_Outputs_wrapper(const uint8_T *page,
    const uint8_T *cell,
    const uint8_T *dataSize,
    const uint8_T *data,
    uint8_T *resWrite,
    uint8_T *wpState);
  extern void Eeprom_write_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Eeprom_read_Start_wrapper(void);
  extern void Eeprom_read_Outputs_wrapper(const uint8_T *page,
    const uint8_T *cell,
    const uint8_T *dataSize,
    uint8_T *resRead,
    uint8_T *data);
  extern void Eeprom_read_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void sendEepromUART_Start_wrapper(void);
  extern void sendEepromUART_Outputs_wrapper(const uint8_T *msg);
  extern void sendEepromUART_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void activateBuzzer_Start_wrapper(void);
  extern void activateBuzzer_Outputs_wrapper(void);
  extern void activateBuzzer_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void stopBuzzer_Start_wrapper(void);
  extern void stopBuzzer_Outputs_wrapper(void);
  extern void stopBuzzer_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void ScanADC_Start_wrapper(void);
  extern void ScanADC_Outputs_wrapper(void);
  extern void ScanADC_Terminate_wrapper(void);

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

  extern void load_autoXParameters_Start_wrapper(void);
  extern void load_autoXParameters_Outputs_wrapper(int32_T *autoXParameters);
  extern void load_autoXParameters_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Eeprom_init_Start_wrapper(void);
  extern void Eeprom_init_Outputs_wrapper(uint8_T *wpState,
    uint8_T *eepromState,
    uint8_T *resRead);
  extern void Eeprom_init_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void setKeyOn_Start_wrapper(void);
  extern void setKeyOn_Outputs_wrapper(uint8_T *keyOn);
  extern void setKeyOn_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Buzzer_init_Start_wrapper(void);
  extern void Buzzer_init_Outputs_wrapper(void);
  extern void Buzzer_init_Terminate_wrapper(void);

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

  extern void ClutchMotor_init_Start_wrapper(void);
  extern void ClutchMotor_init_Outputs_wrapper(void);
  extern void ClutchMotor_init_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void FuelPump_init_Start_wrapper(void);
  extern void FuelPump_init_Outputs_wrapper(void);
  extern void FuelPump_init_Terminate_wrapper(void);

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

#ifdef __cplusplus

extern "C" {

#endif

  extern void StopLight_init_Start_wrapper(void);
  extern void StopLight_init_Outputs_wrapper(void);
  extern void StopLight_init_Terminate_wrapper(void);

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

static uint16_T look1_iu16lu64n48_binlcse(uint16_T u0, const uint16_T bp0[],
  const uint16_T table[], uint32_T maxIndex);
static void AAC_ExternalValues(uint16_T rtu_Value, uint16_T rtu_Index, uint16_T
  rty_Values[3], DW_AAC_ExternalValues *localDW);
static void SetRPMLimiter(uint8_T *rty_rpmLimiter_pin, DW_SetRPMLimiter *localDW);
static void UnsetRPMLimiter(uint8_T *rty_rpmLimiter_pin, DW_UnsetRPMLimiter
  *localDW);
static void Gearmotor_turnRight(uint8_T *rty_Pin_In1, uint8_T *rty_Pin_In2,
  uint8_T *rty_Pin_H, DW_Gearmotor_turnRight *localDW);
static void Gearmotor_brake(uint8_T *rty_Pin_In1, uint8_T *rty_Pin_In2, uint8_T *
  rty_Pin_H, DW_Gearmotor_brake *localDW);
static void EngineControl_Start(uint8_T *rty_engine_starter,
  DW_EngineControl_Start *localDW);
static void Evaluate_Request_Init(int32_T rty_gearshiftTimings[24], int32_T
  rty_accParameters[16], int32_T rty_autoXParameters[16], DW_Evaluate_Request
  *localDW);
static void Evaluate_Request(const eepromRequest *rtu_outputRequest, const
  int32_T rtu_accInitialParameters[12], const int32_T
  rtu_gearshiftInitialTimings[23], const int32_T rtu_autoXInitialParameters[12],
  uint8_T *rty_writeResult, uint8_T *rty_readResult, uint8_T *rty_wpState,
  uint8_T rty_dataRead[19], int32_T rty_gearshiftTimings[24], int32_T
  rty_accParameters[16], int32_T rty_autoXParameters[16], DW_Evaluate_Request
  *localDW);
static void SCAN_ADCScanADC(void);
static void Gearmotor_release(void);

/* Forward declaration for local functions */
static void NEUTRAL_STATE(void);
static int32_T Gearshift_getTime(void);
static void Clutch_setValue(uint8_T setValue);
static void GEARSHIFT(void);
static void checkShift(void);
static int32_T getAacParam(acc_params b_index);
static void aacCheckShift(void);
static void checkClutch(void);
static void enter_atomic_MANUAL_MODES(void);
static void ACCELERATION(void);
static int32_T getAutoXParam(autoX_params b_index);
static void autoXCheckShift(void);
static void AUTOCROSS(void);
static void MODES(void);
static void createRequest(uint8_T operation, uint8_T page, uint8_T cell, uint8_T
  dataSize, const uint8_T tempData[16]);
static void extractValues(uint8_T count);
static void shiftArray_h(const int32_T array[12], real_T nValues);
static void shiftArray(const int32_T array[23], real_T nValues);
static void updateOutput(void);
static void testIndex(void);
static void updateData(void);
static void checkGear(void);
static void sendAutoXCommand(uint16_T com);
static void sendAccCommand(uint16_T com);
static void sendModeCommand(uint16_T com);
static void sendShiftCommand(uint16_T com);
static void sendStartEngCommand(void);
static void updateBuffer(const eepromRequest *BusConversion_InsertedFor_EEPRO);
static uint16_T look1_iu16lu64n48_binlcse(uint16_T u0, const uint16_T bp0[],
  const uint16_T table[], uint32_T maxIndex)
{
  uint16_T y;
  uint64_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0ULL;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = ((uint64_T)(uint16_T)((uint32_T)u0 - bp0[iLeft]) << 48) / (uint16_T)
      ((uint32_T)bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = 281474976710656ULL;
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  if (table[iLeft + 1U] >= table[iLeft]) {
    y = (uint16_T)((uint32_T)(uint16_T)(((uint16_T)((uint32_T)table[iLeft + 1U]
      - table[iLeft]) * frac) >> 48) + table[iLeft]);
  } else {
    y = (uint16_T)((uint32_T)table[iLeft] - (uint16_T)(((uint16_T)((uint32_T)
      table[iLeft] - table[iLeft + 1U]) * frac) >> 48));
  }

  return y;
}

/* Output and update for function-call system: '<S4>/AAC_ExternalValues' */
static void AAC_ExternalValues(uint16_T rtu_Value, uint16_T rtu_Index, uint16_T
  rty_Values[3], DW_AAC_ExternalValues *localDW)
{
  /* Assignment: '<S37>/Assignment' incorporates:
   *  UnitDelay: '<S37>/Unit Delay'
   */
  rty_Values[0] = localDW->UnitDelay_DSTATE[0];
  rty_Values[1] = localDW->UnitDelay_DSTATE[1];
  rty_Values[2] = localDW->UnitDelay_DSTATE[2];
  rty_Values[rtu_Index] = rtu_Value;

  /* Update for UnitDelay: '<S37>/Unit Delay' */
  localDW->UnitDelay_DSTATE[0] = rty_Values[0];
  localDW->UnitDelay_DSTATE[1] = rty_Values[1];
  localDW->UnitDelay_DSTATE[2] = rty_Values[2];
}

/* Output and update for function-call system: '<S41>/SetRPMLimiter' */
static void SetRPMLimiter(uint8_T *rty_rpmLimiter_pin, DW_SetRPMLimiter *localDW)
{
  /* S-Function (Efi_setRPMLimiter): '<S51>/Efi SetRPMLimiter' */
  Efi_setRPMLimiter_Outputs_wrapper(&localDW->EfiSetRPMLimiter);

  /* SignalConversion: '<S51>/OutportBufferForrpmLimiter_pin' */
  *rty_rpmLimiter_pin = localDW->EfiSetRPMLimiter;
}

/* Output and update for function-call system: '<S41>/UnsetRPMLimiter' */
static void UnsetRPMLimiter(uint8_T *rty_rpmLimiter_pin, DW_UnsetRPMLimiter
  *localDW)
{
  /* S-Function (Efi_unsetRPMLimiter): '<S53>/Efi UnSetRPMLimiter' */
  Efi_unsetRPMLimiter_Outputs_wrapper(&localDW->EfiUnSetRPMLimiter);

  /* SignalConversion: '<S53>/OutportBufferForrpmLimiter_pin' */
  *rty_rpmLimiter_pin = localDW->EfiUnSetRPMLimiter;
}

/* Output and update for function-call system: '<S45>/Gearmotor_release' */
static void Gearmotor_release(void)
{
  /* S-Function (GearMotor_release): '<S61>/GearMotor Release' */
  GearMotor_release_Outputs_wrapper(&rtDW.GearMotorRelease);

  /* SignalConversion: '<S61>/OutportBufferForPin H' */
  rtDW.Pin_H = rtDW.GearMotorRelease;
}

/* Output and update for function-call system: '<S45>/Gearmotor_turnRight' */
static void Gearmotor_turnRight(uint8_T *rty_Pin_In1, uint8_T *rty_Pin_In2,
  uint8_T *rty_Pin_H, DW_Gearmotor_turnRight *localDW)
{
  /* S-Function (GearMotor_turnRight): '<S63>/GearMotor Turn Right' */
  GearMotor_turnRight_Outputs_wrapper(&localDW->GearMotorTurnRight_o1,
    &localDW->GearMotorTurnRight_o2, &localDW->GearMotorTurnRight_o3);

  /* SignalConversion: '<S63>/OutportBufferForPin_H' */
  *rty_Pin_H = localDW->GearMotorTurnRight_o3;

  /* SignalConversion: '<S63>/OutportBufferForPin_In1' */
  *rty_Pin_In1 = localDW->GearMotorTurnRight_o1;

  /* SignalConversion: '<S63>/OutportBufferForPin_In2' */
  *rty_Pin_In2 = localDW->GearMotorTurnRight_o2;
}

/* Output and update for function-call system: '<S45>/Gearmotor_brake' */
static void Gearmotor_brake(uint8_T *rty_Pin_In1, uint8_T *rty_Pin_In2, uint8_T *
  rty_Pin_H, DW_Gearmotor_brake *localDW)
{
  /* S-Function (GearMotor_brake): '<S60>/GearMotor Brake' */
  GearMotor_brake_Outputs_wrapper(&localDW->GearMotorBrake_o1,
    &localDW->GearMotorBrake_o2, &localDW->GearMotorBrake_o3);

  /* SignalConversion: '<S60>/OutportBufferForPin_H' */
  *rty_Pin_H = localDW->GearMotorBrake_o3;

  /* SignalConversion: '<S60>/OutportBufferForPin_In1' */
  *rty_Pin_In1 = localDW->GearMotorBrake_o1;

  /* SignalConversion: '<S60>/OutportBufferForPin_In2' */
  *rty_Pin_In2 = localDW->GearMotorBrake_o2;
}

/* Output and update for function-call system: '<S42>/EngineControl_Start' */
static void EngineControl_Start(uint8_T *rty_engine_starter,
  DW_EngineControl_Start *localDW)
{
  /* S-Function (EngineControl_start): '<S54>/EngineControl Start' */
  EngineControl_start_Outputs_wrapper(&localDW->EngineControlStart);

  /* SignalConversion: '<S54>/OutportBufferForengine_starter' */
  *rty_engine_starter = localDW->EngineControlStart;
}

/* System initialize for function-call system: '<S2>/Evaluate_Request' */
static void Evaluate_Request_Init(int32_T rty_gearshiftTimings[24], int32_T
  rty_accParameters[16], int32_T rty_autoXParameters[16], DW_Evaluate_Request
  *localDW)
{
  /* SystemInitialize for IfAction SubSystem: '<S25>/LoadFromEEPROM' */
  /* SystemInitialize for Chart: '<S27>/updateValues' */
  localDW->HAL_ERROR = 1U;

  /* End of SystemInitialize for SubSystem: '<S25>/LoadFromEEPROM' */

  /* SystemInitialize for Merge: '<S25>/Merge' */
  memset(&rty_gearshiftTimings[0], 0, 24U * sizeof(int32_T));

  /* SystemInitialize for Merge: '<S25>/Merge1' */
  memset(&rty_accParameters[0], 0, sizeof(int32_T) << 4U);

  /* SystemInitialize for Merge: '<S25>/Merge2' */
  memset(&rty_autoXParameters[0], 0, sizeof(int32_T) << 4U);
}

/* Output and update for function-call system: '<S2>/Evaluate_Request' */
static void Evaluate_Request(const eepromRequest *rtu_outputRequest, const
  int32_T rtu_accInitialParameters[12], const int32_T
  rtu_gearshiftInitialTimings[23], const int32_T rtu_autoXInitialParameters[12],
  uint8_T *rty_writeResult, uint8_T *rty_readResult, uint8_T *rty_wpState,
  uint8_T rty_dataRead[19], int32_T rty_gearshiftTimings[24], int32_T
  rty_accParameters[16], int32_T rty_autoXParameters[16], DW_Evaluate_Request
  *localDW)
{
  uint16_T data_16bit[8];
  int32_T i;
  uint8_T tmp;
  uint32_T qY;

  /* SignalConversion: '<S25>/TmpSignal ConversionAtBus SelectorOutport2' */
  localDW->page = rtu_outputRequest->page;

  /* SignalConversion: '<S25>/TmpSignal ConversionAtBus SelectorOutport3' */
  localDW->cell = rtu_outputRequest->cell;

  /* SignalConversion: '<S25>/TmpSignal ConversionAtBus SelectorOutport4' */
  localDW->dataSize = rtu_outputRequest->dataSize;

  /* If: '<S25>/If' incorporates:
   *  Constant: '<S25>/Constant'
   *  Constant: '<S25>/Constant1'
   *  Constant: '<S25>/Constant2'
   *  Constant: '<S25>/Constant3'
   */
  if (rtu_outputRequest->operation == 87) {
    /* Outputs for IfAction SubSystem: '<S25>/Write' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */

    /* S-Function (Eeprom_write): '<S29>/Eeprom_write' */
    Eeprom_write_Outputs_wrapper(&localDW->page, &localDW->cell,
      &localDW->dataSize, &rtu_outputRequest->data[0], rty_writeResult,
      rty_wpState);

    /* End of Outputs for SubSystem: '<S25>/Write' */
  } else if (rtu_outputRequest->operation == 82) {
    /* Outputs for IfAction SubSystem: '<S25>/Read' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */

    /* S-Function (Eeprom_read): '<S28>/Eeprom_read' */
    Eeprom_read_Outputs_wrapper(&localDW->page, &localDW->cell,
      &localDW->dataSize, rty_readResult, &localDW->Eeprom_read_o2_e[0]);

    /* End of Outputs for SubSystem: '<S25>/Read' */
  } else if (rtu_outputRequest->operation == 76) {
    /* Outputs for IfAction SubSystem: '<S25>/LoadFromEEPROM' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    /* S-Function (Eeprom_read): '<S27>/Eeprom_read' */
    Eeprom_read_Outputs_wrapper(&localDW->page, &localDW->cell,
      &localDW->dataSize, &localDW->Eeprom_read_o1, &localDW->Eeprom_read_o2[0]);

    /* Chart: '<S27>/updateValues' */
    if (localDW->Eeprom_read_o1 != localDW->HAL_ERROR) {
      for (i = 0; i < 8; i++) {
        /* NEW_PATTERN */
        data_16bit[i] = (uint16_T)((localDW->Eeprom_read_o2[((i + 1) << 1) - 2] <<
          8) + localDW->Eeprom_read_o2[((i + 1) << 1) - 1]);
      }

      if ((localDW->page == 1) || (localDW->page == 2) || (localDW->page == 3))
      {
        if (localDW->page > 31) {
          tmp = MAX_uint8_T;
        } else {
          tmp = (uint8_T)(localDW->page << 3);
        }

        qY = tmp - /*MW:OvSatOk*/ 7U;
        if (qY > tmp) {
          qY = 0U;
        }

        for (i = 0; i < 8; i++) {
          localDW->gearshiftTimings[(i + (uint8_T)qY) - 1] = data_16bit[i];
        }
      } else if ((localDW->page == 5) || (localDW->page == 6)) {
        qY = localDW->page - /*MW:OvSatOk*/ 4U;
        if (qY > localDW->page) {
          qY = 0U;
        }

        if ((uint8_T)qY > 31) {
          tmp = MAX_uint8_T;
        } else {
          tmp = (uint8_T)((uint8_T)qY << 3);
        }

        qY = tmp - /*MW:OvSatOk*/ 7U;
        if (qY > tmp) {
          qY = 0U;
        }

        for (i = 0; i < 8; i++) {
          localDW->accParameters[(i + (uint8_T)qY) - 1] = data_16bit[i];
        }
      } else {
        if ((localDW->page == 8) || (localDW->page == 9)) {
          qY = localDW->page - /*MW:OvSatOk*/ 7U;
          if (qY > localDW->page) {
            qY = 0U;
          }

          if ((uint8_T)qY > 31) {
            tmp = MAX_uint8_T;
          } else {
            tmp = (uint8_T)((uint8_T)qY << 3);
          }

          qY = tmp - /*MW:OvSatOk*/ 7U;
          if (qY > tmp) {
            qY = 0U;
          }

          for (i = 0; i < 8; i++) {
            localDW->autoXParameters[(i + (uint8_T)qY) - 1] = data_16bit[i];
          }
        }
      }
    }

    /* End of Chart: '<S27>/updateValues' */

    /* DataTypeConversion: '<S27>/Cast2' */
    for (i = 0; i < 24; i++) {
      rty_gearshiftTimings[i] = localDW->gearshiftTimings[i];
    }

    /* End of DataTypeConversion: '<S27>/Cast2' */
    for (i = 0; i < 16; i++) {
      /* DataTypeConversion: '<S27>/Cast1' */
      rty_autoXParameters[i] = localDW->autoXParameters[i];

      /* DataTypeConversion: '<S27>/Cast3' */
      rty_accParameters[i] = localDW->accParameters[i];
    }

    /* End of Outputs for SubSystem: '<S25>/LoadFromEEPROM' */
  } else {
    if (rtu_outputRequest->operation == 69) {
      /* Outputs for IfAction SubSystem: '<S25>/Error' incorporates:
       *  ActionPort: '<S26>/Action Port'
       */
      /* SignalConversion: '<S26>/OutportBufferForgearshiftTimings' incorporates:
       *  Constant: '<S26>/Constant'
       *  Inport: '<S26>/gearshiftInitialTimings'
       */
      memcpy(&rty_gearshiftTimings[0], &rtu_gearshiftInitialTimings[0], 23U *
             sizeof(int32_T));
      rty_gearshiftTimings[23] = 0;

      /* SignalConversion: '<S26>/OutportBufferForaccParameters' incorporates:
       *  Inport: '<S26>/accInitialParameters'
       */
      rty_accParameters[12] = 0;
      rty_accParameters[13] = 0;
      rty_accParameters[14] = 0;
      rty_accParameters[15] = 0;
      for (i = 0; i < 12; i++) {
        rty_accParameters[i] = rtu_accInitialParameters[i];

        /* SignalConversion: '<S26>/OutportBufferForautoXParameters' incorporates:
         *  Inport: '<S26>/accInitialParameters'
         *  Inport: '<S26>/autoXInitialParameters'
         */
        rty_autoXParameters[i] = rtu_autoXInitialParameters[i];
      }

      /* End of SignalConversion: '<S26>/OutportBufferForaccParameters' */

      /* SignalConversion: '<S26>/OutportBufferForautoXParameters' */
      rty_autoXParameters[12] = 0;
      rty_autoXParameters[13] = 0;
      rty_autoXParameters[14] = 0;
      rty_autoXParameters[15] = 0;

      /* End of Outputs for SubSystem: '<S25>/Error' */
    }
  }

  /* End of If: '<S25>/If' */

  /* SignalConversion: '<S25>/TmpSignal ConversionAtsendEepromUARTInport1' */
  localDW->TmpSignalConversionAtsendEeprom[0] = localDW->page;
  localDW->TmpSignalConversionAtsendEeprom[1] = localDW->cell;
  localDW->TmpSignalConversionAtsendEeprom[2] = localDW->dataSize;
  for (i = 0; i < 16; i++) {
    localDW->TmpSignalConversionAtsendEeprom[i + 3] = localDW->
      Eeprom_read_o2_e[i];
  }

  /* End of SignalConversion: '<S25>/TmpSignal ConversionAtsendEepromUARTInport1' */

  /* S-Function (sendEepromUART): '<S25>/sendEepromUART' */
  sendEepromUART_Outputs_wrapper(&localDW->TmpSignalConversionAtsendEeprom[0]);

  /* SignalConversion: '<S25>/OutportBufferFordataRead' */
  for (i = 0; i < 19; i++) {
    rty_dataRead[i] = localDW->TmpSignalConversionAtsendEeprom[i];
  }

  /* End of SignalConversion: '<S25>/OutportBufferFordataRead' */
}

/* Output and update for function-call system: '<S44>/SCAN_ADC.ScanADC' */
static void SCAN_ADCScanADC(void)
{
  /* S-Function (ScanADC): '<S59>/ScanADC' */
  ScanADC_Outputs_wrapper();
}

/* Function for Chart: '<S5>/GCULogic' */
static void NEUTRAL_STATE(void)
{
  switch (rtDW.is_NEUTRAL_STATE) {
   case IN_NEUTRAL:
    if ((rtDW.sfEvent == event_GearshiftUp) || (rtDW.sfEvent ==
         event_GearshiftDown)) {
      rtDW.is_NEUTRAL_STATE = IN_UNSET_NEUTRAL;
    } else {
      if (rtDW.RateTransition_d != 0) {
        rtDW.is_NEUTRAL_STATE = IN_NO_NEUTRAL;
      }
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
      time = rtDW.Merge[(int32_T)DEFAULT_NT_CLUTCH_DELAY];
    } else {
      time = rtDW.Merge[(int32_T)DELAY];
    }
  } else if (rtDW.is_UPSHIFTING == IN_UP_PUSH) {
    if (rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) {
      time = rtDW.Merge[(int32_T)NT_CLUTCH_DELAY];
    } else {
      switch (rtDW.RateTransition_d) {
       case 1:
        time = rtDW.Merge[(int32_T)UP_PUSH_1_2];
        break;

       case 2:
        time = rtDW.Merge[(int32_T)UP_PUSH_2_3];
        break;

       case 3:
        time = rtDW.Merge[(int32_T)UP_PUSH_3_4];
        break;

       case 4:
        time = rtDW.Merge[(int32_T)UP_PUSH_4_5];
        break;

       default:
        time = rtDW.Merge[(int32_T)UP_PUSH_2_3];
        break;
      }
    }
  } else if (rtDW.is_UPSHIFTING == IN_UP_REBOUND) {
    if (rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) {
      time = rtDW.Merge[(int32_T)NT_REBOUND_1_N];
    } else {
      time = rtDW.Merge[(int32_T)UP_REBOUND];
    }
  } else if (rtDW.is_UPSHIFTING == IN_UP_BRAKE) {
    if (rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) {
      time = rtDW.Merge[(int32_T)NT_BRAKE_1_N];
    } else {
      time = rtDW.Merge[(int32_T)UP_BRAKE];
    }
  } else if (rtDW.is_DOWNSHIFTING == IN_DOWN_START) {
    time = rtDW.Merge[(int32_T)CLUTCH];
  } else if (rtDW.is_DOWNSHIFTING == IN_DOWN_PUSH) {
    time = rtDW.Merge[(int32_T)DN_PUSH];
  } else if (rtDW.is_DOWNSHIFTING == IN_DOWN_REBOUND) {
    time = rtDW.Merge[(int32_T)DN_REBOUND];
  } else {
    time = rtDW.Merge[(int32_T)DN_BRAKE];
  }

  return time;
}

/* Function for Chart: '<S5>/GCULogic' */
static void Clutch_setValue(uint8_T setValue)
{
  uint8_T tmp;
  rtDW.clutchCurrVal = setValue;

  /* Outputs for Function Call SubSystem: '<S40>/ClutchMotor SetPosition ' */
  /* Saturate: '<S48>/Saturation' */
  if (rtDW.clutchCurrVal < 100) {
    tmp = rtDW.clutchCurrVal;
  } else {
    tmp = 100U;
  }

  /* End of Saturate: '<S48>/Saturation' */

  /* Sum: '<S48>/Minus' incorporates:
   *  Constant: '<S48>/Constant'
   */
  rtDW.Minus = (uint8_T)(100 - tmp);

  /* S-Function (ClutchMotor_setPosition): '<S48>/ClutchMotor SetPosition' */
  ClutchMotor_setPosition_Outputs_wrapper(&rtDW.Minus);

  /* End of Outputs for SubSystem: '<S40>/ClutchMotor SetPosition ' */
}

/* Function for Chart: '<S5>/GCULogic' */
static void GEARSHIFT(void)
{
  uint8_T Pin_In2;
  int32_T q0;
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

          /* Outputs for Function Call SubSystem: '<S45>/Gearmotor_release' */
          Gearmotor_release();

          /* End of Outputs for SubSystem: '<S45>/Gearmotor_release' */
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

          /* Outputs for Function Call SubSystem: '<S45>/Gearmotor_release' */
          Gearmotor_release();

          /* End of Outputs for SubSystem: '<S45>/Gearmotor_release' */
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

            /* Outputs for Function Call SubSystem: '<S45>/Gearmotor_brake' */
            Gearmotor_brake(&rtDW.Pin_In1, &Pin_In2, &rtDW.Pin_H,
                            &rtDW.Gearmotor_brake_c);

            /* End of Outputs for SubSystem: '<S45>/Gearmotor_brake' */
          }
        } else {
          if (rtDW.is_DOWN_BRAKE != IN_Default_o) {
            rtDW.is_DOWN_BRAKE = IN_Default_o;

            /* Outputs for Function Call SubSystem: '<S45>/Gearmotor_brake' */
            Gearmotor_brake(&rtDW.Pin_In1, &Pin_In2, &rtDW.Pin_H,
                            &rtDW.Gearmotor_brake_c);

            /* End of Outputs for SubSystem: '<S45>/Gearmotor_brake' */
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

          /* Outputs for Function Call SubSystem: '<S45>/Gearmotor_turnLeft' */
          /* S-Function (GearMotor_turnLeft): '<S62>/GearMotor Turn Left' */
          GearMotor_turnLeft_Outputs_wrapper(&rtDW.GearMotorTurnLeft_o1,
            &rtDW.GearMotorTurnLeft_o2, &rtDW.GearMotorTurnLeft_o3);

          /* SignalConversion: '<S62>/OutportBufferForPin_H' */
          rtDW.Pin_H = rtDW.GearMotorTurnLeft_o3;

          /* SignalConversion: '<S62>/OutportBufferForPin_In1' */
          rtDW.Pin_In1 = rtDW.GearMotorTurnLeft_o1;

          /* End of Outputs for SubSystem: '<S45>/Gearmotor_turnLeft' */
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
    if ((rtDW.sfEvent == event_GearshiftUp) && (rtDW.RateTransition_d < 5)) {
      rtDW.is_GEARSHIFT = IN_UPSHIFTING;
      if (rtDW.is_UPSHIFTING != IN_UP_START) {
        rtDW.is_UPSHIFTING = IN_UP_START;
        q0 = Gearshift_getTime();
        if (q0 > 2147483646) {
          rtDW.ticksCounter = MAX_int32_T;
        } else {
          rtDW.ticksCounter = q0 + 1;
        }
      }

      if (rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) {
        if (rtDW.is_UP_START != IN_SettingNeutral) {
          rtDW.is_UP_START = IN_SettingNeutral;
          Clutch_setValue(80);
        }
      } else {
        if (rtDW.is_UP_START != IN_Default) {
          rtDW.is_UP_START = IN_Default;

          /* Outputs for Function Call SubSystem: '<S41>/SetCut' */

          /* S-Function (Efi_setCut): '<S50>/Efi SetCut' */
          Efi_setCut_Outputs_wrapper(&rtDW.EfiSetCut);

          /* End of Outputs for SubSystem: '<S41>/SetCut' */
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
          if (rtDW.is_DOWN_START != IN_SettingNeutral_b) {
            rtDW.is_DOWN_START = IN_SettingNeutral_b;
            Clutch_setValue(80);
          }
        } else if ((!(rtDW.is_NEUTRAL_STATE == IN_UNSET_NEUTRAL)) &&
                   (rtDW.clutchCurrVal <= 60)) {
          if (rtDW.is_DOWN_START != IN_ChangeClutch) {
            rtDW.is_DOWN_START = IN_ChangeClutch;
            Clutch_setValue(60);
          }
        } else {
          rtDW.is_DOWN_START = IN_Default_o;
        }
      }
    }
    break;

   case IN_INIT_jf:
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

          /* Outputs for Function Call SubSystem: '<S45>/Gearmotor_release' */
          Gearmotor_release();

          /* End of Outputs for SubSystem: '<S45>/Gearmotor_release' */
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

            /* Outputs for Function Call SubSystem: '<S45>/Gearmotor_release' */
            Gearmotor_release();

            /* End of Outputs for SubSystem: '<S45>/Gearmotor_release' */
          }
        } else {
          if (rtDW.is_UP_REBOUND != IN_Default) {
            rtDW.is_UP_REBOUND = IN_Default;

            /* Outputs for Function Call SubSystem: '<S45>/Gearmotor_release' */
            Gearmotor_release();

            /* End of Outputs for SubSystem: '<S45>/Gearmotor_release' */
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

          /* Outputs for Function Call SubSystem: '<S45>/Gearmotor_brake' */
          Gearmotor_brake(&rtDW.Pin_In1, &Pin_In2, &rtDW.Pin_H,
                          &rtDW.Gearmotor_brake_c);

          /* End of Outputs for SubSystem: '<S45>/Gearmotor_brake' */
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

            /* Outputs for Function Call SubSystem: '<S41>/UnsetCut' */

            /* S-Function (Efi_unsetCut): '<S52>/Efi UnSetCut' */
            Efi_unsetCut_Outputs_wrapper(&rtDW.EfiUnSetCut);

            /* End of Outputs for SubSystem: '<S41>/UnsetCut' */

            /* Outputs for Function Call SubSystem: '<S45>/Gearmotor_turnRight' */
            Gearmotor_turnRight(&rtDW.Pin_In1, &Pin_In2, &rtDW.Pin_H,
                                &rtDW.Gearmotor_turnRight_f);

            /* End of Outputs for SubSystem: '<S45>/Gearmotor_turnRight' */
          }
        } else {
          if (rtDW.is_UP_PUSH != IN_Default_o) {
            rtDW.is_UP_PUSH = IN_Default_o;

            /* Outputs for Function Call SubSystem: '<S45>/Gearmotor_turnRight' */
            Gearmotor_turnRight(&rtDW.Pin_In1, &Pin_In2, &rtDW.Pin_H,
                                &rtDW.Gearmotor_turnRight_f);

            /* End of Outputs for SubSystem: '<S45>/Gearmotor_turnRight' */
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
static int32_T getAacParam(acc_params b_index)
{
  return rtDW.Merge1[b_index];
}

/* Function for Chart: '<S5>/GCULogic' */
static void aacCheckShift(void)
{
  int32_T b_previousEvent;
  if ((rtDW.lastShift == rtDW.RateTransition_d) && (rtDW.RateTransition1_c[RPM] >=
       rtDW.Merge1[((int32_T)RPM_LIMIT_1_2 + rtDW.RateTransition_d) - 1]) &&
      (rtDW.RateTransition1_c[WHEEL_SPEED] >= rtDW.Merge1[((int32_T)
        SPEED_LIMIT_1_2 + rtDW.RateTransition_d) - 1])) {
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

/* Function for Chart: '<S5>/GCULogic' */
static void checkClutch(void)
{
  if ((rtDW.Cast1_k != rtDW.clutchCurrVal) && (((!(rtDW.is_GEARSHIFT ==
          IN_DOWNSHIFTING)) && (!(rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL))) ||
       (rtDW.is_NEUTRAL_STATE == IN_UNSET_NEUTRAL))) {
    Clutch_setValue(rtDW.Cast1_k);
  }
}

/* Function for Chart: '<S5>/GCULogic' */
static void enter_atomic_MANUAL_MODES(void)
{
  rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
  rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
  checkShift();
  checkClutch();
}

/* Function for Chart: '<S5>/GCULogic' */
static void ACCELERATION(void)
{
  uint8_T Merge2_i;
  int32_T q0;
  int32_T q1;
  int64_T tmp;
  if ((rtDW.RateTransition8[0] != rtDW.lastModeCom[0]) && (rtDW.RateTransition8
       [1] != rtDW.lastModeCom[1])) {
    /* Outputs for Function Call SubSystem: '<S41>/UnsetRPMLimiter' */
    UnsetRPMLimiter(&Merge2_i, &rtDW.UnsetRPMLimiter_c);

    /* End of Outputs for SubSystem: '<S41>/UnsetRPMLimiter' */
    rtDW.stateFb = (uint16_T)ACC_OFF;
    Clutch_setValue(0);
    if (rtDW.RateTransition8[1] == ENDURANCE_MODE) {
      rtDW.is_ACTIVE = 0;
      rtDW.is_ACC = 0;
      rtDW.is_ACCELERATION = 0;
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        enter_atomic_MANUAL_MODES();
      }
    } else if (rtDW.RateTransition8[1] == SKIDPAD_MODE) {
      rtDW.is_ACTIVE = 0;
      rtDW.is_ACC = 0;
      rtDW.is_ACCELERATION = 0;
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        enter_atomic_MANUAL_MODES();
      }
    } else if (rtDW.RateTransition8[1] == ACCELERATION_MODE) {
      rtDW.is_ACTIVE = 0;
      rtDW.is_ACC = 0;
      rtDW.is_ACCELERATION = 0;
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_ACCELERATION) {
        rtDW.is_MODES = IN_ACCELERATION;
        rtDW.lastAacCom = rtDW.RateTransition4[0];
        rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
        rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
      }

      if (rtDW.is_ACCELERATION != IN_DEFAULT) {
        rtDW.is_ACCELERATION = IN_DEFAULT;
        rtDW.stateFb = (uint16_T)ACC_OFF;
        checkShift();
        checkClutch();
      }
    } else if (rtDW.RateTransition8[1] == AUTOX_MODE) {
      rtDW.is_ACTIVE = 0;
      rtDW.is_ACC = 0;
      rtDW.is_ACCELERATION = 0;
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_AUTOCROSS) {
        rtDW.is_MODES = IN_AUTOCROSS;
        rtDW.lastAutoXCom = rtDW.RateTransition29[0];
        rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
        rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
      }

      if (rtDW.is_AUTOCROSS != IN_DEFAULT_e) {
        rtDW.is_AUTOCROSS = IN_DEFAULT_e;
        rtDW.stateFb = (uint16_T)AUTOX_DEFAULT;
        checkShift();
        checkClutch();
      }
    } else {
      rtDW.is_ACTIVE = 0;
      rtDW.is_ACC = 0;
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
     case IN_ACC:
      switch (rtDW.is_ACC) {
       case IN_ACTIVE:
        if ((rtDW.RateTransition4[0] != rtDW.lastAacCom) &&
            (rtDW.RateTransition4[1] == ACC_OFF)) {
          rtDW.lastAacCom = rtDW.RateTransition4[0];
          rtDW.is_ACTIVE = 0;
          rtDW.is_ACC = 0;
          if (rtDW.is_ACC != IN_STOPPING) {
            rtDW.is_ACC = IN_STOPPING;

            /* Outputs for Function Call SubSystem: '<S41>/UnsetRPMLimiter' */
            UnsetRPMLimiter(&Merge2_i, &rtDW.UnsetRPMLimiter_c);

            /* End of Outputs for SubSystem: '<S41>/UnsetRPMLimiter' */
            Clutch_setValue(0);

            /* sendUpdatesSW(ACC_CODE, uint16(0)); */
          }
        } else {
          switch (rtDW.is_ACTIVE) {
           case IN_READY:
            if (rtDW.aacCounter <= 1) {
              if ((rtDW.RateTransition4[0] != rtDW.lastAacCom) &&
                  (rtDW.RateTransition4[1] == ACC_GO) &&
                  (rtDW.RateTransition1_c[TPS] >= getAacParam(TPS_START_LIMIT)))
              {
                rtDW.lastAacCom = rtDW.RateTransition4[0];
                rtDW.is_ACTIVE = 0;
                if (rtDW.is_ACTIVE != IN_START_RELEASE) {
                  rtDW.is_ACTIVE = IN_START_RELEASE;
                  rtDW.stateFb = (uint16_T)ACC_GO;
                  rtDW.aac_clutchValue = getAacParam(RAMP_START);
                  if (rtDW.aac_clutchValue < 256.0) {
                    if (rtDW.aac_clutchValue >= 0.0) {
                      Merge2_i = (uint8_T)rtDW.aac_clutchValue;
                    } else {
                      Merge2_i = 0U;
                    }
                  } else {
                    Merge2_i = MAX_uint8_T;
                  }

                  Clutch_setValue(Merge2_i);
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
                }
              } else {
                rtDW.is_ACTIVE = 0;
                if (rtDW.is_ACTIVE != IN_READY) {
                  rtDW.is_ACTIVE = IN_READY;
                  rtDW.stateFb = (uint16_T)ACC_READY;
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

                /* Outputs for Function Call SubSystem: '<S41>/UnsetRPMLimiter' */
                UnsetRPMLimiter(&Merge2_i, &rtDW.UnsetRPMLimiter_c);

                /* End of Outputs for SubSystem: '<S41>/UnsetRPMLimiter' */
                rtDW.is_ACTIVE = 0;
                if (rtDW.is_ACTIVE != IN_RUNNING) {
                  rtDW.is_ACTIVE = IN_RUNNING;
                  rtDW.aacCounter = AAC_WORK_RATE_ms;
                  rtDW.lastShift = rtDW.RateTransition_d;
                  aacCheckShift();
                }
              } else {
                rtDW.is_ACTIVE = 0;
                if (rtDW.is_ACTIVE != IN_RELEASING) {
                  rtDW.is_ACTIVE = IN_RELEASING;
                  rtDW.aac_clutchValue -= rtDW.aac_clutchStep;
                  if (rtDW.aac_clutchValue < 256.0) {
                    if (rtDW.aac_clutchValue >= 0.0) {
                      Merge2_i = (uint8_T)rtDW.aac_clutchValue;
                    } else {
                      Merge2_i = 0U;
                    }
                  } else {
                    Merge2_i = MAX_uint8_T;
                  }

                  Clutch_setValue(Merge2_i);
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
            if (rtDW.RateTransition_d >= 5) {
              rtDW.is_ACTIVE = 0;
              rtDW.is_ACC = 0;
              if (rtDW.is_ACC != IN_STOPPING) {
                rtDW.is_ACC = IN_STOPPING;

                /* Outputs for Function Call SubSystem: '<S41>/UnsetRPMLimiter' */
                UnsetRPMLimiter(&Merge2_i, &rtDW.UnsetRPMLimiter_c);

                /* End of Outputs for SubSystem: '<S41>/UnsetRPMLimiter' */
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
                rtDW.stateFb = (uint16_T)ACC_READY;
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
                    Merge2_i = (uint8_T)rtDW.aac_clutchValue;
                  } else {
                    Merge2_i = 0U;
                  }
                } else {
                  Merge2_i = MAX_uint8_T;
                }

                Clutch_setValue(Merge2_i);
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
        rtDW.is_ACC = 0;
        rtDW.is_ACCELERATION = 0;
        if (rtDW.is_ACCELERATION != IN_DEFAULT) {
          rtDW.is_ACCELERATION = IN_DEFAULT;
          rtDW.stateFb = (uint16_T)ACC_OFF;
          checkShift();
          checkClutch();
        }
        break;
      }
      break;

     case IN_DEFAULT:
      if ((rtDW.RateTransition4[0] != rtDW.lastAacCom) && (rtDW.RateTransition4
           [1] == ACC_READY)) {
        rtDW.lastAacCom = rtDW.RateTransition4[0];
        rtDW.is_ACCELERATION = IN_ACC;
        rtDW.aacCounter = 0U;
        rtDW.aac_clutchValue = 0.0;
        rtDW.aac_clutchStep = 0.0;
        rtDW.aac_dtRelease = 0;
        rtDW.is_ACC = IN_ACTIVE;
        if (rtDW.is_ACTIVE != IN_START) {
          rtDW.is_ACTIVE = IN_START;
          rtDW.stateFb = (uint16_T)ACC_READY;
          rtDW.aacCounter = AAC_WORK_RATE_ms;

          /* Outputs for Function Call SubSystem: '<S41>/SetRPMLimiter' */
          SetRPMLimiter(&Merge2_i, &rtDW.SetRPMLimiter_e);

          /* End of Outputs for SubSystem: '<S41>/SetRPMLimiter' */
          Clutch_setValue(100);
        }
      } else {
        rtDW.stateFb = (uint16_T)ACC_OFF;
        checkShift();
        checkClutch();
      }
      break;
    }
  }
}

/* Function for Chart: '<S5>/GCULogic' */
static int32_T getAutoXParam(autoX_params b_index)
{
  return rtDW.Merge2[b_index];
}

/* Function for Chart: '<S5>/GCULogic' */
static void autoXCheckShift(void)
{
  int32_T b_previousEvent;
  if ((rtDW.lastShift == rtDW.RateTransition_d) && (rtDW.RateTransition1_c[RPM] >=
       rtDW.Merge2[((int32_T)AUTOX_RPM_LIMIT_1_2 + rtDW.RateTransition_d) - 1]) &&
      (rtDW.RateTransition1_c[WHEEL_SPEED] >= rtDW.Merge2[((int32_T)
        AUTOX_SPEED_LIMIT_1_2 + rtDW.RateTransition_d) - 1])) {
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

/* Function for Chart: '<S5>/GCULogic' */
static void AUTOCROSS(void)
{
  uint8_T Merge2_i;
  int32_T q0;
  int32_T q1;
  int64_T tmp;
  if ((rtDW.RateTransition8[0] != rtDW.lastModeCom[0]) && (rtDW.RateTransition8
       [1] != rtDW.lastModeCom[1])) {
    /* Outputs for Function Call SubSystem: '<S41>/UnsetRPMLimiter' */
    UnsetRPMLimiter(&Merge2_i, &rtDW.UnsetRPMLimiter_c);

    /* End of Outputs for SubSystem: '<S41>/UnsetRPMLimiter' */
    rtDW.stateFb = (uint16_T)ACC_OFF;
    Clutch_setValue(0);
    if (rtDW.RateTransition8[1] == ENDURANCE_MODE) {
      rtDW.is_ACTIVE_d = 0;
      rtDW.is_LAUNCH = 0;
      rtDW.is_AUTOCROSS = 0;
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        enter_atomic_MANUAL_MODES();
      }
    } else if (rtDW.RateTransition8[1] == SKIDPAD_MODE) {
      rtDW.is_ACTIVE_d = 0;
      rtDW.is_LAUNCH = 0;
      rtDW.is_AUTOCROSS = 0;
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        enter_atomic_MANUAL_MODES();
      }
    } else if (rtDW.RateTransition8[1] == ACCELERATION_MODE) {
      rtDW.is_ACTIVE_d = 0;
      rtDW.is_LAUNCH = 0;
      rtDW.is_AUTOCROSS = 0;
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_ACCELERATION) {
        rtDW.is_MODES = IN_ACCELERATION;
        rtDW.lastAacCom = rtDW.RateTransition4[0];
        rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
        rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
      }

      if (rtDW.is_ACCELERATION != IN_DEFAULT) {
        rtDW.is_ACCELERATION = IN_DEFAULT;
        rtDW.stateFb = (uint16_T)ACC_OFF;
        checkShift();
        checkClutch();
      }
    } else if (rtDW.RateTransition8[1] == AUTOX_MODE) {
      rtDW.is_ACTIVE_d = 0;
      rtDW.is_LAUNCH = 0;
      rtDW.is_AUTOCROSS = 0;
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_AUTOCROSS) {
        rtDW.is_MODES = IN_AUTOCROSS;
        rtDW.lastAutoXCom = rtDW.RateTransition29[0];
        rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
        rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
      }

      if (rtDW.is_AUTOCROSS != IN_DEFAULT_e) {
        rtDW.is_AUTOCROSS = IN_DEFAULT_e;
        rtDW.stateFb = (uint16_T)AUTOX_DEFAULT;
        checkShift();
        checkClutch();
      }
    } else {
      rtDW.is_ACTIVE_d = 0;
      rtDW.is_LAUNCH = 0;
      rtDW.is_AUTOCROSS = 0;
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
    switch (rtDW.is_AUTOCROSS) {
     case IN_DEFAULT_e:
      if ((rtDW.RateTransition29[0] != rtDW.lastAutoXCom) &&
          (rtDW.RateTransition29[1] == AUTOX_READY)) {
        rtDW.lastAutoXCom = rtDW.RateTransition29[0];
        rtDW.is_AUTOCROSS = IN_LAUNCH;
        rtDW.autoXCounter = 0U;
        rtDW.autoX_clutchValue = 0.0;
        rtDW.autoX_clutchStep = 0.0;
        rtDW.autoX_dtRelease = 0;
        rtDW.is_LAUNCH = IN_ACTIVE;
        if (rtDW.is_ACTIVE_d != IN_START) {
          rtDW.is_ACTIVE_d = IN_START;
          rtDW.stateFb = (uint16_T)AUTOX_READY;
          rtDW.autoXCounter = AUTOX_WORK_RATE_ms;

          /* Outputs for Function Call SubSystem: '<S41>/SetRPMLimiter' */
          SetRPMLimiter(&Merge2_i, &rtDW.SetRPMLimiter_e);

          /* End of Outputs for SubSystem: '<S41>/SetRPMLimiter' */
          Clutch_setValue(100);
        }
      } else {
        rtDW.stateFb = (uint16_T)AUTOX_DEFAULT;
        checkShift();
        checkClutch();
      }
      break;

     case IN_LAUNCH:
      switch (rtDW.is_LAUNCH) {
       case IN_ACTIVE:
        if ((rtDW.RateTransition29[0] != rtDW.lastAutoXCom) &&
            (rtDW.RateTransition29[1] == AUTOX_DEFAULT)) {
          rtDW.lastAutoXCom = rtDW.RateTransition29[0];
          rtDW.is_ACTIVE_d = 0;
          rtDW.is_LAUNCH = 0;
          if (rtDW.is_LAUNCH != IN_STOPPING) {
            rtDW.is_LAUNCH = IN_STOPPING;

            /* Outputs for Function Call SubSystem: '<S41>/UnsetRPMLimiter' */
            UnsetRPMLimiter(&Merge2_i, &rtDW.UnsetRPMLimiter_c);

            /* End of Outputs for SubSystem: '<S41>/UnsetRPMLimiter' */
            Clutch_setValue(0);
          }
        } else {
          switch (rtDW.is_ACTIVE_d) {
           case IN_READY:
            if (rtDW.autoXCounter <= 1) {
              if ((rtDW.RateTransition29[0] != rtDW.lastAutoXCom) &&
                  (rtDW.RateTransition29[1] == AUTOX_GO) &&
                  (rtDW.RateTransition1_c[TPS] >= getAutoXParam
                   (AUTOX_TPS_START_LIMIT))) {
                rtDW.lastAutoXCom = rtDW.RateTransition29[0];
                rtDW.is_ACTIVE_d = 0;
                if (rtDW.is_ACTIVE_d != IN_START_RELEASE) {
                  rtDW.is_ACTIVE_d = IN_START_RELEASE;
                  rtDW.stateFb = (uint16_T)AUTOX_GO;
                  rtDW.autoX_clutchValue = getAutoXParam(AUTOX_RAMP_START);
                  if (rtDW.autoX_clutchValue < 256.0) {
                    if (rtDW.autoX_clutchValue >= 0.0) {
                      Merge2_i = (uint8_T)rtDW.autoX_clutchValue;
                    } else {
                      Merge2_i = 0U;
                    }
                  } else {
                    Merge2_i = MAX_uint8_T;
                  }

                  Clutch_setValue(Merge2_i);
                  rtDW.autoX_dtRelease = getAutoXParam(AUTOX_RAMP_TIME) /
                    AUTOX_WORK_RATE_ms;
                  q0 = getAutoXParam(AUTOX_RAMP_START);
                  q1 = getAutoXParam(AUTOX_RAMP_END);
                  if ((q0 >= 0) && (q1 < q0 - MAX_int32_T)) {
                    q0 = MAX_int32_T;
                  } else if ((q0 < 0) && (q1 > q0 - MIN_int32_T)) {
                    q0 = MIN_int32_T;
                  } else {
                    q0 -= q1;
                  }

                  tmp = (int64_T)q0 * AUTOX_WORK_RATE_ms;
                  if (tmp > 2147483647LL) {
                    tmp = 2147483647LL;
                  } else {
                    if (tmp < -2147483648LL) {
                      tmp = -2147483648LL;
                    }
                  }

                  rtDW.autoX_clutchStep = (real_T)(int32_T)tmp / (real_T)
                    getAutoXParam(AUTOX_RAMP_TIME);
                  rtDW.autoXCounter = AUTOX_WORK_RATE_ms;
                }
              } else {
                rtDW.is_ACTIVE_d = 0;
                if (rtDW.is_ACTIVE_d != IN_READY) {
                  rtDW.is_ACTIVE_d = IN_READY;
                  rtDW.stateFb = (uint16_T)AUTOX_READY;
                  rtDW.autoXCounter = AUTOX_WORK_RATE_ms;
                  Clutch_setValue(100);
                  checkShift();
                }
              }
            } else {
              q0 = rtDW.autoXCounter - 1;
              if (q0 < 0) {
                q0 = 0;
              }

              rtDW.autoXCounter = (uint16_T)q0;
              checkShift();
            }
            break;

           case IN_RELEASING:
            if (rtDW.autoXCounter <= 1) {
              if ((rtDW.autoX_dtRelease <= 0) || (rtDW.clutchCurrVal <=
                   getAutoXParam(AUTOX_RAMP_END))) {
                Clutch_setValue(0);

                /* Outputs for Function Call SubSystem: '<S41>/UnsetRPMLimiter' */
                UnsetRPMLimiter(&Merge2_i, &rtDW.UnsetRPMLimiter_c);

                /* End of Outputs for SubSystem: '<S41>/UnsetRPMLimiter' */
                rtDW.is_ACTIVE_d = 0;
                if (rtDW.is_ACTIVE_d != IN_RUNNING) {
                  rtDW.is_ACTIVE_d = IN_RUNNING;
                  rtDW.autoXCounter = AUTOX_WORK_RATE_ms;
                  rtDW.lastShift = rtDW.RateTransition_d;
                  autoXCheckShift();
                }
              } else {
                rtDW.is_ACTIVE_d = 0;
                if (rtDW.is_ACTIVE_d != IN_RELEASING) {
                  rtDW.is_ACTIVE_d = IN_RELEASING;
                  rtDW.autoX_clutchValue -= rtDW.autoX_clutchStep;
                  if (rtDW.autoX_clutchValue < 256.0) {
                    if (rtDW.autoX_clutchValue >= 0.0) {
                      Merge2_i = (uint8_T)rtDW.autoX_clutchValue;
                    } else {
                      Merge2_i = 0U;
                    }
                  } else {
                    Merge2_i = MAX_uint8_T;
                  }

                  Clutch_setValue(Merge2_i);
                  if (rtDW.autoX_dtRelease < -2147483647) {
                    rtDW.autoX_dtRelease = MIN_int32_T;
                  } else {
                    rtDW.autoX_dtRelease--;
                  }

                  rtDW.autoXCounter = AUTOX_WORK_RATE_ms;
                }
              }
            } else {
              q0 = rtDW.autoXCounter - 1;
              if (q0 < 0) {
                q0 = 0;
              }

              rtDW.autoXCounter = (uint16_T)q0;
            }
            break;

           case IN_RUNNING:
            if (rtDW.RateTransition_d >= 5) {
              rtDW.is_ACTIVE_d = 0;
              rtDW.is_LAUNCH = 0;
              if (rtDW.is_LAUNCH != IN_STOPPING) {
                rtDW.is_LAUNCH = IN_STOPPING;

                /* Outputs for Function Call SubSystem: '<S41>/UnsetRPMLimiter' */
                UnsetRPMLimiter(&Merge2_i, &rtDW.UnsetRPMLimiter_c);

                /* End of Outputs for SubSystem: '<S41>/UnsetRPMLimiter' */
                Clutch_setValue(0);
              }
            } else {
              autoXCheckShift();
            }
            break;

           case IN_START:
            if (rtDW.autoXCounter <= 1) {
              rtDW.is_ACTIVE_d = 0;
              if (rtDW.is_ACTIVE_d != IN_READY) {
                rtDW.is_ACTIVE_d = IN_READY;
                rtDW.stateFb = (uint16_T)AUTOX_READY;
                rtDW.autoXCounter = AUTOX_WORK_RATE_ms;
                Clutch_setValue(100);
                checkShift();
              }
            } else {
              q0 = rtDW.autoXCounter - 1;
              if (q0 < 0) {
                q0 = 0;
              }

              rtDW.autoXCounter = (uint16_T)q0;
            }
            break;

           case IN_START_RELEASE:
            if (rtDW.autoXCounter <= 1) {
              rtDW.is_ACTIVE_d = 0;
              if (rtDW.is_ACTIVE_d != IN_RELEASING) {
                rtDW.is_ACTIVE_d = IN_RELEASING;
                rtDW.autoX_clutchValue -= rtDW.autoX_clutchStep;
                if (rtDW.autoX_clutchValue < 256.0) {
                  if (rtDW.autoX_clutchValue >= 0.0) {
                    Merge2_i = (uint8_T)rtDW.autoX_clutchValue;
                  } else {
                    Merge2_i = 0U;
                  }
                } else {
                  Merge2_i = MAX_uint8_T;
                }

                Clutch_setValue(Merge2_i);
                if (rtDW.autoX_dtRelease < -2147483647) {
                  rtDW.autoX_dtRelease = MIN_int32_T;
                } else {
                  rtDW.autoX_dtRelease--;
                }

                rtDW.autoXCounter = AUTOX_WORK_RATE_ms;
              }
            } else {
              q0 = rtDW.autoXCounter - 1;
              if (q0 < 0) {
                q0 = 0;
              }

              rtDW.autoXCounter = (uint16_T)q0;
            }
            break;
          }
        }
        break;

       case IN_STOPPING:
        rtDW.is_LAUNCH = 0;
        rtDW.is_AUTOCROSS = 0;
        if (rtDW.is_AUTOCROSS != IN_DEFAULT_e) {
          rtDW.is_AUTOCROSS = IN_DEFAULT_e;
          rtDW.stateFb = (uint16_T)AUTOX_DEFAULT;
          checkShift();
          checkClutch();
        }
        break;
      }
      break;
    }
  }
}

/* Function for Chart: '<S5>/GCULogic' */
static void MODES(void)
{
  int32_T tmp;
  switch (rtDW.is_MODES) {
   case IN_ACCELERATION:
    ACCELERATION();
    break;

   case IN_AUTOCROSS:
    AUTOCROSS();
    break;

   case IN_INIT_j:
    if (rtDW.buzzerCounter >= 1000) {
      /* Outputs for Function Call SubSystem: '<S39>/BuzzerOff' */

      /* S-Function (stopBuzzer): '<S46>/BuzzerOff' */
      stopBuzzer_Outputs_wrapper();

      /* End of Outputs for SubSystem: '<S39>/BuzzerOff' */
      if (rtDW.RateTransition8[1] == ENDURANCE_MODE) {
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
      } else if (rtDW.RateTransition8[1] == ACCELERATION_MODE) {
        rtDW.is_MODES = 0;
        if (rtDW.is_MODES != IN_ACCELERATION) {
          rtDW.is_MODES = IN_ACCELERATION;
          rtDW.lastAacCom = rtDW.RateTransition4[0];
          rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
          rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
        }

        if (rtDW.is_ACCELERATION != IN_DEFAULT) {
          rtDW.is_ACCELERATION = IN_DEFAULT;
          rtDW.stateFb = (uint16_T)ACC_OFF;
          checkShift();
          checkClutch();
        }
      } else if (rtDW.RateTransition8[1] == AUTOX_MODE) {
        rtDW.is_MODES = 0;
        if (rtDW.is_MODES != IN_AUTOCROSS) {
          rtDW.is_MODES = IN_AUTOCROSS;
          rtDW.lastAutoXCom = rtDW.RateTransition29[0];
          rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
          rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
        }

        if (rtDW.is_AUTOCROSS != IN_DEFAULT_e) {
          rtDW.is_AUTOCROSS = IN_DEFAULT_e;
          rtDW.stateFb = (uint16_T)AUTOX_DEFAULT;
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
      tmp = rtDW.buzzerCounter + 1;
      if (tmp > 65535) {
        tmp = 65535;
      }

      rtDW.buzzerCounter = (uint16_T)tmp;
    }
    break;

   case IN_MANUAL_MODES:
    if ((rtDW.RateTransition8[0] != rtDW.lastModeCom[0]) &&
        (rtDW.RateTransition8[1] != rtDW.lastModeCom[1])) {
      if (rtDW.RateTransition8[1] == ENDURANCE_MODE) {
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
      } else if (rtDW.RateTransition8[1] == ACCELERATION_MODE) {
        rtDW.is_MODES = 0;
        if (rtDW.is_MODES != IN_ACCELERATION) {
          rtDW.is_MODES = IN_ACCELERATION;
          rtDW.lastAacCom = rtDW.RateTransition4[0];
          rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
          rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
        }

        if (rtDW.is_ACCELERATION != IN_DEFAULT) {
          rtDW.is_ACCELERATION = IN_DEFAULT;
          rtDW.stateFb = (uint16_T)ACC_OFF;
          checkShift();
          checkClutch();
        }
      } else if (rtDW.RateTransition8[1] == AUTOX_MODE) {
        rtDW.is_MODES = 0;
        if (rtDW.is_MODES != IN_AUTOCROSS) {
          rtDW.is_MODES = IN_AUTOCROSS;
          rtDW.lastAutoXCom = rtDW.RateTransition29[0];
          rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
          rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
        }

        if (rtDW.is_AUTOCROSS != IN_DEFAULT_e) {
          rtDW.is_AUTOCROSS = IN_DEFAULT_e;
          rtDW.stateFb = (uint16_T)AUTOX_DEFAULT;
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

/* Function for Chart: '<S2>/EEPROM_OutputRequest' */
static void createRequest(uint8_T operation, uint8_T page, uint8_T cell, uint8_T
  dataSize, const uint8_T tempData[16])
{
  int32_T i;
  rtDW.outputRequest.operation = operation;
  rtDW.outputRequest.page = page;
  rtDW.outputRequest.cell = cell;
  rtDW.outputRequest.dataSize = dataSize;
  for (i = 0; i < 16; i++) {
    rtDW.outputRequest.data[i] = tempData[i];
  }
}

/* Function for Chart: '<S2>/EEPROM_OutputRequest' */
static void extractValues(uint8_T count)
{
  int32_T b_index;
  int32_T tmp;
  uint8_T count_0;
  if (count > 15) {
    count_0 = MAX_uint8_T;
  } else {
    count_0 = (uint8_T)(count << 4);
  }

  for (b_index = 0; b_index < 16; b_index++) {
    /* NEW_PATTERN */
    tmp = (b_index + count_0) + 1;
    if (tmp > 255) {
      tmp = 255;
    }

    rtDW.newData[b_index] = rtDW.tempShiftedArray[tmp - 1];
  }
}

/* Function for Chart: '<S2>/EEPROM_OutputRequest' */
static void shiftArray_h(const int32_T array[12], real_T nValues)
{
  real_T b_index;
  int32_T i;
  for (i = 0; i < 50; i++) {
    rtDW.tempShiftedArray[i] = 0U;
  }

  for (b_index = 1.0; b_index <= nValues; b_index++) {
    /* NEW_PATTERN */
    i = array[(int32_T)b_index - 1] >> 8;
    if (i < 0) {
      i = 0;
    } else {
      if (i > 255) {
        i = 255;
      }
    }

    rtDW.tempShiftedArray[(int32_T)(2.0 * b_index - 1.0) - 1] = (uint8_T)i;
    i = array[(int32_T)b_index - 1];
    if (array[(int32_T)b_index - 1] < 0) {
      i = 0;
    } else {
      if (array[(int32_T)b_index - 1] > 65535) {
        i = 65535;
      }
    }

    rtDW.tempShiftedArray[(int32_T)(2.0 * b_index) - 1] = (uint8_T)(i & 255);
  }
}

/* Function for Chart: '<S2>/EEPROM_OutputRequest' */
static void shiftArray(const int32_T array[23], real_T nValues)
{
  real_T b_index;
  int32_T i;
  for (i = 0; i < 50; i++) {
    rtDW.tempShiftedArray[i] = 0U;
  }

  for (b_index = 1.0; b_index <= nValues; b_index++) {
    /* NEW_PATTERN */
    i = array[(int32_T)b_index - 1] >> 8;
    if (i < 0) {
      i = 0;
    } else {
      if (i > 255) {
        i = 255;
      }
    }

    rtDW.tempShiftedArray[(int32_T)(2.0 * b_index - 1.0) - 1] = (uint8_T)i;
    i = array[(int32_T)b_index - 1];
    if (array[(int32_T)b_index - 1] < 0) {
      i = 0;
    } else {
      if (array[(int32_T)b_index - 1] > 65535) {
        i = 65535;
      }
    }

    rtDW.tempShiftedArray[(int32_T)(2.0 * b_index) - 1] = (uint8_T)(i & 255);
  }
}

/* Function for Chart: '<S2>/EEPROM_OutputRequest' */
static void updateOutput(void)
{
  int32_T i;
  if (rtDW.lastEvaluatedIndex >= 20.0) {
    rtDW.lastEvaluatedIndex = 1.0;
  } else {
    rtDW.lastEvaluatedIndex++;
  }

  rtDW.outputRequest.operation = rtDW.RateTransition[(int32_T)
    rtDW.lastEvaluatedIndex - 1].operation;
  rtDW.outputRequest.page = rtDW.RateTransition[(int32_T)rtDW.lastEvaluatedIndex
    - 1].page;
  rtDW.outputRequest.cell = rtDW.RateTransition[(int32_T)rtDW.lastEvaluatedIndex
    - 1].cell;
  rtDW.outputRequest.dataSize = rtDW.RateTransition[(int32_T)
    rtDW.lastEvaluatedIndex - 1].dataSize;
  for (i = 0; i < 16; i++) {
    rtDW.outputRequest.data[i] = rtDW.RateTransition[(int32_T)
      rtDW.lastEvaluatedIndex - 1].data[i];
  }
}

/* Function for Chart: '<S2>/EEPROM_OutputRequest' */
static void testIndex(void)
{
  if (rtDW.RateTransition1 != rtDW.lastEvaluatedIndex) {
    updateOutput();

    /* Outputs for Function Call SubSystem: '<S2>/Evaluate_Request' */
    Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                     rtDW.load_default_timings, rtDW.load_accParameters1,
                     &rtDW.Eeprom_write_o1, &rtDW.Eeprom_read_o1,
                     &rtDW.Eeprom_write_o2, rtDW.OutportBufferFordataRead,
                     rtDW.Merge, rtDW.Merge1, rtDW.Merge2,
                     &rtDW.Evaluate_Request_l);

    /* End of Outputs for SubSystem: '<S2>/Evaluate_Request' */
    if (rtDW.outputRequest.operation == 87) {
      rtDW.reloadFlag = 1.0;
    }
  }
}

/* Function for Chart: '<S7>/AccelerationRoutine' */
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

/* Function for Chart: '<S7>/AccelerationRoutine' */
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

/* Function for Chart: '<S4>/MessageEvaluation1' */
static void sendAutoXCommand(uint16_T com)
{
  int32_T tmp;
  if (rtDW.autoXCommand[0] >= 255) {
    rtDW.autoXCommand[0] = 0U;
  } else {
    tmp = rtDW.autoXCommand[0] + 1;
    if (tmp > 65535) {
      tmp = 65535;
    }

    rtDW.autoXCommand[0] = (uint16_T)tmp;
  }

  rtDW.autoXCommand[1] = com;
}

/* Function for Chart: '<S4>/MessageEvaluation1' */
static void sendAccCommand(uint16_T com)
{
  int32_T tmp;
  if (rtDW.accCommand[0] >= 255) {
    rtDW.accCommand[0] = 0U;
  } else {
    tmp = rtDW.accCommand[0] + 1;
    if (tmp > 65535) {
      tmp = 65535;
    }

    rtDW.accCommand[0] = (uint16_T)tmp;
  }

  rtDW.accCommand[1] = com;
}

/* Function for Chart: '<S4>/MessageEvaluation1' */
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

/* Function for Chart: '<S4>/MessageEvaluation1' */
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
    sendAccCommand(STOP_COM);
    sendAutoXCommand((uint16_T)AUTOX_DEFAULT);
  }
}

/* Function for Chart: '<S4>/MessageEvaluation1' */
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

/* Function for Chart: '<S2>/EEPROM_Load_Buffer' */
static void updateBuffer(const eepromRequest *BusConversion_InsertedFor_EEPRO)
{
  int32_T i;
  if (rtDW.lastInsertedIndex >= 20.0) {
    rtDW.lastInsertedIndex = 1.0;
  } else {
    rtDW.lastInsertedIndex++;
  }

  i = (int32_T)rtDW.lastInsertedIndex - 1;
  rtDW.requestBuffer[i].operation = BusConversion_InsertedFor_EEPRO->operation;
  rtDW.requestBuffer[i].page = BusConversion_InsertedFor_EEPRO->page;
  rtDW.requestBuffer[i].cell = BusConversion_InsertedFor_EEPRO->cell;
  rtDW.requestBuffer[i].dataSize = BusConversion_InsertedFor_EEPRO->dataSize;
  for (i = 0; i < 16; i++) {
    rtDW.requestBuffer[(int32_T)rtDW.lastInsertedIndex - 1].data[i] =
      BusConversion_InsertedFor_EEPRO->data[i];
  }
}

/* Model step function for TID0 */
void GCU_Model_genCode_step0(void)     /* Sample time: [9.9999999999999991E-5s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void GCU_Model_genCode_step1(void)     /* Sample time: [0.001s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_CastToDouble;
  real_T rtb_Internal;
  uint8_T rtb_RateTransition5;
  uint8_T Merge_b;
  int32_T i;
  uint8_T tmp[16];
  int32_T i_0;

  /* RateTransition: '<Root>/Rate Transition' */
  rtDW.RateTransition_d = rtDW.RateTransition_Buffer0;

  /* RateTransition: '<Root>/Rate Transition1' */
  i = rtDW.RateTransition1_ActiveBufIdx * 3;
  rtDW.RateTransition1_c[0] = rtDW.RateTransition1_Buffer[i];
  rtDW.RateTransition1_c[1] = rtDW.RateTransition1_Buffer[1 + i];
  rtDW.RateTransition1_c[2] = rtDW.RateTransition1_Buffer[2 + i];

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
  rtb_RateTransition5 = rtDW.RateTransition5_Buffer0;

  /* RateTransition: '<Root>/Rate Transition8' */
  i = rtDW.RateTransition8_ActiveBufIdx << 1;
  rtDW.RateTransition8[0] = rtDW.RateTransition8_Buffer[i];
  rtDW.RateTransition8[1] = rtDW.RateTransition8_Buffer[1 + i];

  /* RateTransition: '<Root>/Rate Transition29' */
  i = rtDW.RateTransition29_ActiveBufIdx << 1;
  rtDW.RateTransition29[0] = rtDW.RateTransition29_Buffer[i];
  rtDW.RateTransition29[1] = rtDW.RateTransition29_Buffer[1 + i];

  /* RateTransition: '<S2>/Rate Transition' */
  i = rtDW.RateTransition_ActiveBufIdx * 20;
  for (i_0 = 0; i_0 < 20; i_0++) {
    rtDW.RateTransition[i_0] = rtDW.RateTransition_Buffer[i_0 + i];
  }

  /* End of RateTransition: '<S2>/Rate Transition' */

  /* RateTransition: '<S2>/Rate Transition1' */
  rtDW.RateTransition1 = rtDW.RateTransition1_Buffer0;

  /* Outputs for Atomic SubSystem: '<Root>/GCU_timer' */
  /* DiscreteStateSpace: '<S43>/Internal' */
  {
    rtb_Internal = 0.24359453030282938*rtDW.Internal_DSTATE;
  }

  /* DataTypeConversion: '<S5>/Cast1' incorporates:
   *  Constant: '<S5>/Constant'
   *  Sum: '<S5>/Sum'
   */
  rtDW.Cast1_k = (uint8_T)(rtb_Internal + 1.0);

  /* Chart: '<S5>/GCULogic' */
  rtDW.sfEvent = -1;
  if (rtDW.is_active_c1_GCU_Model_genCode == 0U) {
    rtDW.is_active_c1_GCU_Model_genCode = 1U;
    rtDW.is_active_MODES = 1U;
    rtDW.lastAacCom = 0U;
    rtDW.lastShiftCom = 0U;
    rtDW.lastAutoXCom = 0U;
    rtDW.buzzerCounter = 0U;
    if (rtDW.is_MODES != IN_INIT_j) {
      rtDW.is_MODES = IN_INIT_j;

      /* Outputs for Function Call SubSystem: '<S39>/BuzzerOn' */

      /* S-Function (activateBuzzer): '<S47>/BuzzerOn' */
      activateBuzzer_Outputs_wrapper();

      /* End of Outputs for SubSystem: '<S39>/BuzzerOn' */
    }

    rtDW.is_active_NEUTRAL_STATE = 1U;
    rtDW.is_NEUTRAL_STATE = IN_NEUTRAL;
    rtDW.is_active_GEARSHIFT = 1U;
    rtDW.ticksCounter = 0;
    if (rtDW.is_GEARSHIFT != IN_INIT_jf) {
      rtDW.is_GEARSHIFT = IN_INIT_jf;
      rtDW.ticksCounter = 0;
    }

    rtDW.is_active_START_ENGINE = 1U;
    rtDW.lastCom = 0U;
    rtDW.startCounter = 0U;
    rtDW.is_START_ENGINE = IN_WAIT_e;
    if (rtDW.is_active_SCAN_ADC != 1U) {
      rtDW.is_active_SCAN_ADC = 1U;
      rtDW.timerCounter = 0U;
    }

    if (rtDW.is_SCAN_ADC != IN_SCAN) {
      rtDW.is_SCAN_ADC = IN_SCAN;

      /* Outputs for Function Call SubSystem: '<S44>/SCAN_ADC.ScanADC' */
      SCAN_ADCScanADC();

      /* End of Outputs for SubSystem: '<S44>/SCAN_ADC.ScanADC' */
    }

    rtDW.is_active_EEPROM_TRIGGER = 1U;
    rtDW.counterWait = 0.0;
    if (rtDW.is_EEPROM_TRIGGER != IN_WAIT) {
      rtDW.is_EEPROM_TRIGGER = IN_WAIT;
      rtDW.counterWait = 1.0;
    }
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
       case IN_START_e:
        if (rtDW.startCounter <= 0) {
          rtDW.is_START_ENGINE = 0;
          if (rtDW.is_START_ENGINE != IN_STOP) {
            rtDW.is_START_ENGINE = IN_STOP;

            /* Outputs for Function Call SubSystem: '<S42>/EngineControl_Stop' */

            /* S-Function (EngineControl_stop): '<S55>/EngineControl Stop' */
            EngineControl_stop_Outputs_wrapper(&rtDW.EngineControlStop);

            /* End of Outputs for SubSystem: '<S42>/EngineControl_Stop' */
          }
        } else if (rtDW.RateTransition3 != rtDW.lastCom) {
          rtDW.is_START_ENGINE = 0;
          if (rtDW.is_START_ENGINE != IN_START_e) {
            rtDW.is_START_ENGINE = IN_START_e;

            /* Outputs for Function Call SubSystem: '<S42>/EngineControl_Start' */
            EngineControl_Start(&Merge_b, &rtDW.EngineControl_Start_h);

            /* End of Outputs for SubSystem: '<S42>/EngineControl_Start' */
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
          if (rtDW.is_START_ENGINE != IN_START_e) {
            rtDW.is_START_ENGINE = IN_START_e;

            /* Outputs for Function Call SubSystem: '<S42>/EngineControl_Start' */
            EngineControl_Start(&Merge_b, &rtDW.EngineControl_Start_h);

            /* End of Outputs for SubSystem: '<S42>/EngineControl_Start' */
            rtDW.lastCom = rtDW.RateTransition3;
            rtDW.startCounter = 100U;
          }
        }
        break;

       case IN_WAIT_e:
        if (rtDW.RateTransition3 != rtDW.lastCom) {
          rtDW.is_START_ENGINE = 0;
          if (rtDW.is_START_ENGINE != IN_START_e) {
            rtDW.is_START_ENGINE = IN_START_e;

            /* Outputs for Function Call SubSystem: '<S42>/EngineControl_Start' */
            EngineControl_Start(&Merge_b, &rtDW.EngineControl_Start_h);

            /* End of Outputs for SubSystem: '<S42>/EngineControl_Start' */
            rtDW.lastCom = rtDW.RateTransition3;
            rtDW.startCounter = 100U;
          }
        }
        break;
      }
    }

    if (rtDW.is_active_SCAN_ADC != 0U) {
      switch (rtDW.is_SCAN_ADC) {
       case IN_SCAN:
        rtDW.is_SCAN_ADC = 0;
        if (rtDW.is_SCAN_ADC != IN_WAIT) {
          rtDW.is_SCAN_ADC = IN_WAIT;
          rtDW.timerCounter = 0U;
        }
        break;

       case IN_WAIT:
        if (rtDW.timerCounter >= ADC_PERIOD) {
          rtDW.is_SCAN_ADC = 0;
          if (rtDW.is_SCAN_ADC != IN_SCAN) {
            rtDW.is_SCAN_ADC = IN_SCAN;

            /* Outputs for Function Call SubSystem: '<S44>/SCAN_ADC.ScanADC' */
            SCAN_ADCScanADC();

            /* End of Outputs for SubSystem: '<S44>/SCAN_ADC.ScanADC' */
          }
        } else {
          i = rtDW.timerCounter + 1;
          if (i > 65535) {
            i = 65535;
          }

          rtDW.timerCounter = (uint16_T)i;
        }
        break;
      }
    }

    if (rtDW.is_active_EEPROM_TRIGGER != 0U) {
      switch (rtDW.is_EEPROM_TRIGGER) {
       case IN_SEND:
        rtDW.is_EEPROM_TRIGGER = 0;
        if (rtDW.is_EEPROM_TRIGGER != IN_WAIT) {
          rtDW.is_EEPROM_TRIGGER = IN_WAIT;
          rtDW.counterWait = 1.0;
        }
        break;

       case IN_WAIT:
        if (rtDW.counterWait >= 10.0) {
          rtDW.is_EEPROM_TRIGGER = 0;
          if (rtDW.is_EEPROM_TRIGGER != IN_SEND) {
            rtDW.is_EEPROM_TRIGGER = IN_SEND;

            /* Chart: '<S2>/EEPROM_OutputRequest' */
            /* Chart: '<S2>/EEPROM_OutputRequest' */
            switch (rtDW.is_c6_GCU_Model_genCode) {
             case IN_ERROR:
              rtDW.is_c6_GCU_Model_genCode = IN_EVALUATE_SERIAL;
              break;

             case IN_INIT:
              if (rtDW.Eeprom_init_o2 == (int32_T)NEW_EEPROM) {
                rtDW.is_c6_GCU_Model_genCode = IN_LOAD_TO_EEPROM;
                rtDW.newData[0] = 0U;
                rtDW.newData[1] = 0U;
                rtDW.newData[2] = 0U;
                rtDW.newData[3] = 0U;
                rtDW.newData[4] = 0U;
                rtDW.newData[5] = 0U;
                rtDW.newData[6] = 0U;
                rtDW.newData[7] = 0U;
                rtDW.newData[8] = 0U;
                rtDW.newData[9] = 0U;
                rtDW.newData[10] = 0U;
                rtDW.newData[11] = 0U;
                rtDW.newData[12] = 0U;
                rtDW.newData[13] = 0U;
                rtDW.newData[14] = 0U;
                rtDW.newData[15] = 0U;
                rtDW.counter = 0U;
                rtDW.is_LOAD_TO_EEPROM = IN_FIRST_BYTE;
                rtDW.newData[0] = (uint8_T)USED_EEPROM;
                createRequest(87, 0, 0, 1, rtDW.newData);

                /* Outputs for Function Call SubSystem: '<S2>/Evaluate_Request' */
                Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                                 rtDW.load_default_timings,
                                 rtDW.load_accParameters1, &rtDW.Eeprom_write_o1,
                                 &rtDW.Eeprom_read_o1, &rtDW.Eeprom_write_o2,
                                 rtDW.OutportBufferFordataRead, rtDW.Merge,
                                 rtDW.Merge1, rtDW.Merge2,
                                 &rtDW.Evaluate_Request_l);

                /* End of Outputs for SubSystem: '<S2>/Evaluate_Request' */
              } else if (rtDW.Eeprom_init_o2 == (int32_T)USED_EEPROM) {
                rtDW.is_c6_GCU_Model_genCode = IN_LOAD_FROM_EEPROM;
                rtDW.counter = 0U;
                rtDW.is_LOAD_FROM_EEPROM = IN_GEARSHIFT_TIMINGS_j;
                for (i = 0; i < 16; i++) {
                  tmp[i] = 0U;
                }

                i = (int32_T)(rtDW.counter + 1U);
                i_0 = i;
                if ((uint32_T)i > 255U) {
                  i_0 = 255;
                }

                createRequest(76, (uint8_T)i_0, 0, 16, tmp);

                /* Outputs for Function Call SubSystem: '<S2>/Evaluate_Request' */
                Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                                 rtDW.load_default_timings,
                                 rtDW.load_accParameters1, &rtDW.Eeprom_write_o1,
                                 &rtDW.Eeprom_read_o1, &rtDW.Eeprom_write_o2,
                                 rtDW.OutportBufferFordataRead, rtDW.Merge,
                                 rtDW.Merge1, rtDW.Merge2,
                                 &rtDW.Evaluate_Request_l);

                /* End of Outputs for SubSystem: '<S2>/Evaluate_Request' */
                if ((uint32_T)i > 255U) {
                  i = 255;
                }

                rtDW.counter = (uint8_T)i;
              } else {
                rtDW.is_c6_GCU_Model_genCode = IN_ERROR;
                for (i = 0; i < 16; i++) {
                  tmp[i] = 0U;
                }

                createRequest(69, 0, 0, 0, tmp);

                /* Outputs for Function Call SubSystem: '<S2>/Evaluate_Request' */
                Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                                 rtDW.load_default_timings,
                                 rtDW.load_accParameters1, &rtDW.Eeprom_write_o1,
                                 &rtDW.Eeprom_read_o1, &rtDW.Eeprom_write_o2,
                                 rtDW.OutportBufferFordataRead, rtDW.Merge,
                                 rtDW.Merge1, rtDW.Merge2,
                                 &rtDW.Evaluate_Request_l);

                /* End of Outputs for SubSystem: '<S2>/Evaluate_Request' */
              }
              break;

             case IN_LOAD_FROM_EEPROM:
              switch (rtDW.is_LOAD_FROM_EEPROM) {
               case IN_ACC_PARAMETERS:
                if (rtDW.counter >= 6) {
                  rtDW.is_LOAD_FROM_EEPROM = IN_AUTOX_PARAMETERS;
                  rtDW.counter = 7U;
                } else {
                  for (i = 0; i < 16; i++) {
                    tmp[i] = 0U;
                  }

                  i = (int32_T)(rtDW.counter + 1U);
                  i_0 = i;
                  if ((uint32_T)i > 255U) {
                    i_0 = 255;
                  }

                  createRequest(76, (uint8_T)i_0, 0, 16, tmp);

                  /* Outputs for Function Call SubSystem: '<S2>/Evaluate_Request' */
                  Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                                   rtDW.load_default_timings,
                                   rtDW.load_accParameters1,
                                   &rtDW.Eeprom_write_o1, &rtDW.Eeprom_read_o1,
                                   &rtDW.Eeprom_write_o2,
                                   rtDW.OutportBufferFordataRead, rtDW.Merge,
                                   rtDW.Merge1, rtDW.Merge2,
                                   &rtDW.Evaluate_Request_l);

                  /* End of Outputs for SubSystem: '<S2>/Evaluate_Request' */
                  if ((uint32_T)i > 255U) {
                    i = 255;
                  }

                  rtDW.counter = (uint8_T)i;
                }
                break;

               case IN_AUTOX_PARAMETERS:
                if (rtDW.counter >= 9) {
                  rtDW.is_LOAD_FROM_EEPROM = 0;
                  rtDW.is_c6_GCU_Model_genCode = IN_EVALUATE_SERIAL;
                } else {
                  for (i = 0; i < 16; i++) {
                    tmp[i] = 0U;
                  }

                  i = (int32_T)(rtDW.counter + 1U);
                  i_0 = i;
                  if ((uint32_T)i > 255U) {
                    i_0 = 255;
                  }

                  createRequest(76, (uint8_T)i_0, 0, 16, tmp);

                  /* Outputs for Function Call SubSystem: '<S2>/Evaluate_Request' */
                  Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                                   rtDW.load_default_timings,
                                   rtDW.load_accParameters1,
                                   &rtDW.Eeprom_write_o1, &rtDW.Eeprom_read_o1,
                                   &rtDW.Eeprom_write_o2,
                                   rtDW.OutportBufferFordataRead, rtDW.Merge,
                                   rtDW.Merge1, rtDW.Merge2,
                                   &rtDW.Evaluate_Request_l);

                  /* End of Outputs for SubSystem: '<S2>/Evaluate_Request' */
                  if ((uint32_T)i > 255U) {
                    i = 255;
                  }

                  rtDW.counter = (uint8_T)i;
                }
                break;

               default:
                if (rtDW.counter >= 3) {
                  rtDW.is_LOAD_FROM_EEPROM = IN_ACC_PARAMETERS;
                  rtDW.counter = 4U;
                } else {
                  for (i = 0; i < 16; i++) {
                    tmp[i] = 0U;
                  }

                  i = (int32_T)(rtDW.counter + 1U);
                  if ((uint32_T)i > 255U) {
                    i = 255;
                  }

                  createRequest(76, (uint8_T)i, 0, 16, tmp);

                  /* Outputs for Function Call SubSystem: '<S2>/Evaluate_Request' */
                  Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                                   rtDW.load_default_timings,
                                   rtDW.load_accParameters1,
                                   &rtDW.Eeprom_write_o1, &rtDW.Eeprom_read_o1,
                                   &rtDW.Eeprom_write_o2,
                                   rtDW.OutportBufferFordataRead, rtDW.Merge,
                                   rtDW.Merge1, rtDW.Merge2,
                                   &rtDW.Evaluate_Request_l);

                  /* End of Outputs for SubSystem: '<S2>/Evaluate_Request' */
                  i = (int32_T)(rtDW.counter + 1U);
                  if ((uint32_T)i > 255U) {
                    i = 255;
                  }

                  rtDW.counter = (uint8_T)i;
                }
                break;
              }
              break;

             case IN_LOAD_TO_EEPROM:
              switch (rtDW.is_LOAD_TO_EEPROM) {
               case IN_ACC_PARAMETERS:
                if (rtDW.counter >= 2) {
                  rtDW.counter = 0U;
                  rtDW.is_LOAD_TO_EEPROM = IN_AUTOX_PARAMETERS;
                  shiftArray_h(rtDW.load_accParameters1, 12.0);
                } else {
                  extractValues(rtDW.counter);
                  i = (int32_T)(rtDW.counter + 5U);
                  if ((uint32_T)i > 255U) {
                    i = 255;
                  }

                  createRequest(87, (uint8_T)i, 0, 16, rtDW.newData);

                  /* Outputs for Function Call SubSystem: '<S2>/Evaluate_Request' */
                  Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                                   rtDW.load_default_timings,
                                   rtDW.load_accParameters1,
                                   &rtDW.Eeprom_write_o1, &rtDW.Eeprom_read_o1,
                                   &rtDW.Eeprom_write_o2,
                                   rtDW.OutportBufferFordataRead, rtDW.Merge,
                                   rtDW.Merge1, rtDW.Merge2,
                                   &rtDW.Evaluate_Request_l);

                  /* End of Outputs for SubSystem: '<S2>/Evaluate_Request' */
                  i = (int32_T)(rtDW.counter + 1U);
                  if ((uint32_T)i > 255U) {
                    i = 255;
                  }

                  rtDW.counter = (uint8_T)i;
                }
                break;

               case IN_AUTOX_PARAMETERS:
                if (rtDW.counter >= 2) {
                  rtDW.is_LOAD_TO_EEPROM = 0;
                  rtDW.is_c6_GCU_Model_genCode = IN_LOAD_FROM_EEPROM;
                  rtDW.counter = 0U;
                  rtDW.is_LOAD_FROM_EEPROM = IN_GEARSHIFT_TIMINGS_j;
                  for (i = 0; i < 16; i++) {
                    tmp[i] = 0U;
                  }

                  i = (int32_T)(rtDW.counter + 1U);
                  if ((uint32_T)i > 255U) {
                    i = 255;
                  }

                  createRequest(76, (uint8_T)i, 0, 16, tmp);

                  /* Outputs for Function Call SubSystem: '<S2>/Evaluate_Request' */
                  Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                                   rtDW.load_default_timings,
                                   rtDW.load_accParameters1,
                                   &rtDW.Eeprom_write_o1, &rtDW.Eeprom_read_o1,
                                   &rtDW.Eeprom_write_o2,
                                   rtDW.OutportBufferFordataRead, rtDW.Merge,
                                   rtDW.Merge1, rtDW.Merge2,
                                   &rtDW.Evaluate_Request_l);

                  /* End of Outputs for SubSystem: '<S2>/Evaluate_Request' */
                  i = (int32_T)(rtDW.counter + 1U);
                  if ((uint32_T)i > 255U) {
                    i = 255;
                  }

                  rtDW.counter = (uint8_T)i;
                } else {
                  extractValues(rtDW.counter);
                  i = (int32_T)(rtDW.counter + 8U);
                  if ((uint32_T)i > 255U) {
                    i = 255;
                  }

                  createRequest(87, (uint8_T)i, 0, 16, rtDW.newData);

                  /* Outputs for Function Call SubSystem: '<S2>/Evaluate_Request' */
                  Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                                   rtDW.load_default_timings,
                                   rtDW.load_accParameters1,
                                   &rtDW.Eeprom_write_o1, &rtDW.Eeprom_read_o1,
                                   &rtDW.Eeprom_write_o2,
                                   rtDW.OutportBufferFordataRead, rtDW.Merge,
                                   rtDW.Merge1, rtDW.Merge2,
                                   &rtDW.Evaluate_Request_l);

                  /* End of Outputs for SubSystem: '<S2>/Evaluate_Request' */
                  i = (int32_T)(rtDW.counter + 1U);
                  if ((uint32_T)i > 255U) {
                    i = 255;
                  }

                  rtDW.counter = (uint8_T)i;
                }
                break;

               case IN_FIRST_BYTE:
                rtDW.is_LOAD_TO_EEPROM = IN_GEARSHIFT_TIMINGS;
                shiftArray(rtDW.load_default_timings, 23.0);
                extractValues(rtDW.counter);
                i = (int32_T)(rtDW.counter + 1U);
                i_0 = i;
                if ((uint32_T)i > 255U) {
                  i_0 = 255;
                }

                createRequest(87, (uint8_T)i_0, 0, 16, rtDW.newData);

                /* Outputs for Function Call SubSystem: '<S2>/Evaluate_Request' */
                Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                                 rtDW.load_default_timings,
                                 rtDW.load_accParameters1, &rtDW.Eeprom_write_o1,
                                 &rtDW.Eeprom_read_o1, &rtDW.Eeprom_write_o2,
                                 rtDW.OutportBufferFordataRead, rtDW.Merge,
                                 rtDW.Merge1, rtDW.Merge2,
                                 &rtDW.Evaluate_Request_l);

                /* End of Outputs for SubSystem: '<S2>/Evaluate_Request' */
                if ((uint32_T)i > 255U) {
                  i = 255;
                }

                rtDW.counter = (uint8_T)i;
                break;

               default:
                if (rtDW.counter >= 3) {
                  rtDW.counter = 0U;
                  rtDW.is_LOAD_TO_EEPROM = IN_ACC_PARAMETERS;
                  shiftArray_h(rtDW.load_accParameters, 12.0);
                } else {
                  extractValues(rtDW.counter);
                  i = (int32_T)(rtDW.counter + 1U);
                  i_0 = i;
                  if ((uint32_T)i > 255U) {
                    i_0 = 255;
                  }

                  createRequest(87, (uint8_T)i_0, 0, 16, rtDW.newData);

                  /* Outputs for Function Call SubSystem: '<S2>/Evaluate_Request' */
                  Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                                   rtDW.load_default_timings,
                                   rtDW.load_accParameters1,
                                   &rtDW.Eeprom_write_o1, &rtDW.Eeprom_read_o1,
                                   &rtDW.Eeprom_write_o2,
                                   rtDW.OutportBufferFordataRead, rtDW.Merge,
                                   rtDW.Merge1, rtDW.Merge2,
                                   &rtDW.Evaluate_Request_l);

                  /* End of Outputs for SubSystem: '<S2>/Evaluate_Request' */
                  if ((uint32_T)i > 255U) {
                    i = 255;
                  }

                  rtDW.counter = (uint8_T)i;
                }
                break;
              }
              break;

             case IN_EVALUATE_SERIAL:
              if ((rtDW.reloadFlag == 1.0) && (rtDW.Eeprom_write_o1 !=
                   rtDW.HAL_ERROR)) {
                rtDW.is_c6_GCU_Model_genCode = IN_RELOAD;
              } else {
                testIndex();
              }
              break;

             default:
              if (rtDW.reloadFlag == 0.0) {
                rtDW.is_c6_GCU_Model_genCode = IN_EVALUATE_SERIAL;
              } else {
                rtDW.reloadFlag = 0.0;
                rtDW.outputRequest.operation = 76U;
                rtDW.outputRequest.cell = 0U;
                rtDW.outputRequest.dataSize = 16U;

                /* Outputs for Function Call SubSystem: '<S2>/Evaluate_Request' */
                Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                                 rtDW.load_default_timings,
                                 rtDW.load_accParameters1, &rtDW.Eeprom_write_o1,
                                 &rtDW.Eeprom_read_o1, &rtDW.Eeprom_write_o2,
                                 rtDW.OutportBufferFordataRead, rtDW.Merge,
                                 rtDW.Merge1, rtDW.Merge2,
                                 &rtDW.Evaluate_Request_l);

                /* End of Outputs for SubSystem: '<S2>/Evaluate_Request' */
              }
              break;
            }

            /* End of Chart: '<S2>/EEPROM_OutputRequest' */
          }
        } else {
          rtDW.counterWait++;
        }
        break;
      }
    }
  }

  /* End of Chart: '<S5>/GCULogic' */

  /* DataTypeConversion: '<S5>/Cast To Double' */
  rtb_CastToDouble = rtb_RateTransition5;

  /* Update for DiscreteStateSpace: '<S43>/Internal' */
  {
    real_T xnew[1];
    xnew[0] = 0.93910136742429262*rtDW.Internal_DSTATE;
    xnew[0] += 0.25*rtb_CastToDouble;
    (void) memcpy(&rtDW.Internal_DSTATE, xnew,
                  sizeof(real_T)*1);
  }

  /* End of Outputs for SubSystem: '<Root>/GCU_timer' */

  /* Outport: '<Root>/outputRequest' */
  rtY.outputRequest = rtDW.outputRequest;

  /* Outport: '<Root>/readResult' */
  rtY.readResult = rtDW.Eeprom_read_o1;

  /* Outport: '<Root>/writeResult' */
  rtY.writeResult = rtDW.Eeprom_write_o1;

  /* Outport: '<Root>/wpState' */
  rtY.wpState = rtDW.Eeprom_write_o2;

  /* Outport: '<Root>/dataRead' */
  for (i = 0; i < 19; i++) {
    rtY.dataRead[i] = rtDW.OutportBufferFordataRead[i];
  }

  /* End of Outport: '<Root>/dataRead' */

  /* Outport: '<Root>/gearshiftTimings' */
  memcpy(&rtY.gearshiftTimings[0], &rtDW.Merge[0], 24U * sizeof(int32_T));

  /* Outport: '<Root>/accParameters' */
  memcpy(&rtY.accParameters[0], &rtDW.Merge1[0], sizeof(int32_T) << 4U);

  /* Outport: '<Root>/autoXParameters' */
  memcpy(&rtY.autoXParameters[0], &rtDW.Merge2[0], sizeof(int32_T) << 4U);
}

/* Model step function for TID2 */
void GCU_Model_genCode_step2(void)     /* Sample time: [0.001s, 0.0002s] */
{
  uint8_T rtb_Cast;
  int32_T i;
  uint16_T tmp;

  /* RateTransition: '<Root>/Rate Transition6' */
  rtDW.RateTransition6 = rtDW.clutchCurrVal;

  /* RateTransition: '<Root>/Rate Transition7' */
  rtDW.RateTransition7 = rtDW.Pin_In1;

  /* Outputs for Atomic SubSystem: '<Root>/Simulink_Debug' */
  /* Chart: '<S7>/AccelerationRoutine' */
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
    rtDW.firstInt = 5U;
    rtDW.secondInt = 1U;
    break;

   case IN_InsertGear:
    if (rtDW.currGear_m == 1) {
      rtDW.is_c3_GCU_Model_genCode = IN_TPS_On;
      rtDW.id = 773U;
      rtDW.thirdInt = 100U;
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

   case IN_TPS_On:
    rtDW.thirdInt = 100U;
    rtDW.is_c3_GCU_Model_genCode = IN_Ready;
    rtDW.id = 514U;
    rtDW.firstInt = 5U;
    rtDW.secondInt = 2U;
    break;

   case IN_Wait:
    rtDW.is_c3_GCU_Model_genCode = IN_delay;
    rtDW.count = 0.0;
    break;

   default:
    if (rtDW.count == 10.0) {
      rtDW.is_c3_GCU_Model_genCode = IN_EnterAcceleration;
      rtDW.id = 513U;
      rtDW.secondInt = 5U;
    } else {
      rtDW.count++;
    }
    break;
  }

  /* End of Chart: '<S7>/AccelerationRoutine' */

  /* S-Function (PackCanUART): '<S7>/PackCanUart' */
  PackCanUART_Outputs_wrapper(&rtDW.id, &rtDW.firstInt, &rtDW.secondInt,
    &rtDW.thirdInt, (uint16_T*)&GCU_Model_genCode_U16GND, &rtDW.PackCanUart[0]);

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

  /* Outputs for Atomic SubSystem: '<Root>/GCU_CAN_Read' */
  /* S-Function (UnpackCanUART): '<S4>/UnpackCanUart' */
  UnpackCanUART_Outputs_wrapper(&rtDW.MultiportSwitch[0], &rtDW.UnpackCanUart_o1,
    &rtDW.UnpackCanUart_o2, &rtDW.UnpackCanUart_o3, &rtDW.UnpackCanUart_o4,
    &rtDW.UnpackCanUart_o5);

  /* Chart: '<S4>/MessageEvaluation1' */
  if (rtDW.UnpackCanUart_o1 == EFI_GEAR_RPM_TPS_PH2O_ID) {
    rtDW.currGear = rtDW.UnpackCanUart_o2;

    /* Outputs for Function Call SubSystem: '<S4>/AAC_ExternalValues' */
    AAC_ExternalValues(rtDW.UnpackCanUart_o3, (uint16_T)RPM, rtDW.Assignment,
                       &rtDW.AAC_ExternalValues_f);
    AAC_ExternalValues(rtDW.UnpackCanUart_o4, (uint16_T)TPS, rtDW.Assignment,
                       &rtDW.AAC_ExternalValues_f);

    /* End of Outputs for SubSystem: '<S4>/AAC_ExternalValues' */
  } else if (rtDW.UnpackCanUart_o1 == SW_FIRE_GCU_ID) {
    sendStartEngCommand();
  } else if (rtDW.UnpackCanUart_o1 == SW_GEARSHIFT_ID) {
    sendShiftCommand(rtDW.UnpackCanUart_o2);
  } else if (rtDW.UnpackCanUart_o1 == EFI_TRACTION_CONTROL_ID) {
    /* Outputs for Function Call SubSystem: '<S4>/AAC_ExternalValues' */
    AAC_ExternalValues((uint16_T)(rtDW.UnpackCanUart_o2 / 10U), (uint16_T)
                       WHEEL_SPEED, rtDW.Assignment, &rtDW.AAC_ExternalValues_f);

    /* End of Outputs for SubSystem: '<S4>/AAC_ExternalValues' */
  } else if (rtDW.UnpackCanUart_o1 == SW_CLUTCH_MODE_MAP_GCU_ID) {
    tmp = rtDW.UnpackCanUart_o2;
    if (rtDW.UnpackCanUart_o2 > 255) {
      tmp = 255U;
    }

    rtDW.clutchTarget = (uint8_T)tmp;
    sendModeCommand(rtDW.UnpackCanUart_o3);
    if (rtDW.clutchTarget > ACC_CLUTCH_NOISE_LEVEL) {
      sendAccCommand((uint16_T)ACC_OFF);
      sendAutoXCommand((uint16_T)AUTOX_DEFAULT);
    }

    if (rtDW.UnpackCanUart_o4 != 0) {
      rtDW.mapTarget = rtDW.UnpackCanUart_o4;
    }
  } else if (rtDW.UnpackCanUart_o1 == SW_OK_BUTTON_GCU_ID) {
    if (rtDW.UnpackCanUart_o2 == ACCELERATION_MODE) {
      sendAccCommand(rtDW.UnpackCanUart_o3);
      if (rtDW.accCommand[1] == ACC_OFF) {
        rtDW.clutchTarget = 0U;
      }
    } else {
      if (rtDW.UnpackCanUart_o2 == AUTOX_MODE) {
        sendAutoXCommand(rtDW.UnpackCanUart_o3);
        if (rtDW.autoXCommand[1] == AUTOX_DEFAULT) {
          rtDW.clutchTarget = 0U;
        }
      }
    }
  } else {
    if (rtDW.UnpackCanUart_o1 == SW_TRACTION_LIMITER_GCU_ID) {
      rtDW.tractionTarget = rtDW.UnpackCanUart_o2;
      rtDW.rpmLimiterTarget = rtDW.UnpackCanUart_o3;
    }
  }

  /* End of Chart: '<S4>/MessageEvaluation1' */
  /* End of Outputs for SubSystem: '<Root>/GCU_CAN_Read' */

  /* RateTransition: '<Root>/Rate Transition14' */
  if (!(rtDW.RateTransition14_semaphoreTaken != 0)) {
    rtDW.RateTransition14_Buffer0[0] = rtDW.Assignment[0];
    rtDW.RateTransition14_Buffer0[1] = rtDW.Assignment[1];
    rtDW.RateTransition14_Buffer0[2] = rtDW.Assignment[2];
  }

  /* End of RateTransition: '<Root>/Rate Transition14' */

  /* DataTypeConversion: '<Root>/Cast' */
  rtb_Cast = (uint8_T)rtDW.currGear;

  /* Update for RateTransition: '<Root>/Rate Transition' */
  rtDW.RateTransition_Buffer0 = rtb_Cast;

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
    rtDW.accCommand[0];
  rtDW.RateTransition4_Buffer[1 + ((rtDW.RateTransition4_ActiveBufIdx == 0) << 1)]
    = rtDW.accCommand[1];
  rtDW.RateTransition4_ActiveBufIdx = (int8_T)(rtDW.RateTransition4_ActiveBufIdx
    == 0);

  /* Update for RateTransition: '<Root>/Rate Transition5' */
  rtDW.RateTransition5_Buffer0 = rtDW.clutchTarget;

  /* Update for RateTransition: '<Root>/Rate Transition8' */
  rtDW.RateTransition8_Buffer[(rtDW.RateTransition8_ActiveBufIdx == 0) << 1] =
    rtDW.modeCommand[0];
  rtDW.RateTransition8_Buffer[1 + ((rtDW.RateTransition8_ActiveBufIdx == 0) << 1)]
    = rtDW.modeCommand[1];
  rtDW.RateTransition8_ActiveBufIdx = (int8_T)(rtDW.RateTransition8_ActiveBufIdx
    == 0);

  /* Update for RateTransition: '<Root>/Rate Transition29' */
  rtDW.RateTransition29_Buffer[(rtDW.RateTransition29_ActiveBufIdx == 0) << 1] =
    rtDW.autoXCommand[0];
  rtDW.RateTransition29_Buffer[1 + ((rtDW.RateTransition29_ActiveBufIdx == 0) <<
    1)] = rtDW.autoXCommand[1];
  rtDW.RateTransition29_ActiveBufIdx = (int8_T)
    (rtDW.RateTransition29_ActiveBufIdx == 0);
}

/* Model step function for TID3 */
void GCU_Model_genCode_step3(void)     /* Sample time: [0.001s, 0.0004s] */
{
  uint32_T rtb_RateTransition9[9];
  uint16_T rtb_RateTransition27;
  uint16_T rtb_RateTransition10;
  uint8_T rtb_RateTransition11;
  uint16_T rtb_RateTransition16;
  uint16_T rtb_RateTransition12;
  uint16_T rtb_RateTransition13;
  uint16_T rtb_RateTransition25;
  uint8_T rtb_RateTransition15;
  uint8_T rtb_RateTransition17;
  uint8_T rtb_RateTransition24;
  uint16_T rtb_RateTransition14[3];
  uint16_T Cast_n[9];
  int32_T i;
  int32_T i_0;
  uint16_T Cast_n_0;

  /* RateTransition: '<Root>/Rate Transition9' */
  i = rtDW.RateTransition9_ActiveBufIdx * 9;
  for (i_0 = 0; i_0 < 9; i_0++) {
    rtb_RateTransition9[i_0] = rtDW.RateTransition9_Buffer[i_0 + i];
  }

  /* End of RateTransition: '<Root>/Rate Transition9' */

  /* RateTransition: '<Root>/Rate Transition27' */
  rtb_RateTransition27 = rtDW.RateTransition27_Buffer0;

  /* RateTransition: '<Root>/Rate Transition10' */
  rtb_RateTransition10 = rtDW.rpmLimiterTarget;

  /* RateTransition: '<Root>/Rate Transition11' */
  rtb_RateTransition11 = rtDW.clutchCurrVal;

  /* RateTransition: '<Root>/Rate Transition16' */
  rtb_RateTransition16 = rtDW.stateFb;

  /* RateTransition: '<Root>/Rate Transition12' */
  rtb_RateTransition12 = rtDW.tractionTarget;

  /* RateTransition: '<Root>/Rate Transition13' */
  rtb_RateTransition13 = rtDW.lastModeCom[1];

  /* RateTransition: '<Root>/Rate Transition25' */
  rtb_RateTransition25 = rtDW.mapTarget;

  /* RateTransition: '<Root>/Rate Transition14' */
  rtDW.RateTransition14_semaphoreTaken = 1;
  rtb_RateTransition14[0] = rtDW.RateTransition14_Buffer0[0];
  rtb_RateTransition14[1] = rtDW.RateTransition14_Buffer0[1];
  rtb_RateTransition14[2] = rtDW.RateTransition14_Buffer0[2];
  rtDW.RateTransition14_semaphoreTaken = 0;

  /* RateTransition: '<Root>/Rate Transition15' */
  rtb_RateTransition15 = rtDW.Pin_In1;

  /* RateTransition: '<Root>/Rate Transition17' */
  rtb_RateTransition17 = rtDW.clutchTarget;

  /* RateTransition: '<Root>/Rate Transition24' */
  rtb_RateTransition24 = rtDW.Pin_H;

  /* S-Function (fcncallgen): '<Root>/Function_Call_Generator' incorporates:
   *  SubSystem: '<Root>/debugUART'
   */
  for (i = 0; i < 9; i++) {
    /* DataTypeConversion: '<S9>/Cast' */
    Cast_n_0 = (uint16_T)rtb_RateTransition9[i];

    /* SignalConversion: '<S9>/TmpSignal ConversionAtPack_Uart_MessageInport1' */
    rtDW.TmpSignalConversionAtPack_Uart_[i] = Cast_n_0;

    /* DataTypeConversion: '<S9>/Cast' */
    Cast_n[i] = Cast_n_0;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtPack_Uart_MessageInport1' incorporates:
   *  DataTypeConversion: '<S9>/Cast1'
   *  DataTypeConversion: '<S9>/Cast10'
   *  DataTypeConversion: '<S9>/Cast11'
   *  DataTypeConversion: '<S9>/Cast2'
   *  DataTypeConversion: '<S9>/Cast3'
   *  DataTypeConversion: '<S9>/Cast4'
   *  DataTypeConversion: '<S9>/Cast5'
   *  DataTypeConversion: '<S9>/Cast6'
   *  DataTypeConversion: '<S9>/Cast7'
   *  DataTypeConversion: '<S9>/Cast8'
   *  DataTypeConversion: '<S9>/Cast9'
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

  /* S-Function (PackUARTMsg): '<S9>/Pack_Uart_Message' */
  PackUARTMsg_Outputs_wrapper(&rtDW.TmpSignalConversionAtPack_Uart_[0],
    &rtDW.Pack_Uart_Message[0]);

  /* S-Function (sendUART): '<S9>/SendUART' */
  sendUART_Outputs_wrapper(&rtDW.Pack_Uart_Message[0]);

  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function_Call_Generator' */

  /* Outport: '<Root>/debugValues  ' incorporates:
   *  DataTypeConversion: '<S9>/Cast1'
   *  DataTypeConversion: '<S9>/Cast10'
   *  DataTypeConversion: '<S9>/Cast11'
   *  DataTypeConversion: '<S9>/Cast2'
   *  DataTypeConversion: '<S9>/Cast3'
   *  DataTypeConversion: '<S9>/Cast4'
   *  DataTypeConversion: '<S9>/Cast5'
   *  DataTypeConversion: '<S9>/Cast6'
   *  DataTypeConversion: '<S9>/Cast7'
   *  DataTypeConversion: '<S9>/Cast8'
   *  DataTypeConversion: '<S9>/Cast9'
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
  uint32_T CastToDouble[9];
  int32_T i;

  /* S-Function (fcncallgen): '<Root>/Function_Call_Generator1' incorporates:
   *  SubSystem: '<Root>/update_ADC_data'
   */
  /* S-Function (update_ADC_data): '<S11>/update_ADC_data' incorporates:
   *  Inport: '<Root>/adc_buffer'
   */
  update_ADC_data_Outputs_wrapper(&rtU.adc_buffer[0], &rtDW.update_ADC_data[0]);

  /* DataTypeConversion: '<S11>/Cast To Double' incorporates:
   *  Constant: '<S11>/OffSet'
   *  Constant: '<S11>/OffSet1'
   *  Constant: '<S11>/OffSet2'
   *  DataTypeConversion: '<S11>/Cast'
   *  Product: '<S11>/Multiply1'
   *  Product: '<S11>/Multiply2'
   *  Sum: '<S11>/Sum'
   *  Sum: '<S11>/Sum1'
   */
  for (i = 0; i < 9; i++) {
    CastToDouble[i] = (uint32_T)(((real_T)rtDW.update_ADC_data[i] *
      0.00080586080586080586 + rtConstP.OffSet_Value[i]) *
      rtConstP.OffSet1_Value[i] + rtConstP.OffSet2_Value[i]);
  }

  /* End of DataTypeConversion: '<S11>/Cast To Double' */

  /* S-Function (Read_oil_sensor): '<S11>/Read_oil_sensor' */
  Read_oil_sensor_Outputs_wrapper(&rtDW.Read_oil_sensor);

  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function_Call_Generator1' */

  /* Outport: '<Root>/adc_data_vector' */
  for (i = 0; i < 9; i++) {
    rtY.adc_data_vector[i] = CastToDouble[i];
  }

  /* End of Outport: '<Root>/adc_data_vector' */

  /* RateTransition: '<Root>/Rate Transition18' */
  if (!(rtDW.RateTransition18_semaphoreTaken != 0)) {
    for (i = 0; i < 9; i++) {
      rtDW.RateTransition18_Buffer0[i] = CastToDouble[i];
    }
  }

  /* End of RateTransition: '<Root>/Rate Transition18' */

  /* Update for RateTransition: '<Root>/Rate Transition9' */
  for (i = 0; i < 9; i++) {
    rtDW.RateTransition9_Buffer[i + (rtDW.RateTransition9_ActiveBufIdx == 0) * 9]
      = CastToDouble[i];
  }

  rtDW.RateTransition9_ActiveBufIdx = (int8_T)(rtDW.RateTransition9_ActiveBufIdx
    == 0);

  /* End of Update for RateTransition: '<Root>/Rate Transition9' */

  /* Update for RateTransition: '<Root>/Rate Transition27' */
  rtDW.RateTransition27_Buffer0 = rtDW.Read_oil_sensor;
}

/* Model step function for TID5 */
void GCU_Model_genCode_step5(void)     /* Sample time: [0.001s, 0.0008s] */
{
  int32_T i;
  uint16_T uDLookupTable2_tmp;
  boolean_T guard1 = false;

  /* RateTransition: '<Root>/Rate Transition18' */
  rtDW.RateTransition18_semaphoreTaken = 1;
  for (i = 0; i < 9; i++) {
    rtDW.RateTransition18[i] = rtDW.RateTransition18_Buffer0[i];
  }

  rtDW.RateTransition18_semaphoreTaken = 0;

  /* End of RateTransition: '<Root>/Rate Transition18' */

  /* RateTransition: '<Root>/Rate Transition19' */
  rtDW.RateTransition19 = rtDW.rpmLimiterTarget;

  /* RateTransition: '<Root>/Rate Transition20' */
  rtDW.RateTransition20 = rtDW.clutchCurrVal;

  /* RateTransition: '<Root>/Rate Transition21' */
  rtDW.RateTransition21 = rtDW.stateFb;

  /* RateTransition: '<Root>/Rate Transition22' */
  rtDW.RateTransition22 = rtDW.tractionTarget;

  /* RateTransition: '<Root>/Rate Transition23' */
  rtDW.RateTransition23 = rtDW.lastModeCom[1];

  /* RateTransition: '<Root>/Rate Transition26' */
  rtDW.RateTransition26 = rtDW.mapTarget;

  /* RateTransition: '<Root>/Rate Transition28' */
  rtDW.RateTransition28 = rtDW.Read_oil_sensor;

  /* S-Function (fcncallgen): '<Root>/Function_Call_Generator2' incorporates:
   *  SubSystem: '<Root>/CAN_Send'
   */
  /* Lookup_n-D: '<S1>/1-D Lookup Table2' incorporates:
   *  Lookup_n-D: '<S1>/1-D Lookup Table1'
   */
  uDLookupTable2_tmp = look1_iu16lu64n48_binlcse(rtDW.RateTransition22,
    rtConstP.pooled5, rtConstP.pooled4, 7U);
  rtDW.uDLookupTable2 = uDLookupTable2_tmp;

  /* Lookup_n-D: '<S1>/1-D Lookup Table1' */
  rtDW.uDLookupTable1 = uDLookupTable2_tmp;

  /* Lookup_n-D: '<S1>/1-D Lookup Table3' */
  rtDW.uDLookupTable3 = look1_iu16lu64n48_binlcse(rtDW.RateTransition19,
    rtConstP.pooled5, rtConstP.pooled4, 7U);
  rtDW.gcu_traction_limiter_loil_efi_i = (uint16_T)
    GCU_TRACTION_LIMITER_LOIL_EFI_ID;
  rtDW.gcu_clutch_mode_map_sw_id = (uint16_T)GCU_CLUTCH_MODE_MAP_SW_ID;
  rtDW.gcu_traction_limiter_autog_acc_ = (uint16_T)
    GCU_TRACTION_LIMITER_AUTOG_ACC_SW_ID;
  rtDW.gcu_debug_1_id = (uint16_T)GCU_DEBUG_1_ID;
  rtDW.gcu_debug_2_id = (uint16_T)GCU_DEBUG_2_ID;
  guard1 = false;
  if (rtDW.counter3 >= 100) {
    /* Outputs for Function Call SubSystem: '<S1>/Subsystem1' */
    /* DataTypeConversion: '<S19>/Cast' */
    rtDW.Cast_d = (uint16_T)rtDW.RateTransition18[4];

    /* DataTypeConversion: '<S19>/Cast1' */
    rtDW.Cast1_h = (uint16_T)rtDW.RateTransition18[5];

    /* DataTypeConversion: '<S19>/Cast2' */
    rtDW.Cast2_e = (uint16_T)rtDW.RateTransition18[3];

    /* DataTypeConversion: '<S19>/Cast3' */
    rtDW.Cast3_p = (uint16_T)rtDW.RateTransition18[8];

    /* S-Function (PackCANMsg): '<S19>/PackCANMsg' */
    PackCANMsg_Outputs_wrapper(&rtDW.Cast_d, &rtDW.Cast1_h, &rtDW.Cast2_e,
      &rtDW.Cast3_p, &rtDW.PackCANMsg_f[0]);

    /* S-Function (sendCAN): '<S19>/sendCAN' */
    sendCAN_Outputs_wrapper(&rtDW.gcu_debug_1_id, &rtDW.PackCANMsg_f[0]);

    /* End of Outputs for SubSystem: '<S1>/Subsystem1' */

    /* Outputs for Function Call SubSystem: '<S1>/Subsystem2' */
    /* DataTypeConversion: '<S20>/Cast' */
    rtDW.Cast = (uint16_T)rtDW.RateTransition18[6];

    /* DataTypeConversion: '<S20>/Cast1' */
    rtDW.Cast1 = (uint16_T)rtDW.RateTransition18[0];

    /* DataTypeConversion: '<S20>/Cast2' */
    rtDW.Cast2 = (uint16_T)rtDW.RateTransition18[1];

    /* DataTypeConversion: '<S20>/Cast3' */
    rtDW.Cast3 = (uint16_T)rtDW.RateTransition18[2];

    /* S-Function (PackCANMsg): '<S20>/PackCANMsg' */
    PackCANMsg_Outputs_wrapper(&rtDW.Cast, &rtDW.Cast1, &rtDW.Cast2, &rtDW.Cast3,
      &rtDW.PackCANMsg[0]);

    /* S-Function (sendCAN): '<S20>/sendCAN' */
    sendCAN_Outputs_wrapper(&rtDW.gcu_debug_2_id, &rtDW.PackCANMsg[0]);

    /* End of Outputs for SubSystem: '<S1>/Subsystem2' */
    rtDW.counter3 = 0U;
    guard1 = true;
  } else {
    if (rtDW.counter2 >= 10) {
      guard1 = true;
    }
  }

  if (guard1) {
    /* Outputs for Function Call SubSystem: '<S1>/Subsystem' */

    /* S-Function (PackCANMsg): '<S18>/PackCANMsg' */
    PackCANMsg_Outputs_wrapper(&rtDW.RateTransition22, &rtDW.RateTransition19,
      (uint16_T*)&GCU_Model_genCode_U16GND, &rtDW.RateTransition21,
      &rtDW.PackCANMsg_e[0]);

    /* S-Function (sendCAN): '<S18>/sendCAN' */
    sendCAN_Outputs_wrapper(&rtDW.gcu_traction_limiter_autog_acc_,
      &rtDW.PackCANMsg_e[0]);

    /* End of Outputs for SubSystem: '<S1>/Subsystem' */

    /* Outputs for Function Call SubSystem: '<S1>/sendMessage' */

    /* S-Function (PackCANMsg): '<S22>/PackCANMsg' */
    PackCANMsg_Outputs_wrapper(&rtDW.uDLookupTable2, &rtDW.uDLookupTable1,
      &rtDW.uDLookupTable3, &rtDW.RateTransition28, &rtDW.PackCANMsg_l[0]);

    /* S-Function (sendCAN): '<S22>/sendCAN' */
    sendCAN_Outputs_wrapper(&rtDW.gcu_traction_limiter_loil_efi_i,
      &rtDW.PackCANMsg_l[0]);

    /* End of Outputs for SubSystem: '<S1>/sendMessage' */
    rtDW.counter2 = 0U;
  }

  /* Chart: '<S1>/CAN_id' incorporates:
   *  SubSystem: '<S1>/Subsystem3'
   */
  /* DataTypeConversion: '<S21>/Cast' */
  rtDW.Cast_l = rtDW.RateTransition20;

  /* S-Function (PackCANMsg): '<S21>/PackCANMsg' incorporates:
   *  Constant: '<S1>/Constant'
   */
  PackCANMsg_Outputs_wrapper(&rtDW.Cast_l, &rtDW.RateTransition23,
    &rtDW.RateTransition26, &rtConstP.pooled6, &rtDW.PackCANMsg_ls[0]);

  /* S-Function (sendCAN): '<S21>/sendCAN' */
  sendCAN_Outputs_wrapper(&rtDW.gcu_clutch_mode_map_sw_id, &rtDW.PackCANMsg_ls[0]);
  i = rtDW.counter2 + 1;
  if (i > 255) {
    i = 255;
  }

  rtDW.counter2 = (uint8_T)i;
  i = rtDW.counter3 + 1;
  if (i > 255) {
    i = 255;
  }

  rtDW.counter3 = (uint8_T)i;

  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function_Call_Generator2' */
}

/* Model step function for TID6 */
void GCU_Model_genCode_step6(void)     /* Sample time: [0.001s, 0.0009s] */
{
  eepromRequest BusConversion_InsertedFor_EEPRO;
  int32_T i;

  /* BusCreator: '<S2>/BusConversion_InsertedFor_EEPROM_Load_Buffer_at_inport_0' incorporates:
   *  Inport: '<Root>/inputRequest'
   */
  BusConversion_InsertedFor_EEPRO.operation = rtU.inputRequest[0];
  BusConversion_InsertedFor_EEPRO.page = rtU.inputRequest[1];
  BusConversion_InsertedFor_EEPRO.cell = rtU.inputRequest[2];
  BusConversion_InsertedFor_EEPRO.dataSize = rtU.inputRequest[3];
  for (i = 0; i < 16; i++) {
    BusConversion_InsertedFor_EEPRO.data[i] = rtU.inputRequest[i + 4];
  }

  /* End of BusCreator: '<S2>/BusConversion_InsertedFor_EEPROM_Load_Buffer_at_inport_0' */

  /* S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  Chart: '<S2>/EEPROM_Load_Buffer'
   */
  /* Chart: '<S2>/EEPROM_Load_Buffer' */
  updateBuffer(&BusConversion_InsertedFor_EEPRO);

  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function-Call Generator' */

  /* Update for RateTransition: '<S2>/Rate Transition' */
  for (i = 0; i < 20; i++) {
    rtDW.RateTransition_Buffer[i + (rtDW.RateTransition_ActiveBufIdx == 0) * 20]
      = rtDW.requestBuffer[i];
  }

  rtDW.RateTransition_ActiveBufIdx = (int8_T)(rtDW.RateTransition_ActiveBufIdx ==
    0);

  /* End of Update for RateTransition: '<S2>/Rate Transition' */

  /* Update for RateTransition: '<S2>/Rate Transition1' */
  rtDW.RateTransition1_Buffer0 = rtDW.lastInsertedIndex;
}

/* Model initialize function */
void GCU_Model_genCode_initialize(void)
{
  /* Registration code */

  /* initialize sample time offsets */
  /* initialize sample time offsets */
  /* initialize sample time offsets */
  /* initialize sample time offsets */
  /* initialize sample time offsets */

  /* Start for RateTransition: '<S2>/Rate Transition1' */
  rtDW.RateTransition1 = 1.0;

  /* InitializeConditions for RateTransition: '<S2>/Rate Transition1' */
  rtDW.RateTransition1_Buffer0 = 1.0;
  rtDW.sfEvent = -1;

  /* SystemInitialize for Chart: '<S5>/GCULogic' incorporates:
   *  Chart: '<S2>/EEPROM_OutputRequest'
   */
  rtDW.lastEvaluatedIndex = 1.0;
  rtDW.HAL_ERROR = 1U;

  /* Chart: '<S2>/EEPROM_OutputRequest' */
  /* Chart: '<S2>/EEPROM_OutputRequest' */
  rtDW.is_c6_GCU_Model_genCode = IN_INIT;

  /* SystemInitialize for Chart: '<S2>/EEPROM_OutputRequest' incorporates:
   *  SubSystem: '<S2>/Evaluate_Request'
   */
  Evaluate_Request_Init(rtDW.Merge, rtDW.Merge1, rtDW.Merge2,
                        &rtDW.Evaluate_Request_l);

  /* End of SystemInitialize for SubSystem: '<Root>/GCU_timer' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Simulink_Debug' */
  /* Chart: '<S7>/AccelerationRoutine' */
  rtDW.is_c3_GCU_Model_genCode = IN_Wait;

  /* End of SystemInitialize for SubSystem: '<Root>/Simulink_Debug' */

  /* SystemInitialize for S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  Chart: '<S2>/EEPROM_Load_Buffer'
   */
  /* SystemInitialize for Chart: '<S2>/EEPROM_Load_Buffer' */
  rtDW.lastInsertedIndex = 1.0;

  /* End of SystemInitialize for S-Function (fcncallgen): '<Root>/Function-Call Generator' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/InitializeFunction' */

  /* S-Function (load_accParameters): '<S6>/load_accParameters' */
  load_accParameters_Outputs_wrapper(&rtDW.load_accParameters[0]);

  /* S-Function (load_default_timings): '<S6>/load_default_timings' */
  load_default_timings_Outputs_wrapper(&rtDW.load_default_timings[0]);

  /* S-Function (load_autoXParameters): '<S6>/load_accParameters1' */
  load_autoXParameters_Outputs_wrapper(&rtDW.load_accParameters1[0]);

  /* S-Function (Eeprom_init): '<S6>/Eeprom_init' */
  Eeprom_init_Outputs_wrapper(&rtDW.Eeprom_init_o1, &rtDW.Eeprom_init_o2,
    &rtDW.Eeprom_init_o3);

  /* S-Function (setKeyOn): '<S6>/setKeyOn' */
  setKeyOn_Outputs_wrapper(&rtDW.setKeyOn);

  /* S-Function (Buzzer_init): '<S6>/BuzzerInit' */
  Buzzer_init_Outputs_wrapper();

  /* S-Function (CAN_Start): '<S6>/CAN_Start' */
  CAN_Start_Outputs_wrapper();

  /* S-Function (ClutchMotor_init): '<S6>/ClutchMotor Init' */
  ClutchMotor_init_Outputs_wrapper();

  /* S-Function (Efi_init): '<S6>/Efi Init' */
  Efi_init_Outputs_wrapper();

  /* S-Function (FuelPump_init): '<S6>/FuelPump' */
  FuelPump_init_Outputs_wrapper();

  /* S-Function (GearMotor_init): '<S6>/GearMotor Init' */
  GearMotor_init_Outputs_wrapper();

  /* S-Function (InitTimer): '<S6>/InitTimer' */
  InitTimer_Outputs_wrapper();

  /* S-Function (InitUART): '<S6>/InitUART' */
  InitUART_Outputs_wrapper();

  /* S-Function (ScanADC): '<S6>/ScanADC' */
  ScanADC_Outputs_wrapper();

  /* S-Function (StopLight_init): '<S6>/StopLight' */
  StopLight_init_Outputs_wrapper();

  /* End of SystemInitialize for SubSystem: '<Root>/InitializeFunction' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
