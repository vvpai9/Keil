/*----------------------------------------------------------------------------
 *      RL-ARM - CAN
 *----------------------------------------------------------------------------
 *      Name:    CAN_Ex2.c
 *      Purpose: RTX CAN Driver usage example
 *      Rev.:    V4.70
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2013 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <RTL.h>                      /* RTX kernel functions & defines      */
#include <LPC22xx.h>                  /* LPC22xx definitions                 */
#include <RTX_CAN.h>                  /* CAN Generic functions & defines     */ 

__task void task_init     (void);
__task void task_CAN1     (void);
__task void task_CAN2     (void);
__task void task_disp     (void);

U32 Tx_val = 0, Rx_val = 0;           /* Global variables used for display   */
U32 In_val = 0;                       /* Input value (auto incrementing)     */


/*----------------------------------------------------------------------------
 *  Functions for init and getting input value
 *---------------------------------------------------------------------------*/

void In_Init (void) {
  In_val = 0;
}

unsigned char In_Get (void) {
  In_val ++;
  In_val &= 0xFF;

  return (In_val);
}

/*----------------------------------------------------------------------------
 *  Functions for init and output of value on visual element
 *---------------------------------------------------------------------------*/

void Out_Init (void) {
  IODIR0 = 0x00000100;                /* P0.8 defined as Output              */
}

void Out_Val (void) {
  U32 val;

  val = Rx_val;                       /* Read value  to local variable       */
  
  if (val & 1) IOCLR0 = 0x00000100;
  else         IOSET0 = 0x00000100;
}


/*----------------------------------------------------------------------------
 *  Task 0: Initializes and starts other tasks
 *---------------------------------------------------------------------------*/

__task void task_init (void)  {
  os_tsk_create (task_CAN2, 4);       /* Start CAN controller 2   task       */
  os_tsk_create (task_CAN1, 3);       /* Start CAN controller 1   task       */
  os_tsk_create (task_disp, 2);       /* Start displaying outputs task       */
  os_tsk_delete_self();               /* End      initialization  task       */
}

/*----------------------------------------------------------------------------
 *  Task 1: Sends REMOTE FRAME request on CAN 2, and display received value 
 *          on CAN 2
 *---------------------------------------------------------------------------*/

__task void task_CAN2 (void)  {
  /* Initialize message  = { ID, {data[0] .. data[7]}, LEN, CHANNEL, FORMAT, TYPE } */
  CAN_msg msg_send       = { 33, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   
                              1, 2, STANDARD_FORMAT, REMOTE_FRAME };
  CAN_msg msg_rece;

  CAN_init (1, 500000);               /* CAN controller 1 init, 500 kbit/s   */
  CAN_init (2, 500000);               /* CAN controller 2 init, 500 kbit/s   */
  CAN_rx_object (1, 1,  33, DATA_TYPE | STANDARD_TYPE); /* Enable reception  */
                                      /* of message on controller 1, channel */
                                      /* is not used for LPC (can be set to  */
                                      /* whatever value), data frame with    */
                                      /* standard id 33                      */
  CAN_rx_object (2, 2,  33, DATA_TYPE | STANDARD_TYPE); /* Enable reception  */
                                      /* of message on controller 2, channel */
                                      /* is not used for LPC (can be set to  */
                                      /* whatever value), data frame with    */
                                      /* standard id 33                      */

  CAN_start (1);                      /* Start controller 1                  */
  CAN_start (2);                      /* Start controller 2                  */

  for (;;)  {
    CAN_request (2, &msg_send, 0x00FF);  /* Send request on controller 2     */

    /* When message arrives store received value to global variable Rx_val   */
    /* First CAN_receive is because reception is allowed on controller 2 so 
       when controller 2 sends REMOTE FRAME it will also receive it          */
    if (CAN_receive (2, &msg_rece, 0x00F0) == CAN_OK);
    if (CAN_receive (2, &msg_rece, 0x000F) == CAN_OK)  {
      Rx_val = msg_rece.data[0];
    }

    os_dly_wait (100);                /* Wait 1 second                       */
  }
}

/*----------------------------------------------------------------------------
 *  Task 2: When REMOTE FRAME request is received on CAN 1, answer with 
 *          input value on CAN 1
 *---------------------------------------------------------------------------*/

__task void task_CAN1 (void)  {
  CAN_msg msg_rs;

  for (;;)  {
    /* When REMOTE frame arrives send the autoincrementing value in data[0]  */
    if (CAN_receive (1, &msg_rs, 0xFFFF) == CAN_OK)  {
      if (msg_rs.type == REMOTE_FRAME)  {
        msg_rs.data[0] = In_Get ();   /* Data[0] field = input value         */

        CAN_send (1, &msg_rs, 0x0F00);/* Send answer on controller 1         */
      }
    }
  }
}

/*----------------------------------------------------------------------------
 *  Task 3: Activate visual outputs
 *---------------------------------------------------------------------------*/

__task void task_disp (void)  {
  for (;;)  {
    Out_Val ();                       /* Output info on visual outputs       */
    os_dly_wait (10);                 /* Wait 100 ms and display again       */
  }
}


/*----------------------------------------------------------------------------
 *        Main: Initialize and start RTX Kernel
 *---------------------------------------------------------------------------*/

int main (void)  {                    /* Program execution starts here       */

  In_Init  ();                        /* Initialize input                    */
                                      /* - auuto incrementing variable       */
  Out_Init ();                        /* Initialize visual outputs           */
                                      /* - LED                               */

  os_sys_init (task_init);            /* Initialize OS and start init task   */
}


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
