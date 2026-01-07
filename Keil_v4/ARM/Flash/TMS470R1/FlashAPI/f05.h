#define F05

/* define macros */

/* The DUALCPU flag can be specified in your cl470 CFLAGS as '-dDUALCPU'
 * or explicitly in a previous included header file using '#define DUALCPU'
 */
#ifdef DUALCPU
#define ENA_CLEAN  *(volatile UINT32 *)0xffffff50=0;
#define DIS_CLEAN *(volatile UINT32 *)0xffffff50=1;
#define CLEAN(x) *(volatile UINT32 *)0xffffff40=x;x=*(volatile UINT32 *)0xffffff40;
#else
#define ENA_CLEAN
#define DIS_CLEAN
#define CLEAN(x)
#endif /* DUALCPU */

#define READ_FLASH_MEM_U16(a,x) x=*(volatile UINT16 *)a;CLEAN(x);
#define READ_FLASH_MEM_U8(a,x) x=*(volatile UCHAR *)a;CLEAN(x);

/* The PLATFORM flag can be specified in your cl470 CFLAGS as '-dPLATFORM'
 * or explicitly in a previous included header file using '#define PLATFORM'
 */
#ifdef PLATFORM

/* macros */
#define SET_CFG_BIT
#define CLR_CFG_BIT
#define READ_FLASH_MEM_U32(a,x) { UINT32 y;x=*(volatile UINT16 *)a;CLEAN(x);y=*(volatile UINT16 *)((UINT32)a+sizeof(UINT16));CLEAN(y);x<<=16;x|=y;}

/* register offsets */
#define FMREGOPT       0x0100/4 /* FMREGOPT[31:5] Reserved
                                 * FMREGOPT[4]=SPOTP
                                 * FMREGOPT[3]=RDMRGN1
                                 * FMREGOPT[2]=RDMRGN0
                                 * FMREGOPT[1]=READOTP
                                 * FMREGOPT[0]=ENPIPE
			         */

#define FMBBUSY        0x0108/4 /* FMBBUSY[31:16] Reserved
                                 * FMBBUSY[15]=PROTL2DIS
                                 * FMBBUSY[14:8] Reserved
                                 * FMBBUSY[7:0]=BUSY[7:0]
			         */

#define FMPKEY         0x010c/4 /* FMPKEY[31:00] Expected Protection Key
				 */

#define FMEDACCTRL1    0x0110/4 /* FMEDACCTRL1[31:12]=Reserved
				 * FMEDACCTRL1[11]=ECC-MAP
				 * FMEDACCTRL1[10]=EOFEN
				 * FMEDACCTRL1[9]=EZFEN
				 * FMEDACCTRL1[8]=EPEN
				 * FMEDACCTRL1[7:6]=Reserved
				 * FMEDACCTRL1[5]=EOCV
				 * FMEDACCTRL1[4]=EZCV
				 * FMEDACCTRL1[3:0]=EDACEN[3:0]
				 */

#define FMEDACCTRL2    0x0114/4 /* FMEDACCTRL2[31:16]=Reserved
				 * FMEDACCTRL2[15:0]=SEC_THRESHOLD[15:0]
				 */

#define FMEDACCNT      0x0118/4 /* FMEDACCNT[31:16]=Reserved
				 * FMEDACCNT[15:0]=SEC_OCCR[15:0]
				 */

#define FMCERRADDR     0x011c/4 /* FMCERRADDR[31:16]=Reserved
			         * FMCERRADDR[15:0]=CERRADDR[15:0]
			         */

#define FMCERRPOSITION 0x0120/4 /* FMCERRPOSITION[31:9]=Reserved
			         * FMCERRPOSITION[8]=ERRTYPE
			         * FMCERRPOSITION[7]='0'
			         * FMCERRPOSITION[6]='0'
			         * FMCERRPOSITION[5:0]=SERRPOSITION[5:0]
			         */

#define FMEDACSTATUS   0x0124/4 /* FMEDACSTATUS[31:3]=Reserved
			         * FMEDACSTATUS[2]=EOFS
			         * FMEDACSTATUS[1]=EZFS
			         * FMEDACSTATUS[0]=EPS
			         */

#define FMUERRADDR     0x0128/4 /* FMUERRADDR[31:24]=Reserved
			         * FMUERRADDR[23:16]=UERRADDR[23:16]
			         * FMUERRADDR[15:0]=UERRADDR[15:0]
			         */

#define FMEMUDMSW      0x012c/4 /* FMEMUDMSW[31:16]=EMUDW[63:48]
			         * FMEMUDMSW[15:0]=EMUDW[47:32]
			         */

#define FMEMUDLSW      0x0130/4 /* FMEMUDLSW[31:16]=EMUDW[31:16]
			         * FMEMUDLSW[15:0]=EMUDW[15:0]
			         */

#define FMEMUECC       0x0134/4 /* FMEMUECC[31:8]=Reserved
			         * FMEMUECC[7:0]=EMUECC[7:0]
			         */

#define FMSECDIS       0x0138/4 /* FMSECDIS[31:29]=bankID1_inverse[2:0]
			         * FMSECDIS[28:24]=SectorID1_inverse[4:0]
			         * FMSECDIS[23:21]=bankID1[2:0]
			         * FMSECDIS[20:16]=SectorID1[4:0]
			         * FMSECDIS[15:13]=bankID0_inverse[2:0]
			         * FMSECDIS[12:8]=SectorID0_inverse[4:0]
			         * FMSECDIS[7:5]=bankID0[2:0]
			         * FMSECDIS[4:0]=SectorID0[4:0]
			         */

#define FMDIAGCTRL     0x0134/4 /* FMDIAGCTRL[31:10]=Reserved
			         * FMDIAGCTRL[9]=DUERR
			         * FMDIAGCTRL[8]=DCERR
			         * FMDIAGCTRL[7:2]=Reserved
			         * FMDIAGCTRL[1:0]=DIAGMODE[1:0]
			         */

/* 16 bit Flash control registers */

#define FMBAC1         0x0000/4 /* FMBAC1[15:8]=BAGP[7:0]
			         * FMBAC1[7:2]=BSTDBY[5:0]
			         * FMBAC1[1:0]=BNKPWR[1:0]
			         */

#define FMBAC2         0x0004/4 /* FMBAC2[15]=OTPPROTDIS
			         * FMBAC2[14:8]=BLEEP[6:0]
			         * FMBAC2[7:4]=PAGEWAIT[3:0]
			         * FMBAC2[3:0]=READWAIT[3:0]
			         */

#define FMBSEA         0x0008/4 /* FMBSEA[15:0]=Enable sectors 15:0
			         */

#define FMBSEB         0x000c/4 /* FMBSEB[15:0]=Enable sectors 31:16
			         */

#define FMBRDY         0x0010/4 /* FMBRDY[15:6]=Reserved
			         * FMBRDY[5]=BANKRDY
			         * FMBRDY[4:0]=Reserved
			         */

#define FMPRDY         0x0014/4 /* FMPRDY[15:10]=Reserved
			         * FMPRDY[9]=PUMPRDY
			         * FMPRDY[8:0]=Reserved
			         */

#define FMMAC1         0x0018/4 /* FMMAC1[15]=PROTL1DIS
			         * FMMAC1[14:0]=PSLEEP[14:0]
			         */

#define FMMAC2         0x001c/4 /* FMMAC2[15:5]=PSTDBY[10:0]
			         * FMMAC2[4:3]=PMPPWR[1:0]
			         * FMMAC2[2:0]=BANK[2:0]
			         */

#define FMPAGP         0x0020/4 /* FMPAGP[15:0]=PAGP[15:0]
			         */

#define FMMSTAT        0x0024/4 /* FMMSTAT[15:9]=Reserved
			         * FMMSTAT[8]=BUSY
			         * FMMSTAT[7]=ERS
			         * FMMSTAT[6]=PGM
			         * FMMSTAT[5]=INVDAT
			         * FMMSTAT[4]=CSTAT/MAXPLS
			         * FMMSTAT[3]=3VSTAT
			         * FMMSTAT[2]=ESUSP
			         * FMMSTAT[1]=PSUSP
			         * FMMSTAT[0]=SLOCK
			         */

/* other registers */
#define FMTCREG        0x0028/4 /* FMTCREG[15:0] */
#define FMPTR0         0x0300/4 /* FMPTR0[15:0] */
#define FMPTR1         0x0304/4 /* FMPTR1[15:0] */
#define FMPTR2         0x0308/4 /* FMPTR2[15:0] */
#define FMPTR3         0x030c/4 /* FMPTR3[15:0] */
#define FMPTR4         0x0310/4 /* FMPTR4[15:0] */
#define FMPESETUP      0x0218/4 /* FMPESETUP[15:0] */
#define FMCSETUP       0x0220/4 /* FMCSETUP[15:0] */
#define FMPVEVSETUP    0x0224/4 /* FMPVEVSETUP[15:0] */
#define FMPCHOLD       0x0234/4 /* FMPCHOLD[15:0] */
#define FMEHOLD        0x0238/4 /* FMEHOLD[15:0] */
#define FMPVEVHOLD     0x0240/4 /* FMPVEVHOLD[15:0] */
#define FMCVHOLD       0x0248/4 /* FMCVHOLD[15:0] */
#define FMPWIDTH       0x0250/4 /* FMPWIDTH[15:0] */
#define FMEWIDTH       0x0254/4 /* FMEWIDTH[15:0] */
#define FMCWIDTH       0x0258/4 /* FMCWIDTH[15:0] */
#define FMPVEVACCESS   0x025c/4 /* FMPVEVACCESS[15:0] */
#define FMCVACCESS     0x0260/4 /* FMCVACCESS[15:0] */
#define FMWSMREG       0x026c/4 /* FMWSMREG[15:0] */
#define FMMAXPP        0x027c/4 /* FMMAXPP[15:0] */
#define FMMAXEP        0x0280/4 /* FMMAXEP[15:0] */
#define FMMAXCP        0x0284/4 /* FMMAXCP[15:0] */
#define FMPLSCNT       0x0288/4 /* FMPLSCNT[15:0] */
#define FMADDRCTRLOW   0x0298/4 /* FMADDRCTRLOW[15:0] */

/* define aliases for PLATFORM */
#define REGOPT     FMREGOPT
#define BAC1       FMBAC1
#define BAC2       FMBAC2
#define BBUSY      FMBBUSY
#define PROTKEY    FMPKEY
#define BSEA       FMBSEA
#define BSEB       FMBSEB
#define BRDY       FMBRDY
#define PRDY       FMPRDY
#define MAC1       FMMAC1
#define MAC2       FMMAC2
#define PAGP       FMPAGP
#define MSTAT      FMMSTAT
#define TCR        FMTCREG
#define PTR0       FMPTR0
#define PTR1       FMPTR1
#define PTR2       FMPTR2
#define PTR3       FMPTR3
#define PTR4       FMPTR4
#define DPTR       FMBRDY
#define BPTR       FMPRDY
#define PESETUP    FMPESETUP
#define CSETUP     FMCSETUP
#define PVEVSETUP  FMPVEVSETUP
#define PCHOLD     FMPCHOLD
#define EHOLD      FMEHOLD
#define PVEVHOLD   FMPVEVHOLD
#define CVHOLD     FMCVHOLD
#define PWIDTH     FMPWIDTH
#define EWIDTH     FMEWIDTH
#define CWIDTH     FMCWIDTH
#define PVEVACCESS FMPVEVACCESS
#define CVACCESS   FMCVACCESS
#define WSMREG     FMWSMREG
#define MAXPP      FMMAXPP
#define MAXEP      FMMAXEP
#define MAXCP      FMMAXCP
#define ADDRCTRLOW FMADDRCTRLOW
#define MAX_PROG_PULSE FMMAXPP
#define PULSE_COUNTER FMPLSCNT

#else /* not PLATFORM */

/* macros */
#define SET_CFG_BIT *(volatile UINT32 *)0xffffffdc|=0x10;ENA_CLEAN;
#define CLR_CFG_BIT DIS_CLEAN;*(volatile UINT32 *)0xffffffdc&=~0x10;
#define READ_FLASH_MEM_U32(a,x) x=*(volatile UINT32 *)a;CLEAN(x);

/* register offsets */
#define BAC1               0x0000/4
#define BAC2               0x0004/4
#define BSEA               0x0008/4
#define BSEB               0x000c/4
#define DPTR               0x0010/4
#define REGOPT             0x1c00/4
#define BBUSY              0x1c08/4
#define PROTKEY            0x1c0c/4
#define PESETUP            0x2018/4
#define CSETUP             0x2020/4
#define PVEVSETUP          0x2024/4
#define PCHOLD             0x2034/4
#define EHOLD              0x2038/4
#define PVEVHOLD           0x2040/4
#define CVHOLD             0x2048/4
#define PWIDTH             0x2050/4
#define EWIDTH             0x2054/4
#define CWIDTH             0x2058/4
#define PVEVACCESS         0x205c/4
#define CVACCESS           0x2060/4
#define WSMREG             0x206c/4
#define MAXPP              0x207c/4
#define MAXEP              0x2080/4
#define MAXCP              0x2084/4
#define PULSE_COUNTER      0x2088/4
#define ADDRCTRLOW         0x2098/4
#define PTR1               0x2804/4
#define PTR2               0x2808/4
#define PTR3               0x280c/4
#define PTR4               0x2810/4
#define BPTR               0x2814/4
#define CTR0               0x2818/4
#define CTR1               0x281c/4
#define CTR2               0x2820/4
#define CTR3               0x2824/4
#define DATALATCH          0x2828/4
#define MAC1               0x3c00/4
#define MAC2               0x3c04/4
#define PAGP               0x3c08/4
#define MSTAT              0x3c0c/4
#define TCR                0x3c10/4
#define MAX_PROG_PULSE     MAXPP
#endif /* not PLATFORM */

/* WSMREG values */
#define PROG_PULSE_ACTIVE  0x0028
#define ERASE_PULSE_ACTIVE 0x0044
#define CMPCT_PULSE_ACTIVE 0x0064

/* REGOPT modes */
#define READMODE           0x00
#define PIPEMODE           0x01
#define RDM0MODE           0x04
#define RDM1MODE           0x08

/* constants and timings */

/* The MAX_DELAY value can be specified in your cl470 CFLAGS as '-dMAX_DELAY=<x>'
 * or explicitly in a previous included header file using '#define MAX_DELAY <x>'
 */
#ifndef MAX_DELAY
#define MAX_DELAY 12
#endif

#if (MAX_DELAY>16)
#define MAX_DELAY 16
#endif

#define PROG_PLS_WIDTH     8 /* 500ns * PROG_PLS_WIDTH  =   4us */
#define CMPCT_PLS_WIDTH 1000 /* 500ns * CMPCT_PLS_WIDTH = 500us */

#if (MAX_DELAY>12)
#define ERASE_PLS_WIDTH 4000 /* 500ns * ERASE_PLS_WIDTH = 2.0ms */
#else
#define ERASE_PLS_WIDTH 5400 /* 500ns * ERASE_PLS_WIDTH = 2.7ms */
#endif

#define MAX_PROG_PLS    50
#define MAX_CMPCT_PLS 2000
#define MAX_ERASE_PLS 4095


