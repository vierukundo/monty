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
		free_stack(stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = element;
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
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

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	top_node = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
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

	if (current_node == NULL)
		return;
	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}
/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @stack: pointer to stack
 * @line_number: line of instruction
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}
}
/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: line of instruction
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node = *stack, *second_node;

	if (top_node == NULL || top_node->next == NULL)
	{
		free_stack(stack);
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	second_node = top_node->next;
	top_node->prev = second_node;
	top_node->next = second_node->next;
	second_node->prev = NULL;
	second_node->next = top_node;
	if (top_node->next != NULL)
		top_node->next->prev = top_node;
	*stack = second_node;
}
