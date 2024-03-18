# Create new project in STM32CubeIDE workspace
1. ### `File` -> `New` -> `STM32 Project` -> Select your board -> Give a project name -> `Targeted Project Type` -> `Finish`

<br>

# Running a Program in Debug mode in STM32CubeIDE
1. ### Connect the board to the PC
2. ### Right click Build the project (Compile)
3. ### Right click the project and `Debug as` -> `Debug Configurations`
4. ### `STM32 C/C++ Application` -> Double click it to create a new configuration for the current project you've tried to debug as
	- ### Under `Debugger` tab, make sure `ST-LINK (ST-LINK GDB Server)` is selected as the `Debug Probe`
	- ### Under `GDB Server Command Line Options`
		- ### Make sure `SWD` is selected as the interface
		- ### Make sure `SVW` is enabled
	- ### Click `Apply` and close the window
5. ### Right click the project and `Debug as` -> `STM32 C/C++ Application`
6. ### Now in debug perspective, Program is loaded into the target, and the processor's execution is halted at the first instruction of `main()`
7. ### To see trace logs, click `Window` -> `Show View` -> `SVW` -> `STM ITM Data Console`
8. ### In the `STM ITM Data Console`, click the icon to `Configure trace` and select a port to enable; if not sure, then select 0 (`printf` works over port 0)
9. ### In the `STM ITM Data Console`, click the icon to `Start trace`; `STM ITM Data Console` is now ready to accept data on the `SWO` pin
10. ### Click `Resume` to continue with processor execution of the program (May need to click `Reset the chip and restart debug session`, then click `Resume`)

<br>

# Enable `printf`-like debugging (trace logs) with `ARM Cortex-M3/4` processors
1. ### in `syscalls.c` file, add the following code after the last `#include` statement
```
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//					Implementation of printf like feature using ARM Cortex M3/M4/ ITM functionality
//					This function will not work for ARM Cortex M0/M0+
//					If you are using Cortex M0, then you can use semihosting feature of openOCD
/////////////////////////////////////////////////////////////////////////////////////////////////////////

//Debug Exception and Monitor Control Register base address
#define DEMCR        			*((volatile uint32_t*) 0xE000EDFCU )

/* ITM register addresses */
#define ITM_STIMULUS_PORT0   	*((volatile uint32_t*) 0xE0000000 )
#define ITM_TRACE_EN          	*((volatile uint32_t*) 0xE0000E00 )

void ITM_SendChar(uint8_t ch)
{

	//Enable TRCENA
	DEMCR |= ( 1 << 24);

	//enable stimulus port 0
	ITM_TRACE_EN |= ( 1 << 0);

	// read FIFO status in bit [0]:
	while(!(ITM_STIMULUS_PORT0 & 1));

	//Write to ITM stimulus port0
	ITM_STIMULUS_PORT0 = ch;
}
```
2. ### Also in `syscalls.c` file, update the `__write()` function to
```
__attribute__((weak)) int _write(int file, char *ptr, int len)
{
  (void)file;
  int DataIdx;

  for (DataIdx = 0; DataIdx < len; DataIdx++)
  {
    //__io_putchar(*ptr++);
	ITM_SendChar(*ptr++);
  }
  return len;
}
```

<br>

# If getting the following warning in STM32CubeIDE when building a project - `FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use`
- ### Solution:
	- ### Project -> Properties -> C/C++ Build -> Settings -> Tool Settings -> MCU Settings, set Floating-point unit to 'None', and Floating-point ABI to 'Software'

<br>

# Increase size of icons in STM32CubeIDE
1. ### Right click the shortcut and copy the target path and paste into file system
2. ### Open the `.ini` file and insert the below at the bottom of the file
```
-Dswt.enable.autoScale=true
-Dswt.autoScale=150
-Dswt.autoScale.method=nearest
```
3. ### Save the file and open STM32CubeIDE