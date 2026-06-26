#include <tamtypes.h>
#include "camera.h"
#include "types.h"
#include "interop.h"


#define CAMERA_START ((u32)GetAddress(&vaCamera_Start))
#define CAMERA_ROT  ((u32)GetAddress(&vaCamera_Start) + 0x150)
#define CAMERA_FLAG ((u32)GetAddress(&vaCamera_Start) + 0x53e3)

VariableAddress_t vaCamera_Start = {
#ifdef RAC1_PAL
    .Veldin1 = 0x00166c80,
    .Novalis = 0x00167080,
    .Aridia = 0x00167200,
    .Kerwan = 0x00166d00,
    .Eudora = 0x00166d80,
    .Rilgar = 0x00167080,
    .NebulaG34 = 0x00167380,
    .Umbris = 0x00166c80,
    .Batalia = 0x00167400,
    .Gaspar = 0x00166d80,
    .Orxon = 0x00167080,
    .Pokitaru = 0x00167600,
    .Hoven = 0x00167080,
    .OltanisOrbit = 0x00166f00,
    .Oltanis = 0x00167380,
    .Quartu = 0x00167200,
    .Kalebo = 0x00167000,
    .VeldinOrbit = 0x00167500,
    .Veldin2 = 0x00167600,
#elif RAC1_NTSCJ
    .Veldin1 = 0x00166d80,
    .Novalis = 0x00167180,
    .Aridia = 0x00167300,
    .Kerwan = 0x00166e00,
    .Eudora = 0x00166e80,
    .Rilgar = 0x00167180,
    .NebulaG34 = 0x00167480,
    .Umbris = 0x00166d80,
    .Batalia = 0x00167500,
    .Gaspar = 0x00166e80,
    .Orxon = 0x00167180,
    .Pokitaru = 0x00167700,
    .Hoven = 0x00167180,
    .OltanisOrbit = 0x00167000,
    .Oltanis = 0x00167480,
    .Quartu = 0x00167300,
    .Kalebo = 0x00167100,
    .VeldinOrbit = 0x00167600,
    .Veldin2 = 0x00167700,
#else
    .Veldin1 = 0x00166c80,
    .Novalis = 0x00167100,
    .Aridia = 0x00167280,
    .Kerwan = 0x00166d80,
    .Eudora = 0x00166e00,
    .Rilgar = 0x00167080,
    .NebulaG34 = 0x00167400,
    .Umbris = 0x00166d00,
    .Batalia = 0x00167480,
    .Gaspar = 0x00166e00,
    .Orxon = 0x00167100,
    .Pokitaru = 0x00167680,
    .Hoven = 0x00167100,
    .OltanisOrbit = 0x00166f80,
    .Oltanis = 0x00167380,
    .Quartu = 0x00167280,
    .Kalebo = 0x00167080,
    .VeldinOrbit = 0x00167580,
    .Veldin2 = 0x00167680,
#endif
};

u32 cameraGetStart(void)
{
    return CAMERA_START;
}

u32 cameraGetRot(void)
{
    return (u32)CAMERA_ROT;
}