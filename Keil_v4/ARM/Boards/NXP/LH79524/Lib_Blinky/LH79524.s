;/*****************************************************************************/
;/* LH79524.S: Startup file for NXP LH79524 and LH79525 device series         */
;/*****************************************************************************/
;/* <<< Use Configuration Wizard in Context Menu >>>                          */ 
;/*****************************************************************************/
;/* This file is part of the uVision/ARM development tools.                   */
;/* Copyright (c) 2005-2007 Keil Software. All rights reserved.               */
;/* This software may only be used under the terms of a valid, current,       */
;/* end user licence from KEIL for a compatible version of KEIL software      */
;/* development tools. Nothing else gives you the right to use this software. */
;/*****************************************************************************/


;/*
; *  The LH79524.S code is executed after CPU Reset. This file may be 
; *  translated with the following SET symbols. In uVision these SET 
; *  symbols are entered under Options - ASM - Define.
; *
; *  REMAP:         when set the startup code does remaps exception vectors 
; *                 from selected memory to address 0:
; *                 0x44000000  when EXTSRAM1_MODE used - external SRAM nCS1
; *                                                       (Boot ROM)
; *                 0x20000000  when EXTSDRAM_MODE used - external SDRAM nDCS0
; *                 0x60000000  when INTSRAM_MODE used  - internal SRAM
; *                 0x40000000  when EXTSRAM0_MODE used - external SRAM nCS0
; *
; *  EXTSRAM1_MODE: when set the device is configured for code execution
; *                 from external SRAM memory to where also Boot ROM is mapped 
; *                 starting at address 0x44000000.
; *
; *  EXTSDRAM_MODE: when set the device is configured for code execution
; *                 from external SDRAM memory starting at address 0x20000000.
; *
; *  INTSRAM_MODE:  when set the device is configured for code execution
; *                 from on-chip SRAM starting at address 0x60000000.
; *
; *  EXTSRAM0_MODE: when set the device is configured for code execution
; *                 from external SRAM memory starting at address 0x40000000.
; *
; *  EMC_DYN_NOINIT:when set, the Dynamic Memory Interface of External Memory 
; *                 Controller is not initialized in startup.
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
IRAM_BASE       EQU     0x60000000
IROM_BASE       EQU     0x80000000

; External Memory Base Addresses
ESDRAM_BASE     EQU     0x20000000


;----------------------- Stack and Heap Definitions ----------------------------

;// <h> Stack Configuration (Stack Sizes in Bytes)
;//   <o0> Undefined Mode      <0x0-0xFFFFFFFF:8>
;//   <o1> Supervisor Mode     <0x0-0xFFFFFFFF:8>
;//   <o2> Abort Mode          <0x0-0xFFFFFFFF:8>
;//   <o3> Fast Interrupt Mode <0x0-0xFFFFFFFF:8>
;//   <o4> Interrupt Mode      <0x0-0xFFFFFFFF:8>
;//   <o5> User/System Mode    <0x0-0xFFFFFFFF:8>
;// </h>

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


;// <h> Heap Configuration
;//   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF>
;// </h>

Heap_Size       EQU     0x00000000

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


;----------------------- Reset, Clock and Power Controller (RCPC) Definitions --

; Reset, Clock and Power Controller (RCPC) User Interface
RCPC_BASE       EQU     0xFFFE2000      ; RCPC                    Base Address
CTRL_OFS        EQU     0x00            ; RCPC Control Register   Address Offset
CHIPID_OFS      EQU     0x04            ; Chip Identification Reg Address Offset
REMAP_OFS       EQU     0x08            ; Remap Control Register  Address Offset
SOFTRESET_OFS   EQU     0x0C            ; Soft Reset Register     Address Offset
RSTSTATUS_OFS   EQU     0x10            ; Reset Status Register   Address Offset
RSTSTATUSCLR_OFS  EQU   0x14            ; Reset Status Clear Reg  Address Offset
SYSCLKPRE_OFS   EQU     0x18            ; System Clock Prescaler  Address Offset
CPUCLKPRE_OFS   EQU     0x1C            ; CPU Clock Prescaler Reg Address Offset
PCLKCTRL0_OFS   EQU     0x24            ; Peripheral Clock Ctrl 0 Address Offset
PCLKCTRL1_OFS   EQU     0x28            ; Peripheral Clock Ctrl 1 Address Offset
AHBCLKCTRL_OFS  EQU     0x2C            ; AHB Clock Control Reg   Address Offset
PCLKSEL0_OFS    EQU     0x30            ; Peri Clock Select Reg 0 Address Offset
PCLKSEL1_OFS    EQU     0x34            ; Peri Clock Select Reg 1 Address Offset
SILICONREV_OFS  EQU     0x3C            ; Silicon Revision Reg    Address Offset
LCDPRE_OFS      EQU     0x40            ; LCD Prescaler Register  Address Offset
SSPPRE_OFS      EQU     0x44            ; SSP Prescaler Register  Address Offset
ADCPRE_OFS      EQU     0x48            ; ADC Prescaler Register  Address Offset
USBPRE_OFS      EQU     0x4C            ; USB Prescaler Register  Address Offset
INTCONFIG_OFS   EQU     0x80            ; Ext Interrupt Config R  Address Offset
INTCLR_OFS      EQU     0x84            ; Ext Interrupt Clear Reg Address Offset
CORECONFIG_OFS  EQU     0x88            ; Core Clock Config Reg   Address Offset
SYSPLLCNTL_OFS  EQU     0xC0            ; System PLL Control Reg  Address Offset
USBPLLCTL_OFS   EQU     0xC4            ; USB PLL Control Reg     Address Offset

; Constants
CTRL_LOCK_BIT   EQU     (1 << 9)        ; Lock bit in Control Register
REMAP0          EQU     0               ; Remap value 0
REMAP1          EQU     1               ; Remap value 1
REMAP2          EQU     2               ; Remap value 2
REMAP3          EQU     3               ; Remap value 3

;// <e> Clock Configuration (RCPC)
CLOCK_SETUP     EQU     1

;//   <h> Control Register (CTRL)
;//     <o0.5..6> OUTSEL: CLKOUT Source Select
;//                     <0=> System clock oscillator
;//                     <1=> Off
;//                     <2=> FCLK
;//                     <3=> HCLK
;//     <o0.2..4> PWRDWNSEL: Power Down Mode Select
;//                     <0=> Active mode
;//                     <1=> Standby mode
;//                     <2=> Sleep mode
;//                     <3=> Stop1 mode
;//                     <4=> Stop2 mode
;//   </h>
CTRL_Val        EQU     0x00000063

;//   <h> System Clock Prescaler Register (SYSCLKPRE)
;//     <o0.0..3> HDIV: HCLK Divisor <2-30:2><#/2>
;//   </h>
SYSCLKPRE_Val   EQU     0x00000001

;//   <h> CPU Clock Prescaler Register (CPUCLKPRE)
;//     <o0.0..3> FDIV: FCLK Divisor <2-30:2><#/2>
;//   </h>
CPUCLKPRE_Val   EQU     0x00000001

;//   <h> Peripheral Clock Control Register 0 (PCLKCTRL0)
;//     <o0.9>    RTC: RTC Clock Disable
;//     <o0.2>    U2: UART2 Clock Disable
;//     <o0.1>    U1: UART1 Clock Disable
;//     <o0.0>    U0: UART0 Clock Disable
;//   </h>
PCLKCTRL0_Val   EQU     0x000003FF

;//   <h> Peripheral Clock Control Register 1 (PCLKCTRL1)
;//     <o0.3>    USB: USB Clock Disable
;//     <o0.2>    ADC: ADC Clock Disable
;//     <o0.1>    SSP: SSP Clock Disable
;//     <o0.0>    LCD: LCD Data Clock Disable
;//   </h>
PCLKCTRL1_Val   EQU     0x0000000F

;//   <h> AHB Clock Control Register (AHBCLKCTRL)
;//     <o0.4>    LCD: AHB LCD Clock Disable
;//     <o0.3>    USB: AHB USB Clock Disable
;//     <o0.2>    ETHERNET: AHB ETHERNET Clock Disable
;//     <o0.1>    SDRAM: AHB SDRAM Controller Clock Disable
;//     <o0.0>    DMA: AHB DMA Clock Disable
;//   </h>
AHBCLKCTRL_Val  EQU     0x0000001C

;//   <h> Peripheral Clock Select Register 0 (PCLKSEL0)
;//     <o0.2>    UART2: UART2 Clock Source
;//                     <0=> System clock (HCLK)
;//                     <1=> Crystal oscillator output
;//     <o0.1>    UART1: UART1 Clock Source
;//                     <0=> System clock (HCLK)
;//                     <1=> Crystal oscillator output
;//     <o0.0>    UART0: UART0 Clock Source
;//                     <0=> System clock (HCLK)
;//                     <1=> Crystal oscillator output
;//   </h>
PCLKSEL0_Val    EQU     0x00000000

;//   <h> Peripheral Clock Select Register 1 (PCLKSEL1)
;//     <o0.3>    USB: USB Peripheral Clock Source
;//                     <0=> USB PLL clock
;//                     <1=> System clock (HCLK)
;//     <o0.2>    ADC: ADC Peripheral Clock Source
;//                     <0=> System clock oscillator frequency
;//                     <1=> System clock (HCLK)
;//     <o0.1>    SSP: SSP Peripheral Clock Source
;//                     <0=> System clock oscillator frequency
;//                     <1=> System clock (HCLK)
;//   </h>
PCLKSEL1_Val    EQU     0x00000004

;//   <h> LCD Clock Prescaler Register (LCDPRE)
;//     <o0.0..7> LCDDIV: LCD Data Clock Divisor
;//                     <0=>   1 (HCLK)
;//                     <1=>   2 (HCLK/2)
;//                     <2=>   4 (HCLK/4)
;//                     <4=>   8 (HCLK/8)
;//                     <8=>   16 (HCLK/16)
;//                     <16=>  32 (HCLK/32)
;//                     <32=>  64 (HCLK/64)
;//                     <64=>  128 (HCLK/128)
;//                     <128=> 256 (HCLK/256)
;//   </h>
LCDPRE_Val      EQU     0x00000000

;//   <h> SSP Clock Prescaler Register (SSPPRE)
;//     <o0.0..7> SSPDIV: SSP Clock Divisor
;//                     <0=>   1 (clock source)
;//                     <1=>   2 (clock source/2)
;//                     <2=>   4 (clock source/4)
;//                     <4=>   8 (clock source/8)
;//                     <8=>   16 (clock source/16)
;//                     <16=>  32 (clock source/32)
;//                     <32=>  64 (clock source/64)
;//                     <64=>  128 (clock source/128)
;//                     <128=> 256 (clock source/256)
;//   </h>
SSPPRE_Val      EQU     0x00000000

;//   <h> ADC Clock Prescaler Register (ADCPRE)
;//     <o0.0..7> ADCDIV: ADC Clock Divisor
;//                     <0=>   1 (clock source)
;//                     <1=>   2 (clock source/2)
;//                     <2=>   4 (clock source/4)
;//                     <4=>   8 (clock source/8)
;//                     <8=>   16 (clock source/16)
;//                     <16=>  32 (clock source/32)
;//                     <32=>  64 (clock source/64)
;//                     <64=>  128 (clock source/128)
;//                     <128=> 256 (clock source/256)
;//   </h>
ADCPRE_Val      EQU     0x00000008

;//   <h> USB Clock Prescaler Register (USBPRE)
;//     <o0.0..7> USBDIV: ADC Clock Divisor
;//                     <0=>   1 (clock source)
;//                     <1=>   2 (clock source/2)
;//                     <2=>   4 (clock source/4)
;//   </h>
USBPRE_Val      EQU     0x00000000

;//   <h> Core Clock Configuration Register (CORECONFIG)
;//     <o0.0..1> CCLK: Core Clock Configuration
;//                     <0=> Standard mode, async operation
;//                     <1=> FastBus extension mode
;//                     <2=> Standard mode, sync operation
;//                     <3=> FastBus extension mode
;//   </h>
CORECONFIG_Val  EQU     0x00000001

;//   <h> System PLL Control Register (SYSPLLCNTL)
;//     <o0.12>   SYSFRANGE: System PLL Output Frequency Range Select
;//                     <0=> 20 MHz to 100 MHz
;//                     <1=> 100 MHz to 304.819 MHz
;//     <o0.6..11> SYSPREDIV: System PLL Pre-Divider <0-64>
;//                     <i> Prescales the system PLL reference clock.
;//                     <i> Must satisfy equation: (sys clock osc freq)/(SYSPREDIV) >= 5 MHz
;//     <o0.0..5> SYSLOOPDIV: System PLL Loop-Divider <1-63>
;//                     <i> Prescales the system PLL feedback clock.
;//   </h>
SYSPLLCNTL_Val  EQU     0x00003049

;//   <h> USB PLL Control Register (USBPLLCTL)
;//     <o0.12>   USBFRANGE: USB PLL Output Frequency Range Select
;//                     <0=> 20 MHz to 100 MHz
;//                     <1=> 100 MHz to 304.819 MHz
;//     <o0.6..11> USBPREDIV: USB PLL Pre-Divider <0-64>
;//                     <i> Prescales the USB PLL reference clock.
;//                     <i> Must satisfy equation: (sys clock osc freq)/(USBPREDIV) >= 5 MHz
;//     <o0.0..5> USBLOOPDIV: USB PLL Loop-Divider <1-63>
;//                     <i> Prescales the USB PLL feedback clock.
;//   </h>
USBPLLCTL_Val   EQU     0x00002081

;// </e> Clock Configuration


;----------------------- IO Configurations (IOCON) Definitions -----------------

; I/O Configuration (IOCON) User Interface
IOCON_BASE      EQU     0xFFFE5000      ; IOCON Base Address
MUXCTL1_OFS     EQU     0x00            ; Muxing Control 1 Register    Offset
RESCTL1_OFS     EQU     0x04            ; Resistor Control 1 Register  Offset
MUXCTL3_OFS     EQU     0x10            ; Muxing Control 3 Register    Offset
RESCTL3_OFS     EQU     0x14            ; Resistor Control 3 Register  Offset
MUXCTL4_OFS     EQU     0x18            ; Muxing Control 4 Register    Offset
RESCTL4_OFS     EQU     0x1C            ; Resistor Control 4 Register  Offset
MUXCTL5_OFS     EQU     0x20            ; Muxing Control 5 Register    Offset
RESCTL5_OFS     EQU     0x24            ; Resistor Control 5 Register  Offset
MUXCTL6_OFS     EQU     0x28            ; Muxing Control 6 Register    Offset
RESCTL6_OFS     EQU     0x2C            ; Resistor Control 6 Register  Offset
MUXCTL7_OFS     EQU     0x30            ; Muxing Control 7 Register    Offset
RESCTL7_OFS     EQU     0x34            ; Resistor Control 7 Register  Offset
MUXCTL10_OFS    EQU     0x48            ; Muxing Control 10 Register   Offset
RESCTL10_OFS    EQU     0x4C            ; Resistor Control 10 Register Offset
MUXCTL11_OFS    EQU     0x50            ; Muxing Control 11 Register   Offset
RESCTL11_OFS    EQU     0x54            ; Resistor Control 11 Register Offset
MUXCTL12_OFS    EQU     0x58            ; Muxing Control 12 Register   Offset
RESCTL12_OFS    EQU     0x5C            ; Resistor Control 12 Register Offset
RESCTL13_OFS    EQU     0x64            ; Resistor Control 13 Register Offset
MUXCTL14_OFS    EQU     0x68            ; Muxing Control 14 Register   Offset
MUXCTL15_OFS    EQU     0x70            ; Muxing Control 15 Register   Offset
RESCTL15_OFS    EQU     0x74            ; Resistor Control 15 Register Offset
MUXCTL17_OFS    EQU     0x84            ; Muxing Control 17 Register   Offset
MUXCTL19_OFS    EQU     0x90            ; Muxing Control 19 Register   Offset
RESCTL19_OFS    EQU     0x94            ; Resistor Control 19 Register Offset
MUXCTL20_OFS    EQU     0x98            ; Muxing Control 20 Register   Offset
RESCTL20_OFS    EQU     0x9C            ; Resistor Control 20 Register Offset
MUXCTL21_OFS    EQU     0xA0            ; Muxing Control 21 Register   Offset
RESCTL21_OFS    EQU     0xA4            ; Resistor Control 21 Register Offset
MUXCTL22_OFS    EQU     0xA8            ; Muxing Control 22 Register   Offset
RESCTL22_OFS    EQU     0xAC            ; Resistor Control 22 Register Offset
MUXCTL23_OFS    EQU     0xB0            ; Muxing Control 23 Register   Offset
RESCTL23_OFS    EQU     0xB4            ; Resistor Control 23 Register Offset
MUXCTL24_OFS    EQU     0xB8            ; Muxing Control 24 Register   Offset
RESCTL24_OFS    EQU     0xBC            ; Resistor Control 24 Register Offset
MUXCTL25_OFS    EQU     0xC0            ; Muxing Control 25 Register   Offset

;// <e> I/O Configuration (IOCON)
IOCON_SETUP     EQU     1

;//   <e> Configuration 1
;//     <h> Multiplexing Control 1 Register (MUXCTL1)
;//       <o1.8..9>   PI2: PI2/ETHERCOL Assignment  <0=> PI2 <1=> ETHERCOL
;//       <o1.6..7>   PI1: PI1/ETHERMDIO Assignment <0=> PI1 <1=> ETHERMDIO
;//       <o1.4..5>   PI0: PI0/ETHERMDC Assignment  <0=> PI0 <1=> ETHERMDC
;//       <o1.2..3>   PL1: PL1/LCDVD15 Assignment   <0=> PL1 <1=> LCDVD15
;//       <o1.0..1>   PL0: PL0/LCDVD14 Assignment   <0=> PL0 <1=> LCDVD14
;//     </h>
;//     <h> Resistor Configuration Control 1 Register (RESCTL1)
;//       <o2.8..9>   PI2: PI2/ETHERCOL Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.6..7>   PI1: PI1/ETHERMDIO Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.4..5>   PI0: PI0/ETHERMDC Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.2..3>   PL1: PL1/LCDVD15 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.0..1>   PL0: PL0/LCDVD14 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//     </h>
;//   </e>
IOCFG1_SETUP    EQU     0
MUXCTL1_Val     EQU     0x00000000
RESCTL1_Val     EQU     0x00000195

;//   <e> Configuration 3
;//     <h> Multiplexing Control 3 Register (MUXCTL3)
;//       <o1.0..1>   INT4: CTCLK/INT4/BATCNTL Assignment <0=> CTCLK <1=> INT4 <2=> BATCNTL
;//     </h>
;//     <h> Resistor Configuration Control 3 Register (RESCTL3)
;//       <o2.0..1>   INT4: CTCLK/INT4/BATCNTL Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//     </h>
;//   </e>
IOCFG3_SETUP    EQU     0
MUXCTL3_Val     EQU     0x00000000
RESCTL3_Val     EQU     0x00000002

;//   <e> Configuration 4
;//     <h> Multiplexing Control 4 Register (MUXCTL4)
;//       <o1.10..11> PA7: PA7/CTCAP2B/CTCMP2B/SCL Assignment
;//                   <0=> PA7      <1=> CTCAP2B  <2=> CTCMP2B  <3=> SCL
;//       <o1.8..9>   PA6: PA6/CTCAP2A/CTCMP2A/SDA Assignment
;//                   <0=> PA6      <1=> CTCAP2A  <2=> CTCMP2A  <3=> SDA
;//       <o1.6..7>   PA5: PA5/CTCAP1B/CTCMP1B Assignment
;//                   <0=> PA5      <1=> CTCAP1B  <2=> CTCMP1B
;//       <o1.4..5>   PA4: PA4/CTCAP1A/CTCMP1A Assignment
;//                   <0=> PA4      <1=> CTCAP1A  <2=> CTCMP1A
;//       <o1.2..3>   PA3: PA3/CTCAP0B/CTCMP0B Assignment
;//                   <0=> PA3      <1=> CTCAP0B  <2=> CTCMP0B
;//       <o1.0..1>   PA2: PA2/CTCAP0A/CTCMP0A Assignment
;//                   <0=> PA2      <1=> CTCAP0A  <2=> CTCMP0A
;//     </h>
;//     <h> Resistor Configuration Control 4 Register (RESCTL4)
;//       <o2.10..11> PA7: PA7/CTCAP2B/CTCMP2B/SCL Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.8..9>   PA6: PA6/CTCAP2A/CTCMP2A/SDA Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.6..7>   PA5: PA5/CTCAP1B/CTCMP1B Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.4..5>   PA4: PA4/CTCAP1A/CTCMP1A Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.2..3>   PA3: PA3/CTCAP0B/CTCMP0B Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.0..1>   PA2: PA2/CTCAP0A/CTCMP0A Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//     </h>
;//   </e>
IOCFG4_SETUP    EQU     0
MUXCTL4_Val     EQU     0x00000000
RESCTL4_Val     EQU     0x00000A55

;//   <e> Configuration 5
;//     <h> Multiplexing Control 5 Register (MUXCTL5)
;//       <o1.14..15> PA1: PA1/INT3/UARTTX2/UARTIRTX2 Assignment
;//                   <0=> PA1      <1=> INT3     <2=> UARTTX2  <3=> UARTIRTX2
;//       <o1.12..13> PA0: PA0/INT2/UARTRX2/UARTIRRX2 Assignment
;//                   <0=> PA0      <1=> INT2     <2=> UARTRX2  <3=> UARTIRRX2
;//       <o1.10..11> PB7: PB7/INT1/UARTTX0/UARTIRTX0 Assignment
;//                   <0=> PB7      <1=> INT1     <2=> UARTTX0  <3=> UARTIRTX0
;//       <o1.8..9>   PB6: PB6/INT0/UARTRX0/UARTIRRX0 Assignment
;//                   <0=> PB6      <1=> INT0     <2=> UARTRX0  <3=> UARTIRRX0
;//       <o1.6..7>   PB5: PB5/SSPTX/UARTTX1/UARTIRTX1 Assignment
;//                   <0=> PB5      <1=> SSPTX    <2=> UARTTX1  <3=> UARTIRTX1
;//       <o1.4..5>   PB4: PB4/SSPRX/UARTRX1/UARTIRRX1 Assignment
;//                   <0=> PB4      <1=> SSPRX    <2=> UARTRX1  <3=> UARTIRRX1
;//       <o1.2..3>   PB3: PB3/SSPCLK Assignment
;//                   <0=> PB3      <1=> SSPCLK
;//       <o1.0..1>   PB2: PB2/SSPFRM Assignment
;//                   <0=> PB3      <1=> SSPFRM
;//     </h>
;//     <h> Resistor Configuration Control 5 Register (RESCTL5)
;//       <o2.14..15> PA1: PA1/INT3/UARTTX2/UARTIRTX2 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.12..13> PA0: PA0/INT2/UARTRX2/UARTIRRX2 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.10..11> PB7: PB7/INT1/UARTTX0/UARTIRTX0 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.8..9>   PB6: PB6/INT0/UARTRX0/UARTIRRX0 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.6..7>   PB5: PB5/SSPTX/UARTTX1/UARTIRTX1 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.4..5>   PB4: PB4/SSPRX/UARTRX1/UARTIRRX1 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.2..3>   PB3: PB3/SSPCLK Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.0..1>   PB2: PB2/SSPFRM Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//     </h>
;//   </e>
IOCFG5_SETUP    EQU     0
MUXCTL5_Val     EQU     0x00000000
RESCTL5_Val     EQU     0x00005556

;//   <e> Configuration 6
;//     <h> Multiplexing Control 6 Register (MUXCTL6)
;//       <o1.2..3>   PB1: PB1/DREQ/nUARTRTS0 Assignment
;//                   <0=> PB1      <1=> DREQ     <2=> nUARTRTS0
;//       <o1.0..1>   PB0: PB0/nDACK/nUARTCTS0 Assignment
;//                   <0=> PB0      <1=> nDACK    <2=> nUARTCTS0
;//     </h>
;//     <h> Resistor Configuration Control 6 Register (RESCTL6)
;//       <o2.2..3>   PB1: PB1/DREQ/nUARTRTS0 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.0..1>   PB0: PB0/nDACK/nUARTCTS0 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//     </h>
;//   </e>
IOCFG6_SETUP    EQU     0
MUXCTL6_Val     EQU     0x00000000
RESCTL6_Val     EQU     0x0000000A

;//   <e> Configuration 7
;//     <h> Multiplexing Control 7 Register (MUXCTL7)
;//       <o1.14..15> PC7: PC7/A23/nFRE Assignment <0=> PC7  <1=> A23  <2=> nFRE
;//       <o1.12..13> PC6: PC6/A22/nFWE Assignment <0=> PC6  <1=> A22  <2=> nFWE
;//       <o1.10..11> PC5: PC5/A21 Assignment      <0=> PC5  <1=> A21
;//       <o1.8..9>   PC4: PC4/A20 Assignment      <0=> PC4  <1=> A20
;//       <o1.6..7>   PC3: PC3/A19 Assignment      <0=> PC3  <1=> A19
;//       <o1.4..5>   PC2: PC2/A18 Assignment      <0=> PC2  <1=> A18
;//       <o1.2..3>   PC1: PC1/A17 Assignment      <0=> PC1  <1=> A17
;//       <o1.0..1>   PC0: PC0/A16 Assignment      <0=> PC0  <1=> A16
;//     </h>
;//     <h> Resistor Configuration Control 7 Register (RESCTL7)
;//       <o2.14..15> PC7: PC7/A23/nFRE Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.12..13> PC6: PC6/A22/nFWE Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.10..11> PC5: PC5/A21 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.8..9>   PC4: PC4/A20 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.6..7>   PC3: PC3/A19 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.4..5>   PC2: PC2/A18 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.2..3>   PC1: PC1/A17 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.0..1>   PC0: PC0/A16 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//     </h>
;//   </e>
IOCFG7_SETUP    EQU     1
MUXCTL7_Val     EQU     0x00005555
RESCTL7_Val     EQU     0x00000000

;//   <e> Configuration 10
;//     <h> Multiplexing Control 10 Register (MUXCTL10)
;//       <o1.14..15> PN3: PN3/D25 Assignment <0=> PN3  <1=> D25
;//       <o1.12..13> PN2: PN2/D24 Assignment <0=> PN2  <1=> D24
;//       <o1.10..11> PD7: PD7/D15 Assignment <0=> PD7  <1=> D15
;//       <o1.8..9>   PK7: PK7/D23 Assignment <0=> PK7  <1=> D23
;//       <o1.6..7>   PD6: PD6/D14 Assignment <0=> PD6  <1=> D14
;//       <o1.4..5>   PK6: PK6/D22 Assignment <0=> PK6  <1=> D22
;//       <o1.2..3>   PD5: PD5/D13 Assignment <0=> PD5  <1=> D13
;//       <o1.0..1>   PK5: PK5/D21 Assignment <0=> PK5  <1=> D21
;//     </h>
;//     <h> Resistor Configuration Control 10 Register (RESCTL10)
;//       <o2.14..15> PN3: PN3/D25 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.12..13> PN2: PN2/D24 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.10..11> PD7: PD7/D15 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.8..9>   PK7: PK7/D23 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.6..7>   PD6: PD6/D14 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.4..5>   PK6: PK6/D22 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.2..3>   PD5: PD5/D13 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.0..1>   PK5: PK5/D21 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//     </h>
;//   </e>
IOCFG10_SETUP   EQU     1
MUXCTL10_Val    EQU     0x00005555
RESCTL10_Val    EQU     0x00000000

;//   <e> Configuration 11
;//     <h> Multiplexing Control 11 Register (MUXCTL11)
;//       <o1.14..15> PD4: PD4/D12 Assignment <0=> PD4  <1=> D12
;//       <o1.12..13> PK4: PK4/D20 Assignment <0=> PK4  <1=> D20
;//       <o1.10..11> PD3: PD3/D11 Assignment <0=> PD3  <1=> D11
;//       <o1.8..9>   PK3: PK3/D19 Assignment <0=> PK3  <1=> D19
;//       <o1.6..7>   PD2: PD2/D10 Assignment <0=> PD2  <1=> D10
;//       <o1.4..5>   PK2: PK2/D18 Assignment <0=> PK2  <1=> D18
;//       <o1.2..3>   PK1: PK1/D17 Assignment <0=> PK1  <1=> D17
;//       <o1.0..1>   PD1: PD1/D9 Assignment  <0=> PD1  <1=> D9
;//     </h>
;//     <h> Resistor Configuration Control 11 Register (RESCTL11)
;//       <o2.14..15> PD4: PD4/D12 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.12..13> PK4: PK4/D20 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.10..11> PD3: PD3/D11 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.8..9>   PK3: PK3/D19 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.6..7>   PD2: PD2/D10 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.4..5>   PK2: PK2/D18 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.2..3>   PK1: PK1/D17 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.0..1>   PD1: PD1/D9 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//     </h>
;//   </e>
IOCFG11_SETUP   EQU     1
MUXCTL11_Val    EQU     0x00005555
RESCTL11_Val    EQU     0x00000000

;//   <e> Configuration 12
;//     <h> Multiplexing Control 12 Register (MUXCTL12)
;//       <o1.14..15> PK0: PK0/D16 Assignment <0=> PK0  <1=> D16
;//       <o1.12..13> PD0: PD0/D8 Assignment  <0=> PD0  <1=> D8
;//     </h>
;//     <h> Resistor Configuration Control 12 Register (RESCTL12)
;//       <o2.14..15> PK0: PK0/D16 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.12..13> PD0: PD0/D8 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.10..11> D7: PD7 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.8..9>   D6: PD6 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.6..7>   D5: PD5 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.4..5>   D4: PD4 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.2..3>   D3: PD3 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.0..1>   D2: PD2 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//     </h>
;//   </e>
IOCFG12_SETUP   EQU     1
MUXCTL12_Val    EQU     0x00005000
RESCTL12_Val    EQU     0x00000000

;//   <e> Configuration 13
;//     <h> Resistor Configuration Control 13 Register (RESCTL13)
;//       <o1.2..3>   D1: D1 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o1.0..1>   D0: D0 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//     </h>
;//   </e>
IOCFG13_SETUP   EQU     0
RESCTL13_Val    EQU     0x00000005

;//   <e> Configuration 14
;//     <h> Multiplexing Control 14 Register (MUXCTL14)
;//       <o1.14..15> nCS3: nCS3/PM3 Assignment   <0=> nCS3  <1=> PM3
;//       <o1.12..13> nCS2: nCS2/PM2 Assignment   <0=> nCS2  <1=> PM2
;//       <o1.10..11> nCS1: nCS1/PM1 Assignment   <0=> nCS1  <1=> PM1
;//       <o1.8..9>   nCS0: nCS0/PM0 Assignment   <0=> nCS0  <1=> PM0
;//       <o1.4..5>   nBLE3: nBLE3/PM7 Assignment <0=> nBLE3 <1=> PM7
;//       <o1.2..3>   nBLE2: nBLE2/PM6 Assignment <0=> nBLE2 <1=> PM6
;//       <o1.0..1>   nBLE1: nBLE1/PM5 Assignment <0=> nBLE1 <1=> PM5
;//     </h>
;//   </e>
IOCFG14_SETUP   EQU     0
MUXCTL14_Val    EQU     0x00000000

;//   <e> Configuration 15
;//     <h> Multiplexing Control 15 Register (MUXCTL15)
;//       <o1.0..1>   nBLE0: nBLE0/PM4 Assignment <0=> nBLE0 <1=> PM4
;//     </h>
;//     <h> Resistor Configuration Control 15 Register (RESCTL15)
;//       <o2.0..1>   nBLE0: nBLE0/PM4 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//     </h>
;//   </e>
IOCFG15_SETUP   EQU     0
MUXCTL15_Val    EQU     0x00000000
RESCTL15_Val    EQU     0x00000002

;//   <e> Configuration 17
;//     <h> Resistor Configuration Control 17 Register (RESCTL17)
;//       <o1.0..1> SDCLK: SDCLK Resistor Assignment
;//         <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//     </h>
;//   </e>
IOCFG17_SETUP   EQU     0
RESCTL17_Val    EQU     0x00000001

;//   <e> Configuration 19
;//     <h> Multiplexing Control 19 Register (MUXCTL19)
;//       <o1.14..15> PE7: PE7/nWAIT/nDEOT Assignment     <0=> PE7  <1=> nWAIT    <2=> nDEOT
;//       <o1.12..13> PE6: PE6/LCDVEEN/LCDMOD Assignment  <0=> PE6  <1=> LCDVEEN  <2=> LCDMOD
;//       <o1.10..11> PL7: PL7/D31 Assignment             <0=> PL7  <1=> D31
;//       <o1.8..9>   PE5: PE5/LCDVDDEN Assignment        <0=> PE5  <1=> LCDVDDEN
;//       <o1.6..7>   PL6: PL6/D30 Assignment             <0=> PL6  <1=> D30
;//       <o1.4..5>   PE4: PE4/LCDSPLEN/LCDREV Assignment <0=> PE4  <1=> LCDSPLEN <2=> LCDREV
;//       <o1.2..3>   PE3: PE3/LCDCLS Assignment          <0=> PE3  <1=> LCDCLS
;//       <o1.0..1>   PL5: PL5/D29 Assignment             <0=> PL5  <1=> D29
;//     </h>
;//     <h> Resistor Configuration Control 19 Register (RESCTL19)
;//       <o2.14..15> PE7: PE7/nWAIT/nDEOT Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.12..13> PE6: PE6/LCDVEEN/LCDMOD Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.10..11> PL7: PL7/D31 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.8..9>   PE5: PE5/LCDVDDEN Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.6..7>   PL6: PL6/D30 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.4..5>   PE4: PE4/LCDSPLEN/LCDREV Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.2..3>   PE3: PE3/LCDCLS Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.0..1>   PL5: PL5/D29 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//     </h>
;//   </e>
IOCFG19_SETUP   EQU     1
MUXCTL19_Val    EQU     0x00000441
RESCTL19_Val    EQU     0x00000000

;//   <e> Configuration 20
;//     <h> Multiplexing Control 20 Register (MUXCTL20)
;//       <o1.14..15> PE2: PE2/LCDPS Assignment         <0=> PE2  <1=> LCDPS
;//       <o1.12..13> PL4: PL4/D28 Assignment           <0=> PL4  <1=> D28
;//       <o1.10..11> PE1: PE1/LCDDCLK Assignment       <0=> PE1  <1=> LCDDCLK
;//       <o1.8..9>   PN1: PN1/D27 Assignment           <0=> PN1  <1=> D27
;//       <o1.6..7>   PE0: PE0/LCDLP/LCDHRLP Assignment <0=> PE0  <1=> LCDLP <2=> LCDHRLP
;//       <o1.4..5>   PN0: PN0/D26 Assignment           <0=> PN0  <1=> D26
;//       <o1.2..3>   PF7: PF7/LCDFP/LCDSPS Assignment  <0=> PF7  <1=> LCDFP <2=> LCDSPS
;//       <o1.0..1>   PF6: PF6/LCDEN/LCDSPL Assignment  <0=> PF6  <1=> LCDEN <2=> LCDSPL
;//     </h>
;//     <h> Resistor Configuration Control 20 Register (RESCTL20)
;//       <o2.14..15> PE2: PE2/LCDPS Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.12..13> PL4: PL4/D28 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.10..11> PE1: PE1/LCDDCLK Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.8..9>   PN1: PN1/D27 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.6..7>   PE0: PE0/LCDLP/LCDHRLP Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.4..5>   PN0: PN0/D26 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.2..3>   PF7: PF7/LCDFP/LCDSPS Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.0..1>   PF6: PF6/LCDEN/LCDSPL Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//     </h>
;//   </e>
IOCFG20_SETUP   EQU     1
MUXCTL20_Val    EQU     0x00001110
RESCTL20_Val    EQU     0x00000000

;//   <e> Configuration 21
;//     <h> Multiplexing Control 21 Register (MUXCTL21)
;//       <o1.10..11> PF5: PF5/LCDVD11 Assignment <0=> PF5  <1=> LCDVD11
;//       <o1.8..9>   PL3: PL3/LCDVD13 Assignment <0=> PL3  <1=> LCDVD13
;//       <o1.6..7>   PF4: PF4/LCDVD10 Assignment <0=> PF4  <1=> LCDVD10
;//       <o1.4..5>   PL2: PL2/LCDVD12 Assignment <0=> PL2  <1=> LCDVD12
;//       <o1.2..3>   PF3: PF3/LCDVD9 Assignment  <0=> PF3  <1=> LCDVD9
;//       <o1.0..1>   PF2: PF2/LCDVD8 Assignment  <0=> PF2  <1=> LCDVD8
;//     </h>
;//     <h> Resistor Configuration Control 21 Register (RESCTL21)
;//       <o2.10..11> PF5: PF5/LCDVD11 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.8..9>   PL3: PL3/LCDVD13 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.6..7>   PF4: PF4/LCDVD10 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.4..5>   PL2: PL2/LCDVD12 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.2..3>   PF3: PF3/LCDVD9 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.0..1>   PF2: PF2/LCDVD8 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//     </h>
;//   </e>
IOCFG21_SETUP   EQU     0
MUXCTL21_Val    EQU     0x00000000
RESCTL21_Val    EQU     0x00000555

;//   <e> Configuration 22
;//     <h> Multiplexing Control 22 Register (MUXCTL22)
;//       <o1.14..15> PF1: PF1/LCDVD7 Assignment        <0=> PF1  <1=> LCDVD7
;//       <o1.12..13> PF0: PF0/LCDVD6 Assignment        <0=> PF0  <1=> LCDVD6
;//       <o1.10..11> PG7: PG7/LCDVD5 Assignment        <0=> PG7  <1=> LCDVD5
;//       <o1.8..9>   PG6: PG6/LCDVD4 Assignment        <0=> PG6  <1=> LCDVD4
;//       <o1.6..7>   PG5: PG5/LCDVD3 Assignment        <0=> PG5  <1=> LCDVD3
;//       <o1.4..5>   PG4: PG4/LCDVD2 Assignment        <0=> PG4  <1=> LCDVD2
;//       <o1.2..3>   PG3: PG3/LCDVD1 Assignment        <0=> PG3  <1=> LCDVD1
;//       <o1.0..1>   PG2: PG2/LCDVD0 Assignment        <0=> PG2  <1=> LCDVD0
;//     </h>
;//     <h> Resistor Configuration Control 22 Register (RESCTL22)
;//       <o2.14..15> PF1: PF1/LCDVD7 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.12..13> PF0: PF0/LCDVD6 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.10..11> PG7: PG7/LCDVD5 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.8..9>   PG6: PG6/LCDVD4 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.6..7>   PG5: PG5/LCDVD3 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.4..5>   PG4: PG4/LCDVD2 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.2..3>   PG3: PG3/LCDVD1 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.0..1>   PG2: PG2/LCDVD0 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//     </h>
;//   </e>
IOCFG22_SETUP   EQU     0
MUXCTL22_Val    EQU     0x00000000
RESCTL22_Val    EQU     0x00005555

;//   <e> Configuration 23
;//     <h> Multiplexing Control 23 Register (MUXCTL23)
;//       <o1.14..15> PG1: PG1/ETHERTXCLK Assignment <0=> PG1  <1=> ETHERTXCLK
;//       <o1.12..13> PG0: PG0/ETHERTXEN Assignment  <0=> PG0  <1=> ETHERTXEN
;//       <o1.10..11> PH7: PH7/ETHERTX3 Assignment   <0=> PH7  <1=> ETHERTX3
;//       <o1.8..9>   PH6: PH6/ETHERTX2 Assignment   <0=> PH6  <1=> ETHERTX2
;//       <o1.6..7>   PH5: PH5/ETHERTX1 Assignment   <0=> PH5  <1=> ETHERTX1
;//       <o1.4..5>   PH4: PH4/ETHERTX0 Assignment   <0=> PH4  <1=> ETHERTX0
;//       <o1.2..3>   PH3: PH3/ETHERTXER Assignment  <0=> PH3  <1=> ETHERTXER
;//       <o1.0..1>   PH2: PH2/ETHERRXCLK Assignment <0=> PH2  <1=> ETHERRXCLK
;//     </h>
;//     <h> Resistor Configuration Control 23 Register (RESCTL23)
;//       <o2.14..15> PG1: PG1/ETHERTXCLK Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.12..13> PG0: PG0/ETHERTXEN Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.10..11> PH7: PH7/ETHERTX3 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.8..9>   PH6: PH6/ETHERTX2 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.6..7>   PH5: PH5/ETHERTX1 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.4..5>   PH4: PH4/ETHERTX0 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.2..3>   PH3: PH3/ETHERTXER Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.0..1>   PH2: PH2/ETHERRXCLK Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//     </h>
;//   </e>
IOCFG23_SETUP   EQU     0
MUXCTL23_Val    EQU     0x00000000
RESCTL23_Val    EQU     0x00005555

;//   <e> Configuration 24
;//     <h> Multiplexing Control 24 Register (MUXCTL24)
;//       <o1.12..13> PH1: PH1/ETHERRXDV Assignment  <0=> PH1  <1=> ETHERRXDV
;//       <o1.10..11> PH0: PH0/ETHERRX3 Assignment   <0=> PH0  <1=> ETHERRX3
;//       <o1.8..9>   PI7: PI7/ETHERRX2 Assignment   <0=> PI7  <1=> ETHERRX2
;//       <o1.6..7>   PI6: PI6/ETHERRX1 Assignment   <0=> PI6  <1=> ETHERRX1
;//       <o1.4..5>   PI5: PI5/ETHERRX0 Assignment   <0=> PI5  <1=> ETHERRX0
;//       <o1.2..3>   PI4: PI4/ETHERRXER Assignment  <0=> PI4  <1=> ETHERRXER
;//       <o1.0..1>   PI3: PI3/ETHERCRS Assignment   <0=> PI3  <1=> ETHERCRS
;//     </h>
;//     <h> Resistor Configuration Control 24 Register (RESCTL24)
;//       <o2.12..13> PH1: PH1/ETHERRXDV Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.10..11> PH0: PH0/ETHERRX3 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.8..9>   PI7: PI7/ETHERRX2 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.6..7>   PI6: PI6/ETHERRX1 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.4..5>   PI5: PI5/ETHERRX0 Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.2..3>   PI4: PI4/ETHERRXER Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//       <o2.0..1>   PI3: PI3/ETHERCRS Resistor Assignment
;//                   <0=> No pull-down or pull-up  <1=> Pull-down  <2=> Pull-up
;//     </h>
;//   </e>
IOCFG24_SETUP   EQU     0
MUXCTL24_Val    EQU     0x00000000
RESCTL24_Val    EQU     0x00001555

;//   <e> Configuration 25
;//     <h> Multiplexing Control 25 Register (MUXCTL25)
;//       <o1.14..15> AN6: AN6/PJ7/INT7 Assignment   <0=> AN6       <1=> PJ7  <2=> INT7
;//       <o1.12..13> AN7: AN7/PJ6/INT6 Assignment   <0=> AN7       <1=> PJ6  <2=> INT6
;//       <o1.10..11> AN5: AN5/PJ5/INT5 Assignment   <0=> AN5       <1=> PJ5  <2=> INT5
;//       <o1.8..9>   AN8: AN8/PJ4 Assignment        <0=> AN8       <1=> PJ4
;//       <o1.6..7>   AN2: AN2/LLY/Y+/PJ3 Assignment <0=> AN2/LL/Y+ <1=> PJ3
;//       <o1.4..5>   AN9: AN9/PJ2 Assignment        <0=> AN9       <1=> PJ2
;//       <o1.2..3>   AN4: AN4/WIPER/PJ1 Assignment  <0=> AN4/WIPER <1=> PJ1
;//       <o1.0..1>   AN3: AN3/LR/Y-/PJ0 Assignment  <0=> AN3/LR/Y- <1=> PJ0
;//     </h>
;//   </e>
IOCFG25_SETUP   EQU     0
MUXCTL25_Val    EQU     0x00000000

;// </e> I/O Configuration


;----------------------- External Memory Controller (EMC) Definitons -----------

; External Memory Controller (EMC) User Interface
EMC_BASE            EQU 0xFFFF1000      ; EMC Base Address

EMC_CONTROL_OFS     EQU 0x000
EMC_STATUS_OFS      EQU 0x004
EMC_CONFIG_OFS      EQU 0x008
EMC_DYNMCTRL_OFS    EQU 0x020
EMC_DYNMREF_OFS     EQU 0x024
EMC_DYNMRCON_OFS    EQU 0x028
EMC_PRECHARGE_OFS   EQU 0x030
EMC_DYNM2PRE_OFS    EQU 0x034
EMC_REFEXIT_OFS     EQU 0x038
EMC_DOACTIVE_OFS    EQU 0x03C
EMC_DIACTIVE_OFS    EQU 0x040
EMC_DWRT_OFS        EQU 0x044
EMC_DYNACTCMD_OFS   EQU 0x048
EMC_DYNAUTO_OFS     EQU 0x04C
EMC_DYNREFEXIT_OFS  EQU 0x050
EMC_DYNACTIVEAB_OFS EQU 0x054
EMC_DYNAMICMRD_OFS  EQU 0x058
EMC_WAIT_OFS        EQU 0x080
EMC_DYNCFG0_OFS     EQU 0x100
EMC_DYNRASCAS0_OFS  EQU 0x104
EMC_DYNCFG1_OFS     EQU 0x120
EMC_DYNRASCAS1_OFS  EQU 0x124
EMC_SCONFIG0_OFS    EQU 0x200
EMC_SWAITWEN0_OFS   EQU 0x204
EMC_SWAITOEN0_OFS   EQU 0x208
EMC_SWAITRD0_OFS    EQU 0x20C
EMC_SWAITPAGE0_OFS  EQU 0x210
EMC_SWAITWR0_OFS    EQU 0x214
EMC_STURN0_OFS      EQU 0x218
EMC_SCONFIG1_OFS    EQU 0x220
EMC_SWAITWEN1_OFS   EQU 0x224
EMC_SWAITOEN1_OFS   EQU 0x228
EMC_SWAITRD1_OFS    EQU 0x22C
EMC_SWAITPAGE1_OFS  EQU 0x230
EMC_SWAITWR1_OFS    EQU 0x234
EMC_STURN1_OFS      EQU 0x238
EMC_SCONFIG2_OFS    EQU 0x240
EMC_SWAITWEN2_OFS   EQU 0x244
EMC_SWAITOEN2_OFS   EQU 0x248
EMC_SWAITRD2_OFS    EQU 0x24C
EMC_SWAITPAGE2_OFS  EQU 0x250
EMC_SWAITWR2_OFS    EQU 0x254
EMC_STURN2_OFS      EQU 0x258
EMC_SCONFIG3_OFS    EQU 0x260
EMC_SWAITWEN3_OFS   EQU 0x264
EMC_SWAITOEN3_OFS   EQU 0x268
EMC_SWAITRD3_OFS    EQU 0x26C
EMC_SWAITPAGE3_OFS  EQU 0x270
EMC_SWAITWR3_OFS    EQU 0x274
EMC_STURN3_OFS      EQU 0x278

SDRAM0_MODE_REG     EQU 0x20011000      ; SDRAM0 Mode Register Address
SDRAM1_MODE_REG     EQU 0x30011000      ; SDRAM1 Mode Register Address

; Constants
NORMAL_CMD          EQU (0x0 << 7)      ; NORMAL        Command
MODE_CMD            EQU (0x1 << 7)      ; MODE          Command
PALL_CMD            EQU (0x2 << 7)      ; Precharge All Command
NOP_CMD             EQU (0x3 << 7)      ; NOP           Command

BUF_EN_BIT          EQU (1 << 19)       ; Buffer enable Bit
CS_BIT              EQU (1 << 1)        ; Dynamic Memory Clock Select Bit
CE_BIT              EQU (1 << 0)        ; Dynamic Memory Clock Enable Bit

;//     External Memory Controller Configuration (EMC) -------------------------
;// <e> External Memory Controller Configuration (EMC)
EMC_SETUP           EQU 1

;//   <h> EMC Control Register (CONTROL)
;//     <i> Controls operation of the memory controller
;//     <o0.2> MODE: Low-power Mode Enable
;//     <o0.0> ENABLE: EMC Enable
;//   </h>
EMC_CONTROL_Val     EQU 0x00000001

;//   <h> EMC Configuration Register (CONFIG)
;//     <i> Configures operation of the memory controller
;//     <o0.8> CCLK: CLKOUT ratio
;//                     <0=> 1:1
;//                     <1=> 1:2
;//     <o0.0> Endian mode
;//                     <0=> Little-endian
;//                     <1=> Big-endian
;//   </h>
EMC_CONFIG_Val      EQU 0x00000000

;//       Dynamic Memory Interface Configuration -------------------------------
;//   <e> Dynamic Memory Interface Configuration
EMC_DYN_SETUP       EQU 1

;//     <h> Dynamic Memory Refresh Timer Register (DYNMREF)
;//       <i> Configures dynamic memory refresh operation
;//       <o0.0..10> REFRESH: Refresh Timer <0x000-0x7FF>
;//         <i> 0 = Refresh disabled, 0x001-0x7FF: value * 16 HCLK cycles
;//     </h>
EMC_DYNMREF_Val     EQU 0x00000018

;//     <h> Dynamic Memory Read Configuration Register (DYNMRCON)
;//       <i> Configures the dynamic memory read strategy
;//       <o0.0..1> RDS: Read Data Strategy
;//                     <1=> Command delayed strategy
;//     </h>
EMC_DYNMRCON_Val    EQU 0x00000001

;//     <h> Dynamic Memory Precharge Command Period Register (PRECHARGE)
;//       <o0.0..3> tRP: Precharge Command Period <1-16> <#-1>
;//         <i> The delay is in EMCCLK cycles
;//         <i> This value is normally found in SDRAM data sheets as tRP
;//     </h>
;//     <h> Dynamic Memory Active to Precharge Command Period Register (DYNM2PRE)
;//       <o1.0..3> tRAS: Active to Precharge Command Period <1-16> <#-1>
;//         <i> The delay is in EMCCLK cycles
;//         <i> This value is normally found in SDRAM data sheets as tRAS
;//     </h>
;//     <h> Dynamic Memory Self-refresh Exit Time Register (REFEXIT)
;//       <o2.0..3> tSREX: Self-refresh Exit Time <1-16> <#-1>
;//         <i> The delay is in EMCCLK cycles
;//         <i> This value is normally found in SDRAM data sheets as tSREX, 
;//         <i> for devices without this parameter you use the same value as tXSR
;//     </h>
;//     <h> Dynamic Memory Last Data Out to Active Time Register (DOACTIVE)
;//       <o3.0..3> tAPR: Last-data-out to Active Command Time <1-16> <#-1>
;//         <i> The delay is in EMCCLK cycles
;//         <i> This value is normally found in SDRAM data sheets as tAPR
;//     </h>
;//     <h> Dynamic Memory Data-in to Active Command Time Register (DIACTIVE)
;//       <o4.0..3> tDAL: Data-in to Active Command Time <1-16> <#-1>
;//         <i> The delay is in EMCCLK cycles
;//         <i> This value is normally found in SDRAM data sheets as tDAL or tAPW
;//     </h>
;//     <h> Dynamic Memory Write Recovery Time Register (DWRT)
;//       <o5.0..3> tWR: Write Recovery Time <1-16> <#-1>
;//         <i> The delay is in EMCCLK cycles
;//         <i> This value is normally found in SDRAM data sheets as tWR, tDPL, tRWL, or tRDL
;//     </h>
;//     <h> Dynamic Memory Active to Active Command Period Register (DYNACTCMD)
;//       <o6.0..4> tRC: Active to Active Command Period <1-32> <#-1>
;//         <i> The delay is in EMCCLK cycles
;//         <i> This value is normally found in SDRAM data sheets as tRC
;//     </h>
;//     <h> Dynamic Memory Auto-refresh Period Register (DYNAUTO)
;//       <o7.0..4> tRFC: Auto-refresh Period and Auto-refresh to Active Command Period <1-32> <#-1>
;//         <i> The delay is in EMCCLK cycles
;//         <i> This value is normally found in SDRAM data sheets as tRFC or  tRC
;//     </h>
;//     <h> Dynamic Memory Exit Self-refresh Register (DYNREFEXIT)
;//       <o8.0..4> tXSR: Exit Self-refresh to Active Command Time <1-32> <#-1>
;//         <i> The delay is in EMCCLK cycles
;//         <i> This value is normally found in SDRAM data sheets as tXSR
;//     </h>
;//     <h> Dynamic Memory Active Bank A to Active Bank B Time Register (DYNACTIVEAB)
;//       <o9.0..3> tRRD: Active Bank A to Active Bank B Latency <1-16> <#-1>
;//         <i> The delay is in EMCCLK cycles
;//         <i> This value is normally found in SDRAM data sheets as tRRD
;//     </h>
;//     <h> Dynamic Memory Load Mode Register to Active Command Time (DYNAMICMRD)
;//       <o10.0..3> tMRD: Load Mode Register to Active Command Time <1-16> <#-1>
;//         <i> The delay is in EMCCLK cycles
;//         <i> This value is normally found in SDRAM data sheets as tMRD or tRSA
;//     </h>
EMC_PRECHARGE_Val   EQU 0x00000001
EMC_DYNM2PRE_Val    EQU 0x00000003
EMC_REFEXIT_Val     EQU 0x00000006
EMC_DOACTIVE_Val    EQU 0x00000006
EMC_DIACTIVE_Val    EQU 0x00000006
EMC_DWRT_Val        EQU 0x00000002
EMC_DYNACTCMD_Val   EQU 0x00000006
EMC_DYNAUTO_Val     EQU 0x00000006
EMC_DYNREFEXIT_Val  EQU 0x00000006
EMC_DYNACTIVEAB_Val EQU 0x00000002
EMC_DYNAMICMRD_Val  EQU 0x00000002

;//         Configure External Bus Behaviour for Dynamic nDCS0 Area ------------
;//     <e> Configure External Bus Behaviour for Dynamic nDCS0 Area
EMC_DYNAMIC0_SETUP  EQU 1

;//       <h> Dynamic Memory Configuration Register (DYNCFG0)
;//         <i> Defines the configuration information for the dynamic memory nDCS0
;//         <o0.20> P: Write Protect
;//         <o0.19> B: Read and Write Buffer Enable
;//         <o0.14> AM 14: External Bus Data Width
;//                     <0=> 16 bit
;//                     <1=> 32 bit
;//         <o0.12> AM 12: External Bus Memory Type
;//                     <0=> High-performance
;//                     <1=> Low-power SDRAM
;//         <o0.9..11> AM11..9: SDRAM Size
;//                     <0=>  16Mb
;//                     <1=>  64Mb
;//                     <2=> 128Mb
;//                     <3=> 256Mb
;//                     <4=> 512Mb
;//         <o0.7..8> AM8..7: SDRAM Organization
;//           <i>  Example: 64Mb = 2M x "32", 256Mb = 32M x "8"
;//                     <0=> x8
;//                     <1=> x16
;//                     <2=> x32
;//         <o0.3..4> MD: Memory Device
;//                     <0=> SDRAM
;//                     <1=> Low-power SDRAM
;//                     <2=> Micron SyncFlash
;//       </h>
EMC_DYNCFG0_Val     EQU 0x00085480

;//       <h> Dynamic Memory RAS & CAS Delay Register (DYNRASCAS0)
;//         <i> Controls the RAS and CAS latencies for the dynamic memory nDCS0
;//         <o0.8..9> CAS: CAS Latency
;//                     <1=> One CCLK cycle
;//                     <2=> Two CCLK cycles
;//                     <3=> Three CCLK cycles
;//         <o0.0..1> RAS: RAS Latency
;//                     <1=> One CCLK cycle
;//                     <2=> Two CCLK cycles
;//                     <3=> Three CCLK cycles
;//       </h>
EMC_DYNRASCAS0_Val  EQU 0x00000203

;//     </e> End of Configure External Bus Behaviour for Dynamic nDCS0 Area

;//         Configure External Bus Behaviour for Dynamic nDCS1 Area ------------
;//     <e> Configure External Bus Behaviour for Dynamic nDCS1 Area
EMC_DYNAMIC1_SETUP  EQU 0

;//       <h> Dynamic Memory Configuration Register (DYNCFG1)
;//         <i> Defines the configuration information for the dynamic memory nDCS1
;//         <o0.20> P: Write Protect
;//         <o0.19> B: Read and Write Buffer Enable
;//         <o0.14> AM 14: External Bus Data Width
;//                     <0=> 16 bit
;//                     <1=> 32 bit
;//         <o0.12> AM 12: External Bus Memory Type
;//                     <0=> High-performance
;//                     <1=> Low-power SDRAM
;//         <o0.9..11> AM11..9: SDRAM Size
;//                     <0=>  16Mb
;//                     <1=>  64Mb
;//                     <2=> 128Mb
;//                     <3=> 256Mb
;//                     <4=> 512Mb
;//         <o0.7..8> AM8..7: SDRAM Organization
;//           <i>  Example: 64Mb = 2M x "32", 256Mb = 32M x "8"
;//                     <0=> x8
;//                     <1=> x16
;//                     <2=> x32
;//         <o0.3..4> MD: Memory Device
;//                     <0=> SDRAM
;//                     <1=> Low-power SDRAM
;//                     <2=> Micron SyncFlash
;//       </h>
EMC_DYNCFG1_Val     EQU 0x00085680

;//       <h> Dynamic Memory RAS & CAS Delay Register (DYNRASCAS1)
;//         <i> Controls the RAS and CAS latencies for the dynamic memory nDCS1
;//         <o0.8..9> CAS: CAS Latency
;//                     <1=> One CCLK cycle
;//                     <2=> Two CCLK cycles
;//                     <3=> Three CCLK cycles
;//         <o0.0..1> RAS: RAS Latency
;//                     <1=> One CCLK cycle
;//                     <2=> Two CCLK cycles
;//                     <3=> Three CCLK cycles
;//       </h>
EMC_DYNRASCAS1_Val  EQU 0x00000203

;//     </e> End of Configure External Bus Behaviour for Dynamic nDCS1 Area

;//   </e> End of Dynamic Memory Interface Configuration

;//       Static Memory Interface Configuration --------------------------------
;//   <e> Static Memory Interface Configuration
EMC_STA_SETUP       EQU 1

;//     <h> Static Memory Extended Wait Register (WAIT)
;//       <i> Is used to time long static memory read and write transfers
;//       <o0.0..9> WAIT: External Wait Time Out
;//         <i> (value + 1) * 16 HCLK cycles <0-1023>
;//     </h>
EMC_WAIT_Val        EQU 0x00000000

;//         Configure External Bus Behaviour for Static nCS0 Area --------------
;//     <e> Configure External Bus Behaviour for Static nCS0 Area
EMC_STATIC0_SETUP   EQU 1

;//       <h> Static Memory Configuration Register (SCONFIG0)
;//         <i> Defines the configuration information for the static memory nCS0
;//         <o0.20> WP: Write Protect
;//         <o0.19> B: Read and Write Buffer Enable
;//         <o0.8> EW: Extended Wait Enable
;//         <o0.7> BLS: Byte Lane State
;//                     <0=> For reads nBLE are HIGH, for writes nBLE are HIGH
;//                     <1=> For reads nBLE are LOW, for writes nBLE are LOW
;//         <o0.6> PC: Chip Select Polarity
;//                     <0=> Active LOW chip select
;//                     <1=> Active HIGH chip select
;//         <o0.3> PM: Page Mode Enable
;//         <o0.0..1> MW: Memory Width
;//                     <0=> 8 bit
;//                     <1=> 16 bit
;//                     <2=> 32 bit
;//       </h>
EMC_SCONFIG0_Val    EQU 0x00000002

;//       <h> Static Memory Write Enable Delay Register (SWAITWEN0)
;//         <i> Selects the delay from nCS0 to write enable
;//         <o.0..3> WAITWEN: Wait Write Enable <0-15>
;//       </h>
EMC_SWAITWEN0_Val   EQU 0x0000000C

;//       <h> Static Memory Output Enable Delay register (SWAITOEN0)
;//         <i> Selects the delay from nCS0 or address change, whichever is later, to output enable
;//         <o.0..3> WAITOEN: Wait Output Enable <0-15>
;//       </h>
EMC_SWAITOEN0_Val   EQU 0x0000000C
                                      
;//       <h> Static Memory Read Delay Register (SWAITRD0)
;//         <i> Selects the delay from nCS0 to a read access
;//         <o.0..4> WAITRD: Non-page Mode Read Wait States or Asynchronous Page Mode Read First Access Wait Atates <1-32> <#-1>
;//           <i> The delay is in HCLK cycles
;//       </h>
EMC_SWAITRD0_Val    EQU 0x0000000C

;//       <h> Static Memory Page Mode Read Delay Register (SWAITPAGE0)
;//         <i> Selects the delay for asynchronous page mode sequential accesses for nCS0
;//         <o.0..4> WAITPAGE: Asynchronous Page Mode Read After the First Read Wait States <1-32> <#-1>
;//           <i> The delay is in HCLK cycles
;//       </h>
EMC_SWAITPAGE0_Val  EQU 0x0000000C

;//       <h> Static Memory Write Delay Register (SWAITWR0)
;//         <i> Selects the delay from nCS0 to a write access
;//         <o.0..4> WAITWR: Write Wait States <0-31>
;//       </h>
EMC_SWAITWR0_Val    EQU 0x0000000C

;//       <h> Static Memory Turn Round Delay Register (STURN0)
;//         <i> Selects the number of bus turnaround cycles for nCS0
;//         <o.0..4> BTC: Bus Turnaround Cycles <1-16> <#-1>
;//           <i> The delay is in HCLK cycles
;//       </h>
EMC_STURN0_Val      EQU 0x0000000C

;//     </e> End of Configure External Bus Behaviour for Static nCS0 Area

;//         Configure External Bus Behaviour for Static nCS1 Area --------------
;//     <e> Configure External Bus Behaviour for Static nCS1 Area
EMC_STATIC1_SETUP   EQU 1

;//       <h> Static Memory Configuration Register (SCONFIG1)
;//         <i> Defines the configuration information for the static memory nCS1
;//         <o0.20> WP: Write Protect
;//         <o0.19> B: Read and Write Buffer Enable
;//         <o0.8> EW: Extended Wait Enable
;//         <o0.7> BLS: Byte Lane State
;//                     <0=> For reads nBLE are HIGH, for writes nBLE are HIGH
;//                     <1=> For reads nBLE are LOW, for writes nBLE are LOW
;//         <o0.6> PC: Chip Select Polarity
;//                     <0=> Active LOW chip select
;//                     <1=> Active HIGH chip select
;//         <o0.3> PM: Page Mode Enable
;//         <o0.0..1> MW: Memory Width
;//                     <0=> 8 bit
;//                     <1=> 16 bit
;//                     <2=> 32 bit
;//       </h>
EMC_SCONFIG1_Val    EQU 0x00000081

;//       <h> Static Memory Write Enable Delay Register (SWAITWEN1)
;//         <i> Selects the delay from nCS1 to write enable
;//         <o.0..3> WAITWEN: Wait Write Enable <0-15>
;//       </h>
EMC_SWAITWEN1_Val   EQU 0x00000001

;//       <h> Static Memory Output Enable Delay register (SWAITOEN1)
;//         <i> Selects the delay from nCS1 or address change, whichever is later, to output enable
;//         <o.0..3> WAITOEN: Wait Output Enable <0-15>
;//       </h>
EMC_SWAITOEN1_Val   EQU 0x00000001
                                      
;//       <h> Static Memory Read Delay Register (SWAITRD0)
;//         <i> Selects the delay from nCS1 to a read access
;//         <o.0..4> WAITRD: Non-page Mode Read Wait States or Asynchronous Page Mode Read First Access Wait Atates <1-32> <#-1>
;//           <i> The delay is in HCLK cycles
;//       </h>
EMC_SWAITRD1_Val    EQU 0x00000006

;//       <h> Static Memory Page Mode Read Delay Register (SWAITPAGE1)
;//         <i> Selects the delay for asynchronous page mode sequential accesses for nCS1
;//         <o.0..4> WAITPAGE: Asynchronous Page Mode Read After the First Read Wait States <1-32> <#-1>
;//           <i> The delay is in HCLK cycles
;//       </h>
EMC_SWAITPAGE1_Val  EQU 0x00000002

;//       <h> Static Memory Write Delay Register (SWAITWR1)
;//         <i> Selects the delay from nCS1 to a write access
;//         <o.0..4> WAITWR: Write Wait States <0-31>
;//       </h>
EMC_SWAITWR1_Val    EQU 0x00000006

;//       <h> Static Memory Turn Round Delay Register (STURN1)
;//         <i> Selects the number of bus turnaround cycles for nCS1
;//         <o.0..4> BTC: Bus Turnaround Cycles <1-16> <#-1>
;//           <i> The delay is in HCLK cycles
;//       </h>
EMC_STURN1_Val      EQU 0x00000002

;//     </e> End of Configure External Bus Behaviour for Static nCS1 Area

;//         Configure External Bus Behaviour for Static nCS2 Area --------------
;//     <e> Configure External Bus Behaviour for Static nCS2 Area
EMC_STATIC2_SETUP   EQU 1

;//       <h> Static Memory Configuration Register (SCONFIG2)
;//         <i> Defines the configuration information for the static memory nCS2
;//         <o0.20> WP: Write Protect
;//         <o0.19> B: Read and Write Buffer Enable
;//         <o0.8> EW: Extended Wait Enable
;//         <o0.7> BLS: Byte Lane State
;//                     <0=> For reads nBLE are HIGH, for writes nBLE are HIGH
;//                     <1=> For reads nBLE are LOW, for writes nBLE are LOW
;//         <o0.6> PC: Chip Select Polarity
;//                     <0=> Active LOW chip select
;//                     <1=> Active HIGH chip select
;//         <o0.3> PM: Page Mode Enable
;//         <o0.0..1> MW: Memory Width
;//                     <0=> 8 bit
;//                     <1=> 16 bit
;//                     <2=> 32 bit
;//       </h>
EMC_SCONFIG2_Val    EQU 0x00000081

;//       <h> Static Memory Write Enable Delay Register (SWAITWEN2)
;//         <i> Selects the delay from nCS2 to write enable
;//         <o.0..3> WAITWEN: Wait Write Enable <0-15>
;//       </h>
EMC_SWAITWEN2_Val   EQU 0x00000002

;//       <h> Static Memory Output Enable Delay register (SWAITOEN2)
;//         <i> Selects the delay from nCS2 or address change, whichever is later, to output enable
;//         <o.0..3> WAITOEN: Wait Output Enable <0-15>
;//       </h>
EMC_SWAITOEN2_Val   EQU 0x00000002
                                      
;//       <h> Static Memory Read Delay Register (SWAITRD2)
;//         <i> Selects the delay from nCS2 to a read access
;//         <o.0..4> WAITRD: Non-page Mode Read Wait States or Asynchronous Page Mode Read First Access Wait Atates <1-32> <#-1>
;//           <i> The delay is in HCLK cycles
;//       </h>
EMC_SWAITRD2_Val    EQU 0x00000010

;//       <h> Static Memory Page Mode Read Delay Register (SWAITPAGE2)
;//         <i> Selects the delay for asynchronous page mode sequential accesses for nCS2
;//         <o.0..4> WAITPAGE: Asynchronous Page Mode Read After the First Read Wait States <1-32> <#-1>
;//           <i> The delay is in HCLK cycles
;//       </h>
EMC_SWAITPAGE2_Val  EQU 0x00000002

;//       <h> Static Memory Write Delay Register (SWAITWR2)
;//         <i> Selects the delay from nCS2 to a write access
;//         <o.0..4> WAITWR: Write Wait States <0-31>
;//       </h>
EMC_SWAITWR2_Val    EQU 0x0000000E

;//       <h> Static Memory Turn Round Delay Register (STURN2)
;//         <i> Selects the number of bus turnaround cycles for nCS2
;//         <o.0..4> BTC: Bus Turnaround Cycles <1-16> <#-1>
;//           <i> The delay is in HCLK cycles
;//       </h>
EMC_STURN2_Val      EQU 0x00000002

;//     </e> End of Configure External Bus Behaviour for Static nCS2 Area

;//         Configure External Bus Behaviour for Static nCS3 Area --------------
;//     <e> Configure External Bus Behaviour for Static nCS3 Area
EMC_STATIC3_SETUP   EQU 1

;//       <h> Static Memory Configuration Register (SCONFIG3)
;//         <i> Defines the configuration information for the static memory nCS3
;//         <o0.20> WP: Write Protect
;//         <o0.19> B: Read and Write Buffer Enable
;//         <o0.8> EW: Extended Wait Enable
;//         <o0.7> BLS: Byte Lane State
;//                     <0=> For reads nBLE are HIGH, for writes nBLE are HIGH
;//                     <1=> For reads nBLE are LOW, for writes nBLE are LOW
;//         <o0.6> PC: Chip Select Polarity
;//                     <0=> Active LOW chip select
;//                     <1=> Active HIGH chip select
;//         <o0.3> PM: Page Mode Enable
;//         <o0.0..1> MW: Memory Width
;//                     <0=> 8 bit
;//                     <1=> 16 bit
;//                     <2=> 32 bit
;//       </h>
EMC_SCONFIG3_Val    EQU 0x00000081

;//       <h> Static Memory Write Enable Delay Register (SWAITWEN3)
;//         <i> Selects the delay from nCS3 to write enable
;//         <o.0..3> WAITWEN: Wait Write Enable <0-15>
;//       </h>
EMC_SWAITWEN3_Val   EQU 0x00000002

;//       <h> Static Memory Output Enable Delay register (SWAITOEN3)
;//         <i> Selects the delay from nCS3 or address change, whichever is later, to output enable
;//         <o.0..3> WAITOEN: Wait Output Enable <0-15>
;//       </h>
EMC_SWAITOEN3_Val   EQU 0x00000002
                                      
;//       <h> Static Memory Read Delay Register (SWAITRD3)
;//         <i> Selects the delay from nCS3 to a read access
;//         <o.0..4> WAITRD: Non-page Mode Read Wait States or Asynchronous Page Mode Read First Access Wait Atates <1-32> <#-1>
;//           <i> The delay is in HCLK cycles
;//       </h>
EMC_SWAITRD3_Val    EQU 0x00000005

;//       <h> Static Memory Page Mode Read Delay Register (SWAITPAGE3)
;//         <i> Selects the delay for asynchronous page mode sequential accesses for nCS3
;//         <o.0..4> WAITPAGE: Asynchronous Page Mode Read After the First Read Wait States <1-32> <#-1>
;//           <i> The delay is in HCLK cycles
;//       </h>
EMC_SWAITPAGE3_Val  EQU 0x00000002

;//       <h> Static Memory Write Delay Register (SWAITWR3)
;//         <i> Selects the delay from nCS3 to a write access
;//         <o.0..4> WAITWR: Write Wait States <0-31>
;//       </h>
EMC_SWAITWR3_Val    EQU 0x00000005

;//       <h> Static Memory Turn Round Delay Register (STURN3)
;//         <i> Selects the number of bus turnaround cycles for nCS3
;//         <o.0..4> BTC: Bus Turnaround Cycles <1-16> <#-1>
;//           <i> The delay is in HCLK cycles
;//       </h>
EMC_STURN3_Val      EQU 0x00000002

;//     </e> End of Configure External Bus Behaviour for Static nCS3 Area

;//   </e> End of Static Memory Interface Configuration

;// </e> End of External Memory Controller Configuration


;----------------------- Cache Definitions -------------------------------------

; Constants
ICACHE_EN_BIT   EQU     (1<<12)         ; Instruction Cache Enable Bit

;// <e> Instruction Cache Enable
;// </e>
ICACHE_SETUP    EQU     0


;----------------------- CODE --------------------------------------------------

                PRESERVE8
                

; Area Definition and Entry Point
;  Startup Code must be linked first at Address at which it expects to run.

                AREA    RESET, CODE, READONLY
                ARM

                IF      :DEF:__RTX
                IMPORT  SWI_Handler
                IMPORT  IRQ_Handler_RTX
                ENDIF

; Exception Vectors
;  Mapped to Address 0.
;  Absolute addressing mode must be used.
;  Dummy Handlers are implemented as infinite loops which can be modified.

Vectors         LDR     PC,Reset_Addr         
                LDR     PC,Undef_Addr
                LDR     PC,SWI_Addr
                LDR     PC,PAbt_Addr
                LDR     PC,DAbt_Addr
                NOP
                IF      :DEF:__RTX
                LDR     PC,IRQ_Addr     
                ELSE
                LDR     PC, [PC, #-0x0FF0]        ; Vector from VECTADDR
                ENDIF
                LDR     PC,FIQ_Addr

Reset_Addr      DCD     Reset_Handler
Undef_Addr      DCD     Undef_Handler
SWI_Addr        DCD     SWI_Handler
PAbt_Addr       DCD     PAbt_Handler
DAbt_Addr       DCD     DAbt_Handler
                DCD     0                         ; Reserved Address
                IF      :DEF:__RTX
IRQ_Addr        DCD     IRQ_Handler_RTX
                ENDIF
FIQ_Addr        DCD     FIQ_Handler

Undef_Handler   B       Undef_Handler
                IF      :DEF:__RTX
                ELSE
SWI_Handler     B       SWI_Handler
                ENDIF
PAbt_Handler    B       PAbt_Handler
DAbt_Handler    B       DAbt_Handler
FIQ_Handler     B       FIQ_Handler


; Reset Handler

                EXPORT  Reset_Handler
Reset_Handler   


; Clock Setup ------------------------------------------------------------------

                IF      CLOCK_SETUP != 0
                LDR     R0, =RCPC_BASE

                LDR     R1, =(CTRL_Val:OR:CTRL_LOCK_BIT)
                STR     R1, [R0, #CTRL_OFS]
                MOV     R1, #PCLKSEL0_Val
                STR     R1, [R0, #PCLKSEL0_OFS]
                MOV     R1, #PCLKSEL1_Val
                STR     R1, [R0, #PCLKSEL1_OFS]
                MOV     R1, #AHBCLKCTRL_Val
                STR     R1, [R0, #AHBCLKCTRL_OFS]
                LDR     R1, =PCLKCTRL0_Val
                STR     R1, [R0, #PCLKCTRL0_OFS]
                LDR     R1, =PCLKCTRL1_Val
                STR     R1, [R0, #PCLKCTRL1_OFS]
                LDR     R1, =SYSPLLCNTL_Val
                STR     R1, [R0, #SYSPLLCNTL_OFS]
                LDR     R1, =USBPLLCTL_Val
                STR     R1, [R0, #USBPLLCTL_OFS]
                MOV     R1, #SYSCLKPRE_Val
                STR     R1, [R0, #SYSCLKPRE_OFS]
                MOV     R1, #CPUCLKPRE_Val
                STR     R1, [R0, #CPUCLKPRE_OFS]
                MOV     R1, #LCDPRE_Val
                STR     R1, [R0, #LCDPRE_OFS]
                MOV     R1, #SSPPRE_Val
                STR     R1, [R0, #SSPPRE_OFS]
                MOV     R1, #ADCPRE_Val
                STR     R1, [R0, #ADCPRE_OFS]
                MOV     R1, #USBPRE_Val
                STR     R1, [R0, #USBPRE_OFS]
                MOV     R1, #CORECONFIG_Val
                STR     R1, [R0, #CORECONFIG_OFS]
                ENDIF   ; of IF      CLOCK_SETUP != 0


; IO Configuration Setup (IOCON) -----------------------------------------------

                IF      IOCON_SETUP != 0
                LDR     R0, =IOCON_BASE

                IF      IOCFG1_SETUP != 0
                LDR     R1, =MUXCTL1_Val
                STR     R1, [R0, #MUXCTL1_OFS]
                LDR     R1, =RESCTL1_Val
                STR     R1, [R0, #RESCTL1_OFS]
                ENDIF

                IF      IOCFG3_SETUP != 0
                LDR     R1, =MUXCTL3_Val
                STR     R1, [R0, #MUXCTL3_OFS]
                LDR     R1, =RESCTL3_Val
                STR     R1, [R0, #RESCTL3_OFS]
                ENDIF

                IF      IOCFG4_SETUP != 0
                LDR     R1, =MUXCTL4_Val
                STR     R1, [R0, #MUXCTL4_OFS]
                LDR     R1, =RESCTL4_Val
                STR     R1, [R0, #RESCTL4_OFS]
                ENDIF

                IF      IOCFG5_SETUP != 0
                LDR     R1, =MUXCTL5_Val
                STR     R1, [R0, #MUXCTL5_OFS]
                LDR     R1, =RESCTL5_Val
                STR     R1, [R0, #RESCTL5_OFS]
                ENDIF

                IF      IOCFG6_SETUP != 0
                LDR     R1, =MUXCTL6_Val
                STR     R1, [R0, #MUXCTL6_OFS]
                LDR     R1, =RESCTL6_Val
                STR     R1, [R0, #RESCTL6_OFS]
                ENDIF

                IF      IOCFG7_SETUP != 0
                LDR     R1, =MUXCTL7_Val
                STR     R1, [R0, #MUXCTL7_OFS]
                LDR     R1, =RESCTL7_Val
                STR     R1, [R0, #RESCTL7_OFS]
                ENDIF

                IF      IOCFG10_SETUP != 0
                LDR     R1, =MUXCTL10_Val
                STR     R1, [R0, #MUXCTL10_OFS]
                LDR     R1, =RESCTL10_Val
                STR     R1, [R0, #RESCTL10_OFS]
                ENDIF

                IF      IOCFG11_SETUP != 0
                LDR     R1, =MUXCTL11_Val
                STR     R1, [R0, #MUXCTL11_OFS]
                LDR     R1, =RESCTL11_Val
                STR     R1, [R0, #RESCTL11_OFS]
                ENDIF

                IF      IOCFG12_SETUP != 0
                LDR     R1, =MUXCTL12_Val
                STR     R1, [R0, #MUXCTL12_OFS]
                LDR     R1, =RESCTL12_Val
                STR     R1, [R0, #RESCTL12_OFS]
                ENDIF

                IF      IOCFG13_SETUP != 0
                LDR     R1, =RESCTL13_Val
                STR     R1, [R0, #RESCTL13_OFS]
                ENDIF

                IF      IOCFG14_SETUP != 0
                LDR     R1, =MUXCTL14_Val
                STR     R1, [R0, #MUXCTL14_OFS]
                ENDIF

                IF      IOCFG15_SETUP != 0
                LDR     R1, =MUXCTL15_Val
                STR     R1, [R0, #MUXCTL15_OFS]
                LDR     R1, =RESCTL15_Val
                STR     R1, [R0, #RESCTL15_OFS]
                ENDIF

                IF      IOCFG17_SETUP != 0
                LDR     R1, =MUXCTL17_Val
                STR     R1, [R0, #MUXCTL17_OFS]
                ENDIF

                IF      IOCFG19_SETUP != 0
                LDR     R1, =MUXCTL19_Val
                STR     R1, [R0, #MUXCTL19_OFS]
                LDR     R1, =RESCTL19_Val
                STR     R1, [R0, #RESCTL19_OFS]
                ENDIF

                IF      IOCFG20_SETUP != 0
                LDR     R1, =MUXCTL20_Val
                STR     R1, [R0, #MUXCTL20_OFS]
                LDR     R1, =RESCTL20_Val
                STR     R1, [R0, #RESCTL20_OFS]
                ENDIF

                IF      IOCFG21_SETUP != 0
                LDR     R1, =MUXCTL21_Val
                STR     R1, [R0, #MUXCTL21_OFS]
                LDR     R1, =RESCTL21_Val
                STR     R1, [R0, #RESCTL21_OFS]
                ENDIF

                IF      IOCFG22_SETUP != 0
                LDR     R1, =MUXCTL22_Val
                STR     R1, [R0, #MUXCTL22_OFS]
                LDR     R1, =RESCTL22_Val
                STR     R1, [R0, #RESCTL22_OFS]
                ENDIF

                IF      IOCFG23_SETUP != 0
                LDR     R1, =MUXCTL23_Val
                STR     R1, [R0, #MUXCTL23_OFS]
                LDR     R1, =RESCTL23_Val
                STR     R1, [R0, #RESCTL23_OFS]
                ENDIF

                IF      IOCFG24_SETUP != 0
                LDR     R1, =MUXCTL24_Val
                STR     R1, [R0, #MUXCTL24_OFS]
                LDR     R1, =RESCTL24_Val
                STR     R1, [R0, #RESCTL24_OFS]
                ENDIF

                IF      IOCFG25_SETUP != 0
                LDR     R1, =MUXCTL25_Val
                STR     R1, [R0, #MUXCTL25_OFS]
                ENDIF
                ENDIF   ; of IF      IOCON_SETUP != 0


; External Memory Setup (EMC) --------------------------------------------------

                IF      EMC_SETUP != 0
                LDR     R0, =EMC_BASE
                MOV     R1, #EMC_CONTROL_Val
                STR     R1, [R0, #EMC_CONTROL_OFS]
                MOV     R1, #EMC_CONFIG_Val
                STR     R1, [R0, #EMC_CONFIG_OFS]

                IF      EMC_STA_SETUP != 0
                LDR     R1, =EMC_WAIT_Val
                STR     R1, [R0, #EMC_WAIT_OFS]

                IF      EMC_STATIC0_SETUP != 0
                LDR     R1, =EMC_SCONFIG0_Val
                STR     R1, [R0, #EMC_SCONFIG0_OFS]
                LDR     R1, =EMC_SWAITWEN0_Val
                STR     R1, [R0, #EMC_SWAITWEN0_OFS]
                LDR     R1, =EMC_SWAITOEN0_Val
                STR     R1, [R0, #EMC_SWAITOEN0_OFS]
                LDR     R1, =EMC_SWAITRD0_Val
                STR     R1, [R0, #EMC_SWAITRD0_OFS]
                LDR     R1, =EMC_SWAITPAGE0_Val
                STR     R1, [R0, #EMC_SWAITPAGE0_OFS]
                LDR     R1, =EMC_SWAITWR0_Val
                STR     R1, [R0, #EMC_SWAITWR0_OFS]
                LDR     R1, =EMC_STURN0_Val
                STR     R1, [R0, #EMC_STURN0_OFS]
                ENDIF            

                IF      EMC_STATIC1_SETUP != 0
                LDR     R1, =EMC_SCONFIG1_Val
                STR     R1, [R0, #EMC_SCONFIG1_OFS]
                LDR     R1, =EMC_SWAITWEN1_Val
                STR     R1, [R0, #EMC_SWAITWEN1_OFS]
                LDR     R1, =EMC_SWAITOEN1_Val
                STR     R1, [R0, #EMC_SWAITOEN1_OFS]
                LDR     R1, =EMC_SWAITRD1_Val
                STR     R1, [R0, #EMC_SWAITRD1_OFS]
                LDR     R1, =EMC_SWAITPAGE1_Val
                STR     R1, [R0, #EMC_SWAITPAGE1_OFS]
                LDR     R1, =EMC_SWAITWR1_Val
                STR     R1, [R0, #EMC_SWAITWR1_OFS]
                LDR     R1, =EMC_STURN1_Val
                STR     R1, [R0, #EMC_STURN1_OFS]
                ENDIF            

                IF      EMC_STATIC2_SETUP != 0
                LDR     R1, =EMC_SCONFIG2_Val
                STR     R1, [R0, #EMC_SCONFIG2_OFS]
                LDR     R1, =EMC_SWAITWEN2_Val
                STR     R1, [R0, #EMC_SWAITWEN2_OFS]
                LDR     R1, =EMC_SWAITOEN2_Val
                STR     R1, [R0, #EMC_SWAITOEN2_OFS]
                LDR     R1, =EMC_SWAITRD2_Val
                STR     R1, [R0, #EMC_SWAITRD2_OFS]
                LDR     R1, =EMC_SWAITPAGE2_Val
                STR     R1, [R0, #EMC_SWAITPAGE2_OFS]
                LDR     R1, =EMC_SWAITWR2_Val
                STR     R1, [R0, #EMC_SWAITWR2_OFS]
                LDR     R1, =EMC_STURN2_Val
                STR     R1, [R0, #EMC_STURN2_OFS]
                ENDIF            

                IF      EMC_STATIC3_SETUP != 0
                LDR     R1, =EMC_SCONFIG3_Val
                STR     R1, [R0, #EMC_SCONFIG3_OFS]
                LDR     R1, =EMC_SWAITWEN3_Val
                STR     R1, [R0, #EMC_SWAITWEN3_OFS]
                LDR     R1, =EMC_SWAITOEN3_Val
                STR     R1, [R0, #EMC_SWAITOEN3_OFS]
                LDR     R1, =EMC_SWAITRD3_Val
                STR     R1, [R0, #EMC_SWAITRD3_OFS]
                LDR     R1, =EMC_SWAITPAGE3_Val
                STR     R1, [R0, #EMC_SWAITPAGE3_OFS]
                LDR     R1, =EMC_SWAITWR3_Val
                STR     R1, [R0, #EMC_SWAITWR3_OFS]
                LDR     R1, =EMC_STURN3_Val
                STR     R1, [R0, #EMC_STURN3_OFS]
                ENDIF            

                LDR     R6, =10000
Wait_STA0       SUBS    R6, R6, #1
                BNE     Wait_STA0     
                ENDIF

                IF      (EMC_DYN_SETUP != 0):LAND:(:LNOT::DEF:EMC_DYN_NOINIT)
                MOV     R1, #EMC_DYNMRCON_Val
                STR     R1, [R0, #EMC_DYNMRCON_OFS]

                IF      EMC_DYNAMIC0_SETUP != 0
                MVN     R2, #BUF_EN_BIT
                LDR     R1, =EMC_DYNCFG0_Val
                AND     R1, R1, R2
                STR     R1, [R0, #EMC_DYNCFG0_OFS]
                LDR     R1, =EMC_DYNRASCAS0_Val
                STR     R1, [R0, #EMC_DYNRASCAS0_OFS]
                ENDIF            

                IF      EMC_DYNAMIC1_SETUP != 0
                MVN     R2, #BUF_EN_BIT
                LDR     R1, =EMC_DYNCFG1_Val
                AND     R1, R1, R2
                STR     R1, [R0, #EMC_DYNCFG1_OFS]
                LDR     R1, =EMC_DYNRASCAS1_Val
                STR     R1, [R0, #EMC_DYNRASCAS1_OFS]
                ENDIF            

                MOV     R1, #EMC_PRECHARGE_Val
                STR     R1, [R0, #EMC_PRECHARGE_OFS]
                MOV     R1, #EMC_DYNM2PRE_Val
                STR     R1, [R0, #EMC_DYNM2PRE_OFS]
                MOV     R1, #EMC_REFEXIT_Val
                STR     R1, [R0, #EMC_REFEXIT_OFS]
                MOV     R1, #EMC_DOACTIVE_Val
                STR     R1, [R0, #EMC_DOACTIVE_OFS]
                MOV     R1, #EMC_DIACTIVE_Val
                STR     R1, [R0, #EMC_DIACTIVE_OFS]
                MOV     R1, #EMC_DWRT_Val
                STR     R1, [R0, #EMC_DWRT_OFS]
                MOV     R1, #EMC_DYNACTCMD_Val
                STR     R1, [R0, #EMC_DYNACTCMD_OFS]
                MOV     R1, #EMC_DYNAUTO_Val
                STR     R1, [R0, #EMC_DYNAUTO_OFS]
                MOV     R1, #EMC_DYNREFEXIT_Val
                STR     R1, [R0, #EMC_DYNREFEXIT_OFS]
                MOV     R1, #EMC_DYNACTIVEAB_Val
                STR     R1, [R0, #EMC_DYNACTIVEAB_OFS]
                MOV     R1, #EMC_DYNAMICMRD_Val
                STR     R1, [R0, #EMC_DYNAMICMRD_OFS]
                MOV     R1, #(CS_BIT:OR:CE_BIT)
                STR     R1, [R0, #EMC_DYNMCTRL_OFS]

                LDR     R6, =10000
Wait_DYN0       SUBS    R6, R6, #1
                BNE     Wait_DYN0     

                LDR     R1, =(CS_BIT:OR:CE_BIT:OR:NOP_CMD)
                STR     R1, [R0, #EMC_DYNMCTRL_OFS]

                LDR     R6, =20000
Wait_DYN1       SUBS    R6, R6, #1
                BNE     Wait_DYN1     

                LDR     R1, =(CS_BIT:OR:CE_BIT:OR:PALL_CMD)
                STR     R1, [R0, #EMC_DYNMCTRL_OFS]
                MOV     R1, #0
                STR     R1, [R0, #EMC_DYNMREF_OFS]


                LDR     R6, =25000
Wait_DYN2       SUBS    R6, R6, #1
                BNE     Wait_DYN2     

                LDR     R1, =EMC_DYNMREF_Val
                STR     R1, [R0, #EMC_DYNMREF_OFS]

                LDR     R1, =(CS_BIT:OR:CE_BIT:OR:MODE_CMD)
                STR     R1, [R0, #EMC_DYNMCTRL_OFS]

                IF      EMC_DYNAMIC0_SETUP != 0
                LDR     R1, =SDRAM0_MODE_REG
                LDR     R1, [R1, #0]
                LDR     R1, =EMC_DYNCFG0_Val
                STR     R1, [R0, #EMC_DYNCFG0_OFS]
                LDR     R1, =EMC_DYNRASCAS0_Val
                STR     R1, [R0, #EMC_DYNRASCAS0_OFS]
                ENDIF

                IF      EMC_DYNAMIC1_SETUP != 0
                LDR     R1, =SDRAM1_MODE_REG
                LDR     R1, [R1, #0]
                LDR     R1, =EMC_DYNCFG1_Val
                STR     R1, [R0, #EMC_DYNCFG1_OFS]
                LDR     R1, =EMC_DYNRASCAS1_Val
                STR     R1, [R0, #EMC_DYNRASCAS1_OFS]
                ENDIF

                LDR     R1, =(CS_BIT:OR:CE_BIT:OR:NORMAL_CMD)
                STR     R1, [R0, #EMC_DYNMCTRL_OFS]

                IF      EMC_DYNAMIC0_SETUP != 0
                LDR     R1, =EMC_DYNCFG0_Val
                STR     R1, [R0, #EMC_DYNCFG0_OFS]
                ENDIF

                IF      EMC_DYNAMIC1_SETUP != 0
                LDR     R1, =EMC_DYNCFG1_Val
                STR     R1, [R0, #EMC_DYNCFG1_OFS]
                ENDIF

                LDR     R6, =25000
Wait_DYN3       SUBS    R6, R6, #1
                BNE     Wait_DYN3     
                ENDIF
                ENDIF   ; of IF      (EMC_DYN_SETUP != 0):LAND(:LNOT::DEF:EMC_DYN_NOINIT)


; Remap Setting ----------------------------------------------------------------

                IF      :DEF:REMAP
                LDR     R0, =(RCPC_BASE:OR:REMAP_OFS)
                IF      :DEF:EXTSRAM0_MODE
                MOV     R1, #3
                ELIF    :DEF:INTSRAM_MODE
                MOV     R1, #2
                ELIF    :DEF:EXTSDRAM_MODE
                MOV     R1, #1
                ELSE
                MOV     R1, #0
                ENDIF
                STR     R1, [R0]
                ENDIF


; Cache Setup ------------------------------------------------------------------

                IF      ICACHE_SETUP != 0
                MRC     p15, 0, R0, c1, c0, 0   ; Enable Instruction Cache
                ORR     R0, R0, #ICACHE_EN_BIT
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


; Enter the C code

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
