#include "../push_swap.h"
#include "../libft/includes/ft_printf.h"

void	push_all_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size)
	{
		pa(stack_a, stack_b);
	}
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}

void	push_check_last_node(t_stack *from)
{
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
}

void	push(t_stack *from, t_stack *to)
{
	t_node	*tmp;

	if (from->size == 0)
		return ;
	tmp = from->head;
	push_check_last_node(from);
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
