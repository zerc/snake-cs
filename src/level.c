#include <stdlib.h>
#include <string.h>
#include "level.h"

Player init_player(char name[PLAYER_NAME_LENGTH])
{
    Player p = {
        .score = 0,
        .active = true,
    };
    memcpy(p.name, name, PLAYER_NAME_LENGTH);
    return p;
};

void free_player(Player *player)
{
    if (player->seg != NULL)
    {
        free_segment(player->seg);
    }
    free(player);
}

Level *init_level(int x, int y, int stage)
{
    Level *l = malloc(sizeof(Level));
    if (l == NULL)
    {
        return NULL;
    }

    Matrix *m = create_matrix(y, x);
    if (m == NULL)
    {
        return NULL;
    }

    l->top_x = x;
    l->top_y = y;
    l->stage = stage;
    l->players_count = 0;
    l->players = NULL;
    l->area = m;

    return l;
};

int add_player(Level *level, char name[PLAYER_NAME_LENGTH])
{
    if (level->players == NULL)
    {
        level->players = malloc(sizeof(Player));
        if (level->players == NULL)
        {
            return -1;
        }
        Player player = init_player(name);
        memcpy(level->players, &player, sizeof(Player));
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
                Player player = init_player(name);
                memcpy(dst + offset, &player, sizeof(Player));
            }
        }
        free(level->players);
        level->players = dst;
    }
    int player_id = level->players_count;
    level->players_count += 1;
    return player_id;
};

void free_level(Level *level)
{
    if (level->players != NULL)
    {
        for (int i = level->players_count; i < 0; i--)
        {
            Player *p = get_player(level, i);
            free_player(p);
        }
        free(level->players);
        level->players = NULL;
    }

    if (level->area != NULL)
    {
        free_matrix(level->area);
        level->area = NULL;
    }

    free(level);
}

Player *get_player(Level *level, int player_id)
{
    if (level->players_count == 0)
    {
        return NULL;
    }

    Player *pp = (level->players + player_id * sizeof(Player));
    return pp;
}

int update_player_score(Level *level, int player_id, int score_diff)
{
    // NOTE: not thread-safe
    Player *p = get_player(level, player_id);
    if (p == NULL)
    {
        return -1;
    }
    p->score += score_diff;
    if (p->score < 0)
    {
        p->score = 0;
    }
    return p->score;
}