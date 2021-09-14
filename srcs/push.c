#include "../push_swap.h"

void	push(t_stack *from, t_stack *to)
{
	t_node	*tmp;

	tmp = from->head;
	if (from->size == 1)
	{
		from->head = NULL;
		from->tail = NULL;
	}
	else
	{
		from->head = from->head->next;
		from->tail->next = from->head;
	}
	from->size--;
	if (to->size == 0)
	{
		tmp->next = tmp;
		to->tail = tmp;
	}
	else
		tmp->next = to->head;
	to->head = tmp;
	to->tail->next = to->head;
	to->size++;
}
