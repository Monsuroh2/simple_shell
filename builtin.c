#include "header.h"
/**
 * built_in - takes the string and args and check it through the env.
 * @get: string that is being passed
 * @env: args that are being passed.
 * Return: 0 if Success else -1
 **/

int built_in(char *get, list *env)
{

	int args, x;
	char *token;

	builtin b[] = {

		{"cd", _cd},
		{"env", _e},
		{"setenv", _set},
		{"unsetenv", _unset},
	};

	args = _strn(get);

	token = _strtok(get, " ");

	for (x = 0; x < 4; x++)
	{
		if (_strcmp(b[x].command, token) == 0)
		{

			if (args == 1)
			{
				b[x].func("", args, env);
			}
			else
			{
				token = _strtok(NULL, "\n");
				if (b[x].func(token, args, env) == -1)
					return (-1);
			}
			return (0);
		}
	}

	return (-1);
}
/**
 * _cd - takes the string and args and check it through the env.
 * @s: string that is being passed
 * @args: args that are being passed.
 * @env: list that is reference with the outside env.
 * Return: int
 **/

int _cd(char *s, int args, list *env __attribute__((unused)))
{

	int x;

	if (args > 2)
	{
		return (-1);
	}
	if (args == 1)
	{
		chdir("..");
	}

	if (_strcmp(s, "-") == 0)
		chdir("..");
	else
	{
		x = chdir(s);
		if (x == -1)
			return (-1);
	}
	return (0);
}
/**
 * _set - set the string and args and check it through the env.
 * @s: string that is being passed
 * @args: args that are being passed.
 * @env: list that is reference with the outside env.
 * Return: int
 **/
int _set(char *s, int args, list *env)
{
	char *var;
	char *val;
	char *str;
	int len = _strlen(s) + 1;
	list *temp = env;

	if (args != 3)
	{
		return (-1);
	}
	var = _strtok(s, " ");

	val  = _strtok(NULL, " ");

	str = malloc(len * sizeof(char));

	_strcpy(str, var);
	_strcat(str, "=");
	_strcat(str, val);


	while (env)
	{
		if (_strncmp(env->s, var, _strlen(var)) == 0)
		{
			env->s = _strdup(str);
			free(str);
			return (0);
		}
		env = env->next;

	}

		env = add_node_end(&temp, str);

		return (0);

}
/**
 * _unset - takes the string and args and check it through the env.
 * @s: string that is being passed
 * @args: args that are being passed.
 * @env: unset the env.
 * Return: int
 **/

int _unset(char *s, int args, list *env)
{
	char *var;
	int x;
	list *temp = env;

	if (args != 2)
	{
		return (-1);
	}

	var = _strtok(s, " ");

	for (x = 0; env; x++)
	{
		if (_strncmp(env->s, var, _strlen(var)) == 0)
		{
			delete_node(&temp, x);
			break;
		}
		env = env->next;
	}

	return (0);
}

