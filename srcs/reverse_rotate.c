#include "../push_swap.h"
#include "../libft/includes/ft_printf.h"

void	rra(t_stack *stack)
{
	reverse_rotate(stack);
	ft_printf("rra\n");
}

void	rrb(t_stack *stack)
{
	reverse_rotate(stack);
	ft_printf("rrb\n");
}

void	reverse_rotate(t_stack *stack)
{
	stack->head = stack->tail;
	stack->tail = stack->tail->prev;
}
