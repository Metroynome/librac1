#ifndef _LIBRAC1_CAMERA_H_
#define _LIBRAC1_CAMERA_H_

#include <tamtypes.h>
#include "types.h"
#include "math.h"
#include "math3d.h"

#define CameraFlag (*(u32*)0x16C4E3)

typedef enum {
    CAM_FLAG_NULL = 0,
    CAM_FLAG_NO_WALK = 8,
    CAM_FLAG_NORMAL = 16,
} CameraFlags;

// returns top of camera memory
u32 cameraGetStart(void);
// returns the camera rot address.
u32 cameraGetRot(void);

#endif // _LIBRAC1_CAMERA_H_