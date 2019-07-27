/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GCU_Model_genCode.c
 *
 * Code generated for Simulink model 'GCU_Model_genCode'.
 *
 * Model version                  : 1.398
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Sat Jul 27 14:17:34 2019
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
#define CLUTCH_NOISE_LEVEL             ((uint8_T)30U)
#define GEAR_COMMAND_DOWN              ((uint16_T)200U)
#define GEAR_COMMAND_NEUTRAL_DOWN      ((uint16_T)100U)
#define GEAR_COMMAND_NEUTRAL_UP        ((uint16_T)50U)
#define STOP_COM                       ((uint16_T)0U)

/* Named constants for Chart: '<S3>/EEPROM_OutputRequest' */
#define IN_ACC_PARAMETERS              ((uint8_T)1U)
#define IN_ANTI_STALL_PARAMETERS       ((uint8_T)2U)
#define IN_AUTOX_PARAMETERS            ((uint8_T)3U)
#define IN_ERROR                       ((uint8_T)1U)
#define IN_EVALUATE_SERIAL             ((uint8_T)5U)
#define IN_FIRST_BYTE                  ((uint8_T)4U)
#define IN_GEARSHIFT_TIMINGS           ((uint8_T)5U)
#define IN_GEARSHIFT_TIMINGS_j         ((uint8_T)4U)
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
#define IN_ACCELERATION_PID            ((uint8_T)2U)
#define IN_ACTIVE                      ((uint8_T)1U)
#define IN_AUTOCROSS                   ((uint8_T)3U)
#define IN_ChangeClutch                ((uint8_T)1U)
#define IN_Control                     ((uint8_T)1U)
#define IN_CutOff                      ((uint8_T)1U)
#define IN_DEFAULT                     ((uint8_T)2U)
#define IN_DEFAULT_j                   ((uint8_T)1U)
#define IN_DISABLE                     ((uint8_T)1U)
#define IN_DOWNSHIFTING                ((uint8_T)1U)
#define IN_DOWN_BRAKE                  ((uint8_T)1U)
#define IN_DOWN_END                    ((uint8_T)2U)
#define IN_DOWN_PUSH                   ((uint8_T)2U)
#define IN_DOWN_REBOUND                ((uint8_T)3U)
#define IN_DOWN_START                  ((uint8_T)4U)
#define IN_Default                     ((uint8_T)1U)
#define IN_Default_b                   ((uint8_T)2U)
#define IN_ENABLE                      ((uint8_T)2U)
#define IN_ENDURANCE                   ((uint8_T)1U)
#define IN_IDLE                        ((uint8_T)3U)
#define IN_INIT_k                      ((uint8_T)4U)
#define IN_LAUNCH                      ((uint8_T)2U)
#define IN_LAUNCH0                     ((uint8_T)2U)
#define IN_LAUNCH1                     ((uint8_T)3U)
#define IN_LAUNCH2                     ((uint8_T)4U)
#define IN_LAUNCH3                     ((uint8_T)5U)
#define IN_LAUNCH4                     ((uint8_T)6U)
#define IN_LAUNCH5                     ((uint8_T)7U)
#define IN_LAUNCH6                     ((uint8_T)8U)
#define IN_LAUNCH7                     ((uint8_T)9U)
#define IN_LAUNCH8                     ((uint8_T)10U)
#define IN_LAUNCH9                     ((uint8_T)11U)
#define IN_MANUAL_MODES                ((uint8_T)5U)
#define IN_NEUTRAL                     ((uint8_T)1U)
#define IN_NO_NEUTRAL                  ((uint8_T)2U)
#define IN_READY                       ((uint8_T)1U)
#define IN_RELEASE                     ((uint8_T)2U)
#define IN_RELEASING                   ((uint8_T)2U)
#define IN_RUNNING                     ((uint8_T)3U)
#define IN_SCAN                        ((uint8_T)1U)
#define IN_SEND                        ((uint8_T)1U)
#define IN_SET_NEUTRAL                 ((uint8_T)3U)
#define IN_SKIDPAD                     ((uint8_T)2U)
#define IN_START                       ((uint8_T)4U)
#define IN_START_RELEASE               ((uint8_T)5U)
#define IN_START_j                     ((uint8_T)1U)
#define IN_STOP                        ((uint8_T)2U)
#define IN_STOPPING                    ((uint8_T)2U)
#define IN_SettingNeutral              ((uint8_T)2U)
#define IN_SettingNeutral_e            ((uint8_T)3U)
#define IN_UNSET_NEUTRAL               ((uint8_T)4U)
#define IN_UPSHIFTING                  ((uint8_T)5U)
#define IN_UP_BRAKE                    ((uint8_T)1U)
#define IN_UP_END                      ((uint8_T)6U)
#define IN_UP_PUSH                     ((uint8_T)2U)
#define IN_UP_REBOUND                  ((uint8_T)3U)
#define IN_UP_START                    ((uint8_T)4U)
#define IN_WAIT                        ((uint8_T)2U)
#define IN_WAIT_c                      ((uint8_T)3U)
#define event_GearshiftDown            (0)
#define event_GearshiftSetNeutral      (1)
#define event_GearshiftUp              (2)
#define NumBitsPerChar                 8U
#include "solver_zc.h"
#include "zero_crossing_types.h"
#ifndef slZcHadEvent
#define slZcHadEvent(ev, zcsDir)       (((ev) & (zcsDir)) != 0x00 )
#endif

#ifndef slZcUnAliasEvents
#define slZcUnAliasEvents(evL, evR)    ((((slZcHadEvent((evL), (SL_ZCS_EVENT_N2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2P))) || (slZcHadEvent((evL), (SL_ZCS_EVENT_P2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2N)))) ? (SL_ZCS_EVENT_NUL) : (evR)))
#endif

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

  extern void Efi_setMap_Start_wrapper(void);
  extern void Efi_setMap_Outputs_wrapper(const uint8_T *map);
  extern void Efi_setMap_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void CAN_Restart_Start_wrapper(void);
  extern void CAN_Restart_Outputs_wrapper(void);
  extern void CAN_Restart_Terminate_wrapper(void);

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
  extern void Efi_setCut_Outputs_wrapper(void);
  extern void Efi_setCut_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Efi_unsetCut_Start_wrapper(void);
  extern void Efi_unsetCut_Outputs_wrapper(void);
  extern void Efi_unsetCut_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Efi_setRPMLimiter_Start_wrapper(void);
  extern void Efi_setRPMLimiter_Outputs_wrapper(void);
  extern void Efi_setRPMLimiter_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Efi_unsetRPMLimiter_Start_wrapper(void);
  extern void Efi_unsetRPMLimiter_Outputs_wrapper(void);
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

  extern void ClutchMotor_setPWMRegister_Start_wrapper(void);
  extern void ClutchMotor_setPWMRegister_Outputs_wrapper(const real_T
    *percentage);
  extern void ClutchMotor_setPWMRegister_Terminate_wrapper(void);

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

  extern void load_antiStallParameters_Start_wrapper(void);
  extern void load_antiStallParameters_Outputs_wrapper(int32_T
    *antiStallParameters);
  extern void load_antiStallParameters_Terminate_wrapper(void);

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

static uint16_T look1_iu16lu64n48_binlcse(uint16_T u0, const uint16_T bp0[],
  const uint16_T table[], uint32_T maxIndex);
static void SetCut(void);
static void UnsetCut(void);
static void SetRPMLimiter(void);
static void UnsetRPMLimiter(void);
static void Gearmotor_turnRight(uint8_T *rty_Pin_In1, uint8_T *rty_Pin_In2,
  uint8_T *rty_Pin_H, DW_Gearmotor_turnRight *localDW);
static void Gearmotor_brake(uint8_T *rty_Pin_In1, uint8_T *rty_Pin_In2, uint8_T *
  rty_Pin_H, DW_Gearmotor_brake *localDW);
static void EngineControl_Start(uint8_T *rty_engine_starter,
  DW_EngineControl_Start *localDW);
static void Evaluate_Request_Init(int32_T rty_gearshiftTimings[24], int32_T
  rty_accParameters[16], int32_T rty_autoXParameters[16], int32_T
  rty_antiStallParameters[8], DW_Evaluate_Request *localDW);
static void Evaluate_Request(const eepromRequest *rtu_outputRequest, const
  int32_T rtu_accInitialParameters[13], const int32_T
  rtu_gearshiftInitialTimings[23], const int32_T rtu_autoXInitialParameters[13],
  const int32_T rtu_antiStallInitialParameters[3], uint8_T *rty_writeResult,
  uint8_T *rty_readResult, uint8_T *rty_wpState, int32_T rty_gearshiftTimings[24],
  int32_T rty_accParameters[16], int32_T rty_autoXParameters[16], int32_T
  rty_antiStallParameters[8], uint8_T *rty_dataRead, uint8_T *rty_dataRead_i,
  uint8_T *rty_dataRead_d, uint8_T rty_dataRead_l[16], DW_Evaluate_Request
  *localDW);
static void MODESACCELERATION_PIDL_Init(DW_MODESACCELERATION_PIDLAUNCH0 *localDW);
static void MODESACCELERATION_PI_Enable(DW_MODESACCELERATION_PIDLAUNCH0 *localDW);
static void MODESACCELERATION_PIDLAUNCH(RT_MODEL * const rtM, real_T
  *rty_clutchCurrVal, DW_MODESACCELERATION_PIDLAUNCH0 *localDW);
static void MODESACCELERATION_PI_j_Init(DW_MODESACCELERATION_PIDLAUNCH1 *localDW);
static void MODESACCELERATION__c_Enable(DW_MODESACCELERATION_PIDLAUNCH1 *localDW);
static void MODESACCELERATION_PIDLAUN_o(RT_MODEL * const rtM, real_T
  *rty_clutchCurrVal, DW_MODESACCELERATION_PIDLAUNCH1 *localDW);
static void MODESACCELERATION_PI_p_Init(DW_MODESACCELERATION_PIDLAUNCH2 *localDW);
static void MODESACCELERATION__k_Enable(DW_MODESACCELERATION_PIDLAUNCH2 *localDW);
static void MODESACCELERATION_PIDLAUN_g(RT_MODEL * const rtM, real_T
  rtu_currentSlip, real_T rtu_slipTarget, real_T *rty_clutchVal,
  DW_MODESACCELERATION_PIDLAUNCH2 *localDW);
static void MODESACCELERATION_PI_f_Init(DW_MODESACCELERATION_PIDLAUNCH4 *localDW);
static void MODESACCELERATION__i_Enable(DW_MODESACCELERATION_PIDLAUNCH4 *localDW);
static void MODESACCELERATION_PIDLAUN_n(RT_MODEL * const rtM, real_T
  rtu_currentSlip, real_T rtu_slipTarget, real_T *rty_clutchVal,
  DW_MODESACCELERATION_PIDLAUNCH4 *localDW);
static void MODESACCELERATION_PI_l_Init(DW_MODESACCELERATION_PIDLAUNCH6 *localDW);
static void MODESACCELERATION__j_Enable(DW_MODESACCELERATION_PIDLAUNCH6 *localDW);
static void MODESACCELERATION_PIDLAUN_l(RT_MODEL * const rtM, real_T
  rtu_slipTarget, real_T rtu_currentSlip, real_T rtu_reset, real_T
  *rty_clutchVal, DW_MODESACCELERATION_PIDLAUNCH6 *localDW,
  ZCE_MODESACCELERATION_PIDLAUN_j *localZCE);
static void MODESACCELERATION_PI_b_Init(DW_MODESACCELERATION_PIDLAUNCH8 *localDW);
static void MODESACCELERATION__e_Enable(DW_MODESACCELERATION_PIDLAUNCH8 *localDW);
static void MODESACCELERATION_PIDLAUN_e(RT_MODEL * const rtM, real_T
  rtu_slipTarget, real_T rtu_currentSlip, real_T rtu_reset, real_T
  *rty_clutchVal, DW_MODESACCELERATION_PIDLAUNCH8 *localDW,
  ZCE_MODESACCELERATION_PIDLAUN_b *localZCE);
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
static void DEFAULT(void);
static int32_T getAutoXParam(autoX_params b_index);
static void autoXCheckShift(void);
static void LAUNCH2(void);
static void LAUNCH3(void);
static void LAUNCH4(void);
static void LAUNCH5(void);
static void LAUNCH6(void);
static void LAUNCH7(void);
static void LAUNCH8(void);
static void LAUNCH9(void);
static void exit_internal_ACCELERATION_PID(void);
static void enter_atomic_ACCELERATION(void);
static void ACCELERATION_PID(void);
static void AUTOCROSS(void);
static void MODES(void);
static void createRequest(uint8_T operation, uint8_T page, uint8_T cell, uint8_T
  dataSize, const uint8_T tempData[16]);
static void extractValues(uint8_T count);
static void shiftArray_hs(const int32_T array[13], real_T nValues);
static void shiftArray(const int32_T array[3], real_T nValues);
static void shiftArray_h(const int32_T array[23], real_T nValues);
static void updateOutput(void);
static void testIndex(uint8_T *page, uint8_T *cell, uint8_T *dataSize);
static int32_T getAntiStallParam(anti_stall_params b_index, const int32_T
  UnitDelay3[8]);
static void sendAutoXCommand(uint16_T com);
static void sendAccCommand(uint16_T com);
static void sendModeCommand(uint16_T com);
static void sendShiftCommand(uint16_T com);
static void sendStartEngCommand(void);
static void updateBuffer(const eepromRequest *BusConversion_InsertedFor_EEPRO);
extern real_T rtGetNaN(void);
extern real32_T rtGetNaNF(void);
extern ZCEventType rt_ZCFcn(ZCDirection zcDir, ZCSigState *prevZc, real_T
  currValue);
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
extern void rt_InitInfAndNaN(size_t realSize);
extern boolean_T rtIsInf(real_T value);
extern boolean_T rtIsInfF(real32_T value);
extern boolean_T rtIsNaN(real_T value);
extern boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
extern real_T rtGetInf(void);
extern real32_T rtGetInfF(void);
extern real_T rtGetMinusInf(void);
extern real32_T rtGetMinusInfF(void);

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0 } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/* Detect zero crossings events. */
ZCEventType rt_ZCFcn(ZCDirection zcDir, ZCSigState* prevZc, real_T currValue)
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
  slZcSignalSignType currSign = (slZcSignalSignType)((currValue) > 0.0 ?
    SL_ZCS_SIGN_POS :
    ((currValue) < 0.0 ? SL_ZCS_SIGN_NEG : SL_ZCS_SIGN_ZERO));

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
}                                      /* rt_ZCFcn */

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
boolean_T rtIsNaN(real_T value)
{
  return (boolean_T)((value!=value) ? 1U : 0U);
}

/* Test if single-precision value is not a number */
boolean_T rtIsNaNF(real32_T value)
{
  return (boolean_T)(((value!=value) ? 1U : 0U));
}

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

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

/* Output and update for function-call system: '<S45>/SetCut' */
static void SetCut(void)
{
  /* S-Function (Efi_setCut): '<S59>/Efi SetCut' */
  Efi_setCut_Outputs_wrapper();
}

/* Output and update for function-call system: '<S45>/UnsetCut' */
static void UnsetCut(void)
{
  /* S-Function (Efi_unsetCut): '<S61>/Efi UnSetCut' */
  Efi_unsetCut_Outputs_wrapper();
}

/* Output and update for function-call system: '<S45>/SetRPMLimiter' */
static void SetRPMLimiter(void)
{
  /* S-Function (Efi_setRPMLimiter): '<S60>/Efi SetRPMLimiter' */
  Efi_setRPMLimiter_Outputs_wrapper();
}

/* Output and update for function-call system: '<S45>/UnsetRPMLimiter' */
static void UnsetRPMLimiter(void)
{
  /* S-Function (Efi_unsetRPMLimiter): '<S62>/Efi UnSetRPMLimiter' */
  Efi_unsetRPMLimiter_Outputs_wrapper();
}

/* Output and update for function-call system: '<S49>/Gearmotor_release' */
static void Gearmotor_release(void)
{
  /* S-Function (GearMotor_release): '<S123>/GearMotor Release' */
  GearMotor_release_Outputs_wrapper(&rtDW.GearMotorRelease);

  /* SignalConversion: '<S123>/OutportBufferForPin H' */
  rtDW.Pin_H = rtDW.GearMotorRelease;
}

/* Output and update for function-call system: '<S49>/Gearmotor_turnRight' */
static void Gearmotor_turnRight(uint8_T *rty_Pin_In1, uint8_T *rty_Pin_In2,
  uint8_T *rty_Pin_H, DW_Gearmotor_turnRight *localDW)
{
  /* S-Function (GearMotor_turnRight): '<S125>/GearMotor Turn Right' */
  GearMotor_turnRight_Outputs_wrapper(&localDW->GearMotorTurnRight_o1,
    &localDW->GearMotorTurnRight_o2, &localDW->GearMotorTurnRight_o3);

  /* SignalConversion: '<S125>/OutportBufferForPin_H' */
  *rty_Pin_H = localDW->GearMotorTurnRight_o3;

  /* SignalConversion: '<S125>/OutportBufferForPin_In1' */
  *rty_Pin_In1 = localDW->GearMotorTurnRight_o1;

  /* SignalConversion: '<S125>/OutportBufferForPin_In2' */
  *rty_Pin_In2 = localDW->GearMotorTurnRight_o2;
}

/* Output and update for function-call system: '<S49>/Gearmotor_brake' */
static void Gearmotor_brake(uint8_T *rty_Pin_In1, uint8_T *rty_Pin_In2, uint8_T *
  rty_Pin_H, DW_Gearmotor_brake *localDW)
{
  /* S-Function (GearMotor_brake): '<S122>/GearMotor Brake' */
  GearMotor_brake_Outputs_wrapper(&localDW->GearMotorBrake_o1,
    &localDW->GearMotorBrake_o2, &localDW->GearMotorBrake_o3);

  /* SignalConversion: '<S122>/OutportBufferForPin_H' */
  *rty_Pin_H = localDW->GearMotorBrake_o3;

  /* SignalConversion: '<S122>/OutportBufferForPin_In1' */
  *rty_Pin_In1 = localDW->GearMotorBrake_o1;

  /* SignalConversion: '<S122>/OutportBufferForPin_In2' */
  *rty_Pin_In2 = localDW->GearMotorBrake_o2;
}

/* Output and update for function-call system: '<S46>/EngineControl_Start' */
static void EngineControl_Start(uint8_T *rty_engine_starter,
  DW_EngineControl_Start *localDW)
{
  /* S-Function (EngineControl_start): '<S63>/EngineControl Start' */
  EngineControl_start_Outputs_wrapper(&localDW->EngineControlStart);

  /* SignalConversion: '<S63>/OutportBufferForengine_starter' */
  *rty_engine_starter = localDW->EngineControlStart;
}

/* System initialize for function-call system: '<S3>/Evaluate_Request' */
static void Evaluate_Request_Init(int32_T rty_gearshiftTimings[24], int32_T
  rty_accParameters[16], int32_T rty_autoXParameters[16], int32_T
  rty_antiStallParameters[8], DW_Evaluate_Request *localDW)
{
  int32_T i;

  /* SystemInitialize for IfAction SubSystem: '<S30>/LoadFromEEPROM' */
  /* SystemInitialize for Chart: '<S32>/updateValues' */
  localDW->HAL_ERROR = 1U;

  /* End of SystemInitialize for SubSystem: '<S30>/LoadFromEEPROM' */

  /* SystemInitialize for Merge: '<S30>/Merge' */
  memset(&rty_gearshiftTimings[0], 0, 24U * sizeof(int32_T));

  /* SystemInitialize for Merge: '<S30>/Merge1' */
  memset(&rty_accParameters[0], 0, sizeof(int32_T) << 4U);

  /* SystemInitialize for Merge: '<S30>/Merge2' */
  memset(&rty_autoXParameters[0], 0, sizeof(int32_T) << 4U);

  /* SystemInitialize for Merge: '<S30>/Merge3' */
  for (i = 0; i < 8; i++) {
    rty_antiStallParameters[i] = 0;
  }

  /* End of SystemInitialize for Merge: '<S30>/Merge3' */
}

/* Output and update for function-call system: '<S3>/Evaluate_Request' */
static void Evaluate_Request(const eepromRequest *rtu_outputRequest, const
  int32_T rtu_accInitialParameters[13], const int32_T
  rtu_gearshiftInitialTimings[23], const int32_T rtu_autoXInitialParameters[13],
  const int32_T rtu_antiStallInitialParameters[3], uint8_T *rty_writeResult,
  uint8_T *rty_readResult, uint8_T *rty_wpState, int32_T rty_gearshiftTimings[24],
  int32_T rty_accParameters[16], int32_T rty_autoXParameters[16], int32_T
  rty_antiStallParameters[8], uint8_T *rty_dataRead, uint8_T *rty_dataRead_i,
  uint8_T *rty_dataRead_d, uint8_T rty_dataRead_l[16], DW_Evaluate_Request
  *localDW)
{
  uint16_T data_16bit[8];
  int32_T i;
  int32_T qY;
  uint8_T tmp;

  /* If: '<S30>/If' incorporates:
   *  Constant: '<S30>/Constant'
   *  Constant: '<S30>/Constant1'
   *  Constant: '<S30>/Constant2'
   *  Constant: '<S30>/Constant3'
   *  Inport: '<S33>/cell'
   *  Inport: '<S33>/dataSize'
   *  Inport: '<S33>/page'
   */
  if (rtu_outputRequest->operation == 87) {
    /* Outputs for IfAction SubSystem: '<S30>/Write' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */

    /* S-Function (Eeprom_write): '<S34>/Eeprom_write' */
    Eeprom_write_Outputs_wrapper(&rtu_outputRequest->page,
      &rtu_outputRequest->cell, &rtu_outputRequest->dataSize,
      &rtu_outputRequest->data[0], rty_writeResult, rty_wpState);

    /* End of Outputs for SubSystem: '<S30>/Write' */
  } else if (rtu_outputRequest->operation == 82) {
    /* Outputs for IfAction SubSystem: '<S30>/Read' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    *rty_dataRead = rtu_outputRequest->page;
    *rty_dataRead_i = rtu_outputRequest->cell;
    *rty_dataRead_d = rtu_outputRequest->dataSize;

    /* S-Function (Eeprom_read): '<S33>/Eeprom_read' incorporates:
     *  Inport: '<S33>/cell'
     *  Inport: '<S33>/dataSize'
     *  Inport: '<S33>/page'
     */
    Eeprom_read_Outputs_wrapper(rty_dataRead, rty_dataRead_i, rty_dataRead_d,
      rty_readResult, &rty_dataRead_l[0]);

    /* SignalConversion: '<S33>/TmpSignal ConversionAtsendEepromUARTInport1' */
    localDW->TmpSignalConversionAtsendEeprom[0] = *rty_dataRead;
    localDW->TmpSignalConversionAtsendEeprom[1] = *rty_dataRead_i;
    localDW->TmpSignalConversionAtsendEeprom[2] = *rty_dataRead_d;
    for (i = 0; i < 16; i++) {
      localDW->TmpSignalConversionAtsendEeprom[i + 3] = rty_dataRead_l[i];
    }

    /* End of SignalConversion: '<S33>/TmpSignal ConversionAtsendEepromUARTInport1' */

    /* S-Function (sendEepromUART): '<S33>/sendEepromUART' */
    sendEepromUART_Outputs_wrapper(&localDW->TmpSignalConversionAtsendEeprom[0]);

    /* End of Outputs for SubSystem: '<S30>/Read' */
  } else if (rtu_outputRequest->operation == 76) {
    /* Outputs for IfAction SubSystem: '<S30>/LoadFromEEPROM' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    /* S-Function (Eeprom_read): '<S32>/Eeprom_read' */
    Eeprom_read_Outputs_wrapper(&rtu_outputRequest->page,
      &rtu_outputRequest->cell, &rtu_outputRequest->dataSize,
      &localDW->Eeprom_read_o1, &localDW->Eeprom_read_o2[0]);

    /* Chart: '<S32>/updateValues' */
    if (localDW->Eeprom_read_o1 != localDW->HAL_ERROR) {
      for (i = 0; i < 8; i++) {
        /* NEW_PATTERN */
        data_16bit[i] = (uint16_T)((localDW->Eeprom_read_o2[((i + 1) << 1) - 2] <<
          8) + localDW->Eeprom_read_o2[((i + 1) << 1) - 1]);
      }

      if ((rtu_outputRequest->page == 1) || (rtu_outputRequest->page == 2) ||
          (rtu_outputRequest->page == 3)) {
        tmp = (uint8_T)(rtu_outputRequest->page << 3);
        qY = (int32_T)(tmp - /*MW:OvSatOk*/ 7U);
        if ((uint32_T)qY > tmp) {
          qY = 0;
        }

        for (i = 0; i < 8; i++) {
          localDW->gearshiftTimings[(i + (uint8_T)qY) - 1] = data_16bit[i];
        }
      } else if ((rtu_outputRequest->page == 5) || (rtu_outputRequest->page == 6))
      {
        tmp = (uint8_T)((uint8_T)(rtu_outputRequest->page - 4U) << 3);
        qY = (int32_T)(tmp - /*MW:OvSatOk*/ 7U);
        if ((uint32_T)qY > tmp) {
          qY = 0;
        }

        for (i = 0; i < 8; i++) {
          localDW->accParameters[(i + (uint8_T)qY) - 1] = data_16bit[i];
        }
      } else if ((rtu_outputRequest->page == 8) || (rtu_outputRequest->page == 9))
      {
        tmp = (uint8_T)((uint8_T)(rtu_outputRequest->page - 7U) << 3);
        qY = (int32_T)(tmp - /*MW:OvSatOk*/ 7U);
        if ((uint32_T)qY > tmp) {
          qY = 0;
        }

        for (i = 0; i < 8; i++) {
          localDW->autoXParameters[(i + (uint8_T)qY) - 1] = data_16bit[i];
        }
      } else {
        if (rtu_outputRequest->page == 11) {
          for (i = 0; i < 8; i++) {
            localDW->antiStallParameters[i] = data_16bit[i];
          }
        }
      }
    }

    /* End of Chart: '<S32>/updateValues' */

    /* DataTypeConversion: '<S32>/Cast2' */
    for (i = 0; i < 24; i++) {
      rty_gearshiftTimings[i] = localDW->gearshiftTimings[i];
    }

    /* End of DataTypeConversion: '<S32>/Cast2' */
    for (i = 0; i < 16; i++) {
      /* DataTypeConversion: '<S32>/Cast1' */
      rty_autoXParameters[i] = localDW->autoXParameters[i];

      /* DataTypeConversion: '<S32>/Cast3' */
      rty_accParameters[i] = localDW->accParameters[i];
    }

    /* DataTypeConversion: '<S32>/Cast4' */
    for (i = 0; i < 8; i++) {
      rty_antiStallParameters[i] = localDW->antiStallParameters[i];
    }

    /* End of DataTypeConversion: '<S32>/Cast4' */
    /* End of Outputs for SubSystem: '<S30>/LoadFromEEPROM' */
  } else {
    if (rtu_outputRequest->operation == 69) {
      /* Outputs for IfAction SubSystem: '<S30>/Error' incorporates:
       *  ActionPort: '<S31>/Action Port'
       */
      /* SignalConversion: '<S31>/OutportBufferForgearshiftTimings' incorporates:
       *  Constant: '<S31>/Constant'
       *  Inport: '<S31>/gearshiftInitialTimings'
       */
      memcpy(&rty_gearshiftTimings[0], &rtu_gearshiftInitialTimings[0], 23U *
             sizeof(int32_T));
      rty_gearshiftTimings[23] = 0;

      /* SignalConversion: '<S31>/OutportBufferForaccParameters' incorporates:
       *  Inport: '<S31>/accInitialParameters'
       */
      rty_accParameters[13] = 0;
      rty_accParameters[14] = 0;
      rty_accParameters[15] = 0;
      for (i = 0; i < 13; i++) {
        rty_accParameters[i] = rtu_accInitialParameters[i];

        /* SignalConversion: '<S31>/OutportBufferForautoXParameters' incorporates:
         *  Inport: '<S31>/accInitialParameters'
         *  Inport: '<S31>/autoXInitialParameters'
         */
        rty_autoXParameters[i] = rtu_autoXInitialParameters[i];
      }

      /* End of SignalConversion: '<S31>/OutportBufferForaccParameters' */

      /* SignalConversion: '<S31>/OutportBufferForautoXParameters' */
      rty_autoXParameters[13] = 0;

      /* SignalConversion: '<S31>/OutportBufferForantiStallParameters' incorporates:
       *  Inport: '<S31>/antiStallInitialParameters'
       */
      rty_antiStallParameters[0] = rtu_antiStallInitialParameters[0];

      /* SignalConversion: '<S31>/OutportBufferForautoXParameters' */
      rty_autoXParameters[14] = 0;

      /* SignalConversion: '<S31>/OutportBufferForantiStallParameters' incorporates:
       *  Inport: '<S31>/antiStallInitialParameters'
       */
      rty_antiStallParameters[1] = rtu_antiStallInitialParameters[1];

      /* SignalConversion: '<S31>/OutportBufferForautoXParameters' */
      rty_autoXParameters[15] = 0;

      /* SignalConversion: '<S31>/OutportBufferForantiStallParameters' incorporates:
       *  Inport: '<S31>/antiStallInitialParameters'
       */
      rty_antiStallParameters[2] = rtu_antiStallInitialParameters[2];
      for (i = 0; i < 5; i++) {
        rty_antiStallParameters[i + 3] = 0;
      }

      /* End of Outputs for SubSystem: '<S30>/Error' */
    }
  }

  /* End of If: '<S30>/If' */
}

/* System initialize for function-call system: '<S48>/MODES.ACCELERATION_PID.LAUNCH0.ACTIVE.ramp' */
static void MODESACCELERATION_PIDL_Init(DW_MODESACCELERATION_PIDLAUNCH0 *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S72>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_DSTATE = 50.0;
}

/* Enable for function-call system: '<S48>/MODES.ACCELERATION_PID.LAUNCH0.ACTIVE.ramp' */
static void MODESACCELERATION_PI_Enable(DW_MODESACCELERATION_PIDLAUNCH0 *localDW)
{
  localDW->MODESACCELERATION_PIDLAUNCH0A_k = true;

  /* Enable for DiscreteIntegrator: '<S72>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_SYSTEM_ = 1U;
}

/* Output and update for function-call system: '<S48>/MODES.ACCELERATION_PID.LAUNCH0.ACTIVE.ramp' */
static void MODESACCELERATION_PIDLAUNCH(RT_MODEL * const rtM, real_T
  *rty_clutchCurrVal, DW_MODESACCELERATION_PIDLAUNCH0 *localDW)
{
  uint32_T MODESACCELERATION_PIDLAUNCH0ACT;
  real_T DiscreteTimeIntegrator1;
  if (localDW->MODESACCELERATION_PIDLAUNCH0A_k) {
    MODESACCELERATION_PIDLAUNCH0ACT = 0U;
  } else {
    MODESACCELERATION_PIDLAUNCH0ACT = rtM->Timing.clockTick1 -
      localDW->MODESACCELERATION_PIDLAUNCH0A_b;
  }

  localDW->MODESACCELERATION_PIDLAUNCH0A_b = rtM->Timing.clockTick1;
  localDW->MODESACCELERATION_PIDLAUNCH0A_k = false;

  /* DiscreteIntegrator: '<S72>/Discrete-Time Integrator1' */
  if (localDW->DiscreteTimeIntegrator1_SYSTEM_ != 0) {
    DiscreteTimeIntegrator1 = localDW->DiscreteTimeIntegrator1_DSTATE;
  } else {
    DiscreteTimeIntegrator1 = 0.001 * (real_T)MODESACCELERATION_PIDLAUNCH0ACT *
      localDW->DiscreteTimeIntegrator1_PREV_U +
      localDW->DiscreteTimeIntegrator1_DSTATE;
  }

  if (DiscreteTimeIntegrator1 >= 50.0) {
    DiscreteTimeIntegrator1 = 50.0;
  } else {
    if (DiscreteTimeIntegrator1 <= 0.0) {
      DiscreteTimeIntegrator1 = 0.0;
    }
  }

  /* End of DiscreteIntegrator: '<S72>/Discrete-Time Integrator1' */

  /* Sum: '<S72>/Minus' incorporates:
   *  Constant: '<S72>/Constant'
   */
  localDW->Minus = 100.0 - DiscreteTimeIntegrator1;

  /* S-Function (ClutchMotor_setPWMRegister): '<S72>/ClutchMotor SetPWMRegister' */
  ClutchMotor_setPWMRegister_Outputs_wrapper(&localDW->Minus);

  /* SignalConversion: '<S72>/OutportBufferForclutchCurrVal' */
  *rty_clutchCurrVal = DiscreteTimeIntegrator1;

  /* Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S72>/Constant6'
   */
  localDW->DiscreteTimeIntegrator1_SYSTEM_ = 0U;
  localDW->DiscreteTimeIntegrator1_DSTATE = DiscreteTimeIntegrator1;
  localDW->DiscreteTimeIntegrator1_PREV_U = -200.0;
}

/* System initialize for function-call system: '<S48>/MODES.ACCELERATION_PID.LAUNCH1.ACTIVE.ramp' */
static void MODESACCELERATION_PI_j_Init(DW_MODESACCELERATION_PIDLAUNCH1 *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S73>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_DSTATE = 50.0;
}

/* Enable for function-call system: '<S48>/MODES.ACCELERATION_PID.LAUNCH1.ACTIVE.ramp' */
static void MODESACCELERATION__c_Enable(DW_MODESACCELERATION_PIDLAUNCH1 *localDW)
{
  localDW->MODESACCELERATION_PIDLAUNCH1A_i = true;

  /* Enable for DiscreteIntegrator: '<S73>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_SYSTEM_ = 1U;
}

/* Output and update for function-call system: '<S48>/MODES.ACCELERATION_PID.LAUNCH1.ACTIVE.ramp' */
static void MODESACCELERATION_PIDLAUN_o(RT_MODEL * const rtM, real_T
  *rty_clutchCurrVal, DW_MODESACCELERATION_PIDLAUNCH1 *localDW)
{
  uint32_T MODESACCELERATION_PIDLAUNCH1ACT;
  real_T DiscreteTimeIntegrator1;
  if (localDW->MODESACCELERATION_PIDLAUNCH1A_i) {
    MODESACCELERATION_PIDLAUNCH1ACT = 0U;
  } else {
    MODESACCELERATION_PIDLAUNCH1ACT = rtM->Timing.clockTick1 -
      localDW->MODESACCELERATION_PIDLAUNCH1A_m;
  }

  localDW->MODESACCELERATION_PIDLAUNCH1A_m = rtM->Timing.clockTick1;
  localDW->MODESACCELERATION_PIDLAUNCH1A_i = false;

  /* DiscreteIntegrator: '<S73>/Discrete-Time Integrator1' */
  if (localDW->DiscreteTimeIntegrator1_SYSTEM_ != 0) {
    DiscreteTimeIntegrator1 = localDW->DiscreteTimeIntegrator1_DSTATE;
  } else {
    DiscreteTimeIntegrator1 = 0.001 * (real_T)MODESACCELERATION_PIDLAUNCH1ACT *
      localDW->DiscreteTimeIntegrator1_PREV_U +
      localDW->DiscreteTimeIntegrator1_DSTATE;
  }

  if (DiscreteTimeIntegrator1 >= 50.0) {
    DiscreteTimeIntegrator1 = 50.0;
  } else {
    if (DiscreteTimeIntegrator1 <= 15.0) {
      DiscreteTimeIntegrator1 = 15.0;
    }
  }

  /* End of DiscreteIntegrator: '<S73>/Discrete-Time Integrator1' */

  /* Sum: '<S73>/Minus' incorporates:
   *  Constant: '<S73>/Constant'
   */
  localDW->Minus = 100.0 - DiscreteTimeIntegrator1;

  /* S-Function (ClutchMotor_setPWMRegister): '<S73>/ClutchMotor SetPWMRegister' */
  ClutchMotor_setPWMRegister_Outputs_wrapper(&localDW->Minus);

  /* SignalConversion: '<S73>/OutportBufferForclutchCurrVal' */
  *rty_clutchCurrVal = DiscreteTimeIntegrator1;

  /* Update for DiscreteIntegrator: '<S73>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S73>/Constant6'
   */
  localDW->DiscreteTimeIntegrator1_SYSTEM_ = 0U;
  localDW->DiscreteTimeIntegrator1_DSTATE = DiscreteTimeIntegrator1;
  localDW->DiscreteTimeIntegrator1_PREV_U = -200.0;
}

/*
 * System initialize for function-call system:
 *    '<S48>/MODES.ACCELERATION_PID.LAUNCH2.ACTIVE.ramp'
 *    '<S48>/MODES.ACCELERATION_PID.LAUNCH3.ACTIVE.ramp'
 */
static void MODESACCELERATION_PI_p_Init(DW_MODESACCELERATION_PIDLAUNCH2 *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S74>/Discrete-Time Integrator2' */
  localDW->DiscreteTimeIntegrator2_DSTATE = 50.0;
}

/*
 * Enable for function-call system:
 *    '<S48>/MODES.ACCELERATION_PID.LAUNCH2.ACTIVE.ramp'
 *    '<S48>/MODES.ACCELERATION_PID.LAUNCH3.ACTIVE.ramp'
 */
static void MODESACCELERATION__k_Enable(DW_MODESACCELERATION_PIDLAUNCH2 *localDW)
{
  localDW->MODESACCELERATION_PIDLAUNCH2A_o = true;

  /* Enable for DiscreteIntegrator: '<S74>/Discrete-Time Integrator2' */
  localDW->DiscreteTimeIntegrator2_SYSTEM_ = 1U;
}

/*
 * Output and update for function-call system:
 *    '<S48>/MODES.ACCELERATION_PID.LAUNCH2.ACTIVE.ramp'
 *    '<S48>/MODES.ACCELERATION_PID.LAUNCH3.ACTIVE.ramp'
 */
static void MODESACCELERATION_PIDLAUN_g(RT_MODEL * const rtM, real_T
  rtu_currentSlip, real_T rtu_slipTarget, real_T *rty_clutchVal,
  DW_MODESACCELERATION_PIDLAUNCH2 *localDW)
{
  real_T DiscreteTimeIntegrator2;
  if (localDW->MODESACCELERATION_PIDLAUNCH2A_o) {
    localDW->MODESACCELERATION_PIDLAUNCH2ACT = 0U;
  } else {
    localDW->MODESACCELERATION_PIDLAUNCH2ACT = rtM->Timing.clockTick1 -
      localDW->MODESACCELERATION_PIDLAUNCH2A_p;
  }

  localDW->MODESACCELERATION_PIDLAUNCH2A_p = rtM->Timing.clockTick1;
  localDW->MODESACCELERATION_PIDLAUNCH2A_o = false;

  /* DiscreteIntegrator: '<S74>/Discrete-Time Integrator2' */
  if (localDW->DiscreteTimeIntegrator2_SYSTEM_ != 0) {
    DiscreteTimeIntegrator2 = localDW->DiscreteTimeIntegrator2_DSTATE;
  } else {
    DiscreteTimeIntegrator2 = 0.001 * (real_T)
      localDW->MODESACCELERATION_PIDLAUNCH2ACT *
      localDW->DiscreteTimeIntegrator2_PREV_U +
      localDW->DiscreteTimeIntegrator2_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S74>/Discrete-Time Integrator2' */

  /* Saturate: '<S74>/Saturation4' */
  if (DiscreteTimeIntegrator2 > 35.0) {
    *rty_clutchVal = 35.0;
  } else if (DiscreteTimeIntegrator2 < 0.0) {
    *rty_clutchVal = 0.0;
  } else {
    *rty_clutchVal = DiscreteTimeIntegrator2;
  }

  /* End of Saturate: '<S74>/Saturation4' */

  /* Sum: '<S74>/Minus' incorporates:
   *  Constant: '<S74>/Constant'
   */
  localDW->Minus = 100.0 - *rty_clutchVal;

  /* S-Function (ClutchMotor_setPWMRegister): '<S74>/ClutchMotor SetPWMRegister' */
  ClutchMotor_setPWMRegister_Outputs_wrapper(&localDW->Minus);

  /* Update for DiscreteIntegrator: '<S74>/Discrete-Time Integrator2' */
  localDW->DiscreteTimeIntegrator2_SYSTEM_ = 0U;
  localDW->DiscreteTimeIntegrator2_DSTATE = DiscreteTimeIntegrator2;

  /* If: '<S74>/If' */
  if (rtu_currentSlip > 40.0) {
    /* Outputs for IfAction SubSystem: '<S74>/If Action Subsystem' incorporates:
     *  ActionPort: '<S86>/Action Port'
     */
    /* Update for DiscreteIntegrator: '<S74>/Discrete-Time Integrator2' incorporates:
     *  Constant: '<S74>/Constant8'
     *  Inport: '<S86>/In1'
     */
    localDW->DiscreteTimeIntegrator2_PREV_U = 200.0;

    /* End of Outputs for SubSystem: '<S74>/If Action Subsystem' */
  } else if (rtu_currentSlip > rtu_slipTarget) {
    /* Outputs for IfAction SubSystem: '<S74>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S87>/Action Port'
     */
    /* Update for DiscreteIntegrator: '<S74>/Discrete-Time Integrator2' incorporates:
     *  Constant: '<S74>/Constant9'
     *  Inport: '<S87>/In1'
     */
    localDW->DiscreteTimeIntegrator2_PREV_U = 100.0;

    /* End of Outputs for SubSystem: '<S74>/If Action Subsystem1' */
  } else if (rtu_currentSlip > 0.0) {
    /* Outputs for IfAction SubSystem: '<S74>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S89>/Action Port'
     */
    /* Update for DiscreteIntegrator: '<S74>/Discrete-Time Integrator2' incorporates:
     *  Constant: '<S74>/Constant10'
     *  Inport: '<S89>/In1'
     */
    localDW->DiscreteTimeIntegrator2_PREV_U = -600.0;

    /* End of Outputs for SubSystem: '<S74>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S74>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S88>/Action Port'
     */
    /* Update for DiscreteIntegrator: '<S74>/Discrete-Time Integrator2' incorporates:
     *  Constant: '<S74>/Constant11'
     *  Inport: '<S88>/In1'
     */
    localDW->DiscreteTimeIntegrator2_PREV_U = -200.0;

    /* End of Outputs for SubSystem: '<S74>/If Action Subsystem2' */
  }

  /* End of If: '<S74>/If' */
}

/*
 * System initialize for function-call system:
 *    '<S48>/MODES.ACCELERATION_PID.LAUNCH4.ACTIVE.ramp'
 *    '<S48>/MODES.ACCELERATION_PID.LAUNCH5.ACTIVE.ramp'
 */
static void MODESACCELERATION_PI_f_Init(DW_MODESACCELERATION_PIDLAUNCH4 *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S76>/Discrete-Time Integrator2' */
  localDW->DiscreteTimeIntegrator2_DSTATE = 50.0;
}

/*
 * Enable for function-call system:
 *    '<S48>/MODES.ACCELERATION_PID.LAUNCH4.ACTIVE.ramp'
 *    '<S48>/MODES.ACCELERATION_PID.LAUNCH5.ACTIVE.ramp'
 */
static void MODESACCELERATION__i_Enable(DW_MODESACCELERATION_PIDLAUNCH4 *localDW)
{
  localDW->MODESACCELERATION_PIDLAUNCH4A_c = true;

  /* Enable for DiscreteIntegrator: '<S76>/Discrete-Time Integrator2' */
  localDW->DiscreteTimeIntegrator2_SYSTEM_ = 1U;
}

/*
 * Output and update for function-call system:
 *    '<S48>/MODES.ACCELERATION_PID.LAUNCH4.ACTIVE.ramp'
 *    '<S48>/MODES.ACCELERATION_PID.LAUNCH5.ACTIVE.ramp'
 */
static void MODESACCELERATION_PIDLAUN_n(RT_MODEL * const rtM, real_T
  rtu_currentSlip, real_T rtu_slipTarget, real_T *rty_clutchVal,
  DW_MODESACCELERATION_PIDLAUNCH4 *localDW)
{
  real_T DiscreteTimeIntegrator2;
  if (localDW->MODESACCELERATION_PIDLAUNCH4A_c) {
    localDW->MODESACCELERATION_PIDLAUNCH4ACT = 0U;
  } else {
    localDW->MODESACCELERATION_PIDLAUNCH4ACT = rtM->Timing.clockTick1 -
      localDW->MODESACCELERATION_PIDLAUNCH4A_f;
  }

  localDW->MODESACCELERATION_PIDLAUNCH4A_f = rtM->Timing.clockTick1;
  localDW->MODESACCELERATION_PIDLAUNCH4A_c = false;

  /* DiscreteIntegrator: '<S76>/Discrete-Time Integrator2' */
  if (localDW->DiscreteTimeIntegrator2_SYSTEM_ != 0) {
    DiscreteTimeIntegrator2 = localDW->DiscreteTimeIntegrator2_DSTATE;
  } else {
    DiscreteTimeIntegrator2 = 0.001 * (real_T)
      localDW->MODESACCELERATION_PIDLAUNCH4ACT *
      localDW->DiscreteTimeIntegrator2_PREV_U +
      localDW->DiscreteTimeIntegrator2_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S76>/Discrete-Time Integrator2' */

  /* Saturate: '<S76>/Saturation4' */
  if (DiscreteTimeIntegrator2 > 25.0) {
    *rty_clutchVal = 25.0;
  } else if (DiscreteTimeIntegrator2 < 0.0) {
    *rty_clutchVal = 0.0;
  } else {
    *rty_clutchVal = DiscreteTimeIntegrator2;
  }

  /* End of Saturate: '<S76>/Saturation4' */

  /* Sum: '<S76>/Minus' incorporates:
   *  Constant: '<S76>/Constant'
   */
  localDW->Minus = 100.0 - *rty_clutchVal;

  /* S-Function (ClutchMotor_setPWMRegister): '<S76>/ClutchMotor SetPWMRegister' */
  ClutchMotor_setPWMRegister_Outputs_wrapper(&localDW->Minus);

  /* Update for DiscreteIntegrator: '<S76>/Discrete-Time Integrator2' */
  localDW->DiscreteTimeIntegrator2_SYSTEM_ = 0U;
  localDW->DiscreteTimeIntegrator2_DSTATE = DiscreteTimeIntegrator2;

  /* If: '<S76>/If' */
  if (rtu_currentSlip > 40.0) {
    /* Outputs for IfAction SubSystem: '<S76>/If Action Subsystem' incorporates:
     *  ActionPort: '<S94>/Action Port'
     */
    /* Update for DiscreteIntegrator: '<S76>/Discrete-Time Integrator2' incorporates:
     *  Constant: '<S76>/Constant8'
     *  Inport: '<S94>/In1'
     */
    localDW->DiscreteTimeIntegrator2_PREV_U = 200.0;

    /* End of Outputs for SubSystem: '<S76>/If Action Subsystem' */
  } else if (rtu_currentSlip > rtu_slipTarget) {
    /* Outputs for IfAction SubSystem: '<S76>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S95>/Action Port'
     */
    /* Update for DiscreteIntegrator: '<S76>/Discrete-Time Integrator2' incorporates:
     *  Constant: '<S76>/Constant9'
     *  Inport: '<S95>/In1'
     */
    localDW->DiscreteTimeIntegrator2_PREV_U = 100.0;

    /* End of Outputs for SubSystem: '<S76>/If Action Subsystem1' */
  } else if (rtu_currentSlip > 0.0) {
    /* Outputs for IfAction SubSystem: '<S76>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S97>/Action Port'
     */
    /* Update for DiscreteIntegrator: '<S76>/Discrete-Time Integrator2' incorporates:
     *  Constant: '<S76>/Constant10'
     *  Inport: '<S97>/In1'
     */
    localDW->DiscreteTimeIntegrator2_PREV_U = -600.0;

    /* End of Outputs for SubSystem: '<S76>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S76>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S96>/Action Port'
     */
    /* Update for DiscreteIntegrator: '<S76>/Discrete-Time Integrator2' incorporates:
     *  Constant: '<S76>/Constant11'
     *  Inport: '<S96>/In1'
     */
    localDW->DiscreteTimeIntegrator2_PREV_U = -200.0;

    /* End of Outputs for SubSystem: '<S76>/If Action Subsystem2' */
  }

  /* End of If: '<S76>/If' */
}

/*
 * System initialize for function-call system:
 *    '<S48>/MODES.ACCELERATION_PID.LAUNCH6.ACTIVE.pidControl'
 *    '<S48>/MODES.ACCELERATION_PID.LAUNCH7.ACTIVE.pidControl'
 */
static void MODESACCELERATION_PI_l_Init(DW_MODESACCELERATION_PIDLAUNCH6 *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S102>/Integrator' */
  localDW->Integrator_PrevResetState = 2;
}

/*
 * Enable for function-call system:
 *    '<S48>/MODES.ACCELERATION_PID.LAUNCH6.ACTIVE.pidControl'
 *    '<S48>/MODES.ACCELERATION_PID.LAUNCH7.ACTIVE.pidControl'
 */
static void MODESACCELERATION__j_Enable(DW_MODESACCELERATION_PIDLAUNCH6 *localDW)
{
  localDW->MODESACCELERATION_PIDLAUNCH6A_m = true;

  /* Enable for DiscreteIntegrator: '<S102>/Integrator' */
  localDW->Integrator_SYSTEM_ENABLE = 1U;
}

/*
 * Output and update for function-call system:
 *    '<S48>/MODES.ACCELERATION_PID.LAUNCH6.ACTIVE.pidControl'
 *    '<S48>/MODES.ACCELERATION_PID.LAUNCH7.ACTIVE.pidControl'
 */
static void MODESACCELERATION_PIDLAUN_l(RT_MODEL * const rtM, real_T
  rtu_slipTarget, real_T rtu_currentSlip, real_T rtu_reset, real_T
  *rty_clutchVal, DW_MODESACCELERATION_PIDLAUNCH6 *localDW,
  ZCE_MODESACCELERATION_PIDLAUN_j *localZCE)
{
  real_T rtb_IOut;
  real_T rtb_Saturate;
  real_T rtb_SignPreIntegrator;
  real_T rtb_TSamp;
  boolean_T rtb_NotEqual;
  real_T Integrator;
  int8_T rtb_SignPreIntegrator_0;
  if (localDW->MODESACCELERATION_PIDLAUNCH6A_m) {
    localDW->MODESACCELERATION_PIDLAUNCH6ACT = 0U;
  } else {
    localDW->MODESACCELERATION_PIDLAUNCH6ACT = rtM->Timing.clockTick1 -
      localDW->MODESACCELERATION_PIDLAUNCH6A_a;
  }

  localDW->MODESACCELERATION_PIDLAUNCH6A_a = rtM->Timing.clockTick1;
  localDW->MODESACCELERATION_PIDLAUNCH6A_m = false;

  /* If: '<S78>/If1' incorporates:
   *  Constant: '<S78>/Constant12'
   *  Constant: '<S78>/Constant13'
   *  Constant: '<S78>/Constant15'
   *  Constant: '<S78>/Constant16'
   *  Inport: '<S103>/In1'
   *  Inport: '<S103>/In2'
   *  Inport: '<S104>/In1'
   *  Inport: '<S104>/In2'
   */
  if (rtu_slipTarget > rtu_currentSlip) {
    /* Outputs for IfAction SubSystem: '<S78>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S103>/Action Port'
     */
    rtb_Saturate = 0.1;
    rtb_SignPreIntegrator = 0.0;

    /* End of Outputs for SubSystem: '<S78>/If Action Subsystem4' */
  } else {
    /* Outputs for IfAction SubSystem: '<S78>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S104>/Action Port'
     */
    rtb_Saturate = 1.0;
    rtb_SignPreIntegrator = 0.1;

    /* End of Outputs for SubSystem: '<S78>/If Action Subsystem5' */
  }

  /* End of If: '<S78>/If1' */

  /* Sum: '<S78>/Sum1' */
  rtb_IOut = rtu_slipTarget - rtu_currentSlip;

  /* DiscreteIntegrator: '<S102>/Integrator' */
  if (localDW->Integrator_SYSTEM_ENABLE != 0) {
    Integrator = localDW->Integrator_DSTATE;
  } else if ((rtu_reset > 0.0) && (localDW->Integrator_PrevResetState <= 0)) {
    localDW->Integrator_DSTATE = 0.0;
    Integrator = localDW->Integrator_DSTATE;
  } else {
    Integrator = 0.001 * (real_T)localDW->MODESACCELERATION_PIDLAUNCH6ACT *
      localDW->Integrator_PREV_U + localDW->Integrator_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S102>/Integrator' */

  /* Product: '<S102>/DOut' */
  rtb_SignPreIntegrator *= rtb_IOut;

  /* SampleTimeMath: '<S106>/TSamp'
   *
   * About '<S106>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = rtb_SignPreIntegrator / ((real_T)
    localDW->MODESACCELERATION_PIDLAUNCH6ACT * 0.001);

  /* Delay: '<S106>/UD' */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,&localZCE->UD_Reset_ZCE_j,
               (rtu_reset)) != NO_ZCEVENT) {
    localDW->UD_DSTATE = 0.0;
  }

  /* Sum: '<S102>/Sum' incorporates:
   *  Delay: '<S106>/UD'
   *  Product: '<S102>/POut'
   *  Sum: '<S106>/Diff'
   */
  rtb_SignPreIntegrator = (rtb_IOut * rtb_Saturate + Integrator) + (rtb_TSamp -
    localDW->UD_DSTATE);

  /* Saturate: '<S102>/Saturate' */
  if (rtb_SignPreIntegrator > 17.0) {
    rtb_Saturate = 17.0;
  } else if (rtb_SignPreIntegrator < -18.0) {
    rtb_Saturate = -18.0;
  } else {
    rtb_Saturate = rtb_SignPreIntegrator;
  }

  /* End of Saturate: '<S102>/Saturate' */

  /* Sum: '<S78>/Sum' incorporates:
   *  Constant: '<S78>/Constant1'
   */
  *rty_clutchVal = 17.0 - rtb_Saturate;

  /* Sum: '<S78>/Minus' incorporates:
   *  Constant: '<S78>/Constant'
   */
  localDW->Minus = 100.0 - *rty_clutchVal;

  /* S-Function (ClutchMotor_setPWMRegister): '<S78>/ClutchMotor SetPWMRegister' */
  ClutchMotor_setPWMRegister_Outputs_wrapper(&localDW->Minus);

  /* Gain: '<S105>/ZeroGain' */
  rtb_Saturate = 0.0 * rtb_SignPreIntegrator;

  /* DeadZone: '<S105>/DeadZone' */
  if (rtb_SignPreIntegrator > 17.0) {
    rtb_SignPreIntegrator -= 17.0;
  } else if (rtb_SignPreIntegrator >= -18.0) {
    rtb_SignPreIntegrator = 0.0;
  } else {
    rtb_SignPreIntegrator -= -18.0;
  }

  /* End of DeadZone: '<S105>/DeadZone' */

  /* RelationalOperator: '<S105>/NotEqual' */
  rtb_NotEqual = (rtb_Saturate != rtb_SignPreIntegrator);

  /* Signum: '<S105>/SignDeltaU' */
  if (rtb_SignPreIntegrator < 0.0) {
    rtb_SignPreIntegrator = -1.0;
  } else if (rtb_SignPreIntegrator > 0.0) {
    rtb_SignPreIntegrator = 1.0;
  } else if (rtb_SignPreIntegrator == 0.0) {
    rtb_SignPreIntegrator = 0.0;
  } else {
    rtb_SignPreIntegrator = (rtNaN);
  }

  /* End of Signum: '<S105>/SignDeltaU' */

  /* Product: '<S102>/IOut' incorporates:
   *  Constant: '<S78>/Constant14'
   */
  rtb_IOut *= 10.0;

  /* Update for DiscreteIntegrator: '<S102>/Integrator' */
  localDW->Integrator_SYSTEM_ENABLE = 0U;
  localDW->Integrator_DSTATE = Integrator;
  if (rtu_reset > 0.0) {
    localDW->Integrator_PrevResetState = 1;
  } else if (rtu_reset < 0.0) {
    localDW->Integrator_PrevResetState = -1;
  } else if (rtu_reset == 0.0) {
    localDW->Integrator_PrevResetState = 0;
  } else {
    localDW->Integrator_PrevResetState = 2;
  }

  /* DataTypeConversion: '<S105>/DataTypeConv1' */
  if (rtb_SignPreIntegrator < 128.0) {
    rtb_SignPreIntegrator_0 = (int8_T)rtb_SignPreIntegrator;
  } else {
    rtb_SignPreIntegrator_0 = MAX_int8_T;
  }

  /* End of DataTypeConversion: '<S105>/DataTypeConv1' */

  /* Signum: '<S105>/SignPreIntegrator' */
  if (rtb_IOut < 0.0) {
    rtb_SignPreIntegrator = -1.0;
  } else if (rtb_IOut > 0.0) {
    rtb_SignPreIntegrator = 1.0;
  } else if (rtb_IOut == 0.0) {
    rtb_SignPreIntegrator = 0.0;
  } else {
    rtb_SignPreIntegrator = (rtNaN);
  }

  /* End of Signum: '<S105>/SignPreIntegrator' */

  /* Switch: '<S102>/Switch' incorporates:
   *  DataTypeConversion: '<S105>/DataTypeConv2'
   *  Logic: '<S105>/AND'
   *  RelationalOperator: '<S105>/Equal'
   */
  if (rtb_NotEqual && (rtb_SignPreIntegrator_0 == (int8_T)rtb_SignPreIntegrator))
  {
    /* Update for DiscreteIntegrator: '<S102>/Integrator' incorporates:
     *  Constant: '<S102>/Constant'
     */
    localDW->Integrator_PREV_U = 0.0;
  } else {
    /* Update for DiscreteIntegrator: '<S102>/Integrator' */
    localDW->Integrator_PREV_U = rtb_IOut;
  }

  /* End of Switch: '<S102>/Switch' */

  /* Update for Delay: '<S106>/UD' */
  localDW->UD_DSTATE = rtb_TSamp;
}

/*
 * System initialize for function-call system:
 *    '<S48>/MODES.ACCELERATION_PID.LAUNCH8.ACTIVE.pidControl'
 *    '<S48>/MODES.ACCELERATION_PID.LAUNCH9.ACTIVE.pidControl'
 */
static void MODESACCELERATION_PI_b_Init(DW_MODESACCELERATION_PIDLAUNCH8 *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S112>/Integrator' */
  localDW->Integrator_PrevResetState = 2;
}

/*
 * Enable for function-call system:
 *    '<S48>/MODES.ACCELERATION_PID.LAUNCH8.ACTIVE.pidControl'
 *    '<S48>/MODES.ACCELERATION_PID.LAUNCH9.ACTIVE.pidControl'
 */
static void MODESACCELERATION__e_Enable(DW_MODESACCELERATION_PIDLAUNCH8 *localDW)
{
  localDW->MODESACCELERATION_PIDLAUNCH8A_e = true;

  /* Enable for DiscreteIntegrator: '<S112>/Integrator' */
  localDW->Integrator_SYSTEM_ENABLE = 1U;
}

/*
 * Output and update for function-call system:
 *    '<S48>/MODES.ACCELERATION_PID.LAUNCH8.ACTIVE.pidControl'
 *    '<S48>/MODES.ACCELERATION_PID.LAUNCH9.ACTIVE.pidControl'
 */
static void MODESACCELERATION_PIDLAUN_e(RT_MODEL * const rtM, real_T
  rtu_slipTarget, real_T rtu_currentSlip, real_T rtu_reset, real_T
  *rty_clutchVal, DW_MODESACCELERATION_PIDLAUNCH8 *localDW,
  ZCE_MODESACCELERATION_PIDLAUN_b *localZCE)
{
  real_T rtb_IOut;
  real_T rtb_Saturate;
  real_T rtb_SignPreIntegrator;
  real_T rtb_TSamp;
  boolean_T rtb_NotEqual;
  real_T Integrator;
  int8_T rtb_SignPreIntegrator_d;
  if (localDW->MODESACCELERATION_PIDLAUNCH8A_e) {
    localDW->MODESACCELERATION_PIDLAUNCH8ACT = 0U;
  } else {
    localDW->MODESACCELERATION_PIDLAUNCH8ACT = rtM->Timing.clockTick1 -
      localDW->MODESACCELERATION_PIDLAUNCH8A_l;
  }

  localDW->MODESACCELERATION_PIDLAUNCH8A_l = rtM->Timing.clockTick1;
  localDW->MODESACCELERATION_PIDLAUNCH8A_e = false;

  /* If: '<S80>/If1' incorporates:
   *  Constant: '<S80>/Constant12'
   *  Constant: '<S80>/Constant13'
   *  Constant: '<S80>/Constant15'
   *  Constant: '<S80>/Constant16'
   *  Inport: '<S113>/In1'
   *  Inport: '<S113>/In2'
   *  Inport: '<S114>/In1'
   *  Inport: '<S114>/In2'
   */
  if (rtu_slipTarget > rtu_currentSlip) {
    /* Outputs for IfAction SubSystem: '<S80>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S113>/Action Port'
     */
    rtb_Saturate = 0.1;
    rtb_SignPreIntegrator = 0.0;

    /* End of Outputs for SubSystem: '<S80>/If Action Subsystem4' */
  } else {
    /* Outputs for IfAction SubSystem: '<S80>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S114>/Action Port'
     */
    rtb_Saturate = 1.0;
    rtb_SignPreIntegrator = 0.1;

    /* End of Outputs for SubSystem: '<S80>/If Action Subsystem5' */
  }

  /* End of If: '<S80>/If1' */

  /* Sum: '<S80>/Sum1' */
  rtb_IOut = rtu_slipTarget - rtu_currentSlip;

  /* DiscreteIntegrator: '<S112>/Integrator' */
  if (localDW->Integrator_SYSTEM_ENABLE != 0) {
    Integrator = localDW->Integrator_DSTATE;
  } else if ((rtu_reset > 0.0) && (localDW->Integrator_PrevResetState <= 0)) {
    localDW->Integrator_DSTATE = 0.0;
    Integrator = localDW->Integrator_DSTATE;
  } else {
    Integrator = 0.001 * (real_T)localDW->MODESACCELERATION_PIDLAUNCH8ACT *
      localDW->Integrator_PREV_U + localDW->Integrator_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S112>/Integrator' */

  /* Product: '<S112>/DOut' */
  rtb_SignPreIntegrator *= rtb_IOut;

  /* SampleTimeMath: '<S116>/TSamp'
   *
   * About '<S116>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = rtb_SignPreIntegrator / ((real_T)
    localDW->MODESACCELERATION_PIDLAUNCH8ACT * 0.001);

  /* Delay: '<S116>/UD' */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,&localZCE->UD_Reset_ZCE,
               (rtu_reset)) != NO_ZCEVENT) {
    localDW->UD_DSTATE = 0.0;
  }

  /* Sum: '<S112>/Sum' incorporates:
   *  Delay: '<S116>/UD'
   *  Product: '<S112>/POut'
   *  Sum: '<S116>/Diff'
   */
  rtb_SignPreIntegrator = (rtb_IOut * rtb_Saturate + Integrator) + (rtb_TSamp -
    localDW->UD_DSTATE);

  /* Saturate: '<S112>/Saturate' */
  if (rtb_SignPreIntegrator > 20.0) {
    rtb_Saturate = 20.0;
  } else if (rtb_SignPreIntegrator < -20.0) {
    rtb_Saturate = -20.0;
  } else {
    rtb_Saturate = rtb_SignPreIntegrator;
  }

  /* End of Saturate: '<S112>/Saturate' */

  /* Sum: '<S80>/Sum' incorporates:
   *  Constant: '<S80>/Constant1'
   */
  *rty_clutchVal = 20.0 - rtb_Saturate;

  /* Sum: '<S80>/Minus' incorporates:
   *  Constant: '<S80>/Constant'
   */
  localDW->Minus = 100.0 - *rty_clutchVal;

  /* S-Function (ClutchMotor_setPWMRegister): '<S80>/ClutchMotor SetPWMRegister' */
  ClutchMotor_setPWMRegister_Outputs_wrapper(&localDW->Minus);

  /* Gain: '<S115>/ZeroGain' */
  rtb_Saturate = 0.0 * rtb_SignPreIntegrator;

  /* DeadZone: '<S115>/DeadZone' */
  if (rtb_SignPreIntegrator > 20.0) {
    rtb_SignPreIntegrator -= 20.0;
  } else if (rtb_SignPreIntegrator >= -20.0) {
    rtb_SignPreIntegrator = 0.0;
  } else {
    rtb_SignPreIntegrator -= -20.0;
  }

  /* End of DeadZone: '<S115>/DeadZone' */

  /* RelationalOperator: '<S115>/NotEqual' */
  rtb_NotEqual = (rtb_Saturate != rtb_SignPreIntegrator);

  /* Signum: '<S115>/SignDeltaU' */
  if (rtb_SignPreIntegrator < 0.0) {
    rtb_SignPreIntegrator = -1.0;
  } else if (rtb_SignPreIntegrator > 0.0) {
    rtb_SignPreIntegrator = 1.0;
  } else if (rtb_SignPreIntegrator == 0.0) {
    rtb_SignPreIntegrator = 0.0;
  } else {
    rtb_SignPreIntegrator = (rtNaN);
  }

  /* End of Signum: '<S115>/SignDeltaU' */

  /* Product: '<S112>/IOut' incorporates:
   *  Constant: '<S80>/Constant14'
   */
  rtb_IOut *= 10.0;

  /* Update for DiscreteIntegrator: '<S112>/Integrator' */
  localDW->Integrator_SYSTEM_ENABLE = 0U;
  localDW->Integrator_DSTATE = Integrator;
  if (rtu_reset > 0.0) {
    localDW->Integrator_PrevResetState = 1;
  } else if (rtu_reset < 0.0) {
    localDW->Integrator_PrevResetState = -1;
  } else if (rtu_reset == 0.0) {
    localDW->Integrator_PrevResetState = 0;
  } else {
    localDW->Integrator_PrevResetState = 2;
  }

  /* DataTypeConversion: '<S115>/DataTypeConv1' */
  if (rtb_SignPreIntegrator < 128.0) {
    rtb_SignPreIntegrator_d = (int8_T)rtb_SignPreIntegrator;
  } else {
    rtb_SignPreIntegrator_d = MAX_int8_T;
  }

  /* End of DataTypeConversion: '<S115>/DataTypeConv1' */

  /* Signum: '<S115>/SignPreIntegrator' */
  if (rtb_IOut < 0.0) {
    rtb_SignPreIntegrator = -1.0;
  } else if (rtb_IOut > 0.0) {
    rtb_SignPreIntegrator = 1.0;
  } else if (rtb_IOut == 0.0) {
    rtb_SignPreIntegrator = 0.0;
  } else {
    rtb_SignPreIntegrator = (rtNaN);
  }

  /* End of Signum: '<S115>/SignPreIntegrator' */

  /* Switch: '<S112>/Switch' incorporates:
   *  DataTypeConversion: '<S115>/DataTypeConv2'
   *  Logic: '<S115>/AND'
   *  RelationalOperator: '<S115>/Equal'
   */
  if (rtb_NotEqual && (rtb_SignPreIntegrator_d == (int8_T)rtb_SignPreIntegrator))
  {
    /* Update for DiscreteIntegrator: '<S112>/Integrator' incorporates:
     *  Constant: '<S112>/Constant'
     */
    localDW->Integrator_PREV_U = 0.0;
  } else {
    /* Update for DiscreteIntegrator: '<S112>/Integrator' */
    localDW->Integrator_PREV_U = rtb_IOut;
  }

  /* End of Switch: '<S112>/Switch' */

  /* Update for Delay: '<S116>/UD' */
  localDW->UD_DSTATE = rtb_TSamp;
}

/* Output and update for function-call system: '<S48>/SCAN_ADC.ScanADC' */
static void SCAN_ADCScanADC(void)
{
  /* S-Function (ScanADC): '<S82>/ScanADC' */
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
      if (rtDW.RateTransition36[6] != 0) {
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
      time = rtDW.UnitDelay1[(int32_T)DEFAULT_NT_CLUTCH_DELAY];
    } else {
      time = rtDW.UnitDelay1[(int32_T)DELAY];
    }
  } else if (rtDW.is_UPSHIFTING == IN_UP_PUSH) {
    if (rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) {
      time = rtDW.UnitDelay1[(int32_T)NT_CLUTCH_DELAY];
    } else {
      switch (rtDW.RateTransition36[6]) {
       case 1:
        time = rtDW.UnitDelay1[(int32_T)UP_PUSH_1_2];
        break;

       case 2:
        time = rtDW.UnitDelay1[(int32_T)UP_PUSH_2_3];
        break;

       case 3:
        time = rtDW.UnitDelay1[(int32_T)UP_PUSH_3_4];
        break;

       case 4:
        time = rtDW.UnitDelay1[(int32_T)UP_PUSH_4_5];
        break;

       default:
        time = rtDW.UnitDelay1[(int32_T)UP_PUSH_2_3];
        break;
      }
    }
  } else if (rtDW.is_UPSHIFTING == IN_UP_REBOUND) {
    if (rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) {
      time = rtDW.UnitDelay1[(int32_T)NT_REBOUND_1_N];
    } else {
      time = rtDW.UnitDelay1[(int32_T)UP_REBOUND];
    }
  } else if (rtDW.is_UPSHIFTING == IN_UP_BRAKE) {
    if (rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) {
      time = rtDW.UnitDelay1[(int32_T)NT_BRAKE_1_N];
    } else {
      time = rtDW.UnitDelay1[(int32_T)UP_BRAKE];
    }
  } else if (rtDW.is_DOWNSHIFTING == IN_DOWN_START) {
    time = rtDW.UnitDelay1[(int32_T)CLUTCH];
  } else if (rtDW.is_DOWNSHIFTING == IN_DOWN_PUSH) {
    time = rtDW.UnitDelay1[(int32_T)DN_PUSH];
  } else if (rtDW.is_DOWNSHIFTING == IN_DOWN_REBOUND) {
    time = rtDW.UnitDelay1[(int32_T)DN_REBOUND];
  } else {
    time = rtDW.UnitDelay1[(int32_T)DN_BRAKE];
  }

  return time;
}

/* Function for Chart: '<S5>/GCULogic' */
static void Clutch_setValue(uint8_T setValue)
{
  uint8_T tmp;
  rtDW.clutchCurrVal = setValue;

  /* Outputs for Function Call SubSystem: '<S44>/ClutchMotor SetPosition ' */
  /* Saturate: '<S57>/Saturation' */
  if (rtDW.UnitDelay1_i < 100) {
    tmp = rtDW.UnitDelay1_i;
  } else {
    tmp = 100U;
  }

  /* End of Saturate: '<S57>/Saturation' */

  /* Sum: '<S57>/Minus' incorporates:
   *  Constant: '<S57>/Constant'
   */
  rtDW.Minus = (uint8_T)(100 - tmp);

  /* S-Function (ClutchMotor_setPosition): '<S57>/ClutchMotor SetPosition' */
  ClutchMotor_setPosition_Outputs_wrapper(&rtDW.Minus);

  /* End of Outputs for SubSystem: '<S44>/ClutchMotor SetPosition ' */
}

/* Function for Chart: '<S5>/GCULogic' */
static void GEARSHIFT(void)
{
  uint8_T Pin_In1;
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

          /* Outputs for Function Call SubSystem: '<S49>/Gearmotor_release' */
          Gearmotor_release();

          /* End of Outputs for SubSystem: '<S49>/Gearmotor_release' */
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

          /* Outputs for Function Call SubSystem: '<S49>/Gearmotor_release' */
          Gearmotor_release();

          /* End of Outputs for SubSystem: '<S49>/Gearmotor_release' */

          /* Outputs for Function Call SubSystem: '<S45>/UnsetCut' */
          UnsetCut();

          /* End of Outputs for SubSystem: '<S45>/UnsetCut' */
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
            Clutch_setValue(0);

            /* Outputs for Function Call SubSystem: '<S49>/Gearmotor_brake' */
            Gearmotor_brake(&Pin_In1, &Pin_In2, &rtDW.Pin_H,
                            &rtDW.Gearmotor_brake_c);

            /* End of Outputs for SubSystem: '<S49>/Gearmotor_brake' */
          }
        } else {
          if (rtDW.is_DOWN_BRAKE != IN_Default_b) {
            rtDW.is_DOWN_BRAKE = IN_Default_b;

            /* Outputs for Function Call SubSystem: '<S49>/Gearmotor_brake' */
            Gearmotor_brake(&Pin_In1, &Pin_In2, &rtDW.Pin_H,
                            &rtDW.Gearmotor_brake_c);

            /* End of Outputs for SubSystem: '<S49>/Gearmotor_brake' */
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

          /* Outputs for Function Call SubSystem: '<S49>/Gearmotor_turnLeft' */
          /* S-Function (GearMotor_turnLeft): '<S124>/GearMotor Turn Left' */
          GearMotor_turnLeft_Outputs_wrapper(&rtDW.GearMotorTurnLeft_o1,
            &rtDW.GearMotorTurnLeft_o2, &rtDW.GearMotorTurnLeft_o3);

          /* SignalConversion: '<S124>/OutportBufferForPin_H' */
          rtDW.Pin_H = rtDW.GearMotorTurnLeft_o3;

          /* End of Outputs for SubSystem: '<S49>/Gearmotor_turnLeft' */
        }

        if (rtDW.RateTransition36[2] >= 20) {
          /* Outputs for Function Call SubSystem: '<S45>/SetCut' */
          SetCut();

          /* End of Outputs for SubSystem: '<S45>/SetCut' */
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
    if ((rtDW.sfEvent == event_GearshiftUp) && ((rtDW.RateTransition36[6] < 5) ||
         (rtDW.RateTransition36[6] == 8))) {
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

      if ((rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) && (rtDW.clutchCurrVal <= 80))
      {
        if (rtDW.is_UP_START != IN_SettingNeutral) {
          rtDW.is_UP_START = IN_SettingNeutral;
          Clutch_setValue(80);
        }
      } else {
        if (rtDW.is_UP_START != IN_Default) {
          rtDW.is_UP_START = IN_Default;

          /* Outputs for Function Call SubSystem: '<S45>/SetCut' */
          SetCut();

          /* End of Outputs for SubSystem: '<S45>/SetCut' */
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
          if (rtDW.is_DOWN_START != IN_SettingNeutral_e) {
            rtDW.is_DOWN_START = IN_SettingNeutral_e;
            Clutch_setValue(80);
          }
        } else if ((!(rtDW.is_NEUTRAL_STATE == IN_UNSET_NEUTRAL)) &&
                   (rtDW.clutchCurrVal <= 70)) {
          if (rtDW.is_DOWN_START != IN_ChangeClutch) {
            rtDW.is_DOWN_START = IN_ChangeClutch;
            Clutch_setValue(70);
          }
        } else {
          rtDW.is_DOWN_START = IN_Default_b;
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

          /* Outputs for Function Call SubSystem: '<S49>/Gearmotor_release' */
          Gearmotor_release();

          /* End of Outputs for SubSystem: '<S49>/Gearmotor_release' */
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

        if ((rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) && (rtDW.clutchCurrVal <=
             80)) {
          if (rtDW.is_UP_REBOUND != IN_SettingNeutral) {
            rtDW.is_UP_REBOUND = IN_SettingNeutral;
            Clutch_setValue(0);

            /* Outputs for Function Call SubSystem: '<S49>/Gearmotor_release' */
            Gearmotor_release();

            /* End of Outputs for SubSystem: '<S49>/Gearmotor_release' */
          }
        } else {
          if (rtDW.is_UP_REBOUND != IN_Default) {
            rtDW.is_UP_REBOUND = IN_Default;

            /* Outputs for Function Call SubSystem: '<S49>/Gearmotor_release' */
            Gearmotor_release();

            /* End of Outputs for SubSystem: '<S49>/Gearmotor_release' */
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

          /* Outputs for Function Call SubSystem: '<S49>/Gearmotor_brake' */
          Gearmotor_brake(&Pin_In1, &Pin_In2, &rtDW.Pin_H,
                          &rtDW.Gearmotor_brake_c);

          /* End of Outputs for SubSystem: '<S49>/Gearmotor_brake' */
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

            /* Outputs for Function Call SubSystem: '<S45>/UnsetCut' */
            UnsetCut();

            /* End of Outputs for SubSystem: '<S45>/UnsetCut' */

            /* Outputs for Function Call SubSystem: '<S49>/Gearmotor_turnRight' */
            Gearmotor_turnRight(&Pin_In1, &Pin_In2, &rtDW.Pin_H,
                                &rtDW.Gearmotor_turnRight_f);

            /* End of Outputs for SubSystem: '<S49>/Gearmotor_turnRight' */
          }
        } else {
          if (rtDW.is_UP_PUSH != IN_Default_b) {
            rtDW.is_UP_PUSH = IN_Default_b;

            /* Outputs for Function Call SubSystem: '<S49>/Gearmotor_turnRight' */
            Gearmotor_turnRight(&Pin_In1, &Pin_In2, &rtDW.Pin_H,
                                &rtDW.Gearmotor_turnRight_f);

            /* End of Outputs for SubSystem: '<S49>/Gearmotor_turnRight' */
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
  return rtDW.UnitDelay[b_index];
}

/* Function for Chart: '<S5>/GCULogic' */
static void aacCheckShift(void)
{
  int32_T b_previousEvent;
  if ((rtDW.lastShift == rtDW.RateTransition36[6]) && (rtDW.RateTransition36[0] >=
       rtDW.UnitDelay[((int32_T)RPM_LIMIT_1_2 + rtDW.RateTransition36[6]) - 1]) &&
      (rtDW.RateTransition36[1] >= rtDW.UnitDelay[((int32_T)SPEED_LIMIT_1_2 +
        rtDW.RateTransition36[6]) - 1])) {
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
  if ((rtDW.Cast1_k != rtDW.clutchCurrVal) && (rtDW.UnitDelay_b == ANTISTALL_OFF)
      && (((!(rtDW.is_GEARSHIFT == IN_DOWNSHIFTING)) && (!(rtDW.is_NEUTRAL_STATE
          == IN_SET_NEUTRAL))) || (rtDW.is_NEUTRAL_STATE == IN_UNSET_NEUTRAL)))
  {
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
  int32_T q0;
  int32_T q1;
  int64_T tmp;
  uint16_T tmp_0;
  uint8_T tmp_1;
  if ((rtDW.RateTransition8[0] != rtDW.lastModeCom[0]) && (rtDW.RateTransition8
       [1] != rtDW.lastModeCom[1])) {
    /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
    UnsetRPMLimiter();

    /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
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

      rtDW.is_MANUAL_MODES = IN_ENDURANCE;
    } else if (rtDW.RateTransition8[1] == SKIDPAD_MODE) {
      rtDW.is_ACTIVE = 0;
      rtDW.is_ACC = 0;
      rtDW.is_ACCELERATION = 0;
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        enter_atomic_MANUAL_MODES();
      }

      if (rtDW.is_MANUAL_MODES != IN_SKIDPAD) {
        rtDW.is_MANUAL_MODES = IN_SKIDPAD;

        /* Outputs for Function Call SubSystem: '<S45>/SetRPMLimiter' */
        SetRPMLimiter();

        /* End of Outputs for SubSystem: '<S45>/SetRPMLimiter' */
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
      if (rtDW.is_MODES != IN_ACCELERATION_PID) {
        rtDW.is_MODES = IN_ACCELERATION_PID;
        rtDW.lastAutoXCom = rtDW.RateTransition29[0];
        rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
        rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
      }

      if (rtDW.is_ACCELERATION_PID != IN_DEFAULT_j) {
        rtDW.is_ACCELERATION_PID = IN_DEFAULT_j;
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

      rtDW.is_MANUAL_MODES = IN_ENDURANCE;
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

            /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
            UnsetRPMLimiter();

            /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
            Clutch_setValue(0);

            /* sendUpdatesSW(ACC_CODE, uint16(0)); */
          }
        } else {
          switch (rtDW.is_ACTIVE) {
           case IN_READY:
            if (rtDW.aacCounter <= 1) {
              if ((rtDW.RateTransition4[0] != rtDW.lastAacCom) &&
                  (rtDW.RateTransition4[1] == ACC_GO) && (rtDW.RateTransition36
                   [2] >= getAacParam(TPS_START_LIMIT))) {
                rtDW.lastAacCom = rtDW.RateTransition4[0];
                rtDW.is_ACTIVE = 0;
                if (rtDW.is_ACTIVE != IN_START_RELEASE) {
                  rtDW.is_ACTIVE = IN_START_RELEASE;
                  rtDW.stateFb = (uint16_T)ACC_GO;
                  rtDW.aac_clutchValue = getAacParam(RAMP_START);
                  if (rtDW.aac_clutchValue < 256.0) {
                    if (rtDW.aac_clutchValue >= 0.0) {
                      tmp_1 = (uint8_T)rtDW.aac_clutchValue;
                    } else {
                      tmp_1 = 0U;
                    }
                  } else {
                    tmp_1 = MAX_uint8_T;
                  }

                  Clutch_setValue(tmp_1);
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

                /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
                UnsetRPMLimiter();

                /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
                rtDW.is_ACTIVE = 0;
                if (rtDW.is_ACTIVE != IN_RUNNING) {
                  rtDW.is_ACTIVE = IN_RUNNING;
                  rtDW.aacCounter = AAC_WORK_RATE_ms;
                  tmp_0 = rtDW.RateTransition36[6];
                  if (rtDW.RateTransition36[6] > 255) {
                    tmp_0 = 255U;
                  }

                  rtDW.lastShift = (uint8_T)tmp_0;
                  aacCheckShift();
                }
              } else {
                rtDW.is_ACTIVE = 0;
                if (rtDW.is_ACTIVE != IN_RELEASING) {
                  rtDW.is_ACTIVE = IN_RELEASING;
                  rtDW.aac_clutchValue -= rtDW.aac_clutchStep;
                  if (rtDW.aac_clutchValue < 256.0) {
                    if (rtDW.aac_clutchValue >= 0.0) {
                      tmp_1 = (uint8_T)rtDW.aac_clutchValue;
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
              q0 = rtDW.aacCounter - 1;
              if (q0 < 0) {
                q0 = 0;
              }

              rtDW.aacCounter = (uint16_T)q0;
            }
            break;

           case IN_RUNNING:
            if ((rtDW.RateTransition36[6] >= rtDW.UnitDelay[(uint8_T)END_GEAR]) &&
                (rtDW.RateTransition36[6] != 8)) {
              rtDW.is_ACTIVE = 0;
              rtDW.is_ACC = 0;
              if (rtDW.is_ACC != IN_STOPPING) {
                rtDW.is_ACC = IN_STOPPING;

                /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
                UnsetRPMLimiter();

                /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
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
                    tmp_1 = (uint8_T)rtDW.aac_clutchValue;
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

          /* Outputs for Function Call SubSystem: '<S45>/SetRPMLimiter' */
          SetRPMLimiter();

          /* End of Outputs for SubSystem: '<S45>/SetRPMLimiter' */
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
static void DEFAULT(void)
{
  if ((rtDW.RateTransition29[0] != rtDW.lastAutoXCom) && (rtDW.RateTransition29
       [1] == AUTOX_READY)) {
    rtDW.lastAutoXCom = rtDW.RateTransition29[0];
    switch (rtDW.RateTransition1_b) {
     case 0:
      rtDW.is_ACCELERATION_PID = IN_LAUNCH0;
      rtDW.autoXCounter_n = 0U;
      if (rtDW.is_LAUNCH0 != IN_ACTIVE) {
        rtDW.is_LAUNCH0 = IN_ACTIVE;

        /* Enable for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH0.ACTIVE.ramp' */
        MODESACCELERATION_PI_Enable(&rtDW.MODESACCELERATION_PIDLAUNCH0ACT);

        /* End of Enable for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH0.ACTIVE.ramp' */
      }

      if (rtDW.is_ACTIVE_d != IN_START) {
        rtDW.is_ACTIVE_d = IN_START;
        rtDW.stateFb = (uint16_T)AUTOX_READY;
        rtDW.autoXCounter_n = AUTOX_WORK_RATE_ms;

        /* Outputs for Function Call SubSystem: '<S45>/SetRPMLimiter' */
        SetRPMLimiter();

        /* End of Outputs for SubSystem: '<S45>/SetRPMLimiter' */
        Clutch_setValue(100);
      }
      break;

     case 1:
      rtDW.is_ACCELERATION_PID = IN_LAUNCH1;
      rtDW.autoXCounter_o = 0U;
      if (rtDW.is_LAUNCH1 != IN_ACTIVE) {
        rtDW.is_LAUNCH1 = IN_ACTIVE;

        /* Enable for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH1.ACTIVE.ramp' */
        MODESACCELERATION__c_Enable(&rtDW.MODESACCELERATION_PIDLAUNCH1ACT);

        /* End of Enable for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH1.ACTIVE.ramp' */
      }

      if (rtDW.is_ACTIVE_k != IN_START) {
        rtDW.is_ACTIVE_k = IN_START;
        rtDW.stateFb = (uint16_T)AUTOX_READY;
        rtDW.autoXCounter_o = AUTOX_WORK_RATE_ms;

        /* Outputs for Function Call SubSystem: '<S45>/SetRPMLimiter' */
        SetRPMLimiter();

        /* End of Outputs for SubSystem: '<S45>/SetRPMLimiter' */
        Clutch_setValue(100);
      }
      break;

     case 2:
      rtDW.is_ACCELERATION_PID = IN_LAUNCH2;
      rtDW.autoXCounter_j = 0U;
      if (rtDW.is_LAUNCH2 != IN_ACTIVE) {
        rtDW.is_LAUNCH2 = IN_ACTIVE;

        /* Enable for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH2.ACTIVE.ramp' */
        MODESACCELERATION__k_Enable(&rtDW.MODESACCELERATION_PIDLAUNCH2ACT);

        /* End of Enable for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH2.ACTIVE.ramp' */
      }

      if (rtDW.is_ACTIVE_e != IN_START) {
        rtDW.is_ACTIVE_e = IN_START;
        rtDW.stateFb = (uint16_T)AUTOX_READY;
        rtDW.autoXCounter_j = AUTOX_WORK_RATE_ms;

        /* Outputs for Function Call SubSystem: '<S45>/SetRPMLimiter' */
        SetRPMLimiter();

        /* End of Outputs for SubSystem: '<S45>/SetRPMLimiter' */
        Clutch_setValue(100);
      }
      break;

     case 3:
      rtDW.is_ACCELERATION_PID = IN_LAUNCH3;
      rtDW.autoXCounter_b = 0U;
      if (rtDW.is_LAUNCH3 != IN_ACTIVE) {
        rtDW.is_LAUNCH3 = IN_ACTIVE;

        /* Enable for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH3.ACTIVE.ramp' */
        MODESACCELERATION__k_Enable(&rtDW.MODESACCELERATION_PIDLAUNCH3ACT);

        /* End of Enable for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH3.ACTIVE.ramp' */
      }

      if (rtDW.is_ACTIVE_c != IN_START) {
        rtDW.is_ACTIVE_c = IN_START;
        rtDW.stateFb = (uint16_T)AUTOX_READY;
        rtDW.autoXCounter_b = AUTOX_WORK_RATE_ms;

        /* Outputs for Function Call SubSystem: '<S45>/SetRPMLimiter' */
        SetRPMLimiter();

        /* End of Outputs for SubSystem: '<S45>/SetRPMLimiter' */
        Clutch_setValue(100);
      }
      break;

     case 4:
      rtDW.is_ACCELERATION_PID = IN_LAUNCH4;
      rtDW.autoXCounter_l = 0U;
      if (rtDW.is_LAUNCH4 != IN_ACTIVE) {
        rtDW.is_LAUNCH4 = IN_ACTIVE;

        /* Enable for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH4.ACTIVE.ramp' */
        MODESACCELERATION__i_Enable(&rtDW.MODESACCELERATION_PIDLAUNCH4ACT);

        /* End of Enable for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH4.ACTIVE.ramp' */
      }

      if (rtDW.is_ACTIVE_cg != IN_START) {
        rtDW.is_ACTIVE_cg = IN_START;
        rtDW.stateFb = (uint16_T)AUTOX_READY;
        rtDW.autoXCounter_l = AUTOX_WORK_RATE_ms;

        /* Outputs for Function Call SubSystem: '<S45>/SetRPMLimiter' */
        SetRPMLimiter();

        /* End of Outputs for SubSystem: '<S45>/SetRPMLimiter' */
        Clutch_setValue(100);
      }
      break;

     case 5:
      rtDW.is_ACCELERATION_PID = IN_LAUNCH5;
      rtDW.autoXCounter_n2 = 0U;
      if (rtDW.is_LAUNCH5 != IN_ACTIVE) {
        rtDW.is_LAUNCH5 = IN_ACTIVE;

        /* Enable for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH5.ACTIVE.ramp' */
        MODESACCELERATION__i_Enable(&rtDW.MODESACCELERATION_PIDLAUNCH5ACT);

        /* End of Enable for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH5.ACTIVE.ramp' */
      }

      if (rtDW.is_ACTIVE_f != IN_START) {
        rtDW.is_ACTIVE_f = IN_START;
        rtDW.stateFb = (uint16_T)AUTOX_READY;
        rtDW.autoXCounter_n2 = AUTOX_WORK_RATE_ms;

        /* Outputs for Function Call SubSystem: '<S45>/SetRPMLimiter' */
        SetRPMLimiter();

        /* End of Outputs for SubSystem: '<S45>/SetRPMLimiter' */
        Clutch_setValue(100);
      }
      break;

     case 6:
      rtDW.is_ACCELERATION_PID = IN_LAUNCH6;
      rtDW.autoXCounter_e = 0U;
      if (rtDW.is_LAUNCH6 != IN_ACTIVE) {
        rtDW.is_LAUNCH6 = IN_ACTIVE;

        /* Enable for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH6.ACTIVE.pidControl' */
        MODESACCELERATION__j_Enable(&rtDW.MODESACCELERATION_PIDLAUNCH6ACT);

        /* End of Enable for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH6.ACTIVE.pidControl' */
      }

      if (rtDW.is_ACTIVE_a != IN_START) {
        rtDW.is_ACTIVE_a = IN_START;
        rtDW.stateFb = (uint16_T)AUTOX_READY;
        rtDW.autoXCounter_e = AUTOX_WORK_RATE_ms;

        /* Outputs for Function Call SubSystem: '<S45>/SetRPMLimiter' */
        SetRPMLimiter();

        /* End of Outputs for SubSystem: '<S45>/SetRPMLimiter' */
        Clutch_setValue(100);
      }
      break;

     case 7:
      rtDW.is_ACCELERATION_PID = IN_LAUNCH7;
      rtDW.autoXCounter_p = 0U;
      if (rtDW.is_LAUNCH7 != IN_ACTIVE) {
        rtDW.is_LAUNCH7 = IN_ACTIVE;

        /* Enable for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH7.ACTIVE.pidControl' */
        MODESACCELERATION__j_Enable(&rtDW.MODESACCELERATION_PIDLAUNCH7ACT);

        /* End of Enable for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH7.ACTIVE.pidControl' */
      }

      if (rtDW.is_ACTIVE_l != IN_START) {
        rtDW.is_ACTIVE_l = IN_START;
        rtDW.stateFb = (uint16_T)AUTOX_READY;
        rtDW.autoXCounter_p = AUTOX_WORK_RATE_ms;

        /* Outputs for Function Call SubSystem: '<S45>/SetRPMLimiter' */
        SetRPMLimiter();

        /* End of Outputs for SubSystem: '<S45>/SetRPMLimiter' */
        Clutch_setValue(100);
      }
      break;

     case 8:
      rtDW.is_ACCELERATION_PID = IN_LAUNCH8;
      rtDW.autoXCounter_o3 = 0U;
      if (rtDW.is_LAUNCH8 != IN_ACTIVE) {
        rtDW.is_LAUNCH8 = IN_ACTIVE;

        /* Enable for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH8.ACTIVE.pidControl' */
        MODESACCELERATION__e_Enable(&rtDW.MODESACCELERATION_PIDLAUNCH8ACT);

        /* End of Enable for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH8.ACTIVE.pidControl' */
      }

      if (rtDW.is_ACTIVE_ky != IN_START) {
        rtDW.is_ACTIVE_ky = IN_START;
        rtDW.stateFb = (uint16_T)AUTOX_READY;
        rtDW.autoXCounter_o3 = AUTOX_WORK_RATE_ms;

        /* Outputs for Function Call SubSystem: '<S45>/SetRPMLimiter' */
        SetRPMLimiter();

        /* End of Outputs for SubSystem: '<S45>/SetRPMLimiter' */
        Clutch_setValue(100);
      }
      break;

     default:
      rtDW.is_ACCELERATION_PID = IN_LAUNCH9;
      rtDW.autoXCounter_m = 0U;
      if (rtDW.is_LAUNCH9 != IN_ACTIVE) {
        rtDW.is_LAUNCH9 = IN_ACTIVE;

        /* Enable for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH9.ACTIVE.pidControl' */
        MODESACCELERATION__e_Enable(&rtDW.MODESACCELERATION_PIDLAUNCH9ACT);

        /* End of Enable for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH9.ACTIVE.pidControl' */
      }

      if (rtDW.is_ACTIVE_h != IN_START) {
        rtDW.is_ACTIVE_h = IN_START;
        rtDW.stateFb = (uint16_T)AUTOX_READY;
        rtDW.autoXCounter_m = AUTOX_WORK_RATE_ms;

        /* Outputs for Function Call SubSystem: '<S45>/SetRPMLimiter' */
        SetRPMLimiter();

        /* End of Outputs for SubSystem: '<S45>/SetRPMLimiter' */
        Clutch_setValue(100);
      }
      break;
    }
  } else {
    rtDW.stateFb = (uint16_T)AUTOX_DEFAULT;
    checkShift();
    checkClutch();
  }
}

/* Function for Chart: '<S5>/GCULogic' */
static int32_T getAutoXParam(autoX_params b_index)
{
  return rtDW.UnitDelay2[b_index];
}

/* Function for Chart: '<S5>/GCULogic' */
static void autoXCheckShift(void)
{
  int32_T b_previousEvent;
  if ((rtDW.lastShift == rtDW.RateTransition36[6]) && (rtDW.RateTransition36[0] >=
       rtDW.UnitDelay2[((int32_T)AUTOX_RPM_LIMIT_1_2 + rtDW.RateTransition36[6])
       - 1]) && (rtDW.RateTransition36[1] >= rtDW.UnitDelay2[((int32_T)
        AUTOX_SPEED_LIMIT_1_2 + rtDW.RateTransition36[6]) - 1])) {
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
static void LAUNCH2(void)
{
  real_T Saturation4_m;
  int32_T tmp;
  uint16_T tmp_0;
  switch (rtDW.is_LAUNCH2) {
   case IN_ACTIVE:
    if ((rtDW.RateTransition29[0] != rtDW.lastAutoXCom) &&
        (rtDW.RateTransition29[1] == AUTOX_DEFAULT)) {
      rtDW.lastAutoXCom = rtDW.RateTransition29[0];
      rtDW.is_ACTIVE_e = 0;
      if (rtDW.is_LAUNCH2 == IN_ACTIVE) {
        rtDW.is_LAUNCH2 = 0;
      }

      if (rtDW.is_LAUNCH2 != IN_STOPPING) {
        rtDW.is_LAUNCH2 = IN_STOPPING;

        /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
        UnsetRPMLimiter();

        /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
        Clutch_setValue(0);
      }
    } else {
      switch (rtDW.is_ACTIVE_e) {
       case IN_READY:
        if (rtDW.autoXCounter_j <= 1) {
          if ((rtDW.RateTransition29[0] != rtDW.lastAutoXCom) &&
              (rtDW.RateTransition29[1] == AUTOX_GO) && (rtDW.RateTransition36[2]
               >= getAutoXParam(AUTOX_TPS_START_LIMIT))) {
            rtDW.lastAutoXCom = rtDW.RateTransition29[0];
            rtDW.stateFb = (uint16_T)AUTOX_GO;
            rtDW.is_ACTIVE_e = 0;
            if (rtDW.is_ACTIVE_e != IN_RELEASE) {
              rtDW.is_ACTIVE_e = IN_RELEASE;

              /* Outputs for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH2.ACTIVE.ramp' */
              MODESACCELERATION_PIDLAUN_g(rtM, (real_T)rtDW.RateTransition36[3],
                (real_T)rtDW.RateTransition36[4], &Saturation4_m,
                &rtDW.MODESACCELERATION_PIDLAUNCH2ACT);

              /* End of Outputs for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH2.ACTIVE.ramp' */
              if (Saturation4_m < 256.0) {
                if (Saturation4_m >= 0.0) {
                  rtDW.clutchCurrVal = (uint8_T)Saturation4_m;
                } else {
                  rtDW.clutchCurrVal = 0U;
                }
              } else {
                rtDW.clutchCurrVal = MAX_uint8_T;
              }
            }
          } else {
            rtDW.is_ACTIVE_e = 0;
            if (rtDW.is_ACTIVE_e != IN_READY) {
              rtDW.is_ACTIVE_e = IN_READY;
              rtDW.stateFb = (uint16_T)AUTOX_READY;
              rtDW.autoXCounter_j = AUTOX_WORK_RATE_ms;
              Clutch_setValue(55);
              checkShift();
            }
          }
        } else {
          tmp = rtDW.autoXCounter_j - 1;
          if (tmp < 0) {
            tmp = 0;
          }

          rtDW.autoXCounter_j = (uint16_T)tmp;
          checkShift();
        }
        break;

       case IN_RELEASE:
        if (rtDW.RateTransition36[1] >= RELEASE_END_SPEED) {
          Clutch_setValue(0);

          /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
          UnsetRPMLimiter();

          /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
          rtDW.is_ACTIVE_e = 0;
          if (rtDW.is_ACTIVE_e != IN_RUNNING) {
            rtDW.is_ACTIVE_e = IN_RUNNING;
            rtDW.autoXCounter_j = AUTOX_WORK_RATE_ms;
            tmp_0 = rtDW.RateTransition36[6];
            if (rtDW.RateTransition36[6] > 255) {
              tmp_0 = 255U;
            }

            rtDW.lastShift = (uint8_T)tmp_0;
            autoXCheckShift();
          }
        } else {
          /* Outputs for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH2.ACTIVE.ramp' */
          MODESACCELERATION_PIDLAUN_g(rtM, (real_T)rtDW.RateTransition36[3],
            (real_T)rtDW.RateTransition36[4], &Saturation4_m,
            &rtDW.MODESACCELERATION_PIDLAUNCH2ACT);

          /* End of Outputs for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH2.ACTIVE.ramp' */
          if (Saturation4_m < 256.0) {
            if (Saturation4_m >= 0.0) {
              rtDW.clutchCurrVal = (uint8_T)Saturation4_m;
            } else {
              rtDW.clutchCurrVal = 0U;
            }
          } else {
            rtDW.clutchCurrVal = MAX_uint8_T;
          }
        }
        break;

       case IN_RUNNING:
        if ((rtDW.RateTransition36[6] >= 5) && (rtDW.RateTransition36[6] != 8))
        {
          rtDW.is_ACTIVE_e = 0;
          if (rtDW.is_LAUNCH2 == IN_ACTIVE) {
            rtDW.is_LAUNCH2 = 0;
          }

          if (rtDW.is_LAUNCH2 != IN_STOPPING) {
            rtDW.is_LAUNCH2 = IN_STOPPING;

            /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
            UnsetRPMLimiter();

            /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
            Clutch_setValue(0);
          }
        } else {
          autoXCheckShift();
        }
        break;

       case IN_START:
        if (rtDW.autoXCounter_j <= 1) {
          rtDW.is_ACTIVE_e = 0;
          if (rtDW.is_ACTIVE_e != IN_READY) {
            rtDW.is_ACTIVE_e = IN_READY;
            rtDW.stateFb = (uint16_T)AUTOX_READY;
            rtDW.autoXCounter_j = AUTOX_WORK_RATE_ms;
            Clutch_setValue(55);
            checkShift();
          }
        } else {
          tmp = rtDW.autoXCounter_j - 1;
          if (tmp < 0) {
            tmp = 0;
          }

          rtDW.autoXCounter_j = (uint16_T)tmp;
        }
        break;
      }
    }
    break;

   case IN_STOPPING:
    rtDW.is_LAUNCH2 = 0;
    rtDW.is_ACCELERATION_PID = 0;
    if (rtDW.is_ACCELERATION_PID != IN_DEFAULT_j) {
      rtDW.is_ACCELERATION_PID = IN_DEFAULT_j;
      rtDW.stateFb = (uint16_T)AUTOX_DEFAULT;
      checkShift();
      checkClutch();
    }
    break;
  }
}

/* Function for Chart: '<S5>/GCULogic' */
static void LAUNCH3(void)
{
  real_T Saturation4_f;
  int32_T tmp;
  uint16_T tmp_0;
  switch (rtDW.is_LAUNCH3) {
   case IN_ACTIVE:
    if ((rtDW.RateTransition29[0] != rtDW.lastAutoXCom) &&
        (rtDW.RateTransition29[1] == AUTOX_DEFAULT)) {
      rtDW.lastAutoXCom = rtDW.RateTransition29[0];
      rtDW.is_ACTIVE_c = 0;
      if (rtDW.is_LAUNCH3 == IN_ACTIVE) {
        rtDW.is_LAUNCH3 = 0;
      }

      if (rtDW.is_LAUNCH3 != IN_STOPPING) {
        rtDW.is_LAUNCH3 = IN_STOPPING;

        /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
        UnsetRPMLimiter();

        /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
        Clutch_setValue(0);
      }
    } else {
      switch (rtDW.is_ACTIVE_c) {
       case IN_READY:
        if (rtDW.autoXCounter_b <= 1) {
          if ((rtDW.RateTransition29[0] != rtDW.lastAutoXCom) &&
              (rtDW.RateTransition29[1] == AUTOX_GO) && (rtDW.RateTransition36[2]
               >= getAutoXParam(AUTOX_TPS_START_LIMIT))) {
            rtDW.lastAutoXCom = rtDW.RateTransition29[0];
            rtDW.stateFb = (uint16_T)AUTOX_GO;
            rtDW.is_ACTIVE_c = 0;
            if (rtDW.is_ACTIVE_c != IN_RELEASE) {
              rtDW.is_ACTIVE_c = IN_RELEASE;

              /* Outputs for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH3.ACTIVE.ramp' */
              MODESACCELERATION_PIDLAUN_g(rtM, (real_T)rtDW.RateTransition36[3],
                (real_T)rtDW.RateTransition36[4], &Saturation4_f,
                &rtDW.MODESACCELERATION_PIDLAUNCH3ACT);

              /* End of Outputs for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH3.ACTIVE.ramp' */
              if (Saturation4_f < 256.0) {
                if (Saturation4_f >= 0.0) {
                  rtDW.clutchCurrVal = (uint8_T)Saturation4_f;
                } else {
                  rtDW.clutchCurrVal = 0U;
                }
              } else {
                rtDW.clutchCurrVal = MAX_uint8_T;
              }
            }
          } else {
            rtDW.is_ACTIVE_c = 0;
            if (rtDW.is_ACTIVE_c != IN_READY) {
              rtDW.is_ACTIVE_c = IN_READY;
              rtDW.stateFb = (uint16_T)AUTOX_READY;
              rtDW.autoXCounter_b = AUTOX_WORK_RATE_ms;
              Clutch_setValue(55);
              checkShift();
            }
          }
        } else {
          tmp = rtDW.autoXCounter_b - 1;
          if (tmp < 0) {
            tmp = 0;
          }

          rtDW.autoXCounter_b = (uint16_T)tmp;
          checkShift();
        }
        break;

       case IN_RELEASE:
        if (rtDW.RateTransition36[1] >= 15) {
          Clutch_setValue(0);

          /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
          UnsetRPMLimiter();

          /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
          rtDW.is_ACTIVE_c = 0;
          if (rtDW.is_ACTIVE_c != IN_RUNNING) {
            rtDW.is_ACTIVE_c = IN_RUNNING;
            rtDW.autoXCounter_b = AUTOX_WORK_RATE_ms;
            tmp_0 = rtDW.RateTransition36[6];
            if (rtDW.RateTransition36[6] > 255) {
              tmp_0 = 255U;
            }

            rtDW.lastShift = (uint8_T)tmp_0;
            autoXCheckShift();
          }
        } else {
          /* Outputs for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH3.ACTIVE.ramp' */
          MODESACCELERATION_PIDLAUN_g(rtM, (real_T)rtDW.RateTransition36[3],
            (real_T)rtDW.RateTransition36[4], &Saturation4_f,
            &rtDW.MODESACCELERATION_PIDLAUNCH3ACT);

          /* End of Outputs for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH3.ACTIVE.ramp' */
          if (Saturation4_f < 256.0) {
            if (Saturation4_f >= 0.0) {
              rtDW.clutchCurrVal = (uint8_T)Saturation4_f;
            } else {
              rtDW.clutchCurrVal = 0U;
            }
          } else {
            rtDW.clutchCurrVal = MAX_uint8_T;
          }
        }
        break;

       case IN_RUNNING:
        if ((rtDW.RateTransition36[6] >= 5) && (rtDW.RateTransition36[6] != 8))
        {
          rtDW.is_ACTIVE_c = 0;
          if (rtDW.is_LAUNCH3 == IN_ACTIVE) {
            rtDW.is_LAUNCH3 = 0;
          }

          if (rtDW.is_LAUNCH3 != IN_STOPPING) {
            rtDW.is_LAUNCH3 = IN_STOPPING;

            /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
            UnsetRPMLimiter();

            /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
            Clutch_setValue(0);
          }
        } else {
          autoXCheckShift();
        }
        break;

       case IN_START:
        if (rtDW.autoXCounter_b <= 1) {
          rtDW.is_ACTIVE_c = 0;
          if (rtDW.is_ACTIVE_c != IN_READY) {
            rtDW.is_ACTIVE_c = IN_READY;
            rtDW.stateFb = (uint16_T)AUTOX_READY;
            rtDW.autoXCounter_b = AUTOX_WORK_RATE_ms;
            Clutch_setValue(55);
            checkShift();
          }
        } else {
          tmp = rtDW.autoXCounter_b - 1;
          if (tmp < 0) {
            tmp = 0;
          }

          rtDW.autoXCounter_b = (uint16_T)tmp;
        }
        break;
      }
    }
    break;

   case IN_STOPPING:
    rtDW.is_LAUNCH3 = 0;
    rtDW.is_ACCELERATION_PID = 0;
    if (rtDW.is_ACCELERATION_PID != IN_DEFAULT_j) {
      rtDW.is_ACCELERATION_PID = IN_DEFAULT_j;
      rtDW.stateFb = (uint16_T)AUTOX_DEFAULT;
      checkShift();
      checkClutch();
    }
    break;
  }
}

/* Function for Chart: '<S5>/GCULogic' */
static void LAUNCH4(void)
{
  real_T Saturation4_k;
  int32_T tmp;
  uint16_T tmp_0;
  switch (rtDW.is_LAUNCH4) {
   case IN_ACTIVE:
    if ((rtDW.RateTransition29[0] != rtDW.lastAutoXCom) &&
        (rtDW.RateTransition29[1] == AUTOX_DEFAULT)) {
      rtDW.lastAutoXCom = rtDW.RateTransition29[0];
      rtDW.is_ACTIVE_cg = 0;
      if (rtDW.is_LAUNCH4 == IN_ACTIVE) {
        rtDW.is_LAUNCH4 = 0;
      }

      if (rtDW.is_LAUNCH4 != IN_STOPPING) {
        rtDW.is_LAUNCH4 = IN_STOPPING;

        /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
        UnsetRPMLimiter();

        /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
        Clutch_setValue(0);
      }
    } else {
      switch (rtDW.is_ACTIVE_cg) {
       case IN_READY:
        if (rtDW.autoXCounter_l <= 1) {
          if ((rtDW.RateTransition29[0] != rtDW.lastAutoXCom) &&
              (rtDW.RateTransition29[1] == AUTOX_GO) && (rtDW.RateTransition36[2]
               >= getAutoXParam(AUTOX_TPS_START_LIMIT))) {
            rtDW.lastAutoXCom = rtDW.RateTransition29[0];
            rtDW.stateFb = (uint16_T)AUTOX_GO;
            rtDW.is_ACTIVE_cg = 0;
            if (rtDW.is_ACTIVE_cg != IN_RELEASE) {
              rtDW.is_ACTIVE_cg = IN_RELEASE;

              /* Outputs for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH4.ACTIVE.ramp' */
              MODESACCELERATION_PIDLAUN_n(rtM, (real_T)rtDW.RateTransition36[3],
                (real_T)rtDW.RateTransition36[4], &Saturation4_k,
                &rtDW.MODESACCELERATION_PIDLAUNCH4ACT);

              /* End of Outputs for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH4.ACTIVE.ramp' */
              if (Saturation4_k < 256.0) {
                if (Saturation4_k >= 0.0) {
                  rtDW.clutchCurrVal = (uint8_T)Saturation4_k;
                } else {
                  rtDW.clutchCurrVal = 0U;
                }
              } else {
                rtDW.clutchCurrVal = MAX_uint8_T;
              }
            }
          } else {
            rtDW.is_ACTIVE_cg = 0;
            if (rtDW.is_ACTIVE_cg != IN_READY) {
              rtDW.is_ACTIVE_cg = IN_READY;
              rtDW.stateFb = (uint16_T)AUTOX_READY;
              rtDW.autoXCounter_l = AUTOX_WORK_RATE_ms;
              Clutch_setValue(55);
              checkShift();
            }
          }
        } else {
          tmp = rtDW.autoXCounter_l - 1;
          if (tmp < 0) {
            tmp = 0;
          }

          rtDW.autoXCounter_l = (uint16_T)tmp;
          checkShift();
        }
        break;

       case IN_RELEASE:
        if (rtDW.RateTransition36[1] >= RELEASE_END_SPEED) {
          Clutch_setValue(0);

          /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
          UnsetRPMLimiter();

          /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
          rtDW.is_ACTIVE_cg = 0;
          if (rtDW.is_ACTIVE_cg != IN_RUNNING) {
            rtDW.is_ACTIVE_cg = IN_RUNNING;
            rtDW.autoXCounter_l = AUTOX_WORK_RATE_ms;
            tmp_0 = rtDW.RateTransition36[6];
            if (rtDW.RateTransition36[6] > 255) {
              tmp_0 = 255U;
            }

            rtDW.lastShift = (uint8_T)tmp_0;
            autoXCheckShift();
          }
        } else {
          /* Outputs for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH4.ACTIVE.ramp' */
          MODESACCELERATION_PIDLAUN_n(rtM, (real_T)rtDW.RateTransition36[3],
            (real_T)rtDW.RateTransition36[4], &Saturation4_k,
            &rtDW.MODESACCELERATION_PIDLAUNCH4ACT);

          /* End of Outputs for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH4.ACTIVE.ramp' */
          if (Saturation4_k < 256.0) {
            if (Saturation4_k >= 0.0) {
              rtDW.clutchCurrVal = (uint8_T)Saturation4_k;
            } else {
              rtDW.clutchCurrVal = 0U;
            }
          } else {
            rtDW.clutchCurrVal = MAX_uint8_T;
          }
        }
        break;

       case IN_RUNNING:
        if ((rtDW.RateTransition36[6] >= 5) && (rtDW.RateTransition36[6] != 8))
        {
          rtDW.is_ACTIVE_cg = 0;
          if (rtDW.is_LAUNCH4 == IN_ACTIVE) {
            rtDW.is_LAUNCH4 = 0;
          }

          if (rtDW.is_LAUNCH4 != IN_STOPPING) {
            rtDW.is_LAUNCH4 = IN_STOPPING;

            /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
            UnsetRPMLimiter();

            /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
            Clutch_setValue(0);
          }
        } else {
          autoXCheckShift();
        }
        break;

       case IN_START:
        if (rtDW.autoXCounter_l <= 1) {
          rtDW.is_ACTIVE_cg = 0;
          if (rtDW.is_ACTIVE_cg != IN_READY) {
            rtDW.is_ACTIVE_cg = IN_READY;
            rtDW.stateFb = (uint16_T)AUTOX_READY;
            rtDW.autoXCounter_l = AUTOX_WORK_RATE_ms;
            Clutch_setValue(55);
            checkShift();
          }
        } else {
          tmp = rtDW.autoXCounter_l - 1;
          if (tmp < 0) {
            tmp = 0;
          }

          rtDW.autoXCounter_l = (uint16_T)tmp;
        }
        break;
      }
    }
    break;

   case IN_STOPPING:
    rtDW.is_LAUNCH4 = 0;
    rtDW.is_ACCELERATION_PID = 0;
    if (rtDW.is_ACCELERATION_PID != IN_DEFAULT_j) {
      rtDW.is_ACCELERATION_PID = IN_DEFAULT_j;
      rtDW.stateFb = (uint16_T)AUTOX_DEFAULT;
      checkShift();
      checkClutch();
    }
    break;
  }
}

/* Function for Chart: '<S5>/GCULogic' */
static void LAUNCH5(void)
{
  real_T Saturation4;
  int32_T tmp;
  uint16_T tmp_0;
  switch (rtDW.is_LAUNCH5) {
   case IN_ACTIVE:
    if ((rtDW.RateTransition29[0] != rtDW.lastAutoXCom) &&
        (rtDW.RateTransition29[1] == AUTOX_DEFAULT)) {
      rtDW.lastAutoXCom = rtDW.RateTransition29[0];
      rtDW.is_ACTIVE_f = 0;
      if (rtDW.is_LAUNCH5 == IN_ACTIVE) {
        rtDW.is_LAUNCH5 = 0;
      }

      if (rtDW.is_LAUNCH5 != IN_STOPPING) {
        rtDW.is_LAUNCH5 = IN_STOPPING;

        /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
        UnsetRPMLimiter();

        /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
        Clutch_setValue(0);
      }
    } else {
      switch (rtDW.is_ACTIVE_f) {
       case IN_READY:
        if (rtDW.autoXCounter_n2 <= 1) {
          if ((rtDW.RateTransition29[0] != rtDW.lastAutoXCom) &&
              (rtDW.RateTransition29[1] == AUTOX_GO) && (rtDW.RateTransition36[2]
               >= getAutoXParam(AUTOX_TPS_START_LIMIT))) {
            rtDW.lastAutoXCom = rtDW.RateTransition29[0];
            rtDW.stateFb = (uint16_T)AUTOX_GO;
            rtDW.is_ACTIVE_f = 0;
            if (rtDW.is_ACTIVE_f != IN_RELEASE) {
              rtDW.is_ACTIVE_f = IN_RELEASE;

              /* Outputs for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH5.ACTIVE.ramp' */
              MODESACCELERATION_PIDLAUN_n(rtM, (real_T)rtDW.RateTransition36[3],
                (real_T)rtDW.RateTransition36[4], &Saturation4,
                &rtDW.MODESACCELERATION_PIDLAUNCH5ACT);

              /* End of Outputs for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH5.ACTIVE.ramp' */
              if (Saturation4 < 256.0) {
                if (Saturation4 >= 0.0) {
                  rtDW.clutchCurrVal = (uint8_T)Saturation4;
                } else {
                  rtDW.clutchCurrVal = 0U;
                }
              } else {
                rtDW.clutchCurrVal = MAX_uint8_T;
              }
            }
          } else {
            rtDW.is_ACTIVE_f = 0;
            if (rtDW.is_ACTIVE_f != IN_READY) {
              rtDW.is_ACTIVE_f = IN_READY;
              rtDW.stateFb = (uint16_T)AUTOX_READY;
              rtDW.autoXCounter_n2 = AUTOX_WORK_RATE_ms;
              Clutch_setValue(55);
              checkShift();
            }
          }
        } else {
          tmp = rtDW.autoXCounter_n2 - 1;
          if (tmp < 0) {
            tmp = 0;
          }

          rtDW.autoXCounter_n2 = (uint16_T)tmp;
          checkShift();
        }
        break;

       case IN_RELEASE:
        if (rtDW.RateTransition36[1] >= 15) {
          Clutch_setValue(0);

          /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
          UnsetRPMLimiter();

          /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
          rtDW.is_ACTIVE_f = 0;
          if (rtDW.is_ACTIVE_f != IN_RUNNING) {
            rtDW.is_ACTIVE_f = IN_RUNNING;
            rtDW.autoXCounter_n2 = AUTOX_WORK_RATE_ms;
            tmp_0 = rtDW.RateTransition36[6];
            if (rtDW.RateTransition36[6] > 255) {
              tmp_0 = 255U;
            }

            rtDW.lastShift = (uint8_T)tmp_0;
            autoXCheckShift();
          }
        } else {
          /* Outputs for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH5.ACTIVE.ramp' */
          MODESACCELERATION_PIDLAUN_n(rtM, (real_T)rtDW.RateTransition36[3],
            (real_T)rtDW.RateTransition36[4], &Saturation4,
            &rtDW.MODESACCELERATION_PIDLAUNCH5ACT);

          /* End of Outputs for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH5.ACTIVE.ramp' */
          if (Saturation4 < 256.0) {
            if (Saturation4 >= 0.0) {
              rtDW.clutchCurrVal = (uint8_T)Saturation4;
            } else {
              rtDW.clutchCurrVal = 0U;
            }
          } else {
            rtDW.clutchCurrVal = MAX_uint8_T;
          }
        }
        break;

       case IN_RUNNING:
        if ((rtDW.RateTransition36[6] >= 5) && (rtDW.RateTransition36[6] != 8))
        {
          rtDW.is_ACTIVE_f = 0;
          if (rtDW.is_LAUNCH5 == IN_ACTIVE) {
            rtDW.is_LAUNCH5 = 0;
          }

          if (rtDW.is_LAUNCH5 != IN_STOPPING) {
            rtDW.is_LAUNCH5 = IN_STOPPING;

            /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
            UnsetRPMLimiter();

            /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
            Clutch_setValue(0);
          }
        } else {
          autoXCheckShift();
        }
        break;

       case IN_START:
        if (rtDW.autoXCounter_n2 <= 1) {
          rtDW.is_ACTIVE_f = 0;
          if (rtDW.is_ACTIVE_f != IN_READY) {
            rtDW.is_ACTIVE_f = IN_READY;
            rtDW.stateFb = (uint16_T)AUTOX_READY;
            rtDW.autoXCounter_n2 = AUTOX_WORK_RATE_ms;
            Clutch_setValue(55);
            checkShift();
          }
        } else {
          tmp = rtDW.autoXCounter_n2 - 1;
          if (tmp < 0) {
            tmp = 0;
          }

          rtDW.autoXCounter_n2 = (uint16_T)tmp;
        }
        break;
      }
    }
    break;

   case IN_STOPPING:
    rtDW.is_LAUNCH5 = 0;
    rtDW.is_ACCELERATION_PID = 0;
    if (rtDW.is_ACCELERATION_PID != IN_DEFAULT_j) {
      rtDW.is_ACCELERATION_PID = IN_DEFAULT_j;
      rtDW.stateFb = (uint16_T)AUTOX_DEFAULT;
      checkShift();
      checkClutch();
    }
    break;
  }
}

/* Function for Chart: '<S5>/GCULogic' */
static void LAUNCH6(void)
{
  real_T Sum_p;
  int32_T tmp;
  uint16_T tmp_0;
  switch (rtDW.is_LAUNCH6) {
   case IN_ACTIVE:
    if ((rtDW.RateTransition29[0] != rtDW.lastAutoXCom) &&
        (rtDW.RateTransition29[1] == AUTOX_DEFAULT)) {
      rtDW.lastAutoXCom = rtDW.RateTransition29[0];
      rtDW.is_RELEASE = 0;
      rtDW.is_ACTIVE_a = 0;
      if (rtDW.is_LAUNCH6 == IN_ACTIVE) {
        rtDW.is_LAUNCH6 = 0;
      }

      if (rtDW.is_LAUNCH6 != IN_STOPPING) {
        rtDW.is_LAUNCH6 = IN_STOPPING;

        /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
        UnsetRPMLimiter();

        /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
        Clutch_setValue(0);
      }
    } else {
      switch (rtDW.is_ACTIVE_a) {
       case IN_READY:
        if (rtDW.autoXCounter_e <= 1) {
          if ((rtDW.RateTransition29[0] != rtDW.lastAutoXCom) &&
              (rtDW.RateTransition29[1] == AUTOX_GO) && (rtDW.RateTransition36[2]
               >= getAutoXParam(AUTOX_TPS_START_LIMIT))) {
            rtDW.lastAutoXCom = rtDW.RateTransition29[0];
            rtDW.stateFb = (uint16_T)AUTOX_GO;
            rtDW.is_ACTIVE_a = 0;
            if (rtDW.is_ACTIVE_a != IN_RELEASE) {
              rtDW.is_ACTIVE_a = IN_RELEASE;
              rtDW.lastSlip = 0U;

              /* Outputs for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH6.ACTIVE.pidControl' */
              MODESACCELERATION_PIDLAUN_l(rtM, (real_T)rtDW.RateTransition36[4],
                (real_T)rtDW.RateTransition36[3], 1.0, &Sum_p,
                &rtDW.MODESACCELERATION_PIDLAUNCH6ACT,
                &rtPrevZCX.MODESACCELERATION_PIDLAUNCH6ACT);

              /* End of Outputs for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH6.ACTIVE.pidControl' */
            }

            rtDW.is_RELEASE = IN_WAIT;
          } else {
            rtDW.is_ACTIVE_a = 0;
            if (rtDW.is_ACTIVE_a != IN_READY) {
              rtDW.is_ACTIVE_a = IN_READY;
              rtDW.stateFb = (uint16_T)AUTOX_READY;
              rtDW.autoXCounter_e = AUTOX_WORK_RATE_ms;
              Clutch_setValue(55);
              checkShift();
            }
          }
        } else {
          tmp = rtDW.autoXCounter_e - 1;
          if (tmp < 0) {
            tmp = 0;
          }

          rtDW.autoXCounter_e = (uint16_T)tmp;
          checkShift();
        }
        break;

       case IN_RELEASE:
        if (rtDW.RateTransition36[1] >= RELEASE_END_SPEED) {
          Clutch_setValue(0);

          /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
          UnsetRPMLimiter();

          /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
          rtDW.is_RELEASE = 0;
          rtDW.is_ACTIVE_a = 0;
          if (rtDW.is_ACTIVE_a != IN_RUNNING) {
            rtDW.is_ACTIVE_a = IN_RUNNING;
            rtDW.autoXCounter_e = AUTOX_WORK_RATE_ms;
            tmp_0 = rtDW.RateTransition36[6];
            if (rtDW.RateTransition36[6] > 255) {
              tmp_0 = 255U;
            }

            rtDW.lastShift = (uint8_T)tmp_0;
            autoXCheckShift();
          }
        } else {
          switch (rtDW.is_RELEASE) {
           case IN_Control:
            rtDW.is_RELEASE = IN_WAIT;
            break;

           case IN_WAIT:
            if (rtDW.RateTransition34 != rtDW.lastSlip) {
              rtDW.lastSlip = rtDW.RateTransition34;
              rtDW.is_RELEASE = 0;
              if (rtDW.is_RELEASE != IN_Control) {
                rtDW.is_RELEASE = IN_Control;

                /* Outputs for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH6.ACTIVE.pidControl' */
                MODESACCELERATION_PIDLAUN_l(rtM, (real_T)rtDW.RateTransition36[4],
                  (real_T)rtDW.RateTransition36[3], 0.0, &Sum_p,
                  &rtDW.MODESACCELERATION_PIDLAUNCH6ACT,
                  &rtPrevZCX.MODESACCELERATION_PIDLAUNCH6ACT);

                /* End of Outputs for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH6.ACTIVE.pidControl' */
                if (Sum_p < 256.0) {
                  if (Sum_p >= 0.0) {
                    rtDW.clutchCurrVal = (uint8_T)Sum_p;
                  } else {
                    rtDW.clutchCurrVal = 0U;
                  }
                } else {
                  rtDW.clutchCurrVal = MAX_uint8_T;
                }
              }
            }
            break;
          }
        }
        break;

       case IN_RUNNING:
        if ((rtDW.RateTransition36[6] >= 5) && (rtDW.RateTransition36[6] != 8))
        {
          rtDW.is_ACTIVE_a = 0;
          if (rtDW.is_LAUNCH6 == IN_ACTIVE) {
            rtDW.is_LAUNCH6 = 0;
          }

          if (rtDW.is_LAUNCH6 != IN_STOPPING) {
            rtDW.is_LAUNCH6 = IN_STOPPING;

            /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
            UnsetRPMLimiter();

            /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
            Clutch_setValue(0);
          }
        } else {
          autoXCheckShift();
        }
        break;

       case IN_START:
        if (rtDW.autoXCounter_e <= 1) {
          rtDW.is_ACTIVE_a = 0;
          if (rtDW.is_ACTIVE_a != IN_READY) {
            rtDW.is_ACTIVE_a = IN_READY;
            rtDW.stateFb = (uint16_T)AUTOX_READY;
            rtDW.autoXCounter_e = AUTOX_WORK_RATE_ms;
            Clutch_setValue(55);
            checkShift();
          }
        } else {
          tmp = rtDW.autoXCounter_e - 1;
          if (tmp < 0) {
            tmp = 0;
          }

          rtDW.autoXCounter_e = (uint16_T)tmp;
        }
        break;
      }
    }
    break;

   case IN_STOPPING:
    rtDW.is_LAUNCH6 = 0;
    rtDW.is_ACCELERATION_PID = 0;
    if (rtDW.is_ACCELERATION_PID != IN_DEFAULT_j) {
      rtDW.is_ACCELERATION_PID = IN_DEFAULT_j;
      rtDW.stateFb = (uint16_T)AUTOX_DEFAULT;
      checkShift();
      checkClutch();
    }
    break;
  }
}

/* Function for Chart: '<S5>/GCULogic' */
static void LAUNCH7(void)
{
  real_T Sum_e;
  int32_T tmp;
  uint16_T tmp_0;
  switch (rtDW.is_LAUNCH7) {
   case IN_ACTIVE:
    if ((rtDW.RateTransition29[0] != rtDW.lastAutoXCom) &&
        (rtDW.RateTransition29[1] == AUTOX_DEFAULT)) {
      rtDW.lastAutoXCom = rtDW.RateTransition29[0];
      rtDW.is_RELEASE_k = 0;
      rtDW.is_ACTIVE_l = 0;
      if (rtDW.is_LAUNCH7 == IN_ACTIVE) {
        rtDW.is_LAUNCH7 = 0;
      }

      if (rtDW.is_LAUNCH7 != IN_STOPPING) {
        rtDW.is_LAUNCH7 = IN_STOPPING;

        /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
        UnsetRPMLimiter();

        /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
        Clutch_setValue(0);
      }
    } else {
      switch (rtDW.is_ACTIVE_l) {
       case IN_READY:
        if (rtDW.autoXCounter_p <= 1) {
          if ((rtDW.RateTransition29[0] != rtDW.lastAutoXCom) &&
              (rtDW.RateTransition29[1] == AUTOX_GO) && (rtDW.RateTransition36[2]
               >= getAutoXParam(AUTOX_TPS_START_LIMIT))) {
            rtDW.lastAutoXCom = rtDW.RateTransition29[0];
            rtDW.stateFb = (uint16_T)AUTOX_GO;
            rtDW.is_ACTIVE_l = 0;
            if (rtDW.is_ACTIVE_l != IN_RELEASE) {
              rtDW.is_ACTIVE_l = IN_RELEASE;
              rtDW.lastSlip_n = 0U;

              /* Outputs for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH7.ACTIVE.pidControl' */
              MODESACCELERATION_PIDLAUN_l(rtM, (real_T)rtDW.RateTransition36[4],
                (real_T)rtDW.RateTransition36[3], 1.0, &Sum_e,
                &rtDW.MODESACCELERATION_PIDLAUNCH7ACT,
                &rtPrevZCX.MODESACCELERATION_PIDLAUNCH7ACT);

              /* End of Outputs for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH7.ACTIVE.pidControl' */
            }

            rtDW.is_RELEASE_k = IN_WAIT;
          } else {
            rtDW.is_ACTIVE_l = 0;
            if (rtDW.is_ACTIVE_l != IN_READY) {
              rtDW.is_ACTIVE_l = IN_READY;
              rtDW.stateFb = (uint16_T)AUTOX_READY;
              rtDW.autoXCounter_p = AUTOX_WORK_RATE_ms;
              Clutch_setValue(55);
              checkShift();
            }
          }
        } else {
          tmp = rtDW.autoXCounter_p - 1;
          if (tmp < 0) {
            tmp = 0;
          }

          rtDW.autoXCounter_p = (uint16_T)tmp;
          checkShift();
        }
        break;

       case IN_RELEASE:
        if (rtDW.RateTransition36[1] >= 15) {
          Clutch_setValue(0);

          /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
          UnsetRPMLimiter();

          /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
          rtDW.is_RELEASE_k = 0;
          rtDW.is_ACTIVE_l = 0;
          if (rtDW.is_ACTIVE_l != IN_RUNNING) {
            rtDW.is_ACTIVE_l = IN_RUNNING;
            rtDW.autoXCounter_p = AUTOX_WORK_RATE_ms;
            tmp_0 = rtDW.RateTransition36[6];
            if (rtDW.RateTransition36[6] > 255) {
              tmp_0 = 255U;
            }

            rtDW.lastShift = (uint8_T)tmp_0;
            autoXCheckShift();
          }
        } else {
          switch (rtDW.is_RELEASE_k) {
           case IN_Control:
            rtDW.is_RELEASE_k = IN_WAIT;
            break;

           case IN_WAIT:
            if (rtDW.RateTransition34 != rtDW.lastSlip_n) {
              rtDW.lastSlip_n = rtDW.RateTransition34;
              rtDW.is_RELEASE_k = 0;
              if (rtDW.is_RELEASE_k != IN_Control) {
                rtDW.is_RELEASE_k = IN_Control;

                /* Outputs for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH7.ACTIVE.pidControl' */
                MODESACCELERATION_PIDLAUN_l(rtM, (real_T)rtDW.RateTransition36[4],
                  (real_T)rtDW.RateTransition36[3], 0.0, &Sum_e,
                  &rtDW.MODESACCELERATION_PIDLAUNCH7ACT,
                  &rtPrevZCX.MODESACCELERATION_PIDLAUNCH7ACT);

                /* End of Outputs for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH7.ACTIVE.pidControl' */
                if (Sum_e < 256.0) {
                  if (Sum_e >= 0.0) {
                    rtDW.clutchCurrVal = (uint8_T)Sum_e;
                  } else {
                    rtDW.clutchCurrVal = 0U;
                  }
                } else {
                  rtDW.clutchCurrVal = MAX_uint8_T;
                }
              }
            }
            break;
          }
        }
        break;

       case IN_RUNNING:
        if ((rtDW.RateTransition36[6] >= 5) && (rtDW.RateTransition36[6] != 8))
        {
          rtDW.is_ACTIVE_l = 0;
          if (rtDW.is_LAUNCH7 == IN_ACTIVE) {
            rtDW.is_LAUNCH7 = 0;
          }

          if (rtDW.is_LAUNCH7 != IN_STOPPING) {
            rtDW.is_LAUNCH7 = IN_STOPPING;

            /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
            UnsetRPMLimiter();

            /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
            Clutch_setValue(0);
          }
        } else {
          autoXCheckShift();
        }
        break;

       case IN_START:
        if (rtDW.autoXCounter_p <= 1) {
          rtDW.is_ACTIVE_l = 0;
          if (rtDW.is_ACTIVE_l != IN_READY) {
            rtDW.is_ACTIVE_l = IN_READY;
            rtDW.stateFb = (uint16_T)AUTOX_READY;
            rtDW.autoXCounter_p = AUTOX_WORK_RATE_ms;
            Clutch_setValue(55);
            checkShift();
          }
        } else {
          tmp = rtDW.autoXCounter_p - 1;
          if (tmp < 0) {
            tmp = 0;
          }

          rtDW.autoXCounter_p = (uint16_T)tmp;
        }
        break;
      }
    }
    break;

   case IN_STOPPING:
    rtDW.is_LAUNCH7 = 0;
    rtDW.is_ACCELERATION_PID = 0;
    if (rtDW.is_ACCELERATION_PID != IN_DEFAULT_j) {
      rtDW.is_ACCELERATION_PID = IN_DEFAULT_j;
      rtDW.stateFb = (uint16_T)AUTOX_DEFAULT;
      checkShift();
      checkClutch();
    }
    break;
  }
}

/* Function for Chart: '<S5>/GCULogic' */
static void LAUNCH8(void)
{
  real_T Sum_m;
  int32_T tmp;
  uint16_T tmp_0;
  switch (rtDW.is_LAUNCH8) {
   case IN_ACTIVE:
    if ((rtDW.RateTransition29[0] != rtDW.lastAutoXCom) &&
        (rtDW.RateTransition29[1] == AUTOX_DEFAULT)) {
      rtDW.lastAutoXCom = rtDW.RateTransition29[0];
      rtDW.is_RELEASE_d = 0;
      rtDW.is_ACTIVE_ky = 0;
      if (rtDW.is_LAUNCH8 == IN_ACTIVE) {
        rtDW.is_LAUNCH8 = 0;
      }

      if (rtDW.is_LAUNCH8 != IN_STOPPING) {
        rtDW.is_LAUNCH8 = IN_STOPPING;

        /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
        UnsetRPMLimiter();

        /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
        Clutch_setValue(0);
      }
    } else {
      switch (rtDW.is_ACTIVE_ky) {
       case IN_READY:
        if (rtDW.autoXCounter_o3 <= 1) {
          if ((rtDW.RateTransition29[0] != rtDW.lastAutoXCom) &&
              (rtDW.RateTransition29[1] == AUTOX_GO) && (rtDW.RateTransition36[2]
               >= getAutoXParam(AUTOX_TPS_START_LIMIT))) {
            rtDW.lastAutoXCom = rtDW.RateTransition29[0];
            rtDW.stateFb = (uint16_T)AUTOX_GO;
            rtDW.is_ACTIVE_ky = 0;
            if (rtDW.is_ACTIVE_ky != IN_RELEASE) {
              rtDW.is_ACTIVE_ky = IN_RELEASE;
              rtDW.lastSlip_a = 0U;

              /* Outputs for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH8.ACTIVE.pidControl' */
              MODESACCELERATION_PIDLAUN_e(rtM, (real_T)rtDW.RateTransition36[4],
                (real_T)rtDW.RateTransition36[3], 1.0, &Sum_m,
                &rtDW.MODESACCELERATION_PIDLAUNCH8ACT,
                &rtPrevZCX.MODESACCELERATION_PIDLAUNCH8ACT);

              /* End of Outputs for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH8.ACTIVE.pidControl' */
            }

            rtDW.is_RELEASE_d = IN_WAIT;
          } else {
            rtDW.is_ACTIVE_ky = 0;
            if (rtDW.is_ACTIVE_ky != IN_READY) {
              rtDW.is_ACTIVE_ky = IN_READY;
              rtDW.stateFb = (uint16_T)AUTOX_READY;
              rtDW.autoXCounter_o3 = AUTOX_WORK_RATE_ms;
              Clutch_setValue(55);
              checkShift();
            }
          }
        } else {
          tmp = rtDW.autoXCounter_o3 - 1;
          if (tmp < 0) {
            tmp = 0;
          }

          rtDW.autoXCounter_o3 = (uint16_T)tmp;
          checkShift();
        }
        break;

       case IN_RELEASE:
        if (rtDW.RateTransition36[1] >= RELEASE_END_SPEED) {
          Clutch_setValue(0);

          /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
          UnsetRPMLimiter();

          /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
          rtDW.is_RELEASE_d = 0;
          rtDW.is_ACTIVE_ky = 0;
          if (rtDW.is_ACTIVE_ky != IN_RUNNING) {
            rtDW.is_ACTIVE_ky = IN_RUNNING;
            rtDW.autoXCounter_o3 = AUTOX_WORK_RATE_ms;
            tmp_0 = rtDW.RateTransition36[6];
            if (rtDW.RateTransition36[6] > 255) {
              tmp_0 = 255U;
            }

            rtDW.lastShift = (uint8_T)tmp_0;
            autoXCheckShift();
          }
        } else {
          switch (rtDW.is_RELEASE_d) {
           case IN_Control:
            rtDW.is_RELEASE_d = IN_WAIT;
            break;

           case IN_WAIT:
            if (rtDW.RateTransition34 != rtDW.lastSlip_a) {
              rtDW.lastSlip_a = rtDW.RateTransition34;
              rtDW.is_RELEASE_d = 0;
              if (rtDW.is_RELEASE_d != IN_Control) {
                rtDW.is_RELEASE_d = IN_Control;

                /* Outputs for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH8.ACTIVE.pidControl' */
                MODESACCELERATION_PIDLAUN_e(rtM, (real_T)rtDW.RateTransition36[4],
                  (real_T)rtDW.RateTransition36[3], 0.0, &Sum_m,
                  &rtDW.MODESACCELERATION_PIDLAUNCH8ACT,
                  &rtPrevZCX.MODESACCELERATION_PIDLAUNCH8ACT);

                /* End of Outputs for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH8.ACTIVE.pidControl' */
                if (Sum_m < 256.0) {
                  if (Sum_m >= 0.0) {
                    rtDW.clutchCurrVal = (uint8_T)Sum_m;
                  } else {
                    rtDW.clutchCurrVal = 0U;
                  }
                } else {
                  rtDW.clutchCurrVal = MAX_uint8_T;
                }
              }
            }
            break;
          }
        }
        break;

       case IN_RUNNING:
        if ((rtDW.RateTransition36[6] >= 5) && (rtDW.RateTransition36[6] != 8))
        {
          rtDW.is_ACTIVE_ky = 0;
          if (rtDW.is_LAUNCH8 == IN_ACTIVE) {
            rtDW.is_LAUNCH8 = 0;
          }

          if (rtDW.is_LAUNCH8 != IN_STOPPING) {
            rtDW.is_LAUNCH8 = IN_STOPPING;

            /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
            UnsetRPMLimiter();

            /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
            Clutch_setValue(0);
          }
        } else {
          autoXCheckShift();
        }
        break;

       case IN_START:
        if (rtDW.autoXCounter_o3 <= 1) {
          rtDW.is_ACTIVE_ky = 0;
          if (rtDW.is_ACTIVE_ky != IN_READY) {
            rtDW.is_ACTIVE_ky = IN_READY;
            rtDW.stateFb = (uint16_T)AUTOX_READY;
            rtDW.autoXCounter_o3 = AUTOX_WORK_RATE_ms;
            Clutch_setValue(55);
            checkShift();
          }
        } else {
          tmp = rtDW.autoXCounter_o3 - 1;
          if (tmp < 0) {
            tmp = 0;
          }

          rtDW.autoXCounter_o3 = (uint16_T)tmp;
        }
        break;
      }
    }
    break;

   case IN_STOPPING:
    rtDW.is_LAUNCH8 = 0;
    rtDW.is_ACCELERATION_PID = 0;
    if (rtDW.is_ACCELERATION_PID != IN_DEFAULT_j) {
      rtDW.is_ACCELERATION_PID = IN_DEFAULT_j;
      rtDW.stateFb = (uint16_T)AUTOX_DEFAULT;
      checkShift();
      checkClutch();
    }
    break;
  }
}

/* Function for Chart: '<S5>/GCULogic' */
static void LAUNCH9(void)
{
  real_T Sum;
  int32_T tmp;
  uint16_T tmp_0;
  switch (rtDW.is_LAUNCH9) {
   case IN_ACTIVE:
    if ((rtDW.RateTransition29[0] != rtDW.lastAutoXCom) &&
        (rtDW.RateTransition29[1] == AUTOX_DEFAULT)) {
      rtDW.lastAutoXCom = rtDW.RateTransition29[0];
      rtDW.is_RELEASE_g = 0;
      rtDW.is_ACTIVE_h = 0;
      if (rtDW.is_LAUNCH9 == IN_ACTIVE) {
        rtDW.is_LAUNCH9 = 0;
      }

      if (rtDW.is_LAUNCH9 != IN_STOPPING) {
        rtDW.is_LAUNCH9 = IN_STOPPING;

        /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
        UnsetRPMLimiter();

        /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
        Clutch_setValue(0);
      }
    } else {
      switch (rtDW.is_ACTIVE_h) {
       case IN_READY:
        if (rtDW.autoXCounter_m <= 1) {
          if ((rtDW.RateTransition29[0] != rtDW.lastAutoXCom) &&
              (rtDW.RateTransition29[1] == AUTOX_GO) && (rtDW.RateTransition36[2]
               >= getAutoXParam(AUTOX_TPS_START_LIMIT))) {
            rtDW.lastAutoXCom = rtDW.RateTransition29[0];
            rtDW.stateFb = (uint16_T)AUTOX_GO;
            rtDW.is_ACTIVE_h = 0;
            if (rtDW.is_ACTIVE_h != IN_RELEASE) {
              rtDW.is_ACTIVE_h = IN_RELEASE;
              rtDW.lastSlip_l = 0U;

              /* Outputs for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH9.ACTIVE.pidControl' */
              MODESACCELERATION_PIDLAUN_e(rtM, (real_T)rtDW.RateTransition36[4],
                (real_T)rtDW.RateTransition36[3], 1.0, &Sum,
                &rtDW.MODESACCELERATION_PIDLAUNCH9ACT,
                &rtPrevZCX.MODESACCELERATION_PIDLAUNCH9ACT);

              /* End of Outputs for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH9.ACTIVE.pidControl' */
            }

            rtDW.is_RELEASE_g = IN_WAIT;
          } else {
            rtDW.is_ACTIVE_h = 0;
            if (rtDW.is_ACTIVE_h != IN_READY) {
              rtDW.is_ACTIVE_h = IN_READY;
              rtDW.stateFb = (uint16_T)AUTOX_READY;
              rtDW.autoXCounter_m = AUTOX_WORK_RATE_ms;
              Clutch_setValue(55);
              checkShift();
            }
          }
        } else {
          tmp = rtDW.autoXCounter_m - 1;
          if (tmp < 0) {
            tmp = 0;
          }

          rtDW.autoXCounter_m = (uint16_T)tmp;
          checkShift();
        }
        break;

       case IN_RELEASE:
        if (rtDW.RateTransition36[1] >= 15) {
          Clutch_setValue(0);

          /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
          UnsetRPMLimiter();

          /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
          rtDW.is_RELEASE_g = 0;
          rtDW.is_ACTIVE_h = 0;
          if (rtDW.is_ACTIVE_h != IN_RUNNING) {
            rtDW.is_ACTIVE_h = IN_RUNNING;
            rtDW.autoXCounter_m = AUTOX_WORK_RATE_ms;
            tmp_0 = rtDW.RateTransition36[6];
            if (rtDW.RateTransition36[6] > 255) {
              tmp_0 = 255U;
            }

            rtDW.lastShift = (uint8_T)tmp_0;
            autoXCheckShift();
          }
        } else {
          switch (rtDW.is_RELEASE_g) {
           case IN_Control:
            rtDW.is_RELEASE_g = IN_WAIT;
            break;

           case IN_WAIT:
            if (rtDW.RateTransition34 != rtDW.lastSlip_l) {
              rtDW.lastSlip_l = rtDW.RateTransition34;
              rtDW.is_RELEASE_g = 0;
              if (rtDW.is_RELEASE_g != IN_Control) {
                rtDW.is_RELEASE_g = IN_Control;

                /* Outputs for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH9.ACTIVE.pidControl' */
                MODESACCELERATION_PIDLAUN_e(rtM, (real_T)rtDW.RateTransition36[4],
                  (real_T)rtDW.RateTransition36[3], 0.0, &Sum,
                  &rtDW.MODESACCELERATION_PIDLAUNCH9ACT,
                  &rtPrevZCX.MODESACCELERATION_PIDLAUNCH9ACT);

                /* End of Outputs for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH9.ACTIVE.pidControl' */
                if (Sum < 256.0) {
                  if (Sum >= 0.0) {
                    rtDW.clutchCurrVal = (uint8_T)Sum;
                  } else {
                    rtDW.clutchCurrVal = 0U;
                  }
                } else {
                  rtDW.clutchCurrVal = MAX_uint8_T;
                }
              }
            }
            break;
          }
        }
        break;

       case IN_RUNNING:
        if ((rtDW.RateTransition36[6] >= 5) && (rtDW.RateTransition36[6] != 8))
        {
          rtDW.is_ACTIVE_h = 0;
          if (rtDW.is_LAUNCH9 == IN_ACTIVE) {
            rtDW.is_LAUNCH9 = 0;
          }

          if (rtDW.is_LAUNCH9 != IN_STOPPING) {
            rtDW.is_LAUNCH9 = IN_STOPPING;

            /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
            UnsetRPMLimiter();

            /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
            Clutch_setValue(0);
          }
        } else {
          autoXCheckShift();
        }
        break;

       case IN_START:
        if (rtDW.autoXCounter_m <= 1) {
          rtDW.is_ACTIVE_h = 0;
          if (rtDW.is_ACTIVE_h != IN_READY) {
            rtDW.is_ACTIVE_h = IN_READY;
            rtDW.stateFb = (uint16_T)AUTOX_READY;
            rtDW.autoXCounter_m = AUTOX_WORK_RATE_ms;
            Clutch_setValue(55);
            checkShift();
          }
        } else {
          tmp = rtDW.autoXCounter_m - 1;
          if (tmp < 0) {
            tmp = 0;
          }

          rtDW.autoXCounter_m = (uint16_T)tmp;
        }
        break;
      }
    }
    break;

   case IN_STOPPING:
    rtDW.is_LAUNCH9 = 0;
    rtDW.is_ACCELERATION_PID = 0;
    if (rtDW.is_ACCELERATION_PID != IN_DEFAULT_j) {
      rtDW.is_ACCELERATION_PID = IN_DEFAULT_j;
      rtDW.stateFb = (uint16_T)AUTOX_DEFAULT;
      checkShift();
      checkClutch();
    }
    break;
  }
}

/* Function for Chart: '<S5>/GCULogic' */
static void exit_internal_ACCELERATION_PID(void)
{
  switch (rtDW.is_ACCELERATION_PID) {
   case IN_LAUNCH0:
    if (rtDW.is_LAUNCH0 == IN_ACTIVE) {
      rtDW.is_ACTIVE_d = 0;
      if (rtDW.is_LAUNCH0 == IN_ACTIVE) {
        rtDW.is_LAUNCH0 = 0;
      }
    } else {
      rtDW.is_LAUNCH0 = 0;
    }

    rtDW.is_ACCELERATION_PID = 0;
    break;

   case IN_LAUNCH1:
    if (rtDW.is_LAUNCH1 == IN_ACTIVE) {
      rtDW.is_ACTIVE_k = 0;
      if (rtDW.is_LAUNCH1 == IN_ACTIVE) {
        rtDW.is_LAUNCH1 = 0;
      }
    } else {
      rtDW.is_LAUNCH1 = 0;
    }

    rtDW.is_ACCELERATION_PID = 0;
    break;

   case IN_LAUNCH2:
    if (rtDW.is_LAUNCH2 == IN_ACTIVE) {
      rtDW.is_ACTIVE_e = 0;
      if (rtDW.is_LAUNCH2 == IN_ACTIVE) {
        rtDW.is_LAUNCH2 = 0;
      }
    } else {
      rtDW.is_LAUNCH2 = 0;
    }

    rtDW.is_ACCELERATION_PID = 0;
    break;

   case IN_LAUNCH3:
    if (rtDW.is_LAUNCH3 == IN_ACTIVE) {
      rtDW.is_ACTIVE_c = 0;
      if (rtDW.is_LAUNCH3 == IN_ACTIVE) {
        rtDW.is_LAUNCH3 = 0;
      }
    } else {
      rtDW.is_LAUNCH3 = 0;
    }

    rtDW.is_ACCELERATION_PID = 0;
    break;

   case IN_LAUNCH4:
    if (rtDW.is_LAUNCH4 == IN_ACTIVE) {
      rtDW.is_ACTIVE_cg = 0;
      if (rtDW.is_LAUNCH4 == IN_ACTIVE) {
        rtDW.is_LAUNCH4 = 0;
      }
    } else {
      rtDW.is_LAUNCH4 = 0;
    }

    rtDW.is_ACCELERATION_PID = 0;
    break;

   case IN_LAUNCH5:
    if (rtDW.is_LAUNCH5 == IN_ACTIVE) {
      rtDW.is_ACTIVE_f = 0;
      if (rtDW.is_LAUNCH5 == IN_ACTIVE) {
        rtDW.is_LAUNCH5 = 0;
      }
    } else {
      rtDW.is_LAUNCH5 = 0;
    }

    rtDW.is_ACCELERATION_PID = 0;
    break;

   case IN_LAUNCH6:
    if (rtDW.is_LAUNCH6 == IN_ACTIVE) {
      rtDW.is_RELEASE = 0;
      rtDW.is_ACTIVE_a = 0;
      if (rtDW.is_LAUNCH6 == IN_ACTIVE) {
        rtDW.is_LAUNCH6 = 0;
      }
    } else {
      rtDW.is_LAUNCH6 = 0;
    }

    rtDW.is_ACCELERATION_PID = 0;
    break;

   case IN_LAUNCH7:
    if (rtDW.is_LAUNCH7 == IN_ACTIVE) {
      rtDW.is_RELEASE_k = 0;
      rtDW.is_ACTIVE_l = 0;
      if (rtDW.is_LAUNCH7 == IN_ACTIVE) {
        rtDW.is_LAUNCH7 = 0;
      }
    } else {
      rtDW.is_LAUNCH7 = 0;
    }

    rtDW.is_ACCELERATION_PID = 0;
    break;

   case IN_LAUNCH8:
    if (rtDW.is_LAUNCH8 == IN_ACTIVE) {
      rtDW.is_RELEASE_d = 0;
      rtDW.is_ACTIVE_ky = 0;
      if (rtDW.is_LAUNCH8 == IN_ACTIVE) {
        rtDW.is_LAUNCH8 = 0;
      }
    } else {
      rtDW.is_LAUNCH8 = 0;
    }

    rtDW.is_ACCELERATION_PID = 0;
    break;

   case IN_LAUNCH9:
    if (rtDW.is_LAUNCH9 == IN_ACTIVE) {
      rtDW.is_RELEASE_g = 0;
      rtDW.is_ACTIVE_h = 0;
      if (rtDW.is_LAUNCH9 == IN_ACTIVE) {
        rtDW.is_LAUNCH9 = 0;
      }
    } else {
      rtDW.is_LAUNCH9 = 0;
    }

    rtDW.is_ACCELERATION_PID = 0;
    break;

   default:
    rtDW.is_ACCELERATION_PID = 0;
    break;
  }
}

/* Function for Chart: '<S5>/GCULogic' */
static void enter_atomic_ACCELERATION(void)
{
  rtDW.lastAacCom = rtDW.RateTransition4[0];
  rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
  rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
}

/* Function for Chart: '<S5>/GCULogic' */
static void ACCELERATION_PID(void)
{
  real_T OutportBufferForclutchCurrVal_f;
  int32_T tmp;
  uint16_T tmp_0;
  if ((rtDW.RateTransition8[0] != rtDW.lastModeCom[0]) && (rtDW.RateTransition8
       [1] != rtDW.lastModeCom[1])) {
    /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
    UnsetRPMLimiter();

    /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
    rtDW.stateFb = (uint16_T)ACC_OFF;
    Clutch_setValue(0);
    if (rtDW.RateTransition8[1] == ENDURANCE_MODE) {
      exit_internal_ACCELERATION_PID();
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        enter_atomic_MANUAL_MODES();
      }

      rtDW.is_MANUAL_MODES = IN_ENDURANCE;
    } else if (rtDW.RateTransition8[1] == SKIDPAD_MODE) {
      exit_internal_ACCELERATION_PID();
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        enter_atomic_MANUAL_MODES();
      }

      if (rtDW.is_MANUAL_MODES != IN_SKIDPAD) {
        rtDW.is_MANUAL_MODES = IN_SKIDPAD;

        /* Outputs for Function Call SubSystem: '<S45>/SetRPMLimiter' */
        SetRPMLimiter();

        /* End of Outputs for SubSystem: '<S45>/SetRPMLimiter' */
      }
    } else if (rtDW.RateTransition8[1] == ACCELERATION_MODE) {
      exit_internal_ACCELERATION_PID();
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_ACCELERATION) {
        rtDW.is_MODES = IN_ACCELERATION;
        enter_atomic_ACCELERATION();
      }

      if (rtDW.is_ACCELERATION != IN_DEFAULT) {
        rtDW.is_ACCELERATION = IN_DEFAULT;
        rtDW.stateFb = (uint16_T)ACC_OFF;
        checkShift();
        checkClutch();
      }
    } else if (rtDW.RateTransition8[1] == AUTOX_MODE) {
      exit_internal_ACCELERATION_PID();
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_ACCELERATION_PID) {
        rtDW.is_MODES = IN_ACCELERATION_PID;
        rtDW.lastAutoXCom = rtDW.RateTransition29[0];
        rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
        rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
      }

      if (rtDW.is_ACCELERATION_PID != IN_DEFAULT_j) {
        rtDW.is_ACCELERATION_PID = IN_DEFAULT_j;
        rtDW.stateFb = (uint16_T)AUTOX_DEFAULT;
        checkShift();
        checkClutch();
      }
    } else {
      exit_internal_ACCELERATION_PID();
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
        rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
        checkShift();
        checkClutch();
      }

      rtDW.is_MANUAL_MODES = IN_ENDURANCE;
    }
  } else {
    switch (rtDW.is_ACCELERATION_PID) {
     case IN_DEFAULT_j:
      DEFAULT();
      break;

     case IN_LAUNCH0:
      switch (rtDW.is_LAUNCH0) {
       case IN_ACTIVE:
        if ((rtDW.RateTransition29[0] != rtDW.lastAutoXCom) &&
            (rtDW.RateTransition29[1] == AUTOX_DEFAULT)) {
          rtDW.lastAutoXCom = rtDW.RateTransition29[0];
          rtDW.is_ACTIVE_d = 0;
          if (rtDW.is_LAUNCH0 == IN_ACTIVE) {
            rtDW.is_LAUNCH0 = 0;
          }

          if (rtDW.is_LAUNCH0 != IN_STOPPING) {
            rtDW.is_LAUNCH0 = IN_STOPPING;

            /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
            UnsetRPMLimiter();

            /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
            Clutch_setValue(0);
          }
        } else {
          switch (rtDW.is_ACTIVE_d) {
           case IN_READY:
            if (rtDW.autoXCounter_n <= 1) {
              if ((rtDW.RateTransition29[0] != rtDW.lastAutoXCom) &&
                  (rtDW.RateTransition29[1] == AUTOX_GO) &&
                  (rtDW.RateTransition36[2] >= getAutoXParam
                   (AUTOX_TPS_START_LIMIT))) {
                rtDW.lastAutoXCom = rtDW.RateTransition29[0];
                rtDW.stateFb = (uint16_T)AUTOX_GO;
                rtDW.is_ACTIVE_d = 0;
                if (rtDW.is_ACTIVE_d != IN_RELEASE) {
                  rtDW.is_ACTIVE_d = IN_RELEASE;

                  /* Outputs for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH0.ACTIVE.ramp' */
                  MODESACCELERATION_PIDLAUNCH(rtM,
                    &OutportBufferForclutchCurrVal_f,
                    &rtDW.MODESACCELERATION_PIDLAUNCH0ACT);

                  /* End of Outputs for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH0.ACTIVE.ramp' */
                  if (OutportBufferForclutchCurrVal_f < 256.0) {
                    if (OutportBufferForclutchCurrVal_f >= 0.0) {
                      rtDW.clutchCurrVal = (uint8_T)
                        OutportBufferForclutchCurrVal_f;
                    } else {
                      rtDW.clutchCurrVal = 0U;
                    }
                  } else {
                    rtDW.clutchCurrVal = MAX_uint8_T;
                  }
                }
              } else {
                rtDW.is_ACTIVE_d = 0;
                if (rtDW.is_ACTIVE_d != IN_READY) {
                  rtDW.is_ACTIVE_d = IN_READY;
                  rtDW.stateFb = (uint16_T)AUTOX_READY;
                  rtDW.autoXCounter_n = AUTOX_WORK_RATE_ms;
                  Clutch_setValue(55);
                  checkShift();
                }
              }
            } else {
              tmp = rtDW.autoXCounter_n - 1;
              if (tmp < 0) {
                tmp = 0;
              }

              rtDW.autoXCounter_n = (uint16_T)tmp;
              checkShift();
            }
            break;

           case IN_RELEASE:
            if (rtDW.RateTransition36[1] >= RELEASE_END_SPEED) {
              Clutch_setValue(0);

              /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
              UnsetRPMLimiter();

              /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
              rtDW.is_ACTIVE_d = 0;
              if (rtDW.is_ACTIVE_d != IN_RUNNING) {
                rtDW.is_ACTIVE_d = IN_RUNNING;
                rtDW.autoXCounter_n = AUTOX_WORK_RATE_ms;
                tmp_0 = rtDW.RateTransition36[6];
                if (rtDW.RateTransition36[6] > 255) {
                  tmp_0 = 255U;
                }

                rtDW.lastShift = (uint8_T)tmp_0;
                autoXCheckShift();
              }
            } else {
              /* Outputs for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH0.ACTIVE.ramp' */
              MODESACCELERATION_PIDLAUNCH(rtM, &OutportBufferForclutchCurrVal_f,
                &rtDW.MODESACCELERATION_PIDLAUNCH0ACT);

              /* End of Outputs for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH0.ACTIVE.ramp' */
              if (OutportBufferForclutchCurrVal_f < 256.0) {
                if (OutportBufferForclutchCurrVal_f >= 0.0) {
                  rtDW.clutchCurrVal = (uint8_T)OutportBufferForclutchCurrVal_f;
                } else {
                  rtDW.clutchCurrVal = 0U;
                }
              } else {
                rtDW.clutchCurrVal = MAX_uint8_T;
              }
            }
            break;

           case IN_RUNNING:
            if ((rtDW.RateTransition36[6] >= 5) && (rtDW.RateTransition36[6] !=
                 8)) {
              rtDW.is_ACTIVE_d = 0;
              if (rtDW.is_LAUNCH0 == IN_ACTIVE) {
                rtDW.is_LAUNCH0 = 0;
              }

              if (rtDW.is_LAUNCH0 != IN_STOPPING) {
                rtDW.is_LAUNCH0 = IN_STOPPING;

                /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
                UnsetRPMLimiter();

                /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
                Clutch_setValue(0);
              }
            } else {
              autoXCheckShift();
            }
            break;

           case IN_START:
            if (rtDW.autoXCounter_n <= 1) {
              rtDW.is_ACTIVE_d = 0;
              if (rtDW.is_ACTIVE_d != IN_READY) {
                rtDW.is_ACTIVE_d = IN_READY;
                rtDW.stateFb = (uint16_T)AUTOX_READY;
                rtDW.autoXCounter_n = AUTOX_WORK_RATE_ms;
                Clutch_setValue(55);
                checkShift();
              }
            } else {
              tmp = rtDW.autoXCounter_n - 1;
              if (tmp < 0) {
                tmp = 0;
              }

              rtDW.autoXCounter_n = (uint16_T)tmp;
            }
            break;
          }
        }
        break;

       case IN_STOPPING:
        rtDW.is_LAUNCH0 = 0;
        rtDW.is_ACCELERATION_PID = 0;
        if (rtDW.is_ACCELERATION_PID != IN_DEFAULT_j) {
          rtDW.is_ACCELERATION_PID = IN_DEFAULT_j;
          rtDW.stateFb = (uint16_T)AUTOX_DEFAULT;
          checkShift();
          checkClutch();
        }
        break;
      }
      break;

     case IN_LAUNCH1:
      switch (rtDW.is_LAUNCH1) {
       case IN_ACTIVE:
        if ((rtDW.RateTransition29[0] != rtDW.lastAutoXCom) &&
            (rtDW.RateTransition29[1] == AUTOX_DEFAULT)) {
          rtDW.lastAutoXCom = rtDW.RateTransition29[0];
          rtDW.is_ACTIVE_k = 0;
          if (rtDW.is_LAUNCH1 == IN_ACTIVE) {
            rtDW.is_LAUNCH1 = 0;
          }

          if (rtDW.is_LAUNCH1 != IN_STOPPING) {
            rtDW.is_LAUNCH1 = IN_STOPPING;

            /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
            UnsetRPMLimiter();

            /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
            Clutch_setValue(0);
          }
        } else {
          switch (rtDW.is_ACTIVE_k) {
           case IN_READY:
            if (rtDW.autoXCounter_o <= 1) {
              if ((rtDW.RateTransition29[0] != rtDW.lastAutoXCom) &&
                  (rtDW.RateTransition29[1] == AUTOX_GO) &&
                  (rtDW.RateTransition36[2] >= getAutoXParam
                   (AUTOX_TPS_START_LIMIT))) {
                rtDW.lastAutoXCom = rtDW.RateTransition29[0];
                rtDW.stateFb = (uint16_T)AUTOX_GO;
                rtDW.is_ACTIVE_k = 0;
                if (rtDW.is_ACTIVE_k != IN_RELEASE) {
                  rtDW.is_ACTIVE_k = IN_RELEASE;

                  /* Outputs for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH1.ACTIVE.ramp' */
                  MODESACCELERATION_PIDLAUN_o(rtM,
                    &OutportBufferForclutchCurrVal_f,
                    &rtDW.MODESACCELERATION_PIDLAUNCH1ACT);

                  /* End of Outputs for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH1.ACTIVE.ramp' */
                  if (OutportBufferForclutchCurrVal_f < 256.0) {
                    if (OutportBufferForclutchCurrVal_f >= 0.0) {
                      rtDW.clutchCurrVal = (uint8_T)
                        OutportBufferForclutchCurrVal_f;
                    } else {
                      rtDW.clutchCurrVal = 0U;
                    }
                  } else {
                    rtDW.clutchCurrVal = MAX_uint8_T;
                  }
                }
              } else {
                rtDW.is_ACTIVE_k = 0;
                if (rtDW.is_ACTIVE_k != IN_READY) {
                  rtDW.is_ACTIVE_k = IN_READY;
                  rtDW.stateFb = (uint16_T)AUTOX_READY;
                  rtDW.autoXCounter_o = AUTOX_WORK_RATE_ms;
                  Clutch_setValue(55);
                  checkShift();
                }
              }
            } else {
              tmp = rtDW.autoXCounter_o - 1;
              if (tmp < 0) {
                tmp = 0;
              }

              rtDW.autoXCounter_o = (uint16_T)tmp;
              checkShift();
            }
            break;

           case IN_RELEASE:
            if (rtDW.RateTransition36[1] >= RELEASE_END_SPEED) {
              Clutch_setValue(0);

              /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
              UnsetRPMLimiter();

              /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
              rtDW.is_ACTIVE_k = 0;
              if (rtDW.is_ACTIVE_k != IN_RUNNING) {
                rtDW.is_ACTIVE_k = IN_RUNNING;
                rtDW.autoXCounter_o = AUTOX_WORK_RATE_ms;
                tmp_0 = rtDW.RateTransition36[6];
                if (rtDW.RateTransition36[6] > 255) {
                  tmp_0 = 255U;
                }

                rtDW.lastShift = (uint8_T)tmp_0;
                autoXCheckShift();
              }
            } else {
              /* Outputs for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH1.ACTIVE.ramp' */
              MODESACCELERATION_PIDLAUN_o(rtM, &OutportBufferForclutchCurrVal_f,
                &rtDW.MODESACCELERATION_PIDLAUNCH1ACT);

              /* End of Outputs for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH1.ACTIVE.ramp' */
              if (OutportBufferForclutchCurrVal_f < 256.0) {
                if (OutportBufferForclutchCurrVal_f >= 0.0) {
                  rtDW.clutchCurrVal = (uint8_T)OutportBufferForclutchCurrVal_f;
                } else {
                  rtDW.clutchCurrVal = 0U;
                }
              } else {
                rtDW.clutchCurrVal = MAX_uint8_T;
              }
            }
            break;

           case IN_RUNNING:
            if ((rtDW.RateTransition36[6] >= 5) && (rtDW.RateTransition36[6] !=
                 8)) {
              rtDW.is_ACTIVE_k = 0;
              if (rtDW.is_LAUNCH1 == IN_ACTIVE) {
                rtDW.is_LAUNCH1 = 0;
              }

              if (rtDW.is_LAUNCH1 != IN_STOPPING) {
                rtDW.is_LAUNCH1 = IN_STOPPING;

                /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
                UnsetRPMLimiter();

                /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
                Clutch_setValue(0);
              }
            } else {
              autoXCheckShift();
            }
            break;

           case IN_START:
            if (rtDW.autoXCounter_o <= 1) {
              rtDW.is_ACTIVE_k = 0;
              if (rtDW.is_ACTIVE_k != IN_READY) {
                rtDW.is_ACTIVE_k = IN_READY;
                rtDW.stateFb = (uint16_T)AUTOX_READY;
                rtDW.autoXCounter_o = AUTOX_WORK_RATE_ms;
                Clutch_setValue(55);
                checkShift();
              }
            } else {
              tmp = rtDW.autoXCounter_o - 1;
              if (tmp < 0) {
                tmp = 0;
              }

              rtDW.autoXCounter_o = (uint16_T)tmp;
            }
            break;
          }
        }
        break;

       case IN_STOPPING:
        rtDW.is_LAUNCH1 = 0;
        rtDW.is_ACCELERATION_PID = 0;
        if (rtDW.is_ACCELERATION_PID != IN_DEFAULT_j) {
          rtDW.is_ACCELERATION_PID = IN_DEFAULT_j;
          rtDW.stateFb = (uint16_T)AUTOX_DEFAULT;
          checkShift();
          checkClutch();
        }
        break;
      }
      break;

     case IN_LAUNCH2:
      LAUNCH2();
      break;

     case IN_LAUNCH3:
      LAUNCH3();
      break;

     case IN_LAUNCH4:
      LAUNCH4();
      break;

     case IN_LAUNCH5:
      LAUNCH5();
      break;

     case IN_LAUNCH6:
      LAUNCH6();
      break;

     case IN_LAUNCH7:
      LAUNCH7();
      break;

     case IN_LAUNCH8:
      LAUNCH8();
      break;

     case IN_LAUNCH9:
      LAUNCH9();
      break;
    }
  }
}

/* Function for Chart: '<S5>/GCULogic' */
static void AUTOCROSS(void)
{
  int32_T q0;
  int32_T q1;
  int64_T tmp;
  uint16_T tmp_0;
  uint8_T tmp_1;
  if ((rtDW.RateTransition8[0] != rtDW.lastModeCom[0]) && (rtDW.RateTransition8
       [1] != rtDW.lastModeCom[1])) {
    /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
    UnsetRPMLimiter();

    /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
    rtDW.stateFb = (uint16_T)ACC_OFF;
    Clutch_setValue(0);
    if (rtDW.RateTransition8[1] == ENDURANCE_MODE) {
      rtDW.is_ACTIVE_m = 0;
      rtDW.is_LAUNCH = 0;
      rtDW.is_AUTOCROSS = 0;
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        enter_atomic_MANUAL_MODES();
      }

      rtDW.is_MANUAL_MODES = IN_ENDURANCE;
    } else if (rtDW.RateTransition8[1] == SKIDPAD_MODE) {
      rtDW.is_ACTIVE_m = 0;
      rtDW.is_LAUNCH = 0;
      rtDW.is_AUTOCROSS = 0;
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        enter_atomic_MANUAL_MODES();
      }

      if (rtDW.is_MANUAL_MODES != IN_SKIDPAD) {
        rtDW.is_MANUAL_MODES = IN_SKIDPAD;

        /* Outputs for Function Call SubSystem: '<S45>/SetRPMLimiter' */
        SetRPMLimiter();

        /* End of Outputs for SubSystem: '<S45>/SetRPMLimiter' */
      }
    } else if (rtDW.RateTransition8[1] == ACCELERATION_MODE) {
      rtDW.is_ACTIVE_m = 0;
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
      rtDW.is_ACTIVE_m = 0;
      rtDW.is_LAUNCH = 0;
      rtDW.is_AUTOCROSS = 0;
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_ACCELERATION_PID) {
        rtDW.is_MODES = IN_ACCELERATION_PID;
        rtDW.lastAutoXCom = rtDW.RateTransition29[0];
        rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
        rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
      }

      if (rtDW.is_ACCELERATION_PID != IN_DEFAULT_j) {
        rtDW.is_ACCELERATION_PID = IN_DEFAULT_j;
        rtDW.stateFb = (uint16_T)AUTOX_DEFAULT;
        checkShift();
        checkClutch();
      }
    } else {
      rtDW.is_ACTIVE_m = 0;
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

      rtDW.is_MANUAL_MODES = IN_ENDURANCE;
    }
  } else {
    switch (rtDW.is_AUTOCROSS) {
     case IN_DEFAULT_j:
      if ((rtDW.RateTransition29[0] != rtDW.lastAutoXCom) &&
          (rtDW.RateTransition29[1] == AUTOX_READY)) {
        rtDW.lastAutoXCom = rtDW.RateTransition29[0];
        rtDW.is_AUTOCROSS = IN_LAUNCH;
        rtDW.autoXCounter = 0U;
        rtDW.autoX_clutchValue = 0.0;
        rtDW.autoX_clutchStep = 0.0;
        rtDW.autoX_dtRelease = 0;
        rtDW.is_LAUNCH = IN_ACTIVE;
        if (rtDW.is_ACTIVE_m != IN_START) {
          rtDW.is_ACTIVE_m = IN_START;
          rtDW.stateFb = (uint16_T)AUTOX_READY;
          rtDW.autoXCounter = AUTOX_WORK_RATE_ms;

          /* Outputs for Function Call SubSystem: '<S45>/SetRPMLimiter' */
          SetRPMLimiter();

          /* End of Outputs for SubSystem: '<S45>/SetRPMLimiter' */
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
          rtDW.is_ACTIVE_m = 0;
          rtDW.is_LAUNCH = 0;
          if (rtDW.is_LAUNCH != IN_STOPPING) {
            rtDW.is_LAUNCH = IN_STOPPING;

            /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
            UnsetRPMLimiter();

            /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
            Clutch_setValue(0);
          }
        } else {
          switch (rtDW.is_ACTIVE_m) {
           case IN_READY:
            if (rtDW.autoXCounter <= 1) {
              if ((rtDW.RateTransition29[0] != rtDW.lastAutoXCom) &&
                  (rtDW.RateTransition29[1] == AUTOX_GO) &&
                  (rtDW.RateTransition36[2] >= getAutoXParam
                   (AUTOX_TPS_START_LIMIT))) {
                rtDW.lastAutoXCom = rtDW.RateTransition29[0];
                rtDW.is_ACTIVE_m = 0;
                if (rtDW.is_ACTIVE_m != IN_START_RELEASE) {
                  rtDW.is_ACTIVE_m = IN_START_RELEASE;
                  rtDW.stateFb = (uint16_T)AUTOX_GO;
                  rtDW.autoX_clutchValue = getAutoXParam(AUTOX_RAMP_START);
                  if (rtDW.autoX_clutchValue < 256.0) {
                    if (rtDW.autoX_clutchValue >= 0.0) {
                      tmp_1 = (uint8_T)rtDW.autoX_clutchValue;
                    } else {
                      tmp_1 = 0U;
                    }
                  } else {
                    tmp_1 = MAX_uint8_T;
                  }

                  Clutch_setValue(tmp_1);
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
                rtDW.is_ACTIVE_m = 0;
                if (rtDW.is_ACTIVE_m != IN_READY) {
                  rtDW.is_ACTIVE_m = IN_READY;
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

                /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
                UnsetRPMLimiter();

                /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
                rtDW.is_ACTIVE_m = 0;
                if (rtDW.is_ACTIVE_m != IN_RUNNING) {
                  rtDW.is_ACTIVE_m = IN_RUNNING;
                  rtDW.autoXCounter = AUTOX_WORK_RATE_ms;
                  tmp_0 = rtDW.RateTransition36[6];
                  if (rtDW.RateTransition36[6] > 255) {
                    tmp_0 = 255U;
                  }

                  rtDW.lastShift = (uint8_T)tmp_0;
                  autoXCheckShift();
                }
              } else {
                rtDW.is_ACTIVE_m = 0;
                if (rtDW.is_ACTIVE_m != IN_RELEASING) {
                  rtDW.is_ACTIVE_m = IN_RELEASING;
                  rtDW.autoX_clutchValue -= rtDW.autoX_clutchStep;
                  if (rtDW.autoX_clutchValue < 256.0) {
                    if (rtDW.autoX_clutchValue >= 0.0) {
                      tmp_1 = (uint8_T)rtDW.autoX_clutchValue;
                    } else {
                      tmp_1 = 0U;
                    }
                  } else {
                    tmp_1 = MAX_uint8_T;
                  }

                  Clutch_setValue(tmp_1);
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
            if ((rtDW.RateTransition36[6] >= rtDW.UnitDelay2[(uint8_T)
                 AUTOX_END_GEAR]) && (rtDW.RateTransition36[6] != 8)) {
              rtDW.is_ACTIVE_m = 0;
              rtDW.is_LAUNCH = 0;
              if (rtDW.is_LAUNCH != IN_STOPPING) {
                rtDW.is_LAUNCH = IN_STOPPING;

                /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
                UnsetRPMLimiter();

                /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
                Clutch_setValue(0);
              }
            } else {
              autoXCheckShift();
            }
            break;

           case IN_START:
            if (rtDW.autoXCounter <= 1) {
              rtDW.is_ACTIVE_m = 0;
              if (rtDW.is_ACTIVE_m != IN_READY) {
                rtDW.is_ACTIVE_m = IN_READY;
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
              rtDW.is_ACTIVE_m = 0;
              if (rtDW.is_ACTIVE_m != IN_RELEASING) {
                rtDW.is_ACTIVE_m = IN_RELEASING;
                rtDW.autoX_clutchValue -= rtDW.autoX_clutchStep;
                if (rtDW.autoX_clutchValue < 256.0) {
                  if (rtDW.autoX_clutchValue >= 0.0) {
                    tmp_1 = (uint8_T)rtDW.autoX_clutchValue;
                  } else {
                    tmp_1 = 0U;
                  }
                } else {
                  tmp_1 = MAX_uint8_T;
                }

                Clutch_setValue(tmp_1);
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
        if (rtDW.is_AUTOCROSS != IN_DEFAULT_j) {
          rtDW.is_AUTOCROSS = IN_DEFAULT_j;
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

   case IN_ACCELERATION_PID:
    ACCELERATION_PID();
    break;

   case IN_AUTOCROSS:
    AUTOCROSS();
    break;

   case IN_INIT_k:
    if (rtDW.buzzerCounter >= 1000) {
      /* Outputs for Function Call SubSystem: '<S43>/BuzzerOff' */

      /* S-Function (stopBuzzer): '<S55>/BuzzerOff' */
      stopBuzzer_Outputs_wrapper();

      /* End of Outputs for SubSystem: '<S43>/BuzzerOff' */
      if (rtDW.RateTransition8[1] == ENDURANCE_MODE) {
        rtDW.is_MODES = 0;
        if (rtDW.is_MODES != IN_MANUAL_MODES) {
          rtDW.is_MODES = IN_MANUAL_MODES;
          rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
          rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
          checkShift();
          checkClutch();
        }

        rtDW.is_MANUAL_MODES = IN_ENDURANCE;
      } else if (rtDW.RateTransition8[1] == SKIDPAD_MODE) {
        rtDW.is_MODES = 0;
        if (rtDW.is_MODES != IN_MANUAL_MODES) {
          rtDW.is_MODES = IN_MANUAL_MODES;
          rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
          rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
          checkShift();
          checkClutch();
        }

        if (rtDW.is_MANUAL_MODES != IN_SKIDPAD) {
          rtDW.is_MANUAL_MODES = IN_SKIDPAD;

          /* Outputs for Function Call SubSystem: '<S45>/SetRPMLimiter' */
          SetRPMLimiter();

          /* End of Outputs for SubSystem: '<S45>/SetRPMLimiter' */
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
        if (rtDW.is_MODES != IN_ACCELERATION_PID) {
          rtDW.is_MODES = IN_ACCELERATION_PID;
          rtDW.lastAutoXCom = rtDW.RateTransition29[0];
          rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
          rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
        }

        if (rtDW.is_ACCELERATION_PID != IN_DEFAULT_j) {
          rtDW.is_ACCELERATION_PID = IN_DEFAULT_j;
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

        rtDW.is_MANUAL_MODES = IN_ENDURANCE;
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
        if (rtDW.is_MANUAL_MODES == IN_SKIDPAD) {
          if (rtDW.is_MANUAL_MODES == IN_SKIDPAD) {
            /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
            UnsetRPMLimiter();

            /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
            rtDW.is_MANUAL_MODES = 0;
          }
        } else {
          rtDW.is_MANUAL_MODES = 0;
        }

        rtDW.is_MODES = 0;
        if (rtDW.is_MODES != IN_MANUAL_MODES) {
          rtDW.is_MODES = IN_MANUAL_MODES;
          rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
          rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
          checkShift();
          checkClutch();
        }

        rtDW.is_MANUAL_MODES = IN_ENDURANCE;
      } else if (rtDW.RateTransition8[1] == SKIDPAD_MODE) {
        if (rtDW.is_MANUAL_MODES == IN_SKIDPAD) {
          if (rtDW.is_MANUAL_MODES == IN_SKIDPAD) {
            /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
            UnsetRPMLimiter();

            /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
            rtDW.is_MANUAL_MODES = 0;
          }
        } else {
          rtDW.is_MANUAL_MODES = 0;
        }

        rtDW.is_MODES = 0;
        if (rtDW.is_MODES != IN_MANUAL_MODES) {
          rtDW.is_MODES = IN_MANUAL_MODES;
          rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
          rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
          checkShift();
          checkClutch();
        }

        if (rtDW.is_MANUAL_MODES != IN_SKIDPAD) {
          rtDW.is_MANUAL_MODES = IN_SKIDPAD;

          /* Outputs for Function Call SubSystem: '<S45>/SetRPMLimiter' */
          SetRPMLimiter();

          /* End of Outputs for SubSystem: '<S45>/SetRPMLimiter' */
        }
      } else if (rtDW.RateTransition8[1] == ACCELERATION_MODE) {
        if (rtDW.is_MANUAL_MODES == IN_SKIDPAD) {
          if (rtDW.is_MANUAL_MODES == IN_SKIDPAD) {
            /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
            UnsetRPMLimiter();

            /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
            rtDW.is_MANUAL_MODES = 0;
          }
        } else {
          rtDW.is_MANUAL_MODES = 0;
        }

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
        if (rtDW.is_MANUAL_MODES == IN_SKIDPAD) {
          if (rtDW.is_MANUAL_MODES == IN_SKIDPAD) {
            /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
            UnsetRPMLimiter();

            /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
            rtDW.is_MANUAL_MODES = 0;
          }
        } else {
          rtDW.is_MANUAL_MODES = 0;
        }

        rtDW.is_MODES = 0;
        if (rtDW.is_MODES != IN_ACCELERATION_PID) {
          rtDW.is_MODES = IN_ACCELERATION_PID;
          rtDW.lastAutoXCom = rtDW.RateTransition29[0];
          rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
          rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
        }

        if (rtDW.is_ACCELERATION_PID != IN_DEFAULT_j) {
          rtDW.is_ACCELERATION_PID = IN_DEFAULT_j;
          rtDW.stateFb = (uint16_T)AUTOX_DEFAULT;
          checkShift();
          checkClutch();
        }
      } else {
        if (rtDW.is_MANUAL_MODES == IN_SKIDPAD) {
          if (rtDW.is_MANUAL_MODES == IN_SKIDPAD) {
            /* Outputs for Function Call SubSystem: '<S45>/UnsetRPMLimiter' */
            UnsetRPMLimiter();

            /* End of Outputs for SubSystem: '<S45>/UnsetRPMLimiter' */
            rtDW.is_MANUAL_MODES = 0;
          }
        } else {
          rtDW.is_MANUAL_MODES = 0;
        }

        rtDW.is_MODES = 0;
        if (rtDW.is_MODES != IN_MANUAL_MODES) {
          rtDW.is_MODES = IN_MANUAL_MODES;
          rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
          rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
          checkShift();
          checkClutch();
        }

        rtDW.is_MANUAL_MODES = IN_ENDURANCE;
      }
    } else {
      checkShift();
      checkClutch();
    }
    break;
  }
}

/* Function for Chart: '<S3>/EEPROM_OutputRequest' */
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

/* Function for Chart: '<S3>/EEPROM_OutputRequest' */
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

/* Function for Chart: '<S3>/EEPROM_OutputRequest' */
static void shiftArray_hs(const int32_T array[13], real_T nValues)
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

/* Function for Chart: '<S3>/EEPROM_OutputRequest' */
static void shiftArray(const int32_T array[3], real_T nValues)
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

/* Function for Chart: '<S3>/EEPROM_OutputRequest' */
static void shiftArray_h(const int32_T array[23], real_T nValues)
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

/* Function for Chart: '<S3>/EEPROM_OutputRequest' */
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

/* Function for Chart: '<S3>/EEPROM_OutputRequest' */
static void testIndex(uint8_T *page, uint8_T *cell, uint8_T *dataSize)
{
  if (rtDW.RateTransition1 != rtDW.lastEvaluatedIndex) {
    updateOutput();

    /* Outputs for Function Call SubSystem: '<S3>/Evaluate_Request' */
    Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                     rtDW.load_default_timings, rtDW.load_accParameters1,
                     rtDW.load_antiStall_default, &rtDW.Eeprom_write_o1,
                     &rtDW.Eeprom_read_o1, &rtDW.Eeprom_write_o2, rtDW.Merge_d,
                     rtDW.Merge1, rtDW.Merge2, rtDW.Merge3, page, cell, dataSize,
                     rtDW.Eeprom_read_o2, &rtDW.Evaluate_Request_l);

    /* End of Outputs for SubSystem: '<S3>/Evaluate_Request' */
    if (rtDW.outputRequest.operation == 87) {
      rtDW.reloadFlag = 1.0;
    }
  }
}

/* Function for Chart: '<S42>/antiStallLogic' */
static int32_T getAntiStallParam(anti_stall_params b_index, const int32_T
  UnitDelay3[8])
{
  return UnitDelay3[b_index];
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

/* Function for Chart: '<S3>/EEPROM_Load_Buffer' */
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
  uint8_T rtb_RateTransition33;
  uint8_T Merge_b;
  int32_T UnitDelay3[8];
  uint8_T cell;
  uint8_T dataSize;
  int32_T i;
  uint8_T tmp[16];
  int32_T i_0;

  /* UnitDelay: '<Root>/Unit Delay' */
  memcpy(&rtDW.UnitDelay[0], &rtDW.UnitDelay_DSTATE_b[0], sizeof(int32_T) << 4U);

  /* UnitDelay: '<Root>/Unit Delay1' */
  memcpy(&rtDW.UnitDelay1[0], &rtDW.UnitDelay1_DSTATE[0], 24U * sizeof(int32_T));

  /* UnitDelay: '<Root>/Unit Delay2' */
  memcpy(&rtDW.UnitDelay2[0], &rtDW.UnitDelay2_DSTATE[0], sizeof(int32_T) << 4U);

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

  /* UnitDelay: '<Root>/Unit Delay3' */
  for (i = 0; i < 8; i++) {
    UnitDelay3[i] = rtDW.UnitDelay3_DSTATE[i];
  }

  /* End of UnitDelay: '<Root>/Unit Delay3' */

  /* RateTransition: '<Root>/Rate Transition30' */
  rtDW.RateTransition30 = rtDW.RateTransition30_Buffer0;

  /* RateTransition: '<Root>/Rate Transition33' */
  rtb_RateTransition33 = rtDW.RateTransition33_Buffer0;

  /* RateTransition: '<Root>/Rate Transition34' */
  rtDW.RateTransition34 = rtDW.RateTransition34_Buffer0;

  /* RateTransition: '<Root>/Rate Transition35' */
  i = rtDW.RateTransition35_ActiveBufIdx * 9;
  for (i_0 = 0; i_0 < 9; i_0++) {
    rtDW.RateTransition35[i_0] = rtDW.RateTransition35_Buffer[i_0 + i];
  }

  /* End of RateTransition: '<Root>/Rate Transition35' */

  /* RateTransition: '<Root>/Rate Transition36' */
  i = rtDW.RateTransition36_ActiveBufIdx * 7;
  for (i_0 = 0; i_0 < 7; i_0++) {
    rtDW.RateTransition36[i_0] = rtDW.RateTransition36_Buffer[i_0 + i];
  }

  /* End of RateTransition: '<Root>/Rate Transition36' */

  /* RateTransition: '<Root>/Rate Transition1' */
  rtDW.RateTransition1_b = rtDW.RateTransition1_Buffer0_m;

  /* RateTransition: '<Root>/Rate Transition40' */
  rtDW.RateTransition40 = rtDW.RateTransition40_Buffer0;

  /* RateTransition: '<Root>/Rate Transition41' */
  rtDW.RateTransition41 = rtDW.RateTransition41_Buffer0;

  /* RateTransition: '<Root>/Rate Transition42' */
  rtDW.RateTransition42 = rtDW.RateTransition42_Buffer0;

  /* RateTransition: '<S3>/Rate Transition' */
  i = rtDW.RateTransition_ActiveBufIdx * 20;
  for (i_0 = 0; i_0 < 20; i_0++) {
    rtDW.RateTransition[i_0] = rtDW.RateTransition_Buffer[i_0 + i];
  }

  /* End of RateTransition: '<S3>/Rate Transition' */

  /* RateTransition: '<S3>/Rate Transition1' */
  rtDW.RateTransition1 = rtDW.RateTransition1_Buffer0;

  /* Outputs for Atomic SubSystem: '<Root>/GCU_timer' */
  /* DiscreteStateSpace: '<S47>/Internal' */
  {
    rtb_Internal = 0.24359453030282938*rtDW.Internal_DSTATE;
  }

  /* DataTypeConversion: '<S5>/Cast1' incorporates:
   *  Constant: '<S5>/Constant'
   *  Sum: '<S5>/Sum'
   */
  rtDW.Cast1_k = (uint8_T)(rtb_Internal + 1.0);

  /* UnitDelay: '<S5>/Unit Delay' */
  rtDW.UnitDelay_b = rtDW.UnitDelay_DSTATE_o;

  /* UnitDelay: '<S5>/Unit Delay1' */
  rtDW.UnitDelay1_i = rtDW.UnitDelay1_DSTATE_j;

  /* Chart: '<S5>/GCULogic' */
  rtDW.sfEvent = -1;
  if (rtDW.is_active_c1_GCU_Model_genCode == 0U) {
    rtDW.is_active_c1_GCU_Model_genCode = 1U;
    rtDW.is_active_MODES = 1U;
    rtDW.lastAacCom = 0U;
    rtDW.lastShiftCom = 0U;
    rtDW.lastAutoXCom = 0U;
    rtDW.buzzerCounter = 0U;
    if (rtDW.is_MODES != IN_INIT_k) {
      rtDW.is_MODES = IN_INIT_k;

      /* Outputs for Function Call SubSystem: '<S43>/BuzzerOn' */

      /* S-Function (activateBuzzer): '<S56>/BuzzerOn' */
      activateBuzzer_Outputs_wrapper();

      /* End of Outputs for SubSystem: '<S43>/BuzzerOn' */
    }

    rtDW.is_active_NEUTRAL_STATE = 1U;
    rtDW.is_NEUTRAL_STATE = IN_NEUTRAL;
    if (rtDW.is_active_GEARSHIFT != 1U) {
      rtDW.is_active_GEARSHIFT = 1U;
      rtDW.ticksCounter = 0;
    }

    if (rtDW.is_GEARSHIFT != IN_INIT_k) {
      rtDW.is_GEARSHIFT = IN_INIT_k;
      rtDW.ticksCounter = 0;
    }

    rtDW.is_active_START_ENGINE = 1U;
    rtDW.lastCom = 0U;
    rtDW.startCounter = 0U;
    rtDW.is_START_ENGINE = IN_WAIT_c;
    if (rtDW.is_active_SCAN_ADC != 1U) {
      rtDW.is_active_SCAN_ADC = 1U;
    }

    if (rtDW.is_SCAN_ADC != IN_SCAN) {
      rtDW.is_SCAN_ADC = IN_SCAN;

      /* Outputs for Function Call SubSystem: '<S48>/SCAN_ADC.ScanADC' */
      SCAN_ADCScanADC();

      /* End of Outputs for SubSystem: '<S48>/SCAN_ADC.ScanADC' */
    }

    rtDW.is_active_EEPROM_TRIGGER = 1U;
    rtDW.counterWait = 0.0;
    if (rtDW.is_EEPROM_TRIGGER != IN_WAIT) {
      rtDW.is_EEPROM_TRIGGER = IN_WAIT;
      rtDW.counterWait = 1.0;
    }

    rtDW.is_active_ANTISTALL_ENABLE = 1U;
    if (rtDW.is_ANTISTALL_ENABLE != IN_DISABLE) {
      rtDW.is_ANTISTALL_ENABLE = IN_DISABLE;
      rtDW.antiStallEnable = 0U;
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
       case IN_START_j:
        if (rtDW.startCounter <= 0) {
          rtDW.is_START_ENGINE = 0;
          if (rtDW.is_START_ENGINE != IN_STOP) {
            rtDW.is_START_ENGINE = IN_STOP;

            /* Outputs for Function Call SubSystem: '<S46>/EngineControl_Stop' */

            /* S-Function (EngineControl_stop): '<S64>/EngineControl Stop' */
            EngineControl_stop_Outputs_wrapper(&rtDW.EngineControlStop);

            /* End of Outputs for SubSystem: '<S46>/EngineControl_Stop' */
          }
        } else if (rtDW.RateTransition3 != rtDW.lastCom) {
          rtDW.is_START_ENGINE = 0;
          if (rtDW.is_START_ENGINE != IN_START_j) {
            rtDW.is_START_ENGINE = IN_START_j;

            /* Outputs for Function Call SubSystem: '<S46>/EngineControl_Start' */
            EngineControl_Start(&Merge_b, &rtDW.EngineControl_Start_h);

            /* End of Outputs for SubSystem: '<S46>/EngineControl_Start' */
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
          if (rtDW.is_START_ENGINE != IN_START_j) {
            rtDW.is_START_ENGINE = IN_START_j;

            /* Outputs for Function Call SubSystem: '<S46>/EngineControl_Start' */
            EngineControl_Start(&Merge_b, &rtDW.EngineControl_Start_h);

            /* End of Outputs for SubSystem: '<S46>/EngineControl_Start' */
            rtDW.lastCom = rtDW.RateTransition3;
            rtDW.startCounter = 100U;
          }
        }
        break;

       case IN_WAIT_c:
        if (rtDW.RateTransition3 != rtDW.lastCom) {
          rtDW.is_START_ENGINE = 0;
          if (rtDW.is_START_ENGINE != IN_START_j) {
            rtDW.is_START_ENGINE = IN_START_j;

            /* Outputs for Function Call SubSystem: '<S46>/EngineControl_Start' */
            EngineControl_Start(&Merge_b, &rtDW.EngineControl_Start_h);

            /* End of Outputs for SubSystem: '<S46>/EngineControl_Start' */
            rtDW.lastCom = rtDW.RateTransition3;
            rtDW.startCounter = 100U;
          }
        }
        break;
      }
    }

    if (!((rtDW.is_active_SCAN_ADC == 0U) || (rtDW.is_SCAN_ADC != IN_SCAN))) {
      /* Outputs for Function Call SubSystem: '<S48>/SCAN_ADC.ScanADC' */
      SCAN_ADCScanADC();

      /* End of Outputs for SubSystem: '<S48>/SCAN_ADC.ScanADC' */
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

            /* Chart: '<S3>/EEPROM_OutputRequest' */
            /* Chart: '<S3>/EEPROM_OutputRequest' */
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

                /* Outputs for Function Call SubSystem: '<S3>/Evaluate_Request' */
                Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                                 rtDW.load_default_timings,
                                 rtDW.load_accParameters1,
                                 rtDW.load_antiStall_default,
                                 &rtDW.Eeprom_write_o1, &rtDW.Eeprom_read_o1,
                                 &rtDW.Eeprom_write_o2, rtDW.Merge_d,
                                 rtDW.Merge1, rtDW.Merge2, rtDW.Merge3, &Merge_b,
                                 &cell, &dataSize, rtDW.Eeprom_read_o2,
                                 &rtDW.Evaluate_Request_l);

                /* End of Outputs for SubSystem: '<S3>/Evaluate_Request' */
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

                /* Outputs for Function Call SubSystem: '<S3>/Evaluate_Request' */
                Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                                 rtDW.load_default_timings,
                                 rtDW.load_accParameters1,
                                 rtDW.load_antiStall_default,
                                 &rtDW.Eeprom_write_o1, &rtDW.Eeprom_read_o1,
                                 &rtDW.Eeprom_write_o2, rtDW.Merge_d,
                                 rtDW.Merge1, rtDW.Merge2, rtDW.Merge3, &Merge_b,
                                 &cell, &dataSize, rtDW.Eeprom_read_o2,
                                 &rtDW.Evaluate_Request_l);

                /* End of Outputs for SubSystem: '<S3>/Evaluate_Request' */
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

                /* Outputs for Function Call SubSystem: '<S3>/Evaluate_Request' */
                Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                                 rtDW.load_default_timings,
                                 rtDW.load_accParameters1,
                                 rtDW.load_antiStall_default,
                                 &rtDW.Eeprom_write_o1, &rtDW.Eeprom_read_o1,
                                 &rtDW.Eeprom_write_o2, rtDW.Merge_d,
                                 rtDW.Merge1, rtDW.Merge2, rtDW.Merge3, &Merge_b,
                                 &cell, &dataSize, rtDW.Eeprom_read_o2,
                                 &rtDW.Evaluate_Request_l);

                /* End of Outputs for SubSystem: '<S3>/Evaluate_Request' */
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

                  /* Outputs for Function Call SubSystem: '<S3>/Evaluate_Request' */
                  Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                                   rtDW.load_default_timings,
                                   rtDW.load_accParameters1,
                                   rtDW.load_antiStall_default,
                                   &rtDW.Eeprom_write_o1, &rtDW.Eeprom_read_o1,
                                   &rtDW.Eeprom_write_o2, rtDW.Merge_d,
                                   rtDW.Merge1, rtDW.Merge2, rtDW.Merge3,
                                   &Merge_b, &cell, &dataSize,
                                   rtDW.Eeprom_read_o2, &rtDW.Evaluate_Request_l);

                  /* End of Outputs for SubSystem: '<S3>/Evaluate_Request' */
                  if ((uint32_T)i > 255U) {
                    i = 255;
                  }

                  rtDW.counter = (uint8_T)i;
                }
                break;

               case IN_ANTI_STALL_PARAMETERS:
                if (rtDW.counter >= 11) {
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

                  /* Outputs for Function Call SubSystem: '<S3>/Evaluate_Request' */
                  Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                                   rtDW.load_default_timings,
                                   rtDW.load_accParameters1,
                                   rtDW.load_antiStall_default,
                                   &rtDW.Eeprom_write_o1, &rtDW.Eeprom_read_o1,
                                   &rtDW.Eeprom_write_o2, rtDW.Merge_d,
                                   rtDW.Merge1, rtDW.Merge2, rtDW.Merge3,
                                   &Merge_b, &cell, &dataSize,
                                   rtDW.Eeprom_read_o2, &rtDW.Evaluate_Request_l);

                  /* End of Outputs for SubSystem: '<S3>/Evaluate_Request' */
                  if ((uint32_T)i > 255U) {
                    i = 255;
                  }

                  rtDW.counter = (uint8_T)i;
                }
                break;

               case IN_AUTOX_PARAMETERS:
                if (rtDW.counter >= 9) {
                  rtDW.is_LOAD_FROM_EEPROM = IN_ANTI_STALL_PARAMETERS;
                  rtDW.counter = 10U;
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

                  /* Outputs for Function Call SubSystem: '<S3>/Evaluate_Request' */
                  Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                                   rtDW.load_default_timings,
                                   rtDW.load_accParameters1,
                                   rtDW.load_antiStall_default,
                                   &rtDW.Eeprom_write_o1, &rtDW.Eeprom_read_o1,
                                   &rtDW.Eeprom_write_o2, rtDW.Merge_d,
                                   rtDW.Merge1, rtDW.Merge2, rtDW.Merge3,
                                   &Merge_b, &cell, &dataSize,
                                   rtDW.Eeprom_read_o2, &rtDW.Evaluate_Request_l);

                  /* End of Outputs for SubSystem: '<S3>/Evaluate_Request' */
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

                  /* Outputs for Function Call SubSystem: '<S3>/Evaluate_Request' */
                  Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                                   rtDW.load_default_timings,
                                   rtDW.load_accParameters1,
                                   rtDW.load_antiStall_default,
                                   &rtDW.Eeprom_write_o1, &rtDW.Eeprom_read_o1,
                                   &rtDW.Eeprom_write_o2, rtDW.Merge_d,
                                   rtDW.Merge1, rtDW.Merge2, rtDW.Merge3,
                                   &Merge_b, &cell, &dataSize,
                                   rtDW.Eeprom_read_o2, &rtDW.Evaluate_Request_l);

                  /* End of Outputs for SubSystem: '<S3>/Evaluate_Request' */
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
                  shiftArray_hs(rtDW.load_accParameters1, 13.0);
                } else {
                  extractValues(rtDW.counter);
                  i = (int32_T)(rtDW.counter + 5U);
                  if ((uint32_T)i > 255U) {
                    i = 255;
                  }

                  createRequest(87, (uint8_T)i, 0, 16, rtDW.newData);

                  /* Outputs for Function Call SubSystem: '<S3>/Evaluate_Request' */
                  Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                                   rtDW.load_default_timings,
                                   rtDW.load_accParameters1,
                                   rtDW.load_antiStall_default,
                                   &rtDW.Eeprom_write_o1, &rtDW.Eeprom_read_o1,
                                   &rtDW.Eeprom_write_o2, rtDW.Merge_d,
                                   rtDW.Merge1, rtDW.Merge2, rtDW.Merge3,
                                   &Merge_b, &cell, &dataSize,
                                   rtDW.Eeprom_read_o2, &rtDW.Evaluate_Request_l);

                  /* End of Outputs for SubSystem: '<S3>/Evaluate_Request' */
                  i = (int32_T)(rtDW.counter + 1U);
                  if ((uint32_T)i > 255U) {
                    i = 255;
                  }

                  rtDW.counter = (uint8_T)i;
                }
                break;

               case IN_ANTI_STALL_PARAMETERS:
                if (rtDW.counter >= 1) {
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

                  /* Outputs for Function Call SubSystem: '<S3>/Evaluate_Request' */
                  Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                                   rtDW.load_default_timings,
                                   rtDW.load_accParameters1,
                                   rtDW.load_antiStall_default,
                                   &rtDW.Eeprom_write_o1, &rtDW.Eeprom_read_o1,
                                   &rtDW.Eeprom_write_o2, rtDW.Merge_d,
                                   rtDW.Merge1, rtDW.Merge2, rtDW.Merge3,
                                   &Merge_b, &cell, &dataSize,
                                   rtDW.Eeprom_read_o2, &rtDW.Evaluate_Request_l);

                  /* End of Outputs for SubSystem: '<S3>/Evaluate_Request' */
                  i = (int32_T)(rtDW.counter + 1U);
                  if ((uint32_T)i > 255U) {
                    i = 255;
                  }

                  rtDW.counter = (uint8_T)i;
                } else {
                  extractValues(rtDW.counter);
                  i = (int32_T)(rtDW.counter + 11U);
                  if ((uint32_T)i > 255U) {
                    i = 255;
                  }

                  createRequest(87, (uint8_T)i, 0, 16, rtDW.newData);

                  /* Outputs for Function Call SubSystem: '<S3>/Evaluate_Request' */
                  Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                                   rtDW.load_default_timings,
                                   rtDW.load_accParameters1,
                                   rtDW.load_antiStall_default,
                                   &rtDW.Eeprom_write_o1, &rtDW.Eeprom_read_o1,
                                   &rtDW.Eeprom_write_o2, rtDW.Merge_d,
                                   rtDW.Merge1, rtDW.Merge2, rtDW.Merge3,
                                   &Merge_b, &cell, &dataSize,
                                   rtDW.Eeprom_read_o2, &rtDW.Evaluate_Request_l);

                  /* End of Outputs for SubSystem: '<S3>/Evaluate_Request' */
                  i = (int32_T)(rtDW.counter + 1U);
                  if ((uint32_T)i > 255U) {
                    i = 255;
                  }

                  rtDW.counter = (uint8_T)i;
                }
                break;

               case IN_AUTOX_PARAMETERS:
                if (rtDW.counter >= 2) {
                  rtDW.counter = 0U;
                  rtDW.is_LOAD_TO_EEPROM = IN_ANTI_STALL_PARAMETERS;
                  shiftArray(rtDW.load_antiStall_default, 3.0);
                } else {
                  extractValues(rtDW.counter);
                  i = (int32_T)(rtDW.counter + 8U);
                  if ((uint32_T)i > 255U) {
                    i = 255;
                  }

                  createRequest(87, (uint8_T)i, 0, 16, rtDW.newData);

                  /* Outputs for Function Call SubSystem: '<S3>/Evaluate_Request' */
                  Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                                   rtDW.load_default_timings,
                                   rtDW.load_accParameters1,
                                   rtDW.load_antiStall_default,
                                   &rtDW.Eeprom_write_o1, &rtDW.Eeprom_read_o1,
                                   &rtDW.Eeprom_write_o2, rtDW.Merge_d,
                                   rtDW.Merge1, rtDW.Merge2, rtDW.Merge3,
                                   &Merge_b, &cell, &dataSize,
                                   rtDW.Eeprom_read_o2, &rtDW.Evaluate_Request_l);

                  /* End of Outputs for SubSystem: '<S3>/Evaluate_Request' */
                  i = (int32_T)(rtDW.counter + 1U);
                  if ((uint32_T)i > 255U) {
                    i = 255;
                  }

                  rtDW.counter = (uint8_T)i;
                }
                break;

               case IN_FIRST_BYTE:
                rtDW.is_LOAD_TO_EEPROM = IN_GEARSHIFT_TIMINGS;
                shiftArray_h(rtDW.load_default_timings, 23.0);
                extractValues(rtDW.counter);
                i = (int32_T)(rtDW.counter + 1U);
                if ((uint32_T)i > 255U) {
                  i = 255;
                }

                createRequest(87, (uint8_T)i, 0, 16, rtDW.newData);

                /* Outputs for Function Call SubSystem: '<S3>/Evaluate_Request' */
                Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                                 rtDW.load_default_timings,
                                 rtDW.load_accParameters1,
                                 rtDW.load_antiStall_default,
                                 &rtDW.Eeprom_write_o1, &rtDW.Eeprom_read_o1,
                                 &rtDW.Eeprom_write_o2, rtDW.Merge_d,
                                 rtDW.Merge1, rtDW.Merge2, rtDW.Merge3, &Merge_b,
                                 &cell, &dataSize, rtDW.Eeprom_read_o2,
                                 &rtDW.Evaluate_Request_l);

                /* End of Outputs for SubSystem: '<S3>/Evaluate_Request' */
                i = (int32_T)(rtDW.counter + 1U);
                if ((uint32_T)i > 255U) {
                  i = 255;
                }

                rtDW.counter = (uint8_T)i;
                break;

               default:
                if (rtDW.counter >= 3) {
                  rtDW.counter = 0U;
                  rtDW.is_LOAD_TO_EEPROM = IN_ACC_PARAMETERS;
                  shiftArray_hs(rtDW.load_accParameters, 13.0);
                } else {
                  extractValues(rtDW.counter);
                  i = (int32_T)(rtDW.counter + 1U);
                  i_0 = i;
                  if ((uint32_T)i > 255U) {
                    i_0 = 255;
                  }

                  createRequest(87, (uint8_T)i_0, 0, 16, rtDW.newData);

                  /* Outputs for Function Call SubSystem: '<S3>/Evaluate_Request' */
                  Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                                   rtDW.load_default_timings,
                                   rtDW.load_accParameters1,
                                   rtDW.load_antiStall_default,
                                   &rtDW.Eeprom_write_o1, &rtDW.Eeprom_read_o1,
                                   &rtDW.Eeprom_write_o2, rtDW.Merge_d,
                                   rtDW.Merge1, rtDW.Merge2, rtDW.Merge3,
                                   &Merge_b, &cell, &dataSize,
                                   rtDW.Eeprom_read_o2, &rtDW.Evaluate_Request_l);

                  /* End of Outputs for SubSystem: '<S3>/Evaluate_Request' */
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
                testIndex(&Merge_b, &cell, &dataSize);
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

                /* Outputs for Function Call SubSystem: '<S3>/Evaluate_Request' */
                Evaluate_Request(&rtDW.outputRequest, rtDW.load_accParameters,
                                 rtDW.load_default_timings,
                                 rtDW.load_accParameters1,
                                 rtDW.load_antiStall_default,
                                 &rtDW.Eeprom_write_o1, &rtDW.Eeprom_read_o1,
                                 &rtDW.Eeprom_write_o2, rtDW.Merge_d,
                                 rtDW.Merge1, rtDW.Merge2, rtDW.Merge3, &Merge_b,
                                 &cell, &dataSize, rtDW.Eeprom_read_o2,
                                 &rtDW.Evaluate_Request_l);

                /* End of Outputs for SubSystem: '<S3>/Evaluate_Request' */
              }
              break;
            }

            /* End of Chart: '<S3>/EEPROM_OutputRequest' */
          }
        } else {
          rtDW.counterWait++;
        }
        break;
      }
    }

    if (rtDW.is_active_ANTISTALL_ENABLE != 0U) {
      switch (rtDW.is_ANTISTALL_ENABLE) {
       case IN_DISABLE:
        rtDW.antiStallEnable = 0U;
        if (UnitDelay3[RPM_THRESHOLD] != 0) {
          rtDW.is_ANTISTALL_ENABLE = 0;
          if (rtDW.is_ANTISTALL_ENABLE != IN_ENABLE) {
            rtDW.is_ANTISTALL_ENABLE = IN_ENABLE;
            rtDW.antiStallEnable = 1U;
          }
        }
        break;

       case IN_ENABLE:
        rtDW.antiStallEnable = 1U;
        break;
      }
    }
  }

  /* End of Chart: '<S5>/GCULogic' */

  /* Outputs for Atomic SubSystem: '<S5>/Anti_Stall_System' */
  /* Chart: '<S42>/timeCounter' incorporates:
   *  UnitDelay: '<S42>/Unit Delay'
   */
  rtDW.timeMs++;
  if (rtb_RateTransition33 != rtDW.last_rpmUpdate) {
    rtDW.deltaTime = rtDW.timeMs;
    rtDW.timeMs = 0.0;
    rtDW.last_rpmUpdate = rtb_RateTransition33;
    rtDW.last_rpmValue = rtDW.UnitDelay_DSTATE_e;
  }

  /* End of Chart: '<S42>/timeCounter' */

  /* Outport: '<Root>/antiStallState' incorporates:
   *  Chart: '<S42>/antiStallLogic'
   */
  rtY.antiStallState = 0.0;

  /* Chart: '<S42>/antiStallLogic' incorporates:
   *  Constant: '<S42>/Constant'
   *  DataTypeConversion: '<S42>/Cast To Double'
   *  DataTypeConversion: '<S42>/Cast To Double1'
   *  Product: '<S42>/Divide'
   *  Product: '<S42>/Multiply'
   *  Sum: '<S42>/Minus'
   */
  if (rtDW.antiStallEnable == 1) {
    /* Outport: '<Root>/antiStallState' */
    rtY.antiStallState = 1.0;
    if (rtDW.RateTransition30 == 0) {
      /* Outport: '<Root>/antiStallState' */
      rtY.antiStallState = 2.0;
      if ((rtDW.RateTransition36[1] < 20) && (rtDW.RateTransition36[6] >=
           getAntiStallParam(GEAR_THRESHOLD, UnitDelay3))) {
        /* Outport: '<Root>/antiStallState' */
        rtY.antiStallState = 3.0;
        if (rtDW.RateTransition36[0] <= getAntiStallParam(RPM_THRESHOLD,
             UnitDelay3)) {
          /* Outport: '<Root>/antiStallState' */
          rtY.antiStallState = 4.0;
          i = getAntiStallParam(RPM_DELTA_THRESHOLD, UnitDelay3);
          if (i <= MIN_int32_T) {
            i = MAX_int32_T;
          } else {
            i = -i;
          }

          if ((real_T)(rtDW.RateTransition36[0] - rtDW.last_rpmValue) * 10.0 /
              rtDW.deltaTime <= i) {
            /* send(antiStallActivate); */
            rtDW.Inport = 0U;

            /* Outputs for Function Call SubSystem: '<S52>/AntiStallActivate' */

            /* S-Function (ClutchMotor_setPosition): '<S54>/ClutchMotor SetPosition' */
            ClutchMotor_setPosition_Outputs_wrapper(&rtDW.Inport);

            /* End of Outputs for SubSystem: '<S52>/AntiStallActivate' */
            rtDW.antiStallFb = (uint16_T)ANTISTALL_ON;

            /* Outport: '<Root>/antiStallState' */
            rtY.antiStallState = 5.0;
            rtDW.antiStallClutchVal = 100U;
          }
        }
      }
    } else {
      rtDW.antiStallFb = (uint16_T)ANTISTALL_OFF;
      rtDW.antiStallClutchVal = 0U;
    }
  }

  /* Update for UnitDelay: '<S42>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_e = rtDW.RateTransition36[0];

  /* End of Outputs for SubSystem: '<S5>/Anti_Stall_System' */

  /* DataTypeConversion: '<S5>/Cast To Double' */
  rtb_CastToDouble = rtb_RateTransition5;

  /* If: '<S5>/If' incorporates:
   *  Inport: '<S50>/In1'
   *  Inport: '<S51>/In1'
   */
  if (rtDW.antiStallClutchVal > 0) {
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem' incorporates:
     *  ActionPort: '<S50>/Action Port'
     */
    rtDW.Merge_n = rtDW.antiStallClutchVal;

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S51>/Action Port'
     */
    rtDW.Merge_n = rtDW.UnitDelay1_i;

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem1' */
  }

  /* End of If: '<S5>/If' */

  /* Update for DiscreteStateSpace: '<S47>/Internal' */
  {
    real_T xnew[1];
    xnew[0] = 0.93910136742429262*rtDW.Internal_DSTATE;
    xnew[0] += 0.25*rtb_CastToDouble;
    (void) memcpy(&rtDW.Internal_DSTATE, xnew,
                  sizeof(real_T)*1);
  }

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_o = rtDW.antiStallFb;

  /* Update for UnitDelay: '<S5>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE_j = rtDW.clutchCurrVal;

  /* End of Outputs for SubSystem: '<Root>/GCU_timer' */

  /* Outport: '<Root>/outputRequest' */
  rtY.outputRequest = rtDW.outputRequest;

  /* Outport: '<Root>/readResult' */
  rtY.readResult = rtDW.Eeprom_read_o1;

  /* Outport: '<Root>/writeResult' */
  rtY.writeResult = rtDW.Eeprom_write_o1;

  /* Outport: '<Root>/wpState' */
  rtY.wpState = rtDW.Eeprom_write_o2;

  /* Outport: '<Root>/gearshiftTimings' */
  memcpy(&rtY.gearshiftTimings[0], &rtDW.Merge_d[0], 24U * sizeof(int32_T));

  /* Outport: '<Root>/accParameters' */
  memcpy(&rtY.accParameters[0], &rtDW.Merge1[0], sizeof(int32_T) << 4U);

  /* Outport: '<Root>/autoXParameters' */
  memcpy(&rtY.autoXParameters[0], &rtDW.Merge2[0], sizeof(int32_T) << 4U);

  /* Outport: '<Root>/antiStallParameters' */
  for (i = 0; i < 8; i++) {
    rtY.antiStallParameters[i] = rtDW.Merge3[i];
  }

  /* End of Outport: '<Root>/antiStallParameters' */

  /* Outport: '<Root>/pidCounter' */
  rtY.pidCounter = rtDW.pidCounter;

  /* Update for UnitDelay: '<Root>/Unit Delay' */
  memcpy(&rtDW.UnitDelay_DSTATE_b[0], &rtDW.Merge1[0], sizeof(int32_T) << 4U);

  /* Update for UnitDelay: '<Root>/Unit Delay1' */
  memcpy(&rtDW.UnitDelay1_DSTATE[0], &rtDW.Merge_d[0], 24U * sizeof(int32_T));

  /* Update for UnitDelay: '<Root>/Unit Delay2' */
  memcpy(&rtDW.UnitDelay2_DSTATE[0], &rtDW.Merge2[0], sizeof(int32_T) << 4U);

  /* Update for UnitDelay: '<Root>/Unit Delay3' */
  for (i = 0; i < 8; i++) {
    rtDW.UnitDelay3_DSTATE[i] = rtDW.Merge3[i];
  }

  /* End of Update for UnitDelay: '<Root>/Unit Delay3' */

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  rtM->Timing.clockTick1++;
}

/* Model step function for TID2 */
void GCU_Model_genCode_step2(void)     /* Sample time: [0.001s, 0.0002s] */
{
  int32_T i;
  uint16_T tmp;

  /* RateTransition: '<Root>/Rate Transition6' */
  rtDW.RateTransition6 = rtDW.Merge_n;

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
      rtDW.MultiportSwitch[i] = 0U;
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
    rtDW.canData_ValuesArray[(uint8_T)GEAR_INDEX] = rtDW.UnpackCanUart_o2;
    rtDW.canData_ValuesArray[(uint8_T)RPM_INDEX] = rtDW.UnpackCanUart_o3;
    rtDW.canData_ValuesArray[(uint8_T)TPS_INDEX] = (uint16_T)(0.39216 * (real_T)
      rtDW.UnpackCanUart_o4);
    if (rtDW.rpmUpdateCounter >= 255) {
      rtDW.rpmUpdateCounter = 0U;
    } else {
      i = rtDW.rpmUpdateCounter + 1;
      if (i > 255) {
        i = 255;
      }

      rtDW.rpmUpdateCounter = (uint8_T)i;
    }
  } else if (rtDW.UnpackCanUart_o1 == SW_FIRE_GCU_ID) {
    sendStartEngCommand();
  } else if (rtDW.UnpackCanUart_o1 == SW_GEARSHIFT_ID) {
    sendShiftCommand(rtDW.UnpackCanUart_o2);
  } else if (rtDW.UnpackCanUart_o1 == EFI_TRACTION_CONTROL_ID) {
    rtDW.canData_ValuesArray[(uint8_T)VH_SPEED_INDEX] = (uint16_T)(0.1 * (real_T)
      rtDW.UnpackCanUart_o2);
    rtDW.canData_ValuesArray[(uint8_T)SLIP_TARGET_INDEX] = (uint16_T)(0.1 *
      (real_T)rtDW.UnpackCanUart_o3);
    rtDW.canData_ValuesArray[(uint8_T)GEAR_ADbits_INDEX] = rtDW.UnpackCanUart_o5;
    if (rtDW.slipUpdateCounter >= 255) {
      rtDW.slipUpdateCounter = 0U;
    } else {
      i = rtDW.slipUpdateCounter + 1;
      if (i > 255) {
        i = 255;
      }

      rtDW.slipUpdateCounter = (uint8_T)i;
    }

    rtDW.canData_ValuesArray[(uint8_T)SLIP_INDEX] = (uint16_T)(0.1 * (real_T)
      rtDW.UnpackCanUart_o4);
  } else if (rtDW.UnpackCanUart_o1 == SW_CLUTCH_MODE_MAP_GCU_ID) {
    tmp = rtDW.UnpackCanUart_o2;
    if (rtDW.UnpackCanUart_o2 > 255) {
      tmp = 255U;
    }

    rtDW.clutchTarget = (uint8_T)tmp;
    sendModeCommand(rtDW.UnpackCanUart_o3);
    if (rtDW.clutchTarget > CLUTCH_NOISE_LEVEL) {
      sendAccCommand((uint16_T)ACC_OFF);
      sendAutoXCommand((uint16_T)AUTOX_DEFAULT);
      rtDW.stopAntiStallCom = 1U;
    } else {
      rtDW.stopAntiStallCom = 0U;
    }

    if (rtDW.UnpackCanUart_o4 != 0) {
      rtDW.mapTarget = rtDW.UnpackCanUart_o4;
      tmp = rtDW.mapTarget;
      if (rtDW.mapTarget > 255) {
        tmp = 255U;
      }

      /* Outputs for Function Call SubSystem: '<S37>/setMap' */
      /* Outputs for IfAction SubSystem: '<S39>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S41>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S39>/If Action Subsystem' incorporates:
       *  ActionPort: '<S40>/Action Port'
       */
      /* If: '<S39>/If' incorporates:
       *  Inport: '<S40>/In1'
       *  Inport: '<S41>/In1'
       */
      rtDW.Merge_a = (uint8_T)(tmp == 1);

      /* End of Outputs for SubSystem: '<S39>/If Action Subsystem' */
      /* End of Outputs for SubSystem: '<S39>/If Action Subsystem1' */

      /* S-Function (Efi_setMap): '<S39>/SetMap' */
      Efi_setMap_Outputs_wrapper(&rtDW.Merge_a);

      /* End of Outputs for SubSystem: '<S37>/setMap' */
    }
  } else if (rtDW.UnpackCanUart_o1 == SW_OK_BUTTON_GCU_ID) {
    if (rtDW.UnpackCanUart_o2 == ACCELERATION_MODE) {
      sendAccCommand(rtDW.UnpackCanUart_o3);
      rtDW.pidSubMode = rtDW.UnpackCanUart_o4;
      if (rtDW.accCommand[1] == ACC_OFF) {
        rtDW.clutchTarget = 0U;
      }
    } else {
      if (rtDW.UnpackCanUart_o2 == AUTOX_MODE) {
        sendAutoXCommand(rtDW.UnpackCanUart_o3);
        rtDW.pidSubMode = rtDW.UnpackCanUart_o4;
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
    rtDW.RateTransition14_Buffer0[0] = rtDW.canData_ValuesArray[0];
    rtDW.RateTransition14_Buffer0[1] = rtDW.canData_ValuesArray[1];
    rtDW.RateTransition14_Buffer0[2] = rtDW.canData_ValuesArray[2];
  }

  /* End of RateTransition: '<Root>/Rate Transition14' */

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

  /* Update for RateTransition: '<Root>/Rate Transition30' */
  rtDW.RateTransition30_Buffer0 = rtDW.stopAntiStallCom;

  /* Update for RateTransition: '<Root>/Rate Transition33' */
  rtDW.RateTransition33_Buffer0 = rtDW.rpmUpdateCounter;

  /* Update for RateTransition: '<Root>/Rate Transition34' */
  rtDW.RateTransition34_Buffer0 = rtDW.slipUpdateCounter;

  /* Update for RateTransition: '<Root>/Rate Transition36' */
  for (i = 0; i < 7; i++) {
    rtDW.RateTransition36_Buffer[i + (rtDW.RateTransition36_ActiveBufIdx == 0) *
      7] = rtDW.canData_ValuesArray[i];
  }

  rtDW.RateTransition36_ActiveBufIdx = (int8_T)
    (rtDW.RateTransition36_ActiveBufIdx == 0);

  /* End of Update for RateTransition: '<Root>/Rate Transition36' */

  /* Update for RateTransition: '<Root>/Rate Transition1' */
  rtDW.RateTransition1_Buffer0_m = rtDW.pidSubMode;

  /* Update for RateTransition: '<Root>/Rate Transition42' */
  rtDW.RateTransition42_Buffer0 = rtDW.canErrorCommand;
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
  uint16_T rtb_RateTransition15;
  uint16_T rtb_RateTransition17;
  uint32_T rtb_RateTransition24;
  uint16_T rtb_RateTransition14[3];
  uint16_T Cast_n[9];
  uint16_T Cast9;
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
  rtb_RateTransition11 = rtDW.Merge_n;

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
  rtb_RateTransition15 = rtDW.canData_ValuesArray[3];

  /* RateTransition: '<Root>/Rate Transition17' */
  rtb_RateTransition17 = rtDW.canData_ValuesArray[4];

  /* RateTransition: '<Root>/Rate Transition24' */
  rtb_RateTransition24 = rtDW.pidCounter;

  /* S-Function (fcncallgen): '<Root>/Function_Call_Generator' incorporates:
   *  SubSystem: '<Root>/debugUART'
   */
  /* DataTypeConversion: '<S11>/Cast9' */
  Cast9 = (uint16_T)rtb_RateTransition24;
  for (i = 0; i < 9; i++) {
    /* DataTypeConversion: '<S11>/Cast' */
    Cast_n_0 = (uint16_T)rtb_RateTransition9[i];

    /* SignalConversion: '<S11>/TmpSignal ConversionAtPack_Uart_MessageInport1' */
    rtDW.TmpSignalConversionAtPack_Uart_[i] = Cast_n_0;

    /* DataTypeConversion: '<S11>/Cast' */
    Cast_n[i] = Cast_n_0;
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtPack_Uart_MessageInport1' incorporates:
   *  DataTypeConversion: '<S11>/Cast1'
   *  DataTypeConversion: '<S11>/Cast10'
   *  DataTypeConversion: '<S11>/Cast11'
   *  DataTypeConversion: '<S11>/Cast2'
   *  DataTypeConversion: '<S11>/Cast3'
   *  DataTypeConversion: '<S11>/Cast4'
   *  DataTypeConversion: '<S11>/Cast5'
   *  DataTypeConversion: '<S11>/Cast6'
   *  DataTypeConversion: '<S11>/Cast7'
   *  DataTypeConversion: '<S11>/Cast8'
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
  rtDW.TmpSignalConversionAtPack_Uart_[19] = Cast9;

  /* S-Function (PackUARTMsg): '<S11>/Pack_Uart_Message' */
  PackUARTMsg_Outputs_wrapper(&rtDW.TmpSignalConversionAtPack_Uart_[0],
    &rtDW.Pack_Uart_Message[0]);

  /* S-Function (sendUART): '<S11>/SendUART' */
  sendUART_Outputs_wrapper(&rtDW.Pack_Uart_Message[0]);

  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function_Call_Generator' */

  /* Outport: '<Root>/debugValues  ' incorporates:
   *  DataTypeConversion: '<S11>/Cast1'
   *  DataTypeConversion: '<S11>/Cast10'
   *  DataTypeConversion: '<S11>/Cast11'
   *  DataTypeConversion: '<S11>/Cast2'
   *  DataTypeConversion: '<S11>/Cast3'
   *  DataTypeConversion: '<S11>/Cast4'
   *  DataTypeConversion: '<S11>/Cast5'
   *  DataTypeConversion: '<S11>/Cast6'
   *  DataTypeConversion: '<S11>/Cast7'
   *  DataTypeConversion: '<S11>/Cast8'
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

  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function_Call_Generator' */
  rtY.debugValues[19] = Cast9;

  /* End of Outport: '<Root>/debugValues  ' */
}

/* Model step function for TID4 */
void GCU_Model_genCode_step4(void)     /* Sample time: [0.001s, 0.0006s] */
{
  real_T rtb_Multiply4[9];
  real_T rtb_Sum1[7];
  real_T rtb_y;
  real_T Multiply1;
  uint32_T CastToDouble_f[7];
  uint32_T Gain1;
  uint32_T Gain2;
  int32_T i;

  /* S-Function (fcncallgen): '<Root>/Function_Call_Generator1' incorporates:
   *  SubSystem: '<Root>/update_ADC_data'
   */
  /* S-Function (update_ADC_data): '<S12>/update_ADC_data' incorporates:
   *  Inport: '<Root>/adc_buffer'
   */
  update_ADC_data_Outputs_wrapper(&rtU.adc_buffer[0], &rtDW.update_ADC_data[0]);

  /* Product: '<S12>/Multiply4' incorporates:
   *  DataTypeConversion: '<S12>/Cast'
   */
  for (i = 0; i < 9; i++) {
    rtb_Multiply4[i] = (real_T)rtDW.update_ADC_data[i] * 0.00080586080586080586;
  }

  /* End of Product: '<S12>/Multiply4' */

  /* Sum: '<S12>/Sum1' incorporates:
   *  Constant: '<S12>/OffSet'
   *  Constant: '<S12>/OffSet1'
   *  Constant: '<S12>/OffSet2'
   *  Product: '<S12>/Multiply1'
   *  Sum: '<S12>/Sum'
   */
  for (i = 0; i < 6; i++) {
    rtb_Sum1[i] = (rtb_Multiply4[i] + rtConstP.OffSet_Value[i]) *
      rtConstP.OffSet1_Value[i] + rtConstP.OffSet2_Value[i];
  }

  rtb_Sum1[6] = (rtb_Multiply4[8] + 0.33) * 37.878787878787875;

  /* End of Sum: '<S12>/Sum1' */

  /* DataTypeConversion: '<S12>/Cast To Double' */
  for (i = 0; i < 7; i++) {
    CastToDouble_f[i] = (uint32_T)rtb_Sum1[i];
  }

  /* End of DataTypeConversion: '<S12>/Cast To Double' */

  /* MATLAB Function: '<S131>/f_T_lt' incorporates:
   *  Constant: '<S131>/Constant10'
   *  Constant: '<S131>/Constant5'
   *  Constant: '<S131>/Constant6'
   *  Constant: '<S131>/Constant7'
   *  Constant: '<S131>/Constant8'
   *  Constant: '<S131>/Constant9'
   *  UnitDelay: '<S12>/Unit Delay'
   */
  rtb_y = (((rtDW.UnitDelay_DSTATE - 25.0) * 0.00329 + 1.0) /
           ((rtDW.UnitDelay_DSTATE - 25.0) * 0.00418 + 1.0) * 0.97 +
           ((rtDW.UnitDelay_DSTATE - 25.0) * 0.00343 + 1.0) /
           ((rtDW.UnitDelay_DSTATE - 25.0) * 0.00401 + 1.0)) / 2.0;

  /* Product: '<S131>/Multiply1' incorporates:
   *  Constant: '<S131>/Constant'
   *  Constant: '<S131>/Constant1'
   *  Constant: '<S131>/Constant3'
   *  Product: '<S131>/Divide1'
   *  Product: '<S131>/Multiply'
   *  Sum: '<S131>/Sum'
   */
  Multiply1 = (rtb_Multiply4[6] / 470.0 - 0.00019088148936170213) *
    (16527.306609952782 * rtb_y);

  /* Gain: '<S12>/Gain1' incorporates:
   *  DataTypeConversion: '<S12>/Cast To Double1'
   */
  Gain1 = 10U * (uint32_T)Multiply1;

  /* Product: '<S131>/Multiply2' incorporates:
   *  Constant: '<S131>/Constant'
   *  Constant: '<S131>/Constant2'
   *  Constant: '<S131>/Constant4'
   *  Product: '<S131>/Divide'
   *  Product: '<S131>/Multiply3'
   *  Sum: '<S131>/Sum1'
   */
  rtb_y = (0.0021276595744680851 * rtb_Multiply4[7] - 0.00013662617021276596) *
    (rtb_y * 16475.911160575281);

  /* Gain: '<S12>/Gain2' incorporates:
   *  DataTypeConversion: '<S12>/Cast To Double2'
   */
  Gain2 = 10U * (uint32_T)rtb_y;

  /* S-Function (Read_oil_sensor): '<S12>/Read_oil_sensor' */
  Read_oil_sensor_Outputs_wrapper(&rtDW.Read_oil_sensor);

  /* Update for UnitDelay: '<S12>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtb_Sum1[4];

  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function_Call_Generator1' */

  /* Outport: '<Root>/adc_data_vector' */
  for (i = 0; i < 6; i++) {
    rtY.adc_data_vector[i] = CastToDouble_f[i];
  }

  rtY.adc_data_vector[6] = Gain1;
  rtY.adc_data_vector[7] = Gain2;
  rtY.adc_data_vector[8] = CastToDouble_f[6];

  /* End of Outport: '<Root>/adc_data_vector' */

  /* RateTransition: '<Root>/Rate Transition18' */
  if (!(rtDW.RateTransition18_semaphoreTaken != 0)) {
    for (i = 0; i < 6; i++) {
      rtDW.RateTransition18_Buffer0[i] = CastToDouble_f[i];
    }

    rtDW.RateTransition18_Buffer0[6] = Gain1;
    rtDW.RateTransition18_Buffer0[7] = Gain2;
    rtDW.RateTransition18_Buffer0[8] = CastToDouble_f[6];
  }

  /* End of RateTransition: '<Root>/Rate Transition18' */

  /* Update for RateTransition: '<Root>/Rate Transition9' */
  for (i = 0; i < 6; i++) {
    rtDW.RateTransition9_Buffer[i + (rtDW.RateTransition9_ActiveBufIdx == 0) * 9]
      = CastToDouble_f[i];
  }

  rtDW.RateTransition9_Buffer[6 + (rtDW.RateTransition9_ActiveBufIdx == 0) * 9] =
    Gain1;
  rtDW.RateTransition9_Buffer[7 + (rtDW.RateTransition9_ActiveBufIdx == 0) * 9] =
    Gain2;
  rtDW.RateTransition9_Buffer[8 + (rtDW.RateTransition9_ActiveBufIdx == 0) * 9] =
    CastToDouble_f[6];
  rtDW.RateTransition9_ActiveBufIdx = (int8_T)(rtDW.RateTransition9_ActiveBufIdx
    == 0);

  /* End of Update for RateTransition: '<Root>/Rate Transition9' */

  /* Update for RateTransition: '<Root>/Rate Transition27' */
  rtDW.RateTransition27_Buffer0 = rtDW.Read_oil_sensor;

  /* Update for RateTransition: '<Root>/Rate Transition35' */
  for (i = 0; i < 6; i++) {
    rtDW.RateTransition35_Buffer[i + (rtDW.RateTransition35_ActiveBufIdx == 0) *
      9] = CastToDouble_f[i];
  }

  rtDW.RateTransition35_Buffer[6 + (rtDW.RateTransition35_ActiveBufIdx == 0) * 9]
    = Gain1;
  rtDW.RateTransition35_Buffer[7 + (rtDW.RateTransition35_ActiveBufIdx == 0) * 9]
    = Gain2;
  rtDW.RateTransition35_Buffer[8 + (rtDW.RateTransition35_ActiveBufIdx == 0) * 9]
    = CastToDouble_f[6];
  rtDW.RateTransition35_ActiveBufIdx = (int8_T)
    (rtDW.RateTransition35_ActiveBufIdx == 0);

  /* End of Update for RateTransition: '<Root>/Rate Transition35' */

  /* Update for RateTransition: '<Root>/Rate Transition40' */
  rtDW.RateTransition40_Buffer0 = Multiply1;

  /* Update for RateTransition: '<Root>/Rate Transition41' */
  rtDW.RateTransition41_Buffer0 = rtb_y;
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
  rtDW.RateTransition20 = rtDW.Merge_n;

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

  /* RateTransition: '<Root>/Rate Transition31' */
  rtDW.RateTransition31 = rtDW.antiStallFb;

  /* S-Function (fcncallgen): '<Root>/Function_Call_Generator2' incorporates:
   *  SubSystem: '<Root>/CAN_Send'
   */
  /* Lookup_n-D: '<S2>/1-D Lookup Table2' incorporates:
   *  Lookup_n-D: '<S2>/1-D Lookup Table1'
   */
  uDLookupTable2_tmp = look1_iu16lu64n48_binlcse(rtDW.RateTransition22,
    rtConstP.pooled23, rtConstP.pooled22, 7U);
  rtDW.uDLookupTable2 = uDLookupTable2_tmp;

  /* Lookup_n-D: '<S2>/1-D Lookup Table1' */
  rtDW.uDLookupTable1 = uDLookupTable2_tmp;

  /* Lookup_n-D: '<S2>/1-D Lookup Table3' */
  rtDW.uDLookupTable3 = look1_iu16lu64n48_binlcse(rtDW.RateTransition19,
    rtConstP.uDLookupTable3_bp01Data, rtConstP.uDLookupTable3_tableData, 10U);
  rtDW.gcu_traction_limiter_loil_efi_i = (uint16_T)
    GCU_TRACTION_LIMITER_LOIL_EFI_ID;
  rtDW.gcu_clutch_mode_map_sw_id = (uint16_T)GCU_CLUTCH_MODE_MAP_SW_ID;
  rtDW.gcu_traction_limiter_autog_acc_ = (uint16_T)
    GCU_TRACTION_LIMITER_AUTOG_ACC_SW_ID;
  rtDW.gcu_debug_1_id = (uint16_T)GCU_DEBUG_1_ID;
  rtDW.gcu_debug_2_id = (uint16_T)GCU_DEBUG_2_ID;
  guard1 = false;
  if (rtDW.counter3 >= 100) {
    /* Outputs for Function Call SubSystem: '<S2>/Subsystem1' */
    /* DataTypeConversion: '<S22>/Cast' */
    rtDW.Cast_d = (uint16_T)rtDW.RateTransition18[4];

    /* DataTypeConversion: '<S22>/Cast1' */
    rtDW.Cast1_h = (uint16_T)rtDW.RateTransition18[5];

    /* DataTypeConversion: '<S22>/Cast2' */
    rtDW.Cast2_e = (uint16_T)rtDW.RateTransition18[3];

    /* DataTypeConversion: '<S22>/Cast3' */
    rtDW.Cast3_p = (uint16_T)rtDW.RateTransition18[8];

    /* S-Function (PackCANMsg): '<S22>/PackCANMsg' */
    PackCANMsg_Outputs_wrapper(&rtDW.Cast_d, &rtDW.Cast1_h, &rtDW.Cast2_e,
      &rtDW.Cast3_p, &rtDW.PackCANMsg_f[0]);

    /* S-Function (sendCAN): '<S22>/sendCAN' */
    sendCAN_Outputs_wrapper(&rtDW.gcu_debug_1_id, &rtDW.PackCANMsg_f[0]);

    /* End of Outputs for SubSystem: '<S2>/Subsystem1' */

    /* Outputs for IfAction SubSystem: '<S19>/If Action Subsystem' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S19>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    /* If: '<S19>/If' incorporates:
     *  Inport: '<S25>/In1'
     *  Inport: '<S26>/In1'
     */
    if (rtDW.RateTransition18[6] > rtDW.RateTransition18[7]) {
      /* Outputs for Function Call SubSystem: '<S2>/Subsystem2' */
      /* DataTypeConversion: '<S23>/Cast' */
      rtDW.Cast = (uint16_T)rtDW.RateTransition18[6];

      /* End of Outputs for SubSystem: '<S2>/Subsystem2' */
    } else {
      /* Outputs for Function Call SubSystem: '<S2>/Subsystem2' */
      /* DataTypeConversion: '<S23>/Cast' */
      rtDW.Cast = (uint16_T)rtDW.RateTransition18[7];

      /* End of Outputs for SubSystem: '<S2>/Subsystem2' */
    }

    /* End of If: '<S19>/If' */
    /* End of Outputs for SubSystem: '<S19>/If Action Subsystem1' */
    /* End of Outputs for SubSystem: '<S19>/If Action Subsystem' */

    /* Outputs for Function Call SubSystem: '<S2>/Subsystem2' */
    /* DataTypeConversion: '<S23>/Cast1' */
    rtDW.Cast1 = (uint16_T)rtDW.RateTransition18[0];

    /* DataTypeConversion: '<S23>/Cast2' */
    rtDW.Cast2 = (uint16_T)rtDW.RateTransition18[1];

    /* DataTypeConversion: '<S23>/Cast3' */
    rtDW.Cast3 = (uint16_T)rtDW.RateTransition18[2];

    /* S-Function (PackCANMsg): '<S23>/PackCANMsg' */
    PackCANMsg_Outputs_wrapper(&rtDW.Cast, &rtDW.Cast1, &rtDW.Cast2, &rtDW.Cast3,
      &rtDW.PackCANMsg[0]);

    /* S-Function (sendCAN): '<S23>/sendCAN' */
    sendCAN_Outputs_wrapper(&rtDW.gcu_debug_2_id, &rtDW.PackCANMsg[0]);

    /* End of Outputs for SubSystem: '<S2>/Subsystem2' */
    rtDW.counter3 = 0U;
    guard1 = true;
  } else {
    if (rtDW.counter2 >= 10) {
      guard1 = true;
    }
  }

  if (guard1) {
    /* Outputs for Function Call SubSystem: '<S2>/Subsystem' */

    /* S-Function (PackCANMsg): '<S21>/PackCANMsg' */
    PackCANMsg_Outputs_wrapper(&rtDW.RateTransition22, &rtDW.RateTransition19,
      (uint16_T*)&GCU_Model_genCode_U16GND, &rtDW.RateTransition21,
      &rtDW.PackCANMsg_e[0]);

    /* S-Function (sendCAN): '<S21>/sendCAN' */
    sendCAN_Outputs_wrapper(&rtDW.gcu_traction_limiter_autog_acc_,
      &rtDW.PackCANMsg_e[0]);

    /* End of Outputs for SubSystem: '<S2>/Subsystem' */

    /* Outputs for Function Call SubSystem: '<S2>/sendMessage' */

    /* S-Function (PackCANMsg): '<S27>/PackCANMsg' */
    PackCANMsg_Outputs_wrapper(&rtDW.uDLookupTable2, &rtDW.uDLookupTable1,
      &rtDW.uDLookupTable3, &rtDW.RateTransition28, &rtDW.PackCANMsg_l[0]);

    /* S-Function (sendCAN): '<S27>/sendCAN' */
    sendCAN_Outputs_wrapper(&rtDW.gcu_traction_limiter_loil_efi_i,
      &rtDW.PackCANMsg_l[0]);

    /* End of Outputs for SubSystem: '<S2>/sendMessage' */
    rtDW.counter2 = 0U;
  }

  /* Chart: '<S2>/CAN_id' incorporates:
   *  SubSystem: '<S2>/Subsystem3'
   */
  /* DataTypeConversion: '<S24>/Cast' */
  rtDW.Cast_l = rtDW.RateTransition20;

  /* S-Function (PackCANMsg): '<S24>/PackCANMsg' */
  PackCANMsg_Outputs_wrapper(&rtDW.Cast_l, &rtDW.RateTransition23,
    &rtDW.RateTransition26, &rtDW.RateTransition31, &rtDW.PackCANMsg_ls[0]);

  /* S-Function (sendCAN): '<S24>/sendCAN' */
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

  /* BusCreator: '<S3>/BusConversion_InsertedFor_EEPROM_Load_Buffer_at_inport_0' incorporates:
   *  Inport: '<Root>/inputRequest'
   */
  BusConversion_InsertedFor_EEPRO.operation = rtU.inputRequest[0];
  BusConversion_InsertedFor_EEPRO.page = rtU.inputRequest[1];
  BusConversion_InsertedFor_EEPRO.cell = rtU.inputRequest[2];
  BusConversion_InsertedFor_EEPRO.dataSize = rtU.inputRequest[3];
  for (i = 0; i < 16; i++) {
    BusConversion_InsertedFor_EEPRO.data[i] = rtU.inputRequest[i + 4];
  }

  /* End of BusCreator: '<S3>/BusConversion_InsertedFor_EEPROM_Load_Buffer_at_inport_0' */

  /* S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  Chart: '<S3>/EEPROM_Load_Buffer'
   */
  /* Chart: '<S3>/EEPROM_Load_Buffer' */
  updateBuffer(&BusConversion_InsertedFor_EEPRO);

  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function-Call Generator' */

  /* Update for RateTransition: '<S3>/Rate Transition' */
  for (i = 0; i < 20; i++) {
    rtDW.RateTransition_Buffer[i + (rtDW.RateTransition_ActiveBufIdx == 0) * 20]
      = rtDW.requestBuffer[i];
  }

  rtDW.RateTransition_ActiveBufIdx = (int8_T)(rtDW.RateTransition_ActiveBufIdx ==
    0);

  /* End of Update for RateTransition: '<S3>/Rate Transition' */

  /* Update for RateTransition: '<S3>/Rate Transition1' */
  rtDW.RateTransition1_Buffer0 = rtDW.lastInsertedIndex;
}

/* Model initialize function */
void GCU_Model_genCode_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize sample time offsets */
  /* initialize sample time offsets */
  /* initialize sample time offsets */
  /* initialize sample time offsets */
  /* initialize sample time offsets */

  /* Start for RateTransition: '<S3>/Rate Transition1' */
  rtDW.RateTransition1 = 1.0;
  rtPrevZCX.MODESACCELERATION_PIDLAUNCH9ACT.UD_Reset_ZCE = UNINITIALIZED_ZCSIG;
  rtPrevZCX.MODESACCELERATION_PIDLAUNCH8ACT.UD_Reset_ZCE = UNINITIALIZED_ZCSIG;
  rtPrevZCX.MODESACCELERATION_PIDLAUNCH7ACT.UD_Reset_ZCE_j = UNINITIALIZED_ZCSIG;
  rtPrevZCX.MODESACCELERATION_PIDLAUNCH6ACT.UD_Reset_ZCE_j = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for RateTransition: '<S3>/Rate Transition1' */
  rtDW.RateTransition1_Buffer0 = 1.0;
  rtDW.sfEvent = -1;

  /* SystemInitialize for Chart: '<S5>/GCULogic' incorporates:
   *  Chart: '<S3>/EEPROM_OutputRequest'
   */
  rtDW.lastEvaluatedIndex = 1.0;
  rtDW.HAL_ERROR = 1U;

  /* Chart: '<S3>/EEPROM_OutputRequest' */
  /* Chart: '<S3>/EEPROM_OutputRequest' */
  rtDW.is_c6_GCU_Model_genCode = IN_INIT;

  /* SystemInitialize for Chart: '<S3>/EEPROM_OutputRequest' incorporates:
   *  SubSystem: '<S3>/Evaluate_Request'
   */
  Evaluate_Request_Init(rtDW.Merge_d, rtDW.Merge1, rtDW.Merge2, rtDW.Merge3,
                        &rtDW.Evaluate_Request_l);

  /* SystemInitialize for Chart: '<S5>/GCULogic' incorporates:
   *  SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH0.ACTIVE.ramp'
   */
  MODESACCELERATION_PIDL_Init(&rtDW.MODESACCELERATION_PIDLAUNCH0ACT);

  /* SystemInitialize for Chart: '<S5>/GCULogic' incorporates:
   *  SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH1.ACTIVE.ramp'
   */
  MODESACCELERATION_PI_j_Init(&rtDW.MODESACCELERATION_PIDLAUNCH1ACT);

  /* SystemInitialize for Chart: '<S5>/GCULogic' incorporates:
   *  SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH2.ACTIVE.ramp'
   */
  MODESACCELERATION_PI_p_Init(&rtDW.MODESACCELERATION_PIDLAUNCH2ACT);

  /* SystemInitialize for Chart: '<S5>/GCULogic' incorporates:
   *  SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH3.ACTIVE.ramp'
   */
  MODESACCELERATION_PI_p_Init(&rtDW.MODESACCELERATION_PIDLAUNCH3ACT);

  /* SystemInitialize for Chart: '<S5>/GCULogic' incorporates:
   *  SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH4.ACTIVE.ramp'
   */
  MODESACCELERATION_PI_f_Init(&rtDW.MODESACCELERATION_PIDLAUNCH4ACT);

  /* SystemInitialize for Chart: '<S5>/GCULogic' incorporates:
   *  SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH5.ACTIVE.ramp'
   */
  MODESACCELERATION_PI_f_Init(&rtDW.MODESACCELERATION_PIDLAUNCH5ACT);

  /* SystemInitialize for Chart: '<S5>/GCULogic' incorporates:
   *  SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH6.ACTIVE.pidControl'
   */
  MODESACCELERATION_PI_l_Init(&rtDW.MODESACCELERATION_PIDLAUNCH6ACT);

  /* SystemInitialize for Chart: '<S5>/GCULogic' incorporates:
   *  SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH7.ACTIVE.pidControl'
   */
  MODESACCELERATION_PI_l_Init(&rtDW.MODESACCELERATION_PIDLAUNCH7ACT);

  /* SystemInitialize for Chart: '<S5>/GCULogic' incorporates:
   *  SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH8.ACTIVE.pidControl'
   */
  MODESACCELERATION_PI_b_Init(&rtDW.MODESACCELERATION_PIDLAUNCH8ACT);

  /* SystemInitialize for Chart: '<S5>/GCULogic' incorporates:
   *  SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH9.ACTIVE.pidControl'
   */
  MODESACCELERATION_PI_b_Init(&rtDW.MODESACCELERATION_PIDLAUNCH9ACT);

  /* End of SystemInitialize for SubSystem: '<Root>/GCU_timer' */

  /* SystemInitialize for S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  Chart: '<S3>/EEPROM_Load_Buffer'
   */
  /* SystemInitialize for Chart: '<S3>/EEPROM_Load_Buffer' */
  rtDW.lastInsertedIndex = 1.0;

  /* End of SystemInitialize for S-Function (fcncallgen): '<Root>/Function-Call Generator' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/InitializeFunction' */

  /* S-Function (load_accParameters): '<S6>/load_accParameters' */
  load_accParameters_Outputs_wrapper(&rtDW.load_accParameters[0]);

  /* S-Function (load_default_timings): '<S6>/load_default_timings' */
  load_default_timings_Outputs_wrapper(&rtDW.load_default_timings[0]);

  /* S-Function (load_autoXParameters): '<S6>/load_accParameters1' */
  load_autoXParameters_Outputs_wrapper(&rtDW.load_accParameters1[0]);

  /* S-Function (load_antiStallParameters): '<S6>/load_antiStall_default' */
  load_antiStallParameters_Outputs_wrapper(&rtDW.load_antiStall_default[0]);

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

  /* Enable for Atomic SubSystem: '<Root>/GCU_timer' */
  /* Enable for Chart: '<S5>/GCULogic' */
  if (rtDW.is_LAUNCH0 == IN_ACTIVE) {
    /* Enable for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH0.ACTIVE.ramp' */
    MODESACCELERATION_PI_Enable(&rtDW.MODESACCELERATION_PIDLAUNCH0ACT);

    /* End of Enable for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH0.ACTIVE.ramp' */
  }

  if (rtDW.is_LAUNCH1 == IN_ACTIVE) {
    /* Enable for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH1.ACTIVE.ramp' */
    MODESACCELERATION__c_Enable(&rtDW.MODESACCELERATION_PIDLAUNCH1ACT);

    /* End of Enable for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH1.ACTIVE.ramp' */
  }

  if (rtDW.is_LAUNCH2 == IN_ACTIVE) {
    /* Enable for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH2.ACTIVE.ramp' */
    MODESACCELERATION__k_Enable(&rtDW.MODESACCELERATION_PIDLAUNCH2ACT);

    /* End of Enable for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH2.ACTIVE.ramp' */
  }

  if (rtDW.is_LAUNCH3 == IN_ACTIVE) {
    /* Enable for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH3.ACTIVE.ramp' */
    MODESACCELERATION__k_Enable(&rtDW.MODESACCELERATION_PIDLAUNCH3ACT);

    /* End of Enable for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH3.ACTIVE.ramp' */
  }

  if (rtDW.is_LAUNCH4 == IN_ACTIVE) {
    /* Enable for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH4.ACTIVE.ramp' */
    MODESACCELERATION__i_Enable(&rtDW.MODESACCELERATION_PIDLAUNCH4ACT);

    /* End of Enable for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH4.ACTIVE.ramp' */
  }

  if (rtDW.is_LAUNCH5 == IN_ACTIVE) {
    /* Enable for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH5.ACTIVE.ramp' */
    MODESACCELERATION__i_Enable(&rtDW.MODESACCELERATION_PIDLAUNCH5ACT);

    /* End of Enable for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH5.ACTIVE.ramp' */
  }

  if (rtDW.is_LAUNCH6 == IN_ACTIVE) {
    /* Enable for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH6.ACTIVE.pidControl' */
    MODESACCELERATION__j_Enable(&rtDW.MODESACCELERATION_PIDLAUNCH6ACT);

    /* End of Enable for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH6.ACTIVE.pidControl' */
  }

  if (rtDW.is_LAUNCH7 == IN_ACTIVE) {
    /* Enable for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH7.ACTIVE.pidControl' */
    MODESACCELERATION__j_Enable(&rtDW.MODESACCELERATION_PIDLAUNCH7ACT);

    /* End of Enable for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH7.ACTIVE.pidControl' */
  }

  if (rtDW.is_LAUNCH8 == IN_ACTIVE) {
    /* Enable for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH8.ACTIVE.pidControl' */
    MODESACCELERATION__e_Enable(&rtDW.MODESACCELERATION_PIDLAUNCH8ACT);

    /* End of Enable for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH8.ACTIVE.pidControl' */
  }

  if (rtDW.is_LAUNCH9 == IN_ACTIVE) {
    /* Enable for Function Call SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH9.ACTIVE.pidControl' */
    MODESACCELERATION__e_Enable(&rtDW.MODESACCELERATION_PIDLAUNCH9ACT);

    /* End of Enable for SubSystem: '<S48>/MODES.ACCELERATION_PID.LAUNCH9.ACTIVE.pidControl' */
  }

  /* End of Enable for Chart: '<S5>/GCULogic' */
  /* End of Enable for SubSystem: '<Root>/GCU_timer' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
