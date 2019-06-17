/* Include files */

#include "GCU_Model_genCode_sfun.h"
#include "c8_GCU_Model_genCode.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "GCU_Model_genCode_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c8_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c8_sv0[3] = { "RPM_THRESHOLD", "RPM_DELTA_THRESHOLD",
  "GEAR_THRESHOLD" };

static const int32_T c8_iv0[3] = { 0, 1, 2 };

/* Function Declarations */
static void initialize_c8_GCU_Model_genCode(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void initialize_params_c8_GCU_Model_genCode
  (SFc8_GCU_Model_genCodeInstanceStruct *chartInstance);
static void enable_c8_GCU_Model_genCode(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void disable_c8_GCU_Model_genCode(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void c8_update_debugger_state_c8_GCU_Model_genCode
  (SFc8_GCU_Model_genCodeInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_GCU_Model_genCode
  (SFc8_GCU_Model_genCodeInstanceStruct *chartInstance);
static void set_sim_state_c8_GCU_Model_genCode
  (SFc8_GCU_Model_genCodeInstanceStruct *chartInstance, const mxArray *c8_st);
static void c8_set_sim_state_side_effects_c8_GCU_Model_genCode
  (SFc8_GCU_Model_genCodeInstanceStruct *chartInstance);
static void finalize_c8_GCU_Model_genCode(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void sf_gateway_c8_GCU_Model_genCode(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void mdl_start_c8_GCU_Model_genCode(SFc8_GCU_Model_genCodeInstanceStruct *
  chartInstance);
static void initSimStructsc8_GCU_Model_genCode
  (SFc8_GCU_Model_genCodeInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber, uint32_T c8_instanceNumber);
static int32_T c8_getAntiStallParam(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance, c8_anti_stall_params c8_index);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData);
static int32_T c8_emlrt_marshallIn(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_e_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static uint16_T c8_b_emlrt_marshallIn(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c8_b_antiStallFb, const char_T *c8_identifier);
static uint16_T c8_c_emlrt_marshallIn(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static real_T c8_d_emlrt_marshallIn(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c8_b_antiStallState, const char_T
  *c8_identifier);
static real_T c8_e_emlrt_marshallIn(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static uint8_T c8_f_emlrt_marshallIn(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c8_b_antiStallClutchVal, const char_T
  *c8_identifier);
static uint8_T c8_g_emlrt_marshallIn(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_f_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static c8_anti_stall_params c8_h_emlrt_marshallIn
  (SFc8_GCU_Model_genCodeInstanceStruct *chartInstance, const mxArray *c8_u,
   const emlrtMsgIdentifier *c8_parentId);
static void c8_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_i_emlrt_marshallIn(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c8_b_setSimStateSideEffectsInfo, const char_T
  *c8_identifier);
static const mxArray *c8_j_emlrt_marshallIn(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static const mxArray *sf_get_hover_data_for_msg
  (SFc8_GCU_Model_genCodeInstanceStruct *chartInstance, int32_T c8_ssid);
static void c8_init_sf_message_store_memory(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void init_dsm_address_info(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c8_GCU_Model_genCode(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc8_GCU_Model_genCode(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c8_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_doSetSimStateSideEffects = 0U;
  chartInstance->c8_setSimStateSideEffectsInfo = NULL;
  chartInstance->c8_is_active_c8_GCU_Model_genCode = 0U;
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    *chartInstance->c8_antiStallFb = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c8_antiStallFb, 6U);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 2) != 0)) {
    *chartInstance->c8_antiStallState = 0.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c8_antiStallState, 7U);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 3) != 0)) {
    *chartInstance->c8_antiStallClutchVal = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c8_antiStallClutchVal, 8U);
  }
}

static void initialize_params_c8_GCU_Model_genCode
  (SFc8_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c8_GCU_Model_genCode(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_enable(chartInstance->S, 0, "antiStallActivate", 1);
  sf_call_output_fcn_enable(chartInstance->S, 1, "AntiStallActivate", 1);
}

static void disable_c8_GCU_Model_genCode(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_disable(chartInstance->S, 0, "antiStallActivate", 1);
  sf_call_output_fcn_disable(chartInstance->S, 1, "AntiStallActivate", 1);
}

static void c8_update_debugger_state_c8_GCU_Model_genCode
  (SFc8_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c8_GCU_Model_genCode
  (SFc8_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  uint8_T c8_hoistedGlobal;
  const mxArray *c8_b_y = NULL;
  uint16_T c8_b_hoistedGlobal;
  const mxArray *c8_c_y = NULL;
  real_T c8_c_hoistedGlobal;
  const mxArray *c8_d_y = NULL;
  uint8_T c8_d_hoistedGlobal;
  const mxArray *c8_e_y = NULL;
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellmatrix(4, 1), false);
  c8_hoistedGlobal = *chartInstance->c8_antiStallClutchVal;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_b_hoistedGlobal = *chartInstance->c8_antiStallFb;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_b_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c8_y, 1, c8_c_y);
  c8_c_hoistedGlobal = *chartInstance->c8_antiStallState;
  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_create("y", &c8_c_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c8_y, 2, c8_d_y);
  c8_d_hoistedGlobal = chartInstance->c8_is_active_c8_GCU_Model_genCode;
  c8_e_y = NULL;
  sf_mex_assign(&c8_e_y, sf_mex_create("y", &c8_d_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c8_y, 3, c8_e_y);
  sf_mex_assign(&c8_st, c8_y, false);
  return c8_st;
}

static void set_sim_state_c8_GCU_Model_genCode
  (SFc8_GCU_Model_genCodeInstanceStruct *chartInstance, const mxArray *c8_st)
{
  const mxArray *c8_u;
  chartInstance->c8_doneDoubleBufferReInit = true;
  c8_u = sf_mex_dup(c8_st);
  *chartInstance->c8_antiStallClutchVal = c8_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c8_u, 0)), "antiStallClutchVal");
  *chartInstance->c8_antiStallFb = c8_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c8_u, 1)), "antiStallFb");
  *chartInstance->c8_antiStallState = c8_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c8_u, 2)), "antiStallState");
  chartInstance->c8_is_active_c8_GCU_Model_genCode = c8_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 3)),
     "is_active_c8_GCU_Model_genCode");
  sf_mex_assign(&chartInstance->c8_setSimStateSideEffectsInfo,
                c8_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c8_u, 4)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c8_u);
  chartInstance->c8_doSetSimStateSideEffects = 1U;
  c8_update_debugger_state_c8_GCU_Model_genCode(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void c8_set_sim_state_side_effects_c8_GCU_Model_genCode
  (SFc8_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  if (chartInstance->c8_doSetSimStateSideEffects != 0) {
    chartInstance->c8_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c8_GCU_Model_genCode(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c8_setSimStateSideEffectsInfo);
}

static void sf_gateway_c8_GCU_Model_genCode(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  int32_T c8_i0;
  boolean_T c8_out;
  boolean_T c8_b_out;
  int32_T c8_i1;
  boolean_T c8_c_out;
  real_T c8_d0;
  boolean_T c8_d_out;
  int32_T c8_i2;
  boolean_T c8_covSaturation;
  int32_T c8_saturatedUnaryMinus;
  real_T c8_d1;
  boolean_T c8_e_out;
  uint8_T c8_b_Inport;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  c8_set_sim_state_side_effects_c8_GCU_Model_genCode(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c8_currGear, 5U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c8_deltarpm, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c8_rpm, 3U);
  for (c8_i0 = 0; c8_i0 < 8; c8_i0++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c8_antiStall_parameters)
                          [c8_i0], 2U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c8_stop, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c8_enable, 0U);
  chartInstance->c8_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
  *chartInstance->c8_antiStallState = 0.0;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c8_antiStallState, 7U);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c8_sfEvent);
  c8_out = (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(5U, 1U, 0, (boolean_T)
              CV_RELATIONAL_EVAL(5U, 1U, 0, (real_T)*chartInstance->c8_enable,
    1.0, 0, 0U, *chartInstance->c8_enable == 1) != 0U, chartInstance->c8_sfEvent))
            != 0);
  guard1 = false;
  guard2 = false;
  guard3 = false;
  if (c8_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
    *chartInstance->c8_antiStallState = 1.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c8_antiStallState, 7U);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c8_sfEvent);
    c8_b_out = (CV_TRANSITION_EVAL(3U, (int32_T)_SFD_CCP_CALL(5U, 3U, 0,
      (boolean_T)CV_RELATIONAL_EVAL(5U, 3U, 0, (real_T)*chartInstance->c8_stop,
      0.0, 0, 0U, *chartInstance->c8_stop == 0) != 0U, chartInstance->c8_sfEvent))
                != 0);
    if (c8_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c8_sfEvent);
      *chartInstance->c8_antiStallState = 2.0;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c8_antiStallState, 7U);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U,
                   chartInstance->c8_sfEvent);
      c8_i1 = c8_getAntiStallParam(chartInstance,
        anti_stall_params_GEAR_THRESHOLD);
      c8_c_out = (CV_TRANSITION_EVAL(17U, (int32_T)_SFD_CCP_CALL(5U, 17U, 0,
        (boolean_T)CV_RELATIONAL_EVAL(5U, 17U, 0, (real_T)
        *chartInstance->c8_currGear, (real_T)c8_i1, 0, 5U,
        *chartInstance->c8_currGear >= c8_i1) != 0U, chartInstance->c8_sfEvent))
                  != 0);
      if (c8_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c8_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c8_sfEvent);
        *chartInstance->c8_antiStallState = 3.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c8_antiStallState, 7U);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                     chartInstance->c8_sfEvent);
        c8_d0 = (real_T)c8_getAntiStallParam(chartInstance,
          anti_stall_params_RPM_THRESHOLD);
        c8_d_out = (CV_TRANSITION_EVAL(4U, (int32_T)_SFD_CCP_CALL(5U, 4U, 0,
          (boolean_T)CV_RELATIONAL_EVAL(5U, 4U, 0, *chartInstance->c8_rpm, c8_d0,
          -1, 3U, *chartInstance->c8_rpm <= c8_d0) != 0U,
          chartInstance->c8_sfEvent)) != 0);
        if (c8_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c8_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c8_sfEvent);
          *chartInstance->c8_antiStallState = 4.0;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c8_antiStallState, 7U);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                       chartInstance->c8_sfEvent);
          c8_i2 = c8_getAntiStallParam(chartInstance,
            anti_stall_params_RPM_DELTA_THRESHOLD);
          c8_covSaturation = false;
          if (c8_i2 <= MIN_int32_T) {
            c8_covSaturation = true;
            c8_saturatedUnaryMinus = MAX_int32_T;
            _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 22U, 13U, 1U);
          } else {
            c8_saturatedUnaryMinus = -c8_i2;
          }

          CV_SATURATION_EVAL(5, 6, 0, 0, c8_covSaturation);
          c8_d1 = (real_T)c8_saturatedUnaryMinus;
          c8_e_out = (CV_TRANSITION_EVAL(6U, (int32_T)_SFD_CCP_CALL(5U, 6U, 0,
            (boolean_T)CV_RELATIONAL_EVAL(5U, 6U, 0, *chartInstance->c8_deltarpm,
            c8_d1, -1, 3U, *chartInstance->c8_deltarpm <= c8_d1) != 0U,
            chartInstance->c8_sfEvent)) != 0);
          if (c8_e_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c8_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c8_sfEvent);
            c8_b_Inport = 0U;
            _SFD_SET_DATA_VALUE_PTR(10U, (void *)&c8_b_Inport);
            _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
            _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("Inport", &c8_b_Inport,
              c8_b_sf_marshallOut, c8_d_sf_marshallIn);
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                         chartInstance->c8_sfEvent);
            *chartInstance->c8_Inport = c8_b_Inport;
            sf_call_output_fcn_call(chartInstance->S, 1, "AntiStallActivate", 1);
            _SFD_SYMBOL_SCOPE_POP();
            _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
            _SFD_UNSET_DATA_VALUE_PTR(10U);
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c8_sfEvent);
            *chartInstance->c8_antiStallFb = (uint16_T)ANTISTALL_ON;
            _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c8_antiStallFb, 6U);
            *chartInstance->c8_antiStallState = 5.0;
            _SFD_DATA_RANGE_CHECK(*chartInstance->c8_antiStallState, 7U);
            *chartInstance->c8_antiStallClutchVal = 100U;
            _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c8_antiStallClutchVal,
                                  8U);
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c8_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c8_sfEvent);
          }
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c8_sfEvent);
          guard1 = true;
        }
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c8_sfEvent);
        guard2 = true;
      }
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c8_sfEvent);
      *chartInstance->c8_antiStallFb = (uint16_T)ANTISTALL_OFF;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c8_antiStallFb, 6U);
      *chartInstance->c8_antiStallClutchVal = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c8_antiStallClutchVal, 8U);
      guard3 = true;
    }
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c8_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c8_sfEvent);
    guard3 = true;
  }

  if (guard3) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c8_sfEvent);
    guard2 = true;
  }

  if (guard2) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c8_sfEvent);
    guard1 = true;
  }

  if (guard1) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c8_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c8_sfEvent);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
}

static void mdl_start_c8_GCU_Model_genCode(SFc8_GCU_Model_genCodeInstanceStruct *
  chartInstance)
{
  c8_init_sf_message_store_memory(chartInstance);
  sim_mode_is_external(chartInstance->S);
}

static void initSimStructsc8_GCU_Model_genCode
  (SFc8_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber, uint32_T c8_instanceNumber)
{
  (void)(c8_machineNumber);
  (void)(c8_chartNumber);
  (void)(c8_instanceNumber);
}

const mxArray *sf_c8_GCU_Model_genCode_get_eml_resolved_functions_info(void)
{
  const mxArray *c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  sf_mex_assign(&c8_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c8_nameCaptureInfo;
}

static int32_T c8_getAntiStallParam(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance, c8_anti_stall_params c8_index)
{
  int32_T c8_param;
  int32_T c8_b_param;
  _SFD_SET_DATA_VALUE_PTR(11U, (void *)&c8_param);
  _SFD_SET_DATA_VALUE_PTR(9U, (void *)&c8_index);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(2U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("index", &c8_index, c8_f_sf_marshallOut,
    c8_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("param", &c8_param, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c8_sfEvent);
  c8_param = 0;
  _SFD_DATA_RANGE_CHECK((real_T)c8_param, 11U);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c8_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c8_sfEvent);
  c8_param = (*chartInstance->c8_antiStall_parameters)[sf_array_bounds_check
    (sfGlobalDebugInstanceStruct, chartInstance->S, 58U, 9, 20, 2U, (int32_T)
     c8_index, 0, 7)];
  _SFD_DATA_RANGE_CHECK((real_T)c8_param, 11U);
  c8_b_param = c8_param;
  sf_mex_printf("%s =\\n", "param");
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 12, c8_b_param);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(11U);
  _SFD_UNSET_DATA_VALUE_PTR(9U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c8_sfEvent);
  return c8_param;
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData)
{
  const mxArray *c8_mxArrayOutData;
  int32_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc8_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_mxArrayOutData = NULL;
  c8_u = *(int32_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static int32_T c8_emlrt_marshallIn(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_y;
  int32_T c8_i3;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i3, 1, 6, 0U, 0, 0U, 0);
  c8_y = c8_i3;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y;
  SFc8_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc8_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = (const char *)c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_y = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent), &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData;
  uint8_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc8_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_mxArrayOutData = NULL;
  c8_u = *(uint8_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData;
  int32_T c8_i4;
  const mxArray *c8_y = NULL;
  int32_T c8_u[8];
  SFc8_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc8_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_mxArrayOutData = NULL;
  for (c8_i4 = 0; c8_i4 < 8; c8_i4++) {
    c8_u[c8_i4] = (*(int32_T (*)[8])c8_inData)[c8_i4];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 6, 0U, 1U, 0U, 2, 1, 8), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData;
  real_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc8_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_mxArrayOutData = NULL;
  c8_u = *(real_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_e_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData;
  uint16_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc8_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_mxArrayOutData = NULL;
  c8_u = *(uint16_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static uint16_T c8_b_emlrt_marshallIn(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c8_b_antiStallFb, const char_T *c8_identifier)
{
  uint16_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = (const char *)c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_y = c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_antiStallFb),
    &c8_thisId);
  sf_mex_destroy(&c8_b_antiStallFb);
  return c8_y;
}

static uint16_T c8_c_emlrt_marshallIn(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint16_T c8_y;
  uint16_T c8_u0;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u0, 1, 5, 0U, 0, 0U, 0);
  c8_y = c8_u0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_antiStallFb;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  uint16_T c8_y;
  SFc8_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc8_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c8_b_antiStallFb = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = (const char *)c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_y = c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_antiStallFb),
    &c8_thisId);
  sf_mex_destroy(&c8_b_antiStallFb);
  *(uint16_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static real_T c8_d_emlrt_marshallIn(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c8_b_antiStallState, const char_T
  *c8_identifier)
{
  real_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = (const char *)c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_y = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_antiStallState),
    &c8_thisId);
  sf_mex_destroy(&c8_b_antiStallState);
  return c8_y;
}

static real_T c8_e_emlrt_marshallIn(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_y;
  real_T c8_d2;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_d2, 1, 0, 0U, 0, 0U, 0);
  c8_y = c8_d2;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_antiStallState;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y;
  SFc8_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc8_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c8_b_antiStallState = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = (const char *)c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_y = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_antiStallState),
    &c8_thisId);
  sf_mex_destroy(&c8_b_antiStallState);
  *(real_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static uint8_T c8_f_emlrt_marshallIn(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c8_b_antiStallClutchVal, const char_T
  *c8_identifier)
{
  uint8_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = (const char *)c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_y = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_antiStallClutchVal),
    &c8_thisId);
  sf_mex_destroy(&c8_b_antiStallClutchVal);
  return c8_y;
}

static uint8_T c8_g_emlrt_marshallIn(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_y;
  uint8_T c8_u1;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u1, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_u1;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_antiStallClutchVal;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  uint8_T c8_y;
  SFc8_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc8_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c8_b_antiStallClutchVal = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = (const char *)c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_y = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_antiStallClutchVal),
    &c8_thisId);
  sf_mex_destroy(&c8_b_antiStallClutchVal);
  *(uint8_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_f_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData;
  c8_anti_stall_params c8_u;
  const mxArray *c8_y = NULL;
  int32_T c8_b_u;
  const mxArray *c8_b_y = NULL;
  const mxArray *c8_m0 = NULL;
  SFc8_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc8_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_mxArrayOutData = NULL;
  c8_u = *(c8_anti_stall_params *)c8_inData;
  c8_y = NULL;
  sf_mex_check_enum("anti_stall_params", 3, c8_sv0, c8_iv0);
  c8_b_u = (int32_T)c8_u;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_m0, c8_b_y, false);
  sf_mex_assign(&c8_y, sf_mex_create_enum("anti_stall_params", c8_m0), false);
  sf_mex_destroy(&c8_m0);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static c8_anti_stall_params c8_h_emlrt_marshallIn
  (SFc8_GCU_Model_genCodeInstanceStruct *chartInstance, const mxArray *c8_u,
   const emlrtMsgIdentifier *c8_parentId)
{
  c8_anti_stall_params c8_y;
  (void)chartInstance;
  sf_mex_check_enum("anti_stall_params", 3, c8_sv0, c8_iv0);
  sf_mex_check_builtin(c8_parentId, c8_u, "anti_stall_params", 0, 0U, NULL);
  c8_y = (c8_anti_stall_params)sf_mex_get_enum_element(c8_u, 0);
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_index;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  c8_anti_stall_params c8_y;
  SFc8_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc8_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c8_index = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = (const char *)c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_y = c8_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_index), &c8_thisId);
  sf_mex_destroy(&c8_index);
  *(c8_anti_stall_params *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_i_emlrt_marshallIn(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c8_b_setSimStateSideEffectsInfo, const char_T
  *c8_identifier)
{
  const mxArray *c8_y = NULL;
  emlrtMsgIdentifier c8_thisId;
  c8_y = NULL;
  c8_thisId.fIdentifier = (const char *)c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  sf_mex_assign(&c8_y, c8_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_setSimStateSideEffectsInfo), &c8_thisId), false);
  sf_mex_destroy(&c8_b_setSimStateSideEffectsInfo);
  return c8_y;
}

static const mxArray *c8_j_emlrt_marshallIn(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  const mxArray *c8_y = NULL;
  (void)chartInstance;
  (void)c8_parentId;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_duplicatearraysafe(&c8_u), false);
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static const mxArray *sf_get_hover_data_for_msg
  (SFc8_GCU_Model_genCodeInstanceStruct *chartInstance, int32_T c8_ssid)
{
  (void)chartInstance;
  (void)c8_ssid;
  return NULL;
}

static void c8_init_sf_message_store_memory(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_dsm_address_info(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc8_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  chartInstance->c8_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c8_enable = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c8_stop = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c8_antiStall_parameters = (int32_T (*)[8])
    ssGetInputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c8_rpm = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c8_deltarpm = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c8_antiStallFb = (uint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c8_currGear = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c8_antiStallState = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c8_antiStallClutchVal = (uint8_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 3);
  chartInstance->c8_Inport = (uint8_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c8_GCU_Model_genCode_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3032290800U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2963614062U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1486345909U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1562096906U);
}

mxArray* sf_c8_GCU_Model_genCode_get_post_codegen_info(void);
mxArray *sf_c8_GCU_Model_genCode_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("nyc7jVNDW10ZcmM1KJTQgG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(8);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c8_GCU_Model_genCode_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c8_GCU_Model_genCode_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c8_GCU_Model_genCode_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("early");
  mxArray *fallbackReason = mxCreateString("custom_code");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c8_GCU_Model_genCode_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c8_GCU_Model_genCode_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c8_GCU_Model_genCode(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[63],T\"antiStallClutchVal\",},{M[1],M[33],T\"antiStallFb\",},{M[1],M[60],T\"antiStallState\",},{M[8],M[0],T\"is_active_c8_GCU_Model_genCode\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_GCU_Model_genCode_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc8_GCU_Model_genCodeInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_GCU_Model_genCodeInstanceStruct *chartInstance =
      (SFc8_GCU_Model_genCodeInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _GCU_Model_genCodeMachineNumber_,
           8,
           2,
           23,
           0,
           12,
           1,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_GCU_Model_genCodeMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_GCU_Model_genCodeMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _GCU_Model_genCodeMachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,1,1,0,"enable");
          _SFD_SET_DATA_PROPS(1,1,1,0,"stop");
          _SFD_SET_DATA_PROPS(2,1,1,0,"antiStall_parameters");
          _SFD_SET_DATA_PROPS(3,1,1,0,"rpm");
          _SFD_SET_DATA_PROPS(4,1,1,0,"deltarpm");
          _SFD_SET_DATA_PROPS(5,1,1,0,"currGear");
          _SFD_SET_DATA_PROPS(6,2,0,1,"antiStallFb");
          _SFD_SET_DATA_PROPS(7,2,0,1,"antiStallState");
          _SFD_SET_DATA_PROPS(8,2,0,1,"antiStallClutchVal");
          _SFD_SET_DATA_PROPS(9,8,0,0,"");
          _SFD_SET_DATA_PROPS(10,8,0,0,"");
          _SFD_SET_DATA_PROPS(11,9,0,0,"");
          _SFD_EVENT_SCOPE(0,2);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(1,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 12 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(1,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 10 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(3,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 10 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(3,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 64 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(17,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 64 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 5, 5 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(17,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 58 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(4,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 58 };

          static int sRelationalopEps[] = { -1 };

          static int sRelationalopType[] = { 3, 3 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(4,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 70 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(6,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartSaturateMap[] = { 13 };

          static unsigned int sEndSaturateMap[] = { 14 };

          _SFD_CV_INIT_TRANSITION_SATURATION(6,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 70 };

          static int sRelationalopEps[] = { -1 };

          static int sRelationalopType[] = { 3, 3 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(6,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 8U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_e_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_d_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_f_sf_marshallOut,(MexInFcnForType)c8_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)c8_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(9,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(10,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(11,(void *)(NULL));
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _GCU_Model_genCodeMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_GCU_Model_genCodeInstanceStruct *chartInstance =
      (SFc8_GCU_Model_genCodeInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c8_enable);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c8_stop);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)
          chartInstance->c8_antiStall_parameters);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c8_rpm);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c8_deltarpm);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)chartInstance->c8_antiStallFb);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)chartInstance->c8_currGear);
        _SFD_SET_DATA_VALUE_PTR(7U, (void *)chartInstance->c8_antiStallState);
        _SFD_SET_DATA_VALUE_PTR(8U, (void *)chartInstance->c8_antiStallClutchVal);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "s3AgCfBKfl4CbKXixcOcfoH";
}

static void sf_opaque_initialize_c8_GCU_Model_genCode(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc8_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c8_GCU_Model_genCode((SFc8_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar);
  initialize_c8_GCU_Model_genCode((SFc8_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c8_GCU_Model_genCode(void *chartInstanceVar)
{
  enable_c8_GCU_Model_genCode((SFc8_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c8_GCU_Model_genCode(void *chartInstanceVar)
{
  disable_c8_GCU_Model_genCode((SFc8_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c8_GCU_Model_genCode(void *chartInstanceVar)
{
  sf_gateway_c8_GCU_Model_genCode((SFc8_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c8_GCU_Model_genCode(SimStruct* S)
{
  return get_sim_state_c8_GCU_Model_genCode
    ((SFc8_GCU_Model_genCodeInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c8_GCU_Model_genCode(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c8_GCU_Model_genCode((SFc8_GCU_Model_genCodeInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c8_GCU_Model_genCode(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_GCU_Model_genCodeInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_GCU_Model_genCode_optimization_info();
    }

    finalize_c8_GCU_Model_genCode((SFc8_GCU_Model_genCodeInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_GCU_Model_genCode((SFc8_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_GCU_Model_genCode(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_GCU_Model_genCode((SFc8_GCU_Model_genCodeInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c8_GCU_Model_genCode(SimStruct *S)
{
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetInputPortDirectFeedThrough(S, 1, 1);
  ssSetInputPortDirectFeedThrough(S, 2, 1);
  ssSetInputPortDirectFeedThrough(S, 3, 1);
  ssSetInputPortDirectFeedThrough(S, 4, 1);
  ssSetInputPortDirectFeedThrough(S, 5, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_GCU_Model_genCode_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetSupportedForRowMajorCodeGen(S, 1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,8,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 8);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,8);
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,8,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,8,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,8,4);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,8);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetCallsOutputInInitFcn(S,1);
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(67037061U));
  ssSetChecksum1(S,(3115373792U));
  ssSetChecksum2(S,(2267001132U));
  ssSetChecksum3(S,(1743087694U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c8_GCU_Model_genCode(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c8_GCU_Model_genCode(SimStruct *S)
{
  SFc8_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc8_GCU_Model_genCodeInstanceStruct *)utMalloc(sizeof
    (SFc8_GCU_Model_genCodeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc8_GCU_Model_genCodeInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_GCU_Model_genCode;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_GCU_Model_genCode;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c8_GCU_Model_genCode;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c8_GCU_Model_genCode;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c8_GCU_Model_genCode;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_GCU_Model_genCode;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_GCU_Model_genCode;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_GCU_Model_genCode;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_GCU_Model_genCode;
  chartInstance->chartInfo.mdlStart = mdlStart_c8_GCU_Model_genCode;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_GCU_Model_genCode;
  chartInstance->chartInfo.callGetHoverDataForMsg =
    sf_opaque_get_hover_data_for_msg;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c8_GCU_Model_genCode(chartInstance);
}

void c8_GCU_Model_genCode_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_GCU_Model_genCode(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_GCU_Model_genCode(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_GCU_Model_genCode(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_GCU_Model_genCode_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
