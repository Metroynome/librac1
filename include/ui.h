#ifndef _LIBRAC1_UI_H_
#define _LIBRAC1_UI_H_

#include <tamtypes.h>
#include "types.h"
#include "moby.h"

#ifdef RAC1_NTSCJ
#define UI_GLOBALS_ADDRESS 0x001ba270
#elif RAC1_PAL_V200
#define UI_GLOBALS_ADDRESS 0x001ba470
#elif RAC1_PAL
#define UI_GLOBALS_ADDRESS 0x001ba0f0
#else
#define UI_GLOBALS_ADDRESS 0x001ba170
#endif

// Resource Table Information
#define UI_RESOURCE_FLAG_LARGE_CLASS 1
#define UI_RESOURCE_FLAG_IN_USE      2
#define UI_RESOURCE_FLAG_LOADING     4
#define UI_RESOURCE_POOL_SMALL_SIZE 0x11800
#define UI_RESOURCE_POOL_LARGE_SIZE 0x4f000

#define UI_FLAG_MASK_HAS_EXPLICIT_SOURCE (UI_FLAG_HERO_ANIM_SRC |UI_FLAG_COUNTER_SRC | UI_FLAG_MENU_LOOKUP_SRC |UI_FLAG_DISABLED_OPTION |UI_FLAG_OPTIONS_TAB_SRC)   // 0x11e4
#define UI_FLAG_MASK_LOCKED_CHECK (UI_FLAG_HERO_ANIM_SRC | UI_FLAG_LOCKED_OPTION)


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

typedef struct UiGlobals { // 0x4f0
/* 0x000 */ int activeIndex;
/* 0x004 */ void *activeMenu;
/* 0x008 */ void *changeToMenu;
/* 0x00c */ int exitAction;
/* 0x010 */ void *scratchBufferB;
/* 0x014 */ int transitionTimer;
/* 0x018 */ void *savedLevelHeapPtr;
/* 0x01c */ char pad_01c[0x14];
/* 0x030 */ char savedCameraState[0x40];
/* 0x070 */ char pad_070[0x5b];
/* 0x0cb */ bool resourceLoadActive;
/* 0x0cc */ u32 savedMenuAllocCount;
/* 0x0d0 */ void *previousActiveMenu;
/* 0x0d4 */ char pad_0d4[0x10];
/* 0x0e4 */ int returnPlanetId;
/* 0x0e8 */ float savedCameraDistance;
/* 0x0ec */ char pad_0ec[0x04];
/* 0x0f0 */ void *returnMenu;
/* 0x0f4 */ int returnMenuIndex;
/* 0x0f8 */ char pad_0f8[0x04];
/* 0x0fc */ void *resourcePoolSmallAlt;
/* 0x100 */ void *resourcePoolLargeAlt;
/* 0x104 */ void *scratchBufferA;
/* 0x108 */ void *resourcePoolPrimary;
/* 0x10c */ void *resourcePoolSecondary;
/* 0x110 */ int frameCounter;
/* 0x114 */ char pad_114[0x10];
/* 0x124 */ int suppressExitInput;
/* 0x128 */ char pad_128[0x78];
/* 0x1a0 */ Moby *uiMobys[14];
/* 0x1d8 */ char pad_1d8[0x2f0];
/* 0x4c8 */ UiResourceTable_t resourceTable[5];
} UiGlobals_t;

#define UI_GLOBALS (*(UiGlobals_t*)UI_GLOBALS_ADDRESS)
#define UI_ACTIVE_INDEX UI_GLOBALS.activeIndex
#define UI_ACTIVE_POINTER UI_GLOBALS.activeMenu
#define UI_CHANGE_TO_POINTER UI_GLOBALS.changeToMenu
#define UI_EXIT_ACTION UI_GLOBALS.exitAction
#define UI_TRANSITION_TIMER UI_GLOBALS.transitionTimer
#define UI_SAVED_LEVEL_HEAP_PTR UI_GLOBALS.savedLevelHeapPtr
#define UI_RESOURCE_LOAD_ACTIVE UI_GLOBALS.resourceLoadActive
#define UI_PREVIOUS_ACTIVE_POINTER UI_GLOBALS.previousActiveMenu
#define UI_RETURN_PLANET_ID UI_GLOBALS.returnPlanetId
#define UI_RETURN_MENU_POINTER UI_GLOBALS.returnMenu
#define UI_RETURN_MENU_INDEX UI_GLOBALS.returnMenuIndex
#define UI_RESOURCE_POOL_PRIMARY UI_GLOBALS.resourcePoolPrimary
#define UI_RESOURCE_POOL_SECONDARY UI_GLOBALS.resourcePoolSecondary
#define UI_FRAME_COUNTER UI_GLOBALS.frameCounter
#define UI_SUPPRESS_EXIT_INPUT UI_GLOBALS.suppressExitInput
#define UI_MOBYS UI_GLOBALS.uiMobys
#define UI_RESOURCE_TABLE UI_GLOBALS.resourceTable

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
/* 0x68 */ UiElementButton_t helpDesk;
/* 0x74 */ UiElementButton_t save;
/* 0x80 */ UiElementButton_t load;
/* 0x8c */ UiElementButton_t sound;
/* 0x98 */ UiElementButton_t camera;
/* 0xa4 */ UiElementButton_t subtitles;
/* 0xb0 */ UiElementButton_t quit;
/* 0xbc */ UiElementButton_t empty;
} UiOptionsMenu_Main_t;

typedef struct UiSelectExit { // 0x50
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
} UiSelectExit;

#endif // _LIBRAC1_UI_H_