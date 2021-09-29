#include "../push_swap.h"
#include "../libft/includes/ft_printf.h"

static void	sort_rest(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bit;
	t_node	*node;
	t_node	*next;
	int	i;
	int	j;
	int	stack_size;

	j = 0;
	i = 0;
	stack_size = stack_a->size;
	node = stack_a->head;
	max_bit = get_max_bit(stack_a->size);
	ft_printf("max_bit = %d\n", max_bit);
	while (i <= max_bit)
	{
		ft_printf("NEXT\n");
		while (j < stack_size)
		{
			ft_printf("--index=%d--\n", node->index);
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
		node = stack_a->head;
		push_all_b_to_a(stack_a, stack_b);
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

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	set_index(stack_a);
	print_stack_index(stack_a);
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
	else
	{
		sort_rest(stack_a, stack_b);
		ft_printf("size stack_b: %d \n", stack_b->size);
	}
}
