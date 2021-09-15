#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>

typedef struct s_node
{
	int	data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	size_t	size;
}	t_stack;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
} t_data;

/* utils.c */
int		arguments_are_digits(char **argv);
int		check_duplicates(t_stack *stack);
/* swap.c */
void	swap(t_stack *stack);
/* push.c */
void	push(t_stack *from, t_stack *to);
/* rotate.c */
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
/* stacks.c */
void	print_stack(t_stack *stack);
void	init_stack(t_stack *stack, char **argv);
void	free_stack(t_stack *stack);
t_node	*create_head_node(t_stack *stack, int data);
t_node	*create_new_node(t_stack *stack, t_node *previous, t_node *first, int data);
/* error.c */
void	error();

#endif
