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
  acc_params_TPS_START_LIMIT
};

#endif                                 /*enum_acc_params*/

#ifndef typedef_c1_acc_params
#define typedef_c1_acc_params

typedef enum acc_params c1_acc_params;

#endif                                 /*typedef_c1_acc_params*/

#ifndef enum_acc_values
#define enum_acc_values

enum acc_values
{
  acc_values_RPM = 0,                  /* Default value */
  acc_values_WHEEL_SPEED,
  acc_values_TPS
};

#endif                                 /*enum_acc_values*/

#ifndef typedef_c1_acc_values
#define typedef_c1_acc_values

typedef enum acc_values c1_acc_values;

#endif                                 /*typedef_c1_acc_values*/

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
  uint8_T c1_tp_AUTOCROSS;
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
  uint8_T c1_tp_NotReady;
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
  uint8_T c1_tp_START_ENGINE;
  uint8_T c1_tp_WAIT;
  uint8_T c1_b_tp_START;
  uint8_T c1_tp_STOP;
  uint8_T c1_tp_SCAN_ADC;
  uint8_T c1_b_tp_WAIT;
  uint8_T c1_tp_SCAN;
  uint8_T c1_tp_EEPROM_TRIGGER;
  uint8_T c1_c_tp_WAIT;
  uint8_T c1_tp_SEND;
  uint8_T c1_is_active_c1_GCU_Model_genCode;
  uint8_T c1_is_MODES;
  uint8_T c1_is_active_MODES;
  uint8_T c1_is_MANUAL_MODES;
  uint8_T c1_is_ACCELERATION;
  uint8_T c1_is_ACC;
  uint8_T c1_is_ACTIVE;
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
  uint8_T c1_is_START_ENGINE;
  uint8_T c1_is_active_START_ENGINE;
  uint8_T c1_is_SCAN_ADC;
  uint8_T c1_is_active_SCAN_ADC;
  uint8_T c1_is_EEPROM_TRIGGER;
  uint8_T c1_is_active_EEPROM_TRIGGER;
  uint8_T c1_lastShift;
  uint16_T c1_lastAacCom;
  uint16_T c1_lastShiftCom;
  uint8_T c1_lastClutchCom;
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
  int32_T c1_ticksCounter;
  real_T c1_data;
  real_T c1_counterWait;
  uint8_T c1_lastCom;
  uint8_T c1_startCounter;
  uint16_T c1_timerCounter;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
  void *c1_dataSetLogObjVector[2];
  uint8_T c1_sdiLoggedStatesBuffer[58];
  uint8_T c1_sdiLoggedDataBuffer[51];
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
  rtwCAPI_ModelMappingInfo c1_testPointMappingInfo;
  void *c1_testPointAddrMap[2];
  void *c1_fEmlrtCtx;
  uint8_T *c1_currentGear;
  uint8_T *c1_clutchCurrVal;
  uint16_T (*c1_lastModeCom)[2];
  uint16_T (*c1_shiftCom)[2];
  uint8_T *c1_startEngCom;
  uint16_T (*c1_aacCom)[2];
  uint16_T (*c1_acc_externValues)[3];
  uint8_T (*c1_clutchCom)[2];
  uint16_T (*c1_modeCom)[2];
  uint16_T *c1_accFb;
  int32_T (*c1_acc_parameters)[12];
  int32_T (*c1_timings)[23];
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
