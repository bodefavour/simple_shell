#include "s_shell.h"

/**
 * env_buil_tin - function that prints the current environment
 *
 * @environ: Pointer to the environment variable
 * Return: void
 */


void env_buil_tin(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		fav_print(*env);
		fav_print("\n");
		env++;
	}
}
