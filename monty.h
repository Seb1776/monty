#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#define FUNCTION_OPS { \
	{"push", push},\
	{"pall", pall},\
	{NULL, NULL} \
}

/**
* struct help - argument for the current opcode
* @data_struct: stack mode, stack (default) and queue
* @argument: String args
*
* Description: Structure used to pass function data easily
*/
typedef struct help
{
	int data_struct;
	char *argument;
} help;

help global;

extern int status;

void push(stack_t **stack, unsigned int line);
int is_digit(char *string);
int is_number(char *str);
stack_t *add_node(stack_t **stack, const int n);
stack_t *queue_node(stack_t **stack, const int n);

#endif
