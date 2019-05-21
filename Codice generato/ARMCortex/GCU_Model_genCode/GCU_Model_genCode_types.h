/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GCU_Model_genCode_types.h
 *
 * Code generated for Simulink model 'GCU_Model_genCode'.
 *
 * Model version                  : 1.173
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Tue May 21 18:47:07 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_GCU_Model_genCode_types_h_
#define RTW_HEADER_GCU_Model_genCode_types_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#ifndef SS_INT64
#define SS_INT64                       18
#endif

#ifndef SS_UINT64
#define SS_UINT64                      19
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

#ifndef DEFINED_TYPEDEF_FOR_acc_values_
#define DEFINED_TYPEDEF_FOR_acc_values_

typedef enum {
  RPM = 0,                             /* Default value */
  WHEEL_SPEED,
  TPS
} acc_values;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#endif                                 /* RTW_HEADER_GCU_Model_genCode_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
