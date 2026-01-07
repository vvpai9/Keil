;/*****************************************************************************/
;/* LPC3000.S: Startup file for Philips LPC3000 device series                 */
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
; *  The LPC3000.S code is executed after CPU Reset. This file may be 
; *  translated with the following SET symbols. In uVision these SET 
; *  symbols are entered under Options - ASM - Define.
; *
; *  REMAP:         when set, the startup code remaps exception vectors from
; *                 on-chip RAM to address 0.
; *
; *  RAM_INTVEC:    when set, the startup code copies exception vectors 
; *                 from on-chip Flash to on-chip RAM.
; *
; *  SDRAM_INIT:    when set, the SDRAM controller is initialized in startup
; *                 (if 2-nd level bootloader is used this should not be set 
; *                 as bootloader already initializes SDRAM).
; *
; *  NAND_INIT:     when set, the NAND Flash controller is initialized in 
; *                 startup (if 2-nd level bootloader is used this should 
; *                 not be set as bootloader already initializes NAND Flash
; *                 controller).
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


;----------------------- Memory Definitions ------------------------------------

; Internal Memory Base Addresses
IRAM_BASE       EQU     0x08000000
IROM_BASE       EQU     0x0C000000

; External Memory Base Addresses
ERAM_BASE       EQU     0x80000000


; System Control User Interface
SYSTEM_BASE     EQU     0x40004000      ; System Control          Base Address
BOOT_MAP_OFS    EQU     0x14            ; Boot Map Control Reg    Address Offset

; Constants
REMAP_BIT       EQU     (1<<0)          ; Remap RAM to 0

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

Heap_Size       EQU     0x00000800

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


;----------------------- SDRAM Definitions -------------------------------------

; SDRAM Controller (SDRAMC) User Interface
SDRAMCLK_CTRL_OFS   EQU     0x68        ; SDRAM Configuration Reg Address Offset
DDR_LAP_NOM_OFS     EQU     0x6C        ; DDR DQS Nominal Value   Address Offset
RINGOSC_CTRL_OFS    EQU     0x88        ; Ring Oscillator Values  Address Offset
                                        
SDRAMC_BASE         EQU     0x31080000  ; SDRAM Controller        Base Address
MPMCControl_OFS     EQU     0x00        ; Memory Controller Contr Address Offset
MPMCStatus_OFS      EQU     0x04        ; SDRAMC Status           Address Offset
MPMCConfig_OFS      EQU     0x08        ; SDRAMC Controller Cfg R Address Offset
MPMCDynControl_OFS  EQU     0x20        ; Dynamic Mem Control Reg Address Offset
MPMCDynRefresh_OFS  EQU     0x24        ; Dynamic Mem Refresh Reg Address Offset
MPMCDynReadCfg_OFS  EQU     0x28        ; Dynamic Mem Read Config Address Offset
MPMCDynRP_OFS       EQU     0x30        ; Precharge Cmd Period    Address Offset
MPMCDynRAS_OFS      EQU     0x34        ; Active to Prchg Period  Address Offset
MPMCDynSREX_OFS     EQU     0x38        ; Self-refresh Exit Time  Address Offset
MPMCDynWR_OFS       EQU     0x44        ; Write Recovery Time     Address Offset
MPMCDynRC_OFS       EQU     0x48        ; Act to Act Cmd Period   Address Offset
MPMCDynRFC_OFS      EQU     0x4C        ; Auto-refresh Period     Address Offset
MPMCDynXSR_OFS      EQU     0x50        ; Exit Selfref to Act Cmd Address Offset
MPMCDynRRD_OFS      EQU     0x54        ; Active bank A to B      Address Offset
MPMCDynMRD_OFS      EQU     0x58        ; Load Mode to Act Cmd    Address Offset
MPMCDynCDLR_OFS     EQU     0x5C        ; Last data into Read Cmd Address Offset
MPMCDynConfig0_OFS  EQU     0x100       ; SDRAM Config Info       Address Offset
MPMCDynRasCas0_OFS  EQU     0x104       ; RAS and CAS Latencies   Address Offset
MPMCAHBControl0_OFS EQU     0x400       ; AHB port 0 Control Reg  Address Offset
MPMCAHBStatus0_OFS  EQU     0x404       ; AHB port 0 Status  Reg  Address Offset
MPMCAHBTimeOut0_OFS EQU     0x408       ; AHB port 0 Timeout Reg  Address Offset
MPMCAHBControl2_OFS EQU     0x440       ; AHB port 2 Control Reg  Address Offset
MPMCAHBStatus2_OFS  EQU     0x444       ; AHB port 2 Status  Reg  Address Offset
MPMCAHBTimeOut2_OFS EQU     0x448       ; AHB port 2 Timeout Reg  Address Offset
MPMCAHBControl3_OFS EQU     0x460       ; AHB port 3 Control Reg  Address Offset
MPMCAHBStatus3_OFS  EQU     0x464       ; AHB port 3 Status  Reg  Address Offset
MPMCAHBTimeOut3_OFS EQU     0x468       ; AHB port 3 Timeout Reg  Address Offset
MPMCAHBControl4_OFS EQU     0x480       ; AHB port 4 Control Reg  Address Offset
MPMCAHBStatus4_OFS  EQU     0x484       ; AHB port 4 Status  Reg  Address Offset
MPMCAHBTimeOut4_OFS EQU     0x488       ; AHB port 4 Timeout Reg  Address Offset

SDRAM_MODE_REG      EQU     0x80018000  ; SDRAM Mode Register     Address
SDRAM_EXT_MODE_REG  EQU     0x8102C000  ; SDRAM Extended Mode Reg Address

; Constants
NORMAL_CMD      EQU     (0x0 << 7)      ; NORMAL        Command
MODE_CMD        EQU     (0x1 << 7)      ; MODE          Command
PALL_CMD        EQU     (0x2 << 7)      ; Precharge All Command
NOP_CMD         EQU     (0x3 << 7)      ; NOP           Command
REFSH_MODE      EQU     (0x1 << 2)      ; Self-refresh mode

;// <e> SDRAM Controller Configuration (SDRAMC)
SDRAMC_SETUP    EQU     0

;//   <h> SDRAM Clock Control Register (SDRAMCLK_CTRL)
;//     <o0.22>  SDRAM_PIN_SPEED3: Slew rate on the pin RAM_CLK
;//                   <0=> Fast
;//                   <1=> Slow
;//                   <i>  Default: Fast
;//     <o0.21>  SDRAM_PIN_SPEED2: Slew rate on the pins RAM_A[14:0], RAM_CKE, RAM_CS_N, RAM_RAS_N, RAM_WR_N
;//                   <0=> Fast
;//                   <1=> Slow
;//                   <i>  Default: Fast
;//     <o0.20>  SDRAM_PIN_SPEED0: Slew rate on the pins RAM_D[31:0], RAM_DQM[3:0]
;//                   <0=> Fast
;//                   <1=> Slow
;//                   <i>  Default: Fast
;//     <o0.19>      SW_DDR_RESET: Reset SDRAM Controller when writing from 0 to 1
;//                   <0=> No Reset
;//                   <1=> Reset Active
;//                   <i>  Default: No Reset
;//     <o0.14..18> HCLKDELAY_DELAY: Delay of the HCLKDELAY input from the HCLK <0-31>
;//                   <i>  Delay = value programmed * 0.25ns
;//                   <i>  Default: 0
;//     <o0.13>                    Delay circuitry Adder status
;//                   <0=> No overflow or sign bit
;//                   <1=> Last calibration produced overflow or negative number
;//     <o0.10..12>                Sensitivity factor for DDR SDRAM calibration <0-7>
;//                   <i>  Number of bits to shift error value
;//                   <i>  Default: 0
;//     <o0.9>          CAL_DELAY: Delay settings for DDR SDRAM
;//                   <0=> Un-calibrated
;//                   <1=> Calibrated
;//                   <i>  Default: Un-calibrated
;//     <o0.8>         SW_DDR_CAL: Perform DDR calibration
;//                   <0=> No manual DDR delay calibration
;//                   <1=> Perform a DDR delay calibration
;//                   <i>  Default: No manual DDR delay calibration
;//     <o0.7>        RTC_TICK_EN: Automatic DDR delay calibration
;//                   <0=> No
;//                   <1=> Yes, on each RTC TICK
;//                   <i>  Default: No
;//     <o0.2..6> DDR_DQSIN_DELAY: Delay of the DQS input from the DDR SDRAM device
;//                   <0-15>
;//                   <i>  Delay = value programmed * 0.25ns
;//                   <i>  Default: 0
;//     <o0.1>            DDR_SEL: Pin multiplexing selection
;//                   <0=> SDR SDRAM used
;//                   <1=> DDR SDRAM used
;//                   <i>  Default: SDR SDRAM used
;//     <o0.0>                     Clock enable
;//                   <0=> SDRAM HCLK and inverted HCLK enabled
;//                   <1=> All clocks to SDRAM block disabled
;//                   <i>  Default: SDRAM HCLK and inverted HCLK enabled
;//   </h>
SDRAMCLK_CTRL_Val  EQU  0x0001C000

;//   <h> Dynamic Memory Refresh Timer Register (MPMCDynamicRefresh)
;//     <o0.0..10>        REFRESH: Multiple of 16 clocks between SDRAM refresh cycles <0-2047>
;//   </h>
MPMCDynRefresh_Val EQU  0x00000065

;//   <h> Dynamic Memory Read Configuration Register (MPMCDynamicReadConfig)
;//     <o0.12>               DRP: DDR SDRAM read data capture polarity
;//                   <0-1>
;//     <o0.8..9>             DRD: DDR SDRAM read data strategy
;//                   <0=> Using RAM_CLK
;//                   <1=> Using MPMCCLKDELAY
;//                   <2=> Plus 1 clock cycle, using MPMCCLKDELAY
;//                   <3=> Plus 2 clock cycle, using MPMCCLKDELAY
;//     <o0.4>                SRP: SDR-SDRAM read data capture polarity
;//                   <0=> Data captured on negative edge of HCLK
;//                   <1=> Data captured on positive edge of HCLK
;//     <o0.0..1>             SRD: SDR-SDRAM read data strategy
;//                   <0=> Using RAM_CLK
;//                   <1=> Using MPMCCLKDELAY
;//                   <2=> Plus 1 clock cycle, using MPMCCLKDELAY
;//                   <3=> Plus 2 clock cycle, using MPMCCLKDELAY
;//   </h>
MPMCDynReadCfg_Val EQU  0x00000011

;//   <h> Dynamic Memory Precharge Command Period Register (MPMCDynamicRP)
;//     <o0.0..3>             tRP: Precharge command period <0-15>
;//                   <i>  (value + 1) clock cycles
;//   </h>
MPMCDynRP_Val      EQU  0x00000002

;//   <h> Dynamic Memory Active to Precharge Command Period Register (MPMCDynamicRAS)
;//     <o0.0..3>            tRAS: Active to Precharge command period <0-15>
;//                   <i>  (value + 1) clock cycles
;//   </h>
MPMCDynRAS_Val     EQU  0x00000005

;//   <h> Dynamic Memory Self-refresh Exit Time Register (MPMCDynamicSREX)
;//     <o0.0..6>           tSREX: Self-refresh exit time <0-127>
;//                   <i>  (value + 1) clock cycles
;//   </h>
MPMCDynSREX_Val    EQU  0x00000008

;//   <h> Dynamic Memory Write Recovery Time Register (MPMCDynamicWR)
;//     <o0.0..3>             tWR: Write recovery time <0-15>
;//                   <i>  (value + 1) clock cycles
;//   </h>
MPMCDynWR_Val      EQU  0x00000001

;//   <h> Dynamic Memory Active to Active Command Period Register (MPMCDynamicRC)
;//     <o0.0..4>             tRC: Active to active command <0-31>
;//                   <i>  (value + 1) clock cycles
;//   </h>
MPMCDynRC_Val      EQU  0x00000008

;//   <h> Dynamic Memory Auto-refresh Period Register (MPMCDynamicRFC)
;//     <o0.0..4>            tRFC: Auto-refresh period and auto-refresh to active command period <0-31>
;//                   <i>  (value + 1) clock cycles
;//   </h>
MPMCDynRFC_Val     EQU  0x00000008

;//   <h> Dynamic Memory Exit Self-refresh Register (MPMCDynamicXSR)
;//     <o0.0..7>            tXSR: Exit self-refresh to active command time <0-255>
;//                   <i>  (value + 1) clock cycles
;//   </h>
MPMCDynXSR_Val     EQU  0x00000008

;//   <h> Dynamic Memory Active Bank A to Active Bank B Time Register (MPMCDynamicRRD)
;//     <o0.0..3>            tRRD: Active bank A to active bank B latency <0-15>
;//                   <i>  (value + 1) clock cycles
;//   </h>
MPMCDynRRD_Val     EQU  0x00000001

;//   <h> Dynamic Memory Load Mode Register to Active Command Time (MPMCDynamicMRD)
;//     <o0.0..3>            tMRD: Load mode register to active command time <0-15>
;//                   <i>  (value + 1) clock cycles
;//   </h>
MPMCDynMRD_Val     EQU  0x00000001

;//   <h> Dynamic Memory Last Data In to Read Command Time (MPMCDynamicCDLR)
;//     <o0.0..3>           tCDLR: Last data in to read command time <0-15>
;//                   <i>  (value + 1) clock cycles
;//   </h>
MPMCDynCDLR_Val    EQU  0x00000000

;//   <h> Dynamic Memory Configuration Register (MPMCDynamicConfig0)
;//     <o0.20>                WP: Write Protect
;//                   <0=> Not protected
;//                   <1=> Protected
;//     <o0.14>                    Address Mapping - number of bits on external bus
;//                   <0=> 16-bit
;//                   <1=> 32-bit
;//     <o0.12..13>                Address Mapping - power setting for external bus
;//                   <0=> High-performance
;//                   <1=> Low-power
;//     <o0.9..11>                 Address Mapping - SDRAM size
;//                   <0=>  16Mb
;//                   <1=>  64Mb
;//                   <2=> 128Mb
;//                   <3=> 256Mb
;//                   <4=> 512Mb
;//     <o0.7..8>                  Address Mapping - SDRAM organization
;//                   <0=> x8
;//                   <1=> x16
;//                   <2=> x32
;//                   <i>  Example: 64Mb = 2M x "32", 256Mb = 32M x "8"
;//     <o0.0..2>              MD: Memory device
;//                   <0=> SDR SDRAM
;//                   <2=> Low power SDR SDRAM
;//                   <4=> DDR SDRAM
;//                   <6=> Low power DDR SDRAM
;//   </h>
MPMCDynConfig0_Val EQU  0x00005482

;//   <h> Dynamic Memory RAS and CAS Delay Register (MPMCDynamicRasCas0)
;//     <o0.7..10>            CAS: CAS latency <1-15>
;//                   <i>  (value /2) clock cycles
;//     <o0.0..3>             RAS: RAS latency <1-15>
;//                   <i>  (value) clock cycles
;//   </h>
MPMCDynRasCas0_Val EQU  0x00000303

;//   <h> AHB Port 0 Settings
;//     <h> Control Register (MPMCAHBControl0)
;//       <e0.0>                   AHB port buffer enable
;//       </e>
;//     </h>
;//     <h> Timeout Register (MPMCAHBTimeOut0)
;//       <o0.0..9>    AHBTIMEOUT: AHB timeout <0-1023>
;//     </h>
;//   </h>
MPMCAHBControl0_Val EQU 0x00000001
MPMCAHBTimeOut0_Val EQU 0x00000064

;//   <h> AHB Port 2 Settings
;//     <h> Control Register (MPMCAHBControl2)
;//       <e0.0>                   AHB port buffer enable
;//       </e>
;//     </h>
;//     <h> Timeout Register (MPMCAHBTimeOut2)
;//       <o0.0..9>    AHBTIMEOUT: AHB timeout <0-1023>
;//     </h>
;//   </h>
MPMCAHBControl2_Val EQU 0x00000001
MPMCAHBTimeOut2_Val EQU 0x00000190
               
;//   <h> AHB Port 3 Settings
;//     <h> Control Register (MPMCAHBControl3)
;//       <e0.0>                   AHB port buffer enable
;//       </e>
;//     </h>
;//     <h> Timeout Register (MPMCAHBTimeOut3)
;//       <o0.0..9>    AHBTIMEOUT: AHB timeout <0-1023>
;//     </h>
;//   </h>
MPMCAHBControl3_Val EQU 0x00000001
MPMCAHBTimeOut3_Val EQU 0x00000190

;//   <h> AHB Port 4 Settings
;//     <h> Control Register (MPMCAHBControl4)
;//       <e0.0>                   AHB port buffer enable
;//       </e>
;//     </h>
;//     <h> Timeout Register (MPMCAHBTimeOut4)
;//       <o0.0..9>    AHBTIMEOUT: AHB timeout <0-1023>
;//     </h>
;//   </h>
MPMCAHBControl4_Val EQU 0x00000001
MPMCAHBTimeOut4_Val EQU 0x00000190

;// </e> SDRAM Controller Configuration (SDRAMC)


;----------------------- NAND Flash Definitions --------------------------------

; NAND Flash Controller (NANDC) User Interface
; Single-level NAND flash controller definitions
FLASHCLK_CTRL_OFS   EQU     0xC8        ; NAND Configuration Reg  Address Offset
                                        
SLC_BASE            EQU     0x20020000  ; SLC NAND Controller     Base Address
                                        ; SLC NAND Flash Registers
SLC_DATA_OFS        EQU     0x00        ; Data           Register Address Offset
SLC_ADDR_OFS        EQU     0x04        ; Address        Register Address Offset
SLC_CMD_OFS         EQU     0x08        ; Command        Register Address Offset
SLC_STOP_OFS        EQU     0x0C        ; STOP           Register Address Offset
SLC_CTRL_OFS        EQU     0x10        ; Control        Register Address Offset
SLC_CFG_OFS         EQU     0x14        ; Configuration  Register Address Offset
SLC_STAT_OFS        EQU     0x18        ; Status         Register Address Offset
SLC_INT_STAT_OFS    EQU     0x1C        ; Interrupt Status    Reg Address Offset
SLC_IEN_OFS         EQU     0x20        ; Interrupt Enable    Reg Address Offset
SLC_ISR_OFS         EQU     0x24        ; Interrupt Set       Reg Address Offset
SLC_ICR_OFS         EQU     0x28        ; Interrupt Clear     Reg Address Offset
SLC_TAC_OFS         EQU     0x2C        ; Read Timing Arc Cfg Reg Address Offset
SLC_TC_OFS          EQU     0x30        ; Transfer Count Register Address Offset
SLC_ECC_OFS         EQU     0x34        ; Parity Bits    Register Address Offset
SLC_DMA_DATA_OFS    EQU     0x38        ; DMA DATA       Register Address Offset

; Multi-level NAND flash controller definitions
MLC_DATA_BASE       EQU     0x200A8000  ; MLC Data Buffer         Base Address
MLC_BASE            EQU     0x200B8000  ; MLC NAND Controller     Base Address
                                        ; MLC NAND Flash Registers
MLC_CMD_OFS         EQU     0x00        ; Command        Register Address Offset
MLC_ADDR_OFS        EQU     0x04        ; Address        Register Address Offset
MLC_ECC_ENC_REG_OFS EQU     0x08        ; ECC Encode     Register Address Offset
MLC_ECC_DEC_REG_OFS EQU     0x0C        ; ECC Decode     Register Address Offset
MLC_ECC_AUTO_ENC_REG_OFS EQU 0x10       ; ECC Auto Encode     Reg Address Offset
MLC_ECC_AUTO_DEC_REG_OFS EQU 0x14       ; ECC Auto Decode     Reg Address Offset
MLC_RPR_OFS         EQU     0x18        ; Read Parity    Register Address Offset
MLC_WPR_OFS         EQU     0x1C        ; Write Parity   Register Address Offset
MLC_RUBP_OFS        EQU     0x20        ; Reset User Buf Ptr  Reg Address Offset
MLC_ROBP_OFS        EQU     0x24        ; Reset Overhead Buf Ptr  Address Offset
MLC_SW_WP_ADD_LOW_OFS EQU   0x28        ; Sw Wr Protect Low   Reg Address Offset
MLC_SW_WP_ADD_HIG_OFS EQU   0x2C        ; Sw Wr Protect High  Reg Address Offset
MLC_ICR_OFS         EQU     0x30        ; Configuration  Register Address Offset
MLC_TIME_REG_OFS    EQU     0x34        ; Timing         Register Address Offset
MLC_IRQ_MR_OFS      EQU     0x38        ; Interrupt Mask Register Address Offset
MLC_IRQ_SR_OFS      EQU     0x3C        ; Interrupt Status    Reg Address Offset
MLC_LOCK_PR_OFS     EQU     0x44        ; Lock Protection     Reg Address Offset
MLC_ISR_OFS         EQU     0x48        ; Status         Register Address Offset
MLC_CEH_OFS         EQU     0x4C        ; Chip-Enable Host Ctrl R Address Offset


; NAND Flash Commands
NAND_CMD_READ0      EQU     0x00        ; Read mode (1) command
NAND_CMD_READ1      EQU     0x01        ; Read mode (2) command
NAND_CMD_PAGEPROG   EQU     0x10        ; Auto program command
NAND_CMD_READSTART  EQU     0x30        ; Read start command
NAND_CMD_READ2      EQU     0x50        ; Read mode (3) command
NAND_CMD_ERASE1ST   EQU     0x60        ; Auto block erase 1-st command
NAND_CMD_STATUS     EQU     0x70        ; Status read (1) command
NAND_CMD_STATUS_MULTI EQU   0x71        ; Status read (2) command
NAND_CMD_SDIN       EQU     0x80        ; Serial data input command
NAND_CMD_READID     EQU     0x90        ; ID read (1) command
NAND_CMD_ERASE2ND   EQU     0xD0        ; Auto block erase 2-nd command
NAND_CMD_RESET      EQU     0xFF        ; Reset command

; NAND Constants
MLC_LOCK_Val        EQU     0xA25E      ; Unlocking               Constant

;// <e> NAND Flash Controller Configuration (NANDC)
NANDC_SETUP    EQU     0

;//   <h> NAND Clock Control Register (FLASHCLK_CTRL)
;//     <o0.5>   NAND Flash Controller Interrupt
;//                   <0=> SLC NAND Flash controller interrupt enabled
;//                   <1=> MLC NAND Flash controller interrupt enabled
;//                   <i>  Default: SLC NAND Flash controller interrupt enabled
;//     <o0.4>   NAND_DMA_REQ on NAND_RnB (only for MLC)
;//                   <0=> Disabled
;//                   <1=> Enabled
;//                   <i>  Default: Disabled
;//     <o0.3>   NAND_DMA_REQ on NAND_INT (only for MLC)
;//                   <0=> Disabled
;//                   <1=> Enabled
;//                   <i>  Default: Disabled
;//     <o0.2>   SLC/MLC Select
;//                   <0=> Multi-level (MLC) NAND Flash controller
;//                   <1=> Single-level (LLC) NAND Flash controller
;//                   <i>  Default: Multi-level (MLC) NAND Flash controller
;//     <o0.1>   MLC NAND Flash Clock Enable
;//                   <0=> Disabled
;//                   <1=> Enabled
;//                   <i>  Default: Enabled
;//     <o0.0>   SLC NAND Flash Clock Enable
;//                   <0=> Disabled
;//                   <1=> Enabled
;//                   <i>  Default: Enabled
;//   </h>
FLASHCLK_CTRL_Val  EQU  0x00000002

;//   <h> MLC NAND Flash Chip-Enable Host Control Register (MLC_CEH)
;//     <o0.0>   nCE Assert
;//                   <0=> Force nCE assert
;//                   <1=> Normal nCE operation (nCE controlled by controller)
;//                   <i>  Default: Force nCE assert
;//   </h>
MLC_CEH_Val        EQU  0x00000000

;//   <h> MLC NAND Controller Configuration Register (MLC_ICR)
;//     <o0.3>   Software Write Protection
;//                   <0=> Disabled
;//                   <1=> Enabled
;//                   <i>  Default: Disabled
;//     <o0.2>   Block Size
;//                   <0=> Small block flash device ( 512 + 16 bytes page)
;//                   <1=> Large block flash device (2048 + 64 bytes page)
;//                   <i>  Default: Small block flash device ( 512 + 16 bytes page)
;//     <o0.1>   NAND Flash Address Word Count
;//                   <0=> 3 address cycles
;//                   <1=> 4 address cycles
;//                   <i>  Default: 3 address cycles
;//     <o0.0>   NAND Flash I/O Bus Width
;//                   <0=> 8-bit bus width
;//                   <1=> 16-bit bus width (Not supported)
;//                   <i>  Default: 8-bit bus width
;//   </h>
MLC_ICR_Val        EQU  0x00000000

;// </e> NAND Flash Controller Configuration (NANDC)


;----------------------- Clock Definitions -------------------------------------

; Clock User Interface
PWR_CTRL_OFS     EQU    0x44            ; Power Control Register  Address Offset
OSC_CTRL_OFS     EQU    0x4C            ; Main Oscilator Ctrl Reg Address Offset
SYSCLK_CTRL_OFS  EQU    0x50            ; SYSCLK Control Register Address Offset
PLL397_CTRL_OFS  EQU    0x48            ; PLL397 Control Register Address Offset
HCLKPLL_CTRL_OFS EQU    0x58            ; ARM and HCLK Ctrl Reg   Address Offset
HCLKDIV_CTRL_OFS EQU    0x40            ; HCLK Divider Settings   Address Offset

; Constants
NORMAL_RUN_BIT   EQU    (1<<2)          ; Run mode control                   bit
SYSCLK_PLL_BIT   EQU    (1<<1)          ; PLL397 used for system clock       bit
PLL_LOCK_BIT     EQU    (1<<0)          ; PLL locked                         bit
HCLKPLL_PD_BIT   EQU    (1<<16)         ; HCLK PLL power down mode           bit

;// <e> Clock Configuration
CLOCK_SETUP      EQU    1

;//   <h> Main Oscillator Control Register (OSC_CTRL)
;//     <e0.0>                     Main Oscillator Disable
;//     </e>
;//   </h>
OSC_CTRL_Val     EQU    0x00000000

;//   <h> SYSCLK Control Register (SYSCLK_CTRL)
;//     <o0.2..11>                 Bad Phase Length Before Clock Switching Trigger <0x000-0x3FF>
;//     <o0.1>                     Oscillator Switch
;//                   <0=> Switch to main oscillator
;//                   <1=> Switch to 13MHz clock source (PLL397 output)
;//   </h>
SYSCLK_CTRL_Val  EQU    0x00000140

;//   <h> PLL397 Control Register (PLL397_CTRL)
;//     <o0.1>                     PLL397 Operational Control
;//                   <0=> PLL397 is running
;//                   <1=> PLL397 is stopped and is in low power mode
;//   </h>
PLL397_CTRL_Val  EQU    0x00000000

;//   <h> HCLK PLL Control Register (HCLKPLL_CTRL)
;//     <i> Example for 208MHz PLL from 13MHz oscillator
;//     <i> settings:
;//     <i> - PLL Power Down: PLL in operating mode
;//     <i> - Bypass Control: CCO clock is sent to post-divider
;//     <i> - Direct Output Control: CCO clock is the direct output of the PLL
;//     <i> - Feedback Divider Path Control: don't care
;//     <i> - PLL Post-divider Settings (P): don't care
;//     <i> - PLL Pre-divider Settings (N): 1
;//     <i> - PLL Feedback Divider (M): 16
;//     <o0.16>                    PLL Power Down
;//                   <0=> PLL in power down mode
;//                   <1=> PLL in operating mode
;//     <o0.15>                    Bypass Control
;//                   <0=> CCO clock is sent to post-divider
;//                   <1=> PLL input bypasses the CCO
;//     <o0.14>                    Direct Output Control
;//                   <0=> The output of the post-divider is output of the PLL
;//                   <1=> CCO clock is the direct output of the PLL
;//     <o0.13>                    Feedback Divider Path Control
;//                   <0=> Clocked by CCO clock
;//                   <1=> Clocked by PLL_CLKOUT
;//     <o0.11..12>                PLL Post-divider Settings (P)
;//                   <0=> / 2 (P=1)
;//                   <1=> / 4 (P=2)
;//                   <2=> / 8 (P=4)
;//                   <3=> / 16 (P=8)
;//     <o0.9..10>                 PLL Pre-divider Settings (N)
;//                   <0=> 1
;//                   <1=> 2
;//                   <2=> 3
;//                   <3=> 4
;//     <o0.1..8>                  PLL Feedback Divider (M) 
;//                   <1-256><#-1>
;//   </h>
HCLKPLL_CTRL_Val EQU    0x0001401E

;//   <h> HCLK Divider Control Register (HCLKDIV_CTRL)
;//     <o0.7..8>                  DDRAM_CLK Control
;//                   <0=> Stopped
;//                   <1=> Nominal speed
;//                   <2=> Half speed
;//     <o0.2..6>                  PERIPH_CLK Divider Control <1-32><#-1>
;//                   <i>  PERIPH_CLK = ARM PLL clock / value
;//     <o0.0..1>                  HCLK Divider Control
;//                   <0=> HCLK = ARM PLL clock
;//                   <1=> HCLK = ARM PLL clock / 2
;//                   <2=> HCLK = ARM PLL clock / 4
;//   </h>
HCLKDIV_CTRL_Val EQU    0x0000003D

;// </e> Clock Configuration


;----------------------- Vector Floating-Point Definitions ---------------------

; Constants
VFP_EN_BIT      EQU     (1<<30)         ; VFP Enable Bit


;----------------------- Cache Definitions -------------------------------------

; Constants
ICACHE_EN_BIT   EQU     (1<<12)         ; Instruction Cache Enable Bit

;// <e> Instruction Cache Enable
;// </e>
ICACHE_SETUP    EQU     1


;----------------------- CODE --------------------------------------------------

                PRESERVE8
                

; Area Definition and Entry Point
;  Startup Code must be linked first at Address at which it expects to run.

                AREA    RESET, CODE, READONLY
                ARM

                IMPORT  ||Image$$ER_ROM1$$RO$$Length||
                IMPORT  ||Image$$RW_RAM1$$RW$$Length||

; Exception Vectors
;  Mapped to Address 0.
;  Absolute addressing mode must be used.
;  Dummy Handlers are implemented as infinite loops which can be modified.

Vectors         LDR     PC,Reset_Addr         
                LDR     PC,Undef_Addr
                LDR     PC,SWI_Addr
                LDR     PC,PAbt_Addr
                LDR     PC,DAbt_Addr
                DCD     ||Image$$ER_ROM1$$RO$$Length||+\
                        ||Image$$RW_RAM1$$RW$$Length||
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


; SDRAM Setup ------------------------------------------------------------------

                ; Setup SDRAM Controller if enabled
                IF      (:DEF:SDRAM_INIT):LOR:(SDRAMC_SETUP != 0)

                LDR     R0, =SYSTEM_BASE          ; Address of SYSTEM CONTROL Config
                LDR     R1, =SDRAMC_BASE          ; Address of SDRAM Controller
                LDR     R2, =ERAM_BASE            ; External SDRAM Start Address

                MOV     R5, #0                    ; 0 value

                LDR     R4, =SDRAMCLK_CTRL_Val    ; Setup SDRAM Clock
                STR     R4, [R0, #SDRAMCLK_CTRL_OFS]
                MOV     R4, #0x01                 ; Enable SDRAM Controller
                STR     R4, [R1, #MPMCControl_OFS]
                MOV     R4, #0x00                 ; SDRAM Controller CFG -> Set Little-Endian
                STR     R4, [R1, #MPMCConfig_OFS]
                LDR     R4, =MPMCAHBControl0_Val  ; AHB 0 Enable Buffer
                STR     R4, [R1, #MPMCAHBControl0_OFS]
                LDR     R4, =MPMCAHBControl2_Val  ; AHB 2 Enable Buffer
                STR     R4, [R1, #MPMCAHBControl2_OFS]
                LDR     R4, =MPMCAHBControl3_Val  ; AHB 3 Enable Buffer
                STR     R4, [R1, #MPMCAHBControl3_OFS]
                LDR     R4, =MPMCAHBControl4_Val  ; AHB 4 Enable Buffer
                STR     R4, [R1, #MPMCAHBControl4_OFS]
                LDR     R4, =MPMCDynConfig0_Val   ; Dyn Mem Configuration 0
                STR     R4, [R1, #MPMCDynConfig0_OFS]
                LDR     R4, =MPMCDynRasCas0_Val   ; Dyn Mem RAS and CAS Setup
                STR     R4, [R1, #MPMCDynRasCas0_OFS]
                LDR     R4, =MPMCDynReadCfg_Val   ; Dyn Mem Read Config
                STR     R4, [R1, #MPMCDynReadCfg_OFS]
                LDR     R4, =MPMCDynRP_Val        ; Dyn Mem Prchg Cmd Time
                STR     R4, [R1, #MPMCDynRP_OFS]
                LDR     R4, =MPMCDynRAS_Val       ; Mem Act to Prchg Cmd Time
                STR     R4, [R1, #MPMCDynRAS_OFS]
                LDR     R4, =MPMCDynSREX_Val      ; Dyn Mem Self-Rfsh Exit Time
                STR     R4, [R1, #MPMCDynSREX_OFS]
                LDR     R4, =MPMCDynWR_Val        ; Dyn Mem Write Recovery Time
                STR     R4, [R1, #MPMCDynWR_OFS]
                LDR     R4, =MPMCDynRC_Val        ; Mem Act to Act Cmd Time
                STR     R4, [R1, #MPMCDynRC_OFS]
                LDR     R4, =MPMCDynRFC_Val       ; Dyn Mem Auto-Rfsh Period
                STR     R4, [R1, #MPMCDynRFC_OFS]
                LDR     R4, =MPMCDynXSR_Val       ; Dyn Mem Exit Self-Rfsh
                STR     R4, [R1, #MPMCDynXSR_OFS]
                LDR     R4, =MPMCDynRRD_Val       ; Dyn Mem Bnk A to Bnk B
                STR     R4, [R1, #MPMCDynRRD_OFS]
                LDR     R4, =MPMCDynMRD_Val       ; Dyn Mem Load Mode Reg to Act
                STR     R4, [R1, #MPMCDynMRD_OFS]
                LDR     R4, =MPMCDynCDLR_Val      ; Dyn Mem Last Data In to Read
                STR     R4, [R1, #MPMCDynCDLR_OFS]

                MOV     R6, #0x100                ; Number of cycles to delay
Wait_SDRAMC_0   SUBS    R6, R6, #1                ; Delay
                BNE     Wait_SDRAMC_0

                LDR     R4, =(NOP_CMD:OR:0x13)    ; Write NOP Command
                STR     R4, [R1, #MPMCDynControl_OFS]

                MOV     R6, #0x200                ; Number of cycles to delay
Wait_SDRAMC_1   SUBS    R6, R6, #1                ; Delay
                BNE     Wait_SDRAMC_1

                LDR     R4, =(PALL_CMD:OR:0x13)   ; Write Precharge All Command
                STR     R4, [R1, #MPMCDynControl_OFS]
                MOV     R4, #0x02                 ; Dyn Mem Refresh Timer
                STR     R4, [R1, #MPMCDynRefresh_OFS]

                MOV     R6, #0x15                 ; Number of cycles to delay
Wait_SDRAMC_2   SUBS    R6, R6, #1                ; Delay
                BNE     Wait_SDRAMC_2

                LDR     R4, =MPMCDynRefresh_Val   ; Dyn Mem Refresh Timer
                STR     R4, [R1, #MPMCDynRefresh_OFS]
                LDR     R4, =MPMCDynRasCas0_Val   ; Dyn Mem RAS and CAS Setup
                STR     R4, [R1, #MPMCDynRasCas0_OFS]
                LDR     R4, =MPMCDynConfig0_Val   ; Dyn Mem Configuration 0
                STR     R4, [R1, #MPMCDynConfig0_OFS]
                LDR     R4, =(MODE_CMD:OR:0x13)   ; Write MODE Command
                STR     R4, [R1, #MPMCDynControl_OFS]
                LDR     R4, =SDRAM_MODE_REG       ; Load Mode Register
                LDR     R4, [R4, #0]
                LDR     R4, =(MODE_CMD:OR:0x13)   ; Write MODE Command
                STR     R4, [R1, #MPMCDynControl_OFS]
                LDR     R4, =SDRAM_MODE_REG       ; Load Extended Mode Register
                LDR     R4, [R4, #0]
                LDR     R4, =(NORMAL_CMD:OR:0x10) ; Write NORMAL Command
                STR     R4, [R1, #MPMCDynControl_OFS]
                LDR     R4, =MPMCAHBTimeOut0_Val  ; AHB 0 Timeout
                STR     R4, [R1, #MPMCAHBTimeOut0_OFS]
                LDR     R4, =MPMCAHBTimeOut2_Val  ; AHB 2 Timeout
                STR     R4, [R1, #MPMCAHBTimeOut2_OFS]
                LDR     R4, =MPMCAHBTimeOut3_Val  ; AHB 3 Timeout
                STR     R4, [R1, #MPMCAHBTimeOut3_OFS]
                LDR     R4, =MPMCAHBTimeOut4_Val  ; AHB 4 Timeout
                STR     R4, [R1, #MPMCAHBTimeOut4_OFS]

                ENDIF   ; of IF      :DEF:SDRAM_INIT or SDRAMC_SETUP != 0


; NAND Flash Setup -------------------------------------------------------------

                ; Setup NAND Controller if enabled
                IF      (:DEF:NAND_INIT):LOR:(NANDC_SETUP != 0)

                LDR     R0, =SYSTEM_BASE          ; Address of SYSTEM CONTROL Config
                LDR     R1, =MLC_BASE             ; Address of MLC NAND Controller
                LDR     R2, =MLC_DATA_BASE        ; Address of MLC Data Buffer
                MOV     R5, #0                    ; 0 value

                LDR     R4, =FLASHCLK_CTRL_Val    ; Setup NAND Flash Clock Control
                STR     R4, [R0, #FLASHCLK_CTRL_OFS]
                LDR     R4, =MLC_CEH_Val          ; Setup NAND Flash Chip-Enable Control
                STR     R4, [R1, #MLC_CEH_OFS]
                LDR     R4, =NAND_CMD_RESET       ; Reset NAND Flash
                STR     R4, [R1, #MLC_CMD_OFS]
                BL      NAND_Wait                 ; Wait for operation to finish
                LDR     R4, =MLC_LOCK_Val         ; Unlock write to MLC_ICR
                STR     R4, [R1, #MLC_LOCK_PR_OFS]
                LDR     R4, =MLC_ICR_Val          ; Setup NAND Controller Configuration
                STR     R4, [R1, #MLC_ICR_OFS]
                BL      NAND_Wait                 ; Wait for operation to finish
                B       NAND_End                  ; NAND Setup Finished

                MOV     R6, #0x01                 ; Wait function
                MOV     R7, #16
NAND_Wait       LDR     R5, [R0, #MLC_ISR_OFS]
                ANDS    R5, R5, R6
                BNE     NAND_Wait_Dec
NAND_Wait_More  LDR     R5, [R0, #MLC_ISR_OFS]
                ANDS    R5, R5, R6
                BNE     NAND_Wait_More
                BX      R14
NAND_Wait_Dec   SUBS    R7, R7, #1
                BNE     NAND_Wait

NAND_End

                ENDIF   ; of IF      :DEF:NAND_INIT or NANDC_SETUP != 0


; Clock Setup ------------------------------------------------------------------

                IF      CLOCK_SETUP != 0

                LDR     R0, =SYSTEM_BASE

                ; If PLL397 is used for system clock
                IF      (SYSCLK_CTRL_Val:AND:SYSCLK_PLL_BIT) != 0
PLL_Loop        LDR     R1, [R0, #PLL397_CTRL_OFS]    ; Wait for PLL397 stabil
                ANDS    R1, R1, #PLL_LOCK_BIT
                BEQ     PLL_Loop
                LDR     R1, =SYSCLK_CTRL_Val          ; Switch to PLL397
                STR     R1, [R0, #SYSCLK_CTRL_OFS]
                LDR     R1, =OSC_CTRL_Val             ; Control main oscillator
                STR     R1, [R0, #OSC_CTRL_OFS]

                ELSE    ; If PLL397 is not used for system clock
                LDR     R1, =SYSCLK_CTRL_Val          ; Control PLL397
                STR     R1, [R0, #SYSCLK_CTRL_OFS]
                ENDIF

                LDR     R1, =HCLKPLL_CTRL_Val         ; Setup HCLK PLL
                STR     R1, [R0, #HCLKPLL_CTRL_OFS]

                ; If HCLK PLL is setup for operating mode
                IF      (HCLKPLL_CTRL_Val:AND:HCLKPLL_PD_BIT) != 0
HCLK_Loop       LDR     R1, [R0, #HCLKPLL_CTRL_OFS]   ; Wait for HCLK stabil
                ANDS    R1, R1, #PLL_LOCK_BIT
                BEQ     HCLK_Loop
                LDR     R1, =HCLKDIV_CTRL_Val         ; Setup HCLK dividers
                STR     R1, [R0, #HCLKDIV_CTRL_OFS]

                LDR     R1, [R0, #PWR_CTRL_OFS]       ; Switch to Normal RUN
                ORR     R1, R1, #NORMAL_RUN_BIT
                STR     R1, [R0, #PWR_CTRL_OFS]
                ENDIF

                ENDIF   ; of IF      CLOCK_SETUP != 0


; Copy Exception Vectors to Internal RAM ---------------------------------------

                IF      :DEF:RAM_INTVEC
                ADR     R8,  Vectors    ; Source
                LDR     R9, =IRAM_BASE  ; Destination
                LDMIA   R8!, {R0-R7}    ; Load Vectors 
                STMIA   R9!, {R0-R7}    ; Store Vectors 
                LDMIA   R8!, {R0-R7}    ; Load Handler Addresses 
                STMIA   R9!, {R0-R7}    ; Store Handler Addresses
                ENDIF


; Remap on-chip RAM to address 0 -----------------------------------------------

                IF      :DEF:REMAP
                LDR     R0, =SYSTEM_BASE
                MOV     R1, #REMAP_BIT  ; Remap for Instruction and Data Master
                STR     R1, [R0, #BOOT_MAP_OFS] ; Execute Remap
                ENDIF


; Vector Floating-Point (VFP) Setup --------------------------------------------

                IF      {FPU} != "SoftVFP"
                MOV     R1, #VFP_EN_BIT ; Enable VFP
                FMXR    FPEXC, R1
                ENDIF


; Cache Setup ------------------------------------------------------------------

                IF      ICACHE_SETUP != 0
                MRC     p15, 0, R0, c1, c0, 0   ; Enable Instruction Cache
                ORR     R0, R0, #ICACHE_EN_BIT
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
