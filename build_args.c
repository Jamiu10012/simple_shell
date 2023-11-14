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
