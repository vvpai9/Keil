/*----------------------------------------------------------------------------
 *      RL-ARM - FlashFS
 *----------------------------------------------------------------------------
 *      Name:    EM_FILE.C
 *      Purpose: File manipulation example program
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2011 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <RTL.h>                      /* RTL kernel functions & defines      */
#include <stdio.h>                    /* standard I/O .h-file                */
#include <ctype.h>                    /* character functions                 */
#include <string.h>                   /* string and memory functions         */
#include "Em_File.h"
#include "LCD.h"

/* Command Functions */
static void cmd_capture (char *par);
static void cmd_type (char *par);
static void cmd_rename (char *par);
static void cmd_copy (char *par);
static void cmd_delete (char *par);
static void cmd_dir (char *par);
static void cmd_format (char *par);
static void cmd_help (char *par);
static void cmd_fill (char *par);

/* Local constants */
static const char intro[] =
  "\n\n\n\n\n\n\n\n"
  "+------------------------------------------------------------------+\n"
  "|             Embedded Flash File Manipulation example             |\n";
static const char help[] = 
  "+ command -------------+ function ---------------------------------+\n"
  "| CAP fname [/A]       | captures serial data to a file            |\n"
  "|                      |  [/A option appends data to a file]       |\n"
  "| FILL fname [nnnn]    | create a file filled with text            |\n"
  "|                      |  [nnnn - number of lines, default=1000]   |\n"
  "| TYPE fname           | displays the content of a text file       |\n"
  "| REN fname1 fname2    | renames a file to 'fname2'                |\n"
  "| COPY fin [fin2] fout | copies a file 'fin' to 'fout' file        |\n"
  "|                      |  ['fin2' option merges 'fin' and 'fin2']  |\n"
  "| DEL fname            | deletes a file                            |\n"
  "| DIR [mask]           | displays a list of files in the directory |\n"
  "| FORMAT               | formats Embedded Flash Memory             |\n"
  "| HELP  or  ?          | displays this help                        |\n"
  "+----------------------+-------------------------------------------+\n";
static const SCMD cmd[] = {
  "CAP",    cmd_capture,
  "TYPE",   cmd_type,
  "REN",    cmd_rename,
  "COPY",   cmd_copy,
  "DEL",    cmd_delete,
  "DIR",    cmd_dir,
  "FORMAT", cmd_format,
  "HELP",   cmd_help,
  "FILL",   cmd_fill,
  "?",      cmd_help };

#define CMD_COUNT   (sizeof (cmd) / sizeof (cmd[0]))

/* Local variables */
static char in_line[80];

/* Local Function Prototypes */
static void dot_format (U64 val, char *sp);
static char *get_entry (char *cp, char **pNext);
static void init_file (void);

/*----------------------------------------------------------------------------
 *        Initialize On Board LCD Module
 *---------------------------------------------------------------------------*/
static void init_display (void) {
  /* LCD Module.2x16 init*/

  LCD_init ();
  LCD_cur_off ();
  LCD_puts ("    RL-ARM      "
            "Em_File example ");
}

/*----------------------------------------------------------------------------
 *        Process input string for an entry
 *---------------------------------------------------------------------------*/
static char *get_entry (char *cp, char **pNext) {
   char *sp;

  if (cp == NULL) {                           /* skip NULL pointers          */
    *pNext = cp;
    return (cp);
  }

  for ( ; *cp == ' '; cp++) {                 /* skip blanks                 */
    *cp = 0;
  }

  for (sp = cp; *sp != ' ' && *sp != CR && *sp != LF; sp++) {
    *sp = (char)toupper (*sp);                /* convert entry to uppercase  */
  }
  for ( ; *sp == ' ' || *sp == CR || *sp == LF; sp++) {
    *sp = 0;
  }

  *pNext = (*sp) ? sp : NULL;                 /* next entry                  */
  return (cp);
}

/*----------------------------------------------------------------------------
 *        Print size in dotted fomat
 *---------------------------------------------------------------------------*/
static void dot_format (U64 val, char *sp) {

  if (val >= (U64)1e9) {
    sp += sprintf (sp,"%d.",(U32)(val/(U64)1e9));
    val %= (U64)1e9;
    sp += sprintf (sp,"%03d.",(U32)(val/(U64)1e6));
    val %= (U64)1e6;
    sprintf (sp,"%03d.%03d",(U32)(val/1000),(U32)(val%1000));
    return;
  }
  if (val >= (U64)1e6) {
    sp += sprintf (sp,"%d.",(U32)(val/(U64)1e6));
    val %= (U64)1e6;
    sprintf (sp,"%03d.%03d",(U32)(val/1000),(U32)(val%1000));
    return;
  }
  if (val >= 1000) {
    sprintf (sp,"%d.%03d",(U32)(val/1000),(U32)(val%1000));
    return;
  }
  sprintf (sp,"%d",(U32)(val));
}

/*----------------------------------------------------------------------------
 *        Capture serial data to file
 *---------------------------------------------------------------------------*/
static void cmd_capture (char *par) {
  char *fname,*next;
  BOOL append,retv;
  FILE *f;

  fname = get_entry (par, &next);
  if (fname == NULL) {
    printf ("\nFilename missing.\n");
    return;
  }
  append = __FALSE;
  if (next) {
    par = get_entry (next, &next);
      if (strcmp (par, "/A") == 0) {
      append = __TRUE;
    }
    else {
      printf ("\nCommand error.\n");
      return;
    }
  }
  printf ((append) ? "\nAppend data to file %s" :
                     "\nCapture data to file %s", fname);
  printf("\nPress ESC to stop.\n");
  f = fopen (fname,append ? "a" : "w"); /* open a file for writing           */
  if (f == NULL) {
    printf ("\nCan not open file!\n");  /* error when trying to open file    */
    return;
  } 
  do {
    retv = getline (in_line, sizeof (in_line));
    fputs (in_line, f);
  } while (retv == __TRUE);
  fclose (f);                         /* close the output file               */
  printf ("\nFile closed.\n");
}

/*----------------------------------------------------------------------------
 *        Create a file and fill it with some text
 *---------------------------------------------------------------------------*/
static void cmd_fill (char *par) {
  char *fname, *next;
  FILE *f;
  int i,cnt = 1000;

  fname = get_entry (par, &next);
  if (fname == NULL) {
    printf ("\nFilename missing.\n");
    return;
  }
  if (next) {
    par = get_entry (next, &next);
    if (sscanf (par,"%d", &cnt) == 0) {
      printf ("\nCommand error.\n");
      return;
    }
  }

  f = fopen (fname, "w");               /* open a file for writing           */
  if (f == NULL) {
    printf ("\nCan not open file!\n");  /* error when trying to open file    */
    return;
  } 
  for (i = 0; i < cnt; i++)  {
    fprintf (f, "This is line # %d in file %s\n", i, fname);
  }
  fclose (f);                         /* close the output file               */
  printf ("\nFile closed.\n");
}


/*----------------------------------------------------------------------------
 *        Read file and dump it to serial window
 *---------------------------------------------------------------------------*/
static void cmd_type (char *par) {
  char *fname,*next;
  FILE *f;
  int ch;

  fname = get_entry (par, &next);
  if (fname == NULL) {
    printf ("\nFilename missing.\n");
    return;
  }
  printf("\nRead data from file %s\n",fname);
  f = fopen (fname,"r");              /* open the file for reading           */
  if (f == NULL) {
    printf ("\nFile not found!\n");
    return;
  }
 
  while ((ch = fgetc (f)) != EOF) {   /* read the characters from the file   */
    putchar (ch);                     /* and write them on the screen        */
  }
  fclose (f);                         /* close the input file when done      */
  printf ("\nFile closed.\n");
}

/*----------------------------------------------------------------------------
 *        Rename a File
 *---------------------------------------------------------------------------*/
static void cmd_rename (char *par) {
  char *fname,*fnew,*next;

  fname = get_entry (par, &next);
  if (fname == NULL) {
    printf ("\nFilename missing.\n");
    return;
  }
  fnew = get_entry (next, &next);
  if (fnew == NULL) {
    printf ("\nNew Filename missing.\n");
    return;
  }
  if (strcmp (fname,fnew) == 0) {
    printf ("\nNew name is the same.\n");
    return;
  }
  if (frename (fname, fnew) == 0) {
    printf ("\nFile %s renamed to %s\n",fname,fnew);
  }
  else {
    printf ("\nFile rename error.\n");
  }
}

/*----------------------------------------------------------------------------
 *        Copy a File
 *---------------------------------------------------------------------------*/
static void cmd_copy (char *par) {
  char *fname,*fnew,*fmer,*next;
  FILE *fin,*fout;
  U32 cnt,total;
  char buf[512];
  BOOL merge;

  fname = get_entry (par, &next);
  if (fname == NULL) {
    printf ("\nFilename missing.\n");
    return;
  }
  fmer = get_entry (next, &next);
  if (fmer == NULL) {
    printf ("\nNew Filename missing.\n");
    return;
  }
  fnew = get_entry (next, &next);
  if (fnew != NULL) {
    merge = __TRUE;
  }
  else {
    merge = __FALSE;
    fnew = fmer;
  }
  if ((strcmp (fname,fnew) == 0)        ||
      (merge && strcmp (fmer,fnew) == 0)) {
    printf ("\nNew name is the same.\n");
    return;
  }

  fin = fopen (fname,"r");            /* open the file for reading           */
  if (fin == NULL) {
    printf ("\nFile %s not found!\n",fname);
    return;
  }

  if (merge == __FALSE) {
    printf ("\nCopy file %s to %s\n",fname,fnew);
  }
  else {
    printf ("\nCopy file %s, %s to %s\n",fname,fmer,fnew);
  }
  fout = fopen (fnew,"w");            /* open the file for writing           */
  if (fout == NULL) {
    printf ("\nFailed to open %s for writing!\n",fnew);
    fclose (fin);
    return;
  }

  total = 0;
  while ((cnt = fread (&buf, 1, 512, fin)) != 0) {
    fwrite (&buf, 1, cnt, fout);
    total += cnt;
  }
  fclose (fin);                       /* close input file when done          */

  if (merge == __TRUE) {
    fin = fopen (fmer,"r");           /* open the file for reading           */
    if (fin == NULL) {
      printf ("\nFile %s not found!\n",fmer);
    }
    else {
      while ((cnt = fread (&buf, 1, 512, fin)) != 0) {
        fwrite (&buf, 1, cnt, fout);
        total += cnt;
      }
      fclose (fin);
    }
  }
  fclose (fout);
  dot_format (total, &buf[0]);
  printf ("\n%s bytes copied.\n", &buf[0]);
}

/*----------------------------------------------------------------------------
 *        Delete a File
 *---------------------------------------------------------------------------*/
static void cmd_delete (char *par) {
  char *fname,*next;

  fname = get_entry (par, &next);
  if (fname == NULL) {
    printf ("\nFilename missing.\n");
    return;
  }

  if (fdelete (fname) == 0) {
    printf ("\nFile %s deleted.\n",fname);
  }
  else {
    printf ("\nFile %s not found.\n",fname);
  }
}

/*----------------------------------------------------------------------------
 *        Print a Flash Memory Directory
 *---------------------------------------------------------------------------*/
static void cmd_dir (char *par) {
  U64 fsize;
  U32 files;
  char temp[32],*mask,*next;
  FINFO info;

  mask = get_entry (par, &next);
  if (mask == NULL) {
    mask = "*.*";
  }

  printf ("\nFile System Directory...");
  files = 0;
  fsize = 0;
  info.fileID = 0;
  while (ffind (mask,&info) == 0) {
    dot_format (info.size, &temp[0]);
    printf ("\n%-20s %14s ", info.name, temp);
    printf ("  %02d.%02d.%04d  %02d:%02d  ID[%04d]",
             info.time.day, info.time.mon, info.time.year,
             info.time.hr, info.time.min, info.fileID);
    fsize += info.size;
    files++;
  }
  if (info.fileID == 0) {
    printf ("\nNo files...");
  }
  else {
    dot_format (fsize, &temp[0]);
    printf ("\n%9d File(s)    %14s bytes", files, temp);
  }
  dot_format (ffree(""), &temp[0]);
  printf ("\n%35s bytes free.\n",temp);
}

/*----------------------------------------------------------------------------
 *        Format a Flash Memory
 *---------------------------------------------------------------------------*/
static void cmd_format (char *par) {
  U32 retv;

  printf ("\nFormat Embedded Flash Memory? [Y/N]\n");
  retv = getkey();
  if (retv == 'y' || retv == 'Y') {
    /* Format Embedded Flash Memory. "*/
    if (fformat ("F:") == 0) {
      printf ("Flash Bank 1 Memory Formatted.\n");
    }
    else {
      printf ("Formatting failed.\n");
    }
  }
}

/*----------------------------------------------------------------------------
 *        Display Command Syntax help
 *---------------------------------------------------------------------------*/
static void cmd_help (char *par) {
  printf (help);
}

/*----------------------------------------------------------------------------
 *        Initialize a Flash File System
 *---------------------------------------------------------------------------*/
static void init_file (void) {
  U32 retv;

  retv = finit (NULL);
  if (retv == 0) {
    retv = fcheck ("F:");
  }
  if (retv != 0) {
    printf ("\nFlash File System needs Formatting.");
    in_line[0] = 0;
    cmd_format (&in_line[0]);
  }
}

/*----------------------------------------------------------------------------
 *        Main: 
 *---------------------------------------------------------------------------*/

int main (void) {
  char *sp,*next;
  U32 i;

  init_comm ();
  init_display ();
  printf (intro);                             /* display example info        */
  printf (help);

  init_file ();
  while (1) {
    printf ("\nCmd> ");                       /* display prompt              */
    fflush (stdout);
                                              /* get command line input      */
    if (getline (in_line, sizeof (in_line)) == __FALSE) {
      continue;
    }
    sp = get_entry (&in_line[0], &next);
    if (*sp == 0) {
      continue;
    }

    for (i = 0; i < CMD_COUNT; i++) {
      if (strcmp (sp, (const char *)&cmd[i].val)) {
        continue;
      }
      cmd[i].func (next);                     /* execute command function    */
      break;
    }
    if (i == CMD_COUNT) {
      printf ("\nCommand error\n");
    }
  }
}


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
