/*
    The package should `#include' the configuration header file before any other
    header files, to prevent inconsistencies in declarations (for example, if it
    redefines const). Use `#include <config.h>' instead of
    `#include "config.h"', and pass the C compiler a `-I.' option
    (or `-I..'; whichever directory contains `config.h').
*/
#include <config.h> // Autotools configuration.

#include <my_program/common.h>
#include <my_program/my_program.h>

#include <argp.h>
#include <string.h>
#include <stdlib.h>

#define STD_OUTPUT stdout
#define ERR_OUTPUT stderr

const char *argp_my_program_version = PACKAGE_STRING;
const char *argp_my_program_bug_address = PACKAGE_BUGREPORT;
static char doc[] = "my_program description.";
static char args_doc[] = "my_program arguments.";
static struct argp_option options[] = {
    {0, 0, 0, 0, "my_program options:", 0},

    {0, 0, 0, 0, "General options:", -1},
    {"output", 'o', "Output pipe", 0, "Default output.", -1},
    {"erroutput", 200, "Output pipe", 0, "Default output.", -1},
    {"verbose", 'v', 0, 0, "Verbose mode.", -1},
    {"quiet", 'q', 0, 0, "Quiet mode.", -1},
    {"usage", 'u', 0, 0, "Prints ussage and exits.", -1},
    {"help", 'h', 0, 0, "Prints help and exits.", -1},
    {"version", 'V', 0, 0, "Prints version and exits.", -1},
    {0}};

static error_t my_arg_parser(int key, char *arg, struct argp_state *state)
{
    struct my_program_configuration *arguments = state->input;
    switch (key)
    {
    case 200:
        arguments->err_output = fopen(arg, "w");
        break;
    case 'o':
        arguments->std_output = fopen(arg, "w");
        break;
    case 'v':
        arguments->verbose = 1;
        break;
    case 'q':
        arguments->verbose = 0;
        break;
    case 'V':
        fprintf(stdout, "%s\n", argp_my_program_version);
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

void general_clean(int state, void *args)
{
    struct my_program_configuration *config =
        (struct my_program_configuration *)args;
    if (NULL != config->std_output)
        fclose(config->std_output);
    if (NULL != config->err_output)
        fclose(config->err_output);
}

/**
 * @brief Generates a command for my_program.
 *
 * @param argc Num of arguments.
 * @param argv Vector of arguments.
 * @return int Return state.
 */
int main(int argc, char *argv[])
{
    struct my_program_configuration configuration; // my_program configuration.
    unsigned int i;                                // Index.

// Enable/Disable my feature.
#ifdef ENABLE_MY_FEATURE
    printf("My feature enabled.\n");
#else
    printf("My feature non-enabled.\n");
#endif

    configuration.version = PACKAGE_VERSION; // Import version from autotools.
    configuration.verbose = 0;               // Default value.
    configuration.std_output = STD_OUTPUT;
    configuration.err_output = ERR_OUTPUT;

    // Parses arguments.
    if (0 != argp_parse(&argp, argc, argv, ARGP_NO_HELP, NULL, &configuration))
    {
        fprintf(stderr, "Error parsing arguments: %s.\n", strerror(errno));
    }

    // Triggers a function before the program closes.
    on_exit(general_clean, &configuration);

    // Executes my_program.
    if (0 != (my_program(&configuration)))
    {
        fprintf(configuration.err_output, "Error executing %s: %s.\n", PACKAGE_NAME,
                strerror(errno));
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
