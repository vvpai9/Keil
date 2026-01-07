/*----------------------------------------------------------------------------
 *      RL-ARM - USB
 *----------------------------------------------------------------------------
 *      Name:    USBD_Demo.c
 *      Purpose: USB Device Demonstration
 *      Rev.:    V4.70
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2013 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <RTL.h>
#include <rl_usb.h>
#include <71x_lib.H>

__task void init (void) {
  RCCU_MCLKConfig(RCCU_DEFAULT);                    /* MCLK = RCLK            */
  RCCU_FCLKConfig(RCCU_RCLK_2);                     /* FCLK = RCLK/2          */
  RCCU_PCLKConfig(RCCU_RCLK_4);                     /* PCLK = RCLK/4          */
  RCCU_PLL1Config(RCCU_PLL1_Mul_12, RCCU_Div_2);    /* 48MHz PLL @ 16MHz XTAL */

  while (RCCU_FlagStatus(RCCU_PLL1_LOCK) == RESET); /* Wait for PLL to Lock   */
  RCCU_RCLKSourceConfig(RCCU_PLL1_Output);          /* Select PLL for RCLK    */

  os_tsk_prio_self(100);
  usbd_init();                          /* USB Initialization                 */
  usbd_connect(__TRUE);                 /* USB Connect                        */
  os_tsk_delete_self();                 /* Terminate Task                     */
}

int main (void) {
  os_sys_init(init);                    /* Init RTX and start 'init'          */
}
