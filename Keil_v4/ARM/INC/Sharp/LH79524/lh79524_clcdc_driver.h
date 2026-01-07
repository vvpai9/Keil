/***********************************************************************
 * $Id:: lh79524_clcdc_driver.h 27 2007-08-31 19:35:06Z kevinw         $
 *
 * Project: LH79524 CLCDC driver
 *
 * Description:
 *     This file contains driver support for the CLCDC module on the
 *     LH79524
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


#ifndef LH79524_CLCDC_DRIVER_H
#define LH79524_CLCDC_DRIVER_H

#include "lpc_types.h"
#include "lpc_lcd_params.h"
#include "lh79524_clcdc.h"


/***********************************************************************
 * Color LCD controller driver structures
 **********************************************************************/

/* LCD driver control structure */
typedef struct CLCDC_S
{
  /* Lcd Base address  */ 
  void*      regs;
  /* Tft Base address  */ 
  void*      tft;
  /* Init status */
  BOOL_32    init;       
  /* Default irq handler */
  void*      irq_hdlr; 
  /* Callback method to be used by isr */
  PFI        callback;       
  /* Interrupt mask */
  UNS_32     imask;      
  /* Interrupt vector */
  UNS_32     ivec; 
  /* LCD input clock frequency in Hz */
  UNS_32     clcdclk;      
  /* Config params */ 
  void*      cfg;        
} CLCDC_T, *PCLCDC_T;

/* Structure containing the values used to program the 
   LCD controller */
typedef struct {
   LCD_PARAM_T*  lcdparam;
   UNS_32       board_xtal_in; 
} CLCDC_SETTINGS_T;

/***********************************************************************
 * Color LCD controller driver enumerations
 **********************************************************************/

/***********************************************************************
 * LCD device configuration commands (IOCTL commands and arguments)
 **********************************************************************/

/* LCD device commands (IOCTL commands) */
typedef enum {
  /* Enable the lcd controller */
  LCD_ENABLE = 0,
  /* Enable the lcd controller */
  LCD_DISABLE,
  /* Enable LCD power */
  LCD_PW_ENABLE,
  /* Disable LCD power */
  LCD_PW_DISABLE,
  /* Update the frame buffer pointer */
  LCD_SET_FB,
  /* Get the state of the controller - Enable or disabled */
  LCD_GET_STATUS,
  /* Mask interrupts */
  LCD_DISABLE_INT,
  /* UnMask interrupts */
  LCD_ENABLE_INT,
  /* Enable Vertical compare interrupts */
  LCD_ENABLE_VCOMP_INT,
  /* Disable Vertical compare interrupts */
  LCD_DISABLE_VCOMP_INT,
  /* Set the controller into BGR mode */
  LCD_SET_BGR,
  /* Set the controller into RGB mode */
  LCD_SET_RGB,
  /* Set DMA requests to start when 4 or 8 entries are free in the 
     CLCDC FIFOs, use arg = 1 for 4 entries, use arg = 0 for 8 */
  LCD_DMA_ON_4MT,  
  /* Return a pointer to the driver isr */
  LCD_GET_ISR,
  /* Bind a callback method to be used by the isr */
  LCD_SET_CALLBACK,
  /* LCD extended ioctl */
  LCD_EXTENDED_IOCTL
} LCD_IOCTLS_T;

/***********************************************************************
 * LCD driver API functions
 **********************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/* Open the LCD */
INT_32 lcd_open(INT_32 ipbase, INT_32 arg);

/* Close the LCD */
STATUS lcd_close(INT_32 devid);

/* LCD configuration block */
STATUS lcd_ioctl(INT_32 devid, INT_32 cmd, INT_32 arg);

/* LCD read function (stub only) */
INT_32 lcd_read(INT_32 devid, CHAR* buffer, INT_32 max_bytes);

/* LCD write function (stub only) */
INT_32 lcd_write(INT_32 devid, CHAR* buffer, INT_32 n_bytes);

/* Update the pixel clock */
void lcd_update_clock(UNS_32 desired_clock);

#ifdef __cplusplus
}
#endif

#endif /* LH79524_CLCDC_DRIVER_H */
