/*
 * File: WaitTime.c
 *
 * Code generated for Simulink model 'WaitTime'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Feb 15 23:33:07 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "WaitTime.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void WaitTime_step(void)
{
  real_T lastSin_tmp;

  /* Sin: '<Root>/Sine Wave' */
  if (rtDW.systemEnable != 0) {
    lastSin_tmp = 0.1 * ((rtM->Timing.clockTick0) * 1.0);
    rtDW.lastSin = sin(lastSin_tmp);
    rtDW.lastCos = cos(lastSin_tmp);
    rtDW.systemEnable = 0;
  }

  /* Outport: '<Root>/WaitTime' incorporates:
   *  Gain: '<Root>/Gain'
   *  Sin: '<Root>/Sine Wave'
   */
  rtY.WaitTime_g = (((rtDW.lastSin * 0.99500416527802571 + rtDW.lastCos *
                      -0.099833416646828155) * 0.99500416527802571 +
                     (rtDW.lastCos * 0.99500416527802571 - rtDW.lastSin *
                      -0.099833416646828155) * 0.099833416646828155) * 0.2 +
                    0.25) * 1000.0;

  /* Update for Sin: '<Root>/Sine Wave' */
  lastSin_tmp = rtDW.lastSin;
  rtDW.lastSin = rtDW.lastSin * 0.99500416527802571 + rtDW.lastCos *
    0.099833416646828155;
  rtDW.lastCos = rtDW.lastCos * 0.99500416527802571 - lastSin_tmp *
    0.099833416646828155;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 1.0, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  rtM->Timing.clockTick0++;
}

/* Model initialize function */
void WaitTime_initialize(void)
{
  /* Enable for Sin: '<Root>/Sine Wave' */
  rtDW.systemEnable = 1;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
