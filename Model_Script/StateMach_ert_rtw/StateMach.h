/*
 * File: StateMach.h
 *
 * Code generated for Simulink model 'StateMach'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Thu Feb 17 23:12:31 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_StateMach_h_
#define RTW_HEADER_StateMach_h_
#ifndef StateMach_COMMON_INCLUDES_
# define StateMach_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* StateMach_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  uint16_T debTime;                    /* '<Root>/State_LedBtn' */
  uint8_T is_active_c3_StateMach;      /* '<Root>/State_LedBtn' */
  uint8_T is_c3_StateMach;             /* '<Root>/State_LedBtn' */
} DW;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  boolean_T In_Btn;                    /* '<Root>/In_Btn' */
  uint16_T In_DebTime;                 /* '<Root>/In_DebTime' */
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  boolean_T Out_Ld;                    /* '<Root>/Out_Ld' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (auto storage) */
extern DW rtDW;

/* External inputs (root inport signals with auto storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void StateMach_initialize(void);
extern void StateMach_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

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
 * '<Root>' : 'StateMach'
 * '<S1>'   : 'StateMach/State_LedBtn'
 */
#endif                                 /* RTW_HEADER_StateMach_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
