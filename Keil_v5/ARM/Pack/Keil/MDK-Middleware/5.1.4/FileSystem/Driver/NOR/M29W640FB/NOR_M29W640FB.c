/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::Drivers:NOR
 * Copyright (c) 2004-2013 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    NOR_M29W640FB.c
 * Purpose: NOR Flash Device Driver for M29W640FB (16-bit Bus)
 * Rev.:    V5.04
 *----------------------------------------------------------------------------*/

#include "Driver_NOR.h"
#include "NOR_M29W640FB.h"

#define ARM_NOR_DRV_VERSION ARM_DRV_VERSION_MAJOR_MINOR(5,04)    /* driver version */


#define M16(addr) (*((volatile uint16_t *) (addr)))

/* Flash Commands */
#define CMD_RESET           0xF0
#define CMD_ERASE           0x80
#define CMD_ERASE_CHIP      0x10
#define CMD_ERASE_SECTOR    0x30
#define CMD_ERASE_BLOCK     0x50
#define CMD_PROGRAM         0xA0

/* Flash Status Register bits */
#define DQ7                 (1<<7)
#define DQ6                 (1<<6)
#define DQ5                 (1<<5)
#define DQ3                 (1<<3)

static uint32_t NOR_Addr;               /* NOR Flash Base Address */


/* Driver Version */
static const ARM_DRV_VERSION DriverVersion = {
  ARM_NOR_API_VERSION,
  ARM_NOR_DRV_VERSION
};

/* Sector Information */
static ARM_NOR_SECTOR ARM_NOR_Sector_(NOR_FLASH_NAME)[NOR_FLASH_SECTOR_NUM] = {
  NOR_FLASH_SECTORS
};

/* Device Information */
ARM_NOR_DEVICE ARM_NOR_Device_(NOR_FLASH_NAME) = {
  NOR_FLASH_SIZE,
  NOR_FLASH_SECTOR_NUM,
  ARM_NOR_Sector_(NOR_FLASH_NAME),
  NOR_FLASH_EVAL
};


/* Check if Program/Erase completed */
static bool Q6_Polling (uint32_t addr) {
  uint32_t fsreg;
  uint32_t dqold;

  fsreg = M16(addr);
  do {
    dqold = fsreg & DQ6;
    fsreg = M16(addr);
    if ((fsreg & DQ6) == dqold) {
      return true;              /* Done */
    }
  } while ((fsreg & DQ5) != DQ5);
  fsreg = M16(addr);
  dqold = fsreg & DQ6;
  fsreg = M16(addr);
  if ((fsreg & DQ6) == dqold) {
    return true;                /* Done */
  }
  M16(addr) = CMD_RESET;        /* Reset Flash Device */
  return false;                 /* Error */
}


/**
  \fn          ARM_DRV_VERSION NOR_GetVersion (void)
  \brief       Get driver version.
  \return      \ref ARM_DRV_VERSION
*/
static ARM_DRV_VERSION NOR_GetVersion (void) {
  return DriverVersion;
}


/**
  \fn          ARM_NOR_STATUS NOR_Initialize (uint32_t base_addr)
  \brief       Initialize NOR Flash Interface.
  \param[in]   base_addr specifies device base address
  \return      \ref ARM_NOR_STATUS
*/
static ARM_NOR_STATUS NOR_Initialize (uint32_t base_addr) {
  NOR_Addr = base_addr;
  return ARM_NOR_OK;
}

/**
  \fn          ARM_NOR_STATUS NOR_Uninitialize (void)
  \brief       De-initialize NOR Flash Interface.
  \return      \ref ARM_NOR_STATUS
*/
static ARM_NOR_STATUS NOR_Uninitialize (void) {
  /* ... */
  return ARM_NOR_OK;
} 

/**
  \fn          ARM_NOR_STATUS NOR_PowerControl (ARM_POWER_STATE state)
  \brief       Control NOR Flash Interface Power.
  \param[in]   state specifies Power state
  \return      \ref ARM_NOR_STATUS
*/
static ARM_NOR_STATUS NOR_PowerControl (ARM_POWER_STATE state) {
  /* ... */
  return ARM_NOR_OK;
}

/**
  \fn          ARM_NOR_STATUS NOR_WriteData (uint32_t addr, const uint8_t *data, uint32_t size)
  \brief       Write data to NOR Flash.
  \param[in]   addr specifies data address
  \param[in]   data specifies pointer to buffer with data to write to NOR Flash
  \param[in]   size specifies number of bytes to write
  \return      \ref ARM_NOR_STATUS
*/
static ARM_NOR_STATUS NOR_WriteData (uint32_t addr, const uint8_t *data, uint32_t size) {
  uint32_t cnt;
  
  for (cnt = size & ~1; cnt; cnt -= 2, addr += 2, data += 2) {
    M16(NOR_Addr + 0xAAA) = 0xAA;
    M16(NOR_Addr + 0x554) = 0x55;
    M16(NOR_Addr + 0xAAA) = CMD_PROGRAM;
    M16(NOR_Addr + addr)  = *(__packed uint16_t *)data;

    if (!Q6_Polling(NOR_Addr)) return ARM_NOR_ERROR;  /* Wait until Programming completed */
  }

  return ARM_NOR_OK;
}

/**
  \fn          ARM_NOR_STATUS NOR_EraseSector (uint32_t addr)
  \brief       Erase NOR Flash Sector.
  \param[in]   addr specifies sector address
  \return      \ref ARM_NOR_STATUS
*/
static ARM_NOR_STATUS NOR_EraseSector (uint32_t addr) {
  uint32_t fsreg;

  M16(NOR_Addr + 0xAAA) = 0xAA;
  M16(NOR_Addr + 0x554) = 0x55;
  M16(NOR_Addr + 0xAAA) = CMD_ERASE;
  M16(NOR_Addr + 0xAAA) = 0xAA;
  M16(NOR_Addr + 0x554) = 0x55;
  M16(NOR_Addr + addr)  = CMD_ERASE_SECTOR;

  /* Wait for Sector Erase Timeout */
  do {
    fsreg = M16(NOR_Addr + addr);
  } while ((fsreg & DQ3) != DQ3);

  if (!Q6_Polling(NOR_Addr)) return ARM_NOR_ERROR;  /* Wait until Erase completed */

  return ARM_NOR_OK;
}

/**
  \fn          ARM_NOR_STATUS NOR_EraseChip (void)
  \brief       Erase complete NOR Flash.
               Optional function for faster full chip erase.
  \return      \ref ARM_NOR_STATUS
*/
static ARM_NOR_STATUS NOR_EraseChip (void) {

  M16(NOR_Addr + 0xAAA) = 0xAA;
  M16(NOR_Addr + 0x554) = 0x55;
  M16(NOR_Addr + 0xAAA) = CMD_ERASE;
  M16(NOR_Addr + 0xAAA) = 0xAA;
  M16(NOR_Addr + 0x554) = 0x55;
  M16(NOR_Addr + 0xAAA) = CMD_ERASE_CHIP;

  if (!Q6_Polling(NOR_Addr)) return ARM_NOR_ERROR;  /* Wait until Erase completed */

  return ARM_NOR_OK;
}


/* NOR_Flash Device Driver Control Block */
ARM_DRIVER_NOR ARM_Driver_NOR_(NOR_FLASH_NAME) = {
  NOR_GetVersion,
  NOR_Initialize,
  NOR_Uninitialize,
  NOR_PowerControl,
  NULL,
  NOR_WriteData,
  NOR_EraseSector,
  NOR_EraseChip
};
