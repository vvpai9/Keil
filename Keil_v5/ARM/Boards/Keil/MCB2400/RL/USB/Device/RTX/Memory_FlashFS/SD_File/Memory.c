/*-----------------------------------------------------------------------------
 *      RL-ARM - USB
 *-----------------------------------------------------------------------------
 *      Name:    Memory.c
 *      Purpose: USB Memory Storage Demo
 *      Rev.:    V4.70
 *-----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2013 KEIL - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include <LPC24xx.H>                    /* LPC24xx definitions                */
#include <stdint.h>

#include <RTL.h>
#include <File_Config.h>
#include <rl_usb.h>

#include "Terminal.h"
#include "Memory.h"
#include "Serial.h"
#include "LED.h"

#define EINT0     (1 << 10)

#define SEL_TERM  0
#define SEL_PC    1

OS_TID tid_sel;                         /* Interface selection task ID        */
OS_TID tid_term;                        /* Terminal task ID                   */

FAT_VI *mc0;                            /* FAT Media Control Block            */
Media_INFO info;                        /* Media information                  */ 

U64 term_stack[800/4];                  /* Terminal uses user provided stack  */

extern __task void file_man (void);     /* File manipulation main task        */

/*-----------------------------------------------------------------------------
  Check and debounce the wakeup key
 *----------------------------------------------------------------------------*/
__task void chk_key (void) {
  static BOOL WKUP_Key = __TRUE;
  BOOL key;

  os_itv_set (50);                      /* Set task interval to 50ms          */
  while (1) {
    key = ((FIO2PIN & EINT0) == 0);
    if (key && !WKUP_Key) {
      /* Key was pressed, switch the interface */
      os_evt_set (EVT_SW, tid_sel);
    }
    WKUP_Key = key;
    os_itv_wait();
  }
}


/*-----------------------------------------------------------------------------
  Interface selection task
 *----------------------------------------------------------------------------*/
__task void sel_if (void) {
  U32 sel = SEL_TERM;

  while (1) {
    if (sel == SEL_PC) {
      /* Switch from the PC to Terminal Interface                             */
      sel = SEL_TERM;
      usbd_connect(__FALSE);            /* USB Device Disconnect              */
      LED_Val (LED_MSK_OFF);

      os_evt_set (EVT_SW, tid_term);    /* Send terminal activation request   */
    }
    else {
      /* Switch from the Terminal to PC Interface                             */
      sel = SEL_PC;
      
      os_evt_set (EVT_SW, tid_term);    /* Send terminal deactivation request */
      os_evt_wait_and (EVT_SW, 0xFFFF); /* Wait until terminal is deactivated */

      mc0 = ioc_getcb (NULL);
      if (ioc_init (mc0) == 0) {
        ioc_read_info (&info, mc0);
        usbd_msc_init ();               /* Init USB MSC Global Variables      */
        usbd_connect(__TRUE);           /* USB Device Connect                 */
      }
      else {
        LED_Val (LED_MSK_ALL);
      }
    }
    os_evt_wait_and (EVT_SW, 0xFFFF);   /* Wait for interface switch event    */    
  }
}


/*-----------------------------------------------------------------------------
  Init peripheral and create application tasks
 *----------------------------------------------------------------------------*/
__task void init (void) {
  SER_Init   ();                        /* Init serial interface              */
  LED_Init   ();                        /* Init LEDs                          */
  usbd_init  ();                        /* Init USB Device                    */

  os_tsk_prio_self (10);
  os_tsk_create (chk_key, 2);           /* Create Wakeup key checking task    */
  tid_sel = os_tsk_create (sel_if,  1); /* Create Interface selection task    */
  
  /* Create File manipulation task with user provided stack                   */
  tid_term = os_tsk_create_user (file_man, 1, &term_stack, sizeof (term_stack));
  os_tsk_delete_self ();  
}


/*-----------------------------------------------------------------------------
  Main Entry
 *----------------------------------------------------------------------------*/
int main (void) {
  os_sys_init (init);                   /* Init RTX and start application     */
}

/*-----------------------------------------------------------------------------
 * End of file
 *----------------------------------------------------------------------------*/
