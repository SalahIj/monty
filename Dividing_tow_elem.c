#include "monty.h"

/**
 * Dividing_tow_elem - the function name
 * @stack: first input
 * @nb: second input
*/
void Dividing_tow_elem(stack_t **stack, unsigned int nb)
{
stack_t *temp;
int div;
(void)nb;

if ((*stack)->n)
{
temp = (*stack);
(*stack) = (*stack)->next;
div = (*stack)->n / temp->n;
(*stack)->n = div;
(*stack)->prev = NULL;
free(temp);
}
}
