#include <check.h>

START_TEST(example_test)
{
    ck_assert_uint_eq(0u, 1u);
}
END_TEST;

static Suite *suite_request(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("Example");

    tc = tcase_create("Example test");
    tcase_add_test(tc, example_test);
    suite_add_tcase(s, tc);

    return s;
}