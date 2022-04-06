#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <my_program/my_program.h>
#include <my_program/util.h>

static void basic_test(void **state)
{
    int actualResult,
        expectedResult;

    expectedResult = actualResult = 0;

    assert_int_equal(expectedResult, actualResult);
}

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

    return mock_type(double); // Returns the specified double.
}

static int setup(void **state)
{
    struct my_program_configuration *config;

    config = malloc(1 * sizeof(struct my_program_configuration));
    if (config == NULL)
    {
        return -1;
    }

    config->verbose = 0;

    config->err_output = NULL;
    config->std_output = NULL;
    config->version = NULL;

    *state = config;

    return 0;
}
static int teardown(void **state)
{
    free(*state);
    return 0;
}

/**
 * @brief An example test case.
 *
 * @param state
 */
static void my_program_test(void **state)
{
    struct my_program_configuration *config = *state;

    int actualResult,
        expectedResult;

    // WARNING: Decimals are not checked in this function.
    expect_value(__wrap_sum, a, 1.333333);
    // WARNING: Decimals are not checked in this function.
    expect_value(__wrap_sum, b, 1.999);
    will_return(__wrap_sum, 2.0); // Mock return value.

    expectedResult = EXIT_SUCCESS;
    actualResult = my_program(config);

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
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(basic_test),
        cmocka_unit_test_setup_teardown(my_program_test, setup, teardown)};
    return cmocka_run_group_tests(tests, NULL, NULL);
}