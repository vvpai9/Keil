;/*****************************************************************************/
;/* TMS470R1B1M.S: Startup file for Texas Instruments TMS470R1B1M device      */
;/*****************************************************************************/
;/* <<< Use Configuration Wizard in Context Menu >>>                          */
;/*****************************************************************************/
;/* This file is part of the uVision/ARM development tools.                   */
;/* Copyright (c) 2005-2008 Keil Software. All rights reserved.               */
;/* This software may only be used under the terms of a valid, current,       */
;/* end user licence from KEIL for a compatible version of KEIL software      */
;/* development tools. Nothing else gives you the right to use this software. */
;/*****************************************************************************/


;/*
; *  The TMS470R1B1M.S code is executed after CPU Reset. This file may be 
; *  translated with the following SET symbols. In uVision these SET 
; *  symbols are entered under Options - ASM - Define.
; *
; *  NO_KEYS: when set then no protection keys are assembled (it is used for 
; *  RAM version because protection keys are not required for RAM version).
; *
; *  MEMORY_MAP: when set the startup code executes memory mapping.
; */


;----------------------- CONSTANTS DEFINITIONS ---------------------------------

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


; Stack definitions ------------------------------------------------------------

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


; Protection Keys Definitions --------------------------------------------------

;// <e0> Protect Device (!!! NEVER USE 0x00000000 FOR MEMORY SECURITY KEYS!!!)
;//   <i> IMPORTANT !!! - DO NOT PROGRAM 0x00000000 to MEMORY SECURITY KEYS 
;//   <i> BECAUSE DEVICE WILL NOT BE ACCESSIBLE ANY MORE !!!
;//   <e0.1> Are you sure you want to change the keys ?
;//     <o1.0..31> Memory Security Key 0 <0x0-0xFFFFFFFF>
;//     <o2.0..31> Memory Security Key 1 <0x0-0xFFFFFFFF>
;//     <o3.0..31> Memory Security Key 2 <0x0-0xFFFFFFFF>
;//     <o4.0..31> Memory Security Key 3 <0x0-0xFFFFFFFF>
;//     <o5.0..31> Flash Protection Key 0 <0x0-0xFFFFFFFF>
;//     <o6.0..31> Flash Protection Key 1 <0x0-0xFFFFFFFF>
;//     <o7.0..31> Flash Protection Key 2 <0x0-0xFFFFFFFF>
;//     <o8.0..31> Flash Protection Key 3 <0x0-0xFFFFFFFF>
;//   </e>
;// </e>
PROTECT_SETUP   EQU     0x00000000
MS_KEY0_Val     EQU     0xFFFFFFFF
MS_KEY1_Val     EQU     0xFFFFFFFF
MS_KEY2_Val     EQU     0xFFFFFFFF
MS_KEY3_Val     EQU     0xFFFFFFFF
FP_KEY0_Val     EQU     0xFFFFFFFF
FP_KEY1_Val     EQU     0xFFFFFFFF
FP_KEY2_Val     EQU     0xFFFFFFFF
FP_KEY3_Val     EQU     0xFFFFFFFF


; System Module (SM) definitions -----------------------------------------------

SM_BASE         EQU     0xFFFFFD00  ; System Module                 Base Address
SM_SMCR0_OFS    EQU     0x00        ; Static Memory Control Register 0    Offset
SM_SMCR1_OFS    EQU     0x04        ; Static Memory Control Register 1    Offset
SM_WCR0_OFS     EQU     0x2C        ; Write Control Register              Offset
SM_PCR_OFS      EQU     0x30        ; Peripheral Clock Register           Offset
SM_MFBAHR0_OFS  EQU     0x100       ; Memory Fine Base Address High Reg 0 Offset
SM_MFBALR0_OFS  EQU     0x104       ; Memory Fine Base Address Low  Reg 0 Offset
SM_MFBAHR1_OFS  EQU     0x108       ; Memory Fine Base Address High Reg 1 Offset
SM_MFBALR1_OFS  EQU     0x10C       ; Memory Fine Base Address Low  Reg 1 Offset
SM_MFBAHR2_OFS  EQU     0x110       ; Memory Fine Base Address High Reg 2 Offset
SM_MFBALR2_OFS  EQU     0x114       ; Memory Fine Base Address Low  Reg 2 Offset
SM_MFBAHR3_OFS  EQU     0x118       ; Memory Fine Base Address High Reg 3 Offset
SM_MFBALR3_OFS  EQU     0x11C       ; Memory Fine Base Address Low  Reg 3 Offset
SM_MFBAHR4_OFS  EQU     0x120       ; Memory Fine Base Address High Reg 4 Offset
SM_MFBALR4_OFS  EQU     0x124       ; Memory Fine Base Address Low  Reg 4 Offset
SM_MFBAHR5_OFS  EQU     0x128       ; Memory Fine Base Address High Reg 5 Offset
SM_MFBALR5_OFS  EQU     0x12C       ; Memory Fine Base Address Low  Reg 5 Offset
SM_GLBCTRL_OFS  EQU     0x2DC       ; Global Control Register             Offset
SM_SYSECR_OFS   EQU     0x2E0       ; System Exception Control Register   Offset

; Constants
SM_SYSECR_Val   EQU     0x00004007  ; No reset, no access violations
MFBALR0_MS_Val  EQU     0x00000100  ; Memory map enable


; Memory definitions -----------------------------------------------------------

;// <h> Memory Configuration
;//   <h> Memory Fine Base Address Register 0
;//     <o0.0..15> Memory Fine Base Address High Register 0 (MFBAHR0) <0x0-0xFFFF>
;//     <o1.10..15> Memory Fine Base Address Low Register 0 (MFBALR0) <0x0-0x3FF>
;//     <o1.4..7> Block Size
;//                 <0=> Memory Select is Disabled
;//                 <1=> 1K
;//                 <2=> 2K
;//                 <3=> 4K
;//                 <4=> 8K
;//                 <5=> 16K
;//                 <6=> 32K
;//                 <7=> 64K
;//                 <8=> 128K
;//                 <9=> 256K
;//                 <10=> 512K
;//                 <11=> 1M
;//                 <12=> 2M
;//                 <13=> 4M
;//                 <14=> 8M
;//                 <15=> 16M
;//     <e1.1> RONLY: Read-only Protection
;//     </e>
;//     <e1.0> PRIV: Privilege mode Protection
;//     </e>
;//   </h>
MFBAHR0_Val     EQU     0x00000000
MFBALR0_Val     EQU     0x000000B2

;//   <e0> Use Memory Fine Base Address Register 1
;//     <o1.0..15> Memory Fine Base Address High Register 1 (MFBAHR1) <0x0-0xFFFF>
;//     <o2.10..15> Memory Fine Base Address Low Register 1 (MFBALR1) <0x0-0x3FF>
;//     <e2.9> AW: Auto-wait on Write
;//     </e>
;//     <o2.4..7> Block Size
;//                 <0=> Memory Select is Disabled
;//                 <1=> 1K
;//                 <2=> 2K
;//                 <3=> 4K
;//                 <4=> 8K
;//                 <5=> 16K
;//                 <6=> 32K
;//                 <7=> 64K
;//                 <8=> 128K
;//                 <9=> 256K
;//                 <10=> 512K
;//                 <11=> 1M
;//                 <12=> 2M
;//                 <13=> 4M
;//                 <14=> 8M
;//                 <15=> 16M
;//     <e2.1> RONLY: Read-only Protection
;//     </e>
;//     <e2.0> PRIV: Privilege mode Protection
;//     </e>
;//   </e>
MFBA_R1_SETUP   EQU     0
MFBAHR1_Val     EQU     0x00000000
MFBALR1_Val     EQU     0x00000000

;//   <h> Memory Fine Base Address Register 2
;//     <o0.0..15> Memory Fine Base Address High Register 2 (MFBAHR2) <0x0-0xFFFF>
;//     <o1.10..15> Memory Fine Base Address Low Register 2 (MFBALR2) <0x0-0x3FF>
;//     <e1.9> AW: Auto-wait on Write
;//     </e>
;//     <o1.4..7> Block Size
;//                 <0=> Memory Select is Disabled
;//                 <1=> 1K
;//                 <2=> 2K
;//                 <3=> 4K
;//                 <4=> 8K
;//                 <5=> 16K
;//                 <6=> 32K
;//                 <7=> 64K
;//                 <8=> 128K
;//                 <9=> 256K
;//                 <10=> 512K
;//                 <11=> 1M
;//                 <12=> 2M
;//                 <13=> 4M
;//                 <14=> 8M
;//                 <15=> 16M
;//     <e1.1> RONLY: Read-only Protection
;//     </e>
;//     <e1.0> PRIV: Privilege mode Protection
;//     </e>
;//   </h>
MFBAHR2_Val     EQU     0x00002000
MFBALR2_Val     EQU     0x00000070

;//   <e0> Use Memory Fine Base Address Register 3
;//     <o1.0..15> Memory Fine Base Address High Register 3 (MFBAHR3) <0x0-0xFFFF>
;//     <o2.10..15> Memory Fine Base Address Low Register 3 (MFBALR3) <0x0-0x3FF>
;//     <e2.9> AW: Auto-wait on Write
;//     </e>
;//     <o2.4..7> Block Size
;//                 <0=> Memory Select is Disabled
;//                 <1=> 1K
;//                 <2=> 2K
;//                 <3=> 4K
;//                 <4=> 8K
;//                 <5=> 16K
;//                 <6=> 32K
;//                 <7=> 64K
;//                 <8=> 128K
;//                 <9=> 256K
;//                 <10=> 512K
;//                 <11=> 1M
;//                 <12=> 2M
;//                 <13=> 4M
;//                 <14=> 8M
;//                 <15=> 16M
;//     <e2.1> RONLY: Read-only Protection
;//     </e>
;//     <e2.0> PRIV: Privilege mode Protection
;//     </e>
;//   </e>
MFBA_R3_SETUP   EQU     0
MFBAHR3_Val     EQU     0x00000000
MFBALR3_Val     EQU     0x00000000

;//   <e> Use Memory Fine Base Address Register 4
;//     <o0.0..15> Memory Fine Base Address High Register 4 (MFBAHR4) <0x0-0xFFFF>
;//     <o1.10..15> Memory Fine Base Address Low Register 4 (MFBALR4) <0x0-0x3FF>
;//     <e1.9> AW: Auto-wait on Write
;//     </e>
;//     <o1.4..7> Block Size
;//                 <0=> Memory Select is Disabled
;//                 <1=> 1K
;//                 <2=> 2K
;//                 <3=> 4K
;//                 <4=> 8K
;//                 <5=> 16K
;//                 <6=> 32K
;//                 <7=> 64K
;//                 <8=> 128K
;//                 <9=> 256K
;//                 <10=> 512K
;//                 <11=> 1M
;//                 <12=> 2M
;//                 <13=> 4M
;//                 <14=> 8M
;//                 <15=> 16M
;//     <e1.1> RONLY: Read-only Protection
;//     </e>
;//     <e1.0> PRIV: Privilege mode Protection
;//     </e>
;//   </e>
MFBAHR4_Val     EQU     0x00004000
MFBALR4_Val     EQU     0x00000020

;//   <e0> Use Memory Fine Base Address Register 5
;//     <o1.0..15> Memory Fine Base Address High Register 5 (MFBAHR5) <0x0-0xFFFF>
;//     <o2.10..15> Memory Fine Base Address Low Register 5 (MFBALR5) <0x0-0x3FF>
;//     <e2.9> AW: Auto-wait on Write
;//     </e>
;//     <o2.4..7> Block Size
;//                 <0=> Memory Select is Disabled
;//                 <1=> 1K
;//                 <2=> 2K
;//                 <3=> 4K
;//                 <4=> 8K
;//                 <5=> 16K
;//                 <6=> 32K
;//                 <7=> 64K
;//                 <8=> 128K
;//                 <9=> 256K
;//                 <10=> 512K
;//                 <11=> 1M
;//                 <12=> 2M
;//                 <13=> 4M
;//                 <14=> 8M
;//                 <15=> 16M
;//     <e2.1> RONLY: Read-only Protection
;//     </e>
;//     <e2.0> PRIV: Privilege mode Protection
;//     </e>
;//   </e>
;//
MFBA_R5_SETUP   EQU     0
MFBAHR5_Val     EQU     0x00000000
MFBALR5_Val     EQU     0x00000000

;// </h> End of Memory Configuration


; Clock definitions ------------------------------------------------------------

; Constants
GLBCTRL_FC_Val  EQU     0x00000010

;// <e0> Clock Configuration
;//   <h> PLL Setup
;//     <i> fPLL = fOSC * M / R
;//     <o1.3> MULT4 (M): Multiply by 4
;//                   <0=> Multiply by 8
;//                   <1=> Multiply by 4
;//       <i> PLL multiply configuration
;//       <i> Default: Multiply by 4
;//     <o1.0..2> CLK DIV PRE (R): Clock Divider Prescale
;//                   <0=> Divide by 1
;//                   <1=> Divide by 2
;//                   <2=> Divide by 3
;//                   <3=> Divide by 4
;//                   <4=> Divide by 5
;//                   <5=> Divide by 6
;//                   <6=> Divide by 7
;//                   <7=> Divide by 8
;//       <i> Determines the divisor of the VCO output
;//       <i> Default: Divide by 8
;//   </h>
;//   <h> Peripheral Clock Setup
;//     <o2.1..4> CLKDIV: Peripheral Clock Divider Ratio
;//                   <0=> ICLK = SYSCLK
;//                   <1=> ICLK = SYSCLK / 2
;//                   <2=> ICLK = SYSCLK / 3
;//                   <3=> ICLK = SYSCLK / 4
;//                   <4=> ICLK = SYSCLK / 5
;//                   <5=> ICLK = SYSCLK / 6
;//                   <6=> ICLK = SYSCLK / 7
;//                   <7=> ICLK = SYSCLK / 8
;//                   <8=> ICLK = SYSCLK / 9
;//                   <9=> ICLK = SYSCLK / 10
;//                   <10=> ICLK = SYSCLK / 11
;//                   <11=> ICLK = SYSCLK / 12
;//                   <12=> ICLK = SYSCLK / 13
;//                   <13=> ICLK = SYSCLK / 14
;//                   <14=> ICLK = SYSCLK / 15
;//                   <15=> ICLK = SYSCLK / 16
;//       <i> Default: ICLK = SYSCLK / 16
;//     <e2.0> PENABLE: Peripheral Enable
;//       <i> Default: Disabled
;//     </e>
;//   </h>
;// </e>
CLOCK_SETUP     EQU     1
GLBCTRL_Val     EQU     0x00000000
PCR_Val         EQU     0x0000000F


; HET RAM definitions ----------------------------------------------------------

HET_BASE        EQU     0xFFF7FC00  ; HET Module                    Base Address
HET_GCR_OFS     EQU     0x00        ; Global Configuration Register       Offset
HET_PFR_OFS     EQU     0x04        ; Prescale Factor Register            Offset
HET_DIR_OFS     EQU     0x34        ; HET Direction Register              Offset

; Constants
HETGCR_INI_Val  EQU     0x00010002  ; Master, ignore suspend
HETGCR_RUN_Val  EQU     0x00010003  ; Master, ignore suspend, on


;// <e0> HET RAM Configuration
;//   <o1.12..13> ASC: Address Setup Time Cycles
;//                 <0=> No Setup Time Required
;//                 <1=> Write Strobe is Delayed 1 Cycle
;//                 <2=> Write Strobe is Delayed 2 Cycles
;//                 <3=> Write Strobe is Delayed 3 Cycles
;//     <i> Determine the number of wait cycles required for the address setup time
;//     <i> to the write strobe for the write operations
;//   <o1.9..11> TWS: Trailing Wait States <0-7>
;//     <i> Determine the trailing wait states after read and write operations to the 
;//     <i> memory associated with the chip select corresponding to the wait states
;//   <o1.4..7> WS: Wait States (both read/write operations) <0-15>
;//   <o1.0..1> DW: Data Width
;//                 <0=> 8 bits
;//                 <1=> 16 bits
;//                 <2=> 32 bits
;//     <i> Data width of the memory region
;// </e>
HET_RAM_SETUP   EQU     1
SMCR1_Val       EQU     0x00000072
WCR0_Val        EQU     0x00000003


; Flash Module (FM) definitions ------------------------------------------------

FM_BASE         EQU     0xFFE88000  ; System Module Base Address
FM_FMBAC1       EQU     0xFFE88000  ; Bank Access Control register 1
FM_FMBAC2       EQU     0xFFE88004  ; Bank Access Control register 2
FM_FMREGOPT     EQU     0xFFE89C00  ; Option Control Register Address
FM_FMMAC1       EQU     0xFFE8BC00  ; Module Access Control register 1 Address
FM_FMMAC2       EQU     0xFFE8BC04  ; Module Access Control register 2 Address

; Constants
B0_FMMAC2_Val   EQU     0x0000FFF8
B1_FMMAC2_Val   EQU     0x0000FFF9
B2_FMMAC2_Val   EQU     0x0000FFFA
B3_FMMAC2_Val   EQU     0x0000FFFB
B4_FMMAC2_Val   EQU     0x0000FFFC
B5_FMMAC2_Val   EQU     0x0000FFFD
B6_FMMAC2_Val   EQU     0x0000FFFE
B7_FMMAC2_Val   EQU     0x0000FFFF

;// <e0> Flash Configuration
;//   <e1.0> Enable Pipeline (in FMREGOPT)
;//   </e>
FLASH_SETUP     EQU     1
FMREGOPT_Val    EQU     0x00000001

;//   <e0> Flash Bank 0
;//     <h> Bank Access Control Register 1 (FMBAC1)
;//       <o1.8..15> BAGP: Bank Active Grace Period <0-255>
;//         <i> Starting count value for the bank active grace period down timer
;//       <o1.2..7> BSTBY: Bank Standby <0-63>
;//         <i> Starting count walue for the bank standby down counter
;//       <o1.0..1> BNKPWR: Bank Power Mode
;//                 <0=> Sleep
;//                 <1=> Standby
;//                 <3=> Active
;//         <i> Fall back power mode which the flash bank enters after the bank grace 
;//         <i> period counter has timed out
;//     </h>
;//     <h> Bank Access Control Register 2 (FMBAC2)
;//       <o2.8..14> BSLEEP: Bank Sleep <0-127>
;//         <i> Starting count value for the bank sleep down counter
;//       <o2.0..7> WAIT: Wait State Counter
;//                 <0x00=> Single Cycle Read Mode
;//                 <0x11=> Pipeline Mode
;//                 <0x22=> 2
;//                 <0x33=> 3
;//                 <0x44=> 4
;//                 <0x55=> 5
;//                 <0x66=> 6
;//                 <0x77=> 7
;//                 <0x88=> 8
;//                 <0x99=> 9
;//                 <0xAA=> 10
;//                 <0xBB=> 11
;//                 <0xCC=> 12
;//                 <0xDD=> 13
;//                 <0xEE=> 14
;//                 <0xFF=> 15
;//         <i> Starting count value for the wait state down counter
;//     </h>
;//   </e>
BANK0_SETUP     EQU     1
B0_FMBAC1_Val   EQU     0x000000FF
B0_FMBAC2_Val   EQU     0x00007F11

;//   <e0> Flash Bank 1
;//     <h> Bank Access Control Register 1 (FMBAC1)
;//       <o1.8..15> BAGP: Bank Active Grace Period <0-255>
;//         <i> Starting count value for the bank active grace period down timer
;//       <o1.2..7> BSTBY: Bank Standby <0-63>
;//         <i> Starting count walue for the bank standby down counter
;//       <o1.0..1> BNKPWR: Bank Power Mode
;//                 <0=> Sleep
;//                 <1=> Standby
;//                 <3=> Active
;//         <i> Fall back power mode which the flash bank enters after the bank grace 
;//         <i> period counter has timed out
;//     </h>
;//     <h> Bank Access Control Register 2 (FMBAC2)
;//       <o2.8..14> BSLEEP: Bank Sleep <0-127>
;//         <i> Starting count value for the bank sleep down counter
;//       <o2.0..7> WAIT: Wait State Counter
;//                 <0x00=> Single Cycle Read Mode
;//                 <0x11=> Pipeline Mode
;//                 <0x22=> 2
;//                 <0x33=> 3
;//                 <0x44=> 4
;//                 <0x55=> 5
;//                 <0x66=> 6
;//                 <0x77=> 7
;//                 <0x88=> 8
;//                 <0x99=> 9
;//                 <0xAA=> 10
;//                 <0xBB=> 11
;//                 <0xCC=> 12
;//                 <0xDD=> 13
;//                 <0xEE=> 14
;//                 <0xFF=> 15
;//         <i> Starting count value for the wait state down counter
;//     </h>
;//   </e>
BANK1_SETUP     EQU     0
B1_FMBAC1_Val   EQU     0x000000FF
B1_FMBAC2_Val   EQU     0x00007F11

;//   <e0> Flash Bank 2
;//     <h> Bank Access Control Register 1 (FMBAC1)
;//       <o1.8..15> BAGP: Bank Active Grace Period <0-255>
;//         <i> Starting count value for the bank active grace period down timer
;//       <o1.2..7> BSTBY: Bank Standby <0-63>
;//         <i> Starting count walue for the bank standby down counter
;//       <o1.0..1> BNKPWR: Bank Power Mode
;//                 <0=> Sleep
;//                 <1=> Standby
;//                 <3=> Active
;//         <i> Fall back power mode which the flash bank enters after the bank grace 
;//         <i> period counter has timed out
;//     </h>
;//     <h> Bank Access Control Register 2 (FMBAC2)
;//       <o2.8..14> BSLEEP: Bank Sleep <0-127>
;//         <i> Starting count value for the bank sleep down counter
;//       <o2.0..7> WAIT: Wait State Counter
;//                 <0x00=> Single Cycle Read Mode
;//                 <0x11=> Pipeline Mode
;//                 <0x22=> 2
;//                 <0x33=> 3
;//                 <0x44=> 4
;//                 <0x55=> 5
;//                 <0x66=> 6
;//                 <0x77=> 7
;//                 <0x88=> 8
;//                 <0x99=> 9
;//                 <0xAA=> 10
;//                 <0xBB=> 11
;//                 <0xCC=> 12
;//                 <0xDD=> 13
;//                 <0xEE=> 14
;//                 <0xFF=> 15
;//         <i> Starting count value for the wait state down counter
;//     </h>
;//   </e>
BANK2_SETUP     EQU     0
B2_FMBAC1_Val   EQU     0x000000FF
B2_FMBAC2_Val   EQU     0x00007F11

;//   <e0> Flash Bank 3
;//     <h> Bank Access Control Register 1 (FMBAC1)
;//       <o1.8..15> BAGP: Bank Active Grace Period <0-255>
;//         <i> Starting count value for the bank active grace period down timer
;//       <o1.2..7> BSTBY: Bank Standby <0-63>
;//         <i> Starting count walue for the bank standby down counter
;//       <o1.0..1> BNKPWR: Bank Power Mode
;//                 <0=> Sleep
;//                 <1=> Standby
;//                 <3=> Active
;//         <i> Fall back power mode which the flash bank enters after the bank grace 
;//         <i> period counter has timed out
;//     </h>
;//     <h> Bank Access Control Register 2 (FMBAC2)
;//       <o2.8..14> BSLEEP: Bank Sleep <0-127>
;//         <i> Starting count value for the bank sleep down counter
;//       <o2.0..7> WAIT: Wait State Counter
;//                 <0x00=> Single Cycle Read Mode
;//                 <0x11=> Pipeline Mode
;//                 <0x22=> 2
;//                 <0x33=> 3
;//                 <0x44=> 4
;//                 <0x55=> 5
;//                 <0x66=> 6
;//                 <0x77=> 7
;//                 <0x88=> 8
;//                 <0x99=> 9
;//                 <0xAA=> 10
;//                 <0xBB=> 11
;//                 <0xCC=> 12
;//                 <0xDD=> 13
;//                 <0xEE=> 14
;//                 <0xFF=> 15
;//         <i> Starting count value for the wait state down counter
;//     </h>
;//   </e>
BANK3_SETUP     EQU     0
B3_FMBAC1_Val   EQU     0x000000FF
B3_FMBAC2_Val   EQU     0x00007F11

;//   <e0> Flash Bank 4
;//     <h> Bank Access Control Register 1 (FMBAC1)
;//       <o1.8..15> BAGP: Bank Active Grace Period <0-255>
;//         <i> Starting count value for the bank active grace period down timer
;//       <o1.2..7> BSTBY: Bank Standby <0-63>
;//         <i> Starting count walue for the bank standby down counter
;//       <o1.0..1> BNKPWR: Bank Power Mode
;//                 <0=> Sleep
;//                 <1=> Standby
;//                 <3=> Active
;//         <i> Fall back power mode which the flash bank enters after the bank grace 
;//         <i> period counter has timed out
;//     </h>
;//     <h> Bank Access Control Register 2 (FMBAC2)
;//       <o2.8..14> BSLEEP: Bank Sleep <0-127>
;//         <i> Starting count value for the bank sleep down counter
;//       <o2.0..7> WAIT: Wait State Counter
;//                 <0x00=> Single Cycle Read Mode
;//                 <0x11=> Pipeline Mode
;//                 <0x22=> 2
;//                 <0x33=> 3
;//                 <0x44=> 4
;//                 <0x55=> 5
;//                 <0x66=> 6
;//                 <0x77=> 7
;//                 <0x88=> 8
;//                 <0x99=> 9
;//                 <0xAA=> 10
;//                 <0xBB=> 11
;//                 <0xCC=> 12
;//                 <0xDD=> 13
;//                 <0xEE=> 14
;//                 <0xFF=> 15
;//         <i> Starting count value for the wait state down counter
;//     </h>
;//   </e>
BANK4_SETUP     EQU     0
B4_FMBAC1_Val   EQU     0x000000FF
B4_FMBAC2_Val   EQU     0x00007F11

;//
;//   <e0> Flash Bank 5
;//     <h> Bank Access Control Register 1 (FMBAC1)
;//       <o1.8..15> BAGP: Bank Active Grace Period <0-255>
;//         <i> Starting count value for the bank active grace period down timer
;//       <o1.2..7> BSTBY: Bank Standby <0-63>
;//         <i> Starting count walue for the bank standby down counter
;//       <o1.0..1> BNKPWR: Bank Power Mode
;//                 <0=> Sleep
;//                 <1=> Standby
;//                 <3=> Active
;//         <i> Fall back power mode which the flash bank enters after the bank grace 
;//         <i> period counter has timed out
;//     </h>
;//     <h> Bank Access Control Register 2 (FMBAC2)
;//       <o2.8..14> BSLEEP: Bank Sleep <0-127>
;//         <i> Starting count value for the bank sleep down counter
;//       <o2.0..7> WAIT: Wait State Counter
;//                 <0x00=> Single Cycle Read Mode
;//                 <0x11=> Pipeline Mode
;//                 <0x22=> 2
;//                 <0x33=> 3
;//                 <0x44=> 4
;//                 <0x55=> 5
;//                 <0x66=> 6
;//                 <0x77=> 7
;//                 <0x88=> 8
;//                 <0x99=> 9
;//                 <0xAA=> 10
;//                 <0xBB=> 11
;//                 <0xCC=> 12
;//                 <0xDD=> 13
;//                 <0xEE=> 14
;//                 <0xFF=> 15
;//         <i> Starting count value for the wait state down counter
;//     </h>
;//   </e>
BANK5_SETUP     EQU     0
B5_FMBAC1_Val   EQU     0x000000FF
B5_FMBAC2_Val   EQU     0x00007F11

;//   <e0> Flash Bank 6
;//     <h> Bank Access Control Register 1 (FMBAC1)
;//       <o1.8..15> BAGP: Bank Active Grace Period <0-255>
;//         <i> Starting count value for the bank active grace period down timer
;//       <o1.2..7> BSTBY: Bank Standby <0-63>
;//         <i> Starting count walue for the bank standby down counter
;//       <o1.0..1> BNKPWR: Bank Power Mode
;//                 <0=> Sleep
;//                 <1=> Standby
;//                 <3=> Active
;//         <i> Fall back power mode which the flash bank enters after the bank grace 
;//         <i> period counter has timed out
;//     </h>
;//     <h> Bank Access Control Register 2 (FMBAC2)
;//       <o2.8..14> BSLEEP: Bank Sleep <0-127>
;//         <i> Starting count value for the bank sleep down counter
;//       <o2.0..7> WAIT: Wait State Counter
;//                 <0x00=> Single Cycle Read Mode
;//                 <0x11=> Pipeline Mode
;//                 <0x22=> 2
;//                 <0x33=> 3
;//                 <0x44=> 4
;//                 <0x55=> 5
;//                 <0x66=> 6
;//                 <0x77=> 7
;//                 <0x88=> 8
;//                 <0x99=> 9
;//                 <0xAA=> 10
;//                 <0xBB=> 11
;//                 <0xCC=> 12
;//                 <0xDD=> 13
;//                 <0xEE=> 14
;//                 <0xFF=> 15
;//         <i> Starting count value for the wait state down counter
;//     </h>
;//   </e>
BANK6_SETUP     EQU     0
B6_FMBAC1_Val   EQU     0x000000FF
B6_FMBAC2_Val   EQU     0x00007F11

;//   <e0> Flash Bank 7
;//     <h> Bank Access Control Register 1 (FMBAC1)
;//       <o1.8..15> BAGP: Bank Active Grace Period <0-255>
;//         <i> Starting count value for the bank active grace period down timer
;//       <o1.2..7> BSTBY: Bank Standby <0-63>
;//         <i> Starting count walue for the bank standby down counter
;//       <o1.0..1> BNKPWR: Bank Power Mode
;//                 <0=> Sleep
;//                 <1=> Standby
;//                 <3=> Active
;//         <i> Fall back power mode which the flash bank enters after the bank grace 
;//         <i> period counter has timed out
;//     </h>
;//     <h> Bank Access Control Register 2 (FMBAC2)
;//       <o2.8..14> BSLEEP: Bank Sleep <0-127>
;//         <i> Starting count value for the bank sleep down counter
;//       <o2.0..7> WAIT: Wait State Counter
;//                 <0x00=> Single Cycle Read Mode
;//                 <0x11=> Pipeline Mode
;//                 <0x22=> 2
;//                 <0x33=> 3
;//                 <0x44=> 4
;//                 <0x55=> 5
;//                 <0x66=> 6
;//                 <0x77=> 7
;//                 <0x88=> 8
;//                 <0x99=> 9
;//                 <0xAA=> 10
;//                 <0xBB=> 11
;//                 <0xCC=> 12
;//                 <0xDD=> 13
;//                 <0xEE=> 14
;//                 <0xFF=> 15
;//         <i> Starting count value for the wait state down counter
;//     </h>
;//   </e>
BANK7_SETUP     EQU     0
B7_FMBAC1_Val   EQU     0x000000FF
B7_FMBAC2_Val   EQU     0x00007F11

;// </e>


;----------------------- CODE --------------------------------------------------

; - Protection Keys ------------------------------------------------------------

                PRESERVE8

; Area Definition for Protection Keys
                
                IF      :DEF:NO_KEYS
                ELSE

                AREA    |.ARM.__AT_0xFFE0|, CODE, READONLY
                ARM

                IF      PROTECT_SETUP = 3   ; Write MSM and Flash protect keys
                DCD     MS_KEY0_Val
                DCD     MS_KEY1_Val
                DCD     MS_KEY2_Val
                DCD     MS_KEY3_Val
                DCD     FP_KEY0_Val
                DCD     FP_KEY1_Val
                DCD     FP_KEY2_Val
                DCD     FP_KEY3_Val
                ELSE                        ; Write default key values
                DCD     0xFFFFFFFF
                DCD     0xFFFFFFFF
                DCD     0xFFFFFFFF
                DCD     0xFFFFFFFF
                DCD     0xFFFFFFFF
                DCD     0xFFFFFFFF
                DCD     0xFFFFFFFF
                DCD     0xFFFFFFFF
                ENDIF

                ENDIF

; - Starup Code ----------------------------------------------------------------

; Area Definition and Entry Point
;  Startup Code must be linked first at Address at which it expects to run.

                AREA    RESET, CODE, READONLY
                ARM

                IMPORT  SWI_Handler
                IMPORT  IRQ_Handler

; Exception Vectors
;  Mapped to Address 0.
;  Absolute addressing mode must be used.
;  Dummy Handlers are implemented as infinite loops which can be modified.
;  Implementation is made with B instructions instead of LDR instructions
;  because at reset vectors are in unsecured space and can not read the 
;  address of jump from secured space, so Branch has to be used

Vectors         B       Reset_Handler
Undef_Handler   B       Undef_Handler
SWI             B       SWI_Handler
PAbt_Handler    B       PAbt_Handler
DAbt_Handler    B       DAbt_Handler
                NOP                     ; Reserved Vector
IRQ             B       IRQ_Handler
FIQ_Handler     B       FIQ_Handler


; Reset Handler

                EXPORT  Reset_Handler
Reset_Handler   


; System Initialization --------------------------------------------------------

                ; Disable violations (peripheral, memory and illegal address)
                LDR     R0, =SM_BASE
                LDR     R1, =SM_SYSECR_Val
                STR     R1, [R0, #SM_SYSECR_OFS]

; - Memory Setup ---------------------------------------------------------------

                IF      :DEF:MEMORY_MAP

                ; Flash Setup
                LDR     R1, =MFBAHR0_Val
                STR     R1, [R0, #SM_MFBAHR0_OFS]
                LDR     R1, =MFBALR0_Val
                STR     R1, [R0, #SM_MFBALR0_OFS]

                IF      MFBA_R1_SETUP != 0
                LDR     R1, =MFBAHR1_Val
                STR     R1, [R0, #SM_MFBAHR1_OFS]
                LDR     R1, =MFBALR1_Val
                STR     R1, [R0, #SM_MFBALR1_OFS]
                ENDIF

                ; RAM Setup
                LDR     R1, =MFBAHR2_Val
                STR     R1, [R0, #SM_MFBAHR2_OFS]
                LDR     R1, =MFBALR2_Val
                STR     R1, [R0, #SM_MFBALR2_OFS]

                IF      MFBA_R3_SETUP != 0
                LDR     R1, =MFBAHR3_Val
                STR     R1, [R0, #SM_MFBAHR3_OFS]
                LDR     R1, =MFBALR3_Val
                STR     R1, [R0, #SM_MFBALR3_OFS]
                ENDIF

                ; HET RAM Setup
                IF      HET_RAM_SETUP != 0
                LDR     R1, =SMCR1_Val
                STR     R1, [R0, #SM_SMCR1_OFS]

                LDR     R1, =MFBAHR4_Val
                STR     R1, [R0, #SM_MFBAHR4_OFS]
                LDR     R1, =MFBALR4_Val
                STR     R1, [R0, #SM_MFBALR4_OFS]

                LDR     R1, =WCR0_Val
                STR     R1, [R0, #SM_WCR0_OFS]
                ENDIF
                
                IF      MFBA_R5_SETUP != 0
                LDR     R1, =MFBAHR5_Val
                STR     R1, [R0, #SM_MFBAHR5_OFS]
                LDR     R1, =MFBALR5_Val
                STR     R1, [R0, #SM_MFBALR5_OFS]
                ENDIF

                ; Enable Memory Map
                LDR     R1, =MFBALR0_Val
                LDR     R2, =MFBALR0_MS_Val
                ORR     R1, R1, R2
                STR     R1, [R0, #SM_MFBALR0_OFS]

                ENDIF

; - Clock Setup ----------------------------------------------------------------

                IF      CLOCK_SETUP != 0
                LDR     R1, =PCR_Val            ; Peripheral clock setting
                STR     R1, [R0, #SM_PCR_OFS]
                LDR     R1, =GLBCTRL_Val        ; PLL setting
                STR     R1, [R0, #SM_GLBCTRL_OFS]
                ENDIF

; - Flash Setup ----------------------------------------------------------------

                IF      FLASH_SETUP != 0
                LDR     R2, =GLBCTRL_FC_Val     ; Enable Flash Config Mode
                LDR     R1, [R0, #SM_GLBCTRL_OFS]
                ORR     R1, R1, R2
                STR     R1, [R0, #SM_GLBCTRL_OFS]

                IF      BANK0_SETUP != 0
                LDR     R0, =FM_FMMAC2          ; Setup Bank 0
                LDR     R1, =B0_FMMAC2_Val
                STR     R1, [R0, #0]
                LDR     R0, =FM_FMBAC1
                LDR     R1, =B0_FMBAC1_Val
                STR     R1, [R0, #0]
                LDR     R0, =FM_FMBAC2
                LDR     R1, =B0_FMBAC2_Val
                STR     R1, [R0, #0]
                ENDIF

                IF      BANK1_SETUP != 0
                LDR     R0, =FM_FMMAC2
                LDR     R1, =B1_FMMAC2_Val
                STR     R1, [R0, #0]
                LDR     R0, =FM_FMBAC1
                LDR     R1, =B1_FMBAC1_Val
                STR     R1, [R0, #0]
                LDR     R0, =FM_FMBAC2
                LDR     R1, =B1_FMBAC2_Val
                STR     R1, [R0, #0]
                ENDIF

                IF      BANK2_SETUP != 0
                LDR     R0, =FM_FMMAC2
                LDR     R1, =B2_FMMAC2_Val
                STR     R1, [R0, #0]
                LDR     R0, =FM_FMBAC1
                LDR     R1, =B2_FMBAC1_Val
                STR     R1, [R0, #0]
                LDR     R0, =FM_FMBAC2
                LDR     R1, =B2_FMBAC2_Val
                STR     R1, [R0, #0]
                ENDIF

                IF      BANK3_SETUP != 0
                LDR     R0, =FM_FMMAC2
                LDR     R1, =B3_FMMAC2_Val
                STR     R1, [R0, #0]
                LDR     R0, =FM_FMBAC1
                LDR     R1, =B3_FMBAC1_Val
                STR     R1, [R0, #0]
                LDR     R0, =FM_FMBAC2
                LDR     R1, =B3_FMBAC2_Val
                STR     R1, [R0, #0]
                ENDIF

                IF      BANK4_SETUP != 0
                LDR     R0, =FM_FMMAC2
                LDR     R1, =B4_FMMAC2_Val
                STR     R1, [R0, #0]
                LDR     R0, =FM_FMBAC1
                LDR     R1, =B4_FMBAC1_Val
                STR     R1, [R0, #0]
                LDR     R0, =FM_FMBAC2
                LDR     R1, =B4_FMBAC2_Val
                STR     R1, [R0, #0]
                ENDIF

                IF      BANK5_SETUP != 0
                LDR     R0, =FM_FMMAC2
                LDR     R1, =B5_FMMAC2_Val
                STR     R1, [R0, #0]
                LDR     R0, =FM_FMBAC1
                LDR     R1, =B5_FMBAC1_Val
                STR     R1, [R0, #0]
                LDR     R0, =FM_FMBAC2
                LDR     R1, =B5_FMBAC2_Val
                STR     R1, [R0, #0]
                ENDIF

                IF      BANK6_SETUP != 0
                LDR     R0, =FM_FMMAC2
                LDR     R1, =B6_FMMAC2_Val
                STR     R1, [R0, #0]
                LDR     R0, =FM_FMBAC1
                LDR     R1, =B6_FMBAC1_Val
                STR     R1, [R0, #0]
                LDR     R0, =FM_FMBAC2
                LDR     R1, =B6_FMBAC2_Val
                STR     R1, [R0, #0]
                ENDIF

                IF      BANK7_SETUP != 0
                LDR     R0, =FM_FMMAC2
                LDR     R1, =B7_FMMAC2_Val
                STR     R1, [R0, #0]
                LDR     R0, =FM_FMBAC1
                LDR     R1, =B7_FMBAC1_Val
                STR     R1, [R0, #0]
                LDR     R0, =FM_FMBAC2
                LDR     R1, =B7_FMBAC2_Val
                STR     R1, [R0, #0]
                ENDIF

                LDR     R0, =FM_FMREGOPT        ; Enable Pipeline 
                LDR     R1, =FMREGOPT_Val
                STR     R1, [R0, #0]

                LDR     R0, =SM_BASE            ; Disable Flash Config Mode
                LDR     R2, =GLBCTRL_FC_Val
                LDR     R1, =0xFFFFFFFF
                EOR     R2, R1, R2
                LDR     R1, [R0, #SM_GLBCTRL_OFS]
                AND     R1, R1, R2
                STR     R1, [R0, #SM_GLBCTRL_OFS]
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
