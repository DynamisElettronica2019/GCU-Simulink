/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GCU_Model_genCode_data.c
 *
 * Code generated for Simulink model 'GCU_Model_genCode'.
 *
 * Model version                  : 1.249
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Sun Jun  2 10:41:53 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "GCU_Model_genCode.h"

/* Constant parameters (default storage) */
const ConstP rtConstP = {
  /* Expression: GainVector
   * Referenced by: '<S11>/Gain'
   */
  { 0.030525030525030521, 0.030525030525030521, 0.030525030525030521,
    0.030525030525030521, -0.00028666080586080587, 0.26862026862026861,
    1.614951514751114E-6, 1.614951514751114E-6, 0.030525030525030521 },

  /* Expression: OffsetVector
   * Referenced by: '<S11>/OffSet'
   */
  { 0.0, 0.0, 0.0, 0.0, 190.95, 0.0, 0.00016999999999999999,
    0.00016999999999999999, 0.0 },

  /* Expression: IS_to_IL_vector
   * Referenced by: '<S11>/OffSet1'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 195000.0, 195000.0, 1.0 },

  /* Pooled Parameter (Expression: [uint16(0),uint16(100),uint16(200),uint16(300),uint16(400),uint16(500),uint16(600),uint16(700)])
   * Referenced by:
   *   '<S1>/1-D Lookup Table1'
   *   '<S1>/1-D Lookup Table2'
   *   '<S1>/1-D Lookup Table3'
   */
  { 0U, 100U, 200U, 300U, 400U, 500U, 600U, 700U },

  /* Pooled Parameter (Expression: [0:7])
   * Referenced by:
   *   '<S1>/1-D Lookup Table1'
   *   '<S1>/1-D Lookup Table2'
   *   '<S1>/1-D Lookup Table3'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

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
   *   '<S37>/Values'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
