;/*****************************************************************************/
;/* S3F4A.S: Startup file for Samsung S3F4A device series                     */
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


;----------------------- Interleave Program Flash Memory Controller Definitions 

IFC_BASE        EQU     0xFFE04000      ; IFC                      Base Address
IFC_PMSR_OFS    EQU     0x58            ; Power Management Status Reg    Offset
IFC_CR_OFS      EQU     0x60            ; Controller Register            Offset
IFC_MR_OFS      EQU     0x64            ; Mode Register                  Offset
IFC_CSR_OFS     EQU     0x6C            ; Clear Status Register          Offset
IFC_SR_OFS      EQU     0x70            ; Status Register                Offset
IFC_IER_OFS     EQU     0x74            ; Interrupt Enable Register      Offset
IFC_IDR_OFS     EQU     0x78            ; Interrupt Disable Register     Offset
IFC_IMR_OFS     EQU     0x7C            ; Interrupt Mask Register        Offset

;// <e> Flash Setup
;//   <h> IFC Mode Register (IFC_MR)
;//     <o1.24..31>  BA: Interleave Flash Controller Base Address
;//     <o1.7>       WPR: Write and Erase Protection Enable
;//     <o1.4>       STANDEN: Standby Mode Enable
;//     <o1.2>       SPEEDMODE: High Speed Mode Enable
;//       <i> Must be enabled for system clock frequency higher than 20 MHz
;//   </h>
;// </e> Flash Setup
IFC_SETUP       EQU     1
IFC_MR_Val      EQU     0x0000AC04


;----------------------- Internal RAM Controller Definitions ------------------ 

IRC_BASE        EQU     0xFFFF0000      ; IRC                      Base Address
IRC_MR_OFS      EQU     0x00            ; Mode Register                  Offset

;// <e> RAM Setup
;//   <h> IRC Mode Register (IRC_MR)
;//     <o1.20..31>  BA: Internal SRAM Base Address
;//   </h>
;// </e> Flash Setup
IRC_SETUP       EQU     0
IRC_MR_Val      EQU     0x00300000


;----------------------- Clock Manager Definitions -----------------------------

CM_BASE         EQU     0xFFFE8000      ; Clock Manager            Base Address
CM_STR_OFS      EQU     0x00            ; Osc and PLL Status Register    Offset
CM_WFIR_OFS     EQU     0x08            ; Master Clock w f Interrupt Reg Offset
CM_PSTR_OFS     EQU     0x0C            ; PLL Stabilization Time Reg     Offset
CM_PDPR_OFS     EQU     0x10            ; PLL Divider Parameters Reg     Offset
CM_OSTR_OFS     EQU     0x14            ; Master Osc Stabilization Time  Offset
CM_DIVBR_OFS    EQU     0x1C            ; Main Clock Divider Register    Offset
CM_SELR_OFS     EQU     0x20            ; System Clock Selection Reg     Offset
CM_RSR_OFS      EQU     0x24            ; Reset Status Register          Offset
CM_MDIVR_OFS    EQU     0x28            ; Master Osc Clock Divider Reg   Offset
CM_LFOSCR_OFS   EQU     0x2C            ; Low Frequency Osc Control Reg  Offset
CM_CR_OFS       EQU     0x30            ; Control Register               Offset
CM_MR_OFS       EQU     0x64            ; Mode Register                  Offset
CM_CSR_OFS      EQU     0x6C            ; Clear Status Register          Offset
CM_SR_OFS       EQU     0x70            ; Status Register                Offset
CM_IER_OFS      EQU     0x74            ; Interrupt Enable Register      Offset
CM_IDR_OFS      EQU     0x78            ; Interrupt Disable Register     Offset
CM_IMR_OFS      EQU     0x7C            ; Interrupt Mask Register        Offset

; Constants
CM_SELKEY_Val   EQU     (0xD0C9 << 16)  ; CM_SELR SELKEY Value
CM_SELR_Val_N   EQU     0               ; CM_SELR Normal Mode Value
CM_SELR_Val_HS  EQU     1               ; CM_SELR High Speed Mode Value
CM_SELR_Val_S   EQU     2               ; CM_SELR Slow Mode Value
CM_SELR_Val_LP  EQU     3               ; CM_SELR Low Power Value

LFUSED_Val      EQU     (1 << 3)        ; CM_STR LFUSED Bit Value
LFOST_Val       EQU     (1 << 2)        ; CM_STR LFOST Bit Value
OSCST_Val       EQU     (1 << 1)        ; CM_STR OSCST Bit Value
PLLST_Val       EQU     (1 << 0)        ; CM_STR PLLST Bit Value


;// <e> Clock Setup
;//   <o1> Clock Mode
;//     <0=> High Speed
;//     <1=> Slow
;//     <2=> Low Power
;//   <h> Main Clock Divider Register (CM_DIVBR)
;//     <o2.0..2> PCLK1DIV: Peripheral Divider Value <1-8><#-1>
;//       <i> Division rate between CORECLK system clock and peripheral clock domain
;//   </h>
;//   <h> Master Oscillator Clock Divider Register (CM_MDIVR)
;//     <o3.0..8> MDIV: Master Clock Divider Value <1-511>
;//     <o3.10..12> CDIV: Core Clock Divider Value <1-8><#-1>
;//       <i> Division rate between PLLOUT or MCLK clock and CORECLK clock
;//     <o3.13..15> LDIV: Low Frequency Oscillator Clock Divider Value <1-8><#-1>
;//       <i> Division rate between RINGCLK or DIVOUT clock and LFDIV clock
;//   </h>
CLOCK_SETUP     EQU     1
CLOCK_MODE      EQU     0
CM_DIVBR_Val    EQU     0x00000003
CM_MDIVR_Val    EQU     0xACDC0000

;//     <h> PLL Divider Parameters Register (CM_PDPR)
;//       <i> Fout = (M * Fin) / (P * S)
;//       <i> PLL output frequency must be between 12 and 40 MHz
;//       <o0.0..7> M: Main Divider M Value <9-263><#-8>
;//         <i> M = PMUL[7:0] + 8
;//       <o0.8..9> S: Post Scalar S Value
;//         <i> S = 2 ^ PLL_POST[1:0]
;//         <0=> 1  <1=> 2  <2=> 4  <3=> 8
;//       <o0.10..15> P: Pre Divider P Value <2-65><#-2>
;//         <i> P = PLL_PRE[5:0] + 2
;//     </h>
;//     <h> PLL Stabilization Time Register (CM_PSTR)
;//       <i> PLL stabilization time = (PST[10:0] + 5) * MCLK period * 256
;//       <o1.0..10> PST: PLL Stabilization Time Register Value <0-2047>
;//     </h>
CM_PDPR_Val     EQU     0x7AB20534
CM_PSTR_Val     EQU     0x59C10000

;//     <h> Low Frequency Oscillator Control Register (CM_LFOSCR)
;//       <o0.8..15> Low Frequency Stabilization Time Value <0-255>
;//         <i> Low frequency stabilization time = (LF_ST[7:0] + 3) * MCLK period * 128
;//       <o0.1> LFSEL: Low Frequency Clock Selection
;//         <0=> Master clock divided by MDIV + 1
;//         <1=> Low frequency oscillator clock
;//       <o0.0> LFOSCEN: Low Frequency Oscillator Enable
;//     </h>
CM_LFOSCR_Val   EQU     0xA34C0003

;//     <h> Oscillator Stabilization Time Register (CM_OSTR)
;//       <o0.8..15> OST: Master Oscillator Stabilization Time Value <0-65535>
;//         <i> Master oscillator stabilization time = OST[15:0] * LFCLK period
;//     </h>
CM_OSTR_Val     EQU     0xFA4B2EE0

;// </e> Clock Setup


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
;               LDR     PC,IRQ_Addr
                LDR     PC,[PC,#-0xF20]         ; Vector From GIC_IVR
;               LDR     PC,FIQ_Addr
                LDR     PC,[PC,#-0xF20]         ; Vector From GIC_FVR

                IF      :DEF:__RTX
                IMPORT  SWI_Handler
                IMPORT  IRQ_Handler_RTX
                ENDIF

Reset_Addr      DCD     Reset_Handler
Undef_Addr      DCD     Undef_Handler
SWI_Addr        DCD     SWI_Handler
PAbt_Addr       DCD     PAbt_Handler
DAbt_Addr       DCD     DAbt_Handler
                DCD     0                       ; Reserved Address 
                IF      :DEF:__RTX
IRQ_Addr        DCD     IRQ_Handler_RTX
                ELSE
IRQ_Addr        DCD     IRQ_Handler
                ENDIF
FIQ_Addr        DCD     FIQ_Handler

Undef_Handler   B       Undef_Handler
                IF      :DEF:__RTX
                ELSE
SWI_Handler     B       SWI_Handler
                ENDIF
PAbt_Handler    B       PAbt_Handler
DAbt_Handler    B       DAbt_Handler
IRQ_Handler     PROC
                EXPORT  IRQ_Handler             [WEAK]
                B       .
                ENDP
FIQ_Handler     B       FIQ_Handler


; Reset Handler

                EXPORT  Reset_Handler
Reset_Handler   


; Ensure Debugger Connection ---------------------------------------------------

                MOV     R0, #0x200000           ; Wait aprox. 2 seconds
Wait_Dbg        SUBS    R0, R0, #1
                BNE     Wait_Dbg


; Flash Setup ------------------------------------------------------------------

                IF      IFC_SETUP != 0
                LDR     R0, =IFC_BASE
                LDR     R1, =IFC_MR_Val
                STR     R1, [R0, #IFC_MR_OFS]
                ENDIF


; RAM Setup --------------------------------------------------------------------

                IF      IRC_SETUP != 0
                LDR     R12, =Remap_Addr        ; Remember address after remap

                LDR     R0, =IRC_BASE
                LDR     R1, =IRC_MR_Val
                STR     R1, [R0, #IRC_MR_OFS]

                BX      R12

Remap_Addr
                ENDIF
                

; Clock Setup ------------------------------------------------------------------
                
                IF      CLOCK_SETUP != 0

                LDR     R0,      =CM_BASE
                LDR     R1,      =CM_DIVBR_Val  ; Set dividers
                STR     R1, [R0, #CM_DIVBR_OFS]
                LDR     R1,      =CM_MDIVR_Val
                STR     R1, [R0, #CM_MDIVR_OFS]

                IF      CLOCK_MODE  == 0        ; If High Speed Clock Used
                LDR     R1,      =CM_PDPR_Val
                STR     R1, [R0, #CM_PDPR_OFS]
                LDR     R1,      =CM_PSTR_Val
                STR     R1, [R0, #CM_PSTR_OFS]
                LDR     R1,      =(CM_SELKEY_Val:OR:CM_SELR_Val_HS)
                STR     R1, [R0, #CM_SELR_OFS]
Stabil_Clk      LDR     R2, [R0, #CM_STR_OFS]   ;  Wait until PLL is stabilized
                ANDS    R2, R2,  #PLLST_Val
                BEQ     Stabil_Clk

                ELIF    CLOCK_MODE  == 1        ; If Slow Clock Used
                LDR     R1,      =CM_LFOSCR_Val
                STR     R1, [R0, #CM_LFOSCR_OFS]
                LDR     R1,      =(CM_SELKEY_Val:OR:CM_SELR_Val_S)
                STR     R1, [R0, #CM_SELR_OFS]
Stabil_Clk      LDR     R2, [R0, #CM_STR_OFS]   ;  Wait until PLL is stabilized
                ANDS    R2, R2,  #LFOST_Val
                BEQ     Stabil_Clk

                ELIF    CLOCK_MODE  == 2        ; If Low Power Clock Used
                LDR     R1,      =CM_OSTR_Val
                STR     R1, [R0, #CM_OSTR_OFS]
                LDR     R1,      =CM_LFOSCR_Val
                STR     R1, [R0, #CM_LFOSCR_OFS]
                LDR     R1,      =(CM_SELKEY_Val:OR:CM_SELR_Val_LP)
                STR     R1, [R0, #CM_SELR_OFS]
Stabil_Clk      LDR     R2, [R0, #CM_STR_OFS]   ;  Wait until PLL is stabilized
                ANDS    R2, R2,  #OSCST_Val
                BEQ     Stabil_Clk
                ENDIF

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
