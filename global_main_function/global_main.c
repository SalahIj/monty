#include "monty.h"

stack_t *top = NULL;

void Adding_to_stack(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    if (!*stack)
    {
        top = *stack;
        return;
    } 
    if (top == NULL)
    {
        top = *stack;
        return;
    }
    (*stack)->next = top;
    top->prev = *stack;
    top = *stack;
}

void Free_nodes(stack_t **stack)
{
    stack_t *tmp;

    if (*stack == NULL)
        return;

    while (*stack != NULL)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }
}

void Printing_from_stack(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;
    (void)line_number;

    temp = *stack;
    while(temp)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}

stack_t *Creating_node(char *str, int line_number)
{
    stack_t *temp;
    int j;

    if (str == NULL)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        return NULL;
    }

    for (j = 0; str[j] != '\0'; j++) 
    {
        if (str[j] < '0' || str[j] > '9') 
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            return NULL;
        }
    }

    temp = malloc(sizeof(stack_t));
    if (temp == NULL)
    {
        perror("malloc");
        return NULL;
    }
    
    temp->prev = NULL;
    temp->n = atoi(str);
    temp->next = NULL;

    return (temp);
}

void Safty_out(stack_t **stack, char *len, char **tab, FILE *fd)
{
    Free_nodes(stack);
    fclose(fd);
    free(len);
    free(tab);
    exit(EXIT_FAILURE);
}

void Printing_topmost(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    if (*stack != NULL && stack)
        printf("%d\n", (*stack)->n);
}

void Poping_from_stack(stack_t **stack, unsigned int line_number) {
    stack_t *temp;
    (void)line_number;

    temp = *stack;
    *stack = (*stack)->next;
    if (*stack != NULL)
        (*stack)->prev = NULL;
    free(temp);
}

void Swaping_in_stack(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;
    (void)line_number;

    temp = *stack;
    *stack = (*stack)->next;
    temp->next = (*stack)->next;
    temp->prev = (*stack)->prev;
    (*stack)->prev = NULL;
    (*stack)->next = temp;
}

void Adding_tow_elem(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;
    int add = 0;
    (void)line_number;

    temp = (*stack);
    (*stack) = (*stack)->next;
    add = temp->n + (*stack)->n;
    (*stack)->n = add;
    (*stack)->prev = NULL;
    free(temp);
}


void Subtracting_tow_elem(stack_t **stack, unsigned int nb)
{
    stack_t *temp;
    int sub = 0;
    (void)nb;

    temp = (*stack);
    (*stack) = (*stack)->next;
    sub = (*stack)->n - temp->n;
    (*stack)->n = sub;
    (*stack)->prev = NULL;
    free(temp);
}

void Dividing_tow_elem(stack_t **stack, unsigned int nb)
{
    stack_t *temp;
    int div;
    (void)nb;

    if ((*stack)->n)
    {
        temp = (*stack);
        (*stack) = (*stack)->next;
        div = (*stack)->n / temp->n;
        (*stack)->n = div;
        (*stack)->prev = NULL;
        free(temp);
    }
}

void Multipling_tow_elem(stack_t **stack, unsigned int nb)
{
    stack_t *temp;
    int mul;
    (void)nb;

    temp = (*stack);
    (*stack) = (*stack)->next;
    mul = temp->n * (*stack)->n;
    (*stack)->n = mul;
    (*stack)->prev = NULL;
    free(temp);
}

void Mod_of_tow_elem(stack_t **stack, unsigned int nb)
{
    stack_t *temp;
    int mod;
    (void)nb;

    if ((*stack)->n)
    {
        temp = (*stack);
        (*stack) = (*stack)->next;
        mod = temp->n % (*stack)->n;
        (*stack)->n = mod;
        (*stack)->prev = NULL;
        free(temp);
    }
}

void Printing_char(stack_t **stack, unsigned int nb)
{
    int charr;
    (void)nb;

    charr = (*stack)->n;
    if (charr >= 0 && charr <= 127)
        printf("%c\n", charr);
}

void Printing_str(stack_t **stack, unsigned int nb)
{
    stack_t *t;
    int str;
    (void)nb;

    if (!stack || !*stack)
    {
        printf("\n");
        return;
    }
    t = *stack;
    for (t = *stack; t; t = t->next)
    {
        str = t->n;
        if (str > 127 || str <=0)
            break;
        printf("%c", str);
    }
    printf("\n");
}

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

void Finding_a_func(stack_t **stack, char *str, int line_number)
{
    instruction_t list_func[] = {
        {"pall", Printing_from_stack},
        {"pint", Printing_topmost},
        {"pop", Poping_from_stack},
        {"swap", Swaping_in_stack},
        {"add", Adding_tow_elem},
        {"sub", Subtracting_tow_elem},
        {"div", Dividing_tow_elem},
        {"mul", Multipling_tow_elem},
        {"mod", Mod_of_tow_elem},
        {"pchar", Printing_char},
        {"pstr", Printing_str},
        {"rotl", Rotating_a_stack}
    };    
    int i;

    for (i = 0; i < 12; i++)
    {
        if (strcmp(str, list_func[i].opcode) == 0)
            list_func[i].f(stack, line_number);
    }
}

int Error(char *str)
{
    char *tab[] = {"pall", "pint", "pop", "swap", "add", "sub", 
    "div", "mul", "mod", "pchar", "pstr", "rotl"};
    int i;

    for (i = 0; i < 12; i++)
    {
        if (strcmp(tab[i], str) == 0)
            return (0);
    }
    return (1);
}


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

void Help_error(char *str, int n, stack_t **st, char *l, char **t, FILE *fd)
{
    if (Error(str) == 1)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", n, str);
        Safty_out(st, l, t, fd);
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

/*int is_comment(char *str) {
    if (str[0] == '#')
        return 1;
    return 0;
}*/

FILE *Opennig_file (char *arr)
{
    FILE *file;

    file = fopen(arr, "r");
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", arr);
        exit(EXIT_FAILURE);
    }
    return (file);
}

int main(int argc, char* argv[]) 
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
            continue;;
        }
        if (strcmp(array[0], "push") == 0) 
        {
            new = Creating_node(array[1], counter);
            if (!new)
                Safty_out(&top, line, array, file);
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
