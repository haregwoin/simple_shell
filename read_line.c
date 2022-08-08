#include "shell.h"

/**
 * shell_readline - reads a line in the shell prompt
 * Return: Nothing
 */
char *shell_readline(void)
{
	int bufsize = SHELL_BUFSIZE;
	int pos = 0;
	char *buf = malloc(sizeof(char) * bufsize);
	int c;

	if (!buf)
	{
		fprintf(stderr, "shell: Failed to allocate\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		c = getchar();

		if (c == EOF || c == '\n')
		{
			buf[pos] = '\0';
			return (buf);
		}

		else
		{
			buf[pos] = c;
		}
		pos++;

		if (pos >= bufsize)
		{
			bufsize += SHELL_BUFSIZE;
			buf = realloc(buf, bufsize);

			if (!buf)
			{
				fprintf(stderr, "shell: Failed to allocate\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
