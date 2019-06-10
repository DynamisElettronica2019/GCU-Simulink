/* Include files */

#define IN_SF_MACHINE_SOURCE           1
#include "GCU_Model_genCode_sfun.h"
#include "GCU_Model_genCode_sfun_debug_macros.h"
#include "c1_GCU_Model_genCode.h"
#include "c2_GCU_Model_genCode.h"
#include "c4_GCU_Model_genCode.h"
#include "c8_GCU_Model_genCode.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _GCU_Model_genCodeMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void GCU_Model_genCode_initializer(void)
{
}

void GCU_Model_genCode_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_GCU_Model_genCode_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_GCU_Model_genCode_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_GCU_Model_genCode_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_GCU_Model_genCode_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_GCU_Model_genCode_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_GCU_Model_genCode_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4205344304U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3837958942U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3748599752U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2281856281U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_GCU_Model_genCode_get_check_sum(mxArray *plhs[]);
          sf_c1_GCU_Model_genCode_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_GCU_Model_genCode_get_check_sum(mxArray *plhs[]);
          sf_c2_GCU_Model_genCode_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_GCU_Model_genCode_get_check_sum(mxArray *plhs[]);
          sf_c4_GCU_Model_genCode_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_GCU_Model_genCode_get_check_sum(mxArray *plhs[]);
          sf_c8_GCU_Model_genCode_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3396320905U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3534093100U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1163356009U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1282337809U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2902997441U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1750052129U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1649502381U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3287871486U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_GCU_Model_genCode_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "esqDYHVBT8zfveGKuwf9HG") == 0) {
          extern mxArray *sf_c1_GCU_Model_genCode_get_autoinheritance_info(void);
          plhs[0] = sf_c1_GCU_Model_genCode_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "lWv88Bn0onC6PMtPZdrk1E") == 0) {
          extern mxArray *sf_c2_GCU_Model_genCode_get_autoinheritance_info(void);
          plhs[0] = sf_c2_GCU_Model_genCode_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "MtlUQhpwbIOQ6yVjy2E9DC") == 0) {
          extern mxArray *sf_c4_GCU_Model_genCode_get_autoinheritance_info(void);
          plhs[0] = sf_c4_GCU_Model_genCode_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "nyc7jVNDW10ZcmM1KJTQgG") == 0) {
          extern mxArray *sf_c8_GCU_Model_genCode_get_autoinheritance_info(void);
          plhs[0] = sf_c8_GCU_Model_genCode_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_GCU_Model_genCode_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  char instanceChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    mxGetString(prhs[2], instanceChksum,sizeof(instanceChksum)/sizeof(char));
    instanceChksum[(sizeof(instanceChksum)/sizeof(char)-1)] = '\0';
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(instanceChksum, "seB97c4jlif5ElZb0RP2zWF") == 0) {
          extern const mxArray
            *sf_c1_GCU_Model_genCode_get_eml_resolved_functions_info(void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c1_GCU_Model_genCode_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     case 2:
      {
        if (strcmp(instanceChksum, "s9pNSV2LWbzZ9FkHOepVXzD") == 0) {
          extern const mxArray
            *sf_c2_GCU_Model_genCode_get_eml_resolved_functions_info(void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c2_GCU_Model_genCode_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     case 4:
      {
        if (strcmp(instanceChksum, "souaVfS7EeeIE1tFQdFJzVH") == 0) {
          extern const mxArray
            *sf_c4_GCU_Model_genCode_get_eml_resolved_functions_info(void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c4_GCU_Model_genCode_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     case 8:
      {
        if (strcmp(instanceChksum, "s3sb1UIv7mho1UH4CvwMqN") == 0) {
          extern const mxArray
            *sf_c8_GCU_Model_genCode_get_eml_resolved_functions_info(void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c8_GCU_Model_genCode_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_GCU_Model_genCode_third_party_uses_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "seB97c4jlif5ElZb0RP2zWF") == 0) {
          extern mxArray *sf_c1_GCU_Model_genCode_third_party_uses_info(void);
          plhs[0] = sf_c1_GCU_Model_genCode_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "s9pNSV2LWbzZ9FkHOepVXzD") == 0) {
          extern mxArray *sf_c2_GCU_Model_genCode_third_party_uses_info(void);
          plhs[0] = sf_c2_GCU_Model_genCode_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "souaVfS7EeeIE1tFQdFJzVH") == 0) {
          extern mxArray *sf_c4_GCU_Model_genCode_third_party_uses_info(void);
          plhs[0] = sf_c4_GCU_Model_genCode_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "s3sb1UIv7mho1UH4CvwMqN") == 0) {
          extern mxArray *sf_c8_GCU_Model_genCode_third_party_uses_info(void);
          plhs[0] = sf_c8_GCU_Model_genCode_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_GCU_Model_genCode_jit_fallback_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the jit_fallback_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_jit_fallback_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "seB97c4jlif5ElZb0RP2zWF") == 0) {
          extern mxArray *sf_c1_GCU_Model_genCode_jit_fallback_info(void);
          plhs[0] = sf_c1_GCU_Model_genCode_jit_fallback_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "s9pNSV2LWbzZ9FkHOepVXzD") == 0) {
          extern mxArray *sf_c2_GCU_Model_genCode_jit_fallback_info(void);
          plhs[0] = sf_c2_GCU_Model_genCode_jit_fallback_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "souaVfS7EeeIE1tFQdFJzVH") == 0) {
          extern mxArray *sf_c4_GCU_Model_genCode_jit_fallback_info(void);
          plhs[0] = sf_c4_GCU_Model_genCode_jit_fallback_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "s3sb1UIv7mho1UH4CvwMqN") == 0) {
          extern mxArray *sf_c8_GCU_Model_genCode_jit_fallback_info(void);
          plhs[0] = sf_c8_GCU_Model_genCode_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_GCU_Model_genCode_updateBuildInfo_args_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "seB97c4jlif5ElZb0RP2zWF") == 0) {
          extern mxArray *sf_c1_GCU_Model_genCode_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_GCU_Model_genCode_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "s9pNSV2LWbzZ9FkHOepVXzD") == 0) {
          extern mxArray *sf_c2_GCU_Model_genCode_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_GCU_Model_genCode_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "souaVfS7EeeIE1tFQdFJzVH") == 0) {
          extern mxArray *sf_c4_GCU_Model_genCode_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_GCU_Model_genCode_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "s3sb1UIv7mho1UH4CvwMqN") == 0) {
          extern mxArray *sf_c8_GCU_Model_genCode_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_GCU_Model_genCode_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void GCU_Model_genCode_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _GCU_Model_genCodeMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "GCU_Model_genCode","sfun",0,9,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _GCU_Model_genCodeMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _GCU_Model_genCodeMachineNumber_,0);
}

void GCU_Model_genCode_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
typedef struct SfOptimizationInfoFlagsTag {
  boolean_T isRtwGen;
  boolean_T isModelRef;
  boolean_T isExternal;
} SfOptimizationInfoFlags;

static SfOptimizationInfoFlags sOptimizationInfoFlags;
void unload_GCU_Model_genCode_optimization_info(void);
mxArray* load_GCU_Model_genCode_optimization_info(boolean_T isRtwGen, boolean_T
  isModelRef, boolean_T isExternal)
{
  if (sOptimizationInfoFlags.isRtwGen != isRtwGen ||
      sOptimizationInfoFlags.isModelRef != isModelRef ||
      sOptimizationInfoFlags.isExternal != isExternal) {
    unload_GCU_Model_genCode_optimization_info();
  }

  sOptimizationInfoFlags.isRtwGen = isRtwGen;
  sOptimizationInfoFlags.isModelRef = isModelRef;
  sOptimizationInfoFlags.isExternal = isExternal;
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "GCU_Model_genCode", "GCU_Model_genCode");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_GCU_Model_genCode_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
