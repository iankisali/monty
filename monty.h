#ifndef _MONTY_
#define _MONTY_

#include <stdio.h>
#include <stdlib>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>


/**
 * struct stack_s - DLL representation of stack/queue
 * @n: integer
 * @prev: point to prev element
 * @next: point to next element
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct globals - global structure 
 * @lifo: stack or queue
 * @cont: current line
 * @arg: second parameter in line
 * @head: DLL
 * @fd: file descriptor
 * @buffer: input text
 */
typedef struct globals
{
	int lifo;
	char *buffer
	char *arg;
	unsigned int cont;
	stack_t *head;
	FILE *fd;
} global_t;

extern global_t vglo;

/**
 * struct instruction_s - opcode and its functions
 * @opcode: opcode
 * @func: function to handle opcode
 *
 *  Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*func)(stack_t **stack, unsigned int numLine);
} instruction_t;

/*get opcodes*/
void (*getopcodes(char *opcode))(stack_t **stack, unsigned int numLine);

/*Doubly Linked List functions*/
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/*Opcode Instructions*/
void push(stack_t **head, unsigned int numLine);
void pall(stack_t **head, unsigned int numLine);
void pint(stack_t **head, unsigned int numLine);
void pop(stack_t **head, unsigned int numLine);
void swap(stack_t **head, unsigned int numLine);
void add(stack_t **head, unsigned int numLine);
void nop(stack_t **head, unsigned int numLine);
void sub(stack_t **head, unsigned int numLine);
void div(stack_t **head, unsigned int numLine);
void mul(stack_t **head, unsigned int numLine);
void mod(stack_t **head, unsigned int numLine);
void pchar(stack_t **head, unsigned int numLine);
void pstr(stack_t **head, unsigned int numLine);
void rotl(stack_t **head, unsigned int numLine);
void rotr(stack_t **head, unsigned inr numLine);
void stack(stack_t **head, unsigned int numLine);
void queue(stack_t **head, unsigned int numLine);

/* main*/
void free_vglo(void);

/*imported func*/
char *stroky(char *s, char *d);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);
int search(char *s, char c);
int strcmp(char *str1, char *str2);
#endif
