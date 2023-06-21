#include "monty.h"
#include <ctype.h>
/**
 * stack_op_choice - chooses stack operation
 * @line: line of instructions
 * @line_number: number of line
 * Return: nothing
 */
int element = 0;
void stack_op_choice(char *line, int line_number, stack_t **stack)
{
	char *instruction = strtok(line, " \t\n"), *argument;
	int i;
	instruction_t stack_op[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop}
	};

	if (instruction == NULL)
		return;
	if (strcmp(instruction, "push") == 0)
	{
		argument = strtok(NULL, " \t\n");
		if (argument == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction <opcode>\n", line_number);
			exit(EXIT_FAILURE);
		}
		for (i = 0; argument[i] != '\0'; i++)
		{
			if (!isdigit(argument[i]))
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, argument);
				exit(EXIT_FAILURE);
			}
		}
		element = atoi(argument);
		stack_op[0].f(stack, line_number);
	}
	else if (strcmp(instruction, "pall") == 0)
	{
		stack_op[1].f(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction <opcode>\n", line_number);
		exit(EXIT_FAILURE);
	}
}
