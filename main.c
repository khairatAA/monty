#include "monty.h"

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
	File_content *file_ptr;

	file_ptr = (File_content *)malloc(sizeof(File_content));
	if (file_ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	file_ptr->file = NULL;
	file_ptr->line_number = 0;
	/* Initalize other properties of the struct here*/

	return (file_ptr);
}

/**
 *
 */

void free_file_ptr(File_content *file_ptr)
{
	fclose(file_ptr->file);
	free(file_ptr);
}

/**
 *
 */

int main(int argc, char **argv)
{
	File_content *file_ptr = allocated_file_content();
	char *line = NULL;
	size_t line_size = 0;

	count_arguments(argc);
	handle_file_opening(argv[1], &(file_ptr->file));
	if (file_ptr->file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_file_ptr(file_ptr);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &line_size, file_ptr->file) != -1)
	{
		printf("%s", line);
	}

	free(line);
	free_file_ptr(file_ptr);
	return (0);
}
