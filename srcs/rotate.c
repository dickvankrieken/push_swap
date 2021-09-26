#include "../push_swap.h"
#include "../libft/includes/ft_printf.h"

void	ra(t_stack *stack)
{
	rotate(stack);
	ft_printf("ra\n");
}

void	rb(t_stack *stack)
{
	rotate(stack);
	ft_printf("rb\n");
}

void	rotate(t_stack *stack)
{
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
}
