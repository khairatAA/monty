#ifndef MONTY_H
#define MONTY_H

/* HEADER FILES*/

#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
 *
 */

typedef struct
{
	FILE *file;
	unsigned int line_number;
} File_content;

/* FUNCTION PROTOTYPES */

void count_arguments(int argc);
int main(int argc, char **argv);
void handle_file_opening(const char *name_of_file, FILE **file);
File_content *allocated_file_content(void);
void free_file_ptr(File_content *file_ptr);
#endif /* MONTY_H */
