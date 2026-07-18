/***************************************************
 * FILENAME :		level.h
 * DESCRIPTION :
 * 		Contains level ids and helpers for RAC1.
 * NOTES :
 * AUTHOR :
 */

#ifndef _LIBRAC1_LEVEL_H_
#define _LIBRAC1_LEVEL_H_

#include <tamtypes.h>

enum LEVEL_IDS {
    LEVEL_ID_MAIN_MENU      = -1,
    LEVEL_ID_VELDIN1        = 0,
    LEVEL_ID_NOVALIS        = 1,
    LEVEL_ID_ARIDIA         = 2,
    LEVEL_ID_KERWAN         = 3,
    LEVEL_ID_EUDORA         = 4,
    LEVEL_ID_RILGAR         = 5,
    LEVEL_ID_NEBULA_G34     = 6,
    LEVEL_ID_UMBRIS         = 7,
    LEVEL_ID_BATALIA        = 8,
    LEVEL_ID_GASPAR         = 9,
    LEVEL_ID_ORXON          = 10,
    LEVEL_ID_POKITARU       = 11,
    LEVEL_ID_HOVEN          = 12,
    LEVEL_ID_OLTANIS_ORBIT  = 13,
    LEVEL_ID_OLTANIS        = 14,
    LEVEL_ID_QUARTU         = 15,
    LEVEL_ID_KALEBO         = 16,
    LEVEL_ID_VELDIN_ORBIT   = 17,
    LEVEL_ID_VELDIN2        = 18,
};

enum LEVEL_MASK_IDS {
    LEVEL_MASK_NONE             = 0,
    LEVEL_MASK_MAIN_MENU        = (1 << 0),
    LEVEL_MASK_VELDIN1          = (1 << 1),
    LEVEL_MASK_NOVALIS          = (1 << 2),
    LEVEL_MASK_ARIDIA           = (1 << 3),
    LEVEL_MASK_KERWAN           = (1 << 4),
    LEVEL_MASK_EUDORA           = (1 << 5),
    LEVEL_MASK_RILGAR           = (1 << 6),
    LEVEL_MASK_NEBULA_G34       = (1 << 7),
    LEVEL_MASK_UMBRIS           = (1 << 8),
    LEVEL_MASK_BATALIA          = (1 << 9),
    LEVEL_MASK_GASPAR           = (1 << 10),
    LEVEL_MASK_ORXON            = (1 << 11),
    LEVEL_MASK_POKITARU         = (1 << 12),
    LEVEL_MASK_HOVEN            = (1 << 13),
    LEVEL_MASK_OLTANIS_ORBIT    = (1 << 14),
    LEVEL_MASK_OLTANIS          = (1 << 15),
    LEVEL_MASK_QUARTU           = (1 << 16),
    LEVEL_MASK_KALEBO           = (1 << 17),
    LEVEL_MASK_VELDIN_ORBIT     = (1 << 18),
    LEVEL_MASK_VELDIN2          = (1 << 19),
    LEVEL_MASK_ALL              = -1,
};

int levelMaskHasMask(int value, int maskValue);
int levelIdToMask(int levelId);
int levelMaskToId(int levelMask);
char * levelGetName(enum LEVEL_IDS levelId);

#endif // _LIBRAC1_LEVEL_H_
