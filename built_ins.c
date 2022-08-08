#include "shell.h"

/**
 * shell_num_builtins - function to find the number of builtin functions
 * Return: Number of builtins
 */
int shell_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

/**
 * shell_cd - change working directory
 * @args: argument vector
 * Return: 1
 */
int shell_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "shell: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("shell");
		}
	}
	return (1);
}

/**
 * shell_help - prints the help information of the shell
 * @args: Number of arguments
 * Return: 1
 */
int shell_help(char **args)
{
	int i;

	printf("Edward Jr Agyemang - Prempeh and  haregwoin asrat kassa asrat\n");
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");

	for (i = 0; i < shell_num_builtins(); i++)
	{
		printf(" %s\n", builtin_str[i]);
	}

	printf("Use the man command for information on available programs.\n");
	return (1);
}

/**
 * shell_exit - exits the shell
 * @args: Argument vector
 * Return: 0 on exit
 */
int shell_exit(char **args)
{
	return (0);
}
