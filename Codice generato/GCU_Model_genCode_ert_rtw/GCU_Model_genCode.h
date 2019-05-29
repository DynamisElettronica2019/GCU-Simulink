/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GCU_Model_genCode.h
 *
 * Code generated for Simulink model 'GCU_Model_genCode'.
 *
 * Model version                  : 1.229
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Wed May 29 22:55:03 2019
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
#define SS_INT64                       20
#endif

#ifndef SS_UINT64
#define SS_UINT64                      21
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
  TPS_START_LIMIT
} acc_params;

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
  AUTOX_TPS_START_LIMIT
} autoX_params;

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
  NEW_EEPROM = 25,
  GEARSHIFT_NUM = 23,
  ACC_PAR_NUM = 12,
  AUTOX_PAR_NUM = 12
} eepromConstants;

#endif

/* Block signals and states (default storage) for system '<S4>/AAC_ExternalValues' */
typedef struct {
  uint16_T UnitDelay_DSTATE[3];        /* '<S32>/Unit Delay' */
} DW_AAC_ExternalValues;

/* Block signals and states (default storage) for system '<S36>/SetRPMLimiter' */
typedef struct {
  uint8_T EfiSetRPMLimiter;            /* '<S45>/Efi SetRPMLimiter' */
} DW_SetRPMLimiter;

/* Block signals and states (default storage) for system '<S36>/UnsetRPMLimiter' */
typedef struct {
  uint8_T EfiUnSetRPMLimiter;          /* '<S47>/Efi UnSetRPMLimiter' */
} DW_UnsetRPMLimiter;

/* Block signals and states (default storage) for system '<S39>/Gearmotor_turnRight' */
typedef struct {
  uint8_T GearMotorTurnRight_o1;       /* '<S54>/GearMotor Turn Right' */
  uint8_T GearMotorTurnRight_o2;       /* '<S54>/GearMotor Turn Right' */
  uint8_T GearMotorTurnRight_o3;       /* '<S54>/GearMotor Turn Right' */
} DW_Gearmotor_turnRight;

/* Block signals and states (default storage) for system '<S39>/Gearmotor_brake' */
typedef struct {
  uint8_T GearMotorBrake_o1;           /* '<S51>/GearMotor Brake' */
  uint8_T GearMotorBrake_o2;           /* '<S51>/GearMotor Brake' */
  uint8_T GearMotorBrake_o3;           /* '<S51>/GearMotor Brake' */
} DW_Gearmotor_brake;

/* Block signals and states (default storage) for system '<S37>/EngineControl_Start' */
typedef struct {
  uint8_T EngineControlStart;          /* '<S48>/EngineControl Start' */
} DW_EngineControl_Start;

/* Block signals and states (default storage) for system '<S2>/Evaluate_Request' */
typedef struct {
  uint16_T gearshiftTimings[24];       /* '<S22>/updateValues' */
  uint16_T accParameters[16];          /* '<S22>/updateValues' */
  uint16_T autoXParameters[16];        /* '<S22>/updateValues' */
  uint8_T TmpSignalConversionAtsendEeprom[19];
  uint8_T Eeprom_read_o2[16];          /* '<S22>/Eeprom_read' */
  uint8_T Eeprom_read_o2_e[16];        /* '<S23>/Eeprom_read' */
  uint8_T page;
  uint8_T cell;
  uint8_T dataSize;
  uint8_T Eeprom_read_o1;              /* '<S22>/Eeprom_read' */
} DW_Evaluate_Request;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_Evaluate_Request Evaluate_Request_l;/* '<S2>/Evaluate_Request' */
  DW_EngineControl_Start EngineControl_Start_h;/* '<S37>/EngineControl_Start' */
  DW_Gearmotor_brake Gearmotor_brake_c;/* '<S39>/Gearmotor_brake' */
  DW_Gearmotor_turnRight Gearmotor_turnRight_f;/* '<S39>/Gearmotor_turnRight' */
  DW_UnsetRPMLimiter UnsetRPMLimiter_c;/* '<S36>/UnsetRPMLimiter' */
  DW_SetRPMLimiter SetRPMLimiter_e;    /* '<S36>/SetRPMLimiter' */
  DW_AAC_ExternalValues AAC_ExternalValues_f;/* '<S4>/AAC_ExternalValues' */
  volatile eepromRequest RateTransition_Buffer[40];/* '<S2>/Rate Transition' */
  eepromRequest RateTransition[20];    /* '<S2>/Rate Transition' */
  eepromRequest requestBuffer[20];     /* '<S2>/EEPROM_Load_Buffer' */
  eepromRequest outputRequest;         /* '<S2>/EEPROM_OutputRequest' */
  real_T RateTransition1;              /* '<S2>/Rate Transition1' */
  real_T lastInsertedIndex;            /* '<S2>/EEPROM_Load_Buffer' */
  volatile real_T RateTransition1_Buffer0;/* '<S2>/Rate Transition1' */
  real_T message;                      /* '<S7>/AccelerationRoutine' */
  real_T count;                        /* '<S7>/AccelerationRoutine' */
  real_T aac_clutchValue;              /* '<S5>/GCULogic' */
  real_T aac_clutchStep;               /* '<S5>/GCULogic' */
  real_T autoX_clutchValue;            /* '<S5>/GCULogic' */
  real_T autoX_clutchStep;             /* '<S5>/GCULogic' */
  real_T counterWait;                  /* '<S5>/GCULogic' */
  real_T lastEvaluatedIndex;           /* '<S2>/EEPROM_OutputRequest' */
  real_T reloadFlag;                   /* '<S2>/EEPROM_OutputRequest' */
  int32_T load_accParameters[12];      /* '<S6>/load_accParameters' */
  int32_T load_default_timings[23];    /* '<S6>/load_default_timings' */
  int32_T load_accParameters1[12];     /* '<S6>/load_accParameters1' */
  int32_T Merge[24];                   /* '<S20>/Merge' */
  int32_T Merge1[16];                  /* '<S20>/Merge1' */
  int32_T Merge2[16];                  /* '<S20>/Merge2' */
  int32_T sfEvent;                     /* '<S5>/GCULogic' */
  int32_T aac_dtRelease;               /* '<S5>/GCULogic' */
  int32_T autoX_dtRelease;             /* '<S5>/GCULogic' */
  int32_T ticksCounter;                /* '<S5>/GCULogic' */
  uint32_T update_ADC_data[9];         /* '<S11>/update_ADC_data' */
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
  uint16_T Assignment[3];              /* '<S32>/Assignment' */
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
  uint16_T id;                         /* '<S7>/AccelerationRoutine' */
  uint16_T firstInt;                   /* '<S7>/AccelerationRoutine' */
  uint16_T secondInt;                  /* '<S7>/AccelerationRoutine' */
  uint16_T thirdInt;                   /* '<S7>/AccelerationRoutine' */
  uint16_T stateFb;                    /* '<S5>/GCULogic' */
  uint16_T UnpackCanUart_o1;           /* '<S4>/UnpackCanUart' */
  uint16_T UnpackCanUart_o2;           /* '<S4>/UnpackCanUart' */
  uint16_T UnpackCanUart_o3;           /* '<S4>/UnpackCanUart' */
  uint16_T UnpackCanUart_o4;           /* '<S4>/UnpackCanUart' */
  uint16_T UnpackCanUart_o5;           /* '<S4>/UnpackCanUart' */
  uint16_T currGear;                   /* '<S4>/MessageEvaluation1' */
  uint16_T tractionTarget;             /* '<S4>/MessageEvaluation1' */
  uint16_T mapTarget;                  /* '<S4>/MessageEvaluation1' */
  uint16_T rpmLimiterTarget;           /* '<S4>/MessageEvaluation1' */
  uint16_T uDLookupTable2;             /* '<S1>/1-D Lookup Table2' */
  uint16_T uDLookupTable1;             /* '<S1>/1-D Lookup Table1' */
  uint16_T uDLookupTable3;             /* '<S1>/1-D Lookup Table3' */
  uint16_T Cast;                       /* '<S14>/Cast' */
  uint16_T Cast_d;                     /* '<S16>/Cast' */
  uint16_T Cast1;                      /* '<S16>/Cast1' */
  uint16_T Cast2;                      /* '<S16>/Cast2' */
  uint16_T Cast3;                      /* '<S16>/Cast3' */
  uint16_T Cast_o;                     /* '<S17>/Cast' */
  uint16_T Cast1_c;                    /* '<S17>/Cast1' */
  uint16_T Cast2_e;                    /* '<S17>/Cast2' */
  uint16_T Cast3_j;                    /* '<S17>/Cast3' */
  uint16_T gcu_traction_limiter_loil_efi_i;/* '<S1>/CAN_id' */
  uint16_T gcu_clutch_mode_map_sw_id;  /* '<S1>/CAN_id' */
  uint16_T gcu_traction_limiter_autog_acc_;/* '<S1>/CAN_id' */
  uint16_T gcu_debug_1_id;             /* '<S1>/CAN_id' */
  uint16_T gcu_debug_2_id;             /* '<S1>/CAN_id' */
  uint16_T Read_oil_sensor;            /* '<S11>/Read_oil_sensor' */
  volatile uint16_T RateTransition27_Buffer0;/* '<Root>/Rate Transition27' */
  uint16_T rpm;                        /* '<S7>/AccelerationRoutine' */
  uint16_T wheelSpeed;                 /* '<S7>/AccelerationRoutine' */
  uint16_T currGear_m;                 /* '<S7>/AccelerationRoutine' */
  uint16_T lastAacCom;                 /* '<S5>/GCULogic' */
  uint16_T lastShiftCom;               /* '<S5>/GCULogic' */
  uint16_T lastAutoXCom;               /* '<S5>/GCULogic' */
  uint16_T aacCounter;                 /* '<S5>/GCULogic' */
  uint16_T autoXCounter;               /* '<S5>/GCULogic' */
  uint16_T timerCounter;               /* '<S5>/GCULogic' */
  volatile int8_T RateTransition9_ActiveBufIdx;/* '<Root>/Rate Transition9' */
  volatile int8_T RateTransition1_ActiveBufIdx;/* '<Root>/Rate Transition1' */
  volatile int8_T RateTransition2_ActiveBufIdx;/* '<Root>/Rate Transition2' */
  volatile int8_T RateTransition4_ActiveBufIdx;/* '<Root>/Rate Transition4' */
  volatile int8_T RateTransition5_ActiveBufIdx;/* '<Root>/Rate Transition5' */
  volatile int8_T RateTransition8_ActiveBufIdx;/* '<Root>/Rate Transition8' */
  volatile int8_T RateTransition29_ActiveBufIdx;/* '<Root>/Rate Transition29' */
  volatile int8_T RateTransition_ActiveBufIdx;/* '<S2>/Rate Transition' */
  volatile int8_T RateTransition14_semaphoreTaken;/* '<Root>/Rate Transition14' */
  volatile int8_T RateTransition18_semaphoreTaken;/* '<Root>/Rate Transition18' */
  uint8_T RateTransition5[2];          /* '<Root>/Rate Transition5' */
  uint8_T MultiportSwitch[10];         /* '<Root>/Multiport Switch' */
  uint8_T PackCanUart[10];             /* '<S7>/PackCanUart' */
  uint8_T OutportBufferFordataRead[19];
  uint8_T clutchCommand[2];            /* '<S4>/MessageEvaluation1' */
  uint8_T PackCANMsg[8];               /* '<S13>/PackCANMsg' */
  uint8_T PackCANMsg_l[8];             /* '<S14>/PackCANMsg' */
  uint8_T PackCANMsg_e[8];             /* '<S15>/PackCANMsg' */
  uint8_T PackCANMsg_f[8];             /* '<S16>/PackCANMsg' */
  uint8_T PackCANMsg_o[8];             /* '<S17>/PackCANMsg' */
  uint8_T Pack_Uart_Message[40];       /* '<S9>/Pack_Uart_Message' */
  volatile uint8_T RateTransition5_Buffer[4];/* '<Root>/Rate Transition5' */
  uint8_T tempShiftedArray[50];        /* '<S2>/EEPROM_OutputRequest' */
  uint8_T newData[16];                 /* '<S2>/EEPROM_OutputRequest' */
  uint8_T RateTransition_d;            /* '<Root>/Rate Transition' */
  uint8_T RateTransition3;             /* '<Root>/Rate Transition3' */
  uint8_T RateTransition6;             /* '<Root>/Rate Transition6' */
  uint8_T RateTransition7;             /* '<Root>/Rate Transition7' */
  uint8_T Eeprom_init_o1;              /* '<S6>/Eeprom_init' */
  uint8_T Eeprom_init_o2;              /* '<S6>/Eeprom_init' */
  uint8_T Eeprom_init_o3;              /* '<S6>/Eeprom_init' */
  uint8_T Pin_H;                       /* '<S39>/Pin_H' */
  uint8_T Pin_In1;                     /* '<S39>/Pin_In1' */
  uint8_T Pin_In2;                     /* '<S39>/Pin_In2' */
  uint8_T clutchCurrVal;               /* '<S5>/GCULogic' */
  uint8_T Eeprom_read_o1;              /* '<S23>/Eeprom_read' */
  uint8_T Eeprom_write_o1;             /* '<S24>/Eeprom_write' */
  uint8_T Eeprom_write_o2;             /* '<S24>/Eeprom_write' */
  uint8_T EngineControlStop;           /* '<S49>/EngineControl Stop' */
  uint8_T GearMotorTurnLeft_o1;        /* '<S53>/GearMotor Turn Left' */
  uint8_T GearMotorTurnLeft_o2;        /* '<S53>/GearMotor Turn Left' */
  uint8_T GearMotorTurnLeft_o3;        /* '<S53>/GearMotor Turn Left' */
  uint8_T GearMotorRelease;            /* '<S52>/GearMotor Release' */
  uint8_T EfiUnSetCut;                 /* '<S46>/Efi UnSetCut' */
  uint8_T EfiSetCut;                   /* '<S44>/Efi SetCut' */
  uint8_T Minus;                       /* '<S42>/Minus' */
  uint8_T startEngCommand;             /* '<S4>/MessageEvaluation1' */
  volatile uint8_T RateTransition_Buffer0;/* '<Root>/Rate Transition' */
  volatile uint8_T RateTransition3_Buffer0;/* '<Root>/Rate Transition3' */
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
  uint8_T lastShift;                   /* '<S5>/GCULogic' */
  uint8_T lastClutchCom;               /* '<S5>/GCULogic' */
  uint8_T lastCom;                     /* '<S5>/GCULogic' */
  uint8_T startCounter;                /* '<S5>/GCULogic' */
  uint8_T is_c6_GCU_Model_genCode;     /* '<S2>/EEPROM_OutputRequest' */
  uint8_T is_LOAD_TO_EEPROM;           /* '<S2>/EEPROM_OutputRequest' */
  uint8_T is_LOAD_FROM_EEPROM;         /* '<S2>/EEPROM_OutputRequest' */
  uint8_T counter;                     /* '<S2>/EEPROM_OutputRequest' */
  uint8_T HAL_ERROR;                   /* '<S2>/EEPROM_OutputRequest' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [uint16(0),uint16(100),uint16(200),uint16(300),uint16(400),uint16(500),uint16(600),uint16(700)])
   * Referenced by:
   *   '<S1>/1-D Lookup Table1'
   *   '<S1>/1-D Lookup Table2'
   *   '<S1>/1-D Lookup Table3'
   */
  uint16_T pooled4[8];

  /* Pooled Parameter (Expression: [0:7])
   * Referenced by:
   *   '<S1>/1-D Lookup Table1'
   *   '<S1>/1-D Lookup Table2'
   *   '<S1>/1-D Lookup Table3'
   */
  uint16_T pooled5[8];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<Root>/Rate Transition1'
   *   '<Root>/Rate Transition2'
   *   '<Root>/Rate Transition27'
   *   '<Root>/Rate Transition29'
   *   '<Root>/Rate Transition4'
   *   '<Root>/Rate Transition8'
   *   '<S1>/Constant'
   *   '<S9>/debugValues'
   *   '<S11>/oil_sensor'
   *   '<S32>/Values'
   */
  uint16_T pooled6;
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
 * Block '<S1>/Cast' : Eliminate redundant data type conversion
 * Block '<S1>/Cast1' : Eliminate redundant data type conversion
 * Block '<S13>/Cast' : Eliminate redundant data type conversion
 * Block '<S13>/Cast1' : Eliminate redundant data type conversion
 * Block '<S13>/Cast2' : Eliminate redundant data type conversion
 * Block '<S13>/Cast3' : Eliminate redundant data type conversion
 * Block '<S14>/Cast1' : Eliminate redundant data type conversion
 * Block '<S14>/Cast2' : Eliminate redundant data type conversion
 * Block '<S14>/Cast3' : Eliminate redundant data type conversion
 * Block '<S15>/Cast' : Eliminate redundant data type conversion
 * Block '<S15>/Cast1' : Eliminate redundant data type conversion
 * Block '<S15>/Cast2' : Eliminate redundant data type conversion
 * Block '<S15>/Cast3' : Eliminate redundant data type conversion
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
 * '<S1>'   : 'GCU_Model_genCode/CAN_Send'
 * '<S2>'   : 'GCU_Model_genCode/EEPROM'
 * '<S3>'   : 'GCU_Model_genCode/EEPROM Memory'
 * '<S4>'   : 'GCU_Model_genCode/GCU_CAN_Read'
 * '<S5>'   : 'GCU_Model_genCode/GCU_timer'
 * '<S6>'   : 'GCU_Model_genCode/InitializeFunction'
 * '<S7>'   : 'GCU_Model_genCode/Simulink_Debug'
 * '<S8>'   : 'GCU_Model_genCode/Triggered Subsystem'
 * '<S9>'   : 'GCU_Model_genCode/debugUART'
 * '<S10>'  : 'GCU_Model_genCode/rpmPin_update'
 * '<S11>'  : 'GCU_Model_genCode/update_ADC_data'
 * '<S12>'  : 'GCU_Model_genCode/CAN_Send/CAN_id'
 * '<S13>'  : 'GCU_Model_genCode/CAN_Send/sendMessage'
 * '<S14>'  : 'GCU_Model_genCode/CAN_Send/sendMessage1'
 * '<S15>'  : 'GCU_Model_genCode/CAN_Send/sendMessage2'
 * '<S16>'  : 'GCU_Model_genCode/CAN_Send/sendMessage3'
 * '<S17>'  : 'GCU_Model_genCode/CAN_Send/sendMessage4'
 * '<S18>'  : 'GCU_Model_genCode/EEPROM/EEPROM_Load_Buffer'
 * '<S19>'  : 'GCU_Model_genCode/EEPROM/EEPROM_OutputRequest'
 * '<S20>'  : 'GCU_Model_genCode/EEPROM/Evaluate_Request'
 * '<S21>'  : 'GCU_Model_genCode/EEPROM/Evaluate_Request/Error'
 * '<S22>'  : 'GCU_Model_genCode/EEPROM/Evaluate_Request/LoadFromEEPROM'
 * '<S23>'  : 'GCU_Model_genCode/EEPROM/Evaluate_Request/Read'
 * '<S24>'  : 'GCU_Model_genCode/EEPROM/Evaluate_Request/Write'
 * '<S25>'  : 'GCU_Model_genCode/EEPROM/Evaluate_Request/LoadFromEEPROM/updateValues'
 * '<S26>'  : 'GCU_Model_genCode/EEPROM Memory/changeAccValue'
 * '<S27>'  : 'GCU_Model_genCode/EEPROM Memory/changeTimingsValue'
 * '<S28>'  : 'GCU_Model_genCode/EEPROM Memory/changeAccValue/ '
 * '<S29>'  : 'GCU_Model_genCode/EEPROM Memory/changeAccValue/Triggered Subsystem'
 * '<S30>'  : 'GCU_Model_genCode/EEPROM Memory/changeTimingsValue/ '
 * '<S31>'  : 'GCU_Model_genCode/EEPROM Memory/changeTimingsValue/Triggered Subsystem'
 * '<S32>'  : 'GCU_Model_genCode/GCU_CAN_Read/AAC_ExternalValues'
 * '<S33>'  : 'GCU_Model_genCode/GCU_CAN_Read/MessageEvaluation1'
 * '<S34>'  : 'GCU_Model_genCode/GCU_timer/Buzzer'
 * '<S35>'  : 'GCU_Model_genCode/GCU_timer/ClutchMotor'
 * '<S36>'  : 'GCU_Model_genCode/GCU_timer/Efi'
 * '<S37>'  : 'GCU_Model_genCode/GCU_timer/EngineControl'
 * '<S38>'  : 'GCU_Model_genCode/GCU_timer/GCULogic'
 * '<S39>'  : 'GCU_Model_genCode/GCU_timer/GearMotor1'
 * '<S40>'  : 'GCU_Model_genCode/GCU_timer/Buzzer/BuzzerOff'
 * '<S41>'  : 'GCU_Model_genCode/GCU_timer/Buzzer/BuzzerOn'
 * '<S42>'  : 'GCU_Model_genCode/GCU_timer/ClutchMotor/ClutchMotor SetPosition '
 * '<S43>'  : 'GCU_Model_genCode/GCU_timer/Efi/Init'
 * '<S44>'  : 'GCU_Model_genCode/GCU_timer/Efi/SetCut'
 * '<S45>'  : 'GCU_Model_genCode/GCU_timer/Efi/SetRPMLimiter'
 * '<S46>'  : 'GCU_Model_genCode/GCU_timer/Efi/UnsetCut'
 * '<S47>'  : 'GCU_Model_genCode/GCU_timer/Efi/UnsetRPMLimiter'
 * '<S48>'  : 'GCU_Model_genCode/GCU_timer/EngineControl/EngineControl_Start'
 * '<S49>'  : 'GCU_Model_genCode/GCU_timer/EngineControl/EngineControl_Stop'
 * '<S50>'  : 'GCU_Model_genCode/GCU_timer/GCULogic/SCAN_ADC.ScanADC'
 * '<S51>'  : 'GCU_Model_genCode/GCU_timer/GearMotor1/Gearmotor_brake'
 * '<S52>'  : 'GCU_Model_genCode/GCU_timer/GearMotor1/Gearmotor_release'
 * '<S53>'  : 'GCU_Model_genCode/GCU_timer/GearMotor1/Gearmotor_turnLeft'
 * '<S54>'  : 'GCU_Model_genCode/GCU_timer/GearMotor1/Gearmotor_turnRight'
 * '<S55>'  : 'GCU_Model_genCode/Simulink_Debug/AccelerationRoutine'
 * '<S56>'  : 'GCU_Model_genCode/rpmPin_update/Triggered_Subsystem'
 * '<S57>'  : 'GCU_Model_genCode/rpmPin_update/Triggered_Subsystem1'
 */
#endif                                 /* RTW_HEADER_GCU_Model_genCode_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
