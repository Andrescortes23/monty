#include "monty.h"
/**
 *tokenize - make tokens from strings in file
 *@s: string
 *Return: pointer to array of tokens
 */
char **tokenize(char *s)
{
	int it = 0;
	char **buf = NULL;
	char *token = NULL;

	buf = malloc(sizeof(char *) * 3);
	if (buf == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(s, "\t\n ");
	while (token != NULL)
	{
		buf[it] = token;
		it++;
		token = strtok(NULL, "\t\n ");
	}
	return (buf);
}
