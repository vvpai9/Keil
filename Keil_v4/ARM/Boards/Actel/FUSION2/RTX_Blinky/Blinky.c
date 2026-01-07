/*----------------------------------------------------------------------------
 *      R T L   K e r n e l   E x a m p l e
 *----------------------------------------------------------------------------
 *      Name:    BLINKY.C
 *      Purpose: RTX example program
 *      Rev.:    V3.40
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2009 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <RTL.h>
#include <A2FM3Fxxx.h>                  /* A2FM3Fxxx Registers               */


OS_TID t_blink;                         /* assigned task id of task: blink   */
OS_TID t_ledoff;                        /* assigned task id of task: ledoff  */


/*----------------------------------------------------------------------------
 *        Task 1 'blink': Blinks LED
 *---------------------------------------------------------------------------*/
__task void blink (void) {
  for (;;) {
    GPIO->GPOUT &= ~(1 << 6);           /* Turn LED On  (GPIO6 = 0)          */
    os_evt_set (0x0001, t_ledoff);      /* send event to task 'ledoff'       */
    os_dly_wait (50);                   /* delay 50 clock ticks              */
  }
}

/*----------------------------------------------------------------------------
 *        Task 2 'blink_off': Blinks LED
 *---------------------------------------------------------------------------*/
__task void ledoff (void) {
  for (;;) {
    os_evt_wait_and (0x0001, 0xffff);   /* wait for an event flag 0x0001     */
    os_dly_wait (8);                    /* delay 8 clock ticks               */
    GPIO->GPOUT |=  (1 << 6);           /* Turn LED Off (GPIO6 = 0)          */
  }
}

/*----------------------------------------------------------------------------
 *        Task 3 'init': Initialize
 *---------------------------------------------------------------------------*/
__task void init (void) {

  GPIO->CONFIG_6 = 5;                    /* Setup GPIO6 as output for LED    */

  t_blink  = os_tsk_create (blink, 0);   /* start task 'blink'               */
  t_ledoff = os_tsk_create (ledoff, 0);  /* start task 'ledoff'              */
  os_tsk_delete_self ();
}

/*----------------------------------------------------------------------------
 *        Main: Initialize and start RTX Kernel
 *---------------------------------------------------------------------------*/
int main (void) {
  WATCHDOG->WDOGENABLE = 0x4C6E55FA;    /* Disable the watchdog              */

  SystemInit();                         /* Initialize the MCU clocks         */

  os_sys_init (init);                   /* Initialize RTX and start init     */
}

/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/

