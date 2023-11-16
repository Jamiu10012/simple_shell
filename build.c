#include "shell.h"
#define MAX_COMMAND_LENGTH 100
/**
 * command_print - Read and print out user input at entry point
 * @command: Display promt for user
 * Author: EmEch and Silent Coder
 */

void command_print(const char *command)
{
write(1, command, strlen(command));
fgets(command, MAX_COMMAND_LENGTH, stdin);
command[strcspn(command, "\n")] = '\0';
}
