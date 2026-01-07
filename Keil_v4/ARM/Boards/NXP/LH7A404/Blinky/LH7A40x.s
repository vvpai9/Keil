;/*****************************************************************************/
;/* LH7A40x.S: Startup file for NXP LH7A40x device series                     */
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
; *  The LH7A40x.S code is executed after CPU Reset. This file may be 
; *  translated with the following SET symbols. In uVision these SET 
; *  symbols are entered under Options - ASM - Define.
; *
; *  SDMC_NOINIT:   when set, the Synchronous Dynamic Memory Controller is not  
; *                 initialized in startup.
; *
; *  MMU_NOINIT:    when set the startup code does not initialize Memory 
; *                 Management Unit (MMU is necessary for remapping)
; *
; *  EXTSDRAM_MODE: when set the device is configured for code execution
; *                 from external SDRAM memory starting at address 0xC0000000.
; *
; *  INTSRAM_MODE:  when set the device is configured for code execution
; *                 from on-chip SRAM starting at address 0xB0000000.
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


;----------------------- Clock and State Controller (CSC) Definitions ----------

; Clock and State Controller (CSC) Definitions
CSC_BASE        EQU     0x80000400      ; CSC                     Base Address
PWRSR_OFS       EQU     0x00            ; Power Reset Register    Address Offset
PWRCNT_OFS      EQU     0x04            ; Power Control Register  Address Offset
HALT_OFS        EQU     0x08            ; Halt Register           Address Offset
STBY_OFS        EQU     0x0C            ; Standby Register        Address Offset
BLEOI_OFS       EQU     0x10            ; Battery Low Interrupt R Address Offset
MCEOI_OFS       EQU     0x14            ; Media Change Interupt R Address Offset
TEOI_OFS        EQU     0x18            ; TICK and TICK Tout Int  Address Offset
STFCLR_OFS      EQU     0x1C            ; New Bat, User Res,..Int Address Offset
CLKSET_OFS      EQU     0x20            ; Clock Set Regsiter      Address Offset
SCRREG0_OFS     EQU     0x40            ; Scratch Register 0      Address Offset
SCRREG1_OFS     EQU     0x44            ; Scratch Register 1      Address Offset
USBDRESET_OFS   EQU     0x4C            ; USB Device Reset Reg    Address Offset
BMAR_OFS        EQU     0x54            ; Bus Master Arbitration  Address Offset
BOOTCLR_OFS     EQU     0x58            ; Boot ROM Clear Register Address Offset

; Constants
HCLKDIV_MASK    EQU     (3 <<  0)       ; HCLKDIV mask in CLKSET Register

;// <e> Clock Configuration (CSC)
CLOCK_SETUP     EQU     1

;//   <h> Power Control Register (PWRCNT)
;//     <o0.29>     UARTBAUD: UART Baud Clock Source
;//                     <0=> 14.7456 MHz
;//                     <1=> 7.3728 MHz
;//     <o0.28>     USHEN: USB Host Clock Enable
;//     <o0.27>     DMAM2MCH1: DMA M2M Channel 1 Clock Enable
;//     <o0.26>     DMAM2MCH0: DMA M2M Channel 0 Clock Enable
;//     <o0.25>     DMAM2PCH8: DMA M2P Channel 8 Clock Enable
;//     <o0.24>     DMAM2PCH9: DMA M2P Channel 9 Clock Enable
;//     <o0.23>     DMAM2PCH6: DMA M2P Channel 6 Clock Enable
;//     <o0.22>     DMAM2PCH7: DMA M2P Channel 7 Clock Enable
;//     <o0.21>     DMAM2PCH4: DMA M2P Channel 4 Clock Enable
;//     <o0.20>     DMAM2PCH5: DMA M2P Channel 5 Clock Enable
;//     <o0.19>     DMAM2PCH2: DMA M2P Channel 2 Clock Enable
;//     <o0.18>     DMAM2PCH3: DMA M2P Channel 3 Clock Enable
;//     <o0.17>     DMAM2PCH0: DMA M2P Channel 0 Clock Enable
;//     <o0.16>     DMAM2PCH1: DMA M2P Channel 1 Clock Enable
;//     <o0.8..15>  PGMCLK: Program Clock Divisor <0x0-0xFE:2>
;//       <i> PGMCLK output = 14.7456 MHz / Divisor value
;//       <i> This field value has to be an even number or 1, if 0 this 
;//       <i> clock output is disabled
;//     <o0.1>      WAKEDIS: Wakeup Disable
;//   </h>
PWRCNT_Val      EQU     0x00000100

;//   <h> Clock Set Register (CLKSET)
;//     <o0.24>     SMCROM: SCM Clock Disable
;//       <i> Disables HCLK gating to Static Memory Controller (SMC)
;//     <o0.18..19> PS: PS Divisor
;//                     <i> PLL1 output clock signal divisor
;//                     <0=> PLL1 / 1
;//                     <1=> PLL1 / 2
;//                     <2=> PLL1 / 4
;//                     <3=> PLL1 / 8
;//     <o0.16..17> PCLKDIV: PCLK Divisor
;//       <i> Divisor for the HCLK AHB clock to generate PCLK APB clock
;//                     <0=> PCLK = HCLK / 2
;//                     <1=> PCLK = HCLK / 4
;//                     <2=> PCLK = HCLK / 8
;//                     <3=> PCLK = HCLK / 8
;//     <o0.11..15> MAINDIV2: Main Divisor 2 <0-31>
;//       <i> Divisor value used in PLL1; PLL1 output is called GCLK
;//       <i> GCLK=((MAINDIV1+2)*(MAINDIV2+2)*14.7456 MHz)/((PREDIV+2)*(^2^PS))
;//     <o0.7..10>  MAINDIV1: Main Divisor 1 <0-15>
;//       <i> Divisor value used in PLL1; PLL1 output is called GCLK
;//       <i> GCLK=((MAINDIV1+2)*(MAINDIV2+2)*14.7456 MHz)/((PREDIV+2)*(^2^PS))
;//     <o0.2..6>   PREDIV: Predivisor <0-31>
;//       <i> Predivisor value used in PLL1; PLL1 output is called GCLK
;//       <i> GCLK=((MAINDIV1+2)*(MAINDIV2+2)*14.7456 MHz)/((PREDIV+2)*(^2^PS))
;//     <o0.0..1>   HCLKDIV: HCLK Divisor
;//       <i> Divisor value for HCLK to generate the FCLK processor clock
;//                     <0=> FCLK = HCLK
;//                     <1=> FCLK = HCLK / 2
;//                     <2=> FCLK = HCLK / 3
;//                     <3=> FCLK = HCLK / 4
;//   </h>
CLKSET_Val      EQU     0x0004EE39

;//   <h> USB Device Reset Register (USBDRESET)
;//     <o0.1>      APBRESETREG: Reset USB Device control side
;//     <o0.0>      IORESETREG: Reset USB Device I/O side
;//   </h>
USBDRESET_Val   EQU     0x00000000

;//   <h> Bus Master Arbitration Register (BMAR)
;//     <o0.5>      DENIRQ: De-grant DMA IRQ
;//     <o0.4>      DENFIQ: De-grant DMA FIQ
;//     <o0.3>      PRICORE: ARM Core Priority
;//     <o0.0..1>   PRIORITY: Priority Order
;//                     <0=> Priority order: USB Host, DMA Controller
;//                     <1=> Priority order: DMA Controller, USB Host
;//                     <2=> Priority order: DMA Controller, USB Host
;//                     <3=> Priority order: USB Host, DMA Controller
;//   </h>
BMAR_Val        EQU     0x00000000

;//   <h> Boot ROM Clear Register (BOOTCLR)
;//     <o0.0>      BOOTCLR: Boot ROM Clear
;//   </h>
BOOTCLR_Val     EQU     0x00000001

;// </e> Clock Configuration


;----------------------- Static Memory Controller (SMC) Definitions ------------

; Static Memory Controller (SMC) User Interface
SMC_BASE            EQU 0x80002000      ; SMC Base Address
SMC_BCR0_OFS        EQU 0x000
SMC_BCR1_OFS        EQU 0x004
SMC_BCR2_OFS        EQU 0x008
SMC_BCR3_OFS        EQU 0x00C
SMC_BCR6_OFS        EQU 0x018
SMC_BCR7_OFS        EQU 0x01C
SMC_PC1ATTRIB_OFS   EQU 0x020
SMC_PC1COM_OFS      EQU 0x024
SMC_PC1IO_OFS       EQU 0x028
SMC_PC2ATTRIB_OFS   EQU 0x030
SMC_PC2COM_OFS      EQU 0x034
SMC_PC2IO_OFS       EQU 0x038
SMC_PCMCIACON_OFS   EQU 0x040

;// <e> Static Memory Controller Configuration (SMC)
SMC_SETUP           EQU 1

;//   <e0> Bank Configuration Register 0 (BCR0)
;//     <o1.28..29> MW: Memory Width
;//                     <0=> 8 bits <1=> 16 bits <2=> 32 bits
;//     <o1.27>     PME: Page Mode Enable
;//     <o1.26>     WP: Write Protect Enable
;//     <o1.25>     WPERR: Clear Write Protect Error
;//     <o1.11..15> WST2: Wait State 2 <0-31>
;//     <o1.10>     RBLE: Read Byte Lane Enables
;//                     <0=> nBLE[3:0] driven HIGH during ext mem read or write
;//                     <1=> nBLE[3:0] driven LOW during ext mem read or write
;//     <o1.5..9>   WST1: Wait State 1 <0-31>
;//       <i> This defines read and write access time, time = (WST1 + 1) * HCLK
;//     <o1.0..3>   IDCY: Idle Cycle <0-15>
;//       <i> This defines data bus turnaround time, time = (IDCY + 1) * HCLK
;//   </e>
SMC_BCR0_SETUP      EQU 0
SMC_BCR0_Val        EQU 0x2000FBEF

;//   <e0> Bank Configuration Register 1 (BCR1)
;//     <o1.28..29> MW: Memory Width
;//                     <0=> 8 bits <1=> 16 bits <2=> 32 bits
;//     <o1.27>     PME: Page Mode Enable
;//     <o1.26>     WP: Write Protect Enable
;//     <o1.25>     WPERR: Clear Write Protect Error
;//     <o1.11..15> WST2: Wait State 2 <0-31>
;//     <o1.10>     RBLE: Read Byte Lane Enables
;//                     <0=> nBLE[3:0] driven HIGH during ext mem read or write
;//                     <1=> nBLE[3:0] driven LOW during ext mem read or write
;//     <o1.5..9>   WST1: Wait State 1 <0-31>
;//       <i> This defines read and write access time, time = (WST1 + 1) * HCLK
;//     <o1.0..3>   IDCY: Idle Cycle <0-15>
;//       <i> This defines data bus turnaround time, time = (IDCY + 1) * HCLK
;//   </e>
SMC_BCR1_SETUP      EQU 0
SMC_BCR1_Val        EQU 0x00000000

;//   <e0> Bank Configuration Register 2 (BCR2)
;//     <o1.28..29> MW: Memory Width
;//                     <0=> 8 bits <1=> 16 bits <2=> 32 bits
;//     <o1.27>     PME: Page Mode Enable
;//     <o1.26>     WP: Write Protect Enable
;//     <o1.25>     WPERR: Clear Write Protect Error
;//     <o1.11..15> WST2: Wait State 2 <0-31>
;//     <o1.10>     RBLE: Read Byte Lane Enables
;//                     <0=> nBLE[3:0] driven HIGH during ext mem read or write
;//                     <1=> nBLE[3:0] driven LOW during ext mem read or write
;//     <o1.5..9>   WST1: Wait State 1 <0-31>
;//       <i> This defines read and write access time, time = (WST1 + 1) * HCLK
;//     <o1.0..3>   IDCY: Idle Cycle <0-15>
;//       <i> This defines data bus turnaround time, time = (IDCY + 1) * HCLK
;//   </e>
SMC_BCR2_SETUP      EQU 0
SMC_BCR2_Val        EQU 0x00000000

;//   <e0> Bank Configuration Register 3 (BCR3)
;//     <o1.28..29> MW: Memory Width
;//                     <0=> 8 bits <1=> 16 bits <2=> 32 bits
;//     <o1.27>     PME: Page Mode Enable
;//     <o1.26>     WP: Write Protect Enable
;//     <o1.25>     WPERR: Clear Write Protect Error
;//     <o1.11..15> WST2: Wait State 2 <0-31>
;//     <o1.10>     RBLE: Read Byte Lane Enables
;//                     <0=> nBLE[3:0] driven HIGH during ext mem read or write
;//                     <1=> nBLE[3:0] driven LOW during ext mem read or write
;//     <o1.5..9>   WST1: Wait State 1 <0-31>
;//       <i> This defines read and write access time, time = (WST1 + 1) * HCLK
;//     <o1.0..3>   IDCY: Idle Cycle <0-15>
;//       <i> This defines data bus turnaround time, time = (IDCY + 1) * HCLK
;//   </e>
SMC_BCR3_SETUP      EQU 0
SMC_BCR3_Val        EQU 0x00000000

;//   <e0> Bank Configuration Register 6 (BCR6)
;//     <o1.28..29> MW: Memory Width
;//                     <0=> 8 bits <1=> 16 bits <2=> 32 bits
;//     <o1.27>     PME: Page Mode Enable
;//     <o1.26>     WP: Write Protect Enable
;//     <o1.25>     WPERR: Clear Write Protect Error
;//     <o1.11..15> WST2: Wait State 2 <0-31>
;//     <o1.10>     RBLE: Read Byte Lane Enables
;//                     <0=> nBLE[3:0] driven HIGH during ext mem read or write
;//                     <1=> nBLE[3:0] driven LOW during ext mem read or write
;//     <o1.5..9>   WST1: Wait State 1 <0-31>
;//       <i> This defines read and write access time, time = (WST1 + 1) * HCLK
;//     <o1.0..3>   IDCY: Idle Cycle <0-15>
;//       <i> This defines data bus turnaround time, time = (IDCY + 1) * HCLK
;//   </e>
SMC_BCR6_SETUP      EQU 1
SMC_BCR6_Val        EQU 0x1000FBEF

;//   <e0> Bank Configuration Register 7 (BCR7)
;//     <o1.28..29> MW: Memory Width
;//                     <0=> 8 bits <1=> 16 bits <2=> 32 bits
;//     <o1.27>     PME: Page Mode Enable
;//     <o1.26>     WP: Write Protect Enable
;//     <o1.25>     WPERR: Clear Write Protect Error
;//     <o1.11..15> WST2: Wait State 2 <0-31>
;//     <o1.10>     RBLE: Read Byte Lane Enables
;//                     <0=> nBLE[3:0] driven HIGH during ext mem read or write
;//                     <1=> nBLE[3:0] driven LOW during ext mem read or write
;//     <o1.5..9>   WST1: Wait State 1 <0-31>
;//       <i> This defines read and write access time, time = (WST1 + 1) * HCLK
;//     <o1.0..3>   IDCY: Idle Cycle <0-15>
;//       <i> This defines data bus turnaround time, time = (IDCY + 1) * HCLK
;//   </e>
SMC_BCR7_SETUP      EQU 1
SMC_BCR7_Val        EQU 0x1000FBEF

;//   <e0> PCMCIA Configuration
;//     <h> PC Card 1 Attribute Space Register (PC1ATTRIB)
;//       <o1.31>     WA: Width of Attribute Address Space
;//                       <0=> 8 bits <1=> 16 bits
;//       <o1.16..23> AA: Access Time for Attribute Space <0-255>
;//         <i> This defines attribute space access time, time = (AA + 1) * HCLK
;//       <o1.8..11>  HT: Hold Time <0-15>
;//         <i> This defines hold time between nOE and nWE, 
;//         <i> time = (HT + 1) * HCLK
;//       <o1.0..7>   PA: Pre-charge Delay Time for Attribute Space <0-255>
;//         <i> This defines attribute space pre-charge delay time, 
;//         <i> time = (PA + 1) * HCLK
;//     </h>
;//     <h> PC Card 1 Common Memory Space Register (PC1COM)
;//       <o2.31>     WC: Width of Common Memory Address Space
;//                       <0=> 8 bits <1=> 16 bits
;//       <o2.16..23> AC: Access Time for Common Memory <0-255>
;//         <i> This defines common memory space access time, 
;//         <i> time = (AC + 1) * HCLK
;//       <o2.8..11>  HT: Hold Time <0-15>
;//         <i> This defines hold time between data and chip select signal 
;//         <i> release, time = HT * HCLK
;//       <o2.0..7>   PC: Pre-charge Delay Time for Common Memory <0-255>
;//         <i> This defines common memory space pre-charge delay time, 
;//         <i> time = (PC + 1) * HCLK
;//     </h>
;//     <h> PC Card 1 I/O Space Register (PC1IO)
;//       <o3.31>     WI: Width of I/O Address Space
;//                       <0=> 8 bits <1=> 16 bits
;//       <o3.16..23> AI: Access Time for I/O Space <0-255>
;//         <i> This defines I/O space access time, time = (AI + 1) * HCLK
;//       <o3.8..11>  HT: Hold Time <0-15>
;//         <i> This defines hold time between data and chip select signal 
;//         <i> release, time = HT * HCLK
;//       <o3.0..7>   PI: Pre-charge Delay Time for I/O Space <0-255>
;//         <i> This defines I/O space pre-charge delay time, 
;//         <i> time = (PI + 1) * HCLK
;//     </h>
SMC_PCMCIA_SETUP    EQU 0
SMC_PC1ATTRIB_Val   EQU 0x00000000
SMC_PC1COM_Val      EQU 0x00000000
SMC_PC1IO_Val       EQU 0x00000000

;//     <h> PC Card 2 Attribute Space Register (PC2ATTRIB)
;//       <o1.31>     WA: Width of Attribute Address Space
;//                       <0=> 8 bits <1=> 16 bits
;//       <o1.16..23> AA: Access Time for Attribute Space <0-255>
;//         <i> This defines attribute space access time, time = (AA + 1) * HCLK
;//       <o1.8..11>  HT: Hold Time <0-15>
;//         <i> This defines hold time between nOE and nWE, 
;//         <i> time = (HT + 1) * HCLK
;//       <o1.0..7>   PA: Pre-charge Delay Time for Attribute Space <0-255>
;//         <i> This defines attribute space pre-charge delay time, 
;//         <i> time = (PA + 1) * HCLK
;//     </h>
;//     <h> PC Card 2 Common Memory Space Register (PC2COM)
;//       <o2.31>     WC: Width of Common Memory Address Space
;//                       <0=> 8 bits <1=> 16 bits
;//       <o2.16..23> AC: Access Time for Common Memory <0-255>
;//         <i> This defines common memory space access time, 
;//         <i> time = (AC + 1) * HCLK
;//       <o2.8..11>  HT: Hold Time <0-15>
;//         <i> This defines hold time between data and chip select signal 
;//         <i> release, time = HT * HCLK
;//       <o2.0..7>   PC: Pre-charge Delay Time for Common Memory <0-255>
;//         <i> This defines common memory space pre-charge delay time, 
;//         <i> time = (PC + 1) * HCLK
;//     </h>
;//     <h> PC Card 2 I/O Space Register (PC2IO)
;//       <o3.31>     WI: Width of I/O Address Space
;//                       <0=> 8 bits <1=> 16 bits
;//       <o3.16..23> AI: Access Time for I/O Space <0-255>
;//         <i> This defines I/O space access time, time = (AI + 1) * HCLK
;//       <o3.8..11>  HT: Hold Time <0-15>
;//         <i> This defines hold time between data and chip select signal 
;//         <i> release, time = HT * HCLK
;//       <o3.0..7>   PI: Pre-charge Delay Time for I/O Space <0-255>
;//         <i> This defines I/O space pre-charge delay time, 
;//         <i> time = (PI + 1) * HCLK
;//     </h>
SMC_PC2ATTRIB_Val   EQU 0x00000000
SMC_PC2COM_Val      EQU 0x00000000
SMC_PC2IO_Val       EQU 0x00000000

;//     <h> PCMCIA Control Register (PCMCIACON)
;//       <o0.8>      MPREG: Manual Control of PCREG Enable
;//       <o0.5>      WEN2: Wait State Enable for Card 2
;//       <o0.4>      WEN1: Wait State Enable for Card 1
;//       <o0.3>      PC2RST: PC Card 2 Reset
;//       <o0.2>      PC1RST: PC Card 1 Reset
;//       <o0.0..1>   PC12EN: PC Card 1 and 2 Enable
;//                     <0=> No cards enabled
;//                     <1=> One card enabled in CF mode (at 0x40000000)
;//                     <2=> One card enabled in PCMCIA mode (at 0x40000000)
;//                     <3=> Two cards enabled
;//     </h>
;//   </e>
;// </e>
SMC_PCMCIACON_Val   EQU 0x00000003


;----------------------- Synchronous Dynamic Memory Controller (SDMC) Defs -----

; Synchronous Dynamic Memory Controller (SDMC) User Interface
SDMC_BASE           EQU 0x80002400      ; SDMC Base Address
SDMC_GBLCNFG_OFS    EQU 0x004
SDMC_RFSHTMR_OFS    EQU 0x008
SDMC_BOOTSTAT_OFS   EQU 0x00C
SDMC_SDCSC0_OFS     EQU 0x010
SDMC_SDCSC1_OFS     EQU 0x014
SDMC_SDCSC2_OFS     EQU 0x018
SDMC_SDCSC3_OFS     EQU 0x01C

SDRAM_MODE_REG      EQU 0xC000C800      ; SDRAM Mode Register Address

; Constants
NORMAL_CMD          EQU 0x0             ; NORMAL        Command
PALL_CMD            EQU 0x1             ; Precharge All Command
MODE_CMD            EQU 0x2             ; MODE          Command
NOP_CMD             EQU 0x3             ; NOP           Command

CKE_BIT             EQU (1 << 31)       ; Clock Enable Bit (in register GBLCNFG)
SROMLL_MASK         EQU (1 <<  5)       ; SROMLL mask (in register SDCSCx)

;// <e> Synchronous Dynamic Memory Controller Configuration (SDMC)
SDMC_SETUP          EQU 1

;//   <e> Setup Memory Area Controlled by CS0
SDMC_CS0_SETUP      EQU 1
;//     <h> Synchronous Domain Chip Select 0 Register (SDCSC0)
;//       <o0.24>     AutoPrecharge: AutoPrecharge Enable
;//       <o0.20..21> RasToCas: Row Address Strobe To Column Address Strobe
;//                     <2=> RAS latency is 2
;//                     <3=> RAS latency is 3
;//       <o0.19>     WBL: Write Burst Disable
;//       <o0.16..18> CasLat: Column Address Strobe Latency
;//                     <1=> CAS latency is 2
;//                     <2=> CAS latency is 3
;//                     <3=> CAS latency is 4
;//                     <4=> CAS latency is 5
;//                     <5=> CAS latency is 6
;//                     <6=> CAS latency is 7
;//                     <7=> CAS latency is 8
;//       <o0.6>      2KPAGE: 2K PAGE Depth
;//       <o0.5>      SROMLL: SROM Lookalike
;//       <o0.4>      SROM512: SROM Page Depth 512
;//       <o0.3>      BankCount: Bank Count
;//                     <0=> Two bank devices
;//                     <1=> Four bank devices
;//       <o0.2>      EBW: External Bus Width
;//                     <0=> 32 bit,read bust length is 4
;//                     <1=> 16 bit,read bust length is 8, page depth is 512 bytes
;//     </h>
SDMC_SDCSC0_Val     EQU 0x01220028
;//   </e>

;//   <e> Setup Memory Area Controlled by CS1
SDMC_CS1_SETUP      EQU 0
;//     <h> Synchronous Domain Chip Select 1 Register (SDCSC1)
;//       <o0.24>     AutoPrecharge: AutoPrecharge Enable
;//       <o0.20..21> RasToCas: Row Address Strobe To Column Address Strobe
;//                     <2=> RAS latency is 2
;//                     <3=> RAS latency is 3
;//       <o0.19>     WBL: Write Burst Disable
;//       <o0.16..18> CasLat: Column Address Strobe Latency
;//                     <1=> CAS latency is 2
;//                     <2=> CAS latency is 3
;//                     <3=> CAS latency is 4
;//                     <4=> CAS latency is 5
;//                     <5=> CAS latency is 6
;//                     <6=> CAS latency is 7
;//                     <7=> CAS latency is 8
;//       <o0.6>      2KPAGE: 2K PAGE Depth
;//       <o0.5>      SROMLL: SROM Lookalike
;//       <o0.4>      SROM512: SROM Page Depth 512
;//       <o0.3>      BankCount: Bank Count
;//                     <0=> Two bank devices
;//                     <1=> Four bank devices
;//       <o0.2>      EBW: External Bus Width
;//                     <0=> 32 bit,read bust length is 4
;//                     <1=> 16 bit,read bust length is 8, page depth is 512 bytes
;//     </h>
SDMC_SDCSC1_Val     EQU 0x00000000
;//   </e>

;//   <e> Setup Memory Area Controlled by CS2
SDMC_CS2_SETUP      EQU 0
;//     <h> Synchronous Domain Chip Select 2 Register (SDCSC2)
;//       <o0.24>     AutoPrecharge: AutoPrecharge Enable
;//       <o0.20..21> RasToCas: Row Address Strobe To Column Address Strobe
;//                     <2=> RAS latency is 2
;//                     <3=> RAS latency is 3
;//       <o0.19>     WBL: Write Burst Disable
;//       <o0.16..18> CasLat: Column Address Strobe Latency
;//                     <1=> CAS latency is 2
;//                     <2=> CAS latency is 3
;//                     <3=> CAS latency is 4
;//                     <4=> CAS latency is 5
;//                     <5=> CAS latency is 6
;//                     <6=> CAS latency is 7
;//                     <7=> CAS latency is 8
;//       <o0.6>      2KPAGE: 2K PAGE Depth
;//       <o0.5>      SROMLL: SROM Lookalike
;//       <o0.4>      SROM512: SROM Page Depth 512
;//       <o0.3>      BankCount: Bank Count
;//                     <0=> Two bank devices
;//                     <1=> Four bank devices
;//       <o0.2>      EBW: External Bus Width
;//                     <0=> 32 bit,read bust length is 4
;//                     <1=> 16 bit,read bust length is 8, page depth is 512 bytes
;//     </h>
SDMC_SDCSC2_Val     EQU 0x00000000
;//   </e>

;//   <e> Setup Memory Area Controlled by CS3
SDMC_CS3_SETUP      EQU 0
;//     <h> Synchronous Domain Chip Select 3 Register (SDCSC3)
;//       <o0.24>     AutoPrecharge: AutoPrecharge Enable
;//       <o0.20..21> RasToCas: Row Address Strobe To Column Address Strobe
;//                     <2=> RAS latency is 2
;//                     <3=> RAS latency is 3
;//       <o0.19>     WBL: Write Burst Disable
;//       <o0.16..18> CasLat: Column Address Strobe Latency
;//                     <1=> CAS latency is 2
;//                     <2=> CAS latency is 3
;//                     <3=> CAS latency is 4
;//                     <4=> CAS latency is 5
;//                     <5=> CAS latency is 6
;//                     <6=> CAS latency is 7
;//                     <7=> CAS latency is 8
;//       <o0.6>      2KPAGE: 2K PAGE Depth
;//       <o0.5>      SROMLL: SROM Lookalike
;//       <o0.4>      SROM512: SROM Page Depth 512
;//       <o0.3>      BankCount: Bank Count
;//                     <0=> Two bank devices
;//                     <1=> Four bank devices
;//       <o0.2>      EBW: External Bus Width
;//                     <0=> 32 bit,read bust length is 4
;//                     <1=> 16 bit,read bust length is 8, page depth is 512 bytes
;//     </h>
SDMC_SDCSC3_Val     EQU 0x00000000
;//   </e>

;//   <h> Dynamic Memory Refresh Timer Register (DYNMREF)
;//     <o0.0..15>  REFCNT: Refresh Count <0x000-0xFFFF>
;//   </h>
SDMC_RFSHTMR_Val    EQU 0x0000030C

;// </e>


;----------------------- Memory Management Unit (MMU) Definitions --------------

; Constants
BUS_MASK        EQU     (3 << 30)       ; Bus settings mask in MMU config reg
CBIT_MASK       EQU     (1 <<  2)       ; DCache enable in MMU config reg
ABIT_MASK       EQU     (1 <<  1)       ; Alignment fault enable in MMU cfg reg
MBIT_MASK       EQU     (1 <<  0)       ; MMU enable in MMU config reg
SYNC_BIT        EQU     (1 << 30)       ; Bit to set synchro mode in MMU cfg reg
ICACHE_ENABLE   EQU     (1<<12)         ; Instruction Cache Enable Bit

LEVEL1_SECT_RO  EQU     0x00000812      ; Level 1 Section Descriptor for RO
LEVEL1_SECT_RW  EQU     0x00000C12      ; Level 1 Section Descriptor for RW
LEVEL1_COARSE   EQU     0x00000011      ; Level 1 Coarse page table desc
LEVEL1_FINE     EQU     0x00000013      ; Level 1 Fine page table desc
LEVEL2_LP_RO    EQU     0x00000AA1      ; Level 2 large page descriptor for RO
LEVEL2_LP_RW    EQU     0x00000FF1      ; Level 2 large page descriptor for RW
LEVEL2_SP_RO    EQU     0x00000AA2      ; Level 2 small page descriptor for RO
LEVEL2_SP_RW    EQU     0x00000FF2      ; Level 2 small page descriptor for RW
LEVEL2_TP_RO    EQU     0x00000023      ; Level 2 tiny page descriptor for RO
LEVEL2_TP_RW    EQU     0x00000033      ; Level 2 tiny page descriptor for RW

IRAM_BASE       EQU     0xB0000000      ; Internal RAM Memory Base
ERAM_BASE       EQU     0xC0000000      ; External SDRAM Memory Base
CS6_BASE        EQU     0x60000000      ; CPLD CS6 Area Base
CS7_BASE        EQU     0x70000000      ; CPLD CS7 Area Base
APB_BASE        EQU     0x80000000      ; Advanced Peripheral Bus Base

MMU_TTB_ADR     EQU     0xB0010000      ; Translation Table start address
MMU_VICTBL_ADR  EQU     0xB000FC00      ; Coarse page for VIC start address
VIC1_BASE       EQU     0x80008000      ; VIC1 base address
VIC1_REMAP_BASE EQU     0xFFFFF000      ; VIC1 remapped address

;// <e> Memory Management Unit Configuration (MMU)
MMU_SETUP       EQU     1

;//   <e> Remap VIC1 to address 0xFFFFF000
;//   </e>
VIC_REMAP_SETUP EQU     1

;//   <e> Instruction Cache Enable
;//   </e>
ICACHE_SETUP    EQU     1

;// </e>


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
                LDR     R0, =CSC_BASE

                ; Enable Fastbus mode
                MRC     p15, 0, R1, c1, c0, 0   ; Read MMU control register
                LDR     R2, =~(BUS_MASK:OR:CBIT_MASK:OR:ABIT_MASK:OR:MBIT_MASK)
                AND     R1, R1, R2
                MCR     p15, 0, R1, c1, c0, 0   ; Write MMU Control register
                NOP
                NOP
                NOP
                NOP
                NOP

                LDR     R1, =CLKSET_Val         ; Set selected clock settings
                STR     R1, [R0, #CLKSET_OFS]
                NOP
                NOP
                NOP
                NOP
                NOP

                ; IF CPU and bus clock are different switch to Sync Mode
                IF      ((CLKSET_Val:AND:HCLKDIV_MASK) != 0)
                MRC     p15, 0, R1, c1, c0, 0   ; Read MMU control register
                LDR     R2, =~(BUS_MASK:OR:CBIT_MASK:OR:ABIT_MASK:OR:MBIT_MASK)
                AND     R1, R1, R2
                ORR     R1, R1, #SYNC_BIT
                MCR     p15, 0, R1, c1, c0, 0   ; Write MMU Control register
                NOP
                NOP
                NOP
                NOP
                NOP
                ENDIF

                LDR     R1, =PWRCNT_Val
                STR     R1, [R0, #PWRCNT_OFS]
                MOV     R1, #USBDRESET_Val
                STR     R1, [R0, #USBDRESET_OFS]
                MOV     R1, #BMAR_Val
                STR     R1, [R0, #BMAR_OFS]

                IF      (BOOTCLR_Val != 0)
                MOV     R1, #BOOTCLR_Val
                STR     R1, [R0, #BOOTCLR_OFS]
                ENDIF
                ENDIF   ; of IF      CLOCK_SETUP != 0


; Static Memory Controller Setup (SMC) -----------------------------------------

                IF      SMC_SETUP != 0
                LDR     R0, =SMC_BASE

                IF      SMC_BCR0_SETUP != 0
                LDR     R1, =SMC_BCR0_Val
                STR     R1, [R0, #SMC_BCR0_OFS]
                ENDIF
                IF      SMC_BCR1_SETUP != 0
                LDR     R1, =SMC_BCR1_Val
                STR     R1, [R0, #SMC_BCR1_OFS]
                ENDIF
                IF      SMC_BCR2_SETUP != 0
                LDR     R1, =SMC_BCR2_Val
                STR     R1, [R0, #SMC_BCR2_OFS]
                ENDIF
                IF      SMC_BCR3_SETUP != 0
                LDR     R1, =SMC_BCR3_Val
                STR     R1, [R0, #SMC_BCR3_OFS]
                ENDIF
                IF      SMC_BCR6_SETUP != 0
                LDR     R1, =SMC_BCR6_Val
                STR     R1, [R0, #SMC_BCR6_OFS]
                ENDIF
                IF      SMC_BCR7_SETUP != 0
                LDR     R1, =SMC_BCR7_Val
                STR     R1, [R0, #SMC_BCR7_OFS]
                ENDIF

                IF      SMC_PCMCIA_SETUP != 0
                LDR     R1, =SMC_PC1ATTRIB_Val
                STR     R1, [R0, #SMC_PC1ATTRIB_OFS]
                LDR     R1, =SMC_PC1COM_Val
                STR     R1, [R0, #SMC_PC1COM_OFS]
                LDR     R1, =SMC_PC1IO_Val
                STR     R1, [R0, #SMC_PC1IO_OFS]
                LDR     R1, =SMC_PC2ATTRIB_Val
                STR     R1, [R0, #SMC_PC2ATTRIB_OFS]
                LDR     R1, =SMC_PC2COM_Val
                STR     R1, [R0, #SMC_PC2COM_OFS]
                LDR     R1, =SMC_PC2IO_Val
                STR     R1, [R0, #SMC_PC2IO_OFS]
                MOV     R1, #SMC_PCMCIACON_Val
                STR     R1, [R0, #SMC_PCMCIACON_OFS]
                ENDIF
                ENDIF   ; of IF      SMC_SETUP != 0


; Synchronous Dynamic Memory Controller Setup (SDMC) ---------------------------

                IF      (SDMC_SETUP != 0):LAND:(:LNOT::DEF:SDMC_NOINIT)
                LDR     R0, =SDMC_BASE

                IF      SDMC_CS0_SETUP != 0
                LDR     R1, =(SDMC_SDCSC0_Val:AND:~SROMLL_MASK)
                STR     R1, [R0, #SDMC_SDCSC0_OFS]
                ENDIF
                IF      SDMC_CS1_SETUP != 0
                LDR     R1, =(SDMC_SDCSC1_Val:AND:~SROMLL_MASK)
                STR     R1, [R0, #SDMC_SDCSC1_OFS]
                ENDIF
                IF      SDMC_CS2_SETUP != 0
                LDR     R1, =(SDMC_SDCSC2_Val:AND:~SROMLL_MASK)
                STR     R1, [R0, #SDMC_SDCSC2_OFS]
                ENDIF
                IF      SDMC_CS3_SETUP != 0
                LDR     R1, =(SDMC_SDCSC3_Val:AND:~SROMLL_MASK)
                STR     R1, [R0, #SDMC_SDCSC3_OFS]
                ENDIF

                MOV     R1, #0x14
                STR     R1, [R0, #SDMC_RFSHTMR_OFS]

                LDR     R1, =(CKE_BIT:OR:NOP_CMD)     ; NOP Command
                STR     R1, [R0, #SDMC_GBLCNFG_OFS]
                MOV     R6, #0x5000
Wait_SDRAM0     SUBS    R6, R6, #1
                BNE     Wait_SDRAM0

                LDR     R1, =(CKE_BIT:OR:PALL_CMD)    ; Precharge all Command
                STR     R1, [R0, #SDMC_GBLCNFG_OFS]
                MOV     R6, #0xF00
Wait_SDRAM1     SUBS    R6, R6, #1
                BNE     Wait_SDRAM1

                LDR     R1, =SDMC_RFSHTMR_Val
                STR     R1, [R0, #SDMC_RFSHTMR_OFS]

                LDR     R1, =(CKE_BIT:OR:MODE_CMD)    ; Mode Command
                LDR     R2, =SDRAM_MODE_REG
                STR     R1, [R0, #SDMC_GBLCNFG_OFS]
                LDR     R1, [R2, #0]

                MOV     R6, #0x10
Wait_SDRAM2     SUBS    R6, R6, #1
                BNE     Wait_SDRAM2

                IF      SDMC_CS0_SETUP != 0
                LDR     R1, =(SDMC_SDCSC0_Val:AND:~SROMLL_MASK)
                STR     R1, [R0, #SDMC_SDCSC0_OFS]
                ENDIF
                IF      SDMC_CS1_SETUP != 0
                LDR     R1, =(SDMC_SDCSC1_Val:AND:~SROMLL_MASK)
                STR     R1, [R0, #SDMC_SDCSC1_OFS]
                ENDIF
                IF      SDMC_CS2_SETUP != 0
                LDR     R1, =(SDMC_SDCSC2_Val:AND:~SROMLL_MASK)
                STR     R1, [R0, #SDMC_SDCSC2_OFS]
                ENDIF
                IF      SDMC_CS3_SETUP != 0
                LDR     R1, =(SDMC_SDCSC3_Val:AND:~SROMLL_MASK)
                STR     R1, [R0, #SDMC_SDCSC3_OFS]
                ENDIF
                LDR     R1, =(CKE_BIT:OR:NORMAL_CMD)  ; Normal Command
                STR     R1, [R0, #SDMC_GBLCNFG_OFS]
                MOV     R6, #0x10
Wait_SDRAM3     SUBS    R6, R6, #1
                BNE     Wait_SDRAM3

                IF      SDMC_CS0_SETUP != 0
                LDR     R1, =SDMC_SDCSC0_Val
                STR     R1, [R0, #SDMC_SDCSC0_OFS]
                ENDIF
                IF      SDMC_CS1_SETUP != 0
                LDR     R1, =SDMC_SDCSC1_Val
                STR     R1, [R0, #SDMC_SDCSC1_OFS]
                ENDIF
                IF      SDMC_CS2_SETUP != 0
                LDR     R1, =SDMC_SDCSC2_Val
                STR     R1, [R0, #SDMC_SDCSC2_OFS]
                ENDIF
                IF      SDMC_CS3_SETUP != 0
                LDR     R1, =SDMC_SDCSC3_Val
                STR     R1, [R0, #SDMC_SDCSC3_OFS]
                ENDIF
                ENDIF   ; of IF      (SDMC_SETUP != 0):LAND:(:LNOT::DEF:SDMC_NOINIT)


; MMU Setup --------------------------------------------------------------------

                IF      (MMU_SETUP != 0):LAND:(:LNOT::DEF:MMU_NOINIT)

                ; Clear Translation Table
                MOV     R0, #0
                MOV     R1, R0
                MOV     R2, R0
                MOV     R3, R0
                MOV     R4, R0
                MOV     R5, R0
                MOV     R6, R0
                MOV     R7, R0

                MOV     R8, #(4096/8)
                LDR     R9, =MMU_TTB_ADR
Clear_TBL_RAM   STMIA   R9!, {R0-R7}    ; Store 0
                SUBS    R8, R8, #1
                BNE     Clear_TBL_RAM

                ; Load correct values to map external SDRAM to its original 
                ; address 0xC0000000, and if remap for external SDRAM is active 
                ; map external SDRAM to address 0 also (size 64 MB)
                LDR     R9, =MMU_TTB_ADR

                LDR     R8, =(MMU_TTB_ADR:OR:((ERAM_BASE>>18):AND:0xFFFFFFFC))
                LDR     R0, =(ERAM_BASE:AND:0xFFF00000):OR:LEVEL1_SECT_RW
                SUB     R7, R0, #0x100000
                MOV     R10,#8          ; Repeat 8 times
Set_adr_SDRAM   CMP     R10,#4
                BNE     SDRAM_Cont
                ADD     R7, R7, #0x2000000
SDRAM_Cont      ADD     R0, R7, #0x100000
                ADD     R1, R0, #0x100000
                ADD     R2, R1, #0x100000
                ADD     R3, R2, #0x100000
                ADD     R4, R3, #0x100000
                ADD     R5, R4, #0x100000
                ADD     R6, R5, #0x100000
                ADD     R7, R6, #0x100000
                STMIA   R8!, {R0-R7}    ; Store table values for SDRAM (16MB)
                IF      :DEF:EXTSDRAM_MODE
                STMIA   R9!, {R0-R7}    ; Store table values for SDRAM for adr 0
                ENDIF
                SUBS    R10, R10, #1
                BNE     Set_adr_SDRAM

                ; Load correct values to map internal SRAM to its original 
                ; address 0xB0000000, and if remap for internal SRAM is active 
                ; map internal SRAM to address 0 also
                LDR     R8, =(MMU_TTB_ADR:OR:((IRAM_BASE>>18):AND:0xFFFFFFFC))
                LDR     R0, =(IRAM_BASE:AND:0xFFF00000):OR:LEVEL1_SECT_RW
                STR     R0, [R8, #0]
                IF      :DEF:INTSRAM_MODE
                STR     R0, [R9, #0]
                ENDIF

                ; Load correct values to map external NOR flash to its original 
                ; address 0x00000000 if remap is not used
                IF      (:LNOT::DEF:EXTSDRAM_MODE):LAND:(:LNOT::DEF:INTSRAM_MODE)
                LDR     R0, =LEVEL1_SECT_RW
                ADD     R1, R0, #0x100000
                ADD     R2, R1, #0x100000
                ADD     R3, R2, #0x100000
                ADD     R4, R3, #0x100000
                ADD     R5, R4, #0x100000
                ADD     R6, R5, #0x100000
                ADD     R7, R6, #0x100000
                STMIA   R9!, {R0-R7}    ; Store table values for address 0
                ENDIF
                
                ; Load correct values to map peripherals to theirs original 
                ; address 0x80000000
                LDR     R8, =(MMU_TTB_ADR:OR:((APB_BASE>>18):AND:0xFFFFFFFC))
                LDR     R0, =(APB_BASE:AND:0xFFF00000):OR:LEVEL1_SECT_RW
                STR     R0, [R8, #0]

                ; Load correct values to map CPLD to its original 
                ; addresses 0x60000000 and 0x70000000
                LDR     R8, =(MMU_TTB_ADR:OR:((CS6_BASE>>18):AND:0xFFFFFFFC))
                LDR     R0, =(CS6_BASE:AND:0xFFF00000):OR:LEVEL1_SECT_RW
                ADD     R1, R0, #0x100000
                ADD     R2, R1, #0x100000
                ADD     R3, R2, #0x100000
                ADD     R4, R3, #0x100000
                ADD     R5, R4, #0x100000
                STMIA   R8!, {R0-R5}
                LDR     R8, =(MMU_TTB_ADR:OR:((CS7_BASE>>18):AND:0xFFFFFFFC))
                LDR     R0, =(CS7_BASE:AND:0xFFF00000):OR:LEVEL1_SECT_RW
                SUB     R7, R0, #0x100000
                MOV     R10,#4          ; Repeat 4 times
Set_adr_CS7     ADD     R0, R7, #0x100000
                ADD     R1, R0, #0x100000
                ADD     R2, R1, #0x100000
                ADD     R3, R2, #0x100000
                ADD     R4, R3, #0x100000
                ADD     R5, R4, #0x100000
                ADD     R6, R5, #0x100000
                ADD     R7, R6, #0x100000
                STMIA   R8!, {R0-R7}    ; Store table values for CS7
                SUBS    R10, R10, #1
                BNE     Set_adr_CS7

                ; Remap VIC1 to address 0xFFFFF000 if requested
                IF      VIC_REMAP_SETUP != 0
                LDR     R8, =(MMU_TTB_ADR:OR:((VIC1_REMAP_BASE>>18):AND:0xFFFFFFFC))
                LDR     R0, =(MMU_VICTBL_ADR:AND:0xFFFFFC00):OR:LEVEL1_COARSE
                STR     R0, [R8, #0]
                LDR     R8, =(MMU_VICTBL_ADR:OR:((VIC1_REMAP_BASE>>10):AND:0x000003FC))
                LDR     R0, =(VIC1_BASE:AND:0xFFFFF000):OR:LEVEL2_SP_RW
                STR     R0, [R8, #0]
                ENDIF

                LDR     R0, =MMU_TTB_ADR
                MCR     p15, 0, R0, c2, c0, 0   ; Write TTB register
                MOV     R0, #0x01
                MCR     p15, 0, R0, c3, c0, 0   ; Write Domain Access Control
                MRC     p15, 0, R0, c1, c0, 0   ; Read MMU Control register
                IF      ICACHE_SETUP != 0
                LDR     R1, =(ICACHE_ENABLE:OR:MBIT_MASK)
                ELSE
                MOV     R1, #MBIT_MASK
                ENDIF
                ORR     R0, R0, R1
                MCR     p15, 0, R0, c1, c0, 0   ; Write MMU Control register
                NOP
                NOP
                NOP
                NOP
                NOP

                ENDIF   ; of IF      (MMU_SETUP != 0):LAND:(:LNOT::DEF:MMU_NOINIT)


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
