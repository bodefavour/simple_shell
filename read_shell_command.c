#include "shell.h"

void read_favour_command(char *sh_in_command, size_t size_s)
{
    if (fgets(in_command, size_s, stdin) == NULL)
    {
        if (feof(stdin))
        {
            favour_print("\n");
            exit(EXIT_SUCCESS);
        }
        else
        {
            favour_print("Error reading command.\n");
            exit(EXIT_FAILURE);
        }
    }
    in_command[strcspn(in_command, "\n")] = '\0';
}