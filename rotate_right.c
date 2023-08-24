#include "monty.h"

/**
 * f_rotr - Rotates the stack to move the top element to the bottom.
 * @head: Pointer to the stack's head
 * @counter: Line number being executed (unused)
 * Return: No return value
*/
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *head;

	/* If the stack is empty or has only one element, no rotation needed */
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	/* Traverse the stack to find the last element */
	while (copy->next)
	{
		copy = copy->next;
	}

	/* Adjust the pointers to rotate the stack */
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
