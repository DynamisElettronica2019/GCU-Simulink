/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GCU_Model_genCode_data.c
 *
 * Code generated for Simulink model 'GCU_Model_genCode'.
 *
 * Model version                  : 1.288
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Sun Jun  9 17:13:37 2019
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
  /* Expression: VoltageOffsetVector
   * Referenced by: '<S10>/OffSet'
   */
  { 0.0, 0.0, 0.0, 0.0, -0.1, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: ConversionGainVector
   * Referenced by: '<S10>/OffSet1'
   */
  { 37.878787878787875, 37.878787878787875, 37.878787878787875,
    37.878787878787875, 100.0, 333.33333333333331, 414.89361702127661,
    414.89361702127661, 37.878787878787875 },

  /* Expression: ConversionOffsetVector
   * Referenced by: '<S10>/OffSet2'
   */
  { 0.0, 0.0, 0.0, 0.0, -40.0, 0.0, -33.15, -33.15, 0.0 },

  /* Pooled Parameter (Expression: [uint16(0),uint16(100),uint16(200),uint16(300),uint16(400),uint16(500),uint16(600),uint16(700)])
   * Referenced by:
   *   '<S2>/1-D Lookup Table1'
   *   '<S2>/1-D Lookup Table2'
   *   '<S2>/1-D Lookup Table3'
   */
  { 0U, 100U, 200U, 300U, 400U, 500U, 600U, 700U },

  /* Pooled Parameter (Expression: [0:7])
   * Referenced by:
   *   '<S2>/1-D Lookup Table1'
   *   '<S2>/1-D Lookup Table2'
   *   '<S2>/1-D Lookup Table3'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<Root>/Rate Transition'
   *   '<Root>/Rate Transition3'
   *   '<Root>/Rate Transition30'
   *   '<Root>/Rate Transition33'
   *   '<Root>/Rate Transition5'
   *   '<S25>/dataRead'
   *   '<S38>/Merge'
   *   '<S41>/Pin_H'
   *   '<S41>/Pin_In1'
   *   '<S41>/Pin_In2'
   *   '<S27>/loadResult'
   *   '<S28>/readResult'
   *   '<S28>/data'
   *   '<S29>/writeResult'
   *   '<S29>/wpState'
   *   '<S46>/Constant'
   *   '<S47>/Saturation'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
