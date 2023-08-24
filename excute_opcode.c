#include "monty.h"

/**
 *
 */

void execute_opcode()
{
	stack_t *stack = NULL;

	if (file_ptr->opcode_instruction->f)
	{
		file_ptr->opcode_instruction->f(&stack,
				file_ptr->line_number);
	}
	else
		invalid_instruction();
}
