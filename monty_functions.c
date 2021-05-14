#include "monty.h"

/**
 * push - Push an element into the stack
 *
 * @stack: Given stack
 * @line: Amount of lines
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line)
{
	char *c = global.argument;

	if ((is_digit(c)) == 0)
	{
		fprintf(stderr, "L%d: usage push integer\n", line);
		status = EXIT_FAILURE;
		return;
	}

	if (global.data_struct == 1)
	{
		if (!add_node(stack, atoi(global.argument)))
		{
			return;
			status = EXIT_FAILURE;
		}
	}

	else
	{
		if (!queue_node(stack, atoi(global.argument)))
		{
			return;
			status = EXIT_FAILURE;
		}
	}
}

/**
 * pall - Prints the stack
 *
 * @stack: Given stack
 *
 * Return: void
 */
void pall(stack_t **stack)
{
	print_stack(*stack);
}

/**
 * pint - Print the data value of the top position
 *
 * @stack: Given stack
 * @line: Line amount
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		status = EXIT_FAILURE;
		return;
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element
 *
 * @stack: Given stack
 * @line: Amount of lines
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line)
{
	stack_t *tmp = NULL;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line);
		status = EXIT_FAILURE;
		return;
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;

	if (!*stack)
		return;

	(*stack)->prev = NULL;
}
