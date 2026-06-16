/***************************************************
 * FILENAME :		stdio.h
 * DESCRIPTION :
 * 		Contains useful functions for debugging.
 * AUTHOR :			
 */

#ifndef _LIBRAC1_STDIO_H_
#define _LIBRAC1_STDIO_H_

#include "types.h"


//--------------------------------------------------------
__LIBRAC1_INLINE__ int printf(const char * format, ...);

//--------------------------------------------------------
#ifdef DEBUG
    #define DPRINTF(fmt, ...)       \
        printf("%s"fmt, "", ##__VA_ARGS__);
#else
    #define DPRINTF(fmt, ...) 
#endif


#endif // _LIBRAC1_STDIO_H_
