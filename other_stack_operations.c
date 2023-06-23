#include "monty.h"
/**
 * nop - doesn’t do anything
 * @stack: pointer to stack
 * @line_number: line of instruction
 * Return: nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @stack: pointer to stack
 * @line_number: line of instruction
 * Return: nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 32 || (*stack)->n >= 127)
	{
		free_stack(stack);
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar((*stack)->n);
	putchar('\n');
}
/**
 * pstr - prints the string starting at the
 * top of the stack, followed by a new line
 * @stack: pointer to stack
 * @line_number: line of instruction
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	if (current == NULL)
		return;
	while (current != NULL)
	{
		if (current->n < 32 || current->n >= 127 || current->n == 0)
		{
			break;
		}
		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}
/**
 * free_stack - frees allocated memory for stack
 * @stack: pointer to stack
 * Return: nothing
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *temp;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*stack = NULL;
}
/**
 * rotl - rotates the stack to the top
 * @stack: pointer to stack
 * @line_number: line of instruction
 * Return: nothing
 * Description: The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node = *stack;
	stack_t *second_node = top_node->next;
	stack_t *last_node = *stack;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = top_node;
	top_node->prev = last_node;
	*stack = second_node;
	second_node->prev = NULL;
	top_node->next = NULL;
}
