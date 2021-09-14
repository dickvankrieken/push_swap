#include "../push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*new_head;

	if (stack->size > 1)
	{
		new_head = stack->head->next;
		stack->head->next = stack->head->next->next;
		stack->head->prev = new_head;
		new_head->next = stack->head;
		stack->head = new_head;
		stack->tail->next = new_head;
		if (stack->size == 2)
			stack->tail = new_head->next;
	}
}
