#ifndef __c1_GCU_Model_genCode_h__
#define __c1_GCU_Model_genCode_h__
#include "sf_runtime/sfc_sdi.h"
#include "rtw_capi.h"
#include "rtw_modelmap.h"

/* Type Definitions */
#ifndef enum_acc_params
#define enum_acc_params

enum acc_params
{
  acc_params_RAMP_START = 0,           /* Default value */
  acc_params_RAMP_END,
  acc_params_RAMP_TIME,
  acc_params_RPM_LIMIT_1_2,
  acc_params_RPM_LIMIT_2_3,
  acc_params_RPM_LIMIT_3_4,
  acc_params_RPM_LIMIT_4_5,
  acc_params_SPEED_LIMIT_1_2,
  acc_params_SPEED_LIMIT_2_3,
  acc_params_SPEED_LIMIT_3_4,
  acc_params_SPEED_LIMIT_4_5,
  acc_params_TPS_START_LIMIT,
  acc_params_END_GEAR
};

#endif                                 /*enum_acc_params*/

#ifndef typedef_c1_acc_params
#define typedef_c1_acc_params

typedef enum acc_params c1_acc_params;

#endif                                 /*typedef_c1_acc_params*/

#ifndef enum_autoX_params
#define enum_autoX_params

enum autoX_params
{
  autoX_params_AUTOX_RAMP_START = 0,   /* Default value */
  autoX_params_AUTOX_RAMP_END,
  autoX_params_AUTOX_RAMP_TIME,
  autoX_params_AUTOX_RPM_LIMIT_1_2,
  autoX_params_AUTOX_RPM_LIMIT_2_3,
  autoX_params_AUTOX_RPM_LIMIT_3_4,
  autoX_params_AUTOX_RPM_LIMIT_4_5,
  autoX_params_AUTOX_SPEED_LIMIT_1_2,
  autoX_params_AUTOX_SPEED_LIMIT_2_3,
  autoX_params_AUTOX_SPEED_LIMIT_3_4,
  autoX_params_AUTOX_SPEED_LIMIT_4_5,
  autoX_params_AUTOX_TPS_START_LIMIT,
  autoX_params_AUTOX_END_GEAR
};

#endif                                 /*enum_autoX_params*/

#ifndef typedef_c1_autoX_params
#define typedef_c1_autoX_params

typedef enum autoX_params c1_autoX_params;

#endif                                 /*typedef_c1_autoX_params*/

#ifndef enum_anti_stall_params
#define enum_anti_stall_params

enum anti_stall_params
{
  anti_stall_params_RPM_THRESHOLD = 0, /* Default value */
  anti_stall_params_RPM_DELTA_THRESHOLD,
  anti_stall_params_GEAR_THRESHOLD
};

#endif                                 /*enum_anti_stall_params*/

#ifndef typedef_c1_anti_stall_params
#define typedef_c1_anti_stall_params

typedef enum anti_stall_params c1_anti_stall_params;

#endif                                 /*typedef_c1_anti_stall_params*/

#ifndef typedef_SFc1_GCU_Model_genCodeInstanceStruct
#define typedef_SFc1_GCU_Model_genCodeInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_MODES;
  uint8_T c1_tp_MANUAL_MODES;
  uint8_T c1_tp_ENDURANCE;
  uint8_T c1_tp_SKIDPAD;
  uint8_T c1_tp_INIT;
  uint8_T c1_tp_ACCELERATION;
  uint8_T c1_tp_ACC;
  uint8_T c1_tp_ACTIVE;
  uint8_T c1_tp_START;
  uint8_T c1_tp_READY;
  uint8_T c1_tp_START_RELEASE;
  uint8_T c1_tp_RUNNING;
  uint8_T c1_tp_RELEASING;
  uint8_T c1_tp_STOPPING;
  uint8_T c1_tp_DEFAULT;
  uint8_T c1_tp_AUTOCROSS;
  uint8_T c1_tp_LAUNCH;
  uint8_T c1_b_tp_ACTIVE;
  uint8_T c1_b_tp_START;
  uint8_T c1_b_tp_READY;
  uint8_T c1_b_tp_START_RELEASE;
  uint8_T c1_b_tp_RUNNING;
  uint8_T c1_b_tp_RELEASING;
  uint8_T c1_b_tp_STOPPING;
  uint8_T c1_b_tp_DEFAULT;
  uint8_T c1_tp_ACCELERATION_PID;
  uint8_T c1_tp_LAUNCH0;
  uint8_T c1_c_tp_ACTIVE;
  uint8_T c1_c_tp_START;
  uint8_T c1_c_tp_READY;
  uint8_T c1_c_tp_RUNNING;
  uint8_T c1_tp_RELEASE;
  uint8_T c1_tp_Control;
  uint8_T c1_tp_WAIT;
  uint8_T c1_c_tp_STOPPING;
  uint8_T c1_tp_LAUNCH1;
  uint8_T c1_d_tp_ACTIVE;
  uint8_T c1_d_tp_START;
  uint8_T c1_d_tp_READY;
  uint8_T c1_d_tp_RUNNING;
  uint8_T c1_b_tp_RELEASE;
  uint8_T c1_b_tp_Control;
  uint8_T c1_b_tp_WAIT;
  uint8_T c1_d_tp_STOPPING;
  uint8_T c1_tp_LAUNCH2;
  uint8_T c1_e_tp_ACTIVE;
  uint8_T c1_e_tp_START;
  uint8_T c1_e_tp_READY;
  uint8_T c1_e_tp_RUNNING;
  uint8_T c1_c_tp_RELEASE;
  uint8_T c1_c_tp_Control;
  uint8_T c1_c_tp_WAIT;
  uint8_T c1_e_tp_STOPPING;
  uint8_T c1_tp_LAUNCH3;
  uint8_T c1_f_tp_ACTIVE;
  uint8_T c1_f_tp_START;
  uint8_T c1_f_tp_READY;
  uint8_T c1_f_tp_RUNNING;
  uint8_T c1_d_tp_RELEASE;
  uint8_T c1_d_tp_Control;
  uint8_T c1_d_tp_WAIT;
  uint8_T c1_f_tp_STOPPING;
  uint8_T c1_tp_LAUNCH4;
  uint8_T c1_g_tp_ACTIVE;
  uint8_T c1_g_tp_START;
  uint8_T c1_g_tp_READY;
  uint8_T c1_g_tp_RUNNING;
  uint8_T c1_e_tp_RELEASE;
  uint8_T c1_e_tp_Control;
  uint8_T c1_e_tp_WAIT;
  uint8_T c1_g_tp_STOPPING;
  uint8_T c1_tp_LAUNCH5;
  uint8_T c1_h_tp_ACTIVE;
  uint8_T c1_h_tp_START;
  uint8_T c1_h_tp_READY;
  uint8_T c1_h_tp_RUNNING;
  uint8_T c1_f_tp_RELEASE;
  uint8_T c1_f_tp_Control;
  uint8_T c1_f_tp_WAIT;
  uint8_T c1_h_tp_STOPPING;
  uint8_T c1_tp_LAUNCH6;
  uint8_T c1_i_tp_ACTIVE;
  uint8_T c1_i_tp_START;
  uint8_T c1_i_tp_READY;
  uint8_T c1_i_tp_RUNNING;
  uint8_T c1_g_tp_RELEASE;
  uint8_T c1_g_tp_Control;
  uint8_T c1_g_tp_WAIT;
  uint8_T c1_i_tp_STOPPING;
  uint8_T c1_tp_LAUNCH8;
  uint8_T c1_j_tp_ACTIVE;
  uint8_T c1_j_tp_START;
  uint8_T c1_j_tp_READY;
  uint8_T c1_j_tp_RUNNING;
  uint8_T c1_h_tp_RELEASE;
  uint8_T c1_h_tp_Control;
  uint8_T c1_h_tp_WAIT;
  uint8_T c1_j_tp_STOPPING;
  uint8_T c1_tp_LAUNCH9;
  uint8_T c1_k_tp_ACTIVE;
  uint8_T c1_k_tp_START;
  uint8_T c1_k_tp_READY;
  uint8_T c1_k_tp_RUNNING;
  uint8_T c1_i_tp_RELEASE;
  uint8_T c1_i_tp_Control;
  uint8_T c1_i_tp_WAIT;
  uint8_T c1_k_tp_STOPPING;
  uint8_T c1_tp_LAUNCH7;
  uint8_T c1_l_tp_ACTIVE;
  uint8_T c1_l_tp_START;
  uint8_T c1_l_tp_READY;
  uint8_T c1_l_tp_RUNNING;
  uint8_T c1_j_tp_RELEASE;
  uint8_T c1_j_tp_Control;
  uint8_T c1_j_tp_WAIT;
  uint8_T c1_l_tp_STOPPING;
  uint8_T c1_c_tp_DEFAULT;
  uint8_T c1_tp_NEUTRAL_STATE;
  uint8_T c1_tp_NEUTRAL;
  uint8_T c1_tp_UNSET_NEUTRAL;
  uint8_T c1_tp_SET_NEUTRAL;
  uint8_T c1_tp_NO_NEUTRAL;
  uint8_T c1_tp_GEARSHIFT;
  uint8_T c1_tp_UPSHIFTING;
  uint8_T c1_tp_UP_REBOUND;
  uint8_T c1_tp_Default;
  uint8_T c1_tp_SettingNeutral;
  uint8_T c1_tp_UP_PUSH;
  uint8_T c1_b_tp_Default;
  uint8_T c1_tp_CutOff;
  uint8_T c1_tp_UP_START;
  uint8_T c1_c_tp_Default;
  uint8_T c1_b_tp_SettingNeutral;
  uint8_T c1_tp_UP_BRAKE;
  uint8_T c1_tp_UP_END;
  uint8_T c1_tp_IDLE;
  uint8_T c1_b_tp_INIT;
  uint8_T c1_tp_DOWNSHIFTING;
  uint8_T c1_tp_DOWN_START;
  uint8_T c1_c_tp_SettingNeutral;
  uint8_T c1_tp_ChangeClutch;
  uint8_T c1_d_tp_Default;
  uint8_T c1_tp_DOWN_BRAKE;
  uint8_T c1_e_tp_Default;
  uint8_T c1_b_tp_ChangeClutch;
  uint8_T c1_tp_DOWN_PUSH;
  uint8_T c1_tp_DOWN_REBOUND;
  uint8_T c1_tp_DOWN_END;
  uint8_T c1_tp_EEPROM_TRIGGER;
  uint8_T c1_k_tp_WAIT;
  uint8_T c1_tp_SEND;
  uint8_T c1_tp_START_ENGINE;
  uint8_T c1_l_tp_WAIT;
  uint8_T c1_m_tp_START;
  uint8_T c1_tp_STOP;
  uint8_T c1_tp_SCAN_ADC;
  uint8_T c1_tp_SCAN;
  uint8_T c1_tp_ANTISTALL_ENABLE;
  uint8_T c1_tp_DISABLE;
  uint8_T c1_tp_ENABLE;
  uint8_T c1_tp_RETRY_LOGIC;
  uint8_T c1_tp_NO_RETRY;
  uint8_T c1_tp_WAITING_RETRY;
  uint8_T c1_tp_RETRY_UP;
  uint8_T c1_tp_RETRY_DOWN;
  uint8_T c1_is_active_c1_GCU_Model_genCode;
  uint8_T c1_is_MODES;
  uint8_T c1_is_active_MODES;
  uint8_T c1_is_MANUAL_MODES;
  uint8_T c1_is_ACCELERATION;
  uint8_T c1_is_ACC;
  uint8_T c1_is_ACTIVE;
  uint8_T c1_is_AUTOCROSS;
  uint8_T c1_is_LAUNCH;
  uint8_T c1_b_is_ACTIVE;
  uint8_T c1_is_ACCELERATION_PID;
  uint8_T c1_is_LAUNCH0;
  uint8_T c1_c_is_ACTIVE;
  uint8_T c1_is_RELEASE;
  uint8_T c1_is_LAUNCH1;
  uint8_T c1_d_is_ACTIVE;
  uint8_T c1_b_is_RELEASE;
  uint8_T c1_is_LAUNCH2;
  uint8_T c1_e_is_ACTIVE;
  uint8_T c1_c_is_RELEASE;
  uint8_T c1_is_LAUNCH3;
  uint8_T c1_f_is_ACTIVE;
  uint8_T c1_d_is_RELEASE;
  uint8_T c1_is_LAUNCH4;
  uint8_T c1_g_is_ACTIVE;
  uint8_T c1_e_is_RELEASE;
  uint8_T c1_is_LAUNCH5;
  uint8_T c1_h_is_ACTIVE;
  uint8_T c1_f_is_RELEASE;
  uint8_T c1_is_LAUNCH6;
  uint8_T c1_i_is_ACTIVE;
  uint8_T c1_g_is_RELEASE;
  uint8_T c1_is_LAUNCH8;
  uint8_T c1_j_is_ACTIVE;
  uint8_T c1_h_is_RELEASE;
  uint8_T c1_is_LAUNCH9;
  uint8_T c1_k_is_ACTIVE;
  uint8_T c1_i_is_RELEASE;
  uint8_T c1_is_LAUNCH7;
  uint8_T c1_l_is_ACTIVE;
  uint8_T c1_j_is_RELEASE;
  uint8_T c1_is_NEUTRAL_STATE;
  uint8_T c1_is_active_NEUTRAL_STATE;
  uint8_T c1_is_GEARSHIFT;
  uint8_T c1_is_active_GEARSHIFT;
  uint8_T c1_is_UPSHIFTING;
  uint8_T c1_is_UP_REBOUND;
  uint8_T c1_is_UP_PUSH;
  uint8_T c1_is_UP_START;
  uint8_T c1_is_DOWNSHIFTING;
  uint8_T c1_is_DOWN_START;
  uint8_T c1_is_DOWN_BRAKE;
  uint8_T c1_is_EEPROM_TRIGGER;
  uint8_T c1_is_active_EEPROM_TRIGGER;
  uint8_T c1_is_START_ENGINE;
  uint8_T c1_is_active_START_ENGINE;
  uint8_T c1_is_SCAN_ADC;
  uint8_T c1_is_active_SCAN_ADC;
  uint8_T c1_is_ANTISTALL_ENABLE;
  uint8_T c1_is_active_ANTISTALL_ENABLE;
  uint8_T c1_is_RETRY_LOGIC;
  uint8_T c1_is_active_RETRY_LOGIC;
  uint8_T c1_lastShift;
  uint16_T c1_lastTryShift[2];
  uint16_T c1_lastAacCom;
  uint16_T c1_lastShiftCom;
  uint16_T c1_lastAutoXCom;
  uint16_T c1_buzzerCounter;
  uint16_T c1_GEAR_COMMAND_NEUTRAL_UP;
  uint16_T c1_GEAR_COMMAND_NEUTRAL_DOWN;
  uint16_T c1_GEAR_COMMAND_UP;
  uint16_T c1_GEAR_COMMAND_DOWN;
  uint16_T c1_b_GEAR_COMMAND_NEUTRAL_UP;
  uint16_T c1_b_GEAR_COMMAND_NEUTRAL_DOWN;
  uint16_T c1_b_GEAR_COMMAND_UP;
  uint16_T c1_b_GEAR_COMMAND_DOWN;
  uint16_T c1_AAC_WORK_RATE_ms;
  uint16_T c1_aacCounter;
  real_T c1_aac_clutchValue;
  real_T c1_aac_clutchStep;
  int32_T c1_aac_dtRelease;
  int32_T c1_DEF_RAMP_START;
  int32_T c1_DEF_RAMP_END;
  int32_T c1_DEF_RAMP_TIME;
  int32_T c1_DEF_RPM_LIMIT_1_2;
  int32_T c1_DEF_RPM_LIMIT_2_3;
  int32_T c1_DEF_RPM_LIMIT_3_4;
  int32_T c1_DEF_RPM_LIMIT_4_5;
  int32_T c1_DEF_SPEED_LIMIT_1_2;
  int32_T c1_DEF_SPEED_LIMIT_2_3;
  int32_T c1_DEF_SPEED_LIMIT_3_4;
  int32_T c1_DEF_SPEED_LIMIT_4_5;
  uint16_T c1_ACC_CODE;
  uint16_T c1_AUTOX_WORK_RATE_ms;
  uint16_T c1_autoXCounter;
  real_T c1_autoX_clutchValue;
  real_T c1_autoX_clutchStep;
  int32_T c1_autoX_dtRelease;
  uint16_T c1_b_AUTOX_WORK_RATE_ms;
  uint16_T c1_b_autoXCounter;
  real_T c1_b_autoX_clutchValue;
  real_T c1_b_autoX_clutchStep;
  int32_T c1_b_autoX_dtRelease;
  uint16_T c1_lastSlip;
  uint16_T c1_c_AUTOX_WORK_RATE_ms;
  uint16_T c1_c_autoXCounter;
  real_T c1_c_autoX_clutchValue;
  real_T c1_c_autoX_clutchStep;
  int32_T c1_c_autoX_dtRelease;
  uint16_T c1_b_lastSlip;
  uint16_T c1_d_AUTOX_WORK_RATE_ms;
  uint16_T c1_d_autoXCounter;
  real_T c1_d_autoX_clutchValue;
  real_T c1_d_autoX_clutchStep;
  int32_T c1_d_autoX_dtRelease;
  uint16_T c1_c_lastSlip;
  uint16_T c1_e_AUTOX_WORK_RATE_ms;
  uint16_T c1_e_autoXCounter;
  real_T c1_e_autoX_clutchValue;
  real_T c1_e_autoX_clutchStep;
  int32_T c1_e_autoX_dtRelease;
  uint16_T c1_d_lastSlip;
  uint16_T c1_f_AUTOX_WORK_RATE_ms;
  uint16_T c1_f_autoXCounter;
  real_T c1_f_autoX_clutchValue;
  real_T c1_f_autoX_clutchStep;
  int32_T c1_f_autoX_dtRelease;
  uint16_T c1_e_lastSlip;
  uint16_T c1_g_AUTOX_WORK_RATE_ms;
  uint16_T c1_g_autoXCounter;
  real_T c1_g_autoX_clutchValue;
  real_T c1_g_autoX_clutchStep;
  int32_T c1_g_autoX_dtRelease;
  uint16_T c1_f_lastSlip;
  uint16_T c1_h_AUTOX_WORK_RATE_ms;
  uint16_T c1_h_autoXCounter;
  real_T c1_h_autoX_clutchValue;
  real_T c1_h_autoX_clutchStep;
  int32_T c1_h_autoX_dtRelease;
  uint16_T c1_g_lastSlip;
  uint16_T c1_i_AUTOX_WORK_RATE_ms;
  uint16_T c1_i_autoXCounter;
  real_T c1_i_autoX_clutchValue;
  real_T c1_i_autoX_clutchStep;
  int32_T c1_i_autoX_dtRelease;
  uint16_T c1_h_lastSlip;
  uint16_T c1_j_AUTOX_WORK_RATE_ms;
  uint16_T c1_j_autoXCounter;
  real_T c1_j_autoX_clutchValue;
  real_T c1_j_autoX_clutchStep;
  int32_T c1_j_autoX_dtRelease;
  uint16_T c1_i_lastSlip;
  uint16_T c1_k_AUTOX_WORK_RATE_ms;
  uint16_T c1_k_autoXCounter;
  real_T c1_k_autoX_clutchValue;
  real_T c1_k_autoX_clutchStep;
  int32_T c1_k_autoX_dtRelease;
  uint16_T c1_j_lastSlip;
  real_T c1_delayCount;
  real_T c1_retryCount;
  uint16_T c1_c_GEAR_COMMAND_UP;
  uint16_T c1_c_GEAR_COMMAND_DOWN;
  int32_T c1_ticksCounter;
  real_T c1_data;
  real_T c1_counterWait;
  uint8_T c1_lastCom;
  uint8_T c1_startCounter;
  uint16_T c1_timerCounter;
  real_T c1_b_counterWait;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
  void *c1_dataSetLogObjVector[13];
  uint8_T c1_sdiLoggedStatesBuffer[166];
  uint8_T c1_sdiLoggedDataBuffer[204];
  sdiBlockID_t c1_sdiBlockInfo;
  SignalExportStruct c1_SignalExportProp;
  SignalExportStruct c1_b_SignalExportProp;
  SignalExportStruct c1_c_SignalExportProp;
  SignalExportStruct c1_d_SignalExportProp;
  SignalExportStruct c1_e_SignalExportProp;
  SignalExportStruct c1_f_SignalExportProp;
  SignalExportStruct c1_g_SignalExportProp;
  SignalExportStruct c1_h_SignalExportProp;
  SignalExportStruct c1_i_SignalExportProp;
  SignalExportStruct c1_j_SignalExportProp;
  SignalExportStruct c1_k_SignalExportProp;
  SignalExportStruct c1_l_SignalExportProp;
  SignalExportStruct c1_m_SignalExportProp;
  SignalExportStruct c1_n_SignalExportProp;
  SignalExportStruct c1_o_SignalExportProp;
  SignalExportStruct c1_p_SignalExportProp;
  SignalExportStruct c1_q_SignalExportProp;
  SignalExportStruct c1_r_SignalExportProp;
  SignalExportStruct c1_s_SignalExportProp;
  SignalExportStruct c1_t_SignalExportProp;
  SignalExportStruct c1_u_SignalExportProp;
  SignalExportStruct c1_v_SignalExportProp;
  SignalExportStruct c1_w_SignalExportProp;
  SignalExportStruct c1_x_SignalExportProp;
  SignalExportStruct c1_y_SignalExportProp;
  SignalExportStruct c1_ab_SignalExportProp;
  SignalExportStruct c1_bb_SignalExportProp;
  SignalExportStruct c1_cb_SignalExportProp;
  SignalExportStruct c1_db_SignalExportProp;
  SignalExportStruct c1_eb_SignalExportProp;
  SignalExportStruct c1_fb_SignalExportProp;
  SignalExportStruct c1_gb_SignalExportProp;
  SignalExportStruct c1_hb_SignalExportProp;
  SignalExportStruct c1_ib_SignalExportProp;
  SignalExportStruct c1_jb_SignalExportProp;
  SignalExportStruct c1_kb_SignalExportProp;
  SignalExportStruct c1_lb_SignalExportProp;
  SignalExportStruct c1_mb_SignalExportProp;
  SignalExportStruct c1_nb_SignalExportProp;
  SignalExportStruct c1_ob_SignalExportProp;
  SignalExportStruct c1_pb_SignalExportProp;
  SignalExportStruct c1_qb_SignalExportProp;
  SignalExportStruct c1_rb_SignalExportProp;
  SignalExportStruct c1_sb_SignalExportProp;
  SignalExportStruct c1_tb_SignalExportProp;
  SignalExportStruct c1_ub_SignalExportProp;
  SignalExportStruct c1_vb_SignalExportProp;
  SignalExportStruct c1_wb_SignalExportProp;
  SignalExportStruct c1_xb_SignalExportProp;
  SignalExportStruct c1_yb_SignalExportProp;
  SignalExportStruct c1_ac_SignalExportProp;
  SignalExportStruct c1_bc_SignalExportProp;
  SignalExportStruct c1_cc_SignalExportProp;
  SignalExportStruct c1_dc_SignalExportProp;
  SignalExportStruct c1_ec_SignalExportProp;
  SignalExportStruct c1_fc_SignalExportProp;
  SignalExportStruct c1_gc_SignalExportProp;
  SignalExportStruct c1_hc_SignalExportProp;
  SignalExportStruct c1_ic_SignalExportProp;
  SignalExportStruct c1_jc_SignalExportProp;
  SignalExportStruct c1_kc_SignalExportProp;
  SignalExportStruct c1_lc_SignalExportProp;
  SignalExportStruct c1_mc_SignalExportProp;
  SignalExportStruct c1_nc_SignalExportProp;
  SignalExportStruct c1_oc_SignalExportProp;
  SignalExportStruct c1_pc_SignalExportProp;
  SignalExportStruct c1_qc_SignalExportProp;
  SignalExportStruct c1_rc_SignalExportProp;
  SignalExportStruct c1_sc_SignalExportProp;
  SignalExportStruct c1_tc_SignalExportProp;
  SignalExportStruct c1_uc_SignalExportProp;
  SignalExportStruct c1_vc_SignalExportProp;
  SignalExportStruct c1_wc_SignalExportProp;
  SignalExportStruct c1_xc_SignalExportProp;
  SignalExportStruct c1_yc_SignalExportProp;
  SignalExportStruct c1_ad_SignalExportProp;
  SignalExportStruct c1_bd_SignalExportProp;
  SignalExportStruct c1_cd_SignalExportProp;
  SignalExportStruct c1_dd_SignalExportProp;
  SignalExportStruct c1_ed_SignalExportProp;
  SignalExportStruct c1_fd_SignalExportProp;
  SignalExportStruct c1_gd_SignalExportProp;
  SignalExportStruct c1_hd_SignalExportProp;
  SignalExportStruct c1_id_SignalExportProp;
  SignalExportStruct c1_jd_SignalExportProp;
  SignalExportStruct c1_kd_SignalExportProp;
  SignalExportStruct c1_ld_SignalExportProp;
  SignalExportStruct c1_md_SignalExportProp;
  SignalExportStruct c1_nd_SignalExportProp;
  SignalExportStruct c1_od_SignalExportProp;
  SignalExportStruct c1_pd_SignalExportProp;
  SignalExportStruct c1_qd_SignalExportProp;
  SignalExportStruct c1_rd_SignalExportProp;
  SignalExportStruct c1_sd_SignalExportProp;
  SignalExportStruct c1_td_SignalExportProp;
  SignalExportStruct c1_ud_SignalExportProp;
  SignalExportStruct c1_vd_SignalExportProp;
  SignalExportStruct c1_wd_SignalExportProp;
  SignalExportStruct c1_xd_SignalExportProp;
  SignalExportStruct c1_yd_SignalExportProp;
  SignalExportStruct c1_ae_SignalExportProp;
  SignalExportStruct c1_be_SignalExportProp;
  SignalExportStruct c1_ce_SignalExportProp;
  SignalExportStruct c1_de_SignalExportProp;
  SignalExportStruct c1_ee_SignalExportProp;
  SignalExportStruct c1_fe_SignalExportProp;
  SignalExportStruct c1_ge_SignalExportProp;
  SignalExportStruct c1_he_SignalExportProp;
  SignalExportStruct c1_ie_SignalExportProp;
  SignalExportStruct c1_je_SignalExportProp;
  SignalExportStruct c1_ke_SignalExportProp;
  SignalExportStruct c1_le_SignalExportProp;
  SignalExportStruct c1_me_SignalExportProp;
  SignalExportStruct c1_ne_SignalExportProp;
  SignalExportStruct c1_oe_SignalExportProp;
  SignalExportStruct c1_pe_SignalExportProp;
  SignalExportStruct c1_qe_SignalExportProp;
  SignalExportStruct c1_re_SignalExportProp;
  SignalExportStruct c1_se_SignalExportProp;
  SignalExportStruct c1_te_SignalExportProp;
  SignalExportStruct c1_ue_SignalExportProp;
  SignalExportStruct c1_ve_SignalExportProp;
  SignalExportStruct c1_we_SignalExportProp;
  SignalExportStruct c1_xe_SignalExportProp;
  SignalExportStruct c1_ye_SignalExportProp;
  SignalExportStruct c1_af_SignalExportProp;
  SignalExportStruct c1_bf_SignalExportProp;
  SignalExportStruct c1_cf_SignalExportProp;
  SignalExportStruct c1_df_SignalExportProp;
  SignalExportStruct c1_ef_SignalExportProp;
  SignalExportStruct c1_ff_SignalExportProp;
  SignalExportStruct c1_gf_SignalExportProp;
  SignalExportStruct c1_hf_SignalExportProp;
  SignalExportStruct c1_if_SignalExportProp;
  SignalExportStruct c1_jf_SignalExportProp;
  SignalExportStruct c1_kf_SignalExportProp;
  SignalExportStruct c1_lf_SignalExportProp;
  SignalExportStruct c1_mf_SignalExportProp;
  SignalExportStruct c1_nf_SignalExportProp;
  SignalExportStruct c1_of_SignalExportProp;
  SignalExportStruct c1_pf_SignalExportProp;
  SignalExportStruct c1_qf_SignalExportProp;
  SignalExportStruct c1_rf_SignalExportProp;
  SignalExportStruct c1_sf_SignalExportProp;
  SignalExportStruct c1_tf_SignalExportProp;
  SignalExportStruct c1_uf_SignalExportProp;
  SignalExportStruct c1_vf_SignalExportProp;
  SignalExportStruct c1_wf_SignalExportProp;
  SignalExportStruct c1_xf_SignalExportProp;
  SignalExportStruct c1_yf_SignalExportProp;
  SignalExportStruct c1_ag_SignalExportProp;
  SignalExportStruct c1_bg_SignalExportProp;
  SignalExportStruct c1_cg_SignalExportProp;
  SignalExportStruct c1_dg_SignalExportProp;
  SignalExportStruct c1_eg_SignalExportProp;
  SignalExportStruct c1_fg_SignalExportProp;
  SignalExportStruct c1_gg_SignalExportProp;
  SignalExportStruct c1_hg_SignalExportProp;
  SignalExportStruct c1_ig_SignalExportProp;
  SignalExportStruct c1_jg_SignalExportProp;
  SignalExportStruct c1_kg_SignalExportProp;
  SignalExportStruct c1_lg_SignalExportProp;
  SignalExportStruct c1_mg_SignalExportProp;
  SignalExportStruct c1_ng_SignalExportProp;
  SignalExportStruct c1_og_SignalExportProp;
  SignalExportStruct c1_pg_SignalExportProp;
  SignalExportStruct c1_qg_SignalExportProp;
  SignalExportStruct c1_rg_SignalExportProp;
  SignalExportStruct c1_sg_SignalExportProp;
  SignalExportStruct c1_tg_SignalExportProp;
  SignalExportStruct c1_ug_SignalExportProp;
  SignalExportStruct c1_vg_SignalExportProp;
  SignalExportStruct c1_wg_SignalExportProp;
  SignalExportStruct c1_xg_SignalExportProp;
  SignalExportStruct c1_yg_SignalExportProp;
  SignalExportStruct c1_ah_SignalExportProp;
  SignalExportStruct c1_bh_SignalExportProp;
  SignalExportStruct c1_ch_SignalExportProp;
  SignalExportStruct c1_dh_SignalExportProp;
  SignalExportStruct c1_eh_SignalExportProp;
  SignalExportStruct c1_fh_SignalExportProp;
  SignalExportStruct c1_gh_SignalExportProp;
  SignalExportStruct c1_hh_SignalExportProp;
  SignalExportStruct c1_ih_SignalExportProp;
  SignalExportStruct c1_jh_SignalExportProp;
  SignalExportStruct c1_kh_SignalExportProp;
  SignalExportStruct c1_lh_SignalExportProp;
  SignalExportStruct c1_mh_SignalExportProp;
  SignalExportStruct c1_nh_SignalExportProp;
  SignalExportStruct c1_oh_SignalExportProp;
  SignalExportStruct c1_ph_SignalExportProp;
  SignalExportStruct c1_qh_SignalExportProp;
  SignalExportStruct c1_rh_SignalExportProp;
  SignalExportStruct c1_sh_SignalExportProp;
  SignalExportStruct c1_th_SignalExportProp;
  SignalExportStruct c1_uh_SignalExportProp;
  SignalExportStruct c1_vh_SignalExportProp;
  SignalExportStruct c1_wh_SignalExportProp;
  SignalExportStruct c1_xh_SignalExportProp;
  SignalExportStruct c1_yh_SignalExportProp;
  SignalExportStruct c1_ai_SignalExportProp;
  SignalExportStruct c1_bi_SignalExportProp;
  SignalExportStruct c1_ci_SignalExportProp;
  SignalExportStruct c1_di_SignalExportProp;
  SignalExportStruct c1_ei_SignalExportProp;
  SignalExportStruct c1_fi_SignalExportProp;
  SignalExportStruct c1_gi_SignalExportProp;
  SignalExportStruct c1_hi_SignalExportProp;
  SignalExportStruct c1_ii_SignalExportProp;
  SignalExportStruct c1_ji_SignalExportProp;
  SignalExportStruct c1_ki_SignalExportProp;
  SignalExportStruct c1_li_SignalExportProp;
  SignalExportStruct c1_mi_SignalExportProp;
  SignalExportStruct c1_ni_SignalExportProp;
  SignalExportStruct c1_oi_SignalExportProp;
  SignalExportStruct c1_pi_SignalExportProp;
  SignalExportStruct c1_qi_SignalExportProp;
  SignalExportStruct c1_ri_SignalExportProp;
  SignalExportStruct c1_si_SignalExportProp;
  SignalExportStruct c1_ti_SignalExportProp;
  SignalExportStruct c1_ui_SignalExportProp;
  SignalExportStruct c1_vi_SignalExportProp;
  SignalExportStruct c1_wi_SignalExportProp;
  SignalExportStruct c1_xi_SignalExportProp;
  SignalExportStruct c1_yi_SignalExportProp;
  SignalExportStruct c1_aj_SignalExportProp;
  SignalExportStruct c1_bj_SignalExportProp;
  SignalExportStruct c1_cj_SignalExportProp;
  SignalExportStruct c1_dj_SignalExportProp;
  SignalExportStruct c1_ej_SignalExportProp;
  SignalExportStruct c1_fj_SignalExportProp;
  SignalExportStruct c1_gj_SignalExportProp;
  SignalExportStruct c1_hj_SignalExportProp;
  SignalExportStruct c1_ij_SignalExportProp;
  SignalExportStruct c1_jj_SignalExportProp;
  SignalExportStruct c1_kj_SignalExportProp;
  SignalExportStruct c1_lj_SignalExportProp;
  SignalExportStruct c1_mj_SignalExportProp;
  SignalExportStruct c1_nj_SignalExportProp;
  SignalExportStruct c1_oj_SignalExportProp;
  SignalExportStruct c1_pj_SignalExportProp;
  SignalExportStruct c1_qj_SignalExportProp;
  rtwCAPI_ModelMappingInfo c1_testPointMappingInfo;
  void *c1_testPointAddrMap[13];
  void *c1_fEmlrtCtx;
  uint8_T *c1_clutchCurrVal;
  uint16_T (*c1_lastModeCom)[2];
  uint16_T (*c1_shiftCom)[2];
  uint8_T *c1_startEngCom;
  uint16_T (*c1_aacCom)[2];
  uint8_T *c1_clutchTarget;
  uint16_T (*c1_modeCom)[2];
  uint16_T *c1_stateFb;
  int32_T (*c1_acc_parameters)[16];
  int32_T (*c1_timings)[24];
  uint16_T (*c1_autoXCom)[2];
  int32_T (*c1_autoX_parameters)[16];
  uint8_T *c1_slipUpdateCounter;
  uint8_T *c1_antiStallEnable;
  int32_T (*c1_antiStall_parameters)[8];
  uint16_T *c1_antiStallFb;
  uint32_T (*c1_gearMotorCurent_1_2)[2];
  uint16_T *c1_currGear;
  uint16_T *c1_currTps;
  uint16_T *c1_currRpm;
  uint16_T *c1_currVhSpeed;
  uint16_T *c1_currSlip;
  uint16_T *c1_currSlipTarget;
  uint16_T *c1_pidSubMode;
  uint32_T *c1_pidCounter;
  real_T *c1_I1_L;
  real_T *c1_I2_L;
  uint16_T *c1_canErrorCom;
  real_T *c1_slipTarget;
  real_T *c1_currentSlip;
  real_T *c1_clutchVal;
  real_T *c1_reset;
  real_T *c1_b_slipTarget;
  real_T *c1_b_currentSlip;
  real_T *c1_b_clutchVal;
  real_T *c1_b_reset;
  real_T *c1_c_slipTarget;
  real_T *c1_c_currentSlip;
  real_T *c1_c_clutchVal;
  real_T *c1_c_reset;
  real_T *c1_d_slipTarget;
  real_T *c1_d_currentSlip;
  real_T *c1_d_clutchVal;
  real_T *c1_d_reset;
  real_T *c1_e_slipTarget;
  real_T *c1_e_currentSlip;
  real_T *c1_e_clutchVal;
  real_T *c1_e_reset;
  real_T *c1_f_slipTarget;
  real_T *c1_f_currentSlip;
  real_T *c1_f_clutchVal;
  real_T *c1_f_reset;
  real_T *c1_g_slipTarget;
  real_T *c1_g_currentSlip;
  real_T *c1_g_reset;
  real_T *c1_g_clutchVal;
  real_T *c1_h_slipTarget;
  real_T *c1_h_currentSlip;
  real_T *c1_h_reset;
  real_T *c1_h_clutchVal;
  real_T *c1_i_slipTarget;
  real_T *c1_i_currentSlip;
  real_T *c1_i_reset;
  real_T *c1_i_clutchVal;
  real_T *c1_j_slipTarget;
  real_T *c1_j_currentSlip;
  real_T *c1_j_reset;
  real_T *c1_j_clutchVal;
  boolean_T *c1_out;
  real_T *c1_time;
  real_T *c1_current;
} SFc1_GCU_Model_genCodeInstanceStruct;

#endif                                 /*typedef_SFc1_GCU_Model_genCodeInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_GCU_Model_genCode_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c1_GCU_Model_genCode_get_check_sum(mxArray *plhs[]);
extern void c1_GCU_Model_genCode_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
