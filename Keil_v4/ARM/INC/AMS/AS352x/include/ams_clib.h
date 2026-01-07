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
 *      $Revision: 759 $
 *      LANGUAGE:  ANSI C
*/

/*! \file
 *
 *  \author U. Herrmann
 *  \author M. Arpa (Substitute)
 *
 *  \brief Definition of standard clib functions.
 *  
 *  Definition of standard clib functions. Currently the FS 
 *  implementation is used for ctype.h API since the compilers 
 *  clib needs additional startup.
 *
 */


#ifndef _AMS_CLIB_H_
#define _AMS_CLIB_H_

/*
******************************************************************************
* INCLUDES
******************************************************************************
*/

/* include string.h here so we can undef and overwrite the forbidden functions
 */
#include <string.h>
#include <stdlib.h>

/*
******************************************************************************
* DEFINES
******************************************************************************
*/

#define AMS_ATOI(s)             FS__CLIB_atoi(s)
#define AMS_TOUPPER(c)          FS__CLIB_toupper(c)

#define AMS_MEMCHR(A,B,C)   memchr(A,B,C)   
#define AMS_MEMCMP(A,B,C)   memcmp(A,B,C)   
#define AMS_MEMCPY(A,B,C)   memcpy(A,B,C)   
#define AMS_MEMMOVE(A,B,C)  memmove(A,B,C)  
#define AMS_MEMSET(A,B,C)   memset(A,B,C)   
#define AMS_STRCAT(A,B)     strcat(A,B)     
#define AMS_STRCHR(A,B)     strchr(A,B)     
#define AMS_STRCMP(A,B)     strcmp(A,B)     
#define AMS_STRCOLL(A,B)    strcoll(A,B)    
#define AMS_STRCPY(A,B)     strcpy(A,B)     
#define AMS_STRCSPN(A,B)    strcspn(A,B)    
#define AMS_STRERROR(A)     strerror(A)     
#define AMS_STRLEN(A)       strlen(A)       
#define AMS_STRNCAT(A,B,C)  strncat(A,B,C)  
#define AMS_STRNCMP(A,B,C)  strncmp(A,B,C)  
#define AMS_STRNCPY(A,B,C)  strncpy(A,B,C)  
#define AMS_STRPBRK(A,B)    strpbrk(A,B)    
#define AMS_STRRCHR(A,B)    strrchr(A,B)    
#define AMS_STRSPN(A,B)     strspn(A,B)     
#define AMS_STRSTR(A,B)     strstr(A,B)     
#define AMS_STRTOK(A,B)     strtok(A,B)     
#define AMS_STRXFRM(A,B,C)  strxfrm(A,B,C)  
#define AMS_STRTOL(A,B,C)   strtol(A,B,C)

/* forbid to use direct ctype.h functions since they are not guaranteed to work 
   without setting up a proper locale. E.g. islower, toupper, etc. are not working
*/

#undef isalnum
#undef isalpha 
#undef iscntrl 
#undef isdigit 
#undef isgraph 
#undef islower 
#undef isprint 
#undef ispunct 
#undef isspace 
#undef isupper 
#undef isxdigit
#undef tolower 
#undef toupper 
/* from ctype.h */
#define isalnum(c)  AMS_FORBIDDEN_TO_USE(c)
#define isalpha(c)  AMS_FORBIDDEN_TO_USE(c)
#define iscntrl(c)  AMS_FORBIDDEN_TO_USE(c)
#define isdigit(c)  AMS_FORBIDDEN_TO_USE(c)
#define isgraph(c)  AMS_FORBIDDEN_TO_USE(c)
#define islower(c)  AMS_FORBIDDEN_TO_USE(c)
#define isprint(c)  AMS_FORBIDDEN_TO_USE(c)
#define ispunct(c)  AMS_FORBIDDEN_TO_USE(c)
#define isspace(c)  AMS_FORBIDDEN_TO_USE(c)
#define isupper(c)  AMS_FORBIDDEN_TO_USE(c)
#define isxdigit(c) AMS_FORBIDDEN_TO_USE(c)
#define tolower(c)  AMS_FORBIDDEN_TO_USE(c)
#define toupper(c)  AMS_FORBIDDEN_TO_USE(c)

/* from string.h */
/* These functions do not work without locale */

#undef strcoll
#undef strxfrm
#undef strtol
#define strcoll(a,b)    AMS_FORBIDDEN_TO_USE(a,b) 
#define strxfrm(a,b,c)  AMS_FORBIDDEN_TO_USE(a,b,c)
#define strtol(a,b,c)   AMS_FORBIDDEN_TO_USE(a,b,c) 

#include "ams_clib.hh"

#endif /* _AMS_CLIB_ */



