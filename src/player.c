#include "player.h"

Player init_player(char *name)
{
    Player p = {
        .name = name,
        .score = 0,
    };
    return p;
}