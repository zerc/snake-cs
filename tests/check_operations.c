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


TCase* create_operations_tcase(void)
{
    TCase *tcase;
    tcase = tcase_create("Operations");

    tcase_add_test(tcase, test_create_vector);
    return tcase;
}