#ifndef __c4_GCU_CAN_C_h__
#define __c4_GCU_CAN_C_h__

/* Type Definitions */
#ifndef enum_aac_values
#define enum_aac_values

enum aac_values
{
  aac_values_RPM = 0,                  /* Default value */
  aac_values_WHEEL_SPEED,
  aac_values_APPS
};

#endif                                 /*enum_aac_values*/

#ifndef typedef_c4_aac_values
#define typedef_c4_aac_values

typedef enum aac_values c4_aac_values;

#endif                                 /*typedef_c4_aac_values*/

#ifndef typedef_SFc4_GCU_CAN_CInstanceStruct
#define typedef_SFc4_GCU_CAN_CInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_GCU_CAN_C;
  uint16_T c4_STOP_COM;
  uint16_T c4_b_STOP_COM;
  uint16_T c4_GEAR_COMMAND_NEUTRAL_DOWN;
  uint16_T c4_GEAR_COMMAND_NEUTRAL_UP;
  uint16_T c4_GEAR_COMMAND_DOWN;
  uint8_T c4_clutchTarget;
  uint16_T c4_c_STOP_COM;
  uint8_T c4_ACC_CLUTCH_NOISE_LEVEL;
  uint16_T c4_d_STOP_COM;
  uint16_T c4_e_STOP_COM;
  uint8_T c4_doSetSimStateSideEffects;
  const mxArray *c4_setSimStateSideEffectsInfo;
  void *c4_fEmlrtCtx;
  uint16_T *c4_Id;
  uint16_T *c4_firstInt;
  uint16_T *c4_secondInt;
  uint16_T *c4_thirdInt;
  uint16_T *c4_fourthInt;
  real_T *c4_out;
  uint16_T *c4_currGear;
  uint16_T *c4_aac_externValue;
  uint16_T *c4_aac_externValues_index;
  uint16_T (*c4_shiftCommand)[2];
  uint8_T *c4_startEngCommand;
  uint16_T (*c4_accCommand)[2];
  uint16_T *c4_tractionTarget;
  uint8_T (*c4_clutchCommand)[2];
  uint8_T *c4_clutchCurrVal;
  uint16_T (*c4_modeCommand)[2];
  uint16_T *c4_accParametersValue;
  uint16_T *c4_accParametersIndex;
  uint16_T *c4_timingsValue;
  uint16_T *c4_timingsIndex;
  uint16_T *c4_mapTarget;
  uint16_T *c4_rpmLimiterTarget;
} SFc4_GCU_CAN_CInstanceStruct;

#endif                                 /*typedef_SFc4_GCU_CAN_CInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_GCU_CAN_C_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_GCU_CAN_C_get_check_sum(mxArray *plhs[]);
extern void c4_GCU_CAN_C_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
