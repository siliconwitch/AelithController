/*
 * File: fuzzyController.h
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

#ifndef RTW_HEADER_fuzzyController_h_
#define RTW_HEADER_fuzzyController_h_
#ifndef fuzzyController_COMMON_INCLUDES_
# define fuzzyController_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* fuzzyController_COMMON_INCLUDES_ */

#include "fuzzyController_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T impMethod_b[404];             /* '<S20>/impMethod' */
  real_T impMethod_p[404];             /* '<S21>/impMethod' */
  real_T impMethod_l[404];             /* '<S22>/impMethod' */
  real_T impMethod_d[404];             /* '<S23>/impMethod' */
  real_T impMethod_m[404];             /* '<S24>/impMethod' */
  real_T impMethod_k[202];             /* '<S25>/impMethod' */
  real_T impMethod_f[202];             /* '<S15>/impMethod' */
  real_T impMethod_kl[202];            /* '<S16>/impMethod' */
  real_T impMethod_ck[202];            /* '<S17>/impMethod' */
  real_T impMethod[101];               /* '<S14>/impMethod' */
  real_T impMethod_c[101];             /* '<S18>/impMethod' */
  real_T AggMethod3[101];              /* '<S4>/AggMethod3' */
  real_T TmpSignalConversionAtAnimation1[6];
  real_T Switch[5];                    /* '<S4>/Switch' */
  real_T Weighting;                    /* '<S14>/Weighting' */
  real_T Weighting_g;                  /* '<S18>/Weighting' */
  real_T Weighting_c;                  /* '<S19>/Weighting' */
  real_T Weighting_j;                  /* '<S20>/Weighting' */
  real_T Weighting_p;                  /* '<S21>/Weighting' */
  real_T Weighting_cb;                 /* '<S22>/Weighting' */
  real_T Weighting_m;                  /* '<S23>/Weighting' */
  real_T Weighting_k;                  /* '<S24>/Weighting' */
  real_T AveragingCOA_fi;              /* '<S8>/Averaging (COA)' */
  real_T AveragingCOA_d;               /* '<S9>/Averaging (COA)' */
  real_T Weighting_o;                  /* '<S25>/Weighting' */
  real_T Weighting_b;                  /* '<S15>/Weighting' */
  real_T Weighting_f;                  /* '<S16>/Weighting' */
  real_T ZeroFiringStrength;           /* '<S4>/Zero Firing Strength?' */
  real_T AveragingCOA_i;               /* '<S10>/Averaging (COA)' */
  real_T Merge;                        /* '<S104>/Merge' */
  real_T Merge_i;                      /* '<S105>/Merge' */
  real_T Merge_h;                      /* '<S103>/Merge' */
  real_T Sum1;                         /* '<S7>/Sum1' */
  real_T Merge_a;                      /* '<S118>/Merge' */
  real_T Merge_p;                      /* '<S119>/Merge' */
  real_T Merge_l;                      /* '<S120>/Merge' */
  real_T Sum1_i;                       /* '<S8>/Sum1' */
  real_T Merge_l2;                     /* '<S8>/Merge' */
  real_T Sum1_o;                       /* '<S9>/Sum1' */
  real_T Merge_lr;                     /* '<S9>/Merge' */
  real_T Sum1_m;                       /* '<S10>/Sum1' */
  real_T Sum1_a;                       /* '<S11>/Sum1' */
  real_T Merge_c;                      /* '<S7>/Merge' */
  real_T Merge_d;                      /* '<S74>/Merge' */
  real_T Merge_m;                      /* '<S73>/Merge' */
  real_T Merge_am;                     /* '<S88>/Merge' */
  real_T Merge_k;                      /* '<S89>/Merge' */
  real_T Merge_e;                      /* '<S10>/Merge' */
  real_T Merge_m0;                     /* '<S11>/Merge' */
  real_T Merge_f;                      /* '<S43>/Merge' */
} B_fuzzyController_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T gyroYaw;                      /* '<Root>/gyroYaw' */
  real_T steeringSignal;               /* '<Root>/steeringSignal' */
  real_T throttleSignal;               /* '<Root>/throttleSignal' */
  real_T frontDifferential;            /* '<Root>/frontDifferential' */
  real_T rearDifferential;             /* '<Root>/rearDifferential' */
  real_T powerBias;                    /* '<Root>/powerBias' */
} ExtU_fuzzyController_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T steeringOutput;               /* '<Root>/steeringOutput' */
  real_T FLWheelOutput;                /* '<Root>/FLWheelOutput' */
  real_T FRWheelOutput;                /* '<Root>/FRWheelOutput' */
  real_T BLWheelOutput;                /* '<Root>/BLWheelOutput' */
  real_T BRWheelOutput;                /* '<Root>/BRWheelOutput' */
} ExtY_fuzzyController_T;

/* Parameters for system: '<S43>/If Action Subsystem3' */
struct P_IfActionSubsystem3_fuzzyCon_T_ {
  real_T a_Value;                      /* Expression: a
                                        * Referenced by: '<S49>/a'
                                        */
  real_T b_Value;                      /* Expression: b
                                        * Referenced by: '<S49>/b'
                                        */
};

/* Parameters for system: '<S43>/If Action Subsystem2' */
struct P_IfActionSubsystem2_fuzzyCon_T_ {
  real_T b_Value;                      /* Expression: b
                                        * Referenced by: '<S48>/b'
                                        */
  real_T c_Value;                      /* Expression: c
                                        * Referenced by: '<S48>/c'
                                        */
};

/* Parameters (auto storage) */
struct P_fuzzyController_T_ {
  real_T Out1_Y0;                      /* Expression: 0
                                        * Referenced by: '<S33>/Out1'
                                        */
  real_T One_Value;                    /* Expression: 1
                                        * Referenced by: '<S33>/One'
                                        */
  real_T Out1_Y0_l;                    /* Expression: 0
                                        * Referenced by: '<S35>/Out1'
                                        */
  real_T One_Value_e;                  /* Expression: 1
                                        * Referenced by: '<S35>/One'
                                        */
  real_T Out1_Y0_g;                    /* Expression: 0
                                        * Referenced by: '<S37>/Out1'
                                        */
  real_T One_Value_ei;                 /* Expression: 1
                                        * Referenced by: '<S37>/One'
                                        */
  real_T Out1_Y0_gs;                   /* Expression: 0
                                        * Referenced by: '<S39>/Out1'
                                        */
  real_T One_Value_m;                  /* Expression: 1
                                        * Referenced by: '<S39>/One'
                                        */
  real_T Out1_Y0_o;                    /* Expression: 0
                                        * Referenced by: '<S41>/Out1'
                                        */
  real_T One_Value_b;                  /* Expression: 1
                                        * Referenced by: '<S41>/One'
                                        */
  real_T Out1_Y0_i;                    /* Expression: 0
                                        * Referenced by: '<S46>/Out1'
                                        */
  real_T _Value;                       /* Expression: 0
                                        * Referenced by: '<S46>/0'
                                        */
  real_T Out1_Y0_k;                    /* Expression: 1
                                        * Referenced by: '<S47>/Out1'
                                        */
  real_T _Value_l;                     /* Expression: 1
                                        * Referenced by: '<S47>/0'
                                        */
  real_T Out1_Y0_a;                    /* Expression: 0
                                        * Referenced by: '<S50>/Out1'
                                        */
  real_T _Value_o;                     /* Expression: 0
                                        * Referenced by: '<S50>/0'
                                        */
  real_T Out1_Y0_p;                    /* Expression: 1
                                        * Referenced by: '<S51>/Out1'
                                        */
  real_T _Value_a;                     /* Expression: 1
                                        * Referenced by: '<S51>/0'
                                        */
  real_T Out1_Y0_n;                    /* Expression: 0
                                        * Referenced by: '<S54>/Out1'
                                        */
  real_T _Value_g;                     /* Expression: 0
                                        * Referenced by: '<S54>/0'
                                        */
  real_T Out1_Y0_f;                    /* Expression: 1
                                        * Referenced by: '<S55>/Out1'
                                        */
  real_T _Value_ak;                    /* Expression: 1
                                        * Referenced by: '<S55>/0'
                                        */
  real_T Out1_Y0_h;                    /* Expression: 0
                                        * Referenced by: '<S61>/Out1'
                                        */
  real_T _Value_p;                     /* Expression: 0
                                        * Referenced by: '<S61>/0'
                                        */
  real_T Out1_Y0_b;                    /* Expression: 1
                                        * Referenced by: '<S62>/Out1'
                                        */
  real_T _Value_k;                     /* Expression: 1
                                        * Referenced by: '<S62>/0'
                                        */
  real_T Out1_Y0_bz;                   /* Expression: 0
                                        * Referenced by: '<S65>/Out1'
                                        */
  real_T _Value_kp;                    /* Expression: 0
                                        * Referenced by: '<S65>/0'
                                        */
  real_T Out1_Y0_hh;                   /* Expression: 1
                                        * Referenced by: '<S66>/Out1'
                                        */
  real_T _Value_pz;                    /* Expression: 1
                                        * Referenced by: '<S66>/0'
                                        */
  real_T Out1_Y0_m;                    /* Expression: 0
                                        * Referenced by: '<S69>/Out1'
                                        */
  real_T _Value_i;                     /* Expression: 0
                                        * Referenced by: '<S69>/0'
                                        */
  real_T Out1_Y0_e;                    /* Expression: 1
                                        * Referenced by: '<S70>/Out1'
                                        */
  real_T _Value_in;                    /* Expression: 1
                                        * Referenced by: '<S70>/0'
                                        */
  real_T Out1_Y0_ie;                   /* Expression: 0
                                        * Referenced by: '<S76>/Out1'
                                        */
  real_T _Value_j;                     /* Expression: 0
                                        * Referenced by: '<S76>/0'
                                        */
  real_T Out1_Y0_ef;                   /* Expression: 1
                                        * Referenced by: '<S77>/Out1'
                                        */
  real_T _Value_o1;                    /* Expression: 1
                                        * Referenced by: '<S77>/0'
                                        */
  real_T Out1_Y0_oa;                   /* Expression: 0
                                        * Referenced by: '<S80>/Out1'
                                        */
  real_T _Value_j3;                    /* Expression: 0
                                        * Referenced by: '<S80>/0'
                                        */
  real_T Out1_Y0_fl;                   /* Expression: 1
                                        * Referenced by: '<S81>/Out1'
                                        */
  real_T _Value_o3;                    /* Expression: 1
                                        * Referenced by: '<S81>/0'
                                        */
  real_T Out1_Y0_d;                    /* Expression: 0
                                        * Referenced by: '<S84>/Out1'
                                        */
  real_T _Value_h;                     /* Expression: 0
                                        * Referenced by: '<S84>/0'
                                        */
  real_T Out1_Y0_aq;                   /* Expression: 1
                                        * Referenced by: '<S85>/Out1'
                                        */
  real_T _Value_f;                     /* Expression: 1
                                        * Referenced by: '<S85>/0'
                                        */
  real_T Out1_Y0_f0;                   /* Expression: 0
                                        * Referenced by: '<S91>/Out1'
                                        */
  real_T _Value_id;                    /* Expression: 0
                                        * Referenced by: '<S91>/0'
                                        */
  real_T Out1_Y0_ih;                   /* Expression: 1
                                        * Referenced by: '<S92>/Out1'
                                        */
  real_T _Value_b;                     /* Expression: 1
                                        * Referenced by: '<S92>/0'
                                        */
  real_T Out1_Y0_pl;                   /* Expression: 0
                                        * Referenced by: '<S95>/Out1'
                                        */
  real_T _Value_fa;                    /* Expression: 0
                                        * Referenced by: '<S95>/0'
                                        */
  real_T Out1_Y0_li;                   /* Expression: 1
                                        * Referenced by: '<S96>/Out1'
                                        */
  real_T _Value_m;                     /* Expression: 1
                                        * Referenced by: '<S96>/0'
                                        */
  real_T Out1_Y0_gi;                   /* Expression: 0
                                        * Referenced by: '<S99>/Out1'
                                        */
  real_T _Value_pc;                    /* Expression: 0
                                        * Referenced by: '<S99>/0'
                                        */
  real_T Out1_Y0_am;                   /* Expression: 1
                                        * Referenced by: '<S100>/Out1'
                                        */
  real_T _Value_e;                     /* Expression: 1
                                        * Referenced by: '<S100>/0'
                                        */
  real_T Out1_Y0_j;                    /* Expression: 0
                                        * Referenced by: '<S106>/Out1'
                                        */
  real_T _Value_bk;                    /* Expression: 0
                                        * Referenced by: '<S106>/0'
                                        */
  real_T Out1_Y0_mm;                   /* Expression: 1
                                        * Referenced by: '<S107>/Out1'
                                        */
  real_T _Value_e1;                    /* Expression: 1
                                        * Referenced by: '<S107>/0'
                                        */
  real_T Out1_Y0_fd;                   /* Expression: 0
                                        * Referenced by: '<S110>/Out1'
                                        */
  real_T _Value_i1;                    /* Expression: 0
                                        * Referenced by: '<S110>/0'
                                        */
  real_T Out1_Y0_aa;                   /* Expression: 1
                                        * Referenced by: '<S111>/Out1'
                                        */
  real_T _Value_ph;                    /* Expression: 1
                                        * Referenced by: '<S111>/0'
                                        */
  real_T Out1_Y0_a3;                   /* Expression: 0
                                        * Referenced by: '<S114>/Out1'
                                        */
  real_T _Value_p5;                    /* Expression: 0
                                        * Referenced by: '<S114>/0'
                                        */
  real_T Out1_Y0_dn;                   /* Expression: 1
                                        * Referenced by: '<S115>/Out1'
                                        */
  real_T _Value_fc;                    /* Expression: 1
                                        * Referenced by: '<S115>/0'
                                        */
  real_T Out1_Y0_k3;                   /* Expression: 0
                                        * Referenced by: '<S121>/Out1'
                                        */
  real_T _Value_hh;                    /* Expression: 0
                                        * Referenced by: '<S121>/0'
                                        */
  real_T Out1_Y0_j4;                   /* Expression: 1
                                        * Referenced by: '<S122>/Out1'
                                        */
  real_T _Value_pg;                    /* Expression: 1
                                        * Referenced by: '<S122>/0'
                                        */
  real_T Out1_Y0_b3;                   /* Expression: 0
                                        * Referenced by: '<S125>/Out1'
                                        */
  real_T _Value_bv;                    /* Expression: 0
                                        * Referenced by: '<S125>/0'
                                        */
  real_T Out1_Y0_fi;                   /* Expression: 1
                                        * Referenced by: '<S126>/Out1'
                                        */
  real_T _Value_hy;                    /* Expression: 1
                                        * Referenced by: '<S126>/0'
                                        */
  real_T Out1_Y0_hw;                   /* Expression: 0
                                        * Referenced by: '<S129>/Out1'
                                        */
  real_T _Value_om;                    /* Expression: 0
                                        * Referenced by: '<S129>/0'
                                        */
  real_T Out1_Y0_ja;                   /* Expression: 1
                                        * Referenced by: '<S130>/Out1'
                                        */
  real_T _Value_os;                    /* Expression: 1
                                        * Referenced by: '<S130>/0'
                                        */
  real_T xdata_Value[101];             /* Expression: Xdata
                                        * Referenced by: '<S7>/x data'
                                        */
  real_T Weight_Value;                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S14>/Weight'
                                        */
  real_T left_Value[101];              /* Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(1).params)
                                        * Referenced by: '<S30>/left'
                                        */
  real_T Weight_Value_n;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S18>/Weight'
                                        */
  real_T right_Value[101];             /* Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(2).params)
                                        * Referenced by: '<S30>/right'
                                        */
  real_T Weight_Value_f;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S19>/Weight'
                                        */
  real_T center_Value[101];            /* Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(3).params)
                                        * Referenced by: '<S30>/center'
                                        */
  real_T xdata_Value_n[101];           /* Expression: Xdata
                                        * Referenced by: '<S8>/x data'
                                        */
  real_T Weight_Value_j;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S20>/Weight'
                                        */
  real_T forward_Value[101];           /* Expression: trimf(linspace(fis.output(2).range(1),fis.output(2).range(2),101),fis.output(2).mf(3).params)
                                        * Referenced by: '<S12>/forward'
                                        */
  real_T forward_Value_c[101];         /* Expression: trimf(linspace(fis.output(3).range(1),fis.output(3).range(2),101),fis.output(3).mf(3).params)
                                        * Referenced by: '<S13>/forward'
                                        */
  real_T forward_Value_k[101];         /* Expression: trimf(linspace(fis.output(4).range(1),fis.output(4).range(2),101),fis.output(4).mf(3).params)
                                        * Referenced by: '<S5>/forward'
                                        */
  real_T forward_Value_f[101];         /* Expression: trimf(linspace(fis.output(5).range(1),fis.output(5).range(2),101),fis.output(5).mf(3).params)
                                        * Referenced by: '<S6>/forward'
                                        */
  real_T Weight_Value_g;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S21>/Weight'
                                        */
  real_T reverse_Value[101];           /* Expression: trimf(linspace(fis.output(4).range(1),fis.output(4).range(2),101),fis.output(4).mf(1).params)
                                        * Referenced by: '<S5>/reverse'
                                        */
  real_T reverse_Value_c[101];         /* Expression: trimf(linspace(fis.output(5).range(1),fis.output(5).range(2),101),fis.output(5).mf(1).params)
                                        * Referenced by: '<S6>/reverse'
                                        */
  real_T Weight_Value_p;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S22>/Weight'
                                        */
  real_T reverse_Value_cg[101];        /* Expression: trimf(linspace(fis.output(2).range(1),fis.output(2).range(2),101),fis.output(2).mf(1).params)
                                        * Referenced by: '<S12>/reverse'
                                        */
  real_T reverse_Value_m[101];         /* Expression: trimf(linspace(fis.output(3).range(1),fis.output(3).range(2),101),fis.output(3).mf(1).params)
                                        * Referenced by: '<S13>/reverse'
                                        */
  real_T Weight_Value_m;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S23>/Weight'
                                        */
  real_T neutral_Value[101];           /* Expression: trimf(linspace(fis.output(2).range(1),fis.output(2).range(2),101),fis.output(2).mf(2).params)
                                        * Referenced by: '<S12>/neutral'
                                        */
  real_T neutral_Value_o[101];         /* Expression: trimf(linspace(fis.output(3).range(1),fis.output(3).range(2),101),fis.output(3).mf(2).params)
                                        * Referenced by: '<S13>/neutral'
                                        */
  real_T neutral_Value_b[101];         /* Expression: trimf(linspace(fis.output(4).range(1),fis.output(4).range(2),101),fis.output(4).mf(2).params)
                                        * Referenced by: '<S5>/neutral'
                                        */
  real_T neutral_Value_n[101];         /* Expression: trimf(linspace(fis.output(5).range(1),fis.output(5).range(2),101),fis.output(5).mf(2).params)
                                        * Referenced by: '<S6>/neutral'
                                        */
  real_T Weight_Value_pr;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S24>/Weight'
                                        */
  real_T xdata_Value_i[101];           /* Expression: Xdata
                                        * Referenced by: '<S9>/x data'
                                        */
  real_T xdata_Value_c[101];           /* Expression: Xdata
                                        * Referenced by: '<S10>/x data'
                                        */
  real_T Weight_Value_b;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S25>/Weight'
                                        */
  real_T Weight_Value_h;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S15>/Weight'
                                        */
  real_T Weight_Value_nt;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S16>/Weight'
                                        */
  real_T Weight_Value_fw;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S17>/Weight'
                                        */
  real_T xdata_Value_l[101];           /* Expression: Xdata
                                        * Referenced by: '<S11>/x data'
                                        */
  real_T Zero_Value;                   /* Expression: 0
                                        * Referenced by: '<S4>/Zero'
                                        */
  real_T MidRange_Value[5];            /* Expression: mean(cat(1,fis.output.range),2)
                                        * Referenced by: '<S4>/MidRange'
                                        */
  real_T Switch_Threshold;             /* Expression: 1
                                        * Referenced by: '<S4>/Switch'
                                        */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_k;/* '<S120>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_gb;/* '<S120>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_h;/* '<S119>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_b;/* '<S119>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_e;/* '<S118>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_k;/* '<S118>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_j;/* '<S105>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_g;/* '<S105>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2;/* '<S104>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3;/* '<S104>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_p;/* '<S103>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_p;/* '<S103>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_ea;/* '<S90>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_gg;/* '<S90>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_l;/* '<S89>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_gv;/* '<S89>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_ak;/* '<S88>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_f;/* '<S88>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_c;/* '<S75>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_lk;/* '<S75>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_a;/* '<S74>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_j;/* '<S74>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_pq;/* '<S73>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_jn;/* '<S73>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_hl;/* '<S60>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_p3;/* '<S60>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_ac;/* '<S59>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_l;/* '<S59>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_ew;/* '<S58>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_m;/* '<S58>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_ht;/* '<S45>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_d;/* '<S45>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_m;/* '<S44>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_ps;/* '<S44>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_jw;/* '<S43>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_e;/* '<S43>/If Action Subsystem3' */
};

/* Block parameters (auto storage) */
extern P_fuzzyController_T fuzzyController_P;

/* Block signals (auto storage) */
extern B_fuzzyController_T fuzzyController_B;

/* External inputs (root inport signals with auto storage) */
extern ExtU_fuzzyController_T fuzzyController_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_fuzzyController_T fuzzyController_Y;

/* Model entry point functions */
extern void fuzzyController_initialize(void);
extern void fuzzyController_step(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('fuzzyControllerTestBench/fuzzyController')    - opens subsystem fuzzyControllerTestBench/fuzzyController
 * hilite_system('fuzzyControllerTestBench/fuzzyController/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'fuzzyControllerTestBench'
 * '<S1>'   : 'fuzzyControllerTestBench/fuzzyController'
 * '<S2>'   : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer'
 * '<S3>'   : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller'
 * '<S4>'   : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard'
 * '<S5>'   : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/BLWheelOutput'
 * '<S6>'   : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/BRWheelOutput'
 * '<S7>'   : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Defuzzification1'
 * '<S8>'   : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Defuzzification2'
 * '<S9>'   : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Defuzzification3'
 * '<S10>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Defuzzification4'
 * '<S11>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Defuzzification5'
 * '<S12>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/FLWheelOutput'
 * '<S13>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/FRWheelOutput'
 * '<S14>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Rule1'
 * '<S15>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Rule10'
 * '<S16>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Rule11'
 * '<S17>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Rule12'
 * '<S18>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Rule2'
 * '<S19>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Rule3'
 * '<S20>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Rule4'
 * '<S21>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Rule5'
 * '<S22>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Rule6'
 * '<S23>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Rule7'
 * '<S24>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Rule8'
 * '<S25>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Rule9'
 * '<S26>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential'
 * '<S27>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw'
 * '<S28>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias'
 * '<S29>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential'
 * '<S30>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringOutput'
 * '<S31>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal'
 * '<S32>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal'
 * '<S33>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Defuzzification1/Action: One'
 * '<S34>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Defuzzification1/Action: u1'
 * '<S35>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Defuzzification2/Action: One'
 * '<S36>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Defuzzification2/Action: u1'
 * '<S37>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Defuzzification3/Action: One'
 * '<S38>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Defuzzification3/Action: u1'
 * '<S39>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Defuzzification4/Action: One'
 * '<S40>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Defuzzification4/Action: u1'
 * '<S41>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Defuzzification5/Action: One'
 * '<S42>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Defuzzification5/Action: u1'
 * '<S43>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/loose'
 * '<S44>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/medium'
 * '<S45>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/tight'
 * '<S46>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/loose/If Action Subsystem'
 * '<S47>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/loose/If Action Subsystem1'
 * '<S48>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/loose/If Action Subsystem2'
 * '<S49>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/loose/If Action Subsystem3'
 * '<S50>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/medium/If Action Subsystem'
 * '<S51>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/medium/If Action Subsystem1'
 * '<S52>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/medium/If Action Subsystem2'
 * '<S53>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/medium/If Action Subsystem3'
 * '<S54>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/tight/If Action Subsystem'
 * '<S55>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/tight/If Action Subsystem1'
 * '<S56>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/tight/If Action Subsystem2'
 * '<S57>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/tight/If Action Subsystem3'
 * '<S58>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CCW'
 * '<S59>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CW'
 * '<S60>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw/still'
 * '<S61>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CCW/If Action Subsystem'
 * '<S62>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CCW/If Action Subsystem1'
 * '<S63>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CCW/If Action Subsystem2'
 * '<S64>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CCW/If Action Subsystem3'
 * '<S65>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CW/If Action Subsystem'
 * '<S66>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CW/If Action Subsystem1'
 * '<S67>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CW/If Action Subsystem2'
 * '<S68>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CW/If Action Subsystem3'
 * '<S69>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw/still/If Action Subsystem'
 * '<S70>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw/still/If Action Subsystem1'
 * '<S71>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw/still/If Action Subsystem2'
 * '<S72>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw/still/If Action Subsystem3'
 * '<S73>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias/back'
 * '<S74>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias/front'
 * '<S75>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias/middle'
 * '<S76>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias/back/If Action Subsystem'
 * '<S77>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias/back/If Action Subsystem1'
 * '<S78>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias/back/If Action Subsystem2'
 * '<S79>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias/back/If Action Subsystem3'
 * '<S80>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias/front/If Action Subsystem'
 * '<S81>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias/front/If Action Subsystem1'
 * '<S82>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias/front/If Action Subsystem2'
 * '<S83>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias/front/If Action Subsystem3'
 * '<S84>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias/middle/If Action Subsystem'
 * '<S85>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias/middle/If Action Subsystem1'
 * '<S86>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias/middle/If Action Subsystem2'
 * '<S87>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias/middle/If Action Subsystem3'
 * '<S88>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/loose'
 * '<S89>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/medium'
 * '<S90>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/tight'
 * '<S91>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/loose/If Action Subsystem'
 * '<S92>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/loose/If Action Subsystem1'
 * '<S93>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/loose/If Action Subsystem2'
 * '<S94>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/loose/If Action Subsystem3'
 * '<S95>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/medium/If Action Subsystem'
 * '<S96>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/medium/If Action Subsystem1'
 * '<S97>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/medium/If Action Subsystem2'
 * '<S98>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/medium/If Action Subsystem3'
 * '<S99>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/tight/If Action Subsystem'
 * '<S100>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/tight/If Action Subsystem1'
 * '<S101>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/tight/If Action Subsystem2'
 * '<S102>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/tight/If Action Subsystem3'
 * '<S103>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal/center'
 * '<S104>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal/left'
 * '<S105>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal/right'
 * '<S106>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal/center/If Action Subsystem'
 * '<S107>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal/center/If Action Subsystem1'
 * '<S108>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal/center/If Action Subsystem2'
 * '<S109>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal/center/If Action Subsystem3'
 * '<S110>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal/left/If Action Subsystem'
 * '<S111>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal/left/If Action Subsystem1'
 * '<S112>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal/left/If Action Subsystem2'
 * '<S113>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal/left/If Action Subsystem3'
 * '<S114>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal/right/If Action Subsystem'
 * '<S115>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal/right/If Action Subsystem1'
 * '<S116>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal/right/If Action Subsystem2'
 * '<S117>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal/right/If Action Subsystem3'
 * '<S118>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/forward'
 * '<S119>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/neutral'
 * '<S120>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/reverse'
 * '<S121>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/forward/If Action Subsystem'
 * '<S122>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/forward/If Action Subsystem1'
 * '<S123>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/forward/If Action Subsystem2'
 * '<S124>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/forward/If Action Subsystem3'
 * '<S125>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/neutral/If Action Subsystem'
 * '<S126>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/neutral/If Action Subsystem1'
 * '<S127>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/neutral/If Action Subsystem2'
 * '<S128>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/neutral/If Action Subsystem3'
 * '<S129>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/reverse/If Action Subsystem'
 * '<S130>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/reverse/If Action Subsystem1'
 * '<S131>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/reverse/If Action Subsystem2'
 * '<S132>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/reverse/If Action Subsystem3'
 */
#endif                                 /* RTW_HEADER_fuzzyController_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
