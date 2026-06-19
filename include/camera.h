#ifndef _LIBRAC1_CAMERA_H_
#define _LIBRAC1_CAMERA_H_

#include <tamtypes.h>
#include "types.h"

// only tested on Novalis
#define CameraFlag (*(u32*)0x16C4E3)

typedef enum {
    CAM_FLAG_NULL = 0,
    CAM_FLAG_NO_WALK = 8,
    CAM_FLAG_NORMA = 16,
} CameraFlags;

#endif // _LIBRAC1_CAMERA_H_