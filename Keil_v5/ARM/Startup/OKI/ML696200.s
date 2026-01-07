;/*****************************************************************************/
;/* ML696200.S: Startup file for OKI ML69620x device series                   */
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
; *  The ML696200.S code is executed after CPU Reset. This file may be 
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


;----------------------- Global Constants Definitions --------------------------

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
IRAM_BASE       EQU     0x50000000      ; On-chip RAM
SRAM_BASE       EQU     0xD0000000      ; Off-chip SRAM
DRAM_BASE       EQU     0xC0000000      ; Off-chip DRAM
                IF      :DEF:IRAM_MODE
RAM_BASE        EQU     IRAM_BASE
RAM_MAP         EQU     10
                ENDIF
                IF      :DEF:SRAM_MODE
RAM_BASE        EQU     SRAM_BASE
RAM_MAP         EQU     8
                ENDIF
                IF      :DEF:DRAM_MODE
RAM_BASE        EQU     DRAM_BASE
RAM_MAP         EQU     9
                ENDIF
CCR_BASE        EQU     0x80000000      ; Chip Configuration Base
SCR_BASE        EQU     0xB8000000      ; System Control Base
EMCR_BASE       EQU     0x78100000      ; External Memory Control Base
DCR_BASE        EQU     0x78180000      ; DRAM Control Base

; Constants
WRITE_EN        EQU     0x0000003C      ; Enable write to Configuration Register


;----------------------- Stack/Heap Definitons ---------------------------------

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


;----------------------- Power Management Definitions --------------------------

; Power Management definitions
CCR_MCKST_OFS   EQU     0x04            ; Module Clock Stop Register      Offset
SCR_CLKSTP_OFS  EQU     0x04            ; Clock Stop Register             Offset
SCR_CGBCNT0_OFS EQU     0x08            ; Clock Select Register           Offset

;// <e> Power Management
;//   <h> MCKST: Module Clock Stop Register
;//     <o1.0>  DMAC Clock             <0=> Enabled  <1=> Disabled
;//     <o1.1>  DRAM Controller Clock  <0=> Enabled  <1=> Disabled
;//     <o1.2>  I2S Transmitter Clock  <0=> Enabled  <1=> Disabled
;//     <o1.3>  I2S Receiver Clock     <0=> Enabled  <1=> Disabled
;//     <o1.4>  NAND Controller Clock  <0=> Enabled  <1=> Disabled
;//     <o1.5>  NAND Buffer Clock      <0=> Enabled  <1=> Disabled
;//     <o1.6>  XSYS Pin Clock         <0=> Enabled  <1=> Disabled
;//   </h>
;//   <h> CLKSTOP: Clock Stop Register
;//     <o2.0>  SIO Clock              <0=> Enabled  <1=> Disabled
;//     <o2.1>  TIC Clock              <0=> Enabled  <1=> Disabled
;//     <o2.2>  CPU Group Clock        <0=> Enabled  <1=> Disabled
;//     <o2.7>  STOP Mode              <0=> Enabled  <1=> Disabled
;//   </h>
;//   <h> CGBCNT0: Clock Control Register 0
;//     <o3.0..2> FCLKGEAR: Operating Clock Frequency
;//               <0=> 120MHz   <1=> 60MHz    <2=> 30MHz    <3=> 15MHz
;//               <4=> 7.5MHz   <5=> 3.75MHz  <7=> 32kHz
;//     <o3.4..6> CCLKGEAR: Various Peripheral Clock
;//               <0=> 120MHz   <7=> 32kHz
;//     <e3.7>   HCLKGEAR1: AHB Bus Frequency Division
;//       <o3.3>   HCLKGEAR0: Select HCLK Divider
;//                 <0=> CPUCLK/2  <1=> CPUCLK/4
;//     </e>
;//   </h>
;// </e>
PM_SETUP        EQU     0
MCKST_Val       EQU     0x00000000
CLKSTP_Val      EQU     0x00000000
CGBCNT0_Val     EQU     0x00000080


;----------------------- External Memory Definitions ---------------------------

; External Memory definitions
EMCR_BWC_OFS    EQU     0x00            ; Bus Width Control               Offset
EMCR_ROMAC_OFS  EQU     0x04            ; ROM Access Control              Offset
EMCR_RAMAC_OFS  EQU     0x08            ; SRAM Access Control             Offset
EMCR_IO0AC_OFS  EQU     0x0C            ; I/O Bank 0 Control              Offset
EMCR_IO1AC_OFS  EQU     0x0C            ; I/O Bank 1 Control              Offset
DCR_DBWC_OFS    EQU     0x00            ; DRAM Bus Width Control          Offset
DCR_DRMC_OFS    EQU     0x04            ; DRAM Control                    Offset
DCR_DRPC_OFS    EQU     0x08            ; DRAM Characteristics Control    Offset
DCR_SDMD_OFS    EQU     0x0C            ; SDRAM Mode Control              Offset
DCR_DCMD_OFS    EQU     0x10            ; DRAM Command                    Offset
DCR_RFSH0_OFS   EQU     0x14            ; DRAM Refresh Cycle Control 0    Offset
DCR_PDWC_OFS    EQU     0x18            ; DRAM Power Down Control         Offset
DCR_RFSH1_OFS   EQU     0x1C            ; DRAM Refresh Cycle Control 1    Offset

; DRAM Command definitions
DCMD_NOP        EQU     0x00            ; No operation
DCMD_PALL       EQU     0x04            ; Pre-charge all banks Command
DCMD_REF        EQU     0x05            ; CBR Refresh Command
DCMD_SELF       EQU     0x06            ; Self Refresh Start Command
DCMD_SREX       EQU     0x07            ; Self Refresh Stop Command

;// <e.0> External Memory Controller
;//   <h> BWC: Bus Width Control
;//     <o1.2..3>  ROMBW: ROM Bus Width
;//       <0=> Not Present  <2=> 16-bits
;//     <o1.4..5>  RAMBW: SRAM Bus Width
;//       <0=> Not Present  <2=> 16-bits
;//     <o1.6..7>  IO0BW: I/O Bank 0 Bus Width
;//       <0=> Not Present  <2=> 16-bits
;//     <o2.6..7>  IO1BW: I/O Bank 1 Bus Width
;//       <0=> Not Present  <2=> 16-bits
;//   </h>
;//   <h> ROMAC: ROM Access Control
;//     <o2.0..2>  ROMTYPE: ROM Timming (in cycles)
;//       <0=> Address Setup = 1, OE/WE =  1, Read off = 1, Burst = 1
;//       <1=> Address Setup = 1, OE/WE =  2, Read off = 2, Burst = 2
;//       <2=> Address Setup = 1, OE/WE =  3, Read off = 3, Burst = 3
;//       <3=> Address Setup = 1, OE/WE =  5, Read off = 3, Burst = 3
;//       <4=> Address Setup = 2, OE/WE =  8, Read off = 4, Burst = 5
;//       <5=> Address Setup = 2, OE/WE = 10, Read off = 5, Burst = 6
;//       <6=> Address Setup = 2, OE/WE = 13, Read off = 6, Burst = 7
;//       <7=> Address Setup = 2, OE/WE = 16, Read off = 7, Burst = 9
;//     <o2.4>     ROMBRST: ROM Page Mode
;//   </h>
;//   <h> RAMAC: SRAM Access Control
;//     <o3.0..2>  RAMTYPE: SRAM Timming (in cycles)
;//       <0=> Address Setup = 1, OE/WE =  1, Read off = 1, Burst = 1
;//       <1=> Address Setup = 1, OE/WE =  2, Read off = 2, Burst = 2
;//       <2=> Address Setup = 1, OE/WE =  3, Read off = 3, Burst = 3
;//       <3=> Address Setup = 1, OE/WE =  5, Read off = 3, Burst = 3
;//       <4=> Address Setup = 2, OE/WE =  8, Read off = 4, Burst = 5
;//       <5=> Address Setup = 2, OE/WE = 10, Read off = 5, Burst = 6
;//       <6=> Address Setup = 2, OE/WE = 13, Read off = 6, Burst = 7
;//       <7=> Address Setup = 2, OE/WE = 16, Read off = 7, Burst = 9
;//     <o3.4>     RAMBRST: SRAM Page Mode
;//   </h>
;//   <h> IO0AC: External I/O Bank 0 Access Control
;//     <o4.0..2>  IO0TYPE: I/O Bank 0 Timming (in cycles)
;//       <0=> Address Setup = 1, OE/WE =  1, Read off = 1
;//       <1=> Address Setup = 1, OE/WE =  4, Read off = 3
;//       <2=> Address Setup = 1, OE/WE =  6, Read off = 4
;//       <3=> Address Setup = 2, OE/WE =  8, Read off = 5
;//       <4=> Address Setup = 2, OE/WE = 12, Read off = 7
;//       <5=> Address Setup = 2, OE/WE = 16, Read off = 8
;//       <6=> Address Setup = 3, OE/WE = 20, Read off = 9
;//       <7=> Address Setup = 4, OE/WE = 24, Read off = 11
;//   </h>
;//   <h> IO1AC: External I/O Bank 1 Access Control
;//     <o5.0..2>  IO1TYPE: I/O Bank 1 Timming (in cycles)
;//       <0=> Address Setup = 1, OE/WE =  1, Read off = 1
;//       <1=> Address Setup = 1, OE/WE =  4, Read off = 3
;//       <2=> Address Setup = 1, OE/WE =  6, Read off = 4
;//       <3=> Address Setup = 2, OE/WE =  8, Read off = 5
;//       <4=> Address Setup = 2, OE/WE = 12, Read off = 7
;//       <5=> Address Setup = 2, OE/WE = 16, Read off = 8
;//       <6=> Address Setup = 3, OE/WE = 20, Read off = 9
;//       <7=> Address Setup = 4, OE/WE = 24, Read off = 11
;//   </h>
;//   <e.1> DRAM Controller
;//     <h> DBWC: DRAM Bus Width Control
;//       <o6.0..1>  BWDRAM: DRAM Bus Width
;//         <0=> Not Present  <1=> 8-bits  <2=> 16-bits
;//     </h>
;//     <h> DRMC: DRAM Control
;//       <o7.0..1>  AMUX: Column Length
;//         <0=> 8-bits  <1=> 9-bits  <2=> 10-bits
;//       <o7.2>     ARCH: DRAM Type
;//         <0=> SDRAM
;//       <o7.4>     PRELAT: SDRAM Pre-charge latency
;//         <0=> 2 cycles  <1=> CAS latency
;//       <o7.6>     PDWN: SDRAM Power Down Mode
;//         <0=> Disable automatic shift  <1=> Enable automatic shift
;//       <o7.7>     RFRSH: CBR - CAS before RAS Refresh
;//         <0=> Stop distributed CBR  <1=> Enable distributed CBR
;//     </h>
;//     <h> DRPC: DRAM Characteristics Control
;//       <o8.0..3>  DRAMSPEC: DRAM Timming (in cycles)
;//         <0=>  SDRAM:RCD=1,RAS=2,RP=1,DPL=1
;//         <1=>  SDRAM:RCD=1,RAS=3,RP=1,DPL=1
;//         <2=>  SDRAM:RCD=2,RAS=3,RP=2,DPL=1
;//         <3=>  SDRAM:RCD=2,RAS=4,RP=2,DPL=1
;//         <4=>  SDRAM:RCD=2,RAS=4,RP=2,DPL=2
;//         <5=>  SDRAM:RCD=2,RAS=5,RP=2,DPL=1
;//         <6=>  SDRAM:RCD=2,RAS=5,RP=2,DPL=2
;//         <7=>  SDRAM:RCD=2,RAS=5,RP=3,DPL=1
;//         <8=>  SDRAM:RCD=3,RAS=5,RP=3,DPL=2
;//         <9=>  SDRAM:RCD=3,RAS=6,RP=3,DPL=2
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
;//       <o11.0..10>  RFSEL1: DRAM Refresh Period Divider <8-1030>
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
IO0AC_Val       EQU     0x00000007
IO1AC_Val       EQU     0x00000007
DBWC_Val        EQU     0x00000002
DRMC_Val        EQU     0x00000080
DRPC_Val        EQU     0x00000009
SDMD_Val        EQU     0x00000080
RFSH0_Val       EQU     0x00000001
RFSH1_Val       EQU     0x000003A9
PDWC_Val        EQU     0x0000000F


;----------------------- Memory Protection and Cache Definitions ---------------

; Constants
MPU_EN_BIT      EQU     (1<<0)          ; Memory Protection Unit Enable Bit
DCACHE_EN_BIT   EQU     (1<<2)          ; Data        Cache      Enable Bit
ICACHE_EN_BIT   EQU     (1<<12)         ; Instruction Cache      Enable Bit


;// <e> Memory Protection Unit and Cache
;//   <h> Memory Region 0
;//     <o1.12..31> Region Base <0x00000-0xFFFFF>
;//       <i> Region Base must be aligned to an area size boundary.
;//     <o1.1..5> Area Size
;//       <11=>   4kB  <12=>   8kB  <13=>  16kB  <14=>  32kB 
;//       <15=>  64kB  <16=> 128kB  <17=> 256kB  <18=> 512kB
;//       <19=>   1MB  <20=>   2MB  <21=>   4MB  <22=>   8MB
;//       <23=>  16MB  <24=>  32MB  <25=>  64MB  <26=> 128MB
;//       <27=> 256MB  <28=> 512MB  <29=>   1GB  <30=>   2GB
;//       <31=>   4GB
;//     <o1.0> Region Enable
;//   </h>
;//   <h> Memory Region 1
;//     <o2.12..31> Region Base <0x00000-0xFFFFF>
;//       <i> Region Base must be aligned to an area size boundary.
;//     <o2.1..5> Area Size
;//       <11=>   4kB  <12=>   8kB  <13=>  16kB  <14=>  32kB 
;//       <15=>  64kB  <16=> 128kB  <17=> 256kB  <18=> 512kB
;//       <19=>   1MB  <20=>   2MB  <21=>   4MB  <22=>   8MB
;//       <23=>  16MB  <24=>  32MB  <25=>  64MB  <26=> 128MB
;//       <27=> 256MB  <28=> 512MB  <29=>   1GB  <30=>   2GB
;//       <31=>   4GB
;//     <o2.0> Region Enable
;//   </h>
;//   <h> Memory Region 2
;//     <o3.12..31> Region Base <0x00000-0xFFFFF>
;//       <i> Region Base must be aligned to an area size boundary.
;//     <o3.1..5> Area Size
;//       <11=>   4kB  <12=>   8kB  <13=>  16kB  <14=>  32kB 
;//       <15=>  64kB  <16=> 128kB  <17=> 256kB  <18=> 512kB
;//       <19=>   1MB  <20=>   2MB  <21=>   4MB  <22=>   8MB
;//       <23=>  16MB  <24=>  32MB  <25=>  64MB  <26=> 128MB
;//       <27=> 256MB  <28=> 512MB  <29=>   1GB  <30=>   2GB
;//       <31=>   4GB
;//     <o3.0> Region Enable
;//   </h>
;//   <h> Memory Region 3
;//     <o4.12..31> Region Base <0x00000-0xFFFFF>
;//       <i> Region Base must be aligned to an area size boundary.
;//     <o4.1..5> Area Size
;//       <11=>   4kB  <12=>   8kB  <13=>  16kB  <14=>  32kB 
;//       <15=>  64kB  <16=> 128kB  <17=> 256kB  <18=> 512kB
;//       <19=>   1MB  <20=>   2MB  <21=>   4MB  <22=>   8MB
;//       <23=>  16MB  <24=>  32MB  <25=>  64MB  <26=> 128MB
;//       <27=> 256MB  <28=> 512MB  <29=>   1GB  <30=>   2GB
;//       <31=>   4GB
;//     <o4.0> Region Enable
;//   </h>
;//   <h> Memory Region 4
;//     <o5.12..31> Region Base <0x00000-0xFFFFF>
;//       <i> Region Base must be aligned to an area size boundary.
;//     <o5.1..5> Area Size
;//       <11=>   4kB  <12=>   8kB  <13=>  16kB  <14=>  32kB 
;//       <15=>  64kB  <16=> 128kB  <17=> 256kB  <18=> 512kB
;//       <19=>   1MB  <20=>   2MB  <21=>   4MB  <22=>   8MB
;//       <23=>  16MB  <24=>  32MB  <25=>  64MB  <26=> 128MB
;//       <27=> 256MB  <28=> 512MB  <29=>   1GB  <30=>   2GB
;//       <31=>   4GB
;//     <o5.0> Region Enable
;//   </h>
;//   <h> Memory Region 5
;//     <o6.12..31> Region Base <0x00000-0xFFFFF>
;//       <i> Region Base must be aligned to an area size boundary.
;//     <o6.1..5> Area Size
;//       <11=>   4kB  <12=>   8kB  <13=>  16kB  <14=>  32kB 
;//       <15=>  64kB  <16=> 128kB  <17=> 256kB  <18=> 512kB
;//       <19=>   1MB  <20=>   2MB  <21=>   4MB  <22=>   8MB
;//       <23=>  16MB  <24=>  32MB  <25=>  64MB  <26=> 128MB
;//       <27=> 256MB  <28=> 512MB  <29=>   1GB  <30=>   2GB
;//       <31=>   4GB
;//     <o6.0> Region Enable
;//   </h>
;//   <h> Memory Region 6
;//     <o7.12..31> Region Base <0x00000-0xFFFFF>
;//       <i> Region Base must be aligned to an area size boundary.
;//     <o7.1..5> Area Size
;//       <11=>   4kB  <12=>   8kB  <13=>  16kB  <14=>  32kB 
;//       <15=>  64kB  <16=> 128kB  <17=> 256kB  <18=> 512kB
;//       <19=>   1MB  <20=>   2MB  <21=>   4MB  <22=>   8MB
;//       <23=>  16MB  <24=>  32MB  <25=>  64MB  <26=> 128MB
;//       <27=> 256MB  <28=> 512MB  <29=>   1GB  <30=>   2GB
;//       <31=>   4GB
;//     <o7.0> Region Enable
;//   </h>
;//   <h> Memory Region 7
;//     <o8.12..31> Region Base <0x00000-0xFFFFF>
;//       <i> Region Base must be aligned to an area size boundary.
;//     <o8.1..5> Area Size
;//       <11=>   4kB  <12=>   8kB  <13=>  16kB  <14=>  32kB 
;//       <15=>  64kB  <16=> 128kB  <17=> 256kB  <18=> 512kB
;//       <19=>   1MB  <20=>   2MB  <21=>   4MB  <22=>   8MB
;//       <23=>  16MB  <24=>  32MB  <25=>  64MB  <26=> 128MB
;//       <27=> 256MB  <28=> 512MB  <29=>   1GB  <30=>   2GB
;//       <31=>   4GB
;//     <o8.0> Region Enable
;//   </h>
;//   <h> Data Cache Configuration
;//     <o9.7> Region 7 Data Cacheable
;//     <o9.6> Region 6 Data Cacheable
;//     <o9.5> Region 5 Data Cacheable
;//     <o9.4> Region 4 Data Cacheable
;//     <o9.3> Region 3 Data Cacheable
;//     <o9.2> Region 2 Data Cacheable
;//     <o9.1> Region 1 Data Cacheable
;//     <o9.0> Region 0 Data Cacheable
;//   </h>
;//   <h> Instruction Cache Configuration
;//     <o10.7> Region 7 Instructions Cacheable
;//     <o10.6> Region 6 Instructions Cacheable
;//     <o10.5> Region 5 Instructions Cacheable
;//     <o10.4> Region 4 Instructions Cacheable
;//     <o10.3> Region 3 Instructions Cacheable
;//     <o10.2> Region 2 Instructions Cacheable
;//     <o10.1> Region 1 Instructions Cacheable
;//     <o10.0> Region 0 Instructions Cacheable
;//   </h>
;//   <h> Data Write Buffer Configuration
;//     <o11.7> Region 7 Data Bufferable
;//     <o11.6> Region 6 Data Bufferable
;//     <o11.5> Region 5 Data Bufferable
;//     <o11.4> Region 4 Data Bufferable
;//     <o11.3> Region 3 Data Bufferable
;//     <o11.2> Region 2 Data Bufferable
;//     <o11.1> Region 1 Data Bufferable
;//     <o11.0> Region 0 Data Bufferable
;//   </h>
;//   <h> Data Access Permission Configuration
;//     <o12.28..31> Region 7 Access Permission
;//       <0=> Privileged: No access         |  User: No access
;//       <1=> Privileged: Read/Write access |  User: No access
;//       <2=> Privileged: Read/Write access |  User: Read-only
;//       <3=> Privileged: Read/Write access |  User: Read/Write access
;//       <5=> Privileged: Read-only         |  User: No access
;//       <6=> Privileged: Read-only         |  User: Read-only
;//     <o12.24..27> Region 6 Access Permission
;//       <0=> Privileged: No access         |  User: No access
;//       <1=> Privileged: Read/Write access |  User: No access
;//       <2=> Privileged: Read/Write access |  User: Read-only
;//       <3=> Privileged: Read/Write access |  User: Read/Write access
;//       <5=> Privileged: Read-only         |  User: No access
;//       <6=> Privileged: Read-only         |  User: Read-only
;//     <o12.20..23> Region 5 Access Permission
;//       <0=> Privileged: No access         |  User: No access
;//       <1=> Privileged: Read/Write access |  User: No access
;//       <2=> Privileged: Read/Write access |  User: Read-only
;//       <3=> Privileged: Read/Write access |  User: Read/Write access
;//       <5=> Privileged: Read-only         |  User: No access
;//       <6=> Privileged: Read-only         |  User: Read-only
;//     <o12.16..19> Region 4 Access Permission
;//       <0=> Privileged: No access         |  User: No access
;//       <1=> Privileged: Read/Write access |  User: No access
;//       <2=> Privileged: Read/Write access |  User: Read-only
;//       <3=> Privileged: Read/Write access |  User: Read/Write access
;//       <5=> Privileged: Read-only         |  User: No access
;//       <6=> Privileged: Read-only         |  User: Read-only
;//     <o12.12..15> Region 3 Access Permission
;//       <0=> Privileged: No access         |  User: No access
;//       <1=> Privileged: Read/Write access |  User: No access
;//       <2=> Privileged: Read/Write access |  User: Read-only
;//       <3=> Privileged: Read/Write access |  User: Read/Write access
;//       <5=> Privileged: Read-only         |  User: No access
;//       <6=> Privileged: Read-only         |  User: Read-only
;//     <o12.8..11> Region 2 Access Permission
;//       <0=> Privileged: No access         |  User: No access
;//       <1=> Privileged: Read/Write access |  User: No access
;//       <2=> Privileged: Read/Write access |  User: Read-only
;//       <3=> Privileged: Read/Write access |  User: Read/Write access
;//       <5=> Privileged: Read-only         |  User: No access
;//       <6=> Privileged: Read-only         |  User: Read-only
;//     <o12.4..7> Region 1 Access Permission
;//       <0=> Privileged: No access         |  User: No access
;//       <1=> Privileged: Read/Write access |  User: No access
;//       <2=> Privileged: Read/Write access |  User: Read-only
;//       <3=> Privileged: Read/Write access |  User: Read/Write access
;//       <5=> Privileged: Read-only         |  User: No access
;//       <6=> Privileged: Read-only         |  User: Read-only
;//     <o12.0..3> Region 0 Access Permission
;//       <0=> Privileged: No access         |  User: No access
;//       <1=> Privileged: Read/Write access |  User: No access
;//       <2=> Privileged: Read/Write access |  User: Read-only
;//       <3=> Privileged: Read/Write access |  User: Read/Write access
;//       <5=> Privileged: Read-only         |  User: No access
;//       <6=> Privileged: Read-only         |  User: Read-only
;//   </h>
;//   <h> Instruction Access Permission Configuration
;//     <o13.28..31> Region 7 Access Permission
;//       <0=> Privileged: No access         |  User: No access
;//       <1=> Privileged: Read/Write access |  User: No access
;//       <2=> Privileged: Read/Write access |  User: Read-only
;//       <3=> Privileged: Read/Write access |  User: Read/Write access
;//       <5=> Privileged: Read-only         |  User: No access
;//       <6=> Privileged: Read-only         |  User: Read-only
;//     <o13.24..27> Region 6 Access Permission
;//       <0=> Privileged: No access         |  User: No access
;//       <1=> Privileged: Read/Write access |  User: No access
;//       <2=> Privileged: Read/Write access |  User: Read-only
;//       <3=> Privileged: Read/Write access |  User: Read/Write access
;//       <5=> Privileged: Read-only         |  User: No access
;//       <6=> Privileged: Read-only         |  User: Read-only
;//     <o13.20..23> Region 5 Access Permission
;//       <0=> Privileged: No access         |  User: No access
;//       <1=> Privileged: Read/Write access |  User: No access
;//       <2=> Privileged: Read/Write access |  User: Read-only
;//       <3=> Privileged: Read/Write access |  User: Read/Write access
;//       <5=> Privileged: Read-only         |  User: No access
;//       <6=> Privileged: Read-only         |  User: Read-only
;//     <o13.16..19> Region 4 Access Permission
;//       <0=> Privileged: No access         |  User: No access
;//       <1=> Privileged: Read/Write access |  User: No access
;//       <2=> Privileged: Read/Write access |  User: Read-only
;//       <3=> Privileged: Read/Write access |  User: Read/Write access
;//       <5=> Privileged: Read-only         |  User: No access
;//       <6=> Privileged: Read-only         |  User: Read-only
;//     <o13.12..15> Region 3 Access Permission
;//       <0=> Privileged: No access         |  User: No access
;//       <1=> Privileged: Read/Write access |  User: No access
;//       <2=> Privileged: Read/Write access |  User: Read-only
;//       <3=> Privileged: Read/Write access |  User: Read/Write access
;//       <5=> Privileged: Read-only         |  User: No access
;//       <6=> Privileged: Read-only         |  User: Read-only
;//     <o13.8..11> Region 2 Access Permission
;//       <0=> Privileged: No access         |  User: No access
;//       <1=> Privileged: Read/Write access |  User: No access
;//       <2=> Privileged: Read/Write access |  User: Read-only
;//       <3=> Privileged: Read/Write access |  User: Read/Write access
;//       <5=> Privileged: Read-only         |  User: No access
;//       <6=> Privileged: Read-only         |  User: Read-only
;//     <o13.4..7> Region 1 Access Permission
;//       <0=> Privileged: No access         |  User: No access
;//       <1=> Privileged: Read/Write access |  User: No access
;//       <2=> Privileged: Read/Write access |  User: Read-only
;//       <3=> Privileged: Read/Write access |  User: Read/Write access
;//       <5=> Privileged: Read-only         |  User: No access
;//       <6=> Privileged: Read-only         |  User: Read-only
;//     <o13.0..3> Region 0 Access Permission
;//       <0=> Privileged: No access         |  User: No access
;//       <1=> Privileged: Read/Write access |  User: No access
;//       <2=> Privileged: Read/Write access |  User: Read-only
;//       <3=> Privileged: Read/Write access |  User: Read/Write access
;//       <5=> Privileged: Read-only         |  User: No access
;//       <6=> Privileged: Read-only         |  User: Read-only
;//   </h>
;// </e>
MPU_SETUP       EQU     1
MEM_REG_0_Val   EQU     0x0000003F
MEM_REG_1_Val   EQU     0x00000035
MEM_REG_2_Val   EQU     0x50000035
MEM_REG_3_Val   EQU     0xC0000035
MEM_REG_4_Val   EQU     0xC8000025
MEM_REG_5_Val   EQU     0xD0000035
MEM_REG_6_Val   EQU     0x00000000
MEM_REG_7_Val   EQU     0x00000000
DCACHE_CFG_Val  EQU     0x0000003E
ICACHE_CFG_Val  EQU     0x0000003E
BUFFER_CFG_Val  EQU     0x00000000
DMEM_ACCESS_Val EQU     0x00363333
IMEM_ACCESS_Val EQU     0x00363333


;----------------------- CODE --------------------------------------------------

                PRESERVE8
                

; Area Definition and Entry Point
;  Startup Code must be linked first at Address at which it expects to run.

                AREA    RESET, CODE, READONLY
                ARM

                IMPORT  IRQ_Handler

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


; Setup Power Management -------------------------------------------------------

                IF      PM_SETUP != 0
                LDR     R0, =CCR_BASE
                MOV     R1, #WRITE_EN   
                LDR     R2, =MCKST_Val
                STR     R1, [R0, #CCR_MCKST_OFS]  ; Enable Write to Register
                STR     R2, [R0, #CCR_MCKST_OFS]
                LDR     R0, =SCR_BASE
                LDR     R2, =CLKSTP_Val
                STR     R1, [R0, #SCR_CLKSTP_OFS]
                STR     R2, [R0, #SCR_CLKSTP_OFS]
                LDR     R2, =CGBCNT0_Val
                STR     R1, [R0, #SCR_CGBCNT0_OFS]
                STR     R2, [R0, #SCR_CGBCNT0_OFS]
                ENDIF


; Setup External Memory Controller ---------------------------------------------

                LDR     R0, =(12000/4)  ; Wait at least 200us after Power-On
DRAM_Wait       SUBS    R0, R0, #1      ;  which is required for DRAM
                BNE     DRAM_Wait       ;  12000 cycles @ HCLK = 60MHz

                IF      (EMC_SETUP:AND:1) != 0

                LDR     R0, =EMCR_BASE
                LDR     R1, =BWC_Val
                STR     R1, [R0, #EMCR_BWC_OFS]
                LDR     R1, =ROMAC_Val
                STR     R1, [R0, #EMCR_ROMAC_OFS]
                LDR     R1, =RAMAC_Val
                STR     R1, [R0, #EMCR_RAMAC_OFS]
                LDR     R1, =IO0AC_Val
                STR     R1, [R0, #EMCR_IO0AC_OFS]
                LDR     R1, =IO1AC_Val
                STR     R1, [R0, #EMCR_IO1AC_OFS]


; Setup DRAM Controller --------------------------------------------------------

                IF      (EMC_SETUP:AND:2) != 0

                LDR     R0, =DCR_BASE
                LDR     R1, =RFSH0_Val
                STR     R1, [R0, #DCR_RFSH0_OFS]
                LDR     R1, =RFSH1_Val
                STR     R1, [R0, #DCR_RFSH1_OFS]
                LDR     R1, =DBWC_Val
                STR     R1, [R0, #DCR_DBWC_OFS]
                LDR     R1, =DRMC_Val
                STR     R1, [R0, #DCR_DRMC_OFS]
                LDR     R1, =DRPC_Val
                STR     R1, [R0, #DCR_DRPC_OFS]
                LDR     R1, =SDMD_Val
                STR     R1, [R0, #DCR_SDMD_OFS]
                LDR     R1, =PDWC_Val
                STR     R1, [R0, #DCR_PDWC_OFS]
                MOV     R1, #DCMD_PALL
                STR     R1, [R0, #DCR_DCMD_OFS]
                MOV     R1, #DCMD_REF
                MOV     R2, #8
DRAM_Loop       STR     R1, [R0, #DCR_DCMD_OFS]
                SUBS    R2, R2, #1
                BNE     DRAM_Loop

                ENDIF

                ENDIF


; Copy Exception Vectors to Internal RAM ---------------------------------------

                IF      :DEF:RAM_INTVEC
                ADR     R8, Vectors     ; Source
                LDR     R9, =RAM_BASE   ; Destination
                LDMIA   R8!, {R0-R7}    ; Load Vectors 
                STMIA   R9!, {R0-R7}    ; Store Vectors 
                LDMIA   R8!, {R0-R7}    ; Load Handler Addresses 
                STMIA   R9!, {R0-R7}    ; Store Handler Addresses
                ENDIF


; Remap RAM (selected by xRAM_MODE) to address 0 -------------------------------

SCR_RMPCON_OFS  EQU     0x10            ; Remap Control Register

                IF      :DEF:REMAP
                LDR     R0, =SCR_BASE
                MOV     R1, #WRITE_EN   ; Protection Code (Write Enable)
                MOV     R2, #RAM_MAP    ; RAM Mapping
                STR     R1, [R0, #SCR_RMPCON_OFS]
                STR     R2, [R0, #SCR_RMPCON_OFS]
                ENDIF


; Setup Memory Protection Unit and Cache ---------------------------------------

                IF      MPU_SETUP != 0
                LDR     R0, =MEM_REG_0_Val      ; Setup Memory Regions
                MCR     p15, 0, R0, c6, c0, 0
                LDR     R0, =MEM_REG_1_Val
                MCR     p15, 0, R0, c6, c1, 0
                LDR     R0, =MEM_REG_2_Val
                MCR     p15, 0, R0, c6, c2, 0
                LDR     R0, =MEM_REG_3_Val    
                MCR     p15, 0, R0, c6, c3, 0
                LDR     R0, =MEM_REG_4_Val
                MCR     p15, 0, R0, c6, c4, 0
                LDR     R0, =MEM_REG_5_Val
                MCR     p15, 0, R0, c6, c5, 0
                LDR     R0, =MEM_REG_6_Val
                MCR     p15, 0, R0, c6, c6, 0
                LDR     R0, =MEM_REG_7_Val
                MCR     p15, 0, R0, c6, c7, 0

                MOV     R0, #DCACHE_CFG_Val     ; Setup D Cacheable bits
                MCR     p15, 0, R0, c2, c0, 0
                MOV     R0, #ICACHE_CFG_Val     ; Setup I Cacheable bits
                MCR     p15, 0, R0, c2, c0, 1
                MOV     R0, #BUFFER_CFG_Val     ; Setup Bufferable bits
                MCR     p15, 0, R0, c3, c0, 0

                LDR     R0, =DMEM_ACCESS_Val    ; Setup Data  Access Permissions
                MCR     p15, 0, R0, c5, c0, 2
                LDR     R0, =IMEM_ACCESS_Val    ; Setup Instr Access Permissions
                MCR     p15, 0, R0, c5, c0, 3

                MRC     p15, 0, R0, c1, c0, 0   ; Enable MPU + Caches
                ORR     R0, R0, #MPU_EN_BIT
                ORR     R0, R0, #ICACHE_EN_BIT
                ORR     R0, R0, #DCACHE_EN_BIT
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
