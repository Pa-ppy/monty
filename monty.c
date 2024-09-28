#include "monty.h"

/**
 * main - Entry point of program
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, or EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
		error_usage();

	file = fopen(argv[1], "r");
	if (file == NULL)
		error_file(argv[1]);

	run_monty(file);

	fclose(file);

	return (0);
}

/**
 * run_monty - Reads and executes Monty bytecode commands
 * @file: Pointer to the file containing monty bytecode
 */
void run_monty(FILE *file)
{
	char line[1024];
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};
	char *opcode;
	char *arg;
	int i;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \n");
		arg = strtok(NULL, " \n");
		i = 0;

		if (opcode == NULL || opcode[0] == '#')
			continue;

		while (instructions[i].opcode != NULL)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number, arg);
				break;
			}
			i++;
		}
		if (instructions[i].opcode == NULL)
			error_instruction(line_number, opcode);
	}

	free_stack(stack);
}
