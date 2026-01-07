;/*****************************************************************************/
;/* RM9200.S: Startup file for Atmel AT91RM9200 device series                 */
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
; *  The RM9200.S code is executed after CPU Reset. This file may be 
; *  translated with the following SET symbols. In uVision these SET 
; *  symbols are entered under Options - ASM - Define.
; *
; *  REMAP: when set the startup code remaps exception vectors from
; *  on-chip RAM to address 0.
; *
; *  RAM_INTVEC: when set the startup code copies exception vectors 
; *  from on-chip Flash to on-chip RAM.
; *
; *  NO_SDRAM_INIT: when set the SDRAM controller is not initialized in startup
; *  and it is used when SDRAM controller is initialized from debugger 
; *  enviroment (using the debug script).
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


; Internal Memory Base Addresses
FLASH_BASE      EQU     0x00100000   
RAM_BASE        EQU     0x00200000

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
IRQ_Stack_Size  EQU     0x00000040
USR_Stack_Size  EQU     0x00000050

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


; Parallel Input/Output Controller (PIO) User Interface
PIOA_BASE       EQU     0xFFFFF400      ; PIO A Base Address
PIOB_BASE       EQU     0xFFFFF600      ; PIO B Base Address
PIOC_BASE       EQU     0xFFFFF800      ; PIO C Base Address
PIOD_BASE       EQU     0xFFFFFA00      ; PIO D Base Address
PIO_PER_OFS     EQU     0x00            ; PIO Enable Register     Address Offset
PIO_PDR_OFS     EQU     0x04            ; PIO Disable Register    Address Offset
PIO_OER_OFS     EQU     0x10            ; PIO Output Enable Reg   Address Offset
PIO_ODR_OFS     EQU     0x14            ; PIO Output Disable Reg  Address Offset
PIO_MDER_OFS    EQU     0x50            ; PIO Multi-Driver En Reg Address Offset
PIO_MDDR_OFS    EQU     0x54            ; PIO Multi-Driver Ds Reg Address Offset
PIO_PUDR_OFS    EQU     0x60            ; PIO Pull-up Disable Reg Address Offset
PIO_PUER_OFS    EQU     0x64            ; PIO Pull-up Enable Reg  Address Offset
PIO_ASR_OFS     EQU     0x70            ; PIO Periph A Select Reg Address Offset
PIO_BSR_OFS     EQU     0x74            ; PIO Periph B Select Reg Address Offset


; Memory Control (MC) User Interface
;  |- External Bus Interface (EBI) User Interface
;      |- Static Memory Controller (SMC) User Interface
;      |- SDRAM Controller (SDRAMC) User Interface
;      |- Burst Flash Controller (BFC) User Interface
MC_BASE         EQU     0xFFFFFF00      ; MC Base Address
MC_RCR_OFS      EQU     0x00            ; Remap Control Reg       Address Offset
MC_ASR_OFS      EQU     0x04            ; Abort Status Register   Address Offset
MC_AASR_OFS     EQU     0x08            ; Abort Adress Status Reg Address Offset

; External Bus Interface (EBI) User Interface
EBI_BASE        EQU     0xFFFFFF60      ; EBI Base Address
EBI_CSA_OFS     EQU     0x00            ; Chip Select Assign Reg  Address Offset
EBI_CFGR_OFS    EQU     0x04            ; Configuration Register  Address Offset

; Static Memory Controller (SMC) User Interface
SMC_BASE        EQU     0xFFFFFF70      ; SMC Base Address
SMC_CSR0_OFS    EQU     0x00            ; Chip Select 0 Reg       Address Offset
SMC_CSR1_OFS    EQU     0x04            ; Chip Select 1 Reg       Address Offset
SMC_CSR2_OFS    EQU     0x08            ; Chip Select 2 Reg       Address Offset
SMC_CSR3_OFS    EQU     0x0C            ; Chip Select 3 Reg       Address Offset
SMC_CSR4_OFS    EQU     0x10            ; Chip Select 4 Reg       Address Offset
SMC_CSR5_OFS    EQU     0x14            ; Chip Select 5 Reg       Address Offset
SMC_CSR6_OFS    EQU     0x18            ; Chip Select 6 Reg       Address Offset
SMC_CSR7_OFS    EQU     0x1C            ; Chip Select 7 Reg       Address Offset

; Constants
EBI_CS0_ADDRESS EQU     0x10000000      ; Start of memory addressed by CS0
EBI_CS1_ADDRESS EQU     0x20000000      ; Start of memory addressed by CS1
EBI_CS2_ADDRESS EQU     0x30000000      ; Start of memory addressed by CS2
EBI_CS3_ADDRESS EQU     0x40000000      ; Start of memory addressed by CS3
EBI_CS4_ADDRESS EQU     0x50000000      ; Start of memory addressed by CS4
EBI_CS5_ADDRESS EQU     0x60000000      ; Start of memory addressed by CS5
EBI_CS6_ADDRESS EQU     0x70000000      ; Start of memory addressed by CS6
EBI_CS7_ADDRESS EQU     0x80000000      ; Start of memory addressed by CS7

; SDRAM Controller (SDRAMC) User Interface
SDRAMC_BASE     EQU     0xFFFFFF90      ; SDRAMC Base Address
SDRAMC_MR_OFS   EQU     0x00            ; Mode Register          Address Offsett
SDRAMC_TR_OFS   EQU     0x04            ; Refresh Timer Register Address Offsett
SDRAMC_CR_OFS   EQU     0x08            ; Configuration Register Address Offsett
SDRAMC_SRR_OFS  EQU     0x0C            ; Self Refresh Register  Address Offsett
SDRAMC_LPR_OFS  EQU     0x10            ; Low Power Register     Address Offsett
SDRAMC_IER_OFS  EQU     0x14            ; Interrupt Enable Reg   Address Offsett
SDRAMC_IDR_OFS  EQU     0x18            ; Interrupt Disable Reg  Address Offsett
SDRAMC_IMR_OFS  EQU     0x1C            ; Interrupt Mask Reg     Address Offsett
SDRAMC_ISR_OFS  EQU     0x20            ; Interrupt Status Reg   Address Offsett

; Constants
NORMAL_CMD      EQU     0x00            ; SDRAM Normal Mode
NOP_CMD         EQU     0x01            ; SDRAM NOP Command
PRCGALL_CMD     EQU     0x02            ; SDRAM All Banks Precharge Command
LMR_CMD         EQU     0x03            ; SDRAM Load Mode Register Command
RFSH_CMD        EQU     0x04            ; SDRAM Refresh Command

; Burst Flash Controller (BFC) User Interface
BFC_BASE        EQU     0xFFFFFFC0      ; BFC Base Address
BFC_MR_OFS      EQU     0x00            ; Mode Register          Address Offset

;// <e> External Bus Interface (EBI)
EBI_SETUP       EQU     1

;//   <h> Static Memory Controller Chip Select Registers
;//     <e> Chip Select Register 0 (SMC_CSR0)
;//       <o1.0..6>   NWS: Number of Wait States <0-127>
;//       <o1.7>      WSEN: Wait State Enabled
;//       <o1.8..11>  TDF: Data Float Time <0-15>
;//       <o1.12>     BAT: Byte Access Type  
;//                     <0=> Chip Select line connected to  8-bit wide (2 or 4) devices
;//                     <1=> Chip Select line connected to 16-bit wide device
;//       <o1.13..14> DBW: Data Bus Width
;//                     <0=> Reserved     <1=> 16-bit
;//                     <2=> 8-bit        <3=> Reserved
;//       <o1.15>     DRP: Data Read Protocol
;//                     <0=> Standard Read Protocol is used
;//                     <1=> Early Read Protocol is used
;//       <o1.16..17> ACSS: Address to Chip Select Setup
;//                     <0=> Standard, asserted at the bigining of access and deasserted at the end
;//                     <1=> One cycle less at the begining and the end of access
;//                     <2=> Two cycle less at the begining and the end of access
;//                    <3=> Three cycle less at the begining and the end of access
;//       <o1.24..26> RWSETUP: Read and Write Signal Setup Time <0-7>
;//       <o1.28..30> RWHOLD: Read and Write Signal Hold Time <0-7>
;//     </e>
SMC_CSR0_SETUP  EQU     0x00000001
SMC_CSR0_Val    EQU     0x00003284

;//     <e> Chip Select Register 1 (SMC_CSR1)
;//       <o1.0..6>   NWS: Number of Wait States <0-127>
;//       <o1.7>      WSEN: Wait State Enabled
;//       <o1.8..11>  TDF: Data Float Time <0-15>
;//       <o1.12>     BAT: Byte Access Type  
;//                     <0=> Chip Select line connected to  8-bit wide (2 or 4) devices
;//                     <1=> Chip Select line connected to 16-bit wide device
;//       <o1.13..14> DBW: Data Bus Width
;//                     <0=> Reserved     <1=> 16-bit
;//                     <2=> 8-bit        <3=> Reserved
;//       <o1.15>     DRP: Data Read Protocol
;//                     <0=> Standard Read Protocol is used
;//                     <1=> Early Read Protocol is used
;//       <o1.16..17> ACSS: Address to Chip Select Setup
;//                     <0=> Standard, asserted at the bigining of access and deasserted at the end
;//                     <1=> One cycle less at the begining and the end of access
;//                     <2=> Two cycle less at the begining and the end of access
;//                     <3=> Three cycle less at the begining and the end of access
;//       <o1.24..26> RWSETUP: Read and Write Signal Setup Time <0-7>
;//       <o1.28..30> RWHOLD: Read and Write Signal Hold Time <0-7>
;//     </e>
SMC_CSR1_SETUP  EQU     0x00000000
SMC_CSR1_Val    EQU     0x00000000

;//     <e> Chip Select Register 2 (SMC_CSR2)
;//       <o1.0..6>   NWS: Number of Wait States <0-127>
;//       <o1.7>      WSEN: Wait State Enabled
;//       <o1.8..11>  TDF: Data Float Time <0-15>
;//       <o1.12>     BAT: Byte Access Type  
;//                     <0=> Chip Select line connected to  8-bit wide (2 or 4) devices
;//                     <1=> Chip Select line connected to 16-bit wide device
;//       <o1.13..14> DBW: Data Bus Width
;//                     <0=> Reserved     <1=> 16-bit
;//                     <2=> 8-bit        <3=> Reserved
;//       <o1.15>     DRP: Data Read Protocol
;//                     <0=> Standard Read Protocol is used
;//                     <1=> Early Read Protocol is used
;//       <o1.16..17> ACSS: Address to Chip Select Setup
;//                     <0=> Standard, asserted at the bigining of access and deasserted at the end
;//                     <1=> One cycle less at the begining and the end of access
;//                     <2=> Two cycle less at the begining and the end of access
;//                     <3=> Three cycle less at the begining and the end of access
;//       <o1.24..26> RWSETUP: Read and Write Signal Setup Time <0-7>
;//       <o1.28..30> RWHOLD: Read and Write Signal Hold Time <0-7>
;//     </e>
SMC_CSR2_SETUP  EQU     0x00000000
SMC_CSR2_Val    EQU     0x00000000

;//     <e> Chip Select Register 3 (SMC_CSR3)
;//       <o1.0..6>   NWS: Number of Wait States <0-127>
;//       <o1.7>      WSEN: Wait State Enabled
;//       <o1.8..11>  TDF: Data Float Time <0-15>
;//       <o1.12>     BAT: Byte Access Type  
;//                     <0=> Chip Select line connected to  8-bit wide (2 or 4) devices
;//                     <1=> Chip Select line connected to 16-bit wide device
;//       <o1.13..14> DBW: Data Bus Width
;//                     <0=> Reserved     <1=> 16-bit
;//                     <2=> 8-bit        <3=> Reserved
;//       <o1.15>     DRP: Data Read Protocol
;//                     <0=> Standard Read Protocol is used
;//                     <1=> Early Read Protocol is used
;//       <o1.16..17> ACSS: Address to Chip Select Setup
;//                     <0=> Standard, asserted at the bigining of access and deasserted at the end
;//                     <1=> One cycle less at the begining and the end of access
;//                     <2=> Two cycle less at the begining and the end of access
;//                     <3=> Three cycle less at the begining and the end of access
;//       <o1.24..26> RWSETUP: Read and Write Signal Setup Time <0-7>
;//       <o1.28..30> RWHOLD: Read and Write Signal Hold Time <0-7>
;//     </e>
SMC_CSR3_SETUP  EQU     0x00000000
SMC_CSR3_Val    EQU     0x00000000

;//     <e> Chip Select Register 4 (SMC_CSR4)
;//       <o1.0..6>   NWS: Number of Wait States <0-127>
;//       <o1.7>      WSEN: Wait State Enabled
;//       <o1.8..11>  TDF: Data Float Time <0-15>
;//       <o1.12>     BAT: Byte Access Type  
;//                     <0=> Chip Select line connected to  8-bit wide (2 or 4) devices
;//                     <1=> Chip Select line connected to 16-bit wide device
;//       <o1.13..14> DBW: Data Bus Width
;//                     <0=> Reserved     <1=> 16-bit
;//                     <2=> 8-bit        <3=> Reserved
;//       <o1.15>     DRP: Data Read Protocol
;//                     <0=> Standard Read Protocol is used
;//                     <1=> Early Read Protocol is used
;//       <o1.16..17> ACSS: Address to Chip Select Setup
;//                     <0=> Standard, asserted at the bigining of access and deasserted at the end
;//                     <1=> One cycle less at the begining and the end of access
;//                     <2=> Two cycle less at the begining and the end of access
;//                     <3=> Three cycle less at the begining and the end of access
;//       <o1.24..26> RWSETUP: Read and Write Signal Setup Time <0-7>
;//       <o1.28..30> RWHOLD: Read and Write Signal Hold Time <0-7>
;//     </e>
SMC_CSR4_SETUP  EQU     0x00000000
SMC_CSR4_Val    EQU     0x00000000

;//     <e> Chip Select Register 5 (SMC_CSR5)
;//       <o1.0..6>   NWS: Number of Wait States <0-127>
;//       <o1.7>      WSEN: Wait State Enabled
;//       <o1.8..11>  TDF: Data Float Time <0-15>
;//       <o1.12>     BAT: Byte Access Type  
;//                     <0=> Chip Select line connected to  8-bit wide (2 or 4) devices
;//                     <1=> Chip Select line connected to 16-bit wide device
;//       <o1.13..14> DBW: Data Bus Width
;//                     <0=> Reserved     <1=> 16-bit
;//                     <2=> 8-bit        <3=> Reserved
;//       <o1.15>     DRP: Data Read Protocol
;//                     <0=> Standard Read Protocol is used
;//                     <1=> Early Read Protocol is used
;//       <o1.16..17> ACSS: Address to Chip Select Setup
;//                     <0=> Standard, asserted at the bigining of access and deasserted at the end
;//                     <1=> One cycle less at the begining and the end of access
;//                     <2=> Two cycle less at the begining and the end of access
;//                     <3=> Three cycle less at the begining and the end of access
;//       <o1.24..26> RWSETUP: Read and Write Signal Setup Time <0-7>
;//       <o1.28..30> RWHOLD: Read and Write Signal Hold Time <0-7>
;//     </e>
SMC_CSR5_SETUP  EQU     0x00000000
SMC_CSR5_Val    EQU     0x00000000

;//     <e> Chip Select Register 6 (SMC_CSR6)
;//       <o1.0..6>   NWS: Number of Wait States <0-127>
;//       <o1.7>      WSEN: Wait State Enabled
;//       <o1.8..11>  TDF: Data Float Time <0-15>
;//       <o1.12>     BAT: Byte Access Type  
;//                     <0=> Chip Select line connected to  8-bit wide (2 or 4) devices
;//                     <1=> Chip Select line connected to 16-bit wide device
;//       <o1.13..14> DBW: Data Bus Width
;//                     <0=> Reserved     <1=> 16-bit
;//                     <2=> 8-bit        <3=> Reserved
;//       <o1.15>     DRP: Data Read Protocol
;//                     <0=> Standard Read Protocol is used
;//                     <1=> Early Read Protocol is used
;//       <o1.16..17> ACSS: Address to Chip Select Setup
;//                     <0=> Standard, asserted at the bigining of access and deasserted at the end
;//                     <1=> One cycle less at the begining and the end of access
;//                     <2=> Two cycle less at the begining and the end of access
;//                     <3=> Three cycle less at the begining and the end of access
;//       <o1.24..26> RWSETUP: Read and Write Signal Setup Time <0-7>
;//       <o1.28..30> RWHOLD: Read and Write Signal Hold Time <0-7>
;//     </e>
SMC_CSR6_SETUP  EQU     0x00000000
SMC_CSR6_Val    EQU     0x00000000

;//     <e> Chip Select Register 7 (SMC_CSR7)
;//       <o1.0..6>   NWS: Number of Wait States <0-127>
;//       <o1.7>      WSEN: Wait State Enabled
;//       <o1.8..11>  TDF: Data Float Time <0-15>
;//       <o1.12>     BAT: Byte Access Type  
;//                     <0=> Chip Select line connected to  8-bit wide (2 or 4) devices
;//                     <1=> Chip Select line connected to 16-bit wide device
;//       <o1.13..14> DBW: Data Bus Width
;//                     <0=> Reserved     <1=> 16-bit
;//                     <2=> 8-bit        <3=> Reserved
;//       <o1.15>     DRP: Data Read Protocol
;//                     <0=> Standard Read Protocol is used
;//                     <1=> Early Read Protocol is used
;//       <o1.16..17> ACSS: Address to Chip Select Setup
;//                     <0=> Standard, asserted at the bigining of access and deasserted at the end
;//                     <1=> One cycle less at the begining and the end of access
;//                     <2=> Two cycle less at the begining and the end of access
;//                     <3=> Three cycle less at the begining and the end of access
;//       <o1.24..26> RWSETUP: Read and Write Signal Setup Time <0-7>
;//       <o1.28..30> RWHOLD: Read and Write Signal Hold Time <0-7>
;//     </e>
;//   </h>
SMC_CSR7_SETUP  EQU     0x00000000
SMC_CSR7_Val    EQU     0x00000000

;//   <e> External Bus Interface Configuration
;//     <h> Chip Select Assignment Register (EBI_CSA)
;//       <o1.0>      CS0A: Chip Select 0 Assignment
;//                     <0=> Assigned to the Static Memory Controller
;//                     <1=> Assigned to the Burst Flash Controller
;//       <o1.1>      CS1A: Chip Select 1 Assignment
;//                     <0=> Assigned to the Static Memory Controller
;//                     <1=> Assigned to the SDRAM Controller
;//       <o1.3>      CS3A: Chip Select 3 Assignment
;//                     <0=> Assigned to the Static Memory Controller
;//                     <1=> Assigned to the SMC and NAND Flash/SmartMedia Logic activated
;//       <o1.4>      CS4A: Chip Select 4 Assignment
;//                     <0=> Assigned to the Static Memory Controller and NCS4, NCS5 and NCS6
;//                     <1=> Assigned to the SMC and Compact Flash Logic activated
;//     </h>
;//
;//     <h> Configuration Register (EBI_CFGR)
;//       <o2.0>      DBPUC: Data Bus Pull-Up Configuration
;//                     <0=> Internally pulled-up to the VDDIOM power supply
;//                     <1=> Not internally pulled-up
;//     </h>
;//   </e>
EBI_CFG_SETUP   EQU     0x00000001
EBI_CSA_Val     EQU     0x00000002
EBI_CFGR_Val    EQU     0x00000000

;//   <e> SDRAM Controller (SDRAMC)
SDRAMC_SETUP    EQU     1

;//     <h> Mode Register (SDRAMC_MR)
;//       <o0.0..3>   MODE: SDRAMC Command Mode
;//                     <i> 0 - Normal Mode, SDRAM is decoded normally
;//                     <i> 1 - SDRAM Controller issues NOP command on SDRAM access
;//                     <i> 2 - SDRAM Controller issues an "All Bank Precharge"
;//                     <i>     command when SDRAM is accessed
;//                     <i> 3 - SDRAM Controller issues an "Load Mode Register"
;//                     <i>     command when SDRAM is accessed
;//                     <i> 4 - SDRAM Controller issues an "Refresh", previously an 
;//                     <i>     "All Bank Precharge" command must be issued
;//                     <0=> Normal Mode          <1=> NOP Command
;//                     <2=> All Banks Precharge  <3=> Load Mode Register
;//                     <4=> Refresh
;//       <o0.4>      DBW: Data Bus Width
;//                     <0=> 32 bits              <1=> 16 bits
;//     </h>
SDRAMC_MR_Val   EQU     0x00000000

;//     <h> Refresh Timer Register (SDRAMC_TR)
;//       <o0.0..12>  COUNT: SDRAMC Refresh Timer Count <0-4095>
;//                     <i> This 12-bit field is loaded into a timer that generates
;//                     <i> the refresh pulse
;//     </h>
SDRAMC_TR_Val   EQU     0x000002E0

;//     <h> Configuration Register (SDRAMC_CR)
;//       <o0.0..1>   NC: Number of Column Bits
;//                     <0=> 8  <1=> 9  <2=> 10 <3=> 11
;//       <o0.2..3>   NR: Number of Row Bits
;//                     <0=> 11 <1=> 12 <2=> 13  <3=> Reserved
;//       <o0.4>      NB: Number of Banks
;//                     <0=> 2  <1=> 4
;//       <o0.5..6>   CAS: CAS Latency
;//                     <0=> Reserved <1=> Reserved <2=> 2  <3=> Reserved
;//       <o0.7..10>  TWR: Write Recovery Delay <2-15>
;//                     <i> Defines Write Recovery Time in cycles,
;//                     <i> if it is less than 2 cycles, 2 clock periods are inserted
;//       <o0.11..14> TRC: Row Cycle Delay <2-15>
;//                     <i> Defines delay between Refresh and an Activate 
;//                     <i> Command in cycles,
;//                     <i> if it is less than 2 cycles, 2 clock periods are used
;//       <o0.15..18> TRP: Row Precharge Delay <2-15>
;//                     <i> Defines delay between Precharge Command
;//                     <i> and another Command in cycles,
;//                     <i> if it is less than 2 cycles, 2 clock periods are used
;//       <o0.19..22> TRCD: Row to Column Delay <2-15>
;//                     <i> Defines delay between Activate Command
;//                     <i> and a Read/Write Command in cycles,
;//                     <i> if it is less than 2 cycles, 2 clock periods are used
;//       <o0.23..26> TRAS: Active to Precharge Delay <2-15>
;//                     <i> Defines delay between Activate Command
;//                     <i> and a Precharge Command in cycles,
;//                     <i> if it is less than 2 cycles, 2 clock periods are used
;//       <o0.27..30> TXSR: Exit Self Refresh to Active Delay <1-15>
;//                     <i> Defines delay between SCKE set high
;//                     <i> and an Activate Command in cycles, number of cycles
;//                     <i> is between 0.5 and 15.5, 0.5 is used for value 0 also
;//     </h>
SDRAMC_CR_Val   EQU     0x2188C155

;//     <h> Self-refresh Register (SDRAMC_SRR)
;//       <o0.0>      SRR: Self-refresh Enabled
;//     </h>
SDRAMC_SRR_Val  EQU     0x00001955

;//     <h> Interrupt Enable Register (SDRAMC_IER)
;//       <o0.0>      RES: Refresh Error interrupt Enabled
;//     </h>
SDRAMC_IER_Val  EQU     0x00000000

;//   </e>

;//   <e> Burst Flash Controller (BFC)
;//     <o1.0..1>     BFCOM: Burst Flash Controller Operating Mode
;//                     <0=> Disabled   <1=> Asynchronous 
;//                     <2=> Burst Read <3=> Reserved
;//     <o1.2..3>     BFCC: Burst Flash Controller Clock
;//                     <0=> Reserved         <1=> Master Clock 
;//                     <2=> Master Clock / 2 <3=> Master Clock / 4
;//     <o1.4..7>     AVL: Address Valid Latency <0-15>
;//                     <i> Is a number of BFC Clock Cycles from the first BFCK
;//                     <i> rising edge when BFAVD is asserted to the BFCK rising
;//                     <i> edge that samples read data
;//                     <i> The latency is equal to AVL + 1
;//     <o1.8..10>    PAGES: Page Size
;//                     <0=> No page handling <1=> 16 bytes page 
;//                     <2=> 32 bytes page    <3=> 64 bytes page 
;//                     <4=> 128 bytes page   <5=> 256 bytes page 
;//                     <6=> 512 bytes page   <7=> 1024 bytes page 
;//     <o1.12..13>   OEL: Output Enable Latency <1-3>
;//                     <i> Defines the number of idle cycles inserted after each 
;//                     <i> level change on the BFOE output enable signal
;//     <o1.16>       BAAEN: Burst Address Advance Enable
;//     <o1.17>       BFOEH: Burst Flash Output Enable Handling
;//     <o1.18>       MUXEN: Multiplexed Bus Enable
;//     <o1.19>       RDYEN: Ready Enable Mode
;//   </e>
BFC_SETUP       EQU     0
BFC_MR_Val      EQU     0x00000000

;// </e>


; Power Management Controller (PMC) definitions
PMC_BASE        EQU     0xFFFFFC00      ; PMC Base Address
PMC_SCER_OFS    EQU     0x00            ; Sys Clk Enable Reg      Address Offset
PMC_SCDR_OFS    EQU     0x04            ; Sys Clk Disable Reg     Address Offset
PMC_SCSR_OFS    EQU     0x08            ; Sys Clk Status Reg      Address Offset
PMC_PCER_OFS    EQU     0x10            ; Periph Clk Enable Reg   Address Offset
PMC_PCDR_OFS    EQU     0x14            ; Periph Clk Disable Reg  Address Offset
PMC_PCSR_OFS    EQU     0x18            ; Periph Clk Status Reg   Address Offset
CKGR_MOR_OFS    EQU     0x20            ; Main Oscillator Reg     Address Offset
CKGR_MCFR_OFS   EQU     0x24            ; Main Clock Freq Reg     Address Offset
CKGR_PLLAR_OFS  EQU     0x28            ; PLLA Reg                Address Offset
CKGR_PLLBR_OFS  EQU     0x2C            ; PLLA Reg                Address Offset
PMC_MCKR_OFS    EQU     0x30            ; Master Clock Reg        Address Offset
PMC_PCK0_OFS    EQU     0x40            ; Programmable Clk 0 Reg  Address Offset
PMC_PCK1_OFS    EQU     0x44            ; Programmable Clk 1 Reg  Address Offset
PMC_PCK2_OFS    EQU     0x48            ; Programmable Clk 2 Reg  Address Offset
PMC_PCK3_OFS    EQU     0x4C            ; Programmable Clk 3 Reg  Address Offset
PMC_IER_OFS     EQU     0x60            ; Interrupt Enable  Reg   Address Offset
PMC_IDR_OFS     EQU     0x64            ; Interrupt Disable Reg   Address Offset
PMC_SR_OFS      EQU     0x68            ; Status Reg              Address Offset
PMC_IMR_OFS     EQU     0x6C            ; Interrupt Mask Reg      Address Offset

; Bit constants
PMC_MOSCEN      EQU     (1<<0)          ; Main Oscillator Enable
PMC_MUL         EQU     (0x7FF<<16)     ; PLL Multiplier
PMC_MOSCS       EQU     (1<<0)          ; Main Oscillator Stable
PMC_LOCKA       EQU     (1<<1)          ; PLL A Lock Status
PMC_LOCKB       EQU     (1<<2)          ; PLL A Lock Status
PMC_MCKRDY      EQU     (1<<3)          ; Master Clock Status

;// <e> Power Management Controller (PMC)
;//   <h> System Clock Enable Register (PMC_SCER)
;//     <o1.0>      PCK: Processor Clock Enable
;//     <o1.1>      UDP: USB Device Port Clock Enable
;//     <o1.2>      MCKUDP: USB Device Port Master Clock Automatic Disable on Suspend Enable
;//     <o1.4>      UHP: USB Host Port Clock Enable
;//     <o1.8>      PCK0: Programmable Clock Output Enable
;//     <o1.9>      PCK1: Programmable Clock Output Enable
;//     <o1.10>     PCK2: Programmable Clock Output Enable
;//     <o1.11>     PCK3: Programmable Clock Output Enable
;//   </h>
;//
;//   <h> Peripheral Clock Enable Register (PMC_PCER)
;//     <o2.2>      PID2: Parallel IO Controller A Enable
;//     <o2.3>      PID3: Parallel IO Controller B Enable
;//     <o2.4>      PID4: Parallel IO Controller C Enable
;//     <o2.5>      PID5: Parallel IO Controller D Enable
;//     <o2.6>      PID6: USART0 Enable
;//     <o2.7>      PID7: USART1 Enable
;//     <o2.8>      PID8: USART2 Enable
;//     <o2.9>      PID9: USART3 Enable
;//     <o2.10>     PID10: Multimedia Card Interface Enable
;//     <o2.11>     PID11: USB Device Port Enable
;//     <o2.12>     PID12: Two-Wire Interface Enable
;//     <o2.13>     PID13: Serial Peripheral Interface Enable
;//     <o2.14>     PID14: Serial Synchronous Controller 0 Enable
;//     <o2.15>     PID15: Serial Synchronous Controller 1 Enable
;//     <o2.16>     PID16: Serial Synchronous Controller 2 Enable
;//     <o2.17>     PID17: Timer Counter 0 Enable
;//     <o2.18>     PID18: Timer Counter 1 Enable
;//     <o2.19>     PID19: Timer Counter 2 Enable
;//     <o2.20>     PID20: Timer Counter 3 Enable
;//     <o2.21>     PID21: Timer Counter 4 Enable
;//     <o2.22>     PID22: Timer Counter 5 Enable
;//     <o2.23>     PID23: USB Host Port Enable
;//     <o2.24>     PID24: Ethernet MAC Enable
;//     <o2.25>     PID25: Advanced Interrupt Controller (IRQ0) Enable
;//     <o2.26>     PID26: Advanced Interrupt Controller (IRQ1) Enable
;//     <o2.27>     PID27: Advanced Interrupt Controller (IRQ2) Enable
;//     <o2.28>     PID28: Advanced Interrupt Controller (IRQ3) Enable
;//     <o2.29>     PID29: Advanced Interrupt Controller (IRQ4) Enable
;//     <o2.30>     PID30: Advanced Interrupt Controller (IRQ5) Enable
;//     <o2.31>     PID31: Advanced Interrupt Controller (IRQ6) Enable
;//   </h>
;//
;//   <h> Main Oscillator Register (CKGR_MOR)
;//     <o3.0>      MOSCEN: Main Oscillator Enable
;//     <o3.8..15>  OSCOUNT: Main Oscillator Startup Time <0-255>
;//   </h>
;//
;//   <h> Clock Generator Phase Locked Loop A Register (CKGR_PLLAR)
;//                   <i> PLL A Freq = (Main CLOCK Freq / DIVA) * (MULA + 1)
;//     <o4.0..7>   DIVA: PLL Divider A <0-255>
;//                   <i> 0        - Divider output is 0
;//                   <i> 1        - Divider is bypassed
;//                   <i> 2 .. 255 - Divider output is the Main Clock divided by DIVA
;//     <o4.8..13>  PLLACOUNT: PLL A Counter <0-63>
;//                   <i> Number of Slow Clocks before the LOCKA bit is set in 
;//                   <i> PMC_SR after CKGR_PLLAR is written
;//     <o4.14..15> OUTA: PLL A Clock Frequency Range
;//                   <0=> 80 .. 160MHz   <1=> Reserved
;//                   <2=> 150 .. 240MHz  <3=> Reserved
;//     <o4.16..26> MULA: PLL A Multiplier <0-2047>
;//                   <i> 0         - The PLL A is deactivated
;//                   <i> 1 .. 2047 - The PLL A Clock frequency is the PLL a input 
;//                   <i>             frequency multiplied by MULA + 1
;//   </h>
;//
;//   <h> Clock Generator Phase Locked Loop B Register (CKGR_PLLBR)
;//                   <i> PLL B Freq = (Main CLOCK Freq / DIVB) * (MULB + 1)
;//     <o5.0..7>   DIVB: PLL Divider B <0-255>
;//                   <i> 0        - Divider output is 0
;//                   <i> 1        - Divider is bypassed
;//                   <i> 2 .. 255 - Divider output is the Main Clock divided by DIVB
;//     <o5.8..13>  PLLBCOUNT: PLL B Counter <0-63>
;//                   <i> Number of Slow Clocks before the LOCKB bit is set in 
;//                   <i> PMC_SR after CKGR_PLLBR is written
;//     <o5.14..15> OUTB: PLL B Clock Frequency Range
;//                   <0=> 80 .. 160MHz   <1=> Reserved
;//                   <2=> 150 .. 240MHz  <3=> Reserved
;//     <o5.16..26> MULB: PLL B Multiplier <0-2047>
;//                   <i> 0         - The PLL B is deactivated
;//                   <i> 1 .. 2047 - The PLL B Clock frequency is the PLL a input 
;//                   <i>             frequency multiplied by MULB + 1
;//     <o5.28>     USB_96M: Divider by 2 Enable
;//                   <i> 0 - USB ports = PLL B Clock, PLL B Clock must be 48MHz
;//                   <i> 1 - USB ports = PLL B Clock / 2, PLL B Clock must be 96MHz
;//   </h>
;//
;//   <h> Master Clock Register (CKGR_MCKR)
;//     <o6.0..1>   CSS: Master Clock Selection
;//                   <0=> Slow Clock
;//                   <1=> Main Clock
;//                   <2=> PLL A Clock
;//                   <3=> PLL B Clock
;//     <o6.2..4>   PRES: Master Clock Prescaler
;//                   <0=> Clock        <1=> Clock / 2
;//                   <2=> Clock / 4    <3=> Clock / 8
;//                   <4=> Clock / 16   <5=> Clock / 32
;//                   <6=> Clock / 64   <7=> Reserved
;//     <o6.8..9>   MDIV: Master Clock Division
;//                   <0=> Processor Clock = Master Clock
;//                   <1=> Processor Clock = 2 x Master Clock
;//                   <2=> Processor Clock = 3 x Master Clock
;//                   <3=> Processor Clock = 4 x Master Clock
;//   </h>
;//
;//   <h> Programmable Clock Register 0 (PMC_PCK0)
;//     <o7.0..1>   CSS: Master Clock Selection
;//                   <0=> Slow Clock
;//                   <1=> Main Clock
;//                   <2=> PLL A Clock
;//                   <3=> PLL B Clock
;//     <o7.2..4>   PRES: Programmable Clock Prescaler
;//                   <0=> Clock        <1=> Clock / 2
;//                   <2=> Clock / 4    <3=> Clock / 8
;//                   <4=> Clock / 16   <5=> Clock / 32
;//                   <6=> Clock / 64   <7=> Reserved
;//   </h>
;//
;//   <h> Programmable Clock Register 1 (PMC_PCK1)
;//     <o8.0..1>   CSS: Master Clock Selection
;//                   <0=> Slow Clock
;//                   <1=> Main Clock
;//                   <2=> PLL A Clock
;//                   <3=> PLL B Clock
;//     <o8.2..4>   PRES: Programmable Clock Prescaler
;//                   <0=> None         <1=> Clock / 2
;//                   <2=> Clock / 4    <3=> Clock / 8
;//                   <4=> Clock / 16   <5=> Clock / 32
;//                   <6=> Clock / 64   <7=> Reserved
;//   </h>
;//
;//   <h> Programmable Clock Register 2 (PMC_PCK2)
;//     <o9.0..1>   CSS: Master Clock Selection
;//                   <0=> Slow Clock
;//                   <1=> Main Clock
;//                   <2=> PLL A Clock
;//                   <3=> PLL B Clock
;//     <o9.2..4>   PRES: Programmable Clock Prescaler
;//                   <0=> None         <1=> Clock / 2
;//                   <2=> Clock / 4    <3=> Clock / 8
;//                   <4=> Clock / 16   <5=> Clock / 32
;//                   <6=> Clock / 64   <7=> Reserved
;//   </h>
;//
;//   <h> Programmable Clock Register 3 (PMC_PCK3)
;//     <o10.0..1>  CSS: Master Clock Selection
;//                   <0=> Slow Clock
;//                   <1=> Main Clock
;//                   <2=> PLL A Clock
;//                   <3=> PLL B Clock
;//     <o10.2..4>  PRES: Programmable Clock Prescaler
;//                   <0=> None         <1=> Clock / 2
;//                   <2=> Clock / 4    <3=> Clock / 8
;//                   <4=> Clock / 16   <5=> Clock / 32
;//                   <6=> Clock / 64   <7=> Reserved
;//   </h>
;// </e>
PMC_SETUP       EQU     1
PMC_SCER_Val    EQU     0x00000001
PMC_PCER_Val    EQU     0x007E0018
CKGR_MOR_Val    EQU     0x0000FF01
CKGR_PLLAR_Val  EQU     0x2026BF04
CKGR_PLLBR_Val  EQU     0x10483F0E
PMC_MCKR_Val    EQU     0x00000202
PMC_PCK0_Val    EQU     0x00000000
PMC_PCK1_Val    EQU     0x00000000
PMC_PCK2_Val    EQU     0x00000000
PMC_PCK3_Val    EQU     0x00000000


; Cache

; Constants
ICACHE_ENABLE   EQU     (1<<12)         ; Instruction Cache Enable Value

;// <e> Instruction Cache Enable
;// </e>
CACHE_SETUP     EQU     1


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
                NOP                     ; Reserved Vector
;               LDR     PC,IRQ_Addr     
                LDR     PC,[PC,#-0xF20] ; Vector From AIC_IVR
;               LDR     PC,FIQ_Addr
                LDR     PC,[PC,#-0xF20] ; Vector From AIC_FVR

Reset_Addr      DCD     Reset_Handler
Undef_Addr      DCD     Undef_Handler
SWI_Addr        DCD     SWI_Handler
PAbt_Addr       DCD     PAbt_Handler
DAbt_Addr       DCD     DAbt_Handler
                DCD     0               ; Reserved Address
IRQ_Addr        DCD     IRQ_Handler
FIQ_Addr        DCD     FIQ_Handler

                IMPORT  SWI_Handler

Undef_Handler   B       Undef_Handler
;SWI_Handler    B       SWI_Handler     ; Part of RTL
PAbt_Handler    B       PAbt_Handler
DAbt_Handler    B       DAbt_Handler
IRQ_Handler     B       IRQ_Handler
FIQ_Handler     B       FIQ_Handler


; Reset Handler

                EXPORT  Reset_Handler
Reset_Handler   


; Setup External Bus Interface (EBI)

                IF      EBI_SETUP != 0

                ; Setup Static Memory Controller if enabled
                LDR     R0, =SMC_BASE

                IF      SMC_CSR0_SETUP != 0
                LDR     R1, =SMC_CSR0_Val
                STR     R1, [R0, #SMC_CSR0_OFS]
                ENDIF
                IF      SMC_CSR1_SETUP != 0
                LDR     R1, =SMC_CSR1_Val
                STR     R1, [R0, #SMC_CSR1_OFS]
                ENDIF
                IF      SMC_CSR2_SETUP != 0
                LDR     R1, =SMC_CSR2_Val
                STR     R1, [R0, #SMC_CSR2_OFS]
                ENDIF
                IF      SMC_CSR3_SETUP != 0
                LDR     R1, =SMC_CSR3_Val
                STR     R1, [R0, #SMC_CSR3_OFS]
                ENDIF
                IF      SMC_CSR4_SETUP != 0
                LDR     R1, =SMC_CSR4_Val
                STR     R1, [R0, #SMC_CSR4_OFS]
                ENDIF
                IF      SMC_CSR5_SETUP != 0
                LDR     R1, =SMC_CSR5_Val
                STR     R1, [R0, #SMC_CSR5_OFS]
                ENDIF
                IF      SMC_CSR6_SETUP != 0
                LDR     R1, =SMC_CSR6_Val
                STR     R1, [R0, #SMC_CSR6_OFS]
                ENDIF
                IF      SMC_CSR7_SETUP != 0
                LDR     R1, =SMC_CSR7_Val
                STR     R1, [R0, #SMC_CSR7_OFS]
                ENDIF

                ; Enable EBI Chip Select assignments if necessary
                IF      EBI_CFG_SETUP != 0
                LDR     R0, =EBI_BASE

                LDR     R1, =EBI_CSA_Val
                STR     R1, [R0, #EBI_CSA_OFS]
                LDR     R1, =EBI_CFGR_Val
                STR     R1, [R0, #EBI_CFGR_OFS]
                ENDIF

                ; Setup SDRAM Controller if enabled
                IF      :DEF:NO_SDRAM_INIT
                ELSE
                IF      SDRAMC_SETUP != 0

                ; Setup Parallel Input/Output C Registers
                ; for driving SDRAM lines
                LDR     R0, =PIOC_BASE
                LDR     R1, =0xFFFF0000  
                STR     R1, [R0, #PIO_PDR_OFS]

                LDR     R0, =SDRAMC_BASE
                LDR     R2, =EBI_CS1_ADDRESS
                MOV     R3, #0

                ; Setup Control Register of SDRAM Controller
                LDR     R1, =SDRAMC_CR_Val
                STR     R1, [R0, #SDRAMC_CR_OFS]

                ; Write All Banks Precharge Command to SDRAM
                MOV     R1, #PRCGALL_CMD
                STR     R1, [R0, #SDRAMC_MR_OFS]
                STR     R3, [R2, #0]

                ; Provide 8 Auto Refresh to SDRAM
                MOV     R1, #RFSH_CMD
                STR     R1, [R0, #SDRAMC_MR_OFS]
                STR     R3, [R2, #0]
                STR     R3, [R2, #0]
                STR     R3, [R2, #0]
                STR     R3, [R2, #0]
                STR     R3, [R2, #0]
                STR     R3, [R2, #0]
                STR     R3, [R2, #0]
                STR     R3, [R2, #0]

                ; Write a Load Mode Register Command to SDRAM
                MOV     R1, #LMR_CMD
                STR     R1, [R0, #SDRAMC_MR_OFS]
                STR     R3, [R2, #0x80]

                ; Setup Refresh Timer Register
                LDR     R1, =SDRAMC_TR_Val
                STR     R1, [R0, #SDRAMC_TR_OFS]
                STR     R3, [R2, #0]

                ; Enter Normal Mode
                MOV     R1, #NORMAL_CMD
                STR     R1, [R0, #SDRAMC_MR_OFS]

                ; Setup SDRAM Controller Registers
                LDR     R1, =SDRAMC_SRR_Val
                STR     R1, [R0, #SDRAMC_SRR_OFS]
                LDR     R1, =SDRAMC_IER_Val
                STR     R1, [R0, #SDRAMC_IER_OFS]
                ENDIF
                ENDIF   ; of IF      :DEF:NO_SDRAM_INIT

                ; Setup Burst Flash Controller if enabled
                IF      BFC_SETUP != 0

                ; Setup Parallel Input/Output C Registers
                ; for driving Burst Flash
                LDR     R0, =PIOC_BASE
                MOV     R1, #0x7F  
                STR     R1, [R0, #PIO_PDR_OFS]

                ; Setup Burst Flash Controller Registers
                LDR     R0, =BFC_BASE

                LDR     R1, =BFC_MR_Val
                STR     R1, [R0, #BFC_MR_OFS]
                ENDIF

                ENDIF   ; of IF EBI_SETUP != 0


; Setup Power Management Controller (PMC)

                IF      PMC_SETUP != 0
                LDR     R0, =PMC_BASE

                ; System Clock Enable
                LDR     R1, =PMC_SCER_Val
                STR     R1, [R0, #PMC_SCER_OFS]

                ; Peripheral Clock Enable
                LDR     R1, =PMC_PCER_Val
                STR     R1, [R0, #PMC_PCER_OFS]

                ; Setup Main Oscillator
                IF      (CKGR_MOR_Val:AND:PMC_MOSCEN) != 0
                LDR     R1, =CKGR_MOR_Val
                STR     R1, [R0, #CKGR_MOR_OFS]

                ; Wait until Main Oscillator is stabilized
MOSCS_Loop      LDR     R2, [R0, #PMC_SR_OFS]
                ANDS    R2, R2, #PMC_MOSCS
                BEQ     MOSCS_Loop
                ENDIF

                ; Setup the PLL A
                IF      (CKGR_PLLAR_Val:AND:PMC_MUL) != 0  
                LDR     R1, =CKGR_PLLAR_Val
                STR     R1, [R0, #CKGR_PLLAR_OFS]

                ; Wait until PLL A is stabilized
PLLA_Loop       LDR     R2, [R0, #PMC_SR_OFS]
                ANDS    R2, R2, #PMC_LOCKA
                BEQ     PLLA_Loop
                ENDIF

                ; Setup the PLL B
                IF      (CKGR_PLLBR_Val:AND:PMC_MUL) != 0  
                LDR     R1, =CKGR_PLLBR_Val
                STR     R1, [R0, #CKGR_PLLBR_OFS]

                ; Wait until PLL B is stabilized
PLLB_Loop       LDR     R2, [R0, #PMC_SR_OFS]
                ANDS    R2, R2, #PMC_LOCKB
                BEQ     PLLB_Loop
                ENDIF

                ; Setup the Master Clock and the Processor Clock
                LDR     R1, =PMC_MCKR_Val
                STR     R1, [R0, #PMC_MCKR_OFS]

                ; Wait until Main Master Clock is ready
MCKR_Loop       LDR     R2, [R0, #PMC_SR_OFS]
                ANDS    R2, R2, #PMC_MCKRDY
                BEQ     MCKR_Loop

                ; Setup Programmable Clock Register 0
                LDR     R1, =PMC_PCK0_Val
                STR     R1, [R0, #PMC_PCK0_OFS]

                ; Setup Programmable Clock Register 1
                LDR     R1, =PMC_PCK1_Val
                STR     R1, [R0, #PMC_PCK1_OFS]

                ; Setup Programmable Clock Register 2
                LDR     R1, =PMC_PCK2_Val
                STR     R1, [R0, #PMC_PCK2_OFS]

                ; Setup Programmable Clock Register 3
                LDR     R1, =PMC_PCK3_Val
                STR     R1, [R0, #PMC_PCK3_OFS]
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

                IF      :DEF:REMAP
                LDR     R0, =MC_BASE
                MOV     R1, #1
                STR     R1, [R0, #MC_RCR_OFS]   ; Remap
                ENDIF

; Cache Setup
                IF      CACHE_SETUP != 0
                MRC     p15, 0, R0, c1, c0, 0   ; Enable Instruction Cache
                ORR     R0, R0, #ICACHE_ENABLE
                MCR     p15, 0, R0, c1, c0, 0
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
