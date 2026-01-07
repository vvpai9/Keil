/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2003                           */
/***********************************************************************/
/*                                                                     */
/*  SF.H:  Header file for Special Functions                           */
/*                                                                     */
/***********************************************************************/

#ifndef __SF_H
#define __SF_H


/*--------------*/
/* SF Registers */
/*--------------*/
#define SF_CIDR    REG(SF_BASE + 0x00) /* Chip Identification Register */
#define SF_EXID    REG(SF_BASE + 0x04) /* Chip Identification Extension */
#define SF_RSR     REG(SF_BASE + 0x08) /* Reset Status Register */
#ifdef AT91R40807
#define SF_MMR     REG(SF_BASE + 0x0C) /* Memory Mode Register */
#endif
#define SF_PMR     REG(SF_BASE + 0x18) /* Protect Mode Register */


/*---------------------------------------*/
/* SF_CIDR: Chip Identification Register */
/*---------------------------------------*/

#define SF_VERSION         0x1F        /* Version Number */

#define SF_NVPSIZ          (0x0F<<8)   /* Non Volatile Program Memory Size */
#define SF_NVPSIZ_NONE     (0x00<<8)   /* None */
#define SF_NVPSIZ_32K      (0x03<<8)   /* 32K Bytes */
#define SF_NVPSIZ_64K      (0x05<<8)   /* 64K Bytes */
#define SF_NVPSIZ_128K     (0x07<<8)   /* 128K Bytes */
#define SF_NVPSIZ_256K     (0x09<<8)   /* 256K Bytes */

#define SF_NVDSIZ          (0x0F<<12)  /* Non Volatile Data Memory Size */
#define SF_NVDSIZ_NONE     (0x00<<12)  /* None */

#define SF_VDSIZ           (0x0F<<16)  /* Volatile Data Memory Size */
#define SF_VDSIZ_NONE      (0x00<<16)  /* None */
#define SF_VDSIZ_1K        (0x01<<16)  /* 1K Bytes */
#define SF_VDSIZ_2K        (0x02<<16)  /* 2K Bytes */
#define SF_VDSIZ_3K        (0x03<<16)  /* 3K Bytes */
#define SF_VDSIZ_4K        (0x04<<16)  /* 4K Bytes */
#define SF_VDSIZ_8K        (0x08<<16)  /* 8K Bytes */

#define SF_ARCH            (0xFF<<20)  /* Architecture Code */
#define SF_ARCH_AT91x40    (0x40<<20)  /* AT91x40yyy */
#define SF_ARCH_AT91x43    (0x43<<20)  /* AT91x43yyy */
#define SF_ARCH_AT91x63    (0x63<<20)  /* AT91x63yyy */
#define SF_ARCH_AT91x42    (0x42<<20)  /* AT91x42yyy */
#define SF_ARCH_AT91x55    (0x55<<20)  /* AT91x55yyy */

#define SF_NVPTYP          (0x07<<28)  /* Non Volatile Program Memory Type */
#define SF_NVPTYP_M        (0x01<<28)  /* M or F series */
#define SF_NVPTYP_C        (0x02<<28)  /* C series */
#define SF_NVPTYP_S        (0x03<<28)  /* S series */
#define SF_NVPTYP_R        (0x04<<28)  /* R series */

#define SF_EXT             (1<<31)     /* Extension Flag */

/*-------------------------------*/
/* SF_RSR: Reset Status Register */
/*-------------------------------*/

#define SF_EXT_RESET       0x6C        /* External Pin Reset */
#define SF_WD_RESET        0x53        /* Internal Watchdog Reset */

/*-----------------------------------------------------------------*/
/* SF_MMR: Memory Mode Register - Defined only for the AT91R40807  */
/*-----------------------------------------------------------------*/
#ifdef AT91R40807
#define SF_RAMWU           (1<<0)      /* Internal XRAM Write Detection */
#endif

/*-------------------------------*/
/* SF_PMR: Protect Mode Register */
/*-------------------------------*/
#define SF_AIC             (1<<5)      /* AIC Protect Mode Enable */
#define SF_PMRKEY          (0x27A8<<16)/* Protect Mode Register Key */


#endif /* __SF_H */
