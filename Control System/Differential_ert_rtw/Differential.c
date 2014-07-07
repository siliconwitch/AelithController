/*
 * File: Differential.c
 *
 * Code generated for Simulink model 'Differential'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Mon Jul 07 11:52:22 2014
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Differential.h"
#include "Differential_private.h"

/* External inputs (root inport signals with auto storage) */
ExtU_Differential_T Differential_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Differential_T Differential_Y;

/* Real-time model */
RT_MODEL_Differential_T Differential_M_;
RT_MODEL_Differential_T *const Differential_M = &Differential_M_;

/* Model step function */
void Differential_step(void)
{
  real_T rtb_Product1;
  real_T rtb_Product2;

  /* Product: '<Root>/Product' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In6'
   */
  rtb_Product1 = Differential_U.frontpowerbias * Differential_U.throttle;

  /* Product: '<Root>/Product3' incorporates:
   *  Inport: '<Root>/In2'
   *  Inport: '<Root>/In5'
   */
  rtb_Product2 = Differential_U.frontslip * Differential_U.steering;

  /* Outport: '<Root>/Out1' incorporates:
   *  Bias: '<Root>/Bias'
   *  Product: '<Root>/Product6'
   */
  Differential_Y.Out1 = (rtb_Product2 + Differential_P.Bias_Bias) * rtb_Product1;

  /* Outport: '<Root>/Out2' incorporates:
   *  Bias: '<Root>/Bias1'
   *  Constant: '<Root>/Constant'
   *  Product: '<Root>/Product4'
   *  Product: '<Root>/Product7'
   */
  Differential_Y.Out2 = (rtb_Product2 * Differential_P.Constant_Value +
    Differential_P.Bias1_Bias) * rtb_Product1;

  /* Product: '<Root>/Product2' incorporates:
   *  Inport: '<Root>/In4'
   *  Inport: '<Root>/In5'
   */
  rtb_Product2 = Differential_U.steering * Differential_U.rearslip;

  /* Product: '<Root>/Product1' incorporates:
   *  Inport: '<Root>/In3'
   *  Inport: '<Root>/In6'
   */
  rtb_Product1 = Differential_U.throttle * Differential_U.rearpowerbias;

  /* Outport: '<Root>/Out3' incorporates:
   *  Bias: '<Root>/Bias2'
   *  Constant: '<Root>/Constant'
   *  Product: '<Root>/Product5'
   *  Product: '<Root>/Product8'
   */
  Differential_Y.Out3 = (Differential_P.Constant_Value * rtb_Product2 +
    Differential_P.Bias2_Bias) * rtb_Product1;

  /* Outport: '<Root>/Out4' incorporates:
   *  Bias: '<Root>/Bias3'
   *  Product: '<Root>/Product9'
   */
  Differential_Y.Out4 = (rtb_Product2 + Differential_P.Bias3_Bias) *
    rtb_Product1;
}

/* Model initialize function */
void Differential_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Differential_M, (NULL));

  /* external inputs */
  (void) memset((void *)&Differential_U, 0,
                sizeof(ExtU_Differential_T));

  /* external outputs */
  (void) memset((void *)&Differential_Y, 0,
                sizeof(ExtY_Differential_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
