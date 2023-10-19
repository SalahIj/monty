#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *top;

char **Spliting_function(char *buffer, char *delemiter);
void Adding_to_stack(stack_t **stack, unsigned int line_number);
stack_t *Creating_node(char *str, int line_number);
void Free_nodes(stack_t **stack);
void Printing_topmost(stack_t **stack, unsigned int line_number);
void Poping_from_stack(stack_t **stack, unsigned int line_number);
void Adding_tow_elem(stack_t **stack, unsigned int line_number);
void Swaping_in_stack(stack_t **stack, unsigned int line_number);
void Nopping_nothing(stack_t **stack, unsigned int line_number);
int Handling_errors(stack_t **st, char *str, int nb);
void Subtracting_tow_elem(stack_t **stack, unsigned int nb);
void Dividing_tow_elem(stack_t **stack, unsigned int nb);
void Multipling_tow_elem(stack_t **stack, unsigned int nb);
void Mod_of_tow_elem(stack_t **stack, unsigned int nb);
void Printing_char(stack_t **stack, unsigned int nb);
void Printing_str(stack_t **stack, unsigned int nb);
FILE *Opennig_file (char *arr);
void Rotating_a_stack(stack_t **stack, unsigned int nb);
int Handling_errors_oper(stack_t **st, char *str, int nb);
int Error_ascii(stack_t **st, char *str, int nb);
void Help_error(char *str, int n, stack_t **st, char *l, char **t, FILE *fd);
void Printing_from_stack(stack_t **stack, unsigned int line_number);
void Safty_out(stack_t **stack, char *len, char **tab, FILE *fd);
void Finding_a_func(stack_t **stack, char *str, int line_number);
int Error(char *str);

#endif