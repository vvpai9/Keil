/******************** (C) COPYRIGHT 2006 STMicroelectronics ********************
* File Name          : Readme.txt
* Author             : MCD Application Team
* Date First Issued  : 03/10/2006
* Description        : Description of the TB Example1.
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
This example show how to configure the TB peripheral in Timing mode to generate 
a time base equal to 2 ms.

The CK_TIM frequency is set to 60 MHz, the TB is running at 250 KHz and the 
Update period is equal to 2 ms. 

On each Update event, an interrupt is generated and the leds connected to P2.18,
P1.01 and P0.16 pins are toggled with different frequencies respectively equal 
to 10 Hz, 1 Hz and 2 Hz. 


Directory contents
==================
75x_conf.h  Library Configuration file
75x_it.c    Interrupt handlers
main.c      Main program


Hardware environment
====================
 - Connect three leds to pins P2.18, P1.01 and P0.16(respectively LD4, LD2 and 
   LD3 on STR75x-EVAL board).

    
How to use it
=============
In order to make the program work, you must do the following :
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files :
  + 75x_lib.c
  + 75x_tb.c
  + 75x_gpio.c
  + 75x_mrcc.c
  + 75x_eic.c
  + 75x_cfg.c
  
- Link all compiled files and load your image into either RAM or Flash
- Run the example


******************* (C) COPYRIGHT 2006 STMicroelectronics *****END OF FILE******
