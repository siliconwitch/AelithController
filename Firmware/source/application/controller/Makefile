SHELL = cmd.exe

CL = cl.exe
LINK = link.exe

CLFLAGS = /D "CGEN_LIBFUNC_PREFIX=__declspec(dllexport)" /D "_CRT_SECURE_NO_WARNINGS" /MT /Zp4 /W3 /nologo /c
LINKFLAGS = /nologo /dll /machine:I386

# Required include to import project settings
include dependencies.mk

# Included when the simulation module is installed
-include simulation.windows.mk

# Name of the output file, without extension
APPLICATION = Sharedlib

SRC += dllmain.c

INCLUDES = /I "." /I "$(LVPATH)\CCodeGen\include\blockdiagram" /I "$(LVPATH)\CCodeGen\include\comms" /I "$(LVPATH)\CCodeGen\include\frontpanel" /I "$(LVPATH)\CCodeGen\include\platform\win" /I "$(LVPATH)\CCodeGen\analysis\development\include" /I "$(LVPATH)\CCodeGen\analysis\LV\source\include"

LIBSRCPATH = $(LVPATH)\CCodegen\libsrc
VPATH = $(LIBSRCPATH)\lvanalysis:$(LIBSRCPATH)\blockdiagram:$(LIBSRCPATH)\frontpanel:$(LIBSRCPATH)\lvanalysis:$(LIBSRCPATH)\comms:$(LIBSRCPATH)\os\common:$(LIBSRCPATH)\platform\win

BDLIBS1 = CCGArrSupport.c CCGArrSupport2.c CCGArrSupport3.c CCGClusterSupport.c CCGCmplxSupport.c CCGDVRSupport.c CCGEnumSupport.c CCGErrorSupport.c CCGFXPSupport.c
BDLIBS2 = CCGFltSupport.c CCGIntSupport.c CCGStrSupport.c CCGTimeSupport.c CCGTokString.c CCGUDClassSupport.c CCGVariant.c CCGXMLSupport.c ExecStack.c
BDLIBS3 = LVBlockDiagram.c LVCGenRTInit.c LVContext.c LVHeap.c LVTdp.c MemCheck.c nbemptybin.c nbfifo.c nbfifo_inst.c nbitemtable.c NumText.c ViLib.c rtmath.c
BDLIBS = $(BDLIBS1) $(BDLIBS2) $(BDLIBS3)

FPLIBS1 = LVArrayControl.c LVBoolean.c LVClusterControl.c LVEnumCtl.c LVFrontPanel.c
FPLIBS2 = LVListbox.c LVNumeric.c LVRadioClustCtl.c LVRing.c LVScrollbar.c LVString.c LVTab.c LVTable.c
FPLIBS3 = LVTimestamp.c LVTree.c Pict.c
FPLIBS = $(FPLIBS1) $(FPLIBS2) $(FPLIBS3)

COMMSLIBS = CCGVIRefSupport.c crc.c

LVLIBS = arrresize.c

COMMONLIBS = Headless.c

# Windows-specific DLL entry points.  This file should not be compiled for other platforms.
WINLIBS = DllMain.c

LIBSRC = $(BDLIBS) $(FPLIBS) $(COMMSLIBS) $(COMMONLIBS) $(LVLIBS) $(WINLIBS)

OBJDIR = .\obj

LIBSRCOBJS = $(LIBSRC:%.c=$(OBJDIR)\\%.obj)
OBJS = $(SRC:%.c=$(OBJDIR)\\%.obj)

LIBS = $(LIBSRCOBJS)

OSLIBS = kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib Ws2_32.lib
ANALYSISLIBS = $(LVPATH)\CCodegen\lib\win\lv_analysis.lib

CG = "$(LVPATH)\CCodegen\bin\lvcg.exe"
CGOPTS = -override-destination

.DEFAULT_GOAL = default
default: $(APPLICATION).dll

dependencies.mk : $(LVPROJ)
	@$(CG) $(CGOPTS) $(LVPROJ) $(BUILDSPEC)
	
$(OBJDIR)\\%.obj: %.c LVFuncsUsed.h LVForms.h LVGlobs.h
	@if not exist "$(OBJDIR)" mkdir obj
	@$(CL) /c $(CLFLAGS) $(INCLUDES) /Fo"$(OBJDIR)\\" $<

$(APPLICATION).dll: $(LIBSRCOBJS) $(OBJS) $(ANALYSISLIBS) $(SIM_OBJS)
	@$(LINK) $(LINKFLAGS) $(OSLIBS) $(ANALYSISLIBS) $(OBJDIR)\*.obj $(SIM_OBJS) /out:"$(APPLICATION).dll" /implib:"$(APPLICATION).lib"
	
$(LVPATH)\CCodegen\lib\win\lv_analysis.lib:
	@$(MAKE) -C "$(LVPATH)\CCodegen\analysis" analysislib

clean: dummy
	@del /f/s/q $(OBJS)
	@del /f/s/q $(LIBSRCOBJS)

#
# False targets.
#
.PHONY: dummy

#
# A rule to do nothing
#
dummy:
