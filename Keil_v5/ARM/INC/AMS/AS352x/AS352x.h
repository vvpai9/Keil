/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2007                           */
/***********************************************************************/
/*                                                                     */
/*  AS352x.H: Header file for AustriaMicroSystems AS352x               */
/*                                                                     */
/***********************************************************************/

#ifndef __AS352x_H
#define __AS352x_H

#include "include\sdk_base_addresses.h"
#include "include\as3525_events.h"
#include "include\as3525_interrupts.h"
#include "include\as3525_registers.h"

#include "drv_ccu\ccu_registers.h"
#include "drv_cgu\cgu_registers.h"
#include "drv_dbop\dbop_registers.h"
#include "drv_dma\dmac_registers.h"
#include "drv_gpio\gpio_registers.h"
#include "drv_i2c\i2c_registers.h"
#include "drv_i2s\i2sin_registers.h"
#include "drv_i2s\i2sout_registers.h"
#include "drv_ide\ide_registers.h"
#include "drv_naf\naf_registers.h"
#include "drv_sd_mmc\sd_const.h"
#include "drv_sd_mmc\sd_hwl_driver.h"
#include "drv_ssp\ssp_registers.h"
#include "drv_timer\timer_registers.h"
#include "drv_uart\uart_registers.h"
#include "drv_usb\usb_registers.h"
#include "drv_wdt\wdt_registers.h"

/* Register access definitions                                         */
#define Reg8(adr)  (*((volatile unsigned char  *) (adr)))
#define Reg16(adr) (*((volatile unsigned short *) (adr)))
#define Reg32(adr) (*((volatile unsigned long  *) (adr)))

#endif /* __AS352x_H */
