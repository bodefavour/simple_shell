#include "s_shell.h"

/**
 * main - function that runs the shell
 * 
 * Return: 0 on success
*/

int main(void)
{
    char s_h_command[1024];

    while (true)
    {
        s_h_prompt();
        read_favour_command(s_h_command, sizeof(s_h_command));
        fav_print(s_h_command);
    }
}