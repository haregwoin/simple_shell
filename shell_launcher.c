#include "shell.h"

/**
 * shell_launch - use to launch shell
 * @args: argument vector
 * Return: 1
 */
int shell_launch(char **args)
{
	pid_t pid, wpid;
	int stats;

	pid = fork();

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
			perror("shell");
		exit(EXIT_FAILURE);
	}

	else if (pid < 0)
		perror("shell");
	else
	{
		do {
			wpid = waitpid(pid, &stats, WUNTRACED);
		} while (!WIFEXITED(stats) && !WIFSIGNALED(stats));
	}

	return (1);
}
