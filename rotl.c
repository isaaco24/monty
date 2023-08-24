#include "monty.h"

/**
 * f_rotl - Rotates the stack to move the bottom element to the top.
 * @head: Pointer to the stack's head
 * @counter: Line number being executed (unused)
 * Return: No return value
*/
void f_rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;

	/* Traverse the stack to find the last element */
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}
