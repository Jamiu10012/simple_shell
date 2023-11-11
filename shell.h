#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_PATH_LENGTH 1024
#define MAX_INPUT_LENGTH 1024
#define COMMAND_LENGTH 100
#define BUFFER_SIZE 1024

extern char **environ;

void build_command(char *command);
void execute_mycommand(void);
void execute_env(void);
void exit_shell(void);
int find_command(char **directories, char *command, char *buffer);
int execute_command(char *command_path, char **arguments);
char *custom_getline(void);
void execut_command(char **args);

#endif
