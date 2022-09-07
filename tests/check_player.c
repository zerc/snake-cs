#include <check.h>

#include "player.h"

START_TEST(test_init_player)
{
    Player p = init_player("Player One");

    ck_assert_str_eq(p.name, "Player One");
    ck_assert_int_eq(p.score, 0);
    ck_assert_ptr_null(p.seg);
}
END_TEST

TCase *create_player_tcase(void)
{
    TCase *tcase;
    tcase = tcase_create("player");

    tcase_add_test(tcase, test_init_player);

    return tcase;
}
