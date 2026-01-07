/**************************************************************************//**
 * @file
 * @brief LEUART prototypes and definitions
 * @author Energy Micro AS
 * @version v1.0.0
 ******************************************************************************
 * @section License
 * <b>(C) Copyright 2009 Energy Micro AS, http://www.energymicro.com</b>
 ******************************************************************************
 *
 * This source code is the property of Energy Micro AS. The source and compiled
 * code may only be used on Energy Micro "EFM32" microcontrollers.
 *
 * This copyright notice may not be removed from the source code nor changed.
 *
 * DISCLAIMER OF WARRANTY/LIMITATION OF REMEDIES: Energy Micro AS has no
 * obligation to support this Software. Energy Micro AS is providing the
 * Software "AS IS", with no express or implied warranties of any kind,
 * including, but not limited to, any implied warranties of merchantability
 * or fitness for any particular purpose or warranties against infringement
 * of any proprietary rights of a third party.
 *
 * Energy Micro AS will not be liable for any consequential, incidental, or
 * special damages, or any other relief, or for any claim by any third party,
 * arising from your use of this Software.
 *
 *****************************************************************************/

#ifndef _LEUART_H
#define _LEUART_H

#include <stdint.h>
#include "efm32.h"

int LEUART1_txByte(uint8_t data);
int LEUART1_rxByte(void);
int LEUART1_txBuf(uint8_t *buffer, int length);
int LEUART1_rxBuf(uint8_t *buffer, int length);
void LEUART1_init(int baudrate, int databits, int parity, int stopbits);

#endif
