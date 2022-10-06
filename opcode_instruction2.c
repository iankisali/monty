#include "monty.h"

/**
 * add - adds top two elements of stack
 * @head: pointer to first node
 * @numLine: line number
 * Return: void
 */
void add(stack_t **head, unsigned int numLine)
{
	int num = 0;
	stack_t *temp = NULL;

	temp = *head;
	for (; temp != NULL; temp = temp->next, num++)
		;

	if (num < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", numLine);
		fre_vglo();
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	temp->n += (head)->n;
	pop(head, numLine);
}

/**
 * nop - does not do anything
 * @head: pointer to head
 * @numLine: line number
 * Return: void
 */
void nop(stack_t **head, unsigned int numLine)
{
	(void)head;
	(void)numLine;
}

/**
 * sub - subracts top elements
 * @head: pointer to first element
 * @numLine: line number
 * Return: void
 */
void sub(stack_t **head, unsigned int numLine)
{
	int num = 0;
	stack_t *temp = NULL;

	temp = *head;

	for (; temp != NULL; temp = temp->next, num++)
		;

	if (num < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", numLine);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n -= (*head)->n;
	pop(head, numLine);
}

/**
 * div - divides the second element by the top element of the stack
 *
 * @head: head of the linked list
 * @numLine: line number;
 * Return: no return
 */
void div(stack_t **head, unsigned int numLine)
{
	int num = 0;
	stack_t *temp = NULL;

	temp = *head;

	for (; temp != NULL; temp = temp->next, num++)
	{
		dprintf(2, "L%u: can't div, stack too short\n", numLine);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", numLine);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n /= (*head)->n;
	pop(head, numLine);
}

/**
 * mul - multiplies two elements
 * @head: pointer to first node
 * @numLine: line number
 * Return: void
 */
void mul(stack_t **head, unsigned int numLine)
{
	int num = 0;
	stack_t *temp = NULL;

	temp = *head;

	for (; temp != NULL; temp = temp->next, num++)
		;
	if (num < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", numLine);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n *= (*head)->n;
	pop(head, numLine);
}
