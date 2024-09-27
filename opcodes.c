#include "monty.h"

/**
 * push - Pushes an element to the stack
 * @stack: Pointer to the stack (doubly linked list)
 * @line_number: Current line number in bytecode
 * @arg: Argument for the push command
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *new_node;
	int n;

	if (!arg || (n = atoi(arg)) == 0 && strcmp(arg, "0") != 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - Prints all the values on the stack from the top
 * @stack: Pointer to the stack (doubly linked list)
 * @line_number: Current line number in the bytecode
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
