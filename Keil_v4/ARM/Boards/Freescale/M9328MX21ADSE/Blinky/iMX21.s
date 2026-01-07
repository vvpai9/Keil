;/*****************************************************************************/
;/* iMX21.S: Startup file for Freescale i.MX21 device series                  */
;/*****************************************************************************/
;/* <<< Use Configuration Wizard in Context Menu >>>                          */ 
;/*****************************************************************************/
;/* This file is part of the uVision/ARM development tools.                   */
;/* Copyright (c) 2005-2008 Keil Software. All rights reserved.               */
;/* This software may only be used under the terms of a valid, current,       */
;/* end user licence from KEIL for a compatible version of KEIL software      */
;/* development tools. Nothing else gives you the right to use this software. */
;/*****************************************************************************/


; The iMX21.S code is executed after CPU Reset. This file may be 
; translated with the following SET symbols. In uVision these SET 
; symbols are entered under Options - ASM - Define.
;
; CLOCK_NO_INIT:  if set, the clock controller is not initialized
;                 
; SDRAMC_NO_INIT: if set, the SDRAM controller is not initialized
;
; EIM_NO_INIT:    if set, the ext memory controller (EIM) is not initialized
;
; NFC_NO_INIT:    if set, the NAND flash controller (NFC) is not initialized
;
; RAM_HADR:       if set, exception handler addresses are copied to on-chip RAM


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


;----------------------- Memory Definitions ------------------------------------

; Internal Memory Base Addresses
IROM_BASE       EQU     0x00000000      ; 24 kB
IRAM_BASE       EQU     0xFFFFE800      ;  6 kB

; External Memory Base Addresses
CSD0_BASE       EQU     0xC0000000   
CSD1_BASE       EQU     0xC4000000
CS0_BASE        EQU     0xC8000000
CS1_BASE        EQU     0xCC000000
CS2_BASE        EQU     0xD0000000
CS3_BASE        EQU     0xD1000000
CS4_BASE        EQU     0xD2000000
CS5_BASE        EQU     0xD3000000


;----------------------- System Control Definitions ----------------------------

; System Control User Interface
SYSTEM_BASE     EQU     0x10027800      ; System Control                Base Adr
SIDR_OFS        EQU     0x04            ; Silicon ID                     Adr Ofs
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
PCSR_OFS        EQU     0x50            ; Priority Control and Select    Adr Ofs


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
                        ( 0xFF800000                ) )
AIPI2_PSR0_Val  EQU     ((AIPI2_PERI0  & 0x01)        | \
                        ((AIPI2_PERI1  & 0x01) << 1 ) | \
                        ((AIPI2_PERI2  & 0x01) << 2 ) | \
                        ((AIPI2_PERI4  & 0x01) << 4 ) | \
                        ((AIPI2_PERI5  & 0x01) << 5 ) | \
                        ((AIPI2_PERI6  & 0x01) << 6 ) | \
                        ((AIPI2_PERI7  & 0x01) << 7 ) | \
                        ((AIPI2_PERI8  & 0x01) << 8 ) | \
                        ( 0xFFFC0000                ) )
AIPI2_PSR1_Val  EQU    (((AIPI2_PERI0  & 0x02) >> 1 ) | \
                        ((AIPI2_PERI1  & 0x02)      ) | \
                        ((AIPI2_PERI2  & 0x02) << 1 ) | \
                        ((AIPI2_PERI4  & 0x02) << 3 ) | \
                        ((AIPI2_PERI5  & 0x02) << 4 ) | \
                        ((AIPI2_PERI6  & 0x02) << 5 ) | \
                        ((AIPI2_PERI7  & 0x02) << 6 ) | \
                        ((AIPI2_PERI8  & 0x02) << 7 ) | \
                        ( 0xFFFFFC08                ) )

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
AIPI1_PAR_Val   EQU     0xFFFFFFFF
AIPI2_PAR_Val   EQU     0xFFFFFFFF

;// </e> AHB-Lite IP Interface Module Configuration


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
PMCTL_OFS       EQU     0x2C            ; PMOS Switch Control            Adr Ofs
PMCOUNT_OFS     EQU     0x30            ; PMOS Switch Counter            Adr Ofs
WKGDCTL_OFS     EQU     0x34            ; Wakeup Guard Mode Control      Adr Ofs

; Constants
OSC26M_PEAK_FLD EQU     (0x03<<16)      ; Oscillator Current Amplitude     Field
AGC_FLD         EQU     (0x3F<< 8)      ; Automatic Gain Control           Field
AGC_VAL_4       EQU     (0x04<< 8)      ; Automatic Gain Control 4         Value
AGC_VAL_1       EQU     (0x01<< 8)      ; Automatic Gain Control 1         Value
SPLL_RESTART_BIT EQU    (0x01<<22)      ; SPLL Restart                     Bit
MPLL_RESTART_BIT EQU    (0x01<<21)      ; MPLL Restart                     Bit
SP_SEL_BIT      EQU     (0x01<<17)      ; SPLL Select                      Bit
MCU_SEL_BIT     EQU     (0x01<<16)      ; MPLL Select                      Bit
SPEN_BIT        EQU     (0x01<< 1)      ; SPLL Enable                      Bit
MPEN_BIT        EQU     (0x01<< 0)      ; MPLL Enable                      Bit
LF_BIT          EQU     (0x01<<15)      ; Lock Flag                        Bit

; <e> Clock Configuration
CLOCK_SETUP     EQU     1

;   <h> Clock Source Control Register (CSCR)
;     <o0.29..31> PRESC: MPU PLL Clock Prescaler <1-8><#-1>
;     <o0.26..28> USB_DIV: USB Clock Divider
;                   <0=> SPLL_CLK
;                   <1=> SPLL_CLK / 2
;                   <2=> SPLL_CLK / 3
;                   <3=> SPLL_CLK / 4
;                   <4=> SPLL_CLK / 5
;                   <5=> SPLL_CLK / 6
;                   <6=> SPLL_CLK / 7
;                   <7=> SPLL_CLK / 8
;     <o0.24..25> SD_CNT: Shut-Down Control
;                   <0=> DPLL shut-down after next rising edge of CLK32
;                   <1=> DPLL shut-down after second rising edge of CLK32
;                   <2=> DPLL shut-down after third rising edge of CLK32
;                   <3=> DPLL shut-down after fourth rising edge of CLK32
;     <o0.20> SSI2_SEL: SSI2 Baud Source Select
;                   <0=> Fractional divider from SPLL
;                   <1=> Fractional divider from MPLL
;     <o0.19> SSI1_SEL: SSI1 Baud Source Select
;                   <0=> Fractional divider from SPLL
;                   <1=> Fractional divider from MPLL
;     <o0.18> FIR_SEL: FIR and MIR Select
;                   <0=> FIRI baud rate clock divider is from MPLL
;                   <1=> FIRI baud rate clock divider is from SPLL
;     <o0.17> SP_SEL: SPLL Clock Source Select
;                   <0=> Internal premultiplier
;                   <1=> External high frequency clock
;     <o0.16> MCU_SEL: MPLL Clock Source Select
;                   <0=> Internal premultiplier
;                   <1=> External high frequency clock
;     <o0.10..13> BCLKDIV: Divider Value for HCLK Clock <1-16><#-1>
;     <o0.9> IPDIV: Peripheral Clock Divider
;                   <0=> Only for test purpose
;                   <1=> HCLK / 2
;     <o0.4> OSC26M_DIV1P5: Oscillator 26M Divide Enable
;                   <0=> OSC26M output divide by 1
;                   <1=> OSC26M output divide by 1.5
;     <o0.3> OSC26M_DIS: Oscillator Disable
;     <o0.2> FPM_EN: Frequency Premultiplier Enable
;     <o0.1> SPEN: Serial Peripheral PLL Enable
;     <o0.0> MPEN: MPLL Enable
;   </h>
CSCR_Val        EQU     0x17180607

;   <h> MPU and System PLL Control Register 0 (MPCTL0)
;     <i> fDPLL = 2*fREF*((MFI+MFN/(MFD+1))/(PD+1))
;     <i> fREF = 512*32.768 kHz or 512*32.0 kHz or 26  MHz
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
;     <o0.0..9> MFN: Multiplication Factor (Numerator) <0-1022>
;   </h>
;   <h> MPU and System PLL Control Register 1 (MPCTL1)
;     <o1.6> BRMO: BRM Order
;                   <0=> MF Fractional Part is between 1/10 and 9/10
;                   <1=> MF Fractional Part less than 1/10 or more than 9/10
;   </h>
MPCTL0_Val      EQU     0x007B1C73
MPCTL1_Val      EQU     0x00000040

;   <h> Serial Peripheral PLL Control Register 0 (SPCTL0)
;     <i> fDPLL = 2*fREF*((MFI+MFN/(MFD+1))/(PD+1))
;     <i> fREF = 512*32.768 kHz or 512*32.0 kHz or 26  MHz
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
;     <o0.0..9> MFN: Multiplication Factor (Numerator) <0-1022>
;   </h>
;   <h> Serial Peripheral PLL Control Register 1 (SPCTL1)
;     <o1.6> BRMO: BRM Order
;                   <0=> MF Fractional Part is between 1/10 and 9/10
;                   <1=> MF Fractional Part less than 1/10 or more than 9/10
;   </h>
SPCTL0_Val      EQU     0x03B02227
SPCTL1_Val      EQU     0x00000000

;   <h> Peripheral Clock Divider Register 0 (PCDR0)
;     <o0.26..31> SSI2DIV: SSI2 Baud Clock Divider
;                   <0=>     62 <1=>    2.5 <2=>     3 <3=>   3.5 <4=>     4
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
;     <o0.16..21> SSI1DIV: SSI1 Baud Clock Divider
;                   <0=>     62 <1=>    2.5 <2=>     3 <3=>   3.5 <4=>     4
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
;     <o0.12..15> NFCDIV: NAND Flash Controller Clock Divider <1-16><#-1>
;     <o0.5..7> CLKO_48MDIV: Clock Out 48M Clock Divider 1 <1-8><#-1>
;     <o0.0..4> FIRI_DIV: FIRI Divider <1-32><#-1>
;   </h>
PCDR0_Val       EQU     0x64197007

;   <h> Peripheral Clock Divider Register 1 (PCDR1)
;     <o0.24..29> PERDIV4: Peripheral Clock Divider 4 <1-64><#-1>
;     <o0.16..21> PERDIV3: Peripheral Clock Divider 3 <1-64><#-1>
;     <o0.8..13>  PERDIV2: Peripheral Clock Divider 2 <1-64><#-1>
;     <o0.0..5>   PERDIV1: Peripheral Clock Divider 1 <1-64><#-1>
;   </h>
PCDR1_Val       EQU     0x05070F0F

;   <h> Peripheral Clock Control Register 0 (PCCR0)
;     <o0.31> HCLK_CSI_EN: CMOS Sensor Interface Clock Enable
;     <o0.30> HCLK_DMA_EN: DMA Clock Enable
;     <o0.28> HCLK_BROM_EN: BROM Clock Enable
;     <o0.27> HCLK_EMMA_EN: EMMA Clock Enable
;     <o0.26> HCLK_LCDC_EN: LCDC Clock Enable
;     <o0.25> HCLK_SLCDC_EN: SLCDC Clock Enable
;     <o0.24> HCLK_USBOTG_EN: USB OTG Clock Enable
;     <o0.23> HCLK_BMI_EN: BMI Clock Enable
;     <o0.22> PERCLK4_EN: PERCLK4 Clock Enable
;     <o0.21> SLCDC_EN: SLCDC Clock Enable
;     <o0.20> FIRI_BAUD_EN: FIRI Baud Clock Enable
;     <o0.19> NFC_EN: NAND Flash Controller Clock Enable
;     <o0.18> PERCLK3_EN: PERCLK3 Clock Enable
;     <o0.17> SSI1_BAUD_EN: SSI1 Baud Clock Enable
;     <o0.16> SSI2_BAUD_EN: SSI2 Baud Clock Enable
;     <o0.15> EMMA_EN: EMMA Clock Enable
;     <o0.14> USBOTG_EN: USB OTG Clock Enable
;     <o0.13> DMA_EN: DMA Clock Enable
;     <o0.12> I2C_EN: I2C Clock Enable
;     <o0.11> GPIO_EN: GPIO Clock Enable
;     <o0.10> SDHC2_EN: SDHC2 Clock Enable
;     <o0.9>  SDHC1_EN: SDHC1 Clock Enable
;     <o0.8>  FIRI_EN: FIR Clock Enable
;     <o0.7>  SSI2_EN: SSI2 Clock Enable
;     <o0.6>  SSI1_EN: SSI1 Clock Enable
;     <o0.5>  CSPI2_EN: CSPI2 Clock Enable
;     <o0.4>  CSPI1_EN: CSPI1 Clock Enable
;     <o0.3>  UART4_EN: UART4 Clock Enable
;     <o0.2>  UART3_EN: UART3 Clock Enable
;     <o0.1>  UART2_EN: UART2 Clock Enable
;     <o0.0>  UART1_EN: UART1 Clock Enable
;   </h>
PCCR0_Val       EQU     0x31084003

;   <h> Peripheral Clock Control Register 1 (PCCR1)
;     <o0.31> OWIRE_EN: OWIRE Clock Enable
;     <o0.30> KPP_EN: KPP Clock Enable
;     <o0.29> RTC_EN: RTC Clock Enable
;     <o0.28> PWM_EN: PWM Clock Enable
;     <o0.27> GPT3_EN: GPT3 Clock Enable
;     <o0.26> GPT2_EN: GPT2 Clock Enable
;     <o0.25> GPT1_EN: GPT1 Clock Enable
;     <o0.24> WDT_EN: WDT Clock Enable
;     <o0.23> CSPI3_EN: CSPI3 Clock Enable
;   </h>
PCCR1_Val       EQU     0x00000000

; </e> Clock Configuration


;----------------------- SDRAM Definitions -------------------------------------

; SDRAM Controller User Interface
SDRAMC_BASE     EQU     0xDF000000      ; SDRAM Controller              Base Adr
SDCTL0_OFS      EQU     0x00            ; SDRAM 0 Control                Adr Ofs
SDCTL1_OFS      EQU     0x04            ; SDRAM 1 Control                Adr Ofs
SDMISC_OFS      EQU     0x14            ; SDRAM Miscellaneous            Adr Ofs
SDRST_OFS       EQU     0x18            ; SDRAM Reset                    Adr Ofs

; Constants
SDCTL_MSK       EQU     (0xFFF00000)    ; SDCTL Register Mask for Init

; Constants for Commands
NORMAL_CMD      EQU     (0x0 << 28)     ; NORMAL        Command
PALL_CMD        EQU     (0x1 << 28)     ; Precharge All Command
AREFSH_MODE     EQU     (0x2 << 28)     ; Auto-Refresh  Command
MODE_CMD        EQU     (0x3 << 28)     ; MODE          Command
MREFSH_MODE     EQU     (0x4 << 28)     ; Manual Self Refresh

; <e> SDRAM Controller Setup (SDRAMC)
SDRAMC_SETUP    EQU     1

;   <e0> SDRAM 0 Controller Setup (on CSD0)
;     <h> SDRAM 0 Control Register (SDCTL0)
;       <o1.31> SDE: SDRAM Controller Enable
;       <o1.27> SP: Supervisor Protect Enable
;       <o1.24..25> ROW: Row Address Width <11-13><#-11>
;       <o1.20..21> COL: Column Address Width <8-9><#-8>
;       <o1.16..17> DSIZ: SDRAM Memory Data Width
;                   <0=> 16-bit memory width aligned to D[31:16]
;                   <1=> 16-bit memory width aligned to D[15:0]
;                   <2=> 32-bit memory width
;                   <3=> 32-bit memory width
;       <o1.14..15> SREFR: SDRAM Refresh Rate
;                   <0=> Disabled
;                   <1=> 31.25 us
;                   <2=> 15.62 us
;                   <3=>  7.81 us
;       <o1.12..13> PWDT: Power Down Timeout
;                   <0=> Disabled
;                   <1=> Any time
;                   <2=>  64 clocks after last access
;                   <3=> 128 clocks after last access
;       <o1.10..11> CI: Cache Inhibit
;                   <0=> Disabled
;                   <1=> 1 MB
;                   <2=> 2 MB
;                   <3=> 4 MB
;       <o1.8..9> SCL: SDRAM CAS Latency
;                   <0=> Reserved
;                   <1=> 1 clock
;                   <2=> 2 clocks
;                   <3=> 3 clocks
;       <o1.6> SRP: SDRAM Row Precharge Delay
;                   <0=> 3 clocks inserted
;                   <1=> 2 clocks inserted
;       <o1.4..5> SRCD: SDRAM Row to Column Delay
;                   <0=> 4 clocks inserted
;                   <1=> 1 clock inserted
;                   <2=> 2 clocks inserted
;                   <3=> 3 clocks inserted
;       <o1.0..3> SRC: SDRAM Row Cycle Delay
;                   <0=> 10 clocks
;                   <1=> 1 clock
;                   <2=> 2 clocks
;                   <3=> 3 clocks
;                   <4=> 4 clocks
;                   <5=> 5 clocks
;                   <6=> 6 clocks
;                   <7=> 7 clocks
;                   <8=> 8 clocks
;                   <9=> 9 clocks
;     </h>
;     <h> SDRAM 0 Mode Settings (for 16Mx16x2 chip configuration)
;       <o2.20> WM: Write Mode
;                   <0=> Burst writes
;                   <1=> Single word writes
;       <o2.15..16> LTMODE: Latency Mode
;                   <0=> Reserved
;                   <1=> 1 clock
;                   <2=> 2 clocks
;                   <3=> 3 clocks
;       <o2.14> BT: Burst Type
;                   <0=> Sequential
;                   <1=> Interleave
;       <o2.11..13> BL: Burst Length
;                   <0=> 1
;                   <1=> 2
;                   <2=> 4
;                   <3=> 8
;                   <4=> Reserved
;                   <5=> Reserved
;                   <6=> Reserved
;                   <7=> Full page
;     </h>
;   </e>
SDRAMC0_SETUP   EQU     1
SDCTL0_Val      EQU     0x8212F339
SDRAM0_MODE_Val EQU     0x00119800

;   <e0> SDRAM 1 Controller Setup (on CSD1)
;     <h> SDRAM 1 Control Register (SDCTL1)
;       <o1.31> SDE: SDRAM Controller Enable
;       <o1.27> SP: Supervisor Protect Enable
;       <o1.24..25> ROW: Row Address Width <11-13><#-11>
;       <o1.20..21> COL: Column Address Width <8-9><#-8>
;       <o1.16..17> DSIZ: SDRAM Memory Data Width
;                   <0=> 16-bit memory width aligned to D[31:16]
;                   <1=> 16-bit memory width aligned to D[15:0]
;                   <2=> 32-bit memory width
;                   <3=> 32-bit memory width
;       <o1.14..15> SREFR: SDRAM Refresh Rate
;                   <0=> Disabled
;                   <1=> 31.25 us
;                   <2=> 15.62 us
;                   <3=>  7.81 us
;       <o1.12..13> PWDT: Power Down Timeout
;                   <0=> Disabled
;                   <1=> Any time
;                   <2=>  64 clocks after last access
;                   <3=> 128 clocks after last access
;       <o1.10..11> CI: Cache Inhibit
;                   <0=> Disabled
;                   <1=> 1 MB
;                   <2=> 2 MB
;                   <3=> 4 MB
;       <o1.8..9> SCL: SDRAM CAS Latency
;                   <0=> Reserved
;                   <1=> 1 clock
;                   <2=> 2 clocks
;                   <3=> 3 clocks
;       <o1.6> SRP: SDRAM Row Precharge Delay
;                   <0=> 3 clocks inserted
;                   <1=> 2 clocks inserted
;       <o1.4..5> SRCD: SDRAM Row to Column Delay
;                   <0=> 4 clocks inserted
;                   <1=> 1 clock inserted
;                   <2=> 2 clocks inserted
;                   <3=> 3 clocks inserted
;       <o1.0..3> SRC: SDRAM Row Cycle Delay
;                   <0=> 10 clocks
;                   <1=> 1 clock
;                   <2=> 2 clocks
;                   <3=> 3 clocks
;                   <4=> 4 clock
;                   <5=> 5 clocks
;                   <6=> 6 clocks
;                   <7=> 7 clock
;                   <8=> 8 clocks
;                   <9=> 9 clocks
;     </h>
;     <h> SDRAM 1 Mode Settings (for 16Mx16x2 chip configuration)
;       <o2.20> WM: Write Mode
;                   <0=> Burst writes
;                   <1=> Single word writes
;       <o2.15..16> LTMODE: Latency Mode
;                   <0=> Reserved
;                   <1=> 1 clock
;                   <2=> 2 clocks
;                   <3=> 3 clocks
;       <o2.14> BT: Burst Type
;                   <0=> Sequential
;                   <1=> Interleave
;       <o2.11..13> BL: Burst Length
;                   <0=> 1
;                   <1=> 2
;                   <2=> 4
;                   <3=> 8
;                   <4=> Reserved
;                   <5=> Reserved
;                   <6=> Reserved
;                   <7=> Full page
;     </h>
;   </e>
SDRAMC1_SETUP   EQU     0
SDCTL1_Val      EQU     0x01000300
SDRAM1_MODE_Val EQU     0x00119800

;   <h> Miscellaneous Register
;     <o0.31> OMA: Multiplexed Address Override
;                   <0=> Address from internal address multiplexed is routed out to MA0
;                   <1=> Force RMA0 out to MA0
;     <o0.0> RMA0: MA0 Replacement
;                   <0=> 0
;                   <1=> 1
;   </h>
SDMISC_Val      EQU     0x00000000

; </e>


;----------------------- External Interface Module Definitions -----------------

; External Interface Module (EIM) User Interface
EIM_BASE        EQU     0xDF001000      ; EIM                           Base Adr
CS0U_OFS        EQU     0x00            ; CS0 Upper Control Register     Adr Ofs
CS0L_OFS        EQU     0x04            ; CS0 Lower Control Register     Adr Ofs
CS1U_OFS        EQU     0x08            ; CS1 Upper Control Register     Adr Ofs
CS1L_OFS        EQU     0x0C            ; CS1 Lower Control Register     Adr Ofs
CS2U_OFS        EQU     0x10            ; CS2 Upper Control Register     Adr Ofs
CS2L_OFS        EQU     0x14            ; CS2 Lower Control Register     Adr Ofs
CS3U_OFS        EQU     0x18            ; CS3 Upper Control Register     Adr Ofs
CS3L_OFS        EQU     0x1C            ; CS3 Lower Control Register     Adr Ofs
CS4U_OFS        EQU     0x20            ; CS4 Upper Control Register     Adr Ofs
CS4L_OFS        EQU     0x24            ; CS4 Lower Control Register     Adr Ofs
CS5U_OFS        EQU     0x28            ; CS5 Upper Control Register     Adr Ofs
CS5L_OFS        EQU     0x2C            ; CS5 Lower Control Register     Adr Ofs
EIM_CNF_OFS     EQU     0x30            ; EIM Configuration Register     Adr Ofs

; <e> External Interface Module Setup (EIM)
EIM_SETUP       EQU     1

;   <e0> Setup for CS0
;     <h> Chip Select 0 Upper Control Register (CS0U)
;       <i> Configures operation of the EIM for CS0
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o1.31> SP: Supervisory Protect Enable
;         <i> If enabled, user mode accesses are not allowed.
;       <o1.30> WP: Write Protect Enable
;       <o1.28..29> BCD/DCT: Burst Clock Divisor / DTACK Check Time
;         <i> If SYNC = 1 (BCD), if SYNC = 0 (DCT).
;                   <0=> for BCD: Divisor is 1 | for DCT: 2 HCLK cycles between CS and DTACK
;                   <1=> for BCD: Divisor is 2 | for DCT: 3 HCLK cycles between CS and DTACK
;                   <2=> for BCD: Divisor is 3 | for DCT: 4 HCLK cycles between CS and DTACK
;                   <3=> for BCD: Divisor is 4 | for DCT: 5 HCLK cycles between CS and DTACK
;       <o1.24..27> BCS/RWA: Burst Clock Start / Read/Write Assertion <0-15>
;         <i> If SYNC = 1 (BCS), if SYNC = 0 (RWA).
;         <i> Values are in half HCLK cycles. For BCS, 1 is added to field value.
;       <o1.22..23> PSZ: Page Size
;                   <0=> 4 words
;                   <1=> 8 words
;                   <2=> 16 words
;                   <3=> 32 words
;       <o1.21> PME: Page Mode Emulation Enable
;       <o1.20> SYNC: Synchronous Burst Mode Enable
;       <o1.16..19> DOL/RWN: Data Output Length / Read/Write Negation <0-15>
;         <i> If SYNC = 1 (DOL), if SYNC = 0 (RWN).
;         <i> Values for DOL are in HCLK cycles and for RWN in half HCLK cycles. 
;         <i> For DOL, 1 is added to field value.
;       <o1.14..15> CNC: Chip Select Negation Clock Cycles (in HCLK clock cycles) <0-3>
;       <o1.8..13> WSC: Wait State Control <0-63>
;       <o1.7> EW: !ECB / WAIT
;                   <0=> for SYNC = 1: ECB mode  | for SYNC = 0: !DTACK level sensitive operation disabled
;                   <1=> for SYNC = 1: WAIT mode | for SYNC = 0: !DTACK level sensitive operation enabled
;       <o1.4..6> WWS: Write Wait State <0-7>
;       <o1.0..3> EDC: Extra Dead Cycles (in HCLK clock cycles) <0-15>
;     </h>
;     <h> Chip Select 0 Lower Control Register (CS0L)
;       <i> Configures operation of the EIM for CS0
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o2.28..31> OEA: !OE Assert (in half HCLK cycles) <0-15>
;       <o2.24..27> OEN: !OE Negate (in half HCLK cycles) <0-15>
;       <o2.20..23> WEA: !EB[3:0] Assert (in half HCLK cycles) <0-15>
;       <o2.16..19> WEN: !EB[3:0] Negate During Write (in half HCLK cycles) <0-15>
;       <o2.12..15> CSA: Chip Select Assert (in half HCLK cycles) <0-15>
;       <o2.11> EBC: Enable Byte Control
;                   <0=> Read and write accesses assert !EB[3:0]
;                   <1=> Only write accesses assert !EB[3:0]
;       <o2.8..10> DSZ: Data Port Size
;                   <0=> 8-bit port, on D[31:24]
;                   <1=> 8-bit port, on D[23:16]
;                   <2=> 8-bit port, on D[15:8]
;                   <3=> 8-bit port, on D[15:0]
;                   <4=> 16-bit port, on D[31:16]
;                   <5=> 16-bit port, on D[15:0]
;                   <6=> 32-bit port
;                   <7=> Reserved
;       <o2.4..7> CSN: !CS Negate (in half HCLK cycles) <0-15>
;       <o2.3> PSR: Pseudo SRAM Enable
;       <o2.2> CRE: Control Register Enable
;       <o2.1> WRAP: Wrap Memory Mode Enable
;       <o2.0> CSEN: !CS Enable
;     </h>
;   </e>
EIM_CS0_SETUP   EQU     1
CS0U_Val        EQU     0x00000A01
CS0L_Val        EQU     0x00000E01

;   <e0> Setup for CS1
;     <h> Chip Select 0 Upper Control Register (CS1U)
;       <i> Configures operation of the EIM for CS1
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o1.31> SP: Supervisory Protect Enable
;         <i> If enabled, user mode accesses are not allowed.
;       <o1.30> WP: Write Protect Enable
;       <o1.28..29> BCD/DCT: Burst Clock Divisor / DTACK Check Time
;         <i> If SYNC = 1 (BCD), if SYNC = 0 (DCT).
;                   <0=> for BCD: Divisor is 1 | for DCT: 2 HCLK cycles between CS and DTACK
;                   <1=> for BCD: Divisor is 2 | for DCT: 3 HCLK cycles between CS and DTACK
;                   <2=> for BCD: Divisor is 3 | for DCT: 4 HCLK cycles between CS and DTACK
;                   <3=> for BCD: Divisor is 4 | for DCT: 5 HCLK cycles between CS and DTACK
;       <o1.24..27> BCS/RWA: Burst Clock Start / Read/Write Assertion <0-15>
;         <i> If SYNC = 1 (BCS), if SYNC = 0 (RWA).
;         <i> Values are in half HCLK cycles. For BCS, 1 is added to field value.
;       <o1.22..23> PSZ: Page Size
;                   <0=> 4 words
;                   <1=> 8 words
;                   <2=> 16 words
;                   <3=> 32 words
;       <o1.21> PME: Page Mode Emulation Enable
;       <o1.20> SYNC: Synchronous Burst Mode Enable
;       <o1.16..19> DOL/RWN: Data Output Length / Read/Write Negation <0-15>
;         <i> If SYNC = 1 (DOL), if SYNC = 0 (RWN).
;         <i> Values for DOL are in HCLK cycles and for RWN in half HCLK cycles. 
;         <i> For DOL, 1 is added to field value.
;       <o1.14..15> CNC: Chip Select Negation Clock Cycles (in HCLK clock cycles) <0-3>
;       <o1.8..13> WSC: Wait State Control <0-63>
;       <o1.7> EW: !ECB / WAIT
;                   <0=> for SYNC = 1: ECB mode  | for SYNC = 0: !DTACK level sensitive operation disabled
;                   <1=> for SYNC = 1: WAIT mode | for SYNC = 0: !DTACK level sensitive operation enabled
;       <o1.4..6> WWS: Write Wait State <0-7>
;       <o1.0..3> EDC: Extra Dead Cycles (in HCLK clock cycles) <0-15>
;     </h>
;     <h> Chip Select 0 Lower Control Register (CS1L)
;       <i> Configures operation of the EIM for CS1
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o2.28..31> OEA: !OE Assert (in half HCLK cycles) <0-15>
;       <o2.24..27> OEN: !OE Negate (in half HCLK cycles) <0-15>
;       <o2.20..23> WEA: !EB[3:0] Assert (in half HCLK cycles) <0-15>
;       <o2.16..19> WEN: !EB[3:0] Negate During Write (in half HCLK cycles) <0-15>
;       <o2.12..15> CSA: Chip Select Assert (in half HCLK cycles) <0-15>
;       <o2.11> EBC: Enable Byte Control
;                   <0=> Read and write accesses assert !EB[3:0]
;                   <1=> Only write accesses assert !EB[3:0]
;       <o2.8..10> DSZ: Data Port Size
;                   <0=> 8-bit port, on D[31:24]
;                   <1=> 8-bit port, on D[23:16]
;                   <2=> 8-bit port, on D[15:8]
;                   <3=> 8-bit port, on D[15:0]
;                   <4=> 16-bit port, on D[31:16]
;                   <5=> 16-bit port, on D[15:0]
;                   <6=> 32-bit port
;                   <7=> Reserved
;       <o2.4..7> CSN: !CS Negate (in half HCLK cycles) <0-15>
;       <o2.3> PSR: Pseudo SRAM Enable
;       <o2.2> CRE: Control Register Enable
;       <o2.1> WRAP: Wrap Memory Mode Enable
;       <o2.0> CSEN: !CS Enable
;     </h>
;   </e>
EIM_CS1_SETUP   EQU     1
CS1U_Val        EQU     0x00002000
CS1L_Val        EQU     0x11118501

;   <e0> Setup for CS2
;     <h> Chip Select 0 Upper Control Register (CS2U)
;       <i> Configures operation of the EIM for CS2
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o1.31> SP: Supervisory Protect Enable
;         <i> If enabled, user mode accesses are not allowed.
;       <o1.30> WP: Write Protect Enable
;       <o1.28..29> BCD/DCT: Burst Clock Divisor / DTACK Check Time
;         <i> If SYNC = 1 (BCD), if SYNC = 0 (DCT).
;                   <0=> for BCD: Divisor is 1 | for DCT: 2 HCLK cycles between CS and DTACK
;                   <1=> for BCD: Divisor is 2 | for DCT: 3 HCLK cycles between CS and DTACK
;                   <2=> for BCD: Divisor is 3 | for DCT: 4 HCLK cycles between CS and DTACK
;                   <3=> for BCD: Divisor is 4 | for DCT: 5 HCLK cycles between CS and DTACK
;       <o1.24..27> BCS/RWA: Burst Clock Start / Read/Write Assertion <0-15>
;         <i> If SYNC = 1 (BCS), if SYNC = 0 (RWA).
;         <i> Values are in half HCLK cycles. For BCS, 1 is added to field value.
;       <o1.22..23> PSZ: Page Size
;                   <0=> 4 words
;                   <1=> 8 words
;                   <2=> 16 words
;                   <3=> 32 words
;       <o1.21> PME: Page Mode Emulation Enable
;       <o1.20> SYNC: Synchronous Burst Mode Enable
;       <o1.16..19> DOL/RWN: Data Output Length / Read/Write Negation <0-15>
;         <i> If SYNC = 1 (DOL), if SYNC = 0 (RWN).
;         <i> Values for DOL are in HCLK cycles and for RWN in half HCLK cycles. 
;         <i> For DOL, 1 is added to field value.
;       <o1.14..15> CNC: Chip Select Negation Clock Cycles (in HCLK clock cycles) <0-3>
;       <o1.8..13> WSC: Wait State Control <0-63>
;       <o1.7> EW: !ECB / WAIT
;                   <0=> for SYNC = 1: ECB mode  | for SYNC = 0: !DTACK level sensitive operation disabled
;                   <1=> for SYNC = 1: WAIT mode | for SYNC = 0: !DTACK level sensitive operation enabled
;       <o1.4..6> WWS: Write Wait State <0-7>
;       <o1.0..3> EDC: Extra Dead Cycles (in HCLK clock cycles) <0-15>
;     </h>
;     <h> Chip Select 0 Lower Control Register (CS2L)
;       <i> Configures operation of the EIM for CS2
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o2.28..31> OEA: !OE Assert (in half HCLK cycles) <0-15>
;       <o2.24..27> OEN: !OE Negate (in half HCLK cycles) <0-15>
;       <o2.20..23> WEA: !EB[3:0] Assert (in half HCLK cycles) <0-15>
;       <o2.16..19> WEN: !EB[3:0] Negate During Write (in half HCLK cycles) <0-15>
;       <o2.12..15> CSA: Chip Select Assert (in half HCLK cycles) <0-15>
;       <o2.11> EBC: Enable Byte Control
;                   <0=> Read and write accesses assert !EB[3:0]
;                   <1=> Only write accesses assert !EB[3:0]
;       <o2.8..10> DSZ: Data Port Size
;                   <0=> 8-bit port, on D[31:24]
;                   <1=> 8-bit port, on D[23:16]
;                   <2=> 8-bit port, on D[15:8]
;                   <3=> 8-bit port, on D[15:0]
;                   <4=> 16-bit port, on D[31:16]
;                   <5=> 16-bit port, on D[15:0]
;                   <6=> 32-bit port
;                   <7=> Reserved
;       <o2.4..7> CSN: !CS Negate (in half HCLK cycles) <0-15>
;       <o2.3> PSR: Pseudo SRAM Enable
;       <o2.2> CRE: Control Register Enable
;       <o2.1> WRAP: Wrap Memory Mode Enable
;       <o2.0> CSEN: !CS Enable
;     </h>
;   </e>
EIM_CS2_SETUP   EQU     0
CS2U_Val        EQU     0x00003E00
CS2L_Val        EQU     0x20000801

;   <e0> Setup for CS3
;     <h> Chip Select 0 Upper Control Register (CS3U)
;       <i> Configures operation of the EIM for CS3
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o1.31> SP: Supervisory Protect Enable
;         <i> If enabled, user mode accesses are not allowed.
;       <o1.30> WP: Write Protect Enable
;       <o1.28..29> BCD/DCT: Burst Clock Divisor / DTACK Check Time
;         <i> If SYNC = 1 (BCD), if SYNC = 0 (DCT).
;                   <0=> for BCD: Divisor is 1 | for DCT: 2 HCLK cycles between CS and DTACK
;                   <1=> for BCD: Divisor is 2 | for DCT: 3 HCLK cycles between CS and DTACK
;                   <2=> for BCD: Divisor is 3 | for DCT: 4 HCLK cycles between CS and DTACK
;                   <3=> for BCD: Divisor is 4 | for DCT: 5 HCLK cycles between CS and DTACK
;       <o1.24..27> BCS/RWA: Burst Clock Start / Read/Write Assertion <0-15>
;         <i> If SYNC = 1 (BCS), if SYNC = 0 (RWA).
;         <i> Values are in half HCLK cycles. For BCS, 1 is added to field value.
;       <o1.22..23> PSZ: Page Size
;                   <0=> 4 words
;                   <1=> 8 words
;                   <2=> 16 words
;                   <3=> 32 words
;       <o1.21> PME: Page Mode Emulation Enable
;       <o1.20> SYNC: Synchronous Burst Mode Enable
;       <o1.16..19> DOL/RWN: Data Output Length / Read/Write Negation <0-15>
;         <i> If SYNC = 1 (DOL), if SYNC = 0 (RWN).
;         <i> Values for DOL are in HCLK cycles and for RWN in half HCLK cycles. 
;         <i> For DOL, 1 is added to field value.
;       <o1.14..15> CNC: Chip Select Negation Clock Cycles (in HCLK clock cycles) <0-3>
;       <o1.8..13> WSC: Wait State Control <0-63>
;       <o1.7> EW: !ECB / WAIT
;                   <0=> for SYNC = 1: ECB mode  | for SYNC = 0: !DTACK level sensitive operation disabled
;                   <1=> for SYNC = 1: WAIT mode | for SYNC = 0: !DTACK level sensitive operation enabled
;       <o1.4..6> WWS: Write Wait State <0-7>
;       <o1.0..3> EDC: Extra Dead Cycles (in HCLK clock cycles) <0-15>
;     </h>
;     <h> Chip Select 0 Lower Control Register (CS3L)
;       <i> Configures operation of the EIM for CS3
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o2.28..31> OEA: !OE Assert (in half HCLK cycles) <0-15>
;       <o2.24..27> OEN: !OE Negate (in half HCLK cycles) <0-15>
;       <o2.20..23> WEA: !EB[3:0] Assert (in half HCLK cycles) <0-15>
;       <o2.16..19> WEN: !EB[3:0] Negate During Write (in half HCLK cycles) <0-15>
;       <o2.12..15> CSA: Chip Select Assert (in half HCLK cycles) <0-15>
;       <o2.11> EBC: Enable Byte Control
;                   <0=> Read and write accesses assert !EB[3:0]
;                   <1=> Only write accesses assert !EB[3:0]
;       <o2.8..10> DSZ: Data Port Size
;                   <0=> 8-bit port, on D[31:24]
;                   <1=> 8-bit port, on D[23:16]
;                   <2=> 8-bit port, on D[15:8]
;                   <3=> 8-bit port, on D[15:0]
;                   <4=> 16-bit port, on D[31:16]
;                   <5=> 16-bit port, on D[15:0]
;                   <6=> 32-bit port
;                   <7=> Reserved
;       <o2.4..7> CSN: !CS Negate (in half HCLK cycles) <0-15>
;       <o2.3> PSR: Pseudo SRAM Enable
;       <o2.2> CRE: Control Register Enable
;       <o2.1> WRAP: Wrap Memory Mode Enable
;       <o2.0> CSEN: !CS Enable
;     </h>
;   </e>
EIM_CS3_SETUP   EQU     0
CS3U_Val        EQU     0x00003E00
CS3L_Val        EQU     0x20000801

;   <e0> Setup for CS4
;     <h> Chip Select 0 Upper Control Register (CS4U)
;       <i> Configures operation of the EIM for CS4
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o1.31> SP: Supervisory Protect Enable
;         <i> If enabled, user mode accesses are not allowed.
;       <o1.30> WP: Write Protect Enable
;       <o1.28..29> BCD/DCT: Burst Clock Divisor / DTACK Check Time
;         <i> If SYNC = 1 (BCD), if SYNC = 0 (DCT).
;                   <0=> for BCD: Divisor is 1 | for DCT: 2 HCLK cycles between CS and DTACK
;                   <1=> for BCD: Divisor is 2 | for DCT: 3 HCLK cycles between CS and DTACK
;                   <2=> for BCD: Divisor is 3 | for DCT: 4 HCLK cycles between CS and DTACK
;                   <3=> for BCD: Divisor is 4 | for DCT: 5 HCLK cycles between CS and DTACK
;       <o1.24..27> BCS/RWA: Burst Clock Start / Read/Write Assertion <0-15>
;         <i> If SYNC = 1 (BCS), if SYNC = 0 (RWA).
;         <i> Values are in half HCLK cycles. For BCS, 1 is added to field value.
;       <o1.22..23> PSZ: Page Size
;                   <0=> 4 words
;                   <1=> 8 words
;                   <2=> 16 words
;                   <3=> 32 words
;       <o1.21> PME: Page Mode Emulation Enable
;       <o1.20> SYNC: Synchronous Burst Mode Enable
;       <o1.16..19> DOL/RWN: Data Output Length / Read/Write Negation <0-15>
;         <i> If SYNC = 1 (DOL), if SYNC = 0 (RWN).
;         <i> Values for DOL are in HCLK cycles and for RWN in half HCLK cycles. 
;         <i> For DOL, 1 is added to field value.
;       <o1.14..15> CNC: Chip Select Negation Clock Cycles (in HCLK clock cycles) <0-3>
;       <o1.8..13> WSC: Wait State Control <0-63>
;       <o1.7> EW: !ECB / WAIT
;                   <0=> for SYNC = 1: ECB mode  | for SYNC = 0: !DTACK level sensitive operation disabled
;                   <1=> for SYNC = 1: WAIT mode | for SYNC = 0: !DTACK level sensitive operation enabled
;       <o1.4..6> WWS: Write Wait State <0-7>
;       <o1.0..3> EDC: Extra Dead Cycles (in HCLK clock cycles) <0-15>
;     </h>
;     <h> Chip Select 0 Lower Control Register (CS4L)
;       <i> Configures operation of the EIM for CS4
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o2.28..31> OEA: !OE Assert (in half HCLK cycles) <0-15>
;       <o2.24..27> OEN: !OE Negate (in half HCLK cycles) <0-15>
;       <o2.20..23> WEA: !EB[3:0] Assert (in half HCLK cycles) <0-15>
;       <o2.16..19> WEN: !EB[3:0] Negate During Write (in half HCLK cycles) <0-15>
;       <o2.12..15> CSA: Chip Select Assert (in half HCLK cycles) <0-15>
;       <o2.11> EBC: Enable Byte Control
;                   <0=> Read and write accesses assert !EB[3:0]
;                   <1=> Only write accesses assert !EB[3:0]
;       <o2.8..10> DSZ: Data Port Size
;                   <0=> 8-bit port, on D[31:24]
;                   <1=> 8-bit port, on D[23:16]
;                   <2=> 8-bit port, on D[15:8]
;                   <3=> 8-bit port, on D[15:0]
;                   <4=> 16-bit port, on D[31:16]
;                   <5=> 16-bit port, on D[15:0]
;                   <6=> 32-bit port
;                   <7=> Reserved
;       <o2.4..7> CSN: !CS Negate (in half HCLK cycles) <0-15>
;       <o2.3> PSR: Pseudo SRAM Enable
;       <o2.2> CRE: Control Register Enable
;       <o2.1> WRAP: Wrap Memory Mode Enable
;       <o2.0> CSEN: !CS Enable
;     </h>
;   </e>
EIM_CS4_SETUP   EQU     0
CS4U_Val        EQU     0x00003E00
CS4L_Val        EQU     0x20000801

;   <e0> Setup for CS5
;     <h> Chip Select 0 Upper Control Register (CS5U)
;       <i> Configures operation of the EIM for CS5
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o1.31> SP: Supervisory Protect Enable
;         <i> If enabled, user mode accesses are not allowed.
;       <o1.30> WP: Write Protect Enable
;       <o1.28..29> BCD/DCT: Burst Clock Divisor / DTACK Check Time
;         <i> If SYNC = 1 (BCD), if SYNC = 0 (DCT).
;                   <0=> for BCD: Divisor is 1 | for DCT: 2 HCLK cycles between CS and DTACK
;                   <1=> for BCD: Divisor is 2 | for DCT: 3 HCLK cycles between CS and DTACK
;                   <2=> for BCD: Divisor is 3 | for DCT: 4 HCLK cycles between CS and DTACK
;                   <3=> for BCD: Divisor is 4 | for DCT: 5 HCLK cycles between CS and DTACK
;       <o1.24..27> BCS/RWA: Burst Clock Start / Read/Write Assertion <0-15>
;         <i> If SYNC = 1 (BCS), if SYNC = 0 (RWA).
;         <i> Values are in half HCLK cycles. For BCS, 1 is added to field value.
;       <o1.22..23> PSZ: Page Size
;                   <0=> 4 words
;                   <1=> 8 words
;                   <2=> 16 words
;                   <3=> 32 words
;       <o1.21> PME: Page Mode Emulation Enable
;       <o1.20> SYNC: Synchronous Burst Mode Enable
;       <o1.16..19> DOL/RWN: Data Output Length / Read/Write Negation <0-15>
;         <i> If SYNC = 1 (DOL), if SYNC = 0 (RWN).
;         <i> Values for DOL are in HCLK cycles and for RWN in half HCLK cycles. 
;         <i> For DOL, 1 is added to field value.
;       <o1.14..15> CNC: Chip Select Negation Clock Cycles (in HCLK clock cycles) <0-3>
;       <o1.8..13> WSC: Wait State Control <0-63>
;       <o1.7> EW: !ECB / WAIT
;                   <0=> for SYNC = 1: ECB mode  | for SYNC = 0: !DTACK level sensitive operation disabled
;                   <1=> for SYNC = 1: WAIT mode | for SYNC = 0: !DTACK level sensitive operation enabled
;       <o1.4..6> WWS: Write Wait State <0-7>
;       <o1.0..3> EDC: Extra Dead Cycles (in HCLK clock cycles) <0-15>
;     </h>
;     <h> Chip Select 0 Lower Control Register (CS5L)
;       <i> Configures operation of the EIM for CS5
;       <i> Look into Reference Manual for detailed explanation of fields!
;       <o2.28..31> OEA: !OE Assert (in half HCLK cycles) <0-15>
;       <o2.24..27> OEN: !OE Negate (in half HCLK cycles) <0-15>
;       <o2.20..23> WEA: !EB[3:0] Assert (in half HCLK cycles) <0-15>
;       <o2.16..19> WEN: !EB[3:0] Negate During Write (in half HCLK cycles) <0-15>
;       <o2.12..15> CSA: Chip Select Assert (in half HCLK cycles) <0-15>
;       <o2.11> EBC: Enable Byte Control
;                   <0=> Read and write accesses assert !EB[3:0]
;                   <1=> Only write accesses assert !EB[3:0]
;       <o2.8..10> DSZ: Data Port Size
;                   <0=> 8-bit port, on D[31:24]
;                   <1=> 8-bit port, on D[23:16]
;                   <2=> 8-bit port, on D[15:8]
;                   <3=> 8-bit port, on D[15:0]
;                   <4=> 16-bit port, on D[31:16]
;                   <5=> 16-bit port, on D[15:0]
;                   <6=> 32-bit port
;                   <7=> Reserved
;       <o2.4..7> CSN: !CS Negate (in half HCLK cycles) <0-15>
;       <o2.3> PSR: Pseudo SRAM Enable
;       <o2.2> CRE: Control Register Enable
;       <o2.1> WRAP: Wrap Memory Mode Enable
;       <o2.0> CSEN: !CS Enable
;     </h>
;   </e>
EIM_CS5_SETUP   EQU     0
CS5U_Val        EQU     0x00003E00
CS5L_Val        EQU     0x20000801

;   <h> EIM Configuration Register (EIM_CNF)
;     <i> Configures operation of the EIM
;     <i> Look into Reference Manual for detailed explanation of fields!
;     <o0.2> BCM: Burst Clock Mode Enable
;     <o0.1> AGE: Acknowledge Glue Enable
;   </h>
EIM_CNF_Val     EQU     0x00000004

; </e>


;----------------------- NAND Flash Definitions --------------------------------

; NAND Flash Controller (NFC) User Interface
NFC_BASE              EQU   0xDF003E00  ; NADN Flash Controller         Base Adr
NFC_BUFSIZ_OFS        EQU   0x00        ; NFC Buffer Size Reg            Adr Ofs
BLOCK_ADR_LOCK_OFS    EQU   0x02        ; Block Address Lock Check       Adr Ofs
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
;     <o0.0..15> USBA: Unlock Start Block Address
;   </h>
UNLOCK_S_BLK_ADR_Val  EQU   0x0000

;   <h> Address to Unlock in Write Protection Mode - End (UNLOCK_END_BLK_ADD)
;     <o0.0..15> UEBA: Unlock End Block Address
;   </h>
UNLOCK_E_BLK_ADR_Val  EQU   0x0000

;   <h> NAND Flash Operation Configuration 1 (NAND_FLASH_CONFIG1)
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
                LDR     PC,IRQ_Addr     
                LDR     PC,FIQ_Addr

Reset_Addr      DCD     Reset_Handler
Undef_Addr      DCD     Undef_Handler
SWI_Addr        DCD     SWI_Handler
PAbt_Addr       DCD     PAbt_Handler
DAbt_Addr       DCD     DAbt_Handler
IRQ_Addr        DCD     IRQ_Handler
FIQ_Addr        DCD     FIQ_Handler

Undef_Handler   B       Undef_Handler
SWI_Handler     B       SWI_Handler
PAbt_Handler    B       PAbt_Handler
DAbt_Handler    B       DAbt_Handler
IRQ_Handler     B       IRQ_Handler
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
                IF      (CSCR_Val:AND:(MCU_SEL_BIT|SP_SEL_BIT)) != 0
Trim            LDR     R2, [R0, #OSC26MCTL_OFS]
                ANDS    R1, R2, #OSC26M_PEAK_FLD
                BEQ     Operate
                SUB     R2, R2, #AGC_VAL_1
                AND     R2, R2, #AGC_FLD
                STR     R2, [R0, #OSC26MCTL_OFS]
                LDR     R6, =4608                 ; ~30us at 266 MHz
WaitTrim0       SUBS    R6, R6, #1
                BNE     WaitTrim0
                B       Trim
Operate         MOV     R3, R2
                SUBS    R2, R2, #AGC_VAL_4
                BPL     TrimVal
                MVN     R2, #AGC_FLD
                AND     R2, R3, R2
TrimVal         STR     R2, [R0, #OSC26MCTL_OFS]
                LDR     R6, =4608                 ; ~30us at 266 MHz
WaitTrim1       SUBS    R6, R6, #1
                BNE     WaitTrim1
                ENDIF

                ; If MPLL is used
                IF      (CSCR_Val:AND:MPEN_BIT) != 0
                LDR     R1, =MPCTL0_Val
                STR     R1, [R0, #MPCTL0_OFS]
                LDR     R1, =MPCTL1_Val
                STR     R1, [R0, #MPCTL1_OFS]
                LDR     R1, =CSCR_Val
                MOV     R2, #MPLL_RESTART_BIT
                ORR     R1, R1, R2
                STR     R1, [R0, #CSCR_OFS]
MPLL_Loop       LDR     R1, [R0, #MPCTL1_OFS]
                ANDS    R1, R1, #LF_BIT
                BEQ     MPLL_Loop
                ENDIF

                ; If SPLL is used
                IF      (CSCR_Val:AND:SPEN_BIT) != 0
                LDR     R1, =SPCTL0_Val
                STR     R1, [R0, #SPCTL0_OFS]
                LDR     R1, =SPCTL1_Val
                STR     R1, [R0, #SPCTL1_OFS]
                LDR     R1, =CSCR_Val
                MOV     R2, #SPLL_RESTART_BIT
                ORR     R1, R1, R2
                STR     R1, [R0, #CSCR_OFS]
SPLL_Loop       LDR     R1, [R0, #SPCTL1_OFS]
                ANDS    R1, R1, #LF_BIT
                BEQ     SPLL_Loop
                ENDIF

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


; SDRAM Setup ------------------------------------------------------------------

                IF      (:LNOT::DEF:SDRAMC_NO_INIT):LAND:(SDRAMC_SETUP != 0)
                LDR     R0, =SYSTEM_BASE          ; Address of System Controller
                LDR     R1, =SDRAMC_BASE          ; Address of SDRAM Controller
                MOV     R2, #CSD0_BASE            ; CSD0 Area Address
                MOV     R8, #0

                IF      (SDRAMC0_SETUP != 0)
                LDR     R4, [R0, #FMCR_OFS]
                MOV     R5, #0x00000001
                ORR     R4, R4, R5
                STR     R4, [R0, #FMCR_OFS]
                LDR     R4, =((SDCTL0_Val & SDCTL_MSK) | PALL_CMD)
                STR     R4, [R1, #SDCTL0_OFS]
                LDR     R4, =(CSD0_BASE | (1 << 21))
                STR     R8, [R4, #0]
                LDR     R4, =((SDCTL0_Val & SDCTL_MSK) | AREFSH_MODE)
                STR     R4, [R1, #SDCTL0_OFS]
                STR     R8, [R2, #0]
                STR     R8, [R2, #0]
                STR     R8, [R2, #0]
                STR     R8, [R2, #0]
                STR     R8, [R2, #0]
                STR     R8, [R2, #0]
                STR     R8, [R2, #0]
                STR     R8, [R2, #0]
                LDR     R4, =((SDCTL0_Val & SDCTL_MSK) | MODE_CMD)
                STR     R4, [R1, #SDCTL0_OFS]
                LDR     R4, =(CSD0_BASE | SDRAM0_MODE_Val)
                LDR     R4, [R4, #0]
                LDR     R4, =SDCTL0_Val
                STR     R4, [R1, #SDCTL0_OFS]
                ENDIF   ;(SDRAMC0_SETUP != 0)

                IF      (SDRAMC1_SETUP != 0)
                ; Code needs to be written to initialize used SDRAM
                ENDIF   ;(SDRAMC1_SETUP != 0)

                LDR     R4, =SDMISC_Val
                STR     R4, [R1, #SDMISC_OFS]
                ENDIF   ;(:LNOT::DEF:SDRAMC_NO_INIT):LAND:(SDRAMC_SETUP != 0)


; External Interface Module (EIM) Setup ----------------------------------------

                IF      (:LNOT::DEF:EIM_NO_INIT):LAND:(EIM_SETUP != 0)
                LDR     R0, =SYSTEM_BASE          ; Address of System Controller
                LDR     R1, =EIM_BASE             ; Address of EIM Controller

                IF      (EIM_CS0_SETUP != 0)
                LDR     R2, =CS0U_Val
                LDR     R3, =CS0L_Val
                STR     R2, [R1, #CS0U_OFS]
                STR     R3, [R1, #CS0L_OFS]
                ENDIF   ;(EIM_CS0_SETUP != 0)

                IF      (EIM_CS1_SETUP != 0)
                LDR     R2, =CS1U_Val
                LDR     R3, =CS1L_Val
                STR     R2, [R1, #CS1U_OFS]
                STR     R3, [R1, #CS1L_OFS]
                ENDIF   ;(EIM_CS1_SETUP != 0)

                IF      (EIM_CS2_SETUP != 0)
                LDR     R2, =CS2U_Val
                LDR     R3, =CS2L_Val
                STR     R2, [R1, #CS2U_OFS]
                STR     R3, [R1, #CS2L_OFS]
                ENDIF   ;(EIM_CS2_SETUP != 0)

                IF      (EIM_CS3_SETUP != 0)
                LDR     R2, =CS3U_Val
                LDR     R3, =CS3L_Val
                STR     R2, [R1, #CS3U_OFS]
                STR     R3, [R1, #CS3L_OFS]
                ENDIF   ;(EIM_CS3_SETUP != 0)

                IF      (EIM_CS4_SETUP != 0)
                LDR     R2, =CS4U_Val
                LDR     R3, =CS4L_Val
                STR     R2, [R1, #CS4U_OFS]
                STR     R3, [R1, #CS4L_OFS]
                ENDIF   ;(EIM_CS4_SETUP != 0)

                IF      (EIM_CS5_SETUP != 0)
                LDR     R2, =CS5U_Val
                LDR     R3, =CS5L_Val
                STR     R2, [R1, #CS5U_OFS]
                STR     R3, [R1, #CS5L_OFS]
                ENDIF   ;(EIM_CS5_SETUP != 0)

                LDR     R2, =EIM_CNF_Val
                STR     R2, [R1, #EIM_CNF_OFS]

                ENDIF   ;(:LNOT::DEF:EIM_NO_INIT):LAND:(EIM_SETUP != 0)


; NAND Flash Setup -------------------------------------------------------------

                IF      (:LNOT::DEF:NFC_NO_INIT):LAND:(NFC_SETUP != 0)
                LDR     R0, =SYSTEM_BASE          ; Address of System Controller
                LDR     R1, =NFC_BASE             ; Address of NFC Controller

                LDR     R2, [R0, #FMCR_OFS]
                MOV     R3, #(1<<5)
                ORR     R2, R2, R3
                STR     R2, [R0, #FMCR_OFS]

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

;  Enter User Mode and set its Stack Pointer
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
