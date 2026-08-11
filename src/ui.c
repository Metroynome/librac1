#include <tamtypes.h>
#include "interop.h"
#include "math.h"
#include "string.h"
#include "graphics.h"
#include "ui.h"

#define UI_FRAME_MOBY_MODEBIT_HIDDEN 0x0002

static int uiTextLength(const char *text)
{
    int length;

    if (!text) {
        return 0;
    }

    length = 0;
    while (text[length]) {
        length++;
    }

    return length;
}

static void uiDrawCustomText(UiElementBase_t *base, u32 modeFlags, const char *text, u32 color)
{
    int x;
    int y;
    int length;
    int font;
    void *fontTable;

    if (!base || !text) {
        return;
    }

    x = base->x;
    y = base->y;
    if (modeFlags & UI_FLAG_CENTER_H) {
        x += base->w / 2;
    }
    if (modeFlags & UI_FLAG_CENTER_V) {
        y += base->h / 2;
    }

    length = uiTextLength(text);
    font = FontSet(1);
    fontTable = (void *)0x001c35d0;
    if (modeFlags & UI_FLAG_CENTER_H) {
        FontPrintCenter(x, y, color, text, length);
    }
    else {
        FontPrint(x, y, color, text, length, font, fontTable);
    }
}

u64 uiElementTextCustomDraw(UiElementTextCustom_t *element)
{
    if (!element) {
        return 0;
    }

    uiDrawCustomText(&element->base, element->modeFlags, element->pText, element->color);
    return 0;
}

u64 uiElementDescriptionCustomDraw(UiElementDescriptionCustom_t *element)
{
    if (!element) {
        return 0;
    }

    uiDrawCustomText(&element->base, element->modeFlags, element->pText, element->color);
    return 0;
}
VariableAddress_t vaUiVTable_HandleExit = {
#ifdef RAC1_PAL_V200
    .MainMenu = 0x00000000,
    .Veldin1 = 0x002788e0,
    .Novalis = 0x0028e5c8,
    .Aridia = 0x00279d48,
    .Kerwan = 0x00267468,
    .Eudora = 0x0026bb40,
    .Rilgar = 0x002a2b90,
    .NebulaG34 = 0x00287640,
    .Umbris = 0x002a1230,
    .Batalia = 0x00282f58,
    .Gaspar = 0x00297600,
    .Orxon = 0x0026b710,
    .Pokitaru = 0x0029db88,
    .Hoven = 0x002914b8,
    .OltanisOrbit = 0x00284970,
    .Oltanis = 0x00281020,
    .Quartu = 0x002684c8,
    .Kalebo = 0x00273af0,
    .VeldinOrbit = 0x002729b8,
    .Veldin2 = 0x0027a7a8,
#elif RAC1_NTSCJ
    .MainMenu = 0x00000000,
    .Veldin1 = 0x00279838,
    .Novalis = 0x0028f518,
    .Aridia = 0x0027ac98,
    .Kerwan = 0x002683c0,
    .Eudora = 0x0026cb18,
    .Rilgar = 0x002a3ae0,
    .NebulaG34 = 0x00288518,
    .Umbris = 0x002a2188,
    .Batalia = 0x00283ea8,
    .Gaspar = 0x002985d8,
    .Orxon = 0x0026c668,
    .Pokitaru = 0x0029ead8,
    .Hoven = 0x00292488,
    .OltanisOrbit = 0x002858c8,
    .Oltanis = 0x00281f70,
    .Quartu = 0x00269420,
    .Kalebo = 0x00274ac0,
    .VeldinOrbit = 0x00273910,
    .Veldin2 = 0x0027b700,
#elif RAC1_PAL
    .MainMenu = 0x00000000,
    .Veldin1 = 0x00277358,
    .Novalis = 0x0028d0a0,
    .Aridia = 0x002787f8,
    .Kerwan = 0x00265f50,
    .Eudora = 0x0026a608,
    .Rilgar = 0x002a1648,
    .NebulaG34 = 0x002860b8,
    .Umbris = 0x0029fcf8,
    .Batalia = 0x00281a30,
    .Gaspar = 0x002960f8,
    .Orxon = 0x0026a1f8,
    .Pokitaru = 0x0029c668,
    .Hoven = 0x0028ff88,
    .OltanisOrbit = 0x00283458,
    .Oltanis = 0x0027faf0,
    .Quartu = 0x00266f88,
    .Kalebo = 0x002725b8,
    .VeldinOrbit = 0x00271388,
    .Veldin2 = 0x00279268,
#else
    .MainMenu = 0x00000000,
    .Veldin1 = 0x002779c8,
    .Novalis = 0x0028d788,
    .Aridia = 0x00278ee0,
    .Kerwan = 0x00266638,
    .Eudora = 0x0026acf8,
    .Rilgar = 0x002a1cd0,
    .NebulaG34 = 0x002867a8,
    .Umbris = 0x002a03e8,
    .Batalia = 0x00282118,
    .Gaspar = 0x002967e8,
    .Orxon = 0x0026a8e8,
    .Pokitaru = 0x0029cd50,
    .Hoven = 0x00290670,
    .OltanisOrbit = 0x00283b48,
    .Oltanis = 0x00280158,
    .Quartu = 0x00267670,
    .Kalebo = 0x00272cc0,
    .VeldinOrbit = 0x00271a78,
    .Veldin2 = 0x00279950,
#endif
};

VariableAddress_t vaUiVTable_Draw = {
#ifdef RAC1_PAL_V200
    .MainMenu = 0x00000000,
    .Veldin1 = 0x0027df78,
    .Novalis = 0x00293c60,
    .Aridia = 0x0027f3e0,
    .Kerwan = 0x0026cb00,
    .Eudora = 0x002711d8,
    .Rilgar = 0x002a8228,
    .NebulaG34 = 0x0028ccd8,
    .Umbris = 0x002a68c8,
    .Batalia = 0x002885f0,
    .Gaspar = 0x0029cc98,
    .Orxon = 0x00270da8,
    .Pokitaru = 0x002a3220,
    .Hoven = 0x00296b50,
    .OltanisOrbit = 0x0028a008,
    .Oltanis = 0x002866b8,
    .Quartu = 0x0026db60,
    .Kalebo = 0x00279188,
    .VeldinOrbit = 0x00278050,
    .Veldin2 = 0x0027fe40,
#elif RAC1_NTSCJ
    .MainMenu = 0x00000000,
    .Veldin1 = 0x0027ee00,
    .Novalis = 0x00294ae0,
    .Aridia = 0x00280260,
    .Kerwan = 0x0026d988,
    .Eudora = 0x002720e0,
    .Rilgar = 0x002a90a8,
    .NebulaG34 = 0x0028dae0,
    .Umbris = 0x002a7750,
    .Batalia = 0x00289470,
    .Gaspar = 0x0029dba0,
    .Orxon = 0x00271c30,
    .Pokitaru = 0x002a40a0,
    .Hoven = 0x00297a50,
    .OltanisOrbit = 0x0028ae90,
    .Oltanis = 0x00287538,
    .Quartu = 0x0026e9e8,
    .Kalebo = 0x0027a088,
    .VeldinOrbit = 0x00278ed8,
    .Veldin2 = 0x00280cc8,
#elif RAC1_PAL
    .MainMenu = 0x00219e20,
    .Veldin1 = 0x00277900,
    .Novalis = 0x0028d648,
    .Aridia = 0x00278da0,
    .Kerwan = 0x002664f8,
    .Eudora = 0x0026abb0,
    .Rilgar = 0x002a1bf0,
    .NebulaG34 = 0x00286660,
    .Umbris = 0x002a02a0,
    .Batalia = 0x00281fd8,
    .Gaspar = 0x002966a0,
    .Orxon = 0x0026a7a0,
    .Pokitaru = 0x0029cc10,
    .Hoven = 0x00290530,
    .OltanisOrbit = 0x00283a00,
    .Oltanis = 0x00280098,
    .Quartu = 0x00267530,
    .Kalebo = 0x00272b60,
    .VeldinOrbit = 0x00271930,
    .Veldin2 = 0x00279810,
#else
    .MainMenu = 0x0021a328,
    .Veldin1 = 0x00277f70,
    .Novalis = 0x0028dd30,
    .Aridia = 0x00279488,
    .Kerwan = 0x00266be0,
    .Eudora = 0x0026b2a0,
    .Rilgar = 0x002a2278,
    .NebulaG34 = 0x00286d50,
    .Umbris = 0x002a0990,
    .Batalia = 0x002826c0,
    .Gaspar = 0x00296d90,
    .Orxon = 0x0026ae90,
    .Pokitaru = 0x0029d2f8,
    .Hoven = 0x00290c18,
    .OltanisOrbit = 0x002840f0,
    .Oltanis = 0x00280700,
    .Quartu = 0x00267c18,
    .Kalebo = 0x00273268,
    .VeldinOrbit = 0x00272020,
    .Veldin2 = 0x00279ef8,
#endif
};

VariableAddress_t vaUiElementSelect_DrawList = {
#ifdef RAC1_PAL_V200
    .MainMenu = 0x00000000,
    .Veldin1 = 0x00279db8,
    .Novalis = 0x0028faa0,
    .Aridia = 0x0027b220,
    .Kerwan = 0x00268940,
    .Eudora = 0x0026d018,
    .Rilgar = 0x002a4068,
    .NebulaG34 = 0x00288b18,
    .Umbris = 0x002a2708,
    .Batalia = 0x00284430,
    .Gaspar = 0x00298ad8,
    .Orxon = 0x0026cbe8,
    .Pokitaru = 0x0029f060,
    .Hoven = 0x00292990,
    .OltanisOrbit = 0x00285e48,
    .Oltanis = 0x002824f8,
    .Quartu = 0x002699a0,
    .Kalebo = 0x00274fc8,
    .VeldinOrbit = 0x00273e90,
    .Veldin2 = 0x0027bc80,
#elif RAC1_NTSCJ
    .MainMenu = 0x00000000,
    .Veldin1 = 0x0027ace0,
    .Novalis = 0x002909c0,
    .Aridia = 0x0027c140,
    .Kerwan = 0x00269868,
    .Eudora = 0x0026dfc0,
    .Rilgar = 0x002a4f88,
    .NebulaG34 = 0x002899c0,
    .Umbris = 0x002a3630,
    .Batalia = 0x00285350,
    .Gaspar = 0x00299a80,
    .Orxon = 0x0026db10,
    .Pokitaru = 0x0029ff80,
    .Hoven = 0x00293930,
    .OltanisOrbit = 0x00286d70,
    .Oltanis = 0x00283418,
    .Quartu = 0x0026a8c8,
    .Kalebo = 0x00275f68,
    .VeldinOrbit = 0x00274db8,
    .Veldin2 = 0x0027cba8,
#elif RAC1_PAL
    .MainMenu = 0x0021acc0,
    .Veldin1 = 0x002787a0,
    .Novalis = 0x0028e4e8,
    .Aridia = 0x00279c40,
    .Kerwan = 0x00267398,
    .Eudora = 0x0026ba50,
    .Rilgar = 0x002a2a90,
    .NebulaG34 = 0x00287500,
    .Umbris = 0x002a1140,
    .Batalia = 0x00282e78,
    .Gaspar = 0x00297540,
    .Orxon = 0x0026b640,
    .Pokitaru = 0x0029dab0,
    .Hoven = 0x002913d0,
    .OltanisOrbit = 0x002848a0,
    .Oltanis = 0x00280f38,
    .Quartu = 0x002683d0,
    .Kalebo = 0x00273a00,
    .VeldinOrbit = 0x002727d0,
    .Veldin2 = 0x0027a6b0,
#else
    .MainMenu = 0x0021b1c8,
    .Veldin1 = 0x00278e10,
    .Novalis = 0x0028ebd0,
    .Aridia = 0x0027a328,
    .Kerwan = 0x00267a80,
    .Eudora = 0x0026c140,
    .Rilgar = 0x002a3118,
    .NebulaG34 = 0x00287bf0,
    .Umbris = 0x002a1830,
    .Batalia = 0x00283560,
    .Gaspar = 0x00297c30,
    .Orxon = 0x0026bd30,
    .Pokitaru = 0x0029e198,
    .Hoven = 0x00291ab8,
    .OltanisOrbit = 0x00284f90,
    .Oltanis = 0x002815a0,
    .Quartu = 0x00268ab8,
    .Kalebo = 0x00274108,
    .VeldinOrbit = 0x00272ec0,
    .Veldin2 = 0x0027ad98,
#endif
};

VariableAddress_t vaUiElementSelect_DrawWindowList = {
#ifdef RAC1_PAL_V200
    .MainMenu = 0x0021e4b0,
    .Veldin1 = 0x0027c0b8,
    .Novalis = 0x00291da0,
    .Aridia = 0x0027d520,
    .Kerwan = 0x0026ac40,
    .Eudora = 0x0026f318,
    .Rilgar = 0x002a6368,
    .NebulaG34 = 0x0028ae18,
    .Umbris = 0x002a4a08,
    .Batalia = 0x00286730,
    .Gaspar = 0x0029add8,
    .Orxon = 0x0026eee8,
    .Pokitaru = 0x002a1360,
    .Hoven = 0x00294c90,
    .OltanisOrbit = 0x00288148,
    .Oltanis = 0x002847f8,
    .Quartu = 0x0026bca0,
    .Kalebo = 0x002772c8,
    .VeldinOrbit = 0x00276190,
    .Veldin2 = 0x0027df80,
#elif RAC1_NTSCJ
    .MainMenu = 0x0021f310,
    .Veldin1 = 0x0027cf88,
    .Novalis = 0x00292c68,
    .Aridia = 0x0027e3e8,
    .Kerwan = 0x0026bb10,
    .Eudora = 0x00270268,
    .Rilgar = 0x002a7230,
    .NebulaG34 = 0x0028bc68,
    .Umbris = 0x002a58d8,
    .Batalia = 0x002875f8,
    .Gaspar = 0x0029bd28,
    .Orxon = 0x0026fdb8,
    .Pokitaru = 0x002a2228,
    .Hoven = 0x00295bd8,
    .OltanisOrbit = 0x00289018,
    .Oltanis = 0x002856c0,
    .Quartu = 0x0026cb70,
    .Kalebo = 0x00278210,
    .VeldinOrbit = 0x00277060,
    .Veldin2 = 0x0027ee50,
#elif RAC1_PAL
    .MainMenu = 0x0021cfa0,
    .Veldin1 = 0x0027aa80,
    .Novalis = 0x002907c8,
    .Aridia = 0x0027bf20,
    .Kerwan = 0x00269678,
    .Eudora = 0x0026dd30,
    .Rilgar = 0x002a4d70,
    .NebulaG34 = 0x002897e0,
    .Umbris = 0x002a3420,
    .Batalia = 0x00285158,
    .Gaspar = 0x00299820,
    .Orxon = 0x0026d920,
    .Pokitaru = 0x0029fd90,
    .Hoven = 0x002936b0,
    .OltanisOrbit = 0x00286b80,
    .Oltanis = 0x00283218,
    .Quartu = 0x0026a6b0,
    .Kalebo = 0x00275ce0,
    .VeldinOrbit = 0x00274ab0,
    .Veldin2 = 0x0027c990,
#else
    .MainMenu = 0x0021d4a8,
    .Veldin1 = 0x0027b0f0,
    .Novalis = 0x00290eb0,
    .Aridia = 0x0027c608,
    .Kerwan = 0x00269d60,
    .Eudora = 0x0026e420,
    .Rilgar = 0x002a53f8,
    .NebulaG34 = 0x00289ed0,
    .Umbris = 0x002a3b10,
    .Batalia = 0x00285840,
    .Gaspar = 0x00299f10,
    .Orxon = 0x0026e010,
    .Pokitaru = 0x002a0478,
    .Hoven = 0x00293d98,
    .OltanisOrbit = 0x00287270,
    .Oltanis = 0x00283880,
    .Quartu = 0x0026ad98,
    .Kalebo = 0x002763e8,
    .VeldinOrbit = 0x002751a0,
    .Veldin2 = 0x0027d078,
#endif
};

VariableAddress_t vaUiResourceElement_Init = {
#ifdef RAC1_PAL_V200
    .MainMenu = 0x0021e200,
    .Veldin1 = 0x0027be08,
    .Novalis = 0x00291af0,
    .Aridia = 0x0027d270,
    .Kerwan = 0x0026a990,
    .Eudora = 0x0026f068,
    .Rilgar = 0x002a60b8,
    .NebulaG34 = 0x0028ab68,
    .Umbris = 0x002a4758,
    .Batalia = 0x00286480,
    .Gaspar = 0x0029ab28,
    .Orxon = 0x0026ec38,
    .Pokitaru = 0x002a10b0,
    .Hoven = 0x002949e0,
    .OltanisOrbit = 0x00287e98,
    .Oltanis = 0x00284548,
    .Quartu = 0x0026b9f0,
    .Kalebo = 0x00277018,
    .VeldinOrbit = 0x00275ee0,
    .Veldin2 = 0x0027dcd0,
#elif RAC1_NTSCJ
    .MainMenu = 0x0021f060,
    .Veldin1 = 0x0027ccd8,
    .Novalis = 0x002929b8,
    .Aridia = 0x0027e138,
    .Kerwan = 0x0026b860,
    .Eudora = 0x0026ffb8,
    .Rilgar = 0x002a6f80,
    .NebulaG34 = 0x0028b9b8,
    .Umbris = 0x002a5628,
    .Batalia = 0x00287348,
    .Gaspar = 0x0029ba78,
    .Orxon = 0x0026fb08,
    .Pokitaru = 0x002a1f78,
    .Hoven = 0x00295928,
    .OltanisOrbit = 0x00288d68,
    .Oltanis = 0x00285410,
    .Quartu = 0x0026c8c0,
    .Kalebo = 0x00277f60,
    .VeldinOrbit = 0x00276db0,
    .Veldin2 = 0x0027eba0,
#elif RAC1_PAL
    .MainMenu = 0x0021ccf0,
    .Veldin1 = 0x0027a7d0,
    .Novalis = 0x00290518,
    .Aridia = 0x0027bc70,
    .Kerwan = 0x002693c8,
    .Eudora = 0x0026da80,
    .Rilgar = 0x002a4ac0,
    .NebulaG34 = 0x00289530,
    .Umbris = 0x002a3170,
    .Batalia = 0x00284ea8,
    .Gaspar = 0x00299570,
    .Orxon = 0x0026d670,
    .Pokitaru = 0x0029fae0,
    .Hoven = 0x00293400,
    .OltanisOrbit = 0x002868d0,
    .Oltanis = 0x00282f68,
    .Quartu = 0x0026a400,
    .Kalebo = 0x00275a30,
    .VeldinOrbit = 0x00274800,
    .Veldin2 = 0x0027c6e0,
#else
    .MainMenu = 0x0021d1f8,
    .Veldin1 = 0x0027ae40,
    .Novalis = 0x00290c00,
    .Aridia = 0x0027c358,
    .Kerwan = 0x00269ab0,
    .Eudora = 0x0026e170,
    .Rilgar = 0x002a5148,
    .NebulaG34 = 0x00289c20,
    .Umbris = 0x002a3860,
    .Batalia = 0x00285590,
    .Gaspar = 0x00299c60,
    .Orxon = 0x0026dd60,
    .Pokitaru = 0x002a01c8,
    .Hoven = 0x00293ae8,
    .OltanisOrbit = 0x00286fc0,
    .Oltanis = 0x002835d0,
    .Quartu = 0x0026aae8,
    .Kalebo = 0x00276138,
    .VeldinOrbit = 0x00274ef0,
    .Veldin2 = 0x0027cdc8,
#endif
};

VariableAddress_t vaUiResourceElement_Update = {
#ifdef RAC1_PAL_V200
    .MainMenu = 0x002209a0,
    .Veldin1 = 0x0027e5a8,
    .Novalis = 0x00294290,
    .Aridia = 0x0027fa10,
    .Kerwan = 0x0026d130,
    .Eudora = 0x00271808,
    .Rilgar = 0x002a8858,
    .NebulaG34 = 0x0028d308,
    .Umbris = 0x002a6ef8,
    .Batalia = 0x00288c20,
    .Gaspar = 0x0029d2c8,
    .Orxon = 0x002713d8,
    .Pokitaru = 0x002a3850,
    .Hoven = 0x00297180,
    .OltanisOrbit = 0x0028a638,
    .Oltanis = 0x00286ce8,
    .Quartu = 0x0026e190,
    .Kalebo = 0x002797b8,
    .VeldinOrbit = 0x00278680,
    .Veldin2 = 0x00280470,
#elif RAC1_NTSCJ
    .MainMenu = 0x002217b8,
    .Veldin1 = 0x0027f430,
    .Novalis = 0x00295110,
    .Aridia = 0x00280890,
    .Kerwan = 0x0026dfb8,
    .Eudora = 0x00272710,
    .Rilgar = 0x002a96d8,
    .NebulaG34 = 0x0028e110,
    .Umbris = 0x002a7d80,
    .Batalia = 0x00289aa0,
    .Gaspar = 0x0029e1d0,
    .Orxon = 0x00272260,
    .Pokitaru = 0x002a46d0,
    .Hoven = 0x00298080,
    .OltanisOrbit = 0x0028b4c0,
    .Oltanis = 0x00287b68,
    .Quartu = 0x0026f018,
    .Kalebo = 0x0027a6b8,
    .VeldinOrbit = 0x00279508,
    .Veldin2 = 0x002812f8,
#elif RAC1_PAL
    .MainMenu = 0x0021f490,
    .Veldin1 = 0x0027cf70,
    .Novalis = 0x00292cb8,
    .Aridia = 0x0027e410,
    .Kerwan = 0x0026bb68,
    .Eudora = 0x00270220,
    .Rilgar = 0x002a7260,
    .NebulaG34 = 0x0028bcd0,
    .Umbris = 0x002a5910,
    .Batalia = 0x00287648,
    .Gaspar = 0x0029bd10,
    .Orxon = 0x0026fe10,
    .Pokitaru = 0x002a2280,
    .Hoven = 0x00295ba0,
    .OltanisOrbit = 0x00289070,
    .Oltanis = 0x00285708,
    .Quartu = 0x0026cba0,
    .Kalebo = 0x002781d0,
    .VeldinOrbit = 0x00276fa0,
    .Veldin2 = 0x0027ee80,
#else
    .MainMenu = 0x0021f990,
    .Veldin1 = 0x0027d5d8,
    .Novalis = 0x00293398,
    .Aridia = 0x0027eaf0,
    .Kerwan = 0x0026c248,
    .Eudora = 0x00270908,
    .Rilgar = 0x002a78e0,
    .NebulaG34 = 0x0028c3b8,
    .Umbris = 0x002a5ff8,
    .Batalia = 0x00287d28,
    .Gaspar = 0x0029c3f8,
    .Orxon = 0x002704f8,
    .Pokitaru = 0x002a2960,
    .Hoven = 0x00296280,
    .OltanisOrbit = 0x00289758,
    .Oltanis = 0x00285d68,
    .Quartu = 0x0026d280,
    .Kalebo = 0x002788d0,
    .VeldinOrbit = 0x00277688,
    .Veldin2 = 0x0027f560,
#endif
};

VariableAddress_t vaUiVTable_DrawTexture = {
#ifdef RAC1_PAL_V200
    .MainMenu = 0x00221380,
    .Veldin1 = 0x0027ef88,
    .Novalis = 0x00294c70,
    .Aridia = 0x002803f0,
    .Kerwan = 0x0026db10,
    .Eudora = 0x002721e8,
    .Rilgar = 0x002a9238,
    .NebulaG34 = 0x0028dce8,
    .Umbris = 0x002a78d8,
    .Batalia = 0x00289600,
    .Gaspar = 0x0029dca8,
    .Orxon = 0x00271db8,
    .Pokitaru = 0x002a4230,
    .Hoven = 0x00297b60,
    .OltanisOrbit = 0x0028b018,
    .Oltanis = 0x002876c8,
    .Quartu = 0x0026eb70,
    .Kalebo = 0x0027a198,
    .VeldinOrbit = 0x00279060,
    .Veldin2 = 0x00280e50,
#elif RAC1_NTSCJ
    .MainMenu = 0x00222198,
    .Veldin1 = 0x0027fe10,
    .Novalis = 0x00295af0,
    .Aridia = 0x00281270,
    .Kerwan = 0x0026e998,
    .Eudora = 0x002730f0,
    .Rilgar = 0x002aa0b8,
    .NebulaG34 = 0x0028eaf0,
    .Umbris = 0x002a8760,
    .Batalia = 0x0028a480,
    .Gaspar = 0x0029ebb0,
    .Orxon = 0x00272c40,
    .Pokitaru = 0x002a50b0,
    .Hoven = 0x00298a60,
    .OltanisOrbit = 0x0028bea0,
    .Oltanis = 0x00288548,
    .Quartu = 0x0026f9f8,
    .Kalebo = 0x0027b098,
    .VeldinOrbit = 0x00279ee8,
    .Veldin2 = 0x00281cd8,
#elif RAC1_PAL
    .MainMenu = 0x0021fe48,
    .Veldin1 = 0x0027d928,
    .Novalis = 0x00293670,
    .Aridia = 0x0027edc8,
    .Kerwan = 0x0026c520,
    .Eudora = 0x00270bd8,
    .Rilgar = 0x002a7c18,
    .NebulaG34 = 0x0028c688,
    .Umbris = 0x002a62c8,
    .Batalia = 0x00288000,
    .Gaspar = 0x0029c6c8,
    .Orxon = 0x002707c8,
    .Pokitaru = 0x002a2c38,
    .Hoven = 0x00296558,
    .OltanisOrbit = 0x00289a28,
    .Oltanis = 0x002860c0,
    .Quartu = 0x0026d558,
    .Kalebo = 0x00278b88,
    .VeldinOrbit = 0x00277958,
    .Veldin2 = 0x0027f838,
#else
    .MainMenu = 0x00220348,
    .Veldin1 = 0x0027df90,
    .Novalis = 0x00293d50,
    .Aridia = 0x0027f4a8,
    .Kerwan = 0x0026cc00,
    .Eudora = 0x002712c0,
    .Rilgar = 0x002a8298,
    .NebulaG34 = 0x0028cd70,
    .Umbris = 0x002a69b0,
    .Batalia = 0x002886e0,
    .Gaspar = 0x0029cdb0,
    .Orxon = 0x00270eb0,
    .Pokitaru = 0x002a3318,
    .Hoven = 0x00296c38,
    .OltanisOrbit = 0x0028a110,
    .Oltanis = 0x00286720,
    .Quartu = 0x0026dc38,
    .Kalebo = 0x00279288,
    .VeldinOrbit = 0x00278040,
    .Veldin2 = 0x0027ff18,
#endif
};

VariableAddress_t vaUiVTable_OptionsInit = {
#ifdef RAC1_PAL_V200
    .MainMenu = 0x00220d08,
    .Veldin1 = 0x0027e910,
    .Novalis = 0x002945f8,
    .Aridia = 0x0027fd78,
    .Kerwan = 0x0026d498,
    .Eudora = 0x00271b70,
    .Rilgar = 0x002a8bc0,
    .NebulaG34 = 0x0028d670,
    .Umbris = 0x002a7260,
    .Batalia = 0x00288f88,
    .Gaspar = 0x0029d630,
    .Orxon = 0x00271740,
    .Pokitaru = 0x002a3bb8,
    .Hoven = 0x002974e8,
    .OltanisOrbit = 0x0028a9a0,
    .Oltanis = 0x00287050,
    .Quartu = 0x0026e4f8,
    .Kalebo = 0x00279b20,
    .VeldinOrbit = 0x002789e8,
    .Veldin2 = 0x002807d8,
#elif RAC1_NTSCJ
    .MainMenu = 0x00221b20,
    .Veldin1 = 0x0027f798,
    .Novalis = 0x00295478,
    .Aridia = 0x00280bf8,
    .Kerwan = 0x0026e320,
    .Eudora = 0x00272a78,
    .Rilgar = 0x002a9a40,
    .NebulaG34 = 0x0028e478,
    .Umbris = 0x002a80e8,
    .Batalia = 0x00289e08,
    .Gaspar = 0x0029e538,
    .Orxon = 0x002725c8,
    .Pokitaru = 0x002a4a38,
    .Hoven = 0x002983e8,
    .OltanisOrbit = 0x0028b828,
    .Oltanis = 0x00287ed0,
    .Quartu = 0x0026f380,
    .Kalebo = 0x0027aa20,
    .VeldinOrbit = 0x00279870,
    .Veldin2 = 0x00281660,
#elif RAC1_PAL
    .MainMenu = 0x0021f7e0,
    .Veldin1 = 0x0027d2c0,
    .Novalis = 0x00293008,
    .Aridia = 0x0027e760,
    .Kerwan = 0x0026beb8,
    .Eudora = 0x00270570,
    .Rilgar = 0x002a75b0,
    .NebulaG34 = 0x0028c020,
    .Umbris = 0x002a5c60,
    .Batalia = 0x00287998,
    .Gaspar = 0x0029c060,
    .Orxon = 0x00270160,
    .Pokitaru = 0x002a25d0,
    .Hoven = 0x00295ef0,
    .OltanisOrbit = 0x002893c0,
    .Oltanis = 0x00285a58,
    .Quartu = 0x0026cef0,
    .Kalebo = 0x00278520,
    .VeldinOrbit = 0x002772f0,
    .Veldin2 = 0x0027f1d0,
#else
    .MainMenu = 0x0021fce0,
    .Veldin1 = 0x0027d928,
    .Novalis = 0x002936e8,
    .Aridia = 0x0027ee40,
    .Kerwan = 0x0026c598,
    .Eudora = 0x00270c58,
    .Rilgar = 0x002a7c30,
    .NebulaG34 = 0x0028c708,
    .Umbris = 0x002a6348,
    .Batalia = 0x00288078,
    .Gaspar = 0x0029c748,
    .Orxon = 0x00270848,
    .Pokitaru = 0x002a2cb0,
    .Hoven = 0x002965d0,
    .OltanisOrbit = 0x00289aa8,
    .Oltanis = 0x002860b8,
    .Quartu = 0x0026d5d0,
    .Kalebo = 0x00278c20,
    .VeldinOrbit = 0x002779d8,
    .Veldin2 = 0x0027f8b0,
#endif
};

VariableAddress_t vaUiVTable_OptionsMenuShutdown = {
#ifdef RAC1_PAL_V200
    .MainMenu = 0x00220da0,
    .Veldin1 = 0x0027e9a8,
    .Novalis = 0x00294690,
    .Aridia = 0x0027fe10,
    .Kerwan = 0x0026d530,
    .Eudora = 0x00271c08,
    .Rilgar = 0x002a8c58,
    .NebulaG34 = 0x0028d708,
    .Umbris = 0x002a72f8,
    .Batalia = 0x00289020,
    .Gaspar = 0x0029d6c8,
    .Orxon = 0x002717d8,
    .Pokitaru = 0x002a3c50,
    .Hoven = 0x00297580,
    .OltanisOrbit = 0x0028aa38,
    .Oltanis = 0x002870e8,
    .Quartu = 0x0026e590,
    .Kalebo = 0x00279bb8,
    .VeldinOrbit = 0x00278a80,
    .Veldin2 = 0x00280870,
#elif RAC1_NTSCJ
    .MainMenu = 0x00221bb8,
    .Veldin1 = 0x0027f830,
    .Novalis = 0x00295510,
    .Aridia = 0x00280c90,
    .Kerwan = 0x0026e3b8,
    .Eudora = 0x00272b10,
    .Rilgar = 0x002a9ad8,
    .NebulaG34 = 0x0028e510,
    .Umbris = 0x002a8180,
    .Batalia = 0x00289ea0,
    .Gaspar = 0x0029e5d0,
    .Orxon = 0x00272660,
    .Pokitaru = 0x002a4ad0,
    .Hoven = 0x00298480,
    .OltanisOrbit = 0x0028b8c0,
    .Oltanis = 0x00287f68,
    .Quartu = 0x0026f418,
    .Kalebo = 0x0027aab8,
    .VeldinOrbit = 0x00279908,
    .Veldin2 = 0x002816f8,
#elif RAC1_PAL
    .MainMenu = 0x0021f878,
    .Veldin1 = 0x0027d358,
    .Novalis = 0x002930a0,
    .Aridia = 0x0027e7f8,
    .Kerwan = 0x0026bf50,
    .Eudora = 0x00270608,
    .Rilgar = 0x002a7648,
    .NebulaG34 = 0x0028c0b8,
    .Umbris = 0x002a5cf8,
    .Batalia = 0x00287a30,
    .Gaspar = 0x0029c0f8,
    .Orxon = 0x002701f8,
    .Pokitaru = 0x002a2668,
    .Hoven = 0x00295f88,
    .OltanisOrbit = 0x00289458,
    .Oltanis = 0x00285af0,
    .Quartu = 0x0026cf88,
    .Kalebo = 0x002785b8,
    .VeldinOrbit = 0x00277388,
    .Veldin2 = 0x0027f268,
#else
    .MainMenu = 0x0021fd78,
    .Veldin1 = 0x0027d9c0,
    .Novalis = 0x00293780,
    .Aridia = 0x0027eed8,
    .Kerwan = 0x0026c630,
    .Eudora = 0x00270cf0,
    .Rilgar = 0x002a7cc8,
    .NebulaG34 = 0x0028c7a0,
    .Umbris = 0x002a63e0,
    .Batalia = 0x00288110,
    .Gaspar = 0x0029c7e0,
    .Orxon = 0x002708e0,
    .Pokitaru = 0x002a2d48,
    .Hoven = 0x00296668,
    .OltanisOrbit = 0x00289b40,
    .Oltanis = 0x00286150,
    .Quartu = 0x0026d668,
    .Kalebo = 0x00278cb8,
    .VeldinOrbit = 0x00277a70,
    .Veldin2 = 0x0027f948,
#endif
};

VariableAddress_t vaUiVTable_UpdateState = {
#ifdef RAC1_PAL_V200
    .MainMenu = 0x00220df0,
    .Veldin1 = 0x0027e9f8,
    .Novalis = 0x002946e0,
    .Aridia = 0x0027fe60,
    .Kerwan = 0x0026d580,
    .Eudora = 0x00271c58,
    .Rilgar = 0x002a8ca8,
    .NebulaG34 = 0x0028d758,
    .Umbris = 0x002a7348,
    .Batalia = 0x00289070,
    .Gaspar = 0x0029d718,
    .Orxon = 0x00271828,
    .Pokitaru = 0x002a3ca0,
    .Hoven = 0x002975d0,
    .OltanisOrbit = 0x0028aa88,
    .Oltanis = 0x00287138,
    .Quartu = 0x0026e5e0,
    .Kalebo = 0x00279c08,
    .VeldinOrbit = 0x00278ad0,
    .Veldin2 = 0x002808c0,
#elif RAC1_NTSCJ
    .MainMenu = 0x00221c08,
    .Veldin1 = 0x0027f880,
    .Novalis = 0x00295560,
    .Aridia = 0x00280ce0,
    .Kerwan = 0x0026e408,
    .Eudora = 0x00272b60,
    .Rilgar = 0x002a9b28,
    .NebulaG34 = 0x0028e560,
    .Umbris = 0x002a81d0,
    .Batalia = 0x00289ef0,
    .Gaspar = 0x0029e620,
    .Orxon = 0x002726b0,
    .Pokitaru = 0x002a4b20,
    .Hoven = 0x002984d0,
    .OltanisOrbit = 0x0028b910,
    .Oltanis = 0x00287fb8,
    .Quartu = 0x0026f468,
    .Kalebo = 0x0027ab08,
    .VeldinOrbit = 0x00279958,
    .Veldin2 = 0x00281748,
#elif RAC1_PAL
    .MainMenu = 0x0021f8c8,
    .Veldin1 = 0x0027d3a8,
    .Novalis = 0x002930f0,
    .Aridia = 0x0027e848,
    .Kerwan = 0x0026bfa0,
    .Eudora = 0x00270658,
    .Rilgar = 0x002a7698,
    .NebulaG34 = 0x0028c108,
    .Umbris = 0x002a5d48,
    .Batalia = 0x00287a80,
    .Gaspar = 0x0029c148,
    .Orxon = 0x00270248,
    .Pokitaru = 0x002a26b8,
    .Hoven = 0x00295fd8,
    .OltanisOrbit = 0x002894a8,
    .Oltanis = 0x00285b40,
    .Quartu = 0x0026cfd8,
    .Kalebo = 0x00278608,
    .VeldinOrbit = 0x002773d8,
    .Veldin2 = 0x0027f2b8,
#else
    .MainMenu = 0x0021fdc8,
    .Veldin1 = 0x0027da10,
    .Novalis = 0x002937d0,
    .Aridia = 0x0027ef28,
    .Kerwan = 0x0026c680,
    .Eudora = 0x00270d40,
    .Rilgar = 0x002a7d18,
    .NebulaG34 = 0x0028c7f0,
    .Umbris = 0x002a6430,
    .Batalia = 0x00288160,
    .Gaspar = 0x0029c830,
    .Orxon = 0x00270930,
    .Pokitaru = 0x002a2d98,
    .Hoven = 0x002966b8,
    .OltanisOrbit = 0x00289b90,
    .Oltanis = 0x002861a0,
    .Quartu = 0x0026d6b8,
    .Kalebo = 0x00278d08,
    .VeldinOrbit = 0x00277ac0,
    .Veldin2 = 0x0027f998,
#endif
};


static int uiFrameSlotIsValid(int slot)
{
    return slot >= 0 && slot < UI_MENU_MAX_ELEMENTS;
}

static void uiCopyVector(VECTOR output, const VECTOR input)
{
    output[0] = input[0];
    output[1] = input[1];
    output[2] = input[2];
    output[3] = input[3];
}

static float uiVectorDistance3(const VECTOR a, const VECTOR b)
{
    float x;
    float y;
    float z;

    x = b[0] - a[0];
    y = b[1] - a[1];
    z = b[2] - a[2];
    return sqrtf((x * x) + (y * y) + (z * z));
}

static void uiFramePvarSetRectFromCorners(M1138_MenuItem_Pvar_t *frame, const VECTOR topLeft, const VECTOR topRight, const VECTOR bottomLeft)
{
    int x;
    int y;
    int w;
    int h;

    if (!frame) {
        return;
    }

    x = (int)topLeft[0];
    y = (int)topLeft[1];
    w = (int)fabsf(topRight[0] - topLeft[0]);
    h = (int)fabsf(bottomLeft[1] - topLeft[1]);

    uiFramePvarSetScreenRect(frame, x, y, w, h);
}

static void uiElementSetBoundsFromFrame(UiElementBase_t *element, M1138_MenuItem_Pvar_t *frame)
{
    if (!element || !frame) {
        return;
    }

    element->x = frame->x;
    element->y = frame->y;
    element->w = frame->w;
    element->h = frame->h;
}

void uiFramePvarSetScreenRect(M1138_MenuItem_Pvar_t *frame, int x, int y, int w, int h)
{
    if (!frame) {
        return;
    }

    frame->x = x;
    frame->y = y;
    frame->w = w;
    frame->h = h;
}

void uiFramePvarSetCorners2D(M1138_MenuItem_Pvar_t *frame, float x, float y, float z, float w, float h)
{
    if (!frame) {
        return;
    }

    frame->point[0][0] = x;
    frame->point[0][1] = y;
    frame->point[0][2] = z;
    frame->point[0][3] = 1.0f;

    frame->point[1][0] = x + w;
    frame->point[1][1] = y;
    frame->point[1][2] = z;
    frame->point[1][3] = 1.0f;

    frame->point[2][0] = x;
    frame->point[2][1] = y + h;
    frame->point[2][2] = z;
    frame->point[2][3] = 1.0f;

    frame->point[3][0] = x + w;
    frame->point[3][1] = y + h;
    frame->point[3][2] = z;
    frame->point[3][3] = 1.0f;

    frame->worldWidth = fabsf(w);
    frame->worldHeight = fabsf(h);
    frame->unk_48 = 0;
    frame->unk_4c = 0;

    uiFramePvarSetScreenRect(frame, (int)x, (int)y, (int)w, (int)h);
}

void uiFramePvarSetCorners(M1138_MenuItem_Pvar_t *frame, const VECTOR topLeft, const VECTOR topRight, const VECTOR bottomLeft, const VECTOR bottomRight)
{
    if (!frame) {
        return;
    }

    uiCopyVector(frame->point[0], topLeft);
    uiCopyVector(frame->point[1], topRight);
    uiCopyVector(frame->point[2], bottomLeft);
    uiCopyVector(frame->point[3], bottomRight);

    frame->worldWidth = uiVectorDistance3(topLeft, topRight);
    frame->worldHeight = uiVectorDistance3(topLeft, bottomLeft);
    frame->unk_48 = 0;
    frame->unk_4c = 0;
    uiFramePvarSetRectFromCorners(frame, topLeft, topRight, bottomLeft);
}

void uiFrameMobyAttach(Moby *moby, M1138_MenuItem_Pvar_t *frame)
{
    if (!moby || !frame) {
        return;
    }

    moby->pVar = frame;
    moby->modeBits &= ~UI_FRAME_MOBY_MODEBIT_HIDDEN;
}

void uiFrameMobyUseCustomPoints(Moby *moby, M1138_MenuItem_Pvar_t *frame)
{
    if (!moby || !frame) {
        return;
    }

    uiFrameMobyAttach(moby, frame);

    // The stock frame updater rebuilds pVar points from animation every frame.
    // Clear it when caller-owned points should be rendered directly.
    moby->pUpdate = 0;
    moby->animSpeed = 0.0f;
}

Moby *uiMenuGetFrameMoby(int slot)
{
    if (!uiFrameSlotIsValid(slot)) {
        return 0;
    }

    return UI_GLOBALS.uiMobys[slot];
}

int uiMenuSetFrameAnim(UiMenu_t *menu, int slot, int animId)
{
    if (!menu || !uiFrameSlotIsValid(slot)) {
        return 0;
    }

    menu->mobyAnimIds[slot] = animId;
    return 1;
}

int uiMenuSetElement(UiMenu_t *menu, int slot, UiElementBase_t *element)
{
    Moby *moby;

    if (!menu || !uiFrameSlotIsValid(slot)) {
        return 0;
    }

    moby = uiMenuGetFrameMoby(slot);
    menu->pElements[slot] = element;

    if (element) {
        element->pMoby = moby;
    }

    return 1;
}

int uiMenuBindFrameSlot(UiMenu_t *menu, int slot, UiElementBase_t *element, M1138_MenuItem_Pvar_t *frame)
{
    Moby *moby;

    if (!frame || !uiMenuSetElement(menu, slot, element)) {
        return 0;
    }

    moby = uiMenuGetFrameMoby(slot);
    if (!moby) {
        return 0;
    }

    uiFrameMobyUseCustomPoints(moby, frame);
    return 1;
}

void uiMenuInit(UiMenu_t *menu, UiMenu_t *parent, int menuId)
{
    if (!menu) {
        return;
    }

    memset(menu, 0, sizeof(UiMenu_t));
    menu->pParent = parent;
    menu->menuId = menuId;
}

void uiMenuOpen(UiMenu_t *menu)
{
    if (!menu) {
        return;
    }

    UI_GLOBALS.pChangeToMenu = menu;
}
void uiCreateBase(UiElementBase_t *element, M1138_MenuItem_Pvar_t *frame, const VECTOR topLeft, const VECTOR topRight, const VECTOR bottomLeft, const VECTOR bottomRight)
{
    if (!element || !frame) {
        return;
    }

    uiFramePvarSetCorners(frame, topLeft, topRight, bottomLeft, bottomRight);
    element->pUpdate = 0;
    element->pDraw = 0;
    element->pInit = 0;
    element->pUninit = 0;
    element->renderFlags = 0;
    element->pMoby = 0;
    element->unk_28 = 0;
    element->unk_2c = 0;
    uiElementSetBoundsFromFrame(element, frame);
}

void uiCreateText(UiElementText_t *element, M1138_MenuItem_Pvar_t *frame, const VECTOR topLeft, const VECTOR topRight, const VECTOR bottomLeft, const VECTOR bottomRight, u32 modeFlags, int stringId)
{
    if (!element) {
        return;
    }

    uiCreateBase(&element->base, frame, topLeft, topRight, bottomLeft, bottomRight);
    element->base.pUpdate = (void *)uiVTableHandleExit;
    element->base.pDraw = (void *)uiVTableDraw;
    element->modeFlags = modeFlags;
    element->stringId = stringId;
    element->entryStride = 0;
    element->scrollOffset = 0;
    element->selectedIndex = 0;
    element->uptime = 0;
    element->currentStringId = stringId;
    element->currentMsgFlags = 0;
}

void uiCreateTitle(UiElementText_t *element, M1138_MenuItem_Pvar_t *frame, const VECTOR topLeft, const VECTOR topRight, const VECTOR bottomLeft, const VECTOR bottomRight, int stringId)
{
    uiCreateText(element, frame, topLeft, topRight, bottomLeft, bottomRight, UI_FLAG_CENTER_H | UI_FLAG_CENTER_V, stringId);
}

void uiCreateDescription(UiElementDescriptionText_t *element, M1138_MenuItem_Pvar_t *frame, const VECTOR topLeft, const VECTOR topRight, const VECTOR bottomLeft, const VECTOR bottomRight, u32 modeFlags, int *descriptionStringId)
{
    if (!element) {
        return;
    }

    uiCreateBase(&element->base, frame, topLeft, topRight, bottomLeft, bottomRight);
    element->base.pUpdate = (void *)uiVTableHandleExit;
    element->base.pDraw = (void *)uiVTableDraw;
    element->modeFlags = modeFlags;
    element->pDescriptionStringId = descriptionStringId;
    element->entryStride = 0;
    element->scrollOffset = 0;
    element->selectedIndex = 0;
    element->uptime = 0;
    element->currentStringId = descriptionStringId ? *descriptionStringId : 0;
    element->currentMsgFlags = 0;
}


void uiCreateTextCustom(UiElementTextCustom_t *element, M1138_MenuItem_Pvar_t *frame, const VECTOR topLeft, const VECTOR topRight, const VECTOR bottomLeft, const VECTOR bottomRight, u32 modeFlags, const char *pText)
{
    if (!element) {
        return;
    }

    uiCreateBase(&element->base, frame, topLeft, topRight, bottomLeft, bottomRight);
    element->base.pUpdate = (void *)uiVTableHandleExit;
    element->base.pDraw = (void *)uiElementTextCustomDraw;
    element->base.renderFlags = 0;
    element->modeFlags = modeFlags;
    element->pText = pText;
    element->color = UI_CUSTOM_TEXT_DEFAULT_COLOR;
    element->pad_3c = 0;
}

void uiCreateTitleCustom(UiElementTextCustom_t *element, M1138_MenuItem_Pvar_t *frame, const VECTOR topLeft, const VECTOR topRight, const VECTOR bottomLeft, const VECTOR bottomRight, const char *pText)
{
    uiCreateTextCustom(element, frame, topLeft, topRight, bottomLeft, bottomRight, UI_FLAG_CENTER_H | UI_FLAG_CENTER_V, pText);
}

void uiCreateDescriptionCustom(UiElementDescriptionCustom_t *element, M1138_MenuItem_Pvar_t *frame, const VECTOR topLeft, const VECTOR topRight, const VECTOR bottomLeft, const VECTOR bottomRight, u32 modeFlags, const char *pText)
{
    if (!element) {
        return;
    }

    uiCreateBase(&element->base, frame, topLeft, topRight, bottomLeft, bottomRight);
    element->base.pUpdate = (void *)uiVTableHandleExit;
    element->base.pDraw = (void *)uiElementDescriptionCustomDraw;
    element->base.renderFlags = 0;
    element->modeFlags = modeFlags;
    element->pText = pText;
    element->color = UI_CUSTOM_TEXT_DEFAULT_COLOR;
    element->pad_3c = 0;
}
void uiCreateFrame(UiElementFrame_t *element, M1138_MenuItem_Pvar_t *frame, const VECTOR topLeft, const VECTOR topRight, const VECTOR bottomLeft, const VECTOR bottomRight, u32 modeFlags, UiFrameTableEntry_t *frameTable, int frameWidth, int frameHeight, int *frameIndex)
{
    if (!element) {
        return;
    }

    uiCreateBase(&element->header.base, frame, topLeft, topRight, bottomLeft, bottomRight);
    element->header.base.pUpdate = (void *)uiVTableUpdateState;
    element->header.base.pDraw = (void *)uiVTableDrawTexture;
    element->header.base.pInit = (void *)uiVTableOptionsInit;
    element->header.base.pUninit = (void *)uiVTableOptionsMenuShutdown;
    element->header.pFrameTable = frameTable;
    element->header.modeFlags = modeFlags;
    element->header.frameWidth = frameWidth;
    element->header.frameHeight = frameHeight;
    element->header.pFrameIndex = frameIndex;
    element->header.state = -1;
    element->header.pBufferA = 0;
    element->header.pBufferB = 0;
    element->committedFrameA = -1;
    element->committedFrameB = -1;
    element->forcedFrame = -1;
    element->callCount = 0;
    element->loadOffsetAdjust = 0;
    element->pad_64 = 0;
}
void uiCreateSelectList(UiElementList_t *element, M1138_MenuItem_Pvar_t *frame, const VECTOR topLeft, const VECTOR topRight, const VECTOR bottomLeft, const VECTOR bottomRight, u32 modeFlags, UiOptionEntry_t *entries, UiElementBase_t *previousElement, UiElementBase_t *nextElement, int selectedIndex)
{
    if (!element) {
        return;
    }

    uiCreateBase(&element->base, frame, topLeft, topRight, bottomLeft, bottomRight);
    element->base.pUpdate = (void *)uiVTableHandleExit;
    element->base.pDraw = (void *)uiElementSelectDrawList;
    element->modeFlags = modeFlags;
    element->pEntries = entries;
    element->pPreviousElement = previousElement;
    element->pNextElement = nextElement;
    element->selectedIndex = selectedIndex;
}

void uiCreateMenuOption(UiElementMenuOption_t *element, M1138_MenuItem_Pvar_t *frame, const VECTOR topLeft, const VECTOR topRight, const VECTOR bottomLeft, const VECTOR bottomRight, u32 modeFlags, UiMenuOption_t *option, UiElementMenuOption_t *previousElement, UiElementMenuOption_t *nextElement, int selectedIndex)
{
    if (!element) {
        return;
    }

    uiCreateBase(&element->base, frame, topLeft, topRight, bottomLeft, bottomRight);
    element->base.pUpdate = (void *)uiVTableHandleExit;
    element->base.pDraw = (void *)uiVTableDraw;
    element->modeFlags = modeFlags;
    element->pOption = option;
    element->pPreviousElement = previousElement;
    element->pNextElement = nextElement;
    element->selectedIndex = selectedIndex;
}
void uiCreateFooter(UiElementFooter_t *element, M1138_MenuItem_Pvar_t *frame, const VECTOR topLeft, const VECTOR topRight, const VECTOR bottomLeft, const VECTOR bottomRight, u32 modeFlags, UiOptionEntry_t *entries, UiElementBase_t *previousElement, UiElementBase_t *nextElement, int selectedIndex)
{
    if (!element) {
        return;
    }

    uiCreateBase(&element->base, frame, topLeft, topRight, bottomLeft, bottomRight);
    element->base.pUpdate = (void *)uiVTableHandleExit;
    element->base.pDraw = (void *)uiElementSelectDrawList;
    element->modeFlags = modeFlags;
    element->pEntries = entries;
    element->pPreviousElement = previousElement;
    element->pNextElement = nextElement;
    element->selectedIndex = selectedIndex;
}

