#include "../libft/includes/ft_printf.h"
#include "../libft/includes/libft.h"
#include "../push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*node;

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
	int		i;

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
	stack->tail = new_node;
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
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!arguments_are_digits(argv))
	{
		ft_printf("Invalid input, not all arguments are digits");
		exit(EXIT_FAILURE);
	}
	stack_a = malloc(sizeof(t_stack));
	init_stack(stack_a, argv);
	if (check_duplicates(stack_a))
	{
		ft_printf("Invalid input, contains duplicates");
		free_stack(stack_a);
		exit(EXIT_FAILURE);
	}
	stack_b = malloc(sizeof(t_stack));
	stack_b->size = 0;
	print_stack(stack_a);
	push(stack_a, stack_b);
	ft_printf("stack a na push: \n");
	print_stack(stack_a);
	ft_printf("stack b na push: \n");
	print_stack(stack_b);
	push(stack_a, stack_b);
	ft_printf("stack a na push: \n");
	print_stack(stack_a);
	ft_printf("stack b na push: \n");
	print_stack(stack_b);
	push(stack_a, stack_b);
	ft_printf("stack a na push: \n");
	print_stack(stack_a);
	ft_printf("stack b na push: \n");
	print_stack(stack_b);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_printf("Not enough arguments");
	else
		push_swap(argv);
}
