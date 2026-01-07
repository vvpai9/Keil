==============================================================================
        Flash Memory Write Utility

        for ML67Q5250 CPU Board Support

        Copyright (C) 2008 Oki Electric Industry Co., Ltd.

        Version       Date
        Preliminary   2008/07/17

    Adaption for MDK-ARM
    Keil - An ARM Company  2008.08.07
==============================================================================

Contents
---------
1. Overview
2. Operating Environment
3. Data File Format Supported
4. Setting Switches and Jumpers
5. Package Files
6. Execution Method


1. Overview
-------------------------------------------------------------------
The ML67Q5250 Flash Downloader for MDK-ARM can write to the Embedded 
Flash Memory by using the flash download function of uVision.


2. Operating Environment
-------------------------------------------------------------------
Operation of these sample programs has been confirmed in the
following development environment.

  Keil uVision V3.23
  ULINK (USB JTAG Adapter)


3. Data File Format Supported
-------------------------------------------------------------------
This utility supports to the Intel 32 bit Hex format.


4. Setting Switches and Jumpers
-------------------------------------------------------------------
This utility uses the following hardware settings.
*Please note the difference from ADS and RVDS.

 < 8bit DIP-SWITCH >
 No | DIP-SWITCH  |           
 =============================
  1 |  BOOTP      |    ON    
  2 |  JTAGE      |    ON     
  3 |  TEST2      |    OFF    
  4 |  Reserved   |    OFF    
  5 |  Reserved   |    OFF    
  6 |  Reserved   |    OFF    
  7 |  PB08/FTM0  |    OFF    
  8 |  PB09/FTM1  |    OFF    


5. Package Files
-------------------------------------------------------------------
The file composition is as follows.

FLASH_WRITE_MDK-ARM        -- Flash Downloader folder
 |
 |- MDK-ARM_PROJ           -- Flash Downloader RVMDK Project folder
 |  |- flash_writer_restore_Data -- HEX file storage folder
 |  |- flash_writer_update_Data  -- HEX file storage folder
 |  |- flash_writer_restore.Uv2  -- RVMDK Project file for Flash Downloader
 |  |- flash_writer_update.Uv2   -- RVMDK Project file for Flash Downloader
 |
 |- readme_mdk-arm.txt     -- Flash Write Utility Readme file

-------------------------------------------------------------------


6. Execution Method
-------------------------------------------------------------------
As for the project file, two types below are bundled.
Please select and use a necessary function.

========
a) The firmware update function
This is the function to rewrite only the program code area in the Embedded 
Flash memory. 
The program code area in the Embedded Flash memory is rewritten but
the stored fingerprint template data is not deleted.

b) The restore function
This is the function to write the program code after all area in the 
Embedded Flash memory is deleted.
All stored fingerprint template data is deleted.
========

Please output program code as the Intel 32 bit Hex format file "flash_data.hex".
Please store the Hex file in the directory "flash_writer_restore_Data" or 
the directory "flash_writer_update_Data" according to the project file.
 
Please select the Menu "Flash->Download" after opening the project file.

When the following messages is output on the "Output Window - Build",
the process writing to flash memory is successful.

===
Erase Done.
Programming Done.
Verify OK.
===



