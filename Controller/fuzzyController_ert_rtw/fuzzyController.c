/*
 * File: fuzzyController.c
 *
 * Code generated for Simulink model 'fuzzyController'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Mon Jul 21 19:59:36 2014
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
 *    '<S8>/Action: u1'
 *    '<S9>/Action: u1'
 *    '<S10>/Action: u1'
 *    '<S11>/Action: u1'
 *    '<S103>/Action: u1'
 */
void fuzzyController_Actionu1(real_T rtu_0, real_T *rty_u2)
{
  /* Inport: '<S29>/u1' */
  *rty_u2 = rtu_0;
}

/*
 * Output and update for action system:
 *    '<S36>/If Action Subsystem3'
 *    '<S37>/If Action Subsystem3'
 *    '<S38>/If Action Subsystem3'
 *    '<S51>/If Action Subsystem3'
 *    '<S52>/If Action Subsystem3'
 *    '<S61>/If Action Subsystem3'
 *    '<S62>/If Action Subsystem3'
 *    '<S63>/If Action Subsystem3'
 *    '<S76>/If Action Subsystem3'
 *    '<S77>/If Action Subsystem3'
 *    ...
 */
void fuzzyControl_IfActionSubsystem3(real_T rtu_x, real_T *rty_Out1,
  P_IfActionSubsystem3_fuzzyCon_T *localP)
{
  /* Product: '<S42>/Product ab (trimf)' incorporates:
   *  Constant: '<S42>/a'
   *  Constant: '<S42>/b'
   *  Sum: '<S42>/Sum'
   *  Sum: '<S42>/Sum1'
   */
  *rty_Out1 = (rtu_x - localP->a_Value) / (localP->b_Value - localP->a_Value);
}

/*
 * Output and update for action system:
 *    '<S36>/If Action Subsystem2'
 *    '<S37>/If Action Subsystem2'
 *    '<S38>/If Action Subsystem2'
 *    '<S51>/If Action Subsystem2'
 *    '<S52>/If Action Subsystem2'
 *    '<S61>/If Action Subsystem2'
 *    '<S62>/If Action Subsystem2'
 *    '<S63>/If Action Subsystem2'
 *    '<S76>/If Action Subsystem2'
 *    '<S77>/If Action Subsystem2'
 *    ...
 */
void fuzzyControl_IfActionSubsystem2(real_T rtu_x, real_T *rty_Out1,
  P_IfActionSubsystem2_fuzzyCon_T *localP)
{
  /* Product: '<S41>/Product cd (trimf)' incorporates:
   *  Constant: '<S41>/b'
   *  Constant: '<S41>/c'
   *  Sum: '<S41>/Sum2'
   *  Sum: '<S41>/Sum3'
   */
  *rty_Out1 = 1.0 / (localP->c_Value - localP->b_Value) * (localP->c_Value -
    rtu_x);
}

/* Model step function */
void fuzzyController_step(void)
{
  /* local block i/o variables */
  real_T rtb_Merge_ch;
  real_T rtb_Merge_ic;
  real_T rtb_Merge_cf;
  real_T rtb_Merge_j2;
  real_T rtb_Merge_kn;
  real_T rtb_Merge_ok;
  real_T rtb_Merge_cy;
  int32_T i;

  /* If: '<S123>/If' incorporates:
   *  Constant: '<S125>/0'
   *  Constant: '<S126>/0'
   *  Inport: '<Root>/steeringSignal'
   */
  if ((fuzzyController_U.steeringSignal < -3.0) ||
      (fuzzyController_U.steeringSignal > 1.0)) {
    /* Outputs for IfAction SubSystem: '<S123>/If Action Subsystem' incorporates:
     *  ActionPort: '<S125>/Action Port'
     */
    fuzzyController_B.Merge = fuzzyController_P._Value_ho;

    /* End of Outputs for SubSystem: '<S123>/If Action Subsystem' */
  } else if (fuzzyController_U.steeringSignal == -1.0) {
    /* Outputs for IfAction SubSystem: '<S123>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S126>/Action Port'
     */
    fuzzyController_B.Merge = fuzzyController_P._Value_g;

    /* End of Outputs for SubSystem: '<S123>/If Action Subsystem1' */
  } else if (fuzzyController_U.steeringSignal < -1.0) {
    /* Outputs for IfAction SubSystem: '<S123>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S128>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.steeringSignal,
      &fuzzyController_B.Merge, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S123>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S123>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S127>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.steeringSignal,
      &fuzzyController_B.Merge, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S123>/If Action Subsystem2' */
  }

  /* End of If: '<S123>/If' */

  /* Product: '<S104>/Weighting' incorporates:
   *  Constant: '<S104>/Weight'
   *  Product: '<S104>/andorMethod'
   */
  fuzzyController_B.Weighting_a = fuzzyController_P.Weight_Value *
    fuzzyController_B.Merge;

  /* Product: '<S104>/impMethod' incorporates:
   *  Constant: '<S109>/left'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod[i] = fuzzyController_B.Weighting_a *
      fuzzyController_P.left_Value[i];
  }

  /* End of Product: '<S104>/impMethod' */

  /* If: '<S124>/If' incorporates:
   *  Constant: '<S129>/0'
   *  Constant: '<S130>/0'
   *  Inport: '<Root>/steeringSignal'
   */
  if ((fuzzyController_U.steeringSignal < -1.0) ||
      (fuzzyController_U.steeringSignal > 3.0)) {
    /* Outputs for IfAction SubSystem: '<S124>/If Action Subsystem' incorporates:
     *  ActionPort: '<S129>/Action Port'
     */
    fuzzyController_B.Merge_b = fuzzyController_P._Value_pu;

    /* End of Outputs for SubSystem: '<S124>/If Action Subsystem' */
  } else if (fuzzyController_U.steeringSignal == 1.0) {
    /* Outputs for IfAction SubSystem: '<S124>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S130>/Action Port'
     */
    fuzzyController_B.Merge_b = fuzzyController_P._Value_hv;

    /* End of Outputs for SubSystem: '<S124>/If Action Subsystem1' */
  } else if (fuzzyController_U.steeringSignal < 1.0) {
    /* Outputs for IfAction SubSystem: '<S124>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S132>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.steeringSignal,
      &fuzzyController_B.Merge_b, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_c);

    /* End of Outputs for SubSystem: '<S124>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S124>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S131>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.steeringSignal,
      &fuzzyController_B.Merge_b, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_j);

    /* End of Outputs for SubSystem: '<S124>/If Action Subsystem2' */
  }

  /* End of If: '<S124>/If' */

  /* Product: '<S105>/Weighting' incorporates:
   *  Constant: '<S105>/Weight'
   *  Product: '<S105>/andorMethod'
   */
  fuzzyController_B.Weighting_i = fuzzyController_P.Weight_Value_l *
    fuzzyController_B.Merge_b;

  /* Product: '<S105>/impMethod' incorporates:
   *  Constant: '<S109>/right'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_a[i] = fuzzyController_B.Weighting_i *
      fuzzyController_P.right_Value[i];
  }

  /* End of Product: '<S105>/impMethod' */

  /* Saturate: '<S1>/Saturation' incorporates:
   *  Inport: '<Root>/gyroGain'
   */
  if (fuzzyController_U.gyroGain >= fuzzyController_P.Saturation_UpperSat) {
    fuzzyController_B.d0 = fuzzyController_P.Saturation_UpperSat;
  } else if (fuzzyController_U.gyroGain <= fuzzyController_P.Saturation_LowerSat)
  {
    fuzzyController_B.d0 = fuzzyController_P.Saturation_LowerSat;
  } else {
    fuzzyController_B.d0 = fuzzyController_U.gyroGain;
  }

  /* Product: '<S1>/Product' incorporates:
   *  Inport: '<Root>/gyroYaw'
   *  Saturate: '<S1>/Saturation'
   */
  fuzzyController_B.Product = fuzzyController_U.gyroYaw * fuzzyController_B.d0;

  /* If: '<S114>/If' incorporates:
   *  Constant: '<S119>/0'
   *  Constant: '<S120>/0'
   */
  if ((fuzzyController_B.Product < -2.0) || (fuzzyController_B.Product > 0.0)) {
    /* Outputs for IfAction SubSystem: '<S114>/If Action Subsystem' incorporates:
     *  ActionPort: '<S119>/Action Port'
     */
    fuzzyController_B.Merge_k = fuzzyController_P._Value_i1;

    /* End of Outputs for SubSystem: '<S114>/If Action Subsystem' */
  } else if (fuzzyController_B.Product == -1.0) {
    /* Outputs for IfAction SubSystem: '<S114>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S120>/Action Port'
     */
    fuzzyController_B.Merge_k = fuzzyController_P._Value_l5;

    /* End of Outputs for SubSystem: '<S114>/If Action Subsystem1' */
  } else if (fuzzyController_B.Product < -1.0) {
    /* Outputs for IfAction SubSystem: '<S114>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S122>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_B.Product,
      &fuzzyController_B.Merge_k, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_k);

    /* End of Outputs for SubSystem: '<S114>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S114>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S121>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_B.Product,
      &fuzzyController_B.Merge_k, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_o);

    /* End of Outputs for SubSystem: '<S114>/If Action Subsystem2' */
  }

  /* End of If: '<S114>/If' */

  /* Product: '<S106>/Weighting' incorporates:
   *  Constant: '<S106>/Weight'
   *  Product: '<S106>/andorMethod'
   */
  fuzzyController_B.Weighting_k = fuzzyController_B.Merge_k *
    fuzzyController_B.Merge * fuzzyController_P.Weight_Value_f;

  /* Product: '<S106>/impMethod' incorporates:
   *  Constant: '<S109>/left'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_k[i] = fuzzyController_B.Weighting_k *
      fuzzyController_P.left_Value[i];
  }

  /* End of Product: '<S106>/impMethod' */

  /* If: '<S113>/If' incorporates:
   *  Constant: '<S115>/0'
   *  Constant: '<S116>/0'
   */
  if ((fuzzyController_B.Product < 0.0) || (fuzzyController_B.Product > 2.0)) {
    /* Outputs for IfAction SubSystem: '<S113>/If Action Subsystem' incorporates:
     *  ActionPort: '<S115>/Action Port'
     */
    fuzzyController_B.Merge_bs = fuzzyController_P._Value_ll;

    /* End of Outputs for SubSystem: '<S113>/If Action Subsystem' */
  } else if (fuzzyController_B.Product == 1.0) {
    /* Outputs for IfAction SubSystem: '<S113>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S116>/Action Port'
     */
    fuzzyController_B.Merge_bs = fuzzyController_P._Value_fz;

    /* End of Outputs for SubSystem: '<S113>/If Action Subsystem1' */
  } else if (fuzzyController_B.Product < 1.0) {
    /* Outputs for IfAction SubSystem: '<S113>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S118>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_B.Product,
      &fuzzyController_B.Merge_bs, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_b);

    /* End of Outputs for SubSystem: '<S113>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S113>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S117>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_B.Product,
      &fuzzyController_B.Merge_bs, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_e);

    /* End of Outputs for SubSystem: '<S113>/If Action Subsystem2' */
  }

  /* End of If: '<S113>/If' */

  /* Product: '<S107>/Weighting' incorporates:
   *  Constant: '<S107>/Weight'
   *  Product: '<S107>/andorMethod'
   */
  fuzzyController_B.Weighting_h = fuzzyController_B.Merge_bs *
    fuzzyController_B.Merge_b * fuzzyController_P.Weight_Value_a;

  /* Sum: '<S102>/AggMethod1' incorporates:
   *  Constant: '<S109>/right'
   *  Product: '<S107>/impMethod'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod[i] = ((fuzzyController_B.impMethod[i] +
      fuzzyController_B.impMethod_a[i]) + fuzzyController_B.impMethod_k[i]) +
      fuzzyController_B.Weighting_h * fuzzyController_P.right_Value[i];
  }

  /* End of Sum: '<S102>/AggMethod1' */

  /* Sum: '<S103>/Sum1' */
  fuzzyController_B.d0 = fuzzyController_B.impMethod[0];
  for (i = 0; i < 100; i++) {
    fuzzyController_B.d0 += fuzzyController_B.impMethod[i + 1];
  }

  fuzzyController_B.Sum1 = fuzzyController_B.d0;

  /* End of Sum: '<S103>/Sum1' */

  /* If: '<S103>/If' incorporates:
   *  Constant: '<S111>/One'
   */
  if (fuzzyController_B.Sum1 <= 0.0) {
    /* Outputs for IfAction SubSystem: '<S103>/Action: One' incorporates:
     *  ActionPort: '<S111>/Action Port'
     */
    fuzzyController_B.Merge_c = fuzzyController_P.One_Value_l;

    /* End of Outputs for SubSystem: '<S103>/Action: One' */
  } else {
    /* Outputs for IfAction SubSystem: '<S103>/Action: u1' incorporates:
     *  ActionPort: '<S112>/Action Port'
     */
    fuzzyController_Actionu1(fuzzyController_B.Sum1, &fuzzyController_B.Merge_c);

    /* End of Outputs for SubSystem: '<S103>/Action: u1' */
  }

  /* End of If: '<S103>/If' */

  /* Switch: '<S102>/Switch' incorporates:
   *  Constant: '<S102>/MidRange'
   *  Constant: '<S102>/Zero'
   *  Product: '<S103>/Averaging (COA)'
   *  RelationalOperator: '<S102>/Zero Firing Strength?'
   *  Sum: '<S102>/Total Firing Strength'
   */
  if ((((fuzzyController_B.Weighting_a + fuzzyController_B.Weighting_i) +
        fuzzyController_B.Weighting_k) + fuzzyController_B.Weighting_h >
       fuzzyController_P.Zero_Value) >= fuzzyController_P.Switch_Threshold) {
    /* Product: '<S103>/Product (COA)' incorporates:
     *  Constant: '<S103>/x data'
     */
    for (i = 0; i < 101; i++) {
      fuzzyController_B.impMethod[i] *= fuzzyController_P.xdata_Value[i];
    }

    /* End of Product: '<S103>/Product (COA)' */

    /* Sum: '<S103>/Sum' */
    fuzzyController_B.Weighting_i = fuzzyController_B.impMethod[0];
    for (i = 0; i < 100; i++) {
      fuzzyController_B.Weighting_i += fuzzyController_B.impMethod[i + 1];
    }

    /* End of Sum: '<S103>/Sum' */
    fuzzyController_B.Switch = fuzzyController_B.Weighting_i /
      fuzzyController_B.Merge_c;
  } else {
    fuzzyController_B.Switch = fuzzyController_P.MidRange_Value;
  }

  /* End of Switch: '<S102>/Switch' */

  /* Outport: '<Root>/steeringOutput' */
  fuzzyController_Y.steeringOutput = fuzzyController_B.Switch;

  /* If: '<S51>/If' incorporates:
   *  Constant: '<S53>/0'
   *  Constant: '<S54>/0'
   *  Inport: '<Root>/powerBias'
   */
  if ((fuzzyController_U.powerBias < -0.0) || (fuzzyController_U.powerBias > 2.0))
  {
    /* Outputs for IfAction SubSystem: '<S51>/If Action Subsystem' incorporates:
     *  ActionPort: '<S53>/Action Port'
     */
    fuzzyController_B.Merge_m = fuzzyController_P._Value_e;

    /* End of Outputs for SubSystem: '<S51>/If Action Subsystem' */
  } else if (fuzzyController_U.powerBias == 1.0) {
    /* Outputs for IfAction SubSystem: '<S51>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S54>/Action Port'
     */
    fuzzyController_B.Merge_m = fuzzyController_P._Value_p;

    /* End of Outputs for SubSystem: '<S51>/If Action Subsystem1' */
  } else if (fuzzyController_U.powerBias < 1.0) {
    /* Outputs for IfAction SubSystem: '<S51>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S56>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.powerBias,
      &fuzzyController_B.Merge_m, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_d);

    /* End of Outputs for SubSystem: '<S51>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S51>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S55>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.powerBias,
      &fuzzyController_B.Merge_m, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_b);

    /* End of Outputs for SubSystem: '<S51>/If Action Subsystem2' */
  }

  /* End of If: '<S51>/If' */

  /* Product: '<S15>/Weighting' incorporates:
   *  Constant: '<S15>/Weight'
   *  Product: '<S15>/andorMethod'
   */
  fuzzyController_B.Weighting_h = fuzzyController_P.Weight_Value_b *
    fuzzyController_B.Merge_m;

  /* Product: '<S15>/impMethod' incorporates:
   *  Constant: '<S12>/neutral'
   *  Constant: '<S13>/neutral'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_f1[i] = fuzzyController_B.Weighting_h *
      fuzzyController_P.neutral_Value[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_f1[i + 101] = fuzzyController_B.Weighting_h *
      fuzzyController_P.neutral_Value_h[i];
  }

  /* End of Product: '<S15>/impMethod' */

  /* If: '<S87>/If' incorporates:
   *  Constant: '<S93>/0'
   *  Constant: '<S94>/0'
   *  Inport: '<Root>/throttleSignal'
   */
  if ((fuzzyController_U.throttleSignal < -1.0) ||
      (fuzzyController_U.throttleSignal > 1.0)) {
    /* Outputs for IfAction SubSystem: '<S87>/If Action Subsystem' incorporates:
     *  ActionPort: '<S93>/Action Port'
     */
    fuzzyController_B.Merge_k4 = fuzzyController_P._Value_af;

    /* End of Outputs for SubSystem: '<S87>/If Action Subsystem' */
  } else if (fuzzyController_U.throttleSignal == 0.0) {
    /* Outputs for IfAction SubSystem: '<S87>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S94>/Action Port'
     */
    fuzzyController_B.Merge_k4 = fuzzyController_P._Value_b;

    /* End of Outputs for SubSystem: '<S87>/If Action Subsystem1' */
  } else if (fuzzyController_U.throttleSignal < 0.0) {
    /* Outputs for IfAction SubSystem: '<S87>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S96>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.throttleSignal,
      &fuzzyController_B.Merge_k4, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_co);

    /* End of Outputs for SubSystem: '<S87>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S87>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S95>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.throttleSignal,
      &fuzzyController_B.Merge_k4, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_f);

    /* End of Outputs for SubSystem: '<S87>/If Action Subsystem2' */
  }

  /* End of If: '<S87>/If' */

  /* Product: '<S16>/Weighting' incorporates:
   *  Constant: '<S16>/Weight'
   *  Product: '<S16>/andorMethod'
   */
  fuzzyController_B.Weighting_k = fuzzyController_P.Weight_Value_h *
    fuzzyController_B.Merge_k4;

  /* Product: '<S16>/impMethod' incorporates:
   *  Constant: '<S12>/neutral'
   *  Constant: '<S13>/neutral'
   *  Constant: '<S6>/neutral'
   *  Constant: '<S7>/neutral'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_p[i] = fuzzyController_B.Weighting_k *
      fuzzyController_P.neutral_Value[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_p[i + 101] = fuzzyController_B.Weighting_k *
      fuzzyController_P.neutral_Value_h[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_p[i + 202] = fuzzyController_B.Weighting_k *
      fuzzyController_P.neutral_Value_he[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_p[i + 303] = fuzzyController_B.Weighting_k *
      fuzzyController_P.neutral_Value_hb[i];
  }

  /* End of Product: '<S16>/impMethod' */

  /* If: '<S88>/If' incorporates:
   *  Constant: '<S97>/0'
   *  Constant: '<S98>/0'
   *  Inport: '<Root>/throttleSignal'
   */
  if ((fuzzyController_U.throttleSignal < -2.0) ||
      (fuzzyController_U.throttleSignal > 0.0)) {
    /* Outputs for IfAction SubSystem: '<S88>/If Action Subsystem' incorporates:
     *  ActionPort: '<S97>/Action Port'
     */
    fuzzyController_B.Merge_j = fuzzyController_P._Value_i3;

    /* End of Outputs for SubSystem: '<S88>/If Action Subsystem' */
  } else if (fuzzyController_U.throttleSignal == -1.0) {
    /* Outputs for IfAction SubSystem: '<S88>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S98>/Action Port'
     */
    fuzzyController_B.Merge_j = fuzzyController_P._Value_f;

    /* End of Outputs for SubSystem: '<S88>/If Action Subsystem1' */
  } else if (fuzzyController_U.throttleSignal < -1.0) {
    /* Outputs for IfAction SubSystem: '<S88>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S100>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.throttleSignal,
      &fuzzyController_B.Merge_j, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_l);

    /* End of Outputs for SubSystem: '<S88>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S88>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S99>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.throttleSignal,
      &fuzzyController_B.Merge_j, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_c);

    /* End of Outputs for SubSystem: '<S88>/If Action Subsystem2' */
  }

  /* End of If: '<S88>/If' */

  /* Product: '<S17>/Weighting' incorporates:
   *  Constant: '<S17>/Weight'
   *  Product: '<S17>/andorMethod'
   */
  fuzzyController_B.Weighting_i = fuzzyController_P.Weight_Value_hu *
    fuzzyController_B.Merge_j;

  /* Product: '<S17>/impMethod' incorporates:
   *  Constant: '<S12>/reverse'
   *  Constant: '<S13>/reverse'
   *  Constant: '<S6>/reverse'
   *  Constant: '<S7>/reverse'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_c[i] = fuzzyController_B.Weighting_i *
      fuzzyController_P.reverse_Value[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_c[i + 101] = fuzzyController_B.Weighting_i *
      fuzzyController_P.reverse_Value_b[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_c[i + 202] = fuzzyController_B.Weighting_i *
      fuzzyController_P.reverse_Value_c[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_c[i + 303] = fuzzyController_B.Weighting_i *
      fuzzyController_P.reverse_Value_n[i];
  }

  /* End of Product: '<S17>/impMethod' */

  /* If: '<S37>/If' incorporates:
   *  Constant: '<S43>/0'
   *  Constant: '<S44>/0'
   *  Inport: '<Root>/frontDifferential'
   */
  if ((fuzzyController_U.frontDifferential < -1.0) ||
      (fuzzyController_U.frontDifferential > 1.0)) {
    /* Outputs for IfAction SubSystem: '<S37>/If Action Subsystem' incorporates:
     *  ActionPort: '<S43>/Action Port'
     */
    fuzzyController_B.Merge_g = fuzzyController_P._Value_i;

    /* End of Outputs for SubSystem: '<S37>/If Action Subsystem' */
  } else if (fuzzyController_U.frontDifferential == 0.0) {
    /* Outputs for IfAction SubSystem: '<S37>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S44>/Action Port'
     */
    fuzzyController_B.Merge_g = fuzzyController_P._Value_h;

    /* End of Outputs for SubSystem: '<S37>/If Action Subsystem1' */
  } else if (fuzzyController_U.frontDifferential < 0.0) {
    /* Outputs for IfAction SubSystem: '<S37>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S46>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.frontDifferential,
      &fuzzyController_B.Merge_g, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_a);

    /* End of Outputs for SubSystem: '<S37>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S37>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S45>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.frontDifferential,
      &fuzzyController_B.Merge_g, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_d);

    /* End of Outputs for SubSystem: '<S37>/If Action Subsystem2' */
  }

  /* End of If: '<S37>/If' */

  /* If: '<S76>/If' incorporates:
   *  Constant: '<S78>/0'
   *  Constant: '<S79>/0'
   */
  if ((fuzzyController_B.Switch < -2.0) || (fuzzyController_B.Switch > 0.0)) {
    /* Outputs for IfAction SubSystem: '<S76>/If Action Subsystem' incorporates:
     *  ActionPort: '<S78>/Action Port'
     */
    fuzzyController_B.Merge_my = fuzzyController_P._Value_pq;

    /* End of Outputs for SubSystem: '<S76>/If Action Subsystem' */
  } else if (fuzzyController_B.Switch == -1.0) {
    /* Outputs for IfAction SubSystem: '<S76>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S79>/Action Port'
     */
    fuzzyController_B.Merge_my = fuzzyController_P._Value_a;

    /* End of Outputs for SubSystem: '<S76>/If Action Subsystem1' */
  } else if (fuzzyController_B.Switch < -1.0) {
    /* Outputs for IfAction SubSystem: '<S76>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S81>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_B.Switch,
      &fuzzyController_B.Merge_my, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_p);

    /* End of Outputs for SubSystem: '<S76>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S76>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S80>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_B.Switch,
      &fuzzyController_B.Merge_my, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_p);

    /* End of Outputs for SubSystem: '<S76>/If Action Subsystem2' */
  }

  /* End of If: '<S76>/If' */

  /* If: '<S86>/If' incorporates:
   *  Constant: '<S89>/0'
   *  Constant: '<S90>/0'
   *  Inport: '<Root>/throttleSignal'
   */
  if ((fuzzyController_U.throttleSignal < -0.0) ||
      (fuzzyController_U.throttleSignal > 2.0)) {
    /* Outputs for IfAction SubSystem: '<S86>/If Action Subsystem' incorporates:
     *  ActionPort: '<S89>/Action Port'
     */
    fuzzyController_B.Merge_o = fuzzyController_P._Value_aj;

    /* End of Outputs for SubSystem: '<S86>/If Action Subsystem' */
  } else if (fuzzyController_U.throttleSignal == 1.0) {
    /* Outputs for IfAction SubSystem: '<S86>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S90>/Action Port'
     */
    fuzzyController_B.Merge_o = fuzzyController_P._Value_ju;

    /* End of Outputs for SubSystem: '<S86>/If Action Subsystem1' */
  } else if (fuzzyController_U.throttleSignal < 1.0) {
    /* Outputs for IfAction SubSystem: '<S86>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S92>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.throttleSignal,
      &fuzzyController_B.Merge_o, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_g);

    /* End of Outputs for SubSystem: '<S86>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S86>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S91>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.throttleSignal,
      &fuzzyController_B.Merge_o, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_pl);

    /* End of Outputs for SubSystem: '<S86>/If Action Subsystem2' */
  }

  /* End of If: '<S86>/If' */

  /* Product: '<S20>/Weighting' incorporates:
   *  Constant: '<S20>/Weight'
   *  Product: '<S20>/andorMethod'
   */
  fuzzyController_B.Weighting_a = fuzzyController_B.Merge_my *
    fuzzyController_B.Merge_o * fuzzyController_B.Merge_g *
    fuzzyController_P.Weight_Value_bt;

  /* Product: '<S20>/impMethod' incorporates:
   *  Constant: '<S12>/neutral'
   *  Constant: '<S13>/forward'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_g[i] = fuzzyController_B.Weighting_a *
      fuzzyController_P.neutral_Value[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_g[i + 101] = fuzzyController_B.Weighting_a *
      fuzzyController_P.forward_Value[i];
  }

  /* End of Product: '<S20>/impMethod' */

  /* If: '<S77>/If' incorporates:
   *  Constant: '<S82>/0'
   *  Constant: '<S83>/0'
   */
  if ((fuzzyController_B.Switch < -0.0) || (fuzzyController_B.Switch > 2.0)) {
    /* Outputs for IfAction SubSystem: '<S77>/If Action Subsystem' incorporates:
     *  ActionPort: '<S82>/Action Port'
     */
    fuzzyController_B.Merge_h = fuzzyController_P._Value_n4;

    /* End of Outputs for SubSystem: '<S77>/If Action Subsystem' */
  } else if (fuzzyController_B.Switch == 1.0) {
    /* Outputs for IfAction SubSystem: '<S77>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S83>/Action Port'
     */
    fuzzyController_B.Merge_h = fuzzyController_P._Value_py;

    /* End of Outputs for SubSystem: '<S77>/If Action Subsystem1' */
  } else if (fuzzyController_B.Switch < 1.0) {
    /* Outputs for IfAction SubSystem: '<S77>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S85>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_B.Switch,
      &fuzzyController_B.Merge_h, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_db);

    /* End of Outputs for SubSystem: '<S77>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S77>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S84>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_B.Switch,
      &fuzzyController_B.Merge_h, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_g);

    /* End of Outputs for SubSystem: '<S77>/If Action Subsystem2' */
  }

  /* End of If: '<S77>/If' */

  /* Product: '<S21>/Weighting' incorporates:
   *  Constant: '<S21>/Weight'
   *  Product: '<S21>/andorMethod'
   */
  fuzzyController_B.Weighting = fuzzyController_B.Merge_h *
    fuzzyController_B.Merge_o * fuzzyController_B.Merge_g *
    fuzzyController_P.Weight_Value_fj;

  /* Product: '<S21>/impMethod' incorporates:
   *  Constant: '<S12>/forward'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_j[i] = fuzzyController_B.Weighting *
      fuzzyController_P.forward_Value_a[i];
  }

  /* Product: '<S22>/Weighting' incorporates:
   *  Constant: '<S22>/Weight'
   *  Product: '<S22>/andorMethod'
   */
  fuzzyController_B.Weighting_c = fuzzyController_P.Weight_Value_o *
    fuzzyController_B.Merge_o;
  for (i = 0; i < 101; i++) {
    /* Product: '<S21>/impMethod' incorporates:
     *  Constant: '<S13>/neutral'
     */
    fuzzyController_B.impMethod_j[i + 101] = fuzzyController_B.Weighting *
      fuzzyController_P.neutral_Value_h[i];

    /* Product: '<S22>/impMethod' incorporates:
     *  Constant: '<S12>/forward'
     */
    fuzzyController_B.impMethod_pd[i] = fuzzyController_B.Weighting_c *
      fuzzyController_P.forward_Value_a[i];
  }

  /* Product: '<S22>/impMethod' incorporates:
   *  Constant: '<S13>/forward'
   *  Constant: '<S6>/forward'
   *  Constant: '<S7>/forward'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_pd[i + 101] = fuzzyController_B.Weighting_c *
      fuzzyController_P.forward_Value[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_pd[i + 202] = fuzzyController_B.Weighting_c *
      fuzzyController_P.forward_Value_e[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_pd[i + 303] = fuzzyController_B.Weighting_c *
      fuzzyController_P.forward_Value_c[i];
  }

  /* Sum: '<S5>/AggMethod1' */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod[i] = ((((fuzzyController_B.impMethod_f1[i] +
      fuzzyController_B.impMethod_p[i]) + fuzzyController_B.impMethod_c[i]) +
      fuzzyController_B.impMethod_g[i]) + fuzzyController_B.impMethod_j[i]) +
      fuzzyController_B.impMethod_pd[i];
  }

  /* End of Sum: '<S5>/AggMethod1' */

  /* Sum: '<S8>/Sum1' */
  fuzzyController_B.d0 = fuzzyController_B.impMethod[0];
  for (i = 0; i < 100; i++) {
    fuzzyController_B.d0 += fuzzyController_B.impMethod[i + 1];
  }

  fuzzyController_B.Sum1_f = fuzzyController_B.d0;

  /* End of Sum: '<S8>/Sum1' */

  /* If: '<S8>/If' incorporates:
   *  Constant: '<S28>/One'
   */
  if (fuzzyController_B.Sum1_f <= 0.0) {
    /* Outputs for IfAction SubSystem: '<S8>/Action: One' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    fuzzyController_B.Merge_jp = fuzzyController_P.One_Value;

    /* End of Outputs for SubSystem: '<S8>/Action: One' */
  } else {
    /* Outputs for IfAction SubSystem: '<S8>/Action: u1' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    fuzzyController_Actionu1(fuzzyController_B.Sum1_f,
      &fuzzyController_B.Merge_jp);

    /* End of Outputs for SubSystem: '<S8>/Action: u1' */
  }

  /* End of If: '<S8>/If' */

  /* Sum: '<S5>/AggMethod2' */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_a[i] = ((((fuzzyController_B.impMethod_f1[i +
      101] + fuzzyController_B.impMethod_p[i + 101]) +
      fuzzyController_B.impMethod_c[i + 101]) + fuzzyController_B.impMethod_g[i
      + 101]) + fuzzyController_B.impMethod_j[i + 101]) +
      fuzzyController_B.impMethod_pd[i + 101];
  }

  /* End of Sum: '<S5>/AggMethod2' */

  /* Sum: '<S9>/Sum1' */
  fuzzyController_B.d0 = fuzzyController_B.impMethod_a[0];
  for (i = 0; i < 100; i++) {
    fuzzyController_B.d0 += fuzzyController_B.impMethod_a[i + 1];
  }

  fuzzyController_B.Sum1_l = fuzzyController_B.d0;

  /* End of Sum: '<S9>/Sum1' */

  /* If: '<S9>/If' incorporates:
   *  Constant: '<S30>/One'
   */
  if (fuzzyController_B.Sum1_l <= 0.0) {
    /* Outputs for IfAction SubSystem: '<S9>/Action: One' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    fuzzyController_B.Merge_i = fuzzyController_P.One_Value_n;

    /* End of Outputs for SubSystem: '<S9>/Action: One' */
  } else {
    /* Outputs for IfAction SubSystem: '<S9>/Action: u1' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    fuzzyController_Actionu1(fuzzyController_B.Sum1_l,
      &fuzzyController_B.Merge_i);

    /* End of Outputs for SubSystem: '<S9>/Action: u1' */
  }

  /* End of If: '<S9>/If' */

  /* If: '<S52>/If' incorporates:
   *  Constant: '<S57>/0'
   *  Constant: '<S58>/0'
   *  Inport: '<Root>/powerBias'
   */
  if ((fuzzyController_U.powerBias < -2.0) || (fuzzyController_U.powerBias >
       -0.0)) {
    /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem' incorporates:
     *  ActionPort: '<S57>/Action Port'
     */
    fuzzyController_B.Merge_n = fuzzyController_P._Value_j;

    /* End of Outputs for SubSystem: '<S52>/If Action Subsystem' */
  } else if (fuzzyController_U.powerBias == -1.0) {
    /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S58>/Action Port'
     */
    fuzzyController_B.Merge_n = fuzzyController_P._Value_mx;

    /* End of Outputs for SubSystem: '<S52>/If Action Subsystem1' */
  } else if (fuzzyController_U.powerBias < -1.0) {
    /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S60>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.powerBias,
      &fuzzyController_B.Merge_n, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_f);

    /* End of Outputs for SubSystem: '<S52>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S59>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.powerBias,
      &fuzzyController_B.Merge_n, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_ga);

    /* End of Outputs for SubSystem: '<S52>/If Action Subsystem2' */
  }

  /* End of If: '<S52>/If' */

  /* Product: '<S14>/Weighting' incorporates:
   *  Constant: '<S14>/Weight'
   *  Product: '<S14>/andorMethod'
   */
  fuzzyController_B.Weighting_e = fuzzyController_P.Weight_Value_k *
    fuzzyController_B.Merge_n;

  /* Product: '<S14>/impMethod' incorporates:
   *  Constant: '<S6>/neutral'
   *  Constant: '<S7>/neutral'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_j[i] = fuzzyController_B.Weighting_e *
      fuzzyController_P.neutral_Value_he[i];
  }

  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_j[i + 101] = fuzzyController_B.Weighting_e *
      fuzzyController_P.neutral_Value_hb[i];
  }

  /* End of Product: '<S14>/impMethod' */

  /* If: '<S62>/If' incorporates:
   *  Constant: '<S68>/0'
   *  Constant: '<S69>/0'
   *  Inport: '<Root>/rearDifferential'
   */
  if ((fuzzyController_U.rearDifferential < -1.0) ||
      (fuzzyController_U.rearDifferential > 1.0)) {
    /* Outputs for IfAction SubSystem: '<S62>/If Action Subsystem' incorporates:
     *  ActionPort: '<S68>/Action Port'
     */
    rtb_Merge_ch = fuzzyController_P._Value_d;

    /* End of Outputs for SubSystem: '<S62>/If Action Subsystem' */
  } else if (fuzzyController_U.rearDifferential == 0.0) {
    /* Outputs for IfAction SubSystem: '<S62>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S69>/Action Port'
     */
    rtb_Merge_ch = fuzzyController_P._Value_no;

    /* End of Outputs for SubSystem: '<S62>/If Action Subsystem1' */
  } else if (fuzzyController_U.rearDifferential < 0.0) {
    /* Outputs for IfAction SubSystem: '<S62>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S71>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.rearDifferential,
      &rtb_Merge_ch, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_i);

    /* End of Outputs for SubSystem: '<S62>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S62>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S70>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.rearDifferential,
      &rtb_Merge_ch, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_a);

    /* End of Outputs for SubSystem: '<S62>/If Action Subsystem2' */
  }

  /* End of If: '<S62>/If' */

  /* Product: '<S18>/Weighting' incorporates:
   *  Constant: '<S18>/Weight'
   *  Product: '<S18>/andorMethod'
   */
  fuzzyController_B.Weighting_o = fuzzyController_B.Merge_my *
    fuzzyController_B.Merge_o * rtb_Merge_ch * fuzzyController_P.Weight_Value_g;

  /* Product: '<S18>/impMethod' incorporates:
   *  Constant: '<S6>/neutral'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_g[i] = fuzzyController_B.Weighting_o *
      fuzzyController_P.neutral_Value_he[i];
  }

  /* Product: '<S19>/Weighting' incorporates:
   *  Constant: '<S19>/Weight'
   *  Product: '<S19>/andorMethod'
   */
  fuzzyController_B.ZeroFiringStrength_n = fuzzyController_B.Merge_h *
    fuzzyController_B.Merge_o * rtb_Merge_ch * fuzzyController_P.Weight_Value_j;
  for (i = 0; i < 101; i++) {
    /* Product: '<S18>/impMethod' incorporates:
     *  Constant: '<S7>/forward'
     */
    fuzzyController_B.impMethod_g[i + 101] = fuzzyController_B.Weighting_o *
      fuzzyController_P.forward_Value_c[i];

    /* Product: '<S19>/impMethod' incorporates:
     *  Constant: '<S6>/forward'
     */
    fuzzyController_B.impMethod_f1[i] = fuzzyController_B.ZeroFiringStrength_n *
      fuzzyController_P.forward_Value_e[i];
  }

  /* Product: '<S19>/impMethod' incorporates:
   *  Constant: '<S7>/neutral'
   */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_f1[i + 101] =
      fuzzyController_B.ZeroFiringStrength_n *
      fuzzyController_P.neutral_Value_hb[i];
  }

  /* Sum: '<S5>/AggMethod3' */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.impMethod_k[i] = ((((fuzzyController_B.impMethod_p[i + 202]
      + fuzzyController_B.impMethod_j[i]) + fuzzyController_B.impMethod_c[i +
      202]) + fuzzyController_B.impMethod_g[i]) +
      fuzzyController_B.impMethod_f1[i]) + fuzzyController_B.impMethod_pd[i +
      202];
  }

  /* End of Sum: '<S5>/AggMethod3' */

  /* Sum: '<S10>/Sum1' */
  fuzzyController_B.d0 = fuzzyController_B.impMethod_k[0];
  for (i = 0; i < 100; i++) {
    fuzzyController_B.d0 += fuzzyController_B.impMethod_k[i + 1];
  }

  fuzzyController_B.Sum1_h = fuzzyController_B.d0;

  /* End of Sum: '<S10>/Sum1' */

  /* If: '<S10>/If' incorporates:
   *  Constant: '<S32>/One'
   */
  if (fuzzyController_B.Sum1_h <= 0.0) {
    /* Outputs for IfAction SubSystem: '<S10>/Action: One' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    rtb_Merge_ic = fuzzyController_P.One_Value_g;

    /* End of Outputs for SubSystem: '<S10>/Action: One' */
  } else {
    /* Outputs for IfAction SubSystem: '<S10>/Action: u1' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    fuzzyController_Actionu1(fuzzyController_B.Sum1_h, &rtb_Merge_ic);

    /* End of Outputs for SubSystem: '<S10>/Action: u1' */
  }

  /* End of If: '<S10>/If' */

  /* Sum: '<S5>/AggMethod4' */
  for (i = 0; i < 101; i++) {
    fuzzyController_B.AggMethod4[i] = ((((fuzzyController_B.impMethod_j[i + 101]
      + fuzzyController_B.impMethod_p[i + 303]) +
      fuzzyController_B.impMethod_c[i + 303]) + fuzzyController_B.impMethod_g[i
      + 101]) + fuzzyController_B.impMethod_f1[i + 101]) +
      fuzzyController_B.impMethod_pd[i + 303];
  }

  /* End of Sum: '<S5>/AggMethod4' */

  /* Sum: '<S11>/Sum1' */
  fuzzyController_B.d0 = fuzzyController_B.AggMethod4[0];
  for (i = 0; i < 100; i++) {
    fuzzyController_B.d0 += fuzzyController_B.AggMethod4[i + 1];
  }

  fuzzyController_B.Sum1_b = fuzzyController_B.d0;

  /* End of Sum: '<S11>/Sum1' */

  /* If: '<S11>/If' incorporates:
   *  Constant: '<S34>/One'
   */
  if (fuzzyController_B.Sum1_b <= 0.0) {
    /* Outputs for IfAction SubSystem: '<S11>/Action: One' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    rtb_Merge_cf = fuzzyController_P.One_Value_o;

    /* End of Outputs for SubSystem: '<S11>/Action: One' */
  } else {
    /* Outputs for IfAction SubSystem: '<S11>/Action: u1' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    fuzzyController_Actionu1(fuzzyController_B.Sum1_b, &rtb_Merge_cf);

    /* End of Outputs for SubSystem: '<S11>/Action: u1' */
  }

  /* End of If: '<S11>/If' */

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/MidRange'
   *  Constant: '<S5>/Zero'
   *  Product: '<S11>/Averaging (COA)'
   *  RelationalOperator: '<S5>/Zero Firing Strength?'
   *  Sum: '<S5>/Total Firing Strength'
   */
  if (((((((((fuzzyController_B.Weighting_e + fuzzyController_B.Weighting_h) +
             fuzzyController_B.Weighting_k) + fuzzyController_B.Weighting_i) +
           fuzzyController_B.Weighting_o) +
          fuzzyController_B.ZeroFiringStrength_n) +
         fuzzyController_B.Weighting_a) + fuzzyController_B.Weighting) +
       fuzzyController_B.Weighting_c > fuzzyController_P.Zero_Value_j) >=
      fuzzyController_P.Switch_Threshold_k) {
    /* Product: '<S8>/Product (COA)' incorporates:
     *  Constant: '<S8>/x data'
     */
    for (i = 0; i < 101; i++) {
      fuzzyController_B.impMethod[i] *= fuzzyController_P.xdata_Value_m[i];
    }

    /* End of Product: '<S8>/Product (COA)' */

    /* Sum: '<S8>/Sum' */
    fuzzyController_B.Weighting_a = fuzzyController_B.impMethod[0];
    for (i = 0; i < 100; i++) {
      fuzzyController_B.Weighting_a += fuzzyController_B.impMethod[i + 1];
    }

    /* End of Sum: '<S8>/Sum' */

    /* Product: '<S8>/Averaging (COA)' */
    fuzzyController_B.Weighting_i = fuzzyController_B.Weighting_a /
      fuzzyController_B.Merge_jp;

    /* Product: '<S9>/Product (COA)' incorporates:
     *  Constant: '<S9>/x data'
     */
    for (i = 0; i < 101; i++) {
      fuzzyController_B.impMethod_a[i] *= fuzzyController_P.xdata_Value_my[i];
    }

    /* End of Product: '<S9>/Product (COA)' */

    /* Sum: '<S9>/Sum' */
    fuzzyController_B.Weighting_a = fuzzyController_B.impMethod_a[0];
    for (i = 0; i < 100; i++) {
      fuzzyController_B.Weighting_a += fuzzyController_B.impMethod_a[i + 1];
    }

    /* End of Sum: '<S9>/Sum' */

    /* Product: '<S9>/Averaging (COA)' */
    fuzzyController_B.Weighting_c = fuzzyController_B.Weighting_a /
      fuzzyController_B.Merge_i;

    /* Product: '<S10>/Product (COA)' incorporates:
     *  Constant: '<S10>/x data'
     */
    for (i = 0; i < 101; i++) {
      fuzzyController_B.impMethod_k[i] *= fuzzyController_P.xdata_Value_i[i];
    }

    /* End of Product: '<S10>/Product (COA)' */

    /* Sum: '<S10>/Sum' */
    fuzzyController_B.Weighting_a = fuzzyController_B.impMethod_k[0];
    for (i = 0; i < 100; i++) {
      fuzzyController_B.Weighting_a += fuzzyController_B.impMethod_k[i + 1];
    }

    /* End of Sum: '<S10>/Sum' */

    /* Product: '<S10>/Averaging (COA)' */
    fuzzyController_B.Weighting_e = fuzzyController_B.Weighting_a / rtb_Merge_ic;

    /* Product: '<S11>/Product (COA)' incorporates:
     *  Constant: '<S11>/x data'
     */
    for (i = 0; i < 101; i++) {
      fuzzyController_B.AggMethod4[i] *= fuzzyController_P.xdata_Value_j[i];
    }

    /* End of Product: '<S11>/Product (COA)' */

    /* Sum: '<S11>/Sum' */
    fuzzyController_B.Weighting_a = fuzzyController_B.AggMethod4[0];
    for (i = 0; i < 100; i++) {
      fuzzyController_B.Weighting_a += fuzzyController_B.AggMethod4[i + 1];
    }

    /* End of Sum: '<S11>/Sum' */
    fuzzyController_B.Weighting_a /= rtb_Merge_cf;
  } else {
    fuzzyController_B.Weighting_i = fuzzyController_P.MidRange_Value_i[0];
    fuzzyController_B.Weighting_c = fuzzyController_P.MidRange_Value_i[1];
    fuzzyController_B.Weighting_e = fuzzyController_P.MidRange_Value_i[2];
    fuzzyController_B.Weighting_a = fuzzyController_P.MidRange_Value_i[3];
  }

  /* End of Switch: '<S5>/Switch' */

  /* Outport: '<Root>/FLWheelOutput' */
  fuzzyController_Y.FLWheelOutput = fuzzyController_B.Weighting_i;

  /* Outport: '<Root>/FRWheelOutput' */
  fuzzyController_Y.FRWheelOutput = fuzzyController_B.Weighting_c;

  /* Outport: '<Root>/BLWheelOutput' */
  fuzzyController_Y.BLWheelOutput = fuzzyController_B.Weighting_e;

  /* Outport: '<Root>/BRWheelOutput' */
  fuzzyController_Y.BRWheelOutput = fuzzyController_B.Weighting_a;

  /* If: '<S36>/If' incorporates:
   *  Constant: '<S39>/0'
   *  Constant: '<S40>/0'
   *  Inport: '<Root>/frontDifferential'
   */
  if ((fuzzyController_U.frontDifferential < -2.0) ||
      (fuzzyController_U.frontDifferential > 0.0)) {
    /* Outputs for IfAction SubSystem: '<S36>/If Action Subsystem' incorporates:
     *  ActionPort: '<S39>/Action Port'
     */
    rtb_Merge_j2 = fuzzyController_P._Value;

    /* End of Outputs for SubSystem: '<S36>/If Action Subsystem' */
  } else if (fuzzyController_U.frontDifferential == -1.0) {
    /* Outputs for IfAction SubSystem: '<S36>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S40>/Action Port'
     */
    rtb_Merge_j2 = fuzzyController_P._Value_n;

    /* End of Outputs for SubSystem: '<S36>/If Action Subsystem1' */
  } else if (fuzzyController_U.frontDifferential < -1.0) {
    /* Outputs for IfAction SubSystem: '<S36>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S42>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.frontDifferential,
      &rtb_Merge_j2, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_n);

    /* End of Outputs for SubSystem: '<S36>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S36>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S41>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.frontDifferential,
      &rtb_Merge_j2, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_c0);

    /* End of Outputs for SubSystem: '<S36>/If Action Subsystem2' */
  }

  /* End of If: '<S36>/If' */

  /* If: '<S38>/If' incorporates:
   *  Constant: '<S47>/0'
   *  Constant: '<S48>/0'
   *  Inport: '<Root>/frontDifferential'
   */
  if ((fuzzyController_U.frontDifferential < -0.0) ||
      (fuzzyController_U.frontDifferential > 2.0)) {
    /* Outputs for IfAction SubSystem: '<S38>/If Action Subsystem' incorporates:
     *  ActionPort: '<S47>/Action Port'
     */
    rtb_Merge_kn = fuzzyController_P._Value_o;

    /* End of Outputs for SubSystem: '<S38>/If Action Subsystem' */
  } else if (fuzzyController_U.frontDifferential == 1.0) {
    /* Outputs for IfAction SubSystem: '<S38>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S48>/Action Port'
     */
    rtb_Merge_kn = fuzzyController_P._Value_m;

    /* End of Outputs for SubSystem: '<S38>/If Action Subsystem1' */
  } else if (fuzzyController_U.frontDifferential < 1.0) {
    /* Outputs for IfAction SubSystem: '<S38>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S50>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.frontDifferential,
      &rtb_Merge_kn, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_ng);

    /* End of Outputs for SubSystem: '<S38>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S38>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S49>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.frontDifferential,
      &rtb_Merge_kn, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_p0);

    /* End of Outputs for SubSystem: '<S38>/If Action Subsystem2' */
  }

  /* End of If: '<S38>/If' */

  /* If: '<S61>/If' incorporates:
   *  Constant: '<S64>/0'
   *  Constant: '<S65>/0'
   *  Inport: '<Root>/rearDifferential'
   */
  if ((fuzzyController_U.rearDifferential < -2.0) ||
      (fuzzyController_U.rearDifferential > 0.0)) {
    /* Outputs for IfAction SubSystem: '<S61>/If Action Subsystem' incorporates:
     *  ActionPort: '<S64>/Action Port'
     */
    rtb_Merge_ok = fuzzyController_P._Value_mg;

    /* End of Outputs for SubSystem: '<S61>/If Action Subsystem' */
  } else if (fuzzyController_U.rearDifferential == -1.0) {
    /* Outputs for IfAction SubSystem: '<S61>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S65>/Action Port'
     */
    rtb_Merge_ok = fuzzyController_P._Value_iq;

    /* End of Outputs for SubSystem: '<S61>/If Action Subsystem1' */
  } else if (fuzzyController_U.rearDifferential < -1.0) {
    /* Outputs for IfAction SubSystem: '<S61>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S67>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.rearDifferential,
      &rtb_Merge_ok, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_o);

    /* End of Outputs for SubSystem: '<S61>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S61>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S66>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.rearDifferential,
      &rtb_Merge_ok, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_l);

    /* End of Outputs for SubSystem: '<S61>/If Action Subsystem2' */
  }

  /* End of If: '<S61>/If' */

  /* If: '<S63>/If' incorporates:
   *  Constant: '<S72>/0'
   *  Constant: '<S73>/0'
   *  Inport: '<Root>/rearDifferential'
   */
  if ((fuzzyController_U.rearDifferential < 0.0) ||
      (fuzzyController_U.rearDifferential > 2.0)) {
    /* Outputs for IfAction SubSystem: '<S63>/If Action Subsystem' incorporates:
     *  ActionPort: '<S72>/Action Port'
     */
    rtb_Merge_cy = fuzzyController_P._Value_l;

    /* End of Outputs for SubSystem: '<S63>/If Action Subsystem' */
  } else if (fuzzyController_U.rearDifferential == 1.0) {
    /* Outputs for IfAction SubSystem: '<S63>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S73>/Action Port'
     */
    rtb_Merge_cy = fuzzyController_P._Value_in;

    /* End of Outputs for SubSystem: '<S63>/If Action Subsystem1' */
  } else if (fuzzyController_U.rearDifferential < 1.0) {
    /* Outputs for IfAction SubSystem: '<S63>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S75>/Action Port'
     */
    fuzzyControl_IfActionSubsystem3(fuzzyController_U.rearDifferential,
      &rtb_Merge_cy, (P_IfActionSubsystem3_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem3_m);

    /* End of Outputs for SubSystem: '<S63>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S63>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S74>/Action Port'
     */
    fuzzyControl_IfActionSubsystem2(fuzzyController_U.rearDifferential,
      &rtb_Merge_cy, (P_IfActionSubsystem2_fuzzyCon_T *)
      &fuzzyController_P.IfActionSubsystem2_m);

    /* End of Outputs for SubSystem: '<S63>/If Action Subsystem2' */
  }

  /* End of If: '<S63>/If' */

  /* SignalConversion: '<S2>/TmpSignal ConversionAtAnimation1Inport1' incorporates:
   *  Inport: '<Root>/frontDifferential'
   *  Inport: '<Root>/powerBias'
   *  Inport: '<Root>/rearDifferential'
   *  Inport: '<Root>/throttleSignal'
   */
  fuzzyController_B.TmpSignalConversionAtAnimation1[0] =
    fuzzyController_B.Switch;
  fuzzyController_B.TmpSignalConversionAtAnimation1[1] =
    fuzzyController_U.throttleSignal;
  fuzzyController_B.TmpSignalConversionAtAnimation1[2] =
    fuzzyController_U.frontDifferential;
  fuzzyController_B.TmpSignalConversionAtAnimation1[3] =
    fuzzyController_U.rearDifferential;
  fuzzyController_B.TmpSignalConversionAtAnimation1[4] =
    fuzzyController_U.powerBias;

  /* SignalConversion: '<S3>/TmpSignal ConversionAtAnimation1Inport1' incorporates:
   *  Inport: '<Root>/steeringSignal'
   */
  fuzzyController_B.TmpSignalConversionAtAnimatio_o[0] =
    fuzzyController_B.Product;
  fuzzyController_B.TmpSignalConversionAtAnimatio_o[1] =
    fuzzyController_U.steeringSignal;
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
