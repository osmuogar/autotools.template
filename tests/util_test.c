#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <program/util.h>

static void util_test(void **state)
{
    (void)state; // unused.

    double actualResult,
        expectedResult;

    expectedResult = 2.0;
    actualResult = sum(1, 1);

    assert_int_equal(expectedResult, actualResult);
}

/**
 * @brief Main test function.
 * 
 * This test is failing on purpose. The point is to show that, alghough program
 * requires sum, the program test is working fine thanks to the stub, while this
 * test is failing.
 *
 * @return int Number of failed tests.
 */
int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(util_test)};
    return cmocka_run_group_tests(tests, NULL, NULL);
}