#include "monty.h"

/**
 * stack - sets the format fo the data to a stack (LIFO)
 * @head: pointer to first node
 * @numLine: line number
 * Return: void
 */
void stack(stack_t **head, unsigned int numLine)
{
	(void)head;
	(void)numLine;

	vglo.lifo = 1;
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @head: pointer to first node
 * @numLine: line number
 * Return: void
 */
void queue(stack_t **head, unsigned int numLine)
{
	(void)head;
	(void)numLine;

	vglo.lifo = 0;
}
