#include "monty.h"

/**
 * Creating_node - the function name
 * @str: first input
 * @line_number - second input
 * Return: the result
*/
stack_t *Creating_node(char *str, int line_number)
{
stack_t *temp;
int j;

if (str == NULL)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
return (NULL);
}
for (j = 0; str[j] != '\0'; j++)
{
if (str[j] < '0' || str[j] > '9')
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
return (NULL);
}
}
temp = malloc(sizeof(stack_t));
if (temp == NULL)
{
fprintf(stderr, "Error: malloc failed");
return (NULL);
}
temp->prev = NULL;
temp->n = atoi(str);
temp->next = NULL;
return (temp);
}
