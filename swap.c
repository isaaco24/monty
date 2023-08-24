#include "monty.h"

/**
 * f_swap - swaps the positions of the top two elements in the stack.
 * @head: Pointer to the stack's head
 * @counter: Line number being executed
 * Return: No return value
*/
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;

	/* Calculate the length of the stack */
	while (h)
	{
		h = h->next;
		len++;
	}

	/* Check if there are at least two elements in the stack */
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
