/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::Drivers:NOR
 * Copyright (c) 2004-2013 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    NOR_Device.c
 * Purpose: NOR Flash Device Driver - Template
 * Rev.:    V5.04
 *----------------------------------------------------------------------------*/

#include "Driver_NOR.h"
#include "NOR_Device.h"

#define ARM_NOR_DRV_VERSION ARM_DRV_VERSION_MAJOR_MINOR(5,04)    /* driver version */


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
  /* ... */
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
  \fn          ARM_NOR_STATUS NOR_ReadData (uint32_t addr, uint8_t *data, uint32_t size)
  \brief       Read data from NOR Flash.
               Optional function used for non-memory mapped devices.
  \param[in]   addr specifies data address
  \param[out]  data specifies pointer to buffer for data read from NOR Flash
  \param[in]   size specifies number of bytes to read
  \return      \ref ARM_NOR_STATUS
*/
static ARM_NOR_STATUS NOR_ReadData (uint32_t addr, uint8_t *data, uint32_t size) {
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
  /* ... */
  return ARM_NOR_OK;
}

/**
  \fn          ARM_NOR_STATUS NOR_EraseSector (uint32_t addr)
  \brief       Erase NOR Flash Sector.
  \param[in]   addr specifies sector address
  \return      \ref ARM_NOR_STATUS
*/
static ARM_NOR_STATUS NOR_EraseSector (uint32_t addr) {
  /* ... */
  return ARM_NOR_OK;
}

/**
  \fn          ARM_NOR_STATUS EraseChip (void)
  \brief       Erase complete NOR Flash.
               Optional function for faster full chip erase.
  \return      \ref ARM_NOR_STATUS
*/
static ARM_NOR_STATUS NOR_EraseChip (void) {
  /* ... */
  return ARM_NOR_OK;
}


/* NOR_Flash Device Driver Control Block */
ARM_DRIVER_NOR ARM_Driver_NOR_(NOR_FLASH_NAME) = {
  NOR_GetVersion,
  NOR_Initialize,
  NOR_Uninitialize,
  NOR_PowerControl,
  NOR_ReadData,
  NOR_WriteData,
  NOR_EraseSector,
  NOR_EraseChip
};
