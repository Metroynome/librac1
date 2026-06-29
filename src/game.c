#include "interop.h"
#include "game.h"
#include "types.h"

bool isInGameMode(eGameMode mode)
{
    if (gameMode != mode || gameModeTimer < 8)
        return false;

    return true;
}
