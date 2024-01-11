#include "shell.h"
/**
 * main- Entry point
 * Return: 0 Always
 */




int main(void)
{
char *input = NULL;
size_t len;

while (1)
{
	write(STDOUT_FILENO, "cisfun$ ", 8);
	if (getline(&input, &len, stdin) == -1)
	{
	perror("Error reading input");
	exit(EXIT_FAILURE);
	}

	if (input[0] == '\n')
	continue;

	input[strlen(input) - 1] = '\0';

	if (strcmp(input, "exit") == 0)
	break;

_exec(input);
}
free(input);
return (0);
}
