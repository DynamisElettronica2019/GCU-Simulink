/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GCU_Model.c
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

#include "GCU_Model.h"

/* Named constants for Chart: '<Root>/AccelerationRoutine' */
#define GCU_Model_IN_ActivateAac       ((uint8_T)1U)
#define GCU_Model_IN_DajeDeGas         ((uint8_T)2U)
#define GCU_Model_IN_EXIT              ((uint8_T)3U)
#define GCU_Model_IN_InsertGear        ((uint8_T)4U)
#define GCU_Model_IN_Ready             ((uint8_T)5U)
#define GCU_Model_IN_Wait              ((uint8_T)6U)
#define GCU_Model_IN_delay             ((uint8_T)7U)

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

const uint16_T GCU_Model_U16GND = 0U;  /* uint16_T ground */

/* Block signals and states (default storage) */
DW_GCU_Model_T GCU_Model_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_GCU_Model_T GCU_Model_Y;

/* Real-time model */
RT_MODEL_GCU_Model_T GCU_Model_M_;
RT_MODEL_GCU_Model_T *const GCU_Model_M = &GCU_Model_M_;

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

/* Forward declaration for local functions */
static void GCU_Model_updateData(void);
static void GCU_Model_checkGear(void);

/* Function for Chart: '<Root>/AccelerationRoutine' */
static void GCU_Model_updateData(void)
{
  uint32_T tmp;
  boolean_T guard1 = false;
  if ((GCU_Model_DW.RateTransition7 == 0) && (GCU_Model_DW.lastGearPin == 1)) {
    tmp = GCU_Model_DW.currGear_m + 1U;
    if (tmp > 65535U) {
      tmp = 65535U;
    }

    GCU_Model_DW.currGear_m = (uint16_T)tmp;
  } else {
    guard1 = false;
    if (GCU_Model_DW.RateTransition7 == 1) {
      GCU_Model_DW.rpm = 0U;
      GCU_Model_DW.wheelSpeed = 0U;
      guard1 = true;
    } else {
      tmp = GCU_Model_DW.rpm + 150U;
      if (tmp > 65535U) {
        tmp = 65535U;
      }

      GCU_Model_DW.rpm = (uint16_T)tmp;
      tmp = GCU_Model_DW.wheelSpeed + 5U;
      if (tmp > 65535U) {
        tmp = 65535U;
      }

      GCU_Model_DW.wheelSpeed = (uint16_T)tmp;
      if (GCU_Model_DW.message == 0.0) {
        guard1 = true;
      } else {
        GCU_Model_DW.message = 0.0;
        GCU_Model_DW.id = 774U;
        GCU_Model_DW.firstInt = GCU_Model_DW.wheelSpeed;
      }
    }

    if (guard1) {
      GCU_Model_DW.message = 1.0;
      GCU_Model_DW.id = 773U;
      GCU_Model_DW.firstInt = GCU_Model_DW.currGear_m;
      GCU_Model_DW.secondInt = GCU_Model_DW.rpm;
    }
  }

  GCU_Model_DW.lastGearPin = GCU_Model_DW.RateTransition7;
}

/* Function for Chart: '<Root>/AccelerationRoutine' */
static void GCU_Model_checkGear(void)
{
  uint32_T tmp;
  if ((GCU_Model_DW.RateTransition7 == 0) && (GCU_Model_DW.lastGearPin == 1)) {
    tmp = GCU_Model_DW.currGear_m + 1U;
    if (tmp > 65535U) {
      tmp = 65535U;
    }

    GCU_Model_DW.currGear_m = (uint16_T)tmp;
  }

  GCU_Model_DW.lastGearPin = GCU_Model_DW.RateTransition7;
}

/* Model step function for TID0 */
void GCU_Model_step0(void)             /* Sample time: [0.0s, 0.0s] */
{
  int32_T tmp;

  /* Outport: '<Root>/currGear' incorporates:
   *  RateTransition: '<Root>/Rate Transition'
   */
  GCU_Model_Y.currGear = GCU_Model_DW.RateTransition_Buffer0;

  /* RateTransition: '<Root>/Rate Transition1' */
  tmp = GCU_Model_DW.RateTransition1_ActiveBufIdx * 3;
  GCU_Model_DW.RateTransition1[0] = GCU_Model_DW.RateTransition1_Buffer[tmp];
  GCU_Model_DW.RateTransition1[1] = GCU_Model_DW.RateTransition1_Buffer[1 + tmp];
  GCU_Model_DW.RateTransition1[2] = GCU_Model_DW.RateTransition1_Buffer[2 + tmp];

  /* RateTransition: '<Root>/Rate Transition2' */
  tmp = GCU_Model_DW.RateTransition2_ActiveBufIdx << 1;
  GCU_Model_DW.RateTransition2[0] = GCU_Model_DW.RateTransition2_Buffer[tmp];
  GCU_Model_DW.RateTransition2[1] = GCU_Model_DW.RateTransition2_Buffer[1 + tmp];

  /* RateTransition: '<Root>/Rate Transition3' */
  GCU_Model_DW.RateTransition3 = GCU_Model_DW.RateTransition3_Buffer0;

  /* RateTransition: '<Root>/Rate Transition4' */
  tmp = GCU_Model_DW.RateTransition4_ActiveBufIdx << 1;
  GCU_Model_DW.RateTransition4[0] = GCU_Model_DW.RateTransition4_Buffer[tmp];
  GCU_Model_DW.RateTransition4[1] = GCU_Model_DW.RateTransition4_Buffer[1 + tmp];

  /* RateTransition: '<Root>/Rate Transition5' */
  tmp = GCU_Model_DW.RateTransition5_ActiveBufIdx << 1;
  GCU_Model_DW.RateTransition5[0] = GCU_Model_DW.RateTransition5_Buffer[tmp];
  GCU_Model_DW.RateTransition5[1] = GCU_Model_DW.RateTransition5_Buffer[1 + tmp];

  /* ModelReference: '<Root>/GCU timer' incorporates:
   *  Outport: '<Root>/currGear'
   */
  GCU_timer(&GCU_Model_Y.currGear, &GCU_Model_DW.RateTransition1[0],
            &GCU_Model_DW.RateTransition2[0], &GCU_Model_DW.RateTransition3,
            &GCU_Model_DW.RateTransition4[0], &GCU_Model_DW.RateTransition5[0],
            &GCU_Model_DW.alive, &GCU_Model_DW.clutchCurrVal,
            &GCU_Model_DW.GCUtimer_o3, &GCU_Model_DW.GCUtimer_o4,
            &GCU_Model_DW.GCUtimer_o5, &GCU_Model_DW.GCUtimer_o6,
            &GCU_Model_DW.GCUtimer_o7, &GCU_Model_DW.GCUtimer_o8);

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  GCU_Model_M->Timing.t[0] =
    (++GCU_Model_M->Timing.clockTick0) * GCU_Model_M->Timing.stepSize0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  GCU_Model_M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void GCU_Model_step2(void)             /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  uint8_T rtb_Cast;

  /* RateTransition: '<Root>/Rate Transition7' */
  GCU_Model_DW.RateTransition7 = GCU_Model_DW.GCUtimer_o6;

  /* Chart: '<Root>/AccelerationRoutine' */
  switch (GCU_Model_DW.is_c3_GCU_Model) {
   case GCU_Model_IN_ActivateAac:
    GCU_Model_DW.is_c3_GCU_Model = GCU_Model_IN_InsertGear;
    GCU_Model_DW.id = 512U;
    GCU_Model_DW.firstInt = 400U;
    break;

   case GCU_Model_IN_DajeDeGas:
    if (GCU_Model_DW.currGear_m == 2) {
      GCU_Model_DW.is_c3_GCU_Model = GCU_Model_IN_EXIT;
      GCU_Model_DW.id = 513U;
      GCU_Model_DW.firstInt = 25600U;
    } else {
      GCU_Model_updateData();
    }
    break;

   case GCU_Model_IN_EXIT:
    break;

   case GCU_Model_IN_InsertGear:
    if (GCU_Model_DW.currGear_m == 1) {
      GCU_Model_DW.is_c3_GCU_Model = GCU_Model_IN_Ready;
      GCU_Model_DW.id = 514U;
      GCU_Model_DW.firstInt = 2U;
    } else {
      GCU_Model_checkGear();
    }
    break;

   case GCU_Model_IN_Ready:
    GCU_Model_DW.is_c3_GCU_Model = GCU_Model_IN_DajeDeGas;
    GCU_Model_DW.id = 0U;
    GCU_Model_DW.rpm = 0U;
    GCU_Model_DW.wheelSpeed = 0U;
    break;

   case GCU_Model_IN_Wait:
    GCU_Model_DW.is_c3_GCU_Model = GCU_Model_IN_delay;
    break;

   default:
    GCU_Model_DW.is_c3_GCU_Model = GCU_Model_IN_ActivateAac;
    GCU_Model_DW.id = 514U;
    GCU_Model_DW.firstInt = 1U;
    break;
  }

  /* End of Chart: '<Root>/AccelerationRoutine' */

  /* S-Function (PackCanUART): '<Root>/PackCanUart' */
  PackCanUART_Outputs_wrapper(&GCU_Model_DW.id, &GCU_Model_DW.firstInt,
    &GCU_Model_DW.secondInt, (uint16_T*)&GCU_Model_U16GND, (uint16_T*)
    &GCU_Model_U16GND, &GCU_Model_DW.PackCanUart[0]);

  /* RateTransition: '<Root>/Rate Transition6' */
  GCU_Model_DW.RateTransition6 = GCU_Model_DW.clutchCurrVal;

  /* ModelReference: '<Root>/GCU CAN' */
  GCU_CAN(&GCU_Model_DW.RateTransition6, &GCU_Model_DW.PackCanUart[0],
          &GCU_Model_DW.currGear, &GCU_Model_DW.GCUCAN_o2[0],
          &GCU_Model_DW.shiftCommand[0], &GCU_Model_DW.startEngCommand,
          &GCU_Model_DW.aacCommand[0], &GCU_Model_DW.clutchCommand[0],
          &GCU_Model_DW.GCUCAN_o7);

  /* DataTypeConversion: '<Root>/Cast' */
  rtb_Cast = (uint8_T)GCU_Model_DW.currGear;

  /* Update for RateTransition: '<Root>/Rate Transition' */
  GCU_Model_DW.RateTransition_Buffer0 = rtb_Cast;

  /* Update for RateTransition: '<Root>/Rate Transition1' */
  GCU_Model_DW.RateTransition1_Buffer[(GCU_Model_DW.RateTransition1_ActiveBufIdx
    == 0) * 3] = GCU_Model_DW.GCUCAN_o2[0];
  GCU_Model_DW.RateTransition1_Buffer[1 +
    (GCU_Model_DW.RateTransition1_ActiveBufIdx == 0) * 3] =
    GCU_Model_DW.GCUCAN_o2[1];
  GCU_Model_DW.RateTransition1_Buffer[2 +
    (GCU_Model_DW.RateTransition1_ActiveBufIdx == 0) * 3] =
    GCU_Model_DW.GCUCAN_o2[2];
  GCU_Model_DW.RateTransition1_ActiveBufIdx = (int8_T)
    (GCU_Model_DW.RateTransition1_ActiveBufIdx == 0);

  /* Update for RateTransition: '<Root>/Rate Transition2' */
  GCU_Model_DW.RateTransition2_Buffer[(GCU_Model_DW.RateTransition2_ActiveBufIdx
    == 0) << 1] = GCU_Model_DW.shiftCommand[0];
  GCU_Model_DW.RateTransition2_Buffer[1 +
    ((GCU_Model_DW.RateTransition2_ActiveBufIdx == 0) << 1)] =
    GCU_Model_DW.shiftCommand[1];
  GCU_Model_DW.RateTransition2_ActiveBufIdx = (int8_T)
    (GCU_Model_DW.RateTransition2_ActiveBufIdx == 0);

  /* Update for RateTransition: '<Root>/Rate Transition3' */
  GCU_Model_DW.RateTransition3_Buffer0 = GCU_Model_DW.startEngCommand;

  /* Update for RateTransition: '<Root>/Rate Transition4' */
  GCU_Model_DW.RateTransition4_Buffer[(GCU_Model_DW.RateTransition4_ActiveBufIdx
    == 0) << 1] = GCU_Model_DW.aacCommand[0];
  GCU_Model_DW.RateTransition4_Buffer[1 +
    ((GCU_Model_DW.RateTransition4_ActiveBufIdx == 0) << 1)] =
    GCU_Model_DW.aacCommand[1];
  GCU_Model_DW.RateTransition4_ActiveBufIdx = (int8_T)
    (GCU_Model_DW.RateTransition4_ActiveBufIdx == 0);

  /* Update for RateTransition: '<Root>/Rate Transition5' */
  GCU_Model_DW.RateTransition5_Buffer[(GCU_Model_DW.RateTransition5_ActiveBufIdx
    == 0) << 1] = GCU_Model_DW.clutchCommand[0];
  GCU_Model_DW.RateTransition5_Buffer[1 +
    ((GCU_Model_DW.RateTransition5_ActiveBufIdx == 0) << 1)] =
    GCU_Model_DW.clutchCommand[1];
  GCU_Model_DW.RateTransition5_ActiveBufIdx = (int8_T)
    (GCU_Model_DW.RateTransition5_ActiveBufIdx == 0);
}

/* Model initialize function */
void GCU_Model_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&GCU_Model_M->solverInfo,
                          &GCU_Model_M->Timing.simTimeStep);
    rtsiSetTPtr(&GCU_Model_M->solverInfo, &rtmGetTPtr(GCU_Model_M));
    rtsiSetStepSizePtr(&GCU_Model_M->solverInfo, &GCU_Model_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&GCU_Model_M->solverInfo, ((const char_T **)
      (&rtmGetErrorStatus(GCU_Model_M))));
    rtsiSetRTModelPtr(&GCU_Model_M->solverInfo, GCU_Model_M);
  }

  rtsiSetSimTimeStep(&GCU_Model_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&GCU_Model_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(GCU_Model_M, &GCU_Model_M->Timing.tArray[0]);
  GCU_Model_M->Timing.stepSize0 = 0.001;

  /* Model Initialize fcn for ModelReference Block: '<Root>/GCU CAN' */
  GCU_CAN_initialize(rtmGetErrorStatusPointer(GCU_Model_M));

  /* Model Initialize fcn for ModelReference Block: '<Root>/GCU timer' */
  GCU_timer_initialize(rtmGetErrorStatusPointer(GCU_Model_M),
                       &(GCU_Model_M->solverInfo));

  /* SystemInitialize for ModelReference: '<Root>/GCU timer' incorporates:
   *  Outport: '<Root>/currGear'
   */
  GCU_timer_Init();

  /* Chart: '<Root>/AccelerationRoutine' */
  GCU_Model_DW.is_c3_GCU_Model = GCU_Model_IN_Wait;

  /* SystemInitialize for ModelReference: '<Root>/GCU CAN' */
  GCU_CAN_Init(&GCU_Model_DW.shiftCommand[0], &GCU_Model_DW.aacCommand[0],
               &GCU_Model_DW.clutchCommand[0]);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
