#include "monty.h"

/**
 * Printing_str - the function name
 * @stack: first input
 * @nb: second input
 */
void Printing_str(stack_t **stack, unsigned int nb)
{
	stack_t *t;
	int str;
	(void)nb;

	if (!stack || !*stack)
	{
		printf("\n");
		return;
	}
	t = *stack;
	for (t = *stack; t; t = t->next)
	{
		str = t->n;
		if (str > 127 || str <= 0)
			break;
		printf("%c", str);
	}
	printf("\n");
}
