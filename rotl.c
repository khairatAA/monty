#include "monty.h"

/**
 * rotl - rotates the stack to the top, putting first
 * element at the end and leaving the rest intact
 *
 * @stack: stack
 * @line_number: line number of file to execute
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *current;
	(void) *stack;
	(void) line_number;

	if (count_stacks(file_ptr->head) < 2)
	{
		return;
	}

	temp = file_ptr->head;
	current = temp->next;
	while (current != NULL)
	{
		if (current->next == NULL)
		{
			current->next = temp;
			temp->next = NULL;
			temp->prev = current;
			break;
		}
		current = current->next;
	}
}
