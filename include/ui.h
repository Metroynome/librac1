#ifndef _LIBRAC1_UI_H_
#define _LIBRAC1_UI_H_

#include <tamtypes.h>
#include "tyes.h"
#include "moby.h"

#define UI_ACTIVE_POINTER (*(u32*)0x001ba174)
#define UI_CHANGE_TO_POINTER (*(u32*)0x001ba178)
#define UI_MOBYS (*(Moby**)0x001ba310)

// Resource TAble Information
#define UI_RESOURCE_TABLE ((UiResourceTable_t*)0x001ba638)
#define UI_RESOURCE_FLAG_LARGE_CLASS 1
#define UI_RESOURCE_FLAG_IN_USE      2
#define UI_RESOURCE_FLAG_LOADING     4
#define UI_RESOURCE_POOL_SMALL_SIZE 0x11800
#define UI_RESOURCE_POOL_LARGE_SIZE 0x4f000

#define UI_FLAG_MASK_HAS_EXPLICIT_SOURCE (FRAME_FLAG_HERO_ANIM_SRC |UI_FLAG_COUNTER_SRC | UI_FLAG_MENU_LOOKUP_SRC |UI_FLAG_DISABLED_OPTION |UI_FLAG_OPTIONS_TAB_SRC)   // 0x11e4
#define UI_FLAG_MASK_LOCKED_CHECK (FRAME_FLAG_HERO_ANIM_SRC | UI_FLAG_LOCKED_OPTION)


typedef enum UiModeFlags {
   UI_FLAG_CENTER_H          = 0x00001,  // center text horizontally (width/2 offset)
   UI_FLAG_CENTER_V          = 0x00002,  // center text vertically (height/2 offset)
   UI_FLAG_HERO_ANIM_SRC     = 0x00004,  // text source: hero animation state (Hero_AnimFramesToStateFrames)
   UI_FLAG_FONT_STYLE_A      = 0x00008,  // use font/box style A (uVar14=3, &DAT_001c3d10)
   UI_FLAG_FONT_STYLE_B      = 0x00010,  // use font/box style B (uVar14=2, &DAT_001c3970)
   UI_FLAG_COUNTER_SRC       = 0x00020,  // text source: clamped global counter (iGpffff8184)
   UI_FLAG_RAW_COUNTER_SRC   = 0x00040,  // text source: raw global counter (DAT_00184894)
   UI_FLAG_MENU_SRC          = 0x00080,  // text source: focused UiFrame's current value
   UI_FLAG_MENU_LOOKUP_SRC   = 0x00100,  // text source: focused UiFrame options-table lookup (stride 0xc)
   UI_FLAG_APPEND_PREFIX     = 0x00200,  // prepend msg_str(0x4ecc)-based prefix text
   UI_FLAG_SCROLLING         = 0x00400,  // box is currently auto-scrolling (state, not just a mode select)
   UI_FLAG_DISABLED_OPTION   = 0x00800,  // check/append "disabled option" message (msg_str(0x4f54))
   UI_FLAG_OPTIONS_TAB_SRC   = 0x01000,  // text source: focused UiFrame tab/PDA table (+0x3c/+0x48, stride 0xa)
   UI_FLAG_SCROLL_RESET      = 0x02000,  // else-branch of scroll-state check; resets scroll accumulator
   UI_FLAG_LOCKED_OPTION     = 0x04000,  // combined with HERO_ANIM_SRC + msgId==0x523e to force centered "locked" text
   UI_FLAG_MENU_SRC_ALT      = 0x08000,  // modifies MENU_SRC handling (sets uVar10 from uGpffff8180)
   UI_FLAG_BOTTOM_ANCHOR     = 0x10000,  // shift box y-position to bottom of screen
} UiModeFlags_e;

typedef struct UiResourceTable {
/* 0x0 */ u32 *resource;
/* 0x4 */ u32 flag;
} UiResourceTable_t;

typedef struct FrameTableEntry { // 0x8
/* 0x0 */ u32 offset;
/* 0x4 */ u32 size;
} FrameTableEntry_t;

struct UiString {
/* 0x0 */ short flags;
/* 0x2 */ u16 id;
};

typedef struct UiElementSelect { // 0x18
/* 0x00 */ struct UiString labelStringId;
/* 0x04 */ int *pModifier;
/* 0x08 */ struct UiString stringId[4];
} UiElementSelect_t;

typedef struct UiElementButton { // 0x18
/* 0x00 */ struct UiString labelStringId;
/* 0x04 */ int *pNextMenu;
/* 0x08 */ int timeSelected;
} UiElementButton_t;

typedef struct UiHeader { // 0x88 (Pause->Options->Camera)
/* 0x00 */ int unk_00;
/* 0x38 */ int *pParent;
/* 0x3c */ int index;
/* 0x40 */ void *pChildren[16];
/* 0x80 */ char pad_80[0x8];
} UiHeader_t;

typedef struct UiTitle { // 0x58
/* 0x00 */ void *pHandleExit;
/* 0x04 */ void *pDraw;
/* 0x08 */ void *pUseResourceTable_False;
/* 0x0c */ void *func_0c;
/* 0x10 */ void *func_10;
/* 0x14 */ Moby *pMoby;
/* 0x18 */ int w;
/* 0x1c */ int h;
/* 0x20 */ int x;
/* 0x24 */ int y;
/* 0x28 */ int unk_28;
/* 0x2c */ int unk_2c;
/* 0x30 */ u32 modeFlags;
/* 0x34 */ int stringId;
/* 0x38 */ int entryStride;
/* 0x3c */ int scrollOffset;
/* 0x40 */ int selectedIndex;
/* 0x44 */ int uptime;
/* 0x48 */ int currentStringId;
/* 0x4c */ u32 currentMsgFlags;
/* 0x50 */ char unk_50[0x8];
} UiTitle_t;

/*
 NOTES:
 Updating UiOptionsMenu_Description->pOptions[i]->labelStringId also updates UiOptionsMenu_Main->button[i].labelStringId
*/

typedef struct UiOptionsMenu_Description { // 0x70
/* 0x00 */ void *pHandleInput;
/* 0x04 */ void *pDraw;
/* 0x08 */ void *func_08;
/* 0x0c */ void *func_0c;
/* 0x10 */ void *func_10;
/* 0x14 */ Moby *pMoby;
/* 0x18 */ int w;
/* 0x1c */ int h;
/* 0x20 */ int x;
/* 0x24 */ int y;
/* 0x28 */ int unk_28;
/* 0x2c */ int unk_2c;
/* 0x30 */ u32 modeFlags;
/* 0x34 */ UiElementSelect_t *pOptions;
/* 0x38 */ int entryStride;
/* 0x3c */ int scrollOffset;
/* 0x40 */ int selectedIndex;
/* 0x44 */ int uptime;
/* 0x48 */ int currentStringId;
/* 0x4c */ u32 currentMsgFlags;
/* 0x50 */ int descriptionStringId[8];
} UiOptionsMenu_Description_t;

typedef struct UiOptionsMenu_Description_2 { // 0x58
/* 0x00 */ void *pHandleInput;
/* 0x04 */ void *pDraw;
/* 0x08 */ void *func_08;
/* 0x0c */ void *func_0c;
/* 0x10 */ void *func_10;
/* 0x14 */ Moby *pMoby;
/* 0x18 */ int w;
/* 0x1c */ int h;
/* 0x20 */ int x;
/* 0x24 */ int y;
/* 0x28 */ int unk_28;
/* 0x2c */ int unk_2c;
/* 0x30 */ u32 modeFlags;
/* 0x34 */ int *pDescriptionStringId;
/* 0x38 */ int entryStride;
/* 0x3c */ int scrollOffset;
/* 0x40 */ int selectedIndex;
/* 0x44 */ int uptime;
/* 0x48 */ int currentStringId;
/* 0x4c */ u32 currentMsgFlags;
/* 0x50 */ int pad_50[2];
} UiOptionsMenu_Description_2_t;

typedef struct UiOptionsMenu_Main { // 0xc8
/* 0x00 */ void *pUpdate;
/* 0x04 */ void *pDraw;
/* 0x08 */ void *pInit;
/* 0x0c */ void *pUninit;
/* 0x10 */ void *func_10;
/* 0x14 */ Moby *pMoby;
/* 0x18 */ int w;
/* 0x1c */ int h;
/* 0x20 */ int x;
/* 0x24 */ int y;
/* 0x28 */ int unk_28;
/* 0x2c */ int unk_2c;
/* 0x30 */ FrameTableEntry_t *frameTable;
/* 0x34 */ u32 modeFlags;
/* 0x38 */ UiElementSelect_t *pOptions;
/* 0x3c */ int uptime;
/* 0x40 */ void *loadHandle;
/* 0x44 */ int state;            // -1 = idle, 0-6 = load pipeline stage
/* 0x48 */ void *bufferA;
/* 0x4c */ void *bufferB;
/* 0x50 */ int committedFrameA;
/* 0x54 */ int committedFrameB;
/* 0x58 */ int forcedFrame;
/* 0x5c */ u32 callCount;
/* 0x60 */ int loadOffsetAdjust;
/* 0x64 */ int pad_64;
/* 0x68 */ UielementButton_t helpDesk;
/* 0x74 */ UielementButton_t save;
/* 0x80 */ UielementButton_t load;
/* 0x8c */ UielementButton_t sound;
/* 0x98 */ UielementButton_t camera;
/* 0xa4 */ UielementButton_t subtitles;
/* 0xb0 */ UielementButton_t quit;
/* 0xbc */ UielementButton_t empty;
} UiOptionsMenu_Main_t;

typedef struct UiOptionsMenu_SelectExit { // 0x50
/* 0x00 */ void *pUpdate;
/* 0x04 */ void *pDraw;
/* 0x08 */ void *pInit;
/* 0x0c */ void *pUninit;
/* 0x10 */ void *func_10;
/* 0x14 */ Moby *pMoby;
/* 0x18 */ int w;
/* 0x1c */ int h;
/* 0x20 */ int x;
/* 0x24 */ int y;
/* 0x28 */ int unk_28;
/* 0x2c */ int unk_2c;
/* 0x30 */ FrameTableEntry_t *frameTable;
/* 0x34 */ u32 modeFlags;
/* 0x38 */ UiElementSelect_t *pOptions;
/* 0x3c */ int uptime;
/* 0x40 */ void *loadHandle;
/* 0x44 */ int state;            // -1 = idle, 0-6 = load pipeline stage
/* 0x48 */ void *bufferA;
/* 0x4c */ void *bufferB;
} UiOptionsMenu_SelectExit;

#endif // _LIBRAC1_UI_H_