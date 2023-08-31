#include "monty.h"

/**
 * execute_opcode - handles the excution, if a valid command is passed
 */

void execute_opcode(void)
{
	stack_t *stack = NULL;

	if (file_ptr->opcode_instruction->f)
	{
		if (strcmp(file_ptr->opcode_instruction->opcode, "push") != 0
				&& strcmp(file_ptr->mode,"queue") == 0)
		{
			if (count_stacks(file_ptr->head) >= 2)
			{
				/* converts the stack to queue to execute command */
				switch_stack();
				file_ptr->opcode_instruction->f(&stack,
						file_ptr->line_number);
				/* switches back to stack (default) after execution */
				switch_stack();
			}
			else
			{
				file_ptr->opcode_instruction->f(&stack,
						file_ptr->line_number);
			}
		}
		else
		{
			file_ptr->opcode_instruction->f(&stack,
					file_ptr->line_number);
		}
	}
	else
		invalid_instruction();
}

/**
 * switch_stack - converts stack to queue and vice versa
 */
void switch_stack(void)
{
	stack_t *current = NULL, *temp2 = NULL, *newnode = NULL, *inverted_head = NULL;

	if (file_ptr->head == NULL)
		return;

	current = file_ptr->head;
	/* tranverse temp to end of the head list */
	while(current->next != NULL)
		current = current->next;

	while (current != NULL)
	{
		newnode = malloc(sizeof(stack_t));
		if (newnode == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			while(inverted_head != NULL)
			{
				current = inverted_head;
				inverted_head = inverted_head->next;
				free(current);
			}
			free(newnode);
			return;
		}

		newnode->n = current->n;
		if (current->next == NULL)
		{
			inverted_head = newnode;
			newnode->prev = NULL;
			newnode->next = NULL;
			temp2 = newnode;
			current = current->prev;
		}
		else
		{
			temp2->next = newnode;
			newnode->prev = temp2;
			temp2 = newnode;
			temp2->next = NULL;
			current = current->prev;
		}
	}
	free_head(); /* frees the stack or queue */
	file_ptr->head = inverted_head; /* updates file_ptr->head */
}
