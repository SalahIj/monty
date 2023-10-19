#include "monty.h"

/**
 * Multipling_tow_elem - the function name
 * @stack: first input
 * @nb: second input
 */
void Multipling_tow_elem(stack_t **stack, unsigned int nb)
{
	stack_t *temp;
	int mul;
	(void)nb;

	temp = (*stack);
	(*stack) = (*stack)->next;
	mul = temp->n * (*stack)->n;
	(*stack)->n = mul;
	(*stack)->prev = NULL;
	free(temp);
}
