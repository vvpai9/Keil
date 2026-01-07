/* ----------------------------------------------------------------------
 * Copyright (C) 2013 ARM Limited. All rights reserved.
 *  
 * $Date:        12. September 2013
 * $Revision:    V5.01
 *  
 * Driver:       Driver_ETH_PHYn (default: Driver_ETH_PHY0)
 * Project:      Ethernet Physical Layer Transceiver (PHY)
 *               Driver for DP83848C
 * ---------------------------------------------------------------------- 
 * Use the following configuration settings in the middleware component
 * to connect to this driver.
 * 
 *   Configuration Setting                 Value
 *   ---------------------                 -----
 *   Connect to hardware via Driver_ETH# = n (default: 0)
 * -------------------------------------------------------------------- */

/* History:
 *  Version 5.01
 *    Based on API V1.10 (namespace prefix ARM_ added)
 *  Version 5.00
 *    Initial release
 */ 

#include "PHY_DP83848C.h"
#include "Driver_ETH_PHY.h"

#define ARM_ETH_PHY_DRV_VERSION ARM_DRV_VERSION_MAJOR_MINOR(5,01) /* driver version */


#ifndef ETH_PHY_NUM
#define ETH_PHY_NUM     0        /* Default driver number */
#endif

#ifndef ETH_PHY_ADDR
#define ETH_PHY_ADDR    0x01     /* Default device address */
#endif


/* Driver Version */
static const ARM_DRV_VERSION DriverVersion = {
  ARM_ETH_PHY_API_VERSION,
  ARM_ETH_PHY_DRV_VERSION
};


/* Ethernet PHY local variables */
static ARM_ETH_PHY_Read_t  reg_rd;
static ARM_ETH_PHY_Write_t reg_wr;
static uint16_t            reg_bmcr;


/**
  \fn          ARM_DRV_VERSION ETH_PHY_GetVersion (void)
  \brief       Get driver version.
  \return      \ref ARM_DRV_VERSION
*/
static ARM_DRV_VERSION GetVersion (void) {
  return DriverVersion;
}


/**
  \fn          ARM_ETH_STATUS ETH_PHY_Initialize (ARM_ETH_PHY_Read_t  fn_read,
                                                  ARM_ETH_PHY_Write_t fn_write)
  \brief       Initialize Ethernet PHY Device.
  \param[in]   fn_read   Pointer to \ref ARM_ETH_PHY_Read
  \param[in]   fn_write  Pointer to \ref ARM_ETH_PHY_Write
  \return      \ref ARM_ETH_STATUS
*/
static ARM_ETH_STATUS Initialize (ARM_ETH_PHY_Read_t fn_read, ARM_ETH_PHY_Write_t fn_write) {
  uint16_t val;

  /* Register PHY read/write functions. */
  if ((fn_read == NULL) || (fn_write == NULL)) return ARM_ETH_ERROR;
  reg_rd = fn_read;
  reg_wr = fn_write;

  /* Check Device Identification. */
  reg_rd(ETH_PHY_ADDR, REG_PHYIDR1, &val);
  if (val != PHY_ID1) {
    /* Wrong PHY device. */
    return ARM_ETH_ERROR_UNSUPPORTED;
  }
  reg_rd(ETH_PHY_ADDR, REG_PHYIDR2, &val);
  if ((val & 0xFFF0) != PHY_ID2) {
    /* Wrong PHY device. */
    return ARM_ETH_ERROR_UNSUPPORTED;
  }

  reg_bmcr = BMCR_POWER_DOWN;
  return (reg_wr(ETH_PHY_ADDR, REG_BMCR, reg_bmcr));
}

/**
  \fn          ARM_ETH_STATUS ETH_PHY_Uninitialize (void)
  \brief       De-initialize Ethernet PHY Device.
  \return      \ref ARM_ETH_STATUS
*/
static ARM_ETH_STATUS Uninitialize (void) {
  return (reg_wr(ETH_PHY_ADDR, REG_BMCR, BMCR_POWER_DOWN));
}

/**
  \fn          ARM_ETH_STATUS ETH_PHY_PowerControl (ARM_POWER_STATE state)
  \brief       Control Ethernet PHY Device Power.
  \param[in]   state  Power state
  \return      \ref ARM_ETH_STATUS
*/
static ARM_ETH_STATUS PowerControl (ARM_POWER_STATE state) {

  switch (state) {
    case ARM_POWER_OFF:
      reg_bmcr |=  BMCR_POWER_DOWN;
      break;
    case ARM_POWER_FULL:
      reg_bmcr &= ~BMCR_POWER_DOWN;
      break;
    default:
      return ARM_ETH_ERROR_UNSUPPORTED;
  }

  return (reg_wr(ETH_PHY_ADDR, REG_BMCR, reg_bmcr));
}

/**
  \fn          ARM_ETH_STATUS ETH_PHY_SetInterface (ARM_ETH_INTERFACE interface)
  \brief       Set Ethernet Media Interface.
  \param[in]   interface  \ref ARM_ETH_INTERFACE
  \return      \ref ARM_ETH_STATUS
*/
static ARM_ETH_STATUS SetInterface (ARM_ETH_INTERFACE interface) {
  uint16_t val;

  switch (interface) {
    case ARM_ETH_INTERFACE_MII:
      val = 0x0001;
      break;
    case ARM_ETH_INTERFACE_RMII:
      val = RBR_RMII_MODE | 0x0001;
      break;
    default:
      return ARM_ETH_ERROR_UNSUPPORTED;
  }

  return (reg_wr(ETH_PHY_ADDR, REG_RBR, val));
}

/**
  \fn          ARM_ETH_STATUS ETH_PHY_SetMode (ARM_ETH_MODE mode)
  \brief       Set Ethernet PHY device Operation mode.
  \param[in]   mode  \ref ARM_ETH_MODE
  \return      \ref ARM_ETH_STATUS
*/
static ARM_ETH_STATUS SetMode (ARM_ETH_MODE mode) {

  reg_bmcr &= BMCR_POWER_DOWN;

  switch (mode) {
    case ARM_ETH_MODE_AUTO_NEGOTIATE:
      reg_bmcr |= BMCR_ANEG_EN;
      break; 
    case ARM_ETH_MODE_10M_FULL_DUPLEX:
      reg_bmcr |= BMCR_DUPLEX;
      break;
    case ARM_ETH_MODE_10M_HALF_DUPLEX:
      break;
    case ARM_ETH_MODE_100M_FULL_DUPLEX:
      reg_bmcr |= BMCR_SPEED_SEL | BMCR_DUPLEX;
      break;
    case ARM_ETH_MODE_100M_HALF_DUPLEX:
      reg_bmcr |= BMCR_SPEED_SEL;
      break;
    case ARM_ETH_MODE_LOOPBACK:
      reg_bmcr |= BMCR_LOOPBACK;
      break;
    case ARM_ETH_MODE_ISOLATE:
      reg_bmcr |= BMCR_ISOLATE;
      break;
    default:
      return ARM_ETH_ERROR_UNSUPPORTED;
  }

  return (reg_wr(ETH_PHY_ADDR, REG_BMCR, reg_bmcr));
}

/**
  \fn          ARM_ETH_LINK_STATE ETH_PHY_GetLinkState (void)
  \brief       Get Ethernet PHY Device Link state.
  \return      \ref ARM_ETH_LINK_STATE
*/
static ARM_ETH_LINK_STATE GetLinkState (void) {
  ARM_ETH_LINK_STATE state;
  uint16_t           val;

  reg_rd(ETH_PHY_ADDR, REG_BMSR, &val);
  state = (val & BMSR_LINK_STAT) ? ARM_ETH_LINK_UP : ARM_ETH_LINK_DOWN;

  return (state);
}

/**
  \fn          ARM_ETH_LINK_INFO ETH_PHY_GetLinkInfo (void)
  \brief       Get Ethernet PHY Device Link information.
  \return      \ref ARM_ETH_LINK_INFO
*/
static ARM_ETH_LINK_INFO GetLinkInfo (void) {
  ARM_ETH_LINK_INFO info;
  uint16_t          val;

  reg_rd(ETH_PHY_ADDR, REG_PHYSTS, &val);
  info.speed  = (val & PHYSTS_SPEED)  ? ARM_ETH_SPEED_10M   : ARM_ETH_SPEED_100M;
  info.duplex = (val & PHYSTS_DUPLEX) ? ARM_ETH_DUPLEX_FULL : ARM_ETH_DUPLEX_HALF;

  return (info);
}


/* PHY Driver Control Block */
ARM_DRIVER_ETH_PHY ARM_Driver_ETH_PHY_(ETH_PHY_NUM) = {
  GetVersion,
  Initialize,
  Uninitialize,
  PowerControl,
  SetInterface,
  SetMode,
  GetLinkState,
  GetLinkInfo
};
