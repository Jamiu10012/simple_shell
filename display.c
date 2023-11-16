#include "shell.h"

/**
 * display_prompt - Entry point to collect user input
 * @: calls the command_print to print the command, followed by a new line.
 *
 * Return: Always 0.
 */

void display_prompt(void)
{
	command_print("simple shell ");
	return (0);
}
