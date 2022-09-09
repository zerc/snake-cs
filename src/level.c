#include <stdlib.h>
#include <string.h>
#include "level.h"

Player init_player(char *name)
{
    Player p = {
        .name = name,
        .score = 0,
    };
    return p;
};

Level init_level(int x, int y, int stage)
{
    Level l = {
        .top_x = x,
        .top_y = y,
        .stage = stage,
        .players_count = 0,
        .players = NULL,
    };
    return l;
};

int add_player(Level *level, Player *player)
{
    if (level->players == NULL)
    {
        level->players = malloc(sizeof(Player));
        if (level->players == NULL)
        {
            return -1;
        }
        memcpy(level->players, player, sizeof(Player));
    }
    else
    {
        // TODO: Use linked list instead?
        Player *dst = malloc(level->players_count * sizeof(Player));

        if (dst == NULL)
        {
            return -1;
        }

        Player *src = level->players;
        int offset = 0;

        for (int i = 0; i <= level->players_count; i++)
        {
            offset = i * sizeof(Player);

            if (i < level->players_count)
            {
                memcpy(dst + offset, src + offset, sizeof(Player));
            }
            else
            {
                memcpy(dst + offset, player, sizeof(Player));
            }
        }
        free(level->players);
        level->players = dst;
    }
    int player_id = level->players_count;
    level->players_count += 1;
    return player_id;
};

Player *get_player(Level *level, int player_id)
{
    if (level->players_count == 0)
    {
        return NULL;
    }

    Player *pp = (level->players + player_id * sizeof(Player));
    return pp;
}