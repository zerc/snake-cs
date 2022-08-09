#ifndef SNAKE_CS_OPERATIONS_H
#define SNAKE_CS_OPERATIONS_H

typedef struct Vector Vector;
struct Vector
{
    int x;
    int y;
};

Vector create_vector(int x, int y);

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

#endif // SNAKE_CS_OPERATIONS_H