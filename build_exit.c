#include "shell.h"

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
char user_input[256];
pid_t pid;
char *args[2];

while (1)
{
printf("Shell> ");
fgets(user_input, sizeof(user_input), stdin);
if (user_input[strlen(user_input) - 1] == '\n')
{
user_input[strlen(user_input) - 1] = '\0';
}

if (strcmp(user_input, "exit") == 0)
{
exit_shell();
}
pid = fork();
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0) /* Child process */
{
args[0] = user_input;
args[1] = NULL;

if (execvp(user_input, args) == -1)
{
perror("execvp");
exit(EXIT_FAILURE);
}
}
else /* Parent process */
{
waitpid(pid, NULL, 0);
}
}
return (0);
}
