#include "monty.h"

/**
 * main - Entry point of program
 * @file: File for usage
 * @argc: Argument
 * @argv: Argument pool
 *
 * Return: 0 on success
 */
int main (int argc, char *argv[])
{
	FILE *file;
	char *line = NULL, *opcode = NULL, *arg = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n");
		arg = strtok(NULL, " \n");

		if (opcode == NULL || opcode[0] == '#')
			continue;

		int i = 0;
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
		{
			fprint(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			free(line);
			fclose(file);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
	fclose(file);
	free_stack(stack);

	return (0);
}
