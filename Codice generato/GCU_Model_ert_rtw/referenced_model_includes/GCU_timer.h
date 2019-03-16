/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GCU_timer.h
 *
 * Code generated for Simulink model 'GCU_timer'.
 *
 * Model version                  : 1.144
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Mon Feb 18 22:26:27 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_GCU_timer_h_
#define RTW_HEADER_GCU_timer_h_
#include "rtwtypes.h"
#ifndef GCU_timer_COMMON_INCLUDES_
# define GCU_timer_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* GCU_timer_COMMON_INCLUDES_ */

/* Forward declaration for rtModel */
typedef struct tag_RTM_GCU_timer_T RT_MODEL_GCU_timer_T;

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

/* Block signals and states (default storage) for system '<S2>/SetCut' */
#ifndef GCU_timer_MDLREF_HIDE_CHILD_

typedef struct {
  uint8_T EfiSetBlip;                  /* '<S12>/Efi SetBlip' */
} DW_SetCut_GCU_timer_T;

#endif                                 /*GCU_timer_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S2>/UnsetCut' */
#ifndef GCU_timer_MDLREF_HIDE_CHILD_

typedef struct {
  uint8_T EfiUnSetBlip;                /* '<S14>/Efi UnSetBlip' */
} DW_UnsetCut_GCU_timer_T;

#endif                                 /*GCU_timer_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S5>/Gearmotor_turnRight' */
#ifndef GCU_timer_MDLREF_HIDE_CHILD_

typedef struct {
  uint8_T GearMotorTurnRight_o1;       /* '<S21>/GearMotor Turn Right' */
  uint8_T GearMotorTurnRight_o2;       /* '<S21>/GearMotor Turn Right' */
  uint8_T GearMotorTurnRight_o3;       /* '<S21>/GearMotor Turn Right' */
} DW_Gearmotor_turnRight_GCU_ti_T;

#endif                                 /*GCU_timer_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S5>/Gearmotor_brake' */
#ifndef GCU_timer_MDLREF_HIDE_CHILD_

typedef struct {
  uint8_T GearMotorBrake_o1;           /* '<S18>/GearMotor Brake' */
  uint8_T GearMotorBrake_o2;           /* '<S18>/GearMotor Brake' */
  uint8_T GearMotorBrake_o3;           /* '<S18>/GearMotor Brake' */
} DW_Gearmotor_brake_GCU_timer_T;

#endif                                 /*GCU_timer_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S3>/EngineControl_Start' */
#ifndef GCU_timer_MDLREF_HIDE_CHILD_

typedef struct {
  uint8_T EngineControlStart;          /* '<S16>/EngineControl Start' */
} DW_EngineControl_Start_GCU_ti_T;

#endif                                 /*GCU_timer_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for model 'GCU_timer' */
#ifndef GCU_timer_MDLREF_HIDE_CHILD_

typedef struct {
  DW_EngineControl_Start_GCU_ti_T EngineControl_Start;/* '<S3>/EngineControl_Start' */
  DW_Gearmotor_brake_GCU_timer_T Gearmotor_brake;/* '<S5>/Gearmotor_brake' */
  DW_Gearmotor_turnRight_GCU_ti_T Gearmotor_turnRight;/* '<S5>/Gearmotor_turnRight' */
  DW_UnsetCut_GCU_timer_T UnsetRPMLimiter_p;/* '<S2>/UnsetRPMLimiter' */
  DW_SetCut_GCU_timer_T SetRPMLimiter_o;/* '<S2>/SetRPMLimiter' */
  DW_UnsetCut_GCU_timer_T UnsetCut;    /* '<S2>/UnsetCut' */
  DW_SetCut_GCU_timer_T SetCut;        /* '<S2>/SetCut' */
  real_T aac_clutchValue;              /* '<Root>/GCULogic' */
  real_T aac_clutchStep;               /* '<Root>/GCULogic' */
  int32_T aac_parameters[11];          /* '<Root>/GCULogic' */
  int32_T sfEvent;                     /* '<Root>/GCULogic' */
  int32_T aac_dtRelease;               /* '<Root>/GCULogic' */
  int32_T ticksCounter;                /* '<Root>/GCULogic' */
  uint16_T lastAacCom;                 /* '<Root>/GCULogic' */
  uint16_T lastShiftCom;               /* '<Root>/GCULogic' */
  uint16_T aacCounter;                 /* '<Root>/GCULogic' */
  uint8_T EngineControlStop;           /* '<S17>/EngineControl Stop' */
  uint8_T GearMotorTurnLeft_o1;        /* '<S20>/GearMotor Turn Left' */
  uint8_T GearMotorTurnLeft_o2;        /* '<S20>/GearMotor Turn Left' */
  uint8_T GearMotorTurnLeft_o3;        /* '<S20>/GearMotor Turn Left' */
  uint8_T GearMotorRelease;            /* '<S19>/GearMotor Release' */
  uint8_T Minus;                       /* '<S10>/Minus' */
  uint8_T is_active_c3_GCU_timer;      /* '<Root>/GCULogic' */
  uint8_T is_MODES;                    /* '<Root>/GCULogic' */
  uint8_T is_active_MODES;             /* '<Root>/GCULogic' */
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
} DW_GCU_timer_f_T;

#endif                                 /*GCU_timer_MDLREF_HIDE_CHILD_*/

#ifndef GCU_timer_MDLREF_HIDE_CHILD_

/* Real-time Model Data Structure */
struct tag_RTM_GCU_timer_T {
  const char_T **errorStatus;
  RTWSolverInfo *solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize0;
    SimTimeStep *simTimeStep;
  } Timing;
};

#endif                                 /*GCU_timer_MDLREF_HIDE_CHILD_*/

#ifndef GCU_timer_MDLREF_HIDE_CHILD_

typedef struct {
  RT_MODEL_GCU_timer_T rtm;
} MdlrefDW_GCU_timer_T;

#endif                                 /*GCU_timer_MDLREF_HIDE_CHILD_*/

extern void GCU_timer_Init(void);
extern void GCU_timer(const uint8_T *rtu_currentGear, const uint16_T
                      rtu_aac_externValues[3], const uint16_T rtu_shiftCom[2],
                      const uint8_T *rtu_startEngCom, const uint16_T rtu_aacCom
                      [2], const uint8_T rtu_clutchCom[2], uint32_T *rty_Alive,
                      uint8_T *rty_clutchCurrVal, uint8_T *rty_upCut_Pin,
                      uint8_T *rty_rpmLimiter_Pin, uint8_T *rty_PinIn1, uint8_T *
                      rty_PinIn2, uint8_T *rty_PinH, uint8_T
                      *rty_engineStarter_pin);

/* Model reference registration function */
extern void GCU_timer_initialize(const char_T **rt_errorStatus, RTWSolverInfo
  *rt_solverInfo);

#ifndef GCU_timer_MDLREF_HIDE_CHILD_

extern void GCU_timer_SetCut(uint8_T *rty_downCut_pin, DW_SetCut_GCU_timer_T
  *localDW);
extern void GCU_timer_UnsetCut(uint8_T *rty_downCut_pin, DW_UnsetCut_GCU_timer_T
  *localDW);
extern void GCU_timer_Gearmotor_turnRight(uint8_T *rty_Pin_In1, uint8_T
  *rty_Pin_In2, uint8_T *rty_Pin_H, DW_Gearmotor_turnRight_GCU_ti_T *localDW);
extern void GCU_timer_Gearmotor_brake(uint8_T *rty_Pin_In1, uint8_T *rty_Pin_In2,
  uint8_T *rty_Pin_H, DW_Gearmotor_brake_GCU_timer_T *localDW);
extern void GCU_timer_EngineControl_Start(uint8_T *rty_engine_starter,
  DW_EngineControl_Start_GCU_ti_T *localDW);
extern void GCU_timer_Gearmotor_release(void);

#endif                                 /*GCU_timer_MDLREF_HIDE_CHILD_*/

#ifndef GCU_timer_MDLREF_HIDE_CHILD_

extern MdlrefDW_GCU_timer_T GCU_timer_MdlrefDW;

#endif                                 /*GCU_timer_MDLREF_HIDE_CHILD_*/

#ifndef GCU_timer_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern DW_GCU_timer_f_T GCU_timer_DW;

#endif                                 /*GCU_timer_MDLREF_HIDE_CHILD_*/

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S7>/FromWs' : Unused code path elimination
 * Block '<S8>/FromWs' : Unused code path elimination
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
 * '<Root>' : 'GCU_timer'
 * '<S1>'   : 'GCU_timer/ClutchMotor'
 * '<S2>'   : 'GCU_timer/Efi'
 * '<S3>'   : 'GCU_timer/EngineControl'
 * '<S4>'   : 'GCU_timer/GCULogic'
 * '<S5>'   : 'GCU_timer/GearMotor1'
 * '<S6>'   : 'GCU_timer/InitializeFunction'
 * '<S7>'   : 'GCU_timer/downshift & setting neutral down'
 * '<S8>'   : 'GCU_timer/upshift & setting neutral up'
 * '<S9>'   : 'GCU_timer/ClutchMotor/ClutchMotor Init '
 * '<S10>'  : 'GCU_timer/ClutchMotor/ClutchMotor SetPosition '
 * '<S11>'  : 'GCU_timer/Efi/Init'
 * '<S12>'  : 'GCU_timer/Efi/SetCut'
 * '<S13>'  : 'GCU_timer/Efi/SetRPMLimiter'
 * '<S14>'  : 'GCU_timer/Efi/UnsetCut'
 * '<S15>'  : 'GCU_timer/Efi/UnsetRPMLimiter'
 * '<S16>'  : 'GCU_timer/EngineControl/EngineControl_Start'
 * '<S17>'  : 'GCU_timer/EngineControl/EngineControl_Stop'
 * '<S18>'  : 'GCU_timer/GearMotor1/Gearmotor_brake'
 * '<S19>'  : 'GCU_timer/GearMotor1/Gearmotor_release'
 * '<S20>'  : 'GCU_timer/GearMotor1/Gearmotor_turnLeft'
 * '<S21>'  : 'GCU_timer/GearMotor1/Gearmotor_turnRight'
 */
#endif                                 /* RTW_HEADER_GCU_timer_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
