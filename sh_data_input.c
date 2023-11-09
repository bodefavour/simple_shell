#include "s_shell.h"

/**
 * read_favour_command - function that reads a command from the shell
 * 
 * @sh_in_command: command to read
 * @size_s: size of the command
 * Return: void
*/

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
    in_command[strcspn(sh_in_command, "\n")] = '\0';
}