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

t_node	*create_head_node(t_stack *stack, int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		error();
	new_node->data = data;
	new_node->next = new_node;
	new_node->prev = new_node;
	stack->head = new_node;
	stack->tail = new_node;
	stack->size = 1;
	return (new_node);
}

t_node	*create_new_node(t_stack *stack, t_node *prev, t_node *first, int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		error();
	new_node->data = data;
	prev->next = new_node;
	new_node->next = first;
	new_node->prev = prev;
	stack->head->prev = new_node;
	stack->tail = new_node;
	stack->size++;
	return (new_node);
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
	while (1)
	{
		next_node = node->next;
		free(node);
		node = next_node;
		if (node == stack->head)
			break ;
	}
	free(stack);
}
