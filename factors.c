#include "main.h"
#define _GNU_SOURCE
/**
  *main - the entry point of the program
  *@argc: the number of arbuments accepted into the program
  *@argv: an array of strings of arguments
  *
  *Return: exit with success on success
  */
int main(int argc, char **argv)
{
	size_t c, num;

	readbuf = NULL;
	file = NULL;
	atexit(cleanup);
	if (argc != 2)
	{
		fprintf(stderr, "Usage %s <file>\n", argv[0]);
		exit(EPERM);
	}
	file = fopen(argv[1], "r");
	c = num = 0;
	while ((getline(&readbuf, &c, file)) >= 0)
	{
		num = numcon(readbuf);
		calcproduct(num);
	}
	exit(EXIT_SUCCESS);
}
/**
  *cleanup - clean up function to exit the programm
  *
  *Return: void
  */
void cleanup(void)
{
	fclose(file);
	free(readbuf);
}
/**
  *calcproduct - function to find the largest product of a number
  *@num: the number to be broken down into individual products
  *
  *Return: void
  */
void calcproduct(size_t num)
{
	size_t a = 2;
	size_t b = 0;

	if (num % a == 0)
		b = num / a;
	else if (num % 3 == 0)
	{
		a = 3;
		b = num / a;
	}
	else
	{
		for (a = 5; a < num / 2; )
		{
			if (num % a == 0)
			{
				b = num / a;
				break;
			}
			a = a + 2;
		}
	}
	printf("%lu=%lu*%lu\n", num, a, b);
}
