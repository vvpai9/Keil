/*----------------------------------------------------------------------------
 *      R T L   K e r n e l   E x a m p l e
 *----------------------------------------------------------------------------
 *      Name:    BLINKY.C
 *      Purpose: RTX example program
 *      Rev.:    V3.40
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2008 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <RTL.h>
#include <LM3Sxxxx.H>

OS_TID t_lights;                              /* assigned task id's          */
OS_TID t_keyread;
OS_TID t_blinking;

#define RED     0x01
#define YELLOW  0x02
#define GREEN   0x04
#define STOP    0x08
#define WALK    0x10

BIT normal_mode;

__task void init (void);                      /* Function prototypes         */
__task void blinking (void);
__task void lights (void);
__task void keyread (void);

/*--------------------------- LED_Out ---------------------------------------*/

static void LED_Out (U32 led) {
  GPIOPinWrite (GPIO_PORTB_BASE, GPIO_PIN_0, led >> 4);
  GPIOPinWrite (GPIO_PORTD_BASE, GPIO_PIN_0 | GPIO_PIN_1 |
                                 GPIO_PIN_2 | GPIO_PIN_3, led);
}

/*----------------------------------------------------------------------------
 *      Task 1 'lights': Normal Traffic light operation
 *---------------------------------------------------------------------------*/
__task void lights (void) {
  while (1) {                                 /* endless loop                */
    LED_Out (RED|STOP);                       /* RED & STOP lights on        */
    os_dly_wait (50);                         /* wait for timeout: 50 ticks  */
    if (normal_mode == __FALSE) {             /* if traffic signal time over */
      os_tsk_create (blinking, 0);            /* start blinking              */
      os_tsk_delete_self ();                  /* STOP lights                 */
    }
    LED_Out (RED|STOP|YELLOW);
    os_dly_wait (50);                         /* wait for timeout: 50 ticks  */
    LED_Out (STOP|GREEN);                     /* GREEN light for cars        */
    os_evt_clr (0x0010, t_lights);
    os_dly_wait (50);                         /* wait for timeout: 50 ticks  */
    os_evt_wait_and (0x0010, 750);            /* wait for event with timeout */
    LED_Out (STOP|YELLOW);                    /* timeout value: 750 ticks    */
    os_dly_wait (50);                         /* wait for timeout: 50 ticks  */
    LED_Out (STOP|RED);                       /* RED light for cars          */
    os_dly_wait (50);                         /* wait for timeout: 50 ticks  */
    LED_Out (WALK|RED);                       /* GREEN light for walkers     */    
    os_dly_wait (250);                        /* wait for timeout: 250 ticks */
  }
}

/*----------------------------------------------------------------------------
 *      Task 2 'blinking': runs outside normal traffic light operation
 *---------------------------------------------------------------------------*/
__task void blinking (void) {                 /* blink YELLOW light          */
  while (1) {                                 /* endless loop                */
    LED_Out (YELLOW);                         /* YELLOW light on             */
    os_dly_wait (30);                         /* wait for timeout: 30 ticks  */
    LED_Out (0);                              /* YELLOW light off            */
    os_dly_wait (30);                         /* wait for timeout: 30 ticks  */
    if (normal_mode == __TRUE) {              /* if blinking time over       */
      t_lights = os_tsk_create (lights, 0);   /* start lights                */
      os_tsk_delete_self ();                  /* and STOP blinking           */
    }
  }
}

/*----------------------------------------------------------------------------
 *      Task 3 'keyread': process key stroke from pedestrian push button
 *---------------------------------------------------------------------------*/
__task void keyread (void) {
  U32 val;

  while (1) {                                 /* endless loop                */
    val = GPIOPinRead (GPIO_PORTC_BASE, GPIO_PIN_4);
    if (val != 0) {                           /* if key pressed              */
      os_evt_set (0x0010, t_lights);          /* send signal to task lights  */
    }
    os_dly_wait (5);                          /* wait for timeout: 5 ticks   */
  }
}

/*----------------------------------------------------------------------------
 *        Task 5 'init': Initialize
 *---------------------------------------------------------------------------*/
__task void init (void) {

  /* Set the clocking to run directly from the crystal                       */
  SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | 
                 SYSCTL_OSC_MAIN | SYSCTL_XTAL_6MHZ);

  /* Set LED pins as outputs */
  SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOB |
                          SYSCTL_PERIPH_GPIOC |
                          SYSCTL_PERIPH_GPIOD);
  GPIODirModeSet(GPIO_PORTB_BASE, GPIO_PIN_0, GPIO_DIR_MODE_OUT);
  GPIODirModeSet(GPIO_PORTC_BASE, GPIO_PIN_4, GPIO_DIR_MODE_IN);
  GPIODirModeSet(GPIO_PORTD_BASE, GPIO_PIN_0 | GPIO_PIN_1 |
                                  GPIO_PIN_2 | GPIO_PIN_3, GPIO_DIR_MODE_OUT);

  normal_mode = __FALSE;
  t_blinking  = os_tsk_create (blinking,0);   /* start blinking              */
  t_keyread   = os_tsk_create (keyread,0);    /* start keyread task          */
  os_dly_wait (500);
  normal_mode = __TRUE;
  os_tsk_delete_self ();
}

/*----------------------------------------------------------------------------
 *        Main: Initialize and start RTX Kernel
 *---------------------------------------------------------------------------*/
int main (void) {

  os_sys_init (init);                    /* Initialize RTX and start init    */
}

/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/

