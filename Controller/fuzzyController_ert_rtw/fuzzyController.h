/*
 * File: fuzzyController.h
 *
 * Code generated for Simulink model 'fuzzyController'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Tue Jul 15 21:10:01 2014
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
  real_T impMethod_g[404];             /* '<S22>/impMethod' */
  real_T impMethod_f[404];             /* '<S23>/impMethod' */
  real_T impMethod_e[404];             /* '<S16>/impMethod' */
  real_T impMethod_l[202];             /* '<S25>/impMethod' */
  real_T impMethod_i[202];             /* '<S24>/impMethod' */
  real_T impMethod_p[202];             /* '<S20>/impMethod' */
  real_T impMethod[101];               /* '<S14>/impMethod' */
  real_T impMethod_b[101];             /* '<S19>/impMethod' */
  real_T impMethod_m[101];             /* '<S17>/impMethod' */
  real_T TmpSignalConversionAtAnimation1[6];
  real_T Switch[5];                    /* '<S4>/Switch' */
  real_T Weighting;                    /* '<S14>/Weighting' */
  real_T Weighting_h;                  /* '<S19>/Weighting' */
  real_T Weighting_oc;                 /* '<S17>/Weighting' */
  real_T Weighting_a;                  /* '<S18>/Weighting' */
  real_T Weighting_i;                  /* '<S21>/Weighting' */
  real_T Weighting_o;                  /* '<S22>/Weighting' */
  real_T Weighting_l;                  /* '<S23>/Weighting' */
  real_T Weighting_c;                  /* '<S26>/Weighting' */
  real_T Weighting_m5;                 /* '<S15>/Weighting' */
  real_T Weighting_m;                  /* '<S16>/Weighting' */
  real_T AveragingCOA_l;               /* '<S8>/Averaging (COA)' */
  real_T AveragingCOA_b;               /* '<S9>/Averaging (COA)' */
  real_T Weighting_k;                  /* '<S20>/Weighting' */
  real_T Weighting_ae;                 /* '<S24>/Weighting' */
  real_T ZeroFiringStrength;           /* '<S4>/Zero Firing Strength?' */
  real_T AveragingCOA_f;               /* '<S10>/Averaging (COA)' */
  real_T AveragingCOA_a;               /* '<S11>/Averaging (COA)' */
  real_T Sum;                          /* '<S7>/Sum' */
  real_T Merge;                        /* '<S94>/Merge' */
  real_T Merge_h;                      /* '<S95>/Merge' */
  real_T Sum1;                         /* '<S7>/Sum1' */
  real_T Merge_m;                      /* '<S69>/Merge' */
  real_T Merge_k;                      /* '<S105>/Merge' */
  real_T Merge_j5;                     /* '<S106>/Merge' */
  real_T Merge_o;                      /* '<S104>/Merge' */
  real_T Sum1_l;                       /* '<S8>/Sum1' */
  real_T Merge_i;                      /* '<S8>/Merge' */
  real_T Sum1_h;                       /* '<S9>/Sum1' */
  real_T Merge_ic;                     /* '<S9>/Merge' */
  real_T Merge_n1;                     /* '<S70>/Merge' */
  real_T Sum1_b;                       /* '<S10>/Sum1' */
  real_T Merge_cf;                     /* '<S10>/Merge' */
  real_T Sum1_a;                       /* '<S11>/Sum1' */
  real_T Merge_kq;                     /* '<S11>/Merge' */
  real_T Merge_d;                      /* '<S60>/Merge' */
  real_T Merge_n;                      /* '<S59>/Merge' */
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

/* Parameters for system: '<S44>/If Action Subsystem3' */
struct P_IfActionSubsystem3_fuzzyCon_T_ {
  real_T a_Value;                      /* Expression: a
                                        * Referenced by: '<S50>/a'
                                        */
  real_T b_Value;                      /* Expression: b
                                        * Referenced by: '<S50>/b'
                                        */
};

/* Parameters for system: '<S44>/If Action Subsystem3' */
typedef struct P_IfActionSubsystem3_fuzzyCon_T_ P_IfActionSubsystem3_fuzzyCon_T;

/* Parameters for system: '<S44>/If Action Subsystem2' */
struct P_IfActionSubsystem2_fuzzyCon_T_ {
  real_T b_Value;                      /* Expression: b
                                        * Referenced by: '<S49>/b'
                                        */
  real_T c_Value;                      /* Expression: c
                                        * Referenced by: '<S49>/c'
                                        */
};

/* Parameters for system: '<S44>/If Action Subsystem2' */
typedef struct P_IfActionSubsystem2_fuzzyCon_T_ P_IfActionSubsystem2_fuzzyCon_T;

/* Parameters (auto storage) */
struct P_fuzzyController_T_ {
  real_T Out1_Y0;                      /* Expression: 0
                                        * Referenced by: '<S34>/Out1'
                                        */
  real_T One_Value;                    /* Expression: 1
                                        * Referenced by: '<S34>/One'
                                        */
  real_T Out1_Y0_n;                    /* Expression: 0
                                        * Referenced by: '<S36>/Out1'
                                        */
  real_T One_Value_n;                  /* Expression: 1
                                        * Referenced by: '<S36>/One'
                                        */
  real_T Out1_Y0_a;                    /* Expression: 0
                                        * Referenced by: '<S38>/Out1'
                                        */
  real_T One_Value_g;                  /* Expression: 1
                                        * Referenced by: '<S38>/One'
                                        */
  real_T Out1_Y0_f;                    /* Expression: 0
                                        * Referenced by: '<S40>/Out1'
                                        */
  real_T One_Value_o;                  /* Expression: 1
                                        * Referenced by: '<S40>/One'
                                        */
  real_T Out1_Y0_k;                    /* Expression: 0
                                        * Referenced by: '<S42>/Out1'
                                        */
  real_T One_Value_e;                  /* Expression: 1
                                        * Referenced by: '<S42>/One'
                                        */
  real_T Out1_Y0_j;                    /* Expression: 0
                                        * Referenced by: '<S47>/Out1'
                                        */
  real_T _Value;                       /* Expression: 0
                                        * Referenced by: '<S47>/0'
                                        */
  real_T Out1_Y0_l;                    /* Expression: 1
                                        * Referenced by: '<S48>/Out1'
                                        */
  real_T _Value_n;                     /* Expression: 1
                                        * Referenced by: '<S48>/0'
                                        */
  real_T Out1_Y0_e;                    /* Expression: 0
                                        * Referenced by: '<S51>/Out1'
                                        */
  real_T _Value_i;                     /* Expression: 0
                                        * Referenced by: '<S51>/0'
                                        */
  real_T Out1_Y0_h;                    /* Expression: 1
                                        * Referenced by: '<S52>/Out1'
                                        */
  real_T _Value_h;                     /* Expression: 1
                                        * Referenced by: '<S52>/0'
                                        */
  real_T Out1_Y0_fs;                   /* Expression: 0
                                        * Referenced by: '<S55>/Out1'
                                        */
  real_T _Value_o;                     /* Expression: 0
                                        * Referenced by: '<S55>/0'
                                        */
  real_T Out1_Y0_c;                    /* Expression: 1
                                        * Referenced by: '<S56>/Out1'
                                        */
  real_T _Value_m;                     /* Expression: 1
                                        * Referenced by: '<S56>/0'
                                        */
  real_T Out1_Y0_d;                    /* Expression: 0
                                        * Referenced by: '<S61>/Out1'
                                        */
  real_T _Value_p;                     /* Expression: 0
                                        * Referenced by: '<S61>/0'
                                        */
  real_T Out1_Y0_nz;                   /* Expression: 1
                                        * Referenced by: '<S62>/Out1'
                                        */
  real_T _Value_c;                     /* Expression: 1
                                        * Referenced by: '<S62>/0'
                                        */
  real_T Out1_Y0_i;                    /* Expression: 0
                                        * Referenced by: '<S65>/Out1'
                                        */
  real_T _Value_a;                     /* Expression: 0
                                        * Referenced by: '<S65>/0'
                                        */
  real_T Out1_Y0_n3;                   /* Expression: 1
                                        * Referenced by: '<S66>/Out1'
                                        */
  real_T _Value_oz;                    /* Expression: 1
                                        * Referenced by: '<S66>/0'
                                        */
  real_T Out1_Y0_et;                   /* Expression: 0
                                        * Referenced by: '<S71>/Out1'
                                        */
  real_T _Value_e;                     /* Expression: 0
                                        * Referenced by: '<S71>/0'
                                        */
  real_T Out1_Y0_m;                    /* Expression: 1
                                        * Referenced by: '<S72>/Out1'
                                        */
  real_T _Value_p0;                    /* Expression: 1
                                        * Referenced by: '<S72>/0'
                                        */
  real_T Out1_Y0_jy;                   /* Expression: 0
                                        * Referenced by: '<S75>/Out1'
                                        */
  real_T _Value_j;                     /* Expression: 0
                                        * Referenced by: '<S75>/0'
                                        */
  real_T Out1_Y0_cy;                   /* Expression: 1
                                        * Referenced by: '<S76>/Out1'
                                        */
  real_T _Value_mx;                    /* Expression: 1
                                        * Referenced by: '<S76>/0'
                                        */
  real_T Out1_Y0_f4;                   /* Expression: 0
                                        * Referenced by: '<S82>/Out1'
                                        */
  real_T _Value_mg;                    /* Expression: 0
                                        * Referenced by: '<S82>/0'
                                        */
  real_T Out1_Y0_ex;                   /* Expression: 1
                                        * Referenced by: '<S83>/Out1'
                                        */
  real_T _Value_iq;                    /* Expression: 1
                                        * Referenced by: '<S83>/0'
                                        */
  real_T Out1_Y0_g;                    /* Expression: 0
                                        * Referenced by: '<S86>/Out1'
                                        */
  real_T _Value_d;                     /* Expression: 0
                                        * Referenced by: '<S86>/0'
                                        */
  real_T Out1_Y0_kq;                   /* Expression: 1
                                        * Referenced by: '<S87>/Out1'
                                        */
  real_T _Value_no;                    /* Expression: 1
                                        * Referenced by: '<S87>/0'
                                        */
  real_T Out1_Y0_fsc;                  /* Expression: 0
                                        * Referenced by: '<S90>/Out1'
                                        */
  real_T _Value_l;                     /* Expression: 0
                                        * Referenced by: '<S90>/0'
                                        */
  real_T Out1_Y0_lc;                   /* Expression: 1
                                        * Referenced by: '<S91>/Out1'
                                        */
  real_T _Value_in;                    /* Expression: 1
                                        * Referenced by: '<S91>/0'
                                        */
  real_T Out1_Y0_kz;                   /* Expression: 0
                                        * Referenced by: '<S96>/Out1'
                                        */
  real_T _Value_pq;                    /* Expression: 0
                                        * Referenced by: '<S96>/0'
                                        */
  real_T Out1_Y0_cp;                   /* Expression: 1
                                        * Referenced by: '<S97>/Out1'
                                        */
  real_T _Value_ar;                    /* Expression: 1
                                        * Referenced by: '<S97>/0'
                                        */
  real_T Out1_Y0_nzd;                  /* Expression: 0
                                        * Referenced by: '<S100>/Out1'
                                        */
  real_T _Value_n4;                    /* Expression: 0
                                        * Referenced by: '<S100>/0'
                                        */
  real_T Out1_Y0_n3l;                  /* Expression: 1
                                        * Referenced by: '<S101>/Out1'
                                        */
  real_T _Value_py;                    /* Expression: 1
                                        * Referenced by: '<S101>/0'
                                        */
  real_T Out1_Y0_p;                    /* Expression: 0
                                        * Referenced by: '<S107>/Out1'
                                        */
  real_T _Value_aj;                    /* Expression: 0
                                        * Referenced by: '<S107>/0'
                                        */
  real_T Out1_Y0_hv;                   /* Expression: 1
                                        * Referenced by: '<S108>/Out1'
                                        */
  real_T _Value_ju;                    /* Expression: 1
                                        * Referenced by: '<S108>/0'
                                        */
  real_T Out1_Y0_o;                    /* Expression: 0
                                        * Referenced by: '<S111>/Out1'
                                        */
  real_T _Value_af;                    /* Expression: 0
                                        * Referenced by: '<S111>/0'
                                        */
  real_T Out1_Y0_cw;                   /* Expression: 1
                                        * Referenced by: '<S112>/Out1'
                                        */
  real_T _Value_b;                     /* Expression: 1
                                        * Referenced by: '<S112>/0'
                                        */
  real_T Out1_Y0_cm;                   /* Expression: 0
                                        * Referenced by: '<S115>/Out1'
                                        */
  real_T _Value_i3;                    /* Expression: 0
                                        * Referenced by: '<S115>/0'
                                        */
  real_T Out1_Y0_o4;                   /* Expression: 1
                                        * Referenced by: '<S116>/Out1'
                                        */
  real_T _Value_f;                     /* Expression: 1
                                        * Referenced by: '<S116>/0'
                                        */
  real_T xdata_Value[101];             /* Expression: Xdata
                                        * Referenced by: '<S7>/x data'
                                        */
  real_T Weight_Value;                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S14>/Weight'
                                        */
  real_T left_Value[101];              /* Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(1).params)
                                        * Referenced by: '<S31>/left'
                                        */
  real_T Weight_Value_b;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S19>/Weight'
                                        */
  real_T right_Value[101];             /* Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(2).params)
                                        * Referenced by: '<S31>/right'
                                        */
  real_T Weight_Value_j;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S17>/Weight'
                                        */
  real_T Weight_Value_f;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S18>/Weight'
                                        */
  real_T xdata_Value_m[101];           /* Expression: Xdata
                                        * Referenced by: '<S8>/x data'
                                        */
  real_T Weight_Value_h;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S21>/Weight'
                                        */
  real_T neutral_Value[101];           /* Expression: trimf(linspace(fis.output(2).range(1),fis.output(2).range(2),101),fis.output(2).mf(2).params)
                                        * Referenced by: '<S12>/neutral'
                                        */
  real_T neutral_Value_h[101];         /* Expression: trimf(linspace(fis.output(3).range(1),fis.output(3).range(2),101),fis.output(3).mf(2).params)
                                        * Referenced by: '<S13>/neutral'
                                        */
  real_T Weight_Value_g;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S22>/Weight'
                                        */
  real_T neutral_Value_he[101];        /* Expression: trimf(linspace(fis.output(4).range(1),fis.output(4).range(2),101),fis.output(4).mf(2).params)
                                        * Referenced by: '<S5>/neutral'
                                        */
  real_T neutral_Value_hb[101];        /* Expression: trimf(linspace(fis.output(5).range(1),fis.output(5).range(2),101),fis.output(5).mf(2).params)
                                        * Referenced by: '<S6>/neutral'
                                        */
  real_T Weight_Value_jg;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S23>/Weight'
                                        */
  real_T reverse_Value[101];           /* Expression: trimf(linspace(fis.output(2).range(1),fis.output(2).range(2),101),fis.output(2).mf(1).params)
                                        * Referenced by: '<S12>/reverse'
                                        */
  real_T reverse_Value_b[101];         /* Expression: trimf(linspace(fis.output(3).range(1),fis.output(3).range(2),101),fis.output(3).mf(1).params)
                                        * Referenced by: '<S13>/reverse'
                                        */
  real_T reverse_Value_c[101];         /* Expression: trimf(linspace(fis.output(4).range(1),fis.output(4).range(2),101),fis.output(4).mf(1).params)
                                        * Referenced by: '<S5>/reverse'
                                        */
  real_T reverse_Value_n[101];         /* Expression: trimf(linspace(fis.output(5).range(1),fis.output(5).range(2),101),fis.output(5).mf(1).params)
                                        * Referenced by: '<S6>/reverse'
                                        */
  real_T Weight_Value_o;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S26>/Weight'
                                        */
  real_T forward_Value[101];           /* Expression: trimf(linspace(fis.output(3).range(1),fis.output(3).range(2),101),fis.output(3).mf(3).params)
                                        * Referenced by: '<S13>/forward'
                                        */
  real_T Weight_Value_ou;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S15>/Weight'
                                        */
  real_T forward_Value_a[101];         /* Expression: trimf(linspace(fis.output(2).range(1),fis.output(2).range(2),101),fis.output(2).mf(3).params)
                                        * Referenced by: '<S12>/forward'
                                        */
  real_T Weight_Value_p;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S16>/Weight'
                                        */
  real_T forward_Value_e[101];         /* Expression: trimf(linspace(fis.output(4).range(1),fis.output(4).range(2),101),fis.output(4).mf(3).params)
                                        * Referenced by: '<S5>/forward'
                                        */
  real_T forward_Value_c[101];         /* Expression: trimf(linspace(fis.output(5).range(1),fis.output(5).range(2),101),fis.output(5).mf(3).params)
                                        * Referenced by: '<S6>/forward'
                                        */
  real_T xdata_Value_i[101];           /* Expression: Xdata
                                        * Referenced by: '<S9>/x data'
                                        */
  real_T xdata_Value_j[101];           /* Expression: Xdata
                                        * Referenced by: '<S10>/x data'
                                        */
  real_T Weight_Value_hi;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S20>/Weight'
                                        */
  real_T Weight_Value_bt;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S24>/Weight'
                                        */
  real_T Weight_Value_fj;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S25>/Weight'
                                        */
  real_T xdata_Value_f[101];           /* Expression: Xdata
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
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_c;/* '<S106>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_l;/* '<S106>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_f;/* '<S105>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_co;/* '<S105>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_p;/* '<S104>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_g;/* '<S104>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_g;/* '<S95>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_d;/* '<S95>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2;/* '<S94>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3;/* '<S94>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_m;/* '<S81>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_m;/* '<S81>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_a;/* '<S80>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_i;/* '<S80>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_l;/* '<S79>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_o;/* '<S79>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_ga;/* '<S70>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_f;/* '<S70>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_b;/* '<S69>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_d1;/* '<S69>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_go;/* '<S60>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_c;/* '<S60>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_k;/* '<S59>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_j;/* '<S59>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_p0;/* '<S46>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_ng;/* '<S46>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_d;/* '<S45>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_a;/* '<S45>/If Action Subsystem3' */
  P_IfActionSubsystem2_fuzzyCon_T IfActionSubsystem2_c0;/* '<S44>/If Action Subsystem2' */
  P_IfActionSubsystem3_fuzzyCon_T IfActionSubsystem3_n;/* '<S44>/If Action Subsystem3' */
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
 * '<S18>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Rule13'
 * '<S19>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Rule2'
 * '<S20>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Rule3'
 * '<S21>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Rule4'
 * '<S22>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Rule5'
 * '<S23>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Rule6'
 * '<S24>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Rule7'
 * '<S25>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Rule8'
 * '<S26>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Rule9'
 * '<S27>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential'
 * '<S28>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw'
 * '<S29>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias'
 * '<S30>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential'
 * '<S31>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringOutput'
 * '<S32>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal'
 * '<S33>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal'
 * '<S34>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Defuzzification1/Action: One'
 * '<S35>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Defuzzification1/Action: u1'
 * '<S36>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Defuzzification2/Action: One'
 * '<S37>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Defuzzification2/Action: u1'
 * '<S38>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Defuzzification3/Action: One'
 * '<S39>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Defuzzification3/Action: u1'
 * '<S40>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Defuzzification4/Action: One'
 * '<S41>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Defuzzification4/Action: u1'
 * '<S42>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Defuzzification5/Action: One'
 * '<S43>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/Defuzzification5/Action: u1'
 * '<S44>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/anti'
 * '<S45>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/loose'
 * '<S46>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/tight'
 * '<S47>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/anti/If Action Subsystem'
 * '<S48>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/anti/If Action Subsystem1'
 * '<S49>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/anti/If Action Subsystem2'
 * '<S50>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/anti/If Action Subsystem3'
 * '<S51>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/loose/If Action Subsystem'
 * '<S52>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/loose/If Action Subsystem1'
 * '<S53>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/loose/If Action Subsystem2'
 * '<S54>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/loose/If Action Subsystem3'
 * '<S55>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/tight/If Action Subsystem'
 * '<S56>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/tight/If Action Subsystem1'
 * '<S57>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/tight/If Action Subsystem2'
 * '<S58>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/frontDifferential/tight/If Action Subsystem3'
 * '<S59>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CCW'
 * '<S60>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CW'
 * '<S61>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CCW/If Action Subsystem'
 * '<S62>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CCW/If Action Subsystem1'
 * '<S63>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CCW/If Action Subsystem2'
 * '<S64>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CCW/If Action Subsystem3'
 * '<S65>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CW/If Action Subsystem'
 * '<S66>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CW/If Action Subsystem1'
 * '<S67>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CW/If Action Subsystem2'
 * '<S68>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/gyroYaw/CW/If Action Subsystem3'
 * '<S69>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias/back'
 * '<S70>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias/front'
 * '<S71>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias/back/If Action Subsystem'
 * '<S72>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias/back/If Action Subsystem1'
 * '<S73>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias/back/If Action Subsystem2'
 * '<S74>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias/back/If Action Subsystem3'
 * '<S75>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias/front/If Action Subsystem'
 * '<S76>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias/front/If Action Subsystem1'
 * '<S77>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias/front/If Action Subsystem2'
 * '<S78>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/powerBias/front/If Action Subsystem3'
 * '<S79>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/anti'
 * '<S80>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/loose'
 * '<S81>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/tight'
 * '<S82>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/anti/If Action Subsystem'
 * '<S83>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/anti/If Action Subsystem1'
 * '<S84>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/anti/If Action Subsystem2'
 * '<S85>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/anti/If Action Subsystem3'
 * '<S86>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/loose/If Action Subsystem'
 * '<S87>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/loose/If Action Subsystem1'
 * '<S88>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/loose/If Action Subsystem2'
 * '<S89>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/loose/If Action Subsystem3'
 * '<S90>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/tight/If Action Subsystem'
 * '<S91>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/tight/If Action Subsystem1'
 * '<S92>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/tight/If Action Subsystem2'
 * '<S93>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/rearDifferential/tight/If Action Subsystem3'
 * '<S94>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal/left'
 * '<S95>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal/right'
 * '<S96>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal/left/If Action Subsystem'
 * '<S97>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal/left/If Action Subsystem1'
 * '<S98>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal/left/If Action Subsystem2'
 * '<S99>'  : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal/left/If Action Subsystem3'
 * '<S100>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal/right/If Action Subsystem'
 * '<S101>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal/right/If Action Subsystem1'
 * '<S102>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal/right/If Action Subsystem2'
 * '<S103>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/steeringSignal/right/If Action Subsystem3'
 * '<S104>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/forward'
 * '<S105>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/neutral'
 * '<S106>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/reverse'
 * '<S107>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/forward/If Action Subsystem'
 * '<S108>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/forward/If Action Subsystem1'
 * '<S109>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/forward/If Action Subsystem2'
 * '<S110>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/forward/If Action Subsystem3'
 * '<S111>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/neutral/If Action Subsystem'
 * '<S112>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/neutral/If Action Subsystem1'
 * '<S113>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/neutral/If Action Subsystem2'
 * '<S114>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/neutral/If Action Subsystem3'
 * '<S115>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/reverse/If Action Subsystem'
 * '<S116>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/reverse/If Action Subsystem1'
 * '<S117>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/reverse/If Action Subsystem2'
 * '<S118>' : 'fuzzyControllerTestBench/fuzzyController/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/FIS Wizard/throttleSignal/reverse/If Action Subsystem3'
 */
#endif                                 /* RTW_HEADER_fuzzyController_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
