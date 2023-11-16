#include "shell.h"

/**
* execute_command - Execute a command
*
* @command_path: The full path to the command to execute
* @arguments: An array of arguments to pass to the command.
*
* Return: Always 0 if command is successfully executed or -1 if otherwise.
*/

int execute_command(char *command_path, char **arguments)
{
pid_t child_pid = fork();
if (child_pid == 0)
{
execvp(command_path, arguments);
perror("Error executing command");
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("Fork failed");
}
else
{
wait(NULL);
}
return (-1);
}
