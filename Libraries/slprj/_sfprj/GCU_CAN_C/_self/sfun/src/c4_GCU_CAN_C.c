/* Include files */

#include "GCU_CAN_C_sfun.h"
#include "c4_GCU_CAN_C.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "GCU_CAN_C_sfun_debug_macros.h"
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
#define c4_const_STOP_COM              ((uint16_T)0U)
#define c4_const_GEAR_COMMAND_NEUTRAL_DOWN ((uint16_T)100U)
#define c4_const_GEAR_COMMAND_NEUTRAL_UP ((uint16_T)50U)
#define c4_const_GEAR_COMMAND_DOWN     ((uint16_T)200U)
#define c4_const_ACC_CLUTCH_NOISE_LEVEL ((uint8_T)30U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c4_GCU_CAN_C(SFc4_GCU_CAN_CInstanceStruct *chartInstance);
static void initialize_params_c4_GCU_CAN_C(SFc4_GCU_CAN_CInstanceStruct
  *chartInstance);
static void enable_c4_GCU_CAN_C(SFc4_GCU_CAN_CInstanceStruct *chartInstance);
static void disable_c4_GCU_CAN_C(SFc4_GCU_CAN_CInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_GCU_CAN_C(SFc4_GCU_CAN_CInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c4_GCU_CAN_C(SFc4_GCU_CAN_CInstanceStruct
  *chartInstance);
static void set_sim_state_c4_GCU_CAN_C(SFc4_GCU_CAN_CInstanceStruct
  *chartInstance, const mxArray *c4_st);
static void c4_set_sim_state_side_effects_c4_GCU_CAN_C
  (SFc4_GCU_CAN_CInstanceStruct *chartInstance);
static void finalize_c4_GCU_CAN_C(SFc4_GCU_CAN_CInstanceStruct *chartInstance);
static void sf_gateway_c4_GCU_CAN_C(SFc4_GCU_CAN_CInstanceStruct *chartInstance);
static void mdl_start_c4_GCU_CAN_C(SFc4_GCU_CAN_CInstanceStruct *chartInstance);
static void c4_chartstep_c4_GCU_CAN_C(SFc4_GCU_CAN_CInstanceStruct
  *chartInstance);
static void initSimStructsc4_GCU_CAN_C(SFc4_GCU_CAN_CInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static void c4_sendClutchCommand(SFc4_GCU_CAN_CInstanceStruct *chartInstance,
  uint16_T c4_com);
static void c4_sendAccCommand(SFc4_GCU_CAN_CInstanceStruct *chartInstance,
  uint16_T c4_com);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static int32_T c4_emlrt_marshallIn(SFc4_GCU_CAN_CInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_b_emlrt_marshallIn(SFc4_GCU_CAN_CInstanceStruct *chartInstance,
  const mxArray *c4_b_out, const char_T *c4_identifier);
static real_T c4_c_emlrt_marshallIn(SFc4_GCU_CAN_CInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint16_T c4_d_emlrt_marshallIn(SFc4_GCU_CAN_CInstanceStruct
  *chartInstance, const mxArray *c4_b_currGear, const char_T *c4_identifier);
static uint16_T c4_e_emlrt_marshallIn(SFc4_GCU_CAN_CInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_f_emlrt_marshallIn(SFc4_GCU_CAN_CInstanceStruct *chartInstance,
  const mxArray *c4_b_shiftCommand, const char_T *c4_identifier, uint16_T c4_y[2]);
static void c4_g_emlrt_marshallIn(SFc4_GCU_CAN_CInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, uint16_T c4_y[2]);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static uint8_T c4_h_emlrt_marshallIn(SFc4_GCU_CAN_CInstanceStruct *chartInstance,
  const mxArray *c4_b_startEngCommand, const char_T *c4_identifier);
static uint8_T c4_i_emlrt_marshallIn(SFc4_GCU_CAN_CInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_j_emlrt_marshallIn(SFc4_GCU_CAN_CInstanceStruct *chartInstance,
  const mxArray *c4_b_clutchCommand, const char_T *c4_identifier, uint8_T c4_y[2]);
static void c4_k_emlrt_marshallIn(SFc4_GCU_CAN_CInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, uint8_T c4_y[2]);
static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_l_emlrt_marshallIn(SFc4_GCU_CAN_CInstanceStruct
  *chartInstance, const mxArray *c4_b_setSimStateSideEffectsInfo, const char_T
  *c4_identifier);
static const mxArray *c4_m_emlrt_marshallIn(SFc4_GCU_CAN_CInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static const mxArray *sf_get_hover_data_for_msg(SFc4_GCU_CAN_CInstanceStruct
  *chartInstance, int32_T c4_ssid);
static void c4_init_sf_message_store_memory(SFc4_GCU_CAN_CInstanceStruct
  *chartInstance);
static uint16_T c4__u16_s32_(SFc4_GCU_CAN_CInstanceStruct *chartInstance,
  int32_T c4_b, uint32_T c4_ssid_src_loc, int32_T c4_offset_src_loc, int32_T
  c4_length_src_loc);
static int32_T c4__s32_add__(SFc4_GCU_CAN_CInstanceStruct *chartInstance,
  int32_T c4_b, int32_T c4_c, uint32_T c4_ssid_src_loc, int32_T
  c4_offset_src_loc, int32_T c4_length_src_loc);
static void init_dsm_address_info(SFc4_GCU_CAN_CInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc4_GCU_CAN_CInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_GCU_CAN_C(SFc4_GCU_CAN_CInstanceStruct *chartInstance)
{
  int32_T c4_i0;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc4_GCU_CAN_C(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_doSetSimStateSideEffects = 0U;
  chartInstance->c4_setSimStateSideEffectsInfo = NULL;
  chartInstance->c4_is_active_c4_GCU_CAN_C = 0U;
  chartInstance->c4_clutchTarget = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c4_clutchTarget, 0U);
  chartInstance->c4_STOP_COM = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c4_STOP_COM, 23U);
  chartInstance->c4_b_STOP_COM = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c4_b_STOP_COM, 27U);
  chartInstance->c4_GEAR_COMMAND_NEUTRAL_DOWN = 100U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c4_GEAR_COMMAND_NEUTRAL_DOWN, 25U);
  chartInstance->c4_GEAR_COMMAND_NEUTRAL_UP = 50U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c4_GEAR_COMMAND_NEUTRAL_UP, 26U);
  chartInstance->c4_GEAR_COMMAND_DOWN = 200U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c4_GEAR_COMMAND_DOWN, 24U);
  chartInstance->c4_c_STOP_COM = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c4_c_STOP_COM, 29U);
  chartInstance->c4_ACC_CLUTCH_NOISE_LEVEL = 30U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c4_ACC_CLUTCH_NOISE_LEVEL, 28U);
  chartInstance->c4_d_STOP_COM = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c4_d_STOP_COM, 30U);
  chartInstance->c4_e_STOP_COM = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c4_e_STOP_COM, 31U);
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    *chartInstance->c4_out = 0.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c4_out, 7U);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 2) != 0)) {
    *chartInstance->c4_currGear = 0U;
    _SFD_DATA_RANGE_CHECK_MAX((real_T)*chartInstance->c4_currGear, 8U, 5.0, 0U,
      0, 0);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 3) != 0)) {
    *chartInstance->c4_aac_externValue = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_aac_externValue, 9U);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 4) != 0)) {
    *chartInstance->c4_aac_externValues_index = 0U;
    _SFD_DATA_RANGE_CHECK_MAX((real_T)*chartInstance->c4_aac_externValues_index,
      10U, 3.0, 0U, 0, 0);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 5) != 0)) {
    (*chartInstance->c4_shiftCommand)[0] = 0U;
    for (c4_i0 = 0; c4_i0 < 2; c4_i0++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_shiftCommand)[c4_i0],
                            11U);
    }

    (*chartInstance->c4_shiftCommand)[1] = 0U;
    for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_shiftCommand)[c4_i2],
                            11U);
    }
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 6) != 0)) {
    *chartInstance->c4_startEngCommand = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_startEngCommand, 12U);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 7) != 0)) {
    (*chartInstance->c4_accCommand)[0] = 0U;
    for (c4_i1 = 0; c4_i1 < 2; c4_i1++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_accCommand)[c4_i1], 13U);
    }

    (*chartInstance->c4_accCommand)[1] = 0U;
    for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_accCommand)[c4_i4], 13U);
    }
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 8) != 0)) {
    *chartInstance->c4_tractionTarget = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_tractionTarget, 14U);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 9) != 0)) {
    (*chartInstance->c4_clutchCommand)[0] = 0U;
    for (c4_i3 = 0; c4_i3 < 2; c4_i3++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_clutchCommand)[c4_i3],
                            15U);
    }

    (*chartInstance->c4_clutchCommand)[1] = 0U;
    for (c4_i6 = 0; c4_i6 < 2; c4_i6++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_clutchCommand)[c4_i6],
                            15U);
    }
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 10) != 0)) {
    (*chartInstance->c4_modeCommand)[0] = 0U;
    for (c4_i5 = 0; c4_i5 < 2; c4_i5++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_modeCommand)[c4_i5], 16U);
    }

    (*chartInstance->c4_modeCommand)[1] = 0U;
    for (c4_i7 = 0; c4_i7 < 2; c4_i7++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_modeCommand)[c4_i7], 16U);
    }
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 11) != 0)) {
    *chartInstance->c4_accParametersValue = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_accParametersValue, 17U);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 12) != 0)) {
    *chartInstance->c4_accParametersIndex = 0U;
    _SFD_DATA_RANGE_CHECK_MAX((real_T)*chartInstance->c4_accParametersIndex, 18U,
      3.0, 0U, 0, 0);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 13) != 0)) {
    *chartInstance->c4_timingsValue = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_timingsValue, 19U);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 14) != 0)) {
    *chartInstance->c4_timingsIndex = 0U;
    _SFD_DATA_RANGE_CHECK_MAX((real_T)*chartInstance->c4_timingsIndex, 20U, 3.0,
      0U, 0, 0);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 15) != 0)) {
    *chartInstance->c4_mapTarget = 0U;
    _SFD_DATA_RANGE_CHECK_MAX((real_T)*chartInstance->c4_mapTarget, 21U, 5.0, 0U,
      0, 0);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 16) != 0)) {
    *chartInstance->c4_rpmLimiterTarget = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_rpmLimiterTarget, 22U);
  }
}

static void initialize_params_c4_GCU_CAN_C(SFc4_GCU_CAN_CInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_GCU_CAN_C(SFc4_GCU_CAN_CInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_enable(chartInstance->S, 0, "Efi_setRPMLimiter", 0);
  sf_call_output_fcn_enable(chartInstance->S, 1, "Efi_unsetRPMLimiter", 0);
  sf_call_output_fcn_enable(chartInstance->S, 2, "aac_updateExternValue", 0);
}

static void disable_c4_GCU_CAN_C(SFc4_GCU_CAN_CInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_disable(chartInstance->S, 0, "Efi_setRPMLimiter", 0);
  sf_call_output_fcn_disable(chartInstance->S, 1, "Efi_unsetRPMLimiter", 0);
  sf_call_output_fcn_disable(chartInstance->S, 2, "aac_updateExternValue", 0);
}

static void c4_update_debugger_state_c4_GCU_CAN_C(SFc4_GCU_CAN_CInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_GCU_CAN_C(SFc4_GCU_CAN_CInstanceStruct
  *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  uint16_T c4_hoistedGlobal;
  const mxArray *c4_b_y = NULL;
  uint16_T c4_b_hoistedGlobal;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  uint16_T c4_c_hoistedGlobal;
  const mxArray *c4_e_y = NULL;
  uint16_T c4_d_hoistedGlobal;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_g_y = NULL;
  uint16_T c4_e_hoistedGlobal;
  const mxArray *c4_h_y = NULL;
  uint16_T c4_f_hoistedGlobal;
  const mxArray *c4_i_y = NULL;
  const mxArray *c4_j_y = NULL;
  real_T c4_g_hoistedGlobal;
  const mxArray *c4_k_y = NULL;
  uint16_T c4_h_hoistedGlobal;
  const mxArray *c4_l_y = NULL;
  const mxArray *c4_m_y = NULL;
  uint8_T c4_i_hoistedGlobal;
  const mxArray *c4_n_y = NULL;
  uint16_T c4_j_hoistedGlobal;
  const mxArray *c4_o_y = NULL;
  uint16_T c4_k_hoistedGlobal;
  const mxArray *c4_p_y = NULL;
  uint16_T c4_l_hoistedGlobal;
  const mxArray *c4_q_y = NULL;
  uint8_T c4_m_hoistedGlobal;
  const mxArray *c4_r_y = NULL;
  uint8_T c4_n_hoistedGlobal;
  const mxArray *c4_s_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(18, 1), false);
  c4_hoistedGlobal = *chartInstance->c4_aac_externValue;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_hoistedGlobal, 5, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = *chartInstance->c4_aac_externValues_index;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", *chartInstance->c4_accCommand, 5, 0U,
    1U, 0U, 2, 1, 2), false);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_c_hoistedGlobal = *chartInstance->c4_accParametersIndex;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_c_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_d_hoistedGlobal = *chartInstance->c4_accParametersValue;
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_d_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 4, c4_f_y);
  c4_g_y = NULL;
  sf_mex_assign(&c4_g_y, sf_mex_create("y", *chartInstance->c4_clutchCommand, 3,
    0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_setcell(c4_y, 5, c4_g_y);
  c4_e_hoistedGlobal = *chartInstance->c4_currGear;
  c4_h_y = NULL;
  sf_mex_assign(&c4_h_y, sf_mex_create("y", &c4_e_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 6, c4_h_y);
  c4_f_hoistedGlobal = *chartInstance->c4_mapTarget;
  c4_i_y = NULL;
  sf_mex_assign(&c4_i_y, sf_mex_create("y", &c4_f_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 7, c4_i_y);
  c4_j_y = NULL;
  sf_mex_assign(&c4_j_y, sf_mex_create("y", *chartInstance->c4_modeCommand, 5,
    0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_setcell(c4_y, 8, c4_j_y);
  c4_g_hoistedGlobal = *chartInstance->c4_out;
  c4_k_y = NULL;
  sf_mex_assign(&c4_k_y, sf_mex_create("y", &c4_g_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 9, c4_k_y);
  c4_h_hoistedGlobal = *chartInstance->c4_rpmLimiterTarget;
  c4_l_y = NULL;
  sf_mex_assign(&c4_l_y, sf_mex_create("y", &c4_h_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 10, c4_l_y);
  c4_m_y = NULL;
  sf_mex_assign(&c4_m_y, sf_mex_create("y", *chartInstance->c4_shiftCommand, 5,
    0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_setcell(c4_y, 11, c4_m_y);
  c4_i_hoistedGlobal = *chartInstance->c4_startEngCommand;
  c4_n_y = NULL;
  sf_mex_assign(&c4_n_y, sf_mex_create("y", &c4_i_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 12, c4_n_y);
  c4_j_hoistedGlobal = *chartInstance->c4_timingsIndex;
  c4_o_y = NULL;
  sf_mex_assign(&c4_o_y, sf_mex_create("y", &c4_j_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 13, c4_o_y);
  c4_k_hoistedGlobal = *chartInstance->c4_timingsValue;
  c4_p_y = NULL;
  sf_mex_assign(&c4_p_y, sf_mex_create("y", &c4_k_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 14, c4_p_y);
  c4_l_hoistedGlobal = *chartInstance->c4_tractionTarget;
  c4_q_y = NULL;
  sf_mex_assign(&c4_q_y, sf_mex_create("y", &c4_l_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 15, c4_q_y);
  c4_m_hoistedGlobal = chartInstance->c4_clutchTarget;
  c4_r_y = NULL;
  sf_mex_assign(&c4_r_y, sf_mex_create("y", &c4_m_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 16, c4_r_y);
  c4_n_hoistedGlobal = chartInstance->c4_is_active_c4_GCU_CAN_C;
  c4_s_y = NULL;
  sf_mex_assign(&c4_s_y, sf_mex_create("y", &c4_n_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 17, c4_s_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_GCU_CAN_C(SFc4_GCU_CAN_CInstanceStruct
  *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  uint16_T c4_uv0[2];
  int32_T c4_i8;
  uint8_T c4_uv1[2];
  int32_T c4_i9;
  uint16_T c4_uv2[2];
  int32_T c4_i10;
  uint16_T c4_uv3[2];
  int32_T c4_i11;
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  *chartInstance->c4_aac_externValue = c4_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 0)), "aac_externValue");
  *chartInstance->c4_aac_externValues_index = c4_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
     "aac_externValues_index");
  c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 2)),
                        "accCommand", c4_uv0);
  for (c4_i8 = 0; c4_i8 < 2; c4_i8++) {
    (*chartInstance->c4_accCommand)[c4_i8] = c4_uv0[c4_i8];
  }

  *chartInstance->c4_accParametersIndex = c4_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 3)), "accParametersIndex");
  *chartInstance->c4_accParametersValue = c4_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 4)), "accParametersValue");
  c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 5)),
                        "clutchCommand", c4_uv1);
  for (c4_i9 = 0; c4_i9 < 2; c4_i9++) {
    (*chartInstance->c4_clutchCommand)[c4_i9] = c4_uv1[c4_i9];
  }

  *chartInstance->c4_currGear = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 6)), "currGear");
  *chartInstance->c4_mapTarget = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 7)), "mapTarget");
  c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 8)),
                        "modeCommand", c4_uv2);
  for (c4_i10 = 0; c4_i10 < 2; c4_i10++) {
    (*chartInstance->c4_modeCommand)[c4_i10] = c4_uv2[c4_i10];
  }

  *chartInstance->c4_out = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 9)), "out");
  *chartInstance->c4_rpmLimiterTarget = c4_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 10)), "rpmLimiterTarget");
  c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 11)),
                        "shiftCommand", c4_uv3);
  for (c4_i11 = 0; c4_i11 < 2; c4_i11++) {
    (*chartInstance->c4_shiftCommand)[c4_i11] = c4_uv3[c4_i11];
  }

  *chartInstance->c4_startEngCommand = c4_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 12)), "startEngCommand");
  *chartInstance->c4_timingsIndex = c4_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 13)), "timingsIndex");
  *chartInstance->c4_timingsValue = c4_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 14)), "timingsValue");
  *chartInstance->c4_tractionTarget = c4_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 15)), "tractionTarget");
  chartInstance->c4_clutchTarget = c4_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 16)), "clutchTarget");
  chartInstance->c4_is_active_c4_GCU_CAN_C = c4_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 17)), "is_active_c4_GCU_CAN_C");
  sf_mex_assign(&chartInstance->c4_setSimStateSideEffectsInfo,
                c4_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 18)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c4_u);
  chartInstance->c4_doSetSimStateSideEffects = 1U;
  c4_update_debugger_state_c4_GCU_CAN_C(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void c4_set_sim_state_side_effects_c4_GCU_CAN_C
  (SFc4_GCU_CAN_CInstanceStruct *chartInstance)
{
  if (chartInstance->c4_doSetSimStateSideEffects != 0) {
    chartInstance->c4_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c4_GCU_CAN_C(SFc4_GCU_CAN_CInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c4_setSimStateSideEffectsInfo);
}

static void sf_gateway_c4_GCU_CAN_C(SFc4_GCU_CAN_CInstanceStruct *chartInstance)
{
  c4_set_sim_state_side_effects_c4_GCU_CAN_C(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_clutchCurrVal, 6U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_fourthInt, 5U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_thirdInt, 4U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_secondInt, 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_firstInt, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_Id, 1U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  c4_chartstep_c4_GCU_CAN_C(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
}

static void mdl_start_c4_GCU_CAN_C(SFc4_GCU_CAN_CInstanceStruct *chartInstance)
{
  c4_init_sf_message_store_memory(chartInstance);
  sim_mode_is_external(chartInstance->S);
}

static void c4_chartstep_c4_GCU_CAN_C(SFc4_GCU_CAN_CInstanceStruct
  *chartInstance)
{
  boolean_T c4_b_out;
  boolean_T c4_c_out;
  boolean_T c4_d_out;
  boolean_T c4_e_out;
  uint16_T c4_hoistedGlobal;
  uint16_T c4_com;
  boolean_T c4_f_out;
  boolean_T c4_g_out;
  int32_T c4_i12;
  boolean_T c4_covSaturation;
  uint16_T c4_u0;
  uint8_T c4_u1;
  boolean_T c4_h_out;
  uint16_T c4_u2;
  boolean_T c4_b_covSaturation;
  int32_T c4_i13;
  boolean_T c4_c_covSaturation;
  boolean_T c4_i_out;
  boolean_T c4_j_out;
  int32_T c4_i14;
  boolean_T c4_k_out;
  boolean_T c4_d_covSaturation;
  uint16_T c4_b_hoistedGlobal;
  int32_T c4_i15;
  boolean_T c4_l_out;
  int32_T c4_i16;
  uint16_T c4_b_com;
  boolean_T c4_e_covSaturation;
  uint16_T c4_u3;
  int32_T c4_i17;
  uint16_T c4_u4;
  int32_T c4_i18;
  boolean_T c4_m_out;
  uint16_T c4_u5;
  int32_T c4_i19;
  boolean_T c4_f_covSaturation;
  int32_T c4_i20;
  boolean_T c4_n_out;
  uint16_T c4_u6;
  int32_T c4_i21;
  boolean_T c4_temp;
  uint16_T c4_u7;
  int32_T c4_i22;
  boolean_T c4_b_temp;
  uint16_T c4_u8;
  boolean_T c4_o_out;
  boolean_T c4_p_out;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, chartInstance->c4_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 36U, chartInstance->c4_sfEvent);
  c4_b_out = (CV_TRANSITION_EVAL(36U, (int32_T)_SFD_CCP_CALL(5U, 36U, 0,
    (*chartInstance->c4_Id == EFI_GEAR_RPM_TPS_PH2O_ID) != 0U,
    chartInstance->c4_sfEvent)) != 0);
  if (c4_b_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 36U, chartInstance->c4_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 49U, chartInstance->c4_sfEvent);
    *chartInstance->c4_currGear = *chartInstance->c4_firstInt;
    _SFD_DATA_RANGE_CHECK_MAX((real_T)*chartInstance->c4_currGear, 8U, 5.0, 500U,
      2, 20);
    *chartInstance->c4_aac_externValues_index = c4__u16_s32_(chartInstance,
      (int32_T)aac_values_RPM, 500U, 50, 6);
    _SFD_DATA_RANGE_CHECK_MAX((real_T)*chartInstance->c4_aac_externValues_index,
      10U, 3.0, 500U, 25, 48);
    *chartInstance->c4_aac_externValue = *chartInstance->c4_secondInt;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_aac_externValue, 9U);
    sf_call_output_fcn_call(chartInstance->S, 2, "aac_updateExternValue", 0);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 41U, chartInstance->c4_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 38U,
                 chartInstance->c4_sfEvent);
    c4_c_out = (CV_TRANSITION_EVAL(38U, (int32_T)_SFD_CCP_CALL(5U, 38U, 0,
      (*chartInstance->c4_Id == SW_FIRE_GCU_ID) != 0U, chartInstance->c4_sfEvent))
                != 0);
    if (c4_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 38U, chartInstance->c4_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 50U, chartInstance->c4_sfEvent);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U,
                   chartInstance->c4_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c4_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U,
                   chartInstance->c4_sfEvent);
      c4_f_out = (CV_TRANSITION_EVAL(23U, (int32_T)_SFD_CCP_CALL(5U, 23U, 0,
        (boolean_T)CV_RELATIONAL_EVAL(5U, 23U, 0, (real_T)
        *chartInstance->c4_startEngCommand, 255.0, 0, 5U,
        *chartInstance->c4_startEngCommand >= 255) != 0U,
        chartInstance->c4_sfEvent)) != 0);
      if (c4_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c4_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c4_sfEvent);
        *chartInstance->c4_startEngCommand = 0U;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_startEngCommand, 12U);
        c4_u1 = *chartInstance->c4_startEngCommand;
        sf_mex_printf("%s =\\n", "startEngCommand");
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 9, c4_u1);
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c4_sfEvent);
        c4_i12 = c4__s32_add__(chartInstance, (int32_T)
          *chartInstance->c4_startEngCommand, 1, 290U, 35, 1);
        c4_covSaturation = false;
        if (c4_i12 < 0) {
          c4_covSaturation = true;
          c4_i12 = 0;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 290U, 35U, 1U);
        } else {
          if (c4_i12 > 255) {
            c4_i12 = 255;
            _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 290U, 35U, 1U);
          }

          CV_SATURATION_EVAL(5, 24, 0, 0, c4_covSaturation);
        }

        *chartInstance->c4_startEngCommand = (uint8_T)c4_i12;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_startEngCommand, 12U);
      }

      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c4_sfEvent);
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 37U, chartInstance->c4_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 39U,
                   chartInstance->c4_sfEvent);
      c4_d_out = (CV_TRANSITION_EVAL(39U, (int32_T)_SFD_CCP_CALL(5U, 39U, 0,
        (*chartInstance->c4_Id == SW_GEARSHIFT_ID) != 0U,
        chartInstance->c4_sfEvent)) != 0);
      if (c4_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 39U, chartInstance->c4_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 51U, chartInstance->c4_sfEvent);
        c4_hoistedGlobal = *chartInstance->c4_firstInt;
        c4_com = c4_hoistedGlobal;
        _SFD_DATA_RANGE_CHECK((real_T)c4_com, 34U);
        _SFD_SET_DATA_VALUE_PTR(34U, (void *)&c4_com);
        _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
        _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("com", &c4_com, c4_b_sf_marshallOut,
          c4_c_sf_marshallIn);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U,
                     chartInstance->c4_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c4_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                     chartInstance->c4_sfEvent);
        c4_i_out = (CV_TRANSITION_EVAL(14U, (int32_T)_SFD_CCP_CALL(5U, 14U, 0,
          (boolean_T)CV_RELATIONAL_EVAL(5U, 14U, 0, (real_T)
          (*chartInstance->c4_shiftCommand)[0], 255.0, 0, 5U,
          (*chartInstance->c4_shiftCommand)[0] >= 255) != 0U,
          chartInstance->c4_sfEvent)) != 0);
        if (c4_i_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c4_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c4_sfEvent);
          (*chartInstance->c4_shiftCommand)[0] = 0U;
          for (c4_i15 = 0; c4_i15 < 2; c4_i15++) {
            _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_shiftCommand)
                                  [c4_i15], 11U);
          }

          c4_u3 = (*chartInstance->c4_shiftCommand)[0];
          sf_mex_printf("%s =\\n", "shiftCommand[0]");
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11,
                            c4_u3);
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c4_sfEvent);
          c4_i14 = (*chartInstance->c4_shiftCommand)[0] + 1;
          c4_d_covSaturation = false;
          if (c4_i14 < 0) {
            c4_d_covSaturation = true;
            c4_i14 = 0;
            _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 219U, 35U, 1U);
          } else {
            if (c4_i14 > 65535) {
              c4_i14 = 65535;
              _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 219U, 35U, 1U);
            }

            CV_SATURATION_EVAL(5, 15, 0, 0, c4_d_covSaturation);
          }

          (*chartInstance->c4_shiftCommand)[0] = (uint16_T)c4_i14;
          for (c4_i17 = 0; c4_i17 < 2; c4_i17++) {
            _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_shiftCommand)
                                  [c4_i17], 11U);
          }

          c4_u4 = (*chartInstance->c4_shiftCommand)[0];
          sf_mex_printf("%s =\\n", "shiftCommand[0]");
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11,
                            c4_u4);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c4_sfEvent);
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c4_sfEvent);
        (*chartInstance->c4_shiftCommand)[1] = c4_com;
        for (c4_i18 = 0; c4_i18 < 2; c4_i18++) {
          _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_shiftCommand)[c4_i18],
                                11U);
        }

        c4_u5 = (*chartInstance->c4_shiftCommand)[1];
        sf_mex_printf("%s =\\n", "shiftCommand[1]");
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11, c4_u5);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U,
                     chartInstance->c4_sfEvent);
        c4_n_out = (CV_TRANSITION_EVAL(19U, (int32_T)_SFD_CCP_CALL(5U, 19U, 0,
          (boolean_T)CV_RELATIONAL_EVAL(5U, 19U, 0, (real_T)
          *chartInstance->c4_clutchCurrVal, 100.0, 0, 1U,
          *chartInstance->c4_clutchCurrVal != 100) != 0U,
          chartInstance->c4_sfEvent)) != 0);
        if (c4_n_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c4_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c4_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 26U,
                       chartInstance->c4_sfEvent);
          c4_temp = _SFD_CCP_CALL(5U, 26U, 0, (boolean_T)CV_RELATIONAL_EVAL(5U,
            26U, 0, (real_T)c4_com, (real_T)c4_const_GEAR_COMMAND_NEUTRAL_UP, 0,
            0U, c4_com == c4_const_GEAR_COMMAND_NEUTRAL_UP) != 0U,
            chartInstance->c4_sfEvent);
          if (!c4_temp) {
            c4_temp = _SFD_CCP_CALL(5U, 26U, 1, (boolean_T)CV_RELATIONAL_EVAL(5U,
              26U, 1, (real_T)c4_com, (real_T)c4_const_GEAR_COMMAND_NEUTRAL_DOWN,
              0, 0U, c4_com == c4_const_GEAR_COMMAND_NEUTRAL_DOWN) != 0U,
              chartInstance->c4_sfEvent);
          }

          c4_b_temp = c4_temp;
          if (!c4_b_temp) {
            c4_b_temp = _SFD_CCP_CALL(5U, 26U, 2, (boolean_T)CV_RELATIONAL_EVAL
              (5U, 26U, 2, (real_T)c4_com, (real_T)c4_const_GEAR_COMMAND_DOWN, 0,
               0U, c4_com == c4_const_GEAR_COMMAND_DOWN) != 0U,
              chartInstance->c4_sfEvent);
          }

          c4_o_out = (CV_TRANSITION_EVAL(26U, (int32_T)c4_b_temp) != 0);
          if (c4_o_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, chartInstance->c4_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, chartInstance->c4_sfEvent);
            c4_sendAccCommand(chartInstance, c4_const_STOP_COM);
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, chartInstance->c4_sfEvent);
          }
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c4_sfEvent);
        }

        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
        _SFD_UNSET_DATA_VALUE_PTR(34U);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c4_sfEvent);
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 40U, chartInstance->c4_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 47U,
                     chartInstance->c4_sfEvent);
        c4_e_out = (CV_TRANSITION_EVAL(47U, (int32_T)_SFD_CCP_CALL(5U, 47U, 0, (*
          chartInstance->c4_Id == EFI_TRACTION_CONTROL_ID) != 0U,
          chartInstance->c4_sfEvent)) != 0);
        if (c4_e_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 47U, chartInstance->c4_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 52U, chartInstance->c4_sfEvent);
          *chartInstance->c4_aac_externValues_index = c4__u16_s32_(chartInstance,
            (int32_T)aac_values_WHEEL_SPEED, 510U, 27, 6);
          _SFD_DATA_RANGE_CHECK_MAX((real_T)
            *chartInstance->c4_aac_externValues_index, 10U, 3.0, 510U, 2, 56);
          c4_u0 = *chartInstance->c4_aac_externValues_index;
          sf_mex_printf("%s =\\n", "aac_externValues_index");
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11,
                            c4_u0);
          c4_i13 = (int32_T)((uint32_T)*chartInstance->c4_firstInt / 10U);
          c4_c_covSaturation = false;
          if (c4_i13 < 0) {
            c4_c_covSaturation = true;
            c4_i13 = 0;
            _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 510U, 86U, 1U);
          } else {
            if (c4_i13 > 65535) {
              c4_i13 = 65535;
              _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 510U, 86U, 1U);
            }

            CV_SATURATION_EVAL(5, 52, 0, 0, c4_c_covSaturation);
          }

          *chartInstance->c4_aac_externValue = (uint16_T)c4_i13;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_aac_externValue, 9U);
          sf_call_output_fcn_call(chartInstance->S, 2, "aac_updateExternValue",
            0);
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 46U, chartInstance->c4_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 42U,
                       chartInstance->c4_sfEvent);
          c4_g_out = (CV_TRANSITION_EVAL(42U, (int32_T)_SFD_CCP_CALL(5U, 42U, 0,
            (*chartInstance->c4_Id == SW_CLUTCH_MODE_MAP_GCU_ID) != 0U,
            chartInstance->c4_sfEvent)) != 0);
          if (c4_g_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 42U, chartInstance->c4_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 53U, chartInstance->c4_sfEvent);
            c4_u2 = *chartInstance->c4_firstInt;
            c4_b_covSaturation = false;
            if (c4_u2 > 255) {
              c4_b_covSaturation = true;
              c4_u2 = 255U;
              _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 513U, 16U, 8U);
            }

            CV_SATURATION_EVAL(5, 53, 0, 0, c4_b_covSaturation);
            chartInstance->c4_clutchTarget = (uint8_T)c4_u2;
            _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c4_clutchTarget, 0U);
            c4_b_hoistedGlobal = *chartInstance->c4_secondInt;
            c4_b_com = c4_b_hoistedGlobal;
            _SFD_DATA_RANGE_CHECK((real_T)c4_b_com, 32U);
            _SFD_SET_DATA_VALUE_PTR(32U, (void *)&c4_b_com);
            _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
            _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("com", &c4_b_com,
              c4_b_sf_marshallOut, c4_c_sf_marshallIn);
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                         chartInstance->c4_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, chartInstance->c4_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 30U,
                         chartInstance->c4_sfEvent);
            c4_m_out = (CV_TRANSITION_EVAL(30U, (int32_T)_SFD_CCP_CALL(5U, 30U,
              0, (boolean_T)CV_RELATIONAL_EVAL(5U, 30U, 0, (real_T)
              (*chartInstance->c4_modeCommand)[0], 255.0, 0, 5U,
              (*chartInstance->c4_modeCommand)[0] >= 255) != 0U,
              chartInstance->c4_sfEvent)) != 0);
            if (c4_m_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c4_sfEvent);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, chartInstance->c4_sfEvent);
              (*chartInstance->c4_modeCommand)[0] = 0U;
              for (c4_i20 = 0; c4_i20 < 2; c4_i20++) {
                _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_modeCommand)
                                      [c4_i20], 16U);
              }

              c4_u6 = (*chartInstance->c4_modeCommand)[0];
              sf_mex_printf("%s =\\n", "modeCommand[0]");
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11,
                                c4_u6);
            } else {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, chartInstance->c4_sfEvent);
              c4_i19 = (*chartInstance->c4_modeCommand)[0] + 1;
              c4_f_covSaturation = false;
              if (c4_i19 < 0) {
                c4_f_covSaturation = true;
                c4_i19 = 0;
                _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 332U, 33U, 1U);
              } else {
                if (c4_i19 > 65535) {
                  c4_i19 = 65535;
                  _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 332U, 33U, 1U);
                }

                CV_SATURATION_EVAL(5, 31, 0, 0, c4_f_covSaturation);
              }

              (*chartInstance->c4_modeCommand)[0] = (uint16_T)c4_i19;
              for (c4_i21 = 0; c4_i21 < 2; c4_i21++) {
                _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_modeCommand)
                                      [c4_i21], 16U);
              }

              c4_u7 = (*chartInstance->c4_modeCommand)[0];
              sf_mex_printf("%s =\\n", "modeCommand[0]");
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11,
                                c4_u7);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U, chartInstance->c4_sfEvent);
            }

            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, chartInstance->c4_sfEvent);
            (*chartInstance->c4_modeCommand)[1] = c4_b_com;
            for (c4_i22 = 0; c4_i22 < 2; c4_i22++) {
              _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_modeCommand)
                                    [c4_i22], 16U);
            }

            c4_u8 = (*chartInstance->c4_modeCommand)[1];
            sf_mex_printf("%s =\\n", "modeCommand[1]");
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11,
                              c4_u8);
            _SFD_SYMBOL_SCOPE_POP();
            _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
            _SFD_UNSET_DATA_VALUE_PTR(32U);
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U,
                         chartInstance->c4_sfEvent);
            *chartInstance->c4_mapTarget = *chartInstance->c4_thirdInt;
            _SFD_DATA_RANGE_CHECK_MAX((real_T)*chartInstance->c4_mapTarget, 21U,
              5.0, 513U, 56, 21);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 57U,
                         chartInstance->c4_sfEvent);
            c4_p_out = (CV_TRANSITION_EVAL(57U, (int32_T)_SFD_CCP_CALL(5U, 57U,
              0, (boolean_T)CV_RELATIONAL_EVAL(5U, 57U, 0, (real_T)
              chartInstance->c4_clutchTarget, (real_T)
              c4_const_ACC_CLUTCH_NOISE_LEVEL, 0, 4U,
              chartInstance->c4_clutchTarget > c4_const_ACC_CLUTCH_NOISE_LEVEL)
              != 0U, chartInstance->c4_sfEvent)) != 0);
            if (c4_p_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 57U, chartInstance->c4_sfEvent);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 55U, chartInstance->c4_sfEvent);
              c4_sendAccCommand(chartInstance, c4_const_STOP_COM);
            } else {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 59U, chartInstance->c4_sfEvent);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 56U, chartInstance->c4_sfEvent);
            }

            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 58U, chartInstance->c4_sfEvent);
            c4_sendClutchCommand(chartInstance, (uint16_T)
                                 chartInstance->c4_clutchTarget);
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 44U, chartInstance->c4_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 45U,
                         chartInstance->c4_sfEvent);
            c4_h_out = (CV_TRANSITION_EVAL(45U, (int32_T)_SFD_CCP_CALL(5U, 45U,
              0, (*chartInstance->c4_Id == SW_OK_BUTTON_GCU_ID) != 0U,
              chartInstance->c4_sfEvent)) != 0);
            if (c4_h_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 45U, chartInstance->c4_sfEvent);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 60U, chartInstance->c4_sfEvent);
              c4_sendAccCommand(chartInstance, *chartInstance->c4_firstInt);
              _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 63U,
                           chartInstance->c4_sfEvent);
              c4_k_out = (CV_TRANSITION_EVAL(63U, (int32_T)_SFD_CCP_CALL(5U, 63U,
                0, (boolean_T)CV_RELATIONAL_EVAL(5U, 63U, 0, (real_T)
                (*chartInstance->c4_accCommand)[1], (real_T)c4_const_STOP_COM, 0,
                0U, (*chartInstance->c4_accCommand)[1] == c4_const_STOP_COM) !=
                0U, chartInstance->c4_sfEvent)) != 0);
              if (c4_k_out) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 63U,
                             chartInstance->c4_sfEvent);
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 61U,
                             chartInstance->c4_sfEvent);
                c4_sendClutchCommand(chartInstance, 0U);
              } else {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 62U,
                             chartInstance->c4_sfEvent);
              }
            } else {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 48U, chartInstance->c4_sfEvent);
              _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 43U,
                           chartInstance->c4_sfEvent);
              c4_j_out = (CV_TRANSITION_EVAL(43U, (int32_T)_SFD_CCP_CALL(5U, 43U,
                0, (*chartInstance->c4_Id == SW_TRACTION_LIMITER_GCU_ID) != 0U,
                chartInstance->c4_sfEvent)) != 0);
              if (c4_j_out) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 43U,
                             chartInstance->c4_sfEvent);
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 54U,
                             chartInstance->c4_sfEvent);
                c4_i16 = *chartInstance->c4_firstInt * 100;
                c4_e_covSaturation = false;
                if (c4_i16 < 0) {
                  c4_e_covSaturation = true;
                  c4_i16 = 0;
                  _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 517U, 35U, 1U);
                } else {
                  if (c4_i16 > 65535) {
                    c4_i16 = 65535;
                    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 517U, 35U, 1U);
                  }

                  CV_SATURATION_EVAL(5, 54, 0, 0, c4_e_covSaturation);
                }

                *chartInstance->c4_tractionTarget = (uint16_T)c4_i16;
                _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c4_tractionTarget,
                                      14U);
              } else {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 64U,
                             chartInstance->c4_sfEvent);
                _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 65U,
                             chartInstance->c4_sfEvent);
                c4_l_out = (CV_TRANSITION_EVAL(65U, (int32_T)_SFD_CCP_CALL(5U,
                  65U, 0, (*chartInstance->c4_Id == DCU_AUTOGEARSHIFT_GCU_ID) !=
                  0U, chartInstance->c4_sfEvent)) != 0);
                if (c4_l_out) {
                  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 65U,
                               chartInstance->c4_sfEvent);
                  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 66U,
                               chartInstance->c4_sfEvent);
                } else {
                  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 67U,
                               chartInstance->c4_sfEvent);
                }
              }
            }
          }
        }
      }
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
}

static void initSimStructsc4_GCU_CAN_C(SFc4_GCU_CAN_CInstanceStruct
  *chartInstance)
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

const mxArray *sf_c4_GCU_CAN_C_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static void c4_sendClutchCommand(SFc4_GCU_CAN_CInstanceStruct *chartInstance,
  uint16_T c4_com)
{
  boolean_T c4_b_out;
  int32_T c4_i23;
  boolean_T c4_covSaturation;
  int32_T c4_i24;
  uint8_T c4_u9;
  int32_T c4_i25;
  uint16_T c4_u10;
  uint8_T c4_u11;
  boolean_T c4_b_covSaturation;
  int32_T c4_i26;
  uint8_T c4_u12;
  _SFD_DATA_RANGE_CHECK((real_T)c4_com, 35U);
  _SFD_SET_DATA_VALUE_PTR(35U, (void *)&c4_com);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("com", &c4_com, c4_b_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c4_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c4_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c4_sfEvent);
  c4_b_out = (CV_TRANSITION_EVAL(8U, (int32_T)_SFD_CCP_CALL(5U, 8U, 0,
    (boolean_T)CV_RELATIONAL_EVAL(5U, 8U, 0, (real_T)
    (*chartInstance->c4_clutchCommand)[0], 255.0, 0, 5U,
    (*chartInstance->c4_clutchCommand)[0] >= 255) != 0U,
    chartInstance->c4_sfEvent)) != 0);
  if (c4_b_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
    (*chartInstance->c4_clutchCommand)[0] = 0U;
    for (c4_i24 = 0; c4_i24 < 2; c4_i24++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_clutchCommand)[c4_i24],
                            15U);
    }

    c4_u9 = (*chartInstance->c4_clutchCommand)[0];
    sf_mex_printf("%s =\\n", "clutchCommand[0]");
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 9, c4_u9);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
    c4_i23 = (*chartInstance->c4_clutchCommand)[0] + 1;
    c4_covSaturation = false;
    if (c4_i23 < 0) {
      c4_covSaturation = true;
      c4_i23 = 0;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 195U, 37U, 1U);
    } else {
      if (c4_i23 > 255) {
        c4_i23 = 255;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 195U, 37U, 1U);
      }

      CV_SATURATION_EVAL(5, 9, 0, 0, c4_covSaturation);
    }

    (*chartInstance->c4_clutchCommand)[0] = (uint8_T)c4_i23;
    for (c4_i25 = 0; c4_i25 < 2; c4_i25++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_clutchCommand)[c4_i25],
                            15U);
    }

    c4_u11 = (*chartInstance->c4_clutchCommand)[0];
    sf_mex_printf("%s =\\n", "clutchCommand[0]");
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 9, c4_u11);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
  c4_u10 = c4_com;
  c4_b_covSaturation = false;
  if (c4_u10 > 255) {
    c4_b_covSaturation = true;
    c4_u10 = 255U;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 199U, 20U, 3U);
  }

  CV_SATURATION_EVAL(5, 12, 0, 0, c4_b_covSaturation);
  (*chartInstance->c4_clutchCommand)[1] = (uint8_T)c4_u10;
  for (c4_i26 = 0; c4_i26 < 2; c4_i26++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_clutchCommand)[c4_i26],
                          15U);
  }

  c4_u12 = (*chartInstance->c4_clutchCommand)[1];
  sf_mex_printf("%s =\\n", "clutchCommand[1]");
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 9, c4_u12);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(35U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c4_sfEvent);
}

static void c4_sendAccCommand(SFc4_GCU_CAN_CInstanceStruct *chartInstance,
  uint16_T c4_com)
{
  boolean_T c4_b_out;
  int32_T c4_i27;
  boolean_T c4_covSaturation;
  int32_T c4_i28;
  uint16_T c4_u13;
  int32_T c4_i29;
  uint16_T c4_u14;
  int32_T c4_i30;
  uint16_T c4_u15;
  _SFD_DATA_RANGE_CHECK((real_T)c4_com, 33U);
  _SFD_SET_DATA_VALUE_PTR(33U, (void *)&c4_com);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("com", &c4_com, c4_b_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c4_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c4_sfEvent);
  c4_b_out = (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(5U, 1U, 0,
    (boolean_T)CV_RELATIONAL_EVAL(5U, 1U, 0, (real_T)
    (*chartInstance->c4_accCommand)[0], 255.0, 0, 5U,
    (*chartInstance->c4_accCommand)[0] >= 255) != 0U, chartInstance->c4_sfEvent))
              != 0);
  if (c4_b_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
    (*chartInstance->c4_accCommand)[0] = 0U;
    for (c4_i28 = 0; c4_i28 < 2; c4_i28++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_accCommand)[c4_i28], 13U);
    }

    c4_u13 = (*chartInstance->c4_accCommand)[0];
    sf_mex_printf("%s =\\n", "accCommand[0]");
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11, c4_u13);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
    c4_i27 = (*chartInstance->c4_accCommand)[0] + 1;
    c4_covSaturation = false;
    if (c4_i27 < 0) {
      c4_covSaturation = true;
      c4_i27 = 0;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 172U, 31U, 1U);
    } else {
      if (c4_i27 > 65535) {
        c4_i27 = 65535;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 172U, 31U, 1U);
      }

      CV_SATURATION_EVAL(5, 3, 0, 0, c4_covSaturation);
    }

    (*chartInstance->c4_accCommand)[0] = (uint16_T)c4_i27;
    for (c4_i29 = 0; c4_i29 < 2; c4_i29++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_accCommand)[c4_i29], 13U);
    }

    c4_u14 = (*chartInstance->c4_accCommand)[0];
    sf_mex_printf("%s =\\n", "accCommand[0]");
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11, c4_u14);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
  (*chartInstance->c4_accCommand)[1] = c4_com;
  for (c4_i30 = 0; c4_i30 < 2; c4_i30++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_accCommand)[c4_i30], 13U);
  }

  c4_u15 = (*chartInstance->c4_accCommand)[1];
  sf_mex_printf("%s =\\n", "accCommand[1]");
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11, c4_u15);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(33U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c4_sfEvent);
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_GCU_CAN_CInstanceStruct *chartInstance;
  chartInstance = (SFc4_GCU_CAN_CInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_emlrt_marshallIn(SFc4_GCU_CAN_CInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i31;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i31, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i31;
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
  SFc4_GCU_CAN_CInstanceStruct *chartInstance;
  chartInstance = (SFc4_GCU_CAN_CInstanceStruct *)chartInstanceVoid;
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
  SFc4_GCU_CAN_CInstanceStruct *chartInstance;
  chartInstance = (SFc4_GCU_CAN_CInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(uint16_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_GCU_CAN_CInstanceStruct *chartInstance;
  chartInstance = (SFc4_GCU_CAN_CInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_b_emlrt_marshallIn(SFc4_GCU_CAN_CInstanceStruct *chartInstance,
  const mxArray *c4_b_out, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_out), &c4_thisId);
  sf_mex_destroy(&c4_b_out);
  return c4_y;
}

static real_T c4_c_emlrt_marshallIn(SFc4_GCU_CAN_CInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_out;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_GCU_CAN_CInstanceStruct *chartInstance;
  chartInstance = (SFc4_GCU_CAN_CInstanceStruct *)chartInstanceVoid;
  c4_b_out = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_out), &c4_thisId);
  sf_mex_destroy(&c4_b_out);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint16_T c4_d_emlrt_marshallIn(SFc4_GCU_CAN_CInstanceStruct
  *chartInstance, const mxArray *c4_b_currGear, const char_T *c4_identifier)
{
  uint16_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_currGear),
    &c4_thisId);
  sf_mex_destroy(&c4_b_currGear);
  return c4_y;
}

static uint16_T c4_e_emlrt_marshallIn(SFc4_GCU_CAN_CInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint16_T c4_y;
  uint16_T c4_u16;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u16, 1, 5, 0U, 0, 0U, 0);
  c4_y = c4_u16;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_currGear;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  uint16_T c4_y;
  SFc4_GCU_CAN_CInstanceStruct *chartInstance;
  chartInstance = (SFc4_GCU_CAN_CInstanceStruct *)chartInstanceVoid;
  c4_b_currGear = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_currGear),
    &c4_thisId);
  sf_mex_destroy(&c4_b_currGear);
  *(uint16_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_i32;
  const mxArray *c4_y = NULL;
  uint16_T c4_u[2];
  SFc4_GCU_CAN_CInstanceStruct *chartInstance;
  chartInstance = (SFc4_GCU_CAN_CInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  for (c4_i32 = 0; c4_i32 < 2; c4_i32++) {
    c4_u[c4_i32] = (*(uint16_T (*)[2])c4_inData)[c4_i32];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 5, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_f_emlrt_marshallIn(SFc4_GCU_CAN_CInstanceStruct *chartInstance,
  const mxArray *c4_b_shiftCommand, const char_T *c4_identifier, uint16_T c4_y[2])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_shiftCommand), &c4_thisId,
                        c4_y);
  sf_mex_destroy(&c4_b_shiftCommand);
}

static void c4_g_emlrt_marshallIn(SFc4_GCU_CAN_CInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, uint16_T c4_y[2])
{
  uint16_T c4_uv4[2];
  int32_T c4_i33;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_uv4, 1, 5, 0U, 1, 0U, 2, 1, 2);
  for (c4_i33 = 0; c4_i33 < 2; c4_i33++) {
    c4_y[c4_i33] = c4_uv4[c4_i33];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_shiftCommand;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  uint16_T c4_y[2];
  int32_T c4_i34;
  SFc4_GCU_CAN_CInstanceStruct *chartInstance;
  chartInstance = (SFc4_GCU_CAN_CInstanceStruct *)chartInstanceVoid;
  c4_b_shiftCommand = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_shiftCommand), &c4_thisId,
                        c4_y);
  sf_mex_destroy(&c4_b_shiftCommand);
  for (c4_i34 = 0; c4_i34 < 2; c4_i34++) {
    (*(uint16_T (*)[2])c4_outData)[c4_i34] = c4_y[c4_i34];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  uint8_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_GCU_CAN_CInstanceStruct *chartInstance;
  chartInstance = (SFc4_GCU_CAN_CInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(uint8_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static uint8_T c4_h_emlrt_marshallIn(SFc4_GCU_CAN_CInstanceStruct *chartInstance,
  const mxArray *c4_b_startEngCommand, const char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_startEngCommand),
    &c4_thisId);
  sf_mex_destroy(&c4_b_startEngCommand);
  return c4_y;
}

static uint8_T c4_i_emlrt_marshallIn(SFc4_GCU_CAN_CInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u17;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u17, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u17;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_startEngCommand;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  uint8_T c4_y;
  SFc4_GCU_CAN_CInstanceStruct *chartInstance;
  chartInstance = (SFc4_GCU_CAN_CInstanceStruct *)chartInstanceVoid;
  c4_b_startEngCommand = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_startEngCommand),
    &c4_thisId);
  sf_mex_destroy(&c4_b_startEngCommand);
  *(uint8_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_i35;
  const mxArray *c4_y = NULL;
  uint8_T c4_u[2];
  SFc4_GCU_CAN_CInstanceStruct *chartInstance;
  chartInstance = (SFc4_GCU_CAN_CInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  for (c4_i35 = 0; c4_i35 < 2; c4_i35++) {
    c4_u[c4_i35] = (*(uint8_T (*)[2])c4_inData)[c4_i35];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 3, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_j_emlrt_marshallIn(SFc4_GCU_CAN_CInstanceStruct *chartInstance,
  const mxArray *c4_b_clutchCommand, const char_T *c4_identifier, uint8_T c4_y[2])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_clutchCommand),
                        &c4_thisId, c4_y);
  sf_mex_destroy(&c4_b_clutchCommand);
}

static void c4_k_emlrt_marshallIn(SFc4_GCU_CAN_CInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, uint8_T c4_y[2])
{
  uint8_T c4_uv5[2];
  int32_T c4_i36;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_uv5, 1, 3, 0U, 1, 0U, 2, 1, 2);
  for (c4_i36 = 0; c4_i36 < 2; c4_i36++) {
    c4_y[c4_i36] = c4_uv5[c4_i36];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_clutchCommand;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  uint8_T c4_y[2];
  int32_T c4_i37;
  SFc4_GCU_CAN_CInstanceStruct *chartInstance;
  chartInstance = (SFc4_GCU_CAN_CInstanceStruct *)chartInstanceVoid;
  c4_b_clutchCommand = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_clutchCommand),
                        &c4_thisId, c4_y);
  sf_mex_destroy(&c4_b_clutchCommand);
  for (c4_i37 = 0; c4_i37 < 2; c4_i37++) {
    (*(uint8_T (*)[2])c4_outData)[c4_i37] = c4_y[c4_i37];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_l_emlrt_marshallIn(SFc4_GCU_CAN_CInstanceStruct
  *chartInstance, const mxArray *c4_b_setSimStateSideEffectsInfo, const char_T
  *c4_identifier)
{
  const mxArray *c4_y = NULL;
  emlrtMsgIdentifier c4_thisId;
  c4_y = NULL;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  sf_mex_assign(&c4_y, c4_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_setSimStateSideEffectsInfo), &c4_thisId), false);
  sf_mex_destroy(&c4_b_setSimStateSideEffectsInfo);
  return c4_y;
}

static const mxArray *c4_m_emlrt_marshallIn(SFc4_GCU_CAN_CInstanceStruct
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

static const mxArray *sf_get_hover_data_for_msg(SFc4_GCU_CAN_CInstanceStruct
  *chartInstance, int32_T c4_ssid)
{
  (void)chartInstance;
  (void)c4_ssid;
  return NULL;
}

static void c4_init_sf_message_store_memory(SFc4_GCU_CAN_CInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static uint16_T c4__u16_s32_(SFc4_GCU_CAN_CInstanceStruct *chartInstance,
  int32_T c4_b, uint32_T c4_ssid_src_loc, int32_T c4_offset_src_loc, int32_T
  c4_length_src_loc)
{
  uint16_T c4_a;
  (void)chartInstance;
  c4_a = (uint16_T)c4_b;
  if (c4_a != c4_b) {
    _SFD_OVERFLOW_DETECTION(SFDB_OVERFLOW, c4_ssid_src_loc, c4_offset_src_loc,
      c4_length_src_loc);
  }

  return c4_a;
}

static int32_T c4__s32_add__(SFc4_GCU_CAN_CInstanceStruct *chartInstance,
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

static void init_dsm_address_info(SFc4_GCU_CAN_CInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc4_GCU_CAN_CInstanceStruct *chartInstance)
{
  chartInstance->c4_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c4_Id = (uint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c4_firstInt = (uint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c4_secondInt = (uint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c4_thirdInt = (uint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c4_fourthInt = (uint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c4_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c4_currGear = (uint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c4_aac_externValue = (uint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c4_aac_externValues_index = (uint16_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 4);
  chartInstance->c4_shiftCommand = (uint16_T (*)[2])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 5);
  chartInstance->c4_startEngCommand = (uint8_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c4_accCommand = (uint16_T (*)[2])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c4_tractionTarget = (uint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c4_clutchCommand = (uint8_T (*)[2])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 9);
  chartInstance->c4_clutchCurrVal = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c4_modeCommand = (uint16_T (*)[2])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 10);
  chartInstance->c4_accParametersValue = (uint16_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 11);
  chartInstance->c4_accParametersIndex = (uint16_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 12);
  chartInstance->c4_timingsValue = (uint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 13);
  chartInstance->c4_timingsIndex = (uint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 14);
  chartInstance->c4_mapTarget = (uint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 15);
  chartInstance->c4_rpmLimiterTarget = (uint16_T *)ssGetOutputPortSignal_wrapper
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

void sf_c4_GCU_CAN_C_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3055712096U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3726283150U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1942969129U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2084196452U);
}

mxArray* sf_c4_GCU_CAN_C_get_post_codegen_info(void);
mxArray *sf_c4_GCU_CAN_C_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("1m2jHkGJvkq7lclcFracrG");
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
    mxArray* mxPostCodegenInfo = sf_c4_GCU_CAN_C_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_GCU_CAN_C_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_GCU_CAN_C_jit_fallback_info(void)
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

mxArray *sf_c4_GCU_CAN_C_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c4_GCU_CAN_C_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c4_GCU_CAN_C(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[104],T\"aac_externValue\",},{M[1],M[103],T\"aac_externValues_index\",},{M[1],M[162],T\"accCommand\",},{M[1],M[362],T\"accParametersIndex\",},{M[1],M[361],T\"accParametersValue\",},{M[1],M[184],T\"clutchCommand\",},{M[1],M[102],T\"currGear\",},{M[1],M[373],T\"mapTarget\",},{M[1],M[337],T\"modeCommand\",},{M[1],M[94],T\"out\",}}",
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[583],T\"rpmLimiterTarget\",},{M[1],M[131],T\"shiftCommand\",},{M[1],M[161],T\"startEngCommand\",},{M[1],M[364],T\"timingsIndex\",},{M[1],M[363],T\"timingsValue\",},{M[1],M[183],T\"tractionTarget\",},{M[3],M[578],T\"clutchTarget\",},{M[8],M[0],T\"is_active_c4_GCU_CAN_C\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 18, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_GCU_CAN_C_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc4_GCU_CAN_CInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_GCU_CAN_CInstanceStruct *chartInstance = (SFc4_GCU_CAN_CInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _GCU_CAN_CMachineNumber_,
           4,
           13,
           68,
           0,
           36,
           3,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_GCU_CAN_CMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_GCU_CAN_CMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _GCU_CAN_CMachineNumber_,
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
          _SFD_SET_DATA_PROPS(9,2,0,1,"aac_externValue");
          _SFD_SET_DATA_PROPS(10,2,0,1,"aac_externValues_index");
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
          _SFD_SET_DATA_PROPS(31,7,0,0,"STOP_COM");
          _SFD_SET_DATA_PROPS(32,8,0,0,"");
          _SFD_SET_DATA_PROPS(33,8,0,0,"");
          _SFD_SET_DATA_PROPS(34,8,0,0,"");
          _SFD_SET_DATA_PROPS(35,8,0,0,"");
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

          static int sRelationalopType[] = { 5 };

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

          static int sRelationalopType[] = { 5 };

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

          static int sRelationalopType[] = { 1 };

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

          static int sRelationalopType[] = { 0, 0, 0 };

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

          static int sRelationalopType[] = { 5 };

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

          static int sRelationalopType[] = { 4 };

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

          static int sRelationalopType[] = { 5 };

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

          static unsigned int sEndGuardMap[] = { 26 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(63,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 26 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(63,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
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

          static int sRelationalopType[] = { 5 };

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
          (MexFcnForType)c4_e_sf_marshallOut,(MexInFcnForType)c4_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_UINT16,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_d_sf_marshallOut,(MexInFcnForType)
            c4_d_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(12,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_e_sf_marshallOut,(MexInFcnForType)c4_e_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(13,SF_UINT16,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_d_sf_marshallOut,(MexInFcnForType)
            c4_d_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(14,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(15,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_f_sf_marshallOut,(MexInFcnForType)
            c4_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(16,SF_UINT16,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_d_sf_marshallOut,(MexInFcnForType)
            c4_d_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(17,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(30,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(31,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(32,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(33,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(34,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(35,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_c_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(32,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(33,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(34,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(35,(void *)(NULL));
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _GCU_CAN_CMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_GCU_CAN_CInstanceStruct *chartInstance = (SFc4_GCU_CAN_CInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c4_Id);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c4_firstInt);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c4_secondInt);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c4_thirdInt);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)chartInstance->c4_fourthInt);
        _SFD_SET_DATA_VALUE_PTR(7U, (void *)chartInstance->c4_out);
        _SFD_SET_DATA_VALUE_PTR(8U, (void *)chartInstance->c4_currGear);
        _SFD_SET_DATA_VALUE_PTR(9U, (void *)chartInstance->c4_aac_externValue);
        _SFD_SET_DATA_VALUE_PTR(10U, (void *)
          chartInstance->c4_aac_externValues_index);
        _SFD_SET_DATA_VALUE_PTR(11U, (void *)chartInstance->c4_shiftCommand);
        _SFD_SET_DATA_VALUE_PTR(12U, (void *)chartInstance->c4_startEngCommand);
        _SFD_SET_DATA_VALUE_PTR(13U, (void *)chartInstance->c4_accCommand);
        _SFD_SET_DATA_VALUE_PTR(14U, (void *)chartInstance->c4_tractionTarget);
        _SFD_SET_DATA_VALUE_PTR(15U, (void *)chartInstance->c4_clutchCommand);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)chartInstance->c4_clutchCurrVal);
        _SFD_SET_DATA_VALUE_PTR(16U, (void *)chartInstance->c4_modeCommand);
        _SFD_SET_DATA_VALUE_PTR(17U, (void *)
          chartInstance->c4_accParametersValue);
        _SFD_SET_DATA_VALUE_PTR(18U, (void *)
          chartInstance->c4_accParametersIndex);
        _SFD_SET_DATA_VALUE_PTR(19U, (void *)chartInstance->c4_timingsValue);
        _SFD_SET_DATA_VALUE_PTR(20U, (void *)chartInstance->c4_timingsIndex);
        _SFD_SET_DATA_VALUE_PTR(21U, (void *)chartInstance->c4_mapTarget);
        _SFD_SET_DATA_VALUE_PTR(22U, (void *)chartInstance->c4_rpmLimiterTarget);
        _SFD_SET_DATA_VALUE_PTR(23U, (void *)&chartInstance->c4_STOP_COM);
        _SFD_SET_DATA_VALUE_PTR(27U, (void *)&chartInstance->c4_b_STOP_COM);
        _SFD_SET_DATA_VALUE_PTR(25U, (void *)
          &chartInstance->c4_GEAR_COMMAND_NEUTRAL_DOWN);
        _SFD_SET_DATA_VALUE_PTR(26U, (void *)
          &chartInstance->c4_GEAR_COMMAND_NEUTRAL_UP);
        _SFD_SET_DATA_VALUE_PTR(24U, (void *)
          &chartInstance->c4_GEAR_COMMAND_DOWN);
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)&chartInstance->c4_clutchTarget);
        _SFD_SET_DATA_VALUE_PTR(29U, (void *)&chartInstance->c4_c_STOP_COM);
        _SFD_SET_DATA_VALUE_PTR(28U, (void *)
          &chartInstance->c4_ACC_CLUTCH_NOISE_LEVEL);
        _SFD_SET_DATA_VALUE_PTR(30U, (void *)&chartInstance->c4_d_STOP_COM);
        _SFD_SET_DATA_VALUE_PTR(31U, (void *)&chartInstance->c4_e_STOP_COM);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "slGa2wm9Aiy7X6iplwOFEND";
}

static void sf_opaque_initialize_c4_GCU_CAN_C(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_GCU_CAN_CInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c4_GCU_CAN_C((SFc4_GCU_CAN_CInstanceStruct*)
    chartInstanceVar);
  initialize_c4_GCU_CAN_C((SFc4_GCU_CAN_CInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_GCU_CAN_C(void *chartInstanceVar)
{
  enable_c4_GCU_CAN_C((SFc4_GCU_CAN_CInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_GCU_CAN_C(void *chartInstanceVar)
{
  disable_c4_GCU_CAN_C((SFc4_GCU_CAN_CInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_GCU_CAN_C(void *chartInstanceVar)
{
  sf_gateway_c4_GCU_CAN_C((SFc4_GCU_CAN_CInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_GCU_CAN_C(SimStruct* S)
{
  return get_sim_state_c4_GCU_CAN_C((SFc4_GCU_CAN_CInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_GCU_CAN_C(SimStruct* S, const mxArray *st)
{
  set_sim_state_c4_GCU_CAN_C((SFc4_GCU_CAN_CInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c4_GCU_CAN_C(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_GCU_CAN_CInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_GCU_CAN_C_optimization_info();
    }

    finalize_c4_GCU_CAN_C((SFc4_GCU_CAN_CInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_GCU_CAN_C((SFc4_GCU_CAN_CInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_GCU_CAN_C(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_GCU_CAN_C((SFc4_GCU_CAN_CInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c4_GCU_CAN_C(SimStruct *S)
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
    mxArray *infoStruct = load_GCU_CAN_C_optimization_info(sim_mode_is_rtw_gen(S),
      sim_mode_is_modelref_sim(S), sim_mode_is_external(S));
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
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,16);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1349862788U));
  ssSetChecksum1(S,(1126160001U));
  ssSetChecksum2(S,(3374808870U));
  ssSetChecksum3(S,(841982402U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_GCU_CAN_C(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c4_GCU_CAN_C(SimStruct *S)
{
  SFc4_GCU_CAN_CInstanceStruct *chartInstance;
  chartInstance = (SFc4_GCU_CAN_CInstanceStruct *)utMalloc(sizeof
    (SFc4_GCU_CAN_CInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc4_GCU_CAN_CInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_GCU_CAN_C;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_GCU_CAN_C;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_GCU_CAN_C;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_GCU_CAN_C;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_GCU_CAN_C;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_GCU_CAN_C;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_GCU_CAN_C;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c4_GCU_CAN_C;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_GCU_CAN_C;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_GCU_CAN_C;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_GCU_CAN_C;
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
  mdl_start_c4_GCU_CAN_C(chartInstance);
}

void c4_GCU_CAN_C_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_GCU_CAN_C(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_GCU_CAN_C(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_GCU_CAN_C(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_GCU_CAN_C_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
