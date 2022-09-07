#include "operations.h"

#ifndef SNAKE_CS_PLAYER_H
#define SNAKE_CS_PLAYER_H

typedef struct Player Player;
struct Player
{
    char *name;
    int score;
    Segment *seg;
};

Player init_player(char *name);

#endif // SNAKE_CS_PLAYER_H