/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GCU_Timer_debug.h
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

#ifndef RTW_HEADER_GCU_Timer_debug_h_
#define RTW_HEADER_GCU_Timer_debug_h_
#include "rtwtypes.h"
#ifndef GCU_Timer_debug_COMMON_INCLUDES_
# define GCU_Timer_debug_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* GCU_Timer_debug_COMMON_INCLUDES_ */

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

/* Block signals and states (default storage) for system '<S3>/SetCut' */
typedef struct {
  uint8_T EfiSetBlip;                  /* '<S10>/Efi SetBlip' */
} DW_SetCut;

/* Block signals and states (default storage) for system '<S3>/UnsetCut' */
typedef struct {
  uint8_T EfiUnSetBlip;                /* '<S12>/Efi UnSetBlip' */
} DW_UnsetCut;

/* Block signals and states (default storage) for system '<S6>/Gearmotor_turnRight' */
typedef struct {
  uint8_T GearMotorTurnRight_o1;       /* '<S20>/GearMotor Turn Right' */
  uint8_T GearMotorTurnRight_o2;       /* '<S20>/GearMotor Turn Right' */
  uint8_T GearMotorTurnRight_o3;       /* '<S20>/GearMotor Turn Right' */
} DW_Gearmotor_turnRight;

/* Block signals and states (default storage) for system '<S6>/Gearmotor_brake' */
typedef struct {
  uint8_T GearMotorBrake_o1;           /* '<S17>/GearMotor Brake' */
  uint8_T GearMotorBrake_o2;           /* '<S17>/GearMotor Brake' */
  uint8_T GearMotorBrake_o3;           /* '<S17>/GearMotor Brake' */
} DW_Gearmotor_brake;

/* Block signals and states (default storage) for system '<S4>/EngineControl_Start' */
typedef struct {
  uint8_T EngineControlStart;          /* '<S14>/EngineControl Start' */
} DW_EngineControl_Start;

/* Block signals and states (default storage) for system '<S5>/sendUpdatesSW' */
typedef struct {
  uint8_T PackCanUart[10];             /* '<S16>/PackCanUart' */
} DW_sendUpdatesSW;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_sendUpdatesSW sendUpdatesSW_b;    /* '<S5>/sendUpdatesSW' */
  DW_EngineControl_Start EngineControl_Start_c;/* '<S4>/EngineControl_Start' */
  DW_Gearmotor_brake Gearmotor_brake_e;/* '<S6>/Gearmotor_brake' */
  DW_Gearmotor_turnRight Gearmotor_turnRight_o;/* '<S6>/Gearmotor_turnRight' */
  DW_UnsetCut UnsetRPMLimiter_k;       /* '<S3>/UnsetRPMLimiter' */
  DW_SetCut SetRPMLimiter_n;           /* '<S3>/SetRPMLimiter' */
  DW_UnsetCut UnsetCut_g;              /* '<S3>/UnsetCut' */
  DW_SetCut SetCut_b;                  /* '<S3>/SetCut' */
  real_T aac_clutchValue;              /* '<Root>/GCULogic' */
  real_T aac_clutchStep;               /* '<Root>/GCULogic' */
  int32_T aac_parameters[11];          /* '<Root>/GCULogic' */
  int32_T sfEvent;                     /* '<Root>/GCULogic' */
  int32_T aac_dtRelease;               /* '<Root>/GCULogic' */
  int32_T ticksCounter;                /* '<Root>/GCULogic' */
  uint32_T alive;                      /* '<Root>/GCULogic' */
  uint16_T TmpSignalConversionAtPack_Uart_[10];
  uint16_T accFb;                      /* '<Root>/GCULogic' */
  uint16_T valCode;                    /* '<Root>/GCULogic' */
  uint16_T value;                      /* '<Root>/GCULogic' */
  uint16_T lastAacCom;                 /* '<Root>/GCULogic' */
  uint16_T lastShiftCom;               /* '<Root>/GCULogic' */
  uint16_T lastModeCom;                /* '<Root>/GCULogic' */
  uint16_T aacCounter;                 /* '<Root>/GCULogic' */
  uint8_T Pack_Uart_Message1[20];      /* '<S2>/Pack_Uart_Message1' */
  uint8_T Pin_In1;                     /* '<S6>/Pin_In1' */
  uint8_T Pin_H;                       /* '<S6>/Pin_H' */
  uint8_T Merge1;                      /* '<S3>/Merge1' */
  uint8_T Merge2;                      /* '<S3>/Merge2' */
  uint8_T Pin_In2;                     /* '<S6>/Pin_In2' */
  uint8_T Merge;                       /* '<S4>/Merge' */
  uint8_T clutchCurrVal;               /* '<Root>/GCULogic' */
  uint8_T EngineControlStop;           /* '<S15>/EngineControl Stop' */
  uint8_T GearMotorTurnLeft_o1;        /* '<S19>/GearMotor Turn Left' */
  uint8_T GearMotorTurnLeft_o2;        /* '<S19>/GearMotor Turn Left' */
  uint8_T GearMotorTurnLeft_o3;        /* '<S19>/GearMotor Turn Left' */
  uint8_T GearMotorRelease;            /* '<S18>/GearMotor Release' */
  uint8_T Minus;                       /* '<S8>/Minus' */
  uint8_T is_active_c1_GCU_Timer_debug;/* '<Root>/GCULogic' */
  uint8_T is_MODES;                    /* '<Root>/GCULogic' */
  uint8_T is_active_MODES;             /* '<Root>/GCULogic' */
  uint8_T is_ACCELERATION;             /* '<Root>/GCULogic' */
  uint8_T is_AAC;                      /* '<Root>/GCULogic' */
  uint8_T is_ACTIVE;                   /* '<Root>/GCULogic' */
  uint8_T is_NEUTRAL_STATE;            /* '<Root>/GCULogic' */
  uint8_T is_active_NEUTRAL_STATE;     /* '<Root>/GCULogic' */
  uint8_T is_GEARSHIFT;                /* '<Root>/GCULogic' */
  uint8_T is_active_GEARSHIFT;         /* '<Root>/GCULogic' */
  uint8_T is_UPSHIFTING;               /* '<Root>/GCULogic' */
  uint8_T is_UP_REBOUND;               /* '<Root>/GCULogic' */
  uint8_T is_UP_PUSH;                  /* '<Root>/GCULogic' */
  uint8_T is_UP_START;                 /* '<Root>/GCULogic' */
  uint8_T is_DOWNSHIFTING;             /* '<Root>/GCULogic' */
  uint8_T is_DOWN_START;               /* '<Root>/GCULogic' */
  uint8_T is_DOWN_BRAKE;               /* '<Root>/GCULogic' */
  uint8_T is_START_ENGINE;             /* '<Root>/GCULogic' */
  uint8_T is_active_START_ENGINE;      /* '<Root>/GCULogic' */
  uint8_T lastShift;                   /* '<Root>/GCULogic' */
  uint8_T lastClutchCom;               /* '<Root>/GCULogic' */
  uint8_T lastCom;                     /* '<Root>/GCULogic' */
  uint8_T startCounter;                /* '<Root>/GCULogic' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: GCU_FEEDBACK_ID_Value
   * Referenced by: '<S16>/GCU_FEEDBACK_ID'
   */
  uint16_T GCU_FEEDBACK_ID_Value;
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint8_T currentGear;                 /* '<Root>/currentGear' */
  uint16_T aac_externValues[3];        /* '<Root>/aac_externValues' */
  uint16_T shiftCom[2];                /* '<Root>/shiftCom' */
  uint8_T startEngCom;                 /* '<Root>/startEngCom' */
  uint16_T aacCom[2];                  /* '<Root>/aacCom' */
  uint8_T clutchCom[2];                /* '<Root>/clutchCom' */
  uint16_T modeCom[2];                 /* '<Root>/modeCom' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint16_T debugValues[10];            /* '<Root>/debugValues  ' */
  uint32_T Alive;                      /* '<Root>/Alive' */
  uint8_T clutchCurrVal;               /* '<Root>/clutchCurrVal' */
  uint8_T upCut_Pin;                   /* '<Root>/upCut_Pin' */
  uint8_T rpmLimiter_Pin;              /* '<Root>/rpmLimiter_Pin' */
  uint8_T PinIn1;                      /* '<Root>/PinIn1' */
  uint8_T PinIn2;                      /* '<Root>/PinIn2' */
  uint8_T PinH;                        /* '<Root>/PinH' */
  uint8_T engineStarter_pin;           /* '<Root>/engineStarter_pin' */
  uint16_T accFb;                      /* '<Root>/accFb' */
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
extern const uint16_T GCU_Timer_debug_U16GND;/* uint16_T ground */

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void GCU_Timer_debug_initialize(void);
extern void GCU_Timer_debug_step0(void);
extern void GCU_Timer_debug_step1(void);
extern void GCU_Timer_debug_step2(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Scope1' : Unused code path elimination
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
 * '<Root>' : 'GCU_Timer_debug'
 * '<S1>'   : 'GCU_Timer_debug/ClutchMotor'
 * '<S2>'   : 'GCU_Timer_debug/Debug '
 * '<S3>'   : 'GCU_Timer_debug/Efi'
 * '<S4>'   : 'GCU_Timer_debug/EngineControl'
 * '<S5>'   : 'GCU_Timer_debug/GCULogic'
 * '<S6>'   : 'GCU_Timer_debug/GearMotor1'
 * '<S7>'   : 'GCU_Timer_debug/ClutchMotor/ClutchMotor Init '
 * '<S8>'   : 'GCU_Timer_debug/ClutchMotor/ClutchMotor SetPosition '
 * '<S9>'   : 'GCU_Timer_debug/Efi/Init'
 * '<S10>'  : 'GCU_Timer_debug/Efi/SetCut'
 * '<S11>'  : 'GCU_Timer_debug/Efi/SetRPMLimiter'
 * '<S12>'  : 'GCU_Timer_debug/Efi/UnsetCut'
 * '<S13>'  : 'GCU_Timer_debug/Efi/UnsetRPMLimiter'
 * '<S14>'  : 'GCU_Timer_debug/EngineControl/EngineControl_Start'
 * '<S15>'  : 'GCU_Timer_debug/EngineControl/EngineControl_Stop'
 * '<S16>'  : 'GCU_Timer_debug/GCULogic/sendUpdatesSW'
 * '<S17>'  : 'GCU_Timer_debug/GearMotor1/Gearmotor_brake'
 * '<S18>'  : 'GCU_Timer_debug/GearMotor1/Gearmotor_release'
 * '<S19>'  : 'GCU_Timer_debug/GearMotor1/Gearmotor_turnLeft'
 * '<S20>'  : 'GCU_Timer_debug/GearMotor1/Gearmotor_turnRight'
 */
#endif                                 /* RTW_HEADER_GCU_Timer_debug_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
