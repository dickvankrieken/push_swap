#include <stdlib.h>
#include "../push_swap.h"
#include "../checker.h"
#include "../libft/includes/ft_printf.h"

t_stack	*validate_arguments_and_init_stack(char **argv)
{
	t_stack	*stack_a;

	if (!arguments_are_digits(argv))
		error();
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		error();
	init_stack(stack_a, argv);
	if (check_duplicates(stack_a))
	{
		free_stack(stack_a);
		error();
	}
	return stack_a;
}

void	checker(char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_operation	*operation_list;
	char *line;

	stack_a = validate_arguments_and_init_stack(argv);
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
	{
		free_stack(stack_a);
		error();
	}
	stack_b->size = 0;
	operation_list = malloc(sizeof(t_operation));
	if (!operation_list)
	{
		free_stack(stack_a)
		error();
	}
	get_next_line(0, &line);
/* WIP */
	print_stack(stack_a);
}

int	main(int argc, char **argv)
{
	if (argc > 2)
	{
		checker(argv);
	}		
}
