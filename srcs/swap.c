#include "../push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*tmp;

	// if (stack->size > 1)
	// {
	// 	new_head = stack->head->next;
	// 	stack->head->next = stack->head->next->next;
	// 	stack->head->prev = new_head;
	// 	new_head->next = stack->head;
	// 	stack->head = new_head;
	// 	stack->tail->next = new_head;
	// 	if (stack->size == 2)
	// 		stack->tail = new_head->next;
	// }
	if (stack->size < 2)
		return ;
	tmp = stack->head;
	
}

/*
tmp wordt gelijk gesteld aan de head

wat moet er veranderen:

stack->head wordt stack->head->next
stack->head->next wordt tmp
stack->head->prev wordt 
als de size == 2 verandert de tail naar tmp en de tmp->next wordt gelijkgesteld aan stack->head
stack->head->prev wordt 
 */