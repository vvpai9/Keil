;/*****************************************************************************/
;/* iMX27.S: Startup file for Freescale i.MX27 device series                  */
;/*****************************************************************************/
;/* <<< Use Configuration Wizard in Context Menu >>>                          */ 
;/*****************************************************************************/
;/* This file is part of the uVision/ARM development tools.                   */
;/* Copyright (c) 2005-2008 Keil Software. All rights reserved.               */
;/* This software may only be used under the terms of a valid, current,       */
;/* end user licence from KEIL for a compatible version of KEIL software      */
;/* development tools. Nothing else gives you the right to use this software. */
;/*****************************************************************************/


; The iMX27.S code is executed after CPU Reset. This file may be 
; translated with the following SET symbols. In uVision these SET 
; symbols are entered under Options - ASM - Define.
;
; CLOCK_NO_INIT:   if set, the clock controller is not initialized
;
; ESDRAMC_NO_INIT: if set, the enhanced SDRAM controller is not initialized
;
; WEIM_NO_INIT:    if set, the wireless external flash controller (WEIM) is not 
;                  initialized
;
; NFC_NO_INIT:     if set, the NAND flash controller (NFC) is not initialized
;
; RAM_HADR:        if set, exception handler addresses are copied to on-chip RAM


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
IRQ_Stack_Size  EQU     0x00000000
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


;----------------------- Memory Definitions ------------------------------------

; Internal Memory Base Addresses
IROM_BASE       EQU     0x00000000      ; 24 kB
IRAM_BASE       EQU     0xFFFF4C00      ; 45 kB

; External Memory Base Addresses
CSD0_BASE       EQU     0xA0000000   
CSD1_BASE       EQU     0xB0000000
CS0_BASE        EQU     0xC0000000
CS1_BASE        EQU     0xC8000000
CS2_BASE        EQU     0xD0000000
CS3_BASE        EQU     0xD2000000
CS4_BASE        EQU     0xD4000000
CS5_BASE        EQU     0xD6000000


;----------------------- System Control Definitions ----------------------------

; System Control User Interface
SYSTEM_BASE     EQU     0x10027800      ; System Control                Base Adr
CID_OFS         EQU     0x00            ; Chip ID                        Adr Ofs
FMCR_OFS        EQU     0x14            ; Function Multiplexing Control  Adr Ofs
GPCR_OFS        EQU     0x18            ; Global Peripheral Control      Adr Ofs
WBCR_OFS        EQU     0x1C            ; Well Bias Control              Adr Ofs
DSCR1_OFS       EQU     0x20            ; Drive Strength Control 1       Adr Ofs
DSCR2_OFS       EQU     0x24            ; Drive Strength Control 2       Adr Ofs
DSCR3_OFS       EQU     0x28            ; Drive Strength Control 3       Adr Ofs
DSCR4_OFS       EQU     0x2C            ; Drive Strength Control 4       Adr Ofs
DSCR5_OFS       EQU     0x30            ; Drive Strength Control 5       Adr Ofs
DSCR6_OFS       EQU     0x34            ; Drive Strength Control 6       Adr Ofs
DSCR7_OFS       EQU     0x38            ; Drive Strength Control 7       Adr Ofs
DSCR8_OFS       EQU     0x3C            ; Drive Strength Control 8       Adr Ofs
DSCR9_OFS       EQU     0x40            ; Drive Strength Control 9       Adr Ofs
DSCR10_OFS      EQU     0x44            ; Drive Strength Control 10      Adr Ofs
DSCR11_OFS      EQU     0x48            ; Drive Strength Control 11      Adr Ofs
DSCR12_OFS      EQU     0x4C            ; Drive Strength Control 12      Adr Ofs
DSCR13_OFS      EQU     0x50            ; Drive Strength Control 13      Adr Ofs
PSCR_OFS        EQU     0x54            ; Pull Strength Control          Adr Ofs
PCSR_OFS        EQU     0x58            ; Priority Control and Select    Adr Ofs
PMCR_OFS        EQU     0x60            ; Power Management Control       Adr Ofs
DCVR0_OFS       EQU     0x64            ; DPTC Comparator Value 0        Adr Ofs
DCVR1_OFS       EQU     0x68            ; DPTC Comparator Value 1        Adr Ofs
DCVR2_OFS       EQU     0x6C            ; DPTC Comparator Value 2        Adr Ofs
DCVR3_OFS       EQU     0x70            ; DPTC Comparator Value 3        Adr Ofs


;----------------------- AHB-Lite IP Interface (AIPI) Definitions --------------

; AHB-Lite IP Interface (AIPI) Module User Interface
AIPI1_BASE      EQU     0x10000000      ; AIPI1 Module                  Base Adr
AIPI2_BASE      EQU     0x10020000      ; AIPI2 Module                  Base Adr
PSR0_OFS        EQU     0x00            ; Peripheral Size Register 0     Adr Ofs
PSR1_OFS        EQU     0x04            ; Peripheral Size Register 1     Adr Ofs
PAR_OFS         EQU     0x08            ; Peripheral Access Register     Adr Ofs

; <e> AHB-Lite IP Interface Module Configuration
AIPI_SETUP      EQU     1

;   <h> Peripheral Access Sizes
;     <o0.0..1> AIPI1 Control
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o1.0..1> DMA
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o2.0..1> WDOG
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o3.0..1> GPT1
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o4.0..1> GPT2
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o5.0..1> GPT3
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o6.0..1> PWM
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o7.0..1> RTC
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o8.0..1> KPP
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o9.0..1> 1-Wire
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o10.0..1> UART1
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o11.0..1> UART2
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o12.0..1> UART3
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o13.0..1> UART4
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o14.0..1> CSPI1
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o15.0..1> CSPI2
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o16.0..1> SSI1
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o17.0..1> SSI2
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o18.0..1> I2C
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o19.0..1> SDHC1
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o20.0..1> SDHC2
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o21.0..1> GPIO
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o22.0..1> AUDMUX
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o23.0..1> CSPI3
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o24.0..1> AIPI2 Control
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o25.0..1> LCDC
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o26.0..1> SLCDC
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o27.0..1> USB OTG
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o28.0..1> USB OTG
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o29.0..1> EMMA
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o30.0..1> CRM
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;     <o31.0..1> FIRI
;                   <0=> 8-bit <1=> 16-bit <2=> 32-bit <3=> Unoccupied
;   </h>
AIPI1_PERI0     EQU     0x02
AIPI1_PERI1     EQU     0x02
AIPI1_PERI2     EQU     0x01
AIPI1_PERI3     EQU     0x02
AIPI1_PERI4     EQU     0x02
AIPI1_PERI5     EQU     0x02
AIPI1_PERI6     EQU     0x02
AIPI1_PERI7     EQU     0x02
AIPI1_PERI8     EQU     0x01
AIPI1_PERI9     EQU     0x01
AIPI1_PERI10    EQU     0x02
AIPI1_PERI11    EQU     0x02
AIPI1_PERI12    EQU     0x02
AIPI1_PERI13    EQU     0x02
AIPI1_PERI14    EQU     0x02
AIPI1_PERI15    EQU     0x02
AIPI1_PERI16    EQU     0x02
AIPI1_PERI17    EQU     0x02
AIPI1_PERI18    EQU     0x01
AIPI1_PERI19    EQU     0x02
AIPI1_PERI20    EQU     0x02
AIPI1_PERI21    EQU     0x02
AIPI1_PERI22    EQU     0x02
AIPI1_PERI23    EQU     0x02
AIPI2_PERI0     EQU     0x02
AIPI2_PERI1     EQU     0x02
AIPI2_PERI2     EQU     0x02
AIPI2_PERI4     EQU     0x02
AIPI2_PERI5     EQU     0x02
AIPI2_PERI6     EQU     0x02
AIPI2_PERI7     EQU     0x02
AIPI2_PERI8     EQU     0x02

AIPI1_PSR0_Val  EQU     ((AIPI1_PERI0  & 0x01)        | \
                        ((AIPI1_PERI1  & 0x01) << 1 ) | \
                        ((AIPI1_PERI2  & 0x01) << 2 ) | \
                        ((AIPI1_PERI3  & 0x01) << 3 ) | \
                        ((AIPI1_PERI4  & 0x01) << 4 ) | \
                        ((AIPI1_PERI5  & 0x01) << 5 ) | \
                        ((AIPI1_PERI6  & 0x01) << 6 ) | \
                        ((AIPI1_PERI7  & 0x01) << 7 ) | \
                        ((AIPI1_PERI8  & 0x01) << 8 ) | \
                        ((AIPI1_PERI9  & 0x01) << 9 ) | \
                        ((AIPI1_PERI10 & 0x01) << 10) | \
                        ((AIPI1_PERI11 & 0x01) << 11) | \
                        ((AIPI1_PERI12 & 0x01) << 12) | \
                        ((AIPI1_PERI13 & 0x01) << 13) | \
                        ((AIPI1_PERI14 & 0x01) << 14) | \
                        ((AIPI1_PERI15 & 0x01) << 15) | \
                        ((AIPI1_PERI16 & 0x01) << 16) | \
                        ((AIPI1_PERI17 & 0x01) << 17) | \
                        ((AIPI1_PERI18 & 0x01) << 18) | \
                        ((AIPI1_PERI19 & 0x01) << 19) | \
                        ((AIPI1_PERI20 & 0x01) << 20) | \
                        ((AIPI1_PERI21 & 0x01) << 21) | \
                        ((AIPI1_PERI22 & 0x01) << 22) | \
                        ((AIPI1_PERI23 & 0x01) << 23) | \
                        ( 0x00000000                ) )
AIPI1_PSR1_Val  EQU    (((AIPI1_PERI0  & 0x02) >> 1 ) | \
                        ((AIPI1_PERI1  & 0x02)      ) | \
                        ((AIPI1_PERI2  & 0x02) << 1 ) | \
                        ((AIPI1_PERI3  & 0x02) << 2 ) | \
                        ((AIPI1_PERI4  & 0x02) << 3 ) | \
                        ((AIPI1_PERI5  & 0x02) << 4 ) | \
                        ((AIPI1_PERI6  & 0x02) << 5 ) | \
                        ((AIPI1_PERI7  & 0x02) << 6 ) | \
                        ((AIPI1_PERI8  & 0x02) << 7 ) | \
                        ((AIPI1_PERI9  & 0x02) << 8 ) | \
                        ((AIPI1_PERI10 & 0x02) << 9 ) | \
                        ((AIPI1_PERI11 & 0x02) << 10) | \
                        ((AIPI1_PERI12 & 0x02) << 11) | \
                        ((AIPI1_PERI13 & 0x02) << 12) | \
                        ((AIPI1_PERI14 & 0x02) << 13) | \
                        ((AIPI1_PERI15 & 0x02) << 14) | \
                        ((AIPI1_PERI16 & 0x02) << 15) | \
                        ((AIPI1_PERI17 & 0x02) << 16) | \
                        ((AIPI1_PERI18 & 0x02) << 17) | \
                        ((AIPI1_PERI19 & 0x02) << 18) | \
                        ((AIPI1_PERI20 & 0x02) << 19) | \
                        ((AIPI1_PERI21 & 0x02) << 20) | \
                        ((AIPI1_PERI22 & 0x02) << 21) | \
                        ((AIPI1_PERI23 & 0x02) << 22) | \
                        ( 0xFF000000                ) )
AIPI2_PSR0_Val  EQU     ((AIPI2_PERI0  & 0x01)        | \
                        ((AIPI2_PERI1  & 0x01) << 1 ) | \
                        ((AIPI2_PERI2  & 0x01) << 2 ) | \
                        ((AIPI2_PERI4  & 0x01) << 4 ) | \
                        ((AIPI2_PERI5  & 0x01) << 5 ) | \
                        ((AIPI2_PERI6  & 0x01) << 6 ) | \
                        ((AIPI2_PERI7  & 0x01) << 7 ) | \
                        ((AIPI2_PERI8  & 0x01) << 8 ) | \
                        ( 0x3FDC0000                ) )
AIPI2_PSR1_Val  EQU    (((AIPI2_PERI0  & 0x02) >> 1 ) | \
                        ((AIPI2_PERI1  & 0x02)      ) | \
                        ((AIPI2_PERI2  & 0x02) << 1 ) | \
                        ((AIPI2_PERI4  & 0x02) << 3 ) | \
                        ((AIPI2_PERI5  & 0x02) << 4 ) | \
                        ((AIPI2_PERI6  & 0x02) << 5 ) | \
                        ((AIPI2_PERI7  & 0x02) << 6 ) | \
                        ((AIPI2_PERI8  & 0x02) << 7 ) | \
                        ( 0x3FFFFC08                ) )

;   <h> Peripheral Access Rights
;     <o0.0> AIPI1 Control Supervisor Access Only Enable
;     <o0.1> DMA Supervisor Access Only Enable
;     <o0.2> WDOG Supervisor Access Only Enable
;     <o0.3> GPT1 Supervisor Access Only Enable
;     <o0.4> GPT2 Supervisor Access Only Enable
;     <o0.5> GPT3 Supervisor Access Only Enable
;     <o0.6> PWM Supervisor Access Only Enable
;     <o0.7> RTC Supervisor Access Only Enable
;     <o0.8> KPP Supervisor Access Only Enable
;     <o0.9> 1-Wire Supervisor Access Only Enable
;     <o0.10> UART1 Supervisor Access Only Enable
;     <o0.11> UART2 Supervisor Access Only Enable
;     <o0.12> UART3 Supervisor Access Only Enable
;     <o0.13> UART4 Supervisor Access Only Enable
;     <o0.14> CSPI1 Supervisor Access Only Enable
;     <o0.15> CSPI2 Supervisor Access Only Enable
;     <o0.16> SSI1 Supervisor Access Only Enable
;     <o0.17> SSI2 Supervisor Access Only Enable
;     <o0.18> I2C Supervisor Access Only Enable
;     <o0.19> SDHC1 Supervisor Access Only Enable
;     <o0.20> SDHC2 Supervisor Access Only Enable
;     <o0.21> GPIO Supervisor Access Only Enable
;     <o0.22> AUDMUX Supervisor Access Only Enable
;     <o0.23> CSPI3 Supervisor Access Only Enable
;     <o1.0> AIPI2 Control Supervisor Access Only Enable
;     <o1.1> LCDC Supervisor Access Only Enable
;     <o1.2> SLCDC Supervisor Access Only Enable
;     <o1.4> USB OTG Supervisor Access Only Enable
;     <o1.5> USB OTG Supervisor Access Only Enable
;     <o1.6> EMMA Supervisor Access Only Enable
;     <o1.7> CRM Supervisor Access Only Enable
;     <o1.8> FIRI Supervisor Access Only Enable
;   </h>
AIPI1_PAR_Val   EQU     0xFFDFFFFF
AIPI2_PAR_Val   EQU     0xFFFFFF7F

; </e> AHB-Lite IP Interface Module Configuration


;----------------------- PLL Clock Definitions ---------------------------------

; PLL Clock Controller User Interface
CLOCK_BASE      EQU     0x10027000      ; PLL Clock Controller          Base Adr
CSCR_OFS        EQU     0x00            ; Clock Source Control           Adr Ofs
MPCTL0_OFS      EQU     0x04            ; MPLL Control 0                 Adr Ofs
MPCTL1_OFS      EQU     0x08            ; MPLL Control 1                 Adr Ofs
SPCTL0_OFS      EQU     0x0C            ; SPLL Control 0                 Adr Ofs
SPCTL1_OFS      EQU     0x10            ; SPLL Control 1                 Adr Ofs
OSC26MCTL_OFS   EQU     0x14            ; Oscillator 26M                 Adr Ofs
PCDR0_OFS       EQU     0x18            ; Peripheral Clock Divider 0     Adr Ofs
PCDR1_OFS       EQU     0x1C            ; Peripheral Clock Divider 1     Adr Ofs
PCCR0_OFS       EQU     0x20            ; Peripheral Clock Control 0     Adr Ofs
PCCR1_OFS       EQU     0x24            ; Peripheral Clock Control 1     Adr Ofs
CCSR_OFS        EQU     0x28            ; Clock Control Status           Adr Ofs
WKGDCTL_OFS     EQU     0x34            ; Wakeup Guard Mode Control      Adr Ofs

; Constants
OSC26M_PEAK_FLD EQU     (0x03<<16)      ; Oscillator Current Amplitude     Field
OSC26M_AMP_HIGH EQU     (0x02<<16)      ; Oscillator Current Amp High      Value
OSC26M_AMP_LOW  EQU     (0x01<<16)      ; Oscillator Current Amp Low       Value
AGC_FLD         EQU     (0x3F<< 8)      ; Automatic Gain Control           Field
AGC_VAL_4       EQU     (0x04<< 8)      ; Automatic Gain Control 4         Value
AGC_VAL_1       EQU     (0x01<< 8)      ; Automatic Gain Control 1         Value
UPDATE_DIS_BIT  EQU     (0x01<<31)      ; Disable Clock Update             Bit
SPLL_RESTART_BIT EQU    (0x01<<19)      ; SPLL Restart                     Bit
MPLL_RESTART_BIT EQU    (0x01<<18)      ; MPLL Restart                     Bit
SP_SEL_BIT      EQU     (0x01<<17)      ; SPLL Select                      Bit
MCU_SEL_BIT     EQU     (0x01<<16)      ; MPLL Select                      Bit
SPEN_BIT        EQU     (0x01<< 1)      ; SPLL Enable                      Bit
MPEN_BIT        EQU     (0x01<< 0)      ; MPLL Enable                      Bit
LF_BIT          EQU     (0x01<<15)      ; Lock Flag                        Bit

; <e> Clock Configuration
CLOCK_SETUP     EQU     1

;   <h> Clock Source Control Register (CSCR)
;     <o0.28..30> USB_DIV: USB Clock Divider <1-8><#-1>
;     <o0.24..25> SD_CNT: Shut-Down Control
;                   <0=> DPLL shut-down after next rising edge of CLK32
;                   <1=> DPLL shut-down after second rising edge of CLK32
;                   <2=> DPLL shut-down after third rising edge of CLK32
;                   <3=> DPLL shut-down after fourth rising edge of CLK32
;     <o0.23> SSI2_SEL: SSI2 Baud Source Select
;                   <0=> Fractional divider from SPLL
;                   <1=> Fractional divider from MPLL
;     <o0.22> SSI1_SEL: SSI1 Baud Source Select
;                   <0=> Fractional divider from SPLL
;                   <1=> Fractional divider from MPLL
;     <o0.21> H264: H264 CCLK Source Select
;                   <0=> Divider is from SPLL
;                   <1=> Divider is from MPLL
;     <o0.20> MSHC_SEL: MSHC CCLK Source Select
;                   <0=> Divider is from SPLL
;                   <1=> Divider is from MPLL
;     <o0.17> SP_SEL: SPLL Clock Source Select
;                   <0=> Internal premultiplier
;                   <1=> External high frequency clock
;     <o0.16> MCU_SEL: MPLL Clock Source Select
;                   <0=> Internal premultiplier
;                   <1=> External high frequency clock
;     <o0.15> ARM_SRC: ARM Clock Source
;                   <0=> MPLL CLK * 2 / 3
;                   <1=> MPLL CLK
;     <o0.12..13> ARM_DIV: Divider Value for ARM Clock <1-4><#-1>
;     <o0.8..9> AHB_DIV: Divider Value for AHB Clock <1-4><#-1>
;     <o0.4> OSC26M_DIV1P5: Oscillator 26M Divide Enable
;                   <0=> OSC26M output divide by 1
;                   <1=> OSC26M output divide by 1.5
;     <o0.3> OSC26M_DIS: Oscillator Disable
;     <o0.2> FPM_EN: Frequency Premultiplier Enable
;     <o0.1> SPEN: Serial Peripheral PLL Enable
;     <o0.0> MPEN: MPLL Enable
;   </h>
CSCR_Val        EQU     0x33F30107

;   <h> MPU and System PLL Control Register 0 (MPCTL0)
;     <i> fDPLL = 2*fREF*((MFI+MFN/(MFD+1))/(PD+1))
;     <i> fREF = 1024*32.768 kHz or 1024*32.0 kHz or 26  MHz
;     <i> MFI - Multiplication Factor (Integer)
;     <i> MFN - Multiplication Factor (Numerator)
;     <i> MFD - Multiplication Factor (Denominator)
;     <i> PD  - Predivider Factor
;     <o0.31> CPLM: Phase Lock Mode
;                   <0=> Frequency Only Lock mode (FOL)
;                   <1=> Frequency and Phase Lock mode (FPL)
;     <o0.26..29> PD: Predivider Factor <0-15>
;     <o0.16..25> MFD: Multiplication Factor (Denominator) <1-1023>
;     <o0.10..13> MFI: Multiplication Factor (Integer) <5-15>
;     <h> MFN: Multiplication Factor (Numerator)
;       <o0.9> Sign
;                   <0=> +
;                   <1=> -
;       <o0.0..8> Value <0-510>
;     </h>
;   </h>
;   <h> MPU and System PLL Control Register 1 (MPCTL1)
;     <o1.6> BRMO: BRM Order
;                   <0=> MF Fractional Part is between 1/10 and 9/10
;                   <1=> MF Fractional Part less than 1/10 or more than 9/10
;   </h>
MPCTL0_Val      EQU     0x00331C23
MPCTL1_Val      EQU     0x00000000

;   <h> Serial Peripheral PLL Control Register 0 (SPCTL0)
;     <i> fDPLL = 2*fREF*((MFI+MFN/(MFD+1))/(PD+1))
;     <i> fREF = 1024*32.768 kHz or 1024*32.0 kHz or 26  MHz
;     <i> MFI - Multiplication Factor (Integer)
;     <i> MFN - Multiplication Factor (Numerator)
;     <i> MFD - Multiplication Factor (Denominator)
;     <i> PD  - Predivider Factor
;     <o0.31> CPLM: Phase Lock Mode
;                   <0=> Frequency Only Lock mode (FOL)
;                   <1=> Frequency and Phase Lock mode (FPL)
;     <o0.26..29> PD: Predivider Factor <0-15>
;     <o0.16..25> MFD: Multiplication Factor (Denominator) <1-1023>
;     <o0.10..13> MFI: Multiplication Factor (Integer) <5-15>
;     <h> MFN: Multiplication Factor (Numerator)
;       <o0.9> Sign
;                   <0=> +
;                   <1=> -
;       <o0.0..8> Value <0-510>
;     </h>
;   </h>
;   <h> Serial Peripheral PLL Control Register 1 (SPCTL1)
;     <o1.6> BRMO: BRM Order
;                   <0=> MF Fractional Part is between 1/10 and 9/10
;                   <1=> MF Fractional Part less than 1/10 or more than 9/10
;   </h>
SPCTL0_Val      EQU     0x040C2403
SPCTL1_Val      EQU     0x00000000

;   <h> Peripheral Clock Divider Register 0 (PCDR0)
;     <o0.26..31> SSI2DIV: SSI2 Baud Clock Divider
;                   <0=>      2 <1=>    2.5 <2=>     3 <3=>   3.5 <4=>     4
;                   <5=>    4.5 <6=>      5 <7=>   5.5 <8=>     6 <9=>   6.5
;                   <10=>     7 <11=>   7.5 <12=>    8 <13=>  8.5 <14=>    9
;                   <15=>   9.5 <16=>    10 <17=> 10.5 <18=>   11 <19=> 11.5
;                   <20=>    12 <21=>  12.5 <22=>   13 <23=> 13.5 <24=>   14
;                   <25=>  14.5 <26=>    15 <27=> 15.5 <28=>   16 <29=> 16.5
;                   <30=>    17 <31=>  17.5 <32=>   18 <33=> 18.5 <34=>   19
;                   <35=>  19.5 <36=>    20 <37=> 20.5 <38=>   21 <39=> 21.5
;                   <40=>    22 <41=>  22.5 <42=>   23 <43=> 23.5 <44=>   24
;                   <45=>  24.5 <46=>    25 <47=> 25.5 <48=>   26 <49=> 26.5
;                   <50=>    27 <51=>  27.5 <52=>   28 <53=> 28.5 <54=>   29
;                   <55=>  29.5 <56=>    30 <57=> 30.5 <58=>   31 <59=> 31.5
;                   <60=>    32 <61=>  32.5 <62=>   33 <63=> 33.5
;     <o0.25> CLKO_EN: Clock Out Enable
;     <o0.22..24> CLKO_DIV: Clock Out Divider <1-8><#-1>
;     <o0.16..21> SSI1DIV: SSI1 Baud Clock Divider
;                   <0=>      2 <1=>    2.5 <2=>     3 <3=>   3.5 <4=>     4
;                   <5=>    4.5 <6=>      5 <7=>   5.5 <8=>     6 <9=>   6.5
;                   <10=>     7 <11=>   7.5 <12=>    8 <13=>  8.5 <14=>    9
;                   <15=>   9.5 <16=>    10 <17=> 10.5 <18=>   11 <19=> 11.5
;                   <20=>    12 <21=>  12.5 <22=>   13 <23=> 13.5 <24=>   14
;                   <25=>  14.5 <26=>    15 <27=> 15.5 <28=>   16 <29=> 16.5
;                   <30=>    17 <31=>  17.5 <32=>   18 <33=> 18.5 <34=>   19
;                   <35=>  19.5 <36=>    20 <37=> 20.5 <38=>   21 <39=> 21.5
;                   <40=>    22 <41=>  22.5 <42=>   23 <43=> 23.5 <44=>   24
;                   <45=>  24.5 <46=>    25 <47=> 25.5 <48=>   26 <49=> 26.5
;                   <50=>    27 <51=>  27.5 <52=>   28 <53=> 28.5 <54=>   29
;                   <55=>  29.5 <56=>    30 <57=> 30.5 <58=>   31 <59=> 31.5
;                   <60=>    32 <61=>  32.5 <62=>   33 <63=> 33.5
;     <o0.10..15> H264DIV: H264 Baud Clock Divider
;                   <0=>      2 <1=>    2.5 <2=>     3 <3=>   3.5 <4=>     4
;                   <5=>    4.5 <6=>      5 <7=>   5.5 <8=>     6 <9=>   6.5
;                   <10=>     7 <11=>   7.5 <12=>    8 <13=>  8.5 <14=>    9
;                   <15=>   9.5 <16=>    10 <17=> 10.5 <18=>   11 <19=> 11.5
;                   <20=>    12 <21=>  12.5 <22=>   13 <23=> 13.5 <24=>   14
;                   <25=>  14.5 <26=>    15 <27=> 15.5 <28=>   16 <29=> 16.5
;                   <30=>    17 <31=>  17.5 <32=>   18 <33=> 18.5 <34=>   19
;                   <35=>  19.5 <36=>    20 <37=> 20.5 <38=>   21 <39=> 21.5
;                   <40=>    22 <41=>  22.5 <42=>   23 <43=> 23.5 <44=>   24
;                   <45=>  24.5 <46=>    25 <47=> 25.5 <48=>   26 <49=> 26.5
;                   <50=>    27 <51=>  27.5 <52=>   28 <53=> 28.5 <54=>   29
;                   <55=>  29.5 <56=>    30 <57=> 30.5 <58=>   31 <59=> 31.5
;                   <60=>    32 <61=>  32.5 <62=>   33 <63=> 33.5
;     <o0.6..9> NFCDIV: NAND Flash Controller Clock Divider <1-16><#-1>
;     <o0.0..5> MSHCDIV: MSHC Clock Divider <1-64><#-1>
;   </h>
PCDR0_Val       EQU     0x12041543

;   <h> Peripheral Clock Divider Register 1 (PCDR1)
;     <o0.24..29> PERDIV4: Peripheral Clock Divider 4 <1-64><#-1>
;     <o0.16..21> PERDIV3: Peripheral Clock Divider 3 <1-64><#-1>
;     <o0.8..13>  PERDIV2: Peripheral Clock Divider 2 <1-64><#-1>
;     <o0.0..5>   PERDIV1: Peripheral Clock Divider 1 <1-64><#-1>
;   </h>
PCDR1_Val       EQU     0x03030303

;   <h> Peripheral Clock Control Register 0 (PCCR0)
;     <o0.31> CSPI1_EN: CSPI1 IPG Clock Enable
;     <o0.30> CSPI2_EN: CSPI2 IPG Clock Enable
;     <o0.29> CSPI3_EN: CSPI1 IPG Clock Enable
;     <o0.28> DMA_EN: DMA IPG Clock Enable
;     <o0.27> EMMA_EN: EMMA IPG Clock Enable
;     <o0.26> FEC_EN: FEC IPG Clock Enable
;     <o0.25> GPIO_EN: GPIO IPG Clock Enable
;     <o0.24> GPT1_EN: GPT1 IPG Clock Enable
;     <o0.23> GPT2_EN: GPT2 IPG Clock Enable
;     <o0.22> GPT3_EN: GPT3 IPG Clock Enable
;     <o0.21> GPT4_EN: GPT4 IPG Clock Enable
;     <o0.20> GPT5_EN: GPT5 IPG Clock Enable
;     <o0.19> GPT6_EN: GPT6 IPG Clock Enable
;     <o0.18> I2C1_EN: I2C1 IPG Clock Enable
;     <o0.17> I2C2_EN: I2C2 IPG Clock Enable
;     <o0.16> IIM_EN: IIM IPG Clock Enable
;     <o0.15> KPP_EN: KPP IPG Clock Enable
;     <o0.14> LCDC_EN: LCDC IPG Clock Enable
;     <o0.13> MSHC_EN: MSHC IPG Clock Enable
;     <o0.12> OWIRE_EN: OWIRE IPG Clock Enable
;     <o0.11> PWM_EN: PWM IPG Clock Enable
;     <o0.9>  RTC_EN: RTC IPG Clock Enable
;     <o0.8>  RTIC_EN: RTIC IPG Clock Enable
;     <o0.7>  SAHARA_EN: SAHARA IPG Clock Enable
;     <o0.6>  SCC_EN: SCC IPG Clock Enable
;     <o0.5>  SDHC1_EN: SDHC1 IPG Clock Enable
;     <o0.4>  SDHC2_EN: SDHC2 IPG Clock Enable
;     <o0.3>  SDHC3_EN: SDHC3 IPG Clock Enable
;     <o0.2>  SLCDC_EN: SLCDC IPG Clock Enable
;     <o0.1>  SSI1_EN: SSI1 IPG Clock Enable
;     <o0.0>  SSI2_EN: SSI2 IPG Clock Enable
;   </h>
PCCR0_Val       EQU     0x060101C0

;   <h> Peripheral Clock Control Register 1 (PCCR1)
;     <o0.31> UART1_EN: UART1 IPG Clock Enable
;     <o0.30> UART2_EN: UART2 IPG Clock Enable
;     <o0.29> UART3_EN: UART3 IPG Clock Enable
;     <o0.28> UART4_EN: UART4 IPG Clock Enable
;     <o0.27> UART5_EN: UART5 IPG Clock Enable
;     <o0.26> UART6_EN: UART6 IPG Clock Enable
;     <o0.25> USB_EN: USB IPG Clock Enable
;     <o0.24> WDT_EN: WDT IPG Clock Enable
;     <o0.23> HCLK_ATA: ATA AHB Clock Enable
;     <o0.22> HCLK_BROM: BROM AHB Clock Enable
;     <o0.21> HCLK_CSI: CSI AHB Clock Enable
;     <o0.20> HCLK_DMA: DMA AHB Clock Enable
;     <o0.19> HCLK_EMI: EMI AHB Clock Enable
;     <o0.18> HCLK_EMMA: EMMA AHB Clock Enable
;     <o0.17> HCLK_FEC: FEC AHB Clock Enable
;     <o0.16> HCLK_H264: H264 AHB Clock Enable
;     <o0.15> HCLK_LCDC: LCDC AHB Clock Enable
;     <o0.14> HCLK_RTIC: RTIC AHB Clock Enable
;     <o0.13> HCLK_SAHARA: SAHARA AHB Clock Enable
;     <o0.12> HCLK_SLCDC: SLCDC AHB Clock Enable
;     <o0.11> HCLK_USB: USB AHB Clock Enable
;     <o0.10> PERCLK1_EN: PERCLK1 Clock Enable
;     <o0.9>  PERCLK2_EN: PERCLK2 Clock Enable
;     <o0.8>  PERCLK3_EN: PERCLK3 Clock Enable
;     <o0.7>  PERCLK4_EN: PERCLK4 Clock Enable
;     <o0.6>  H264_BAUDEN: H264 BAUD Clock Enable
;     <o0.5>  SSI1_BAUDEN: SSI1 BAUD Clock Enable
;     <o0.4>  SSI2_BAUDEN: SSI2 BAUD Clock Enable
;     <o0.3>  NFC_BAUDEN: NFC BAUD Clock Enable
;     <o0.2>  MSHC_BAUDEN: MSHC BAUD Clock Enable
;   </h>
PCCR1_Val       EQU     0xFF4B6848

; </e> Clock Configuration


;----------------------- Enhanced SDRAM Definitions ----------------------------

; Enhanced SDRAM Controller User Interface
ESDRAMC_BASE    EQU     0xD8001000      ; Enhanced SDRAM Controller     Base Adr
ESDCTL0_OFS     EQU     0x00            ; ESDRAM Control 0               Adr Ofs
ESDCFG0_OFS     EQU     0x04            ; ESDRAM Configuration 0         Adr Ofs
ESDCTL1_OFS     EQU     0x08            ; ESDRAM Control 1               Adr Ofs
ESDCFG1_OFS     EQU     0x0C            ; ESDRAM Configuration 1         Adr Ofs
ESDMISC_OFS     EQU     0x10            ; ESDRAM Miscellaneous           Adr Ofs
ESDCDLY1_OFS    EQU     0x20            ; EMDDR Delay Line 1 Config Dbg  Adr Ofs
ESDCDLY2_OFS    EQU     0x24            ; EMDDR Delay Line 2 Config Dbg  Adr Ofs
ESDCDLY3_OFS    EQU     0x28            ; EMDDR Delay Line 3 Config Dbg  Adr Ofs
ESDCDLY4_OFS    EQU     0x2C            ; EMDDR Delay Line 4 Config Dbg  Adr Ofs
ESDCDLY5_OFS    EQU     0x30            ; EMDDR Delay Line 5 Config Dbg  Adr Ofs
ESDCDLYL_OFS    EQU     0x34            ; EMDDR Delay Line Cyc Conf Dbg  Adr Ofs

; Constants
NORMAL_CMD      EQU     (0x0 << 28)     ; NORMAL        Command
PALL_CMD        EQU     (0x1 << 28)     ; Precharge All Command
AREFSH_MODE     EQU     (0x2 << 28)     ; Auto-Refresh  Command
MODE_CMD        EQU     (0x3 << 28)     ; MODE          Command
MREFSH_MODE     EQU     (0x4 << 28)     ; Manual Self Refresh
ESDCTL_MSK      EQU     (0xFFF00000)    ; ESDCTL Register Mask for Init

; <e> Enhanced SDRAM Controller Setup (ESDRAMC)
ESDRAMC_SETUP   EQU     1

;   <e> Enhanced SDRAM Controller Setup for CSD0
ESDRAMC_CSD0_SETUP  EQU 1

;     <h> Enhanced SDRAM Control Register 0 (ESDCTL0)
;       <i> Configures operation of the memory controller
;       <o0.31> SDE: Enhanced SDRAM Controller Enable
;       <o0.27> SP: Supervisor Protect Enable
;       <o0.24..26> ROW: Row Address Width <11-15><#-11>
;       <o0.20..21> COL: Column Address Width <8-10><#-8>
;       <o0.16..17> DSIZ: SDRAM Memory Data Width
;                   <0=> 16-bit memory width aligned to D[31:16]
;                   <1=> 16-bit memory width aligned to D[15:0]
;                   <2=> 32-bit memory width
;                   <3=> Reserved
;       <o0.13..15> SREFR: SDRAM Refresh Rate
;                   <0=> Disabled
;                   <1=> 31.25 us
;                   <2=> 15.62 us
;                   <3=>  7.81 us
;                   <4=>  3.91 us
;                   <5=>  1.95 us
;                   <6=> Reserved
;                   <7=> Reserved
;       <o0.10..11> PWDT: Power Down Timer
;                   <0=> Disabled
;                   <1=> Any time
;                   <2=>  64 clocks (HCLK) after last access
;                   <3=> 128 clocks (HCLK) after last access
;       <o0.8> FP: Full Page
;                   <0=> Burst Length is not set to Full Page
;                   <1=> Burst Length is set to Full Page
;       <o0.7> BL: Burst Length
;                   <0=> 4
;                   <1=> 8
;       <o0.0..5> PRCT: Precharge Timer <0-126:2>
;         <i> Value 0 means that Precharge Timer is Disabled
;     </h>
ESDCTL0_Val     EQU     0x82226080

;     <h> Enhanced SDRAM Configuration Register 0 (ESDCFG0)
;       <i> Configures operation of the memory controller
;       <o0.21..22> tXP: LPDDR Exit Power Down to Next Valid Command Delay
;                   <0=> 1 clock
;                   <1=> 2 clocks
;                   <2=> 3 clocks
;                   <3=> 4 clocks
;       <o0.20> tWTR: LPDDR Write to Read Command Delay
;                   <0=> 1 clock
;                   <1=> 2 clocks
;       <o0.18..19> tRP: SDRAM Row Precharge Delay
;                   <0=> 1 clock
;                   <1=> 2 clocks
;                   <2=> 3 clocks
;                   <3=> 4 clocks
;       <o0.16..17> tMRD: SDRAM Load Mode Register to Active Command
;                   <0=> 1 clock
;                   <1=> 2 clocks
;                   <2=> 3 clocks
;                   <3=> 4 clocks
;       <o0.15> tWR: SDRAM Write to Precharge Command
;                   <0=> 1 clock (for SDRAM) | 2 clocks (for LPDDR)
;                   <1=> 2 clocks (for SDRAM) | 3 clocks (for LPDDR)
;       <o0.12..14> tRAS: SDRAM Active to Precharge Command
;                   <0=> 1 clock
;                   <1=> 2 clocks
;                   <2=> 3 clocks
;                   <3=> 4 clocks
;                   <4=> 5 clocks
;                   <5=> 6 clocks
;                   <6=> 7 clocks
;                   <7=> 8 clocks
;       <o0.10..11> tRRD: Active Bank A to Active Bank B Command
;                   <0=> 1 clock
;                   <1=> 2 clocks
;                   <2=> 3 clocks
;                   <3=> 4 clocks
;       <o0.8..9> tCAS: SDRAM CAS Latency
;                   <0=> 3 clocks only for LPDDR SDRAM CAS latency
;                   <1=> Reserved
;                   <2=> 3 clocks SDR and LPDDR SDRAM CAS latency
;                   <3=> 3 clocks SDR and LPDDR SDRAM CAS latency
;       <o0.4..6> tRCD: SDRAM Row to Column Delay
;                   <0=> 1 clock
;                   <1=> 2 clocks
;                   <2=> 3 clocks
;                   <3=> 4 clocks
;                   <4=> 5 clocks
;                   <5=> 6 clocks
;                   <6=> 7 clocks
;                   <7=> 8 clocks
;       <o0.0..3> tRC: SDRAM Row Cycle Delay
;                   <0=> 20 clocks
;                   <1=> 2 clocks
;                   <2=> 3 clocks
;                   <3=> 4 clocks
;                   <4=> 5 clocks
;                   <5=> 6 clocks
;                   <6=> 7 clocks
;                   <7=> 8 clocks
;                   <8=> 9 clocks
;                   <9=> 10 clocks
;                   <10=> 11 clocks
;                   <11=> 12 clocks
;                   <12=> 13 clocks
;                   <13=> 14 clocks
;                   <14=> 14 clocks
;                   <15=> 16 clocks
;     </h>
ESDCFG0_Val     EQU     0x006AC73A

;   </e>

;   <e> Enhanced SDRAM Controller Setup for CSD1
ESDRAMC_CSD1_SETUP  EQU 0

;     <h> Enhanced SDRAM Control Register 1 (ESDCTL1)
;       <i> Configures operation of the memory controller
;       <o0.31> SDE: Enhanced SDRAM Controller Enable
;       <o0.27> SP: Supervisor Protect Enable
;       <o0.24..26> ROW: Row Address Width <11-15><#-11>
;       <o0.20..21> COL: Column Address Width <8-10><#-8>
;       <o0.16..17> DSIZ: SDRAM Memory Data Width
;                   <0=> 16-bit memory width aligned to D[31:16]
;                   <1=> 16-bit memory width aligned to D[15:0]
;                   <2=> 32-bit memory width
;                   <3=> Reserved
;       <o0.13..15> SREFR: SDRAM Refresh Rate
;                   <0=> Disabled
;                   <1=> 31.25 us
;                   <2=> 15.62 us
;                   <3=>  7.81 us
;                   <4=>  3.91 us
;                   <5=>  1.95 us
;                   <6=> Reserved
;                   <7=> Reserved
;       <o0.10..11> PWDT: Power Down Timer
;                   <0=> Disabled
;                   <1=> Any time
;                   <2=>  64 clocks (HCLK) after last access
;                   <3=> 128 clocks (HCLK) after last access
;       <o0.8> FP: Full Page
;                   <0=> Burst Length is not set to Full Page
;                   <1=> Burst Length is set to Full Page
;       <o0.7> BL: Burst Length
;                   <0=> 4
;                   <1=> 8
;       <o0.0..5> PRCT: Precharge Timer <0-126:2>
;         <i> Value 0 means that Precharge Timer is Disabled
;     </h>
ESDCTL1_Val     EQU     0x00000000

;     <h> Enhanced SDRAM Configuration Register 1 (ESDCFG1)
;       <i> Configures operation of the memory controller
;       <o0.21..22> tXP: LPDDR Exit Power Down to Next Valid Command Delay
;                   <0=> 1 clock
;                   <1=> 2 clocks
;                   <2=> 3 clocks
;                   <3=> 4 clocks
;       <o0.20> tWTR: LPDDR Write to Read Command Delay
;                   <0=> 1 clock
;                   <1=> 2 clocks
;       <o0.18..19> tRP: SDRAM Row Precharge Delay
;                   <0=> 1 clock
;                   <1=> 2 clocks
;                   <2=> 3 clocks
;                   <3=> 4 clocks
;       <o0.16..17> tMRD: SDRAM Load Mode Register to Active Command
;                   <0=> 1 clock
;                   <1=> 2 clocks
;                   <2=> 3 clocks
;                   <3=> 4 clocks
;       <o0.15> tWR: SDRAM Write to Precharge Command
;                   <0=> 1 clock (for SDRAM) | 2 clocks (for LPDDR)
;                   <1=> 2 clocks (for SDRAM) | 3 clocks (for LPDDR)
;       <o0.12..14> tRAS: SDRAM Active to Precharge Command
;                   <0=> 1 clock
;                   <1=> 2 clocks
;                   <2=> 3 clocks
;                   <3=> 4 clocks
;                   <4=> 5 clocks
;                   <5=> 6 clocks
;                   <6=> 7 clocks
;                   <7=> 8 clocks
;       <o0.10..11> tRRD: Active Bank A to Active Bank B Command
;                   <0=> 1 clock
;                   <1=> 2 clocks
;                   <2=> 3 clocks
;                   <3=> 4 clocks
;       <o0.8..9> tCAS: SDRAM CAS Latency
;                   <0=> 3 clocks only for LPDDR SDRAM CAS latency
;                   <1=> Reserved
;                   <2=> 3 clocks SDR and LPDDR SDRAM CAS latency
;                   <3=> 3 clocks SDR and LPDDR SDRAM CAS latency
;       <o0.4..6> tRCD: SDRAM Row to Column Delay
;                   <0=> 1 clock
;                   <1=> 2 clocks
;                   <2=> 3 clocks
;                   <3=> 4 clocks
;                   <4=> 5 clocks
;                   <5=> 6 clocks
;                   <6=> 7 clocks
;                   <7=> 8 clocks
;       <o0.0..3> tRC: SDRAM Row Cycle Delay
;                   <0=> 20 clocks
;                   <1=> 2 clocks
;                   <2=> 3 clocks
;                   <3=> 4 clocks
;                   <4=> 5 clocks
;                   <5=> 6 clocks
;                   <6=> 7 clocks
;                   <7=> 8 clocks
;                   <8=> 9 clocks
;                   <9=> 10 clocks
;                   <10=> 11 clocks
;                   <11=> 12 clocks
;                   <12=> 13 clocks
;                   <13=> 14 clocks
;                   <14=> 14 clocks
;                   <15=> 16 clocks
;     </h>
ESDCFG1_Val     EQU     0x00000000
;   </e>

;   <h> Enhanced SDRAM Miscellaneous Register (ESDMISC)
;     <o0.6> MA10_SHARE: MA10 Share Enable
;     <o0.5> LHD: Latency Hiding Disable
;     <o0.4> MDDR_MDIS: LPDDR Delay Line Measure Disable
;     <o0.2> MDDREN: Mobile / Low Power DDR SDRAM Enable
;   </h>
ESDMISC_Val     EQU     0x00000004

;   <h> MDDR Delay Line 1 Configuration Debug Register (ESDCDLY1)
;     <o0.31> SEL_DLY_REG_1: Select Delay Used by Delay Line 1
;                   <0=> DLY_CORR_1
;                   <1=> DLY_REG_1
;     <o0.16..26> DLY_CORR_1: Delay Line 1 Correction Factor (in number of inverter units)
;                   <0-2047>
;     <o0.0..10> DLY_REG_1: Delay Used by Line 1 (in number of inverter units)
;                   <0-2047>
;   </h>
;   <h> MDDR Delay Line 2 Configuration Debug Register (ESDCDLY2)
;     <o1.31> SEL_DLY_REG_2: Select Delay Used by Delay Line 2
;                   <0=> DLY_CORR_2
;                   <1=> DLY_REG_2
;     <o1.16..26> DLY_CORR_2: Delay Line 2 Correction Factor (in number of inverter units)
;                   <0-2047>
;     <o1.0..10> DLY_REG_2: Delay Used by Line 2 (in number of inverter units)
;                   <0-2047>
;   </h>
;   <h> MDDR Delay Line 3 Configuration Debug Register (ESDCDLY3)
;     <o2.31> SEL_DLY_REG_3: Select Delay Used by Delay Line 3
;                   <0=> DLY_CORR_3
;                   <1=> DLY_REG_3
;     <o2.16..26> DLY_CORR_3: Delay Line 3 Correction Factor (in number of inverter units)
;                   <0-2047>
;     <o2.0..10> DLY_REG_3: Delay Used by Line 3 (in number of inverter units)
;                   <0-2047>
;   </h>
;   <h> MDDR Delay Line 4 Configuration Debug Register (ESDCDLY4)
;     <o3.31> SEL_DLY_REG_4: Select Delay Used by Delay Line 4
;                   <0=> DLY_CORR_4
;                   <1=> DLY_REG_4
;     <o3.16..26> DLY_CORR_4: Delay Line 4 Correction Factor (in number of inverter units)
;                   <0-2047>
;     <o3.0..10> DLY_REG_4: Delay Used by Line 4 (in number of inverter units)
;                   <0-2047>
;   </h>
;   <h> MDDR Delay Line 5 Configuration Debug Register (ESDCDLY5)
;     <o4.31> SEL_DLY_REG_5: Select Delay Used by Delay Line 5
;                   <0=> DLY_CORR_5
;                   <1=> DLY_REG_5
;     <o4.16..26> DLY_CORR_5: Delay Line 5 Correction Factor (in number of inverter units)
;                   <0-2047>
;     <o4.0..10> DLY_REG_5: Delay Used by Line 5 (in number of inverter units)
;                   <0-2047>
;   </h>
ESDCDLY1_Val    EQU     0x00000000
ESDCDLY2_Val    EQU     0x00000000
ESDCDLY3_Val    EQU     0x00000000
ESDCDLY4_Val    EQU     0x00000000
ESDCDLY5_Val    EQU     0x00000000

; </e>


;----------------------- Wireless External Interface Module Definitions --------

; Wireless External Interface Module (WEIM) User Interface
WEIM_BASE       EQU     0xD8002000      ; WEIM                          Base Adr
CSCR0U_OFS      EQU     0x00            ; CS0 Upper Control Register     Adr Ofs
CSCR0L_OFS      EQU     0x04            ; CS0 Lower Control Register     Adr Ofs
CSCR0A_OFS      EQU     0x08            ; CS0 Additional Control Reg     Adr Ofs
CSCR1U_OFS      EQU     0x10            ; CS1 Upper Control Register     Adr Ofs
CSCR1L_OFS      EQU     0x14            ; CS1 Lower Control Register     Adr Ofs
CSCR1A_OFS      EQU     0x18            ; CS1 Additional Control Reg     Adr Ofs
CSCR2U_OFS      EQU     0x20            ; CS2 Upper Control Register     Adr Ofs
CSCR2L_OFS      EQU     0x24            ; CS2 Lower Control Register     Adr Ofs
CSCR2A_OFS      EQU     0x28            ; CS2 Additional Control Reg     Adr Ofs
CSCR3U_OFS      EQU     0x30            ; CS3 Upper Control Register     Adr Ofs
CSCR3L_OFS      EQU     0x34            ; CS3 Lower Control Register     Adr Ofs
CSCR3A_OFS      EQU     0x38            ; CS3 Additional Control Reg     Adr Ofs
CSCR4U_OFS      EQU     0x40            ; CS4 Upper Control Register     Adr Ofs
CSCR4L_OFS      EQU     0x44            ; CS4 Lower Control Register     Adr Ofs
CSCR4A_OFS      EQU     0x48            ; CS4 Additional Control Reg     Adr Ofs
CSCR5U_OFS      EQU     0x50            ; CS5 Upper Control Register     Adr Ofs
CSCR5L_OFS      EQU     0x54            ; CS5 Lower Control Register     Adr Ofs
CSCR5A_OFS      EQU     0x58            ; CS5 Additional Control Reg     Adr Ofs
WCR_OFS         EQU     0x60            ; WEIM Configuration Register    Adr Ofs

; <e> Wireless External Interface Module Setup (WEIM)
WEIM_SETUP      EQU     0

;   <e0> Setup for CS0
;     <h> Chip Select 0 Upper Control Register (CSCR0U)
;       <i> Configures operation of the WEIM for CS0
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o1.31> SP: Supervisory Protect Enable
;         <i> If enabled, user mode accesses are not allowed.
;       <o1.30> WP: Write Protect Enable
;       <o1.28..29> BCD: Burst Clock Divisor
;                   <0=> AHB clock / 1
;                   <1=> AHB clock / 2
;                   <2=> AHB clock / 3
;                   <3=> AHB clock / 4
;       <o1.24..27> BCS: Burst Clock Start (in half AHB cycles) <1-16>
;       <o1.22..23> PSZ: Page Size
;                   <0=> 4 words
;                   <1=> 8 words
;                   <2=> 16 words
;                   <3=> continuous if PME = 0 | 32 words if PME = 1
;       <o1.21> PME: Page Mode Emulation Enable
;       <o1.20> SYNC: Synchronous Burst Mode Enable
;       <o1.16..19> DOL: Data Output Length (in AHB clock cycles) <1-16><#-1>
;       <o1.14..15> CNC: Chip Select Negation Clock Cycles (in AHB clock cycles) <0-3>
;       <o1.8..13> WSC: Wait State Control <0-63>
;       <o1.7> EW: !ECB / WAIT
;       <o1.4..6> WWS: Write Wait State <0-7>
;       <o1.0..3> EDC: Extra Dead Cycles (in AHB clock cycles) <0-15>
;     </h>
;     <h> Chip Select 0 Lower Control Register (CSCR0L)
;       <i> Configures operation of the WEIM for CS0
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o2.28..31> OEA: !OE Assert (in half AHB cycles) <0-15>
;       <o2.24..27> OEN: !OE Negate (in half AHB cycles) <0-15>
;       <o2.20..23> EBWA: !EB Write Assert (in half AHB cycles) <0-15>
;       <o2.16..19> EBWN: !EB Write Negate (in half AHB cycles) <0-15>
;       <o2.12..15> CSA: !CS Assert (in half AHB cycles) <0-15>
;       <o2.11> EBC: Enable Byte Control
;                   <0=> Read and write accesses assert !EB[3:0]
;                   <1=> Only write accesses assert !EB[3:0]
;       <o2.8..10> DSZ: Data Port Size <0-7>
;       <o2.4..7> CSN: !CS Negate (in half AHB cycles) <0-15>
;       <o2.3> PSR: Pseudo SRAM Enable
;       <o2.2> CRE: Control Register Enable
;       <o2.1> WRAP: Wrap Memory Mode Enable
;       <o2.0> CSEN: !CS Enable
;     </h>
;     <h> Chip Select 0 Additional Control Register (CSCR0A)
;       <i> Configures operation of the WEIM for CS0
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o3.28..31> EBRA: !EB Read Assert (in half AHB cycles) <0-15>
;       <o3.24..27> EBRN: !EB Read Negate (in half AHB cycles) <0-15>
;       <o3.20..23> RWA: !RW Assertion (in half AHB cycles) <0-15>
;       <o3.16..19> RWN: !RW Negation (in half AHB cycles) <0-15>
;       <o3.15> MUM: Multiplexed Mode Enable
;       <o3.13..14> LAH: !LBA to Address Hold (in half AHB cycles) <0-3>
;       <o3.10..12> LBN: !LBA Negation <0-7>
;       <o3.8..9> LBA: !LBA Assertion (in half AHB cycles) <0-3>
;       <o3.6..7> DWW: Decrease Write Wait State <0-3>
;       <o3.4..5> DCT: !DTACK Check Time (in AHB clock cycles)
;                   <0=> 2   <1=> 6  <2=> 8  <3=> 12
;       <o3.3> WWU: Write Wrap Unmask Enable
;       <o3.2> AGE: Acknowledge Glue Enable
;       <o3.1> CNC2: Chip Select Negation Clock Cycles Enable
;       <o3.0> FCE: Feedback Clock Enable
;     </h>
;   </e>
WEIM_CS0_SETUP  EQU     1
CSCR0U_Val      EQU     0x0000CC03
CSCR0L_Val      EQU     0xA0330D01
CSCR0A_Val      EQU     0x00220800

;   <e0> Setup for CS1
;     <h> Chip Select 1 Upper Control Register (CSCR1U)
;       <i> Configures operation of the WEIM for CS1
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o1.31> SP: Supervisory Protect Enable
;         <i> If enabled, user mode accesses are not allowed.
;       <o1.30> WP: Write Protect Enable
;       <o1.28..29> BCD: Burst Clock Divisor
;                   <0=> AHB clock / 1
;                   <1=> AHB clock / 2
;                   <2=> AHB clock / 3
;                   <3=> AHB clock / 4
;       <o1.24..27> BCS: Burst Clock Start (in half AHB cycles) <1-16>
;       <o1.22..23> PSZ: Page Size
;                   <0=> 4 words
;                   <1=> 8 words
;                   <2=> 16 words
;                   <3=> continuous if PME = 0 | 32 words if PME = 1
;       <o1.21> PME: Page Mode Emulation Enable
;       <o1.20> SYNC: Synchronous Burst Mode Enable
;       <o1.16..19> DOL: Data Output Length (in AHB clock cycles) <1-16><#-1>
;       <o1.14..15> CNC: Chip Select Negation Clock Cycles (in AHB clock cycles) <0-3>
;       <o1.8..13> WSC: Wait State Control <0-63>
;       <o1.7> EW: !ECB / WAIT
;       <o1.4..6> WWS: Write Wait State <0-7>
;       <o1.0..3> EDC: Extra Dead Cycles (in AHB clock cycles) <0-15>
;     </h>
;     <h> Chip Select 1 Lower Control Register (CSCR1L)
;       <i> Configures operation of the WEIM for CS1
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o2.28..31> OEA: !OE Assert (in half AHB cycles) <0-15>
;       <o2.24..27> OEN: !OE Negate (in half AHB cycles) <0-15>
;       <o2.20..23> EBWA: !EB Write Assert (in half AHB cycles) <0-15>
;       <o2.16..19> EBWN: !EB Write Negate (in half AHB cycles) <0-15>
;       <o2.12..15> CSA: !CS Assert (in half AHB cycles) <0-15>
;       <o2.11> EBC: Enable Byte Control
;                   <0=> Read and write accesses assert !EB[3:0]
;                   <1=> Only write accesses assert !EB[3:0]
;       <o2.8..10> DSZ: Data Port Size <0-7>
;       <o2.4..7> CSN: !CS Negate (in half AHB cycles) <0-15>
;       <o2.3> PSR: Pseudo SRAM Enable
;       <o2.2> CRE: Control Register Enable
;       <o2.1> WRAP: Wrap Memory Mode Enable
;       <o2.0> CSEN: !CS Enable
;     </h>
;     <h> Chip Select 1 Additional Control Register (CSCR1A)
;       <i> Configures operation of the WEIM for CS1
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o3.28..31> EBRA: !EB Read Assert (in half AHB cycles) <0-15>
;       <o3.24..27> EBRN: !EB Read Negate (in half AHB cycles) <0-15>
;       <o3.20..23> RWA: !RW Assertion (in half AHB cycles) <0-15>
;       <o3.16..19> RWN: !RW Negation (in half AHB cycles) <0-15>
;       <o3.15> MUM: Multiplexed Mode Enable
;       <o3.13..14> LAH: !LBA to Address Hold (in half AHB cycles) <0-3>
;       <o3.10..12> LBN: !LBA Negation <0-7>
;       <o3.8..9> LBA: !LBA Assertion (in half AHB cycles) <0-3>
;       <o3.6..7> DWW: Decrease Write Wait State <0-3>
;       <o3.4..5> DCT: !DTACK Check Time (in AHB clock cycles)
;                   <0=> 2   <1=> 6  <2=> 8  <3=> 12
;       <o3.3> WWU: Write Wrap Unmask Enable
;       <o3.2> AGE: Acknowledge Glue Enable
;       <o3.1> CNC2: Chip Select Negation Clock Cycles Enable
;       <o3.0> FCE: Feedback Clock Enable
;     </h>
;   </e>
WEIM_CS1_SETUP  EQU     0
CSCR1U_Val      EQU     0x00000000
CSCR1L_Val      EQU     0x00000000
CSCR1A_Val      EQU     0x00000000

;   <e0> Setup for CS2
;     <h> Chip Select 2 Upper Control Register (CSCR2U)
;       <i> Configures operation of the WEIM for CS2
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o1.31> SP: Supervisory Protect Enable
;         <i> If enabled, user mode accesses are not allowed.
;       <o1.30> WP: Write Protect Enable
;       <o1.28..29> BCD: Burst Clock Divisor
;                   <0=> AHB clock / 1
;                   <1=> AHB clock / 2
;                   <2=> AHB clock / 3
;                   <3=> AHB clock / 4
;       <o1.24..27> BCS: Burst Clock Start (in half AHB cycles) <1-16>
;       <o1.22..23> PSZ: Page Size
;                   <0=> 4 words
;                   <1=> 8 words
;                   <2=> 16 words
;                   <3=> continuous if PME = 0 | 32 words if PME = 1
;       <o1.21> PME: Page Mode Emulation Enable
;       <o1.20> SYNC: Synchronous Burst Mode Enable
;       <o1.16..19> DOL: Data Output Length (in AHB clock cycles) <1-16><#-1>
;       <o1.14..15> CNC: Chip Select Negation Clock Cycles (in AHB clock cycles) <0-3>
;       <o1.8..13> WSC: Wait State Control <0-63>
;       <o1.7> EW: !ECB / WAIT
;       <o1.4..6> WWS: Write Wait State <0-7>
;       <o1.0..3> EDC: Extra Dead Cycles (in AHB clock cycles) <0-15>
;     </h>
;     <h> Chip Select 2 Lower Control Register (CSCR2L)
;       <i> Configures operation of the WEIM for CS2
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o2.28..31> OEA: !OE Assert (in half AHB cycles) <0-15>
;       <o2.24..27> OEN: !OE Negate (in half AHB cycles) <0-15>
;       <o2.20..23> EBWA: !EB Write Assert (in half AHB cycles) <0-15>
;       <o2.16..19> EBWN: !EB Write Negate (in half AHB cycles) <0-15>
;       <o2.12..15> CSA: !CS Assert (in half AHB cycles) <0-15>
;       <o2.11> EBC: Enable Byte Control
;                   <0=> Read and write accesses assert !EB[3:0]
;                   <1=> Only write accesses assert !EB[3:0]
;       <o2.8..10> DSZ: Data Port Size <0-7>
;       <o2.4..7> CSN: !CS Negate (in half AHB cycles) <0-15>
;       <o2.3> PSR: Pseudo SRAM Enable
;       <o2.2> CRE: Control Register Enable
;       <o2.1> WRAP: Wrap Memory Mode Enable
;       <o2.0> CSEN: !CS Enable
;     </h>
;     <h> Chip Select 2 Additional Control Register (CSCR2A)
;       <i> Configures operation of the WEIM for CS2
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o3.28..31> EBRA: !EB Read Assert (in half AHB cycles) <0-15>
;       <o3.24..27> EBRN: !EB Read Negate (in half AHB cycles) <0-15>
;       <o3.20..23> RWA: !RW Assertion (in half AHB cycles) <0-15>
;       <o3.16..19> RWN: !RW Negation (in half AHB cycles) <0-15>
;       <o3.15> MUM: Multiplexed Mode Enable
;       <o3.13..14> LAH: !LBA to Address Hold (in half AHB cycles) <0-3>
;       <o3.10..12> LBN: !LBA Negation <0-7>
;       <o3.8..9> LBA: !LBA Assertion (in half AHB cycles) <0-3>
;       <o3.6..7> DWW: Decrease Write Wait State <0-3>
;       <o3.4..5> DCT: !DTACK Check Time (in AHB clock cycles)
;                   <0=> 2   <1=> 6  <2=> 8  <3=> 12
;       <o3.3> WWU: Write Wrap Unmask Enable
;       <o3.2> AGE: Acknowledge Glue Enable
;       <o3.1> CNC2: Chip Select Negation Clock Cycles Enable
;       <o3.0> FCE: Feedback Clock Enable
;     </h>
;   </e>
WEIM_CS2_SETUP  EQU     0
CSCR2U_Val      EQU     0x00000000
CSCR2L_Val      EQU     0x00000000
CSCR2A_Val      EQU     0x00000000

;   <e0> Setup for CS3
;     <h> Chip Select 3 Upper Control Register (CSCR3U)
;       <i> Configures operation of the WEIM for CS3
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o1.31> SP: Supervisory Protect Enable
;         <i> If enabled, user mode accesses are not allowed.
;       <o1.30> WP: Write Protect Enable
;       <o1.28..29> BCD: Burst Clock Divisor
;                   <0=> AHB clock / 1
;                   <1=> AHB clock / 2
;                   <2=> AHB clock / 3
;                   <3=> AHB clock / 4
;       <o1.24..27> BCS: Burst Clock Start (in half AHB cycles) <1-16>
;       <o1.22..23> PSZ: Page Size
;                   <0=> 4 words
;                   <1=> 8 words
;                   <2=> 16 words
;                   <3=> continuous if PME = 0 | 32 words if PME = 1
;       <o1.21> PME: Page Mode Emulation Enable
;       <o1.20> SYNC: Synchronous Burst Mode Enable
;       <o1.16..19> DOL: Data Output Length (in AHB clock cycles) <1-16><#-1>
;       <o1.14..15> CNC: Chip Select Negation Clock Cycles (in AHB clock cycles) <0-3>
;       <o1.8..13> WSC: Wait State Control <0-63>
;       <o1.7> EW: !ECB / WAIT
;       <o1.4..6> WWS: Write Wait State <0-7>
;       <o1.0..3> EDC: Extra Dead Cycles (in AHB clock cycles) <0-15>
;     </h>
;     <h> Chip Select 3 Lower Control Register (CSCR3L)
;       <i> Configures operation of the WEIM for CS3
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o2.28..31> OEA: !OE Assert (in half AHB cycles) <0-15>
;       <o2.24..27> OEN: !OE Negate (in half AHB cycles) <0-15>
;       <o2.20..23> EBWA: !EB Write Assert (in half AHB cycles) <0-15>
;       <o2.16..19> EBWN: !EB Write Negate (in half AHB cycles) <0-15>
;       <o2.12..15> CSA: !CS Assert (in half AHB cycles) <0-15>
;       <o2.11> EBC: Enable Byte Control
;                   <0=> Read and write accesses assert !EB[3:0]
;                   <1=> Only write accesses assert !EB[3:0]
;       <o2.8..10> DSZ: Data Port Size <0-7>
;       <o2.4..7> CSN: !CS Negate (in half AHB cycles) <0-15>
;       <o2.3> PSR: Pseudo SRAM Enable
;       <o2.2> CRE: Control Register Enable
;       <o2.1> WRAP: Wrap Memory Mode Enable
;       <o2.0> CSEN: !CS Enable
;     </h>
;     <h> Chip Select 3 Additional Control Register (CSCR3A)
;       <i> Configures operation of the WEIM for CS3
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o3.28..31> EBRA: !EB Read Assert (in half AHB cycles) <0-15>
;       <o3.24..27> EBRN: !EB Read Negate (in half AHB cycles) <0-15>
;       <o3.20..23> RWA: !RW Assertion (in half AHB cycles) <0-15>
;       <o3.16..19> RWN: !RW Negation (in half AHB cycles) <0-15>
;       <o3.15> MUM: Multiplexed Mode Enable
;       <o3.13..14> LAH: !LBA to Address Hold (in half AHB cycles) <0-3>
;       <o3.10..12> LBN: !LBA Negation <0-7>
;       <o3.8..9> LBA: !LBA Assertion (in half AHB cycles) <0-3>
;       <o3.6..7> DWW: Decrease Write Wait State <0-3>
;       <o3.4..5> DCT: !DTACK Check Time (in AHB clock cycles)
;                   <0=> 2   <1=> 6  <2=> 8  <3=> 12
;       <o3.3> WWU: Write Wrap Unmask Enable
;       <o3.2> AGE: Acknowledge Glue Enable
;       <o3.1> CNC2: Chip Select Negation Clock Cycles Enable
;       <o3.0> FCE: Feedback Clock Enable
;     </h>
;   </e>
WEIM_CS3_SETUP  EQU     0
CSCR3U_Val      EQU     0x00000000
CSCR3L_Val      EQU     0x00000000
CSCR3A_Val      EQU     0x00000000

;   <e0> Setup for CS4
;     <h> Chip Select 4 Upper Control Register (CSCR4U)
;       <i> Configures operation of the WEIM for CS4
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o1.31> SP: Supervisory Protect Enable
;         <i> If enabled, user mode accesses are not allowed.
;       <o1.30> WP: Write Protect Enable
;       <o1.28..29> BCD: Burst Clock Divisor
;                   <0=> AHB clock / 1
;                   <1=> AHB clock / 2
;                   <2=> AHB clock / 3
;                   <3=> AHB clock / 4
;       <o1.24..27> BCS: Burst Clock Start (in half AHB cycles) <1-16>
;       <o1.22..23> PSZ: Page Size
;                   <0=> 4 words
;                   <1=> 8 words
;                   <2=> 16 words
;                   <3=> continuous if PME = 0 | 32 words if PME = 1
;       <o1.21> PME: Page Mode Emulation Enable
;       <o1.20> SYNC: Synchronous Burst Mode Enable
;       <o1.16..19> DOL: Data Output Length (in AHB clock cycles) <1-16><#-1>
;       <o1.14..15> CNC: Chip Select Negation Clock Cycles (in AHB clock cycles) <0-3>
;       <o1.8..13> WSC: Wait State Control <0-63>
;       <o1.7> EW: !ECB / WAIT
;       <o1.4..6> WWS: Write Wait State <0-7>
;       <o1.0..3> EDC: Extra Dead Cycles (in AHB clock cycles) <0-15>
;     </h>
;     <h> Chip Select 4 Lower Control Register (CSCR4L)
;       <i> Configures operation of the WEIM for CS4
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o2.28..31> OEA: !OE Assert (in half AHB cycles) <0-15>
;       <o2.24..27> OEN: !OE Negate (in half AHB cycles) <0-15>
;       <o2.20..23> EBWA: !EB Write Assert (in half AHB cycles) <0-15>
;       <o2.16..19> EBWN: !EB Write Negate (in half AHB cycles) <0-15>
;       <o2.12..15> CSA: !CS Assert (in half AHB cycles) <0-15>
;       <o2.11> EBC: Enable Byte Control
;                   <0=> Read and write accesses assert !EB[3:0]
;                   <1=> Only write accesses assert !EB[3:0]
;       <o2.8..10> DSZ: Data Port Size <0-7>
;       <o2.4..7> CSN: !CS Negate (in half AHB cycles) <0-15>
;       <o2.3> PSR: Pseudo SRAM Enable
;       <o2.2> CRE: Control Register Enable
;       <o2.1> WRAP: Wrap Memory Mode Enable
;       <o2.0> CSEN: !CS Enable
;     </h>
;     <h> Chip Select 4 Additional Control Register (CSCR4A)
;       <i> Configures operation of the WEIM for CS4
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o3.28..31> EBRA: !EB Read Assert (in half AHB cycles) <0-15>
;       <o3.24..27> EBRN: !EB Read Negate (in half AHB cycles) <0-15>
;       <o3.20..23> RWA: !RW Assertion (in half AHB cycles) <0-15>
;       <o3.16..19> RWN: !RW Negation (in half AHB cycles) <0-15>
;       <o3.15> MUM: Multiplexed Mode Enable
;       <o3.13..14> LAH: !LBA to Address Hold (in half AHB cycles) <0-3>
;       <o3.10..12> LBN: !LBA Negation <0-7>
;       <o3.8..9> LBA: !LBA Assertion (in half AHB cycles) <0-3>
;       <o3.6..7> DWW: Decrease Write Wait State <0-3>
;       <o3.4..5> DCT: !DTACK Check Time (in AHB clock cycles)
;                   <0=> 2   <1=> 6  <2=> 8  <3=> 12
;       <o3.3> WWU: Write Wrap Unmask Enable
;       <o3.2> AGE: Acknowledge Glue Enable
;       <o3.1> CNC2: Chip Select Negation Clock Cycles Enable
;       <o3.0> FCE: Feedback Clock Enable
;     </h>
;   </e>
WEIM_CS4_SETUP  EQU     0
CSCR4U_Val      EQU     0x00000000
CSCR4L_Val      EQU     0x00000000
CSCR4A_Val      EQU     0x00000000

;   <e0> Setup for CS5
;     <h> Chip Select 5 Upper Control Register (CSCR5U)
;       <i> Configures operation of the WEIM for CS5
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o1.31> SP: Supervisory Protect Enable
;         <i> If enabled, user mode accesses are not allowed.
;       <o1.30> WP: Write Protect Enable
;       <o1.28..29> BCD: Burst Clock Divisor
;                   <0=> AHB clock / 1
;                   <1=> AHB clock / 2
;                   <2=> AHB clock / 3
;                   <3=> AHB clock / 4
;       <o1.24..27> BCS: Burst Clock Start (in half AHB cycles) <1-16>
;       <o1.22..23> PSZ: Page Size
;                   <0=> 4 words
;                   <1=> 8 words
;                   <2=> 16 words
;                   <3=> continuous if PME = 0 | 32 words if PME = 1
;       <o1.21> PME: Page Mode Emulation Enable
;       <o1.20> SYNC: Synchronous Burst Mode Enable
;       <o1.16..19> DOL: Data Output Length (in AHB clock cycles) <1-16><#-1>
;       <o1.14..15> CNC: Chip Select Negation Clock Cycles (in AHB clock cycles) <0-3>
;       <o1.8..13> WSC: Wait State Control <0-63>
;       <o1.7> EW: !ECB / WAIT
;       <o1.4..6> WWS: Write Wait State <0-7>
;       <o1.0..3> EDC: Extra Dead Cycles (in AHB clock cycles) <0-15>
;     </h>
;     <h> Chip Select 5 Lower Control Register (CSCR5L)
;       <i> Configures operation of the WEIM for CS5
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o2.28..31> OEA: !OE Assert (in half AHB cycles) <0-15>
;       <o2.24..27> OEN: !OE Negate (in half AHB cycles) <0-15>
;       <o2.20..23> EBWA: !EB Write Assert (in half AHB cycles) <0-15>
;       <o2.16..19> EBWN: !EB Write Negate (in half AHB cycles) <0-15>
;       <o2.12..15> CSA: !CS Assert (in half AHB cycles) <0-15>
;       <o2.11> EBC: Enable Byte Control
;                   <0=> Read and write accesses assert !EB[3:0]
;                   <1=> Only write accesses assert !EB[3:0]
;       <o2.8..10> DSZ: Data Port Size <0-7>
;       <o2.4..7> CSN: !CS Negate (in half AHB cycles) <0-15>
;       <o2.3> PSR: Pseudo SRAM Enable
;       <o2.2> CRE: Control Register Enable
;       <o2.1> WRAP: Wrap Memory Mode Enable
;       <o2.0> CSEN: !CS Enable
;     </h>
;     <h> Chip Select 5 Additional Control Register (CSCR5A)
;       <i> Configures operation of the WEIM for CS5
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o3.28..31> EBRA: !EB Read Assert (in half AHB cycles) <0-15>
;       <o3.24..27> EBRN: !EB Read Negate (in half AHB cycles) <0-15>
;       <o3.20..23> RWA: !RW Assertion (in half AHB cycles) <0-15>
;       <o3.16..19> RWN: !RW Negation (in half AHB cycles) <0-15>
;       <o3.15> MUM: Multiplexed Mode Enable
;       <o3.13..14> LAH: !LBA to Address Hold (in half AHB cycles) <0-3>
;       <o3.10..12> LBN: !LBA Negation <0-7>
;       <o3.8..9> LBA: !LBA Assertion (in half AHB cycles) <0-3>
;       <o3.6..7> DWW: Decrease Write Wait State <0-3>
;       <o3.4..5> DCT: !DTACK Check Time (in AHB clock cycles)
;                   <0=> 2   <1=> 6  <2=> 8  <3=> 12
;       <o3.3> WWU: Write Wrap Unmask Enable
;       <o3.2> AGE: Acknowledge Glue Enable
;       <o3.1> CNC2: Chip Select Negation Clock Cycles Enable
;       <o3.0> FCE: Feedback Clock Enable
;     </h>
;   </e>
WEIM_CS5_SETUP  EQU     0
CSCR5U_Val      EQU     0x00000000
CSCR5L_Val      EQU     0x00000000
CSCR5A_Val      EQU     0x00000000

;   <h> WEIM Configuration Register (WCR)
;     <i> Configures operation of the WEIM
;     <i> Look into Reference Manual for detailed explanation of fields!
;     <o0.19> ECP5: !ECB Capture Phase for CS5
;                 <0=> BCLK start phase is as BCS[0]
;                 <1=> BCLK start phase is the opposite of BCS[0] for write access only
;     <o0.18> ECP4: !ECB Capture Phase for CS4
;                 <0=> BCLK start phase is as BCS[0]
;                 <1=> BCLK start phase is the opposite of BCS[0] for write access only
;     <o0.17> ECP3: !ECB Capture Phase for CS3
;                 <0=> BCLK start phase is as BCS[0]
;                 <1=> BCLK start phase is the opposite of BCS[0] for write access only
;     <o0.16> ECP2: !ECB Capture Phase for CS2
;                 <0=> BCLK start phase is as BCS[0]
;                 <1=> BCLK start phase is the opposite of BCS[0] for write access only
;     <o0.15> ECP1: !ECB Capture Phase for CS1
;                 <0=> BCLK start phase is as BCS[0]
;                 <1=> BCLK start phase is the opposite of BCS[0] for write access only
;     <o0.14> ECP0: !ECB Capture Phase for CS0
;                 <0=> BCLK start phase is as BCS[0]
;                 <1=> BCLK start phase is the opposite of BCS[0] for write access only
;     <o0.13> AUS5: Address Unshifted for CS5
;                 <0=> Address shifted according to CS5 port size
;                 <1=> Address unshifted
;     <o0.12> AUS4: Address Unshifted for CS4
;                 <0=> Address shifted according to CS4 port size
;                 <1=> Address unshifted
;     <o0.11> AUS3: Address Unshifted for CS3
;                 <0=> Address shifted according to CS3 port size
;                 <1=> Address unshifted
;     <o0.10> AUS2: Address Unshifted for CS2
;                 <0=> Address shifted according to CS2 port size
;                 <1=> Address unshifted
;     <o0.9> AUS1: Address Unshifted for CS1
;                 <0=> Address shifted according to CS1 port size
;                 <1=> Address unshifted
;     <o0.8> AUS0: Address Unshifted for CS0
;                 <0=> Address shifted according to CS0 port size
;                 <1=> Address unshifted
;     <o0.2> BCM: Burst Clock Mode Enable
;     <o0.0> MAS: Merged Address Space
;                 <0=> Standard address space
;                 <1=> Merged address space
;   </h>
WCR_Val         EQU     0x00000000

; </e>


;----------------------- NAND Flash Definitions --------------------------------

; NAND Flash Controller (NFC) User Interface
NFC_BASE              EQU   0xD8000E00  ; NADN Flash Controller         Base Adr
NFC_BUFSIZ_OFS        EQU   0x00        ; NFC Buffer Size Reg            Adr Ofs
RAM_BUF_ADR_OFS       EQU   0x04        ; RAM Buffer Address Register    Adr Ofs
NAND_FLASH_ADR_OFS    EQU   0x06        ; NAND Flash Address Register    Adr Ofs
NAND_FLASH_CMD_OFS    EQU   0x08        ; NAND Flash Command Register    Adr Ofs
NFC_CONF_OFS          EQU   0x0A        ; NFC Internal Buffer Lock Ctrl  Adr Ofs
ECC_STAT_RESULT_FS    EQU   0x0C        ; Status Register                Adr Ofs
ECC_RSLT_MA_OFS       EQU   0x0E        ; ECC Error Pos in Main Area     Adr Ofs
ECC_RSLT_SA_OFS       EQU   0x10        ; ECC Error Pos in Spare Area    Adr Ofs
NF_WR_PROT_OFS        EQU   0x12        ; NAND Flash Write Protection    Adr Ofs
UNLOCK_S_BLK_ADR_OFS  EQU   0x14        ; Start Address Unlock           Adr Ofs
UNLOCK_E_BLK_ADR_OFS  EQU   0x16        ; End   Address Unlock           Adr Ofs
NAND_FL_WR_PR_ST_OFS  EQU   0x18        ; NAND Flash Wr Protect Status   Adr Ofs
NAND_FL_CONFIG1_OFS   EQU   0x1A        ; NAND Flash Operation Config 1  Adr Ofs
NAND_FL_CONFIG2_OFS   EQU   0x1C        ; NAND Flash Operation Config 2  Adr Ofs

; <e> NAND Flash Controller Configuration (NFC)
NFC_SETUP             EQU   0

;   <h> Buffer Number for Page Data Transfer (RAM_BUFFER_ADDRESS)
;     <o0.0..3> RBA: RAM Buffer Address
;                   <0=> 1st internal RAM buffer
;                   <1=> 2nd internal RAM buffer
;                   <2=> 3rd internal RAM buffer
;                   <3=> 4th internal RAM buffer
;   </h>
RAM_BUF_ADR_Val       EQU   0x0000

;   <h> NFC Internal Buffer Lock Control (NFC_CONFIGURATION)
;     <o0.0..1> BLS: Buffer Lock Set
;       <i> This field specifies the buffer lock status of first two pages 
;       <i> in the internal buffer. The other two pages are always Unlocked.
;                   <0=> Locked
;                   <1=> Locked
;                   <2=> Unlocked
;                   <3=> Locked
;   </h>
NFC_CONF_Val          EQU   0x0002

;   <h> NAND Flash Write Protection (NF_WR_PROT)
;     <o0.0..2> WPC: Write Protect Command
;       <i> This field specifies the operation that controller will perform. 
;                   <1=> Lock-tight locked blocks
;                   <2=> Lock all NAND flash blocks
;                   <4=> Unlock NAND flash blocks
;   </h>
NF_WR_PROT_Val        EQU   0x0004

;   <h> Address to Unlock in Write Protection Mode - Start (UNLOCK_START_BLK_ADD)
;     <o0> USBA: Unlock Start Block Address <0x0000-0xFFFF>
;   </h>
UNLOCK_S_BLK_ADR_Val  EQU   0x0000

;   <h> Address to Unlock in Write Protection Mode - End (UNLOCK_END_BLK_ADD)
;     <o0> UEBA: Unlock End Block Address <0x0000-0xFFFF>
;   </h>
UNLOCK_E_BLK_ADR_Val  EQU   0x0000

;   <h> NAND Flash Operation Configuration 1 (NAND_FLASH_CONFIG1)
;     <o0.7> NF_!CE: NAND Flash Force !CE
;                   <0=> !CE signal operates normally
;                   <1=> !CE signal is asserted as long as this bit is set to 1
;     <o0.6> NF_RST: NFC Reset
;     <o0.5> NF_BIG: NAND Flash Big Endian Mode Enable
;     <o0.4> INT_MSK: Mask Interrupt Bit Enable
;     <o0.3> ECC_EN: ECC Operation Enable
;     <o0.2> SP_EN: NAND Flash Spare Enable
;                   <0=> NAND flash main and spare data is enabled
;                   <1=> NAND flash spare only data is enabled
;   </h>
NAND_FL_CONFIG1_Val   EQU   0x0000

; </e> NAND Flash Controller Configuration (NFC)


;----------------------- Cache Definitions -------------------------------------

; Constants
ICACHE_EN_BIT   EQU     (1<<12)         ; Instruction Cache Enable Bit

; <e> Instruction Cache Enable
; </e>
ICACHE_SETUP    EQU     1


;----------------------- CODE --------------------------------------------------

                PRESERVE8
                

; Area Definition and Entry Point
;  Startup Code must be linked first at Address at which it expects to run.

                AREA    RESET, CODE, READONLY
                ARM

                IF      :DEF:SIZE_INFO
                IF      :LNOT::DEF:__EVAL 
                IMPORT  ||Image$$ER_ROM1$$RO$$Length||
                IMPORT  ||Image$$RW_RAM1$$RW$$Length||
                ENDIF
                ENDIF

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
                ; Reserved vector is used for image size information
                IF      :DEF:SIZE_INFO
                  IF    :DEF:__EVAL
                    DCD 0x1000
                  ELSE 
                    DCD ||Image$$ER_ROM1$$RO$$Length||+\
                        ||Image$$RW_RAM1$$RW$$Length||
                  ENDIF
                ELSE
                  NOP
                ENDIF
                LDR     PC,IRQ_Addr     
                LDR     PC,FIQ_Addr

Reset_Addr      DCD     Reset_Handler
Undef_Addr      DCD     Undef_Handler
SWI_Addr        DCD     SWI_Handler
PAbt_Addr       DCD     PAbt_Handler
DAbt_Addr       DCD     DAbt_Handler
                IF      :DEF:__RTX
IRQ_Addr        DCD     IRQ_Handler_RTX
                ELSE
IRQ_Addr        DCD     IRQ_Handler
                ENDIF
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
FIQ_Handler     B       FIQ_Handler


; Reset Handler

                EXPORT  Reset_Handler
Reset_Handler   


; AHB-Lite IP Interface (AIPI) Setup -------------------------------------------

                IF      (AIPI_SETUP != 0)
                LDR     R0, =AIPI1_BASE
                LDR     R1, =AIPI2_BASE

                LDR     R2, =AIPI1_PSR0_Val
                LDR     R3, =AIPI1_PSR1_Val
                LDR     R4, =AIPI1_PAR_Val
                STR     R2, [R0, #PSR0_OFS]
                STR     R3, [R0, #PSR1_OFS]
                STR     R4, [R0, #PAR_OFS]

                LDR     R2, =AIPI2_PSR0_Val
                LDR     R3, =AIPI2_PSR1_Val
                LDR     R4, =AIPI2_PAR_Val
                STR     R2, [R1, #PSR0_OFS]
                STR     R3, [R1, #PSR1_OFS]
                STR     R4, [R1, #PAR_OFS]
                ENDIF   ;(AIPI_SETUP != 0)


; Clock Setup ------------------------------------------------------------------

                IF      (:LNOT::DEF:CLOCK_NO_INIT):LAND:(CLOCK_SETUP != 0)
                LDR     R0, =CLOCK_BASE

                ; If external high freq clock is used
                ; Adjust the 26 MHz Oscillator Trim
                IF      ((CSCR_Val:AND:MCU_SEL_BIT) != 0):LOR:((CSCR_Val:AND:SP_SEL_BIT) != 0)
Trim            LDR     R2, [R0, #OSC26MCTL_OFS]
                MOV     R1, #OSC26M_AMP_HIGH
                TST     R2, R1
                BEQ     Operate
                ANDS    R1, R2, #AGC_FLD
                CMP     R1, #AGC_VAL_4
                BLE     Operate
                SUB     R2, R2, #AGC_VAL_1
                STR     R2, [R0, #OSC26MCTL_OFS]
                LDR     R6, =1500                 ; ~30us at 200 MHz
WaitTrim0       SUBS    R6, R6, #1
                BNE     WaitTrim0
                B       Trim
Operate         MOV     R3, R2
                SUB     R2, R2, #AGC_VAL_4
                BPL     TrimVal
                MVN     R2, #AGC_FLD
                AND     R2, R3, R2
TrimVal         STR     R2, [R0, #OSC26MCTL_OFS]
                LDR     R6, =1500                 ; ~30us at 200 MHz
WaitTrim1       SUBS    R6, R6, #1
                BNE     WaitTrim1
                ENDIF

                ; If MPLL is used
                IF      (CSCR_Val:AND:MPEN_BIT) != 0
                LDR     R1, =MPCTL0_Val
                STR     R1, [R0, #MPCTL0_OFS]
                LDR     R1, =MPCTL1_Val
                STR     R1, [R0, #MPCTL1_OFS]
                LDR     R1, [R0, #CSCR_OFS]
                MOV     R2, #MPLL_RESTART_BIT
                ORR     R1, R1, R2
                STR     R1, [R0, #CSCR_OFS]
MPLL_Loop       LDR     R1, [R0, #MPCTL1_OFS]
                TST     R1, #LF_BIT
                BEQ     MPLL_Loop
                ENDIF

                ; If SPLL is used
                IF      (CSCR_Val:AND:SPEN_BIT) != 0
                LDR     R1, =SPCTL0_Val
                STR     R1, [R0, #SPCTL0_OFS]
                LDR     R1, =SPCTL1_Val
                STR     R1, [R0, #SPCTL1_OFS]
                LDR     R1, [R0, #CSCR_OFS]
                MOV     R2, #SPLL_RESTART_BIT
                ORR     R1, R1, R2
                STR     R1, [R0, #CSCR_OFS]
SPLL_Loop       LDR     R1, [R0, #SPCTL1_OFS]
                TST     R1, #LF_BIT
                BEQ     SPLL_Loop
                ENDIF

                MOV     R6, #1000
WaitOscStabil   SUBS    R6, R6, #1
                BNE     WaitOscStabil

                MOV     R2, #UPDATE_DIS_BIT
                LDR     R1, [R0, #CSCR_OFS]
                ORR     R1, R1, R2
                STR     R1, [R0, #CSCR_OFS]
                LDR     R1, =CSCR_Val
                STR     R1, [R0, #CSCR_OFS]
                LDR     R1, =PCDR0_Val
                STR     R1, [R0, #PCDR0_OFS]
                LDR     R1, =PCDR1_Val
                STR     R1, [R0, #PCDR1_OFS]
                LDR     R1, =PCCR0_Val
                STR     R1, [R0, #PCCR0_OFS]
                LDR     R1, =PCCR1_Val
                STR     R1, [R0, #PCCR1_OFS]
                ENDIF   ;(:LNOT::DEF:CLOCK_NO_INIT):LAND:(CLOCK_SETUP != 0)


; Enhanced SDRAM Setup ---------------------------------------------------------

                IF      (:LNOT::DEF:ESDRAMC_NO_INIT):LAND:(ESDRAMC_SETUP != 0)
                LDR     R0, =SYSTEM_BASE          ; Address of System Controller
                LDR     R1, =ESDRAMC_BASE         ; Address of ESDRAM Controller
                LDR     R2, =(CSD0_BASE | 0x0F00)
                MOV     R3, #0

                IF      (ESDRAMC_CSD0_SETUP != 0)
                MOV     R4, #0x08
                STR     R4, [R1, #ESDMISC_OFS]
                LDR     R4, =0x55555555
                LDR     R5, =0x55555555
                LDR     R6, =0x55555555
                LDR     R7, =0x00005005
                LDR     R8, =0x15555555
                STR     R4, [R0, #DSCR3_OFS]
                STR     R5, [R0, #DSCR5_OFS]
                STR     R6, [R0, #DSCR6_OFS]
                STR     R7, [R0, #DSCR7_OFS]
                STR     R8, [R0, #DSCR8_OFS]
                LDR     R4, =ESDMISC_Val
                STR     R4, [R1, #ESDMISC_OFS]
                LDR     R4, =ESDCFG0_Val
                STR     R4, [R1, #ESDCFG0_OFS]
                LDR     R4, =((ESDCTL0_Val & ESDCTL_MSK) | PALL_CMD)
                STR     R4, [R1, #ESDCTL0_OFS]
                STR     R3, [R2, #0]
                LDR     R4, =((ESDCTL0_Val & ESDCTL_MSK) | AREFSH_MODE)
                STR     R4, [R1, #ESDCTL0_OFS]
                STR     R3, [R2, #0]
                STR     R3, [R2, #0]
                STR     R3, [R2, #0]
                STR     R3, [R2, #0]
                LDR     R4, =((ESDCTL0_Val & ESDCTL_MSK) | AREFSH_MODE)
                STR     R4, [R1, #ESDCTL0_OFS]
                STR     R3, [R2, #0]
                STR     R3, [R2, #0]
                STR     R3, [R2, #0]
                STR     R3, [R2, #0]
                LDR     R4, =((ESDCTL0_Val & ESDCTL_MSK) | MODE_CMD)
                STR     R4, [R1, #ESDCTL0_OFS]
                LDR     R4, =(CSD0_BASE | 0x00000033)
                MOV     R5, #0xDA
                STRB    R5, [R4, #0]
                LDR     R4, =(CSD0_BASE | 0x01000000)
                MOV     R5, #0xFF
                STRB    R5, [R4, #0]
                LDR     R4, =ESDCTL0_Val
                STR     R4, [R1, #ESDCTL0_OFS]
                ENDIF   ;(ESDRAMC_CSD0_SETUP != 0)

                IF      (ESDRAMC_CSD1_SETUP != 0)
                ; Code needs to be written to initialize used SDRAM
                ENDIF   ;(ESDRAMC_CSD1_SETUP != 0)

                LDR     R4, =ESDCDLY1_Val
                STR     R4, [R1, #ESDCDLY1_OFS]
                LDR     R4, =ESDCDLY2_Val
                STR     R4, [R1, #ESDCDLY2_OFS]
                LDR     R4, =ESDCDLY3_Val
                STR     R4, [R1, #ESDCDLY3_OFS]
                LDR     R4, =ESDCDLY4_Val
                STR     R4, [R1, #ESDCDLY4_OFS]
                LDR     R4, =ESDCDLY5_Val
                STR     R4, [R1, #ESDCDLY5_OFS]
                ENDIF   ;(:LNOT::DEF:ESDRAMC_NO_INIT):LAND:(ESDRAMC_SETUP != 0)


; NOR Flash Setup (Wireless External Interface Module (WEIM)) ------------------

                IF      (:LNOT::DEF:WEIM_NO_INIT):LAND:(WEIM_SETUP != 0)
                LDR     R0, =SYSTEM_BASE          ; Address of System Controller
                LDR     R1, =WEIM_BASE            ; Address of WEIM Controller

                LDR     R2, =0x55555555
                LDR     R3, =0x55555555
                STR     R7, [R0, #DSCR7_OFS]
                ORR     R7, R7, #0x0200
                STR     R2, [R0, #DSCR2_OFS]
                STR     R3, [R0, #DSCR3_OFS]
                STR     R7, [R0, #DSCR7_OFS]

                IF      (WEIM_CS0_SETUP != 0)
                LDR     R2, =CSCR0U_Val
                LDR     R3, =CSCR0L_Val
                LDR     R4, =CSCR0A_Val
                STR     R2, [R1, #CSCR0U_OFS]
                STR     R3, [R1, #CSCR0L_OFS]
                STR     R4, [R1, #CSCR0A_OFS]
                ENDIF   ;(WEIM_CS0_SETUP != 0)

                IF      (WEIM_CS1_SETUP != 0)
                LDR     R2, =CSCR1U_Val
                LDR     R3, =CSCR1L_Val
                LDR     R4, =CSCR1A_Val
                STR     R2, [R1, #CSCR1U_OFS]
                STR     R3, [R1, #CSCR1L_OFS]
                STR     R4, [R1, #CSCR1A_OFS]
                ENDIF   ;(WEIM_CS1_SETUP != 0)

                IF      (WEIM_CS2_SETUP != 0)
                LDR     R2, =CSCR2U_Val
                LDR     R3, =CSCR2L_Val
                LDR     R4, =CSCR2A_Val
                STR     R2, [R1, #CSCR2U_OFS]
                STR     R3, [R1, #CSCR2L_OFS]
                STR     R4, [R1, #CSCR2A_OFS]
                ENDIF   ;(WEIM_CS2_SETUP != 0)

                IF      (WEIM_CS3_SETUP != 0)
                LDR     R2, =CSCR3U_Val
                LDR     R3, =CSCR3L_Val
                LDR     R4, =CSCR3A_Val
                STR     R2, [R1, #CSCR3U_OFS]
                STR     R3, [R1, #CSCR3L_OFS]
                STR     R4, [R1, #CSCR3A_OFS]
                ENDIF   ;(WEIM_CS3_SETUP != 0)

                IF      (WEIM_CS4_SETUP != 0)
                LDR     R2, =CSCR4U_Val
                LDR     R3, =CSCR4L_Val
                LDR     R4, =CSCR4A_Val
                STR     R2, [R1, #CSCR4U_OFS]
                STR     R3, [R1, #CSCR4L_OFS]
                STR     R4, [R1, #CSCR4A_OFS]
                ENDIF   ;(WEIM_CS4_SETUP != 0)

                IF      (WEIM_CS5_SETUP != 0)
                LDR     R2, =CSCR5U_Val
                LDR     R3, =CSCR5L_Val
                LDR     R4, =CSCR5A_Val
                STR     R2, [R1, #CSCR5U_OFS]
                STR     R3, [R1, #CSCR5L_OFS]
                STR     R4, [R1, #CSCR5A_OFS]
                ENDIF   ;(WEIM_CS5_SETUP != 0)

                LDR     R2, =WCR_Val
                STR     R2, [R1, #WCR_OFS]

                ENDIF   ;(:LNOT::DEF:WEIM_NO_INIT):LAND:(WEIM_SETUP != 0)


; NAND Flash Setup -------------------------------------------------------------

                IF      (:LNOT::DEF:NFC_NO_INIT):LAND:(NFC_SETUP != 0)
                LDR     R0, =SYSTEM_BASE          ; Address of System Controller
                LDR     R1, =NFC_BASE             ; Address of NFC Controller

                LDR     R2, =0xFFFFFFFB
                STR     R2, [R0, #FMCR_OFS]
                LDR     R2, =0x00002AAA
                STR     R2, [R0, #DSCR10_OFS]

                LDR     R2, =RAM_BUF_ADR_Val
                STRH    R2, [R1, #RAM_BUF_ADR_OFS]
                LDR     R2, =NFC_CONF_Val
                STRH    R2, [R1, #NFC_CONF_OFS]
                LDR     R2, =NF_WR_PROT_Val
                STRH    R2, [R1, #NF_WR_PROT_OFS]
                LDR     R2, =UNLOCK_S_BLK_ADR_Val
                STRH    R2, [R1, #UNLOCK_S_BLK_ADR_OFS]
                LDR     R2, =UNLOCK_E_BLK_ADR_Val
                STRH    R2, [R1, #UNLOCK_E_BLK_ADR_OFS]
                LDR     R2, =NAND_FL_CONFIG1_Val
                STRH    R2, [R1, #NAND_FL_CONFIG1_OFS]
                ENDIF   ;(:LNOT::DEF:NFC_NO_INIT):LAND:(NFC_SETUP != 0)


; Copy Exception Handler Addresses to Internal RAM -----------------------------
; Bootloader automatically jumps to these addresses

HADR_BASE       EQU     0xFFFFFEF0

                IF      :DEF:RAM_HADR
                ADR     R8,  Undef_Addr ; Source
                LDR     R9, =HADR_BASE  ; Destination
                LDMIA   R8!, {R0-R5}    ; Load Handler Addresses 
                STMIA   R9!, {R0-R5}    ; Store Handler Addresses
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

;  Enter System Mode and set its Stack Pointer
                MSR     CPSR_c, #Mode_SYS
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
