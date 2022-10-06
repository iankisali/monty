#include "monty.h"

global_t vglo;


/**
 * start_vglo - initialize global variables
 * @fd: file descriptor
 * Return: void
 */
void start_vglo(FILE *fd)
{
	vglo.lifo = 1;
	vglo.cont = 1;
	vglo.arg = NULL;
	vglo.head = NULL;
	vglo.fd = fd;
	vglo.buffer = NULL;
}
/**
 * free_vglo - free global variable
 * Return: void
 */
void free_vglo(void)
{
	free_dlistint(vglo.head);
	free(vglo.head);
	fclose(vglo.fd);
}

/**
 * check_input - check if file exist and if can be opened
 * @argc: argument count
 * @argv: argument vector
 * Return: file
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: void
 */
int main(int argc, char *argv[])
{
	void (*func)(stack_t **stack, unsigned int numLine);
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_input(argc, argv);
	start_vglo(fd);
	nlines = getline(&vglo.buffer, &size, fd);
	while (nlines != -1)
	{
		lines[0] = stroky(vglo.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			func = get_opcodes(lines[0]);
			if (!func)
			{
				dprintf(2, "L%u: ", vglo.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_vglo();
				exit(EXIT_FAILURE);
			}
			vglo.arg = stroky(NULL, " \t\n");
			func(&vglo.head, vglo.cont);
		}
		nlines = getline(&vglo.buffer, &size, fd);
		vglo.cont++;
	}
	free_vglo();

	return (0);
}
