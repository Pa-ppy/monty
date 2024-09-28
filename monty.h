#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - Doubly linked list representation of a stack
 * @n: integer
 * @prev: points to the previous element of the stack
 * @next: points to the next element of the stack
 *
 * Description: doubly linked list node structure for stacks, queues
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its functions
 * @opcode:the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function for stack, queues
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number, char *arg);
} instruction_t;

/* Function prototypes */

/* Opcode functions */
void push(stack_t **stack, unsigned int line_number, char *arg);
void pall(stack_t **stack, unsigned int line_number, char *arg);

/* Utility function */
void free_stack(stack_t *stack);

/* Main program function */
void run_monty(FILE *file);

/* Error handling functions */
void error_usage(void);
void error_file(char *filename);
void error_malloc(void);
void error_instruction(unsigned int line_number, char *opcode);

#endif
