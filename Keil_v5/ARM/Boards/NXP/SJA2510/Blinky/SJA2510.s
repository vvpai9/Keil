;/*****************************************************************************/
;/* SJA2510.S: Startup file for NXP SJA2510 device series                     */
;/*****************************************************************************/
;/* <<< Use Configuration Wizard in Context Menu >>>                          */
;/*****************************************************************************/
;/* This file is part of the uVision/ARM development tools.                   */
;/* Copyright (c) 2007 Keil - An ARM Company. All rights reserved.            */
;/* This software may only be used under the terms of a valid, current,       */
;/* end user licence from KEIL for a compatible version of KEIL software      */
;/* development tools. Nothing else gives you the right to use this software. */
;/*****************************************************************************/


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
;//     <o0.12..23>    LOAD: Load Value <0x0-0x3FF>
;//     <o0.0..11> DENOMINATOR: Denominator or Modulo Value <0x0-0x3FF>
;//   </h>
;//   <h> FDIV Control 1 Register (FDIV_CONTROL_1)
;//     <o1.24..31> CLK_SEL: Clock Source Selection
;//                     <0=> LP_OSC
;//                     <1=> Crystal Oscillator
;//                     <2=> PLL
;//                     <3=> PLL + 120°
;//                     <4=> PLL + 240°
;//     <o1.12..23>    LOAD: Load Value <0x0-0x3FF>
;//     <o1.0..11> DENOMINATOR: Denominator or Modulo Value <0x0-0x3FF>
;//   </h>
;//   <h> FDIV Control 2 Register (FDIV_CONTROL_2)
;//     <o2.24..31> CLK_SEL: Clock Source Selection
;//                     <0=> LP_OSC
;//                     <1=> Crystal Oscillator
;//                     <2=> PLL
;//                     <3=> PLL + 120°
;//                     <4=> PLL + 240°
;//     <o2.12..23>    LOAD: Load Value <0x0-0x3FF>
;//     <o2.0..11> DENOMINATOR: Denominator or Modulo Value <0x0-0x3FF>
;//   </h>
;//   <h> FDIV Control 3 Register (FDIV_CONTROL_3)
;//     <o3.24..31> CLK_SEL: Clock Source Selection
;//                     <0=> LP_OSC
;//                     <1=> Crystal Oscillator
;//                     <2=> PLL
;//                     <3=> PLL + 120°
;//                     <4=> PLL + 240°
;//     <o3.12..23>    LOAD: Load Value <0x0-0x3FF>
;//     <o3.0..11> DENOMINATOR: Denominator or Modulo Value <0x0-0x3FF>
;//   </h>
;//   <h> FDIV Control 4 Register (FDIV_CONTROL_4)
;//     <o4.24..31> CLK_SEL: Clock Source Selection
;//                     <0=> LP_OSC
;//                     <1=> Crystal Oscillator
;//                     <2=> PLL
;//                     <3=> PLL + 120°
;//                     <4=> PLL + 240°
;//     <o4.12..23>    LOAD: Load Value <0x0-0x3FF>
;//     <o4.0..11> DENOMINATOR: Denominator or Modulo Value <0x0-0x3FF>
;//   </h>
;//   <h> FDIV Control 5 Register (FDIV_CONTROL_5)
;//     <o5.24..31> CLK_SEL: Clock Source Selection
;//                     <0=> LP_OSC
;//                     <1=> Crystal Oscillator
;//                     <2=> PLL
;//                     <3=> PLL + 120°
;//                     <4=> PLL + 240°
;//     <o5.12..23>    LOAD: Load Value <0x0-0x3FF>
;//     <o5.0..11> DENOMINATOR: Denominator or Modulo Value <0x0-0x3FF>
;//   </h>
;//   <h> FDIV Control 6 Register (FDIV_CONTROL_6)
;//     <o6.24..31> CLK_SEL: Clock Source Selection
;//                     <0=> LP_OSC
;//                     <1=> Crystal Oscillator
;//                     <2=> PLL
;//                     <3=> PLL + 120°
;//                     <4=> PLL + 240°
;//     <o6.12..23>    LOAD: Load Value <0x0-0x3FF>
;//     <o6.0..11> DENOMINATOR: Denominator or Modulo Value <0x0-0x3FF>
;//   </h>
FDIV_CTRL0_Val  EQU     0x00001001
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


                PRESERVE8

; Area Definition and Entry Point
;  Startup Code must be linked first at Address at which it expects to run.

                AREA    RESET, CODE, READONLY
                ARM


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
SWI_Handler     B       SWI_Handler
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


; Setup Clock
                IF      CLOCK_SETUP != 0
                LDR     R0, =CGU_BASE

;  If crystal oscillator control requested is different then reset value
                IF      XTAL_OSC_CTRL_Val != 0x00000005
                LDR     R1, =XTAL_OSC_CTRL_Val
                STR     R1, [R0, #XTAL_CTRL_OFS]
                ENDIF

;  Use crystal oscillator instead of LP oscillator to speed up setup
                LDR     R1, =PLL_XTAL_SEL     ; Switch to XTAL
                STR     R1, [R0, #SYS_CLK_CO_OFS] 

;  If PLL is used
                IF      (PLL_CONTROL_Val:AND:PLL_PD) = 0
                LDR     R1, =(PLL_CONTROL_Val:OR:0x00000001)
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
