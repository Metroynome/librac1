#ifndef _LIBRAC1_TYPES_H_
#define _LIBRAC1_TYPES_H_

#include <tamtypes.h>

#if (defined(RAC1_PAL_V100) || defined(RAC1_NTSCU_V100) || defined(RAC1_NTSCJ_V100)) && !defined(RAC1_V100)
#define RAC1_V100
#endif

#if (defined(RAC1_PAL_V200) || defined(RAC1_NTSCU_V200) || defined(RAC1_NTSCJ_V200)) && !defined(RAC1_V200)
#define RAC1_V200
#endif

#if (defined(RAC_PAL_V100) || defined(RAC_NTSCU_V100) || defined(RAC_NTSCJ_V100)) && !defined(RAC_V100)
#define RAC_V100
#endif

#if (defined(RAC_PAL_V200) || defined(RAC_NTSCU_V200) || defined(RAC_NTSCJ_V200)) && !defined(RAC_V200)
#define RAC_V200
#endif

#if (defined(RAC1_PAL) || defined(RAC1_NTSCU) || defined(RAC1_NTSCJ)) && !defined(RAC1_V100) && !defined(RAC1_V200)
#define RAC1_V100
#endif

#if defined(RAC1_V100) && !defined(RAC_V100)
#define RAC_V100
#endif

#if defined(RAC1_V200) && !defined(RAC_V200)
#define RAC_V200
#endif

#if defined(RAC1_PAL_V100) && !defined(RAC1_PAL)
#define RAC1_PAL
#endif

#if defined(RAC1_NTSCU_V100) && !defined(RAC1_NTSCU)
#define RAC1_NTSCU
#endif

#if defined(RAC1_NTSCJ_V100) && !defined(RAC1_NTSCJ)
#define RAC1_NTSCJ
#endif

#if defined(RAC1_PAL_V200) && !defined(RAC1_PAL)
#define RAC1_PAL
#endif

#if defined(RAC1_NTSCU_V200) && !defined(RAC1_NTSCU)
#define RAC1_NTSCU
#endif

#if defined(RAC1_NTSCJ_V200) && !defined(RAC1_NTSCJ)
#define RAC1_NTSCJ
#endif

#if defined(RAC1_PAL) && defined(RAC1_V100) && !defined(RAC1_PAL_V100)
#define RAC1_PAL_V100
#endif

#if defined(RAC_PAL) && defined(RAC_V100) && !defined(RAC_PAL_V100)
#define RAC_PAL_V100
#endif

#if defined(RAC1_NTSCU) && defined(RAC1_V100) && !defined(RAC1_NTSCU_V100)
#define RAC1_NTSCU_V100
#endif

#if defined(RAC1_NTSCJ) && defined(RAC1_V100) && !defined(RAC1_NTSCJ_V100)
#define RAC1_NTSCJ_V100
#endif

#if defined(RAC1_PAL) && defined(RAC1_V200) && !defined(RAC1_PAL_V200)
#define RAC1_PAL_V200
#endif

#if defined(RAC_PAL) && defined(RAC_V200) && !defined(RAC_PAL_V200)
#define RAC_PAL_V200
#endif

#if defined(RAC1_NTSCU) && defined(RAC1_V200) && !defined(RAC1_NTSCU_V200)
#define RAC1_NTSCU_V200
#endif

#if defined(RAC1_NTSCJ) && defined(RAC1_V200) && !defined(RAC1_NTSCJ_V200)
#define RAC1_NTSCJ_V200
#endif

#define __LIBRAC1_GETTER__    inline
#define __LIBRAC1_SETTER__    inline
#define __LIBRAC1_INLINE__    inline

#define true 1
#define false 0
typedef _Bool bool;

#endif
