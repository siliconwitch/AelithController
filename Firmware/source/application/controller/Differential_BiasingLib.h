#ifndef _Differential_BiasingLib_h
#define _Differential_BiasingLib_h

#include "LVDefs_plat.h"

#ifndef CGEN_LIBFUNC_PREFIX 
#define CGEN_LIBFUNC_PREFIX 
#endif 
#ifndef  CGEN_LIBFUNC_CALL 
#define  CGEN_LIBFUNC_CALL 
#endif

#ifdef __cplusplus 
extern "C" { 
#endif

CGEN_LIBFUNC_PREFIX void CGEN_LIBFUNC_CALL DifferentialBiasing(float32 FrontSlip2,			/* Input */
		float32 FrontPowerBias2,			/* Input */
		float32 RearPowerBias2,			/* Input */
		float32 RearSlip2,			/* Input */
		float32 Steering2,			/* Input */
		float32 Throttle2,			/* Input */
		float32 *WheelFL2,			/* Output */
		float32 *WheelFR2,			/* Output */
		float32 *WheelBL2,			/* Output */
		float32 *WheelBR2);			/* Output */

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* _Differential_BiasingLib_h */
