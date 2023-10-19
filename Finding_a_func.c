#include "monty.h"

/**
 * Finding_a_func - the function name
 * @stack: first input
 * @str: second input
 * @line_number: third input
*/
void Finding_a_func(stack_t **stack, char *str, int line_number)
{
instruction_t list_func[] = {
{"pall", Printing_from_stack},
{"pint", Printing_topmost},
{"pop", Poping_from_stack},
{"swap", Swaping_in_stack},
{"add", Adding_tow_elem},
{"nop", Nopping_nothing},
{"sub", Subtracting_tow_elem},
{"div", Dividing_tow_elem},
{"mul", Multipling_tow_elem},
{"mod", Mod_of_tow_elem},
{"pchar", Printing_char},
{"pstr", Printing_str},
{"rotl", Rotating_a_stack}
};
int i;

for (i = 0; i < 13; i++)
{
if (strcmp(str, list_func[i].opcode) == 0)
list_func[i].f(stack, line_number);
}
}
