#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @stack: stack
 * @line_number: line number of file to execute
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) *stack;

	temp = file_ptr->head;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_file_ptr();
		exit(EXIT_FAILURE);
	}

	if ((temp->n >= 'A' && temp->n <= 'Z') || (temp->n >= 'a' && temp->n <= 'z'))
		printf("%c\n", temp->n);
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_file_ptr();
		exit(EXIT_FAILURE);
	}
}
