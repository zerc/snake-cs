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

START_TEST(test_vectors_eq)
{
    Vector a, b, c;

    a = create_vector(1, 2);
    b = create_vector(1, 2);
    c = create_vector(2, 1);

    if (vectors_eq(&a, &b) == false)
    {
        ck_abort_msg("Vectors a and b are supposed to be equal");
    }

    if (vectors_eq(&a, &c) == true)
    {
        ck_abort_msg("Vectors a and c are not supposed to be equal");
    }
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
    ck_assert(vectors_eq(&seg->start, &start));
    ck_assert(vectors_eq(&seg->direction, &direction));
    ck_assert_int_eq(seg->magnitude, 10);
    ck_assert_ptr_null(seg->next);

    free_segment(seg);
}
END_TEST

TCase *create_operations_tcase(void)
{
    TCase *tcase;
    tcase = tcase_create("operations");

    tcase_add_test(tcase, test_create_vector);
    tcase_add_test(tcase, test_vectors_eq);
    tcase_add_test(tcase, test_create_segment);
    return tcase;
}