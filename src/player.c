#include <tamtypes.h>
#include "game.h"
#include "player.h"

int playerCanControl(void)
{
    Player *player = PLAYER_STRUCT;

    if (!isInGameMode(GAME_MODE_NORMAL))
        return 0;

    if (player == NULL || player->pMoby == NULL)
        return 0;

    if (player->cutsceneControlLock != 0 || player->gameplayReady == 0)
        return 0;

    if (player->state == PLAYER_STATE_CUT_SCENE)
        return 0;

    return 1;
}
