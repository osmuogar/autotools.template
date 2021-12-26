#ifndef __MY_PROGRAM__
#define __MY_PROGRAM__

/**
 * @brief my_program configuration structure.
 */
struct my_program_configuration
{
    char *version;     // Configuration version.
    int verbose;       // Marks verbose mode.
    char *output_path; // Output path.
};

/**
 * @brief Executes my_program.
 *
 * @param configuration my_program configurtion.
 * @return int: Returns 0 on success and any other number on failure.
 */
int my_program(struct my_program_configuration *configuration);

#endif