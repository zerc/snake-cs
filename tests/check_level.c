#include <check.h>

#include "level.h"

START_TEST(test_init_player)
{
    Player p = init_player("Player One");

    ck_assert_str_eq(p.name, "Player One");
    ck_assert_int_eq(p.score, 0);
    ck_assert_ptr_null(p.seg);
}
END_TEST

START_TEST(test_init_level)
{
    Level *l = init_level(3, 4, 0);

    ck_assert_int_eq(l->stage, 0);
    ck_assert_int_eq(l->top_x, 3);
    ck_assert_int_eq(l->top_y, 4);
    ck_assert_int_eq(l->players_count, 0);
    ck_assert_ptr_null(l->players);

    free_level(l);
}
END_TEST

START_TEST(test_add_player)
{
    Level *l = init_level(3, 4, 0);

    int p1_id = add_player(l, "Player One");
    ck_assert_int_eq(l->players_count, 1);

    int p2_id = add_player(l, "Player Two");
    ck_assert_int_eq(l->players_count, 2);

    int p3_id = add_player(l, "Player Three");
    ck_assert_int_eq(l->players_count, 3);

    ck_assert_int_eq(p1_id, 0);
    ck_assert_int_eq(p2_id, 1);
    ck_assert_int_eq(p3_id, 2);

    ck_assert_ptr_nonnull(l->players);

    ck_assert_str_eq(get_player(l, p1_id)->name, "Player One");
    ck_assert_str_eq(get_player(l, p2_id)->name, "Player Two");
    ck_assert_str_eq(get_player(l, p3_id)->name, "Player Three");

    free_level(l);
}

START_TEST(test_update_player_score)
{
    Level *l = init_level(3, 4, 0);

    int p1_id = add_player(l, "Player One");
    Player *p = get_player(l, p1_id);

    ck_assert_int_eq(p->score, 0);

    ck_assert_int_eq(update_player_score(l, p1_id, 10), 10);  // 0 + 10 = 10
    ck_assert_int_eq(update_player_score(l, p1_id, 10), 20);  // 10 + 10 = 20
    ck_assert_int_eq(update_player_score(l, p1_id, -10), 10); // 20 + (-10) = 10
    ck_assert_int_eq(update_player_score(l, p1_id, -100), 0); // 10 + (-100) = 0

    free_level(l);
}

TCase *create_level_tcase(void)
{
    TCase *tcase;
    tcase = tcase_create("level");

    tcase_add_test(tcase, test_init_player);
    tcase_add_test(tcase, test_init_level);
    tcase_add_test(tcase, test_add_player);
    tcase_add_test(tcase, test_update_player_score);

    return tcase;
}
