#include "../push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*head;
	t_node	*node;

	head = stack->head;
	node = stack->head;
	stack->head = stack->head->next;
	while (node->next != NULL)
		node = node->next;
	node->next = head;
	head->next = NULL;
}


void	reverse_rotate(t_stack *stack)
{
	t_node	*new_first;
	t_node	*new_last;
	t_node	*last;

	new_first = stack->head;
	while (new_first->next != NULL)
	{
		if (new_first->next->next == NULL)
		{
			new_last = new_first;
		}
		new_first = new_first->next;
	}
	new_first->next = stack->head;
	stack->head = new_first;
	last = stack->head;
	new_last->next = NULL;
}
