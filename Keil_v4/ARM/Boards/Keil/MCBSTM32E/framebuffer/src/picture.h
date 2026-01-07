
#ifndef __PICTURE_H__
#define __PICTURE_H__

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------

// <e> Use Background Image
#define USE_BACKGROUND   1


#if USE_BACKGROUND
  extern const unsigned short mcbstm32e[173264];
#endif


#define PICT_SIZE         173264
#define PICT_WIDTH        476
#define PICT_HEIGHT       (PICT_SIZE/PICT_WIDTH)
#define PICT_MOVE_SPEED   4                       // 1..10



#endif


