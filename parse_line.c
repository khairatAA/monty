#include "monty.h"

/**
 *
 */

void parse_line(char *line)
{
	int num_tokens = 0;
	char *arg = NULL, *line_copy = NULL;
	char *opcode = NULL;

	line_copy = strdup(line);
	if (line_copy == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	opcode = strtok(line_copy, " \n");
	if (opcode)
	{
		num_tokens = 1;
		arg = strtok(NULL, " \n");
		while (arg)
		{
			num_tokens++;
			arg = strtok(NULL, " \n");
		}
		file_ptr->tokens = (char **)malloc(num_tokens *
				sizeof(char *));
		if (file_ptr->tokens == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		file_ptr->num_tokens = num_tokens;
	}
	free(line_copy);
}
