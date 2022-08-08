#include "shell.h"

/**
 * shell_splitline - parses shell input
 * @line: The input line
 * Return: Token
 */
char **shell_splitline(char *line)
{
	int bufsize = SHELL_TBUFSIZE, pos = 0;
	char **t = malloc(bufsize * sizeof(char *));
	char *tk;

	if (!t)
	{
		fprintf(stderr, "shell: Failed to allocate\n");
		exit(EXIT_FAILURE);
	}

	tk = strtok(line, SHELL_TDELIM);
	while (tk != NULL)
	{
		t[pos] = tk;
		pos++;

		if (pos >= bufsize)
		{
			bufsize += SHELL_TBUFSIZE;
			t = realloc(t, bufsize * sizeof(char *));
			if (!t)
			{
				fprintf(stderr, "shell: Failed to allocate\n");
				exit(EXIT_FAILURE);
			}
		}

		tk = strtok(NULL, SHELL_TDELIM);
	}
	t[pos] = NULL;
	return (tk);
}
