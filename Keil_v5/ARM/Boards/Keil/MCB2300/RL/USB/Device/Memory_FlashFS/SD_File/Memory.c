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

#include "SD_File.h"
#include "Memory.h"
#include "LCD.h"

FAT_VI *mc0;                                /* Media Control Block */
Media_INFO info;

/*------------------------------------------------------------------------------
  WakeUp Event (INT0 Key)
 *------------------------------------------------------------------------------*/
volatile BOOL WakeUp   = __FALSE;           /* WakeUp Event */
volatile BOOL INT0_Key = __FALSE;           /* INT0 Key Active */


/*------------------------------------------------------------------------------
  Timer0 IRQ (happens every 50ms)
 *------------------------------------------------------------------------------*/
__irq void T0_IRQHandler (void) {
  BOOL key;

  key = ((FIO2PIN & (1 << 10)) == 0);
  if (key && !INT0_Key) {
    WakeUp = __TRUE;
  }
  INT0_Key = key;

  T0IR = 1;                                 /* Clear interrupt flag  */
  VICVectAddr = 0;                          /* Acknowledge Interrupt */
}


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
  BOOL usb_initialized = __FALSE;

  PINSEL10 = 0;                             /* Disable ETM interface */
  FIO2DIR |= LED_MSK;                       /* LEDs, port 2, bit 0~7 output only */

  /* Enable and setup timer interrupt, start timer */
  T0MR0         = 50*12000-1;               /* 50msec at 12.0 MHz          */
  T0MCR         = 3;                        /* Interrupt and Reset on MR0  */
  T0TCR         = 1;                        /* Timer0 Enable               */
  VICVectAddr4  = (U32)T0_IRQHandler;       /* Set Interrupt Vector        */
  VICVectCntl4  = 15;                       /* use it for Timer0 Interrupt */
  VICIntEnable  = (1  << 4);                /* Enable Timer0 Interrupt     */

  init_serial();                            /* Initialize Serial Port */

  lcd_init();                               /* LCD Initialization */
  lcd_clear();
  lcd_print ("MCB2300 MSD Demo");

  while (1) {
    if (WakeUp) {
      WakeUp = __FALSE;
      usbd_connect(__FALSE);                /* USB Device Disconnect */
      LED_Off(LED_MSK);
      set_cursor (0, 1);
      lcd_print (" Term Interface ");       /* Term Interface */
      sd_main();
    } else {
      mc0 = ioc_getcb (NULL);
      if (ioc_init (mc0) == 0) {
        ioc_read_info (&info, mc0);
        if (usb_initialized == __FALSE) {
          usbd_init();                      /* USB Device Initialization */
          usb_initialized = __TRUE;
        } else {
          usbd_msc_init();
        }
        usbd_connect(__TRUE);               /* USB Device Connect */
        set_cursor (0, 1);
        lcd_print ("  PC Interface  ");     /* PC Interface */
      } else {
        LED_On(LED_MSK);                    /* Card Failure! */
        set_cursor (0, 1);
        lcd_print (" Card Failure!  ");
      }
      while (!WakeUp);
    }
  }
}
