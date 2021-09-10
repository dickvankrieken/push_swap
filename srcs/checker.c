#include <stdlib.h>
#include "../push_swap.h"
#include "../libft/includes/ft_printf.h"

void	checker(char **argv)
{
	t_stack	*stack_a;

	stack_a = malloc(sizeof(t_stack));
	init_stack(stack_a, argv);
	print_stack(stack_a);
}

int	main(int argc, char **argv)
{
	if (argc > 2)
	{
		checker(argv);
	}		
}
