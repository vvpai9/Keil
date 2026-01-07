/******************************************************************************

     Copyright (C) 2005 Oki Electric Industry Co.,LTD.

     System Name  :  ML69Q6203 CPU Board
     Module Name  :  definition for registers
     File   Name  :  ML69Q6203.h
     Revision     :  01.00
     Date         :  2005/03/03      First version

******************************************************************************/
#ifndef ML69Q6203_H
#define ML69Q6203_H

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************/
/*    system control register                        */
/*****************************************************/
#define SCR_BASE        (0xB8000000)    /* base address */
#define IDR             (SCR_BASE+0x00) /* type and revision (RO,32,0x00000100) */
#define CLKSTP          (SCR_BASE+0x04) /* clock stop register (W,32,0x00000000) */
#define CGBCNT0         (SCR_BASE+0x08) /* clock(CGB) control register 0 (RW,32,0x00000000) */
#define CKWT            (SCR_BASE+0x0C) /* clock wait register (RW,32,0x000000FF) */
#define RMPCON          (SCR_BASE+0x10) /* remap control register (RW,32,0x00000000) */
#define CGBCNT1         (SCR_BASE+0x18) /* clock(CGB) control register 1 (RW,32,0x00000000) */
#define CGBCNT2         (SCR_BASE+0x1C) /* clock(CGB) control register 2 (RW,32,0x00000000) */

/* for IDR, CLKSTP, CGBCNT0, CKWT, RMPCON, CGBCNT1, CGBCNT2 registers */
#define SCR_UNLOCK      0x0000003c

/* bit field of CLKSTP register */
#define CLKSTP_SIO      (0x00000001)    /* SIO HALT */
#define CLKSTP_TIC      (0x00000002)    /* TIC HALT */
#define CLKSTP_HALT     (0x00000004)    /* CPU group HALT */
#define CLKSTP_STOP     (0x00000080)    /* STOPMODE */

/* bit field of CGBCNT0 register */
#define CGBCNT0_FCLKGEAR1   (0x00000000) /* CPUCLK  1 dividing : 120    MHz */
#define CGBCNT0_FCLKGEAR2   (0x00000001) /* CPUCLK  2 dividing :  60    MHz */
#define CGBCNT0_FCLKGEAR4   (0x00000002) /* CPUCLK  4 dividing :  30    MHz */
#define CGBCNT0_FCLKGEAR8   (0x00000003) /* CPUCLK  8 dividing :  15    MHz */
#define CGBCNT0_FCLKGEAR16  (0x00000004) /* CPUCLK 16 dividing :   7.5  MHz */
#define CGBCNT0_FCLKGEAR32  (0x00000005) /* CPUCLK 32 dividing :   3.75 MHz */
#define CGBCNT0_FCLKGEAR32K (0x00000007) /* CPUCLK                32    kHz */

/* bit field of CGBCNT0 register */
#define CGBCNT0_HCLKGEAR1   (0x00000000) /* CPUCLK/1 dividing : 120 MHz */
#define CGBCNT0_HCLKGEAR2   (0x00000008) /* CPUCLK/1 dividing : 120 MHz */
#define CGBCNT0_HCLKGEAR4   (0x00000080) /* CPUCLK/2 dividing :  60 MHz */
#define CGBCNT0_HCLKGEAR8   (0x00000088) /* CPUCLK/4 dividing :  30 MHz */

/* bit field of CGBCNT0 register */
#define CGBCNT0_CCLKGEAR1   (0x00000000) /* CPUCLK/1 dividing : 120    MHz */
#define CGBCNT0_CCLKGEAR32K (0x00000070) /* CPUCLK               32    kHz */

/* bit field of RMPCON register */
#define RMPCON_ENABLE   (0x00000008)    /* remap enabled */
#define RMPCON_DISABLE  (0x00000000)    /* remap disabled */
#define RMPCON_EXT      (0x00000000)    /* device space is external SRAM */
#define RMPCON_DRAM     (0x00000001)    /* device space is external SDRAM */
#define RMPCON_AHB      (0x00000002)    /* device space is AHBRAM*/

/*****************************************************************************
    CONFIG
*****************************************************************************/
#define CNFIG_BAS   0x80000000
#define PDMASK      (CNFIG_BAS+(0x00))  /* power down mask register (RW,32,0x00000000) */
#define MCKST       (CNFIG_BAS+(0x04))  /* dodule clock stop register (RW,32,0x00000000) */
#define PIOCTL      (CNFIG_BAS+(0x08))  /* chabge PIO function register (RW,32,0x00000000) */
#define I2SCNTL     (CNFIG_BAS+(0x0C))  /* I2S control register (RW,32,0x00000000) */
#define OCONFIG     (CNFIG_BAS+(0x10))  /* other configuration register (RW,32,0x00000000) */
#define TST         (CNFIG_BAS+(0x14))  /* ATD test register (RW,32,0x00000000) */

/* for MCKST, PIOCTL, I2SCNTL, OCONFIG, TST registers */
#define CNFIG_UNLOCK    0x0000003c

/* bit field of PDMASK */
#define PDMASK_PDMASK_EN  (0x0000)      /* power cut without RTC disable */
#define PDMASK_PDMASK_DIS (0x0001)      /* power cut without RTC disable */
    /* these are aliases */
#define PDMASK_RTC_DIS    (0x0000)      /* RTC disabled, can powerdown */
#define PDMASK_RTC_EN     (0x0001)      /* RTC enabled, can NOT powerdown */

/* bit field of MCKST */
#define MCKST_DMAC_EN     (0x0000)      /* supply DMAC clock to enable */
#define MCKST_DMAC_DIS    (0x0001)      /* supply DMAC clock to disable */
#define MCKST_DRAMC_EN    (0x0000)      /* supply DRAMC clock to enable */
#define MCKST_DRAMC_DIS   (0x0002)      /* supply DRAMC clock to disable */
#define MCKST_I2SSEND_EN  (0x0000)      /* supply I2S send clock enable */
#define MCKST_I2SSEND_DIS (0x0004)      /* supply I2S send clock disable */
#define MCKST_I2SSRCV_EN  (0x0000)      /* supply I2S receive clock enable */
#define MCKST_I2SSRCV_DIS (0x0008)      /* supply I2S receive clock disable */
#define MCKST_NFC_EN      (0x0000)      /* supply clock to NAND FLASH controller enable */
#define MCKST_NFC_DIS     (0x0010)      /* supply clock to NAND FLASH controller disable */
#define MCKST_NFB_EN      (0x0000)      /* supply clock to NAND FLASH Buffer memory enable */
#define MCKST_NFB_DIS     (0x0020)      /* supply clock to NAND FLASH Buffer memory disable */
#define MCKST_XSYSCLK_DIS (0x0000)      /* supply clock to XSYSCLK disable */
#define MCKST_XSYSCLK_EN  (0x0040)      /* supply clock to XSYSCLK enable */

/*****************************************************/
/*    interrupt control register                     */
/*****************************************************/
#define ICR_BASE    (0x78000000)        /* base address of interrupt control register */
#define IRQ         (ICR_BASE+0x00)     /* IRQ register (R,32,0x00000000) */
#define IRQS        (ICR_BASE+0x04)     /* IRQ soft register (RW,32,0x00000000) */
#define FIQ         (ICR_BASE+0x08)     /* FIQ register (R,32,0x00000000) */
#define FIQRAW      (ICR_BASE+0x0C)     /* FIQRAW status register (R,32,--)*/
#define FIQEN       (ICR_BASE+0x10)     /* FIQ enable register (RW,32,0x00000000)*/
#define IRN         (ICR_BASE+0x14)     /* IRQ number register (R,32,0x00000000)*/
#define CIL         (ICR_BASE+0x18)     /* current IRQ level register (RW,32,0x00000000)*/
#define ILC0        (ICR_BASE+0x20)     /* IRQ level control register 0 (RW,32,0x00000000) */
#define ILC1        (ICR_BASE+0x24)     /* IRQ level control register 1 (RW,32,0x00000000) */
#define CILCL       (ICR_BASE+0x28)     /* current IRQ level clear register (W,32,--) */
#define CILE        (ICR_BASE+0x2C)     /* current IRQ level encode register (R,32,0x00000000) */

#define EIC_BASE    (0x7BF00000)        /* base address */
#define IRCL        (EIC_BASE+0x04)     /* Extended interrupt Clear register (W,32,--) */
#define IRQA        (EIC_BASE+0x10)     /* Extended interrupt IRQ register (RW,32,0x00000000) */
#define IDM         (EIC_BASE+0x14)     /* Extended interrupt Mode control register (RW,32,0x00000000) */
#define ILC         (EIC_BASE+0x18)     /* Extended interrupt IRQ Level control register (RW,32,0x00000000) */

/* bit field of IRQ register */
#define IRQ_nIR0        (0x00000001)    /* nIR[0] */
#define IRQ_nIR1        (0x00000002)    /* nIR[1] */
#define IRQ_nIR2        (0x00000004)    /* nIR[2] */
#define IRQ_nIR3        (0x00000008)    /* nIR[3] */
#define IRQ_nIR4        (0x00000010)    /* nIR[4] */
#define IRQ_nIR5        (0x00000020)    /* nIR[5] */
#define IRQ_nIR6        (0x00000040)    /* nIR[6] */
#define IRQ_nIR7        (0x00000080)    /* nIR[7] */
#define IRQ_nIR8        (0x00000100)    /* nIR[8] */
#define IRQ_nIR9        (0x00000200)    /* nIR[9] */
#define IRQ_nIR10       (0x00000400)    /* nIR[10] */
#define IRQ_nIR11       (0x00000800)    /* nIR[11] */
#define IRQ_nIR12       (0x00001000)    /* nIR[12] */
#define IRQ_nIR13       (0x00002000)    /* nIR[13] */
#define IRQ_nIR14       (0x00004000)    /* nIR[14] */
#define IRQ_nIR15       (0x00008000)    /* nIR[15] */

/* bit field of IRQS register */
#define IRQS_IRQS       (0x00000002)    /* IRQS bit */

/* bit field of FIQ register */
#define FIQ_FIQ         (0x00000001)    /* FIQ bit */

/* bit field of FIQRAW register */
#define FIQRAW_FIQRAW   (0x00000001)    /* FIQRAW bit */

/* bit field of FIQEN register */
#define FIQEN_FIQEN     (0x00000001)    /* FIQEN bit */

/* bit field of IRN register */
#define IRN_IRN         (0x0000007F)    /* IRN[6:0] */

/* bit field of CIL register */
#define CIL_INT_LV1     (0x00000002)    /* interrupt level 1 */
#define CIL_INT_LV2     (0x00000004)    /* interrupt level 2 */
#define CIL_INT_LV3     (0x00000008)    /* interrupt level 3 */
#define CIL_INT_LV4     (0x00000010)    /* interrupt level 4 */
#define CIL_INT_LV5     (0x00000020)    /* interrupt level 5 */
#define CIL_INT_LV6     (0x00000040)    /* interrupt level 6 */
#define CIL_INT_LV7     (0x00000080)    /* interrupt level 7 */

/* bit field of ILC0 register */
#define ILC0_ILR0       (0x00000007)    /* nIR[0] */
#define ILC0_ILR1       (0x00000070)    /* nIR[1],nIR[2],nIR[3] */
#define ILC0_ILR4       (0x00070000)    /* nIR[4],nIR[5] */
#define ILC0_ILR6       (0x07000000)    /* nIR[6],nIR[7] */
#define ILC0_INT_LV1    (0x11111111)    /* interrupt level 1 */
#define ILC0_INT_LV2    (0x22222222)    /* interrupt level 2 */
#define ILC0_INT_LV3    (0x33333333)    /* interrupt level 3 */
#define ILC0_INT_LV4    (0x44444444)    /* interrupt level 4 */
#define ILC0_INT_LV5    (0x55555555)    /* interrupt level 5 */
#define ILC0_INT_LV6    (0x66666666)    /* interrupt level 6 */
#define ILC0_INT_LV7    (0x77777777)    /* interrupt level 7 */

/* bit field of ILC1 register */
#define ILC1_ILR8       (0x00000007)    /* nIR[8] */
#define ILC1_ILR9       (0x00000070)    /* nIR[9] */
#define ILC1_ILR10      (0x00000700)    /* nIR[10] */
#define ILC1_ILR11      (0x00007000)    /* nIR[11] */
#define ILC1_ILR12      (0x00070000)    /* nIR[12] */
#define ILC1_ILR13      (0x00700000)    /* nIR[13] */
#define ILC1_ILR14      (0x07000000)    /* nIR[14] */
#define ILC1_ILR15      (0x70000000)    /* nIR[15] */
#define ILC1_INT_LV1    (0x11111111)    /* interrupt level 1 */
#define ILC1_INT_LV2    (0x22222222)    /* interrupt level 2 */
#define ILC1_INT_LV3    (0x33333333)    /* interrupt level 3 */
#define ILC1_INT_LV4    (0x44444444)    /* interrupt level 4 */
#define ILC1_INT_LV5    (0x55555555)    /* interrupt level 5 */
#define ILC1_INT_LV6    (0x66666666)    /* interrupt level 6 */
#define ILC1_INT_LV7    (0x77777777)    /* interrupt level 7 */

/* bit field of CILCL register */
#define CILCL_CLEAR (0x00000001)    /* most significant '1' bit of CIL is cleared */

/* bit field of CILE register */
#define CILE_CILE   (0x00000007)    /* CILE[2:0] */

/* bit field of IRCL register */
#define IRCL_IRCL   (0x0000007F)        /* IRCL[6:0] */

/* bit field of IRQA register */
#define IRQA_IRQ16  (0x00000001)        /* IRQ16 */
#define IRQA_IRQ17  (0x00000002)        /* IRQ17 */
#define IRQA_IRQ18  (0x00000004)        /* IRQ18 */
#define IRQA_IRQ19  (0x00000008)        /* IRQ19 */
#define IRQA_IRQ20  (0x00000010)        /* IRQ20 */
#define IRQA_IRQ21  (0x00000020)        /* IRQ21 */
#define IRQA_IRQ22  (0x00000040)        /* IRQ22 */
#define IRQA_IRQ23  (0x00000080)        /* IRQ23 */
#define IRQA_IRQ24  (0x00000100)        /* IRQ24 */
#define IRQA_IRQ25  (0x00000200)        /* IRQ25 */
#define IRQA_IRQ26  (0x00000400)        /* IRQ26 */
#define IRQA_IRQ27  (0x00000800)        /* IRQ27 */
#define IRQA_IRQ28  (0x00001000)        /* IRQ28 */
#define IRQA_IRQ29  (0x00002000)        /* IRQ29 */
#define IRQA_IRQ30  (0x00004000)        /* IRQ30 */
#define IRQA_IRQ31  (0x00008000)        /* IRQ31 */

/* bit field of IDM register */
#define IDM_IDM22   (0x00000040)        /* IRQ22 */
#define IDM_IDM26   (0x00000400)        /* IRQ26 */
#define IDM_IDM28   (0x00001000)        /* IRQ28 */
#define IDM_IDM30   (0x00004000)        /* IRQ31 */
#define IDM_IDMP22  (0x00000080)        /* IRQ22 */
#define IDM_IDMP26  (0x00000800)        /* IRQ26 */
#define IDM_IDMP28  (0x00002000)        /* IRQ28 */
#define IDM_IDMP30  (0x00008000)        /* IRQ31 */
#define IDM_INT_L_L (0x00000000)        /* level sensing, interrupt occurs when 'L' */
#define IDM_INT_L_H (0x0000AAAA)        /* level sensing, interrupt occurs when 'H' */
#define IDM_INT_E_F (0x00005555)        /* edge sensing, interrupt occurs when falling edge */
#define IDM_INT_E_R (0x0000FFFF)        /* edge sensing, interrupt occurs when rising edge */
#define IDM_IRQ22   (0x000000C0)        /* IRQ22 */
#define IDM_IRQ26   (0x00000C00)        /* IRQ26 */
#define IDM_IRQ28   (0x00003000)        /* IRQ28 */
#define IDM_IRQ31   (0x0000C000)        /* IRQ31 */


/* bit field of ILC register */
#define ILC_ILC16   (0x00000007)        /* IRQ16, IRQ17 */
#define ILC_ILC18   (0x00000070)        /* IRQ18, IRQ19 */
#define ILC_ILC20   (0x00000700)        /* IRQ20, IRQ21 */
#define ILC_ILC22   (0x00007000)        /* IRQ22, IRQ23 */
#define ILC_ILC24   (0x00070000)        /* IRQ24, IRQ25 */
#define ILC_ILC26   (0x00700000)        /* IRQ26, IRQ27 */
#define ILC_ILC28   (0x07000000)        /* IRQ28, IRQ29 */
#define ILC_ILC30   (0x70000000)        /* IRQ30, IRQ31 */
#define ILC_INT_LV1 (0x11111111)        /* interrupt level 1 */
#define ILC_INT_LV2 (0x22222222)        /* interrupt level 2 */
#define ILC_INT_LV3 (0x33333333)        /* interrupt level 3 */
#define ILC_INT_LV4 (0x44444444)        /* interrupt level 4 */
#define ILC_INT_LV5 (0x55555555)        /* interrupt level 5 */
#define ILC_INT_LV6 (0x66666666)        /* interrupt level 6 */
#define ILC_INT_LV7 (0x77777777)        /* interrupt level 7 */

/*****************************************************/
/*    external memory control register               */
/*****************************************************/
#define EMCR_BASE   (0x78100000)        /* base address */
#define BWC         (EMCR_BASE+0x00)    /* bus width control register (RW,32,0x00000008) */
#define ROMAC       (EMCR_BASE+0x04)    /* external ROM access control register (RW,32,0x00000007) */
#define RAMAC       (EMCR_BASE+0x08)    /* external SRAM access control register (RW,32,0x00000007) */
#define IO0AC       (EMCR_BASE+0x0C)    /* external IO0 access control register (RW,32,0x00000007) */
#define IO1AC       (EMCR_BASE+0x10)    /* external IO1 access control register (RW,32,0x00000007) */

/* bit field of BWC register */
#define BWC_ROMBW0  (0x00000000)        /* ROM disable */
#define BWC_ROMBW16 (0x00000008)        /* ROM 16bit */
#define BWC_RAMBW0  (0x00000000)        /* RAM disable */
#define BWC_RAMBW16 (0x00000020)        /* RAM 16bit */
#define BWC_IO0BW0  (0x00000000)        /* IO0 disable */
#define BWC_IO0BW8  (0x00000040)        /* IO0 8bit */
#define BWC_IO0BW16 (0x00000080)        /* IO0 16 bit */
#define BWC_IO1BW0  (0x00000000)        /* IO1 disable */
#define BWC_IO1BW8  (0x00000100)        /* IO1 8bit */
#define BWC_IO1BW16 (0x00000200)        /* IO1 16bit */

/* bit field of ROMAC register */
#define ROMAC_ROMTYPE   (0x00000007)    /* ROMTYPE[2:0] */

/* bit field of RAMAC register */
#define RAMAC_RAMTYPE   (0x00000007)    /* RAMTYPE[2:0] */

/* bit field of IO0AC register */
#define IO0AC_IO0TYPE   (0x00000007)    /* IO0TYPE[2:0] */

/* bit field of IO1AC register */
#define IO1AC_IO1TYPE   (0x00000007)    /* IO1TYPE[2:0] */


/*****************************************************/
/*    DRAM control register                          */
/*****************************************************/
#define DCR_BASE    (0x78180000)        /* base address */
#define DBWC        (DCR_BASE+0x00)     /* DRAM Bus Width control register (RW,32,0x00000000) */
#define DRMC        (DCR_BASE+0x04)     /* DRAM control register (RW,32,0x00000000) */
#define DRPC        (DCR_BASE+0x08)     /* DRAM Attribute parameter Setup register (RW,32,0x00000000)*/
#define SDMD        (DCR_BASE+0x0C)     /* SDRAM Mode Setup register (RW,32,0x00000001) */
#define DCMD        (DCR_BASE+0x10)     /* DRAM Command register (RW,32,0x00000000) */
#define RFSH0       (DCR_BASE+0x14)     /* DRAM Refresh Cycle register 0 (RW,32,0x00000000) */
#define PDWC        (DCR_BASE+0x18)     /* Power Down Mode control register (RW,32,0x00000003) */
#define RFSH1       (DCR_BASE+0x1C)     /* DRAM Refresh Cycle register 1 (RW,32,0x00000000) */

/* bit field of DBWC register */
#define DBWC_DBDRAM0    (0x00000000)    /* DRAM disable */
#define DBWC_DBDRAM8    (0x00000001)    /* 8bit width */
#define DBWC_DBDRAM16   (0x00000002)    /* 16bit width */

/* bit field of DRMC register */
#define DRMC_8bit       (0x00000000)    /* DRAM column length : 8bit */
#define DRMC_9bit       (0x00000001)    /* DRAM column length : 9bit */
#define DRMC_10bit      (0x00000002)    /* DRAM column length : 10bit */
#define DRMC_SDRAM      (0x00000000)    /* DRAM architecture : SDRAM */
#define DRMC_EDO        (0x00000004)    /* DRAM architecture : EDO-DRAM */
#define DRMC_2CLK       (0x00000000)    /* SDRAM pre-charge latency : 2clock */
#define DRMC_CAS        (0x00000010)    /* SDRAM pre-charge latency : same as CAS latency */
#define DRMC_PD_DIS     (0x00000000)    /* automatic shift to SDRAM power down mode : disable */
#define DRMC_PD_EN      (0x00000040)    /* automatic shift to SDRAM power down mode : enable */
#define DRMC_CBR_STOP   (0x00000000)    /* CBR refresh : stop */
#define DRMC_CBR_EXE    (0x00000080)    /* CBR refresh : execution */

/* bit field of DRPC register */
#define DRPC_DRAMSPEC   (0x0000000F)    /* DRAMSPEC[3:0] */

/* bit field of SDMD register */
#define SDMD_CL2    (0x00000000)        /* SDRAM CAS latency : 2 */
#define SDMD_CL3    (0x00000001)        /* SDRAM CAS latency : 3 */
#define SDMD_MODEWR (0x00000080)        /* setting operation : valid */

/* bit field of DCMD register */
#define DCMD_S_NOP      (0x00000000)    /* No operation */
#define DCMD_S_PALL     (0x00000004)    /* SDRAM all bank pre-charge command */
#define DCMD_S_REF      (0x00000005)    /* SDRAM CBR refresh command */
#define DCMD_S_SELF     (0x00000006)    /* SDRAM self refresh start command */
#define DCMD_S_SREX     (0x00000007)    /* SDRAM self refresh stop command */
#define DCMD_EDO_NOP    (0x00000000)    /* No operation */
#define DCMD_EDO_PC     (0x00000004)    /* EDO-DRAM pre-charge cycle */
#define DCMD_EDO_REF    (0x00000005)    /* EDO-DRAM CBR refresh cycle */
#define DCMD_EDO_SELF   (0x00000006)    /* EDO-DRAM self refresh start cycle */
#define DCMD_EDO_SREX   (0x00000007)    /* EDO-DRAM self refresh stop cycle */

/* bit field of RFSH0 register */
#define RFSH0_RCCON  (0x00000001)       /* RCCON bit, refresh frequency = refclk(RFSH1)*2(RCCON=0) */
#define RFSH0_SINGLE (0x00000000)       /* RCCON bit, refresh frequency = refclk(RFSH1)  (RCCON=1) */
/* bit field of RFSH1 register */
#define RFSH1_RFSEL1    (0x000007FF)    /* RFSEL1[10:0], refckl(RFSH1) = CCLK/RFSEL1[10:0] */

/* bit field of PDWC register */
#define PDWC_1  (0x00000000)            /* when  1 or more cycles of idol state continue,
                                           it shifts to power down mode. */
#define PDWC_2  (0x00000001)            /*                   :                   */
#define PDWC_3  (0x00000002)            /*                   :                   */
#define PDWC_4  (0x00000003)            /*                   :                   */
#define PDWC_5  (0x00000004)            /*                   :                   */
#define PDWC_6  (0x00000005)            /*                   :                   */
#define PDWC_7  (0x00000006)            /*                   :                   */
#define PDWC_8  (0x00000007)            /*                   :                   */
#define PDWC_9  (0x00000008)            /*                   :                   */
#define PDWC_10 (0x00000009)            /*                   :                   */
#define PDWC_11 (0x0000000A)            /*                   :                   */
#define PDWC_12 (0x0000000B)            /*                   :                   */
#define PDWC_13 (0x0000000C)            /*                   :                   */
#define PDWC_14 (0x0000000D)            /*                   :                   */
#define PDWC_15 (0x0000000E)            /*                   :                   */
#define PDWC_16 (0x0000000F)            /* when 16 or more cycles of idol state continue,
                                           it shifts to power down mode. */

/*****************************************************/
/*    DMA control register                           */
/*****************************************************/
#define DMA_BASE    (0x7BE00000)        /* base address */
#define DMAMOD      (DMA_BASE+0x0000)   /* DMA Mode register (RW,32,0x00000000) */
#define DMASTA      (DMA_BASE+0x0004)   /* DMA Status register (R,32,0x00000000) */
#define DMAINT      (DMA_BASE+0x0008)   /* DMA interrupt Status register (R,32,0x00000000) */
#define DMACMSK0    (DMA_BASE+0x0100)   /* Channel 0 Mask register (RW,32,0x00000001) */
#define DMACTMOD0   (DMA_BASE+0x0104)   /* Channel 0 Transfer Mode register (RW,32,0x00000040) */
#define DMACSAD0    (DMA_BASE+0x0108)   /* Channel 0 Source Address register (RW,32,0x00000000) */
#define DMACDAD0    (DMA_BASE+0x010C)   /* Channel 0 Destination Address register (RW,32,0x00000000) */
#define DMACSIZ0    (DMA_BASE+0x0110)   /* Channel 0 Transfer Size register (RW,32,0x00000000) */
#define DMACCINT0   (DMA_BASE+0x0114)   /* Channel 0 interrupt Clear register (W,32,--) */
#define DMACMSK1    (DMA_BASE+0x0200)   /* Channel 1 Mask register (RW,32,0x00000001) */
#define DMACTMOD1   (DMA_BASE+0x0204)   /* Channel 1 Transfer Mode register (RW,32,0x00000040) */
#define DMACSAD1    (DMA_BASE+0x0208)   /* Channel 1 Source Address register (RW,32,0x00000000) */
#define DMACDAD1    (DMA_BASE+0x020C)   /* Channel 1 Destination Address register (RW,32,0x00000000) */
#define DMACSIZ1    (DMA_BASE+0x0210)   /* Channel 1 Transfer Size register (RW,32,0x00000000) */
#define DMACCINT1   (DMA_BASE+0x0214)   /* Channel 1 interrupt Clear register (W,32,--) */
#define DMACMSK2    (DMA_BASE+0x0300)   /* Channel 2 Mask register (RW,32,0x00000001) */
#define DMACTMOD2   (DMA_BASE+0x0304)   /* Channel 2 Transfer Mode register (RW,32,0x00000040) */
#define DMACSAD2    (DMA_BASE+0x0308)   /* Channel 2 Source Address register (RW,32,0x00000000) */
#define DMACDAD2    (DMA_BASE+0x030C)   /* Channel 2 Destination Address register (RW,32,0x00000000) */
#define DMACSIZ2    (DMA_BASE+0x0310)   /* Channel 2 Transfer Size register (RW,32,0x00000000) */
#define DMACCINT2   (DMA_BASE+0x0314)   /* Channel 2 interrupt Clear register (W,32,--) */
#define DMACMSK3    (DMA_BASE+0x0400)   /* Channel 3 Mask register (RW,32,0x00000001) */
#define DMACTMOD3   (DMA_BASE+0x0404)   /* Channel 3 Transfer Mode register (RW,32,0x00000040) */
#define DMACSAD3    (DMA_BASE+0x0408)   /* Channel 3 Source Address register (RW,32,0x00000000) */
#define DMACDAD3    (DMA_BASE+0x040C)   /* Channel 3 Destination Address register (RW,32,0x00000000) */
#define DMACSIZ3    (DMA_BASE+0x0410)   /* Channel 3 Transfer Size register (RW,32,0x00000000) */
#define DMACCINT3   (DMA_BASE+0x0414)   /* Channel 3 interrupt Clear register (W,32,--) */

/* bit field of DMAMOD register */
#define DMAMOD_PRI  (0x00000001)        /* PRI bit */
#define DMAMOD_FIX  (0x00000000)        /* Priority of DMA channel : CH0 > CH1 */
#define DMAMOD_RR   (0x00000001)        /* Priority of DMA channel : Round robin */

/* bit field of DMASTA register */
#define DMASTA_STA0 (0x00000001)        /* Non-transmitted data is in CH0 */
#define DMASTA_STA1 (0x00000002)        /* Non-transmitted data is in CH1 */

/* bit field of DMAINT register */
#define DMAINT_IREQ0    (0x00000001)    /* CH0 interrupt */
#define DMAINT_IREQ1    (0x00000002)    /* CH1 interrupt */
#define DMAINT_ISTA0    (0x00000100)    /* CH0 abnormal end */
#define DMAINT_ISTA1    (0x00000200)    /* CH1 abnormal end */
#define DMAINT_ISTP0    (0x00010000)    /* CH0 abnormal end situation */
#define DMAINT_ISTP1    (0x00020000)    /* CH1 abnormal end situation */

/* bit field of DMAMSK0,1 register */
#define DMACMSK_MSK (0x00000001)        /* Mask */

/* bit field of DMATMOD0,1 register */
#define DMACTMOD_ARQ    (0x00000001)    /* Auto request */
#define DMACTMOD_ERQ    (0x00000000)    /* External request */
#define DMACTMOD_BYTE   (0x00000000)    /* Byte transmission */
#define DMACTMOD_HWORD  (0x00000002)    /* Half word transmission */
#define DMACTMOD_WORD   (0x00000004)    /* Word transmission */
#define DMACTMOD_SFA    (0x00000000)    /* Source data type(fixed address device) */
#define DMACTMOD_SIA    (0x00000008)    /* Source data type(incremental address device) */
#define DMACTMOD_DFA    (0x00000000)    /* Destination data type(fixed address device) */
#define DMACTMOD_DIA    (0x00000010)    /* Destination data type(incremental address device) */
#define DMACTMOD_BM     (0x00000000)    /* Bus request mode(burst mode) */
#define DMACTMOD_CSM    (0x00000020)    /* Bus request mode(cycle steal mode) */
#define DMACTMOD_IMK    (0x00000040)    /* interrupt mask */

/*****************************************************/
/*    port control register                           */
/*****************************************************/
#define PCR_BASE    (0xB7A00000)        /* base address */
#define GPPOA       (PCR_BASE+0x00)     /* port A output register (RW,16,--) */
#define GPPIA       (PCR_BASE+0x04)     /* port A input register (R,16,--)*/
#define GPPMA       (PCR_BASE+0x08)     /* port A Mode register (RW,16,0x0000) */

#define GPPOB       (PCR_BASE+0x20)     /* port B Output register (RW,16,--) */
#define GPPIB       (PCR_BASE+0x24)     /* port B Input register (R,16,--) */
#define GPPMB       (PCR_BASE+0x28)     /* port B Mode register (RW,16,0x0000) */

#define GPPOC       (PCR_BASE+0x40)     /* port C Output register (RW,16,--) */
#define GPPIC       (PCR_BASE+0x44)     /* port C Input register (R,16,--) */
#define GPPMC       (PCR_BASE+0x48)     /* port C Mode register (RW,16,0x0000) */

#define GPPOD       (PCR_BASE+0x60)     /* port D Output register (RW,16,--) */
#define GPPID       (PCR_BASE+0x64)     /* port D Input register (R,16,--) */
#define GPPMD       (PCR_BASE+0x68)     /* port D Mode register (RW,16,0x0000) */

#define GPPOE       (PCR_BASE+0x80)     /* port E Output register (RW,16,--) */
#define GPPIE       (PCR_BASE+0x84)     /* port E Input register (R,16,--) */
#define GPPME       (PCR_BASE+0x88)     /* port E Mode register (RW,16,0x0000) */
#define GPIEE       (PCR_BASE+0x8C)     /* port E interrupt enable (RW,16,0x0000) */
#define GPIPE       (PCR_BASE+0x90)     /* port E interrupt Polarity (RW,16,0x0000) */
#define GPISE       (PCR_BASE+0x94)     /* port E interrupt Status (RW,16,0x0000) */
#define GPIME       (PCR_BASE+0x98)     /* port E interrupt Mode register (RW,16,0x0000) */

#define GPPOF       (PCR_BASE+0xA0)     /* port D Output register (RW,7,--) */
#define GPPIF       (PCR_BASE+0xA4)     /* port D Input register (R,7,--) */
#define GPPMF       (PCR_BASE+0xA8)     /* port D Mode register (RW,7,0x0000) */

/* bit field of GPPOA/GPPOB/GPPOC/GPPOD/GPPOE register */
#define GPPOA_GPPOA (0xFFFF)            /* GPPOA[15:0] */
#define GPPOB_GPPOB (0xFFFF)            /* GPPOB[15:0] */
#define GPPOC_GPPOC (0xFFFF)            /* GPPOC[15:0] */
#define GPPOD_GPPOD (0xFFFF)            /* GPPOD[15:0] */
#define GPPOE_GPPOE (0xFFFF)            /* GPPOE[15:0] */
#define GPPOF_GPPOF (0x007F)            /* GPPOF[ 6:0] */

/* bit field of GPPIA/GPPIB/GPPIC/GPPID/GPPIE register */
#define GPPIA_GPPIA (0xFFFF)            /* GPPIA[15:0] */
#define GPPIB_GPPIB (0xFFFF)            /* GPPIB[15:0] */
#define GPPIC_GPPIC (0xFFFF)            /* GPPIC[15:0] */
#define GPPID_GPPID (0xFFFF)            /* GPPID[15:0] */
#define GPPIE_GPPIE (0xFFFF)            /* GPPIE[15:0] */
#define GPPIF_GPPIF (0x007F)            /* GPPIF[ 6:0] */

/* bit field of GPPMA/GPPMB/GPPMC/GPPMD/GPPME/GPPMF register */
#define GPPMA_GPPMA (0xFFFF)            /* GPPMA[15:0] 0:input, 1:output */
#define GPPMB_GPPMB (0xFFFF)            /* GPPMB[15:0] 0:input, 1:output */
#define GPPMC_GPPMC (0xFFFF)            /* GPPMC[15:0] 0:input, 1:output */
#define GPPMD_GPPMD (0xFFFF)            /* GPPMD[15:0] 0:input, 1:output */
#define GPPME_GPPME (0xFFFF)            /* GPPME[15:0] 0:input, 1:output */
#define GPPMF_GPPMF (0x00FF)            /* GPPME[ 7:0] 0:input, 1:output */

/* bit field of GPIEE register */
#define GPIEE_GPIEE (0x0F00)            /* GPIEE[15:12] 0:interrupt disable, 1:interrupt enable */

/* bit field of GPIPE register */
#define GPIPE_GPIPE (0x0F00)            /* GPIPE[15:12] 0:"L"level, 1: "H"level */

/* bit field of GPISE register */
#define GPISE_GPISE (0x0F00)            /* GPISE[15:12] 0:interrupt not occurred, 1:interrupt occurred */

/* bit field of GPIME register */
#define GPIME_GPIME (0x0F00)            /* GPISE[15:12] 0:edge detect mode, 1:level detect mode */

/*****************************************************/
/*    Watch Dog Timer control register               */
/*****************************************************/
#define WDT_BASE    (0xB7E00000)        /* base address */
#define WDTCON      (WDT_BASE+0x00)     /* Watch Dog Timer control register (W,8,--) */
#define WDTBCON     (WDT_BASE+0x04)     /* time base counter control register (RW,8,0x00) */
#define WDSTAT      (WDT_BASE+0x14)     /* Watch Dog Timer status register (RW,8,0x00) */

/* bit field of WDTCON */
#define WDTCON_0xC3 (0xC3)              /* 0xC3 */
#define WDTCON_0x3C (0x3C)              /* 0x3C */

/* bit field of WDTBCON */
#define WDTBCON_UNLOCK  (0x5A)          /* enable writing to this register */

#define WDTBCON_CLK75   (0x00)          /* CCLK/(=7.5MHz) */
#define WDTBCON_CLK4    (0x01)          /* CCLK/4         */
#define WDTBCON_CLK32   (0x02)          /* CCLK/32        */
#define WDTBCON_CLK64   (0x03)          /* CCLK/64        */

#define WDTBCON_WDTM    (0x00)          /* WDT mode */
#define WDTBCON_ITM     (0x08)          /* interval timer mode */

#define WDTBCON_ITDIS   (0x00)          /* disable interval timer */
#define WDTBCON_ITEN    (0x10)          /* enable interval timer */

#define WDTBCON_INT     (0x00)          /* generate interrupt */
#define WDTBCON_RESET   (0x40)          /* system reset */

#define WDTBCON_COUNT   (0x00)          /* timer count */
#define WDTBCON_WDHLT   (0x80)          /* timer stop  */

/* bit field of WDTSTAT */
#define WDSTAT_RSTWDT   (0x01)          /* reset by WDT */
#define WDSTAT_RSTPWON  (0x00)          /* reset by power on */

#define WDSTAT_WDTIST   (0x10)          /* WDT interrupt */
#define WDSTAT_IVTIST   (0x20)          /* IVT interrupt */

/*****************************************************/
/*    system timer control register                  */
/*****************************************************/
#define STCR_BASE   (0xB8001000)        /* base address */
#define TMEN        (STCR_BASE+0x04)    /* timer enable register (RW,16,0x0000) */
#define TMRLR       (STCR_BASE+0x08)    /* timer reload register (RW,16,0x0000) */
#define TMOVF       (STCR_BASE+0x10)    /* overflow register (RW,16,0x0000) */

/* bit field of TMEN register */
#define TMEN_TCEN   (0x0001)            /* timer enabled */
#define TMEN_TCDSBL (0x0000)            /* timer disabled */
    /* these are aliases */
#define TMEN_RUN    (0x0001)            /* timer enabled */
#define TMEN_STOP   (0x0000)            /* timer disabled */

/* bit field of TMOVF register */
#define TMOVF_OVF   (0x0001)            /* overflow generated */
#define TMOVF_NOOVF (0x0000)            /* no overflow generated */


/*****************************************************/
/*    timer control register                         */
/*****************************************************/
#define TCR_BASE    (0xB7F00000)        /* base address */
#define TIMECNTL0   (TCR_BASE+0x00)     /* timer0 control register (RW,16,0x0000) */
#define TIMEBASE0   (TCR_BASE+0x04)     /* timer0 base register (RW,16,0x0000) */
#define TIMECNT0    (TCR_BASE+0x08)     /* timer0 counter register (R,16,0x0000) */
#define TIMECMP0    (TCR_BASE+0x0C)     /* timer0 compare register (RW,16,0xFFFF) */
#define TIMESTAT0   (TCR_BASE+0x10)     /* timer0 status register (RW,16,0x0000) */
#define TIMECNTL1   (TCR_BASE+0x20)     /* timer1 control register (RW,16,0x0000) */
#define TIMEBASE1   (TCR_BASE+0x24)     /* timer1 base register (RW,16,0x0000) */
#define TIMECNT1    (TCR_BASE+0x28)     /* timer1 counter register (R,16,0x0000) */
#define TIMECMP1    (TCR_BASE+0x2C)     /* timer1 compare register (RW,16,0xFFFF) */
#define TIMESTAT1   (TCR_BASE+0x30)     /* timer1 status register (RW,16,0x0000) */
#define TIMECNTL2   (TCR_BASE+0x40)     /* timer2 control register (RW,16,0x0000) */
#define TIMEBASE2   (TCR_BASE+0x44)     /* timer2 base register (RW,16,0x0000) */
#define TIMECNT2    (TCR_BASE+0x48)     /* timer2 counter register (R,16,0x0000) */
#define TIMECMP2    (TCR_BASE+0x4C)     /* timer2 compare register (RW,16,0xFFFF) */
#define TIMESTAT2   (TCR_BASE+0x50)     /* timer2 status register (RW,16,0x0000) */


/* bit field of TIMECNTL0-2 register */
#define TIMECNTL_OS     (0x0001)        /* one shot timer */
#define TIMECNTL_INT    (0x0000)        /* interval timer */
#define TIMECNTL_START  (0x0008)        /* timer start */
#define TIMECNTL_STOP   (0x0000)        /* timer stop  */
#define TIMECNTL_IE     (0x0010)        /* enable interrupt */
#define TIMECNTL_ID     (0x0000)        /* denable interrupt */

#define TIMECNTL_CLK    (0x0000)        /* CCLK(=7.5MHz or 2.048kHz) */
#define TIMECNTL_CLK2   (0x0020)        /* CPUCLK/2 */
#define TIMECNTL_CLK4   (0x0040)        /* CPUCLK/4 */
#define TIMECNTL_CLK8   (0x0060)        /* CPUCLK/8 */
#define TIMECNTL_CLK16  (0x0080)        /* CPUCLK/16 */
#define TIMECNTL_CLK64  (0x00A0)        /* CPUCLK/64 */
#define TIMECNTL_CLK128 (0x00C0)        /* CPUCLK/128 */
#define TIMECNTL_CLK256 (0x00E0)        /* CPUCLK/256 */


/* bit field of TIMESTAT0-5 register */
#define TIMESTAT_STATUS (0x0001)        /* status bit */

/*****************************************************/
/*    PWM control register                           */
/*****************************************************/
#define PWM_BASE        (0xB7D00000)    /* base address */
#define PWR             (PWM_BASE+0x00) /* PWM register (RW,16,0x0000) */
#define PWCY            (PWM_BASE+0x04) /* PWM cycle register (RW,16,0x0000) */
#define PWC             (PWM_BASE+0x08) /* PWM counter (RW,16,0x0000) */
#define PWCON           (PWM_BASE+0x0C) /* PWM contrlo register (RW,16,0x0000) */
#define PWINTSTS        (PWM_BASE+0x3C) /* PWM interrupt status register (RW,16,0x0000) */

/* bit field of PWCON register */
#define PWCON_PWR       (0x0001)        /* enable PWC */
    /* this is alias */
#define PWCON_RUN       (0x0001)        /* enable PWC */

#define PWCON_CLK1      (0x0000)        /* 1/1 CPUCLK */
#define PWCON_CLK4      (0x0002)        /* 1/4 CPUCLK */
#define PWCON_CLK16     (0x0004)        /* 1/16 CPUCLK */
#define PWCON_CLK32     (0x0006)        /* 1/32 CPUCLK */
#define PWCON_INTIE     (0x0040)        /* enable interrupt */
#define PWCON_PWCOV     (0x0080)        /* interruput when PWC overflow */

/* bit field of PWINTSTS register */
#define PWINTSTS_INTS    (0x0100)       /* interrupt generated */
#define PWINTSTS_INTCLR  (0x0001)       /* interrupt clear */


/*****************************************************/
/*    ASIO control register                          */
/*****************************************************/
#define SC_BASE (0xB8002000)            /* base address */
#define SIOBUF  (SC_BASE+0x00)          /* transmiting/receiving buffer register (RW,16,0x0000) */
#define SIOSTA  (SC_BASE+0x04)          /* SIO status register (RW,16,0x0000) */
#define SIOCON  (SC_BASE+0x08)          /* SIO control register (RW,16,0x0000) */
#define SIOBCN  (SC_BASE+0x0C)          /* baud rate control register (RW,16,0x0000) */
#define SIOBT   (SC_BASE+0x14)          /* baud rate timer register (RW,16,0x0000) */
#define SIOTCN  (SC_BASE+0x18)          /* SIO test control register (RW,16,0x0000) */

/* bit field of SIOBUF register */
#define SIOBUF_SIOBUF   (0x00FF)        /* SIOBUF[7:0] */

/* bit field of SIOSTA register */
#define SIOSTA_FERR     (0x0001)        /* framing error */
#define SIOSTA_OERR     (0x0002)        /* overrun error */
#define SIOSTA_PERR     (0x0004)        /* parity error */
#define SIOSTA_RVIRQ    (0x0010)        /* receive ready */
#define SIOSTA_TRIRQ    (0x0020)        /* transmit ready */

/* bit field of SIOCON register */
#define SIOCON_LN7      (0x0001)        /* data length : 7bit */
#define SIOCON_LN8      (0x0000)        /* data length : 8bit */
#define SIOCON_PEN      (0x0002)        /* parity enabled */
#define SIOCON_PDIS     (0x0000)        /* parity disabled */
#define SIOCON_EVN      (0x0004)        /* even parity */
#define SIOCON_ODD      (0x0000)        /* odd parity */
#define SIOCON_TSTB1    (0x0008)        /* stop bit : 1 */
#define SIOCON_TSTB2    (0x0000)        /* stop bit : 2 */

/* bit field of SIOBCN register */
#define SIOBCN_BGRUN    (0x0010)        /* count start */
#define SIOBCN_BGSTOP   (0x0000)        /* count stop  */

/* bit field of SIOBT register */
#define SIOBT_SIOBT (0x00FF)            /* SIOBT[7:0] */

/* bit field of SIOTCN register */
#define SIOTCN_MFERR    (0x0001)        /* generate framin error */
#define SIOTCN_MPERR    (0x0002)        /* generate parity error */
#define SIOTCN_LBTST    (0x0080)        /* loop back test */


/*****************************************************/
/*    ADC control register                           */
/*****************************************************/
#define ADC_BASE    (0xB6000000)        /* base address */
#define ADCON1      (ADC_BASE+0x04)     /* ADC control 1 register (RW,16,0x0000) */
#define ADCON2      (ADC_BASE+0x08)     /* ADC control 2 register (RW,16,0x0003) */
#define ADINT       (ADC_BASE+0x0C)     /* AD interrupt control register (RW,16,0x0000) */
#define ADR0        (ADC_BASE+0x14)     /* AD Result 0 register (RW,16,0x0000) */
#define ADR1        (ADC_BASE+0x18)     /* AD Result 1 register (RW,16,0x0000) */
#define ADR2        (ADC_BASE+0x1C)     /* AD Result 2 register (RW,16,0x0000) */
#define ADR3        (ADC_BASE+0x20)     /* AD Result 3 register (RW,16,0x0000) */

/* bit field of ADCON1 register */
#define ADCON1_ADSTM    (0x0003)        /* ADSTM[1:0] */
#define ADCON1_CH0      (0x0000)        /* CH0 */
#define ADCON1_CH1      (0x0001)        /* CH1 */
#define ADCON1_CH2      (0x0002)        /* CH2 */
#define ADCON1_CH3      (0x0003)        /* CH3 */
#define ADCON1_STS      (0x0010)        /* AD conversion start */

/* bit field of ADCON2 register */
#define ADCON2_ACKSEL   (0x0003)        /* ACKSEL[1:0] */
#define ADCON2_CLK2     (0x0001)        /* CPUCLK/2 */
#define ADCON2_CLK4     (0x0002)        /* CPUCLK/4 */
#define ADCON2_CLK8     (0x0003)        /* CPUCLK/8 */

/* bit field of ADINT register */
//#define ADINT_INTSN     (0x0001)        /* AD conversion of ch7 finished (scan mode) */
#define ADINT_INTST     (0x0002)        /* AD conversion finished (select mode) */
//#define ADINT_ADSNIE    (0x0004)        /* enable interrupt (scan mode) */
#define ADINT_ADSTIE    (0x0008)        /* enable interrupt (select mode) */

/* bit field of ADR0,ADR1,ADR2,ADR3 register */
#define ADR0_DT0    (0x03FF)            /* DT0[9:0] AD result */
#define ADR1_DT1    (0x03FF)            /* DT1[9:0] AD result */
#define ADR2_DT2    (0x03FF)            /* DT2[9:0] AD result */
#define ADR3_DT3    (0x03FF)            /* DT3[9:0] AD result */



/*****************************************************/
/*    SSIO control register                          */
/*****************************************************/
#define SSIO_BASE   (0xB7B10000)        /* base address */
#define SSIOBUF0    (SSIO_BASE+0x00)    /* transmiting/receiving buffer register (RW,8,0x00) */
#define SSIOSTA0    (SSIO_BASE+0x04)    /* SSIO status register (RW,8,0x00) */
#define SSIOCON0    (SSIO_BASE+0x08)    /* SSIO control register (RW,8,0x00) */
#define SSIOINT0    (SSIO_BASE+0x0C)    /* SSIO interrupt demand register (RW,8,0x00) */
#define SSIOINTEN0  (SSIO_BASE+0x10)    /* SSIO interrupt enable register (RW,8,0x00) */
#define SSIODMAC0   (SSIO_BASE+0x14)    /* SSIO DMA transmit register (RW,8,0x00) */
#define SSIOTSCON0  (SSIO_BASE+0x18)    /* SSIO test control register (RW,8,0x00) */
#define SSIOBUF1    (SSIO_BASE+0x20)    /* transmiting/receiving buffer register (RW,8,0x00) */
#define SSIOSTA1    (SSIO_BASE+0x24)    /* SSIO status register (RW,8,0x00) */
#define SSIOCON1    (SSIO_BASE+0x28)    /* SSIO control register (RW,8,0x00) */
#define SSIOINT1    (SSIO_BASE+0x2C)    /* SSIO interrupt demand register (RW,8,0x00) */
#define SSIOINTEN1  (SSIO_BASE+0x30)    /* SSIO interrupt enable register (RW,8,0x00) */
#define SSIODMAC1   (SSIO_BASE+0x34)    /* SSIO DMA transmit register (RW,8,0x00) */
#define SSIOTSCON1  (SSIO_BASE+0x38)    /* SSIO test control register (RW,8,0x00) */

/* bit field of SSIOBUF0,SSIOBUF1 register */
#define SSIOSTA_DUMMY   (0xFF)

/* bit field of SSIOSTA0,SSIOSTA1 register */
#define SSIOSTA_BUSY    (0x01)          /* transmiting/receiving buffer busy */
#define SSIOSTA_SFCT0   (0x00)          /* transmit end or not transmitted */
#define SSIOSTA_SFCT1   (0x20)          /* 1bit transmit end */
#define SSIOSTA_SFCT2   (0x40)          /* 2bit transmit end */
#define SSIOSTA_SFCT3   (0x60)          /* 3bit transmit end */
#define SSIOSTA_SFCT4   (0x80)          /* 4bit transmit end */
#define SSIOSTA_SFCT5   (0xA0)          /* 5bit transmit end */
#define SSIOSTA_SFCT6   (0xC0)          /* 6bit transmit end */
#define SSIOSTA_SFCT7   (0xE0)          /* 7bit transmit end */

/* bit field of SSIOCON0,SSIOCON1 register */
#define SSIOCON_TCK0    (0x00)          /* selected  15    MHz for sync clock */
#define SSIOCON_TCK1    (0x01)          /* selected   7.5  MHz for sync clock */
#define SSIOCON_TCK2    (0x02)          /* selected   3.75 MHz for sync clock */
#define SSIOCON_TCK3    (0x03)          /* selected 937.5  kHz for sync clock */
#define SSIOCON_TCK4    (0x04)          /* selected 468.75 kHz for sync clock */
#define SSIOCON_TCK5    (0x05)          /* selected 117.18 kHz for sync clock */
#define SSIOCON_TCK7    (0x07)          /* selected TMOUTx for sync clock */
#define SSIOCON_MASTER  (0x00)          /* Master */
#define SSIOCON_SLAVE   (0x10)          /* Slave */
#define SSIOCON_LSBFST  (0x00)          /* LSB first */
#define SSIOCON_MSBFST  (0x20)          /* MSB first */
#define SSIOCON_SCKNML  (0x00)          /* normal clock */
#define SSIOCON_SCKINV  (0x40)          /* clock inverted */
#define SSIOCON_RSTOFF  (0x00)          /* serial reset off */
#define SSIOCON_RSTON   (0x80)          /* serial reset on  */


/* bit field of SSIOINT0,SSIOINT1 register */
#define SSIOINT_TXRXCMP (0x01)          /* transmit/receive complete */
#define SSIOINT_TREMP   (0x02)          /* transmit empty */

/* bit field of SSIOINTEN0,SSIOINTEN1 register */
#define SSIOINTEN_TXRXCMPEN (0x01)      /* transmit/receive complete enable */
#define SSIOINTEN_TREMPEN   (0x02)      /* transmit empty enable */

/* bit field of SSIODMAC0, SSIODMAC1 register */
#define SSIODMAC_DMAEN   (0x00)         /* DMA transfer mode desable */
#define SSIODMAC_DMADES  (0x01)         /* DMA transfer mode enable */
#define SSIODMAC_TRNSACT (0x00)         /* DMA transmit action */
#define SSIODMAC_RCVACT  (0x10)         /* DMA receive action */

/* bit field of SSIOTSCON0,SSIOTSCON01 register */
#define SSIOTSCON_LBTST (0x80)          /* loop back test mode on*/
#define SSIOTSCON_NOTST (0x00)          /* test mode off */

/*****************************************************/
/*    I2C control register                          */
/*****************************************************/
#define I2C_BASE    (0xB7B00000)        /* base address */
#define I2CCON      (I2C_BASE+0x00)     /* I2C control register (RW,8,0x00) */
#define I2CSAD      (I2C_BASE+0x04)     /* I2C slave address mode setting register (RW,8,0x00) */
#define I2CCLR      (I2C_BASE+0x08)     /* I2C transmit speed setting register (RW,8,0x00) */
#define I2CSR       (I2C_BASE+0x0C)     /* I2C status register (R,8,0x00) */
#define I2CIR       (I2C_BASE+0x10)     /* I2C interrupt demand register (RW,8,0x00) */
#define I2CIMR      (I2C_BASE+0x14)     /* I2C interrupt mask register  (RW,8,0x00) */
#define I2CDR       (I2C_BASE+0x18)     /* I2C transmiting/receiving buffer register (RW,8,0x00) */

/* bit field of I2CCON register */
#define I2CCON_EN       (0x01)          /* restart sequence start */
#define I2CCON_OC       (0x02)          /* I2C-bus hold */
#define I2CCON_STCM     (0x04)          /* communication start */
#define I2CCON_RESTR    (0x08)          /* carry out restart */
#define I2CCON_START    (0x10)          /* exist START byte */

/* bit field of I2CSAD register */
#define I2CSAD_RW_SND   (0x00)          /* data transmiting mode */
#define I2CSAD_RW_REC   (0x01)          /* data receiving mode */
#define I2CSAD_SLVAD0   (0x02)          /* slave address 0 */
#define I2CSAD_SLVAD1   (0x04)          /* slave address 1 */
#define I2CSAD_SLVAD2   (0x08)          /* slave address 2 */
#define I2CSAD_SLVAD3   (0x10)          /* slave address 3 */
#define I2CSAD_SLVAD4   (0x20)          /* slave address 4 */
#define I2CSAD_SLVAD5   (0x40)          /* slave address 5 */
#define I2CSAD_SLVAD6   (0x80)          /* slave address 6 */

/* bit field of I2CCLR register */
#define I2CCLR_CMD1 (0x00)              /* Standard-mode */
#define I2CCLR_CMD4 (0x01)              /* Fast-mode */

/* bit field of I2CSR register */
#define I2CSR_DAK   (0x01)              /* data ACKnowledge no receive */
#define I2CSR_AAK   (0x02)              /* slave address ACKnowledge no receive */

/* bit field of I2CIR register */
#define I2CIR_IR    (0x01)              /* interrupt demand */

/* bit field of I2CIMR register */
#define I2CIMR_MF   (0x01)              /* interrupt mask set */


/*****************************************************/
/*    RTC Control register                           */
/*****************************************************/
#define RTC_BASE    (0xB7C00000)        /* base address */
#define RTCREG      (RTC_BASE+0x00)     /* RTC second count register  */
#define RTCCON      (RTC_BASE+0x04)     /* RTC control register  */
#define RTCCMP      (RTC_BASE+0x08)     /* RTC compare register  */
#define RTCSCRP     (RTC_BASE+0x0C)     /* RTC scratchpad register  */
#define RTCST       (RTC_BASE+0x10)     /* RTC status register  */

/* for RTCREG, RTCCON, RTCCMP, RTCST registers */
#define RTC_UNLOCK1     0x0000003c
#define RTC_UNLOCK2     0x0000005a

/*****************************************************/
/*    I2S send control register                      */
/*****************************************************/
#define I2SSND_BASE (0x82000000)     /* base address */
#define I2SFIFOO    (I2SSND_BASE+0x00)  /* I2S transceiver FIFO register (RW,32,---) */
#define I2SCONO0    (I2SSND_BASE+0x04)  /* I2S transceiver contorl register0 (RW,32,0x0000) */
#define I2SCONO1    (I2SSND_BASE+0x08)  /* I2S transceiver control register1 (RW,32,0x0000) */
#define I2SAFRO     (I2SSND_BASE+0x0C)  /* I2S transceiver Almost Full threshold register (RW,32,0x0000) */
#define I2SAERO     (I2SSND_BASE+0x10)  /* I2S transceiver Almost Empty threshold register (RW,32,0x0000) */
#define I2SIMRO     (I2SSND_BASE+0x14)  /* I2S transceiver interrupt mask register (RW,32,0x000F) */
#define I2SISTO     (I2SSND_BASE+0x18)  /* I2S transceiver interrupt status register (RW,32,0x0000) */
#define I2SWADRO    (I2SSND_BASE+0x1C)  /* I2S transceiver FIFO write address register (RW,32,0x0000) */
#define I2SRADRO    (I2SSND_BASE+0x20)  /* I2S transceiver FIFO read address register (RW,32,0x0000) */
#define I2SDNOO     (I2SSND_BASE+0x24)  /* I2S transceiver FIFO occupation data size register (R,32,0x0000) */

/*****************************************************/
/*    I2S receive control register                   */
/*****************************************************/
#define I2SRCV_BASE (0x84000000)        /* base address */
#define I2SFIFOI    (I2SRCV_BASE+0x00)  /* I2S receiver FIFO register (RW,32,0x0000) */
#define I2SCONI0    (I2SRCV_BASE+0x04)  /* I2S receiver contorl register0 (RW,32,0x0000) */
#define I2SCONI1    (I2SRCV_BASE+0x08)  /* I2S receiver control register1 (RW,32,0x0000) */
#define I2SAFRI     (I2SRCV_BASE+0x0C)  /* I2S receiver Almost Full threshold register (RW,32,0x0000) */
#define I2SAERI     (I2SRCV_BASE+0x10)  /* I2S receiver Almost Empty threshold register (RW,32,0x0000) */
#define I2SIMRI     (I2SRCV_BASE+0x14)  /* I2S receiver interrupt mask register (RW,32,0x000F) */
#define I2SISTI     (I2SRCV_BASE+0x18)  /* I2S receiver interrupt status register (RW,32,0x0000) */
#define I2SWADRI    (I2SRCV_BASE+0x1C)  /* I2S receiver FIFO write address register (RW,32,0x0000) */
#define I2SRADRI    (I2SRCV_BASE+0x20)  /* I2S receiver FIFO read address register (RW,32,0x0000) */
#define I2SDNOI     (I2SRCV_BASE+0x24)  /* I2S receiver FIFO occupation data size register (R,32,0x0000) */


/*****************************************************/
/*    NAND FLASH Controller register                 */
/*****************************************************/
#define NFC_BASE    (0x86000000)        /* base address */
#define MBANK       (NFC_BASE+0x00)     /* media bank register (RW,32,0x0000) */
#define MSCTRL      (NFC_BASE+0x04)     /* media sequencer controller register (RW,32,0x0000) */
#define MSWAIT      (NFC_BASE+0x08)     /* media sequencer wait register (RW,32,0x0000) */
#define MSSTS       (NFC_BASE+0x0C)     /* media sequencer status register (R,32,0x001E) */
#define MINTENBL    (NFC_BASE+0x10)     /* media sequencer interrupt enable register (RW,32,0x0000) */
#define MSERR       (NFC_BASE+0x14)     /* media sequencer error status register (R,32,0x0000) */
#define MMCMD       (NFC_BASE+0x18)     /* media command register (W,32,---) */
#define MMADR       (NFC_BASE+0x1C)     /* media address register (W,32,---) */
#define MMSEL       (NFC_BASE+0x20)     /* media select register (RW,32,0x0000) */
#define MMRDCTL     (NFC_BASE+0x24)     /* media data read control register (RW,32,0x0000) */
#define MOPTION     (NFC_BASE+0x28)     /* media option register (RW,32,0x0000) */
#define MMRDDATA    (NFC_BASE+0x2C)     /* media read data store register (R,32,0x0000 */
#define ECCLP1      (NFC_BASE+0x30)     /* ECC line parity register1 (R,32,0xFFFFFFFF) */
#define ECCCP1      (NFC_BASE+0x34)     /* ECC column parity register1 (R,32,0x003F003F)) */
#define ECCERR1     (NFC_BASE+0x38)     /* ECC error pointer register1 (R,32,0x0000) */
#define HREV1       (NFC_BASE+0x40)     /* redundancy reserve data register1 (RW,32,0x0000) */
#define HSTAD1      (NFC_BASE+0x44)     /* redundancy data /block-status.address register1 (RW,32,0x0000) */
#define HECC2       (NFC_BASE+0x48)     /* redundancy ECC2-High, ECC2-Low block address register (RW,32,0x0000) */
#define HECC1       (NFC_BASE+0x4C)     /* redundancy ECC1-High, ECC1-Low block address register (RW,32,0x0000) */
#define ECCLP3      (NFC_BASE+0x50)     /* ECC line parity register3 (R,32,0xFFFFFFFF) */
#define ECCCP3      (NFC_BASE+0x54)     /* ECC column parity register3 (R,32,0x003F003F)) */
#define ECCERR3     (NFC_BASE+0x58)     /* ECC error pointer register3 (R,32,0x0000) */
#define HREV3       (NFC_BASE+0x60)     /* redundancy reserve data register3 (RW,32,0x0000) */
#define HSTAD3      (NFC_BASE+0x64)     /* redundancy data/block status block address register (RW,32,0x0000) */

/*****************************************************/
/*    interrupt number                               */
/*****************************************************/
#define INT_SYSTEM_TIMER    0
#define INT_SSIO_0          1
#define INT_SSIO_1          2
#define INT_SSIO_2          3
#define INT_WDT             4
#define INT_RTC             5
#define INT_PIOE12          6
    /* reserved             7   */
#define INT_IRQS            8
#define INT_PWM             9
#define INT_SIO             10
#define INT_I2C             11
#define INT_ADC             12
#define INT_NANDFLASH       13
#define INT_IDEC            14
    /* reserved             15  */
#define INT_TIMER0          16
#define INT_TIMER1          17
#define INT_TIMER2          18
    /* reserved             19  */
#define INT_I2STRANS        20
#define INT_I2SRECEIVE      21
#define INT_DMA0            22
#define INT_DMA1            23
#define INT_DMA2            24
#define INT_DMA3            25
#define INT_PIOE15          26
#define INT_USBVBUS         26  /* same as PIOE15, we sense VBUS by PIOE15 */
#define INT_USB             27
    /* reserved             28  */
#define INT_PIOE14          29
    /* reserved             30  */
#define INT_PIOE13          31

/*****************************************************/
/*    other                                          */
/*****************************************************/
//#define UNLOCK      (0x3C)              /* unlock protect for mis-write */

#ifdef __cplusplus
};      /* End of 'extern "C"' */
#endif
#endif  /* End of ML69Q6203_H */
