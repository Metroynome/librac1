#ifndef _LIBRAC1_GAME_H_
#define _LIBRAC1_GAME_H_


#include <tamtypes.h>
#include "types.h"

#ifdef RAC1_NTSCJ
#define Level (*(volatile int*)0x0015ee84)
#define worldupdateTime (*(volatile int*)0x0015f4f8)
#define gameMode (*(volatile int*)0x0015f6c4)
#define gameModeTimer (*(volatile int*)0x0015f6c8)
#define levelLoadedTimer (*(volatile int*)0x0015f6cc)
#define levelLoopExitFlag (*(volatile int*)0x0015f670)
#define movieLoadRequest (*(volatile int*)0x0015f730)
#define asyncLoadActive (*(volatile int*)0x00151804)
#define asyncLoadIndex (*(volatile short*)0x00151808)
#define asyncLoadFlags (*(volatile short*)0x0015180a)
#define asyncLoadMode (*(volatile short*)0x0015180c)
#define asyncLoadReady (*(volatile short*)0x0015180e)
#define asyncLoadDelay (*(volatile int*)0x00151818)
#define asyncLoadTimeout (*(volatile int*)0x0015181c)
#define gameMode_startMenu (*(volatile innt*)0x0015f704)
#else
// NTSCU and PAL are the same
// Addresses are different if on start menu versus in game.
// LEvel stays the same.
#define Level (*(volatile int*)0x0015ed84)
#define worldupdateTime (*(volatile int*)0x0015f3f8)
#define gameMode (*(volatile int*)0x0015f5c4)
#define gameModeTimer (*(volatile int*)0x0015f5c8)
#define levelLoadedTimer (*(volatile int*)0x0015f5cc)
#define levelLoopExitFlag (*(volatile int*)0x0015f570)
#define movieLoadRequest (*(volatile int*)0x0015f630)
#define asyncLoadActive (*(volatile int*)0x00151704)
#define asyncLoadIndex (*(volatile short*)0x00151708)
#define asyncLoadFlags (*(volatile short*)0x0015170a)
#define asyncLoadMode (*(volatile short*)0x0015170c)
#define asyncLoadReady (*(volatile short*)0x0015170e)
#define asyncLoadDelay (*(volatile int*)0x00151718)
#define asyncLoadTimeout (*(volatile int*)0x0015171c)
#define gameMode_startMenu (*(volatile innt*)0x0015f604)
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
