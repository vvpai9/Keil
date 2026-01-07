/***********************************************************************
 * $Id:: lh7a404_adc_driver.h 14 2007-08-28 16:08:18Z kevinw           $
 *
 * Project: LH7A404 ADC driver
 *
 * Description:
 *     This file contains driver support for the ADC module on the
 *     LH7A404
 *
 * Notes:
 *     See the lh7a404_adc_driver.c file for more information on this
 *     driver.
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
 **********************************************************************/

#ifndef LH7A404_ADC_DRIVER_H
#define LH7A404_ADC_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lh7a404_adc.h"

/***********************************************************************
 * ADC device configuration commands (IOCTL commands and arguments)
 **********************************************************************/

/* ADC device commands (IOCTL commands) */
typedef enum {
    ADC_SET_CLOCK,   /* Set base speed of ADC clock in Hz, use arg as
                        frequency to set in Hz */
    ADC_CLEAR_FIFO,  /* Clear the ADC sample FIFO, use arg = 0 */
    ADC_ENABLE_IREF, /* Enable or disable the internal reference buffer,
                        use arg = 1 to enable, 0 to disable */
    ADC_CLEAR_INTS,  /* Clear pending ADC interrupts, use arg as an
                        OR'ed value of ADC_EOS_CLR, ADC_PEN_CLR, and
                        ADC_BROWNOUT_CLR */
    ADC_INT_ENABLE,  /* Enable ADC interrupts, use arg as an OR'ed value
                        or ADC_FIFO_OV_INT, ADC_WATERM_INT, ADC_EOS_INT,
                        ADC_PEN_INT, and ADC_GLOBAL_INT - enabling the
                        interrupts will automatically enable the
                        adc_read() function to use the ring buffer for
                        data storage */
    ADC_INT_DISABLE, /* Disable ADC interrupts, use arg as an OR'ed
                        value or ADC_FIFO_OV_INT, ADC_WATERM_INT,
                        ADC_EOS_INT, ADC_PEN_INT, and ADC_GLOBAL_INT -
                        disabling the interrupts will automatically
                        enable the adc_read() function to read data
                        directly from the FIFOs when called */
    ADC_INSTALL_BRO, /* Install the brownout interrupt callback
                        function. Use arg as address of function to call
                        when a brownout interrupt occurs */
    ADC_INSTALL_PDC, /* Install the pendown interrupt callback function.
                        Use arg as address of function to call when a
                        pendown interrupt occurs */
    ADC_INSTALL_EOS, /* Install the end of sequence interrupt callback
                        function. Use arg as address of function to call
                        when a end of sequence completes */
    ADC_SET_IDLE_CH, /* Configure or reconfigure the ADC inputs used
                        during idle mode, use arg as a pointer of type
                        ADC_CH_CONV_T */
    ADC_SET_WMLEVEL, /* Set ADC FIFO watermark (interrupt trip) level,
                        use arg as a value between 1 and 16 */
    ADC_ADD_CHANNEL, /* Add a conversion sequence entry, use arg as a
                        pointer of type ADC_CH_CONV_T (note that
                        mutliple entries of the same type may be added
                        to the conversion sequence list), returns a key
                        to the entry that has to be used as the argument
                        with the ADC_CHG_CHANNEL command */
    ADC_CHG_CHANNEL, /* Changes a conversion sequence entry with the
                        passed key argument, arg must be a value that
                        was previously returned with the ADC_ADD_CHANNEL
                        command */
    ADC_START_SAMP,  /* Starts an ADC sample (goes through a conversion
                        list and stops and used when ADC_SET_STATE is
                        set to ADC_SW_TRIGGERED), use arg = 0 */
    ADC_SET_STATE,   /* Set sampling state, use arg as a value of type
                        ADC_SSTATE_T */
    ADC_GET_STATUS   /* Get an ADC status, use an argument type of
                        ADC_IOCTL_STS_T as the argument to return the
                        correct status */
} ADC_IOCTL_CMD_T;

/* Possible ADC and driver modes - these modes defines how the ADC
   controller and driver will work and are used with the ADC_SET_STATE
   IOCTL command */
typedef enum
{
    /* The ADC controller is configured to it's default settings and
       the placed in a low power state. The conversion sequence list
       is cleared. */
    ADC_MODE_RESET,
    /* The ADC controller is placed into a low power state and stopped,
       but the sequence list and ADC controller configuration are
       unchanged */
    ADC_MODE_STOP,
    /* The ADC controller is placed into idle mode and will wait for
       the IOCTL ADC_START_SAMP command. When the command is given, the
       ADC will convert the data as defined by the programmed sequence
       list and then stop. The data can be read with the adc_read()
       function shortly after the ADC_START_SAMP command. */
    ADC_SW_TRIGGERED,
    /* The ADC controller is placed into idle mode and will wait for
       a pendown condition. When the condition occurs, the ADC will
       convert the data as defined by the sequence list and generate
       an interrupt. The data can be read with the adc_read()
       function. If the pendown callback function is installed, it
       will be called when the conversion is complete. */
    ADC_PENDOWN_TRIGGERED,
    /* The ADC controller is placed into a mode where pendown events
       and a software command will trigger a conversion event */
    ADC_PENDOWN_SW_TRIGGERED,
    /* The ADC controller is placed into continuous conversion mode.
       The data can be read with the adc_read() function */
    ADC_CONTINUOUS
} ADC_SSTATE_T;

/* ADC input channel positive selection enumeration list */
typedef enum
{
    ADC_NOT_USED = -1, /* ADC no channel */    
    ADC_ANALOG_0 = 0,  /* ADC analog channel 0 input */
    ADC_ANALOG_1,      /* ADC analog channel 1 input */
    ADC_ANALOG_2,      /* ADC analog channel 2 input */
    ADC_ANALOG_3,      /* ADC analog channel 3 input */
    ADC_ANALOG_4,      /* ADC analog channel 4 input */
    ADC_ANALOG_5,      /* ADC analog channel 5 input */
    ADC_ANALOG_6,      /* ADC analog channel 6 input */
    ADC_ANALOG_7,      /* ADC analog channel 7 input */
    ADC_ANALOG_8,      /* ADC analog channel 8 input */
    ADC_ANALOG_9,      /* ADC analog channel 9 input */
    ADC_ANALOG_10      /* ADC analog channel 10 input */
} ADC_INPUTP_CH_T;

/* ADC input channel negative selection enumeration list */
typedef enum
{
    ADC_REFN_VREFN = 0, /* Use VREF- as negative reference */
    ADC_REFN_GND       /* Use ground as negative reference */
} ADC_INPUTN_CH_T;

/* ADC positive channel reference selection type */
typedef enum
{
    ADC_REFP_VREF = 0, /* Use VREF+ as postive reference */
    ADC_REFP_AN0,      /* Use AN0 as postive reference */
    ADC_REFP_AN2,      /* Use AN2 as postive reference */
    ADC_REFP_VN8       /* Use AN8 as postive reference */
} ADC_VREFP_T;

/* ADC negative channel reference selection type */
typedef enum
{
    ADC_REFN_VREF = 0, /* Use VREF- as negative reference */
    ADC_REFN_AN1,      /* Use AN1 as negative reference */
    ADC_REFN_AN3,      /* Use AN3 as negative reference */
    ADC_REFN_VN9       /* Use AN9 as negative reference */
} ADC_VREFN_T;

/* ADC channel configuration structure, used to add an ADC channel
   into the conversion sequence, used with ADC_SET_CHANNEL command */
typedef struct
{
    INT_32 chkey;         /* ADC channel key used with ADC_CHG_CHANNEL
                             command, set to 0 with ADC_ADD_CHANNEL
                             command */
    UNS_16 settle_clks;   /* Number of settling clocks per sample */
    ADC_INPUTP_CH_T inpc; /* ADC + input tied to MUX channel */
    ADC_INPUTN_CH_T innc; /* ADC - input tied to MUX channel */
    ADC_VREFP_T vrefp;    /* Positive analog sample reference */
    ADC_VREFN_T vrefn;    /* Negative analog sample reference */
    UNS_32 bias;          /* Bias FET enable bits - for each bit
                             enabled, the FET associated with that bit
                             will be turned on - see the ADC
                             documentation on bias uses - this should
                             ne an OR'ed combination of
                             ADC_FET_ANx_xxx (see lh7a404_adc.h) */
} ADC_CH_CONV_T;

/* ADC device arguments for ADC_GET_STATUS command (IOCTL arguments) */
typedef enum {
    ADC_RAWINT_ST,  /* Returns raw interrupt status, an OR'ed value
                       of ADC_FIFO_OV_IRQ, ADC_WATERM_IRQ, ADC_EOS_IRQ,
                       ADC_PEN_IRQ, and ADC_BROWNOUT_IRQ */
    ADC_INT_ST,     /* Returns pending (enabled) interrupt statuses, an
                       OR'ed value of ADC_FIFO_OV_IRQ, ADC_WATERM_IRQ,
                       ADC_EOS_IRQ, ADC_PEN_IRQ, and ADC_BROWNOUT_IRQ */
    ADC_CONV_COUNT  /* Return the number of conversions in the
                       conversion count sequence */
} ADC_IOCTL_STS_T;

/***********************************************************************
 * ADC driver API functions
 **********************************************************************/

/* Open the ADC */
INT_32 adc_open(void *ipbase,
                INT_32 arg);

/* Close the ADC */
STATUS adc_close(INT_32 devid);

/* ADC configuration block */
STATUS adc_ioctl(INT_32 devid,
                 INT_32 cmd,
                 INT_32 arg);

/* ADC read function (polled) */
INT_32 adc_read_polled(INT_32 devid,
                       void *buffer,
                       INT_32 max_bytes);

/* ADC read function (interrupt, ring buffer) */
INT_32 adc_read_ring(INT_32 devid,
                     void *buffer,
                     INT_32 max_bytes);

/* ADC write function (stub only) */
INT_32 adc_write(INT_32 devid,
                 void *buffer,
                 INT_32 n_bytes);

/***********************************************************************
 * ADC driver miscellaneous functions
 **********************************************************************/

/* ADC interrupt handler */
void adc_isr(void);

/* The data that is returned from the adc_read() function returns a
   value that has data and the analog input number mixed into it. This
   function strips off the analog input number and returns only the
   converted 10-bit data value right justified into a 16-bit field */
UNS_16 adc_strip_data(UNS_16 data);

/* The data that is returned from the adc_read() function returns a
   value that has data and the analog input number mixed into it. This
   function strips off the converted data and returns only the analog
   input channel number (this returned value matches the key value
   return with the ADC_ADD_CHANNEL IOCTL command */
UNS_16 adc_strip_input(UNS_16 data);

#ifdef __cplusplus
}
#endif

#endif /* LH7A404_ADC_DRIVER_H */
