#include "../push_swap.h"

void	rotate(t_stack *stack)
{
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
}

void	reverse_rotate(t_stack *stack)
{
	stack->head = stack->tail;
	stack->tail = stack->tail->prev;
}
