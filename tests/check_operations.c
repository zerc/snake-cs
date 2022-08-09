#include <check.h>

#include "operations.h"

START_TEST(test_create_vector)
{
    Vector v;
    v = create_vector(1, 2);

    ck_assert_int_eq(v.x, 1);
    ck_assert_int_eq(v.y, 2);
}
END_TEST

START_TEST(test_create_segment)
{
    Segment *seg;
    Vector start, direction;
    int magnitude;

    start = create_vector(0, 0);
    direction = create_vector(1, 0);
    magnitude = 10;

    seg = create_segment(start, direction, magnitude);

    ck_assert_ptr_nonnull(seg);
    ck_assert_int_eq(seg->start.x, 0);
    ck_assert_int_eq(seg->start.y, 0);

    ck_assert_int_eq(seg->direction.x, 1);
    ck_assert_int_eq(seg->direction.y, 0);

    ck_assert_int_eq(seg->magnitude, 10);

    ck_assert_ptr_null(seg->next);

    free_segment(seg);
}
END_TEST

TCase *create_operations_tcase(void)
{
    TCase *tcase;
    tcase = tcase_create("Operations");

    tcase_add_test(tcase, test_create_vector);
    tcase_add_test(tcase, test_create_segment);
    return tcase;
}