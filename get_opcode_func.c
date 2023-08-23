#include "monty.h"

/**
 *
 */

void get_opcode_func(const char *opcode,
		void (**f)(stack_t **stack, unsigned int line_number))
{
	size_t i;

	static instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
	};
}
