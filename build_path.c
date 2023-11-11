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
for (int i = 0; directories[i] != NULL; i++)
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
/**
* main - main function of the code
*
* Return: Always 0.
*/
int main(void)
{
char *path = getenv("PATH");
char *path_dir[MAX_PATH_LENGTH / 2];
char *token = strtok(path, ":");
int i = 0;
while (token != NULL)
{
path_dir[i++] = token;
token = strtok(NULL, ":");
}
path_dir[i] = NULL;

while (1)
{
char user_input[MAX_INPUT_LENGTH];
printf("$ ");
fgets(user_input, MAX_INPUT_LENGTH, stdin);
user_input[strcspn(user_input, "\n")] = '\0';

if (strcmp(user_input, "exit") == 0)
break;

char *command = strtok(user_input, " ");
if (command == NULL)
continue;

char cmd_path[MAX_PATH_LENGTH];
if (find_command(path_dir, command, cmd_path) == 0)
{
char **arguments = (char **)malloc(MAX_INPUT_LENGTH * sizeof(char *));
execute_command(cmd_path, arguments);
}
else
{
printf("Command '%s' not found or not executable.\n", command);
}
}
return (0);
}
