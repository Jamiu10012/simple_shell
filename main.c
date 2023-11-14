#include "shell.h"

/**
* main - Entry point for the simple shell program.
*
* Return: Always returns 0.
*/

int main(void)
{
char *command;
char cmd_path[MAX_PATH_LENGTH];
char *path = getenv("PATH");
char *path_dir[MAX_PATH_LENGTH / 2];

parsePath(path, path_dir);

while (1)
{
char user_input[MAX_INPUT_LENGTH];
getUserInput(user_input);
if (strcmp(user_input, "exit") == 0)
break;
command = strtok(user_input, " ");
if (command == NULL)
continue;
if (find_command(path_dir, command, cmd_path) == 0)
{
int arg_count = 0;
char *token = strtok(user_input, " ");
char *args[MAX_INPUT_LENGTH / 2];

while (token != NULL && arg_count < MAX_INPUT_LENGTH / 2 - 1)
{
args[arg_count++] = token;
token = strtok(NULL, " ");
}
args[arg_count] = NULL;
if (arg_count > 0)
{
execut_command(args);
}
}
else
{
printf("Command '%s' not found or not executable.\n", command);
}
}
return (0);
}

/**
* parsePath - ple
* @path: path
* @path_dir: dir
*/

void parsePath(char *path, char *path_dir[])
{
int i = 0;
char *token = strtok(path, ":");

while (token != NULL && i < MAX_PATH_LENGTH / 2 - 1)
{
path_dir[i++] = token;
token = strtok(NULL, ":");
}

path_dir[i] = NULL;
}

/**
* getUserInput - input
* @user_input: yser
*/
void getUserInput(char user_input[])
{
printf("$ ");
fgets(user_input, MAX_INPUT_LENGTH, stdin);
user_input[strcspn(user_input, "\n")] = '\0';
}
