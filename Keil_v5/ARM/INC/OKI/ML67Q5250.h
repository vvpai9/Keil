/******************************************************************************

     Copyright (C) 2007 Oki Electric Industry Co.,LTD.

     System Name  :  ML67Q5250 CPU Board
     Module Name  :  definition for registers
     File   Name  :  ML67Q5250.h
     Revision     :  01.00
     Date         :  2007/04/18      First version

******************************************************************************/
#ifndef ML67Q5250_H
#define ML67Q5250_H

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************/
/*    system control register                        */
/*****************************************************/
/*****************************************************************************
    uPLAT_CTL
*****************************************************************************/
#define SCR_BASE        (0xB8000000)    /* base address */
#define IDR             (SCR_BASE+0x00) /* type and revision (RO,32,0x00000100) */
#define CLKSTP          (SCR_BASE+0x04) /* clock stop register (W,32,0x00000000) */
#define RMPCON          (SCR_BASE+0x10) /* remap control register (RW,32,0x00000000) */

/* for IDR, CLKSTP, CGBCNT0, CKWT, RMPCON, CGBCNT1, CGBCNT2 registers */
#define SCR_UNLOCK      0x0000003c

/* bit field of CLKSTP register */
#define CLKSTP_SIO      (0x00000001)    /* SIO HALT */
#define CLKSTP_TIC      (0x00000002)    /* TIC HALT */
#define CLKSTP_HALT     (0x00000004)    /* CPU group HALT */
#define CLKSTP_STOP     (0x00000080)    /* STOPMODE */

/* bit field of RMPCON register */
#define RMPCON_RMPM_P_RAM (0x0000000C)    /* Processor RAM */
#define RMPCON_RMPM_E_ROM (0x00000008)    /* External ROM */

/*****************************************************************************
    control
*****************************************************************************/
#define CTL_BAS     0xB7000000
#define DMARQCNT    (CTL_BAS+(0x00))  /* DMA request source control register (RW,32,0x00000000) */
#define LSICNT      (CTL_BAS+(0x04))  /* LSI control register (R,32,0xXXXXXXXX) */
#define PORTSELA    (CTL_BAS+(0x10))  /* PIOA function control register (RW,32,0x00000000) */
#define PORTSELB    (CTL_BAS+(0x14))  /* PIOB function control register (RW,32,0x00000000) */
#define PORTSELC    (CTL_BAS+(0x18))  /* PIOC function control register (RW,32,0x00000000) */

#if 1
/*****************************************************************************
    clock control
*****************************************************************************/
#define PECLKCNT    (CTL_BAS+(0x100))   /* peripheral clock control register (RW,32,0x0000001F) */
#define PERSTCNT    (CTL_BAS+(0x104))   /* peripheral reset control register (RW,32,0x00000000) */
#define CLKCNT      (CTL_BAS+(0x10C))   /* clock control register (RW,32,0x02011111) */
#define CLKSTPCNT   (CTL_BAS+(0x110))   /* clock stop control register (RW,32,0x00000000) */
#define CKWT        (CTL_BAS+(0x114))   /* clock wait time control register (RW,32,0x00000FFF) */

#define PERSTCNT_RST_FPSP	(0x10)
#define PERSTCNT_RST_USB	(0x08)
#define PERSTCNT_RST_SPI	(0x04)
#define PERSTCNT_RST_SIMIF	(0x02)
#define PERSTCNT_RST_SSIO	(0x01)

/*****************************************************************************
    Flash control
*****************************************************************************/
#define FLACON      (CTL_BAS+(0x200))   /* Flash ROM control register (RW,32,0xXXXXXXXX) */
#endif

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

/*****************************************************************************
    EXINTCo
*****************************************************************************/
#define EICR_BASE   (0x7BF00000)        /* base address */
#define EXIRS         (EICR_BASE+0x00)    /* Extended interrupt Size register (R,32,0x0000003F?? 1F??) */
#define EXIRQA        (EICR_BASE+0x10)    /* Extended interrupt IRQ register (R,32,0x00000000) */
#define EXIDMA        (EICR_BASE+0x14)    /* Extended interrupt Mode control register (RW,32,0x00000000) */
#define EXILCA        (EICR_BASE+0x18)    /* Extended interrupt level control register (RW,32,0x00000000) */
#define EXIRQSA       (EICR_BASE+0x1C)    /* Extended interrupt status register (R,32,0x00000000) */
#define EXFIQ         (EICR_BASE+0x80)    /* Extended interrupt FIQ register (RW,32,0x00000000) */
#define EXFIDM        (EICR_BASE+0x84)    /* Extended interrupt FIQ Mode register (RW,32,0x00000000) */

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

/* bit field of EXIRQA register */
#define EXIRQA_IRQ16  (0x00000001)        /* IRQ16 */
#define EXIRQA_IRQ17  (0x00000002)        /* IRQ17 */
#define EXIRQA_IRQ18  (0x00000004)        /* IRQ18 */
#define EXIRQA_IRQ19  (0x00000008)        /* IRQ19 */
#define EXIRQA_IRQ20  (0x00000010)        /* IRQ20 */
#define EXIRQA_IRQ21  (0x00000020)        /* IRQ21 */
#define EXIRQA_IRQ22  (0x00000040)        /* IRQ22 */
#define EXIRQA_IRQ23  (0x00000080)        /* IRQ23 */
#define EXIRQA_IRQ24  (0x00000100)        /* IRQ24 */
#define EXIRQA_IRQ25  (0x00000200)        /* IRQ25 */
#define EXIRQA_IRQ26  (0x00000400)        /* IRQ26 */
#define EXIRQA_IRQ27  (0x00000800)        /* IRQ27 */
#define EXIRQA_IRQ28  (0x00001000)        /* IRQ28 */
#define EXIRQA_IRQ29  (0x00002000)        /* IRQ29 */
#define EXIRQA_IRQ30  (0x00004000)        /* IRQ30 */
#define EXIRQA_IRQ31  (0x00008000)        /* IRQ31 */

/* bit field of EXIDMA register */
#define EXIDM_IDM22   (0x00000040)        /* IRQ22 */
#define EXIDM_IDM26   (0x00000400)        /* IRQ26 */
#define EXIDM_IDM28   (0x00001000)        /* IRQ28 */
#define EXIDM_IDM30   (0x00004000)        /* IRQ31 */
#define EXIDM_IDMP22  (0x00000080)        /* IRQ22 */
#define EXIDM_IDMP26  (0x00000800)        /* IRQ26 */
#define EXIDM_IDMP28  (0x00002000)        /* IRQ28 */
#define EXIDM_IDMP30  (0x00008000)        /* IRQ31 */
#define EXIDM_INT_L_L (0x00000000)        /* level sensing, interrupt occurs when 'L' */
#define EXIDM_INT_L_H (0x0000AAAA)        /* level sensing, interrupt occurs when 'H' */
#define EXIDM_INT_E_F (0x00005555)        /* edge sensing, interrupt occurs when falling edge */
#define EXIDM_INT_E_R (0x0000FFFF)        /* edge sensing, interrupt occurs when rising edge */
#define EXIDM_IRQ22   (0x000000C0)        /* IRQ22 */
#define EXIDM_IRQ26   (0x00000C00)        /* IRQ26 */
#define EXIDM_IRQ28   (0x00003000)        /* IRQ28 */
#define EXIDM_IRQ31   (0x0000C000)        /* IRQ31 */


/* bit field of EXILCA register */
#define EXILC_ILC16   (0x00000007)        /* IRQ16, IRQ17 */
#define EXILC_ILC18   (0x00000070)        /* IRQ18, IRQ19 */
#define EXILC_ILC20   (0x00000700)        /* IRQ20, IRQ21 */
#define EXILC_ILC22   (0x00007000)        /* IRQ22, IRQ23 */
#define EXILC_ILC24   (0x00070000)        /* IRQ24, IRQ25 */
#define EXILC_ILC26   (0x00700000)        /* IRQ26, IRQ27 */
#define EXILC_ILC28   (0x07000000)        /* IRQ28, IRQ29 */
#define EXILC_ILC30   (0x70000000)        /* IRQ30, IRQ31 */
#define EXILC_INT_LV1 (0x11111111)        /* interrupt level 1 */
#define EXILC_INT_LV2 (0x22222222)        /* interrupt level 2 */
#define EXILC_INT_LV3 (0x33333333)        /* interrupt level 3 */
#define EXILC_INT_LV4 (0x44444444)        /* interrupt level 4 */
#define EXILC_INT_LV5 (0x55555555)        /* interrupt level 5 */
#define EXILC_INT_LV6 (0x66666666)        /* interrupt level 6 */
#define EXILC_INT_LV7 (0x77777777)        /* interrupt level 7 */

/*****************************************************/
/*    external memory control register               */
/*****************************************************/
/*****************************************************************************
    PBIC
*****************************************************************************/
#define EMCR_BASE   (0x78100000)        /* base address */
#define BWC         (EMCR_BASE+0x00)    /* bus width control register (RW,32,0x00000008) */
#define ROMAC       (EMCR_BASE+0x04)    /* external ROM access control register (RW,32,0x00000007) */
#define RAMAC       (EMCR_BASE+0x08)    /* external SRAM access control register (RW,32,0x00000007) */
#define IO0AC       (EMCR_BASE+0x0C)    /* external IO0 access control register (RW,32,0x00000007) */
#define IO1AC       (EMCR_BASE+0x10)    /* external IO1 access control register (RW,32,0x00000007) */

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
#define POA         (PCR_BASE+0x0000)   /* port A output register (RW,16,--) */
#define PIA         (PCR_BASE+0x0004)   /* port A input register (R,16,--)*/
#define PMA         (PCR_BASE+0x0008)   /* port A Mode register (RW,16,0x0000) */
#define IEA         (PCR_BASE+0x000C)   /* port A interrupt enable (RW,16,0x0000) */
#define IM0A        (PCR_BASE+0x0010)   /* port A interrupt Mode register 0 (RW,16,0x0000) */
#define IM1A        (PCR_BASE+0x0014)   /* port A interrupt Mode register 1 (RW,16,0x0000) */
#define ISA         (PCR_BASE+0x0018)   /* port A interrupt Status (RW,16,0x0000) */

#define POB         (PCR_BASE+0x1000)   /* port B Output register (RW,16,--) */
#define PIB         (PCR_BASE+0x1004)   /* port B Input register (R,16,--) */
#define PMB         (PCR_BASE+0x1008)   /* port B Mode register (RW,16,0x0000) */
#define IEB         (PCR_BASE+0x100C)   /* port B interrupt enable (RW,16,0x0000) */
#define IM0B        (PCR_BASE+0x1010)   /* port B interrupt Mode register 0 (RW,16,0x0000) */
#define IM1B        (PCR_BASE+0x1014)   /* port B interrupt Mode register 1 (RW,16,0x0000) */
#define ISB         (PCR_BASE+0x1018)   /* port B interrupt Status (RW,16,0x0000) */

#define POC         (PCR_BASE+0x2000)   /* port C Output register (RW,16,--) */
#define PIC         (PCR_BASE+0x2004)   /* port C Input register (R,16,--) */
#define PMC         (PCR_BASE+0x2008)   /* port C Mode register (RW,16,0x0000) */
#define IEC         (PCR_BASE+0x200C)   /* port C interrupt enable (RW,16,0x0000) */
#define IM0C        (PCR_BASE+0x2010)   /* port C interrupt Mode register 0 (RW,16,0x0000) */
#define IM1C        (PCR_BASE+0x2014)   /* port C interrupt Mode register 1 (RW,16,0x0000) */
#define ISC         (PCR_BASE+0x2018)   /* port C interrupt Status (RW,16,0x0000) */


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
/*****************************************************************************
    FTM
*****************************************************************************/
#define FTM_BASE	0xB7F00000  /* base address */

#define FTM0CON		(FTM_BASE+0x00) /* timer0 control register */
#define FTM0ST		(FTM_BASE+0x04)	/* timer0 status register */
#define FTM0C		(FTM_BASE+0x08) /* timer0 counter register */
#define FTM0R		(FTM_BASE+0x0C)	/* timer0 register */
#define FTM0GR		(FTM_BASE+0x10)	/* timer0 wide use register */
#define FTM0IOLV	(FTM_BASE+0x14)	/* timer0 I/O level register */
#define FTM0OUT		(FTM_BASE+0x18)	/* timer0 out register */
#define FTM0IER		(FTM_BASE+0x1C) /* timer0 interrupt enable register */

#define FTM1CON		(FTM_BASE+0x20) /* timer1 control register */
#define FTM1ST		(FTM_BASE+0x24)	/* timer1 status register */
#define FTM1C		(FTM_BASE+0x28) /* timer1 counter register */
#define FTM1R		(FTM_BASE+0x2C)	/* timer1 register */
#define FTM1GR		(FTM_BASE+0x30)	/* timer1 wide use register */
#define FTM1IOLV	(FTM_BASE+0x34)	/* timer1 I/O level register */
#define FTM1OUT		(FTM_BASE+0x38)	/* timer1 out register */
#define FTM1IER		(FTM_BASE+0x3C) /* timer1 interrupt enable register */

#define FTM2CON		(FTM_BASE+0x40) /* timer2 control register */
#define FTM2ST		(FTM_BASE+0x44)	/* timer2 status register */
#define FTM2C		(FTM_BASE+0x48) /* timer2 counter register */
#define FTM2R		(FTM_BASE+0x4C)	/* timer2 register */
#define FTM2GR		(FTM_BASE+0x50)	/* timer2 wide use register */
#define FTM2IOLV	(FTM_BASE+0x54)	/* timer2 I/O level register */
#define FTM2OUT		(FTM_BASE+0x58)	/* timer2 out register */
#define FTM2IER		(FTM_BASE+0x5C) /* timer2 interrupt enable register */

#define	FTMEN		(FTM_BASE+0xC0)	/* timer enable register */
#define FTMDIS		(FTM_BASE+0xC4)	/* timer disable register */

/* bit field of FTMnCON */
#define FTMnCON_FIELD_FTMCLK		0x0
#define FTMnCON_VALUE_FTMCLK_MASK	(0x0007u << FTMnCON_FIELD_FTMCLK)
#define FTMnCON_FIELD_MOD			0x3
#define FTMnCON_VALUE_MOD_ART		(0x0000u << FTMnCON_FIELD_MOD)
#define FTMnCON_VALUE_MOD_CMO		(0x0001u << FTMnCON_FIELD_MOD)
#define FTMnCON_VALUE_MOD_PWM		(0x0002u << FTMnCON_FIELD_MOD)
#define FTMnCON_VALUE_MOD_CAP		(0x0003u << FTMnCON_FIELD_MOD)
#define FTMnCON_VALUE_MOD_MASK		(0x0003u << FTMnCON_FIELD_MOD)

/* bit field of FTMnST, FTMnIER */
#define FTMn_FIELD_CMO_CAP			0x0
#define FTMn_VALUE_CMO_CAP_MASK		(0x0001u << FTMn_FIELD_CMO_CAP)
#define FTMn_FIELD_OVF				0x1
#define FTMn_VALUE_OVF_MASK			(0x0001u << FTMn_FIELD_OVF)

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
/*    SSIO control register                          */
/*****************************************************/
#define SSIO_BASE   (0xB7B10000)        /* base address */

#define SSIOBUF_OFFSET     0x00    /* transmiting/receiving buffer register (RW,8,0xXX) */
#define SSIOST_OFFSET      0x04    /* SSIO status register (RW,8,0x00) */
#define SSIOCON_OFFSET     0x08    /* SSIO control register (RW,8,0x02) */
#define SSIOINT_OFFSET     0x0C    /* SSIO interrupt demand register (RW,8,0x00) */
#define SSIOINTEN_OFFSET   0x10    /* SSIO interrupt enable register (RW,8,0x00) */
#define SSIODMAC_OFFSET    0x14    /* SSIO DMA transmit register (RW,8,0x00) */
#define SSIOTSCON_OFFSET   0x18    /* SSIO test control register (RW,8,0x00) */

#define SSIOBUF     (SSIO_BASE+SSIOBUF_OFFSET)
#define SSIOST      (SSIO_BASE+SSIOST_OFFSET)
#define SSIOCON     (SSIO_BASE+SSIOCON_OFFSET)
#define SSIOINT     (SSIO_BASE+SSIOINT_OFFSET)
#define SSIOINTEN   (SSIO_BASE+SSIOINTEN_OFFSET)
#define SSIODMAC    (SSIO_BASE+SSIODMAC_OFFSET)
#define SSIOTSCON   (SSIO_BASE+SSIOTSCON_OFFSET)

/* bit field of SSIOBUF0,SSIOBUF1 register */
#define SSIOBUF_DUMMY    (0xFF)

/* bit field of SSIOSTA0,SSIOSTA1 register */
#define SSIOST_BUSY     (0x01)          /* transmiting/receiving buffer busy */
#define SSIOST_SFCT0    (0x00)          /* transmit end or not transmitted */
#define SSIOST_SFCT1    (0x20)          /* 1bit transmit end */
#define SSIOST_SFCT2    (0x40)          /* 2bit transmit end */
#define SSIOST_SFCT3    (0x60)          /* 3bit transmit end */
#define SSIOST_SFCT4    (0x80)          /* 4bit transmit end */
#define SSIOST_SFCT5    (0xA0)          /* 5bit transmit end */
#define SSIOST_SFCT6    (0xC0)          /* 6bit transmit end */
#define SSIOST_SFCT7    (0xE0)          /* 7bit transmit end */

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
#define SSIOCON_FIELD_SLMSB  (0x05)      /* SLMSB */
#define SSIOCON_VALUE_SLMSB_MASK  (0x1<<SSIOCON_FIELD_SLMSB)      /* SLMSB */
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
#define SSIODMAC_DMADES  (0x00)         /* DMA transfer mode desable */
#define SSIODMAC_DMAEN   (0x01)         /* DMA transfer mode enable */
#define SSIODMAC_TRNSACT (0x00)         /* DMA transmit action */
#define SSIODMAC_RCVACT  (0x10)         /* DMA receive action */

/* bit field of SSIOTSCON0,SSIOTSCON01 register */
#define SSIOTSCON_LBTST (0x80)          /* loop back test mode on*/
#define SSIOTSCON_NOTST (0x00)          /* test mode off */


/*****************************************************/
/*    USB 2.0 FS Device control registers            */
/*****************************************************/
#define UDE_BASE        0xB7700000              /* base address of USB 2.0 FS Device control registers */

#define bmREQUESTTYPE   (UDE_BASE+0x00)         /* bmRequestType setup register */
#define bREQUEST        (UDE_BASE+0x04)         /* bRequest setup register   */
#define wVALUE_LSB      (UDE_BASE+0x08)         /* wValueLSB setup register  */
#define wVALUE_MSB      (UDE_BASE+0x0C)         /* wValueMSB setup register  */
#define wINDEX_LSB      (UDE_BASE+0x10)         /* wIndexLSB setup register  */
#define wINDEX_MSB      (UDE_BASE+0x14)         /* wIndexMSB setup register  */
#define wLENGTH_LSB     (UDE_BASE+0x18)         /* wLengthLSB setup register */
#define wLENGTH_MSB     (UDE_BASE+0x1C)         /* wLengthMSB setup register */

#define DVCADR          (UDE_BASE+0x80)         /* Device address register */
#define INTSTAT1        (UDE_BASE+0x84)         /* Interrupt status register 1 */
#define INTSTAT2        (UDE_BASE+0x88)         /* Interrupt status register 2 */
#define INTENBL1        (UDE_BASE+0x90)         /* Interrupt enable register 1 */
#define INTENBL2        (UDE_BASE+0x94)         /* Interrupt enable register 2 */

#define ISO_M_SEL       (UDE_BASE+0xB0)         /* Isochronous mode selection register */
#define FRAME_LSB       (UDE_BASE+0xB4)         /* Frame number register LSB */
#define FRAME_MSB       (UDE_BASE+0xB8)         /* Frame number register MSB */

#define SYSCON          (UDE_BASE+0xBC)         /* System control register */
#define POLSEL          (UDE_BASE+0xC0)         /* Polarity select register */
#define EP0CONF         (UDE_BASE+0x100)        /* EP0 configuration register */
#define EP1CONF         (UDE_BASE+0x104)        /* EP1 configuration register */
#define EP2CONF         (UDE_BASE+0x108)        /* EP2 configuration register */
#define EP3CONF         (UDE_BASE+0x10C)        /* EP3 configuration register */
#define EP4CONF         (UDE_BASE+0x110)        /* EP4 configuration register */
#define EP5CONF         (UDE_BASE+0x114)        /* EP5 configuration register */
#define EP0CONT         (UDE_BASE+0x120)        /* EP0 control register */
#define EP1CONT         (UDE_BASE+0x124)        /* EP1 control register */
#define EP2CONT         (UDE_BASE+0x128)        /* EP2 control register */
#define EP3CONT         (UDE_BASE+0x12C)        /* EP3 control register */
#define EP4CONT         (UDE_BASE+0x130)        /* EP4 control register */
#define EP5CONT         (UDE_BASE+0x134)        /* EP5 control register */
#define EP0PLD          (UDE_BASE+0x140)        /* EP0 payload register */
#define EP1PLD          (UDE_BASE+0x144)        /* EP1 payload register */
#define EP2PLD          (UDE_BASE+0x148)        /* EP2 payload register */
#define EP3PLD          (UDE_BASE+0x14C)        /* EP3 payload register */
#define EP4PLD          (UDE_BASE+0x150)        /* EP4 payload register */
#define EP5PLD          (UDE_BASE+0x154)        /* EP5 payload register */
#define EP0RXCNT        (UDE_BASE+0x160)        /* EP0 received byte counter */
#define EP1RXCNT        (UDE_BASE+0x164)        /* EP1 received byte counter */
#define EP2RXCNT        (UDE_BASE+0x168)        /* EP2 received byte counter */
#define EP3RXCNT        (UDE_BASE+0x16C)        /* EP3 received byte counter */
#define EP4RXCNT        (UDE_BASE+0x170)        /* EP4 received byte counter */
#define EP5RXCNT        (UDE_BASE+0x174)        /* EP5 received byte counter */
#define EP0STAT         (UDE_BASE+0x180)        /* EP0 status register */
#define EP1STAT         (UDE_BASE+0x184)        /* EP1 status register */
#define EP2STAT         (UDE_BASE+0x188)        /* EP2 status register */
#define EP3STAT         (UDE_BASE+0x18C)        /* EP3 status register */
#define EP4STAT         (UDE_BASE+0x190)        /* EP4 status register */
#define EP5STAT         (UDE_BASE+0x194)        /* EP5 status register */
#define EP0TXFIFO       (UDE_BASE+0x1C0)        /* EP0 Transmitter FIFO */
#define EP0RXFIFO       (UDE_BASE+0x1E0)        /* EP0 Receive FIFO */
#define EP1FIFO         (UDE_BASE+0x1E4)        /* EP1 Transmit/Receive FIFO */
#define EP2FIFO         (UDE_BASE+0x1E8)        /* EP2 Transmit/Receive FIFO */
#define EP3FIFO         (UDE_BASE+0x1EC)        /* EP3 Transmit/Receive FIFO */
#define EP4FIFO         (UDE_BASE+0x1F0)        /* EP4 Transmit/Receive FIFO */
#define EP5FIFO         (UDE_BASE+0x1F4)        /* EP5 Transmit/Receive FIFO */

/* bit field of bmRequestType register */
#define bmRequestType_Recipient 0x0000001F      /* Receiver type */
#define bmRequestType_Type      0x00000060      /* Type definition */
#define bmRequestType_Direction 0x00000080      /* Data transfer direction */

/* bit field of INTSTAT1 register */
#define INTSTAT1_D0             0x00000001      /* Setup ready interrupt */
#define INTSTAT1_D1             0x00000002      /* EP1 packet ready interrupt */
#define INTSTAT1_D2             0x00000004      /* EP2 packet ready interrupt */
#define INTSTAT1_D3             0x00000008      /* EP3 packet ready interrupt */
#define INTSTAT1_D4             0x00000010      /* EP4 packet ready interrupt */
#define INTSTAT1_D5             0x00000020      /* EP5 packet ready interrupt */
#define INTSTAT1_D6             0x00000040      /* EP0 receive packet ready interrupt */
#define INTSTAT1_D7             0x00000080      /* EP0 transmit packet ready interrupt */

/* bit field of INTSTAT2 register */
#define INTSTAT2_D0             0x00000001      /* SOF interrupt */
#define INTSTAT2_D1             0x00000002      /* USB bus reset assert interrupt */
#define INTSTAT2_D2             0x00000004      /* USB bus reset de-assert interrupt */
#define INTSTAT2_D3             0x00000008      /* Device suspended state interrupt */
#define INTSTAT2_D4             0x00000010      /* Device awake interrupt */

/* bit field of INTENBL1 register */
#define INTENBL1_D0             0x00000001      /* Enable setup ready interrupt */
#define INTENBL1_D1             0x00000002      /* Enable EP1 packet ready interrupt */
#define INTENBL1_D2             0x00000004      /* Enable EP2 packet ready interrupt */
#define INTENBL1_D3             0x00000008      /* Enable EP3 packet ready interrupt */
#define INTENBL1_D4             0x00000010      /* Enable EP4 packet ready interrupt */
#define INTENBL1_D5             0x00000020      /* Enable EP5 packet ready interrupt */
#define INTENBL1_D6             0x00000040      /* Enable EP0 receive packet ready interrupt */
#define INTENBL1_D7             0x00000080      /* Enable EP0 transmit packet ready interrupt */

/* bit field of INTENBL2 register */
#define INTENBL2_D0             0x00000001      /* Enable SOF interrupt */
#define INTENBL2_D1             0x00000002      /* Enable USB bus reset assert interrupt */
#define INTENBL2_D2             0x00000004      /* Enable USB bus reset de-assert interrupt */
#define INTENBL2_D3             0x00000008      /* Enable Device suspended state interrupt */
#define INTENBL2_D4             0x00000010      /* Enable evice awake interrupt */

/* bit field of ISOMODESEL register */
#define ISOMODESEL_D4           0x00000010      /* EP4ISO mode select */
#define ISOMODESEL_D5           0x00000020      /* EP5ISO mode select */

/* bit field of SYSCON register */
#define SYSCON_D0               0x00000001      /* Soft reset */
#define SYSCON_D1               0x00000002      /* Power-down mode */
#define SYSCON_D2               0x00000004      /* EP mode */
#define SYSCON_D3               0x00000008      /* Pull-up/pull-down */
#define SYSCON_D4               0x00000010      /* Remote wake up */

/* bit field of POLSEL register */
#define POLSEL_D4               0x00000010      /* USBINTN Porarity */

/* bit field of EP0CONF register */
#define EP0CONF_D4              0x00000010      /* Configuration bit */

/* bit field of EP1CONF register */
#define EP1CONF_D01             0x00000003      /* Transfer type */
#define EP1CONF_D4              0x00000010      /* Configuration bit */
#define EP1CONF_D7              0x00000080      /* Transfer direction */

/* bit field of EP2CONF register */
#define EP2CONF_D01             0x00000003      /* Transfer type */
#define EP2CONF_D4              0x00000010      /* Configuration bit */
#define EP2CONF_D7              0x00000080      /* Transfer direction */

/* bit field of EP3CONF register */
#define EP3CONF_D01             0x00000003      /* Transfer type */
#define EP3CONF_D4              0x00000010      /* Configuration bit */
#define EP3CONF_D7              0x00000080      /* Transfer direction */

/* bit field of EP4CONF register */
#define EP4CONF_D01             0x00000003      /* Transfer type */
#define EP4CONF_D4              0x00000010      /* Configuration bit */
#define EP4CONF_D7              0x00000080      /* Transfer direction */

/* bit field of EP5CONF register */
#define EP5CONF_D01             0x00000003      /* Transfer type */
#define EP5CONF_D4              0x00000010      /* Configuration bit */
#define EP5CONF_D7              0x00000080      /* Transfer direction */

/* bit field of EP0CONT register */
#define EP0CONT_D0              0x00000001      /* Stall bit */
#define EP0CONT_D1              0x00000002      /* Received data sequence toggle bit */
#define EP0CONT_D4              0x00000010      /* Transmitted data sequence toggle bit */

/* bit field of EP1CONT register */
#define EP1CONT_D0              0x00000001      /* Stall bit */
#define EP1CONT_D1              0x00000002      /* Data sequence toggle bit */
#define EP1CONT_D2              0x00000004      /* FIFO clear */

/* bit field of EP2CONT register */
#define EP2CONT_D0              0x00000001      /* Stall bit */
#define EP2CONT_D1              0x00000002      /* Data sequence toggle bit */
#define EP2CONT_D2              0x00000004      /* FIFO clear */

/* bit field of EP3CONT register */
#define EP3CONT_D0              0x00000001      /* Stall bit */
#define EP3CONT_D1              0x00000002      /* Data sequence toggle bit */
#define EP3CONT_D2              0x00000004      /* FIFO clear */

/* bit field of EP4CONT register */
#define EP4CONT_D0              0x00000001      /* Stall bit */
#define EP4CONT_D1              0x00000002      /* Data sequence toggle bit */
#define EP4CONT_D2              0x00000004      /* FIFO clear */

/* bit field of EP5CONT register */
#define EP5CONT_D0              0x00000001      /* Stall bit */
#define EP5CONT_D1              0x00000002      /* Data sequence toggle bit */
#define EP5CONT_D2              0x00000004      /* FIFO clear */

/* bit field of EP0PLD register */
#define EP0PLD_D05              0x0000003F      /* Maximum packet size */

/* bit field of EP1PLD register */
#define EP1PLD_D06              0x0000007F      /* Maximum packet size */

/* bit field of EP2PLD register */
#define EP2PLD_D06              0x0000007F      /* Maximum packet size */

/* bit field of EP3PLD register */
#define EP3PLD_D05              0x0000003F      /* Maximum packet size */

/* bit field of EP4PLD register */
#define EP4PLD_D07              0x000000FF      /* Maximum packet size LSB */

/* bit field of EP5PLD register */
#define EP5PLD_D06              0x0000007F      /* Maximum packet size LSB */

/* bit field of EP0RXCNT register */
#define EP0RXCNT_D05            0x0000003F      /* Received packet counter(byte) */

/* bit field of EP1RXCNT register */
#define EP1RXCNT_D06            0x0000007F      /* Received packet counter(byte) */

/* bit field of EP2RXCNT register */
#define EP2RXCNT_D06            0x0000007F      /* Received packet counter(byte) */

/* bit field of EP3RXCNT register */
#define EP3RXCNT_D05            0x0000003F      /* Received packet counter(byte) */

/* bit field of EP4RXCNT register */
#define EP4RXCNT_D07            0x000000FF      /* Received packet counter(byte) */

/* bit field of EP5RXCNT register */
#define EP5RXCNT_D07            0x000000FF      /* Received packet counter(byte) */

/* bit field of EP0STAT register */
#define EP0STAT_D0              0x00000001      /* Received packet ready */
#define EP0STAT_D1              0x00000002      /* Transmitted packet ready */
#define EP0STAT_D2              0x00000004      /* Setup ready  */
#define EP0STAT_D45             0x00000030      /* Stage bit */

/* bit field of EP1STAT register */
#define EP1STAT_D0              0x00000001      /* Received packet ready */
#define EP1STAT_D1              0x00000002      /* Transmitted packet ready */

/* bit field of EP2STAT register */
#define EP2STAT_D0              0x00000001      /* EP0 received packet ready */
#define EP2STAT_D1              0x00000002      /* EP0 Transmitted packet ready */

/* bit field of EP3STAT register */
#define EP3STAT_D0              0x00000001      /* Received packet ready */
#define EP3STAT_D1              0x00000002      /* Transmitted packet ready */

/* bit field of EP4STAT register */
#define EP4STAT_D0              0x00000001      /* Received packet ready */
#define EP4STAT_D1              0x00000002      /* Transmitted packet ready */

/* bit field of EP5STAT register */
#define EP5STAT_D0              0x00000001      /* Received packet ready */
#define EP5STAT_D1              0x00000002      /* Transmitted packet ready */


/*----------------------------------------------------------------------------
    The fields of ILC
----------------------------------------------------------------------------*/
#define IRQLEVELMAX	7
#define IRN_MASK	0x1Ful
#define ILR_MASK	0x7ul
#define ILR0		0x00000001ul
#define ILR1		0x00000010ul
#define ILR4		0x00010000ul
#define ILR6		0x01000000ul
#define ILR8		0x00000001ul
#define ILR9		0x00000010ul
#define ILR10		0x00000100ul
#define ILR11		0x00001000ul
#define ILR12		0x00010000ul
#define ILR13		0x00100000ul
#define ILR14		0x01000000ul
#define ILR15		0x10000000ul
#define ILR16		0x00000001ul
#define ILR18		0x00000010ul
#define ILR20		0x00000100ul
#define ILR22		0x00001000ul
#define ILR24		0x00010000ul
#define ILR26		0x00100000ul
#define ILR28		0x01000000ul
#define ILR30		0x10000000ul

/*----------------------------------------------------------------------------
    IRQ Number
----------------------------------------------------------------------------*/
#define STMIRQ		0			/* uPLAT System Timer */
#define WDTIRQ		1			/* Watchdog Timer */
#define GPIOAIRQ	4			/* GPIOA */
#define FPSPIRQ		6			/* FPSP */
#define SOFTIRQ		8			/* Software */
#define GPIOBIRQ	9			/* GPIOB */
#define UARTIRQ		10			/* UART */
#define SSIOIRQ		11			/* Synchronous SIO */
#define USBIRQ		12			/* USB */
#define SPIIRQ0		13			/* SPI Channel 0 */
#define SPIIRQ1		14			/* SPI Channel 1 */
#define SIMIFIRQ	15			/* SIM IF */
#define GPIOCIRQ	16			/* GPIOC */
#define TMRIRQ0		19			/* Timer Channel 0 */
#define TMRIRQ1		20			/* Timer Channel 1 */
#define TMRIRQ2		21			/* Timer Channel 2 */
#define DMAIRQ0		22			/* DMA Channel 0 */
#define DMAIRQ1		23			/* DMA Channel 1 */
#define EXTIRQ3		24			/* External INT 3 */
#define EXTIRQ2		26			/* External INT 2 */
#define EXTIRQ1		28			/* External INT 1 */
#define EXTIRQ0		30			/* External INT 0 */

/*----------------------------------------------------------------------------
    IRQ Number (alias )
----------------------------------------------------------------------------*/
#define INT_SYSTIMER		0
#define INT_WDT             1
    /* reserved             2   */
    /* reserved             3   */
#define INT_GPIOA           4
    /* reserved             5   */
#define INT_FPSP			6
    /* reserved             7   */
#define INT_SOFT            8
#define INT_GPIOB           9
#define INT_SIO             10
#define INT_SSIO            11
#define INT_USB             12
#define INT_SPI0            13
#define INT_SPI1            14
#define INT_SIMIF           15
#define INT_GPIOC           16
    /* reserved             17  */
    /* reserved             18  */
#define INT_TIMER0          19
#define INT_TIMER1          20
#define INT_TIMER2          21
#define INT_DMAC0           22
#define INT_DMAC1           23
#define EXINT_N3			24
    /* reserved             25  */
#define EXINT_N2			26
    /* reserved             27  */
#define EXINT_N1			28
    /* reserved             29  */
#define EXINT_N0			30
    /* reserved             31  */

#ifdef __cplusplus
};      /* End of 'extern "C"' */
#endif
#endif  /* End of ML67Q5250_H */

