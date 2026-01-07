;/*****************************************************************************/
;/* LPC29xx.S: Startup file for NXP LPC29xx device series                     */
;/*****************************************************************************/
;/* <<< Use Configuration Wizard in Context Menu >>>                          */
;/*****************************************************************************/
;/* This file is part of the uVision/ARM development tools.                   */
;/* Copyright (c) 2008 Keil - An ARM Company. All rights reserved.            */
;/* This software may only be used under the terms of a valid, current,       */
;/* end user licence from KEIL for a compatible version of KEIL software      */
;/* development tools. Nothing else gives you the right to use this software. */
;/*****************************************************************************/


;/*
; *  The LPC29xx.S code is executed after CPU Reset. This file may be 
; *  translated with the following SET symbols. In uVision these SET 
; *  symbols are entered under Options - ASM - Define.
; *
; *  RAM_INTVEC: when set the startup code copies exception vectors 
; *  from on-chip Flash to on-chip RAM.
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


; Memory Definitions

; Internal Memory Base Addresses
FLASH_BASE      EQU     0x20000000   
RAM_BASE        EQU     0x80000000
EXTMEM0_BASE    EQU     0x40000000
EXTMEM1_BASE    EQU     0x44000000
EXTMEM2_BASE    EQU     0x48000000
EXTMEM3_BASE    EQU     0x4C000000
EXTMEM4_BASE    EQU     0x50000000
EXTMEM5_BASE    EQU     0x54000000
EXTMEM6_BASE    EQU     0x58000000
EXTMEM7_BASE    EQU     0x5C000000


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
IRQ_Stack_Size  EQU     0x00000100
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


; Clock Generation Unit (CGU) Module Definitions
CGU_BASE        EQU     0xFFFF8000      ; CGU Base Address
FREQ_MON_OFS    EQU     0x14            ; Frequency Monitor Register Offset
RDET_OFS        EQU     0x18            ; Clock Detection Register Offset
XTAL_STAT_OFS   EQU     0x1C            ; Crytal-oscillator Status Reg Offset
XTAL_CTRL_OFS   EQU     0x20            ; Crytal-oscillator Control Reg Offset
PLL_STATUS_OFS  EQU     0x24            ; PLL Status Register Offset
PLL_CONTROL_OFS EQU     0x28            ; PLL Control Register Offset
FDIV_STAT0_OFS  EQU     0x2C            ; FDIV0 Status Register Offset
FDIV_CTRL0_OFS  EQU     0x30            ; FDIV0 Control Register Offset
FDIV_STAT1_OFS  EQU     0x34            ; FDIV1 Status Register Offset
FDIV_CTRL1_OFS  EQU     0x38            ; FDIV1 Control Register Offset
FDIV_STAT2_OFS  EQU     0x3C            ; FDIV2 Status Register Offset
FDIV_CTRL2_OFS  EQU     0x40            ; FDIV2 Control Register Offset
FDIV_STAT3_OFS  EQU     0x44            ; FDIV3 Status Register Offset
FDIV_CTRL3_OFS  EQU     0x48            ; FDIV3 Control Register Offset
FDIV_STAT4_OFS  EQU     0x4C            ; FDIV4 Status Register Offset
FDIV_CTRL4_OFS  EQU     0x50            ; FDIV4 Control Register Offset
FDIV_STAT5_OFS  EQU     0x54            ; FDIV5 Status Register Offset
FDIV_CTRL5_OFS  EQU     0x58            ; FDIV5 Control Register Offset
FDIV_STAT6_OFS  EQU     0x5C            ; FDIV6 Status Register Offset
FDIV_CTRL6_OFS  EQU     0x60            ; FDIV6 Control Register Offset
SAFE_CLK_ST_OFS EQU     0x64            ; BASE_SAFE_CLK Status Register Offset
SAFE_CLK_CO_OFS EQU     0x68            ; BASE_SAFE_CLK Config Register Offset
SYS_CLK_ST_OFS  EQU     0x6C            ; BASE_SYS_CLK Status Register Offset
SYS_CLK_CO_OFS  EQU     0x70            ; BASE_SYS_CLK Config Register Offset
PCR_CLK_ST_OFS  EQU     0x74            ; BASE_PCR_CLK Status Register Offset
PCR_CLK_CO_OFS  EQU     0x78            ; BASE_PCR_CLK Config Register Offset
IVNSS_CLK_ST_OFS EQU    0x7C            ; BASE_IVNSS_CLK Status Register Offset
IVNSS_CLK_CO_OFS EQU    0x80            ; BASE_IVNSS_CLK Config Register Offset
MSCSS_CLK_ST_OFS EQU    0x84            ; BASE_MPCSS_CLK Status Register Offset
MSCSS_CLK_CO_OFS EQU    0x88            ; BASE_MPCSS_CLK Config Register Offset
FRSS_CLK_ST_OFS EQU     0x8C            ; BASE_FRSS_CLK Status Register Offset
FRSS_CLK_CO_OFS EQU     0x90            ; BASE_FRSS_CLK Config Register Offset
UART_CLK_ST_OFS EQU     0x94            ; BASE_UART_CLK Status Register Offset
UART_CLK_CO_OFS EQU     0x98            ; BASE_UART_CLK Config Register Offset
SPI_CLK_ST_OFS  EQU     0x9C            ; BASE_SPI_CLK Status Register Offset
SPI_CLK_CO_OFS  EQU     0xA0            ; BASE_SPI_CLK Config Register Offset
TMR_CLK_ST_OFS  EQU     0xA4            ; BASE_TMR_CLK Status Register Offset
TMR_CLK_CO_OFS  EQU     0xA8            ; BASE_TMR_CLK Config Register Offset
ADC_CLK_ST_OFS  EQU     0xAC            ; BASE_ADC_CLK Status Register Offset
ADC_CLK_CO_OFS  EQU     0xB0            ; BASE_ADC_CLK Config Register Offset
CLK_TS_ST_OFS   EQU     0xB4            ; BASE_TESTSHELL_CLK Status Reg Offset
CLK_TS_CO_OFS   EQU     0xB8            ; BASE_TESTSHELL_CLK Config Reg Offset

INT_CLR_EN_OFS  EQU     0xFD8           ; Interrupt Clear Enable Register Offset
INT_SET_EN_OFS  EQU     0xFDC           ; Interrupt Set   Enable Register Offset
INT_STATUS_OFS  EQU     0xFE0           ; Interrupt Status Register Offset
INT_ENABLE_OFS  EQU     0xFE4           ; Interrupt Enable Register Offset
INT_CLR_ST_OFS  EQU     0xFE8           ; Interrupt Clear Status Register Offset
INT_SET_ST_OFS  EQU     0xFEC           ; Interrupt Set   Status Register Offset

BUS_DISABLE_OFS EQU     0xFF4           ; Bus Disable Register Offset

; Constants
PLL_XTAL_SEL    EQU     (1 << 24)       ; Crystal Oscillator Select
AUTOBLOK        EQU     (1 << 11)       ; Enables Auto-blocking of Clock
P23EN           EQU     (1 <<  2)       ; Three-phase Output Mode Control
PLL_PD          EQU     (1 <<  0)       ; PLL Power-down Control
PLL_LOCK        EQU     (1 <<  0)       ; PLL Lock
PLL_PRESENT     EQU     (1 <<  2)       ; PLL Present
FDIV0_PRESENT   EQU     (1 <<  5)       ; FDIV0 Present
FDIV1_PRESENT   EQU     (1 <<  6)       ; FDIV1 Present
FDIV2_PRESENT   EQU     (1 <<  7)       ; FDIV2 Present
FDIV3_PRESENT   EQU     (1 <<  8)       ; FDIV3 Present
FDIV4_PRESENT   EQU     (1 <<  9)       ; FDIV4 Present
FDIV5_PRESENT   EQU     (1 << 10)       ; FDIV5 Present
FDIV6_PRESENT   EQU     (1 << 11)       ; FDIV6 Present

;// <e> Clock Setup
CLOCK_SETUP     EQU     1

;//   <h> Crystall Oscillator Control Register (XTAL_OSC_CONTROL)
;//     <o0.2>           HF: Oscillator HF Pining of clock
;//                     <0=> Oscillator Low-frequency mode (lower then 20 MHz)
;//                     <1=> Oscillator High-frequency mode (higher then 10 MHz)
;//     <o0.1>       BYPASS: Bypass Mode Enable
;//     <o0.0>       ENABLE: Oscillator-pad Enable
;//   </h>
XTAL_OSC_CTRL_Val EQU   0x00000001

;//   <h> PLL Control Register (PLL_CONTROL)
;//                     <i> PLL_clk = (M * PLL_clk_src); F_coo = 2 * P * PLL_clk
;//     <o0.24..31> CLK_SEL: Clock Source Selection
;//                     <1=> Crystal Oscillator
;//     <o0.16..23>    MSEL: Feedback-divider Division Ratio <1-32><#-1>
;//                     <i> M value (divider value, not the register value)
;//     <o0.11>    AUTOBLOK: Enable Auto-blocking of Clock
;//                     <i> Enable auto-blocking of clock when programming changes
;//     <o0.8..9>      PSEL: Post-divider Division Ratio
;//                     <0=> 2
;//                     <1=> 4
;//                     <2=> 8
;//                     <3=> 16
;//                     <i> P value (divider value, not the register value)
;//     <o0.7>       DIRECT: Direct Clock Output Enable
;//     <o0.2>        P23EN: Three-phase Output Mode Control
;//                     <0=> PLL + 120° and PLL + 120° outputs disabled
;//                     <1=> PLL + 120° and PLL + 120° outputs enabled
;//     <o0.1>       BYPASS: Input Clock Bypass Disable
;//     <o0.0>           PD: Power-down Enable
;//   </h>
PLL_CONTROL_Val EQU     0x010F0004

;//   <h> FDIV Control 0 Register (FDIV_CONTROL_0)
;//     <o0.24..31> CLK_SEL: Clock Source Selection
;//                     <0=> LP_OSC
;//                     <1=> Crystal Oscillator
;//                     <2=> PLL
;//                     <3=> PLL + 120°
;//                     <4=> PLL + 240°
;//     <o0.12..23>    LOAD: Load Value <0-4095>
;//     <o0.0..11> DENOMINATOR: Denominator or Modulo Value <0-4095>
;//   </h>
;//   <h> FDIV Control 1 Register (FDIV_CONTROL_1)
;//     <o1.24..31> CLK_SEL: Clock Source Selection
;//                     <0=> LP_OSC
;//                     <1=> Crystal Oscillator
;//                     <2=> PLL
;//                     <3=> PLL + 120°
;//                     <4=> PLL + 240°
;//     <o1.12..23>    LOAD: Load Value <0-4095>
;//     <o1.0..11> DENOMINATOR: Denominator or Modulo Value <0-4095>
;//   </h>
;//   <h> FDIV Control 2 Register (FDIV_CONTROL_2)
;//     <o2.24..31> CLK_SEL: Clock Source Selection
;//                     <0=> LP_OSC
;//                     <1=> Crystal Oscillator
;//                     <2=> PLL
;//                     <3=> PLL + 120°
;//                     <4=> PLL + 240°
;//     <o2.12..23>    LOAD: Load Value <0-4095>
;//     <o2.0..11> DENOMINATOR: Denominator or Modulo Value <0-4095>
;//   </h>
;//   <h> FDIV Control 3 Register (FDIV_CONTROL_3)
;//     <o3.24..31> CLK_SEL: Clock Source Selection
;//                     <0=> LP_OSC
;//                     <1=> Crystal Oscillator
;//                     <2=> PLL
;//                     <3=> PLL + 120°
;//                     <4=> PLL + 240°
;//     <o3.12..23>    LOAD: Load Value <0-4095>
;//     <o3.0..11> DENOMINATOR: Denominator or Modulo Value <0-4095>
;//   </h>
;//   <h> FDIV Control 4 Register (FDIV_CONTROL_4)
;//     <o4.24..31> CLK_SEL: Clock Source Selection
;//                     <0=> LP_OSC
;//                     <1=> Crystal Oscillator
;//                     <2=> PLL
;//                     <3=> PLL + 120°
;//                     <4=> PLL + 240°
;//     <o4.12..23>    LOAD: Load Value <0-4095>
;//     <o4.0..11> DENOMINATOR: Denominator or Modulo Value <0-4095>
;//   </h>
;//   <h> FDIV Control 5 Register (FDIV_CONTROL_5)
;//     <o5.24..31> CLK_SEL: Clock Source Selection
;//                     <0=> LP_OSC
;//                     <1=> Crystal Oscillator
;//                     <2=> PLL
;//                     <3=> PLL + 120°
;//                     <4=> PLL + 240°
;//     <o5.12..23>    LOAD: Load Value <0-4095>
;//     <o5.0..11> DENOMINATOR: Denominator or Modulo Value <0-4095>
;//   </h>
;//   <h> FDIV Control 6 Register (FDIV_CONTROL_6)
;//     <o6.24..31> CLK_SEL: Clock Source Selection
;//                     <0=> LP_OSC
;//                     <1=> Crystal Oscillator
;//                     <2=> PLL
;//                     <3=> PLL + 120°
;//                     <4=> PLL + 240°
;//     <o6.12..23>    LOAD: Load Value <0-4095>
;//     <o6.0..11> DENOMINATOR: Denominator or Modulo Value <0-4095>
;//   </h>
FDIV_CTRL0_Val  EQU     0x02001028
FDIV_CTRL1_Val  EQU     0x00001001
FDIV_CTRL2_Val  EQU     0x00001001
FDIV_CTRL3_Val  EQU     0x00001001
FDIV_CTRL4_Val  EQU     0x00001001
FDIV_CTRL5_Val  EQU     0x00001001
FDIV_CTRL6_Val  EQU     0x00001001

;//   <h> Output-clock Configuration Register for BASE_SYS_CLK (SYS_CLK_CONF)
;//     <o0.24..31> CLK_SEL: Clock Source Selection
;//                     <0=> LP_OSC
;//                     <1=> Crystal Oscillator
;//                     <2=> PLL
;//                     <3=> PLL + 120°
;//                     <4=> PLL + 240°
;//                     <5=> FDIV0
;//                     <6=> FDIV1
;//                     <7=> FDIV2
;//                     <8=> FDIV3
;//                     <9=> FDIV4
;//                     <10=> FDIV5
;//                     <11=> FDIV6
;//     <o0.11>    AUTOBLOK: Enable Auto-blocking of Clock
;//                     <i> Enable auto-blocking of clock when programming changes
;//     <o0.2..4>      IDIV: Integer Divide Value <0-7>
;//     <o0.0>           PD: Power-down Clock Slice
;//   </h>
SYS_CLK_Val     EQU     0x02000804

;// </e> Clock Setup


; Flash Memory Controller (FMC) Module Definitions
FMC_BASE        EQU     0x20200000      ; FMC Base Address
FCTR_OFS        EQU     0x00            ; Flash Control Register Offset
FBWST_OFS       EQU     0x10            ; Flash Bridge Wait State Reg Offset

;// <e> Flash Setup
;//   <h> Flash Memory Control Register (FCTR)
;//     <o1.13> FS_CACHEBYP: Read Buffering Disable
;//     <o1.9>        FS_PD: Power-down Enable
;//     <o1.4>       FS_DCR: Asynchronous Reading Enable
;//     <o1.0>        FS_CS: Flash Memory Chip Select Enable
;//   </h>
;//   <h> Flash Bridge Wait States Register (FBWST)
;//     <o2.15>    CACHE2EN: Dual Buffering Enable
;//     <o2.14>  SPECALWAYS: Speculative Reading Always Enable
;//     <o2.0..7>       WST: Number of Wait States <0-255>
;//   </h>
;// </e>
FLASH_SETUP     EQU     1
FCTR_Val        EQU     0x00000011
FBWST_Val       EQU     0x0000C004


; System Control Unit (SCU) Module Definitions
SCU_SFSP0_BASE      EQU 0xE0001000      ; SCU SFSP0 Base Address
SCU_SFSP1_BASE      EQU 0xE0001100      ; SCU SFSP1 Base Address
SCU_SFSP2_BASE      EQU 0xE0001200      ; SCU SFSP2 Base Address
SCU_SFSP3_BASE      EQU 0xE0001300      ; SCU SFSP3 Base Address
SFSP_0_OFS          EQU 0x00            ; Pin 0 Offset
SFSP_1_OFS          EQU 0x04            ; Pin 1 Offset
SFSP_2_OFS          EQU 0x08            ; Pin 2 Offset
SFSP_3_OFS          EQU 0x0C            ; Pin 3 Offset
SFSP_4_OFS          EQU 0x10            ; Pin 4 Offset
SFSP_5_OFS          EQU 0x14            ; Pin 5 Offset
SFSP_6_OFS          EQU 0x18            ; Pin 6 Offset
SFSP_7_OFS          EQU 0x1C            ; Pin 7 Offset
SFSP_8_OFS          EQU 0x20            ; Pin 8 Offset
SFSP_9_OFS          EQU 0x24            ; Pin 9 Offset
SFSP_10_OFS         EQU 0x28            ; Pin 10 Offset
SFSP_11_OFS         EQU 0x2C            ; Pin 11 Offset
SFSP_12_OFS         EQU 0x30            ; Pin 12 Offset
SFSP_13_OFS         EQU 0x34            ; Pin 13 Offset
SFSP_14_OFS         EQU 0x38            ; Pin 14 Offset
SFSP_15_OFS         EQU 0x3C            ; Pin 15 Offset
SFSP_16_OFS         EQU 0x40            ; Pin 16 Offset
SFSP_17_OFS         EQU 0x44            ; Pin 17 Offset
SFSP_18_OFS         EQU 0x48            ; Pin 18 Offset
SFSP_19_OFS         EQU 0x4C            ; Pin 19 Offset
SFSP_20_OFS         EQU 0x50            ; Pin 20 Offset
SFSP_21_OFS         EQU 0x54            ; Pin 21 Offset
SFSP_22_OFS         EQU 0x58            ; Pin 22 Offset
SFSP_23_OFS         EQU 0x5C            ; Pin 23 Offset
SFSP_24_OFS         EQU 0x60            ; Pin 24 Offset
SFSP_25_OFS         EQU 0x64            ; Pin 25 Offset
SFSP_26_OFS         EQU 0x68            ; Pin 26 Offset
SFSP_27_OFS         EQU 0x6C            ; Pin 27 Offset
SFSP_28_OFS         EQU 0x70            ; Pin 28 Offset
SFSP_29_OFS         EQU 0x74            ; Pin 29 Offset
SFSP_30_OFS         EQU 0x78            ; Pin 30 Offset
SFSP_31_OFS         EQU 0x7C            ; Pin 31 Offset


; Static Memory Controller (SMC) Module Definitons
SMC_BASE            EQU 0x60000000      ; SMC Base Address
SMBIDCYR0_OFS       EQU 0x000           ; Idle-cycle Control Register
SMBWST1R0_OFS       EQU 0x004           ; Wait-state 1 Control Register
SMBWST2R0_OFS       EQU 0x008           ; Wait-state 2 Control Register
SMBWSTOENR0_OFS     EQU 0x00C           ; Output-enable Assertion Delay Reg
SMBWSTWENR0_OFS     EQU 0x010           ; Write-enable Assertion Delay Reg
SMBCR0_OFS          EQU 0x014           ; Config Register
SMBSR0_OFS          EQU 0x018           ; Status Register
SMBIDCYR1_OFS       EQU 0x01C           ; Idle-cycle Control Register
SMBWST1R1_OFS       EQU 0x020           ; Wait-state 1 Control Register
SMBWST2R1_OFS       EQU 0x024           ; Wait-state 2 Control Register
SMBWSTOENR1_OFS     EQU 0x028           ; Output-enable Assertion Delay Reg
SMBWSTWENR1_OFS     EQU 0x02C           ; Write-enable Assertion Delay Reg
SMBCR1_OFS          EQU 0x030           ; Config Register
SMBSR1_OFS          EQU 0x034           ; Status Register
SMBIDCYR2_OFS       EQU 0x038           ; Idle-cycle Control Register
SMBWST1R2_OFS       EQU 0x03C           ; Wait-state 1 Control Register
SMBWST2R2_OFS       EQU 0x040           ; Wait-state 2 Control Register
SMBWSTOENR2_OFS     EQU 0x044           ; Output-enable Assertion Delay Reg
SMBWSTWENR2_OFS     EQU 0x048           ; Write-enable Assertion Delay Reg
SMBCR2_OFS          EQU 0x04C           ; Config Register
SMBSR2_OFS          EQU 0x050           ; Status Register
SMBIDCYR3_OFS       EQU 0x054           ; Idle-cycle Control Register
SMBWST1R3_OFS       EQU 0x058           ; Wait-state 1 Control Register
SMBWST2R3_OFS       EQU 0x05C           ; Wait-state 2 Control Register
SMBWSTOENR3_OFS     EQU 0x060           ; Output-enable Assertion Delay Reg
SMBWSTWENR3_OFS     EQU 0x064           ; Write-enable Assertion Delay Reg
SMBCR3_OFS          EQU 0x068           ; Config Register
SMBSR3_OFS          EQU 0x06C           ; Status Register
SMBIDCYR4_OFS       EQU 0x070           ; Idle-cycle Control Register
SMBWST1R4_OFS       EQU 0x074           ; Wait-state 1 Control Register
SMBWST2R4_OFS       EQU 0x078           ; Wait-state 2 Control Register
SMBWSTOENR4_OFS     EQU 0x07C           ; Output-enable Assertion Delay Reg
SMBWSTWENR4_OFS     EQU 0x080           ; Write-enable Assertion Delay Reg
SMBCR4_OFS          EQU 0x084           ; Config Register
SMBSR4_OFS          EQU 0x088           ; Status Register
SMBIDCYR5_OFS       EQU 0x08C           ; Idle-cycle Control Register
SMBWST1R5_OFS       EQU 0x090           ; Wait-state 1 Control Register
SMBWST2R5_OFS       EQU 0x094           ; Wait-state 2 Control Register
SMBWSTOENR5_OFS     EQU 0x098           ; Output-enable Assertion Delay Reg
SMBWSTWENR5_OFS     EQU 0x09C           ; Write-enable Assertion Delay Reg
SMBCR5_OFS          EQU 0x0A0           ; Config Register
SMBSR5_OFS          EQU 0x0A4           ; Status Register
SMBIDCYR6_OFS       EQU 0x0A8           ; Idle-cycle Control Register
SMBWST1R6_OFS       EQU 0x0AC           ; Wait-state 1 Control Register
SMBWST2R6_OFS       EQU 0x0B0           ; Wait-state 2 Control Register
SMBWSTOENR6_OFS     EQU 0x0B4           ; Output-enable Assertion Delay Reg
SMBWSTWENR6_OFS     EQU 0x0B8           ; Write-enable Assertion Delay Reg
SMBCR6_OFS          EQU 0x0BC           ; Config Register
SMBSR6_OFS          EQU 0x0C0           ; Status Register
SMBIDCYR7_OFS       EQU 0x0C4           ; Idle-cycle Control Register
SMBWST1R7_OFS       EQU 0x0C8           ; Wait-state 1 Control Register
SMBWST2R7_OFS       EQU 0x0CC           ; Wait-state 2 Control Register
SMBWSTOENR7_OFS     EQU 0x0D0           ; Output-enable Assertion Delay Reg
SMBWSTWENR7_OFS     EQU 0x0D4           ; Write-enable Assertion Delay Reg
SMBCR7_OFS          EQU 0x0D8           ; Config Register
SMBSR7_OFS          EQU 0x0DC           ; Status Register

; External Static Memory Pins definitions
; pin functions for external static memory interfacing
EXT_SRAM_PIN_Val    EQU 0x00000007

;// <e> Static Memory Controller (SMC)
SMC_SETUP           EQU 0

;//   <e0> Configure Static Memory Controller for Bank 0 Address Range
;//     <h> Bank Idle-cycle Control Register (SMBIDCYR0)
;//       <o1.0..3> IDCY: Idle or turnaround cycles <0-15>
;//         <i> Number of bus turnaround cycles added between read and write access.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Wait-state 1 Control Register (SMBWST1R0)
;//       <o2.0..4> WST: Wait-state 1 <0-31>
;//         <i> Length of read accesses, except for burst ROM where it defines the length
;//         <i> of the firse read access only.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Wait-state 1 Control Register (SMBWST2R0)
;//       <o3.0..4> WST: Wait-state 2 <0-31>
;//         <i> Length of write accesses, except for burst ROM where it defines the length
;//         <i> of burst-read accesses.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Output Enable Assertion-delay Control Register (SMBWSTOENR0)
;//       <o4.0..3> WSTOEN: Output-enable assertion delay <0-15>
;//         <i> Length of output-enable delay after the chip-select assertion.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Write Enable Assertion-delay Control Register (SMBWSTWENR0)
;//       <o5.0..3> WSTWEN: Write-enable assertion delay <0-15>
;//         <i> Length of write enable delay after the chip-select assertion.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Configuration Register (SMBCR0)
;//       <o6.6..7> MW: Memory-width configuration
;//                     <0=> 8-bit
;//                     <1=> 16-bit
;//                     <2=> 32-bit
;//       <o6.5>    BM: Burst mode enable
;//       <o6.4>    WP: Write protect enable
;//       <o6.3>    CSPOL: Chip-select polarity
;//                     <0=> Active LOW
;//                     <1=> Active HIGH
;//       <o6.0>    RBLE: Read-byte lane enable
;//     </h>
;//   </e>
SMC_BANK0_SETUP     EQU 1
SMBIDCYR0_Val       EQU 0x00000001
SMBWST1R0_Val       EQU 0x00000006
SMBWST2R0_Val       EQU 0x00000006
SMBWSTOENR0_Val     EQU 0x00000000
SMBWSTWENR0_Val     EQU 0x00000001
SMBCR0_Val          EQU 0x00000040

;//   <e0> Configure Static Memory Controller for Bank 1 Address Range
;//     <h> Bank Idle-cycle Control Register (SMBIDCYR1)
;//       <o1.0..3> IDCY: Idle or turnaround cycles <0-15>
;//         <i> Number of bus turnaround cycles added between read and write access.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Wait-state 1 Control Register (SMBWST1R1)
;//       <o2.0..4> WST: Wait-state 1 <0-31>
;//         <i> Length of read accesses, except for burst ROM where it defines the length
;//         <i> of the firse read access only.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Wait-state 1 Control Register (SMBWST2R1)
;//       <o3.0..4> WST: Wait-state 2 <0-31>
;//         <i> Length of write accesses, except for burst ROM where it defines the length
;//         <i> of burst-read accesses.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Output Enable Assertion-delay Control Register (SMBWSTOENR1)
;//       <o4.0..3> WSTOEN: Output-enable assertion delay <0-15>
;//         <i> Length of output-enable delay after the chip-select assertion.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Write Enable Assertion-delay Control Register (SMBWSTWENR1)
;//       <o5.0..3> WSTWEN: Write-enable assertion delay <0-15>
;//         <i> Length of write enable delay after the chip-select assertion.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Configuration Register (SMBCR1)
;//       <o6.6..7> MW: Memory-width configuration
;//                     <0=> 8-bit
;//                     <1=> 16-bit
;//                     <2=> 32-bit
;//       <o6.5>    BM: Burst mode enable
;//       <o6.4>    WP: Write protect enable
;//       <o6.3>    CSPOL: Chip-select polarity
;//                     <0=> Active LOW
;//                     <1=> Active HIGH
;//       <o6.0>    RBLE: Read-byte lane enable
;//     </h>
;//   </e>
SMC_BANK1_SETUP     EQU 0
SMBIDCYR1_Val       EQU 0x0000000F
SMBWST1R1_Val       EQU 0x0000001F
SMBWST2R1_Val       EQU 0x0000001F
SMBWSTOENR1_Val     EQU 0x00000000
SMBWSTWENR1_Val     EQU 0x00000001
SMBCR1_Val          EQU 0x00000000

;//   <e0> Configure Static Memory Controller for Bank 2 Address Range
;//     <h> Bank Idle-cycle Control Register (SMBIDCYR2)
;//       <o1.0..3> IDCY: Idle or turnaround cycles <0-15>
;//         <i> Number of bus turnaround cycles added between read and write access.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Wait-state 1 Control Register (SMBWST1R2)
;//       <o2.0..4> WST: Wait-state 1 <0-31>
;//         <i> Length of read accesses, except for burst ROM where it defines the length
;//         <i> of the firse read access only.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Wait-state 1 Control Register (SMBWST2R2)
;//       <o3.0..4> WST: Wait-state 2 <0-31>
;//         <i> Length of write accesses, except for burst ROM where it defines the length
;//         <i> of burst-read accesses.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Output Enable Assertion-delay Control Register (SMBWSTOENR2)
;//       <o4.0..3> WSTOEN: Output-enable assertion delay <0-15>
;//         <i> Length of output-enable delay after the chip-select assertion.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Write Enable Assertion-delay Control Register (SMBWSTWENR2)
;//       <o5.0..3> WSTWEN: Write-enable assertion delay <0-15>
;//         <i> Length of write enable delay after the chip-select assertion.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Configuration Register (SMBCR2)
;//       <o6.6..7> MW: Memory-width configuration
;//                     <0=> 8-bit
;//                     <1=> 16-bit
;//                     <2=> 32-bit
;//       <o6.5>    BM: Burst mode enable
;//       <o6.4>    WP: Write protect enable
;//       <o6.3>    CSPOL: Chip-select polarity
;//                     <0=> Active LOW
;//                     <1=> Active HIGH
;//       <o6.0>    RBLE: Read-byte lane enable
;//     </h>
;//   </e>
SMC_BANK2_SETUP     EQU 0
SMBIDCYR2_Val       EQU 0x0000000F
SMBWST1R2_Val       EQU 0x0000001F
SMBWST2R2_Val       EQU 0x0000001F
SMBWSTOENR2_Val     EQU 0x00000000
SMBWSTWENR2_Val     EQU 0x00000001
SMBCR2_Val          EQU 0x00000000

;//   <e0> Configure Static Memory Controller for Bank 3 Address Range
;//     <h> Bank Idle-cycle Control Register (SMBIDCYR3)
;//       <o1.0..3> IDCY: Idle or turnaround cycles <0-15>
;//         <i> Number of bus turnaround cycles added between read and write access.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Wait-state 1 Control Register (SMBWST1R3)
;//       <o2.0..4> WST: Wait-state 1 <0-31>
;//         <i> Length of read accesses, except for burst ROM where it defines the length
;//         <i> of the firse read access only.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Wait-state 1 Control Register (SMBWST2R3)
;//       <o3.0..4> WST: Wait-state 2 <0-31>
;//         <i> Length of write accesses, except for burst ROM where it defines the length
;//         <i> of burst-read accesses.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Output Enable Assertion-delay Control Register (SMBWSTOENR3)
;//       <o4.0..3> WSTOEN: Output-enable assertion delay <0-15>
;//         <i> Length of output-enable delay after the chip-select assertion.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Write Enable Assertion-delay Control Register (SMBWSTWENR3)
;//       <o5.0..3> WSTWEN: Write-enable assertion delay <0-15>
;//         <i> Length of write enable delay after the chip-select assertion.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Configuration Register (SMBCR3)
;//       <o6.6..7> MW: Memory-width configuration
;//                     <0=> 8-bit
;//                     <1=> 16-bit
;//                     <2=> 32-bit
;//       <o6.5>    BM: Burst mode enable
;//       <o6.4>    WP: Write protect enable
;//       <o6.3>    CSPOL: Chip-select polarity
;//                     <0=> Active LOW
;//                     <1=> Active HIGH
;//       <o6.0>    RBLE: Read-byte lane enable
;//     </h>
;//   </e>
SMC_BANK3_SETUP     EQU 0
SMBIDCYR3_Val       EQU 0x0000000F
SMBWST1R3_Val       EQU 0x0000001F
SMBWST2R3_Val       EQU 0x0000001F
SMBWSTOENR3_Val     EQU 0x00000000
SMBWSTWENR3_Val     EQU 0x00000001
SMBCR3_Val          EQU 0x00000000

;//   <e0> Configure Static Memory Controller for Bank 4 Address Range
;//     <h> Bank Idle-cycle Control Register (SMBIDCYR4)
;//       <o1.0..3> IDCY: Idle or turnaround cycles <0-15>
;//         <i> Number of bus turnaround cycles added between read and write access.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Wait-state 1 Control Register (SMBWST1R4)
;//       <o2.0..4> WST: Wait-state 1 <0-31>
;//         <i> Length of read accesses, except for burst ROM where it defines the length
;//         <i> of the firse read access only.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Wait-state 1 Control Register (SMBWST2R4)
;//       <o3.0..4> WST: Wait-state 2 <0-31>
;//         <i> Length of write accesses, except for burst ROM where it defines the length
;//         <i> of burst-read accesses.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Output Enable Assertion-delay Control Register (SMBWSTOENR4)
;//       <o4.0..3> WSTOEN: Output-enable assertion delay <0-15>
;//         <i> Length of output-enable delay after the chip-select assertion.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Write Enable Assertion-delay Control Register (SMBWSTWENR4)
;//       <o5.0..3> WSTWEN: Write-enable assertion delay <0-15>
;//         <i> Length of write enable delay after the chip-select assertion.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Configuration Register (SMBCR4)
;//       <o6.6..7> MW: Memory-width configuration
;//                     <0=> 8-bit
;//                     <1=> 16-bit
;//                     <2=> 32-bit
;//       <o6.5>    BM: Burst mode enable
;//       <o6.4>    WP: Write protect enable
;//       <o6.3>    CSPOL: Chip-select polarity
;//                     <0=> Active LOW
;//                     <1=> Active HIGH
;//       <o6.0>    RBLE: Read-byte lane enable
;//     </h>
;//   </e>
SMC_BANK4_SETUP     EQU 0
SMBIDCYR4_Val       EQU 0x0000000F
SMBWST1R4_Val       EQU 0x0000001F
SMBWST2R4_Val       EQU 0x0000001F
SMBWSTOENR4_Val     EQU 0x00000000
SMBWSTWENR4_Val     EQU 0x00000001
SMBCR4_Val          EQU 0x00000000

;//   <e0> Configure Static Memory Controller for Bank 5 Address Range
;//     <h> Bank Idle-cycle Control Register (SMBIDCYR5)
;//       <o1.0..3> IDCY: Idle or turnaround cycles <0-15>
;//         <i> Number of bus turnaround cycles added between read and write access.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Wait-state 1 Control Register (SMBWST1R5)
;//       <o2.0..4> WST: Wait-state 1 <0-31>
;//         <i> Length of read accesses, except for burst ROM where it defines the length
;//         <i> of the firse read access only.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Wait-state 1 Control Register (SMBWST2R5)
;//       <o3.0..4> WST: Wait-state 2 <0-31>
;//         <i> Length of write accesses, except for burst ROM where it defines the length
;//         <i> of burst-read accesses.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Output Enable Assertion-delay Control Register (SMBWSTOENR5)
;//       <o4.0..3> WSTOEN: Output-enable assertion delay <0-15>
;//         <i> Length of output-enable delay after the chip-select assertion.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Write Enable Assertion-delay Control Register (SMBWSTWENR5)
;//       <o5.0..3> WSTWEN: Write-enable assertion delay <0-15>
;//         <i> Length of write enable delay after the chip-select assertion.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Configuration Register (SMBCR5)
;//       <o6.6..7> MW: Memory-width configuration
;//                     <0=> 8-bit
;//                     <1=> 16-bit
;//                     <2=> 32-bit
;//       <o6.5>    BM: Burst mode enable
;//       <o6.4>    WP: Write protect enable
;//       <o6.3>    CSPOL: Chip-select polarity
;//                     <0=> Active LOW
;//                     <1=> Active HIGH
;//       <o6.0>    RBLE: Read-byte lane enable
;//     </h>
;//   </e>
SMC_BANK5_SETUP     EQU 0
SMBIDCYR5_Val       EQU 0x0000000F
SMBWST1R5_Val       EQU 0x0000001F
SMBWST2R5_Val       EQU 0x0000001F
SMBWSTOENR5_Val     EQU 0x00000000
SMBWSTWENR5_Val     EQU 0x00000001
SMBCR5_Val          EQU 0x00000000

;//   <e0> Configure Static Memory Controller for Bank 6 Address Range
;//     <h> Bank Idle-cycle Control Register (SMBIDCYR6)
;//       <o1.0..3> IDCY: Idle or turnaround cycles <0-15>
;//         <i> Number of bus turnaround cycles added between read and write access.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Wait-state 1 Control Register (SMBWST1R6)
;//       <o2.0..4> WST: Wait-state 1 <0-31>
;//         <i> Length of read accesses, except for burst ROM where it defines the length
;//         <i> of the firse read access only.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Wait-state 1 Control Register (SMBWST2R6)
;//       <o3.0..4> WST: Wait-state 2 <0-31>
;//         <i> Length of write accesses, except for burst ROM where it defines the length
;//         <i> of burst-read accesses.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Output Enable Assertion-delay Control Register (SMBWSTOENR6)
;//       <o4.0..3> WSTOEN: Output-enable assertion delay <0-15>
;//         <i> Length of output-enable delay after the chip-select assertion.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Write Enable Assertion-delay Control Register (SMBWSTWENR6)
;//       <o5.0..3> WSTWEN: Write-enable assertion delay <0-15>
;//         <i> Length of write enable delay after the chip-select assertion.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Configuration Register (SMBCR6)
;//       <o6.6..7> MW: Memory-width configuration
;//                     <0=> 8-bit
;//                     <1=> 16-bit
;//                     <2=> 32-bit
;//       <o6.5>    BM: Burst mode enable
;//       <o6.4>    WP: Write protect enable
;//       <o6.3>    CSPOL: Chip-select polarity
;//                     <0=> Active LOW
;//                     <1=> Active HIGH
;//       <o6.0>    RBLE: Read-byte lane enable
;//     </h>
;//   </e>
SMC_BANK6_SETUP     EQU 0
SMBIDCYR6_Val       EQU 0x0000000F
SMBWST1R6_Val       EQU 0x0000001F
SMBWST2R6_Val       EQU 0x0000001F
SMBWSTOENR6_Val     EQU 0x00000000
SMBWSTWENR6_Val     EQU 0x00000001
SMBCR6_Val          EQU 0x00000000

;//   <e0> Configure Static Memory Controller for Bank 7 Address Range
;//     <h> Bank Idle-cycle Control Register (SMBIDCYR7)
;//       <o1.0..3> IDCY: Idle or turnaround cycles <0-15>
;//         <i> Number of bus turnaround cycles added between read and write access.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Wait-state 1 Control Register (SMBWST1R7)
;//       <o2.0..4> WST: Wait-state 1 <0-31>
;//         <i> Length of read accesses, except for burst ROM where it defines the length
;//         <i> of the firse read access only.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Wait-state 1 Control Register (SMBWST2R7)
;//       <o3.0..4> WST: Wait-state 2 <0-31>
;//         <i> Length of write accesses, except for burst ROM where it defines the length
;//         <i> of burst-read accesses.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Output Enable Assertion-delay Control Register (SMBWSTOENR7)
;//       <o4.0..3> WSTOEN: Output-enable assertion delay <0-15>
;//         <i> Length of output-enable delay after the chip-select assertion.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Write Enable Assertion-delay Control Register (SMBWSTWENR7)
;//       <o5.0..3> WSTWEN: Write-enable assertion delay <0-15>
;//         <i> Length of write enable delay after the chip-select assertion.
;//         <i> In system clock period cycles.
;//     </h>
;//     <h> Bank Configuration Register (SMBCR7)
;//       <o6.6..7> MW: Memory-width configuration
;//                     <0=> 8-bit
;//                     <1=> 16-bit
;//                     <2=> 32-bit
;//       <o6.5>    BM: Burst mode enable
;//       <o6.4>    WP: Write protect enable
;//       <o6.3>    CSPOL: Chip-select polarity
;//                     <0=> Active LOW
;//                     <1=> Active HIGH
;//       <o6.0>    RBLE: Read-byte lane enable
;//     </h>
;//   </e>
SMC_BANK7_SETUP     EQU 0
SMBIDCYR7_Val       EQU 0x0000000F
SMBWST1R7_Val       EQU 0x0000001F
SMBWST2R7_Val       EQU 0x0000001F
SMBWSTOENR7_Val     EQU 0x00000000
SMBWSTWENR7_Val     EQU 0x00000001
SMBCR7_Val          EQU 0x00000000

;// </e> End of SMC Setup


                PRESERVE8

; Area Definition IRQ Table
                
                AREA    |.ARM.__AT_0x20000800|, CODE, READONLY
                ARM

; Interrupt Vector Table

IRQ_Table       DCD     0                    ;0.  ; Vector 0
                DCD     0                         ; Unused
                DCD     Watchdog_Handler     ;1.  ; Watchdog IRQ Handler
                DCD     1                         ; Watchdog IRQ Priority
                DCD     Timer0_Handler       ;2.  ; Timer 0 IRQ Handler
                DCD     1                         ; Timer 0 IRQ Priority
                DCD     Timer1_Handler       ;3.  ; Timer 1 IRQ Handler
                DCD     1                         ; Timer 1 IRQ Priority
                DCD     Timer2_Handler       ;4.  ; Timer 2 IRQ Handler
                DCD     1                         ; Timer 2 IRQ Priority
                DCD     Timer3_Handler       ;5.  ; Timer 3 IRQ Handler
                DCD     1                         ; Timer 3 IRQ Priority
                DCD     UART0_Handler        ;6.  ; UART 0 IRQ Handler
                DCD     1                         ; UART 0 IRQ Priority
                DCD     UART1_Handler        ;7.  ; UART 1 IRQ Handler
                DCD     1                         ; UART 1 IRQ Priority
                DCD     SPI0_Handler         ;8.  ; SPI 0 IRQ Handler
                DCD     1                         ; SPI 0 IRQ Priority
                DCD     SPI1_Handler         ;9.  ; SPI 1 IRQ Handler
                DCD     1                         ; SPI 1 IRQ Priority
                DCD     SPI2_Handler         ;10. ; SPI 2 IRQ Handler
                DCD     1                         ; SPI 2 IRQ Priority
                DCD     Flash_Handler        ;11. ; Flash IRQ Handler
                DCD     1                         ; Flash IRQ Priority
                DCD     RT_ICE_Rx_Handler    ;12. ; RT-ICE Rx IRQ Handler
                DCD     1                         ; RT-ICE Rx IRQ Priority
                DCD     RT_ICE_Tx_Handler    ;13. ; RT-ICE Tx IRQ Handler
                DCD     1                         ; RT-ICE Tx IRQ Priority
                DCD     MSCSS_Timer0_Handler ;14. ; MSCSS Timer 0 IRQ Handler
                DCD     1                         ; MSCSS Timer 0 IRQ Priority
                DCD     MSCSS_Timer1_Handler ;15. ; MSCSS Timer 1 IRQ Handler
                DCD     1                         ; MSCSS Timer 1 IRQ Priority
                DCD     0                    ;16. ; Reserved
                DCD     0                         ; Reserved
                DCD     ADC1_Handler         ;17. ; ADC 1 IRQ Handler
                DCD     1                         ; ADC 1 IRQ Priority
                DCD     ADC2_Handler         ;18. ; ADC 2 IRQ Handler
                DCD     1                         ; ADC 2 IRQ Priority
                DCD     PWM0_Handler         ;19. ; PWM 0 IRQ Handler
                DCD     1                         ; PWM 0 IRQ Priority
                DCD     PWM0_CM_Handler      ;20. ; PWM 0 Capt/Match IRQ Handler
                DCD     1                         ; PWM 0 Capt/Match IRQ Prio
                DCD     PWM1_Handler         ;21. ; PWM 1 IRQ Handler
                DCD     1                         ; PWM 1 IRQ Priority
                DCD     PWM1_CM_Handler      ;22. ; PWM 1 Capt/Match IRQ Handler
                DCD     1                         ; PWM 1 Capt/Match IRQ Prio
                DCD     PWM2_Handler         ;23. ; PWM 2 IRQ Handler
                DCD     1                         ; PWM 2 IRQ Priority
                DCD     PWM2_CM_Handler      ;24. ; PWM 2 Capt/Match IRQ Handler
                DCD     1                         ; PWM 2 Capt/Match IRQ Prio
                DCD     PWM3_Handler         ;25. ; PWM 3 IRQ Handler
                DCD     1                         ; PWM 3 IRQ Priority
                DCD     PWM3_CM_Handler      ;26. ; PWM 3 Capt/Match IRQ Handler
                DCD     1                         ; PWM 3 Capt/Match IRQ Prio
                DCD     ER_Handler           ;27. ; Event Router IRQ Handler
                DCD     1                         ; Event Router IRQ Priority
                DCD     LIN0_Handler         ;28. ; LIN 0 IRQ Handler
                DCD     1                         ; LIN 0 IRQ Priority
                DCD     LIN1_Handler         ;29. ; LIN 1 IRQ Handler
                DCD     1                         ; LIN 1 IRQ Priority
                DCD     0                    ;30. ; Reserved
                DCD     0                         ; Reserved
                DCD     0                    ;31. ; Reserved
                DCD     0                         ; Reserved
                DCD     0                    ;32. ; Reserved
                DCD     0                         ; Reserved
                DCD     0                    ;33. ; Reserved
                DCD     0                         ; Reserved
                DCD     0                    ;34. ; Reserved
                DCD     0                         ; Reserved
                DCD     0                    ;35. ; Reserved
                DCD     0                         ; Reserved
                DCD     CAN_All_Handler      ;36. ; CAN All IRQ Handler
                DCD     1                         ; CAN All IRQ Priority
                DCD     CAN0_Rx_Handler      ;37. ; CAN 0 Rx IRQ Handler
                DCD     1                         ; CAN 0 Rx IRQ Priority
                DCD     CAN1_Rx_Handler      ;38. ; CAN 1 Rx IRQ Handler
                DCD     1                         ; CAN 1 Rx IRQ Priority
                DCD     0                    ;39. ; Reserved
                DCD     0                         ; Reserved
                DCD     0                    ;40. ; Reserved
                DCD     0                         ; Reserved
                DCD     0                    ;41. ; Reserved
                DCD     0                         ; Reserved
                DCD     0                    ;42. ; Reserved
                DCD     0                         ; Reserved
                DCD     CAN0_Tx_Handler      ;43. ; CAN 0 Tx IRQ Handler
                DCD     1                         ; CAN 0 Tx IRQ Priority
                DCD     CAN1_Tx_Handler      ;44. ; CAN 1 Tx IRQ Handler
                DCD     1                         ; CAN 1 Tx IRQ Priority


                PRESERVE8

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
                NOP                               ; Reserved Vector 
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

IRQ_Handler     STMDB   SP!,{R0,PC}               ; Store R0, PC (PC is dummy)
                LDR     R0, =0xFFFFF104           ; Address of INT_VECTOR_1
                LDR     R0,[R0, #0]               ; Address from INT_VECTOR_1
                LDR     R0,[R0, #0]               ; Address of IRQ routine
                STR     R0,[SP, #4]               ; Put address of IRQ on stack
                LDMIA   SP!,{R0,PC}               ; Jump to IRQ and restore R0

FIQ_Handler     PROC
                EXPORT  FIQ_Handler               [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  Watchdog_Handler          [WEAK]
                EXPORT  Timer0_Handler            [WEAK]
                EXPORT  Timer1_Handler            [WEAK]
                EXPORT  Timer2_Handler            [WEAK]
                EXPORT  Timer3_Handler            [WEAK]
                EXPORT  UART0_Handler             [WEAK]
                EXPORT  UART1_Handler             [WEAK]
                EXPORT  SPI0_Handler              [WEAK]
                EXPORT  SPI1_Handler              [WEAK]
                EXPORT  SPI2_Handler              [WEAK]
                EXPORT  Flash_Handler             [WEAK]
                EXPORT  RT_ICE_Rx_Handler         [WEAK]
                EXPORT  RT_ICE_Tx_Handler         [WEAK]
                EXPORT  MSCSS_Timer0_Handler      [WEAK]
                EXPORT  MSCSS_Timer1_Handler      [WEAK]
                EXPORT  ADC1_Handler              [WEAK]
                EXPORT  ADC2_Handler              [WEAK]
                EXPORT  PWM0_Handler              [WEAK]
                EXPORT  PWM0_CM_Handler           [WEAK]
                EXPORT  PWM1_Handler              [WEAK]
                EXPORT  PWM1_CM_Handler           [WEAK]
                EXPORT  PWM2_Handler              [WEAK]
                EXPORT  PWM2_CM_Handler           [WEAK]
                EXPORT  PWM3_Handler              [WEAK]
                EXPORT  PWM3_CM_Handler           [WEAK]
                EXPORT  ER_Handler                [WEAK]
                EXPORT  LIN0_Handler              [WEAK]
                EXPORT  LIN1_Handler              [WEAK]
                EXPORT  CAN_All_Handler           [WEAK]
                EXPORT  CAN0_Rx_Handler           [WEAK]
                EXPORT  CAN1_Rx_Handler           [WEAK]
                EXPORT  CAN0_Tx_Handler           [WEAK]
                EXPORT  CAN1_Tx_Handler           [WEAK]

Watchdog_Handler    
Timer0_Handler      
Timer1_Handler      
Timer2_Handler      
Timer3_Handler      
UART0_Handler       
UART1_Handler       
SPI0_Handler        
SPI1_Handler        
SPI2_Handler        
Flash_Handler       
RT_ICE_Rx_Handler   
RT_ICE_Tx_Handler   
MSCSS_Timer0_Handler
MSCSS_Timer1_Handler
ADC1_Handler        
ADC2_Handler        
PWM0_Handler        
PWM0_CM_Handler     
PWM1_Handler        
PWM1_CM_Handler     
PWM2_Handler        
PWM2_CM_Handler     
PWM3_Handler        
PWM3_CM_Handler     
ER_Handler          
LIN0_Handler        
LIN1_Handler        
CAN_All_Handler     
CAN0_Rx_Handler     
CAN1_Rx_Handler     
CAN0_Tx_Handler     
CAN1_Tx_Handler     

                B       .

                ENDP


; Reset Handler

                EXPORT  Reset_Handler
Reset_Handler   

; Setup Interrupt INT_VECTOR_1 Table Address

INT_VECTOR_1    EQU     0xFFFFF104          ; INT_VECTOR_1 Address
                LDR     R0, =INT_VECTOR_1
                LDR     R1, =IRQ_Table
                STR     R1, [R0, #0]                


; Setup Clock

                IF      CLOCK_SETUP != 0
                LDR     R0, =CGU_BASE

;  If crystal oscillator control requested is different then reset value
                IF      XTAL_OSC_CTRL_Val != 0x00000005
                LDR     R1, =XTAL_OSC_CTRL_Val
                STR     R1, [R0, #XTAL_CTRL_OFS]
                ENDIF

;  Use crystal oscillator instead of LP oscillator to speed up setup
                LDR     R1, =(PLL_XTAL_SEL:OR:AUTOBLOK)
                STR     R1, [R0, #SYS_CLK_CO_OFS] 

;  If PLL is used
                IF      (PLL_CONTROL_Val:AND:PLL_PD) = 0
                LDR     R1, =((PLL_CONTROL_Val:AND:P23EN):OR:PLL_PD)
                STR     R1, [R0, #PLL_CONTROL_OFS]
                LDR     R1, =(PLL_CONTROL_Val:OR:PLL_PD)
                STR     R1, [R0, #PLL_CONTROL_OFS]
                LDR     R1, =PLL_CONTROL_Val
                STR     R1, [R0, #PLL_CONTROL_OFS]

;  Wait until PLL Locked
PLL_Not_Locked  LDR     R2, [R0, #PLL_STATUS_OFS]
                ANDS    R2, R2, #PLL_LOCK
                BEQ     PLL_Not_Locked
                ENDIF

;  Wait until PLL Clock Present
PLL_Not_Present LDR     R2, [R0, #RDET_OFS]
                ANDS    R2, R2, #PLL_PRESENT
                BEQ     PLL_Not_Present

                IF      FDIV_CTRL0_Val != 0x00001001
                LDR     R1, =FDIV_CTRL0_Val
                STR     R1, [R0, #FDIV_CTRL0_OFS]
FDIV0_Locking   LDR     R2, [R0, #RDET_OFS]
                ANDS    R2, R2, #FDIV0_PRESENT
                BEQ     FDIV0_Locking
                ENDIF

                IF      FDIV_CTRL1_Val != 0x00001001
                LDR     R1, =FDIV_CTRL1_Val
                STR     R1, [R0, #FDIV_CTRL1_OFS]
FDIV1_Locking   LDR     R2, [R0, #RDET_OFS]
                ANDS    R2, R2, #FDIV1_PRESENT
                BEQ     FDIV1_Locking
                ENDIF

                IF      FDIV_CTRL2_Val != 0x00001001
                LDR     R1, =FDIV_CTRL2_Val
                STR     R1, [R0, #FDIV_CTRL2_OFS]
FDIV2_Locking   LDR     R2, [R0, #RDET_OFS]
                ANDS    R2, R2, #FDIV2_PRESENT
                BEQ     FDIV0_Locking
                ENDIF

                IF      FDIV_CTRL3_Val != 0x00001001
                LDR     R1, =FDIV_CTRL3_Val
                STR     R1, [R0, #FDIV_CTRL3_OFS]
FDIV3_Locking   LDR     R2, [R0, #RDET_OFS]
                ANDS    R2, R2, #FDIV3_PRESENT
                BEQ     FDIV3_Locking
                ENDIF

                IF      FDIV_CTRL4_Val != 0x00001001
                LDR     R1, =FDIV_CTRL4_Val
                STR     R1, [R0, #FDIV_CTRL4_OFS]
FDIV4_Locking   LDR     R2, [R0, #RDET_OFS]
                ANDS    R2, R2, #FDIV4_PRESENT
                BEQ     FDIV4_Locking
                ENDIF

                IF      FDIV_CTRL5_Val != 0x00001001
                LDR     R1, =FDIV_CTRL5_Val
                STR     R1, [R0, #FDIV_CTRL5_OFS]
FDIV5_Locking   LDR     R2, [R0, #RDET_OFS]
                ANDS    R2, R2, #FDIV5_PRESENT
                BEQ     FDIV5_Locking
                ENDIF

                IF      FDIV_CTRL6_Val != 0x00001001
                LDR     R1, =FDIV_CTRL6_Val
                STR     R1, [R0, #FDIV_CTRL6_OFS]
FDIV6_Locking   LDR     R2, [R0, #RDET_OFS]
                ANDS    R2, R2, #FDIV6_PRESENT
                BEQ     FDIV6_Locking
                ENDIF

                IF      SYS_CLK_Val != 0
                LDR     R1, =SYS_CLK_Val      ; Setup SYS Clock Config
                STR     R1, [R0, #SYS_CLK_CO_OFS] 
                ENDIF

                ENDIF   ; CLOCK_SETUP


; Setup Flash Controller

                IF      FLASH_SETUP != 0
                LDR     R0, =FMC_BASE
                LDR     R1, =FCTR_Val
                STR     R1, [R0, #FCTR_OFS] 
                LDR     R1, =FBWST_Val
                STR     R1, [R0, #FBWST_OFS] 
                ENDIF   ; FLASH_SETUP


; Setup Static Memory Controller

                IF      SMC_SETUP != 0

                ; Enable alternate pin functions for address and data bus
                ; and control lines (CS0, BLS0, BLS1 and OEN)
                LDR     R0, =SCU_SFSP0_BASE
                MOV     R1, #EXT_SRAM_PIN_Val
                STR     R1, [R0, #SFSP_10_OFS] 
                STR     R1, [R0, #SFSP_11_OFS] 
                STR     R1, [R0, #SFSP_12_OFS] 
                STR     R1, [R0, #SFSP_13_OFS] 
                STR     R1, [R0, #SFSP_14_OFS] 
                STR     R1, [R0, #SFSP_15_OFS] 
                STR     R1, [R0, #SFSP_18_OFS] 
                STR     R1, [R0, #SFSP_19_OFS] 
                STR     R1, [R0, #SFSP_20_OFS] 
                STR     R1, [R0, #SFSP_21_OFS] 
                STR     R1, [R0, #SFSP_22_OFS] 
                STR     R1, [R0, #SFSP_23_OFS] 

                LDR     R0, =SCU_SFSP1_BASE
                STR     R1, [R0, #SFSP_1_OFS] 
                STR     R1, [R0, #SFSP_2_OFS] 
                STR     R1, [R0, #SFSP_3_OFS] 
                STR     R1, [R0, #SFSP_4_OFS] 
                STR     R1, [R0, #SFSP_5_OFS] 
                STR     R1, [R0, #SFSP_6_OFS] 
                STR     R1, [R0, #SFSP_7_OFS] 
                STR     R1, [R0, #SFSP_8_OFS] 
                STR     R1, [R0, #SFSP_12_OFS] 
                STR     R1, [R0, #SFSP_14_OFS] 
                STR     R1, [R0, #SFSP_15_OFS] 
                STR     R1, [R0, #SFSP_16_OFS] 
                STR     R1, [R0, #SFSP_17_OFS] 
                STR     R1, [R0, #SFSP_18_OFS] 
                STR     R1, [R0, #SFSP_19_OFS] 
                STR     R1, [R0, #SFSP_20_OFS] 
                STR     R1, [R0, #SFSP_21_OFS] 

                LDR     R0, =SCU_SFSP2_BASE
                STR     R1, [R0, #SFSP_0_OFS] 
                STR     R1, [R0, #SFSP_1_OFS] 
                STR     R1, [R0, #SFSP_2_OFS] 
                STR     R1, [R0, #SFSP_3_OFS] 
                STR     R1, [R0, #SFSP_4_OFS] 
                STR     R1, [R0, #SFSP_5_OFS] 
                STR     R1, [R0, #SFSP_6_OFS] 
                STR     R1, [R0, #SFSP_7_OFS] 
                STR     R1, [R0, #SFSP_14_OFS] 
                STR     R1, [R0, #SFSP_15_OFS] 

                LDR     R0, =SMC_BASE

                IF      SMC_BANK0_SETUP != 0
                MOV     R1, #SMBIDCYR0_Val
                STR     R1, [R0, #SMBIDCYR0_OFS] 
                MOV     R1, #SMBWST1R0_Val
                STR     R1, [R0, #SMBWST1R0_OFS] 
                MOV     R1, #SMBWST2R0_Val
                STR     R1, [R0, #SMBWST2R0_OFS] 
                MOV     R1, #SMBWSTOENR0_Val
                STR     R1, [R0, #SMBWSTOENR0_OFS] 
                MOV     R1, #SMBWSTWENR0_Val
                STR     R1, [R0, #SMBWSTWENR0_OFS] 
                MOV     R1, #SMBCR0_Val
                STR     R1, [R0, #SMBCR0_OFS] 
                ENDIF   ; SMC_BANK0_SETUP

                IF      SMC_BANK1_SETUP != 0
                MOV     R1, #SMBIDCYR1_Val
                STR     R1, [R0, #SMBIDCYR1_OFS] 
                MOV     R1, #SMBWST1R1_Val
                STR     R1, [R0, #SMBWST1R1_OFS] 
                MOV     R1, #SMBWST2R1_Val
                STR     R1, [R0, #SMBWST2R1_OFS] 
                MOV     R1, #SMBWSTOENR1_Val
                STR     R1, [R0, #SMBWSTOENR1_OFS] 
                MOV     R1, #SMBWSTWENR1_Val
                STR     R1, [R0, #SMBWSTWENR1_OFS] 
                MOV     R1, #SMBCR1_Val
                STR     R1, [R0, #SMBCR1_OFS] 
                ENDIF   ; SMC_BANK1_SETUP

                IF      SMC_BANK2_SETUP != 0
                MOV     R1, #SMBIDCYR2_Val
                STR     R1, [R0, #SMBIDCYR2_OFS] 
                MOV     R1, #SMBWST1R2_Val
                STR     R1, [R0, #SMBWST1R2_OFS] 
                MOV     R1, #SMBWST2R2_Val
                STR     R1, [R0, #SMBWST2R2_OFS] 
                MOV     R1, #SMBWSTOENR2_Val
                STR     R1, [R0, #SMBWSTOENR2_OFS] 
                MOV     R1, #SMBWSTWENR2_Val
                STR     R1, [R0, #SMBWSTWENR2_OFS] 
                MOV     R1, #SMBCR2_Val
                STR     R1, [R0, #SMBCR2_OFS] 
                ENDIF   ; SMC_BANK2_SETUP

                IF      SMC_BANK3_SETUP != 0
                MOV     R1, #SMBIDCYR3_Val
                STR     R1, [R0, #SMBIDCYR3_OFS] 
                MOV     R1, #SMBWST1R3_Val
                STR     R1, [R0, #SMBWST1R3_OFS] 
                MOV     R1, #SMBWST2R3_Val
                STR     R1, [R0, #SMBWST2R3_OFS] 
                MOV     R1, #SMBWSTOENR3_Val
                STR     R1, [R0, #SMBWSTOENR3_OFS] 
                MOV     R1, #SMBWSTWENR3_Val
                STR     R1, [R0, #SMBWSTWENR3_OFS] 
                MOV     R1, #SMBCR3_Val
                STR     R1, [R0, #SMBCR3_OFS] 
                ENDIF   ; SMC_BANK3_SETUP

                IF      SMC_BANK4_SETUP != 0
                MOV     R1, #SMBIDCYR4_Val
                STR     R1, [R0, #SMBIDCYR4_OFS] 
                MOV     R1, #SMBWST1R4_Val
                STR     R1, [R0, #SMBWST1R4_OFS] 
                MOV     R1, #SMBWST2R4_Val
                STR     R1, [R0, #SMBWST2R4_OFS] 
                MOV     R1, #SMBWSTOENR4_Val
                STR     R1, [R0, #SMBWSTOENR4_OFS] 
                MOV     R1, #SMBWSTWENR4_Val
                STR     R1, [R0, #SMBWSTWENR4_OFS] 
                MOV     R1, #SMBCR4_Val
                STR     R1, [R0, #SMBCR4_OFS] 
                ENDIF   ; SMC_BANK4_SETUP

                IF      SMC_BANK5_SETUP != 0
                MOV     R1, #SMBIDCYR5_Val
                STR     R1, [R0, #SMBIDCYR5_OFS] 
                MOV     R1, #SMBWST1R5_Val
                STR     R1, [R0, #SMBWST1R5_OFS] 
                MOV     R1, #SMBWST2R5_Val
                STR     R1, [R0, #SMBWST2R5_OFS] 
                MOV     R1, #SMBWSTOENR5_Val
                STR     R1, [R0, #SMBWSTOENR5_OFS] 
                MOV     R1, #SMBWSTWENR5_Val
                STR     R1, [R0, #SMBWSTWENR5_OFS] 
                MOV     R1, #SMBCR5_Val
                STR     R1, [R0, #SMBCR5_OFS] 
                ENDIF   ; SMC_BANK5_SETUP

                IF      SMC_BANK6_SETUP != 0
                MOV     R1, #SMBIDCYR6_Val
                STR     R1, [R0, #SMBIDCYR6_OFS] 
                MOV     R1, #SMBWST1R6_Val
                STR     R1, [R0, #SMBWST1R6_OFS] 
                MOV     R1, #SMBWST2R6_Val
                STR     R1, [R0, #SMBWST2R6_OFS] 
                MOV     R1, #SMBWSTOENR6_Val
                STR     R1, [R0, #SMBWSTOENR6_OFS] 
                MOV     R1, #SMBWSTWENR6_Val
                STR     R1, [R0, #SMBWSTWENR6_OFS] 
                MOV     R1, #SMBCR6_Val
                STR     R1, [R0, #SMBCR6_OFS] 
                ENDIF   ; SMC_BANK6_SETUP

                IF      SMC_BANK7_SETUP != 0
                MOV     R1, #SMBIDCYR7_Val
                STR     R1, [R0, #SMBIDCYR7_OFS] 
                MOV     R1, #SMBWST1R7_Val
                STR     R1, [R0, #SMBWST1R7_OFS] 
                MOV     R1, #SMBWST2R7_Val
                STR     R1, [R0, #SMBWST2R7_OFS] 
                MOV     R1, #SMBWSTOENR7_Val
                STR     R1, [R0, #SMBWSTOENR7_OFS] 
                MOV     R1, #SMBWSTWENR7_Val
                STR     R1, [R0, #SMBWSTWENR7_OFS] 
                MOV     R1, #SMBCR7_Val
                STR     R1, [R0, #SMBCR7_OFS] 
                ENDIF   ; SMC_BANK7_SETUP

                ENDIF   ; SMC_SETUP


; Copy Exception Vectors to Internal RAM

                IF      :DEF:RAM_INTVEC
                ADR     R8, Vectors         ; Source
                LDR     R9, =RAM_BASE       ; Destination
                LDMIA   R8!, {R0-R7}        ; Load Vectors 
                STMIA   R9!, {R0-R7}        ; Store Vectors 
                LDMIA   R8!, {R0-R7}        ; Load Handler Addresses 
                STMIA   R9!, {R0-R7}        ; Store Handler Addresses
                ENDIF


; Setup Stack for each mode

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
