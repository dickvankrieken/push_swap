#include "../push_swap.h"
#include "../libft/includes/libft.h"

t_node	*create_head_node(t_stack *stack, int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		error();
	new_node->data = data;
	new_node->next = new_node;
	new_node->prev = new_node;
	stack->head = new_node;
	stack->tail = new_node;
	stack->size = 1;
	return (new_node);
}

t_node	*create_new_node(t_stack *stack, t_node *prev, t_node *first, int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		error();
	new_node->data = data;
	prev->next = new_node;
	new_node->next = first;
	new_node->prev = prev;
	stack->head->prev = new_node;
	stack->tail = new_node;
	stack->size++;
	return (new_node);
}
