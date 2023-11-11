#include "shell.h"

/**
* execute_env - Execute the env command.
*/
void execute_env(void)
{

int i;
for (i = 0; environ[i] != NULL; i++)
{
printf("%s\n", environ[i]);
}
}

/**
* execute_mycommand - Execute the mycommand command.
*/
void execute_mycommand(void)
{
printf("Executing mycommand...\n");
/* Add your implementation for the mycommand built-in here */
}

/**
* main - The main function.
*
* Return: Always 0.
*/
int main(void)
{
char input[100]; /* Assuming a maximum input length of 100 characters */

printf("Enter a command (env or mycommand): ");
scanf("%s", input);

if (strcmp(input, "env") == 0)
{
execute_env();
}
else if (strcmp(input, "mycommand") == 0)
{
execute_mycommand();
}
else
{
printf("Unknown command: %s\n", input);
}

return (0);
}
