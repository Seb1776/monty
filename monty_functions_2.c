#include "monty.h"

/**
 * swap - Swaps the last and top values
 *
 * @stack: Given stack
 * @line: Amount of lines
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line)
{
	stack_t *tmp = NULL;
	int n = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		status = EXIT_FAILURE;
		return;
	}

	tmp = *stack;
	n = tmp->n;
	tmp->n = n;

	tmp->n = tmp->next->n;
	tmp->next->n = n;
}

/**
 * addd - Sums the first two nodes of the stack
 *
 * @stack: Given stack
 * @line: Ammount of lines
 *
 * Return: void
 */
void addd(stack_t **stack, unsigned int line)
{
	int res;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		status = EXIT_FAILURE;
		return;
	}

	res = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, line);
	(*stack)->n = res;
}
