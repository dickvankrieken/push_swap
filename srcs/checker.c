#include <stdlib.h>
#include "../push_swap.h"
#include "../checker.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"
#include "../get_next_line/get_next_line.h"

void	malloc_stacks(t_stack *stack_a, t_stack *stack_b)
{
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
	{
		error();
	}
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a)
	{
		free(stack_a);
		error();
	}
}

void	free_and_exit_checker(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		free(stack_a);
	if (stack_b)
		free(stack_b);
	exit(EXIT_FAILURE);
}

void	checker(char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_operation_list	*operation_list;

	stack_a = NULL;
	stack_b = NULL;
	if (!stack_b)
		ft_printf("OK");
	validate_arguments_and_init_stacks(stack_a, stack_b, argv);
	operation_list = malloc(sizeof(t_operation_list));
	if (!operation_list)
		free_and_exit_checker(stack_a, stack_b);
/* wat er nu moet gebeuren: die check_input functie moet gaan kijken of de ingegeven lijn een correcte input is of dat het een ERROR geeft en gaat die input opslaan in de linked list  */
	read_input(operation_list);

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
