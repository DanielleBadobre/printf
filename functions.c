#include "main.h"
/**
 * print_c - print characters
 * @a: element of valist
 * @s: buffer
 * @index: position
 * Return: number of characters
 */
int print_c(va_list a, char *s, int *index)
{
	int x;

	x = va_arg(a, int);
	buffer(s, x, index);
	return (1);
}
/**
 * print_s - print string
 * @a: element of valist
 * @s: buffer
 * @index: position
 * @Return: number of character
 */
int print_s(va_list a, char *s, int *index)
{
	char *x;
	int y = 0;
	int c = 0;

	x = va_arg(a, char *);
	if (!x)
		x = "(null)";
	while (x[c])
	{
		buffer(s, x[c], index);
		c++;
		y++;
	}
	return (y);
}
/**
 * print_por - print %
 * @a: valist
 * @s: buffer
 * @index: position on buffer
 * Return: number of char
 */
int print_por(va_list a, char *s, int *index)
{
	(void)a;
	buffer(s, '%', index);
	return (1);
}
/**
 * print_id - print num
 * @a: valist
 * @s: buffer
 * @index: position
 * @Return: num
 */
int print_id(va_list a, char *s, int *index)
{
	unsigned int j, cont = 1;
	unsigned int var1, num, var2, var3 = 1;
	int x, y = 0;

	x = va_arg(a, int);
	var2 = x;
	if (x < 0)
	{
		buffer(s, '-', index);
		var2 = x * (-1);
		y++;
	}
	num = var2;
	while (num > 9)
	{
		num = num / 10;
		cont++;
		var3 = var3 *10;
	}
	for (j = 1; j <= cont; j++)
	{
		var1 = var2 / var3;
		var2 = var2 % var3;
		var3 = var3 / 10;
		y++;
		buffer(s, ('0' + var1), index);
	}
	return (y);
}
/**
 * print_bin - prints binary
 * @a: valist
 * @s: buffer
 * @index: position
 * Return: num
 */
int print_bin(va_list a, char *s, int *index)
{
	int x, c, d, y = 0, aux = 0;
	int arr[32] = {0};

	aux = va_arg(a, int);
	x = aux;
	if (aux == 0)
	{
		buffer(s, '0', index);
		return (1);
	}
	if (aux < 0)
		x = -(x + 1);
	for (c = 0; x > 0; c++)
	{
		arr[c] = x % 2;
		x = x / 2;
	}
	if (aux >= 0)
	{
		for (d = c - 1; d >= 0; d--)
		{
			buffer(s, ('0' + arr[d]), index);
			y++;
		}
	}
	else
	{
		for (d = 31; d >= 0; d--)
		{
			if (arr[d] == 1)
				arr[d] = 0;
			else if (arr[d] == 0)
				arr[d] = 1;
			buffer(s, ('0' + arr[d]), index);
			y++;
		}
	}
	return (y);
}
