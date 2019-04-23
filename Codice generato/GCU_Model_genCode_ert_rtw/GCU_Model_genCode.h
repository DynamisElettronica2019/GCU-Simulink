/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GCU_Model_genCode.h
 *
 * Code generated for Simulink model 'GCU_Model_genCode'.
 *
 * Model version                  : 1.64
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Sun Apr 21 17:22:39 2019
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
#include "zero_crossing_types.h"
#ifndef GCU_Model_genCode_COMMON_INCLUDES_
# define GCU_Model_genCode_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
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

#ifndef DEFINED_TYPEDEF_FOR_aac_params_
#define DEFINED_TYPEDEF_FOR_aac_params_

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
  SPEED_LIMIT_4_5
} aac_params;

#endif

#ifndef DEFINED_TYPEDEF_FOR_aac_values_
#define DEFINED_TYPEDEF_FOR_aac_values_

typedef enum {
  RPM = 0,                             /* Default value */
  WHEEL_SPEED,
  APPS
} aac_values;

#endif

#ifndef DEFINED_TYPEDEF_FOR_timings_
#define DEFINED_TYPEDEF_FOR_timings_

typedef enum {
  DEFAULT_DELAY = 20,                  /* Default value */
  DEFAULT_UP_REBOUND = 15,
  DEFAULT_UP_BRAKE = 20,
  DEFAULT_UP_PUSH_1_2 = 115,
  DEFAULT_UP_PUSH_2_3 = 100,
  DEFAULT_UP_PUSH_3_4 = 100,
  DEFAULT_UP_PUSH_4_5 = 100,
  DEFAULT_CLUTCH = 70,
  DEFAULT_DN_PUSH = 100,
  DEFAULT_DN_BRAKE = 15,
  DEFAULT_DN_REBOUND = 20,
  DEFAULT_NT_CLUTCH_DELAY = 20,
  DEFAULT_NT_REBOUND_1_N = 15,
  DEFAULT_NT_REBOUND_2_N = 15,
  DEFAULT_NT_BRAKE_1_N = 35,
  DEFAULT_NT_BRAKE_2_N = 35,
  DEFAULT_NT_PUSH_1_N = 22,
  DEFAULT_NT_PUSH_2_N = 25,
  DEFAULT_NT_CLUTCH_1_N = 300,
  DEFAULT_NT_CLUTCH_2_N = 300,
  DEFAULT_DOWN_TIME_CHECK = 500,
  DEFAULT_UP_TIME_CHECK = 500,
  DEFAULT_MAX_TRIES = 2
} timings;

#endif

/* Block signals and states (default storage) for system '<S3>/TractionValue' */
typedef struct {
  uint16_T Divide;                     /* '<S18>/Divide' */
  uint16_T UnitDelay_DSTATE;           /* '<S18>/Unit Delay' */
  uint8_T PackCanUart[10];             /* '<S21>/PackCanUart' */
  uint8_T PackCanUart_g[10];           /* '<S22>/PackCanUart' */
} DW_TractionValue;

/* Block signals and states (default storage) for system '<S16>/Efi_setRpmLimiter' */
typedef struct {
  uint8_T EfiSetRPMLimiter;            /* '<S19>/Efi SetRPMLimiter' */
} DW_Efi_setRpmLimiter;

/* Block signals and states (default storage) for system '<S16>/Efi_unsetRpmLimiter' */
typedef struct {
  uint8_T EfiUnSetRPMLimiter;          /* '<S20>/Efi UnSetRPMLimiter' */
} DW_Efi_unsetRpmLimiter;

/* Block signals and states (default storage) for system '<S3>/AAC_ExternalValues' */
typedef struct {
  uint16_T UnitDelay_DSTATE[3];        /* '<S15>/Unit Delay' */
} DW_AAC_ExternalValues;

/* Block signals and states (default storage) for system '<S27>/Gearmotor_turnRight' */
typedef struct {
  uint8_T GearMotorTurnRight_o1;       /* '<S41>/GearMotor Turn Right' */
  uint8_T GearMotorTurnRight_o2;       /* '<S41>/GearMotor Turn Right' */
  uint8_T GearMotorTurnRight_o3;       /* '<S41>/GearMotor Turn Right' */
} DW_Gearmotor_turnRight;

/* Block signals and states (default storage) for system '<S27>/Gearmotor_brake' */
typedef struct {
  uint8_T GearMotorBrake_o1;           /* '<S38>/GearMotor Brake' */
  uint8_T GearMotorBrake_o2;           /* '<S38>/GearMotor Brake' */
  uint8_T GearMotorBrake_o3;           /* '<S38>/GearMotor Brake' */
} DW_Gearmotor_brake;

/* Block signals and states (default storage) for system '<S25>/EngineControl_Start' */
typedef struct {
  uint8_T EngineControlStart;          /* '<S35>/EngineControl Start' */
} DW_EngineControl_Start;

/* Block signals and states (default storage) for system '<S26>/sendUpdatesSW' */
typedef struct {
  uint8_T PackCanUart[10];             /* '<S37>/PackCanUart' */
} DW_sendUpdatesSW;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_sendUpdatesSW sendUpdatesSW_e;    /* '<S26>/sendUpdatesSW' */
  DW_EngineControl_Start EngineControl_Start_h;/* '<S25>/EngineControl_Start' */
  DW_Gearmotor_brake Gearmotor_brake_c;/* '<S27>/Gearmotor_brake' */
  DW_Gearmotor_turnRight Gearmotor_turnRight_f;/* '<S27>/Gearmotor_turnRight' */
  DW_Efi_unsetRpmLimiter UnsetRPMLimiter_c;/* '<S24>/UnsetRPMLimiter' */
  DW_Efi_setRpmLimiter SetRPMLimiter_e;/* '<S24>/SetRPMLimiter' */
  DW_AAC_ExternalValues AAC_ExternalValues_f;/* '<S3>/AAC_ExternalValues' */
  DW_Efi_unsetRpmLimiter Efi_unsetRpmLimiter_f;/* '<S16>/Efi_unsetRpmLimiter' */
  DW_Efi_setRpmLimiter Efi_setRpmLimiter_b;/* '<S16>/Efi_setRpmLimiter' */
  DW_TractionValue TractionValue_h;    /* '<S3>/TractionValue' */
  real_T message;                      /* '<S6>/AccelerationRoutine' */
  real_T count;                        /* '<S6>/AccelerationRoutine' */
  real_T aac_clutchValue;              /* '<S4>/GCULogic' */
  real_T aac_clutchStep;               /* '<S4>/GCULogic' */
  int32_T aac_parameters[11];          /* '<S4>/GCULogic' */
  int32_T sfEvent;                     /* '<S4>/GCULogic' */
  int32_T aac_dtRelease;               /* '<S4>/GCULogic' */
  int32_T ticksCounter;                /* '<S4>/GCULogic' */
  uint32_T update_ADC_data[10];        /* '<S9>/update_ADC_data' */
  volatile uint32_T RateTransition9_Buffer[20];/* '<Root>/Rate Transition9' */
  volatile uint32_T RateTransition18_Buffer0[10];/* '<Root>/Rate Transition18' */
  uint16_T RateTransition1[3];         /* '<Root>/Rate Transition1' */
  uint16_T RateTransition2[2];         /* '<Root>/Rate Transition2' */
  uint16_T RateTransition4[2];         /* '<Root>/Rate Transition4' */
  uint16_T RateTransition8[2];         /* '<Root>/Rate Transition8' */
  uint16_T lastModeCom[2];             /* '<S4>/GCULogic' */
  uint16_T shiftCommand[2];            /* '<S3>/MessageEvaluation' */
  uint16_T aacCommand[2];              /* '<S3>/MessageEvaluation' */
  uint16_T modeCommand[2];             /* '<S3>/MessageEvaluation' */
  uint16_T Assignment[3];              /* '<S15>/Assignment' */
  uint16_T TmpSignalConversionAtPack_Uart_[10];
  volatile uint16_T RateTransition1_Buffer[6];/* '<Root>/Rate Transition1' */
  volatile uint16_T RateTransition2_Buffer[4];/* '<Root>/Rate Transition2' */
  volatile uint16_T RateTransition4_Buffer[4];/* '<Root>/Rate Transition4' */
  volatile uint16_T RateTransition8_Buffer[4];/* '<Root>/Rate Transition8' */
  volatile uint16_T RateTransition11_Buffer0[3];/* '<Root>/Rate Transition11' */
  volatile uint16_T RateTransition14_Buffer0[2];/* '<Root>/Rate Transition14' */
  volatile uint16_T RateTransition17_Buffer0[2];/* '<Root>/Rate Transition17' */
  uint16_T RateTransition22;           /* '<Root>/Rate Transition22' */
  uint16_T RateTransition21;           /* '<Root>/Rate Transition21' */
  uint16_T RateTransition23;           /* '<Root>/Rate Transition23' */
  uint16_T id;                         /* '<S6>/AccelerationRoutine' */
  uint16_T firstInt;                   /* '<S6>/AccelerationRoutine' */
  uint16_T secondInt;                  /* '<S6>/AccelerationRoutine' */
  uint16_T accFb;                      /* '<S4>/GCULogic' */
  uint16_T valCode;                    /* '<S4>/GCULogic' */
  uint16_T value;                      /* '<S4>/GCULogic' */
  uint16_T UnpackCanUart_o1;           /* '<S3>/UnpackCanUart' */
  uint16_T UnpackCanUart_o2;           /* '<S3>/UnpackCanUart' */
  uint16_T UnpackCanUart_o3;           /* '<S3>/UnpackCanUart' */
  uint16_T UnpackCanUart_o4;           /* '<S3>/UnpackCanUart' */
  uint16_T UnpackCanUart_o5;           /* '<S3>/UnpackCanUart' */
  uint16_T currGear;                   /* '<S3>/MessageEvaluation' */
  uint16_T Assignment_e;               /* '<S18>/Assignment' */
  uint16_T Cast;                       /* '<S10>/Cast' */
  uint16_T Cast1;                      /* '<S10>/Cast1' */
  uint16_T Cast2;                      /* '<S10>/Cast2' */
  uint16_T Cast3;                      /* '<S10>/Cast3' */
  uint16_T Cast_p;                     /* '<S11>/Cast' */
  uint16_T Cast1_d;                    /* '<S11>/Cast1' */
  uint16_T Cast2_i;                    /* '<S11>/Cast2' */
  uint16_T Cast3_f;                    /* '<S11>/Cast3' */
  uint16_T Cast_k;                     /* '<S12>/Cast' */
  uint16_T Cast1_k;                    /* '<S12>/Cast1' */
  uint16_T Cast_j;                     /* '<S13>/Cast' */
  uint16_T Cast1_p;                    /* '<S13>/Cast1' */
  uint16_T rpm;                        /* '<S6>/AccelerationRoutine' */
  uint16_T wheelSpeed;                 /* '<S6>/AccelerationRoutine' */
  uint16_T currGear_m;                 /* '<S6>/AccelerationRoutine' */
  uint16_T lastAacCom;                 /* '<S4>/GCULogic' */
  uint16_T lastShiftCom;               /* '<S4>/GCULogic' */
  uint16_T aacCounter;                 /* '<S4>/GCULogic' */
  volatile int8_T RateTransition1_ActiveBufIdx;/* '<Root>/Rate Transition1' */
  volatile int8_T RateTransition2_ActiveBufIdx;/* '<Root>/Rate Transition2' */
  volatile int8_T RateTransition4_ActiveBufIdx;/* '<Root>/Rate Transition4' */
  volatile int8_T RateTransition5_ActiveBufIdx;/* '<Root>/Rate Transition5' */
  volatile int8_T RateTransition8_ActiveBufIdx;/* '<Root>/Rate Transition8' */
  volatile int8_T RateTransition11_semaphoreTaken;/* '<Root>/Rate Transition11' */
  volatile int8_T RateTransition14_semaphoreTaken;/* '<Root>/Rate Transition14' */
  volatile int8_T RateTransition17_semaphoreTaken;/* '<Root>/Rate Transition17' */
  volatile int8_T RateTransition15_semaphoreTaken;/* '<Root>/Rate Transition15' */
  volatile int8_T RateTransition9_ActiveBufIdx;/* '<Root>/Rate Transition9' */
  volatile int8_T RateTransition18_semaphoreTaken;/* '<Root>/Rate Transition18' */
  uint8_T RateTransition5[2];          /* '<Root>/Rate Transition5' */
  uint8_T MultiportSwitch[10];         /* '<Root>/Multiport Switch' */
  uint8_T PackCanUart[10];             /* '<S6>/PackCanUart' */
  uint8_T clutchCommand[2];            /* '<S3>/MessageEvaluation' */
  uint8_T PackCANMsg[8];               /* '<S10>/PackCANMsg' */
  uint8_T PackCANMsg_g[8];             /* '<S11>/PackCANMsg' */
  uint8_T PackCANMsg_i[8];             /* '<S12>/PackCANMsg' */
  uint8_T PackCANMsg_p[8];             /* '<S13>/PackCANMsg' */
  uint8_T PackCANMsg_o[8];             /* '<S14>/PackCANMsg' */
  uint8_T Pack_Uart_Message1[20];      /* '<S2>/Pack_Uart_Message1' */
  volatile uint8_T RateTransition5_Buffer[4];/* '<Root>/Rate Transition5' */
  volatile uint8_T RateTransition15_Buffer0[2];/* '<Root>/Rate Transition15' */
  uint8_T RateTransition;              /* '<Root>/Rate Transition' */
  uint8_T RateTransition3;             /* '<Root>/Rate Transition3' */
  uint8_T RateTransition7;             /* '<Root>/Rate Transition7' */
  uint8_T RateTransition6;             /* '<Root>/Rate Transition6' */
  uint8_T Cast_a;                      /* '<Root>/Cast' */
  uint8_T Merge;                       /* '<S8>/Merge' */
  uint8_T Merge2;                      /* '<S24>/Merge2' */
  uint8_T Pin_H;                       /* '<S27>/Pin_H' */
  uint8_T Pin_In1;                     /* '<S27>/Pin_In1' */
  uint8_T clutchCurrVal;               /* '<S4>/GCULogic' */
  uint8_T EngineControlStop;           /* '<S36>/EngineControl Stop' */
  uint8_T GearMotorTurnLeft_o1;        /* '<S40>/GearMotor Turn Left' */
  uint8_T GearMotorTurnLeft_o2;        /* '<S40>/GearMotor Turn Left' */
  uint8_T GearMotorTurnLeft_o3;        /* '<S40>/GearMotor Turn Left' */
  uint8_T GearMotorRelease;            /* '<S39>/GearMotor Release' */
  uint8_T EfiUnSetCut;                 /* '<S33>/Efi UnSetCut' */
  uint8_T EfiSetCut;                   /* '<S31>/Efi SetCut' */
  uint8_T Minus;                       /* '<S29>/Minus' */
  uint8_T Merge_i;                     /* '<S16>/Merge' */
  uint8_T startEngCommand;             /* '<S3>/MessageEvaluation' */
  volatile uint8_T RateTransition_Buffer0;/* '<Root>/Rate Transition' */
  volatile uint8_T RateTransition3_Buffer0;/* '<Root>/Rate Transition3' */
  volatile uint8_T RateTransition_Buffer0_g;/* '<S8>/Rate Transition' */
  uint8_T is_c3_GCU_Model_genCode;     /* '<S6>/AccelerationRoutine' */
  uint8_T lastGearPin;                 /* '<S6>/AccelerationRoutine' */
  uint8_T is_active_c1_GCU_Model_genCode;/* '<S4>/GCULogic' */
  uint8_T is_MODES;                    /* '<S4>/GCULogic' */
  uint8_T is_active_MODES;             /* '<S4>/GCULogic' */
  uint8_T is_ACCELERATION;             /* '<S4>/GCULogic' */
  uint8_T is_AAC;                      /* '<S4>/GCULogic' */
  uint8_T is_ACTIVE;                   /* '<S4>/GCULogic' */
  uint8_T is_NEUTRAL_STATE;            /* '<S4>/GCULogic' */
  uint8_T is_active_NEUTRAL_STATE;     /* '<S4>/GCULogic' */
  uint8_T is_GEARSHIFT;                /* '<S4>/GCULogic' */
  uint8_T is_active_GEARSHIFT;         /* '<S4>/GCULogic' */
  uint8_T is_UPSHIFTING;               /* '<S4>/GCULogic' */
  uint8_T is_UP_REBOUND;               /* '<S4>/GCULogic' */
  uint8_T is_UP_PUSH;                  /* '<S4>/GCULogic' */
  uint8_T is_UP_START;                 /* '<S4>/GCULogic' */
  uint8_T is_DOWNSHIFTING;             /* '<S4>/GCULogic' */
  uint8_T is_DOWN_START;               /* '<S4>/GCULogic' */
  uint8_T is_DOWN_BRAKE;               /* '<S4>/GCULogic' */
  uint8_T is_START_ENGINE;             /* '<S4>/GCULogic' */
  uint8_T is_active_START_ENGINE;      /* '<S4>/GCULogic' */
  uint8_T lastShift;                   /* '<S4>/GCULogic' */
  uint8_T lastClutchCom;               /* '<S4>/GCULogic' */
  uint8_T lastCom;                     /* '<S4>/GCULogic' */
  uint8_T startCounter;                /* '<S4>/GCULogic' */
  uint8_T is_active_c2_GCU_Model_genCode;/* '<S3>/MessageEvaluation' */
  uint8_T is_c2_GCU_Model_genCode;     /* '<S3>/MessageEvaluation' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Triggered_Subsystem1_Trig_ZCE;/* '<S8>/Triggered_Subsystem1' */
  ZCSigState Triggered_Subsystem_Trig_ZCE;/* '<S8>/Triggered_Subsystem' */
} PrevZCX;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: 100)
   * Referenced by:
   *   '<S10>/ADC_data1_ID'
   *   '<S11>/ADC_data1_ID'
   *   '<S12>/ADC_data1_ID'
   *   '<S13>/ADC_data1_ID'
   *   '<S14>/ADC_data1_ID'
   *   '<S18>/Constant'
   */
  uint16_T pooled2;

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<Root>/Rate Transition1'
   *   '<Root>/Rate Transition2'
   *   '<Root>/Rate Transition4'
   *   '<Root>/Rate Transition8'
   *   '<S1>/Constant'
   *   '<S1>/Constant1'
   *   '<S2>/debugValues'
   *   '<S15>/Values'
   *   '<S18>/tractionValue'
   *   '<S18>/Unit Delay'
   */
  uint16_T pooled3;

  /* Computed Parameter: GCU_TRACTION_CONTROL_EFI_ID_Val
   * Referenced by: '<S21>/GCU_TRACTION_CONTROL_EFI_ID'
   */
  uint16_T GCU_TRACTION_CONTROL_EFI_ID_Val;

  /* Pooled Parameter (Expression: 793)
   * Referenced by:
   *   '<S22>/GCU_FEEDBACK_ID'
   *   '<S37>/GCU_FEEDBACK_ID'
   */
  uint16_T pooled4;

  /* Computed Parameter: TRACTION_CODE_Value
   * Referenced by: '<S18>/TRACTION_CODE'
   */
  uint16_T TRACTION_CODE_Value;
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint8_T UART_debug[10];              /* '<Root>/UART_debug' */
  real_T SelectMode;                   /* '<Root>/SelectMode' */
  uint8_T CAN[10];                     /* '<Root>/CAN' */
  uint32_T adc_buffer[10];             /* '<Root>/adc_buffer' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint16_T debugValues[10];            /* '<Root>/debugValues  ' */
  uint32_T adc_data_vector[10];        /* '<Root>/adc_data_vector' */
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

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S12>/Cast2' : Eliminate redundant data type conversion
 * Block '<S12>/Cast3' : Eliminate redundant data type conversion
 * Block '<S13>/Cast2' : Eliminate redundant data type conversion
 * Block '<S13>/Cast3' : Eliminate redundant data type conversion
 * Block '<S14>/Cast' : Eliminate redundant data type conversion
 * Block '<S14>/Cast1' : Eliminate redundant data type conversion
 * Block '<S14>/Cast2' : Eliminate redundant data type conversion
 * Block '<S14>/Cast3' : Eliminate redundant data type conversion
 * Block '<Root>/Cast1' : Eliminate redundant data type conversion
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
 * '<S2>'   : 'GCU_Model_genCode/Debug_UART '
 * '<S3>'   : 'GCU_Model_genCode/GCU_CAN_Read'
 * '<S4>'   : 'GCU_Model_genCode/GCU_timer'
 * '<S5>'   : 'GCU_Model_genCode/Initialize Function'
 * '<S6>'   : 'GCU_Model_genCode/Simulink_Debug'
 * '<S7>'   : 'GCU_Model_genCode/Triggered Subsystem'
 * '<S8>'   : 'GCU_Model_genCode/rpmPin_update'
 * '<S9>'   : 'GCU_Model_genCode/update_ADC_data'
 * '<S10>'  : 'GCU_Model_genCode/CAN_Send/send_ADC_data1'
 * '<S11>'  : 'GCU_Model_genCode/CAN_Send/send_ADC_data2'
 * '<S12>'  : 'GCU_Model_genCode/CAN_Send/send_ADC_data3'
 * '<S13>'  : 'GCU_Model_genCode/CAN_Send/send_Feedbacks_1'
 * '<S14>'  : 'GCU_Model_genCode/CAN_Send/send_Feedbacks_2'
 * '<S15>'  : 'GCU_Model_genCode/GCU_CAN_Read/AAC_ExternalValues'
 * '<S16>'  : 'GCU_Model_genCode/GCU_CAN_Read/EfiRPMLimiter'
 * '<S17>'  : 'GCU_Model_genCode/GCU_CAN_Read/MessageEvaluation'
 * '<S18>'  : 'GCU_Model_genCode/GCU_CAN_Read/TractionValue'
 * '<S19>'  : 'GCU_Model_genCode/GCU_CAN_Read/EfiRPMLimiter/Efi_setRpmLimiter'
 * '<S20>'  : 'GCU_Model_genCode/GCU_CAN_Read/EfiRPMLimiter/Efi_unsetRpmLimiter'
 * '<S21>'  : 'GCU_Model_genCode/GCU_CAN_Read/TractionValue/Efi_setTraction'
 * '<S22>'  : 'GCU_Model_genCode/GCU_CAN_Read/TractionValue/sendUpdatesSW'
 * '<S23>'  : 'GCU_Model_genCode/GCU_timer/ClutchMotor'
 * '<S24>'  : 'GCU_Model_genCode/GCU_timer/Efi'
 * '<S25>'  : 'GCU_Model_genCode/GCU_timer/EngineControl'
 * '<S26>'  : 'GCU_Model_genCode/GCU_timer/GCULogic'
 * '<S27>'  : 'GCU_Model_genCode/GCU_timer/GearMotor1'
 * '<S28>'  : 'GCU_Model_genCode/GCU_timer/ClutchMotor/ClutchMotor Init '
 * '<S29>'  : 'GCU_Model_genCode/GCU_timer/ClutchMotor/ClutchMotor SetPosition '
 * '<S30>'  : 'GCU_Model_genCode/GCU_timer/Efi/Init'
 * '<S31>'  : 'GCU_Model_genCode/GCU_timer/Efi/SetCut'
 * '<S32>'  : 'GCU_Model_genCode/GCU_timer/Efi/SetRPMLimiter'
 * '<S33>'  : 'GCU_Model_genCode/GCU_timer/Efi/UnsetCut'
 * '<S34>'  : 'GCU_Model_genCode/GCU_timer/Efi/UnsetRPMLimiter'
 * '<S35>'  : 'GCU_Model_genCode/GCU_timer/EngineControl/EngineControl_Start'
 * '<S36>'  : 'GCU_Model_genCode/GCU_timer/EngineControl/EngineControl_Stop'
 * '<S37>'  : 'GCU_Model_genCode/GCU_timer/GCULogic/sendUpdatesSW'
 * '<S38>'  : 'GCU_Model_genCode/GCU_timer/GearMotor1/Gearmotor_brake'
 * '<S39>'  : 'GCU_Model_genCode/GCU_timer/GearMotor1/Gearmotor_release'
 * '<S40>'  : 'GCU_Model_genCode/GCU_timer/GearMotor1/Gearmotor_turnLeft'
 * '<S41>'  : 'GCU_Model_genCode/GCU_timer/GearMotor1/Gearmotor_turnRight'
 * '<S42>'  : 'GCU_Model_genCode/Simulink_Debug/AccelerationRoutine'
 * '<S43>'  : 'GCU_Model_genCode/rpmPin_update/Triggered_Subsystem'
 * '<S44>'  : 'GCU_Model_genCode/rpmPin_update/Triggered_Subsystem1'
 */
#endif                                 /* RTW_HEADER_GCU_Model_genCode_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
