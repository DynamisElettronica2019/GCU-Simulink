/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GCU_Model.h
 *
 * Code generated for Simulink model 'GCU_Model'.
 *
 * Model version                  : 1.31
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Mon Feb 18 22:26:47 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_GCU_Model_h_
#define RTW_HEADER_GCU_Model_h_
#ifndef GCU_Model_COMMON_INCLUDES_
# define GCU_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* GCU_Model_COMMON_INCLUDES_ */

/* Child system includes */
#define GCU_timer_MDLREF_HIDE_CHILD_
#include "GCU_timer.h"
#define GCU_CAN_MDLREF_HIDE_CHILD_
#include "GCU_CAN.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) ((const char_T **)(&((rtm)->errorStatus)))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_GCU_Model_T RT_MODEL_GCU_Model_T;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T message;                      /* '<Root>/AccelerationRoutine' */
  uint32_T alive;                      /* '<Root>/GCU timer' */
  uint32_T GCUCAN_o7;                  /* '<Root>/GCU CAN' */
  uint16_T RateTransition1[3];         /* '<Root>/Rate Transition1' */
  uint16_T RateTransition2[2];         /* '<Root>/Rate Transition2' */
  uint16_T RateTransition4[2];         /* '<Root>/Rate Transition4' */
  uint16_T GCUCAN_o2[3];               /* '<Root>/GCU CAN' */
  uint16_T shiftCommand[2];            /* '<Root>/GCU CAN' */
  uint16_T aacCommand[2];              /* '<Root>/GCU CAN' */
  volatile uint16_T RateTransition1_Buffer[6];/* '<Root>/Rate Transition1' */
  volatile uint16_T RateTransition2_Buffer[4];/* '<Root>/Rate Transition2' */
  volatile uint16_T RateTransition4_Buffer[4];/* '<Root>/Rate Transition4' */
  uint16_T currGear;                   /* '<Root>/GCU CAN' */
  uint16_T id;                         /* '<Root>/AccelerationRoutine' */
  uint16_T firstInt;                   /* '<Root>/AccelerationRoutine' */
  uint16_T secondInt;                  /* '<Root>/AccelerationRoutine' */
  uint16_T rpm;                        /* '<Root>/AccelerationRoutine' */
  uint16_T wheelSpeed;                 /* '<Root>/AccelerationRoutine' */
  uint16_T currGear_m;                 /* '<Root>/AccelerationRoutine' */
  volatile int8_T RateTransition1_ActiveBufIdx;/* '<Root>/Rate Transition1' */
  volatile int8_T RateTransition2_ActiveBufIdx;/* '<Root>/Rate Transition2' */
  volatile int8_T RateTransition4_ActiveBufIdx;/* '<Root>/Rate Transition4' */
  volatile int8_T RateTransition5_ActiveBufIdx;/* '<Root>/Rate Transition5' */
  uint8_T RateTransition5[2];          /* '<Root>/Rate Transition5' */
  uint8_T PackCanUart[10];             /* '<Root>/PackCanUart' */
  uint8_T clutchCommand[2];            /* '<Root>/GCU CAN' */
  volatile uint8_T RateTransition5_Buffer[4];/* '<Root>/Rate Transition5' */
  uint8_T RateTransition3;             /* '<Root>/Rate Transition3' */
  uint8_T clutchCurrVal;               /* '<Root>/GCU timer' */
  uint8_T GCUtimer_o3;                 /* '<Root>/GCU timer' */
  uint8_T GCUtimer_o4;                 /* '<Root>/GCU timer' */
  uint8_T GCUtimer_o5;                 /* '<Root>/GCU timer' */
  uint8_T GCUtimer_o6;                 /* '<Root>/GCU timer' */
  uint8_T GCUtimer_o7;                 /* '<Root>/GCU timer' */
  uint8_T GCUtimer_o8;                 /* '<Root>/GCU timer' */
  uint8_T RateTransition7;             /* '<Root>/Rate Transition7' */
  uint8_T RateTransition6;             /* '<Root>/Rate Transition6' */
  uint8_T startEngCommand;             /* '<Root>/GCU CAN' */
  volatile uint8_T RateTransition_Buffer0;/* '<Root>/Rate Transition' */
  volatile uint8_T RateTransition3_Buffer0;/* '<Root>/Rate Transition3' */
  uint8_T is_c3_GCU_Model;             /* '<Root>/AccelerationRoutine' */
  uint8_T lastGearPin;                 /* '<Root>/AccelerationRoutine' */
} DW_GCU_Model_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint8_T currGear;                    /* '<Root>/currGear' */
} ExtY_GCU_Model_T;

/* Real-time Model Data Structure */
struct tag_RTM_GCU_Model_T {
  const char_T * volatile errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block signals and states (default storage) */
extern DW_GCU_Model_T GCU_Model_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_GCU_Model_T GCU_Model_Y;

/* External data declarations for dependent source files */
extern const uint16_T GCU_Model_U16GND;/* uint16_T ground */

/* Model entry point functions */
extern void GCU_Model_initialize(void);
extern void GCU_Model_step0(void);
extern void GCU_Model_step2(void);

/* Real-time Model object */
extern RT_MODEL_GCU_Model_T *const GCU_Model_M;

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
 * '<Root>' : 'GCU_Model'
 * '<S1>'   : 'GCU_Model/AccelerationRoutine'
 * '<S2>'   : 'GCU_Model/Signal Builder'
 */
#endif                                 /* RTW_HEADER_GCU_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
