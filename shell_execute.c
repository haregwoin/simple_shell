#include "shell.h"

/**
 * shell_execute - used to launch a builtin or a process
 * @args: argument vector
 * Return: process or builtins
 */
int shell_execute(char **args)
{
	int i;

	if (args[0] == NULL)
	{
		return (1);
	}

	for (i = 0; i < shell_num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}

	return (shell_launch(args));
}
