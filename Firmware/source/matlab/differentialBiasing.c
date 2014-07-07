/*
 * File: differentialBiasing.c
 *
 * Code generated for Simulink model 'differentialBiasing'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Mon Jul 07 23:15:50 2014
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "differentialBiasing.h"
#include "differentialBiasing_private.h"

/* External inputs (root inport signals with auto storage) */
ExtU_differentialBiasing_T differentialBiasing_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_differentialBiasing_T differentialBiasing_Y;

/* Real-time model */
RT_MODEL_differentialBiasing_T differentialBiasing_M_;
RT_MODEL_differentialBiasing_T *const differentialBiasing_M =
  &differentialBiasing_M_;

/* Model step function */
void differentialBiasing_step(void)
{
  real_T rtb_Product;
  real_T rtb_Product1;
  real_T rtb_Bias;
  real_T rtb_Bias1;
  real_T rtb_Bias2;
  real_T rtb_Bias3;

  /* Product: '<S1>/Product3' incorporates:
   *  Inport: '<Root>/frontslip'
   *  Inport: '<Root>/steering'
   */
  rtb_Product = differentialBiasing_U.frontslip * differentialBiasing_U.steering;

  /* Bias: '<S1>/Bias' */
  rtb_Bias = rtb_Product + differentialBiasing_P.Bias_Bias;

  /* Bias: '<S1>/Bias1' incorporates:
   *  Constant: '<S1>/Constant'
   *  Product: '<S1>/Product4'
   */
  rtb_Bias1 = rtb_Product * differentialBiasing_P.Constant_Value +
    differentialBiasing_P.Bias1_Bias;

  /* Product: '<S1>/Product2' incorporates:
   *  Inport: '<Root>/rearslip'
   *  Inport: '<Root>/steering'
   */
  rtb_Product = differentialBiasing_U.steering * differentialBiasing_U.rearslip;

  /* Bias: '<S1>/Bias2' incorporates:
   *  Constant: '<S1>/Constant'
   *  Product: '<S1>/Product5'
   */
  rtb_Bias2 = differentialBiasing_P.Constant_Value * rtb_Product +
    differentialBiasing_P.Bias2_Bias;

  /* Bias: '<S1>/Bias3' */
  rtb_Bias3 = rtb_Product + differentialBiasing_P.Bias3_Bias;

  /* Product: '<S1>/Product' incorporates:
   *  Inport: '<Root>/frontpowerbias'
   *  Inport: '<Root>/throttle'
   */
  rtb_Product = differentialBiasing_U.frontpowerbias *
    differentialBiasing_U.throttle;

  /* Product: '<S1>/Product1' incorporates:
   *  Inport: '<Root>/rearpowerbias'
   *  Inport: '<Root>/throttle'
   */
  rtb_Product1 = differentialBiasing_U.throttle *
    differentialBiasing_U.rearpowerbias;

  /* Outport: '<Root>/FLWheel' incorporates:
   *  Product: '<S1>/Product6'
   */
  differentialBiasing_Y.FLWheel = rtb_Product * rtb_Bias;

  /* Outport: '<Root>/FRWheel' incorporates:
   *  Product: '<S1>/Product7'
   */
  differentialBiasing_Y.FRWheel = rtb_Product * rtb_Bias1;

  /* Outport: '<Root>/BLWheel' incorporates:
   *  Product: '<S1>/Product9'
   */
  differentialBiasing_Y.BLWheel = rtb_Bias3 * rtb_Product1;

  /* Outport: '<Root>/BRWheel' incorporates:
   *  Product: '<S1>/Product8'
   */
  differentialBiasing_Y.BRWheel = rtb_Bias2 * rtb_Product1;
}

/* Model initialize function */
void differentialBiasing_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(differentialBiasing_M, (NULL));

  /* external inputs */
  (void) memset((void *)&differentialBiasing_U, 0,
                sizeof(ExtU_differentialBiasing_T));

  /* external outputs */
  (void) memset((void *)&differentialBiasing_Y, 0,
                sizeof(ExtY_differentialBiasing_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
