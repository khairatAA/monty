#ifndef MONTY_H
#define MONTY_H

/* HEADER FILES*/

#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* DATA STRUCTURES */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct File_content - a struct containing item of a line
 * @file: pointer to the file
 * @line: a pointer to the line read by getline
 * @line_number: the line number been read
 * @num_tokens: number of tokens passed
 * @tokens: contains the tokenized string
 * @opcode_instruction: array holding a instruction_t struct
 * @head: pointer to the head
 */

typedef struct File_content
{
	FILE *file;
	char *line;
	unsigned int line_number;
	int num_tokens;
	char **tokens;
	instruction_t *opcode_instruction;
	stack_t *head;
} File_content;

extern File_content *file_ptr;

/* FUNCTION PROTOTYPES */

void count_arguments(int argc);
int main(int argc, char **argv);
void handle_file_opening(const char *name_of_file, FILE **file);
File_content *allocated_file_content(void);
void parse_line(void);
void get_opcode_func(void);
void invalid_instruction(void);
void fclose_file(void);
void free_tokens(void);
void free_file_ptr(void);
void execute_opcode(void);
void push(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *head);
int is_digit_(char *str);
void free_head(void);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
