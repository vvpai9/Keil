
This example project uses the EFM32 CMSIS including
DVK BSP (board support package).

It sets up access to DVK registers, and toggles 
access to serial port b. 

Connecting a terminal emulator on serial port b,
with configuration 9600-8-N-1 will show a printf
output and provide a "local echo" on typed 
characters.

Redirecting output from printf is specific to each
IDE, so separate files for IAR EWARM and Keil MDK-ARM
is provided for this purpose.

Board:  Energy Micro EFM32-Gxxx-DK Development Kit
Device: EFM32G290F128 and EFM32G890F128

-- CMSIS ---------------------------------------------
SystemInit       called from startup_efm32.s
SystemCoreClock  is 14Mhz
SysTick          runs in interrupt mode
