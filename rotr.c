#include "monty.h"

/**
 * rotr - rotates the stack to the bottom, making the
 * last element the first and leaving the rest intact
 *
 * @stack: stack
 * @line_number: line number of file to execute
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *current;
	(void) *stack;
	(void) line_number;

	temp = file_ptr->head;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't rotl, stack too short\n", line_number);
		free_file_ptr();
		exit(EXIT_FAILURE);
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = file_ptr->head;
	current = temp->prev;
	temp->prev = NULL;
	current->next = NULL;
	file_ptr->head->prev = temp;
	file_ptr->head = temp;
}
