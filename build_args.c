#include "shell.h"

#define MAX_COMMAND_LENGTH 1000

/**
 * build_command_args - command arguments
 * @command args: Handles all arguments in commands
 * Author by EmEch and Silent Coder
 */

void build_command_args(char *command)
{
printf("simple_shell> ");
fgets(command, MAX_COMMAND_LENGTH, stdin);
command[strcspn(command, "\n")] = '\0';
}

/**
 * execute_command - execute command
 * @args: Handles and executes arguments
 */

void execut_command(char **args)
{
pid_t pid = fork();
if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
perror("execlp");
exit(EXIT_FAILURE);
}
}
else if (pid < 0)
{
perror("fork");
}
else
{
wait(NULL);
}
}

/**
 * main - Reads command  length and size
 * Author: EmEch and SilentCoder
 * Return: Always 0.
 * Or Errno upon Failure
 */

int main(void)
{
char command[MAX_COMMAND_LENGTH];
while (1)
{
build_command_args(command);
if (strcmp(command, "exit") == 0)
{
printf("See you again!\n");
break;
}
if (strlen(command) > 0)
{
int arg_count = 0;
char *token = strtok(command, " ");
char *args[MAX_COMMAND_LENGTH];
while (token != NULL)
{
args[arg_count] = token;
arg_count++;
token = strtok(NULL, " ");
}
args[arg_count] = NULL;
if (arg_count > 0)
{
execut_command(args);
}
}
}
return (0);
}
