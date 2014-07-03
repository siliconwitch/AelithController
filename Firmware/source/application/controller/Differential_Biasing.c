/****************************************************************************************
 *	LabVIEW (TM) Code Generator 13.0f2
 *	(C) Copyright 1997-2011 by National Instruments Corp.
 *	All rights reserved.
 *	Delimited VI name: Differential Biasing.vi
 *	Generated from: C:\Users\Raj\Documents\GitHub\AelithController\Control System\Differential Biasing.vi
 *  Generated UI: false
 *  Generated Debug Info: false
 *  Generated Serial Only: true
 *  Generated Stack Variables: false
 *  Generated Guard Code: true
 *  Generated Interrupt Code: false
 *  Generated C Function Calls: true
 *  Generated Integer Only : false
 *  Generated Expression Folding : true
 *  Generated memory model: dynamic
*****************************************************************************************/
#define LV_MAIN
#include "LVCGenIncludes.h"
#include "Differential_BiasingLib.h"
#if CGEN_VERSION != 13000
#error CGenerator version mismatch
#endif
/* VI heap data */
struct _Differential_Biasing_heap { 
	int32 l_Constant;
	float32 n_Rear_Slip_2;
	float32 n_Rear_Power_Bias_2;
	float32 n_Front_Power_Bias_2;
	float32 n_Multiply_x_y;
	float32 n_Multiply_x_y_1;
	float32 n_Increment_x_1;
	float32 n_Multiply_x_y_2;
	float32 n_Increment_x_1_1;
	float32 n_Increment_x_1_2;
	float32 n_Increment_x_1_3;
	float32 n_Multiply_x_y_3;
	float32 n_Multiply_x_y_4;
	float32 n_Multiply_x_y_5;
	float32 n_Multiply_x_y_6;
	float32 n_Multiply_x_y_7;
	float32 n_Multiply_x_y_8;
	float32 n_Multiply_x_y_9;
	float32 n_Front_Slip_2;
	float32 n_Steering_2;
	float32 n_Throttle_2;
} _DATA_SECTION __Differential_Biasing_heap; /* heap */

static struct _Differential_Biasing_heap _DATA_SECTION *heap = &__Differential_Biasing_heap; /* heap */



/****** Clean Up Uninitialized Left Shift Registers before program exits to prevent memory leaks **********/


void _TEXT_SECTION Differential_Biasing_CleanupLSRs(void);
void _TEXT_SECTION Differential_Biasing_CleanupLSRs(void) {
}


/****** Add Sub VI Instance Data to global list **********/


void _TEXT_SECTION Differential_Biasing_AddSubVIInstanceData(void);
void _TEXT_SECTION Differential_Biasing_AddSubVIInstanceData(void) {
}


/****** Allocate VI Constants  **********/


void _TEXT_SECTION Differential_Biasing_AddVIGlobalConstants(void);
void _TEXT_SECTION Differential_Biasing_AddVIGlobalConstants(void) {
}


/****** VI Constant Initialization function **********/


void _TEXT_SECTION Differential_Biasing_InitVIConstantList(void);
void _TEXT_SECTION Differential_Biasing_InitVIConstantList(void) {
}


/****** Block diagram code **********/


float32 Differential_Biasing_out_2_Wheel_FR_2_135_init_ = 0.0000000000000000000E+0 ;
static float32* Differential_Biasing_out_2_Wheel_FR_2_135 = &Differential_Biasing_out_2_Wheel_FR_2_135_init_;
static DataType dtDifferential_Biasing_out_2_Wheel_FR_2_135 = floatDataType;
float32 Differential_Biasing_out_3_Wheel_FL_2_15F_init_ = 0.0000000000000000000E+0 ;
static float32* Differential_Biasing_out_3_Wheel_FL_2_15F = &Differential_Biasing_out_3_Wheel_FL_2_15F_init_;
static DataType dtDifferential_Biasing_out_3_Wheel_FL_2_15F = floatDataType;
float32 Differential_Biasing_out_0_Wheel_BR_2_17D_init_ = 1.0000000000000000000E+0 ;
static float32* Differential_Biasing_out_0_Wheel_BR_2_17D = &Differential_Biasing_out_0_Wheel_BR_2_17D_init_;
static DataType dtDifferential_Biasing_out_0_Wheel_BR_2_17D = floatDataType;
float32 Differential_Biasing_out_1_Wheel_BL_2_19C_init_ = 0.0000000000000000000E+0 ;
static float32* Differential_Biasing_out_1_Wheel_BL_2_19C = &Differential_Biasing_out_1_Wheel_BL_2_19C_init_;
static DataType dtDifferential_Biasing_out_1_Wheel_BL_2_19C = floatDataType;
float32 Differential_Biasing_in_1_Steering_2_1BA_init_ = 0.0000000000000000000E+0 ;
static float32* Differential_Biasing_in_1_Steering_2_1BA = &Differential_Biasing_in_1_Steering_2_1BA_init_;
static DataType dtDifferential_Biasing_in_1_Steering_2_1BA = floatDataType;
float32 Differential_Biasing_in_0_Throttle_2_1D7_init_ = 0.0000000000000000000E+0 ;
static float32* Differential_Biasing_in_0_Throttle_2_1D7 = &Differential_Biasing_in_0_Throttle_2_1D7_init_;
static DataType dtDifferential_Biasing_in_0_Throttle_2_1D7 = floatDataType;
float32 Differential_Biasing_in_4_Front_Power_Bias_2_1F7_init_ = 0.0000000000000000000E+0 ;
static float32* Differential_Biasing_in_4_Front_Power_Bias_2_1F7 = &Differential_Biasing_in_4_Front_Power_Bias_2_1F7_init_;
static DataType dtDifferential_Biasing_in_4_Front_Power_Bias_2_1F7 = floatDataType;
float32 Differential_Biasing_in_3_Rear_Power_Bias_2_206_init_ = 0.0000000000000000000E+0 ;
static float32* Differential_Biasing_in_3_Rear_Power_Bias_2_206 = &Differential_Biasing_in_3_Rear_Power_Bias_2_206_init_;
static DataType dtDifferential_Biasing_in_3_Rear_Power_Bias_2_206 = floatDataType;
float32 Differential_Biasing_in_2_Rear_Slip_2_215_init_ = 0.0000000000000000000E+0 ;
static float32* Differential_Biasing_in_2_Rear_Slip_2_215 = &Differential_Biasing_in_2_Rear_Slip_2_215_init_;
static DataType dtDifferential_Biasing_in_2_Rear_Slip_2_215 = floatDataType;
float32 Differential_Biasing_in_5_Front_Slip_2_224_init_ = 0.0000000000000000000E+0 ;
static float32* Differential_Biasing_in_5_Front_Slip_2_224 = &Differential_Biasing_in_5_Front_Slip_2_224_init_;
static DataType dtDifferential_Biasing_in_5_Front_Slip_2_224 = floatDataType;
extern eRunStatus Differential_Biasing_Run(	)
{
	Boolean bRunToFinish = true;
	int32 nReady = 1;
	Differential_Biasing_InitVIConstantList();
	{
		heap->l_Constant = -1;
		heap->n_Throttle_2 = *Differential_Biasing_in_0_Throttle_2_1D7;
		heap->n_Front_Power_Bias_2 = *Differential_Biasing_in_4_Front_Power_Bias_2_1F7;
		/**/
		/* Multiply */
		/**/
		PDAFltBinop( &heap->n_Front_Power_Bias_2, floatDataType, &heap->n_Throttle_2, floatDataType, opMult, &heap->n_Multiply_x_y_1, floatDataType);
		heap->n_Rear_Power_Bias_2 = *Differential_Biasing_in_3_Rear_Power_Bias_2_206;
		/**/
		/* Multiply */
		/**/
		PDAFltBinop( &heap->n_Throttle_2, floatDataType, &heap->n_Rear_Power_Bias_2, floatDataType, opMult, &heap->n_Multiply_x_y_3, floatDataType);
		heap->n_Rear_Slip_2 = *Differential_Biasing_in_2_Rear_Slip_2_215;
		heap->n_Steering_2 = *Differential_Biasing_in_1_Steering_2_1BA;
		/**/
		/* Multiply */
		/**/
		PDAFltBinop( &heap->n_Steering_2, floatDataType, &heap->n_Rear_Slip_2, floatDataType, opMult, &heap->n_Multiply_x_y_7, floatDataType);
		/**/
		/* Increment */
		/**/
		PDAFltUnop( &(heap->n_Multiply_x_y_7), floatDataType, opIncr, &(heap->n_Increment_x_1), floatDataType);
		/**/
		/* Multiply */
		/**/
		PDAFltBinop( &heap->n_Increment_x_1, floatDataType, &heap->n_Multiply_x_y_3, floatDataType, opMult, &heap->n_Multiply_x_y, floatDataType);
		*Differential_Biasing_out_0_Wheel_BR_2_17D = heap->n_Multiply_x_y;
		/**/
		/* Multiply */
		/**/
		PDAFltBinop( &heap->l_Constant, int32DataType, &heap->n_Multiply_x_y_7, floatDataType, opMult, &heap->n_Multiply_x_y_4, floatDataType);
		/**/
		/* Increment */
		/**/
		PDAFltUnop( &(heap->n_Multiply_x_y_4), floatDataType, opIncr, &(heap->n_Increment_x_1_3), floatDataType);
		/**/
		/* Multiply */
		/**/
		PDAFltBinop( &heap->n_Increment_x_1_3, floatDataType, &heap->n_Multiply_x_y_3, floatDataType, opMult, &heap->n_Multiply_x_y_2, floatDataType);
		*Differential_Biasing_out_1_Wheel_BL_2_19C = heap->n_Multiply_x_y_2;
		heap->n_Front_Slip_2 = *Differential_Biasing_in_5_Front_Slip_2_224;
		/**/
		/* Multiply */
		/**/
		PDAFltBinop( &heap->n_Front_Slip_2, floatDataType, &heap->n_Steering_2, floatDataType, opMult, &heap->n_Multiply_x_y_6, floatDataType);
		/**/
		/* Increment */
		/**/
		PDAFltUnop( &(heap->n_Multiply_x_y_6), floatDataType, opIncr, &(heap->n_Increment_x_1_1), floatDataType);
		/**/
		/* Multiply */
		/**/
		PDAFltBinop( &heap->n_Multiply_x_y_1, floatDataType, &heap->n_Increment_x_1_1, floatDataType, opMult, &heap->n_Multiply_x_y_9, floatDataType);
		*Differential_Biasing_out_2_Wheel_FR_2_135 = heap->n_Multiply_x_y_9;
		/**/
		/* Multiply */
		/**/
		PDAFltBinop( &heap->n_Multiply_x_y_6, floatDataType, &heap->l_Constant, int32DataType, opMult, &heap->n_Multiply_x_y_5, floatDataType);
		/**/
		/* Increment */
		/**/
		PDAFltUnop( &(heap->n_Multiply_x_y_5), floatDataType, opIncr, &(heap->n_Increment_x_1_2), floatDataType);
		/**/
		/* Multiply */
		/**/
		PDAFltBinop( &heap->n_Multiply_x_y_1, floatDataType, &heap->n_Increment_x_1_2, floatDataType, opMult, &heap->n_Multiply_x_y_8, floatDataType);
		*Differential_Biasing_out_3_Wheel_FL_2_15F = heap->n_Multiply_x_y_8;
		return eFinished;
	}
}
/****** Main Entry Point for VI **********/

TextPtr Differential_Biasing_VIName = "Differential Biasing.vi";

eRunStatus Differential_Biasing_Start(subVIInstanceDataPtr viInstanceData, Boolean bShowFrontPanel, Boolean bRunToFinish, ArgList* argsIn, ArgList* argsOut, Boolean *pause);
eRunStatus Differential_Biasing_Start(subVIInstanceDataPtr viInstanceData, Boolean bShowFrontPanel, Boolean bRunToFinish, ArgList* argsIn, ArgList* argsOut, Boolean *pause){
	Differential_Biasing_AddSubVIInstanceData();
	return Differential_Biasing_Run();
}


/****** Library interface **********/


void DifferentialBiasing(float32 FrontSlip2,
float32 FrontPowerBias2,
float32 RearPowerBias2,
float32 RearSlip2,
float32 Steering2,
float32 Throttle2,
float32 *WheelFL2,
float32 *WheelFR2,
float32 *WheelBL2,
float32 *WheelBR2)
{
	int32 i;
	LVCGenRTInit();

	/* Init globals */
	for (i=0;i<sizeof(globTable)/sizeof(InitFPTermsFunc);i++) {
		(*(globTable[i]))(NULL, false);
	}

	/* Init VI Constants */
	for (i=0;i<sizeof(globConstInitTable)/sizeof(VoidFn);i++) {
		(*(globConstInitTable[i]))();
	}

	Differential_Biasing_AddSubVIInstanceData();
	Differential_Biasing_InitVIConstantList();

	Differential_Biasing_in_5_Front_Slip_2_224 = &(FrontSlip2);
	Differential_Biasing_in_4_Front_Power_Bias_2_1F7 = &(FrontPowerBias2);
	Differential_Biasing_in_3_Rear_Power_Bias_2_206 = &(RearPowerBias2);
	Differential_Biasing_in_2_Rear_Slip_2_215 = &(RearSlip2);
	Differential_Biasing_in_1_Steering_2_1BA = &(Steering2);
	Differential_Biasing_in_0_Throttle_2_1D7 = &(Throttle2);
	/* Call top level VI main function */
	Differential_Biasing_Run();
	*WheelFL2 = *Differential_Biasing_out_3_Wheel_FL_2_15F;
	*WheelFR2 = *Differential_Biasing_out_2_Wheel_FR_2_135;
	*WheelBL2 = *Differential_Biasing_out_1_Wheel_BL_2_19C;
	*WheelBR2 = *Differential_Biasing_out_0_Wheel_BR_2_17D;

	/* Cleanup VI Constants */
	for (i=0;i<sizeof(globConstCleanupTable)/sizeof(VoidFn);i++) {
		(*(globConstCleanupTable[i]))();
	}

	/* Cleanup globals */
	for (i=0;i<sizeof(globCleanupTable)/sizeof(VoidFn);i++) {
		(*(globCleanupTable[i]))(false);
	}

	for (i=0;i<sizeof(lsrCleanupTable)/sizeof(VoidFn);i++) {
		(*(lsrCleanupTable[i]))();
	}

	LVCGenRTEnd();
	return;
}



/****** End of generated code **********/


