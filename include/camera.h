#ifndef _LIBRAC1_CAMERA_H_
#define _LIBRAC1_CAMERA_H_

#include <tamtypes.h>
#include "types.h"
#include "math.h"
#include "math3d.h"

#define CAMERA cameraGetCamera()
#define CAMERA_CURRENT_UPDATE_CAM cameraGetCurrentUpdateCam()
#define CAMERA_UPDATE_CAM_POOL cameraGetUpdateCamPool()
#define CAMERA_SPEEDS cameraGetSpeeds()

#define CameraFlag (*cameraGetFlag())

typedef enum {
    CAM_FLAG_NULL = 0,
    CAM_FLAG_NO_WALK = 8,
    CAM_FLAG_NORMAL = 16,
} CameraFlags;

typedef struct CameraPolar { // 0x14
/* 0x00 */ float azimuth;
/* 0x04 */ float elevation;
/* 0x08 */ float radius;
/* 0x0c */ float rotY;
/* 0x10 */ float rotZ;
} CameraPolar;

typedef struct CameraControlActivation { // 0x10
/* 0x00 */ int activationType;
/* 0x04 */ float blendSpeed;
/* 0x08 */ char priority;
/* 0x09 */ char activate;
/* 0x0a */ s16 deactivate;
/* 0x0c */ s16 repCam;
/* 0x0e */ s16 orgCam;
} CameraControlActivation;

typedef struct CameraShake { // 0x10
/* 0x00 */ float strength;
/* 0x04 */ float adjust;
/* 0x08 */ int time;
/* 0x0c */ int div;
} CameraShake;

typedef struct CameraFov { // 0x30
/* 0x00 */ float speed;
/* 0x04 */ float ideal;
/* 0x08 */ float actual;
/* 0x0c */ float gain;
/* 0x10 */ float damp;
/* 0x14 */ float limit;
/* 0x18 */ char changeType;
/* 0x19 */ char state;
/* 0x1a */ s16 timer;
/* 0x1c */ float timerInv;
/* 0x20 */ float init;
/* 0x24 */ float pad[3];
} CameraFov;

typedef struct CameraStatics { // 0xf0
/* 0x00 */ vec3 heroNoJump;
/* 0x0c */ float heroLastZ;
/* 0x10 */ float heroLastZSpeed;
/* 0x14 */ char pad_14[0x0c];
/* 0x20 */ vec4 heroUp;
/* 0x30 */ vec4 heroUpActual;
/* 0x40 */ vec4 heroUpLast;
/* 0x50 */ vec4 heroUpSpeed;
/* 0x60 */ vec4 heroLastPos;
/* 0x70 */ vec4 heroMoveVec;
/* 0x80 */ vec4 heroMoveVec2D;
/* 0x90 */ vec4 heroMoveVecUp;
/* 0xa0 */ float heroSpeed;
/* 0xa4 */ float heroSpeed2D;
/* 0xa8 */ float heroSpeedUp;
/* 0xac */ float heroLastRotZ[5];
/* 0xc0 */ int hotspot;
/* 0xc4 */ void *pCamColl;
/* 0xc8 */ float fadeSpeed;
/* 0xcc */ float fadeIdeal;
/* 0xd0 */ int fadeTimer;
/* 0xd4 */ float flashInSpeed;
/* 0xd8 */ float flashOutSpeed;
/* 0xdc */ float flashIdeal;
/* 0xe0 */ int flashTimer;
/* 0xe4 */ void *boss;
/* 0xe8 */ int bossTimer;
/* 0xec */ int pad_ec;
} CameraStatics;

typedef struct CameraHeroData { // 0x160
/* 0x000 */ mtx4 mtx;
/* 0x040 */ vec4 pos;
/* 0x050 */ vec4f rot;
/* 0x060 */ vec4 cg;
/* 0x070 */ vec4 moveActualFromExternal;
/* 0x080 */ vec4 groundGravity;
/* 0x090 */ vec4 jumpGravity;
/* 0x0a0 */ vec4 sphereCenter;
/* 0x0b0 */ mtx3 fpsCamMtx;
/* 0x0e0 */ vec4 fpsCamPos;
/* 0x0f0 */ void *pMoby;
/* 0x0f4 */ void *vehicleMoby;
/* 0x0f8 */ void *groundMoby;
/* 0x0fc */ int desiredCam;
/* 0x100 */ int state;
/* 0x104 */ int stateType;
/* 0x108 */ int previousState;
/* 0x10c */ float moveSpeed;
/* 0x110 */ float moveSpeed2D;
/* 0x114 */ float groundDist;
/* 0x118 */ float groundWaterHeight;
/* 0x11c */ int groundOnGood;
/* 0x120 */ s16 groundOffAny;
/* 0x122 */ s16 groundOffGood;
/* 0x124 */ s16 groundMagnetic;
/* 0x126 */ s16 lockOnStrafing;
/* 0x128 */ s16 jumpFramesToLand;
/* 0x12a */ char jumpDescend;
/* 0x12b */ char critterMode;
/* 0x12c */ char multiplayer;
/* 0x12d */ char fpsActive;
/* 0x12e */ char hotSpotLava;
/* 0x12f */ char hotSpotDeathSand;
/* 0x130 */ char hotSpotQuickSand;
/* 0x131 */ char hotSpotIceWater;
/* 0x132 */ char hotSpotWater;
/* 0x133 */ char aiFollowingMe;
/* 0x134 */ void *pPad;
/* 0x138 */ void *pSwingTargetMoby;
/* 0x13c */ float swingForwardAng;
/* 0x140 */ float swingIdealRadius;
/* 0x144 */ int timersLedgeCamAdj;
/* 0x148 */ float ledgeWallAngZ;
/* 0x14c */ int EOPtime;
/* 0x150 */ void *pPath;
/* 0x154 */ int pad[3];
} CameraHeroData;

typedef struct CameraWidget { // 0x14
/* 0x00 */ struct UpdateCam *pCam;
/* 0x04 */ void *semaphore;
/* 0x08 */ float closest;
/* 0x0c */ float interp;
/* 0x10 */ void *preFunc;
} CameraWidget;

typedef struct CameraExternal { // 0x10
/* 0x00 */ vec4 move;
} CameraExternal;

typedef struct CameraControl { // known fields through 0x230
/* 0x000 */ char pad_000[0x010];
/* 0x010 */ s16 followMode;
/* 0x012 */ s16 followRandTimer;
/* 0x014 */ s16 followBlendTimer;
/* 0x016 */ s16 followNoiseTimer;
/* 0x018 */ char pad_018[0x0d8];
/* 0x0f0 */ float elevation;
/* 0x0f4 */ float pendingElevation;
/* 0x0f8 */ float elevationRate;
/* 0x0fc */ float elevationPad;
/* 0x100 */ void *targetMoby;
/* 0x104 */ char targetEnabled;
/* 0x105 */ char pad_105;
/* 0x106 */ s16 targetTimer;
/* 0x108 */ char pad_108[0x00e];
/* 0x116 */ char blendEnabled;
/* 0x117 */ char pad_117;
/* 0x118 */ s16 blendTimer;
/* 0x11a */ s16 elevationPending;
/* 0x11c */ float positionSmoothing;
/* 0x120 */ float positionSmoothingAccel;
/* 0x124 */ float targetSmoothing;
/* 0x128 */ float targetSmoothingAccel;
/* 0x12c */ char pad_12c[0x004];
/* 0x130 */ vec4 currentTargetVector;
/* 0x140 */ vec4 desiredTargetVector;
/* 0x150 */ float rollSmoothing;
/* 0x154 */ float yawSmoothing;
/* 0x158 */ float pitchSmoothing;
/* 0x15c */ float followDistance;
/* 0x160 */ float baseFollowDistance;
/* 0x164 */ float pad_164;
/* 0x168 */ float pad_168;
/* 0x16c */ s16 distancePending;
/* 0x16e */ s16 anglePending;
/* 0x170 */ float pendingFollowDistance;
/* 0x174 */ float pad_174;
/* 0x178 */ float followDistanceRate;
/* 0x17c */ float pendingFollowAngleOrOffset;
/* 0x180 */ float pad_180;
/* 0x184 */ float followAngleOrOffsetRate;
/* 0x188 */ float currentFollowDistance;
/* 0x18c */ char pad_18c[0x0a4];
/* 0x230 */ int state;
} CameraControl;

typedef struct UpdateCam { // 0xb0
/* 0x00 */ mtx3 mtx;
/* 0x30 */ vec4 pos;
/* 0x40 */ vec4f rot;
/* 0x50 */ CameraPolar pol;
/* 0x64 */ vec3 lPos;
/* 0x70 */ CameraControl *control;
/* 0x74 */ CameraControlActivation activation;
/* 0x84 */ s16 importCameraIdx;
/* 0x86 */ s16 type;
/* 0x88 */ char subType;
/* 0x89 */ char bumped;
/* 0x8a */ s16 bumpOff;
/* 0x8c */ s16 funcIdx;
/* 0x8e */ s16 active;
/* 0x90 */ float fov;
/* 0x94 */ int gameCamIdx;
/* 0x98 */ float prevExternalMoveZ;
/* 0x9c */ int pad[2];
} UpdateCam_t;

typedef struct CamBlender { // 0xe0
/* 0x00 */ char data[0xe0];
} CamBlender;

typedef struct Camera { // known fields through 0x570
/* 0x000 */ mtx4 rMtx;
/* 0x040 */ mtx4 fMtx;
/* 0x080 */ mtx4 nfMtx;
/* 0x0c0 */ mtx4 hMtx;
/* 0x100 */ mtx4 hsMtx;
/* 0x140 */ VECTOR pos;
/* 0x150 */ VECTOR rot;
/* 0x160 */ char pad_160[0x020];
/* 0x180 */ UpdateCam_t *pCurrentUpdCam;
/* 0x184 */ UpdateCam_t *pLastUpdCam;
/* 0x188 */ char pad_188[0x348];
/* 0x4d0 */ UpdateCam_t updateCamPool[1];
} Camera_t;

// returns the camera memory as a typed pointer.
Camera_t *cameraGetCamera(void);
// returns the current update camera pointer.
UpdateCam_t *cameraGetCurrentUpdateCam(void);
// returns the start of the update camera pool.
UpdateCam_t *cameraGetUpdateCamPool(void);
// returns the camera flag address.
u32 *cameraGetFlag(void);
// returns the camera speed table address.
float *cameraGetSpeeds(void);
// Sets pending follow distance. When setCurrentDistance is nonzero, also writes the current distance field.
void cameraSetFollowDistance(float distance, float rate, int setCurrentDistance);
// Sets a pending follow angle/offset value used by camera follow positioning.
void cameraSetFollowAngleOrOffset(float value, float rate);
// Sets pending elevation/pitch. When relativeToCurrent is nonzero, adds elevation to the current field.
void cameraSetElevation(float elevation, float rate, int relativeToCurrent);
// Writes the camera follow mode field.
void cameraSetFollowMode(s16 mode);
// Sets the smoothing values used by the follow position interpolation.
void cameraSetFollowSmoothing(float positionRate, float positionAccel);
// Enables the camera blend mode flag.
void cameraEnableBlendMode(void);


#endif // _LIBRAC1_CAMERA_H_
