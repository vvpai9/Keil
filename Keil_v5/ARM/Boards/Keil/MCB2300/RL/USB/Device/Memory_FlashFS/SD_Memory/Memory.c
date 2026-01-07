/*----------------------------------------------------------------------------
 *      RL-ARM - USB
 *----------------------------------------------------------------------------
 *      Name:    Memory.c
 *      Purpose: USB Memory Storage Demo
 *      Rev.:    V4.70
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2013 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <LPC23xx.H>                        /* LPC23xx/LPC24xx definitions */

#include <RTL.h>
#include <File_Config.h>
#include <rl_usb.h>

#include "Memory.h"
#include "LCD.h"

FAT_VI *mc0;                                /* Media Control Block */
Media_INFO info;

/*------------------------------------------------------------------------------
  Switch on LEDs
 *------------------------------------------------------------------------------*/
void LED_On (unsigned int value) {

  FIO2SET = (value);                        /* Turn On  LED */
}


/*------------------------------------------------------------------------------
  Switch off LEDs
 *------------------------------------------------------------------------------*/
void LED_Off (unsigned int value) {

  FIO2CLR = (value);                        /* Turn Off LED */
}


/*------------------------------------------------------------------------------
  Main Program
 *------------------------------------------------------------------------------*/
int main (void) {
  PINSEL10 = 0;                             /* Disable ETM interface */
  FIO2DIR |= LED_MSK;                       /* LEDs, port 2, bit 0~7 output only */

  lcd_init();                               /* LCD Initialization */
  lcd_clear();
  lcd_print ("MCB2300 MSD Demo");
  set_cursor (0, 1);
  lcd_print ("  www.keil.com  ");

  mc0 = ioc_getcb (NULL);
  if (ioc_init (mc0) == 0) {
    ioc_read_info (&info, mc0);
    usbd_init();                            /* USB Device Initialization */
    usbd_connect(__TRUE);                   /* USB Device Connect */
  } else {
    set_cursor (0, 1);
    lcd_print (" Card Failure!  ");
  }
  while (1);
}
