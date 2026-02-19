# 3DSP-Valve-Controller
This repository contains the code for the Valve Controller by 3DSP. It is using the Anybus CompactCom Driver API ([abcc-api](https://github.com/hms-networks/abcc-driver-api)) ported for the [Anybus CompactCom Adapter Board - Module to STM32 Nucleo™](https://www.hms-networks.com/p/024620-b-anybus-compactcom-adapter-board-module-to-stm32-nucleo) evaluation platform.

## Prerequisites
### Integrated Development Environment (IDE)
- [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html) is required to run the application.
### Hardware
- Valve Driver v1.0
- This application is created for the [STM32 Nucleo H753ZI](https://www.st.com/en/evaluation-tools/nucleo-h753zi.html) board together with the [adapter board](https://www.hms-networks.com/p/024620-b-anybus-compactcom-adapter-board-module-to-stm32-nucleo) from HMS. See the [Anybus® CompactCom™ Adapter Board for STM32 Nucleo™ - Installation Guide](https://hmsnetworks.blob.core.windows.net/nlw/docs/default-source/products/anybus/manuals-and-guides---manuals/hms-scm-1202-236.pdf?sfvrsn=90594caf_4) for more details on how to set up the hardware.

## Cloning
This repository contain submodules [abcc-driver-api](https://github.com/hms-networks/abcc-api), [abcc-driver](https://github.com/hms-networks/abcc-driver) and [abcc-abp](https://github.com/hms-networks/abcc-abp) that must be initialized. Therefore, pass the flag `--recurse-submodules` when cloning.
```
git clone --recurse-submodules https://github.com/leonluz80/3DSP-Valve-Controller.git
```

If you did not pass the flag `--recurse-submodules` when cloning, the following command can be run:
```
git submodule update --init --recursive
```

## Build and run
### Step 1. Setup the Anybus hardware
Follow the steps in the chapter called *Confuguration* in the [Anybus® CompactCom™ Adapter Board for STM32 Nucleo™ - Installation Guide](https://hmsnetworks.blob.core.windows.net/nlw/docs/default-source/products/anybus/manuals-and-guides---manuals/hms-scm-1202-236.pdf?sfvrsn=90594caf_4) to setup your hardware correctly.
### Step 2. Connect the Valve Driver v1.0
Use Connector CN11 on the Nucleo:
SCK -> PC10 (yellow)
CS -> PC11 (orange)
MOSI -> PC12 (green)
5V -> 5V_ext (red)
GND -> GND (brown)
### Step 3. Power the Valve Driver v1.0
Connect 24V and GND to power the valves.
### Step 4. Open the project
Find the **.project** file in the repository root and open it with STM32CubeIDE.
### Step 5. Build and run
Select *Run*->*Debug* to build and run the configuration called "Debug". Use the function keys to step through or run the debug application.
### Step 6. See debug print-out
Open *Window*->*Show view*->*SWV*->*SWV ITM Data Console*. From there, click on the wrench icon to open the Serial Wire Viewer settings and enable the 0th ITM Stimulus port (rightmost checkbox). Then, press the red circle "Start Trace" to view the debug print-out from the example application.

#### (Nothing is happening...)
Make sure that your hardware is set up correctly and that the switch (S4) on the adapter board is configured to either SPI or UART operation mode. See the [Anybus® CompactCom™ Adapter Board for STM32 Nucleo™ - Installation Guide](https://hmsnetworks.blob.core.windows.net/nlw/docs/default-source/products/anybus/manuals-and-guides---manuals/hms-scm-1202-236.pdf?sfvrsn=90594caf_4) for more details.

#### Weird behaviour?
Make sure that the hardware matches the configuration in src/io_expander/io_config.c :
- Instances of type MCP23S17_Bus_t are serially connected PCBs that share the same SPI bus. If multiple PCB's are connected, make sure to adjust the adress bytes in the code and on the DIP switch on each PCB.
- Instances of type MCP23S17_t are the IO Expanders. Each PCB hosts two of them.



