/******************** (C) COPYRIGHT 2006 STMicroelectronics ********************
* File Name          : Readme.txt
* Author             : MCD Application Team
* Date First Issued  : 03/10/2006
* Description        : Description of the UART Example6.
********************************************************************************
* History:
* 07/17/2006 : V1.0
* 03/10/2006 : V0.1
********************************************************************************
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

Example description
===================
This example shows how to retarget the C library printf function to the UART. 
This implementation output the printf message on the Hyperterminal using UARTx.
UARTx can be UART0, UART1 or UART2; to select the UART interface to be used
uncomment the '#define USE_UARTx' line in 'main.h' file.

UARTx configured as follow:
  - Word Length = 8 Bits
  - One Stop Bit
  - Odd parity
  - BaudRate = 115200 baud
  - Hardware flow control disabled (RTS and CTS signals)
  - Receive and transmit enabled
  - Receive and transmit FIFOs are enabled
  - Transmit FIFO level have 8 bytes depth 
  - Receive FIFO level have 8 bytes depth 

        
Directory contents
==================
75x_conf.h  Library Configuration file
75x_it.c    Interrupt handlers
main.c      Main program
main.h      Header for main.c


Hardware environment
====================
 - The UARTx signals (Rx, Tx) must be connected to a DB9 connector using a RS232
   transceiver.

 - Connect a null-modem female/female RS232 cable between the DB9 connector 
   (CN4 for UART0, CN8 for UART1 or CN10 for UART2  in the STR75x-EVAL board) 
   and PC serial port.  

 - Hyperterminal configuration:
    - Word Length = 8 Bits
    - One Stop Bit
    - Odd parity
    - BaudRate = 115200 baud
    - flow control: None 


How to use it
=============
In order to make the program work, you must do the following :
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files :
  + 75x_lib.c
  + 75x_uart.c
  + 75x_gpio.c
  + 75x_mrcc.c
  
- Link all compiled files and load your image into either RAM or Flash
- Run the example


******************* (C) COPYRIGHT 2006 STMicroelectronics *****END OF FILE******
