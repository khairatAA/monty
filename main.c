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

int main(int argc, char **argv)
{
	FILE *file;

	count_arguments(argc);
	handle_file_opening(argv[1], &file);


	fclose(file);
	return (0);
}
