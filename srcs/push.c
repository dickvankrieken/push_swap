#include "../push_swap.h"

void	push(t_stack *from, t_stack *to)
{
	t_node	*tmp;

	tmp = from->head;
	from->head = from->head->next;
	from->tail->next = from->head;
	from->size--;
	tmp->next = to->head;
	to->head = tmp;
	to->tail->next = to->head;
	to->size++;
}
