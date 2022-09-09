#include <stdbool.h>

#ifndef SNAKE_CS_MATRIX_H
#define SNAKE_CS_MATRIX_H

typedef struct Matrix Matrix;
struct Matrix
{
    int rows;
    int cols;
    int *arr;
};

Matrix *create_matrix(int rows, int cols);
void free_matrix(Matrix *m);
bool _validate_boundary(Matrix *m, int row, int col);
int get_value(Matrix *m, int row, int col);
bool set_value(Matrix *m, int row, int col, int value);
#endif // SNAKE_CS_MATRIX_H
