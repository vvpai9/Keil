;/*****************************************************************************/
;/* STARTUP.S: Startup file for OKI ML674000 device series                    */
;/*****************************************************************************/
;/* <<< Use Configuration Wizard in Context Menu >>>                          */ 
;/*****************************************************************************/
;/* This file is part of the uVision/ARM development tools.                   */
;/* Copyright (c) 2005-2006 Keil Software. All rights reserved.               */
;/* This software may only be used under the terms of a valid, current,       */
;/* end user licence from KEIL for a compatible version of KEIL software      */
;/* development tools. Nothing else gives you the right to use this software. */
;/*****************************************************************************/


;/*
; *  The STARTUP.S code is executed after CPU Reset. This file may be 
; *  translated with the following SET symbols. In uVision these SET 
; *  symbols are entered under Options - ASM - Define.
; *
; *  IRAM_MODE: when set the device is configured for code execution
; *  from on-chip RAM starting at address IRAM_BASE. The startup
; *  vectors are located to IRAM_BASE.
; *
; *  SRAM_MODE: when set the device is configured for code execution
; *  from off-chip SRAM starting at address SRAM_BASE. The startup
; *  vectors are located to SRAM_BASE.
; *
; *  DRAM_MODE: when set the device is configured for code execution
; *  from off-chip DRAM starting at address DRAM_BASE. The startup
; *  vectors are located to DRAM_BASE.
; *
; *  REMAP: when set the startup code remaps exception vectors from
; *  RAM (selected by xRAM_MODE) to address 0.
; *
; *  RAM_INTVEC: when set the startup code copies exception vectors 
; *  from Boot ROM to RAM (selected by xRAM_MODE).
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


; Memory Base Addresses
ROM_BASE        EQU     0xC8000000      ; Boot ROM
IRAM_BASE       EQU     0x10000000      ; On-chip RAM
SRAM_BASE       EQU     0xD0000000      ; Off-chip SRAM
DRAM_BASE       EQU     0xC0000000      ; Off-chip DRAM
                IF      :DEF:IRAM_MODE
RAM_BASE        EQU     IRAM_BASE
RAM_MAP         EQU     12
                ENDIF
                IF      :DEF:SRAM_MODE
RAM_BASE        EQU     SRAM_BASE
RAM_MAP         EQU     8
                ENDIF
                IF      :DEF:DRAM_MODE
RAM_BASE        EQU     DRAM_BASE
RAM_MAP         EQU     9
                ENDIF
CCR_BASE        EQU     0xB7000000      ; Chip Configuration Base
SCR_BASE        EQU     0xB8000000      ; System Control Base
EMCR_BASE       EQU     0x78100000      ; External Memory Control Base
DCR_BASE        EQU     0x78180000      ; DRAM Control Base


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



; Power Management definitions
CCR_BCKCTL      EQU     0x04            ; Block Clock Control Register
SCR_CGBCNT0     EQU     0x08            ; Clock Select Register

;// <e> Power Management
;//   <h> Block Clock Control
;//     <o1.0>  A/D Converter Clock    <0=> Enabled  <1=> Disabled
;//     <o1.1>  PWM Block Clock        <0=> Enabled  <1=> Disabled
;//     <o1.2>  Timer 0 Clock          <0=> Enabled  <1=> Disabled
;//     <o1.3>  Timer 1 Clock          <0=> Enabled  <1=> Disabled
;//     <o1.4>  Timer 2 Clock          <0=> Enabled  <1=> Disabled
;//     <o1.5>  Timer 3 Clock          <0=> Enabled  <1=> Disabled
;//     <o1.6>  Timer 4 Clock          <0=> Enabled  <1=> Disabled
;//     <o1.7>  Timer 5 Clock          <0=> Enabled  <1=> Disabled
;//     <o1.8>  DRAM Controller Clock  <0=> Enabled  <1=> Disabled
;//     <o1.9>  DMA Controller Clock   <0=> Enabled  <1=> Disabled
;//     <o1.10> UART Clock             <0=> Enabled  <1=> Disabled
;//     <o1.11> SSIO Clock             <0=> Enabled  <1=> Disabled
;//     <o1.12> I2C Clock              <0=> Enabled  <1=> Disabled
;//   </h>
;//   <h> Clock Gear Control
;//     <o2.0..2> HCLKSEL: Select HCLK Divider
;//               <0=> 1  <1=> 2  <2=> 4  <3=> 8  <4=> 16
;//     <o2.4..6> CCLKSEL: Select CCLK Divider
;//               <0=> 1  <1=> 2  <2=> 4  <3=> 8  <4=> 16
;//   </h>
;// </e>
PM_SETUP        EQU     0
BCKCTL_Val      EQU     0x00000000
CGBCNT0_Val     EQU     0x00000000


; Port Functions definitions
CCR_GPCTL       EQU     0x00            ; Port Function Select Register

;// <e> Port Functions
;//   <o1.0>  GPCTL0: UART Interface         <0=> Disabled  <1=> Enabled
;//   <o1.1>  GPCTL1: Serial Interface       <0=> Disabled  <1=> Enabled
;//   <o1.2>  GPCTL2: Ext. Bus: XA19..23     <0=> Disabled  <1=> Enabled
;//   <o1.3>  GPCTL3: DMA Channel 0          <0=> Disabled  <1=> Enabled
;//   <o1.4>  GPCTL4: DMA Channel 1          <0=> Disabled  <1=> Enabled
;//   <o1.5>  GPCTL5: PWM Outputs            <0=> Disabled  <1=> Enabled
;//   <o1.6>  GPCTL6: WAIT Input             <0=> Disabled  <1=> Enabled
;//   <o1.7>  GPCTL7: Ext. Bus: XWR          <0=> Disabled  <1=> Enabled
;//   <o1.8>  GPCTL8: SSIO: SCLK,SDI,SDO     <0=> Disabled  <1=> Enabled
;//   <o1.9>  GPCTL9: SSIO: SDA,SCL          <0=> Disabled  <1=> Enabled
;//   <o1.10> GPCTL10: EXINT0 Input          <0=> Disabled  <1=> Enabled
;//   <o1.11> GPCTL11: EXINT1 Input          <0=> Disabled  <1=> Enabled
;//   <o1.12> GPCTL12: EXINT2 Input          <0=> Disabled  <1=> Enabled
;//   <o1.13> GPCTL13: EXINT3 Input          <0=> Disabled  <1=> Enabled
;//   <o1.14> GPCTL14: EFIQ_N Input          <0=> Disabled  <1=> Enabled
;// </e>
PF_SETUP        EQU     1
GPCTL_Val       EQU     0x00000004


; External Memory definitions
EMCR_BWC        EQU     0x00            ; Bus Width Control
EMCR_ROMAC      EQU     0x04            ; ROM Access Control
EMCR_RAMAC      EQU     0x08            ; SRAM Access Control
EMCR_IO01AC     EQU     0x0C            ; I/O Bank 0/1 Control
EMCR_IO23AC     EQU     0x10            ; I/O Bank 2/3 Control
DCR_DBWC        EQU     0x00            ; DRAM Bus Width Control
DCR_DRMC        EQU     0x04            ; DRAM Control
DCR_DRPC        EQU     0x08            ; DRAM Characteristics Control
DCR_SDMD        EQU     0x0C            ; SDRAM Mode Control
DCR_DCMD        EQU     0x10            ; DRAM Command
DCR_RFSH0       EQU     0x14            ; DRAM Refresh Cycle Control 0
DCR_RFSH1       EQU     0x1C            ; DRAM Refresh Cycle Control 1
DCR_PDWC        EQU     0x18            ; DRAM Power Down Control

; DRAM Command definitions
DCMD_NOP        EQU     0x00            ; No operation
DCMD_PALL       EQU     0x04            ; Pre-charge all banks Command
DCMD_REF        EQU     0x05            ; CBR Refresh Command
DCMD_SELF       EQU     0x06            ; Self Refresh Start Command
DCMD_SREX       EQU     0x07            ; Self Refresh Stop Command

;// <e.0> External Memory Controller
;//   <h> BWC: Bus Width Control
;//     <o1.2..3>  ROMBW: ROM Bus Width
;//       <0=> Not Present  <1=> Reserved  <2=> 16-bits  <3=> Reserved
;//     <o1.4..5>  RAMBW: SRAM Bus Width
;//       <0=> Not Present  <1=> Reserved  <2=> 16-bits  <3=> Reserved
;//     <o1.6..7>  IO01BW: I/O Bank 0/1 Bus Width
;//       <0=> Not Present  <1=> 8-bits  <2=> 16-bits  <3=> Reserved
;//     <o1.7..8>  IO23BW: I/O Bank 2/3 Bus Width
;//       <0=> Not Present  <1=> 8-bits  <2=> 16-bits  <3=> Reserved
;//   </h>
;//   <h> ROMAC: ROM Access Control
;//     <o2.0..2>  ROMTYPE: ROM Timming (in cycles)
;//       <0=> OE/WE = 1, Read off = 0
;//       <1=> OE/WE = 2, Read off = 0
;//       <2=> OE/WE = 3, Read off = 2
;//       <3=> OE/WE = 4, Read off = 2
;//       <4=> Reserved
;//       <5=> Reserved
;//       <6=> Reserved
;//       <7=> OE/WE = 8, Read off = 4
;//     <o2.4>     ROMBRST: ROM Page Mode
;//   </h>
;//   <h> RAMAC: SRAM Access Control
;//     <o3.0..2>  RAMTYPE: SRAM Timming (in cycles)
;//       <0=> OE/WE = 1, Read off = 0
;//       <1=> OE/WE = 2, Read off = 0
;//       <2=> OE/WE = 3, Read off = 2
;//       <3=> OE/WE = 4, Read off = 2
;//       <4=> Reserved
;//       <5=> Reserved
;//       <6=> Reserved
;//       <7=> OE/WE = 8, Read off = 4
;//     <o3.4>     RAMBRST: SRAM Page Mode
;//   </h>
;//   <h> IO01AC: I/O Bank 0/1 Access Control
;//     <o4.0..2>  IO01TYPE: I/O Bank 0/1 Timming (in cycles)
;//       <0=> Address Setup = 1, OE/WE =  1, Read off = 1
;//       <1=> Address Setup = 1, OE/WE =  4, Read off = 2
;//       <2=> Reserved
;//       <3=> Address Setup = 2, OE/WE =  8, Read off = 4
;//       <4=> Address Setup = 2, OE/WE = 12, Read off = 6
;//       <5=> Address Setup = 2, OE/WE = 16, Read off = 7
;//       <6=> Reserved
;//       <7=> Address Setup = 4, OE/WE = 24, Read off = 10
;//   </h>
;//   <h> IO23AC: I/O Bank 2/3 Access Control
;//     <o5.0..2>  IO23TYPE: I/O Bank 2/3 Timming (in cycles)
;//       <0=> Address Setup = 1, OE/WE =  1, Read off = 1
;//       <1=> Address Setup = 1, OE/WE =  4, Read off = 2
;//       <2=> Reserved
;//       <3=> Address Setup = 2, OE/WE =  8, Read off = 4
;//       <4=> Address Setup = 2, OE/WE = 12, Read off = 6
;//       <5=> Address Setup = 2, OE/WE = 16, Read off = 7
;//       <6=> Reserved
;//       <7=> Address Setup = 4, OE/WE = 24, Read off = 10
;//   </h>
;//   <e.1> DRAM Controller
;//     <h> DBWC: DRAM Bus Width Control
;//       <o6.0..1>  BWDRAM: DRAM Bus Width
;//         <0=> Not Present  <1=> 8-bits  <2=> 16-bits  <3=> Reserved
;//     </h>
;//     <h> DRMC: DRAM Control
;//       <o7.0..1>  AMUX: Column Length
;//         <0=> 8-bits  <1=> 9-bits  <2=> 10-bits  <3=> Reserved
;//       <o7.2>     ARCH: DRAM Type
;//         <0=> SDRAM  <1=> EDO-DRAM
;//       <o7.4>     PRELAT: SDRAM Pre-charge latency
;//         <0=> 2 cycles  <1=> CAS latency
;//       <o7.6>     PDWN: SDRAM Power Down Mode
;//         <0=> Disable automatic shift  <1=> Enable automatic shift
;//       <o7.7>     RFRSH: CBR - CAS before RAS Refresh
;//         <0=> Stop distributed CBR  <1=> Enable distributed CBR
;//     </h>
;//     <h> DRPC: DRAM Characteristics Control
;//       <o8.0..3>  DRAMSPEC: DRAM Timming (in cycles)
;//         <0=>  SDRAM:RCD=1,RAS=2,RP=1,DPL=1; EDO-DRAM:RAH/CAS=1,RCD=2,CAC/OEZ=1,RP=1
;//         <1=>  SDRAM:RCD=1,RAS=3,RP=1,DPL=1; EDO-DRAM:RAH/CAS=1,RCD=2,CAC/OEZ=1,RP=2
;//         <2=>  SDRAM:RCD=2,RAS=3,RP=2,DPL=1; EDO-DRAM:RAH/CAS=1,RCD=3,CAC/OEZ=1,RP=2
;//         <3=>  SDRAM:RCD=2,RAS=4,RP=2,DPL=1; EDO-DRAM:RAH/CAS=1,RCD=3,CAC/OEZ=1,RP=3
;//         <4=>  SDRAM:RCD=2,RAS=4,RP=2,DPL=2; EDO-DRAM:RAH/CAS=1,RCD=3,CAC/OEZ=2,RP=3
;//         <5=>  SDRAM:RCD=2,RAS=5,RP=2,DPL=1; EDO-DRAM:RAH/CAS=1,RCD=4,CAC/OEZ=2,RP=4
;//         <6=>  SDRAM:RCD=2,RAS=5,RP=2,DPL=2; EDO-DRAM:RAH/CAS=1,RCD=5,CAC/OEZ=2,RP=5
;//         <7=>  SDRAM:RCD=2,RAS=5,RP=3,DPL=1; EDO-DRAM:RAH/CAS=2,RCD=4,CAC/OEZ=2,RP=4
;//         <8=>  SDRAM:RCD=3,RAS=5,RP=3,DPL=2; EDO-DRAM:RAH/CAS=2,RCD=5,CAC/OEZ=2,RP=5
;//         <9=>  SDRAM:RCD=3,RAS=6,RP=3,DPL=2; EDO-DRAM:RAH/CAS=2,RCD=6,CAC/OEZ=2,RP=6
;//         <10=> SDRAM:Reserved; EDO-DRAM:RAH/CAS=3,RCD=8,CAC/OEZ=3,RP=7
;//         <11=> Reserved <12=> Reserved <13=> Reserved <14=> Reserved <15=> Reserved
;//     </h>
;//     <h> SDMD: SDRAM Mode
;//       <o9.0>  LTMODE: SDRAM CAS Latency
;//         <0=> 2 cycles  <1=> 3 cycles
;//     </h>
;//     <h> RFSH0: DRAM Refresh Cycle Control 0
;//       <o10.0>  RCCON: DRAM Refresh Period
;//         <0=> Double RSFH1 Period  <1=> Single RFSH1 Period
;//     </h>
;//     <h> RFSH1: DRAM Refresh Cycle Control 1
;//       <o11.0..10>  RFSEL1: DRAM Refresh Period Divider <8-2047>
;//         <i> Refresh Period = CCLK / RFSEL1
;//     </h>
;//     <h> PDWC: DRAM Power Down Control
;//       <o12.0..3>  PDCNT: DRAM Idle Cycles before Power Down
;//         <0=>  1 or more cycles   <1=>   2 or more cycles
;//         <2=>  3 or more cycles   <3=>   4 or more cycles
;//         <4=>  5 or more cycles   <5=>   6 or more cycles
;//         <6=>  7 or more cycles   <7=>   8 or more cycles
;//         <8=>  9 or more cycles   <9=>  10 or more cycles
;//         <10=> 11 or more cycles  <11=> 12 or more cycles
;//         <12=> 13 or more cycles  <13=> 14 or more cycles
;//         <14=> 15 or more cycles  <15=> 16 or more cycles
;//     </h>
;//   </e>
;// </e>
EMC_SETUP       EQU     3
BWC_Val         EQU     0x00000028
ROMAC_Val       EQU     0x00000007
RAMAC_Val       EQU     0x00000007
IO01AC_Val      EQU     0x00000007
IO23AC_Val      EQU     0x00000007
DBWC_Val        EQU     0x00000002
DRMC_Val        EQU     0x00000080
DRPC_Val        EQU     0x00000009
SDMD_Val        EQU     0x00000080
RFSH0_Val       EQU     0x00000001
RFSH1_Val       EQU     0x00000202
PDWC_Val        EQU     0x0000000F


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
                NOP                            ; Reserved Vector 
                LDR     PC,IRQ_Addr
                LDR     PC,FIQ_Addr

                IMPORT  IRQ_Handler

Reset_Addr      DCD     Reset_Handler
Undef_Addr      DCD     Undef_Handler
SWI_Addr        DCD     SWI_Handler
PAbt_Addr       DCD     PAbt_Handler
DAbt_Addr       DCD     DAbt_Handler
                DCD     0                      ; Reserved Address 
IRQ_Addr        DCD     IRQ_Handler
FIQ_Addr        DCD     FIQ_Handler

Undef_Handler   B       Undef_Handler
SWI_Handler     B       SWI_Handler
PAbt_Handler    B       PAbt_Handler
DAbt_Handler    B       DAbt_Handler
;IRQ_Handler    B       IRQ_Handler
FIQ_Handler     B       FIQ_Handler


; Reset Handler

                EXPORT  Reset_Handler
Reset_Handler   


; Setup Power Management
                IF      PM_SETUP <> 0
                LDR     R0, =CCR_BASE
                LDR     R1, =BCKCTL_Val
                STR     R1, [R0, #CCR_BCKCTL]
                LDR     R0, =SCR_BASE
                LDR     R1, =CGBCNT0_Val
                STR     R1, [R0, #SCR_CGBCNT0]
                ENDIF


; Setup Port Functions
                IF      PF_SETUP <> 0
                LDR     R0, =CCR_BASE
                LDR     R1, =GPCTL_Val
                STR     R1, [R0, #CCR_GPCTL]
                ENDIF


; Setup External Memory Controller
                IF      (EMC_SETUP:AND:1) <> 0

                LDR     R0, =EMCR_BASE
                LDR     R1, =BWC_Val
                STR     R1, [R0, #EMCR_BWC]
                LDR     R1, =ROMAC_Val
                STR     R1, [R0, #EMCR_ROMAC]
                LDR     R1, =RAMAC_Val
                STR     R1, [R0, #EMCR_RAMAC]
                LDR     R1, =IO01AC_Val
                STR     R1, [R0, #EMCR_IO01AC]
                LDR     R1, =IO23AC_Val
                STR     R1, [R0, #EMCR_IO23AC]

; Setup DRAM Controller
                IF      (EMC_SETUP:AND:2) <> 0

                LDR     R0, =(12000/4)  ; Wait at least 200us after Power-On
DRAM_Wait       SUBS    R0, R0, #1      ;  which is required for DRAM
                BNE     DRAM_Wait       ;  12000 cycles @ HCLK = 60MHz
                LDR     R0, =DCR_BASE
                LDR     R1, =RFSH0_Val
                STR     R1, [R0, #DCR_RFSH0]
                LDR     R1, =RFSH1_Val
                STR     R1, [R0, #DCR_RFSH1]
                LDR     R1, =DBWC_Val
                STR     R1, [R0, #DCR_DBWC]
                LDR     R1, =DRMC_Val
                STR     R1, [R0, #DCR_DRMC]
                LDR     R1, =DRPC_Val
                STR     R1, [R0, #DCR_DRPC]
                LDR     R1, =SDMD_Val
                STR     R1, [R0, #DCR_SDMD]
                LDR     R1, =PDWC_Val
                STR     R1, [R0, #DCR_PDWC]
                MOV     R1, #DCMD_PALL
                STR     R1, [R0, #DCR_DCMD]
                MOV     R1, #DCMD_REF
                MOV     R2, #8
DRAM_Loop       STR     R1, [R0, #DCR_DCMD]
                SUBS    R2, R2, #1
                BNE     DRAM_Loop

                ENDIF

                ENDIF


; Copy Exception Vectors to Internal RAM

                IF      :DEF:RAM_INTVEC
                ADR     R8, Vectors     ; Source
                LDR     R9, =RAM_BASE   ; Destination
                LDMIA   R8!, {R0-R7}    ; Load Vectors 
                STMIA   R9!, {R0-R7}    ; Store Vectors 
                LDMIA   R8!, {R0-R7}    ; Load Handler Addresses 
                STMIA   R9!, {R0-R7}    ; Store Handler Addresses
                ENDIF


; Remap on-chip RAM to address 0

SCR_RMPCON      EQU     0x10            ; Remap Control Register

                IF      :DEF:REMAP
                LDR     R0, =SCR_BASE
                MOV     R1, #0x3C       ; Protection Code
                MOV     R2, #RAM_MAP    ; RAM Mapping
                STR     R1, [R0, #SCR_RMPCON]
                STR     R2, [R0, #SCR_RMPCON]
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
