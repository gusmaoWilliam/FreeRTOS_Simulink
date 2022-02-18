/*
 * File: StateMach.c
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

#include "StateMach.h"

/* Named constants for Chart: '<Root>/State_LedBtn' */
#define IN_Debounce                    ((uint8_T)1U)
#define IN_Led_Off                     ((uint8_T)2U)
#define IN_Led_On                      ((uint8_T)3U)

/* Block signals and states (auto storage) */
DW rtDW;

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void StateMach_step(void)
{
  uint32_T tmp;

  /* Chart: '<Root>/State_LedBtn' incorporates:
   *  Inport: '<Root>/In_Btn'
   *  Inport: '<Root>/In_DebTime'
   */
  /* Gateway: State_LedBtn */
  /* During: State_LedBtn */
  if (rtDW.is_active_c3_StateMach == 0U) {
    /* Entry: State_LedBtn */
    rtDW.is_active_c3_StateMach = 1U;

    /* Entry Internal: State_LedBtn */
    /* Transition: '<S1>:4' */
    rtDW.is_c3_StateMach = IN_Led_Off;

    /* Outport: '<Root>/Out_Ld' */
    /* Entry 'Led_Off': '<S1>:3' */
    /* '<S1>:3:1' Out_Led = false; */
    rtY.Out_Ld = false;
  } else {
    switch (rtDW.is_c3_StateMach) {
     case IN_Debounce:
      /* During 'Debounce': '<S1>:5' */
      /* '<S1>:8:1' sf_internal_predicateOutput = ... */
      /* '<S1>:8:1' (debTime > KdebTime) && (In_Button == true); */
      if ((rtDW.debTime > rtU.In_DebTime) && rtU.In_Btn) {
        /* Transition: '<S1>:8' */
        rtDW.is_c3_StateMach = IN_Led_On;

        /* Outport: '<Root>/Out_Ld' */
        /* Entry 'Led_On': '<S1>:7' */
        /* '<S1>:7:1' Out_Led = true; */
        rtY.Out_Ld = true;
      } else {
        /* '<S1>:11:1' sf_internal_predicateOutput = ... */
        /* '<S1>:11:1' (debTime > KdebTime) && (In_Button == false); */
        if ((rtDW.debTime > rtU.In_DebTime) && (!rtU.In_Btn)) {
          /* Transition: '<S1>:11' */
          rtDW.is_c3_StateMach = IN_Led_Off;

          /* Outport: '<Root>/Out_Ld' */
          /* Entry 'Led_Off': '<S1>:3' */
          /* '<S1>:3:1' Out_Led = false; */
          rtY.Out_Ld = false;
        } else {
          /* '<S1>:5:1' debTime = debTime + 1.0; */
          tmp = rtDW.debTime + 1U;
          if (tmp > 65535U) {
            tmp = 65535U;
          }

          rtDW.debTime = (uint16_T)tmp;
        }
      }
      break;

     case IN_Led_Off:
      /* During 'Led_Off': '<S1>:3' */
      /* '<S1>:6:1' sf_internal_predicateOutput = ... */
      /* '<S1>:6:1' In_Button == true; */
      if (rtU.In_Btn) {
        /* Transition: '<S1>:6' */
        rtDW.is_c3_StateMach = IN_Debounce;

        /* Entry 'Debounce': '<S1>:5' */
        /* '<S1>:5:1' debTime = uint16(0.0); */
        rtDW.debTime = 0U;
      }
      break;

     default:
      /* During 'Led_On': '<S1>:7' */
      /* '<S1>:9:1' sf_internal_predicateOutput = ... */
      /* '<S1>:9:1' In_Button == false; */
      if (!rtU.In_Btn) {
        /* Transition: '<S1>:9' */
        rtDW.is_c3_StateMach = IN_Debounce;

        /* Entry 'Debounce': '<S1>:5' */
        /* '<S1>:5:1' debTime = uint16(0.0); */
        rtDW.debTime = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/State_LedBtn' */
}

/* Model initialize function */
void StateMach_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
