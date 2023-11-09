#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LENGTH 1024
#define MAX_INPUT_LENGTH 1024
#define COMMAND_LENGTH 100

/* find the command in specified directories */
int find_command(char *command, char **directories, char *buffer)
{
	for (int e = 0, path_dir[e] != NULL; ++)
	{
		char path[BUFFER SIZE]
			
		strcpy(path, directories[e]);
		strcat(path, "/");
		strcat(path, cmd);
		
		if (access(path, cmd, X_OK) == 0)
	{
		strcpy(buffer, path);
		return;
	}
	}
/* Taking maximum of 2 directories in PATH */
int main(void)
{
	char buffer[BUFFER SIZE];

	char *command
	char **arguments;
	char *path = getenv("PATH");
	char *path_dir[MAX_PATH_LENGTH / 2];
	char *token = strtok(path, ":");
	int i = 0;
while (token != NULL)
	{
		path_dir[i++] = token;
		token = strtok(NULL, ":");
	}
	path_dir[e] = NULL;
while
	{
	char user_input[MAX_INPUT_LENGTH];
	printf("$ ");
/* Read user input and length */
	fgets(user_input, MAX_INPUT_LENGHT, stdin);
/* Remove the newline character */	
	user_input[strcspn(user_input, "\n")] = '\0';
	}
if (strcmp(user_input, "exit") == 0)
	{
	break;
	}
	char *command = strtok(user_input, " ");
	if (command == NULL)
	{
		continue;
	}

	char cmd_path[MAX_LENGTH};
	find_command (path_dir, command, cmd_path);
	if (cmd_path[0] != '\0')
	{
		pid_t pid = fork();
		if (pid == 0)
		{
			execvp(cmd_path, &command);
			perror("Error command, execvp");
			exit(EXIT_FAILURE);
		}

		else if (pid < 0)
		{
			perror("fork");
		}
		else
		{
			wait(NULL);
		}
		else
		{
			printf("Command '%s' not found or not executable.\n", command);
		}
	}
	return (0);
}
