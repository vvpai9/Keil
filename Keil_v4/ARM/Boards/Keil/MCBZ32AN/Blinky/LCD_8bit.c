/******************************************************************************/
/* LCD.c: Functions for 2 line 16 character Text LCD, with 8-bit interface    */
/*        driven by Zilog Z32AN on-chip LCD Controller                        */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2009 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

#include <Z32AN.h>                       /* Zilog Z32AN definitions           */

/*********************** Hardware specific configuration **********************/

/*------------------------- Speed dependant settings -------------------------*/

/* If processor works on high frequency delay has to be increased, it can be 
   increased by factor 2^N by this constant                                   */
#define DELAY_2N     0

/*------------------------- Text LCD size definitions ------------------------*/

#define LineLen     16                  /* Width (in characters)              */
#define NumLines     2                  /* Hight (in lines)                   */

/*-------------------- LCD interface hardware definitions --------------------*/

/* PINS:
   - DB0 = LCD0
   - DB1 = LCD1
   - DB2 = LCD2
   - DB3 = LCD3
   - DB4 = LCD4
   - DB5 = LCD5
   - DB6 = LCD6
   - DB7 = LCD7
   - E   = LCD_E
   - RW  = LCD_RNW
   - RS  = LCD_RS                                                             */
/* Setting all pins to output mode                                            */

#define LCD_ALL_DIR_OUT       BSP_WR32(GPIO1_BASE | GPIO_EN_CLR, (0x07UL<<29)); \
                              BSP_WR32(GPIO2_BASE | GPIO_EN_CLR, (0xFFUL<< 0));

/******************************************************************************/


/* 8 user defined characters to be loaded into CGRAM (used for bargraph)      */
const unsigned char UserFont[8][8] = {
  { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 },
  { 0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10 },
  { 0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18 },
  { 0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C },
  { 0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E },
  { 0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F },
  { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 },
  { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 }
};


/************************ Global function definitions *************************/


/*******************************************************************************
* Delay in while loop cycles                                                   *
*   Parameter:    cnt:    number of while cycles to delay                      *
*   Return:                                                                    *
*******************************************************************************/

void lcd_delay (int cnt)
{
  cnt <<= DELAY_2N;
  while (cnt--);
}


/*******************************************************************************
* Read status of LCD controller                                                *
*   Parameter:    none                                                         *
*   Return:       Status byte contains busy flag and address pointer           *
*******************************************************************************/

static unsigned char lcd_read_status (void)
{
  unsigned long status;

  BSP_WR32(LCD_RD_REG, (1<<9)|(0<<8));  /* Initiate read cycle                */
  do {
    status = BSP_RD32(LCD_RD_REG);
  } while (status & (1<<9));            /* Wait for read operation to finish  */
  return(status & 0xFF);                /* Return read data                   */
}


/*******************************************************************************
* Wait until LCD controller busy flag is 0                                     *
*   Parameter:                                                                 *
*   Return:       Status byte of LCD controller (busy + address)               *
*******************************************************************************/

static unsigned char wait_while_busy (void)
{
  unsigned char status;

  do  {
    status = lcd_read_status();
  }  while (status & 0x80);             /* Wait for busy flag                 */

  return (status);
}


/*******************************************************************************
* Write command to LCD controller                                              *
*   Parameter:    c:      command to be written                                *
*   Return:                                                                    *
*******************************************************************************/

void lcd_write_cmd (unsigned char c)
{
  wait_while_busy();

  BSP_WR32(LCD_WR_REG, (1<<9)|(0<<8)|(c));
  while (BSP_RD32(LCD_WR_REG)&(1<<9));  /* Wait for write operation to finish */
}


/*******************************************************************************
* Write data to LCD controller                                                 *
*   Parameter:    c:      data to be written                                   *
*   Return:                                                                    *
*******************************************************************************/

static void lcd_write_data (unsigned char c)
{
  wait_while_busy();

  BSP_WR32(LCD_WR_REG, (1<<9)|(1<<8)|(c));
  while (BSP_RD32(LCD_WR_REG)&(1<<9));  /* Wait for write operation to finish */
}


/*******************************************************************************
* Print Character to current cursor position                                   *
*   Parameter:    c:      character to be printed                              *
*   Return:                                                                    *
*******************************************************************************/

void lcd_putchar (char c)
{ 
  lcd_write_data (c);
}


/*******************************************************************************
* Initialize the LCD controller                                                *
*   Parameter:                                                                 *
*   Return:                                                                    *
*******************************************************************************/

void lcd_init (void)
{ 
  int i;
  unsigned char const *p;

  /* Set all pins for LCD as outputs                                          */
  LCD_ALL_DIR_OUT

  BSP_WR32(LCD_CTRL_REG, 0x3F3F7703);	  /* Setup Control Register             */

  lcd_write_cmd (0x38);                 /* 2 lines, 5x8 character matrix      */
  lcd_write_cmd (0x0C);                 /* Display ctrl:Disp=ON,Curs/Blnk=OFF */
  lcd_write_cmd (0x01);                 /* Display clear                      */
  lcd_write_cmd (0x06);                 /* Entry mode: Move right, no shift   */

  /* Load user-specific characters into CGRAM                                 */
  lcd_write_cmd(0x40);                  /* Set CGRAM address counter to 0     */
  p = &UserFont[0][0];
  for (i = 0; i < sizeof(UserFont); i++, p++)
    lcd_putchar (*p);

  lcd_write_cmd(0x80);                  /* Set DDRAM address counter to 0     */
}


/*******************************************************************************
* Set cursor position on LCD display                                           *
*   Parameter:    column: column position                                      *
*                 line:   line position                                        *
*   Return:                                                                    *
*******************************************************************************/

void set_cursor (unsigned char column, unsigned char line)
{
  unsigned char address;

  address = (line * 40) + column;
  address = 0x80 + (address & 0x7F);
  lcd_write_cmd (address);              /* Set DDRAM address counter to 0     */
}

/*******************************************************************************
* Clear the LCD display                                                        *
*   Parameter:                                                                 *
*   Return:                                                                    *
*******************************************************************************/

void lcd_clear (void)
{
  lcd_write_cmd (0x01);                 /* Display clear                      */
  set_cursor (0, 0);
}


/*******************************************************************************
* Print sting to LCD display                                                   *
*   Parameter:    string: pointer to output string                             *
*   Return:                                                                    *
*******************************************************************************/

void lcd_print (unsigned char const *string)
{
  while (*string)  {
    lcd_putchar (*string++);
  }
}


/*******************************************************************************
* Display bargraph on LCD display                                              *
*   Parameter:     pos_x: horizontal position of bargraph start                *
*                  pos_y: vertical position of bargraph                        *
*                  width: width used for bargraph in characters                *
*                  value: size of bargraph active field (in %)                 *
*   Return:                                                                    *
*******************************************************************************/

void lcd_bargraphXY (int pos_x, int pos_y, int width, int value) {
  int i;

  value = ((value * width) + 10) / 20;
  set_cursor (pos_x, pos_y);
  for (i = 0; i < width; i++)  {
    if (value > 5) {
      lcd_putchar (0x05);
      value -= 5;
    } else {
      lcd_putchar (value);
      while (++i < width) lcd_putchar (0);
    }
  }
}

/******************************************************************************/
