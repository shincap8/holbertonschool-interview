#include "lists.h"
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
/**
* find_listint_loop- finds the loop in the linked list
* @head: pointer to the first element
*
* Description: this function finds a loop in the linked list
* Return: the address of the node where the loop starts
*/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast;
	listint_t *slow;

	if (head == NULL)
		return (NULL);

	slow = head;
	fast = head;

	while (slow && fast && fast->next)
	{
		fast = fast->next;
		fast = fast->next;
		slow = slow->next;

		if (slow == fast && slow == head)
		{
			return (slow);
		}
		else if (slow == fast)
		{
			slow = find_listint_loop(head->next);
			if (slow)
				return (slow);
		}
	}

	return (NULL);
}
