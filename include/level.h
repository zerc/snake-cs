#include "operations.h"

#ifndef SNAKE_CS_LEVEL_H
#define SNAKE_CS_LEVEL_H

#define PLAYER_NAME_LENGTH 20

typedef struct Player Player;
struct Player
{
    char name[PLAYER_NAME_LENGTH];
    int score;
    Segment *seg;
};
Player init_player(char name[PLAYER_NAME_LENGTH]);

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
int add_player(Level *level, char name[PLAYER_NAME_LENGTH]);
Player *get_player(Level *level, int player_id);
#endif // SNAKE_CS_LEVEL_H