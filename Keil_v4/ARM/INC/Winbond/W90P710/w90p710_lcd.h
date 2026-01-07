/****************************************************************************
 *                                                                                    
 * Copyright (c) 2004 - 2004 Winbond Electronics Corp. All rights reserved.           
 *                                                                                    
 ***************************************************************************/
 
/****************************************************************************
 * 
 * FILENAME
 *     lcd_controller.h
 *
 * VERSION
 *     1.0
 *
 * DESCRIPTION
 *     The header file for LCD Controller.
 *
 * DATA STRUCTURES
 *     None
 *
 * FUNCTIONS
 *     None
 *
 * HISTORY
 *     12/??/04		 Ver 1.0 Created by PC33 WCCHEN7
 *
 * REMARK
 *     None
 *
 **************************************************************************/

#define LCD_BA    		0xFFF08000 /* Display, LCM Interface & Bypass */
#define SSP_BA    		0xFFF86200 /* Synchronous Serial Port */
#define GPIO_BA			0xFFF83000

#define UINT8 		unsigned char
#define UINT16 	unsigned short
#define UINT32 	unsigned int

#define REG_GPIO_CFG1			((GPIO_BA+0x0010))
#define REG_GPIO_CFG2			((GPIO_BA+0x0020))
#define REG_GPIO_CFG5			((GPIO_BA+0x0050))
#define REG_GPIO_CFG6			((GPIO_BA+0x0060))

/* Select color depth */
#define CONFIG_W90P710_LCD_TFT_16BPP
//#define CONFIG_W90P710_LCD_STN_16BPP

#ifdef CONFIG_W90P710_LCD_TFT
#ifdef CONFIG_W90P710_LCD_TFT_CASIO
#define FB_X_RES       480
#define FB_Y_RES       240
#endif

#ifdef CONFIG_W90P710_LCD_TFT_AUO960240
#define FB_X_RES       960
#define FB_Y_RES       240
#endif

#ifdef CONFIG_W90P710_LCD_TFT_TOPPOLY240320
#define FB_X_RES       240
#define FB_Y_RES       320
#endif

#ifdef CONFIG_W90P710_LCD_TFT_LG
#define FB_X_RES       640
#define FB_Y_RES       480
#endif
#endif

#ifdef CONFIG_W90P710_LCD_STN
#define FB_X_RES       320
#define FB_Y_RES       240
#endif



#ifdef CONFIG_W90P710_LCD_TFT_24BPP
#define FB_BPP         24
#define BURSTY			1
#endif
#if defined(CONFIG_W90P710_LCD_TFT_16BPP ) || defined(CONFIG_W90P710_LCD_STN_16BPP)
#define FB_BPP         16
#define BURSTY		    1 << 1
#endif
#if defined(CONFIG_W90P710_LCD_TFT_8BPP) || defined(CONFIG_W90P710_LCD_STN_8BPP)
#define FB_BPP         8
#define BURSTY			1 << 2
#endif
#if defined(CONFIG_W90P710_LCD_TFT_4BPP) || defined(CONFIG_W90P710_LCD_STN_4BPP)
#define FB_BPP         4
#define BURSTY			1 << 3
#endif
#if defined(CONFIG_W90P710_LCD_TFT_2BPP) || defined(CONFIG_W90P710_LCD_STN_2BPP)
#define FB_BPP         2
#define BURSTY			1 << 4
#endif
#if defined(CONFIG_W90P710_LCD_TFT_1BPP) || defined(CONFIG_W90P710_LCD_STN_1BPP)
#define FB_BPP         1
#define BURSTY			1 << 5
#endif

#define TRANSBURSTY (FB_X_RES / BURSTY)


#if defined(CONFIG_W90P710_LCD_TFT_24BPP) || defined(CONFIG_W90P710_LCD_TFT_18BPP)
#define FB_Size (FB_X_RES * FB_Y_RES * 32 / 8)
#else
#define FB_Size (FB_X_RES * FB_Y_RES * FB_BPP / 8)
#endif

/**********************************************************************************************************
 *                                                               
 * Universal Serial Interface Control Registers  
 *
 **********************************************************************************************************/
#define	REG_USI_CNTRL		(SSP_BA+0x0)     /* Control and Status Register */
#define	REG_USI_DIVIDER		(SSP_BA+0x04)    /* Clock Divider Register */
#define	REG_USI_SSR			(SSP_BA+0x08)    /* Slave Select Register */
#define	REG_USI_Rx0			(SSP_BA+0x10)    /* Data Receive Register 0 */
#define	REG_USI_Rx1			(SSP_BA+0x14)    /* Data Receive Register 1 */
#define	REG_USI_Rx2			(SSP_BA+0x18)    /* Data Receive Register 2 */
#define	REG_USI_Rx3			(SSP_BA+0x1C)    /* Data Receive Register 3 */
#define	REG_USI_Tx0			(SSP_BA+0x10)    /* Data Transmit Register 0 */
#define	REG_USI_Tx1			(SSP_BA+0x14)    /* Data Transmit Register 1 */
#define	REG_USI_Tx2			(SSP_BA+0x18)    /* Data Transmit Register 2 */
#define	REG_USI_Tx3			(SSP_BA+0x1C)    /* Data Transmit Register 3 */

/****************************************************************************************************
 *
 * 710 LCD Controller Register Sets
 *
 ****************************************************************************************************/
/* LCD Controller */
#define REG_LCD_LCDCON           (LCD_BA+0x0000)   /* LCD Controller control register */

/* LCD Interrupt Control */
#define REG_LCD_LCDINTENB        (LCD_BA+0x0004)   /* LCD interrupt enable register */
#define REG_LCD_LCDINTS          (LCD_BA+0x0008)   /* LCD interrupt status register */
#define REG_LCD_LCDINTC          (LCD_BA+0x000C)   /* LCD interrupt clear register */
                            
/* LCD Pre-processing */    
#define REG_LCD_OSDUPSCF         (LCD_BA+0x0010)   /* OSD data Horizontal/Vertical up-scaling factor */
#define REG_LCD_VDUPSCF          (LCD_BA+0x0014)   /* Video data Horizontal/Vertical up-scaling factor */
#define REG_LCD_OSDNSCF          (LCD_BA+0x0018)   /* OSD data Horizontal/Vertical down-scaling factor */
#define REG_LCD_VDDNSCF          (LCD_BA+0x001C)   /* Video data Horizontal/Vertical down-scaling factor */
                            
/* LCD FIFO Control */      
#define REG_LCD_FIFOCON          (LCD_BA+0x0020)   /* LCD FIFOs controller register */
#define REG_LCD_FIFOSTATUS       (LCD_BA+0x0024)   /* LCD FIFOs status register */
#define REG_LCD_FIFO1PRM         (LCD_BA+0x0028)   /* LCD FIFO1 transfer parameters */
#define REG_LCD_FIFO2PRM         (LCD_BA+0x002C)   /* LCD FIFO2 transfer parameters */
#define REG_LCD_F1SADDR          (LCD_BA+0x0030)   /* FIFO1 transfer data source start address */
#define REG_LCD_F2SADDR          (LCD_BA+0x0034)   /* FIFO2 transfer data source start address */
#define REG_LCD_F1DREQCNT        (LCD_BA+0x0038)   /* FIFO1 transfer data count register */
#define REG_LCD_F2DREQCNT        (LCD_BA+0x003C)   /* FIFO2 transfer data count register */
#define REG_LCD_F1CURADR         (LCD_BA+0x0040)   /* FIFO1 current access data address register */
#define REG_LCD_F2CURADR         (LCD_BA+0x0044)   /* FIFO2 current access data address register */
#define REG_LCD_FIFO1RELACOLCNT   (LCD_BA+0x0048)   /* FIFO 1 real column count register */
#define REG_LCD_FIFO2RELACOLCNT  (LCD_BA+0x004C)   /* FIFO 2 real column count register */

/* Color Generation */
#define REG_LCD_LUTENTY1         (LCD_BA+0x0050)   /* TFT: lookup table entry index register */
#define REG_LCD_LUTENTY2         (LCD_BA+0x0054)   /* TFT: lookup table entry index register */
#define REG_LCD_LUTENTY3         (LCD_BA+0x0058)   /* TFT: lookup table entry index register */
#define REG_LCD_LUTENTY4         (LCD_BA+0x005C)   /* TFT: lookup table entry index register */

#define REG_LCD_OSDLUTENTY1      (LCD_BA+0x0060)   /* TFT: lookup table entry index register */
#define REG_LCD_OSDLUTENTY2      (LCD_BA+0x0064)   /* TFT: lookup table entry index register */
#define REG_LCD_OSDLUTENTY3      (LCD_BA+0x0068)   /* TFT: lookup table entry index register */
#define REG_LCD_OSDLUTENTY4      (LCD_BA+0x006C)   /* TFT: lookup table entry index register */
#define REG_LCD_TMDDITHP1        (LCD_BA+0x0070)   /* Gray level dithered data duty pattern */
#define REG_LCD_TMDDITHP2        (LCD_BA+0x0074)   /* Gray level dithered data duty pattern */
#define REG_LCD_TMDDITHP3        (LCD_BA+0x0078)   /* Gray level dithered data duty pattern */
#define REG_LCD_TMDDITHP4        (LCD_BA+0x007C)   /* Gray level dithered data duty pattern */
#define REG_LCD_TMDDITHP5        (LCD_BA+0x0080)   /* Gray level dithered data duty pattern */
#define REG_LCD_TMDDITHP6        (LCD_BA+0x0084)   /* Gray level dithered data duty pattern */
#define REG_LCD_TMDDITHP7        (LCD_BA+0x0088)   /* Gray level dithered data duty pattern */
                             
/* LCD Post-processing */    
#define REG_LCD_DDISPCP          (LCD_BA+0x0090)   /* Dummy Display Color Pattern Register */
#define REG_LCD_DISPWINS         (LCD_BA+0x0094)   /* Valid Display Window Starting Coordinate */
#define REG_LCD_DISPWINE         (LCD_BA+0x0098)   /* Valid Display Window Ending Coordinate */
#define REG_LCD_OSDWINS          (LCD_BA+0x009C)   /* OSD Window Starting Coordinate */
#define REG_LCD_OSDWINE          (LCD_BA+0x00A0)   /* OSD Window Ending Coordinate */
#define REG_LCD_OSDOVCN          (LCD_BA+0x00A4)   /* OSD Overlay Control Register */
#define REG_LCD_OSDKYP           (LCD_BA+0x00A8)   /* OSD Overlay Color-Key Pattern */
#define REG_LCD_OSDKYM           (LCD_BA+0x00AC)   /* OSD Overlay Color-Key Mask */

/* LCD Timing Generation */
#define REG_LCD_LCDTCON1         (LCD_BA+0x00B0)   /* LCD Timing Control Register 1 */
#define REG_LCD_LCDTCON2         (LCD_BA+0x00B4)   /* LCD Timing Control Register 2 */
#define REG_LCD_LCDTCON3         (LCD_BA+0x00B8)   /* LCD Timing Control Register 3 */
#define REG_LCD_LCDTCON4         (LCD_BA+0x00BC)   /* LCD Timing Control Register 4 */
#define REG_LCD_LCDTCON5         (LCD_BA+0x00C0)   /* LCD Timing Control Register 5 */
#define REG_LCD_LCDTCON6         (LCD_BA+0x00C4)   /* LCD Timing Control Register 6 */
                             
/* Look Up Table SRAM */     
#define REG_LCD_LUTADDR          (LCD_BA+0x0100)   /* The start address of Look-Up Table. 
                                                      The memory range is 0x100 ~ 0x4FF. */
/************************************* 
   710 LCD Controller Register Sets 
   - Bits Definition
*************************************/
#define LCD_LCDCON_PPRST     0x20000000     /* LCD Pre-Processor Reset */
#define LCD_LCDCON_LCDRST    0x10000000     /* LCD Controller Reset(except Control Registers) */
#define LCD_LCDCON_LUTWREN   0x04000000     /* Look Up Table SRAM Read/Write Enable */
#define LCD_LCDCON_OSDEN     0x02000000     /* OSD Data Fetch Control */
#define LCD_LCDCON_LCDCEN    0x01000000     /* LCD Controller Enable */
#define LCD_LCDCON_LCDMON8   0x00800000     /* Monochrome LCD has an 8-bit interface */
#define LCD_LCDCON_LCDBW     0x00400000     /* STN LCD is monochrome */
#define LCD_LCDCON_YUVNRGB   0x00200000     /* Image stored in memory device is YUV format or RGB format */
#define LCD_LCDCON_TVEN      0x00100000     /* External TV encoder Enable */
typedef enum {LCD_LCDCON_CASIOSHOWTYPE_R1G1B2R2G3B3 = 0x00000000,
              LCD_LCDCON_CASIOSHOWTYPE_R1G2B3R4G5B6 = 0x00040000, 
              LCD_LCDCON_CASIOSHOWTYPE_R1G1B1R2G2B2 = 0x00080000} 
             LCD_LCDCON_CASIOSHOWTYPE;             /* NEW */
#define LCD_LCDCON_LCDTFTTYPE  0x00020000     /* CASIO LCD */
#define LCD_LCDCON_LCDTFT    0x00010000     /* LCD is TFT */
//#define LCD_LCDCON_LUTEN     0x00020000     /* Look Up Table Enable */
typedef enum {LCD_LCDCON_LCDSEQ_UYVY = 0x00000000,
              LCD_LCDCON_LCDSEQ_YUYV = 0x00001000, 
              LCD_LCDCON_LCDSEQ_VYUY = 0x00002000,              
              LCD_LCDCON_LCDSEQ_YVYU = 0x00003000} 
             LCD_LCDCON_YUVSEQ;             /* YUV output sequence */
typedef enum {LCD_LCDCON_RGBSEQ_RGB = 0x00000000,
              LCD_LCDCON_RGBSEQ_BGR = 0x00000400, 
              LCD_LCDCON_RGBSEQ_GBR = 0x00000800,              
              LCD_LCDCON_RGBSEQ_RBG = 0x00000C00} 
             LCD_LCDCON_RGBSEQ;             /* LCD Line Data Sequence */
typedef enum {LCD_LCDCON_LCDBUS_24 = 0x00000000,
              LCD_LCDCON_LCDBUS_18 = 0x00000100, 
              LCD_LCDCON_LCDBUS_08 = 0x00000200} 
             LCD_LCDCON_LCDBUS;                /* Video Data output re-map */
#define LCD_LCDCON_OSDLUTEN  0x00000080     /* (NEW) */
typedef enum {LCD_LCDCON_OSDBPP_01 = 0x00000000,
 			  LCD_LCDCON_OSDBPP_02 = 0x00000010, 
 			  LCD_LCDCON_OSDBPP_04 = 0x00000020, 
 			  LCD_LCDCON_OSDBPP_08 = 0x00000030,
              LCD_LCDCON_OSDBPP_12 = 0x00000040, 
              LCD_LCDCON_OSDBPP_16 = 0x00000050, 
              LCD_LCDCON_OSDBPP_18 = 0x00000060, 
              LCD_LCDCON_OSDBPP_24 = 0x00000070} 
             LCD_LCDCON_OSDBPP;             /* (NEW) */
#define LCD_LCDCON_VDLUTEN   0x00000008     /* (NEW) */
typedef enum {LCD_LCDCON_BPP_01, LCD_LCDCON_BPP_02, LCD_LCDCON_BPP_04, LCD_LCDCON_BPP_08,
              LCD_LCDCON_BPP_12, LCD_LCDCON_BPP_16, LCD_LCDCON_BPP_18, LCD_LCDCON_BPP_24} 
             LCD_LCDCON_BPP;                /* LCD bits per pixel */

#define LCD_LCDINTENB_UNDREN2  0x00040000   /* FIFO2 UNDERRUN interrupt enable */
#define LCD_LCDINTENB_UNDREN1  0x00020000   /* FIFO1 UNDERRUN interrupt enable */
#define LCD_LCDINTENB_AHBEREN  0x00010000   /* AHB ERROR interrupt enable */
#define LCD_LCDINTENB_HSEN     0x00000020   /* HSYNC interrupt enable */
#define LCD_LCDINTENB_VSEN     0x00000010   /* VSYNC interrupt enable */
#define LCD_LCDINTENB_VLFINEN2 0x00000008   /* FIFO2 VLINE FINISH interrupt enable */
#define LCD_LCDINTENB_VFFINEN2 0x00000004   /* FIFO2 VFRAME FINISH interrupt enable */
#define LCD_LCDINTENB_VLFINEN1 0x00000002   /* FIFO1 VLINE FINISH interrupt enable */
#define LCD_LCDINTENB_VFFINEN1 0x00000001   /* FIFO1 VFRAME FINISH interrupt enable */

#define LCD_LCDINTS_UNDRIS2    0x00040000   /* FIFO2 have no data for output to Panel */
#define LCD_LCDINTS_UNDRIS1    0x00020000   /* FIFO1 have no data for output to Panel */
#define LCD_LCDINTS_AHBERIS    0x00010000   /* AHB master bus error status */
#define LCD_LCDINTS_HSIS       0x00000020   /* Timing Generator output a HSYNC pulse */
#define LCD_LCDINTS_VSIS       0x00000010   /* Timing Generator output a VSYNC pulse */
#define LCD_LCDINTS_VLFINIS2   0x00000008   /* FIFO2 transfer one line stream complete */
#define LCD_LCDINTS_VFFINIS2   0x00000004   /* FIFO2 transfer one frame stream complete */
#define LCD_LCDINTS_VLFINIS1   0x00000002   /* FIFO1 transfer one line stream complete */
#define LCD_LCDINTS_VFFINIS1   0x00000001   /* FIFO1 transfer one frame stream complete */
                               
#define LCD_LCDINTC_UNDRIC2    0x00040000   /* Clear FIFO2 UNDERRUN interrupt */
#define LCD_LCDINTC_UNDRIC1    0x00020000   /* Clear FIFO1 UNDERRUN interrupt */
#define LCD_LCDINTC_AHBERIC    0x00010000   /* Clear MBERROR interrupt */
#define LCD_LCDINTC_HSIC       0x00000020   /* Clear HSYNC interrupt */
#define LCD_LCDINTC_VSIC       0x00000010   /* Clear VSYNC interrupt */
#define LCD_LCDINTC_VLFINIC2   0x00000008   /* Clear FIFO2 VLINEFINSH interrupt */
#define LCD_LCDINTC_VFFINIC2   0x00000004   /* Clear FIFO2 VFRAMFINSH interrupt */
#define LCD_LCDINTC_VLFINIC1   0x00000002   /* Clear FIFO1 VLINEFINSH interrupt */
#define LCD_LCDINTC_VFFINIC1   0x00000001   /* Clear FIFO1 VFRAMFINSH interrupt */

typedef enum {LCD_OSDUPSCF_OSDHUP_1X = 0x00000000, 
              LCD_OSDUPSCF_OSDHUP_2X = 0x00000008, 
              LCD_OSDUPSCF_OSDHUP_4X = 0x00000010} 
             LCD_OSDUPSCF_OSDHUP;           /* OSD Stream Horizontal Up-scaling */
typedef enum {LCD_OSDUPSCF_OSDVUP_1X = 0x00000000, 
              LCD_OSDUPSCF_OSDVUP_2X = 0x00000002, 
              LCD_OSDUPSCF_OSDVUP_4X = 0x00000004} 
             LCD_OSDUPSCF_OSDVUP;           /* OSD Stream Vertical Up-scaling */             

typedef enum {LCD_VDUPSCF_VDHUP_1X = 0x00000000, 
              LCD_VDUPSCF_VDHUP_2X = 0x00000008, 
              LCD_VDUPSCF_VDHUP_4X = 0x00000010} 
             LCD_VDUPSCF_VDHUP;             /* Video Horizontal Up-scaling control */
typedef enum {LCD_VDUPSCF_VDVUP_1X = 0x00000000, 
              LCD_VDUPSCF_VDVUP_2X = 0x00000002, 
              LCD_VDUPSCF_VDVUP_4X = 0x00000004} 
             LCD_VDUPSCF_VDVUP;             /* Video Vertical Up-scaling control */        

#define LCD_FIFOCON_BPP24SW    0x00080000   /* FIFO 24bpp image swap control bit */
#define LCD_FIFOCON_BPP18SW    0x00040000   /* FIFO 18bpp image swap control bit */
#define LCD_FIFOCON_HSWP       0x00020000   /* FIFO half-word swap control bit */
#define LCD_FIFOCON_BSWP       0x00010000   /* FIFO byte swap control bit */
typedef enum {LCD_FIFOCON_FIFOEN_FIFO1 = 0x00000001, 
              LCD_FIFOCON_FIFOEN_FIFO2 = 0x00000002} 
             LCD_FIFOCON_FIFOEN;            /* FIFOs transfer data enable */     
             
typedef enum {LCD_FIFOSTATUS_MASTERID_FIFO1 = 0x00000001, 
              LCD_FIFOSTATUS_MASTERID_FIFO2 = 0x00000002} 
             LCD_FIFOSTATUS_MASTERID;       /* Currently, the data bus master */             
             
#define LCD_FIFO1PRM_F1LOCK    0x00000010   /* FIFO1 lock transfer enable */   
typedef enum {LCD_FIFO1PRM_F1BURSTY_04DATABURST = 0x00000000, 
              LCD_FIFO1PRM_F1BURSTY_08DATABURST = 0x00000004, 
              LCD_FIFO1PRM_F1BURSTY_16DATABURST = 0x00000008} 
             LCD_FIFO1PRM_F1BURSTY;         /* FIFO1 burst transfer type */  
typedef enum {LCD_FIFO1PRM_F1TRANSZ_1BYTE, 
              LCD_FIFO1PRM_F1TRANSZ_2BYTE, 
              LCD_FIFO1PRM_F1TRANSZ_4BYTE} 
             LCD_FIFO1PRM_F1TRANSZ;         /* FIFO1 data width per-transfer */               

#define LCD_FIFO2PRM_F2LOCK    0x00000010   /* FIFO2 lock transfer enable */   
typedef enum {LCD_FIFO2PRM_F2BURSTY_04DATABURST = 0x00000000,  
              LCD_FIFO2PRM_F2BURSTY_08DATABURST = 0x00000004, 
              LCD_FIFO2PRM_F2BURSTY_16DATABURST = 0x00000008} 
             LCD_FIFO2PRM_F2BURSTY;         /* FIFO2 burst transfer type */  
typedef enum {LCD_FIFO2PRM_F2TRANSZ_1BYTE, 
              LCD_FIFO2PRM_F2TRANSZ_2BYTE, 
              LCD_FIFO2PRM_F2TRANSZ_4BYTE} 
             LCD_FIFO2PRM_F2TRANSZ;         /* FIFO2 data width per-transfer */        
             
#define LCD_OSDOVCN_OSDBLI    0x00000200    /* OSD Blinking Control */  
#define LCD_OSDOVCN_OSDCKY    0x00000100    /* OSD Color Key Control */  
typedef enum {LCD_OSDOVCN_OCR1_VIDEO = 0x00000000, 
              LCD_OSDOVCN_OCR1_OSD = 0x00000004,
              LCD_OSDOVCN_OCR1_VIDEOANDOSD = 0x00000008} 
             LCD_OSDOVCN_OCR1;              /* FIFO2 data width per-transfer */   
typedef enum {LCD_OSDOVCN_OCR0_VIDEO, 
              LCD_OSDOVCN_OCR0_OSD,
              LCD_OSDOVCN_OCR0_VIDEOANDOSD} 
             LCD_OSDOVCN_OCR0;              /* FIFO2 data width per-transfer */                

/************************************* 
   Macro Declarations
*************************************/
#if 0

#if 0
($) #define AddMappingEntry(entry, lutEntry) outpb(LCD_LUTENTY1 + (entry), (value))
($) #define RemoveMappingEntry(entry) outpb(LCD_LUTENTY1 + (entry), 0x0)
#endif

#define WriteLUT(entry, value) outpw(REG_LCD_LUTADDR + ((entry) << 2), (value))
#define ReadLUT(entry) inpw(REG_LCD_LUTADDR + ((entry) << 2))

struct w90p710fb_rgb {
    struct fb_bitfield		red;
    struct fb_bitfield		green;
    struct fb_bitfield		blue;
    struct fb_bitfield		transp;
};

struct w90p710fb_lcd_reg {
    unsigned long lcdcon;
    unsigned long lcdfifo;
    unsigned long lcdfifo1para;
    unsigned long lcdfifo1saddr;
    unsigned long lcdfifo1count;    
};

struct w90p710fb_mach_info {
    u_long		pixclock;

    u_short		xres;
    u_short		yres;

    u_char		bpp;
    u_char		hsync_len;
    u_char		left_margin;
    u_char		right_margin;

    u_char		vsync_len;
    u_char		upper_margin;
    u_char		lower_margin;
    u_char		sync;

    u_int		cmap_grayscale:1,
    			cmap_inverse:1,
				cmap_static:1,
		        unused:29;
    u_int		state;

	struct w90p710fb_lcd_reg reg;
#if 0
    unsigned long redlut;
    unsigned long greenlut;
    unsigned long bluelut;

    unsigned long dithmode;
    unsigned long tpal;
#endif
};

#define RGB_8	(0)
#define RGB_16	(1)
#define RGB_24  (2)

#define NR_RGB	3

struct w90p710fb_info {
    struct fb_info		fb;

    signed int			currcon;

    struct w90p710fb_rgb	*rgb[NR_RGB];

    u_int			max_bpp;
    u_int			max_xres;
    u_int			max_yres;

    dma_addr_t		map_dma;
    u_char *		map_cpu;
    u_int			map_size;

    u_char *		screen_cpu;
    dma_addr_t		screen_dma;
    
    u16 *			palette_cpu;
    dma_addr_t		palette_dma; 
    u_int			palette_size;

    u_int			cmap_inverse:1,
    				cmap_static:1,
					unused:30;
    struct w90p710fb_lcd_reg reg;

};

#define outpb(port,value)     (*((UINT8   volatile*)(port))=value)
#define inpb(port)            (*((UINT8   volatile*)(port)))
#define outphw(port,value)    (*((UINT16  volatile*)(port))=value)
#define inphw(port)           (*((UINT16  volatile*)(port)))
#define outpw(port,value)     (*((UINT32  volatile*)(port))=value)
#define inpw(port)            (*((UINT32  volatile*)(port)))

#define W90P710_NAME		"W90P710"

#define MIN_XRES	64
#define MIN_YRES	64

#endif