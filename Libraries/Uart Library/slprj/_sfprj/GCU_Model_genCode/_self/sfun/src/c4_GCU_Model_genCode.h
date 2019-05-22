#ifndef __c4_GCU_Model_genCode_h__
#define __c4_GCU_Model_genCode_h__

/* Type Definitions */
#ifndef typedef_SFc4_GCU_Model_genCodeInstanceStruct
#define typedef_SFc4_GCU_Model_genCodeInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_GCU_Model_genCode;
  uint8_T c4_doSetSimStateSideEffects;
  const mxArray *c4_setSimStateSideEffectsInfo;
  void *c4_fEmlrtCtx;
  uint16_T *c4_gcu_traction_limiter_loil_efi_id;
  uint16_T *c4_gcu_clutch_mode_map_sw_id;
  uint16_T *c4_gcu_traction_limiter_autog_acc_sw_id;
  uint16_T *c4_gcu_debug_1_id;
  uint16_T *c4_gcu_debug_2_id;
} SFc4_GCU_Model_genCodeInstanceStruct;

#endif                                 /*typedef_SFc4_GCU_Model_genCodeInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_GCU_Model_genCode_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c4_GCU_Model_genCode_get_check_sum(mxArray *plhs[]);
extern void c4_GCU_Model_genCode_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
