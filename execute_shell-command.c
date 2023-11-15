#include "s_shell.h"

/**
 * execute_sh_command - function that executes a shell command
 *
 * @sh_in_command: command to execute
 * @args: argument to be passed
 * Return: void
*/

void execute_sh_child_process(const char *sh_in_command, const char *args[]);
void search_cm_and_execute(const char *sh_in_command, const char *args[]);

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

		args[0] = sh_in_command;
		search_cm_and_execute(sh_in_command, args);
	}
	else
	{
		int status;

		if (waitpid(child_pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
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

/**
 * execute_sh_child_process - function that excute child process
 *
 * @sh_in_command: command to execute
 * @args: argument to be passed
 * Return: void
*/

void execute_sh_child_process(const char *sh_in_command, const char *args[])
{
	if (execve(sh_in_command, (char *const *)args, NULL) == -1)
	{
		perror("execve");

		exit(EXIT_FAILURE);
	}
}

/**
 * search_cm_and_execute - function that search for commands and execute them
 *
 * @sh_in_command: command to execute
 * @args: argument to be passed
 * Return: void
*/

void search_cm_and_execute(const char *sh_in_command, const char *args[])
{
	char *path = getenv("PATH");
	char *token, *sh_in_command_path = NULL;

	if (path != NULL)
	{
		path = strdup(path);
		token = strtok(path, ":");

		while (token != NULL)
		{
			sh_in_command_path = malloc(strlen(token) + strlen(sh_in_command) + 2);
			if (sh_in_command_path == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			sprintf(sh_in_command_path, "%s%s", token, sh_in_command);

			if (access(sh_in_command_path, X_OK) == 0)
			{
				args[0] = sh_in_command_path;
				execute_sh_child_process(sh_in_command_path, args);
				free(sh_in_command_path);
				token = strtok(NULL, ":");
			}
			free(path);
		}

		perror("command not found");
		exit(EXIT_FAILURE);
	}
}
