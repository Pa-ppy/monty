#include "monty.h"

/**
 * error_usage - Prints usage error message and exits
 */
void error_usage(void)
{
	fprintf(stderr, "Usage: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * error_file - Prints the file error message and exits
 * @filename: The name of the file that couldn't be opened
 */
void error_file(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * error_mallo - Prints malloc error message and exits
 */
void error_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * error_instruction - Prints unknown instruction error and exits
 * @line_number: Line number in the bytecode file where the error occurred
 * @opcode: The unknown opcode that caused the error
 */
void error_instruction(unsigned int line_number, char *opcode)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
