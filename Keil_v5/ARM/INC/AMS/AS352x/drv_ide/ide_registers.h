/*
 *****************************************************************************
 * Copyright @ 2007 by austriamicrosystems AG                                *
 * All rights are reserved.                                                  *
 *                                                                           *
 * Reproduction in whole or in part is prohibited without the written consent*
 * of the copyright owner. Austriamicrosystems reserves the right to make    *
 * changes without notice at any time. The software is provided as is and    *
 * Austriamicrosystems makes no warranty, expressed, implied or statutory,   *
 * including but not limited to any implied warranty of merchantability or   *
 * fitness for any particular purpose, or that the use will not infringe any *
 * third party patent, copyright or trademark. Austriamicrosystems should    *
 * not be liable for any loss or damage arising from its use.                *
 *****************************************************************************
 */

/*
 *      PROJECT:   AS353x
 *      $Revision: 759 $
 *      LANGUAGE:  ANSI C
*/

/*! \file
 *
 *  \author E. Schneeberger
 *
 *  \brief Definition of AS353x IDE registers.
 *
 *  Definition of AS353x IDE registers.
 *
 */
#ifndef IDE_REGISTERS_H
#define IDE_REGISTERS_H


/*
******************************************************************************
* INCLUDES
******************************************************************************
*/
#include "sdk_base_addresses.h"


/*
******************************************************************************
* MACROS
******************************************************************************
*/

/*! \def IDE_REG8
 *  8-bit access to the IDE register
 *  \def IDE_REG16
 *  16-bit access to the IDE register
 *  \def IDE_REG32
 *  32-bit access to the IDE register
 */

#define IDE_REG8(X)     (* ((volatile uint8  *)((REGISTER_BASE_CF_IDE) + X)))
#define IDE_REG16(X)    (* ((volatile uint16 *)((REGISTER_BASE_CF_IDE) + X)))
#define IDE_REG32(X)    (* ((volatile uint32 *)((REGISTER_BASE_CF_IDE) + X)))


/*
******************************************************************************
* DEFINES
******************************************************************************
*/

/*! \def IDEREG_BMICP
 *  R/W Primary Channel Bus Master IDE Command Register, when the block is
 *  configured as primary channel.
 *  \def IDEREG_BMISP
 *  R/W Primary Channel Bus Master IDE Status Register, when the block is
 *  configured as primary channel.
 *  \def IDEREG_BMIDTPP
 *  R/W Primary Channel Bus Master Table Pointer Register, when the block is
 *  configured as primary channel.
 *  \def IDEREG_BMIDTPP_LO
 *  Primary Channel Bus Master Table Pointer Register 16 access, lower bits
 *  \def IDEREG_BMIDTPP_HI
 *  Primary Channel Bus Master Table Pointer Register 16 access, upper bits
 *  \def IDEREG_IDETIMP
 *  R/W  Primary IDE Channel Timing Register
 *  \def IDEREG_IDETIMP_LO
 *  Primary IDE Channel Timing Registe lower bits (8)
 *  \def IDEREG_IDETIMP_HI
 *  Primary IDE Channel Timing Registe upper bits (8)
 *  \def IDEREG_IDETIMS
 *  R/W     Secondary IDE Channel Timing Register
 *  \def IDEREG_IDETIMS_LO
 *  Secondary IDE Channel Timing Register lower bits (8)
 *  \def IDEREG_IDETIMS_HI
 *  Secondary IDE Channel Timing Register upper bits (8)
 *  \def IDEREG_SL_IDETIM
 *  Slave IDE Timing Register
 *  \def IDEREG_SLEWCTL_LO
 *  R/W     IDE Slew Rate Control Register (configuration option) lower bits (8)
 *  \def IDEREG_SLEWCTL_HI
 *  R/W     IDE Slew Rate Control Register (configuration option) upper bits (8)
 *  \def IDEREG_IDESTAT
 *  R       IDE Status Register
 *  \def IDEREG_UDMACTL
 *  R/W     Ultra DMA Control Register
 *  \def IDEREG_UDMATIM
 *  R/W     Ultra DMA Timing Register
 *  \def IDEREG_UDMATIM_LO
 *  R/W     Ultra DMA Timing Register lower bits (8)
 *  \def IDEREG_UDMATIM_HI
 *  R/W     Ultra DMA Timing Register upper bits (8)
 *  \def IDEREG_MISCCTL
 *  R/W     Miscellaneous Control Register
 *  \def IDEREG_REGSTB
 *  R/W     Task File Register Strobe Timing Register
 *  \def IDEREG_REGRCVR
 *  R/W     Task File Register Recovery Timing Register
 *  \def IDEREG_DATSTB
 *  R/W     Data Register PIO Strobe Timing Register
 *  \def IDEREG_DATRCVR
 *  R/W     Data Register PIO Recovery Timing Register
 *  \def IDEREG_DMASTB
 *  R/W     DMA Strobe Timing Register
 *  \def IDEREG_DMARCVR
 *  R/W     DMA Recovery Timing Register
 *  \def IDEREG_UDMASTB
 *  R/W     Ultra DMA Strobe Timing Register
 *  \def IDEREG_UDMATRP
 *  R/W     Ultra DMA Ready-to-Stop Timing Register
 *  \def IDEREG_UDMATENV
 *  R/W     Ultra DMA Timing Envelope Register
 *  \def IDEREG_IORDYTMP
 *  R/W     Primary IO Ready Timer Configuration Register
 *  \def IDEREG_IORDYTMS
 *  R/W     Secondary IO Ready Timer Configuration Register
 */

/* DMA Engine Registers                                                      */
#define IDEREG_BMICP                IDE_REG16(0x00)
#define IDEREG_BMISP                IDE_REG16(0x02)
#define IDEREG_BMIDTPP              IDE_REG32(0x04)
#define IDEREG_BMIDTPP_LO           IDE_REG16(0x04)
#define IDEREG_BMIDTPP_HI           IDE_REG16(0x06)
/* Configuration Registers                                                   */
#define IDEREG_IDETIMP              IDE_REG16(0x40)
#define IDEREG_IDETIMP_LO           IDE_REG8(0x40)
#define IDEREG_IDETIMP_HI           IDE_REG8(0x41)
#define IDEREG_IDETIMS              IDE_REG16(0x42)
#define IDEREG_IDETIMS_LO           IDE_REG8(0x42)
#define IDEREG_IDETIMS_HI           IDE_REG8(0x43)
#define IDEREG_SL_IDETIM            IDE_REG8(0x44)
#define IDEREG_SLEWCTL_LO           IDE_REG8(0x45)
#define IDEREG_SLEWCTL_HI           IDE_REG8(0x46)
#define IDEREG_IDESTAT              IDE_REG8(0x47)
#define IDEREG_UDMACTL              IDE_REG8(0x48)
#define IDEREG_UDMATIM              IDE_REG16(0x4A)
#define IDEREG_UDMATIM_LO           IDE_REG8(0x4A)
#define IDEREG_UDMATIM_HI           IDE_REG8(0x4B)

#define IDEREG_MISCCTL              IDE_REG32(0x50)
#define IDEREG_REGSTB               IDE_REG32(0x54)
#define IDEREG_REGRCVR              IDE_REG32(0x58)
#define IDEREG_DATSTB               IDE_REG32(0x5C)
#define IDEREG_DATRCVR              IDE_REG32(0x60)
#define IDEREG_DMASTB               IDE_REG32(0x64)
#define IDEREG_DMARCVR              IDE_REG32(0x68)
#define IDEREG_UDMASTB              IDE_REG32(0x6C)
#define IDEREG_UDMATRP              IDE_REG32(0x70)
#define IDEREG_UDMATENV             IDE_REG32(0x74)
#define IDEREG_IORDYTMP             IDE_REG32(0x78)
#define IDEREG_IORDYTMS             IDE_REG32(0x7C)

/* primary Task File Registers (implemented on external IDE device)          */
#define IdeTaskF_DATA               IDE_REG8(0x1F0)
#define IdeTaskF_ERR_FEAT           IDE_REG8(0x1F1)
#define IdeTaskF_SECT_CNT           IDE_REG8(0x1F2)
#define IdeTaskF_SECT_NUM           IDE_REG8(0x1F3)
#define IdeTaskF_CYL_LO             IDE_REG8(0x1F4)
#define IdeTaskF_CYL_HI             IDE_REG8(0x1F5)
#define IdeTaskF_DEV_HEAD           IDE_REG8(0x1F6)
#define IdeTaskF_STAT_CMD           IDE_REG8(0x1F7)

#define IdeTaskF_ALT_STAT_DEV_CTRL  IDE_REG8(0x3F6)
#define IdeTaskF_DEV_ADDR           IDE_REG8(0x3F7)

/*secondary IDE channel registers       */
#define IDEREG_BMICS                IDE_REG16(0x08)
#define IDEREG_BMISS                IDE_REG16(0x0A)
#define IDEREG_BMIDTPS              IDE_REG32(0x0C)
#define IDEREG_BMIDTPS_LO           IDE_REG16(0x0C)
#define IDEREG_BMIDTPS_HI           IDE_REG16(0x0E)

#endif /* IDE_REGISTERS_H                                                    */


