#include "monty.h"

/**
 * f_push - Adds a new node with integer to stack or queue.
 * @head: Pointer to stack's head
 * @counter: Line number executed
 * Return: No return value
 */
void f_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;
	/* Check if argument is provided */
	if (bus.arg)
	{
		/* Check if the argument is a negative number */
		if (bus.arg[0] == '-')
			j++;
		/* Validate that the argument contains only digits */
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > '9' || bus.arg[j] < '0')
				flag = 1;
		}
		/* If argument contains non-digit characters */
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/* Convert argument to an integer */
	n = atoi(bus.arg);
	/* Choose whether to add to stack or queue based on "lifi" */
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
