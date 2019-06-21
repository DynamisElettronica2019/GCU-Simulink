#ifndef __c2_GCU_Model_genCode_h__
#define __c2_GCU_Model_genCode_h__

/* Type Definitions */
#ifndef enum_can_data
#define enum_can_data

enum can_data
{
  can_data_RPM = 0,                    /* Default value */
  can_data_VH_SPEED,
  can_data_TPS,
  can_data_SLIP,
  can_data_SLIP_TARGET,
  can_data_GEAR_ADbits,
  can_data_GEAR
};

#endif                                 /*enum_can_data*/

#ifndef typedef_c2_can_data
#define typedef_c2_can_data

typedef enum can_data c2_can_data;

#endif                                 /*typedef_c2_can_data*/

#ifndef typedef_SFc2_GCU_Model_genCodeInstanceStruct
#define typedef_SFc2_GCU_Model_genCodeInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_GCU_Model_genCode;
  uint16_T c2_STOP_COM;
  uint16_T c2_b_STOP_COM;
  uint16_T c2_GEAR_COMMAND_NEUTRAL_DOWN;
  uint16_T c2_GEAR_COMMAND_NEUTRAL_UP;
  uint16_T c2_GEAR_COMMAND_DOWN;
  uint16_T c2_c_STOP_COM;
  uint8_T c2_CLUTCH_NOISE_LEVEL;
  uint16_T c2_d_STOP_COM;
  uint16_T c2_e_STOP_COM;
  uint8_T c2_doSetSimStateSideEffects;
  const mxArray *c2_setSimStateSideEffectsInfo;
  void *c2_fEmlrtCtx;
  uint16_T *c2_Id;
  uint16_T *c2_firstInt;
  uint16_T *c2_secondInt;
  uint16_T *c2_thirdInt;
  uint16_T *c2_fourthInt;
  real_T *c2_out;
  uint16_T *c2_currGear;
  uint16_T *c2_acc_externValue;
  uint16_T *c2_acc_externValues_index;
  uint16_T (*c2_shiftCommand)[2];
  uint8_T *c2_startEngCommand;
  uint16_T (*c2_accCommand)[2];
  uint16_T *c2_tractionTarget;
  uint8_T *c2_clutchTarget;
  uint8_T *c2_clutchCurrVal;
  uint16_T (*c2_modeCommand)[2];
  uint16_T *c2_mapTarget;
  uint16_T *c2_rpmLimiterTarget;
  uint16_T (*c2_autoXCommand)[2];
  uint8_T *c2_stopAntiStallCom;
  uint8_T *c2_rpmUpdateCounter;
  uint8_T *c2_slipUpdateCounter;
  uint16_T (*c2_canData_ValuesArray)[7];
  uint8_T *c2_map;
} SFc2_GCU_Model_genCodeInstanceStruct;

#endif                                 /*typedef_SFc2_GCU_Model_genCodeInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_GCU_Model_genCode_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c2_GCU_Model_genCode_get_check_sum(mxArray *plhs[]);
extern void c2_GCU_Model_genCode_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
