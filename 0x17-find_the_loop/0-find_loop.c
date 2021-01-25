#include "lists.h"
#include "lists.h"
/**
 * loop - check through the list.
 * @turtle: pointer one by one
 * @rabbit: pointer one ahead
 * Return: pointer where the loop start
 */
listint_t *loop(listint_t *turtle, listint_t *rabbit)
{
	while (turtle != rabbit)
	{
		turtle = turtle->next;
		rabbit = rabbit->next;
	}
	return (turtle);
}
/**
 * find_listint_loop - finds loops inside linked lists
 * @head: pointer to the first element
 * Return: the address of the node where the loop starts
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *turtle, *rabbit;

	if (head)
	{
		turtle = head->next;
		rabbit = head->next->next;
		while (turtle && rabbit)
		{
			if (turtle == rabbit)
			{
				turtle = head;
				return (loop(turtle, rabbit));
			}
			turtle = turtle->next;
			rabbit = rabbit->next->next;
		}
	}
	return (NULL);
}
