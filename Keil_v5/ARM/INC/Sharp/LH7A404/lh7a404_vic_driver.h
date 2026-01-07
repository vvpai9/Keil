/***********************************************************************
 * $Id:: lh7a404_vic_driver.h 14 2007-08-28 16:08:18Z kevinw           $
 *
 * Project: LH7A404 vectored interrupt driver
 *
 * Description:
 *     This file contains driver support for the LH7A404 vectored
 *     interrupt driver.
 *
 ***********************************************************************
 * Software that is described herein is for illustrative purposes only  
 * which provides customers with programming information regarding the  
 * products. This software is supplied "AS IS" without any warranties.  
 * NXP Semiconductors assumes no responsibility or liability for the 
 * use of the software, conveys no license or title under any patent, 
 * copyright, or mask work right to the product. NXP Semiconductors 
 * reserves the right to make changes in the software without 
 * notification. NXP Semiconductors also make no representation or 
 * warranty that such application will be suitable for the specified 
 * use without further testing or modification. 
 *********************************************************************/

#ifndef LH7A404_VIC_DRIVER_H
#define LH7A404_VIC_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lh7a404_vic.h"

/* Interrupt and exception enumerations */
typedef enum
{
   RESET_VEC,
   UNDEFINED_INST_VEC,
   SWI_VEC,
   PREFETCH_ABORT_VEC,
   DATA_ABORT_VEC,
   IRQ_VEC,
   FIQ_VEC,
   VIC1_IRQ_VEC,
   VIC2_IRQ_VEC
} VECTOR_T;

/* Possible interrupt types */
typedef enum {VIC_IRQ, VIC_FIQ, VIC_VECTORED} VIC_INT_T;

/***********************************************************************
 * Vectored Interrupt driver functions
 **********************************************************************/

/* Initialize the vectored interrupt controller */
void vic_initialize(UNS_32 vectbladdr);

/* Install an new ARM interrupt or exception handler */
void vic_install_arm_handler(VECTOR_T handler_id,
                             PFV handler_ptr);

/* Install a function for a specific interrupt */
BOOL_32 vic_install_handler(VIC_INT_SOURCE_T source,
                            VIC_INT_T itype,
                            PFV func_ptr);

/* Enable or disable an interrupt */
void vic_int_enable(VIC_INT_SOURCE_T source,
                    BOOL_32 enable);

/* Check to see if an interrupt is pending */
BOOL_32 vic_int_pending(VIC_INT_SOURCE_T source);

/* Check to see if an interrupt is enabled */
BOOL_32 vic_int_enabled(VIC_INT_SOURCE_T source);

/* Clears the vectored interrupt (called after a vectored interrupt) */
void vic_clear_int(VIC_INT_SOURCE_T source);

/* Default IRQ interrupt dispatcher for VIC1 */
void vic1_irq_dispatcher(void);

/* Default IRQ interrupt dispatcher for VIC2 */
void vic2_irq_dispatcher(void);

#ifdef __ICCARM__ 
/* Default IRQ interrupt dispatcher */
void vic_arm_irq_dispatcher(void);
#endif

#ifdef __GNUC__
/* Default ARM core IRQ interrupt dispatcher */
void vic_arm_irq_dispatcher(void);
#endif

#ifdef __ghs__
/* Default ARM core IRQ interrupt dispatcher */
__interrupt void vic_arm_irq_dispatcher(void);
#endif

#ifdef __arm
/* Default ARM core IRQ interrupt dispatcher */
__irq void vic_arm_irq_dispatcher(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* LH7A404_VIC_DRIVER_H */
