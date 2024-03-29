#include "monty.h"

/**
 * print_char - Prints the ASCII value.
 * @s: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the opcode.
 */
void print_char(stack_t **s, unsigned int ln)
{
	int ascii;

	if (s == NULL || *s == NULL)
		string_err(11, ln);

	ascii = (*s)->n;
	if (ascii < 0 || ascii > 127)
		string_err(10, ln);
	printf("%c\n", ascii);
}

/**
 * print_str - Prints a string.
 * @s: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the opcode.
 */
void print_str(stack_t **s, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *t;

	if (s == NULL || *s == NULL)
	{
		printf("\n");
		return;
	}

	t = *s;
	while (t != NULL)
	{
		ascii = t->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		t = t->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @s: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the opcode.
 */
void rotl(stack_t **s, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (s == NULL || *s == NULL || (*s)->next == NULL)
		return;

	tmp = *s;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *s;
	(*s)->prev = tmp;
	*s = (*s)->next;
	(*s)->prev->next = NULL;
	(*s)->prev = NULL;
}

/**
 * rotr - Rotates the last node of the stack to the top.
 * @s: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the opcode.
 */
void rotr(stack_t **s, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (s == NULL || *s == NULL || (*s)->next == NULL)
		return;

	tmp = *s;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *s;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*s)->prev = tmp;
	*s = tmp;
}

