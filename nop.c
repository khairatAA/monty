#include "monty.h"

/**
 * nop - nop doesn’t do anything.
 * @stack: a pointer to the stack struct
 * @line_number: the line number of each line in the file
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) *stack;
	(void) line_number;
}
