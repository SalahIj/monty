#include "monty.h"

/**
 * Safty_out - the function name
 * @stack: first input
 * @len: second input
 * @tab: third input
 * @fd: input number 4
 */
void Safty_out(stack_t **stack, char *len, char **tab, FILE *fd)
{
	Free_nodes(stack);
	fclose(fd);
	free(len);
	free(tab);
	exit(EXIT_FAILURE);
}
