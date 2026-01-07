/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2005                                  */
/******************************************************************************/
/*                                                                            */
/*  S3C4510.H:  Header file for Samsung S3C4510B                               */
/*                                                                            */
/******************************************************************************/

#ifndef __S3C4510_H
#define __S3C4510_H

#define SFR_BASE 0x3FF8000

#define S3C4510
  /* System Manager Group */
  #define SYSCFG   (*((volatile unsigned long *) (SFR_BASE + 0x0000)))
  #define CLKCFG   (*((volatile unsigned long *) (SFR_BASE + 0x3000)))
  #define EXTACON0 (*((volatile unsigned long *) (SFR_BASE + 0x3008)))
  #define EXTACON1 (*((volatile unsigned long *) (SFR_BASE + 0x300C)))
  #define EXTDBWTH (*((volatile unsigned long *) (SFR_BASE + 0x3010)))
  #define ROMCON0  (*((volatile unsigned long *) (SFR_BASE + 0x3014)))
  #define ROMCON1  (*((volatile unsigned long *) (SFR_BASE + 0x3018)))
  #define ROMCON2  (*((volatile unsigned long *) (SFR_BASE + 0x301C)))
  #define ROMCON3  (*((volatile unsigned long *) (SFR_BASE + 0x3020)))
  #define ROMCON4  (*((volatile unsigned long *) (SFR_BASE + 0x3024)))
  #define ROMCON5  (*((volatile unsigned long *) (SFR_BASE + 0x3028)))  
  #define DRAMCON0 (*((volatile unsigned long *) (SFR_BASE + 0x302C)))
  #define DRAMCON1 (*((volatile unsigned long *) (SFR_BASE + 0x3030)))
  #define DRAMCON2 (*((volatile unsigned long *) (SFR_BASE + 0x3034)))
  #define DRAMCON3 (*((volatile unsigned long *) (SFR_BASE + 0x3038)))  
  #define REFEXTCON (*((volatile unsigned long *)(SFR_BASE + 0x303C)))
  #define REFEXTCON (*((volatile unsigned long *)(SFR_BASE + 0x303C)))

  /* Ethernet Group */
  #define BDMATXCON (*((volatile unsigned long *) (SFR_BASE + 0x9000)))
  #define BDMARXCON (*((volatile unsigned long *) (SFR_BASE + 0x9004)))
  #define BDMATXPTR (*((volatile unsigned long *) (SFR_BASE + 0x9008)))
  #define BDMARXPTR (*((volatile unsigned long *) (SFR_BASE + 0x900C)))
  #define BDMARXLSZ (*((volatile unsigned long *) (SFR_BASE + 0x9010)))
  #define BDMASTAT  (*((volatile unsigned long *) (SFR_BASE + 0x9014)))
  #define CAM       (*((volatile unsigned short *) (SFR_BASE + 0x9100)))
  #define BDMATXBUF (*((volatile unsigned short *) (SFR_BASE + 0x9200)))  
  #define BDMARXBUF (*((volatile unsigned long *) (SFR_BASE + 0x9800)))  
  #define MACON     (*((volatile unsigned long *) (SFR_BASE + 0xA000)))  
  #define CAMCON    (*((volatile unsigned long *) (SFR_BASE + 0xA004)))  
  #define MACTXCON  (*((volatile unsigned long *) (SFR_BASE + 0xA008)))  
  #define MACTXSTAT (*((volatile unsigned long *) (SFR_BASE + 0xA00C)))  
  #define MACRXCON  (*((volatile unsigned long *) (SFR_BASE + 0xA010)))  
  #define MACRXSTAT (*((volatile unsigned long *) (SFR_BASE + 0xA014)))  
  #define STADATA   (*((volatile unsigned long *) (SFR_BASE + 0xA018)))  
  #define STACON    (*((volatile unsigned long *) (SFR_BASE + 0xA01C)))  
  #define CAMEN     (*((volatile unsigned long *) (SFR_BASE + 0xA028)))  
  #define EMISSCNT  (*((volatile unsigned long *) (SFR_BASE + 0xA03C)))  
  #define EPZCNT    (*((volatile unsigned long *) (SFR_BASE + 0xA040)))  
  #define ERMPZCNT  (*((volatile unsigned long *) (SFR_BASE + 0xA044)))  
  #define ETXSTAT   (*((volatile unsigned long *) (SFR_BASE + 0x9040)))  

  /* HDLC Channel A */
  #define HMODE_A     (*((volatile unsigned long *) (SFR_BASE + 0x7000)))
  #define HCON_A      (*((volatile unsigned long *) (SFR_BASE + 0x7004)))
  #define HSTAT_A     (*((volatile unsigned long *) (SFR_BASE + 0x7008)))
  #define HINTEN_A    (*((volatile unsigned long *) (SFR_BASE + 0x700C)))
  #define HTXFIFOC_A  (*((volatile unsigned long *) (SFR_BASE + 0x7010)))
  #define HTXFIFOT_A  (*((volatile unsigned long *) (SFR_BASE + 0x7014)))
  #define HRXFIFO_A   (*((volatile unsigned long *) (SFR_BASE + 0x7018)))
  #define HBRGTC_A    (*((volatile unsigned long *) (SFR_BASE + 0x701C)))  
  #define HPRMB_A     (*((volatile unsigned long *) (SFR_BASE + 0x7020)))  
  #define HSAR0_A     (*((volatile unsigned long *) (SFR_BASE + 0x7024)))  
  #define HSAR1_A     (*((volatile unsigned long *) (SFR_BASE + 0x7028)))  
  #define HSAR2_A     (*((volatile unsigned long *) (SFR_BASE + 0x702C)))  
  #define HSAR3_A     (*((volatile unsigned long *) (SFR_BASE + 0x7030)))  
  #define HMASK_A     (*((volatile unsigned long *) (SFR_BASE + 0x7034)))  
  #define DMATxPTR_A  (*((volatile unsigned long *) (SFR_BASE + 0x7038)))  
  #define DMARxPTR_A  (*((volatile unsigned long *) (SFR_BASE + 0x703C)))  
  #define HMFLR_A     (*((volatile unsigned long *) (SFR_BASE + 0x7040)))  
  #define HRBSR_A     (*((volatile unsigned long *) (SFR_BASE + 0x7044)))  

  /* HDLC Channel B */
  #define HMODE_B     (*((volatile unsigned long *) (SFR_BASE + 0x8000)))
  #define HCON_B      (*((volatile unsigned long *) (SFR_BASE + 0x8004)))
  #define HSTAT_B     (*((volatile unsigned long *) (SFR_BASE + 0x8008)))
  #define HINTEN_B    (*((volatile unsigned long *) (SFR_BASE + 0x800C)))
  #define HTXFIFOC_B  (*((volatile unsigned long *) (SFR_BASE + 0x8010)))
  #define HTXFIFOT_B  (*((volatile unsigned long *) (SFR_BASE + 0x8014)))
  #define HRXFIFO_B   (*((volatile unsigned long *) (SFR_BASE + 0x8018)))
  #define HBRGTC_B    (*((volatile unsigned long *) (SFR_BASE + 0x801C)))  
  #define HPRMB_B     (*((volatile unsigned long *) (SFR_BASE + 0x8020)))  
  #define HSAR0_B     (*((volatile unsigned long *) (SFR_BASE + 0x8024)))  
  #define HSAR1_B     (*((volatile unsigned long *) (SFR_BASE + 0x8028)))  
  #define HSAR2_B     (*((volatile unsigned long *) (SFR_BASE + 0x802C)))  
  #define HSAR3_B     (*((volatile unsigned long *) (SFR_BASE + 0x8030)))  
  #define HMASK_B     (*((volatile unsigned long *) (SFR_BASE + 0x8034)))  
  #define DMATxPTR_B  (*((volatile unsigned long *) (SFR_BASE + 0x8038)))  
  #define DMARxPTR_B  (*((volatile unsigned long *) (SFR_BASE + 0x803C)))  
  #define HMFLR_B     (*((volatile unsigned long *) (SFR_BASE + 0x8040)))  
  #define HRBSR_B     (*((volatile unsigned long *) (SFR_BASE + 0x8044)))

  /* I/O Ports */
  #define IOPMOD      (*((volatile unsigned long *) (SFR_BASE + 0x5000)))
  #define IOPCON      (*((volatile unsigned long *) (SFR_BASE + 0x5004)))  
  #define IOPDATA     (*((volatile unsigned long *) (SFR_BASE + 0x5008)))

  /* Interrupt Controller */
  #define INTMOD      (*((volatile unsigned long *) (SFR_BASE + 0x4000)))
  #define INTPND      (*((volatile unsigned long *) (SFR_BASE + 0x4004)))  
  #define INTMSK      (*((volatile unsigned long *) (SFR_BASE + 0x4008)))
  #define INTPRI0     (*((volatile unsigned long *) (SFR_BASE + 0x400C)))
  #define INTPRI1     (*((volatile unsigned long *) (SFR_BASE + 0x4010)))
  #define INTPRI2     (*((volatile unsigned long *) (SFR_BASE + 0x4014)))
  #define INTPRI3     (*((volatile unsigned long *) (SFR_BASE + 0x4018)))
  #define INTPRI4     (*((volatile unsigned long *) (SFR_BASE + 0x401C)))
  #define INTPRI5     (*((volatile unsigned long *) (SFR_BASE + 0x4020)))
  #define INTOFFSET   (*((volatile unsigned long *) (SFR_BASE + 0x4024)))
  #define INTOSET_FIQ (*((volatile unsigned long *) (SFR_BASE + 0x4030)))
  #define INTOSET_IRQ (*((volatile unsigned long *) (SFR_BASE + 0x4034)))

  /* I2C Bus */
  #define IICON       (*((volatile unsigned long *) (SFR_BASE + 0xF000)))
  #define IICBUF      (*((volatile unsigned long *) (SFR_BASE + 0xF004)))
  #define IICPS       (*((volatile unsigned long *) (SFR_BASE + 0xF008)))
  #define IICCOUNT    (*((volatile unsigned long *) (SFR_BASE + 0xF00C)))

  /* GDMA */
  #define GDMACON0    (*((volatile unsigned long *) (SFR_BASE + 0xB000)))
  #define GDMACON1    (*((volatile unsigned long *) (SFR_BASE + 0xC000)))
  #define GDMASRC0    (*((volatile unsigned long *) (SFR_BASE + 0xB004)))
  #define GDMADST0    (*((volatile unsigned long *) (SFR_BASE + 0xB008)))
  #define GDMASRC1    (*((volatile unsigned long *) (SFR_BASE + 0xC004)))
  #define GDMADST1    (*((volatile unsigned long *) (SFR_BASE + 0xC008)))
  #define GDMACNT0    (*((volatile unsigned long *) (SFR_BASE + 0xB00C)))
  #define GDMACNT1    (*((volatile unsigned long *) (SFR_BASE + 0xC00C)))

  /* I2C Bus */
  #define ULCON0      (*((volatile unsigned long *) (SFR_BASE + 0xD000)))
  #define ULCON1      (*((volatile unsigned long *) (SFR_BASE + 0xE000)))
  #define UCON0       (*((volatile unsigned long *) (SFR_BASE + 0xD004)))
  #define UCON1       (*((volatile unsigned long *) (SFR_BASE + 0xE004)))
  #define USTAT0      (*((volatile unsigned long *) (SFR_BASE + 0xD008)))
  #define USTAT1      (*((volatile unsigned long *) (SFR_BASE + 0xE008)))
  #define UTXBUF0     (*((volatile unsigned long *) (SFR_BASE + 0xD00C)))
  #define UTXBUF1     (*((volatile unsigned long *) (SFR_BASE + 0xE00C)))
  #define URXBUF0     (*((volatile unsigned long *) (SFR_BASE + 0xD00C)))
  #define URXBUF1     (*((volatile unsigned long *) (SFR_BASE + 0xD010)))
  #define UBRDIV0     (*((volatile unsigned long *) (SFR_BASE + 0xD014)))
  #define UBRDIV1     (*((volatile unsigned long *) (SFR_BASE + 0xE014)))

  /* Timers */
  #define TMOD        (*((volatile unsigned long *) (SFR_BASE + 0x6000)))
  #define TDATA0      (*((volatile unsigned long *) (SFR_BASE + 0x6004)))
  #define TDATA1      (*((volatile unsigned long *) (SFR_BASE + 0x6008)))
  #define TCNT0       (*((volatile unsigned long *) (SFR_BASE + 0x600C)))
  #define TCNT1       (*((volatile unsigned long *) (SFR_BASE + 0x6010)))

#endif /* __S3C4510_H */
