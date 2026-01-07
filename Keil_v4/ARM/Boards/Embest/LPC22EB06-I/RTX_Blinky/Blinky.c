/*----------------------------------------------------------------------------
 *      R T L   K e r n e l   E x a m p l e
 *----------------------------------------------------------------------------
 *      Name:    BLINKY.C
 *      Purpose: RTX example program
 *      Rev.:    V3.12
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2007 KEIL - An ARM Company. All rights reserved. 
 *---------------------------------------------------------------------------*/

#include <RTL.h>
#include <LPC22xx.h>                    /* LPC22xx Peripheral Registers      */


OS_TID t_blink1;                         /* assigned task id of task: blink1   */
OS_TID t_blink2;                         /* assigned task id of task: blink2   */

/*----------------------------------------------------------------------------
 *        Task 1 'blink1': Blinks LED
 *---------------------------------------------------------------------------*/
__task void blink1(void) {
  for (;;) {

	IOSET2 = 0x01800000;    
    IOCLR2 = 0x01000000;                   
              

    os_dly_wait (15);                  /* delay 15 clock ticks              */
	IOSET2 = 0x01800000;    
    IOCLR2 = 0x01000000;                    
            


  }
}

/*----------------------------------------------------------------------------
 *        Task2 'blink2': Blinks LED
 *---------------------------------------------------------------------------*/

__task void blink2(void) {
  for (;;) {
  
    IOSET2 = 0x01800000;     
    IOCLR2 = 0x00800000;                  
          

    os_dly_wait (20);                   /* delay 20 clock ticks              */
    IOSET2 = 0x00800000;     
    IOCLR2 = 0x01000000;                   
  }
}



/*----------------------------------------------------------------------------
 *        Task 3 'init': Initialize
 *---------------------------------------------------------------------------*/
__task void init (void) {

  IODIR2 = 0x00000030;         
  t_blink1  = os_tsk_create (blink1, 2);   /* start task 'blink1'               */
  t_blink2  = os_tsk_create (blink2, 1);   /* start task 'blink2'               */
  os_tsk_delete_self ();
}

/*----------------------------------------------------------------------------
 *        Main: Initialize and start RTX Kernel
 *---------------------------------------------------------------------------*/
int main (void) {
  os_sys_init (init);                   /* Initialize RTX and start init     */
}

/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/

