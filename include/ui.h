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
#define UI_CUSTOM_TEXT_DEFAULT_COLOR 0x80808080
#define UI_ELEMENT_RENDER_DIRECT 1
#define UI_ELEMENT_RENDER_SECOND_PASS 2

#define UI_DRAW_RESULT_SKIP_COMPOSITE 1
#define UI_DRAW_RESULT_EXACT_SIZE 2
#define UI_DRAW_RESULT_KEEP_ASPECT 4
#define UI_DRAW_RESULT_CENTER_SOURCE 8
#define UI_DRAW_RESULT_NO_COMPOSITE_SCALE 0x10

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


typedef enum UiSpecialBytes {
   // Font color-control bytes. FontPrint skips these bytes; FontPrintWindow
   // uses them as palette indices when color codes are enabled.
   UI_SPECIAL_COLOR_0          = 0x08,
   UI_SPECIAL_COLOR_1          = 0x09,
   UI_SPECIAL_COLOR_2          = 0x0a,
   UI_SPECIAL_COLOR_3          = 0x0b,
   UI_SPECIAL_COLOR_4          = 0x0c,
   UI_SPECIAL_COLOR_5          = 0x0d,
   UI_SPECIAL_COLOR_6          = 0x0e,
   UI_SPECIAL_COLOR_7          = 0x0f,

   UI_SPECIAL_COLOR_ORANGE     = UI_SPECIAL_COLOR_0,
   UI_SPECIAL_COLOR_WHITE      = UI_SPECIAL_COLOR_1,
   UI_SPECIAL_COLOR_BLUE       = UI_SPECIAL_COLOR_2,
   UI_SPECIAL_COLOR_GREEN      = UI_SPECIAL_COLOR_3,
   UI_SPECIAL_COLOR_RED        = UI_SPECIAL_COLOR_4,
   UI_SPECIAL_COLOR_YELLOW     = UI_SPECIAL_COLOR_5,
   UI_SPECIAL_COLOR_GRAY       = UI_SPECIAL_COLOR_6,
   UI_SPECIAL_COLOR_DEFAULT    = UI_SPECIAL_COLOR_7,

   // Font glyph bytes below ASCII space. These draw as 24x16 special glyphs.
   UI_SPECIAL_GLYPH_00         = 0x00,
   UI_SPECIAL_GLYPH_01         = 0x01,
   UI_SPECIAL_GLYPH_02         = 0x02,
   UI_SPECIAL_GLYPH_03         = 0x03,
   UI_SPECIAL_GLYPH_04         = 0x04,
   UI_SPECIAL_GLYPH_05         = 0x05,
   UI_SPECIAL_GLYPH_06         = 0x06,
   UI_SPECIAL_GLYPH_07         = 0x07,
   UI_SPECIAL_GLYPH_10         = 0x10,
   UI_SPECIAL_GLYPH_11         = 0x11,
   UI_SPECIAL_GLYPH_12         = 0x12,
   UI_SPECIAL_BUTTON_CROSS         = 0x10,
   UI_SPECIAL_BUTTON_CIRCLE         = 0x11,
   UI_SPECIAL_BUTTON_TRIANGLE         = 0x12,
   UI_SPECIAL_GLYPH_13         = 0x13,
   UI_SPECIAL_GLYPH_14         = 0x14,
   UI_SPECIAL_GLYPH_15         = 0x15,
   UI_SPECIAL_GLYPH_16         = 0x16,
   UI_SPECIAL_GLYPH_17         = 0x17,
   UI_SPECIAL_GLYPH_18         = 0x18,
   UI_SPECIAL_GLYPH_19         = 0x19,
   UI_SPECIAL_GLYPH_1A         = 0x1a,
   UI_SPECIAL_GLYPH_1B         = 0x1b,
   UI_SPECIAL_GLYPH_1C         = 0x1c,
   UI_SPECIAL_GLYPH_1D         = 0x1d,
   UI_SPECIAL_GLYPH_1E         = 0x1e,
   UI_SPECIAL_GLYPH_1F         = 0x1f,

   // Common controller glyph aliases. Verify visually before depending on a
   // specific byte for final UI copy; these are regular font glyph indices.
   UI_SPECIAL_SELECT           = UI_SPECIAL_GLYPH_10,
   UI_SPECIAL_START            = UI_SPECIAL_GLYPH_11,
   UI_SPECIAL_UP               = UI_SPECIAL_GLYPH_12,
   UI_SPECIAL_DOWN             = UI_SPECIAL_GLYPH_13,
   UI_SPECIAL_LEFT             = UI_SPECIAL_GLYPH_14,
   UI_SPECIAL_RIGHT            = UI_SPECIAL_GLYPH_15,
   UI_SPECIAL_TRIANGLE         = UI_SPECIAL_GLYPH_16,
   UI_SPECIAL_CIRCLE           = UI_SPECIAL_GLYPH_17,
   UI_SPECIAL_CROSS            = UI_SPECIAL_GLYPH_18,
   UI_SPECIAL_SQUARE           = UI_SPECIAL_GLYPH_19,
   UI_SPECIAL_L1               = UI_SPECIAL_GLYPH_1A,
   UI_SPECIAL_R1               = UI_SPECIAL_GLYPH_1B,
   UI_SPECIAL_L2               = UI_SPECIAL_GLYPH_1C,
   UI_SPECIAL_R2               = UI_SPECIAL_GLYPH_1D,
   UI_SPECIAL_L3               = UI_SPECIAL_GLYPH_1E,
   UI_SPECIAL_R3               = UI_SPECIAL_GLYPH_1F,
} UiSpecialBytes_e;

typedef enum UiModeFlags {
   UI_FLAG_CENTER_H          = 0x00001,  // center text horizontally (width/2 offset)
   UI_FLAG_CENTER_V          = 0x00002,  // center text vertically (height/2 offset)
   UI_FLAG_HERO_ANIM_SRC     = 0x00004,  // stock fixed-string title/text branch with transition timing
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
   UI_FLAG_MENU_SRC_ALT      = 0x08000,  // modifies MENU_SRC handling (sets source flag from uGpffff8180)
   UI_FLAG_BOTTOM_ANCHOR     = 0x10000,  // shift box y-position to bottom of screen
} UiModeFlags_e;

typedef enum UIMenuIds {
   UI_MENU_CUSTOM              = 0x100,
   UI_MENU_PAUSE_MAIN          = 2,
   UI_MENU_WEAPONS             = 3,
   UI_MENU_GADGETS             = 4,
   UI_MENU_QUICK_SELECT        = 5,
   UI_MENU_ITEMS               = 6,
   UI_MENU_HELP                = 7,
   UI_MENU_OPTIONS             = 8,
   UI_MENU_GOODIES             = 9,
   UI_MENU_PLANET_SELECT       = 11,
   UI_MENU_PLANET_INFO         = 12, // 0x001b3bf8, opened from planet select
   UI_MENU_QUIT_GAME           = 13,
   UI_MENU_VENDOR              = 15, // 0x001b6508, special activeIndex 0x0f entry
   UI_MENU_VENDOR_CONFIRM      = 16, // 0x001b6878, child of vendor menu
   UI_MENU_HELPDESK            = 19,
   UI_MENU_HELP_LOG            = 21,
   UI_MENU_CONTROLS            = 22,
   UI_MENU_MOVES               = 23,
   UI_MENU_HELP_WEAPONS        = 24,
   UI_MENU_HELP_GADGETS        = 25,
   UI_MENU_SAVE_LOAD_CONFIRM   = 26, // 0x001b6af8, 0x001b93b8, 0x001b9518
   UI_MENU_SUBTITLES           = 27,
   UI_MENU_SUBTITLES_OPTIONS   = 28,
   UI_MENU_CAMERA              = 29,
   UI_MENU_SAVE                = 30,
   UI_MENU_LOAD                = 31, // extra records at 0x001b9180 and 0x001b9208
   UI_MENU_SOUND               = 32, // extra record at 0x001b8e38
   UI_MENU_UNKNOWN_34          = 34, // records at 0x001b7670 and 0x001b9440
   UI_MENU_SKILL_POINTS        = 36,
   UI_MENU_CREDITS             = 37, // records at 0x001b6f30 and 0x001b6fb8
   UI_MENU_CHEATS              = 38,
   UI_MENU_CINEMATICS          = 39,
   UI_MENU_IN_LEVEL_MOVIES     = 40,
   UI_MENU_SKETCHBOOK          = 41,
   UI_MENU_EPILOGUE            = 42,
   UI_MENU_COMMERCIALS         = 44,
   UI_MENU_UNKNOWN_46          = 46, // 0x001b8b48, special activeIndex 0x2d entry
   UI_MENU_UNKNOWN_47          = 47, // 0x001b8d08, child of menu 46
   UI_MENU_UNKNOWN_48          = 48, // 0x001b8ec0, child of menu 47
   UI_MENU_UNKNOWN_49          = 49, // 0x001b9038, child of menu 47
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

// Tracks a resource pool slot used by frame/image-backed UI elements.
// The game maintains five slots in UiGlobals.resourceTable.
typedef struct UiResourceTable {
/* 0x0 */ u32 *pResource;
/* 0x4 */ u32 flag;
} UiResourceTable_t;

// Offset/size pair for one frame inside a loaded UI image resource.
typedef struct UiFrameTableEntry { // 0x8
/* 0x0 */ u32 offset;
/* 0x4 */ u32 size;
} UiFrameTableEntry_t;

// Message string reference. flags are consumed by the UI text drawing path,
// id is the msg_string id.
typedef struct UiString { // 0x4
/* 0x0 */ u16 id;
/* 0x2 */ short flags;
} UiString_t;

// Toggle/select row: label plus up to four value strings selected by *pModifier.
// Used by HelpDesk, Sound, Camera, Subtitles, and similar option pages.
typedef struct UiSelectValueEntry { // 0x18
/* 0x00 */ UiString_t labelStringId;
/* 0x04 */ int *pModifier;
/* 0x08 */ UiString_t stringId[4];
} UiSelectValueEntry_t;

// Compact menu row used by generic lists and footer controls. The stock list
// callbacks overload this 0x0c record: +0 is the label string id, +2 is row
// flags/state, +4 is usually the destination menu/row payload, +8 can be a
// secondary/right-side string id, and +0a is the per-row highlight timer.
typedef struct UiOptionEntry { // 0x0c
/* 0x00 */ UiString_t labelStringId;
/* 0x04 */ union { struct UiMenu *pNextMenu; void *pPayload; int value; };
/* 0x08 */ union {
    int timeSelected;
    UiString_t secondaryStringId;
    struct { u16 valueStringId; short rowTimer; };
};
} UiOptionEntry_t;

// Pause-menu row. Same leading fields as UiOptionEntry, with extra per-row state.
typedef struct UiMenuOption { // 0x18
/* 0x00 */ UiString_t labelStringId;
/* 0x04 */ union { struct UiMenu *pNextMenu; void *pPayload; int value; };
/* 0x08 */ union {
    int timeSelected;
    UiString_t secondaryStringId;
    struct { u16 valueStringId; short rowTimer; };
};
/* 0x0c */ int pad_0c[3];
} UiMenuOption_t;

// Global UI state block. Menu transitions are staged by writing pChangeToMenu,
// then UiMenu_Open/Update promotes it to pActiveMenu and activeIndex.
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

// Common element header. All menu element records start with this callback table
// and owning moby pointer. Ghidra confirms uiRenderMenu writes 0x18/0x1c from
// the projected screen origin and 0x20/0x24 from the projected local window size.
// Stock text/list draw callbacks use windowW/windowH for FontWindow clipping and
// row layout.
typedef struct UiElementBase { // 0x30
/* 0x00 */ void *pUpdate;
/* 0x04 */ void *pDraw;
/* 0x08 */ void *pInit;
/* 0x0c */ void *pUninit;
/* 0x10 */ u32 renderFlags;
/* 0x14 */ Moby *pMoby;
/* 0x18 */ union { int screenX; int w; };
/* 0x1c */ union { int screenY; int h; };
/* 0x20 */ union { int windowW; int x; };
/* 0x24 */ union { int windowH; int y; };
/* 0x28 */ int unk_28;
/* 0x2c */ int unk_2c;
} UiElementBase_t;

// Draws one text label. The source string can be a fixed stringId or derived
// from menu/counter state based on modeFlags.
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

// Custom literal text label. Uses pText directly instead of looking up a RAC1
// msg_string id through the stock UI text path.
typedef struct UiElementTextCustom { // 0x40
/* 0x00 */ UiElementBase_t base;
/* 0x30 */ u32 modeFlags;
/* 0x34 */ const char *pText;
/* 0x38 */ u32 color;
/* 0x3c */ int pad_3c;
} UiElementTextCustom_t;

// Vertical option list. pPreviousElement/pNextElement are focus links used when
// moving out of the list rather than neighboring entries inside pEntries.
typedef struct UiElementList { // 0x50
/* 0x00 */ UiElementBase_t base;
/* 0x30 */ u32 modeFlags;
/* 0x34 */ UiOptionEntry_t *pEntries;
/* 0x38 */ UiElementBase_t *pPreviousElement;
/* 0x3c */ UiElementBase_t *pNextElement;
/* 0x40 */ int selectedIndex;
/* 0x44 */ int pad_44[3];
} UiElementList_t;

// Option list with a parallel description string table indexed by selectedIndex.
typedef struct UiElementDescriptionList { // 0x70
/* 0x00 */ UiElementList_t list;
/* 0x50 */ int descriptionStringId[8];
} UiElementDescriptionList_t;

// Inventory/grid cell descriptor used by Weapons, Gadgets, and Quick Select.
typedef struct UiElementGridEntry { // 0x0a
/* 0x00 */ u16 frameId;
/* 0x02 */ u16 frameState;
/* 0x04 */ u16 value;
/* 0x06 */ u16 stringId;
/* 0x08 */ u16 altStringId;
} UiElementGridEntry_t;

// Two-dimensional selectable grid. Direction pointers are fallback focus targets
// when navigation leaves the grid bounds.
typedef struct UiElementGrid { // 0x5c
/* 0x00 */ UiElementBase_t base;
/* 0x30 */ u32 modeFlags;
/* 0x34 */ float columnSpacing;
/* 0x38 */ float rowSpacing;
/* 0x3c */ int selectedIndex;
/* 0x40 */ int rowCount;
/* 0x44 */ int columnCount;
/* 0x48 */ UiElementGridEntry_t *pEntries;
/* 0x4c */ UiElementBase_t *pUpElement;
/* 0x50 */ UiElementBase_t *pDownElement;
/* 0x54 */ UiElementBase_t *pLeftElement;
/* 0x58 */ UiElementBase_t *pRightElement;
} UiElementGrid_t;

// Planet selector input/render element used by the galaxy map menus.
typedef struct UiElementPlanetSelect { // 0x68
/* 0x00 */ UiElementBase_t base;
/* 0x30 */ u32 selectedPlanetId;
/* 0x34 */ u32 modeFlags;
/* 0x38 */ int pad_38[12];
} UiElementPlanetSelect_t;

// Planet preview/map frame element. The internals past the common header still
// need a dedicated pass before they should be edited directly.
typedef struct UiElementPlanetPreview { // 0x68
/* 0x00 */ UiElementBase_t base;
/* 0x30 */ int pad_30[14];
} UiElementPlanetPreview_t;

// Text block whose string id is read through pDescriptionStringId, usually from
// the currently selected list/grid entry.
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

// Custom literal description block. Same draw behavior as UiElementTextCustom,
// kept separate so menu layouts can name title/body/footer fields clearly.
typedef struct UiElementDescriptionCustom { // 0x40
/* 0x00 */ UiElementBase_t base;
/* 0x30 */ u32 modeFlags;
/* 0x34 */ const char *pText;
/* 0x38 */ u32 color;
/* 0x3c */ int pad_3c;
} UiElementDescriptionCustom_t;

// Image/frame-backed element header. The state field drives the resource load
// pipeline; use -1 for idle and 0-6 for the loader's staged work.
typedef struct UiElementFrameBase { // 0x50
/* 0x00 */ UiElementBase_t base;
/* 0x30 */ UiFrameTableEntry_t *pFrameTable;
/* 0x34 */ u32 modeFlags;
/* 0x38 */ int frameWidth;
/* 0x3c */ int frameHeight;
/* 0x40 */ int *pFrameIndex;
/* 0x44 */ int state;            // -1 = idle, 0-6 = load pipeline stage
/* 0x48 */ void *pBufferA;
/* 0x4c */ void *pBufferB;
} UiElementFrameBase_t;

// Animated/static UI frame element. forcedFrame overrides the selected frame
// when non-negative; committedFrameA/B are the loaded/rendered frame state.
typedef struct UiElementFrame { // 0x68
/* 0x00 */ UiElementFrameBase_t header;
/* 0x50 */ int committedFrameA;
/* 0x54 */ int committedFrameB;
/* 0x58 */ int forcedFrame;
/* 0x5c */ u32 callCount;
/* 0x60 */ int loadOffsetAdjust;
/* 0x64 */ int pad_64;
} UiElementFrame_t;

// Pause main-menu option element bound to one UiMenuOption row.
typedef struct UiElementMenuOption { // 0x50
/* 0x00 */ UiElementBase_t base;
/* 0x30 */ u32 modeFlags;
/* 0x34 */ UiMenuOption_t *pOption;
/* 0x38 */ struct UiElementMenuOption *pPreviousElement;
/* 0x3c */ struct UiElementMenuOption *pNextElement;
/* 0x40 */ int selectedIndex;
/* 0x44 */ int pad_44[3];
} UiElementMenuOption_t;

// Footer control row. Same layout is used for Select/Exit and Toggle/Exit;
// only the strings in pEntries change.
typedef struct UiElementFooter { // 0x50
/* 0x00 */ UiElementBase_t base;
/* 0x30 */ u32 modeFlags;
/* 0x34 */ UiOptionEntry_t *pEntries;
/* 0x38 */ UiElementBase_t *pPreviousElement;
/* 0x3c */ UiElementBase_t *pNextElement;
/* 0x40 */ int selectedIndex;
/* 0x44 */ int pad_44[3];
} UiElementFooter_t;

// Empty placeholder element. The stock menus use one shared zeroed element in
// unused/background slots that still need a valid child pointer.
typedef struct UiElementEmpty { // 0x30
/* 0x00 */ UiElementBase_t base;
} UiElementEmpty_t;

// Compact options selector with value strings chosen through UiSelectValueEntry.
typedef struct UiElementToggleList { // 0x40
/* 0x00 */ UiElementBase_t base;
/* 0x30 */ u32 modeFlags;
/* 0x34 */ UiSelectValueEntry_t *pOptions; // some callbacks treat this as UiGoodiesToggleEntry_t *
/* 0x38 */ int selectedIndex;
/* 0x3c */ int transitionTimer;
} UiElementToggleList_t;

// Goodies toggle row, used by cheats-style on/off pages.
typedef struct UiGoodiesToggleEntry { // 0x14
/* 0x00 */ int labelStringId;
/* 0x04 */ char *pValue;
/* 0x08 */ int enabledStringId;
/* 0x0c */ int disabledStringId;
/* 0x10 */ u32 flags;
} UiGoodiesToggleEntry_t;

// Goodies toggle list element. The transition timer is used by the page animation
// and selection feedback paths.
typedef struct UiElementGoodiesToggleList { // 0x40
/* 0x00 */ UiElementBase_t base;
/* 0x30 */ u32 modeFlags;
/* 0x34 */ UiGoodiesToggleEntry_t *pEntries;
/* 0x38 */ int selectedIndex;
/* 0x3c */ int transitionTimer;
} UiElementGoodiesToggleList_t;

// Memory-card slot selector used by save/load menus. Save, load, and the
// alternate save/load entry points share this layout with different callbacks.
typedef struct UiElementSaveLoadList { // 0x50
/* 0x00 */ UiElementBase_t base;
/* 0x30 */ u32 modeFlags;
/* 0x34 */ int pad_34;
/* 0x38 */ int pad_38;
/* 0x3c */ int pad_3c;
/* 0x40 */ int selectedIndex;
/* 0x44 */ int pad_44;
/* 0x48 */ int slotIndex;
/* 0x4c */ int state;
} UiElementSaveLoadList_t;

// 3D moby/item preview element used by equipment/help pages.
typedef struct UiElementMobyPreview { // 0x50
/* 0x00 */ UiElementBase_t base;
/* 0x30 */ u32 modeFlags;
/* 0x34 */ int state;
/* 0x38 */ float rotation;
/* 0x3c */ int pad_3c;
/* 0x40 */ int pad_40;
/* 0x44 */ Moby *pMobyA;
/* 0x48 */ Moby *pMobyB;
/* 0x4c */ int pad_4c;
} UiElementMobyPreview_t;

// UI menus

// Base menu header. The first 0x38 bytes are moby animation ids for the element
// slots, followed by parent/id/selection pointers. Menu-specific structs below
// are typed views over this same 0x88-byte header unless they include inline data.
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

// Helper layout for building a custom option menu in writable memory.
typedef struct UiCustomMenu {
/* 0x000 */ UiMenu_t menu;
/* 0x088 */ UiMenuOption_t entries[UI_CUSTOM_MENU_MAX_OPTIONS];
/* 0x1d8 */ UiElementMenuOption_t optionElements[UI_CUSTOM_MENU_MAX_OPTIONS];
} UiCustomMenu_t;

// Helper layout for a custom text/info page with a title, body, and footer.
typedef struct UiCustomTextMenu {
/* 0x000 */ UiMenu_t menu;
/* 0x088 */ UiElementTextCustom_t title;
/* 0x0c8 */ UiElementDescriptionCustom_t body;
/* 0x108 */ UiElementFooter_t footer;
} UiCustomTextMenu_t;

// Inline rows for the stock pause menu.
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
/* 0x4c */ UiElementGrid_t *pWeaponList;
/* 0x50 */ UiElementBase_t *pHelpWeapons;
/* 0x54 */ UiElementBase_t *pGadgetsTab;
/* 0x58 */ UiElementDescriptionText_t *pDescription;
/* 0x5c */ UiElementFrame_t *pSharedFrame;
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
/* 0x4c */ UiElementGrid_t *pGadgetList;
/* 0x50 */ UiElementBase_t *pSelectedGadget;
/* 0x54 */ UiElementBase_t *pWeaponTab;
/* 0x58 */ UiElementBase_t *pHelpGadgets;
/* 0x5c */ UiElementFrame_t *pSharedFrame;
/* 0x60 */ UiElementDescriptionText_t *pDescription;
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
/* 0x4c */ UiElementGrid_t *pQuickSelectList;
/* 0x50 */ UiElementBase_t *pSelectedSlot;
/* 0x54 */ UiElementBase_t *pWeaponsTab;
/* 0x58 */ UiElementBase_t *pGadgetsTab;
/* 0x5c */ UiElementFrame_t *pSharedFrame;
/* 0x60 */ UiElementDescriptionText_t *pDescription;
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
/* 0x60 */ UiElementFrame_t *pSharedFrame;
/* 0x64 */ UiElementDescriptionText_t *pDescription;
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
/* 0x44 */ UiElementList_t *pHelpList;
/* 0x48 */ UiElementText_t *pTitle;
/* 0x4c */ UiElementDescriptionText_t *pDescription;
/* 0x50 */ UiElementFrame_t *pResource;
/* 0x54 */ UiElementList_t *pSelectedHelpEntry;
/* 0x58 */ UiElementFooter_t *pFooter;
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
/* 0x50 */ UiElementFooter_t *pControls;
/* 0x54 */ UiElementFooter_t *pFooter;
/* 0x58 */ UiElementBase_t *pSlots[9];
/* 0x7c */ int elementCountOrState;
/* 0x80 */ UiElementBase_t *pQueuedSelectedElement;
/* 0x84 */ int queuedSelectionState;
} UiHelpTopicMenu_t;

/*
 NOTES:
 Updating description list option labels also updates the matching UiOptionsMenuMain entry labelStringId.
*/

// Options menu inline data: one shared frame plus the main option rows.
typedef struct UiOptionsMenuMain { // 0xc8
/* 0x00 */ UiElementFrame_t frame;
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

// Inline rows for the Goodies root menu.
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

// Header view for one-page toggle menus: HelpDesk, Subtitles, Sound, Camera,
// and related option pages.
typedef struct UiToggleOptionsMenu { // 0x88, menu header view
/* 0x00 */ int mobyAnimIds[14];
/* 0x38 */ UiMenu_t *pParent;
/* 0x3c */ UIMenuIds_e menuId;
/* 0x40 */ UiElementBase_t *pSelectedElement;
/* 0x44 */ UiElementText_t *pTitle;
/* 0x48 */ UiElementEmpty_t *pBackgroundA;
/* 0x4c */ UiElementEmpty_t *pBackgroundB;
/* 0x50 */ UiElementToggleList_t *pToggleList;
/* 0x54 */ UiElementFooter_t *pFooter;
/* 0x58 */ UiElementBase_t *pSlots[9];
/* 0x7c */ int elementCountOrState;
/* 0x80 */ UiElementBase_t *pQueuedSelectedElement;
/* 0x84 */ int queuedSelectionState;
} UiToggleOptionsMenu_t;

// Header view for confirmation/dialog menus, including Quit Game and the
// save/load confirmation records.
typedef struct UiConfirmMenu { // 0x88, menu header view
/* 0x00 */ int mobyAnimIds[14];
/* 0x38 */ UiMenu_t *pParent;
/* 0x3c */ UIMenuIds_e menuId;
/* 0x40 */ UiElementBase_t *pSelectedElement;
/* 0x44 */ UiElementText_t *pTitle;
/* 0x48 */ UiElementBase_t *pBackgroundA;
/* 0x4c */ UiElementBase_t *pBackgroundB;
/* 0x50 */ UiElementBase_t *pBackgroundC;
/* 0x54 */ UiElementText_t *pSelectedTitle;
/* 0x58 */ UiElementBase_t *pSlots[9];
/* 0x7c */ int elementCountOrState;
/* 0x80 */ UiElementBase_t *pQueuedSelectedElement;
/* 0x84 */ int queuedSelectionState;
} UiConfirmMenu_t;

// Header view for memory-card save/load slot lists. Extra menu records reuse
// menu id 31 for alternate load states.
typedef struct UiSaveLoadMenu { // 0x88, menu header view
/* 0x00 */ int mobyAnimIds[14];
/* 0x38 */ UiMenu_t *pParent;
/* 0x3c */ UIMenuIds_e menuId;
/* 0x40 */ UiElementSaveLoadList_t *pSelectedElement;
/* 0x44 */ UiElementText_t *pTitle;
/* 0x48 */ UiElementSaveLoadList_t *pSlotList;
/* 0x4c */ UiElementFrame_t *pDetailFrame;
/* 0x50 */ UiElementBase_t *pPreview;
/* 0x54 */ UiElementFooter_t *pFooter;
/* 0x58 */ UiElementBase_t *pSlots[9];
/* 0x7c */ int elementCountOrState;
/* 0x80 */ UiElementBase_t *pQueuedSelectedElement;
/* 0x84 */ int queuedSelectionState;
} UiSaveLoadMenu_t;

// Header view for Goodies list pages such as Skill Points, Credits, Cinematics,
// Movies, Sketchbook, Epilogue, and Commercials.
typedef struct UiGoodiesListMenu { // 0x88, menu header view
/* 0x00 */ int mobyAnimIds[14];
/* 0x38 */ UiMenu_t *pParent;
/* 0x3c */ UIMenuIds_e menuId;
/* 0x40 */ UiElementBase_t *pSelectedElement;
/* 0x44 */ UiElementText_t *pTitle;
/* 0x48 */ UiElementBase_t *pList;
/* 0x4c */ UiElementText_t *pSelectedTitle;
/* 0x50 */ UiElementBase_t *pPreview;
/* 0x54 */ UiElementBase_t *pFooter;
/* 0x58 */ UiElementBase_t *pSlots[9];
/* 0x7c */ int elementCountOrState;
/* 0x80 */ UiElementBase_t *pQueuedSelectedElement;
/* 0x84 */ int queuedSelectionState;
} UiGoodiesListMenu_t;

// Header view for Goodies toggle pages such as Cheats.
typedef struct UiGoodiesToggleMenu { // 0x88, menu header view
/* 0x00 */ int mobyAnimIds[14];
/* 0x38 */ UiMenu_t *pParent;
/* 0x3c */ UIMenuIds_e menuId;
/* 0x40 */ UiElementBase_t *pSelectedElement;
/* 0x44 */ UiElementText_t *pTitle;
/* 0x48 */ UiElementBase_t *pBody;
/* 0x4c */ UiElementText_t *pSelectedTitle;
/* 0x50 */ UiElementGoodiesToggleList_t *pToggleList;
/* 0x54 */ UiElementBase_t *pSlots[10];
/* 0x7c */ int elementCountOrState;
/* 0x80 */ UiElementBase_t *pQueuedSelectedElement;
/* 0x84 */ int queuedSelectionState;
} UiGoodiesToggleMenu_t;

// Header view for galaxy map selection and planet info menus.
typedef struct UiPlanetSelectMenu { // 0x88, menu header view
/* 0x00 */ int mobyAnimIds[14];
/* 0x38 */ UiMenu_t *pParent;
/* 0x3c */ UIMenuIds_e menuId;
/* 0x40 */ UiElementBase_t *pSelectedElement;
/* 0x44 */ UiElementPlanetSelect_t *pPlanetList;
/* 0x48 */ UiElementText_t *pPreviousMap;
/* 0x4c */ UiElementText_t *pNextMap;
/* 0x50 */ UiElementPlanetSelect_t *pSelectedPlanet;
/* 0x54 */ UiElementPlanetPreview_t *pMapPreview;
/* 0x58 */ UiElementFooter_t *pControls;
/* 0x5c */ UiElementBase_t *pSlots[8];
/* 0x7c */ int elementCountOrState;
/* 0x80 */ UiElementBase_t *pQueuedSelectedElement;
/* 0x84 */ int queuedSelectionState;
} UiPlanetSelectMenu_t;

// Stock UI callback trampolines. These resolve through VariableAddress_t for the active level/region.
void uiVTableHandleExit(UiElementBase_t *element);
u64 uiVTableDraw(UiElementBase_t *element);
u64 uiElementSelectDrawList(UiElementList_t *element);
u64 uiElementSelectDrawWindowList(UiElementList_t *element);
void uiResourceElementInit(UiElementFrameBase_t *element);
u64 uiVTableUseResourceTableOff(void);
void uiResourceElementUpdate(UiElementFrameBase_t *element);
u64 uiVTableDrawTexture(UiElementFrame_t *element);
void uiVTableOptionsInit(UiElementFrameBase_t *element);
void uiVTableOptionsMenuShutdown(UiElementFrameBase_t *element);
void uiVTableUpdateState(UiElementFrameBase_t *element);
// UI frame and element helpers

// Set only the cached screen bounds. uiRenderMenu normally overwrites these from point[0] and point[3].
void uiFramePvarSetScreenRect(M1138_MenuItem_Pvar_t *frame, int x, int y, int w, int h);
// Set caller-owned corner points in the same space consumed by uiRenderMenu.
void uiFramePvarSetCorners2D(M1138_MenuItem_Pvar_t *frame, float x, float y, float z, float w, float h);
void uiFramePvarSetCorners(M1138_MenuItem_Pvar_t *frame, const VECTOR topLeft, const VECTOR topRight, const VECTOR bottomLeft, const VECTOR bottomRight);
void uiFrameMobyAttach(Moby *moby, M1138_MenuItem_Pvar_t *frame);
void uiFrameMobyUseCustomPoints(Moby *moby, M1138_MenuItem_Pvar_t *frame);
Moby *uiMenuGetFrameMoby(int slot);
int uiMenuSetFrameAnim(UiMenu_t *menu, int slot, int animId);
int uiMenuCopyFrameAnims(UiMenu_t *menu, const UiMenu_t *source);
int uiMenuSetElement(UiMenu_t *menu, int slot, UiElementBase_t *element);
// Safe to call while preparing a menu. It only retargets the live frame moby when menu is active.
int uiMenuBindFrameSlot(UiMenu_t *menu, int slot, UiElementBase_t *element, M1138_MenuItem_Pvar_t *frame);
void uiMenuInit(UiMenu_t *menu, UiMenu_t *parent, int menuId);
void uiMenuOpen(UiMenu_t *menu);

void uiCreateBase(UiElementBase_t *element, M1138_MenuItem_Pvar_t *frame, const VECTOR topLeft, const VECTOR topRight, const VECTOR bottomLeft, const VECTOR bottomRight);
void uiCreateText(UiElementText_t *element, M1138_MenuItem_Pvar_t *frame, const VECTOR topLeft, const VECTOR topRight, const VECTOR bottomLeft, const VECTOR bottomRight, u32 modeFlags, int stringId);
u64 uiElementTextCustomDraw(UiElementTextCustom_t *element);
u64 uiElementDescriptionCustomDraw(UiElementDescriptionCustom_t *element);
void uiCreateTextCustom(UiElementTextCustom_t *element, M1138_MenuItem_Pvar_t *frame, const VECTOR topLeft, const VECTOR topRight, const VECTOR bottomLeft, const VECTOR bottomRight, u32 modeFlags, const char *pText);
void uiCreateTitleCustom(UiElementTextCustom_t *element, M1138_MenuItem_Pvar_t *frame, const VECTOR topLeft, const VECTOR topRight, const VECTOR bottomLeft, const VECTOR bottomRight, const char *pText);
void uiCreateDescriptionCustom(UiElementDescriptionCustom_t *element, M1138_MenuItem_Pvar_t *frame, const VECTOR topLeft, const VECTOR topRight, const VECTOR bottomLeft, const VECTOR bottomRight, u32 modeFlags, const char *pText);
void uiCreateTitle(UiElementText_t *element, M1138_MenuItem_Pvar_t *frame, const VECTOR topLeft, const VECTOR topRight, const VECTOR bottomLeft, const VECTOR bottomRight, int stringId);
void uiCreateDescription(UiElementDescriptionText_t *element, M1138_MenuItem_Pvar_t *frame, const VECTOR topLeft, const VECTOR topRight, const VECTOR bottomLeft, const VECTOR bottomRight, u32 modeFlags, int *descriptionStringId);
void uiCreateFrame(UiElementFrame_t *element, M1138_MenuItem_Pvar_t *frame, const VECTOR topLeft, const VECTOR topRight, const VECTOR bottomLeft, const VECTOR bottomRight, u32 modeFlags, UiFrameTableEntry_t *frameTable, int frameWidth, int frameHeight, int *frameIndex);
void uiCreateSelectList(UiElementList_t *element, M1138_MenuItem_Pvar_t *frame, const VECTOR topLeft, const VECTOR topRight, const VECTOR bottomLeft, const VECTOR bottomRight, u32 modeFlags, UiOptionEntry_t *entries, UiElementBase_t *previousElement, UiElementBase_t *nextElement, int selectedIndex);
void uiCreateMenuOption(UiElementMenuOption_t *element, M1138_MenuItem_Pvar_t *frame, const VECTOR topLeft, const VECTOR topRight, const VECTOR bottomLeft, const VECTOR bottomRight, u32 modeFlags, UiMenuOption_t *option, UiElementMenuOption_t *previousElement, UiElementMenuOption_t *nextElement, int selectedIndex);
void uiCreateFooter(UiElementFooter_t *element, M1138_MenuItem_Pvar_t *frame, const VECTOR topLeft, const VECTOR topRight, const VECTOR bottomLeft, const VECTOR bottomRight, u32 modeFlags, UiOptionEntry_t *entries, UiElementBase_t *previousElement, UiElementBase_t *nextElement, int selectedIndex);
#endif // _LIBRAC1_UI_H_





