#include "monty.h"

/**
 * Adding_to_stack - the name of the function
 * @stack: first input
 * @line_number: second input
*/
void Adding_to_stack(stack_t **stack, unsigned int line_number)
{
(void)line_number;

if (!*stack)
{
top = *stack;
return;
}
if (top == NULL)
{
top = *stack;
return;
}
(*stack)->next = top;
top->prev = *stack;
top = *stack;
}
