/******************** (C) COPYRIGHT 2006 STMicroelectronics ********************
* File Name          : Readme.txt
* Author             : MCD Application Team
* Date First Issued  : 03/10/2006
* Description        : Description of the ADC Example2.
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
This example provides a description of how to use the PWM TRGO signal as ADC 
injected conversion start trigger.
ADC Channel0 to Channel2 are converted in scan mode while ADC Channel3 is configured 
as injected channel which its start of conversion is driven by the PWM TRGO signal.
The PWM is cofigured to provide the TRGO signal which is synchronized with the 
Output compare OC with a frequency of 10Hz. 
On each rising edge of this signal a conversion of the injected ADC Channel3
starts. 
In an infinite loop the program check the end of injected chain conversion and 
toggle a led connected to P2.18 pin, if this flag is set.
The Channel3 converted value can be checked using your toolchain watch window. 

Directory contents
==================
75x_conf.h  Library Configuration file
75x_it.c    Interrupt handlers
main.c      Main program


Hardware environment
====================
 - Connect a led to pin P2.18 (LD4 on STR75x-EVAL board).
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
  + 75x_pwm.c
  
- Link all compiled files and load your image into either RAM or Flash
- Run the example


******************* (C) COPYRIGHT 2006 STMicroelectronics *****END OF FILE****
