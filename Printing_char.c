#include "monty.h"

/**
 * Printing_char - the function name
 * @stack: first input
 * @nb: second input
 */
void Printing_char(stack_t **stack, unsigned int nb)
{
	int charr;
	(void)nb;

	charr = (*stack)->n;
	if (charr >= 0 && charr <= 127)
		printf("%c\n", charr);
}
