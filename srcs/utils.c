#include "../push_swap.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"

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
			{
				ft_printf("Invalid input, not all arguments are digits");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	check_duplicates(t_stack *stack)
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
				return (1);
			}
			compare_node = compare_node->next;
			j++;
		}
		j = i;
		i++;
		node = node->next;
	}
	return (0);
}

void	validate_arguments_and_init_stacks(t_stack *stack_a, t_stack *stack_b, char **argv)
{
	arguments_are_digits(argv);
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		error();
	init_stack(stack_a, argv);
	if (check_duplicates(stack_a))
	{
		free_stack(stack_a);
		error();
	}
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
	{
		free_stack(stack_a);
		error();
	}
	stack_b->size = 0;
}
