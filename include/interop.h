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
	u32 MainMenu; // Level: -1
	u32 Veldin1; // Level: 0
	u32 Novalis; // Level: 1
	u32 Aridia; // Level: 2
	u32 Kerwan; // Level: 3
	u32 Eudora; // Level: 4
	u32 Rilgar; // Level: 5
	u32 NebulaG34; // Level: 6
	u32 Umbris; // Level: 7
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

/* Compact tables tag MainMenu and retain Veldin1 as the absolute base.
 * Offset zero is unavailable; 0x8000 denotes the same address as the base. */
#define RAC1_VA_COMPACT_MENU(address) ((u32)(address) | (u32)0x80000000)
#define RAC1_VA_COMPACT_OFFSET(base, address) ((address) == 0 ? 0 : \
	(u16)(((s32)(address) - (s32)(base)) / 4 + 0x8000 + \
	0 * sizeof(char[((address) == 0 || (((s32)(address) - (s32)(base)) % 4 == 0 && \
	((s32)(address) - (s32)(base)) / 4 >= -32767 && \
	((s32)(address) - (s32)(base)) / 4 <= 32767)) ? 1 : -1])))

typedef struct rac1VariableAddressCompact {
	/* 0x00 */ u32 MainMenu;
	/* 0x04 */ u32 Veldin1;
	/* 0x08 */ u16 Novalis;
	/* 0x0a */ u16 Aridia;
	/* 0x0c */ u16 Kerwan;
	/* 0x0e */ u16 Eudora;
	/* 0x10 */ u16 Rilgar;
	/* 0x12 */ u16 NebulaG34;
	/* 0x14 */ u16 Umbris;
	/* 0x16 */ u16 Batalia;
	/* 0x18 */ u16 Gaspar;
	/* 0x1a */ u16 Orxon;
	/* 0x1c */ u16 Pokitaru;
	/* 0x1e */ u16 Hoven;
	/* 0x20 */ u16 OltanisOrbit;
	/* 0x22 */ u16 Oltanis;
	/* 0x24 */ u16 Quartu;
	/* 0x26 */ u16 Kalebo;
	/* 0x28 */ u16 VeldinOrbit;
	/* 0x2a */ u16 Veldin2;
} rac1VariableAddressCompact_t;

u32 GetAddress(const void* address);
u32 GetAddressImmediate(const void* address);

#endif // _LIBRAC1_INTEROP_H_
