/******************** (C) COPYRIGHT 2006 STMicroelectronics ********************
* File Name          : Readme.txt
* Author             : MCD Application Team
* Date First Issued  : 03/10/2006
* Description        : Description of the ADC Example1.
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
This example provides a description of how to use the ADC Ananalog watchdog low
and high thresholds detection.
The ADC channel3 analog input which is guarded by the Analog watchdog0, is 
converted in scan mode with a conversion frequency equal to 71KHz. 
On each end of conversion (EOC), an interrupt is generated where the program 
read the comparison result between the converted input value and the configured
Analog Watchdog0 low (0x100) and high (0x200) thresholds. The result is then 
displayed on two leds connected to pins P2.18 and P2.19 as below:
 - Analog input under Analog Watchdog0 low threshold: Led connected to P2.18 switched on
 - Analog input up Analog Watchdog0 high threshold: Led connected to P2.19 switched on
 - Analog input between Analog Watchdog0 low and high thresholds: leds switched off 


Directory contents
==================
75x_conf.h  Library Configuration file
75x_it.c    Interrupt handlers
main.c      Main program


Hardware environment
====================
 - Connect two leds to pins P2.18 and P2.19 (LD4 and LD5 on STR75x-EVAL board).
 - Connect a variable power supply 0-3.3V to ADC Channel3 mapped on pin P0.17
   (potentiometer RV2 on STR75x-EVAL board) 
   

How to use it
=============
In order to make the program work, you must do the following :
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files :
  + 75x_lib.c
  + 75x_adc.c
  + 75x_gpio.c
  + 75x_mrcc.c
  + 75x_eic.c
  
- Link all compiled files and load your image into either RAM or Flash
- Run the example


******************* (C) COPYRIGHT 2006 STMicroelectronics *****END OF FILE****
