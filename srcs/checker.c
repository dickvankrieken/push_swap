#include <stdlib.h>
#include "../push_swap.h"
#include "../checker.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"
#include "../get_next_line/get_next_line.h"

t_stack	*validate_arguments_and_init_stack(t_stack *stack_a)
{
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
	data->stack_b = malloc(sizeof(t_stack));
	if (!data->stack_b)
	{
		free_stack(data->stack_a);
		error();
	}
	data->stack_b->size = 0;

	return stack_a;
}

void	add_operation(char *code, t_c_data *data)
{
	data->operation_list->code = code;
	data->operation_list->next = NULL;
}

void	validate_input(char *line)
{
	int	i;

	i = 0;
	if (!ft_strncmp(line, "sa", 2))
		add_operation(data);
	if (!ft_strncmp(line, "sb", 2))
		add_operation(data);
	if (!ft_strncmp(line, "ss", 2))
		add_operation(data);
	if (!ft_strncmp(line, "pa", 2))
		add_operation(data);
	if (!ft_strncmp(line, "pb", 2))
		add_operation(data);
	if (!ft_strncmp(line, "ra", 2))
		add_operation(data);
	if (!ft_strncmp(line, "rb", 2))
		add_operation(data);
	if (!ft_strncmp(line, "rra", 2))
		add_operation(data);
	if (!ft_strncmp(line, "rrb", 2))
		add_operation(data);
	if (!ft_strncmp(line, "rrr", 2))
		add_operation(data);
}

void		malloc_stacks(t_c_data *data)
{
	data->stack_a = malloc(sizeof(t_stacks));
	if (!data->stack_a)
	{
		free(data);
		error();
	}
	data->stack_b = malloc(sizeof(t_stacks));
	if (!data->stack_a)
	{
		free(data->stack_a);
		free(data);
		error();
	}
}

void	checker(char **argv)
{
	t_c_data *data;
	t_operation_list *operation_list;
	char *line;
/* ik ben de draad een beetje kwijt geraakt met die mallocs en waar nou wat in het geheugen staat en waarom het nou eigenlijk gemalloct moet worden en of het ook niet zonder kan en zo ... */

	data = malloc(sizeof(t_c_data));
	if (!data)
		error();
	malloc_stacks(data);
	operation_list = malloc(sizeof(t_operation_list));
	while (get_next_line(0, &line))
	{
/* wat er nu moet gebeuren: die check_input functie moet gaan kijken of de ingegeven lijn een correcte input is of dat het een ERROR geeft en gaat die input opslaan in de linked list  */
		validate_input(line);
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
