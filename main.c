#include "monty.h"

/**
 *main - interpreter for monty
 *@argc: arguments counter
 *@argv: arguments value
 *Return: 0
 */

int main(int argc, char **argv)
{
	FILE *fd;
	char *buffer = NULL, **token;
	size_t size;
	stack_t **stack;
	unsigned int line_number = 1;

	stack = malloc(sizeof(stack_t *));
	if (stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (argc != 2) /*Mira que tenga el File para ejecutar*/
	{
		fprintf(stderr, "USAGE: monty file\n");
		free(stack);
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r"); /*Abre el file*/
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free(stack);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, fd) != EOF)
	{
		token = tokenize(buffer); /*Tokeniza para separar el comando del numero*/
		if (token[0] == NULL)
			continue;
		numbers = token[1]; /*Convierte en int, quizas toca hacerlo dsps*/
		match(token[0], stack, line_number);
		line_number++;
	}
	freestack(stack);
	free(buffer);
	fclose(fd);
	return (0);
}
