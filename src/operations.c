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

Segment *create_segment(Vector start, Vector direction, int magnitude)
{
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
        free(seg);
    }
    return 0;
}