#ifndef __c2_GCU_Model_genCode_h__
#define __c2_GCU_Model_genCode_h__

/* Type Definitions */
#ifndef enum_acc_values
#define enum_acc_values

enum acc_values
{
  acc_values_RPM = 0,                  /* Default value */
  acc_values_WHEEL_SPEED,
  acc_values_TPS
};

#endif                                 /*enum_acc_values*/

#ifndef typedef_c2_acc_values
#define typedef_c2_acc_values

typedef enum acc_values c2_acc_values;

#endif                                 /*typedef_c2_acc_values*/

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
  uint8_T c2_clutchTarget;
  uint16_T c2_c_STOP_COM;
  uint8_T c2_ACC_CLUTCH_NOISE_LEVEL;
  uint16_T c2_d_STOP_COM;
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
  uint8_T (*c2_clutchCommand)[2];
  uint8_T *c2_clutchCurrVal;
  uint16_T (*c2_modeCommand)[2];
  uint16_T *c2_accParametersValue;
  uint16_T *c2_accParametersIndex;
  uint16_T *c2_timingsValue;
  uint16_T *c2_timingsIndex;
  uint16_T *c2_mapTarget;
  uint16_T *c2_rpmLimiterTarget;
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
