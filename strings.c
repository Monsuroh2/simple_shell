#include "header.h"
/**
 * _strdup - duplicate and malloc for the new string.
 * @str: targeted string.
  * Return: The completed string that is being duplicated.
  **/

char *_strdup(char *str)
{

	char *ar;
	unsigned int i;
	unsigned int length = 0;

	if (str == NULL)
		return (NULL);

	for (length = 0; str[length] != '\0'; length++)
		;
	length++;

	if (length < 1)
		return (NULL);

	ar = malloc((length + 1) * sizeof(char));

	if (ar == NULL)
	{
		free(ar);
		return (NULL);
	}

	for (i = 0; i < length; i++)
		ar[i] = str[i];

	ar[i] = '\0';

	return (ar);

}
/**
 * _strlen - measures the string lenght
 * @s: destination of the string.
 * Return: The count of the string.
 **/

int _strlen(char *s)
{
	int count;

	for (count = 0; s[count] != '\0'; count++)
	;
		return (count);
}
/**
 * _strcpy - string we are going to copy together.
 * @dest: destination of the string.
 * @src: source of the string.
 * Return: The completed copy string.
 **/

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (*src != '\0')
	{
		*(dest + i) = *(src);
		i++;
		src++;

	}
	*(dest + i) = '\0';
	return (dest);
}

/**
 * _strcat - string concat string together.
 * @dest: destination of the string.
 * @src: source of the string.
 * Return: The completed added string.
 **/

char *_strcat(char *dest, char *src)
{
	int length = 0;
	char *temp = dest;

	while (*temp != '\0')
	{
		temp++;
		length++;
	}
	while (*src)
	{
		*temp = *src;
		temp++;
		src++;
		length++;

	}
	*temp = '\0';
	temp = temp - length;
	return (dest);

}
