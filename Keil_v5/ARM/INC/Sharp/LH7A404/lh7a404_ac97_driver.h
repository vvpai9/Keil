/***********************************************************************
 * $Id:: lh7a404_ac97_driver.h 14 2007-08-28 16:08:18Z kevinw          $
 *
 * Project: LH7A404 AC97 driver
 *
 * Description:
 *     This file contains driver support for the AAC module on the
 *     LH7A404 when used with an AC97 audio CODEC
 *
 * Notes:
 *     Care should be taken to not write AC97 CODEC registers too fast.
 *     Allow about 42uS delay after an operation that performs a raw
 *     CODEC register write. This includes the ac97_reset() and the
 *     following ioctl commands: AC97_SET_VOL, AC97_SET_MIXGAIN,
 *     AC97_SET_TONE, AC97_SET_RCHAN, AC97_SET_RECGAIN, and
 *     AC97_CODEC_WRITE.
 *
 *     There are 3 ways to use this driver.
 *     #1 - Direct software polling
 *         In this mode, the user application continuously checks
 *         the status of the channel. If the FIFO needs data, the
 *         user needs to provided data to the CODEC. This option
 *         will waste a very large amount of time polling the driver
 *         to determine if more data is needed.
 *     #2 - Interrupt driven FIFO mode
 *         In this mode, the driver will generate an interrupt when
 *         more data is needed.
 *     #3 - DMA driven buffer mode
 *         In this mode, the driver will perform a callback to a
 *         user function when another large chunk of data is needed.
 *         This mode is very efficient.
 *
 * Audio driver data formats:
 *     Compacted 12-bit and 16-bit data
 *         This data format is right aligned data in 16-bit data
 *         entries. Compacted data can only be used for stereo audio
 *         sampling. (The AC97 controller FIFO will contain a left
 *         and right sample in a single 32-bit FIFO entry).
 *     Uncompacted 12-bit and 16-bit data
 *         This data format is right aligned data in 16-bit data
 *         entries. This data type can be used for mono, stereo, or
 *         stereo+ (center channel) audio sampling. (The AC97
 *         controller FIFO will place a single 16-bit data sample in a
 *         32-bit FIFO entry).
 *     Uncompacted 18-bit and 20-bit data
 *         This data format is right aligned data in 32-bit data
 *         entries. This data type can be used for mono, stereo, or
 *         stereo+ (center channel) audio sampling. (The AC97
 *         controller FIFO will place a single 32-bit data sample in a
 *         32-bit FIFO entry).
 *
 * Expected supported CODEC functions:
 *     This driver assumes the following CODEC functions are supported:
 *         Variable rate audio sampling on playback (VRA) - this driver
 *             will not work correctly without this support
 *         Bass and Tone control - this driver will work correctly if
 *             the CODEC does not support this
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

#ifndef LH7A404_AC97_DRIVER_H
#define LH7A404_AC97_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lh7a404_aac.h"
#include "lpc_ac97_codec.h"

/***********************************************************************
 * AC97 driver configuration commands (IOCTL commands and arguments)
 **********************************************************************/

/* AC97 driver commands (IOCTL commands) */
typedef enum {
    AC97_ENABLE,      /* Enable or disable the AC97 controller, use
                         arg = 0 to disable, use arg = 1 to enable */
    AC97_DO_RESET,    /* Perform an AC97 reset, use arg = 0 to do a
                         timed (cold) reset, use arg = 1 to do a AC97
                         software reset */
    AC97_SET_VOL,     /* Sets the master volume, aux volume, or mono
                         output volume on the AC97 CODEC, use arg as
                         a pointer to a structure of type
                         AC97_VOLUME_T */
    AC97_SET_MIXGAIN, /* Set a mixer gain, use arg as a pointer to a
                         structure of type AC97_MIX_GAIN_T */
    AC97_SET_TONE,    /* Set tone levels (bass and treble), use arg as
                         a pointer to a structure of type AC97_TONE_T */
    AC97_SET_RCHAN,   /* Set record channel, use arg as a type from
                         AC97_RECORD_T */
    AC97_SET_RECGAIN, /* Set a recording channel gain, use arg as a
                         pointer to a structure of type
                         AC97_REC_GAIN_T */
    AC97_SET_CHANNEL, /* Set channel configuration, use arg as a pointer
                         to a structure of type AC97_CHANNEL_CONFIG_T */
    AC97_INT_START,   /* Start a record or playback session in interrupt
                         mode, use arg as a pointer to a structure of
                         type AC97_BKG_T */
    AC97_DMA_START,   /* Start a record or playback session in DMA
                         mode, use arg as a pointer to a structure of
                         type AC97_BKG_T */
    AC97_STOP,        /* Stop an interrupt or DMA driven playback or
                         record session, use arg = 0 */
    AC97_CODEC_READ,  /* Directly reads a CODEC register, use the lower
                         16 bits of arg as the register number */
    AC97_CODEC_WRITE, /* Directly writes to a CODEC register, use the
                         lower 16 bits of arg as the register number
                         and the upper 16 bits as the value */
    AC97_GET_STATUS   /* Get an AC97 status, use an argument type of
                         AC97_IOCTL_STS_T as the argument to return
                         the correct status */
} AC97_IOCTL_CMD_T;

/* AC97 volume channel selection argument for the AC97_VOLUME_T
   structure */
typedef enum
{
    MASTER_OUT = 0,             /* Master out volume */
    AUX_OUT,                    /* Auxilliary out volume */
    MONO_OUT                    /* Mono out volume */
} AC97_VOLUME_SEL_T;

/* AC97 driver argument for AC97_SET_VOL command (IOCTL arguments) */
typedef struct
{
    AC97_VOLUME_SEL_T select;   /* Volume to change */
    UNS_8             left;     /* Left channel or mono volume TBD */
    UNS_8             right;    /* Right channel volume TBD */
    BOOL_32           mute;     /* Mute flag */
} AC97_VOLUME_T;

/* AC97 record channel selection argument for the AC97_MIX_GAIN_T
   structure */
typedef enum
{
    BEEP_OUT = 0,               /* Beep put mixer selection */
    PHONE_OUT,                  /* Phone out mixer selection */
    MIC_OUT,                    /* MIC out mixer selection */
    LINE_IN,                    /* Line input mixer selection */
    CD_OUT,                     /* CD out mixer selection */
    VIDEO_OUT,                  /* Video out mixer selection */
    AUX_IN,                     /* Aux input mixer selection */
    PCM_OUT                     /* PCM out mixer selection */
} AC97_MIX_GAIN_SEL_T;

/* AC97 driver argument for AC97_SET_MIXGAIN command (IOCTL
   arguments) */
typedef struct
{
    AC97_MIX_GAIN_SEL_T select; /* Channel gain to change */
    UNS_8               left;   /* Left channel or mono gain */
    UNS_8               right;  /* Right channel gain */
    BOOL_32             mute;   /* Mute flag */
} AC97_MIX_GAIN_T;

/* AC97 driver argument for AC97_SET_TONE command (IOCTL arguments) */
typedef struct
{
    UNS_8 bass_gain;            /* Bass gain */
    UNS_8 treble_gain;          /* Treble gain */
} AC97_TONE_T;

/* AC97 driver argument for AC97_SET_RCHAN command (IOCTL arguments) */
typedef enum
{
    MIC_IN_SEL = 0,             /* MIC in record select */
    CD_IN_SEL,                  /* CD in record select */
    VIDEO_IN_SEL,               /* Video in record select */
    AUX_IN_SEL,                 /* Aux in record select */
    LINE_IN_SEL,                /* Line in record select */
    STEREO_MIX_SEL,             /* Stereo mixer record select */
    MONO_MIX_SEL,               /* Mono mixer record select */
    PHONE_SEL                   /* Phone in record select */
} AC97_RECORD_T;

/* AC97 driver argument for AC97_SET_RECGAIN command (IOCTL
   arguments) */
typedef struct
{
    UNS_8 left_gain;            /* Left channel recording gain */
    UNS_8 right_gain;           /* Right channel recording gain */
} AC97_REC_GAIN_T;

/* AC97 Bytes per second playback and record value argument for the
   AC97_CHANNEL_CONFIG_T structure */
typedef enum
{
    BPSEC_8000 = 0,             /* Sample rate is 8KHz */
    BPSEC_11025,                /* Sample rate is 11.026KHz */
    BPSEC_16000,                /* Sample rate is 16KHz */
    BPSEC_22050,                /* Sample rate is 22.05KHz */
    BPSEC_24000,                /* Sample rate is 24KHz */
    BPSEC_32000,                /* Sample rate is 32KHz */
    BPSEC_44100,                /* Sample rate is 44.1KHz */
    BPSEC_48000                 /* Sample rate is 48KHz */
} AC97_SAMPLE_RATE_T;

/* AC97 Bits per sample playback and record value argument for the
   AC97_CHANNEL_CONFIG_T structure */
typedef enum
{
    BPSAM_12 = 0,               /* 12 bits per sample */
    BPSAM_16,                   /* 16 bits per sample */
    BPSAM_18,                   /* 18 bits per sample */
    BPSAM_20                    /* 20 bits per sample */
} AC97_SAMPLE_SIZE_T;

/* AC97 channel direction value argument for the AC97_CHANNEL_CONFIG_T
   structure */
typedef enum {
    PLAYBACK,                   /* Playback channel mode */
    RECORD                      /* Record channel mode */
} AC97_DIRECTION_T;

/* AC97 driver data transfer mode type used for the
   AC97_CHANNEL_CONFIG_T structure */
typedef enum
{
    AC97_POLLED = 0,            /* Polled functions */
    AC97_INTERRUPT,             /* Interrupt driven functions */
    AC97_DMA                    /* DMA driven functions */
} AC97_TMODE_T;

/* AC97 driver argument for AC97_SET_CHANNEL command (IOCTL
   arguments) */
typedef struct
{
    AC97_SAMPLE_RATE_T  srate;  /* Channel sampling rate (will
                                   override all channels) */
    AC97_SAMPLE_SIZE_T  ssize;  /* Channel data size */
    INT_32              channels; /* Number of audio channels (1 =
                                     mono, 2 = stereo, etc.) */
    BOOL_32             compact; /* Use compacted data */
    AC97_DIRECTION_T    dir;    /* Channel direction */
    AC97_TMODE_T        tmode;  /* AC97 driver data transfer mode
                                   type */
} AC97_CHANNEL_CONFIG_T;

/* Function prototype used for polled and interrupt driven audio
   transfers - this is a prototype to a user defined function and
   will be called when the amount of data transferred reaches the
   transfer trip size in the AC97_BKG_T structure */
typedef INT_32 (*AC97_CB_FUNC_T) (INT_32);

/* Structure used for starting an AC97 interrupt driven record or
   playback session */
typedef struct
{
    void           *buffer;            /* Address of where to fetch
                                          or store data */
    UNS_32         transfer_size;      /* Total number of bytes to
                                          transfer */
    UNS_32         transfer_trip_size; /* The number of bytes to
                                          transfer before calling
                                          funcptr() */
    AC97_CB_FUNC_T funcptr;            /* Callback function */
} AC97_BKG_T;

/* Channel statuses used with DMA and interrupt modes - these statuses
   are not valid in polled mode */
typedef enum
{
    CH_FREE = 0,   /* Channel is not being used */
    CH_IDLE,       /* Channel is idle */
    CH_PLAYING,    /* Channel is playing an audio stream */
    CH_RECORDING,  /* Channel is recording an audio stream */
    CH_PAUSED,     /* Channel is paused (DMA mode only) */
    CH_ERROR       /* Error has occured on the channel (DMA mode
                      only) */
} AC97_CH_STATUS_T;

/* AC97 driver arguments for AC97_GET_STATUS command (IOCTL
   arguments) */
typedef enum
{
    AC97_ENABLE_ST,   /* Returns AC97 controller enabled status
                         (1 = enabled, 0 = disabled */
    AC97_CHANNEL_ST,  /* Returns a channel status of type
                         AC97_CH_STATUS_T */
    AC97_TRANSFER_CT  /* Returns the number of bytes transferred in
                         interrupt or DMA modes */
} AC97_IOCTL_STS_T;

/***********************************************************************
 * AC97 driver API functions
 **********************************************************************/

/* Open the AC97 device */
INT_32 ac97_open(void *ipbase,
                 INT_32 arg);

/* Close the AC97 device */
STATUS ac97_close(INT_32 devid);

/* AC97 configuration block */
STATUS ac97_ioctl(INT_32 devid,
                   INT_32 cmd,
                   INT_32 arg);

/* AC97 read function - this function should only be used in polled
   modes. Use the IOCTL AC97_INT_START and AC97_DMA_START commands for
   interrupt and DMA modes */
INT_32 ac97_read(INT_32 devid,
                 void *buffer,
                 INT_32 max_bytes);

/* AC97 write function - this function should only be used in polled
   modes. Use the IOCTL AC97_INT_START and AC97_DMA_START commands for
   interrupt and DMA modes */
INT_32 ac97_write(INT_32 devid,
                  void *buffer,
                  INT_32 n_bytes);

/***********************************************************************
 * Other AC97 driver functions
 **********************************************************************/

/* AC97 Interrupt service routine */
void ac97_isr(void);

#ifdef __cplusplus
}
#endif

#endif /* LH7A404_AC97_DRIVER_H */
