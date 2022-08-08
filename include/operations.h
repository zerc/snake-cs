#ifndef SNAKE_CS_OPERATIONS_H
#define SNAKE_CS_OPERATIONS_H

typedef struct Vector Vector;
struct Vector {
    int x;
    int y;
};

Vector create_vector(int x, int y);

#endif // SNAKE_CS_OPERATIONS_H