#ifndef _LIBRAC1_UI_H_
#define _LIBRAC1_UI_H_

#include <tamtypes.h>
#include "tyes.h"
#include "moby.h"

#define UI_ACTIVE_POINTER (*(u32*)0x001ba174)
#define UI_MOBYS (*(Moby**)0x001ba310)

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

#define UI_FLAG_MASK_HAS_EXPLICIT_SOURCE (FRAME_FLAG_HERO_ANIM_SRC |UI_FLAG_COUNTER_SRC |UI_FLAG_MENU_LOOKUP_SRC |UI_FLAG_DISABLED_OPTION |UI_FLAG_OPTIONS_TAB_SRC)   // 0x11e4
#define UI_FLAG_MASK_LOCKED_CHECK (FRAME_FLAG_HERO_ANIM_SRC |UI_FLAG_LOCKED_OPTION)

typedef struct UiMenu { // unkown size
/* 0x00 */ int unk_00;
} UiMenu_t;

typedef struct UiElementText  { // 0x58
/* 0x00 */ void *func_00;
/* 0x04 */ void *func_04;
/* 0x08 */ void *func_08;
/* 0x0c */ void *func_0c;
/* 0x10 */ void *func_10;
/* 0x14 */ void *func_14;
/* 0x18 */ int unk_18;
/* 0x1c */ int unk_1c;
/* 0x20 */ int x;
/* 0x24 */ int y;
/* 0x28 */ int unk_28;
/* 0x2c */ int unk_2c;
/* 0x30 */ u32 modeFlags;
/* 0x34 */ int stringId;
/* 0x38 */ int entryStride;
/* 0x3c */ int scrollOffset;
/* 0x44 */ int fadeCounter;
/* 0x48 */ int currentStringId;
/* 0x4c */ u32 currentMsgFlags;
/* 0x50 */ char unk_50[0x8];
} UiElementText_t;

typedef struct UiOptions { // 0x18
/* 0x00 */ int labelStringId;
/* 0x04 */ void *pUpdate;
/* 0x08 */ int valueStringId[4];
} UiOptions_t;

typedef struct UiElementMultiText {
/* 0x00 */ void *pHandleInput;
/* 0x04 */ void *pLayoutUpdate;
/* 0x08 */ char unk_08[0x8];
/* 0x10 */ u32 flags;
/* 0x14 */ char unk_14[0x4];
/* 0x18 */ int width;
/* 0x1c */ int height;
/* 0x20 */ int scissor_x;
/* 0x24 */ int scissor_y;
/* 0x28 */ char unk_28[0xc];
/* 0x34 */ UiOptions_t *pOptions;
/* 0x38 */ int selectedIndex;
} UiElementMultiText_t;

#endif // _LIBRAC1_UI_H_