#include "monty.h"
/**
 * Error_ascii - The function name
 * @st: first input
 * @str: second input
 * @nb: third input
 * Return the result
*/
int Error_ascii(stack_t **st, char *str, int nb)
{
int nub;

nub = (*st)->n;
if ((nub < 0 || nub > 127) && strcmp(str, "pchar") == 0)
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", nb);
return (1);
}
return (0);
}
