#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <stdio.h>

#include "../src/program.c"

extern struct program_configuration *config;
extern int program(struct program_configuration *configuration);

/**
 * @brief Wrapper of sum function. Requires to import the wrapped function
 * implicitely to work.
 *
 * @param a sum a param.
 * @param b sum b param.
 * @return double sum result.
 */
double __wrap_sum(const double a, double b)
{
    check_expected(a); // Checks a param is what is expected.
    check_expected(b); // Checks b param is what is expected.

    return mock_type(double); // Returns the specified double.
}

/**
 * @brief An example test case.
 *
 * @param state
 */
static void program_test(void **state)
{
    (void)state; // unused.

    int actualResult,
        expectedResult;

    expect_value(__wrap_sum, a, 1); // Mock expected a value.
    expect_value(__wrap_sum, b, 1); // Mock expected b value.
    will_return(__wrap_sum, 2);     // Mock return value.

    expectedResult = EXIT_SUCCESS;
    actualResult = program(NULL); // In this case, config is not required.

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
    const struct CMUnitTest tests[] = {cmocka_unit_test(program_test)};
    return cmocka_run_group_tests(tests, NULL, NULL);
}