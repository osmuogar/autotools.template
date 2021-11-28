#include <check.h>
#include <stdlib.h>

#include "./example_test.c"

int main(void)
{
    SRunner *sr;
    int number_failed = 0;

    sr = srunner_create(suite_example());
    // srunner_add_suite(sr, suite_example2());

    // Eases debugging
    // srunner_set_fork_status(sr, CK_NOFORK);

    srunner_set_log(sr, "verbose_test.log");

    srunner_run_all(sr, CK_NORMAL);
    number_failed += srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
