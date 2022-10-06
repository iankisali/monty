#include "monty.h"
/**
 * push - pushes element to stack
 * @head: head of linked list
 * @numLine: line number
 * Return: void
 */
void push(stack_t **head, unsigned int numLine)
{
	int i, j;

	if (!vglo.arg)
	{
		dprintf(2, "L%u: ", numLine);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	for (j = 0; vglo.arg[j] != '\0'; j++)
	{
		if (!isdigit(vglo.arg[j]) && vglo.arg[j] != '-')
		{
			dprintf(2, "L%u: ", numLine);
			dprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint(doubly, n);
	else
		add_dnodeint_end(doubly, n);
}

/**
 * pall - print value on stack
 * @numLine: line numbers
 * @head: pointer to first node
 * Return: void
 */
void pall(stack_t **head, unsigned int numLine)
{
	(void)numLine;

	while (*head)
	{
		printf("%d\n", (*head)->n);
		*head = (*head)->next;
	}
}
/**
 * pint - print value at top of stack
 * @head: pointer to first node
 * @numLine: line number
 * Return: void
 */
void pint(stack_t **head, unsigned int numLine)
{
	(void)NumLine;

	if (*head == NULL)
	{
		dprintf(2, "L%u: ", numLine);
		dprintf(2, "can't pint, stack empty\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pop - removes top element of stack
 * @numLine: line number
 * @head: pointer to head
 * Return: void
 */
void pop(stack_t **head, unsigned int numLine)
{
	stack_t *temp;

	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", numLine);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	free(temp);
}

/**
 * swap - swap top two lements of stack
 * @head: pointer to first element
 * @numLine: line number
 * Return: void
 */
void swap(stack_t **head, unsigned int numLine)
{
	int num = 0;
	stack_t *temp = NULL;

	temp = *head;

	for (; temp != NULL; temp = temp->next, num++)
		;

	if (num < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", numLine);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	temp->prev = *head;
	(*head)->next = temp;
	(*head)->prev = NULL;
}
