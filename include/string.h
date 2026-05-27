#ifndef _LIBRAC1_STRING_H_
#define _LIBRAC1_STRING_H_

#include "types.h"

//--------------------------------------------------------
__LIBRAC1_INLINE__ void * memset(void * ptr, int value, int num);
__LIBRAC1_INLINE__ void * memcpy(void * destination, const void * source, int num);
__LIBRAC1_INLINE__ char * strncpy(char *dest, const char *src, int n);
__LIBRAC1_INLINE__ int strcmp(char *str1, char *str2);
__LIBRAC1_INLINE__ int strncmp(char * str1, char * str2, int n);
__LIBRAC1_INLINE__ int strlen(const char *str);

#endif // _LIBRAC1_STRING_H_
