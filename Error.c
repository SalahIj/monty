#include "monty.h"

/**
 * Error - the function name
 * @str: the input
 * Return: the result.
*/
int Error(char *str)
{
char *tab[] = {"pall", "pint", "pop", "swap", "add", "nop", "sub",
"div", "mul", "mod", "pchar", "pstr", "rotl"};
int i;

for (i = 0; i < 13; i++)
{
if (strcmp(tab[i], str) == 0)
return (0);
}
return (1);
}
