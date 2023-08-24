#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: stack
 * @line_number: line number of file to execute
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) *stack;
	(void) line_number;

	temp = file_ptr->head;
	if (temp == NULL)
	{
		printf("\n");
	}

	printf("%c", temp->n);
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (!(temp->n >= 'A' && temp->n <= 'Z')
				&& !(temp->n >= 'a' && temp->n <= 'z'))
			break;
		if (temp->n == 0)
			break;
		printf("%c", temp->n);
	}

	printf("\n");
}
