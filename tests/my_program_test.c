#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <stdio.h>

#include <my_program/my_program.h>
#include <my_program/util.h>

/**
 * @brief Wrapper of sum function. Requires to import the wrapped function
 * implicitely to work.
 *
 * @param a sum a param.
 * @param b sum b param.
 * @return double sum result.
 */
double __wrap_sum(double a, double b)
{
    check_expected(a); // Checks a param is what is expected.
    check_expected(b); // Checks b param is what is expected.

    fprintf(stderr, "Calling the wrap function\n");

    return mock_type(double); // Returns the specified double.
}

/**
 * @brief An example test case.
 *
 * @param state
 */
static void my_program_test(void **state)
{
    (void)state; // unused.
    
    struct my_program_configuration config = {
        .verbose =1
    };

    int actualResult,
        expectedResult;

    // WARNING: Decimals are not checked in this function.
    expect_value(__wrap_sum, a, 1.333333); 
    // WARNING: Decimals are not checked in this function.
    expect_value(__wrap_sum, b, 1.999);
    will_return(__wrap_sum, 2.0); // Mock return value.

    expectedResult = EXIT_SUCCESS;
    actualResult = my_program(&config);

    assert_int_equal(expectedResult, actualResult);
}

/**
 * @brief Main test function.
 *
 * This test is NOT failing, but should fail if it triggers the real code form
 * sum. This is thanks to the stub, that allows decoupling tests.
 *
 * @return int Number of failed tests.
 */
int main(void)
{
    const struct CMUnitTest tests[] = {cmocka_unit_test(my_program_test)};
    return cmocka_run_group_tests(tests, NULL, NULL);
}