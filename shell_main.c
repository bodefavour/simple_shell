#include "s_shell.h"

/**
 * main - function that runs the shell
 * 
 * Return: 0 on success
*/

int main(void)
{
    char in_command[1024];

    while (1)
    {
        s_h_prompt();
        read_favour_command(in_command, sizeof(in_command));
        if (strcmp(in_command, "exit") == 0)
            break;

        execute_sh_command(in_command);
    }

    return 0;
}
