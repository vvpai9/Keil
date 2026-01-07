/******************** (C) COPYRIGHT 2006 STMicroelectronics ********************
* File Name          : Readme.txt
* Author             : MCD Application Team
* Date First Issued  : 03/10/2006 : V0.1
* Description        : Description of the Joystick USB HID Demo 
********************************************************************************
* History:
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
This example provides a description of how to use the USB on the STR75x devices.
The STR75x device is enumerated as an USB Joystick Mouse, that uses the native
PC Host USB HID driver.
The Joystick mounted on the STR75x-Eval board is used to emulate the Mouse
directions.


Directory contents
==================

 + include

   - 75x_conf.h  Library Configuration file
   - usb_conf.h  USB Library configuration file
   - usb_desc.h  Joystick Mouse descriptor header
   - usb_pwr.h   Joystick Mouse Power header
   - usb_mem.h   USB memory transfers header 
   - usb_prop.h  Joystick Mouse Prosessing header

 + source

   - 75x_it.c    Interrupt handlers
   - main.c      Main program
   - usb_desc.c  Joystick Mouse descriptor file
   - usb_pwr.c   Joystick Mouse Power file
   - usb_mem.c   USB memory transfers file 
   - usb_prop.c  Joystick Mouse Prosessing file
   - usb_istr.c  Main USB interrupts file
   - usb_endp.c  Non-Control interrupt routines file


Hardware environment
====================
 - STR75x-Eval board
 - Ensure that the JP2 jumper is on position 1-2 
   

How to use it
=============
In order to make the program work, you must do the following :
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files, the required Standard Library files,
  and all USB library files :
  + 75x_lib.c
  + 75x_gpio.c
  + 75x_mrcc.c
  + 75x_eic.c
  + 75x_cfg.c
  + usb_core.c
  + usb_int.c
  + usb_regs.c
  + usb_init.c
  
- Link all compiled files and load your image into either RAM or Flash
- Run the example


******************* (C) COPYRIGHT 2006 STMicroelectronics *****END OF FILE****
