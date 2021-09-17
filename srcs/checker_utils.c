 #include "../push_swap.h"
#include "../checker.h"
#include "../libft/includes/libft.h"

void	add_operation(int code, t_operation_list *operation_list)
{
	if (!operation_list->head)
	{
		data->operation_list->head = malloc(sizeof(t_code));
		if (!data->operation_list->head)
			free_and_exit_checker(data);
	}
}

/*
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
*/
