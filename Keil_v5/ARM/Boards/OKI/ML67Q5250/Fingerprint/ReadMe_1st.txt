------------------------------------------------------------------------------
    ML67Q5250 Fingerprint Authentication Software Development Kit for MDK-ARM

    Copyright(C) 2008, Oki Electric Industry Co.,Ltd.
    All rights reserved.

    Preliminary version    2008.07.17

    Adaption for MDK-ARM
    Keil - An ARM Company  2008.08.07
------------------------------------------------------------------------------

NOTE: This is a precompiled project.
      DO NOT RECOMPILE THE EXAMPLE WITHOUT SOURCE FILES INSTALLED!

1. Overview
----------------
This package includes files (project file and setup files) for using 
ML67Q5250 Fingerprint Authentication Software Development Kit in MDK-ARM.


2. Build Project
----------------
!Do not build project without valid source files!

- change to folder .\ML67Q5250FPSDK_Source\mdk-arm_demoproj. 
- Open project FPSDK2510.Uv2. 
- Rebuild all target files.
- File .\FPSDK2510_Data\flash_data.hex is created.

Note: if file flash_data.hex is removed copy file flash_data.hex.sav to flash_data.hex.
 

3. Write Project to Flash 
-------------------------
!see file .\FLASH_WRITE_MDK-ARM\readme_mdk-arm.txt.
 
- copy file flash_data.hex to folder .\FLASH_WRITE_MDK-ARM\MDK-ARM_PROJ\flash_writer_update_Data.
- change to folder .\FLASH_WRITE_MDK-ARM\MDK-ARM_PROJ.
- open project flash_writer_update.Uv2
- Download to Flash Memory.


4. Setting Switches
-------------------
SW4-1: Bootp      ON:  Flash (program goes into FLASH with uVision).
                  OFF: external RAM (progarm loaded into RAM when debugger entered).
SW4-2: JTAG       ON:  JTAG enabled (ULINK can connect).
                  OFF: JTAG disabled.

     SW4-1  SW4-2
       OFF    OFF    RAM - standalone - no debugger See Note 2:
       OFF    ON     RAM with JTAG debugger
       ON     OFF    FLASH - standalone demo - no JTAG debugger  
       ON     ON     FLASH - operation using JTAG debugger

SW4-3: TEST2      OFF:    
SW4-4: Reserved   OFF:    
SW4-5: Reserved   OFF:    
SW4-6: Reserved   OFF:    
SW4-7: PB08/FTM0  OFF:    
SW4-8: PB09/FTM1  OFF:    

 
Note 1:  after changing switches - you must activate it by pressing RESET button.
Note 2:  You must program RAM with debugger first - then remove debugger, 
         change switch SW2 from down to up to turn JTAG off and RESET board.


5. Directory map
----------------

Fingerprint
|
|- FLASH_WRITE_MDK-ARM -- Project file for Flash Downloader
|  |- MDK-ARM_PROJ
|  |  |- flash_writer_restore.Uv2 -- Restore function project file for MDK-ARM
|  |  |- flash_writer_update.Uv2  -- Firmware update function project file for MDK-ARM
|  |
|  |- readme_mdk-arm.txt -- Readme for Flash Downloader
|
|- ML67Q5250FPSDK_Source -- ML67Q5250 Fingerprint source code
|  |- mdk-arm_demoproj -- Project file for MDK-ARM(Destination to save template:SRAM)
|  |  |- FPSDK2510.Uv2 -- Project file for AES2510(SPI:2ch)
|  |
|  |- mdk-arm_lib     -- Library for MDK-ARM
|  |  |- rFPAE.lib            -- Fingerprint Authentication engine
|  |  |- rFPSP.lib            -- Fingerprint Authentication accelerator driver
|  |  |- rSensor2510.lib      -- Sensor driver for AES2510(SPI:2ch)
|  |  |- rSensor2510slave.lib -- Sensor driver for AES2510(SPI:1ch)
|  |
|  |- mdk-arm_proj    -- Project file for MDK-ARM(Destination to save template:Flash)
|     |- FPSDK2510flash.mcp       -- Project file for AES2510(SPI:2ch)
|     |- FPSDK2510flash_slave.mcp -- Project file for AES2510(SPI:1ch)
|
|
|- ReadMe_1st.txt     -- Readme first

