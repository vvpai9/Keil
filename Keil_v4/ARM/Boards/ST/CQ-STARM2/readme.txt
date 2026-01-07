How to use CQ-STM2 board with ST DfuSe                               15.02.2008
--------------------------------------

1. change target mapping

1.1 using licensed uVision
  in 'Options for Target - Target' change start address of IROM1 to 0x08003000
  in 'Options for Target - Linker' check 'Use Memory Layout from Target Dialog'

1.2 using evaluation version
  in 'Options for Target - Target' change start address of IROM1 to 0x08003000
  in 'Options for Target - Linker' change R/O base to 0x08003000

2. change STM_init configuration
  open file STM32_Init.c and use 'Configuartion Wizzard'
  check 'Nested Vectored Interrupt Controller (NVIC)'
  check 'Vector Table Offset Register'
  set 'TBLBASE: Vector Table Base' to FLASH
  set 'TBLOFF: Vector Table Offset' to 0x00003000

3. create HEX-file
  in 'Options for Target - Output' check 'Create HEX File'
  execute 'Project - Rebuild all target files'

4. create DFU-file
  use ST tool DfuFileMgr.exe to create a DFU-file from the HEX-file
    according ST documetation.
  (use default settings for VID, PID, Version)

5. download DFU-file
  use ST tool DfuSeDemo.exe to download generated DFU-file according ST documentation    
  Note: set jumper J6 before connecting CQ-STARM2 board

6. run application
  disconnect CQ-STARM2 board
  open jumper J6 
  reconnect CQ-STARM2 board

