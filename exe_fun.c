#include "shell.h"
/**
 * exe_fun - function that executes the command sent to the shell
 * @Token: letter
 * @search: the command to be looked for
 * Return: 1
 */
int exe_fun(char **Token, char *search)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid == 0)
	{
	if ((access(search, X_OK | F_OK) == 0) == 1)
	{
		execve(Token[0], Token, NULL);
	}
	else
	{
		free(search);
		perror("./shell");
		exit(127);
	}
	}
	else
		waitpid(child_pid, &status, 0);
	return (0);
}
