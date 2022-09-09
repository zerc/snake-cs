#include <stdlib.h>
#include "operations.h"

Vector create_vector(int x, int y)
{
    Vector v = {
        .x = x,
        .y = y,
    };
    return v;
}

bool vectors_eq(Vector *a, Vector *b)
{
    return a->x == b->x && a->y == b->y;
}

Segment *create_segment(Vector start, Vector direction, int magnitude)
{
    // Validate the direction vector: it should be (-1, 0), (1, 0), (0, -1), (0, 1)
    if (abs(direction.x) + abs(direction.y) != 1)
    {
        return NULL;
    };

    Segment *seg = malloc(sizeof(Segment));

    if (seg == NULL)
    {
        return NULL;
    }

    seg->start = start;
    seg->direction = direction;
    seg->magnitude = magnitude;
    seg->next = NULL;

    return seg;
}

int free_segment(Segment *seg)
{
    if (seg != NULL)
    {
        if (seg->next != NULL)
        {
            free_segment(seg->next);
        }
        free(seg);
    }
    return 0;
}

int move_segment(Segment *seg, int distance, Vector *boundary)
{
    Vector start = {
        .x = seg->start.x + (seg->direction.x * distance),
        .y = seg->start.y + (seg->direction.y * distance),
    };

    if (start.x < 0 || start.y < 0)
    {
        return -1;
    }
    if (start.x > boundary->x || start.y > boundary->y)
    {
        return -1;
    }

    seg->start.x = start.x;
    seg->start.y = start.y;

    return 0;
}