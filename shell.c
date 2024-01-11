#include "shell.h"
/**
 * _exec - Entry point
 * @command: parameter
 */

void _exec(char *command)
{
	pid_t pid, wpid;
	int status;

pid = fork();

if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}

if (pid == 0)
{

char *args[2];
args[0] = command;
args[1] = NULL;

if (execve(command, args, NULL) == -1)
{
	perror("./shell");
	exit(EXIT_FAILURE);
}
}
else
{

do {
wpid = waitpid(pid, &status, WUNTRACED);
if (wpid == -1)
{
perror("waitpid");
exit(EXIT_FAILURE);
}
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}

