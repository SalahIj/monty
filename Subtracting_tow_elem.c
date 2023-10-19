#include "monty.h"

/**
 * Subtracting_tow_elem - the function name
 * @stack: first input
 * @nb: second input
 */
void Subtracting_tow_elem(stack_t **stack, unsigned int nb)
{
	stack_t *temp;
	int sub = 0;
	(void)nb;

	temp = (*stack);
	(*stack) = (*stack)->next;
	sub = (*stack)->n - temp->n;
	(*stack)->n = sub;
	(*stack)->prev = NULL;
	free(temp);
}
