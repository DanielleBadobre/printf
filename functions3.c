#include "main.h"
/**
 * switch_h - print hexa
 * @sum: num
 * @h: array
 * @y: space
 * Return: num
 */
int switch_h(int sum, int *h, int y)
{
	switch (sum)
	{
		case 10:
			h[y] = 'a';
			break;
		case 11:
			h[y] = 'b';
			break;
		case 12:
			h[y] = 'c';
			break;
		case 13:
			h[y] = 'd';
			break;
		case 14:
			h[y] = 'e';
			break;
		case 15:
			h[y] = 'f';
			break;
		default:
			h[y] = sum;
	}
	return (h[y]);
}
/**
 * impression_x - hexa lowercase
 * @a: array
 * @b: size
 * @s: buffer
 * @index: position
 * Return: num
 */
int impression_x(int *a, int b, char *s, int *index)
{
	int c = 0, y = 0, mul = 1;
	int sum = 0, i, j;
	iny h[8] = {0};

	while (c < b)
	{
		sum = 0;
		for (i = 0; i < 4; i++)
		{
			if (i == 0 && c < b)
			{
				sum = sum + a[c];
				mul = 2;
				c++; }
			else if (i != 0 && c < b)
			{
				sum = sum + (mul * a[c]);
				c++;
				mul = 2 * mul;}
			else
				break;
		}
		h[y] = switch_h(sum, h, y);
		y++;
	}
	for (j = y - 1; j >= 0; j--)
	{
		if (h[j] == 'a' || h[j] == 'b' || h[j] == 'c' || h[j] == 'd'
				|| h[j] == 'e' || h[j] == 'f')
			buffer(s, h[j], index);
		else
			buffer(s, (h[j] + '0'), index);
	}
	return (y);
}
/**
 * print_x - hexa base 16
 * @a: valist
 * @s:buffer
 * @index: position
 * @Return: num
 */
int print_x(va_list a, char *s, int *index)
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
		y = impression_x(arr, c, s, index);
	else
	{
		for (d = 31; d >= 0; d--)
		{
			if (arr[d] == 1)
				arr[d] = 0;
			else if (arr[d] == 0)
				arr[d] = 1;
		}
		y = impression_x(arr, 32, s, index);
	}
	return (y);
}
