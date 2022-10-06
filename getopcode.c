#include "monty.h"
/**
 * getopcodes - finds opcode
 *
 * @opcode: opcode passed
 * Return: pointer to function that executes opcode
 */
void (*getopcodes(char *opcode))(stack_t **stack, unsigned int numLine)
{
	instrunction_t instruct[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}

	};
	int num;

	for (num = 0; instruct[num].opcode; num++)
	{
		if (strcmp(instruct[num].opcode, opcode) == 0)
			break;
	}
	return (instruct[num].func);
}
