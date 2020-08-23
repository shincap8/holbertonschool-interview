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
	int length, i = 0, half[1024];
	listint_t *aux = *head;

	if (head == NULL)
		return (1);
	length = list_length(aux);
	aux = *head;
	for (i = 0; i < length / 2; i++)
	{
		half[i] = aux->n;
		aux = aux->next;
	}
	i--;
	if (length % 2 == 1)
		aux = aux->next;
	while (aux)
	{
		if (aux->n != half[i])
			return (0);
		i--;
		aux = aux->next;
	}
	return (1);
}
