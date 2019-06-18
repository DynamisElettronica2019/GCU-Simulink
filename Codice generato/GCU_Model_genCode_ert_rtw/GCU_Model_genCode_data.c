/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GCU_Model_genCode_data.c
 *
 * Code generated for Simulink model 'GCU_Model_genCode'.
 *
 * Model version                  : 1.312
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Tue Jun 18 20:21:41 2019
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
  /* Pooled Parameter (Expression: [uint16(0),uint16(100),uint16(200),uint16(300),uint16(400),uint16(500),uint16(600),uint16(700)])
   * Referenced by:
   *   '<S2>/1-D Lookup Table1'
   *   '<S2>/1-D Lookup Table2'
   */
  { 0U, 100U, 200U, 300U, 400U, 500U, 600U, 700U },

  /* Pooled Parameter (Expression: [0:7])
   * Referenced by:
   *   '<S2>/1-D Lookup Table1'
   *   '<S2>/1-D Lookup Table2'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Expression: [uint16(0),uint16(100),uint16(200),uint16(300),uint16(400),uint16(500),uint16(600),uint16(700),uint16(800),uint16(900),uint16(1000)];
   * Referenced by: '<S2>/1-D Lookup Table3'
   */
  { 0U, 100U, 200U, 300U, 400U, 500U, 600U, 700U, 800U, 900U, 1000U },

  /* Computed Parameter: uDLookupTable3_bp01Data
   * Referenced by: '<S2>/1-D Lookup Table3'
   */
  { 65U, 70U, 75U, 80U, 85U, 90U, 95U, 100U, 105U, 110U, 115U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
