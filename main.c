#include "monty.h"

 File_content *file_ptr = NULL;

/**
 *
 */

void count_arguments(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 *
 */

void handle_file_opening(const char *name_of_file, FILE **file)
{
	*file = fopen(name_of_file, "r");
	if (*file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", name_of_file);
		exit(EXIT_FAILURE);
	}
}

/**
 *
 */

File_content *allocated_file_content(void)
{
	file_ptr = (File_content *)malloc(sizeof(File_content));
	if (file_ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	file_ptr->file = NULL;
	file_ptr->line = NULL;
	file_ptr->line_number = 0;
	file_ptr->num_tokens = 0;
	file_ptr->tokens = NULL;
	file_ptr->head = NULL;
	file_ptr->opcode_instruction = (instruction_t *)
		malloc(sizeof(instruction_t));
	if (file_ptr->opcode_instruction == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	file_ptr->opcode_instruction->opcode = NULL;
	file_ptr->opcode_instruction->f = NULL;
	/* Initalize other properties of the struct here*/

	return (file_ptr);
}

/**
 *
 */

int main(int argc, char **argv)
{
	size_t line_size = 0;

	count_arguments(argc);
	file_ptr = allocated_file_content();
	handle_file_opening(argv[1], &(file_ptr->file));
	if (file_ptr->file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_file_ptr();
		exit(EXIT_FAILURE);
	}

	while (getline(&file_ptr->line, &line_size, file_ptr->file) != -1)
	{
		file_ptr->line_number = file_ptr->line_number + 1;
		parse_line();
		get_opcode_func();
		execute_opcode();
		free_tokens();
	}

	fclose_file();
	free_file_ptr();
	return (0);
}
