#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void nop(stack_t **s, unsigned int line_num)
{
    /* No operation is performed */
    (void)s;
    (void)line_num;
}

/**
 * swap_nodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void swap_nodes(stack_t **s, unsigned int line_num)
{
    stack_t *t;

    if (s == NULL || *s == NULL || (*s)->next == NULL)
        more_errors(8, line_num, "swap");

    t = (*s)->next;
    (*s)->next = t->next;
    if (t->next != NULL)
        t->next->prev = *s;
    t->next = *s;
    (*s)->prev = t;
    t->prev = NULL;
    *s = t;
}

/**
 * add_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void add_nodes(stack_t **s, unsigned int line_num)
{
    int res;

    if (s == NULL || *s == NULL || (*s)->next == NULL)
        more_errors(8, line_num, "add");

    (*s) = (*s)->next;
    res = (*s)->n + (*s)->prev->n;
    (*s)->n = res;
    free((*s)->prev);
    (*s)->prev = NULL;
}

/**
 * sub_nodes - Subtracts the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void sub_nodes(stack_t **s, unsigned int line_num)
{
    int res;

    if (s == NULL || *s == NULL || (*s)->next == NULL)
        more_errors(8, line_num, "sub");

    (*s) = (*s)->next;
    res = (*s)->n - (*s)->prev->n;
    (*s)->n = res;
    free((*s)->prev);
    (*s)->prev = NULL;
}

void div_nodes(stack_t **s, unsigned int line_num)
{
    int res;

    if (s == NULL || *s == NULL || (*s)->next == NULL)
        more_errors(8, line_num, "div");

    if ((*s)->n == 0)
        more_errors(9, line_num);

    (*s) = (*s)->next;
    res = (*s)->n / (*s)->prev->n;
    (*s)->n = res;
    free((*s)->prev);
    (*s)->prev = NULL;
}

