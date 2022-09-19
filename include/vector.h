#include <stdbool.h>

#ifndef SNAKE_CS_VECTOR_H
#define SNAKE_CS_VECTOR_H

typedef struct Vector Vector;
struct Vector
{
    int x;
    int y;
};

Vector create_vector(int x, int y);
bool vectors_eq(Vector *a, Vector *b);

typedef struct Segment Segment;
struct Segment
{
    Vector start;
    Vector direction;
    int magnitude;
    Segment *next;
};

Segment *create_segment(Vector start, Vector direction, int magnitude);
int free_segment(Segment *seg);
int move_segment(Segment *segment, int distance, Vector *boundary);

#endif // SNAKE_CS_VECTOR_H