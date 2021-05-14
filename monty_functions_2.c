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

/**
 * nop - This... doens't do anything lmao
 * 
 * @stack: Given by main, useless
 * @line: Line count? who needs that bruh
 *
 * Return: what are you expecting it to return? 
 */
void nop(stack_t **stack, unsigned line)
{
	(void) stack;
	(void) line;
}

/**
 * opcode - This function manages builtins
 *
 * @stack: Given stack
 * @str: Strings to compare
 * @line: Line  ammoun
 *
 * Return: void 
 */
void opcode(stack_t **stack, char *str, unsigned int line)
{
	int i = 0;

	instruction_t op[] = INSTRUCTIONS;

	if (!strcmp(str, "stack"))
	{
		global.data_struct = 1;
		return;
	}

	if (!strcmp(str, "queue"))
	{
		global.data_struct = 0;
		return;
	}

	while (op[i].opcode)
	{
		if (strcmp(op[i].opcode, str) == 0)
		{
			op[i].f(stack, line);
			return;
		}

		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line, str);
	status = EXIT_FAILURE;
}
