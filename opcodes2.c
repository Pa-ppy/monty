#include "monty.h"

/**
 * add - adds the top two elements
 * @stack: double pointer to the stack
 * @line_number: line number of the current instruction
 * @arg: Argument
 *
 * Description: Prints an error message if stack contains less than 2 elements
 */
void add(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *temp;

	(void)arg;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
