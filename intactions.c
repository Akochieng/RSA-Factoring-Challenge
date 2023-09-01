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
	return (strtonum(temp));
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
  *is_prime - check whether a number is a prime number
  *@num: the number
  *
  *Return: True if the number is a prime number
  */
int is_prime(size_t num)
{
	int prime = TRUE;
	size_t temp = 2;
	size_t halft;

	if (num == 2 || num == 3)
		return (prime);
	if (num < 2 || num % 2 == 0)
		prime = FALSE;
	else
	{
		halft = temp / 2;
		while (temp < halft)
		{
			if (num % temp == 0)
			{
				prime = FALSE;
				break;
			}
			temp = temp + 2;
		}
	}
	return (prime);
}
