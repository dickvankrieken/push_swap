#include "../push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head->next;
	stack->head->next = stack->head->next->next;
	tmp->next = stack->head;
	stack->head = tmp;
	stack->tail->next = stack->head;
}
