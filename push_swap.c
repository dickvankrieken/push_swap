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
the check_arguments function checks if each and every argv argument actually is a number
argv consists of an array of strings so we loop through every character of every string 
and for each character we check if it is a number or not
whenever a non-digit is found return 0, if only digits are found a 1 is returned.
*/

int		arguments_are_digits(char **argv)
{
	int	i;

	i = 1;
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

/*
the no_double_arguments function checks 
if the data integers of the nodes from a stack
are all unique so that there are no duplicates
*/

int		check_doubles(t_stack *stack)
{
	t_node	*node = stack->first;
	int numbers[];

	while (node)
	{
		if (numbers[node->value])
			return (1);
		else
			number[node->value] = 1;
		node->next;
		
	}
}

void	push_swap(char **argv)
{
	t_stack *stack_a;
	/* TODO: check if arguments are valid */
	arguments_are_digits(argv);
	check_doubles(stack_a);
	stack_a = malloc(sizeof(t_stack));
	init_stack(stack_a, argv);
	/* now that stack a is initialized... things have to be done, but what? */
	/* TODO: check for doubles */

	print_stack(stack_a);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_printf("Not enough arguments");
	else
		push_swap(argv);
}
