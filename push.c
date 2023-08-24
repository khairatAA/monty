#include "monty.h"

/**
 *
 */

void push(stack_t **stack, unsigned int line_number)
{
	if (file_ptr->num_tokens < 2 || !(is_digit_(file_ptr->tokens[1])))
	{
		free_file_ptr();
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*printf("DEBUG: Token[1]: %s\n", file_ptr->tokens[1]);*/
	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (int) atoi(file_ptr->tokens[1]);
	(*stack)->prev = (*stack)->next = NULL;
	if (file_ptr->head != NULL)
	{
		(*stack)->next = file_ptr->head;
		file_ptr->head->prev = *stack;
	}
	file_ptr->head = *stack;
}

int is_digit_(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
		{
			i++;
			continue;
		}
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void free_stack(stack_t *head)
{
	if (head == NULL)
		return;
	if (head->next != NULL)
	{
		free_stack(head->next);
	}
	free(head);
}

void free_head(void)
{
	if (file_ptr->head)
		free_stack(file_ptr->head);
	file_ptr->head = NULL;
}
