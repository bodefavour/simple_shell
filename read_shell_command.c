#include "s_shell.h"

void read_favour_command(char *sh_in_command, size_t size_s)
{
    if (fgets(sh_in_command, size_s, stdin) == NULL)
    {
        if (feof(stdin))
        {
            fav_print("\n");
            exit(EXIT_SUCCESS);
        }
        else
        {
            fav_print("Error reading command.\n");
            exit(EXIT_FAILURE);
        }
    }
    sh_in_command[strcspn(sh_in_command, "\n")] = '\0';
}
