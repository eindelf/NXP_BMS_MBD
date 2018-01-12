################################################################################
#
#                     (c) Copyright 2011, Freescale
#
#                  Makefile for compiling MCLIB with LCC
#
################################################################################

.SUFFIXES:

LCC_DIR     = $(MATLAB_DIR)\sys\lcc
LCC_BIN     = $(LCC_DIR)\bin
LCC_INCLUDE = $(LCC_DIR)\include

LCC_CC      = $(LCC_BIN)\lcc.exe
LCC_LIB     = $(LCC_BIN)\lcclib.exe

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
       -I..\..\include\lcc \
       -I$(LCC_INCLUDE) 

# Create a list of object files from all c source files for LCC compiler
LCC_OBJECTS  = $(foreach gf,$(gflib),$(gf).obj) \
		       $(foreach gmc,$(gmclib),$(gmc).obj) \
		       $(foreach gdf,$(gdflib),$(gdf).obj)
			  
all: clean $(LCC_OBJECTS)
	@echo ==== Building library
	$(LCC_LIB) /out:$(MCLIB_NAME) $(LCC_OBJECTS)
	@if exist *.obj del *.obj

%.obj: $(SRCDIR)\%.c
	@echo ==== Building file $@
	$(LCC_CC) $(IDIR) -w -noregistrylookup $<

clean:
	@echo ==== Clean 
	@if exist *.obj del *.obj
	@if exist *.lib del *.lib
