#include "monty.h"

/**
 * handle_hash - When the first non-space character of a line is #,
 * treat this line as a comment
 *
 * Return: void
 */

void handle_hash(void)
{
	file_ptr->opcode_instruction->opcode = "nop";
	file_ptr->opcode_instruction->f = nop;
}
