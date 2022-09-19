#include "vector.h"
#include "matrix.h"

#ifndef SNAKE_CS_LEVEL_H
#define SNAKE_CS_LEVEL_H

#define PLAYER_NAME_LENGTH 20

typedef struct Player Player;
struct Player
{
    char name[PLAYER_NAME_LENGTH];
    int score;
    bool active;
    Segment *seg;
};
Player init_player(char name[PLAYER_NAME_LENGTH]);
void free_player(Player *player);

typedef struct Level Level;
struct Level
{
    int stage;
    int top_x;
    int top_y;
    int players_count;
    Player *players;
    Matrix *area;
};

Level *init_level(int x, int y, int stage);
void free_level(Level *level);
int add_player(Level *level, char name[PLAYER_NAME_LENGTH]);
Player *get_player(Level *level, int player_id);
int update_player_score(Level *level, int player_id, int score);
#endif // SNAKE_CS_LEVEL_H