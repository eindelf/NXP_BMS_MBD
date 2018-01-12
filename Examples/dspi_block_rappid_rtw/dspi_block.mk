#
# File    : rappid_564xl_cw.tmf
#
# Abstract:
#	Real-Time Workshop template makefile used to create <model>.mk
#	file for RAppID target.
#
#	Note that this template is automatically customized by the Real-Time
#	Workshop build procedure to create "<model>.mk" which then is
#	passed to nmake to produce <model>.mak
#
#	The following defines can be used to modify the behavior of the build:
#    OPTS           - Additional user defines.
#    USER_SRCS      - Additional user sources, such as files needed by
#                     S-functions.
#    USER_INCLUDES  - Additional include paths
#                     (i.e. USER_INCLUDES="/I where-ever1 /I where-ever2")
# Copyright 2011
# Freescale Semiconductor Inc
# All Rights Reserved .
#
# $Log: rappid_564xl_cw.tmf,v $

#---------------------- Tokens expanded by make_rtw ----------------------------
#
# The following tokens, when wrapped with "|>" and "|<" are expanded by the
# Real-Time Workshop build procedure.
#
#  MODEL_NAME      - Name of the Simulink block diagram
#  MODEL_MODULES   - Any additional generated source modules
#  MAKEFILE_NAME   - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT     - Path to were MATLAB is installed.
#  S_FUNCTIONS     - List of S-functions.
#  S_FUNCTIONS_LIB - List of S-functions libraries to link.
#  SOLVER          - Solver source file name
#  NUMST           - Number of sample times
#  TID01EQ         - yes (1) or no (0): Are sampling rates of continuous task
#                    (tid=0) and 1st discrete task equal.
#  NCSTATES        - Number of continuous states
#  MEM_ALLOC       - Either RT_MALLOC or RT_STATIC indicating the style of the
#                    generated code. Statically allocated data is only useful
#                    for one instance of the model.
#  COMPUTER        - Computer type. See the MATLAB computer command.
#  BUILDARGS       - Options passed in at the command line.
#  MULTITASKING    - yes (1) or no (0): Is solver mode multitasking
#  MAT_FILE        - yes (1) or no (0): MAT file logging
#  EXT_MODE        - yes (1) or no (0): Build for external mode
#  TMW_EXTMODE_TESTING - yes (1) or no (0): Build ext_test.c for external mode
#                        testing.
#  EXTMODE_TRANSPORT   - Index of transport mechanism (e.g. tcpip, serial) for extmode
#  EXTMODE_STATIC      - yes (1) or no (0): Use static instead of dynamic mem alloc.
#  EXTMODE_STATIC_SIZE - Size of static memory allocation buffer.

MODEL           = dspi_block
MODULES         = BMU_Driver.c SPITask.c SPITask_wrapper.c dspi0_EOC_isr.c dspi1_2_isr.c dspi1_4_isr.c dspi_564xL_library.c freemaster_MPC56xx.c freemaster_appcmd.c freemaster_protocol.c freemaster_rec.c freemaster_scope.c freemaster_serial.c freemaster_sfio.c freemaster_tsa.c gpio_564xl_library.c intc_init.c intc_sw_vectable.c linflex_init.c linflex_siu_init.c rappid_main.c rappid_utils.c siu_init.c sys_init.c sysclk_init.c 
MAKEFILE        = dspi_block.mk
ALT_MATLAB_ROOT = C:\PROGRA~1\MATLAB\R2016b
MATLAB_ROOT     = C:\Program Files\MATLAB\R2016b
S_FUNCTIONS     = 
S_FUNCTIONS_OBJ = 
S_FUNCTIONS_LIB = 
SOLVER          = 
NUMST           = 1
TID01EQ         = 0
NCSTATES        = 0
MEM_ALLOC       = RT_STATIC
COMPUTER        = PCWIN64
BUILDARGS       =  GENERATE_ERT_S_FUNCTION=0 INCLUDE_MDL_TERMINATE_FCN=1 COMBINE_OUTPUT_UPDATE_FCNS=1 MULTI_INSTANCE_CODE=0 INTEGER_CODE=0 ISPROTECTINGMODEL=NOTPROTECTING
MULTITASKING    = 0
MAT_FILE        = 0
GENERATE_ASAP2 	= 0
EXT_MODE             = 0
TMW_EXTMODE_TESTING  = 0
EXTMODE_TRANSPORT    = 0
EXTMODE_STATIC       = 0
EXTMODE_STATIC_SIZE  = 1000000

MAKEFILEBUILDER_TGT = 0
STANDALONE_SUPPRESS_EXE = 0
GEN_SAMPLE_MAIN = 0

MODELREFS               = 
SHARED_SRC              = 
SHARED_SRC_DIR          = 
SHARED_BIN_DIR          = 
SHARED_LIB              = 
LIB_SKIP                = rt_logging.o avi_rt.o


#--------------------------- Model and reference models -----------------------
MODELLIB                  = dspi_blocklib.lib
MODELREF_LINK_LIBS        = 
MODELREF_INC_PATH         = 
RELATIVE_PATH_TO_ANCHOR   = ..
# NONE: standalone, SIM: modelref sim, RTW: modelref rtw
MODELREF_TARGET_TYPE       = NONE

#-- In the case when directory name contains space ---
ifneq ($(MATLAB_ROOT),$(ALT_MATLAB_ROOT))
MATLAB_ROOT := $(ALT_MATLAB_ROOT)
endif
ifneq ($(MATLAB_BIN),$(ALT_MATLAB_BIN))
MATLAB_BIN := $(ALT_MATLAB_BIN)
endif



#------------------------ Macros read by make_rtw -----------------------------
#
# The following macros are read by the Real-Time Workshop build procedure:
#
#  MAKECMD             - This is the command used to invoke the make utility
#  HOST                - What platform this template makefile is targeted for
#                        (i.e. PC or UNIX)
#  BUILD               - Invoke make from the Real-Time Workshop build procedure
#                        (yes/no)?
#  SYS_TARGET_FILE     - Name of system target file.
#  BUILD_SUCCESS       - Message to use when build completes with no errors
#  COMPILER_TOOL_CHAIN - defines compliler tool chain (lcc, vc, ...) or if mcu compiler (default)

MAKECMD             = "C:\Program Files\MATLAB\R2016b\bin\win64\gmake"
HOST                = PC
BUILD               = yes
SYS_TARGET_FILE     = rappid564xl.tlc
BUILD_SUCCESS	    = *** Created executable:
COMPILER_TOOL_CHAIN = default

#----------------------------- External mode -----------------------------------

# Uncomment -DVERBOSE to have information printed to stdout
# To add a new transport layer, see the comments in
#   <matlabroot>/toolbox/simulink/simulink/extmode_transports.m
ifeq ($(EXT_MODE),1)
  EXT_CC_OPTS = -DEXT_MODE -DWIN32 # -DVERBOSE
  ifeq ($(EXTMODE_TRANSPORT),0) #tcpip
    EXT_SRC = ext_svr.c updown.c ext_work.c ext_svr_tcpip_transport.c
    EXT_LIB = $(MATLAB_ROOT)\sys\lcc\lib\wsock32.lib
  endif
  ifeq ($(EXTMODE_TRANSPORT),1) #serial_win32
    EXT_SRC  = ext_svr.c updown.c ext_work.c ext_svr_serial_transport.c
    EXT_SRC += ext_serial_pkt.c ext_serial_win32_port.c
  endif
  ifeq ($(TMW_EXTMODE_TESTING),1)
    EXT_SRC     += ext_test.c
    EXT_CC_OPTS += -DTMW_EXTMODE_TESTING
  endif
  ifeq ($(EXTMODE_STATIC),1)
    EXT_SRC     += mem_mgr.c
    EXT_CC_OPTS += -DEXTMODE_STATIC 
-DEXTMODE_STATIC_SIZE=$(EXTMODE_STATIC_SIZE)
  endif
endif



#------------------------------ Include Path -----------------------------------

MATLAB_INCLUDES = \
	-I"$(MATLAB)"\simulink\include \
	-I"$(MATLAB)"\extern\include \
	-I"$(MATLAB)"\rtw\c\src \
	-I"$(MATLAB)"\rtw\c\libsrc \
	-I"$(MATLAB)"\rtw\c\src\ext_mode\common \
	-I"$(MATLAB)"\rtw\c\src\ext_mode\tcpip \
	-I"$(MATLAB)"\rtw\c\src\ext_mode\serial \
	-I"$(MATLAB)"\rtw\c\src\ext_mode\custom

# Additional file include paths
ADD_INCLUDES = \
	-I$(MATLAB_ROOT)\simulink\include\sf_runtime \
	-IC:\MCToolbox\rappid564xl\Examples\dspi_block_rappid_rtw \
	-IC:\MCToolbox\rappid564xl\Examples \


USER_INCLUDES=

SHARED_INCLUDES =
ifneq ($(SHARED_SRC_DIR),)
SHARED_INCLUDES = -I$(SHARED_SRC_DIR)
endif


#------------------------------ Libraries -----------------------------------

LIBS =
 
 

WR_LIBS =
 
 


#---------------------------------TOOLCHAIN------------------------------------
#---------- Define codewarrior tools to build using command line ---------------
#------------------------------------------------------------------------------

ifeq "$(origin MW_TOOL)" "undefined"	
	#CodeWarrior v.10.x
	TOOL_ROOT=$(CW_TOOL)
	CMDLINE_TOOLS=$(TOOL_ROOT)/MCU/PA_Tools/Command_Line_Tools
	TOOL_INCLUDES=-I"$(TOOL_ROOT)/MCU/PA_Support/ewl/EWL_Runtime/Runtime_PA/Include" \
			-I"$(TOOL_ROOT)/MCU/PA_Support/ewl/EWL_Runtime/Runtime_PA/Source" \
			-I"$(TOOL_ROOT)/MCU/PA_Support/ewl/lib" \
			-I"$(TOOL_ROOT)/MCU/PA_Support/ewl/EWL_C/include" \
			-I"$(TOOL_ROOT)/MCU/PA_Support/ewl/EWL_C++/include"
	TOOL_LIB= "$(MC_LIB)" \
		"$(TOOL_ROOT)/MCU/PA_Support/ewl/lib/libc_E200z446_VLE_SPFP_Only.a" \
		"$(TOOL_ROOT)/MCU/PA_Support/ewl/lib/librt_E200z446_VLE_SPFP_Only.a"
	LIB_OPTS= -prefix "$(TOOL_ROOT)/MCU/PA_Support/ewl/EWL_C/include/lib_ewl.prefix"
	
else
	#CodeWarrior version v.2.x
	TOOL_ROOT=$(MW_TOOL)
	CMDLINE_TOOLS=$(TOOL_ROOT)/PowerPC_EABI_Tools/Command_Line_Tools
	TOOL_INCLUDES=-I"$(TOOL_ROOT)/PowerPC_EABI_Support/Runtime/Include" \
		-I"$(TOOL_ROOT)/PowerPC_EABI_Support/Runtime/Src" \
		-I"$(TOOL_ROOT)/PowerPC_EABI_Support/Runtime/Lib" \
		-I"$(TOOL_ROOT)/PowerPC_EABI_Support/MSL/MSL_C/PPC_EABI/Lib" \
		-I"$(TOOL_ROOT)/PowerPC_EABI_Support/MSL/MSL_C/PPC_EABI/Include" \
		-I"$(TOOL_ROOT)/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Include" \
		-I"$(TOOL_ROOT)/PowerPC_EABI_Support/MSL/MSL_C++/PPC_EABI/Lib" \
		-I"$(TOOL_ROOT)/PowerPC_EABI_Support/MSL/MSL_C++/PPC_EABI/Include" \
		-I"$(TOOL_ROOT)/PowerPC_EABI_Support/MSL/MSL_C++/MSL_Common/Include"
	TOOL_LIB= "$(MC_LIB)" \
		"$(TOOL_ROOT)/PowerPC_EABI_Support/Runtime/Lib/Runtime.PPCEABI.V.UC.a" \
		"$(TOOL_ROOT)/PowerPC_EABI_Support/MSL/MSL_C/PPC_EABI/Lib/MSL_C.PPCEABI.bare.V.SP.UC.a"
	LIB_OPTS=
	
endif

TOOL_SPECIFIC_FILES=cw_specific_files
COMPILE_TOOL="$(CMDLINE_TOOLS)/mwcceppc"
ASSEMBLY_TOOL="$(CMDLINE_TOOLS)/mwasmeppc"
ARCHIVER_TOOL="$(CMDLINE_TOOLS)/mwldeppc"
LINK_TOOL="$(CMDLINE_TOOLS)/mwldeppc"
TOOL_OPTS= -proc Zen 
COMPILE_TOOL_OPTS= -vle -DVLE_IS_ON -gdwarf-2 -fp spfp_only -spe_vector -char unsigned $(TOOL_OPTS) -gccincludes -nostdinc -nosyspath -ansi off -opt all -bool on -Cpp_exceptions off $(LIB_OPTS)
ASSEMBLY_TOOL_OPTS= -vle -DVLE_IS_ON $(TOOL_OPTS) -list -gccincludes -nostdinc
LIBRARY_OPTS = $(TOOL_OPTS) -library -nostdlib -gdwarf-2 -fp spfp_only -char unsigned
ifeq ($(MAKEFILEBUILDER_TGT),1)
LCF_FILE = ../MPC564xLRAM.lcf
else
LCF_FILE = MPC564xLRAM.lcf
endif
LINK_TOOL_OPTS= -gdwarf-2 -fp spfp_only -char unsigned $(TOOL_OPTS) -m _start -nostdlib -srec -lcf $(LCF_FILE)
PLIB_TEMP = precomp
LIB_TEMP  = libs
LIB_SUFFIX = MW

TOOL_CFiles =  intc_init.c intc_sw_vecttable.c rappid_utils.c romcopy.c sys_init.c sysclk_init.c
# TBA: bam_init.c - initialize Bootup Reset Config Half Word(RCHW)
# TBA: swt_init.c - initialize Software Watchdog Timer (SWT)
ifeq ($(MAKEFILEBUILDER_TGT),1)
MC_LIB = ../MCLIB_MPC564xL.PPCEABI.V.UC.a
else
MC_LIB = MCLIB_MPC564xL.PPCEABI.V.UC.a
endif

#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
#------------------------------------------------------------------------------



INCLUDES =  -I. \
	-I$(RELATIVE_PATH_TO_ANCHOR) \
	$(MATLAB_INCLUDES) \
	$(TOOL_INCLUDES) \
	$(ADD_INCLUDES) \
	$(USER_INCLUDES) \
	$(MODELREF_INC_PATH) \
	$(SHARED_INCLUDES)


#------------------------ rtModel ----------------------------------------------

CPP_REQ_DEFINES = -DUSE_RTMODEL -DMODEL=$(MODEL) -DREAL_T=float -DRT -DNUMST=$(NUMST) \
	-DTID01EQ=$(TID01EQ) -DNCSTATES=$(NCSTATES) \
	-DMT=$(MULTITASKING) -DHAVESTDIO



#-------------------- Definitons for application files: -----------------------
#
# C_FILES       = all application specific C source files.
# S_FILES       = all application specific assembly source files.
# APP_INCS      = all application specific include files.
#

ifeq ($(STANDALONE_SUPPRESS_EXE),1)
C_FILES_MODEL   = 
else
C_FILES_MODEL   = $(MODEL).c 
endif
ifeq ($(MODELREF_TARGET_TYPE), NONE)
C_FILES_MODULES = $(MODULES) 
else
C_FILES_MODULES = $(MODULES:rappid_main.c=) 
endif
C_FILES_SOLVER  = $(SOLVER) 
ifeq ($(MAKEFILEBUILDER_TGT),1)
C_FILES_SFUN    =
else
C_FILES_SFUN    = $(S_FUNCTIONS) 
endif
C_FILES_EXT_SRC = $(EXT_SRC)
#C_FILES_TOOL   = $(TOOL_CFiles)

C_FILES = $(C_FILES_MODEL) $(C_FILES_MODULES) $(C_FILES_SOLVER) $(C_FILES_SFUN) $(C_FILES_EXT_SRC)

ifeq ($(MAKEFILEBUILDER_TGT),1)
S_FILES = ..\crt0.s ..\sw_handlers.s ..\excep_handler.s 
else
S_FILES = crt0.s sw_handlers.s excep_handler.s 
endif

# TBA: rappid_func.s - initialize IVPR
CFLAGS =	$(INCLUDES) \
			$(CPP_REQ_DEFINES) \
            		-c \
			$(EXT_CC_OPTS) \
			$(OPTS)

AFLAGS = -c

######################################################################
# The remainder of this makefile is generally not specific to
# a particular application and normally need not be changed.
######################################################################


LFLAGS    = $(TOOL_LIB) \
			$(LIBS) \
			$(EXT_LIB) \
			-Map $(MODEL).map \
			$(S_FUNCTIONS_LIB)

#
#------------------------ Construct the object file lists------------------------
#
C_OBJECTS = $(C_FILES:.c=.o)
S_OBJECTS = $(S_FILES:.s=.o)
OBJ_FILES = $(S_OBJECTS) $(C_OBJECTS) 

SHARED_SRC := $(subst \,/,$(SHARED_SRC))
SHARED_SRC := $(wildcard $(SHARED_SRC))
SHARED_OBJS = $(addsuffix .o, $(basename $(SHARED_SRC)))
#
#----------------------- make all variables available to sub-makes---------------
#
export


#
#---------------------------------------Build rules------------------------------
#
ifeq ($(MODELREF_TARGET_TYPE), NONE)
ifeq ($(MAKEFILEBUILDER_TGT), 1)
  # Top-level model for RTW
  PRODUCT            = $(MODEL).elf
  BIN_SETTING        = $(LD) $(LDFLAGS) -o $(PRODUCT) $(SYSLIBS) 
  BUILD_PRODUCT_TYPE = "executable"
else
ifeq ($(STANDALONE_SUPPRESS_EXE), 1)
PRODUCT            = "ObjectModulesOnly"
else
  # Top-level model for RTW
  PRODUCT            = $(MODEL).elf
  BIN_SETTING        = $(LD) $(LDFLAGS) -o $(PRODUCT) $(SYSLIBS) 
  BUILD_PRODUCT_TYPE = "executable"
endif
endif  
else
  # sub-model for RTW
  PRODUCT            = $(MODELLIB)
  BUILD_PRODUCT_TYPE = "library"
endif

all : clean SetupFiles $(PRODUCT)
	@echo Building target $@
	@echo $(BUILD_SUCCESS) $(PRODUCT)

clean:
	@echo clean
	@echo RELATIVE_PATH_TO_ANCHOR is $(RELATIVE_PATH_TO_ANCHOR)
	@echo ==== Removing object files from build directory ====
	@if exist *.o del *.o
	@if exist *.obj del *.obj
	@if exist *.elf del *.elf
ifeq ($(BUILD_PRODUCT_TYPE), library)	
	@if exist *.lib del *.lib
endif	
	@if exist *.s19 del *.s19
	@if exist *.out del *.out
	@if exist *.mot del *.mot
	@if exist *.bin del *.bin
	@if exist *.srz del *.srz
	@if exist *.d del *.d
	@if exist *.dbo del *.dbo
	@if exist *.rsp del *.rsp
	@if exist *.lst  del *.lst
	@if exist err.log del err.log
	@if exist $(LIB_TEMP)\*.o del $(LIB_TEMP)\*.o

SetupFiles:
	@echo Copying necessary files to build directory...
	@echo Compiler details : $(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS)
	@echo Assembler details : $(ASSEMBLY_TOOL) $(ASSEMBLY_TOOL_OPTS) $(AFLAGS)

$(MODELLIB): $(OBJ_FILES) $(WR_LIBS)$(SHARED_OBJS)
	$(ARCHIVER_TOOL) -o $@ $(LIBRARY_OPTS) $(OBJ_FILES)$(SHARED_OBJS)
	@echo Created library: $(MODELLIB)

	
ifeq ($(MAKEFILEBUILDER_TGT),1)

ifeq ($(STANDALONE_SUPPRESS_EXE), 1)
$(MODEL).elf: $(OBJ_FILES) $(S_FUNCTIONS_OBJ)
	@echo ==== Creating $(MODEL).out from obj files ====
	$(LINK_TOOL) $(OBJ_FILES) $(S_FUNCTIONS_OBJ) $(MODELLIB) -o $@ $(LINK_TOOL_OPTS) $(LFLAGS)
	@echo Created executable: $(MODEL).elf
else
$(MODEL).elf: $(S_FUNCTIONS_OBJ)
	@echo ==== Creating $(MODEL).out from obj files ====
	$(LINK_TOOL) $(S_FUNCTIONS_OBJ) $(MODELLIB) -o $@ $(LINK_TOOL_OPTS) $(LFLAGS)
	@echo Created executable: $(MODEL).elf
endif	
	
%.obj : $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/%.c
	@echo Building file $@...
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ $<
%.obj : %.c
	@echo Building file $@...
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ $<
else
ifeq ($(STANDALONE_SUPPRESS_EXE), 1)
.PHONY: $(PRODUCT)
$(PRODUCT) : $(OBJS)

else
$(MODEL).elf: $(OBJ_FILES) $(WR_LIBS)
	@echo ==== Creating $(MODEL).out from obj files ====
	$(LINK_TOOL) $(OBJ_FILES) -o $@ $(LINK_TOOL_OPTS) $(LFLAGS)
	@echo Created executable: $(MODEL).elf
endif
endif

##$(C_OBJECTS) : $(C_FILES)
##	@echo Building file $@...
##	$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ $(@:.o=.c)

$(S_OBJECTS) : $(S_FILES)
	@echo Building assembly file $@...
	@$(ASSEMBLY_TOOL) $(ASSEMBLY_TOOL_OPTS) $(AFLAGS) -o $@ $(@:.o=.s)

%.o : %.c
	@echo Building file $@...
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ $(@:.o=.c)

%.o : %.cpp
	@echo Building file $@...
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ $(@:.o=.c)

%.o : ../%.c
	@echo Building file $@...
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ $(@:.o=.c)

%.o : ../%.cpp
	@echo Building file $@...
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ $(@:.o=.c)

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	@echo Building file $@...
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ $(@:.o=.c)

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	@echo Building file $@...
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ $(@:.o=.c)

%.o : $(MATLAB_ROOT)/rtw/c/tornado/%.c
	@echo Building file $@...
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ $(@:.o=.c)

%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	@echo Building file $@...
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ $(@:.o=.c)

%.o : $(MATLAB_ROOT)/simulink/src/%.c
	@echo Building file $@...
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ $(@:.o=.c)

%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	@echo Building file $@...
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ $(@:.o=.c)

###################################
$(SHARED_LIB) : $(SHARED_OBJS)
	@echo "### Creating $@ "
	@$(AR) r $@ $(SHARED_OBJS)
	@$(ARCHIVER_TOOL) -q $@ $(LIBRARY_OPTS) $(SHARED_OBJS) > $@.lst
	@echo "### $@ Created "


###################################

$(LIB_TEMP)/%.o: $(MATLAB_ROOT)\rtw\c\src/%.c
	@echo ### "$(MATLAB_ROOT)\rtw\c\src\$*.c"
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ -c $<
$(PLIB_TEMP)/%.o: $(MATLAB_ROOT)\rtw\c\src/%.c
	@echo ### "$(MATLAB_ROOT)\rtw\c\src\$*.c"
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ -c $<


$(LIB_TEMP)/%.o: $(MATLAB_ROOT)\simulink\src/%.c
	@echo ### "$(MATLAB_ROOT)\simulink\src\$*.c"
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ -c $<
$(PLIB_TEMP)/%.o: $(MATLAB_ROOT)\simulink\src/%.c
	@echo ### "$(MATLAB_ROOT)\simulink\src\$*.c"
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ -c $<


$(LIB_TEMP)/%.o: ../%.c
	@echo ### "..\$*.c"
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ -c $<
$(PLIB_TEMP)/%.o: ../%.c
	@echo ### "..\$*.c"
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ -c $<





###################################

                                                                          

###################################


# EOF: rappid_564xl_cw.tmf
