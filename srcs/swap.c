#include "../push_swap.h"
#include "../libft/includes/ft_printf.h"

void	sa(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	swap(stack);
	ft_printf("sa\n");
}

void	sb(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	swap(stack);
	ft_printf("sb\n");
}

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	first = stack->head;
	second = stack->head->next;
	if (stack->size == 2)
		stack->tail = first;
	first->prev = stack->head->next;
	first->next = stack->head->next->next;
	second->next = first;
	second->prev = stack->tail;
	stack->tail->next = second;
	stack->head = second;
}
