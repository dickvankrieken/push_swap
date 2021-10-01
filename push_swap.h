#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>

typedef struct s_node
{
	int	data;
	int index;
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
}	t_data;

/* utils.c */
void	set_index(t_stack *stack);
void		arguments_are_digits(char **argv);
void		check_duplicates(t_stack *stack);
void	validate_arguments_and_init_stacks(t_stack *stack_a, t_stack *stack_b, char **argv);
int	is_sorted(t_stack *stack_a, t_stack *stack_b);
/* utils-2.c */
int		get_max_bit(int size);
/* swap.c */
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	swap(t_stack *stack);
/* push.c */
void	push_all_b_to_a(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *from, t_stack *to);
/* rotate.c */
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rotate(t_stack *stack);
/* reverse_rotate.c */
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	reverse_rotate(t_stack *stack);
/* stacks.c */
void	print_stack_index(t_stack *stack);
void	print_stack(t_stack *stack);
t_stack	*init_stack(char **argv);
void	free_stack(t_stack *stack);
void	free_stacks_and_exit(t_stack *stack_a, t_stack *stack_b);
/* nodes.c */
t_node	*create_head_node(t_stack *stack, int data);
t_node	*create_new_node(t_stack *stack, t_node *previous, t_node *first, int data);
/* error.c */
void	error();
/* sort.c */
void	sort(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *stack_a);
/* sort_four_five.c */
void	sort_four(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
#endif
