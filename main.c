#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argczr: arguments count
 * @argvaze: list of arguments
 * Return: always 0
 */

int main(int argczr, char *argvaze[])
{
	if (argczr != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	opfnm(argvaze[1]);
	free_nodes();
	return (0);
}

/**
 * cretnode - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *cretnode(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		error(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - Frees nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * add_to_queue - Adds a node to the queue.
 * @nevonode: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void add_to_queue(stack_t **nevonode, __attribute__((unused)) unsigned int ln)
{
	stack_t *tmp;

	if (nevonode == NULL || *nevonode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *nevonode;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *nevonode;
	(*nevonode)->prev = tmp;
}
