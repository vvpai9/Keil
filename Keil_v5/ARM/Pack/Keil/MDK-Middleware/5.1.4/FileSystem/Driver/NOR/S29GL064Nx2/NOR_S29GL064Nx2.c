/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::Drivers:NOR
 * Copyright (c) 2004-2013 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    NOR_S29GL064Nx2.c
 * Purpose: NOR Flash Device Driver for S29GL064Nx2 (32-bit Bus)
 * Rev.:    V5.04
 *----------------------------------------------------------------------------*/

#include "Driver_NOR.h"
#include "NOR_S29GL064Nx2.h"

#define ARM_NOR_DRV_VERSION ARM_DRV_VERSION_MAJOR_MINOR(5,04)    /* driver version */


#define M32(addr) (*((volatile uint32_t *) (addr)))

/* Flash Commands */
#define CMD_RESET           0x00F000F0
#define CMD_ERASE           0x00800080
#define CMD_ERASE_CHIP      0x00100010
#define CMD_ERASE_SECTOR    0x00300030
#define CMD_PROGRAM         0x00A000A0

/* Flash Status Register bits */
#define DQ7                 (1<<7)
#define DQ6                 (1<<6)
#define DQ5                 (1<<5)
#define DQ3                 (1<<3)

union fsreg {                           /* Flash Status Register */
  struct b  {
    unsigned int q0l:1;
    unsigned int q1l:1;
    unsigned int q2l:1;
    unsigned int q3l:1;
    unsigned int q4l:1;
    unsigned int q5l:1;
    unsigned int q6l:1;
    unsigned int q7l:1;
    unsigned int rl:8;
    unsigned int q0h:1;
    unsigned int q1h:1;
    unsigned int q2h:1;
    unsigned int q3h:1;
    unsigned int q4h:1;
    unsigned int q5h:1;
    unsigned int q6h:1;
    unsigned int q7h:1;
    unsigned int rh:8;
  } b;
  unsigned int v;
} fsr;

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
  unsigned int q6l, q6h;

  fsr.v = M32(addr);
  q6l = fsr.b.q6l;
  q6h = fsr.b.q6h;
  do {
    fsr.v = M32(addr);
    if ((fsr.b.q6l == q6l) && (fsr.b.q6h == q6h)) {
      return (true);                /* Done */
    }
    q6l = fsr.b.q6l;
    q6h = fsr.b.q6h;
  } while ((fsr.b.q5l == 0) || (fsr.b.q5h == 0));  /* Check for Timeout */
  fsr.v = M32(addr);
  q6l = fsr.b.q6l;
  q6h = fsr.b.q6h;
  fsr.v = M32(addr);
  if ((fsr.b.q6l == q6l) && (fsr.b.q6h == q6h)) {
    return (true);                  /* Done */
  }
  M32(addr) = CMD_RESET;            /* Reset Device */
  return (false);                   /* Failed */
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

  for (cnt = size & ~3; cnt; cnt -= 4, addr += 4, data += 4) {
    M32(NOR_Addr + (0x555 << 2)) = 0x00AA00AA;
    M32(NOR_Addr + (0x2AA << 2)) = 0x00550055;
    M32(NOR_Addr + (0x555 << 2)) = CMD_PROGRAM;
    M32(NOR_Addr + addr)  = *(__packed uint32_t *)data;

    if (!Q6_Polling(NOR_Addr + addr)) return ARM_NOR_ERROR;  /* Wait until Programming completed */
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

  M32(NOR_Addr + (0x555 << 2)) = 0x00AA00AA;
  M32(NOR_Addr + (0x2AA << 2)) = 0x00550055;
  M32(NOR_Addr + (0x555 << 2)) = CMD_ERASE;
  M32(NOR_Addr + (0x555 << 2)) = 0x00AA00AA;
  M32(NOR_Addr + (0x2AA << 2)) = 0x00550055;
  M32(NOR_Addr + addr)  = CMD_ERASE_SECTOR;

  /* Wait for Sector Erase Timeout */
  do {
    fsr.v = M32(NOR_Addr + addr);
  } while ((fsr.b.q3l == 0) || (fsr.b.q3h == 0));

  if (!Q6_Polling(NOR_Addr + addr)) return ARM_NOR_ERROR;  /* Wait until Erase completed */

  return ARM_NOR_OK;
}

/**
  \fn          ARM_NOR_STATUS NOR_EraseChip (void)
  \brief       Erase complete NOR Flash.
               Optional function for faster full chip erase.
  \return      \ref ARM_NOR_STATUS
*/
static ARM_NOR_STATUS NOR_EraseChip (void) {

  M32(NOR_Addr + (0x555 << 2)) = 0x00AA00AA;
  M32(NOR_Addr + (0x2AA << 2)) = 0x00550055;
  M32(NOR_Addr + (0x555 << 2)) = CMD_ERASE;
  M32(NOR_Addr + (0x555 << 2)) = 0x00AA00AA;
  M32(NOR_Addr + (0x2AA << 2)) = 0x00550055;
  M32(NOR_Addr + (0x555 << 2)) = CMD_ERASE_CHIP;

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
