#include "gadget.h"
#include "interop.h"

// Verified against all 19 gameplay overlays for each supported retail build.
// The existing NTSC-J library uses V100 defines for the Japanese v1.02 disc.
#if defined(RAC1_PAL_V200) || defined(RAC1_NTSCJ_V100) || defined(RAC1_NTSCJ_V102)
#define GOLD_GADGET_FLAGS_ADDRESS 0x0013e620
#elif defined(RAC1_NTSCU_V100) || defined(RAC1_PAL_V100)
#define GOLD_GADGET_FLAGS_ADDRESS 0x0013e520
#endif

int gadgetUnlockGold(eGADGET_IDS gadgetId)
{
#ifdef GOLD_GADGET_FLAGS_ADDRESS
    // NTSC-U gold pickup table at 0x001deb10 contains these ten gadget IDs.
    // The pickup handler at 0x002e1ac0 writes one byte at 0x0013e520 + ID.
    switch (gadgetId) {
        case GADGET_ID_SUCK_CANNON:
        case GADGET_ID_BOMB_GLOVE:
        case GADGET_ID_DEVASTATOR:
        case GADGET_ID_BLASTER:
        case GADGET_ID_PYROCITOR:
        case GADGET_ID_MINE_GLOVE:
        case GADGET_ID_TESLA_CLAW:
        case GADGET_ID_GLOVE_OF_DOOM:
        case GADGET_ID_MORPH_O_RAY:
        case GADGET_ID_DECOY_GLOVE:
            ((volatile unsigned char *)GOLD_GADGET_FLAGS_ADDRESS)[gadgetId] = 1;
            return 1;
        default:
            return 0;
    }
#else
    // Unmapped builds must not write to an assumed game address.
    (void)gadgetId;
    return 0;
#endif
}

#ifdef GOLD_GADGET_FLAGS_ADDRESS
// The definition table lives in each level's data overlay, not core memory.
static rac1VariableAddressCompact_t vaGadgetDefs = {
	.MainMenu = 0,
#if defined(RAC1_NTSCU_V100)
	.Veldin1 = RAC1_VA_COMPACT_BASE(0x00179ac0),
	.Novalis = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x00179f40),
	.Aridia = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x0017a0c0),
	.Kerwan = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x00179bc0),
	.Eudora = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x00179c40),
	.Rilgar = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x00179f20),
	.NebulaG34 = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x0017a240),
	.Umbris = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x00179b40),
	.Batalia = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x0017a2c0),
	.Gaspar = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x00179c40),
	.Orxon = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x00179f40),
	.Pokitaru = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x0017a4c0),
	.Hoven = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x00179f40),
	.OltanisOrbit = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x00179dc0),
	.Oltanis = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x0017a1c0),
	.Quartu = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x0017a0c0),
	.Kalebo = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x00179f20),
	.VeldinOrbit = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x0017a3c0),
	.Veldin2 = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x0017a4c0),
#elif defined(RAC1_PAL_V100)
	.Veldin1 = RAC1_VA_COMPACT_BASE(0x00179ac0),
	.Novalis = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x00179ec0),
	.Aridia = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x0017a040),
	.Kerwan = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x00179b40),
	.Eudora = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x00179bc0),
	.Rilgar = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x00179f20),
	.NebulaG34 = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x0017a1c0),
	.Umbris = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x00179ac0),
	.Batalia = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x0017a240),
	.Gaspar = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x00179bc0),
	.Orxon = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x00179ec0),
	.Pokitaru = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x0017a440),
	.Hoven = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x00179ec0),
	.OltanisOrbit = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x00179d40),
	.Oltanis = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x0017a1c0),
	.Quartu = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x0017a040),
	.Kalebo = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x00179ea0),
	.VeldinOrbit = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x0017a340),
	.Veldin2 = RAC1_VA_COMPACT_OFFSET(0x00179ac0, 0x0017a440),
#elif defined(RAC1_PAL_V200)
	.Veldin1 = RAC1_VA_COMPACT_BASE(0x00179bc0),
	.Novalis = RAC1_VA_COMPACT_OFFSET(0x00179bc0, 0x00179fc0),
	.Aridia = RAC1_VA_COMPACT_OFFSET(0x00179bc0, 0x0017a140),
	.Kerwan = RAC1_VA_COMPACT_OFFSET(0x00179bc0, 0x00179c40),
	.Eudora = RAC1_VA_COMPACT_OFFSET(0x00179bc0, 0x00179cc0),
	.Rilgar = RAC1_VA_COMPACT_OFFSET(0x00179bc0, 0x0017a020),
	.NebulaG34 = RAC1_VA_COMPACT_OFFSET(0x00179bc0, 0x0017a340),
	.Umbris = RAC1_VA_COMPACT_OFFSET(0x00179bc0, 0x00179bc0),
	.Batalia = RAC1_VA_COMPACT_OFFSET(0x00179bc0, 0x0017a340),
	.Gaspar = RAC1_VA_COMPACT_OFFSET(0x00179bc0, 0x00179cc0),
	.Orxon = RAC1_VA_COMPACT_OFFSET(0x00179bc0, 0x00179fc0),
	.Pokitaru = RAC1_VA_COMPACT_OFFSET(0x00179bc0, 0x0017a540),
	.Hoven = RAC1_VA_COMPACT_OFFSET(0x00179bc0, 0x00179fc0),
	.OltanisOrbit = RAC1_VA_COMPACT_OFFSET(0x00179bc0, 0x00179e40),
	.Oltanis = RAC1_VA_COMPACT_OFFSET(0x00179bc0, 0x0017a2c0),
	.Quartu = RAC1_VA_COMPACT_OFFSET(0x00179bc0, 0x0017a140),
	.Kalebo = RAC1_VA_COMPACT_OFFSET(0x00179bc0, 0x00179fa0),
	.VeldinOrbit = RAC1_VA_COMPACT_OFFSET(0x00179bc0, 0x0017a440),
	.Veldin2 = RAC1_VA_COMPACT_OFFSET(0x00179bc0, 0x0017a540),
#elif defined(RAC1_NTSCJ_V100) || defined(RAC1_NTSCJ_V102)
	.Veldin1 = RAC1_VA_COMPACT_BASE(0x001799c0),
	.Novalis = RAC1_VA_COMPACT_OFFSET(0x001799c0, 0x00179dc0),
	.Aridia = RAC1_VA_COMPACT_OFFSET(0x001799c0, 0x00179f40),
	.Kerwan = RAC1_VA_COMPACT_OFFSET(0x001799c0, 0x00179a40),
	.Eudora = RAC1_VA_COMPACT_OFFSET(0x001799c0, 0x00179ac0),
	.Rilgar = RAC1_VA_COMPACT_OFFSET(0x001799c0, 0x00179e20),
	.NebulaG34 = RAC1_VA_COMPACT_OFFSET(0x001799c0, 0x0017a0c0),
	.Umbris = RAC1_VA_COMPACT_OFFSET(0x001799c0, 0x001799c0),
	.Batalia = RAC1_VA_COMPACT_OFFSET(0x001799c0, 0x0017a140),
	.Gaspar = RAC1_VA_COMPACT_OFFSET(0x001799c0, 0x00179ac0),
	.Orxon = RAC1_VA_COMPACT_OFFSET(0x001799c0, 0x00179dc0),
	.Pokitaru = RAC1_VA_COMPACT_OFFSET(0x001799c0, 0x0017a340),
	.Hoven = RAC1_VA_COMPACT_OFFSET(0x001799c0, 0x00179dc0),
	.OltanisOrbit = RAC1_VA_COMPACT_OFFSET(0x001799c0, 0x00179c40),
	.Oltanis = RAC1_VA_COMPACT_OFFSET(0x001799c0, 0x0017a0c0),
	.Quartu = RAC1_VA_COMPACT_OFFSET(0x001799c0, 0x00179f40),
	.Kalebo = RAC1_VA_COMPACT_OFFSET(0x001799c0, 0x00179da0),
	.VeldinOrbit = RAC1_VA_COMPACT_OFFSET(0x001799c0, 0x0017a240),
	.Veldin2 = RAC1_VA_COMPACT_OFFSET(0x001799c0, 0x0017a340),
#endif
};
#endif

GadgetDef *gadgetGetDef(eGADGET_IDS gadgetId)
{
#ifdef GOLD_GADGET_FLAGS_ADDRESS
    GadgetDef *defs;

    if ((unsigned int)gadgetId == 0 || (unsigned int)gadgetId >= GADGET_DEF_COUNT)
        return 0;

    defs = (GadgetDef *)GetAddress(&vaGadgetDefs);
    if (!defs)
        return 0;

    return &defs[gadgetId];
#else
    (void)gadgetId;
    return 0;
#endif
}
