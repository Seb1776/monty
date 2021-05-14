#include "monty.h"

/**
 * free_stack - frees a dlistint_t linked list
 *
 * @stack: list head
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	if (stack)
	{
		next = stack->next;
		while (current)
		{
			free(current);
			current = next;
			if (next)
				next = next->next;
		}
	}
}

/**
 * print_stack - Prints the contents of a stack_t stack
 *
 * @stack: stack head
 *
 * Return: number of elements of the list
 */
size_t print_stack(const stack_t *stack)
{
	size_t c = 0;

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		c++;
	}

	return (c);
}
