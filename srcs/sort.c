#include "../push_swap.h"
#include "../libft/includes/ft_printf.h"

static void	sort_rest(t_stack *stack_a, t_stack *stack_b)
{
	int		max_bit;
	t_node	*node;
	t_node	*next;
	int		i;
	int		j;
	int		stack_size;

	j = 0;
	i = 0;
	stack_size = stack_a->size;
	node = stack_a->head;
	max_bit = get_max_bit(stack_a->size);
	while (i <= max_bit) // dit lijkt 1 keer te vaak er door te loopen, maar zonder die laatste loop gaat het ook niet goed .
	{
		while (j < stack_size)
		{
			next = node->next;
			if ((node->index >> i) & 1)
			{
				ra(stack_a);
			}
			else
			{
				pb(stack_a, stack_b);
			}
			node = next;
			j++;
		}
		j = 0;
		push_all_b_to_a(stack_a, stack_b);
		node = stack_a->head;
		i++;
	}
}

static void	sort_three(t_stack *stack_a)
{
	int	first;
	int	second;
	int	last;

	first = stack_a->head->data;
	second = stack_a->head->next->data;
	last = stack_a->tail->data;
	if (last > first && last < second)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first > second && first < last)
		sa(stack_a);
	else if (first < second && first > last)
		rra(stack_a);
	else if (first > second && second < last)
		ra(stack_a);
	else if (first > second && second > last)
	{
		sa(stack_a);
		rra(stack_a);
	}
}

static void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	if (stack_b->head->index < stack_b->tail->index)
		sb(stack_b);
	if (stack_b->head->index == 4)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	if (stack_b->head->index >= 3)
	{
	}
	if (stack_b->head->index <= 2)
	{
	}
	while (stack_b->size)
	{
		if ((stack_a->head->index - 1) == stack_b->head->index)
			pa(stack_a, stack_b);
		ra(stack_a);
	}
	while (stack_a->head->index != 0)
		ra(stack_a);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	set_index(stack_a);
//	print_stack_index(stack_a);
	if (stack_a->size == 2)
	{
		if (stack_a->head->data > stack_a->head->next->data)
		{
			swap(stack_a);
			ft_printf("sa\n");
		}
	}
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size <= 5)
		sort_five(stack_a, stack_b);
	else
		sort_rest(stack_a, stack_b);
}
