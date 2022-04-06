/*
    The package should `#include' the configuration header file before any other
    header files, to prevent inconsistencies in declarations (for example, if it
    redefines const). Use `#include <config.h>' instead of
    `#include "config.h"', and pass the C compiler a `-I.' option
    (or `-I..'; whichever directory contains `config.h').
*/
#include <config.h>

#include <errno.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

double sum(double a, double b)
{
    fprintf(stderr, "Calling the real function\n");
    errno = 0;
    if (a < 0 || b < 0)
    {
        errno = EINVAL;
    }

    return a + b + 1.0;
}