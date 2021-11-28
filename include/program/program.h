#ifndef __PROGRAM__
#define __PROGRAM__

/**
 * @brief Program configuration structure.
 */
struct program_configuration
{
    char *version; // Configuration version.
    int verbose;   // Marks verbose mode
};

/**
 * @brief Executes the program.
 * 
 * @param configuration Program configurtion.
 * @return int: Returns 0 on success and any other number on failure.
 */
int program(struct program_configuration *configuration);

#endif