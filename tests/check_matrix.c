#include <check.h>

#include "matrix.h"

START_TEST(test_create_matrix)
{
    Matrix *m = create_matrix(3, 2);

    ck_assert_int_eq(m->rows, 3);
    ck_assert_int_eq(m->cols, 2);
    ck_assert_ptr_nonnull(m->arr);

    free_matrix(m);
}
END_TEST

START_TEST(test_get_value)
{
    Matrix *m = create_matrix(3, 2);

    int value = 0;
    for (int r = 0; r < m->rows; r++)
    {
        for (int c = 0; c < m->cols; c++)
        {
            set_value(m, r, c, value++);
        }
    }

    ck_assert_int_eq(get_value(m, 0, 0), 0);
    ck_assert_int_eq(get_value(m, 0, 1), 1);
    ck_assert_int_eq(get_value(m, 1, 0), 2);
    ck_assert_int_eq(get_value(m, 1, 1), 3);
    ck_assert_int_eq(get_value(m, 2, 0), 4);
    ck_assert_int_eq(get_value(m, 2, 1), 5);

    ck_assert_int_eq(get_value(m, 0, 10), -1);
    ck_assert_int_eq(get_value(m, 0, -1), -1);
    ck_assert_int_eq(get_value(m, 10, 0), -1);
    ck_assert_int_eq(get_value(m, -1, 0), -1);

    free_matrix(m);
}
END_TEST

TCase *create_matrix_tcase(void)
{
    TCase *tcase;
    tcase = tcase_create("matrix");

    tcase_add_test(tcase, test_create_matrix);
    tcase_add_test(tcase, test_get_value);

    return tcase;
}
