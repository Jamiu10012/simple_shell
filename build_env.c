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
