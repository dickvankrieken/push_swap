#include "../push_swap.h"
#include "../checker.h"
#include "../libft/includes/libft.h"

void	validate_arguments_and_init_stack(t_c_data *data, char **argv)
{
	if (!arguments_are_digits(argv))
		error();
	data->stack_a = malloc(sizeof(t_stack));
	if (!data->stack_a)
		error();
	init_stack(data->stack_a, argv);
	if (check_duplicates(data->stack_a))
	{
		free_stack(data->stack_a);
		error();
	}
	data->stack_b = malloc(sizeof(t_stack));
	if (!data->stack_b)
	{
		free_stack(data->stack_a);
		error();
	}
	data->stack_b->size = 0;
}


void	add_operation(int code, t_c_data *data)
{
	if (!data->operation_list->head)
	{
		data->operation_list->head = malloc(sizeof(t_code));
		if (!data->operation_list->head)
			free_and_exit_checker(data);
	}
}

void	validate_input(t_c_data *data, char *line)
{
	if (!ft_strncmp(line, "sa", 2))
		add_operation(data, 0);
	if (!ft_strncmp(line, "sb", 2))
		add_operation(data, 1);
	if (!ft_strncmp(line, "ss", 2))
		add_operation(data, 2);
	if (!ft_strncmp(line, "pa", 2))
		add_operation(data, 3);
	if (!ft_strncmp(line, "pb", 2))
		add_operation(data, 4);
	if (!ft_strncmp(line, "ra", 2))
		add_operation(data, 5);
	if (!ft_strncmp(line, "rb", 2))
		add_operation(data, 6);
	if (!ft_strncmp(line, "rra", 2))
		add_operation(data, 7);
	if (!ft_strncmp(line, "rrb", 2))
		add_operation(data, 8);
	if (!ft_strncmp(line, "rrr", 2))
		add_operation(data, 9);
}
