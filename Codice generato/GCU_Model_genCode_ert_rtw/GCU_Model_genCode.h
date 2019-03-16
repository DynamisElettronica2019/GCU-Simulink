/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GCU_Model_genCode.h
 *
 * Code generated for Simulink model 'GCU_Model_genCode'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Sun Feb 24 14:02:14 2019
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
#include <math.h>
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

/* Block signals and states (default storage) for system '<S4>/TractionValue' */
typedef struct {
  uint16_T Divide;                     /* '<S10>/Divide' */
  uint16_T UnitDelay_DSTATE;           /* '<S10>/Unit Delay' */
  uint8_T PackCanUart[10];             /* '<S13>/PackCanUart' */
  uint8_T PackCanUart_c[10];           /* '<S14>/PackCanUart' */
} DW_TractionValue;

/* Block signals and states (default storage) for system '<S8>/Efi_setRpmLimiter' */
typedef struct {
  uint8_T EfiSetRPMLimiter;            /* '<S11>/Efi SetRPMLimiter' */
} DW_Efi_setRpmLimiter;

/* Block signals and states (default storage) for system '<S8>/Efi_unsetRpmLimiter' */
typedef struct {
  uint8_T EfiUnSetRPMLimiter;          /* '<S12>/Efi UnSetRPMLimiter' */
} DW_Efi_unsetRpmLimiter;

/* Block signals and states (default storage) for system '<S4>/AAC_ExternalValues' */
typedef struct {
  uint16_T UnitDelay_DSTATE[3];        /* '<S7>/Unit Delay' */
} DW_AAC_ExternalValues;

/* Block signals and states (default storage) for system '<S16>/SetCut' */
typedef struct {
  uint8_T EfiSetBlip;                  /* '<S23>/Efi SetBlip' */
} DW_SetCut;

/* Block signals and states (default storage) for system '<S16>/UnsetCut' */
typedef struct {
  uint8_T EfiUnSetBlip;                /* '<S25>/Efi UnSetBlip' */
} DW_UnsetCut;

/* Block signals and states (default storage) for system '<S19>/Gearmotor_turnRight' */
typedef struct {
  uint8_T GearMotorTurnRight_o1;       /* '<S33>/GearMotor Turn Right' */
  uint8_T GearMotorTurnRight_o2;       /* '<S33>/GearMotor Turn Right' */
  uint8_T GearMotorTurnRight_o3;       /* '<S33>/GearMotor Turn Right' */
} DW_Gearmotor_turnRight;

/* Block signals and states (default storage) for system '<S19>/Gearmotor_brake' */
typedef struct {
  uint8_T GearMotorBrake_o1;           /* '<S30>/GearMotor Brake' */
  uint8_T GearMotorBrake_o2;           /* '<S30>/GearMotor Brake' */
  uint8_T GearMotorBrake_o3;           /* '<S30>/GearMotor Brake' */
} DW_Gearmotor_brake;

/* Block signals and states (default storage) for system '<S17>/EngineControl_Start' */
typedef struct {
  uint8_T EngineControlStart;          /* '<S27>/EngineControl Start' */
} DW_EngineControl_Start;

/* Block signals and states (default storage) for system '<S18>/sendUpdatesSW' */
typedef struct {
  uint8_T PackCanUart[10];             /* '<S29>/PackCanUart' */
} DW_sendUpdatesSW;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_sendUpdatesSW sendUpdatesSW_g;    /* '<S18>/sendUpdatesSW' */
  DW_EngineControl_Start EngineControl_Start_k;/* '<S17>/EngineControl_Start' */
  DW_Gearmotor_brake Gearmotor_brake_e;/* '<S19>/Gearmotor_brake' */
  DW_Gearmotor_turnRight Gearmotor_turnRight_a;/* '<S19>/Gearmotor_turnRight' */
  DW_UnsetCut UnsetRPMLimiter_o;       /* '<S16>/UnsetRPMLimiter' */
  DW_SetCut SetRPMLimiter_o;           /* '<S16>/SetRPMLimiter' */
  DW_UnsetCut UnsetCut_f;              /* '<S16>/UnsetCut' */
  DW_SetCut SetCut_h;                  /* '<S16>/SetCut' */
  DW_AAC_ExternalValues AAC_ExternalValues_j;/* '<S4>/AAC_ExternalValues' */
  DW_Efi_unsetRpmLimiter Efi_unsetRpmLimiter_o;/* '<S8>/Efi_unsetRpmLimiter' */
  DW_Efi_setRpmLimiter Efi_setRpmLimiter_e;/* '<S8>/Efi_setRpmLimiter' */
  DW_TractionValue TractionValue_f;    /* '<S4>/TractionValue' */
  real_T aac_clutchValue;              /* '<S5>/GCULogic' */
  real_T aac_clutchStep;               /* '<S5>/GCULogic' */
  real_T message;                      /* '<Root>/AccelerationRoutine' */
  int32_T aac_parameters[11];          /* '<S5>/GCULogic' */
  int32_T sfEvent;                     /* '<S5>/GCULogic' */
  int32_T aac_dtRelease;               /* '<S5>/GCULogic' */
  int32_T ticksCounter;                /* '<S5>/GCULogic' */
  uint32_T alive;                      /* '<S5>/GCULogic' */
  uint16_T RateTransition1[3];         /* '<Root>/Rate Transition1' */
  uint16_T RateTransition2[2];         /* '<Root>/Rate Transition2' */
  uint16_T RateTransition4[2];         /* '<Root>/Rate Transition4' */
  uint16_T shiftCommand[2];            /* '<S4>/MessageEvaluation' */
  uint16_T aacCommand[2];              /* '<S4>/MessageEvaluation' */
  uint16_T Assignment[3];              /* '<S7>/Assignment' */
  volatile uint16_T RateTransition1_Buffer[6];/* '<Root>/Rate Transition1' */
  volatile uint16_T RateTransition2_Buffer[4];/* '<Root>/Rate Transition2' */
  volatile uint16_T RateTransition4_Buffer[4];/* '<Root>/Rate Transition4' */
  uint16_T valCode;                    /* '<S5>/GCULogic' */
  uint16_T value;                      /* '<S5>/GCULogic' */
  uint16_T UnpackCanUart_o1;           /* '<S4>/UnpackCanUart' */
  uint16_T UnpackCanUart_o2;           /* '<S4>/UnpackCanUart' */
  uint16_T UnpackCanUart_o3;           /* '<S4>/UnpackCanUart' */
  uint16_T UnpackCanUart_o4;           /* '<S4>/UnpackCanUart' */
  uint16_T UnpackCanUart_o5;           /* '<S4>/UnpackCanUart' */
  uint16_T currGear;                   /* '<S4>/MessageEvaluation' */
  uint16_T id;                         /* '<Root>/AccelerationRoutine' */
  uint16_T firstInt;                   /* '<Root>/AccelerationRoutine' */
  uint16_T secondInt;                  /* '<Root>/AccelerationRoutine' */
  uint16_T lastAacCom;                 /* '<S5>/GCULogic' */
  uint16_T lastShiftCom;               /* '<S5>/GCULogic' */
  uint16_T aacCounter;                 /* '<S5>/GCULogic' */
  uint16_T rpm;                        /* '<Root>/AccelerationRoutine' */
  uint16_T wheelSpeed;                 /* '<Root>/AccelerationRoutine' */
  uint16_T currGear_m;                 /* '<Root>/AccelerationRoutine' */
  volatile int8_T RateTransition1_ActiveBufIdx;/* '<Root>/Rate Transition1' */
  volatile int8_T RateTransition2_ActiveBufIdx;/* '<Root>/Rate Transition2' */
  volatile int8_T RateTransition4_ActiveBufIdx;/* '<Root>/Rate Transition4' */
  volatile int8_T RateTransition5_ActiveBufIdx;/* '<Root>/Rate Transition5' */
  uint8_T RateTransition5[2];          /* '<Root>/Rate Transition5' */
  uint8_T PackCanUart[10];             /* '<Root>/PackCanUart' */
  uint8_T clutchCommand[2];            /* '<S4>/MessageEvaluation' */
  volatile uint8_T RateTransition5_Buffer[4];/* '<Root>/Rate Transition5' */
  uint8_T RateTransition3;             /* '<Root>/Rate Transition3' */
  uint8_T RateTransition7;             /* '<Root>/Rate Transition7' */
  uint8_T RateTransition6;             /* '<Root>/Rate Transition6' */
  uint8_T RateTransition_k;            /* '<S6>/Rate Transition' */
  uint8_T Merge2;                      /* '<S16>/Merge2' */
  uint8_T Pin_H;                       /* '<S19>/Pin_H' */
  uint8_T Pin_In1;                     /* '<S19>/Pin_In1' */
  uint8_T clutchCurrVal;               /* '<S5>/GCULogic' */
  uint8_T EngineControlStop;           /* '<S28>/EngineControl Stop' */
  uint8_T GearMotorTurnLeft_o1;        /* '<S32>/GearMotor Turn Left' */
  uint8_T GearMotorTurnLeft_o2;        /* '<S32>/GearMotor Turn Left' */
  uint8_T GearMotorTurnLeft_o3;        /* '<S32>/GearMotor Turn Left' */
  uint8_T GearMotorRelease;            /* '<S31>/GearMotor Release' */
  uint8_T Minus;                       /* '<S21>/Minus' */
  uint8_T Merge_o;                     /* '<S8>/Merge' */
  uint8_T startEngCommand;             /* '<S4>/MessageEvaluation' */
  volatile uint8_T RateTransition_Buffer0;/* '<Root>/Rate Transition' */
  volatile uint8_T RateTransition3_Buffer0;/* '<Root>/Rate Transition3' */
  uint8_T RateTransition_Buffer0_m;    /* '<S6>/Rate Transition' */
  uint8_T is_active_c2_GCU_Model_genCode;/* '<S5>/GCULogic' */
  uint8_T is_MODES;                    /* '<S5>/GCULogic' */
  uint8_T is_active_MODES;             /* '<S5>/GCULogic' */
  uint8_T is_AAC;                      /* '<S5>/GCULogic' */
  uint8_T is_ACTIVE;                   /* '<S5>/GCULogic' */
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
  uint8_T is_START_ENGINE;             /* '<S5>/GCULogic' */
  uint8_T is_active_START_ENGINE;      /* '<S5>/GCULogic' */
  uint8_T lastShift;                   /* '<S5>/GCULogic' */
  uint8_T lastClutchCom;               /* '<S5>/GCULogic' */
  uint8_T lastCom;                     /* '<S5>/GCULogic' */
  uint8_T startCounter;                /* '<S5>/GCULogic' */
  uint8_T is_active_c1_GCU_Model_genCode;/* '<S4>/MessageEvaluation' */
  uint8_T is_c1_GCU_Model_genCode;     /* '<S4>/MessageEvaluation' */
  uint8_T is_c3_GCU_Model_genCode;     /* '<Root>/AccelerationRoutine' */
  uint8_T lastGearPin;                 /* '<Root>/AccelerationRoutine' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Triggered_Subsystem1_Trig_ZCE;/* '<S6>/Triggered_Subsystem1' */
  ZCSigState Triggered_Subsystem_Trig_ZCE;/* '<S6>/Triggered_Subsystem' */
} PrevZCX;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: GCU_TRACTION_CONTROL_EFI_ID_Val
   * Referenced by: '<S13>/GCU_TRACTION_CONTROL_EFI_ID'
   */
  uint16_T GCU_TRACTION_CONTROL_EFI_ID_Val;

  /* Pooled Parameter (Expression: 793)
   * Referenced by:
   *   '<S14>/GCU_FEEDBACK_ID'
   *   '<S29>/GCU_FEEDBACK_ID'
   */
  uint16_T pooled1;

  /* Computed Parameter: TRACTION_CODE_Value
   * Referenced by: '<S10>/TRACTION_CODE'
   */
  uint16_T TRACTION_CODE_Value;
} ConstP;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint8_T currGear;                    /* '<Root>/currGear' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID0_1;
    } RateInteraction;
  } Timing;
};

/* Block signals and states (default storage) */
extern DW rtDW;

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

/* Real-time Model object */
extern RT_MODEL *const rtM;

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
 * '<S1>'   : 'GCU_Model_genCode/AccelerationRoutine'
 * '<S2>'   : 'GCU_Model_genCode/Initialize Function'
 * '<S3>'   : 'GCU_Model_genCode/Initialize Function1'
 * '<S4>'   : 'GCU_Model_genCode/Subsystem'
 * '<S5>'   : 'GCU_Model_genCode/Subsystem1'
 * '<S6>'   : 'GCU_Model_genCode/rpmPin_update'
 * '<S7>'   : 'GCU_Model_genCode/Subsystem/AAC_ExternalValues'
 * '<S8>'   : 'GCU_Model_genCode/Subsystem/EfiRPMLimiter'
 * '<S9>'   : 'GCU_Model_genCode/Subsystem/MessageEvaluation'
 * '<S10>'  : 'GCU_Model_genCode/Subsystem/TractionValue'
 * '<S11>'  : 'GCU_Model_genCode/Subsystem/EfiRPMLimiter/Efi_setRpmLimiter'
 * '<S12>'  : 'GCU_Model_genCode/Subsystem/EfiRPMLimiter/Efi_unsetRpmLimiter'
 * '<S13>'  : 'GCU_Model_genCode/Subsystem/TractionValue/Efi_setTraction'
 * '<S14>'  : 'GCU_Model_genCode/Subsystem/TractionValue/sendUpdatesSW'
 * '<S15>'  : 'GCU_Model_genCode/Subsystem1/ClutchMotor'
 * '<S16>'  : 'GCU_Model_genCode/Subsystem1/Efi'
 * '<S17>'  : 'GCU_Model_genCode/Subsystem1/EngineControl'
 * '<S18>'  : 'GCU_Model_genCode/Subsystem1/GCULogic'
 * '<S19>'  : 'GCU_Model_genCode/Subsystem1/GearMotor1'
 * '<S20>'  : 'GCU_Model_genCode/Subsystem1/ClutchMotor/ClutchMotor Init '
 * '<S21>'  : 'GCU_Model_genCode/Subsystem1/ClutchMotor/ClutchMotor SetPosition '
 * '<S22>'  : 'GCU_Model_genCode/Subsystem1/Efi/Init'
 * '<S23>'  : 'GCU_Model_genCode/Subsystem1/Efi/SetCut'
 * '<S24>'  : 'GCU_Model_genCode/Subsystem1/Efi/SetRPMLimiter'
 * '<S25>'  : 'GCU_Model_genCode/Subsystem1/Efi/UnsetCut'
 * '<S26>'  : 'GCU_Model_genCode/Subsystem1/Efi/UnsetRPMLimiter'
 * '<S27>'  : 'GCU_Model_genCode/Subsystem1/EngineControl/EngineControl_Start'
 * '<S28>'  : 'GCU_Model_genCode/Subsystem1/EngineControl/EngineControl_Stop'
 * '<S29>'  : 'GCU_Model_genCode/Subsystem1/GCULogic/sendUpdatesSW'
 * '<S30>'  : 'GCU_Model_genCode/Subsystem1/GearMotor1/Gearmotor_brake'
 * '<S31>'  : 'GCU_Model_genCode/Subsystem1/GearMotor1/Gearmotor_release'
 * '<S32>'  : 'GCU_Model_genCode/Subsystem1/GearMotor1/Gearmotor_turnLeft'
 * '<S33>'  : 'GCU_Model_genCode/Subsystem1/GearMotor1/Gearmotor_turnRight'
 * '<S34>'  : 'GCU_Model_genCode/rpmPin_update/Triggered_Subsystem'
 * '<S35>'  : 'GCU_Model_genCode/rpmPin_update/Triggered_Subsystem1'
 */
#endif                                 /* RTW_HEADER_GCU_Model_genCode_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
