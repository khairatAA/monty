#include "monty.h"

/**
 *
 */

void get_opcode_func(void)
{
	size_t i;

	static instruction_t opcodes[] = {
		/* {"push", push}, */
		/* {"pall", pall}, */
		/* This will increase as we keep implementing */
		{NULL, NULL}
	};

	if (file_ptr->num_tokens == 0)
		return;
	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcodes[i].opcode, file_ptr->tokens[0]) == 0)
		{
			file_ptr->opcode_instruction->opcode = opcodes[i].opcode;
			file_ptr->opcode_instruction->f = opcodes[i].f;
			return;
		}
	}
	invalid_instruction();
}

/**
 *
 */

void invalid_instruction(void)
{
	fprintf(stderr, "L%d: unknown instruction %s\n",
			file_ptr->line_number, file_ptr->tokens[0]);
	fclose_file();
	free_tokens();
	free_file_ptr();
	exit(EXIT_FAILURE);
}

/**
 *
 */

void fclose_file(void)
{
	if (file_ptr->file != NULL)
	{
		fclose(file_ptr->file);
	}
	file_ptr->file = NULL;
}

/**
 *
 */

void free_tokens(void)
{
	int i = 0;

	if (file_ptr->tokens == NULL)
		return;
	while (file_ptr->tokens[i])
	{
		free(file_ptr->tokens[i]);
		i++;
	}
	free(file_ptr->tokens);
	file_ptr->tokens = NULL;
}

/**
 *
 */

void free_file_ptr(void)
{
	free(file_ptr->opcode_instruction);
	free(file_ptr);
}
