/*
 * File: Differential.h
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

#ifndef RTW_HEADER_Differential_h_
#define RTW_HEADER_Differential_h_
#ifndef Differential_COMMON_INCLUDES_
# define Differential_COMMON_INCLUDES_
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* Differential_COMMON_INCLUDES_ */

#include "Differential_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T frontpowerbias;               /* '<Root>/In1' */
  real_T frontslip;                    /* '<Root>/In2' */
  real_T rearpowerbias;                /* '<Root>/In3' */
  real_T rearslip;                     /* '<Root>/In4' */
  real_T steering;                     /* '<Root>/In5' */
  real_T throttle;                     /* '<Root>/In6' */
} ExtU_Differential_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
  real_T Out2;                         /* '<Root>/Out2' */
  real_T Out3;                         /* '<Root>/Out3' */
  real_T Out4;                         /* '<Root>/Out4' */
} ExtY_Differential_T;

/* Parameters (auto storage) */
struct P_Differential_T_ {
  real_T Bias_Bias;                    /* Expression: 1
                                        * Referenced by: '<Root>/Bias'
                                        */
  real_T Constant_Value;               /* Expression: -1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Bias1_Bias;                   /* Expression: 1
                                        * Referenced by: '<Root>/Bias1'
                                        */
  real_T Bias2_Bias;                   /* Expression: 1
                                        * Referenced by: '<Root>/Bias2'
                                        */
  real_T Bias3_Bias;                   /* Expression: 1
                                        * Referenced by: '<Root>/Bias3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Differential_T {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern P_Differential_T Differential_P;

/* External inputs (root inport signals with auto storage) */
extern ExtU_Differential_T Differential_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Differential_T Differential_Y;

/* Model entry point functions */
extern void Differential_initialize(void);
extern void Differential_step(void);

/* Real-time Model object */
extern RT_MODEL_Differential_T *const Differential_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Differential'
 */
#endif                                 /* RTW_HEADER_Differential_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
