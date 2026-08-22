#ifndef _LIBRAC1_SOUND_H_
#define _LIBRAC1_SOUND_H_

#include <tamtypes.h>
#include "interop.h"
#include "math3d.h"
#include "moby.h"

extern VariableAddress_t vaSoundPlay;

int soundPlay(struct SoundDef *soundDef, u8 flags, Moby *sourceMoby, VECTOR *position, int range);
int soundPlayByMobyIndex(int soundIndex, u8 flags, Moby *sourceMoby);

#endif // _LIBRAC1_SOUND_H_
