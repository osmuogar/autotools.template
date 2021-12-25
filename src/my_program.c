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

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

/**
 * @brief Mail my_program. Calls a buggy function.
 * @bug The buggy function sum is used to show the functionality of mocks.
 *
 * @param configuration
 * @return int
 */
int my_program(struct my_program_configuration *configuration)
{
    int res; // Return value.
    double result;
    // Retrieve external value for my_program_configuration.
    extern struct my_program_configuration *config;
    config = configuration; // Assign value.

    res = EXIT_SUCCESS; // If all goes fine.

    result = sum(-1, 1);

    if (0 != errno)
    {
        res = EXIT_FAILURE; // Something failed.
    }
    else
    {
        printf("The value is %f\n", result);
    }

    return res; // Return status.
}
