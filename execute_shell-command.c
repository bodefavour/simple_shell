#include "s_shell.h"

/**
 * execute_sh_command - function that executes a shell command
 * 
 * @sh_in_command: command to execute
 * Return: void
*/
void execute_sh_command(const char*sh_in_command)
{
    pid_t child_pid = fork();

    if (child_pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (child_pid == 0)
    {
        if (execlp(sh_in_command, sh_in_command, NULL) == -1)
        {
            perror("execlp");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        wait(NULL);
    }

}
