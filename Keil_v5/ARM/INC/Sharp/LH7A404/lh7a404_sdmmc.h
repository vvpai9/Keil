/***********************************************************************
 * $Id:: lh7a404_sdmmc.h 14 2007-08-28 16:08:18Z kevinw                $
 *
 * Project: LH7A404 SD/MMC definitions
 *
 * Description:
 *     This file contains the structure definitions and manifest
 *     constants for the LH7A404 component:
 *         Secure Digital and Multi-Media Card Controller
 *
 ***********************************************************************
 * Software that is described herein is for illustrative purposes only  
 * which provides customers with programming information regarding the  
 * products. This software is supplied "AS IS" without any warranties.  
 * NXP Semiconductors assumes no responsibility or liability for the 
 * use of the software, conveys no license or title under any patent, 
 * copyright, or mask work right to the product. NXP Semiconductors 
 * reserves the right to make changes in the software without 
 * notification. NXP Semiconductors also make no representation or 
 * warranty that such application will be suitable for the specified 
 * use without further testing or modification. 
 **********************************************************************/

#ifndef LH7A404_SDMMC_H
#define LH7A404_SDMMC_H

#include "lpc_types.h"
#include "lh7a404_chip.h"

/***********************************************************************
 * SDMMC Module Register Structure
 **********************************************************************/

/* SDMMC Module Register Structure */ 
typedef struct 
{
    volatile UNS_32 clock_control; /* SDMMC Clock control register */ 
    volatile UNS_32 status;        /* SDMMC Controller status reg */ 
    volatile UNS_32 clock_rate;    /* SDMMC clock divider register */
    volatile UNS_32 clock_prediv;  /* SDMMC clock pre-divider reg */
    volatile UNS_32 reserved1;
    volatile UNS_32 cmd_control;   /* SDMMC Command control reg */
    volatile UNS_32 response_to;   /* SDMMC Response timeout reg */
    volatile UNS_32 read_to;       /* SDMMC Read timeout register */
    volatile UNS_32 block_len;     /* SDMMC Block length register */
    volatile UNS_32 block_count;   /* SDMMC Block count register */ 
    volatile UNS_32 int_status;    /* SDMMC Interrupt status reg */
    volatile UNS_32 int_clear;     /* SDMMC Interrupt clear reg */ 
    volatile UNS_32 reserved2;
    volatile UNS_32 int_enable;    /* SDMMC Interrupt enable register */
    volatile UNS_32 command;       /* SDMMC Command Number register */
    volatile UNS_32 argument;      /* SDMMC Command Argument register */
    volatile UNS_32 response_fifo; /* SDMMC Response FIFO register */
    volatile UNS_32 reserved3;
    volatile UNS_32 data_fifo;     /* SDMMC Data FIFO register */
    volatile UNS_32 reserved4;
} SDMMC_REGS_T;

/***********************************************************************
 * SDMMC clock control start/stop register definitions
 **********************************************************************/

/* SDMMC clock start/stop register stop clock bit */
#define MMC_CTRL_STOP_CLK                0x00000001
/* SDMMC clock start/stop register start clock bit */
#define MMC_CTRL_START_CLK               0x00000002

/***********************************************************************
 * MMC status register definitions
 **********************************************************************/

/* SDMMC status register read timeout bit */
#define MMC_STATUS_READ_TO               0x00000001
/* SDMMC status register response timeout bit */
#define MMC_STATUS_RESPONSE_TO           0x00000002
/* SDMMC status register CRC write error bit */
#define MMC_STATUS_CRC_ERROR_WRITE       0x00000004
/* SDMMC status register CRC read error bit */
#define MMC_STATUS_CRC_ERROR_READ        0x00000008
/* SDMMC status register SPI read error token bit */
#define MMC_STATUS_CRC_ERROR_RESPONSE    0x00000020
/* SDMMC status register FIFO empty bit */
#define MMC_STATUS_FIFO_EMPTY            0x00000040
/* SDMMC status register FIFO full bit */
#define MMC_STATUS_FIFO_FULL             0x00000080
/* SDMMC status register clock stopped bit */
#define MMC_STATUS_CLOCK_STOPPED         0x00000100
/* SDMMC status register data transfer done bit */
#define MMC_STATUS_DATA_TRANSFER_DONE    0x00000800
/* SDMMC status register program done bit */
#define MMC_STATUS_PROGRAM_DONE          0x00001000
/* SDMMC status register command response complete bit */
#define MMC_STATUS_END_COMMAND_RESPONSE  0x00002000

/***********************************************************************
 * SDMMC clock rate register definitions
 **********************************************************************/

/* SDMMC clock rate register load macro */
#define MMC_CLOCK_RATE(n)                _SBF(0, ((n) & 0x7))
/* SDMMC clock rate register divide by 1 load value */
#define MMC_CLOCK_DIV1                   0
/* SDMMC clock rate register divide by 2 load value */
#define MMC_CLOCK_DIV2                   1
/* SDMMC clock rate register divide by 4 load value */
#define MMC_CLOCK_DIV4                   2
/* SDMMC clock rate register divide by 8 load value */
#define MMC_CLOCK_DIV8                   3
/* SDMMC clock rate register divide by 16 load value */
#define MMC_CLOCK_DIV16                  4
/* SDMMC clock rate register divide by 32 load value */
#define MMC_CLOCK_DIV32                  5
/* SDMMC clock rate register divide by 64 load value */
#define MMC_CLOCK_DIV64                  6

/***********************************************************************
 * SDMMC clock predivide register definitions
 **********************************************************************/

/* SDMMC clock predivide register load macro - use a value between
   1 and 8 */
#define MMC_PREDIV(n)                    _SBF(0, ((n) & 0xF))
/* SDMMC clock predivide MMC clock gate bit */
#define MMC_PREDIV_EN                     0x00000010
/* SDMMC clock predivide APB read enable bit */
#define MMC_PREDIV_APB_RD_EN              0x00000020

/***********************************************************************
 * SDMMC command/data register definitions
 **********************************************************************/

/* SDMMC command/data register response format none value */
#define MMC_CMD_RESPONSE_NONE             _SBF(0, 0x0)
/* SDMMC command/data register response format R1 value */
#define MMC_CMD_RESPONSE_R1               _SBF(0, 0x1)
/* SDMMC command/data register response format R2 value */
#define MMC_CMD_RESPONSE_R2               _SBF(0, 0x2)
/* SDMMC command/data register response format R3 value */
#define MMC_CMD_RESPONSE_R3               _SBF(0, 0x3)
/* SDMMC command/data register data enable bit */
#define MMC_CMD_DATA_EN                   0x00000004
/* SDMMC command/data register write enable bit */
#define MMC_CMD_WRITE                     0x00000008
/* SDMMC command/data register stream enable bit */
#define MMC_CMD_STREAM                    0x00000010
/* SDMMC command/data register busy signal expectation bit */
#define MMC_CMD_BUSY                      0x00000020
/* SDMMC command/data register initialize enable bit */
#define MMC_CMD_INITIALIZE                0x00000040
/* SDMMC command/data register SD wide mode enable bit */
#define MMC_CMD_WIDE                      0x00000080
/* SDMMC command/data register big endian mode enable bit */
#define MMC_CMD_BIG_ENDIAN                0x00000100
/* SDMMC command/data SDIO mode enable bit */
#define MMC_CMD_SDIO_ENABLE               0x00000200
/* SDMMC command/data read wait state enable bit */
#define MMC_CMD_RWS_ENABLE                0x00000400
/* SDMMC command/data multi-block interrupt enable bit */
#define MMC_CMD_MBI_ENABLE                0x00000800
/* SDMMC command/data transaction mode read/write bit */
#define MMC_CMD_WRITE_TRANS               0x00001000
/* SDMMC command/data transaction abort bit */
#define MMC_CMD_ABORT                     0x00002000

/***********************************************************************
 * SDMMC response timeout register definitions
 **********************************************************************/

/* SDMMC response timeout register load macro */
#define MMC_RESPONSE_TO(n)                ((n) & 0x0000007F)

/***********************************************************************
 * SDMMC read timeout register definitions
 **********************************************************************/

/* SDMMC read timeout register load macro */
#define MMC_READ_TO(n)                    ((n) & 0x0000FFFF)

/***********************************************************************
 * SDMMC block length register definitions
 **********************************************************************/

/* SDMMC block length register load macro */
#define MMC_BLOCK_LEN(n)                  ((n) & 0x000003FF)

/***********************************************************************
 * SDMMC block count register definitions
 **********************************************************************/

/* SDMMC block count register load macro */
#define MMC_BLOCK_COUNT(n)                ((n) & 0x0000FFFF)

/***********************************************************************
 * SDMMC interrupt/clear/mask register definitions
 **********************************************************************/

/* SDMMC interrupt/clear/mask register data transfer done bit */
#define MMC_INT_DATA_TRANSFER_DONE        0x00000001
/* SDMMC interrupt/clear/mask register program done bit */
#define MMC_INT_PROGRAM_DONE              0x00000002
/* SDMMC interrupt/clear/mask register end command bit */
#define MMC_INT_END_CMD_RESPONSE          0x00000004
/* SDMMC interrupt/clear/mask register buffer ready bit */
#define MMC_INT_BUFFER_READY              0x00000008
/* SDMMC interrupt/clear/mask register bus clock stopped bit */
#define MMC_INT_CLOCK_STOPPED             0x00000010
/* SDMMC interrupt/clear/mask register SDIO interrupt bit */
#define MMC_INT_SDIO_INT                  0x00000020

/***********************************************************************
 * SDMMC command number register definitions
 **********************************************************************/
                                          
/* SDMMC command number register load macro */
#define MMC_CMD_NUM(n)                    _SBF(0, ((n) & 0x3F))

/* Macro pointing to interrupt controller registers */
#define SDMMC ((SDMMC_REGS_T *)(SDMMC_BASE))

#endif /* LH7A404_SDMMC_H */ 
