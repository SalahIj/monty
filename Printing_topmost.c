#include "monty.h"

/**
 * Printing_topmost - the function name
 * @stack: first input
 * @line_number: second input
 */
void Printing_topmost(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack != NULL && stack)
		printf("%d\n", (*stack)->n);
}
