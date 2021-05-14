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
