# Targets:
# - build_executable     : Build executable artifact file
# - build_staticlib      : Build static library artifact file
# - install_executable   : Build and install executable artifact file
# - install_staticlib    : Build and install static library artifact file
# - clean                : Clean built, installed and intermediate files
# - rebuild_executable   : Rebuild executable artifact file
# - rebuild_staticlib    : Rebuild static library artifact file
# - reinstall_executable : Rebuild and install executable artifact file
# - reinstall_staticlib  : Rebuild and install static library artifact file
# - all                  : Build executable or static library artifact file (depending on the variable BUILD_TYPE)
# - build                : Build executable or static library artifact file (depending on the variable BUILD_TYPE)
# - install              : Build and install executable or static library artifact file (depending on the variable BUILD_TYPE)
# - rebuild              : Rebuild executable or static library artifact file (depending on the variable BUILD_TYPE)
# - reinstall            : Rebuild and install executable or static library artifact file (depending on the variable BUILD_TYPE)

##========================== User Section 001 Begin ==========================##
##========================== User Section 001  End  ==========================##

# Main variables

# Hints:
# Spaces must be escaped by the `\` character. E.g., the path `path with spaces` can be specified like `path\ with\ spaces`.
# The variable `BUILD_TYPE` has two possible values: `executable` to build an executable artifact file and `staticlib` to build a static library artifact file.
# Use only relative paths (relative to this file).
# Do not specify preprocessor macros with string values at variable `DEFINED_PREPROCESSOR_MACROS`. Instead, create a header file, e.g. `macros.inc` containing all preprocessor macros with string values and add `macros.inc` to the variable `INCLUDE_FILES`.
# Toolchain-specific flags must be inserted at the following variables: `TARGET_FLAGS`, `ASM_COMPILER_FLAGS`, `C_COMPILER_FLAGS`, `CPP_COMPILER_FLAGS`, `LINKER_FLAGS`, `ARCHIVER_FLAGS`, `IMG_FILE_CREATOR_FLAGS`, `EXT_LIST_CREATOR_FLAGS`. The rest of the variables do not require toolchain-specific flags.

BUILD_NAME                    ?= _iROM_TC334_LK_TCXX4_V1_0_LLVM
BUILD_TYPE                    ?= executable
ARTIFACT_BASE_NAME            ?= tc3xx-bsp-example
ARTIFACT_EXTENSION            ?= .elf
INSTALL_DIR                   ?= ../_iROM_TC334_LK_TCXX4_V1_0_LLVM
TOOLCHAIN_PREFIX              ?= C:/HighTec/toolchains/tricore/v11.0.0/bin/
ASM_COMPILER_PATH             ?= clang
C_COMPILER_PATH               ?= clang
CPP_COMPILER_PATH             ?= clang
LINKER_PATH                   ?= clang
ARCHIVER_PATH                 ?= llvm-ar
IMG_FILE_CREATOR_PATH         ?= llvm-objcopy
EXT_LIST_CREATOR_PATH         ?= llvm-objdump
SIZE_PRINTER_PATH             ?= llvm-size
LINKER_SCRIPTS                ?= ../tc3xx-platform/ld/tc33x_memory.ld ../tc3xx-platform/ld/tc33x_bsp_example.ld
LINKER_SEARCH_DIRS            ?= ../tc3xx-platform/ld
LINKER_ADDITIONAL_LIBS        ?=
INCLUDE_DIRS                  ?= ../tc3xx-platform/bsp ../tc3xx-platform/bsp/board ../tc3xx-platform/bsp/board/board_appkit_TC3X7_ADAS_V1.0 ../tc3xx-platform/bsp/board/board_appkit_TC3X7_ADAS_V2.0 ../tc3xx-platform/bsp/board/board_appkit_TC3X7_V1.0 ../tc3xx-platform/bsp/board/board_appkit_TC3X7_V2.0 ../tc3xx-platform/bsp/board/board_litekit_TC375_V2 ../tc3xx-platform/bsp/board/board_litekit_TCXX4_V1.0 ../tc3xx-platform/bsp/board/board_radar_TC3X6_V1.3 ../tc3xx-platform/bsp/board/board_triboard_TC377TX_V1.X ../tc3xx-platform/bsp/board/board_triboard_TC3X2_V1.0 ../tc3xx-platform/bsp/board/board_triboard_TC3X3_V1.0 ../tc3xx-platform/bsp/board/board_triboard_TC3X4L_V1.0 ../tc3xx-platform/bsp/board/board_triboard_TC3X4T_V1.0 ../tc3xx-platform/bsp/board/board_triboard_TC3X5_V1.X ../tc3xx-platform/bsp/board/board_triboard_TC3X6_ADAS_V1.0 ../tc3xx-platform/bsp/board/board_triboard_TC3X6_V1.0 ../tc3xx-platform/bsp/board/board_triboard_TC3X7_ADAS_V1.0 ../tc3xx-platform/bsp/board/board_triboard_TC3X7_ADAS_V2.0 ../tc3xx-platform/bsp/board/board_triboard_TC3X7_V1.0 ../tc3xx-platform/bsp/board/board_triboard_TC3X7_V2.0 ../tc3xx-platform/bsp/board/board_triboard_TC3X9_V1.0 ../tc3xx-platform/bsp/board/board_triboard_TC3X9_V2.0 ../tc3xx-platform/bsp/isr ../tc3xx-platform/bsp/uc ../tc3xx-platform/bsp/uc/uc_tc33 ../tc3xx-platform/bsp/uc/uc_tc33/TC33x32x_RegCHeaders ../tc3xx-platform/bsp/uc/uc_tc33/TC33x32x_RegCHeaders/_Reg ../tc3xx-platform/bsp/uc/uc_tc39 ../tc3xx-platform/bsp/uc/uc_tc39/TC39xB_RegCHeaders ../tc3xx-platform/bsp/uc/uc_tc39/TC39xB_RegCHeaders/_Reg ../tc3xx-platform/bsp/uc/uc_tc39/_Reg_TC39xA_V3.0.R0 ../tc3xx-platform/bsp/uc/uc_tc39/_Reg_TC39xA_V3.0.R0/_Reg ../tc3xx-platform/crt0 ../tc3xx-platform/ld ../tc3xx-platform/toolchain ../src
INCLUDE_FILES                 ?=
ASM_SOURCE_FILES              ?= ../tc3xx-platform/crt0/tc3x_crt0.S
C_SOURCE_FILES                ?= ../src/core0_main.c ../src/core1_main.c ../src/core2_main.c ../src/core3_main.c ../src/core4_main.c ../src/core5_main.c ../src/shared_main.c ../tc3xx-platform/bsp/board/board_appkit_TC3X7_ADAS_V1.0/board.c ../tc3xx-platform/bsp/board/board_appkit_TC3X7_ADAS_V2.0/board.c ../tc3xx-platform/bsp/board/board_appkit_TC3X7_V1.0/board.c ../tc3xx-platform/bsp/board/board_appkit_TC3X7_V2.0/board.c ../tc3xx-platform/bsp/board/board_litekit_TC375_V2/board.c ../tc3xx-platform/bsp/board/board_litekit_TCXX4_V1.0/board.c ../tc3xx-platform/bsp/board/board_radar_TC3X6_V1.3/board.c ../tc3xx-platform/bsp/board/board_triboard_TC377TX_V1.X/board.c ../tc3xx-platform/bsp/board/board_triboard_TC3X2_V1.0/board.c ../tc3xx-platform/bsp/board/board_triboard_TC3X3_V1.0/board.c ../tc3xx-platform/bsp/board/board_triboard_TC3X4L_V1.0/board.c ../tc3xx-platform/bsp/board/board_triboard_TC3X4T_V1.0/board.c ../tc3xx-platform/bsp/board/board_triboard_TC3X5_V1.X/board.c ../tc3xx-platform/bsp/board/board_triboard_TC3X6_ADAS_V1.0/board.c ../tc3xx-platform/bsp/board/board_triboard_TC3X6_V1.0/board.c ../tc3xx-platform/bsp/board/board_triboard_TC3X7_ADAS_V1.0/board.c ../tc3xx-platform/bsp/board/board_triboard_TC3X7_ADAS_V2.0/board.c ../tc3xx-platform/bsp/board/board_triboard_TC3X7_V1.0/board.c ../tc3xx-platform/bsp/board/board_triboard_TC3X7_V2.0/board.c ../tc3xx-platform/bsp/board/board_triboard_TC3X9_V1.0/board.c ../tc3xx-platform/bsp/board/board_triboard_TC3X9_V2.0/board.c ../tc3xx-platform/bsp/board/bsp_board.c ../tc3xx-platform/bsp/isr/bsp_interrupt_vector_table.c ../tc3xx-platform/bsp/isr/bsp_isr.c ../tc3xx-platform/bsp/isr/bsp_trap_vector_table.c ../tc3xx-platform/bsp/uc/bsp_uc.c ../tc3xx-platform/bsp/uc/tricore_wdtcon.c ../tc3xx-platform/bsp/uc/uc_tc33/uc_tc33.c ../tc3xx-platform/bsp/uc/uc_tc39/uc_tc39.c ../tc3xx-platform/crt0/uc_tc33_bmhd.c ../tc3xx-platform/crt0/uc_tc39_bmhd.c
CPP_SOURCE_FILES              ?=
ADDITIONAL_OBJECTS            ?=
DEFINED_PREPROCESSOR_MACROS   ?= __TC33XX__=1 LITEKIT_TCXX4_V1=1
UNDEFINED_PREPROCESSOR_MACROS ?=
TARGET_FLAGS                  ?= -march=tc162
ASM_COMPILER_FLAGS            ?= -O0 -std=c11 -g3 -Wall -Wextra -Wconversion
C_COMPILER_FLAGS              ?= -O0 -std=c11 -g3 -Wall -Wextra -Wconversion
CPP_COMPILER_FLAGS            ?=
LINKER_FLAGS                  ?= -Wl,--gc-sections
ARCHIVER_FLAGS                ?=
IMG_FILE_CREATOR_FLAGS        ?=
EXT_LIST_CREATOR_FLAGS        ?= -S -x -C -d -l -r -t -w

##========================== User Section 002 Begin ==========================##
##========================== User Section 002  End  ==========================##

# Environment identification
ifeq ($(OS),Windows_NT)
ifneq ($(MSYSTEM),)
ENV_PLATFORM ?= LINUXLIKE
ENV_SHELL    ?= LINUXLIKEONWINDOWS
else ifneq ($(findstring cygdrive,$(PATH))$(findstring Cygdrive,$(PATH))$(findstring cygwin,$(PATH))$(findstring Cygwin,$(PATH)),)
ENV_PLATFORM ?= LINUXLIKE
ENV_SHELL    ?= LINUXLIKEONWINDOWS
else
ENV_PLATFORM ?= WINDOWSLIKE
ENV_SHELL    ?= WINDOWSLIKE
endif
else
ENV_PLATFORM ?= LINUXLIKE
ENV_SHELL    ?= LINUXLIKE
endif

# Environment-dependent function definitions
ifeq ($(ENV_PLATFORM),WINDOWSLIKE)
SHELL        = cmd.exe
ENV_NORMPATH = $(subst /,\,$1)
ENV_ECHO     = @echo $1
ENV_MKDIR    = @mkdir "$(call ENV_NORMPATH,$1)" >nul 2>&1 || (exit 0)
ENV_RMDIR    = @rmdir /S /Q "$(call ENV_NORMPATH,$1)" >nul 2>&1 || (exit 0)
ENV_CPFILE   = @copy /Y "$(call ENV_NORMPATH,$1)" "$(call ENV_NORMPATH,$2)" >nul 2>&1 || (exit 0)
ENV_RMFILE   = @del /F /Q "$(call ENV_NORMPATH,$1)" >nul 2>&1 || (exit 0)
ENV_RMFILES  = @del /F /Q /S "$(call ENV_NORMPATH,$1$2)" >nul 2>&1 || (exit 0)
else ifeq ($(ENV_PLATFORM),LINUXLIKE)
ENV_NORMPATH = $(subst \,/,$1)
ENV_ECHO     = @printf "%s\n" "$1"
ENV_MKDIR    = @mkdir -p "$(call ENV_NORMPATH,$1)"
ENV_RMDIR    = @rm -rf "$(call ENV_NORMPATH,$1)"
ENV_CPFILE   = @cp -f "$(call ENV_NORMPATH,$1)" "$(call ENV_NORMPATH,$2)" 2>/dev/null || true
ENV_RMFILE   = @rm -rf "$(call ENV_NORMPATH,$1)"
ENV_RMFILES  = @find "$(call ENV_NORMPATH,$1)" -type f -name '$2' -delete 2>/dev/null || true
endif

##========================== User Section 003 Begin ==========================##
##========================== User Section 003  End  ==========================##

# Helper functions
PARDIR_TO_OUTDIR   = $(subst ../,o/,$1)
ESCSP_TO_NORMSP    = $(subst \ , ,$1)
ESCSP_TO_REPLCHAR  = $(subst \ ,<,$1)
REPLCHAR_TO_ESCSP  = $(subst <,\ ,$1)
REPLCHAR_TO_NORMSP = $(subst <, ,$1)
SRC_TO_OBJ_FILE    = $(call PARDIR_TO_OUTDIR,$(addsuffix .o,$1))
SRC_TO_DEP_FILE    = $(call PARDIR_TO_OUTDIR,$(addsuffix .o.d,$1))

# Helper variables
OBJECT_FILES       := $(strip $(call REPLCHAR_TO_ESCSP,$(call SRC_TO_OBJ_FILE,$(call ESCSP_TO_REPLCHAR,$(ASM_SOURCE_FILES) $(C_SOURCE_FILES) $(CPP_SOURCE_FILES)))))
DEPENDENCY_FILES   := $(strip $(call REPLCHAR_TO_ESCSP,$(call SRC_TO_DEP_FILE,$(call ESCSP_TO_REPLCHAR,$(ASM_SOURCE_FILES) $(C_SOURCE_FILES) $(CPP_SOURCE_FILES)))))
OUTPUT_DIRS        := $(strip $(sort $(dir $(call ESCSP_TO_REPLCHAR,$(OBJECT_FILES)))))
EXECUTABLE_FILE    := $(ARTIFACT_BASE_NAME)$(ARTIFACT_EXTENSION)
STATICLIB_FILE     := lib$(ARTIFACT_BASE_NAME).a
INTEL_HEX_FILE     := $(ARTIFACT_BASE_NAME).hex
RAW_BINARY_FILE    := $(ARTIFACT_BASE_NAME).bin
MOTOROLA_SREC_FILE := $(ARTIFACT_BASE_NAME).srec
LST_FILE_OF_EXE    := $(ARTIFACT_BASE_NAME).lst
LST_FILE_OF_SLIB   := lib$(ARTIFACT_BASE_NAME).lst
MAP_FILE           := $(ARTIFACT_BASE_NAME).map
MEM_FILE           := $(ARTIFACT_BASE_NAME).mem
RESPONSE_FILE_ID   := # Intentionally empty variable

# Prevent printed messages from interleaving each other
ifneq ($(filter build_executable build_staticlib install_executable install_staticlib all build install main-build,$(MAKECMDGOALS)),)
MAKEFLAGS += --output-sync=target
endif

##========================== User Section 004 Begin ==========================##
##========================== User Section 004  End  ==========================##

# Linker flag that tells the linker to output a memory consumption file
LINKER_FLAG_GENERATE_MEM_FILE ?= -Wl,--print-memory-usage > "$(call ESCSP_TO_NORMSP,$(MEM_FILE))"

# Define this variable to 1 to skip the generation of the compile_commands.json file
COMPILE_COMMANDS_JSON_GENERATION_SKIP ?= 0

# Commands to execute before the building process
PRE_BUILD_STEPS ?=

# Commands to execute after the building process
POST_BUILD_STEPS ?=

##========================== User Section 005 Begin ==========================##
##========================== User Section 005  End  ==========================##

# Make compatibility check
ifeq ($(filter $(firstword $(subst ., ,$(MAKE_VERSION))),4),)
$(error Makefile error. Current make version ($(MAKE_VERSION)) is incompatible with required make version (4.x.y). Please, install a newer version of make)
endif

# Whitespace definitions
EMPTY :=
SPACE := $(EMPTY) $(EMPTY)
COMMA := ,
define NEWLINE

$(EMPTY)
endef

##========================== User Section 006 Begin ==========================##
##========================== User Section 006  End  ==========================##

# Compile rule: Compiles an assembly source file into an object file
define ASM_COMPILE_RULE ?=
	$(call ENV_ECHO,# [$(BUILD_NAME)] Compile : $(call ESCSP_TO_NORMSP,$2))
	$(file >o/$4.rsp, \
		$(TARGET_FLAGS)$(NEWLINE) \
		$(ASM_COMPILER_FLAGS)$(NEWLINE) \
		-fmessage-length=0$(NEWLINE) \
		$(call REPLCHAR_TO_NORMSP,$(addprefix -I",$(addsuffix ",$(call ESCSP_TO_REPLCHAR,$(INCLUDE_DIRS)))))$(NEWLINE) \
		$(call REPLCHAR_TO_NORMSP,$(addprefix -include",$(addsuffix ",$(call ESCSP_TO_REPLCHAR,$(INCLUDE_FILES)))))$(NEWLINE) \
		$(addprefix -D,$(DEFINED_PREPROCESSOR_MACROS))$(NEWLINE) \
		$(addprefix -U,$(UNDEFINED_PREPROCESSOR_MACROS))$(NEWLINE) \
		-MMD -MF "$(call ESCSP_TO_NORMSP,$3)"$(NEWLINE) \
		-o "$(call ESCSP_TO_NORMSP,$2)")
	@"$(call ESCSP_TO_NORMSP,$(TOOLCHAIN_PREFIX)$(ASM_COMPILER_PATH))" @"o/$4.rsp" \
		-c "$(call REPLCHAR_TO_NORMSP,$(abspath $(call ESCSP_TO_REPLCHAR,$1)))"
	$(call ENV_RMFILE,o/$4.rsp)
endef

# Compile rule: Compiles a C source file into an object file
define C_COMPILE_RULE ?=
	$(call ENV_ECHO,# [$(BUILD_NAME)] Compile : $(call ESCSP_TO_NORMSP,$2))
	$(file >o/$4.rsp, \
		$(TARGET_FLAGS)$(NEWLINE) \
		$(C_COMPILER_FLAGS)$(NEWLINE) \
		-fmessage-length=0$(NEWLINE) \
		$(call REPLCHAR_TO_NORMSP,$(addprefix -I",$(addsuffix ",$(call ESCSP_TO_REPLCHAR,$(INCLUDE_DIRS)))))$(NEWLINE) \
		$(call REPLCHAR_TO_NORMSP,$(addprefix -include",$(addsuffix ",$(call ESCSP_TO_REPLCHAR,$(INCLUDE_FILES)))))$(NEWLINE) \
		$(addprefix -D,$(DEFINED_PREPROCESSOR_MACROS))$(NEWLINE) \
		$(addprefix -U,$(UNDEFINED_PREPROCESSOR_MACROS))$(NEWLINE) \
		-MMD -MF "$(call ESCSP_TO_NORMSP,$3)"$(NEWLINE) \
		-o "$(call ESCSP_TO_NORMSP,$2)")
	@"$(call ESCSP_TO_NORMSP,$(TOOLCHAIN_PREFIX)$(C_COMPILER_PATH))" @"o/$4.rsp" \
		-c "$(call REPLCHAR_TO_NORMSP,$(abspath $(call ESCSP_TO_REPLCHAR,$1)))"
	$(call ENV_RMFILE,o/$4.rsp)
endef

# Compile rule: Compiles a C++ source file into an object file
define CPP_COMPILE_RULE ?=
	$(call ENV_ECHO,# [$(BUILD_NAME)] Compile : $(call ESCSP_TO_NORMSP,$2))
	$(file >o/$4.rsp, \
		$(TARGET_FLAGS)$(NEWLINE) \
		$(CPP_COMPILER_FLAGS)$(NEWLINE) \
		-fmessage-length=0$(NEWLINE) \
		$(call REPLCHAR_TO_NORMSP,$(addprefix -I",$(addsuffix ",$(call ESCSP_TO_REPLCHAR,$(INCLUDE_DIRS)))))$(NEWLINE) \
		$(call REPLCHAR_TO_NORMSP,$(addprefix -include",$(addsuffix ",$(call ESCSP_TO_REPLCHAR,$(INCLUDE_FILES)))))$(NEWLINE) \
		$(addprefix -D,$(DEFINED_PREPROCESSOR_MACROS))$(NEWLINE) \
		$(addprefix -U,$(UNDEFINED_PREPROCESSOR_MACROS))$(NEWLINE) \
		-MMD -MF "$(call ESCSP_TO_NORMSP,$3)"$(NEWLINE) \
		-o "$(call ESCSP_TO_NORMSP,$2)")
	@"$(call ESCSP_TO_NORMSP,$(TOOLCHAIN_PREFIX)$(CPP_COMPILER_PATH))" @"o/$4.rsp" \
		-c "$(call REPLCHAR_TO_NORMSP,$(abspath $(call ESCSP_TO_REPLCHAR,$1)))"
	$(call ENV_RMFILE,o/$4.rsp)
endef

# Link rule: Links all object files into an executable file
define LINK_RULE ?=
	$(call ENV_ECHO,# [$(BUILD_NAME)] Link    : $(call ESCSP_TO_NORMSP,$2))
	$(file >o/link.rsp, \
		$(TARGET_FLAGS)$(NEWLINE) \
		$(LINKER_FLAGS)$(NEWLINE) \
		-fmessage-length=0$(NEWLINE) \
		$(call REPLCHAR_TO_NORMSP,$(addprefix -T",$(addsuffix ",$(call ESCSP_TO_REPLCHAR,$(LINKER_SCRIPTS)))))$(NEWLINE) \
		$(call REPLCHAR_TO_NORMSP,$(addprefix ",$(addsuffix ",$(call ESCSP_TO_REPLCHAR,$1))))$(NEWLINE) \
		$(call REPLCHAR_TO_NORMSP,$(addprefix ",$(addsuffix ",$(call ESCSP_TO_REPLCHAR,$(ADDITIONAL_OBJECTS)))))$(NEWLINE) \
		$(call REPLCHAR_TO_NORMSP,$(addprefix -L",$(addsuffix ",$(call ESCSP_TO_REPLCHAR,$(LINKER_SEARCH_DIRS)))))$(NEWLINE) \
		-Wl,--start-group$(NEWLINE) \
		$(call REPLCHAR_TO_NORMSP,$(addprefix -l",$(addsuffix ",$(call ESCSP_TO_REPLCHAR,$(LINKER_ADDITIONAL_LIBS)))))$(NEWLINE) \
		-Wl,--end-group$(NEWLINE) \
		-o "$(call ESCSP_TO_NORMSP,$2)"$(NEWLINE) \
		-Wl,-Map,"$(call ESCSP_TO_NORMSP,$(MAP_FILE))",--cref)
	@"$(call ESCSP_TO_NORMSP,$(TOOLCHAIN_PREFIX)$(LINKER_PATH))" @"o/link.rsp" \
		$(LINKER_FLAG_GENERATE_MEM_FILE)
	$(call ENV_RMFILE,o/link.rsp)
endef

# Archive rule: Packs all object files into a static library file
define ARCHIVE_RULE ?=
	$(call ENV_ECHO,# [$(BUILD_NAME)] Archive : $(call ESCSP_TO_NORMSP,$2))
	$(file >o/archive.rsp, \
		$(ARCHIVER_FLAGS)$(NEWLINE) \
		-rcs "$(call ESCSP_TO_NORMSP,$2)"$(NEWLINE) \
		$(call REPLCHAR_TO_NORMSP,$(addprefix ",$(addsuffix ",$(call ESCSP_TO_REPLCHAR,$1))))$(NEWLINE) \
		$(call REPLCHAR_TO_NORMSP,$(addprefix ",$(addsuffix ",$(call ESCSP_TO_REPLCHAR,$(ADDITIONAL_OBJECTS))))))
	@"$(call ESCSP_TO_NORMSP,$(TOOLCHAIN_PREFIX)$(ARCHIVER_PATH))" @"o/archive.rsp"
	$(call ENV_RMFILE,o/archive.rsp)
endef

# Install rule: Copies the executable file or static library file to the destination directory
define INSTALL_RULE ?=
	$(call ENV_ECHO,# [$(BUILD_NAME)] Install : $(call ESCSP_TO_NORMSP,$2))
	$(call ENV_CPFILE,$(call ESCSP_TO_NORMSP,$1),$(call ESCSP_TO_NORMSP,$2))
endef

# Intel Hex file creation rule: Creates Intel Hex file from the executable file
define HEX_RULE ?=
	$(call ENV_ECHO,# [$(BUILD_NAME)] IHex    : $(call ESCSP_TO_NORMSP,$2))
	@"$(call ESCSP_TO_NORMSP,$(TOOLCHAIN_PREFIX)$(IMG_FILE_CREATOR_PATH))" "$(call ESCSP_TO_NORMSP,$1)" "$(call ESCSP_TO_NORMSP,$2)" $(IMG_FILE_CREATOR_FLAGS) -Oihex || echo Unable to generate Intel-Hex file. > "$(call ESCSP_TO_NORMSP,$2)"
endef

# Raw binary file creation rule: Creates raw binary file from the executable file
define BIN_RULE ?=
	$(call ENV_ECHO,# [$(BUILD_NAME)] Bin     : $(call ESCSP_TO_NORMSP,$2))
	@"$(call ESCSP_TO_NORMSP,$(TOOLCHAIN_PREFIX)$(IMG_FILE_CREATOR_PATH))" "$(call ESCSP_TO_NORMSP,$1)" "$(call ESCSP_TO_NORMSP,$2)" $(IMG_FILE_CREATOR_FLAGS) -Obinary || echo Unable to generate binary file. > "$(call ESCSP_TO_NORMSP,$2)"
endef

# Motorola S-Record file creation rule: Creates Motorola S-Record file from the executable file
define SREC_RULE ?=
	$(call ENV_ECHO,# [$(BUILD_NAME)] SRec    : $(call ESCSP_TO_NORMSP,$2))
	@"$(call ESCSP_TO_NORMSP,$(TOOLCHAIN_PREFIX)$(IMG_FILE_CREATOR_PATH))" "$(call ESCSP_TO_NORMSP,$1)" "$(call ESCSP_TO_NORMSP,$2)" $(IMG_FILE_CREATOR_FLAGS) -Osrec || echo Unable to generate S-Record file. > "$(call ESCSP_TO_NORMSP,$2)"
endef

# Extended listing file creation rule: Creates extended listing file from the executable file
define LST_RULE ?=
	$(call ENV_ECHO,# [$(BUILD_NAME)] List    : $(call ESCSP_TO_NORMSP,$2))
	@"$(call ESCSP_TO_NORMSP,$(TOOLCHAIN_PREFIX)$(EXT_LIST_CREATOR_PATH))" $(EXT_LIST_CREATOR_FLAGS) "$(call ESCSP_TO_NORMSP,$1)" > "$(call ESCSP_TO_NORMSP,$2)" || echo Unable to generate extended listing file. > "$(call ESCSP_TO_NORMSP,$2)"
endef

# Size printing rule: Prints information about executable file section sizes
define SIZE_RULE ?=
	$(call ENV_ECHO,# [$(BUILD_NAME)] Size)
	@"$(call ESCSP_TO_NORMSP,$(TOOLCHAIN_PREFIX)$(SIZE_PRINTER_PATH))"  "$(call ESCSP_TO_NORMSP,$1)"
endef

# Clean rule: Cleans built, installed and intermediate files
define CLEAN_RULE ?=
	$(call ENV_ECHO,# [$(BUILD_NAME)] Clean)
	$(call ENV_RMFILES,o/,*.d)
	$(call ENV_RMFILES,o/,*.o)
	$(call ENV_RMFILE,$(call ESCSP_TO_NORMSP,$(EXECUTABLE_FILE)))
	$(call ENV_RMFILE,$(call ESCSP_TO_NORMSP,$(STATICLIB_FILE)))
	$(call ENV_RMFILE,$(call ESCSP_TO_NORMSP,$(INSTALL_DIR)/$(EXECUTABLE_FILE)))
	$(call ENV_RMFILE,$(call ESCSP_TO_NORMSP,$(INSTALL_DIR)/$(STATICLIB_FILE)))
	$(call ENV_RMFILE,$(call ESCSP_TO_NORMSP,$(LST_FILE_OF_EXE)))
	$(call ENV_RMFILE,$(call ESCSP_TO_NORMSP,$(LST_FILE_OF_SLIB)))
	$(call ENV_RMFILE,$(call ESCSP_TO_NORMSP,$(INTEL_HEX_FILE)))
	$(call ENV_RMFILE,$(call ESCSP_TO_NORMSP,$(RAW_BINARY_FILE)))
	$(call ENV_RMFILE,$(call ESCSP_TO_NORMSP,$(MOTOROLA_SREC_FILE)))
	$(call ENV_RMFILE,$(call ESCSP_TO_NORMSP,$(MAP_FILE)))
	$(call ENV_RMFILE,$(call ESCSP_TO_NORMSP,$(MEM_FILE)))
	$(call ENV_RMFILE,.tmp.pre_build_step.tmp)
endef

# Recursive rule: Executes make recursively with the specified target
define RECURSIVE_RULE ?=
	$(call ENV_ECHO,# [$(BUILD_NAME)])
	+"$(MAKE)" $1
endef

# Compilation database creation rules: help creating the compile_commands.json file
define COMPILE_COMMAND_RULE ?=
\"$(call ESCSP_TO_NORMSP,$(TOOLCHAIN_PREFIX)$2)\" \
$(TARGET_FLAGS) \
$3 \
-fmessage-length=0 \
$(call REPLCHAR_TO_NORMSP,$(addprefix -I\",$(addsuffix \",$(call ESCSP_TO_REPLCHAR,$(INCLUDE_DIRS))))) \
$(call REPLCHAR_TO_NORMSP,$(addprefix -include\",$(addsuffix \",$(call ESCSP_TO_REPLCHAR,$(INCLUDE_FILES))))) \
$(addprefix -D,$(DEFINED_PREPROCESSOR_MACROS)) \
$(addprefix -U,$(UNDEFINED_PREPROCESSOR_MACROS)) \
-MMD -MF \"$(call REPLCHAR_TO_NORMSP,$(call SRC_TO_DEP_FILE,$1))\" \
-o \"$(call REPLCHAR_TO_NORMSP,$(call SRC_TO_OBJ_FILE,$1))\" \
-c \"$(call REPLCHAR_TO_NORMSP,$1)\"
endef
define COMPILE_COMMANDS_JSON_ENTRY_RULE ?=
$(SPACE)$(SPACE)$(SPACE){$(NEWLINE) \
$(SPACE)$(SPACE)$(SPACE)$(SPACE)$(SPACE)$(SPACE)$(SPACE)"directory": "$(realpath $(CURDIR))",$(NEWLINE) \
$(SPACE)$(SPACE)$(SPACE)$(SPACE)$(SPACE)$(SPACE)$(SPACE)"command": "$(strip $(call COMPILE_COMMAND_RULE,$1,$2,$3))",$(NEWLINE) \
$(SPACE)$(SPACE)$(SPACE)$(SPACE)$(SPACE)$(SPACE)$(SPACE)"file": "$(call REPLCHAR_TO_NORMSP,$1)",$(NEWLINE) \
$(SPACE)$(SPACE)$(SPACE)$(SPACE)$(SPACE)$(SPACE)$(SPACE)"output": "$(call REPLCHAR_TO_NORMSP,$(call SRC_TO_OBJ_FILE,$1))"$(NEWLINE) \
$(SPACE)$(SPACE)$(SPACE)},
endef

# Compilation database creation variables: compile_commands.json string
COMPILE_COMMANDS_JSON_STRING := [$(NEWLINE)
ifneq ($(strip $(ASM_SOURCE_FILES)),)
COMPILE_COMMANDS_JSON_STRING += $(foreach s,$(call ESCSP_TO_REPLCHAR,$(ASM_SOURCE_FILES)),$(call COMPILE_COMMANDS_JSON_ENTRY_RULE,$(s),$(ASM_COMPILER_PATH),$(ASM_COMPILER_FLAGS))$(NEWLINE))
endif
ifneq ($(strip $(C_SOURCE_FILES)),)
COMPILE_COMMANDS_JSON_STRING += $(foreach s,$(call ESCSP_TO_REPLCHAR,$(C_SOURCE_FILES)),$(call COMPILE_COMMANDS_JSON_ENTRY_RULE,$(s),$(C_COMPILER_PATH),$(C_COMPILER_FLAGS))$(NEWLINE))
endif
ifneq ($(strip $(CPP_SOURCE_FILES)),)
COMPILE_COMMANDS_JSON_STRING += $(foreach s,$(call ESCSP_TO_REPLCHAR,$(CPP_SOURCE_FILES)),$(call COMPILE_COMMANDS_JSON_ENTRY_RULE,$(s),$(CPP_COMPILER_PATH),$(CPP_COMPILER_FLAGS))$(NEWLINE))
endif
COMPILE_COMMANDS_JSON_STRING += ]
COMPILE_COMMANDS_JSON_STRING := $(subst $(SPACE)],],$(COMPILE_COMMANDS_JSON_STRING))
COMPILE_COMMANDS_JSON_STRING := $(subst [$(NEWLINE)],[],$(COMPILE_COMMANDS_JSON_STRING))
COMPILE_COMMANDS_JSON_STRING := $(subst }$(COMMA)$(NEWLINE)],}$(NEWLINE)],$(COMPILE_COMMANDS_JSON_STRING))

##========================== User Section 007 Begin ==========================##
##========================== User Section 007  End  ==========================##

# Main target: Help
.PHONY: help
help:
	$(call ENV_ECHO,# Targets:)
	$(call ENV_ECHO,# - build_executable     : Build executable artifact file)
	$(call ENV_ECHO,# - build_staticlib      : Build static library artifact file)
	$(call ENV_ECHO,# - install_executable   : Build and install executable artifact file)
	$(call ENV_ECHO,# - install_staticlib    : Build and install static library artifact file)
	$(call ENV_ECHO,# - clean                : Clean built, installed and intermediate files)
	$(call ENV_ECHO,# - rebuild_executable   : Rebuild executable artifact file)
	$(call ENV_ECHO,# - rebuild_staticlib    : Rebuild static library artifact file)
	$(call ENV_ECHO,# - reinstall_executable : Rebuild and install executable artifact file)
	$(call ENV_ECHO,# - reinstall_staticlib  : Rebuild and install static library artifact file)
	$(call ENV_ECHO,# - all                  : Build executable or static library artifact file (depending on the variable BUILD_TYPE))
	$(call ENV_ECHO,# - build                : Build executable or static library artifact file (depending on the variable BUILD_TYPE))
	$(call ENV_ECHO,# - install              : Build and install executable or static library artifact file (depending on the variable BUILD_TYPE))
	$(call ENV_ECHO,# - rebuild              : Rebuild executable or static library artifact file (depending on the variable BUILD_TYPE))
	$(call ENV_ECHO,# - reinstall            : Rebuild and install executable or static library artifact file (depending on the variable BUILD_TYPE))

# Main target: Build executable file
.PHONY: build_executable
build_executable: $(EXECUTABLE_FILE) $(RAW_BINARY_FILE) $(MOTOROLA_SREC_FILE) $(LST_FILE_OF_EXE) $(INTEL_HEX_FILE)
	$(call SIZE_RULE,$(EXECUTABLE_FILE))
	$(call ENV_RMFILE,.tmp.pre_build_step.tmp)
ifneq ($(strip $(POST_BUILD_STEPS)),)
	$(call ENV_ECHO,# [$(BUILD_NAME)] Post-build steps)
	$(POST_BUILD_STEPS)
endif

# Main target: Build static library file
.PHONY: build_staticlib
build_staticlib: $(STATICLIB_FILE) $(LST_FILE_OF_SLIB)
	$(call SIZE_RULE,$(STATICLIB_FILE))
	$(call ENV_RMFILE,.tmp.pre_build_step.tmp)
ifneq ($(strip $(POST_BUILD_STEPS)),)
	$(call ENV_ECHO,# [$(BUILD_NAME)] Post-build steps)
	$(POST_BUILD_STEPS)
endif

# Main target: Install executable file
.PHONY: install_executable
install_executable: $(EXECUTABLE_FILE) $(INSTALL_DIR)/$(EXECUTABLE_FILE)
	$(call SIZE_RULE,$(INSTALL_DIR)/$(EXECUTABLE_FILE))
	$(call ENV_RMFILE,.tmp.pre_build_step.tmp)
ifneq ($(strip $(POST_BUILD_STEPS)),)
	$(call ENV_ECHO,# [$(BUILD_NAME)] Post-build steps)
	$(POST_BUILD_STEPS)
endif

# Main target: Install static library file
.PHONY: install_staticlib
install_staticlib: $(STATICLIB_FILE) $(INSTALL_DIR)/$(STATICLIB_FILE)
	$(call SIZE_RULE,$(INSTALL_DIR)/$(STATICLIB_FILE))
	$(call ENV_RMFILE,.tmp.pre_build_step.tmp)
ifneq ($(strip $(POST_BUILD_STEPS)),)
	$(call ENV_ECHO,# [$(BUILD_NAME)] Post-build steps)
	$(POST_BUILD_STEPS)
endif

# Main target: Clean built, installed and intermediate files
.PHONY: clean
clean:
	$(call CLEAN_RULE)

# Main target: Rebuild executable file
.PHONY: rebuild_executable
rebuild_executable: clean
	$(call RECURSIVE_RULE,build_executable)

# Main target: Rebuild static library file
.PHONY: rebuild_staticlib
rebuild_staticlib: clean
	$(call RECURSIVE_RULE,build_staticlib)

# Main target: Reinstall executable file
.PHONY: reinstall_executable
reinstall_executable: clean
	$(call RECURSIVE_RULE,install_executable)

# Main target: Reinstall static library file
.PHONY: reinstall_staticlib
reinstall_staticlib: clean
	$(call RECURSIVE_RULE,install_staticlib)

# Main target: All
.PHONY: all
all: build_$(BUILD_TYPE)

# Main target: Build executable file or static library file
.PHONY: build
build: build_$(BUILD_TYPE)

# Main target: Install executable file or static library file
.PHONY: install
install: install_$(BUILD_TYPE)

# Main target: Rebuild executable file or static library file
.PHONY: rebuild
rebuild: rebuild_$(BUILD_TYPE)

# Main target: Reinstall executable file or static library file
.PHONY: reinstall
reinstall: reinstall_$(BUILD_TYPE)

# Compatibility target: Eclipse CDT (main-build)
.PHONY: main-build
main-build: build_$(BUILD_TYPE)

# Helper target: Pre-build steps
.tmp.pre_build_step.tmp:
ifneq ($(strip $(PRE_BUILD_STEPS)),)
	$(call ENV_ECHO,# [$(BUILD_NAME)] Pre-build steps)
	$(PRE_BUILD_STEPS)
endif
	$(file >.tmp.pre_build_step.tmp,.)

# Helper target: Create compile_commands.json file
.PHONY: _create_compile_commands_json_
_create_compile_commands_json_: .tmp.pre_build_step.tmp
ifeq ($(COMPILE_COMMANDS_JSON_GENERATION_SKIP),0)
	$(file >compile_commands.json,$(COMPILE_COMMANDS_JSON_STRING))
endif

# Helper target: Create output directory structure
.PHONY: _create_out_dirs_
_create_out_dirs_: _create_compile_commands_json_
	$(foreach d,$(OUTPUT_DIRS),$(call ENV_MKDIR,$(call REPLCHAR_TO_NORMSP,$(d)))$(NEWLINE))
ifneq ($(filter install_executable install_staticlib install,$(MAKECMDGOALS)),)
	$(call ENV_MKDIR,$(call ESCSP_TO_NORMSP,$(INSTALL_DIR)))
endif

##========================== User Section 008 Begin ==========================##
##========================== User Section 008  End  ==========================##

# Use HEX_RULE to create Intel Hex file
$(INTEL_HEX_FILE): $(EXECUTABLE_FILE)
	$(call HEX_RULE,$(EXECUTABLE_FILE),$(INTEL_HEX_FILE))

# Use BIN_RULE to create raw binary file
$(RAW_BINARY_FILE): $(EXECUTABLE_FILE)
	$(call BIN_RULE,$(EXECUTABLE_FILE),$(RAW_BINARY_FILE))

# Use SREC_RULE to create Motorola S-Record file
$(MOTOROLA_SREC_FILE): $(EXECUTABLE_FILE)
	$(call SREC_RULE,$(EXECUTABLE_FILE),$(MOTOROLA_SREC_FILE))

# Use LST_RULE to create extended listing file
$(LST_FILE_OF_EXE): $(EXECUTABLE_FILE)
	$(call LST_RULE,$(EXECUTABLE_FILE),$(LST_FILE_OF_EXE))

# Use LST_RULE to create extended listing file
$(LST_FILE_OF_SLIB): $(STATICLIB_FILE)
	$(call LST_RULE,$(STATICLIB_FILE),$(LST_FILE_OF_SLIB))

# Use LINK_RULE to create executable file
$(EXECUTABLE_FILE): $(OBJECT_FILES) $(LINKER_SCRIPTS)
	$(call LINK_RULE,$(OBJECT_FILES),$(EXECUTABLE_FILE))

# Use ARCHIVE_RULE to create static library file
$(STATICLIB_FILE): $(OBJECT_FILES)
	$(call ARCHIVE_RULE,$(OBJECT_FILES),$(STATICLIB_FILE))

# Use INSTALL_RULE to install executable file
$(INSTALL_DIR)/$(EXECUTABLE_FILE): $(EXECUTABLE_FILE)
	$(call INSTALL_RULE,$(EXECUTABLE_FILE),$(INSTALL_DIR)/$(EXECUTABLE_FILE))

# Use INSTALL_RULE to install static library file
$(INSTALL_DIR)/$(STATICLIB_FILE): $(STATICLIB_FILE)
	$(call INSTALL_RULE,$(STATICLIB_FILE),$(INSTALL_DIR)/$(STATICLIB_FILE))

# Use ASM_COMPILE_RULE to create object and dependency files
define GENERATE_ASM_COMPILATION_RECIPES ?=
$2: $1 | _create_out_dirs_
	$$(call ASM_COMPILE_RULE,$1,$2,$3,o$4)
$3: $1 | _create_out_dirs_
	$$(call ASM_COMPILE_RULE,$1,$2,$3,d$4)
endef
# Use C_COMPILE_RULE to create object and dependency files
define GENERATE_C_COMPILATION_RECIPES ?=
$2: $1 | _create_out_dirs_
	$$(call C_COMPILE_RULE,$1,$2,$3,o$4)
$3: $1 | _create_out_dirs_
	$$(call C_COMPILE_RULE,$1,$2,$3,d$4)
endef
# Use CPP_COMPILE_RULE to create object and dependency files
define GENERATE_CPP_COMPILATION_RECIPES ?=
$2: $1 | _create_out_dirs_
	$$(call CPP_COMPILE_RULE,$1,$2,$3,o$4)
$3: $1 | _create_out_dirs_
	$$(call CPP_COMPILE_RULE,$1,$2,$3,d$4)
endef
# Generate compilation recipes
$(foreach s,$(call ESCSP_TO_REPLCHAR,$(ASM_SOURCE_FILES)), \
	$(eval $(call GENERATE_ASM_COMPILATION_RECIPES, \
	$(call REPLCHAR_TO_ESCSP,$(s)),$(call REPLCHAR_TO_ESCSP,$(call SRC_TO_OBJ_FILE,$(s))),$(call REPLCHAR_TO_ESCSP,$(call SRC_TO_DEP_FILE,$(s))),$(eval RESPONSE_FILE_ID += x)$(words $(RESPONSE_FILE_ID)))))
$(foreach s,$(call ESCSP_TO_REPLCHAR,$(C_SOURCE_FILES)), \
	$(eval $(call GENERATE_C_COMPILATION_RECIPES, \
	$(call REPLCHAR_TO_ESCSP,$(s)),$(call REPLCHAR_TO_ESCSP,$(call SRC_TO_OBJ_FILE,$(s))),$(call REPLCHAR_TO_ESCSP,$(call SRC_TO_DEP_FILE,$(s))),$(eval RESPONSE_FILE_ID += x)$(words $(RESPONSE_FILE_ID)))))
$(foreach s,$(call ESCSP_TO_REPLCHAR,$(CPP_SOURCE_FILES)), \
	$(eval $(call GENERATE_CPP_COMPILATION_RECIPES, \
	$(call REPLCHAR_TO_ESCSP,$(s)),$(call REPLCHAR_TO_ESCSP,$(call SRC_TO_OBJ_FILE,$(s))),$(call REPLCHAR_TO_ESCSP,$(call SRC_TO_DEP_FILE,$(s))),$(eval RESPONSE_FILE_ID += x)$(words $(RESPONSE_FILE_ID)))))

##========================== User Section 009 Begin ==========================##
##========================== User Section 009  End  ==========================##

# Include dependency files created by the toolchain
ifneq ($(filter build_executable build_staticlib install_executable install_staticlib all build install main-build,$(MAKECMDGOALS)),)
-include $(DEPENDENCY_FILES)
endif

##========================== User Section 010 Begin ==========================##
##========================== User Section 010  End  ==========================##
