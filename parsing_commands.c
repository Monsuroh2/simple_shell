#include "shell.h"

/**
 * parse_line - Parses the command line looking for commands and argumements.
 * This function it is also in charged of freeing memory that is not longer
 * needed by the program.
 * @l: A pointer to a string. Will always be NULL upon function entry.
 * @s: A holder for numbers of size_t. Will always be initilized to 0.
 * @command_counter: A counter keeping track of how many commands have been
 * entered into the shell.
 * @m: Name of the program running the shell
 */

void parse_line(char *l, size_t s, int command_counter, char **m)
{
	int i;
	ssize_t read_len;
	int token_count;
	char **param_array;
	const char *delim = "\n\t ";

	token_count = 0;
	write(STDOUT_FILENO, PROMPT, str_len(PROMPT));
	read_len = getline(&l, &s, stdin);
	if (read_len != -1)
	{
		param_array = token_interface(l, delim, token_count);
		if (param_array[0] == NULL)
		{
			single_free(2, param_array, l);
			return;
		}
		i = built_in(param_array, l);
		if (i == -1)
			create_child(param_array, l, command_counter, m);
		for (i = 0; param_array[i] != NULL; i++)
			free(param_array[i]);
		single_free(2, param_array, l);
	}
	else
		exit_b(l);
}

/**
 * create_child - Creates a child in order to execute another program.
 * @param_array: An array of pointers to strings containing the possible name
 * of a program and its parameters. This array is NULL terminated.
 * @l: The contents of the read line.
 * @count: A counter keeping track of how many commands have been entered
 * into the shell.
 * @m: Name of the program running the shell
 */

void create_child(char **param_array, char *l, int count, char **m)
{
	pid_t id;
	int status;
	int i;
	int check;
	struct stat buf;
	char *tmp_command;
	char *command;

	id = fork();
	if (id == 0)
	{
		tmp_command = param_array[0];
		command = path_finder(param_array[0]);
		if (command == NULL)
		{
			/*Looking for file in current directory*/
			check = stat(tmp_command, &buf);
			if (check == -1)
			{
				error_printing(m[0], count, tmp_command);
				print_str(": not found", 0);
				single_free(2, l, tmp_command);
				for (i = 1; param_array[i]; i++)
					free(param_array[i]);
				free(param_array);
				exit(100);
			}
			/*file exist in cwd or has full path*/
			command = tmp_command;
		}
		param_array[0] = command;
		if (param_array[0] != NULL)
		{
			if (execve(param_array[0], param_array, environ) == -1)
				exec_error(m[0], count, tmp_command);
		}
	}
	else
		wait(&status);
}

/**
 * token_interface - Meant to interact with other token functions, and make
 * them more accessible to other parts of the program.
 * @l: A string containing the raw user input.
 * @delim: A constant string containing the desired delimeter to tokenize line.
 * @token_count: A holder for the amount of tokens in a string.
 * Return: Upon success an array of tokens representing the command. Otherwise
 * returns NULL.
 */

char **token_interface(char *l, const char *delim, int token_count)
{
	char **param_array;

	token_count = count_token(l, delim);
	if (token_count == -1)
	{
		free(l);
		return (NULL);
	}
	param_array = tokenize(token_count, l, delim);
	if (param_array == NULL)
	{
		free(l);
		return (NULL);
	}

	return (param_array);
}

/**
 * tokenize - Separates a string into an array of tokens. DON'T FORGET TO FREE
 * on receiving function when using tokenize.
 * @token_count: An integer representing the amount of tokens in the array.
 * @l: String that is separated by an specified delimeter
 * @delim: The desired delimeter to separate tokens.
 * Return: Upon success a NULL terminated array of pointer to strings.
 * Otherwise returns NULL.
 */

char **tokenize(int token_count, char *l, const char *delim)
{
	int i;
	char **buffer;
	char *token;
	char *line_cp;

	line_cp = _strdup(l);
	buffer = malloc(sizeof(char *) * (token_count + 1));
	if (buffer == NULL)
		return (NULL);
	token = strtok(line_cp, delim);
	for (i = 0; token != NULL; i++)
	{
		buffer[i] = _strdup(token);
		token = strtok(NULL, delim);
	}
	buffer[i] = NULL;
	free(line_cp);
	return (buffer);
}

/**
 * count_token - Counts tokens in the passed string.
 * @l: String that is separated by an specified delimeter
 * @delim: The desired delimeter to separate tokens.
 * Return: Upon success the total count of the tokens. Otherwise -1.
 */

int count_token(char *l, const char *delim)
{
	char *str;
	char *token;
	int i;

	str = _strdup(l);
	if (str == NULL)
		return (-1);
	token = strtok(str, delim);
	for (i = 0; token != NULL; i++)
		token = strtok(NULL, delim);
	free(str);
	return (i);
}
