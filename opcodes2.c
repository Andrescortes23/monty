#include "monty.h"
/**
 *add - adds the top two elements of stack
 *@stack: the stack
 *@line_number: file lines number
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
		return;

	if (tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		freestack(*stack);
		exit(EXIT_FAILURE);
	}

	tmp->next->n += (*stack)->n;
	*stack = (*stack)->next;
	free(tmp);
	(*stack)->prev = NULL;
}

/**
 *nop - doesn't do anything
 *@stack: stack
 *@line_number: file lines number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
