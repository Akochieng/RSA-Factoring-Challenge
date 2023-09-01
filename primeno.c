#include "main.h"
/**
  *add_node - adds a node to the tail of the doubly linked list
  *@num: the number pointing to the node
  *Description: the function sorts the value of n in the linked list
  *Return: the newly created node
  */
primeno *add_node(size_t num)
{
	primeno *cur, *new, *nxt;

	cur = NULL;
	new = NULL;
	new = malloc(sizeof(primeno));
	if (new == NULL)
		return (NULL);
	new->n = num;
	new->next = NULL;
	if (tail == NULL)
	{
		new->prev = NULL;
		head = new;
		tail = new;
		return (new);
	}
	cur = tail;
	if (cur->n > num)
	{
		while (cur->n > num)
			cur = cur->prev;
		nxt = cur->next;
		new->next = nxt;
		nxt->prev = new;
		cur->next = new;
		new->prev = cur;
	}
	else
	{
		cur->next = new;
		new->prev = cur;
		tail = new;
	}
	return (new);
}
/**
  *freelist - free up the space used by the linked list
  *
  *Return: void
  */
void freelist(void)
{
	primeno *cur, *nxt;

	cur = NULL;
	nxt = NULL;
	cur = head;
	while (!(cur == NULL))
	{
		nxt = cur->next;
		free(cur);
		cur = nxt;
	}
	head = NULL;
	tail = NULL;
}
