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

START_TEST(test_create_segment__invalid_direction)
{
    Segment *seg;
    Vector start = create_vector(0, 0);

    seg = create_segment(start, create_vector(0, 0), 1);
    ck_assert_ptr_null(seg);

    seg = create_segment(start, create_vector(1, 1), 1);
    ck_assert_ptr_null(seg);

    seg = create_segment(start, create_vector(-1, -1), 1);
    ck_assert_ptr_null(seg);

    seg = create_segment(start, create_vector(-1, 10), 1);
    ck_assert_ptr_null(seg);
}
END_TEST

START_TEST(test_move_segment)
{
    Segment *seg;
    seg = create_segment(create_vector(0, 0), create_vector(0, 1), 2);
    ck_assert_ptr_nonnull(seg);

    Vector boundary = {
        .x = 5,
        .y = 5,
    };

    int result = move_segment(seg, 3, &boundary);
    ck_assert_int_eq(result, 0);

    Vector new_start = create_vector(0, 3);
    ck_assert(vectors_eq(&seg->start, &new_start));

    // not possible to move beyond boundary
    result = move_segment(seg, 3, &boundary);
    ck_assert_int_eq(result, -1);
    ck_assert(vectors_eq(&seg->start, &new_start));

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
    tcase_add_test(tcase, test_create_segment__invalid_direction);
    tcase_add_test(tcase, test_move_segment);

    return tcase;
}