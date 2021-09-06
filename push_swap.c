#include "libft/includes/ft_printf.h"
#include "libft/includes/libft.h"
#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node *node;

	node = stack->head;
	ft_printf("%d\n", node->data);
	node = node->next;
	while (node != stack->head)
	{
		ft_printf("%d\n", node->data);
		node = node->next;
	}
}

void	init_stack(t_stack *stack, char **argv)
{
	t_node	*new_node;
	t_node	*node;
	t_node	*first;
	int	i;

	new_node = malloc(sizeof(t_node));
	new_node->data = ft_atoi(argv[1]);
	new_node->next = new_node;
	node = new_node;
	first = new_node;
	stack->size++;
	i = 2;
	while (argv[i])
	{
		new_node = malloc(sizeof(t_node));
		new_node->data = ft_atoi(argv[i]);
		node->next = new_node;
		new_node->next = first;
		node = new_node;
		i++;
		stack->size++;
	}
	stack->head = first;
}

/*
the check_arguments function checks if each argv argument actually is a number
when a non-digit is found 0 is returned
if only digits are found a 1 is returned.
*/

int		arguments_are_digits(char **argv)
{
	int	i;
	int j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		check_duplicates(t_stack *stack)
{
	t_node	*node;
	t_node	*compare_node;
	int	size;

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

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*next_node;

	node = stack->head;
	while (node)
	{
		next_node = node->next;
		free(node);
		node = next_node;
	}
	free(stack);
}

void	push_swap(char **argv)
{
	t_stack *stack_a;

	arguments_are_digits(argv);

	stack_a = malloc(sizeof(t_stack));
	init_stack(stack_a, argv);
	if(check_duplicates(stack_a))
	{
		ft_printf("Invalid input, contains duplicates");
		free_stack(stack_a);
	}
	print_stack(stack_a);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_printf("Not enough arguments");
	else
		push_swap(argv);
}
