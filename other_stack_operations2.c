#include "monty.h"
/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to stack
 * @line_number: line of instruction
 * Return: nothing
 * Description: The last element of the
 * stack becomes the top element of the stack
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last_node = *stack;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	(*stack)->prev = last_node;
	*stack = last_node;
}
/**
 * _stack - sets the format of the data to a stack (LIFO)
 * @stack: pointer to stack
 * @line_number: line of instruction
 * Return: nothing
 * Description: when switching, The front of the
 * queue becomes the top of the stack
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *prev = NULL;
	stack_t *next = NULL;
	(void)line_number;

	if (current == NULL)
		return;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		current->prev = next;
		prev = current;
		current = next;
	}
	*stack = prev;
}
/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: pointer to stack
 * @line_number: line of instruction
 * Return: nothing
 * Description: when switching, the top of the stack becomes
 * the front of the queue
 */
void queue(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *prev = NULL;
	stack_t *next = NULL;
	(void)line_number;

	if (current == NULL)
		return;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		current->prev = next;
		prev = current;
		current = next;
	}
	*stack = prev;
}
