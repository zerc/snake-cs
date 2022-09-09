#include <stdlib.h>

#include "matrix.h"

Matrix *create_matrix(int rows, int cols)
{
    Matrix *m = malloc(sizeof(Matrix));
    if (m == NULL)
    {
        return NULL;
    }
    m->rows = rows;
    m->cols = cols;
    m->arr = calloc(rows * cols, sizeof(int));

    return m;
}

void free_matrix(Matrix *m)
{
    if (m->arr != NULL)
    {
        free(m->arr);
    }
    free(m);
}

bool _validate_boundary(Matrix *m, int row, int col)
{
    if (m->arr == NULL)
    {
        return false;
    }
    if (row < 0 || col < 0)
    {
        return false;
    }
    if (col >= m->cols || row >= m->rows)
    {
        return false;
    }
    return true;
}

int get_value(Matrix *m, int row, int col)
{
    if (!_validate_boundary(m, row, col))
    {
        return -1;
    }
    int offset = row * m->cols + col;
    return m->arr[offset];
}

bool set_value(Matrix *m, int row, int col, int value)
{
    if (!_validate_boundary(m, row, col))
    {
        return false;
    }
    int offset = row * m->cols + col;
    m->arr[offset] = value;
    return true;
}