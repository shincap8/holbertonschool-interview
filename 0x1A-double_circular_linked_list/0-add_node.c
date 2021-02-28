#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
* add_node_end - Add node to end of a double linked list.
* @list: pointer to head of list
* @str: the string to copy into the new node
* Return: the address of the new node
*/
List *add_node_end(List **list, char *str)
{
	List *new, *last;

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);
	if (list == NULL || str == NULL)
		return (NULL);
	new->str = str;
	if (*list == NULL)
	{
		new->prev = new;
		new->next = new;
		*list = new;
	}
	else
	{
		last = (*list)->prev;
		new->next = *list;
		new->prev = last;
		(*list)->prev = new;
		last->next = new;
	}
	return (new);
}
/**
* add_node_begin - Add node to start of a double linked list.
* @list: pointer to head of list
* @str: the string to copy into the new node
* Return: the address of the new node
*/
List *add_node_begin(List **list, char *str)
{
	List *new, *next;

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);
	if (list == NULL || str == NULL)
		return (NULL);
	new->str = str;
	if (*list == NULL)
	{
		new->prev = new;
		new->next = new;
		*list = new;
	}
	else
	{
		next = *list;
		new->next = next;
		new->prev = next->prev;
		next->prev->next = new;
		next->prev = new;
		(*list) = new;
	}
	return (new);
}
