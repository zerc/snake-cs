#include <check.h>

#include "sn_options.h"

START_TEST(test_sn_parse_options__version_help)
{
    char *argv[] = {"snake", "--version", "-h"};
    SN_Options options = sn_parse_options(3, argv);

    ck_assert_int_eq(options.show_version, 1);
    ck_assert_int_eq(options.show_help, 1);
    ck_assert_int_eq(options.gui, 0);
    ck_assert_str_eq(options.name, "guest");
    ck_assert_str_eq(options.connect, "");
}
END_TEST

START_TEST(test_sn_parse_options__name)
{
    char *argv[] = {"snake", "--name", "vladimir"};
    SN_Options options = sn_parse_options(3, argv);

    ck_assert_str_eq(options.name, "vladimir");
}

// name length should comply with PLAYER_NAME_LENGTH
START_TEST(test_sn_parse_options__name__truncates)
{
    char *argv[] = {"snake", "--name", "vladimir123456789101010"};
    SN_Options options = sn_parse_options(3, argv);

    ck_assert_str_eq(options.name, "vladimir12345678910");
}

// long option takes priority
START_TEST(test_sn_parse_options__name__override)
{
    char *argv[] = {"snake", "--name", "vladimir", "-n", "vlad"};
    SN_Options options = sn_parse_options(5, argv);

    ck_assert_str_eq(options.name, "vladimir");
}

TCase *create_sn_options_tcase(void)
{
    TCase *tcase;
    tcase = tcase_create("sn_options");

    tcase_add_test(tcase, test_sn_parse_options__version_help);
    tcase_add_test(tcase, test_sn_parse_options__name);
    tcase_add_test(tcase, test_sn_parse_options__name__truncates);
    tcase_add_test(tcase, test_sn_parse_options__name__override);

    return tcase;
}
