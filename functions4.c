#include "main.h"
/**
 * switch_H - hexa char
 * @sum: num
 * @h: array
 * @y: spaces of array
 * Return: number of character
 */
int switch_H(int sum, int *h, int y)
{
	switch (sum)
	{
		case 10:
			h[y] = 'A';
			break;
		case 11:
			h[y] = 'B';
			break;
		case 12:
			h[y] = 'C';
			break;
		case 13:
			h[y] = 'D';
			break;
		case 14:
			h[y] = 'E';
			break;
		case 15:
			h[y] = 'F';
			break;
		default:
			h[y] = sum;
	}
	return (h[y]);
}
/**
 * impresion_X - print hexa
 * @a: array
 * @b: size
 * @s: buffer
 * @index: position
 * Return: number
 */
int impresion_X(int *a, int b, char *s, int *index)
{
	int c = 0, y = 0, mul = 1;
	int sum = 0, i, j;
	int h[8] = {0};

	while (c < b)
	{
		sum = 0;
		for (i = 0; i < 4; i++)
		{
			if (i == 0 && c < b)
			{
				sum = sum + a[c];
				mul = 2;
				c++;}
			else if (i != 0 && c < b)
			{
				sum = sum + (mul * a[c]);
				c++;
				mul = 2 * mul;}
			else
				break;
		}
		h[y] = switch_H(sum, h, y);
		y++;
	}
	for (j = y - 1; j >= 0; j--)
	{
		if (h[j] == 'A' || h[j] == 'B' || h[j] == 'C' || h[j] == 'D'
				|| h[j] == 'E' || h[j] == 'F')
			buffer(s, h[j], index);
		else
			buffer(s, (h[j] + '0'), index);
	}
	return (y);
}
/**
 * print_X - print base 16
 * @a: valist
 * @s: buffer
 * @index: position
 * Reurn: number
 */
int print_X(va_list a, char *s, int *index)
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
		y = impresion_X(arr, c, s, index);
	else
	{
		for (d = 32; d >= 0; d--)
		{
			if (arr[d] == 1)
				arr[d] = 0;
			else if (arr[d] == 0)
				arr[d] = 1;
		}
		y = impresion_X(arr, 32, s, index);
	}
	return (y);
}

