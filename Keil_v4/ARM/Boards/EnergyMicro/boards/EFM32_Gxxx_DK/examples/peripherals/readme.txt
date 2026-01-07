
This example project uses the EFM32 CMSIS including
DVK BSP (board support package).

It sets up access to DVK registers, and toggles 
access/switches to various peripheral devices on the
DVK. Each enabled DVK will have a corresponding 
orange LED lit up.

Board:  Energy Micro EFM32-Gxxx-DK Development Kit
Device: EFM32G290F128 and EFM32G890F128

-- CMSIS ---------------------------------------------
SystemInit       called from startup_efm32.s
SystemCoreClock  is 14Mhz
SysTick          runs in interrupt mode
