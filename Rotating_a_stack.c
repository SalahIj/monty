#include "monty.h"

/**
 * Rotating_a_stack - the function name
 * @stack: first input
 * @nb: second input
 */
void Rotating_a_stack(stack_t **stack, unsigned int nb)
{
	stack_t *t;
	(void)nb;

	if (!stack || !*stack || !(*stack)->next)
		return;

	for (t = *stack; t->next; t = t->next)
		;

	t->next = *stack;
	(*stack)->prev = t;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
