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
FILE *file;
char *readbuf;

size_t numcon(char *s);
size_t getsqrt(size_t n);
size_t strtonum(char *s);
int is_prime(size_t num);
size_t rtbubble(size_t min, size_t max, size_t n);

void calcproduct(size_t num);

void cleanup(void);
#endif
