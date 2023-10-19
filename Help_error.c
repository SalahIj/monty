#include "monty.h"

/**
 * Help_error - the function name
 * @str: first input
 * @n: second input
 * @st: third input
 * @l: input 4
 * @t: input 5
 * @fd: input 6
*/
void Help_error(char *str, int n, stack_t **st, char *l, char **t, FILE *fd)
{
if (Error(str) == 1)
{
fprintf(stderr, "L%d: unknown instruction %s\n", n, str);
Safty_out(st, l, t, fd);
exit(EXIT_FAILURE);
}
else if (Handling_errors(st, str, n) || Handling_errors_oper(st, str, n))
{
Safty_out(st, l, t, fd);
exit(EXIT_FAILURE);
}
else if (Error_ascii(st, str, n))
{
Safty_out(st, l, t, fd);
exit(EXIT_FAILURE);
}
else
Finding_a_func(st, str, n);
}
