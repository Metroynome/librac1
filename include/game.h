#ifndef _LIBRAC1_GAME_H_
#define _LIBRAC1_GAME_H_


#include <tamtypes.h>
#include "types.h"

#ifdef RAC1_NTSCJ
#define gameMode (*(volatile int*)0x0015f6a8)
#define Level (*(volatile int*)0x0015ee84)
#else
// NTSCU and PAL are the same
#define gameMode (*(volatile int*)0x0015f5c4)
#define Level (*(volatile int*)0x0015ed84)
#endif

typedef enum {
	GAME_MODE_NONE = -2,
	GAME_MODE_DEBUG = -1,
	GAME_MODE_NORMAL = 0,
	GAME_MODE_MOVIE = 1,
	GAME_MODE_SCENE = 2,
	GAME_MODE_PAUSE = 3,
	GAME_MODE_FREEZE = 4,
	GAME_MODE_VENDOR = 5,
	GAME_MODE_SPACE = 6,
	GAME_MODE_PUZZLE = 7,
	GAME_MODE_WEAPON_UPGRADE = 8,
	GAME_MODE_CREDITS = 9,
	GAME_MODE_LOBBY = 10,
	GAME_MODE_FLYBY = 11,
	GAME_MODE_THERMAL = 12,
	GAME_MODE_PRE_LOBBY_MEMCARD_LOAD = 13,
	GAME_MODE_PRE_LOBBY = 14,
	GAME_MODE_WAIT_FOR_MPSTART = 15,
	GAME_MODE_EXEC_MP_MEMCARD_COMMAND = 16,
	GAME_MODE_IOP_DEBUG = 17,
	GAME_MODE_MAX = 18
} gameMode_t;

#endif // _LIBRAC1_GAME_H_
