#include "monty.h"

/**
 * Handling_errors_oper - the function name
 * @st: first input
 * @s: second input
 * @nb: third input
 * Return: the result
*/
int Handling_errors_oper(stack_t **st, char *s, int nb)
{
char *t[] = {"add", "div", "mul", "sub", "swap", "mod"};
int i;

if (!*st || !st || !(*st)->next)
{
for (i = 0; i < 6; i++)
{
if (strcmp(s, t[i]) == 0)
{
fprintf(stderr, "L%d: can't %s, stack too short\n", nb, t[i]);
return (1);
}
}
}
else if ((*st)->n == 0 && (strcmp(s, "div") == 0 || strcmp(s, "mod") == 0))
{
fprintf(stderr,  "L%d: division by zero\n", nb);
return (1);
}
return (0);
}
