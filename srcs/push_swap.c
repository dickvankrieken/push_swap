#include "../libft/includes/ft_printf.h"
#include "../libft/includes/libft.h"
#include "../push_swap.h"

static t_stack	*malloc_stack_b(t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
	{
		free_stack(stack_a);
		error();
	}
	stack_b->size = 0;
	return (stack_b);
}

void	push_swap(char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	arguments_are_digits(argv);
	stack_a = init_stack(argv);
	check_duplicates(stack_a);
	stack_b = malloc_stack_b(stack_a);
	if (is_sorted(stack_a, stack_b))
		free_stacks_and_exit(stack_a, stack_b);
	else
		sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_printf("Not enough arguments");
	else
		push_swap(argv);
}
