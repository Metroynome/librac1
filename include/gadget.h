#ifndef _LIBRAC1_GADGET_H_
#define _LIBRAC1_GADGET_H_

#include "types.h"

typedef enum GADGET_IDS {
    GADGET_ID_NONE = 0,
    GADGET_ID_WRENCH = 8,
    GADGET_ID_SUCK_CANNON = 9,
    GADGET_ID_BOMB_GLOVE = 10,
    GADGET_ID_DEVASTATOR = 11,
    GADGET_ID_SWINGSHOT = 12,
    GADGET_ID_VISIBOMB_GUN = 13,
    GADGET_ID_TAUNTER = 14,
    GADGET_ID_BLASTER = 15,
    GADGET_ID_PYROCITOR = 16,
    GADGET_ID_MINE_GLOVE = 17,
    GADGET_ID_WALLOPER = 18,
    GADGET_ID_TESLA_CLAW = 19,
    GADGET_ID_GLOVE_OF_DOOM = 20,
    GADGET_ID_MORPH_O_RAY = 21,
    GADGET_ID_HYDRODISPLACER = 22,
    GADGET_ID_RYNO = 23,
    GADGET_ID_DRONE_DEVICE = 24,
    GADGET_ID_DECOY_GLOVE = 25,
    GADGET_ID_TRESPASSER = 26,
    GADGET_ID_PDA = 32,
} eGADGET_IDS;

#define GADGET_DEF_COUNT 37

// RAC1's per-gadget definition, indexed by gadget ID (PS2 layout: 0x4c).
// unk_* fields retain their offsets without assuming Deadlocked semantics.
typedef struct GadgetDef {
    /* 0x00 */ int unk_00; // Message-tag-like value; exact role unverified.
    /* 0x04 */ int unk_04; // Gold message-tag-like value; exact role unverified.
    /* 0x08 */ int type; // Index into the hero's equipped gadget slots.
    /* 0x0c */ int joint; // Index into the hero's gadget attachment matrices.
    /* 0x10 */ int mobyClass;
    /* 0x14 */ int mobyClass2;
    /* 0x18 */ int handGadgetType;
    /* 0x1c */ int unk_1c;
    /* 0x20 */ int unk_20;
    /* 0x24 */ int fullFireAnim;
    /* 0x28 */ int armFireAnimDefault;
    /* 0x2c */ int armFireAnimCrouch;
    /* 0x30 */ int cycleFire;
    /* 0x34 */ short ammoPickupTagPlural;
    /* 0x36 */ short ammoPickupTagSingular;
    /* 0x38 */ unsigned short icon;
    /* 0x3a */ short ammoClass;
    /* 0x3c */ short unk_3c; // Do not treat this as maximum ammo.
    /* 0x3e */ short maxUpgradeLevel; // 1 for gold-capable weapons, otherwise 0.
    /* 0x40 */ short menuTextTag;
    /* 0x42 */ short unk_42;
    /* 0x44 */ short menuSecondaryTextTag;
    /* 0x46 */ short quickSelectTag;
    /* 0x48 */ short goldQuickSelectTag;
    /* 0x4a */ short unk_4a;
} GadgetDef;

// Returns the live definition for IDs 1..36 in normal gameplay, or NULL for
// NONE/invalid IDs, unavailable levels/modes, or unsupported builds.
// Supports all four library builds. Reacquire after changing levels: this is
// overlay data, so pointers and edits do not survive an overlay reload.
GadgetDef *gadgetGetDef(eGADGET_IDS gadgetId);

// Sets the gold-upgrade flag for a weapon with a gold variant.
// Returns 1 on success (including already unlocked), or 0 for an unsupported
// gadget or build. Supports NTSC-U, PAL v1.00/v2.00, and NTSC-J retail.
// Does not grant the base weapon, charge currency, or refresh its held model.
int gadgetUnlockGold(eGADGET_IDS gadgetId);

#endif // _LIBRAC1_GADGET_H_
