#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <my_program/util.h>

/**
 * @brief An example test case.
 *
 * @param state
 */
static void sum_test(void **state)
{
    (void)state; // unused.

    double actualResult, // Actual test result.
        expectedResult;  // Expected test result.

    expectedResult = 0.0;
    actualResult = sum(-1, 1);
    assert_int_equal(expectedResult, actualResult);
}



static void dblcmp_test(void **state)
{
    (void)state; // unused.

    int actualValue,
        expectedValue;

    expectedValue = 0;
    actualValue = dblcmp(1.001, 1.002, 0.0011);
    assert_int_equal(expectedValue, actualValue);

    actualValue = dblcmp(1.002, 1.001, 0.0011);
    assert_int_equal(expectedValue, actualValue);

    expectedValue = -1;
    actualValue = dblcmp(1.001, 1.002, 0.0010);
    assert_int_equal(expectedValue, actualValue);

    expectedValue = 1;
    actualValue = dblcmp(1.002, 1.001, 0.0010);
    assert_int_equal(expectedValue, actualValue);

    expectedValue = 0;
    actualValue = dblcmp(1.0000000000, 1.0000000000, 0.00000000001);
    assert_int_equal(expectedValue, actualValue);

    expectedValue = 1;
    actualValue = dblcmp(1.0000000000, 0.9999999999, 0.00000000001);
    assert_int_equal(expectedValue, actualValue);

    expectedValue = -1;
    actualValue = dblcmp(1.0000000000, 1.0000000001, 0.00000000001);
    assert_int_equal(expectedValue, actualValue);
    actualValue = dblcmp(1.0000000000, 1.0000000002, 0.00000000001);
    assert_int_equal(expectedValue, actualValue);
    actualValue = dblcmp(1.0000000000, 1.0000000003, 0.00000000001);
    assert_int_equal(expectedValue, actualValue);
}



/**
 * @brief Main test function.
 *
 * This test is failing on purpose. The point is to show that, alghough my_program
 * requires sum, my_program test is working fine thanks to the stub, while this
 * test is failing.
 *
 * @return int Number of failed tests.
 */
int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(sum_test),
        cmocka_unit_test(dblcmp_test),
        };
    return cmocka_run_group_tests(tests, NULL, NULL);
}