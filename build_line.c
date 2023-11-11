#include "shell.h"

#define BUFFER_SIZE 1024

/**
* custom_getline - Read a line from standard input.
*
* Return: A pointer to the string containing the input line.
*         NULL if end of file is reached or an error occurs.
*/
char *custom_getline(void)
{
static char buffer[BUFFER_SIZE];
static int buffer_index;
static int buffer_size;

char *line = NULL;
int line_index = 0;
char current_char;

if (buffer_index >= buffer_size)
{
buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
if (buffer_size <= 0)
{
return (NULL);
}
buffer_index = 0;
}
line = (char *)malloc(BUFFER_SIZE * sizeof(char));

while (buffer_index < buffer_size)
{
current_char = buffer[buffer_index++];
if (current_char == '\n' || current_char == EOF)
{
/* End of line */
line[line_index] = '\0';
break;
}
else
{
line[line_index++] = current_char;
}
if (line_index % BUFFER_SIZE == 0)
{
line = (char *)realloc(line, (line_index + BUFFER_SIZE) * sizeof(char));
}
}
line = (char *)realloc(line, (line_index + 1) * sizeof(char));

return (line);
}

/**
* main - Entry point for the simple shell program.
*
* Return: Always returns 0.
*/
int main(void)
{
char *line;

while ((line = custom_getline()) != NULL)
{
/* For simplicity, this example just prints the line */

write(STDOUT_FILENO, "You entered: ", 13);
write(STDOUT_FILENO, line, strlen(line));
write(STDOUT_FILENO, "\n", 1);

/* Free the memory allocated for the line */
free(line);
}

return (0);
}
