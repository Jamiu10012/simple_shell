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
