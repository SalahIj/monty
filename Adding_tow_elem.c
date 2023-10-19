#include "monty.h"

/**
 * Adding_tow_elem - the function name
 * @stack: first input
 * @line_number: second iput
*/
void Adding_tow_elem(stack_t **stack, unsigned int line_number)
{
stack_t *temp;
int add = 0;
(void)line_number;

temp = (*stack);
(*stack) = (*stack)->next;
add = temp->n + (*stack)->n;
(*stack)->n = add;
(*stack)->prev = NULL;
free(temp);
}
