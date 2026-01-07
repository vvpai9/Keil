;/*****************************************************************************/
;/* PC72xx.S: Startup file for Socle PC72xx device series                     */
;/*****************************************************************************/
;/* <<< Use Configuration Wizard in Context Menu >>>                          */ 
;/*****************************************************************************/
;/* This file is part of the uVision/ARM development tools.                   */
;/* Copyright (c) 2005-2009 Keil Software. All rights reserved.               */
;/* This software may only be used under the terms of a valid, current,       */
;/* end user licence from KEIL for a compatible version of KEIL software      */
;/* development tools. Nothing else gives you the right to use this software. */
;/*****************************************************************************/


; Startup code is executed after CPU Reset. This file may be 
; translated with the following SET symbols. In uVision these SET 
; symbols are entered under Options - ASM - Define.
; If any of the following symbols is set:
;
; CLOCK_NO_INIT: the clock controller is not initialized
;
; MC_NO_INIT:    the memory controller is not initialized
;
; MCSDR_NO_INIT: the SDRAM memory controller is not initialized
;
; MCST0_NO_INIT: the static memory 0 controller is not initialized
;
; MCST1_NO_INIT: the static memory 1 controller is not initialized
;
; MCST2_NO_INIT: the static memory 2 controller is not initialized
;
; MCST3_NO_INIT: the static memory 3 controller is not initialized
;
; CACHE_NO_INIT: the cache controller is not initialized
;
; ARB_NO_INIT:   the AHB bus arbiter is not initialized
;
; REMAP:         the SDRAM is remapped to address 0
;

; Standard definitions of Mode bits and Interrupt (I & F) flags in PSRs

Mode_USR          EQU     0x10
Mode_FIQ          EQU     0x11
Mode_IRQ          EQU     0x12
Mode_SVC          EQU     0x13
Mode_ABT          EQU     0x17
Mode_UND          EQU     0x1B
Mode_SYS          EQU     0x1F

I_Bit             EQU     0x80        ; when I bit is set, IRQ is disabled
F_Bit             EQU     0x40        ; when F bit is set, FIQ is disabled


;----------------------- Stack and Heap Definitions ----------------------------

; <h> Stack Configuration (Stack Sizes in Bytes)
;   <o0> Undefined Mode      <0x0-0xFFFFFFFF:8>
;   <o1> Supervisor Mode     <0x0-0xFFFFFFFF:8>
;   <o2> Abort Mode          <0x0-0xFFFFFFFF:8>
;   <o3> Fast Interrupt Mode <0x0-0xFFFFFFFF:8>
;   <o4> Interrupt Mode      <0x0-0xFFFFFFFF:8>
;   <o5> User/System Mode    <0x0-0xFFFFFFFF:8>
; </h>

UND_Stack_Size    EQU     0x00000000
SVC_Stack_Size    EQU     0x00000008
ABT_Stack_Size    EQU     0x00000000
FIQ_Stack_Size    EQU     0x00000000
IRQ_Stack_Size    EQU     0x00000080
USR_Stack_Size    EQU     0x00000400

ISR_Stack_Size    EQU     (UND_Stack_Size + SVC_Stack_Size + ABT_Stack_Size + \
                           FIQ_Stack_Size + IRQ_Stack_Size)

                  AREA    STACK, NOINIT, READWRITE, ALIGN=3

Stack_Mem         SPACE   USR_Stack_Size
__initial_sp      SPACE   ISR_Stack_Size
Stack_Top


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF>
; </h>

Heap_Size         EQU     0x00000000

                  AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem          SPACE   Heap_Size
__heap_limit


;----------------------- System Control Unit (SCU) -----------------------------

; Register definitions
SCU_BASE          EQU     0x1803C000
SCU_P7CID_OFS     EQU     0x00
SCU_PLLA_OFS      EQU     0x04
SCU_PLLB_OFS      EQU     0x08
SCU_CFGA_OFS      EQU     0x0C
SCU_CFGB_OFS      EQU     0x10
SCU_CLKCFG_OFS    EQU     0x14
SCU_CFGC_OFS      EQU     0x18

; Constants
USE_PLL           EQU     0xDEEDDEED
PLL_DISABLE       EQU     0x00010001
REMAP_SDRAM       EQU     0xBEEFDEAD
REMAP_OFF         EQU     0x00000000

; <e> System Control Unit Configuration
;   <h> PLL Configuration
;     <i> PLL clock frequency = ((Xin * M) / N) / (2^OD)
;     <o1.23..31> UPLL_MUL: M value <2-1025><#-2>
;     <o1.18..22> UPLL_DIV: N value <2-33><#-2>
;     <o1.16..17> UPLL_OD: Output divider control <0=> 0 <1=> 1 <3=> 2
;     <o1.7..15>  CPLL_MUL: M value <2-1025><#-2>
;     <o1.2..6>   CPLL_DIV: N value <2-33><#-2>
;     <o1.0..1>   CPLL_OD: Output divider control <0=> 0 <1=> 1 <3=> 2
;     <o2.19>     UPLL power down
;     <o2.18>     CPLL power down
;     <o2.16..17> CPU / AHB clock ratio <0=> 1/1 <1=> 2/1 <2=> Reserved <3=> Reserved
;     <o2.0..15>  PLL lock period (in 12MHz clocks) <0-65535>
;   </h>
;   <h> Chip Configuration
;     <o3.18>     Disable USB PHY's analog block power in Suspend mode
;     <o3.16..17> DCFG_MODE setting 
;                 <0=> Tri-state mode, all bi-direction pin as input state
;                 <1=> DCFG_MODE1
;                 <2=> DCFG_MODE2
;                 <3=> DCFG_MODE3
;     <o3.13..15> UCFG_MODE setting 
;                 <0=> Tri-state mode, all bi-direction pin as input state
;                 <1=> UCFG_MODE1
;                 <2=> UCFG_MODE2
;                 <3=> UCFG_MODE3
;                 <4=> UCFG_MODE4
;                 <5=> UCFG_MODE5
;                 <6=> UCFG_MODE6
;                 <7=> Reserved
;     <o3.6..7>   Selection of UART that will occupy HDMA request 2/3
;                 <0=> UART0
;                 <1=> UART1
;                 <2=> UART2
;                 <3=> UART3
;     <o3.4..5>   Selection of UART that will occupy HDMA request 0/1
;                 <0=> UART0
;                 <1=> UART1
;                 <2=> UART2
;                 <3=> UART3
;     <o3.3>      USB Transceiver play mode
;                 <0=> Downstream (UHC)
;                 <1=> Upstream (UDC)
;     <o3.2>      Fast IRQ plarity
;                 <0=> Active low
;                 <1=> Active high
;     <o3.1>      USB port over current function polarity
;                 <0=> Active low
;                 <1=> Active high
;     <o3.0>      Fast IRQ or USB port over current function selection
;                 <0=> USB port over current
;                 <1=> CPU fast IRQ
;     <o4.0..15>  ADC clock duty period (in PCLK clocks) <0-65535>
;   </h>
;   <h> IP Clock Control Configuration
;     <o5.24>     ADC Clock Enable
;     <o5.21>     UART3 Clock Enable
;     <o5.20>     UART2 Clock Enable
;     <o5.19>     UART1 Clock Enable
;     <o5.18>     UART0 Clock Enable
;     <o5.17>     ADC Controller Clock Enable
;     <o5.16>     PWM Clock Enable
;     <o5.15>     SDC Clock Enable
;     <o5.14>     I2S Clock Enable
;     <o5.13>     I2C Clock Enable
;     <o5.12>     SPI Clock Enable
;     <o5.11>     GPIO Clock Enable
;     <o5.10>     WDT Clock Enable
;     <o5.9>      RTC Clock Enable
;     <o5.8>      Timer Clock Enable
;     <o5.6>      LCD Controller Clock Enable
;     <o5.5>      NAND Flash Controller Clock Enable
;     <o5.4>      UDC Clock Enable
;     <o5.3>      UHC Clock Enable
;     <o5.2>      MAC Clock Enable
;     <o5.1>      HDMA Clock Enable
;     <o5.0>      Memory Controller Clock Enable
;   </h>
; </e>

CLOCK_SETUP       EQU     1
SCU_PLLA_Val      EQU     0x0F0141A8    ; Reset value: 0x0F012890
SCU_PLLB_Val      EQU     0x00001770    ; Reset value: 0x000700FF
SCU_CFGA_Val      EQU     0x00032000    ; Reset value: 0x00040003
SCU_CFGB_Val      EQU     0x0000FFFF    ; Reset value: 0x0000FFFF
SCU_CLKCFG_Val    EQU     0xFFFFFFFF    ; Reset value: 0xFFFFFFFF


;----------------------- Static / SDRAM Memory Controller ----------------------

; Register definitions
MC_BASE           EQU     0x18058000
MCSDR_MODE_OFS    EQU     0x0100
MCSDR_ADDMAP_OFS  EQU     0x0104
MCSDR_ADDCFG_OFS  EQU     0x0108
MCSDR_BASIC_OFS   EQU     0x010C
MCSDR_T_REF_OFS   EQU     0x0110
MCSDR_T_RFC_OFS   EQU     0x0114
MCSDR_T_MRD_OFS   EQU     0x0118
MCSDR_T_RP_OFS    EQU     0x0120
MCSDR_T_RCD_OFS   EQU     0x0124
MCST0_T_CEWD_OFS  EQU     0x0200
MCST0_T_CE2WE_OFS EQU     0x0204
MCST0_T_WEWD_OFS  EQU     0x0208
MCST0_T_WE2CE_OFS EQU     0x020C
MCST0_T_CEWDR_OFS EQU     0x0210
MCST0_T_CE2RD_OFS EQU     0x0214
MCST0_T_RDWD_OFS  EQU     0x0218
MCST0_T_RD2CE_OFS EQU     0x021C
MCST0_BASIC_OFS   EQU     0x0220
MCST1_T_CEWD_OFS  EQU     0x0300
MCST1_T_CE2WE_OFS EQU     0x0304
MCST1_T_WEWD_OFS  EQU     0x0308
MCST1_T_WE2CE_OFS EQU     0x030C
MCST1_T_CEWDR_OFS EQU     0x0310
MCST1_T_CE2RD_OFS EQU     0x0314
MCST1_T_RDWD_OFS  EQU     0x0318
MCST1_T_RD2CE_OFS EQU     0x031C
MCST1_BASIC_OFS   EQU     0x0320
MCST2_T_CEWD_OFS  EQU     0x0400
MCST2_T_CE2WE_OFS EQU     0x0404
MCST2_T_WEWD_OFS  EQU     0x0408
MCST2_T_WE2CE_OFS EQU     0x040C
MCST2_T_CEWDR_OFS EQU     0x0410
MCST2_T_CE2RD_OFS EQU     0x0414
MCST2_T_RDWD_OFS  EQU     0x0418
MCST2_T_RD2CE_OFS EQU     0x041C
MCST2_BASIC_OFS   EQU     0x0420
MCST3_T_CEWD_OFS  EQU     0x0500
MCST3_T_CE2WE_OFS EQU     0x0504
MCST3_T_WEWD_OFS  EQU     0x0508
MCST3_T_WE2CE_OFS EQU     0x050C
MCST3_T_CEWDR_OFS EQU     0x0510
MCST3_T_CE2RD_OFS EQU     0x0514
MCST3_T_RDWD_OFS  EQU     0x0518
MCST3_T_RD2CE_OFS EQU     0x051C
MCST3_BASIC_OFS   EQU     0x0520

; <e0> Memory Controller Setup
; <e1> SDRAM Memory Controller Setup
;   <h> SDRAM CAS Latency and Burst Length (MCSDR_MODE)
;     <o2.4..6>   SDRAM CAS latency <2-3>
;     <o2.0..2>   SDRAM burst length 
;                 <0=> 1 
;                 <1=> 2 
;                 <2=> 4 
;                 <3=> 8
;   </h>
;   <h> SDRAM Memory Modules Address Mapping (MCSDR_ADDMAP)
;     <o3.11>     Memory module address mapping
;                 <0=> Module 0 is lower address / Module 1 is higher address 
;                 <1=> Module 0 is higher address / Module 1 is lower address 
;     <o3.8..10>  The Module 1 base address
;                 <0=> 0: No addressing
;                 <1=> 1: 0x04000000
;                 <2=> 2: 0x08000000
;                 <3=> 3: 0x10000000
;                 <4=> 4: 0x20000000
;                 <5=> 5: Reserved
;                 <6=> 6: Reserved
;                 <7=> 7: Reserved
;     <o3.6..7>   The Module 1 memory size
;                 <0=> 0: 64 MB
;                 <1=> 1: 128 MB
;                 <2=> 2: 256 MB
;                 <3=> 3: 512 MB
;     <o3.4..5>   The Module 0 memory size
;                 <0=> 0: 64 MB
;                 <1=> 1: 128 MB
;                 <2=> 2: 256 MB
;                 <3=> 3: 512 MB
;     <o3.2..3>   The number of banks in Module 1
;                 <0=> 0: Reserved
;                 <1=> 1: 1 bank, CS4 is used
;                 <2=> 2: 2 banks, CS4 and CS6 are used
;                 <3=> 3: 4 banks CS4..CS7 are used
;     <o3.0..1>   The number of banks in Module 0
;                 <0=> 0: Reserved
;                 <1=> 1: 1 bank, CS0 is used
;                 <2=> 2: 2 banks, CS0 and CS2 are used
;                 <3=> 3: 4 banks CS0..CS3 are used
;   </h>
;   <h> SDRAM Memory Modules Address Configuration (MCSDR_ADDCFG)
;     <o4.12..13> The number of bits of SDRAM Module 1 row address
;                 <0=> 0: 11 bits
;                 <1=> 1: 12 bits
;                 <2=> 2: 13 bits
;                 <3=> 3: Reserved
;     <o4.8..10>  The number of bits of SDRAM Module 1 column address
;                 <0=> 0: 8 bits
;                 <1=> 1: 9 bits
;                 <2=> 2: 10 bits
;                 <3=> 3: 11 bits
;                 <4=> 4: 12 bits
;                 <5=> 5: Reserved
;                 <6=> 6: Reserved
;                 <7=> 7: Reserved
;     <o4.4..5>   The number of bits of SDRAM Module 0 row address
;                 <0=> 0: 11 bits
;                 <1=> 1: 12 bits
;                 <2=> 2: 13 bits
;                 <3=> 3: Reserved
;     <o4.0..2>   The number of bits of SDRAM Module 0 column address
;                 <0=> 0: 8 bits
;                 <1=> 1: 9 bits
;                 <2=> 2: 10 bits
;                 <3=> 3: 11 bits
;                 <4=> 4: 12 bits
;                 <5=> 5: Reserved
;                 <6=> 6: Reserved
;                 <7=> 7: Reserved
;   </h>
;   <h> SDRAM Basic Settings (MCSDR_BASIC)
;     <o5.5..7>   Arbiter priority strategy for different slave port read/write operation
;                 <0=> 0: Round-robin, write priority is higher than read
;                 <1=> 1: Round-robin, write priority is same as read
;                 <2=> 2: S1 has higher priority, write priority is higher than read
;                 <3=> 3: S1 has higher priority, write priority is same as read
;                 <4=> 4: S2 has higher priority, write priority is higher than read
;                 <5=> 5: S2 has higher priority, write priority is same as read
;                 <6=> 6: Reserved
;                 <7=> 7: Reserved
;     <o5.2..3>   SDRAM Module 1 data width size
;                 <0=> 0: Reserved
;                 <1=> 1: 16 bits
;                 <2=> 2: 32 bits
;                 <3=> 3: Reserved
;     <o5.0..1>   SDRAM Module 0 data width size
;                 <0=> 0: Reserved
;                 <1=> 1: 16 bits
;                 <2=> 2: 32 bits
;                 <3=> 3: Reserved
;   </h>
;   <h> SDRAM Timings
;     <o6.0..15>  Average periodic refresh interval (MCSDR_T_REF) <0-65535>
;                 <i> For autorefresh of 15.625us, value must be less than 1560 at 100 MHz.
;     <o7.0..3>   Autorefresh period (MCSDR_T_RFC) <1-16><#-1>
;     <o8.0..2>   Command to Active refresh period (MCSDR_T_MRD) <1-8><#-1>
;     <o9.0..2>   Precharge command period (MCSDR_T_RP) <1-8><#-1>
;     <o10.0..2>  Active Read to Write delay (MCSDR_T_RCD) <1-8><#-1>
;   </h>
; </e> SDRAM Memory Controller Setup

MC_SETUP          EQU     1
MCSDR_SETUP       EQU     1
MCSDR_MODE_Val    EQU     0x00000030    ; Reset value: 0x00000030
MCSDR_ADDMAP_Val  EQU     0x000000FF    ; Reset value: 0x000000FF
MCSDR_ADDCFG_Val  EQU     0x00002121    ; Reset value: 0x00002222
MCSDR_BASIC_Val   EQU     0x0000000A    ; Reset value: 0x0000000A
MCSDR_T_REF_Val   EQU     0x0000040F    ; Reset value: 0x0000030C
MCSDR_T_RFC_Val   EQU     0x00000009    ; Reset value: 0x0000000A
MCSDR_T_MRD_Val   EQU     0x00000001    ; Reset value: 0x00000002
MCSDR_T_RP_Val    EQU     0x00000002    ; Reset value: 0x00000002
MCSDR_T_RCD_Val   EQU     0x00000001    ; Reset value: 0x00000002

; <e> Static Memory 0 Controller Setup
;   <h> Static Memory 0 Timings
;     <o1.0..7>   Static Memory timing control for write CE width (MCST0_T_CEWD) <0-255>
;     <o2.0..7>   Static Memory timing control for low of CE to low of WE (MCST0_T_CE2WE) <0-255>
;     <o3.0..7>   Static Memory timing control for WE width (MCST0_T_WEWD) <0-255>
;     <o4.0..7>   Static Memory timing control for high of WE to high of CE (MCST0_T_WE2CE) <0-255>
;     <o5.0..7>   Static Memory timing control for read CE width (MCST0_T_CEWDR) <0-255>
;     <o6.0..7>   Static Memory timing control for low of CE to low of RD (MCST0_T_CE2RD) <0-255>
;     <o7.0..7>   Static Memory timing control for RD width (MCST0_T_RDWR) <0-255>
;     <o8.0..7>   Static Memory timing control for high of RD to high of CE (MCST0_T_RD2CE) <0-255>
;   </h>
;   <h> Static Memory 0 Basic Settings (MCST0_BASIC)
;     <o9.5>      Write protect enable
;     <o9.0..1>   Static memory data size
;                 <0=> 8 bits
;                 <1=> 16 bits
;                 <2=> 32 bits
;                 <3=> Reserved
;   </h>
; </e> Static Memory 0 Controller Setup

MCST0_SETUP       EQU     1
MCST0_T_CEWD_Val  EQU     0x00000006    ; Reset value: 0x0000000F
MCST0_T_CE2WE_Val EQU     0x00000000    ; Reset value: 0x0000000F
MCST0_T_WEWD_Val  EQU     0x00000005    ; Reset value: 0x0000000F
MCST0_T_WE2CE_Val EQU     0x00000000    ; Reset value: 0x0000000F
MCST0_T_CEWDR_Val EQU     0x00000000    ; Reset value: 0x00000000
MCST0_T_CE2RD_Val EQU     0x00000006    ; Reset value: 0x0000000F
MCST0_T_RDWD_Val  EQU     0x0000000A    ; Reset value: 0x00000015
MCST0_T_RD2CE_Val EQU     0x00000000    ; Reset value: 0x00000000
MCST0_BASIC_Val   EQU     0x00000001    ; Reset value: 0x00000000

; <e> Static Memory 1 Controller Setup
;   <h> Static Memory 1 Timings
;     <o1.0..7>   Static Memory timing control for write CE width (MCST1_T_CEWD) <0-255>
;     <o2.0..7>   Static Memory timing control for low of CE to low of WE (MCST1_T_CE2WE) <0-255>
;     <o3.0..7>   Static Memory timing control for WE width (MCST1_T_WEWD) <0-255>
;     <o4.0..7>   Static Memory timing control for high of WE to high of CE (MCST1_T_WE2CE) <0-255>
;     <o5.0..7>   Static Memory timing control for read CE width (MCST1_T_CEWDR) <0-255>
;     <o6.0..7>   Static Memory timing control for low of CE to low of RD (MCST1_T_CE2RD) <0-255>
;     <o7.0..7>   Static Memory timing control for RD width (MCST1_T_RDWR) <0-255>
;     <o8.0..7>   Static Memory timing control for high of RD to high of CE (MCST1_T_RD2CE) <0-255>
;   </h>
;   <h> Static Memory 1 Basic Settings (MCST1_BASIC)
;     <o9.5>      Write protect enable
;     <o9.0..1>   Static memory data size
;                 <0=> 8 bits
;                 <1=> 16 bits
;                 <2=> 32 bits
;                 <3=> Reserved
;   </h>
; </e> Static Memory 1 Controller Setup

MCST1_SETUP       EQU     1
MCST1_T_CEWD_Val  EQU     0x00000006    ; Reset value: 0x0000000F
MCST1_T_CE2WE_Val EQU     0x00000000    ; Reset value: 0x0000000F
MCST1_T_WEWD_Val  EQU     0x00000005    ; Reset value: 0x0000000F
MCST1_T_WE2CE_Val EQU     0x00000000    ; Reset value: 0x0000000F
MCST1_T_CEWDR_Val EQU     0x00000000    ; Reset value: 0x00000000
MCST1_T_CE2RD_Val EQU     0x00000006    ; Reset value: 0x0000000F
MCST1_T_RDWD_Val  EQU     0x0000000A    ; Reset value: 0x0000000F
MCST1_T_RD2CE_Val EQU     0x00000000    ; Reset value: 0x00000000
MCST1_BASIC_Val   EQU     0x00000001    ; Reset value: 0x00000000

; <e> Static Memory 2 Controller Setup
;   <h> Static Memory 2 Timings
;     <o1.0..7>   Static Memory timing control for write CE width (MCST2_T_CEWD) <0-255>
;     <o2.0..7>   Static Memory timing control for low of CE to low of WE (MCST2_T_CE2WE) <0-255>
;     <o3.0..7>   Static Memory timing control for WE width (MCST2_T_WEWD) <0-255>
;     <o4.0..7>   Static Memory timing control for high of WE to high of CE (MCST2_T_WE2CE) <0-255>
;     <o5.0..7>   Static Memory timing control for read CE width (MCST2_T_CEWDR) <0-255>
;     <o6.0..7>   Static Memory timing control for low of CE to low of RD (MCST2_T_CE2RD) <0-255>
;     <o7.0..7>   Static Memory timing control for RD width (MCST2_T_RDWR) <0-255>
;     <o8.0..7>   Static Memory timing control for high of RD to high of CE (MCST2_T_RD2CE) <0-255>
;   </h>
;   <h> Static Memory 2 Basic Settings (MCST2_BASIC)
;     <o9.5>      Write protect enable
;     <o9.0..1>   Static memory data size
;                 <0=> 8 bits
;                 <1=> 16 bits
;                 <2=> 32 bits
;                 <3=> Reserved
;   </h>
; </e> Static Memory 2 Controller Setup

MCST2_SETUP       EQU     0
MCST2_T_CEWD_Val  EQU     0x0000000F    ; Reset value: 0x0000000F
MCST2_T_CE2WE_Val EQU     0x0000000F    ; Reset value: 0x0000000F
MCST2_T_WEWD_Val  EQU     0x0000000F    ; Reset value: 0x0000000F
MCST2_T_WE2CE_Val EQU     0x0000000F    ; Reset value: 0x0000000F
MCST2_T_CEWDR_Val EQU     0x00000000    ; Reset value: 0x00000000
MCST2_T_CE2RD_Val EQU     0x0000000F    ; Reset value: 0x0000000F
MCST2_T_RDWD_Val  EQU     0x0000000F    ; Reset value: 0x0000000F
MCST2_T_RD2CE_Val EQU     0x00000000    ; Reset value: 0x00000000
MCST2_BASIC_Val   EQU     0x00000000    ; Reset value: 0x00000000

; <e> Static Memory 3 Controller Setup
;   <h> Static Memory 3 Timings
;     <o1.0..7>   Static Memory timing control for write CE width (MCST3_T_CEWD) <0-255>
;     <o2.0..7>   Static Memory timing control for low of CE to low of WE (MCST3_T_CE2WE) <0-255>
;     <o3.0..7>   Static Memory timing control for WE width (MCST3_T_WEWD) <0-255>
;     <o4.0..7>   Static Memory timing control for high of WE to high of CE (MCST3_T_WE2CE) <0-255>
;     <o5.0..7>   Static Memory timing control for read CE width (MCST3_T_CEWDR) <0-255>
;     <o6.0..7>   Static Memory timing control for low of CE to low of RD (MCST3_T_CE2RD) <0-255>
;     <o7.0..7>   Static Memory timing control for RD width (MCST3_T_RDWR) <0-255>
;     <o8.0..7>   Static Memory timing control for high of RD to high of CE (MCST3_T_RD2CE) <0-255>
;   </h>
;   <h> Static Memory 3 Basic Settings (MCST3_BASIC)
;     <o9.5>      Write protect enable
;     <o9.0..1>   Static memory data size
;                 <0=> 8 bits
;                 <1=> 16 bits
;                 <2=> 32 bits
;                 <3=> Reserved
;   </h>
; </e> Static Memory 3 Controller Setup

MCST3_SETUP       EQU     0
MCST3_T_CEWD_Val  EQU     0x0000000F    ; Reset value: 0x0000000F
MCST3_T_CE2WE_Val EQU     0x0000000F    ; Reset value: 0x0000000F
MCST3_T_WEWD_Val  EQU     0x0000000F    ; Reset value: 0x0000000F
MCST3_T_WE2CE_Val EQU     0x0000000F    ; Reset value: 0x0000000F
MCST3_T_CEWDR_Val EQU     0x00000000    ; Reset value: 0x00000000
MCST3_T_CE2RD_Val EQU     0x0000000F    ; Reset value: 0x0000000F
MCST3_T_RDWD_Val  EQU     0x0000000F    ; Reset value: 0x0000000F
MCST3_T_RD2CE_Val EQU     0x00000000    ; Reset value: 0x00000000
MCST3_BASIC_Val   EQU     0x00000000    ; Reset value: 0x00000000

; </e> Memory Controller Setup


;----------------------- Cache Controller --------------------------------------

; Register definitions
CACHE_BASE        EQU     0xEFFF0000
DEVID_OFS         EQU     0x00
CACHEOP_OFS       EQU     0x04
CACHELKDN_OFS     EQU     0x08
MEMMAPA_OFS       EQU     0x10
MEMMAPB_OFS       EQU     0x14
MEMMAPC_OFS       EQU     0x18
MEMMAPD_OFS       EQU     0x1C
PFCNTRA_CTRL_OFS  EQU     0x20
PFCNTRA_OFS       EQU     0x24
PFCNTRB_CTRL_OFS  EQU     0x28
PFCNTRB_OFS       EQU     0x2C

; Constants
CACHE_EN          EQU     (1 << 31)

; <e> Cache Controller Configuration
;   <h> Uncacheable Area Setting
;     <o1.25..31> Area 0 Start Address <0x00000000-0xFE000000:0x02000000><#/0x02000000>
;     <o1.0..7>   Area 0 Size
;                 <0x00=> None
;                 <0xFE=> 32 MB
;                 <0xFC=> 64 MB
;                 <0xF8=> 128 MB
;     <o2.25..31> Area 1 Start Address <0x00000000-0xFE000000:0x02000000><#/0x02000000>
;     <o2.0..7>   Area 1 Size
;                 <0x00=> None
;                 <0xFE=> 32 MB
;                 <0xFC=> 64 MB
;                 <0xF8=> 128 MB
;     <o3.25..31> Area 2 Start Address <0x00000000-0xFE000000:0x02000000><#/0x02000000>
;     <o3.0..7>   Area 2 Size
;                 <0x00=> None
;                 <0xFE=> 32 MB
;                 <0xFC=> 64 MB
;                 <0xF8=> 128 MB
;     <o4.25..31> Area 3 Start Address <0x00000000-0xFE000000:0x02000000><#/0x02000000>
;     <o4.0..7>   Area 3 Size
;                 <0x00=> None
;                 <0xFE=> 32 MB
;                 <0xFC=> 64 MB
;                 <0xF8=> 128 MB
;   </h>
;   <h> Performance Counter A Setting
;     <o5.4..8>   Count event
;                 <0=> 0: Cycle counts
;                 <1=> 1: Instruction counts
;                 <2=> 2: Cacheable instruction counts
;                 <3=> 3: Instruction hit counts
;                 <4=> 4: Reserved
;                 <5=> 5: Data counts
;                 <6=> 6: Data write counts
;                 <7=> 7: Cacheable data counts
;                 <8=> 8: Data read hit counts
;                 <9=> 9: Reserved
;     <o5.0>      Counter enable
;   </h>
;   <h> Performance Counter B Setting
;     <o6.4..8>   Count event
;                 <0=> 0: Cycle counts
;                 <1=> 1: Instruction counts
;                 <2=> 2: Cacheable instruction counts
;                 <3=> 3: Instruction hit counts
;                 <4=> 4: Reserved
;                 <5=> 5: Data counts
;                 <6=> 6: Data write counts
;                 <7=> 7: Cacheable data counts
;                 <8=> 8: Data read hit counts
;                 <9=> 9: Reserved
;     <o6.0>      Counter enable
;   </h>
; </e>

CACHE_SETUP       EQU     1
MEMMAPA_Val       EQU     0x180000F8    ; Reset value: 0x00000000
MEMMAPB_Val       EQU     0x00000000    ; Reset value: 0x00000000
MEMMAPC_Val       EQU     0x00000000    ; Reset value: 0x00000000
MEMMAPD_Val       EQU     0x00000000    ; Reset value: 0x00000000
PFCNTRA_CTRL_Val  EQU     0x00000000    ; Reset value: 0x00000000
PFCNTRB_CTRL_Val  EQU     0x00000000    ; Reset value: 0x00000000


;----------------------- AHB Bus Arbiter ---------------------------------------

; Register definitions
ARB_BASE          EQU     0x1806C000
ARB_MODE_OFS      EQU     0x00
ARB_PRIO1_OFS     EQU     0x04+ 0*4
ARB_PRIO2_OFS     EQU     0x04+ 1*4
ARB_PRIO3_OFS     EQU     0x04+ 2*4
ARB_PRIO4_OFS     EQU     0x04+ 3*4
ARB_PRIO5_OFS     EQU     0x04+ 4*4
ARB_PRIO6_OFS     EQU     0x04+ 5*4
ARB_PRIO7_OFS     EQU     0x04+ 6*4
ARB_PRIO8_OFS     EQU     0x04+ 7*4
ARB_PRIO9_OFS     EQU     0x04+ 8*4
ARB_PRIO10_OFS    EQU     0x04+ 9*4
ARB_PRIO11_OFS    EQU     0x04+10*4
ARB_PRIO12_OFS    EQU     0x04+11*4
ARB_PRIO13_OFS    EQU     0x04+12*4
ARB_PRIO14_OFS    EQU     0x04+13*4
ARB_PRIO15_OFS    EQU     0x04+14*4

; <e> AHB Bus Arbiter
;   <h> Arbitration mode
;     <o1.2..7>   Time-out force arbitration timeout counter
;                 <i> Range: 16 HCLK cycles < 16 HCLK cycles + Time-out value < 64 HCLK cycles
;     <o1.0>      Arbitration scheme mode
;                 <0=> 0: Round robin
;                 <1=> 1: 2-stage, fixed arbitration
;   </h>
;   <h> Arbitration priority
;     <o2.0..3>   Priority level for Master 1 <0-15>
;     <o3.0..3>   Priority level for Master 2 <0-15>
;     <o4.0..3>   Priority level for Master 3 <0-15>
;     <o5.0..3>   Priority level for Master 4 <0-15>
;     <o6.0..3>   Priority level for Master 5 <0-15>
;     <o7.0..3>   Priority level for Master 6 <0-15>
;     <o8.0..3>   Priority level for Master 7 <0-15>
;     <o9.0..3>   Priority level for Master 8 <0-15>
;     <o10.0..3>  Priority level for Master 9 <0-15>
;     <o11.0..3>  Priority level for Master 10 <0-15>
;     <o12.0..3>  Priority level for Master 11 <0-15>
;     <o13.0..3>  Priority level for Master 12 <0-15>
;     <o14.0..3>  Priority level for Master 13 <0-15>
;     <o15.0..3>  Priority level for Master 14 <0-15>
;     <o16.0..3>  Priority level for Master 15 <0-15>
;   </h>
; </e>

ARB_SETUP         EQU     0
ARB_MODE_Val      EQU     0x00000041    ; Reset value: 0x00000041
ARB_PRIO1_Val     EQU     0x00000000    ; Reset value: 0x00000000
ARB_PRIO2_Val     EQU     0x00000000    ; Reset value: 0x00000000
ARB_PRIO3_Val     EQU     0x00000000    ; Reset value: 0x00000000
ARB_PRIO4_Val     EQU     0x00000000    ; Reset value: 0x00000000
ARB_PRIO5_Val     EQU     0x00000000    ; Reset value: 0x00000000
ARB_PRIO6_Val     EQU     0x00000000    ; Reset value: 0x00000000
ARB_PRIO7_Val     EQU     0x00000000    ; Reset value: 0x00000000
ARB_PRIO8_Val     EQU     0x00000000    ; Reset value: 0x00000000
ARB_PRIO9_Val     EQU     0x00000000    ; Reset value: 0x00000000
ARB_PRIO10_Val    EQU     0x00000000    ; Reset value: 0x00000000
ARB_PRIO11_Val    EQU     0x00000000    ; Reset value: 0x00000000
ARB_PRIO12_Val    EQU     0x00000000    ; Reset value: 0x00000000
ARB_PRIO13_Val    EQU     0x00000000    ; Reset value: 0x00000000
ARB_PRIO14_Val    EQU     0x00000000    ; Reset value: 0x00000000
ARB_PRIO15_Val    EQU     0x00000000    ; Reset value: 0x00000000


;----------------------- CODE --------------------------------------------------

                PRESERVE8
                

; Area Definition and Entry Point
;  Startup Code must be linked first at Address at which it expects to run.

                AREA    RESET, CODE, READONLY
                ARM

                IF      :DEF:__RTX
                IMPORT  SWI_Handler
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
                NOP                             ; Reserved
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
                IF      :LNOT::DEF:__RTX
SWI_Handler     B       SWI_Handler
                ENDIF
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

                LDR     R6, =25000                ; Wait for Debugger to connect
WaitConnect     SUBS    R6, R6, #1
                BNE     WaitConnect

; Clock Setup ------------------------------------------------------------------

                LDR     R0, =SCU_BASE
                LDR     R1, =REMAP_OFF
                STR     R1, [R0, #SCU_CFGC_OFS]

                IF      (:LNOT::DEF:CLOCK_NO_INIT):LAND:(CLOCK_SETUP != 0)
                LDR     R1, =PLL_DISABLE
                STR     R1, [R1, #SCU_CFGC_OFS]
                LDR     R1, =SCU_PLLA_Val
                STR     R1, [R0, #SCU_PLLA_OFS]
                LDR     R1, =SCU_PLLB_Val
                STR     R1, [R0, #SCU_PLLB_OFS]
                LDR     R1, =SCU_CFGA_Val
                STR     R1, [R0, #SCU_CFGA_OFS]
                LDR     R1, =SCU_CFGB_Val
                STR     R1, [R0, #SCU_CFGB_OFS]
                LDR     R1, =SCU_CLKCFG_Val
                STR     R1, [R0, #SCU_CLKCFG_OFS]

                LDR     R1, =USE_PLL
                STR     R1, [R0, #SCU_CFGC_OFS]
                ENDIF   ;(:LNOT::DEF:CLOCK_NO_INIT):LAND:(CLOCK_SETUP != 0)


; Static / SDRAM Memory Controller Setup ---------------------------------------

                IF      (:LNOT::DEF:MC_NO_INIT):LAND:(MC_SETUP != 0)
                LDR     R0, =MC_BASE

;  SDRAM Memory Controller Setup -----------------------------------------------

                IF      (:LNOT::DEF:MCSDR_NO_INIT):LAND:(MCSDR_SETUP != 0)
                LDR     R1, =MCSDR_MODE_Val
                STR     R1, [R0, #MCSDR_MODE_OFS]
                LDR     R1, =MCSDR_ADDMAP_Val
                STR     R1, [R0, #MCSDR_ADDMAP_OFS]
                LDR     R1, =MCSDR_ADDCFG_Val
                STR     R1, [R0, #MCSDR_ADDCFG_OFS]
                LDR     R1, =MCSDR_T_REF_Val
                STR     R1, [R0, #MCSDR_T_REF_OFS]
                LDR     R1, =MCSDR_T_RFC_Val
                STR     R1, [R0, #MCSDR_T_RFC_OFS]
                LDR     R1, =MCSDR_T_MRD_Val
                STR     R1, [R0, #MCSDR_T_MRD_OFS]
                LDR     R1, =MCSDR_T_RP_Val
                STR     R1, [R0, #MCSDR_T_RP_OFS]
                LDR     R1, =MCSDR_T_RCD_Val
                STR     R1, [R0, #MCSDR_T_RCD_OFS]
                LDR     R1, =MCSDR_BASIC_Val
                STR     R1, [R0, #MCSDR_BASIC_OFS]
                ENDIF   ;(:LNOT::DEF:MCSDR_NO_INIT):LAND:(MCSDR_SETUP != 0)

;  Static Memory 0 Controller Configuration ------------------------------------

                IF      (:LNOT::DEF:MCST0_NO_INIT):LAND:(MCST0_SETUP != 0)
                LDR     R1, =MCST0_T_CEWD_Val
                STR     R1, [R0, #MCST0_T_CEWD_OFS]
                LDR     R1, =MCST0_T_CE2WE_Val
                STR     R1, [R0, #MCST0_T_CE2WE_OFS]
                LDR     R1, =MCST0_T_WEWD_Val
                STR     R1, [R0, #MCST0_T_WEWD_OFS]
                LDR     R1, =MCST0_T_WE2CE_Val
                STR     R1, [R0, #MCST0_T_WE2CE_OFS]
                LDR     R1, =MCST0_T_CEWDR_Val
                STR     R1, [R0, #MCST0_T_CEWDR_OFS]
                LDR     R1, =MCST0_T_CE2RD_Val
                STR     R1, [R0, #MCST0_T_CE2RD_OFS]
                LDR     R1, =MCST0_T_RDWD_Val
                STR     R1, [R0, #MCST0_T_RDWD_OFS]
                LDR     R1, =MCST0_T_RD2CE_Val
                STR     R1, [R0, #MCST0_T_RD2CE_OFS]
                LDR     R1, =MCST0_BASIC_Val
                STR     R1, [R0, #MCST0_BASIC_OFS]
                ENDIF   ;(:LNOT::DEF:MCST0_NO_INIT):LAND:(MCST0_SETUP != 0)

;  Static Memory 1 Controller Configuration ------------------------------------

                IF      (:LNOT::DEF:MCST1_NO_INIT):LAND:(MCST1_SETUP != 0)
                LDR     R1, =MCST1_T_CEWD_Val
                STR     R1, [R0, #MCST1_T_CEWD_OFS]
                LDR     R1, =MCST1_T_CE2WE_Val
                STR     R1, [R0, #MCST1_T_CE2WE_OFS]
                LDR     R1, =MCST1_T_WEWD_Val
                STR     R1, [R0, #MCST1_T_WEWD_OFS]
                LDR     R1, =MCST1_T_WE2CE_Val
                STR     R1, [R0, #MCST1_T_WE2CE_OFS]
                LDR     R1, =MCST1_T_CEWDR_Val
                STR     R1, [R0, #MCST1_T_CEWDR_OFS]
                LDR     R1, =MCST1_T_CE2RD_Val
                STR     R1, [R0, #MCST1_T_CE2RD_OFS]
                LDR     R1, =MCST1_T_RDWD_Val
                STR     R1, [R0, #MCST1_T_RDWD_OFS]
                LDR     R1, =MCST1_T_RD2CE_Val
                STR     R1, [R0, #MCST1_T_RD2CE_OFS]
                LDR     R1, =MCST1_BASIC_Val
                STR     R1, [R0, #MCST0_BASIC_OFS]
                ENDIF   ;(:LNOT::DEF:MCST1_NO_INIT):LAND:(MCST1_SETUP != 0)

;  Static Memory 2 Controller Configuration ------------------------------------

                IF      (:LNOT::DEF:MCST2_NO_INIT):LAND:(MCST2_SETUP != 0)
                LDR     R1, =MCST2_T_CEWD_Val
                STR     R1, [R0, #MCST2_T_CEWD_OFS]
                LDR     R1, =MCST2_T_CE2WE_Val
                STR     R1, [R0, #MCST2_T_CE2WE_OFS]
                LDR     R1, =MCST2_T_WEWD_Val
                STR     R1, [R0, #MCST2_T_WEWD_OFS]
                LDR     R1, =MCST2_T_WE2CE_Val
                STR     R1, [R0, #MCST2_T_WE2CE_OFS]
                LDR     R1, =MCST2_T_CEWDR_Val
                STR     R1, [R0, #MCST2_T_CEWDR_OFS]
                LDR     R1, =MCST2_T_CE2RD_Val
                STR     R1, [R0, #MCST2_T_CE2RD_OFS]
                LDR     R1, =MCST2_T_RDWD_Val
                STR     R1, [R0, #MCST2_T_RDWD_OFS]
                LDR     R1, =MCST2_T_RD2CE_Val
                STR     R1, [R0, #MCST2_T_RD2CE_OFS]
                LDR     R1, =MCST2_BASIC_Val
                STR     R1, [R0, #MCST2_BASIC_OFS]
                ENDIF   ;(:LNOT::DEF:MCST2_NO_INIT):LAND:(MCST2_SETUP != 0)

;  Static Memory 3 Controller Configuration ------------------------------------

                IF      (:LNOT::DEF:MCST3_NO_INIT):LAND:(MCST3_SETUP != 0)
                LDR     R1, =MCST3_T_CEWD_Val
                STR     R1, [R0, #MCST3_T_CEWD_OFS]
                LDR     R1, =MCST3_T_CE2WE_Val
                STR     R1, [R0, #MCST3_T_CE2WE_OFS]
                LDR     R1, =MCST3_T_WEWD_Val
                STR     R1, [R0, #MCST3_T_WEWD_OFS]
                LDR     R1, =MCST3_T_WE2CE_Val
                STR     R1, [R0, #MCST3_T_WE2CE_OFS]
                LDR     R1, =MCST3_T_CEWDR_Val
                STR     R1, [R0, #MCST3_T_CEWDR_OFS]
                LDR     R1, =MCST3_T_CE2RD_Val
                STR     R1, [R0, #MCST3_T_CE2RD_OFS]
                LDR     R1, =MCST3_T_RDWD_Val
                STR     R1, [R0, #MCST3_T_RDWD_OFS]
                LDR     R1, =MCST3_T_RD2CE_Val
                STR     R1, [R0, #MCST3_T_RD2CE_OFS]
                LDR     R1, =MCST3_BASIC_Val
                STR     R1, [R0, #MCST3_BASIC_OFS]
                ENDIF   ;(:LNOT::DEF:MCST3_NO_INIT):LAND:(MCST3_SETUP != 0)
                ENDIF   ;(:LNOT::DEF:MC_NO_INIT):LAND:(MC_SETUP != 0)


; Cache Controller Setup -------------------------------------------------------

                IF      (:LNOT::DEF:CACHE_NO_INIT):LAND:(CACHE_SETUP != 0)
                LDR     R0, =CACHE_BASE
                LDR     R1, =MEMMAPA_Val
                STR     R1, [R0, #MEMMAPA_OFS]
                LDR     R1, =MEMMAPB_Val
                STR     R1, [R0, #MEMMAPB_OFS]
                LDR     R1, =MEMMAPC_Val
                STR     R1, [R0, #MEMMAPC_OFS]
                LDR     R1, =MEMMAPD_Val
                STR     R1, [R0, #MEMMAPD_OFS]
                LDR     R1, =PFCNTRA_CTRL_Val
                STR     R1, [R0, #PFCNTRA_CTRL_OFS]
                LDR     R1, =PFCNTRB_CTRL_Val
                STR     R1, [R0, #PFCNTRB_CTRL_OFS]

                LDR     R1, =CACHE_EN
                STR     R1, [R0, #DEVID_OFS]
                ENDIF   ;(:LNOT::DEF:CACHE_NO_INIT):LAND:(CACHE_SETUP != 0)


; AHB Bus Arbiter Setup --------------------------------------------------------

                IF      (:LNOT::DEF:ARB_NO_INIT):LAND:(ARB_SETUP != 0)
                LDR     R0, =ARB_BASE
                LDR     R1, =ARB_PRIO1_Val
                STR     R1, [R0, #ARB_PRIO1_OFS]
                LDR     R1, =ARB_PRIO2_Val
                STR     R1, [R0, #ARB_PRIO2_OFS]
                LDR     R1, =ARB_PRIO3_Val
                STR     R1, [R0, #ARB_PRIO3_OFS]
                LDR     R1, =ARB_PRIO4_Val
                STR     R1, [R0, #ARB_PRIO4_OFS]
                LDR     R1, =ARB_PRIO5_Val
                STR     R1, [R0, #ARB_PRIO5_OFS]
                LDR     R1, =ARB_PRIO6_Val
                STR     R1, [R0, #ARB_PRIO6_OFS]
                LDR     R1, =ARB_PRIO7_Val
                STR     R1, [R0, #ARB_PRIO7_OFS]
                LDR     R1, =ARB_PRIO8_Val
                STR     R1, [R0, #ARB_PRIO8_OFS]
                LDR     R1, =ARB_PRIO9_Val
                STR     R1, [R0, #ARB_PRIO9_OFS]
                LDR     R1, =ARB_PRIO10_Val
                STR     R1, [R0, #ARB_PRIO10_OFS]
                LDR     R1, =ARB_PRIO11_Val
                STR     R1, [R0, #ARB_PRIO11_OFS]
                LDR     R1, =ARB_PRIO12_Val
                STR     R1, [R0, #ARB_PRIO12_OFS]
                LDR     R1, =ARB_PRIO13_Val
                STR     R1, [R0, #ARB_PRIO13_OFS]
                LDR     R1, =ARB_PRIO14_Val
                STR     R1, [R0, #ARB_PRIO14_OFS]
                LDR     R1, =ARB_PRIO15_Val
                STR     R1, [R0, #ARB_PRIO15_OFS]
                LDR     R1, =ARB_MODE_Val
                STR     R1, [R0, #ARB_MODE_OFS]
                ENDIF   ;(:LNOT::DEF:ARB_NO_INIT):LAND:(ARB_SETUP != 0)


;  SDRAM Remap -----------------------------------------------------------------

                IF      (:DEF:REMAP)
                LDR     R1, =SCU_BASE
                LDR     R2, =REMAP_SDRAM
                STR     R2, [R1, #SCU_CFGC_OFS]
                ENDIF   ;(:DEF:REMAP)


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
