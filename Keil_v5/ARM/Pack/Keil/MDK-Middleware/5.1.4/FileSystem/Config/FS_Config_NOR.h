/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::File System:Drive
 * Copyright (c) 2004-2013 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    FS_Config_NOR_%Instance%.h
 * Purpose: File System Configuration for NOR Flash Drive
 * Rev.:    V5.04
 *----------------------------------------------------------------------------*/

//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------

// <h>NOR Flash Drive %Instance%
// <i>Configuration for NOR Flash device assigned to drive letter "F%Instance%:"
#define NOR%Instance%_ENABLE             1

//   <e>NOR Flash Access via Memory Bus
//   <i>NOR Flash Device is memory mapped and accessed via Memory Bus
#define NOR%Instance%_MEM_BUS            1

//     <o>Base address <0x0-0xFFFFF000:0x1000>
//     <i>Define NOR Flash Device base address on the Memory Bus
#define NOR%Instance%_BASE_ADDR          0x80000000

//   </e>

//   <e>NOR Flash Access via SPI
//   <i>NOR Flash Device is connected via SPI
#define NOR%Instance%_SPI                0

//     <o>Connect to hardware via Driver_SPI# <0-255>
//     <i>Select driver control block for hardware interface
#define NOR%Instance%_SPI_DRIVER         0

//   </e>

#if (NOR%Instance%_MEM_BUS == 0) && (NOR%Instance%_SPI == 0)
#error "NOR Flash Access undefined: select Memory Bus or SPI"
#endif

#if (NOR%Instance%_MEM_BUS == 1) && (NOR%Instance%_SPI == 1)
#error "NOR Flash Access: select either Memory Bus or SPI"
#endif

//   <o>NOR Flash Device
//     <0=>AM29x800BB
//     <1=>M29W640FB
//     <2=>AT45DB642D
//   <i>Specify NOR Flash Device Name (selects Flash Device description) 
#define NOR%Instance%_NAME_ID            0
#if    (NOR%Instance%_NAME_ID == 0)
#define NOR%Instance%_NAME               AM29x800BB
#elif  (NOR%Instance%_NAME_ID == 1)
#define NOR%Instance%_NAME               M29W640FB
#elif  (NOR%Instance%_NAME_ID == 2)
#define NOR%Instance%_NAME               AT45DB642D
#else
#error "NOR Flash Device not selected!"
#endif

//   <q>Default Drive "F%Instance%:"
//   <i>Use this drive when no drive letter is specified.
#define NOR%Instance%_DEFAULT_DRIVE      0

// </h>
