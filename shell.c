#include "shell.h"

/**
 * main - Entry point of the program.
 * @n: The number of parameters passed to the executable file. In the case
 * this variable will not be used.
 * @m: The name of the program.
 * Return: Always 0.
 */

int main(__attribute__((unused)) int n, char **m)
{
	char *line;
	size_t size;
	int command_counter;

	command_counter = 0;
	signal(SIGINT, SIG_IGN);
	do {
		command_counter++;
		line = NULL;
		size = 0;
		parse_line(line, size, command_counter, m);

	} while (1);

	return (0);
}
