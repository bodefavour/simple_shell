#include "s_shell.h"

/**
 * fav_print - function that prints a message
 * 
 * @sh_in_message: message to print
 * Return: void
*/

void fav_print(const char *sh_in_message)
{
            write(STDOUT_FILENO, sh_in_message, strlen(sh_in_message));
}