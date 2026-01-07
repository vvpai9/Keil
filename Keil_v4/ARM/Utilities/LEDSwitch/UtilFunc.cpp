#include "stdafx.h"
#include "UtilFunc.h"
#include "LEDSwitch.h"
#include "LEDSwitchDlg.h"


char delim;          /* Result of ngetarg() */

const char del[] = {  ' ', ';', ',', '(', ')', '=', '#',
                      '!', '$', '~', '`', '&',
                      '|', '[', ']', '%', '\n','\r', 0x7f,
                      '{', '}', '\0',                0x1A,  };

/*----------------*/
/* Find Delimiter */
/*----------------*/

char fnddel (char c) {
  WORD  i;

  for (i = 0; i < sizeof(del); i++) {
    if (c == (delim = del [i])) return (1);   /* IS A DELIMITER */
  }
  return (0);                                 /* NOT A DELIMITER */
}

long getnum(char *buf) {
  WORD number, i, len, neg;
  char tmp, base;
  char *nchr;
  WORD oldnumber;
  WORD cmpnumber;


  buf[99] = '\0';
  for (i = 0; i < 100; i++) {       /* convert to uppercase */
    if ((buf[i] = toupper(buf[i])) == '\0') break;
  }
  i = 0;
  while (fnddel(buf[i])) {      /* skip leading delimiter */
    i++;
    if (delim == '\0') return (-1);     /* if no input */
  }
  nchr = &buf[i];
  len = 0;
  for (; i < 100; i++, len++) {         /* determine the length */
    if (fnddel(buf[i])) break;
  }
  len--;

  number = 0;
  base = 10;
  neg = 0;
  cmpnumber = 6554;
  if (*(nchr) == '-') {
    nchr++;
    len--;
    neg = 1;
  }
  if (*(nchr) == '+') {
    nchr++;
    len--;
  }
  if ((*(nchr+len) == 'Q') || (*(nchr+len) == 'O')) {
    base = 8;
    len--;
    cmpnumber = 0x2000;
  }
  if ((*(nchr+1) == 'X') && (base == 10)) {
    base = 16;
    len-=2;
    nchr += 2;
    cmpnumber = 0x1000;
  }
  if ((*(nchr+len) == 'H') && (base == 10)) {
    base = 16;
    len--;
    cmpnumber = 0x1000;
  }
  if ((*(nchr+len) == 'B') && (base == 10)) {
    base = 2;
    len--;
    cmpnumber = 0x8000;
  }
  if ((*(nchr+len) == 'D') && (base == 10)) {
    len--;
  }
  for (i = 0; i <= len; i++) {
    tmp = (*(nchr+i)) - '0';                 /* CHARACTER */
    if ((*(nchr+i)) >= 'A') tmp = (*(nchr+i)) - 'A' + 10;
    if (tmp >= base) return(-1);             /* BAD NUMBER */
    oldnumber = number;
    if (number >= cmpnumber) return(-1);
    number = (number * base) + tmp;
    if (oldnumber > number) return(-1);
  }
  if (neg) number = (~number + 1) & 0xffff;    /* calculate -number with unsigned type */
  return (number);
}

/*
 * Output 2-digit Hexnumber to Text-Control of given Dialog
 * May be used for any Dialog.
 */

void StringHex2 (CWnd * pCWnd, WORD val)  {
  char locbuffer[20];

  sprintf (locbuffer, "0x%02X", val);
  pCWnd->SetWindowText (locbuffer);
}

const char INPUT_ERR_TITLE [] = "Invalid number";
const char INPUT_ERRMSG[]     = "You have entered an invalid number!\n"
                                "The previous value will be restored.\n"
                                "Examples:\n"
                                "0x12   hex number\n"
                                "12H    hex number\n"
                                "200    decimal number\n"
                                "321O   octal number\n"
                                "10101010B    binary number\n";

long GetDlgNumber (CWnd * pCWnd, BYTE oldval) {
  long temp;
  WORD n;
  char lbuf[100];

  n = pCWnd->GetWindowText (lbuf, 100);
  lbuf[n] = '\0';  /* terminate string */
  temp = getnum(lbuf);
  if (temp == -1) {
    MessageBeep(MB_ICONEXCLAMATION);
    pCWnd->MessageBox(&INPUT_ERRMSG[0], &INPUT_ERR_TITLE[0], MB_OK|MB_ICONSTOP);
    StringHex2 (pCWnd, oldval);
    return(-1);
  }
  StringHex2 (pCWnd, (BYTE)temp);
  return(temp);
}

// This function handles a byte input in a dialog
//void HandleByteInput(CWnd * pCWnd, DWORD sfr) {
long HandleByteInput(CWnd * pCWnd, DWORD sfr) {
  BYTE oldval;
  long tmp;

//  oldval = GetSFR(sfr);
  oldval = (BYTE)sfr;
  tmp = GetDlgNumber (pCWnd, oldval);
  if ((tmp != -1) && ((BYTE)tmp != oldval)) {
    return(tmp);
  }
  return(0xFFFF);
}
