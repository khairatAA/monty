#include "monty.h"

/**
 * pint - prints all the values on the stack, starting
 * from the top of the stack
 * @stack: a pointer to the stack struct
 * @line_number: the line number of each line in the file
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void) *stack;

	current = file_ptr->head;
	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		free_file_ptr();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", current->n);
}
