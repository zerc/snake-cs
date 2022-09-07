#include <check.h>

#include "level.h"

START_TEST(test_init_level)
{
    Level l = init_level(3, 4, 0);

    ck_assert_int_eq(l.stage, 0);
    ck_assert_int_eq(l.top_x, 3);
    ck_assert_int_eq(l.top_y, 4);
    ck_assert_int_eq(l.players_count, 0);
    ck_assert_ptr_null(l.players);
}
END_TEST

START_TEST(test_add_player)
{
    Level l = init_level(3, 4, 0);
    Player p1 = init_player("Player One");
    Player p2 = init_player("Player Two");
    Player p3 = init_player("Player Three");

    int p1_id = add_player(&l, &p1);
    ck_assert_int_eq(l.players_count, 1);

    int p2_id = add_player(&l, &p2);
    ck_assert_int_eq(l.players_count, 2);

    int p3_id = add_player(&l, &p3);
    ck_assert_int_eq(l.players_count, 3);

    ck_assert_int_eq(p1_id, 0);
    ck_assert_int_eq(p2_id, 1);
    ck_assert_int_eq(p3_id, 2);

    ck_assert_ptr_nonnull(l.players);

    ck_assert_str_eq(get_player(&l, p1_id)->name, "Player One");
    ck_assert_str_eq(get_player(&l, p2_id)->name, "Player Two");
    ck_assert_str_eq(get_player(&l, p3_id)->name, "Player Three");
}

TCase *create_level_tcase(void)
{
    TCase *tcase;
    tcase = tcase_create("level");

    tcase_add_test(tcase, test_init_level);
    tcase_add_test(tcase, test_add_player);

    return tcase;
}
