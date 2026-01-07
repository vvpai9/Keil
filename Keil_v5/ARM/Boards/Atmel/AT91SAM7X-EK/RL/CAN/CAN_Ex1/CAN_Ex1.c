/*----------------------------------------------------------------------------
 *      RL-ARM - CAN
 *----------------------------------------------------------------------------
 *      Name:    CAN_Ex1.c
 *      Purpose: RTX CAN Driver usage example
 *      Rev.:    V4.70
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2013 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <RTL.h>                      /* RTX kernel functions & defines      */
#include <AT91SAM7X256.H>             /* AT91SAM7X256 definitions            */
#include "AT91SAM7X-EK.h"             /* AT91SAM7X-EK Eval Board definitions */
#include "CAN_Cfg.h"                  /* CAN Configuration                   */
#include <RTX_CAN.h>                  /* CAN Generic functions & defines     */ 

__task void task_init     (void);
__task void task_send_CAN (void);
__task void task_rece_CAN (void);
__task void task_disp     (void);

U32 Tx_val = 0, Rx_val = 0;           /* Global variables used for display   */

/*----------------------------------------------------------------------------
 *  Functions for init and getting input value
 *---------------------------------------------------------------------------*/

void In_Init (void) {
  /* Enable the peripheral clocks for port where joystick is connected       */
  AT91C_BASE_PMC->PMC_PCER = 1 << AT91C_ID_PIOA;
}

unsigned char In_Get (void) {
  /* bit 0 = UP, bit 1 = DOWN, bit 2 = LEFT, bit 3 = RIGHT                   */
  return ((~AT91C_BASE_PIOA->PIO_PDSR >> 21) & 0x0F);
}


/*----------------------------------------------------------------------------
 *  Functions for init and output of value on visual element
 *---------------------------------------------------------------------------*/

void Out_Init (void) {
  /* Enable the peripheral clocks for port where LEDs are connected          */
  AT91C_BASE_PMC->PMC_PCER = 1 << AT91C_ID_PIOB;

	AT91C_BASE_PIOB->PIO_PER = AT91B_LED_MASK;              /* LEDs as outputs */
	AT91C_BASE_PIOB->PIO_OER = AT91B_LED_MASK;
}

void Out_Val (void) {
  U32 val = Rx_val >> 4;              /* Read last  Rx value                 */

  val <<= 19;
  val   = ~val;
  val  &= (0x0F << 19);
  AT91C_BASE_PIOB->PIO_SODR = val;                        /* LEDs off        */
  val  ^= (0x0F << 19);
  AT91C_BASE_PIOB->PIO_CODR = val;                        /* other LEDs on   */
}


/*----------------------------------------------------------------------------
 *  Task 0: Initializes and starts other tasks
 *---------------------------------------------------------------------------*/

__task void task_init (void)  {
  os_tsk_create (task_send_CAN, 3);   /* Start                 transmit task */
  os_tsk_create (task_rece_CAN, 4);   /* Start                  receive task */
  os_tsk_create (task_disp    , 2);   /* Start output to visual element task */
  os_tsk_delete_self();               /* End             initialization task */
}

/*----------------------------------------------------------------------------
 *  Task 1: Sends message with input value in data[0] over CAN periodically
 *---------------------------------------------------------------------------*/

__task void task_send_CAN (void)  {
  /* Initialize message  = { ID, {data[0] .. data[7]}, LEN, CHANNEL, FORMAT, TYPE } */
  CAN_msg msg_send       = { 33, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   
                              1, 1, STANDARD_FORMAT, DATA_FRAME };

  CAN_init (1, 500000);               /* CAN controller 1 init, 500 kbit/s   */

  /* Transmit object does not have to be enabled but channel has to be 
     reserved for transmitting, in this example channel 1 is reserved for 
     transmission                                                            */

  CAN_rx_object (1, 2,  33, DATA_TYPE | STANDARD_TYPE); /* Enable reception  */
                                      /* of message on controller 1, channel */
                                      /* 2, data frame with standard id 33   */
  CAN_start (1);                      /* Start controller 1                  */
  os_dly_wait (10);                   /* Wait for AD to get first data       */

  for (;;)  {
    msg_send.data[0] = In_Get ();     /* Data[0] field = joystick status     */
    CAN_send (1, &msg_send, 0x0F00);  /* Send msg_send on controller 1       */
    Tx_val = msg_send.data[0];
    os_dly_wait (100);                /* Wait 1 second                       */
  }
}

/*----------------------------------------------------------------------------
 *  Task 2: Received CAN message
 *---------------------------------------------------------------------------*/

__task void task_rece_CAN (void)  {
  CAN_msg msg_rece;

  for (;;)  {
    /* When message arrives store received value to global variable Rx_val   */
    if (CAN_receive (1, &msg_rece, 0x00FF) == CAN_OK)  {
      Rx_val = msg_rece.data[0];
    }
  }
}

/*----------------------------------------------------------------------------
 *  Task 3: Activate visual output
 *---------------------------------------------------------------------------*/

__task void task_disp (void)  {
  for (;;)  {
    Out_Val ();                       /* Output info on visual output        */
    os_dly_wait (10);                 /* Wait 100 ms and display again       */
  }
}


/*----------------------------------------------------------------------------
 *        Main: Initialize and start RTX Kernel
 *---------------------------------------------------------------------------*/

int main (void)  {                    /* Program execution starts here       */

  In_Init  ();                        /* Initialize input                    */
                                      /* - Analog voltage                    */
  Out_Init ();                        /* Initialize visual outputs           */
                                      /* - LEDs                              */

  os_sys_init (task_init);            /* Initialize OS and start init task   */
}


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
