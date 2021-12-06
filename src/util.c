/*
    The package should `#include' the configuration header file before any other
    header files, to prevent inconsistencies in declarations (for example, if it
    redefines const). Use `#include <config.h>' instead of
    `#include "config.h"', and pass the C compiler a `-I.' option
    (or `-I..'; whichever directory contains `config.h').
*/
#include <config.h>

/**
 * @brief Sums two nums.
 * @bug There is an intentional bug used to show mock usability.
 *
 * @param a Number to sum.
 * @param b Number to sum.
 * @return double Sum of number a and b.
 */
double sum(double a, double b)
{
    return a + b + 1;
}