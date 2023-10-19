#include "monty.h"

/**
 * Mod_of_tow_elem - the function name
 * @stack - the first input
 * @nb: the second input
*/
void Mod_of_tow_elem(stack_t **stack, unsigned int nb)
{
stack_t *temp;
int mod;
(void)nb;

if ((*stack)->n)
{
temp = (*stack);
(*stack) = (*stack)->next;
mod = temp->n % (*stack)->n;
(*stack)->n = mod;
(*stack)->prev = NULL;
free(temp);
}
}
