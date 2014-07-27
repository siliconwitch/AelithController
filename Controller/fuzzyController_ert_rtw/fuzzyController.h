/*
 * File: fuzzyController.h
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

#ifndef RTW_HEADER_fuzzyController_h_
#define RTW_HEADER_fuzzyController_h_
#include "rtwtypes.h"
#ifndef fuzzyController_COMMON_INCLUDES_
# define fuzzyController_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* fuzzyController_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T impMethod_p[404];             /* '<S16>/impMethod' */
  real_T impMethod_c[404];             /* '<S17>/impMethod' */
  real_T impMethod_pd[404];            /* '<S22>/impMethod' */
  real_T impMethod_f1[202];            /* '<S19>/impMethod' */
  real_T impMethod_g[202];             /* '<S18>/impMethod' */
  real_T impMethod_j[202];             /* '<S14>/impMethod' */
  real_T impMethod[101];               /* '<S104>/impMethod' */
  real_T impMethod_a[101];             /* '<S105>/impMethod' */
  real_T impMethod_k[101];             /* '<S106>/impMethod' */
  real_T AggMethod4[101];              /* '<S5>/AggMethod4' */
  real_T TmpSignalConversionAtAnimation1[5];
  real_T TmpSignalConversionAtAnimatio_o[2];
  real_T Weighting_a;                  /* '<S20>/Weighting' */
  real_T Weighting_i;                  /* '<S17>/Weighting' */
  real_T Weighting_k;                  /* '<S16>/Weighting' */
  real_T Weighting_h;                  /* '<S15>/Weighting' */
  real_T Weighting;                    /* '<S21>/Weighting' */
  real_T Weighting_c;                  /* '<S22>/Weighting' */
  real_T Weighting_e;                  /* '<S14>/Weighting' */
  real_T Weighting_o;                  /* '<S18>/Weighting' */
  real_T ZeroFiringStrength_n;         /* '<S5>/Zero Firing Strength?' */
  real_T d0;
  real_T Product;                      /* '<S1>/Product' */
  real_T Sum1;                         /* '<S103>/Sum1' */
  real_T Switch;                       /* '<S102>/Switch' */
  real_T Sum1_f;                       /* '<S8>/Sum1' */
  real_T Sum1_l;                       /* '<S9>/Sum1' */
  real_T Sum1_h;                       /* '<S10>/Sum1' */
  real_T Sum1_b;                       /* '<S11>/Sum1' */
  real_T Merge;                        /* '<S123>/Merge' */
  real_T Merge_b;                      /* '<S124>/Merge' */
  real_T Merge_k;                      /* '<S114>/Merge' */
  real_T Merge_bs;                     /* '<S113>/Merge' */
  real_T Merge_c;                      /* '<S103>/Merge' */
  real_T Merge_m;                      /* '<S51>/Merge' */
  real_T Merge_k4;                     /* '<S87>/Merge' */
  real_T Merge_j;                      /* '<S88>/Merge' */
  real_T Merge_g;                      /* '<S37>/Merge' */
  real_T Merge_my;                     /* '<S76>/Merge' */
  real_T Merge_o;                      /* '<S86>/Merge' */
  real_T Merge_h;                      /* '<S77>/Merge' */
  real_T Merge_jp;                     /* '<S8>/Merge' */
  real_T Merge_i;                      /* '<S9>/Merge' */
  real_T Merge_n;                      /* '<S52>/Merge' */
} B_fuzzyController_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T gyroYaw;                      /* '<Root>/gyroYaw' */
  real_T steeringSignal;               /* '<Root>/steeringSignal' */
  real_T throttleSignal;               /* '<Root>/throttleSignal' */
  real_T frontDifferential;            /* '<Root>/frontDifferential' */
  real_T rearDifferential;             /* '<Root>/rearDifferential' */
  real_T powerBias;                    /* '<Root>/powerBias' */
  real_T gyroGain;                     /* '<Root>/gyroGain' */
} ExtU_fuzzyController_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T steeringOutput;               /* '<Root>/steeringOutput' */
  real_T FLWheelOutput;                /* '<Root>/FLWheelOutput' */
  real_T FRWheelOutput;                /* '<Root>/FRWheelOutput' */
  real_T BLWheelOutput;                /* '<Root>/BLWheelOutput' */
  real_T BRWheelOutput;                /* '<Root>/BRWheelOutput' */
} ExtY_fuzzyController_T;

/* Parameters for system: '<S36>/If Action Subsystem3' */
struct P_IfActionSubsystem3_fuzzyCon_T_ {
  real_T a_Value;                      /* Expression: a
                                        * Referenced by: '<S42>/a'
                                        */
  real_T b_Value;                      /* Expression: b
                                        * Referenced by: '<S42>/b'
                                        */
};

/* Parameters for system: '<S36>/If Action Subsystem3' */
typedef struct P_IfActionSubsystem3_fuzzyCon_T_ P_IfActionSubsystem3_fuzzyCon_T;

/* Parameters for system: '<S36>/If Action Subsystem2' */
struct P_IfActionSubsystem2_fuzzyCon_T_ {
  real_T b_Value;                      /* Expression: b
                                        * Referenced by: '<S41>/b'
                                        */
  real_T c_Value;                      /* Expression: c
                                        * Referenced by: '<S41>/c'
                                        */
};

/* Parameters for system: '<S36>/If Action Subsystem2' */
typedef struct P_IfActionSubsystem2_fuzzyCon_T_ P_IfActionSubsystem2_fuzzyCon_T;

/* Parameters (auto storage) */
struct P_fuzzyController_T_ {
  real_T Out1_Y0;                      /* Expression: 0
                                        * Referenced by: '<S28>/Out1'
                                        */
  real_T One_Value;                    /* Expression: 1
                                        * Referenced by: '<S28>/One'
                                        */
  real_T Out1_Y0_n;                    /* Expression: 0
                                        * Referenced by: '<S30>/Out1'
                                        */
  real_T One_Value_n;                  /* Expression: 1
                                        * Referenced by: '<S30>/One'
                                        */
  real_T Out1_Y0_a;                    /* Expression: 0
                                        * Referenced by: '<S32>/Out1'
                                        */
  real_T One_Value_g;                  /* Expression: 1
                                        * Referenced by: '<S32>/One'
                                        */
  real_T Out1_Y0_f;                    /* Expression: 0
                                        * Referenced by: '<S34>/Out1'
                                        */
  real_T One_Value_o;                  /* Expression: 1
                                        * Referenced by: '<S34>/One'
                                        */
  real_T Out1_Y0_j;                    /* Expression: 0
                                        * Referenced by: '<S39>/Out1'
                                        */
  real_T _Value;                       /* Expression: 0
                                        * Referenced by: '<S39>/0'
                                        */
  real_T Out1_Y0_l;                    /* Expression: 1
                                        * Referenced by: '<S40>/Out1'
                                        */
  real_T _Value_n;                     /* Expression: 1
                                        * Referenced by: '<S40>/0'
                                        */
  real_T Out1_Y0_e;                    /* Expression: 0
                                        * Referenced by: '<S43>/Out1'
                                        */
  real_T _Value_i;                     /* Expression: 0
                                        * Referenced by: '<S43>/0'
                                        */
  real_T Out1_Y0_h;                    /* Expression: 1
                                        * Referenced by: '<S44>/Out1'
                                        */
  real_T _Value_h;                     /* Expression: 1
                                        * Referenced by: '<S44>/0'
                                        */
  real_T Out1_Y0_fs;                   /* Expression: 0
                                        * Referenced by: '<S47>/Out1'
                                        */
  real_T _Value_o;                     /* Expression: 0
                                        * Referenced by: '<S47>/0'
                                        */
  real_T Out1_Y0_c;                    /* Expression: 1
                                        * Referenced by: '<S48>/Out1'
                                        */
  real_T _Value_m;                     /* Expression: 1
                                        * Referenced by: '<S48>/0'
                                        */
  real_T Out1_Y0_et;                   /* Expression: 0
                                        * Referenced by: '<S53>/Out1'
                                        */
  real_T _Value_e;                     /* Expression: 0
                                        * Referenced by: '<S53>/0'
                                        */
  real_T Out1_Y0_m;                    /* Expression: 1
                                        * Referenced by: '<S54>/Out1'
                                        */
  real_T _Value_p;                     /* Expression: 1
                                        * Referenced by: '<S54>/0'
                                        */
  real_T Out1_Y0_jy;                   /* Expression: 0
                                        * Referenced by: '<S57>/Out1'
                                        */
  real_T _Value_j;                     /* Expression: 0
                                        * Referenced by: '<S57>/0'
                                        */
  real_T Out1_Y0_cy;                   /* Expression: 1
                                        * Referenced by: '<S58>/Out1'
                                        */
  real_T _Value_mx;                    /* Expression: 1
                                        * Referenced by: '<S58>/0'
                                        */
  real_T Out1_Y0_f4;                   /* Expression: 0
                                        * Referenced by: '<S64>/Out1'
                                        */
  real_T _Value_mg;                    /* Expression: 0
                                        * Referenced by: '<S64>/0'
                                        */
  real_T Out1_Y0_ex;                   /* Expression: 1
                                        * Referenced by: '<S65>/Out1'
                                        */
  real_T _Value_iq;                    /* Expression: 1
                                        * Referenced by: '<S65>/0'
                                        */
  real_T Out1_Y0_g;                    /* Expression: 0
                                        * Referenced by: '<S68>/Out1'
                                        */
  real_T _Value_d;                     /* Expression: 0
                                        * Referenced by: '<S68>/0'
                                        */
  real_T Out1_Y0_k;                    /* Expression: 1
                                        * Referenced by: '<S69>/Out1'
                                        */
  real_T _Value_no;                    /* Expression: 1
                                        * Referenced by: '<S69>/0'
                                        */
  real_T Out1_Y0_fsc;                  /* Expression: 0
                                        * Referenced by: '<S72>/Out1'
                                        */
  real_T _Value_l;                     /* Expression: 0
                                        * Referenced by: '<S72>/0'
                                        */
  real_T Out1_Y0_lc;                   /* Expression: 1
                                        * Referenced by: '<S73>/Out1'
                                        */
  real_T _Value_in;                    /* Expression: 1
                                        * Referenced by: '<S73>/0'
                                        */
  real_T Out1_Y0_kz;                   /* Expression: 0
                                        * Referenced by: '<S78>/Out1'
                                        */
  real_T _Value_pq;                    /* Expression: 0
                                        * Referenced by: '<S78>/0'
                                        */
  real_T Out1_Y0_cp;                   /* Expression: 1
                                        * Referenced by: '<S79>/Out1'
                                        */
  real_T _Value_a;                     /* Expression: 1
                                        * Referenced by: '<S79>/0'
                                        */
  real_T Out1_Y0_nz;                   /* Expression: 0
                                        * Referenced by: '<S82>/Out1'
                                        */
  real_T _Value_n4;                    /* Expression: 0
                                        * Referenced by: '<S82>/0'
                                        */
  real_T Out1_Y0_n3;                   /* Expression: 1
                                        * Referenced by: '<S83>/Out1'
                                        */
  real_T _Value_py;                    /* Expression: 1
                                        * Referenced by: '<S83>/0'
                                        */
  real_T Out1_Y0_p;                    /* Expression: 0
                                        * Referenced by: '<S89>/Out1'
                                        */
  real_T _Value_aj;                    /* Expression: 0
                                        * Referenced by: '<S89>/0'
                                        */
  real_T Out1_Y0_hv;                   /* Expression: 1
                                        * Referenced by: '<S90>/Out1'
                                        */
  real_T _Value_ju;                    /* Expression: 1
                                        * Referenced by: '<S90>/0'
                                        */
  real_T Out1_Y0_o;                    /* Expression: 0
                                        * Referenced by: '<S93>/Out1'
                                        */
  real_T _Value_af;                    /* Expression: 0
                                        * Referenced by: '<S93>/0'
                                        */
  real_T Out1_Y0_cw;                   /* Expression: 1
                                        * Referenced by: '<S94>/Out1'
                                        */
  real_T _Value_b;                     /* Expression: 1
                                        * Referenced by: '<S94>/0'
                                        */
  real_T Out1_Y0_cm;                   /* Expression: 0
                                        * Referenced by: '<S97>/Out1'
                                        */
  real_T _Value_i3;                    /* Expression: 0
                                        * Referenced by: '<S97>/0'
                                        */
  real_T Out1_Y0_o4;                   /* Expression: 1
                                        * Referenced by: '<S98>/Out1'
                                        */
  real_T _Value_f;                     /* Expression: 1
                                        * Referenced by: '<S98>/0'
                                        */
  real_T Out1_Y0_mf;                   /* Expression: 0
                                        * Referenced by: '<S111>/Out1'
                                        */
  real_T One_Value_l;                  /* Expression: 1
                                        * Referenced by: '<S111>/One'
                                        */
  real_T Out1_Y0_h0;                   /* Expression: 0
                                        * Referenced by: '<S115>/Out1'
                                        */
  real_T _Value_ll;                    /* Expression: 0
                                        * Referenced by: '<S115>/0'
                                        */
  real_T Out1_Y0_h2;                   /* Expression: 1
                                        * Referenced by: '<S116>/Out1'
                                        */
  real_T _Value_fz;                    /* Expression: 1
                                        * Referenced by: '<S116>/0'
                                        */
  real_T Out1_Y0_ed;                   /* Expression: 0
                                        * Referenced by: '<S119>/Out1'
                                        */
  real_T _Value_i1;                    /* Expression: 0
                                        * Referenced by: '<S119>/0'
                                        */
  real_T Out1_Y0_pz;                   /* Expression: 1
                                        * Referenced by: '<S120>/Out1'
                                        */
  real_T _Value_l5;                    /* Expression: 1
                                        * Referenced by: '<S120>/0'
                                        */
  real_T Out1_Y0_cb;                   /* Expression: 0
                                        * Referenced by: '<S125>/Out1'
                                        */
  real_T _Value_ho;                    /* Expression: 0
                                        * Referenced by: '<S125>/0'
                                        */
  real_T Out1_Y0_i;                    /* Expression: 1
                                        * Referenced by: '<S126>/Out1'
                                        */
  real_T _Value_g;                     /* Expression: 1
                                        * Referenced by: '<S126>/0'
                                        */
  real_T Out1_Y0_lk;                   /* Expression: 0
                                        * Referenced by: '<S129>/Out1'
                                        */
  real_T _Value_pu;                    /* Expression: 0
                                        * Referenced by: '<S129>/0'
                                        */
  real_T Out1_Y0_b;                    /* Expression: 1
                                        * Referenced by: '<S130>/Out1'
                                        */
  real_T _Value_hv;                    /* Expression: 1
                                        * Referenced by: '<S130>/0'
                                        */
  real_T xdata_Value[101];             /* Expression: Xdata
                                        * Referenced by: '<S103>/x data'
                                        */
  real_T Weight_Value;                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S104>/Weight'
                                        */
  real_T left_Value[101];              /* Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(1).params)
                                        * Referenced by: '<S109>/left'
                                        */
  real_T Weight_Value_l;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S105>/Weight'
                                        */
  real_T right_Value[101];             /* Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(2).params)
                                        * Referenced by: '<S109>/right'
                                        */
  real_T Weight_Value_f;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S106>/Weight'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Weight_Value_a;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S107>/Weight'
                                        */
  real_T Zero_Value;                   /* Expression: 0
                                        * Referenced by: '<S102>/Zero'
                                        */
  real_T MidRange_Value;               /* Expression: mean(cat(1,fis.output.range),2)
                                        * Referenced by: '<S102>/MidRange'
                                        */
  real_T Switch_Threshold;             /* Expression: 1
                                        * Referenced by: '<S102>/Switch'
                                        */
  real_T xdata_Value_m[101];           /* Expression: Xdata
                                        * Referenced by: '<S8>/x data'
                                        */
  real_T Weight_Value_b;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S15>/Weight'
                                        */
  real_T neutral_Value[101];           /* Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(2).params)
                                        * Referenced by: '<S12>/neutral'
                                        */
  real_T neutral_Value_h[101];         /* Expression: trimf(linspace(fis.output(2).range(1),fis.output(2).range(2),101),fis.output(2).mf(2).params)
                                        * Referenced by: '<S13>/neutral'
                                        */
  real_T Weight_Value_h;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S16>/Weight'
                                        */
  real_T neutral_Value_he[101];        /* Expression: trimf(linspace(fis.output(3).range(1),fis.output(3).range(2),101),fis.output(3).mf(2).params)
                                        * Referenced by: '<S6>/neutral'
                                        */
  real_T neutral_Value_hb[101];        /* Expression: trimf(linspace(fis.output(4).range(1),fis.output(4).range(2),101),fis.output(4).mf(2).params)
                                        * Referenced by: '<S7>/neutral'
                                        */
  real_T Weight_Value_hu;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S17>/Weight'
                                        */
  real_T reverse_Value[101];           /* Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(1).params)
                                        * Referenced by: '<S12>/reverse'
                                        */
  real_T reverse_Value_b[101];         /* Expression: trimf(linspace(fis.output(2).range(1),fis.output(2).range(2),101),fis.output(2).mf(1).params)
                                        * Referenced by: '<S13>/reverse'
                                        */
  real_T reverse_Value_c[101];         /* Expression: trimf(linspace(fis.output(3).range(1),fis.output(3).range(2),101),fis.output(3).mf(1).params)
                                        * Referenced by: '<S6>/reverse'
                                        */
  real_T reverse_Value_n[101];         /* Expression: trimf(linspace(fis.output(4).range(1),fis.output(4).range(2),101),fis.output(4).mf(1).params)
                                        * Referenced by: '<S7>/reverse'
                                        */
  real_T Weight_Value_bt;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S20>/Weight'
                                        */
  real_T forward_Value[101];           /* Expression: trimf(linspace(fis.output(2).range(1),fis.output(2).range(2),101),fis.output(2).mf(3).params)
                                        * Referenced by: '<S13>/forward'
                                        */
  real_T Weight_Value_fj;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S21>/Weight'
                                        */
  real_T forward_Value_a[101];         /* Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(3).params)
                                        * Referenced by: '<S12>/forward'
                                        */
  real_T Weight_Value_o;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S22>/Weight'
                                        */
  real_T forward_Value_e[101];         /* Expression: trimf(linspace(fis.output(3).range(1),fis.output(3).range(2),101),fis.output(3).mf(3).params)
                                        * Referenced by: '<S6>/forward'
                                        */
  real_T forward_Value_c[101];         /* Expression: trimf(linspace(fis.output(4).range(1),fis.output(4).range(2),101),fis.output(4).mf(3).params)
                                        * Referenced by: '<S7>/forward'
                                        */
  real_T xdata_Value_my[101];          /* Expression: Xdata
                                        * Referenced by: '<S9>/x data'
                                        */
  real_T xdata_Value_i[101];           /* Expression: Xdata
                                        * Referenced by: '<S10>/x data'
                                        */
  real_T Weight_Value_k;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S14>/Weight'
                                        */
  real_T Weight_Value_g;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S18>/Weight'
                                        */
  real_T Weight_Value_j;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S19>/Weight'
                                        */
  real_T xdata_Value_j[101];           /* Expression: Xdata
                                        * Referenced by: '<S11>/x data'
                                        */
  real_T Zero_Value_j;                 /* Expression: 0
                                        * Referenced by: '<S5>/Zero'
                                        */
  real_T MidRange_Value_i[4];          /* Expression: mean(cat(1,fis.output.range),2)
                                        * Referenced by: '<S5>/MidRange'
                                        */
  real_T Switch_Threshold_k;           /* Expression: 1
                                        * Referenced by: '<S5>/Switch'
                                        */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_j;/* '<S124>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_c;/* '<S124>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2;/* '<S123>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3;/* '<S123>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_o;/* '<S114>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_k;/* '<S114>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_e;/* '<S113>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_b;/* '<S113>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_c;/* '<S88>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_l;/* '<S88>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_f;/* '<S87>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_co;/* '<S87>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_pl;/* '<S86>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_g;/* '<S86>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_g;/* '<S77>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_db;/* '<S77>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_p;/* '<S76>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_p;/* '<S76>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_m;/* '<S63>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_m;/* '<S63>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_a;/* '<S62>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_i;/* '<S62>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_l;/* '<S61>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_o;/* '<S61>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_ga;/* '<S52>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_f;/* '<S52>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_b;/* '<S51>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_d;/* '<S51>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_p0;/* '<S38>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_ng;/* '<S38>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_d;/* '<S37>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_a;/* '<S37>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_c0;/* '<S36>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_n;/* '<S36>/If Action Subsystem3' */
};

/* Parameters (auto storage) */
typedef struct P_fuzzyController_T_ P_fuzzyController_T;

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
 * '<S2>'   : 'fuzzyControllerTestBench/fuzzyController/Active Differential'
 * '<S3>'   : 'fuzzyControllerTestBench/fuzzyController/Steering Logic'
 * '<S4>'   : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller'
 * '<S5>'   : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard'
 * '<S6>'   : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/BLWheelOutput'
 * '<S7>'   : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/BRWheelOutput'
 * '<S8>'   : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/Defuzzification1'
 * '<S9>'   : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/Defuzzification2'
 * '<S10>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/Defuzzification3'
 * '<S11>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/Defuzzification4'
 * '<S12>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/FLWheelOutput'
 * '<S13>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/FRWheelOutput'
 * '<S14>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/Rule1'
 * '<S15>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/Rule2'
 * '<S16>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/Rule3'
 * '<S17>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/Rule4'
 * '<S18>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/Rule5'
 * '<S19>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/Rule6'
 * '<S20>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/Rule7'
 * '<S21>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/Rule8'
 * '<S22>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/Rule9'
 * '<S23>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/frontDifferential'
 * '<S24>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/powerBias'
 * '<S25>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/rearDifferential'
 * '<S26>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/steeringSignal'
 * '<S27>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/throttleSignal'
 * '<S28>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/Defuzzification1/Action: One'
 * '<S29>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/Defuzzification1/Action: u1'
 * '<S30>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/Defuzzification2/Action: One'
 * '<S31>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/Defuzzification2/Action: u1'
 * '<S32>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/Defuzzification3/Action: One'
 * '<S33>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/Defuzzification3/Action: u1'
 * '<S34>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/Defuzzification4/Action: One'
 * '<S35>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/Defuzzification4/Action: u1'
 * '<S36>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/frontDifferential/anti'
 * '<S37>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/frontDifferential/loose'
 * '<S38>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/frontDifferential/tight'
 * '<S39>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/frontDifferential/anti/If Action Subsystem'
 * '<S40>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/frontDifferential/anti/If Action Subsystem1'
 * '<S41>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/frontDifferential/anti/If Action Subsystem2'
 * '<S42>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/frontDifferential/anti/If Action Subsystem3'
 * '<S43>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/frontDifferential/loose/If Action Subsystem'
 * '<S44>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/frontDifferential/loose/If Action Subsystem1'
 * '<S45>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/frontDifferential/loose/If Action Subsystem2'
 * '<S46>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/frontDifferential/loose/If Action Subsystem3'
 * '<S47>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/frontDifferential/tight/If Action Subsystem'
 * '<S48>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/frontDifferential/tight/If Action Subsystem1'
 * '<S49>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/frontDifferential/tight/If Action Subsystem2'
 * '<S50>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/frontDifferential/tight/If Action Subsystem3'
 * '<S51>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/powerBias/back'
 * '<S52>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/powerBias/front'
 * '<S53>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/powerBias/back/If Action Subsystem'
 * '<S54>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/powerBias/back/If Action Subsystem1'
 * '<S55>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/powerBias/back/If Action Subsystem2'
 * '<S56>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/powerBias/back/If Action Subsystem3'
 * '<S57>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/powerBias/front/If Action Subsystem'
 * '<S58>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/powerBias/front/If Action Subsystem1'
 * '<S59>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/powerBias/front/If Action Subsystem2'
 * '<S60>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/powerBias/front/If Action Subsystem3'
 * '<S61>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/rearDifferential/anti'
 * '<S62>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/rearDifferential/loose'
 * '<S63>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/rearDifferential/tight'
 * '<S64>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/rearDifferential/anti/If Action Subsystem'
 * '<S65>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/rearDifferential/anti/If Action Subsystem1'
 * '<S66>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/rearDifferential/anti/If Action Subsystem2'
 * '<S67>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/rearDifferential/anti/If Action Subsystem3'
 * '<S68>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/rearDifferential/loose/If Action Subsystem'
 * '<S69>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/rearDifferential/loose/If Action Subsystem1'
 * '<S70>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/rearDifferential/loose/If Action Subsystem2'
 * '<S71>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/rearDifferential/loose/If Action Subsystem3'
 * '<S72>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/rearDifferential/tight/If Action Subsystem'
 * '<S73>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/rearDifferential/tight/If Action Subsystem1'
 * '<S74>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/rearDifferential/tight/If Action Subsystem2'
 * '<S75>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/rearDifferential/tight/If Action Subsystem3'
 * '<S76>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/steeringSignal/left'
 * '<S77>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/steeringSignal/right'
 * '<S78>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/steeringSignal/left/If Action Subsystem'
 * '<S79>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/steeringSignal/left/If Action Subsystem1'
 * '<S80>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/steeringSignal/left/If Action Subsystem2'
 * '<S81>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/steeringSignal/left/If Action Subsystem3'
 * '<S82>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/steeringSignal/right/If Action Subsystem'
 * '<S83>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/steeringSignal/right/If Action Subsystem1'
 * '<S84>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/steeringSignal/right/If Action Subsystem2'
 * '<S85>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/steeringSignal/right/If Action Subsystem3'
 * '<S86>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/throttleSignal/forward'
 * '<S87>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/throttleSignal/neutral'
 * '<S88>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/throttleSignal/reverse'
 * '<S89>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/throttleSignal/forward/If Action Subsystem'
 * '<S90>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/throttleSignal/forward/If Action Subsystem1'
 * '<S91>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/throttleSignal/forward/If Action Subsystem2'
 * '<S92>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/throttleSignal/forward/If Action Subsystem3'
 * '<S93>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/throttleSignal/neutral/If Action Subsystem'
 * '<S94>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/throttleSignal/neutral/If Action Subsystem1'
 * '<S95>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/throttleSignal/neutral/If Action Subsystem2'
 * '<S96>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/throttleSignal/neutral/If Action Subsystem3'
 * '<S97>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/throttleSignal/reverse/If Action Subsystem'
 * '<S98>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/throttleSignal/reverse/If Action Subsystem1'
 * '<S99>'  : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/throttleSignal/reverse/If Action Subsystem2'
 * '<S100>' : 'fuzzyControllerTestBench/fuzzyController/Active Differential/Fuzzy Logic Controller/FIS Wizard/throttleSignal/reverse/If Action Subsystem3'
 * '<S101>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller'
 * '<S102>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard'
 * '<S103>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/Defuzzification1'
 * '<S104>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/Rule1'
 * '<S105>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/Rule2'
 * '<S106>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/Rule3'
 * '<S107>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/Rule4'
 * '<S108>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/gyroYaw'
 * '<S109>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/steeringOutput'
 * '<S110>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/steeringSignal'
 * '<S111>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/Defuzzification1/Action: One'
 * '<S112>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/Defuzzification1/Action: u1'
 * '<S113>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CCW'
 * '<S114>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CW'
 * '<S115>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CCW/If Action Subsystem'
 * '<S116>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CCW/If Action Subsystem1'
 * '<S117>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CCW/If Action Subsystem2'
 * '<S118>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CCW/If Action Subsystem3'
 * '<S119>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CW/If Action Subsystem'
 * '<S120>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CW/If Action Subsystem1'
 * '<S121>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CW/If Action Subsystem2'
 * '<S122>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CW/If Action Subsystem3'
 * '<S123>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/steeringSignal/left'
 * '<S124>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/steeringSignal/right'
 * '<S125>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/steeringSignal/left/If Action Subsystem'
 * '<S126>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/steeringSignal/left/If Action Subsystem1'
 * '<S127>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/steeringSignal/left/If Action Subsystem2'
 * '<S128>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/steeringSignal/left/If Action Subsystem3'
 * '<S129>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/steeringSignal/right/If Action Subsystem'
 * '<S130>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/steeringSignal/right/If Action Subsystem1'
 * '<S131>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/steeringSignal/right/If Action Subsystem2'
 * '<S132>' : 'fuzzyControllerTestBench/fuzzyController/Steering Logic/Fuzzy Logic Controller/FIS Wizard/steeringSignal/right/If Action Subsystem3'
 */
#endif                                 /* RTW_HEADER_fuzzyController_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
