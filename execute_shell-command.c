#include "s_shell.h"

/**
 * execute_sh_command - function that executes a shell command
 * 
 * @sh_in_command: command to execute
 * Return: void
*/
void execute_sh_command(const char *sh_in_command)
{
    pid_t child_pid = fork();

    if (child_pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (child_pid == 0)
    {
	    const char *args[] = {NULL, NULL};
	    args[0]=sh_in_command;

	    if (execve(sh_in_command, (char *const *)args, NULL) == -1)
	    {
		    perror("execve");
		    exit(EXIT_FAILURE);
	    }
    }
    else
    {
        int status;
	waitpid(child_pid, &status, 0);

	if (WIFEXITED(status))
	{
		printf("Child process exited with status %d\n", WEXITSTATUS(status));
	}
	else
	{
		fav_print("Child process terminated somehow abnormally\n");
	}
    }
}
