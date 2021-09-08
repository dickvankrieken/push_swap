#include "../push_swap.h"
#include "../libft/includes/libft.h"

int	arguments_are_digits(char **argv)
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
			{
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	check_duplicates(t_stack *stack)
{
	t_node	*node;
	t_node	*compare_node;
	int		size;

	size = stack->size;
	node = stack->head;
	while (node->next != stack->head)
	{
		compare_node = node->next;
		while (compare_node != node)
		{
			if (compare_node->data == node->data)
			{
				return (1);
			}
			compare_node = compare_node->next;
		}
		node = node->next;
	}
	return (0);
}
