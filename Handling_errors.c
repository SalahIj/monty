#include "monty.h"

/**
 * Handling_errors - the function name
 * @st: first input
 * @str: second input
 * @nb: third input
 * Return: the result
*/
int Handling_errors(stack_t **st, char *str, int nb)
{
char *t[] = {"pint", "pop", "pchar"};
int i;

if (!*st || !st)
{
for (i = 0; i < 3; i++)
{
if (strcmp(str, t[i]) == 0)
{
fprintf(stderr, "L%d: can't %s, stack empty\n", nb, t[i]);
return (1);
}
}
}
return (0);
}
