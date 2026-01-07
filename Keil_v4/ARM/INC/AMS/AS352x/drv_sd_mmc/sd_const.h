
/********************************************************************************/
/* Copyright @ 2004 by austriamicrosystems AG                                   */
/* All rights are reserved. Reproduction in whole or in part is                 */
/* prohibited without the written consent of the copyright owner.               */
/* austriamicrosystems reserves the right to make changes without notice at     */
/* any time. The software is provided as is and austriamicrosystems makes       */
/* no warranty, expressed, implied or statutory, including but not limited to   */
/* any implied warranty of merchantability or fitness for any particular        */
/* purpose, or that the use will not infringe any third party patent, copyright */
/* or trademark. Austriamicrosystems should not be liable for any loss or       */
/* damage arising from its use.                                                 */
/********************************************************************************/

/**
 *        PROJECT: AS353x             
 *      COPYRIGHT: austriamicrosystems 2004   
 *      $Revision: 759 $                      
 *          $Date: 2007/03/05 12:13:51 $      
 *         AUTHOR: P. Marinsek
 *     SUBSTITUTE: M. Barjaktarevic
 *       LANGUAGE: C
 *    DESCRIPTION: Multi Media Card Driver - definition of constants
 *                 
 **/
#ifndef _SD_CONST_H_
#define _SD_CONST_H_

/*
 * Description:
 * Mask of bits for CID
 */
#define bsMCI_CID_RCA           ( (UWORD32) 16)     /*relative card address*/

#define bwMCI_OCR_BUSY          ( (UWORD32) 1)      /*busy bit in voltage checking*/
#define bsMCI_OCR_BUSY          ( (UWORD32) 31)

#define bwMCI_OCR_VOLTAGE       ( (UWORD32) 24)     /*defined voltage level*/
#define bsMCI_OCR_VOLTAGE       ( (UWORD32) 0)

/*
 * Description:
 * Bit offsets and masks in CID register
 */
#define bsMCI_CID_MID          120         /*Manufacturer ID*/
#define bwMCI_CID_MID            8         /*Manufacturer ID*/
#define bsMCI_CID_OID          104         /*Application ID*/
#define bwMCI_CID_OID           16         /*Application ID*/
#define bsMCI_SD_CID_PNM_H      96         /*Product Name upper one ASCII chars*/
#define bwMCI_SD_CID_PNM_H       8         /*Product Name*/
#define bsMCI_SD_CID_PNM_L      64         /*Product Name lower four ASCII chars*/
#define bwMCI_SD_CID_PNM_L      32         /*Product Name*/
#define bsMCI_SD_CID_PRV        56         /*Product Revision*/
#define bwMCI_SD_CID_PRV         8         /*Product Revision*/
#define bsMCI_SD_CID_PSN        24         /*Product Serial Number*/
#define bwMCI_SD_CID_PSN        32         /*Product Serial Number*/
#define bsMCI_SD_CID_MDT         8         /*Manufacturing Date*/
#define bwMCI_SD_CID_MDT        12         /*Manufacturing Date*/
#define bsMCI_CID_PNM_H         88         /*Product Name upper two ASCII chars*/
#define bwMCI_CID_PNM_H         16         /*Product Name*/
#define bsMCI_CID_PNM_L         56         /*Product Name lower four ASCII chars*/
#define bwMCI_CID_PNM_L         32         /*Product Name*/
#define bsMCI_CID_PRV           48         /*Product Revision*/
#define bwMCI_CID_PRV            8         /*Product Revision*/
#define bsMCI_CID_PSN           16         /*Product Serial Number*/
#define bwMCI_CID_PSN           32         /*Product Serial Number*/
#define bsMCI_CID_MDT            8         /*Manufacturing Date*/
#define bwMCI_CID_MDT            8         /*Manufacturing Date*/

/*
 * Description:
 * Bit offsets and masks in Card Specific Data
 */
#define bsMCI_CSD_STRUCTURE        126      /*CSD structure*/
#define bwMCI_CSD_STRUCTURE          2      /*CSD structure*/
#define bsMCI_CSD_SPEC_VERS        122      /*System specification version*/
#define bwMCI_CSD_SPEC_VERS          4      /*System specification version*/
#define bsMCI_CSD_TAACHI           115      /*asynch data access time*/
#define bwMCI_CSD_TAACHI             4      /*asynch data access time*/
#define bsMCI_CSD_TAACLO           112      /*asynch data access time*/
#define bwMCI_CSD_TAACLO             3      /*asynch data access time*/
#define bsMCI_CSD_NSAC             104      /*clocked data access time*/
#define bwMCI_CSD_NSAC               8      /*clocked data access time*/
#define bsMCI_CSD_MAXTRANHI         99      /*maximum transfer speed (high bits)*/
#define bwMCI_CSD_MAXTRANHI          4      /*maximum transfer speed (high bits)*/
#define bsMCI_CSD_MAXTRANLO         96      /*maximum transfer speed (low bits)*/
#define bwMCI_CSD_MAXTRANLO          3      /*maximum transfer speed (low bits)*/
#define bsMCI_CSD_CCC               84      /*card command classes supported*/
#define bwMCI_CSD_CCC               12      /*card command classes supported*/
#define bsMCI_CSD_RDBL              80      /*read block length*/
#define bwMCI_CSD_RDBL               4      /*read block length*/
#define bsMCI_CSD_RDBLP             79      /*read block partial allowed*/
#define bwMCI_CSD_RDBLP              1      /*read block partial allowed*/
#define bsMCI_CSD_WTBLMIS           78      /*read block misalign allowed*/
#define bwMCI_CSD_WTBLMIS            1      /*read block misalign allowed*/
#define bsMCI_CSD_RDBLMIS           77      /*read block misalign allowed*/
#define bwMCI_CSD_RDBLMIS            1      /*read block misalign allowed*/
#define bsMCI_CSD_DSR_IMP           76      /*DSR implimented*/
#define bwMCI_CSD_DSR_IMP            1      /*DSR implimented*/
#define bsMCI_CSD_CSIZE             62      /*card size*/
#define bsMCI_CSD_CSIZE_v2_0        48      /*card size (CSD v2.0) */
#define bwMCI_CSD_CSIZE             12      /*card size*/
#define bwMCI_CSD_CSIZE_v2_0        22      /*card size (CSD v2.0) */
#define bsMCI_CSD_CMULT             47      /*card multiplier*/
#define bwMCI_CSD_CMULT              3      /*card multiplier*/
#define bsMCI_CSD_ERASE_SECT        42      /*size of erase sector*/
#define bwMCI_CSD_ERASE_SECT         5      /*size of erase sector*/
#define bsMCI_CSD_ERASE_SECT_SD     39      /*size of erase sector for SD*/
#define bwMCI_CSD_ERASE_SECT_SD      7      /*size of erase sector for SD*/
#define bsMCI_CSD_ERASE_GRP         37      /*size of erase group*/
#define bwMCI_CSD_ERASE_GRP          5      /*size of erase group*/
#define bsMCI_CSD_WP_GRP_SIZE       32      /*write protect group size*/
#define bwMCI_CSD_WP_GRP_SIZE        5      /*write protect group size*/
#define bsMCI_CSD_WP_GRP_ENABLE     31      /*write protect group enable*/
#define bwMCI_CSD_WP_GRP_ENABLE      1      /*write protect group enable*/

#define bsMCI_CSD_ERASE_GRP_SIZE11  42      /* CSD v1.1 */
#define bwMCI_CSD_ERASE_GRP_SIZE11   5
#define bsMCI_CSD_ERASE_GRP_MULT11  37
#define bwMCI_CSD_ERASE_GRP_MULT11   5
#define bsMCI_CSD_WP_GRP_SIZE11     32
#define bwMCI_CSD_WP_GRP_SIZE11      5

#define bsMCI_CSD_R2W               26      /*Read/Write factor*/
#define bwMCI_CSD_R2W                3      /*Read/Write factor*/
#define bsMCI_CSD_WTBL              22      /*write block length*/
#define bwMCI_CSD_WTBL               4      /*write block length*/
#define bsMCI_CSD_WTBLP             21      /*write block partial allowed*/
#define bwMCI_CSD_WTBLP              1      /*write block partial allowed*/
#define bsMCI_CSD_FILE_FORMAT_GRP   15      /*file format group*/
#define bwMCI_CSD_FILE_FORMAT_GRP    1      /*file format group*/
#define bsMCI_CSD_COPY              14      /*copy flag (OTP)*/
#define bwMCI_CSD_COPY               1      /*copy flag (OTP)*/
#define bsMCI_CSD_PERM_WP           13      /*permanent write protect*/
#define bwMCI_CSD_PERM_WP            1      /*permanent write protect*/
#define bsMCI_CSD_TEMP_WP           12      /*temporary write protect*/
#define bwMCI_CSD_TEMP_WP            1      /*temporary write protect*/
#define bsMCI_CSD_FILE_FORMAT       10      /*file format*/
#define bwMCI_CSD_FILE_FORMAT        2      /*file format*/
#define bsMCI_CSD_CAN_ERASE          5      /*card supports erase commands (bit within MCI_CCC)*/
#define bwMCI_CSD_CAN_ERASE          1      /*card supports erase commands*/
#define bsMCI_CSD_ERASE_SINGLE_BLOCK_ENABLE 46
#define bwMCI_CSD_ERASE_SINGLE_BLOCK_ENABLE 1
#define bsMCI_CSD_C_SIZE_MULT 47
#define bwMCI_CSD_C_SIZE_MULT 2
#define bsMCI_CSD_VDD_W_CURR_MAX 50
#define bwMCI_CSD_VDD_W_CURR_MAX 3
#define bsMCI_CSD_VDD_W_CURR_MIN 53
#define bwMCI_CSD_VDD_W_CURR_MIN 3
#define bsMCI_CSD_VDD_R_CURR_MAX 56
#define bwMCI_CSD_VDD_R_CURR_MAX 3
#define bsMCI_CSD_VDD_R_CURR_MIN 59
#define bwMCI_CSD_VDD_R_CURR_MIN 3
#define bsMCI_CSD_CRC 1
#define bwMCI_CSD_CRC 7

/*
 * Description:
 * Bit offsets and masks in SCR register
 */
#define MCI_SCR_BYTE_LENGTH 8         /* total length of SCR in bytes */
#define bsMCI_SCR_SCR_STRUCTURE 60
#define bwMCI_SCR_SCR_STRUCTURE 4
#define bsMCI_SCR_SD_SPEC 56
#define bwMCI_SCR_SD_SPEC 4
#define bsMCI_SCR_DATA_STAT_AFTER_ERASE 55
#define bwMCI_SCR_DATA_STAT_AFTER_ERASE 1
#define bsMCI_SCR_SD_SECURITY 52
#define bwMCI_SCR_SD_SECURITY 3
#define bsMCI_SCR_SD_BUS_WIDTH1 48
#define bwMCI_SCR_SD_BUS_WIDTH1 1
#define bsMCI_SCR_SD_BUS_WIDTH4 50
#define bwMCI_SCR_SD_BUS_WIDTH4 1

/*
 * Description:
 * Bit Masks for on-card status (R1 response)
 */
#define bwMCI_CARD_STATE        ( (UWORD32) 4)        /*CURRENT_STATE response*/
#define bsMCI_CARD_STATE        ( (UWORD32) 9)        /*CURRENT_STATE response*/
#define bwMCI_CARD_READY        ( (UWORD32) 1)        /*ready for data*/
#define bsMCI_CARD_READY        ( (UWORD32) 8)        /*ready for data*/
#define MCI_CARD_ERASE_FAIL     ( (UWORD32) 0xFDFF8000) /*erase failure mask*/
#define bwMCI_CARD_DATA_FAIL    ( (UWORD32) (4))      /*failure in data transfer*/
#define bsMCI_CARD_DATA_FAIL    ( (UWORD32) (14))     /*failure in data transfer*/
#define bwMCI_CARD_ANY_FAIL     ( (UWORD32) 8 )       /*any failure reported by card*/
#define bsMCI_CARD_ANY_FAIL     ( (UWORD32) 17 )

/*
 * Description:
 * Bit offsets and masks in SD Status
 */
#define MCI_SDSTATUS_BYTE_LENGTH 64         /* total length of SD Status in bytes */
#define bsMCI_SDSTATUS_DAT_BUS_WIDTH 510
#define bwMCI_SDSTATUS_DAT_BUS_WIDTH 2
#define bsMCI_SDSTATUS_SECURED_MODE 509
#define bwMCI_SDSTATUS_SECURED_MODE 1
#define bsMCI_SDSTATUS_SD_CARD_TYPE 480
#define bwMCI_SDSTATUS_SD_CARD_TYPE 16
#define bsMCI_SDSTATUS_SIZE_OF_PROTECTED_AREA 448
#define bwMCI_SDSTATUS_SIZE_OF_PROTECTED_AREA 32

/*
 * Description:
 * This constant specifies the voltage to used by the cards and is the bit to be set as
 * defined in multimedia card spec version 3.2
 */
#define SD_USE_VOLTAGE  23
#define SD_USE_HCS      30

/*
 * Description:
 *  mask bits for CMD8
 */
#define CMD8_VOLTAGE         0x1
#define CMD8_CHECK_PATTERN   0xAA

/*
 * Description:
 * Bit offsets and masks for Data registers
 */
#define bsMCI_DATA_LENGTH      ( (UWORD32) 0)
#define bwMCI_DATA_LENGTH      ( (UWORD32) 16)

#define bsMCI_DATA_ENABLE      ( (UWORD32) 0)
#define bwMCI_DATA_ENABLE      ( (UWORD32) 1)
#define bsMCI_DATA_DIRECTION   ( (UWORD32) 1)
#define bwMCI_DATA_DIRECTION   ( (UWORD32) 1)
#define bsMCI_DATA_MODE        ( (UWORD32) 2)
#define bwMCI_DATA_MODE        ( (UWORD32) 1)
#define bsMCI_DATA_DMA_ENABLE  ( (UWORD32) 3)
#define bwMCI_DATA_DMA_ENABLE  ( (UWORD32) 1)
#define bsMCI_DATA_BLOCKSIZE   ( (UWORD32) 4)
#define bwMCI_DATA_BLOCKSIZE   ( (UWORD32) 4)

/*
 * Description:
 * On-card states
 */
typedef enum MCI_xCardState
{
    MCI_CARD_IDLE=0,
    MCI_CARD_READY,
    MCI_CARD_IDENT,
    MCI_CARD_STBY,
    MCI_CARD_TRAN,
    MCI_CARD_DATA,
    MCI_CARD_RCV,
    MCI_CARD_PRG,
    MCI_CARD_DIS,
    MCI_CARD_IGNORE         /*dummy entry*/
} sdCardState_t;

#endif /* _SD_MMC_DRIVER_H_ */


