/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::Drivers:NAND
 * Copyright (c) 2004-2013 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    OneNAND.h
 * Purpose: OneNAND Flash Device connected to Memory Bus Definitions
 * Rev.:    V5.00
 *----------------------------------------------------------------------------*/

#ifndef __ONE_NAND_H
#define __ONE_NAND_H


/*-----------------------------------------------------------------------------
 *      OneNAND Device Specific Definitions
 *----------------------------------------------------------------------------*/

/* OneNAND Data/Spare Address Map */
#define ONENAND_D0BUF_ADDR      0x000400    /* DataRAM 0 User Area Address    */
#define ONENAND_S0BUF_ADDR      0x010020    /* DataRAM 0 Spare Area Address   */
#define ONENAND_D1BUF_ADDR      0x000C00    /* DataRAM 1 User Area Address    */
#define ONENAND_S1BUF_ADDR      0x010060    /* DataRAM 1 Spare Area Address   */

/* OneNAND Register Address Map */
#define ONENAND_REG_MAN_ID      0x01E000    /* Manufacturer ID                */
#define ONENAND_REG_DEV_ID      0x01E002    /* Device ID                      */
#define ONENAND_REG_DBF_SZ      0x01E006    /* Data buffer size               */
#define ONENAND_REG_BBF_SZ      0x01E008    /* Boot buffer size               */
#define ONENAND_REG_DBF_AM      0x01E00A    /* Data/Boot buffer amount        */
#define ONENAND_REG_TECH        0x01E00C    /* Info about technology          */
#define ONENAND_REG_SA_1        0x01E200    /* NAND Flash Block Address       */
#define ONENAND_REG_SA_2        0x01E202    /* N/A, reserved                  */
#define ONENAND_REG_SA_3        0x01E204    /* Copyback program dest BA       */
#define ONENAND_REG_SA_4        0x01E206    /* Copyback program desc PA,SA    */
#define ONENAND_REG_SA_5        0x01E208    /* N/A, reserved                  */
#define ONENAND_REG_SA_6        0x01E20A    /* N/A, reserved                  */
#define ONENAND_REG_SA_7        0x01E20C    /* N/A, reserved                  */
#define ONENAND_REG_SA_8        0x01E20E    /* NAND Page & Sector Address     */
#define ONENAND_REG_ST_BUF      0x01E400    /* Buffer number for Page Data    */
#define ONENAND_REG_CMD         0x01E440    /* Ctrl/Mem operation commands    */
#define ONENAND_REG_CFG_1       0x01E442    /* System Configuration 1         */
#define ONENAND_REG_CFG_2       0x01E444    /* System Configuration 2         */
#define ONENAND_REG_STAT        0x01E480    /* Controller Status/Results      */
#define ONENAND_REG_INT         0x01E482    /* Command Completion ISR Status  */
#define ONENAND_REG_SBA         0x01E498    /* Start Block Address            */
#define ONENAND_REG_WPS         0x01E49C    /* Write Protection Status        */
#define ONENAND_REG_ECC_ST      0x01FE00    /* ECC Status of sector           */

/* OneNAND Commands */
#define ONENAND_CMD_LDM_BUF     0x00        /* Load main area into buffer     */
#define ONENAND_CMD_LDS_BUF     0x13        /* Load spare area into buffer    */
#define ONENAND_CMD_PRG_BUF     0x80        /* Program from buffer to NAND    */
#define ONENAND_CMD_CPY_BACK    0x1B        /* Copyback program operation     */
#define ONENAND_CMD_UNLOCK      0x23        /* Unlock NAND array a block      */
#define ONENAND_CMD_ERASE       0x94        /* Block erase                    */
#define ONENAND_CMD_RST_COR     0xF0        /* Reset NAND Flash Core          */
#define ONENAND_CMD_RST_HOT     0xF3        /* Reset OneNAND == Hot reset     */

// OneNAND Status Flags Masks (OneNAND, Flex OneNAND)
#define ONENAND_STAT_ONGO       0x8000      /* Internal device status         */
#define ONENAND_STAT_ERROR      0x0400      /* Load, Program and Erase status */
#define ONENAND_STAT_OTPL       0x0040      /* OTP Lock status                */
#define ONENAND_STAT_OTPBL      0x0020      /* 1st Block OTP Lock status      */
#define ONENAND_STAT_TO         0x0001      /* Time Out                       */

/* OneNAND Flags */
#define ONENAND_FLAG_ISR_INT    (1<<15)     /* Master interrupt bit (INT)     */


/*-----------------------------------------------------------------------------
 *      OneNAND Page Layout Definitions
 *----------------------------------------------------------------------------*/

/* Page Data Layout */
#define ONENAND_SECTOR_INCREMENT    512     /* Sector address increment       */
#define ONENAND_SPARE_OFFSET        2048    /* Spare address offset           */
#define ONENAND_SPARE_INCREMENT     16      /* Spare address increment        */

/* Spare Info Data Layout */
#define ONENAND_OFFSET_LSN          2       /* Logical Sector Number offset   */
#define ONENAND_OFFSET_DCM          1       /* Data Corrupted Marker offset   */
#define ONENAND_OFFSET_BBM          0       /* Bad Block Marker offset        */
#define ONENAND_OFFSET_ECC          8       /* ECC data bytes offset          */


#endif /* __ONE_NAND_H */
