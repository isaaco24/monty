#include "monty.h"

/**
 * f_sub - Subtracts the top element from the second top element of the stack.
 * @head: Pointer to the stack's head
 * @counter: Line number being executed
 * Return: No return value
*/
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int result, nodes;

	aux = *head;

	/* Count the number of nodes in the stack */
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;

	/* Check if there are at least two elements in the stack */
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	aux = *head;
	result = aux->next->n - aux->n;
	aux->next->n = result;
	*head = aux->next;
	free(aux);
}
