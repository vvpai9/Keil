/******************** (C) COPYRIGHT 2006 STMicroelectronics ********************
* File Name          : Readme.txt
* Author             : MCD Application Team
* Date First Issued  : 03/10/2006
* Description        : Description of the RTC Example.
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
This example demonstrates and explain how to use the RTC peripheral. 
As an application example, it demonstrates how to setup the RTC peripheral, in 
terms of prescaler and interrupts, to be used to keep time and to generate 
Second interrupt.

The RTC clock source can be OSC32K or OSC4M divided by 128, to select the clock
to be used uncomment the corresponding line: '#define RTCClockSource_OSC32K' or
'#define RTCClockSource_OSC4M' in 'main.c' file.

In this example, each second interrupt a led connected to P2.19 is toggled and
the time is displayed on the Hyperterminal using the C library printf function. 
The time is displayed with the following format: HH:MM:SS where HH, MM and SS are
initialilzed to 0 in the application. For this you have to adjust time by  changing
these three variables.

The C library printf function is retarget to the UART0,i.e the printf message is
output to the Hyperterminal using UART0.

 
Directory contents
==================
75x_conf.h  Library Configuration file
75x_it.c    Interrupt handlers
main.c      Main program


Hardware environment
====================
 - Connect a led to pin P2.19 (respectively LD5 on STR75x-EVAL board).

 - The UART0 signals (Rx, Tx) must be connected to a DB9 connector using a RS232
   transceiver.

 - Connect a null-modem female/female RS232 cable between the DB9 connector 
   (CN4 on the STR75x-EVAL board) and PC serial port. 
   
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
  + 75x_rtc.c
  + 75x_gpio.c
  + 75x_mrcc.c
  + 75x_eic.c
  + 75x_uart.c
  
- Link all compiled files and load your image into Flash
- Run the example


******************* (C) COPYRIGHT 2006 STMicroelectronics *****END OF FILE******
