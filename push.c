#include "monty.h"

/**
 * push - prints all the values on the stack, starting
 * from the top of the stack
 * @stack: a pointer to the stack struct
 * @line_number: the line number of each line in the file
 */

void push(stack_t **stack, unsigned int line_number)
{
	if (file_ptr->num_tokens <= 1 || !(is_digit_(file_ptr->tokens[1])))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose_file();
		free_tokens();
		free_file_ptr();
		exit(EXIT_FAILURE);
	}
	/*printf("in push DEBUG: Token[1]: %s\n", file_ptr->tokens[1]);*/
	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose_file();
		free_tokens();
		free_file_ptr();
		exit(EXIT_FAILURE);
	}

	(*stack)->next = (*stack)->prev = NULL;
	(*stack)->n = (int) atoi(file_ptr->tokens[1]);
	if (file_ptr->head != NULL)
	{
		(*stack)->next = file_ptr->head;
		file_ptr->head->prev = *stack;
	}
	file_ptr->head = *stack;
}

/**
 * is_digit_ - checks if a string is a digit
 * @str: the string o check
 * Return: 0 on success
 */

int is_digit_(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (i == 0 && str[i] == '-' && str[i + 1])
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

/**
 * free_stack - handles the free of all the stacks created
 * @head: a pointer to the head of the node
 */

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

/**
 * free_head - frees the head pointer
 */

void free_head(void)
{
	if (file_ptr->head)
		free_stack(file_ptr->head);
	file_ptr->head = NULL;
}
