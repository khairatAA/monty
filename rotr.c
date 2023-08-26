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
	if (count_stacks(file_ptr->head) < 2)
	{
		return;
	}

	while (temp != NULL)
	{
		if (temp->next == NULL)
		{
			current = temp;
			break;
		}
		temp = temp->next;
	}
	current->prev->next = NULL;
	current->next = file_ptr->head;
	current->prev = NULL;
	file_ptr->head = current;
}
