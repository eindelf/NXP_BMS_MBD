################################################################################
#
#                     (c) Copyright 2011, Freescale
#
#                  Makefile for compiling MCLIB with LCC
#
################################################################################

.SUFFIXES:

#VC_DIR     = "c:\Program Files (x86)\Microsoft Visual Studio 10.0"
VC_BIN     = $(VC_DIR)\VC\bin\amd64
VC_INCLUDE = "$(VC_DIR)\include"

VC_CC      = "$(VC_BIN)\cl.exe"
VC_LIB     = "$(VC_BIN)\lib.exe"

CC_OPT  = /c /favor:AMD64 
LIB_OPT =/MACHINE:X64

# GFLIB modules to compile
gflib   = GFLIB_Sin \
          GFLIB_Cos \
          GFLIB_Tan\
          GFLIB_Sqrt\
          GFLIB_ControllerPIr \
          GFLIB_ControllerPIrAW \
          GFLIB_ControllerPIp \
          GFLIB_ControllerPIpAW \
          GFLIB_Asin \
          GFLIB_Acos \
          GFLIB_Atan \
          GFLIB_AtanYX \
          GFLIB_Sign \
          GFLIB_Lut1D \
          GFLIB_Lut2D \
          GFLIB_VectorLimit \
          GFLIB_Limit \
          GFLIB_UpperLimit \
          GFLIB_LowerLimit \
          GFLIB_Hyst \
          GFLIB_IntegratorTR \
          GFLIB_Ramp \
          GFLIB_AtanYXShifted

# GDFLIB modules to compile
gmclib  = GMCLIB_SvmStd \
          GMCLIB_Clark \
          GMCLIB_ClarkInv \
          GMCLIB_Park \
          GMCLIB_ParkInv \
          GMCLIB_ElimDcBusRip \
          GMCLIB_DecouplingPMSM
          
# GMCLIB modules to compile
gdflib  = GDFLIB_FilterIIR1 \
          GDFLIB_FilterIIR2 \
          GDFLIB_FilterFIR \
          GDFLIB_FilterMA

MCLIB_NAME = MCLIB.lib

# Common Paths
SRCDIR = ..\..\src

# Include Directories
IDIR = -I..\..\include \
       -I$(VC_INCLUDE) 

# Create a list of object files from all c source files for VC compiler
VC_OBJECTS  = $(foreach gf,$(gflib),$(gf).obj) \
		      $(foreach gmc,$(gmclib),$(gmc).obj) \
		      $(foreach gdf,$(gdflib),$(gdf).obj)
			  
all: clean $(VC_OBJECTS)
	@echo ==== Building library
	$(VC_LIB) /out:$(MCLIB_NAME) $(VC_OBJECTS)
	@if exist *.obj del *.obj

%.obj: $(SRCDIR)\%.c
	@echo ==== Building file $@
	$(VC_CC) $(IDIR) $(CC_OPT) $<

clean:
	@echo ==== Clean 
	@if exist *.obj del *.obj
	@if exist *.lib del *.lib
