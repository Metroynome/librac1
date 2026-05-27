/***************************************************
 * FILENAME :		interop.h
 * DESCRIPTION :
 * 		Provides tools to define and reference/invoke addresses in memory by map.
 * NOTES :
 * AUTHOR :			
 */

#ifndef _LIBRAC1_INTEROP_H_
#define _LIBRAC1_INTEROP_H_

#include <tamtypes.h>

/*
Possible GAME_MAP_ID:
0013A4E0
0013D320
0014EEE0
0015ED84 <-- Most likely this one.
*/

typedef struct VariableAddress {
	u32 Veldin1; // Level: 0
	u32 Novalis; // Level: 1
	u32 Aridia; // Level: 2
	u32 Kerwan; // Level: 3
	u32 Eudora; // Level: 4
	u32 Rilgar; // Level: 5
	u32 NebulaG34; // Level: 6
	u32 Unbris; // Level: 7
	u32 Batalia; // Level: 8
	u32 Gaspar; // Level: 9
	u32 Orxon; // Level: 10
	u32 Pokitaru; // Level: 11
	u32 Hoven; // Level: 12
	u32 OltanisOrbit; // Level: 13
	u32 Oltanis; // Level: 14
	u32 Quartu; // Level: 15
	u32 Kalebo; // Level: 16
	u32 VeldinOrbit; // Level: 17
	u32 Veldin2; // Level: 18
} VariableAddress_t;

u32 GetAddress(VariableAddress_t* address);
u32 GetAddressImmediate(VariableAddress_t* address);

#endif // _LIBRAC1_INTEROP_H_
