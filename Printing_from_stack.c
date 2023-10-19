#include "monty.h"

/**
 * Printing_from_stack - the function name
 * @stack: first input
 * @line_number: second input
 */
void Printing_from_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
