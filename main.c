#include "monty.h"
#include <stdio.h>
#define BUFFER_SIZE 120
/**
 * main - main entry
 * @ac: number of arguments
 * @av: array of string arguments
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	FILE *fp;
	char buffer[BUFFER_SIZE];
	int line = 0;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, BUFFER_SIZE, fp) != NULL)
	{
		line++;
		stack_op_choice(buffer, line, &stack);
	}
	fclose(fp);
	return (0);
}
