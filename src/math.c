#include "math.h"
#include "interop.h"

VariableAddress_t vaFastAngleCosF = {
#ifdef RAC1_PAL_V200
	.Veldin1 = 0x001ff7b0,
	.Novalis = 0x00221640,
	.Aridia = 0x00210798,
	.Kerwan = 0x001f90c8,
	.Eudora = 0x001f2198,
	.Rilgar = 0x0022e498,
	.NebulaG34 = 0x00217850,
	.Umbris = 0x00227598,
	.Batalia = 0x002122b0,
	.Gaspar = 0x0021f390,
	.Orxon = 0x001f2d98,
	.Pokitaru = 0x00231098,
	.Hoven = 0x00222640,
	.OltanisOrbit = 0x0020b218,
	.Oltanis = 0x00212dc0,
	.Quartu = 0x001f8ea8,
	.Kalebo = 0x001fdf98,
	.VeldinOrbit = 0x001fc8d8,
	.Veldin2 = 0x00208518,
#elif RAC1_PAL
	.Veldin1 = 0x001ff3b0,
	.Novalis = 0x00221240,
	.Aridia = 0x00210398,
	.Kerwan = 0x001f8cc8,
	.Eudora = 0x001f1d98,
	.Rilgar = 0x0022e098,
	.NebulaG34 = 0x002173d0,
	.Umbris = 0x00227198,
	.Batalia = 0x00211eb0,
	.Gaspar = 0x0021f010,
	.Orxon = 0x001f2998,
	.Pokitaru = 0x00230c98,
	.Hoven = 0x00222240,
	.OltanisOrbit = 0x0020ae18,
	.Oltanis = 0x002129c0,
	.Quartu = 0x001f8aa8,
	.Kalebo = 0x001fdb98,
	.VeldinOrbit = 0x001fc3d8,
	.Veldin2 = 0x00208118,
#elif RAC1_NTSCJ
	.Veldin1 = 0x00200700,
	.Novalis = 0x00222590,
	.Aridia = 0x002116e8,
	.Kerwan = 0x001fa018,
	.Eudora = 0x001f3168,
	.Rilgar = 0x0022f3e8,
	.NebulaG34 = 0x00218720,
	.Umbris = 0x002284e8,
	.Batalia = 0x00213200,
	.Gaspar = 0x00220360,
	.Orxon = 0x001f3ce8,
	.Pokitaru = 0x00231fe8,
	.Hoven = 0x00223610,
	.OltanisOrbit = 0x0020c168,
	.Oltanis = 0x00213d10,
	.Quartu = 0x001f9df8,
	.Kalebo = 0x001fef68,
	.VeldinOrbit = 0x001fd828,
	.Veldin2 = 0x00209468,
#else
	.Veldin1 = 0x001ff800,
	.Novalis = 0x00221710,
	.Aridia = 0x00210868,
	.Kerwan = 0x001f9198,
	.Eudora = 0x001f2268,
	.Rilgar = 0x0022e4e8,
	.NebulaG34 = 0x002178a0,
	.Umbris = 0x00227668,
	.Batalia = 0x00212380,
	.Gaspar = 0x0021f4e0,
	.Orxon = 0x001f2e68,
	.Pokitaru = 0x00231168,
	.Hoven = 0x00222710,
	.OltanisOrbit = 0x0020b2e8,
	.Oltanis = 0x00212e10,
	.Quartu = 0x001f8f78,
	.Kalebo = 0x001fe068,
	.VeldinOrbit = 0x001fc8a8,
	.Veldin2 = 0x002085e8,
#endif
};

VariableAddress_t vaATAN2F = {
#ifdef RAC1_PAL_V200
	.Veldin1 = 0x001ff860,
	.Novalis = 0x002216f0,
	.Aridia = 0x00210848,
	.Kerwan = 0x001f9178,
	.Eudora = 0x001f2248,
	.Rilgar = 0x0022e548,
	.NebulaG34 = 0x00217900,
	.Umbris = 0x00227648,
	.Batalia = 0x00212360,
	.Gaspar = 0x0021f440,
	.Orxon = 0x001f2e48,
	.Pokitaru = 0x00231148,
	.Hoven = 0x002226f0,
	.OltanisOrbit = 0x0020b2c8,
	.Oltanis = 0x00212e70,
	.Quartu = 0x001f8f58,
	.Kalebo = 0x001fe048,
	.VeldinOrbit = 0x001fc988,
	.Veldin2 = 0x002085c8,
#elif RAC1_PAL
	.Veldin1 = 0x001ff460,
	.Novalis = 0x002212f0,
	.Aridia = 0x00210448,
	.Kerwan = 0x001f8d78,
	.Eudora = 0x001f1e48,
	.Rilgar = 0x0022e148,
	.NebulaG34 = 0x00217480,
	.Umbris = 0x00227248,
	.Batalia = 0x00211f60,
	.Gaspar = 0x0021f0c0,
	.Orxon = 0x001f2a48,
	.Pokitaru = 0x00230d48,
	.Hoven = 0x002222f0,
	.OltanisOrbit = 0x0020aec8,
	.Oltanis = 0x00212a70,
	.Quartu = 0x001f8b58,
	.Kalebo = 0x001fdc48,
	.VeldinOrbit = 0x001fc488,
	.Veldin2 = 0x002081c8,
#elif RAC1_NTSCJ
	.Veldin1 = 0x002007b0,
	.Novalis = 0x00222640,
	.Aridia = 0x00211798,
	.Kerwan = 0x001fa0c8,
	.Eudora = 0x001f3218,
	.Rilgar = 0x0022f498,
	.NebulaG34 = 0x002187d0,
	.Umbris = 0x00228598,
	.Batalia = 0x002132b0,
	.Gaspar = 0x00220410,
	.Orxon = 0x001f3d98,
	.Pokitaru = 0x00232098,
	.Hoven = 0x002236c0,
	.OltanisOrbit = 0x0020c218,
	.Oltanis = 0x00213dc0,
	.Quartu = 0x001f9ea8,
	.Kalebo = 0x001ff018,
	.VeldinOrbit = 0x001fd8d8,
	.Veldin2 = 0x00209518,
#else
	.Veldin1 = 0x001ff8b0,
	.Novalis = 0x002217c0,
	.Aridia = 0x00210918,
	.Kerwan = 0x001f9248,
	.Eudora = 0x001f2318,
	.Rilgar = 0x0022e598,
	.NebulaG34 = 0x00217950,
	.Umbris = 0x00227718,
	.Batalia = 0x00212430,
	.Gaspar = 0x0021f590,
	.Orxon = 0x001f2f18,
	.Pokitaru = 0x00231218,
	.Hoven = 0x002227c0,
	.OltanisOrbit = 0x0020b398,
	.Oltanis = 0x00212ec0,
	.Quartu = 0x001f9028,
	.Kalebo = 0x001fe118,
	.VeldinOrbit = 0x001fc958,
	.Veldin2 = 0x00208698,
#endif
};

VariableAddress_t vaFastAngleSinF = {
#ifdef RAC1_PAL_V200
	.Veldin1 = 0x001ff798,
	.Novalis = 0x00221628,
	.Aridia = 0x00210780,
	.Kerwan = 0x001f90b0,
	.Eudora = 0x001f2180,
	.Rilgar = 0x0022e480,
	.NebulaG34 = 0x00217838,
	.Umbris = 0x00227580,
	.Batalia = 0x00212298,
	.Gaspar = 0x0021f378,
	.Orxon = 0x001f2d80,
	.Pokitaru = 0x00231080,
	.Hoven = 0x00222628,
	.OltanisOrbit = 0x0020b200,
	.Oltanis = 0x00212da8,
	.Quartu = 0x001f8e90,
	.Kalebo = 0x001fdf80,
	.VeldinOrbit = 0x001fc8c0,
	.Veldin2 = 0x00208500,
#elif RAC1_PAL
	.Veldin1 = 0x001ff398,
	.Novalis = 0x00221228,
	.Aridia = 0x00210380,
	.Kerwan = 0x001f8cb0,
	.Eudora = 0x001f1d80,
	.Rilgar = 0x0022e080,
	.NebulaG34 = 0x002173b8,
	.Umbris = 0x00227180,
	.Batalia = 0x00211e98,
	.Gaspar = 0x0021eff8,
	.Orxon = 0x001f2980,
	.Pokitaru = 0x00230c80,
	.Hoven = 0x00222228,
	.OltanisOrbit = 0x0020ae00,
	.Oltanis = 0x002129a8,
	.Quartu = 0x001f8a90,
	.Kalebo = 0x001fdb80,
	.VeldinOrbit = 0x001fc3c0,
	.Veldin2 = 0x00208100,
#elif RAC1_NTSCJ
	.Veldin1 = 0x002006e8,
	.Novalis = 0x00222578,
	.Aridia = 0x002116d0,
	.Kerwan = 0x001fa000,
	.Eudora = 0x001f3150,
	.Rilgar = 0x0022f3d0,
	.NebulaG34 = 0x00218708,
	.Umbris = 0x002284d0,
	.Batalia = 0x002131e8,
	.Gaspar = 0x00220348,
	.Orxon = 0x001f3cd0,
	.Pokitaru = 0x00231fd0,
	.Hoven = 0x002235f8,
	.OltanisOrbit = 0x0020c150,
	.Oltanis = 0x00213cf8,
	.Quartu = 0x001f9de0,
	.Kalebo = 0x001fef50,
	.VeldinOrbit = 0x001fd810,
	.Veldin2 = 0x00209450,
#else
	.Veldin1 = 0x001ff7e8,
	.Novalis = 0x002216f8,
	.Aridia = 0x00210850,
	.Kerwan = 0x001f9180,
	.Eudora = 0x001f2250,
	.Rilgar = 0x0022e4d0,
	.NebulaG34 = 0x00217888,
	.Umbris = 0x00227650,
	.Batalia = 0x00212368,
	.Gaspar = 0x0021f4c8,
	.Orxon = 0x001f2e50,
	.Pokitaru = 0x00231150,
	.Hoven = 0x002226f8,
	.OltanisOrbit = 0x0020b2d0,
	.Oltanis = 0x00212df8,
	.Quartu = 0x001f8f60,
	.Kalebo = 0x001fe050,
	.VeldinOrbit = 0x001fc890,
	.Veldin2 = 0x002085d0,
#endif
};


//--------------------------------------------------------
float sinf(float x)
{
    // normalize to [-PI, PI]
    while (x >  MATH_PI) x -= MATH_TAU;
    while (x < -MATH_PI) x += MATH_TAU;

    float x2 = x * x;
    return x - (x  * x2) / 6.0f + (x  * x2 * x2) / 120.0f - (x  * x2 * x2 * x2) / 5040.0f + (x  * x2 * x2 * x2 * x2) / 362880.0f;
}

//--------------------------------------------------------
float cosf(float x)
{
    return sinf(x + MATH_PI / 2.0f);
}

//--------------------------------------------------------
// float acosf(float v)
// {
//     return (MATH_PI / 2) - asinf(v);
// }

//--------------------------------------------------------
float lerpf(float a, float b, float t)
{
    return (b-a)*t + a;
}

//--------------------------------------------------------
float fabsf(float f)
{
    union { float x; unsigned int i; } u = { f };
    u.i &= 0x7fffffff;
    return u.x;
}

//--------------------------------------------------------
float signf(float a)
{
    return (a < 0) ? -1 : 1;
}

//--------------------------------------------------------
float maxf(float a, float b)
{
    return (a < b) ? b : a;
}

//--------------------------------------------------------
float minf(float a, float b)
{
    return (a > b) ? b : a;
}

//--------------------------------------------------------
float lerpfAngle(float a, float b, float t)
{
    if (fabsf(a-b) < MATH_PI)
        return clampAngle(lerpf(a, b, t));
    else if (a < b)
        return clampAngle(lerpf(a, b - MATH_TAU, t));
    else
        return clampAngle(lerpf(a, b + MATH_TAU, t));
}

//--------------------------------------------------------
float clamp(float v, float min, float max)
{
    if (v < min)
        return min;
    if (v > max)
        return max;

    return v;
}

//--------------------------------------------------------
/*
float clampAngle(float theta)
{
  float f1 = (theta + MATH_PI) / MATH_TAU;
  return (f1 - (float)(int)f1) * MATH_TAU - MATH_PI;
}
*/

//--------------------------------------------------------

float clampAngle(float theta)
{
    if (theta > MATH_PI)
        theta -= MATH_TAU;
    else if (theta < -MATH_PI)
        theta += MATH_TAU;

    return theta;
}


//--------------------------------------------------------
float fastSubRots(float input0, float input1)
{
    input0 = input0 - input1;
    int i = input0 < -MATH_PI;
    if (MATH_PI <= input0)
        input0 = (input0 - MATH_PI) - MATH_PI;

    if (i)
        input0 = input0 + MATH_PI + MATH_PI;
    
    return input0;
}

float fastDiffRots(float input0, float input1)
{
    float diff = fabsf(input0 - input1);
    if (MATH_PI <= diff) 
        diff = MATH_TAU - diff;

    return diff;
}

//float sqrtf(float number) {
//    float x = number * 0.5f;
//    float y = number;
//    long i = *(long*)&y;           // evil float bit hack
//    i = 0x5f3759df - (i >> 1);     // what the hell?
//    y = *(float*)&i;
//    y = y * (1.5f - (x * y * y));  // 1st iteration
//    return number * y;
//}

float sqrtf(float x)
{
    if (x <= 0.0f) return 0.0f;
    float out;
    __asm__ volatile (
        "sqrt.s %0, %1\n"
         : "=f"(out)
        : "f"(x)
        );
    return out;
    }