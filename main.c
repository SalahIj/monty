#include "monty.h"

stack_t *top = NULL;

/**
 * main - the principal entry
 * @argc: first input
 * @argv: second input
 * Return: the result
*/
int main(int argc, char *argv[])
{
FILE *file;
char *line = NULL, **array;
size_t len = 0;
int counter = 1;
stack_t *new = NULL;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
file = Opennig_file(argv[1]);
while (getline(&line, &len, file) != -1)
{
array = Spliting_function(line, "\t\n$ ");
if (array[0][0] == '#')
{
free(array);
continue;
}
if (strcmp(array[0], "push") == 0)
{
new = Creating_node(array[1], counter);
if (!new)
{
Safty_out(&top, line, array, file);
exit(EXIT_FAILURE);
}
Adding_to_stack(&new, 1);
}
else
Help_error(array[0], counter, &top, line, array, file);
counter++;
free(array);
}
Free_nodes(&top);
free(line);
fclose(file);
return (0);
}
