#include "../push_swap.h"
#include "../libft/includes/ft_printf.h"

static void	sort_rest_loop(t_stack *a, t_stack *b, int max_bit, int size)
{
	t_node	*node;
	t_node	*next;
	int		i;
	int		j;

	i = 0;
	j = 0;
	node = a->head;
	while (i <= max_bit)
	{
		while (j < stack_size)
		{
			next = node->next;
			if ((node->index >> i) & 1)
				ra(a);
			else
				pb(a, b);
			node = next;
			j++;
		}
		j = 0;
		push_all_b_to_a(a, b);
		node = a->head;
		i++;
	}
}

static void	sort_rest(t_stack *stack_a, t_stack *stack_b)
{
	int		max_bit;
	int		stack_size;

	stack_size = stack_a->size;
	max_bit = get_max_bit(stack_a->size);
	sort_rest_loop(stack_a, stack_b, max_bit, stack_size);
}

void	sort_three(t_stack *stack_a)
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

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	set_index(stack_a);
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
	else if (stack_a->size == 4)
		sort_four(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_five(stack_a, stack_b);
	else
		sort_rest(stack_a, stack_b);
}
