#include "shell.h"
/**
 * main - Main entry point for the shell program
 * @argc: Argument count parameter
 * @argv: pointer to array of argument values
 *
 * Return: 0 Always (Success)
 */

int main(int argc, char *argv[])
{
(void)argc;
(void)argv;
char *buffer = NULL;
size_t count = 0;
ssize_t readings;
pid_t pid;
int state;
char *token;
char **arr_str;
int i;

while (1)
{
	write(STDOUT_FILENO, "cisfun$ ", 8);

	readings = getline(&buffer, &count, stdin);
	if (readings == -1)
	{
		perror("Error: Exiting program...");
		exit(1);
	}

	token = strtok(buffer, " \n");

	arr_str = malloc(sizeof(char *) * MAX_VALUE);
	i = 0;
	while (token)
	{
		arr_str[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}
	arr_str[i] = NULL;

	pid = fork();
	if (pid == -1)
	{
	perror("Failed to create a child process");
	exit(41);
	}
	if (pid == 0)
	{
		/**printf("PID created successfully\n");**/
		if (execve(arr_str[0], arr_str, NULL) == -1)
		{
			perror("./shell");
			exit(97);
		}
	}
	else
	{
	wait(&state);
	}
}
free(buffer);
return (0);
}
