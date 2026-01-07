/******************** (C) COPYRIGHT 2006 STMicroelectronics ********************
* File Name          : Readme.txt
* Author             : MCD Application Team
* Date First Issued  : 03/10/2006
* Description        : Description of the MRCC Example4.
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
This example shows how to enters the system to WFI mode with DMA transfer enabled
and wake-up from this mode by the DMA end of transfer interrupt.

In the associated software, the system clock is set to 60 MHz, the DMA Stream2
is configured to transfer 4 data from the UART0 receive FIFO to a predefined 
buffer, DST_Buffer, and to generate an interrupt at the end of the transfer.
The UART0 receives data from Hyperterminal.
A led connected to P2.18 pin is toggled with a frequency depending on the system
clock, this is used to indicate whether the MCU is in WFI or RUN mode. 

The system enters and exits WFI mode as following:
After system power on, a led connected to P2.18 pin is toggled then after a delay
the system enters WFI mode causing the P2.18 pin to stop toggling. 
To wake-up from WFI mode you have to send four characters from the Hyperterminal
to the UART0. Once the four data are received, the DMA transfers these data from 
UART0 Rx FIFO to DST_Buffer then generates an interrupt which exits the system 
from WFI mode. 
After that the P2.18 pin restarts toggling and after a delay the system will
enter again in WFI mode then exit in the way described above. This behavior is
repeated in an infinite loop.
You can verify the characters you have entered with Hyperterminal by checking the
DST_Buffer content.

If the system fails to enter WFI mode, a led connected to P2.19 pin is turned on.

The system clock is outputted on P0.01 pin, you can monitor this clock using an 
oscilloscope.

Note:  If the Flash is used in Burst mode, it must be kept enabled in WFI mode.


Directory contents
==================
75x_conf.h  Library Configuration file
75x_it.c    Interrupt handlers
main.c      Main program


Hardware environment
====================
 - Connect the P0.01 pin to an oscilloscope (TP7 on STR75x-EVAL board) 
 - Connect two leds to P2.18 and P2.19 pins (respectively LD4 and LD5 on 
   STR75x-EVAL board).
 - The UART0 signals (Rx and Tx) must be connected to a DB9 connector using
   a RS232 transceiver.
 - Connect a null-modem female/female RS232 cable between the DB9 connector 
   (CN4 on STR75x-EVAL board) and PC serial port.  
 - Hyperterminal configuration:
    - Word Length = 8 Bits
    - One Stop Bit
    - Odd parity
    - BaudRate = 9600 baud
    - flow control: None    
   

How to use it
=============
In order to make the program work, you must do the following :
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files :
  + 75x_lib.c
  + 75x_gpio.c
  + 75x_mrcc.c
  + 75x_eic.c
  + 75x_cfg.c
  + 75x_uart.c
  + 75x_dma.c
  
- Link all compiled files and load your image into either RAM or Flash
- Run the example


******************* (C) COPYRIGHT 2006 STMicroelectronics *****END OF FILE******
