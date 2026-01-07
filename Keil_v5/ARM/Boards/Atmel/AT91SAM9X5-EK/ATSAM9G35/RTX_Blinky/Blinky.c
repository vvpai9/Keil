/*----------------------------------------------------------------------------
 *      RL-ARM - RTX
 *----------------------------------------------------------------------------
 *      Name:    BLINKY.C
 *      Purpose: RTX example program
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2011 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <RTL.h>
#include <AT91SAM9G35.H>                /* AT91SAM9G35 definitions           */

OS_TID t_phaseA;                        /* assigned task id of task: phase_a */
OS_TID t_phaseB;                        /* assigned task id of task: phase_b */


/*----------------------------------------------------------------------------
 *        Function 'signal_func' called from multiple tasks
 *---------------------------------------------------------------------------*/
void signal_func (OS_TID task)  {
  os_dly_wait (100);                     /* delay 100 clock ticks            */
  os_evt_set (0x0001, task);             /* send event to task 'task'        */
  os_dly_wait (50);                      /* delay 50 clock ticks             */
}

/*----------------------------------------------------------------------------
 *        Task 1 'phaseA': Phase A output
 *---------------------------------------------------------------------------*/
__task void phaseA (void) {
  for (;;) {
    os_evt_wait_and (0x0001, 0xffff);    /* wait for an event flag 0x0001    */
    PIOD->PIO_SODR |= PIO_OER_P21;       /* Clear the LED        */
    signal_func (t_phaseB);              /* call common signal function      */
    PIOD->PIO_CODR |= PIO_OER_P21;
  }
}

/*----------------------------------------------------------------------------
 *        Task 2 'phaseB': Phase B output
 *---------------------------------------------------------------------------*/
__task void phaseB (void) {
  for (;;) {
    os_evt_wait_and (0x0001, 0xffff);    /* wait for an event flag 0x0001    */
    PIOB->PIO_CODR |= PIO_OER_P18;
    signal_func (t_phaseA);              /* call common signal function      */
    PIOB->PIO_SODR |= PIO_OER_P18;
  }
}

/*----------------------------------------------------------------------------
 *        Task 5 'init': Initialize
 *---------------------------------------------------------------------------*/
__task void init (void) {

  PMC->PMC_PCER  |= PMC_PCER_PID2;                         /* Enable clock for LED */
  PIOD->PIO_OER  |= PIO_OER_P21;                           /* Config LED as output */
  PIOB->PIO_OER  |= PIO_OER_P18;
  PIOD->PIO_SODR |= PIO_OER_P21;                           /* Clear the LED        */
  PIOB->PIO_SODR |= PIO_OER_P18;

  t_phaseA = os_tsk_create (phaseA, 0);  /* start task phaseA                */
  t_phaseB = os_tsk_create (phaseB, 0);  /* start task phaseB                */
  os_evt_set (0x0001, t_phaseA);         /* send signal event to task phaseA */
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

