#include "monty.h"
/**
 * push - adds new element on top of stack
 * @stack: addrss of stack
 * @line_number: line of instruction
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	(void)line_number;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = element;
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
/**
 * pop - removes element on top of stack
 * @stack: addrss of stack
 * @line_number: line of instruction
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node;
	(void)line_number;

	if (*stack == NULL)
	{
		fprintf(stderr, "Error: Stack Underflow\n");
		exit(EXIT_FAILURE);
	}
	top_node = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(top_node);
}
/**
 * pall - prints elements of stack
 * @stack: address of stack
 * @line_number: line of instruction
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node = *stack;
	(void)line_number;

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}
