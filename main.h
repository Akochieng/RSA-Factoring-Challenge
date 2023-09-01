#ifndef PRIME_H
#define PRIME_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <errno.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
/**
  *struct primes: defines a node in a linked list of prime numbers
  *@n: the prime number
  *@next: the next number in the list
  *@prev: the previous number in the list
  */
typedef struct primes{
	size_t n;
	struct primes *next;
	struct primes *prev;
} primeno;

FILE *file;
char *readbuf;
primeno *head;
primeno *tail;

primeno *add_node(size_t num);
void freelist(void);

size_t numcon(char *s);
size_t getsqrt(size_t n);
size_t strtonum(char *s);
int is_prime(size_t num);
size_t rtbubble(size_t min, size_t max, size_t n);

void calcproduct(size_t num);

void printans(size_t num, size_t a, size_t b);
void cleanup(void);
#endif
