#include <check.h>
#include <stdlib.h>

TCase* create_operations_tcase(void);

Suite *suite(void)
{
    Suite *s;

    s = suite_create("Snake CS");

    suite_add_tcase(s, create_operations_tcase());

    return s;
}

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_NORMAL);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}