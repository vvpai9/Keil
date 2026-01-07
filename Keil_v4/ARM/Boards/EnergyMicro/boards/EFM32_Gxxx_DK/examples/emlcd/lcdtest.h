/**************************************************************************//**
 * @file
 * @brief LCD demo and test, prototypes and definitions
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

#ifndef _LCDTEST_H
#define _LCDTEST_H

#include "efm32.h"

/* Test patterns */
void LCD_ScrollText(LCD_TypeDef *lcd, char *scrolltext);
void LCD_Test(LCD_TypeDef *lcd);
void LCD_BlinkTest(LCD_TypeDef *lcd);

#endif
