#include "monty.h"

/**
 * Free_nodes - the function name
 * @stack: tne input
*/
void Free_nodes(stack_t **stack)
{
stack_t *tmp;

if (*stack == NULL)
return;

while (*stack != NULL)
{
tmp = *stack;
*stack = (*stack)->next;
free(tmp);
}
}
