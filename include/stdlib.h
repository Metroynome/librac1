/***************************************************
 * FILENAME :    stdlib.h
 * 
 * DESCRIPTION :
 * 
 * AUTHOR :
 */

#ifndef _LIBRAC1_STDLIB_H_
#define _LIBRAC1_STDLIB_H_

#include "types.h"


//--------------------------------------------------------
__LIBRAC1_INLINE__ void* malloc( unsigned long size );
__LIBRAC1_INLINE__ void free( void* ptr );

#endif // _LIBRAC1_STDLIB_H_