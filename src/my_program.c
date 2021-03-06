/*
    The package should `#include' the configuration header file before any other
    header files, to prevent inconsistencies in declarations (for example, if it
    redefines const). Use `#include <config.h>' instead of
    `#include "config.h"', and pass the C compiler a `-I.' option
    (or `-I..'; whichever directory contains `config.h').
*/
#include <config.h>

#include <my_program/common.h>
#include <my_program/my_program.h>
#include <my_program/util.h>

#include <gsl/gsl_math.h>

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

/**
 * @brief my_program main function.
 *
 * @param config
 * @return int
 */
int my_program(struct my_program_configuration *configuration)
{
    extern struct my_program_configuration *config;

    double result; // Function result.

    // Check configuration.
    if (NULL == configuration)
        return errno = EINVAL, EXIT_FAILURE;
    config = configuration;

    result = sum(1.1111, 1.2222); // Compute result.

    if (0 != errno)
        return EXIT_FAILURE; // Errno already set.

    // Square the result.
    result = gsl_pow_int(result, 2);

    if (config->verbose)
    {
        fprintf(stdout, "The value is %f\n", result);
    }

    return EXIT_SUCCESS; // Return status.
}
