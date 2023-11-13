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
