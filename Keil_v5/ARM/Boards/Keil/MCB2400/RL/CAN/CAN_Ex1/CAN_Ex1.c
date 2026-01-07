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
#include <LPC23xx.h>                  /* LPC23xx library definitions         */
#include <RTX_CAN.h>                  /* CAN Generic functions & defines     */ 

__task void task_init     (void);
__task void task_send_CAN (void);
__task void task_rece_CAN (void);
__task void task_disp     (void);

U32 Tx_val = 0, Rx_val = 0;           /* Global variables used for display   */

char hex_chars[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

#define I2C_AA     0x00000004
#define I2C_SI     0x00000008
#define I2C_STO    0x00000010
#define I2C_STA    0x00000020
#define I2C_I2EN   0x00000040

/*----------------------------------------------------------------------------
 *  Function that initializes LEDs
 *---------------------------------------------------------------------------*/
static void LED_Init (void) {
  PCONP    |=  (1 << 7);                /* Enable clock for I2C0             */

  /* Initialize pins for SDA (P0.27) and SCL (P0.28) functions               */
  PINSEL1  &= ~0x03C00000;
  PINSEL1  |=  0x01400000;

  /* Clear I2C state machine                                                 */
  I20CONCLR =  I2C_AA | I2C_SI | I2C_STA | I2C_I2EN;

  /* Setup I2C clock speed                                                   */
  I20SCLL   =  0x80;
  I20SCLH   =  0x80;

  I20CONSET =  I2C_I2EN;
  I20CONSET =  I2C_STO;
}

/*----------------------------------------------------------------------------
 *  Function that outputs value to LEDs
 *---------------------------------------------------------------------------*/
static void LED_Out (U32 val) {
  U32 v;

  v =  (val & 0x01)       | ((val << 1) & 0x04) | 
      ((val << 2) & 0x10) | ((val << 3) & 0x40);
  I20CONCLR =  I2C_AA | I2C_SI | I2C_STA | I2C_STO;
  I20CONSET =  I2C_STA;
  while (!(I20CONSET & I2C_SI));         /* Wait for START                   */
  I20DAT    =  0xC0;
  I20CONCLR =  I2C_SI | I2C_STA;
  while (!(I20CONSET & I2C_SI));         /* Wait for ADDRESS send            */
  I20DAT    =  0x18;
  I20CONCLR =  I2C_SI;
  while (!(I20CONSET & I2C_SI));         /* Wait for DATA send               */
  I20DAT    =  v;
  I20CONCLR =  I2C_SI;
  while (!(I20CONSET & I2C_SI));         /* Wait for DATA send               */
  I20CONSET =  I2C_STO;
  I20CONCLR =  I2C_SI;
  while (I20CONSET & I2C_STO);           /* Wait for STOP                    */
}

/*----------------------------------------------------------------------------
 *  Function for converting 1 byte to string in hexadecimal notation
 *---------------------------------------------------------------------------*/

void Hex_Str (unsigned char hex, char *str) {
  *str++ = '0';
  *str++ = 'x';
  *str++ = hex_chars[hex >>  4];
  *str++ = hex_chars[hex & 0xF];
}

/*----------------------------------------------------------------------------
 *  Functions for init and getting input value
 *---------------------------------------------------------------------------*/

void In_Init (void) {
  /* Power enable, Setup pin, enable and setup AD converter interrupt        */
  PCONP        |= (1 << 12);          /* Enable power to AD block            */
  PINSEL1      &=~0x0000C000;         /* AD0.0 pin function select           */
  PINSEL1      |= 0x00004000;
  AD0CR         = 0x002E0301;         /* Power up, PCLK/4, sel AD0.0         */
}

unsigned char In_Get (void) {
  unsigned int val;

  AD0CR |=  0x01000000;               /* Start A/D Conversion                */
  while (!((val=AD0GDR)&0x80000000)); /* Wait for Conversion and Read Data   */
  AD0CR &= ~0x01000000;               /* Stop A/D Conversion                 */

  val = (val >> 8) & 0xFF;            /* Extract AIN0 Value                  */

  return (val);
}

/*----------------------------------------------------------------------------
 *  Functions for init and output of value on visual element
 *---------------------------------------------------------------------------*/

void Out_Init (void) {
  PINSEL10 = 0;                       /* Disable ETM interface               */
  LED_Init();                         /* Initialize the LEDs                 */
}

void Out_Val (void) {
  U32 val1, val2;
  static char disp_buf[] = "Tx:    , Rx:    ";

  val1 = Tx_val;                      /* Read values to local variable       */
  val2 = Rx_val;    

  LED_Out (Rx_val & 0x0F);            /* Turn on requested LEDs, lower 4 Bits*/

  Hex_Str(val1, &disp_buf[ 3]);       /* Display Tx and Rx values to LCD disp*/ 
  Hex_Str(val2, &disp_buf[12]);
}


/*----------------------------------------------------------------------------
 *  Task 0: Initializes and starts other tasks
 *---------------------------------------------------------------------------*/

__task void task_init (void)  {
  os_tsk_create (task_send_CAN, 3);   /* Start          transmit task        */
  os_tsk_create (task_rece_CAN, 4);   /* Start           receive task        */
  os_tsk_create (task_disp    , 2);   /* Start displaying to LCD task        */
  os_tsk_delete_self();               /* End      initialization task        */
}

/*----------------------------------------------------------------------------
 *  Task 1: Sends message with input value in data[0] over CAN periodically
 *---------------------------------------------------------------------------*/

__task void task_send_CAN (void)  {
  /* Initialize message  = { ID, {data[0] .. data[7]}, LEN, CHANNEL, FORMAT, TYPE } */
  CAN_msg msg_send       = { 33, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   
                              1, 2, STANDARD_FORMAT, DATA_FRAME };

  CAN_init (1, 500000);               /* CAN controller 1 init, 500 kbit/s   */
  CAN_init (2, 500000);               /* CAN controller 2 init, 500 kbit/s   */

  /* Transmit object does not have to be enabled but channel has to be 
     reserved for transmitting, in this example channel 1 is reserved for 
     transmission                                                            */

  CAN_rx_object (1, 2,  33, DATA_TYPE | STANDARD_TYPE); /* Enable reception  */
                                      /* of message on controller 1, channel */
                                      /* is not used for LPC (can be set to  */
                                      /* whatever value), data frame with    */
                                      /* standard id 33                      */
  CAN_start (1);                      /* Start controller 1                  */
  CAN_start (2);                      /* Start controller 2                  */

  for (;;)  {
    msg_send.data[0] = In_Get ();     /* Data[0] field = analog value from   */
                                      /* potentiometer                       */

    CAN_send (2, &msg_send, 0x0F00);  /* Send msg_send on controller 2       */
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
                                      /* - Analog voltage                    */
  Out_Init ();                        /* Initialize visual outputs           */
                                      /* - LEDs, LCD display (2x16 chars)    */

  os_sys_init (task_init);            /* Initialize OS and start init task   */
}


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
