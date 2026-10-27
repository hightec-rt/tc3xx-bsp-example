# TC3xx BSP example

## Example overview

A **TC3xx BSP example** is a small functional project designed to simplify an evaluation phase of the AURIX™ TC3xx microcontroller architecture with the HighTec LLVM and GCC-based TriCore toolchains. It comes with necessary low-level functions like a startup code, minimalistic hardware and toolchain abstraction, and predefined memory partitioning.

The example demonstrates simple LED blinking, where each active core toggles an LED via a dedicated microcontroller pin. The initialization code sets the toggling period in multiples of 250 ms, scaled according to the current Core ID. In addition to blinking an LED, this project demonstrates how to create per-core `main` functions (using a small counter example), configure linker sections, and define per-core code and global variables.

### Supported targets

- Evaluation board
  - **AURIX™ Application Kit TC3x7 V2.0** (with **TC397** microcontroller)
  - **AURIX™ TriBoard TC3x9 TH V2.01** (with **TC399XE** microcontroller)
  - **AURIX™ Lite Kit TCxx4 V1** (with **TC334** microcontroller)

### Required toolchains

- HighTec TriCore Development Platform v11.0.0 (LLVM)
- HighTec TriCore Development Platform v4.9.4.1 (GCC)

## Build

The project can be built several different ways:

- in command line
- in [HighTec IDE](https://docs.hightec-rt.com/component-ide-qsg/chapter/chapter-software-installation.html)
- in [VSCode IDE](https://code.visualstudio.com)
- in [Zed IDE](https://zed.dev)

### Makefile

The project can contain multiple build configurations, e.g. a separate build configuration for every supported board or microcontroller. Every build configuration uses a separate build directory. A GNU Makefile (called `makefile`) is provided in every build directory.

The default toolchain installation directory is hardcoded into the Makefiles. If the used HighTec toolchain is not installed to its default installation directory, the `TOOLCHAIN_PREFIX` variable can be changed in the corresponding Makefile.

Customizing the example project (e.g. if the HighTec IDE project is a Makefile project) requires the modification of the provided Makefiles. A few examples for modifying the provided Makefiles are listed below.

| Example modification | Makefile modification |
| --- | --- |
| Adjusting the toolchain installation directory | Modify the `TOOLCHAIN_PREFIX` variable |
| Adding to or modifying the list of linker scripts | Extend or modify the `LINKER_SCRIPTS` variable |
| Adding to or modifying the list of compiler include directories | Extend or modify the `INCLUDE_DIRS` variable |
| Adding to or modifying the list of assembly source files | Extend or modify the `ASM_SOURCE_FILES` variable |
| Adding to or modifying the list of C source files | Extend or modify the `C_SOURCE_FILES` variable |
| Adding to or modifying the list of defined preprocessor macros | Extend or modify the `DEFINED_PREPROCESSOR_MACROS` variable |
| Adding to or modifying the list of target flags | Extend or modify the `TARGET_FLAGS` variable |
| Adding to or modifying the list of assembly compiler flags | Extend or modify the `ASM_COMPILER_FLAGS` variable |
| Adding to or modifying the list of C compiler flags | Extend or modify the `C_COMPILER_FLAGS` variable |
| Adding to or modifying the list of linker flags | Extend or modify the `LINKER_FLAGS` variable |

To list the available Makefile targets, the following command can be used:

```shell
make -s -C PATH/TO/BUILD/DIRECTORY help
```

### Building in command line

Prerequisites:

- GNU Make v4.1 or newer
- GNU Make tool (`make`) is available on the system PATH

Supported command line terminals:

- Windows CommandPrompt
- Windows PowerShell
- Git Bash on Windows
- Linux Shell

Build steps:

1. Open a command line terminal
2. Navigate to the root directory of the example project
3. Execute the `make --version` command to check if `make` is available
4. Build the example project by executing a command like the following: `make -s -j8 -C PATH/TO/BUILD/DIRECTORY build`, e.g. if the build directory is called `_iROM_TC39X_TB_TC3X9_V2_0_LLVM`, the exact command is the following: `make -s -j8 -C _iROM_TC39X_TB_TC3X9_V2_0_LLVM build`
5. The artifact files are located next to the Makefile

### Building in HighTec IDE

Prerequisites:

- HighTec IDE v6.0.1 or newer

Build steps:

1. The latest version of the HighTec IDE can be downloaded from [here](https://docs.hightec-rt.com/component-ide-qsg/chapter/chapter-software-installation.html)
2. Launch the HighTec IDE and choose a workspace directory that has no spaces in its path
3. Import the HighTec IDE project
    1. Go to ***File*** --> ***Import...***
    2. Select ***General*** --> ***Existing Projects into Workspace*** --> ***Next***
    3. Browse for the root directory of the example project (the containing directory of the `.project` file) --> ***Finish***
4. Activate the imported HighTec IDE project (if it is necessary)
    1. Go to ***project*** --> ***Set Active Project***
5. Select the desired build configuration
    1. Go to ***project*** --> ***Build Configurations*** --> ***Set Active*** --> Click on the desired build configuration
6. Build the selected build configuration
    1. Go to ***project*** --> ***Build Project***
7. The artifact files are located in the directory that has the same name as the build configuration

Further information about using the HighTec IDE can be found [here](https://docs.hightec-rt.com/component-ide-qsg).

> ***NOTE:*** Building in HighTec IDE may overwrite or remove the provided Makefile, so if building in other environment (e.g. in command line or in other IDEs) is needed after building in HighTec IDE, it may be necessary to restore the original provided Makefile.

### Building in VSCode IDE

Prerequisites: The prerequisites are the same as when building in command line.

The example project contains VSCode specific files in the `.vscode` directory.

At the time of writing this document, there are two options for setting up intelli-sense in VSCode:

1. Using the extension `C/C++ Extension Pack` (`ms-vscode.cpptools-extension-pack`) (recommended)
2. Using the extension `clangd` (`llvm-vs-code-extensions.vscode-clangd`)

The two options are mutually exclusive, only one of them can be used at a time.

Option 1 supports selecting "active" build configurations (just like in HighTec IDE), while option 2 does not support it.
Option 1 is the recommended, because that makes the VSCode IDE experience similar to the HighTec IDE experience.

Build steps for intelli-sense option 1:

1. Open the root directory of the example project (the containing directory of the `.vscode` directory) in VSCode
2. Select the desired build configuration
    1. Run the command `Show All Commands` (Default: ***Ctrl+Shift+P***)
    2. Run `C/C++: Select a Configuration...`
    3. Select the desired build configuration (This step sets the intelli-sense active for the selected build configuration)
3. Build the selected or all build configurations
    1. Run the command `Show All Commands` (Default: ***Ctrl+Shift+P***)
    2. Run `Tasks: Run Build Task`
    3. Run the `#### [ Active Config ] # Build` to build the selected build configuration
    4. Run the `#### [ All Configs ] # Build` to build all build configurations

Build steps for intelli-sense option 2:

1. Open the root directory of the example project (the containing directory of the `.vscode` directory) in VSCode
2. Build the desired or all build configurations
    1. Run the command `Show All Commands` (Default: ***Ctrl+Shift+P***)
    2. Run `Tasks: Run Build Task`
    3. Run the `#### BUILD_CONFIG_NAME # Build` to build the build configuration named `BUILD_CONFIG_NAME` (This step sets the intelli-sense active for build configuration `BUILD_CONFIG_NAME`)
    4. Run the `#### [ All Configs ] # Build` to build all build configurations (This step sets the intelli-sense active for the last build configuration)
    5. Run the command `Show All Commands` (Default: ***Ctrl+Shift+P***)
    6. Run `clangd: Restart language server` to let `clangd` reload the intelli-sense configuration

### Building in Zed IDE

Prerequisites: The prerequisites are the same as when building in command line.

The example project contains Zed specific files in the `.zed` directory.

At the time of writing this document, there is one option for setting up intelli-sense in Zed:

- `clangd` support is built into Zed, there is no need for additional extensions

Build steps:

1. Open the root directory of the example project (the containing directory of the `.zed` directory) in Zed
2. Build the desired or all build configurations
    1. Open the `Command Palette` (Default: ***Ctrl+Shift+P***)
    2. Run `task: spawn`
    3. Run the `#### <Win> BUILD_CONFIG_NAME # Build` to build the build configuration named `BUILD_CONFIG_NAME` (This step sets the intelli-sense active for build configuration `BUILD_CONFIG_NAME`)
    4. Run the `#### <Win> [ All Configs ] # Build` to build all build configurations (This step sets the intelli-sense active for the last build configuration)

## Flash with AURIXFlasher

1. Download and install [AURIX™ Flasher Software Tool](https://softwaretools.infineon.com/assets/com.ifx.tb.tool.aurixflashersoftwaretool)
2. Make sure that `AURIXFlasher` is available on the system PATH
3. Open a command line terminal (Windows CommandPrompt, Windows PowerShell, Git Bash on Windows)
4. Execute the `AURIXFlasher -v` command to check if `AURIXFlasher` is available
5. Deploy the elf file with command: `AURIXFlasher -elf PATH/TO/ELF/FILE`

## Debug with TCF in HighTec IDE

1. Build the desired build configuration in HighTec IDE
2. Connect the board to your PC and supply it with +12VDC
3. Go to ***project*** then press select ***Debug As*** --> ***Debug Configurations...***
4. Go to ***TCF AURIX Debug Launch*** --> ***New Configuration***
5. Browse for the elf file at the ***Debug binary to flash and launch*** field
6. The board should be identified automatically
7. Click on ***Debug*** to start the session

> ***NOTE:*** Further information about the usage of the TCF debugger can be found [here](https://docs.hightec-rt.com/tcf-quick-start-guide).

