/*
 * File: differentialBiasing.h
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

#ifndef RTW_HEADER_differentialBiasing_h_
#define RTW_HEADER_differentialBiasing_h_
#ifndef differentialBiasing_COMMON_INCLUDES_
# define differentialBiasing_COMMON_INCLUDES_
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* differentialBiasing_COMMON_INCLUDES_ */

#include "differentialBiasing_types.h"

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
  real_T throttle;                     /* '<Root>/throttle' */
  real_T frontpowerbias;               /* '<Root>/frontpowerbias' */
  real_T rearpowerbias;                /* '<Root>/rearpowerbias' */
  real_T steering;                     /* '<Root>/steering' */
  real_T frontslip;                    /* '<Root>/frontslip' */
  real_T rearslip;                     /* '<Root>/rearslip' */
} ExtU_differentialBiasing_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T FLWheel;                      /* '<Root>/FLWheel' */
  real_T FRWheel;                      /* '<Root>/FRWheel' */
  real_T BLWheel;                      /* '<Root>/BLWheel' */
  real_T BRWheel;                      /* '<Root>/BRWheel' */
} ExtY_differentialBiasing_T;

/* Parameters (auto storage) */
struct P_differentialBiasing_T_ {
  real_T Bias_Bias;                    /* Expression: 1
                                        * Referenced by: '<S1>/Bias'
                                        */
  real_T Constant_Value;               /* Expression: -1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Bias1_Bias;                   /* Expression: 1
                                        * Referenced by: '<S1>/Bias1'
                                        */
  real_T Bias2_Bias;                   /* Expression: 1
                                        * Referenced by: '<S1>/Bias2'
                                        */
  real_T Bias3_Bias;                   /* Expression: 1
                                        * Referenced by: '<S1>/Bias3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_differentialBiasing_T {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern P_differentialBiasing_T differentialBiasing_P;

/* External inputs (root inport signals with auto storage) */
extern ExtU_differentialBiasing_T differentialBiasing_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_differentialBiasing_T differentialBiasing_Y;

/* Model entry point functions */
extern void differentialBiasing_initialize(void);
extern void differentialBiasing_step(void);

/* Real-time Model object */
extern RT_MODEL_differentialBiasing_T *const differentialBiasing_M;

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
 * hilite_system('topController/differentialBiasing')    - opens subsystem topController/differentialBiasing
 * hilite_system('topController/differentialBiasing/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'topController'
 * '<S1>'   : 'topController/differentialBiasing'
 */
#endif                                 /* RTW_HEADER_differentialBiasing_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
