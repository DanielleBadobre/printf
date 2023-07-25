#include "main.h"
/**
 * buffer - defines buffer
 * @s: buffer
 * @x: char to print
 * @index: actual position
 * Return: funcion
 */
void buffer(char *s, char x, int *index)
{
	s[*index] = x;
	*index = *index + 1;
	if (*index == 1024)
	{
		write(1, s, *index);
		*index = 0;
	}
}
/**
 * getfunction - gets fum=nction
 * @c: char to find
 * Return: function
 */
int (*getfunction(char c))(va_list a, char *s, int *index)
{
	int c1;
	choose l[] = {
		{'c', print_c}, {'s', print_s}, {'%', print_por}, {'i', print_id},
		{'d', print_id}, {'b', print_bin}, {'u', print_u}, {'o', print_o},
		{'x', print_x}, {'X', print_X}, {'S', print_S}, {'R', print_R},
		{'r', print_r}, {'p', print_p}, {'\0', NULL}
	};
	for (c1 = 0; l[c1].c != '\0'; c1++)
	{
		if (c == l[c1].c)
			return (l[c1].p);
	}
	return (NULL);
}
/**
 * _printf - prints
 * @format: format of argument
 * Return: string
 */
int _printf(const char *format, ...)
{
	int c1 = 0, w = 0, x = -1, (*f)(va_list, char *s, int *m);
	int *index;
	char *s;
	va_liste elements;

	va_start(elements, format);
	s = malloc(1024);
	index = &w;
	if (!s)
		return (-1);
	if (format)
	{
		x = 0;
		for (; format[c1] != '\0'; c1++, x++)
		{
			if (format[c1] != '%')
				buffer(s, format[c1], index);
			else if (format[c1] == '%' && format[c1 + 1] == '\0')
				return (-1);
			else if (format[c1] == '%' && format[c1 + 1] != '\0')
			{
				f = getfunction(format[c1 + 1]);
				if (f)
				{
					x = (x + f(elements, s, index)) - 1;
					c1++;
				}
				else
					buffer(s, format[c1], index);
			}
		}
	}
	if (*index != 1024)
		write(1, s, *index);
	free(s);
	va_end(elements);
	return (x);
}
