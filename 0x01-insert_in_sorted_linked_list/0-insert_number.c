#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: pointer to head of list
 * @number: number to insert
 * Return: the address of the new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *aux, *new;

	if (head == NULL || *head == NULL)
		return (NULL);
	aux = *head;
	new = malloc(sizeof(listint_t));
		if (new == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;
	if (aux->n > number)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	while (aux)
	{
		if (aux->next != NULL)
		{
			if (aux->next->n > number)
			{
				new->next = aux->next;
				aux->next = new;
				return (new);
			}
			aux = aux->next;
		} else
		{
			new->next = NULL;
			aux->next = new;
			return (new);
		}
	}
	return (new);
}
