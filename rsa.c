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
	add_node(2);
	add_node(3);
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
	freelist();
}
/**
  *printans - print the answer in the function
  *@num: the number
  *@a: the value a
  *@b: the value b
  *
  *Return: void
  */
void printans(size_t num, size_t a, size_t b)
{
	printf("%lu=%lu*%lu\n", num, b, a);
}
/**
  *calcproduct - function to find the largest product of a number
  *@num: the number to be broken down into individual products
  *
  *Return: void
  */
void calcproduct(size_t num)
{
	size_t a, b, halfn;
	primeno *cur;

	a = b = 1;
	cur = head;
	while (cur)
	{
		if (num % cur->n == 0)
		{
			a = cur->n;
			b = num / a;
			if (is_prime(b))
			{
				add_node(b);
				printans(num, a, b);
				return;
			}
		}
		cur = cur->next;
	}
	halfn = num / 2;
	for ( ; a < halfn; a += 2)
		if (num % a == 0)
			if (is_prime(a))
			{
				add_node(a);
				b = num / a;
				if (is_prime(b))
				{
					add_node(b);
					printans(num, a, b);
					return;
				}
			}
	printans(num, 1, num);
}
