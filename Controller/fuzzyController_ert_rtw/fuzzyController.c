/*
 * File: fuzzyController.c
 *
 * Code generated for Simulink model 'fuzzyController'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Tue Jul 15 18:52:03 2014
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "fuzzyController.h"

/* Block signals (auto storage) */
B_fuzzyController_T fuzzyController_B;

/* External inputs (root inport signals with auto storage) */
ExtU_fuzzyController_T fuzzyController_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_fuzzyController_T fuzzyController_Y;
extern void fuzzyController_Actionu1(real_T rtu_0, real_T *rty_u2);
extern void fuzzyControl_IfActionSubsystem3(real_T rtu_x, real_T *rty_Out1,
  P_IfActionSubsystem3_fuzzyCon_T *localP);
extern void fuzzyControl_IfActionSubsystem2(real_T rtu_x, real_T *rty_Out1,
  P_IfActionSubsystem2_fuzzyCon_T *localP);

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
  /* Inport: '<S35>/u1' */
  *rty_u2 = rtu_0;
}

/*
 * Output and update for action system:
 *    '<S44>/If Action Subsystem3'
 *    '<S45>/If Action Subsystem3'
 *    '<S46>/If Action Subsystem3'
 *    '<S59>/If Action Subsystem3'
 *    '<S60>/If Action Subsystem3'
 *    '<S69>/If Action Subsystem3'
 *    '<S70>/If Action Subsystem3'
 *    '<S79>/If Action Subsystem3'
 *    '<S80>/If Action Subsystem3'
 *    '<S81>/If Action Subsystem3'
 *    ...
 */
void fuzzyControl_IfActionSubsystem3(real_T rtu_x, real_T *rty_Out1,
  P_IfActionSubsystem3_fuzzyCon_T *localP)
{
  /* Product: '<S50>/Product ab (trimf)' incorporates:
   *  Constant: '<S50>/a'
   *  Constant: '<S50>/b'
   *  Sum: '<S50>/Sum'
   *  Sum: '<S50>/Sum1'
   */
  *rty_Out1 = (rtu_x - localP->a_Value) / (localP->b_Value - localP->a_Value);
}

/*
 * Output and update for action system:
 *    '<S44>/If Action Subsystem2'
 *    '<S45>/If Action Subsystem2'
 *    '<S46>/If Action Subsystem2'
 *    '<S59>/If Action Subsystem2'
 *    '<S60>/If Action Subsystem2'
 *    '<S69>/If Action Subsystem2'
 *    '<S70>/If Action Subsystem2'
 *    '<S79>/If Action Subsystem2'
 *    '<S80>/If Action Subsystem2'
 *    '<S81>/If Action Subsystem2'
 *    ...
 */
void fuzzyControl_IfActionSubsystem2(real_T rtu_x, real_T *rty_Out1,
  P_IfActionSubsystem2_fuzzyCon_T *localP)
{
  /* Product: '<S49>/Product cd (trimf)' incorporates:
   *  Constant: '<S49>/b'
   *  Constant: '<S49>/c'
   *  Sum: '<S49>/Sum2'
   *  Sum: '<S49>/Sum3'
   */
  *rty_Out1 = 1.0 / (localP->c_Value - localP->b_Value) * (localP->c_Value -
    rtu_x);
}

/* Model step function */
void fuzzyController_step(void)
{
  /* local block i/o variables */
  real_T rtb_Merge_j;
  real_T rtb_Merge_g;
  real_T rtb_Merge_c;
  real_T rtb_Merge_j2;
  real_T rtb_Merge_kn;
  real_T rtb_Merge_ok;
  real_T rtb_Merge_cy;
  int32_T i;

  /* If: '<S94>/If' incorporates:
   *  Constant: '<S96>/0'
   *  Constant: '<S97>/0'
   *  Inport: '<Root>/steeringSignal'
   */
  if ((fuzzyController_U.steeringSignal < -3.0) ||
      (fuzzyController_U.steeringSignal > 1.0)) {
    /* Outputs for IfAction SubSystem: '<S94>/If Action Subsystem' incorporates:
     *  ActionPort: '<S96>/Action Port'
     */
    fuzzyController_B.Merge = fuzzyController_P._Value_pq;

    /* End of Outputs for SubSystem: '<S94>/If Action Subsystem' */
  } else if (fuzzyController_U.steeringSignal == -1.0) {
    /* Outputs for IfAction SubSystem: '<S94>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S97>/Action Port'
     */
    fuzzyController_B.Merge = fuzzyController_P._Value_ar;

    /* End of Outputs for SubSystem: '<S94>/If Action Subsystem1' */
  } else if (fuzzyController_U.steeringSignal < -1.0) {
    /* Outputs for IfAction SubSystem: '<S94>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S99>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.steeringSignal,
      &fuzzyController_B.Merge, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S94>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S94>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S98>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.steeringSignal,
      &fuzzyController_B.Merge, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S94>/If Action Subsystem2' */
  }

  /* End of If: '<S94>/If' */

  /* Product: '<S14>/Weighting' incorporates:
   *  Constant: '<S14>/Weight'
   */
  fuzzyController_B.Weighting = fuzzyController_P.Weight_Value *
    fuzzyController_B.Merge;

  /* Product: '<S14>/impMethod' incorporates:
   *  Constant: '<S31>/left'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod[i] = fuzzyController_B.Weighting *
      fuzzyController_P.left_Value[i];
  }

  /* End of Product: '<S14>/impMethod' */

  /* If: '<S95>/If' incorporates:
   *  Constant: '<S100>/0'
   *  Constant: '<S101>/0'
   *  Inport: '<Root>/steeringSignal'
   */
  if ((fuzzyController_U.steeringSignal < -1.0) ||
      (fuzzyController_U.steeringSignal > 3.0)) {
    /* Outputs for IfAction SubSystem: '<S95>/If Action Subsystem' incorporates:
     *  ActionPort: '<S100>/Action Port'
     */
    fuzzyController_B.Merge_h = fuzzyController_P._Value_n4;

    /* End of Outputs for SubSystem: '<S95>/If Action Subsystem' */
  } else if (fuzzyController_U.steeringSignal == 1.0) {
    /* Outputs for IfAction SubSystem: '<S95>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S101>/Action Port'
     */
    fuzzyController_B.Merge_h = fuzzyController_P._Value_py;

    /* End of Outputs for SubSystem: '<S95>/If Action Subsystem1' */
  } else if (fuzzyController_U.steeringSignal < 1.0) {
    /* Outputs for IfAction SubSystem: '<S95>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S103>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.steeringSignal,
      &fuzzyController_B.Merge_h, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_d);

    /* End of Outputs for SubSystem: '<S95>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S95>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S102>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.steeringSignal,
      &fuzzyController_B.Merge_h, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_g);

    /* End of Outputs for SubSystem: '<S95>/If Action Subsystem2' */
  }

  /* End of If: '<S95>/If' */

  /* Product: '<S19>/Weighting' incorporates:
   *  Constant: '<S19>/Weight'
   */
  fuzzyController_B.Weighting_h = fuzzyController_P.Weight_Value_b *
    fuzzyController_B.Merge_h;

  /* Product: '<S19>/impMethod' incorporates:
   *  Constant: '<S31>/right'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_b[i] = fuzzyController_B.Weighting_h *
      fuzzyController_P.right_Value[i];
  }

  /* End of Product: '<S19>/impMethod' */

  /* If: '<S60>/If' incorporates:
   *  Constant: '<S65>/0'
   *  Constant: '<S66>/0'
   *  Inport: '<Root>/gyroYaw'
   */
  if ((fuzzyController_U.gyroYaw < -2.0) || (fuzzyController_U.gyroYaw > 0.0)) {
    /* Outputs for IfAction SubSystem: '<S60>/If Action Subsystem' incorporates:
     *  ActionPort: '<S65>/Action Port'
     */
    fuzzyController_B.Merge_d = fuzzyController_P._Value_a;

    /* End of Outputs for SubSystem: '<S60>/If Action Subsystem' */
  } else if (fuzzyController_U.gyroYaw == -1.0) {
    /* Outputs for IfAction SubSystem: '<S60>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S66>/Action Port'
     */
    fuzzyController_B.Merge_d = fuzzyController_P._Value_oz;

    /* End of Outputs for SubSystem: '<S60>/If Action Subsystem1' */
  } else if (fuzzyController_U.gyroYaw < -1.0) {
    /* Outputs for IfAction SubSystem: '<S60>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S68>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.gyroYaw,
      &fuzzyController_B.Merge_d, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_c);

    /* End of Outputs for SubSystem: '<S60>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S60>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S67>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.gyroYaw,
      &fuzzyController_B.Merge_d, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_go);

    /* End of Outputs for SubSystem: '<S60>/If Action Subsystem2' */
  }

  /* End of If: '<S60>/If' */

  /* MinMax: '<S17>/andorMethod' */
  if (fuzzyController_B.Merge_d <= fuzzyController_B.Merge) {
    fuzzyController_B.Sum = fuzzyController_B.Merge_d;
  } else {
    fuzzyController_B.Sum = fuzzyController_B.Merge;
  }

  /* End of MinMax: '<S17>/andorMethod' */

  /* Product: '<S17>/Weighting' incorporates:
   *  Constant: '<S17>/Weight'
   */
  fuzzyController_B.Weighting_oc = fuzzyController_P.Weight_Value_j *
    fuzzyController_B.Sum;

  /* Product: '<S17>/impMethod' incorporates:
   *  Constant: '<S31>/left'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_m[i] = fuzzyController_B.Weighting_oc *
      fuzzyController_P.left_Value[i];
  }

  /* End of Product: '<S17>/impMethod' */

  /* If: '<S59>/If' incorporates:
   *  Constant: '<S61>/0'
   *  Constant: '<S62>/0'
   *  Inport: '<Root>/gyroYaw'
   */
  if ((fuzzyController_U.gyroYaw < 0.0) || (fuzzyController_U.gyroYaw > 2.0)) {
    /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem' incorporates:
     *  ActionPort: '<S61>/Action Port'
     */
    fuzzyController_B.Merge_n = fuzzyController_P._Value_p;

    /* End of Outputs for SubSystem: '<S59>/If Action Subsystem' */
  } else if (fuzzyController_U.gyroYaw == 1.0) {
    /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S62>/Action Port'
     */
    fuzzyController_B.Merge_n = fuzzyController_P._Value_c;

    /* End of Outputs for SubSystem: '<S59>/If Action Subsystem1' */
  } else if (fuzzyController_U.gyroYaw < 1.0) {
    /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S64>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.gyroYaw,
      &fuzzyController_B.Merge_n, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_j);

    /* End of Outputs for SubSystem: '<S59>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S63>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.gyroYaw,
      &fuzzyController_B.Merge_n, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_k);

    /* End of Outputs for SubSystem: '<S59>/If Action Subsystem2' */
  }

  /* End of If: '<S59>/If' */

  /* MinMax: '<S18>/andorMethod' */
  if (fuzzyController_B.Merge_n <= fuzzyController_B.Merge_h) {
    fuzzyController_B.Sum = fuzzyController_B.Merge_n;
  } else {
    fuzzyController_B.Sum = fuzzyController_B.Merge_h;
  }

  /* End of MinMax: '<S18>/andorMethod' */

  /* Product: '<S18>/Weighting' incorporates:
   *  Constant: '<S18>/Weight'
   */
  fuzzyController_B.Weighting_a = fuzzyController_P.Weight_Value_f *
    fuzzyController_B.Sum;

  /* Sum: '<S4>/AggMethod1' incorporates:
   *  Constant: '<S31>/right'
   *  Product: '<S18>/impMethod'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod[i] = ((fuzzyController_B.impMethod[i] +
      fuzzyController_B.impMethod_b[i]) + fuzzyController_B.impMethod_m[i]) +
      fuzzyController_B.Weighting_a * fuzzyController_P.right_Value[i];
  }

  /* End of Sum: '<S4>/AggMethod1' */

  /* Sum: '<S7>/Sum1' */
  fuzzyController_B.Sum = fuzzyController_B.impMethod[0];
  for (i = 0; i < 100; i++) {
    fuzzyController_B.Sum += fuzzyController_B.impMethod[i + 1];
  }

  fuzzyController_B.Sum1 = fuzzyController_B.Sum;

  /* End of Sum: '<S7>/Sum1' */

  /* If: '<S7>/If' incorporates:
   *  Constant: '<S34>/One'
   */
  if (fuzzyController_B.Sum1 <= 0.0) {
    /* Outputs for IfAction SubSystem: '<S7>/Action: One' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    rtb_Merge_j = fuzzyController_P.One_Value;

    /* End of Outputs for SubSystem: '<S7>/Action: One' */
  } else {
    /* Outputs for IfAction SubSystem: '<S7>/Action: u1' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    fuzzyController_Actionu1(fuzzyController_B.Sum1, &rtb_Merge_j);

    /* End of Outputs for SubSystem: '<S7>/Action: u1' */
  }

  /* End of If: '<S7>/If' */

  /* If: '<S69>/If' incorporates:
   *  Constant: '<S71>/0'
   *  Constant: '<S72>/0'
   *  Inport: '<Root>/powerBias'
   */
  if ((fuzzyController_U.powerBias < -0.0) || (fuzzyController_U.powerBias > 2.0))
  {
    /* Outputs for IfAction SubSystem: '<S69>/If Action Subsystem' incorporates:
     *  ActionPort: '<S71>/Action Port'
     */
    fuzzyController_B.Merge_m = fuzzyController_P._Value_e;

    /* End of Outputs for SubSystem: '<S69>/If Action Subsystem' */
  } else if (fuzzyController_U.powerBias == 1.0) {
    /* Outputs for IfAction SubSystem: '<S69>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S72>/Action Port'
     */
    fuzzyController_B.Merge_m = fuzzyController_P._Value_p0;

    /* End of Outputs for SubSystem: '<S69>/If Action Subsystem1' */
  } else if (fuzzyController_U.powerBias < 1.0) {
    /* Outputs for IfAction SubSystem: '<S69>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S74>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.powerBias,
      &fuzzyController_B.Merge_m, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_d1);

    /* End of Outputs for SubSystem: '<S69>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S69>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S73>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.powerBias,
      &fuzzyController_B.Merge_m, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_b);

    /* End of Outputs for SubSystem: '<S69>/If Action Subsystem2' */
  }

  /* End of If: '<S69>/If' */

  /* Product: '<S21>/Weighting' incorporates:
   *  Constant: '<S21>/Weight'
   */
  fuzzyController_B.Weighting_i = fuzzyController_P.Weight_Value_h *
    fuzzyController_B.Merge_m;

  /* Product: '<S21>/impMethod' incorporates:
   *  Constant: '<S12>/neutral'
   *  Constant: '<S13>/neutral'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_l[i] = fuzzyController_B.Weighting_i *
      fuzzyController_P.neutral_Value[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_l[i + 101] = fuzzyController_B.Weighting_i *
      fuzzyController_P.neutral_Value_h[i];
  }

  /* End of Product: '<S21>/impMethod' */

  /* If: '<S105>/If' incorporates:
   *  Constant: '<S111>/0'
   *  Constant: '<S112>/0'
   *  Inport: '<Root>/throttleSignal'
   */
  if ((fuzzyController_U.throttleSignal < -1.0) ||
      (fuzzyController_U.throttleSignal > 1.0)) {
    /* Outputs for IfAction SubSystem: '<S105>/If Action Subsystem' incorporates:
     *  ActionPort: '<S111>/Action Port'
     */
    fuzzyController_B.Merge_k = fuzzyController_P._Value_af;

    /* End of Outputs for SubSystem: '<S105>/If Action Subsystem' */
  } else if (fuzzyController_U.throttleSignal == 0.0) {
    /* Outputs for IfAction SubSystem: '<S105>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S112>/Action Port'
     */
    fuzzyController_B.Merge_k = fuzzyController_P._Value_b;

    /* End of Outputs for SubSystem: '<S105>/If Action Subsystem1' */
  } else if (fuzzyController_U.throttleSignal < 0.0) {
    /* Outputs for IfAction SubSystem: '<S105>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S114>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.throttleSignal,
      &fuzzyController_B.Merge_k, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_co);

    /* End of Outputs for SubSystem: '<S105>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S105>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S113>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.throttleSignal,
      &fuzzyController_B.Merge_k, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_f);

    /* End of Outputs for SubSystem: '<S105>/If Action Subsystem2' */
  }

  /* End of If: '<S105>/If' */

  /* Product: '<S22>/Weighting' incorporates:
   *  Constant: '<S22>/Weight'
   */
  fuzzyController_B.Weighting_o = fuzzyController_P.Weight_Value_g *
    fuzzyController_B.Merge_k;

  /* Product: '<S22>/impMethod' incorporates:
   *  Constant: '<S12>/neutral'
   *  Constant: '<S13>/neutral'
   *  Constant: '<S5>/neutral'
   *  Constant: '<S6>/neutral'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_g[i] = fuzzyController_B.Weighting_o *
      fuzzyController_P.neutral_Value[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_g[i + 101] = fuzzyController_B.Weighting_o *
      fuzzyController_P.neutral_Value_h[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_g[i + 202] = fuzzyController_B.Weighting_o *
      fuzzyController_P.neutral_Value_he[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_g[i + 303] = fuzzyController_B.Weighting_o *
      fuzzyController_P.neutral_Value_hb[i];
  }

  /* End of Product: '<S22>/impMethod' */

  /* If: '<S106>/If' incorporates:
   *  Constant: '<S115>/0'
   *  Constant: '<S116>/0'
   *  Inport: '<Root>/throttleSignal'
   */
  if ((fuzzyController_U.throttleSignal < -2.0) ||
      (fuzzyController_U.throttleSignal > 0.0)) {
    /* Outputs for IfAction SubSystem: '<S106>/If Action Subsystem' incorporates:
     *  ActionPort: '<S115>/Action Port'
     */
    fuzzyController_B.Merge_j5 = fuzzyController_P._Value_i3;

    /* End of Outputs for SubSystem: '<S106>/If Action Subsystem' */
  } else if (fuzzyController_U.throttleSignal == -1.0) {
    /* Outputs for IfAction SubSystem: '<S106>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S116>/Action Port'
     */
    fuzzyController_B.Merge_j5 = fuzzyController_P._Value_f;

    /* End of Outputs for SubSystem: '<S106>/If Action Subsystem1' */
  } else if (fuzzyController_U.throttleSignal < -1.0) {
    /* Outputs for IfAction SubSystem: '<S106>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S118>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.throttleSignal,
      &fuzzyController_B.Merge_j5, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_l);

    /* End of Outputs for SubSystem: '<S106>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S106>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S117>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.throttleSignal,
      &fuzzyController_B.Merge_j5, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_c);

    /* End of Outputs for SubSystem: '<S106>/If Action Subsystem2' */
  }

  /* End of If: '<S106>/If' */

  /* Product: '<S23>/Weighting' incorporates:
   *  Constant: '<S23>/Weight'
   */
  fuzzyController_B.Weighting_l = fuzzyController_P.Weight_Value_jg *
    fuzzyController_B.Merge_j5;

  /* Product: '<S23>/impMethod' incorporates:
   *  Constant: '<S12>/reverse'
   *  Constant: '<S13>/reverse'
   *  Constant: '<S5>/reverse'
   *  Constant: '<S6>/reverse'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_f[i] = fuzzyController_B.Weighting_l *
      fuzzyController_P.reverse_Value[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_f[i + 101] = fuzzyController_B.Weighting_l *
      fuzzyController_P.reverse_Value_b[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_f[i + 202] = fuzzyController_B.Weighting_l *
      fuzzyController_P.reverse_Value_c[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_f[i + 303] = fuzzyController_B.Weighting_l *
      fuzzyController_P.reverse_Value_n[i];
  }

  /* End of Product: '<S23>/impMethod' */

  /* If: '<S45>/If' incorporates:
   *  Constant: '<S51>/0'
   *  Constant: '<S52>/0'
   *  Inport: '<Root>/frontDifferential'
   */
  if ((fuzzyController_U.frontDifferential < -1.0) ||
      (fuzzyController_U.frontDifferential > 1.0)) {
    /* Outputs for IfAction SubSystem: '<S45>/If Action Subsystem' incorporates:
     *  ActionPort: '<S51>/Action Port'
     */
    rtb_Merge_g = fuzzyController_P._Value_i;

    /* End of Outputs for SubSystem: '<S45>/If Action Subsystem' */
  } else if (fuzzyController_U.frontDifferential == 0.0) {
    /* Outputs for IfAction SubSystem: '<S45>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S52>/Action Port'
     */
    rtb_Merge_g = fuzzyController_P._Value_h;

    /* End of Outputs for SubSystem: '<S45>/If Action Subsystem1' */
  } else if (fuzzyController_U.frontDifferential < 0.0) {
    /* Outputs for IfAction SubSystem: '<S45>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S54>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.frontDifferential,
      &rtb_Merge_g, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_a);

    /* End of Outputs for SubSystem: '<S45>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S45>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S53>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.frontDifferential,
      &rtb_Merge_g, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_d);

    /* End of Outputs for SubSystem: '<S45>/If Action Subsystem2' */
  }

  /* End of If: '<S45>/If' */

  /* If: '<S104>/If' incorporates:
   *  Constant: '<S107>/0'
   *  Constant: '<S108>/0'
   *  Inport: '<Root>/throttleSignal'
   */
  if ((fuzzyController_U.throttleSignal < -0.0) ||
      (fuzzyController_U.throttleSignal > 2.0)) {
    /* Outputs for IfAction SubSystem: '<S104>/If Action Subsystem' incorporates:
     *  ActionPort: '<S107>/Action Port'
     */
    fuzzyController_B.Merge_o = fuzzyController_P._Value_aj;

    /* End of Outputs for SubSystem: '<S104>/If Action Subsystem' */
  } else if (fuzzyController_U.throttleSignal == 1.0) {
    /* Outputs for IfAction SubSystem: '<S104>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S108>/Action Port'
     */
    fuzzyController_B.Merge_o = fuzzyController_P._Value_ju;

    /* End of Outputs for SubSystem: '<S104>/If Action Subsystem1' */
  } else if (fuzzyController_U.throttleSignal < 1.0) {
    /* Outputs for IfAction SubSystem: '<S104>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S110>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.throttleSignal,
      &fuzzyController_B.Merge_o, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_g);

    /* End of Outputs for SubSystem: '<S104>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S104>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S109>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.throttleSignal,
      &fuzzyController_B.Merge_o, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_p);

    /* End of Outputs for SubSystem: '<S104>/If Action Subsystem2' */
  }

  /* End of If: '<S104>/If' */

  /* MinMax: '<S26>/andorMethod' */
  if (fuzzyController_B.Merge <= fuzzyController_B.Merge_o) {
    fuzzyController_B.ZeroFiringStrength = fuzzyController_B.Merge;
  } else {
    fuzzyController_B.ZeroFiringStrength = fuzzyController_B.Merge_o;
  }

  if (!(fuzzyController_B.ZeroFiringStrength <= rtb_Merge_g)) {
    fuzzyController_B.ZeroFiringStrength = rtb_Merge_g;
  }

  /* Product: '<S26>/Weighting' incorporates:
   *  Constant: '<S26>/Weight'
   *  MinMax: '<S26>/andorMethod'
   */
  fuzzyController_B.Weighting_c = fuzzyController_P.Weight_Value_o *
    fuzzyController_B.ZeroFiringStrength;

  /* Product: '<S26>/impMethod' incorporates:
   *  Constant: '<S12>/neutral'
   *  Constant: '<S13>/forward'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_i[i] = fuzzyController_B.Weighting_c *
      fuzzyController_P.neutral_Value[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_i[i + 101] = fuzzyController_B.Weighting_c *
      fuzzyController_P.forward_Value[i];
  }

  /* End of Product: '<S26>/impMethod' */

  /* MinMax: '<S15>/andorMethod' */
  if (fuzzyController_B.Merge_h <= fuzzyController_B.Merge_o) {
    fuzzyController_B.ZeroFiringStrength = fuzzyController_B.Merge_h;
  } else {
    fuzzyController_B.ZeroFiringStrength = fuzzyController_B.Merge_o;
  }

  if (!(fuzzyController_B.ZeroFiringStrength <= rtb_Merge_g)) {
    fuzzyController_B.ZeroFiringStrength = rtb_Merge_g;
  }

  /* Product: '<S15>/Weighting' incorporates:
   *  Constant: '<S15>/Weight'
   *  MinMax: '<S15>/andorMethod'
   */
  fuzzyController_B.Weighting_m5 = fuzzyController_P.Weight_Value_ou *
    fuzzyController_B.ZeroFiringStrength;

  /* Product: '<S15>/impMethod' incorporates:
   *  Constant: '<S12>/forward'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_p[i] = fuzzyController_B.Weighting_m5 *
      fuzzyController_P.forward_Value_a[i];
  }

  /* Product: '<S16>/Weighting' incorporates:
   *  Constant: '<S16>/Weight'
   */
  fuzzyController_B.Weighting_m = fuzzyController_P.Weight_Value_p *
    fuzzyController_B.Merge_o;
  for (i = 0; i < 101; i++) {
    /* Product: '<S15>/impMethod' incorporates:
     *  Constant: '<S13>/neutral'
     */
    fuzzyController_B.impMethod_p[i + 101] = fuzzyController_B.Weighting_m5 *
      fuzzyController_P.neutral_Value_h[i];

    /* Product: '<S16>/impMethod' incorporates:
     *  Constant: '<S12>/forward'
     */
    fuzzyController_B.impMethod_e[i] = fuzzyController_B.Weighting_m *
      fuzzyController_P.forward_Value_a[i];
  }

  /* Product: '<S16>/impMethod' incorporates:
   *  Constant: '<S13>/forward'
   *  Constant: '<S5>/forward'
   *  Constant: '<S6>/forward'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_e[i + 101] = fuzzyController_B.Weighting_m *
      fuzzyController_P.forward_Value[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_e[i + 202] = fuzzyController_B.Weighting_m *
      fuzzyController_P.forward_Value_e[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_e[i + 303] = fuzzyController_B.Weighting_m *
      fuzzyController_P.forward_Value_c[i];
  }

  for (i = 0; i < 101; i++) {
    /* Sum: '<S4>/AggMethod2' */
    fuzzyController_B.Sum = ((((fuzzyController_B.impMethod_l[i] +
      fuzzyController_B.impMethod_g[i]) + fuzzyController_B.impMethod_f[i]) +
      fuzzyController_B.impMethod_i[i]) + fuzzyController_B.impMethod_p[i]) +
      fuzzyController_B.impMethod_e[i];

    /* Product: '<S8>/Product (COA)' incorporates:
     *  Constant: '<S8>/x data'
     */
    fuzzyController_B.impMethod_b[i] = fuzzyController_P.xdata_Value_m[i] *
      fuzzyController_B.Sum;

    /* Sum: '<S4>/AggMethod2' */
    fuzzyController_B.impMethod_m[i] = fuzzyController_B.Sum;
  }

  /* Sum: '<S8>/Sum' */
  fuzzyController_B.AveragingCOA_l = fuzzyController_B.impMethod_b[0];

  /* Sum: '<S8>/Sum1' */
  fuzzyController_B.Sum = fuzzyController_B.impMethod_m[0];
  for (i = 0; i < 100; i++) {
    /* Sum: '<S8>/Sum' */
    fuzzyController_B.AveragingCOA_l += fuzzyController_B.impMethod_b[i + 1];
    fuzzyController_B.Sum += fuzzyController_B.impMethod_m[i + 1];
  }

  fuzzyController_B.Sum1_l = fuzzyController_B.Sum;

  /* End of Sum: '<S8>/Sum1' */

  /* If: '<S8>/If' incorporates:
   *  Constant: '<S36>/One'
   */
  if (fuzzyController_B.Sum1_l <= 0.0) {
    /* Outputs for IfAction SubSystem: '<S8>/Action: One' incorporates:
     *  ActionPort: '<S36>/Action Port'
     */
    fuzzyController_B.Merge_i = fuzzyController_P.One_Value_n;

    /* End of Outputs for SubSystem: '<S8>/Action: One' */
  } else {
    /* Outputs for IfAction SubSystem: '<S8>/Action: u1' incorporates:
     *  ActionPort: '<S37>/Action Port'
     */
    fuzzyController_Actionu1(fuzzyController_B.Sum1_l,
      &fuzzyController_B.Merge_i);

    /* End of Outputs for SubSystem: '<S8>/Action: u1' */
  }

  /* End of If: '<S8>/If' */

  /* Product: '<S8>/Averaging (COA)' */
  fuzzyController_B.AveragingCOA_l /= fuzzyController_B.Merge_i;
  for (i = 0; i < 101; i++) {
    /* Sum: '<S4>/AggMethod3' */
    fuzzyController_B.Sum = ((((fuzzyController_B.impMethod_l[i + 101] +
      fuzzyController_B.impMethod_g[i + 101]) + fuzzyController_B.impMethod_f[i
      + 101]) + fuzzyController_B.impMethod_i[i + 101]) +
      fuzzyController_B.impMethod_p[i + 101]) + fuzzyController_B.impMethod_e[i
      + 101];

    /* Product: '<S9>/Product (COA)' incorporates:
     *  Constant: '<S9>/x data'
     */
    fuzzyController_B.impMethod_b[i] = fuzzyController_P.xdata_Value_i[i] *
      fuzzyController_B.Sum;

    /* Sum: '<S4>/AggMethod3' */
    fuzzyController_B.impMethod_m[i] = fuzzyController_B.Sum;
  }

  /* Sum: '<S9>/Sum' */
  fuzzyController_B.AveragingCOA_b = fuzzyController_B.impMethod_b[0];

  /* Sum: '<S9>/Sum1' */
  fuzzyController_B.Sum = fuzzyController_B.impMethod_m[0];
  for (i = 0; i < 100; i++) {
    /* Sum: '<S9>/Sum' */
    fuzzyController_B.AveragingCOA_b += fuzzyController_B.impMethod_b[i + 1];
    fuzzyController_B.Sum += fuzzyController_B.impMethod_m[i + 1];
  }

  fuzzyController_B.Sum1_h = fuzzyController_B.Sum;

  /* End of Sum: '<S9>/Sum1' */

  /* If: '<S9>/If' incorporates:
   *  Constant: '<S38>/One'
   */
  if (fuzzyController_B.Sum1_h <= 0.0) {
    /* Outputs for IfAction SubSystem: '<S9>/Action: One' incorporates:
     *  ActionPort: '<S38>/Action Port'
     */
    fuzzyController_B.Merge_ic = fuzzyController_P.One_Value_g;

    /* End of Outputs for SubSystem: '<S9>/Action: One' */
  } else {
    /* Outputs for IfAction SubSystem: '<S9>/Action: u1' incorporates:
     *  ActionPort: '<S39>/Action Port'
     */
    fuzzyController_Actionu1(fuzzyController_B.Sum1_h,
      &fuzzyController_B.Merge_ic);

    /* End of Outputs for SubSystem: '<S9>/Action: u1' */
  }

  /* End of If: '<S9>/If' */

  /* Product: '<S9>/Averaging (COA)' */
  fuzzyController_B.AveragingCOA_b /= fuzzyController_B.Merge_ic;

  /* If: '<S70>/If' incorporates:
   *  Constant: '<S75>/0'
   *  Constant: '<S76>/0'
   *  Inport: '<Root>/powerBias'
   */
  if ((fuzzyController_U.powerBias < -2.0) || (fuzzyController_U.powerBias >
       -0.0)) {
    /* Outputs for IfAction SubSystem: '<S70>/If Action Subsystem' incorporates:
     *  ActionPort: '<S75>/Action Port'
     */
    fuzzyController_B.Merge_n1 = fuzzyController_P._Value_j;

    /* End of Outputs for SubSystem: '<S70>/If Action Subsystem' */
  } else if (fuzzyController_U.powerBias == -1.0) {
    /* Outputs for IfAction SubSystem: '<S70>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S76>/Action Port'
     */
    fuzzyController_B.Merge_n1 = fuzzyController_P._Value_mx;

    /* End of Outputs for SubSystem: '<S70>/If Action Subsystem1' */
  } else if (fuzzyController_U.powerBias < -1.0) {
    /* Outputs for IfAction SubSystem: '<S70>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S78>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.powerBias,
      &fuzzyController_B.Merge_n1, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_f);

    /* End of Outputs for SubSystem: '<S70>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S70>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S77>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.powerBias,
      &fuzzyController_B.Merge_n1, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_ga);

    /* End of Outputs for SubSystem: '<S70>/If Action Subsystem2' */
  }

  /* End of If: '<S70>/If' */

  /* Product: '<S20>/Weighting' incorporates:
   *  Constant: '<S20>/Weight'
   */
  fuzzyController_B.Weighting_k = fuzzyController_P.Weight_Value_hi *
    fuzzyController_B.Merge_n1;

  /* Product: '<S20>/impMethod' incorporates:
   *  Constant: '<S5>/neutral'
   *  Constant: '<S6>/neutral'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_p[i] = fuzzyController_B.Weighting_k *
      fuzzyController_P.neutral_Value_he[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_p[i + 101] = fuzzyController_B.Weighting_k *
      fuzzyController_P.neutral_Value_hb[i];
  }

  /* End of Product: '<S20>/impMethod' */

  /* If: '<S80>/If' incorporates:
   *  Constant: '<S86>/0'
   *  Constant: '<S87>/0'
   *  Inport: '<Root>/rearDifferential'
   */
  if ((fuzzyController_U.rearDifferential < -1.0) ||
      (fuzzyController_U.rearDifferential > 1.0)) {
    /* Outputs for IfAction SubSystem: '<S80>/If Action Subsystem' incorporates:
     *  ActionPort: '<S86>/Action Port'
     */
    rtb_Merge_c = fuzzyController_P._Value_d;

    /* End of Outputs for SubSystem: '<S80>/If Action Subsystem' */
  } else if (fuzzyController_U.rearDifferential == 0.0) {
    /* Outputs for IfAction SubSystem: '<S80>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S87>/Action Port'
     */
    rtb_Merge_c = fuzzyController_P._Value_no;

    /* End of Outputs for SubSystem: '<S80>/If Action Subsystem1' */
  } else if (fuzzyController_U.rearDifferential < 0.0) {
    /* Outputs for IfAction SubSystem: '<S80>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S89>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.rearDifferential,
      &rtb_Merge_c, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_i);

    /* End of Outputs for SubSystem: '<S80>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S80>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S88>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.rearDifferential,
      &rtb_Merge_c, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_a);

    /* End of Outputs for SubSystem: '<S80>/If Action Subsystem2' */
  }

  /* End of If: '<S80>/If' */

  /* MinMax: '<S24>/andorMethod' */
  if (fuzzyController_B.Merge <= fuzzyController_B.Merge_o) {
    fuzzyController_B.ZeroFiringStrength = fuzzyController_B.Merge;
  } else {
    fuzzyController_B.ZeroFiringStrength = fuzzyController_B.Merge_o;
  }

  if (!(fuzzyController_B.ZeroFiringStrength <= rtb_Merge_c)) {
    fuzzyController_B.ZeroFiringStrength = rtb_Merge_c;
  }

  /* Product: '<S24>/Weighting' incorporates:
   *  Constant: '<S24>/Weight'
   *  MinMax: '<S24>/andorMethod'
   */
  fuzzyController_B.Weighting_ae = fuzzyController_P.Weight_Value_bt *
    fuzzyController_B.ZeroFiringStrength;

  /* Product: '<S24>/impMethod' incorporates:
   *  Constant: '<S5>/neutral'
   *  Constant: '<S6>/forward'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_i[i] = fuzzyController_B.Weighting_ae *
      fuzzyController_P.neutral_Value_he[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_i[i + 101] = fuzzyController_B.Weighting_ae *
      fuzzyController_P.forward_Value_c[i];
  }

  /* End of Product: '<S24>/impMethod' */

  /* MinMax: '<S25>/andorMethod' */
  if (fuzzyController_B.Merge_h <= fuzzyController_B.Merge_o) {
    fuzzyController_B.ZeroFiringStrength = fuzzyController_B.Merge_h;
  } else {
    fuzzyController_B.ZeroFiringStrength = fuzzyController_B.Merge_o;
  }

  if (!(fuzzyController_B.ZeroFiringStrength <= rtb_Merge_c)) {
    fuzzyController_B.ZeroFiringStrength = rtb_Merge_c;
  }

  /* Product: '<S25>/Weighting' incorporates:
   *  Constant: '<S25>/Weight'
   *  MinMax: '<S25>/andorMethod'
   */
  fuzzyController_B.ZeroFiringStrength *= fuzzyController_P.Weight_Value_fj;

  /* Product: '<S25>/impMethod' incorporates:
   *  Constant: '<S5>/forward'
   *  Constant: '<S6>/neutral'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_l[i] = fuzzyController_B.ZeroFiringStrength *
      fuzzyController_P.forward_Value_e[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_l[i + 101] =
      fuzzyController_B.ZeroFiringStrength *
      fuzzyController_P.neutral_Value_hb[i];
  }

  for (i = 0; i < 101; i++) {
    /* Sum: '<S4>/AggMethod4' */
    fuzzyController_B.Sum = ((((fuzzyController_B.impMethod_g[i + 202] +
      fuzzyController_B.impMethod_p[i]) + fuzzyController_B.impMethod_f[i + 202])
      + fuzzyController_B.impMethod_i[i]) + fuzzyController_B.impMethod_l[i]) +
      fuzzyController_B.impMethod_e[i + 202];

    /* Product: '<S10>/Product (COA)' incorporates:
     *  Constant: '<S10>/x data'
     */
    fuzzyController_B.impMethod_b[i] = fuzzyController_P.xdata_Value_j[i] *
      fuzzyController_B.Sum;

    /* Sum: '<S4>/AggMethod4' */
    fuzzyController_B.impMethod_m[i] = fuzzyController_B.Sum;
  }

  /* End of Product: '<S25>/impMethod' */

  /* Sum: '<S10>/Sum' */
  fuzzyController_B.AveragingCOA_f = fuzzyController_B.impMethod_b[0];

  /* Sum: '<S10>/Sum1' */
  fuzzyController_B.Sum = fuzzyController_B.impMethod_m[0];
  for (i = 0; i < 100; i++) {
    /* Sum: '<S10>/Sum' */
    fuzzyController_B.AveragingCOA_f += fuzzyController_B.impMethod_b[i + 1];
    fuzzyController_B.Sum += fuzzyController_B.impMethod_m[i + 1];
  }

  fuzzyController_B.Sum1_b = fuzzyController_B.Sum;

  /* End of Sum: '<S10>/Sum1' */

  /* If: '<S10>/If' incorporates:
   *  Constant: '<S40>/One'
   */
  if (fuzzyController_B.Sum1_b <= 0.0) {
    /* Outputs for IfAction SubSystem: '<S10>/Action: One' incorporates:
     *  ActionPort: '<S40>/Action Port'
     */
    fuzzyController_B.Merge_cf = fuzzyController_P.One_Value_o;

    /* End of Outputs for SubSystem: '<S10>/Action: One' */
  } else {
    /* Outputs for IfAction SubSystem: '<S10>/Action: u1' incorporates:
     *  ActionPort: '<S41>/Action Port'
     */
    fuzzyController_Actionu1(fuzzyController_B.Sum1_b,
      &fuzzyController_B.Merge_cf);

    /* End of Outputs for SubSystem: '<S10>/Action: u1' */
  }

  /* End of If: '<S10>/If' */

  /* Product: '<S10>/Averaging (COA)' */
  fuzzyController_B.AveragingCOA_f /= fuzzyController_B.Merge_cf;
  for (i = 0; i < 101; i++) {
    /* Sum: '<S4>/AggMethod5' */
    fuzzyController_B.Sum = ((((fuzzyController_B.impMethod_p[i + 101] +
      fuzzyController_B.impMethod_g[i + 303]) + fuzzyController_B.impMethod_f[i
      + 303]) + fuzzyController_B.impMethod_i[i + 101]) +
      fuzzyController_B.impMethod_l[i + 101]) + fuzzyController_B.impMethod_e[i
      + 303];

    /* Product: '<S11>/Product (COA)' incorporates:
     *  Constant: '<S11>/x data'
     */
    fuzzyController_B.impMethod_b[i] = fuzzyController_P.xdata_Value_f[i] *
      fuzzyController_B.Sum;

    /* Sum: '<S4>/AggMethod5' */
    fuzzyController_B.impMethod_m[i] = fuzzyController_B.Sum;
  }

  /* Sum: '<S11>/Sum' */
  fuzzyController_B.AveragingCOA_a = fuzzyController_B.impMethod_b[0];

  /* Sum: '<S11>/Sum1' */
  fuzzyController_B.Sum = fuzzyController_B.impMethod_m[0];
  for (i = 0; i < 100; i++) {
    /* Sum: '<S11>/Sum' */
    fuzzyController_B.AveragingCOA_a += fuzzyController_B.impMethod_b[i + 1];
    fuzzyController_B.Sum += fuzzyController_B.impMethod_m[i + 1];
  }

  fuzzyController_B.Sum1_a = fuzzyController_B.Sum;

  /* End of Sum: '<S11>/Sum1' */

  /* If: '<S11>/If' incorporates:
   *  Constant: '<S42>/One'
   */
  if (fuzzyController_B.Sum1_a <= 0.0) {
    /* Outputs for IfAction SubSystem: '<S11>/Action: One' incorporates:
     *  ActionPort: '<S42>/Action Port'
     */
    fuzzyController_B.Merge_kq = fuzzyController_P.One_Value_e;

    /* End of Outputs for SubSystem: '<S11>/Action: One' */
  } else {
    /* Outputs for IfAction SubSystem: '<S11>/Action: u1' incorporates:
     *  ActionPort: '<S43>/Action Port'
     */
    fuzzyController_Actionu1(fuzzyController_B.Sum1_a,
      &fuzzyController_B.Merge_kq);

    /* End of Outputs for SubSystem: '<S11>/Action: u1' */
  }

  /* End of If: '<S11>/If' */

  /* Product: '<S11>/Averaging (COA)' */
  fuzzyController_B.AveragingCOA_a /= fuzzyController_B.Merge_kq;

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/MidRange'
   *  Constant: '<S4>/Zero'
   *  Product: '<S7>/Averaging (COA)'
   *  RelationalOperator: '<S4>/Zero Firing Strength?'
   *  Sum: '<S4>/Total Firing Strength'
   */
  if (((((((((((((fuzzyController_B.Weighting + fuzzyController_B.Weighting_h) +
                 fuzzyController_B.Weighting_k) + fuzzyController_B.Weighting_i)
               + fuzzyController_B.Weighting_o) + fuzzyController_B.Weighting_l)
             + fuzzyController_B.Weighting_ae) +
            fuzzyController_B.ZeroFiringStrength) +
           fuzzyController_B.Weighting_c) + fuzzyController_B.Weighting_m5) +
         fuzzyController_B.Weighting_m) + fuzzyController_B.Weighting_oc) +
       fuzzyController_B.Weighting_a > fuzzyController_P.Zero_Value) >=
      fuzzyController_P.Switch_Threshold) {
    /* Product: '<S7>/Product (COA)' incorporates:
     *  Constant: '<S7>/x data'
     */
    for (i = 0; i < 101; i++) {
      fuzzyController_B.impMethod[i] *= fuzzyController_P.xdata_Value[i];
    }

    /* End of Product: '<S7>/Product (COA)' */

    /* Sum: '<S7>/Sum' */
    fuzzyController_B.Sum = fuzzyController_B.impMethod[0];
    for (i = 0; i < 100; i++) {
      fuzzyController_B.Sum += fuzzyController_B.impMethod[i + 1];
    }

    /* End of Sum: '<S7>/Sum' */
    fuzzyController_B.Switch[0] = fuzzyController_B.Sum / rtb_Merge_j;
    fuzzyController_B.Switch[1] = fuzzyController_B.AveragingCOA_l;
    fuzzyController_B.Switch[2] = fuzzyController_B.AveragingCOA_b;
    fuzzyController_B.Switch[3] = fuzzyController_B.AveragingCOA_f;
    fuzzyController_B.Switch[4] = fuzzyController_B.AveragingCOA_a;
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

  /* If: '<S44>/If' incorporates:
   *  Constant: '<S47>/0'
   *  Constant: '<S48>/0'
   *  Inport: '<Root>/frontDifferential'
   */
  if ((fuzzyController_U.frontDifferential < -2.0) ||
      (fuzzyController_U.frontDifferential > 0.0)) {
    /* Outputs for IfAction SubSystem: '<S44>/If Action Subsystem' incorporates:
     *  ActionPort: '<S47>/Action Port'
     */
    rtb_Merge_j2 = fuzzyController_P._Value;

    /* End of Outputs for SubSystem: '<S44>/If Action Subsystem' */
  } else if (fuzzyController_U.frontDifferential == -1.0) {
    /* Outputs for IfAction SubSystem: '<S44>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S48>/Action Port'
     */
    rtb_Merge_j2 = fuzzyController_P._Value_n;

    /* End of Outputs for SubSystem: '<S44>/If Action Subsystem1' */
  } else if (fuzzyController_U.frontDifferential < -1.0) {
    /* Outputs for IfAction SubSystem: '<S44>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S50>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.frontDifferential,
      &rtb_Merge_j2, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_n);

    /* End of Outputs for SubSystem: '<S44>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S44>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S49>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.frontDifferential,
      &rtb_Merge_j2, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_c0);

    /* End of Outputs for SubSystem: '<S44>/If Action Subsystem2' */
  }

  /* End of If: '<S44>/If' */

  /* If: '<S46>/If' incorporates:
   *  Constant: '<S55>/0'
   *  Constant: '<S56>/0'
   *  Inport: '<Root>/frontDifferential'
   */
  if ((fuzzyController_U.frontDifferential < -0.0) ||
      (fuzzyController_U.frontDifferential > 2.0)) {
    /* Outputs for IfAction SubSystem: '<S46>/If Action Subsystem' incorporates:
     *  ActionPort: '<S55>/Action Port'
     */
    rtb_Merge_kn = fuzzyController_P._Value_o;

    /* End of Outputs for SubSystem: '<S46>/If Action Subsystem' */
  } else if (fuzzyController_U.frontDifferential == 1.0) {
    /* Outputs for IfAction SubSystem: '<S46>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S56>/Action Port'
     */
    rtb_Merge_kn = fuzzyController_P._Value_m;

    /* End of Outputs for SubSystem: '<S46>/If Action Subsystem1' */
  } else if (fuzzyController_U.frontDifferential < 1.0) {
    /* Outputs for IfAction SubSystem: '<S46>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S58>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.frontDifferential,
      &rtb_Merge_kn, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_ng);

    /* End of Outputs for SubSystem: '<S46>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S46>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S57>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.frontDifferential,
      &rtb_Merge_kn, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_p0);

    /* End of Outputs for SubSystem: '<S46>/If Action Subsystem2' */
  }

  /* End of If: '<S46>/If' */

  /* If: '<S79>/If' incorporates:
   *  Constant: '<S82>/0'
   *  Constant: '<S83>/0'
   *  Inport: '<Root>/rearDifferential'
   */
  if ((fuzzyController_U.rearDifferential < -2.0) ||
      (fuzzyController_U.rearDifferential > 0.0)) {
    /* Outputs for IfAction SubSystem: '<S79>/If Action Subsystem' incorporates:
     *  ActionPort: '<S82>/Action Port'
     */
    rtb_Merge_ok = fuzzyController_P._Value_mg;

    /* End of Outputs for SubSystem: '<S79>/If Action Subsystem' */
  } else if (fuzzyController_U.rearDifferential == -1.0) {
    /* Outputs for IfAction SubSystem: '<S79>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S83>/Action Port'
     */
    rtb_Merge_ok = fuzzyController_P._Value_iq;

    /* End of Outputs for SubSystem: '<S79>/If Action Subsystem1' */
  } else if (fuzzyController_U.rearDifferential < -1.0) {
    /* Outputs for IfAction SubSystem: '<S79>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S85>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.rearDifferential,
      &rtb_Merge_ok, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_o);

    /* End of Outputs for SubSystem: '<S79>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S79>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S84>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.rearDifferential,
      &rtb_Merge_ok, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_l);

    /* End of Outputs for SubSystem: '<S79>/If Action Subsystem2' */
  }

  /* End of If: '<S79>/If' */

  /* If: '<S81>/If' incorporates:
   *  Constant: '<S90>/0'
   *  Constant: '<S91>/0'
   *  Inport: '<Root>/rearDifferential'
   */
  if ((fuzzyController_U.rearDifferential < 0.0) ||
      (fuzzyController_U.rearDifferential > 2.0)) {
    /* Outputs for IfAction SubSystem: '<S81>/If Action Subsystem' incorporates:
     *  ActionPort: '<S90>/Action Port'
     */
    rtb_Merge_cy = fuzzyController_P._Value_l;

    /* End of Outputs for SubSystem: '<S81>/If Action Subsystem' */
  } else if (fuzzyController_U.rearDifferential == 1.0) {
    /* Outputs for IfAction SubSystem: '<S81>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S91>/Action Port'
     */
    rtb_Merge_cy = fuzzyController_P._Value_in;

    /* End of Outputs for SubSystem: '<S81>/If Action Subsystem1' */
  } else if (fuzzyController_U.rearDifferential < 1.0) {
    /* Outputs for IfAction SubSystem: '<S81>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S93>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.rearDifferential,
      &rtb_Merge_cy, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_m);

    /* End of Outputs for SubSystem: '<S81>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S81>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S92>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.rearDifferential,
      &rtb_Merge_cy, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_m);

    /* End of Outputs for SubSystem: '<S81>/If Action Subsystem2' */
  }

  /* End of If: '<S81>/If' */

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
