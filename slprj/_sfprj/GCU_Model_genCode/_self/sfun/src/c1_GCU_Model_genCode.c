/* Include files */

#include "simstruc.h"
#include "fixedpoint.h"
#include "simtarget/slSimTgtLogLoadBlocksSfcnBridge.h"
#include "GCU_Model_genCode_sfun.h"
#include "c1_GCU_Model_genCode.h"
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
#define c1_event_GearshiftUp           (2)
#define c1_event_GearshiftDown         (0)
#define c1_event_GearshiftSetNeutral   (1)
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c1_IN_ACCELERATION             ((uint8_T)1U)
#define c1_IN_AUTOCROSS                ((uint8_T)2U)
#define c1_IN_INIT                     ((uint8_T)3U)
#define c1_IN_MANUAL_MODES             ((uint8_T)4U)
#define c1_IN_ENDURANCE                ((uint8_T)1U)
#define c1_IN_SKIDPAD                  ((uint8_T)2U)
#define c1_IN_ACC                      ((uint8_T)1U)
#define c1_IN_DEFAULT                  ((uint8_T)2U)
#define c1_IN_ACTIVE                   ((uint8_T)1U)
#define c1_IN_STOPPING                 ((uint8_T)2U)
#define c1_IN_READY                    ((uint8_T)1U)
#define c1_IN_RELEASING                ((uint8_T)2U)
#define c1_IN_RUNNING                  ((uint8_T)3U)
#define c1_IN_START                    ((uint8_T)4U)
#define c1_IN_START_RELEASE            ((uint8_T)5U)
#define c1_b_IN_DEFAULT                ((uint8_T)1U)
#define c1_IN_LAUNCH                   ((uint8_T)2U)
#define c1_IN_NEUTRAL                  ((uint8_T)1U)
#define c1_IN_NO_NEUTRAL               ((uint8_T)2U)
#define c1_IN_SET_NEUTRAL              ((uint8_T)3U)
#define c1_IN_UNSET_NEUTRAL            ((uint8_T)4U)
#define c1_IN_DOWNSHIFTING             ((uint8_T)1U)
#define c1_IN_DOWN_END                 ((uint8_T)2U)
#define c1_IN_IDLE                     ((uint8_T)3U)
#define c1_b_IN_INIT                   ((uint8_T)4U)
#define c1_IN_UPSHIFTING               ((uint8_T)5U)
#define c1_IN_UP_END                   ((uint8_T)6U)
#define c1_IN_UP_BRAKE                 ((uint8_T)1U)
#define c1_IN_UP_PUSH                  ((uint8_T)2U)
#define c1_IN_UP_REBOUND               ((uint8_T)3U)
#define c1_IN_UP_START                 ((uint8_T)4U)
#define c1_IN_Default                  ((uint8_T)1U)
#define c1_IN_SettingNeutral           ((uint8_T)2U)
#define c1_IN_CutOff                   ((uint8_T)1U)
#define c1_b_IN_Default                ((uint8_T)2U)
#define c1_IN_DOWN_BRAKE               ((uint8_T)1U)
#define c1_IN_DOWN_PUSH                ((uint8_T)2U)
#define c1_IN_DOWN_REBOUND             ((uint8_T)3U)
#define c1_IN_DOWN_START               ((uint8_T)4U)
#define c1_IN_ChangeClutch             ((uint8_T)1U)
#define c1_b_IN_SettingNeutral         ((uint8_T)3U)
#define c1_IN_SEND                     ((uint8_T)1U)
#define c1_IN_WAIT                     ((uint8_T)2U)
#define c1_b_IN_START                  ((uint8_T)1U)
#define c1_IN_STOP                     ((uint8_T)2U)
#define c1_b_IN_WAIT                   ((uint8_T)3U)
#define c1_IN_SCAN                     ((uint8_T)1U)
#define c1_const_GEAR_COMMAND_NEUTRAL_UP ((uint16_T)50U)
#define c1_const_GEAR_COMMAND_NEUTRAL_DOWN ((uint16_T)100U)
#define c1_const_GEAR_COMMAND_UP       ((uint16_T)400U)
#define c1_const_GEAR_COMMAND_DOWN     ((uint16_T)200U)
#define c1_const_AAC_WORK_RATE_ms      ((uint16_T)25U)
#define c1_const_DEF_RAMP_START        (50)
#define c1_const_DEF_RAMP_END          (0)
#define c1_const_DEF_RAMP_TIME         (250)
#define c1_const_DEF_RPM_LIMIT_1_2     (11000)
#define c1_const_DEF_RPM_LIMIT_2_3     (11000)
#define c1_const_DEF_RPM_LIMIT_3_4     (11000)
#define c1_const_DEF_RPM_LIMIT_4_5     (11000)
#define c1_const_DEF_SPEED_LIMIT_1_2   (46)
#define c1_const_DEF_SPEED_LIMIT_2_3   (61)
#define c1_const_DEF_SPEED_LIMIT_3_4   (77)
#define c1_const_DEF_SPEED_LIMIT_4_5   (113)
#define c1_const_ACC_CODE              ((uint16_T)1U)
#define c1_const_AUTOX_WORK_RATE_ms    ((uint16_T)25U)
#define c1_const_data                  (0.0)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c1_sv0[12] = { "RAMP_START", "RAMP_END", "RAMP_TIME",
  "RPM_LIMIT_1_2", "RPM_LIMIT_2_3", "RPM_LIMIT_3_4", "RPM_LIMIT_4_5",
  "SPEED_LIMIT_1_2", "SPEED_LIMIT_2_3", "SPEED_LIMIT_3_4", "SPEED_LIMIT_4_5",
  "TPS_START_LIMIT" };

static const int32_T c1_iv0[12] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

static const char * c1_sv1[12] = { "AUTOX_RAMP_START", "AUTOX_RAMP_END",
  "AUTOX_RAMP_TIME", "AUTOX_RPM_LIMIT_1_2", "AUTOX_RPM_LIMIT_2_3",
  "AUTOX_RPM_LIMIT_3_4", "AUTOX_RPM_LIMIT_4_5", "AUTOX_SPEED_LIMIT_1_2",
  "AUTOX_SPEED_LIMIT_2_3", "AUTOX_SPEED_LIMIT_3_4", "AUTOX_SPEED_LIMIT_4_5",
  "AUTOX_TPS_START_LIMIT" };

/* Function Declarations */
static void c1_sdiInitialize(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_sdiTerminate(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void initialize_c1_GCU_Model_genCode(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void initialize_params_c1_GCU_Model_genCode
  (SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void enable_c1_GCU_Model_genCode(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void disable_c1_GCU_Model_genCode(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_GCU_Model_genCode
  (SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_GCU_Model_genCode
  (SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void set_sim_state_c1_GCU_Model_genCode
  (SFc1_GCU_Model_genCodeInstanceStruct *chartInstance, const mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_GCU_Model_genCode
  (SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void finalize_c1_GCU_Model_genCode(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void sf_gateway_c1_GCU_Model_genCode(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void mdl_start_c1_GCU_Model_genCode(SFc1_GCU_Model_genCodeInstanceStruct *
  chartInstance);
static void c1_enter_internal_c1_GCU_Model_genCode
  (SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_c1_GCU_Model_genCode(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void initSimStructsc1_GCU_Model_genCode
  (SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_enter_atomic_MANUAL_MODES(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void c1_MANUAL_MODES(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_exit_internal_MANUAL_MODES(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void c1_INIT(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_enter_internal_ACCELERATION(SFc1_GCU_Model_genCodeInstanceStruct *
  chartInstance);
static void c1_ACCELERATION(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_exit_internal_ACCELERATION(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void c1_ACC(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_ACTIVE(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_exit_internal_ACTIVE(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void c1_START(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_enter_atomic_READY(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void c1_START_RELEASE(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_RELEASING(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_DEFAULT(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_enter_internal_AUTOCROSS(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void c1_AUTOCROSS(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_exit_internal_AUTOCROSS(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void c1_LAUNCH(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_b_ACTIVE(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_b_exit_internal_ACTIVE(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void c1_b_START(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_b_enter_atomic_READY(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void c1_b_START_RELEASE(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void c1_b_RELEASING(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_b_DEFAULT(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_NEUTRAL_STATE(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_GEARSHIFT(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_UPSHIFTING(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_exit_internal_UP_REBOUND(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void c1_exit_internal_UP_PUSH(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void c1_UP_START(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_exit_internal_UP_START(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void c1_IDLE(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_DOWNSHIFTING(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_DOWN_START(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_exit_internal_DOWN_START(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void c1_exit_internal_DOWN_BRAKE(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void c1_START_ENGINE(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static void c1_checkClutch(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_checkShift(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void c1_aacCheckShift(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static int32_T c1_getAacParam(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, c1_acc_params c1_index);
static void c1_autoXCheckShift(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static int32_T c1_getAutoXParam(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, c1_autoX_params c1_index);
static int32_T c1_Gearshift_getTime(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void c1_Clutch_setValue(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, uint8_T c1_setValue);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static int32_T c1_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c1_b_sfEvent, const char_T *c1_identifier);
static int32_T c1_b_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_c_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c1_b_tp_MODES, const char_T *c1_identifier);
static uint8_T c1_d_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_e_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c1_b_lastModeCom, const char_T *c1_identifier,
  uint16_T c1_y[2]);
static void c1_f_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  uint16_T c1_y[2]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint16_T c1_g_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c1_b_stateFb, const char_T *c1_identifier);
static uint16_T c1_h_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_i_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c1_b_aac_clutchValue, const char_T
  *c1_identifier);
static real_T c1_j_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_k_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static c1_acc_params c1_k_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_l_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static c1_autoX_params c1_l_emlrt_marshallIn
  (SFc1_GCU_Model_genCodeInstanceStruct *chartInstance, const mxArray *c1_u,
   const emlrtMsgIdentifier *c1_parentId);
static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_m_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c1_u);
static const mxArray *c1_n_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier);
static const mxArray *c1_o_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static const mxArray *sf_get_hover_data_for_msg
  (SFc1_GCU_Model_genCodeInstanceStruct *chartInstance, int32_T c1_ssid);
static void c1_init_sf_message_store_memory(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static int32_T c1_div_nzp_s32(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, int32_T c1_numerator, int32_T c1_denominator, uint32_T
  c1_ssid_src_loc, int32_T c1_offset_src_loc, int32_T c1_length_src_loc);
static int32_T c1__s32_add__(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance,
  int32_T c1_b, int32_T c1_c, uint32_T c1_ssid_src_loc, int32_T
  c1_offset_src_loc, int32_T c1_length_src_loc);
static int32_T c1__s32_minus__(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, int32_T c1_b, int32_T c1_c, uint32_T c1_ssid_src_loc, int32_T
  c1_offset_src_loc, int32_T c1_length_src_loc);
static uint8_T c1__u8_s32_(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance,
  int32_T c1_b, uint32_T c1_ssid_src_loc, int32_T c1_offset_src_loc, int32_T
  c1_length_src_loc);
static void c1_sdiStreamingWrapperFcn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, int32_T c1_modeFlag, int32_T c1_ssidIdx, uint32_T c1_ssid,
  int32_T c1_streamedData);
static void c1_b_sdiStreamingWrapperFcn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, int32_T c1_modeFlag, int32_T c1_ssidIdx, uint32_T c1_ssid,
  void *c1_streamedData);
static void c1_c_sdiStreamingWrapperFcn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, int32_T c1_modeFlag, int32_T c1_ssidIdx, uint32_T c1_ssid,
  int32_T c1_streamedData);
static void c1_d_sdiStreamingWrapperFcn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, int32_T c1_modeFlag, int32_T c1_ssidIdx, uint32_T c1_ssid,
  void *c1_streamedData);
static void init_test_point_addr_map(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void **get_test_point_address_map(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info
  (SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void **get_dataset_logging_obj_vector
  (SFc1_GCU_Model_genCodeInstanceStruct *chartInstance);
static void init_dsm_address_info(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance);

/* Function Definitions */
static void c1_sdiInitialize(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  uint32_T c1_b[67] = { 0U, 418U, 820U, 434U, 538U, 545U, 544U, 514U, 543U, 547U,
    515U, 821U, 951U, 952U, 974U, 985U, 999U, 1025U, 1002U, 998U, 1001U, 1028U,
    429U, 727U, 729U, 728U, 31U, 36U, 32U, 34U, 35U, 1U, 697U, 17U, 410U, 409U,
    15U, 16U, 14U, 398U, 406U, 399U, 18U, 5U, 7U, 693U, 12U, 10U, 423U, 422U,
    11U, 390U, 391U, 9U, 385U, 383U, 13U, 479U, 482U, 483U, 494U, 929U, 932U,
    930U, 940U, 946U, 944U };

  uint32_T c1_c[62] = { 4U, 123U, 834U, 443U, 485U, 524U, 579U, 680U, 715U, 799U,
    833U, 837U, 925U, 1044U, 1060U, 627U, 681U, 684U, 1043U, 1063U, 643U, 644U,
    645U, 646U, 631U, 632U, 633U, 634U, 537U, 550U, 561U, 563U, 564U, 698U, 699U,
    700U, 702U, 704U, 705U, 706U, 707U, 708U, 709U, 710U, 754U, 568U, 569U, 957U,
    958U, 959U, 960U, 961U, 1031U, 1032U, 45U, 437U, 164U, 501U, 950U, 484U,
    488U, 938U };

  const char * c1_d[5] = { "None", "ACCELERATION", "AUTOCROSS", "INIT",
    "MANUAL_MODES" };

  int32_T c1_e[5] = { 0, 1, 2, 3, 4 };

  const char * c1_f[18] = { "None", "INIT", "ENDURANCE", "SKIDPAD", "DEFAULT",
    "START", "READY", "START_RELEASE", "RELEASING", "RUNNING", "STOPPING",
    "DEFAULT", "START", "READY", "START_RELEASE", "RELEASING", "RUNNING",
    "STOPPING" };

  int32_T c1_g[18] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
    17 };

  const char * c1_h[3] = { "None", "ACC", "DEFAULT" };

  int32_T c1_i[3] = { 0, 1, 2 };

  const char * c1_j[8] = { "None", "DEFAULT", "START", "READY", "START_RELEASE",
    "RELEASING", "RUNNING", "STOPPING" };

  int32_T c1_k[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };

  const char * c1_l[3] = { "None", "ACTIVE", "STOPPING" };

  int32_T c1_m[3] = { 0, 1, 2 };

  const char * c1_n[7] = { "None", "START", "READY", "START_RELEASE",
    "RELEASING", "RUNNING", "STOPPING" };

  int32_T c1_o[7] = { 0, 1, 2, 3, 4, 5, 6 };

  const char * c1_p[6] = { "None", "READY", "RELEASING", "RUNNING", "START",
    "START_RELEASE" };

  int32_T c1_q[6] = { 0, 1, 2, 3, 4, 5 };

  const char * c1_r[6] = { "None", "START", "READY", "START_RELEASE",
    "RELEASING", "RUNNING" };

  int32_T c1_s[6] = { 0, 1, 2, 3, 4, 5 };

  const char * c1_t[3] = { "None", "DEFAULT", "LAUNCH" };

  int32_T c1_u[3] = { 0, 1, 2 };

  const char * c1_v[8] = { "None", "DEFAULT", "START", "READY", "START_RELEASE",
    "RELEASING", "RUNNING", "STOPPING" };

  int32_T c1_w[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };

  const char * c1_x[3] = { "None", "ACTIVE", "STOPPING" };

  int32_T c1_y[3] = { 0, 1, 2 };

  const char * c1_ab[7] = { "None", "START", "READY", "START_RELEASE",
    "RELEASING", "RUNNING", "STOPPING" };

  int32_T c1_bb[7] = { 0, 1, 2, 3, 4, 5, 6 };

  const char * c1_cb[6] = { "None", "READY", "RELEASING", "RUNNING", "START",
    "START_RELEASE" };

  int32_T c1_db[6] = { 0, 1, 2, 3, 4, 5 };

  const char * c1_eb[6] = { "None", "START", "READY", "START_RELEASE",
    "RELEASING", "RUNNING" };

  int32_T c1_fb[6] = { 0, 1, 2, 3, 4, 5 };

  const char * c1_gb[3] = { "None", "ENDURANCE", "SKIDPAD" };

  int32_T c1_hb[3] = { 0, 1, 2 };

  const char * c1_ib[3] = { "None", "ENDURANCE", "SKIDPAD" };

  int32_T c1_jb[3] = { 0, 1, 2 };

  const char * c1_kb[5] = { "None", "NEUTRAL", "NO_NEUTRAL", "SET_NEUTRAL",
    "UNSET_NEUTRAL" };

  int32_T c1_lb[5] = { 0, 1, 2, 3, 4 };

  const char * c1_mb[5] = { "None", "NEUTRAL", "UNSET_NEUTRAL", "NO_NEUTRAL",
    "SET_NEUTRAL" };

  int32_T c1_nb[5] = { 0, 1, 2, 3, 4 };

  const char * c1_ob[7] = { "None", "DOWNSHIFTING", "DOWN_END", "IDLE", "INIT",
    "UPSHIFTING", "UP_END" };

  int32_T c1_pb[7] = { 0, 1, 2, 3, 4, 5, 6 };

  const char * c1_qb[19] = { "None", "INIT", "IDLE", "SettingNeutral", "Default",
    "CutOff", "Default", "SettingNeutral", "Default", "UP_BRAKE", "UP_END",
    "SettingNeutral", "ChangeClutch", "Default", "DOWN_PUSH", "DOWN_REBOUND",
    "ChangeClutch", "Default", "DOWN_END" };

  int32_T c1_rb[19] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
    17, 18 };

  const char * c1_sb[5] = { "None", "DOWN_BRAKE", "DOWN_PUSH", "DOWN_REBOUND",
    "DOWN_START" };

  int32_T c1_tb[5] = { 0, 1, 2, 3, 4 };

  const char * c1_ub[8] = { "None", "SettingNeutral", "ChangeClutch", "Default",
    "DOWN_PUSH", "DOWN_REBOUND", "ChangeClutch", "Default" };

  int32_T c1_vb[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };

  const char * c1_wb[3] = { "None", "ChangeClutch", "Default" };

  int32_T c1_xb[3] = { 0, 1, 2 };

  const char * c1_yb[3] = { "None", "ChangeClutch", "Default" };

  int32_T c1_ac[3] = { 0, 1, 2 };

  const char * c1_bc[4] = { "None", "ChangeClutch", "Default", "SettingNeutral"
  };

  int32_T c1_cc[4] = { 0, 1, 2, 3 };

  const char * c1_dc[4] = { "None", "SettingNeutral", "ChangeClutch", "Default"
  };

  int32_T c1_ec[4] = { 0, 1, 2, 3 };

  const char * c1_fc[5] = { "None", "UP_BRAKE", "UP_PUSH", "UP_REBOUND",
    "UP_START" };

  int32_T c1_gc[5] = { 0, 1, 2, 3, 4 };

  const char * c1_hc[8] = { "None", "SettingNeutral", "Default", "CutOff",
    "Default", "SettingNeutral", "Default", "UP_BRAKE" };

  int32_T c1_ic[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };

  const char * c1_jc[3] = { "None", "CutOff", "Default" };

  int32_T c1_kc[3] = { 0, 1, 2 };

  const char * c1_lc[3] = { "None", "CutOff", "Default" };

  int32_T c1_mc[3] = { 0, 1, 2 };

  const char * c1_nc[3] = { "None", "Default", "SettingNeutral" };

  int32_T c1_oc[3] = { 0, 1, 2 };

  const char * c1_pc[3] = { "None", "SettingNeutral", "Default" };

  int32_T c1_qc[3] = { 0, 1, 2 };

  const char * c1_rc[3] = { "None", "Default", "SettingNeutral" };

  int32_T c1_sc[3] = { 0, 1, 2 };

  const char * c1_tc[3] = { "None", "SettingNeutral", "Default" };

  int32_T c1_uc[3] = { 0, 1, 2 };

  const char * c1_vc[4] = { "None", "START", "STOP", "WAIT" };

  int32_T c1_wc[4] = { 0, 1, 2, 3 };

  const char * c1_xc[4] = { "None", "WAIT", "START", "STOP" };

  int32_T c1_yc[4] = { 0, 1, 2, 3 };

  const char * c1_ad[3] = { "None", "SCAN", "WAIT" };

  int32_T c1_bd[3] = { 0, 1, 2 };

  const char * c1_cd[3] = { "None", "SCAN", "WAIT" };

  int32_T c1_dd[3] = { 0, 1, 2 };

  const char * c1_ed[3] = { "None", "SEND", "WAIT" };

  int32_T c1_fd[3] = { 0, 1, 2 };

  const char * c1_gd[3] = { "None", "WAIT", "SEND" };

  int32_T c1_hd[3] = { 0, 1, 2 };

  int32_T c1_id[1] = { 1 };

  int32_T c1_jd[1] = { 2 };

  int32_T c1_kd[1] = { 1 };

  int32_T c1_ld[1] = { 1 };

  int32_T c1_md[1] = { 1 };

  int32_T c1_nd[1] = { 1 };

  int32_T c1_od[1] = { 1 };

  int32_T c1_pd[1] = { 1 };

  int32_T c1_qd[1] = { 1 };

  int32_T c1_rd[1] = { 1 };

  int32_T c1_sd[1] = { 1 };

  int32_T c1_td[1] = { 1 };

  int32_T c1_ud[1] = { 1 };

  int32_T c1_vd[1] = { 1 };

  int32_T c1_wd[1] = { 1 };

  int32_T c1_xd[1] = { 1 };

  int32_T c1_yd[1] = { 1 };

  int32_T c1_ae[1] = { 1 };

  int32_T c1_be[1] = { 1 };

  int32_T c1_ce[1] = { 1 };

  int32_T c1_de[1] = { 1 };

  int32_T c1_ee[1] = { 1 };

  chartInstance->c1_sdiBlockInfo.mdlRefFullPath = "";
  chartInstance->c1_sdiBlockInfo.SimStruct = (void *)chartInstance->S;
  chartInstance->c1_sdiBlockInfo.blkPath = "";
  chartInstance->c1_sdiBlockInfo.blkSID = "GCU_Model_genCode:651";
  chartInstance->c1_sdiBlockInfo.sharedSCMPath = "";
  chartInstance->c1_sdiBlockInfo.sdiRuntime = NULL;
  sdi_database_initialize(&chartInstance->c1_sdiBlockInfo, c1_b, (uint8_T *)
    &chartInstance->c1_sdiLoggedStatesBuffer[0U], 67, c1_c, (uint8_T *)
    &chartInstance->c1_sdiLoggedDataBuffer[0U], 62);
  if (chartInstance->c1_sdiLoggedStatesBuffer[1U] & 1) {
    sdi_register_child_activity_signal(&chartInstance->c1_sdiBlockInfo, "MODES",
      "MODES", 5, c1_d, c1_e, sizeof(uint8_T), 1, 418U);
  }

  chartInstance->c1_SignalExportProp.logName = "";
  chartInstance->c1_SignalExportProp.signalName = "MODES";
  chartInstance->c1_SignalExportProp.useCustomName = 0;
  chartInstance->c1_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_SignalExportProp.decimate = 0;
  chartInstance->c1_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[1U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo, "MODES",
      "MODES", 1, &chartInstance->c1_SignalExportProp, 418U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[1U] & 2) {
    sdi_register_leaf_activity_signal(&chartInstance->c1_sdiBlockInfo, "MODES",
      "MODES", 18, c1_f, c1_g, 1, 418U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[2U] & 1) {
    sdi_register_child_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.ACCELERATION", "MODES/ACCELERATION", 3, c1_h, c1_i, sizeof(uint8_T),
      1, 820U);
  }

  chartInstance->c1_b_SignalExportProp.logName = "";
  chartInstance->c1_b_SignalExportProp.signalName = "MODES.ACCELERATION";
  chartInstance->c1_b_SignalExportProp.useCustomName = 0;
  chartInstance->c1_b_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_b_SignalExportProp.decimate = 0;
  chartInstance->c1_b_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_b_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[2U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.ACCELERATION", "MODES/ACCELERATION", 1,
      &chartInstance->c1_b_SignalExportProp, 820U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[2U] & 2) {
    sdi_register_leaf_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.ACCELERATION", "MODES/ACCELERATION", 8, c1_j, c1_k, 1, 820U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[3U] & 1) {
    sdi_register_child_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.ACCELERATION.ACC", "MODES/ACCELERATION/ACC", 3, c1_l, c1_m, sizeof
      (uint8_T), 1, 434U);
  }

  chartInstance->c1_c_SignalExportProp.logName = "";
  chartInstance->c1_c_SignalExportProp.signalName = "MODES.ACCELERATION.ACC";
  chartInstance->c1_c_SignalExportProp.useCustomName = 0;
  chartInstance->c1_c_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_c_SignalExportProp.decimate = 0;
  chartInstance->c1_c_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_c_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[3U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.ACCELERATION.ACC", "MODES/ACCELERATION/ACC", 1,
      &chartInstance->c1_c_SignalExportProp, 434U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[3U] & 2) {
    sdi_register_leaf_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.ACCELERATION.ACC", "MODES/ACCELERATION/ACC", 7, c1_n, c1_o, 1, 434U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[4U] & 1) {
    sdi_register_child_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.ACCELERATION.ACC.ACTIVE", "MODES/ACCELERATION/ACC/ACTIVE", 6, c1_p,
      c1_q, sizeof(uint8_T), 1, 538U);
  }

  chartInstance->c1_d_SignalExportProp.logName = "";
  chartInstance->c1_d_SignalExportProp.signalName =
    "MODES.ACCELERATION.ACC.ACTIVE";
  chartInstance->c1_d_SignalExportProp.useCustomName = 0;
  chartInstance->c1_d_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_d_SignalExportProp.decimate = 0;
  chartInstance->c1_d_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_d_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[4U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.ACCELERATION.ACC.ACTIVE", "MODES/ACCELERATION/ACC/ACTIVE", 1,
      &chartInstance->c1_d_SignalExportProp, 538U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[4U] & 2) {
    sdi_register_leaf_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.ACCELERATION.ACC.ACTIVE", "MODES/ACCELERATION/ACC/ACTIVE", 6, c1_r,
      c1_s, 1, 538U);
  }

  chartInstance->c1_e_SignalExportProp.logName = "";
  chartInstance->c1_e_SignalExportProp.signalName =
    "MODES.ACCELERATION.ACC.ACTIVE.READY";
  chartInstance->c1_e_SignalExportProp.useCustomName = 0;
  chartInstance->c1_e_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_e_SignalExportProp.decimate = 0;
  chartInstance->c1_e_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_e_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[5U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.ACCELERATION.ACC.ACTIVE.READY",
      "MODES/ACCELERATION/ACC/ACTIVE/READY", 1,
      &chartInstance->c1_e_SignalExportProp, 545U);
  }

  chartInstance->c1_f_SignalExportProp.logName = "";
  chartInstance->c1_f_SignalExportProp.signalName =
    "MODES.ACCELERATION.ACC.ACTIVE.RELEASING";
  chartInstance->c1_f_SignalExportProp.useCustomName = 0;
  chartInstance->c1_f_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_f_SignalExportProp.decimate = 0;
  chartInstance->c1_f_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_f_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[6U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.ACCELERATION.ACC.ACTIVE.RELEASING",
      "MODES/ACCELERATION/ACC/ACTIVE/RELEASING", 1,
      &chartInstance->c1_f_SignalExportProp, 544U);
  }

  chartInstance->c1_g_SignalExportProp.logName = "";
  chartInstance->c1_g_SignalExportProp.signalName =
    "MODES.ACCELERATION.ACC.ACTIVE.RUNNING";
  chartInstance->c1_g_SignalExportProp.useCustomName = 0;
  chartInstance->c1_g_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_g_SignalExportProp.decimate = 0;
  chartInstance->c1_g_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_g_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[7U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.ACCELERATION.ACC.ACTIVE.RUNNING",
      "MODES/ACCELERATION/ACC/ACTIVE/RUNNING", 1,
      &chartInstance->c1_g_SignalExportProp, 514U);
  }

  chartInstance->c1_h_SignalExportProp.logName = "";
  chartInstance->c1_h_SignalExportProp.signalName =
    "MODES.ACCELERATION.ACC.ACTIVE.START";
  chartInstance->c1_h_SignalExportProp.useCustomName = 0;
  chartInstance->c1_h_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_h_SignalExportProp.decimate = 0;
  chartInstance->c1_h_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_h_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[8U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.ACCELERATION.ACC.ACTIVE.START",
      "MODES/ACCELERATION/ACC/ACTIVE/START", 1,
      &chartInstance->c1_h_SignalExportProp, 543U);
  }

  chartInstance->c1_i_SignalExportProp.logName = "";
  chartInstance->c1_i_SignalExportProp.signalName =
    "MODES.ACCELERATION.ACC.ACTIVE.START_RELEASE";
  chartInstance->c1_i_SignalExportProp.useCustomName = 0;
  chartInstance->c1_i_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_i_SignalExportProp.decimate = 0;
  chartInstance->c1_i_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_i_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[9U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.ACCELERATION.ACC.ACTIVE.START_RELEASE",
      "MODES/ACCELERATION/ACC/ACTIVE/START_RELEASE", 1,
      &chartInstance->c1_i_SignalExportProp, 547U);
  }

  chartInstance->c1_j_SignalExportProp.logName = "";
  chartInstance->c1_j_SignalExportProp.signalName =
    "MODES.ACCELERATION.ACC.STOPPING";
  chartInstance->c1_j_SignalExportProp.useCustomName = 0;
  chartInstance->c1_j_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_j_SignalExportProp.decimate = 0;
  chartInstance->c1_j_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_j_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[10U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.ACCELERATION.ACC.STOPPING", "MODES/ACCELERATION/ACC/STOPPING", 1,
      &chartInstance->c1_j_SignalExportProp, 515U);
  }

  chartInstance->c1_k_SignalExportProp.logName = "";
  chartInstance->c1_k_SignalExportProp.signalName = "MODES.ACCELERATION.DEFAULT";
  chartInstance->c1_k_SignalExportProp.useCustomName = 0;
  chartInstance->c1_k_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_k_SignalExportProp.decimate = 0;
  chartInstance->c1_k_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_k_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[11U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.ACCELERATION.DEFAULT", "MODES/ACCELERATION/DEFAULT", 1,
      &chartInstance->c1_k_SignalExportProp, 821U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[12U] & 1) {
    sdi_register_child_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.AUTOCROSS", "MODES/AUTOCROSS", 3, c1_t, c1_u, sizeof(uint8_T), 1,
      951U);
  }

  chartInstance->c1_l_SignalExportProp.logName = "";
  chartInstance->c1_l_SignalExportProp.signalName = "MODES.AUTOCROSS";
  chartInstance->c1_l_SignalExportProp.useCustomName = 0;
  chartInstance->c1_l_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_l_SignalExportProp.decimate = 0;
  chartInstance->c1_l_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_l_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[12U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.AUTOCROSS", "MODES/AUTOCROSS", 1,
      &chartInstance->c1_l_SignalExportProp, 951U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[12U] & 2) {
    sdi_register_leaf_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.AUTOCROSS", "MODES/AUTOCROSS", 8, c1_v, c1_w, 1, 951U);
  }

  chartInstance->c1_m_SignalExportProp.logName = "";
  chartInstance->c1_m_SignalExportProp.signalName = "MODES.AUTOCROSS.DEFAULT";
  chartInstance->c1_m_SignalExportProp.useCustomName = 0;
  chartInstance->c1_m_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_m_SignalExportProp.decimate = 0;
  chartInstance->c1_m_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_m_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[13U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.AUTOCROSS.DEFAULT", "MODES/AUTOCROSS/DEFAULT", 1,
      &chartInstance->c1_m_SignalExportProp, 952U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[14U] & 1) {
    sdi_register_child_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.AUTOCROSS.LAUNCH", "MODES/AUTOCROSS/LAUNCH", 3, c1_x, c1_y, sizeof
      (uint8_T), 1, 974U);
  }

  chartInstance->c1_n_SignalExportProp.logName = "";
  chartInstance->c1_n_SignalExportProp.signalName = "MODES.AUTOCROSS.LAUNCH";
  chartInstance->c1_n_SignalExportProp.useCustomName = 0;
  chartInstance->c1_n_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_n_SignalExportProp.decimate = 0;
  chartInstance->c1_n_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_n_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[14U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.AUTOCROSS.LAUNCH", "MODES/AUTOCROSS/LAUNCH", 1,
      &chartInstance->c1_n_SignalExportProp, 974U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[14U] & 2) {
    sdi_register_leaf_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.AUTOCROSS.LAUNCH", "MODES/AUTOCROSS/LAUNCH", 7, c1_ab, c1_bb, 1,
      974U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[15U] & 1) {
    sdi_register_child_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.AUTOCROSS.LAUNCH.ACTIVE", "MODES/AUTOCROSS/LAUNCH/ACTIVE", 6, c1_cb,
      c1_db, sizeof(uint8_T), 1, 985U);
  }

  chartInstance->c1_o_SignalExportProp.logName = "";
  chartInstance->c1_o_SignalExportProp.signalName =
    "MODES.AUTOCROSS.LAUNCH.ACTIVE";
  chartInstance->c1_o_SignalExportProp.useCustomName = 0;
  chartInstance->c1_o_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_o_SignalExportProp.decimate = 0;
  chartInstance->c1_o_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_o_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[15U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.AUTOCROSS.LAUNCH.ACTIVE", "MODES/AUTOCROSS/LAUNCH/ACTIVE", 1,
      &chartInstance->c1_o_SignalExportProp, 985U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[15U] & 2) {
    sdi_register_leaf_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.AUTOCROSS.LAUNCH.ACTIVE", "MODES/AUTOCROSS/LAUNCH/ACTIVE", 6, c1_eb,
      c1_fb, 1, 985U);
  }

  chartInstance->c1_p_SignalExportProp.logName = "";
  chartInstance->c1_p_SignalExportProp.signalName =
    "MODES.AUTOCROSS.LAUNCH.ACTIVE.READY";
  chartInstance->c1_p_SignalExportProp.useCustomName = 0;
  chartInstance->c1_p_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_p_SignalExportProp.decimate = 0;
  chartInstance->c1_p_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_p_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[16U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.AUTOCROSS.LAUNCH.ACTIVE.READY",
      "MODES/AUTOCROSS/LAUNCH/ACTIVE/READY", 1,
      &chartInstance->c1_p_SignalExportProp, 999U);
  }

  chartInstance->c1_q_SignalExportProp.logName = "";
  chartInstance->c1_q_SignalExportProp.signalName =
    "MODES.AUTOCROSS.LAUNCH.ACTIVE.RELEASING";
  chartInstance->c1_q_SignalExportProp.useCustomName = 0;
  chartInstance->c1_q_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_q_SignalExportProp.decimate = 0;
  chartInstance->c1_q_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_q_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[17U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.AUTOCROSS.LAUNCH.ACTIVE.RELEASING",
      "MODES/AUTOCROSS/LAUNCH/ACTIVE/RELEASING", 1,
      &chartInstance->c1_q_SignalExportProp, 1025U);
  }

  chartInstance->c1_r_SignalExportProp.logName = "";
  chartInstance->c1_r_SignalExportProp.signalName =
    "MODES.AUTOCROSS.LAUNCH.ACTIVE.RUNNING";
  chartInstance->c1_r_SignalExportProp.useCustomName = 0;
  chartInstance->c1_r_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_r_SignalExportProp.decimate = 0;
  chartInstance->c1_r_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_r_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[18U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.AUTOCROSS.LAUNCH.ACTIVE.RUNNING",
      "MODES/AUTOCROSS/LAUNCH/ACTIVE/RUNNING", 1,
      &chartInstance->c1_r_SignalExportProp, 1002U);
  }

  chartInstance->c1_s_SignalExportProp.logName = "";
  chartInstance->c1_s_SignalExportProp.signalName =
    "MODES.AUTOCROSS.LAUNCH.ACTIVE.START";
  chartInstance->c1_s_SignalExportProp.useCustomName = 0;
  chartInstance->c1_s_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_s_SignalExportProp.decimate = 0;
  chartInstance->c1_s_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_s_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[19U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.AUTOCROSS.LAUNCH.ACTIVE.START",
      "MODES/AUTOCROSS/LAUNCH/ACTIVE/START", 1,
      &chartInstance->c1_s_SignalExportProp, 998U);
  }

  chartInstance->c1_t_SignalExportProp.logName = "";
  chartInstance->c1_t_SignalExportProp.signalName =
    "MODES.AUTOCROSS.LAUNCH.ACTIVE.START_RELEASE";
  chartInstance->c1_t_SignalExportProp.useCustomName = 0;
  chartInstance->c1_t_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_t_SignalExportProp.decimate = 0;
  chartInstance->c1_t_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_t_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[20U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.AUTOCROSS.LAUNCH.ACTIVE.START_RELEASE",
      "MODES/AUTOCROSS/LAUNCH/ACTIVE/START_RELEASE", 1,
      &chartInstance->c1_t_SignalExportProp, 1001U);
  }

  chartInstance->c1_u_SignalExportProp.logName = "";
  chartInstance->c1_u_SignalExportProp.signalName =
    "MODES.AUTOCROSS.LAUNCH.STOPPING";
  chartInstance->c1_u_SignalExportProp.useCustomName = 0;
  chartInstance->c1_u_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_u_SignalExportProp.decimate = 0;
  chartInstance->c1_u_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_u_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[21U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.AUTOCROSS.LAUNCH.STOPPING", "MODES/AUTOCROSS/LAUNCH/STOPPING", 1,
      &chartInstance->c1_u_SignalExportProp, 1028U);
  }

  chartInstance->c1_v_SignalExportProp.logName = "";
  chartInstance->c1_v_SignalExportProp.signalName = "MODES.INIT";
  chartInstance->c1_v_SignalExportProp.useCustomName = 0;
  chartInstance->c1_v_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_v_SignalExportProp.decimate = 0;
  chartInstance->c1_v_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_v_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[22U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.INIT", "MODES/INIT", 1, &chartInstance->c1_v_SignalExportProp, 429U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[23U] & 1) {
    sdi_register_child_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.MANUAL_MODES", "MODES/MANUAL_MODES", 3, c1_gb, c1_hb, sizeof
      (uint8_T), 1, 727U);
  }

  chartInstance->c1_w_SignalExportProp.logName = "";
  chartInstance->c1_w_SignalExportProp.signalName = "MODES.MANUAL_MODES";
  chartInstance->c1_w_SignalExportProp.useCustomName = 0;
  chartInstance->c1_w_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_w_SignalExportProp.decimate = 0;
  chartInstance->c1_w_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_w_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[23U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.MANUAL_MODES", "MODES/MANUAL_MODES", 1,
      &chartInstance->c1_w_SignalExportProp, 727U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[23U] & 2) {
    sdi_register_leaf_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.MANUAL_MODES", "MODES/MANUAL_MODES", 3, c1_ib, c1_jb, 1, 727U);
  }

  chartInstance->c1_x_SignalExportProp.logName = "";
  chartInstance->c1_x_SignalExportProp.signalName =
    "MODES.MANUAL_MODES.ENDURANCE";
  chartInstance->c1_x_SignalExportProp.useCustomName = 0;
  chartInstance->c1_x_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_x_SignalExportProp.decimate = 0;
  chartInstance->c1_x_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_x_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[24U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.MANUAL_MODES.ENDURANCE", "MODES/MANUAL_MODES/ENDURANCE", 1,
      &chartInstance->c1_x_SignalExportProp, 729U);
  }

  chartInstance->c1_y_SignalExportProp.logName = "";
  chartInstance->c1_y_SignalExportProp.signalName = "MODES.MANUAL_MODES.SKIDPAD";
  chartInstance->c1_y_SignalExportProp.useCustomName = 0;
  chartInstance->c1_y_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_y_SignalExportProp.decimate = 0;
  chartInstance->c1_y_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_y_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[25U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "MODES.MANUAL_MODES.SKIDPAD", "MODES/MANUAL_MODES/SKIDPAD", 1,
      &chartInstance->c1_y_SignalExportProp, 728U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[26U] & 1) {
    sdi_register_child_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "NEUTRAL_STATE", "NEUTRAL_STATE", 5, c1_kb, c1_lb, sizeof(uint8_T), 1, 31U);
  }

  chartInstance->c1_ab_SignalExportProp.logName = "";
  chartInstance->c1_ab_SignalExportProp.signalName = "NEUTRAL_STATE";
  chartInstance->c1_ab_SignalExportProp.useCustomName = 0;
  chartInstance->c1_ab_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_ab_SignalExportProp.decimate = 0;
  chartInstance->c1_ab_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_ab_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[26U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "NEUTRAL_STATE", "NEUTRAL_STATE", 1,
      &chartInstance->c1_ab_SignalExportProp, 31U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[26U] & 2) {
    sdi_register_leaf_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "NEUTRAL_STATE", "NEUTRAL_STATE", 5, c1_mb, c1_nb, 1, 31U);
  }

  chartInstance->c1_bb_SignalExportProp.logName = "";
  chartInstance->c1_bb_SignalExportProp.signalName = "NEUTRAL_STATE.NEUTRAL";
  chartInstance->c1_bb_SignalExportProp.useCustomName = 0;
  chartInstance->c1_bb_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_bb_SignalExportProp.decimate = 0;
  chartInstance->c1_bb_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_bb_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[27U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "NEUTRAL_STATE.NEUTRAL", "NEUTRAL_STATE/NEUTRAL", 1,
      &chartInstance->c1_bb_SignalExportProp, 36U);
  }

  chartInstance->c1_cb_SignalExportProp.logName = "";
  chartInstance->c1_cb_SignalExportProp.signalName = "NEUTRAL_STATE.NO_NEUTRAL";
  chartInstance->c1_cb_SignalExportProp.useCustomName = 0;
  chartInstance->c1_cb_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_cb_SignalExportProp.decimate = 0;
  chartInstance->c1_cb_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_cb_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[28U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "NEUTRAL_STATE.NO_NEUTRAL", "NEUTRAL_STATE/NO_NEUTRAL", 1,
      &chartInstance->c1_cb_SignalExportProp, 32U);
  }

  chartInstance->c1_db_SignalExportProp.logName = "";
  chartInstance->c1_db_SignalExportProp.signalName = "NEUTRAL_STATE.SET_NEUTRAL";
  chartInstance->c1_db_SignalExportProp.useCustomName = 0;
  chartInstance->c1_db_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_db_SignalExportProp.decimate = 0;
  chartInstance->c1_db_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_db_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[29U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "NEUTRAL_STATE.SET_NEUTRAL", "NEUTRAL_STATE/SET_NEUTRAL", 1,
      &chartInstance->c1_db_SignalExportProp, 34U);
  }

  chartInstance->c1_eb_SignalExportProp.logName = "";
  chartInstance->c1_eb_SignalExportProp.signalName =
    "NEUTRAL_STATE.UNSET_NEUTRAL";
  chartInstance->c1_eb_SignalExportProp.useCustomName = 0;
  chartInstance->c1_eb_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_eb_SignalExportProp.decimate = 0;
  chartInstance->c1_eb_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_eb_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[30U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "NEUTRAL_STATE.UNSET_NEUTRAL", "NEUTRAL_STATE/UNSET_NEUTRAL", 1,
      &chartInstance->c1_eb_SignalExportProp, 35U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[31U] & 1) {
    sdi_register_child_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT", "GEARSHIFT", 7, c1_ob, c1_pb, sizeof(uint8_T), 1, 1U);
  }

  chartInstance->c1_fb_SignalExportProp.logName = "";
  chartInstance->c1_fb_SignalExportProp.signalName = "GEARSHIFT";
  chartInstance->c1_fb_SignalExportProp.useCustomName = 0;
  chartInstance->c1_fb_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_fb_SignalExportProp.decimate = 0;
  chartInstance->c1_fb_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_fb_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[31U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT", "GEARSHIFT", 1, &chartInstance->c1_fb_SignalExportProp, 1U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[31U] & 2) {
    sdi_register_leaf_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT", "GEARSHIFT", 19, c1_qb, c1_rb, 1, 1U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[32U] & 1) {
    sdi_register_child_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.DOWNSHIFTING", "GEARSHIFT/DOWNSHIFTING", 5, c1_sb, c1_tb,
      sizeof(uint8_T), 1, 697U);
  }

  chartInstance->c1_gb_SignalExportProp.logName = "";
  chartInstance->c1_gb_SignalExportProp.signalName = "GEARSHIFT.DOWNSHIFTING";
  chartInstance->c1_gb_SignalExportProp.useCustomName = 0;
  chartInstance->c1_gb_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_gb_SignalExportProp.decimate = 0;
  chartInstance->c1_gb_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_gb_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[32U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.DOWNSHIFTING", "GEARSHIFT/DOWNSHIFTING", 1,
      &chartInstance->c1_gb_SignalExportProp, 697U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[32U] & 2) {
    sdi_register_leaf_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.DOWNSHIFTING", "GEARSHIFT/DOWNSHIFTING", 8, c1_ub, c1_vb, 1,
      697U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[33U] & 1) {
    sdi_register_child_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.DOWNSHIFTING.DOWN_BRAKE", "GEARSHIFT/DOWNSHIFTING/DOWN_BRAKE",
      3, c1_wb, c1_xb, sizeof(uint8_T), 1, 17U);
  }

  chartInstance->c1_hb_SignalExportProp.logName = "";
  chartInstance->c1_hb_SignalExportProp.signalName =
    "GEARSHIFT.DOWNSHIFTING.DOWN_BRAKE";
  chartInstance->c1_hb_SignalExportProp.useCustomName = 0;
  chartInstance->c1_hb_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_hb_SignalExportProp.decimate = 0;
  chartInstance->c1_hb_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_hb_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[33U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.DOWNSHIFTING.DOWN_BRAKE", "GEARSHIFT/DOWNSHIFTING/DOWN_BRAKE",
      1, &chartInstance->c1_hb_SignalExportProp, 17U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[33U] & 2) {
    sdi_register_leaf_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.DOWNSHIFTING.DOWN_BRAKE", "GEARSHIFT/DOWNSHIFTING/DOWN_BRAKE",
      3, c1_yb, c1_ac, 1, 17U);
  }

  chartInstance->c1_ib_SignalExportProp.logName = "";
  chartInstance->c1_ib_SignalExportProp.signalName =
    "GEARSHIFT.DOWNSHIFTING.DOWN_BRAKE.ChangeClutch";
  chartInstance->c1_ib_SignalExportProp.useCustomName = 0;
  chartInstance->c1_ib_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_ib_SignalExportProp.decimate = 0;
  chartInstance->c1_ib_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_ib_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[34U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.DOWNSHIFTING.DOWN_BRAKE.ChangeClutch",
      "GEARSHIFT/DOWNSHIFTING/DOWN_BRAKE/ChangeClutch", 1,
      &chartInstance->c1_ib_SignalExportProp, 410U);
  }

  chartInstance->c1_jb_SignalExportProp.logName = "";
  chartInstance->c1_jb_SignalExportProp.signalName =
    "GEARSHIFT.DOWNSHIFTING.DOWN_BRAKE.Default";
  chartInstance->c1_jb_SignalExportProp.useCustomName = 0;
  chartInstance->c1_jb_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_jb_SignalExportProp.decimate = 0;
  chartInstance->c1_jb_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_jb_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[35U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.DOWNSHIFTING.DOWN_BRAKE.Default",
      "GEARSHIFT/DOWNSHIFTING/DOWN_BRAKE/Default", 1,
      &chartInstance->c1_jb_SignalExportProp, 409U);
  }

  chartInstance->c1_kb_SignalExportProp.logName = "";
  chartInstance->c1_kb_SignalExportProp.signalName =
    "GEARSHIFT.DOWNSHIFTING.DOWN_PUSH";
  chartInstance->c1_kb_SignalExportProp.useCustomName = 0;
  chartInstance->c1_kb_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_kb_SignalExportProp.decimate = 0;
  chartInstance->c1_kb_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_kb_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[36U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.DOWNSHIFTING.DOWN_PUSH", "GEARSHIFT/DOWNSHIFTING/DOWN_PUSH", 1,
      &chartInstance->c1_kb_SignalExportProp, 15U);
  }

  chartInstance->c1_lb_SignalExportProp.logName = "";
  chartInstance->c1_lb_SignalExportProp.signalName =
    "GEARSHIFT.DOWNSHIFTING.DOWN_REBOUND";
  chartInstance->c1_lb_SignalExportProp.useCustomName = 0;
  chartInstance->c1_lb_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_lb_SignalExportProp.decimate = 0;
  chartInstance->c1_lb_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_lb_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[37U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.DOWNSHIFTING.DOWN_REBOUND",
      "GEARSHIFT/DOWNSHIFTING/DOWN_REBOUND", 1,
      &chartInstance->c1_lb_SignalExportProp, 16U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[38U] & 1) {
    sdi_register_child_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.DOWNSHIFTING.DOWN_START", "GEARSHIFT/DOWNSHIFTING/DOWN_START",
      4, c1_bc, c1_cc, sizeof(uint8_T), 1, 14U);
  }

  chartInstance->c1_mb_SignalExportProp.logName = "";
  chartInstance->c1_mb_SignalExportProp.signalName =
    "GEARSHIFT.DOWNSHIFTING.DOWN_START";
  chartInstance->c1_mb_SignalExportProp.useCustomName = 0;
  chartInstance->c1_mb_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_mb_SignalExportProp.decimate = 0;
  chartInstance->c1_mb_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_mb_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[38U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.DOWNSHIFTING.DOWN_START", "GEARSHIFT/DOWNSHIFTING/DOWN_START",
      1, &chartInstance->c1_mb_SignalExportProp, 14U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[38U] & 2) {
    sdi_register_leaf_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.DOWNSHIFTING.DOWN_START", "GEARSHIFT/DOWNSHIFTING/DOWN_START",
      4, c1_dc, c1_ec, 1, 14U);
  }

  chartInstance->c1_nb_SignalExportProp.logName = "";
  chartInstance->c1_nb_SignalExportProp.signalName =
    "GEARSHIFT.DOWNSHIFTING.DOWN_START.ChangeClutch";
  chartInstance->c1_nb_SignalExportProp.useCustomName = 0;
  chartInstance->c1_nb_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_nb_SignalExportProp.decimate = 0;
  chartInstance->c1_nb_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_nb_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[39U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.DOWNSHIFTING.DOWN_START.ChangeClutch",
      "GEARSHIFT/DOWNSHIFTING/DOWN_START/ChangeClutch", 1,
      &chartInstance->c1_nb_SignalExportProp, 398U);
  }

  chartInstance->c1_ob_SignalExportProp.logName = "";
  chartInstance->c1_ob_SignalExportProp.signalName =
    "GEARSHIFT.DOWNSHIFTING.DOWN_START.Default";
  chartInstance->c1_ob_SignalExportProp.useCustomName = 0;
  chartInstance->c1_ob_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_ob_SignalExportProp.decimate = 0;
  chartInstance->c1_ob_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_ob_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[40U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.DOWNSHIFTING.DOWN_START.Default",
      "GEARSHIFT/DOWNSHIFTING/DOWN_START/Default", 1,
      &chartInstance->c1_ob_SignalExportProp, 406U);
  }

  chartInstance->c1_pb_SignalExportProp.logName = "";
  chartInstance->c1_pb_SignalExportProp.signalName =
    "GEARSHIFT.DOWNSHIFTING.DOWN_START.SettingNeutral";
  chartInstance->c1_pb_SignalExportProp.useCustomName = 0;
  chartInstance->c1_pb_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_pb_SignalExportProp.decimate = 0;
  chartInstance->c1_pb_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_pb_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[41U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.DOWNSHIFTING.DOWN_START.SettingNeutral",
      "GEARSHIFT/DOWNSHIFTING/DOWN_START/SettingNeutral", 1,
      &chartInstance->c1_pb_SignalExportProp, 399U);
  }

  chartInstance->c1_qb_SignalExportProp.logName = "";
  chartInstance->c1_qb_SignalExportProp.signalName = "GEARSHIFT.DOWN_END";
  chartInstance->c1_qb_SignalExportProp.useCustomName = 0;
  chartInstance->c1_qb_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_qb_SignalExportProp.decimate = 0;
  chartInstance->c1_qb_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_qb_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[42U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.DOWN_END", "GEARSHIFT/DOWN_END", 1,
      &chartInstance->c1_qb_SignalExportProp, 18U);
  }

  chartInstance->c1_rb_SignalExportProp.logName = "";
  chartInstance->c1_rb_SignalExportProp.signalName = "GEARSHIFT.IDLE";
  chartInstance->c1_rb_SignalExportProp.useCustomName = 0;
  chartInstance->c1_rb_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_rb_SignalExportProp.decimate = 0;
  chartInstance->c1_rb_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_rb_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[43U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.IDLE", "GEARSHIFT/IDLE", 1,
      &chartInstance->c1_rb_SignalExportProp, 5U);
  }

  chartInstance->c1_sb_SignalExportProp.logName = "";
  chartInstance->c1_sb_SignalExportProp.signalName = "GEARSHIFT.INIT";
  chartInstance->c1_sb_SignalExportProp.useCustomName = 0;
  chartInstance->c1_sb_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_sb_SignalExportProp.decimate = 0;
  chartInstance->c1_sb_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_sb_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[44U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.INIT", "GEARSHIFT/INIT", 1,
      &chartInstance->c1_sb_SignalExportProp, 7U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[45U] & 1) {
    sdi_register_child_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.UPSHIFTING", "GEARSHIFT/UPSHIFTING", 5, c1_fc, c1_gc, sizeof
      (uint8_T), 1, 693U);
  }

  chartInstance->c1_tb_SignalExportProp.logName = "";
  chartInstance->c1_tb_SignalExportProp.signalName = "GEARSHIFT.UPSHIFTING";
  chartInstance->c1_tb_SignalExportProp.useCustomName = 0;
  chartInstance->c1_tb_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_tb_SignalExportProp.decimate = 0;
  chartInstance->c1_tb_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_tb_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[45U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.UPSHIFTING", "GEARSHIFT/UPSHIFTING", 1,
      &chartInstance->c1_tb_SignalExportProp, 693U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[45U] & 2) {
    sdi_register_leaf_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.UPSHIFTING", "GEARSHIFT/UPSHIFTING", 8, c1_hc, c1_ic, 1, 693U);
  }

  chartInstance->c1_ub_SignalExportProp.logName = "";
  chartInstance->c1_ub_SignalExportProp.signalName =
    "GEARSHIFT.UPSHIFTING.UP_BRAKE";
  chartInstance->c1_ub_SignalExportProp.useCustomName = 0;
  chartInstance->c1_ub_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_ub_SignalExportProp.decimate = 0;
  chartInstance->c1_ub_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_ub_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[46U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.UPSHIFTING.UP_BRAKE", "GEARSHIFT/UPSHIFTING/UP_BRAKE", 1,
      &chartInstance->c1_ub_SignalExportProp, 12U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[47U] & 1) {
    sdi_register_child_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.UPSHIFTING.UP_PUSH", "GEARSHIFT/UPSHIFTING/UP_PUSH", 3, c1_jc,
      c1_kc, sizeof(uint8_T), 1, 10U);
  }

  chartInstance->c1_vb_SignalExportProp.logName = "";
  chartInstance->c1_vb_SignalExportProp.signalName =
    "GEARSHIFT.UPSHIFTING.UP_PUSH";
  chartInstance->c1_vb_SignalExportProp.useCustomName = 0;
  chartInstance->c1_vb_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_vb_SignalExportProp.decimate = 0;
  chartInstance->c1_vb_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_vb_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[47U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.UPSHIFTING.UP_PUSH", "GEARSHIFT/UPSHIFTING/UP_PUSH", 1,
      &chartInstance->c1_vb_SignalExportProp, 10U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[47U] & 2) {
    sdi_register_leaf_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.UPSHIFTING.UP_PUSH", "GEARSHIFT/UPSHIFTING/UP_PUSH", 3, c1_lc,
      c1_mc, 1, 10U);
  }

  chartInstance->c1_wb_SignalExportProp.logName = "";
  chartInstance->c1_wb_SignalExportProp.signalName =
    "GEARSHIFT.UPSHIFTING.UP_PUSH.CutOff";
  chartInstance->c1_wb_SignalExportProp.useCustomName = 0;
  chartInstance->c1_wb_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_wb_SignalExportProp.decimate = 0;
  chartInstance->c1_wb_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_wb_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[48U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.UPSHIFTING.UP_PUSH.CutOff",
      "GEARSHIFT/UPSHIFTING/UP_PUSH/CutOff", 1,
      &chartInstance->c1_wb_SignalExportProp, 423U);
  }

  chartInstance->c1_xb_SignalExportProp.logName = "";
  chartInstance->c1_xb_SignalExportProp.signalName =
    "GEARSHIFT.UPSHIFTING.UP_PUSH.Default";
  chartInstance->c1_xb_SignalExportProp.useCustomName = 0;
  chartInstance->c1_xb_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_xb_SignalExportProp.decimate = 0;
  chartInstance->c1_xb_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_xb_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[49U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.UPSHIFTING.UP_PUSH.Default",
      "GEARSHIFT/UPSHIFTING/UP_PUSH/Default", 1,
      &chartInstance->c1_xb_SignalExportProp, 422U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[50U] & 1) {
    sdi_register_child_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.UPSHIFTING.UP_REBOUND", "GEARSHIFT/UPSHIFTING/UP_REBOUND", 3,
      c1_nc, c1_oc, sizeof(uint8_T), 1, 11U);
  }

  chartInstance->c1_yb_SignalExportProp.logName = "";
  chartInstance->c1_yb_SignalExportProp.signalName =
    "GEARSHIFT.UPSHIFTING.UP_REBOUND";
  chartInstance->c1_yb_SignalExportProp.useCustomName = 0;
  chartInstance->c1_yb_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_yb_SignalExportProp.decimate = 0;
  chartInstance->c1_yb_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_yb_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[50U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.UPSHIFTING.UP_REBOUND", "GEARSHIFT/UPSHIFTING/UP_REBOUND", 1,
      &chartInstance->c1_yb_SignalExportProp, 11U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[50U] & 2) {
    sdi_register_leaf_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.UPSHIFTING.UP_REBOUND", "GEARSHIFT/UPSHIFTING/UP_REBOUND", 3,
      c1_pc, c1_qc, 1, 11U);
  }

  chartInstance->c1_ac_SignalExportProp.logName = "";
  chartInstance->c1_ac_SignalExportProp.signalName =
    "GEARSHIFT.UPSHIFTING.UP_REBOUND.Default";
  chartInstance->c1_ac_SignalExportProp.useCustomName = 0;
  chartInstance->c1_ac_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_ac_SignalExportProp.decimate = 0;
  chartInstance->c1_ac_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_ac_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[51U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.UPSHIFTING.UP_REBOUND.Default",
      "GEARSHIFT/UPSHIFTING/UP_REBOUND/Default", 1,
      &chartInstance->c1_ac_SignalExportProp, 390U);
  }

  chartInstance->c1_bc_SignalExportProp.logName = "";
  chartInstance->c1_bc_SignalExportProp.signalName =
    "GEARSHIFT.UPSHIFTING.UP_REBOUND.SettingNeutral";
  chartInstance->c1_bc_SignalExportProp.useCustomName = 0;
  chartInstance->c1_bc_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_bc_SignalExportProp.decimate = 0;
  chartInstance->c1_bc_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_bc_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[52U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.UPSHIFTING.UP_REBOUND.SettingNeutral",
      "GEARSHIFT/UPSHIFTING/UP_REBOUND/SettingNeutral", 1,
      &chartInstance->c1_bc_SignalExportProp, 391U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[53U] & 1) {
    sdi_register_child_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.UPSHIFTING.UP_START", "GEARSHIFT/UPSHIFTING/UP_START", 3, c1_rc,
      c1_sc, sizeof(uint8_T), 1, 9U);
  }

  chartInstance->c1_cc_SignalExportProp.logName = "";
  chartInstance->c1_cc_SignalExportProp.signalName =
    "GEARSHIFT.UPSHIFTING.UP_START";
  chartInstance->c1_cc_SignalExportProp.useCustomName = 0;
  chartInstance->c1_cc_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_cc_SignalExportProp.decimate = 0;
  chartInstance->c1_cc_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_cc_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[53U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.UPSHIFTING.UP_START", "GEARSHIFT/UPSHIFTING/UP_START", 1,
      &chartInstance->c1_cc_SignalExportProp, 9U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[53U] & 2) {
    sdi_register_leaf_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.UPSHIFTING.UP_START", "GEARSHIFT/UPSHIFTING/UP_START", 3, c1_tc,
      c1_uc, 1, 9U);
  }

  chartInstance->c1_dc_SignalExportProp.logName = "";
  chartInstance->c1_dc_SignalExportProp.signalName =
    "GEARSHIFT.UPSHIFTING.UP_START.Default";
  chartInstance->c1_dc_SignalExportProp.useCustomName = 0;
  chartInstance->c1_dc_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_dc_SignalExportProp.decimate = 0;
  chartInstance->c1_dc_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_dc_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[54U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.UPSHIFTING.UP_START.Default",
      "GEARSHIFT/UPSHIFTING/UP_START/Default", 1,
      &chartInstance->c1_dc_SignalExportProp, 385U);
  }

  chartInstance->c1_ec_SignalExportProp.logName = "";
  chartInstance->c1_ec_SignalExportProp.signalName =
    "GEARSHIFT.UPSHIFTING.UP_START.SettingNeutral";
  chartInstance->c1_ec_SignalExportProp.useCustomName = 0;
  chartInstance->c1_ec_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_ec_SignalExportProp.decimate = 0;
  chartInstance->c1_ec_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_ec_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[55U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.UPSHIFTING.UP_START.SettingNeutral",
      "GEARSHIFT/UPSHIFTING/UP_START/SettingNeutral", 1,
      &chartInstance->c1_ec_SignalExportProp, 383U);
  }

  chartInstance->c1_fc_SignalExportProp.logName = "";
  chartInstance->c1_fc_SignalExportProp.signalName = "GEARSHIFT.UP_END";
  chartInstance->c1_fc_SignalExportProp.useCustomName = 0;
  chartInstance->c1_fc_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_fc_SignalExportProp.decimate = 0;
  chartInstance->c1_fc_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_fc_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[56U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "GEARSHIFT.UP_END", "GEARSHIFT/UP_END", 1,
      &chartInstance->c1_fc_SignalExportProp, 13U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[57U] & 1) {
    sdi_register_child_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "START_ENGINE", "START_ENGINE", 4, c1_vc, c1_wc, sizeof(uint8_T), 1, 479U);
  }

  chartInstance->c1_gc_SignalExportProp.logName = "";
  chartInstance->c1_gc_SignalExportProp.signalName = "START_ENGINE";
  chartInstance->c1_gc_SignalExportProp.useCustomName = 0;
  chartInstance->c1_gc_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_gc_SignalExportProp.decimate = 0;
  chartInstance->c1_gc_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_gc_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[57U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "START_ENGINE", "START_ENGINE", 1, &chartInstance->c1_gc_SignalExportProp,
      479U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[57U] & 2) {
    sdi_register_leaf_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "START_ENGINE", "START_ENGINE", 4, c1_xc, c1_yc, 1, 479U);
  }

  chartInstance->c1_hc_SignalExportProp.logName = "";
  chartInstance->c1_hc_SignalExportProp.signalName = "START_ENGINE.START";
  chartInstance->c1_hc_SignalExportProp.useCustomName = 0;
  chartInstance->c1_hc_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_hc_SignalExportProp.decimate = 0;
  chartInstance->c1_hc_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_hc_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[58U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "START_ENGINE.START", "START_ENGINE/START", 1,
      &chartInstance->c1_hc_SignalExportProp, 482U);
  }

  chartInstance->c1_ic_SignalExportProp.logName = "";
  chartInstance->c1_ic_SignalExportProp.signalName = "START_ENGINE.STOP";
  chartInstance->c1_ic_SignalExportProp.useCustomName = 0;
  chartInstance->c1_ic_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_ic_SignalExportProp.decimate = 0;
  chartInstance->c1_ic_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_ic_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[59U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "START_ENGINE.STOP", "START_ENGINE/STOP", 1,
      &chartInstance->c1_ic_SignalExportProp, 483U);
  }

  chartInstance->c1_jc_SignalExportProp.logName = "";
  chartInstance->c1_jc_SignalExportProp.signalName = "START_ENGINE.WAIT";
  chartInstance->c1_jc_SignalExportProp.useCustomName = 0;
  chartInstance->c1_jc_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_jc_SignalExportProp.decimate = 0;
  chartInstance->c1_jc_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_jc_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[60U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "START_ENGINE.WAIT", "START_ENGINE/WAIT", 1,
      &chartInstance->c1_jc_SignalExportProp, 494U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[61U] & 1) {
    sdi_register_child_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "SCAN_ADC", "SCAN_ADC", 3, c1_ad, c1_bd, sizeof(uint8_T), 1, 929U);
  }

  chartInstance->c1_kc_SignalExportProp.logName = "";
  chartInstance->c1_kc_SignalExportProp.signalName = "SCAN_ADC";
  chartInstance->c1_kc_SignalExportProp.useCustomName = 0;
  chartInstance->c1_kc_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_kc_SignalExportProp.decimate = 0;
  chartInstance->c1_kc_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_kc_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[61U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "SCAN_ADC", "SCAN_ADC", 1, &chartInstance->c1_kc_SignalExportProp, 929U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[61U] & 2) {
    sdi_register_leaf_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "SCAN_ADC", "SCAN_ADC", 3, c1_cd, c1_dd, 1, 929U);
  }

  chartInstance->c1_lc_SignalExportProp.logName = "";
  chartInstance->c1_lc_SignalExportProp.signalName = "SCAN_ADC.SCAN";
  chartInstance->c1_lc_SignalExportProp.useCustomName = 0;
  chartInstance->c1_lc_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_lc_SignalExportProp.decimate = 0;
  chartInstance->c1_lc_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_lc_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[62U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "SCAN_ADC.SCAN", "SCAN_ADC/SCAN", 1,
      &chartInstance->c1_lc_SignalExportProp, 932U);
  }

  chartInstance->c1_mc_SignalExportProp.logName = "";
  chartInstance->c1_mc_SignalExportProp.signalName = "SCAN_ADC.WAIT";
  chartInstance->c1_mc_SignalExportProp.useCustomName = 0;
  chartInstance->c1_mc_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_mc_SignalExportProp.decimate = 0;
  chartInstance->c1_mc_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_mc_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[63U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "SCAN_ADC.WAIT", "SCAN_ADC/WAIT", 1,
      &chartInstance->c1_mc_SignalExportProp, 930U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[64U] & 1) {
    sdi_register_child_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "EEPROM_TRIGGER", "EEPROM_TRIGGER", 3, c1_ed, c1_fd, sizeof(uint8_T), 1,
      940U);
  }

  chartInstance->c1_nc_SignalExportProp.logName = "";
  chartInstance->c1_nc_SignalExportProp.signalName = "EEPROM_TRIGGER";
  chartInstance->c1_nc_SignalExportProp.useCustomName = 0;
  chartInstance->c1_nc_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_nc_SignalExportProp.decimate = 0;
  chartInstance->c1_nc_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_nc_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[64U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "EEPROM_TRIGGER", "EEPROM_TRIGGER", 1,
      &chartInstance->c1_nc_SignalExportProp, 940U);
  }

  if (chartInstance->c1_sdiLoggedStatesBuffer[64U] & 2) {
    sdi_register_leaf_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "EEPROM_TRIGGER", "EEPROM_TRIGGER", 3, c1_gd, c1_hd, 1, 940U);
  }

  chartInstance->c1_oc_SignalExportProp.logName = "";
  chartInstance->c1_oc_SignalExportProp.signalName = "EEPROM_TRIGGER.SEND";
  chartInstance->c1_oc_SignalExportProp.useCustomName = 0;
  chartInstance->c1_oc_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_oc_SignalExportProp.decimate = 0;
  chartInstance->c1_oc_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_oc_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[65U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "EEPROM_TRIGGER.SEND", "EEPROM_TRIGGER/SEND", 1,
      &chartInstance->c1_oc_SignalExportProp, 946U);
  }

  chartInstance->c1_pc_SignalExportProp.logName = "";
  chartInstance->c1_pc_SignalExportProp.signalName = "EEPROM_TRIGGER.WAIT";
  chartInstance->c1_pc_SignalExportProp.useCustomName = 0;
  chartInstance->c1_pc_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_pc_SignalExportProp.decimate = 0;
  chartInstance->c1_pc_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_pc_SignalExportProp.decimation = 2U;
  if (chartInstance->c1_sdiLoggedStatesBuffer[66U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c1_sdiBlockInfo,
      "EEPROM_TRIGGER.WAIT", "EEPROM_TRIGGER/WAIT", 1,
      &chartInstance->c1_pc_SignalExportProp, 944U);
  }

  chartInstance->c1_qc_SignalExportProp.logName = "";
  chartInstance->c1_qc_SignalExportProp.signalName = "clutchCurrVal";
  chartInstance->c1_qc_SignalExportProp.useCustomName = 0;
  chartInstance->c1_qc_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_qc_SignalExportProp.decimate = 0;
  chartInstance->c1_qc_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_qc_SignalExportProp.decimation = 1U;
  if (chartInstance->c1_sdiLoggedDataBuffer[1U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c1_sdiBlockInfo,
      "clutchCurrVal", "", 1, c1_id, 1, 3, 0, 0,
      &chartInstance->c1_qc_SignalExportProp, "", 123U);
  }

  chartInstance->c1_rc_SignalExportProp.logName = "";
  chartInstance->c1_rc_SignalExportProp.signalName = "lastModeCom";
  chartInstance->c1_rc_SignalExportProp.useCustomName = 0;
  chartInstance->c1_rc_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_rc_SignalExportProp.decimate = 0;
  chartInstance->c1_rc_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_rc_SignalExportProp.decimation = 1U;
  if (chartInstance->c1_sdiLoggedDataBuffer[2U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c1_sdiBlockInfo,
      "lastModeCom", "", 1, c1_jd, 1, 5, 0, 0,
      &chartInstance->c1_rc_SignalExportProp, "", 834U);
  }

  chartInstance->c1_sc_SignalExportProp.logName = "";
  chartInstance->c1_sc_SignalExportProp.signalName = "lastShift";
  chartInstance->c1_sc_SignalExportProp.useCustomName = 0;
  chartInstance->c1_sc_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_sc_SignalExportProp.decimate = 0;
  chartInstance->c1_sc_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_sc_SignalExportProp.decimation = 1U;
  if (chartInstance->c1_sdiLoggedDataBuffer[8U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c1_sdiBlockInfo,
      "lastShift", "", 1, c1_kd, 1, 3, 0, 0,
      &chartInstance->c1_sc_SignalExportProp, "", 715U);
  }

  chartInstance->c1_tc_SignalExportProp.logName = "";
  chartInstance->c1_tc_SignalExportProp.signalName = "stateFb";
  chartInstance->c1_tc_SignalExportProp.useCustomName = 0;
  chartInstance->c1_tc_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_tc_SignalExportProp.decimate = 0;
  chartInstance->c1_tc_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_tc_SignalExportProp.decimation = 1U;
  if (chartInstance->c1_sdiLoggedDataBuffer[10U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c1_sdiBlockInfo,
      "stateFb", "", 1, c1_ld, 1, 5, 0, 0,
      &chartInstance->c1_tc_SignalExportProp, "", 833U);
  }

  chartInstance->c1_uc_SignalExportProp.logName = "";
  chartInstance->c1_uc_SignalExportProp.signalName = "lastAacCom";
  chartInstance->c1_uc_SignalExportProp.useCustomName = 0;
  chartInstance->c1_uc_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_uc_SignalExportProp.decimate = 0;
  chartInstance->c1_uc_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_uc_SignalExportProp.decimation = 1U;
  if (chartInstance->c1_sdiLoggedDataBuffer[15U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c1_sdiBlockInfo,
      "lastAacCom", "MODES", 1, c1_md, 1, 5, 0, 0,
      &chartInstance->c1_uc_SignalExportProp, "", 627U);
  }

  chartInstance->c1_vc_SignalExportProp.logName = "";
  chartInstance->c1_vc_SignalExportProp.signalName = "lastShiftCom";
  chartInstance->c1_vc_SignalExportProp.useCustomName = 0;
  chartInstance->c1_vc_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_vc_SignalExportProp.decimate = 0;
  chartInstance->c1_vc_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_vc_SignalExportProp.decimation = 1U;
  if (chartInstance->c1_sdiLoggedDataBuffer[16U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c1_sdiBlockInfo,
      "lastShiftCom", "MODES", 1, c1_nd, 1, 5, 0, 0,
      &chartInstance->c1_vc_SignalExportProp, "", 681U);
  }

  chartInstance->c1_wc_SignalExportProp.logName = "";
  chartInstance->c1_wc_SignalExportProp.signalName = "lastClutchCom";
  chartInstance->c1_wc_SignalExportProp.useCustomName = 0;
  chartInstance->c1_wc_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_wc_SignalExportProp.decimate = 0;
  chartInstance->c1_wc_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_wc_SignalExportProp.decimation = 1U;
  if (chartInstance->c1_sdiLoggedDataBuffer[17U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c1_sdiBlockInfo,
      "lastClutchCom", "MODES", 1, c1_od, 1, 3, 0, 0,
      &chartInstance->c1_wc_SignalExportProp, "", 684U);
  }

  chartInstance->c1_xc_SignalExportProp.logName = "";
  chartInstance->c1_xc_SignalExportProp.signalName = "lastAutoXCom";
  chartInstance->c1_xc_SignalExportProp.useCustomName = 0;
  chartInstance->c1_xc_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_xc_SignalExportProp.decimate = 0;
  chartInstance->c1_xc_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_xc_SignalExportProp.decimation = 1U;
  if (chartInstance->c1_sdiLoggedDataBuffer[18U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c1_sdiBlockInfo,
      "lastAutoXCom", "MODES", 1, c1_pd, 1, 5, 0, 0,
      &chartInstance->c1_xc_SignalExportProp, "", 1043U);
  }

  chartInstance->c1_yc_SignalExportProp.logName = "";
  chartInstance->c1_yc_SignalExportProp.signalName = "buzzerCounter";
  chartInstance->c1_yc_SignalExportProp.useCustomName = 0;
  chartInstance->c1_yc_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_yc_SignalExportProp.decimate = 0;
  chartInstance->c1_yc_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_yc_SignalExportProp.decimation = 1U;
  if (chartInstance->c1_sdiLoggedDataBuffer[19U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c1_sdiBlockInfo,
      "buzzerCounter", "MODES", 1, c1_qd, 1, 5, 0, 0,
      &chartInstance->c1_yc_SignalExportProp, "", 1063U);
  }

  chartInstance->c1_ad_SignalExportProp.logName = "";
  chartInstance->c1_ad_SignalExportProp.signalName = "aacCounter";
  chartInstance->c1_ad_SignalExportProp.useCustomName = 0;
  chartInstance->c1_ad_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_ad_SignalExportProp.decimate = 0;
  chartInstance->c1_ad_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_ad_SignalExportProp.decimation = 1U;
  if (chartInstance->c1_sdiLoggedDataBuffer[29U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c1_sdiBlockInfo,
      "aacCounter", "MODES/ACCELERATION/ACC", 1, c1_rd, 1, 5, 0, 0,
      &chartInstance->c1_ad_SignalExportProp, "", 550U);
  }

  chartInstance->c1_bd_SignalExportProp.logName = "";
  chartInstance->c1_bd_SignalExportProp.signalName = "aac_clutchValue";
  chartInstance->c1_bd_SignalExportProp.useCustomName = 0;
  chartInstance->c1_bd_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_bd_SignalExportProp.decimate = 0;
  chartInstance->c1_bd_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_bd_SignalExportProp.decimation = 1U;
  if (chartInstance->c1_sdiLoggedDataBuffer[30U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c1_sdiBlockInfo,
      "aac_clutchValue", "MODES/ACCELERATION/ACC", 1, c1_sd, 1, 0, 0, 0,
      &chartInstance->c1_bd_SignalExportProp, "", 561U);
  }

  chartInstance->c1_cd_SignalExportProp.logName = "";
  chartInstance->c1_cd_SignalExportProp.signalName = "aac_clutchStep";
  chartInstance->c1_cd_SignalExportProp.useCustomName = 0;
  chartInstance->c1_cd_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_cd_SignalExportProp.decimate = 0;
  chartInstance->c1_cd_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_cd_SignalExportProp.decimation = 1U;
  if (chartInstance->c1_sdiLoggedDataBuffer[31U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c1_sdiBlockInfo,
      "aac_clutchStep", "MODES/ACCELERATION/ACC", 1, c1_td, 1, 0, 0, 0,
      &chartInstance->c1_cd_SignalExportProp, "", 563U);
  }

  chartInstance->c1_dd_SignalExportProp.logName = "";
  chartInstance->c1_dd_SignalExportProp.signalName = "aac_dtRelease";
  chartInstance->c1_dd_SignalExportProp.useCustomName = 0;
  chartInstance->c1_dd_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_dd_SignalExportProp.decimate = 0;
  chartInstance->c1_dd_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_dd_SignalExportProp.decimation = 1U;
  if (chartInstance->c1_sdiLoggedDataBuffer[32U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c1_sdiBlockInfo,
      "aac_dtRelease", "MODES/ACCELERATION/ACC", 1, c1_ud, 1, 6, 0, 0,
      &chartInstance->c1_dd_SignalExportProp, "", 564U);
  }

  chartInstance->c1_ed_SignalExportProp.logName = "";
  chartInstance->c1_ed_SignalExportProp.signalName = "autoXCounter";
  chartInstance->c1_ed_SignalExportProp.useCustomName = 0;
  chartInstance->c1_ed_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_ed_SignalExportProp.decimate = 0;
  chartInstance->c1_ed_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_ed_SignalExportProp.decimation = 1U;
  if (chartInstance->c1_sdiLoggedDataBuffer[48U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c1_sdiBlockInfo,
      "autoXCounter", "MODES/AUTOCROSS/LAUNCH", 1, c1_vd, 1, 5, 0, 0,
      &chartInstance->c1_ed_SignalExportProp, "", 958U);
  }

  chartInstance->c1_fd_SignalExportProp.logName = "";
  chartInstance->c1_fd_SignalExportProp.signalName = "autoX_clutchValue";
  chartInstance->c1_fd_SignalExportProp.useCustomName = 0;
  chartInstance->c1_fd_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_fd_SignalExportProp.decimate = 0;
  chartInstance->c1_fd_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_fd_SignalExportProp.decimation = 1U;
  if (chartInstance->c1_sdiLoggedDataBuffer[49U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c1_sdiBlockInfo,
      "autoX_clutchValue", "MODES/AUTOCROSS/LAUNCH", 1, c1_wd, 1, 0, 0, 0,
      &chartInstance->c1_fd_SignalExportProp, "", 959U);
  }

  chartInstance->c1_gd_SignalExportProp.logName = "";
  chartInstance->c1_gd_SignalExportProp.signalName = "autoX_clutchStep";
  chartInstance->c1_gd_SignalExportProp.useCustomName = 0;
  chartInstance->c1_gd_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_gd_SignalExportProp.decimate = 0;
  chartInstance->c1_gd_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_gd_SignalExportProp.decimation = 1U;
  if (chartInstance->c1_sdiLoggedDataBuffer[50U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c1_sdiBlockInfo,
      "autoX_clutchStep", "MODES/AUTOCROSS/LAUNCH", 1, c1_xd, 1, 0, 0, 0,
      &chartInstance->c1_gd_SignalExportProp, "", 960U);
  }

  chartInstance->c1_hd_SignalExportProp.logName = "";
  chartInstance->c1_hd_SignalExportProp.signalName = "autoX_dtRelease";
  chartInstance->c1_hd_SignalExportProp.useCustomName = 0;
  chartInstance->c1_hd_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_hd_SignalExportProp.decimate = 0;
  chartInstance->c1_hd_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_hd_SignalExportProp.decimation = 1U;
  if (chartInstance->c1_sdiLoggedDataBuffer[51U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c1_sdiBlockInfo,
      "autoX_dtRelease", "MODES/AUTOCROSS/LAUNCH", 1, c1_yd, 1, 6, 0, 0,
      &chartInstance->c1_hd_SignalExportProp, "", 961U);
  }

  chartInstance->c1_id_SignalExportProp.logName = "";
  chartInstance->c1_id_SignalExportProp.signalName = "ticksCounter";
  chartInstance->c1_id_SignalExportProp.useCustomName = 0;
  chartInstance->c1_id_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_id_SignalExportProp.decimate = 0;
  chartInstance->c1_id_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_id_SignalExportProp.decimation = 1U;
  if (chartInstance->c1_sdiLoggedDataBuffer[54U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c1_sdiBlockInfo,
      "ticksCounter", "GEARSHIFT", 1, c1_ae, 1, 6, 0, 0,
      &chartInstance->c1_id_SignalExportProp, "", 45U);
  }

  chartInstance->c1_jd_SignalExportProp.logName = "";
  chartInstance->c1_jd_SignalExportProp.signalName = "counterWait";
  chartInstance->c1_jd_SignalExportProp.useCustomName = 0;
  chartInstance->c1_jd_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_jd_SignalExportProp.decimate = 0;
  chartInstance->c1_jd_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_jd_SignalExportProp.decimation = 1U;
  if (chartInstance->c1_sdiLoggedDataBuffer[58U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c1_sdiBlockInfo,
      "counterWait", "EEPROM_TRIGGER", 1, c1_be, 1, 0, 0, 0,
      &chartInstance->c1_jd_SignalExportProp, "", 950U);
  }

  chartInstance->c1_kd_SignalExportProp.logName = "";
  chartInstance->c1_kd_SignalExportProp.signalName = "lastCom";
  chartInstance->c1_kd_SignalExportProp.useCustomName = 0;
  chartInstance->c1_kd_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_kd_SignalExportProp.decimate = 0;
  chartInstance->c1_kd_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_kd_SignalExportProp.decimation = 1U;
  if (chartInstance->c1_sdiLoggedDataBuffer[59U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c1_sdiBlockInfo,
      "lastCom", "START_ENGINE", 1, c1_ce, 1, 3, 0, 0,
      &chartInstance->c1_kd_SignalExportProp, "", 484U);
  }

  chartInstance->c1_ld_SignalExportProp.logName = "";
  chartInstance->c1_ld_SignalExportProp.signalName = "startCounter";
  chartInstance->c1_ld_SignalExportProp.useCustomName = 0;
  chartInstance->c1_ld_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_ld_SignalExportProp.decimate = 0;
  chartInstance->c1_ld_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_ld_SignalExportProp.decimation = 1U;
  if (chartInstance->c1_sdiLoggedDataBuffer[60U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c1_sdiBlockInfo,
      "startCounter", "START_ENGINE", 1, c1_de, 1, 3, 0, 0,
      &chartInstance->c1_ld_SignalExportProp, "", 488U);
  }

  chartInstance->c1_md_SignalExportProp.logName = "";
  chartInstance->c1_md_SignalExportProp.signalName = "timerCounter";
  chartInstance->c1_md_SignalExportProp.useCustomName = 0;
  chartInstance->c1_md_SignalExportProp.limitDataPoints = 0;
  chartInstance->c1_md_SignalExportProp.decimate = 0;
  chartInstance->c1_md_SignalExportProp.maxPoints = 5000U;
  chartInstance->c1_md_SignalExportProp.decimation = 1U;
  if (chartInstance->c1_sdiLoggedDataBuffer[61U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c1_sdiBlockInfo,
      "timerCounter", "SCAN_ADC", 1, c1_ee, 1, 5, 0, 0,
      &chartInstance->c1_md_SignalExportProp, "", 938U);
  }
}

static void c1_sdiTerminate(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  sdi_database_terminate(&chartInstance->c1_sdiBlockInfo);
}

static void initialize_c1_GCU_Model_genCode(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  int32_T c1_i0;
  int32_T c1_i1;
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc1_GCU_Model_genCode(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_is_active_EEPROM_TRIGGER = 0U;
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 64, 940U, (int32_T)
    (chartInstance->c1_is_active_EEPROM_TRIGGER == 1));
  chartInstance->c1_is_EEPROM_TRIGGER = c1_IN_NO_ACTIVE_CHILD;
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 64, 940U, (void *)
    &chartInstance->c1_is_EEPROM_TRIGGER);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 65, 946U, (int32_T)
    (chartInstance->c1_is_EEPROM_TRIGGER == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 66, 944U, (int32_T)
    (chartInstance->c1_is_EEPROM_TRIGGER == 2));
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 64, 940U, 0);
  chartInstance->c1_tp_EEPROM_TRIGGER = 0U;
  chartInstance->c1_tp_SEND = 0U;
  chartInstance->c1_tp_WAIT = 0U;
  chartInstance->c1_is_active_GEARSHIFT = 0U;
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 31, 1U, (int32_T)
    (chartInstance->c1_is_active_GEARSHIFT == 1));
  chartInstance->c1_is_GEARSHIFT = c1_IN_NO_ACTIVE_CHILD;
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 31, 1U, (void *)
    &chartInstance->c1_is_GEARSHIFT);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 32, 697U, (int32_T)
    (chartInstance->c1_is_GEARSHIFT == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 42, 18U, (int32_T)
    (chartInstance->c1_is_GEARSHIFT == 2));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 43, 5U, (int32_T)
    (chartInstance->c1_is_GEARSHIFT == 3));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 44, 7U, (int32_T)
    (chartInstance->c1_is_GEARSHIFT == 4));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 45, 693U, (int32_T)
    (chartInstance->c1_is_GEARSHIFT == 5));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 56, 13U, (int32_T)
    (chartInstance->c1_is_GEARSHIFT == 6));
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 0);
  chartInstance->c1_tp_GEARSHIFT = 0U;
  chartInstance->c1_is_DOWNSHIFTING = c1_IN_NO_ACTIVE_CHILD;
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 32, 697U, (void *)
    &chartInstance->c1_is_DOWNSHIFTING);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 33, 17U, (int32_T)
    (chartInstance->c1_is_DOWNSHIFTING == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 36, 15U, (int32_T)
    (chartInstance->c1_is_DOWNSHIFTING == 2));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 37, 16U, (int32_T)
    (chartInstance->c1_is_DOWNSHIFTING == 3));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 38, 14U, (int32_T)
    (chartInstance->c1_is_DOWNSHIFTING == 4));
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 0);
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 32, 697U, 0);
  chartInstance->c1_tp_DOWNSHIFTING = 0U;
  chartInstance->c1_is_DOWN_BRAKE = c1_IN_NO_ACTIVE_CHILD;
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 33, 17U, (void *)
    &chartInstance->c1_is_DOWN_BRAKE);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 34, 410U, (int32_T)
    (chartInstance->c1_is_DOWN_BRAKE == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 35, 409U, (int32_T)
    (chartInstance->c1_is_DOWN_BRAKE == 2));
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 0);
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 32, 697U, 0);
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 33, 17U, 0);
  chartInstance->c1_tp_DOWN_BRAKE = 0U;
  chartInstance->c1_b_tp_ChangeClutch = 0U;
  chartInstance->c1_e_tp_Default = 0U;
  chartInstance->c1_tp_DOWN_PUSH = 0U;
  chartInstance->c1_tp_DOWN_REBOUND = 0U;
  chartInstance->c1_is_DOWN_START = c1_IN_NO_ACTIVE_CHILD;
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 38, 14U, (void *)
    &chartInstance->c1_is_DOWN_START);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 39, 398U, (int32_T)
    (chartInstance->c1_is_DOWN_START == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 40, 406U, (int32_T)
    (chartInstance->c1_is_DOWN_START == 2));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 41, 399U, (int32_T)
    (chartInstance->c1_is_DOWN_START == 3));
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 0);
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 32, 697U, 0);
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 38, 14U, 0);
  chartInstance->c1_tp_DOWN_START = 0U;
  chartInstance->c1_tp_ChangeClutch = 0U;
  chartInstance->c1_d_tp_Default = 0U;
  chartInstance->c1_c_tp_SettingNeutral = 0U;
  chartInstance->c1_tp_DOWN_END = 0U;
  chartInstance->c1_tp_IDLE = 0U;
  chartInstance->c1_b_tp_INIT = 0U;
  chartInstance->c1_is_UPSHIFTING = c1_IN_NO_ACTIVE_CHILD;
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 45, 693U, (void *)
    &chartInstance->c1_is_UPSHIFTING);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 46, 12U, (int32_T)
    (chartInstance->c1_is_UPSHIFTING == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 47, 10U, (int32_T)
    (chartInstance->c1_is_UPSHIFTING == 2));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 50, 11U, (int32_T)
    (chartInstance->c1_is_UPSHIFTING == 3));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 53, 9U, (int32_T)
    (chartInstance->c1_is_UPSHIFTING == 4));
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 0);
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 45, 693U, 0);
  chartInstance->c1_tp_UPSHIFTING = 0U;
  chartInstance->c1_tp_UP_BRAKE = 0U;
  chartInstance->c1_is_UP_PUSH = c1_IN_NO_ACTIVE_CHILD;
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 47, 10U, (void *)
    &chartInstance->c1_is_UP_PUSH);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 48, 423U, (int32_T)
    (chartInstance->c1_is_UP_PUSH == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 49, 422U, (int32_T)
    (chartInstance->c1_is_UP_PUSH == 2));
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 0);
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 45, 693U, 0);
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 47, 10U, 0);
  chartInstance->c1_tp_UP_PUSH = 0U;
  chartInstance->c1_tp_CutOff = 0U;
  chartInstance->c1_b_tp_Default = 0U;
  chartInstance->c1_is_UP_REBOUND = c1_IN_NO_ACTIVE_CHILD;
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 50, 11U, (void *)
    &chartInstance->c1_is_UP_REBOUND);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 51, 390U, (int32_T)
    (chartInstance->c1_is_UP_REBOUND == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 52, 391U, (int32_T)
    (chartInstance->c1_is_UP_REBOUND == 2));
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 0);
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 45, 693U, 0);
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 50, 11U, 0);
  chartInstance->c1_tp_UP_REBOUND = 0U;
  chartInstance->c1_tp_Default = 0U;
  chartInstance->c1_tp_SettingNeutral = 0U;
  chartInstance->c1_is_UP_START = c1_IN_NO_ACTIVE_CHILD;
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 53, 9U, (void *)
    &chartInstance->c1_is_UP_START);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 54, 385U, (int32_T)
    (chartInstance->c1_is_UP_START == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 55, 383U, (int32_T)
    (chartInstance->c1_is_UP_START == 2));
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 0);
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 45, 693U, 0);
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 53, 9U, 0);
  chartInstance->c1_tp_UP_START = 0U;
  chartInstance->c1_c_tp_Default = 0U;
  chartInstance->c1_b_tp_SettingNeutral = 0U;
  chartInstance->c1_tp_UP_END = 0U;
  chartInstance->c1_is_active_MODES = 0U;
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 1, 418U, (int32_T)
    (chartInstance->c1_is_active_MODES == 1));
  chartInstance->c1_is_MODES = c1_IN_NO_ACTIVE_CHILD;
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 1, 418U, (void *)
    &chartInstance->c1_is_MODES);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
    (chartInstance->c1_is_MODES == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
    (chartInstance->c1_is_MODES == 2));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
    (chartInstance->c1_is_MODES == 3));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
    (chartInstance->c1_is_MODES == 4));
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 0);
  chartInstance->c1_tp_MODES = 0U;
  chartInstance->c1_is_ACCELERATION = c1_IN_NO_ACTIVE_CHILD;
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 2, 820U, (void *)
    &chartInstance->c1_is_ACCELERATION);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 3, 434U, (int32_T)
    (chartInstance->c1_is_ACCELERATION == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 11, 821U, (int32_T)
    (chartInstance->c1_is_ACCELERATION == 2));
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 0);
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 2, 820U, 0);
  chartInstance->c1_tp_ACCELERATION = 0U;
  chartInstance->c1_is_ACC = c1_IN_NO_ACTIVE_CHILD;
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 3, 434U, (void *)
    &chartInstance->c1_is_ACC);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 4, 538U, (int32_T)
    (chartInstance->c1_is_ACC == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 10, 515U, (int32_T)
    (chartInstance->c1_is_ACC == 2));
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 0);
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 2, 820U, 0);
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 3, 434U, 0);
  chartInstance->c1_tp_ACC = 0U;
  chartInstance->c1_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 4, 538U, (void *)
    &chartInstance->c1_is_ACTIVE);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 5, 545U, (int32_T)
    (chartInstance->c1_is_ACTIVE == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 6, 544U, (int32_T)
    (chartInstance->c1_is_ACTIVE == 2));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 7, 514U, (int32_T)
    (chartInstance->c1_is_ACTIVE == 3));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 8, 543U, (int32_T)
    (chartInstance->c1_is_ACTIVE == 4));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 9, 547U, (int32_T)
    (chartInstance->c1_is_ACTIVE == 5));
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 0);
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 2, 820U, 0);
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 3, 434U, 0);
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 4, 538U, 0);
  chartInstance->c1_tp_ACTIVE = 0U;
  chartInstance->c1_tp_READY = 0U;
  chartInstance->c1_tp_RELEASING = 0U;
  chartInstance->c1_tp_RUNNING = 0U;
  chartInstance->c1_tp_START = 0U;
  chartInstance->c1_tp_START_RELEASE = 0U;
  chartInstance->c1_tp_STOPPING = 0U;
  chartInstance->c1_tp_DEFAULT = 0U;
  chartInstance->c1_is_AUTOCROSS = c1_IN_NO_ACTIVE_CHILD;
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 12, 951U, (void *)
    &chartInstance->c1_is_AUTOCROSS);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 13, 952U, (int32_T)
    (chartInstance->c1_is_AUTOCROSS == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 14, 974U, (int32_T)
    (chartInstance->c1_is_AUTOCROSS == 2));
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 0);
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 12, 951U, 0);
  chartInstance->c1_tp_AUTOCROSS = 0U;
  chartInstance->c1_b_tp_DEFAULT = 0U;
  chartInstance->c1_is_LAUNCH = c1_IN_NO_ACTIVE_CHILD;
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 14, 974U, (void *)
    &chartInstance->c1_is_LAUNCH);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 15, 985U, (int32_T)
    (chartInstance->c1_is_LAUNCH == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 21, 1028U, (int32_T)
    (chartInstance->c1_is_LAUNCH == 2));
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 0);
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 12, 951U, 0);
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 14, 974U, 0);
  chartInstance->c1_tp_LAUNCH = 0U;
  chartInstance->c1_b_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 15, 985U, (void *)
    &chartInstance->c1_b_is_ACTIVE);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 16, 999U, (int32_T)
    (chartInstance->c1_b_is_ACTIVE == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 17, 1025U, (int32_T)
    (chartInstance->c1_b_is_ACTIVE == 2));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 18, 1002U, (int32_T)
    (chartInstance->c1_b_is_ACTIVE == 3));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 19, 998U, (int32_T)
    (chartInstance->c1_b_is_ACTIVE == 4));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 20, 1001U, (int32_T)
    (chartInstance->c1_b_is_ACTIVE == 5));
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 0);
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 12, 951U, 0);
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 14, 974U, 0);
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 15, 985U, 0);
  chartInstance->c1_b_tp_ACTIVE = 0U;
  chartInstance->c1_b_tp_READY = 0U;
  chartInstance->c1_b_tp_RELEASING = 0U;
  chartInstance->c1_b_tp_RUNNING = 0U;
  chartInstance->c1_b_tp_START = 0U;
  chartInstance->c1_b_tp_START_RELEASE = 0U;
  chartInstance->c1_b_tp_STOPPING = 0U;
  chartInstance->c1_tp_INIT = 0U;
  chartInstance->c1_is_MANUAL_MODES = c1_IN_NO_ACTIVE_CHILD;
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 23, 727U, (void *)
    &chartInstance->c1_is_MANUAL_MODES);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 24, 729U, (int32_T)
    (chartInstance->c1_is_MANUAL_MODES == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 25, 728U, (int32_T)
    (chartInstance->c1_is_MANUAL_MODES == 2));
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 0);
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 23, 727U, 0);
  chartInstance->c1_tp_MANUAL_MODES = 0U;
  chartInstance->c1_tp_ENDURANCE = 0U;
  chartInstance->c1_tp_SKIDPAD = 0U;
  chartInstance->c1_is_active_NEUTRAL_STATE = 0U;
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 26, 31U, (int32_T)
    (chartInstance->c1_is_active_NEUTRAL_STATE == 1));
  chartInstance->c1_is_NEUTRAL_STATE = c1_IN_NO_ACTIVE_CHILD;
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 26, 31U, (void *)
    &chartInstance->c1_is_NEUTRAL_STATE);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 27, 36U, (int32_T)
    (chartInstance->c1_is_NEUTRAL_STATE == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 28, 32U, (int32_T)
    (chartInstance->c1_is_NEUTRAL_STATE == 2));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 29, 34U, (int32_T)
    (chartInstance->c1_is_NEUTRAL_STATE == 3));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 30, 35U, (int32_T)
    (chartInstance->c1_is_NEUTRAL_STATE == 4));
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 26, 31U, 0);
  chartInstance->c1_tp_NEUTRAL_STATE = 0U;
  chartInstance->c1_tp_NEUTRAL = 0U;
  chartInstance->c1_tp_NO_NEUTRAL = 0U;
  chartInstance->c1_tp_SET_NEUTRAL = 0U;
  chartInstance->c1_tp_UNSET_NEUTRAL = 0U;
  chartInstance->c1_is_active_SCAN_ADC = 0U;
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 61, 929U, (int32_T)
    (chartInstance->c1_is_active_SCAN_ADC == 1));
  chartInstance->c1_is_SCAN_ADC = c1_IN_NO_ACTIVE_CHILD;
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 61, 929U, (void *)
    &chartInstance->c1_is_SCAN_ADC);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 62, 932U, (int32_T)
    (chartInstance->c1_is_SCAN_ADC == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 63, 930U, (int32_T)
    (chartInstance->c1_is_SCAN_ADC == 2));
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 61, 929U, 0);
  chartInstance->c1_tp_SCAN_ADC = 0U;
  chartInstance->c1_tp_SCAN = 0U;
  chartInstance->c1_c_tp_WAIT = 0U;
  chartInstance->c1_is_active_START_ENGINE = 0U;
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 57, 479U, (int32_T)
    (chartInstance->c1_is_active_START_ENGINE == 1));
  chartInstance->c1_is_START_ENGINE = c1_IN_NO_ACTIVE_CHILD;
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 57, 479U, (void *)
    &chartInstance->c1_is_START_ENGINE);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 58, 482U, (int32_T)
    (chartInstance->c1_is_START_ENGINE == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 59, 483U, (int32_T)
    (chartInstance->c1_is_START_ENGINE == 2));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 60, 494U, (int32_T)
    (chartInstance->c1_is_START_ENGINE == 3));
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 57, 479U, 0);
  chartInstance->c1_tp_START_ENGINE = 0U;
  chartInstance->c1_c_tp_START = 0U;
  chartInstance->c1_tp_STOP = 0U;
  chartInstance->c1_b_tp_WAIT = 0U;
  chartInstance->c1_is_active_c1_GCU_Model_genCode = 0U;
  chartInstance->c1_lastShift = 0U;
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 8, 715U, (void *)
    &chartInstance->c1_lastShift);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastShift, 18U);
  chartInstance->c1_lastAacCom = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastAacCom, 1U);
  chartInstance->c1_lastShiftCom = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastShiftCom, 4U);
  chartInstance->c1_lastClutchCom = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastClutchCom, 3U);
  chartInstance->c1_lastAutoXCom = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastAutoXCom, 2U);
  chartInstance->c1_buzzerCounter = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_buzzerCounter, 0U);
  chartInstance->c1_aacCounter = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_aacCounter, 5U);
  chartInstance->c1_aac_clutchValue = 0.0;
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_aac_clutchValue, 7U);
  chartInstance->c1_aac_clutchStep = 0.0;
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_aac_clutchStep, 6U);
  chartInstance->c1_aac_dtRelease = 0;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_aac_dtRelease, 8U);
  chartInstance->c1_autoXCounter = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_autoXCounter, 9U);
  chartInstance->c1_autoX_clutchValue = 0.0;
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_autoX_clutchValue, 11U);
  chartInstance->c1_autoX_clutchStep = 0.0;
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_autoX_clutchStep, 10U);
  chartInstance->c1_autoX_dtRelease = 0;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_autoX_dtRelease, 12U);
  chartInstance->c1_ticksCounter = 0;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_ticksCounter, 13U);
  chartInstance->c1_counterWait = 0.0;
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_counterWait, 14U);
  chartInstance->c1_lastCom = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastCom, 15U);
  chartInstance->c1_startCounter = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_startCounter, 16U);
  chartInstance->c1_timerCounter = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_timerCounter, 17U);
  chartInstance->c1_GEAR_COMMAND_NEUTRAL_UP = 50U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_GEAR_COMMAND_NEUTRAL_UP, 35U);
  chartInstance->c1_GEAR_COMMAND_NEUTRAL_DOWN = 100U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_GEAR_COMMAND_NEUTRAL_DOWN, 34U);
  chartInstance->c1_GEAR_COMMAND_UP = 400U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_GEAR_COMMAND_UP, 36U);
  chartInstance->c1_GEAR_COMMAND_DOWN = 200U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_GEAR_COMMAND_DOWN, 33U);
  chartInstance->c1_b_GEAR_COMMAND_NEUTRAL_UP = 50U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_b_GEAR_COMMAND_NEUTRAL_UP, 39U);
  chartInstance->c1_b_GEAR_COMMAND_NEUTRAL_DOWN = 100U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_b_GEAR_COMMAND_NEUTRAL_DOWN,
                        38U);
  chartInstance->c1_b_GEAR_COMMAND_UP = 400U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_b_GEAR_COMMAND_UP, 40U);
  chartInstance->c1_b_GEAR_COMMAND_DOWN = 200U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_b_GEAR_COMMAND_DOWN, 37U);
  chartInstance->c1_AAC_WORK_RATE_ms = 25U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_AAC_WORK_RATE_ms, 41U);
  chartInstance->c1_DEF_RAMP_START = 50;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_DEF_RAMP_START, 44U);
  chartInstance->c1_DEF_RAMP_END = 0;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_DEF_RAMP_END, 43U);
  chartInstance->c1_DEF_RAMP_TIME = 250;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_DEF_RAMP_TIME, 45U);
  chartInstance->c1_DEF_RPM_LIMIT_1_2 = 11000;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_DEF_RPM_LIMIT_1_2, 46U);
  chartInstance->c1_DEF_RPM_LIMIT_2_3 = 11000;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_DEF_RPM_LIMIT_2_3, 47U);
  chartInstance->c1_DEF_RPM_LIMIT_3_4 = 11000;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_DEF_RPM_LIMIT_3_4, 48U);
  chartInstance->c1_DEF_RPM_LIMIT_4_5 = 11000;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_DEF_RPM_LIMIT_4_5, 49U);
  chartInstance->c1_DEF_SPEED_LIMIT_1_2 = 46;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_DEF_SPEED_LIMIT_1_2, 50U);
  chartInstance->c1_DEF_SPEED_LIMIT_2_3 = 61;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_DEF_SPEED_LIMIT_2_3, 51U);
  chartInstance->c1_DEF_SPEED_LIMIT_3_4 = 77;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_DEF_SPEED_LIMIT_3_4, 52U);
  chartInstance->c1_DEF_SPEED_LIMIT_4_5 = 113;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_DEF_SPEED_LIMIT_4_5, 53U);
  chartInstance->c1_ACC_CODE = 1U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_ACC_CODE, 42U);
  chartInstance->c1_AUTOX_WORK_RATE_ms = 25U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_AUTOX_WORK_RATE_ms, 54U);
  chartInstance->c1_data = 0.0;
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_data, 55U);
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    *chartInstance->c1_clutchCurrVal = 0U;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 1, 123U, (void *)
      chartInstance->c1_clutchCurrVal);
    _SFD_DATA_RANGE_CHECK_MIN_MAX((real_T)*chartInstance->c1_clutchCurrVal, 30U,
      0.0, 100.0, 0U, 0, 0);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 2) != 0)) {
    for (c1_i0 = 0; c1_i0 < 2; c1_i0++) {
      (*chartInstance->c1_lastModeCom)[c1_i0] = 0U;
    }

    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
      chartInstance->c1_lastModeCom);
    for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)[c1_i1], 31U);
    }
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 3) != 0)) {
    *chartInstance->c1_stateFb = 0U;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 10, 833U, (void *)
      chartInstance->c1_stateFb);
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_stateFb, 32U);
  }
}

static void initialize_params_c1_GCU_Model_genCode
  (SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_GCU_Model_genCode(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_enable(chartInstance->S, 0, "Clutch_set", 0);
  sf_call_output_fcn_enable(chartInstance->S, 1, "Efi_init", 0);
  sf_call_output_fcn_enable(chartInstance->S, 2, "Efi_setCut", 0);
  sf_call_output_fcn_enable(chartInstance->S, 3, "Efi_unsetCut", 0);
  sf_call_output_fcn_enable(chartInstance->S, 4, "Efi_setRPMLimiter", 0);
  sf_call_output_fcn_enable(chartInstance->S, 5, "Efi_unsetRPMLimiter", 0);
  sf_call_output_fcn_enable(chartInstance->S, 6, "Gearshift_rebound", 0);
  sf_call_output_fcn_enable(chartInstance->S, 7, "Gearshift_up_push", 0);
  sf_call_output_fcn_enable(chartInstance->S, 8, "Gearshift_down_push", 0);
  sf_call_output_fcn_enable(chartInstance->S, 9, "Gearshift_brake", 0);
  sf_call_output_fcn_enable(chartInstance->S, 10, "Gearshift_free", 0);
  sf_call_output_fcn_enable(chartInstance->S, 11, "EngineControl_start", 0);
  sf_call_output_fcn_enable(chartInstance->S, 12, "EngineControl_stop", 0);
  sf_call_output_fcn_enable(chartInstance->S, 13, "eepromTrigger", 0);
  sf_call_output_fcn_enable(chartInstance->S, 14, "BuzzerOn", 0);
  sf_call_output_fcn_enable(chartInstance->S, 15, "BuzzerOff", 0);
  if (chartInstance->c1_is_active_SCAN_ADC == 1U) {
    sf_call_output_fcn_enable(chartInstance->S, 16, "ScanADC", 0);
  }
}

static void disable_c1_GCU_Model_genCode(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_disable(chartInstance->S, 0, "Clutch_set", 0);
  sf_call_output_fcn_disable(chartInstance->S, 1, "Efi_init", 0);
  sf_call_output_fcn_disable(chartInstance->S, 2, "Efi_setCut", 0);
  sf_call_output_fcn_disable(chartInstance->S, 3, "Efi_unsetCut", 0);
  sf_call_output_fcn_disable(chartInstance->S, 4, "Efi_setRPMLimiter", 0);
  sf_call_output_fcn_disable(chartInstance->S, 5, "Efi_unsetRPMLimiter", 0);
  sf_call_output_fcn_disable(chartInstance->S, 6, "Gearshift_rebound", 0);
  sf_call_output_fcn_disable(chartInstance->S, 7, "Gearshift_up_push", 0);
  sf_call_output_fcn_disable(chartInstance->S, 8, "Gearshift_down_push", 0);
  sf_call_output_fcn_disable(chartInstance->S, 9, "Gearshift_brake", 0);
  sf_call_output_fcn_disable(chartInstance->S, 10, "Gearshift_free", 0);
  sf_call_output_fcn_disable(chartInstance->S, 11, "EngineControl_start", 0);
  sf_call_output_fcn_disable(chartInstance->S, 12, "EngineControl_stop", 0);
  sf_call_output_fcn_disable(chartInstance->S, 13, "eepromTrigger", 0);
  sf_call_output_fcn_disable(chartInstance->S, 14, "BuzzerOn", 0);
  sf_call_output_fcn_disable(chartInstance->S, 15, "BuzzerOff", 0);
  if (chartInstance->c1_is_active_SCAN_ADC == 1U) {
    sf_call_output_fcn_disable(chartInstance->S, 16, "ScanADC", 0);
  }
}

static void c1_update_debugger_state_c1_GCU_Model_genCode
  (SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c1_is_active_c1_GCU_Model_genCode == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_MODES == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_MODES == c1_IN_MANUAL_MODES) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 57U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 57U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_MANUAL_MODES == c1_IN_ENDURANCE) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 58U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 58U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_MANUAL_MODES == c1_IN_SKIDPAD) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 59U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_MODES == c1_IN_INIT) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 56U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 56U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_MODES == c1_IN_ACCELERATION) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_ACCELERATION == c1_IN_ACC) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 33U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_ACC == c1_IN_ACTIVE) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_ACTIVE == c1_IN_START) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 38U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 38U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_ACTIVE == c1_IN_READY) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_ACTIVE == c1_IN_START_RELEASE) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_ACTIVE == c1_IN_RUNNING) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 37U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 37U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_ACTIVE == c1_IN_RELEASING) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_ACC == c1_IN_STOPPING) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 41U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 41U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_ACCELERATION == c1_IN_DEFAULT) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 43U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 43U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_MODES == c1_IN_AUTOCROSS) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 44U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 44U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_AUTOCROSS == c1_IN_LAUNCH) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 46U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 46U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_LAUNCH == c1_IN_ACTIVE) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 47U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 47U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_b_is_ACTIVE == c1_IN_START) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 51U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 51U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_b_is_ACTIVE == c1_IN_READY) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 48U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 48U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_b_is_ACTIVE == c1_IN_START_RELEASE) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 52U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 52U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_b_is_ACTIVE == c1_IN_RUNNING) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 50U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 50U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_b_is_ACTIVE == c1_IN_RELEASING) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 49U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 49U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_LAUNCH == c1_IN_STOPPING) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 54U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 54U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_AUTOCROSS == c1_b_IN_DEFAULT) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 45U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 45U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_NEUTRAL_STATE == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 62U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 62U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_NEUTRAL_STATE == c1_IN_NEUTRAL) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 63U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 63U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_NEUTRAL_STATE == c1_IN_UNSET_NEUTRAL) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 66U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 66U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_NEUTRAL_STATE == c1_IN_SET_NEUTRAL) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 65U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 65U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_NEUTRAL_STATE == c1_IN_NO_NEUTRAL) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 64U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 64U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_GEARSHIFT == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_GEARSHIFT == c1_IN_UPSHIFTING) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_UPSHIFTING == c1_IN_UP_REBOUND) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_UP_REBOUND == c1_IN_Default) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_UP_REBOUND == c1_IN_SettingNeutral) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_UPSHIFTING == c1_IN_UP_PUSH) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_UP_PUSH == c1_b_IN_Default) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_UP_PUSH == c1_IN_CutOff) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_UPSHIFTING == c1_IN_UP_START) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_UP_START == c1_IN_Default) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_UP_START == c1_IN_SettingNeutral) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_UPSHIFTING == c1_IN_UP_BRAKE) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_GEARSHIFT == c1_IN_UP_END) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_GEARSHIFT == c1_IN_IDLE) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_GEARSHIFT == c1_b_IN_INIT) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_GEARSHIFT == c1_IN_DOWNSHIFTING) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_DOWNSHIFTING == c1_IN_DOWN_START) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_DOWN_START == c1_b_IN_SettingNeutral) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_DOWN_START == c1_IN_ChangeClutch) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_DOWN_START == c1_b_IN_Default) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_DOWNSHIFTING == c1_IN_DOWN_BRAKE) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_DOWN_BRAKE == c1_b_IN_Default) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_DOWN_BRAKE == c1_IN_ChangeClutch) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_DOWNSHIFTING == c1_IN_DOWN_PUSH) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_DOWNSHIFTING == c1_IN_DOWN_REBOUND) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_GEARSHIFT == c1_IN_DOWN_END) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_EEPROM_TRIGGER == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_EEPROM_TRIGGER == c1_IN_WAIT) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_EEPROM_TRIGGER == c1_IN_SEND) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_START_ENGINE == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 71U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 71U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_START_ENGINE == c1_b_IN_WAIT) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 74U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 74U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_START_ENGINE == c1_b_IN_START) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 72U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 72U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_START_ENGINE == c1_IN_STOP) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 73U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 73U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_SCAN_ADC == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 67U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 67U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_SCAN_ADC == c1_IN_WAIT) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 70U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 70U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_SCAN_ADC == c1_IN_SCAN) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 68U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 68U, chartInstance->c1_sfEvent);
  }

  _SFD_SET_ANIMATION(c1_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_GCU_Model_genCode
  (SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  uint8_T c1_hoistedGlobal;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  uint16_T c1_b_hoistedGlobal;
  const mxArray *c1_d_y = NULL;
  uint16_T c1_c_hoistedGlobal;
  const mxArray *c1_e_y = NULL;
  real_T c1_d_hoistedGlobal;
  const mxArray *c1_f_y = NULL;
  real_T c1_e_hoistedGlobal;
  const mxArray *c1_g_y = NULL;
  int32_T c1_f_hoistedGlobal;
  const mxArray *c1_h_y = NULL;
  uint16_T c1_g_hoistedGlobal;
  const mxArray *c1_i_y = NULL;
  real_T c1_h_hoistedGlobal;
  const mxArray *c1_j_y = NULL;
  real_T c1_i_hoistedGlobal;
  const mxArray *c1_k_y = NULL;
  int32_T c1_j_hoistedGlobal;
  const mxArray *c1_l_y = NULL;
  uint16_T c1_k_hoistedGlobal;
  const mxArray *c1_m_y = NULL;
  real_T c1_l_hoistedGlobal;
  const mxArray *c1_n_y = NULL;
  uint16_T c1_m_hoistedGlobal;
  const mxArray *c1_o_y = NULL;
  uint16_T c1_n_hoistedGlobal;
  const mxArray *c1_p_y = NULL;
  uint8_T c1_o_hoistedGlobal;
  const mxArray *c1_q_y = NULL;
  uint8_T c1_p_hoistedGlobal;
  const mxArray *c1_r_y = NULL;
  uint8_T c1_q_hoistedGlobal;
  const mxArray *c1_s_y = NULL;
  uint16_T c1_r_hoistedGlobal;
  const mxArray *c1_t_y = NULL;
  uint8_T c1_s_hoistedGlobal;
  const mxArray *c1_u_y = NULL;
  int32_T c1_t_hoistedGlobal;
  const mxArray *c1_v_y = NULL;
  uint16_T c1_u_hoistedGlobal;
  const mxArray *c1_w_y = NULL;
  uint8_T c1_v_hoistedGlobal;
  const mxArray *c1_x_y = NULL;
  uint8_T c1_w_hoistedGlobal;
  const mxArray *c1_y_y = NULL;
  uint8_T c1_x_hoistedGlobal;
  const mxArray *c1_ab_y = NULL;
  uint8_T c1_y_hoistedGlobal;
  const mxArray *c1_bb_y = NULL;
  uint8_T c1_ab_hoistedGlobal;
  const mxArray *c1_cb_y = NULL;
  uint8_T c1_bb_hoistedGlobal;
  const mxArray *c1_db_y = NULL;
  uint8_T c1_cb_hoistedGlobal;
  const mxArray *c1_eb_y = NULL;
  uint8_T c1_db_hoistedGlobal;
  const mxArray *c1_fb_y = NULL;
  uint8_T c1_eb_hoistedGlobal;
  const mxArray *c1_gb_y = NULL;
  uint8_T c1_fb_hoistedGlobal;
  const mxArray *c1_hb_y = NULL;
  uint8_T c1_gb_hoistedGlobal;
  const mxArray *c1_ib_y = NULL;
  uint8_T c1_hb_hoistedGlobal;
  const mxArray *c1_jb_y = NULL;
  uint8_T c1_ib_hoistedGlobal;
  const mxArray *c1_kb_y = NULL;
  uint8_T c1_jb_hoistedGlobal;
  const mxArray *c1_lb_y = NULL;
  uint8_T c1_kb_hoistedGlobal;
  const mxArray *c1_mb_y = NULL;
  uint8_T c1_lb_hoistedGlobal;
  const mxArray *c1_nb_y = NULL;
  uint8_T c1_mb_hoistedGlobal;
  const mxArray *c1_ob_y = NULL;
  uint8_T c1_nb_hoistedGlobal;
  const mxArray *c1_pb_y = NULL;
  uint8_T c1_ob_hoistedGlobal;
  const mxArray *c1_qb_y = NULL;
  uint8_T c1_pb_hoistedGlobal;
  const mxArray *c1_rb_y = NULL;
  uint8_T c1_qb_hoistedGlobal;
  const mxArray *c1_sb_y = NULL;
  uint8_T c1_rb_hoistedGlobal;
  const mxArray *c1_tb_y = NULL;
  uint8_T c1_sb_hoistedGlobal;
  const mxArray *c1_ub_y = NULL;
  uint8_T c1_tb_hoistedGlobal;
  const mxArray *c1_vb_y = NULL;
  uint8_T c1_ub_hoistedGlobal;
  const mxArray *c1_wb_y = NULL;
  uint8_T c1_vb_hoistedGlobal;
  const mxArray *c1_xb_y = NULL;
  uint8_T c1_wb_hoistedGlobal;
  const mxArray *c1_yb_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(49, 1), false);
  c1_hoistedGlobal = *chartInstance->c1_clutchCurrVal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", *chartInstance->c1_lastModeCom, 5,
    0U, 1U, 0U, 1, 2), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_b_hoistedGlobal = *chartInstance->c1_stateFb;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_b_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_c_hoistedGlobal = chartInstance->c1_aacCounter;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_c_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_d_hoistedGlobal = chartInstance->c1_aac_clutchStep;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_d_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_e_hoistedGlobal = chartInstance->c1_aac_clutchValue;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_e_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 5, c1_g_y);
  c1_f_hoistedGlobal = chartInstance->c1_aac_dtRelease;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_f_hoistedGlobal, 6, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 6, c1_h_y);
  c1_g_hoistedGlobal = chartInstance->c1_autoXCounter;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_g_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 7, c1_i_y);
  c1_h_hoistedGlobal = chartInstance->c1_autoX_clutchStep;
  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_h_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 8, c1_j_y);
  c1_i_hoistedGlobal = chartInstance->c1_autoX_clutchValue;
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_i_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 9, c1_k_y);
  c1_j_hoistedGlobal = chartInstance->c1_autoX_dtRelease;
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_j_hoistedGlobal, 6, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 10, c1_l_y);
  c1_k_hoistedGlobal = chartInstance->c1_buzzerCounter;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_k_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 11, c1_m_y);
  c1_l_hoistedGlobal = chartInstance->c1_counterWait;
  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_l_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 12, c1_n_y);
  c1_m_hoistedGlobal = chartInstance->c1_lastAacCom;
  c1_o_y = NULL;
  sf_mex_assign(&c1_o_y, sf_mex_create("y", &c1_m_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 13, c1_o_y);
  c1_n_hoistedGlobal = chartInstance->c1_lastAutoXCom;
  c1_p_y = NULL;
  sf_mex_assign(&c1_p_y, sf_mex_create("y", &c1_n_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 14, c1_p_y);
  c1_o_hoistedGlobal = chartInstance->c1_lastClutchCom;
  c1_q_y = NULL;
  sf_mex_assign(&c1_q_y, sf_mex_create("y", &c1_o_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 15, c1_q_y);
  c1_p_hoistedGlobal = chartInstance->c1_lastCom;
  c1_r_y = NULL;
  sf_mex_assign(&c1_r_y, sf_mex_create("y", &c1_p_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 16, c1_r_y);
  c1_q_hoistedGlobal = chartInstance->c1_lastShift;
  c1_s_y = NULL;
  sf_mex_assign(&c1_s_y, sf_mex_create("y", &c1_q_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 17, c1_s_y);
  c1_r_hoistedGlobal = chartInstance->c1_lastShiftCom;
  c1_t_y = NULL;
  sf_mex_assign(&c1_t_y, sf_mex_create("y", &c1_r_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 18, c1_t_y);
  c1_s_hoistedGlobal = chartInstance->c1_startCounter;
  c1_u_y = NULL;
  sf_mex_assign(&c1_u_y, sf_mex_create("y", &c1_s_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 19, c1_u_y);
  c1_t_hoistedGlobal = chartInstance->c1_ticksCounter;
  c1_v_y = NULL;
  sf_mex_assign(&c1_v_y, sf_mex_create("y", &c1_t_hoistedGlobal, 6, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 20, c1_v_y);
  c1_u_hoistedGlobal = chartInstance->c1_timerCounter;
  c1_w_y = NULL;
  sf_mex_assign(&c1_w_y, sf_mex_create("y", &c1_u_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 21, c1_w_y);
  c1_v_hoistedGlobal = chartInstance->c1_is_active_c1_GCU_Model_genCode;
  c1_x_y = NULL;
  sf_mex_assign(&c1_x_y, sf_mex_create("y", &c1_v_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 22, c1_x_y);
  c1_w_hoistedGlobal = chartInstance->c1_is_active_GEARSHIFT;
  c1_y_y = NULL;
  sf_mex_assign(&c1_y_y, sf_mex_create("y", &c1_w_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 23, c1_y_y);
  c1_x_hoistedGlobal = chartInstance->c1_is_active_NEUTRAL_STATE;
  c1_ab_y = NULL;
  sf_mex_assign(&c1_ab_y, sf_mex_create("y", &c1_x_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 24, c1_ab_y);
  c1_y_hoistedGlobal = chartInstance->c1_is_active_MODES;
  c1_bb_y = NULL;
  sf_mex_assign(&c1_bb_y, sf_mex_create("y", &c1_y_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 25, c1_bb_y);
  c1_ab_hoistedGlobal = chartInstance->c1_is_active_START_ENGINE;
  c1_cb_y = NULL;
  sf_mex_assign(&c1_cb_y, sf_mex_create("y", &c1_ab_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 26, c1_cb_y);
  c1_bb_hoistedGlobal = chartInstance->c1_is_active_SCAN_ADC;
  c1_db_y = NULL;
  sf_mex_assign(&c1_db_y, sf_mex_create("y", &c1_bb_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 27, c1_db_y);
  c1_cb_hoistedGlobal = chartInstance->c1_is_active_EEPROM_TRIGGER;
  c1_eb_y = NULL;
  sf_mex_assign(&c1_eb_y, sf_mex_create("y", &c1_cb_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 28, c1_eb_y);
  c1_db_hoistedGlobal = chartInstance->c1_is_GEARSHIFT;
  c1_fb_y = NULL;
  sf_mex_assign(&c1_fb_y, sf_mex_create("y", &c1_db_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 29, c1_fb_y);
  c1_eb_hoistedGlobal = chartInstance->c1_is_UP_START;
  c1_gb_y = NULL;
  sf_mex_assign(&c1_gb_y, sf_mex_create("y", &c1_eb_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 30, c1_gb_y);
  c1_fb_hoistedGlobal = chartInstance->c1_is_UP_PUSH;
  c1_hb_y = NULL;
  sf_mex_assign(&c1_hb_y, sf_mex_create("y", &c1_fb_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 31, c1_hb_y);
  c1_gb_hoistedGlobal = chartInstance->c1_is_UP_REBOUND;
  c1_ib_y = NULL;
  sf_mex_assign(&c1_ib_y, sf_mex_create("y", &c1_gb_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 32, c1_ib_y);
  c1_hb_hoistedGlobal = chartInstance->c1_is_DOWN_START;
  c1_jb_y = NULL;
  sf_mex_assign(&c1_jb_y, sf_mex_create("y", &c1_hb_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 33, c1_jb_y);
  c1_ib_hoistedGlobal = chartInstance->c1_is_DOWN_BRAKE;
  c1_kb_y = NULL;
  sf_mex_assign(&c1_kb_y, sf_mex_create("y", &c1_ib_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 34, c1_kb_y);
  c1_jb_hoistedGlobal = chartInstance->c1_is_NEUTRAL_STATE;
  c1_lb_y = NULL;
  sf_mex_assign(&c1_lb_y, sf_mex_create("y", &c1_jb_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 35, c1_lb_y);
  c1_kb_hoistedGlobal = chartInstance->c1_is_MODES;
  c1_mb_y = NULL;
  sf_mex_assign(&c1_mb_y, sf_mex_create("y", &c1_kb_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 36, c1_mb_y);
  c1_lb_hoistedGlobal = chartInstance->c1_is_ACC;
  c1_nb_y = NULL;
  sf_mex_assign(&c1_nb_y, sf_mex_create("y", &c1_lb_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 37, c1_nb_y);
  c1_mb_hoistedGlobal = chartInstance->c1_is_START_ENGINE;
  c1_ob_y = NULL;
  sf_mex_assign(&c1_ob_y, sf_mex_create("y", &c1_mb_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 38, c1_ob_y);
  c1_nb_hoistedGlobal = chartInstance->c1_is_ACTIVE;
  c1_pb_y = NULL;
  sf_mex_assign(&c1_pb_y, sf_mex_create("y", &c1_nb_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 39, c1_pb_y);
  c1_ob_hoistedGlobal = chartInstance->c1_is_UPSHIFTING;
  c1_qb_y = NULL;
  sf_mex_assign(&c1_qb_y, sf_mex_create("y", &c1_ob_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 40, c1_qb_y);
  c1_pb_hoistedGlobal = chartInstance->c1_is_DOWNSHIFTING;
  c1_rb_y = NULL;
  sf_mex_assign(&c1_rb_y, sf_mex_create("y", &c1_pb_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 41, c1_rb_y);
  c1_qb_hoistedGlobal = chartInstance->c1_is_MANUAL_MODES;
  c1_sb_y = NULL;
  sf_mex_assign(&c1_sb_y, sf_mex_create("y", &c1_qb_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 42, c1_sb_y);
  c1_rb_hoistedGlobal = chartInstance->c1_is_ACCELERATION;
  c1_tb_y = NULL;
  sf_mex_assign(&c1_tb_y, sf_mex_create("y", &c1_rb_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 43, c1_tb_y);
  c1_sb_hoistedGlobal = chartInstance->c1_is_SCAN_ADC;
  c1_ub_y = NULL;
  sf_mex_assign(&c1_ub_y, sf_mex_create("y", &c1_sb_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 44, c1_ub_y);
  c1_tb_hoistedGlobal = chartInstance->c1_is_EEPROM_TRIGGER;
  c1_vb_y = NULL;
  sf_mex_assign(&c1_vb_y, sf_mex_create("y", &c1_tb_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 45, c1_vb_y);
  c1_ub_hoistedGlobal = chartInstance->c1_is_AUTOCROSS;
  c1_wb_y = NULL;
  sf_mex_assign(&c1_wb_y, sf_mex_create("y", &c1_ub_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 46, c1_wb_y);
  c1_vb_hoistedGlobal = chartInstance->c1_is_LAUNCH;
  c1_xb_y = NULL;
  sf_mex_assign(&c1_xb_y, sf_mex_create("y", &c1_vb_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 47, c1_xb_y);
  c1_wb_hoistedGlobal = chartInstance->c1_b_is_ACTIVE;
  c1_yb_y = NULL;
  sf_mex_assign(&c1_yb_y, sf_mex_create("y", &c1_wb_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 48, c1_yb_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_GCU_Model_genCode
  (SFc1_GCU_Model_genCodeInstanceStruct *chartInstance, const mxArray *c1_st)
{
  c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_st));
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_GCU_Model_genCode(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_GCU_Model_genCode
  (SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    if (chartInstance->c1_is_active_MODES == 1U) {
      chartInstance->c1_tp_MODES = 1U;
    } else {
      chartInstance->c1_tp_MODES = 0U;
    }

    if (chartInstance->c1_is_MODES == c1_IN_ACCELERATION) {
      chartInstance->c1_tp_ACCELERATION = 1U;
    } else {
      chartInstance->c1_tp_ACCELERATION = 0U;
    }

    if (chartInstance->c1_is_ACCELERATION == c1_IN_ACC) {
      chartInstance->c1_tp_ACC = 1U;
    } else {
      chartInstance->c1_tp_ACC = 0U;
    }

    if (chartInstance->c1_is_ACC == c1_IN_ACTIVE) {
      chartInstance->c1_tp_ACTIVE = 1U;
    } else {
      chartInstance->c1_tp_ACTIVE = 0U;
    }

    if (chartInstance->c1_is_ACTIVE == c1_IN_READY) {
      chartInstance->c1_tp_READY = 1U;
    } else {
      chartInstance->c1_tp_READY = 0U;
    }

    if (chartInstance->c1_is_ACTIVE == c1_IN_RELEASING) {
      chartInstance->c1_tp_RELEASING = 1U;
    } else {
      chartInstance->c1_tp_RELEASING = 0U;
    }

    if (chartInstance->c1_is_ACTIVE == c1_IN_RUNNING) {
      chartInstance->c1_tp_RUNNING = 1U;
    } else {
      chartInstance->c1_tp_RUNNING = 0U;
    }

    if (chartInstance->c1_is_ACTIVE == c1_IN_START) {
      chartInstance->c1_tp_START = 1U;
    } else {
      chartInstance->c1_tp_START = 0U;
    }

    if (chartInstance->c1_is_ACTIVE == c1_IN_START_RELEASE) {
      chartInstance->c1_tp_START_RELEASE = 1U;
    } else {
      chartInstance->c1_tp_START_RELEASE = 0U;
    }

    if (chartInstance->c1_is_ACC == c1_IN_STOPPING) {
      chartInstance->c1_tp_STOPPING = 1U;
    } else {
      chartInstance->c1_tp_STOPPING = 0U;
    }

    if (chartInstance->c1_is_ACCELERATION == c1_IN_DEFAULT) {
      chartInstance->c1_tp_DEFAULT = 1U;
    } else {
      chartInstance->c1_tp_DEFAULT = 0U;
    }

    if (chartInstance->c1_is_MODES == c1_IN_AUTOCROSS) {
      chartInstance->c1_tp_AUTOCROSS = 1U;
    } else {
      chartInstance->c1_tp_AUTOCROSS = 0U;
    }

    if (chartInstance->c1_is_AUTOCROSS == c1_b_IN_DEFAULT) {
      chartInstance->c1_b_tp_DEFAULT = 1U;
    } else {
      chartInstance->c1_b_tp_DEFAULT = 0U;
    }

    if (chartInstance->c1_is_AUTOCROSS == c1_IN_LAUNCH) {
      chartInstance->c1_tp_LAUNCH = 1U;
    } else {
      chartInstance->c1_tp_LAUNCH = 0U;
    }

    if (chartInstance->c1_is_LAUNCH == c1_IN_ACTIVE) {
      chartInstance->c1_b_tp_ACTIVE = 1U;
    } else {
      chartInstance->c1_b_tp_ACTIVE = 0U;
    }

    if (chartInstance->c1_b_is_ACTIVE == c1_IN_READY) {
      chartInstance->c1_b_tp_READY = 1U;
    } else {
      chartInstance->c1_b_tp_READY = 0U;
    }

    if (chartInstance->c1_b_is_ACTIVE == c1_IN_RELEASING) {
      chartInstance->c1_b_tp_RELEASING = 1U;
    } else {
      chartInstance->c1_b_tp_RELEASING = 0U;
    }

    if (chartInstance->c1_b_is_ACTIVE == c1_IN_RUNNING) {
      chartInstance->c1_b_tp_RUNNING = 1U;
    } else {
      chartInstance->c1_b_tp_RUNNING = 0U;
    }

    if (chartInstance->c1_b_is_ACTIVE == c1_IN_START) {
      chartInstance->c1_b_tp_START = 1U;
    } else {
      chartInstance->c1_b_tp_START = 0U;
    }

    if (chartInstance->c1_b_is_ACTIVE == c1_IN_START_RELEASE) {
      chartInstance->c1_b_tp_START_RELEASE = 1U;
    } else {
      chartInstance->c1_b_tp_START_RELEASE = 0U;
    }

    if (chartInstance->c1_is_LAUNCH == c1_IN_STOPPING) {
      chartInstance->c1_b_tp_STOPPING = 1U;
    } else {
      chartInstance->c1_b_tp_STOPPING = 0U;
    }

    if (chartInstance->c1_is_MODES == c1_IN_INIT) {
      chartInstance->c1_tp_INIT = 1U;
    } else {
      chartInstance->c1_tp_INIT = 0U;
    }

    if (chartInstance->c1_is_MODES == c1_IN_MANUAL_MODES) {
      chartInstance->c1_tp_MANUAL_MODES = 1U;
    } else {
      chartInstance->c1_tp_MANUAL_MODES = 0U;
    }

    if (chartInstance->c1_is_MANUAL_MODES == c1_IN_ENDURANCE) {
      chartInstance->c1_tp_ENDURANCE = 1U;
    } else {
      chartInstance->c1_tp_ENDURANCE = 0U;
    }

    if (chartInstance->c1_is_MANUAL_MODES == c1_IN_SKIDPAD) {
      chartInstance->c1_tp_SKIDPAD = 1U;
    } else {
      chartInstance->c1_tp_SKIDPAD = 0U;
    }

    if (chartInstance->c1_is_active_NEUTRAL_STATE == 1U) {
      chartInstance->c1_tp_NEUTRAL_STATE = 1U;
    } else {
      chartInstance->c1_tp_NEUTRAL_STATE = 0U;
    }

    if (chartInstance->c1_is_NEUTRAL_STATE == c1_IN_NEUTRAL) {
      chartInstance->c1_tp_NEUTRAL = 1U;
    } else {
      chartInstance->c1_tp_NEUTRAL = 0U;
    }

    if (chartInstance->c1_is_NEUTRAL_STATE == c1_IN_NO_NEUTRAL) {
      chartInstance->c1_tp_NO_NEUTRAL = 1U;
    } else {
      chartInstance->c1_tp_NO_NEUTRAL = 0U;
    }

    if (chartInstance->c1_is_NEUTRAL_STATE == c1_IN_SET_NEUTRAL) {
      chartInstance->c1_tp_SET_NEUTRAL = 1U;
    } else {
      chartInstance->c1_tp_SET_NEUTRAL = 0U;
    }

    if (chartInstance->c1_is_NEUTRAL_STATE == c1_IN_UNSET_NEUTRAL) {
      chartInstance->c1_tp_UNSET_NEUTRAL = 1U;
    } else {
      chartInstance->c1_tp_UNSET_NEUTRAL = 0U;
    }

    if (chartInstance->c1_is_active_GEARSHIFT == 1U) {
      chartInstance->c1_tp_GEARSHIFT = 1U;
    } else {
      chartInstance->c1_tp_GEARSHIFT = 0U;
    }

    if (chartInstance->c1_is_GEARSHIFT == c1_IN_DOWNSHIFTING) {
      chartInstance->c1_tp_DOWNSHIFTING = 1U;
    } else {
      chartInstance->c1_tp_DOWNSHIFTING = 0U;
    }

    if (chartInstance->c1_is_DOWNSHIFTING == c1_IN_DOWN_BRAKE) {
      chartInstance->c1_tp_DOWN_BRAKE = 1U;
    } else {
      chartInstance->c1_tp_DOWN_BRAKE = 0U;
    }

    if (chartInstance->c1_is_DOWN_BRAKE == c1_IN_ChangeClutch) {
      chartInstance->c1_b_tp_ChangeClutch = 1U;
    } else {
      chartInstance->c1_b_tp_ChangeClutch = 0U;
    }

    if (chartInstance->c1_is_DOWN_BRAKE == c1_b_IN_Default) {
      chartInstance->c1_e_tp_Default = 1U;
    } else {
      chartInstance->c1_e_tp_Default = 0U;
    }

    if (chartInstance->c1_is_DOWNSHIFTING == c1_IN_DOWN_PUSH) {
      chartInstance->c1_tp_DOWN_PUSH = 1U;
    } else {
      chartInstance->c1_tp_DOWN_PUSH = 0U;
    }

    if (chartInstance->c1_is_DOWNSHIFTING == c1_IN_DOWN_REBOUND) {
      chartInstance->c1_tp_DOWN_REBOUND = 1U;
    } else {
      chartInstance->c1_tp_DOWN_REBOUND = 0U;
    }

    if (chartInstance->c1_is_DOWNSHIFTING == c1_IN_DOWN_START) {
      chartInstance->c1_tp_DOWN_START = 1U;
    } else {
      chartInstance->c1_tp_DOWN_START = 0U;
    }

    if (chartInstance->c1_is_DOWN_START == c1_IN_ChangeClutch) {
      chartInstance->c1_tp_ChangeClutch = 1U;
    } else {
      chartInstance->c1_tp_ChangeClutch = 0U;
    }

    if (chartInstance->c1_is_DOWN_START == c1_b_IN_Default) {
      chartInstance->c1_d_tp_Default = 1U;
    } else {
      chartInstance->c1_d_tp_Default = 0U;
    }

    if (chartInstance->c1_is_DOWN_START == c1_b_IN_SettingNeutral) {
      chartInstance->c1_c_tp_SettingNeutral = 1U;
    } else {
      chartInstance->c1_c_tp_SettingNeutral = 0U;
    }

    if (chartInstance->c1_is_GEARSHIFT == c1_IN_DOWN_END) {
      chartInstance->c1_tp_DOWN_END = 1U;
    } else {
      chartInstance->c1_tp_DOWN_END = 0U;
    }

    if (chartInstance->c1_is_GEARSHIFT == c1_IN_IDLE) {
      chartInstance->c1_tp_IDLE = 1U;
    } else {
      chartInstance->c1_tp_IDLE = 0U;
    }

    if (chartInstance->c1_is_GEARSHIFT == c1_b_IN_INIT) {
      chartInstance->c1_b_tp_INIT = 1U;
    } else {
      chartInstance->c1_b_tp_INIT = 0U;
    }

    if (chartInstance->c1_is_GEARSHIFT == c1_IN_UPSHIFTING) {
      chartInstance->c1_tp_UPSHIFTING = 1U;
    } else {
      chartInstance->c1_tp_UPSHIFTING = 0U;
    }

    if (chartInstance->c1_is_UPSHIFTING == c1_IN_UP_BRAKE) {
      chartInstance->c1_tp_UP_BRAKE = 1U;
    } else {
      chartInstance->c1_tp_UP_BRAKE = 0U;
    }

    if (chartInstance->c1_is_UPSHIFTING == c1_IN_UP_PUSH) {
      chartInstance->c1_tp_UP_PUSH = 1U;
    } else {
      chartInstance->c1_tp_UP_PUSH = 0U;
    }

    if (chartInstance->c1_is_UP_PUSH == c1_IN_CutOff) {
      chartInstance->c1_tp_CutOff = 1U;
    } else {
      chartInstance->c1_tp_CutOff = 0U;
    }

    if (chartInstance->c1_is_UP_PUSH == c1_b_IN_Default) {
      chartInstance->c1_b_tp_Default = 1U;
    } else {
      chartInstance->c1_b_tp_Default = 0U;
    }

    if (chartInstance->c1_is_UPSHIFTING == c1_IN_UP_REBOUND) {
      chartInstance->c1_tp_UP_REBOUND = 1U;
    } else {
      chartInstance->c1_tp_UP_REBOUND = 0U;
    }

    if (chartInstance->c1_is_UP_REBOUND == c1_IN_Default) {
      chartInstance->c1_tp_Default = 1U;
    } else {
      chartInstance->c1_tp_Default = 0U;
    }

    if (chartInstance->c1_is_UP_REBOUND == c1_IN_SettingNeutral) {
      chartInstance->c1_tp_SettingNeutral = 1U;
    } else {
      chartInstance->c1_tp_SettingNeutral = 0U;
    }

    if (chartInstance->c1_is_UPSHIFTING == c1_IN_UP_START) {
      chartInstance->c1_tp_UP_START = 1U;
    } else {
      chartInstance->c1_tp_UP_START = 0U;
    }

    if (chartInstance->c1_is_UP_START == c1_IN_Default) {
      chartInstance->c1_c_tp_Default = 1U;
    } else {
      chartInstance->c1_c_tp_Default = 0U;
    }

    if (chartInstance->c1_is_UP_START == c1_IN_SettingNeutral) {
      chartInstance->c1_b_tp_SettingNeutral = 1U;
    } else {
      chartInstance->c1_b_tp_SettingNeutral = 0U;
    }

    if (chartInstance->c1_is_GEARSHIFT == c1_IN_UP_END) {
      chartInstance->c1_tp_UP_END = 1U;
    } else {
      chartInstance->c1_tp_UP_END = 0U;
    }

    if (chartInstance->c1_is_active_START_ENGINE == 1U) {
      chartInstance->c1_tp_START_ENGINE = 1U;
    } else {
      chartInstance->c1_tp_START_ENGINE = 0U;
    }

    if (chartInstance->c1_is_START_ENGINE == c1_b_IN_START) {
      chartInstance->c1_c_tp_START = 1U;
    } else {
      chartInstance->c1_c_tp_START = 0U;
    }

    if (chartInstance->c1_is_START_ENGINE == c1_IN_STOP) {
      chartInstance->c1_tp_STOP = 1U;
    } else {
      chartInstance->c1_tp_STOP = 0U;
    }

    if (chartInstance->c1_is_START_ENGINE == c1_b_IN_WAIT) {
      chartInstance->c1_b_tp_WAIT = 1U;
    } else {
      chartInstance->c1_b_tp_WAIT = 0U;
    }

    if (chartInstance->c1_is_active_SCAN_ADC == 1U) {
      chartInstance->c1_tp_SCAN_ADC = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 62) == 0.0) {
        sf_call_output_fcn_enable(chartInstance->S, 16, "ScanADC", 0);
      }
    } else {
      chartInstance->c1_tp_SCAN_ADC = 0U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 62) > 0.0) {
        sf_call_output_fcn_disable(chartInstance->S, 16, "ScanADC", 0);
      }
    }

    if (chartInstance->c1_is_SCAN_ADC == c1_IN_SCAN) {
      chartInstance->c1_tp_SCAN = 1U;
    } else {
      chartInstance->c1_tp_SCAN = 0U;
    }

    if (chartInstance->c1_is_SCAN_ADC == c1_IN_WAIT) {
      chartInstance->c1_c_tp_WAIT = 1U;
    } else {
      chartInstance->c1_c_tp_WAIT = 0U;
    }

    if (chartInstance->c1_is_active_EEPROM_TRIGGER == 1U) {
      chartInstance->c1_tp_EEPROM_TRIGGER = 1U;
    } else {
      chartInstance->c1_tp_EEPROM_TRIGGER = 0U;
    }

    if (chartInstance->c1_is_EEPROM_TRIGGER == c1_IN_SEND) {
      chartInstance->c1_tp_SEND = 1U;
    } else {
      chartInstance->c1_tp_SEND = 0U;
    }

    if (chartInstance->c1_is_EEPROM_TRIGGER == c1_IN_WAIT) {
      chartInstance->c1_tp_WAIT = 1U;
    } else {
      chartInstance->c1_tp_WAIT = 0U;
    }

    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_GCU_Model_genCode(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  c1_sdiTerminate(chartInstance);
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_gateway_c1_GCU_Model_genCode(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i10;
  c1_set_sim_state_side_effects_c1_GCU_Model_genCode(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i2 = 0; c1_i2 < 16; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_autoX_parameters)[c1_i2],
                          29U);
  }

  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_autoXCom)[c1_i3], 28U);
  }

  for (c1_i4 = 0; c1_i4 < 24; c1_i4++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_timings)[c1_i4], 27U);
  }

  for (c1_i5 = 0; c1_i5 < 16; c1_i5++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_acc_parameters)[c1_i5],
                          26U);
  }

  for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_modeCom)[c1_i6], 25U);
  }

  for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_clutchCom)[c1_i7], 24U);
  }

  for (c1_i8 = 0; c1_i8 < 3; c1_i8++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_acc_externValues)[c1_i8],
                          23U);
  }

  for (c1_i9 = 0; c1_i9 < 2; c1_i9++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_aacCom)[c1_i9], 22U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_startEngCom, 21U);
  for (c1_i10 = 0; c1_i10 < 2; c1_i10++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_shiftCom)[c1_i10], 20U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_currentGear, 19U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_c1_GCU_Model_genCode(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
}

static void mdl_start_c1_GCU_Model_genCode(SFc1_GCU_Model_genCodeInstanceStruct *
  chartInstance)
{
  c1_init_sf_message_store_memory(chartInstance);
  c1_sdiInitialize(chartInstance);
  sim_mode_is_external(chartInstance->S);
}

static void c1_enter_internal_c1_GCU_Model_genCode
  (SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  chartInstance->c1_is_active_MODES = 1U;
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 1, 418U, (int32_T)
    (chartInstance->c1_is_active_MODES == 1));
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_MODES = 1U;
  chartInstance->c1_lastAacCom = 0U;
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 15, 627U, (void *)
    &chartInstance->c1_lastAacCom);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastAacCom, 1U);
  chartInstance->c1_lastShiftCom = 0U;
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 16, 681U, (void *)
    &chartInstance->c1_lastShiftCom);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastShiftCom, 4U);
  chartInstance->c1_lastClutchCom = 0U;
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 17, 684U, (void *)
    &chartInstance->c1_lastClutchCom);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastClutchCom, 3U);
  chartInstance->c1_lastAutoXCom = 0U;
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 18, 1043U, (void *)
    &chartInstance->c1_lastAutoXCom);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastAutoXCom, 2U);
  chartInstance->c1_buzzerCounter = 0U;
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 19, 1063U, (void *)
    &chartInstance->c1_buzzerCounter);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_buzzerCounter, 0U);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 78U, chartInstance->c1_sfEvent);
  if (chartInstance->c1_is_MODES == c1_IN_INIT) {
  } else {
    chartInstance->c1_is_MODES = c1_IN_INIT;
    c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 1, 418U, (void *)
      &chartInstance->c1_is_MODES);
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
      (chartInstance->c1_is_MODES == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
      (chartInstance->c1_is_MODES == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
      (chartInstance->c1_is_MODES == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
      (chartInstance->c1_is_MODES == 4));
    c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 1);
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 56U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_INIT = 1U;
    sf_call_output_fcn_call(chartInstance->S, 14, "BuzzerOn", 0);
  }

  chartInstance->c1_is_active_NEUTRAL_STATE = 1U;
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 26, 31U, (int32_T)
    (chartInstance->c1_is_active_NEUTRAL_STATE == 1));
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 62U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_NEUTRAL_STATE = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_NEUTRAL_STATE = c1_IN_NEUTRAL;
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 26, 31U, (void *)
    &chartInstance->c1_is_NEUTRAL_STATE);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 27, 36U, (int32_T)
    (chartInstance->c1_is_NEUTRAL_STATE == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 28, 32U, (int32_T)
    (chartInstance->c1_is_NEUTRAL_STATE == 2));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 29, 34U, (int32_T)
    (chartInstance->c1_is_NEUTRAL_STATE == 3));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 30, 35U, (int32_T)
    (chartInstance->c1_is_NEUTRAL_STATE == 4));
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 26, 31U, 1);
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 63U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_NEUTRAL = 1U;
  chartInstance->c1_is_active_GEARSHIFT = 1U;
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 31, 1U, (int32_T)
    (chartInstance->c1_is_active_GEARSHIFT == 1));
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_GEARSHIFT = 1U;
  chartInstance->c1_ticksCounter = 0;
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 54, 45U, (void *)
    &chartInstance->c1_ticksCounter);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_ticksCounter, 13U);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  if (chartInstance->c1_is_GEARSHIFT == c1_b_IN_INIT) {
  } else {
    chartInstance->c1_is_GEARSHIFT = c1_b_IN_INIT;
    c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 31, 1U, (void *)
      &chartInstance->c1_is_GEARSHIFT);
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 32, 697U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 42, 18U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 43, 5U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 44, 7U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 4));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 45, 693U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 5));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 56, 13U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 6));
    c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 1);
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
    chartInstance->c1_b_tp_INIT = 1U;
    chartInstance->c1_ticksCounter = 0;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 54, 45U, (void *)
      &chartInstance->c1_ticksCounter);
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_ticksCounter, 13U);
  }

  chartInstance->c1_is_active_START_ENGINE = 1U;
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 57, 479U, (int32_T)
    (chartInstance->c1_is_active_START_ENGINE == 1));
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 71U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_START_ENGINE = 1U;
  chartInstance->c1_lastCom = 0U;
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 59, 484U, (void *)
    &chartInstance->c1_lastCom);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastCom, 15U);
  chartInstance->c1_startCounter = 0U;
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 60, 488U, (void *)
    &chartInstance->c1_startCounter);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_startCounter, 16U);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 95U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_START_ENGINE = c1_b_IN_WAIT;
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 57, 479U, (void *)
    &chartInstance->c1_is_START_ENGINE);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 58, 482U, (int32_T)
    (chartInstance->c1_is_START_ENGINE == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 59, 483U, (int32_T)
    (chartInstance->c1_is_START_ENGINE == 2));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 60, 494U, (int32_T)
    (chartInstance->c1_is_START_ENGINE == 3));
  c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 57, 479U, 1);
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 74U, chartInstance->c1_sfEvent);
  chartInstance->c1_b_tp_WAIT = 1U;
  if (chartInstance->c1_is_active_SCAN_ADC == 1U) {
  } else {
    chartInstance->c1_is_active_SCAN_ADC = 1U;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 61, 929U, (int32_T)
      (chartInstance->c1_is_active_SCAN_ADC == 1));
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 67U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_SCAN_ADC = 1U;
    chartInstance->c1_timerCounter = 0U;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 61, 938U, (void *)
      &chartInstance->c1_timerCounter);
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_timerCounter, 17U);
    sf_call_output_fcn_enable(chartInstance->S, 16, "ScanADC", 0);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 147U, chartInstance->c1_sfEvent);
  if (chartInstance->c1_is_SCAN_ADC == c1_IN_SCAN) {
  } else {
    chartInstance->c1_is_SCAN_ADC = c1_IN_SCAN;
    c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 61, 929U, (void *)
      &chartInstance->c1_is_SCAN_ADC);
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 62, 932U, (int32_T)
      (chartInstance->c1_is_SCAN_ADC == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 63, 930U, (int32_T)
      (chartInstance->c1_is_SCAN_ADC == 2));
    c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 61, 929U, 1);
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 68U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_SCAN = 1U;
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 69U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 69U, chartInstance->c1_sfEvent);
    sf_call_output_fcn_call(chartInstance->S, 16, "ScanADC", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 69U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 69U, chartInstance->c1_sfEvent);
  }

  chartInstance->c1_is_active_EEPROM_TRIGGER = 1U;
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 64, 940U, (int32_T)
    (chartInstance->c1_is_active_EEPROM_TRIGGER == 1));
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_EEPROM_TRIGGER = 1U;
  chartInstance->c1_counterWait = 0.0;
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 58, 950U, (void *)
    &chartInstance->c1_counterWait);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_counterWait, 14U);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 150U, chartInstance->c1_sfEvent);
  if (chartInstance->c1_is_EEPROM_TRIGGER == c1_IN_WAIT) {
  } else {
    chartInstance->c1_is_EEPROM_TRIGGER = c1_IN_WAIT;
    c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 64, 940U, (void *)
      &chartInstance->c1_is_EEPROM_TRIGGER);
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 65, 946U, (int32_T)
      (chartInstance->c1_is_EEPROM_TRIGGER == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 66, 944U, (int32_T)
      (chartInstance->c1_is_EEPROM_TRIGGER == 2));
    c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 64, 940U, 1);
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_WAIT = 1U;
    chartInstance->c1_counterWait = 1.0;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 58, 950U, (void *)
      &chartInstance->c1_counterWait);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_counterWait, 14U);
  }
}

static void c1_c1_GCU_Model_genCode(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  int32_T c1_i11;
  boolean_T c1_covSaturation;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  if (chartInstance->c1_is_active_c1_GCU_Model_genCode == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_c1_GCU_Model_genCode = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    c1_enter_internal_c1_GCU_Model_genCode(chartInstance);
  } else {
    if (chartInstance->c1_is_active_MODES == 0U) {
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 31U,
                   chartInstance->c1_sfEvent);
      switch (chartInstance->c1_is_MODES) {
       case c1_IN_ACCELERATION:
        CV_STATE_EVAL(31, 0, c1_IN_ACCELERATION);
        c1_ACCELERATION(chartInstance);
        break;

       case c1_IN_AUTOCROSS:
        CV_STATE_EVAL(31, 0, c1_IN_AUTOCROSS);
        c1_AUTOCROSS(chartInstance);
        break;

       case c1_IN_INIT:
        CV_STATE_EVAL(31, 0, c1_IN_INIT);
        c1_INIT(chartInstance);
        break;

       case c1_IN_MANUAL_MODES:
        CV_STATE_EVAL(31, 0, c1_IN_MANUAL_MODES);
        c1_MANUAL_MODES(chartInstance);
        break;

       default:
        CV_STATE_EVAL(31, 0, 0);

        /* Unreachable state, for coverage only */
        chartInstance->c1_is_MODES = c1_IN_NO_ACTIVE_CHILD;
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
          (chartInstance->c1_is_MODES == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
          (chartInstance->c1_is_MODES == 2));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
          (chartInstance->c1_is_MODES == 3));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
          (chartInstance->c1_is_MODES == 4));
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 31U, chartInstance->c1_sfEvent);
    }

    if (chartInstance->c1_is_active_NEUTRAL_STATE == 0U) {
    } else {
      c1_NEUTRAL_STATE(chartInstance);
    }

    if (chartInstance->c1_is_active_GEARSHIFT == 0U) {
    } else {
      c1_GEARSHIFT(chartInstance);
    }

    if (chartInstance->c1_is_active_START_ENGINE == 0U) {
    } else {
      c1_START_ENGINE(chartInstance);
    }

    if (chartInstance->c1_is_active_SCAN_ADC == 0U) {
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 67U,
                   chartInstance->c1_sfEvent);
      switch (chartInstance->c1_is_SCAN_ADC) {
       case c1_IN_SCAN:
        CV_STATE_EVAL(67, 0, c1_IN_SCAN);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 149U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_SCAN = 0U;
        chartInstance->c1_is_SCAN_ADC = c1_IN_NO_ACTIVE_CHILD;
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 62, 932U, (int32_T)
          (chartInstance->c1_is_SCAN_ADC == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 63, 930U, (int32_T)
          (chartInstance->c1_is_SCAN_ADC == 2));
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 68U, chartInstance->c1_sfEvent);
        if (chartInstance->c1_is_SCAN_ADC == c1_IN_WAIT) {
        } else {
          chartInstance->c1_is_SCAN_ADC = c1_IN_WAIT;
          c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 61, 929U, (void *)
            &chartInstance->c1_is_SCAN_ADC);
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 62, 932U, (int32_T)
            (chartInstance->c1_is_SCAN_ADC == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 63, 930U, (int32_T)
            (chartInstance->c1_is_SCAN_ADC == 2));
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 61, 929U, 2);
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 70U, chartInstance->c1_sfEvent);
          chartInstance->c1_c_tp_WAIT = 1U;
          chartInstance->c1_timerCounter = 0U;
          c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 61, 938U, (void *)
            &chartInstance->c1_timerCounter);
          _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_timerCounter, 17U);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 68U, chartInstance->c1_sfEvent);
        break;

       case c1_IN_WAIT:
        CV_STATE_EVAL(67, 0, c1_IN_WAIT);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 148U,
                     chartInstance->c1_sfEvent);
        c1_out = (CV_TRANSITION_EVAL(148U, (int32_T)_SFD_CCP_CALL(5U, 148U, 0,
                    (chartInstance->c1_timerCounter >= ADC_PERIOD) != 0U,
                    chartInstance->c1_sfEvent)) != 0);
        if (c1_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 148U, chartInstance->c1_sfEvent);
          chartInstance->c1_c_tp_WAIT = 0U;
          chartInstance->c1_is_SCAN_ADC = c1_IN_NO_ACTIVE_CHILD;
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 62, 932U, (int32_T)
            (chartInstance->c1_is_SCAN_ADC == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 63, 930U, (int32_T)
            (chartInstance->c1_is_SCAN_ADC == 2));
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 70U, chartInstance->c1_sfEvent);
          if (chartInstance->c1_is_SCAN_ADC == c1_IN_SCAN) {
          } else {
            chartInstance->c1_is_SCAN_ADC = c1_IN_SCAN;
            c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 61, 929U, (void *)
              &chartInstance->c1_is_SCAN_ADC);
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 62, 932U, (int32_T)
              (chartInstance->c1_is_SCAN_ADC == 1));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 63, 930U, (int32_T)
              (chartInstance->c1_is_SCAN_ADC == 2));
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 61, 929U, 1);
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 68U, chartInstance->c1_sfEvent);
            chartInstance->c1_tp_SCAN = 1U;
            _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 69U, chartInstance->c1_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 69U,
                         chartInstance->c1_sfEvent);
            sf_call_output_fcn_call(chartInstance->S, 16, "ScanADC", 0);
            _SFD_SYMBOL_SCOPE_POP();
            _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 69U, chartInstance->c1_sfEvent);
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 69U,
                         chartInstance->c1_sfEvent);
          }
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 70U,
                       chartInstance->c1_sfEvent);
          c1_i11 = c1__s32_add__(chartInstance, (int32_T)
            chartInstance->c1_timerCounter, 1, 930U, 40, 14);
          c1_covSaturation = false;
          if (c1_i11 < 0) {
            c1_covSaturation = true;
            c1_i11 = 0;
            _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 930U, 40U, 14U);
          } else {
            if (c1_i11 > 65535) {
              c1_i11 = 65535;
              _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 930U, 40U, 14U);
            }

            CV_SATURATION_EVAL(4, 70, 0, 0, c1_covSaturation);
          }

          chartInstance->c1_timerCounter = (uint16_T)c1_i11;
          c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 61, 938U, (void *)
            &chartInstance->c1_timerCounter);
          _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_timerCounter, 17U);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 70U, chartInstance->c1_sfEvent);
        break;

       default:
        CV_STATE_EVAL(67, 0, 0);

        /* Unreachable state, for coverage only */
        chartInstance->c1_is_SCAN_ADC = c1_IN_NO_ACTIVE_CHILD;
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 62, 932U, (int32_T)
          (chartInstance->c1_is_SCAN_ADC == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 63, 930U, (int32_T)
          (chartInstance->c1_is_SCAN_ADC == 2));
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 68U, chartInstance->c1_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 67U, chartInstance->c1_sfEvent);
    }

    if (chartInstance->c1_is_active_EEPROM_TRIGGER == 0U) {
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c1_sfEvent);
      switch (chartInstance->c1_is_EEPROM_TRIGGER) {
       case c1_IN_SEND:
        CV_STATE_EVAL(1, 0, c1_IN_SEND);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 152U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_SEND = 0U;
        chartInstance->c1_is_EEPROM_TRIGGER = c1_IN_NO_ACTIVE_CHILD;
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 65, 946U, (int32_T)
          (chartInstance->c1_is_EEPROM_TRIGGER == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 66, 944U, (int32_T)
          (chartInstance->c1_is_EEPROM_TRIGGER == 2));
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
        if (chartInstance->c1_is_EEPROM_TRIGGER == c1_IN_WAIT) {
        } else {
          chartInstance->c1_is_EEPROM_TRIGGER = c1_IN_WAIT;
          c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 64, 940U, (void *)
            &chartInstance->c1_is_EEPROM_TRIGGER);
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 65, 946U, (int32_T)
            (chartInstance->c1_is_EEPROM_TRIGGER == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 66, 944U, (int32_T)
            (chartInstance->c1_is_EEPROM_TRIGGER == 2));
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 64, 940U, 1);
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_WAIT = 1U;
          chartInstance->c1_counterWait = 1.0;
          c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 58, 950U, (void *)
            &chartInstance->c1_counterWait);
          _SFD_DATA_RANGE_CHECK(chartInstance->c1_counterWait, 14U);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
        break;

       case c1_IN_WAIT:
        CV_STATE_EVAL(1, 0, c1_IN_WAIT);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 151U,
                     chartInstance->c1_sfEvent);
        c1_b_out = (CV_TRANSITION_EVAL(151U, (int32_T)_SFD_CCP_CALL(5U, 151U, 0,
          (boolean_T)CV_RELATIONAL_EVAL(5U, 151U, 0,
          chartInstance->c1_counterWait, 10.0, -1, 5U,
          chartInstance->c1_counterWait >= 10.0) != 0U,
          chartInstance->c1_sfEvent)) != 0);
        if (c1_b_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 151U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_WAIT = 0U;
          chartInstance->c1_is_EEPROM_TRIGGER = c1_IN_NO_ACTIVE_CHILD;
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 65, 946U, (int32_T)
            (chartInstance->c1_is_EEPROM_TRIGGER == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 66, 944U, (int32_T)
            (chartInstance->c1_is_EEPROM_TRIGGER == 2));
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
          if (chartInstance->c1_is_EEPROM_TRIGGER == c1_IN_SEND) {
          } else {
            chartInstance->c1_is_EEPROM_TRIGGER = c1_IN_SEND;
            c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 64, 940U, (void *)
              &chartInstance->c1_is_EEPROM_TRIGGER);
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 65, 946U, (int32_T)
              (chartInstance->c1_is_EEPROM_TRIGGER == 1));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 66, 944U, (int32_T)
              (chartInstance->c1_is_EEPROM_TRIGGER == 2));
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 64, 940U, 2);
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
            chartInstance->c1_tp_SEND = 1U;
            sf_call_output_fcn_call(chartInstance->S, 13, "eepromTrigger", 0);
          }
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                       chartInstance->c1_sfEvent);
          chartInstance->c1_counterWait++;
          c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 58, 950U, (void *)
            &chartInstance->c1_counterWait);
          _SFD_DATA_RANGE_CHECK(chartInstance->c1_counterWait, 14U);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c1_sfEvent);
        break;

       default:
        CV_STATE_EVAL(1, 0, 0);

        /* Unreachable state, for coverage only */
        chartInstance->c1_is_EEPROM_TRIGGER = c1_IN_NO_ACTIVE_CHILD;
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 65, 946U, (int32_T)
          (chartInstance->c1_is_EEPROM_TRIGGER == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 66, 944U, (int32_T)
          (chartInstance->c1_is_EEPROM_TRIGGER == 2));
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_GCU_Model_genCode
  (SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_enter_atomic_MANUAL_MODES(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  int32_T c1_i12;
  int32_T c1_i13;
  (*chartInstance->c1_lastModeCom)[0] = (*chartInstance->c1_modeCom)[0];
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
    chartInstance->c1_lastModeCom);
  for (c1_i12 = 0; c1_i12 < 2; c1_i12++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)[c1_i12], 31U);
  }

  (*chartInstance->c1_lastModeCom)[1] = (*chartInstance->c1_modeCom)[1];
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
    chartInstance->c1_lastModeCom);
  for (c1_i13 = 0; c1_i13 < 2; c1_i13++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)[c1_i13], 31U);
  }

  c1_checkShift(chartInstance);
  c1_checkClutch(chartInstance);
}

static void c1_MANUAL_MODES(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  boolean_T c1_temp;
  boolean_T c1_out;
  boolean_T c1_b_out;
  boolean_T c1_c_out;
  boolean_T c1_d_out;
  boolean_T c1_e_out;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 143U, chartInstance->c1_sfEvent);
  c1_temp = _SFD_CCP_CALL(5U, 143U, 0, (boolean_T)CV_RELATIONAL_EVAL(5U, 143U, 0,
    (real_T)(*chartInstance->c1_modeCom)[0], (real_T)
    (*chartInstance->c1_lastModeCom)[0], 0, 1U, (*chartInstance->c1_modeCom)[0]
    != (*chartInstance->c1_lastModeCom)[0]) != 0U, chartInstance->c1_sfEvent);
  if (c1_temp) {
    c1_temp = _SFD_CCP_CALL(5U, 143U, 1, (boolean_T)CV_RELATIONAL_EVAL(5U, 143U,
      1, (real_T)(*chartInstance->c1_modeCom)[1], (real_T)
      (*chartInstance->c1_lastModeCom)[1], 0, 1U, (*chartInstance->c1_modeCom)[1]
      != (*chartInstance->c1_lastModeCom)[1]) != 0U, chartInstance->c1_sfEvent);
  }

  c1_out = (CV_TRANSITION_EVAL(143U, (int32_T)c1_temp) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 143U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 145U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 137U,
                 chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(137U, (int32_T)_SFD_CCP_CALL(5U, 137U, 0,
      ((*chartInstance->c1_modeCom)[1] == ENDURANCE_MODE) != 0U,
      chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 137U, chartInstance->c1_sfEvent);
      c1_exit_internal_MANUAL_MODES(chartInstance);
      chartInstance->c1_tp_MANUAL_MODES = 0U;
      chartInstance->c1_is_MODES = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
        (chartInstance->c1_is_MODES == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
        (chartInstance->c1_is_MODES == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
        (chartInstance->c1_is_MODES == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
        (chartInstance->c1_is_MODES == 4));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 23, 727U, 0);
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 23, 727U, (void *)
        &chartInstance->c1_is_MANUAL_MODES);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 57U, chartInstance->c1_sfEvent);
      if (chartInstance->c1_is_MODES == c1_IN_MANUAL_MODES) {
      } else {
        chartInstance->c1_is_MODES = c1_IN_MANUAL_MODES;
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 1, 418U, (void *)
          &chartInstance->c1_is_MODES);
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
          (chartInstance->c1_is_MODES == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
          (chartInstance->c1_is_MODES == 2));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
          (chartInstance->c1_is_MODES == 3));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
          (chartInstance->c1_is_MODES == 4));
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 57U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_MANUAL_MODES = 1U;
        c1_enter_atomic_MANUAL_MODES(chartInstance);
      }

      chartInstance->c1_is_MANUAL_MODES = c1_IN_ENDURANCE;
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 23, 727U, (void *)
        &chartInstance->c1_is_MANUAL_MODES);
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 24, 729U, (int32_T)
        (chartInstance->c1_is_MANUAL_MODES == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 25, 728U, (int32_T)
        (chartInstance->c1_is_MANUAL_MODES == 2));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 2);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 23, 727U, 1);
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 58U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_ENDURANCE = 1U;
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 138U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 139U,
                   chartInstance->c1_sfEvent);
      c1_c_out = (CV_TRANSITION_EVAL(139U, (int32_T)_SFD_CCP_CALL(5U, 139U, 0,
        ((*chartInstance->c1_modeCom)[1] == SKIDPAD_MODE) != 0U,
        chartInstance->c1_sfEvent)) != 0);
      if (c1_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 139U, chartInstance->c1_sfEvent);
        c1_exit_internal_MANUAL_MODES(chartInstance);
        chartInstance->c1_tp_MANUAL_MODES = 0U;
        chartInstance->c1_is_MODES = c1_IN_NO_ACTIVE_CHILD;
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
          (chartInstance->c1_is_MODES == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
          (chartInstance->c1_is_MODES == 2));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
          (chartInstance->c1_is_MODES == 3));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
          (chartInstance->c1_is_MODES == 4));
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 23, 727U, 0);
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 23, 727U, (void *)
          &chartInstance->c1_is_MANUAL_MODES);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 57U, chartInstance->c1_sfEvent);
        if (chartInstance->c1_is_MODES == c1_IN_MANUAL_MODES) {
        } else {
          chartInstance->c1_is_MODES = c1_IN_MANUAL_MODES;
          c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 1, 418U, (void *)
            &chartInstance->c1_is_MODES);
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
            (chartInstance->c1_is_MODES == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
            (chartInstance->c1_is_MODES == 2));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
            (chartInstance->c1_is_MODES == 3));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
            (chartInstance->c1_is_MODES == 4));
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 57U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_MANUAL_MODES = 1U;
          c1_enter_atomic_MANUAL_MODES(chartInstance);
        }

        chartInstance->c1_is_MANUAL_MODES = c1_IN_SKIDPAD;
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 23, 727U, (void *)
          &chartInstance->c1_is_MANUAL_MODES);
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 24, 729U, (int32_T)
          (chartInstance->c1_is_MANUAL_MODES == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 25, 728U, (int32_T)
          (chartInstance->c1_is_MANUAL_MODES == 2));
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 3);
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 23, 727U, 2);
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_SKIDPAD = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 140U, chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 141U,
                     chartInstance->c1_sfEvent);
        c1_d_out = (CV_TRANSITION_EVAL(141U, (int32_T)_SFD_CCP_CALL(5U, 141U, 0,
          ((*chartInstance->c1_modeCom)[1] == ACCELERATION_MODE) != 0U,
          chartInstance->c1_sfEvent)) != 0);
        if (c1_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 141U, chartInstance->c1_sfEvent);
          c1_exit_internal_MANUAL_MODES(chartInstance);
          chartInstance->c1_tp_MANUAL_MODES = 0U;
          chartInstance->c1_is_MODES = c1_IN_NO_ACTIVE_CHILD;
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
            (chartInstance->c1_is_MODES == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
            (chartInstance->c1_is_MODES == 2));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
            (chartInstance->c1_is_MODES == 3));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
            (chartInstance->c1_is_MODES == 4));
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 23, 727U, 0);
          c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 23, 727U, (void *)
            &chartInstance->c1_is_MANUAL_MODES);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 57U, chartInstance->c1_sfEvent);
          if (chartInstance->c1_is_MODES == c1_IN_ACCELERATION) {
          } else {
            chartInstance->c1_is_MODES = c1_IN_ACCELERATION;
            c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 1, 418U, (void *)
              &chartInstance->c1_is_MODES);
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
              (chartInstance->c1_is_MODES == 1));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
              (chartInstance->c1_is_MODES == 2));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
              (chartInstance->c1_is_MODES == 3));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
              (chartInstance->c1_is_MODES == 4));
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
            chartInstance->c1_tp_ACCELERATION = 1U;
            chartInstance->c1_lastAacCom = (*chartInstance->c1_aacCom)[0];
            c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 15, 627U, (void *)
              &chartInstance->c1_lastAacCom);
            _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastAacCom, 1U);
            (*chartInstance->c1_lastModeCom)[0] = (*chartInstance->c1_modeCom)[0];
            c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
              chartInstance->c1_lastModeCom);
            for (c1_i14 = 0; c1_i14 < 2; c1_i14++) {
              _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)
                                    [c1_i14], 31U);
            }

            (*chartInstance->c1_lastModeCom)[1] = (*chartInstance->c1_modeCom)[1];
            c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
              chartInstance->c1_lastModeCom);
            for (c1_i17 = 0; c1_i17 < 2; c1_i17++) {
              _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)
                                    [c1_i17], 31U);
            }
          }

          c1_enter_internal_ACCELERATION(chartInstance);
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 179U, chartInstance->c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 180U,
                       chartInstance->c1_sfEvent);
          c1_e_out = (CV_TRANSITION_EVAL(180U, (int32_T)_SFD_CCP_CALL(5U, 180U,
            0, ((*chartInstance->c1_modeCom)[1] == AUTOX_MODE) != 0U,
            chartInstance->c1_sfEvent)) != 0);
          if (c1_e_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 180U, chartInstance->c1_sfEvent);
            c1_exit_internal_MANUAL_MODES(chartInstance);
            chartInstance->c1_tp_MANUAL_MODES = 0U;
            chartInstance->c1_is_MODES = c1_IN_NO_ACTIVE_CHILD;
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
              (chartInstance->c1_is_MODES == 1));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
              (chartInstance->c1_is_MODES == 2));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
              (chartInstance->c1_is_MODES == 3));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
              (chartInstance->c1_is_MODES == 4));
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 23, 727U, 0);
            c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 23, 727U, (void *)
              &chartInstance->c1_is_MANUAL_MODES);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 57U, chartInstance->c1_sfEvent);
            if (chartInstance->c1_is_MODES == c1_IN_AUTOCROSS) {
            } else {
              chartInstance->c1_is_MODES = c1_IN_AUTOCROSS;
              c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 1, 418U, (void *)
                &chartInstance->c1_is_MODES);
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
                (chartInstance->c1_is_MODES == 1));
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
                (chartInstance->c1_is_MODES == 2));
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
                (chartInstance->c1_is_MODES == 3));
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
                (chartInstance->c1_is_MODES == 4));
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 44U, chartInstance->c1_sfEvent);
              chartInstance->c1_tp_AUTOCROSS = 1U;
              chartInstance->c1_lastAutoXCom = (*chartInstance->c1_autoXCom)[0];
              c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 18, 1043U, (void *)
                &chartInstance->c1_lastAutoXCom);
              _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastAutoXCom, 2U);
              (*chartInstance->c1_lastModeCom)[0] = (*chartInstance->c1_modeCom)
                [0];
              c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
                chartInstance->c1_lastModeCom);
              for (c1_i16 = 0; c1_i16 < 2; c1_i16++) {
                _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)
                                      [c1_i16], 31U);
              }

              (*chartInstance->c1_lastModeCom)[1] = (*chartInstance->c1_modeCom)
                [1];
              c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
                chartInstance->c1_lastModeCom);
              for (c1_i19 = 0; c1_i19 < 2; c1_i19++) {
                _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)
                                      [c1_i19], 31U);
              }
            }

            c1_enter_internal_AUTOCROSS(chartInstance);
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 181U, chartInstance->c1_sfEvent);
            c1_exit_internal_MANUAL_MODES(chartInstance);
            chartInstance->c1_tp_MANUAL_MODES = 0U;
            chartInstance->c1_is_MODES = c1_IN_NO_ACTIVE_CHILD;
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
              (chartInstance->c1_is_MODES == 1));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
              (chartInstance->c1_is_MODES == 2));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
              (chartInstance->c1_is_MODES == 3));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
              (chartInstance->c1_is_MODES == 4));
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 23, 727U, 0);
            c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 23, 727U, (void *)
              &chartInstance->c1_is_MANUAL_MODES);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 57U, chartInstance->c1_sfEvent);
            if (chartInstance->c1_is_MODES == c1_IN_MANUAL_MODES) {
            } else {
              chartInstance->c1_is_MODES = c1_IN_MANUAL_MODES;
              c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 1, 418U, (void *)
                &chartInstance->c1_is_MODES);
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
                (chartInstance->c1_is_MODES == 1));
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
                (chartInstance->c1_is_MODES == 2));
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
                (chartInstance->c1_is_MODES == 3));
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
                (chartInstance->c1_is_MODES == 4));
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 57U, chartInstance->c1_sfEvent);
              chartInstance->c1_tp_MANUAL_MODES = 1U;
              (*chartInstance->c1_lastModeCom)[0] = (*chartInstance->c1_modeCom)
                [0];
              c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
                chartInstance->c1_lastModeCom);
              for (c1_i15 = 0; c1_i15 < 2; c1_i15++) {
                _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)
                                      [c1_i15], 31U);
              }

              (*chartInstance->c1_lastModeCom)[1] = (*chartInstance->c1_modeCom)
                [1];
              c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
                chartInstance->c1_lastModeCom);
              for (c1_i18 = 0; c1_i18 < 2; c1_i18++) {
                _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)
                                      [c1_i18], 31U);
              }

              c1_checkShift(chartInstance);
              c1_checkClutch(chartInstance);
            }

            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 136U, chartInstance->c1_sfEvent);
            chartInstance->c1_is_MANUAL_MODES = c1_IN_ENDURANCE;
            c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 23, 727U, (void *)
              &chartInstance->c1_is_MANUAL_MODES);
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 24, 729U, (int32_T)
              (chartInstance->c1_is_MANUAL_MODES == 1));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 25, 728U, (int32_T)
              (chartInstance->c1_is_MANUAL_MODES == 2));
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 2);
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 23, 727U, 1);
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 58U, chartInstance->c1_sfEvent);
            chartInstance->c1_tp_ENDURANCE = 1U;
          }
        }
      }
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 57U, chartInstance->c1_sfEvent);
    c1_checkShift(chartInstance);
    c1_checkClutch(chartInstance);
    switch (chartInstance->c1_is_MANUAL_MODES) {
     case c1_IN_ENDURANCE:
      CV_STATE_EVAL(57, 0, c1_IN_ENDURANCE);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 58U,
                   chartInstance->c1_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 58U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_SKIDPAD:
      CV_STATE_EVAL(57, 0, c1_IN_SKIDPAD);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 59U,
                   chartInstance->c1_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 59U, chartInstance->c1_sfEvent);
      break;

     default:
      CV_STATE_EVAL(57, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c1_is_MANUAL_MODES = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 24, 729U, (int32_T)
        (chartInstance->c1_is_MANUAL_MODES == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 25, 728U, (int32_T)
        (chartInstance->c1_is_MANUAL_MODES == 2));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 58U, chartInstance->c1_sfEvent);
      break;
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 57U, chartInstance->c1_sfEvent);
}

static void c1_exit_internal_MANUAL_MODES(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c1_is_MANUAL_MODES) {
   case c1_IN_ENDURANCE:
    CV_STATE_EVAL(57, 1, c1_IN_ENDURANCE);
    chartInstance->c1_tp_ENDURANCE = 0U;
    chartInstance->c1_is_MANUAL_MODES = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 24, 729U, (int32_T)
      (chartInstance->c1_is_MANUAL_MODES == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 25, 728U, (int32_T)
      (chartInstance->c1_is_MANUAL_MODES == 2));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 58U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_SKIDPAD:
    CV_STATE_EVAL(57, 1, c1_IN_SKIDPAD);
    chartInstance->c1_tp_SKIDPAD = 0U;
    chartInstance->c1_is_MANUAL_MODES = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 24, 729U, (int32_T)
      (chartInstance->c1_is_MANUAL_MODES == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 25, 728U, (int32_T)
      (chartInstance->c1_is_MANUAL_MODES == 2));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 59U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(57, 1, 0);
    chartInstance->c1_is_MANUAL_MODES = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 24, 729U, (int32_T)
      (chartInstance->c1_is_MANUAL_MODES == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 25, 728U, (int32_T)
      (chartInstance->c1_is_MANUAL_MODES == 2));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 58U, chartInstance->c1_sfEvent);
    break;
  }
}

static void c1_INIT(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  int32_T c1_i20;
  boolean_T c1_covSaturation;
  boolean_T c1_b_out;
  boolean_T c1_c_out;
  boolean_T c1_d_out;
  boolean_T c1_e_out;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i30;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 79U, chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(79U, (int32_T)_SFD_CCP_CALL(5U, 79U, 0,
              (boolean_T)CV_RELATIONAL_EVAL(5U, 79U, 0, (real_T)
    chartInstance->c1_buzzerCounter, 1000.0, 0, 5U,
    chartInstance->c1_buzzerCounter >= 1000) != 0U, chartInstance->c1_sfEvent))
            != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 79U, chartInstance->c1_sfEvent);
    sf_call_output_fcn_call(chartInstance->S, 15, "BuzzerOff", 0);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 137U,
                 chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(137U, (int32_T)_SFD_CCP_CALL(5U, 137U, 0,
      ((*chartInstance->c1_modeCom)[1] == ENDURANCE_MODE) != 0U,
      chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 137U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_INIT = 0U;
      chartInstance->c1_is_MODES = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
        (chartInstance->c1_is_MODES == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
        (chartInstance->c1_is_MODES == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
        (chartInstance->c1_is_MODES == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
        (chartInstance->c1_is_MODES == 4));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 56U, chartInstance->c1_sfEvent);
      if (chartInstance->c1_is_MODES == c1_IN_MANUAL_MODES) {
      } else {
        chartInstance->c1_is_MODES = c1_IN_MANUAL_MODES;
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 1, 418U, (void *)
          &chartInstance->c1_is_MODES);
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
          (chartInstance->c1_is_MODES == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
          (chartInstance->c1_is_MODES == 2));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
          (chartInstance->c1_is_MODES == 3));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
          (chartInstance->c1_is_MODES == 4));
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 57U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_MANUAL_MODES = 1U;
        (*chartInstance->c1_lastModeCom)[0] = (*chartInstance->c1_modeCom)[0];
        c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
          chartInstance->c1_lastModeCom);
        for (c1_i21 = 0; c1_i21 < 2; c1_i21++) {
          _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)[c1_i21],
                                31U);
        }

        (*chartInstance->c1_lastModeCom)[1] = (*chartInstance->c1_modeCom)[1];
        c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
          chartInstance->c1_lastModeCom);
        for (c1_i23 = 0; c1_i23 < 2; c1_i23++) {
          _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)[c1_i23],
                                31U);
        }

        c1_checkShift(chartInstance);
        c1_checkClutch(chartInstance);
      }

      chartInstance->c1_is_MANUAL_MODES = c1_IN_ENDURANCE;
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 23, 727U, (void *)
        &chartInstance->c1_is_MANUAL_MODES);
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 24, 729U, (int32_T)
        (chartInstance->c1_is_MANUAL_MODES == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 25, 728U, (int32_T)
        (chartInstance->c1_is_MANUAL_MODES == 2));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 2);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 23, 727U, 1);
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 58U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_ENDURANCE = 1U;
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 138U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 139U,
                   chartInstance->c1_sfEvent);
      c1_c_out = (CV_TRANSITION_EVAL(139U, (int32_T)_SFD_CCP_CALL(5U, 139U, 0,
        ((*chartInstance->c1_modeCom)[1] == SKIDPAD_MODE) != 0U,
        chartInstance->c1_sfEvent)) != 0);
      if (c1_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 139U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_INIT = 0U;
        chartInstance->c1_is_MODES = c1_IN_NO_ACTIVE_CHILD;
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
          (chartInstance->c1_is_MODES == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
          (chartInstance->c1_is_MODES == 2));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
          (chartInstance->c1_is_MODES == 3));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
          (chartInstance->c1_is_MODES == 4));
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 56U, chartInstance->c1_sfEvent);
        if (chartInstance->c1_is_MODES == c1_IN_MANUAL_MODES) {
        } else {
          chartInstance->c1_is_MODES = c1_IN_MANUAL_MODES;
          c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 1, 418U, (void *)
            &chartInstance->c1_is_MODES);
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
            (chartInstance->c1_is_MODES == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
            (chartInstance->c1_is_MODES == 2));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
            (chartInstance->c1_is_MODES == 3));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
            (chartInstance->c1_is_MODES == 4));
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 57U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_MANUAL_MODES = 1U;
          (*chartInstance->c1_lastModeCom)[0] = (*chartInstance->c1_modeCom)[0];
          c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
            chartInstance->c1_lastModeCom);
          for (c1_i22 = 0; c1_i22 < 2; c1_i22++) {
            _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)
                                  [c1_i22], 31U);
          }

          (*chartInstance->c1_lastModeCom)[1] = (*chartInstance->c1_modeCom)[1];
          c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
            chartInstance->c1_lastModeCom);
          for (c1_i24 = 0; c1_i24 < 2; c1_i24++) {
            _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)
                                  [c1_i24], 31U);
          }

          c1_checkShift(chartInstance);
          c1_checkClutch(chartInstance);
        }

        chartInstance->c1_is_MANUAL_MODES = c1_IN_SKIDPAD;
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 23, 727U, (void *)
          &chartInstance->c1_is_MANUAL_MODES);
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 24, 729U, (int32_T)
          (chartInstance->c1_is_MANUAL_MODES == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 25, 728U, (int32_T)
          (chartInstance->c1_is_MANUAL_MODES == 2));
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 3);
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 23, 727U, 2);
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_SKIDPAD = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 140U, chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 141U,
                     chartInstance->c1_sfEvent);
        c1_d_out = (CV_TRANSITION_EVAL(141U, (int32_T)_SFD_CCP_CALL(5U, 141U, 0,
          ((*chartInstance->c1_modeCom)[1] == ACCELERATION_MODE) != 0U,
          chartInstance->c1_sfEvent)) != 0);
        if (c1_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 141U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_INIT = 0U;
          chartInstance->c1_is_MODES = c1_IN_NO_ACTIVE_CHILD;
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
            (chartInstance->c1_is_MODES == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
            (chartInstance->c1_is_MODES == 2));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
            (chartInstance->c1_is_MODES == 3));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
            (chartInstance->c1_is_MODES == 4));
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 56U, chartInstance->c1_sfEvent);
          if (chartInstance->c1_is_MODES == c1_IN_ACCELERATION) {
          } else {
            chartInstance->c1_is_MODES = c1_IN_ACCELERATION;
            c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 1, 418U, (void *)
              &chartInstance->c1_is_MODES);
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
              (chartInstance->c1_is_MODES == 1));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
              (chartInstance->c1_is_MODES == 2));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
              (chartInstance->c1_is_MODES == 3));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
              (chartInstance->c1_is_MODES == 4));
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
            chartInstance->c1_tp_ACCELERATION = 1U;
            chartInstance->c1_lastAacCom = (*chartInstance->c1_aacCom)[0];
            c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 15, 627U, (void *)
              &chartInstance->c1_lastAacCom);
            _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastAacCom, 1U);
            (*chartInstance->c1_lastModeCom)[0] = (*chartInstance->c1_modeCom)[0];
            c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
              chartInstance->c1_lastModeCom);
            for (c1_i25 = 0; c1_i25 < 2; c1_i25++) {
              _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)
                                    [c1_i25], 31U);
            }

            (*chartInstance->c1_lastModeCom)[1] = (*chartInstance->c1_modeCom)[1];
            c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
              chartInstance->c1_lastModeCom);
            for (c1_i28 = 0; c1_i28 < 2; c1_i28++) {
              _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)
                                    [c1_i28], 31U);
            }
          }

          c1_enter_internal_ACCELERATION(chartInstance);
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 179U, chartInstance->c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 180U,
                       chartInstance->c1_sfEvent);
          c1_e_out = (CV_TRANSITION_EVAL(180U, (int32_T)_SFD_CCP_CALL(5U, 180U,
            0, ((*chartInstance->c1_modeCom)[1] == AUTOX_MODE) != 0U,
            chartInstance->c1_sfEvent)) != 0);
          if (c1_e_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 180U, chartInstance->c1_sfEvent);
            chartInstance->c1_tp_INIT = 0U;
            chartInstance->c1_is_MODES = c1_IN_NO_ACTIVE_CHILD;
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
              (chartInstance->c1_is_MODES == 1));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
              (chartInstance->c1_is_MODES == 2));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
              (chartInstance->c1_is_MODES == 3));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
              (chartInstance->c1_is_MODES == 4));
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 56U, chartInstance->c1_sfEvent);
            if (chartInstance->c1_is_MODES == c1_IN_AUTOCROSS) {
            } else {
              chartInstance->c1_is_MODES = c1_IN_AUTOCROSS;
              c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 1, 418U, (void *)
                &chartInstance->c1_is_MODES);
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
                (chartInstance->c1_is_MODES == 1));
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
                (chartInstance->c1_is_MODES == 2));
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
                (chartInstance->c1_is_MODES == 3));
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
                (chartInstance->c1_is_MODES == 4));
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 44U, chartInstance->c1_sfEvent);
              chartInstance->c1_tp_AUTOCROSS = 1U;
              chartInstance->c1_lastAutoXCom = (*chartInstance->c1_autoXCom)[0];
              c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 18, 1043U, (void *)
                &chartInstance->c1_lastAutoXCom);
              _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastAutoXCom, 2U);
              (*chartInstance->c1_lastModeCom)[0] = (*chartInstance->c1_modeCom)
                [0];
              c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
                chartInstance->c1_lastModeCom);
              for (c1_i27 = 0; c1_i27 < 2; c1_i27++) {
                _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)
                                      [c1_i27], 31U);
              }

              (*chartInstance->c1_lastModeCom)[1] = (*chartInstance->c1_modeCom)
                [1];
              c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
                chartInstance->c1_lastModeCom);
              for (c1_i30 = 0; c1_i30 < 2; c1_i30++) {
                _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)
                                      [c1_i30], 31U);
              }
            }

            c1_enter_internal_AUTOCROSS(chartInstance);
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 181U, chartInstance->c1_sfEvent);
            chartInstance->c1_tp_INIT = 0U;
            chartInstance->c1_is_MODES = c1_IN_NO_ACTIVE_CHILD;
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
              (chartInstance->c1_is_MODES == 1));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
              (chartInstance->c1_is_MODES == 2));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
              (chartInstance->c1_is_MODES == 3));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
              (chartInstance->c1_is_MODES == 4));
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 56U, chartInstance->c1_sfEvent);
            if (chartInstance->c1_is_MODES == c1_IN_MANUAL_MODES) {
            } else {
              chartInstance->c1_is_MODES = c1_IN_MANUAL_MODES;
              c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 1, 418U, (void *)
                &chartInstance->c1_is_MODES);
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
                (chartInstance->c1_is_MODES == 1));
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
                (chartInstance->c1_is_MODES == 2));
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
                (chartInstance->c1_is_MODES == 3));
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
                (chartInstance->c1_is_MODES == 4));
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 57U, chartInstance->c1_sfEvent);
              chartInstance->c1_tp_MANUAL_MODES = 1U;
              (*chartInstance->c1_lastModeCom)[0] = (*chartInstance->c1_modeCom)
                [0];
              c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
                chartInstance->c1_lastModeCom);
              for (c1_i26 = 0; c1_i26 < 2; c1_i26++) {
                _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)
                                      [c1_i26], 31U);
              }

              (*chartInstance->c1_lastModeCom)[1] = (*chartInstance->c1_modeCom)
                [1];
              c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
                chartInstance->c1_lastModeCom);
              for (c1_i29 = 0; c1_i29 < 2; c1_i29++) {
                _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)
                                      [c1_i29], 31U);
              }

              c1_checkShift(chartInstance);
              c1_checkClutch(chartInstance);
            }

            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 136U, chartInstance->c1_sfEvent);
            chartInstance->c1_is_MANUAL_MODES = c1_IN_ENDURANCE;
            c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 23, 727U, (void *)
              &chartInstance->c1_is_MANUAL_MODES);
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 24, 729U, (int32_T)
              (chartInstance->c1_is_MANUAL_MODES == 1));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 25, 728U, (int32_T)
              (chartInstance->c1_is_MANUAL_MODES == 2));
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 2);
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 23, 727U, 1);
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 58U, chartInstance->c1_sfEvent);
            chartInstance->c1_tp_ENDURANCE = 1U;
          }
        }
      }
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 56U, chartInstance->c1_sfEvent);
    c1_i20 = c1__s32_add__(chartInstance, (int32_T)
      chartInstance->c1_buzzerCounter, 1, 429U, 38, 15);
    c1_covSaturation = false;
    if (c1_i20 < 0) {
      c1_covSaturation = true;
      c1_i20 = 0;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 429U, 38U, 15U);
    } else {
      if (c1_i20 > 65535) {
        c1_i20 = 65535;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 429U, 38U, 15U);
      }

      CV_SATURATION_EVAL(4, 56, 0, 0, c1_covSaturation);
    }

    chartInstance->c1_buzzerCounter = (uint16_T)c1_i20;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 19, 1063U, (void *)
      &chartInstance->c1_buzzerCounter);
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_buzzerCounter, 0U);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 56U, chartInstance->c1_sfEvent);
}

static void c1_enter_internal_ACCELERATION(SFc1_GCU_Model_genCodeInstanceStruct *
  chartInstance)
{
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 142U, chartInstance->c1_sfEvent);
  if (chartInstance->c1_is_ACCELERATION == c1_IN_DEFAULT) {
  } else {
    chartInstance->c1_is_ACCELERATION = c1_IN_DEFAULT;
    c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 2, 820U, (void *)
      &chartInstance->c1_is_ACCELERATION);
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 3, 434U, (int32_T)
      (chartInstance->c1_is_ACCELERATION == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 11, 821U, (int32_T)
      (chartInstance->c1_is_ACCELERATION == 2));
    c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 4);
    c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 2, 820U, 1);
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 43U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_DEFAULT = 1U;
    *chartInstance->c1_stateFb = (uint16_T)ACC_OFF;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 10, 833U, (void *)
      chartInstance->c1_stateFb);
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_stateFb, 32U);
    c1_checkShift(chartInstance);
    c1_checkClutch(chartInstance);
  }
}

static void c1_ACCELERATION(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  boolean_T c1_temp;
  boolean_T c1_out;
  boolean_T c1_b_out;
  boolean_T c1_c_out;
  boolean_T c1_d_out;
  boolean_T c1_e_out;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 144U, chartInstance->c1_sfEvent);
  c1_temp = _SFD_CCP_CALL(5U, 144U, 0, (boolean_T)CV_RELATIONAL_EVAL(5U, 144U, 0,
    (real_T)(*chartInstance->c1_modeCom)[0], (real_T)
    (*chartInstance->c1_lastModeCom)[0], 0, 1U, (*chartInstance->c1_modeCom)[0]
    != (*chartInstance->c1_lastModeCom)[0]) != 0U, chartInstance->c1_sfEvent);
  if (c1_temp) {
    c1_temp = _SFD_CCP_CALL(5U, 144U, 1, (boolean_T)CV_RELATIONAL_EVAL(5U, 144U,
      1, (real_T)(*chartInstance->c1_modeCom)[1], (real_T)
      (*chartInstance->c1_lastModeCom)[1], 0, 1U, (*chartInstance->c1_modeCom)[1]
      != (*chartInstance->c1_lastModeCom)[1]) != 0U, chartInstance->c1_sfEvent);
  }

  c1_out = (CV_TRANSITION_EVAL(144U, (int32_T)c1_temp) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 144U, chartInstance->c1_sfEvent);
    sf_call_output_fcn_call(chartInstance->S, 5, "Efi_unsetRPMLimiter", 0);
    *chartInstance->c1_stateFb = (uint16_T)ACC_OFF;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 10, 833U, (void *)
      chartInstance->c1_stateFb);
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_stateFb, 32U);
    c1_Clutch_setValue(chartInstance, 0U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 145U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 137U,
                 chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(137U, (int32_T)_SFD_CCP_CALL(5U, 137U, 0,
      ((*chartInstance->c1_modeCom)[1] == ENDURANCE_MODE) != 0U,
      chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 137U, chartInstance->c1_sfEvent);
      c1_exit_internal_ACCELERATION(chartInstance);
      chartInstance->c1_tp_ACCELERATION = 0U;
      chartInstance->c1_is_MODES = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
        (chartInstance->c1_is_MODES == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
        (chartInstance->c1_is_MODES == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
        (chartInstance->c1_is_MODES == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
        (chartInstance->c1_is_MODES == 4));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 2, 820U, 0);
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 2, 820U, (void *)
        &chartInstance->c1_is_ACCELERATION);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
      if (chartInstance->c1_is_MODES == c1_IN_MANUAL_MODES) {
      } else {
        chartInstance->c1_is_MODES = c1_IN_MANUAL_MODES;
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 1, 418U, (void *)
          &chartInstance->c1_is_MODES);
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
          (chartInstance->c1_is_MODES == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
          (chartInstance->c1_is_MODES == 2));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
          (chartInstance->c1_is_MODES == 3));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
          (chartInstance->c1_is_MODES == 4));
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 57U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_MANUAL_MODES = 1U;
        c1_enter_atomic_MANUAL_MODES(chartInstance);
      }

      chartInstance->c1_is_MANUAL_MODES = c1_IN_ENDURANCE;
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 23, 727U, (void *)
        &chartInstance->c1_is_MANUAL_MODES);
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 24, 729U, (int32_T)
        (chartInstance->c1_is_MANUAL_MODES == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 25, 728U, (int32_T)
        (chartInstance->c1_is_MANUAL_MODES == 2));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 2);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 23, 727U, 1);
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 58U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_ENDURANCE = 1U;
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 138U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 139U,
                   chartInstance->c1_sfEvent);
      c1_c_out = (CV_TRANSITION_EVAL(139U, (int32_T)_SFD_CCP_CALL(5U, 139U, 0,
        ((*chartInstance->c1_modeCom)[1] == SKIDPAD_MODE) != 0U,
        chartInstance->c1_sfEvent)) != 0);
      if (c1_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 139U, chartInstance->c1_sfEvent);
        c1_exit_internal_ACCELERATION(chartInstance);
        chartInstance->c1_tp_ACCELERATION = 0U;
        chartInstance->c1_is_MODES = c1_IN_NO_ACTIVE_CHILD;
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
          (chartInstance->c1_is_MODES == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
          (chartInstance->c1_is_MODES == 2));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
          (chartInstance->c1_is_MODES == 3));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
          (chartInstance->c1_is_MODES == 4));
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 2, 820U, 0);
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 2, 820U, (void *)
          &chartInstance->c1_is_ACCELERATION);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
        if (chartInstance->c1_is_MODES == c1_IN_MANUAL_MODES) {
        } else {
          chartInstance->c1_is_MODES = c1_IN_MANUAL_MODES;
          c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 1, 418U, (void *)
            &chartInstance->c1_is_MODES);
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
            (chartInstance->c1_is_MODES == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
            (chartInstance->c1_is_MODES == 2));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
            (chartInstance->c1_is_MODES == 3));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
            (chartInstance->c1_is_MODES == 4));
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 57U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_MANUAL_MODES = 1U;
          c1_enter_atomic_MANUAL_MODES(chartInstance);
        }

        chartInstance->c1_is_MANUAL_MODES = c1_IN_SKIDPAD;
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 23, 727U, (void *)
          &chartInstance->c1_is_MANUAL_MODES);
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 24, 729U, (int32_T)
          (chartInstance->c1_is_MANUAL_MODES == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 25, 728U, (int32_T)
          (chartInstance->c1_is_MANUAL_MODES == 2));
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 3);
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 23, 727U, 2);
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_SKIDPAD = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 140U, chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 141U,
                     chartInstance->c1_sfEvent);
        c1_d_out = (CV_TRANSITION_EVAL(141U, (int32_T)_SFD_CCP_CALL(5U, 141U, 0,
          ((*chartInstance->c1_modeCom)[1] == ACCELERATION_MODE) != 0U,
          chartInstance->c1_sfEvent)) != 0);
        if (c1_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 141U, chartInstance->c1_sfEvent);
          c1_exit_internal_ACCELERATION(chartInstance);
          chartInstance->c1_tp_ACCELERATION = 0U;
          chartInstance->c1_is_MODES = c1_IN_NO_ACTIVE_CHILD;
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
            (chartInstance->c1_is_MODES == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
            (chartInstance->c1_is_MODES == 2));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
            (chartInstance->c1_is_MODES == 3));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
            (chartInstance->c1_is_MODES == 4));
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 2, 820U, 0);
          c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 2, 820U, (void *)
            &chartInstance->c1_is_ACCELERATION);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
          if (chartInstance->c1_is_MODES == c1_IN_ACCELERATION) {
          } else {
            chartInstance->c1_is_MODES = c1_IN_ACCELERATION;
            c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 1, 418U, (void *)
              &chartInstance->c1_is_MODES);
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
              (chartInstance->c1_is_MODES == 1));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
              (chartInstance->c1_is_MODES == 2));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
              (chartInstance->c1_is_MODES == 3));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
              (chartInstance->c1_is_MODES == 4));
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
            chartInstance->c1_tp_ACCELERATION = 1U;
            chartInstance->c1_lastAacCom = (*chartInstance->c1_aacCom)[0];
            c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 15, 627U, (void *)
              &chartInstance->c1_lastAacCom);
            _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastAacCom, 1U);
            (*chartInstance->c1_lastModeCom)[0] = (*chartInstance->c1_modeCom)[0];
            c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
              chartInstance->c1_lastModeCom);
            for (c1_i31 = 0; c1_i31 < 2; c1_i31++) {
              _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)
                                    [c1_i31], 31U);
            }

            (*chartInstance->c1_lastModeCom)[1] = (*chartInstance->c1_modeCom)[1];
            c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
              chartInstance->c1_lastModeCom);
            for (c1_i34 = 0; c1_i34 < 2; c1_i34++) {
              _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)
                                    [c1_i34], 31U);
            }
          }

          c1_enter_internal_ACCELERATION(chartInstance);
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 179U, chartInstance->c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 180U,
                       chartInstance->c1_sfEvent);
          c1_e_out = (CV_TRANSITION_EVAL(180U, (int32_T)_SFD_CCP_CALL(5U, 180U,
            0, ((*chartInstance->c1_modeCom)[1] == AUTOX_MODE) != 0U,
            chartInstance->c1_sfEvent)) != 0);
          if (c1_e_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 180U, chartInstance->c1_sfEvent);
            c1_exit_internal_ACCELERATION(chartInstance);
            chartInstance->c1_tp_ACCELERATION = 0U;
            chartInstance->c1_is_MODES = c1_IN_NO_ACTIVE_CHILD;
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
              (chartInstance->c1_is_MODES == 1));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
              (chartInstance->c1_is_MODES == 2));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
              (chartInstance->c1_is_MODES == 3));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
              (chartInstance->c1_is_MODES == 4));
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 2, 820U, 0);
            c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 2, 820U, (void *)
              &chartInstance->c1_is_ACCELERATION);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
            if (chartInstance->c1_is_MODES == c1_IN_AUTOCROSS) {
            } else {
              chartInstance->c1_is_MODES = c1_IN_AUTOCROSS;
              c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 1, 418U, (void *)
                &chartInstance->c1_is_MODES);
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
                (chartInstance->c1_is_MODES == 1));
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
                (chartInstance->c1_is_MODES == 2));
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
                (chartInstance->c1_is_MODES == 3));
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
                (chartInstance->c1_is_MODES == 4));
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 44U, chartInstance->c1_sfEvent);
              chartInstance->c1_tp_AUTOCROSS = 1U;
              chartInstance->c1_lastAutoXCom = (*chartInstance->c1_autoXCom)[0];
              c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 18, 1043U, (void *)
                &chartInstance->c1_lastAutoXCom);
              _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastAutoXCom, 2U);
              (*chartInstance->c1_lastModeCom)[0] = (*chartInstance->c1_modeCom)
                [0];
              c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
                chartInstance->c1_lastModeCom);
              for (c1_i33 = 0; c1_i33 < 2; c1_i33++) {
                _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)
                                      [c1_i33], 31U);
              }

              (*chartInstance->c1_lastModeCom)[1] = (*chartInstance->c1_modeCom)
                [1];
              c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
                chartInstance->c1_lastModeCom);
              for (c1_i36 = 0; c1_i36 < 2; c1_i36++) {
                _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)
                                      [c1_i36], 31U);
              }
            }

            c1_enter_internal_AUTOCROSS(chartInstance);
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 181U, chartInstance->c1_sfEvent);
            c1_exit_internal_ACCELERATION(chartInstance);
            chartInstance->c1_tp_ACCELERATION = 0U;
            chartInstance->c1_is_MODES = c1_IN_NO_ACTIVE_CHILD;
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
              (chartInstance->c1_is_MODES == 1));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
              (chartInstance->c1_is_MODES == 2));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
              (chartInstance->c1_is_MODES == 3));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
              (chartInstance->c1_is_MODES == 4));
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 2, 820U, 0);
            c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 2, 820U, (void *)
              &chartInstance->c1_is_ACCELERATION);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
            if (chartInstance->c1_is_MODES == c1_IN_MANUAL_MODES) {
            } else {
              chartInstance->c1_is_MODES = c1_IN_MANUAL_MODES;
              c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 1, 418U, (void *)
                &chartInstance->c1_is_MODES);
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
                (chartInstance->c1_is_MODES == 1));
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
                (chartInstance->c1_is_MODES == 2));
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
                (chartInstance->c1_is_MODES == 3));
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
                (chartInstance->c1_is_MODES == 4));
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 57U, chartInstance->c1_sfEvent);
              chartInstance->c1_tp_MANUAL_MODES = 1U;
              (*chartInstance->c1_lastModeCom)[0] = (*chartInstance->c1_modeCom)
                [0];
              c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
                chartInstance->c1_lastModeCom);
              for (c1_i32 = 0; c1_i32 < 2; c1_i32++) {
                _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)
                                      [c1_i32], 31U);
              }

              (*chartInstance->c1_lastModeCom)[1] = (*chartInstance->c1_modeCom)
                [1];
              c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
                chartInstance->c1_lastModeCom);
              for (c1_i35 = 0; c1_i35 < 2; c1_i35++) {
                _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)
                                      [c1_i35], 31U);
              }

              c1_checkShift(chartInstance);
              c1_checkClutch(chartInstance);
            }

            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 136U, chartInstance->c1_sfEvent);
            chartInstance->c1_is_MANUAL_MODES = c1_IN_ENDURANCE;
            c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 23, 727U, (void *)
              &chartInstance->c1_is_MANUAL_MODES);
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 24, 729U, (int32_T)
              (chartInstance->c1_is_MANUAL_MODES == 1));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 25, 728U, (int32_T)
              (chartInstance->c1_is_MANUAL_MODES == 2));
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 2);
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 23, 727U, 1);
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 58U, chartInstance->c1_sfEvent);
            chartInstance->c1_tp_ENDURANCE = 1U;
          }
        }
      }
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 32U, chartInstance->c1_sfEvent);
    switch (chartInstance->c1_is_ACCELERATION) {
     case c1_IN_ACC:
      CV_STATE_EVAL(32, 0, c1_IN_ACC);
      c1_ACC(chartInstance);
      break;

     case c1_IN_DEFAULT:
      CV_STATE_EVAL(32, 0, c1_IN_DEFAULT);
      c1_DEFAULT(chartInstance);
      break;

     default:
      CV_STATE_EVAL(32, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c1_is_ACCELERATION = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 3, 434U, (int32_T)
        (chartInstance->c1_is_ACCELERATION == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 11, 821U, (int32_T)
        (chartInstance->c1_is_ACCELERATION == 2));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c1_sfEvent);
      break;
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 32U, chartInstance->c1_sfEvent);
}

static void c1_exit_internal_ACCELERATION(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c1_is_ACCELERATION) {
   case c1_IN_ACC:
    CV_STATE_EVAL(32, 1, c1_IN_ACC);
    switch (chartInstance->c1_is_ACC) {
     case c1_IN_ACTIVE:
      CV_STATE_EVAL(33, 1, c1_IN_ACTIVE);
      c1_exit_internal_ACTIVE(chartInstance);
      chartInstance->c1_tp_ACTIVE = 0U;
      chartInstance->c1_is_ACC = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 4, 538U, (int32_T)
        (chartInstance->c1_is_ACC == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 10, 515U, (int32_T)
        (chartInstance->c1_is_ACC == 2));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 4, 538U, 0);
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 4, 538U, (void *)
        &chartInstance->c1_is_ACTIVE);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_STOPPING:
      CV_STATE_EVAL(33, 1, c1_IN_STOPPING);
      chartInstance->c1_tp_STOPPING = 0U;
      chartInstance->c1_is_ACC = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 4, 538U, (int32_T)
        (chartInstance->c1_is_ACC == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 10, 515U, (int32_T)
        (chartInstance->c1_is_ACC == 2));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 41U, chartInstance->c1_sfEvent);
      break;

     default:
      CV_STATE_EVAL(33, 1, 0);
      chartInstance->c1_is_ACC = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 4, 538U, (int32_T)
        (chartInstance->c1_is_ACC == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 10, 515U, (int32_T)
        (chartInstance->c1_is_ACC == 2));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
      break;
    }

    chartInstance->c1_tp_ACC = 0U;
    chartInstance->c1_is_ACCELERATION = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 3, 434U, (int32_T)
      (chartInstance->c1_is_ACCELERATION == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 11, 821U, (int32_T)
      (chartInstance->c1_is_ACCELERATION == 2));
    c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 3, 434U, 0);
    c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 3, 434U, (void *)
      &chartInstance->c1_is_ACC);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_DEFAULT:
    CV_STATE_EVAL(32, 1, c1_IN_DEFAULT);
    chartInstance->c1_tp_DEFAULT = 0U;
    chartInstance->c1_is_ACCELERATION = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 3, 434U, (int32_T)
      (chartInstance->c1_is_ACCELERATION == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 11, 821U, (int32_T)
      (chartInstance->c1_is_ACCELERATION == 2));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 43U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(32, 1, 0);
    chartInstance->c1_is_ACCELERATION = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 3, 434U, (int32_T)
      (chartInstance->c1_is_ACCELERATION == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 11, 821U, (int32_T)
      (chartInstance->c1_is_ACCELERATION == 2));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c1_sfEvent);
    break;
  }
}

static void c1_ACC(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 33U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_ACC) {
   case c1_IN_ACTIVE:
    CV_STATE_EVAL(33, 0, c1_IN_ACTIVE);
    c1_ACTIVE(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 33U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_STOPPING:
    CV_STATE_EVAL(33, 0, c1_IN_STOPPING);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 120U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_STOPPING = 0U;
    chartInstance->c1_is_ACC = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 4, 538U, (int32_T)
      (chartInstance->c1_is_ACC == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 10, 515U, (int32_T)
      (chartInstance->c1_is_ACC == 2));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 41U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_ACC = 0U;
    chartInstance->c1_is_ACCELERATION = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 3, 434U, (int32_T)
      (chartInstance->c1_is_ACCELERATION == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 11, 821U, (int32_T)
      (chartInstance->c1_is_ACCELERATION == 2));
    c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 3, 434U, 0);
    c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 3, 434U, (void *)
      &chartInstance->c1_is_ACC);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c1_sfEvent);
    if (chartInstance->c1_is_ACCELERATION == c1_IN_DEFAULT) {
    } else {
      chartInstance->c1_is_ACCELERATION = c1_IN_DEFAULT;
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 2, 820U, (void *)
        &chartInstance->c1_is_ACCELERATION);
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 3, 434U, (int32_T)
        (chartInstance->c1_is_ACCELERATION == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 11, 821U, (int32_T)
        (chartInstance->c1_is_ACCELERATION == 2));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 4);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 2, 820U, 1);
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 43U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_DEFAULT = 1U;
      *chartInstance->c1_stateFb = (uint16_T)ACC_OFF;
      c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 10, 833U, (void *)
        chartInstance->c1_stateFb);
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_stateFb, 32U);
      c1_checkShift(chartInstance);
      c1_checkClutch(chartInstance);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 41U, chartInstance->c1_sfEvent);
    if (chartInstance->c1_is_ACCELERATION != c1_IN_ACC) {
    } else {
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 33U, chartInstance->c1_sfEvent);
    }
    break;

   default:
    CV_STATE_EVAL(33, 0, 0);

    /* Unreachable state, for coverage only */
    chartInstance->c1_is_ACC = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 4, 538U, (int32_T)
      (chartInstance->c1_is_ACC == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 10, 515U, (int32_T)
      (chartInstance->c1_is_ACC == 2));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 33U, chartInstance->c1_sfEvent);
    break;
  }
}

static void c1_ACTIVE(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  boolean_T c1_temp;
  boolean_T c1_out;
  boolean_T c1_b_out;
  boolean_T c1_c_out;
  uint16_T c1_u0;
  int32_T c1_i37;
  boolean_T c1_covSaturation;
  boolean_T c1_b_temp;
  boolean_T c1_c_temp;
  int32_T c1_i38;
  boolean_T c1_d_out;
  int32_T c1_i39;
  real_T c1_d0;
  boolean_T c1_b_covSaturation;
  uint8_T c1_u1;
  int32_T c1_q0;
  int32_T c1_q1;
  boolean_T c1_c_covSaturation;
  int32_T c1_qY;
  int64_T c1_i40;
  boolean_T c1_d_covSaturation;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 100U, chartInstance->c1_sfEvent);
  c1_temp = _SFD_CCP_CALL(5U, 100U, 0, (boolean_T)CV_RELATIONAL_EVAL(5U, 100U, 0,
    (real_T)(*chartInstance->c1_aacCom)[0], (real_T)chartInstance->c1_lastAacCom,
    0, 1U, (*chartInstance->c1_aacCom)[0] != chartInstance->c1_lastAacCom) != 0U,
    chartInstance->c1_sfEvent);
  if (c1_temp) {
    c1_temp = _SFD_CCP_CALL(5U, 100U, 1, ((*chartInstance->c1_aacCom)[1] ==
      ACC_OFF) != 0U, chartInstance->c1_sfEvent);
  }

  c1_out = (CV_TRANSITION_EVAL(100U, (int32_T)c1_temp) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 100U, chartInstance->c1_sfEvent);
    chartInstance->c1_lastAacCom = (*chartInstance->c1_aacCom)[0];
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 15, 627U, (void *)
      &chartInstance->c1_lastAacCom);
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastAacCom, 1U);
    c1_u0 = chartInstance->c1_lastAacCom;
    sf_mex_printf("%s =\\n", "lastAacCom");
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11, c1_u0);
    c1_exit_internal_ACTIVE(chartInstance);
    chartInstance->c1_tp_ACTIVE = 0U;
    chartInstance->c1_is_ACC = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 4, 538U, (int32_T)
      (chartInstance->c1_is_ACC == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 10, 515U, (int32_T)
      (chartInstance->c1_is_ACC == 2));
    c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 4, 538U, 0);
    c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 4, 538U, (void *)
      &chartInstance->c1_is_ACTIVE);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
    if (chartInstance->c1_is_ACC == c1_IN_STOPPING) {
    } else {
      chartInstance->c1_is_ACC = c1_IN_STOPPING;
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 3, 434U, (void *)
        &chartInstance->c1_is_ACC);
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 4, 538U, (int32_T)
        (chartInstance->c1_is_ACC == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 10, 515U, (int32_T)
        (chartInstance->c1_is_ACC == 2));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 17);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 2, 820U, 7);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 3, 434U, 6);
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 41U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_STOPPING = 1U;
      sf_call_output_fcn_call(chartInstance->S, 5, "Efi_unsetRPMLimiter", 0);
      c1_Clutch_setValue(chartInstance, 0U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 34U, chartInstance->c1_sfEvent);
    switch (chartInstance->c1_is_ACTIVE) {
     case c1_IN_READY:
      CV_STATE_EVAL(34, 0, c1_IN_READY);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 106U,
                   chartInstance->c1_sfEvent);
      c1_b_out = (CV_TRANSITION_EVAL(106U, (int32_T)_SFD_CCP_CALL(5U, 106U, 0,
        (boolean_T)CV_RELATIONAL_EVAL(5U, 106U, 0, (real_T)
        chartInstance->c1_aacCounter, 1.0, 0, 3U, chartInstance->c1_aacCounter <=
        1) != 0U, chartInstance->c1_sfEvent)) != 0);
      if (c1_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 106U, chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 101U,
                     chartInstance->c1_sfEvent);
        c1_b_temp = _SFD_CCP_CALL(5U, 101U, 0, (boolean_T)CV_RELATIONAL_EVAL(5U,
          101U, 0, (real_T)(*chartInstance->c1_aacCom)[0], (real_T)
          chartInstance->c1_lastAacCom, 0, 1U, (*chartInstance->c1_aacCom)[0] !=
          chartInstance->c1_lastAacCom) != 0U, chartInstance->c1_sfEvent);
        if (c1_b_temp) {
          c1_b_temp = _SFD_CCP_CALL(5U, 101U, 1, ((*chartInstance->c1_aacCom)[1]
            == ACC_GO) != 0U, chartInstance->c1_sfEvent);
        }

        c1_c_temp = c1_b_temp;
        if (c1_c_temp) {
          c1_i38 = (*chartInstance->c1_acc_externValues)[sf_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 539U, 51, 16, 23U,
             (int32_T)acc_values_TPS, 0, 2)];
          c1_i39 = c1_getAacParam(chartInstance, acc_params_TPS_START_LIMIT);
          c1_c_temp = _SFD_CCP_CALL(5U, 101U, 2, (boolean_T)CV_RELATIONAL_EVAL
            (5U, 101U, 1, (real_T)c1_i38, (real_T)c1_i39, 0, 5U, c1_i38 >=
             c1_i39) != 0U, chartInstance->c1_sfEvent);
        }

        c1_d_out = (CV_TRANSITION_EVAL(101U, (int32_T)c1_c_temp) != 0);
        if (c1_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 101U, chartInstance->c1_sfEvent);
          chartInstance->c1_lastAacCom = (*chartInstance->c1_aacCom)[0];
          c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 15, 627U, (void *)
            &chartInstance->c1_lastAacCom);
          _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastAacCom, 1U);
          chartInstance->c1_tp_READY = 0U;
          chartInstance->c1_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 5, 545U, (int32_T)
            (chartInstance->c1_is_ACTIVE == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 6, 544U, (int32_T)
            (chartInstance->c1_is_ACTIVE == 2));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 7, 514U, (int32_T)
            (chartInstance->c1_is_ACTIVE == 3));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 8, 543U, (int32_T)
            (chartInstance->c1_is_ACTIVE == 4));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 9, 547U, (int32_T)
            (chartInstance->c1_is_ACTIVE == 5));
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
          if (chartInstance->c1_is_ACTIVE == c1_IN_START_RELEASE) {
          } else {
            chartInstance->c1_is_ACTIVE = c1_IN_START_RELEASE;
            c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 4, 538U, (void *)
              &chartInstance->c1_is_ACTIVE);
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 5, 545U, (int32_T)
              (chartInstance->c1_is_ACTIVE == 1));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 6, 544U, (int32_T)
              (chartInstance->c1_is_ACTIVE == 2));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 7, 514U, (int32_T)
              (chartInstance->c1_is_ACTIVE == 3));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 8, 543U, (int32_T)
              (chartInstance->c1_is_ACTIVE == 4));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 9, 547U, (int32_T)
              (chartInstance->c1_is_ACTIVE == 5));
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 14);
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 2, 820U, 4);
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 3, 434U, 3);
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 4, 538U, 3);
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
            chartInstance->c1_tp_START_RELEASE = 1U;
            *chartInstance->c1_stateFb = (uint16_T)ACC_GO;
            c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 10, 833U, (void *)
              chartInstance->c1_stateFb);
            _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_stateFb, 32U);
            chartInstance->c1_aac_clutchValue = (real_T)c1_getAacParam
              (chartInstance, acc_params_RAMP_START);
            c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 30, 561U, (void *)
              &chartInstance->c1_aac_clutchValue);
            _SFD_DATA_RANGE_CHECK(chartInstance->c1_aac_clutchValue, 7U);
            c1_d0 = chartInstance->c1_aac_clutchValue;
            c1_b_covSaturation = false;
            if (c1_d0 < 256.0) {
              if (c1_d0 >= 0.0) {
                c1_u1 = (uint8_T)c1_d0;
              } else {
                c1_b_covSaturation = true;
                c1_u1 = 0U;
                _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 547U, 120U, 5U);
              }
            } else if (c1_d0 >= 256.0) {
              c1_b_covSaturation = true;
              c1_u1 = MAX_uint8_T;
              _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 547U, 120U, 5U);
            } else {
              c1_u1 = 0U;
            }

            CV_SATURATION_EVAL(4, 39, 0, 0, c1_b_covSaturation);
            c1_Clutch_setValue(chartInstance, c1_u1);
            chartInstance->c1_aac_dtRelease = c1_div_nzp_s32(chartInstance,
              c1_getAacParam(chartInstance, acc_params_RAMP_TIME), (int32_T)
              c1_const_AAC_WORK_RATE_ms, 547U, 196, 1);
            c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 32, 564U, (void *)
              &chartInstance->c1_aac_dtRelease);
            _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_aac_dtRelease, 8U);
            c1_q0 = c1_getAacParam(chartInstance, acc_params_RAMP_START);
            c1_q1 = c1_getAacParam(chartInstance, acc_params_RAMP_END);
            c1_c_covSaturation = false;
            if ((c1_q0 >= 0) && (c1_q1 < c1_q0 - MAX_int32_T)) {
              c1_c_covSaturation = true;
              c1_qY = MAX_int32_T;
              _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 547U, 284U, 1U);
            } else if ((c1_q0 < 0) && (c1_q1 > c1_q0 - MIN_int32_T)) {
              c1_c_covSaturation = true;
              c1_qY = MIN_int32_T;
              _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 547U, 284U, 1U);
            } else {
              c1_qY = c1_q0 - c1_q1;
            }

            CV_SATURATION_EVAL(4, 39, 1, 0, c1_c_covSaturation);
            c1_i40 = (int64_T)c1_qY * (int64_T)c1_const_AAC_WORK_RATE_ms;
            c1_d_covSaturation = false;
            if (c1_i40 > 2147483647LL) {
              c1_d_covSaturation = true;
              c1_i40 = 2147483647LL;
              _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 547U, 320U, 1U);
            } else {
              if (c1_i40 < -2147483648LL) {
                c1_d_covSaturation = true;
                c1_i40 = -2147483648LL;
                _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 547U, 320U, 1U);
              }
            }

            CV_SATURATION_EVAL(4, 39, 2, 0, c1_d_covSaturation);
            chartInstance->c1_aac_clutchStep = (real_T)(int32_T)c1_i40 / (real_T)
              c1_getAacParam(chartInstance, acc_params_RAMP_TIME);
            c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 31, 563U, (void *)
              &chartInstance->c1_aac_clutchStep);
            _SFD_DATA_RANGE_CHECK(chartInstance->c1_aac_clutchStep, 6U);
            chartInstance->c1_aacCounter = c1_const_AAC_WORK_RATE_ms;
            c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 29, 550U, (void *)
              &chartInstance->c1_aacCounter);
            _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_aacCounter, 5U);
          }
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 107U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_READY = 0U;
          chartInstance->c1_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 5, 545U, (int32_T)
            (chartInstance->c1_is_ACTIVE == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 6, 544U, (int32_T)
            (chartInstance->c1_is_ACTIVE == 2));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 7, 514U, (int32_T)
            (chartInstance->c1_is_ACTIVE == 3));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 8, 543U, (int32_T)
            (chartInstance->c1_is_ACTIVE == 4));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 9, 547U, (int32_T)
            (chartInstance->c1_is_ACTIVE == 5));
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
          if (chartInstance->c1_is_ACTIVE == c1_IN_READY) {
          } else {
            chartInstance->c1_is_ACTIVE = c1_IN_READY;
            c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 4, 538U, (void *)
              &chartInstance->c1_is_ACTIVE);
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 5, 545U, (int32_T)
              (chartInstance->c1_is_ACTIVE == 1));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 6, 544U, (int32_T)
              (chartInstance->c1_is_ACTIVE == 2));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 7, 514U, (int32_T)
              (chartInstance->c1_is_ACTIVE == 3));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 8, 543U, (int32_T)
              (chartInstance->c1_is_ACTIVE == 4));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 9, 547U, (int32_T)
              (chartInstance->c1_is_ACTIVE == 5));
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 13);
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 2, 820U, 3);
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 3, 434U, 2);
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 4, 538U, 2);
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
            chartInstance->c1_tp_READY = 1U;
            c1_enter_atomic_READY(chartInstance);
          }
        }
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 35U,
                     chartInstance->c1_sfEvent);
        c1_i37 = c1__s32_minus__(chartInstance, (int32_T)
          chartInstance->c1_aacCounter, 1, 545U, 129, 1);
        c1_covSaturation = false;
        if (c1_i37 < 0) {
          c1_covSaturation = true;
          c1_i37 = 0;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 545U, 129U, 1U);
        } else {
          if (c1_i37 > 65535) {
            c1_i37 = 65535;
            _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 545U, 129U, 1U);
          }

          CV_SATURATION_EVAL(4, 35, 0, 0, c1_covSaturation);
        }

        chartInstance->c1_aacCounter = (uint16_T)c1_i37;
        c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 29, 550U, (void *)
          &chartInstance->c1_aacCounter);
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_aacCounter, 5U);
        c1_checkShift(chartInstance);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 35U, chartInstance->c1_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_RELEASING:
      CV_STATE_EVAL(34, 0, c1_IN_RELEASING);
      c1_RELEASING(chartInstance);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_RUNNING:
      CV_STATE_EVAL(34, 0, c1_IN_RUNNING);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 111U,
                   chartInstance->c1_sfEvent);
      c1_c_out = (CV_TRANSITION_EVAL(111U, (int32_T)_SFD_CCP_CALL(5U, 111U, 0,
        (boolean_T)CV_RELATIONAL_EVAL(5U, 111U, 0, (real_T)
        *chartInstance->c1_currentGear, 5.0, 0, 5U,
        *chartInstance->c1_currentGear >= 5) != 0U, chartInstance->c1_sfEvent))
                  != 0);
      if (c1_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 111U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_RUNNING = 0U;
        chartInstance->c1_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 5, 545U, (int32_T)
          (chartInstance->c1_is_ACTIVE == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 6, 544U, (int32_T)
          (chartInstance->c1_is_ACTIVE == 2));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 7, 514U, (int32_T)
          (chartInstance->c1_is_ACTIVE == 3));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 8, 543U, (int32_T)
          (chartInstance->c1_is_ACTIVE == 4));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 9, 547U, (int32_T)
          (chartInstance->c1_is_ACTIVE == 5));
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 37U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_ACTIVE = 0U;
        chartInstance->c1_is_ACC = c1_IN_NO_ACTIVE_CHILD;
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 4, 538U, (int32_T)
          (chartInstance->c1_is_ACC == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 10, 515U, (int32_T)
          (chartInstance->c1_is_ACC == 2));
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 4, 538U, 0);
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 4, 538U, (void *)
          &chartInstance->c1_is_ACTIVE);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
        if (chartInstance->c1_is_ACC == c1_IN_STOPPING) {
        } else {
          chartInstance->c1_is_ACC = c1_IN_STOPPING;
          c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 3, 434U, (void *)
            &chartInstance->c1_is_ACC);
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 4, 538U, (int32_T)
            (chartInstance->c1_is_ACC == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 10, 515U, (int32_T)
            (chartInstance->c1_is_ACC == 2));
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 17);
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 2, 820U, 7);
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 3, 434U, 6);
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 41U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_STOPPING = 1U;
          sf_call_output_fcn_call(chartInstance->S, 5, "Efi_unsetRPMLimiter", 0);
          c1_Clutch_setValue(chartInstance, 0U);
        }
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 37U,
                     chartInstance->c1_sfEvent);
        c1_aacCheckShift(chartInstance);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 37U, chartInstance->c1_sfEvent);
      if (chartInstance->c1_is_ACC != c1_IN_ACTIVE) {
      } else {
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, chartInstance->c1_sfEvent);
      }
      break;

     case c1_IN_START:
      CV_STATE_EVAL(34, 0, c1_IN_START);
      c1_START(chartInstance);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_START_RELEASE:
      CV_STATE_EVAL(34, 0, c1_IN_START_RELEASE);
      c1_START_RELEASE(chartInstance);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, chartInstance->c1_sfEvent);
      break;

     default:
      CV_STATE_EVAL(34, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c1_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 5, 545U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 6, 544U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 7, 514U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 8, 543U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 4));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 9, 547U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 5));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, chartInstance->c1_sfEvent);
      break;
    }
  }
}

static void c1_exit_internal_ACTIVE(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c1_is_ACTIVE) {
   case c1_IN_READY:
    CV_STATE_EVAL(34, 1, c1_IN_READY);
    chartInstance->c1_tp_READY = 0U;
    chartInstance->c1_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 5, 545U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 6, 544U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 7, 514U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 8, 543U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 4));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 9, 547U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 5));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_RELEASING:
    CV_STATE_EVAL(34, 1, c1_IN_RELEASING);
    chartInstance->c1_tp_RELEASING = 0U;
    chartInstance->c1_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 5, 545U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 6, 544U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 7, 514U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 8, 543U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 4));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 9, 547U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 5));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_RUNNING:
    CV_STATE_EVAL(34, 1, c1_IN_RUNNING);
    chartInstance->c1_tp_RUNNING = 0U;
    chartInstance->c1_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 5, 545U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 6, 544U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 7, 514U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 8, 543U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 4));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 9, 547U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 5));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 37U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_START:
    CV_STATE_EVAL(34, 1, c1_IN_START);
    chartInstance->c1_tp_START = 0U;
    chartInstance->c1_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 5, 545U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 6, 544U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 7, 514U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 8, 543U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 4));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 9, 547U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 5));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 38U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_START_RELEASE:
    CV_STATE_EVAL(34, 1, c1_IN_START_RELEASE);
    chartInstance->c1_tp_START_RELEASE = 0U;
    chartInstance->c1_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 5, 545U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 6, 544U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 7, 514U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 8, 543U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 4));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 9, 547U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 5));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(34, 1, 0);
    chartInstance->c1_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 5, 545U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 6, 544U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 7, 514U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 8, 543U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 4));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 9, 547U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 5));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
    break;
  }
}

static void c1_START(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  int32_T c1_i41;
  boolean_T c1_covSaturation;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 103U, chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(103U, (int32_T)_SFD_CCP_CALL(5U, 103U, 0,
              (boolean_T)CV_RELATIONAL_EVAL(5U, 103U, 0, (real_T)
    chartInstance->c1_aacCounter, 1.0, 0, 3U, chartInstance->c1_aacCounter <= 1)
              != 0U, chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 103U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_START = 0U;
    chartInstance->c1_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 5, 545U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 6, 544U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 7, 514U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 8, 543U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 4));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 9, 547U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 5));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 38U, chartInstance->c1_sfEvent);
    if (chartInstance->c1_is_ACTIVE == c1_IN_READY) {
    } else {
      chartInstance->c1_is_ACTIVE = c1_IN_READY;
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 4, 538U, (void *)
        &chartInstance->c1_is_ACTIVE);
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 5, 545U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 6, 544U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 7, 514U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 8, 543U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 4));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 9, 547U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 5));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 13);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 2, 820U, 3);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 3, 434U, 2);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 4, 538U, 2);
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_READY = 1U;
      c1_enter_atomic_READY(chartInstance);
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 38U, chartInstance->c1_sfEvent);
    c1_i41 = c1__s32_minus__(chartInstance, (int32_T)
      chartInstance->c1_aacCounter, 1, 543U, 155, 1);
    c1_covSaturation = false;
    if (c1_i41 < 0) {
      c1_covSaturation = true;
      c1_i41 = 0;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 543U, 155U, 1U);
    } else {
      if (c1_i41 > 65535) {
        c1_i41 = 65535;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 543U, 155U, 1U);
      }

      CV_SATURATION_EVAL(4, 38, 0, 0, c1_covSaturation);
    }

    chartInstance->c1_aacCounter = (uint16_T)c1_i41;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 29, 550U, (void *)
      &chartInstance->c1_aacCounter);
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_aacCounter, 5U);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 38U, chartInstance->c1_sfEvent);
}

static void c1_enter_atomic_READY(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  uint16_T c1_u2;
  *chartInstance->c1_stateFb = (uint16_T)ACC_READY;
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 10, 833U, (void *)
    chartInstance->c1_stateFb);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_stateFb, 32U);
  chartInstance->c1_aacCounter = c1_const_AAC_WORK_RATE_ms;
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 29, 550U, (void *)
    &chartInstance->c1_aacCounter);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_aacCounter, 5U);
  c1_u2 = chartInstance->c1_aacCounter;
  sf_mex_printf("%s =\\n", "aacCounter");
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11, c1_u2);
  c1_Clutch_setValue(chartInstance, 100U);
  c1_checkShift(chartInstance);
}

static void c1_START_RELEASE(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  int32_T c1_i42;
  boolean_T c1_covSaturation;
  real_T c1_d1;
  boolean_T c1_b_covSaturation;
  uint8_T c1_u3;
  int32_T c1_q0;
  int32_T c1_q1;
  boolean_T c1_c_covSaturation;
  int32_T c1_qY;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 102U, chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(102U, (int32_T)_SFD_CCP_CALL(5U, 102U, 0,
              (boolean_T)CV_RELATIONAL_EVAL(5U, 102U, 0, (real_T)
    chartInstance->c1_aacCounter, 1.0, 0, 3U, chartInstance->c1_aacCounter <= 1)
              != 0U, chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 102U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_START_RELEASE = 0U;
    chartInstance->c1_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 5, 545U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 6, 544U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 7, 514U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 8, 543U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 4));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 9, 547U, (int32_T)
      (chartInstance->c1_is_ACTIVE == 5));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
    if (chartInstance->c1_is_ACTIVE == c1_IN_RELEASING) {
    } else {
      chartInstance->c1_is_ACTIVE = c1_IN_RELEASING;
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 4, 538U, (void *)
        &chartInstance->c1_is_ACTIVE);
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 5, 545U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 6, 544U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 7, 514U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 8, 543U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 4));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 9, 547U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 5));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 15);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 2, 820U, 5);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 3, 434U, 4);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 4, 538U, 4);
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_RELEASING = 1U;
      chartInstance->c1_aac_clutchValue -= chartInstance->c1_aac_clutchStep;
      c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 30, 561U, (void *)
        &chartInstance->c1_aac_clutchValue);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_aac_clutchValue, 7U);
      c1_d1 = chartInstance->c1_aac_clutchValue;
      c1_b_covSaturation = false;
      if (c1_d1 < 256.0) {
        if (c1_d1 >= 0.0) {
          c1_u3 = (uint8_T)c1_d1;
        } else {
          c1_b_covSaturation = true;
          c1_u3 = 0U;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 544U, 87U, 5U);
        }
      } else if (c1_d1 >= 256.0) {
        c1_b_covSaturation = true;
        c1_u3 = MAX_uint8_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 544U, 87U, 5U);
      } else {
        c1_u3 = 0U;
      }

      CV_SATURATION_EVAL(4, 36, 2, 0, c1_b_covSaturation);
      c1_Clutch_setValue(chartInstance, c1_u3);
      c1_q0 = chartInstance->c1_aac_dtRelease;
      c1_q1 = 1;
      c1_c_covSaturation = false;
      if ((c1_q1 < 0) && (c1_q0 > c1_q1 + MAX_int32_T)) {
        c1_c_covSaturation = true;
        c1_qY = MAX_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 544U, 143U, 1U);
      } else if ((c1_q1 > 0) && (c1_q0 < c1_q1 + MIN_int32_T)) {
        c1_c_covSaturation = true;
        c1_qY = MIN_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 544U, 143U, 1U);
      } else {
        c1_qY = c1_q0 - c1_q1;
      }

      CV_SATURATION_EVAL(4, 36, 0, 0, c1_c_covSaturation);
      chartInstance->c1_aac_dtRelease = c1_qY;
      c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 32, 564U, (void *)
        &chartInstance->c1_aac_dtRelease);
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_aac_dtRelease, 8U);
      chartInstance->c1_aacCounter = c1_const_AAC_WORK_RATE_ms;
      c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 29, 550U, (void *)
        &chartInstance->c1_aacCounter);
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_aacCounter, 5U);
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 39U, chartInstance->c1_sfEvent);
    c1_i42 = c1__s32_minus__(chartInstance, (int32_T)
      chartInstance->c1_aacCounter, 1, 547U, 457, 1);
    c1_covSaturation = false;
    if (c1_i42 < 0) {
      c1_covSaturation = true;
      c1_i42 = 0;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 547U, 457U, 1U);
    } else {
      if (c1_i42 > 65535) {
        c1_i42 = 65535;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 547U, 457U, 1U);
      }

      CV_SATURATION_EVAL(4, 39, 3, 0, c1_covSaturation);
    }

    chartInstance->c1_aacCounter = (uint16_T)c1_i42;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 29, 550U, (void *)
      &chartInstance->c1_aacCounter);
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_aacCounter, 5U);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 39U, chartInstance->c1_sfEvent);
}

static void c1_RELEASING(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  int32_T c1_i43;
  boolean_T c1_covSaturation;
  boolean_T c1_temp;
  int32_T c1_i44;
  boolean_T c1_b_out;
  real_T c1_d2;
  boolean_T c1_b_covSaturation;
  uint16_T c1_u4;
  uint8_T c1_u5;
  int32_T c1_q0;
  int32_T c1_q1;
  boolean_T c1_c_covSaturation;
  int32_T c1_qY;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 104U, chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(104U, (int32_T)_SFD_CCP_CALL(5U, 104U, 0,
              (boolean_T)CV_RELATIONAL_EVAL(5U, 104U, 0, (real_T)
    chartInstance->c1_aacCounter, 1.0, 0, 3U, chartInstance->c1_aacCounter <= 1)
              != 0U, chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 104U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 110U,
                 chartInstance->c1_sfEvent);
    c1_temp = _SFD_CCP_CALL(5U, 110U, 0, (boolean_T)CV_RELATIONAL_EVAL(5U, 110U,
      0, (real_T)chartInstance->c1_aac_dtRelease, 0.0, 0, 3U,
      chartInstance->c1_aac_dtRelease <= 0) != 0U, chartInstance->c1_sfEvent);
    if (!c1_temp) {
      c1_i44 = c1_getAacParam(chartInstance, acc_params_RAMP_END);
      c1_temp = _SFD_CCP_CALL(5U, 110U, 1, (boolean_T)CV_RELATIONAL_EVAL(5U,
        110U, 1, (real_T)*chartInstance->c1_clutchCurrVal, (real_T)c1_i44, 0, 3U,
        *chartInstance->c1_clutchCurrVal <= c1_i44) != 0U,
        chartInstance->c1_sfEvent);
    }

    c1_b_out = (CV_TRANSITION_EVAL(110U, (int32_T)c1_temp) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 110U, chartInstance->c1_sfEvent);
      c1_Clutch_setValue(chartInstance, 0U);
      sf_call_output_fcn_call(chartInstance->S, 5, "Efi_unsetRPMLimiter", 0);
      chartInstance->c1_tp_RELEASING = 0U;
      chartInstance->c1_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 5, 545U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 6, 544U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 7, 514U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 8, 543U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 4));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 9, 547U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 5));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
      if (chartInstance->c1_is_ACTIVE == c1_IN_RUNNING) {
      } else {
        chartInstance->c1_is_ACTIVE = c1_IN_RUNNING;
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 4, 538U, (void *)
          &chartInstance->c1_is_ACTIVE);
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 5, 545U, (int32_T)
          (chartInstance->c1_is_ACTIVE == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 6, 544U, (int32_T)
          (chartInstance->c1_is_ACTIVE == 2));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 7, 514U, (int32_T)
          (chartInstance->c1_is_ACTIVE == 3));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 8, 543U, (int32_T)
          (chartInstance->c1_is_ACTIVE == 4));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 9, 547U, (int32_T)
          (chartInstance->c1_is_ACTIVE == 5));
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 16);
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 2, 820U, 6);
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 3, 434U, 5);
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 4, 538U, 5);
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 37U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_RUNNING = 1U;
        chartInstance->c1_aacCounter = c1_const_AAC_WORK_RATE_ms;
        c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 29, 550U, (void *)
          &chartInstance->c1_aacCounter);
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_aacCounter, 5U);
        c1_u4 = chartInstance->c1_aacCounter;
        sf_mex_printf("%s =\\n", "aacCounter");
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11, c1_u4);
        chartInstance->c1_lastShift = *chartInstance->c1_currentGear;
        c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 8, 715U, (void *)
          &chartInstance->c1_lastShift);
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastShift, 18U);
        c1_aacCheckShift(chartInstance);
      }
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 112U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_RELEASING = 0U;
      chartInstance->c1_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 5, 545U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 6, 544U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 7, 514U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 8, 543U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 4));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 9, 547U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 5));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
      if (chartInstance->c1_is_ACTIVE == c1_IN_RELEASING) {
      } else {
        chartInstance->c1_is_ACTIVE = c1_IN_RELEASING;
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 4, 538U, (void *)
          &chartInstance->c1_is_ACTIVE);
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 5, 545U, (int32_T)
          (chartInstance->c1_is_ACTIVE == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 6, 544U, (int32_T)
          (chartInstance->c1_is_ACTIVE == 2));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 7, 514U, (int32_T)
          (chartInstance->c1_is_ACTIVE == 3));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 8, 543U, (int32_T)
          (chartInstance->c1_is_ACTIVE == 4));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 9, 547U, (int32_T)
          (chartInstance->c1_is_ACTIVE == 5));
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 15);
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 2, 820U, 5);
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 3, 434U, 4);
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 4, 538U, 4);
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_RELEASING = 1U;
        chartInstance->c1_aac_clutchValue -= chartInstance->c1_aac_clutchStep;
        c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 30, 561U, (void *)
          &chartInstance->c1_aac_clutchValue);
        _SFD_DATA_RANGE_CHECK(chartInstance->c1_aac_clutchValue, 7U);
        c1_d2 = chartInstance->c1_aac_clutchValue;
        c1_b_covSaturation = false;
        if (c1_d2 < 256.0) {
          if (c1_d2 >= 0.0) {
            c1_u5 = (uint8_T)c1_d2;
          } else {
            c1_b_covSaturation = true;
            c1_u5 = 0U;
            _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 544U, 87U, 5U);
          }
        } else if (c1_d2 >= 256.0) {
          c1_b_covSaturation = true;
          c1_u5 = MAX_uint8_T;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 544U, 87U, 5U);
        } else {
          c1_u5 = 0U;
        }

        CV_SATURATION_EVAL(4, 36, 2, 0, c1_b_covSaturation);
        c1_Clutch_setValue(chartInstance, c1_u5);
        c1_q0 = chartInstance->c1_aac_dtRelease;
        c1_q1 = 1;
        c1_c_covSaturation = false;
        if ((c1_q1 < 0) && (c1_q0 > c1_q1 + MAX_int32_T)) {
          c1_c_covSaturation = true;
          c1_qY = MAX_int32_T;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 544U, 143U, 1U);
        } else if ((c1_q1 > 0) && (c1_q0 < c1_q1 + MIN_int32_T)) {
          c1_c_covSaturation = true;
          c1_qY = MIN_int32_T;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 544U, 143U, 1U);
        } else {
          c1_qY = c1_q0 - c1_q1;
        }

        CV_SATURATION_EVAL(4, 36, 0, 0, c1_c_covSaturation);
        chartInstance->c1_aac_dtRelease = c1_qY;
        c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 32, 564U, (void *)
          &chartInstance->c1_aac_dtRelease);
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_aac_dtRelease, 8U);
        chartInstance->c1_aacCounter = c1_const_AAC_WORK_RATE_ms;
        c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 29, 550U, (void *)
          &chartInstance->c1_aacCounter);
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_aacCounter, 5U);
      }
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 36U, chartInstance->c1_sfEvent);
    c1_i43 = c1__s32_minus__(chartInstance, (int32_T)
      chartInstance->c1_aacCounter, 1, 544U, 213, 1);
    c1_covSaturation = false;
    if (c1_i43 < 0) {
      c1_covSaturation = true;
      c1_i43 = 0;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 544U, 213U, 1U);
    } else {
      if (c1_i43 > 65535) {
        c1_i43 = 65535;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 544U, 213U, 1U);
      }

      CV_SATURATION_EVAL(4, 36, 1, 0, c1_covSaturation);
    }

    chartInstance->c1_aacCounter = (uint16_T)c1_i43;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 29, 550U, (void *)
      &chartInstance->c1_aacCounter);
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_aacCounter, 5U);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 36U, chartInstance->c1_sfEvent);
}

static void c1_DEFAULT(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  boolean_T c1_temp;
  boolean_T c1_out;
  uint16_T c1_u6;
  uint16_T c1_u7;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 121U, chartInstance->c1_sfEvent);
  c1_temp = _SFD_CCP_CALL(5U, 121U, 0, (boolean_T)CV_RELATIONAL_EVAL(5U, 121U, 0,
    (real_T)(*chartInstance->c1_aacCom)[0], (real_T)chartInstance->c1_lastAacCom,
    0, 1U, (*chartInstance->c1_aacCom)[0] != chartInstance->c1_lastAacCom) != 0U,
    chartInstance->c1_sfEvent);
  if (c1_temp) {
    c1_temp = _SFD_CCP_CALL(5U, 121U, 1, ((*chartInstance->c1_aacCom)[1] ==
      ACC_READY) != 0U, chartInstance->c1_sfEvent);
  }

  c1_out = (CV_TRANSITION_EVAL(121U, (int32_T)c1_temp) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 121U, chartInstance->c1_sfEvent);
    chartInstance->c1_lastAacCom = (*chartInstance->c1_aacCom)[0];
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 15, 627U, (void *)
      &chartInstance->c1_lastAacCom);
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastAacCom, 1U);
    c1_u6 = chartInstance->c1_lastAacCom;
    sf_mex_printf("%s =\\n", "lastAacCom");
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11, c1_u6);
    chartInstance->c1_tp_DEFAULT = 0U;
    chartInstance->c1_is_ACCELERATION = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 3, 434U, (int32_T)
      (chartInstance->c1_is_ACCELERATION == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 11, 821U, (int32_T)
      (chartInstance->c1_is_ACCELERATION == 2));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 43U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_ACCELERATION = c1_IN_ACC;
    c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 2, 820U, (void *)
      &chartInstance->c1_is_ACCELERATION);
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 3, 434U, (int32_T)
      (chartInstance->c1_is_ACCELERATION == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 11, 821U, (int32_T)
      (chartInstance->c1_is_ACCELERATION == 2));
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 33U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_ACC = 1U;
    chartInstance->c1_aacCounter = 0U;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 29, 550U, (void *)
      &chartInstance->c1_aacCounter);
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_aacCounter, 5U);
    chartInstance->c1_aac_clutchValue = 0.0;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 30, 561U, (void *)
      &chartInstance->c1_aac_clutchValue);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_aac_clutchValue, 7U);
    chartInstance->c1_aac_clutchStep = 0.0;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 31, 563U, (void *)
      &chartInstance->c1_aac_clutchStep);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_aac_clutchStep, 6U);
    chartInstance->c1_aac_dtRelease = 0;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 32, 564U, (void *)
      &chartInstance->c1_aac_dtRelease);
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_aac_dtRelease, 8U);
    chartInstance->c1_is_ACC = c1_IN_ACTIVE;
    c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 3, 434U, (void *)
      &chartInstance->c1_is_ACC);
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 4, 538U, (int32_T)
      (chartInstance->c1_is_ACC == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 10, 515U, (int32_T)
      (chartInstance->c1_is_ACC == 2));
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_ACTIVE = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 105U, chartInstance->c1_sfEvent);
    if (chartInstance->c1_is_ACTIVE == c1_IN_START) {
    } else {
      chartInstance->c1_is_ACTIVE = c1_IN_START;
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 4, 538U, (void *)
        &chartInstance->c1_is_ACTIVE);
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 5, 545U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 6, 544U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 7, 514U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 8, 543U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 4));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 9, 547U, (int32_T)
        (chartInstance->c1_is_ACTIVE == 5));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 12);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 2, 820U, 2);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 3, 434U, 1);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 4, 538U, 1);
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 38U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_START = 1U;
      *chartInstance->c1_stateFb = (uint16_T)ACC_READY;
      c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 10, 833U, (void *)
        chartInstance->c1_stateFb);
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_stateFb, 32U);
      chartInstance->c1_aacCounter = c1_const_AAC_WORK_RATE_ms;
      c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 29, 550U, (void *)
        &chartInstance->c1_aacCounter);
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_aacCounter, 5U);
      c1_u7 = chartInstance->c1_aacCounter;
      sf_mex_printf("%s =\\n", "aacCounter");
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11, c1_u7);
      sf_call_output_fcn_call(chartInstance->S, 4, "Efi_setRPMLimiter", 0);
      c1_Clutch_setValue(chartInstance, 100U);
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 43U, chartInstance->c1_sfEvent);
    *chartInstance->c1_stateFb = (uint16_T)ACC_OFF;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 10, 833U, (void *)
      chartInstance->c1_stateFb);
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_stateFb, 32U);
    c1_checkShift(chartInstance);
    c1_checkClutch(chartInstance);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 43U, chartInstance->c1_sfEvent);
}

static void c1_enter_internal_AUTOCROSS(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 153U, chartInstance->c1_sfEvent);
  if (chartInstance->c1_is_AUTOCROSS == c1_b_IN_DEFAULT) {
  } else {
    chartInstance->c1_is_AUTOCROSS = c1_b_IN_DEFAULT;
    c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 12, 951U, (void *)
      &chartInstance->c1_is_AUTOCROSS);
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 13, 952U, (int32_T)
      (chartInstance->c1_is_AUTOCROSS == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 14, 974U, (int32_T)
      (chartInstance->c1_is_AUTOCROSS == 2));
    c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 11);
    c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 12, 951U, 1);
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 45U, chartInstance->c1_sfEvent);
    chartInstance->c1_b_tp_DEFAULT = 1U;
    *chartInstance->c1_stateFb = (uint16_T)AUTOX_DEFAULT;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 10, 833U, (void *)
      chartInstance->c1_stateFb);
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_stateFb, 32U);
    c1_checkShift(chartInstance);
    c1_checkClutch(chartInstance);
  }
}

static void c1_AUTOCROSS(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  boolean_T c1_temp;
  boolean_T c1_out;
  boolean_T c1_b_out;
  boolean_T c1_c_out;
  boolean_T c1_d_out;
  boolean_T c1_e_out;
  int32_T c1_i45;
  int32_T c1_i46;
  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i50;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 182U, chartInstance->c1_sfEvent);
  c1_temp = _SFD_CCP_CALL(5U, 182U, 0, (boolean_T)CV_RELATIONAL_EVAL(5U, 182U, 0,
    (real_T)(*chartInstance->c1_modeCom)[0], (real_T)
    (*chartInstance->c1_lastModeCom)[0], 0, 1U, (*chartInstance->c1_modeCom)[0]
    != (*chartInstance->c1_lastModeCom)[0]) != 0U, chartInstance->c1_sfEvent);
  if (c1_temp) {
    c1_temp = _SFD_CCP_CALL(5U, 182U, 1, (boolean_T)CV_RELATIONAL_EVAL(5U, 182U,
      1, (real_T)(*chartInstance->c1_modeCom)[1], (real_T)
      (*chartInstance->c1_lastModeCom)[1], 0, 1U, (*chartInstance->c1_modeCom)[1]
      != (*chartInstance->c1_lastModeCom)[1]) != 0U, chartInstance->c1_sfEvent);
  }

  c1_out = (CV_TRANSITION_EVAL(182U, (int32_T)c1_temp) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 182U, chartInstance->c1_sfEvent);
    sf_call_output_fcn_call(chartInstance->S, 5, "Efi_unsetRPMLimiter", 0);
    *chartInstance->c1_stateFb = (uint16_T)ACC_OFF;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 10, 833U, (void *)
      chartInstance->c1_stateFb);
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_stateFb, 32U);
    c1_Clutch_setValue(chartInstance, 0U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 145U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 137U,
                 chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(137U, (int32_T)_SFD_CCP_CALL(5U, 137U, 0,
      ((*chartInstance->c1_modeCom)[1] == ENDURANCE_MODE) != 0U,
      chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 137U, chartInstance->c1_sfEvent);
      c1_exit_internal_AUTOCROSS(chartInstance);
      chartInstance->c1_tp_AUTOCROSS = 0U;
      chartInstance->c1_is_MODES = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
        (chartInstance->c1_is_MODES == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
        (chartInstance->c1_is_MODES == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
        (chartInstance->c1_is_MODES == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
        (chartInstance->c1_is_MODES == 4));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 12, 951U, 0);
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 12, 951U, (void *)
        &chartInstance->c1_is_AUTOCROSS);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 44U, chartInstance->c1_sfEvent);
      if (chartInstance->c1_is_MODES == c1_IN_MANUAL_MODES) {
      } else {
        chartInstance->c1_is_MODES = c1_IN_MANUAL_MODES;
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 1, 418U, (void *)
          &chartInstance->c1_is_MODES);
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
          (chartInstance->c1_is_MODES == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
          (chartInstance->c1_is_MODES == 2));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
          (chartInstance->c1_is_MODES == 3));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
          (chartInstance->c1_is_MODES == 4));
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 57U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_MANUAL_MODES = 1U;
        c1_enter_atomic_MANUAL_MODES(chartInstance);
      }

      chartInstance->c1_is_MANUAL_MODES = c1_IN_ENDURANCE;
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 23, 727U, (void *)
        &chartInstance->c1_is_MANUAL_MODES);
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 24, 729U, (int32_T)
        (chartInstance->c1_is_MANUAL_MODES == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 25, 728U, (int32_T)
        (chartInstance->c1_is_MANUAL_MODES == 2));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 2);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 23, 727U, 1);
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 58U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_ENDURANCE = 1U;
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 138U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 139U,
                   chartInstance->c1_sfEvent);
      c1_c_out = (CV_TRANSITION_EVAL(139U, (int32_T)_SFD_CCP_CALL(5U, 139U, 0,
        ((*chartInstance->c1_modeCom)[1] == SKIDPAD_MODE) != 0U,
        chartInstance->c1_sfEvent)) != 0);
      if (c1_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 139U, chartInstance->c1_sfEvent);
        c1_exit_internal_AUTOCROSS(chartInstance);
        chartInstance->c1_tp_AUTOCROSS = 0U;
        chartInstance->c1_is_MODES = c1_IN_NO_ACTIVE_CHILD;
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
          (chartInstance->c1_is_MODES == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
          (chartInstance->c1_is_MODES == 2));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
          (chartInstance->c1_is_MODES == 3));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
          (chartInstance->c1_is_MODES == 4));
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 12, 951U, 0);
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 12, 951U, (void *)
          &chartInstance->c1_is_AUTOCROSS);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 44U, chartInstance->c1_sfEvent);
        if (chartInstance->c1_is_MODES == c1_IN_MANUAL_MODES) {
        } else {
          chartInstance->c1_is_MODES = c1_IN_MANUAL_MODES;
          c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 1, 418U, (void *)
            &chartInstance->c1_is_MODES);
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
            (chartInstance->c1_is_MODES == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
            (chartInstance->c1_is_MODES == 2));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
            (chartInstance->c1_is_MODES == 3));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
            (chartInstance->c1_is_MODES == 4));
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 57U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_MANUAL_MODES = 1U;
          c1_enter_atomic_MANUAL_MODES(chartInstance);
        }

        chartInstance->c1_is_MANUAL_MODES = c1_IN_SKIDPAD;
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 23, 727U, (void *)
          &chartInstance->c1_is_MANUAL_MODES);
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 24, 729U, (int32_T)
          (chartInstance->c1_is_MANUAL_MODES == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 25, 728U, (int32_T)
          (chartInstance->c1_is_MANUAL_MODES == 2));
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 3);
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 23, 727U, 2);
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_SKIDPAD = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 140U, chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 141U,
                     chartInstance->c1_sfEvent);
        c1_d_out = (CV_TRANSITION_EVAL(141U, (int32_T)_SFD_CCP_CALL(5U, 141U, 0,
          ((*chartInstance->c1_modeCom)[1] == ACCELERATION_MODE) != 0U,
          chartInstance->c1_sfEvent)) != 0);
        if (c1_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 141U, chartInstance->c1_sfEvent);
          c1_exit_internal_AUTOCROSS(chartInstance);
          chartInstance->c1_tp_AUTOCROSS = 0U;
          chartInstance->c1_is_MODES = c1_IN_NO_ACTIVE_CHILD;
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
            (chartInstance->c1_is_MODES == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
            (chartInstance->c1_is_MODES == 2));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
            (chartInstance->c1_is_MODES == 3));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
            (chartInstance->c1_is_MODES == 4));
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 12, 951U, 0);
          c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 12, 951U, (void *)
            &chartInstance->c1_is_AUTOCROSS);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 44U, chartInstance->c1_sfEvent);
          if (chartInstance->c1_is_MODES == c1_IN_ACCELERATION) {
          } else {
            chartInstance->c1_is_MODES = c1_IN_ACCELERATION;
            c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 1, 418U, (void *)
              &chartInstance->c1_is_MODES);
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
              (chartInstance->c1_is_MODES == 1));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
              (chartInstance->c1_is_MODES == 2));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
              (chartInstance->c1_is_MODES == 3));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
              (chartInstance->c1_is_MODES == 4));
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
            chartInstance->c1_tp_ACCELERATION = 1U;
            chartInstance->c1_lastAacCom = (*chartInstance->c1_aacCom)[0];
            c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 15, 627U, (void *)
              &chartInstance->c1_lastAacCom);
            _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastAacCom, 1U);
            (*chartInstance->c1_lastModeCom)[0] = (*chartInstance->c1_modeCom)[0];
            c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
              chartInstance->c1_lastModeCom);
            for (c1_i45 = 0; c1_i45 < 2; c1_i45++) {
              _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)
                                    [c1_i45], 31U);
            }

            (*chartInstance->c1_lastModeCom)[1] = (*chartInstance->c1_modeCom)[1];
            c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
              chartInstance->c1_lastModeCom);
            for (c1_i48 = 0; c1_i48 < 2; c1_i48++) {
              _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)
                                    [c1_i48], 31U);
            }
          }

          c1_enter_internal_ACCELERATION(chartInstance);
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 179U, chartInstance->c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 180U,
                       chartInstance->c1_sfEvent);
          c1_e_out = (CV_TRANSITION_EVAL(180U, (int32_T)_SFD_CCP_CALL(5U, 180U,
            0, ((*chartInstance->c1_modeCom)[1] == AUTOX_MODE) != 0U,
            chartInstance->c1_sfEvent)) != 0);
          if (c1_e_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 180U, chartInstance->c1_sfEvent);
            c1_exit_internal_AUTOCROSS(chartInstance);
            chartInstance->c1_tp_AUTOCROSS = 0U;
            chartInstance->c1_is_MODES = c1_IN_NO_ACTIVE_CHILD;
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
              (chartInstance->c1_is_MODES == 1));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
              (chartInstance->c1_is_MODES == 2));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
              (chartInstance->c1_is_MODES == 3));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
              (chartInstance->c1_is_MODES == 4));
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 12, 951U, 0);
            c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 12, 951U, (void *)
              &chartInstance->c1_is_AUTOCROSS);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 44U, chartInstance->c1_sfEvent);
            if (chartInstance->c1_is_MODES == c1_IN_AUTOCROSS) {
            } else {
              chartInstance->c1_is_MODES = c1_IN_AUTOCROSS;
              c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 1, 418U, (void *)
                &chartInstance->c1_is_MODES);
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
                (chartInstance->c1_is_MODES == 1));
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
                (chartInstance->c1_is_MODES == 2));
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
                (chartInstance->c1_is_MODES == 3));
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
                (chartInstance->c1_is_MODES == 4));
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 44U, chartInstance->c1_sfEvent);
              chartInstance->c1_tp_AUTOCROSS = 1U;
              chartInstance->c1_lastAutoXCom = (*chartInstance->c1_autoXCom)[0];
              c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 18, 1043U, (void *)
                &chartInstance->c1_lastAutoXCom);
              _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastAutoXCom, 2U);
              (*chartInstance->c1_lastModeCom)[0] = (*chartInstance->c1_modeCom)
                [0];
              c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
                chartInstance->c1_lastModeCom);
              for (c1_i47 = 0; c1_i47 < 2; c1_i47++) {
                _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)
                                      [c1_i47], 31U);
              }

              (*chartInstance->c1_lastModeCom)[1] = (*chartInstance->c1_modeCom)
                [1];
              c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
                chartInstance->c1_lastModeCom);
              for (c1_i50 = 0; c1_i50 < 2; c1_i50++) {
                _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)
                                      [c1_i50], 31U);
              }
            }

            c1_enter_internal_AUTOCROSS(chartInstance);
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 181U, chartInstance->c1_sfEvent);
            c1_exit_internal_AUTOCROSS(chartInstance);
            chartInstance->c1_tp_AUTOCROSS = 0U;
            chartInstance->c1_is_MODES = c1_IN_NO_ACTIVE_CHILD;
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
              (chartInstance->c1_is_MODES == 1));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
              (chartInstance->c1_is_MODES == 2));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
              (chartInstance->c1_is_MODES == 3));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
              (chartInstance->c1_is_MODES == 4));
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 12, 951U, 0);
            c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 12, 951U, (void *)
              &chartInstance->c1_is_AUTOCROSS);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 44U, chartInstance->c1_sfEvent);
            if (chartInstance->c1_is_MODES == c1_IN_MANUAL_MODES) {
            } else {
              chartInstance->c1_is_MODES = c1_IN_MANUAL_MODES;
              c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 1, 418U, (void *)
                &chartInstance->c1_is_MODES);
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
                (chartInstance->c1_is_MODES == 1));
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
                (chartInstance->c1_is_MODES == 2));
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
                (chartInstance->c1_is_MODES == 3));
              c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
                (chartInstance->c1_is_MODES == 4));
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 57U, chartInstance->c1_sfEvent);
              chartInstance->c1_tp_MANUAL_MODES = 1U;
              (*chartInstance->c1_lastModeCom)[0] = (*chartInstance->c1_modeCom)
                [0];
              c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
                chartInstance->c1_lastModeCom);
              for (c1_i46 = 0; c1_i46 < 2; c1_i46++) {
                _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)
                                      [c1_i46], 31U);
              }

              (*chartInstance->c1_lastModeCom)[1] = (*chartInstance->c1_modeCom)
                [1];
              c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
                chartInstance->c1_lastModeCom);
              for (c1_i49 = 0; c1_i49 < 2; c1_i49++) {
                _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_lastModeCom)
                                      [c1_i49], 31U);
              }

              c1_checkShift(chartInstance);
              c1_checkClutch(chartInstance);
            }

            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 136U, chartInstance->c1_sfEvent);
            chartInstance->c1_is_MANUAL_MODES = c1_IN_ENDURANCE;
            c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 23, 727U, (void *)
              &chartInstance->c1_is_MANUAL_MODES);
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 24, 729U, (int32_T)
              (chartInstance->c1_is_MANUAL_MODES == 1));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 25, 728U, (int32_T)
              (chartInstance->c1_is_MANUAL_MODES == 2));
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 2);
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 23, 727U, 1);
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 58U, chartInstance->c1_sfEvent);
            chartInstance->c1_tp_ENDURANCE = 1U;
          }
        }
      }
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 44U, chartInstance->c1_sfEvent);
    switch (chartInstance->c1_is_AUTOCROSS) {
     case c1_b_IN_DEFAULT:
      CV_STATE_EVAL(44, 0, c1_b_IN_DEFAULT);
      c1_b_DEFAULT(chartInstance);
      break;

     case c1_IN_LAUNCH:
      CV_STATE_EVAL(44, 0, c1_IN_LAUNCH);
      c1_LAUNCH(chartInstance);
      break;

     default:
      CV_STATE_EVAL(44, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c1_is_AUTOCROSS = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 13, 952U, (int32_T)
        (chartInstance->c1_is_AUTOCROSS == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 14, 974U, (int32_T)
        (chartInstance->c1_is_AUTOCROSS == 2));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 45U, chartInstance->c1_sfEvent);
      break;
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 44U, chartInstance->c1_sfEvent);
}

static void c1_exit_internal_AUTOCROSS(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c1_is_AUTOCROSS) {
   case c1_b_IN_DEFAULT:
    CV_STATE_EVAL(44, 1, c1_b_IN_DEFAULT);
    chartInstance->c1_b_tp_DEFAULT = 0U;
    chartInstance->c1_is_AUTOCROSS = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 13, 952U, (int32_T)
      (chartInstance->c1_is_AUTOCROSS == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 14, 974U, (int32_T)
      (chartInstance->c1_is_AUTOCROSS == 2));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 45U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_LAUNCH:
    CV_STATE_EVAL(44, 1, c1_IN_LAUNCH);
    switch (chartInstance->c1_is_LAUNCH) {
     case c1_IN_ACTIVE:
      CV_STATE_EVAL(46, 1, c1_IN_ACTIVE);
      c1_b_exit_internal_ACTIVE(chartInstance);
      chartInstance->c1_b_tp_ACTIVE = 0U;
      chartInstance->c1_is_LAUNCH = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 15, 985U, (int32_T)
        (chartInstance->c1_is_LAUNCH == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 21, 1028U, (int32_T)
        (chartInstance->c1_is_LAUNCH == 2));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 15, 985U, 0);
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 15, 985U, (void *)
        &chartInstance->c1_b_is_ACTIVE);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 47U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_STOPPING:
      CV_STATE_EVAL(46, 1, c1_IN_STOPPING);
      chartInstance->c1_b_tp_STOPPING = 0U;
      chartInstance->c1_is_LAUNCH = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 15, 985U, (int32_T)
        (chartInstance->c1_is_LAUNCH == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 21, 1028U, (int32_T)
        (chartInstance->c1_is_LAUNCH == 2));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 54U, chartInstance->c1_sfEvent);
      break;

     default:
      CV_STATE_EVAL(46, 1, 0);
      chartInstance->c1_is_LAUNCH = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 15, 985U, (int32_T)
        (chartInstance->c1_is_LAUNCH == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 21, 1028U, (int32_T)
        (chartInstance->c1_is_LAUNCH == 2));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 47U, chartInstance->c1_sfEvent);
      break;
    }

    chartInstance->c1_tp_LAUNCH = 0U;
    chartInstance->c1_is_AUTOCROSS = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 13, 952U, (int32_T)
      (chartInstance->c1_is_AUTOCROSS == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 14, 974U, (int32_T)
      (chartInstance->c1_is_AUTOCROSS == 2));
    c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 14, 974U, 0);
    c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 14, 974U, (void *)
      &chartInstance->c1_is_LAUNCH);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 46U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(44, 1, 0);
    chartInstance->c1_is_AUTOCROSS = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 13, 952U, (int32_T)
      (chartInstance->c1_is_AUTOCROSS == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 14, 974U, (int32_T)
      (chartInstance->c1_is_AUTOCROSS == 2));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 45U, chartInstance->c1_sfEvent);
    break;
  }
}

static void c1_LAUNCH(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 46U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_LAUNCH) {
   case c1_IN_ACTIVE:
    CV_STATE_EVAL(46, 0, c1_IN_ACTIVE);
    c1_b_ACTIVE(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 46U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_STOPPING:
    CV_STATE_EVAL(46, 0, c1_IN_STOPPING);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 157U, chartInstance->c1_sfEvent);
    chartInstance->c1_b_tp_STOPPING = 0U;
    chartInstance->c1_is_LAUNCH = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 15, 985U, (int32_T)
      (chartInstance->c1_is_LAUNCH == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 21, 1028U, (int32_T)
      (chartInstance->c1_is_LAUNCH == 2));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 54U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_LAUNCH = 0U;
    chartInstance->c1_is_AUTOCROSS = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 13, 952U, (int32_T)
      (chartInstance->c1_is_AUTOCROSS == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 14, 974U, (int32_T)
      (chartInstance->c1_is_AUTOCROSS == 2));
    c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 14, 974U, 0);
    c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 14, 974U, (void *)
      &chartInstance->c1_is_LAUNCH);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 46U, chartInstance->c1_sfEvent);
    if (chartInstance->c1_is_AUTOCROSS == c1_b_IN_DEFAULT) {
    } else {
      chartInstance->c1_is_AUTOCROSS = c1_b_IN_DEFAULT;
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 12, 951U, (void *)
        &chartInstance->c1_is_AUTOCROSS);
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 13, 952U, (int32_T)
        (chartInstance->c1_is_AUTOCROSS == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 14, 974U, (int32_T)
        (chartInstance->c1_is_AUTOCROSS == 2));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 11);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 12, 951U, 1);
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 45U, chartInstance->c1_sfEvent);
      chartInstance->c1_b_tp_DEFAULT = 1U;
      *chartInstance->c1_stateFb = (uint16_T)AUTOX_DEFAULT;
      c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 10, 833U, (void *)
        chartInstance->c1_stateFb);
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_stateFb, 32U);
      c1_checkShift(chartInstance);
      c1_checkClutch(chartInstance);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 54U, chartInstance->c1_sfEvent);
    if (chartInstance->c1_is_AUTOCROSS != c1_IN_LAUNCH) {
    } else {
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 46U, chartInstance->c1_sfEvent);
    }
    break;

   default:
    CV_STATE_EVAL(46, 0, 0);

    /* Unreachable state, for coverage only */
    chartInstance->c1_is_LAUNCH = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 15, 985U, (int32_T)
      (chartInstance->c1_is_LAUNCH == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 21, 1028U, (int32_T)
      (chartInstance->c1_is_LAUNCH == 2));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 47U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 46U, chartInstance->c1_sfEvent);
    break;
  }
}

static void c1_b_ACTIVE(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  boolean_T c1_temp;
  boolean_T c1_out;
  boolean_T c1_b_out;
  boolean_T c1_c_out;
  uint16_T c1_u8;
  int32_T c1_i51;
  boolean_T c1_covSaturation;
  boolean_T c1_b_temp;
  boolean_T c1_c_temp;
  int32_T c1_i52;
  boolean_T c1_d_out;
  int32_T c1_i53;
  real_T c1_d3;
  boolean_T c1_b_covSaturation;
  uint8_T c1_u9;
  int32_T c1_q0;
  int32_T c1_q1;
  boolean_T c1_c_covSaturation;
  int32_T c1_qY;
  int64_T c1_i54;
  boolean_T c1_d_covSaturation;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 155U, chartInstance->c1_sfEvent);
  c1_temp = _SFD_CCP_CALL(5U, 155U, 0, (boolean_T)CV_RELATIONAL_EVAL(5U, 155U, 0,
    (real_T)(*chartInstance->c1_aacCom)[0], (real_T)chartInstance->c1_lastAacCom,
    0, 1U, (*chartInstance->c1_aacCom)[0] != chartInstance->c1_lastAacCom) != 0U,
    chartInstance->c1_sfEvent);
  if (c1_temp) {
    c1_temp = _SFD_CCP_CALL(5U, 155U, 1, ((*chartInstance->c1_aacCom)[1] ==
      ACC_OFF) != 0U, chartInstance->c1_sfEvent);
  }

  c1_out = (CV_TRANSITION_EVAL(155U, (int32_T)c1_temp) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 155U, chartInstance->c1_sfEvent);
    chartInstance->c1_lastAacCom = (*chartInstance->c1_aacCom)[0];
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 15, 627U, (void *)
      &chartInstance->c1_lastAacCom);
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastAacCom, 1U);
    c1_u8 = chartInstance->c1_lastAacCom;
    sf_mex_printf("%s =\\n", "lastAacCom");
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11, c1_u8);
    c1_b_exit_internal_ACTIVE(chartInstance);
    chartInstance->c1_b_tp_ACTIVE = 0U;
    chartInstance->c1_is_LAUNCH = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 15, 985U, (int32_T)
      (chartInstance->c1_is_LAUNCH == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 21, 1028U, (int32_T)
      (chartInstance->c1_is_LAUNCH == 2));
    c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 15, 985U, 0);
    c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 15, 985U, (void *)
      &chartInstance->c1_b_is_ACTIVE);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 47U, chartInstance->c1_sfEvent);
    if (chartInstance->c1_is_LAUNCH == c1_IN_STOPPING) {
    } else {
      chartInstance->c1_is_LAUNCH = c1_IN_STOPPING;
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 14, 974U, (void *)
        &chartInstance->c1_is_LAUNCH);
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 15, 985U, (int32_T)
        (chartInstance->c1_is_LAUNCH == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 21, 1028U, (int32_T)
        (chartInstance->c1_is_LAUNCH == 2));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 17);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 12, 951U, 7);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 14, 974U, 6);
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 54U, chartInstance->c1_sfEvent);
      chartInstance->c1_b_tp_STOPPING = 1U;
      sf_call_output_fcn_call(chartInstance->S, 5, "Efi_unsetRPMLimiter", 0);
      c1_Clutch_setValue(chartInstance, 0U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 47U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 47U, chartInstance->c1_sfEvent);
    switch (chartInstance->c1_b_is_ACTIVE) {
     case c1_IN_READY:
      CV_STATE_EVAL(47, 0, c1_IN_READY);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 161U,
                   chartInstance->c1_sfEvent);
      c1_b_out = (CV_TRANSITION_EVAL(161U, (int32_T)_SFD_CCP_CALL(5U, 161U, 0,
        (boolean_T)CV_RELATIONAL_EVAL(5U, 161U, 0, (real_T)
        chartInstance->c1_autoXCounter, 1.0, 0, 3U,
        chartInstance->c1_autoXCounter <= 1) != 0U, chartInstance->c1_sfEvent))
                  != 0);
      if (c1_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 161U, chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 162U,
                     chartInstance->c1_sfEvent);
        c1_b_temp = _SFD_CCP_CALL(5U, 162U, 0, (boolean_T)CV_RELATIONAL_EVAL(5U,
          162U, 0, (real_T)(*chartInstance->c1_autoXCom)[0], (real_T)
          chartInstance->c1_lastAutoXCom, 0, 1U, (*chartInstance->c1_autoXCom)[0]
          != chartInstance->c1_lastAutoXCom) != 0U, chartInstance->c1_sfEvent);
        if (c1_b_temp) {
          c1_b_temp = _SFD_CCP_CALL(5U, 162U, 1, ((*chartInstance->c1_autoXCom)
            [1] == AUTOX_GO) != 0U, chartInstance->c1_sfEvent);
        }

        c1_c_temp = c1_b_temp;
        if (c1_c_temp) {
          c1_i52 = (*chartInstance->c1_acc_externValues)[sf_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 992U, 59, 16, 23U,
             (int32_T)acc_values_TPS, 0, 2)];
          c1_i53 = c1_getAutoXParam(chartInstance,
            autoX_params_AUTOX_TPS_START_LIMIT);
          c1_c_temp = _SFD_CCP_CALL(5U, 162U, 2, (boolean_T)CV_RELATIONAL_EVAL
            (5U, 162U, 1, (real_T)c1_i52, (real_T)c1_i53, 0, 5U, c1_i52 >=
             c1_i53) != 0U, chartInstance->c1_sfEvent);
        }

        c1_d_out = (CV_TRANSITION_EVAL(162U, (int32_T)c1_c_temp) != 0);
        if (c1_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 162U, chartInstance->c1_sfEvent);
          chartInstance->c1_lastAutoXCom = (*chartInstance->c1_autoXCom)[0];
          c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 18, 1043U, (void *)
            &chartInstance->c1_lastAutoXCom);
          _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastAutoXCom, 2U);
          chartInstance->c1_b_tp_READY = 0U;
          chartInstance->c1_b_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 16, 999U, (int32_T)
            (chartInstance->c1_b_is_ACTIVE == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 17, 1025U, (int32_T)
            (chartInstance->c1_b_is_ACTIVE == 2));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 18, 1002U, (int32_T)
            (chartInstance->c1_b_is_ACTIVE == 3));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 19, 998U, (int32_T)
            (chartInstance->c1_b_is_ACTIVE == 4));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 20, 1001U, (int32_T)
            (chartInstance->c1_b_is_ACTIVE == 5));
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 48U, chartInstance->c1_sfEvent);
          if (chartInstance->c1_b_is_ACTIVE == c1_IN_START_RELEASE) {
          } else {
            chartInstance->c1_b_is_ACTIVE = c1_IN_START_RELEASE;
            c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 15, 985U, (void *)
              &chartInstance->c1_b_is_ACTIVE);
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 16, 999U, (int32_T)
              (chartInstance->c1_b_is_ACTIVE == 1));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 17, 1025U, (int32_T)
              (chartInstance->c1_b_is_ACTIVE == 2));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 18, 1002U, (int32_T)
              (chartInstance->c1_b_is_ACTIVE == 3));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 19, 998U, (int32_T)
              (chartInstance->c1_b_is_ACTIVE == 4));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 20, 1001U, (int32_T)
              (chartInstance->c1_b_is_ACTIVE == 5));
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 14);
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 12, 951U, 4);
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 14, 974U, 3);
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 15, 985U, 3);
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 52U, chartInstance->c1_sfEvent);
            chartInstance->c1_b_tp_START_RELEASE = 1U;
            *chartInstance->c1_stateFb = (uint16_T)AUTOX_GO;
            c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 10, 833U, (void *)
              chartInstance->c1_stateFb);
            _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_stateFb, 32U);
            chartInstance->c1_autoX_clutchValue = (real_T)c1_getAutoXParam
              (chartInstance, autoX_params_AUTOX_RAMP_START);
            c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 49, 959U, (void *)
              &chartInstance->c1_autoX_clutchValue);
            _SFD_DATA_RANGE_CHECK(chartInstance->c1_autoX_clutchValue, 11U);
            c1_d3 = chartInstance->c1_autoX_clutchValue;
            c1_b_covSaturation = false;
            if (c1_d3 < 256.0) {
              if (c1_d3 >= 0.0) {
                c1_u9 = (uint8_T)c1_d3;
              } else {
                c1_b_covSaturation = true;
                c1_u9 = 0U;
                _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1001U, 121U, 5U);
              }
            } else if (c1_d3 >= 256.0) {
              c1_b_covSaturation = true;
              c1_u9 = MAX_uint8_T;
              _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1001U, 121U, 5U);
            } else {
              c1_u9 = 0U;
            }

            CV_SATURATION_EVAL(4, 52, 0, 0, c1_b_covSaturation);
            c1_Clutch_setValue(chartInstance, c1_u9);
            chartInstance->c1_autoX_dtRelease = c1_div_nzp_s32(chartInstance,
              c1_getAutoXParam(chartInstance, autoX_params_AUTOX_RAMP_TIME),
              (int32_T)c1_const_AUTOX_WORK_RATE_ms, 1001U, 198, 1);
            c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 51, 961U, (void *)
              &chartInstance->c1_autoX_dtRelease);
            _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_autoX_dtRelease, 12U);
            c1_q0 = c1_getAutoXParam(chartInstance,
              autoX_params_AUTOX_RAMP_START);
            c1_q1 = c1_getAutoXParam(chartInstance, autoX_params_AUTOX_RAMP_END);
            c1_c_covSaturation = false;
            if ((c1_q0 >= 0) && (c1_q1 < c1_q0 - MAX_int32_T)) {
              c1_c_covSaturation = true;
              c1_qY = MAX_int32_T;
              _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1001U, 287U, 1U);
            } else if ((c1_q0 < 0) && (c1_q1 > c1_q0 - MIN_int32_T)) {
              c1_c_covSaturation = true;
              c1_qY = MIN_int32_T;
              _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1001U, 287U, 1U);
            } else {
              c1_qY = c1_q0 - c1_q1;
            }

            CV_SATURATION_EVAL(4, 52, 1, 0, c1_c_covSaturation);
            c1_i54 = (int64_T)c1_qY * (int64_T)c1_const_AUTOX_WORK_RATE_ms;
            c1_d_covSaturation = false;
            if (c1_i54 > 2147483647LL) {
              c1_d_covSaturation = true;
              c1_i54 = 2147483647LL;
              _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1001U, 320U, 1U);
            } else {
              if (c1_i54 < -2147483648LL) {
                c1_d_covSaturation = true;
                c1_i54 = -2147483648LL;
                _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1001U, 320U, 1U);
              }
            }

            CV_SATURATION_EVAL(4, 52, 2, 0, c1_d_covSaturation);
            chartInstance->c1_autoX_clutchStep = (real_T)(int32_T)c1_i54 /
              (real_T)c1_getAutoXParam(chartInstance,
              autoX_params_AUTOX_RAMP_TIME);
            c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 50, 960U, (void *)
              &chartInstance->c1_autoX_clutchStep);
            _SFD_DATA_RANGE_CHECK(chartInstance->c1_autoX_clutchStep, 10U);
            chartInstance->c1_autoXCounter = c1_const_AUTOX_WORK_RATE_ms;
            c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 48, 958U, (void *)
              &chartInstance->c1_autoXCounter);
            _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_autoXCounter, 9U);
          }
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 159U, chartInstance->c1_sfEvent);
          chartInstance->c1_b_tp_READY = 0U;
          chartInstance->c1_b_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 16, 999U, (int32_T)
            (chartInstance->c1_b_is_ACTIVE == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 17, 1025U, (int32_T)
            (chartInstance->c1_b_is_ACTIVE == 2));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 18, 1002U, (int32_T)
            (chartInstance->c1_b_is_ACTIVE == 3));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 19, 998U, (int32_T)
            (chartInstance->c1_b_is_ACTIVE == 4));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 20, 1001U, (int32_T)
            (chartInstance->c1_b_is_ACTIVE == 5));
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 48U, chartInstance->c1_sfEvent);
          if (chartInstance->c1_b_is_ACTIVE == c1_IN_READY) {
          } else {
            chartInstance->c1_b_is_ACTIVE = c1_IN_READY;
            c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 15, 985U, (void *)
              &chartInstance->c1_b_is_ACTIVE);
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 16, 999U, (int32_T)
              (chartInstance->c1_b_is_ACTIVE == 1));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 17, 1025U, (int32_T)
              (chartInstance->c1_b_is_ACTIVE == 2));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 18, 1002U, (int32_T)
              (chartInstance->c1_b_is_ACTIVE == 3));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 19, 998U, (int32_T)
              (chartInstance->c1_b_is_ACTIVE == 4));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 20, 1001U, (int32_T)
              (chartInstance->c1_b_is_ACTIVE == 5));
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 13);
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 12, 951U, 3);
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 14, 974U, 2);
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 15, 985U, 2);
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 48U, chartInstance->c1_sfEvent);
            chartInstance->c1_b_tp_READY = 1U;
            c1_b_enter_atomic_READY(chartInstance);
          }
        }
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 48U,
                     chartInstance->c1_sfEvent);
        c1_i51 = c1__s32_minus__(chartInstance, (int32_T)
          chartInstance->c1_autoXCounter, 1, 999U, 139, 1);
        c1_covSaturation = false;
        if (c1_i51 < 0) {
          c1_covSaturation = true;
          c1_i51 = 0;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 999U, 139U, 1U);
        } else {
          if (c1_i51 > 65535) {
            c1_i51 = 65535;
            _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 999U, 139U, 1U);
          }

          CV_SATURATION_EVAL(4, 48, 0, 0, c1_covSaturation);
        }

        chartInstance->c1_autoXCounter = (uint16_T)c1_i51;
        c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 48, 958U, (void *)
          &chartInstance->c1_autoXCounter);
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_autoXCounter, 9U);
        c1_checkShift(chartInstance);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 48U, chartInstance->c1_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 47U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_RELEASING:
      CV_STATE_EVAL(47, 0, c1_IN_RELEASING);
      c1_b_RELEASING(chartInstance);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 47U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_RUNNING:
      CV_STATE_EVAL(47, 0, c1_IN_RUNNING);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 156U,
                   chartInstance->c1_sfEvent);
      c1_c_out = (CV_TRANSITION_EVAL(156U, (int32_T)_SFD_CCP_CALL(5U, 156U, 0,
        (boolean_T)CV_RELATIONAL_EVAL(5U, 156U, 0, (real_T)
        *chartInstance->c1_currentGear, 5.0, 0, 5U,
        *chartInstance->c1_currentGear >= 5) != 0U, chartInstance->c1_sfEvent))
                  != 0);
      if (c1_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 156U, chartInstance->c1_sfEvent);
        chartInstance->c1_b_tp_RUNNING = 0U;
        chartInstance->c1_b_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 16, 999U, (int32_T)
          (chartInstance->c1_b_is_ACTIVE == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 17, 1025U, (int32_T)
          (chartInstance->c1_b_is_ACTIVE == 2));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 18, 1002U, (int32_T)
          (chartInstance->c1_b_is_ACTIVE == 3));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 19, 998U, (int32_T)
          (chartInstance->c1_b_is_ACTIVE == 4));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 20, 1001U, (int32_T)
          (chartInstance->c1_b_is_ACTIVE == 5));
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 50U, chartInstance->c1_sfEvent);
        chartInstance->c1_b_tp_ACTIVE = 0U;
        chartInstance->c1_is_LAUNCH = c1_IN_NO_ACTIVE_CHILD;
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 15, 985U, (int32_T)
          (chartInstance->c1_is_LAUNCH == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 21, 1028U, (int32_T)
          (chartInstance->c1_is_LAUNCH == 2));
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 15, 985U, 0);
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 15, 985U, (void *)
          &chartInstance->c1_b_is_ACTIVE);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 47U, chartInstance->c1_sfEvent);
        if (chartInstance->c1_is_LAUNCH == c1_IN_STOPPING) {
        } else {
          chartInstance->c1_is_LAUNCH = c1_IN_STOPPING;
          c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 14, 974U, (void *)
            &chartInstance->c1_is_LAUNCH);
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 15, 985U, (int32_T)
            (chartInstance->c1_is_LAUNCH == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 21, 1028U, (int32_T)
            (chartInstance->c1_is_LAUNCH == 2));
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 17);
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 12, 951U, 7);
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 14, 974U, 6);
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 54U, chartInstance->c1_sfEvent);
          chartInstance->c1_b_tp_STOPPING = 1U;
          sf_call_output_fcn_call(chartInstance->S, 5, "Efi_unsetRPMLimiter", 0);
          c1_Clutch_setValue(chartInstance, 0U);
        }
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 50U,
                     chartInstance->c1_sfEvent);
        c1_autoXCheckShift(chartInstance);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 50U, chartInstance->c1_sfEvent);
      if (chartInstance->c1_is_LAUNCH != c1_IN_ACTIVE) {
      } else {
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 47U, chartInstance->c1_sfEvent);
      }
      break;

     case c1_IN_START:
      CV_STATE_EVAL(47, 0, c1_IN_START);
      c1_b_START(chartInstance);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 47U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_START_RELEASE:
      CV_STATE_EVAL(47, 0, c1_IN_START_RELEASE);
      c1_b_START_RELEASE(chartInstance);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 47U, chartInstance->c1_sfEvent);
      break;

     default:
      CV_STATE_EVAL(47, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c1_b_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 16, 999U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 17, 1025U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 18, 1002U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 19, 998U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 4));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 20, 1001U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 5));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 48U, chartInstance->c1_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 47U, chartInstance->c1_sfEvent);
      break;
    }
  }
}

static void c1_b_exit_internal_ACTIVE(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c1_b_is_ACTIVE) {
   case c1_IN_READY:
    CV_STATE_EVAL(47, 1, c1_IN_READY);
    chartInstance->c1_b_tp_READY = 0U;
    chartInstance->c1_b_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 16, 999U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 17, 1025U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 18, 1002U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 19, 998U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 4));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 20, 1001U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 5));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 48U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_RELEASING:
    CV_STATE_EVAL(47, 1, c1_IN_RELEASING);
    chartInstance->c1_b_tp_RELEASING = 0U;
    chartInstance->c1_b_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 16, 999U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 17, 1025U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 18, 1002U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 19, 998U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 4));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 20, 1001U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 5));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 49U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_RUNNING:
    CV_STATE_EVAL(47, 1, c1_IN_RUNNING);
    chartInstance->c1_b_tp_RUNNING = 0U;
    chartInstance->c1_b_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 16, 999U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 17, 1025U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 18, 1002U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 19, 998U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 4));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 20, 1001U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 5));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 50U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_START:
    CV_STATE_EVAL(47, 1, c1_IN_START);
    chartInstance->c1_b_tp_START = 0U;
    chartInstance->c1_b_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 16, 999U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 17, 1025U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 18, 1002U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 19, 998U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 4));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 20, 1001U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 5));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 51U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_START_RELEASE:
    CV_STATE_EVAL(47, 1, c1_IN_START_RELEASE);
    chartInstance->c1_b_tp_START_RELEASE = 0U;
    chartInstance->c1_b_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 16, 999U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 17, 1025U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 18, 1002U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 19, 998U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 4));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 20, 1001U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 5));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 52U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(47, 1, 0);
    chartInstance->c1_b_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 16, 999U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 17, 1025U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 18, 1002U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 19, 998U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 4));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 20, 1001U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 5));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 48U, chartInstance->c1_sfEvent);
    break;
  }
}

static void c1_b_START(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  int32_T c1_i55;
  boolean_T c1_covSaturation;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 160U, chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(160U, (int32_T)_SFD_CCP_CALL(5U, 160U, 0,
              (boolean_T)CV_RELATIONAL_EVAL(5U, 160U, 0, (real_T)
    chartInstance->c1_autoXCounter, 1.0, 0, 3U, chartInstance->c1_autoXCounter <=
    1) != 0U, chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 160U, chartInstance->c1_sfEvent);
    chartInstance->c1_b_tp_START = 0U;
    chartInstance->c1_b_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 16, 999U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 17, 1025U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 18, 1002U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 19, 998U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 4));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 20, 1001U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 5));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 51U, chartInstance->c1_sfEvent);
    if (chartInstance->c1_b_is_ACTIVE == c1_IN_READY) {
    } else {
      chartInstance->c1_b_is_ACTIVE = c1_IN_READY;
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 15, 985U, (void *)
        &chartInstance->c1_b_is_ACTIVE);
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 16, 999U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 17, 1025U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 18, 1002U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 19, 998U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 4));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 20, 1001U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 5));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 13);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 12, 951U, 3);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 14, 974U, 2);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 15, 985U, 2);
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 48U, chartInstance->c1_sfEvent);
      chartInstance->c1_b_tp_READY = 1U;
      c1_b_enter_atomic_READY(chartInstance);
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 51U, chartInstance->c1_sfEvent);
    c1_i55 = c1__s32_minus__(chartInstance, (int32_T)
      chartInstance->c1_autoXCounter, 1, 998U, 165, 1);
    c1_covSaturation = false;
    if (c1_i55 < 0) {
      c1_covSaturation = true;
      c1_i55 = 0;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 998U, 165U, 1U);
    } else {
      if (c1_i55 > 65535) {
        c1_i55 = 65535;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 998U, 165U, 1U);
      }

      CV_SATURATION_EVAL(4, 51, 0, 0, c1_covSaturation);
    }

    chartInstance->c1_autoXCounter = (uint16_T)c1_i55;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 48, 958U, (void *)
      &chartInstance->c1_autoXCounter);
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_autoXCounter, 9U);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 51U, chartInstance->c1_sfEvent);
}

static void c1_b_enter_atomic_READY(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  uint16_T c1_u10;
  *chartInstance->c1_stateFb = (uint16_T)AUTOX_READY;
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 10, 833U, (void *)
    chartInstance->c1_stateFb);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_stateFb, 32U);
  chartInstance->c1_autoXCounter = c1_const_AUTOX_WORK_RATE_ms;
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 48, 958U, (void *)
    &chartInstance->c1_autoXCounter);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_autoXCounter, 9U);
  c1_u10 = chartInstance->c1_autoXCounter;
  sf_mex_printf("%s =\\n", "autoXCounter");
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11, c1_u10);
  c1_Clutch_setValue(chartInstance, 100U);
  c1_checkShift(chartInstance);
}

static void c1_b_START_RELEASE(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  int32_T c1_i56;
  boolean_T c1_covSaturation;
  real_T c1_d4;
  boolean_T c1_b_covSaturation;
  uint8_T c1_u11;
  int32_T c1_q0;
  int32_T c1_q1;
  boolean_T c1_c_covSaturation;
  int32_T c1_qY;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 163U, chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(163U, (int32_T)_SFD_CCP_CALL(5U, 163U, 0,
              (boolean_T)CV_RELATIONAL_EVAL(5U, 163U, 0, (real_T)
    chartInstance->c1_autoXCounter, 1.0, 0, 3U, chartInstance->c1_autoXCounter <=
    1) != 0U, chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 163U, chartInstance->c1_sfEvent);
    chartInstance->c1_b_tp_START_RELEASE = 0U;
    chartInstance->c1_b_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 16, 999U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 17, 1025U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 18, 1002U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 19, 998U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 4));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 20, 1001U, (int32_T)
      (chartInstance->c1_b_is_ACTIVE == 5));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 52U, chartInstance->c1_sfEvent);
    if (chartInstance->c1_b_is_ACTIVE == c1_IN_RELEASING) {
    } else {
      chartInstance->c1_b_is_ACTIVE = c1_IN_RELEASING;
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 15, 985U, (void *)
        &chartInstance->c1_b_is_ACTIVE);
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 16, 999U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 17, 1025U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 18, 1002U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 19, 998U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 4));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 20, 1001U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 5));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 15);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 12, 951U, 5);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 14, 974U, 4);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 15, 985U, 4);
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 49U, chartInstance->c1_sfEvent);
      chartInstance->c1_b_tp_RELEASING = 1U;
      chartInstance->c1_autoX_clutchValue -= chartInstance->c1_autoX_clutchStep;
      c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 49, 959U, (void *)
        &chartInstance->c1_autoX_clutchValue);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_autoX_clutchValue, 11U);
      c1_d4 = chartInstance->c1_autoX_clutchValue;
      c1_b_covSaturation = false;
      if (c1_d4 < 256.0) {
        if (c1_d4 >= 0.0) {
          c1_u11 = (uint8_T)c1_d4;
        } else {
          c1_b_covSaturation = true;
          c1_u11 = 0U;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1025U, 93U, 5U);
        }
      } else if (c1_d4 >= 256.0) {
        c1_b_covSaturation = true;
        c1_u11 = MAX_uint8_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1025U, 93U, 5U);
      } else {
        c1_u11 = 0U;
      }

      CV_SATURATION_EVAL(4, 49, 2, 0, c1_b_covSaturation);
      c1_Clutch_setValue(chartInstance, c1_u11);
      c1_q0 = chartInstance->c1_autoX_dtRelease;
      c1_q1 = 1;
      c1_c_covSaturation = false;
      if ((c1_q1 < 0) && (c1_q0 > c1_q1 + MAX_int32_T)) {
        c1_c_covSaturation = true;
        c1_qY = MAX_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1025U, 155U, 1U);
      } else if ((c1_q1 > 0) && (c1_q0 < c1_q1 + MIN_int32_T)) {
        c1_c_covSaturation = true;
        c1_qY = MIN_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1025U, 155U, 1U);
      } else {
        c1_qY = c1_q0 - c1_q1;
      }

      CV_SATURATION_EVAL(4, 49, 0, 0, c1_c_covSaturation);
      chartInstance->c1_autoX_dtRelease = c1_qY;
      c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 51, 961U, (void *)
        &chartInstance->c1_autoX_dtRelease);
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_autoX_dtRelease, 12U);
      chartInstance->c1_autoXCounter = c1_const_AUTOX_WORK_RATE_ms;
      c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 48, 958U, (void *)
        &chartInstance->c1_autoXCounter);
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_autoXCounter, 9U);
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 52U, chartInstance->c1_sfEvent);
    c1_i56 = c1__s32_minus__(chartInstance, (int32_T)
      chartInstance->c1_autoXCounter, 1, 1001U, 464, 1);
    c1_covSaturation = false;
    if (c1_i56 < 0) {
      c1_covSaturation = true;
      c1_i56 = 0;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1001U, 464U, 1U);
    } else {
      if (c1_i56 > 65535) {
        c1_i56 = 65535;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1001U, 464U, 1U);
      }

      CV_SATURATION_EVAL(4, 52, 3, 0, c1_covSaturation);
    }

    chartInstance->c1_autoXCounter = (uint16_T)c1_i56;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 48, 958U, (void *)
      &chartInstance->c1_autoXCounter);
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_autoXCounter, 9U);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 52U, chartInstance->c1_sfEvent);
}

static void c1_b_RELEASING(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  int32_T c1_i57;
  boolean_T c1_covSaturation;
  boolean_T c1_temp;
  int32_T c1_i58;
  boolean_T c1_b_out;
  real_T c1_d5;
  boolean_T c1_b_covSaturation;
  uint16_T c1_u12;
  uint8_T c1_u13;
  int32_T c1_q0;
  int32_T c1_q1;
  boolean_T c1_c_covSaturation;
  int32_T c1_qY;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 166U, chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(166U, (int32_T)_SFD_CCP_CALL(5U, 166U, 0,
              (boolean_T)CV_RELATIONAL_EVAL(5U, 166U, 0, (real_T)
    chartInstance->c1_autoXCounter, 1.0, 0, 3U, chartInstance->c1_autoXCounter <=
    1) != 0U, chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 166U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 164U,
                 chartInstance->c1_sfEvent);
    c1_temp = _SFD_CCP_CALL(5U, 164U, 0, (boolean_T)CV_RELATIONAL_EVAL(5U, 164U,
      0, (real_T)chartInstance->c1_autoX_dtRelease, 0.0, 0, 3U,
      chartInstance->c1_autoX_dtRelease <= 0) != 0U, chartInstance->c1_sfEvent);
    if (!c1_temp) {
      c1_i58 = c1_getAutoXParam(chartInstance, autoX_params_AUTOX_RAMP_END);
      c1_temp = _SFD_CCP_CALL(5U, 164U, 1, (boolean_T)CV_RELATIONAL_EVAL(5U,
        164U, 1, (real_T)*chartInstance->c1_clutchCurrVal, (real_T)c1_i58, 0, 3U,
        *chartInstance->c1_clutchCurrVal <= c1_i58) != 0U,
        chartInstance->c1_sfEvent);
    }

    c1_b_out = (CV_TRANSITION_EVAL(164U, (int32_T)c1_temp) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 164U, chartInstance->c1_sfEvent);
      c1_Clutch_setValue(chartInstance, 0U);
      sf_call_output_fcn_call(chartInstance->S, 5, "Efi_unsetRPMLimiter", 0);
      chartInstance->c1_b_tp_RELEASING = 0U;
      chartInstance->c1_b_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 16, 999U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 17, 1025U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 18, 1002U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 19, 998U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 4));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 20, 1001U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 5));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 49U, chartInstance->c1_sfEvent);
      if (chartInstance->c1_b_is_ACTIVE == c1_IN_RUNNING) {
      } else {
        chartInstance->c1_b_is_ACTIVE = c1_IN_RUNNING;
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 15, 985U, (void *)
          &chartInstance->c1_b_is_ACTIVE);
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 16, 999U, (int32_T)
          (chartInstance->c1_b_is_ACTIVE == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 17, 1025U, (int32_T)
          (chartInstance->c1_b_is_ACTIVE == 2));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 18, 1002U, (int32_T)
          (chartInstance->c1_b_is_ACTIVE == 3));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 19, 998U, (int32_T)
          (chartInstance->c1_b_is_ACTIVE == 4));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 20, 1001U, (int32_T)
          (chartInstance->c1_b_is_ACTIVE == 5));
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 16);
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 12, 951U, 6);
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 14, 974U, 5);
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 15, 985U, 5);
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 50U, chartInstance->c1_sfEvent);
        chartInstance->c1_b_tp_RUNNING = 1U;
        chartInstance->c1_autoXCounter = c1_const_AUTOX_WORK_RATE_ms;
        c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 48, 958U, (void *)
          &chartInstance->c1_autoXCounter);
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_autoXCounter, 9U);
        c1_u12 = chartInstance->c1_autoXCounter;
        sf_mex_printf("%s =\\n", "autoXCounter");
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11,
                          c1_u12);
        chartInstance->c1_lastShift = *chartInstance->c1_currentGear;
        c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 8, 715U, (void *)
          &chartInstance->c1_lastShift);
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastShift, 18U);
        c1_autoXCheckShift(chartInstance);
      }
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 165U, chartInstance->c1_sfEvent);
      chartInstance->c1_b_tp_RELEASING = 0U;
      chartInstance->c1_b_is_ACTIVE = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 16, 999U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 17, 1025U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 18, 1002U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 19, 998U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 4));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 20, 1001U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 5));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 49U, chartInstance->c1_sfEvent);
      if (chartInstance->c1_b_is_ACTIVE == c1_IN_RELEASING) {
      } else {
        chartInstance->c1_b_is_ACTIVE = c1_IN_RELEASING;
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 15, 985U, (void *)
          &chartInstance->c1_b_is_ACTIVE);
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 16, 999U, (int32_T)
          (chartInstance->c1_b_is_ACTIVE == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 17, 1025U, (int32_T)
          (chartInstance->c1_b_is_ACTIVE == 2));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 18, 1002U, (int32_T)
          (chartInstance->c1_b_is_ACTIVE == 3));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 19, 998U, (int32_T)
          (chartInstance->c1_b_is_ACTIVE == 4));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 20, 1001U, (int32_T)
          (chartInstance->c1_b_is_ACTIVE == 5));
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 15);
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 12, 951U, 5);
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 14, 974U, 4);
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 15, 985U, 4);
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 49U, chartInstance->c1_sfEvent);
        chartInstance->c1_b_tp_RELEASING = 1U;
        chartInstance->c1_autoX_clutchValue -=
          chartInstance->c1_autoX_clutchStep;
        c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 49, 959U, (void *)
          &chartInstance->c1_autoX_clutchValue);
        _SFD_DATA_RANGE_CHECK(chartInstance->c1_autoX_clutchValue, 11U);
        c1_d5 = chartInstance->c1_autoX_clutchValue;
        c1_b_covSaturation = false;
        if (c1_d5 < 256.0) {
          if (c1_d5 >= 0.0) {
            c1_u13 = (uint8_T)c1_d5;
          } else {
            c1_b_covSaturation = true;
            c1_u13 = 0U;
            _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1025U, 93U, 5U);
          }
        } else if (c1_d5 >= 256.0) {
          c1_b_covSaturation = true;
          c1_u13 = MAX_uint8_T;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1025U, 93U, 5U);
        } else {
          c1_u13 = 0U;
        }

        CV_SATURATION_EVAL(4, 49, 2, 0, c1_b_covSaturation);
        c1_Clutch_setValue(chartInstance, c1_u13);
        c1_q0 = chartInstance->c1_autoX_dtRelease;
        c1_q1 = 1;
        c1_c_covSaturation = false;
        if ((c1_q1 < 0) && (c1_q0 > c1_q1 + MAX_int32_T)) {
          c1_c_covSaturation = true;
          c1_qY = MAX_int32_T;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1025U, 155U, 1U);
        } else if ((c1_q1 > 0) && (c1_q0 < c1_q1 + MIN_int32_T)) {
          c1_c_covSaturation = true;
          c1_qY = MIN_int32_T;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1025U, 155U, 1U);
        } else {
          c1_qY = c1_q0 - c1_q1;
        }

        CV_SATURATION_EVAL(4, 49, 0, 0, c1_c_covSaturation);
        chartInstance->c1_autoX_dtRelease = c1_qY;
        c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 51, 961U, (void *)
          &chartInstance->c1_autoX_dtRelease);
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_autoX_dtRelease, 12U);
        chartInstance->c1_autoXCounter = c1_const_AUTOX_WORK_RATE_ms;
        c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 48, 958U, (void *)
          &chartInstance->c1_autoXCounter);
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_autoXCounter, 9U);
      }
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 49U, chartInstance->c1_sfEvent);
    c1_i57 = c1__s32_minus__(chartInstance, (int32_T)
      chartInstance->c1_autoXCounter, 1, 1025U, 233, 1);
    c1_covSaturation = false;
    if (c1_i57 < 0) {
      c1_covSaturation = true;
      c1_i57 = 0;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1025U, 233U, 1U);
    } else {
      if (c1_i57 > 65535) {
        c1_i57 = 65535;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1025U, 233U, 1U);
      }

      CV_SATURATION_EVAL(4, 49, 1, 0, c1_covSaturation);
    }

    chartInstance->c1_autoXCounter = (uint16_T)c1_i57;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 48, 958U, (void *)
      &chartInstance->c1_autoXCounter);
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_autoXCounter, 9U);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 49U, chartInstance->c1_sfEvent);
}

static void c1_b_DEFAULT(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  boolean_T c1_temp;
  boolean_T c1_out;
  uint16_T c1_u14;
  uint16_T c1_u15;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 154U, chartInstance->c1_sfEvent);
  c1_temp = _SFD_CCP_CALL(5U, 154U, 0, (boolean_T)CV_RELATIONAL_EVAL(5U, 154U, 0,
    (real_T)(*chartInstance->c1_autoXCom)[0], (real_T)
    chartInstance->c1_lastAutoXCom, 0, 1U, (*chartInstance->c1_autoXCom)[0] !=
    chartInstance->c1_lastAutoXCom) != 0U, chartInstance->c1_sfEvent);
  if (c1_temp) {
    c1_temp = _SFD_CCP_CALL(5U, 154U, 1, ((*chartInstance->c1_autoXCom)[1] ==
      AUTOX_READY) != 0U, chartInstance->c1_sfEvent);
  }

  c1_out = (CV_TRANSITION_EVAL(154U, (int32_T)c1_temp) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 154U, chartInstance->c1_sfEvent);
    chartInstance->c1_lastAutoXCom = (*chartInstance->c1_autoXCom)[0];
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 18, 1043U, (void *)
      &chartInstance->c1_lastAutoXCom);
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastAutoXCom, 2U);
    c1_u14 = chartInstance->c1_lastAutoXCom;
    sf_mex_printf("%s =\\n", "lastAutoXCom");
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11, c1_u14);
    chartInstance->c1_b_tp_DEFAULT = 0U;
    chartInstance->c1_is_AUTOCROSS = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 13, 952U, (int32_T)
      (chartInstance->c1_is_AUTOCROSS == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 14, 974U, (int32_T)
      (chartInstance->c1_is_AUTOCROSS == 2));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 45U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_AUTOCROSS = c1_IN_LAUNCH;
    c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 12, 951U, (void *)
      &chartInstance->c1_is_AUTOCROSS);
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 13, 952U, (int32_T)
      (chartInstance->c1_is_AUTOCROSS == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 14, 974U, (int32_T)
      (chartInstance->c1_is_AUTOCROSS == 2));
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 46U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_LAUNCH = 1U;
    chartInstance->c1_autoXCounter = 0U;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 48, 958U, (void *)
      &chartInstance->c1_autoXCounter);
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_autoXCounter, 9U);
    chartInstance->c1_autoX_clutchValue = 0.0;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 49, 959U, (void *)
      &chartInstance->c1_autoX_clutchValue);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_autoX_clutchValue, 11U);
    chartInstance->c1_autoX_clutchStep = 0.0;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 50, 960U, (void *)
      &chartInstance->c1_autoX_clutchStep);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_autoX_clutchStep, 10U);
    chartInstance->c1_autoX_dtRelease = 0;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 51, 961U, (void *)
      &chartInstance->c1_autoX_dtRelease);
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_autoX_dtRelease, 12U);
    chartInstance->c1_is_LAUNCH = c1_IN_ACTIVE;
    c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 14, 974U, (void *)
      &chartInstance->c1_is_LAUNCH);
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 15, 985U, (int32_T)
      (chartInstance->c1_is_LAUNCH == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 21, 1028U, (int32_T)
      (chartInstance->c1_is_LAUNCH == 2));
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 47U, chartInstance->c1_sfEvent);
    chartInstance->c1_b_tp_ACTIVE = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 158U, chartInstance->c1_sfEvent);
    if (chartInstance->c1_b_is_ACTIVE == c1_IN_START) {
    } else {
      chartInstance->c1_b_is_ACTIVE = c1_IN_START;
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 15, 985U, (void *)
        &chartInstance->c1_b_is_ACTIVE);
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 16, 999U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 17, 1025U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 18, 1002U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 19, 998U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 4));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 20, 1001U, (int32_T)
        (chartInstance->c1_b_is_ACTIVE == 5));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 1, 418U, 12);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 12, 951U, 2);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 14, 974U, 1);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 15, 985U, 1);
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 51U, chartInstance->c1_sfEvent);
      chartInstance->c1_b_tp_START = 1U;
      *chartInstance->c1_stateFb = (uint16_T)AUTOX_READY;
      c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 10, 833U, (void *)
        chartInstance->c1_stateFb);
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_stateFb, 32U);
      chartInstance->c1_autoXCounter = c1_const_AUTOX_WORK_RATE_ms;
      c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 48, 958U, (void *)
        &chartInstance->c1_autoXCounter);
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_autoXCounter, 9U);
      c1_u15 = chartInstance->c1_autoXCounter;
      sf_mex_printf("%s =\\n", "autoXCounter");
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 11, c1_u15);
      sf_call_output_fcn_call(chartInstance->S, 4, "Efi_setRPMLimiter", 0);
      c1_Clutch_setValue(chartInstance, 100U);
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 45U, chartInstance->c1_sfEvent);
    *chartInstance->c1_stateFb = (uint16_T)AUTOX_DEFAULT;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 10, 833U, (void *)
      chartInstance->c1_stateFb);
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_stateFb, 32U);
    c1_checkShift(chartInstance);
    c1_checkClutch(chartInstance);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 45U, chartInstance->c1_sfEvent);
}

static void c1_NEUTRAL_STATE(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  boolean_T c1_temp;
  boolean_T c1_b_temp;
  boolean_T c1_c_out;
  boolean_T c1_d_out;
  boolean_T c1_e_out;
  boolean_T c1_f_out;
  boolean_T guard1 = false;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 62U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_NEUTRAL_STATE) {
   case c1_IN_NEUTRAL:
    CV_STATE_EVAL(62, 0, c1_IN_NEUTRAL);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                 chartInstance->c1_sfEvent);
    c1_out = (CV_TRANSITION_EVAL(14U, (int32_T)_SFD_CCP_CALL(5U, 14U, 0,
                (chartInstance->c1_sfEvent == c1_event_GearshiftUp) != 0U,
                chartInstance->c1_sfEvent)) != 0);
    guard1 = false;
    if (c1_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
      guard1 = true;
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 92U,
                   chartInstance->c1_sfEvent);
      c1_c_out = (CV_TRANSITION_EVAL(92U, (int32_T)_SFD_CCP_CALL(5U, 92U, 0,
        (chartInstance->c1_sfEvent == c1_event_GearshiftDown) != 0U,
        chartInstance->c1_sfEvent)) != 0);
      if (c1_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 92U, chartInstance->c1_sfEvent);
        guard1 = true;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 183U,
                     chartInstance->c1_sfEvent);
        c1_f_out = (CV_TRANSITION_EVAL(183U, (int32_T)_SFD_CCP_CALL(5U, 183U, 0,
          (boolean_T)CV_RELATIONAL_EVAL(5U, 183U, 0, (real_T)
          *chartInstance->c1_currentGear, 0.0, 0, 1U,
          *chartInstance->c1_currentGear != 0) != 0U, chartInstance->c1_sfEvent))
                    != 0);
        if (c1_f_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 183U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_NEUTRAL = 0U;
          chartInstance->c1_is_NEUTRAL_STATE = c1_IN_NO_ACTIVE_CHILD;
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 27, 36U, (int32_T)
            (chartInstance->c1_is_NEUTRAL_STATE == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 28, 32U, (int32_T)
            (chartInstance->c1_is_NEUTRAL_STATE == 2));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 29, 34U, (int32_T)
            (chartInstance->c1_is_NEUTRAL_STATE == 3));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 30, 35U, (int32_T)
            (chartInstance->c1_is_NEUTRAL_STATE == 4));
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 63U, chartInstance->c1_sfEvent);
          chartInstance->c1_is_NEUTRAL_STATE = c1_IN_NO_NEUTRAL;
          c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 26, 31U, (void *)
            &chartInstance->c1_is_NEUTRAL_STATE);
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 27, 36U, (int32_T)
            (chartInstance->c1_is_NEUTRAL_STATE == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 28, 32U, (int32_T)
            (chartInstance->c1_is_NEUTRAL_STATE == 2));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 29, 34U, (int32_T)
            (chartInstance->c1_is_NEUTRAL_STATE == 3));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 30, 35U, (int32_T)
            (chartInstance->c1_is_NEUTRAL_STATE == 4));
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 26, 31U, 3);
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 64U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_NO_NEUTRAL = 1U;
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 63U,
                       chartInstance->c1_sfEvent);
        }
      }
    }

    if (guard1) {
      chartInstance->c1_tp_NEUTRAL = 0U;
      chartInstance->c1_is_NEUTRAL_STATE = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 27, 36U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 28, 32U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 29, 34U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 30, 35U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 4));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 63U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_NEUTRAL_STATE = c1_IN_UNSET_NEUTRAL;
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 26, 31U, (void *)
        &chartInstance->c1_is_NEUTRAL_STATE);
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 27, 36U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 28, 32U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 29, 34U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 30, 35U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 4));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 26, 31U, 2);
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 66U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_UNSET_NEUTRAL = 1U;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 63U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_NO_NEUTRAL:
    CV_STATE_EVAL(62, 0, c1_IN_NO_NEUTRAL);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U,
                 chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(16U, (int32_T)_SFD_CCP_CALL(5U, 16U, 0,
      (chartInstance->c1_sfEvent == c1_event_GearshiftSetNeutral) != 0U,
      chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_NO_NEUTRAL = 0U;
      chartInstance->c1_is_NEUTRAL_STATE = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 27, 36U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 28, 32U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 29, 34U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 30, 35U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 4));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 64U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_NEUTRAL_STATE = c1_IN_SET_NEUTRAL;
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 26, 31U, (void *)
        &chartInstance->c1_is_NEUTRAL_STATE);
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 27, 36U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 28, 32U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 29, 34U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 30, 35U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 4));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 26, 31U, 4);
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 65U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_SET_NEUTRAL = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 64U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 64U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_SET_NEUTRAL:
    CV_STATE_EVAL(62, 0, c1_IN_SET_NEUTRAL);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U,
                 chartInstance->c1_sfEvent);
    c1_temp = _SFD_CCP_CALL(5U, 17U, 0, (chartInstance->c1_is_GEARSHIFT ==
      c1_IN_DOWN_END) != 0U, chartInstance->c1_sfEvent);
    if (!c1_temp) {
      c1_temp = _SFD_CCP_CALL(5U, 17U, 1, (chartInstance->c1_is_GEARSHIFT ==
        c1_IN_UP_END) != 0U, chartInstance->c1_sfEvent);
    }

    c1_d_out = (CV_TRANSITION_EVAL(17U, (int32_T)c1_temp) != 0);
    if (c1_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_SET_NEUTRAL = 0U;
      chartInstance->c1_is_NEUTRAL_STATE = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 27, 36U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 28, 32U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 29, 34U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 30, 35U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 4));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 65U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_NEUTRAL_STATE = c1_IN_NEUTRAL;
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 26, 31U, (void *)
        &chartInstance->c1_is_NEUTRAL_STATE);
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 27, 36U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 28, 32U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 29, 34U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 30, 35U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 4));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 26, 31U, 1);
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 63U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_NEUTRAL = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 65U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 65U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_UNSET_NEUTRAL:
    CV_STATE_EVAL(62, 0, c1_IN_UNSET_NEUTRAL);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U,
                 chartInstance->c1_sfEvent);
    c1_b_temp = _SFD_CCP_CALL(5U, 15U, 0, (chartInstance->c1_is_GEARSHIFT ==
      c1_IN_DOWN_END) != 0U, chartInstance->c1_sfEvent);
    if (!c1_b_temp) {
      c1_b_temp = _SFD_CCP_CALL(5U, 15U, 1, (chartInstance->c1_is_GEARSHIFT ==
        c1_IN_UP_END) != 0U, chartInstance->c1_sfEvent);
    }

    c1_e_out = (CV_TRANSITION_EVAL(15U, (int32_T)c1_b_temp) != 0);
    if (c1_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_UNSET_NEUTRAL = 0U;
      chartInstance->c1_is_NEUTRAL_STATE = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 27, 36U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 28, 32U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 29, 34U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 30, 35U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 4));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 66U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_NEUTRAL_STATE = c1_IN_NO_NEUTRAL;
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 26, 31U, (void *)
        &chartInstance->c1_is_NEUTRAL_STATE);
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 27, 36U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 28, 32U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 29, 34U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 30, 35U, (int32_T)
        (chartInstance->c1_is_NEUTRAL_STATE == 4));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 26, 31U, 3);
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 64U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_NO_NEUTRAL = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 66U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 66U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(62, 0, 0);

    /* Unreachable state, for coverage only */
    chartInstance->c1_is_NEUTRAL_STATE = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 27, 36U, (int32_T)
      (chartInstance->c1_is_NEUTRAL_STATE == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 28, 32U, (int32_T)
      (chartInstance->c1_is_NEUTRAL_STATE == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 29, 34U, (int32_T)
      (chartInstance->c1_is_NEUTRAL_STATE == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 30, 35U, (int32_T)
      (chartInstance->c1_is_NEUTRAL_STATE == 4));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 63U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 62U, chartInstance->c1_sfEvent);
}

static void c1_GEARSHIFT(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_GEARSHIFT) {
   case c1_IN_DOWNSHIFTING:
    CV_STATE_EVAL(4, 0, c1_IN_DOWNSHIFTING);
    c1_DOWNSHIFTING(chartInstance);
    break;

   case c1_IN_DOWN_END:
    CV_STATE_EVAL(4, 0, c1_IN_DOWN_END);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_DOWN_END = 0U;
    chartInstance->c1_is_GEARSHIFT = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 32, 697U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 42, 18U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 43, 5U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 44, 7U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 4));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 45, 693U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 5));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 56, 13U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 6));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_GEARSHIFT = c1_IN_IDLE;
    c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 31, 1U, (void *)
      &chartInstance->c1_is_GEARSHIFT);
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 32, 697U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 42, 18U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 43, 5U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 44, 7U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 4));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 45, 693U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 5));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 56, 13U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 6));
    c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 2);
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_IDLE = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_IDLE:
    CV_STATE_EVAL(4, 0, c1_IN_IDLE);
    c1_IDLE(chartInstance);
    break;

   case c1_b_IN_INIT:
    CV_STATE_EVAL(4, 0, c1_b_IN_INIT);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
    chartInstance->c1_b_tp_INIT = 0U;
    chartInstance->c1_is_GEARSHIFT = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 32, 697U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 42, 18U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 43, 5U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 44, 7U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 4));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 45, 693U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 5));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 56, 13U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 6));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_GEARSHIFT = c1_IN_IDLE;
    c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 31, 1U, (void *)
      &chartInstance->c1_is_GEARSHIFT);
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 32, 697U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 42, 18U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 43, 5U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 44, 7U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 4));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 45, 693U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 5));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 56, 13U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 6));
    c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 2);
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_IDLE = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_UPSHIFTING:
    CV_STATE_EVAL(4, 0, c1_IN_UPSHIFTING);
    c1_UPSHIFTING(chartInstance);
    break;

   case c1_IN_UP_END:
    CV_STATE_EVAL(4, 0, c1_IN_UP_END);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_UP_END = 0U;
    chartInstance->c1_is_GEARSHIFT = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 32, 697U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 42, 18U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 43, 5U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 44, 7U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 4));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 45, 693U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 5));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 56, 13U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 6));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_GEARSHIFT = c1_IN_IDLE;
    c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 31, 1U, (void *)
      &chartInstance->c1_is_GEARSHIFT);
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 32, 697U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 42, 18U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 43, 5U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 44, 7U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 4));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 45, 693U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 5));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 56, 13U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 6));
    c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 2);
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_IDLE = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 30U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(4, 0, 0);

    /* Unreachable state, for coverage only */
    chartInstance->c1_is_GEARSHIFT = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 32, 697U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 42, 18U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 43, 5U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 44, 7U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 4));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 45, 693U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 5));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 56, 13U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 6));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c1_sfEvent);
}

static void c1_UPSHIFTING(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  boolean_T c1_c_out;
  int32_T c1_q0;
  int32_T c1_b_q0;
  int32_T c1_c_q0;
  int32_T c1_q1;
  int32_T c1_b_q1;
  int32_T c1_c_q1;
  boolean_T c1_covSaturation;
  boolean_T c1_b_covSaturation;
  boolean_T c1_c_covSaturation;
  int32_T c1_qY;
  int32_T c1_b_qY;
  int32_T c1_c_qY;
  boolean_T c1_d_out;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 19U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_UPSHIFTING) {
   case c1_IN_UP_BRAKE:
    CV_STATE_EVAL(19, 0, c1_IN_UP_BRAKE);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U, chartInstance->c1_sfEvent);
    c1_out = (CV_TRANSITION_EVAL(7U, (int32_T)_SFD_CCP_CALL(5U, 7U, 0,
                (boolean_T)CV_RELATIONAL_EVAL(5U, 7U, 0, (real_T)
      chartInstance->c1_ticksCounter, 1.0, 0, 0U, chartInstance->c1_ticksCounter
      == 1) != 0U, chartInstance->c1_sfEvent)) != 0);
    if (c1_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_UP_BRAKE = 0U;
      chartInstance->c1_is_UPSHIFTING = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 46, 12U, (int32_T)
        (chartInstance->c1_is_UPSHIFTING == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 47, 10U, (int32_T)
        (chartInstance->c1_is_UPSHIFTING == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 50, 11U, (int32_T)
        (chartInstance->c1_is_UPSHIFTING == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 53, 9U, (int32_T)
        (chartInstance->c1_is_UPSHIFTING == 4));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_UPSHIFTING = 0U;
      chartInstance->c1_is_GEARSHIFT = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 32, 697U, (int32_T)
        (chartInstance->c1_is_GEARSHIFT == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 42, 18U, (int32_T)
        (chartInstance->c1_is_GEARSHIFT == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 43, 5U, (int32_T)
        (chartInstance->c1_is_GEARSHIFT == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 44, 7U, (int32_T)
        (chartInstance->c1_is_GEARSHIFT == 4));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 45, 693U, (int32_T)
        (chartInstance->c1_is_GEARSHIFT == 5));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 56, 13U, (int32_T)
        (chartInstance->c1_is_GEARSHIFT == 6));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 45, 693U, 0);
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 45, 693U, (void *)
        &chartInstance->c1_is_UPSHIFTING);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
      if (chartInstance->c1_is_GEARSHIFT == c1_IN_UP_END) {
      } else {
        chartInstance->c1_is_GEARSHIFT = c1_IN_UP_END;
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 31, 1U, (void *)
          &chartInstance->c1_is_GEARSHIFT);
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 32, 697U, (int32_T)
          (chartInstance->c1_is_GEARSHIFT == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 42, 18U, (int32_T)
          (chartInstance->c1_is_GEARSHIFT == 2));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 43, 5U, (int32_T)
          (chartInstance->c1_is_GEARSHIFT == 3));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 44, 7U, (int32_T)
          (chartInstance->c1_is_GEARSHIFT == 4));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 45, 693U, (int32_T)
          (chartInstance->c1_is_GEARSHIFT == 5));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 56, 13U, (int32_T)
          (chartInstance->c1_is_GEARSHIFT == 6));
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 10);
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_UP_END = 1U;
        sf_call_output_fcn_call(chartInstance->S, 10, "Gearshift_free", 0);
      }
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 20U,
                   chartInstance->c1_sfEvent);
      c1_q0 = chartInstance->c1_ticksCounter;
      c1_q1 = 1;
      c1_covSaturation = false;
      if ((c1_q1 < 0) && (c1_q0 > c1_q1 + MAX_int32_T)) {
        c1_covSaturation = true;
        c1_qY = MAX_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 12U, 114U, 1U);
      } else if ((c1_q1 > 0) && (c1_q0 < c1_q1 + MIN_int32_T)) {
        c1_covSaturation = true;
        c1_qY = MIN_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 12U, 114U, 1U);
      } else {
        c1_qY = c1_q0 - c1_q1;
      }

      CV_SATURATION_EVAL(4, 20, 0, 0, c1_covSaturation);
      chartInstance->c1_ticksCounter = c1_qY;
      c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 54, 45U, (void *)
        &chartInstance->c1_ticksCounter);
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_ticksCounter, 13U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, chartInstance->c1_sfEvent);
    if (chartInstance->c1_is_GEARSHIFT != c1_IN_UPSHIFTING) {
    } else {
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c1_sfEvent);
    }
    break;

   case c1_IN_UP_PUSH:
    CV_STATE_EVAL(19, 0, c1_IN_UP_PUSH);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(5U, (int32_T)_SFD_CCP_CALL(5U, 5U, 0,
      (boolean_T)CV_RELATIONAL_EVAL(5U, 5U, 0, (real_T)
      chartInstance->c1_ticksCounter, 1.0, 0, 0U, chartInstance->c1_ticksCounter
      == 1) != 0U, chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
      c1_exit_internal_UP_PUSH(chartInstance);
      chartInstance->c1_tp_UP_PUSH = 0U;
      chartInstance->c1_is_UPSHIFTING = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 46, 12U, (int32_T)
        (chartInstance->c1_is_UPSHIFTING == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 47, 10U, (int32_T)
        (chartInstance->c1_is_UPSHIFTING == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 50, 11U, (int32_T)
        (chartInstance->c1_is_UPSHIFTING == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 53, 9U, (int32_T)
        (chartInstance->c1_is_UPSHIFTING == 4));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 47, 10U, 0);
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 47, 10U, (void *)
        &chartInstance->c1_is_UP_PUSH);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c1_sfEvent);
      if (chartInstance->c1_is_UPSHIFTING == c1_IN_UP_REBOUND) {
      } else {
        chartInstance->c1_is_UPSHIFTING = c1_IN_UP_REBOUND;
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 45, 693U, (void *)
          &chartInstance->c1_is_UPSHIFTING);
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 46, 12U, (int32_T)
          (chartInstance->c1_is_UPSHIFTING == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 47, 10U, (int32_T)
          (chartInstance->c1_is_UPSHIFTING == 2));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 50, 11U, (int32_T)
          (chartInstance->c1_is_UPSHIFTING == 3));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 53, 9U, (int32_T)
          (chartInstance->c1_is_UPSHIFTING == 4));
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_UP_REBOUND = 1U;
        chartInstance->c1_ticksCounter = c1_Gearshift_getTime(chartInstance);
        c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 54, 45U, (void *)
          &chartInstance->c1_ticksCounter);
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_ticksCounter, 13U);
      }

      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 65U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 64U,
                   chartInstance->c1_sfEvent);
      c1_d_out = (CV_TRANSITION_EVAL(64U, (int32_T)_SFD_CCP_CALL(5U, 64U, 0,
        (chartInstance->c1_is_NEUTRAL_STATE == c1_IN_SET_NEUTRAL) != 0U,
        chartInstance->c1_sfEvent)) != 0);
      if (c1_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 64U, chartInstance->c1_sfEvent);
        if (chartInstance->c1_is_UP_REBOUND == c1_IN_SettingNeutral) {
        } else {
          chartInstance->c1_is_UP_REBOUND = c1_IN_SettingNeutral;
          c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 50, 11U, (void *)
            &chartInstance->c1_is_UP_REBOUND);
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 51, 390U, (int32_T)
            (chartInstance->c1_is_UP_REBOUND == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 52, 391U, (int32_T)
            (chartInstance->c1_is_UP_REBOUND == 2));
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 7);
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 45, 693U, 5);
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 50, 11U, 1);
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_SettingNeutral = 1U;
          c1_Clutch_setValue(chartInstance, 0U);
          sf_call_output_fcn_call(chartInstance->S, 6, "Gearshift_rebound", 0);
        }
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 66U, chartInstance->c1_sfEvent);
        if (chartInstance->c1_is_UP_REBOUND == c1_IN_Default) {
        } else {
          chartInstance->c1_is_UP_REBOUND = c1_IN_Default;
          c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 50, 11U, (void *)
            &chartInstance->c1_is_UP_REBOUND);
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 51, 390U, (int32_T)
            (chartInstance->c1_is_UP_REBOUND == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 52, 391U, (int32_T)
            (chartInstance->c1_is_UP_REBOUND == 2));
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 8);
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 45, 693U, 6);
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 50, 11U, 2);
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_Default = 1U;
          sf_call_output_fcn_call(chartInstance->S, 6, "Gearshift_rebound", 0);
        }
      }
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 21U,
                   chartInstance->c1_sfEvent);
      c1_b_q0 = chartInstance->c1_ticksCounter;
      c1_b_q1 = 1;
      c1_b_covSaturation = false;
      if ((c1_b_q1 < 0) && (c1_b_q0 > c1_b_q1 + MAX_int32_T)) {
        c1_b_covSaturation = true;
        c1_b_qY = MAX_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 10U, 89U, 1U);
      } else if ((c1_b_q1 > 0) && (c1_b_q0 < c1_b_q1 + MIN_int32_T)) {
        c1_b_covSaturation = true;
        c1_b_qY = MIN_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 10U, 89U, 1U);
      } else {
        c1_b_qY = c1_b_q0 - c1_b_q1;
      }

      CV_SATURATION_EVAL(4, 21, 0, 0, c1_b_covSaturation);
      chartInstance->c1_ticksCounter = c1_b_qY;
      c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 54, 45U, (void *)
        &chartInstance->c1_ticksCounter);
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_ticksCounter, 13U);
      switch (chartInstance->c1_is_UP_PUSH) {
       case c1_IN_CutOff:
        CV_STATE_EVAL(21, 0, c1_IN_CutOff);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 22U,
                     chartInstance->c1_sfEvent);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c1_sfEvent);
        break;

       case c1_b_IN_Default:
        CV_STATE_EVAL(21, 0, c1_b_IN_Default);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 23U,
                     chartInstance->c1_sfEvent);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 23U, chartInstance->c1_sfEvent);
        break;

       default:
        CV_STATE_EVAL(21, 0, 0);

        /* Unreachable state, for coverage only */
        chartInstance->c1_is_UP_PUSH = c1_IN_NO_ACTIVE_CHILD;
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 48, 423U, (int32_T)
          (chartInstance->c1_is_UP_PUSH == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 49, 422U, (int32_T)
          (chartInstance->c1_is_UP_PUSH == 2));
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c1_sfEvent);
        break;
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_UP_REBOUND:
    CV_STATE_EVAL(19, 0, c1_IN_UP_REBOUND);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U, chartInstance->c1_sfEvent);
    c1_c_out = (CV_TRANSITION_EVAL(6U, (int32_T)_SFD_CCP_CALL(5U, 6U, 0,
      (boolean_T)CV_RELATIONAL_EVAL(5U, 6U, 0, (real_T)
      chartInstance->c1_ticksCounter, 1.0, 0, 0U, chartInstance->c1_ticksCounter
      == 1) != 0U, chartInstance->c1_sfEvent)) != 0);
    if (c1_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
      c1_exit_internal_UP_REBOUND(chartInstance);
      chartInstance->c1_tp_UP_REBOUND = 0U;
      chartInstance->c1_is_UPSHIFTING = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 46, 12U, (int32_T)
        (chartInstance->c1_is_UPSHIFTING == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 47, 10U, (int32_T)
        (chartInstance->c1_is_UPSHIFTING == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 50, 11U, (int32_T)
        (chartInstance->c1_is_UPSHIFTING == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 53, 9U, (int32_T)
        (chartInstance->c1_is_UPSHIFTING == 4));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 50, 11U, 0);
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 50, 11U, (void *)
        &chartInstance->c1_is_UP_REBOUND);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c1_sfEvent);
      if (chartInstance->c1_is_UPSHIFTING == c1_IN_UP_BRAKE) {
      } else {
        chartInstance->c1_is_UPSHIFTING = c1_IN_UP_BRAKE;
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 45, 693U, (void *)
          &chartInstance->c1_is_UPSHIFTING);
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 46, 12U, (int32_T)
          (chartInstance->c1_is_UPSHIFTING == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 47, 10U, (int32_T)
          (chartInstance->c1_is_UPSHIFTING == 2));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 50, 11U, (int32_T)
          (chartInstance->c1_is_UPSHIFTING == 3));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 53, 9U, (int32_T)
          (chartInstance->c1_is_UPSHIFTING == 4));
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 9);
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 45, 693U, 7);
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_UP_BRAKE = 1U;
        chartInstance->c1_ticksCounter = c1_Gearshift_getTime(chartInstance);
        c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 54, 45U, (void *)
          &chartInstance->c1_ticksCounter);
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_ticksCounter, 13U);
        sf_call_output_fcn_call(chartInstance->S, 9, "Gearshift_brake", 0);
      }
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 24U,
                   chartInstance->c1_sfEvent);
      c1_c_q0 = chartInstance->c1_ticksCounter;
      c1_c_q1 = 1;
      c1_c_covSaturation = false;
      if ((c1_c_q1 < 0) && (c1_c_q0 > c1_c_q1 + MAX_int32_T)) {
        c1_c_covSaturation = true;
        c1_c_qY = MAX_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 11U, 92U, 1U);
      } else if ((c1_c_q1 > 0) && (c1_c_q0 < c1_c_q1 + MIN_int32_T)) {
        c1_c_covSaturation = true;
        c1_c_qY = MIN_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 11U, 92U, 1U);
      } else {
        c1_c_qY = c1_c_q0 - c1_c_q1;
      }

      CV_SATURATION_EVAL(4, 24, 0, 0, c1_c_covSaturation);
      chartInstance->c1_ticksCounter = c1_c_qY;
      c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 54, 45U, (void *)
        &chartInstance->c1_ticksCounter);
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_ticksCounter, 13U);
      switch (chartInstance->c1_is_UP_REBOUND) {
       case c1_IN_Default:
        CV_STATE_EVAL(24, 0, c1_IN_Default);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 25U,
                     chartInstance->c1_sfEvent);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 25U, chartInstance->c1_sfEvent);
        break;

       case c1_IN_SettingNeutral:
        CV_STATE_EVAL(24, 0, c1_IN_SettingNeutral);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 26U,
                     chartInstance->c1_sfEvent);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, chartInstance->c1_sfEvent);
        break;

       default:
        CV_STATE_EVAL(24, 0, 0);

        /* Unreachable state, for coverage only */
        chartInstance->c1_is_UP_REBOUND = c1_IN_NO_ACTIVE_CHILD;
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 51, 390U, (int32_T)
          (chartInstance->c1_is_UP_REBOUND == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 52, 391U, (int32_T)
          (chartInstance->c1_is_UP_REBOUND == 2));
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
        break;
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_UP_START:
    CV_STATE_EVAL(19, 0, c1_IN_UP_START);
    c1_UP_START(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(19, 0, 0);

    /* Unreachable state, for coverage only */
    chartInstance->c1_is_UPSHIFTING = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 46, 12U, (int32_T)
      (chartInstance->c1_is_UPSHIFTING == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 47, 10U, (int32_T)
      (chartInstance->c1_is_UPSHIFTING == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 50, 11U, (int32_T)
      (chartInstance->c1_is_UPSHIFTING == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 53, 9U, (int32_T)
      (chartInstance->c1_is_UPSHIFTING == 4));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c1_sfEvent);
    break;
  }
}

static void c1_exit_internal_UP_REBOUND(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c1_is_UP_REBOUND) {
   case c1_IN_Default:
    CV_STATE_EVAL(24, 1, c1_IN_Default);
    chartInstance->c1_tp_Default = 0U;
    chartInstance->c1_is_UP_REBOUND = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 51, 390U, (int32_T)
      (chartInstance->c1_is_UP_REBOUND == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 52, 391U, (int32_T)
      (chartInstance->c1_is_UP_REBOUND == 2));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_SettingNeutral:
    CV_STATE_EVAL(24, 1, c1_IN_SettingNeutral);
    chartInstance->c1_tp_SettingNeutral = 0U;
    chartInstance->c1_is_UP_REBOUND = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 51, 390U, (int32_T)
      (chartInstance->c1_is_UP_REBOUND == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 52, 391U, (int32_T)
      (chartInstance->c1_is_UP_REBOUND == 2));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(24, 1, 0);
    chartInstance->c1_is_UP_REBOUND = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 51, 390U, (int32_T)
      (chartInstance->c1_is_UP_REBOUND == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 52, 391U, (int32_T)
      (chartInstance->c1_is_UP_REBOUND == 2));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
    break;
  }
}

static void c1_exit_internal_UP_PUSH(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c1_is_UP_PUSH) {
   case c1_IN_CutOff:
    CV_STATE_EVAL(21, 1, c1_IN_CutOff);
    chartInstance->c1_tp_CutOff = 0U;
    chartInstance->c1_is_UP_PUSH = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 48, 423U, (int32_T)
      (chartInstance->c1_is_UP_PUSH == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 49, 422U, (int32_T)
      (chartInstance->c1_is_UP_PUSH == 2));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c1_sfEvent);
    break;

   case c1_b_IN_Default:
    CV_STATE_EVAL(21, 1, c1_b_IN_Default);
    chartInstance->c1_b_tp_Default = 0U;
    chartInstance->c1_is_UP_PUSH = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 48, 423U, (int32_T)
      (chartInstance->c1_is_UP_PUSH == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 49, 422U, (int32_T)
      (chartInstance->c1_is_UP_PUSH == 2));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(21, 1, 0);
    chartInstance->c1_is_UP_PUSH = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 48, 423U, (int32_T)
      (chartInstance->c1_is_UP_PUSH == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 49, 422U, (int32_T)
      (chartInstance->c1_is_UP_PUSH == 2));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c1_sfEvent);
    break;
  }
}

static void c1_UP_START(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  int32_T c1_q0;
  int32_T c1_q1;
  boolean_T c1_covSaturation;
  int32_T c1_qY;
  boolean_T c1_b_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(4U, (int32_T)_SFD_CCP_CALL(5U, 4U, 0, (boolean_T)
              CV_RELATIONAL_EVAL(5U, 4U, 0, (real_T)
    chartInstance->c1_ticksCounter, 1.0, 0, 0U, chartInstance->c1_ticksCounter ==
    1) != 0U, chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
    c1_exit_internal_UP_START(chartInstance);
    chartInstance->c1_tp_UP_START = 0U;
    chartInstance->c1_is_UPSHIFTING = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 46, 12U, (int32_T)
      (chartInstance->c1_is_UPSHIFTING == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 47, 10U, (int32_T)
      (chartInstance->c1_is_UPSHIFTING == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 50, 11U, (int32_T)
      (chartInstance->c1_is_UPSHIFTING == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 53, 9U, (int32_T)
      (chartInstance->c1_is_UPSHIFTING == 4));
    c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 53, 9U, 0);
    c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 53, 9U, (void *)
      &chartInstance->c1_is_UP_START);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
    if (chartInstance->c1_is_UPSHIFTING == c1_IN_UP_PUSH) {
    } else {
      chartInstance->c1_is_UPSHIFTING = c1_IN_UP_PUSH;
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 45, 693U, (void *)
        &chartInstance->c1_is_UPSHIFTING);
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 46, 12U, (int32_T)
        (chartInstance->c1_is_UPSHIFTING == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 47, 10U, (int32_T)
        (chartInstance->c1_is_UPSHIFTING == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 50, 11U, (int32_T)
        (chartInstance->c1_is_UPSHIFTING == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 53, 9U, (int32_T)
        (chartInstance->c1_is_UPSHIFTING == 4));
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_UP_PUSH = 1U;
      chartInstance->c1_ticksCounter = c1_Gearshift_getTime(chartInstance);
      c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 54, 45U, (void *)
        &chartInstance->c1_ticksCounter);
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_ticksCounter, 13U);
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 75U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 77U,
                 chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(77U, !_SFD_CCP_CALL(5U, 77U, 0,
      (chartInstance->c1_is_NEUTRAL_STATE == c1_IN_SET_NEUTRAL) != 0U,
      chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 77U, chartInstance->c1_sfEvent);
      if (chartInstance->c1_is_UP_PUSH == c1_IN_CutOff) {
      } else {
        chartInstance->c1_is_UP_PUSH = c1_IN_CutOff;
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 47, 10U, (void *)
          &chartInstance->c1_is_UP_PUSH);
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 48, 423U, (int32_T)
          (chartInstance->c1_is_UP_PUSH == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 49, 422U, (int32_T)
          (chartInstance->c1_is_UP_PUSH == 2));
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 5);
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 45, 693U, 3);
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 47, 10U, 1);
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_CutOff = 1U;
        sf_call_output_fcn_call(chartInstance->S, 3, "Efi_unsetCut", 0);
        sf_call_output_fcn_call(chartInstance->S, 7, "Gearshift_up_push", 0);
      }
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 76U, chartInstance->c1_sfEvent);
      if (chartInstance->c1_is_UP_PUSH == c1_b_IN_Default) {
      } else {
        chartInstance->c1_is_UP_PUSH = c1_b_IN_Default;
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 47, 10U, (void *)
          &chartInstance->c1_is_UP_PUSH);
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 48, 423U, (int32_T)
          (chartInstance->c1_is_UP_PUSH == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 49, 422U, (int32_T)
          (chartInstance->c1_is_UP_PUSH == 2));
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 17);
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 45, 693U, 4);
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 47, 10U, 2);
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c1_sfEvent);
        chartInstance->c1_b_tp_Default = 1U;
        sf_call_output_fcn_call(chartInstance->S, 7, "Gearshift_up_push", 0);
      }
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 27U, chartInstance->c1_sfEvent);
    c1_q0 = chartInstance->c1_ticksCounter;
    c1_q1 = 1;
    c1_covSaturation = false;
    if ((c1_q1 < 0) && (c1_q0 > c1_q1 + MAX_int32_T)) {
      c1_covSaturation = true;
      c1_qY = MAX_int32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 9U, 94U, 1U);
    } else if ((c1_q1 > 0) && (c1_q0 < c1_q1 + MIN_int32_T)) {
      c1_covSaturation = true;
      c1_qY = MIN_int32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 9U, 94U, 1U);
    } else {
      c1_qY = c1_q0 - c1_q1;
    }

    CV_SATURATION_EVAL(4, 27, 1, 0, c1_covSaturation);
    chartInstance->c1_ticksCounter = c1_qY;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 54, 45U, (void *)
      &chartInstance->c1_ticksCounter);
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_ticksCounter, 13U);
    switch (chartInstance->c1_is_UP_START) {
     case c1_IN_Default:
      CV_STATE_EVAL(27, 0, c1_IN_Default);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 28U,
                   chartInstance->c1_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 28U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_SettingNeutral:
      CV_STATE_EVAL(27, 0, c1_IN_SettingNeutral);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 29U,
                   chartInstance->c1_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 29U, chartInstance->c1_sfEvent);
      break;

     default:
      CV_STATE_EVAL(27, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c1_is_UP_START = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 54, 385U, (int32_T)
        (chartInstance->c1_is_UP_START == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 55, 383U, (int32_T)
        (chartInstance->c1_is_UP_START == 2));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
      break;
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 27U, chartInstance->c1_sfEvent);
}

static void c1_exit_internal_UP_START(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c1_is_UP_START) {
   case c1_IN_Default:
    CV_STATE_EVAL(27, 1, c1_IN_Default);
    chartInstance->c1_c_tp_Default = 0U;
    chartInstance->c1_is_UP_START = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 54, 385U, (int32_T)
      (chartInstance->c1_is_UP_START == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 55, 383U, (int32_T)
      (chartInstance->c1_is_UP_START == 2));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_SettingNeutral:
    CV_STATE_EVAL(27, 1, c1_IN_SettingNeutral);
    chartInstance->c1_b_tp_SettingNeutral = 0U;
    chartInstance->c1_is_UP_START = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 54, 385U, (int32_T)
      (chartInstance->c1_is_UP_START == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 55, 383U, (int32_T)
      (chartInstance->c1_is_UP_START == 2));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(27, 1, 0);
    chartInstance->c1_is_UP_START = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 54, 385U, (int32_T)
      (chartInstance->c1_is_UP_START == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 55, 383U, (int32_T)
      (chartInstance->c1_is_UP_START == 2));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
    break;
  }
}

static void c1_IDLE(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  boolean_T c1_temp;
  boolean_T c1_out;
  boolean_T c1_b_out;
  boolean_T c1_c_out;
  boolean_T c1_b_temp;
  int32_T c1_q0;
  boolean_T c1_d_out;
  int32_T c1_q1;
  boolean_T c1_covSaturation;
  boolean_T c1_c_temp;
  int32_T c1_qY;
  boolean_T c1_e_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c1_sfEvent);
  c1_temp = _SFD_CCP_CALL(5U, 2U, 0, (chartInstance->c1_sfEvent ==
    c1_event_GearshiftUp) != 0U, chartInstance->c1_sfEvent);
  if (c1_temp) {
    c1_temp = _SFD_CCP_CALL(5U, 2U, 1, (boolean_T)CV_RELATIONAL_EVAL(5U, 2U, 0,
      (real_T)*chartInstance->c1_currentGear, 5.0, 0, 2U,
      *chartInstance->c1_currentGear < 5) != 0U, chartInstance->c1_sfEvent);
  }

  c1_out = (CV_TRANSITION_EVAL(2U, (int32_T)c1_temp) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_IDLE = 0U;
    chartInstance->c1_is_GEARSHIFT = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 32, 697U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 42, 18U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 43, 5U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 44, 7U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 4));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 45, 693U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 5));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 56, 13U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 6));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_GEARSHIFT = c1_IN_UPSHIFTING;
    c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 31, 1U, (void *)
      &chartInstance->c1_is_GEARSHIFT);
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 32, 697U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 42, 18U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 43, 5U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 44, 7U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 4));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 45, 693U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 5));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 56, 13U, (int32_T)
      (chartInstance->c1_is_GEARSHIFT == 6));
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_UPSHIFTING = 1U;
    if (chartInstance->c1_is_UPSHIFTING == c1_IN_UP_START) {
    } else {
      chartInstance->c1_is_UPSHIFTING = c1_IN_UP_START;
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 45, 693U, (void *)
        &chartInstance->c1_is_UPSHIFTING);
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 46, 12U, (int32_T)
        (chartInstance->c1_is_UPSHIFTING == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 47, 10U, (int32_T)
        (chartInstance->c1_is_UPSHIFTING == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 50, 11U, (int32_T)
        (chartInstance->c1_is_UPSHIFTING == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 53, 9U, (int32_T)
        (chartInstance->c1_is_UPSHIFTING == 4));
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_UP_START = 1U;
      c1_q0 = c1_Gearshift_getTime(chartInstance);
      c1_q1 = 1;
      c1_covSaturation = false;
      if ((c1_q1 < 0) && (c1_q0 < MIN_int32_T - c1_q1)) {
        c1_covSaturation = true;
        c1_qY = MIN_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 9U, 52U, 1U);
      } else if ((c1_q1 > 0) && (c1_q0 > MAX_int32_T - c1_q1)) {
        c1_covSaturation = true;
        c1_qY = MAX_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 9U, 52U, 1U);
      } else {
        c1_qY = c1_q0 + c1_q1;
      }

      CV_SATURATION_EVAL(4, 27, 0, 0, c1_covSaturation);
      chartInstance->c1_ticksCounter = c1_qY;
      c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 54, 45U, (void *)
        &chartInstance->c1_ticksCounter);
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_ticksCounter, 13U);
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 61U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 62U,
                 chartInstance->c1_sfEvent);
    c1_c_out = (CV_TRANSITION_EVAL(62U, (int32_T)_SFD_CCP_CALL(5U, 62U, 0,
      (chartInstance->c1_is_NEUTRAL_STATE == c1_IN_SET_NEUTRAL) != 0U,
      chartInstance->c1_sfEvent)) != 0);
    if (c1_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 62U, chartInstance->c1_sfEvent);
      if (chartInstance->c1_is_UP_START == c1_IN_SettingNeutral) {
      } else {
        chartInstance->c1_is_UP_START = c1_IN_SettingNeutral;
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 53, 9U, (void *)
          &chartInstance->c1_is_UP_START);
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 54, 385U, (int32_T)
          (chartInstance->c1_is_UP_START == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 55, 383U, (int32_T)
          (chartInstance->c1_is_UP_START == 2));
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 7);
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 45, 693U, 5);
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 53, 9U, 1);
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c1_sfEvent);
        chartInstance->c1_b_tp_SettingNeutral = 1U;
        c1_Clutch_setValue(chartInstance, 80U);
      }
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 63U, chartInstance->c1_sfEvent);
      if (chartInstance->c1_is_UP_START == c1_IN_Default) {
      } else {
        chartInstance->c1_is_UP_START = c1_IN_Default;
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 53, 9U, (void *)
          &chartInstance->c1_is_UP_START);
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 54, 385U, (int32_T)
          (chartInstance->c1_is_UP_START == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 55, 383U, (int32_T)
          (chartInstance->c1_is_UP_START == 2));
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 8);
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 45, 693U, 6);
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 53, 9U, 2);
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
        chartInstance->c1_c_tp_Default = 1U;
        sf_call_output_fcn_call(chartInstance->S, 2, "Efi_setCut", 0);
      }
    }
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(3U, (int32_T)_SFD_CCP_CALL(5U, 3U, 0,
      (chartInstance->c1_sfEvent == c1_event_GearshiftDown) != 0U,
      chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_IDLE = 0U;
      chartInstance->c1_is_GEARSHIFT = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 32, 697U, (int32_T)
        (chartInstance->c1_is_GEARSHIFT == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 42, 18U, (int32_T)
        (chartInstance->c1_is_GEARSHIFT == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 43, 5U, (int32_T)
        (chartInstance->c1_is_GEARSHIFT == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 44, 7U, (int32_T)
        (chartInstance->c1_is_GEARSHIFT == 4));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 45, 693U, (int32_T)
        (chartInstance->c1_is_GEARSHIFT == 5));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 56, 13U, (int32_T)
        (chartInstance->c1_is_GEARSHIFT == 6));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_GEARSHIFT = c1_IN_DOWNSHIFTING;
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 31, 1U, (void *)
        &chartInstance->c1_is_GEARSHIFT);
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 32, 697U, (int32_T)
        (chartInstance->c1_is_GEARSHIFT == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 42, 18U, (int32_T)
        (chartInstance->c1_is_GEARSHIFT == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 43, 5U, (int32_T)
        (chartInstance->c1_is_GEARSHIFT == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 44, 7U, (int32_T)
        (chartInstance->c1_is_GEARSHIFT == 4));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 45, 693U, (int32_T)
        (chartInstance->c1_is_GEARSHIFT == 5));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 56, 13U, (int32_T)
        (chartInstance->c1_is_GEARSHIFT == 6));
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_DOWNSHIFTING = 1U;
      if (chartInstance->c1_is_DOWNSHIFTING == c1_IN_DOWN_START) {
      } else {
        chartInstance->c1_is_DOWNSHIFTING = c1_IN_DOWN_START;
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 32, 697U, (void *)
          &chartInstance->c1_is_DOWNSHIFTING);
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 33, 17U, (int32_T)
          (chartInstance->c1_is_DOWNSHIFTING == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 36, 15U, (int32_T)
          (chartInstance->c1_is_DOWNSHIFTING == 2));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 37, 16U, (int32_T)
          (chartInstance->c1_is_DOWNSHIFTING == 3));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 38, 14U, (int32_T)
          (chartInstance->c1_is_DOWNSHIFTING == 4));
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_DOWN_START = 1U;
        chartInstance->c1_ticksCounter = c1_Gearshift_getTime(chartInstance);
        c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 54, 45U, (void *)
          &chartInstance->c1_ticksCounter);
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_ticksCounter, 13U);
      }

      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 68U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 67U,
                   chartInstance->c1_sfEvent);
      c1_b_temp = _SFD_CCP_CALL(5U, 67U, 0, (chartInstance->c1_is_NEUTRAL_STATE ==
        c1_IN_SET_NEUTRAL) != 0U, chartInstance->c1_sfEvent);
      if (c1_b_temp) {
        c1_b_temp = _SFD_CCP_CALL(5U, 67U, 1, (boolean_T)CV_RELATIONAL_EVAL(5U,
          67U, 0, (real_T)*chartInstance->c1_clutchCurrVal, 80.0, 0, 3U,
          *chartInstance->c1_clutchCurrVal <= 80) != 0U,
          chartInstance->c1_sfEvent);
      }

      c1_d_out = (CV_TRANSITION_EVAL(67U, (int32_T)c1_b_temp) != 0);
      if (c1_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 67U, chartInstance->c1_sfEvent);
        if (chartInstance->c1_is_DOWN_START == c1_b_IN_SettingNeutral) {
        } else {
          chartInstance->c1_is_DOWN_START = c1_b_IN_SettingNeutral;
          c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 38, 14U, (void *)
            &chartInstance->c1_is_DOWN_START);
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 39, 398U, (int32_T)
            (chartInstance->c1_is_DOWN_START == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 40, 406U, (int32_T)
            (chartInstance->c1_is_DOWN_START == 2));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 41, 399U, (int32_T)
            (chartInstance->c1_is_DOWN_START == 3));
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 11);
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 32, 697U, 1);
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 38, 14U, 1);
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
          chartInstance->c1_c_tp_SettingNeutral = 1U;
          c1_Clutch_setValue(chartInstance, 80U);
        }
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 70U, chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 69U,
                     chartInstance->c1_sfEvent);
        c1_c_temp = !_SFD_CCP_CALL(5U, 69U, 0,
          (chartInstance->c1_is_NEUTRAL_STATE == c1_IN_UNSET_NEUTRAL) != 0U,
          chartInstance->c1_sfEvent);
        if (c1_c_temp) {
          c1_c_temp = _SFD_CCP_CALL(5U, 69U, 1, (boolean_T)CV_RELATIONAL_EVAL(5U,
            69U, 0, (real_T)*chartInstance->c1_clutchCurrVal, 60.0, 0, 3U,
            *chartInstance->c1_clutchCurrVal <= 60) != 0U,
            chartInstance->c1_sfEvent);
        }

        c1_e_out = (CV_TRANSITION_EVAL(69U, (int32_T)c1_c_temp) != 0);
        if (c1_e_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 69U, chartInstance->c1_sfEvent);
          if (chartInstance->c1_is_DOWN_START == c1_IN_ChangeClutch) {
          } else {
            chartInstance->c1_is_DOWN_START = c1_IN_ChangeClutch;
            c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 38, 14U, (void *)
              &chartInstance->c1_is_DOWN_START);
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 39, 398U, (int32_T)
              (chartInstance->c1_is_DOWN_START == 1));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 40, 406U, (int32_T)
              (chartInstance->c1_is_DOWN_START == 2));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 41, 399U, (int32_T)
              (chartInstance->c1_is_DOWN_START == 3));
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 16);
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 32, 697U, 6);
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 38, 14U, 2);
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
            chartInstance->c1_tp_ChangeClutch = 1U;
            c1_Clutch_setValue(chartInstance, 60U);
          }
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 71U, chartInstance->c1_sfEvent);
          chartInstance->c1_is_DOWN_START = c1_b_IN_Default;
          c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 38, 14U, (void *)
            &chartInstance->c1_is_DOWN_START);
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 39, 398U, (int32_T)
            (chartInstance->c1_is_DOWN_START == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 40, 406U, (int32_T)
            (chartInstance->c1_is_DOWN_START == 2));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 41, 399U, (int32_T)
            (chartInstance->c1_is_DOWN_START == 3));
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 17);
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 32, 697U, 7);
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 38, 14U, 3);
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
          chartInstance->c1_d_tp_Default = 1U;
        }
      }
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U,
                   chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c1_sfEvent);
}

static void c1_DOWNSHIFTING(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  boolean_T c1_c_out;
  int32_T c1_q0;
  int32_T c1_b_q0;
  int32_T c1_c_q0;
  int32_T c1_q1;
  int32_T c1_b_q1;
  int32_T c1_c_q1;
  boolean_T c1_covSaturation;
  boolean_T c1_b_covSaturation;
  boolean_T c1_c_covSaturation;
  int32_T c1_qY;
  int32_T c1_b_qY;
  int32_T c1_c_qY;
  boolean_T c1_d_out;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_DOWNSHIFTING) {
   case c1_IN_DOWN_BRAKE:
    CV_STATE_EVAL(5, 0, c1_IN_DOWN_BRAKE);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                 chartInstance->c1_sfEvent);
    c1_out = (CV_TRANSITION_EVAL(12U, (int32_T)_SFD_CCP_CALL(5U, 12U, 0,
                (boolean_T)CV_RELATIONAL_EVAL(5U, 12U, 0, (real_T)
      chartInstance->c1_ticksCounter, 1.0, 0, 0U, chartInstance->c1_ticksCounter
      == 1) != 0U, chartInstance->c1_sfEvent)) != 0);
    if (c1_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
      c1_exit_internal_DOWN_BRAKE(chartInstance);
      chartInstance->c1_tp_DOWN_BRAKE = 0U;
      chartInstance->c1_is_DOWNSHIFTING = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 33, 17U, (int32_T)
        (chartInstance->c1_is_DOWNSHIFTING == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 36, 15U, (int32_T)
        (chartInstance->c1_is_DOWNSHIFTING == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 37, 16U, (int32_T)
        (chartInstance->c1_is_DOWNSHIFTING == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 38, 14U, (int32_T)
        (chartInstance->c1_is_DOWNSHIFTING == 4));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 33, 17U, 0);
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 33, 17U, (void *)
        &chartInstance->c1_is_DOWN_BRAKE);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_DOWNSHIFTING = 0U;
      chartInstance->c1_is_GEARSHIFT = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 32, 697U, (int32_T)
        (chartInstance->c1_is_GEARSHIFT == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 42, 18U, (int32_T)
        (chartInstance->c1_is_GEARSHIFT == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 43, 5U, (int32_T)
        (chartInstance->c1_is_GEARSHIFT == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 44, 7U, (int32_T)
        (chartInstance->c1_is_GEARSHIFT == 4));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 45, 693U, (int32_T)
        (chartInstance->c1_is_GEARSHIFT == 5));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 56, 13U, (int32_T)
        (chartInstance->c1_is_GEARSHIFT == 6));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 32, 697U, 0);
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 32, 697U, (void *)
        &chartInstance->c1_is_DOWNSHIFTING);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
      if (chartInstance->c1_is_GEARSHIFT == c1_IN_DOWN_END) {
      } else {
        chartInstance->c1_is_GEARSHIFT = c1_IN_DOWN_END;
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 31, 1U, (void *)
          &chartInstance->c1_is_GEARSHIFT);
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 32, 697U, (int32_T)
          (chartInstance->c1_is_GEARSHIFT == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 42, 18U, (int32_T)
          (chartInstance->c1_is_GEARSHIFT == 2));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 43, 5U, (int32_T)
          (chartInstance->c1_is_GEARSHIFT == 3));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 44, 7U, (int32_T)
          (chartInstance->c1_is_GEARSHIFT == 4));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 45, 693U, (int32_T)
          (chartInstance->c1_is_GEARSHIFT == 5));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 56, 13U, (int32_T)
          (chartInstance->c1_is_GEARSHIFT == 6));
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 18);
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_DOWN_END = 1U;
        sf_call_output_fcn_call(chartInstance->S, 10, "Gearshift_free", 0);
      }
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                   chartInstance->c1_sfEvent);
      c1_q0 = chartInstance->c1_ticksCounter;
      c1_q1 = 1;
      c1_covSaturation = false;
      if ((c1_q1 < 0) && (c1_q0 > c1_q1 + MAX_int32_T)) {
        c1_covSaturation = true;
        c1_qY = MAX_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 17U, 91U, 1U);
      } else if ((c1_q1 > 0) && (c1_q0 < c1_q1 + MIN_int32_T)) {
        c1_covSaturation = true;
        c1_qY = MIN_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 17U, 91U, 1U);
      } else {
        c1_qY = c1_q0 - c1_q1;
      }

      CV_SATURATION_EVAL(4, 6, 0, 0, c1_covSaturation);
      chartInstance->c1_ticksCounter = c1_qY;
      c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 54, 45U, (void *)
        &chartInstance->c1_ticksCounter);
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_ticksCounter, 13U);
      switch (chartInstance->c1_is_DOWN_BRAKE) {
       case c1_IN_ChangeClutch:
        CV_STATE_EVAL(6, 0, c1_IN_ChangeClutch);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                     chartInstance->c1_sfEvent);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c1_sfEvent);
        break;

       case c1_b_IN_Default:
        CV_STATE_EVAL(6, 0, c1_b_IN_Default);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                     chartInstance->c1_sfEvent);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c1_sfEvent);
        break;

       default:
        CV_STATE_EVAL(6, 0, 0);

        /* Unreachable state, for coverage only */
        chartInstance->c1_is_DOWN_BRAKE = c1_IN_NO_ACTIVE_CHILD;
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 34, 410U, (int32_T)
          (chartInstance->c1_is_DOWN_BRAKE == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 35, 409U, (int32_T)
          (chartInstance->c1_is_DOWN_BRAKE == 2));
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
        break;
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c1_sfEvent);
    if (chartInstance->c1_is_GEARSHIFT != c1_IN_DOWNSHIFTING) {
    } else {
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c1_sfEvent);
    }
    break;

   case c1_IN_DOWN_PUSH:
    CV_STATE_EVAL(5, 0, c1_IN_DOWN_PUSH);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                 chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(10U, (int32_T)_SFD_CCP_CALL(5U, 10U, 0,
      (boolean_T)CV_RELATIONAL_EVAL(5U, 10U, 0, (real_T)
      chartInstance->c1_ticksCounter, 1.0, 0, 0U, chartInstance->c1_ticksCounter
      == 1) != 0U, chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_DOWN_PUSH = 0U;
      chartInstance->c1_is_DOWNSHIFTING = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 33, 17U, (int32_T)
        (chartInstance->c1_is_DOWNSHIFTING == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 36, 15U, (int32_T)
        (chartInstance->c1_is_DOWNSHIFTING == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 37, 16U, (int32_T)
        (chartInstance->c1_is_DOWNSHIFTING == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 38, 14U, (int32_T)
        (chartInstance->c1_is_DOWNSHIFTING == 4));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
      if (chartInstance->c1_is_DOWNSHIFTING == c1_IN_DOWN_REBOUND) {
      } else {
        chartInstance->c1_is_DOWNSHIFTING = c1_IN_DOWN_REBOUND;
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 32, 697U, (void *)
          &chartInstance->c1_is_DOWNSHIFTING);
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 33, 17U, (int32_T)
          (chartInstance->c1_is_DOWNSHIFTING == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 36, 15U, (int32_T)
          (chartInstance->c1_is_DOWNSHIFTING == 2));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 37, 16U, (int32_T)
          (chartInstance->c1_is_DOWNSHIFTING == 3));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 38, 14U, (int32_T)
          (chartInstance->c1_is_DOWNSHIFTING == 4));
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 15);
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 32, 697U, 5);
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_DOWN_REBOUND = 1U;
        chartInstance->c1_ticksCounter = c1_Gearshift_getTime(chartInstance);
        c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 54, 45U, (void *)
          &chartInstance->c1_ticksCounter);
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_ticksCounter, 13U);
        sf_call_output_fcn_call(chartInstance->S, 6, "Gearshift_rebound", 0);
      }
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                   chartInstance->c1_sfEvent);
      c1_b_q0 = chartInstance->c1_ticksCounter;
      c1_b_q1 = 1;
      c1_b_covSaturation = false;
      if ((c1_b_q1 < 0) && (c1_b_q0 > c1_b_q1 + MAX_int32_T)) {
        c1_b_covSaturation = true;
        c1_b_qY = MAX_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 15U, 119U, 1U);
      } else if ((c1_b_q1 > 0) && (c1_b_q0 < c1_b_q1 + MIN_int32_T)) {
        c1_b_covSaturation = true;
        c1_b_qY = MIN_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 15U, 119U, 1U);
      } else {
        c1_b_qY = c1_b_q0 - c1_b_q1;
      }

      CV_SATURATION_EVAL(4, 9, 0, 0, c1_b_covSaturation);
      chartInstance->c1_ticksCounter = c1_b_qY;
      c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 54, 45U, (void *)
        &chartInstance->c1_ticksCounter);
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_ticksCounter, 13U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_DOWN_REBOUND:
    CV_STATE_EVAL(5, 0, c1_IN_DOWN_REBOUND);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                 chartInstance->c1_sfEvent);
    c1_c_out = (CV_TRANSITION_EVAL(11U, (int32_T)_SFD_CCP_CALL(5U, 11U, 0,
      (boolean_T)CV_RELATIONAL_EVAL(5U, 11U, 0, (real_T)
      chartInstance->c1_ticksCounter, 1.0, 0, 0U, chartInstance->c1_ticksCounter
      == 1) != 0U, chartInstance->c1_sfEvent)) != 0);
    if (c1_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_DOWN_REBOUND = 0U;
      chartInstance->c1_is_DOWNSHIFTING = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 33, 17U, (int32_T)
        (chartInstance->c1_is_DOWNSHIFTING == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 36, 15U, (int32_T)
        (chartInstance->c1_is_DOWNSHIFTING == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 37, 16U, (int32_T)
        (chartInstance->c1_is_DOWNSHIFTING == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 38, 14U, (int32_T)
        (chartInstance->c1_is_DOWNSHIFTING == 4));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
      if (chartInstance->c1_is_DOWNSHIFTING == c1_IN_DOWN_BRAKE) {
      } else {
        chartInstance->c1_is_DOWNSHIFTING = c1_IN_DOWN_BRAKE;
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 32, 697U, (void *)
          &chartInstance->c1_is_DOWNSHIFTING);
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 33, 17U, (int32_T)
          (chartInstance->c1_is_DOWNSHIFTING == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 36, 15U, (int32_T)
          (chartInstance->c1_is_DOWNSHIFTING == 2));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 37, 16U, (int32_T)
          (chartInstance->c1_is_DOWNSHIFTING == 3));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 38, 14U, (int32_T)
          (chartInstance->c1_is_DOWNSHIFTING == 4));
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_DOWN_BRAKE = 1U;
        chartInstance->c1_ticksCounter = c1_Gearshift_getTime(chartInstance);
        c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 54, 45U, (void *)
          &chartInstance->c1_ticksCounter);
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_ticksCounter, 13U);
      }

      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 73U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 72U,
                   chartInstance->c1_sfEvent);
      c1_d_out = (CV_TRANSITION_EVAL(72U, (int32_T)_SFD_CCP_CALL(5U, 72U, 0,
        (boolean_T)CV_RELATIONAL_EVAL(5U, 72U, 0, (real_T)
        *chartInstance->c1_clutchCurrVal, 81.0, 0, 2U,
        *chartInstance->c1_clutchCurrVal < 81) != 0U, chartInstance->c1_sfEvent))
                  != 0);
      if (c1_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 72U, chartInstance->c1_sfEvent);
        if (chartInstance->c1_is_DOWN_BRAKE == c1_IN_ChangeClutch) {
        } else {
          chartInstance->c1_is_DOWN_BRAKE = c1_IN_ChangeClutch;
          c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 33, 17U, (void *)
            &chartInstance->c1_is_DOWN_BRAKE);
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 34, 410U, (int32_T)
            (chartInstance->c1_is_DOWN_BRAKE == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 35, 409U, (int32_T)
            (chartInstance->c1_is_DOWN_BRAKE == 2));
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 16);
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 32, 697U, 6);
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 33, 17U, 1);
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
          chartInstance->c1_b_tp_ChangeClutch = 1U;
          c1_Clutch_setValue(chartInstance, 80U);
          sf_call_output_fcn_call(chartInstance->S, 9, "Gearshift_brake", 0);
        }
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 74U, chartInstance->c1_sfEvent);
        if (chartInstance->c1_is_DOWN_BRAKE == c1_b_IN_Default) {
        } else {
          chartInstance->c1_is_DOWN_BRAKE = c1_b_IN_Default;
          c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 33, 17U, (void *)
            &chartInstance->c1_is_DOWN_BRAKE);
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 34, 410U, (int32_T)
            (chartInstance->c1_is_DOWN_BRAKE == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 35, 409U, (int32_T)
            (chartInstance->c1_is_DOWN_BRAKE == 2));
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 17);
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 32, 697U, 7);
          c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 33, 17U, 2);
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
          chartInstance->c1_e_tp_Default = 1U;
          sf_call_output_fcn_call(chartInstance->S, 9, "Gearshift_brake", 0);
        }
      }
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                   chartInstance->c1_sfEvent);
      c1_c_q0 = chartInstance->c1_ticksCounter;
      c1_c_q1 = 1;
      c1_c_covSaturation = false;
      if ((c1_c_q1 < 0) && (c1_c_q0 > c1_c_q1 + MAX_int32_T)) {
        c1_c_covSaturation = true;
        c1_c_qY = MAX_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 16U, 120U, 1U);
      } else if ((c1_c_q1 > 0) && (c1_c_q0 < c1_c_q1 + MIN_int32_T)) {
        c1_c_covSaturation = true;
        c1_c_qY = MIN_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 16U, 120U, 1U);
      } else {
        c1_c_qY = c1_c_q0 - c1_c_q1;
      }

      CV_SATURATION_EVAL(4, 10, 0, 0, c1_c_covSaturation);
      chartInstance->c1_ticksCounter = c1_c_qY;
      c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 54, 45U, (void *)
        &chartInstance->c1_ticksCounter);
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_ticksCounter, 13U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_DOWN_START:
    CV_STATE_EVAL(5, 0, c1_IN_DOWN_START);
    c1_DOWN_START(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(5, 0, 0);

    /* Unreachable state, for coverage only */
    chartInstance->c1_is_DOWNSHIFTING = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 33, 17U, (int32_T)
      (chartInstance->c1_is_DOWNSHIFTING == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 36, 15U, (int32_T)
      (chartInstance->c1_is_DOWNSHIFTING == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 37, 16U, (int32_T)
      (chartInstance->c1_is_DOWNSHIFTING == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 38, 14U, (int32_T)
      (chartInstance->c1_is_DOWNSHIFTING == 4));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c1_sfEvent);
    break;
  }
}

static void c1_DOWN_START(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  int32_T c1_q0;
  int32_T c1_q1;
  boolean_T c1_covSaturation;
  int32_T c1_qY;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U, chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(9U, (int32_T)_SFD_CCP_CALL(5U, 9U, 0, (boolean_T)
              CV_RELATIONAL_EVAL(5U, 9U, 0, (real_T)
    chartInstance->c1_ticksCounter, 1.0, 0, 0U, chartInstance->c1_ticksCounter ==
    1) != 0U, chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    c1_exit_internal_DOWN_START(chartInstance);
    chartInstance->c1_tp_DOWN_START = 0U;
    chartInstance->c1_is_DOWNSHIFTING = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 33, 17U, (int32_T)
      (chartInstance->c1_is_DOWNSHIFTING == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 36, 15U, (int32_T)
      (chartInstance->c1_is_DOWNSHIFTING == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 37, 16U, (int32_T)
      (chartInstance->c1_is_DOWNSHIFTING == 3));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 38, 14U, (int32_T)
      (chartInstance->c1_is_DOWNSHIFTING == 4));
    c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 38, 14U, 0);
    c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 38, 14U, (void *)
      &chartInstance->c1_is_DOWN_START);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
    if (chartInstance->c1_is_DOWNSHIFTING == c1_IN_DOWN_PUSH) {
    } else {
      chartInstance->c1_is_DOWNSHIFTING = c1_IN_DOWN_PUSH;
      c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 32, 697U, (void *)
        &chartInstance->c1_is_DOWNSHIFTING);
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 33, 17U, (int32_T)
        (chartInstance->c1_is_DOWNSHIFTING == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 36, 15U, (int32_T)
        (chartInstance->c1_is_DOWNSHIFTING == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 37, 16U, (int32_T)
        (chartInstance->c1_is_DOWNSHIFTING == 3));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 38, 14U, (int32_T)
        (chartInstance->c1_is_DOWNSHIFTING == 4));
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 31, 1U, 14);
      c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 32, 697U, 4);
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_DOWN_PUSH = 1U;
      chartInstance->c1_ticksCounter = c1_Gearshift_getTime(chartInstance);
      c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 54, 45U, (void *)
        &chartInstance->c1_ticksCounter);
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_ticksCounter, 13U);
      sf_call_output_fcn_call(chartInstance->S, 8, "Gearshift_down_push", 0);
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c1_sfEvent);
    c1_q0 = chartInstance->c1_ticksCounter;
    c1_q1 = 1;
    c1_covSaturation = false;
    if ((c1_q1 < 0) && (c1_q0 > c1_q1 + MAX_int32_T)) {
      c1_covSaturation = true;
      c1_qY = MAX_int32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 14U, 92U, 1U);
    } else if ((c1_q1 > 0) && (c1_q0 < c1_q1 + MIN_int32_T)) {
      c1_covSaturation = true;
      c1_qY = MIN_int32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 14U, 92U, 1U);
    } else {
      c1_qY = c1_q0 - c1_q1;
    }

    CV_SATURATION_EVAL(4, 11, 0, 0, c1_covSaturation);
    chartInstance->c1_ticksCounter = c1_qY;
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 54, 45U, (void *)
      &chartInstance->c1_ticksCounter);
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_ticksCounter, 13U);
    switch (chartInstance->c1_is_DOWN_START) {
     case c1_IN_ChangeClutch:
      CV_STATE_EVAL(11, 0, c1_IN_ChangeClutch);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U,
                   chartInstance->c1_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c1_sfEvent);
      break;

     case c1_b_IN_Default:
      CV_STATE_EVAL(11, 0, c1_b_IN_Default);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U,
                   chartInstance->c1_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c1_sfEvent);
      break;

     case c1_b_IN_SettingNeutral:
      CV_STATE_EVAL(11, 0, c1_b_IN_SettingNeutral);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U,
                   chartInstance->c1_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c1_sfEvent);
      break;

     default:
      CV_STATE_EVAL(11, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c1_is_DOWN_START = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 39, 398U, (int32_T)
        (chartInstance->c1_is_DOWN_START == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 40, 406U, (int32_T)
        (chartInstance->c1_is_DOWN_START == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 41, 399U, (int32_T)
        (chartInstance->c1_is_DOWN_START == 3));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
      break;
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c1_sfEvent);
}

static void c1_exit_internal_DOWN_START(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c1_is_DOWN_START) {
   case c1_IN_ChangeClutch:
    CV_STATE_EVAL(11, 1, c1_IN_ChangeClutch);
    chartInstance->c1_tp_ChangeClutch = 0U;
    chartInstance->c1_is_DOWN_START = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 39, 398U, (int32_T)
      (chartInstance->c1_is_DOWN_START == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 40, 406U, (int32_T)
      (chartInstance->c1_is_DOWN_START == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 41, 399U, (int32_T)
      (chartInstance->c1_is_DOWN_START == 3));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
    break;

   case c1_b_IN_Default:
    CV_STATE_EVAL(11, 1, c1_b_IN_Default);
    chartInstance->c1_d_tp_Default = 0U;
    chartInstance->c1_is_DOWN_START = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 39, 398U, (int32_T)
      (chartInstance->c1_is_DOWN_START == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 40, 406U, (int32_T)
      (chartInstance->c1_is_DOWN_START == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 41, 399U, (int32_T)
      (chartInstance->c1_is_DOWN_START == 3));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
    break;

   case c1_b_IN_SettingNeutral:
    CV_STATE_EVAL(11, 1, c1_b_IN_SettingNeutral);
    chartInstance->c1_c_tp_SettingNeutral = 0U;
    chartInstance->c1_is_DOWN_START = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 39, 398U, (int32_T)
      (chartInstance->c1_is_DOWN_START == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 40, 406U, (int32_T)
      (chartInstance->c1_is_DOWN_START == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 41, 399U, (int32_T)
      (chartInstance->c1_is_DOWN_START == 3));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(11, 1, 0);
    chartInstance->c1_is_DOWN_START = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 39, 398U, (int32_T)
      (chartInstance->c1_is_DOWN_START == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 40, 406U, (int32_T)
      (chartInstance->c1_is_DOWN_START == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 41, 399U, (int32_T)
      (chartInstance->c1_is_DOWN_START == 3));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
    break;
  }
}

static void c1_exit_internal_DOWN_BRAKE(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c1_is_DOWN_BRAKE) {
   case c1_IN_ChangeClutch:
    CV_STATE_EVAL(6, 1, c1_IN_ChangeClutch);
    chartInstance->c1_b_tp_ChangeClutch = 0U;
    chartInstance->c1_is_DOWN_BRAKE = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 34, 410U, (int32_T)
      (chartInstance->c1_is_DOWN_BRAKE == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 35, 409U, (int32_T)
      (chartInstance->c1_is_DOWN_BRAKE == 2));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
    break;

   case c1_b_IN_Default:
    CV_STATE_EVAL(6, 1, c1_b_IN_Default);
    chartInstance->c1_e_tp_Default = 0U;
    chartInstance->c1_is_DOWN_BRAKE = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 34, 410U, (int32_T)
      (chartInstance->c1_is_DOWN_BRAKE == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 35, 409U, (int32_T)
      (chartInstance->c1_is_DOWN_BRAKE == 2));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(6, 1, 0);
    chartInstance->c1_is_DOWN_BRAKE = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 34, 410U, (int32_T)
      (chartInstance->c1_is_DOWN_BRAKE == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 35, 409U, (int32_T)
      (chartInstance->c1_is_DOWN_BRAKE == 2));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
    break;
  }
}

static void c1_START_ENGINE(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  boolean_T c1_c_out;
  boolean_T c1_d_out;
  int32_T c1_i59;
  boolean_T c1_e_out;
  boolean_T c1_covSaturation;
  boolean_T guard1 = false;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 71U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_START_ENGINE) {
   case c1_b_IN_START:
    CV_STATE_EVAL(71, 0, c1_b_IN_START);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 94U,
                 chartInstance->c1_sfEvent);
    c1_out = (CV_TRANSITION_EVAL(94U, (int32_T)_SFD_CCP_CALL(5U, 94U, 0,
                (boolean_T)CV_RELATIONAL_EVAL(5U, 94U, 0, (real_T)
      chartInstance->c1_startCounter, 0.0, 0, 3U, chartInstance->c1_startCounter
      <= 0) != 0U, chartInstance->c1_sfEvent)) != 0);
    if (c1_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 94U, chartInstance->c1_sfEvent);
      chartInstance->c1_c_tp_START = 0U;
      chartInstance->c1_is_START_ENGINE = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 58, 482U, (int32_T)
        (chartInstance->c1_is_START_ENGINE == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 59, 483U, (int32_T)
        (chartInstance->c1_is_START_ENGINE == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 60, 494U, (int32_T)
        (chartInstance->c1_is_START_ENGINE == 3));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 72U, chartInstance->c1_sfEvent);
      if (chartInstance->c1_is_START_ENGINE == c1_IN_STOP) {
      } else {
        chartInstance->c1_is_START_ENGINE = c1_IN_STOP;
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 57, 479U, (void *)
          &chartInstance->c1_is_START_ENGINE);
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 58, 482U, (int32_T)
          (chartInstance->c1_is_START_ENGINE == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 59, 483U, (int32_T)
          (chartInstance->c1_is_START_ENGINE == 2));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 60, 494U, (int32_T)
          (chartInstance->c1_is_START_ENGINE == 3));
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 57, 479U, 3);
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 73U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_STOP = 1U;
        sf_call_output_fcn_call(chartInstance->S, 12, "EngineControl_stop", 0);
      }
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 146U,
                   chartInstance->c1_sfEvent);
      c1_d_out = (CV_TRANSITION_EVAL(146U, (int32_T)_SFD_CCP_CALL(5U, 146U, 0,
        (boolean_T)CV_RELATIONAL_EVAL(5U, 146U, 0, (real_T)
        *chartInstance->c1_startEngCom, (real_T)chartInstance->c1_lastCom, 0, 1U,
        *chartInstance->c1_startEngCom != chartInstance->c1_lastCom) != 0U,
        chartInstance->c1_sfEvent)) != 0);
      guard1 = false;
      if (c1_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 146U, chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 93U,
                     chartInstance->c1_sfEvent);
        c1_e_out = (CV_TRANSITION_EVAL(93U, (int32_T)_SFD_CCP_CALL(5U, 93U, 0,
          (boolean_T)CV_RELATIONAL_EVAL(5U, 93U, 1, (real_T)
          *chartInstance->c1_startEngCom, (real_T)chartInstance->c1_lastCom, 0,
          1U, *chartInstance->c1_startEngCom != chartInstance->c1_lastCom) != 0U,
          chartInstance->c1_sfEvent)) != 0);
        if (c1_e_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 93U, chartInstance->c1_sfEvent);
          chartInstance->c1_c_tp_START = 0U;
          chartInstance->c1_is_START_ENGINE = c1_IN_NO_ACTIVE_CHILD;
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 58, 482U, (int32_T)
            (chartInstance->c1_is_START_ENGINE == 1));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 59, 483U, (int32_T)
            (chartInstance->c1_is_START_ENGINE == 2));
          c1_sdiStreamingWrapperFcn(chartInstance, 4, 60, 494U, (int32_T)
            (chartInstance->c1_is_START_ENGINE == 3));
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 72U, chartInstance->c1_sfEvent);
          if (chartInstance->c1_is_START_ENGINE == c1_b_IN_START) {
          } else {
            chartInstance->c1_is_START_ENGINE = c1_b_IN_START;
            c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 57, 479U, (void *)
              &chartInstance->c1_is_START_ENGINE);
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 58, 482U, (int32_T)
              (chartInstance->c1_is_START_ENGINE == 1));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 59, 483U, (int32_T)
              (chartInstance->c1_is_START_ENGINE == 2));
            c1_sdiStreamingWrapperFcn(chartInstance, 4, 60, 494U, (int32_T)
              (chartInstance->c1_is_START_ENGINE == 3));
            c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 57, 479U, 2);
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 72U, chartInstance->c1_sfEvent);
            chartInstance->c1_c_tp_START = 1U;
            sf_call_output_fcn_call(chartInstance->S, 11, "EngineControl_start",
              0);
            chartInstance->c1_lastCom = *chartInstance->c1_startEngCom;
            c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 59, 484U, (void *)
              &chartInstance->c1_lastCom);
            _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastCom, 15U);
            chartInstance->c1_startCounter = 100U;
            c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 60, 488U, (void *)
              &chartInstance->c1_startCounter);
            _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_startCounter, 16U);
          }
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 72U,
                     chartInstance->c1_sfEvent);
        c1_i59 = c1__s32_minus__(chartInstance, (int32_T)
          chartInstance->c1_startCounter, 1, 482U, 120, 1);
        c1_covSaturation = false;
        if (c1_i59 < 0) {
          c1_covSaturation = true;
          c1_i59 = 0;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 482U, 120U, 1U);
        } else {
          if (c1_i59 > 255) {
            c1_i59 = 255;
            _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 482U, 120U, 1U);
          }

          CV_SATURATION_EVAL(4, 72, 0, 0, c1_covSaturation);
        }

        chartInstance->c1_startCounter = (uint8_T)c1_i59;
        c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 60, 488U, (void *)
          &chartInstance->c1_startCounter);
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_startCounter, 16U);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 72U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_STOP:
    CV_STATE_EVAL(71, 0, c1_IN_STOP);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 97U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 93U,
                 chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(93U, (int32_T)_SFD_CCP_CALL(5U, 93U, 0,
      (boolean_T)CV_RELATIONAL_EVAL(5U, 93U, 2, (real_T)
      *chartInstance->c1_startEngCom, (real_T)chartInstance->c1_lastCom, 0, 1U, *
      chartInstance->c1_startEngCom != chartInstance->c1_lastCom) != 0U,
      chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 93U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_STOP = 0U;
      chartInstance->c1_is_START_ENGINE = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 58, 482U, (int32_T)
        (chartInstance->c1_is_START_ENGINE == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 59, 483U, (int32_T)
        (chartInstance->c1_is_START_ENGINE == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 60, 494U, (int32_T)
        (chartInstance->c1_is_START_ENGINE == 3));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 73U, chartInstance->c1_sfEvent);
      if (chartInstance->c1_is_START_ENGINE == c1_b_IN_START) {
      } else {
        chartInstance->c1_is_START_ENGINE = c1_b_IN_START;
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 57, 479U, (void *)
          &chartInstance->c1_is_START_ENGINE);
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 58, 482U, (int32_T)
          (chartInstance->c1_is_START_ENGINE == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 59, 483U, (int32_T)
          (chartInstance->c1_is_START_ENGINE == 2));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 60, 494U, (int32_T)
          (chartInstance->c1_is_START_ENGINE == 3));
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 57, 479U, 2);
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 72U, chartInstance->c1_sfEvent);
        chartInstance->c1_c_tp_START = 1U;
        sf_call_output_fcn_call(chartInstance->S, 11, "EngineControl_start", 0);
        chartInstance->c1_lastCom = *chartInstance->c1_startEngCom;
        c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 59, 484U, (void *)
          &chartInstance->c1_lastCom);
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastCom, 15U);
        chartInstance->c1_startCounter = 100U;
        c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 60, 488U, (void *)
          &chartInstance->c1_startCounter);
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_startCounter, 16U);
      }
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 73U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 73U, chartInstance->c1_sfEvent);
    break;

   case c1_b_IN_WAIT:
    CV_STATE_EVAL(71, 0, c1_b_IN_WAIT);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 96U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 93U,
                 chartInstance->c1_sfEvent);
    c1_c_out = (CV_TRANSITION_EVAL(93U, (int32_T)_SFD_CCP_CALL(5U, 93U, 0,
      (boolean_T)CV_RELATIONAL_EVAL(5U, 93U, 0, (real_T)
      *chartInstance->c1_startEngCom, (real_T)chartInstance->c1_lastCom, 0, 1U, *
      chartInstance->c1_startEngCom != chartInstance->c1_lastCom) != 0U,
      chartInstance->c1_sfEvent)) != 0);
    if (c1_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 93U, chartInstance->c1_sfEvent);
      chartInstance->c1_b_tp_WAIT = 0U;
      chartInstance->c1_is_START_ENGINE = c1_IN_NO_ACTIVE_CHILD;
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 58, 482U, (int32_T)
        (chartInstance->c1_is_START_ENGINE == 1));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 59, 483U, (int32_T)
        (chartInstance->c1_is_START_ENGINE == 2));
      c1_sdiStreamingWrapperFcn(chartInstance, 4, 60, 494U, (int32_T)
        (chartInstance->c1_is_START_ENGINE == 3));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 74U, chartInstance->c1_sfEvent);
      if (chartInstance->c1_is_START_ENGINE == c1_b_IN_START) {
      } else {
        chartInstance->c1_is_START_ENGINE = c1_b_IN_START;
        c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 57, 479U, (void *)
          &chartInstance->c1_is_START_ENGINE);
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 58, 482U, (int32_T)
          (chartInstance->c1_is_START_ENGINE == 1));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 59, 483U, (int32_T)
          (chartInstance->c1_is_START_ENGINE == 2));
        c1_sdiStreamingWrapperFcn(chartInstance, 4, 60, 494U, (int32_T)
          (chartInstance->c1_is_START_ENGINE == 3));
        c1_c_sdiStreamingWrapperFcn(chartInstance, 2, 57, 479U, 2);
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 72U, chartInstance->c1_sfEvent);
        chartInstance->c1_c_tp_START = 1U;
        sf_call_output_fcn_call(chartInstance->S, 11, "EngineControl_start", 0);
        chartInstance->c1_lastCom = *chartInstance->c1_startEngCom;
        c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 59, 484U, (void *)
          &chartInstance->c1_lastCom);
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastCom, 15U);
        chartInstance->c1_startCounter = 100U;
        c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 60, 488U, (void *)
          &chartInstance->c1_startCounter);
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_startCounter, 16U);
      }
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 74U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 74U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(71, 0, 0);

    /* Unreachable state, for coverage only */
    chartInstance->c1_is_START_ENGINE = c1_IN_NO_ACTIVE_CHILD;
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 58, 482U, (int32_T)
      (chartInstance->c1_is_START_ENGINE == 1));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 59, 483U, (int32_T)
      (chartInstance->c1_is_START_ENGINE == 2));
    c1_sdiStreamingWrapperFcn(chartInstance, 4, 60, 494U, (int32_T)
      (chartInstance->c1_is_START_ENGINE == 3));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 72U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 71U, chartInstance->c1_sfEvent);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)(c1_machineNumber);
  (void)(c1_chartNumber);
  (void)(c1_instanceNumber);
}

const mxArray *sf_c1_GCU_Model_genCode_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static void c1_checkClutch(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_temp;
  boolean_T c1_b_temp;
  boolean_T c1_b_out;
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 60U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 60U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 126U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 127U, chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(127U, (int32_T)_SFD_CCP_CALL(5U, 127U, 0,
              (boolean_T)CV_RELATIONAL_EVAL(5U, 127U, 0, (real_T)
    (*chartInstance->c1_clutchCom)[0], (real_T)chartInstance->c1_lastClutchCom,
    0, 1U, (*chartInstance->c1_clutchCom)[0] != chartInstance->c1_lastClutchCom)
              != 0U, chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 127U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 129U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 130U,
                 chartInstance->c1_sfEvent);
    c1_temp = !_SFD_CCP_CALL(5U, 130U, 0, (chartInstance->c1_is_GEARSHIFT ==
      c1_IN_DOWNSHIFTING) != 0U, chartInstance->c1_sfEvent);
    if (c1_temp) {
      c1_temp = !_SFD_CCP_CALL(5U, 130U, 1, (chartInstance->c1_is_NEUTRAL_STATE ==
        c1_IN_SET_NEUTRAL) != 0U, chartInstance->c1_sfEvent);
    }

    c1_b_temp = c1_temp;
    if (!c1_b_temp) {
      c1_b_temp = _SFD_CCP_CALL(5U, 130U, 2, (chartInstance->c1_is_NEUTRAL_STATE
        == c1_IN_UNSET_NEUTRAL) != 0U, chartInstance->c1_sfEvent);
    }

    c1_b_out = (CV_TRANSITION_EVAL(130U, (int32_T)c1_b_temp) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 130U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 132U, chartInstance->c1_sfEvent);
      chartInstance->c1_lastClutchCom = (*chartInstance->c1_clutchCom)[0];
      c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 17, 684U, (void *)
        &chartInstance->c1_lastClutchCom);
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastClutchCom, 3U);
      c1_Clutch_setValue(chartInstance, (*chartInstance->c1_clutchCom)[1]);
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 131U, chartInstance->c1_sfEvent);
    }
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 128U, chartInstance->c1_sfEvent);
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 60U, chartInstance->c1_sfEvent);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 60U, chartInstance->c1_sfEvent);
}

static void c1_checkShift(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  boolean_T c1_c_out;
  int32_T c1_previousEvent;
  boolean_T c1_d_out;
  int32_T c1_b_previousEvent;
  int32_T c1_c_previousEvent;
  boolean_T c1_e_out;
  int32_T c1_d_previousEvent;
  int32_T c1_e_previousEvent;
  int32_T c1_f_previousEvent;
  int32_T c1_g_previousEvent;
  int32_T c1_h_previousEvent;
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 61U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 61U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 122U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 123U, chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(123U, (int32_T)_SFD_CCP_CALL(5U, 123U, 0,
              (boolean_T)CV_RELATIONAL_EVAL(5U, 123U, 0, (real_T)
    (*chartInstance->c1_shiftCom)[0], (real_T)chartInstance->c1_lastShiftCom, 0,
    1U, (*chartInstance->c1_shiftCom)[0] != chartInstance->c1_lastShiftCom) !=
              0U, chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 123U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 124U, chartInstance->c1_sfEvent);
    chartInstance->c1_lastShiftCom = (*chartInstance->c1_shiftCom)[0];
    c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 16, 681U, (void *)
      &chartInstance->c1_lastShiftCom);
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastShiftCom, 4U);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 80U,
                 chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(80U, (int32_T)_SFD_CCP_CALL(5U, 80U, 0,
      (boolean_T)CV_RELATIONAL_EVAL(5U, 80U, 0, (real_T)
      (*chartInstance->c1_shiftCom)[1], (real_T)c1_const_GEAR_COMMAND_UP, 0, 0U,
      (*chartInstance->c1_shiftCom)[1] == c1_const_GEAR_COMMAND_UP) != 0U,
      chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 80U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 81U, chartInstance->c1_sfEvent);
      c1_previousEvent = chartInstance->c1_sfEvent;
      chartInstance->c1_sfEvent = c1_event_GearshiftUp;
      _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_GearshiftUp,
                   chartInstance->c1_sfEvent);
      if (chartInstance->c1_is_active_NEUTRAL_STATE == 0U) {
      } else {
        c1_NEUTRAL_STATE(chartInstance);
      }

      _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_GearshiftUp,
                   chartInstance->c1_sfEvent);
      chartInstance->c1_sfEvent = c1_previousEvent;
      c1_c_previousEvent = chartInstance->c1_sfEvent;
      chartInstance->c1_sfEvent = c1_event_GearshiftUp;
      _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_GearshiftUp,
                   chartInstance->c1_sfEvent);
      if (chartInstance->c1_is_active_GEARSHIFT == 0U) {
      } else {
        c1_GEARSHIFT(chartInstance);
      }

      _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_GearshiftUp,
                   chartInstance->c1_sfEvent);
      chartInstance->c1_sfEvent = c1_c_previousEvent;
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 82U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 83U,
                   chartInstance->c1_sfEvent);
      c1_c_out = (CV_TRANSITION_EVAL(83U, (int32_T)_SFD_CCP_CALL(5U, 83U, 0,
        (boolean_T)CV_RELATIONAL_EVAL(5U, 83U, 0, (real_T)
        (*chartInstance->c1_shiftCom)[1], (real_T)c1_const_GEAR_COMMAND_DOWN, 0,
        0U, (*chartInstance->c1_shiftCom)[1] == c1_const_GEAR_COMMAND_DOWN) !=
        0U, chartInstance->c1_sfEvent)) != 0);
      if (c1_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 83U, chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 84U, chartInstance->c1_sfEvent);
        c1_b_previousEvent = chartInstance->c1_sfEvent;
        chartInstance->c1_sfEvent = c1_event_GearshiftDown;
        _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_GearshiftDown,
                     chartInstance->c1_sfEvent);
        if (chartInstance->c1_is_active_NEUTRAL_STATE == 0U) {
        } else {
          c1_NEUTRAL_STATE(chartInstance);
        }

        _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_GearshiftDown,
                     chartInstance->c1_sfEvent);
        chartInstance->c1_sfEvent = c1_b_previousEvent;
        c1_e_previousEvent = chartInstance->c1_sfEvent;
        chartInstance->c1_sfEvent = c1_event_GearshiftDown;
        _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_GearshiftDown,
                     chartInstance->c1_sfEvent);
        if (chartInstance->c1_is_active_GEARSHIFT == 0U) {
        } else {
          c1_GEARSHIFT(chartInstance);
        }

        _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_GearshiftDown,
                     chartInstance->c1_sfEvent);
        chartInstance->c1_sfEvent = c1_e_previousEvent;
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 85U, chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 86U,
                     chartInstance->c1_sfEvent);
        c1_d_out = (CV_TRANSITION_EVAL(86U, (int32_T)_SFD_CCP_CALL(5U, 86U, 0,
          (boolean_T)CV_RELATIONAL_EVAL(5U, 86U, 0, (real_T)
          (*chartInstance->c1_shiftCom)[1], (real_T)
          c1_const_GEAR_COMMAND_NEUTRAL_UP, 0, 0U, (*chartInstance->c1_shiftCom)
          [1] == c1_const_GEAR_COMMAND_NEUTRAL_UP) != 0U,
          chartInstance->c1_sfEvent)) != 0);
        if (c1_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 86U, chartInstance->c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 87U, chartInstance->c1_sfEvent);
          c1_d_previousEvent = chartInstance->c1_sfEvent;
          chartInstance->c1_sfEvent = c1_event_GearshiftSetNeutral;
          _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_GearshiftSetNeutral,
                       chartInstance->c1_sfEvent);
          if (chartInstance->c1_is_active_NEUTRAL_STATE == 0U) {
          } else {
            c1_NEUTRAL_STATE(chartInstance);
          }

          _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_GearshiftSetNeutral,
                       chartInstance->c1_sfEvent);
          chartInstance->c1_sfEvent = c1_d_previousEvent;
          c1_g_previousEvent = chartInstance->c1_sfEvent;
          chartInstance->c1_sfEvent = c1_event_GearshiftUp;
          _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_GearshiftUp,
                       chartInstance->c1_sfEvent);
          if (chartInstance->c1_is_active_GEARSHIFT == 0U) {
          } else {
            c1_GEARSHIFT(chartInstance);
          }

          _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_GearshiftUp,
                       chartInstance->c1_sfEvent);
          chartInstance->c1_sfEvent = c1_g_previousEvent;
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 88U, chartInstance->c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 89U,
                       chartInstance->c1_sfEvent);
          c1_e_out = (CV_TRANSITION_EVAL(89U, (int32_T)_SFD_CCP_CALL(5U, 89U, 0,
            (boolean_T)CV_RELATIONAL_EVAL(5U, 89U, 0, (real_T)
            (*chartInstance->c1_shiftCom)[1], (real_T)
            c1_const_GEAR_COMMAND_NEUTRAL_DOWN, 0, 0U,
            (*chartInstance->c1_shiftCom)[1] ==
            c1_const_GEAR_COMMAND_NEUTRAL_DOWN) != 0U, chartInstance->c1_sfEvent))
                      != 0);
          if (c1_e_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 89U, chartInstance->c1_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 90U, chartInstance->c1_sfEvent);
            c1_f_previousEvent = chartInstance->c1_sfEvent;
            chartInstance->c1_sfEvent = c1_event_GearshiftSetNeutral;
            _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG,
                         c1_event_GearshiftSetNeutral, chartInstance->c1_sfEvent);
            if (chartInstance->c1_is_active_NEUTRAL_STATE == 0U) {
            } else {
              c1_NEUTRAL_STATE(chartInstance);
            }

            _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_GearshiftSetNeutral,
                         chartInstance->c1_sfEvent);
            chartInstance->c1_sfEvent = c1_f_previousEvent;
            c1_h_previousEvent = chartInstance->c1_sfEvent;
            chartInstance->c1_sfEvent = c1_event_GearshiftDown;
            _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_GearshiftDown,
                         chartInstance->c1_sfEvent);
            if (chartInstance->c1_is_active_GEARSHIFT == 0U) {
            } else {
              c1_GEARSHIFT(chartInstance);
            }

            _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_GearshiftDown,
                         chartInstance->c1_sfEvent);
            chartInstance->c1_sfEvent = c1_h_previousEvent;
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 91U, chartInstance->c1_sfEvent);
          }
        }
      }
    }
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 125U, chartInstance->c1_sfEvent);
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 61U, chartInstance->c1_sfEvent);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 61U, chartInstance->c1_sfEvent);
}

static void c1_aacCheckShift(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  int32_T c1_i60;
  int32_T c1_q0;
  int32_T c1_q1;
  boolean_T c1_covSaturation;
  int32_T c1_qY;
  int32_T c1_i61;
  boolean_T c1_b_out;
  int32_T c1_i62;
  int32_T c1_b_q0;
  int32_T c1_b_q1;
  boolean_T c1_b_covSaturation;
  int32_T c1_b_qY;
  int32_T c1_i63;
  boolean_T c1_c_out;
  int32_T c1_previousEvent;
  int32_T c1_i64;
  boolean_T c1_c_covSaturation;
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 40U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 40U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 113U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 133U, chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(133U, (int32_T)_SFD_CCP_CALL(5U, 133U, 0,
              (boolean_T)CV_RELATIONAL_EVAL(5U, 133U, 0, (real_T)
    chartInstance->c1_lastShift, (real_T)*chartInstance->c1_currentGear, 0, 0U,
    chartInstance->c1_lastShift == *chartInstance->c1_currentGear) != 0U,
              chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 133U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 134U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 114U,
                 chartInstance->c1_sfEvent);
    c1_i60 = (*chartInstance->c1_acc_externValues)[sf_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 605U, 1, 16, 23U, (int32_T)
       acc_values_RPM, 0, 2)];
    c1_q0 = c1__u8_s32_(chartInstance, (int32_T)acc_params_RPM_LIMIT_1_2, 605U,
                        44, 14) + *chartInstance->c1_currentGear;
    c1_q1 = 1;
    c1_covSaturation = false;
    if ((c1_q1 < 0) && (c1_q0 > c1_q1 + MAX_int32_T)) {
      c1_covSaturation = true;
      c1_qY = MAX_int32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 605U, 44U, 14U);
    } else if ((c1_q1 > 0) && (c1_q0 < c1_q1 + MIN_int32_T)) {
      c1_covSaturation = true;
      c1_qY = MIN_int32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 605U, 44U, 14U);
    } else {
      c1_qY = c1_q0 - c1_q1;
    }

    CV_SATURATION_EVAL(5, 114, 0, 0, c1_covSaturation);
    c1_i61 = (*chartInstance->c1_acc_parameters)[sf_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 605U, 44, 14, 26U, c1_qY,
       0, 15)];
    c1_b_out = (CV_TRANSITION_EVAL(114U, (int32_T)_SFD_CCP_CALL(5U, 114U, 0,
      (boolean_T)CV_RELATIONAL_EVAL(5U, 114U, 0, (real_T)c1_i60, (real_T)c1_i61,
      0, 5U, c1_i60 >= c1_i61) != 0U, chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 114U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 116U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 117U,
                   chartInstance->c1_sfEvent);
      c1_i62 = (*chartInstance->c1_acc_externValues)[sf_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 611U, 1, 16, 23U,
         (int32_T)acc_values_WHEEL_SPEED, 0, 2)];
      c1_b_q0 = c1__u8_s32_(chartInstance, (int32_T)acc_params_SPEED_LIMIT_1_2,
                            611U, 52, 14) + *chartInstance->c1_currentGear;
      c1_b_q1 = 1;
      c1_b_covSaturation = false;
      if ((c1_b_q1 < 0) && (c1_b_q0 > c1_b_q1 + MAX_int32_T)) {
        c1_b_covSaturation = true;
        c1_b_qY = MAX_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 611U, 52U, 14U);
      } else if ((c1_b_q1 > 0) && (c1_b_q0 < c1_b_q1 + MIN_int32_T)) {
        c1_b_covSaturation = true;
        c1_b_qY = MIN_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 611U, 52U, 14U);
      } else {
        c1_b_qY = c1_b_q0 - c1_b_q1;
      }

      CV_SATURATION_EVAL(5, 117, 0, 0, c1_b_covSaturation);
      c1_i63 = (*chartInstance->c1_acc_parameters)[sf_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 611U, 52, 14, 26U,
         c1_b_qY, 0, 15)];
      c1_c_out = (CV_TRANSITION_EVAL(117U, (int32_T)_SFD_CCP_CALL(5U, 117U, 0,
        (boolean_T)CV_RELATIONAL_EVAL(5U, 117U, 0, (real_T)c1_i62, (real_T)
        c1_i63, 0, 5U, c1_i62 >= c1_i63) != 0U, chartInstance->c1_sfEvent)) != 0);
      if (c1_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 117U, chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 119U, chartInstance->c1_sfEvent);
        c1_previousEvent = chartInstance->c1_sfEvent;
        chartInstance->c1_sfEvent = c1_event_GearshiftUp;
        _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_GearshiftUp,
                     chartInstance->c1_sfEvent);
        if (chartInstance->c1_is_active_GEARSHIFT == 0U) {
        } else {
          c1_GEARSHIFT(chartInstance);
        }

        _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_GearshiftUp,
                     chartInstance->c1_sfEvent);
        chartInstance->c1_sfEvent = c1_previousEvent;
        c1_i64 = c1__s32_add__(chartInstance, (int32_T)
          chartInstance->c1_lastShift, 1, 615U, 53, 1);
        c1_c_covSaturation = false;
        if (c1_i64 < 0) {
          c1_c_covSaturation = true;
          c1_i64 = 0;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 615U, 53U, 1U);
        } else {
          if (c1_i64 > 255) {
            c1_i64 = 255;
            _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 615U, 53U, 1U);
          }

          CV_SATURATION_EVAL(5, 119, 0, 0, c1_c_covSaturation);
        }

        chartInstance->c1_lastShift = (uint8_T)c1_i64;
        c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 8, 715U, (void *)
          &chartInstance->c1_lastShift);
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastShift, 18U);
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 118U, chartInstance->c1_sfEvent);
      }
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 115U, chartInstance->c1_sfEvent);
    }
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 135U, chartInstance->c1_sfEvent);
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 40U, chartInstance->c1_sfEvent);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 40U, chartInstance->c1_sfEvent);
}

static int32_T c1_getAacParam(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, c1_acc_params c1_index)
{
  int32_T c1_param;
  int32_T c1_b_param;
  _SFD_SET_DATA_VALUE_PTR(59U, (void *)&c1_param);
  _SFD_SET_DATA_VALUE_PTR(56U, (void *)&c1_index);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 42U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(2U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("index", &c1_index, c1_k_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("param", &c1_param, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 42U, chartInstance->c1_sfEvent);
  c1_param = 0;
  _SFD_DATA_RANGE_CHECK((real_T)c1_param, 59U);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 108U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 109U, chartInstance->c1_sfEvent);
  c1_param = (*chartInstance->c1_acc_parameters)[sf_array_bounds_check
    (sfGlobalDebugInstanceStruct, chartInstance->S, 571U, 9, 14, 26U, (int32_T)
     c1_index, 0, 15)];
  _SFD_DATA_RANGE_CHECK((real_T)c1_param, 59U);
  c1_b_param = c1_param;
  sf_mex_printf("%s =\\n", "param");
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 12, c1_b_param);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 42U, chartInstance->c1_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(59U);
  _SFD_UNSET_DATA_VALUE_PTR(56U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 42U, chartInstance->c1_sfEvent);
  return c1_param;
}

static void c1_autoXCheckShift(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  int32_T c1_i65;
  int32_T c1_q0;
  int32_T c1_q1;
  boolean_T c1_covSaturation;
  int32_T c1_qY;
  int32_T c1_i66;
  boolean_T c1_b_out;
  int32_T c1_i67;
  int32_T c1_b_q0;
  int32_T c1_b_q1;
  boolean_T c1_b_covSaturation;
  int32_T c1_b_qY;
  int32_T c1_i68;
  boolean_T c1_c_out;
  int32_T c1_previousEvent;
  int32_T c1_i69;
  boolean_T c1_c_covSaturation;
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 53U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 53U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 167U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 168U, chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(168U, (int32_T)_SFD_CCP_CALL(5U, 168U, 0,
              (boolean_T)CV_RELATIONAL_EVAL(5U, 168U, 0, (real_T)
    chartInstance->c1_lastShift, (real_T)*chartInstance->c1_currentGear, 0, 0U,
    chartInstance->c1_lastShift == *chartInstance->c1_currentGear) != 0U,
              chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 168U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 170U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 171U,
                 chartInstance->c1_sfEvent);
    c1_i65 = (*chartInstance->c1_acc_externValues)[sf_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1019U, 1, 16, 23U,
       (int32_T)acc_values_RPM, 0, 2)];
    c1_q0 = c1__u8_s32_(chartInstance, (int32_T)autoX_params_AUTOX_RPM_LIMIT_1_2,
                        1019U, 44, 16) + *chartInstance->c1_currentGear;
    c1_q1 = 1;
    c1_covSaturation = false;
    if ((c1_q1 < 0) && (c1_q0 > c1_q1 + MAX_int32_T)) {
      c1_covSaturation = true;
      c1_qY = MAX_int32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1019U, 44U, 16U);
    } else if ((c1_q1 > 0) && (c1_q0 < c1_q1 + MIN_int32_T)) {
      c1_covSaturation = true;
      c1_qY = MIN_int32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1019U, 44U, 16U);
    } else {
      c1_qY = c1_q0 - c1_q1;
    }

    CV_SATURATION_EVAL(5, 171, 0, 0, c1_covSaturation);
    c1_i66 = (*chartInstance->c1_autoX_parameters)[sf_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1019U, 44, 16, 29U, c1_qY,
       0, 15)];
    c1_b_out = (CV_TRANSITION_EVAL(171U, (int32_T)_SFD_CCP_CALL(5U, 171U, 0,
      (boolean_T)CV_RELATIONAL_EVAL(5U, 171U, 0, (real_T)c1_i65, (real_T)c1_i66,
      0, 5U, c1_i65 >= c1_i66) != 0U, chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 171U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 173U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 174U,
                   chartInstance->c1_sfEvent);
      c1_i67 = (*chartInstance->c1_acc_externValues)[sf_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1022U, 1, 16, 23U,
         (int32_T)acc_values_WHEEL_SPEED, 0, 2)];
      c1_b_q0 = c1__u8_s32_(chartInstance, (int32_T)
                            autoX_params_AUTOX_SPEED_LIMIT_1_2, 1022U, 52, 16) +
        *chartInstance->c1_currentGear;
      c1_b_q1 = 1;
      c1_b_covSaturation = false;
      if ((c1_b_q1 < 0) && (c1_b_q0 > c1_b_q1 + MAX_int32_T)) {
        c1_b_covSaturation = true;
        c1_b_qY = MAX_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1022U, 52U, 16U);
      } else if ((c1_b_q1 > 0) && (c1_b_q0 < c1_b_q1 + MIN_int32_T)) {
        c1_b_covSaturation = true;
        c1_b_qY = MIN_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1022U, 52U, 16U);
      } else {
        c1_b_qY = c1_b_q0 - c1_b_q1;
      }

      CV_SATURATION_EVAL(5, 174, 0, 0, c1_b_covSaturation);
      c1_i68 = (*chartInstance->c1_autoX_parameters)[sf_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1022U, 52, 16, 29U,
         c1_b_qY, 0, 15)];
      c1_c_out = (CV_TRANSITION_EVAL(174U, (int32_T)_SFD_CCP_CALL(5U, 174U, 0,
        (boolean_T)CV_RELATIONAL_EVAL(5U, 174U, 0, (real_T)c1_i67, (real_T)
        c1_i68, 0, 5U, c1_i67 >= c1_i68) != 0U, chartInstance->c1_sfEvent)) != 0);
      if (c1_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 174U, chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 176U, chartInstance->c1_sfEvent);
        c1_previousEvent = chartInstance->c1_sfEvent;
        chartInstance->c1_sfEvent = c1_event_GearshiftUp;
        _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_GearshiftUp,
                     chartInstance->c1_sfEvent);
        if (chartInstance->c1_is_active_GEARSHIFT == 0U) {
        } else {
          c1_GEARSHIFT(chartInstance);
        }

        _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_GearshiftUp,
                     chartInstance->c1_sfEvent);
        chartInstance->c1_sfEvent = c1_previousEvent;
        c1_i69 = c1__s32_add__(chartInstance, (int32_T)
          chartInstance->c1_lastShift, 1, 1024U, 53, 1);
        c1_c_covSaturation = false;
        if (c1_i69 < 0) {
          c1_c_covSaturation = true;
          c1_i69 = 0;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1024U, 53U, 1U);
        } else {
          if (c1_i69 > 255) {
            c1_i69 = 255;
            _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1024U, 53U, 1U);
          }

          CV_SATURATION_EVAL(5, 176, 0, 0, c1_c_covSaturation);
        }

        chartInstance->c1_lastShift = (uint8_T)c1_i69;
        c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 8, 715U, (void *)
          &chartInstance->c1_lastShift);
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_lastShift, 18U);
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 175U, chartInstance->c1_sfEvent);
      }
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 172U, chartInstance->c1_sfEvent);
    }
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 169U, chartInstance->c1_sfEvent);
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 53U, chartInstance->c1_sfEvent);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 53U, chartInstance->c1_sfEvent);
}

static int32_T c1_getAutoXParam(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, c1_autoX_params c1_index)
{
  int32_T c1_param;
  int32_T c1_b_param;
  _SFD_SET_DATA_VALUE_PTR(60U, (void *)&c1_param);
  _SFD_SET_DATA_VALUE_PTR(58U, (void *)&c1_index);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 55U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(2U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("index", &c1_index, c1_l_sf_marshallOut,
    c1_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("param", &c1_param, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 55U, chartInstance->c1_sfEvent);
  c1_param = 0;
  _SFD_DATA_RANGE_CHECK((real_T)c1_param, 60U);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 177U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 178U, chartInstance->c1_sfEvent);
  c1_param = (*chartInstance->c1_autoX_parameters)[sf_array_bounds_check
    (sfGlobalDebugInstanceStruct, chartInstance->S, 1037U, 9, 16, 29U, (int32_T)
     c1_index, 0, 15)];
  _SFD_DATA_RANGE_CHECK((real_T)c1_param, 60U);
  c1_b_param = c1_param;
  sf_mex_printf("%s =\\n", "param");
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 12, c1_b_param);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 55U, chartInstance->c1_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(60U);
  _SFD_UNSET_DATA_VALUE_PTR(58U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 55U, chartInstance->c1_sfEvent);
  return c1_param;
}

static int32_T c1_Gearshift_getTime(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  int32_T c1_time;
  boolean_T c1_out;
  boolean_T c1_b_out;
  boolean_T c1_c_out;
  boolean_T c1_d_out;
  boolean_T c1_e_out;
  boolean_T c1_f_out;
  boolean_T c1_g_out;
  boolean_T c1_h_out;
  int32_T c1_b_time;
  boolean_T c1_i_out;
  boolean_T c1_j_out;
  boolean_T c1_k_out;
  int32_T c1_c_time;
  boolean_T c1_l_out;
  boolean_T c1_m_out;
  int32_T c1_d_time;
  boolean_T c1_n_out;
  boolean_T c1_o_out;
  int32_T c1_e_time;
  int32_T c1_f_time;
  int32_T c1_g_time;
  _SFD_SET_DATA_VALUE_PTR(61U, (void *)&c1_time);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("time", &c1_time, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U, chartInstance->c1_sfEvent);
  c1_time = 0;
  _SFD_DATA_RANGE_CHECK((real_T)c1_time, 61U);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 20U, chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(20U, (int32_T)_SFD_CCP_CALL(5U, 20U, 0,
              (chartInstance->c1_is_UPSHIFTING == c1_IN_UP_START) != 0U,
              chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 34U,
                 chartInstance->c1_sfEvent);
    c1_c_out = (CV_TRANSITION_EVAL(34U, (int32_T)_SFD_CCP_CALL(5U, 34U, 0,
      (chartInstance->c1_is_NEUTRAL_STATE == c1_IN_SET_NEUTRAL) != 0U,
      chartInstance->c1_sfEvent)) != 0);
    if (c1_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
      c1_time = (*chartInstance->c1_timings)[sf_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 276U, 14, 7, 27U,
         (int32_T)DEFAULT_NT_CLUTCH_DELAY, 0, 23)];
      _SFD_DATA_RANGE_CHECK((real_T)c1_time, 61U);
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
      c1_time = (*chartInstance->c1_timings)[sf_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 323U, 14, 7, 27U,
         (int32_T)DELAY, 0, 23)];
      _SFD_DATA_RANGE_CHECK((real_T)c1_time, 61U);
    }
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 22U,
                 chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(22U, (int32_T)_SFD_CCP_CALL(5U, 22U, 0,
      (chartInstance->c1_is_UPSHIFTING == c1_IN_UP_PUSH) != 0U,
      chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 48U,
                   chartInstance->c1_sfEvent);
      c1_e_out = (CV_TRANSITION_EVAL(48U, (int32_T)_SFD_CCP_CALL(5U, 48U, 0,
        (chartInstance->c1_is_NEUTRAL_STATE == c1_IN_SET_NEUTRAL) != 0U,
        chartInstance->c1_sfEvent)) != 0);
      if (c1_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 48U, chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 56U, chartInstance->c1_sfEvent);
        c1_time = (*chartInstance->c1_timings)[sf_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 364U, 14, 7, 27U,
           (int32_T)NT_CLUTCH_DELAY, 0, 23)];
        _SFD_DATA_RANGE_CHECK((real_T)c1_time, 61U);
        c1_b_time = c1_time;
        sf_mex_printf("%s =\\n", "time");
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 12,
                          c1_b_time);
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 49U, chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 46U,
                     chartInstance->c1_sfEvent);
        c1_h_out = (CV_TRANSITION_EVAL(46U, (int32_T)_SFD_CCP_CALL(5U, 46U, 0,
          (boolean_T)CV_RELATIONAL_EVAL(5U, 46U, 0, (real_T)
          *chartInstance->c1_currentGear, 1.0, 0, 0U,
          *chartInstance->c1_currentGear == 1) != 0U, chartInstance->c1_sfEvent))
                    != 0);
        if (c1_h_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 46U, chartInstance->c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 57U, chartInstance->c1_sfEvent);
          c1_time = (*chartInstance->c1_timings)[sf_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 366U, 14, 7, 27U,
             (int32_T)UP_PUSH_1_2, 0, 23)];
          _SFD_DATA_RANGE_CHECK((real_T)c1_time, 61U);
          c1_c_time = c1_time;
          sf_mex_printf("%s =\\n", "time");
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 12,
                            c1_c_time);
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 52U, chartInstance->c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 51U,
                       chartInstance->c1_sfEvent);
          c1_k_out = (CV_TRANSITION_EVAL(51U, (int32_T)_SFD_CCP_CALL(5U, 51U, 0,
            (boolean_T)CV_RELATIONAL_EVAL(5U, 51U, 0, (real_T)
            *chartInstance->c1_currentGear, 2.0, 0, 0U,
            *chartInstance->c1_currentGear == 2) != 0U,
            chartInstance->c1_sfEvent)) != 0);
          if (c1_k_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 51U, chartInstance->c1_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 58U, chartInstance->c1_sfEvent);
            c1_time = (*chartInstance->c1_timings)[sf_array_bounds_check
              (sfGlobalDebugInstanceStruct, chartInstance->S, 368U, 14, 7, 27U,
               (int32_T)UP_PUSH_2_3, 0, 23)];
            _SFD_DATA_RANGE_CHECK((real_T)c1_time, 61U);
            c1_d_time = c1_time;
            sf_mex_printf("%s =\\n", "time");
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 12,
                              c1_d_time);
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 50U, chartInstance->c1_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 54U,
                         chartInstance->c1_sfEvent);
            c1_m_out = (CV_TRANSITION_EVAL(54U, (int32_T)_SFD_CCP_CALL(5U, 54U,
              0, (boolean_T)CV_RELATIONAL_EVAL(5U, 54U, 0, (real_T)
              *chartInstance->c1_currentGear, 3.0, 0, 0U,
              *chartInstance->c1_currentGear == 3) != 0U,
              chartInstance->c1_sfEvent)) != 0);
            if (c1_m_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 54U, chartInstance->c1_sfEvent);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 59U, chartInstance->c1_sfEvent);
              c1_time = (*chartInstance->c1_timings)[sf_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 370U, 14, 7, 27U,
                 (int32_T)UP_PUSH_3_4, 0, 23)];
              _SFD_DATA_RANGE_CHECK((real_T)c1_time, 61U);
              c1_e_time = c1_time;
              sf_mex_printf("%s =\\n", "time");
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 12,
                                c1_e_time);
            } else {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 55U, chartInstance->c1_sfEvent);
              _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 47U,
                           chartInstance->c1_sfEvent);
              c1_o_out = (CV_TRANSITION_EVAL(47U, (int32_T)_SFD_CCP_CALL(5U, 47U,
                0, (boolean_T)CV_RELATIONAL_EVAL(5U, 47U, 0, (real_T)
                *chartInstance->c1_currentGear, 4.0, 0, 0U,
                *chartInstance->c1_currentGear == 4) != 0U,
                chartInstance->c1_sfEvent)) != 0);
              if (c1_o_out) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 47U,
                             chartInstance->c1_sfEvent);
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 60U,
                             chartInstance->c1_sfEvent);
                c1_time = (*chartInstance->c1_timings)[sf_array_bounds_check
                  (sfGlobalDebugInstanceStruct, chartInstance->S, 372U, 14, 7,
                   27U, (int32_T)UP_PUSH_4_5, 0, 23)];
                _SFD_DATA_RANGE_CHECK((real_T)c1_time, 61U);
                c1_g_time = c1_time;
                sf_mex_printf("%s =\\n", "time");
                sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                  12, c1_g_time);
              } else {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 53U,
                             chartInstance->c1_sfEvent);
                c1_time = (*chartInstance->c1_timings)[sf_array_bounds_check
                  (sfGlobalDebugInstanceStruct, chartInstance->S, 357U, 14, 7,
                   27U, (int32_T)UP_PUSH_2_3, 0, 23)];
                _SFD_DATA_RANGE_CHECK((real_T)c1_time, 61U);
                c1_f_time = c1_time;
                sf_mex_printf("%s =\\n", "time");
                sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                  12, c1_f_time);
              }
            }
          }
        }
      }
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 24U,
                   chartInstance->c1_sfEvent);
      c1_d_out = (CV_TRANSITION_EVAL(24U, (int32_T)_SFD_CCP_CALL(5U, 24U, 0,
        (chartInstance->c1_is_UPSHIFTING == c1_IN_UP_REBOUND) != 0U,
        chartInstance->c1_sfEvent)) != 0);
      if (c1_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 37U,
                     chartInstance->c1_sfEvent);
        c1_g_out = (CV_TRANSITION_EVAL(37U, (int32_T)_SFD_CCP_CALL(5U, 37U, 0,
          (chartInstance->c1_is_NEUTRAL_STATE == c1_IN_SET_NEUTRAL) != 0U,
          chartInstance->c1_sfEvent)) != 0);
        if (c1_g_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 37U, chartInstance->c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
          c1_time = (*chartInstance->c1_timings)[sf_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 329U, 14, 7, 27U,
             (int32_T)NT_REBOUND_1_N, 0, 23)];
          _SFD_DATA_RANGE_CHECK((real_T)c1_time, 61U);
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 38U, chartInstance->c1_sfEvent);
          c1_time = (*chartInstance->c1_timings)[sf_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 328U, 14, 7, 27U,
             (int32_T)UP_REBOUND, 0, 23)];
          _SFD_DATA_RANGE_CHECK((real_T)c1_time, 61U);
        }
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 26U,
                     chartInstance->c1_sfEvent);
        c1_f_out = (CV_TRANSITION_EVAL(26U, (int32_T)_SFD_CCP_CALL(5U, 26U, 0,
          (chartInstance->c1_is_UPSHIFTING == c1_IN_UP_BRAKE) != 0U,
          chartInstance->c1_sfEvent)) != 0);
        if (c1_f_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, chartInstance->c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 40U,
                       chartInstance->c1_sfEvent);
          c1_j_out = (CV_TRANSITION_EVAL(40U, (int32_T)_SFD_CCP_CALL(5U, 40U, 0,
            (chartInstance->c1_is_NEUTRAL_STATE == c1_IN_SET_NEUTRAL) != 0U,
            chartInstance->c1_sfEvent)) != 0);
          if (c1_j_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 40U, chartInstance->c1_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 42U, chartInstance->c1_sfEvent);
            c1_time = (*chartInstance->c1_timings)[sf_array_bounds_check
              (sfGlobalDebugInstanceStruct, chartInstance->S, 335U, 14, 7, 27U,
               (int32_T)NT_BRAKE_1_N, 0, 23)];
            _SFD_DATA_RANGE_CHECK((real_T)c1_time, 61U);
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 41U, chartInstance->c1_sfEvent);
            c1_time = (*chartInstance->c1_timings)[sf_array_bounds_check
              (sfGlobalDebugInstanceStruct, chartInstance->S, 334U, 14, 7, 27U,
               (int32_T)UP_BRAKE, 0, 23)];
            _SFD_DATA_RANGE_CHECK((real_T)c1_time, 61U);
          }
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 28U,
                       chartInstance->c1_sfEvent);
          c1_i_out = (CV_TRANSITION_EVAL(28U, (int32_T)_SFD_CCP_CALL(5U, 28U, 0,
            (chartInstance->c1_is_DOWNSHIFTING == c1_IN_DOWN_START) != 0U,
            chartInstance->c1_sfEvent)) != 0);
          if (c1_i_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 43U, chartInstance->c1_sfEvent);
            c1_time = (*chartInstance->c1_timings)[sf_array_bounds_check
              (sfGlobalDebugInstanceStruct, chartInstance->S, 337U, 14, 7, 27U,
               (int32_T)CLUTCH, 0, 23)];
            _SFD_DATA_RANGE_CHECK((real_T)c1_time, 61U);
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, chartInstance->c1_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 30U,
                         chartInstance->c1_sfEvent);
            c1_l_out = (CV_TRANSITION_EVAL(30U, (int32_T)_SFD_CCP_CALL(5U, 30U,
              0, (chartInstance->c1_is_DOWNSHIFTING == c1_IN_DOWN_PUSH) != 0U,
              chartInstance->c1_sfEvent)) != 0);
            if (c1_l_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 44U, chartInstance->c1_sfEvent);
              c1_time = (*chartInstance->c1_timings)[sf_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 339U, 14, 7, 27U,
                 (int32_T)DN_PUSH, 0, 23)];
              _SFD_DATA_RANGE_CHECK((real_T)c1_time, 61U);
            } else {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, chartInstance->c1_sfEvent);
              _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 32U,
                           chartInstance->c1_sfEvent);
              c1_n_out = (CV_TRANSITION_EVAL(32U, (int32_T)_SFD_CCP_CALL(5U, 32U,
                0, (chartInstance->c1_is_DOWNSHIFTING == c1_IN_DOWN_REBOUND) !=
                0U, chartInstance->c1_sfEvent)) != 0);
              if (c1_n_out) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U,
                             chartInstance->c1_sfEvent);
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 45U,
                             chartInstance->c1_sfEvent);
                c1_time = (*chartInstance->c1_timings)[sf_array_bounds_check
                  (sfGlobalDebugInstanceStruct, chartInstance->S, 341U, 14, 7,
                   27U, (int32_T)DN_REBOUND, 0, 23)];
                _SFD_DATA_RANGE_CHECK((real_T)c1_time, 61U);
              } else {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U,
                             chartInstance->c1_sfEvent);
                c1_time = (*chartInstance->c1_timings)[sf_array_bounds_check
                  (sfGlobalDebugInstanceStruct, chartInstance->S, 270U, 14, 7,
                   27U, (int32_T)DN_BRAKE, 0, 23)];
                _SFD_DATA_RANGE_CHECK((real_T)c1_time, 61U);
              }
            }
          }
        }
      }
    }
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(61U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c1_sfEvent);
  return c1_time;
}

static void c1_Clutch_setValue(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, uint8_T c1_setValue)
{
  _SFD_DATA_RANGE_CHECK((real_T)c1_setValue, 57U);
  _SFD_SET_DATA_VALUE_PTR(57U, (void *)&c1_setValue);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("setValue", &c1_setValue, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 98U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 99U, chartInstance->c1_sfEvent);
  *chartInstance->c1_clutchCurrVal = c1_setValue;
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 1, 123U, (void *)
    chartInstance->c1_clutchCurrVal);
  _SFD_DATA_RANGE_CHECK_MIN_MAX((real_T)*chartInstance->c1_clutchCurrVal, 30U,
    0.0, 100.0, 506U, 1, 25);
  sf_call_output_fcn_call(chartInstance->S, 0, "Clutch_set", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(57U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc1_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c1_b_sfEvent, const char_T *c1_identifier)
{
  int32_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  return c1_y;
}

static int32_T c1_b_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i70;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i70, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i70;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc1_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  uint8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc1_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static uint8_T c1_c_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c1_b_tp_MODES, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_MODES),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_MODES);
  return c1_y;
}

static uint8_T c1_d_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u16;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u16, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u16;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_tp_MODES;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  SFc1_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc1_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c1_b_tp_MODES = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_MODES),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_MODES);
  *(uint8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i71;
  const mxArray *c1_y = NULL;
  uint16_T c1_u[2];
  SFc1_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc1_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  for (c1_i71 = 0; c1_i71 < 2; c1_i71++) {
    c1_u[c1_i71] = (*(uint16_T (*)[2])c1_inData)[c1_i71];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 5, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_e_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c1_b_lastModeCom, const char_T *c1_identifier,
  uint16_T c1_y[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_lastModeCom), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_b_lastModeCom);
}

static void c1_f_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  uint16_T c1_y[2])
{
  uint16_T c1_uv0[2];
  int32_T c1_i72;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_uv0, 1, 5, 0U, 1, 0U, 1, 2);
  for (c1_i72 = 0; c1_i72 < 2; c1_i72++) {
    c1_y[c1_i72] = c1_uv0[c1_i72];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_lastModeCom;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint16_T c1_y[2];
  int32_T c1_i73;
  SFc1_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc1_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c1_b_lastModeCom = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_lastModeCom), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_b_lastModeCom);
  for (c1_i73 = 0; c1_i73 < 2; c1_i73++) {
    (*(uint16_T (*)[2])c1_outData)[c1_i73] = c1_y[c1_i73];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i74;
  const mxArray *c1_y = NULL;
  uint16_T c1_u[2];
  SFc1_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc1_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  for (c1_i74 = 0; c1_i74 < 2; c1_i74++) {
    c1_u[c1_i74] = (*(uint16_T (*)[2])c1_inData)[c1_i74];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 5, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i75;
  const mxArray *c1_y = NULL;
  uint16_T c1_u[3];
  SFc1_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc1_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  for (c1_i75 = 0; c1_i75 < 3; c1_i75++) {
    c1_u[c1_i75] = (*(uint16_T (*)[3])c1_inData)[c1_i75];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 5, 0U, 1U, 0U, 2, 1, 3), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i76;
  const mxArray *c1_y = NULL;
  uint8_T c1_u[2];
  SFc1_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc1_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  for (c1_i76 = 0; c1_i76 < 2; c1_i76++) {
    c1_u[c1_i76] = (*(uint8_T (*)[2])c1_inData)[c1_i76];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 3, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  uint16_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc1_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint16_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static uint16_T c1_g_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c1_b_stateFb, const char_T *c1_identifier)
{
  uint16_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_stateFb),
    &c1_thisId);
  sf_mex_destroy(&c1_b_stateFb);
  return c1_y;
}

static uint16_T c1_h_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint16_T c1_y;
  uint16_T c1_u17;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u17, 1, 5, 0U, 0, 0U, 0);
  c1_y = c1_u17;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_stateFb;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint16_T c1_y;
  SFc1_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc1_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c1_b_stateFb = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_stateFb),
    &c1_thisId);
  sf_mex_destroy(&c1_b_stateFb);
  *(uint16_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i77;
  const mxArray *c1_y = NULL;
  int32_T c1_u[16];
  SFc1_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc1_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  for (c1_i77 = 0; c1_i77 < 16; c1_i77++) {
    c1_u[c1_i77] = (*(int32_T (*)[16])c1_inData)[c1_i77];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 6, 0U, 1U, 0U, 2, 1, 16), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i78;
  const mxArray *c1_y = NULL;
  int32_T c1_u[24];
  SFc1_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc1_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  for (c1_i78 = 0; c1_i78 < 24; c1_i78++) {
    c1_u[c1_i78] = (*(int32_T (*)[24])c1_inData)[c1_i78];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 6, 0U, 1U, 0U, 2, 1, 24), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc1_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_i_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c1_b_aac_clutchValue, const char_T
  *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_aac_clutchValue),
    &c1_thisId);
  sf_mex_destroy(&c1_b_aac_clutchValue);
  return c1_y;
}

static real_T c1_j_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d6;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d6, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d6;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_aac_clutchValue;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc1_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c1_b_aac_clutchValue = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_aac_clutchValue),
    &c1_thisId);
  sf_mex_destroy(&c1_b_aac_clutchValue);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_k_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  c1_acc_params c1_u;
  const mxArray *c1_y = NULL;
  int32_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_m0 = NULL;
  SFc1_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc1_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(c1_acc_params *)c1_inData;
  c1_y = NULL;
  sf_mex_check_enum("acc_params", 12, c1_sv0, c1_iv0);
  c1_b_u = (int32_T)c1_u;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_m0, c1_b_y, false);
  sf_mex_assign(&c1_y, sf_mex_create_enum("acc_params", c1_m0), false);
  sf_mex_destroy(&c1_m0);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static c1_acc_params c1_k_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  c1_acc_params c1_y;
  (void)chartInstance;
  sf_mex_check_enum("acc_params", 12, c1_sv0, c1_iv0);
  sf_mex_check_builtin(c1_parentId, c1_u, "acc_params", 0, 0U, NULL);
  c1_y = (c1_acc_params)sf_mex_get_enum_element(c1_u, 0);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_index;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  c1_acc_params c1_y;
  SFc1_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc1_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c1_index = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_index), &c1_thisId);
  sf_mex_destroy(&c1_index);
  *(c1_acc_params *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_l_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  c1_autoX_params c1_u;
  const mxArray *c1_y = NULL;
  int32_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_m1 = NULL;
  SFc1_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc1_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(c1_autoX_params *)c1_inData;
  c1_y = NULL;
  sf_mex_check_enum("autoX_params", 12, c1_sv1, c1_iv0);
  c1_b_u = (int32_T)c1_u;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_m1, c1_b_y, false);
  sf_mex_assign(&c1_y, sf_mex_create_enum("autoX_params", c1_m1), false);
  sf_mex_destroy(&c1_m1);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static c1_autoX_params c1_l_emlrt_marshallIn
  (SFc1_GCU_Model_genCodeInstanceStruct *chartInstance, const mxArray *c1_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  c1_autoX_params c1_y;
  (void)chartInstance;
  sf_mex_check_enum("autoX_params", 12, c1_sv1, c1_iv0);
  sf_mex_check_builtin(c1_parentId, c1_u, "autoX_params", 0, 0U, NULL);
  c1_y = (c1_autoX_params)sf_mex_get_enum_element(c1_u, 0);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_index;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  c1_autoX_params c1_y;
  SFc1_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc1_GCU_Model_genCodeInstanceStruct *)chartInstanceVoid;
  c1_index = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_index), &c1_thisId);
  sf_mex_destroy(&c1_index);
  *(c1_autoX_params *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static void c1_m_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c1_u)
{
  uint16_T c1_uv1[2];
  int32_T c1_i79;
  *chartInstance->c1_clutchCurrVal = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 0)), "clutchCurrVal");
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 1, 123U, (void *)
    chartInstance->c1_clutchCurrVal);
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
                        "lastModeCom", c1_uv1);
  for (c1_i79 = 0; c1_i79 < 2; c1_i79++) {
    (*chartInstance->c1_lastModeCom)[c1_i79] = c1_uv1[c1_i79];
  }

  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 834U, (void *)
    chartInstance->c1_lastModeCom);
  *chartInstance->c1_stateFb = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 2)), "stateFb");
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 10, 833U, (void *)
    chartInstance->c1_stateFb);
  chartInstance->c1_aacCounter = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 3)), "aacCounter");
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 29, 550U, (void *)
    &chartInstance->c1_aacCounter);
  chartInstance->c1_aac_clutchStep = c1_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 4)), "aac_clutchStep");
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 31, 563U, (void *)
    &chartInstance->c1_aac_clutchStep);
  chartInstance->c1_aac_clutchValue = c1_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 5)), "aac_clutchValue");
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 30, 561U, (void *)
    &chartInstance->c1_aac_clutchValue);
  chartInstance->c1_aac_dtRelease = c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 6)), "aac_dtRelease");
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 32, 564U, (void *)
    &chartInstance->c1_aac_dtRelease);
  chartInstance->c1_autoXCounter = c1_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 7)), "autoXCounter");
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 48, 958U, (void *)
    &chartInstance->c1_autoXCounter);
  chartInstance->c1_autoX_clutchStep = c1_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 8)), "autoX_clutchStep");
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 50, 960U, (void *)
    &chartInstance->c1_autoX_clutchStep);
  chartInstance->c1_autoX_clutchValue = c1_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 9)), "autoX_clutchValue");
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 49, 959U, (void *)
    &chartInstance->c1_autoX_clutchValue);
  chartInstance->c1_autoX_dtRelease = c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 10)), "autoX_dtRelease");
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 51, 961U, (void *)
    &chartInstance->c1_autoX_dtRelease);
  chartInstance->c1_buzzerCounter = c1_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 11)), "buzzerCounter");
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 19, 1063U, (void *)
    &chartInstance->c1_buzzerCounter);
  chartInstance->c1_counterWait = c1_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 12)), "counterWait");
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 58, 950U, (void *)
    &chartInstance->c1_counterWait);
  chartInstance->c1_lastAacCom = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 13)), "lastAacCom");
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 15, 627U, (void *)
    &chartInstance->c1_lastAacCom);
  chartInstance->c1_lastAutoXCom = c1_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 14)), "lastAutoXCom");
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 18, 1043U, (void *)
    &chartInstance->c1_lastAutoXCom);
  chartInstance->c1_lastClutchCom = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 15)), "lastClutchCom");
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 17, 684U, (void *)
    &chartInstance->c1_lastClutchCom);
  chartInstance->c1_lastCom = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 16)), "lastCom");
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 59, 484U, (void *)
    &chartInstance->c1_lastCom);
  chartInstance->c1_lastShift = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 17)), "lastShift");
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 8, 715U, (void *)
    &chartInstance->c1_lastShift);
  chartInstance->c1_lastShiftCom = c1_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 18)), "lastShiftCom");
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 16, 681U, (void *)
    &chartInstance->c1_lastShiftCom);
  chartInstance->c1_startCounter = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 19)), "startCounter");
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 60, 488U, (void *)
    &chartInstance->c1_startCounter);
  chartInstance->c1_ticksCounter = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 20)), "ticksCounter");
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 54, 45U, (void *)
    &chartInstance->c1_ticksCounter);
  chartInstance->c1_timerCounter = c1_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 21)), "timerCounter");
  c1_d_sdiStreamingWrapperFcn(chartInstance, 0, 61, 938U, (void *)
    &chartInstance->c1_timerCounter);
  chartInstance->c1_is_active_c1_GCU_Model_genCode = c1_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 22)),
     "is_active_c1_GCU_Model_genCode");
  chartInstance->c1_is_active_GEARSHIFT = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 23)), "is_active_GEARSHIFT");
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 31, 1U, (int32_T)
    (chartInstance->c1_is_active_GEARSHIFT == 1));
  chartInstance->c1_is_active_NEUTRAL_STATE = c1_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 24)),
     "is_active_NEUTRAL_STATE");
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 26, 31U, (int32_T)
    (chartInstance->c1_is_active_NEUTRAL_STATE == 1));
  chartInstance->c1_is_active_MODES = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 25)), "is_active_MODES");
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 1, 418U, (int32_T)
    (chartInstance->c1_is_active_MODES == 1));
  chartInstance->c1_is_active_START_ENGINE = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 26)), "is_active_START_ENGINE");
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 57, 479U, (int32_T)
    (chartInstance->c1_is_active_START_ENGINE == 1));
  chartInstance->c1_is_active_SCAN_ADC = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 27)), "is_active_SCAN_ADC");
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 61, 929U, (int32_T)
    (chartInstance->c1_is_active_SCAN_ADC == 1));
  chartInstance->c1_is_active_EEPROM_TRIGGER = c1_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 28)),
     "is_active_EEPROM_TRIGGER");
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 64, 940U, (int32_T)
    (chartInstance->c1_is_active_EEPROM_TRIGGER == 1));
  chartInstance->c1_is_GEARSHIFT = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 29)), "is_GEARSHIFT");
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 31, 1U, (void *)
    &chartInstance->c1_is_GEARSHIFT);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 32, 697U, (int32_T)
    (chartInstance->c1_is_GEARSHIFT == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 42, 18U, (int32_T)
    (chartInstance->c1_is_GEARSHIFT == 2));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 43, 5U, (int32_T)
    (chartInstance->c1_is_GEARSHIFT == 3));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 44, 7U, (int32_T)
    (chartInstance->c1_is_GEARSHIFT == 4));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 45, 693U, (int32_T)
    (chartInstance->c1_is_GEARSHIFT == 5));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 56, 13U, (int32_T)
    (chartInstance->c1_is_GEARSHIFT == 6));
  chartInstance->c1_is_UP_START = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 30)), "is_UP_START");
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 53, 9U, (void *)
    &chartInstance->c1_is_UP_START);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 54, 385U, (int32_T)
    (chartInstance->c1_is_UP_START == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 55, 383U, (int32_T)
    (chartInstance->c1_is_UP_START == 2));
  chartInstance->c1_is_UP_PUSH = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 31)), "is_UP_PUSH");
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 47, 10U, (void *)
    &chartInstance->c1_is_UP_PUSH);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 48, 423U, (int32_T)
    (chartInstance->c1_is_UP_PUSH == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 49, 422U, (int32_T)
    (chartInstance->c1_is_UP_PUSH == 2));
  chartInstance->c1_is_UP_REBOUND = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 32)), "is_UP_REBOUND");
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 50, 11U, (void *)
    &chartInstance->c1_is_UP_REBOUND);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 51, 390U, (int32_T)
    (chartInstance->c1_is_UP_REBOUND == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 52, 391U, (int32_T)
    (chartInstance->c1_is_UP_REBOUND == 2));
  chartInstance->c1_is_DOWN_START = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 33)), "is_DOWN_START");
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 38, 14U, (void *)
    &chartInstance->c1_is_DOWN_START);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 39, 398U, (int32_T)
    (chartInstance->c1_is_DOWN_START == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 40, 406U, (int32_T)
    (chartInstance->c1_is_DOWN_START == 2));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 41, 399U, (int32_T)
    (chartInstance->c1_is_DOWN_START == 3));
  chartInstance->c1_is_DOWN_BRAKE = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 34)), "is_DOWN_BRAKE");
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 33, 17U, (void *)
    &chartInstance->c1_is_DOWN_BRAKE);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 34, 410U, (int32_T)
    (chartInstance->c1_is_DOWN_BRAKE == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 35, 409U, (int32_T)
    (chartInstance->c1_is_DOWN_BRAKE == 2));
  chartInstance->c1_is_NEUTRAL_STATE = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 35)), "is_NEUTRAL_STATE");
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 26, 31U, (void *)
    &chartInstance->c1_is_NEUTRAL_STATE);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 27, 36U, (int32_T)
    (chartInstance->c1_is_NEUTRAL_STATE == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 28, 32U, (int32_T)
    (chartInstance->c1_is_NEUTRAL_STATE == 2));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 29, 34U, (int32_T)
    (chartInstance->c1_is_NEUTRAL_STATE == 3));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 30, 35U, (int32_T)
    (chartInstance->c1_is_NEUTRAL_STATE == 4));
  chartInstance->c1_is_MODES = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 36)), "is_MODES");
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 1, 418U, (void *)
    &chartInstance->c1_is_MODES);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 2, 820U, (int32_T)
    (chartInstance->c1_is_MODES == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 12, 951U, (int32_T)
    (chartInstance->c1_is_MODES == 2));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 22, 429U, (int32_T)
    (chartInstance->c1_is_MODES == 3));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 23, 727U, (int32_T)
    (chartInstance->c1_is_MODES == 4));
  chartInstance->c1_is_ACC = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 37)), "is_ACC");
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 3, 434U, (void *)
    &chartInstance->c1_is_ACC);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 4, 538U, (int32_T)
    (chartInstance->c1_is_ACC == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 10, 515U, (int32_T)
    (chartInstance->c1_is_ACC == 2));
  chartInstance->c1_is_START_ENGINE = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 38)), "is_START_ENGINE");
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 57, 479U, (void *)
    &chartInstance->c1_is_START_ENGINE);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 58, 482U, (int32_T)
    (chartInstance->c1_is_START_ENGINE == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 59, 483U, (int32_T)
    (chartInstance->c1_is_START_ENGINE == 2));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 60, 494U, (int32_T)
    (chartInstance->c1_is_START_ENGINE == 3));
  chartInstance->c1_is_ACTIVE = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 39)), "is_ACTIVE");
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 4, 538U, (void *)
    &chartInstance->c1_is_ACTIVE);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 5, 545U, (int32_T)
    (chartInstance->c1_is_ACTIVE == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 6, 544U, (int32_T)
    (chartInstance->c1_is_ACTIVE == 2));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 7, 514U, (int32_T)
    (chartInstance->c1_is_ACTIVE == 3));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 8, 543U, (int32_T)
    (chartInstance->c1_is_ACTIVE == 4));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 9, 547U, (int32_T)
    (chartInstance->c1_is_ACTIVE == 5));
  chartInstance->c1_is_UPSHIFTING = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 40)), "is_UPSHIFTING");
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 45, 693U, (void *)
    &chartInstance->c1_is_UPSHIFTING);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 46, 12U, (int32_T)
    (chartInstance->c1_is_UPSHIFTING == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 47, 10U, (int32_T)
    (chartInstance->c1_is_UPSHIFTING == 2));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 50, 11U, (int32_T)
    (chartInstance->c1_is_UPSHIFTING == 3));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 53, 9U, (int32_T)
    (chartInstance->c1_is_UPSHIFTING == 4));
  chartInstance->c1_is_DOWNSHIFTING = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 41)), "is_DOWNSHIFTING");
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 32, 697U, (void *)
    &chartInstance->c1_is_DOWNSHIFTING);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 33, 17U, (int32_T)
    (chartInstance->c1_is_DOWNSHIFTING == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 36, 15U, (int32_T)
    (chartInstance->c1_is_DOWNSHIFTING == 2));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 37, 16U, (int32_T)
    (chartInstance->c1_is_DOWNSHIFTING == 3));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 38, 14U, (int32_T)
    (chartInstance->c1_is_DOWNSHIFTING == 4));
  chartInstance->c1_is_MANUAL_MODES = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 42)), "is_MANUAL_MODES");
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 23, 727U, (void *)
    &chartInstance->c1_is_MANUAL_MODES);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 24, 729U, (int32_T)
    (chartInstance->c1_is_MANUAL_MODES == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 25, 728U, (int32_T)
    (chartInstance->c1_is_MANUAL_MODES == 2));
  chartInstance->c1_is_ACCELERATION = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 43)), "is_ACCELERATION");
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 2, 820U, (void *)
    &chartInstance->c1_is_ACCELERATION);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 3, 434U, (int32_T)
    (chartInstance->c1_is_ACCELERATION == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 11, 821U, (int32_T)
    (chartInstance->c1_is_ACCELERATION == 2));
  chartInstance->c1_is_SCAN_ADC = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 44)), "is_SCAN_ADC");
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 61, 929U, (void *)
    &chartInstance->c1_is_SCAN_ADC);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 62, 932U, (int32_T)
    (chartInstance->c1_is_SCAN_ADC == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 63, 930U, (int32_T)
    (chartInstance->c1_is_SCAN_ADC == 2));
  chartInstance->c1_is_EEPROM_TRIGGER = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 45)), "is_EEPROM_TRIGGER");
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 64, 940U, (void *)
    &chartInstance->c1_is_EEPROM_TRIGGER);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 65, 946U, (int32_T)
    (chartInstance->c1_is_EEPROM_TRIGGER == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 66, 944U, (int32_T)
    (chartInstance->c1_is_EEPROM_TRIGGER == 2));
  chartInstance->c1_is_AUTOCROSS = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 46)), "is_AUTOCROSS");
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 12, 951U, (void *)
    &chartInstance->c1_is_AUTOCROSS);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 13, 952U, (int32_T)
    (chartInstance->c1_is_AUTOCROSS == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 14, 974U, (int32_T)
    (chartInstance->c1_is_AUTOCROSS == 2));
  chartInstance->c1_is_LAUNCH = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 47)), "is_LAUNCH");
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 14, 974U, (void *)
    &chartInstance->c1_is_LAUNCH);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 15, 985U, (int32_T)
    (chartInstance->c1_is_LAUNCH == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 21, 1028U, (int32_T)
    (chartInstance->c1_is_LAUNCH == 2));
  chartInstance->c1_b_is_ACTIVE = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 48)), "is_ACTIVE");
  c1_b_sdiStreamingWrapperFcn(chartInstance, 1, 15, 985U, (void *)
    &chartInstance->c1_b_is_ACTIVE);
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 16, 999U, (int32_T)
    (chartInstance->c1_b_is_ACTIVE == 1));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 17, 1025U, (int32_T)
    (chartInstance->c1_b_is_ACTIVE == 2));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 18, 1002U, (int32_T)
    (chartInstance->c1_b_is_ACTIVE == 3));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 19, 998U, (int32_T)
    (chartInstance->c1_b_is_ACTIVE == 4));
  c1_sdiStreamingWrapperFcn(chartInstance, 4, 20, 1001U, (int32_T)
    (chartInstance->c1_b_is_ACTIVE == 5));
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 49)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c1_u);
}

static const mxArray *c1_n_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  sf_mex_assign(&c1_y, c1_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId), false);
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static const mxArray *c1_o_emlrt_marshallIn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  (void)c1_parentId;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), false);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static const mxArray *sf_get_hover_data_for_msg
  (SFc1_GCU_Model_genCodeInstanceStruct *chartInstance, int32_T c1_ssid)
{
  (void)chartInstance;
  (void)c1_ssid;
  return NULL;
}

static void c1_init_sf_message_store_memory(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static int32_T c1_div_nzp_s32(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, int32_T c1_numerator, int32_T c1_denominator, uint32_T
  c1_ssid_src_loc, int32_T c1_offset_src_loc, int32_T c1_length_src_loc)
{
  int32_T c1_quotient;
  uint32_T c1_absNumerator;
  uint32_T c1_absDenominator;
  boolean_T c1_quotientNeedsNegation;
  uint32_T c1_tempAbsQuotient;
  (void)chartInstance;
  (void)c1_ssid_src_loc;
  (void)c1_offset_src_loc;
  (void)c1_length_src_loc;
  if (c1_numerator < 0) {
    c1_absNumerator = ~(uint32_T)c1_numerator + 1U;
  } else {
    c1_absNumerator = (uint32_T)c1_numerator;
  }

  if (c1_denominator < 0) {
    c1_absDenominator = ~(uint32_T)c1_denominator + 1U;
  } else {
    c1_absDenominator = (uint32_T)c1_denominator;
  }

  c1_quotientNeedsNegation = ((c1_numerator < 0) != (c1_denominator < 0));
  c1_tempAbsQuotient = c1_absNumerator / c1_absDenominator;
  if (c1_quotientNeedsNegation) {
    c1_quotient = -(int32_T)c1_tempAbsQuotient;
  } else {
    c1_quotient = (int32_T)c1_tempAbsQuotient;
  }

  return c1_quotient;
}

static int32_T c1__s32_add__(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance,
  int32_T c1_b, int32_T c1_c, uint32_T c1_ssid_src_loc, int32_T
  c1_offset_src_loc, int32_T c1_length_src_loc)
{
  int32_T c1_a;
  (void)chartInstance;
  c1_a = c1_b + c1_c;
  if (((c1_a ^ c1_b) & (c1_a ^ c1_c)) < 0) {
    _SFD_OVERFLOW_DETECTION(SFDB_OVERFLOW, c1_ssid_src_loc, c1_offset_src_loc,
      c1_length_src_loc);
  }

  return c1_a;
}

static int32_T c1__s32_minus__(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, int32_T c1_b, int32_T c1_c, uint32_T c1_ssid_src_loc, int32_T
  c1_offset_src_loc, int32_T c1_length_src_loc)
{
  int32_T c1_a;
  (void)chartInstance;
  c1_a = c1_b - c1_c;
  if (((c1_b ^ c1_a) & (c1_b ^ c1_c)) < 0) {
    _SFD_OVERFLOW_DETECTION(SFDB_OVERFLOW, c1_ssid_src_loc, c1_offset_src_loc,
      c1_length_src_loc);
  }

  return c1_a;
}

static uint8_T c1__u8_s32_(SFc1_GCU_Model_genCodeInstanceStruct *chartInstance,
  int32_T c1_b, uint32_T c1_ssid_src_loc, int32_T c1_offset_src_loc, int32_T
  c1_length_src_loc)
{
  uint8_T c1_a;
  (void)chartInstance;
  c1_a = (uint8_T)c1_b;
  if (c1_a != c1_b) {
    _SFD_OVERFLOW_DETECTION(SFDB_OVERFLOW, c1_ssid_src_loc, c1_offset_src_loc,
      c1_length_src_loc);
  }

  return c1_a;
}

static void c1_sdiStreamingWrapperFcn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, int32_T c1_modeFlag, int32_T c1_ssidIdx, uint32_T c1_ssid,
  int32_T c1_streamedData)
{
  if (chartInstance->c1_sdiLoggedStatesBuffer[c1_ssidIdx] & (uint8_T)c1_modeFlag)
  {
    sdi_update_self_activity_signal(&chartInstance->c1_sdiBlockInfo, c1_ssid,
      c1_streamedData);
  }
}

static void c1_b_sdiStreamingWrapperFcn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, int32_T c1_modeFlag, int32_T c1_ssidIdx, uint32_T c1_ssid,
  void *c1_streamedData)
{
  if (chartInstance->c1_sdiLoggedStatesBuffer[c1_ssidIdx] & (uint8_T)c1_modeFlag)
  {
    sdi_stream_child_activity_signal(&chartInstance->c1_sdiBlockInfo, c1_ssid,
      c1_streamedData);
  }
}

static void c1_c_sdiStreamingWrapperFcn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, int32_T c1_modeFlag, int32_T c1_ssidIdx, uint32_T c1_ssid,
  int32_T c1_streamedData)
{
  if (chartInstance->c1_sdiLoggedStatesBuffer[c1_ssidIdx] & (uint8_T)c1_modeFlag)
  {
    sdi_update_leaf_activity_signal(&chartInstance->c1_sdiBlockInfo, c1_ssid,
      c1_streamedData);
  }
}

static void c1_d_sdiStreamingWrapperFcn(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance, int32_T c1_modeFlag, int32_T c1_ssidIdx, uint32_T c1_ssid,
  void *c1_streamedData)
{
  (void)c1_modeFlag;
  if (chartInstance->c1_sdiLoggedDataBuffer[c1_ssidIdx]) {
    sdi_stream_data_signal(&chartInstance->c1_sdiBlockInfo, c1_ssid,
      c1_streamedData);
  }
}

static void init_test_point_addr_map(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  chartInstance->c1_testPointAddrMap[0] = chartInstance->c1_clutchCurrVal;
  chartInstance->c1_testPointAddrMap[1] = &chartInstance->c1_aacCounter;
  chartInstance->c1_testPointAddrMap[2] = &chartInstance->c1_autoXCounter;
}

static void **get_test_point_address_map(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  return &chartInstance->c1_testPointAddrMap[0];
}

static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info
  (SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  return &chartInstance->c1_testPointMappingInfo;
}

static void **get_dataset_logging_obj_vector
  (SFc1_GCU_Model_genCodeInstanceStruct *chartInstance)
{
  return &chartInstance->c1_dataSetLogObjVector[0];
}

static void init_dsm_address_info(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_GCU_Model_genCodeInstanceStruct
  *chartInstance)
{
  chartInstance->c1_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c1_currentGear = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c1_clutchCurrVal = (uint8_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_lastModeCom = (uint16_T (*)[2])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_shiftCom = (uint16_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_startEngCom = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_aacCom = (uint16_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c1_acc_externValues = (uint16_T (*)[3])
    ssGetInputPortSignal_wrapper(chartInstance->S, 4);
  chartInstance->c1_clutchCom = (uint8_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c1_modeCom = (uint16_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c1_stateFb = (uint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c1_acc_parameters = (int32_T (*)[16])
    ssGetInputPortSignal_wrapper(chartInstance->S, 7);
  chartInstance->c1_timings = (int32_T (*)[24])ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c1_autoXCom = (uint16_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c1_autoX_parameters = (int32_T (*)[16])
    ssGetInputPortSignal_wrapper(chartInstance->S, 10);
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

static void init_test_point_mapping_info(SimStruct *S);
void sf_c1_GCU_Model_genCode_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(233981660U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3905960136U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1462000162U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4119951599U);
}

mxArray* sf_c1_GCU_Model_genCode_get_post_codegen_info(void);
mxArray *sf_c1_GCU_Model_genCode_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("RpNUr07ogOwh588o4UFuLH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,11,3,dataFields);

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
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(2);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(2);
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
      pr[1] = (double)(3);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(2);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(16);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(24);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(16);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c1_GCU_Model_genCode_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_GCU_Model_genCode_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_GCU_Model_genCode_jit_fallback_info(void)
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

mxArray *sf_c1_GCU_Model_genCode_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c1_GCU_Model_genCode_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c1_GCU_Model_genCode(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[123],T\"clutchCurrVal\",},{M[1],M[834],T\"lastModeCom\",},{M[1],M[833],T\"stateFb\",},{M[3],M[550],T\"aacCounter\",},{M[3],M[563],T\"aac_clutchStep\",},{M[3],M[561],T\"aac_clutchValue\",},{M[3],M[564],T\"aac_dtRelease\",},{M[3],M[958],T\"autoXCounter\",},{M[3],M[960],T\"autoX_clutchStep\",},{M[3],M[959],T\"autoX_clutchValue\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[961],T\"autoX_dtRelease\",},{M[3],M[1063],T\"buzzerCounter\",},{M[3],M[950],T\"counterWait\",},{M[3],M[627],T\"lastAacCom\",},{M[3],M[1043],T\"lastAutoXCom\",},{M[3],M[684],T\"lastClutchCom\",},{M[3],M[484],T\"lastCom\",},{M[3],M[715],T\"lastShift\",},{M[3],M[681],T\"lastShiftCom\",},{M[3],M[488],T\"startCounter\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[45],T\"ticksCounter\",},{M[3],M[938],T\"timerCounter\",},{M[8],M[0],T\"is_active_c1_GCU_Model_genCode\",},{M[8],M[1],T\"is_active_GEARSHIFT\",},{M[8],M[31],T\"is_active_NEUTRAL_STATE\",},{M[8],M[418],T\"is_active_MODES\",},{M[8],M[479],T\"is_active_START_ENGINE\",},{M[8],M[929],T\"is_active_SCAN_ADC\",},{M[8],M[940],T\"is_active_EEPROM_TRIGGER\",},{M[9],M[1],T\"is_GEARSHIFT\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[9],M[9],T\"is_UP_START\",},{M[9],M[10],T\"is_UP_PUSH\",},{M[9],M[11],T\"is_UP_REBOUND\",},{M[9],M[14],T\"is_DOWN_START\",},{M[9],M[17],T\"is_DOWN_BRAKE\",},{M[9],M[31],T\"is_NEUTRAL_STATE\",},{M[9],M[418],T\"is_MODES\",},{M[9],M[434],T\"is_ACC\",},{M[9],M[479],T\"is_START_ENGINE\",},{M[9],M[538],T\"is_ACTIVE\",}}",
    "100 S1x9'type','srcId','name','auxInfo'{{M[9],M[693],T\"is_UPSHIFTING\",},{M[9],M[697],T\"is_DOWNSHIFTING\",},{M[9],M[727],T\"is_MANUAL_MODES\",},{M[9],M[820],T\"is_ACCELERATION\",},{M[9],M[929],T\"is_SCAN_ADC\",},{M[9],M[940],T\"is_EEPROM_TRIGGER\",},{M[9],M[951],T\"is_AUTOCROSS\",},{M[9],M[974],T\"is_LAUNCH\",},{M[9],M[985],T\"is_ACTIVE\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 49, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_GCU_Model_genCode_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc1_GCU_Model_genCodeInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_GCU_Model_genCodeInstanceStruct *chartInstance =
      (SFc1_GCU_Model_genCodeInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _GCU_Model_genCodeMachineNumber_,
           1,
           75,
           184,
           0,
           62,
           19,
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
            19,
            19,
            19);
          _SFD_SET_DATA_PROPS(0,0,0,0,"buzzerCounter");
          _SFD_SET_DATA_PROPS(1,0,0,0,"lastAacCom");
          _SFD_SET_DATA_PROPS(2,0,0,0,"lastAutoXCom");
          _SFD_SET_DATA_PROPS(3,0,0,0,"lastClutchCom");
          _SFD_SET_DATA_PROPS(4,0,0,0,"lastShiftCom");
          _SFD_SET_DATA_PROPS(5,0,0,0,"aacCounter");
          _SFD_SET_DATA_PROPS(6,0,0,0,"aac_clutchStep");
          _SFD_SET_DATA_PROPS(7,0,0,0,"aac_clutchValue");
          _SFD_SET_DATA_PROPS(8,0,0,0,"aac_dtRelease");
          _SFD_SET_DATA_PROPS(9,0,0,0,"autoXCounter");
          _SFD_SET_DATA_PROPS(10,0,0,0,"autoX_clutchStep");
          _SFD_SET_DATA_PROPS(11,0,0,0,"autoX_clutchValue");
          _SFD_SET_DATA_PROPS(12,0,0,0,"autoX_dtRelease");
          _SFD_SET_DATA_PROPS(13,0,0,0,"ticksCounter");
          _SFD_SET_DATA_PROPS(14,0,0,0,"counterWait");
          _SFD_SET_DATA_PROPS(15,0,0,0,"lastCom");
          _SFD_SET_DATA_PROPS(16,0,0,0,"startCounter");
          _SFD_SET_DATA_PROPS(17,0,0,0,"timerCounter");
          _SFD_SET_DATA_PROPS(18,0,0,0,"lastShift");
          _SFD_SET_DATA_PROPS(19,1,1,0,"currentGear");
          _SFD_SET_DATA_PROPS(20,1,1,0,"shiftCom");
          _SFD_SET_DATA_PROPS(21,1,1,0,"startEngCom");
          _SFD_SET_DATA_PROPS(22,1,1,0,"aacCom");
          _SFD_SET_DATA_PROPS(23,1,1,0,"acc_externValues");
          _SFD_SET_DATA_PROPS(24,1,1,0,"clutchCom");
          _SFD_SET_DATA_PROPS(25,1,1,0,"modeCom");
          _SFD_SET_DATA_PROPS(26,1,1,0,"acc_parameters");
          _SFD_SET_DATA_PROPS(27,1,1,0,"timings");
          _SFD_SET_DATA_PROPS(28,1,1,0,"autoXCom");
          _SFD_SET_DATA_PROPS(29,1,1,0,"autoX_parameters");
          _SFD_SET_DATA_PROPS(30,2,0,1,"clutchCurrVal");
          _SFD_SET_DATA_PROPS(31,2,0,1,"lastModeCom");
          _SFD_SET_DATA_PROPS(32,2,0,1,"stateFb");
          _SFD_SET_DATA_PROPS(33,7,0,0,"GEAR_COMMAND_DOWN");
          _SFD_SET_DATA_PROPS(34,7,0,0,"GEAR_COMMAND_NEUTRAL_DOWN");
          _SFD_SET_DATA_PROPS(35,7,0,0,"GEAR_COMMAND_NEUTRAL_UP");
          _SFD_SET_DATA_PROPS(36,7,0,0,"GEAR_COMMAND_UP");
          _SFD_SET_DATA_PROPS(37,7,0,0,"GEAR_COMMAND_DOWN");
          _SFD_SET_DATA_PROPS(38,7,0,0,"GEAR_COMMAND_NEUTRAL_DOWN");
          _SFD_SET_DATA_PROPS(39,7,0,0,"GEAR_COMMAND_NEUTRAL_UP");
          _SFD_SET_DATA_PROPS(40,7,0,0,"GEAR_COMMAND_UP");
          _SFD_SET_DATA_PROPS(41,7,0,0,"AAC_WORK_RATE_ms");
          _SFD_SET_DATA_PROPS(42,7,0,0,"ACC_CODE");
          _SFD_SET_DATA_PROPS(43,7,0,0,"DEF_RAMP_END");
          _SFD_SET_DATA_PROPS(44,7,0,0,"DEF_RAMP_START");
          _SFD_SET_DATA_PROPS(45,7,0,0,"DEF_RAMP_TIME");
          _SFD_SET_DATA_PROPS(46,7,0,0,"DEF_RPM_LIMIT_1_2");
          _SFD_SET_DATA_PROPS(47,7,0,0,"DEF_RPM_LIMIT_2_3");
          _SFD_SET_DATA_PROPS(48,7,0,0,"DEF_RPM_LIMIT_3_4");
          _SFD_SET_DATA_PROPS(49,7,0,0,"DEF_RPM_LIMIT_4_5");
          _SFD_SET_DATA_PROPS(50,7,0,0,"DEF_SPEED_LIMIT_1_2");
          _SFD_SET_DATA_PROPS(51,7,0,0,"DEF_SPEED_LIMIT_2_3");
          _SFD_SET_DATA_PROPS(52,7,0,0,"DEF_SPEED_LIMIT_3_4");
          _SFD_SET_DATA_PROPS(53,7,0,0,"DEF_SPEED_LIMIT_4_5");
          _SFD_SET_DATA_PROPS(54,7,0,0,"AUTOX_WORK_RATE_ms");
          _SFD_SET_DATA_PROPS(55,7,0,0,"data");
          _SFD_SET_DATA_PROPS(56,8,0,0,"");
          _SFD_SET_DATA_PROPS(57,8,0,0,"");
          _SFD_SET_DATA_PROPS(58,8,0,0,"");
          _SFD_SET_DATA_PROPS(59,9,0,0,"");
          _SFD_SET_DATA_PROPS(60,9,0,0,"");
          _SFD_SET_DATA_PROPS(61,9,0,0,"");
          _SFD_EVENT_SCOPE(0,0);
          _SFD_EVENT_SCOPE(1,0);
          _SFD_EVENT_SCOPE(2,0);
          _SFD_EVENT_SCOPE(3,2);
          _SFD_EVENT_SCOPE(4,2);
          _SFD_EVENT_SCOPE(5,2);
          _SFD_EVENT_SCOPE(6,2);
          _SFD_EVENT_SCOPE(7,2);
          _SFD_EVENT_SCOPE(8,2);
          _SFD_EVENT_SCOPE(9,2);
          _SFD_EVENT_SCOPE(10,2);
          _SFD_EVENT_SCOPE(11,2);
          _SFD_EVENT_SCOPE(12,2);
          _SFD_EVENT_SCOPE(13,2);
          _SFD_EVENT_SCOPE(14,2);
          _SFD_EVENT_SCOPE(15,2);
          _SFD_EVENT_SCOPE(16,2);
          _SFD_EVENT_SCOPE(17,2);
          _SFD_EVENT_SCOPE(18,2);
          _SFD_STATE_INFO(1,0,1);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,1);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(13,0,0);
          _SFD_STATE_INFO(14,0,0);
          _SFD_STATE_INFO(15,0,0);
          _SFD_STATE_INFO(17,0,0);
          _SFD_STATE_INFO(18,0,0);
          _SFD_STATE_INFO(19,0,0);
          _SFD_STATE_INFO(20,0,0);
          _SFD_STATE_INFO(21,0,0);
          _SFD_STATE_INFO(22,0,0);
          _SFD_STATE_INFO(23,0,0);
          _SFD_STATE_INFO(24,0,0);
          _SFD_STATE_INFO(25,0,0);
          _SFD_STATE_INFO(26,0,0);
          _SFD_STATE_INFO(27,0,0);
          _SFD_STATE_INFO(28,0,0);
          _SFD_STATE_INFO(29,0,0);
          _SFD_STATE_INFO(30,0,0);
          _SFD_STATE_INFO(31,0,1);
          _SFD_STATE_INFO(32,0,0);
          _SFD_STATE_INFO(33,0,0);
          _SFD_STATE_INFO(34,0,0);
          _SFD_STATE_INFO(35,0,0);
          _SFD_STATE_INFO(36,0,0);
          _SFD_STATE_INFO(37,0,0);
          _SFD_STATE_INFO(38,0,0);
          _SFD_STATE_INFO(39,0,0);
          _SFD_STATE_INFO(41,0,0);
          _SFD_STATE_INFO(43,0,0);
          _SFD_STATE_INFO(44,0,0);
          _SFD_STATE_INFO(45,0,0);
          _SFD_STATE_INFO(46,0,0);
          _SFD_STATE_INFO(47,0,0);
          _SFD_STATE_INFO(48,0,0);
          _SFD_STATE_INFO(49,0,0);
          _SFD_STATE_INFO(50,0,0);
          _SFD_STATE_INFO(51,0,0);
          _SFD_STATE_INFO(52,0,0);
          _SFD_STATE_INFO(54,0,0);
          _SFD_STATE_INFO(56,0,0);
          _SFD_STATE_INFO(57,0,0);
          _SFD_STATE_INFO(58,0,0);
          _SFD_STATE_INFO(59,0,0);
          _SFD_STATE_INFO(62,0,1);
          _SFD_STATE_INFO(63,0,0);
          _SFD_STATE_INFO(64,0,0);
          _SFD_STATE_INFO(65,0,0);
          _SFD_STATE_INFO(66,0,0);
          _SFD_STATE_INFO(67,0,1);
          _SFD_STATE_INFO(68,0,0);
          _SFD_STATE_INFO(70,0,0);
          _SFD_STATE_INFO(71,0,1);
          _SFD_STATE_INFO(72,0,0);
          _SFD_STATE_INFO(73,0,0);
          _SFD_STATE_INFO(74,0,0);
          _SFD_STATE_INFO(16,0,2);
          _SFD_STATE_INFO(40,0,2);
          _SFD_STATE_INFO(42,0,2);
          _SFD_STATE_INFO(53,0,2);
          _SFD_STATE_INFO(55,0,2);
          _SFD_STATE_INFO(60,0,2);
          _SFD_STATE_INFO(61,0,2);
          _SFD_STATE_INFO(69,0,2);
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(6);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,31);
          _SFD_CH_SUBSTATE_INDEX(1,62);
          _SFD_CH_SUBSTATE_INDEX(2,4);
          _SFD_CH_SUBSTATE_INDEX(3,71);
          _SFD_CH_SUBSTATE_INDEX(4,67);
          _SFD_CH_SUBSTATE_INDEX(5,1);
          _SFD_ST_SUBSTATE_COUNT(31,4);
          _SFD_ST_SUBSTATE_INDEX(31,0,32);
          _SFD_ST_SUBSTATE_INDEX(31,1,44);
          _SFD_ST_SUBSTATE_INDEX(31,2,56);
          _SFD_ST_SUBSTATE_INDEX(31,3,57);
          _SFD_ST_SUBSTATE_COUNT(32,2);
          _SFD_ST_SUBSTATE_INDEX(32,0,33);
          _SFD_ST_SUBSTATE_INDEX(32,1,43);
          _SFD_ST_SUBSTATE_COUNT(33,2);
          _SFD_ST_SUBSTATE_INDEX(33,0,34);
          _SFD_ST_SUBSTATE_INDEX(33,1,41);
          _SFD_ST_SUBSTATE_COUNT(34,5);
          _SFD_ST_SUBSTATE_INDEX(34,0,35);
          _SFD_ST_SUBSTATE_INDEX(34,1,36);
          _SFD_ST_SUBSTATE_INDEX(34,2,37);
          _SFD_ST_SUBSTATE_INDEX(34,3,38);
          _SFD_ST_SUBSTATE_INDEX(34,4,39);
          _SFD_ST_SUBSTATE_COUNT(35,0);
          _SFD_ST_SUBSTATE_COUNT(36,0);
          _SFD_ST_SUBSTATE_COUNT(37,0);
          _SFD_ST_SUBSTATE_COUNT(38,0);
          _SFD_ST_SUBSTATE_COUNT(39,0);
          _SFD_ST_SUBSTATE_COUNT(41,0);
          _SFD_ST_SUBSTATE_COUNT(43,0);
          _SFD_ST_SUBSTATE_COUNT(44,2);
          _SFD_ST_SUBSTATE_INDEX(44,0,45);
          _SFD_ST_SUBSTATE_INDEX(44,1,46);
          _SFD_ST_SUBSTATE_COUNT(45,0);
          _SFD_ST_SUBSTATE_COUNT(46,2);
          _SFD_ST_SUBSTATE_INDEX(46,0,47);
          _SFD_ST_SUBSTATE_INDEX(46,1,54);
          _SFD_ST_SUBSTATE_COUNT(47,5);
          _SFD_ST_SUBSTATE_INDEX(47,0,48);
          _SFD_ST_SUBSTATE_INDEX(47,1,49);
          _SFD_ST_SUBSTATE_INDEX(47,2,50);
          _SFD_ST_SUBSTATE_INDEX(47,3,51);
          _SFD_ST_SUBSTATE_INDEX(47,4,52);
          _SFD_ST_SUBSTATE_COUNT(48,0);
          _SFD_ST_SUBSTATE_COUNT(49,0);
          _SFD_ST_SUBSTATE_COUNT(50,0);
          _SFD_ST_SUBSTATE_COUNT(51,0);
          _SFD_ST_SUBSTATE_COUNT(52,0);
          _SFD_ST_SUBSTATE_COUNT(54,0);
          _SFD_ST_SUBSTATE_COUNT(56,0);
          _SFD_ST_SUBSTATE_COUNT(57,2);
          _SFD_ST_SUBSTATE_INDEX(57,0,58);
          _SFD_ST_SUBSTATE_INDEX(57,1,59);
          _SFD_ST_SUBSTATE_COUNT(58,0);
          _SFD_ST_SUBSTATE_COUNT(59,0);
          _SFD_ST_SUBSTATE_COUNT(62,4);
          _SFD_ST_SUBSTATE_INDEX(62,0,63);
          _SFD_ST_SUBSTATE_INDEX(62,1,64);
          _SFD_ST_SUBSTATE_INDEX(62,2,65);
          _SFD_ST_SUBSTATE_INDEX(62,3,66);
          _SFD_ST_SUBSTATE_COUNT(63,0);
          _SFD_ST_SUBSTATE_COUNT(64,0);
          _SFD_ST_SUBSTATE_COUNT(65,0);
          _SFD_ST_SUBSTATE_COUNT(66,0);
          _SFD_ST_SUBSTATE_COUNT(4,6);
          _SFD_ST_SUBSTATE_INDEX(4,0,5);
          _SFD_ST_SUBSTATE_INDEX(4,1,15);
          _SFD_ST_SUBSTATE_INDEX(4,2,17);
          _SFD_ST_SUBSTATE_INDEX(4,3,18);
          _SFD_ST_SUBSTATE_INDEX(4,4,19);
          _SFD_ST_SUBSTATE_INDEX(4,5,30);
          _SFD_ST_SUBSTATE_COUNT(5,4);
          _SFD_ST_SUBSTATE_INDEX(5,0,6);
          _SFD_ST_SUBSTATE_INDEX(5,1,9);
          _SFD_ST_SUBSTATE_INDEX(5,2,10);
          _SFD_ST_SUBSTATE_INDEX(5,3,11);
          _SFD_ST_SUBSTATE_COUNT(6,2);
          _SFD_ST_SUBSTATE_INDEX(6,0,7);
          _SFD_ST_SUBSTATE_INDEX(6,1,8);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
          _SFD_ST_SUBSTATE_COUNT(11,3);
          _SFD_ST_SUBSTATE_INDEX(11,0,12);
          _SFD_ST_SUBSTATE_INDEX(11,1,13);
          _SFD_ST_SUBSTATE_INDEX(11,2,14);
          _SFD_ST_SUBSTATE_COUNT(12,0);
          _SFD_ST_SUBSTATE_COUNT(13,0);
          _SFD_ST_SUBSTATE_COUNT(14,0);
          _SFD_ST_SUBSTATE_COUNT(15,0);
          _SFD_ST_SUBSTATE_COUNT(17,0);
          _SFD_ST_SUBSTATE_COUNT(18,0);
          _SFD_ST_SUBSTATE_COUNT(19,4);
          _SFD_ST_SUBSTATE_INDEX(19,0,20);
          _SFD_ST_SUBSTATE_INDEX(19,1,21);
          _SFD_ST_SUBSTATE_INDEX(19,2,24);
          _SFD_ST_SUBSTATE_INDEX(19,3,27);
          _SFD_ST_SUBSTATE_COUNT(20,0);
          _SFD_ST_SUBSTATE_COUNT(21,2);
          _SFD_ST_SUBSTATE_INDEX(21,0,22);
          _SFD_ST_SUBSTATE_INDEX(21,1,23);
          _SFD_ST_SUBSTATE_COUNT(22,0);
          _SFD_ST_SUBSTATE_COUNT(23,0);
          _SFD_ST_SUBSTATE_COUNT(24,2);
          _SFD_ST_SUBSTATE_INDEX(24,0,25);
          _SFD_ST_SUBSTATE_INDEX(24,1,26);
          _SFD_ST_SUBSTATE_COUNT(25,0);
          _SFD_ST_SUBSTATE_COUNT(26,0);
          _SFD_ST_SUBSTATE_COUNT(27,2);
          _SFD_ST_SUBSTATE_INDEX(27,0,28);
          _SFD_ST_SUBSTATE_INDEX(27,1,29);
          _SFD_ST_SUBSTATE_COUNT(28,0);
          _SFD_ST_SUBSTATE_COUNT(29,0);
          _SFD_ST_SUBSTATE_COUNT(30,0);
          _SFD_ST_SUBSTATE_COUNT(71,3);
          _SFD_ST_SUBSTATE_INDEX(71,0,72);
          _SFD_ST_SUBSTATE_INDEX(71,1,73);
          _SFD_ST_SUBSTATE_INDEX(71,2,74);
          _SFD_ST_SUBSTATE_COUNT(72,0);
          _SFD_ST_SUBSTATE_COUNT(73,0);
          _SFD_ST_SUBSTATE_COUNT(74,0);
          _SFD_ST_SUBSTATE_COUNT(67,2);
          _SFD_ST_SUBSTATE_INDEX(67,0,68);
          _SFD_ST_SUBSTATE_INDEX(67,1,70);
          _SFD_ST_SUBSTATE_COUNT(68,0);
          _SFD_ST_SUBSTATE_COUNT(70,0);
          _SFD_ST_SUBSTATE_COUNT(1,2);
          _SFD_ST_SUBSTATE_INDEX(1,0,2);
          _SFD_ST_SUBSTATE_INDEX(1,1,3);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
        }

        _SFD_CV_INIT_CHART(6,0,0,0);

        {
          _SFD_CV_INIT_STATE(1,2,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,6,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,4,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,2,1,1,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 91 };

          static unsigned int sEndSaturateMap[] = { 92 };

          _SFD_CV_INIT_STATE_SATURATION(6,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 119 };

          static unsigned int sEndSaturateMap[] = { 120 };

          _SFD_CV_INIT_STATE_SATURATION(9,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 120 };

          static unsigned int sEndSaturateMap[] = { 121 };

          _SFD_CV_INIT_STATE_SATURATION(10,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(11,3,1,1,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 92 };

          static unsigned int sEndSaturateMap[] = { 93 };

          _SFD_CV_INIT_STATE_SATURATION(11,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(12,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(13,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(14,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(15,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(17,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(18,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(19,4,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(20,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 114 };

          static unsigned int sEndSaturateMap[] = { 115 };

          _SFD_CV_INIT_STATE_SATURATION(20,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(21,2,1,1,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 89 };

          static unsigned int sEndSaturateMap[] = { 90 };

          _SFD_CV_INIT_STATE_SATURATION(21,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(22,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(23,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(24,2,1,1,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 92 };

          static unsigned int sEndSaturateMap[] = { 93 };

          _SFD_CV_INIT_STATE_SATURATION(24,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(25,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(26,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(27,2,1,1,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 52, 94 };

          static unsigned int sEndSaturateMap[] = { 53, 95 };

          _SFD_CV_INIT_STATE_SATURATION(27,2,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(28,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(29,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(30,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(31,4,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(32,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(33,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(34,5,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(35,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 129 };

          static unsigned int sEndSaturateMap[] = { 130 };

          _SFD_CV_INIT_STATE_SATURATION(35,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(36,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 143, 213, 87 };

          static unsigned int sEndSaturateMap[] = { 144, 214, 92 };

          _SFD_CV_INIT_STATE_SATURATION(36,3,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(37,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(38,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 155 };

          static unsigned int sEndSaturateMap[] = { 156 };

          _SFD_CV_INIT_STATE_SATURATION(38,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(39,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 120, 284, 320, 457 };

          static unsigned int sEndSaturateMap[] = { 125, 285, 321, 458 };

          _SFD_CV_INIT_STATE_SATURATION(39,4,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(41,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(43,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(44,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(45,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(46,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(47,5,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(48,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 139 };

          static unsigned int sEndSaturateMap[] = { 140 };

          _SFD_CV_INIT_STATE_SATURATION(48,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(49,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 155, 233, 93 };

          static unsigned int sEndSaturateMap[] = { 156, 234, 98 };

          _SFD_CV_INIT_STATE_SATURATION(49,3,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(50,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(51,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 165 };

          static unsigned int sEndSaturateMap[] = { 166 };

          _SFD_CV_INIT_STATE_SATURATION(51,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(52,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 121, 287, 320, 464 };

          static unsigned int sEndSaturateMap[] = { 126, 288, 321, 465 };

          _SFD_CV_INIT_STATE_SATURATION(52,4,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(54,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(56,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 38 };

          static unsigned int sEndSaturateMap[] = { 53 };

          _SFD_CV_INIT_STATE_SATURATION(56,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(57,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(58,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(59,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(62,4,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(63,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(64,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(65,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(66,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(67,2,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(68,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(70,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 40 };

          static unsigned int sEndSaturateMap[] = { 54 };

          _SFD_CV_INIT_STATE_SATURATION(70,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(71,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(72,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 120 };

          static unsigned int sEndSaturateMap[] = { 121 };

          _SFD_CV_INIT_STATE_SATURATION(72,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(73,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(74,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(16,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(40,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(42,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(53,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(55,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(60,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(61,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(69,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(145,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(78,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 20 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(79,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 20 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 5, 5 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(79,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 29 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(137,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(138,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1, 33 };

          static unsigned int sEndGuardMap[] = { 29, 61 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(143,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1, 33 };

          static unsigned int sEndRelationalopMap[] = { 29, 61 };

          static int sRelationalopEps[] = { 0, 0 };

          static int sRelationalopType[] = { 1, 1, 1, 1 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(143,2,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 32 };

          static unsigned int sEndGuardMap[] = { 28, 60 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(182,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1, 32 };

          static unsigned int sEndRelationalopMap[] = { 28, 60 };

          static int sRelationalopEps[] = { 0, 0 };

          static int sRelationalopType[] = { 1, 1, 1, 1 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(182,2,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 32 };

          static unsigned int sEndGuardMap[] = { 28, 60 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(144,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1, 32 };

          static unsigned int sEndRelationalopMap[] = { 28, 60 };

          static int sRelationalopEps[] = { 0, 0 };

          static int sRelationalopType[] = { 1, 1, 1, 1 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(144,2,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 27 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(139,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(140,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(181,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 32 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(141,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(179,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 25 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(180,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(136,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(126,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 30 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(127,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 30 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 1, 1 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(127,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(128,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(129,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 3, 34, 68 };

          static unsigned int sEndGuardMap[] = { 29, 63, 99 };

          static int sPostFixPredicateTree[] = { 0, -1, 1, -1, -3, 2, -2 };

          _SFD_CV_INIT_TRANS(130,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),7,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(131,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(132,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(122,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 28 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(123,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 28 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 1, 1 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(123,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(125,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(124,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 2 };

          static unsigned int sEndGuardMap[] = { 32 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(80,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2 };

          static unsigned int sEndRelationalopMap[] = { 32 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(80,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(82,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(81,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 33 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(83,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 33 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(83,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(85,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(84,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 39 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(86,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 39 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(86,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(88,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(87,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 41 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(89,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 41 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(89,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(91,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(90,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(142,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1, 28 };

          static unsigned int sEndGuardMap[] = { 24, 48 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(100,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 24 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 1, 1 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(100,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(111,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 17 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 5, 5 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(111,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(105,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(107,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 16 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(103,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 16 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 3, 3 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(103,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 16 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(106,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 16 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 3, 3 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(106,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 28, 51 };

          static unsigned int sEndGuardMap[] = { 24, 47, 133 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(101,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1, 51 };

          static unsigned int sEndRelationalopMap[] = { 24, 133 };

          static int sRelationalopEps[] = { 0, 0 };

          static int sRelationalopType[] = { 1, 5, 1, 5 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(101,2,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 16 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(102,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 16 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 3, 3 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(102,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 23 };

          static unsigned int sEndGuardMap[] = { 19, 72 };

          static int sPostFixPredicateTree[] = { 0, 1, -2 };

          _SFD_CV_INIT_TRANS(110,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1, 23 };

          static unsigned int sEndRelationalopMap[] = { 19, 72 };

          static int sRelationalopEps[] = { 0, 0 };

          static int sRelationalopType[] = { 3, 3, 3, 3 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(110,2,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(112,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 15 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(104,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 15 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 3, 3 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(104,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(113,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 25 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(133,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 25 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(133,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(135,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(134,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 109 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(114,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartSaturateMap[] = { 44 };

          static unsigned int sEndSaturateMap[] = { 58 };

          _SFD_CV_INIT_TRANSITION_SATURATION(114,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 109 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 5, 5 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(114,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(115,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(116,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 118 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(117,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartSaturateMap[] = { 52 };

          static unsigned int sEndSaturateMap[] = { 66 };

          _SFD_CV_INIT_TRANSITION_SATURATION(117,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 118 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 5, 5 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(117,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(118,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(119,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartSaturateMap[] = { 53 };

          static unsigned int sEndSaturateMap[] = { 54 };

          _SFD_CV_INIT_TRANSITION_SATURATION(119,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        _SFD_CV_INIT_TRANS(108,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(109,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(153,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1, 28 };

          static unsigned int sEndGuardMap[] = { 24, 48 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(155,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 24 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 1, 1 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(155,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(156,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 17 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 5, 5 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(156,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(158,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(159,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(160,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 18 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 3, 3 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(160,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(161,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 18 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 3, 3 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(161,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 32, 59 };

          static unsigned int sEndGuardMap[] = { 28, 55, 138 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(162,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1, 59 };

          static unsigned int sEndRelationalopMap[] = { 28, 138 };

          static int sRelationalopEps[] = { 0, 0 };

          static int sRelationalopType[] = { 1, 5, 1, 5 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(162,2,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(163,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 18 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 3, 3 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(163,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 25 };

          static unsigned int sEndGuardMap[] = { 21, 71 };

          static int sPostFixPredicateTree[] = { 0, 1, -2 };

          _SFD_CV_INIT_TRANS(164,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1, 25 };

          static unsigned int sEndRelationalopMap[] = { 21, 71 };

          static int sRelationalopEps[] = { 0, 0 };

          static int sRelationalopType[] = { 3, 3, 3, 3 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(164,2,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(165,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(166,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 17 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 3, 3 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(166,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(167,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 25 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(168,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 25 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(168,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(169,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(170,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 106 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(171,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartSaturateMap[] = { 44 };

          static unsigned int sEndSaturateMap[] = { 60 };

          _SFD_CV_INIT_TRANSITION_SATURATION(171,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 106 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 5, 5 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(171,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(172,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(173,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 115 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(174,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartSaturateMap[] = { 52 };

          static unsigned int sEndSaturateMap[] = { 68 };

          _SFD_CV_INIT_TRANSITION_SATURATION(174,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 115 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 5, 5 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(174,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(175,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(176,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartSaturateMap[] = { 53 };

          static unsigned int sEndSaturateMap[] = { 54 };

          _SFD_CV_INIT_TRANSITION_SATURATION(176,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        _SFD_CV_INIT_TRANS(177,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(178,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(92,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 11 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(14,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 27 };

          static unsigned int sEndGuardMap[] = { 23, 47 };

          static int sPostFixPredicateTree[] = { 0, 1, -2 };

          _SFD_CV_INIT_TRANS(17,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(183,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 17 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 1, 1 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(183,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 27 };

          static unsigned int sEndGuardMap[] = { 23, 47 };

          static int sPostFixPredicateTree[] = { 0, 1, -2 };

          _SFD_CV_INIT_TRANS(15,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 19 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(16,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(7,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 18 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(7,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 0, 12 };

          static unsigned int sEndGuardMap[] = { 11, 27 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(2,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 12 };

          static unsigned int sEndRelationalopMap[] = { 27 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 2, 2 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(2,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(3,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(12,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 18 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(12,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(6,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 18 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(6,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(4,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 18 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(4,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(5,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 18 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(5,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(65,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(66,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 30 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(64,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(75,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(76,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 2 };

          static unsigned int sEndGuardMap[] = { 31 };

          static int sPostFixPredicateTree[] = { 0, -1 };

          _SFD_CV_INIT_TRANS(77,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),2,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(61,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(63,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 30 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(62,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(9,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 18 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(9,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(11,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 18 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(11,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(10,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 18 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(10,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(68,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1, 36 };

          static unsigned int sEndGuardMap[] = { 30, 55 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(67,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 36 };

          static unsigned int sEndRelationalopMap[] = { 55 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 3, 3 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(67,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(70,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 2, 37 };

          static unsigned int sEndGuardMap[] = { 33, 56 };

          static int sPostFixPredicateTree[] = { 0, -1, 1, -3 };

          _SFD_CV_INIT_TRANS(69,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),4,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 37 };

          static unsigned int sEndRelationalopMap[] = { 56 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 3, 3 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(69,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(71,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(73,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(74,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 19 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(72,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 19 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 2, 2 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(72,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 24 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(20,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 30 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(34,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(36,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(35,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 23 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(22,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 30 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(48,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(49,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(56,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 26 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(24,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 30 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(37,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(25,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(38,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(39,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(46,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 17 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(46,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(57,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(52,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 24 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(26,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 30 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(40,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(51,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 17 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(51,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(58,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(27,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(41,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(42,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(50,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 28 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(28,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(54,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 17 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(54,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(59,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(29,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(43,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(55,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 27 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(30,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(47,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 17 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(47,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(60,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(31,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(44,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(53,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 30 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(32,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(33,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(45,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(98,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(99,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(150,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(151,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 18 };

          static int sRelationalopEps[] = { -1 };

          static int sRelationalopType[] = { 5, 5 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(151,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(152,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(95,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(96,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 23 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(146,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 23 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 1, 1 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(146,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 23 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(93,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1, 1, 1 };

          static unsigned int sEndRelationalopMap[] = { 23, 23, 23 };

          static int sRelationalopEps[] = { 0, 0, 0 };

          static int sRelationalopType[] = { 1, 1, 1, 1, 1, 1 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(93,3,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(97,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(94,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 18 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 3, 3 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(94,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(147,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 25 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(148,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(149,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1, 28 };

          static unsigned int sEndGuardMap[] = { 24, 50 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(121,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 24 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 1, 1 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(121,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(120,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1, 32 };

          static unsigned int sEndGuardMap[] = { 28, 58 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(154,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 28 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 1, 1 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(154,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(157,0,NULL,NULL,0,NULL);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_j_sf_marshallOut,(MexInFcnForType)c1_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_j_sf_marshallOut,(MexInFcnForType)c1_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_j_sf_marshallOut,(MexInFcnForType)c1_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_j_sf_marshallOut,(MexInFcnForType)c1_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_j_sf_marshallOut,(MexInFcnForType)c1_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(20,SF_UINT16,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(21,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(22,SF_UINT16,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(23,SF_UINT16,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(24,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(25,SF_UINT16,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 16U;
          _SFD_SET_DATA_COMPILED_PROPS(26,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_h_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 24U;
          _SFD_SET_DATA_COMPILED_PROPS(27,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_i_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(28,SF_UINT16,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 16U;
          _SFD_SET_DATA_COMPILED_PROPS(29,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_h_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(30,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(31,SF_UINT16,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)
            c1_c_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(32,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(33,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(34,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(35,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(36,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(37,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(38,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(39,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(40,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(41,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(42,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(43,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(44,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(45,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(46,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(47,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(48,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(49,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(50,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(51,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(52,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(53,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(54,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(55,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_j_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(56,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_k_sf_marshallOut,(MexInFcnForType)c1_f_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(57,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(58,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_l_sf_marshallOut,(MexInFcnForType)c1_g_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(59,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(60,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(61,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(56,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(57,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(58,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(59,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(60,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(61,(void *)(NULL));
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
    SFc1_GCU_Model_genCodeInstanceStruct *chartInstance =
      (SFc1_GCU_Model_genCodeInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(19U, (void *)chartInstance->c1_currentGear);
        _SFD_SET_DATA_VALUE_PTR(30U, (void *)chartInstance->c1_clutchCurrVal);
        _SFD_SET_DATA_VALUE_PTR(31U, (void *)chartInstance->c1_lastModeCom);
        _SFD_SET_DATA_VALUE_PTR(20U, (void *)chartInstance->c1_shiftCom);
        _SFD_SET_DATA_VALUE_PTR(21U, (void *)chartInstance->c1_startEngCom);
        _SFD_SET_DATA_VALUE_PTR(22U, (void *)chartInstance->c1_aacCom);
        _SFD_SET_DATA_VALUE_PTR(23U, (void *)chartInstance->c1_acc_externValues);
        _SFD_SET_DATA_VALUE_PTR(24U, (void *)chartInstance->c1_clutchCom);
        _SFD_SET_DATA_VALUE_PTR(18U, (void *)&chartInstance->c1_lastShift);
        _SFD_SET_DATA_VALUE_PTR(25U, (void *)chartInstance->c1_modeCom);
        _SFD_SET_DATA_VALUE_PTR(32U, (void *)chartInstance->c1_stateFb);
        _SFD_SET_DATA_VALUE_PTR(26U, (void *)chartInstance->c1_acc_parameters);
        _SFD_SET_DATA_VALUE_PTR(27U, (void *)chartInstance->c1_timings);
        _SFD_SET_DATA_VALUE_PTR(28U, (void *)chartInstance->c1_autoXCom);
        _SFD_SET_DATA_VALUE_PTR(29U, (void *)chartInstance->c1_autoX_parameters);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)&chartInstance->c1_lastAacCom);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)&chartInstance->c1_lastShiftCom);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)&chartInstance->c1_lastClutchCom);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)&chartInstance->c1_lastAutoXCom);
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)&chartInstance->c1_buzzerCounter);
        _SFD_SET_DATA_VALUE_PTR(35U, (void *)
          &chartInstance->c1_GEAR_COMMAND_NEUTRAL_UP);
        _SFD_SET_DATA_VALUE_PTR(34U, (void *)
          &chartInstance->c1_GEAR_COMMAND_NEUTRAL_DOWN);
        _SFD_SET_DATA_VALUE_PTR(36U, (void *)&chartInstance->c1_GEAR_COMMAND_UP);
        _SFD_SET_DATA_VALUE_PTR(33U, (void *)
          &chartInstance->c1_GEAR_COMMAND_DOWN);
        _SFD_SET_DATA_VALUE_PTR(39U, (void *)
          &chartInstance->c1_b_GEAR_COMMAND_NEUTRAL_UP);
        _SFD_SET_DATA_VALUE_PTR(38U, (void *)
          &chartInstance->c1_b_GEAR_COMMAND_NEUTRAL_DOWN);
        _SFD_SET_DATA_VALUE_PTR(40U, (void *)
          &chartInstance->c1_b_GEAR_COMMAND_UP);
        _SFD_SET_DATA_VALUE_PTR(37U, (void *)
          &chartInstance->c1_b_GEAR_COMMAND_DOWN);
        _SFD_SET_DATA_VALUE_PTR(41U, (void *)&chartInstance->c1_AAC_WORK_RATE_ms);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)&chartInstance->c1_aacCounter);
        _SFD_SET_DATA_VALUE_PTR(7U, (void *)&chartInstance->c1_aac_clutchValue);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)&chartInstance->c1_aac_clutchStep);
        _SFD_SET_DATA_VALUE_PTR(8U, (void *)&chartInstance->c1_aac_dtRelease);
        _SFD_SET_DATA_VALUE_PTR(44U, (void *)&chartInstance->c1_DEF_RAMP_START);
        _SFD_SET_DATA_VALUE_PTR(43U, (void *)&chartInstance->c1_DEF_RAMP_END);
        _SFD_SET_DATA_VALUE_PTR(45U, (void *)&chartInstance->c1_DEF_RAMP_TIME);
        _SFD_SET_DATA_VALUE_PTR(46U, (void *)
          &chartInstance->c1_DEF_RPM_LIMIT_1_2);
        _SFD_SET_DATA_VALUE_PTR(47U, (void *)
          &chartInstance->c1_DEF_RPM_LIMIT_2_3);
        _SFD_SET_DATA_VALUE_PTR(48U, (void *)
          &chartInstance->c1_DEF_RPM_LIMIT_3_4);
        _SFD_SET_DATA_VALUE_PTR(49U, (void *)
          &chartInstance->c1_DEF_RPM_LIMIT_4_5);
        _SFD_SET_DATA_VALUE_PTR(50U, (void *)
          &chartInstance->c1_DEF_SPEED_LIMIT_1_2);
        _SFD_SET_DATA_VALUE_PTR(51U, (void *)
          &chartInstance->c1_DEF_SPEED_LIMIT_2_3);
        _SFD_SET_DATA_VALUE_PTR(52U, (void *)
          &chartInstance->c1_DEF_SPEED_LIMIT_3_4);
        _SFD_SET_DATA_VALUE_PTR(53U, (void *)
          &chartInstance->c1_DEF_SPEED_LIMIT_4_5);
        _SFD_SET_DATA_VALUE_PTR(42U, (void *)&chartInstance->c1_ACC_CODE);
        _SFD_SET_DATA_VALUE_PTR(54U, (void *)
          &chartInstance->c1_AUTOX_WORK_RATE_ms);
        _SFD_SET_DATA_VALUE_PTR(9U, (void *)&chartInstance->c1_autoXCounter);
        _SFD_SET_DATA_VALUE_PTR(11U, (void *)
          &chartInstance->c1_autoX_clutchValue);
        _SFD_SET_DATA_VALUE_PTR(10U, (void *)&chartInstance->c1_autoX_clutchStep);
        _SFD_SET_DATA_VALUE_PTR(12U, (void *)&chartInstance->c1_autoX_dtRelease);
        _SFD_SET_DATA_VALUE_PTR(13U, (void *)&chartInstance->c1_ticksCounter);
        _SFD_SET_DATA_VALUE_PTR(55U, (void *)&chartInstance->c1_data);
        _SFD_SET_DATA_VALUE_PTR(14U, (void *)&chartInstance->c1_counterWait);
        _SFD_SET_DATA_VALUE_PTR(15U, (void *)&chartInstance->c1_lastCom);
        _SFD_SET_DATA_VALUE_PTR(16U, (void *)&chartInstance->c1_startCounter);
        _SFD_SET_DATA_VALUE_PTR(17U, (void *)&chartInstance->c1_timerCounter);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sNkpFvcAuAdrDWZ2djaMbLC";
}

static void sf_opaque_initialize_c1_GCU_Model_genCode(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_GCU_Model_genCode((SFc1_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar);
  initialize_c1_GCU_Model_genCode((SFc1_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_GCU_Model_genCode(void *chartInstanceVar)
{
  enable_c1_GCU_Model_genCode((SFc1_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_GCU_Model_genCode(void *chartInstanceVar)
{
  disable_c1_GCU_Model_genCode((SFc1_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_GCU_Model_genCode(void *chartInstanceVar)
{
  sf_gateway_c1_GCU_Model_genCode((SFc1_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_GCU_Model_genCode(SimStruct* S)
{
  return get_sim_state_c1_GCU_Model_genCode
    ((SFc1_GCU_Model_genCodeInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_GCU_Model_genCode(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c1_GCU_Model_genCode((SFc1_GCU_Model_genCodeInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c1_GCU_Model_genCode(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_GCU_Model_genCodeInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_GCU_Model_genCode_optimization_info();
    }

    finalize_c1_GCU_Model_genCode((SFc1_GCU_Model_genCodeInstanceStruct*)
      chartInstanceVar);
    if (!sim_mode_is_rtw_gen(S)) {
      ssSetModelMappingInfoPtr(S, NULL);
    }

    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_GCU_Model_genCode((SFc1_GCU_Model_genCodeInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_GCU_Model_genCode(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_GCU_Model_genCode((SFc1_GCU_Model_genCodeInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c1_GCU_Model_genCode(SimStruct *S)
{
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetInputPortDirectFeedThrough(S, 1, 1);
  ssSetInputPortDirectFeedThrough(S, 2, 1);
  ssSetInputPortDirectFeedThrough(S, 3, 1);
  ssSetInputPortDirectFeedThrough(S, 4, 1);
  ssSetInputPortDirectFeedThrough(S, 5, 1);
  ssSetInputPortDirectFeedThrough(S, 6, 1);
  ssSetInputPortDirectFeedThrough(S, 7, 1);
  ssSetInputPortDirectFeedThrough(S, 8, 1);
  ssSetInputPortDirectFeedThrough(S, 9, 1);
  ssSetInputPortDirectFeedThrough(S, 10, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_GCU_Model_genCode_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetSupportedForRowMajorCodeGen(S, 1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 1);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,1);
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,1,17);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,11);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 11; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1614336633U));
  ssSetChecksum1(S,(417125451U));
  ssSetChecksum2(S,(3377825426U));
  ssSetChecksum3(S,(2477436064U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_GCU_Model_genCode(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_GCU_Model_genCode(SimStruct *S)
{
  SFc1_GCU_Model_genCodeInstanceStruct *chartInstance;
  chartInstance = (SFc1_GCU_Model_genCodeInstanceStruct *)utMalloc(sizeof
    (SFc1_GCU_Model_genCodeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_GCU_Model_genCodeInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_GCU_Model_genCode;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_GCU_Model_genCode;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_GCU_Model_genCode;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_GCU_Model_genCode;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_GCU_Model_genCode;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_GCU_Model_genCode;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_GCU_Model_genCode;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_GCU_Model_genCode;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_GCU_Model_genCode;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_GCU_Model_genCode;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_GCU_Model_genCode;
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
    init_test_point_mapping_info(S);
  }

  chart_debug_initialization(S,1);
  mdl_start_c1_GCU_Model_genCode(chartInstance);
}

void c1_GCU_Model_genCode_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_GCU_Model_genCode(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_GCU_Model_genCode(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_GCU_Model_genCode(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_GCU_Model_genCode_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

static const rtwCAPI_DataTypeMap dataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, isComplex, isPointer */
  { "uint16_T", "uint16_T", 0, 0, sizeof(uint16_T), SS_UINT16, 0, 0 },

  { "uint8_T", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 } };

static real_T sfCAPIsampleTimeZero = 0.0;
static const rtwCAPI_SampleTimeMap sampleTimeMap[] = {
  /* *period, *offset, taskId, mode */
  { &sfCAPIsampleTimeZero, &sfCAPIsampleTimeZero, 0, 0 }
};

static const rtwCAPI_DimensionMap dimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims*/
  { rtwCAPI_SCALAR, 0, 2 } };

static const rtwCAPI_Signals testPointSignals[] = {
  /* addrMapIndex, sysNum, SFRelativePath, dataName, portNumber, dataTypeIndex, dimIndex, fixPtIdx, sTimeIndex */
  { 0, 0, "StateflowChart/clutchCurrVal", "clutchCurrVal", 0, 1, 0, 0, 0 },

  { 1, 0, "StateflowChart/MODES.ACCELERATION.ACC.aacCounter", "aacCounter", 0, 0,
    0, 0, 0 },

  { 2, 0, "StateflowChart/MODES.AUTOCROSS.LAUNCH.autoXCounter", "autoXCounter",
    0, 0, 0, 0, 0 } };

static const rtwCAPI_FixPtMap fixedPointMap[] = {
  /* *fracSlope, *bias, scaleType, wordLength, exponent, isSigned */
  { NULL, NULL, rtwCAPI_FIX_RESERVED, 64, 0, 0 } };

static const uint_T dimensionArray[] = {
  1, 1 };

static rtwCAPI_ModelMappingStaticInfo testPointMappingStaticInfo = {
  /* block signal monitoring */
  {
    testPointSignals,                  /* Block signals Array  */
    3,                                 /* Num Block IO signals */
    NULL,                              /* Root Inputs Array    */
    0,                                 /* Num root inputs      */
    NULL,                              /* Root Outputs Array */
    0                                  /* Num root outputs   */
  },

  /* parameter tuning */
  {
    NULL,                              /* Block parameters Array    */
    0,                                 /* Num block parameters      */
    NULL,                              /* Variable parameters Array */
    0                                  /* Num variable parameters   */
  },

  /* block states */
  {
    NULL,                              /* Block States array        */
    0                                  /* Num Block States          */
  },

  /* Static maps */
  {
    dataTypeMap,                       /* Data Type Map            */
    dimensionMap,                      /* Data Dimension Map       */
    fixedPointMap,                     /* Fixed Point Map          */
    NULL,                              /* Structure Element map    */
    sampleTimeMap,                     /* Sample Times Map         */
    dimensionArray                     /* Dimension Array          */
  },

  /* Target type */
  "float",

  {
    1614336633U,
    417125451U,
    3377825426U,
    2477436064U
  }
};

static void init_test_point_mapping_info(SimStruct *S)
{
  rtwCAPI_ModelMappingInfo *testPointMappingInfo;
  void **testPointAddrMap;
  SFc1_GCU_Model_genCodeInstanceStruct *chartInstance =
    (SFc1_GCU_Model_genCodeInstanceStruct *)sf_get_chart_instance_ptr(S);
  init_test_point_addr_map(chartInstance);
  testPointMappingInfo = get_test_point_mapping_info(chartInstance);
  testPointAddrMap = get_test_point_address_map(chartInstance);
  rtwCAPI_SetStaticMap(*testPointMappingInfo, &testPointMappingStaticInfo);
  rtwCAPI_SetLoggingStaticMap(*testPointMappingInfo, NULL);
  rtwCAPI_SetInstanceLoggingInfo(*testPointMappingInfo, NULL);
  rtwCAPI_SetPath(*testPointMappingInfo, "");
  rtwCAPI_SetFullPath(*testPointMappingInfo, NULL);
  rtwCAPI_SetDataAddressMap(*testPointMappingInfo, testPointAddrMap);
  rtwCAPI_SetChildMMIArray(*testPointMappingInfo, NULL);
  rtwCAPI_SetChildMMIArrayLen(*testPointMappingInfo, 0);
  ssSetModelMappingInfoPtr(S, testPointMappingInfo);
}
