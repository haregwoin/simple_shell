#include "shell.h"

/**
 * main - executable
 * @argc: argument count
 * @argv: argument vector
 * Return: Exit success
 */
int main(int argc, char **argv)
{
	shell_loop();

	return (EXIT_SUCCESS);
}
