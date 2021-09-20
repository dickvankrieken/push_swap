#include "../libft/includes/ft_printf.h"
#include "../libft/includes/libft.h"
#include "../push_swap.h"

void	push_swap(char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	arguments_are_digits(argv);
	stack_a = init_stack(argv);
	if (check_duplicates(stack_a))
	{
		ft_printf("Invalid input, contains duplicates");
		free_stack(stack_a);
		exit(EXIT_FAILURE);
	}
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
	{
		ft_printf("Malloc error");
		free_stack(stack_a);
		exit(EXIT_FAILURE);
	}
	stack_b->size = 0;
	if (is_sorted(stack_a, stack_b))
		free_stacks_and_exit(stack_a, stack_b);
	else
		ft_sort(stack_a, stack_b);




	ft_printf("stack a na init: \n");
	print_stack(stack_a);

	/* reverse_rotate(stack_a); */
	/* ft_printf("stack a na rotate: \n"); */
	/* print_stack(stack_a); */

	/* reverse_rotate(stack_a); */
	/* ft_printf("stack a na reverse_rotate: \n"); */
	/* print_stack(stack_a); */

	/* reverse_rotate(stack_a); */
	/* ft_printf("stack a na rotate: \n"); */
	/* print_stack(stack_a); */

	/* reverse_rotate(stack_a); */
	/* ft_printf("stack a na reverse_rotate: \n"); */
	/* print_stack(stack_a); */

	swap(stack_a);
	ft_printf("stack a na swap: \n");
	print_stack(stack_a);
	// ft_printf("stack b na push: \n");
	// print_stack(stack_b);

	// push(stack_a, stack_b);
	// ft_printf("stack a na push: \n");
	// print_stack(stack_a);
	// ft_printf("stack b na push: \n");
	// print_stack(stack_b);

	// push(stack_a, stack_b);
	// ft_printf("stack a na push: \n");
	// print_stack(stack_a);
	// ft_printf("stack b na push: \n");
	// print_stack(stack_b);

	/* swap(stack_b); */
	/* ft_printf("stack b na swap: \n"); */
	/* print_stack(stack_b); */

	/* swap(stack_b);	 */
	/* ft_printf("stack b na swap: \n"); */
	/* print_stack(stack_b); */
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_printf("Not enough arguments");
	else
		push_swap(argv);
}
