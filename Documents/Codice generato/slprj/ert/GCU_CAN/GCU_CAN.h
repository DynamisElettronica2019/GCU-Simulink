/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GCU_CAN.h
 *
 * Code generated for Simulink model 'GCU_CAN'.
 *
 * Model version                  : 1.54
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Mon Feb 18 22:26:07 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_GCU_CAN_h_
#define RTW_HEADER_GCU_CAN_h_
#include "rtwtypes.h"
#ifndef GCU_CAN_COMMON_INCLUDES_
# define GCU_CAN_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* GCU_CAN_COMMON_INCLUDES_ */

/* Forward declaration for rtModel */
typedef struct tag_RTM_GCU_CAN_T RT_MODEL_GCU_CAN_T;

#ifndef DEFINED_TYPEDEF_FOR_aac_values_
#define DEFINED_TYPEDEF_FOR_aac_values_

typedef enum {
  RPM = 0,                             /* Default value */
  WHEEL_SPEED,
  APPS
} aac_values;

#endif

/* Block signals and states (default storage) for system '<Root>/TractionValue' */
#ifndef GCU_CAN_MDLREF_HIDE_CHILD_

typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S3>/Unit Delay' */
} DW_TractionValue_GCU_CAN_T;

#endif                                 /*GCU_CAN_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<Root>/AAC_ExternalValues' */
#ifndef GCU_CAN_MDLREF_HIDE_CHILD_

typedef struct {
  uint16_T UnitDelay_DSTATE[3];        /* '<S1>/Unit Delay' */
} DW_AAC_ExternalValues_GCU_CAN_T;

#endif                                 /*GCU_CAN_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for model 'GCU_CAN' */
#ifndef GCU_CAN_MDLREF_HIDE_CHILD_

typedef struct {
  DW_AAC_ExternalValues_GCU_CAN_T AAC_ExternalValues;/* '<Root>/AAC_ExternalValues' */
  DW_TractionValue_GCU_CAN_T TractionValue;/* '<Root>/TractionValue' */
  uint16_T UnpackCanUart_o1;           /* '<Root>/UnpackCanUart' */
  uint16_T UnpackCanUart_o2;           /* '<Root>/UnpackCanUart' */
  uint16_T UnpackCanUart_o3;           /* '<Root>/UnpackCanUart' */
  uint16_T UnpackCanUart_o4;           /* '<Root>/UnpackCanUart' */
  uint16_T UnpackCanUart_o5;           /* '<Root>/UnpackCanUart' */
  uint8_T is_active_c3_GCU_CAN;        /* '<Root>/MessageEvaluation' */
  uint8_T is_c3_GCU_CAN;               /* '<Root>/MessageEvaluation' */
} DW_GCU_CAN_f_T;

#endif                                 /*GCU_CAN_MDLREF_HIDE_CHILD_*/

#ifndef GCU_CAN_MDLREF_HIDE_CHILD_

/* Real-time Model Data Structure */
struct tag_RTM_GCU_CAN_T {
  const char_T **errorStatus;
};

#endif                                 /*GCU_CAN_MDLREF_HIDE_CHILD_*/

#ifndef GCU_CAN_MDLREF_HIDE_CHILD_

typedef struct {
  RT_MODEL_GCU_CAN_T rtm;
} MdlrefDW_GCU_CAN_T;

#endif                                 /*GCU_CAN_MDLREF_HIDE_CHILD_*/

extern void GCU_CAN_Init(uint16_T rty_shiftCommand[2], uint16_T rty_aacCommand[2],
  uint8_T rty_clutchCommand[2]);
extern void GCU_CAN(const uint8_T *rtu_clutchCurrVal, const uint8_T
                    rtu_dataBuffer[10], uint16_T *rty_currGear, uint16_T
                    rty_aac_externValue[3], uint16_T rty_shiftCommand[2],
                    uint8_T *rty_startEngCommand, uint16_T rty_aacCommand[2],
                    uint8_T rty_clutchCommand[2], uint32_T *rty_tractionValue);

/* Model reference registration function */
extern void GCU_CAN_initialize(const char_T **rt_errorStatus);

#ifndef GCU_CAN_MDLREF_HIDE_CHILD_

extern void GCU_CAN_TractionValue(uint32_T rtu_Value, uint32_T
  *rty_tractionValue, DW_TractionValue_GCU_CAN_T *localDW);
extern void GCU_CAN_AAC_ExternalValues(uint16_T rtu_Value, uint16_T rtu_Index,
  uint16_T rty_Values[3], DW_AAC_ExternalValues_GCU_CAN_T *localDW);

#endif                                 /*GCU_CAN_MDLREF_HIDE_CHILD_*/

#ifndef GCU_CAN_MDLREF_HIDE_CHILD_

extern MdlrefDW_GCU_CAN_T GCU_CAN_MdlrefDW;

#endif                                 /*GCU_CAN_MDLREF_HIDE_CHILD_*/

#ifndef GCU_CAN_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern DW_GCU_CAN_f_T GCU_CAN_DW;

#endif                                 /*GCU_CAN_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'GCU_CAN'
 * '<S1>'   : 'GCU_CAN/AAC_ExternalValues'
 * '<S2>'   : 'GCU_CAN/MessageEvaluation'
 * '<S3>'   : 'GCU_CAN/TractionValue'
 */
#endif                                 /* RTW_HEADER_GCU_CAN_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
