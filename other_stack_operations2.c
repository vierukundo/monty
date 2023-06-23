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
