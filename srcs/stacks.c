#include "../push_swap.h"
#include "../libft/includes/ft_printf.h"
#include "../libft/includes/libft.h"

void	print_stack(t_stack *stack)
{
	t_node	*node;

	node = stack->head;
	while (node != NULL)
	{
		ft_printf("%d\n", node->data);
		node = node->next;
	}
}

void	init_stack(t_stack *stack, char **argv)
{
	t_node	*new_node;
	t_node	*node;
	int		i;

	new_node = malloc(sizeof(t_node));
	new_node->data = ft_atoi(argv[1]);
	new_node->next = NULL;
	node = new_node;
	stack->head = new_node;
	stack->size++;
	i = 2;
	while (argv[i])
	{
		new_node = malloc(sizeof(t_node));
		new_node->data = ft_atoi(argv[i]);
		node->next = new_node;
		new_node->next = NULL;
		node = new_node;
		i++;
		stack->size++;
	}
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
