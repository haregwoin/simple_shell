#include "shell.h"

/**
 * shell_loop - runs the loop of the shell
 * Return: Nothing
 */
void shell_loop(void)
{
	char *line;
	char **args;
	int stats;

	do {
		printf("> ");
		line = shell_readline();
		args = shell_splitline(line);
		stats = shell_execute(args);

		free(line);
		free(args);

	} while (stats);
}
