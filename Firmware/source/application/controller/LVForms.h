#ifndef _LVForms_h
#define _LVForms_h
#include "LVCCG.h"
#include "CCGDataSupport.h"
#include "LVGlobs.h"

extern TextPtr Differential_Biasing_VIName;
extern eRunStatus Differential_Biasing_Start(subVIInstanceDataPtr viInstanceData, Boolean bShowFrontPanel, Boolean bRunToFinish, ArgList *argsIn, ArgList *argsOut, Boolean *pause);
#define Differential_Biasing_formID 2000

#ifdef LV_MAIN
FormTableEntry formTable[] = {
{ Differential_Biasing_formID, Differential_Biasing_Start, &Differential_Biasing_VIName },
};
uInt8 formTableSize = 1;
#ifndef No_OS
LVCriticalSection gVICriticalSections[1];
uInt8 gVICriticalSectionsSize = 0;
#endif
#else
extern FormTableEntry formTable[];
#endif

#endif
