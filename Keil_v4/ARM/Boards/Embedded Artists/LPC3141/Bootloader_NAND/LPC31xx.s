;/*****************************************************************************/
;/* LPC31xx.S: Startup file for NXP LPC313x, LPC314x and LPC315x device series*/
;/*****************************************************************************/
;/* <<< Use Configuration Wizard in Context Menu >>>                          */
;/*****************************************************************************/
;/* This file is part of the uVision/ARM development tools.                   */
;/* Copyright (c) 2007-2009 Keil - An ARM Company. All rights reserved.       */
;/* This software may only be used under the terms of a valid, current,       */
;/* end user licence from KEIL for a compatible version of KEIL software      */
;/* development tools. Nothing else gives you the right to use this software. */
;/*****************************************************************************/

;/*
; *  The Startup code is executed after CPU Reset. This file may be 
; *  translated with the following SET symbols. In uVision these SET 
; *  symbols are entered under Options - ASM - Define.
; *
; *  BOOT_HEADER:          boot header is assembled to beginning of image.
; *
; *  SIZE_INT_INFO:        size of program image is coded instead of Reserved 
; *                        vector at address 0x14, if code is linked for 
; *                        Internal RAM.
; *
; *  SIZE_EXT_INFO:        size of program image is coded instead of Reserved 
; *                        vector at address 0x14, if code is linked for 
; *                        External SDRAM.
; *
; *  NO_CLOCK_INIT:        when set the startup code will not initialize Clock 
; *                       (used mostly when clock is already initialized from 
; *                        script .ini file).
; *
; *  NO_MPMC_INIT:         when set the startup code will not initialize 
; *                        Multi-Port Memory Controller.
; *                       (used mostly when MPMC is already initialized from 
; *                        script .ini file).
; *
; *  NO_MPMC_DYNAMIC_INIT: when set the startup code will not initialize 
; *                        Dynamic Memory Control part of MPMC.
; *                       (used mostly when MPMC is already initialized from 
; *                        script .ini file).
; *
; *  NO_MPMC_STATIC_INIT:  when set the startup code will not initialize 
; *                        Static Memory Control part of MPMC.
; *                       (used mostly when MPMC is already initialized from 
; *                        script .ini file).
; *
; *  NO_SHADOW_INIT:       when set the startup code will not setup shadowing 
; *                        of any address to address 0.
; */


; Standard definitions of Mode bits and Interrupt (I & F) flags in PSRs

Mode_USR        EQU     0x10
Mode_FIQ        EQU     0x11
Mode_IRQ        EQU     0x12
Mode_SVC        EQU     0x13
Mode_ABT        EQU     0x17
Mode_UND        EQU     0x1B
Mode_SYS        EQU     0x1F

I_Bit           EQU     0x80            ; when I bit is set, IRQ is disabled
F_Bit           EQU     0x40            ; when F bit is set, FIQ is disabled


;----------------------- Memory Definitions ------------------------------------

; Internal Memory Base Addresses
IRAM_BASE       EQU     0x11028000
IROM_BASE       EQU     0x12000000

; External Memory Base Addresses
ESRAM0_BASE     EQU     0x20000000
ESRAM1_BASE     EQU     0x20020000
ESDRAM0_BASE    EQU     0x30000000


;----------------------- Stack and Heap Definitions ----------------------------

; <h> Stack Configuration (Stack Sizes in Bytes)
;   <o0> Undefined Mode      <0x0-0xFFFFFFFF:8>
;   <o1> Supervisor Mode     <0x0-0xFFFFFFFF:8>
;   <o2> Abort Mode          <0x0-0xFFFFFFFF:8>
;   <o3> Fast Interrupt Mode <0x0-0xFFFFFFFF:8>
;   <o4> Interrupt Mode      <0x0-0xFFFFFFFF:8>
;   <o5> User/System Mode    <0x0-0xFFFFFFFF:8>
; </h>

UND_Stack_Size  EQU     0x00000000
SVC_Stack_Size  EQU     0x00000008
ABT_Stack_Size  EQU     0x00000000
FIQ_Stack_Size  EQU     0x00000000
IRQ_Stack_Size  EQU     0x00000080
USR_Stack_Size  EQU     0x00000400

ISR_Stack_Size  EQU     (UND_Stack_Size + SVC_Stack_Size + ABT_Stack_Size + \
                         FIQ_Stack_Size + IRQ_Stack_Size)

                AREA    STACK, NOINIT, READWRITE, ALIGN=3

Stack_Mem       SPACE   USR_Stack_Size
__initial_sp    SPACE   ISR_Stack_Size
Stack_Top


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF>
; </h>

Heap_Size       EQU     0x00000000

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


;----------------------- Clock Definitions -------------------------------------

; Clock Generation Unit (CGU) Definitions
CGU_BASE        EQU     0x13004000      ; CGU Base Address
                ^       0x000           ; Switch Configuration Register Offsets
SCR0_OFS        #       0x04            ; for SYS        Base
SCR1_OFS        #       0x04            ; for AHB0_APB0  Base
SCR2_OFS        #       0x04            ; for AHB0_APB1  Base
SCR3_OFS        #       0x04            ; for AHB0_APB2  Base
SCR4_OFS        #       0x04            ; for AHB0_APB3  Base
SCR5_OFS        #       0x04            ; for PCM        Base
SCR6_OFS        #       0x04            ; for UART       Base
SCR7_OFS        #       0x04            ; for CLK1024FS  Base
SCR8_OFS        #       0x04            ; for I2SRX_BCK0 Base
SCR9_OFS        #       0x04            ; for I2SRX_BCK1 Base
SCR10_OFS       #       0x04            ; for SPI_CLK    Base
SCR11_OFS       #       0x04            ; for SYSCLK_O   Base
                ^       0x030           ; Frequency Select Register 1 Offsets
FS1_0_OFS       #       0x04            ; for SYS        Base
FS1_1_OFS       #       0x04            ; for AHB0_APB0  Base
FS1_2_OFS       #       0x04            ; for AHB0_APB1  Base
FS1_3_OFS       #       0x04            ; for AHB0_APB2  Base
FS1_4_OFS       #       0x04            ; for AHB0_APB3  Base
FS1_5_OFS       #       0x04            ; for PCM        Base
FS1_6_OFS       #       0x04            ; for UART       Base
FS1_7_OFS       #       0x04            ; for CLK1024FS  Base
FS1_8_OFS       #       0x04            ; for I2SRX_BCK0 Base
FS1_9_OFS       #       0x04            ; for I2SRX_BCK1 Base
FS1_10_OFS      #       0x04            ; for SPI_CLK    Base
FS1_11_OFS      #       0x04            ; for SYSCLK_O   Base
                ^       0x060           ; Frequency Select Register 2 Offsets
FS2_0_OFS       #       0x04            ; for SYS        Base
FS2_1_OFS       #       0x04            ; for AHB0_APB0  Base
FS2_2_OFS       #       0x04            ; for AHB0_APB1  Base
FS2_3_OFS       #       0x04            ; for AHB0_APB2  Base
FS2_4_OFS       #       0x04            ; for AHB0_APB3  Base
FS2_5_OFS       #       0x04            ; for PCM        Base
FS2_6_OFS       #       0x04            ; for UART       Base
FS2_7_OFS       #       0x04            ; for CLK1024FS  Base
FS2_8_OFS       #       0x04            ; for I2SRX_BCK0 Base
FS2_9_OFS       #       0x04            ; for I2SRX_BCK1 Base
FS2_10_OFS      #       0x04            ; for SPI_CLK    Base
FS2_11_OFS      #       0x04            ; for SYSCLK_O   Base
                ^       0x090           ; Switch Status Register Offsets
SSR0_OFS        #       0x04            ; for SYS        Base
SSR1_OFS        #       0x04            ; for AHB0_APB0  Base
SSR2_OFS        #       0x04            ; for AHB0_APB1  Base
SSR3_OFS        #       0x04            ; for AHB0_APB2  Base
SSR4_OFS        #       0x04            ; for AHB0_APB3  Base
SSR5_OFS        #       0x04            ; for PCM        Base
SSR6_OFS        #       0x04            ; for UART       Base
SSR7_OFS        #       0x04            ; for CLK1024FS  Base
SSR8_OFS        #       0x04            ; for I2SRX_BCK0 Base
SSR9_OFS        #       0x04            ; for I2SRX_BCK1 Base
SSR10_OFS       #       0x04            ; for SPI_CLK    Base
SSR11_OFS       #       0x04            ; for SYSCLK_O   Base
                ^       0x0C0           ; Power Control Register Offsets
PCR0_OFS        #       0x04            ; for APB0_CLK
PCR1_OFS        #       0x04            ; for APB1_CLK
PCR2_OFS        #       0x04            ; for APB2_CLK
PCR3_OFS        #       0x04            ; for APB3_CLK
PCR4_OFS        #       0x04            ; for APB4_CLK
PCR5_OFS        #       0x04            ; for AHB_TO_INTC_CLK
PCR6_OFS        #       0x04            ; for AHB0_CLK
PCR7_OFS        #       0x04            ; for EBI_CLK
PCR8_OFS        #       0x04            ; for DMA_PCLK
PCR9_OFS        #       0x04            ; for DMA_CLK_GATED
PCR10_OFS       #       0x04            ; for NANDFLASH_S0_CLK
PCR11_OFS       #       0x04            ; for NANDFLASH_ECC_CLK
PCR12_OFS       #       0x04            ; for NANDFLASH_AES_CLK
PCR13_OFS       #       0x04            ; for NANDFLASH_NAND_CLK
PCR14_OFS       #       0x04            ; for NANDFLASH_PCLK
PCR15_OFS       #       0x04            ; for CLOCK_OUT
PCR16_OFS       #       0x04            ; for ARM926_CORE_CLK
PCR17_OFS       #       0x04            ; for ARM926_BUSIF_CLK
PCR18_OFS       #       0x04            ; for ARM926_RETIME_CLK
PCR19_OFS       #       0x04            ; for SD_MMC_HCLK
PCR20_OFS       #       0x04            ; for SD_MMC_CCLK_IN
PCR21_OFS       #       0x04            ; for USB_OTG_AHB_CLK
PCR22_OFS       #       0x04            ; for ISRAM0_CLK
PCR23_OFS       #       0x04            ; for RED_CTL_RSCLK
PCR24_OFS       #       0x04            ; for ISRAM1_CLK
PCR25_OFS       #       0x04            ; for ISROM_CLK
PCR26_OFS       #       0x04            ; for MPMC_CFG_CLK
PCR27_OFS       #       0x04            ; for MPMC_CFG_CLK2
PCR28_OFS       #       0x04            ; for MPMC_CFG_CLK3
PCR29_OFS       #       0x04            ; for INTC_CLK
PCR30_OFS       #       0x04            ; for AHB_TO_APB0_PCLK
PCR31_OFS       #       0x04            ; for EVENT_ROUTER_PCLK
PCR32_OFS       #       0x04            ; for ADC_PCLK
PCR33_OFS       #       0x04            ; for ADC_CLK
PCR34_OFS       #       0x04            ; for WDOG_PCLK
PCR35_OFS       #       0x04            ; for IOCONF_PCLK
PCR36_OFS       #       0x04            ; for CGU_PCLK
PCR37_OFS       #       0x04            ; for SYSCREG_PCLK
PCR38_OFS       #       0x04            ; for OTP_PCLK
PCR39_OFS       #       0x04            ; for RNG_PCLK
PCR40_OFS       #       0x04            ; for AHB_TO_APB1_PCLK
PCR41_OFS       #       0x04            ; for TIMER0_PCLK
PCR42_OFS       #       0x04            ; for TIMER1_PCLK
PCR43_OFS       #       0x04            ; for TIMER2_PCLK
PCR44_OFS       #       0x04            ; for TIMER3_PCLK
PCR45_OFS       #       0x04            ; for PWM_PCLK
PCR46_OFS       #       0x04            ; for PWM_PCLK_REGS
PCR47_OFS       #       0x04            ; for PWM_CLK
PCR48_OFS       #       0x04            ; for I2C0_PCLK
PCR49_OFS       #       0x04            ; for I2C1_PCLK
PCR50_OFS       #       0x04            ; for AHB_TO_APB2_PCLK
PCR51_OFS       #       0x04            ; for PCM_PCLK
PCR52_OFS       #       0x04            ; for PCM_APB_PCLK
PCR53_OFS       #       0x04            ; for UART_APB_CLK
PCR54_OFS       #       0x04            ; for LCD_PCLK
PCR55_OFS       #       0x04            ; for LCD_CLK
PCR56_OFS       #       0x04            ; for SPI_PCLK
PCR57_OFS       #       0x04            ; for SPI_PCLK_GATED
PCR58_OFS       #       0x04            ; for AHB_TO_APB3_PCLK
PCR59_OFS       #       0x04            ; for I2S_CFG_PCLK
PCR60_OFS       #       0x04            ; for EDGE_DET_PCLK
PCR61_OFS       #       0x04            ; for I2STX_FIFO_0_PCLK
PCR62_OFS       #       0x04            ; for I2STX_IF_0_PCLK
PCR63_OFS       #       0x04            ; for I2STX_FIFO_1_PCLK
PCR64_OFS       #       0x04            ; for I2STX_IF_1_PCLK
PCR65_OFS       #       0x04            ; for I2SRX_FIFO_0_PCLK
PCR66_OFS       #       0x04            ; for I2SRX_IF_0_PCLK  
PCR67_OFS       #       0x04            ; for I2SRX_FIFO_1_PCLK
PCR68_OFS       #       0x04            ; for I2SRX_IF_1_PCLK  
PCR69_OFS       #       0x04            ;     Reserved (write 0)
PCR70_OFS       #       0x04            ;     Reserved (write 0)
PCR71_OFS       #       0x04            ; for PCM_CLK_IP
PCR72_OFS       #       0x04            ; for UART_U_CLK
PCR73_OFS       #       0x04            ; for I2S_EDGE_DETECT_CLK
PCR74_OFS       #       0x04            ; for I2STX_BCK0_N
PCR75_OFS       #       0x04            ; for I2STX_WS0
PCR76_OFS       #       0x04            ; for I2STX_CLK0
PCR77_OFS       #       0x04            ; for I2STX_BCK1_N
PCR78_OFS       #       0x04            ; for I2STX_WS1
PCR79_OFS       #       0x04            ; for CLK_256FS
PCR80_OFS       #       0x04            ; for I2SRX_BCK0_N
PCR81_OFS       #       0x04            ; for I2SRX_WS0
PCR82_OFS       #       0x04            ; for I2SRX_BCK1_N
PCR83_OFS       #       0x04            ; for I2SRX_WS1
PCR84_OFS       #       0x04            ;     Reserved (write 0)
PCR85_OFS       #       0x04            ;     Reserved (write 0)
PCR86_OFS       #       0x04            ;     Reserved (write 0)
PCR87_OFS       #       0x04            ; for I2SRX_BCK0
PCR88_OFS       #       0x04            ; for I2SRX_BCK1
PCR89_OFS       #       0x04            ; for SPI_CLK
PCR90_OFS       #       0x04            ; for SPI_CLK_GATED
PCR91_OFS       #       0x04            ; for SYSCLK_O
                ^       0x230           ; Power Status Register Offsets
PSR0_OFS        #       0x04            ; for APB0_CLK
PSR1_OFS        #       0x04            ; for APB1_CLK
PSR2_OFS        #       0x04            ; for APB2_CLK
PSR3_OFS        #       0x04            ; for APB3_CLK
PSR4_OFS        #       0x04            ; for APB4_CLK
PSR5_OFS        #       0x04            ; for AHB_TO_INTC_CLK
PSR6_OFS        #       0x04            ; for AHB0_CLK
PSR7_OFS        #       0x04            ; for EBI_CLK
PSR8_OFS        #       0x04            ; for DMA_PCLK
PSR9_OFS        #       0x04            ; for DMA_CLK_GATED
PSR10_OFS       #       0x04            ; for NANDFLASH_S0_CLK
PSR11_OFS       #       0x04            ; for NANDFLASH_ECC_CLK
PSR12_OFS       #       0x04            ; for NANDFLASH_AES_CLK
PSR13_OFS       #       0x04            ; for NANDFLASH_NAND_CLK
PSR14_OFS       #       0x04            ; for NANDFLASH_PCLK
PSR15_OFS       #       0x04            ; for CLOCK_OUT
PSR16_OFS       #       0x04            ; for ARM926_CORE_CLK
PSR17_OFS       #       0x04            ; for ARM926_BUSIF_CLK
PSR18_OFS       #       0x04            ; for ARM926_RETIME_CLK
PSR19_OFS       #       0x04            ; for SD_MMC_HCLK
PSR20_OFS       #       0x04            ; for SD_MMC_CCLK_IN
PSR21_OFS       #       0x04            ; for USB_OTG_AHB_CLK
PSR22_OFS       #       0x04            ; for ISRAM0_CLK
PSR23_OFS       #       0x04            ; for RED_CTL_RSCLK
PSR24_OFS       #       0x04            ; for ISRAM1_CLK
PSR25_OFS       #       0x04            ; for ISROM_CLK
PSR26_OFS       #       0x04            ; for MPMC_CFG_CLK
PSR27_OFS       #       0x04            ; for MPMC_CFG_CLK2
PSR28_OFS       #       0x04            ; for MPMC_CFG_CLK3
PSR29_OFS       #       0x04            ; for INTC_CLK
PSR30_OFS       #       0x04            ; for AHB_TO_APB0_PCLK
PSR31_OFS       #       0x04            ; for EVENT_ROUTER_PCLK
PSR32_OFS       #       0x04            ; for ADC_PCLK
PSR33_OFS       #       0x04            ; for ADC_CLK
PSR34_OFS       #       0x04            ; for WDOG_PCLK
PSR35_OFS       #       0x04            ; for IOCONF_PCLK
PSR36_OFS       #       0x04            ; for CGU_PCLK
PSR37_OFS       #       0x04            ; for SYSCREG_PCLK
PSR38_OFS       #       0x04            ; for OTP_PCLK
PSR39_OFS       #       0x04            ; for RNG_PCLK
PSR40_OFS       #       0x04            ; for AHB_TO_APB1_PCLK
PSR41_OFS       #       0x04            ; for TIMER0_PCLK
PSR42_OFS       #       0x04            ; for TIMER1_PCLK
PSR43_OFS       #       0x04            ; for TIMER2_PCLK
PSR44_OFS       #       0x04            ; for TIMER3_PCLK
PSR45_OFS       #       0x04            ; for PWM_PCLK
PSR46_OFS       #       0x04            ; for PWM_PCLK_REGS
PSR47_OFS       #       0x04            ; for PWM_CLK
PSR48_OFS       #       0x04            ; for I2C0_PCLK
PSR49_OFS       #       0x04            ; for I2C1_PCLK
PSR50_OFS       #       0x04            ; for AHB_TO_APB2_PCLK
PSR51_OFS       #       0x04            ; for PCM_PCLK
PSR52_OFS       #       0x04            ; for PCM_APB_PCLK
PSR53_OFS       #       0x04            ; for UART_APB_CLK
PSR54_OFS       #       0x04            ; for LCD_PCLK
PSR55_OFS       #       0x04            ; for LCD_CLK
PSR56_OFS       #       0x04            ; for SPI_PCLK
PSR57_OFS       #       0x04            ; for SPI_PCLK_GATED
PSR58_OFS       #       0x04            ; for AHB_TO_APB3_PCLK
PSR59_OFS       #       0x04            ; for I2S_CFG_PCLK
PSR60_OFS       #       0x04            ; for EDGE_DET_PCLK
PSR61_OFS       #       0x04            ; for I2STX_FIFO_0_PCLK
PSR62_OFS       #       0x04            ; for I2STX_IF_0_PCLK
PSR63_OFS       #       0x04            ; for I2STX_FIFO_1_PCLK
PSR64_OFS       #       0x04            ; for I2STX_IF_1_PCLK
PSR65_OFS       #       0x04            ; for I2SRX_FIFO_0_PCLK
PSR66_OFS       #       0x04            ; for I2SRX_IF_0_PCLK  
PSR67_OFS       #       0x04            ; for I2SRX_FIFO_1_PCLK
PSR68_OFS       #       0x04            ; for I2SRX_IF_1_PCLK  
PSR69_OFS       #       0x04            ;     Reserved
PSR70_OFS       #       0x04            ;     Reserved
PSR71_OFS       #       0x04            ; for PCM_CLK_IP
PSR72_OFS       #       0x04            ; for UART_U_CLK
PSR73_OFS       #       0x04            ; for I2S_EDGE_DETECT_CLK
PSR74_OFS       #       0x04            ; for I2STX_BCK0_N
PSR75_OFS       #       0x04            ; for I2STX_WS0
PSR76_OFS       #       0x04            ; for I2STX_CLK0
PSR77_OFS       #       0x04            ; for I2STX_BCK1_N
PSR78_OFS       #       0x04            ; for I2STX_WS1
PSR79_OFS       #       0x04            ; for CLK_256FS
PSR80_OFS       #       0x04            ; for I2SRX_BCK0_N
PSR81_OFS       #       0x04            ; for I2SRX_WS0
PSR82_OFS       #       0x04            ; for I2SRX_BCK1_N
PSR83_OFS       #       0x04            ; for I2SRX_WS1
PSR84_OFS       #       0x04            ;     Reserved
PSR85_OFS       #       0x04            ;     Reserved
PSR86_OFS       #       0x04            ;     Reserved
PSR87_OFS       #       0x04            ; for I2SRX_BCK0
PSR88_OFS       #       0x04            ; for I2SRX_BCK1
PSR89_OFS       #       0x04            ; for SPI_CLK
PSR90_OFS       #       0x04            ; for SPI_CLK_GATED
PSR91_OFS       #       0x04            ; for SYSCLK_O
                ^       0x3A0           ; Enable Select Register Offsets
ESR0_OFS        #       0x04            ; for APB0_CLK
ESR1_OFS        #       0x04            ; for APB1_CLK
ESR2_OFS        #       0x04            ; for APB2_CLK
ESR3_OFS        #       0x04            ; for APB3_CLK
ESR4_OFS        #       0x04            ; for APB4_CLK
ESR5_OFS        #       0x04            ; for AHB_TO_INTC_CLK
ESR6_OFS        #       0x04            ; for AHB0_CLK
ESR7_OFS        #       0x04            ; for EBI_CLK
ESR8_OFS        #       0x04            ; for DMA_PCLK
ESR9_OFS        #       0x04            ; for DMA_CLK_GATED
ESR10_OFS       #       0x04            ; for NANDFLASH_S0_CLK
ESR11_OFS       #       0x04            ; for NANDFLASH_ECC_CLK
ESR12_OFS       #       0x04            ; for NANDFLASH_AES_CLK
ESR13_OFS       #       0x04            ; for NANDFLASH_NAND_CLK
ESR14_OFS       #       0x04            ; for NANDFLASH_PCLK
ESR15_OFS       #       0x04            ; for NANDFLASH_CLOCK_OUT
ESR16_OFS       #       0x04            ; for ARM926_CORE_CLK
ESR17_OFS       #       0x04            ; for ARM926_BUSIF_CLK
ESR18_OFS       #       0x04            ; for ARM926_RETIME_CLK
ESR19_OFS       #       0x04            ; for SD_MMC_HCLK
ESR20_OFS       #       0x04            ; for SD_MMC_CCLK_IN
ESR21_OFS       #       0x04            ; for USB_OTG_AHB_CLK
ESR22_OFS       #       0x04            ; for ISRAM0_CLK
ESR23_OFS       #       0x04            ; for RED_CTL_RSCLK
ESR24_OFS       #       0x04            ; for ISRAM1_CLK
ESR25_OFS       #       0x04            ; for ISROM_CLK
ESR26_OFS       #       0x04            ; for MPMC_CFG_CLK
ESR27_OFS       #       0x04            ; for MPMC_CFG_CLK2
ESR28_OFS       #       0x04            ; for MPMC_CFG_CLK3
ESR29_OFS       #       0x04            ; for INTC_CLK
ESR30_OFS       #       0x04            ; for AHB_TO_APB0_PCLK
ESR31_OFS       #       0x04            ; for EVENT_ROUTER_PCLK
ESR32_OFS       #       0x04            ; for ADC_PCLK
ESR33_OFS       #       0x04            ; for ADC_CLK
ESR34_OFS       #       0x04            ; for WDOG_PCLK
ESR35_OFS       #       0x04            ; for IOCONF_PCLK
ESR36_OFS       #       0x04            ; for CGU_PCLK
ESR37_OFS       #       0x04            ; for SYSCREG_PCLK
ESR38_OFS       #       0x04            ; for OTP_PCLK
ESR39_OFS       #       0x04            ; for RNG_PCLK
ESR40_OFS       #       0x04            ; for AHB_TO_APB1_PCLK
ESR41_OFS       #       0x04            ; for TIMER0_PCLK
ESR42_OFS       #       0x04            ; for TIMER1_PCLK
ESR43_OFS       #       0x04            ; for TIMER2_PCLK
ESR44_OFS       #       0x04            ; for TIMER3_PCLK
ESR45_OFS       #       0x04            ; for PWM_PCLK
ESR46_OFS       #       0x04            ; for PWM_PCLK_REGS
ESR47_OFS       #       0x04            ; for PWM_CLK
ESR48_OFS       #       0x04            ; for I2C0_PCLK
ESR49_OFS       #       0x04            ; for I2C1_PCLK
ESR50_OFS       #       0x04            ; for AHB_TO_APB2_PCLK
ESR51_OFS       #       0x04            ; for PCM_PCLK
ESR52_OFS       #       0x04            ; for PCM_APB_PCLK
ESR53_OFS       #       0x04            ; for UART_APB_CLK
ESR54_OFS       #       0x04            ; for LCD_PCLK
ESR55_OFS       #       0x04            ; for LCD_CLK
ESR56_OFS       #       0x04            ; for SPI_PCLK
ESR57_OFS       #       0x04            ; for SPI_PCLK_GATED
ESR58_OFS       #       0x04            ; for AHB_TO_APB3_PCLK
ESR59_OFS       #       0x04            ; for I2S_CFG_PCLK
ESR60_OFS       #       0x04            ; for EDGE_DET_PCLK
ESR61_OFS       #       0x04            ; for I2STX_FIFO_0_PCLK
ESR62_OFS       #       0x04            ; for I2STX_IF_0_PCLK
ESR63_OFS       #       0x04            ; for I2STX_FIFO_1_PCLK
ESR64_OFS       #       0x04            ; for I2STX_IF_1_PCLK
ESR65_OFS       #       0x04            ; for I2SRX_FIFO_0_PCLK
ESR66_OFS       #       0x04            ; for I2SRX_IF_0_PCLK  
ESR67_OFS       #       0x04            ; for I2SRX_FIFO_1_PCLK
ESR68_OFS       #       0x04            ; for I2SRX_IF_1_PCLK  
ESR69_OFS       #       0x04            ;     Reserved
ESR70_OFS       #       0x04            ;     Reserved
ESR71_OFS       #       0x04            ; for PCM_CLK_IP
ESR72_OFS       #       0x04            ; for UART_U_CLK
ESR73_OFS       #       0x04            ; for I2S_EDGE_DETECT_CLK
ESR74_OFS       #       0x04            ; for I2STX_BCK0_N
ESR75_OFS       #       0x04            ; for I2STX_WS0
ESR76_OFS       #       0x04            ; for I2STX_CLK0
ESR77_OFS       #       0x04            ; for I2STX_BCK1_N
ESR78_OFS       #       0x04            ; for I2STX_WS1
ESR79_OFS       #       0x04            ; for CLK_256FS
ESR80_OFS       #       0x04            ; for I2SRX_BCK0_N
ESR81_OFS       #       0x04            ; for I2SRX_WS0
ESR82_OFS       #       0x04            ; for I2SRX_BCK1_N
ESR83_OFS       #       0x04            ; for I2SRX_WS1
ESR84_OFS       #       0x04            ;     Reserved
ESR85_OFS       #       0x04            ;     Reserved
ESR86_OFS       #       0x04            ;     Reserved
ESR87_OFS       #       0x04            ; for SPI_CLK
ESR88_OFS       #       0x04            ; for SPI_CLK_GATED
                ^       0x504           ; Base Control Register Offsets
BCR0_OFS        #       0x04            ; for SYS Base
BCR1_OFS        #       0x04            ; for AHB0_APB0 Base
BCR2_OFS        #       0x04            ; for AHB0_APB1 Base
BCR3_OFS        #       0x04            ; for AHB0_APB2 Base
BCR7_OFS        #       0x04            ; for CLK1024FS Base
                ^       0x518           ; Fraction Div Config Register Offsets
FDC0_OFS        #       0x04            ; for SYS Base
FDC1_OFS        #       0x04            ; for SYS Base
FDC2_OFS        #       0x04            ; for SYS Base
FDC3_OFS        #       0x04            ; for SYS Base
FDC4_OFS        #       0x04            ; for SYS Base
FDC5_OFS        #       0x04            ; for SYS Base
FDC6_OFS        #       0x04            ; for SYS Base
FDC7_OFS        #       0x04            ; for AHB0_APB0 Base
FDC8_OFS        #       0x04            ; for AHB0_APB0 Base
FDC9_OFS        #       0x04            ; for AHB0_APB1 Base
FDC10_OFS       #       0x04            ; for AHB0_APB1 Base
FDC11_OFS       #       0x04            ; for AHB0_APB2 Base
FDC12_OFS       #       0x04            ; for AHB0_APB2 Base
FDC13_OFS       #       0x04            ; for AHB0_APB2 Base
FDC14_OFS       #       0x04            ; for AHB0_APB3 Base
FDC15_OFS       #       0x04            ; for PCM Base
FDC16_OFS       #       0x04            ; for UART Base
FDC17_OFS       #       0x04            ; for CLK1024FS Base
FDC18_OFS       #       0x04            ; for CLK1024FS Base
FDC19_OFS       #       0x04            ; for CLK1024FS Base
FDC20_OFS       #       0x04            ; for CLK1024FS Base
FDC21_OFS       #       0x04            ; for CLK1024FS Base
FDC22_OFS       #       0x04            ; for CLK1024FS Base
FDC23_OFS       #       0x04            ; for SPI_CLK Base
                ^       0x578           ; Dyn Frac Div Config Register Offsets
DYN_FDC0_OFS    #       0x04            ; for SYS Base
DYN_FDC1_OFS    #       0x04            ; for SYS Base
DYN_FDC2_OFS    #       0x04            ; for SYS Base
DYN_FDC3_OFS    #       0x04            ; for SYS Base
DYN_FDC4_OFS    #       0x04            ; for SYS Base
DYN_FDC5_OFS    #       0x04            ; for SYS Base
DYN_FDC6_OFS    #       0x04            ; for SYS Base
                ^       0x594           ; Dyn Sel Reg for Frac Divider Offsets
DYN_SEL0_OFS    #       0x04            ; for SYS Base
DYN_SEL1_OFS    #       0x04            ; for SYS Base
DYN_SEL2_OFS    #       0x04            ; for SYS Base
DYN_SEL3_OFS    #       0x04            ; for SYS Base
DYN_SEL4_OFS    #       0x04            ; for SYS Base
DYN_SEL5_OFS    #       0x04            ; for SYS Base
DYN_SEL6_OFS    #       0x04            ; for SYS Base
                                        ; CGU Configuration Block Reg Offsets
POWERMODE_OFS   EQU     0xC00           ; Power Mode Register
FFAST_ON_OFS    EQU     0xC08           ; Activate Fast Oscillator
FFAST_BYPASS_OFS    EQU 0xC0C           ; Bypass Fast Oscillator Comparator
HP0_FIN_SELECT_OFS  EQU 0xCF0           ; HP0 PLL Input Select
HP0_MDEC_OFS    EQU     0xCF4           ; HP0 PLL M-divider
HP0_NDEC_OFS    EQU     0xCF8           ; HP0 PLL N-divider
HP0_PDEC_OFS    EQU     0xCFC           ; HP0 PLL P-divider
HP0_MODE_OFS    EQU     0xD00           ; HP0 PLL Mode
HP0_STATUS_OFS  EQU     0xD04           ; HP0 PLL Status
HP0_ACK_OFS     EQU     0xD08           ; HP0 PLL Ratio Change Acknowledge
HP0_REQ_OFS     EQU     0xD0C           ; HP0 PLL Ratio Change Request
HP0_INSELR_OFS  EQU     0xD10           ; HP0 PLL Bandwidth Selection
HP0_INSELI_OFS  EQU     0xD14           ; HP0 PLL Bandwidth Selection
HP0_INSELP_OFS  EQU     0xD18           ; HP0 PLL Bandwidth Selection
HP0_SELR_OFS    EQU     0xD1C           ; HP0 PLL Bandwidth Selection
HP0_SELI_OFS    EQU     0xD20           ; HP0 PLL Bandwidth Selection
HP0_SELP_OFS    EQU     0xD24           ; HP0 PLL Bandwidth Selection
HP1_FIN_SELECT_OFS  EQU 0xD28           ; HP1 PLL Input Select
HP1_MDEC_OFS    EQU     0xD2C           ; HP1 PLL M-divider
HP1_NDEC_OFS    EQU     0xD30           ; HP1 PLL N-divider
HP1_PDEC_OFS    EQU     0xD34           ; HP1 PLL P-divider
HP1_MODE_OFS    EQU     0xD38           ; HP1 PLL Mode
HP1_STATUS_OFS  EQU     0xD3C           ; HP1 PLL Status
HP1_ACK_OFS     EQU     0xD40           ; HP1 PLL Ratio Change Acknowledge
HP1_REQ_OFS     EQU     0xD44           ; HP1 PLL Ratio Change Request
HP1_INSELR_OFS  EQU     0xD48           ; HP1 PLL Bandwidth Selection
HP1_INSELI_OFS  EQU     0xD4C           ; HP1 PLL Bandwidth Selection
HP1_INSELP_OFS  EQU     0xD50           ; HP1 PLL Bandwidth Selection
HP1_SELR_OFS    EQU     0xD54           ; HP1 PLL Bandwidth Selection
HP1_SELI_OFS    EQU     0xD58           ; HP1 PLL Bandwidth Selection
HP1_SELP_OFS    EQU     0xD5C           ; HP1 PLL Bandwidth Selection

; Constants
PLL_LOCK        EQU     0x01            ; PLL Lock Status

; <e> Clock Setup
CLOCK_SETUP     EQU     1

;   <o0.0> Fast Oscillator Enable
FFAST_SETUP     EQU     1

;   <h> PLL Setup
;     <e> HP0 PLL Enable
;       <o1.0..2>    hp0_fin_select: Select Input for HP0 PLL
;                       <0=> ffast (12 MHz)
;                       <1=> I2SRX_BCK0
;                       <2=> I2SRX_WS0
;                       <3=> I2SRX_BCK1
;                       <4=> I2SRX_WS1
;                       <5=> Reserved
;                       <6=> HP1_FOUT
;                       <7=> Reserved
;       <o2.0..16>   hp0_mdec: M-divider Value <0-131071>
;       <o3.0..9>    hp0_ndec: N-divider Value <0-1023>
;       <o4.0..6>    hp0_pdec: P-divider Value <0-127>
;       <o5.0..8>    hp0_mode: Select Mode
;                       <0x19=> Mode 1a: Normal operating mode without post-divider and without pre-divider
;                       <0x11=> Mode 1b: Normal operating mode with    post-divider and without pre-divider
;                       <0x09=> Mode 1c: Normal operating mode without post-divider and with    pre-divider
;                       <0x01=> Mode 1d: Normal operating mode with    post-divider and with    pre-divider
;       <o6.0..3>    hp0_selr: Bandwidth Selection for HP0 <0-15>
;       <o7.0..5>    hp0_seli: Bandwidth Selection for HP0 <0-63>
;       <o8.0..4>    hp0_selp: Bandwidth Selection for HP0 <0-31>
;     </e>
HP0PLL_SETUP    EQU     0
HP0_FIN_SELECT_Val EQU  0x00000000      ; 0x00000000
HP0_MDEC_Val    EQU     0x00000000      ; 0x00000000
HP0_NDEC_Val    EQU     0x00000000      ; 0x00000000
HP0_PDEC_Val    EQU     0x00000000      ; 0x00000000
HP0_MODE_Val    EQU     0x00000006      ; 0x00000006
HP0_SELR_Val    EQU     0x00000000      ; 0x00000000
HP0_SELI_Val    EQU     0x00000000      ; 0x00000000
HP0_SELP_Val    EQU     0x00000000      ; 0x00000000

;     <e> HP1 PLL Enable
;       <o1.0..2>    hp1_fin_select: Select Input for HP1 PLL
;                       <0=> ffast (12 MHz)
;                       <1=> I2SRX_BCK0
;                       <2=> I2SRX_WS0
;                       <3=> I2SRX_BCK1
;                       <4=> I2SRX_WS1
;                       <5=> HP0_FOUT
;                       <6=> Reserved
;                       <7=> Reserved
;       <o2.0..16>   hp1_mdec: M-divider Value <0-131071>
;       <o3.0..9>    hp1_ndec: N-divider Value <0-1023>
;       <o4.0..6>    hp1_pdec: P-divider Value <0-127>
;       <o5.0..8>    hp1_mode: Select Mode
;                       <0x19=> Mode 1a: Normal operating mode without post-divider and without pre-divider
;                       <0x11=> Mode 1b: Normal operating mode with    post-divider and without pre-divider
;                       <0x09=> Mode 1c: Normal operating mode without post-divider and with    pre-divider
;                       <0x01=> Mode 1d: Normal operating mode with    post-divider and with    pre-divider
;       <o6.0..3>    hp1_selr: Bandwidth Selection for HP1 <0-15>
;       <o7.0..5>    hp1_seli: Bandwidth Selection for HP1 <0-63>
;       <o8.0..4>    hp1_selp: Bandwidth Selection for HP1 <0-31>
;     </e>
;   </h>
HP1PLL_SETUP    EQU     1
HP1_FIN_SELECT_Val EQU  0x00000000      ; 0x00000000
HP1_MDEC_Val    EQU     0x00001FFF      ; 0x00000000
HP1_NDEC_Val    EQU     0x00000302      ; 0x00000000
HP1_PDEC_Val    EQU     0x00000062      ; 0x00000000
HP1_MODE_Val    EQU     0x00000001      ; 0x00000006
HP1_SELR_Val    EQU     0x00000000      ; 0x00000000
HP1_SELI_Val    EQU     0x00000010      ; 0x00000000
HP1_SELP_Val    EQU     0x00000008      ; 0x00000000

;   <e> Fractional Dividers Setup
;     <h> Fractional Divider 0 (FDC0)
;       <o1.11..18>  MSUB: Modulo Substraction Value <0-255>
;       <o1.3..10>   MADD: Modulo Additional Value <0-255>
;       <o1.2>       FDCTRL_STRETCH: Stretching Enable
;       <o1.0>       FDCTRL_RUN: Fractional Divider Enable
;     </h>
;     <h> Fractional Divider 1 (FDC1)
;       <o2.11..18>  MSUB: Modulo Substraction Value <0-255>
;       <o2.3..10>   MADD: Modulo Additional Value <0-255>
;       <o2.2>       FDCTRL_STRETCH: Stretching Enable
;       <o2.0>       FDCTRL_RUN: Fractional Divider Enable
;     </h>
;     <h> Fractional Divider 2 (FDC2)
;       <o3.11..18>  MSUB: Modulo Substraction Value <0-255>
;       <o3.3..10>   MADD: Modulo Additional Value <0-255>
;       <o3.2>       FDCTRL_STRETCH: Stretching Enable
;       <o3.0>       FDCTRL_RUN: Fractional Divider Enable
;     </h>
;     <h> Fractional Divider 3 (FDC3)
;       <o4.11..18>  MSUB: Modulo Substraction Value <0-255>
;       <o4.3..10>   MADD: Modulo Additional Value <0-255>
;       <o4.2>       FDCTRL_STRETCH: Stretching Enable
;       <o4.0>       FDCTRL_RUN: Fractional Divider Enable
;     </h>
;     <h> Fractional Divider 4 (FDC4)
;       <o5.11..18>  MSUB: Modulo Substraction Value <0-255>
;       <o5.3..10>   MADD: Modulo Additional Value <0-255>
;       <o5.2>       FDCTRL_STRETCH: Stretching Enable
;       <o5.0>       FDCTRL_RUN: Fractional Divider Enable
;     </h>
;     <h> Fractional Divider 5 (FDC5)
;       <o6.11..18>  MSUB: Modulo Substraction Value <0-255>
;       <o6.3..10>   MADD: Modulo Additional Value <0-255>
;       <o6.2>       FDCTRL_STRETCH: Stretching Enable
;       <o6.0>       FDCTRL_RUN: Fractional Divider Enable
;     </h>
;     <h> Fractional Divider 6 (FDC6)
;       <o7.11..18>  MSUB: Modulo Substraction Value <0-255>
;       <o7.3..10>   MADD: Modulo Additional Value <0-255>
;       <o7.2>       FDCTRL_STRETCH: Stretching Enable
;       <o7.0>       FDCTRL_RUN: Fractional Divider Enable
;     </h>
;     <h> Fractional Divider 7 (FDC7)
;       <o8.11..18>  MSUB: Modulo Substraction Value <0-255>
;       <o8.3..10>   MADD: Modulo Additional Value <0-255>
;       <o8.2>       FDCTRL_STRETCH: Stretching Enable
;       <o8.0>       FDCTRL_RUN: Fractional Divider Enable
;     </h>
;     <h> Fractional Divider 8 (FDC8)
;       <o9.11..18>  MSUB: Modulo Substraction Value <0-255>
;       <o9.3..10>   MADD: Modulo Additional Value <0-255>
;       <o9.2>       FDCTRL_STRETCH: Stretching Enable
;       <o9.0>       FDCTRL_RUN: Fractional Divider Enable
;     </h>
;     <h> Fractional Divider 9 (FDC9)
;       <o10.11..18> MSUB: Modulo Substraction Value <0-255>
;       <o10.3..10>  MADD: Modulo Additional Value <0-255>
;       <o10.2>      FDCTRL_STRETCH: Stretching Enable
;       <o10.0>      FDCTRL_RUN: Fractional Divider Enable
;     </h>
;     <h> Fractional Divider 10 (FDC10)
;       <o11.11..18> MSUB: Modulo Substraction Value <0-255>
;       <o11.3..10>  MADD: Modulo Additional Value <0-255>
;       <o11.2>      FDCTRL_STRETCH: Stretching Enable
;       <o11.0>      FDCTRL_RUN: Fractional Divider Enable
;     </h>
;     <h> Fractional Divider 11 (FDC11)
;       <o12.11..18> MSUB: Modulo Substraction Value <0-255>
;       <o12.3..10>  MADD: Modulo Additional Value <0-255>
;       <o12.2>      FDCTRL_STRETCH: Stretching Enable
;       <o12.0>      FDCTRL_RUN: Fractional Divider Enable
;     </h>
;     <h> Fractional Divider 12 (FDC12)
;       <o13.11..18> MSUB: Modulo Substraction Value <0-255>
;       <o13.3..10>  MADD: Modulo Additional Value <0-255>
;       <o13.2>      FDCTRL_STRETCH: Stretching Enable
;       <o13.0>      FDCTRL_RUN: Fractional Divider Enable
;     </h>
;     <h> Fractional Divider 13 (FDC13)
;       <o14.11..18> MSUB: Modulo Substraction Value <0-255>
;       <o14.3..10>  MADD: Modulo Additional Value <0-255>
;       <o14.2>      FDCTRL_STRETCH: Stretching Enable
;       <o14.0>      FDCTRL_RUN: Fractional Divider Enable
;     </h>
;     <h> Fractional Divider 14 (FDC14)
;       <o15.11..18> MSUB: Modulo Substraction Value <0-255>
;       <o15.3..10>  MADD: Modulo Additional Value <0-255>
;       <o15.2>      FDCTRL_STRETCH: Stretching Enable
;       <o15.0>      FDCTRL_RUN: Fractional Divider Enable
;     </h>
;     <h> Fractional Divider 15 (FDC15)
;       <o16.11..18> MSUB: Modulo Substraction Value <0-255>
;       <o16.3..10>  MADD: Modulo Additional Value <0-255>
;       <o16.2>      FDCTRL_STRETCH: Stretching Enable
;       <o16.0>      FDCTRL_RUN: Fractional Divider Enable
;     </h>
;     <h> Fractional Divider 16 (FDC16)
;       <o17.11..18> MSUB: Modulo Substraction Value <0-255>
;       <o17.3..10>  MADD: Modulo Additional Value <0-255>
;       <o17.2>      FDCTRL_STRETCH: Stretching Enable
;       <o17.0>      FDCTRL_RUN: Fractional Divider Enable
;     </h>
;     <h> Fractional Divider 17 (FDC17)
;       <o18.16..28> MSUB: Modulo Substraction Value <0-8191>
;       <o18.3..15>  MADD: Modulo Additional Value <0-8191>
;       <o18.2>      FDCTRL_STRETCH: Stretching Enable
;       <o18.0>      FDCTRL_RUN: Fractional Divider Enable
;     </h>
;     <h> Fractional Divider 18 (FDC18)
;       <o19.11..18> MSUB: Modulo Substraction Value <0-255>
;       <o19.3..10>  MADD: Modulo Additional Value <0-255>
;       <o19.2>      FDCTRL_STRETCH: Stretching Enable
;       <o19.0>      FDCTRL_RUN: Fractional Divider Enable
;     </h>
;     <h> Fractional Divider 19 (FDC19)
;       <o20.11..18> MSUB: Modulo Substraction Value <0-255>
;       <o20.3..10>  MADD: Modulo Additional Value <0-255>
;       <o20.2>      FDCTRL_STRETCH: Stretching Enable
;       <o20.0>      FDCTRL_RUN: Fractional Divider Enable
;     </h>
;     <h> Fractional Divider 20 (FDC20)
;       <o21.11..18> MSUB: Modulo Substraction Value <0-255>
;       <o21.3..10>  MADD: Modulo Additional Value <0-255>
;       <o21.2>      FDCTRL_STRETCH: Stretching Enable
;       <o21.0>      FDCTRL_RUN: Fractional Divider Enable
;     </h>
;     <h> Fractional Divider 21 (FDC21)
;       <o22.11..18> MSUB: Modulo Substraction Value <0-255>
;       <o22.3..10>  MADD: Modulo Additional Value <0-255>
;       <o22.2>      FDCTRL_STRETCH: Stretching Enable
;       <o22.0>      FDCTRL_RUN: Fractional Divider Enable
;     </h>
;     <h> Fractional Divider 22 (FDC22)
;       <o23.11..18> MSUB: Modulo Substraction Value <0-255>
;       <o23.3..10>  MADD: Modulo Additional Value <0-255>
;       <o23.2>      FDCTRL_STRETCH: Stretching Enable
;       <o23.0>      FDCTRL_RUN: Fractional Divider Enable
;     </h>
;     <h> Fractional Divider 23 (FDC23)
;       <o24.11..18> MSUB: Modulo Substraction Value <0-255>
;       <o24.3..10>  MADD: Modulo Additional Value <0-255>
;       <o24.2>      FDCTRL_STRETCH: Stretching Enable
;       <o24.0>      FDCTRL_RUN: Fractional Divider Enable
;     </h>
;   </e>
FDC_SETUP       EQU     1
FDC0_Val        EQU     0x00040405      ; 0x0007F808
FDC1_Val        EQU     0x00000000      ; 0x0007F808
FDC2_Val        EQU     0x00040405      ; 0x0007F808
FDC3_Val        EQU     0x00060605      ; 0x0007F808
FDC4_Val        EQU     0x00060605      ; 0x0007F808
FDC5_Val        EQU     0x00040405      ; 0x0007F808
FDC6_Val        EQU     0x00040405      ; 0x0007F808
FDC7_Val        EQU     0x0007E4A5      ; 0x0007F808
FDC8_Val        EQU     0x00040405      ; 0x0007F808
FDC9_Val        EQU     0x00040405      ; 0x0007F808
FDC10_Val       EQU     0x00040405      ; 0x0007F808
FDC11_Val       EQU     0x00040405      ; 0x0007F808
FDC12_Val       EQU     0x0007E4A5      ; 0x0007F808
FDC13_Val       EQU     0x00000000      ; 0x0007F808
FDC14_Val       EQU     0x00040405      ; 0x0007F808
FDC15_Val       EQU     0x00040405      ; 0x0007F808
FDC16_Val       EQU     0x00000000      ; 0x0007F808
FDC17_Val       EQU     0x00000000      ; 0x00FF0008
FDC18_Val       EQU     0x00000000      ; 0x0007F808
FDC19_Val       EQU     0x00000000      ; 0x0007F808
FDC20_Val       EQU     0x00000000      ; 0x0007F808
FDC21_Val       EQU     0x00000000      ; 0x0007F808
FDC22_Val       EQU     0x00000000      ; 0x0007F808
FDC23_Val       EQU     0x00040405      ; 0x0007F808

;   <e> Enable Select Registers Setup
;     <h> ESR0: Enable Select Register for APB0_CLK
;       <o1.1..3>    ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o1.0>       ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR1: Enable Select Register for APB1_CLK
;       <o2.1..3>    ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o2.0>       ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR2: Enable Select Register for APB2_CLK
;       <o3.1..3>    ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o3.0>       ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR3: Enable Select Register for APB3_CLK
;       <o4.1..3>    ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o4.0>       ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR4: Enable Select Register for APB4_CLK
;       <o5.1..3>    ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o5.0>       ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR5: Enable Select Register for AHB_TO_INTC_CLK
;       <o6.1..3>    ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o6.0>       ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR6: Enable Select Register for AHB0_CLK
;       <o7.1..3>    ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o7.0>       ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR7: Enable Select Register for EBI_CLK
;       <o8.1..3>    ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o8.0>       ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR8: Enable Select Register for DMA_PCLK
;       <o9.1..3>    ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o9.0>       ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR9: Enable Select Register for DMA_CLK_GATED
;       <o10.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o10.0>      ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR10: Enable Select Register for NANDFLASH_S0_CLK
;       <o11.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o11.0>      ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR11: Enable Select Register for NANDFLASH_ECC_CLK
;       <o12.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o12.0>      ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR12: Enable Select Register for NANDFLASH_AES_CLK
;       <o13.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o13.0>      ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR13: Enable Select Register for NANDFLASH_NAND_CLK
;       <o14.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o14.0>      ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR14: Enable Select Register for NANDFLASH_PCLK
;       <o15.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o15.0>      ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR15: Enable Select Register for NANDFLASH_CLOCK_OUT
;       <o16.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o16.0>      ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR16: Enable Select Register for ARM926_CORE_CLK
;       <o17.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o17.0>      ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR17: Enable Select Register for ARM926_BUSIF_CLK
;       <o18.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o18.0>      ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR18: Enable Select Register for ARM926_RETIME_CLK
;       <o19.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o19.0>      ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR19: Enable Select Register for SD_MMC_HCLK
;       <o20.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o20.0>      ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR20: Enable Select Register for SD_MMC_CCLK_IN
;       <o21.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o21.0>      ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR21: Enable Select Register for USB_OTG_AHB_CLK
;       <o22.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o22.0>      ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR22: Enable Select Register for ISRAM0_CLK
;       <o23.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o23.0>      ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR23: Enable Select Register for RED_CTL_RSCLK
;       <o24.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o24.0>      ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR24: Enable Select Register for ISRAM1_CLK
;       <o25.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o25.0>      ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR25: Enable Select Register for ISROM_CLK
;       <o26.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o26.0>      ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR26: Enable Select Register for MPMC_CFG_CLK
;       <o27.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o27.0>      ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR27: Enable Select Register for MPMC_CFG_CLK2
;       <o28.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o28.0>      ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR28: Enable Select Register for MPMC_CFG_CLK3
;       <o29.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o29.0>      ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR29: Enable Select Register for INTC_CLK
;       <o30.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC0  <1=> FDC1  <2=> FDC2  <3=> FDC3  <4=> FDC4  <5=> FDC5  <6=> FDC6
;       <o30.0>      ESR_EN: Select Clock
;                       <0=> Use SYS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR30: Enable Select Register for AHB_TO_APB0_CLK
;       <o31.1>      ESR_SEL: Fraction Divider Select
;                       <0=> FDC7  <1=> FDC8
;       <o31.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB0_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR31: Enable Select Register for EVENT_ROUTER_PCLK
;       <o32.1>      ESR_SEL: Fraction Divider Select
;                       <0=> FDC7  <1=> FDC8
;       <o32.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB0_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR32: Enable Select Register for ADC_PCLK
;       <o33.1>      ESR_SEL: Fraction Divider Select
;                       <0=> FDC7  <1=> FDC8
;       <o33.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB0_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR33: Enable Select Register for ADC_CLK
;       <o34.1>      ESR_SEL: Fraction Divider Select
;                       <0=> FDC7  <1=> FDC8
;       <o34.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB0_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR34: Enable Select Register for WDOG_PCLK
;       <o35.1>      ESR_SEL: Fraction Divider Select
;                       <0=> FDC7  <1=> FDC8
;       <o35.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB0_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR35: Enable Select Register for IOCONF_PCLK
;       <o36.1>      ESR_SEL: Fraction Divider Select
;                       <0=> FDC7  <1=> FDC8
;       <o36.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB0_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR36: Enable Select Register for CGU_PCLK
;       <o37.1>      ESR_SEL: Fraction Divider Select
;                       <0=> FDC7  <1=> FDC8
;       <o37.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB0_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR37: Enable Select Register for SYSCREG_PCLK
;       <o38.1>      ESR_SEL: Fraction Divider Select
;                       <0=> FDC7  <1=> FDC8
;       <o38.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB0_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR38: Enable Select Register for OTP_PCLK
;       <o39.1>      ESR_SEL: Fraction Divider Select
;                       <0=> FDC7  <1=> FDC8
;       <o39.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB0_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR39: Enable Select Register for RNG_PCLK
;       <o40.1>      ESR_SEL: Fraction Divider Select
;                       <0=> FDC7  <1=> FDC8
;       <o40.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB0_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR40: Enable Select Register for AHB_TO_APB1_PCLK
;       <o41.1>      ESR_SEL: Fraction Divider Select
;                       <0=> FDC9  <1=> FDC10
;       <o41.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB1_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR41: Enable Select Register for TIMER0_PCLK
;       <o42.1>      ESR_SEL: Fraction Divider Select
;                       <0=> FDC9  <1=> FDC10
;       <o42.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB1_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR42: Enable Select Register for TIMER1_PCLK
;       <o43.1>      ESR_SEL: Fraction Divider Select
;                       <0=> FDC9  <1=> FDC10
;       <o43.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB1_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR43: Enable Select Register for TIMER2_PCLK
;       <o44.1>      ESR_SEL: Fraction Divider Select
;                       <0=> FDC9  <1=> FDC10
;       <o44.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB1_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR44: Enable Select Register for TIMER3_PCLK
;       <o45.1>      ESR_SEL: Fraction Divider Select
;                       <0=> FDC9  <1=> FDC10
;       <o45.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB1_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR45: Enable Select Register for PWM_PCLK
;       <o46.1>      ESR_SEL: Fraction Divider Select
;                       <0=> FDC9  <1=> FDC10
;       <o46.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB1_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR46: Enable Select Register for PWM_PCLK_REGS
;       <o47.1>      ESR_SEL: Fraction Divider Select
;                       <0=> FDC9  <1=> FDC10
;       <o47.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB1_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR47: Enable Select Register for PWM_CLK
;       <o48.1>      ESR_SEL: Fraction Divider Select
;                       <0=> FDC9  <1=> FDC10
;       <o48.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB1_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR48: Enable Select Register for I2C0_PCLK
;       <o49.1>      ESR_SEL: Fraction Divider Select
;                       <0=> FDC9  <1=> FDC10
;       <o49.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB1_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR49: Enable Select Register for I2C1_PCLK
;       <o50.1>      ESR_SEL: Fraction Divider Select
;                       <0=> FDC9  <1=> FDC10
;       <o50.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB1_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR50: Enable Select Register for AHB_TO_APB2_PCLK
;       <o51.1..2>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC11 <1=> FDC12 <1=> FDC13
;       <o51.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB2_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR51: Enable Select Register for PCM_PCLK
;       <o52.1..2>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC11 <1=> FDC12 <1=> FDC13
;       <o52.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB2_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR52: Enable Select Register for PCM_APB_PCLK
;       <o53.1..2>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC11 <1=> FDC12 <1=> FDC13
;       <o53.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB2_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR53: Enable Select Register for UART_APB_CLK
;       <o54.1..2>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC11 <1=> FDC12 <1=> FDC13
;       <o54.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB2_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR54: Enable Select Register for LCD_PCLK
;       <o55.1..2>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC11 <1=> FDC12 <1=> FDC13
;       <o55.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB2_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR55: Enable Select Register for LCD_CLK
;       <o56.1..2>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC11 <1=> FDC12 <1=> FDC13
;       <o56.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB2_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR56: Enable Select Register for SPI_PCLK
;       <o57.1..2>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC11 <1=> FDC12 <1=> FDC13
;       <o57.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB2_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR57: Enable Select Register for SPI_PCLK_GATED
;       <o58.1..2>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC11 <1=> FDC12 <1=> FDC13
;       <o58.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB2_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR58: Enable Select Register for AHB_TO_APB3_PCLK
;       <o59.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB3_BASE_CLK <1=> Use FDC14 clock
;     </h>
;     <h> ESR59: Enable Select Register for I2S_CFG_PCLK
;       <o60.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB3_BASE_CLK <1=> Use FDC14 clock
;     </h>
;     <h> ESR60: Enable Select Register for EDGE_DET_PCLK
;       <o61.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB3_BASE_CLK <1=> Use FDC14 clock
;     </h>
;     <h> ESR61: Enable Select Register for I2STX_FIFO_0_PCLK
;       <o62.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB3_BASE_CLK <1=> Use FDC14 clock
;     </h>
;     <h> ESR62: Enable Select Register for I2STX_IF_0_PCLK
;       <o63.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB3_BASE_CLK <1=> Use FDC14 clock
;     </h>
;     <h> ESR63: Enable Select Register for I2STX_FIFO_1_PCLK
;       <o64.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB3_BASE_CLK <1=> Use FDC14 clock
;     </h>
;     <h> ESR64: Enable Select Register for I2STX_IF_1_PCLK
;       <o65.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB3_BASE_CLK <1=> Use FDC14 clock
;     </h>
;     <h> ESR65: Enable Select Register for I2SRX_FIFO_0_PCLK
;       <o66.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB3_BASE_CLK <1=> Use FDC14 clock
;     </h>
;     <h> ESR66: Enable Select Register for I2SRX_IF_0_PCLK
;       <o67.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB3_BASE_CLK <1=> Use FDC14 clock
;     </h>
;     <h> ESR67: Enable Select Register for I2SRX_FIFO_1_PCLK
;       <o68.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB3_BASE_CLK <1=> Use FDC14 clock
;     </h>
;     <h> ESR68: Enable Select Register for I2SRX_IF_1_PCLK
;       <o69.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB3_BASE_CLK <1=> Use FDC14 clock
;     </h>
;     <h> ESR69: Reserved
;       <o70.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB3_BASE_CLK <1=> Use FDC14 clock
;     </h>
;     <h> ESR70: Reserved
;       <o71.0>      ESR_EN: Select Clock
;                       <0=> Use AHB_APB3_BASE_CLK <1=> Use FDC14 clock
;     </h>
;     <h> ESR71: Enable Select Register for PCM_CLK_IP
;       <o72.0>      ESR_EN: Select Clock
;                       <0=> Use PCM_BASE_CLK <1=> Use FDC15 clock
;     </h>
;     <h> ESR72: Enable Select Register for UART_U_CLK
;       <o73.0>      ESR_EN: Select Clock
;                       <0=> Use UART_BASE_CLK <1=> Use FDC16 clock
;     </h>
;     <h> ESR73: Enable Select Register for I2S_EDGE_DETECT_CLK
;       <o74.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC17 <1=> FDC18 <2=> FDC19 <3=> FDC20 <4=> FDC21 <5=> FDC22
;       <o74.0>      ESR_EN: Select Clock
;                       <0=> Use CLK1024FS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR74: Enable Select Register for R_I2STX_BCK0_N
;       <o75.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC17 <1=> FDC18 <2=> FDC19 <3=> FDC20 <4=> FDC21 <5=> FDC22
;       <o75.0>      ESR_EN: Select Clock
;                       <0=> Use CLK1024FS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR75: Enable Select Register for I2STX_WS0
;       <o76.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC17 <1=> FDC18 <2=> FDC19 <3=> FDC20 <4=> FDC21 <5=> FDC22
;       <o76.0>      ESR_EN: Select Clock
;                       <0=> Use CLK1024FS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR76: Enable Select Register for I2STX_CLK0
;       <o77.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC17 <1=> FDC18 <2=> FDC19 <3=> FDC20 <4=> FDC21 <5=> FDC22
;       <o77.0>      ESR_EN: Select Clock
;                       <0=> Use CLK1024FS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR77: Enable Select Register for I2STX_IF_BCK1_N
;       <o78.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC17 <1=> FDC18 <2=> FDC19 <3=> FDC20 <4=> FDC21 <5=> FDC22
;       <o78.0>      ESR_EN: Select Clock
;                       <0=> Use CLK1024FS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR78: Enable Select Register for I2STX_WS1
;       <o79.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC17 <1=> FDC18 <2=> FDC19 <3=> FDC20 <4=> FDC21 <5=> FDC22
;       <o79.0>      ESR_EN: Select Clock
;                       <0=> Use CLK1024FS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR79: Enable Select Register for CLK_256FS
;       <o80.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC17 <1=> FDC18 <2=> FDC19 <3=> FDC20 <4=> FDC21 <5=> FDC22
;       <o80.0>      ESR_EN: Select Clock
;                       <0=> Use CLK1024FS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR80: Enable Select Register for I2SRX_BCK0_N
;       <o81.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC17 <1=> FDC18 <2=> FDC19 <3=> FDC20 <4=> FDC21 <5=> FDC22
;       <o81.0>      ESR_EN: Select Clock
;                       <0=> Use CLK1024FS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR81: Enable Select Register for I2SRX_WS0
;       <o82.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC17 <1=> FDC18 <2=> FDC19 <3=> FDC20 <4=> FDC21 <5=> FDC22
;       <o82.0>      ESR_EN: Select Clock
;                       <0=> Use CLK1024FS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR82: Enable Select Register for I2SRX_BCK1_N
;       <o83.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC17 <1=> FDC18 <2=> FDC19 <3=> FDC20 <4=> FDC21 <5=> FDC22
;       <o83.0>      ESR_EN: Select Clock
;                       <0=> Use CLK1024FS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR83: Enable Select Register for I2SRX_WS1
;       <o84.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC17 <1=> FDC18 <2=> FDC19 <3=> FDC20 <4=> FDC21 <5=> FDC22
;       <o84.0>      ESR_EN: Select Clock
;                       <0=> Use CLK1024FS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR84: Reserved
;       <o85.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC17 <1=> FDC18 <2=> FDC19 <3=> FDC20 <4=> FDC21 <5=> FDC22
;       <o85.0>      ESR_EN: Select Clock
;                       <0=> Use CLK1024FS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR85: Reserved
;       <o86.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC17 <1=> FDC18 <2=> FDC19 <3=> FDC20 <4=> FDC21 <5=> FDC22
;       <o86.0>      ESR_EN: Select Clock
;                       <0=> Use CLK1024FS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR86: Reserved
;       <o87.1..3>   ESR_SEL: Fraction Divider Select
;                       <0=> FDC17 <1=> FDC18 <2=> FDC19 <3=> FDC20 <4=> FDC21 <5=> FDC22
;       <o87.0>      ESR_EN: Select Clock
;                       <0=> Use CLK1024FS_BASE_CLK <1=> Use FDC clock
;     </h>
;     <h> ESR87: Enable Select Register for SPI_CLK
;       <o88.0>      ESR_EN: Select Clock
;                       <0=> Use SPI_CLK_BASE_CLK <1=> Use FDC23 clock
;     </h>
;     <h> ESR88: Enable Select Register for SPI_CLK_GATED
;       <o89.0>      ESR_EN: Select Clock
;                       <0=> Use SPI_CLK_BASE_CLK <1=> Use FDC23 clock
;     </h>
;   </e>
ESR_SETUP       EQU     1
ESR0_Val        EQU     0x00000001      ; 0x00000000
ESR1_Val        EQU     0x00000001      ; 0x00000000
ESR2_Val        EQU     0x00000001      ; 0x00000000
ESR3_Val        EQU     0x00000001      ; 0x00000000
ESR4_Val        EQU     0x00000001      ; 0x00000000
ESR5_Val        EQU     0x00000001      ; 0x00000000
ESR6_Val        EQU     0x00000001      ; 0x00000000
ESR7_Val        EQU     0x0000000D      ; 0x00000000
ESR8_Val        EQU     0x00000001      ; 0x00000000
ESR9_Val        EQU     0x00000001      ; 0x00000000
ESR10_Val       EQU     0x00000001      ; 0x00000000
ESR11_Val       EQU     0x00000007      ; 0x00000000
ESR12_Val       EQU     0x00000005      ; 0x00000000
ESR13_Val       EQU     0x00000005      ; 0x00000000
ESR14_Val       EQU     0x00000001      ; 0x00000000
ESR15_Val       EQU     0x0000000B      ; 0x00000000
ESR16_Val       EQU     0x00000000      ; 0x00000000
ESR17_Val       EQU     0x00000001      ; 0x00000000
ESR18_Val       EQU     0x00000000      ; 0x00000000
ESR19_Val       EQU     0x00000001      ; 0x00000000
ESR20_Val       EQU     0x00000009      ; 0x00000000
ESR21_Val       EQU     0x00000001      ; 0x00000000
ESR22_Val       EQU     0x00000001      ; 0x00000000
ESR23_Val       EQU     0x00000000      ; 0x00000000
ESR24_Val       EQU     0x00000001      ; 0x00000000
ESR25_Val       EQU     0x00000001      ; 0x00000000
ESR26_Val       EQU     0x00000001      ; 0x00000000
ESR27_Val       EQU     0x00000001      ; 0x00000000
ESR28_Val       EQU     0x00000000      ; 0x00000000
ESR29_Val       EQU     0x00000001      ; 0x00000000
ESR30_Val       EQU     0x00000003      ; 0x00000000
ESR31_Val       EQU     0x00000003      ; 0x00000000
ESR32_Val       EQU     0x00000003      ; 0x00000000
ESR33_Val       EQU     0x00000001      ; 0x00000000
ESR34_Val       EQU     0x00000003      ; 0x00000000
ESR35_Val       EQU     0x00000003      ; 0x00000000
ESR36_Val       EQU     0x00000003      ; 0x00000000
ESR37_Val       EQU     0x00000003      ; 0x00000000
ESR38_Val       EQU     0x00000003      ; 0x00000000
ESR39_Val       EQU     0x00000003      ; 0x00000000
ESR40_Val       EQU     0x00000001      ; 0x00000000
ESR41_Val       EQU     0x00000001      ; 0x00000000
ESR42_Val       EQU     0x00000001      ; 0x00000000
ESR43_Val       EQU     0x00000001      ; 0x00000000
ESR44_Val       EQU     0x00000001      ; 0x00000000
ESR45_Val       EQU     0x00000001      ; 0x00000000
ESR46_Val       EQU     0x00000001      ; 0x00000000
ESR47_Val       EQU     0x00000003      ; 0x00000000
ESR48_Val       EQU     0x00000001      ; 0x00000000
ESR49_Val       EQU     0x00000001      ; 0x00000000
ESR50_Val       EQU     0x00000001      ; 0x00000000
ESR51_Val       EQU     0x00000001      ; 0x00000000
ESR52_Val       EQU     0x00000001      ; 0x00000000
ESR53_Val       EQU     0x00000001      ; 0x00000000
ESR54_Val       EQU     0x00000001      ; 0x00000000
ESR55_Val       EQU     0x00000001      ; 0x00000000
ESR56_Val       EQU     0x00000001      ; 0x00000000
ESR57_Val       EQU     0x00000001      ; 0x00000000
ESR58_Val       EQU     0x00000001      ; 0x00000000
ESR59_Val       EQU     0x00000001      ; 0x00000000
ESR60_Val       EQU     0x00000001      ; 0x00000000
ESR61_Val       EQU     0x00000001      ; 0x00000000
ESR62_Val       EQU     0x00000001      ; 0x00000000
ESR63_Val       EQU     0x00000001      ; 0x00000000
ESR64_Val       EQU     0x00000001      ; 0x00000000
ESR65_Val       EQU     0x00000001      ; 0x00000000
ESR66_Val       EQU     0x00000001      ; 0x00000000
ESR67_Val       EQU     0x00000001      ; 0x00000000
ESR68_Val       EQU     0x00000001      ; 0x00000000
ESR69_Val       EQU     0x00000000      ; 0x00000000
ESR70_Val       EQU     0x00000000      ; 0x00000000
ESR71_Val       EQU     0x00000001      ; 0x00000000
ESR72_Val       EQU     0x00000000      ; 0x00000000
ESR73_Val       EQU     0x00000000      ; 0x00000000
ESR74_Val       EQU     0x00000000      ; 0x00000000
ESR75_Val       EQU     0x00000000      ; 0x00000000
ESR76_Val       EQU     0x00000000      ; 0x00000000
ESR77_Val       EQU     0x00000000      ; 0x00000000
ESR78_Val       EQU     0x00000000      ; 0x00000000
ESR79_Val       EQU     0x00000000      ; 0x00000000
ESR80_Val       EQU     0x00000000      ; 0x00000000
ESR81_Val       EQU     0x00000000      ; 0x00000000
ESR82_Val       EQU     0x00000000      ; 0x00000000
ESR83_Val       EQU     0x00000000      ; 0x00000000
ESR84_Val       EQU     0x00000000      ; 0x00000000
ESR85_Val       EQU     0x00000000      ; 0x00000000
ESR86_Val       EQU     0x00000000      ; 0x00000000
ESR87_Val       EQU     0x00000001      ; 0x00000000
ESR88_Val       EQU     0x00000001      ; 0x00000000

;   <e> Base Control Registers Setup
;     <h> BCR0: Base Control Register 0
;       <o1.0>       FDRUN: Fractional Dividers in Base Run
;     </h>
;     <h> BCR1: Base Control Register 1
;       <o2.0>       FDRUN: Fractional Dividers in Base Run
;     </h>
;     <h> BCR2: Base Control Register 2
;       <o3.0>       FDRUN: Fractional Dividers in Base Run
;     </h>
;     <h> BCR3: Base Control Register 3
;       <o4.0>       FDRUN: Fractional Dividers in Base Run
;     </h>
;     <h> BCR7: Base Control Register 7
;       <o5.0>       FDRUN: Fractional Dividers in Base Run
;     </h>
;   </e>
BCR_SETUP       EQU     1
BCR0_Val        EQU     0x00000001      ; 0x00000000
BCR1_Val        EQU     0x00000001      ; 0x00000000
BCR2_Val        EQU     0x00000001      ; 0x00000000
BCR3_Val        EQU     0x00000001      ; 0x00000000
BCR7_Val        EQU     0x00000000      ; 0x00000000

;   <e> Power Control Registers Setup
;     <h> PCR0: Power Control Register for APB0_CLK
;       <o1.4>       ENOUT_EN: Enableout Enable
;       <o1.3>       EXTEN_EN: External Enabling Enable
;       <o1.2>       WAKE_EN:  Wakeup Enable
;       <o1.1>       AUTO:     Auto Enable
;       <o1.0>       RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR1: Power Control Register for APB1_CLK
;       <o2.4>       ENOUT_EN: Enableout Enable
;       <o2.3>       EXTEN_EN: External Enabling Enable
;       <o2.2>       WAKE_EN:  Wakeup Enable
;       <o2.1>       AUTO:     Auto Enable
;       <o2.0>       RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR2: Power Control Register for APB1_CLK
;       <o3.4>       ENOUT_EN: Enableout Enable
;       <o3.3>       EXTEN_EN: External Enabling Enable
;       <o3.2>       WAKE_EN:  Wakeup Enable
;       <o3.1>       AUTO:     Auto Enable
;       <o3.0>       RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR3: Power Control Register for APB3_CLK
;       <o4.4>       ENOUT_EN: Enableout Enable
;       <o4.3>       EXTEN_EN: External Enabling Enable
;       <o4.2>       WAKE_EN:  Wakeup Enable
;       <o4.1>       AUTO:     Auto Enable
;       <o4.0>       RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR4: Power Control Register for APB4_CLK
;       <o5.4>       ENOUT_EN: Enableout Enable
;       <o5.3>       EXTEN_EN: External Enabling Enable
;       <o5.2>       WAKE_EN:  Wakeup Enable
;       <o5.1>       AUTO:     Auto Enable
;       <o5.0>       RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR5: Power Control Register for AHB_TO_INTC_CLK
;       <o6.4>       ENOUT_EN: Enableout Enable
;       <o6.3>       EXTEN_EN: External Enabling Enable
;       <o6.2>       WAKE_EN:  Wakeup Enable
;       <o6.1>       AUTO:     Auto Enable
;       <o6.0>       RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR6: Power Control Register for AHB0_CLK
;       <o7.4>       ENOUT_EN: Enableout Enable
;       <o7.3>       EXTEN_EN: External Enabling Enable
;       <o7.2>       WAKE_EN:  Wakeup Enable
;       <o7.1>       AUTO:     Auto Enable
;       <o7.0>       RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR7: Power Control Register for EBI_CLK
;       <o8.4>       ENOUT_EN: Enableout Enable
;       <o8.3>       EXTEN_EN: External Enabling Enable
;       <o8.2>       WAKE_EN:  Wakeup Enable
;       <o8.1>       AUTO:     Auto Enable
;       <o8.0>       RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR8: Power Control Register for DMA_PCLK
;       <o9.4>       ENOUT_EN: Enableout Enable
;       <o9.3>       EXTEN_EN: External Enabling Enable
;       <o9.2>       WAKE_EN:  Wakeup Enable
;       <o9.1>       AUTO:     Auto Enable
;       <o9.0>       RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR9: Power Control Register for DMA_CLK_GATED
;       <o10.4>      ENOUT_EN: Enableout Enable
;       <o10.3>      EXTEN_EN: External Enabling Enable
;       <o10.2>      WAKE_EN:  Wakeup Enable
;       <o10.1>      AUTO:     Auto Enable
;       <o10.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR10: Power Control Register for NANDFLASH_S0_CLK
;       <o11.4>      ENOUT_EN: Enableout Enable
;       <o11.3>      EXTEN_EN: External Enabling Enable
;       <o11.2>      WAKE_EN:  Wakeup Enable
;       <o11.1>      AUTO:     Auto Enable
;       <o11.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR11: Power Control Register for NANDFLASH_ECC_CLK
;       <o12.4>      ENOUT_EN: Enableout Enable
;       <o12.3>      EXTEN_EN: External Enabling Enable
;       <o12.2>      WAKE_EN:  Wakeup Enable
;       <o12.1>      AUTO:     Auto Enable
;       <o12.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR12: Power Control Register for NANDFLASH_AES_CLK
;       <o13.4>      ENOUT_EN: Enableout Enable
;       <o13.3>      EXTEN_EN: External Enabling Enable
;       <o13.2>      WAKE_EN:  Wakeup Enable
;       <o13.1>      AUTO:     Auto Enable
;       <o13.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR13: Power Control Register for NANDFLASH_NAND_CLK
;       <o14.4>      ENOUT_EN: Enableout Enable
;       <o14.3>      EXTEN_EN: External Enabling Enable
;       <o14.2>      WAKE_EN:  Wakeup Enable
;       <o14.1>      AUTO:     Auto Enable
;       <o14.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR14: Power Control Register for NANDFLASH_PCLK
;       <o15.4>      ENOUT_EN: Enableout Enable
;       <o15.3>      EXTEN_EN: External Enabling Enable
;       <o15.2>      WAKE_EN:  Wakeup Enable
;       <o15.1>      AUTO:     Auto Enable
;       <o15.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR15: Power Control Register for NANDFLASH_CLOCK_OUT
;       <o16.4>      ENOUT_EN: Enableout Enable
;       <o16.3>      EXTEN_EN: External Enabling Enable
;       <o16.2>      WAKE_EN:  Wakeup Enable
;       <o16.1>      AUTO:     Auto Enable
;       <o16.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR16: Power Control Register for ARM926_CORE_CLK
;       <o17.4>      ENOUT_EN: Enableout Enable
;       <o17.3>      EXTEN_EN: External Enabling Enable
;       <o17.2>      WAKE_EN:  Wakeup Enable
;       <o17.1>      AUTO:     Auto Enable
;       <o17.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR17: Power Control Register for ARM926_BUSIF_CLK
;       <o18.4>      ENOUT_EN: Enableout Enable
;       <o18.3>      EXTEN_EN: External Enabling Enable
;       <o18.2>      WAKE_EN:  Wakeup Enable
;       <o18.1>      AUTO:     Auto Enable
;       <o18.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR18: Power Control Register for ARM926_RETIME_CLK
;       <o19.4>      ENOUT_EN: Enableout Enable
;       <o19.3>      EXTEN_EN: External Enabling Enable
;       <o19.2>      WAKE_EN:  Wakeup Enable
;       <o19.1>      AUTO:     Auto Enable
;       <o19.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR19: Power Control Register for SD_MMC_HCLK
;       <o20.4>      ENOUT_EN: Enableout Enable
;       <o20.3>      EXTEN_EN: External Enabling Enable
;       <o20.2>      WAKE_EN:  Wakeup Enable
;       <o20.1>      AUTO:     Auto Enable
;       <o20.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR20: Power Control Register for SD_MMC_CCLK_IN
;       <o21.4>      ENOUT_EN: Enableout Enable
;       <o21.3>      EXTEN_EN: External Enabling Enable
;       <o21.2>      WAKE_EN:  Wakeup Enable
;       <o21.1>      AUTO:     Auto Enable
;       <o21.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR21: Power Control Register for USB_OTG_AHB_CLK
;       <o22.4>      ENOUT_EN: Enableout Enable
;       <o22.3>      EXTEN_EN: External Enabling Enable
;       <o22.2>      WAKE_EN:  Wakeup Enable
;       <o22.1>      AUTO:     Auto Enable
;       <o22.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR22: Power Control Register for ISRAM0_CLK
;       <o23.4>      ENOUT_EN: Enableout Enable
;       <o23.3>      EXTEN_EN: External Enabling Enable
;       <o23.2>      WAKE_EN:  Wakeup Enable
;       <o23.1>      AUTO:     Auto Enable
;       <o23.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR23: Power Control Register for RED_CTL_RSCLK
;       <o24.4>      ENOUT_EN: Enableout Enable
;       <o24.3>      EXTEN_EN: External Enabling Enable
;       <o24.2>      WAKE_EN:  Wakeup Enable
;       <o24.1>      AUTO:     Auto Enable
;       <o24.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR24: Power Control Register for ISRAM1_CLK
;       <o25.4>      ENOUT_EN: Enableout Enable
;       <o25.3>      EXTEN_EN: External Enabling Enable
;       <o25.2>      WAKE_EN:  Wakeup Enable
;       <o25.1>      AUTO:     Auto Enable
;       <o25.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR25: Power Control Register for ISROM_CLK
;       <o26.4>      ENOUT_EN: Enableout Enable
;       <o26.3>      EXTEN_EN: External Enabling Enable
;       <o26.2>      WAKE_EN:  Wakeup Enable
;       <o26.1>      AUTO:     Auto Enable
;       <o26.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR26: Power Control Register for MPMC_CFG_CLK
;       <o27.4>      ENOUT_EN: Enableout Enable
;       <o27.3>      EXTEN_EN: External Enabling Enable
;       <o27.2>      WAKE_EN:  Wakeup Enable
;       <o27.1>      AUTO:     Auto Enable
;       <o27.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR27: Power Control Register for MPMC_CFG_CLK2
;       <o28.4>      ENOUT_EN: Enableout Enable
;       <o28.3>      EXTEN_EN: External Enabling Enable
;       <o28.2>      WAKE_EN:  Wakeup Enable
;       <o28.1>      AUTO:     Auto Enable
;       <o28.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR28: Power Control Register for MPMC_CFG_CLK3
;       <o29.4>      ENOUT_EN: Enableout Enable
;       <o29.3>      EXTEN_EN: External Enabling Enable
;       <o29.2>      WAKE_EN:  Wakeup Enable
;       <o29.1>      AUTO:     Auto Enable
;       <o29.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR29: Power Control Register for INTC_CLK
;       <o30.4>      ENOUT_EN: Enableout Enable
;       <o30.3>      EXTEN_EN: External Enabling Enable
;       <o30.2>      WAKE_EN:  Wakeup Enable
;       <o30.1>      AUTO:     Auto Enable
;       <o30.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR30: Power Control Register for AHB_TO_APB0_CLK
;       <o31.4>      ENOUT_EN: Enableout Enable
;       <o31.3>      EXTEN_EN: External Enabling Enable
;       <o31.2>      WAKE_EN:  Wakeup Enable
;       <o31.1>      AUTO:     Auto Enable
;       <o31.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR31: Power Control Register for EVENT_ROUTER_PCLK
;       <o32.4>      ENOUT_EN: Enableout Enable
;       <o32.3>      EXTEN_EN: External Enabling Enable
;       <o32.2>      WAKE_EN:  Wakeup Enable
;       <o32.1>      AUTO:     Auto Enable
;       <o32.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR32: Power Control Register for ADC_PCLK
;       <o33.4>      ENOUT_EN: Enableout Enable
;       <o33.3>      EXTEN_EN: External Enabling Enable
;       <o33.2>      WAKE_EN:  Wakeup Enable
;       <o33.1>      AUTO:     Auto Enable
;       <o33.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR33: Power Control Register for ADC_CLK
;       <o34.4>      ENOUT_EN: Enableout Enable
;       <o34.3>      EXTEN_EN: External Enabling Enable
;       <o34.2>      WAKE_EN:  Wakeup Enable
;       <o34.1>      AUTO:     Auto Enable
;       <o34.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR34: Power Control Register for WDOG_PCLK
;       <o35.4>      ENOUT_EN: Enableout Enable
;       <o35.3>      EXTEN_EN: External Enabling Enable
;       <o35.2>      WAKE_EN:  Wakeup Enable
;       <o35.1>      AUTO:     Auto Enable
;       <o35.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR35: Power Control Register for IOCONF_PCLK
;       <o36.4>      ENOUT_EN: Enableout Enable
;       <o36.3>      EXTEN_EN: External Enabling Enable
;       <o36.2>      WAKE_EN:  Wakeup Enable
;       <o36.1>      AUTO:     Auto Enable
;       <o36.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR36: Power Control Register for CGU_PCLK
;       <o37.4>      ENOUT_EN: Enableout Enable
;       <o37.3>      EXTEN_EN: External Enabling Enable
;       <o37.2>      WAKE_EN:  Wakeup Enable
;       <o37.1>      AUTO:     Auto Enable
;       <o37.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR37: Power Control Register for SYSCREG_PCLK
;       <o38.4>      ENOUT_EN: Enableout Enable
;       <o38.3>      EXTEN_EN: External Enabling Enable
;       <o38.2>      WAKE_EN:  Wakeup Enable
;       <o38.1>      AUTO:     Auto Enable
;       <o38.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR38: Power Control Register for OTP_PCLK
;       <o39.4>      ENOUT_EN: Enableout Enable
;       <o39.3>      EXTEN_EN: External Enabling Enable
;       <o39.2>      WAKE_EN:  Wakeup Enable
;       <o39.1>      AUTO:     Auto Enable
;       <o39.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR39: Power Control Register for RNG_PCLK
;       <o40.4>      ENOUT_EN: Enableout Enable
;       <o40.3>      EXTEN_EN: External Enabling Enable
;       <o40.2>      WAKE_EN:  Wakeup Enable
;       <o40.1>      AUTO:     Auto Enable
;       <o40.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR40: Power Control Register for AHB_TO_APB1_PCLK
;       <o41.4>      ENOUT_EN: Enableout Enable
;       <o41.3>      EXTEN_EN: External Enabling Enable
;       <o41.2>      WAKE_EN:  Wakeup Enable
;       <o41.1>      AUTO:     Auto Enable
;       <o41.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR41: Power Control Register for TIMER0_PCLK
;       <o42.4>      ENOUT_EN: Enableout Enable
;       <o42.3>      EXTEN_EN: External Enabling Enable
;       <o42.2>      WAKE_EN:  Wakeup Enable
;       <o42.1>      AUTO:     Auto Enable
;       <o42.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR42: Power Control Register for TIMER1_PCLK
;       <o43.4>      ENOUT_EN: Enableout Enable
;       <o43.3>      EXTEN_EN: External Enabling Enable
;       <o43.2>      WAKE_EN:  Wakeup Enable
;       <o43.1>      AUTO:     Auto Enable
;       <o43.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR43: Power Control Register for TIMER2_PCLK
;       <o44.4>      ENOUT_EN: Enableout Enable
;       <o44.3>      EXTEN_EN: External Enabling Enable
;       <o44.2>      WAKE_EN:  Wakeup Enable
;       <o44.1>      AUTO:     Auto Enable
;       <o44.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR44: Power Control Register for TIMER3_PCLK
;       <o45.4>      ENOUT_EN: Enableout Enable
;       <o45.3>      EXTEN_EN: External Enabling Enable
;       <o45.2>      WAKE_EN:  Wakeup Enable
;       <o45.1>      AUTO:     Auto Enable
;       <o45.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR45: Power Control Register for PWM_PCLK
;       <o46.4>      ENOUT_EN: Enableout Enable
;       <o46.3>      EXTEN_EN: External Enabling Enable
;       <o46.2>      WAKE_EN:  Wakeup Enable
;       <o46.1>      AUTO:     Auto Enable
;       <o46.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR46: Power Control Register for PWM_PCLK_REGS
;       <o47.4>      ENOUT_EN: Enableout Enable
;       <o47.3>      EXTEN_EN: External Enabling Enable
;       <o47.2>      WAKE_EN:  Wakeup Enable
;       <o47.1>      AUTO:     Auto Enable
;       <o47.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR47: Power Control Register for PWM_CLK
;       <o48.4>      ENOUT_EN: Enableout Enable
;       <o48.3>      EXTEN_EN: External Enabling Enable
;       <o48.2>      WAKE_EN:  Wakeup Enable
;       <o48.1>      AUTO:     Auto Enable
;       <o48.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR48: Power Control Register for I2C0_PCLK
;       <o49.4>      ENOUT_EN: Enableout Enable
;       <o49.3>      EXTEN_EN: External Enabling Enable
;       <o49.2>      WAKE_EN:  Wakeup Enable
;       <o49.1>      AUTO:     Auto Enable
;       <o49.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR49: Power Control Register for I2C1_PCLK
;       <o50.4>      ENOUT_EN: Enableout Enable
;       <o50.3>      EXTEN_EN: External Enabling Enable
;       <o50.2>      WAKE_EN:  Wakeup Enable
;       <o50.1>      AUTO:     Auto Enable
;       <o50.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR50: Power Control Register for AHB_TO_APB2_PCLK
;       <o51.4>      ENOUT_EN: Enableout Enable
;       <o51.3>      EXTEN_EN: External Enabling Enable
;       <o51.2>      WAKE_EN:  Wakeup Enable
;       <o51.1>      AUTO:     Auto Enable
;       <o51.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR51: Power Control Register for PCM_PCLK
;       <o52.4>      ENOUT_EN: Enableout Enable
;       <o52.3>      EXTEN_EN: External Enabling Enable
;       <o52.2>      WAKE_EN:  Wakeup Enable
;       <o52.1>      AUTO:     Auto Enable
;       <o52.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR52: Power Control Register for PCM_APB_PCLK
;       <o53.4>      ENOUT_EN: Enableout Enable
;       <o53.3>      EXTEN_EN: External Enabling Enable
;       <o53.2>      WAKE_EN:  Wakeup Enable
;       <o53.1>      AUTO:     Auto Enable
;       <o53.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR53: Power Control Register for UART_APB_CLK
;       <o54.4>      ENOUT_EN: Enableout Enable
;       <o54.3>      EXTEN_EN: External Enabling Enable
;       <o54.2>      WAKE_EN:  Wakeup Enable
;       <o54.1>      AUTO:     Auto Enable
;       <o54.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR54: Power Control Register for LCD_PCLK
;       <o55.4>      ENOUT_EN: Enableout Enable
;       <o55.3>      EXTEN_EN: External Enabling Enable
;       <o55.2>      WAKE_EN:  Wakeup Enable
;       <o55.1>      AUTO:     Auto Enable
;       <o55.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR55: Power Control Register for LCD_CLK
;       <o56.4>      ENOUT_EN: Enableout Enable
;       <o56.3>      EXTEN_EN: External Enabling Enable
;       <o56.2>      WAKE_EN:  Wakeup Enable
;       <o56.1>      AUTO:     Auto Enable
;       <o56.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR56: Power Control Register for SPI_PCLK
;       <o57.4>      ENOUT_EN: Enableout Enable
;       <o57.3>      EXTEN_EN: External Enabling Enable
;       <o57.2>      WAKE_EN:  Wakeup Enable
;       <o57.1>      AUTO:     Auto Enable
;       <o57.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR57: Power Control Register for SPI_PCLK_GATED
;       <o58.4>      ENOUT_EN: Enableout Enable
;       <o58.3>      EXTEN_EN: External Enabling Enable
;       <o58.2>      WAKE_EN:  Wakeup Enable
;       <o58.1>      AUTO:     Auto Enable
;       <o58.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR58: Power Control Register for AHB_TO_APB3_PCLK
;       <o59.4>      ENOUT_EN: Enableout Enable
;       <o59.3>      EXTEN_EN: External Enabling Enable
;       <o59.2>      WAKE_EN:  Wakeup Enable
;       <o59.1>      AUTO:     Auto Enable
;       <o59.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR59: Power Control Register for I2S_CFG_PCLK
;       <o60.4>      ENOUT_EN: Enableout Enable
;       <o60.3>      EXTEN_EN: External Enabling Enable
;       <o60.2>      WAKE_EN:  Wakeup Enable
;       <o60.1>      AUTO:     Auto Enable
;       <o60.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR60: Power Control Register for EDGE_DET_PCLK
;       <o61.4>      ENOUT_EN: Enableout Enable
;       <o61.3>      EXTEN_EN: External Enabling Enable
;       <o61.2>      WAKE_EN:  Wakeup Enable
;       <o61.1>      AUTO:     Auto Enable
;       <o61.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR61: Power Control Register for I2STX_FIFO_0_PCLK
;       <o62.4>      ENOUT_EN: Enableout Enable
;       <o62.3>      EXTEN_EN: External Enabling Enable
;       <o62.2>      WAKE_EN:  Wakeup Enable
;       <o62.1>      AUTO:     Auto Enable
;       <o62.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR62: Power Control Register for I2STX_IF_0_PCLK
;       <o63.4>      ENOUT_EN: Enableout Enable
;       <o63.3>      EXTEN_EN: External Enabling Enable
;       <o63.2>      WAKE_EN:  Wakeup Enable
;       <o63.1>      AUTO:     Auto Enable
;       <o63.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR63: Power Control Register for I2STX_FIFO_1_PCLK
;       <o64.4>      ENOUT_EN: Enableout Enable
;       <o64.3>      EXTEN_EN: External Enabling Enable
;       <o64.2>      WAKE_EN:  Wakeup Enable
;       <o64.1>      AUTO:     Auto Enable
;       <o64.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR64: Power Control Register for I2STX_IF_1_PCLK
;       <o65.4>      ENOUT_EN: Enableout Enable
;       <o65.3>      EXTEN_EN: External Enabling Enable
;       <o65.2>      WAKE_EN:  Wakeup Enable
;       <o65.1>      AUTO:     Auto Enable
;       <o65.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR65: Power Control Register for I2SRX_FIFO_0_PCLK
;       <o66.4>      ENOUT_EN: Enableout Enable
;       <o66.3>      EXTEN_EN: External Enabling Enable
;       <o66.2>      WAKE_EN:  Wakeup Enable
;       <o66.1>      AUTO:     Auto Enable
;       <o66.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR66: Power Control Register for I2SRX_IF_0_PCLK
;       <o67.4>      ENOUT_EN: Enableout Enable
;       <o67.3>      EXTEN_EN: External Enabling Enable
;       <o67.2>      WAKE_EN:  Wakeup Enable
;       <o67.1>      AUTO:     Auto Enable
;       <o67.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR67: Power Control Register for I2SRX_FIFO_1_PCLK
;       <o68.4>      ENOUT_EN: Enableout Enable
;       <o68.3>      EXTEN_EN: External Enabling Enable
;       <o68.2>      WAKE_EN:  Wakeup Enable
;       <o68.1>      AUTO:     Auto Enable
;       <o68.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR68: Power Control Register for I2SRX_IF_1_PCLK
;       <o69.4>      ENOUT_EN: Enableout Enable
;       <o69.3>      EXTEN_EN: External Enabling Enable
;       <o69.2>      WAKE_EN:  Wakeup Enable
;       <o69.1>      AUTO:     Auto Enable
;       <o69.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR69: Reserved
;       <o70.4>      ENOUT_EN: Enableout Enable
;       <o70.3>      EXTEN_EN: External Enabling Enable
;       <o70.2>      WAKE_EN:  Wakeup Enable
;       <o70.1>      AUTO:     Auto Enable
;       <o70.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR70: Reserved
;       <o71.4>      ENOUT_EN: Enableout Enable
;       <o71.3>      EXTEN_EN: External Enabling Enable
;       <o71.2>      WAKE_EN:  Wakeup Enable
;       <o71.1>      AUTO:     Auto Enable
;       <o71.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR71: Power Control Register for PCM_CLK_IP
;       <o72.4>      ENOUT_EN: Enableout Enable
;       <o72.3>      EXTEN_EN: External Enabling Enable
;       <o72.2>      WAKE_EN:  Wakeup Enable
;       <o72.1>      AUTO:     Auto Enable
;       <o72.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR72: Power Control Register for UART_U_CLK
;       <o73.4>      ENOUT_EN: Enableout Enable
;       <o73.3>      EXTEN_EN: External Enabling Enable
;       <o73.2>      WAKE_EN:  Wakeup Enable
;       <o73.1>      AUTO:     Auto Enable
;       <o73.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR73: Power Control Register for I2S_EDGE_DETECT_CLK
;       <o74.4>      ENOUT_EN: Enableout Enable
;       <o74.3>      EXTEN_EN: External Enabling Enable
;       <o74.2>      WAKE_EN:  Wakeup Enable
;       <o74.1>      AUTO:     Auto Enable
;       <o74.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR74: Power Control Register for R_I2STX_BCK0_N
;       <o75.4>      ENOUT_EN: Enableout Enable
;       <o75.3>      EXTEN_EN: External Enabling Enable
;       <o75.2>      WAKE_EN:  Wakeup Enable
;       <o75.1>      AUTO:     Auto Enable
;       <o75.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR75: Power Control Register for I2STX_WS0
;       <o76.4>      ENOUT_EN: Enableout Enable
;       <o76.3>      EXTEN_EN: External Enabling Enable
;       <o76.2>      WAKE_EN:  Wakeup Enable
;       <o76.1>      AUTO:     Auto Enable
;       <o76.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR76: Power Control Register for I2STX_CLK0
;       <o77.4>      ENOUT_EN: Enableout Enable
;       <o77.3>      EXTEN_EN: External Enabling Enable
;       <o77.2>      WAKE_EN:  Wakeup Enable
;       <o77.1>      AUTO:     Auto Enable
;       <o77.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR77: Power Control Register for I2STX_IF_BCK1_N
;       <o78.4>      ENOUT_EN: Enableout Enable
;       <o78.3>      EXTEN_EN: External Enabling Enable
;       <o78.2>      WAKE_EN:  Wakeup Enable
;       <o78.1>      AUTO:     Auto Enable
;       <o78.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR78: Power Control Register for I2STX_WS1
;       <o79.4>      ENOUT_EN: Enableout Enable
;       <o79.3>      EXTEN_EN: External Enabling Enable
;       <o79.2>      WAKE_EN:  Wakeup Enable
;       <o79.1>      AUTO:     Auto Enable
;       <o79.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR79: Power Control Register for CLK_256FS
;       <o80.4>      ENOUT_EN: Enableout Enable
;       <o80.3>      EXTEN_EN: External Enabling Enable
;       <o80.2>      WAKE_EN:  Wakeup Enable
;       <o80.1>      AUTO:     Auto Enable
;       <o80.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR80: Power Control Register for I2SRX_BCK0_N
;       <o81.4>      ENOUT_EN: Enableout Enable
;       <o81.3>      EXTEN_EN: External Enabling Enable
;       <o81.2>      WAKE_EN:  Wakeup Enable
;       <o81.1>      AUTO:     Auto Enable
;       <o81.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR81: Power Control Register for I2SRX_WS0
;       <o82.4>      ENOUT_EN: Enableout Enable
;       <o82.3>      EXTEN_EN: External Enabling Enable
;       <o82.2>      WAKE_EN:  Wakeup Enable
;       <o82.1>      AUTO:     Auto Enable
;       <o82.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR82: Power Control Register for I2SRX_BCK1_N
;       <o83.4>      ENOUT_EN: Enableout Enable
;       <o83.3>      EXTEN_EN: External Enabling Enable
;       <o83.2>      WAKE_EN:  Wakeup Enable
;       <o83.1>      AUTO:     Auto Enable
;       <o83.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR83: Power Control Register for I2SRX_WS1
;       <o84.4>      ENOUT_EN: Enableout Enable
;       <o84.3>      EXTEN_EN: External Enabling Enable
;       <o84.2>      WAKE_EN:  Wakeup Enable
;       <o84.1>      AUTO:     Auto Enable
;       <o84.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR84: Reserved
;       <o85.4>      ENOUT_EN: Enableout Enable
;       <o85.3>      EXTEN_EN: External Enabling Enable
;       <o85.2>      WAKE_EN:  Wakeup Enable
;       <o85.1>      AUTO:     Auto Enable
;       <o85.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR85: Reserved
;       <o86.4>      ENOUT_EN: Enableout Enable
;       <o86.3>      EXTEN_EN: External Enabling Enable
;       <o86.2>      WAKE_EN:  Wakeup Enable
;       <o86.1>      AUTO:     Auto Enable
;       <o86.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR86: Reserved
;       <o87.4>      ENOUT_EN: Enableout Enable
;       <o87.3>      EXTEN_EN: External Enabling Enable
;       <o87.2>      WAKE_EN:  Wakeup Enable
;       <o87.1>      AUTO:     Auto Enable
;       <o87.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR87: Power Control Register for I2SRX_BCK0
;       <o88.4>      ENOUT_EN: Enableout Enable
;       <o88.3>      EXTEN_EN: External Enabling Enable
;       <o88.2>      WAKE_EN:  Wakeup Enable
;       <o88.1>      AUTO:     Auto Enable
;       <o88.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR88: Power Control Register for I2SRX_BCK1
;       <o89.4>      ENOUT_EN: Enableout Enable
;       <o89.3>      EXTEN_EN: External Enabling Enable
;       <o89.2>      WAKE_EN:  Wakeup Enable
;       <o89.1>      AUTO:     Auto Enable
;       <o89.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR89: Power Control Register for SPI_CLK
;       <o90.4>      ENOUT_EN: Enableout Enable
;       <o90.3>      EXTEN_EN: External Enabling Enable
;       <o90.2>      WAKE_EN:  Wakeup Enable
;       <o90.1>      AUTO:     Auto Enable
;       <o90.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR90: Power Control Register for SPI_CLK_GATED
;       <o91.4>      ENOUT_EN: Enableout Enable
;       <o91.3>      EXTEN_EN: External Enabling Enable
;       <o91.2>      WAKE_EN:  Wakeup Enable
;       <o91.1>      AUTO:     Auto Enable
;       <o91.0>      RUN:      Clock Enabled and Running
;     </h>
;     <h> PCR91: Power Control Register for SYSCLK_O
;       <o92.4>      ENOUT_EN: Enableout Enable
;       <o92.3>      EXTEN_EN: External Enabling Enable
;       <o92.2>      WAKE_EN:  Wakeup Enable
;       <o92.1>      AUTO:     Auto Enable
;       <o92.0>      RUN:      Clock Enabled and Running
;     </h>
;   </e>
PCR_SETUP       EQU     1
PCR0_Val        EQU     0x00000007      ; 0x00000007
PCR1_Val        EQU     0x00000007      ; 0x00000007
PCR2_Val        EQU     0x00000007      ; 0x00000007
PCR3_Val        EQU     0x00000007      ; 0x00000007
PCR4_Val        EQU     0x00000007      ; 0x00000007
PCR5_Val        EQU     0x00000007      ; 0x00000007
PCR6_Val        EQU     0x00000007      ; 0x00000007
PCR7_Val        EQU     0x00000007      ; 0x00000007
PCR8_Val        EQU     0x00000006      ; 0x00000007
PCR9_Val        EQU     0x0000000E      ; 0x00000007
PCR10_Val       EQU     0x00000007      ; 0x00000007
PCR11_Val       EQU     0x00000007      ; 0x00000007
PCR12_Val       EQU     0x00000000      ; 0x00000007
PCR13_Val       EQU     0x00000007      ; 0x00000007
PCR14_Val       EQU     0x00000007      ; 0x00000007
PCR15_Val       EQU     0x00000007      ; 0x00000007
PCR16_Val       EQU     0x00000007      ; 0x00000007
PCR17_Val       EQU     0x00000017      ; 0x00000007
PCR18_Val       EQU     0x00000007      ; 0x00000007
PCR19_Val       EQU     0x00000007      ; 0x00000007
PCR20_Val       EQU     0x00000007      ; 0x00000007
PCR21_Val       EQU     0x00000006      ; 0x00000007
PCR22_Val       EQU     0x00000007      ; 0x00000007
PCR23_Val       EQU     0x00000006      ; 0x00000007
PCR24_Val       EQU     0x00000007      ; 0x00000007
PCR25_Val       EQU     0x00000007      ; 0x00000007
PCR26_Val       EQU     0x00000017      ; 0x00000007
PCR27_Val       EQU     0x00000007      ; 0x00000007
PCR28_Val       EQU     0x00000007      ; 0x00000007
PCR29_Val       EQU     0x00000007      ; 0x00000007
PCR30_Val       EQU     0x00000007      ; 0x00000007
PCR31_Val       EQU     0x0000000E      ; 0x00000007
PCR32_Val       EQU     0x0000000E      ; 0x00000007
PCR33_Val       EQU     0x00000006      ; 0x00000007
PCR34_Val       EQU     0x00000006      ; 0x00000007
PCR35_Val       EQU     0x0000000F      ; 0x00000007
PCR36_Val       EQU     0x0000000F      ; 0x00000007
PCR37_Val       EQU     0x0000000F      ; 0x00000007
PCR38_Val       EQU     0x0000000F      ; 0x00000007
PCR39_Val       EQU     0x00000006      ; 0x00000007
PCR40_Val       EQU     0x00000007      ; 0x00000007
PCR41_Val       EQU     0x00000007      ; 0x00000007
PCR42_Val       EQU     0x00000007      ; 0x00000007
PCR43_Val       EQU     0x00000006      ; 0x00000007
PCR44_Val       EQU     0x00000006      ; 0x00000007
PCR45_Val       EQU     0x00000006      ; 0x00000007
PCR46_Val       EQU     0x0000000E      ; 0x00000007
PCR47_Val       EQU     0x00000006      ; 0x00000007
PCR48_Val       EQU     0x00000006      ; 0x00000007
PCR49_Val       EQU     0x00000000      ; 0x00000007
PCR50_Val       EQU     0x00000007      ; 0x00000007
PCR51_Val       EQU     0x00000006      ; 0x00000007
PCR52_Val       EQU     0x0000000E      ; 0x00000007
PCR53_Val       EQU     0x00000007      ; 0x00000007
PCR54_Val       EQU     0x00000006      ; 0x00000007
PCR55_Val       EQU     0x00000006      ; 0x00000007
PCR56_Val       EQU     0x00000006      ; 0x00000007
PCR57_Val       EQU     0x0000000E      ; 0x00000007
PCR58_Val       EQU     0x00000007      ; 0x00000007
PCR59_Val       EQU     0x00000006      ; 0x00000007
PCR60_Val       EQU     0x00000007      ; 0x00000007
PCR61_Val       EQU     0x00000006      ; 0x00000007
PCR62_Val       EQU     0x00000006      ; 0x00000007
PCR63_Val       EQU     0x00000006      ; 0x00000007
PCR64_Val       EQU     0x00000006      ; 0x00000007
PCR65_Val       EQU     0x00000006      ; 0x00000007
PCR66_Val       EQU     0x00000006      ; 0x00000007
PCR67_Val       EQU     0x00000006      ; 0x00000007
PCR68_Val       EQU     0x00000006      ; 0x00000007
PCR69_Val       EQU     0x00000006      ; 0x00000007
PCR70_Val       EQU     0x00000006      ; 0x00000007
PCR71_Val       EQU     0x0000000E      ; 0x00000007
PCR72_Val       EQU     0x00000007      ; 0x00000007
PCR73_Val       EQU     0x00000006      ; 0x00000007
PCR74_Val       EQU     0x00000006      ; 0x00000007
PCR75_Val       EQU     0x00000006      ; 0x00000007
PCR76_Val       EQU     0x00000006      ; 0x00000007
PCR77_Val       EQU     0x00000006      ; 0x00000007
PCR78_Val       EQU     0x00000006      ; 0x00000007
PCR79_Val       EQU     0x00000006      ; 0x00000007
PCR80_Val       EQU     0x00000006      ; 0x00000007
PCR81_Val       EQU     0x00000006      ; 0x00000007
PCR82_Val       EQU     0x00000006      ; 0x00000007
PCR83_Val       EQU     0x00000006      ; 0x00000007
PCR84_Val       EQU     0x00000006      ; 0x00000007
PCR85_Val       EQU     0x00000006      ; 0x00000007
PCR86_Val       EQU     0x00000006      ; 0x00000007
PCR87_Val       EQU     0x00000006      ; 0x00000007
PCR88_Val       EQU     0x00000006      ; 0x00000007
PCR89_Val       EQU     0x00000006      ; 0x00000007
PCR90_Val       EQU     0x0000000E      ; 0x00000007
PCR91_Val       EQU     0x00000006      ; 0x00000007

;   <e> Frequency Select Switch 2 Setup
;     <o1.0..2>  FS2_0: Frequency Switch for SYS Base
;                       <0=> ffast (12 MHz)
;                       <1=> I2SRX_BCK0
;                       <2=> I2SRX_WS0
;                       <3=> I2SRX_BCK1
;                       <4=> I2SRX_WS1
;                       <5=> HP0PLL (Audio/I2S PLL)
;                       <6=> HP1PLL (System PLL)
;                       <7=> Reserved
;     <o2.0..2>  FS2_1: Frequency Switch for AHB0_APB0 Base
;                       <0=> ffast (12 MHz)
;                       <1=> I2SRX_BCK0
;                       <2=> I2SRX_WS0
;                       <3=> I2SRX_BCK1
;                       <4=> I2SRX_WS1
;                       <5=> HP0PLL (Audio/I2S PLL)
;                       <6=> HP1PLL (System PLL)
;                       <7=> Reserved
;     <o3.0..2>  FS2_2: Frequency Switch for AHB0_APB1 Base
;                       <0=> ffast (12 MHz)
;                       <1=> I2SRX_BCK0
;                       <2=> I2SRX_WS0
;                       <3=> I2SRX_BCK1
;                       <4=> I2SRX_WS1
;                       <5=> HP0PLL (Audio/I2S PLL)
;                       <6=> HP1PLL (System PLL)
;                       <7=> Reserved
;     <o4.0..2>  FS2_3: Frequency Switch for AHB0_APB2 Base
;                       <0=> ffast (12 MHz)
;                       <1=> I2SRX_BCK0
;                       <2=> I2SRX_WS0
;                       <3=> I2SRX_BCK1
;                       <4=> I2SRX_WS1
;                       <5=> HP0PLL (Audio/I2S PLL)
;                       <6=> HP1PLL (System PLL)
;                       <7=> Reserved
;     <o5.0..2>  FS2_4: Frequency Switch for AHB0_APB3 Base
;                       <0=> ffast (12 MHz)
;                       <1=> I2SRX_BCK0
;                       <2=> I2SRX_WS0
;                       <3=> I2SRX_BCK1
;                       <4=> I2SRX_WS1
;                       <5=> HP0PLL (Audio/I2S PLL)
;                       <6=> HP1PLL (System PLL)
;                       <7=> Reserved
;     <o6.0..2>  FS2_5: Frequency Switch for PCM Base
;                       <0=> ffast (12 MHz)
;                       <1=> I2SRX_BCK0
;                       <2=> I2SRX_WS0
;                       <3=> I2SRX_BCK1
;                       <4=> I2SRX_WS1
;                       <5=> HP0PLL (Audio/I2S PLL)
;                       <6=> HP1PLL (System PLL)
;                       <7=> Reserved
;     <o7.0..2>  FS2_6: Frequency Switch for UART Base
;                       <0=> ffast (12 MHz)
;                       <1=> I2SRX_BCK0
;                       <2=> I2SRX_WS0
;                       <3=> I2SRX_BCK1
;                       <4=> I2SRX_WS1
;                       <5=> HP0PLL (Audio/I2S PLL)
;                       <6=> HP1PLL (System PLL)
;                       <7=> Reserved
;     <o8.0..2>  FS2_7: Frequency Switch for CLK1024FS Base
;                       <0=> ffast (12 MHz)
;                       <1=> I2SRX_BCK0
;                       <2=> I2SRX_WS0
;                       <3=> I2SRX_BCK1
;                       <4=> I2SRX_WS1
;                       <5=> HP0PLL (Audio/I2S PLL)
;                       <6=> HP1PLL (System PLL)
;                       <7=> Reserved
;     <o9.0..2>  FS2_8: Frequency Switch for I2SRX_BCK0 Base
;                       <0=> ffast (12 MHz)
;                       <1=> I2SRX_BCK0
;                       <2=> I2SRX_WS0
;                       <3=> I2SRX_BCK1
;                       <4=> I2SRX_WS1
;                       <5=> HP0PLL (Audio/I2S PLL)
;                       <6=> HP1PLL (System PLL)
;                       <7=> Reserved
;     <o10.0..2> FS2_9: Frequency Switch for I2SRX_BCK1 Base
;                       <0=> ffast (12 MHz)
;                       <1=> I2SRX_BCK0
;                       <2=> I2SRX_WS0
;                       <3=> I2SRX_BCK1
;                       <4=> I2SRX_WS1
;                       <5=> HP0PLL (Audio/I2S PLL)
;                       <6=> HP1PLL (System PLL)
;                       <7=> Reserved
;     <o11.0..2> FS2_10: Frequency Switch for SPI_CLK Base
;                       <0=> ffast (12 MHz)
;                       <1=> I2SRX_BCK0
;                       <2=> I2SRX_WS0
;                       <3=> I2SRX_BCK1
;                       <4=> I2SRX_WS1
;                       <5=> HP0PLL (Audio/I2S PLL)
;                       <6=> HP1PLL (System PLL)
;                       <7=> Reserved
;     <o12.0..2> FS2_11: Frequency Switch for SYSCLK_O Base
;                       <0=> ffast (12 MHz)
;                       <1=> I2SRX_BCK0
;                       <2=> I2SRX_WS0
;                       <3=> I2SRX_BCK1
;                       <4=> I2SRX_WS1
;                       <5=> HP0PLL (Audio/I2S PLL)
;                       <6=> HP1PLL (System PLL)
;                       <7=> Reserved
;   </e>
FS2_SETUP       EQU     1
FS2_0_Val       EQU     0x00000006      ; 0x00000000
FS2_1_Val       EQU     0x00000000      ; 0x00000000
FS2_2_Val       EQU     0x00000000      ; 0x00000000
FS2_3_Val       EQU     0x00000006      ; 0x00000000
FS2_4_Val       EQU     0x00000000      ; 0x00000000
FS2_5_Val       EQU     0x00000006      ; 0x00000000
FS2_6_Val       EQU     0x00000000      ; 0x00000000
FS2_7_Val       EQU     0x00000005      ; 0x00000000
FS2_8_Val       EQU     0x00000001      ; 0x00000000
FS2_9_Val       EQU     0x00000003      ; 0x00000000
FS2_10_Val      EQU     0x00000006      ; 0x00000000
FS2_11_Val      EQU     0x00000000      ; 0x00000000

; </e>

;----------------------- MPMC Definitions --------------------------------------

; Multi-Port Memory Controller (MPMC)
MPMC_BASE             EQU   0x17008000  ; MPMC Base Address
                                        ; MPMC Registers Offsets
MPMCControl_OFS       EQU   0x00        ; Control
MPMCStatus_OFS        EQU   0x04        ; Status
MPMCConfig_OFS        EQU   0x08        ; Configuration
MPMCDynControl_OFS    EQU   0x20        ; Dynamic Memory Control
MPMCDynRefresh_OFS    EQU   0x24        ; Dynamic Memory Refresh Timer
MPMCDynReadCfg_OFS    EQU   0x28        ; Dynamic Memory Read Configuration
MPMCDynRP_OFS         EQU   0x30        ; Dynamic Memory Precharge Command Period
MPMCDynRAS_OFS        EQU   0x34        ; Dynamic Memory Active to Precharge Period
MPMCDynSREX_OFS       EQU   0x38        ; Dynamic Memory Self-refresh Exit Time
MPMCDynAPR_OFS        EQU   0x3C        ; Dynamic Memory Last Data Out to Active Time
MPMCDynDAL_OFS        EQU   0x40        ; Dynamic Memory Data-in to Active Command Time
MPMCDynWR_OFS         EQU   0x44        ; Dynamic Memory Write Recovery Time
MPMCDynRC_OFS         EQU   0x48        ; Dynamic Memory Active to Active Command Period
MPMCDynRFC_OFS        EQU   0x4C        ; Dynamic Memory Auto-refresh Period
MPMCDynXSR_OFS        EQU   0x50        ; Dynamic Memory Exit Self-refresh
MPMCDynRRD_OFS        EQU   0x54        ; Dynamic Memory Active Bank A to Active Bank B Time
MPMCDynMRD_OFS        EQU   0x58        ; Dynamic Memory Load Mode to Active Command Time
MPMCStaExtWait_OFS    EQU   0x80        ; Static Memory Extended Wait
MPMCDynConfig0_OFS    EQU   0x100       ; Dynamic Memory Configuration 0
MPMCDynRasCas0_OFS    EQU   0x104       ; Dynamic Memory RAS and CAS Delay 0
MPMCStaConfig0_OFS    EQU   0x200       ; Static Memory Configuration 0
MPMCStaWaitWen0_OFS   EQU   0x204       ; Static Memory Write Enable Delay 0
MPMCStaWaitOen0_OFS   EQU   0x208       ; Static Memory Output Enable Delay 0
MPMCStaWaitRd0_OFS    EQU   0x20C       ; Static Memory Read Delay 0
MPMCStaWaitPage0_OFS  EQU   0x210       ; Static Memory Page Mode Read Delay 0
MPMCStaWaitWr0_OFS    EQU   0x214       ; Static Memory Write Delay 0
MPMCStaWaitTurn0_OFS  EQU   0x218       ; Static Memory Turn Round Delay 0
MPMCStaConfig1_OFS    EQU   0x220       ; Static Memory Configuration 1
MPMCStaWaitWen1_OFS   EQU   0x224       ; Static Memory Write Enable Delay 1
MPMCStaWaitOen1_OFS   EQU   0x228       ; Static Memory Output Enable Delay 1
MPMCStaWaitRd1_OFS    EQU   0x22C       ; Static Memory Read Delay 1
MPMCStaWaitPage1_OFS  EQU   0x230       ; Static Memory Page Mode Read Delay 1
MPMCStaWaitWr1_OFS    EQU   0x234       ; Static Memory Write Delay 1
MPMCStaWaitTurn1_OFS  EQU   0x238       ; Static Memory Turn Round Delay 1

SDRAM0_MODE_REG       EQU   (0x23<< 13) ; SDRAM0 Mode Register     Address

; Constants
NORMAL_CMD            EQU   (0x0 <<  7) ; NORMAL        Command
MODE_CMD              EQU   (0x1 <<  7) ; MODE          Command
PALL_CMD              EQU   (0x2 <<  7) ; Precharge All Command
NOP_CMD               EQU   (0x3 <<  7) ; NOP           Command
REFSH_MODE            EQU   (0x1 <<  2) ; Self-refresh mode

B_BIT                 EQU   (0x1 << 19) ; Self-refresh mode

; <e> Multi-port Memory Controller Setup (MPMC)
MPMC_SETUP            EQU   1

;   <h> MPMC Control Register (MPMCControl)
;     <i> Controls operation of the memory controller
;     <o0.2> L: Low-power mode enable
;     <o0.1> M: Memory map
;       <0=> Normal memory map
;       <1=> Reset memory map
;     <o0.0> E: Controller enable
;   </h>
MPMCControl_Val       EQU   0x00000001  ; 0x00000003

;   <h> MPMC Configuration Register (MPMCConfig)
;     <i> Configures operation of the memory controller
;     <o0.8> CLK: Clock ratio (HCLK/MPMCCLKOUT ratio)
;       <0=> 1:1
;       <1=> 1:2
;     <o0.0> N: Endian mode
;       <0=> Little-endian
;       <1=> Big-endian
;   </h>
MPMCConfig_Val        EQU   0x00000000  ; 0x00000000

;   <e> Dynamic Memory Interface Setup
MPMC_DYNAMIC_SETUP    EQU   1

;     <h> MPMC Dynamic Control Register (MPMCDynamicControl)
;       <o0.13> DP: Low-power SDRAM deep-sleep mode
;                   <0=> Normal operation
;                   <1=> Enter deep power down mode
;       <o0.5> MMC: Memory clock control
;                   <0=> MPMCCLKOUT enabled
;                   <1=> MPMCCLKOUT disabled
;       <o0.1> CS: Dynamic memory clock control
;                   <0=> MPMCCLKOUT stops when all SDRAMs are idle
;                   <1=> MPMCCLKOUT runs continuously
;       <o0.0> CE: Dynamic memory clock enable
;                   <0=> Clock enable of idle devices are deasserted
;                   <1=> All clock enables are driven high continuously
;     </h>
MPMCDynControl_Val    EQU   0x00000003  ; 0x00000000

;     <h> Dynamic Memory Refresh Timer Register (MPMCDynamicRefresh)
;       <i> Configures dynamic memory refresh operation
;       <o0.0..10> REFRESH: Refresh timer <0x000-0x7FF>
;         <i> 0 = refresh disabled, 0x01-0x7FF: value * 16 HCLKs
;     </h>
MPMCDynRefresh_Val    EQU   0x0000002B  ; 0x00000000

;     <h> Dynamic Memory Read Configuration Register (MPMCDynamicReadConfig)
;       <i> Configures the dynamic memory read strategy
;       <o0.0..1> RD: Read data strategy
;         <0=> Clock out delayed strategy
;         <1=> Command delayed strategy
;         <2=> Command delayed strategy plus one clock cycle
;         <3=> Command delayed strategy plus two clock cycles
;     </h>
MPMCDynReadCfg_Val    EQU   0x00000001  ; 0x00000000

;     <h> Dynamic Memory Timings
;       <i> All delays are in clock cycles
;       <h> Dynamic Memory Precharge Command Period Register (MPMCDynamictRP)
;         <o0.0..3> tRP: Precharge command period <1-16> <#-1>
;           <i> This value is normally found in SDRAM data sheets as tRP
;       </h>
;       <h> Dynamic Memory Active to Precharge Command Period Register (MPMCDynamictRAS)
;         <o1.0..3> tRAS: Active to precharge command period <1-16> <#-1>
;           <i> This value is normally found in SDRAM data sheets as tRAS
;       </h>
;       <h> Dynamic Memory Self-refresh Exit Time Register (MPMCDynamictSREX)
;         <o2.0..3> tSREX: Self-refresh exit time <1-16> <#-1>
;           <i> This value is normally found in SDRAM data sheets as tSREX 
;           <i> for devices without this parameter you use the same value as tXSR
;       </h>
;       <h> Dynamic Memory Last-data-out to ActiveCommand Time Register (MPMCDynamictAPR)
;         <o3.0..3> tAPR: Last-data-out to active command time <1-16> <#-1>
;           <i> This value is normally found in SDRAM data sheets as tAPR 
;       </h>
;       <h> Dynamic Memory Data-in to Active Command Time Register (MPMCDynamictDAL)
;         <o4.0..3> tDAL: Data-in to active command time <1-16> <#-1>
;           <i> This value is normally found in SDRAM data sheets as tDAL or tAPW
;       </h>
;       <h> Dynamic Memory Write Recovery Time Register (MPMCDynamictWR)
;         <o5.0..3> tWR: Write recovery time <1-16> <#-1>
;           <i> This value is normally found in SDRAM data sheets as tWR, tDPL, tRWL, or tRDL
;       </h>
;       <h> Dynamic Memory Active to Active Command Period Register (MPMCDynamictRC)
;         <o6.0..4> tRC: Active to active command period <1-32> <#-1>
;           <i> This value is normally found in SDRAM data sheets as tRC
;       </h>
;       <h> Dynamic Memory Auto-refresh Period Register (MPMCDynamictRFC)
;         <o7.0..4> tRFC: Auto-refresh period and auto-refresh to active command period <1-32> <#-1>
;           <i> This value is normally found in SDRAM data sheets as tRFC or tRC
;       </h>
;       <h> Dynamic Memory Exit Self-refresh Register (MPMCDynamictXSR)
;         <o8.0..4> tXSR: Exit self-refresh to active command time <1-32> <#-1>
;           <i> This value is normally found in SDRAM data sheets as tXSR
;       </h>
;       <h> Dynamic Memory Active Bank A to Active Bank B Time Register (MPMCDynamicRRD)
;         <o9.0..3> tRRD: Active bank A to active bank B latency <1-16> <#-1>
;           <i> This value is normally found in SDRAM data sheets as tRRD
;       </h>
;       <h> Dynamic Memory Load Mode Register to Active Command Time (MPMCDynamictMRD)
;         <o10.0..3> tMRD: Load mode register to active command time <1-16> <#-1>
;           <i> This value is normally found in SDRAM data sheets as tMRD or tRSA
;       </h>
;     </h>
MPMCDynRP_Val         EQU   0x00000002  ; 0x0000000F
MPMCDynRAS_Val        EQU   0x00000004  ; 0x0000000F
MPMCDynSREX_Val       EQU   0x00000007  ; 0x0000000F
MPMCDynAPR_Val        EQU   0x00000004  ; 0x0000000F
MPMCDynDAL_Val        EQU   0x00000005  ; 0x0000000F
MPMCDynWR_Val         EQU   0x00000007  ; 0x0000000F
MPMCDynRC_Val         EQU   0x00000006  ; 0x0000001F
MPMCDynRFC_Val        EQU   0x00000006  ; 0x0000001F
MPMCDynXSR_Val        EQU   0x00000007  ; 0x0000001F
MPMCDynRRD_Val        EQU   0x00000001  ; 0x0000000F
MPMCDynMRD_Val        EQU   0x00000002  ; 0x0000000F

;     <e> Configure External Bus Behaviour for Dynamic CS0 Area
MPMC_DYNCS0_SETUP     EQU   1

;       <h> Dynamic Memory Configuration Register (MPMCDynamicConfig0)
;         <i> Defines the configuration information for the dynamic memory CS0
;         <o0.20> P: Write protect enable
;         <o0.14> AM 14: External bus data width
;           <0=> 16 bit
;         <o0.12> AM 12: External bus memory type
;           <0=> High-performance
;           <1=> Low-power SDRAM
;         <o0.7..11> AM 11..7: External bus address mapping (Row, Bank, Column)
;           <0x00=> 16 Mb = 2MB (2Mx8), 2 banks, row length = 11, column length = 9
;           <0x01=> 16 Mb = 2MB (1Mx16), 2 banks, row length = 11, column length = 8
;           <0x04=> 64 Mb = 8MB (8Mx8), 4 banks, row length = 12, column length = 9
;           <0x05=> 64 Mb = 8MB (4Mx16), 4 banks, row length = 12, column length = 8
;           <0x08=> 128 Mb = 16MB (16Mx8), 4 banks, row length = 12, column length = 10
;           <0x09=> 128 Mb = 16MB (8Mx16), 4 banks, row length = 12, column length = 9
;           <0x0C=> 256 Mb = 32MB (32Mx8), 4 banks, row length = 13, column length = 10
;           <0x0D=> 256 Mb = 32MB (16Mx16), 4 banks, row length = 13, column length = 9
;           <0x10=> 512 Mb = 64MB (64Mx8), 4 banks, row length = 13, column length = 11
;           <0x11=> 512 Mb = 64MB (32Mx16), 4 banks, row length = 13, column length = 10
;         <o0.3..4> MD: Memory device
;           <0=> SDRAM
;           <1=> Low-power SDRAM
;           <2=> Micron SyncFlash
;           <3=> Reserved
;       </h>
MPMCDynConfig0_Val    EQU   0x00000880  ; 0x00000000

;       <h> Dynamic Memory RAS & CAS Delay register (MPMCDynamicRASCAS0)
;         <i> Controls the RAS and CAS latencies for the dynamic memory CS0
;         <o0.8..9> CAS: CAS latency (in clock cycles) <1-3>
;         <o0.0..1> RAS: RAS latency (active to read/write delay, in clock cycles) <1-3>
;       </h>
MPMCDynRasCas0_Val    EQU   0x00000202  ; 0x00000303

;     </e> End of Dynamic Setup for CS0 Area
;   </e> End of Dynamic Setup

;   <e> Static Memory Interface Setup
MPMC_STATIC_SETUP     EQU   0

;     <e> Configure External Bus Behaviour for Static CS0 Area
;       <h> Static Memory Configuration Register (MPMCStaticConfig0)
;         <i> Defines the configuration information for the static memory CS0
;         <o1.20> WP: Write protect enable
;         <o1.8> EW: Extended wait enable
;         <o1.7> BLS: Byte lane state
;           <0=> For reads BLSn are HIGH | for writes BLSn are LOW
;           <1=> For reads BLSn are LOW  | for writes BLSn are LOW
;         <o1.6> PC: Chip select polarity
;           <0=> Active LOW chip select
;           <1=> Active HIGH chip select
;         <o1.3> PM: Page mode enable
;         <o1.0> MW: Memory width
;           <0=> 8 bit
;           <1=> 16 bit
;       </h>
;       <h> Static Memory Write Enable Delay Register (MPMCStaticWaitWen0)
;         <i> Selects the delay from CS0 to write enable
;         <o2.0..3> WAITWEN: Wait write enable <1-16> <#-1>
;           <i> The delay is in HCLK cycles
;       </h>
;       <h> Static Memory Output Enable Delay Register (MPMCStaticWaitOen0)
;         <i> Selects the delay from CS0 or address change, whichever is later, to output enable
;         <o3.0..3> WAITOEN: Wait output enable <0-15>
;           <i> The delay is in HCLK cycles
;       </h>
;       <h> Static Memory Read Delay Register (MPMCStaticWaitRd0)
;         <i> Selects the delay from CS0 to a read access
;         <o4.0..4> WAITRD: Non-page mode read wait states or asynchronous page mode read first access wait states <1-32> <#-1>
;           <i> The delay is in HCLK cycles
;       </h>
;       <h> Static Memory Page Mode Read Delay Register (MPMCStaticWaitPage0)
;         <i> Selects the delay for asynchronous page mode sequential accesses for CS0
;         <o5.0..4> WAITPAGE: Asynchronous page mode read after the first read wait states <1-32> <#-1>
;           <i> The delay is in HCLK cycles
;       </h>
;       <h> Static Memory Write Delay Register (MPMCStaticWaitWr0)
;         <i> Selects the delay from CS0 to a write access
;         <o6.0..4> WAITWR: Write wait states <2-33> <#-2>
;           <i> The delay is in HCLK cycles
;       </h>
;       <h> Static Memory Turn Round Delay Register (MPMCStaticWaitTurn0)
;         <i> Selects the number of bus turnaround cycles for CS0
;         <o7.0..4> WAITTURN: Bus turnaround cycles <1-16> <#-1>
;           <i> The delay is in HCLK cycles
;       </h>
;     </e> End of Static Setup for Static CS0 Area
MPMC_STACS0_SETUP     EQU   0
MPMCStaConfig0_Val    EQU   0x00000000  ; 0x00000000
MPMCStaWaitWen0_Val   EQU   0x00000000  ; 0x00000000
MPMCStaWaitOen0_Val   EQU   0x00000000  ; 0x00000000
MPMCStaWaitRd0_Val    EQU   0x0000001F  ; 0x0000001F
MPMCStaWaitPage0_Val  EQU   0x0000001F  ; 0x0000001F
MPMCStaWaitWr0_Val    EQU   0x0000001F  ; 0x0000001F
MPMCStaWaitTurn0_Val  EQU   0x0000000F  ; 0x0000000F

;     <e> Configure External Bus Behaviour for Static CS1 Area
;       <h> Static Memory Configuration Register (MPMCStaticConfig1)
;         <i> Defines the configuration information for the static memory CS1
;         <o1.20> WP: Write protect enable
;         <o1.8> EW: Extended wait enable
;         <o1.7> BLS: Byte lane state
;           <0=> For reads BLSn are HIGH | for writes BLSn are LOW
;           <1=> For reads BLSn are LOW  | for writes BLSn are LOW
;         <o1.6> PC: Chip select polarity
;           <0=> Active LOW chip select
;           <1=> Active HIGH chip select
;         <o1.3> PM: Page mode enable
;         <o1.0> MW: Memory width
;           <0=> 8 bit
;           <1=> 16 bit
;       </h>
;       <h> Static Memory Write Enable Delay Register (MPMCStaticWaitWen1)
;         <i> Selects the delay from CS1 to write enable
;         <o2.0..3> WAITWEN: Wait write enable <1-16> <#-1>
;           <i> The delay is in HCLK cycles
;       </h>
;       <h> Static Memory Output Enable Delay Register (MPMCStaticWaitOen1)
;         <i> Selects the delay from CS1 or address change, whichever is later, to output enable
;         <o3.0..3> WAITOEN: Wait output enable <0-15>
;           <i> The delay is in HCLK cycles
;       </h>
;       <h> Static Memory Read Delay Register (MPMCStaticWaitRd1)
;         <i> Selects the delay from CS1 to a read access
;         <o4.0..4> WAITRD: Non-page mode read wait states or asynchronous page mode read first access wait states <1-32> <#-1>
;           <i> The delay is in HCLK cycles
;       </h>
;       <h> Static Memory Page Mode Read Delay Register (MPMCStaticWaitPage1)
;         <i> Selects the delay for asynchronous page mode sequential accesses for CS1
;         <o5.0..4> WAITPAGE: Asynchronous page mode read after the first read wait states <1-32> <#-1>
;           <i> The delay is in HCLK cycles
;       </h>
;       <h> Static Memory Write Delay Register (MPMCStaticWaitWr1)
;         <i> Selects the delay from CS1 to a write access
;         <o6.0..4> WAITWR: Write wait states <2-33> <#-2>
;           <i> The delay is in HCLK cycles
;       </h>
;       <h> Static Memory Turn Round Delay Register (MPMCStaticWaitTurn1)
;         <i> Selects the number of bus turnaround cycles for CS1
;         <o7.0..4> WAITTURN: Bus turnaround cycles <1-16> <#-1>
;           <i> The delay is in HCLK cycles
;       </h>
;     </e> End of Static Setup for Static CS1 Area
MPMC_STACS1_SETUP     EQU   0
MPMCStaConfig1_Val    EQU   0x00000000  ; 0x00000000
MPMCStaWaitWen1_Val   EQU   0x00000000  ; 0x00000000
MPMCStaWaitOen1_Val   EQU   0x00000000  ; 0x00000000
MPMCStaWaitRd1_Val    EQU   0x0000001F  ; 0x0000001F
MPMCStaWaitPage1_Val  EQU   0x0000001F  ; 0x0000001F
MPMCStaWaitWr1_Val    EQU   0x0000001F  ; 0x0000001F
MPMCStaWaitTurn1_Val  EQU   0x0000000F  ; 0x0000000F

;     <h> Static Memory Extended Wait Register (MPMCStaticExtendedWait)
;       <i> Time long static memory read and write transfers
;       <o.0..9> EXTENDEDWAIT: Extended wait time out <0-1023>
;         <i> The delay is in (16 * cycles)
;     </h>
MPMCStaExtWait_Val    EQU   0x00000000  ; 0x00000000

;   </e> End of Static Setup
; </e> End of MPMC Setup


;----------------------- System Controller Definitions -------------------------

; System Controller
SC_BASE         EQU     0x13002800      ; System Control Base Address
SC_MPMP_DM_OFS  EQU     0x68            ; Static Memory Delay Mode Register Ofs
SC_ARM926_S_OFS EQU     0x84            ; Shadow Pointer Register Address Offset
SC_MUX_LCD_OFS  EQU     0x90            ; LCD or EBI Pin Select Register Adr Ofs

; <e> Shadow Memory Setup
;   <o1> Address of memory that will be shadowed at address 0 <0x0-0xFFFFFC00:0x400>
; </e>
SHADOW_SETUP    EQU     1
SC_ARM926_S_Val EQU     0x30000000


;----------------------- Cache Definitions -------------------------------------

; Cache

; Constants
ICACHE_ENABLE   EQU     (1<<12)         ; Instruction Cache Enable Bit

; <e> Instruction Cache Enable
; </e>
ICACHE_SETUP    EQU     0


;----------------------- CODE --------------------------------------------------

                PRESERVE8

                IF      :LNOT::DEF:__EVAL 
                IF      :DEF:SIZE_INT_INFO
                IMPORT  ||Image$$ER_IROM1$$RO$$Length||
                IMPORT  ||Image$$RW_IRAM1$$RW$$Length||
                ELIF    :DEF:SIZE_EXT_INFO
                IMPORT  ||Image$$ER_ROM1$$RO$$Length||
                IMPORT  ||Image$$RW_RAM1$$RW$$Length||
                ENDIF
                ENDIF

; Area Definition for Boot Header

                IF      :DEF:BOOT_HEADER
                AREA    |.ARM.__AT_0x11029000|, CODE, READONLY
                ARM

                LDR     PC, Reset_Addr            ; vector
                DCD     0x41676D69                ; magic
                DCD     0x00000000                ; execution_CRC32
                SPACE   16                        ; Reserved0
                DCD     0x0000000A                ; imageType (No CRC)
                                                  ; imageLength
                DCD     0x2000
                DCD     0x00000000                ; releaseID
                DCD     0x00000000                ; buildTime
                DCD     0x00000000                ; sbzBootParameter
                SPACE   60                        ; cust_reserved
                DCD     0x00000000                ; header_crc32
                SPACE   16                        ; Reserved1
                ENDIF

; Area Definition and Entry Point
;  Startup Code must be linked first at Address at which it expects to run.

                AREA    RESET, CODE, READONLY
                ARM

                IF      :DEF:__RTX
                IMPORT  SWI_Handler
                ENDIF

; Exception Vectors
;  Mapped to Address 0.
;  Absolute addressing mode must be used.
;  Dummy Handlers are implemented as infinite loops which can be modified.

Vectors         LDR     PC, Reset_Addr         
                LDR     PC, Undef_Addr
                LDR     PC, SWI_Addr
                LDR     PC, PAbt_Addr
                LDR     PC, DAbt_Addr
                ; Reserved vector is used for image size information
                IF      :DEF:__EVAL
                  DCD   0x8000
                ELSE 
                  IF    :DEF:SIZE_INT_INFO
                    DCD ||Image$$ER_IROM1$$RO$$Length||+\
                        ||Image$$RW_IRAM1$$RW$$Length||
                  ELIF  :DEF:SIZE_EXT_INFO
                    DCD ||Image$$ER_ROM1$$RO$$Length||+\
                        ||Image$$RW_RAM1$$RW$$Length||
                  ELSE
                    NOP
                  ENDIF
                ENDIF
                LDR     PC, IRQ_Addr
                LDR     PC, FIQ_Addr

Reset_Addr      DCD     Reset_Handler
Undef_Addr      DCD     Undef_Handler
SWI_Addr        DCD     SWI_Handler
PAbt_Addr       DCD     PAbt_Handler
DAbt_Addr       DCD     DAbt_Handler
                DCD     0                         ; Reserved Address 
IRQ_Addr        DCD     IRQ_Handler
FIQ_Addr        DCD     FIQ_Handler

Undef_Handler   B       Undef_Handler
                IF      :LNOT::DEF:__RTX
SWI_Handler     B       SWI_Handler
                ENDIF
PAbt_Handler    B       PAbt_Handler
DAbt_Handler    B       DAbt_Handler
IRQ_Handler     PROC
                EXPORT  IRQ_Handler               [WEAK]
                B       .
                ENDP
FIQ_Handler     PROC
                EXPORT  FIQ_Handler               [WEAK]
                B       .
                ENDP



; Reset Handler

                EXPORT  Reset_Handler
Reset_Handler   

                ; Macro for writing register
                MACRO
                Wr_Reg  $cs

                LDR     R1, =$cs._Val
                STR     R1, [R0, #$cs._OFS]
                MEND

; Clock Setup ------------------------------------------------------------------

                IF      (:LNOT:(:DEF:NO_CLOCK_INIT)):LAND:(CLOCK_SETUP != 0)
                LDR     R0, =CGU_BASE

                ; Switch all clocks to ffast (12 MHz) to switch 1
                MOV     R1, #0
                MOV     R2, #1
                STR     R1, [R0, #FS1_0_OFS]
                STR     R1, [R0, #FS1_1_OFS]
                STR     R1, [R0, #FS1_2_OFS]
                STR     R1, [R0, #FS1_3_OFS]
                STR     R1, [R0, #FS1_4_OFS]
                STR     R1, [R0, #FS1_5_OFS]
                STR     R1, [R0, #FS1_6_OFS]
                STR     R1, [R0, #FS1_7_OFS]
                STR     R1, [R0, #FS1_8_OFS]
                STR     R1, [R0, #FS1_9_OFS]
                STR     R1, [R0, #FS1_10_OFS]
                STR     R1, [R0, #FS1_11_OFS]
                STR     R2, [R0, #SCR0_OFS]
                STR     R2, [R0, #SCR1_OFS]
                STR     R2, [R0, #SCR2_OFS]
                STR     R2, [R0, #SCR3_OFS]
                STR     R2, [R0, #SCR4_OFS]
                STR     R2, [R0, #SCR5_OFS]
                STR     R2, [R0, #SCR6_OFS]
                STR     R2, [R0, #SCR7_OFS]
                STR     R2, [R0, #SCR8_OFS]
                STR     R2, [R0, #SCR9_OFS]
                STR     R2, [R0, #SCR10_OFS]
                STR     R2, [R0, #SCR11_OFS]

                IF      (FFAST_SETUP != 0)
                STR     R2, [R0, #FFAST_ON_OFS]
                ENDIF

                IF      (HP0PLL_SETUP != 0)       ; Setup PLL0
                MOV     R1, #(1<<2)               ; Disable PLL
                STR     R1, [R0, #HP0_MODE_OFS]
                MOV     R1, #HP0_FIN_SELECT_Val   ; Select input to PLL
                STR     R1, [R0, #HP0_FIN_SELECT_OFS]
                IF      (HP0_MDEC_Val != 0)       ; Setup feedback divider (M)
                LDR     R1, =HP0_MDEC_Val
                STR     R1, [R0, #HP0_MDEC_OFS]
                ENDIF
                IF      (HP0_NDEC_Val != 0)       ; Setup pre-divider (N)
                LDR     R1, =HP0_NDEC_Val
                STR     R1, [R0, #HP0_NDEC_OFS]
                ENDIF
                IF      (HP0_PDEC_Val != 0)       ; Setup post-divider (P)
                MOV     R1, #HP0_PDEC_Val
                STR     R1, [R0, #HP0_PDEC_OFS]
                ENDIF
                MOV     R1, #HP0_SELR_Val         ; Setup selr
                STR     R1, [R0, #HP0_SELR_OFS]
                MOV     R1, #HP0_SELI_Val         ; Setup seli
                STR     R1, [R0, #HP0_SELI_OFS]
                MOV     R1, #HP0_SELP_Val         ; Setup selp
                STR     R1, [R0, #HP0_SELP_OFS]
                MOV     R1, #HP0_MODE_Val         ; Enable PLL and set mode
                STR     R1, [R0, #HP0_MODE_OFS]
PLL0_Loop       LDR     R1, [R0, #HP0_STATUS_OFS] ; Wait until PLL is stabilized
                ANDS    R1, R1, #PLL_LOCK
                BEQ     PLL0_Loop
                ENDIF

                IF      (HP1PLL_SETUP != 0)       ; Setup PLL1
                MOV     R1, #(1<<2)               ; Disable PLL
                STR     R1, [R0, #HP1_MODE_OFS]
                MOV     R1, #HP1_FIN_SELECT_Val   ; Select input to PLL
                STR     R1, [R0, #HP1_FIN_SELECT_OFS]
                IF      (HP1_MDEC_Val != 0)       ; Setup feedback divider (M)
                LDR     R1, =HP1_MDEC_Val
                STR     R1, [R0, #HP1_MDEC_OFS]
                ENDIF
                IF      (HP1_NDEC_Val != 0)       ; Setup pre-divider (N)
                LDR     R1, =HP1_NDEC_Val
                STR     R1, [R0, #HP1_NDEC_OFS]
                ENDIF
                IF      (HP1_PDEC_Val != 0)       ; Setup post-divider (P)
                MOV     R1, #HP1_PDEC_Val
                STR     R1, [R0, #HP1_PDEC_OFS]
                ENDIF
                MOV     R1, #HP1_SELR_Val         ; Setup selr
                STR     R1, [R0, #HP1_SELR_OFS]
                MOV     R1, #HP1_SELI_Val         ; Setup seli
                STR     R1, [R0, #HP1_SELI_OFS]
                MOV     R1, #HP1_SELP_Val         ; Setup selp
                STR     R1, [R0, #HP1_SELP_OFS]
                MOV     R1, #HP1_MODE_Val         ; Enable PLL and set mode
                STR     R1, [R0, #HP1_MODE_OFS]
PLL1_Loop       LDR     R1, [R0, #HP1_STATUS_OFS] ; Wait until PLL is stabilized
                ANDS    R1, R1, #PLL_LOCK
                BEQ     PLL1_Loop
                ENDIF

                IF      (FDC_SETUP != 0)          ; Reset FDCs
                MOV     R1, #0x02
                STR     R1, [R0, #FDC0_OFS]
                STR     R1, [R0, #FDC1_OFS]
                STR     R1, [R0, #FDC2_OFS]
                STR     R1, [R0, #FDC3_OFS]
                STR     R1, [R0, #FDC4_OFS]
                STR     R1, [R0, #FDC5_OFS]
                STR     R1, [R0, #FDC6_OFS]
                STR     R1, [R0, #FDC7_OFS]
                STR     R1, [R0, #FDC8_OFS]
                STR     R1, [R0, #FDC9_OFS]
                STR     R1, [R0, #FDC10_OFS]
                STR     R1, [R0, #FDC11_OFS]
                STR     R1, [R0, #FDC12_OFS]
                STR     R1, [R0, #FDC13_OFS]
                STR     R1, [R0, #FDC14_OFS]
                STR     R1, [R0, #FDC15_OFS]
                STR     R1, [R0, #FDC16_OFS]
                STR     R1, [R0, #FDC17_OFS]
                STR     R1, [R0, #FDC18_OFS]
                STR     R1, [R0, #FDC19_OFS]
                STR     R1, [R0, #FDC20_OFS]
                STR     R1, [R0, #FDC21_OFS]
                STR     R1, [R0, #FDC22_OFS]
                STR     R1, [R0, #FDC23_OFS]

                ; Setup FDCs but disabled
                LDR     R1, =(FDC0_Val & 0xFFFFFFFE)
                STR     R1, [R0, #FDC0_OFS]       
                LDR     R1, =(FDC1_Val & 0xFFFFFFFE)
                STR     R1, [R0, #FDC1_OFS]       
                LDR     R1, =(FDC2_Val & 0xFFFFFFFE)
                STR     R1, [R0, #FDC2_OFS]       
                LDR     R1, =(FDC3_Val & 0xFFFFFFFE)
                STR     R1, [R0, #FDC3_OFS]       
                LDR     R1, =(FDC4_Val & 0xFFFFFFFE)
                STR     R1, [R0, #FDC4_OFS]       
                LDR     R1, =(FDC5_Val & 0xFFFFFFFE)
                STR     R1, [R0, #FDC5_OFS]       
                LDR     R1, =(FDC6_Val & 0xFFFFFFFE)
                STR     R1, [R0, #FDC6_OFS]       
                LDR     R1, =(FDC7_Val & 0xFFFFFFFE)
                STR     R1, [R0, #FDC7_OFS]       
                LDR     R1, =(FDC8_Val & 0xFFFFFFFE)
                STR     R1, [R0, #FDC8_OFS]       
                LDR     R1, =(FDC9_Val & 0xFFFFFFFE)
                STR     R1, [R0, #FDC9_OFS]       
                LDR     R1, =(FDC10_Val & 0xFFFFFFFE)
                STR     R1, [R0, #FDC10_OFS]       
                LDR     R1, =(FDC11_Val & 0xFFFFFFFE)
                STR     R1, [R0, #FDC11_OFS]       
                LDR     R1, =(FDC12_Val & 0xFFFFFFFE)
                STR     R1, [R0, #FDC12_OFS]       
                LDR     R1, =(FDC13_Val & 0xFFFFFFFE)
                STR     R1, [R0, #FDC13_OFS]       
                LDR     R1, =(FDC14_Val & 0xFFFFFFFE)
                STR     R1, [R0, #FDC14_OFS]       
                LDR     R1, =(FDC15_Val & 0xFFFFFFFE)
                STR     R1, [R0, #FDC15_OFS]       
                LDR     R1, =(FDC16_Val & 0xFFFFFFFE)
                STR     R1, [R0, #FDC16_OFS]       
                LDR     R1, =(FDC17_Val & 0xFFFFFFFE)
                STR     R1, [R0, #FDC17_OFS]       
                LDR     R1, =(FDC18_Val & 0xFFFFFFFE)
                STR     R1, [R0, #FDC18_OFS]       
                LDR     R1, =(FDC19_Val & 0xFFFFFFFE)
                STR     R1, [R0, #FDC19_OFS]       
                LDR     R1, =(FDC20_Val & 0xFFFFFFFE)
                STR     R1, [R0, #FDC20_OFS]       
                LDR     R1, =(FDC21_Val & 0xFFFFFFFE)
                STR     R1, [R0, #FDC21_OFS]       
                LDR     R1, =(FDC22_Val & 0xFFFFFFFE)
                STR     R1, [R0, #FDC22_OFS]       
                LDR     R1, =(FDC23_Val & 0xFFFFFFFE)
                STR     R1, [R0, #FDC23_OFS]       
                ENDIF   ;(FDC_SETUP != 0)

                IF      (ESR_SETUP != 0)          ; Setup ESRs
                Wr_Reg  ESR0 
                Wr_Reg  ESR1 
                Wr_Reg  ESR2 
                Wr_Reg  ESR3 
                Wr_Reg  ESR4 
                Wr_Reg  ESR5 
                Wr_Reg  ESR6 
                Wr_Reg  ESR7 
                Wr_Reg  ESR8 
                Wr_Reg  ESR9 
                Wr_Reg  ESR10
                Wr_Reg  ESR11
                Wr_Reg  ESR12
                Wr_Reg  ESR13
                Wr_Reg  ESR14
                Wr_Reg  ESR15
                Wr_Reg  ESR16
                Wr_Reg  ESR17
                Wr_Reg  ESR18
                Wr_Reg  ESR19
                Wr_Reg  ESR20
                Wr_Reg  ESR21
                Wr_Reg  ESR22
                Wr_Reg  ESR23
                Wr_Reg  ESR24
                Wr_Reg  ESR25
                Wr_Reg  ESR26
                Wr_Reg  ESR27
                Wr_Reg  ESR28
                Wr_Reg  ESR29
                Wr_Reg  ESR30
                Wr_Reg  ESR31
                Wr_Reg  ESR32
                Wr_Reg  ESR33
                Wr_Reg  ESR34
                Wr_Reg  ESR35
                Wr_Reg  ESR36
                Wr_Reg  ESR37
                Wr_Reg  ESR38
                Wr_Reg  ESR39
                Wr_Reg  ESR40
                Wr_Reg  ESR41
                Wr_Reg  ESR42
                Wr_Reg  ESR43
                Wr_Reg  ESR44
                Wr_Reg  ESR45
                Wr_Reg  ESR46
                Wr_Reg  ESR47
                Wr_Reg  ESR48
                Wr_Reg  ESR49
                Wr_Reg  ESR50
                Wr_Reg  ESR51
                Wr_Reg  ESR52
                Wr_Reg  ESR53
                Wr_Reg  ESR54
                Wr_Reg  ESR55
                Wr_Reg  ESR56
                Wr_Reg  ESR57
                Wr_Reg  ESR58
                Wr_Reg  ESR59
                Wr_Reg  ESR60
                Wr_Reg  ESR61
                Wr_Reg  ESR62
                Wr_Reg  ESR63
                Wr_Reg  ESR64
                Wr_Reg  ESR65
                Wr_Reg  ESR66
                Wr_Reg  ESR67
                Wr_Reg  ESR68
                Wr_Reg  ESR69
                Wr_Reg  ESR70
                Wr_Reg  ESR71
                Wr_Reg  ESR72
                Wr_Reg  ESR73
                Wr_Reg  ESR74
                Wr_Reg  ESR75
                Wr_Reg  ESR76
                Wr_Reg  ESR77
                Wr_Reg  ESR78
                Wr_Reg  ESR79
                Wr_Reg  ESR80
                Wr_Reg  ESR81
                Wr_Reg  ESR82
                Wr_Reg  ESR83
                Wr_Reg  ESR84
                Wr_Reg  ESR85
                Wr_Reg  ESR86
                Wr_Reg  ESR87
                Wr_Reg  ESR88
                ENDIF   ;(ESR_SETUP != 0)

                IF      (FDC_SETUP != 0)          ; Setup FDCs
                Wr_Reg  FDC0 
                Wr_Reg  FDC1 
                Wr_Reg  FDC2 
                Wr_Reg  FDC3 
                Wr_Reg  FDC4 
                Wr_Reg  FDC5 
                Wr_Reg  FDC6 
                Wr_Reg  FDC7 
                Wr_Reg  FDC8 
                Wr_Reg  FDC9 
                Wr_Reg  FDC10
                Wr_Reg  FDC11
                Wr_Reg  FDC12
                Wr_Reg  FDC13
                Wr_Reg  FDC14
                Wr_Reg  FDC15
                Wr_Reg  FDC16
                Wr_Reg  FDC17
                Wr_Reg  FDC18
                Wr_Reg  FDC19
                Wr_Reg  FDC20
                Wr_Reg  FDC21
                Wr_Reg  FDC22
                Wr_Reg  FDC23
                ENDIF   ;(FDC_SETUP != 0)

                IF      (BCR_SETUP != 0)          ; Setup BCRs
                MOV     R1, #0
                STR     R1, [R0, #BCR0_OFS]
                Wr_Reg  BCR0
                STR     R1, [R0, #BCR1_OFS]
                Wr_Reg  BCR1
                STR     R1, [R0, #BCR2_OFS]
                Wr_Reg  BCR2
                STR     R1, [R0, #BCR3_OFS]
                Wr_Reg  BCR3
                STR     R1, [R0, #BCR7_OFS]
                Wr_Reg  BCR7
                ENDIF   ;(BCR_SETUP != 0)

                IF      (PCR_SETUP != 0)          ; Setup PCRs
                Wr_Reg  PCR0 
                Wr_Reg  PCR1 
                Wr_Reg  PCR2 
                Wr_Reg  PCR3 
                Wr_Reg  PCR4 
                Wr_Reg  PCR5 
                Wr_Reg  PCR6 
                Wr_Reg  PCR7 
                Wr_Reg  PCR8 
                Wr_Reg  PCR9 
                Wr_Reg  PCR10 
                Wr_Reg  PCR11 
                Wr_Reg  PCR12 
                Wr_Reg  PCR13 
                Wr_Reg  PCR14 
                Wr_Reg  PCR15 
                Wr_Reg  PCR16 
                Wr_Reg  PCR17 
                Wr_Reg  PCR18 
                Wr_Reg  PCR19 
                Wr_Reg  PCR20 
                Wr_Reg  PCR21 
                Wr_Reg  PCR22 
                Wr_Reg  PCR23 
                Wr_Reg  PCR24 
                Wr_Reg  PCR25 
                Wr_Reg  PCR26 
                Wr_Reg  PCR27 
                Wr_Reg  PCR28 
                Wr_Reg  PCR29 
                Wr_Reg  PCR30 
                Wr_Reg  PCR31 
                Wr_Reg  PCR32 
                Wr_Reg  PCR33 
                Wr_Reg  PCR34 
                Wr_Reg  PCR35 
                Wr_Reg  PCR36 
                Wr_Reg  PCR37 
                Wr_Reg  PCR38 
                Wr_Reg  PCR39 
                Wr_Reg  PCR40 
                Wr_Reg  PCR41 
                Wr_Reg  PCR42 
                Wr_Reg  PCR43 
                Wr_Reg  PCR44 
                Wr_Reg  PCR45 
                Wr_Reg  PCR46 
                Wr_Reg  PCR47 
                Wr_Reg  PCR48 
                Wr_Reg  PCR49 
                Wr_Reg  PCR50 
                Wr_Reg  PCR51 
                Wr_Reg  PCR52 
                Wr_Reg  PCR53 
                Wr_Reg  PCR54 
                Wr_Reg  PCR55 
                Wr_Reg  PCR56 
                Wr_Reg  PCR57 
                Wr_Reg  PCR58 
                Wr_Reg  PCR59 
                Wr_Reg  PCR60 
                Wr_Reg  PCR61 
                Wr_Reg  PCR62 
                Wr_Reg  PCR63 
                Wr_Reg  PCR64 
                Wr_Reg  PCR65 
                Wr_Reg  PCR66 
                Wr_Reg  PCR67 
                Wr_Reg  PCR68 
                Wr_Reg  PCR69 
                Wr_Reg  PCR70 
                Wr_Reg  PCR71 
                Wr_Reg  PCR72 
                Wr_Reg  PCR73 
                Wr_Reg  PCR74 
                Wr_Reg  PCR75 
                Wr_Reg  PCR76 
                Wr_Reg  PCR77 
                Wr_Reg  PCR78 
                Wr_Reg  PCR79 
                Wr_Reg  PCR80 
                Wr_Reg  PCR81 
                Wr_Reg  PCR82 
                Wr_Reg  PCR83 
                Wr_Reg  PCR84 
                Wr_Reg  PCR85 
                Wr_Reg  PCR86 
                Wr_Reg  PCR87 
                Wr_Reg  PCR88 
                Wr_Reg  PCR89 
                Wr_Reg  PCR90 
                Wr_Reg  PCR91 
                ENDIF   ;(PCR_SETUP != 0)

                IF      (FS2_SETUP != 0)          ; Setup FS2s
                Wr_Reg  FS2_0
                Wr_Reg  FS2_1
                Wr_Reg  FS2_2
                Wr_Reg  FS2_3
                Wr_Reg  FS2_4
                Wr_Reg  FS2_5
                Wr_Reg  FS2_6
                Wr_Reg  FS2_7
                Wr_Reg  FS2_8
                Wr_Reg  FS2_9
                Wr_Reg  FS2_10
                Wr_Reg  FS2_11
                ENDIF   ;(FS2_SETUP != 0)

                MOV     R2, #2
                STR     R2, [R0, #SCR0_OFS]
                STR     R2, [R0, #SCR1_OFS]
                STR     R2, [R0, #SCR2_OFS]
                STR     R2, [R0, #SCR3_OFS]
                STR     R2, [R0, #SCR4_OFS]
                STR     R2, [R0, #SCR5_OFS]
                STR     R2, [R0, #SCR6_OFS]
                STR     R2, [R0, #SCR7_OFS]
                STR     R2, [R0, #SCR8_OFS]
                STR     R2, [R0, #SCR9_OFS]
                STR     R2, [R0, #SCR10_OFS]
                STR     R2, [R0, #SCR11_OFS]
                ENDIF


; MPMC Setup -------------------------------------------------------------------

                IF      (:LNOT::DEF:NO_MPMC_INIT):LAND:(MPMC_SETUP != 0)
                LDR     R0, =MPMC_BASE            ; Address of MPMC Controller
                LDR     R1, =SC_BASE              ; Address of SYS CON Config
                LDR     R2, =CGU_BASE             ; External SDRAM0 Start Adr

;  Setup Dynamic Memory Interface
                IF      (:LNOT::DEF:NO_MPMC_DYNAMIC_INIT):LAND:(MPMC_DYNAMIC_SETUP != 0)
                LDR     R4, =1
                STR     R4, [R1, #SC_MUX_LCD_OFS] ; Enable EBI pins for SDRAM
                STR     R4, [R2, #PCR7_OFS]
                STR     R4, [R2, #PCR26_OFS]
                STR     R4, [R2, #PCR27_OFS]
                STR     R4, [R2, #PCR28_OFS]

                MOV     R4, #MPMCControl_Val
                STR     R4, [R0, #MPMCControl_OFS]
                LDR     R4, =MPMCConfig_Val
                STR     R4, [R0, #MPMCConfig_OFS]

                LDR     R4, =0x828
                STR     R4, [R1, #SC_MPMP_DM_OFS]

                LDR     R6, =100*45               ; ~100us at 180 MHz
Wait_0          SUBS    R6, R6, #1
                BNE     Wait_0

                LDR     R4, =MPMCDynReadCfg_Val
                STR     R4, [R0, #MPMCDynReadCfg_OFS]

                IF      (MPMC_DYNCS0_SETUP != 0)
                LDR     R4, =MPMCDynConfig0_Val
                STR     R4, [R0, #MPMCDynConfig0_OFS]
                LDR     R4, =MPMCDynRasCas0_Val
                STR     R4, [R0, #MPMCDynRasCas0_OFS]
                ENDIF

                LDR     R4, =MPMCDynRP_Val
                STR     R4, [R0, #MPMCDynRP_OFS]
                LDR     R4, =MPMCDynRAS_Val
                STR     R4, [R0, #MPMCDynRAS_OFS]
                LDR     R4, =MPMCDynSREX_Val
                STR     R4, [R0, #MPMCDynSREX_OFS]
                LDR     R4, =MPMCDynAPR_Val
                STR     R4, [R0, #MPMCDynAPR_OFS]
                LDR     R4, =MPMCDynDAL_Val
                STR     R4, [R0, #MPMCDynDAL_OFS]
                LDR     R4, =MPMCDynWR_Val
                STR     R4, [R0, #MPMCDynWR_OFS]
                LDR     R4, =MPMCDynRC_Val
                STR     R4, [R0, #MPMCDynRC_OFS]
                LDR     R4, =MPMCDynRFC_Val
                STR     R4, [R0, #MPMCDynRFC_OFS]
                LDR     R4, =MPMCDynXSR_Val
                STR     R4, [R0, #MPMCDynXSR_OFS]
                LDR     R4, =MPMCDynRRD_Val
                STR     R4, [R0, #MPMCDynRRD_OFS]
                LDR     R4, =MPMCDynMRD_Val
                STR     R4, [R0, #MPMCDynMRD_OFS]

                LDR     R6, =100*45               ; ~100us at 180 MHz
Wait_1          SUBS    R6, R6, #1
                BNE     Wait_1

                LDR     R4, =(NOP_CMD | MPMCDynControl_Val)     ; Write NOP Cmd
                STR     R4, [R0, #MPMCDynControl_OFS]

                LDR     R6, =200*45               ; ~200us at 180 MHz
Wait_2          SUBS    R6, R6, #1
                BNE     Wait_2

                LDR     R4, =(PALL_CMD | MPMCDynControl_Val)    ; Write Prchg All Cmd
                STR     R4, [R0, #MPMCDynControl_OFS]

                MOV     R4, #0
                STR     R4, [R0, #MPMCDynRefresh_OFS]

                LDR     R6, =250*45               ; ~250us at 180 MHz
Wait_3          SUBS    R6, R6, #1
                BNE     Wait_3

                LDR     R4, =MPMCDynRefresh_Val
                STR     R4, [R0, #MPMCDynRefresh_OFS]

                LDR     R4, =(MODE_CMD | MPMCDynControl_Val)    ; Write MODE Cmd
                STR     R4, [R0, #MPMCDynControl_OFS]

                LDR     R4, =(ESDRAM0_BASE+SDRAM0_MODE_REG)
                LDR     R4, [R4, #0]

                IF      (MPMC_DYNCS0_SETUP != 0)
                LDR     R4, =MPMCDynConfig0_Val
                STR     R4, [R0, #MPMCDynConfig0_OFS]
                LDR     R4, =MPMCDynRasCas0_Val
                STR     R4, [R0, #MPMCDynRasCas0_OFS]
                ENDIF

                LDR     R4, =(NORMAL_CMD | MPMCDynControl_Val)  ; Write NORMAL Cmd
                STR     R4, [R0, #MPMCDynControl_OFS]

                LDR     R4, =(MPMCDynConfig0_Val | B_BIT)       ; Enable buffer
                STR     R4, [R0, #MPMCDynConfig0_OFS]

                LDR     R4, =MPMCDynControl_Val
                STR     R4, [R0, #MPMCDynControl_OFS]
                ENDIF   ;(:LNOT::DEF:NO_MPMC_DYNAMIC_INIT):LAND:(MPMC_DYNAMIC_SETUP != 0)

;  Setup Static Memory Interface
                IF      (:LNOT::DEF:NO_MPMC_STATIC_INIT):LAND:(MPMC_STATIC_SETUP != 0)

                IF      (MPMC_STACS0_SETUP != 0)
                LDR     R4, =MPMCStaConfig0_Val
                STR     R4, [R0, #MPMCStaConfig0_OFS]
                LDR     R4, =MPMCStaWaitWen0_Val
                STR     R4, [R0, #MPMCStaWaitWen0_OFS]
                LDR     R4, =MPMCStaWaitOen0_Val
                STR     R4, [R0, #MPMCStaWaitOen0_OFS]
                LDR     R4, =MPMCStaWaitRd0_Val
                STR     R4, [R0, #MPMCStaWaitRd0_OFS]
                LDR     R4, =MPMCStaWaitPage0_Val
                STR     R4, [R0, #MPMCStaWaitPage0_OFS]
                LDR     R4, =MPMCStaWaitWr0_Val
                STR     R4, [R0, #MPMCStaWaitWr0_OFS]
                LDR     R4, =MPMCStaWaitTurn0_Val
                STR     R4, [R0, #MPMCStaWaitTurn0_OFS]
                ENDIF

                IF      (MPMC_STACS1_SETUP != 0)
                LDR     R4, =MPMCStaConfig1_Val
                STR     R4, [R0, #MPMCStaConfig1_OFS]
                LDR     R4, =MPMCStaWaitWen1_Val
                STR     R4, [R0, #MPMCStaWaitWen1_OFS]
                LDR     R4, =MPMCStaWaitOen1_Val
                STR     R4, [R0, #MPMCStaWaitOen1_OFS]
                LDR     R4, =MPMCStaWaitRd1_Val
                STR     R4, [R0, #MPMCStaWaitRd1_OFS]
                LDR     R4, =MPMCStaWaitPage1_Val
                STR     R4, [R0, #MPMCStaWaitPage1_OFS]
                LDR     R4, =MPMCStaWaitWr1_Val
                STR     R4, [R0, #MPMCStaWaitWr1_OFS]
                LDR     R4, =MPMCStaWaitTurn1_Val
                STR     R4, [R0, #MPMCStaWaitTurn1_OFS]
                ENDIF

                LDR     R4, =MPMCStaExtWait_Val
                STR     R4, [R0, #MPMCStaExtWait_OFS]

                ENDIF   ;(:LNOT::DEF:NO_MPMC_STATIC_INIT):LAND:(MPMC_STATIC_SETUP != 0)
                ENDIF   ;(:LNOT::DEF:NO_MPMC_INIT):LAND:(MPMC_SETUP != 0)


; Setup shadowing --------------------------------------------------------------

                IF      (:LNOT::DEF:NO_SHADOW_INIT):LAND:(SHADOW_SETUP != 0)
                LDR     R0, =SC_BASE
                LDR     R1, =SC_ARM926_S_Val
                STR     R1, [R0, #SC_ARM926_S_OFS]
                ENDIF


; Cache Setup ------------------------------------------------------------------

                IF      ICACHE_SETUP != 0
                MRC     p15, 0, R0, c1, c0, 0   ; Enable Instruction Cache
                ORR     R0, R0, #ICACHE_ENABLE
                MCR     p15, 0, R0, c1, c0, 0
                ENDIF


; Setup Stack for each mode ----------------------------------------------------

                LDR     R0, =Stack_Top

;  Enter Undefined Instruction Mode and set its Stack Pointer
                MSR     CPSR_c, #Mode_UND:OR:I_Bit:OR:F_Bit
                MOV     SP, R0
                SUB     R0, R0, #UND_Stack_Size

;  Enter Abort Mode and set its Stack Pointer
                MSR     CPSR_c, #Mode_ABT:OR:I_Bit:OR:F_Bit
                MOV     SP, R0
                SUB     R0, R0, #ABT_Stack_Size

;  Enter FIQ Mode and set its Stack Pointer
                MSR     CPSR_c, #Mode_FIQ:OR:I_Bit:OR:F_Bit
                MOV     SP, R0
                SUB     R0, R0, #FIQ_Stack_Size

;  Enter IRQ Mode and set its Stack Pointer
                MSR     CPSR_c, #Mode_IRQ:OR:I_Bit:OR:F_Bit
                MOV     SP, R0
                SUB     R0, R0, #IRQ_Stack_Size

;  Enter Supervisor Mode and set its Stack Pointer
                MSR     CPSR_c, #Mode_SVC:OR:I_Bit:OR:F_Bit
                MOV     SP, R0
                SUB     R0, R0, #SVC_Stack_Size

;  Enter User Mode and set its Stack Pointer
                MSR     CPSR_c, #Mode_USR
                IF      :DEF:__MICROLIB

                EXPORT __initial_sp

                ELSE

                MOV     SP, R0
                SUB     SL, SP, #USR_Stack_Size

                ENDIF

; Enter the C code -------------------------------------------------------------

                IMPORT  __main
                LDR     R0, =__main
                BX      R0


                IF      :DEF:__MICROLIB

                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE
; User Initial Stack & Heap
                AREA    |.text|, CODE, READONLY

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + USR_Stack_Size)
                LDR     R2, = (Heap_Mem +      Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR
                ENDIF


                END
