#include "monty.h"
/**
 *match - match with opcode and its function
 *@token: first token from the file
 *@stack: stack to fill
 *@line_number: file line number
 */
void match(char *token, stack_t **stack, unsigned int line_number)
{
	int count = 0;

	instruction_t codes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"NULL", NULL}
	};

	while (count < 6)
	{
		if (strcmp(codes[count].opcode, token) == 0)
		{
			codes[count].f(stack, line_number);
			return;
		}
		count++;
	}
	freestack(*stack);
	fprintf(stderr, "L%d: unknow instruction %s\n", line_number, token);
	exit(EXIT_FAILURE);
}

/**
 *freestack - free the stack
 *@stack: stack to free
 */
void freestack(stack_t *stack)
{
	stack_t *tmp;

	tmp = stack;

	while (stack != NULL)
	{
		tmp = tmp->next;
		free(stack);
		stack = tmp;
	}
}

/**
 *error - print error
 *@line_number: the line in file
 */
void error(unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
}

/**
 *wrongnum - check if the numbers are empty or its a white space
 *@num: number
 *@lin_num: line of file
 *@stack: stack
 *@new: node
 */
void wrongnum(char *num, unsigned int lin_num, stack_t **stack, stack_t *new)
{
	if (num == NULL || isspace(num[0]) != 0)
	{
		error(lin_num);
		freestack(*stack);
		free(new);
		exit(EXIT_FAILURE);
	}
}
