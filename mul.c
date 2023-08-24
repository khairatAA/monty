#include "monty.h"

/**
 * mul - multiplies the second top element stack
 * with the top element of the stack
 * @stack: stack
 * @line_number: line number of file to execute
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int val1, val2;
	stack_t *temp;
	(void) *stack;

	temp = file_ptr->head;
	if (temp == NULL || count_stacks(file_ptr->head) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_file_ptr();
		exit(EXIT_FAILURE);
	}

	val1 = temp->n;
	temp = temp->next;
	val2 = temp->n;
	temp->n = val2 * val1;

	free(file_ptr->head);
	temp->prev = NULL;
	file_ptr->head = temp;
}
