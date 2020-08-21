#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
* list_length - Count the elemnts on a list
* @head: pointer to head of list
* Return: 1 if palindrome 0 if not
*/
int list_length(listint_t *head)
{
int length = 0;

while (head)
{
	head = head->next;
	length++;
}
return (length);
}
/**
* is_palindrome - checks if a singly linked list is a palindrome
* @head: pointer to head of list
* Return: 1 if palindrome 0 if not
*/
int is_palindrome(listint_t **head)
{
	int length, checks, i, j;
	listint_t *start, *end;

	if (head == NULL)
		return (1);
	start = *head;
	length = list_length(start);
	start = *head;
	checks = length / 2;
	for (i = 0; i < checks; i++)
	{
		end = start;
		for (j = length - 1; j > 0; j--)
		{
			end = end->next;
		}
		if (end->n != start->n)
			return (0);
		length = length - 2;
		start = start->next;
	}
	return (1);
}
