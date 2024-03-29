#include "monty.h"

void mul_nodes(stack_t **s, unsigned int line_num)
{
    int res;

    if (s == NULL || *s == NULL || (*s)->next == NULL)
        more_errors(8, line_num, "mul");

    (*s) = (*s)->next;
    res = (*s)->n * (*s)->prev->n;
    (*s)->n = res;
    free((*s)->prev);
    (*s)->prev = NULL;
}


/**
 * mod_nodes - Computes the modulo of the top two elements of the stack.
 * @s: Pointer to a pointer pointing to the top node of the stack.
 * @line_num: Integer representing the line number of the opcode.
 */
void mod_nodes(stack_t **s, unsigned int line_num)
{
    int res;

    if (s == NULL || *s == NULL || (*s)->next == NULL)
        more_errors(8, line_num, "mod");

    if ((*s)->n == 0)
        more_errors(9, line_num);

    (*s) = (*s)->next;
    res = (*s)->n % (*s)->prev->n;
    (*s)->n = res;
    free((*s)->prev);
    (*s)->prev = NULL;
}

