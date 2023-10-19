#include "monty.h"

/**
 * Poping_from_stack - the function name
 * @stack: first input
 * @line_number: second input
 */
void Poping_from_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
