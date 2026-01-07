/*
 *****************************************************************************
 * Copyright @ 2007 by austriamicrosystems AG                                *
 * All rights are reserved.                                                  *
 *                                                                           *
 * Reproduction in whole or in part is prohibited without the written consent*
 * of the copyright owner. Austriamicrosystems reserves the right to make    *
 * changes without notice at any time. The software is provided as is and    *
 * Austriamicrosystems makes no warranty, expressed, implied or statutory,   *
 * including but not limited to any implied warranty of merchantability or   *
 * fitness for any particular purpose, or that the use will not infringe any *
 * third party patent, copyright or trademark. Austriamicrosystems should    *
 * not be liable for any loss or damage arising from its use.                *
 *****************************************************************************
 */

/*
 *      PROJECT:   AS353x
 *      $Revision: 759 $
 *      LANGUAGE:  ANSI C
*/

/*! \file
 *
 *  \author Harsha Kumar
 *  \author (Substitute)
 *
 *  \brief Definition of AS353x interrupt constants.   
 *  
 *  Definition of AS353x interrupt constants.   
 *
 */

#ifndef _AS3525_INTERRUPTS_H_
#define _AS3525_INTERRUPTS_H_


/*
******************************************************************************
* INCLUDES
******************************************************************************
*/

/*
******************************************************************************
* DEFINES
******************************************************************************
*/

/* Interrupt priority in VIC : The VIC driver priority convention follows 
   that higher priority is indicated by a higher value number.
   We have implemented macros for specifying priorities for Vectored and
   Non vectored interrupts */
   
#define VECTORED_IRQ_HIGH_PRIORITY  33
#define NONVECTORED_IRQ_HIGH_PRIORITY  17

#define VECTORED_IRQ_PRIORITY(priority)  \
                    ((uint8)(VECTORED_IRQ_HIGH_PRIORITY - priority))
                    
#define NONVECTORED_IRQ_PRIORITY(priority) \
                    ((uint8)(NONVECTORED_IRQ_HIGH_PRIORITY - priority))


/* interrupt priority. The priorities given below are tentative. This
   can be changed when desired */

/* VECTORED IRQ PRIORITY */
/* The priority 1 is the highest priority among the Vectored IRQ interrupts. */

#define WDTIMER_INTR_PRIORITY          VECTORED_IRQ_PRIORITY(1)
#define TIMER1_INTR_PRIORITY           VECTORED_IRQ_PRIORITY(2)  
#define TIMER2_INTR_PRIORITY           VECTORED_IRQ_PRIORITY(3)  
#define USB_INTR_PRIORITY              VECTORED_IRQ_PRIORITY(4)
#define DMAC_INTR_PRIORITY             VECTORED_IRQ_PRIORITY(5)
#define NANDFLASH_INTR_PRIORITY        VECTORED_IRQ_PRIORITY(6)
#define IDE_INTR_PRIORITY              VECTORED_IRQ_PRIORITY(7)
#define MCIINTR0_INTR_PRIORITY         VECTORED_IRQ_PRIORITY(8)
#define MCIINTR1_INTR_PRIORITY         VECTORED_IRQ_PRIORITY(9)
#define CELLO_INTR_PRIORITY            VECTORED_IRQ_PRIORITY(10)
#define SSP_INTR_PRIORITY              VECTORED_IRQ_PRIORITY(11)
#define I2C_MS_INTR_PRIORITY           VECTORED_IRQ_PRIORITY(12)
#define I2C_AUDIO_INTR_PRIORITY        VECTORED_IRQ_PRIORITY(13)
#define I2SIN_INTR_PRIORITY            VECTORED_IRQ_PRIORITY(14)
#define I2SOUT_INTR_PRIORITY           VECTORED_IRQ_PRIORITY(15)
#define UART_INTR_PRIORITY             VECTORED_IRQ_PRIORITY(16)



/* NON VECTORED IRQ PRIORITY */
/* The priority 1 is the highest priority among the NON Vectored IRQ interrupts. */

#define GPIO4_INTR_PRIORITY            NONVECTORED_IRQ_PRIORITY(1)
#define GPIO3_INTR_PRIORITY            NONVECTORED_IRQ_PRIORITY(2)
#define GPIO2_INTR_PRIORITY            NONVECTORED_IRQ_PRIORITY(3)
#define GPIO1_INTR_PRIORITY            NONVECTORED_IRQ_PRIORITY(4)
#define MEMSTICK_INTR_PRIORITY         NONVECTORED_IRQ_PRIORITY(5)
#define CGU_INTR_PRIORITY              NONVECTORED_IRQ_PRIORITY(6)
#define SOFTWARE_INTR_PRIORITY         NONVECTORED_IRQ_PRIORITY(7)
#define RESERVED_27_INTR_PRIORITY      NONVECTORED_IRQ_PRIORITY(8)
#define RESERVED_26_INTR_PRIORITY      NONVECTORED_IRQ_PRIORITY(9)
#define RESERVED_25_INTR_PRIORITY      NONVECTORED_IRQ_PRIORITY(10)
#define RESERVED_24_INTR_PRIORITY      NONVECTORED_IRQ_PRIORITY(11)
#define RESERVED_23_INTR_PRIORITY      NONVECTORED_IRQ_PRIORITY(12)
#define RESERVED_22_INTR_PRIORITY      NONVECTORED_IRQ_PRIORITY(14)
#define RESERVED_21_INTR_PRIORITY      NONVECTORED_IRQ_PRIORITY(14)
#define DBOP_INTR_PRIORITY             NONVECTORED_IRQ_PRIORITY(15)
#define RESERVED_17_INTR_PRIORITY      NONVECTORED_IRQ_PRIORITY(16)

/*
******************************************************************************
* GLOBAL MACROS
******************************************************************************
*/

/*
******************************************************************************
* GLOBAL DATA TYPES
******************************************************************************
*/
/*
 * Description:
 * Enumeration of the bit positions of the various interrupt 
 * sources in the each of the interrupt controller registers.
 *
 * This is an opaque type so that the interrupt source can be identified
 * by whatever means the system requires.  The implementation used here
 * specifies the controller in bits 8-11, and the source in bits 0-7
 *
 * System : The system contains one VIC, hence the 8-11 bits
 * have been left as default to 0.  The device drivers must use the
 * elements of apOS_INT_xInterruptSource when referring to the correspoding
 * interrupt source.
 */
typedef enum apOS_INT_xInterruptSource
{
     WDTIMER_INTR_SOURCE         = 0,
     TIMER1_INTR_SOURCE         =  1,
     TIMER2_INTR_SOURCE         =  2,
     USB_INTR_SOURCE            =  3,
     DMAC_INTR_SOURCE           =  4,
     NANDFLASH_INTR_SOURCE      =  5,
     CF_IDE_INTR_SOURCE         =  6,
     MCIINTR0_INTR_SOURCE       =  7,
     MCIINTR1_INTR_SOURCE       =  8,
     AFE_INTR_SOURCE            =  9,
     SSP_INTR_SOURCE            = 10,
     I2C_MS_INTR_SOURCE         = 11,
     I2C_AUDIO_INTR_SOURCE      = 12,
     I2SIN_INTR_SOURCE          = 13,
     I2SOUT_INTR_SOURCE         = 14,
     UART_INTR_SOURCE           = 15,
     GPIO4_INTR_SOURCE          = 16,
     RESERVED_SOURCE_17         = 17,
     CGU_INTR_SOURCE            = 18,
     MEMSTICK_INTR_SOURCE       = 19,
     DBOP_INTR_SOURCE           = 20, 
     RESERVED_SOURCE_21         = 21, 
     RESERVED_SOURCE_22         = 22, 
     RESERVED_SOURCE_23         = 23, 
     RESERVED_SOURCE_24         = 24, 
     RESERVED_SOURCE_25         = 25, 
     RESERVED_SOURCE_26         = 26,
     RESERVED_SOURCE_27         = 27, 
     SOFTWARE_INTR_SOURCE       = 28,
     GPIO1_INTR_SOURCE          = 29,
     GPIO2_INTR_SOURCE          = 30,
     GPIO3_INTR_SOURCE          = 31,
     MAX_INTR_SOURCE
}
apOS_INT_oInterruptSource;


#endif /* _AS3525_INTERRUTPS_H_ */


