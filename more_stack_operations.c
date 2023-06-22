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
 * sub - subtracts the top element of the stack
 * from the second top element of the stack
 * @stack: pointer to stack
 * @line_number: line of instruction
 * Return: nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node = *stack;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = result;
	(*stack)->next->prev = NULL;
	*stack = (*stack)->next;
	free(top_node);
}
/**
 * divide - divides the second top element of the
 * stack by the top element of the stack
 * @stack: pointer to stack
 * @line_number: line of instruction
 * Return: nothing
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node = *stack;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = result;
	(*stack)->next->prev = NULL;
	*stack = (*stack)->next;
	free(top_node);
}
/**
 * mul - multiplies the second top element of the
 * stack with the top element of the stack
 * @stack: pointer to stack
 * @line_number: line of instruction
 * Return: nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node = *stack;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n * (*stack)->n;
	(*stack)->next->n = result;
	(*stack)->next->prev = NULL;
	*stack = (*stack)->next;
	free(top_node);
}
/**
 * mod - computes the rest of the division of the
 * second top element of the stack by the top element of the stack
 * @stack: pointer to stack
 * @line_number: line of instruction
 * Return: nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node = *stack;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = result;
	(*stack)->next->prev = NULL;
	*stack = (*stack)->next;
	free(top_node);
}
