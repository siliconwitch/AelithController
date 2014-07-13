/*
 * File: fuzzyController_private.h
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

#ifndef RTW_HEADER_fuzzyController_private_h_
#define RTW_HEADER_fuzzyController_private_h_
#include "rtwtypes.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

extern void fuzzyController_Actionu1(real_T rtu_0, real_T *rty_u2);
extern void fuzzyControl_IfActionSubsystem3(real_T rtu_x, real_T *rty_Out1,
  P_IfActionSubsystem3_fuzzyCon_T *localP);
extern void fuzzyControl_IfActionSubsystem2(real_T rtu_x, real_T *rty_Out1,
  P_IfActionSubsystem2_fuzzyCon_T *localP);

#endif                                 /* RTW_HEADER_fuzzyController_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
