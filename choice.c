#include "monty.h"
#include <ctype.h>

int element;
/**
 * validate_push_argument - validates the argument for push instruction
 * and if is integer, it calls push function.
 * @argument: argument to validate
 * @line_number: line number
 * @stack: pointer to the stack
 */
void validate_push_argument(char *argument, int line_number, stack_t **stack)
{
	int i;
	instruction_t stack_op[] = {
		{"push", push}, {"pall", pall}, {"pop", pop}, {"swap", swap},
		{"add", add}, {"pint", pint}, {"nop", nop}, {"sub", sub},
		{"div", divide}, {"mul", mul}, {"mod", mod}
	};

	if (argument == NULL)
	{
		free_stack(stack);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; argument[i] != '\0'; i++)
	{
		if (!isdigit(argument[i]))
		{
			free_stack(stack);
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	element = atoi(argument);
	stack_op[0].f(stack, line_number);
}
/**
 * comment_checker - checks if the first non-space
 * character of a line is #, treat this line as a comment (don’t do anything).
 * @c: first non-space character
 * Return: 1 on success. -1 otherwise.
 */
int comment_checker(char c)
{
	if (c == '#')
		return (1);
	return (-1);
}
/**
 * stack_op_choice - chooses stack operation
 * @line: line of instructions
 * @line_number: number of line
 * @stack: pointer to stack
 * Return: nothing
 */
void stack_op_choice(char *line, int line_number, stack_t **stack)
{
	char *instruction = strtok(line, " \t\n");
	char *argument = NULL;
	int i;
	instruction_t stack_op[] = {
		{"push", push}, {"pall", pall}, {"pop", pop}, {"pint", pint},
		{"swap", swap}, {"add", add}, {"nop", nop}, {"sub", sub},
		{"div", divide}, {"mul", mul}, {"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}
	};

	if (instruction == NULL)
		return;
	for (i = 0; i < 13; i++)
	{
		if (strcmp(instruction, stack_op[i].opcode) == 0)
		{
			if (i == 0) /* push instruction */
			{
				argument = strtok(NULL, " \t\n");
				validate_push_argument(argument, line_number, stack);
			}
			else
			{
				stack_op[i].f(stack, line_number);
			}
			return;
		}
		else if (comment_checker(*instruction) == 1)
			return;
	}
	free_stack(stack);
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruction);
	exit(EXIT_FAILURE);
}
