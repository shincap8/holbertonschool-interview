#include "palindrome.h"
/**
* num_len - Check the digits in a number
* @n: unsigned long number
* Return: the amount of digits in n
*/
int num_len(unsigned long n)
{
	int digits = 0;

	while (n > 0)
	{
		n = n / 10;
		digits++;
	}

	return (digits);
}
/**
* is_palindrome - checks if an unsigned long num is palindrome
* @n: unsigned long n
* Return: 1 if palindrome 0 if not
*/
int is_palindrome(unsigned long n)
{
	unsigned long half[20];
	int len, i;

	len = num_len(n);

	for (i = 0; i < len / 2; i++)
	{
		half[i] = n % 10;
		n = n / 10;
	}
	i--;
	if (len % 2 == 1)
		n = n / 10;
	for (; i >= 0; i--)
	{
		if (n % 10 != half[i])
			return (0);
		n = n / 10;
	}
	return (1);
}
