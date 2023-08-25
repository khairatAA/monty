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

	temp = current = file_ptr->head;
	/* might remove NULL conditon since rotl should never fail */
	if (temp == NULL)
	{
		free_file_ptr();
		return;
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	current = current->next;
	temp->next = file_ptr->head;
	file_ptr->head->next = NULL;
	file_ptr->head->prev = temp;
	file_ptr->head = current;

}