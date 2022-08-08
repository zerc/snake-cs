#include <check.h>

START_TEST(test_rotation)
{
    ck_assert_str_eq("foo", "foo");
}
END_TEST


TCase* create_operations_tcase(void)
{
    TCase *tcase;
    tcase = tcase_create("Operations");

    tcase_add_test(tcase, test_rotation);
    return tcase;
}