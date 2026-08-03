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
#define UI_MENU_MAX_ELEMENTS 14
#define UI_CUSTOM_MENU_MAX_OPTIONS UI_MENU_MAX_ELEMENTS

#define UI_FLAG_MASK_HAS_EXPLICIT_SOURCE (UI_FLAG_HERO_ANIM_SRC | UI_FLAG_COUNTER_SRC | UI_FLAG_MENU_LOOKUP_SRC | UI_FLAG_DISABLED_OPTION | UI_FLAG_OPTIONS_TAB_SRC)   // 0x11e4
#define UI_FLAG_MASK_LOCKED_CHECK (UI_FLAG_HERO_ANIM_SRC | UI_FLAG_LOCKED_OPTION)

#define UI_GLOBALS (*(UiGlobals_t*)UI_GLOBALS_ADDRESS)
#define UI_ACTIVE_INDEX UI_GLOBALS.activeIndex
#define UI_ACTIVE_POINTER UI_GLOBALS.pActiveMenu
#define UI_CHANGE_TO_POINTER UI_GLOBALS.pChangeToMenu
#define UI_EXIT_ACTION UI_GLOBALS.exitAction
#define UI_TRANSITION_TIMER UI_GLOBALS.transitionTimer
#define UI_SAVED_LEVEL_HEAP_PTR UI_GLOBALS.pSavedLevelHeapPtr
#define UI_RESOURCE_LOAD_ACTIVE UI_GLOBALS.resourceLoadActive
#define UI_PREVIOUS_ACTIVE_POINTER UI_GLOBALS.pPreviousActiveMenu
#define UI_RETURN_PLANET_ID UI_GLOBALS.returnPlanetId
#define UI_RETURN_MENU_POINTER UI_GLOBALS.pReturnMenu
#define UI_RETURN_MENU_INDEX UI_GLOBALS.returnMenuIndex
#define UI_RESOURCE_POOL_PRIMARY UI_GLOBALS.pResourcePoolPrimary
#define UI_RESOURCE_POOL_SECONDARY UI_GLOBALS.pResourcePoolSecondary
#define UI_FRAME_COUNTER UI_GLOBALS.frameCounter
#define UI_SUPPRESS_EXIT_INPUT UI_GLOBALS.suppressExitInput
#define UI_MOBYS UI_GLOBALS.uiMobys
#define UI_RESOURCE_TABLE UI_GLOBALS.resourceTable

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

typedef enum UIMenuIds {
   UI_MENU_PAUSE_MAIN        = 2,
   UI_MENU_WEAPONS           = 3,
   UI_MENU_GADGETS           = 4,
   UI_MENU_QUICK_SELECT      = 5,
   UI_MENU_ITEMS             = 6,
   UI_MENU_HELP              = 7,
   UI_MENU_OPTIONS           = 8,
   UI_MENU_GOODIES           = 9,
   UI_MENU_PLANET_SELECT     = 11,
   UI_MENU_QUIT_GAME         = 13,
   UI_MENU_HELPDESK          = 19,
   UI_MENU_HELP_LOG          = 21,
   UI_MENU_CONTROLS          = 22,
   UI_MENU_MOVES             = 23,
   UI_MENU_HELP_WEAPONS      = 24,
   UI_MENU_HELP_GADGETS      = 25,
   UI_MENU_SUBTITLES         = 27,
   UI_MENU_SUBTITLES_OPTIONS = 28,
   UI_MENU_CAMERA            = 29,
   UI_MENU_SAVE              = 30,
   UI_MENU_LOAD              = 31,
   UI_MENU_SOUND             = 32,
   UI_MENU_SKILL_POINTS      = 36,
   UI_MENU_CHEATS            = 38,
   UI_MENU_CINEMATICS        = 39,
   UI_MENU_IN_LEVEL_MOVIES   = 40,
   UI_MENU_SKETCHBOOK        = 41,
   UI_MENU_EPILOGUE          = 42,
   UI_MENU_COMMERCIALS       = 44,
} UIMenuIds_e;

typedef enum UiMenuElementSlot {
   UI_MENU_ELEMENT_SLOT_0     = 0,
   UI_MENU_ELEMENT_SLOT_1     = 1,
   UI_MENU_ELEMENT_SLOT_2     = 2,
   UI_MENU_ELEMENT_SLOT_3     = 3,
   UI_MENU_ELEMENT_SLOT_4     = 4,
   UI_MENU_ELEMENT_SLOT_5     = 5,
   UI_MENU_ELEMENT_SLOT_6     = 6,
   UI_MENU_ELEMENT_SLOT_7     = 7,
   UI_MENU_ELEMENT_SLOT_8     = 8,
   UI_MENU_ELEMENT_SLOT_9     = 9,
   UI_MENU_ELEMENT_SLOT_10    = 10,
   UI_MENU_ELEMENT_SLOT_11    = 11,
   UI_MENU_ELEMENT_SLOT_12    = 12,
   UI_MENU_ELEMENT_SLOT_13    = 13,
   UI_MENU_ELEMENT_SLOT_COUNT = UI_MENU_MAX_ELEMENTS,
} UiMenuElementSlot_e;

struct UiElementBase;
struct UiElementMenuOption;
struct UiMenu;

// Shared UI records

typedef struct UiResourceTable {
/* 0x0 */ u32 *pResource;
/* 0x4 */ u32 flag;
} UiResourceTable_t;

typedef struct UiFrameTableEntry { // 0x8
/* 0x0 */ u32 offset;
/* 0x4 */ u32 size;
} UiFrameTableEntry_t;

typedef struct UiString { // 0x4
/* 0x0 */ short flags;
/* 0x2 */ u16 id;
} UiString_t;

typedef struct UiSelectValueEntry { // 0x18
/* 0x00 */ UiString_t labelStringId;
/* 0x04 */ int *pModifier;
/* 0x08 */ UiString_t stringId[4];
} UiSelectValueEntry_t;

typedef struct UiOptionEntry { // 0x0c
/* 0x00 */ UiString_t labelStringId;
/* 0x04 */ struct UiMenu *pNextMenu;
/* 0x08 */ int timeSelected;
} UiOptionEntry_t;

typedef struct UiMenuOption { // 0x18
/* 0x00 */ UiString_t labelStringId;
/* 0x04 */ struct UiMenu *pNextMenu;
/* 0x08 */ int timeSelected;
/* 0x0c */ int pad_0c[3];
} UiMenuOption_t;

typedef struct UiGlobals { // 0x4f0
/* 0x000 */ int activeIndex;
/* 0x004 */ void *pActiveMenu;
/* 0x008 */ void *pChangeToMenu;
/* 0x00c */ int exitAction;
/* 0x010 */ void *pScratchBufferB;
/* 0x014 */ int transitionTimer;
/* 0x018 */ void *pSavedLevelHeapPtr;
/* 0x01c */ char pad_01c[0x14];
/* 0x030 */ char savedCameraState[0x40];
/* 0x070 */ char pad_070[0x5b];
/* 0x0cb */ bool resourceLoadActive;
/* 0x0cc */ u32 savedMenuAllocCount;
/* 0x0d0 */ void *pPreviousActiveMenu;
/* 0x0d4 */ char pad_0d4[0x10];
/* 0x0e4 */ int returnPlanetId;
/* 0x0e8 */ float savedCameraDistance;
/* 0x0ec */ char pad_0ec[0x04];
/* 0x0f0 */ void *pReturnMenu;
/* 0x0f4 */ int returnMenuIndex;
/* 0x0f8 */ char pad_0f8[0x04];
/* 0x0fc */ void *pResourcePoolSmallAlt;
/* 0x100 */ void *pResourcePoolLargeAlt;
/* 0x104 */ void *pScratchBufferA;
/* 0x108 */ void *pResourcePoolPrimary;
/* 0x10c */ void *pResourcePoolSecondary;
/* 0x110 */ int frameCounter;
/* 0x114 */ char pad_114[0x10];
/* 0x124 */ int suppressExitInput;
/* 0x128 */ char pad_128[0x78];
/* 0x1a0 */ Moby *uiMobys[14];
/* 0x1d8 */ char pad_1d8[0x2f0];
/* 0x4c8 */ UiResourceTable_t resourceTable[5];
} UiGlobals_t;

// UI elements

typedef struct UiElementBase { // 0x30
/* 0x00 */ void *pUpdate;
/* 0x04 */ void *pDraw;
/* 0x08 */ void *pInit;
/* 0x0c */ void *pUninit;
/* 0x10 */ void *pCallback10;
/* 0x14 */ Moby *pMoby;
/* 0x18 */ int w;
/* 0x1c */ int h;
/* 0x20 */ int x;
/* 0x24 */ int y;
/* 0x28 */ int unk_28;
/* 0x2c */ int unk_2c;
} UiElementBase_t;

typedef struct UiElementText { // 0x58
/* 0x00 */ UiElementBase_t base;
/* 0x30 */ u32 modeFlags;
/* 0x34 */ int stringId;
/* 0x38 */ int entryStride;
/* 0x3c */ int scrollOffset;
/* 0x40 */ int selectedIndex;
/* 0x44 */ int uptime;
/* 0x48 */ int currentStringId;
/* 0x4c */ u32 currentMsgFlags;
/* 0x50 */ char unk_50[0x8];
} UiElementText_t;

typedef struct UiElementList { // 0x50
/* 0x00 */ UiElementBase_t base;
/* 0x30 */ u32 modeFlags;
/* 0x34 */ UiSelectValueEntry_t *pOptions;
/* 0x38 */ int entryStride;
/* 0x3c */ int scrollOffset;
/* 0x40 */ int selectedIndex;
/* 0x44 */ int uptime;
/* 0x48 */ int currentStringId;
/* 0x4c */ u32 currentMsgFlags;
} UiElementList_t;

typedef struct UiElementDescriptionList { // 0x70
/* 0x00 */ UiElementList_t list;
/* 0x50 */ int descriptionStringId[8];
} UiElementDescriptionList_t;

typedef struct UiElementDescriptionText { // 0x58
/* 0x00 */ UiElementBase_t base;
/* 0x30 */ u32 modeFlags;
/* 0x34 */ int *pDescriptionStringId;
/* 0x38 */ int entryStride;
/* 0x3c */ int scrollOffset;
/* 0x40 */ int selectedIndex;
/* 0x44 */ int uptime;
/* 0x48 */ int currentStringId;
/* 0x4c */ u32 currentMsgFlags;
/* 0x50 */ int pad_50[2];
} UiElementDescriptionText_t;

typedef struct UiElementResourceHeader { // 0x50
/* 0x00 */ UiElementBase_t base;
/* 0x30 */ UiFrameTableEntry_t *pFrameTable;
/* 0x34 */ u32 modeFlags;
/* 0x38 */ UiSelectValueEntry_t *pOptions;
/* 0x3c */ int uptime;
/* 0x40 */ void *pLoadHandle;
/* 0x44 */ int state;            // -1 = idle, 0-6 = load pipeline stage
/* 0x48 */ void *pBufferA;
/* 0x4c */ void *pBufferB;
} UiElementResourceHeader_t;

typedef struct UiElementResource { // 0x68
/* 0x00 */ UiElementResourceHeader_t header;
/* 0x50 */ int committedFrameA;
/* 0x54 */ int committedFrameB;
/* 0x58 */ int forcedFrame;
/* 0x5c */ u32 callCount;
/* 0x60 */ int loadOffsetAdjust;
/* 0x64 */ int pad_64;
} UiElementResource_t;

typedef struct UiElementMenuOption { // 0x50
/* 0x00 */ UiElementBase_t base;
/* 0x30 */ int pad_30[4];
/* 0x40 */ int state;
/* 0x44 */ UiMenuOption_t *pOption;
/* 0x48 */ struct UiElementMenuOption *pPreviousElement;
/* 0x4c */ struct UiElementMenuOption *pNextElement;
} UiElementMenuOption_t;

typedef struct UiElementSelectExit { // 0x50
/* 0x00 */ UiElementResourceHeader_t resource;
} UiElementSelectExit_t;

// UI menus

typedef struct UiMenu { // 0x88
/* 0x00 */ int mobyAnimIds[UI_MENU_MAX_ELEMENTS];
/* 0x38 */ struct UiMenu *pParent;
/* 0x3c */ UIMenuIds_e menuId;
/* 0x40 */ UiElementBase_t *pSelectedElement;
/* 0x44 */ UiElementBase_t *pElements[UI_MENU_MAX_ELEMENTS];
/* 0x7c */ int elementCountOrState;
/* 0x80 */ UiElementBase_t *pQueuedSelectedElement;
/* 0x84 */ int queuedSelectionState;
} UiMenu_t;

typedef struct UiCustomMenu {
/* 0x000 */ UiMenu_t menu;
/* 0x088 */ UiMenuOption_t entries[UI_CUSTOM_MENU_MAX_OPTIONS];
/* 0x1d8 */ UiElementMenuOption_t optionElements[UI_CUSTOM_MENU_MAX_OPTIONS];
} UiCustomMenu_t;

typedef struct UiCustomTextMenu {
/* 0x000 */ UiMenu_t menu;
/* 0x088 */ UiElementText_t title;
/* 0x0e0 */ UiElementDescriptionText_t body;
/* 0x138 */ UiElementSelectExit_t selectExit;
} UiCustomTextMenu_t;

typedef struct UiPauseMenuEntries { // 0xa8
/* 0x00 */ UiMenuOption_t weapons;
/* 0x18 */ UiMenuOption_t gadgets;
/* 0x30 */ UiMenuOption_t quickSelect;
/* 0x48 */ UiMenuOption_t items;
/* 0x60 */ UiMenuOption_t help;
/* 0x78 */ UiMenuOption_t options;
/* 0x90 */ UiMenuOption_t goodies;
} UiPauseMenuEntries_t;

typedef struct UiPauseMenu { // 0x360
/* 0x000 */ UiMenu_t menu;
/* 0x088 */ UiPauseMenuEntries_t entries;
/* 0x130 */ UiElementMenuOption_t optionElements[7];
} UiPauseMenu_t;

typedef struct UiWeaponsMenu { // 0x88, menu header view
/* 0x00 */ int mobyAnimIds[14];
/* 0x38 */ UiMenu_t *pParent;
/* 0x3c */ UIMenuIds_e menuId;
/* 0x40 */ UiElementBase_t *pSelectedElement;
/* 0x44 */ UiElementText_t *pTitle;
/* 0x48 */ UiElementBase_t *pInventoryPanel;
/* 0x4c */ UiElementBase_t *pWeaponList;
/* 0x50 */ UiElementBase_t *pHelpWeapons;
/* 0x54 */ UiElementBase_t *pGadgetsTab;
/* 0x58 */ UiElementBase_t *pDescription;
/* 0x5c */ UiElementBase_t *pSharedFrame;
/* 0x60 */ UiElementBase_t *pAmmo;
/* 0x64 */ UiElementBase_t *pPrice;
/* 0x68 */ UiElementBase_t *pSlots[5];
/* 0x7c */ int elementCountOrState;
/* 0x80 */ UiElementBase_t *pQueuedSelectedElement;
/* 0x84 */ int queuedSelectionState;
} UiWeaponsMenu_t;

typedef struct UiGadgetsMenu { // 0x88, menu header view
/* 0x00 */ int mobyAnimIds[14];
/* 0x38 */ UiMenu_t *pParent;
/* 0x3c */ UIMenuIds_e menuId;
/* 0x40 */ UiElementBase_t *pSelectedElement;
/* 0x44 */ UiElementText_t *pTitle;
/* 0x48 */ UiElementBase_t *pInventoryPanel;
/* 0x4c */ UiElementBase_t *pGadgetList;
/* 0x50 */ UiElementBase_t *pSelectedGadget;
/* 0x54 */ UiElementBase_t *pWeaponTab;
/* 0x58 */ UiElementBase_t *pHelpGadgets;
/* 0x5c */ UiElementBase_t *pSharedFrame;
/* 0x60 */ UiElementBase_t *pDescription;
/* 0x64 */ UiElementBase_t *pPrice;
/* 0x68 */ UiElementBase_t *pSlots[5];
/* 0x7c */ int elementCountOrState;
/* 0x80 */ UiElementBase_t *pQueuedSelectedElement;
/* 0x84 */ int queuedSelectionState;
} UiGadgetsMenu_t;

typedef struct UiQuickSelectMenu { // 0x88, menu header view
/* 0x00 */ int mobyAnimIds[14];
/* 0x38 */ UiMenu_t *pParent;
/* 0x3c */ UIMenuIds_e menuId;
/* 0x40 */ UiElementBase_t *pSelectedElement;
/* 0x44 */ UiElementText_t *pTitle;
/* 0x48 */ UiElementBase_t *pInventoryPanel;
/* 0x4c */ UiElementBase_t *pQuickSelectList;
/* 0x50 */ UiElementBase_t *pSelectedSlot;
/* 0x54 */ UiElementBase_t *pWeaponsTab;
/* 0x58 */ UiElementBase_t *pGadgetsTab;
/* 0x5c */ UiElementBase_t *pSharedFrame;
/* 0x60 */ UiElementBase_t *pDescription;
/* 0x64 */ UiElementBase_t *pPrice;
/* 0x68 */ UiElementBase_t *pSlots[5];
/* 0x7c */ int elementCountOrState;
/* 0x80 */ UiElementBase_t *pQueuedSelectedElement;
/* 0x84 */ int queuedSelectionState;
} UiQuickSelectMenu_t;

typedef struct UiItemsMenu { // 0x88, menu header view
/* 0x00 */ int mobyAnimIds[14];
/* 0x38 */ UiMenu_t *pParent;
/* 0x3c */ UIMenuIds_e menuId;
/* 0x40 */ UiElementBase_t *pSelectedElement;
/* 0x44 */ UiElementText_t *pTitle;
/* 0x48 */ UiElementBase_t *pItemList;
/* 0x4c */ UiElementBase_t *pHandItems;
/* 0x50 */ UiElementBase_t *pBackPacks;
/* 0x54 */ UiElementBase_t *pHeadItems;
/* 0x58 */ UiElementBase_t *pFootItems;
/* 0x5c */ UiElementBase_t *pCategoryTab;
/* 0x60 */ UiElementBase_t *pSharedFrame;
/* 0x64 */ UiElementBase_t *pDescription;
/* 0x68 */ UiElementBase_t *pSlots[5];
/* 0x7c */ int elementCountOrState;
/* 0x80 */ UiElementBase_t *pQueuedSelectedElement;
/* 0x84 */ int queuedSelectionState;
} UiItemsMenu_t;

typedef struct UiHelpMenu { // 0x88, menu header view
/* 0x00 */ int mobyAnimIds[14];
/* 0x38 */ UiMenu_t *pParent;
/* 0x3c */ UIMenuIds_e menuId;
/* 0x40 */ UiElementBase_t *pSelectedElement;
/* 0x44 */ UiElementBase_t *pHelpList;
/* 0x48 */ UiElementText_t *pTitle;
/* 0x4c */ UiElementBase_t *pDescription;
/* 0x50 */ UiElementBase_t *pResource;
/* 0x54 */ UiElementBase_t *pSelectedHelpEntry;
/* 0x58 */ UiElementBase_t *pFooter;
/* 0x5c */ UiElementBase_t *pSlots[8];
/* 0x7c */ int elementCountOrState;
/* 0x80 */ UiElementBase_t *pQueuedSelectedElement;
/* 0x84 */ int queuedSelectionState;
} UiHelpMenu_t;

typedef struct UiHelpTopicMenu { // 0x88, menu header view
/* 0x00 */ int mobyAnimIds[14];
/* 0x38 */ UiMenu_t *pParent;
/* 0x3c */ UIMenuIds_e menuId;
/* 0x40 */ UiElementBase_t *pSelectedElement;
/* 0x44 */ UiElementText_t *pTitle;
/* 0x48 */ UiElementBase_t *pTopicText;
/* 0x4c */ UiElementBase_t *pSelectedTopicText;
/* 0x50 */ UiElementBase_t *pControls;
/* 0x54 */ UiElementBase_t *pFooter;
/* 0x58 */ UiElementBase_t *pSlots[9];
/* 0x7c */ int elementCountOrState;
/* 0x80 */ UiElementBase_t *pQueuedSelectedElement;
/* 0x84 */ int queuedSelectionState;
} UiHelpTopicMenu_t;

/*
 NOTES:
 Updating description list option labels also updates the matching UiOptionsMenuMain entry labelStringId.
*/

typedef struct UiOptionsMenuMain { // 0xc8
/* 0x00 */ UiElementResource_t resource;
/* 0x68 */ UiOptionEntry_t helpDesk;
/* 0x74 */ UiOptionEntry_t save;
/* 0x80 */ UiOptionEntry_t load;
/* 0x8c */ UiOptionEntry_t sound;
/* 0x98 */ UiOptionEntry_t camera;
/* 0xa4 */ UiOptionEntry_t subtitles;
/* 0xb0 */ UiOptionEntry_t quit;
/* 0xbc */ UiOptionEntry_t empty;
} UiOptionsMenuMain_t;

typedef struct UiOptionsMenu { // 0x150
/* 0x000 */ UiMenu_t menu;
/* 0x088 */ UiOptionsMenuMain_t main;
} UiOptionsMenu_t;

typedef struct UiGoodiesMenuEntries { // 0x6c
/* 0x00 */ UiOptionEntry_t skillPoints;
/* 0x0c */ UiOptionEntry_t credits;
/* 0x18 */ UiOptionEntry_t cheats;
/* 0x24 */ UiOptionEntry_t cinematics;
/* 0x30 */ UiOptionEntry_t inLevelMovies;
/* 0x3c */ UiOptionEntry_t sketchbook;
/* 0x48 */ UiOptionEntry_t epilogue;
/* 0x54 */ UiOptionEntry_t makingOfVideo;
/* 0x60 */ UiOptionEntry_t commercials;
} UiGoodiesMenuEntries_t;

typedef struct UiGoodiesMenu { // 0x118
/* 0x000 */ UiMenu_t menu;
/* 0x088 */ UiGoodiesMenuEntries_t entries;
/* 0x0f4 */ int descriptionStringId[9];
} UiGoodiesMenu_t;

typedef struct UiPlanetSelectMenu { // 0x88, menu header view
/* 0x00 */ int mobyAnimIds[14];
/* 0x38 */ UiMenu_t *pParent;
/* 0x3c */ UIMenuIds_e menuId;
/* 0x40 */ UiElementBase_t *pSelectedElement;
/* 0x44 */ UiElementBase_t *pPlanetList;
/* 0x48 */ UiElementBase_t *pPreviousMap;
/* 0x4c */ UiElementBase_t *pNextMap;
/* 0x50 */ UiElementBase_t *pSelectedPlanet;
/* 0x54 */ UiElementBase_t *pMapPreview;
/* 0x58 */ UiElementBase_t *pControls;
/* 0x5c */ UiElementBase_t *pSlots[8];
/* 0x7c */ int elementCountOrState;
/* 0x80 */ UiElementBase_t *pQueuedSelectedElement;
/* 0x84 */ int queuedSelectionState;
} UiPlanetSelectMenu_t;

#endif // _LIBRAC1_UI_H_