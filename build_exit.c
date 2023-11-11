#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

/**
 * exit_shell - Exits the shell.
 */
void exit_shell(void)
{
	printf("Exiting the shell.\n");
	exit(0);
}

/**
 * main - The main function for the simple shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
	char user_input[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("Shell> ");
		fgets(user_input, sizeof(user_input), stdin);
		/* Remove the newline character from user input */
		if (user_input[strlen(user_input) - 1] == '\n')
		{
			user_input[strlen(user_input) - 1] = '\0';
		}

		/* Check if the command is 'exit' */
		if (strcmp(user_input, "exit") == 0)
		{
			exit_shell();
		}
		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0) /* Child process */
		{
			char *args[] = {user_input, NULL};

			execve(user_input, args, NULL);

			/* If execve fails, print an error */
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else /* Parent process */
		{
			waitpid(pid, NULL, 0);
		}
	}
	return (0);
}
