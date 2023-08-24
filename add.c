#include "monty.h"

/**
 * count_stacks - counts number of elements on the stack
 * @stack: stack
 *
 * Return: number of elements in stack
 */

int count_stacks(stack_t *stack)
{
	stack_t *temp = stack;
	int i;

	if (temp == NULL)
		return (0);
	i = 1;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

/**
 * add - adds the top two elements of the stack
 * @stack: stack
 * @line_number: line number of file to execute
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	int val1, val2;
	stack_t *temp;
	(void) *stack;

	temp = file_ptr->head;
	if (temp == NULL || count_stacks(file_ptr->head) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_file_ptr();
		exit(EXIT_FAILURE);
	}

	val1 = temp->n;
	temp = temp->next;
	val2 = temp->n;
	temp->n = val1 + val2;

	free(file_ptr->head);
	temp->prev = NULL;
	file_ptr->head = temp;
}
