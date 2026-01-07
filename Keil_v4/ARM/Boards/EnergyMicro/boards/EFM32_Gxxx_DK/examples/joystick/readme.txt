
This example project uses the EFM32 CMSIS including
DVK BSP (board support package) and demonstrates 
the use of the BSP for accessing joystick movement.

It sets up access to DVK registers, enables an 
interrupt to register joystick movement which
are indicated on the user leds.

Board:  Energy Micro EFM32-Gxxx-DK Development Kit
Device: EFM32G290F128 and EFM32G890F128

-- CMSIS ---------------------------------------------
SystemInit       called from startup_efm32.s
SystemCoreClock  is 14Mhz
SysTick          runs in interrupt mode
