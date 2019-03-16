#ifndef __c1_C_model_h__
#define __c1_C_model_h__

/* Type Definitions */
#ifndef typedef_SFc1_C_modelInstanceStruct
#define typedef_SFc1_C_modelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_ff;
  uint8_T c1_is_active_c1_C_model;
  uint8_T c1_is_c1_C_model;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
  void *c1_fEmlrtCtx;
  uint16_T *c1_data;
} SFc1_C_modelInstanceStruct;

#endif                                 /*typedef_SFc1_C_modelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_C_model_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_C_model_get_check_sum(mxArray *plhs[]);
extern void c1_C_model_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
