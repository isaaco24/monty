#include "monty.h"

/**
 * f_queue - Changes stack behavior to queue (Description is unclear).
 * @head: Pointer to the stack's head
 * @counter: Line number being executed
 * Return: No return value
*/
void f_queue(stack_t **head, unsigned int counter)
{
	/* These parameters are currently not used */
	(void)head;
	(void)counter;

	/* Change a value in the bus (not clear what "lifi" represents) */
	bus.lifi = 1;
}

/**
 * addqueue - Adds a node to the tail of the stack (queue behavior).
 * @n: New value to be added
 * @head: Pointer to the head of the stack
 * Return: No return value
*/
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error\n");
	}

	new_node->n = n;
	new_node->next = NULL;

	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}

	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
