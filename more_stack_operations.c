#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: line of instruction
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node = *stack;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = result;
	(*stack)->next->prev = NULL;
	*stack = (*stack)->next;
	free(top_node);
}

/**
 * nop - doesn’t do anything
 * @stack: pointer to stack
 * @line_number: line of instruction
 * Return: nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;

	if (line_number)
		return;
}
