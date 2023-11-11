#include "shell.h"

#define MAX_COMMAND_LENGTH 1000
/**
 * build_command - Function to read and execute user command
 * @command: Display promt for user
 * Author: EmEch and Silent Coder
 */

void build_command(char *command)
{
printf("simple_shell> ");
fgets(command, MAX_COMMAND_LENGTH, stdin);
command[strcspn(command, "\n")] = '\0';
}

/**
 * main - Main function
 *
 * Return: Always 0.
 * Or Errno
 */

int main(void)
{
char command[MAX_COMMAND_LENGTH];
int status;
pid_t pid;

while (1)
{
build_command(command);

if (strlen(command) == 0)
{
continue;
}

pid = fork();

if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}

if (pid == 0)
{
if (execlp(command, command, NULL) == -1)
{
perror("execlp");
exit(EXIT_FAILURE);
}
}
else
{
wait(&status);
}
}

return (0);
}
