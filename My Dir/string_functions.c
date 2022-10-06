#include "monty.h"
/**
 * strcmp - function to compare two strings
 * @str1: string1
 * @str2: string2
 * Return: 0 of string are equals
 *         another value if not equal
 */
int strcmp(char *str1, char *str2)
{
	int num;

	for (num = 0; str1[num] && str2[num]; num++)
		;
	if (str1[num] > str2[num])
		return (1);
	if (str1[num] < str2[num])
		return (-1);
	return (0);
}

/**
 * search - search if char is inside string
 * @s: string
 * @c: char to find
 * Return: 1 if success 0 if not
 */
int search(char *s, char c)
{
	int cont = 0;

	while (s[cont] != '\0')
	{
		if (s[cont] == c)
		{
			break;
		}
		cont++;
	}
	if (s[cont] == c)
		return (1);
	else
		return (0);
}

/**
 * stroky - tokenize string
 * @s: string
 * @d: delimiters
 * Return: first part
 */
char *stroky(char *s, char *d)
{
	static char *ultimo;
	int i = 0, j = 0;

	if (!s)
		s = ultimo;
	while (s[i] != '\0')
	{
		if (search(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			ultimo = s + i + 1;
			*ultimo = '\0';
			s = s + j;
			return (s);
		}
		else if (_sch(d, s[i]) == 0 && _sch(d, s[i + 1]) == 0)
			i++;
		else if (_sch(d, s[i]) == 0 && _sch(d, s[i + 1]) == 1)
		{
			ultimo = s + i + 1;
			*ultimo = '\0';
			ultimo++;
			s = s + j;
			return (s);
		}
		else if (_sch(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
