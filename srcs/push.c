#include "../push_swap.h"

void	push(t_stack *from, t_stack *to)
{
	t_node	*tmp;

	tmp = from->head;
	from->head = from->head->next;
	from->size--;
	if (to->size == 0)
		tmp->next = NULL;
	else
		tmp->next = to->head;
	to->head = tmp;
	to->size++;
}
