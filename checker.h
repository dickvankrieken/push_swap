#ifndef CHECKER_H
# define CHECKER_H

typedef enum e_code
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	ERROR
}	t_code;

typedef struct s_operation
{
	t_code	*code;
	struct s_operation	*next;
}	t_operation;

typedef struct s_operation_list
{
	t_code	*head;
	t_code	*tail;
}

typedef struct s_c_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_operation	*operation_list;
}	t_c_data;

void	add_operation(t_c_data *data);

#endif
