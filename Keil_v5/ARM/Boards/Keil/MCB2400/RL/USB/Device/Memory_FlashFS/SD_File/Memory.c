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

#include <LPC24xx.H>                        /* LPC23xx/LPC24xx definitions */

#include <RTL.h>
#include <File_Config.h>
#include <rl_usb.h>

#include "SD_File.h"
#include "Memory.h"


/* I2C definitions */
#define I2C_AA      0x00000004              /* I2C Assert acknowledge flag */
#define I2C_SI      0x00000008              /* I2C interrupt flag */
#define I2C_STO     0x00000010              /* I2C STOP flag */
#define I2C_STA     0x00000020              /* I2C START flag */
#define I2C_I2EN    0x00000040              /* I2C enable */

U32 LED_State = 0;                          /* reflect the LEDs */
FAT_VI *mc0;                                /* Media Control Block */
Media_INFO info;

/*------------------------------------------------------------------------------
  Initialize the I2C interface
 *------------------------------------------------------------------------------*/
void I2C_Init (void) {
  PCONP    |=  (1 << 7);                    /* Enable clock for I2C0 */

  PINSEL1  &= ~0x03C00000;                  /* P0.27 SDA, P0.28 SCL */
  PINSEL1  |=  0x01400000;                  /* PINSEL1 22.23, 24.25 */
  
  I20CONCLR =  I2C_AA  | I2C_SI | 
               I2C_STA | I2C_I2EN;          /* Clear I2C state machine */

  I20SCLL   =  0x80;                        /* Setup I2C clock speed */
  I20SCLH   =  0x80;

  I20CONSET =  I2C_I2EN;
  I20CONSET =  I2C_STO;
}


/*------------------------------------------------------------------------------
  Set value to LEDs
 *------------------------------------------------------------------------------*/
void LED_Set (unsigned int value) {
  unsigned int val = (value & LED_MSK);     /* only 4 bits are used */

  I20CONCLR =  I2C_AA | I2C_SI | I2C_STA | I2C_STO;
  I20CONSET =  I2C_STA;
  while (!(I20CONSET & I2C_SI));            /* Wait for START */
  I20DAT    =  0xC0;                        /* write to device 0xC0 */
  I20CONCLR =  I2C_SI | I2C_STA;
  while (!(I20CONSET & I2C_SI));            /* Wait for ADDRESS send */
  I20DAT    =  0x18;                        /* select LS2 register */
  I20CONCLR =  I2C_SI;
  while (!(I20CONSET & I2C_SI));            /* Wait for DATA send */
  I20DAT    =  (0x01 * ((val >> 0) & 1)) |	/* set data */
               (0x04 * ((val >> 1) & 1)) |
               (0x10 * ((val >> 2) & 1)) |
               (0x40 * ((val >> 3) & 1)) ;
	I20CONCLR =  I2C_SI;
  while (!(I20CONSET & I2C_SI));            /* Wait for DATA send */
  I20CONSET =  I2C_STO;
  I20CONCLR =  I2C_SI;
  while (I20CONSET & I2C_STO);              /* Wait for STOP */
}


/*------------------------------------------------------------------------------
  WakeUp Event (INT0 Key)
 *------------------------------------------------------------------------------*/
volatile BOOL WakeUp   = __FALSE;           /* WakeUp Event */
volatile BOOL EINT0_Key = __FALSE;          /* EINT0 Key Active */


/*------------------------------------------------------------------------------
  Timer0 IRQ (happens every 50ms)
 *------------------------------------------------------------------------------*/
__irq void T0_IRQHandler (void) {
  BOOL key;

  key = ((FIO2PIN & (1 << 10)) == 0);
  if (key && !EINT0_Key) {
    WakeUp = __TRUE;
  }
  EINT0_Key = key;

  T0IR = 1;                                 /* Clear interrupt flag  */
  VICVectAddr = 0;                          /* Acknowledge Interrupt */
}


/*------------------------------------------------------------------------------
  Switch on LEDs
 *------------------------------------------------------------------------------*/
void LED_On (unsigned int value) {

  LED_State |= value;
  LED_Set(LED_State);
}


/*------------------------------------------------------------------------------
  Switch off LEDs
 *------------------------------------------------------------------------------*/
void LED_Off (unsigned int value) {

  LED_State &= ~value;
  LED_Set(LED_State);
}


/*------------------------------------------------------------------------------
  Main Program
 *------------------------------------------------------------------------------*/
int main (void) {
  BOOL usb_initialized = __FALSE;

  /* Enable and setup timer interrupt, start timer */
  T0MR0         = 50*12000-1;               /* 50msec at 12.0 MHz          */
  T0MCR         = 3;                        /* Interrupt and Reset on MR0  */
  T0TCR         = 1;                        /* Timer0 Enable               */
  VICVectAddr4  = (U32)T0_IRQHandler;       /* Set Interrupt Vector        */
  VICVectCntl4  = 15;                       /* use it for Timer0 Interrupt */
  VICIntEnable  = (1  << 4);                /* Enable Timer0 Interrupt     */

  init_serial();                            /* Initialize Serial Port */
  I2C_Init();                               /* LED Push Button interface */

  while (1) {
    if (WakeUp) {
      WakeUp = __FALSE;
      usbd_connect(__FALSE);                /* USB Device Disconnect */
      LED_Off(LED_MSK);
                                            /* Term Interface */
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
                                            /* PC Interface */
      } else {
        LED_On(LED_MSK);                    /* Card Failure! */
      }
      while (!WakeUp);
    }
  }
}
