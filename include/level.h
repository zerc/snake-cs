#include "operations.h"

#ifndef SNAKE_CS_LEVEL_H
#define SNAKE_CS_LEVEL_H

typedef struct Player Player;
struct Player
{
    char *name;
    int score;
    Segment *seg;
};
Player init_player(char *name);

typedef struct Level Level;
struct Level
{
    int stage;
    int top_x;
    int top_y;
    int players_count;
    Player *players;
};

Level init_level(int x, int y, int stage);
int add_player(Level *level, Player *player);
Player *get_player(Level *level, int player_id);
#endif // SNAKE_CS_LEVEL_H