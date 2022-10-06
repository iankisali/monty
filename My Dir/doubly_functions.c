#include "monty.h"

/**
 * add_dnodeint - add node at beginning of DLL
 * @head: first node
 * @n: data
 * Return: void
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *temp;

	if (head == NULL)
		return (NULL);

	temp = malloc(sizeof(stack_t));

	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	temp->n = n;

	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	(*head)->prev = temp;
	temp->next = (*head);
	temp->prev = NULL;
	*head = temp;
	return (*head);
}


/**
 * add_dnodeint_end - add node at end of DLL
 * @head: first node
 * @n: data
 * Return: DLL
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *temp;

	if (head == NULL)
		return (NULL);

	temp = malloc(sizeof(stack_t));

	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	temp->n = n

	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}

	while ((*head)->next)
		(*head) = (*head)->next;
	temp->next = (*head)->next;
	temp->prev = (*head);
	(*head)->next = temp;
	return ((*head)->next);
}

/**
 * free_dlistint - fres DLL
 * @head: head
 * Return: void
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while ((temp = head) != NULL)
	{
		head = head->next;
		free(temp);
	}
}
