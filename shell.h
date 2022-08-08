#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#define SHELL_BUFSIZE 1024
#define SHELL_TBUFSIZE 64
#define SHELL_TDELIM " \t\r\n\a"

char *builtin_str[] = {
    "cd",
    "help",
    "exit"
};

void shell_loop(void);
char *shell_readline(void);
char **shell_splitline(char *line);
int shell_launch(char **args);
int shell_cd(char **args);
int shell_help(char **args);
int shell_exit(char **args);
int shell_num_builtins(void);

int (*builtin_func[])(char **) = {
	&shell_cd,
	&shell_help,
	&shell_exit
};

#endif
