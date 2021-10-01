#include "../push_swap.h"
#include "../libft/includes/libft.h"

void	set_index(t_stack *stack)
{
	t_node	*node;
	t_node	*compare_node;
	int		i;
	int		j;

	i = 0;
	node = stack->head;
	compare_node = stack->head;
	while (i < (int)stack->size)
	{
		while (j < (int)stack->size)
		{
			if (compare_node->data < node->data)
			{
				node->index++;
			}
			compare_node = compare_node->next;
			j++;
		}
		compare_node = stack->head;
		j = 0;
		node = node->next;
		i++;
	}
}

int	is_sorted(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	node = stack_a->head;
	if (stack_b->size > 0)
		return (0);
	while (node->next != stack_a->head)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}

void	arguments_are_digits(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (j == 0 && argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]))
				j++;
			else if (!ft_isdigit(argv[i][j]))
				error();
			j++;
		}
		j = 0;
		i++;
	}
}

void	check_duplicates(t_stack *stack)
{
	t_node	*node;
	t_node	*compare_node;
	size_t	i;
	size_t	j;

	i = 1;
	j = 1;
	node = stack->head;
	while (i < stack->size)
	{
		compare_node = node->next;
		while (j < stack->size)
		{
			if (compare_node->data == node->data)
			{
				free_stack(stack);
				error();
			}
			compare_node = compare_node->next;
			j++;
		}
		j = i;
		i++;
		node = node->next;
	}
}
