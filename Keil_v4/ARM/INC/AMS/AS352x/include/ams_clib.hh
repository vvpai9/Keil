/*
 *****************************************************************************
 * Copyright @ 2007 by austriamicrosystems AG                                *
 * All rights are reserved.                                                  *
 *                                                                           *
 * Reproduction in whole or in part is prohibited without the written consent*
 * of the copyright owner. Austriamicrosystems reserves the right to make    *
 * changes without notice at any time. The software is provided as is and    *
 * Austriamicrosystems makes no warranty, expressed, implied or statutory,   *
 * including but not limited to any implied warranty of merchantability or   *
 * fitness for any particular purpose, or that the use will not infringe any *
 * third party patent, copyright or trademark. Austriamicrosystems should    *
 * not be liable for any loss or damage arising from its use.                *
 *****************************************************************************
 */

/*
 *      PROJECT:   AS353x
 *      $Revision: $
 *      LANGUAGE:  ANSI C
*/

/*! \file
 *
 *  \author U. Herrmann
 *  \author M. Arpa (Substitute)
 *
 *  \brief Extern declarations of some standard clib functions. 
 *  
 *  Extern declarations of some standard clib functions. 
 *  Currently the FS implementaition is used since the 
 *  compilers clib needs additional startup.
 *
 */


#ifndef _AMS_CLIB_HH_
#define _AMS_CLIB_HH_

/*
******************************************************************************
* INCLUDES
******************************************************************************
*/

/*
******************************************************************************
* DEFINES
******************************************************************************
*/
/* extern declarations, to be hidden from user, not to be used directly */

int            FS__CLIB_atoi    (const char *s);
int            FS__CLIB_memcmp  (const void *s1, const void *s2, unsigned n);
void *         FS__CLIB_memcpy  (      void *s1, const void *s2, unsigned long n);
void *         FS__CLIB_memset  (void *s, int c, unsigned long n);
int            FS__CLIB_strcmp  (const char *s1, const char *s2);
char *         FS__CLIB_strcpy  (char *s1, const char *s2);
unsigned       FS__CLIB_strlen  (const char *s);
int            FS__CLIB_strncmp (const char *s1, const char *s2, int n);
char *         FS__CLIB_strncpy (char *s1, const char *s2, unsigned long n);
int            FS__CLIB_toupper (int c);

#endif /* _AMS_CLIB_HH_ */


