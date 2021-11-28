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
 * Main.
 */
int program(struct program_configuration *configuration)
{
  // Retrieve external value for program_configuration
  extern struct program_configuration *config;
  config = configuration; // Assign value

  return EXIT_SUCCESS;
}
