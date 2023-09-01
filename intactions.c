#include "main.h"
/**
  *numcon - converts a string of numbers to size_t
  *@s: the string
  *Description: uses the supporting function strtonum
  *Return: the converted number
  */
size_t numcon(char *s)
{
	char *temp = NULL;
	char *del = " \n";

	temp = strtok(s, del);
	printf("converting %s\n", temp);
	return (strtonum(s));
}
/**
  *strtonum - simple function to convert a string to a number
  *@s: the string
  *Description: expects only valid numbers
  *Return: the converted number
  */
size_t strtonum(char *s)
{
	size_t num = 0;

	while (*s != '\0' && *s >= '0' && *s <= '9')
	{
		num = num * 10 + (*s - '0');
		s++;
	}
	return (num);
}
/**
  *getsqrt - function to get the square root of a function
  *@n: the number
  *Description: uses the bubble sort algorithm
  *Return: the closest number to the square root if not the square root
  */
size_t getsqrt(size_t n)
{
	if (n <= 3)
		return (n);
	return (rtbubble(0, n / 2, n));
}
/**
  *rtbubble - the bubble sort logic to find the square root
  *@min: the minimum number in consideration
  *@max: the max number in consideration
  *@n: the actual number
  *
  *Return: the closest number to the square root of the number
  */
size_t rtbubble(size_t min, size_t max, size_t n)
{
	size_t temp;

	temp = (min + max) / 2;
	if (((temp * temp) == n) || (max - min) <= 1)
		return (temp);
	else if ((temp * temp) > n)
		return (rtbubble(min, temp, n));
	else
		return (rtbubble(temp, max, n));
}
/**
  *is_prime - check whether a number is a prime number
  *@num: the number
  *
  *Return: True if the number is a prime number
  */
int is_prime(size_t num)
{
	size_t sqrt = 0;
	int prime = TRUE;
	size_t temp = 2;

	if (num == 2)
		return (prime);
	if (num < 2 || num % 2 == 0)
		prime = FALSE;
	else
	{
		sqrt = getsqrt(num);
		if (sqrt * sqrt == num)
			prime = FALSE;
		else
		{
			temp = 3;
			while (temp < sqrt)
			{
				if (sqrt % temp == 0)
				{
					prime = FALSE;
					break;
				}
				temp = temp + 2;
			}
		}
	}
	return (prime);
}
