#include "monty.h"
/**
 *add - adds the top two elements of stack
 *@stack: the stack
 *@line_number: file lines number
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

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
