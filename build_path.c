#include "shell.h"

#define MAX_PATH_LENGTH 1024
#define MAX_INPUT_LENGTH 1024
#define COMMAND_LENGTH 100

/**
* find_command - Find and read command in the given directories
*
* @directories: A list of directories to search for the command.
* @command: The command to search for
* @buffer: The buffer to store the full path to the command
*
* Return: Always 0. if the command is not found, -1 if otherwise.
*/

int find_command(char **directories, char *command, char *buffer)
{
	int i;
for (i = 0; directories[i] != NULL; i++)
{
char path[MAX_PATH_LENGTH];
strcpy(path, directories[i]);
strcat(path, "/");
strcat(path, command);

if (access(path, F_OK) == 0)
{
strcpy(buffer, path);
return (0);
}
}

return (-1);
}
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
pid_t pid = fork();
if (pid == 0)
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
return (0);
}
