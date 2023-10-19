#include "monty.h"

/**
 * Swaping_in_stack - the function name
 * @stack: first input
 * @line_number: second input
 */
void Swaping_in_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	temp->prev = (*stack)->prev;
	(*stack)->prev = NULL;
	(*stack)->next = temp;
}
