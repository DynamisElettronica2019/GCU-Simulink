/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GCU_CAN_debug.h
 *
 * Code generated for Simulink model 'GCU_CAN_debug'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Sat Mar 30 12:39:19 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_GCU_CAN_debug_h_
#define RTW_HEADER_GCU_CAN_debug_h_
#include "rtwtypes.h"
#ifndef GCU_CAN_debug_COMMON_INCLUDES_
# define GCU_CAN_debug_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* GCU_CAN_debug_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#ifndef DEFINED_TYPEDEF_FOR_aac_values_
#define DEFINED_TYPEDEF_FOR_aac_values_

typedef enum {
  RPM = 0,                             /* Default value */
  WHEEL_SPEED,
  APPS
} aac_values;

#endif

/* Block signals and states (default storage) for system '<Root>/TractionValue' */
typedef struct {
  uint16_T Divide;                     /* '<S5>/Divide' */
  uint16_T UnitDelay_DSTATE;           /* '<S5>/Unit Delay' */
  uint8_T PackCanUart[10];             /* '<S8>/PackCanUart' */
  uint8_T PackCanUart_n[10];           /* '<S9>/PackCanUart' */
} DW_TractionValue;

/* Block signals and states (default storage) for system '<S3>/Efi_setRpmLimiter' */
typedef struct {
  uint8_T EfiSetRPMLimiter;            /* '<S6>/Efi SetRPMLimiter' */
} DW_Efi_setRpmLimiter;

/* Block signals and states (default storage) for system '<S3>/Efi_unsetRpmLimiter' */
typedef struct {
  uint8_T EfiUnSetRPMLimiter;          /* '<S7>/Efi UnSetRPMLimiter' */
} DW_Efi_unsetRpmLimiter;

/* Block signals and states (default storage) for system '<Root>/AAC_ExternalValues' */
typedef struct {
  uint16_T UnitDelay_DSTATE[3];        /* '<S1>/Unit Delay' */
} DW_AAC_ExternalValues;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_AAC_ExternalValues AAC_ExternalValues_p;/* '<Root>/AAC_ExternalValues' */
  DW_Efi_unsetRpmLimiter Efi_unsetRpmLimiter_a;/* '<S3>/Efi_unsetRpmLimiter' */
  DW_Efi_setRpmLimiter Efi_setRpmLimiter_c;/* '<S3>/Efi_setRpmLimiter' */
  DW_TractionValue TractionValue_h;    /* '<Root>/TractionValue' */
  uint16_T shiftCommand[2];            /* '<Root>/MessageEvaluation' */
  uint16_T aacCommand[2];              /* '<Root>/MessageEvaluation' */
  uint16_T modeCommand[2];             /* '<Root>/MessageEvaluation' */
  uint16_T Assignment[3];              /* '<S1>/Assignment' */
  uint16_T TmpSignalConversionAtPack_Uart_[10];
  volatile uint16_T RateTransition1_Buffer0[2];/* '<Root>/Rate Transition1' */
  volatile uint16_T RateTransition11_Buffer0[3];/* '<Root>/Rate Transition11' */
  volatile uint16_T RateTransition2_Buffer0[2];/* '<Root>/Rate Transition2' */
  volatile uint16_T RateTransition3_Buffer0[2];/* '<Root>/Rate Transition3' */
  uint16_T UnpackCanUart_o1;           /* '<Root>/UnpackCanUart' */
  uint16_T UnpackCanUart_o2;           /* '<Root>/UnpackCanUart' */
  uint16_T UnpackCanUart_o3;           /* '<Root>/UnpackCanUart' */
  uint16_T UnpackCanUart_o4;           /* '<Root>/UnpackCanUart' */
  uint16_T UnpackCanUart_o5;           /* '<Root>/UnpackCanUart' */
  uint16_T currGear;                   /* '<Root>/MessageEvaluation' */
  uint16_T Assignment_e;               /* '<S5>/Assignment' */
  volatile int8_T RateTransition1_semaphoreTaken;/* '<Root>/Rate Transition1' */
  volatile int8_T RateTransition11_semaphoreTaken;/* '<Root>/Rate Transition11' */
  volatile int8_T RateTransition2_semaphoreTaken;/* '<Root>/Rate Transition2' */
  volatile int8_T RateTransition3_semaphoreTaken;/* '<Root>/Rate Transition3' */
  volatile int8_T RateTransition15_semaphoreTaken;/* '<Root>/Rate Transition15' */
  uint8_T clutchCommand[2];            /* '<Root>/MessageEvaluation' */
  uint8_T Pack_Uart_Message1[20];      /* '<S2>/Pack_Uart_Message1' */
  volatile uint8_T RateTransition15_Buffer0[2];/* '<Root>/Rate Transition15' */
  uint8_T Merge;                       /* '<S3>/Merge' */
  uint8_T startEngCommand;             /* '<Root>/MessageEvaluation' */
  uint8_T is_active_c2_GCU_CAN_debug;  /* '<Root>/MessageEvaluation' */
  uint8_T is_c2_GCU_CAN_debug;         /* '<Root>/MessageEvaluation' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: GCU_TRACTION_CONTROL_EFI_ID_Val
   * Referenced by: '<S8>/GCU_TRACTION_CONTROL_EFI_ID'
   */
  uint16_T GCU_TRACTION_CONTROL_EFI_ID_Val;

  /* Computed Parameter: GCU_FEEDBACK_ID_Value
   * Referenced by: '<S9>/GCU_FEEDBACK_ID'
   */
  uint16_T GCU_FEEDBACK_ID_Value;

  /* Computed Parameter: TRACTION_CODE_Value
   * Referenced by: '<S5>/TRACTION_CODE'
   */
  uint16_T TRACTION_CODE_Value;
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint8_T clutchCurrVal;               /* '<Root>/clutchCurrVal' */
  uint8_T dataBuffer[10];              /* '<Root>/dataBuffer' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint16_T currGear;                   /* '<Root>/currGear' */
  uint16_T aac_externValue[3];         /* '<Root>/aac_externValue' */
  uint16_T shiftCommand[2];            /* '<Root>/shiftCommand' */
  uint8_T startEngCommand;             /* '<Root>/startEngCommand' */
  uint16_T aacCommand[2];              /* '<Root>/aacCommand' */
  uint8_T clutchCommand[2];            /* '<Root>/clutchCommand' */
  uint16_T modeCommand[2];             /* '<Root>/modeCommand' */
  uint16_T tractionValue;              /* '<Root>/tractionValue' */
  uint8_T rpmLimiter_pin;              /* '<Root>/rpmLimiter_pin' */
  uint16_T debugValues[10];            /* '<Root>/debugValues  ' */
  uint16_T id;                         /* '<Root>/id' */
  uint16_T firstInt;                   /* '<Root>/firstInt' */
  uint16_T secondInt;                  /* '<Root>/secondInt' */
  uint16_T thirdInt;                   /* '<Root>/thirdInt' */
  uint16_T fourthInt;                  /* '<Root>/fourthInt' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* External data declarations for dependent source files */
extern const uint16_T GCU_CAN_debug_U16GND;/* uint16_T ground */

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void GCU_CAN_debug_initialize(void);
extern void GCU_CAN_debug_step0(void);
extern void GCU_CAN_debug_step1(void);
extern void GCU_CAN_debug_step2(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Scope1' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'GCU_CAN_debug'
 * '<S1>'   : 'GCU_CAN_debug/AAC_ExternalValues'
 * '<S2>'   : 'GCU_CAN_debug/Debug '
 * '<S3>'   : 'GCU_CAN_debug/EfiRPMLimiter'
 * '<S4>'   : 'GCU_CAN_debug/MessageEvaluation'
 * '<S5>'   : 'GCU_CAN_debug/TractionValue'
 * '<S6>'   : 'GCU_CAN_debug/EfiRPMLimiter/Efi_setRpmLimiter'
 * '<S7>'   : 'GCU_CAN_debug/EfiRPMLimiter/Efi_unsetRpmLimiter'
 * '<S8>'   : 'GCU_CAN_debug/TractionValue/Efi_setTraction'
 * '<S9>'   : 'GCU_CAN_debug/TractionValue/sendUpdatesSW'
 */
#endif                                 /* RTW_HEADER_GCU_CAN_debug_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
