#include "../push_swap.h"
#include "../libft/includes/ft_printf.h"

static int	find_three_four(t_stack *stack_a)
{
	int		i;
	t_node	*node;

	node = stack_a->head;
	i = 1;
	while (node)
	{
		if (node->index >= 3)
		{
			return (i);
		}
		node = node->next;
		i++;
	}
	return (0);
}

static void	push_three_four_to_b(t_stack *stack_a, t_stack *stack_b)
{
	if (find_three_four(stack_a) > 3)
	{
		while (stack_a->head->index != 3 && stack_a->head->index != 4)
			rra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		while (stack_a->head->index != 3 && stack_a->head->index != 4)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	if (find_three_four(stack_a) > 2)
	{
		while (stack_a->head->index != 3 && stack_a->head->index != 4)
			rra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		while (stack_a->head->index != 3 && stack_a->head->index != 4)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	if (find_three_four(stack_a) >= 3)
	{
		while (stack_a->head->index != 3)
			rra(stack_a);
	}
	else
	{
		while (stack_a->head->index != 3)
			ra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	push_three_four_to_b(stack_a, stack_b);
	sort_three(stack_a);
	if (stack_b->head->index > stack_b->head->next->index)
		sb(stack_b);
	while (stack_b->size)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
	}
}
