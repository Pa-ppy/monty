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

	if (!arg || ((n = atoi(arg)) == 0 && strcmp(arg, "0") != 0))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		error_malloc();

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
void pall(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *current;
	(void)line_number;
	(void)arg;

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - Prints the value at the top of the stack
 * @stack: double pointer to the stack
 * @line_number: Line number of the current instruction
 * @arg: Argument
 *
 * Description: Prints an error if stack is empty
 */
void pint(stack_t **stack, unsigned int line_number, char *arg)
{
	(void)arg;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the current instructions
 * @arg: Argument
 *
 * Description: Prints an error message if the stack is empty
 */
void pop(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *temp;

	(void)arg;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}
