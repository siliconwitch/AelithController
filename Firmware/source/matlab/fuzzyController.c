/*
 * File: fuzzyController.c
 *
 * Code generated for Simulink model 'fuzzyController'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Sun Jul 13 16:00:48 2014
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "fuzzyController.h"
#include "fuzzyController_private.h"

/* Block signals (auto storage) */
B_fuzzyController_T fuzzyController_B;

/* External inputs (root inport signals with auto storage) */
ExtU_fuzzyController_T fuzzyController_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_fuzzyController_T fuzzyController_Y;

/*
 * Output and update for action system:
 *    '<S7>/Action: u1'
 *    '<S8>/Action: u1'
 *    '<S9>/Action: u1'
 *    '<S10>/Action: u1'
 *    '<S11>/Action: u1'
 */
void fuzzyController_Actionu1(real_T rtu_0, real_T *rty_u2)
{
  /* Inport: '<S34>/u1' */
  *rty_u2 = rtu_0;
}

/*
 * Output and update for action system:
 *    '<S43>/If Action Subsystem3'
 *    '<S44>/If Action Subsystem3'
 *    '<S45>/If Action Subsystem3'
 *    '<S58>/If Action Subsystem3'
 *    '<S59>/If Action Subsystem3'
 *    '<S60>/If Action Subsystem3'
 *    '<S73>/If Action Subsystem3'
 *    '<S74>/If Action Subsystem3'
 *    '<S75>/If Action Subsystem3'
 *    '<S88>/If Action Subsystem3'
 *    ...
 */
void fuzzyControl_IfActionSubsystem3(real_T rtu_x, real_T *rty_Out1,
  P_IfActionSubsystem3_fuzzyCon_T *localP)
{
  /* Product: '<S49>/Product ab (trimf)' incorporates:
   *  Constant: '<S49>/a'
   *  Constant: '<S49>/b'
   *  Sum: '<S49>/Sum'
   *  Sum: '<S49>/Sum1'
   */
  *rty_Out1 = (rtu_x - localP->a_Value) / (localP->b_Value - localP->a_Value);
}

/*
 * Output and update for action system:
 *    '<S43>/If Action Subsystem2'
 *    '<S44>/If Action Subsystem2'
 *    '<S45>/If Action Subsystem2'
 *    '<S58>/If Action Subsystem2'
 *    '<S59>/If Action Subsystem2'
 *    '<S60>/If Action Subsystem2'
 *    '<S73>/If Action Subsystem2'
 *    '<S74>/If Action Subsystem2'
 *    '<S75>/If Action Subsystem2'
 *    '<S88>/If Action Subsystem2'
 *    ...
 */
void fuzzyControl_IfActionSubsystem2(real_T rtu_x, real_T *rty_Out1,
  P_IfActionSubsystem2_fuzzyCon_T *localP)
{
  /* Product: '<S48>/Product cd (trimf)' incorporates:
   *  Constant: '<S48>/b'
   *  Constant: '<S48>/c'
   *  Sum: '<S48>/Sum2'
   *  Sum: '<S48>/Sum3'
   */
  *rty_Out1 = 1.0 / (localP->c_Value - localP->b_Value) * (localP->c_Value -
    rtu_x);
}

/* Model step function */
void fuzzyController_step(void)
{
  /* local block i/o variables */
  real_T rtb_Merge_d0;
  real_T rtb_Merge_e3;
  real_T rtb_Merge_g;
  real_T rtb_Merge_m1;
  real_T rtb_Merge_i1;
  real_T rtb_Merge_e5;
  real_T rtb_Merge_ev;
  int32_T i;

  /* If: '<S104>/If' incorporates:
   *  Constant: '<S110>/0'
   *  Constant: '<S111>/0'
   *  Inport: '<Root>/steeringSignal'
   */
  if ((fuzzyController_U.steeringSignal < -2.0) ||
      (fuzzyController_U.steeringSignal > 0.0)) {
    /* Outputs for IfAction SubSystem: '<S104>/If Action Subsystem' incorporates:
     *  ActionPort: '<S110>/Action Port'
     */
    fuzzyController_B.Merge = fuzzyController_P._Value_i1;

    /* End of Outputs for SubSystem: '<S104>/If Action Subsystem' */
  } else if (fuzzyController_U.steeringSignal == -1.0) {
    /* Outputs for IfAction SubSystem: '<S104>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S111>/Action Port'
     */
    fuzzyController_B.Merge = fuzzyController_P._Value_ph;

    /* End of Outputs for SubSystem: '<S104>/If Action Subsystem1' */
  } else if (fuzzyController_U.steeringSignal < -1.0) {
    /* Outputs for IfAction SubSystem: '<S104>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S113>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.steeringSignal,
      &fuzzyController_B.Merge, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S104>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S104>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S112>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.steeringSignal,
      &fuzzyController_B.Merge, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S104>/If Action Subsystem2' */
  }

  /* End of If: '<S104>/If' */

  /* Product: '<S14>/Weighting' incorporates:
   *  Constant: '<S14>/Weight'
   */
  fuzzyController_B.Weighting = fuzzyController_P.Weight_Value *
    fuzzyController_B.Merge;

  /* Product: '<S14>/impMethod' incorporates:
   *  Constant: '<S30>/left'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod[i] = fuzzyController_B.Weighting *
      fuzzyController_P.left_Value[i];
  }

  /* End of Product: '<S14>/impMethod' */

  /* If: '<S105>/If' incorporates:
   *  Constant: '<S114>/0'
   *  Constant: '<S115>/0'
   *  Inport: '<Root>/steeringSignal'
   */
  if ((fuzzyController_U.steeringSignal < 0.0) ||
      (fuzzyController_U.steeringSignal > 2.0)) {
    /* Outputs for IfAction SubSystem: '<S105>/If Action Subsystem' incorporates:
     *  ActionPort: '<S114>/Action Port'
     */
    fuzzyController_B.Merge_i = fuzzyController_P._Value_p5;

    /* End of Outputs for SubSystem: '<S105>/If Action Subsystem' */
  } else if (fuzzyController_U.steeringSignal == 1.0) {
    /* Outputs for IfAction SubSystem: '<S105>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S115>/Action Port'
     */
    fuzzyController_B.Merge_i = fuzzyController_P._Value_fc;

    /* End of Outputs for SubSystem: '<S105>/If Action Subsystem1' */
  } else if (fuzzyController_U.steeringSignal < 1.0) {
    /* Outputs for IfAction SubSystem: '<S105>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S117>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.steeringSignal,
      &fuzzyController_B.Merge_i, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_g);

    /* End of Outputs for SubSystem: '<S105>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S105>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S116>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.steeringSignal,
      &fuzzyController_B.Merge_i, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_j);

    /* End of Outputs for SubSystem: '<S105>/If Action Subsystem2' */
  }

  /* End of If: '<S105>/If' */

  /* Product: '<S18>/Weighting' incorporates:
   *  Constant: '<S18>/Weight'
   */
  fuzzyController_B.Weighting_g = fuzzyController_P.Weight_Value_n *
    fuzzyController_B.Merge_i;

  /* Product: '<S18>/impMethod' incorporates:
   *  Constant: '<S30>/right'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_c[i] = fuzzyController_B.Weighting_g *
      fuzzyController_P.right_Value[i];
  }

  /* End of Product: '<S18>/impMethod' */

  /* If: '<S103>/If' incorporates:
   *  Constant: '<S106>/0'
   *  Constant: '<S107>/0'
   *  Inport: '<Root>/steeringSignal'
   */
  if ((fuzzyController_U.steeringSignal < -1.0) ||
      (fuzzyController_U.steeringSignal > 1.0)) {
    /* Outputs for IfAction SubSystem: '<S103>/If Action Subsystem' incorporates:
     *  ActionPort: '<S106>/Action Port'
     */
    fuzzyController_B.Merge_h = fuzzyController_P._Value_bk;

    /* End of Outputs for SubSystem: '<S103>/If Action Subsystem' */
  } else if (fuzzyController_U.steeringSignal == 0.0) {
    /* Outputs for IfAction SubSystem: '<S103>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S107>/Action Port'
     */
    fuzzyController_B.Merge_h = fuzzyController_P._Value_e1;

    /* End of Outputs for SubSystem: '<S103>/If Action Subsystem1' */
  } else if (fuzzyController_U.steeringSignal < 0.0) {
    /* Outputs for IfAction SubSystem: '<S103>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S109>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.steeringSignal,
      &fuzzyController_B.Merge_h, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_p);

    /* End of Outputs for SubSystem: '<S103>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S103>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S108>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.steeringSignal,
      &fuzzyController_B.Merge_h, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_p);

    /* End of Outputs for SubSystem: '<S103>/If Action Subsystem2' */
  }

  /* End of If: '<S103>/If' */

  /* Product: '<S19>/Weighting' incorporates:
   *  Constant: '<S19>/Weight'
   */
  fuzzyController_B.Weighting_c = fuzzyController_P.Weight_Value_f *
    fuzzyController_B.Merge_h;

  /* Sum: '<S4>/AggMethod1' incorporates:
   *  Constant: '<S30>/center'
   *  Product: '<S19>/impMethod'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod[i] = (fuzzyController_B.impMethod[i] +
      fuzzyController_B.impMethod_c[i]) + fuzzyController_B.Weighting_c *
      fuzzyController_P.center_Value[i];
  }

  /* End of Sum: '<S4>/AggMethod1' */

  /* Sum: '<S7>/Sum1' */
  fuzzyController_B.AveragingCOA_i = fuzzyController_B.impMethod[0];
  for (i = 0; i < 100; i++) {
    fuzzyController_B.AveragingCOA_i += fuzzyController_B.impMethod[i + 1];
  }

  fuzzyController_B.Sum1 = fuzzyController_B.AveragingCOA_i;

  /* End of Sum: '<S7>/Sum1' */

  /* If: '<S7>/If' incorporates:
   *  Constant: '<S33>/One'
   */
  if (fuzzyController_B.Sum1 <= 0.0) {
    /* Outputs for IfAction SubSystem: '<S7>/Action: One' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    fuzzyController_B.Merge_c = fuzzyController_P.One_Value;

    /* End of Outputs for SubSystem: '<S7>/Action: One' */
  } else {
    /* Outputs for IfAction SubSystem: '<S7>/Action: u1' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    fuzzyController_Actionu1(fuzzyController_B.Sum1, &fuzzyController_B.Merge_c);

    /* End of Outputs for SubSystem: '<S7>/Action: u1' */
  }

  /* End of If: '<S7>/If' */

  /* If: '<S118>/If' incorporates:
   *  Constant: '<S121>/0'
   *  Constant: '<S122>/0'
   *  Inport: '<Root>/throttleSignal'
   */
  if ((fuzzyController_U.throttleSignal < -0.0) ||
      (fuzzyController_U.throttleSignal > 2.0)) {
    /* Outputs for IfAction SubSystem: '<S118>/If Action Subsystem' incorporates:
     *  ActionPort: '<S121>/Action Port'
     */
    fuzzyController_B.Merge_a = fuzzyController_P._Value_hh;

    /* End of Outputs for SubSystem: '<S118>/If Action Subsystem' */
  } else if (fuzzyController_U.throttleSignal == 1.0) {
    /* Outputs for IfAction SubSystem: '<S118>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S122>/Action Port'
     */
    fuzzyController_B.Merge_a = fuzzyController_P._Value_pg;

    /* End of Outputs for SubSystem: '<S118>/If Action Subsystem1' */
  } else if (fuzzyController_U.throttleSignal < 1.0) {
    /* Outputs for IfAction SubSystem: '<S118>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S124>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.throttleSignal,
      &fuzzyController_B.Merge_a, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_k);

    /* End of Outputs for SubSystem: '<S118>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S118>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S123>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.throttleSignal,
      &fuzzyController_B.Merge_a, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_e);

    /* End of Outputs for SubSystem: '<S118>/If Action Subsystem2' */
  }

  /* End of If: '<S118>/If' */

  /* Product: '<S20>/Weighting' incorporates:
   *  Constant: '<S20>/Weight'
   */
  fuzzyController_B.Weighting_j = fuzzyController_P.Weight_Value_j *
    fuzzyController_B.Merge_a;

  /* Product: '<S20>/impMethod' incorporates:
   *  Constant: '<S12>/forward'
   *  Constant: '<S13>/forward'
   *  Constant: '<S5>/forward'
   *  Constant: '<S6>/forward'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_b[i] = fuzzyController_B.Weighting_j *
      fuzzyController_P.forward_Value[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_b[i + 101] = fuzzyController_B.Weighting_j *
      fuzzyController_P.forward_Value_c[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_b[i + 202] = fuzzyController_B.Weighting_j *
      fuzzyController_P.forward_Value_k[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_b[i + 303] = fuzzyController_B.Weighting_j *
      fuzzyController_P.forward_Value_f[i];
  }

  /* End of Product: '<S20>/impMethod' */

  /* If: '<S74>/If' incorporates:
   *  Constant: '<S80>/0'
   *  Constant: '<S81>/0'
   *  Inport: '<Root>/powerBias'
   */
  if ((fuzzyController_U.powerBias < -2.0) || (fuzzyController_U.powerBias > 0.0))
  {
    /* Outputs for IfAction SubSystem: '<S74>/If Action Subsystem' incorporates:
     *  ActionPort: '<S80>/Action Port'
     */
    fuzzyController_B.Merge_d = fuzzyController_P._Value_j3;

    /* End of Outputs for SubSystem: '<S74>/If Action Subsystem' */
  } else if (fuzzyController_U.powerBias == -1.0) {
    /* Outputs for IfAction SubSystem: '<S74>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S81>/Action Port'
     */
    fuzzyController_B.Merge_d = fuzzyController_P._Value_o3;

    /* End of Outputs for SubSystem: '<S74>/If Action Subsystem1' */
  } else if (fuzzyController_U.powerBias < -1.0) {
    /* Outputs for IfAction SubSystem: '<S74>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S83>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.powerBias,
      &fuzzyController_B.Merge_d, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_j);

    /* End of Outputs for SubSystem: '<S74>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S74>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S82>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.powerBias,
      &fuzzyController_B.Merge_d, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_a);

    /* End of Outputs for SubSystem: '<S74>/If Action Subsystem2' */
  }

  /* End of If: '<S74>/If' */

  /* MinMax: '<S21>/andorMethod' */
  if (fuzzyController_B.Merge_a <= fuzzyController_B.Merge_d) {
    fuzzyController_B.Weighting_o = fuzzyController_B.Merge_a;
  } else {
    fuzzyController_B.Weighting_o = fuzzyController_B.Merge_d;
  }

  /* End of MinMax: '<S21>/andorMethod' */

  /* Product: '<S21>/Weighting' incorporates:
   *  Constant: '<S21>/Weight'
   */
  fuzzyController_B.Weighting_p = fuzzyController_P.Weight_Value_g *
    fuzzyController_B.Weighting_o;

  /* Product: '<S21>/impMethod' incorporates:
   *  Constant: '<S12>/forward'
   *  Constant: '<S13>/forward'
   *  Constant: '<S5>/reverse'
   *  Constant: '<S6>/reverse'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_p[i] = fuzzyController_B.Weighting_p *
      fuzzyController_P.forward_Value[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_p[i + 101] = fuzzyController_B.Weighting_p *
      fuzzyController_P.forward_Value_c[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_p[i + 202] = fuzzyController_B.Weighting_p *
      fuzzyController_P.reverse_Value[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_p[i + 303] = fuzzyController_B.Weighting_p *
      fuzzyController_P.reverse_Value_c[i];
  }

  /* End of Product: '<S21>/impMethod' */

  /* If: '<S73>/If' incorporates:
   *  Constant: '<S76>/0'
   *  Constant: '<S77>/0'
   *  Inport: '<Root>/powerBias'
   */
  if ((fuzzyController_U.powerBias < 0.0) || (fuzzyController_U.powerBias > 2.0))
  {
    /* Outputs for IfAction SubSystem: '<S73>/If Action Subsystem' incorporates:
     *  ActionPort: '<S76>/Action Port'
     */
    fuzzyController_B.Merge_m = fuzzyController_P._Value_j;

    /* End of Outputs for SubSystem: '<S73>/If Action Subsystem' */
  } else if (fuzzyController_U.powerBias == 1.0) {
    /* Outputs for IfAction SubSystem: '<S73>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S77>/Action Port'
     */
    fuzzyController_B.Merge_m = fuzzyController_P._Value_o1;

    /* End of Outputs for SubSystem: '<S73>/If Action Subsystem1' */
  } else if (fuzzyController_U.powerBias < 1.0) {
    /* Outputs for IfAction SubSystem: '<S73>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S79>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.powerBias,
      &fuzzyController_B.Merge_m, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_jn);

    /* End of Outputs for SubSystem: '<S73>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S73>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S78>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.powerBias,
      &fuzzyController_B.Merge_m, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_pq);

    /* End of Outputs for SubSystem: '<S73>/If Action Subsystem2' */
  }

  /* End of If: '<S73>/If' */

  /* MinMax: '<S22>/andorMethod' */
  if (fuzzyController_B.Merge_a <= fuzzyController_B.Merge_m) {
    fuzzyController_B.Weighting_o = fuzzyController_B.Merge_a;
  } else {
    fuzzyController_B.Weighting_o = fuzzyController_B.Merge_m;
  }

  /* End of MinMax: '<S22>/andorMethod' */

  /* Product: '<S22>/Weighting' incorporates:
   *  Constant: '<S22>/Weight'
   */
  fuzzyController_B.Weighting_cb = fuzzyController_P.Weight_Value_p *
    fuzzyController_B.Weighting_o;

  /* Product: '<S22>/impMethod' incorporates:
   *  Constant: '<S12>/reverse'
   *  Constant: '<S13>/reverse'
   *  Constant: '<S5>/forward'
   *  Constant: '<S6>/forward'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_l[i] = fuzzyController_B.Weighting_cb *
      fuzzyController_P.reverse_Value_cg[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_l[i + 101] = fuzzyController_B.Weighting_cb *
      fuzzyController_P.reverse_Value_m[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_l[i + 202] = fuzzyController_B.Weighting_cb *
      fuzzyController_P.forward_Value_k[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_l[i + 303] = fuzzyController_B.Weighting_cb *
      fuzzyController_P.forward_Value_f[i];
  }

  /* End of Product: '<S22>/impMethod' */

  /* If: '<S119>/If' incorporates:
   *  Constant: '<S125>/0'
   *  Constant: '<S126>/0'
   *  Inport: '<Root>/throttleSignal'
   */
  if ((fuzzyController_U.throttleSignal < -1.0) ||
      (fuzzyController_U.throttleSignal > 1.0)) {
    /* Outputs for IfAction SubSystem: '<S119>/If Action Subsystem' incorporates:
     *  ActionPort: '<S125>/Action Port'
     */
    fuzzyController_B.Merge_p = fuzzyController_P._Value_bv;

    /* End of Outputs for SubSystem: '<S119>/If Action Subsystem' */
  } else if (fuzzyController_U.throttleSignal == 0.0) {
    /* Outputs for IfAction SubSystem: '<S119>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S126>/Action Port'
     */
    fuzzyController_B.Merge_p = fuzzyController_P._Value_hy;

    /* End of Outputs for SubSystem: '<S119>/If Action Subsystem1' */
  } else if (fuzzyController_U.throttleSignal < 0.0) {
    /* Outputs for IfAction SubSystem: '<S119>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S128>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.throttleSignal,
      &fuzzyController_B.Merge_p, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_b);

    /* End of Outputs for SubSystem: '<S119>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S119>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S127>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.throttleSignal,
      &fuzzyController_B.Merge_p, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_h);

    /* End of Outputs for SubSystem: '<S119>/If Action Subsystem2' */
  }

  /* End of If: '<S119>/If' */

  /* Product: '<S23>/Weighting' incorporates:
   *  Constant: '<S23>/Weight'
   */
  fuzzyController_B.Weighting_m = fuzzyController_P.Weight_Value_m *
    fuzzyController_B.Merge_p;

  /* Product: '<S23>/impMethod' incorporates:
   *  Constant: '<S12>/neutral'
   *  Constant: '<S13>/neutral'
   *  Constant: '<S5>/neutral'
   *  Constant: '<S6>/neutral'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_d[i] = fuzzyController_B.Weighting_m *
      fuzzyController_P.neutral_Value[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_d[i + 101] = fuzzyController_B.Weighting_m *
      fuzzyController_P.neutral_Value_o[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_d[i + 202] = fuzzyController_B.Weighting_m *
      fuzzyController_P.neutral_Value_b[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_d[i + 303] = fuzzyController_B.Weighting_m *
      fuzzyController_P.neutral_Value_n[i];
  }

  /* End of Product: '<S23>/impMethod' */

  /* If: '<S120>/If' incorporates:
   *  Constant: '<S129>/0'
   *  Constant: '<S130>/0'
   *  Inport: '<Root>/throttleSignal'
   */
  if ((fuzzyController_U.throttleSignal < -2.0) ||
      (fuzzyController_U.throttleSignal > 0.0)) {
    /* Outputs for IfAction SubSystem: '<S120>/If Action Subsystem' incorporates:
     *  ActionPort: '<S129>/Action Port'
     */
    fuzzyController_B.Merge_l = fuzzyController_P._Value_om;

    /* End of Outputs for SubSystem: '<S120>/If Action Subsystem' */
  } else if (fuzzyController_U.throttleSignal == -1.0) {
    /* Outputs for IfAction SubSystem: '<S120>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S130>/Action Port'
     */
    fuzzyController_B.Merge_l = fuzzyController_P._Value_os;

    /* End of Outputs for SubSystem: '<S120>/If Action Subsystem1' */
  } else if (fuzzyController_U.throttleSignal < -1.0) {
    /* Outputs for IfAction SubSystem: '<S120>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S132>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.throttleSignal,
      &fuzzyController_B.Merge_l, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_gb);

    /* End of Outputs for SubSystem: '<S120>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S120>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S131>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.throttleSignal,
      &fuzzyController_B.Merge_l, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_k);

    /* End of Outputs for SubSystem: '<S120>/If Action Subsystem2' */
  }

  /* End of If: '<S120>/If' */

  /* Product: '<S24>/Weighting' incorporates:
   *  Constant: '<S24>/Weight'
   */
  fuzzyController_B.Weighting_k = fuzzyController_P.Weight_Value_pr *
    fuzzyController_B.Merge_l;

  /* Product: '<S24>/impMethod' incorporates:
   *  Constant: '<S12>/reverse'
   *  Constant: '<S13>/reverse'
   *  Constant: '<S5>/reverse'
   *  Constant: '<S6>/reverse'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_m[i] = fuzzyController_B.Weighting_k *
      fuzzyController_P.reverse_Value_cg[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_m[i + 101] = fuzzyController_B.Weighting_k *
      fuzzyController_P.reverse_Value_m[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_m[i + 202] = fuzzyController_B.Weighting_k *
      fuzzyController_P.reverse_Value[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_m[i + 303] = fuzzyController_B.Weighting_k *
      fuzzyController_P.reverse_Value_c[i];
  }

  for (i = 0; i < 101; i++) {
    /* Sum: '<S4>/AggMethod2' */
    fuzzyController_B.Weighting_o = (((fuzzyController_B.impMethod_b[i] +
      fuzzyController_B.impMethod_p[i]) + fuzzyController_B.impMethod_l[i]) +
      fuzzyController_B.impMethod_d[i]) + fuzzyController_B.impMethod_m[i];

    /* Product: '<S8>/Product (COA)' incorporates:
     *  Constant: '<S8>/x data'
     */
    fuzzyController_B.impMethod_c[i] = fuzzyController_P.xdata_Value_n[i] *
      fuzzyController_B.Weighting_o;

    /* Sum: '<S4>/AggMethod2' */
    fuzzyController_B.AggMethod3[i] = fuzzyController_B.Weighting_o;
  }

  /* End of Product: '<S24>/impMethod' */

  /* Sum: '<S8>/Sum' */
  fuzzyController_B.AveragingCOA_fi = fuzzyController_B.impMethod_c[0];

  /* Sum: '<S8>/Sum1' */
  fuzzyController_B.AveragingCOA_i = fuzzyController_B.AggMethod3[0];
  for (i = 0; i < 100; i++) {
    /* Sum: '<S8>/Sum' */
    fuzzyController_B.AveragingCOA_fi += fuzzyController_B.impMethod_c[i + 1];
    fuzzyController_B.AveragingCOA_i += fuzzyController_B.AggMethod3[i + 1];
  }

  fuzzyController_B.Sum1_i = fuzzyController_B.AveragingCOA_i;

  /* End of Sum: '<S8>/Sum1' */

  /* If: '<S8>/If' incorporates:
   *  Constant: '<S35>/One'
   */
  if (fuzzyController_B.Sum1_i <= 0.0) {
    /* Outputs for IfAction SubSystem: '<S8>/Action: One' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    fuzzyController_B.Merge_l2 = fuzzyController_P.One_Value_e;

    /* End of Outputs for SubSystem: '<S8>/Action: One' */
  } else {
    /* Outputs for IfAction SubSystem: '<S8>/Action: u1' incorporates:
     *  ActionPort: '<S36>/Action Port'
     */
    fuzzyController_Actionu1(fuzzyController_B.Sum1_i,
      &fuzzyController_B.Merge_l2);

    /* End of Outputs for SubSystem: '<S8>/Action: u1' */
  }

  /* End of If: '<S8>/If' */

  /* Product: '<S8>/Averaging (COA)' */
  fuzzyController_B.AveragingCOA_fi /= fuzzyController_B.Merge_l2;
  for (i = 0; i < 101; i++) {
    /* Sum: '<S4>/AggMethod3' */
    fuzzyController_B.Weighting_o = (((fuzzyController_B.impMethod_b[i + 101] +
      fuzzyController_B.impMethod_p[i + 101]) + fuzzyController_B.impMethod_l[i
      + 101]) + fuzzyController_B.impMethod_d[i + 101]) +
      fuzzyController_B.impMethod_m[i + 101];

    /* Product: '<S9>/Product (COA)' incorporates:
     *  Constant: '<S9>/x data'
     */
    fuzzyController_B.impMethod_c[i] = fuzzyController_P.xdata_Value_i[i] *
      fuzzyController_B.Weighting_o;

    /* Sum: '<S4>/AggMethod3' */
    fuzzyController_B.AggMethod3[i] = fuzzyController_B.Weighting_o;
  }

  /* Sum: '<S9>/Sum' */
  fuzzyController_B.AveragingCOA_d = fuzzyController_B.impMethod_c[0];

  /* Sum: '<S9>/Sum1' */
  fuzzyController_B.AveragingCOA_i = fuzzyController_B.AggMethod3[0];
  for (i = 0; i < 100; i++) {
    /* Sum: '<S9>/Sum' */
    fuzzyController_B.AveragingCOA_d += fuzzyController_B.impMethod_c[i + 1];
    fuzzyController_B.AveragingCOA_i += fuzzyController_B.AggMethod3[i + 1];
  }

  fuzzyController_B.Sum1_o = fuzzyController_B.AveragingCOA_i;

  /* End of Sum: '<S9>/Sum1' */

  /* If: '<S9>/If' incorporates:
   *  Constant: '<S37>/One'
   */
  if (fuzzyController_B.Sum1_o <= 0.0) {
    /* Outputs for IfAction SubSystem: '<S9>/Action: One' incorporates:
     *  ActionPort: '<S37>/Action Port'
     */
    fuzzyController_B.Merge_lr = fuzzyController_P.One_Value_ei;

    /* End of Outputs for SubSystem: '<S9>/Action: One' */
  } else {
    /* Outputs for IfAction SubSystem: '<S9>/Action: u1' incorporates:
     *  ActionPort: '<S38>/Action Port'
     */
    fuzzyController_Actionu1(fuzzyController_B.Sum1_o,
      &fuzzyController_B.Merge_lr);

    /* End of Outputs for SubSystem: '<S9>/Action: u1' */
  }

  /* End of If: '<S9>/If' */

  /* Product: '<S9>/Averaging (COA)' */
  fuzzyController_B.AveragingCOA_d /= fuzzyController_B.Merge_lr;

  /* If: '<S88>/If' incorporates:
   *  Constant: '<S91>/0'
   *  Constant: '<S92>/0'
   *  Inport: '<Root>/rearDifferential'
   */
  if ((fuzzyController_U.rearDifferential < -2.0) ||
      (fuzzyController_U.rearDifferential > 0.0)) {
    /* Outputs for IfAction SubSystem: '<S88>/If Action Subsystem' incorporates:
     *  ActionPort: '<S91>/Action Port'
     */
    fuzzyController_B.Merge_am = fuzzyController_P._Value_id;

    /* End of Outputs for SubSystem: '<S88>/If Action Subsystem' */
  } else if (fuzzyController_U.rearDifferential == -1.0) {
    /* Outputs for IfAction SubSystem: '<S88>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S92>/Action Port'
     */
    fuzzyController_B.Merge_am = fuzzyController_P._Value_b;

    /* End of Outputs for SubSystem: '<S88>/If Action Subsystem1' */
  } else if (fuzzyController_U.rearDifferential < -1.0) {
    /* Outputs for IfAction SubSystem: '<S88>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S94>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.rearDifferential,
      &fuzzyController_B.Merge_am, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_f);

    /* End of Outputs for SubSystem: '<S88>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S88>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S93>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.rearDifferential,
      &fuzzyController_B.Merge_am, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_ak);

    /* End of Outputs for SubSystem: '<S88>/If Action Subsystem2' */
  }

  /* End of If: '<S88>/If' */

  /* MinMax: '<S25>/andorMethod' */
  if (fuzzyController_B.Merge <= fuzzyController_B.Merge_a) {
    fuzzyController_B.ZeroFiringStrength = fuzzyController_B.Merge;
  } else {
    fuzzyController_B.ZeroFiringStrength = fuzzyController_B.Merge_a;
  }

  if (!(fuzzyController_B.ZeroFiringStrength <= fuzzyController_B.Merge_am)) {
    fuzzyController_B.ZeroFiringStrength = fuzzyController_B.Merge_am;
  }

  /* Product: '<S25>/Weighting' incorporates:
   *  Constant: '<S25>/Weight'
   *  MinMax: '<S25>/andorMethod'
   */
  fuzzyController_B.Weighting_o = fuzzyController_P.Weight_Value_b *
    fuzzyController_B.ZeroFiringStrength;

  /* Product: '<S25>/impMethod' incorporates:
   *  Constant: '<S5>/reverse'
   *  Constant: '<S6>/forward'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_k[i] = fuzzyController_B.Weighting_o *
      fuzzyController_P.reverse_Value[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_k[i + 101] = fuzzyController_B.Weighting_o *
      fuzzyController_P.forward_Value_f[i];
  }

  /* End of Product: '<S25>/impMethod' */

  /* MinMax: '<S15>/andorMethod' */
  if (fuzzyController_B.Merge_i <= fuzzyController_B.Merge_a) {
    fuzzyController_B.ZeroFiringStrength = fuzzyController_B.Merge_i;
  } else {
    fuzzyController_B.ZeroFiringStrength = fuzzyController_B.Merge_a;
  }

  if (!(fuzzyController_B.ZeroFiringStrength <= fuzzyController_B.Merge_am)) {
    fuzzyController_B.ZeroFiringStrength = fuzzyController_B.Merge_am;
  }

  /* Product: '<S15>/Weighting' incorporates:
   *  Constant: '<S15>/Weight'
   *  MinMax: '<S15>/andorMethod'
   */
  fuzzyController_B.Weighting_b = fuzzyController_P.Weight_Value_h *
    fuzzyController_B.ZeroFiringStrength;

  /* Product: '<S15>/impMethod' incorporates:
   *  Constant: '<S5>/forward'
   *  Constant: '<S6>/reverse'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_f[i] = fuzzyController_B.Weighting_b *
      fuzzyController_P.forward_Value_k[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_f[i + 101] = fuzzyController_B.Weighting_b *
      fuzzyController_P.reverse_Value_c[i];
  }

  /* End of Product: '<S15>/impMethod' */

  /* If: '<S89>/If' incorporates:
   *  Constant: '<S95>/0'
   *  Constant: '<S96>/0'
   *  Inport: '<Root>/rearDifferential'
   */
  if ((fuzzyController_U.rearDifferential < -1.0) ||
      (fuzzyController_U.rearDifferential > 1.0)) {
    /* Outputs for IfAction SubSystem: '<S89>/If Action Subsystem' incorporates:
     *  ActionPort: '<S95>/Action Port'
     */
    fuzzyController_B.Merge_k = fuzzyController_P._Value_fa;

    /* End of Outputs for SubSystem: '<S89>/If Action Subsystem' */
  } else if (fuzzyController_U.rearDifferential == 0.0) {
    /* Outputs for IfAction SubSystem: '<S89>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S96>/Action Port'
     */
    fuzzyController_B.Merge_k = fuzzyController_P._Value_m;

    /* End of Outputs for SubSystem: '<S89>/If Action Subsystem1' */
  } else if (fuzzyController_U.rearDifferential < 0.0) {
    /* Outputs for IfAction SubSystem: '<S89>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S98>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.rearDifferential,
      &fuzzyController_B.Merge_k, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_gv);

    /* End of Outputs for SubSystem: '<S89>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S89>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S97>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.rearDifferential,
      &fuzzyController_B.Merge_k, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_l);

    /* End of Outputs for SubSystem: '<S89>/If Action Subsystem2' */
  }

  /* End of If: '<S89>/If' */

  /* MinMax: '<S16>/andorMethod' */
  if (fuzzyController_B.Merge <= fuzzyController_B.Merge_a) {
    fuzzyController_B.ZeroFiringStrength = fuzzyController_B.Merge;
  } else {
    fuzzyController_B.ZeroFiringStrength = fuzzyController_B.Merge_a;
  }

  if (!(fuzzyController_B.ZeroFiringStrength <= fuzzyController_B.Merge_k)) {
    fuzzyController_B.ZeroFiringStrength = fuzzyController_B.Merge_k;
  }

  /* Product: '<S16>/Weighting' incorporates:
   *  Constant: '<S16>/Weight'
   *  MinMax: '<S16>/andorMethod'
   */
  fuzzyController_B.Weighting_f = fuzzyController_P.Weight_Value_nt *
    fuzzyController_B.ZeroFiringStrength;

  /* Product: '<S16>/impMethod' incorporates:
   *  Constant: '<S5>/neutral'
   *  Constant: '<S6>/forward'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_kl[i] = fuzzyController_B.Weighting_f *
      fuzzyController_P.neutral_Value_b[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_kl[i + 101] = fuzzyController_B.Weighting_f *
      fuzzyController_P.forward_Value_f[i];
  }

  /* End of Product: '<S16>/impMethod' */

  /* MinMax: '<S17>/andorMethod' */
  if (fuzzyController_B.Merge_i <= fuzzyController_B.Merge_a) {
    fuzzyController_B.ZeroFiringStrength = fuzzyController_B.Merge_i;
  } else {
    fuzzyController_B.ZeroFiringStrength = fuzzyController_B.Merge_a;
  }

  if (!(fuzzyController_B.ZeroFiringStrength <= fuzzyController_B.Merge_k)) {
    fuzzyController_B.ZeroFiringStrength = fuzzyController_B.Merge_k;
  }

  /* Product: '<S17>/Weighting' incorporates:
   *  Constant: '<S17>/Weight'
   *  MinMax: '<S17>/andorMethod'
   */
  fuzzyController_B.ZeroFiringStrength *= fuzzyController_P.Weight_Value_fw;

  /* Product: '<S17>/impMethod' incorporates:
   *  Constant: '<S5>/forward'
   *  Constant: '<S6>/neutral'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_ck[i] = fuzzyController_B.ZeroFiringStrength *
      fuzzyController_P.forward_Value_k[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_ck[i + 101] =
      fuzzyController_B.ZeroFiringStrength * fuzzyController_P.neutral_Value_n[i];
  }

  /* End of Product: '<S17>/impMethod' */

  /* Sum: '<S4>/AggMethod4' */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_c[i] = (((((((fuzzyController_B.impMethod_b[i +
      202] + fuzzyController_B.impMethod_p[i + 202]) +
      fuzzyController_B.impMethod_l[i + 202]) + fuzzyController_B.impMethod_d[i
      + 202]) + fuzzyController_B.impMethod_m[i + 202]) +
      fuzzyController_B.impMethod_k[i]) + fuzzyController_B.impMethod_f[i]) +
      fuzzyController_B.impMethod_kl[i]) + fuzzyController_B.impMethod_ck[i];
  }

  /* End of Sum: '<S4>/AggMethod4' */

  /* Sum: '<S10>/Sum1' */
  fuzzyController_B.AveragingCOA_i = fuzzyController_B.impMethod_c[0];
  for (i = 0; i < 100; i++) {
    fuzzyController_B.AveragingCOA_i += fuzzyController_B.impMethod_c[i + 1];
  }

  fuzzyController_B.Sum1_m = fuzzyController_B.AveragingCOA_i;

  /* End of Sum: '<S10>/Sum1' */

  /* If: '<S10>/If' incorporates:
   *  Constant: '<S39>/One'
   */
  if (fuzzyController_B.Sum1_m <= 0.0) {
    /* Outputs for IfAction SubSystem: '<S10>/Action: One' incorporates:
     *  ActionPort: '<S39>/Action Port'
     */
    fuzzyController_B.Merge_e = fuzzyController_P.One_Value_m;

    /* End of Outputs for SubSystem: '<S10>/Action: One' */
  } else {
    /* Outputs for IfAction SubSystem: '<S10>/Action: u1' incorporates:
     *  ActionPort: '<S40>/Action Port'
     */
    fuzzyController_Actionu1(fuzzyController_B.Sum1_m,
      &fuzzyController_B.Merge_e);

    /* End of Outputs for SubSystem: '<S10>/Action: u1' */
  }

  /* End of If: '<S10>/If' */

  /* Sum: '<S4>/AggMethod5' */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.AggMethod3[i] = (((((((fuzzyController_B.impMethod_b[i +
      303] + fuzzyController_B.impMethod_p[i + 303]) +
      fuzzyController_B.impMethod_l[i + 303]) + fuzzyController_B.impMethod_d[i
      + 303]) + fuzzyController_B.impMethod_m[i + 303]) +
      fuzzyController_B.impMethod_k[i + 101]) + fuzzyController_B.impMethod_f[i
      + 101]) + fuzzyController_B.impMethod_kl[i + 101]) +
      fuzzyController_B.impMethod_ck[i + 101];
  }

  /* End of Sum: '<S4>/AggMethod5' */

  /* Sum: '<S11>/Sum1' */
  fuzzyController_B.AveragingCOA_i = fuzzyController_B.AggMethod3[0];
  for (i = 0; i < 100; i++) {
    fuzzyController_B.AveragingCOA_i += fuzzyController_B.AggMethod3[i + 1];
  }

  fuzzyController_B.Sum1_a = fuzzyController_B.AveragingCOA_i;

  /* End of Sum: '<S11>/Sum1' */

  /* If: '<S11>/If' incorporates:
   *  Constant: '<S41>/One'
   */
  if (fuzzyController_B.Sum1_a <= 0.0) {
    /* Outputs for IfAction SubSystem: '<S11>/Action: One' incorporates:
     *  ActionPort: '<S41>/Action Port'
     */
    fuzzyController_B.Merge_m0 = fuzzyController_P.One_Value_b;

    /* End of Outputs for SubSystem: '<S11>/Action: One' */
  } else {
    /* Outputs for IfAction SubSystem: '<S11>/Action: u1' incorporates:
     *  ActionPort: '<S42>/Action Port'
     */
    fuzzyController_Actionu1(fuzzyController_B.Sum1_a,
      &fuzzyController_B.Merge_m0);

    /* End of Outputs for SubSystem: '<S11>/Action: u1' */
  }

  /* End of If: '<S11>/If' */

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/MidRange'
   *  Constant: '<S4>/Zero'
   *  Product: '<S11>/Averaging (COA)'
   *  RelationalOperator: '<S4>/Zero Firing Strength?'
   *  Sum: '<S4>/Total Firing Strength'
   */
  if ((((((((((((fuzzyController_B.Weighting + fuzzyController_B.Weighting_g) +
                fuzzyController_B.Weighting_c) + fuzzyController_B.Weighting_j)
              + fuzzyController_B.Weighting_p) + fuzzyController_B.Weighting_cb)
            + fuzzyController_B.Weighting_m) + fuzzyController_B.Weighting_k) +
          fuzzyController_B.Weighting_o) + fuzzyController_B.Weighting_b) +
        fuzzyController_B.Weighting_f) + fuzzyController_B.ZeroFiringStrength >
       fuzzyController_P.Zero_Value) >= fuzzyController_P.Switch_Threshold) {
    /* Product: '<S7>/Product (COA)' incorporates:
     *  Constant: '<S7>/x data'
     */
    for (i = 0; i < 101; i++) {
      fuzzyController_B.impMethod[i] *= fuzzyController_P.xdata_Value[i];
    }

    /* End of Product: '<S7>/Product (COA)' */

    /* Sum: '<S7>/Sum' */
    fuzzyController_B.Weighting_o = fuzzyController_B.impMethod[0];
    for (i = 0; i < 100; i++) {
      fuzzyController_B.Weighting_o += fuzzyController_B.impMethod[i + 1];
    }

    /* End of Sum: '<S7>/Sum' */

    /* Product: '<S7>/Averaging (COA)' */
    fuzzyController_B.ZeroFiringStrength = fuzzyController_B.Weighting_o /
      fuzzyController_B.Merge_c;

    /* Product: '<S10>/Product (COA)' incorporates:
     *  Constant: '<S10>/x data'
     */
    for (i = 0; i < 101; i++) {
      fuzzyController_B.impMethod_c[i] *= fuzzyController_P.xdata_Value_c[i];
    }

    /* End of Product: '<S10>/Product (COA)' */

    /* Sum: '<S10>/Sum' */
    fuzzyController_B.Weighting_o = fuzzyController_B.impMethod_c[0];
    for (i = 0; i < 100; i++) {
      fuzzyController_B.Weighting_o += fuzzyController_B.impMethod_c[i + 1];
    }

    /* End of Sum: '<S10>/Sum' */

    /* Product: '<S10>/Averaging (COA)' */
    fuzzyController_B.AveragingCOA_i = fuzzyController_B.Weighting_o /
      fuzzyController_B.Merge_e;

    /* Product: '<S11>/Product (COA)' incorporates:
     *  Constant: '<S11>/x data'
     */
    for (i = 0; i < 101; i++) {
      fuzzyController_B.AggMethod3[i] *= fuzzyController_P.xdata_Value_l[i];
    }

    /* End of Product: '<S11>/Product (COA)' */

    /* Sum: '<S11>/Sum' */
    fuzzyController_B.Weighting_o = fuzzyController_B.AggMethod3[0];
    for (i = 0; i < 100; i++) {
      fuzzyController_B.Weighting_o += fuzzyController_B.AggMethod3[i + 1];
    }

    /* End of Sum: '<S11>/Sum' */
    fuzzyController_B.Switch[0] = fuzzyController_B.ZeroFiringStrength;
    fuzzyController_B.Switch[1] = fuzzyController_B.AveragingCOA_fi;
    fuzzyController_B.Switch[2] = fuzzyController_B.AveragingCOA_d;
    fuzzyController_B.Switch[3] = fuzzyController_B.AveragingCOA_i;
    fuzzyController_B.Switch[4] = fuzzyController_B.Weighting_o /
      fuzzyController_B.Merge_m0;
  } else {
    for (i = 0; i < 5; i++) {
      fuzzyController_B.Switch[i] = fuzzyController_P.MidRange_Value[i];
    }
  }

  /* End of Switch: '<S4>/Switch' */

  /* Outport: '<Root>/steeringOutput' */
  fuzzyController_Y.steeringOutput = fuzzyController_B.Switch[0];

  /* Outport: '<Root>/FLWheelOutput' */
  fuzzyController_Y.FLWheelOutput = fuzzyController_B.Switch[1];

  /* Outport: '<Root>/FRWheelOutput' */
  fuzzyController_Y.FRWheelOutput = fuzzyController_B.Switch[2];

  /* Outport: '<Root>/BLWheelOutput' */
  fuzzyController_Y.BLWheelOutput = fuzzyController_B.Switch[3];

  /* Outport: '<Root>/BRWheelOutput' */
  fuzzyController_Y.BRWheelOutput = fuzzyController_B.Switch[4];

  /* If: '<S43>/If' incorporates:
   *  Constant: '<S46>/0'
   *  Constant: '<S47>/0'
   *  Inport: '<Root>/frontDifferential'
   */
  if ((fuzzyController_U.frontDifferential < -2.0) ||
      (fuzzyController_U.frontDifferential > 0.0)) {
    /* Outputs for IfAction SubSystem: '<S43>/If Action Subsystem' incorporates:
     *  ActionPort: '<S46>/Action Port'
     */
    fuzzyController_B.Merge_f = fuzzyController_P._Value;

    /* End of Outputs for SubSystem: '<S43>/If Action Subsystem' */
  } else if (fuzzyController_U.frontDifferential == -1.0) {
    /* Outputs for IfAction SubSystem: '<S43>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S47>/Action Port'
     */
    fuzzyController_B.Merge_f = fuzzyController_P._Value_l;

    /* End of Outputs for SubSystem: '<S43>/If Action Subsystem1' */
  } else if (fuzzyController_U.frontDifferential < -1.0) {
    /* Outputs for IfAction SubSystem: '<S43>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S49>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.frontDifferential,
      &fuzzyController_B.Merge_f, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_e);

    /* End of Outputs for SubSystem: '<S43>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S43>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S48>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.frontDifferential,
      &fuzzyController_B.Merge_f, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_jw);

    /* End of Outputs for SubSystem: '<S43>/If Action Subsystem2' */
  }

  /* End of If: '<S43>/If' */

  /* If: '<S44>/If' incorporates:
   *  Constant: '<S50>/0'
   *  Constant: '<S51>/0'
   *  Inport: '<Root>/frontDifferential'
   */
  if ((fuzzyController_U.frontDifferential < -1.0) ||
      (fuzzyController_U.frontDifferential > 1.0)) {
    /* Outputs for IfAction SubSystem: '<S44>/If Action Subsystem' incorporates:
     *  ActionPort: '<S50>/Action Port'
     */
    rtb_Merge_d0 = fuzzyController_P._Value_o;

    /* End of Outputs for SubSystem: '<S44>/If Action Subsystem' */
  } else if (fuzzyController_U.frontDifferential == 0.0) {
    /* Outputs for IfAction SubSystem: '<S44>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S51>/Action Port'
     */
    rtb_Merge_d0 = fuzzyController_P._Value_a;

    /* End of Outputs for SubSystem: '<S44>/If Action Subsystem1' */
  } else if (fuzzyController_U.frontDifferential < 0.0) {
    /* Outputs for IfAction SubSystem: '<S44>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S53>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.frontDifferential,
      &rtb_Merge_d0, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_ps);

    /* End of Outputs for SubSystem: '<S44>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S44>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S52>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.frontDifferential,
      &rtb_Merge_d0, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_m);

    /* End of Outputs for SubSystem: '<S44>/If Action Subsystem2' */
  }

  /* End of If: '<S44>/If' */

  /* If: '<S45>/If' incorporates:
   *  Constant: '<S54>/0'
   *  Constant: '<S55>/0'
   *  Inport: '<Root>/frontDifferential'
   */
  if ((fuzzyController_U.frontDifferential < -0.0) ||
      (fuzzyController_U.frontDifferential > 2.0)) {
    /* Outputs for IfAction SubSystem: '<S45>/If Action Subsystem' incorporates:
     *  ActionPort: '<S54>/Action Port'
     */
    rtb_Merge_e3 = fuzzyController_P._Value_g;

    /* End of Outputs for SubSystem: '<S45>/If Action Subsystem' */
  } else if (fuzzyController_U.frontDifferential == 1.0) {
    /* Outputs for IfAction SubSystem: '<S45>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S55>/Action Port'
     */
    rtb_Merge_e3 = fuzzyController_P._Value_ak;

    /* End of Outputs for SubSystem: '<S45>/If Action Subsystem1' */
  } else if (fuzzyController_U.frontDifferential < 1.0) {
    /* Outputs for IfAction SubSystem: '<S45>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S57>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.frontDifferential,
      &rtb_Merge_e3, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_d);

    /* End of Outputs for SubSystem: '<S45>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S45>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S56>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.frontDifferential,
      &rtb_Merge_e3, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_ht);

    /* End of Outputs for SubSystem: '<S45>/If Action Subsystem2' */
  }

  /* End of If: '<S45>/If' */

  /* If: '<S58>/If' incorporates:
   *  Constant: '<S61>/0'
   *  Constant: '<S62>/0'
   *  Inport: '<Root>/gyroYaw'
   */
  if ((fuzzyController_U.gyroYaw < -2.0) || (fuzzyController_U.gyroYaw > 0.0)) {
    /* Outputs for IfAction SubSystem: '<S58>/If Action Subsystem' incorporates:
     *  ActionPort: '<S61>/Action Port'
     */
    rtb_Merge_g = fuzzyController_P._Value_p;

    /* End of Outputs for SubSystem: '<S58>/If Action Subsystem' */
  } else if (fuzzyController_U.gyroYaw == -1.0) {
    /* Outputs for IfAction SubSystem: '<S58>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S62>/Action Port'
     */
    rtb_Merge_g = fuzzyController_P._Value_k;

    /* End of Outputs for SubSystem: '<S58>/If Action Subsystem1' */
  } else if (fuzzyController_U.gyroYaw < -1.0) {
    /* Outputs for IfAction SubSystem: '<S58>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S64>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.gyroYaw, &rtb_Merge_g,
      (P_IfActionSubsystem3_fuzzyCon_T *)&fuzzyController_P.IfActionSubsystem3_m);

    /* End of Outputs for SubSystem: '<S58>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S58>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S63>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.gyroYaw, &rtb_Merge_g,
      (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_ew);

    /* End of Outputs for SubSystem: '<S58>/If Action Subsystem2' */
  }

  /* End of If: '<S58>/If' */

  /* If: '<S59>/If' incorporates:
   *  Constant: '<S65>/0'
   *  Constant: '<S66>/0'
   *  Inport: '<Root>/gyroYaw'
   */
  if ((fuzzyController_U.gyroYaw < 0.0) || (fuzzyController_U.gyroYaw > 2.0)) {
    /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem' incorporates:
     *  ActionPort: '<S65>/Action Port'
     */
    rtb_Merge_m1 = fuzzyController_P._Value_kp;

    /* End of Outputs for SubSystem: '<S59>/If Action Subsystem' */
  } else if (fuzzyController_U.gyroYaw == 1.0) {
    /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S66>/Action Port'
     */
    rtb_Merge_m1 = fuzzyController_P._Value_pz;

    /* End of Outputs for SubSystem: '<S59>/If Action Subsystem1' */
  } else if (fuzzyController_U.gyroYaw < 1.0) {
    /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S68>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.gyroYaw, &rtb_Merge_m1,
      (P_IfActionSubsystem3_fuzzyCon_T *)&fuzzyController_P.IfActionSubsystem3_l);

    /* End of Outputs for SubSystem: '<S59>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S67>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.gyroYaw, &rtb_Merge_m1,
      (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_ac);

    /* End of Outputs for SubSystem: '<S59>/If Action Subsystem2' */
  }

  /* End of If: '<S59>/If' */

  /* If: '<S60>/If' incorporates:
   *  Constant: '<S69>/0'
   *  Constant: '<S70>/0'
   *  Inport: '<Root>/gyroYaw'
   */
  if ((fuzzyController_U.gyroYaw < -1.0) || (fuzzyController_U.gyroYaw > 1.0)) {
    /* Outputs for IfAction SubSystem: '<S60>/If Action Subsystem' incorporates:
     *  ActionPort: '<S69>/Action Port'
     */
    rtb_Merge_i1 = fuzzyController_P._Value_i;

    /* End of Outputs for SubSystem: '<S60>/If Action Subsystem' */
  } else if (fuzzyController_U.gyroYaw == 0.0) {
    /* Outputs for IfAction SubSystem: '<S60>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S70>/Action Port'
     */
    rtb_Merge_i1 = fuzzyController_P._Value_in;

    /* End of Outputs for SubSystem: '<S60>/If Action Subsystem1' */
  } else if (fuzzyController_U.gyroYaw < 0.0) {
    /* Outputs for IfAction SubSystem: '<S60>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S72>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.gyroYaw, &rtb_Merge_i1,
      (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_p3);

    /* End of Outputs for SubSystem: '<S60>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S60>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S71>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.gyroYaw, &rtb_Merge_i1,
      (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_hl);

    /* End of Outputs for SubSystem: '<S60>/If Action Subsystem2' */
  }

  /* End of If: '<S60>/If' */

  /* If: '<S75>/If' incorporates:
   *  Constant: '<S84>/0'
   *  Constant: '<S85>/0'
   *  Inport: '<Root>/powerBias'
   */
  if ((fuzzyController_U.powerBias < -1.0) || (fuzzyController_U.powerBias > 1.0))
  {
    /* Outputs for IfAction SubSystem: '<S75>/If Action Subsystem' incorporates:
     *  ActionPort: '<S84>/Action Port'
     */
    rtb_Merge_e5 = fuzzyController_P._Value_h;

    /* End of Outputs for SubSystem: '<S75>/If Action Subsystem' */
  } else if (fuzzyController_U.powerBias == 0.0) {
    /* Outputs for IfAction SubSystem: '<S75>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S85>/Action Port'
     */
    rtb_Merge_e5 = fuzzyController_P._Value_f;

    /* End of Outputs for SubSystem: '<S75>/If Action Subsystem1' */
  } else if (fuzzyController_U.powerBias < 0.0) {
    /* Outputs for IfAction SubSystem: '<S75>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S87>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.powerBias, &rtb_Merge_e5,
                                    (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_lk);

    /* End of Outputs for SubSystem: '<S75>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S75>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S86>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.powerBias, &rtb_Merge_e5,
                                    (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_c);

    /* End of Outputs for SubSystem: '<S75>/If Action Subsystem2' */
  }

  /* End of If: '<S75>/If' */

  /* If: '<S90>/If' incorporates:
   *  Constant: '<S100>/0'
   *  Constant: '<S99>/0'
   *  Inport: '<Root>/rearDifferential'
   */
  if ((fuzzyController_U.rearDifferential < 0.0) ||
      (fuzzyController_U.rearDifferential > 2.0)) {
    /* Outputs for IfAction SubSystem: '<S90>/If Action Subsystem' incorporates:
     *  ActionPort: '<S99>/Action Port'
     */
    rtb_Merge_ev = fuzzyController_P._Value_pc;

    /* End of Outputs for SubSystem: '<S90>/If Action Subsystem' */
  } else if (fuzzyController_U.rearDifferential == 1.0) {
    /* Outputs for IfAction SubSystem: '<S90>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S100>/Action Port'
     */
    rtb_Merge_ev = fuzzyController_P._Value_e;

    /* End of Outputs for SubSystem: '<S90>/If Action Subsystem1' */
  } else if (fuzzyController_U.rearDifferential < 1.0) {
    /* Outputs for IfAction SubSystem: '<S90>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S102>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.rearDifferential,
      &rtb_Merge_ev, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_gg);

    /* End of Outputs for SubSystem: '<S90>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S90>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S101>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.rearDifferential,
      &rtb_Merge_ev, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_ea);

    /* End of Outputs for SubSystem: '<S90>/If Action Subsystem2' */
  }

  /* End of If: '<S90>/If' */

  /* SignalConversion: '<S2>/TmpSignal ConversionAtAnimation1Inport1' incorporates:
   *  Inport: '<Root>/frontDifferential'
   *  Inport: '<Root>/gyroYaw'
   *  Inport: '<Root>/powerBias'
   *  Inport: '<Root>/rearDifferential'
   *  Inport: '<Root>/steeringSignal'
   *  Inport: '<Root>/throttleSignal'
   */
  fuzzyController_B.TmpSignalConversionAtAnimation1[0] =
    fuzzyController_U.gyroYaw;
  fuzzyController_B.TmpSignalConversionAtAnimation1[1] =
    fuzzyController_U.steeringSignal;
  fuzzyController_B.TmpSignalConversionAtAnimation1[2] =
    fuzzyController_U.throttleSignal;
  fuzzyController_B.TmpSignalConversionAtAnimation1[3] =
    fuzzyController_U.frontDifferential;
  fuzzyController_B.TmpSignalConversionAtAnimation1[4] =
    fuzzyController_U.rearDifferential;
  fuzzyController_B.TmpSignalConversionAtAnimation1[5] =
    fuzzyController_U.powerBias;
}

/* Model initialize function */
void fuzzyController_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &fuzzyController_B), 0,
                sizeof(B_fuzzyController_T));

  /* external inputs */
  (void) memset((void *)&fuzzyController_U, 0,
                sizeof(ExtU_fuzzyController_T));

  /* external outputs */
  (void) memset((void *)&fuzzyController_Y, 0,
                sizeof(ExtY_fuzzyController_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
