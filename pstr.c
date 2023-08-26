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
	else
	{
		while (temp != NULL)
		{
			if ((temp->n >= 65 && temp->n <= 90)
					|| (temp->n >= 97 && temp->n <= 122))
				printf("%c", temp->n);
			if (temp->n == 0)
				break;
			temp = temp->next;
		}

		printf("\n");
	}
}
