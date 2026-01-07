;/*****************************************************************************/
;/* startup_BU1511KV2.s: Startup file for Rohm BU1511KV2 device series        */
;/*****************************************************************************/
;/* <<< Use Configuration Wizard in Context Menu >>>                          */ 
;/*****************************************************************************/
;/* This file is part of the uVision/ARM development tools.                   */
;/* Copyright (c) 2009-2010 KEIL - An ARM Company. All rights reserved.       */
;/* This software may only be used under the terms of a valid, current,       */
;/* end user licence from KEIL for a compatible version of KEIL software      */
;/* development tools. Nothing else gives you the right to use this software. */
;/*****************************************************************************/


; The startup_BU1511KV2.s code is executed after CPU Reset. This file may be 
; translated with the following SET symbols. In uVision these SET 
; symbols are entered under Options - ASM - Define.
;
; TCM_NO_INIT:         if set, the TCM cach is not enabled
;
; CLOCK_NO_INIT:       if set, the clock controller is not initialized
;
; EMC1_NO_INIT:        if set, the external memory controller  #1
;                      controlling CS0 and CS1 is not initialized
;
; EMC2_NO_INIT:        if set, the external memory controller  #2
;                      controlling CS2 and CS3 is not initialized
;
; CS0_NO_INIT:         if set, the CS0 settings are not initialized
;
; CS1_NO_INIT:         if set, the CS1 settings are not initialized
;
; CS2_NO_INIT:         if set, the CS2 settings are not initialized
;
; CS3_NO_INIT:         if set, the CS3 settings are not initialized


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
USR_Stack_Size  EQU     0x00000100

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


;----------------------- TCM Definitions -------------------------------------

; TCM User Interface
ROM_BASE       EQU     0x00000000
RAM_BASE       EQU     0x10000000

; Constants
I_TCM_LD       EQU     (1 << 19)         ; Instruction TCM load mode
I_TCM_EN       EQU     (1 << 18)         ; Instruction TCM enable
D_TCM_LD       EQU     (1 << 17)         ; Data TCM load mode
D_TCM_EN       EQU     (1 << 16)         ; Data TCM enable

; <e> TCM Configuration
;   <o1.18>      I_TCM_EN: I-TCM  enable
;   <o1.16>      D_TCM_EN: D-TCM  enable
; </e>

TCM_SETUP        EQU     1
CP15_CTRL_Val    EQU     0x00050000


;----------------------- Clock Definitions -------------------------------------

; Clock Controller User Interface
CLOCK_BASE      EQU     0xC0006000
CLKCNT_Ofs      EQU     0x00
PLLCNT_Ofs      EQU     0x04
CLKARM_Ofs      EQU     0x10
CLKADC_Ofs      EQU     0x14
CLKIMG_Ofs      EQU     0x18
CLKTVE_Ofs      EQU     0x1C
CLKSDC_Ofs      EQU     0x20
CLKAUD_Ofs      EQU     0x24

; Constants
PLLON_BIT       EQU     (1 << 0)
PLL_WAIT_Val    EQU      0x100               ;just to test

; <e> Clock Configuration
;   <h> Clock Control Register (CLKCNT)
;     <o1.0>      AXIN_EN: AXIN clock enable
;   </h>
;   <h> PLL Control Register (PLLCNT)
;     <i> fVCO = fXIN * MUL_I / DIV_I
;     <i> fVCO must be in the range of 100MHz..200MHz
;     <i> fPLL = fXIN * MUL_I / (DIV_I * DIV_O)
;     <o2.0>      EN: PLL enable
;     <o2.4>      DIV_I: Input clock devider
;                   <0=> 4
;                   <1=> 2
;     <o2.8>      DIV_O: Output clock devider
;                   <0=> 4
;                   <1=> 2
;     <o2.12..15> MUL_I: Input clock multiplier
;                   <1=>  64
;                   <2=>  60
;                   <3=>  56
;                   <4=>  52
;                   <5=>  48
;                   <6=>  44
;                   <7=>  40
;                   <8=>  36
;                   <9=>  32
;                   <10=> 28
;                   <11=> 24
;                   <12=> 20
;                   <13=> 16
;   </h>
;   <h> System Clock Configuration Register (CLKARM)
;     <i> clock out: (CLK_SEL / CLK_DIV) / P2_DIV
;     <i> Post 2 Devider forces duty cycle 1/2
;     <o3.0..2>   CLK_SEL: Clock Selector
;                   <1=> XIN 
;                   <2=> PLL_OUT
;                   <4=> AXIN
;     <o3.8..14>  CLK_DIV: Clock Devider
;                   <1-128><#-1>
;     <o3.15>     P2_DIV: Post 2 Devider
;   </h>
;   <h> ADC Clock Configuration Register (CLKADC)
;     <i> clock out: (CLK_SEL / CLK_DIV) / P2_DIV
;     <i> Post 2 Devider forces duty cycle 1/2
;     <o4.0..2>   CLK_SEL: Clock Selector
;                   <1=> XIN 
;                   <2=> PLL_OUT
;                   <4=> AXIN
;     <o4.8..14>  CLK_DIV: Clock Devider
;                   <1-128><#-1>
;     <o4.15>     P2_DIV: Post 2 Devider
;   </h>
;   <h> Image Processing Clock Configuration Register (CLKIMG)
;     <i> clock out: (CLK_SEL / CLK_DIV) / P2_DIV
;     <i> Post 2 Devider forces duty cycle 1/2
;     <o5.0..2>   CLK_SEL: Clock Selector
;                   <1=> XIN 
;                   <2=> PLL_OUT
;                   <4=> AXIN
;     <o5.8..14>  CLK_DIV: Clock Devider
;                   <1-128><#-1>
;     <o5.15>     P2_DIV: Post 2 Devider
;   </h>
;   <h> TV Encoder Clock Configuration Register (CLKTVE)
;     <i> clock out: (CLK_SEL / CLK_DIV) / P2_DIV
;     <i> Post 2 Devider forces duty cycle 1/2
;     <o6.0..2>   CLK_SEL: Clock Selector
;                   <1=> XIN 
;                   <2=> PLL_OUT
;                   <4=> AXIN
;     <o6.8..14>  CLK_DIV: Clock Devider
;                   <1-128><#-1>
;     <o6.15>     P2_DIV: Post 2 Devider
;   </h>
;   <h> SD-Card Clock Configuration Register (CLKSDC)
;     <i> clock out: (CLK_SEL / CLK_DIV) / P2_DIV
;     <i> Post 2 Devider forces duty cycle 1/2
;     <o7.0..2>   CLK_SEL: Clock Selector
;                   <1=> XIN 
;                   <2=> PLL_OUT
;                   <4=> AXIN
;     <o7.8..14>  CLK_DIV: Clock Devider
;                   <1-128><#-1>
;     <o7.15>     P2_DIV: Post 2 Devider
;   </h>
;   <h> Audio Clock Configuration Register (CLKAUD)
;     <i> clock out: (CLK_SEL / CLK_DIV) / P2_DIV
;     <i> Post 2 Devider forces duty cycle 1/2
;     <o8.0..2>   CLK_SEL: Clock Selector
;                   <1=> XIN 
;                   <2=> PLL_OUT
;                   <4=> AXIN
;     <o8.8..14>  CLK_DIV: Clock Devider
;                   <1-128><#-1>
;     <o8.15>     P2_DIV: Post 2 Devider
;   </h>
; </e>

CLOCK_SETUP      EQU     1
CLKCNT_Val       EQU     0x00000000
PLLCNT_Val       EQU     0x00005101
CLKARM_Val       EQU     0x00008002
CLKADC_Val       EQU     0x00008001
CLKIMG_Val       EQU     0x00008001
CLKTVE_Val       EQU     0x00008001
CLKSDC_Val       EQU     0x00008001
CLKAUD_Val       EQU     0x00008002


;------------- External Memory Controller #1 Definitions -----------------------

; External Memory Controller #1 User Interface
EMC1_BASE             EQU     0x90000000
EMC1_SCSLR0_LOW_Ofs   EQU     0x14
EMC1_SCSLR1_LOW_Ofs   EQU     0x18
EMC1_SMSKR0_Ofs       EQU     0x54
EMC1_SMSKR1_Ofs       EQU     0x58
EMC1_CSALIAS0_LOW_Ofs EQU     0x74
EMC1_CSALIAS1_LOW_Ofs EQU     0x78
EMC1_SMTMGR_SET0_Ofs  EQU     0x94
EMC1_SMTMGR_SET1_Ofs  EQU     0x98
EMC1_SMTMGR_SET2_Ofs  EQU     0x9C
EMC1_FLASH_TRPDR_Ofs  EQU     0xA0
EMC1_SMCTLR_Ofs       EQU     0xA4

; <e> External Memory Controller #1 Configuration
;   <e1> CS0 Configuration
;     <h> Chip Select Addressing Register (SCSLR0_LOW)
;       <o3.16..31> ADDR: Upper 16bit of CS base address      <0x0-0xFFFF>
;     </h>
;     <h> Mask Register (SMSKR0_LOW)
;       <o4.0..4>   MEM_SIZE: Memory Size                     <0x0-0x1F>
;         <i>  0 = No Memory connected
;         <i> Size Definition: 64KB * (MEM_SIZEth power of 2)
;       <o4.5..7>   MEM_TYPE: Memory Type
;                     <1=> SRAM 
;                     <2=> FLASH
;       <o4.8..10>  TIM_REG: Timing Register to use
;                     <0=> SMTMGR_SET0 
;                     <1=> SMTMGR_SET1
;                     <2=> SMTMGR_SET2
;     </h>
;     <h> Chip Select Alias Register (CSALIAS0_LOW) 
;       <o5.16..31> ADDR: Lower aliasing Chip Select Register <0x0-0xFFFF>
;     </h>
;   </e>
;   <e2> CS1 Configuration
;     <h> Chip Select Addressing Register (SCSLR1_LOW)
;       <o6.16..31> ADDR: Upper 16bit of CS base address      <0x0-0xFFFF>
;     </h>
;     <h> Mask Register (SMSKR1_LOW)
;       <o7.0..4>   MEM_SIZE: Memory Size                     <0x0-0x1F>
;         <i>  0 = No Memory connected
;         <i> Size Definition: 64KB * (MEM_SIZEth power of 2)
;       <o7.5..7>   MEM_TYPE: Memory Type
;                     <1=> SRAM 
;                     <2=> FLASH
;       <o7.8..10>  TIM_REG: Timing Register to use
;                     <0=> SMTMGR_SET0 
;                     <1=> SMTMGR_SET1
;                     <2=> SMTMGR_SET2
;     </h>
;     <h> Chip Select Alias Register (CSALIAS1_LOW) 
;       <o8.16..31> ADDR: Lower aliasing Chip Select Register <0x0-0xFFFF>
;     </h>
;   </e>
;   <h> Static Memory Timing Register
;     <h> Static Memory Timing Set0 (SMTMGR_SET0)
;       <o9.0..5>    T_RC: Read Cycle Time                    <0x0-0x3F>
;       <o9.6..7>    T_AS: Write Address Setup Time           <0x0-0x3>
;       <o9.8..9>    T_WR: Write Address/Data Hold Time       <0x0-0x3>
;       <o9.10..15>  T_WP: Write Pulse Width                  <0x0-0x3F>
;       <o9.16..18>  T_BTA: Idle Cycles between Read to Write <0x0-0x7>
;       <o9.19..22>  T_PRC: Page Mode Read Cycle Time         <0x0-0xF>
;       <o9.23>      PAGE_MODE: Page Mode Enable
;       <o9.24..25>  PAGE_SIZE: Page Memory Size 
;                     <0=> 4 Word 
;                     <1=> 8 Word 
;                     <2=> 16 Word 
;                     <3=> 32 Word
;     </h>
;     <h> Static Memory Timing Set0 (SMTMGR_SET1)
;       <o10.0..5>   T_RC: Read Cycle Time                    <0x0-0x3F>
;       <o10.6..7>   T_AS: Write Address Setup Time           <0x0-0x3>
;       <o10.8..9>   T_WR: Write Address/Data Hold Time       <0x0-0x3>
;       <o10.10..15> T_WP: Write Pulse Width                  <0x0-0x3F>
;       <o10.16..18> T_BTA: Idle Cycles between Read to Write <0x0-0x7>
;       <o10.19..22> T_PRC: Page Mode Read Cycle Time         <0x0-0xF>
;       <o10.23>     PAGE_MODE: Page Mode Enable
;       <o10.24..25> PAGE_SIZE: Page Memory Size 
;                     <0=> 4 Word 
;                     <1=> 8 Word 
;                     <2=> 16 Word 
;                     <3=> 32 Word
;     </h>
;     <h> Static Memory Timing Set0 (SMTMGR_SET2)
;       <o11.0..5>   T_RC: Read Cycle Time                    <0x0-0x3F>
;       <o11.6..7>   T_AS: Write Address Setup Time           <0x0-0x3>
;       <o11.8..9>   T_WR: Write Address/Data Hold Time       <0x0-0x3>
;       <o11.10..15> T_WP: Write Pulse Width                  <0x0-0x3F>
;       <o11.16..18> T_BTA: Idle Cycles between Read to Write <0x0-0x7>
;       <o11.19..22> T_PRC: Page Mode Read Cycle Time         <0x0-0xF>
;       <o11.23>     PAGE_MODE: Page Mode Enable
;       <o11.24..25> PAGE_SIZE: Page Memory Size 
;                     <0=> 4 Word 
;                     <1=> 8 Word 
;                     <2=> 16 Word 
;                     <3=> 32 Word
;     </h>
;   </h>
;   <h> FLASH Access Delay Register (FLASH_TRPDR)
;     <o12.0..31>  WAIT_T: Wait time in System Clock Cycles
;   </h>
;   <h> Bus Access Control Register (SMCTLR)
;     <o13.0>      SM_RP_N: Remove FLASH Power Down
;     <o13.1..3>   WP_N: Flash Write Protection Mode          <0x0-0x7> 
;     <o13.7..9>   SM_DATA_WIDTH_SET0:  Width of Static Memory Controlled by SMTMGR_SET0
;                     <0=> 16 bits 
;                     <1=> 32 bits 
;                     <2=> 64 bits 
;                     <3=> 128 bits 
;                     <4=> 8 bits 
;     <o13.10..12> SM_DATA_WIDTH_SET1:  Width of Static Memory Controlled by SMTMGR_SET1
;                     <0=> 16 bits 
;                     <1=> 32 bits 
;                     <2=> 64 bits 
;                     <3=> 128 bits 
;                     <4=> 8 bits 
;     <o13.13..15> SM_DATA_WIDTH_SET2:  Width of Static Memory Controlled by SMTMGR_SET2
;                     <0=> 16 bits 
;                     <1=> 32 bits 
;                     <2=> 64 bits 
;                     <3=> 128 bits 
;                     <4=> 8 bits 
;   </h>
; </e>

EMC1_SETUP             EQU     1
EMC1_CS0_SETUP         EQU     0
EMC1_CS1_SETUP         EQU     1
EMC1_SCSLR0_LOW_Val    EQU     0x00000000
EMC1_SMSKR0_Val        EQU     0x00000047
EMC1_CSALIAS0_LOW_Val  EQU     0x40000000
EMC1_SCSLR1_LOW_Val    EQU     0x10000000
EMC1_SMSKR1_Val        EQU     0x00000124
EMC1_CSALIAS1_LOW_Val  EQU     0x50000000
EMC1_SMTMGR_SET0_Val   EQU     0x0003FFFF
EMC1_SMTMGR_SET1_Val   EQU     0x00180803
EMC1_SMTMGR_SET2_Val   EQU     0x001C4F5B
EMC1_FLASH_TRPDR_Val   EQU     0x000000C8
EMC1_SMCTLR_Val        EQU     0x00009003


;------------- External Memory Controller #2 Definitions -----------------------

; External Memory Controller #2 User Interface
EMC2_BASE             EQU     0xA0000000
EMC2_SCSLR0_LOW_Ofs   EQU     0x14
EMC2_SCSLR1_LOW_Ofs   EQU     0x18
EMC2_SMSKR0_Ofs       EQU     0x54
EMC2_SMSKR1_Ofs       EQU     0x58
EMC2_CSALIAS0_LOW_Ofs EQU     0x74
EMC2_CSALIAS1_LOW_Ofs EQU     0x78
EMC2_SMTMGR_SET0_Ofs  EQU     0x94
EMC2_SMTMGR_SET1_Ofs  EQU     0x98
EMC2_SMTMGR_SET2_Ofs  EQU     0x9C
EMC2_FLASH_TRPDR_Ofs  EQU     0xA0
EMC2_SMCTLR_Ofs       EQU     0xA4

; <e> External Memory Controller #2 Configuration
;   <e1> CS2 Configuration
;     <h> Chip Select Addressing Register (SCSLR0_LOW)
;       <o3.16..31> ADDR: Upper 16bit of CS base address      <0x0-0xFFFF>
;     </h>
;     <h> Mask Register (SMSKR0_LOW)
;       <o4.0..4>   MEM_SIZE: Memory Size                     <0x0-0x1F>
;         <i>  0 = No Memory connected
;         <i> Size Definition: 64KB * (MEM_SIZEth power of 2)
;       <o4.5..7>   MEM_TYPE: Memory Type
;                     <1=> SRAM 
;                     <2=> FLASH
;       <o4.8..10>  TIM_REG: Timing Register to use
;                     <0=> SMTMGR_SET0 
;                     <1=> SMTMGR_SET1
;                     <2=> SMTMGR_SET2
;     </h>
;     <h> Chip Select Alias Register (CSALIAS0_LOW) 
;       <o5.16..31> ADDR: Lower aliasing Chip Select Register <0x0-0xFFFF>
;     </h>
;   </e>
;   <e2> CS3 Configuration
;     <h> Chip Select Addressing Register (SCSLR1_LOW)
;       <o6.16..31> ADDR: Upper 16bit of CS base address      <0x0-0xFFFF>
;     </h>
;     <h> Mask Register (SMSKR1_LOW)
;       <o7.0..4>   MEM_SIZE: Memory Size                     <0x0-0x1F>
;         <i>  0 = No Memory connected
;         <i> Size Definition: 64KB * (MEM_SIZEth power of 2)
;       <o7.5..7>   MEM_TYPE: Memory Type
;                     <1=> SRAM 
;                     <2=> FLASH
;       <o7.8..10>  TIM_REG: Timing Register to use
;                     <0=> SMTMGR_SET0 
;                     <1=> SMTMGR_SET1
;                     <2=> SMTMGR_SET2
;     </h>
;     <h> Chip Select Alias Register (CSALIAS1_LOW) 
;       <o8.16..31> ADDR: Lower aliasing Chip Select Register <0x0-0xFFFF>
;     </h>
;   </e>
;   <h> Static Memory Timing Register
;     <h> Static Memory Timing Set0 (SMTMGR_SET0)
;       <o9.0..5>    T_RC: Read Cycle Time                    <0x0-0x3F>
;       <o9.6..7>    T_AS: Write Address Setup Time           <0x0-0x3>
;       <o9.8..9>    T_WR: Write Address/Data Hold Time       <0x0-0x3>
;       <o9.10..15>  T_WP: Write Pulse Width                  <0x0-0x3F>
;       <o9.16..18>  T_BTA: Idle Cycles between Read to Write <0x0-0x7>
;       <o9.19..22>  T_PRC: Page Mode Read Cycle Time         <0x0-0xF>
;       <o9.23>      PAGE_MODE: Page Mode Enable
;       <o9.24..25>  PAGE_SIZE: Page Memory Size 
;                     <0=> 4 Word 
;                     <1=> 8 Word 
;                     <2=> 16 Word 
;                     <3=> 32 Word
;     </h>
;     <h> Static Memory Timing Set0 (SMTMGR_SET1)
;       <o10.0..5>   T_RC: Read Cycle Time                    <0x0-0x3F>
;       <o10.6..7>   T_AS: Write Address Setup Time           <0x0-0x3>
;       <o10.8..9>   T_WR: Write Address/Data Hold Time       <0x0-0x3>
;       <o10.10..15> T_WP: Write Pulse Width                  <0x0-0x3F>
;       <o10.16..18> T_BTA: Idle Cycles between Read to Write <0x0-0x7>
;       <o10.19..22> T_PRC: Page Mode Read Cycle Time         <0x0-0xF>
;       <o10.23>     PAGE_MODE: Page Mode Enable
;       <o10.24..25> PAGE_SIZE: Page Memory Size 
;                     <0=> 4 Word 
;                     <1=> 8 Word 
;                     <2=> 16 Word 
;                     <3=> 32 Word
;     </h>
;     <h> Static Memory Timing Set0 (SMTMGR_SET2)
;       <o11.0..5>   T_RC: Read Cycle Time                    <0x0-0x3F>
;       <o11.6..7>   T_AS: Write Address Setup Time           <0x0-0x3>
;       <o11.8..9>   T_WR: Write Address/Data Hold Time       <0x0-0x3>
;       <o11.10..15> T_WP: Write Pulse Width                  <0x0-0x3F>
;       <o11.16..18> T_BTA: Idle Cycles between Read to Write <0x0-0x7>
;       <o11.19..22> T_PRC: Page Mode Read Cycle Time         <0x0-0xF>
;       <o11.23>     PAGE_MODE: Page Mode Enable
;       <o11.24..25> PAGE_SIZE: Page Memory Size 
;                     <0=> 4 Word 
;                     <1=> 8 Word 
;                     <2=> 16 Word 
;                     <3=> 32 Word
;     </h>
;   </h>
;   <h> FLASH Access Delay Register (FLASH_TRPDR)
;     <o12.0..31>  WAIT_T: Wait time in System Clock Cycles
;   </h>
;   <h> Bus Access Control Register (SMCTLR)
;     <o13.0>      SM_RP_N: Remove FLASH Power Down
;     <o13.1..3>   WP_N: Flash Write Protection Mode          <0x0-0x7>
;     <o13.7..9>   SM_DATA_WIDTH_SET0:  Width of Static Memory Controlled by SMTMGR_SET0
;                     <0=> 16 bits 
;                     <1=> 32 bits 
;                     <2=> 64 bits 
;                     <3=> 128 bits 
;                     <4=> 8 bits 
;     <o13.10..12> SM_DATA_WIDTH_SET1:  Width of Static Memory Controlled by SMTMGR_SET1
;                     <0=> 16 bits 
;                     <1=> 32 bits 
;                     <2=> 64 bits 
;                     <3=> 128 bits 
;                     <4=> 8 bits 
;     <o13.13..15> SM_DATA_WIDTH_SET2:  Width of Static Memory Controlled by SMTMGR_SET2
;                     <0=> 16 bits 
;                     <1=> 32 bits 
;                     <2=> 64 bits 
;                     <3=> 128 bits 
;                     <4=> 8 bits 
;   </h>
; </e>

EMC2_SETUP             EQU     0
EMC2_CS2_SETUP         EQU     0
EMC2_CS3_SETUP         EQU     0
EMC2_SCSLR0_LOW_Val    EQU     0x20000000
EMC2_SMSKR0_Val        EQU     0x00000207
EMC2_CSALIAS0_LOW_Val  EQU     0x60000000
EMC2_SCSLR1_LOW_Val    EQU     0x30000000
EMC2_SMSKR1_Val        EQU     0x00000227
EMC2_CSALIAS1_LOW_Val  EQU     0x70000000
EMC2_SMTMGR_SET0_Val   EQU     0x00004954
EMC2_SMTMGR_SET1_Val   EQU     0x00000944
EMC2_SMTMGR_SET2_Val   EQU     0x00000543
EMC2_FLASH_TRPDR_Val   EQU     0x000000C8
EMC2_SMCTLR_Val        EQU     0x0000000F


;----------------- Interrupt Controller Definitions ----------------------------

; Interrupt Controller User Interface
INTCTL_BASE          EQU       0xC0007000
INTCTL_INTEN_I_Ofs   EQU       0x00
INTCTL_INTMASK_I_Ofs EQU       0x08

INTCTL_INTEN_I_Val   EQU       0x00000000
INTCTL_INTMASK_I_Val EQU       0x0000FFFF


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
                NOP                                       ; Reserved Vector 
                LDR     PC,IRQ_Addr
                LDR     PC,FIQ_Addr

                IMPORT  IRQ_Handler

Reset_Addr      DCD     Reset_Handler
Undef_Addr      DCD     Undef_Handler
SWI_Addr        DCD     SWI_Handler
PAbt_Addr       DCD     PAbt_Handler
DAbt_Addr       DCD     DAbt_Handler
                DCD     0                                 ; Reserved Address 
IRQ_Addr        DCD     IRQ_Handler
FIQ_Addr        DCD     FIQ_Handler

Undef_Handler   B       Undef_Handler
SWI_Handler     B       SWI_Handler
PAbt_Handler    B       PAbt_Handler
DAbt_Handler    B       DAbt_Handler
;IRQ_Handler    B       IRQ_Handler                      ; see IRQSYS.s
FIQ_Handler     B       FIQ_Handler


; Reset Handler

                EXPORT  Reset_Handler
Reset_Handler   

; Test -------------------------------------------------------------------------
;                LDR     R2, =300000                       ; Number of cycles to delay
;Wait_0          SUBS    R2, R2, #1                        ; Delay ~100 ms @ proc clk 13,5 MHz
;                BNE     Wait_0

; TCM Cache --------------------------------------------------------------------
                IF      (:LNOT::DEF:TCM_NO_INIT):LAND:(TCM_SETUP != 0)

                MRC p15, 0, R0, c0, c0, 2                 ; read CP15 Register 0, Tightly-coupled Memory Size Register
                MRC p15, 0, R1, c1, c0, 0                 ; read CP15 Register 1, Control Register
                BIC R1, R1, #I_TCM_EN:OR:D_TCM_EN         ; Instruction TCM and Data Cache disable
                MCR p15, 0, R1, c1, c0, 0

; if I-TCM available and I-TCM enabled
                LSRS R2, R0, #3                           ; I-TCM available = CL15.R0 bit2 = 0
                BCS End_I_TCM

                IF      (CP15_CTRL_Val:AND:I_TCM_EN) != 0
; copy I-TCM for I-TCM size
                MOV R2, R0, LSR#6                         ; Instruction TCM size = CL15.R0 bit6..9
                AND R2, #0x0F                             ; Mask 4 bits
                SUB R2, #1

                MOV R3, #0x400                            ; size = 1kB * 2 ^ (size-1)
                LSL R3, R3, R2
                SUB R3, R3, #1                            ; R3 contains I-TCM size in kB

                LDR R2, =ROM_BASE                         ; R2 contains Start address
                ADD R3, R2, R3                            ; R3 contains End Address

                ORR R1, R1, #(I_TCM_LD:OR:I_TCM_EN)
                MCR p15, 0, R1, c1, c0, 0                 ; Enable I-TCM cache and I-TCM Load Mode
Copy_I_TCM
                LDMIA R2,  {R4 - R11}                     ; Load 8 registers from main memory
                STMIA R2!, {R4 - R11}                     ; Store 8 regs into Instruction TCM
                CMP R3, R2                                ; Check if limit reached
                BGT Copy_I_TCM                            ; Repeat if more to do

                BIC R1, R1, #(I_TCM_LD)                   ; Clear Load Mode
                MCR p15, 0, R1, c1, c0, 0

                ENDIF ; (CP15_CTRL_Val:AND:I_TCM_EN) != 0
End_I_TCM

; if D-TCM available and D-TCM enabled
                LSRS R2, R0, #14                          ; D-TCM available = CL15.R0 bit14 = 0
                BCS End_D_TCM

                IF      (CP15_CTRL_Val:AND:D_TCM_EN) != 0
; data for D-TCM cache needs not to be copied
                ORR R1, R1, #(D_TCM_EN)                   ; Enable D-TCM cache
                MCR p15, 0, R1, c1, c0, 0

                ENDIF ; (CP15_CTRL_Val:AND:D_TCM_EN) != 0
End_D_TCM

                ENDIF   ;(:LNOT::DEF:TCM_NO_INIT):LAND:(TCM_SETUP != 0)

; Interrupt Controller ---------------------------------------------------------
                LDR     R0, =INTCTL_BASE
                LDR     R1, =INTCTL_INTEN_I_Val           ; disable all interrupts
                STR     R1, [R0, #INTCTL_INTEN_I_Ofs]
                LDR     R1, =INTCTL_INTMASK_I_Val         ; mask    all interrupts
                STR     R1, [R0, #INTCTL_INTMASK_I_Ofs]

; Clock Setup ------------------------------------------------------------------
                IF      (:LNOT::DEF:CLOCK_NO_INIT):LAND:(CLOCK_SETUP != 0)
                LDR     R0, =CLOCK_BASE
                LDR     R1, =CLKCNT_Val
                STR     R1, [R0, #CLKCNT_Ofs]

                IF      (PLLCNT_Val:AND:PLLON_BIT) != 0
                LDR     R1, =PLLCNT_Val
                STR     R1, [R0, #PLLCNT_Ofs]
                LDR     R2, =PLL_WAIT_Val
PLL_Lock        SUBS    R2, R2, #1                        ; not shure if this is needed but there is no PLL_LOCK bit
                BNE     PLL_Lock
                ENDIF   ;(PLLCNT_Val:AND:PLLON_BIT) != 0

                LDR     R1, =CLKARM_Val
                STR     R1, [R0, #CLKARM_Ofs]
                LDR     R1, =CLKADC_Val
                STR     R1, [R0, #CLKADC_Ofs]
                LDR     R1, =CLKIMG_Val
                STR     R1, [R0, #CLKIMG_Ofs]
                LDR     R1, =CLKTVE_Val
                STR     R1, [R0, #CLKTVE_Ofs]
                LDR     R1, =CLKSDC_Val
                STR     R1, [R0, #CLKSDC_Ofs]
                LDR     R1, =CLKAUD_Val
                STR     R1, [R0, #CLKAUD_Ofs]
                ENDIF   ;(:LNOT::DEF:CLOCK_NO_INIT):LAND:(CLOCK_SETUP != 0)

; External Memory Controller #1 Setup ------------------------------------------
                IF      (:LNOT::DEF:EMC1_NO_INIT):LAND:(EMC1_SETUP != 0)
                LDR     R0, =EMC1_BASE

                ; CS0 Setup ------------------------------------------
                IF      (:LNOT::DEF:CS0_NO_INIT):LAND:(EMC1_CS0_SETUP != 0)
                LDR     R1, =EMC1_SCSLR0_LOW_Val
                STR     R1, [R0, #EMC1_SCSLR0_LOW_Ofs]
                LDR     R1, =EMC1_SMSKR0_Val
                STR     R1, [R0, #EMC1_SMSKR0_Ofs]
                LDR     R1, =EMC1_CSALIAS0_LOW_Val
                STR     R1, [R0, #EMC1_CSALIAS0_LOW_Ofs]
                ENDIF   ;(:LNOT::DEF:CS0_NO_INIT):LAND:(EMC1_CS0_SETUP != 0

                ; CS1 Setup ------------------------------------------
                IF      (:LNOT::DEF:CS1_NO_INIT):LAND:(EMC1_CS1_SETUP != 0)
                LDR     R1, =EMC1_SCSLR1_LOW_Val
                STR     R1, [R0, #EMC1_SCSLR1_LOW_Ofs]
                LDR     R1, =EMC1_SMSKR1_Val
                STR     R1, [R0, #EMC1_SMSKR1_Ofs]
                LDR     R1, =EMC1_CSALIAS1_LOW_Val
                STR     R1, [R0, #EMC1_CSALIAS1_LOW_Ofs]
                ENDIF   ;(:LNOT::DEF:CS1_NO_INIT):LAND:(EMC1_CS1_SETUP != 0

                LDR     R1, =EMC1_SMTMGR_SET0_Val
                STR     R1, [R0, #EMC1_SMTMGR_SET0_Ofs]
                LDR     R1, =EMC1_SMTMGR_SET1_Val
                STR     R1, [R0, #EMC1_SMTMGR_SET1_Ofs]
                LDR     R1, =EMC1_SMTMGR_SET2_Val
                STR     R1, [R0, #EMC1_SMTMGR_SET2_Ofs]
                LDR     R1, =EMC1_FLASH_TRPDR_Val
                STR     R1, [R0, #EMC1_FLASH_TRPDR_Ofs]
                LDR     R1, =EMC1_SMCTLR_Val
                STR     R1, [R0, #EMC1_SMCTLR_Ofs]

                ENDIF   ;(:LNOT::DEF:EMC1_NO_INIT):LAND:(EMC1_SETUP != 0)

; External Memory Controller #2 Setup ------------------------------------------
                IF      (:LNOT::DEF:EMC2_NO_INIT):LAND:(EMC2_SETUP != 0)
                LDR     R0, =EMC2_BASE

                ; CS2 Setup ------------------------------------------
                IF      (:LNOT::DEF:CS2_NO_INIT):LAND:(EMC2_CS2_SETUP != 0)
                LDR     R1, =EMC2_SCSLR0_LOW_Val
                STR     R1, [R0, #EMC2_SCSLR0_LOW_Ofs]
                LDR     R1, =EMC2_SMSKR0_Val
                STR     R1, [R0, #EMC2_SMSKR0_Ofs]
                LDR     R1, =EMC2_CSALIAS0_LOW_Val
                STR     R1, [R0, #EMC2_CSALIAS0_LOW_Ofs]
                ENDIF   ;(:LNOT::DEF:CS2_NO_INIT):LAND:(EMC2_CS2_SETUP != 0

                ; CS3 Setup ------------------------------------------
                IF      (:LNOT::DEF:CS3_NO_INIT):LAND:(EMC2_CS3_SETUP != 0)
                LDR     R1, =EMC2_SCSLR1_LOW_Val
                STR     R1, [R0, #EMC2_SCSLR1_LOW_Ofs]
                LDR     R1, =EMC2_SMSKR1_Val
                STR     R1, [R0, #EMC2_SMSKR1_Ofs]
                LDR     R1, =EMC2_CSALIAS1_LOW_Val
                STR     R1, [R0, #EMC2_CSALIAS1_LOW_Ofs]
                ENDIF   ;(:LNOT::DEF:CS3_NO_INIT):LAND:(EMC2_CS3_SETUP != 0

                LDR     R1, =EMC2_SMTMGR_SET0_Val
                STR     R1, [R0, #EMC2_SMTMGR_SET0_Ofs]
                LDR     R1, =EMC2_SMTMGR_SET1_Val
                STR     R1, [R0, #EMC2_SMTMGR_SET1_Ofs]
                LDR     R1, =EMC2_SMTMGR_SET2_Val
                STR     R1, [R0, #EMC2_SMTMGR_SET2_Ofs]
                LDR     R1, =EMC2_FLASH_TRPDR_Val
                STR     R1, [R0, #EMC2_FLASH_TRPDR_Ofs]
                LDR     R1, =EMC2_SMCTLR_Val
                STR     R1, [R0, #EMC2_SMCTLR_Ofs]

                ENDIF   ;(:LNOT::DEF:EMC2_NO_INIT):LAND:(EMC2_SETUP != 0)


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



