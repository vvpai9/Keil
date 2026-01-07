/* ----------------------------------------------------------------------
 * Copyright (C) 2013 ARM Limited. All rights reserved.
 *  
 * $Date:        12. Sept 2013
 * $Revision:    V1.10
 *  
 * Project:      Ethernet PHY Driver for Middleware
 * -------------------------------------------------------------------- */

/* History:
 *  Version 1.10
 *    Namespace prefix ARM_ added
 *  Version 1.00
 *    Initial release
 */ 

#ifndef __DRIVER_ETH_PHY_H
#define __DRIVER_ETH_PHY_H

#include "Driver_ETH.h"

#define ARM_ETH_PHY_API_VERSION ARM_DRV_VERSION_MAJOR_MINOR(1,10) /* API version */


#define _ARM_Driver_ETH_PHY_(n)      Driver_ETH_PHY##n
#define  ARM_Driver_ETH_PHY_(n) _ARM_Driver_ETH_PHY_(n)


// Function documentation
/**
  \fn          ARM_DRV_VERSION ARM_ETH_PHY_GetVersion (void)
  \brief       Get driver version.
  \return      \ref ARM_DRV_VERSION
*/
/**
  \fn          ARM_ETH_STATUS ARM_ETH_PHY_Initialize (ARM_ETH_PHY_Read_t  fn_read,
                                                      ARM_ETH_PHY_Write_t fn_write)
  \brief       Initialize Ethernet PHY Device.
  \param[in]   fn_read   Pointer to \ref ARM_ETH_MAC_PHY_Read
  \param[in]   fn_write  Pointer to \ref ARM_ETH_MAC_PHY_Write
  \return      execution status \ref ARM_ETH_STATUS
*/
/**
  \fn          ARM_ETH_STATUS ARM_ETH_PHY_Uninitialize (void)
  \brief       De-initialize Ethernet PHY Device.
  \return      execution status \ref ARM_ETH_STATUS
*/
/**
  \fn          ARM_ETH_STATUS ARM_ETH_PHY_PowerControl (ARM_POWER_STATE state)
  \brief       Control Ethernet PHY Device Power.
  \param[in]   state  Power state
  \return      execution status \ref ARM_ETH_STATUS
*/
/**
  \fn          ARM_ETH_STATUS ARM_ETH_PHY_SetInterface (ARM_ETH_INTERFACE interface)
  \brief       Set Ethernet Media Interface.
  \param[in]   interface  \ref ARM_ETH_INTERFACE
  \return      execution status \ref ARM_ETH_STATUS
*/
/**
  \fn          ARM_ETH_STATUS ARM_ETH_PHY_SetMode (ARM_ETH_MODE mode)
  \brief       Set Ethernet PHY Device Operation mode.
  \param[in]   mode  \ref ARM_ETH_MODE
  \return      execution status \ref ARM_ETH_STATUS
*/
/**
  \fn          ARM_ETH_LINK_STATE ARM_ETH_PHY_GetLinkState (void)
  \brief       Get Ethernet PHY Device Link state.
  \return      current link status \ref ARM_ETH_LINK_STATE
*/
/**
  \fn          ARM_ETH_LINK_INFO ARM_ETH_PHY_GetLinkInfo (void)
  \brief       Get Ethernet PHY Device Link information.
  \return      current link parameters \ref ARM_ETH_LINK_INFO
*/


typedef ARM_ETH_STATUS (*ARM_ETH_PHY_Read_t)  (uint8_t phy_addr, uint8_t reg_addr, uint16_t *data); ///< Pointer to \ref ARM_ETH_MAC_PHY_Read : Read Ethernet PHY Register.
typedef ARM_ETH_STATUS (*ARM_ETH_PHY_Write_t) (uint8_t phy_addr, uint8_t reg_addr, uint16_t  data); ///< Pointer to \ref ARM_ETH_MAC_PHY_Write : Write Ethernet PHY Register.


/**
\brief  Access structure of the Ethernet PHY Driver
*/
typedef struct _ARM_DRIVER_ETH_PHY {
  ARM_DRV_VERSION    (*GetVersion)   (void);                          ///< Pointer to \ref ARM_ETH_PHY_GetVersion : Get driver version.
  ARM_ETH_STATUS     (*Initialize)   (ARM_ETH_PHY_Read_t  fn_read,
                                      ARM_ETH_PHY_Write_t fn_write);  ///< Pointer to \ref ARM_ETH_PHY_Initialize : Initialize PHY Device.
  ARM_ETH_STATUS     (*Uninitialize) (void);                          ///< Pointer to \ref ARM_ETH_PHY_Uninitialize : De-initialize PHY Device.
  ARM_ETH_STATUS     (*PowerControl) (ARM_POWER_STATE state);         ///< Pointer to \ref ARM_ETH_PHY_PowerControl : Control PHY Device Power.
  ARM_ETH_STATUS     (*SetInterface) (ARM_ETH_INTERFACE interface);   ///< Pointer to \ref ARM_ETH_PHY_SetInterface : Set Ethernet Media Interface.
  ARM_ETH_STATUS     (*SetMode)      (ARM_ETH_MODE mode);             ///< Pointer to \ref ARM_ETH_PHY_SetMode : Set Ethernet PHY Device Operation mode.
  ARM_ETH_LINK_STATE (*GetLinkState) (void);                          ///< Pointer to \ref ARM_ETH_PHY_GetLinkState : Get Ethernet PHY Device Link state.
  ARM_ETH_LINK_INFO  (*GetLinkInfo)  (void);                          ///< Pointer to \ref ARM_ETH_PHY_GetLinkInfo : Get Ethernet PHY Device Link information.
} const ARM_DRIVER_ETH_PHY;

#endif /* __DRIVER_ETH_PHY_H */
