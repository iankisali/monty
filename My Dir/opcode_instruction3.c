#include "monty.h"

/**
 * mod - computes the rest of the division of the
 *	2nd top element
 * @head: pointer to first element
 * @numLine: line number
 * Return: void
 */
void mod(stack_t **head, unsigned int numLine)
{
	int num = 0;
	stack_t *temp = NULL;

	temp = *head;
	for (; temp != NULL; temp = temp->next, num++)
		;

	if (num < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", numLine);
		free_vlgo();
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n %= (*head)->n;
	pop(head, numLine);
}

/**
 * pchar - print char value of first element
 * @head: pointer to head node
 * @numLine: line number
 * Return: void
 */
void pchar(stack_t **head, unsigned int numLine)
{
	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", numLine);
		free_vlgo();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}

/**
 *pstr - print string of stack
 * @head: pointer to first node
 * @numLine: line number
 * Return: void
 */
void pstr(stack_t **head, unsigned int numLine)
{
	stack_t *temp;
	(void)numLine;

	temp = *head;

	while (temp && temp->n > 0 && temp->n < 128)
	{
		printf("%c", temp->n)
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - rotates stack to the top
 * @head: pointer to first node
 * @numLine: line number
 * Return: void
 */
void rotl(stack_t **head, unsigned int numLine)
{
	stack_t *temp1 = NULL;
	stack_t *temp2 = NULL;
	(void)numLine;

	if (*head == NULL)
		return;

	if ((*head)->next == NULL)
		return;

	temp1 = (*head)->next;
	temp2 = *head;

	for (; temp2->next != NULL; temp2 = temp2->next)
		;

	temp1->prev = NULL;
	temp2->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp2;
	*head = temp1;
}
/**
 * rotr - rverse stack
 * @head: pointer to first node
 * @numLine: line number
 * Return: void
 */
void rotr(stack_t **head, unsigned inr numLine)
{
	stack_t *temp = NULL;
	(void)numLine;

	if (*head == NULL)
		return;
	if ((*head)->next == NULL)
		return;

	temp = *head;

	for (; temp->next != NULL; temp = temp->next)
		;

	temp->prev->next = NULL;
	temp->next = *head;
	temp->prev = NULL;
	(*head)->prev = temp;
	*head = temp;
}
