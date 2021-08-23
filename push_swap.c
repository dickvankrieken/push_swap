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

void	push_swap(char **argv)
{
	t_stack *stack_a;

	stack_a = malloc(sizeof(t_stack));
	init_stack(stack_a, argv);
	print_stack(stack_a);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_printf("Not enough arguments");
	else
		push_swap(argv);
}
