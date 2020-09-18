#include "monty.h"
/**
 *push - push elements to stack
 *@stack: stack to fill
 *@line_number: file line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	int it = 0;
	stack_t *new;
	int num;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		freestack(stack);
		exit(EXIT_FAILURE);
	}

	wrongnum(numbers, line_number, stack, new);

	while (numbers[it] != '\0')
	{
		if (isdigit(numbers[it]) == 0)
		{
			error(line_number);
			freestack(stack);
			free(new);
			exit(EXIT_FAILURE);
		}
		it++;
	}
	num = atoi(numbers);
	new->n = num;
	if (*stack == NULL)
	{
		*stack = new;
		(*stack)->next = NULL;
		(*stack)->prev = NULL;
	}
	else
	{
		(*stack)->prev = new;
		new->next = (*stack);
		(*stack) = new;
		new->prev = NULL;
	}
}

/**
 *pall - to print elements in stack
 *@stack: the stack
 *@line_number: file line number
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		fprintf(stdout, "%d\n", tmp->n);
		tmp = tmp->next;
	}
}
