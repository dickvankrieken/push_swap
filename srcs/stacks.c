#include "../push_swap.h"
#include "../libft/includes/ft_printf.h"
#include "../libft/includes/libft.h"

void	print_stack(t_stack *stack)
{
	t_node	*node;

	node = stack->head;
	while (node && 1)
	{
		ft_printf("%d\n", node->data);
		node = node->next;
		if (node == stack->head)
			break ;
	}
}

void	print_stack_index(t_stack *stack)
{
	t_node	*node;

	node = stack->head;
	while (node && 1)
	{
		ft_printf("%d\n", node->data);
		ft_printf("index: %d\n", node->index);
		node = node->next;
		if (node == stack->head)
			break ;
	}
}

void	free_stacks_and_exit(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	exit(EXIT_SUCCESS);
}

t_stack	*init_stack(char **argv)
{
	t_stack	*stack;
	t_node	*new_node;
	t_node	*previous;
	t_node	*first;
	int		i;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		error();
	new_node = create_head_node(stack, ft_atoi(argv[1]));
	previous = new_node;
	first = new_node;
	i = 2;
	while (argv[i])
	{
		new_node = create_new_node(stack, previous, first, ft_atoi(argv[i]));
		previous = new_node;
		i++;
	}
	return (stack);
}

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*next_node;

	node = stack->head;
	if (stack->size > 0)
	{
		while (1)
		{
			next_node = node->next;
			free(node);
			node = next_node;
			if (node == stack->head)
				break ;
		}
	}
	free(stack);
}
