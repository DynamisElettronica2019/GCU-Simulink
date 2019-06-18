#ifndef __c8_GCU_Model_genCode_h__
#define __c8_GCU_Model_genCode_h__

/* Type Definitions */
#ifndef enum_anti_stall_params
#define enum_anti_stall_params

enum anti_stall_params
{
  anti_stall_params_RPM_THRESHOLD = 0, /* Default value */
  anti_stall_params_RPM_DELTA_THRESHOLD,
  anti_stall_params_GEAR_THRESHOLD
};

#endif                                 /*enum_anti_stall_params*/

#ifndef typedef_c8_anti_stall_params
#define typedef_c8_anti_stall_params

typedef enum anti_stall_params c8_anti_stall_params;

#endif                                 /*typedef_c8_anti_stall_params*/

#ifndef typedef_SFc8_GCU_Model_genCodeInstanceStruct
#define typedef_SFc8_GCU_Model_genCodeInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c8_sfEvent;
  boolean_T c8_doneDoubleBufferReInit;
  uint8_T c8_is_active_c8_GCU_Model_genCode;
  uint8_T c8_doSetSimStateSideEffects;
  const mxArray *c8_setSimStateSideEffectsInfo;
  void *c8_fEmlrtCtx;
  uint8_T *c8_enable;
  uint8_T *c8_stop;
  int32_T (*c8_antiStall_parameters)[8];
  real_T *c8_rpm;
  real_T *c8_deltarpm;
  uint16_T *c8_antiStallFb;
  uint8_T *c8_currGear;
  real_T *c8_antiStallState;
  uint8_T *c8_antiStallClutchVal;
  uint8_T *c8_Inport;
} SFc8_GCU_Model_genCodeInstanceStruct;

#endif                                 /*typedef_SFc8_GCU_Model_genCodeInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c8_GCU_Model_genCode_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c8_GCU_Model_genCode_get_check_sum(mxArray *plhs[]);
extern void c8_GCU_Model_genCode_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
