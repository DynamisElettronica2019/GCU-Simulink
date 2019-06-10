/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GCU_Model_genCode.h
 *
 * Code generated for Simulink model 'GCU_Model_genCode'.
 *
 * Model version                  : 1.296
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Mon Jun 10 22:08:39 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_GCU_Model_genCode_h_
#define RTW_HEADER_GCU_Model_genCode_h_
#include "rtwtypes.h"
#include <string.h>
#ifndef GCU_Model_genCode_COMMON_INCLUDES_
# define GCU_Model_genCode_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* GCU_Model_genCode_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* user code (top of header file) */
#include "timings.h"
#include "constant_defines.h"
#include "id_can.h"
#ifndef SS_INT64
#define SS_INT64                       21
#endif

#ifndef SS_UINT64
#define SS_UINT64                      22
#endif

#ifndef DEFINED_TYPEDEF_FOR_eepromRequest_
#define DEFINED_TYPEDEF_FOR_eepromRequest_

typedef struct {
  uint8_T operation;
  uint8_T page;
  uint8_T cell;
  uint8_T dataSize;
  uint8_T data[16];
} eepromRequest;

#endif

#ifndef DEFINED_TYPEDEF_FOR_anti_stall_params_
#define DEFINED_TYPEDEF_FOR_anti_stall_params_

typedef enum {
  RPM_THRESHOLD = 0,                   /* Default value */
  RPM_DELTA_THRESHOLD,
  GEAR_THRESHOLD
} anti_stall_params;

#endif

#ifndef DEFINED_TYPEDEF_FOR_autoX_params_
#define DEFINED_TYPEDEF_FOR_autoX_params_

typedef enum {
  AUTOX_RAMP_START = 0,                /* Default value */
  AUTOX_RAMP_END,
  AUTOX_RAMP_TIME,
  AUTOX_RPM_LIMIT_1_2,
  AUTOX_RPM_LIMIT_2_3,
  AUTOX_RPM_LIMIT_3_4,
  AUTOX_RPM_LIMIT_4_5,
  AUTOX_SPEED_LIMIT_1_2,
  AUTOX_SPEED_LIMIT_2_3,
  AUTOX_SPEED_LIMIT_3_4,
  AUTOX_SPEED_LIMIT_4_5,
  AUTOX_TPS_START_LIMIT,
  AUTOX_END_GEAR
} autoX_params;

#endif

#ifndef DEFINED_TYPEDEF_FOR_acc_params_
#define DEFINED_TYPEDEF_FOR_acc_params_

typedef enum {
  RAMP_START = 0,                      /* Default value */
  RAMP_END,
  RAMP_TIME,
  RPM_LIMIT_1_2,
  RPM_LIMIT_2_3,
  RPM_LIMIT_3_4,
  RPM_LIMIT_4_5,
  SPEED_LIMIT_1_2,
  SPEED_LIMIT_2_3,
  SPEED_LIMIT_3_4,
  SPEED_LIMIT_4_5,
  TPS_START_LIMIT,
  END_GEAR
} acc_params;

#endif

#ifndef DEFINED_TYPEDEF_FOR_acc_values_
#define DEFINED_TYPEDEF_FOR_acc_values_

typedef enum {
  RPM = 0,                             /* Default value */
  WHEEL_SPEED,
  TPS
} acc_values;

#endif

#ifndef DEFINED_TYPEDEF_FOR_eepromConstants_
#define DEFINED_TYPEDEF_FOR_eepromConstants_

typedef enum {
  USED_EEPROM = 170,                   /* Default value */
  NEW_EEPROM = 255,
  GEARSHIFT_NUM = 23,
  ACC_PAR_NUM = 13,
  AUTOX_PAR_NUM = 13,
  ANTI_STALL_PAR_NUM = 3
} eepromConstants;

#endif

/* Block signals and states (default storage) for system '<S4>/AAC_ExternalValues' */
typedef struct {
  uint16_T UnitDelay_DSTATE[3];        /* '<S31>/Unit Delay' */
} DW_AAC_ExternalValues;

/* Block signals and states (default storage) for system '<S41>/Gearmotor_turnRight' */
typedef struct {
  uint8_T GearMotorTurnRight_o1;       /* '<S64>/GearMotor Turn Right' */
  uint8_T GearMotorTurnRight_o2;       /* '<S64>/GearMotor Turn Right' */
  uint8_T GearMotorTurnRight_o3;       /* '<S64>/GearMotor Turn Right' */
} DW_Gearmotor_turnRight;

/* Block signals and states (default storage) for system '<S41>/Gearmotor_brake' */
typedef struct {
  uint8_T GearMotorBrake_o1;           /* '<S61>/GearMotor Brake' */
  uint8_T GearMotorBrake_o2;           /* '<S61>/GearMotor Brake' */
  uint8_T GearMotorBrake_o3;           /* '<S61>/GearMotor Brake' */
} DW_Gearmotor_brake;

/* Block signals and states (default storage) for system '<S38>/EngineControl_Start' */
typedef struct {
  uint8_T EngineControlStart;          /* '<S55>/EngineControl Start' */
} DW_EngineControl_Start;

/* Block signals and states (default storage) for system '<S3>/Evaluate_Request' */
typedef struct {
  uint16_T gearshiftTimings[24];       /* '<S27>/updateValues' */
  uint16_T accParameters[16];          /* '<S27>/updateValues' */
  uint16_T autoXParameters[16];        /* '<S27>/updateValues' */
  uint16_T antiStallParameters[8];     /* '<S27>/updateValues' */
  uint8_T TmpSignalConversionAtsendEeprom[19];
  uint8_T Eeprom_read_o2[16];          /* '<S27>/Eeprom_read' */
  uint8_T Eeprom_read_o2_e[16];        /* '<S28>/Eeprom_read' */
  uint8_T page;
  uint8_T cell;
  uint8_T dataSize;
  uint8_T Eeprom_read_o1;              /* '<S27>/Eeprom_read' */
  uint8_T HAL_ERROR;                   /* '<S27>/updateValues' */
} DW_Evaluate_Request;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_Evaluate_Request Evaluate_Request_l;/* '<S3>/Evaluate_Request' */
  DW_EngineControl_Start EngineControl_Start_h;/* '<S38>/EngineControl_Start' */
  DW_Gearmotor_brake Gearmotor_brake_c;/* '<S41>/Gearmotor_brake' */
  DW_Gearmotor_turnRight Gearmotor_turnRight_f;/* '<S41>/Gearmotor_turnRight' */
  DW_AAC_ExternalValues AAC_ExternalValues_f;/* '<S4>/AAC_ExternalValues' */
  volatile eepromRequest RateTransition_Buffer[40];/* '<S3>/Rate Transition' */
  eepromRequest RateTransition[20];    /* '<S3>/Rate Transition' */
  eepromRequest requestBuffer[20];     /* '<S3>/EEPROM_Load_Buffer' */
  eepromRequest outputRequest;         /* '<S3>/EEPROM_OutputRequest' */
  real_T RateTransition1;              /* '<S3>/Rate Transition1' */
  real_T deltaTime;                    /* '<S34>/timeCounter' */
  real_T lastInsertedIndex;            /* '<S3>/EEPROM_Load_Buffer' */
  real_T Internal_DSTATE;              /* '<S39>/Internal' */
  volatile real_T RateTransition1_Buffer0;/* '<S3>/Rate Transition1' */
  real_T message;                      /* '<S7>/AccelerationRoutine' */
  real_T count;                        /* '<S7>/AccelerationRoutine' */
  real_T aac_clutchValue;              /* '<S5>/GCULogic' */
  real_T aac_clutchStep;               /* '<S5>/GCULogic' */
  real_T autoX_clutchValue;            /* '<S5>/GCULogic' */
  real_T autoX_clutchStep;             /* '<S5>/GCULogic' */
  real_T counterWait;                  /* '<S5>/GCULogic' */
  real_T lastEvaluatedIndex;           /* '<S3>/EEPROM_OutputRequest' */
  real_T reloadFlag;                   /* '<S3>/EEPROM_OutputRequest' */
  real_T timeMs;                       /* '<S34>/timeCounter' */
  int32_T UnitDelay[16];               /* '<Root>/Unit Delay' */
  int32_T UnitDelay1[24];              /* '<Root>/Unit Delay1' */
  int32_T UnitDelay2[16];              /* '<Root>/Unit Delay2' */
  int32_T load_accParameters[13];      /* '<S6>/load_accParameters' */
  int32_T load_default_timings[23];    /* '<S6>/load_default_timings' */
  int32_T load_accParameters1[13];     /* '<S6>/load_accParameters1' */
  int32_T load_antiStall_default[3];   /* '<S6>/load_antiStall_default' */
  int32_T Merge[24];                   /* '<S25>/Merge' */
  int32_T Merge1[16];                  /* '<S25>/Merge1' */
  int32_T Merge2[16];                  /* '<S25>/Merge2' */
  int32_T Merge3[8];                   /* '<S25>/Merge3' */
  int32_T UnitDelay_DSTATE[16];        /* '<Root>/Unit Delay' */
  int32_T UnitDelay1_DSTATE[24];       /* '<Root>/Unit Delay1' */
  int32_T UnitDelay2_DSTATE[16];       /* '<Root>/Unit Delay2' */
  int32_T UnitDelay3_DSTATE[8];        /* '<Root>/Unit Delay3' */
  int32_T sfEvent;                     /* '<S5>/GCULogic' */
  int32_T aac_dtRelease;               /* '<S5>/GCULogic' */
  int32_T autoX_dtRelease;             /* '<S5>/GCULogic' */
  int32_T ticksCounter;                /* '<S5>/GCULogic' */
  uint32_T RateTransition18[9];        /* '<Root>/Rate Transition18' */
  uint32_T update_ADC_data[9];         /* '<S10>/update_ADC_data' */
  volatile uint32_T RateTransition9_Buffer[18];/* '<Root>/Rate Transition9' */
  volatile uint32_T RateTransition18_Buffer0[9];/* '<Root>/Rate Transition18' */
  uint16_T RateTransition1_c[3];       /* '<Root>/Rate Transition1' */
  uint16_T RateTransition2[2];         /* '<Root>/Rate Transition2' */
  uint16_T RateTransition4[2];         /* '<Root>/Rate Transition4' */
  uint16_T RateTransition8[2];         /* '<Root>/Rate Transition8' */
  uint16_T RateTransition29[2];        /* '<Root>/Rate Transition29' */
  uint16_T lastModeCom[2];             /* '<S5>/GCULogic' */
  uint16_T shiftCommand[2];            /* '<S4>/MessageEvaluation1' */
  uint16_T accCommand[2];              /* '<S4>/MessageEvaluation1' */
  uint16_T modeCommand[2];             /* '<S4>/MessageEvaluation1' */
  uint16_T autoXCommand[2];            /* '<S4>/MessageEvaluation1' */
  uint16_T Assignment[3];              /* '<S31>/Assignment' */
  uint16_T TmpSignalConversionAtPack_Uart_[20];
  volatile uint16_T RateTransition1_Buffer[6];/* '<Root>/Rate Transition1' */
  volatile uint16_T RateTransition2_Buffer[4];/* '<Root>/Rate Transition2' */
  volatile uint16_T RateTransition4_Buffer[4];/* '<Root>/Rate Transition4' */
  volatile uint16_T RateTransition8_Buffer[4];/* '<Root>/Rate Transition8' */
  volatile uint16_T RateTransition29_Buffer[4];/* '<Root>/Rate Transition29' */
  volatile uint16_T RateTransition14_Buffer0[3];/* '<Root>/Rate Transition14' */
  uint16_T RateTransition19;           /* '<Root>/Rate Transition19' */
  uint16_T RateTransition21;           /* '<Root>/Rate Transition21' */
  uint16_T RateTransition22;           /* '<Root>/Rate Transition22' */
  uint16_T RateTransition23;           /* '<Root>/Rate Transition23' */
  uint16_T RateTransition26;           /* '<Root>/Rate Transition26' */
  uint16_T RateTransition28;           /* '<Root>/Rate Transition28' */
  uint16_T RateTransition31;           /* '<Root>/Rate Transition31' */
  uint16_T id;                         /* '<S7>/AccelerationRoutine' */
  uint16_T firstInt;                   /* '<S7>/AccelerationRoutine' */
  uint16_T secondInt;                  /* '<S7>/AccelerationRoutine' */
  uint16_T thirdInt;                   /* '<S7>/AccelerationRoutine' */
  uint16_T UnitDelay_b;                /* '<S5>/Unit Delay' */
  uint16_T stateFb;                    /* '<S5>/GCULogic' */
  uint16_T lastRPMValue;               /* '<S34>/timeCounter' */
  uint16_T antiStallFb;                /* '<S34>/antiStallLogic' */
  uint16_T UnpackCanUart_o1;           /* '<S4>/UnpackCanUart' */
  uint16_T UnpackCanUart_o2;           /* '<S4>/UnpackCanUart' */
  uint16_T UnpackCanUart_o3;           /* '<S4>/UnpackCanUart' */
  uint16_T UnpackCanUart_o4;           /* '<S4>/UnpackCanUart' */
  uint16_T UnpackCanUart_o5;           /* '<S4>/UnpackCanUart' */
  uint16_T currGear;                   /* '<S4>/MessageEvaluation1' */
  uint16_T tractionTarget;             /* '<S4>/MessageEvaluation1' */
  uint16_T mapTarget;                  /* '<S4>/MessageEvaluation1' */
  uint16_T rpmLimiterTarget;           /* '<S4>/MessageEvaluation1' */
  uint16_T uDLookupTable2;             /* '<S2>/1-D Lookup Table2' */
  uint16_T uDLookupTable1;             /* '<S2>/1-D Lookup Table1' */
  uint16_T uDLookupTable3;             /* '<S2>/1-D Lookup Table3' */
  uint16_T gcu_traction_limiter_loil_efi_i;/* '<S2>/CAN_id' */
  uint16_T gcu_clutch_mode_map_sw_id;  /* '<S2>/CAN_id' */
  uint16_T gcu_traction_limiter_autog_acc_;/* '<S2>/CAN_id' */
  uint16_T gcu_debug_1_id;             /* '<S2>/CAN_id' */
  uint16_T gcu_debug_2_id;             /* '<S2>/CAN_id' */
  uint16_T Cast;                       /* '<S20>/Cast' */
  uint16_T Cast1;                      /* '<S20>/Cast1' */
  uint16_T Cast2;                      /* '<S20>/Cast2' */
  uint16_T Cast3;                      /* '<S20>/Cast3' */
  uint16_T Cast_d;                     /* '<S19>/Cast' */
  uint16_T Cast1_h;                    /* '<S19>/Cast1' */
  uint16_T Cast2_e;                    /* '<S19>/Cast2' */
  uint16_T Cast3_p;                    /* '<S19>/Cast3' */
  uint16_T Cast_l;                     /* '<S21>/Cast' */
  uint16_T Read_oil_sensor;            /* '<S10>/Read_oil_sensor' */
  uint16_T UnitDelay_DSTATE_o;         /* '<S5>/Unit Delay' */
  uint16_T UnitDelay_DSTATE_e;         /* '<S34>/Unit Delay' */
  volatile uint16_T RateTransition27_Buffer0;/* '<Root>/Rate Transition27' */
  uint16_T rpm;                        /* '<S7>/AccelerationRoutine' */
  uint16_T wheelSpeed;                 /* '<S7>/AccelerationRoutine' */
  uint16_T currGear_m;                 /* '<S7>/AccelerationRoutine' */
  uint16_T lastAacCom;                 /* '<S5>/GCULogic' */
  uint16_T lastShiftCom;               /* '<S5>/GCULogic' */
  uint16_T lastAutoXCom;               /* '<S5>/GCULogic' */
  uint16_T buzzerCounter;              /* '<S5>/GCULogic' */
  uint16_T aacCounter;                 /* '<S5>/GCULogic' */
  uint16_T autoXCounter;               /* '<S5>/GCULogic' */
  uint16_T timerCounter;               /* '<S5>/GCULogic' */
  volatile int8_T RateTransition9_ActiveBufIdx;/* '<Root>/Rate Transition9' */
  volatile int8_T RateTransition1_ActiveBufIdx;/* '<Root>/Rate Transition1' */
  volatile int8_T RateTransition2_ActiveBufIdx;/* '<Root>/Rate Transition2' */
  volatile int8_T RateTransition4_ActiveBufIdx;/* '<Root>/Rate Transition4' */
  volatile int8_T RateTransition8_ActiveBufIdx;/* '<Root>/Rate Transition8' */
  volatile int8_T RateTransition29_ActiveBufIdx;/* '<Root>/Rate Transition29' */
  volatile int8_T RateTransition_ActiveBufIdx;/* '<S3>/Rate Transition' */
  volatile int8_T RateTransition14_semaphoreTaken;/* '<Root>/Rate Transition14' */
  volatile int8_T RateTransition18_semaphoreTaken;/* '<Root>/Rate Transition18' */
  uint8_T MultiportSwitch[10];         /* '<Root>/Multiport Switch' */
  uint8_T PackCanUart[10];             /* '<S7>/PackCanUart' */
  uint8_T OutportBufferFordataRead[19];
  uint8_T PackCANMsg[8];               /* '<S20>/PackCANMsg' */
  uint8_T PackCANMsg_f[8];             /* '<S19>/PackCANMsg' */
  uint8_T PackCANMsg_l[8];             /* '<S22>/PackCANMsg' */
  uint8_T PackCANMsg_e[8];             /* '<S18>/PackCANMsg' */
  uint8_T PackCANMsg_ls[8];            /* '<S21>/PackCANMsg' */
  uint8_T Pack_Uart_Message[40];       /* '<S9>/Pack_Uart_Message' */
  uint8_T tempShiftedArray[50];        /* '<S3>/EEPROM_OutputRequest' */
  uint8_T newData[16];                 /* '<S3>/EEPROM_OutputRequest' */
  uint8_T RateTransition_d;            /* '<Root>/Rate Transition' */
  uint8_T RateTransition3;             /* '<Root>/Rate Transition3' */
  uint8_T RateTransition30;            /* '<Root>/Rate Transition30' */
  uint8_T RateTransition6;             /* '<Root>/Rate Transition6' */
  uint8_T RateTransition7;             /* '<Root>/Rate Transition7' */
  uint8_T RateTransition20;            /* '<Root>/Rate Transition20' */
  uint8_T Eeprom_init_o1;              /* '<S6>/Eeprom_init' */
  uint8_T Eeprom_init_o2;              /* '<S6>/Eeprom_init' */
  uint8_T Eeprom_init_o3;              /* '<S6>/Eeprom_init' */
  uint8_T setKeyOn;                    /* '<S6>/setKeyOn' */
  uint8_T Cast1_k;                     /* '<S5>/Cast1' */
  uint8_T Pin_H;                       /* '<S41>/Pin_H' */
  uint8_T Pin_In1;                     /* '<S41>/Pin_In1' */
  uint8_T Merge_n;                     /* '<S5>/Merge' */
  uint8_T clutchCurrVal;               /* '<S5>/GCULogic' */
  uint8_T antiStallEnable;             /* '<S5>/GCULogic' */
  uint8_T Eeprom_read_o1;              /* '<S28>/Eeprom_read' */
  uint8_T Eeprom_write_o1;             /* '<S29>/Eeprom_write' */
  uint8_T Eeprom_write_o2;             /* '<S29>/Eeprom_write' */
  uint8_T EngineControlStop;           /* '<S56>/EngineControl Stop' */
  uint8_T GearMotorTurnLeft_o1;        /* '<S63>/GearMotor Turn Left' */
  uint8_T GearMotorTurnLeft_o2;        /* '<S63>/GearMotor Turn Left' */
  uint8_T GearMotorTurnLeft_o3;        /* '<S63>/GearMotor Turn Left' */
  uint8_T GearMotorRelease;            /* '<S62>/GearMotor Release' */
  uint8_T Minus;                       /* '<S49>/Minus' */
  uint8_T antiStallClutchVal;          /* '<S34>/antiStallLogic' */
  uint8_T Inport;                      /* '<S34>/antiStallLogic' */
  uint8_T startEngCommand;             /* '<S4>/MessageEvaluation1' */
  uint8_T clutchTarget;                /* '<S4>/MessageEvaluation1' */
  uint8_T stopAntiStallCom;            /* '<S4>/MessageEvaluation1' */
  uint8_T RPMUpdateCounter;            /* '<S4>/MessageEvaluation1' */
  uint8_T Sum;                         /* '<S33>/Sum' */
  volatile uint8_T RateTransition_Buffer0;/* '<Root>/Rate Transition' */
  volatile uint8_T RateTransition3_Buffer0;/* '<Root>/Rate Transition3' */
  volatile uint8_T RateTransition5_Buffer0;/* '<Root>/Rate Transition5' */
  volatile uint8_T RateTransition30_Buffer0;/* '<Root>/Rate Transition30' */
  volatile uint8_T RateTransition33_Buffer0;/* '<Root>/Rate Transition33' */
  uint8_T is_c3_GCU_Model_genCode;     /* '<S7>/AccelerationRoutine' */
  uint8_T lastGearPin;                 /* '<S7>/AccelerationRoutine' */
  uint8_T is_active_c1_GCU_Model_genCode;/* '<S5>/GCULogic' */
  uint8_T is_MODES;                    /* '<S5>/GCULogic' */
  uint8_T is_active_MODES;             /* '<S5>/GCULogic' */
  uint8_T is_ACCELERATION;             /* '<S5>/GCULogic' */
  uint8_T is_ACC;                      /* '<S5>/GCULogic' */
  uint8_T is_ACTIVE;                   /* '<S5>/GCULogic' */
  uint8_T is_AUTOCROSS;                /* '<S5>/GCULogic' */
  uint8_T is_LAUNCH;                   /* '<S5>/GCULogic' */
  uint8_T is_ACTIVE_d;                 /* '<S5>/GCULogic' */
  uint8_T is_NEUTRAL_STATE;            /* '<S5>/GCULogic' */
  uint8_T is_active_NEUTRAL_STATE;     /* '<S5>/GCULogic' */
  uint8_T is_GEARSHIFT;                /* '<S5>/GCULogic' */
  uint8_T is_active_GEARSHIFT;         /* '<S5>/GCULogic' */
  uint8_T is_UPSHIFTING;               /* '<S5>/GCULogic' */
  uint8_T is_UP_REBOUND;               /* '<S5>/GCULogic' */
  uint8_T is_UP_PUSH;                  /* '<S5>/GCULogic' */
  uint8_T is_UP_START;                 /* '<S5>/GCULogic' */
  uint8_T is_DOWNSHIFTING;             /* '<S5>/GCULogic' */
  uint8_T is_DOWN_START;               /* '<S5>/GCULogic' */
  uint8_T is_DOWN_BRAKE;               /* '<S5>/GCULogic' */
  uint8_T is_EEPROM_TRIGGER;           /* '<S5>/GCULogic' */
  uint8_T is_active_EEPROM_TRIGGER;    /* '<S5>/GCULogic' */
  uint8_T is_START_ENGINE;             /* '<S5>/GCULogic' */
  uint8_T is_active_START_ENGINE;      /* '<S5>/GCULogic' */
  uint8_T is_SCAN_ADC;                 /* '<S5>/GCULogic' */
  uint8_T is_active_SCAN_ADC;          /* '<S5>/GCULogic' */
  uint8_T is_ANTISTALL_ENABLE;         /* '<S5>/GCULogic' */
  uint8_T is_active_ANTISTALL_ENABLE;  /* '<S5>/GCULogic' */
  uint8_T lastShift;                   /* '<S5>/GCULogic' */
  uint8_T lastCom;                     /* '<S5>/GCULogic' */
  uint8_T startCounter;                /* '<S5>/GCULogic' */
  uint8_T is_c6_GCU_Model_genCode;     /* '<S3>/EEPROM_OutputRequest' */
  uint8_T is_LOAD_TO_EEPROM;           /* '<S3>/EEPROM_OutputRequest' */
  uint8_T is_LOAD_FROM_EEPROM;         /* '<S3>/EEPROM_OutputRequest' */
  uint8_T counter;                     /* '<S3>/EEPROM_OutputRequest' */
  uint8_T HAL_ERROR;                   /* '<S3>/EEPROM_OutputRequest' */
  uint8_T lastRPMUpdate;               /* '<S34>/timeCounter' */
  uint8_T counter3;                    /* '<S2>/CAN_id' */
  uint8_T counter2;                    /* '<S2>/CAN_id' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: VoltageOffsetVector
   * Referenced by: '<S10>/OffSet'
   */
  real_T OffSet_Value[9];

  /* Expression: ConversionGainVector
   * Referenced by: '<S10>/OffSet1'
   */
  real_T OffSet1_Value[9];

  /* Expression: ConversionOffsetVector
   * Referenced by: '<S10>/OffSet2'
   */
  real_T OffSet2_Value[9];

  /* Pooled Parameter (Expression: [uint16(0),uint16(100),uint16(200),uint16(300),uint16(400),uint16(500),uint16(600),uint16(700)])
   * Referenced by:
   *   '<S2>/1-D Lookup Table1'
   *   '<S2>/1-D Lookup Table2'
   *   '<S2>/1-D Lookup Table3'
   */
  uint16_T pooled4[8];

  /* Pooled Parameter (Expression: [0:7])
   * Referenced by:
   *   '<S2>/1-D Lookup Table1'
   *   '<S2>/1-D Lookup Table2'
   *   '<S2>/1-D Lookup Table3'
   */
  uint16_T pooled5[8];
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint8_T UART_debug[10];              /* '<Root>/UART_debug' */
  real_T SelectMode;                   /* '<Root>/SelectMode' */
  uint8_T CAN[10];                     /* '<Root>/CAN' */
  uint32_T adc_buffer[9];              /* '<Root>/adc_buffer' */
  uint8_T inputRequest[20];            /* '<Root>/inputRequest' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint16_T debugValues[20];            /* '<Root>/debugValues  ' */
  uint32_T adc_data_vector[9];         /* '<Root>/adc_data_vector' */
  eepromRequest outputRequest;         /* '<Root>/outputRequest' */
  uint8_T readResult;                  /* '<Root>/readResult' */
  uint8_T writeResult;                 /* '<Root>/writeResult' */
  uint8_T wpState;                     /* '<Root>/wpState' */
  uint8_T dataRead[19];                /* '<Root>/dataRead' */
  int32_T gearshiftTimings[24];        /* '<Root>/gearshiftTimings' */
  int32_T accParameters[16];           /* '<Root>/accParameters' */
  int32_T autoXParameters[16];         /* '<Root>/autoXParameters' */
  int32_T antiStallParameters[8];      /* '<Root>/antiStallParameters' */
  real_T antiStallState;               /* '<Root>/antiStallState' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* External data declarations for dependent source files */
extern const uint16_T GCU_Model_genCode_U16GND;/* uint16_T ground */

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void GCU_Model_genCode_initialize(void);
extern void GCU_Model_genCode_step0(void);
extern void GCU_Model_genCode_step1(void);
extern void GCU_Model_genCode_step2(void);
extern void GCU_Model_genCode_step3(void);
extern void GCU_Model_genCode_step4(void);
extern void GCU_Model_genCode_step5(void);
extern void GCU_Model_genCode_step6(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S34>/Scope' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<S2>/Cast' : Eliminate redundant data type conversion
 * Block '<S2>/Cast1' : Eliminate redundant data type conversion
 * Block '<S18>/Cast' : Eliminate redundant data type conversion
 * Block '<S18>/Cast1' : Eliminate redundant data type conversion
 * Block '<S18>/Cast2' : Eliminate redundant data type conversion
 * Block '<S18>/Cast3' : Eliminate redundant data type conversion
 * Block '<S21>/Cast1' : Eliminate redundant data type conversion
 * Block '<S21>/Cast2' : Eliminate redundant data type conversion
 * Block '<S21>/Cast3' : Eliminate redundant data type conversion
 * Block '<S22>/Cast' : Eliminate redundant data type conversion
 * Block '<S22>/Cast1' : Eliminate redundant data type conversion
 * Block '<S22>/Cast2' : Eliminate redundant data type conversion
 * Block '<S22>/Cast3' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'GCU_Model_genCode'
 * '<S1>'   : 'GCU_Model_genCode/Anti_Stall_Debug'
 * '<S2>'   : 'GCU_Model_genCode/CAN_Send'
 * '<S3>'   : 'GCU_Model_genCode/EEPROM'
 * '<S4>'   : 'GCU_Model_genCode/GCU_CAN_Read'
 * '<S5>'   : 'GCU_Model_genCode/GCU_timer'
 * '<S6>'   : 'GCU_Model_genCode/InitializeFunction'
 * '<S7>'   : 'GCU_Model_genCode/Simulink_Acc_Debug'
 * '<S8>'   : 'GCU_Model_genCode/Triggered Subsystem'
 * '<S9>'   : 'GCU_Model_genCode/debugUART'
 * '<S10>'  : 'GCU_Model_genCode/update_ADC_data'
 * '<S11>'  : 'GCU_Model_genCode/Anti_Stall_Debug/AccelerationRoutine'
 * '<S12>'  : 'GCU_Model_genCode/CAN_Send/CAN_id'
 * '<S13>'  : 'GCU_Model_genCode/CAN_Send/Subsystem'
 * '<S14>'  : 'GCU_Model_genCode/CAN_Send/Subsystem1'
 * '<S15>'  : 'GCU_Model_genCode/CAN_Send/Subsystem2'
 * '<S16>'  : 'GCU_Model_genCode/CAN_Send/Subsystem3'
 * '<S17>'  : 'GCU_Model_genCode/CAN_Send/sendMessage'
 * '<S18>'  : 'GCU_Model_genCode/CAN_Send/Subsystem/sendMessage2'
 * '<S19>'  : 'GCU_Model_genCode/CAN_Send/Subsystem1/sendMessage3'
 * '<S20>'  : 'GCU_Model_genCode/CAN_Send/Subsystem2/sendMessage4'
 * '<S21>'  : 'GCU_Model_genCode/CAN_Send/Subsystem3/sendMessage1'
 * '<S22>'  : 'GCU_Model_genCode/CAN_Send/sendMessage/sendMessage'
 * '<S23>'  : 'GCU_Model_genCode/EEPROM/EEPROM_Load_Buffer'
 * '<S24>'  : 'GCU_Model_genCode/EEPROM/EEPROM_OutputRequest'
 * '<S25>'  : 'GCU_Model_genCode/EEPROM/Evaluate_Request'
 * '<S26>'  : 'GCU_Model_genCode/EEPROM/Evaluate_Request/Error'
 * '<S27>'  : 'GCU_Model_genCode/EEPROM/Evaluate_Request/LoadFromEEPROM'
 * '<S28>'  : 'GCU_Model_genCode/EEPROM/Evaluate_Request/Read'
 * '<S29>'  : 'GCU_Model_genCode/EEPROM/Evaluate_Request/Write'
 * '<S30>'  : 'GCU_Model_genCode/EEPROM/Evaluate_Request/LoadFromEEPROM/updateValues'
 * '<S31>'  : 'GCU_Model_genCode/GCU_CAN_Read/AAC_ExternalValues'
 * '<S32>'  : 'GCU_Model_genCode/GCU_CAN_Read/MessageEvaluation1'
 * '<S33>'  : 'GCU_Model_genCode/GCU_CAN_Read/MessageEvaluation1/setMap'
 * '<S34>'  : 'GCU_Model_genCode/GCU_timer/Anti_Stall_System'
 * '<S35>'  : 'GCU_Model_genCode/GCU_timer/Buzzer'
 * '<S36>'  : 'GCU_Model_genCode/GCU_timer/ClutchMotor'
 * '<S37>'  : 'GCU_Model_genCode/GCU_timer/Efi'
 * '<S38>'  : 'GCU_Model_genCode/GCU_timer/EngineControl'
 * '<S39>'  : 'GCU_Model_genCode/GCU_timer/Filtro_software'
 * '<S40>'  : 'GCU_Model_genCode/GCU_timer/GCULogic'
 * '<S41>'  : 'GCU_Model_genCode/GCU_timer/GearMotor1'
 * '<S42>'  : 'GCU_Model_genCode/GCU_timer/If Action Subsystem'
 * '<S43>'  : 'GCU_Model_genCode/GCU_timer/If Action Subsystem1'
 * '<S44>'  : 'GCU_Model_genCode/GCU_timer/Anti_Stall_System/antiStallLogic'
 * '<S45>'  : 'GCU_Model_genCode/GCU_timer/Anti_Stall_System/timeCounter'
 * '<S46>'  : 'GCU_Model_genCode/GCU_timer/Anti_Stall_System/antiStallLogic/AntiStallActivate'
 * '<S47>'  : 'GCU_Model_genCode/GCU_timer/Buzzer/BuzzerOff'
 * '<S48>'  : 'GCU_Model_genCode/GCU_timer/Buzzer/BuzzerOn'
 * '<S49>'  : 'GCU_Model_genCode/GCU_timer/ClutchMotor/ClutchMotor SetPosition '
 * '<S50>'  : 'GCU_Model_genCode/GCU_timer/Efi/Init'
 * '<S51>'  : 'GCU_Model_genCode/GCU_timer/Efi/SetCut'
 * '<S52>'  : 'GCU_Model_genCode/GCU_timer/Efi/SetRPMLimiter'
 * '<S53>'  : 'GCU_Model_genCode/GCU_timer/Efi/UnsetCut'
 * '<S54>'  : 'GCU_Model_genCode/GCU_timer/Efi/UnsetRPMLimiter'
 * '<S55>'  : 'GCU_Model_genCode/GCU_timer/EngineControl/EngineControl_Start'
 * '<S56>'  : 'GCU_Model_genCode/GCU_timer/EngineControl/EngineControl_Stop'
 * '<S57>'  : 'GCU_Model_genCode/GCU_timer/Filtro_software/IO Delay'
 * '<S58>'  : 'GCU_Model_genCode/GCU_timer/Filtro_software/Input Delay'
 * '<S59>'  : 'GCU_Model_genCode/GCU_timer/Filtro_software/Output Delay'
 * '<S60>'  : 'GCU_Model_genCode/GCU_timer/GCULogic/SCAN_ADC.ScanADC'
 * '<S61>'  : 'GCU_Model_genCode/GCU_timer/GearMotor1/Gearmotor_brake'
 * '<S62>'  : 'GCU_Model_genCode/GCU_timer/GearMotor1/Gearmotor_release'
 * '<S63>'  : 'GCU_Model_genCode/GCU_timer/GearMotor1/Gearmotor_turnLeft'
 * '<S64>'  : 'GCU_Model_genCode/GCU_timer/GearMotor1/Gearmotor_turnRight'
 * '<S65>'  : 'GCU_Model_genCode/Simulink_Acc_Debug/AccelerationRoutine'
 */
#endif                                 /* RTW_HEADER_GCU_Model_genCode_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
