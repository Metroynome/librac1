#ifndef _LIBRAC1_MOBY_H_
#define _LIBRAC1_MOBY_H_

#include <tamtypes.h>
#include "types.h"
#include "math3d.h"

enum MobyIds {
    MOBY_ID_NULL = 0,
};

typedef struct Moby { // 0x100
/* 0x00 */ VECTOR bSphere;
/* 0x10 */ VECTOR position;
/* 0x20 */ char state;
/* 0x21 */ u8 group;
/* 0x22 */ char mClass;
/* 0x23 */ u8 opacity;
/* 0x24 */ struct MobyClass *pClass;
/* 0x28 */ struct Moby *pChain;
/* 0x2c */ float scale;
/* 0x30 */ char unk_30[0x44];
/* 0x74 */ void *pUpdate;
/* 0x78 */ void *pVar;
/* 0x7c */ char unk_7c[0x44];
/* 0xc0 */ mtx3 rotMtx;
/* 0xf0 */ vec4 rot;
} Moby;

struct MobyClass { // 0x50
/* 0x00 */ void *packets;
/* 0x04 */ char packet_cnt_0;
/* 0x05 */ char packet_cnt_1;
/* 0x06 */ char metal_cnt;
/* 0x07 */ char metal_ofs;
/* 0x08 */ char joint_cnt;
/* 0x09 */ char pad;
/* 0x0a */ char packet_cnt_2;
/* 0x0b */ char team_texs;
/* 0x0c */ char seq_cnt;
/* 0x0d */ char sound_cnt;
/* 0x0e */ char lod_trans;
/* 0x0f */ char shadow;
/* 0x10 */ short int *collision;
/* 0x14 */ void *skeleton;
/* 0x18 */ void *common_trans;
/* 0x1c */ void *anim_joints;
/* 0x20 */ void *gif_usage;
/* 0x24 */ float gScale;
/* 0x28 */ struct SoundDef *sound_defs;
/* 0x2c */ char bangles;
/* 0x2d */ char mip_dist;
/* 0x2e */ short int corncob;
/* 0x30 */ VECTOR bSphere;
/* 0x40 */ int glow_rgba;
/* 0x44 */ short int mode_bits;
/* 0x46 */ char type;
/* 0x47 */ char mode_bits2;
/* 0x48 */ void *seqs[0];
};


#endif
