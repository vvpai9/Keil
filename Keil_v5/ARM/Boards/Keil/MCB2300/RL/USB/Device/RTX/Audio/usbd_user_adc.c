/*----------------------------------------------------------------------------
 *      RL-ARM - USB
 *----------------------------------------------------------------------------
 *      Name:    usbd_user_adc.c
 *      Purpose: Audio Device Class User module
 *      Rev.:    V4.70
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2013 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <RTL.h>
#include <rl_usb.h>
#include <LPC23xx.H>

/* Clock Definitions                                                          */
#define CPU_CLOCK      48000000         /* CPU Clock                          */
#define VPB_CLOCK     (CPU_CLOCK/4)     /* VPB Clock                          */

#define PB_INT0        0x00000400       /* Push Button Definitions: P2.10     */
#define LED_MSK        0x000000FF       /* LED Definitions: P2.0..7           */

U16 PotVal;                             /* Potenciometer Value                */
U32 VUM;                                /* VU Meter                           */
U32 Tick;                               /* Time Tick                          */

#ifdef __RTX
__task void volume (void);
#endif
static __irq void usbd_adc_tc1_isr (void);


/*
 * Initialize ADC, DAC, TIM1
 */

void usbd_adc_init (void) {

  PINSEL10 = 0;                         /* Disable ETM interface              */
  PINSEL1  = 0x00204000;                /* Select AOUT,AIN0                   */
  FIO2DIR |= LED_MSK;                   /* LEDs, port 2, bit 0~7 output only  */

  PCONP  |= (1 << 12);                  /* Enable power to AD block           */
  AD0CR   = 0x00200E01;                 /* ADC: 10-bit AIN0 @ 4MHz            */
  DACR    = 0x00008000;                 /* DAC Output set to Middle Point     */

  /* Setup Timer Counter 1: Periodic Timer with Interrupt at 
     usbd_adc_cfg_datafreq Rate                                               */
  T1MR0 = VPB_CLOCK/usbd_adc_cfg_datafreq - 1;  /* TC1 Match Value 0          */
  T1MCR = 3;                            /* TC1 Interrupt and Reset on MR0     */
  T1TCR = 1;                            /* TC1 Enable                         */

  /* Setup Timer Counter 1 Interrupt                                          */
  VICVectAddr5 = (U32)usbd_adc_tc1_isr; /* TC1 Interrupt -> Vector 5          */
  VICVectCntl5 = 0x02;                  /* TC1 Interrupt -> Priority 2        */
  VICIntEnable = 1 << 5;                /* Enable TC1 Interrupt               */

#ifdef __RTX
  os_tsk_create(volume,  1);            /* Create Volume Task                 */
#endif
}


/*
 * Get Potentiometer Value
 */

static void get_potval (void) {
  U32 val;

  AD0CR |= 0x01000000;                  /* Start A/D Conversion               */
  do {
    val  = AD0GDR;                      /* Read A/D Data Register             */
  } while ((val & 0x80000000) == 0);    /* Wait for end of A/D Conversion     */
  AD0CR &= ~0x01000000;                 /* Stop A/D Conversion                */
  PotVal = ((val >> 8) & 0xF8) +        /* Extract Potenciometer Value        */
           ((val >> 7) & 0x08);
}


#ifdef __RTX
/* Volume Task                                                                */
__task void volume (void) {

  for (;;) {
    get_potval();                       /* Get Potenciometer Value            */
    if (USBD_ADC_VolCur == 0x8000) {    /* Check for Minimum Level            */
      USBD_ADC_Volume = 0;              /* No Sound                           */
    } else {
      USBD_ADC_Volume = USBD_ADC_VolCur * PotVal;     /* Chained Volume Level */
    }
    os_dly_wait(5);                     /* Wait 50 ms                         */
  }
}
#endif


/*
 * Timer Counter 1 Interrupt Service Routine
 *   executed each 31.25us (32kHz frequency)
 */

static __irq void usbd_adc_tc1_isr (void) {
  long  val;
  U32 cnt;

  if (USBD_ADC_DataRun) {               /* Data Stream is running             */
    val = USBD_ADC_DataBuf[USBD_ADC_DataOut]; /* Get Audio Sample             */
    /* Buffer Data Count                                                      */
    cnt = (USBD_ADC_DataIn - USBD_ADC_DataOut) & (usbd_adc_cfg_b_s - 1);
    if (cnt == (usbd_adc_cfg_b_s - usbd_adc_cfg_p_c*usbd_adc_cfg_p_s)) {
      /* Too much Data in Buffer                                              */
      USBD_ADC_DataOut++;               /* Skip one Sample                    */
    }
    if (cnt > (usbd_adc_cfg_p_c*usbd_adc_cfg_p_s)) {  /* Still enough Data    */
      USBD_ADC_DataOut++;               /* Update Data Out Index              */
    }
    USBD_ADC_DataOut &= usbd_adc_cfg_b_s - 1;         /* Adjust Buffer Out Idx*/
    if (val < 0) VUM -= val;            /* Accumulate Neg Value               */
    else         VUM += val;            /* Accumulate Pos Value               */
    val  *= USBD_ADC_Volume;            /* Apply Volume Level                 */
    val >>= 16;                         /* Adjust Value                       */
    val  += 0x8000;                     /* Add Bias                           */
    val  &= 0xFFFF;                     /* Mask Value                         */
  } else {
    val = 0x8000;                       /* DAC Middle Point                   */
  }

  if (USBD_ADC_Mute) {
    val = 0x8000;                       /* DAC Middle Point                   */
  }

  DACR = val & 0xFFC0;                  /* Set Speaker Output                 */

  if ((Tick++ & 0x03FF) == 0) {         /* On every 1024th Tick               */
#ifndef __RTX
    get_potval();                       /* Get Potenciometer Value            */
    if (USBD_ADC_VolCur == 0x8000) {    /* Check for Minimum Level            */
      USBD_ADC_Volume = 0;              /* No Sound                           */
    } else {
      USBD_ADC_Volume = USBD_ADC_VolCur * PotVal;     /* Chained Volume Level */
    }
#endif
    val = VUM >> 20;                    /* Scale Accumulated Value            */
    VUM = 0;                            /* Clear VUM                          */
    if (val > 7) val = 7;               /* Limit Value                        */
    FIO2CLR = LED_MSK;                  /* Turn Off all LEDs                  */
    FIO2SET = LED_MSK >> (7 - val);     /* LEDs show VU Meter                 */
  }

  T1IR = 1;                             /* Clear Interrupt Flag               */
  VICVectAddr = 0;                      /* Acknowledge Interrupt              */
}
