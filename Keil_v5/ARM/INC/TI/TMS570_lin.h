/** @file lin.h
*   @brief LIN Driver Definition File
*   @date 14.September.2009
*   @version 1.00.000
*   
*   (c) Texas Instruments 2009, All rights reserved.
*/


#ifndef __LIN_H__
#define __LIN_H__

#include "TMS570_gio.h"


/** @def LIN_BREAK_INT
*   @brief Alias for break detect interrupt flag
*
*   Used with linEnableNotification, linDisableNotification.
*/
#define LIN_BREAK_INT 0x00000001U


/** @def LIN_WAKEUP_INT
*   @brief Alias for wakeup interrupt flag
*
*   Used with linEnableNotification, linDisableNotification.
*/
#define LIN_WAKEUP_INT 0x00000002U


/** @def LIN_TO_INT
*   @brief Alias for time out interrupt flag
*
*   Used with linEnableNotification, linDisableNotification.
*/
#define LIN_TO_INT 0x00000010U


/** @def LIN_TOAWUS_INT
*   @brief Alias for time out after wakeup signal interrupt flag
*
*   Used with linEnableNotification, linDisableNotification.
*/
#define LIN_TOAWUS_INT 0x00000040U


/** @def LIN_TOA3WUS_INT
*   @brief Alias for time out after 3 wakeup signals interrupt flag
*
*   Used with linEnableNotification, linDisableNotification.
*/
#define LIN_TOA3WUS_INT 0x00000080U


/** @def LIN_TX_READY
*   @brief Alias for transmit buffer ready flag
*
*   Used with linIsTxReady.
*/
#define LIN_TX_READY 0x00000100U


/** @def LIN_RX_INT
*   @brief Alias for receive buffer ready interrupt flag
*
*   Used with linEnableNotification, linDisableNotification.
*/
#define LIN_RX_INT 0x00000200U


/** @def LIN_ID_INT
*   @brief Alias for received matching identifier interrupt flag
*
*   Used with linEnableNotification, linDisableNotification.
*/
#define LIN_ID_INT 0x00002000U


/** @def LIN_PE_INT
*   @brief Alias for parity error interrupt flag
*
*   Used with linEnableNotification, linDisableNotification.
*/
#define LIN_PE_INT 0x01000000U


/** @def LIN_OE_INT
*   @brief Alias for overrun error interrupt flag
*
*   Used with linEnableNotification, linDisableNotification.
*/
#define LIN_OE_INT 0x02000000U


/** @def LIN_FE_INT
*   @brief Alias for framming error interrupt flag
*
*   Used with linEnableNotification, linDisableNotification.
*/
#define LIN_FE_INT 0x04000000U


/** @def LIN_NRE_INT
*   @brief Alias for no response error interrupt flag
*
*   Used with linEnableNotification, linDisableNotification.
*/
#define LIN_NRE_INT 0x08000000U


/** @def LIN_ISFE_INT
*   @brief Alias for inconsistent sync field error interrupt flag
*
*   Used with linEnableNotification, linDisableNotification.
*/
#define LIN_ISFE_INT 0x10000000U


/** @def LIN_CE_INT
*   @brief Alias for checksum error interrupt flag
*
*   Used with linEnableNotification, linDisableNotification.
*/
#define LIN_CE_INT 0x20000000U


/** @def LIN_PBE_INT
*   @brief Alias for physical bus error interrupt flag
*
*   Used with linEnableNotification, linDisableNotification.
*/
#define LIN_PBE_INT 0x40000000U


/** @def LIN_BE_INT
*   @brief Alias for bit error interrupt flag
*
*   Used with linEnableNotification, linDisableNotification.
*/
#define LIN_BE_INT 0x80000000U


/** @struct linBase
*   @brief LIN Register Definition
*
*   This structure is used to access the LIN module egisters.
*/

typedef volatile struct linBase
{
    unsigned      GCR0;         /**< 0x0000: Global control register 0              */
    unsigned      GCR1;         /**< 0x0004: Global control register 1              */
    unsigned      GCR2;         /**< 0x0008: Global control register 2              */
    unsigned      SETINT;       /**< 0x000C: Set interrupt enable register          */
    unsigned      CLRINT;       /**< 0x0010: Clear interrupt enable register        */
    unsigned      SETINTLVL;    /**< 0x0014: Set interrupt level register           */
    unsigned      CLRINTLVL;    /**< 0x0018: Set interrupt level register           */
    unsigned      FLR;          /**< 0x001C: interrupt flag register                */
    unsigned      INTVECT0;     /**< 0x0020: interrupt vector Offset 0              */
    unsigned      INTVECT1;     /**< 0x0024: interrupt vector Offset 1              */
#ifdef _little_endian__
    unsigned      CHAR   :  3U; /**< 0x0028: Character length control register      */
    unsigned             : 13U; /**< 0x0028: Reserved                               */
    unsigned      LENGTH :  3U; /**< 0x0028: Length control register                */
    unsigned             : 13U; /**< 0x0028: Reserved                               */
#else
    unsigned             : 13U; /**< 0x0028: Reserved                               */
    unsigned      LENGTH :  3U; /**< 0x0028: Length control register                */
    unsigned             : 13U; /**< 0x0028: Reserved                               */
    unsigned      CHAR   :  3U; /**< 0x0028: Character length control register      */
#endif
    unsigned      BRSR;         /**< 0x002C: Baud rate selection register           */
    unsigned      ED;           /**< 0x0030: Emulation register                     */
    unsigned      RD;           /**< 0x0034: Receive data register                  */
    unsigned      TD;           /**< 0x0038: Transmit data register                 */
    unsigned      FUN;          /**< 0x003C: Pin function register                  */
    unsigned      DIR;          /**< 0x0040: Pin direction register                 */
    unsigned      DIN;          /**< 0x0044: Pin data in register                   */
    unsigned      DOUT;         /**< 0x0040: Pin data out register                  */
    unsigned      SET;          /**< 0x004C: Pin data set register                  */
    unsigned      CLR;          /**< 0x0050: Pin data clr register                  */
    unsigned      ODR;          /**< 0x0054: Pin open drain output enable register  */
    unsigned      PD;           /**< 0x0058: Pin pullup/pulldown disable register   */
    unsigned      PSL;          /**< 0x005C: Pin pullup/pulldown selection register */
    unsigned      COMP;         /**< 0x0060: Compare register                       */
    unsigned char RDx[8U];      /**< 0x0064-0x0068: RX buffer register              */
    unsigned      MASK;         /**< 0x006C: Mask register                          */
#ifdef _little_endian__
    unsigned char IDBYTE;       /**< 0x0070: Identifier byte register               */
    unsigned char IDSTB;        /**< 0x0070: Identifier slave task byte register    */
    unsigned char RXID;         /**< 0x0070: Received identifier register           */
    unsigned      : 8U;         /**< 0x0070: Reserved                               */
#else
    unsigned      : 8U;         /**< 0x0070: Reserved                               */
    unsigned char RXID;         /**< 0x0070: Received identifier register           */
    unsigned char IDSTB;        /**< 0x0070: Identifier Slave task byte register    */
    unsigned char IDBYTE;       /**< 0x0070: Identifier byte register               */
#endif
    unsigned char TDx[8U];      /**< 0x0074-0x0078: TX buffer register              */
    unsigned      MBRSR;        /**< 0x007C: Maximum baud rate selection register   */
    unsigned      SL;           /**< 0x0080: Pin slew rate register                 */
    unsigned      : 32U;        /**< 0x0084: Reserved                               */
    unsigned      : 32U;        /**< 0x0088: Reserved                               */
    unsigned      : 32U;        /**< 0x008C: Reserved                               */
    unsigned      DFT;          /**< 0x0090: Pin slew rate register                 */
} linBASE_t;


/** @def linREG1
*   @brief LIN1 Register Frame Pointer
*
*   This pointer is used by the LIN driver to access the lin module registers.
*/
#define linREG1 ((linBASE_t *)0xFFF7E400U)


/** @def linPORT1
*   @brief LIN1 GIO Port Register Pointer
*
*   Pointer used by the GIO driver to access I/O PORT of LIN1
*   (use the GIO drivers to access the port pins).
*/
#define linPORT1 ((gioPORT_t *)0xFFF7E440U)


/** @def linREG2
*   @brief LIN2 Register Frame Pointer
*
*   This pointer is used by the LIN driver to access the lin module registers.
*/
#define linREG2 ((linBASE_t *)0xFFF7E500U)


/** @def linPORT2
*   @brief LIN2 GIO Port Register Pointer
*
*   Pointer used by the GIO driver to access I/O PORT of LIN2
*   (use the GIO drivers to access the port pins).
*/
#define linPORT2 ((gioPORT_t *)0xFFF7E540U)


/* LIN Interface Functions */
void     linInit(void);
void     linSetFunctional(linBASE_t *lin, unsigned port);
void     linSendHeader(linBASE_t *lin, unsigned char identifier);
void     linSendWakupSignal(linBASE_t *lin);
void     linSoftwareReset(linBASE_t *lin);
unsigned linIsTxReady(linBASE_t *lin);
void     linSetLength(linBASE_t *lin, unsigned length);
void     linSend(linBASE_t *lin, const unsigned char *data);
unsigned linIsRxReady(linBASE_t *lin);
unsigned linTxRxError(linBASE_t *lin);
unsigned linGetIdentifier(linBASE_t *lin);
void     linGetData(linBASE_t *lin, unsigned char * const data);
void     linEnableNotification(linBASE_t *lin, unsigned flags);
void     linDisableNotification(linBASE_t *lin, unsigned flags);


/** @fn void linNotification(linBASE_t *lin, unsigned flags)
*   @brief Interrupt callback
*   @param[in] lin   - lin module base address
*   @param[in] flags - copy of error interrupt flags
*
* This is a callback that is provided by the application and is called apon
* an interrupt.  The parameter passed to the callback is a copy of the 
* interrupt flag register.
*/
void linNotification(linBASE_t *lin, unsigned flags);
#endif
