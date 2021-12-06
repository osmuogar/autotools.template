/*
    The package should `#include' the configuration header file before any other
    header files, to prevent inconsistencies in declarations (for example, if it
    redefines const). Use `#include <config.h>' instead of
    `#include "config.h"', and pass the C compiler a `-I.' option
    (or `-I..'; whichever directory contains `config.h').
*/
#include <config.h>

#include <program/common.h>
#include <program/program.h>
#include <program/util.h>

#include <stdlib.h>

/**
 * @brief Mail program. Calls a buggy function.
 * @bug The buggy function sum is used to show the functionality of mocks.
 *
 * @param configuration
 * @return int
 */
int program(struct program_configuration *configuration)
{
  int res; // Return value.
  // Retrieve external value for program_configuration.
  extern struct program_configuration *config;
  config = configuration; // Assign value.

  res = EXIT_SUCCESS; // If all goes fine.

  if (2.0 != sum(1, 1))
  {
    res = EXIT_FAILURE; // Something failed.
  }

  return res; // Return status.
}
