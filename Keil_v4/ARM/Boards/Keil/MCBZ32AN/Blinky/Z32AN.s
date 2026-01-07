;/*****************************************************************************/
;/* Z32AN.s: Startup file for Zilog Z32AN device series                       */
;/*****************************************************************************/
;/* <<< Use Configuration Wizard in Context Menu >>>                          */ 
;/*****************************************************************************/
;/* This file is part of the uVision/ARM development tools.                   */
;/* Copyright (c) 2005-2009 Keil Software. All rights reserved.               */
;/* This software may only be used under the terms of a valid, current,       */
;/* end user licence from KEIL for a compatible version of KEIL software      */
;/* development tools. Nothing else gives you the right to use this software. */
;/*****************************************************************************/


; The Startup code is executed after CPU Reset. This file may be 
; translated with the following SET symbols. In uVision these SET 
; symbols are entered under Options - ASM - Define.
; 
;  NO_PMU_INIT:   when set the Power Management Unit and system clock 
;                 are not initialized in startup and it is used when PLL is 
;                 initialized from debugger enviroment (using the debug script).
;
;  NO_EBI_INIT:   when set the External Bus Interface is not initialized in 
;                 startup and it is used when EBI is initialized from debugger 
;                 enviroment (using the debug script).
;
;  NO_MEMC_INIT:  when set the External Memory Controller is not initialized in 
;                 startup and it is used when MEMC is initialized from debugger 
;                 enviroment (using the debug script).
;
;  NO_SDR_INIT:   when set the SDRAM Controller is not initialized in startup
;                 and it is used when SDRAM Controller is initialized from 
;                 debugger enviroment (using the debug script).
;
;  REMAP:         when set the startup code remaps exception vectors from
;                 on-chip RAM to address 0.
;
;  VEC_TO_RAM:    when set the startup code copies exception vectors 
;                 from Image Load Address to on-chip RAM.
;


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
IRAM_BASE       EQU     0x00000000      ; Remapped RAM address

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
USR_Stack_Size  EQU     0x00000400

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


;----------------------- Power Management Unit (PMU) Definitions ---------------

PMU_BASE        EQU     0xFFFFE000      ; PMU                     Base Address
PMU_PLL_OFS     EQU     0x00            ; PLL Register            Address Offset
PMU_CLK_OFS     EQU     0x04            ; Clock Control Register  Address Offset
PMU_CKEN_OFS    EQU     0x08            ; Clock Enable Register   Address Offset
PMU_RST_OFS     EQU     0x0C            ; Reset Register          Address Offset
PMU_ID0_OFS     EQU     0x10            ; ID 0 Register           Address Offset
PMU_ID1_OFS     EQU     0x14            ; ID 1 Register           Address Offset
PMU_TRIM_OFS    EQU     0x18            ; Trim Register           Address Offset
PMU_CFG_OFS     EQU     0x1C            ; Configuration Register  Address Offset
PMU_OVCK_OFS    EQU     0x30            ; Over-Clock Regsiter     Address Offset

; Bit constants
PMU_PLL_EN      EQU     (1<<0)          ; PLL Power Enable
PMU_PLL_LOCK    EQU     (1<<1)          ; PLL Lock

; <e> Power Management Unit (PMU)
;   <h> PMU PLL Register (PMU_PLL_REG)
;     <i> Fout = (Fin/N)*(M/P)
;     <o1.0>      PLL EN: PLL Power Enable
;     <o1.16..23> PLL MUT M: PLL Multiplier "M" <2-256><#-1>
;                 <i> Multiplied frequency must be greater than 225MHz and below 500MHz.
;     <o1.24..27> PLL IN DIV N: PLL Input Divider "N" <1-16><#-1>
;                 <i> Divided frequency must be greater than 12MHz.
;     <o1.28..31> PLL OUT DIV P: PLL Output Divider "P" <1-16><#-1>
;                 <i> Divider for pll_clk
;   </h>
;
;   <h> PMU Clock Control Register (PMU_CLK_REG)
;     <i> Fout = (Fin/N)*(M/P)
;     <o2.0..4>   FCLK DIVIDER: fclk Divider <1-32><#-1>
;                 <i> fclk = source clock / divider
;     <o2.8..15>  HCLK DIVIDER: hclk Divider <1-256><#-1>
;                 <i> hclk = fclk / divider
;     <o2.16>     SD CLK EN: SDRAM Clock Enable
;     <o2.24>     USB CLK EN: USB Clock Enable
;     <o2.30>     SRC CLK SEL: Source Clock Select
;                 <0=> Crystal clock
;                 <1=> PLL clock
;     <o2.31>     XTAL DIS: Crystal Disable
;   </h>
;
;   <h> PMU Clock Enable Register (PMU_CKEN_REG)
;     <o3.0>      UART0 CKEN: UART0 Clock Enable
;     <o3.1>      UART1 CKEN: UART1 Clock Enable
;     <o3.2>      UART2 CKEN: UART2 Clock Enable
;     <o3.3>      TMR0 CKEN: Timer0 Clock Enable
;     <o3.4>      TMR1 CKEN: Timer1 Clock Enable
;     <o3.5>      TMR2 CKEN: Timer2 Clock Enable
;     <o3.6>      TMR3 CKEN: Timer3 Clock Enable
;     <o3.7>      TMR4 CKEN: Timer4 Clock Enable
;     <o3.8>      TMR5 CKEN: Timer5 Clock Enable
;     <o3.9>      TMR6 CKEN: Timer6 Clock Enable
;     <o3.10>     TMR7 CKEN: Timer7 Clock Enable
;     <o3.11>     TMR8 CKEN: Timer8 Clock Enable
;     <o3.12>     WDOG CKEN: Watchdog Clock Enable
;     <o3.13>     LCD CKEN: LCD Clock Enable
;     <o3.14>     SPI0 CKEN: SPI0 Clock Enable
;     <o3.15>     SPI1 CKEN: SPI1 Clock Enable
;     <o3.16>     SMC CKEN: SmartCard Clock Enable
;     <o3.18>     ADC CKEN: ADC Clock Enable
;     <o3.19>     MCR CKEN: MCR Clock Enable
;     <o3.20>     DMA CKEN: DMA Clock Enable
;     <o3.21>     GPIO0 CKEN: GPIO0 Clock Enable
;     <o3.22>     GPIO1 CKEN: GPIO1 Clock Enable
;     <o3.23>     GPIO2 CKEN: GPIO2 Clock Enable
;     <o3.24>     SHA-1 CKEN: SHA-1 Clock Enable
;     <o3.25>     RNG CKEN: Random Number Cenerator Clock Enable
;     <o3.26>     INTC CKEN: Interrupt Controller Clock Enable
;     <o3.27>     BRDG CKEN: Bridge Clock Enable
;     <o3.28>     SRAM ROM CKEN: SRAM/ROM Clock Enable
;     <o3.29>     MEMC CKEN: External Memory Controller and SDRAM Controller Clock Enable
;     <o3.30>     USB CKEN: USB Clock Enable
;     <o3.31>     CPU CKEN: CPU Clock Enable
;   </h>
; </e>
PMU_SETUP       EQU     1               ; Reset values
PMU_PLL_Val     EQU     0x300F0001      ; 0x22020000
PMU_CLK_Val     EQU     0x40010000      ; 0x00400000
PMU_CKEN_Val    EQU     0xFFFFFFFF      ; 0xFFFFFFFF


;----------------------- External Bus Interface --------------------------------

; External Bus Interface
EBI_BASE        EQU     0xFFFF8000      ; External Mem Controller Base Address

; |- External Memory Controller (MEMC)
MEMC_GCFG_OFS   EQU     0x10            ; Global Configuration    Address Offset
MEMC_CFG_0_OFS  EQU     0x14            ; nCS[0] Configuration    Address Offset
MEMC_CFG_1_OFS  EQU     0x18            ; nCS[1] Configuration    Address Offset
MEMC_CFG_2_OFS  EQU     0x1C            ; nCS[2] Configuration    Address Offset
MEMC_CFG_3_OFS  EQU     0x20            ; nCS[3] Configuration    Address Offset
MEMC_CFG_4_OFS  EQU     0x24            ; nCS[4] Configuration    Address Offset
MEMC_CFG_5_OFS  EQU     0x28            ; nCS[5] Configuration    Address Offset
MEMC_CFG_6_OFS  EQU     0x2C            ; nCS[6] Configuration    Address Offset
MEMC_CFG_7_OFS  EQU     0x30            ; nCS[7] Configuration    Address Offset
MEMC_CFG_8_OFS  EQU     0x34            ; nCS[8] Configuration    Address Offset
MEMC_CFG_9_OFS  EQU     0x38            ; nCS[9] Configuration    Address Offset
MEMC_TIM_0_OFS  EQU     0x3C            ; nCS[0] Timing Register  Address Offset
MEMC_TIM_1_OFS  EQU     0x40            ; nCS[1] Timing Register  Address Offset
MEMC_TIM_2_OFS  EQU     0x44            ; nCS[2] Timing Register  Address Offset
MEMC_TIM_3_OFS  EQU     0x48            ; nCS[3] Timing Register  Address Offset
MEMC_TIM_4_OFS  EQU     0x4C            ; nCS[4] Timing Register  Address Offset
MEMC_TIM_5_OFS  EQU     0x50            ; nCS[5] Timing Register  Address Offset
MEMC_TIM_6_OFS  EQU     0x54            ; nCS[6] Timing Register  Address Offset
MEMC_TIM_7_OFS  EQU     0x58            ; nCS[7] Timing Register  Address Offset
MEMC_TIM_8_OFS  EQU     0x5C            ; nCS[8] Timing Register  Address Offset
MEMC_TIM_9_OFS  EQU     0x60            ; nCS[9] Timing Register  Address Offset
MEMC_STA_OFS    EQU     0x64            ; Status Register         Address Offset

; |- SDRAM Controller
SDR_CFG_OFS     EQU     0x00            ; SDRAM Configuration Reg Address Offset
SDR_CMD_OFS     EQU     0x04            ; SDRAM Command Register  Address Offset
SDR_RFSH_OFS    EQU     0x08            ; SDRAM Refresh Register  Address Offset
SDR_APD_OFS     EQU     0x0C            ; SDRAM Automatic Pow-Dn  Address Offset

; Constants
EBI_CS0_ADDR    EQU     0x10000000      ; Start of memory addressed by nCS0
EBI_CS1_ADDR    EQU     0x11000000      ; Start of memory addressed by nCS1
EBI_CS2_ADDR    EQU     0x12000000      ; Start of memory addressed by nCS2
EBI_CS3_ADDR    EQU     0x13000000      ; Start of memory addressed by nCS3
EBI_CS4_ADDR    EQU     0x14000000      ; Start of memory addressed by nCS4
EBI_CS5_ADDR    EQU     0x15000000      ; Start of memory addressed by nCS5
EBI_CS6_ADDR    EQU     0x16000000      ; Start of memory addressed by nCS6
EBI_CS7_ADDR    EQU     0x17000000      ; Start of memory addressed by nCS7
EBI_CS8_ADDR    EQU     0x18000000      ; Start of memory addressed by nCS8
EBI_CS9_ADDR    EQU     0x19000000      ; Start of memory addressed by nCS9
EBI_SDR0_ADDR   EQU     0x40000000      ; Start of memory addressed by SDRAM0
EBI_SDR1_ADDR   EQU     0x20000000      ; Start of memory addressed by SDRAM1

SDR_EN1_STAT    EQU     (1<<26)         ; SDRAM primary enable status
SDR_EN2_STAT    EQU     (1<<10)         ; SDRAM secondary enable status
SDR_EN1         EQU     (1<<25)         ; SDRAM primary enable
SDR_EN2         EQU     (1<< 9)         ; SDRAM secondary enable

SDR_CMD_NRM     EQU     (0x00)          ; Command: Normal Operation
SDR_CMD_NOP     EQU     (0x01)          ; Command: NOP
SDR_CMD_PRG     EQU     (0x02)          ; Command: PRECHARGE-ALL
SDR_CMD_LMR     EQU     (0x03)          ; Command: LOAD MODE REGISTER
SDR_CMD_SRF     EQU     (0x04)          ; Command: SELF REFRESH
SDR_CMD_PDN     EQU     (0x05)          ; Command: POWER DOWN
SDR_CMD_ARF     EQU     (0x06)          ; Command: AUTO REFRESH
SDR_CMD_ZER     EQU     (0x07)          ; Command: SDRAM Zeroization

; <e> External Bus Interface (EBI)
EBI_SETUP       EQU     1

;   <e> External Memory Controller (MEMC)
MEMC_SETUP      EQU     1

;     <h> MEMC Global Config Register (MEMC_GCFG_REG)
;       <o0.2..3>   FLCLK DIV: FLCLK Divider
;                   <0=> divide hclk by 2
;                   <1=> divide hclk by 4
;                   <2=> divide hclk by 6
;                   <3=> divide hclk by 8
;       <o0.4>      BUS ZERO: Bus Zero Mode
;                   <i> If "1" MD[15] and SD[15] are driven to "0" when SDRAM and 
;                   <i> Memory Controller state mchines are idle, if "0" then 
;                   <i> MD[15] and SD[15] are left floating.
;       <o0.16..27> READY TIMEOUT: Ready Timeout on AHB Bus Error (in hclk cycles) <0-4095>
;     </h>
MEMC_GCFG_Val   EQU     0x00FF000D      ; Reset value: 0x0FFF0000

;     <e> Configure nCS0
;       <h> MEMC nCS[0] Config Register (MEMC_CFG_0_REG)
;       <o1.0>      WDTH: Data Bus Width
;                   <0=> 8 bits
;                   <1=> 16 bits
;       <o1.1>      BYTE STYLE: Byte Control Style
;                   <0=> 8-bit: nWEU = high, nWEL = nWE, A[0] = A0 | 16-bit: nWEU = nWEU, nWEL = nWEL, A[0] = low
;                   <1=> 8-bit: nWEU = nBE , nWEL = nWE, A[0] = A0 | 16-bit: nWEU = nBEU, nWEL = nWE , A[0] = nBEL
;       <o1.2>      RDY EN: READY Pin Enable
;       <o1.3>      RDY POL: READY Pin Polarity
;                   <0=> READY pin active low
;                   <1=> READY pin active high
;       <o1.4>      FLCLK BTEN: FLCLK Based Timing Enable
;       <o1.5>      PAGE EN: Page Mode Enable
;       <o1.8..10>  PAGE BDRY: Page Boundary
;                   <i> Specifies the boundary limit for sync or async burst reads.
;                   <i> This is defined in terms of the least significant AHB address 
;                   <i> bit which must remain constant for the burst to continue.
;                   <0=> A[2]
;                   <1=> A[3]
;                   <2=> A[4]
;                   <3=> A[5]
;                   <4=> A[6]
;                   <5=> A[7]
;       </h>
;       <h> MEMC Timing Register for nCS[0] (MEMC_TIM_0_REG)
;         <i> All timings are based on hclk period when FLCLKBTEN = 0, and on fclk when FCLKBTEN = 1
;       <o2.0..3>   NRS: Read Cycle Setup Time <0-15>
;       <o2.4..7>   NRA: Read Access Time <0-15>
;       <o2.8..10>  NRH: Read Cycle Hold Time <0-7>
;       <o2.11..14> NRPA: Read Access Time of Sequential Access of a Page Burst Read <0-15>
;       <o2.16..19> NWS: Write Cycle Setup Time <0-15>
;       <o2.20..23> NWA: Write Access Time <0-15>
;       <o2.24..26> NWH: Write Cycle Hold Time <0-7>
;       <o2.27..29> NRWI: Minimum Time After a Read Before a Subsequent Write Cycle <0-7>
;       </h>
;     </e>
MEMC_SETUP_0    EQU     1
MEMC_CFG_0_Val  EQU     0x00000003      ; Reset value: 0x00000001
MEMC_TIM_0_Val  EQU     0x3FFF3FFF      ; Reset value: 0x3FFF3FFF

;     <e> Configure nCS1
;       <h> MEMC nCS[1] Config Register (MEMC_CFG_1_REG)
;       <o1.0>      WDTH: Data Bus Width
;                   <0=> 8 bits
;                   <1=> 16 bits
;       <o1.1>      BYTE STYLE: Byte Control Style
;                   <0=> 8-bit: nWEU = high, nWEL = nWE, A[0] = A0 | 16-bit: nWEU = nWEU, nWEL = nWEL, A[0] = low
;                   <1=> 8-bit: nWEU = nBE , nWEL = nWE, A[0] = A0 | 16-bit: nWEU = nBEU, nWEL = nWE , A[0] = nBEL
;       <o1.2>      RDY EN: READY Pin Enable
;       <o1.3>      RDY POL: READY Pin Polarity
;                   <0=> READY pin active low
;                   <1=> READY pin active high
;       <o1.4>      FLCLK BTEN: FLCLK Based Timing Enable
;       <o1.5>      PAGE EN: Page Mode Enable
;       <o1.7>      EXT: Extend
;                   <0=> CS1 used normally
;                   <1=> CS1 becomes MA[24] and CS0 address space is 32MB
;       <o1.8..10>  PAGE BDRY: Page Boundary
;                   <i> Specifies the boundary limit for sync or async burst reads.
;                   <i> This is defined in terms of the least significant AHB address 
;                   <i> bit which must remain constant for the burst to continue.
;                   <0=> A[2]
;                   <1=> A[3]
;                   <2=> A[4]
;                   <3=> A[5]
;                   <4=> A[6]
;                   <5=> A[7]
;       </h>
;       <h> MEMC Timing Register for nCS[1] (MEMC_TIM_1_REG)
;         <i> All timings are based on hclk period when FLCLKBTEN = 0, and on fclk when FCLKBTEN = 1
;       <o2.0..3>   NRS: Read Cycle Setup Time <0-15>
;       <o2.4..7>   NRA: Read Access Time <0-15>
;       <o2.8..10>  NRH: Read Cycle Hold Time <0-7>
;       <o2.11..14> NRPA: Read Access Time of Sequential Access of a Page Burst Read <0-15>
;       <o2.16..19> NWS: Write Cycle Setup Time <0-15>
;       <o2.20..23> NWA: Write Access Time <0-15>
;       <o2.24..26> NWH: Write Cycle Hold Time <0-7>
;       <o2.27..29> NRWI: Minimum Time After a Read Before a Subsequent Write Cycle <0-7>
;       </h>
;     </e>
MEMC_SETUP_1    EQU     0
MEMC_CFG_1_Val  EQU     0x00000001      ; Reset value: 0x00000001
MEMC_TIM_1_Val  EQU     0x3FFF3FFF      ; Reset value: 0x3FFF3FFF

;     <e> Configure nCS2
;       <h> MEMC nCS[2] Config Register (MEMC_CFG_2_REG)
;       <o1.0>      WDTH: Data Bus Width
;                   <0=> 8 bits
;                   <1=> 16 bits
;       <o1.1>      BYTE STYLE: Byte Control Style
;                   <0=> 8-bit: nWEU = high, nWEL = nWE, A[0] = A0 | 16-bit: nWEU = nWEU, nWEL = nWEL, A[0] = low
;                   <1=> 8-bit: nWEU = nBE , nWEL = nWE, A[0] = A0 | 16-bit: nWEU = nBEU, nWEL = nWE , A[0] = nBEL
;       <o1.2>      RDY EN: READY Pin Enable
;       <o1.3>      RDY POL: READY Pin Polarity
;                   <0=> READY pin active low
;                   <1=> READY pin active high
;       <o1.4>      FLCLK BTEN: FLCLK Based Timing Enable
;       <o1.5>      PAGE EN: Page Mode Enable
;       <o1.8..10>  PAGE BDRY: Page Boundary
;                   <i> Specifies the boundary limit for sync or async burst reads.
;                   <i> This is defined in terms of the least significant AHB address 
;                   <i> bit which must remain constant for the burst to continue.
;                   <0=> A[2]
;                   <1=> A[3]
;                   <2=> A[4]
;                   <3=> A[5]
;                   <4=> A[6]
;                   <5=> A[7]
;       </h>
;       <h> MEMC Timing Register for nCS[2] (MEMC_TIM_2_REG)
;         <i> All timings are based on hclk period when FLCLKBTEN = 0, and on fclk when FCLKBTEN = 1
;       <o2.0..3>   NRS: Read Cycle Setup Time <0-15>
;       <o2.4..7>   NRA: Read Access Time <0-15>
;       <o2.8..10>  NRH: Read Cycle Hold Time <0-7>
;       <o2.11..14> NRPA: Read Access Time of Sequential Access of a Page Burst Read <0-15>
;       <o2.16..19> NWS: Write Cycle Setup Time <0-15>
;       <o2.20..23> NWA: Write Access Time <0-15>
;       <o2.24..26> NWH: Write Cycle Hold Time <0-7>
;       <o2.27..29> NRWI: Minimum Time After a Read Before a Subsequent Write Cycle <0-7>
;       </h>
;     </e>
MEMC_SETUP_2    EQU     0
MEMC_CFG_2_Val  EQU     0x00000001      ; Reset value: 0x00000001
MEMC_TIM_2_Val  EQU     0x3FFF3FFF      ; Reset value: 0x3FFF3FFF

;     <e> Configure nCS3
;       <h> MEMC nCS[0] Config Register (MEMC_CFG_3_REG)
;       <o1.0>      WDTH: Data Bus Width
;                   <0=> 8 bits
;                   <1=> 16 bits
;       <o1.1>      BYTE STYLE: Byte Control Style
;                   <0=> 8-bit: nWEU = high, nWEL = nWE, A[0] = A0 | 16-bit: nWEU = nWEU, nWEL = nWEL, A[0] = low
;                   <1=> 8-bit: nWEU = nBE , nWEL = nWE, A[0] = A0 | 16-bit: nWEU = nBEU, nWEL = nWE , A[0] = nBEL
;       <o1.2>      RDY EN: READY Pin Enable
;       <o1.3>      RDY POL: READY Pin Polarity
;                   <0=> READY pin active low
;                   <1=> READY pin active high
;       <o1.4>      FLCLK BTEN: FLCLK Based Timing Enable
;       <o1.5>      PAGE EN: Page Mode Enable
;       <o1.7>      EXT: Extend
;                   <0=> CS3 used normally
;                   <1=> CS3 becomes MA[24] and CS0 address space is 32MB
;       <o1.8..10>  PAGE BDRY: Page Boundary
;                   <i> Specifies the boundary limit for sync or async burst reads.
;                   <i> This is defined in terms of the least significant AHB address 
;                   <i> bit which must remain constant for the burst to continue.
;                   <0=> A[2]
;                   <1=> A[3]
;                   <2=> A[4]
;                   <3=> A[5]
;                   <4=> A[6]
;                   <5=> A[7]
;       </h>
;       <h> MEMC Timing Register for nCS[3] (MEMC_TIM_3_REG)
;         <i> All timings are based on hclk period when FLCLKBTEN = 0, and on fclk when FCLKBTEN = 1
;       <o2.0..3>   NRS: Read Cycle Setup Time <0-15>
;       <o2.4..7>   NRA: Read Access Time <0-15>
;       <o2.8..10>  NRH: Read Cycle Hold Time <0-7>
;       <o2.11..14> NRPA: Read Access Time of Sequential Access of a Page Burst Read <0-15>
;       <o2.16..19> NWS: Write Cycle Setup Time <0-15>
;       <o2.20..23> NWA: Write Access Time <0-15>
;       <o2.24..26> NWH: Write Cycle Hold Time <0-7>
;       <o2.27..29> NRWI: Minimum Time After a Read Before a Subsequent Write Cycle <0-7>
;       </h>
;     </e>
MEMC_SETUP_3    EQU     0
MEMC_CFG_3_Val  EQU     0x00000001      ; Reset value: 0x00000001
MEMC_TIM_3_Val  EQU     0x3FFF3FFF      ; Reset value: 0x3FFF3FFF

;     <e> Configure nCS4
;       <h> MEMC nCS[4] Config Register (MEMC_CFG_4_REG)
;       <o1.0>      WDTH: Data Bus Width
;                   <0=> 8 bits
;                   <1=> 16 bits
;       <o1.1>      BYTE STYLE: Byte Control Style
;                   <0=> 8-bit: nWEU = high, nWEL = nWE, A[0] = A0 | 16-bit: nWEU = nWEU, nWEL = nWEL, A[0] = low
;                   <1=> 8-bit: nWEU = nBE , nWEL = nWE, A[0] = A0 | 16-bit: nWEU = nBEU, nWEL = nWE , A[0] = nBEL
;       <o1.2>      RDY EN: READY Pin Enable
;       <o1.3>      RDY POL: READY Pin Polarity
;                   <0=> READY pin active low
;                   <1=> READY pin active high
;       <o1.4>      FLCLK BTEN: FLCLK Based Timing Enable
;       <o1.5>      PAGE EN: Page Mode Enable
;       <o1.8..10>  PAGE BDRY: Page Boundary
;                   <i> Specifies the boundary limit for sync or async burst reads.
;                   <i> This is defined in terms of the least significant AHB address 
;                   <i> bit which must remain constant for the burst to continue.
;                   <0=> A[2]
;                   <1=> A[3]
;                   <2=> A[4]
;                   <3=> A[5]
;                   <4=> A[6]
;                   <5=> A[7]
;       </h>
;       <h> MEMC Timing Register for nCS[4] (MEMC_TIM_4_REG)
;         <i> All timings are based on hclk period when FLCLKBTEN = 0, and on fclk when FCLKBTEN = 1
;       <o2.0..3>   NRS: Read Cycle Setup Time <0-15>
;       <o2.4..7>   NRA: Read Access Time <0-15>
;       <o2.8..10>  NRH: Read Cycle Hold Time <0-7>
;       <o2.11..14> NRPA: Read Access Time of Sequential Access of a Page Burst Read <0-15>
;       <o2.16..19> NWS: Write Cycle Setup Time <0-15>
;       <o2.20..23> NWA: Write Access Time <0-15>
;       <o2.24..26> NWH: Write Cycle Hold Time <0-7>
;       <o2.27..29> NRWI: Minimum Time After a Read Before a Subsequent Write Cycle <0-7>
;       </h>
;     </e>
MEMC_SETUP_4    EQU     0
MEMC_CFG_4_Val  EQU     0x00000001      ; Reset value: 0x00000001
MEMC_TIM_4_Val  EQU     0x3FFF3FFF      ; Reset value: 0x3FFF3FFF

;     <e> Configure nCS5
;       <h> MEMC nCS[5] Config Register (MEMC_CFG_5_REG)
;       <o1.0>      WDTH: Data Bus Width
;                   <0=> 8 bits
;                   <1=> 16 bits
;       <o1.1>      BYTE STYLE: Byte Control Style
;                   <0=> 8-bit: nWEU = high, nWEL = nWE, A[0] = A0 | 16-bit: nWEU = nWEU, nWEL = nWEL, A[0] = low
;                   <1=> 8-bit: nWEU = nBE , nWEL = nWE, A[0] = A0 | 16-bit: nWEU = nBEU, nWEL = nWE , A[0] = nBEL
;       <o1.2>      RDY EN: READY Pin Enable
;       <o1.3>      RDY POL: READY Pin Polarity
;                   <0=> READY pin active low
;                   <1=> READY pin active high
;       <o1.4>      FLCLK BTEN: FLCLK Based Timing Enable
;       <o1.5>      PAGE EN: Page Mode Enable
;       <o1.8..10>  PAGE BDRY: Page Boundary
;                   <i> Specifies the boundary limit for sync or async burst reads.
;                   <i> This is defined in terms of the least significant AHB address 
;                   <i> bit which must remain constant for the burst to continue.
;                   <0=> A[2]
;                   <1=> A[3]
;                   <2=> A[4]
;                   <3=> A[5]
;                   <4=> A[6]
;                   <5=> A[7]
;       </h>
;       <h> MEMC Timing Register for nCS[5] (MEMC_TIM_5_REG)
;         <i> All timings are based on hclk period when FLCLKBTEN = 0, and on fclk when FCLKBTEN = 1
;       <o2.0..3>   NRS: Read Cycle Setup Time <0-15>
;       <o2.4..7>   NRA: Read Access Time <0-15>
;       <o2.8..10>  NRH: Read Cycle Hold Time <0-7>
;       <o2.11..14> NRPA: Read Access Time of Sequential Access of a Page Burst Read <0-15>
;       <o2.16..19> NWS: Write Cycle Setup Time <0-15>
;       <o2.20..23> NWA: Write Access Time <0-15>
;       <o2.24..26> NWH: Write Cycle Hold Time <0-7>
;       <o2.27..29> NRWI: Minimum Time After a Read Before a Subsequent Write Cycle <0-7>
;       </h>
;     </e>
MEMC_SETUP_5    EQU     0
MEMC_CFG_5_Val  EQU     0x00000001      ; Reset value: 0x00000001
MEMC_TIM_5_Val  EQU     0x3FFF3FFF      ; Reset value: 0x3FFF3FFF

;     <e> Configure nCS6
;       <h> MEMC nCS[6] Config Register (MEMC_CFG_6_REG)
;       <o1.0>      WDTH: Data Bus Width
;                   <0=> 8 bits
;                   <1=> 16 bits
;       <o1.1>      BYTE STYLE: Byte Control Style
;                   <0=> 8-bit: nWEU = high, nWEL = nWE, A[0] = A0 | 16-bit: nWEU = nWEU, nWEL = nWEL, A[0] = low
;                   <1=> 8-bit: nWEU = nBE , nWEL = nWE, A[0] = A0 | 16-bit: nWEU = nBEU, nWEL = nWE , A[0] = nBEL
;       <o1.2>      RDY EN: READY Pin Enable
;       <o1.3>      RDY POL: READY Pin Polarity
;                   <0=> READY pin active low
;                   <1=> READY pin active high
;       <o1.4>      FLCLK BTEN: FLCLK Based Timing Enable
;       <o1.5>      PAGE EN: Page Mode Enable
;       <o1.8..10>  PAGE BDRY: Page Boundary
;                   <i> Specifies the boundary limit for sync or async burst reads.
;                   <i> This is defined in terms of the least significant AHB address 
;                   <i> bit which must remain constant for the burst to continue.
;                   <0=> A[2]
;                   <1=> A[3]
;                   <2=> A[4]
;                   <3=> A[5]
;                   <4=> A[6]
;                   <5=> A[7]
;       </h>
;       <h> MEMC Timing Register for nCS[6] (MEMC_TIM_6_REG)
;         <i> All timings are based on hclk period when FLCLKBTEN = 0, and on fclk when FCLKBTEN = 1
;       <o2.0..3>   NRS: Read Cycle Setup Time <0-15>
;       <o2.4..7>   NRA: Read Access Time <0-15>
;       <o2.8..10>  NRH: Read Cycle Hold Time <0-7>
;       <o2.11..14> NRPA: Read Access Time of Sequential Access of a Page Burst Read <0-15>
;       <o2.16..19> NWS: Write Cycle Setup Time <0-15>
;       <o2.20..23> NWA: Write Access Time <0-15>
;       <o2.24..26> NWH: Write Cycle Hold Time <0-7>
;       <o2.27..29> NRWI: Minimum Time After a Read Before a Subsequent Write Cycle <0-7>
;       </h>
;     </e>
MEMC_SETUP_6    EQU     0
MEMC_CFG_6_Val  EQU     0x00000001      ; Reset value: 0x00000001
MEMC_TIM_6_Val  EQU     0x3FFF3FFF      ; Reset value: 0x3FFF3FFF

;     <e> Configure nCS7
;       <h> MEMC nCS[7] Config Register (MEMC_CFG_7_REG)
;       <o1.0>      WDTH: Data Bus Width
;                   <0=> 8 bits
;                   <1=> 16 bits
;       <o1.1>      BYTE STYLE: Byte Control Style
;                   <0=> 8-bit: nWEU = high, nWEL = nWE, A[0] = A0 | 16-bit: nWEU = nWEU, nWEL = nWEL, A[0] = low
;                   <1=> 8-bit: nWEU = nBE , nWEL = nWE, A[0] = A0 | 16-bit: nWEU = nBEU, nWEL = nWE , A[0] = nBEL
;       <o1.2>      RDY EN: READY Pin Enable
;       <o1.3>      RDY POL: READY Pin Polarity
;                   <0=> READY pin active low
;                   <1=> READY pin active high
;       <o1.4>      FLCLK BTEN: FLCLK Based Timing Enable
;       <o1.5>      PAGE EN: Page Mode Enable
;       <o1.8..10>  PAGE BDRY: Page Boundary
;                   <i> Specifies the boundary limit for sync or async burst reads.
;                   <i> This is defined in terms of the least significant AHB address 
;                   <i> bit which must remain constant for the burst to continue.
;                   <0=> A[2]
;                   <1=> A[3]
;                   <2=> A[4]
;                   <3=> A[5]
;                   <4=> A[6]
;                   <5=> A[7]
;       </h>
;       <h> MEMC Timing Register for nCS[7] (MEMC_TIM_7_REG)
;         <i> All timings are based on hclk period when FLCLKBTEN = 0, and on fclk when FCLKBTEN = 1
;       <o2.0..3>   NRS: Read Cycle Setup Time <0-15>
;       <o2.4..7>   NRA: Read Access Time <0-15>
;       <o2.8..10>  NRH: Read Cycle Hold Time <0-7>
;       <o2.11..14> NRPA: Read Access Time of Sequential Access of a Page Burst Read <0-15>
;       <o2.16..19> NWS: Write Cycle Setup Time <0-15>
;       <o2.20..23> NWA: Write Access Time <0-15>
;       <o2.24..26> NWH: Write Cycle Hold Time <0-7>
;       <o2.27..29> NRWI: Minimum Time After a Read Before a Subsequent Write Cycle <0-7>
;       </h>
;     </e>
MEMC_SETUP_7    EQU     0
MEMC_CFG_7_Val  EQU     0x00000001      ; Reset value: 0x00000001
MEMC_TIM_7_Val  EQU     0x3FFF3FFF      ; Reset value: 0x3FFF3FFF

;     <e> Configure nCS8
;       <h> MEMC nCS[8] Config Register (MEMC_CFG_8_REG)
;       <o1.0>      WDTH: Data Bus Width
;                   <0=> 8 bits
;                   <1=> 16 bits
;       <o1.1>      BYTE STYLE: Byte Control Style
;                   <0=> 8-bit: nWEU = high, nWEL = nWE, A[0] = A0 | 16-bit: nWEU = nWEU, nWEL = nWEL, A[0] = low
;                   <1=> 8-bit: nWEU = nBE , nWEL = nWE, A[0] = A0 | 16-bit: nWEU = nBEU, nWEL = nWE , A[0] = nBEL
;       <o1.2>      RDY EN: READY Pin Enable
;       <o1.3>      RDY POL: READY Pin Polarity
;                   <0=> READY pin active low
;                   <1=> READY pin active high
;       <o1.4>      FLCLK BTEN: FLCLK Based Timing Enable
;       <o1.5>      PAGE EN: Page Mode Enable
;       <o1.8..10>  PAGE BDRY: Page Boundary
;                   <i> Specifies the boundary limit for sync or async burst reads.
;                   <i> This is defined in terms of the least significant AHB address 
;                   <i> bit which must remain constant for the burst to continue.
;                   <0=> A[2]
;                   <1=> A[3]
;                   <2=> A[4]
;                   <3=> A[5]
;                   <4=> A[6]
;                   <5=> A[7]
;       </h>
;       <h> MEMC Timing Register for nCS[8] (MEMC_TIM_8_REG)
;         <i> All timings are based on hclk period when FLCLKBTEN = 0, and on fclk when FCLKBTEN = 1
;       <o2.0..3>   NRS: Read Cycle Setup Time <0-15>
;       <o2.4..7>   NRA: Read Access Time <0-15>
;       <o2.8..10>  NRH: Read Cycle Hold Time <0-7>
;       <o2.11..14> NRPA: Read Access Time of Sequential Access of a Page Burst Read <0-15>
;       <o2.16..19> NWS: Write Cycle Setup Time <0-15>
;       <o2.20..23> NWA: Write Access Time <0-15>
;       <o2.24..26> NWH: Write Cycle Hold Time <0-7>
;       <o2.27..29> NRWI: Minimum Time After a Read Before a Subsequent Write Cycle <0-7>
;       </h>
;     </e>
MEMC_SETUP_8    EQU     0
MEMC_CFG_8_Val  EQU     0x00000001      ; Reset value: 0x00000001
MEMC_TIM_8_Val  EQU     0x3FFF3FFF      ; Reset value: 0x3FFF3FFF

;     <e> Configure nCS9
;       <h> MEMC nCS[9] Config Register (MEMC_CFG_9_REG)
;       <o1.0>      WDTH: Data Bus Width
;                   <0=> 8 bits
;                   <1=> 16 bits
;       <o1.1>      BYTE STYLE: Byte Control Style
;                   <0=> 8-bit: nWEU = high, nWEL = nWE, A[0] = A0 | 16-bit: nWEU = nWEU, nWEL = nWEL, A[0] = low
;                   <1=> 8-bit: nWEU = nBE , nWEL = nWE, A[0] = A0 | 16-bit: nWEU = nBEU, nWEL = nWE , A[0] = nBEL
;       <o1.2>      RDY EN: READY Pin Enable
;       <o1.3>      RDY POL: READY Pin Polarity
;                   <0=> READY pin active low
;                   <1=> READY pin active high
;       <o1.4>      FLCLK BTEN: FLCLK Based Timing Enable
;       <o1.5>      PAGE EN: Page Mode Enable
;       <o1.8..10>  PAGE BDRY: Page Boundary
;                   <i> Specifies the boundary limit for sync or async burst reads.
;                   <i> This is defined in terms of the least significant AHB address 
;                   <i> bit which must remain constant for the burst to continue.
;                   <0=> A[2]
;                   <1=> A[3]
;                   <2=> A[4]
;                   <3=> A[5]
;                   <4=> A[6]
;                   <5=> A[7]
;       </h>
;       <h> MEMC Timing Register for nCS[9] (MEMC_TIM_9_REG)
;         <i> All timings are based on hclk period when FLCLKBTEN = 0, and on fclk when FCLKBTEN = 1
;       <o2.0..3>   NRS: Read Cycle Setup Time <0-15>
;       <o2.4..7>   NRA: Read Access Time <0-15>
;       <o2.8..10>  NRH: Read Cycle Hold Time <0-7>
;       <o2.11..14> NRPA: Read Access Time of Sequential Access of a Page Burst Read <0-15>
;       <o2.16..19> NWS: Write Cycle Setup Time <0-15>
;       <o2.20..23> NWA: Write Access Time <0-15>
;       <o2.24..26> NWH: Write Cycle Hold Time <0-7>
;       <o2.27..29> NRWI: Minimum Time After a Read Before a Subsequent Write Cycle <0-7>
;       </h>
;     </e>
MEMC_SETUP_9    EQU     0
MEMC_CFG_9_Val  EQU     0x00000001      ; Reset value: 0x00000001
MEMC_TIM_9_Val  EQU     0x3FFF3FFF      ; Reset value: 0x3FFF3FFF

;   </e>
;   <e> SDRAM Controllers
SDR_SETUP       EQU     1

;     <h> SDRAM Configuration  Register (SDR_CFG_REG)
;       <o0.0..3>   TRFC: Autorefresh Period <1-10><#-1>
;       <o0.4..5>   TRCD: Active to Read or Write Command Delay <1-4><#-1>
;       <o0.6..7>   TRP: Precharge to any other Command Delay <1-4><#-1>
;       <o0.16..17> COL WIDTH: Column Width
;                   <0=> 8 bits
;                   <1=> 9 bits
;                   <2=> 10 bits
;                   <3=> 11 bits
;       <o0.20..21> ROW WIDTH: Row Width
;                   <0=> 11 bits
;                   <1=> 12 bits
;                   <2=> 13 bits
;                   <3=> reserved
;       <o0.24>     INTER ADDR: Interleave Address
;                   <0=> Bank address derived from MSBs
;                   <1=> Bank address derived from address bits between the column (LSBs) and the row (MSBs)
;     </h>
;     <h> SDRAM Refresh Register (SDR_RFSH_REG)
;       <o1.0..15>  REFRESH TIMER: Refresh Timer <0-65535>
;     </h>
;   </e>
SDR_CFG_Val     EQU     0x002100F9      ; Reset value: 0x000000F9
SDR_RFSH_Val    EQU     0x0000001F      ; Reset value: 0x00000000

; </e>


;----------------------- Cache Definitions -------------------------------------

; Constants
ICACHE_ENABLE   EQU     (1<<12)         ; Instruction Cache Enable Bit

;// <e> Instruction Cache Enable
;// </e>
ICACHE_SETUP    EQU     1


;----------------------- CODE --------------------------------------------------

; - Protection Keys ------------------------------------------------------------

                PRESERVE8

; Area Definition for External Control Block
                
                IF      :DEF:EXT_CONTROL_BLOCK
                AREA    |.ARM.__AT_0x10000000|, CODE, READONLY
                ARM

                DCD     MEMC_CFG_0_Val
                DCD     MEMC_TIM_0_Val
                DCD     MEMC_GCFG_Val
                DCD     0xD3C2B1A0
                DCD     0x00000000
                DCD     0x00000000
                DCD     0x00000000
                DCD     0x00000000
                DCD     Vectors
                IF      :LNOT::DEF:__EVAL 
                IMPORT  ||Image$$ER_ROM1$$RO$$Length||
                IMPORT  ||Image$$RW_IRAM1$$RW$$Length||
                DCD     ||Image$$ER_ROM1$$RO$$Length||+\
                        ||Image$$RW_IRAM1$$RW$$Length||
                ELSE    
                DCD     0x00010000
                ENDIF

                ENDIF


; - Starup Code ----------------------------------------------------------------

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
                NOP
                LDR     PC,[PC,#0xFFFFFF00-(0x18+8)] ; Vector From INTC_IVEC_REG
                LDR     PC,[PC,#0xFFFFFF04-(0x1C+8)] ; Vector From INTC_FVEC_REG

Reset_Addr      DCD     Reset_Handler
Undef_Addr      DCD     Undef_Handler
SWI_Addr        DCD     SWI_Handler
PAbt_Addr       DCD     PAbt_Handler
DAbt_Addr       DCD     DAbt_Handler
                DCD     0               ; Reserved Address
IRQ_Addr        DCD     IRQ_Handler
FIQ_Addr        DCD     FIQ_Handler

Undef_Handler   B       Undef_Handler
                IF      :LNOT::DEF:__RTX
SWI_Handler     B       SWI_Handler
                ENDIF
PAbt_Handler    B       PAbt_Handler
DAbt_Handler    B       DAbt_Handler
IRQ_Handler     B       IRQ_Handler
FIQ_Handler     B       FIQ_Handler


; Reset Handler

                EXPORT  Reset_Handler
Reset_Handler   


; Setup Power Management Unit (PMU) --------------------------------------------

                IF      (:LNOT::DEF:NO_PMU_INIT):LAND:(PMU_SETUP != 0)
                LDR     R0, =PMU_BASE

                IF      ((PMU_SETUP:AND:0x01) != 0)
                LDR     R1, =PMU_PLL_Val
                STR     R1, [R0, #PMU_PLL_OFS]

                ; Wait until PLL is locked
PLL_Lock        LDR     R2, [R0, #PMU_PLL_OFS]
                ANDS    R2, R2, #PMU_PLL_LOCK
                BEQ     PLL_Lock
				ENDIF   ; IF      ((PMU_SETUP:AND:0x01) != 0)

                LDR     R1, =PMU_CLK_Val
                STR     R1, [R0, #PMU_CLK_OFS]
                LDR     R1, =PMU_CKEN_Val
                STR     R1, [R0, #PMU_CKEN_OFS]
				ENDIF   ; IF      (:LNOT::DEF:NO_PMU_INIT):LAND:(PMU_SETUP != 0)


; Setup External Bus Interface (EBI) -------------------------------------------
; |- Setup External Memory Controller (MEMC) -----------------------------------

                IF      (:LNOT::DEF:NO_EBI_INIT):LAND:(EBI_SETUP != 0)
                LDR     R0, =EBI_BASE

                IF      (:LNOT::DEF:NO_MEMC_INIT):LAND:(MEMC_SETUP != 0)
                LDR     R1, =MEMC_GCFG_Val
                STR     R1, [R0, #MEMC_GCFG_OFS]

                ; Macro for setting the External Memory Controller nCSs
                MACRO
$label          MEMC_Cod $cs

$label          LDR     R1, =MEMC_CFG_$cs._Val
                STR     R1, [R0, #MEMC_CFG_$cs._OFS]
                LDR     R1, =MEMC_TIM_$cs._Val
                STR     R1, [R0, #MEMC_TIM_$cs._OFS]
                MEND

                IF      (MEMC_SETUP_0 != 0)
MEMC_0          MEMC_Cod 0
                ENDIF
                IF      (MEMC_SETUP_0 != 0)
MEMC_1          MEMC_Cod 1
                ENDIF
                IF      (MEMC_SETUP_0 != 0)
MEMC_2          MEMC_Cod 2
                ENDIF
                IF      (MEMC_SETUP_0 != 0)
MEMC_3          MEMC_Cod 3
                ENDIF
                IF      (MEMC_SETUP_0 != 0)
MEMC_4          MEMC_Cod 4
                ENDIF
                IF      (MEMC_SETUP_0 != 0)
MEMC_5          MEMC_Cod 5
                ENDIF
                IF      (MEMC_SETUP_0 != 0)
MEMC_6          MEMC_Cod 6
                ENDIF
                IF      (MEMC_SETUP_0 != 0)
MEMC_7          MEMC_Cod 7
                ENDIF
                IF      (MEMC_SETUP_0 != 0)
MEMC_8          MEMC_Cod 8
                ENDIF
                IF      (MEMC_SETUP_0 != 0)
MEMC_9          MEMC_Cod 9
                ENDIF
                ENDIF   ; IF      (:LNOT::DEF:NO_MEMC_INIT):LAND:(MEMC_SETUP != 0)

; |- Setup SDRAM Memory Controller ---------------------------------------------
                IF      (:LNOT::DEF:NO_SDR_INIT):LAND:(SDR_SETUP != 0)
                LDR     R1, =EBI_SDR1_ADDR
                MOV     R2, #0

                LDR     R4, =SDR_CFG_Val
                STR     R4, [R0, #SDR_CFG_OFS]
                MOV     R4, #SDR_EN2
                STR     R4, [R0, #SDR_CMD_OFS]
                STR     R2, [R0, #SDR_RFSH_OFS]
                STR     R2, [R0, #SDR_APD_OFS]

                LDR     R6, =4800                 ; Number of cycles to delay
Wait_0          SUBS    R6, R6, #1                ; Delay ~200 us proc clk 96 MHz
                BNE     Wait_0                    ; BNE (3 cyc) + SUBS (1 cyc) = 4 cyc

                LDR     R4, =((SDR_EN2|0x10|SDR_CMD_PRG))
                STR     R4, [R0, #SDR_CMD_OFS]

                LDR     R6, =48000                ; Number of cycles to delay
Wait_1          SUBS    R6, R6, #1                ; Delay ~200 us proc clk 96 MHz
                BNE     Wait_1                    ; BNE (3 cyc) + SUBS (1 cyc) = 4 cyc

                LDR     R4, =((SDR_EN2|0x10|SDR_CMD_ARF))
                STR     R4, [R0, #SDR_CMD_OFS]
                STR     R4, [R0, #SDR_CMD_OFS]
                STR     R4, [R0, #SDR_CMD_OFS]
                STR     R4, [R0, #SDR_CMD_OFS]
                STR     R4, [R0, #SDR_CMD_OFS]
                STR     R4, [R0, #SDR_CMD_OFS]
                STR     R4, [R0, #SDR_CMD_OFS]
                STR     R4, [R0, #SDR_CMD_OFS]

                LDR     R6, =48000                ; Number of cycles to delay
Wait_3          SUBS    R6, R6, #1                ; Delay ~200 us proc clk 96 MHz
                BNE     Wait_3                    ; BNE (3 cyc) + SUBS (1 cyc) = 4 cyc

                LDR     R3, =0x0030
                LDR     R4, =((SDR_EN2|0x10|SDR_CMD_LMR))
                STR     R4, [R0, #SDR_CMD_OFS]
                STR     R4, [R1, R3]

                LDR     R6, =48000                ; Number of cycles to delay
Wait_4          SUBS    R6, R6, #1                ; Delay ~200 us proc clk 96 MHz
                BNE     Wait_4                    ; BNE (3 cyc) + SUBS (1 cyc) = 4 cyc

                LDR     R4, =SDR_RFSH_Val
                STR     R4, [R0, #SDR_RFSH_OFS]
                LDR     R4, =((SDR_EN2:OR:SDR_CMD_NRM))
                STR     R4, [R0, #SDR_CMD_OFS]
                ENDIF   ; IF      (:LNOT::DEF:NO_SDR_INIT):LAND:(SDR_SETUP != 0)

                ENDIF   ; IF      (:LNOT::DEF:NO_EBI_INIT):LAND:(EBI_SETUP != 0)


; Remap on-chip RAM to address 0 -----------------------------------------------

                IF      :DEF:REMAP
                LDR     R0, =(PMU_BASE+PMU_CFG_OFS)
                LDR     R1, [R0, #0]
                ORR     R1, #1          ; SRAM REMAP
                STR     R1, [R0, #0]    ; Execute Remap
                ENDIF


; Copy Exception Vectors to Internal RAM ---------------------------------------

                IF      :DEF:VEC_TO_RAM
                ADR     R8, Vectors     ; Source
                LDR     R9, =IRAM_BASE  ; Destination
                LDMIA   R8!, {R0-R7}    ; Load Vectors 
                STMIA   R9!, {R0-R7}    ; Store Vectors 
                LDMIA   R8!, {R0-R7}    ; Load Handler Addresses 
                STMIA   R9!, {R0-R7}    ; Store Handler Addresses
                ENDIF


; Cache Setup ------------------------------------------------------------------

                IF      ICACHE_SETUP != 0
                MRC     p15, 0, R0, c1, c0, 0   ; Enable Instruction Cache
                ORR     R0, R0, #ICACHE_ENABLE
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
