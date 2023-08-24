#include "monty.h"

/**
 * parse_line - it handles the tokenization of the string enter
 */

void parse_line(void)
{
	int i = 0;
	char *line_copy = NULL, *token = NULL;

	line_copy = malloc(sizeof(char) * (strlen(file_ptr->line) + 1));
	if (line_copy == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	strcpy(line_copy, file_ptr->line);
	file_ptr->num_tokens = 0;
	token = strtok(line_copy, " \n");
	while (token)
	{
		file_ptr->num_tokens += 1;
		token = strtok(NULL, " \n");
	}
	file_ptr->tokens = malloc(sizeof(char *) *
			(file_ptr->num_tokens + 1));
	if (file_ptr->tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	strcpy(line_copy, file_ptr->line);
	token = strtok(line_copy, " \n");
	while (token)
	{
		file_ptr->tokens[i] = malloc(sizeof(char) *
				(strlen(token) + 1));
		if (file_ptr->tokens[i] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		strcpy(file_ptr->tokens[i], token);
		token = strtok(NULL, " \n");
		i++;
	}
	file_ptr->tokens[i] = NULL;
	free(line_copy);
}
