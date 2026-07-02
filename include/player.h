#ifndef _LIBRAC1_PLAYER_H_
#define _LIBRAC1_PLAYER_H_

#include <tamtypes.h>
#include "types.h"
#include "math3d.h"
#include "pad.h"
#include "math.h"
#include "moby.h"

#ifdef RAC1_NTSCJ
#define PLAYER_STRUCT ((Player*)0x00013f450)
#define PLAYER_GLOBAL_TWEAKERS ((TwakerTable_t*)0x0015ee60)
#elif RAC1_PAL_V200
#define PLAYER_STRUCT ((Player*)0x00013f450)
#define PLAYER_GLOBAL_TWEAKERS ((TwakerTable_t*)0x0015ee60)
#else
#define PLAYER_STRUCT ((Player*)0x00013f350)
#define PLAYER_GLOBAL_TWEAKERS ((TwakerTable_t*)0x0015ed60)
#endif

typedef enum PlayerState {
	PLAYER_STATE_IDLE = 0,
	PLAYER_STATE_LOOK = 1,
	PLAYER_STATE_WALK = 2,
	PLAYER_STATE_SKID = 3,
	PLAYER_STATE_CROUCH = 4,
	PLAYER_STATE_QUICK_TURN = 5,
	PLAYER_STATE_FALL = 6,
	PLAYER_STATE_JUMP = 7,
	PLAYER_STATE_GLIDE = 8,
	PLAYER_STATE_RUN_JUMP = 9,
	PLAYER_STATE_LONG_JUMP = 10,
	PLAYER_STATE_FLIP_JUMP = 11,
	PLAYER_STATE_JINK_JUMP = 12,
	PLAYER_STATE_ROCKET_JUMP = 13,
	PLAYER_STATE_DOUBLE_JUMP = 14,
	PLAYER_STATE_HELI_JUMP = 15,
	PLAYER_STATE_CHARGE_JUMP = 16,
	PLAYER_STATE_WALL_JUMP = 17,
	PLAYER_STATE_WATER_JUMP = 18,
	PLAYER_STATE_COMBO_ATTACK = 19,
	PLAYER_STATE_JUMP_ATTACK = 20,
	PLAYER_STATE_THROW_ATTACK = 21,
	PLAYER_STATE_GET_HIT = 22,
	PLAYER_STATE_LEDGE_GRAB = 23,
	PLAYER_STATE_LEDGE_IDLE = 24,
	PLAYER_STATE_LEDGE_TRAVERSE_LEFT = 25,
	PLAYER_STATE_LEDGE_TRAVERSE_RIGHT = 26,
	PLAYER_STATE_LEDGE_JUMP = 27,
	PLAYER_STATE_VISIBOMB = 28,
	PLAYER_STATE_TARGETING = 29,
	PLAYER_STATE_GUN_WAITING = 30,
	PLAYER_STATE_WALLOPER_ATTACK = 31,
	PLAYER_STATE_ATTACK_BOUNCE = 32,
	PLAYER_STATE_ROCKET_STOMP = 33,
	PLAYER_STATE_GLOVE_ATTACK = 34,
	PLAYER_STATE_GRAPPLE_SHOOT = 35,
	PLAYER_STATE_GRAPPLE_PULL = 36,
	PLAYER_STATE_GRAPPLE_PULL_VEHICLE = 37,
	PLAYER_STATE_SUCK_CANNON = 38,
	PLAYER_STATE_GRIND = 39,
	PLAYER_STATE_GRIND_JUMP = 40,
	PLAYER_STATE_GRIND_SWITCH_JUMP = 41,
	PLAYER_STATE_GRIND_ATTACK = 42,
	PLAYER_STATE_SWING = 43,
	PLAYER_STATE_SWING_FALL = 44,
	PLAYER_STATE_RECOIL = 45,
	PLAYER_STATE_ICE_WALK = 46,
	PLAYER_STATE_DEVASTATOR = 47,
	PLAYER_STATE_SLIDE = 48,
	PLAYER_STATE_VEHICLE = 49,
	PLAYER_STATE_SWIMUNDER = 50,
	PLAYER_STATE_IDLEUNDER = 51,
	PLAYER_STATE_CHARGEUNDER = 52,
	PLAYER_STATE_SWIMSURF = 53,
	PLAYER_STATE_IDLESURF = 54,
	PLAYER_STATE_BOLT_CRANK = 55,
	PLAYER_STATE_LAVA_JUMP = 56,
	PLAYER_STATE_DEATH = 57,
	PLAYER_STATE_BOARD = 58,
	PLAYER_STATE_MAGNE_WALK = 59,
	PLAYER_STATE_GRIND_HIT = 62,
	PLAYER_STATE_GRIND_JUMP_TURN = 63,
	PLAYER_STATE_VENDOR_BOOTH = 98,
	PLAYER_STATE_NPC = 99,
	PLAYER_STATE_WALK_TO_POS = 100,
	PLAYER_STATE_SKID_TO_POS = 101,
	PLAYER_STATE_IDLE_TO_POS = 102,
	PLAYER_STATE_JUMP_TO_POS = 103,
	PLAYER_STATE_QUICKSAND_SINK = 104,
	PLAYER_STATE_QUICKSAND_JUMP = 105,
	PLAYER_STATE_DROWN = 106,
	PLAYER_STATE_MAGNE_ATTACK = 111,
	PLAYER_STATE_MAGNE_JUMP = 112,
	PLAYER_STATE_CUT_SCENE = 113,
	PLAYER_STATE_WADE = 114,
	PLAYER_STATE_ZIP = 115,
	PLAYER_STATE_GET_HIT_SURF = 116,
	PLAYER_STATE_GET_HIT_UNDER = 117,
	PLAYER_STATE_DEATH_FALL = 118,
	PLAYER_STATE_SLOPESLIDE = 120,
	PLAYER_STATE_JUMP_BOUNCE = 121,
	PLAYER_STATE_DEATHSAND_SINK = 122,
	PLAYER_STATE_LAVA_DEATH = 123,
	PLAYER_STATE_CHARGE = 125,
	PLAYER_STATE_ICEWATER_FREEZE = 126,
	PLAYER_STATE_ELECTRIC_DEATH = 127,
	PLAYER_STATE_ROCKET_HOVER = 128,
	PLAYER_STATE_ELECTRIC_DEATH_UNDER = 129,
	PLAYER_STATE_SKATE = 130,
	PLAYER_STATE_MOON_JUMP = 131,
	PLAYER_STATE_JET = 132,
	PLAYER_STATE_THROW_SHURIKEN = 133,
	PLAYER_STATE_RACEBIKE = 134,
	PLAYER_STATE_SPEEDBOAT = 135,
	PLAYER_STATE_HOVERPLANE = 136,
	PLAYER_STATE_LATCH_GRAB = 137,
	PLAYER_STATE_LATCH_IDLE = 138,
	PLAYER_STATE_LATCH_JUMP = 139,
	PLAYER_STATE_PULLSHOT_ATTACH = 140,
	PLAYER_STATE_PULLSHOT_PULL = 141,
	PLAYER_STATE_GET_FLATTENED = 142,
	PLAYER_STATE_SKYDIVE = 143,
	PLAYER_STATE_WAIT_FOR_RESURRECT = 144,
	PLAYER_STATE_FLAIL_ATTACK = 145,
	PLAYER_STATE_MAGIC_TELEPORT = 146,
	PLAYER_STATE_TELEPORT_IN = 147,
	PLAYER_STATE_DEATH_NO_FALL = 148,
	PLAYER_STATE_TURRET_DRIVER = 152,
	PLAYER_STATE_WAIT_FOR_JOIN = 154,
	PLAYER_STATE_DROPPED = 155,
	PLAYER_STATE_CNT = 156
} PlayerState;

typedef enum PlayerType {
	PLAYER_TYPE_IDLE = 0,
	PLAYER_TYPE_WALK = 1,
	PLAYER_TYPE_FALL = 2,
	PLAYER_TYPE_LEDGE = 3,
	PLAYER_TYPE_JUMP = 4,
	PLAYER_TYPE_GLIDE = 5,
	PLAYER_TYPE_ATTACK = 6,
	PLAYER_TYPE_GET_HIT = 7,
	PLAYER_TYPE_SHOOT = 8,
	PLAYER_TYPE_BUSY = 9,
	PLAYER_TYPE_BOUNCE = 10,
	PLAYER_TYPE_STOMP = 11,
	PLAYER_TYPE_CROUCH = 12,
	PLAYER_TYPE_GRAPPLE = 13,
	PLAYER_TYPE_SWING = 14,
	PLAYER_TYPE_GRIND = 15,
	PLAYER_TYPE_SLIDE = 16,
	PLAYER_TYPE_SWIM = 17,
	PLAYER_TYPE_SURF = 18,
	PLAYER_TYPE_HYDRO = 19,
	PLAYER_TYPE_DEATH = 20,
	PLAYER_TYPE_BOARD = 21,
	PLAYER_TYPE_RACEBOARD = 22,
	PLAYER_TYPE_SPIN = 23,
	PLAYER_TYPE_NPC = 24,
	PLAYER_TYPE_QUICKSAND = 25,
	PLAYER_TYPE_ZIP = 26,
	PLAYER_TYPE_HOLO = 27,
	PLAYER_TYPE_CHARGE = 28,
	PLAYER_TYPE_ROCKET_HOVER = 29,
	PLAYER_TYPE_JET = 30,
	PLAYER_TYPE_RACEBIKE = 31,
	PLAYER_TYPE_SPEEDBOAT = 32,
	PLAYER_TYPE_PULL = 33,
	PLAYER_TYPE_LATCH = 34,
	PLAYER_TYPE_LADDER = 36,
	PLAYER_TYPE_SKYDIVE = 37,
	PLAYER_TYPE_CNT = 38
} PlayerType;

typedef struct TwakerTable {
/* 0x00 */ float clankExhaustParticleSize;
/* 0x04 */ float unk_04;
/* 0x08 */ float transAnimSpeed;
/* 0x0c */ float momentumMultiplyer;
/* 0x10 */ float jumpSpeed;
/* 0x14 */ float wrenchThrowSpeed;
/* 0x18 */ int unk_18;
/* 0x1c */ float unk_00;
} TwakerTable_t;

typedef struct HeroMove {
/* 0x00 */ VECTOR behavior;
/* 0x10 */ VECTOR external;
/* 0x20 */ VECTOR actual;
/* 0x30 */ VECTOR actualFromBehavior;
/* 0x40 */ VECTOR actualFromBehaviorGrav;
/* 0x50 */ VECTOR actualFromBehavior2D;
/* 0x60 */ VECTOR actualFromExternal;
/* 0x70 */ VECTOR taper;
/* 0x80 */ float speed;
/* 0x84 */ float speed2D;
/* 0x88 */ float forwardSpeed;
/* 0x8c */ float ascent;
/* 0x90 */ float zSpeed;
/* 0x94 */ float externalSpeed;
/* 0x98 */ int pad[2];
} HeroMove;

typedef struct HeroTurn {
/* 0x00 */ float ideal;
/* 0x04 */ float speed;
/* 0x08 */ float accel;
/* 0x0c */ float diff;
} HeroTurn;

typedef struct HeroMotionControl {
/* 0x00 */ float targetSpeed;
/* 0x04 */ float currentSpeed;
/* 0x08 */ int stateFrame;
/* 0x0c */ int unk_0c;
/* 0x10 */ int transTimerA;
/* 0x14 */ int transTimerB;
/* 0x18 */ int unk_18;
/* 0x1c */ int unk_1c;
/* 0x20 */ int unk_20;
/* 0x24 */ int unk_24;
/* 0x28 */ int unk_28;
/* 0x2c */ int unk_2c;
/* 0x30 */ int unk_30;
/* 0x34 */ int unk_34;
} HeroMotionControl;

typedef struct HeroColl {
/* 0x00 */ VECTOR normal;
/* 0x10 */ VECTOR ip;
/* 0x20 */ float top;
/* 0x24 */ float bot;
/* 0x28 */ float idealTop;
/* 0x2c */ float idealBot;
/* 0x30 */ float idealRadius;
/* 0x34 */ float radius;
/* 0x38 */ float radiusSpeed;
/* 0x3c */ Moby *pContactMoby;
/* 0x40 */ Moby *pBumpMoby;
/* 0x44 */ float bumpPushSpeed;
/* 0x48 */ float distToWall;
/* 0x4c */ float wallAng;
/* 0x50 */ float wallSlope;
/* 0x54 */ char wallIsCrate;
/* 0x55 */ char wallIsMoby;
/* 0x56 */ char contact;
/* 0x57 */ char cpad;
/* 0x58 */ float ledgeHeight;
/* 0x5c */ float ledgeDist;
/* 0x60 */ int atLedge;
/* 0x64 */ Moby *pWallJumpMoby;
/* 0x68 */ int pad[2];
/* 0x70 */ float radiusSqd;
/* 0x74 */ char unk_74[0x0c];
} HeroColl;

typedef struct HeroGround {
/* 0x00 */ VECTOR normal;
/* 0x10 */ VECTOR waterNormal;
/* 0x20 */ VECTOR gravity;
/* 0x30 */ VECTOR point;
/* 0x40 */ VECTOR lastGoodPos;
/* 0x50 */ VECTOR externalBootGrav;
/* 0x60 */ float feetHeights[2];
/* 0x68 */ float pitchSlopes[2];
/* 0x70 */ float rollSlopes[2];
/* 0x78 */ float height;
/* 0x7c */ float dist;
/* 0x80 */ float slope;
/* 0x84 */ float pitchSlope;
/* 0x88 */ float rollSlope;
/* 0x8c */ float angz;
/* 0x90 */ float waterHeight;
/* 0x94 */ float quicksandHeight;
/* 0x98 */ int underWater;
/* 0x9c */ Moby *pMoby;
/* 0xa0 */ int onGood;
/* 0xa4 */ float speed;
/* 0xa8 */ short magnetic;
/* 0xaa */ short stickLanding;
/* 0xac */ short offAny;
/* 0xae */ short offGood;
/* 0xb0 */ int oscillating;
/* 0xb4 */ float oscPos1;
/* 0xb8 */ float oscPos2;
/* 0xbc */ int pad[1];
} HeroGround;

/* start:
0013f350
*/
typedef struct Player { // 0x2310
/* 0x0000 */ MATRIX mtx;
/* 0x0040 */ MATRIX invMtx;
/* 0x0080 */ VECTOR pos;
/* 0x0090 */ VECTOR rot;
/* 0x00a0 */ char unk_00a0[0x40];
/* 0x00e0 */ HeroMove move;
/* 0x0180 */ HeroTurn turn;
/* 0x0190 */ HeroMotionControl motion;
/* 0x01c8 */ char unk_01c8[0x8f8];
/* 0x0ac0 */ MATRIX Gadgets[9];
/* 0x0d00 */ char unk_0d00[0x390];
/* 0x1090 */ Moby *pWeaponMoby;
/* 0x1094 */ char unk_1094[0x10];
/* 0x10a4 */ int weaponOClass;
/* 0x10a8 */ char unk_10a8[0x8];
/* 0x10b0 */ int weaponHeldTime;
/* 0x10b4 */ int unk_10b4;
/* 0x10b8 */ int weaponHeldId;
/* 0x10bc */ char unk_10bc[0xc64];
/* 0x1d20 */ VECTOR sitckInput;
/* 0x1d30 */ char unk_1d30[0x350];
/* 0x2080 */ Moby *pMoby;
/* 0x2084 */ int state;
/* 0x2088 */ int subState;
/* 0x208c */ int stateType;
/* 0x2090 */ int previousState;
/* 0x2094 */ int previousType;
/* 0x2098 */ int stateTimer;
/* 0x209c */ int previousStateTimer;
/* 0x20a0 */ char unk_20a0;
/* 0x20a1 */ char unk_20a1;
/* 0x20a2 */ char unk_20a2;
/* 0x20a3 */ char unk_20a3;
/* 0x20a4 */ char unk_20a4;
/* 0x20a5 */ char invisible;
/* 0x20a6 */ char wrenchOnly;
/* 0x20a7 */ char forceWrench;
/* 0x20a8 */ char firing;
/* 0x20a9 */ char unk_20a9;
/* 0x20aa */ char unk_20aa;
/* 0x20ab */ char unk_20ab;
/* 0x20ac */ char unk_20ac;
/* 0x20ad */ char unk_20ad;
/* 0x20ae */ char unk_20ae;
/* 0x20af */ char hideWeapon;
/* 0x20b0 */ char unk_20b0;
/* 0x20b1 */ char cutsceneControlLock;
/* 0x20b2 */ char unk_20b2;
/* 0x20b3 */ char forceCamTurnOff;
/* 0x20b4 */ char unk_20b4[0x194];
/* 0x2248 */ Moby *unk_2248;
/* 0x224c */ char unk_224c[0x50];
/* 0x229c */ float inputMagnitude;
/* 0x22a0 */ char unk_22a0[0x8];
/* 0x22a8 */ int gameplayReady;
/* 0x22ac */ char unk_22ac[0x28];
/* 0x22d4 */ short timer_22d4;
/* 0x22d6 */ short timer_22d6;
/* 0x22d8 */ char unk_22d8[0x38];
} Player;
typedef Player Hero;

int playerCanControl(void);

#endif
