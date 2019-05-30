/* Include files */

#include "GCU_Model_genCode_sfun.h"
#include "c4_GCU_Model_genCode.h"
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
#define c4_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c4_GCU_Model_genCode(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void initialize_params_c4_GCU_Model_genCode
  (SFc4_GCU_Model_genCodeInstanceStruct *chartInstance);
static void enable_c4_GCU_Model_genCode(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void disable_c4_GCU_Model_genCode(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void c4_update_debugger_state_c4_GCU_Model_genCode
  (SFc4_GCU_Model_genCodeInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_GCU_Model_genCode
  (SFc4_GCU_Model_genCodeInstanceStruct *chartInstance);
static void set_sim_state_c4_GCU_Model_genCode
  (SFc4_GCU_Model_genCodeInstanceStruct *chartInstance, const mxArray *c4_st);
static void c4_set_sim_state_side_effects_c4_GCU_Model_genCode
  (SFc4_GCU_Model_genCodeInstanceStruct *chartInstance);
static void finalize_c4_GCU_Model_genCode(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void sf_gateway_c4_GCU_Model_genCode(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void mdl_start_c4_GCU_Model_genCode(SFc4_GCU_Model_genCodeInstanceStruct *
  chartInstance);
static void initSimStructsc4_GCU_Model_genCode
  (SFc4_GCU_Model_genCodeInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static int32_T c4_emlrt_marshallIn(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static uint16_T c4_b_emlrt_marshallIn(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c4_b_gcu_traction_limiter_loil_efi_id, const
  char_T *c4_identifier);
static uint16_T c4_c_emlrt_marshallIn(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static uint8_T c4_d_emlrt_marshallIn(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c4_b_counter3, const char_T *c4_identifier);
static uint8_T c4_e_emlrt_marshallIn(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_f_emlrt_marshallIn(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c4_b_setSimStateSideEffectsInfo, const char_T
  *c4_identifier);
static const mxArray *c4_g_emlrt_marshallIn(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static const mxArray *sf_get_hover_data_for_msg
  (SFc4_GCU_Model_genCodeInstanceStruct *chartInstance, int32_T c4_ssid);
static void c4_init_sf_message_store_memory(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static int32_T c4__s32_add__(SFc4_GCU_Model_genCodeInstanceStruct *chartInstance,
  int32_T c4_b, int32_T c4_c, uint32_T c4_ssid_src_loc, int32_T
  c4_offset_src_loc, int32_T c4_length_src_loc);
static void init_dsm_address_info(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_GCU_Model_genCode(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc4_GCU_Model_genCode(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_doSetSimStateSideEffects = 0U;
  chartInstance->c4_setSimStateSideEffectsInfo = NULL;
  chartInstance->c4_is_active_c4_GCU_Model_genCode = 0U;
  chartInstance->c4_counter3 = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c4_counter3, 2U);
  chartInstance->c4_counter1 = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c4_counter1, 0U);
  chartInstance->c4_counter2 = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c4_counter2, 1U);
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    *chartInstance->c4_gcu_traction_limiter_loil_efi_id = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)
                          *chartInstance->c4_gcu_traction_limiter_loil_efi_id,
                          3U);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 2) != 0)) {
    *chartInstance->c4_gcu_clutch_mode_map_sw_id = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_gcu_clutch_mode_map_sw_id,
                          4U);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 3) != 0)) {
    *chartInstance->c4_gcu_traction_limiter_autog_acc_sw_id = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)
                          *chartInstance->c4_gcu_traction_limiter_autog_acc_sw_id,
                          5U);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 4) != 0)) {
    *chartInstance->c4_gcu_debug_1_id = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_gcu_debug_1_id, 6U);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 5) != 0)) {
    *chartInstance->c4_gcu_debug_2_id = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_gcu_debug_2_id, 7U);
  }
}

static void initialize_params_c4_GCU_Model_genCode
  (SFc4_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_GCU_Model_genCode(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_enable(chartInstance->S, 0, "send100Hz", 0);
  sf_call_output_fcn_enable(chartInstance->S, 1, "send10Hz", 0);
  sf_call_output_fcn_enable(chartInstance->S, 2, "send1Hz", 0);
}

static void disable_c4_GCU_Model_genCode(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_disable(chartInstance->S, 0, "send100Hz", 0);
  sf_call_output_fcn_disable(chartInstance->S, 1, "send10Hz", 0);
  sf_call_output_fcn_disable(chartInstance->S, 2, "send1Hz", 0);
}

static void c4_update_debugger_state_c4_GCU_Model_genCode
  (SFc4_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_GCU_Model_genCode
  (SFc4_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  uint16_T c4_hoistedGlobal;
  const mxArray *c4_b_y = NULL;
  uint16_T c4_b_hoistedGlobal;
  const mxArray *c4_c_y = NULL;
  uint16_T c4_c_hoistedGlobal;
  const mxArray *c4_d_y = NULL;
  uint16_T c4_d_hoistedGlobal;
  const mxArray *c4_e_y = NULL;
  uint16_T c4_e_hoistedGlobal;
  const mxArray *c4_f_y = NULL;
  uint8_T c4_f_hoistedGlobal;
  const mxArray *c4_g_y = NULL;
  uint8_T c4_g_hoistedGlobal;
  const mxArray *c4_h_y = NULL;
  uint8_T c4_h_hoistedGlobal;
  const mxArray *c4_i_y = NULL;
  uint8_T c4_i_hoistedGlobal;
  const mxArray *c4_j_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(9, 1), false);
  c4_hoistedGlobal = *chartInstance->c4_gcu_clutch_mode_map_sw_id;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_hoistedGlobal, 5, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = *chartInstance->c4_gcu_debug_1_id;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_c_hoistedGlobal = *chartInstance->c4_gcu_debug_2_id;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_d_hoistedGlobal = *chartInstance->c4_gcu_traction_limiter_autog_acc_sw_id;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_e_hoistedGlobal = *chartInstance->c4_gcu_traction_limiter_loil_efi_id;
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_e_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 4, c4_f_y);
  c4_f_hoistedGlobal = chartInstance->c4_counter1;
  c4_g_y = NULL;
  sf_mex_assign(&c4_g_y, sf_mex_create("y", &c4_f_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 5, c4_g_y);
  c4_g_hoistedGlobal = chartInstance->c4_counter2;
  c4_h_y = NULL;
  sf_mex_assign(&c4_h_y, sf_mex_create("y", &c4_g_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 6, c4_h_y);
  c4_h_hoistedGlobal = chartInstance->c4_counter3;
  c4_i_y = NULL;
  sf_mex_assign(&c4_i_y, sf_mex_create("y", &c4_h_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 7, c4_i_y);
  c4_i_hoistedGlobal = chartInstance->c4_is_active_c4_GCU_Model_genCode;
  c4_j_y = NULL;
  sf_mex_assign(&c4_j_y, sf_mex_create("y", &c4_i_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 8, c4_j_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_GCU_Model_genCode
  (SFc4_GCU_Model_genCodeInstanceStruct *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  *chartInstance->c4_gcu_clutch_mode_map_sw_id = c4_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)),
     "gcu_clutch_mode_map_sw_id");
  *chartInstance->c4_gcu_debug_1_id = c4_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 1)), "gcu_debug_1_id");
  *chartInstance->c4_gcu_debug_2_id = c4_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 2)), "gcu_debug_2_id");
  *chartInstance->c4_gcu_traction_limiter_autog_acc_sw_id =
    c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 3)),
    "gcu_traction_limiter_autog_acc_sw_id");
  *chartInstance->c4_gcu_traction_limiter_loil_efi_id = c4_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 4)),
     "gcu_traction_limiter_loil_efi_id");
  chartInstance->c4_counter1 = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 5)), "counter1");
  chartInstance->c4_counter2 = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 6)), "counter2");
  chartInstance->c4_counter3 = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 7)), "counter3");
  chartInstance->c4_is_active_c4_GCU_Model_genCode = c4_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 8)),
     "is_active_c4_GCU_Model_genCode");
  sf_mex_assign(&chartInstance->c4_setSimStateSideEffectsInfo,
                c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 9)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c4_u);
  chartInstance->c4_doSetSimStateSideEffects = 1U;
  c4_update_debugger_state_c4_GCU_Model_genCode(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void c4_set_sim_state_side_effects_c4_GCU_Model_genCode
  (SFc4_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  if (chartInstance->c4_doSetSimStateSideEffects != 0) {
    chartInstance->c4_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c4_GCU_Model_genCode(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c4_setSimStateSideEffectsInfo);
}

static void sf_gateway_c4_GCU_Model_genCode(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  boolean_T c4_out;
  boolean_T c4_b_out;
  int32_T c4_i0;
  boolean_T c4_covSaturation;
  int32_T c4_i1;
  boolean_T c4_b_covSaturation;
  boolean_T guard1 = false;
  c4_set_sim_state_side_effects_c4_GCU_Model_genCode(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
  *chartInstance->c4_gcu_traction_limiter_loil_efi_id = (uint16_T)
    GCU_TRACTION_LIMITER_LOIL_EFI_ID;
  _SFD_DATA_RANGE_CHECK((real_T)
                        *chartInstance->c4_gcu_traction_limiter_loil_efi_id, 3U);
  *chartInstance->c4_gcu_clutch_mode_map_sw_id = (uint16_T)
    GCU_CLUTCH_MODE_MAP_SW_ID;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_gcu_clutch_mode_map_sw_id, 4U);
  *chartInstance->c4_gcu_traction_limiter_autog_acc_sw_id = (uint16_T)
    GCU_TRACTION_LIMITER_AUTOG_ACC_SW_ID;
  _SFD_DATA_RANGE_CHECK((real_T)
                        *chartInstance->c4_gcu_traction_limiter_autog_acc_sw_id,
                        5U);
  *chartInstance->c4_gcu_debug_1_id = (uint16_T)GCU_DEBUG_1_ID;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_gcu_debug_1_id, 6U);
  *chartInstance->c4_gcu_debug_2_id = (uint16_T)GCU_DEBUG_2_ID;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_gcu_debug_2_id, 7U);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c4_sfEvent);
  c4_out = (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(5U, 1U, 0, (boolean_T)
              CV_RELATIONAL_EVAL(5U, 1U, 0, (real_T)chartInstance->c4_counter3,
    100.0, 0, 5U, chartInstance->c4_counter3 >= 100) != 0U,
              chartInstance->c4_sfEvent)) != 0);
  guard1 = false;
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
    sf_call_output_fcn_call(chartInstance->S, 2, "send1Hz", 0);
    chartInstance->c4_counter3 = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c4_counter3, 2U);
    guard1 = true;
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, chartInstance->c4_sfEvent);
    c4_b_out = (CV_TRANSITION_EVAL(4U, (int32_T)_SFD_CCP_CALL(5U, 4U, 0,
      (boolean_T)CV_RELATIONAL_EVAL(5U, 4U, 0, (real_T)
      chartInstance->c4_counter2, 10.0, 0, 5U, chartInstance->c4_counter2 >= 10)
      != 0U, chartInstance->c4_sfEvent)) != 0);
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
      guard1 = true;
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c4_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
    }
  }

  if (guard1) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
    sf_call_output_fcn_call(chartInstance->S, 1, "send10Hz", 0);
    chartInstance->c4_counter2 = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c4_counter2, 1U);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
  sf_call_output_fcn_call(chartInstance->S, 0, "send100Hz", 0);
  c4_i0 = c4__s32_add__(chartInstance, (int32_T)chartInstance->c4_counter2, 1,
                        27U, 19, 10);
  c4_covSaturation = false;
  if (c4_i0 < 0) {
    c4_covSaturation = true;
    c4_i0 = 0;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 27U, 19U, 10U);
  } else {
    if (c4_i0 > 255) {
      c4_i0 = 255;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 27U, 19U, 10U);
    }

    CV_SATURATION_EVAL(5, 6, 0, 0, c4_covSaturation);
  }

  chartInstance->c4_counter2 = (uint8_T)c4_i0;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c4_counter2, 1U);
  c4_i1 = c4__s32_add__(chartInstance, (int32_T)chartInstance->c4_counter3, 1,
                        27U, 32, 10);
  c4_b_covSaturation = false;
  if (c4_i1 < 0) {
    c4_b_covSaturation = true;
    c4_i1 = 0;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 27U, 32U, 10U);
  } else {
    if (c4_i1 > 255) {
      c4_i1 = 255;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 27U, 32U, 10U);
    }

    CV_SATURATION_EVAL(5, 6, 1, 0, c4_b_covSaturation);
  }

  chartInstance->c4_counter3 = (uint8_T)c4_i1;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c4_counter3, 2U);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
}

static void mdl_start_c4_GCU_Model_genCode(SFc4_GCU_Model_genCodeInstanceStruct *
  chartInstance)
{
  c4_init_sf_message_store_memory(chartInstance);
  sim_mode_is_external(chartInstance->S);
}

static void initSimStructsc4_GCU_Model_genCode
  (SFc4_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)(c4_machineNumber);
  (void)(c4_chartNumber);
  (void)(c4_instanceNumber);
}

const mxArray *sf_c4_GCU_Model_genCode_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc4_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_emlrt_marshallIn(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i2;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i2, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i2;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc4_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent), &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  uint16_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc4_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(uint16_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static uint16_T c4_b_emlrt_marshallIn(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c4_b_gcu_traction_limiter_loil_efi_id, const
  char_T *c4_identifier)
{
  uint16_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_gcu_traction_limiter_loil_efi_id), &c4_thisId);
  sf_mex_destroy(&c4_b_gcu_traction_limiter_loil_efi_id);
  return c4_y;
}

static uint16_T c4_c_emlrt_marshallIn(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint16_T c4_y;
  uint16_T c4_u0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 5, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_gcu_traction_limiter_loil_efi_id;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  uint16_T c4_y;
  SFc4_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc4_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c4_b_gcu_traction_limiter_loil_efi_id = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_gcu_traction_limiter_loil_efi_id), &c4_thisId);
  sf_mex_destroy(&c4_b_gcu_traction_limiter_loil_efi_id);
  *(uint16_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  uint8_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc4_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(uint8_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static uint8_T c4_d_emlrt_marshallIn(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c4_b_counter3, const char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_counter3),
    &c4_thisId);
  sf_mex_destroy(&c4_b_counter3);
  return c4_y;
}

static uint8_T c4_e_emlrt_marshallIn(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u1;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u1, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u1;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_counter3;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  uint8_T c4_y;
  SFc4_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc4_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c4_b_counter3 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_counter3),
    &c4_thisId);
  sf_mex_destroy(&c4_b_counter3);
  *(uint8_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_f_emlrt_marshallIn(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c4_b_setSimStateSideEffectsInfo, const char_T
  *c4_identifier)
{
  const mxArray *c4_y = NULL;
  emlrtMsgIdentifier c4_thisId;
  c4_y = NULL;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  sf_mex_assign(&c4_y, c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_setSimStateSideEffectsInfo), &c4_thisId), false);
  sf_mex_destroy(&c4_b_setSimStateSideEffectsInfo);
  return c4_y;
}

static const mxArray *c4_g_emlrt_marshallIn(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  const mxArray *c4_y = NULL;
  (void)chartInstance;
  (void)c4_parentId;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_duplicatearraysafe(&c4_u), false);
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static const mxArray *sf_get_hover_data_for_msg
  (SFc4_GCU_Model_genCodeInstanceStruct *chartInstance, int32_T c4_ssid)
{
  (void)chartInstance;
  (void)c4_ssid;
  return NULL;
}

static void c4_init_sf_message_store_memory(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static int32_T c4__s32_add__(SFc4_GCU_Model_genCodeInstanceStruct *chartInstance,
  int32_T c4_b, int32_T c4_c, uint32_T c4_ssid_src_loc, int32_T
  c4_offset_src_loc, int32_T c4_length_src_loc)
{
  int32_T c4_a;
  (void)chartInstance;
  c4_a = c4_b + c4_c;
  if (((c4_a ^ c4_b) & (c4_a ^ c4_c)) < 0) {
    _SFD_OVERFLOW_DETECTION(SFDB_OVERFLOW, c4_ssid_src_loc, c4_offset_src_loc,
      c4_length_src_loc);
  }

  return c4_a;
}

static void init_dsm_address_info(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc4_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  chartInstance->c4_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c4_gcu_traction_limiter_loil_efi_id = (uint16_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c4_gcu_clutch_mode_map_sw_id = (uint16_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c4_gcu_traction_limiter_autog_acc_sw_id = (uint16_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 3);
  chartInstance->c4_gcu_debug_1_id = (uint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c4_gcu_debug_2_id = (uint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
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

void sf_c4_GCU_Model_genCode_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2244161985U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3048791414U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(120317952U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1472860399U);
}

mxArray* sf_c4_GCU_Model_genCode_get_post_codegen_info(void);
mxArray *sf_c4_GCU_Model_genCode_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("MtlUQhpwbIOQ6yVjy2E9DC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c4_GCU_Model_genCode_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_GCU_Model_genCode_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_GCU_Model_genCode_jit_fallback_info(void)
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

mxArray *sf_c4_GCU_Model_genCode_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c4_GCU_Model_genCode_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c4_GCU_Model_genCode(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x9'type','srcId','name','auxInfo'{{M[1],M[4],T\"gcu_clutch_mode_map_sw_id\",},{M[1],M[6],T\"gcu_debug_1_id\",},{M[1],M[7],T\"gcu_debug_2_id\",},{M[1],M[5],T\"gcu_traction_limiter_autog_acc_sw_id\",},{M[1],M[3],T\"gcu_traction_limiter_loil_efi_id\",},{M[3],M[19],T\"counter1\",},{M[3],M[20],T\"counter2\",},{M[3],M[11],T\"counter3\",},{M[8],M[0],T\"is_active_c4_GCU_Model_genCode\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 9, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_GCU_Model_genCode_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc4_GCU_Model_genCodeInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_GCU_Model_genCodeInstanceStruct *chartInstance =
      (SFc4_GCU_Model_genCodeInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _GCU_Model_genCodeMachineNumber_,
           4,
           0,
           9,
           0,
           8,
           3,
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
            3,
            3,
            3);
          _SFD_SET_DATA_PROPS(0,0,0,0,"counter1");
          _SFD_SET_DATA_PROPS(1,0,0,0,"counter2");
          _SFD_SET_DATA_PROPS(2,0,0,0,"counter3");
          _SFD_SET_DATA_PROPS(3,2,0,1,"gcu_traction_limiter_loil_efi_id");
          _SFD_SET_DATA_PROPS(4,2,0,1,"gcu_clutch_mode_map_sw_id");
          _SFD_SET_DATA_PROPS(5,2,0,1,"gcu_traction_limiter_autog_acc_sw_id");
          _SFD_SET_DATA_PROPS(6,2,0,1,"gcu_debug_1_id");
          _SFD_SET_DATA_PROPS(7,2,0,1,"gcu_debug_2_id");
          _SFD_EVENT_SCOPE(0,2);
          _SFD_EVENT_SCOPE(1,2);
          _SFD_EVENT_SCOPE(2,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 16 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 16 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 5 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(1,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 15 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(4,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 15 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 5 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(4,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartSaturateMap[] = { 19, 32 };

          static unsigned int sEndSaturateMap[] = { 29, 42 };

          _SFD_CV_INIT_TRANSITION_SATURATION(6,2,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)c4_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)c4_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)c4_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
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
    SFc4_GCU_Model_genCodeInstanceStruct *chartInstance =
      (SFc4_GCU_Model_genCodeInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)
          chartInstance->c4_gcu_traction_limiter_loil_efi_id);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)
          chartInstance->c4_gcu_clutch_mode_map_sw_id);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)
          chartInstance->c4_gcu_traction_limiter_autog_acc_sw_id);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)chartInstance->c4_gcu_debug_1_id);
        _SFD_SET_DATA_VALUE_PTR(7U, (void *)chartInstance->c4_gcu_debug_2_id);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)&chartInstance->c4_counter3);
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)&chartInstance->c4_counter1);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)&chartInstance->c4_counter2);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "souaVfS7EeeIE1tFQdFJzVH";
}

static void sf_opaque_initialize_c4_GCU_Model_genCode(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_GCU_Model_genCode((SFc4_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar);
  initialize_c4_GCU_Model_genCode((SFc4_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_GCU_Model_genCode(void *chartInstanceVar)
{
  enable_c4_GCU_Model_genCode((SFc4_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c4_GCU_Model_genCode(void *chartInstanceVar)
{
  disable_c4_GCU_Model_genCode((SFc4_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_GCU_Model_genCode(void *chartInstanceVar)
{
  sf_gateway_c4_GCU_Model_genCode((SFc4_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_GCU_Model_genCode(SimStruct* S)
{
  return get_sim_state_c4_GCU_Model_genCode
    ((SFc4_GCU_Model_genCodeInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_GCU_Model_genCode(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c4_GCU_Model_genCode((SFc4_GCU_Model_genCodeInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c4_GCU_Model_genCode(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_GCU_Model_genCodeInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_GCU_Model_genCode_optimization_info();
    }

    finalize_c4_GCU_Model_genCode((SFc4_GCU_Model_genCodeInstanceStruct*)
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
  initSimStructsc4_GCU_Model_genCode((SFc4_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_GCU_Model_genCode(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_GCU_Model_genCode((SFc4_GCU_Model_genCodeInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c4_GCU_Model_genCode(SimStruct *S)
{
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_GCU_Model_genCode_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetSupportedForRowMajorCodeGen(S, 1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,4,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 4);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,4);
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,4,3);
    if (chartIsInlinable) {
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,5);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=5; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2797294994U));
  ssSetChecksum1(S,(3488441249U));
  ssSetChecksum2(S,(16290395U));
  ssSetChecksum3(S,(2678580367U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_GCU_Model_genCode(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c4_GCU_Model_genCode(SimStruct *S)
{
  SFc4_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc4_GCU_Model_genCodeInstanceStruct *)utMalloc(sizeof
    (SFc4_GCU_Model_genCodeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc4_GCU_Model_genCodeInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_GCU_Model_genCode;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_GCU_Model_genCode;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_GCU_Model_genCode;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_GCU_Model_genCode;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_GCU_Model_genCode;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_GCU_Model_genCode;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_GCU_Model_genCode;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_GCU_Model_genCode;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_GCU_Model_genCode;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_GCU_Model_genCode;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_GCU_Model_genCode;
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
  mdl_start_c4_GCU_Model_genCode(chartInstance);
}

void c4_GCU_Model_genCode_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_GCU_Model_genCode(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_GCU_Model_genCode(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_GCU_Model_genCode(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_GCU_Model_genCode_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
