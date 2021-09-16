#include <stdlib.h>
#include "../push_swap.h"
#include "../checker.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"
#include "../get_next_line/get_next_line.h"

void	malloc_stacks(t_c_data *data)
{
	data->stack_a = malloc(sizeof(t_stack));
	if (!data->stack_a)
	{
		error();
	}
	data->stack_b = malloc(sizeof(t_stack));
	if (!data->stack_a)
	{
		free(data->stack_a);
		free(data);
		error();
	}
}

void	free_and_exit_checker(t_c_data *data)
{
	free(data->stack_a);
	free(data->stack_b);
	free(data);
	exit(EXIT_FAILURE);
}

void	checker(char **argv)
{
	t_c_data *data;
	char *line;
	data = malloc(sizeof(t_c_data));
	if (!data)
		error();
	validate_arguments_and_init_stack(data, argv);
	data->operation_list = malloc(sizeof(t_operation_list));
	if (!data->operation_list)
		free_and_exit_checker(data);
	while (get_next_line(0, &line))
	{
/* wat er nu moet gebeuren: die check_input functie moet gaan kijken of de ingegeven lijn een correcte input is of dat het een ERROR geeft en gaat die input opslaan in de linked list  */
		validate_input(data, line);
		ft_printf("%s", line);
	}
/* WIP */
	print_stack(data->stack_a);
}

int	main(int argc, char **argv)
{
	if (argc > 2)
	{
		checker(argv);
	}
}
