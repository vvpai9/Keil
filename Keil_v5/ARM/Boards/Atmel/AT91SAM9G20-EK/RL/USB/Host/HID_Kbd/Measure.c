/*------------------------------------------------------------------------------
 *      RL-ARM - USB
 *------------------------------------------------------------------------------
 *      Name:    Measure.c
 *      Purpose: Measure Recorder
 *      Rev.:    V4.70
 *------------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2013 KEIL - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include <RTL.h>
#include <rl_usb.h>
#include <stdio.h>                       /* standard I/O .h-file              */
#include <ctype.h>                       /* character functions               */
#include "Terminal.h"
#include "Serial.h"
#include <AT91SAM9G20.H>

#include "Measure.h"                     /* global project definition file    */

const char menu[] =
   "\n"
   "+***** REMOTE MEASUREMENT RECORDER ****+\n"
   "| This program is a simple Measurement |\n"
   "| Recorder.It is based on the SAM9G20  |\n"
   "| and records the simulated analog     |\n"
   "| voltage as there is no potentiometer.|\n"
   "+ command ----+ function --------------+\n"
   "| R [n]       | read <n> records       |\n"
   "| D           | display measurement    |\n"
   "| T hh:mm:ss  | set time               |\n"
   "| I mm:ss.ttt | set interval time      |\n"
   "| C           | clear records          |\n"
   "| Q           | quit recording         |\n"
   "| S           | start recording        |\n"
   "+-------------+------------------------+\n";

struct interval setinterval;                /* interval setting values        */
struct interval interval;                   /* interval counter               */

volatile int measurement_interval = 0;      /* measurement interval over      */
volatile int mdisplay = 0;                  /* measurement display requested  */
volatile int startflag = 0;                 /* start measurement recording    */

struct mrec current;                        /* current measurements           */

#define SCNT 20                             /* number of records              */

struct mrec save_record[SCNT];              /* buffer for measurements        */
int sindex;                                 /* save index                     */
int savefirst;                              /* save first index               */

char ERR [] = "\n*** ERROR: %s\n";          /* ERROR message string in code   */

#define WRONGINDEX 0xffff                   /* error signal for wrong index   */


/******************************************************************************/
/*               Save current measurements in save_record                     */
/******************************************************************************/
static void save_current_measurements (void) {
  save_record[sindex++] = current;             /* copy current measurements   */
  if (sindex == SCNT) sindex = 0;              /* check bounds of sindex      */
  if (sindex == savefirst)  {                  /* check circular buffer limits*/
    if (++savefirst == SCNT)  savefirst = 0;   /* check bounds of savefirst   */
  }
}


/******************************************************************************/
/*               Initialises the Analog/Digital converter                     */
/******************************************************************************/
void ADC_Init (void) {
  /* no potentiometer on the board */
}


/******************************************************************************/
/*               Get result of the Analog/Digital conversion                  */
/******************************************************************************/
int ADC_GetConversion (void) {
  static U16 val = 0;                          /* Dummy value as there is no  */
                                               /* potentiometer               */
  val++;
  val &= 0x03FF;
  return (val);                                /* AD value (10 bit)           */
}


/******************************************************************************/
/*                Timer interrupt service function                            */
/*                executes each 1ms                                           */
/******************************************************************************/
__irq void PIT_Handler (void) {

  if (measurement_interval)  {                 /* measurement done ?          */
    save_current_measurements ();              /* yes -> save measurements    */
    measurement_interval = 0;                  /* Save measurements done      */
  }
                                               /* check if interval is over   */
  if (interval.min  == 0 &&
      interval.sec  == 0 &&
      interval.msec == 0     )  {
    interval = setinterval;                    /* set interval time again     */
    measurement_interval = startflag;          /* determine measurement flag  */
  }
  else  {                                      /* update interval time        */
    if (interval.msec-- == 0)  {               /* calculate millisecond       */
      interval.msec = 999;
      if (interval.sec-- == 0)  {              /* calculate second            */
        interval.sec = 59;
        interval.min--;                        /* calculate minute            */
      }
    }
  }
                                               /* update current time         */
  if (++current.time.msec == 1000)  {          /* update millisecond cnt      */
    current.time.msec = 0;

    if (++current.time.sec == 60)  {           /* update second counter       */
      current.time.sec = 0;

      if (++current.time.min == 60)  {         /* update minute counter       */
        current.time.min = 0;

        if (++current.time.hour == 24)  {      /* update hour counter         */
          current.time.hour = 0;
        }
      }
    }
  } /* end of if( ++current.time.msec... */

  if (measurement_interval || mdisplay)  {     /* process measurement         */
    current.analog = ADC_GetConversion();
    mdisplay = 0;                              /* mdisplay = 0 for ready sig. */
  }

  *AT91C_AIC_EOICR = AT91C_BASE_PITC->PITC_PIVR;
}


/******************************************************************************/
/*                       Calculate first Read Index                           */
/******************************************************************************/
static int read_index (char *buffer) {
  int index = 0;
  int args;

  if (setinterval.min == 0     &&              /* check if setinterval is     */
      setinterval.sec == 0     &&              /* below 1 second and          */
      setinterval.msec < 999   &&              /* measurements are collected  */
      startflag                   )  {
    printf (ERR, "QUIT MEASUREMENTS BEFORE READ");
    return (WRONGINDEX);                       /* no display on the fly if    */
  }                                            /* interval time < 1 second    */
  args = sscanf (buffer, "%d", &index);        /* scan input for read count   */
  if (args == 0  ||  index == 0  || args == EOF)  index = SCNT;
  index = sindex - index;                      /* calculate first read index  */
  if (index < 0) index += SCNT;                /* from read count             */
  return (index);
}


/******************************************************************************/
/*                         Clear Measurement Records                          */
/******************************************************************************/
static void clear_records (void) {
  int idx;                                     /* index for loop              */

  startflag = 0;                               /* stop measurement collecting */
  sindex = savefirst = 0;                      /* reset circular buffer index */
  for (idx = 0; idx != SCNT; idx++)  {         /* mark all records unused     */
    save_record[idx].time.hour = 0xff;         /* unused flag: hour = 0xff    */
  }
}


/******************************************************************************/
/***************************      MAIN PROGRAM      ***************************/
/******************************************************************************/
int main (void)  {                             /* main entry for program      */
  char cmdbuf [15];                            /* command input buffer        */
  char cmd    =  0;                            /* active command              */
  char con    =  0;                            /* Connection status of kbd    */
  char con_ex =  2;                            /* Previous connection status  */
  char out    =  1;                            /* Output to keyboard LEDs     */
  int  i;                                      /* index for command buffer    */
  int  idx = 0;                                /* index for circular buffer   */

  /* Setup System Timer to generate interrupt every 1 ms                      */
  AT91C_BASE_SYS->PITC_PIMR  = 99072000/16/1000 - 1;
  AT91C_BASE_SYS->PITC_PIMR |= AT91C_PITC_PITIEN;
  AT91C_BASE_AIC->AIC_SVR[AT91C_ID_SYS] = (unsigned int) PIT_Handler;
  AT91C_BASE_AIC->AIC_SMR[AT91C_ID_SYS] = AT91C_AIC_SRCTYPE_INT_LEVEL_SENSITIVE | 1;
  AT91C_BASE_AIC->AIC_IECR   = (1<<AT91C_ID_SYS);     /* Enable ST interrupt  */
  AT91C_BASE_SYS->PITC_PIMR |= AT91C_PITC_PITEN;      /* Run System Timer     */

  SER_Init ();                                 /* Initialize serial inteface  */
  ADC_Init();                                  /* Initialize A/D converter    */
  usbh_init(0);                                /* Initialize USB Host         */

  clear_records ();                            /* initialize circular buffer  */
  printf ( menu );                             /* display command menu        */
  for (i = 0; i < 1000000; i++) {              /* allow kbd connect detect    */
    usbh_engine(0);
    if (usbh_hid_status(0, 0))                 /* if connected, break         */
      break;
  }

  while (1)  {                                 /* loop forever                */
    usbh_engine(0);
    con = usbh_hid_status(0, 0);               /* If kbd connection status    */    
    if (con ^ con_ex) {
      if (con) {
        usbh_hid_data_out (0, 0, (U8 *)&out,1);/* Turn on NUM LED             */
        printf ("\nCommand: ");                /* display prompt              */
      } else {
        printf ("\nConnect the keyboard ...\n");
      }
      con_ex = con;
    }

    if (cmd) {                                 /* if command active           */
COMMAND:
      if (getline (&cmdbuf[0], sizeof (cmdbuf))) {      /* input command line */
        if (cmdbuf[0] == 0x1B) {               /* if ESCAPE key abort command */
          printf ("\n");
          printf ("\nCommand: ");
          cmd = 0;
        }
      }
      if (cmd == 'R') {                        /* cmd: Read circular Buffer   */
        if (idx != sindex)  {                  /* check end of table          */
          if (save_record[idx].time.hour != 0xff)  {
            printf ("\n");
            measure_display (save_record[idx]);/* display record              */
          }
          if (++idx == SCNT) idx = 0;          /* next circular buffer entry  */
        } else {
          printf ("\n");
          printf ("\nCommand: ");
          cmd = 0;
        }
      } else if (cmd == 'D') {                 /* cmd: Display Command        */
        mdisplay = 1;                          /* request measurement         */
        while (mdisplay);                      /* wait for measurement        */
        measure_display (current);             /* display values              */
      }
    } else if (getline (&cmdbuf[0], sizeof (cmdbuf))) { /* input command line */

      for (i = 0; cmdbuf[i] != 0; i++)  {      /* convert to upper characters */
        cmdbuf[i] = toupper(cmdbuf[i]);
      }

      for (i = 0; cmdbuf[i] == ' '; i++);      /* skip blanks                 */

      switch (cmdbuf[i])  {                    /* proceed to command function */

        case 'R':                              /* Read circular Buffer        */
          if ((idx = read_index (&cmdbuf[i+1])) == WRONGINDEX)  break;
          if (save_record[idx].time.hour != 0xff)  {
            printf ("\n");
            measure_display (save_record[idx]);/* display 1st record          */
            if (++idx == SCNT) idx = 0;        /* next circular buffer entry  */
          }
          cmd = 'R';
          goto COMMAND;

        case 'T':                              /* Enter Current Time          */
          set_time (&cmdbuf[i+1]);
          break;

        case 'I':                              /* Enter Interval Time         */
          set_interval (&cmdbuf[i+1]);
          break;

        case 'D':                              /* Display Command             */
          printf ("\nDisplay Measurements: (ESC aborts)\n");
          cmd = 'D';
          goto COMMAND;

        case 'S':                              /* Start Command               */
          printf ("\nStart Measurement Recording\n");
          startflag = 1;
          break;

        case 'Q':                              /* Quit Command                */
          printf ("\nQuit Measurement Recording\n");
          startflag = 0;
          break;

        case 'C':                              /* Clear Command               */
          printf ("\nClear Measurement Records\n");
          clear_records ();
          break;

        default:                               /* Error Handling              */
          printf (ERR, "UNKNOWN COMMAND");
          printf (menu);                       /* display command menu        */
          break;
      }
      printf ("\nCommand: ");
    }
  }
}
