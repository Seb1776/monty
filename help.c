#include "monty.h"

/**
 * is_digit - checks if a string is a digit
 *
 * @string: string to check
 *
 * Return: 1 if success, 0 if not
 */
int is_digit(char *string)
{
	if (!string || *string == '\0')
		return (0);

	if (*string == '-')
		string++;

	while (*string)
	{
		if (isdigit(*string) == 0)
			return (0);

		string++;
	}

	return (1);
}
/**
 * isnumber - checks if a string is a number
 *
 * @str: provided string
 *
 * Return: 1 if the string is a number, else, 0.
 */
int is_number(char *str)
{
	int i;

	if (!str)
		return (0);

	for (i = 0; str[i]; i++)
		if (i < '0' || i > '9')
			return (0);

	return (1);
}

/**
 * queue_node - Adds a node to the stack in queue mode
 *
 * @stack: Stack head
 * @n: Index of node
 *
 * Return: newly created node, if memory allocation fails, the function will
 * return NULL.
 */
stack_t *queue_node(stack_t **stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *current = *stack;

	if (!new)
	{
		free(new);
		return (NULL);
	}

	new->n = n;

	if (!*stack)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
		return (new);
	}

	while (current)
	{
		if (!current->next)
		{
			new->next = NULL;
			new->prev = current;
			current->next = new;
			break;
		}

		current = current->next;
	}

	return (new);
}

/**
 * add_node - Adds a node to the start of the stack
 *
 * @stack: Stack head
 * @n: Index of the new node
 *
 * Return: newly created node, if creation fails, the
 * function will return NULL.
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		return (NULL);
	}
	new->n = n;

	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;

	*stack = new;

	return (new);
}
