/* Include files */

#include "GCU_Model_genCode_sfun.h"
#include "c2_GCU_Model_genCode.h"
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
#define c2_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c2_const_STOP_COM              ((uint16_T)0U)
#define c2_const_GEAR_COMMAND_NEUTRAL_DOWN ((uint16_T)100U)
#define c2_const_GEAR_COMMAND_NEUTRAL_UP ((uint16_T)50U)
#define c2_const_GEAR_COMMAND_DOWN     ((uint16_T)200U)
#define c2_const_ACC_CLUTCH_NOISE_LEVEL ((uint8_T)30U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c2_GCU_Model_genCode(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void initialize_params_c2_GCU_Model_genCode
  (SFc2_GCU_Model_genCodeInstanceStruct *chartInstance);
static void enable_c2_GCU_Model_genCode(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void disable_c2_GCU_Model_genCode(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_GCU_Model_genCode
  (SFc2_GCU_Model_genCodeInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_GCU_Model_genCode
  (SFc2_GCU_Model_genCodeInstanceStruct *chartInstance);
static void set_sim_state_c2_GCU_Model_genCode
  (SFc2_GCU_Model_genCodeInstanceStruct *chartInstance, const mxArray *c2_st);
static void c2_set_sim_state_side_effects_c2_GCU_Model_genCode
  (SFc2_GCU_Model_genCodeInstanceStruct *chartInstance);
static void finalize_c2_GCU_Model_genCode(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void sf_gateway_c2_GCU_Model_genCode(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void mdl_start_c2_GCU_Model_genCode(SFc2_GCU_Model_genCodeInstanceStruct *
  chartInstance);
static void c2_chartstep_c2_GCU_Model_genCode
  (SFc2_GCU_Model_genCodeInstanceStruct *chartInstance);
static void initSimStructsc2_GCU_Model_genCode
  (SFc2_GCU_Model_genCodeInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static void c2_sendStartEngCommand(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void c2_sendClutchCommand(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, uint16_T c2_com);
static void c2_sendAccCommand(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, uint16_T c2_com);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static int32_T c2_emlrt_marshallIn(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_b_emlrt_marshallIn(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c2_b_out, const char_T *c2_identifier);
static real_T c2_c_emlrt_marshallIn(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint16_T c2_d_emlrt_marshallIn(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c2_b_currGear, const char_T *c2_identifier);
static uint16_T c2_e_emlrt_marshallIn(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_f_emlrt_marshallIn(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c2_b_shiftCommand, const char_T *c2_identifier,
  uint16_T c2_y[2]);
static void c2_g_emlrt_marshallIn(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  uint16_T c2_y[2]);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static uint8_T c2_h_emlrt_marshallIn(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c2_b_startEngCommand, const char_T
  *c2_identifier);
static uint8_T c2_i_emlrt_marshallIn(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_j_emlrt_marshallIn(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c2_b_clutchCommand, const char_T *c2_identifier,
  uint8_T c2_y[2]);
static void c2_k_emlrt_marshallIn(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  uint8_T c2_y[2]);
static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_l_emlrt_marshallIn(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c2_b_setSimStateSideEffectsInfo, const char_T
  *c2_identifier);
static const mxArray *c2_m_emlrt_marshallIn(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static const mxArray *sf_get_hover_data_for_msg
  (SFc2_GCU_Model_genCodeInstanceStruct *chartInstance, int32_T c2_ssid);
static void c2_init_sf_message_store_memory(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static uint16_T c2__u16_s32_(SFc2_GCU_Model_genCodeInstanceStruct *chartInstance,
  int32_T c2_b, uint32_T c2_ssid_src_loc, int32_T c2_offset_src_loc, int32_T
  c2_length_src_loc);
static int32_T c2__s32_add__(SFc2_GCU_Model_genCodeInstanceStruct *chartInstance,
  int32_T c2_b, int32_T c2_c, uint32_T c2_ssid_src_loc, int32_T
  c2_offset_src_loc, int32_T c2_length_src_loc);
static void init_dsm_address_info(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_GCU_Model_genCode(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  int32_T c2_i0;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc2_GCU_Model_genCode(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_doSetSimStateSideEffects = 0U;
  chartInstance->c2_setSimStateSideEffectsInfo = NULL;
  chartInstance->c2_is_active_c2_GCU_Model_genCode = 0U;
  chartInstance->c2_clutchTarget = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_clutchTarget, 0U);
  chartInstance->c2_STOP_COM = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_STOP_COM, 23U);
  chartInstance->c2_b_STOP_COM = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_b_STOP_COM, 27U);
  chartInstance->c2_GEAR_COMMAND_NEUTRAL_DOWN = 100U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_GEAR_COMMAND_NEUTRAL_DOWN, 25U);
  chartInstance->c2_GEAR_COMMAND_NEUTRAL_UP = 50U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_GEAR_COMMAND_NEUTRAL_UP, 26U);
  chartInstance->c2_GEAR_COMMAND_DOWN = 200U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_GEAR_COMMAND_DOWN, 24U);
  chartInstance->c2_c_STOP_COM = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_c_STOP_COM, 29U);
  chartInstance->c2_ACC_CLUTCH_NOISE_LEVEL = 30U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_ACC_CLUTCH_NOISE_LEVEL, 28U);
  chartInstance->c2_d_STOP_COM = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_d_STOP_COM, 30U);
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    *chartInstance->c2_out = 0.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c2_out, 7U);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 2) != 0)) {
    *chartInstance->c2_currGear = 0U;
    _SFD_DATA_RANGE_CHECK_MAX((real_T)*chartInstance->c2_currGear, 8U, 5.0, 0U,
      0, 0);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 3) != 0)) {
    *chartInstance->c2_acc_externValue = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_acc_externValue, 9U);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 4) != 0)) {
    *chartInstance->c2_acc_externValues_index = 0U;
    _SFD_DATA_RANGE_CHECK_MAX((real_T)*chartInstance->c2_acc_externValues_index,
      10U, 3.0, 0U, 0, 0);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 5) != 0)) {
    (*chartInstance->c2_shiftCommand)[0] = 0U;
    for (c2_i0 = 0; c2_i0 < 2; c2_i0++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_shiftCommand)[c2_i0],
                            11U);
    }

    (*chartInstance->c2_shiftCommand)[1] = 0U;
    for (c2_i2 = 0; c2_i2 < 2; c2_i2++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_shiftCommand)[c2_i2],
                            11U);
    }
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 6) != 0)) {
    *chartInstance->c2_startEngCommand = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_startEngCommand, 12U);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 7) != 0)) {
    (*chartInstance->c2_accCommand)[0] = 0U;
    for (c2_i1 = 0; c2_i1 < 2; c2_i1++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_accCommand)[c2_i1], 13U);
    }

    (*chartInstance->c2_accCommand)[1] = 0U;
    for (c2_i4 = 0; c2_i4 < 2; c2_i4++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_accCommand)[c2_i4], 13U);
    }
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 8) != 0)) {
    *chartInstance->c2_tractionTarget = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_tractionTarget, 14U);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 9) != 0)) {
    (*chartInstance->c2_clutchCommand)[0] = 0U;
    for (c2_i3 = 0; c2_i3 < 2; c2_i3++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_clutchCommand)[c2_i3],
                            15U);
    }

    (*chartInstance->c2_clutchCommand)[1] = 0U;
    for (c2_i6 = 0; c2_i6 < 2; c2_i6++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_clutchCommand)[c2_i6],
                            15U);
    }
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 10) != 0)) {
    (*chartInstance->c2_modeCommand)[0] = 0U;
    for (c2_i5 = 0; c2_i5 < 2; c2_i5++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_modeCommand)[c2_i5], 16U);
    }

    (*chartInstance->c2_modeCommand)[1] = 0U;
    for (c2_i7 = 0; c2_i7 < 2; c2_i7++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_modeCommand)[c2_i7], 16U);
    }
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 11) != 0)) {
    *chartInstance->c2_accParametersValue = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_accParametersValue, 17U);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 12) != 0)) {
    *chartInstance->c2_accParametersIndex = 0U;
    _SFD_DATA_RANGE_CHECK_MAX((real_T)*chartInstance->c2_accParametersIndex, 18U,
      3.0, 0U, 0, 0);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 13) != 0)) {
    *chartInstance->c2_timingsValue = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_timingsValue, 19U);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 14) != 0)) {
    *chartInstance->c2_timingsIndex = 0U;
    _SFD_DATA_RANGE_CHECK_MAX((real_T)*chartInstance->c2_timingsIndex, 20U, 3.0,
      0U, 0, 0);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 15) != 0)) {
    *chartInstance->c2_mapTarget = 0U;
    _SFD_DATA_RANGE_CHECK_MAX((real_T)*chartInstance->c2_mapTarget, 21U, 5.0, 0U,
      0, 0);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 16) != 0)) {
    *chartInstance->c2_rpmLimiterTarget = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_rpmLimiterTarget, 22U);
  }
}

static void initialize_params_c2_GCU_Model_genCode
  (SFc2_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_GCU_Model_genCode(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_enable(chartInstance->S, 0, "Efi_setRPMLimiter", 0);
  sf_call_output_fcn_enable(chartInstance->S, 1, "Efi_unsetRPMLimiter", 0);
  sf_call_output_fcn_enable(chartInstance->S, 2, "aac_updateExternValue", 0);
}

static void disable_c2_GCU_Model_genCode(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_disable(chartInstance->S, 0, "Efi_setRPMLimiter", 0);
  sf_call_output_fcn_disable(chartInstance->S, 1, "Efi_unsetRPMLimiter", 0);
  sf_call_output_fcn_disable(chartInstance->S, 2, "aac_updateExternValue", 0);
}

static void c2_update_debugger_state_c2_GCU_Model_genCode
  (SFc2_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_GCU_Model_genCode
  (SFc2_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  const mxArray *c2_b_y = NULL;
  uint16_T c2_hoistedGlobal;
  const mxArray *c2_c_y = NULL;
  uint16_T c2_b_hoistedGlobal;
  const mxArray *c2_d_y = NULL;
  uint16_T c2_c_hoistedGlobal;
  const mxArray *c2_e_y = NULL;
  uint16_T c2_d_hoistedGlobal;
  const mxArray *c2_f_y = NULL;
  const mxArray *c2_g_y = NULL;
  uint16_T c2_e_hoistedGlobal;
  const mxArray *c2_h_y = NULL;
  uint16_T c2_f_hoistedGlobal;
  const mxArray *c2_i_y = NULL;
  const mxArray *c2_j_y = NULL;
  real_T c2_g_hoistedGlobal;
  const mxArray *c2_k_y = NULL;
  uint16_T c2_h_hoistedGlobal;
  const mxArray *c2_l_y = NULL;
  const mxArray *c2_m_y = NULL;
  uint8_T c2_i_hoistedGlobal;
  const mxArray *c2_n_y = NULL;
  uint16_T c2_j_hoistedGlobal;
  const mxArray *c2_o_y = NULL;
  uint16_T c2_k_hoistedGlobal;
  const mxArray *c2_p_y = NULL;
  uint16_T c2_l_hoistedGlobal;
  const mxArray *c2_q_y = NULL;
  uint8_T c2_m_hoistedGlobal;
  const mxArray *c2_r_y = NULL;
  uint8_T c2_n_hoistedGlobal;
  const mxArray *c2_s_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(18, 1), false);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", *chartInstance->c2_accCommand, 5, 0U,
    1U, 0U, 2, 1, 2), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = *chartInstance->c2_accParametersIndex;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_hoistedGlobal, 5, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_b_hoistedGlobal = *chartInstance->c2_accParametersValue;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_b_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_c_hoistedGlobal = *chartInstance->c2_acc_externValue;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_c_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_d_hoistedGlobal = *chartInstance->c2_acc_externValues_index;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_d_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", *chartInstance->c2_clutchCommand, 3,
    0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_setcell(c2_y, 5, c2_g_y);
  c2_e_hoistedGlobal = *chartInstance->c2_currGear;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_e_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 6, c2_h_y);
  c2_f_hoistedGlobal = *chartInstance->c2_mapTarget;
  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_f_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 7, c2_i_y);
  c2_j_y = NULL;
  sf_mex_assign(&c2_j_y, sf_mex_create("y", *chartInstance->c2_modeCommand, 5,
    0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_setcell(c2_y, 8, c2_j_y);
  c2_g_hoistedGlobal = *chartInstance->c2_out;
  c2_k_y = NULL;
  sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_g_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 9, c2_k_y);
  c2_h_hoistedGlobal = *chartInstance->c2_rpmLimiterTarget;
  c2_l_y = NULL;
  sf_mex_assign(&c2_l_y, sf_mex_create("y", &c2_h_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 10, c2_l_y);
  c2_m_y = NULL;
  sf_mex_assign(&c2_m_y, sf_mex_create("y", *chartInstance->c2_shiftCommand, 5,
    0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_setcell(c2_y, 11, c2_m_y);
  c2_i_hoistedGlobal = *chartInstance->c2_startEngCommand;
  c2_n_y = NULL;
  sf_mex_assign(&c2_n_y, sf_mex_create("y", &c2_i_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 12, c2_n_y);
  c2_j_hoistedGlobal = *chartInstance->c2_timingsIndex;
  c2_o_y = NULL;
  sf_mex_assign(&c2_o_y, sf_mex_create("y", &c2_j_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 13, c2_o_y);
  c2_k_hoistedGlobal = *chartInstance->c2_timingsValue;
  c2_p_y = NULL;
  sf_mex_assign(&c2_p_y, sf_mex_create("y", &c2_k_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 14, c2_p_y);
  c2_l_hoistedGlobal = *chartInstance->c2_tractionTarget;
  c2_q_y = NULL;
  sf_mex_assign(&c2_q_y, sf_mex_create("y", &c2_l_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 15, c2_q_y);
  c2_m_hoistedGlobal = chartInstance->c2_clutchTarget;
  c2_r_y = NULL;
  sf_mex_assign(&c2_r_y, sf_mex_create("y", &c2_m_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 16, c2_r_y);
  c2_n_hoistedGlobal = chartInstance->c2_is_active_c2_GCU_Model_genCode;
  c2_s_y = NULL;
  sf_mex_assign(&c2_s_y, sf_mex_create("y", &c2_n_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 17, c2_s_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_GCU_Model_genCode
  (SFc2_GCU_Model_genCodeInstanceStruct *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  uint16_T c2_uv0[2];
  int32_T c2_i8;
  uint8_T c2_uv1[2];
  int32_T c2_i9;
  uint16_T c2_uv2[2];
  int32_T c2_i10;
  uint16_T c2_uv3[2];
  int32_T c2_i11;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
                        "accCommand", c2_uv0);
  for (c2_i8 = 0; c2_i8 < 2; c2_i8++) {
    (*chartInstance->c2_accCommand)[c2_i8] = c2_uv0[c2_i8];
  }

  *chartInstance->c2_accParametersIndex = c2_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 1)), "accParametersIndex");
  *chartInstance->c2_accParametersValue = c2_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 2)), "accParametersValue");
  *chartInstance->c2_acc_externValue = c2_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 3)), "acc_externValue");
  *chartInstance->c2_acc_externValues_index = c2_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 4)),
     "acc_externValues_index");
  c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 5)),
                        "clutchCommand", c2_uv1);
  for (c2_i9 = 0; c2_i9 < 2; c2_i9++) {
    (*chartInstance->c2_clutchCommand)[c2_i9] = c2_uv1[c2_i9];
  }

  *chartInstance->c2_currGear = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 6)), "currGear");
  *chartInstance->c2_mapTarget = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 7)), "mapTarget");
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 8)),
                        "modeCommand", c2_uv2);
  for (c2_i10 = 0; c2_i10 < 2; c2_i10++) {
    (*chartInstance->c2_modeCommand)[c2_i10] = c2_uv2[c2_i10];
  }

  *chartInstance->c2_out = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 9)), "out");
  *chartInstance->c2_rpmLimiterTarget = c2_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 10)), "rpmLimiterTarget");
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 11)),
                        "shiftCommand", c2_uv3);
  for (c2_i11 = 0; c2_i11 < 2; c2_i11++) {
    (*chartInstance->c2_shiftCommand)[c2_i11] = c2_uv3[c2_i11];
  }

  *chartInstance->c2_startEngCommand = c2_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 12)), "startEngCommand");
  *chartInstance->c2_timingsIndex = c2_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 13)), "timingsIndex");
  *chartInstance->c2_timingsValue = c2_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 14)), "timingsValue");
  *chartInstance->c2_tractionTarget = c2_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 15)), "tractionTarget");
  chartInstance->c2_clutchTarget = c2_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 16)), "clutchTarget");
  chartInstance->c2_is_active_c2_GCU_Model_genCode = c2_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 17)),
     "is_active_c2_GCU_Model_genCode");
  sf_mex_assign(&chartInstance->c2_setSimStateSideEffectsInfo,
                c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 18)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c2_u);
  chartInstance->c2_doSetSimStateSideEffects = 1U;
  c2_update_debugger_state_c2_GCU_Model_genCode(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void c2_set_sim_state_side_effects_c2_GCU_Model_genCode
  (SFc2_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  if (chartInstance->c2_doSetSimStateSideEffects != 0) {
    chartInstance->c2_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c2_GCU_Model_genCode(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c2_setSimStateSideEffectsInfo);
}

static void sf_gateway_c2_GCU_Model_genCode(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  c2_set_sim_state_side_effects_c2_GCU_Model_genCode(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_clutchCurrVal, 6U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_fourthInt, 5U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_thirdInt, 4U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_secondInt, 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_firstInt, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_Id, 1U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_GCU_Model_genCode(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
}

static void mdl_start_c2_GCU_Model_genCode(SFc2_GCU_Model_genCodeInstanceStruct *
  chartInstance)
{
  c2_init_sf_message_store_memory(chartInstance);
  sim_mode_is_external(chartInstance->S);
}

static void c2_chartstep_c2_GCU_Model_genCode
  (SFc2_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  boolean_T c2_b_out;
  boolean_T c2_c_out;
  boolean_T c2_d_out;
  boolean_T c2_e_out;
  uint16_T c2_hoistedGlobal;
  uint16_T c2_com;
  boolean_T c2_f_out;
  uint16_T c2_u0;
  boolean_T c2_g_out;
  uint16_T c2_u1;
  boolean_T c2_covSaturation;
  int32_T c2_i12;
  boolean_T c2_b_covSaturation;
  boolean_T c2_h_out;
  boolean_T c2_i_out;
  int32_T c2_i13;
  boolean_T c2_j_out;
  boolean_T c2_c_covSaturation;
  uint16_T c2_b_hoistedGlobal;
  int32_T c2_i14;
  boolean_T c2_k_out;
  int32_T c2_i15;
  uint16_T c2_b_com;
  boolean_T c2_d_covSaturation;
  uint16_T c2_u2;
  int32_T c2_i16;
  uint16_T c2_u3;
  int32_T c2_i17;
  boolean_T c2_l_out;
  uint16_T c2_u4;
  int32_T c2_i18;
  boolean_T c2_e_covSaturation;
  int32_T c2_i19;
  boolean_T c2_m_out;
  uint16_T c2_u5;
  int32_T c2_i20;
  boolean_T c2_temp;
  uint16_T c2_u6;
  int32_T c2_i21;
  boolean_T c2_b_temp;
  uint16_T c2_u7;
  boolean_T c2_n_out;
  boolean_T c2_o_out;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, chartInstance->c2_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 36U, chartInstance->c2_sfEvent);
  c2_b_out = (CV_TRANSITION_EVAL(36U, (int32_T)_SFD_CCP_CALL(5U, 36U, 0,
    (*chartInstance->c2_Id == EFI_GEAR_RPM_TPS_PH2O_ID) != 0U,
    chartInstance->c2_sfEvent)) != 0);
  if (c2_b_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 36U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 49U, chartInstance->c2_sfEvent);
    *chartInstance->c2_currGear = *chartInstance->c2_firstInt;
    _SFD_DATA_RANGE_CHECK_MAX((real_T)*chartInstance->c2_currGear, 8U, 5.0, 500U,
      2, 20);
    *chartInstance->c2_acc_externValues_index = c2__u16_s32_(chartInstance,
      (int32_T)acc_values_RPM, 500U, 50, 6);
    _SFD_DATA_RANGE_CHECK_MAX((real_T)*chartInstance->c2_acc_externValues_index,
      10U, 3.0, 500U, 25, 48);
    *chartInstance->c2_acc_externValue = *chartInstance->c2_secondInt;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_acc_externValue, 9U);
    sf_call_output_fcn_call(chartInstance->S, 2, "aac_updateExternValue", 0);
    *chartInstance->c2_acc_externValues_index = c2__u16_s32_(chartInstance,
      (int32_T)acc_values_TPS, 500U, 163, 6);
    _SFD_DATA_RANGE_CHECK_MAX((real_T)*chartInstance->c2_acc_externValues_index,
      10U, 3.0, 500U, 138, 48);
    *chartInstance->c2_acc_externValue = *chartInstance->c2_thirdInt;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_acc_externValue, 9U);
    sf_call_output_fcn_call(chartInstance->S, 2, "aac_updateExternValue", 0);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 41U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 38U,
                 chartInstance->c2_sfEvent);
    c2_c_out = (CV_TRANSITION_EVAL(38U, (int32_T)_SFD_CCP_CALL(5U, 38U, 0,
      (*chartInstance->c2_Id == SW_FIRE_GCU_ID) != 0U, chartInstance->c2_sfEvent))
                != 0);
    if (c2_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 38U, chartInstance->c2_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 50U, chartInstance->c2_sfEvent);
      c2_sendStartEngCommand(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 37U, chartInstance->c2_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 39U,
                   chartInstance->c2_sfEvent);
      c2_d_out = (CV_TRANSITION_EVAL(39U, (int32_T)_SFD_CCP_CALL(5U, 39U, 0,
        (*chartInstance->c2_Id == SW_GEARSHIFT_ID) != 0U,
        chartInstance->c2_sfEvent)) != 0);
      if (c2_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 39U, chartInstance->c2_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 51U, chartInstance->c2_sfEvent);
        c2_hoistedGlobal = *chartInstance->c2_firstInt;
        c2_com = c2_hoistedGlobal;
        _SFD_DATA_RANGE_CHECK((real_T)c2_com, 31U);
        _SFD_SET_DATA_VALUE_PTR(31U, (void *)&c2_com);
        _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
        _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("com", &c2_com, c2_b_sf_marshallOut,
          c2_c_sf_marshallIn);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U,
                     chartInstance->c2_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                     chartInstance->c2_sfEvent);
        c2_h_out = (CV_TRANSITION_EVAL(14U, (int32_T)_SFD_CCP_CALL(5U, 14U, 0,
          (boolean_T)CV_RELATIONAL_EVAL(5U, 14U, 0, (real_T)
          (*chartInstance->c2_shiftCommand)[0], 255.0, 0, 5U,
          (*chartInstance->c2_shiftCommand)[0] >= 255) != 0U,
          chartInstance->c2_sfEvent)) != 0);
        if (c2_h_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c2_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c2_sfEvent);
          (*chartInstance->c2_shiftCommand)[0] = 0U;
          for (c2_i14 = 0; c2_i14 < 2; c2_i14++) {
            _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_shiftCommand)
                                  [c2_i14], 11U);
          }

          c2_u2 = (*chartInstance->c2_shiftCommand)[0];
          sf_mex_printf("%s =\\n", "shiftCommand[0]");
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11,
                            c2_u2);
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
          c2_i13 = (*chartInstance->c2_shiftCommand)[0] + 1;
          c2_c_covSaturation = false;
          if (c2_i13 < 0) {
            c2_c_covSaturation = true;
            c2_i13 = 0;
            _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 219U, 35U, 1U);
          } else {
            if (c2_i13 > 65535) {
              c2_i13 = 65535;
              _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 219U, 35U, 1U);
            }

            CV_SATURATION_EVAL(5, 15, 0, 0, c2_c_covSaturation);
          }

          (*chartInstance->c2_shiftCommand)[0] = (uint16_T)c2_i13;
          for (c2_i16 = 0; c2_i16 < 2; c2_i16++) {
            _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_shiftCommand)
                                  [c2_i16], 11U);
          }

          c2_u3 = (*chartInstance->c2_shiftCommand)[0];
          sf_mex_printf("%s =\\n", "shiftCommand[0]");
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11,
                            c2_u3);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c2_sfEvent);
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c2_sfEvent);
        (*chartInstance->c2_shiftCommand)[1] = c2_com;
        for (c2_i17 = 0; c2_i17 < 2; c2_i17++) {
          _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_shiftCommand)[c2_i17],
                                11U);
        }

        c2_u4 = (*chartInstance->c2_shiftCommand)[1];
        sf_mex_printf("%s =\\n", "shiftCommand[1]");
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11, c2_u4);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U,
                     chartInstance->c2_sfEvent);
        c2_m_out = (CV_TRANSITION_EVAL(19U, (int32_T)_SFD_CCP_CALL(5U, 19U, 0,
          (boolean_T)CV_RELATIONAL_EVAL(5U, 19U, 0, (real_T)
          *chartInstance->c2_clutchCurrVal, 100.0, 0, 1U,
          *chartInstance->c2_clutchCurrVal != 100) != 0U,
          chartInstance->c2_sfEvent)) != 0);
        if (c2_m_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c2_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c2_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 26U,
                       chartInstance->c2_sfEvent);
          c2_temp = _SFD_CCP_CALL(5U, 26U, 0, (boolean_T)CV_RELATIONAL_EVAL(5U,
            26U, 0, (real_T)c2_com, (real_T)c2_const_GEAR_COMMAND_NEUTRAL_UP, 0,
            0U, c2_com == c2_const_GEAR_COMMAND_NEUTRAL_UP) != 0U,
            chartInstance->c2_sfEvent);
          if (!c2_temp) {
            c2_temp = _SFD_CCP_CALL(5U, 26U, 1, (boolean_T)CV_RELATIONAL_EVAL(5U,
              26U, 1, (real_T)c2_com, (real_T)c2_const_GEAR_COMMAND_NEUTRAL_DOWN,
              0, 0U, c2_com == c2_const_GEAR_COMMAND_NEUTRAL_DOWN) != 0U,
              chartInstance->c2_sfEvent);
          }

          c2_b_temp = c2_temp;
          if (!c2_b_temp) {
            c2_b_temp = _SFD_CCP_CALL(5U, 26U, 2, (boolean_T)CV_RELATIONAL_EVAL
              (5U, 26U, 2, (real_T)c2_com, (real_T)c2_const_GEAR_COMMAND_DOWN, 0,
               0U, c2_com == c2_const_GEAR_COMMAND_DOWN) != 0U,
              chartInstance->c2_sfEvent);
          }

          c2_n_out = (CV_TRANSITION_EVAL(26U, (int32_T)c2_b_temp) != 0);
          if (c2_n_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, chartInstance->c2_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, chartInstance->c2_sfEvent);
            c2_sendAccCommand(chartInstance, c2_const_STOP_COM);
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, chartInstance->c2_sfEvent);
          }
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c2_sfEvent);
        }

        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
        _SFD_UNSET_DATA_VALUE_PTR(31U);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c2_sfEvent);
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 40U, chartInstance->c2_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 47U,
                     chartInstance->c2_sfEvent);
        c2_e_out = (CV_TRANSITION_EVAL(47U, (int32_T)_SFD_CCP_CALL(5U, 47U, 0, (*
          chartInstance->c2_Id == EFI_TRACTION_CONTROL_ID) != 0U,
          chartInstance->c2_sfEvent)) != 0);
        if (c2_e_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 47U, chartInstance->c2_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 52U, chartInstance->c2_sfEvent);
          *chartInstance->c2_acc_externValues_index = c2__u16_s32_(chartInstance,
            (int32_T)acc_values_WHEEL_SPEED, 510U, 27, 6);
          _SFD_DATA_RANGE_CHECK_MAX((real_T)
            *chartInstance->c2_acc_externValues_index, 10U, 3.0, 510U, 2, 56);
          c2_u0 = *chartInstance->c2_acc_externValues_index;
          sf_mex_printf("%s =\\n", "acc_externValues_index");
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11,
                            c2_u0);
          c2_i12 = (int32_T)((uint32_T)*chartInstance->c2_firstInt / 10U);
          c2_b_covSaturation = false;
          if (c2_i12 < 0) {
            c2_b_covSaturation = true;
            c2_i12 = 0;
            _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 510U, 86U, 1U);
          } else {
            if (c2_i12 > 65535) {
              c2_i12 = 65535;
              _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 510U, 86U, 1U);
            }

            CV_SATURATION_EVAL(5, 52, 0, 0, c2_b_covSaturation);
          }

          *chartInstance->c2_acc_externValue = (uint16_T)c2_i12;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_acc_externValue, 9U);
          sf_call_output_fcn_call(chartInstance->S, 2, "aac_updateExternValue",
            0);
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 46U, chartInstance->c2_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 42U,
                       chartInstance->c2_sfEvent);
          c2_f_out = (CV_TRANSITION_EVAL(42U, (int32_T)_SFD_CCP_CALL(5U, 42U, 0,
            (*chartInstance->c2_Id == SW_CLUTCH_MODE_MAP_GCU_ID) != 0U,
            chartInstance->c2_sfEvent)) != 0);
          if (c2_f_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 42U, chartInstance->c2_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 53U, chartInstance->c2_sfEvent);
            c2_u1 = *chartInstance->c2_firstInt;
            c2_covSaturation = false;
            if (c2_u1 > 255) {
              c2_covSaturation = true;
              c2_u1 = 255U;
              _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 513U, 16U, 8U);
            }

            CV_SATURATION_EVAL(5, 53, 0, 0, c2_covSaturation);
            chartInstance->c2_clutchTarget = (uint8_T)c2_u1;
            _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_clutchTarget, 0U);
            c2_b_hoistedGlobal = *chartInstance->c2_secondInt;
            c2_b_com = c2_b_hoistedGlobal;
            _SFD_DATA_RANGE_CHECK((real_T)c2_b_com, 34U);
            _SFD_SET_DATA_VALUE_PTR(34U, (void *)&c2_b_com);
            _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 10U, chartInstance->c2_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
            _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("com", &c2_b_com,
              c2_b_sf_marshallOut, c2_c_sf_marshallIn);
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                         chartInstance->c2_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, chartInstance->c2_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 30U,
                         chartInstance->c2_sfEvent);
            c2_l_out = (CV_TRANSITION_EVAL(30U, (int32_T)_SFD_CCP_CALL(5U, 30U,
              0, (boolean_T)CV_RELATIONAL_EVAL(5U, 30U, 0, (real_T)
              (*chartInstance->c2_modeCommand)[0], 255.0, 0, 5U,
              (*chartInstance->c2_modeCommand)[0] >= 255) != 0U,
              chartInstance->c2_sfEvent)) != 0);
            if (c2_l_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c2_sfEvent);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, chartInstance->c2_sfEvent);
              (*chartInstance->c2_modeCommand)[0] = 0U;
              for (c2_i19 = 0; c2_i19 < 2; c2_i19++) {
                _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_modeCommand)
                                      [c2_i19], 16U);
              }

              c2_u5 = (*chartInstance->c2_modeCommand)[0];
              sf_mex_printf("%s =\\n", "modeCommand[0]");
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11,
                                c2_u5);
            } else {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, chartInstance->c2_sfEvent);
              c2_i18 = (*chartInstance->c2_modeCommand)[0] + 1;
              c2_e_covSaturation = false;
              if (c2_i18 < 0) {
                c2_e_covSaturation = true;
                c2_i18 = 0;
                _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 332U, 33U, 1U);
              } else {
                if (c2_i18 > 65535) {
                  c2_i18 = 65535;
                  _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 332U, 33U, 1U);
                }

                CV_SATURATION_EVAL(5, 31, 0, 0, c2_e_covSaturation);
              }

              (*chartInstance->c2_modeCommand)[0] = (uint16_T)c2_i18;
              for (c2_i20 = 0; c2_i20 < 2; c2_i20++) {
                _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_modeCommand)
                                      [c2_i20], 16U);
              }

              c2_u6 = (*chartInstance->c2_modeCommand)[0];
              sf_mex_printf("%s =\\n", "modeCommand[0]");
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11,
                                c2_u6);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U, chartInstance->c2_sfEvent);
            }

            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, chartInstance->c2_sfEvent);
            (*chartInstance->c2_modeCommand)[1] = c2_b_com;
            for (c2_i21 = 0; c2_i21 < 2; c2_i21++) {
              _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_modeCommand)
                                    [c2_i21], 16U);
            }

            c2_u7 = (*chartInstance->c2_modeCommand)[1];
            sf_mex_printf("%s =\\n", "modeCommand[1]");
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11,
                              c2_u7);
            _SFD_SYMBOL_SCOPE_POP();
            _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 10U, chartInstance->c2_sfEvent);
            _SFD_UNSET_DATA_VALUE_PTR(34U);
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U,
                         chartInstance->c2_sfEvent);
            *chartInstance->c2_mapTarget = *chartInstance->c2_thirdInt;
            _SFD_DATA_RANGE_CHECK_MAX((real_T)*chartInstance->c2_mapTarget, 21U,
              5.0, 513U, 56, 21);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 57U,
                         chartInstance->c2_sfEvent);
            c2_o_out = (CV_TRANSITION_EVAL(57U, (int32_T)_SFD_CCP_CALL(5U, 57U,
              0, (boolean_T)CV_RELATIONAL_EVAL(5U, 57U, 0, (real_T)
              chartInstance->c2_clutchTarget, (real_T)
              c2_const_ACC_CLUTCH_NOISE_LEVEL, 0, 4U,
              chartInstance->c2_clutchTarget > c2_const_ACC_CLUTCH_NOISE_LEVEL)
              != 0U, chartInstance->c2_sfEvent)) != 0);
            if (c2_o_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 57U, chartInstance->c2_sfEvent);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 55U, chartInstance->c2_sfEvent);
              c2_sendAccCommand(chartInstance, c2_const_STOP_COM);
            } else {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 59U, chartInstance->c2_sfEvent);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 56U, chartInstance->c2_sfEvent);
            }

            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 58U, chartInstance->c2_sfEvent);
            c2_sendClutchCommand(chartInstance, (uint16_T)
                                 chartInstance->c2_clutchTarget);
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 44U, chartInstance->c2_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 45U,
                         chartInstance->c2_sfEvent);
            c2_g_out = (CV_TRANSITION_EVAL(45U, (int32_T)_SFD_CCP_CALL(5U, 45U,
              0, (*chartInstance->c2_Id == SW_OK_BUTTON_GCU_ID) != 0U,
              chartInstance->c2_sfEvent)) != 0);
            if (c2_g_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 45U, chartInstance->c2_sfEvent);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 60U, chartInstance->c2_sfEvent);
              c2_sendAccCommand(chartInstance, *chartInstance->c2_firstInt);
              _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 63U,
                           chartInstance->c2_sfEvent);
              c2_j_out = (CV_TRANSITION_EVAL(63U, (int32_T)_SFD_CCP_CALL(5U, 63U,
                0, ((*chartInstance->c2_accCommand)[1] == ACC_OFF) != 0U,
                chartInstance->c2_sfEvent)) != 0);
              if (c2_j_out) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 63U,
                             chartInstance->c2_sfEvent);
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 61U,
                             chartInstance->c2_sfEvent);
                c2_sendClutchCommand(chartInstance, 0U);
              } else {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 62U,
                             chartInstance->c2_sfEvent);
              }
            } else {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 48U, chartInstance->c2_sfEvent);
              _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 43U,
                           chartInstance->c2_sfEvent);
              c2_i_out = (CV_TRANSITION_EVAL(43U, (int32_T)_SFD_CCP_CALL(5U, 43U,
                0, (*chartInstance->c2_Id == SW_TRACTION_LIMITER_GCU_ID) != 0U,
                chartInstance->c2_sfEvent)) != 0);
              if (c2_i_out) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 43U,
                             chartInstance->c2_sfEvent);
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 54U,
                             chartInstance->c2_sfEvent);
                c2_i15 = *chartInstance->c2_firstInt * 100;
                c2_d_covSaturation = false;
                if (c2_i15 < 0) {
                  c2_d_covSaturation = true;
                  c2_i15 = 0;
                  _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 517U, 35U, 1U);
                } else {
                  if (c2_i15 > 65535) {
                    c2_i15 = 65535;
                    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 517U, 35U, 1U);
                  }

                  CV_SATURATION_EVAL(5, 54, 0, 0, c2_d_covSaturation);
                }

                *chartInstance->c2_tractionTarget = (uint16_T)c2_i15;
                _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_tractionTarget,
                                      14U);
              } else {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 64U,
                             chartInstance->c2_sfEvent);
                _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 65U,
                             chartInstance->c2_sfEvent);
                c2_k_out = (CV_TRANSITION_EVAL(65U, (int32_T)_SFD_CCP_CALL(5U,
                  65U, 0, (*chartInstance->c2_Id == DCU_AUTOGEARSHIFT_GCU_ID) !=
                  0U, chartInstance->c2_sfEvent)) != 0);
                if (c2_k_out) {
                  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 65U,
                               chartInstance->c2_sfEvent);
                  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 66U,
                               chartInstance->c2_sfEvent);
                } else {
                  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 67U,
                               chartInstance->c2_sfEvent);
                }
              }
            }
          }
        }
      }
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_GCU_Model_genCode
  (SFc2_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)(c2_machineNumber);
  (void)(c2_chartNumber);
  (void)(c2_instanceNumber);
}

const mxArray *sf_c2_GCU_Model_genCode_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static void c2_sendStartEngCommand(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  boolean_T c2_b_out;
  int32_T c2_i22;
  boolean_T c2_covSaturation;
  uint8_T c2_u8;
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U, chartInstance->c2_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c2_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U, chartInstance->c2_sfEvent);
  c2_b_out = (CV_TRANSITION_EVAL(23U, (int32_T)_SFD_CCP_CALL(5U, 23U, 0,
    (boolean_T)CV_RELATIONAL_EVAL(5U, 23U, 0, (real_T)
    *chartInstance->c2_startEngCommand, 255.0, 0, 5U,
    *chartInstance->c2_startEngCommand >= 255) != 0U, chartInstance->c2_sfEvent))
              != 0);
  if (c2_b_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c2_sfEvent);
    *chartInstance->c2_startEngCommand = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_startEngCommand, 12U);
    c2_u8 = *chartInstance->c2_startEngCommand;
    sf_mex_printf("%s =\\n", "startEngCommand");
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 9, c2_u8);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c2_sfEvent);
    c2_i22 = c2__s32_add__(chartInstance, (int32_T)
      *chartInstance->c2_startEngCommand, 1, 290U, 35, 1);
    c2_covSaturation = false;
    if (c2_i22 < 0) {
      c2_covSaturation = true;
      c2_i22 = 0;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 290U, 35U, 1U);
    } else {
      if (c2_i22 > 255) {
        c2_i22 = 255;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 290U, 35U, 1U);
      }

      CV_SATURATION_EVAL(5, 24, 0, 0, c2_covSaturation);
    }

    *chartInstance->c2_startEngCommand = (uint8_T)c2_i22;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_startEngCommand, 12U);
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c2_sfEvent);
}

static void c2_sendClutchCommand(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, uint16_T c2_com)
{
  boolean_T c2_b_out;
  int32_T c2_i23;
  boolean_T c2_covSaturation;
  int32_T c2_i24;
  uint8_T c2_u9;
  int32_T c2_i25;
  uint16_T c2_u10;
  uint8_T c2_u11;
  boolean_T c2_b_covSaturation;
  int32_T c2_i26;
  uint8_T c2_u12;
  _SFD_DATA_RANGE_CHECK((real_T)c2_com, 32U);
  _SFD_SET_DATA_VALUE_PTR(32U, (void *)&c2_com);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("com", &c2_com, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c2_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c2_sfEvent);
  c2_b_out = (CV_TRANSITION_EVAL(8U, (int32_T)_SFD_CCP_CALL(5U, 8U, 0,
    (boolean_T)CV_RELATIONAL_EVAL(5U, 8U, 0, (real_T)
    (*chartInstance->c2_clutchCommand)[0], 255.0, 0, 5U,
    (*chartInstance->c2_clutchCommand)[0] >= 255) != 0U,
    chartInstance->c2_sfEvent)) != 0);
  if (c2_b_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c2_sfEvent);
    (*chartInstance->c2_clutchCommand)[0] = 0U;
    for (c2_i24 = 0; c2_i24 < 2; c2_i24++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_clutchCommand)[c2_i24],
                            15U);
    }

    c2_u9 = (*chartInstance->c2_clutchCommand)[0];
    sf_mex_printf("%s =\\n", "clutchCommand[0]");
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 9, c2_u9);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
    c2_i23 = (*chartInstance->c2_clutchCommand)[0] + 1;
    c2_covSaturation = false;
    if (c2_i23 < 0) {
      c2_covSaturation = true;
      c2_i23 = 0;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 195U, 37U, 1U);
    } else {
      if (c2_i23 > 255) {
        c2_i23 = 255;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 195U, 37U, 1U);
      }

      CV_SATURATION_EVAL(5, 9, 0, 0, c2_covSaturation);
    }

    (*chartInstance->c2_clutchCommand)[0] = (uint8_T)c2_i23;
    for (c2_i25 = 0; c2_i25 < 2; c2_i25++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_clutchCommand)[c2_i25],
                            15U);
    }

    c2_u11 = (*chartInstance->c2_clutchCommand)[0];
    sf_mex_printf("%s =\\n", "clutchCommand[0]");
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 9, c2_u11);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
  c2_u10 = c2_com;
  c2_b_covSaturation = false;
  if (c2_u10 > 255) {
    c2_b_covSaturation = true;
    c2_u10 = 255U;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 199U, 20U, 3U);
  }

  CV_SATURATION_EVAL(5, 12, 0, 0, c2_b_covSaturation);
  (*chartInstance->c2_clutchCommand)[1] = (uint8_T)c2_u10;
  for (c2_i26 = 0; c2_i26 < 2; c2_i26++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_clutchCommand)[c2_i26],
                          15U);
  }

  c2_u12 = (*chartInstance->c2_clutchCommand)[1];
  sf_mex_printf("%s =\\n", "clutchCommand[1]");
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 9, c2_u12);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(32U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c2_sfEvent);
}

static void c2_sendAccCommand(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, uint16_T c2_com)
{
  boolean_T c2_b_out;
  int32_T c2_i27;
  boolean_T c2_covSaturation;
  int32_T c2_i28;
  uint16_T c2_u13;
  int32_T c2_i29;
  uint16_T c2_u14;
  int32_T c2_i30;
  uint16_T c2_u15;
  _SFD_DATA_RANGE_CHECK((real_T)c2_com, 33U);
  _SFD_SET_DATA_VALUE_PTR(33U, (void *)&c2_com);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("com", &c2_com, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c2_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c2_sfEvent);
  c2_b_out = (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(5U, 1U, 0,
    (boolean_T)CV_RELATIONAL_EVAL(5U, 1U, 0, (real_T)
    (*chartInstance->c2_accCommand)[0], 255.0, 0, 5U,
    (*chartInstance->c2_accCommand)[0] >= 255) != 0U, chartInstance->c2_sfEvent))
              != 0);
  if (c2_b_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
    (*chartInstance->c2_accCommand)[0] = 0U;
    for (c2_i28 = 0; c2_i28 < 2; c2_i28++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_accCommand)[c2_i28], 13U);
    }

    c2_u13 = (*chartInstance->c2_accCommand)[0];
    sf_mex_printf("%s =\\n", "accCommand[0]");
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11, c2_u13);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
    c2_i27 = (*chartInstance->c2_accCommand)[0] + 1;
    c2_covSaturation = false;
    if (c2_i27 < 0) {
      c2_covSaturation = true;
      c2_i27 = 0;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 172U, 31U, 1U);
    } else {
      if (c2_i27 > 65535) {
        c2_i27 = 65535;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 172U, 31U, 1U);
      }

      CV_SATURATION_EVAL(5, 3, 0, 0, c2_covSaturation);
    }

    (*chartInstance->c2_accCommand)[0] = (uint16_T)c2_i27;
    for (c2_i29 = 0; c2_i29 < 2; c2_i29++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_accCommand)[c2_i29], 13U);
    }

    c2_u14 = (*chartInstance->c2_accCommand)[0];
    sf_mex_printf("%s =\\n", "accCommand[0]");
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11, c2_u14);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
  (*chartInstance->c2_accCommand)[1] = c2_com;
  for (c2_i30 = 0; c2_i30 < 2; c2_i30++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_accCommand)[c2_i30], 13U);
  }

  c2_u15 = (*chartInstance->c2_accCommand)[1];
  sf_mex_printf("%s =\\n", "accCommand[1]");
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11, c2_u15);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(33U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c2_sfEvent);
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc2_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_emlrt_marshallIn(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i31;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i31, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i31;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc2_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent), &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  uint16_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc2_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(uint16_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc2_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_b_emlrt_marshallIn(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c2_b_out, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_out), &c2_thisId);
  sf_mex_destroy(&c2_b_out);
  return c2_y;
}

static real_T c2_c_emlrt_marshallIn(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_out;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc2_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c2_b_out = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_out), &c2_thisId);
  sf_mex_destroy(&c2_b_out);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint16_T c2_d_emlrt_marshallIn(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c2_b_currGear, const char_T *c2_identifier)
{
  uint16_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_currGear),
    &c2_thisId);
  sf_mex_destroy(&c2_b_currGear);
  return c2_y;
}

static uint16_T c2_e_emlrt_marshallIn(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint16_T c2_y;
  uint16_T c2_u16;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u16, 1, 5, 0U, 0, 0U, 0);
  c2_y = c2_u16;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_currGear;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  uint16_T c2_y;
  SFc2_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc2_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c2_b_currGear = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_currGear),
    &c2_thisId);
  sf_mex_destroy(&c2_b_currGear);
  *(uint16_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i32;
  const mxArray *c2_y = NULL;
  uint16_T c2_u[2];
  SFc2_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc2_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i32 = 0; c2_i32 < 2; c2_i32++) {
    c2_u[c2_i32] = (*(uint16_T (*)[2])c2_inData)[c2_i32];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 5, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_f_emlrt_marshallIn(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c2_b_shiftCommand, const char_T *c2_identifier,
  uint16_T c2_y[2])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_shiftCommand), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_b_shiftCommand);
}

static void c2_g_emlrt_marshallIn(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  uint16_T c2_y[2])
{
  uint16_T c2_uv4[2];
  int32_T c2_i33;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_uv4, 1, 5, 0U, 1, 0U, 2, 1, 2);
  for (c2_i33 = 0; c2_i33 < 2; c2_i33++) {
    c2_y[c2_i33] = c2_uv4[c2_i33];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_shiftCommand;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  uint16_T c2_y[2];
  int32_T c2_i34;
  SFc2_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc2_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c2_b_shiftCommand = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_shiftCommand), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_b_shiftCommand);
  for (c2_i34 = 0; c2_i34 < 2; c2_i34++) {
    (*(uint16_T (*)[2])c2_outData)[c2_i34] = c2_y[c2_i34];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  uint8_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc2_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(uint8_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static uint8_T c2_h_emlrt_marshallIn(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c2_b_startEngCommand, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_startEngCommand),
    &c2_thisId);
  sf_mex_destroy(&c2_b_startEngCommand);
  return c2_y;
}

static uint8_T c2_i_emlrt_marshallIn(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u17;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u17, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u17;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_startEngCommand;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  uint8_T c2_y;
  SFc2_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc2_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c2_b_startEngCommand = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_startEngCommand),
    &c2_thisId);
  sf_mex_destroy(&c2_b_startEngCommand);
  *(uint8_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i35;
  const mxArray *c2_y = NULL;
  uint8_T c2_u[2];
  SFc2_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc2_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i35 = 0; c2_i35 < 2; c2_i35++) {
    c2_u[c2_i35] = (*(uint8_T (*)[2])c2_inData)[c2_i35];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 3, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_j_emlrt_marshallIn(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c2_b_clutchCommand, const char_T *c2_identifier,
  uint8_T c2_y[2])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_clutchCommand),
                        &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_clutchCommand);
}

static void c2_k_emlrt_marshallIn(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  uint8_T c2_y[2])
{
  uint8_T c2_uv5[2];
  int32_T c2_i36;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_uv5, 1, 3, 0U, 1, 0U, 2, 1, 2);
  for (c2_i36 = 0; c2_i36 < 2; c2_i36++) {
    c2_y[c2_i36] = c2_uv5[c2_i36];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_clutchCommand;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  uint8_T c2_y[2];
  int32_T c2_i37;
  SFc2_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc2_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c2_b_clutchCommand = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_clutchCommand),
                        &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_clutchCommand);
  for (c2_i37 = 0; c2_i37 < 2; c2_i37++) {
    (*(uint8_T (*)[2])c2_outData)[c2_i37] = c2_y[c2_i37];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_l_emlrt_marshallIn(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c2_b_setSimStateSideEffectsInfo, const char_T
  *c2_identifier)
{
  const mxArray *c2_y = NULL;
  emlrtMsgIdentifier c2_thisId;
  c2_y = NULL;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  sf_mex_assign(&c2_y, c2_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_setSimStateSideEffectsInfo), &c2_thisId), false);
  sf_mex_destroy(&c2_b_setSimStateSideEffectsInfo);
  return c2_y;
}

static const mxArray *c2_m_emlrt_marshallIn(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  (void)c2_parentId;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_duplicatearraysafe(&c2_u), false);
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static const mxArray *sf_get_hover_data_for_msg
  (SFc2_GCU_Model_genCodeInstanceStruct *chartInstance, int32_T c2_ssid)
{
  (void)chartInstance;
  (void)c2_ssid;
  return NULL;
}

static void c2_init_sf_message_store_memory(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static uint16_T c2__u16_s32_(SFc2_GCU_Model_genCodeInstanceStruct *chartInstance,
  int32_T c2_b, uint32_T c2_ssid_src_loc, int32_T c2_offset_src_loc, int32_T
  c2_length_src_loc)
{
  uint16_T c2_a;
  (void)chartInstance;
  c2_a = (uint16_T)c2_b;
  if (c2_a != c2_b) {
    _SFD_OVERFLOW_DETECTION(SFDB_OVERFLOW, c2_ssid_src_loc, c2_offset_src_loc,
      c2_length_src_loc);
  }

  return c2_a;
}

static int32_T c2__s32_add__(SFc2_GCU_Model_genCodeInstanceStruct *chartInstance,
  int32_T c2_b, int32_T c2_c, uint32_T c2_ssid_src_loc, int32_T
  c2_offset_src_loc, int32_T c2_length_src_loc)
{
  int32_T c2_a;
  (void)chartInstance;
  c2_a = c2_b + c2_c;
  if (((c2_a ^ c2_b) & (c2_a ^ c2_c)) < 0) {
    _SFD_OVERFLOW_DETECTION(SFDB_OVERFLOW, c2_ssid_src_loc, c2_offset_src_loc,
      c2_length_src_loc);
  }

  return c2_a;
}

static void init_dsm_address_info(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  chartInstance->c2_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c2_Id = (uint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_firstInt = (uint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_secondInt = (uint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_thirdInt = (uint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c2_fourthInt = (uint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c2_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_currGear = (uint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_acc_externValue = (uint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c2_acc_externValues_index = (uint16_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 4);
  chartInstance->c2_shiftCommand = (uint16_T (*)[2])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 5);
  chartInstance->c2_startEngCommand = (uint8_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c2_accCommand = (uint16_T (*)[2])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c2_tractionTarget = (uint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c2_clutchCommand = (uint8_T (*)[2])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 9);
  chartInstance->c2_clutchCurrVal = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c2_modeCommand = (uint16_T (*)[2])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 10);
  chartInstance->c2_accParametersValue = (uint16_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 11);
  chartInstance->c2_accParametersIndex = (uint16_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 12);
  chartInstance->c2_timingsValue = (uint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 13);
  chartInstance->c2_timingsIndex = (uint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 14);
  chartInstance->c2_mapTarget = (uint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 15);
  chartInstance->c2_rpmLimiterTarget = (uint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 16);
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

void sf_c2_GCU_Model_genCode_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1137737076U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(852895098U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2430769927U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2735254353U);
}

mxArray* sf_c2_GCU_Model_genCode_get_post_codegen_info(void);
mxArray *sf_c2_GCU_Model_genCode_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("omJ5FmgkvjCfIpwIvPAuRC");
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

    mxArray *mxData = mxCreateStructMatrix(1,16,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(2);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(2);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(2);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(2);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,14,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,15,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,15,"type",mxType);
    }

    mxSetField(mxData,15,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c2_GCU_Model_genCode_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_GCU_Model_genCode_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_GCU_Model_genCode_jit_fallback_info(void)
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

mxArray *sf_c2_GCU_Model_genCode_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_GCU_Model_genCode_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c2_GCU_Model_genCode(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[162],T\"accCommand\",},{M[1],M[362],T\"accParametersIndex\",},{M[1],M[361],T\"accParametersValue\",},{M[1],M[104],T\"acc_externValue\",},{M[1],M[103],T\"acc_externValues_index\",},{M[1],M[184],T\"clutchCommand\",},{M[1],M[102],T\"currGear\",},{M[1],M[373],T\"mapTarget\",},{M[1],M[337],T\"modeCommand\",},{M[1],M[94],T\"out\",}}",
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[583],T\"rpmLimiterTarget\",},{M[1],M[131],T\"shiftCommand\",},{M[1],M[161],T\"startEngCommand\",},{M[1],M[364],T\"timingsIndex\",},{M[1],M[363],T\"timingsValue\",},{M[1],M[183],T\"tractionTarget\",},{M[3],M[578],T\"clutchTarget\",},{M[8],M[0],T\"is_active_c2_GCU_Model_genCode\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 18, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_GCU_Model_genCode_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc2_GCU_Model_genCodeInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_GCU_Model_genCodeInstanceStruct *chartInstance =
      (SFc2_GCU_Model_genCodeInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _GCU_Model_genCodeMachineNumber_,
           2,
           13,
           68,
           0,
           35,
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
          _SFD_SET_DATA_PROPS(0,0,0,0,"clutchTarget");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Id");
          _SFD_SET_DATA_PROPS(2,1,1,0,"firstInt");
          _SFD_SET_DATA_PROPS(3,1,1,0,"secondInt");
          _SFD_SET_DATA_PROPS(4,1,1,0,"thirdInt");
          _SFD_SET_DATA_PROPS(5,1,1,0,"fourthInt");
          _SFD_SET_DATA_PROPS(6,1,1,0,"clutchCurrVal");
          _SFD_SET_DATA_PROPS(7,2,0,1,"out");
          _SFD_SET_DATA_PROPS(8,2,0,1,"currGear");
          _SFD_SET_DATA_PROPS(9,2,0,1,"acc_externValue");
          _SFD_SET_DATA_PROPS(10,2,0,1,"acc_externValues_index");
          _SFD_SET_DATA_PROPS(11,2,0,1,"shiftCommand");
          _SFD_SET_DATA_PROPS(12,2,0,1,"startEngCommand");
          _SFD_SET_DATA_PROPS(13,2,0,1,"accCommand");
          _SFD_SET_DATA_PROPS(14,2,0,1,"tractionTarget");
          _SFD_SET_DATA_PROPS(15,2,0,1,"clutchCommand");
          _SFD_SET_DATA_PROPS(16,2,0,1,"modeCommand");
          _SFD_SET_DATA_PROPS(17,2,0,1,"accParametersValue");
          _SFD_SET_DATA_PROPS(18,2,0,1,"accParametersIndex");
          _SFD_SET_DATA_PROPS(19,2,0,1,"timingsValue");
          _SFD_SET_DATA_PROPS(20,2,0,1,"timingsIndex");
          _SFD_SET_DATA_PROPS(21,2,0,1,"mapTarget");
          _SFD_SET_DATA_PROPS(22,2,0,1,"rpmLimiterTarget");
          _SFD_SET_DATA_PROPS(23,7,0,0,"STOP_COM");
          _SFD_SET_DATA_PROPS(24,7,0,0,"GEAR_COMMAND_DOWN");
          _SFD_SET_DATA_PROPS(25,7,0,0,"GEAR_COMMAND_NEUTRAL_DOWN");
          _SFD_SET_DATA_PROPS(26,7,0,0,"GEAR_COMMAND_NEUTRAL_UP");
          _SFD_SET_DATA_PROPS(27,7,0,0,"STOP_COM");
          _SFD_SET_DATA_PROPS(28,7,0,0,"ACC_CLUTCH_NOISE_LEVEL");
          _SFD_SET_DATA_PROPS(29,7,0,0,"STOP_COM");
          _SFD_SET_DATA_PROPS(30,7,0,0,"STOP_COM");
          _SFD_SET_DATA_PROPS(31,8,0,0,"");
          _SFD_SET_DATA_PROPS(32,8,0,0,"");
          _SFD_SET_DATA_PROPS(33,8,0,0,"");
          _SFD_SET_DATA_PROPS(34,8,0,0,"");
          _SFD_EVENT_SCOPE(0,2);
          _SFD_EVENT_SCOPE(1,2);
          _SFD_EVENT_SCOPE(2,2);
          _SFD_STATE_INFO(8,0,2);
          _SFD_STATE_INFO(9,0,2);
          _SFD_STATE_INFO(10,0,2);
          _SFD_STATE_INFO(11,0,2);
          _SFD_STATE_INFO(12,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(11,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(12,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(35,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 31 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(36,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(41,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 21 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(38,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(37,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 22 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(39,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(40,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 30 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(47,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(46,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 30 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(42,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(44,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 26 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(45,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(48,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 33 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(43,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(64,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 29 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(65,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(67,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 23 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(23,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 23 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 5, 5, 5 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(23,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartSaturateMap[] = { 35 };

          static unsigned int sEndSaturateMap[] = { 36 };

          _SFD_CV_INIT_TRANSITION_SATURATION(24,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        _SFD_CV_INIT_TRANS(25,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(49,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(50,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 23 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(14,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 23 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 5, 5, 5 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(14,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartSaturateMap[] = { 35 };

          static unsigned int sEndSaturateMap[] = { 36 };

          _SFD_CV_INIT_TRANSITION_SATURATION(15,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 21 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(19,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 21 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 1, 1, 1 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(19,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 2, 38, 77 };

          static unsigned int sEndGuardMap[] = { 32, 70, 101 };

          static int sPostFixPredicateTree[] = { 0, 1, -2, 2, -2 };

          _SFD_CV_INIT_TRANS(26,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2, 38, 77 };

          static unsigned int sEndRelationalopMap[] = { 32, 70, 101 };

          static int sRelationalopEps[] = { 0, 0, 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(26,3,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(28,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(27,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(51,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(52,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartSaturateMap[] = { 86 };

          static unsigned int sEndSaturateMap[] = { 87 };

          _SFD_CV_INIT_TRANSITION_SATURATION(52,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 24 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(8,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 24 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 5, 5, 5 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(8,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartSaturateMap[] = { 37 };

          static unsigned int sEndSaturateMap[] = { 38 };

          _SFD_CV_INIT_TRANSITION_SATURATION(9,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartSaturateMap[] = { 20 };

          static unsigned int sEndSaturateMap[] = { 23 };

          _SFD_CV_INIT_TRANSITION_SATURATION(12,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        _SFD_CV_INIT_TRANS(53,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartSaturateMap[] = { 16 };

          static unsigned int sEndSaturateMap[] = { 24 };

          _SFD_CV_INIT_TRANSITION_SATURATION(53,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 38 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(57,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 38 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 4, 4, 4 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(57,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(59,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(55,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(56,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(58,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 21 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 21 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 5, 5, 5 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(1,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartSaturateMap[] = { 31 };

          static unsigned int sEndSaturateMap[] = { 32 };

          _SFD_CV_INIT_TRANSITION_SATURATION(3,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(60,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 25 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(63,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(62,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(61,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(29,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 22 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(30,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 22 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 5, 5, 5 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(30,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(31,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartSaturateMap[] = { 33 };

          static unsigned int sEndSaturateMap[] = { 34 };

          _SFD_CV_INIT_TRANSITION_SATURATION(31,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        _SFD_CV_INIT_TRANS(32,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(33,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(34,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(54,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartSaturateMap[] = { 35 };

          static unsigned int sEndSaturateMap[] = { 36 };

          _SFD_CV_INIT_TRANSITION_SATURATION(54,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        _SFD_CV_INIT_TRANS(66,0,NULL,NULL,0,NULL);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)c2_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_UINT16,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)
            c2_d_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(12,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)c2_e_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(13,SF_UINT16,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)
            c2_d_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(14,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(15,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_f_sf_marshallOut,(MexInFcnForType)
            c2_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(16,SF_UINT16,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)
            c2_d_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(17,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(30,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(31,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(32,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(33,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(34,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(31,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(32,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(33,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(34,(void *)(NULL));
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
    SFc2_GCU_Model_genCodeInstanceStruct *chartInstance =
      (SFc2_GCU_Model_genCodeInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c2_Id);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c2_firstInt);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c2_secondInt);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c2_thirdInt);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)chartInstance->c2_fourthInt);
        _SFD_SET_DATA_VALUE_PTR(7U, (void *)chartInstance->c2_out);
        _SFD_SET_DATA_VALUE_PTR(8U, (void *)chartInstance->c2_currGear);
        _SFD_SET_DATA_VALUE_PTR(9U, (void *)chartInstance->c2_acc_externValue);
        _SFD_SET_DATA_VALUE_PTR(10U, (void *)
          chartInstance->c2_acc_externValues_index);
        _SFD_SET_DATA_VALUE_PTR(11U, (void *)chartInstance->c2_shiftCommand);
        _SFD_SET_DATA_VALUE_PTR(12U, (void *)chartInstance->c2_startEngCommand);
        _SFD_SET_DATA_VALUE_PTR(13U, (void *)chartInstance->c2_accCommand);
        _SFD_SET_DATA_VALUE_PTR(14U, (void *)chartInstance->c2_tractionTarget);
        _SFD_SET_DATA_VALUE_PTR(15U, (void *)chartInstance->c2_clutchCommand);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)chartInstance->c2_clutchCurrVal);
        _SFD_SET_DATA_VALUE_PTR(16U, (void *)chartInstance->c2_modeCommand);
        _SFD_SET_DATA_VALUE_PTR(17U, (void *)
          chartInstance->c2_accParametersValue);
        _SFD_SET_DATA_VALUE_PTR(18U, (void *)
          chartInstance->c2_accParametersIndex);
        _SFD_SET_DATA_VALUE_PTR(19U, (void *)chartInstance->c2_timingsValue);
        _SFD_SET_DATA_VALUE_PTR(20U, (void *)chartInstance->c2_timingsIndex);
        _SFD_SET_DATA_VALUE_PTR(21U, (void *)chartInstance->c2_mapTarget);
        _SFD_SET_DATA_VALUE_PTR(22U, (void *)chartInstance->c2_rpmLimiterTarget);
        _SFD_SET_DATA_VALUE_PTR(23U, (void *)&chartInstance->c2_STOP_COM);
        _SFD_SET_DATA_VALUE_PTR(27U, (void *)&chartInstance->c2_b_STOP_COM);
        _SFD_SET_DATA_VALUE_PTR(25U, (void *)
          &chartInstance->c2_GEAR_COMMAND_NEUTRAL_DOWN);
        _SFD_SET_DATA_VALUE_PTR(26U, (void *)
          &chartInstance->c2_GEAR_COMMAND_NEUTRAL_UP);
        _SFD_SET_DATA_VALUE_PTR(24U, (void *)
          &chartInstance->c2_GEAR_COMMAND_DOWN);
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)&chartInstance->c2_clutchTarget);
        _SFD_SET_DATA_VALUE_PTR(29U, (void *)&chartInstance->c2_c_STOP_COM);
        _SFD_SET_DATA_VALUE_PTR(28U, (void *)
          &chartInstance->c2_ACC_CLUTCH_NOISE_LEVEL);
        _SFD_SET_DATA_VALUE_PTR(30U, (void *)&chartInstance->c2_d_STOP_COM);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "s4JycQuEsBuP466ZT6qWrcE";
}

static void sf_opaque_initialize_c2_GCU_Model_genCode(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_GCU_Model_genCode((SFc2_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar);
  initialize_c2_GCU_Model_genCode((SFc2_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_GCU_Model_genCode(void *chartInstanceVar)
{
  enable_c2_GCU_Model_genCode((SFc2_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_GCU_Model_genCode(void *chartInstanceVar)
{
  disable_c2_GCU_Model_genCode((SFc2_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_GCU_Model_genCode(void *chartInstanceVar)
{
  sf_gateway_c2_GCU_Model_genCode((SFc2_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_GCU_Model_genCode(SimStruct* S)
{
  return get_sim_state_c2_GCU_Model_genCode
    ((SFc2_GCU_Model_genCodeInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_GCU_Model_genCode(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c2_GCU_Model_genCode((SFc2_GCU_Model_genCodeInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c2_GCU_Model_genCode(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_GCU_Model_genCodeInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_GCU_Model_genCode_optimization_info();
    }

    finalize_c2_GCU_Model_genCode((SFc2_GCU_Model_genCodeInstanceStruct*)
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
  initSimStructsc2_GCU_Model_genCode((SFc2_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_GCU_Model_genCode(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_GCU_Model_genCode((SFc2_GCU_Model_genCodeInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c2_GCU_Model_genCode(SimStruct *S)
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
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetSupportedForRowMajorCodeGen(S, 1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 2);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,2);
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,2,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,16);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=16; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2619499523U));
  ssSetChecksum1(S,(3975368701U));
  ssSetChecksum2(S,(2178805174U));
  ssSetChecksum3(S,(2029318101U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_GCU_Model_genCode(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c2_GCU_Model_genCode(SimStruct *S)
{
  SFc2_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc2_GCU_Model_genCodeInstanceStruct *)utMalloc(sizeof
    (SFc2_GCU_Model_genCodeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_GCU_Model_genCodeInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_GCU_Model_genCode;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_GCU_Model_genCode;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_GCU_Model_genCode;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_GCU_Model_genCode;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_GCU_Model_genCode;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_GCU_Model_genCode;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_GCU_Model_genCode;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_GCU_Model_genCode;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_GCU_Model_genCode;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_GCU_Model_genCode;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_GCU_Model_genCode;
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
  mdl_start_c2_GCU_Model_genCode(chartInstance);
}

void c2_GCU_Model_genCode_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_GCU_Model_genCode(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_GCU_Model_genCode(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_GCU_Model_genCode(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_GCU_Model_genCode_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
