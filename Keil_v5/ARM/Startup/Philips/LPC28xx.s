;/*****************************************************************************/
;/* LPC28xx.S: Startup file for Philips LPC28xx device series                 */
;/*****************************************************************************/
;/* <<< Use Configuration Wizard in Context Menu >>>                          */ 
;/*****************************************************************************/
;/* This file is part of the uVision/ARM development tools.                   */
;/* Copyright (c) 2005-2007 Keil Software. All rights reserved.               */
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


;----------------------- Memory Definitions ------------------------------------

; Internal Memory Base Addresses
IRAM_BASE       EQU     0x00400000
IROM_BASE       EQU     0x00200000
IFLASH_BASE     EQU     0x10400000

; External Memory Base Addresses
SMC0_BASE       EQU     0x20000000      ; Static  Memory Bank 0
SMC1_BASE       EQU     0x24000000      ; Static  Memory Bank 1
SMC2_BASE       EQU     0x28000000      ; Static  Memory Bank 2
DYN0_BASE       EQU     0x30000000      ; Dynamic Memory Bank 0


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
SVC_Stack_Size  EQU     0x00000020
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


;----------------------- System Control Definitions ----------------------------

; System Control User Interface
SYSTEM_BASE     EQU     0x80005000      ; System Control          Base Address
SYS_BOOTMAP_OFS EQU     0x70            ; Boot Map Control
SYS_BOOTADDR_OFS EQU    0x74            ; Boot Address Control
SYS_PARTID_OFS  EQU     0x7C            ; Part Identification


;----------------------- Clock Definitions -------------------------------------

; Clock User Interface
CGU_BASE         EQU    0x80004C00      ; Clock Generation Unit   Base Address
                                        ; Low Power PLL
LPFIN_OFS        EQU    0xE4            ; Input Select
LPPDN_OFS        EQU    0xE8            ; Power Down
LPMBYP_OFS       EQU    0xEC            ; Multiplier Bypass
LPLOCK_OFS       EQU    0xF0            ; Lock Status
LPDBYP_OFS       EQU    0xF4            ; Divisor Bypass
LPMSEL_OFS       EQU    0xF8            ; Multiplication Factor
LPPSEL_OFS       EQU    0xFC            ; Division Factor
                                        ; High Speed PLL
HPFIN_OFS        EQU    0xAC            ; Input Select
HPNDEC_OFS       EQU    0xB4            ; Initial Divider Control
HPMDEC_OFS       EQU    0xB0            ; Multiplier Control
HPPDEC_OFS       EQU    0xB8            ; Final Divider Control
HPMODE_OFS       EQU    0xBC            ; Mode
HPSTAT_OFS       EQU    0xC0            ; Status
HPREQ_OFS        EQU    0xC8            ; Rate Change Request
HPACK_OFS        EQU    0xC4            ; Rate Change Acknowledge
HPSELR_OFS       EQU    0xD8            ; R Bandwidth
HPSELI_OFS       EQU    0xDC            ; I Bandwidth
HPSELP_OFS       EQU    0xE0            ; P Bandwidth

CGUSWBOX_BASE    EQU    0x80004000      ; Clk Gen Unit Switchbox  Base Address
SYSSCR_OFS       EQU    0x00
APB0SCR_OFS      EQU    0x04
APB1SCR_OFS      EQU    0x08
APB3SCR_OFS      EQU    0x0C
DCDCSCR_OFS      EQU    0x10
RTCSCR_OFS       EQU    0x14
MCISCR_OFS       EQU    0x18
UARTSCR_OFS      EQU    0x1C
DAIOSCR_OFS      EQU    0x20
DAISCR_OFS       EQU    0x24
SYSFSR2_OFS      EQU    0x58            
APB0FSR2_OFS     EQU    0x5C
APB1FSR2_OFS     EQU    0x60
APB3FSR2_OFS     EQU    0x64
DCDCFSR2_OFS     EQU    0x68
RTCFSR2_OFS      EQU    0x6C
MCIFSR2_OFS      EQU    0x70
UARTFSR2_OFS     EQU    0x74
DAIOFSR2_OFS     EQU    0x78
DAIFSR2_OFS      EQU    0x7C


; Constants
HPMODE_FR        EQU    (1<<5)          ; High Speed PLL Free run mode selection bit

LPLOCK_ON        EQU    1               ; Low Power PLL lock bit
HPLOCK_ON        EQU    1               ; High Speed PLL lock bit
FREERUN_ON       EQU    (1<<1)          ; Free Running active bit

;// <e> Clock Configuration
CLOCK_SETUP      EQU    0

;//   <e> Use Low Power PLL
;//     <o1.0..2> LPFIN: Input Select Register
;//                     <0=> 32 kHz oscillator
;//                     <1=> Fast (12 MHz) oscillator
;//                     <2=> MCLKI pin
;//                     <3=> BCKI pin
;//                     <4=> WSI pin
;//                     <7=> High Speed PLL
;//     <o2.0> LPMBYP: Multiplier Bypass Register
;//     <o3.0> LPDBYP: Divisor Bypass Register
;//     <o4.0..4> LPMSEL: Multiplication Factor <0-15>
;//       <i> If LPMBYP = 0 then calculate LPMSEL to get desired Fclkout
;//       <i> by using following formula Fclkout = Fclkin * (LPMSEL + 1)
;//     <o5.0..4> LPPSEL: Division Factor <0-15>
;//       <i> If LPDBYP = 0 then calculate LPPSEL to satisfy following 
;//       <i> condition 160 MHz <= Fclkout * 2^(LPPSEL+1) <= 320 MHz
;//   </e>
LPPLL_SETUP      EQU    1
LPFIN_Val        EQU    0x00000001
LPMBYP_Val       EQU    0x00000000
LPDBYP_Val       EQU    0x00000000
LPMSEL_Val       EQU    0x00000004
LPPSEL_Val       EQU    0x00000001

;//   <h> Selection Stage Setting
;//     <h> Frequency Select 2 Registers
;//       <o0.0..3> SYSFSR2: Side 2 SYS Clock Selection
;//                     <0=> 32 kHz oscillator <1=> Fast oscillator <2=> MCI Clock pin
;//                     <3=> DAI BCLK pin      <4=> DAI WS pin      <7=> High Speed PLL
;//                     <8=> Main PLL
;//       <o1.0..3> APB0FSR2: Side 2 APB0 Clock Selection
;//                     <0=> 32 kHz oscillator <1=> Fast oscillator <2=> MCI Clock pin
;//                     <3=> DAI BCLK pin      <4=> DAI WS pin      <7=> High Speed PLL
;//                     <8=> Main PLL
;//       <o2.0..3> APB1FSR2: Side 2 APB1 Clock Selection
;//                     <0=> 32 kHz oscillator <1=> Fast oscillator <2=> MCI Clock pin
;//                     <3=> DAI BCLK pin      <4=> DAI WS pin      <7=> High Speed PLL
;//                     <8=> Main PLL
;//       <o3.0..3> APB3FSR2: Side 2 APB3 Clock Selection
;//                     <0=> 32 kHz oscillator <1=> Fast oscillator <2=> MCI Clock pin
;//                     <3=> DAI BCLK pin      <4=> DAI WS pin      <7=> High Speed PLL
;//                     <8=> Main PLL
;//       <o4.0..3> DCDCFSR2: Side 2 DCDC Clock Selection
;//                     <0=> 32 kHz oscillator <1=> Fast oscillator <2=> MCI Clock pin
;//                     <3=> DAI BCLK pin      <4=> DAI WS pin      <7=> High Speed PLL
;//                     <8=> Main PLL
;//       <o5.0..3> RTCFSR2: Side 2 RTC Clock Selection
;//                     <0=> 32 kHz oscillator <1=> Fast oscillator <2=> MCI Clock pin
;//                     <3=> DAI BCLK pin      <4=> DAI WS pin      <7=> High Speed PLL
;//                     <8=> Main PLL
;//       <o6.0..3> MCIFSR2: Side 2 MCI Clock Selection
;//                     <0=> 32 kHz oscillator <1=> Fast oscillator <2=> MCI Clock pin
;//                     <3=> DAI BCLK pin      <4=> DAI WS pin      <7=> High Speed PLL
;//                     <8=> Main PLL
;//       <o7.0..3> UARTFSR2: Side 2 UART Clock Selection
;//                     <0=> 32 kHz oscillator <1=> Fast oscillator <2=> MCI Clock pin
;//                     <3=> DAI BCLK pin      <4=> DAI WS pin      <7=> High Speed PLL
;//                     <8=> Main PLL
;//       <o8.0..3> DAIOFSR2: Side 2 DAIO Clock Selection
;//                     <0=> 32 kHz oscillator <1=> Fast oscillator <2=> MCI Clock pin
;//                     <3=> DAI BCLK pin      <4=> DAI WS pin      <7=> High Speed PLL
;//                     <8=> Main PLL
;//       <o9.0..3> DAIFSR2: Side 2 DAI Clock Selection
;//                     <0=> 32 kHz oscillator <1=> Fast oscillator <2=> MCI Clock pin
;//                     <3=> DAI BCLK pin      <4=> DAI WS pin      <7=> High Speed PLL
;//                     <8=> Main PLL
;//     </h>
;//   </h>
SYSFSR2_Val      EQU    0x00000008
APB0FSR2_Val     EQU    0x00000001
APB1FSR2_Val     EQU    0x00000001
APB3FSR2_Val     EQU    0x00000001
DCDCFSR2_Val     EQU    0x00000001
RTCFSR2_Val      EQU    0x00000001
MCIFSR2_Val      EQU    0x00000001
UARTFSR2_Val     EQU    0x00000001
DAIOFSR2_Val     EQU    0x00000001
DAIFSR2_Val      EQU    0x00000001

;// </e> Clock Configuration


;----------------------- CODE --------------------------------------------------

                PRESERVE8
                
; - Flash Marker ---------------------------------------------------------------

; Area Definition for Flash User Program Valid Marker
                
                IF      :DEF:NO_FLASHMARKER
                ELSE

                AREA    |.ARM.__AT_0x104FF800|, CODE, READONLY
                ARM

                DCD     0xAA55AA55

                ENDIF


; - Starup Code ----------------------------------------------------------------

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
                DCD     0               ; Reserved Address
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


; Clock Setup ------------------------------------------------------------------

                IF      CLOCK_SETUP != 0
                LDR     R0, =CGU_BASE

                IF      LPPLL_SETUP != 0          ; If Low Power PLL is used
                MOV     R1, #1
                STR     R1, [R0, #LPPDN_OFS]
                MOV     R1, #LPFIN_Val
                STR     R1, [R0, #LPFIN_OFS]
                MOV     R1, #LPMSEL_Val
                STR     R1, [R0, #LPMSEL_OFS]
                MOV     R1, #LPPSEL_Val
                STR     R1, [R0, #LPPSEL_OFS]
                MOV     R1, #LPMBYP_Val
                STR     R1, [R0, #LPMBYP_OFS]
                MOV     R1, #LPDBYP_Val
                STR     R1, [R0, #LPDBYP_OFS]
                MOV     R1, #0
                STR     R1, [R0, #LPPDN_OFS]
LPPLL_Loop      LDR     R1, [R0, #LPLOCK_OFS]     ; Wait for lock
                ANDS    R1, R1, #LPLOCK_ON
                BEQ     LPPLL_Loop
                ENDIF

                ; Switch to selected clocks
                LDR     R0, =CGUSWBOX_BASE
                MOV     R1, #SYSFSR2_Val
                STR     R1, [R0, #SYSFSR2_OFS]
                MOV     R1, #APB0FSR2_Val
                STR     R1, [R0, #APB0FSR2_OFS]
                MOV     R1, #APB1FSR2_Val
                STR     R1, [R0, #APB1FSR2_OFS]
                MOV     R1, #APB3FSR2_Val
                STR     R1, [R0, #APB3FSR2_OFS]
                MOV     R1, #DCDCFSR2_Val
                STR     R1, [R0, #DCDCFSR2_OFS]
                MOV     R1, #RTCFSR2_Val
                STR     R1, [R0, #RTCFSR2_OFS]
                MOV     R1, #MCIFSR2_Val
                STR     R1, [R0, #MCIFSR2_OFS]
                MOV     R1, #UARTFSR2_Val
                STR     R1, [R0, #UARTFSR2_OFS]
                MOV     R1, #DAIOFSR2_Val
                STR     R1, [R0, #DAIOFSR2_OFS]
                MOV     R1, #DAIFSR2_Val
                STR     R1, [R0, #DAIFSR2_OFS]
                MOV     R1, #2
                STR     R1, [R0, #SYSSCR_OFS]
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
