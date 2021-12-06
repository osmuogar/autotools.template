/*
    The package should `#include' the configuration header file before any other
    header files, to prevent inconsistencies in declarations (for example, if it
    redefines const). Use `#include <config.h>' instead of
    `#include "config.h"', and pass the C compiler a `-I.' option
    (or `-I..'; whichever directory contains `config.h').
*/
#include <config.h> // Autotools configuration.

#include <program/common.h>
#include <program/program.h>

#include <argp.h>
#include <string.h>
#include <stdlib.h>

const char *argp_program_version = PACKAGE_STRING;
const char *argp_program_bug_address = PACKAGE_BUGREPORT;
static char doc[] = "Program description";
static char args_doc[] = "Program arguments";
static struct argp_option options[] = {
    {0, 0, 0, 0, " ", 2},
    {"verbose", 'v', 0, 0, "Verbose mode.", 2},
    {"quiet", 'q', 0, 0, "Quiet mode.", 2},

    {0, 0, 0, 0, " ", -1},
    {"usage", 'u', 0, 0, "Prints ussage and exits.", -1},
    {"help", 'h', 0, 0, "Prints help and exits.", -1},
    {"version", 'V', 0, 0, "Prints version and exits.", -1},
    {0}};

static error_t my_arg_parser(int key, char *arg, struct argp_state *state)
{
    struct program_configuration *arguments = state->input;
    switch (key)
    {
    case 'v':
        arguments->verbose = 1;
        break;
    case 'q':
        arguments->verbose = 0;
        break;
    case 'V':
        fprintf(stdout, "%s\n", argp_program_version);
        exit(0);
    case 'u':
        argp_state_help(state, stderr, ARGP_HELP_USAGE);
        exit(0);
        break;
    case 'h':
        argp_state_help(state, stderr, ARGP_HELP_STD_HELP);
        break;
    case ARGP_KEY_ARG:
        if (state->arg_num >= 1) // Too many arguments.
        {
            argp_usage(state);
        }
        // arguments->argv[state->arg_num] = arg;
        break;
    case ARGP_KEY_END:
        if (state->arg_num < 0) // Not enough arguments.
        {
            argp_usage(state);
        }
        break;
    case ARGP_KEY_NO_ARGS:
        break;
    default:
        return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

// Parse options.
struct argp argp = {
    .options = options,
    .parser = my_arg_parser,
    .args_doc = args_doc,
    .doc = doc,
    .children = NULL,
    .help_filter = NULL,
    .argp_domain = NULL};

/**
 * @brief Generates a command for this repository.
 *
 * @param argc Num of arguments.
 * @param argv Vector of arguments.
 * @return int Return state.
 */
int main(int argc, char *argv[])
{
    struct program_configuration config; // Program configuration.
    int res = 0;                         // Execution result.
    unsigned int i;                      // Index.

// Enable/Disable my feature.
#ifdef ENABLE_MY_FEATURE
    printf("My feature enabled.\n");
#else
    printf("My feature non-enabled.\n");
#endif

    config.version = PACKAGE_VERSION; // Import version from autotools.
    config.verbose = 0;               // Default value.

    // Parses arguments.
    if (0 != argp_parse(&argp, argc, argv, ARGP_NO_HELP, NULL, &config))
    {
        fprintf(stderr, "Error parsing arguments: %s\n", strerror(errno));
    }

    // Executes main program.
    if (0 != (res = program(&config)))
    {
        fprintf(stderr, "Error executing %s: %s\n", PACKAGE_NAME,
                strerror(errno));
    }

    return res;
}
