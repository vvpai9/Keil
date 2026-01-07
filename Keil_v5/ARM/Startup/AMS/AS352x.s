;/*****************************************************************************/
;/* AS352x.S: Startup file for AustriaMicroSystems AS352x device series       */
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
; *  The AS352x.S code is executed after CPU Reset. This file may be 
; *  translated with the following SET symbols. In uVision these SET 
; *  symbols are entered under Options - ASM - Define.
; *
; *  REMAP:         when set, the startup code remaps exception vectors from
; *                 on-chip RAM to address 0.
; *
; *  RAM_INTVEC:    when set, the startup code copies exception vectors 
; *                 to on-chip RAM.
; *
; *  CLOCK_INIT:    when set, the clock is initialized in startup.
; *
; *  SDRAM_INIT:    when set, the SDRAM controller is initialized in startup.
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
IRAM_BASE       EQU     0x81000000
IROM_BASE       EQU     0x80000000

; External Memory Base Addresses
ERAM_BASE       EQU     0x30000000


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


;----------------------- Clock Generation Unit Definitions -------------------- 

CGU_BASE        EQU     0xC80F0000      ; Clock Generation Unit    Base Address        
CGU_PLLA_OFS    EQU     0x00            ; PLLA Configuration Register    Offset
CGU_PLLB_OFS    EQU     0x04            ; PLLB Configuration Register    Offset
CGU_PLLASUP_OFS EQU     0x08            ; PLLA Supervisor Register       Offset
CGU_PLLBSUP_OFS EQU     0x0C            ; PLLB Supervisor Register       Offset
CGU_PROC_OFS    EQU     0x10            ; Processor Clock Control Reg    Offset
CGU_PERI_OFS    EQU     0x14            ; Peripheral Clock Control Reg   Offset
CGU_AUDIO_OFS   EQU     0x18            ; Audio Clock Control Register   Offset
CGU_USB_OFS     EQU     0x1C            ; USB Clock Control Register     Offset
CGU_INTCTRL_OFS EQU     0x20            ; CGU Interrupt Mask and Enable  Offset
CGU_IRQ_OFS     EQU     0x24            ; Interrupt Clear and Lock Stat  Offset
CGU_COUNTA_OFS  EQU     0x28            ; PLLA Lock Counter Register     Offset
CGU_COUNTB_OFS  EQU     0x2C            ; PLLB Lock Counter Register     Offset
CGU_IDE_OFS     EQU     0x30            ; IDE Clock Control Register     Offset
CGU_MS_OFS      EQU     0x34            ; Memory Stick Clock Control Reg Offset
CGU_DBOP_OFS    EQU     0x38            ; DBOP Clock Controller Register Offset

; Constants
PLLB_LOCK_Val   EQU     (1 << 1)        ; PLLB lock status
PLLA_LOCK_Val   EQU     (1 << 0)        ; PLLA lock status


;// <e0> Clock Setup
;//   <e1> PLLA Settings
;//     <h> PLLA Configuration Register (CGU_PLLA)
;//       <o2.13..14> PLLA_OD: PLLA output divider control <0-3>
;//       <o2.8..12>  PLLA_R: PLLA input divider control <0-31>
;//       <o2.0..7>   PLLA_F: PLLA feedback divider control <0-255>
;//     </h>
;//     <h> PLLA Supervisor Register (CGU_PLLASUP)
;//       <o3.3>      PLLA_PD: PLLA power down enabled
;//       <o3.2>      PLLA_OEB: PLLA output enable
;//       <o3.1>      PLLA_BP: PLLA bypass
;//       <o3.0>      PLLA_FIN_SEL: PLLA clock source select
;//         <0=> clk_int <1=> clk_ext
;//     </h>
;//     <h> PLLA Lock Counter Register (CGU_COUNTA)
;//       <o4.0..7>   COUNTA: Number of PLLA clocks until LOCKA bit is set <0-255>
;//     </h>
;//   </e>
CLOCK_SETUP     EQU     0
PLLA_SETUP      EQU     1
CGU_PLLA_Val    EQU     0x00002630
CGU_PLLASUP_Val EQU     0x00000000
CGU_COUNTA_Val  EQU     0x000000FF

;//   <e0> PLLB Settings
;//     <h> PLLB Configuration Register (CGU_PLLB)
;//       <o1.13..14> PLLB_OD: PLLB output divider control <0-3>
;//       <o1.8..12>  PLLB_R: PLLB input divider control <0-31>
;//       <o1.0..7>   PLLB_F: PLLB feedback divider control <0-255>
;//     </h>
;//     <h> PLLB Supervisor Register (CGU_PLLBSUP)
;//       <o2.3>      PLLB_PD: PLLB power down enabled
;//       <o2.2>      PLLB_OEB: PLLB output enable
;//       <o2.1>      PLLB_BP: PLLB bypass
;//       <o2.0>      PLLB_FIN_SEL: PLLB clock source select
;//         <0=> clk_int <1=> clk_ext
;//     </h>
;//     <h> PLLA Lock Counter Register (CGU_COUNTA)
;//       <o3.0..7>   COUNTA: Number of PLLA clocks until LOCKA bit is set <0-255>
;//     </h>
;//   </e>

PLLB_SETUP      EQU     0
CGU_PLLB_Val    EQU     0x00000000
CGU_PLLBSUP_Val EQU     0x00000000
CGU_COUNTB_Val  EQU     0x00000000

;//   <h> Processor Clock Controller Register (CGU_PROC)
;//     <o0.4..7> FCLK_POSTDIV_SEL: Post divider division ratio <0-15>
;//       <i> post_div = 1 / (fclk_postdiv_sel + 1)
;//     <o0.2..3> FCLK_PREDIV_SEL: Pre divider (fractional) division ratio
;//       <0=> pre_div = 1/1 <1=> pre_div = 7/8
;//       <2=> pre_div = 6/8 <3=> pre_div = 5/8
;//     <o0.0..1> FCLK_SEL: clkin select
;//       <0=> clk_main      <1=> plla_fout
;//       <2=> pllb_fout     <3=> reserved (clk_main)
;//   </h>

CGU_PROC_Val    EQU     0x00000051

;//   <h> Peripheral Clock Controller Register (CGU_PERI)
;//     <i> Peripheral clock must not exceed 65 MHz
;//     <o0.28>    MBIST_EN: Memory bist manager clock enable
;//     <o0.27>    EXTMEM_EN: External memory clock enable
;//     <o0.26>    EXTMEMIF_EN: External memory AHB IF clock enable
;//     <o0.25>    1TRAM_EN: 1TRAM controller AHB IF clock enable
;//     <o0.24>    ROM_EN: ROM AHB IF clock enable
;//     <o0.23>    VIC_EN: Vectored interrupt controller AHB IF clock enable
;//     <o0.22>    DMAC_EN: DMA controller AHB IF clock enable
;//     <o0.21>    USB_EN: USB controller AHB IF clock enable
;//     <o0.20>    I2SO_APB_EN: I2Sout APB IF clock enable
;//     <o0.19>    I2SI_APB_EN: I2Sin APB IF clock enable
;//     <o0.18>    I2C_EN: I2C master/slave APB IF clock enable
;//     <o0.17>    I2C_AUDIO_EN: I2C audio APB IF clock enable
;//     <o0.16>    GPIO_EN: General purpose APB IF clock enable
;//     <o0.15>    SDMCI_EN: Secure digital/multimedia APB IF clock enable
;//     <o0.14>    NANDFLASH_EN: NAND flash/Smart Media APB IF clock enable
;//     <o0.13>    UART_EN: UART APB IF clock enable
;//     <o0.12>    WDOCNT_EN: Watchdog counter clock enable
;//     <o0.11>    WDOIF_EN: Watchdog timer module APB IF clock enable
;//     <o0.10>    SSP_EN: Synchronous serial port APB IF clock enable
;//     <o0.9>     TIMER1_EN: Timer module timer1 clock enable
;//     <o0.8>     TIMER2_EN: Timer module timer2 clock enable
;//     <o0.7>     TIMERIF_EN: Timer module APB IF clock enable
;//     <o0.6>     PCLK_DIV1_SEL: Division ratio div1 (AHB/APB clock)
;//       <0=> 0             <1=> 1
;//       <i> div1 = 1 / (pclk_div1_sel + 1)
;//     <o0.2..5>  PCLK_DIV0_SEL: Division ratio div0 (ext memory clock) <0-15>
;//       <i> div0 = 1 / (pclk_div0_sel + 1)
;//     <o0.0..1>  PCLK_SEL: clkin select
;//       <0=> clk_main      <1=> plla_fout
;//       <2=> pllb_fout     <3=> fclk
;//   </h>

CGU_PERI_Val    EQU     0x0FFFFF0B

;//   <h> Audio Clock Controller Register (CGU_AUDIO)
;//     <o0.24>     I2SI_MCLK2PAD_EN: I2S audio input clock to PAD connection enable
;//     <o0.23>     I2SI_MCLK_EN: I2S audio input clock enable
;//     <o0.14..22> I2SI_MCLK_DIV_SEL: I2Sin audio IF clock division ratio <0-511>
;//       <i> div_i = 1 / (i2si_mclk_div_sel + 1)
;//     <o0.12..13> ISI_MCLK_SEL: I2SI_MCLK clkin select
;//       <0=> clk_main      <1=> plla_fout
;//       <2=> pllb_fout     <3=> reserved (clk_main)
;//     <o0.11>     I2SO_MCLK_EN: I2S audio output clock enable
;//     <o0.2..10>  I2SO_MCLK_DIV_SEL: I2Sout audio IF clock division ratio <0-511>
;//       <i> div_o = 1 / (i2so_mclk_div_sel + 1)
;//     <o0.0..1>   ISO_MCLK_SEL: I2SO_MCLK clkin select
;//       <0=> clk_main      <1=> plla_fout
;//       <2=> pllb_fout     <3=> reserved (clk_main)
;//   </h>

CGU_AUDIO_Val   EQU     0x00000000

;//   <h> USB Clock Controller Register (CGU_USB)
;//     <o0.5>      USB_CLK_EN: USB PHY clock enable (clk_usb)
;//     <o0.2..4>   USB_DIV_SEL: Division ratio <0-7>
;//       <i> 0: div = 1/1, > 0: div = 1/(2*n); (even division factors only)
;//     <o0.0..1>   USB_SEL: clkin select
;//       <0=> clk_main      <1=> plla_fout
;//       <2=> pllb_fout     <3=> reserved (clk_main)
;//   </h>

CGU_USB_Val     EQU     0x0000002D

;//   <h> IDE Clock Controller Register (CGU_IDE)
;//     <o0.7>      IDEIF_CLK_EN: IDE AHB IF clock enable
;//     <o0.6>      IDE_CLK_EN: IDE IF clock enable (90 MHz domain) (clk_ide)
;//     <o0.2..5>   IDE_DIV_SEL: Division ratio <0-7>
;//       <i> div = 1 / (ide_div_sel + 1)
;//     <o0.0..1>   IDE_SEL: clkin select (clk_ide)
;//       <0=> clk_main      <1=> plla_fout
;//       <2=> pllb_fout     <3=> reserved (clk_main)
;//   </h>

CGU_IDE_Val     EQU     0x00000000

;//   <h> MS Clock Controller Register (CGU_MS)
;//     <o0.8>      MSIF_CLK_EN: MS APB IF clock enable
;//     <o0.7>      MS_CLK_EN: MS IF clock enable (20/40 MHz domain) (clk_ms)
;//     <o0.2..6>   MS_DIV_SEL: Division ratio <0-7>
;//       <i> div = 1 / (ms_div_sel + 1)
;//     <o0.0..1>   MS_SEL: clkin select (clk_ms)
;//       <0=> clk_main      <1=> plla_fout
;//       <2=> pllb_fout     <3=> reserved (clk_main)
;//   </h>

CGU_MS_Val      EQU     0x00000000

;//   <h> DBOP Clock Controller Register (CGU_DBOP)
;//     <o0.3>      DBOP_EN: DBOP APB IF clock enable
;//     <o0.0..2>   DBOP_PREDIV_SEL: Division ratio <0-7>
;//       <i> div = 1 / (dbop_prediv_sel + 1)
;//   </h>

CGU_DBOP_Val    EQU     0x00000000

;// </e> Clock Setup


;----------------------- SDRAM Definitions -------------------------------------

; SDRAM Controller User Interface
EXTMEM_ITF_BASE EQU     0xC6030000      ; External Memory Interface Base Address
MPMCControl_OFS EQU     0x00            ; Mem Controller Control  Address Offset
MPMCConfig_OFS  EQU     0x08            ; Mem Controller Status   Address Offset
MPMCDyCntl_OFS  EQU     0x20            ; Dynamic Mem Control Reg Address Offset
MPMCDyRef_OFS   EQU     0x24            ; Dynamic Mem Refresh Reg Address Offset
MPMCDyRdCfg_OFS EQU     0x28            ; Dynamic Mem Read Config Address Offset
MPMCDytRP_OFS   EQU     0x30            ; Precharge Cmd Period    Address Offset
MPMCDytRAS_OFS  EQU     0x34            ; Active to Prchg Period  Address Offset
MPMCDytSREX_OFS EQU     0x38            ; Self-refresh Exit Time  Address Offset
MPMCDytAPR_OFS  EQU     0x3C            ; Last data out to Active Address Offset
MPMCDytDAL_OFS  EQU     0x40            ; Data-in to Active Cmd T Address Offset
MPMCDytWR_OFS   EQU     0x44            ; Write Recovery Time     Address Offset
MPMCDytRC_OFS   EQU     0x48            ; Act to Act Cmd Period   Address Offset
MPMCDytRFC_OFS  EQU     0x4C            ; Auto-refresh Period     Address Offset
MPMCDytXSR_OFS  EQU     0x50            ; Exit Selfref to Act Cmd Address Offset
MPMCDytRRD_OFS  EQU     0x54            ; Active bank A to B      Address Offset
MPMCDytMRD_OFS  EQU     0x58            ; Load Mode to Act Cmd    Address Offset
MPMCDyConfig0_OFS   EQU 0x100           ; Config Register         Address Offset
MPMCDyRasCas0_OFS   EQU 0x104           ; RAS and CAS Latencies   Address Offset

SDRAM_MODE_REG      EQU 0x30008C00      ; SDRAM Mode Register     Address
SDRAM_EXT_MODE_REG  EQU 0x30810000      ; SDRAM Extended Mode Reg Address

; Constants
NORMAL_CMD      EQU     (0x0 << 7)      ; NORMAL        Command
MODE_CMD        EQU     (0x1 << 7)      ; MODE          Command
PALL_CMD        EQU     (0x2 << 7)      ; Precharge All Command
NOP_CMD         EQU     (0x3 << 7)      ; NOP           Command
PERI_SDRAM_EN   EQU     (0x3 << 26)     ; Enable clock for EXTMEM and EXTMEMIF
REFSH_MODE      EQU     (0x1 << 2)      ; Self-refresh mode
BUF_ENABLE      EQU     (0x1 << 19)     ; Buffer enable

;// <e> SDRAM Controller Configuration
SDRAM_SETUP     EQU     0

;//   <h> Dynamic Memory Refresh Timer Register (MPMCDynamicRefresh)
;//     <o0.0..10>        REFRESH: Multiple of 16 clocks between SDRAM refresh cycles <0-2047>
;//   </h>
MPMCDyRef_Val   EQU     0x00000017

;//   <h> Dynamic Memory Read Configuration Register (MPMCDynamicReadConfig)
;//     <o0.0..1>             RD: SDRAM read data strategy
;//                   <0=> Using MPMCCLKOUT
;//                   <1=> Using MPMCCLKDELAY
;//                   <2=> Plus 1 clock cycle, using MPMCCLKDELAY
;//                   <3=> Plus 2 clock cycle, using MPMCCLKDELAY
;//   </h>
MPMCDyRdCfg_Val EQU     0x00000001

;//   <h> Dynamic Memory Precharge Command Period Register (MPMCDynamicRP)
;//     <o0.0..3>             tRP: Precharge command period <0-15>
;//                   <i>  (value + 1) clock cycles
;//   </h>
MPMCDytRP_Val   EQU     0x00000001

;//   <h> Dynamic Memory Active to Precharge Command Period Register (MPMCDynamicRAS)
;//     <o0.0..3>            tRAS: Active to Precharge command period <0-15>
;//                   <i>  (value + 1) clock cycles
;//   </h>
MPMCDytRAS_Val  EQU     0x00000003

;//   <h> Dynamic Memory Self-refresh Exit Time Register (MPMCDynamicSREX)
;//     <o0.0..3>           tSREX: Self-refresh exit time <0-15>
;//                   <i>  (value + 1) clock cycles
;//   </h>
MPMCDytSREX_Val EQU     0x00000006

;//   <h> Dynamic Memory Last Data Out to Active Time Register (MPMCDynamicAPR)
;//     <o0.0..3>           tAPR: Last data-out to active command time <0-15>
;//                   <i>  (value + 1) clock cycles
;//   </h>
MPMCDytAPR_Val  EQU     0x00000000

;//   <h> Dynamic Memory Data-in to Active Command Time Register (MPMCDynamicSREX)
;//     <o0.0..3>           tDAL: Data-in to active command time <0-15>
;//                   <i>  (value + 1) clock cycles
;//   </h>
MPMCDytDAL_Val  EQU     0x00000004

;//   <h> Dynamic Memory Write Recovery Time Register (MPMCDynamicWR)
;//     <o0.0..3>             tWR: Write recovery time <0-15>
;//                   <i>  (value + 1) clock cycles
;//   </h>
MPMCDytWR_Val   EQU     0x00000001

;//   <h> Dynamic Memory Active to Active Command Period Register (MPMCDynamicRC)
;//     <o0.0..4>             tRC: Active to active command <0-31>
;//                   <i>  (value + 1) clock cycles
;//   </h>
MPMCDytRC_Val   EQU     0x00000006

;//   <h> Dynamic Memory Auto-refresh Period Register (MPMCDynamicRFC)
;//     <o0.0..4>            tRFC: Auto-refresh period and auto-refresh to active command period <0-31>
;//                   <i>  (value + 1) clock cycles
;//   </h>
MPMCDytRFC_Val  EQU     0x00000006

;//   <h> Dynamic Memory Exit Self-refresh Register (MPMCDynamicXSR)
;//     <o0.0..4>            tXSR: Exit self-refresh to active command time <0-31>
;//                   <i>  (value + 1) clock cycles
;//   </h>
MPMCDytXSR_Val  EQU     0x00000006

;//   <h> Dynamic Memory Active Bank A to Active Bank B Time Register (MPMCDynamicRRD)
;//     <o0.0..3>            tRRD: Active bank A to active bank B latency <0-15>
;//                   <i>  (value + 1) clock cycles
;//   </h>
MPMCDytRRD_Val  EQU     0x00000001

;//   <h> Dynamic Memory Load Mode Register to Active Command Time (MPMCDynamicMRD)
;//     <o0.0..3>            tMRD: Load mode register to active command time <0-15>
;//                   <i>  (value + 1) clock cycles
;//   </h>
MPMCDytMRD_Val  EQU     0x00000001

;//   <h> Dynamic Memory Configuration Register (MPMCDynamicConfig0)
;//     <o0.20>                WP: Write Protect
;//                   <0=> Not protected
;//                   <1=> Protected
;//     <o0.14>                    Address Mapping - number of bits on external bus
;//                   <0=> 16-bit
;//                   <1=> 32-bit
;//     <o0.12>                    Address Mapping - power setting for external bus
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
;//     <o0.3..4>              MD: Memory device
;//                   <0=> SDRAM
;//                   <1=> Low-power SDRAM
;//                   <2=> Micron SyncFlash
;//                   <3=> Reserved
;//   </h>
MPMCDyConfig0_Val  EQU  0x00001488

;//   <h> Dynamic Memory RAS and CAS Delay Register (MPMCDynamicRasCas0)
;//     <o0.8..9>             CAS: CAS latency <1-3>
;//                   <i>  (value) clock cycles
;//     <o0.0..1>             RAS: RAS latency <1-3>
;//                   <i>  (value) clock cycles
;//   </h>
MPMCDyRasCas0_Val  EQU  0x00000202

;// </e> SDRAM Controller Configuration (SDRAMC)


;----------------------- Chip Control Unit Definitions ------------------------ 

CCU_BASE        EQU     0xC8100000      ; Chip Control Unit        Base Address        
CCU_SRC_OFS     EQU     0x00            ; Software Reset Control Reg     Offset
CCU_SRL_OFS     EQU     0x04            ; Software Reset Lock Register   Offset
CCU_MEMMAP_OFS  EQU     0x08            ; Memory Map Register            Offset
CCU_IO_OFS      EQU     0x0C            ; IO Configuration Register      Offset
CCU_SCON_OFS    EQU     0x10            ; System Configuration Register  Offset
CCU_VERS_OFS    EQU     0x14            ; Chip Version Register          Offset
CCU_SPARE1_OFS  EQU     0x18            ; Spare Register 1               Offset
CCU_SPARE2_OFS  EQU     0x1C            ; Spare Register 2               Offset

; Constants
REMAP_BIT       EQU     (1 << 0)        ; Remap bit value


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
                LDR     PC,IRQ_Addr
                LDR     PC,FIQ_Addr

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


; Clock Setup ------------------------------------------------------------------
                
                IF      (:DEF:CLOCK_INIT):LOR:(CLOCK_SETUP != 0)
                LDR     R0, =CGU_BASE

                IF      PLLA_SETUP != 0
                LDR     R1, =CGU_PLLASUP_Val
                STR     R1, [R0, #CGU_PLLASUP_OFS]
                LDR     R1, =CGU_COUNTA_Val
                STR     R1, [R0, #CGU_COUNTA_OFS]
                LDR     R1, =CGU_PLLA_Val
                STR     R1, [R0, #CGU_PLLA_OFS]
PLLA_Lock       LDR     R1, [R0, #CGU_INTCTRL_OFS]
                ANDS    R1, R1,  #PLLA_LOCK_Val
                BEQ     PLLA_Lock
                ENDIF

                IF      PLLB_SETUP != 0
                LDR     R1, =CGU_PLLBSUP_Val
                STR     R1, [R0, #CGU_PLLBSUP_OFS]
                LDR     R1, =CGU_COUNTB_Val
                STR     R1, [R0, #CGU_COUNTB_OFS]
                LDR     R1, =CGU_PLLB_Val
                STR     R1, [R0, #CGU_PLLB_OFS]
PLLB_Lock       LDR     R1, [R0, #CGU_INTCTRL_OFS]
                ANDS    R1, R1,  #PLLB_LOCK_Val
                BEQ     PLLB_Lock
                ENDIF

                LDR     R1, =CGU_PROC_Val
                STR     R1, [R0, #CGU_PROC_OFS]
                LDR     R1, =CGU_AUDIO_Val
                STR     R1, [R0, #CGU_AUDIO_OFS]
                LDR     R1, =CGU_USB_Val
                STR     R1, [R0, #CGU_USB_OFS]
                LDR     R1, =CGU_IDE_Val
                STR     R1, [R0, #CGU_IDE_OFS]
                LDR     R1, =CGU_MS_Val
                STR     R1, [R0, #CGU_MS_OFS]
                LDR     R1, =CGU_DBOP_Val
                STR     R1, [R0, #CGU_DBOP_OFS]
                LDR     R1, =CGU_PERI_Val
                STR     R1, [R0, #CGU_PERI_OFS]
                ENDIF   ; of IF      :DEF:CLOCK_INIT or CLOCK_SETUP != 0

; SDRAM Setup ------------------------------------------------------------------

                IF      (:DEF:SDRAM_INIT):LOR:(SDRAM_SETUP != 0)
                LDR     R0, =EXTMEM_ITF_BASE      ; Address of Ext Mem Interface
                LDR     R1, =CGU_BASE
                MOV     R5, #0

                LDR     R2, [R1, #CGU_PERI_OFS]   ; Enable clock
                ORR     R2, R2, #PERI_SDRAM_EN
                STR     R2, [R1, #CGU_PERI_OFS]

                MOV     R4, #0x01                 ; Enable SDRAM Controller
                STR     R4, [R0, #MPMCControl_OFS]

                LDR     R4, =NOP_CMD              ; Write NOP Command
                STR     R4, [R0, #MPMCDyCntl_OFS]
                LDR     R4, =PALL_CMD             ; Write Precharge All Command
                STR     R4, [R0, #MPMCDyCntl_OFS]
                MOV     R4, #MPMCDyRef_Val
                STR     R4, [R0, #MPMCDyRef_OFS]

                MOV     R4, #0x00                 ; SDRAM Controller CFG -> Set Little-Endian
                STR     R4, [R0, #MPMCConfig_OFS]

                LDR     R4, =MPMCDyRdCfg_Val
                STR     R4, [R0, #MPMCDyRdCfg_OFS]
                LDR     R4, =MPMCDytRP_Val
                STR     R4, [R0, #MPMCDytRP_OFS]
                LDR     R4, =MPMCDytRAS_Val
                STR     R4, [R0, #MPMCDytRAS_OFS]
                LDR     R4, =MPMCDytSREX_Val
                STR     R4, [R0, #MPMCDytSREX_OFS]
                LDR     R4, =MPMCDytAPR_Val
                STR     R4, [R0, #MPMCDytAPR_OFS]
                LDR     R4, =MPMCDytDAL_Val
                STR     R4, [R0, #MPMCDytDAL_OFS]
                LDR     R4, =MPMCDytWR_Val
                STR     R4, [R0, #MPMCDytWR_OFS]
                LDR     R4, =MPMCDytRC_Val
                STR     R4, [R0, #MPMCDytRC_OFS]
                LDR     R4, =MPMCDytRFC_Val
                STR     R4, [R0, #MPMCDytRFC_OFS]
                LDR     R4, =MPMCDytXSR_Val
                STR     R4, [R0, #MPMCDytXSR_OFS]
                LDR     R4, =MPMCDytRRD_Val
                STR     R4, [R0, #MPMCDytRRD_OFS]
                LDR     R4, =MPMCDytMRD_Val
                STR     R4, [R0, #MPMCDytMRD_OFS]

                LDR     R4, =MPMCDyRasCas0_Val
                STR     R4, [R0, #MPMCDyRasCas0_OFS]
                LDR     R4, =MPMCDyConfig0_Val
                STR     R4, [R0, #MPMCDyConfig0_OFS]

                LDR     R4, =MODE_CMD             ; Write MODE Command
                STR     R4, [R0, #MPMCDyCntl_OFS]

                LDR     R4, =SDRAM_MODE_REG       ; Load Mode Register
                LDR     R4, [R4, #0]

                LDR     R4, =SDRAM_EXT_MODE_REG   ; Load Extended Mode Register
                LDR     R4, [R4, #0]

                LDR     R4, =NORMAL_CMD           ; Write NORMAL Command
                STR     R4, [R0, #MPMCDyCntl_OFS]

                LDR     R4, =(MPMCDyConfig0_Val:OR:BUF_ENABLE)  ; Enable buffer
                STR     R4, [R0, #MPMCDyConfig0_OFS]
                ENDIF   ; of IF      :DEF:SDRAM_INIT or SDRAM_SETUP != 0

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
                LDR     R0, =CCU_BASE
                MOV     R1, #REMAP_BIT  ; Remap RAM to 0
                STR     R1, [R0, #CCU_MEMMAP_OFS] ; Execute Remap
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
