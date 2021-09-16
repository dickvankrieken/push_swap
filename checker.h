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
}	t_operation_list;

typedef struct s_c_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_operation_list	*operation_list;
}	t_c_data;

void	add_operation(int code, t_c_data *data);
void	validate_arguments_and_init_stack(t_c_data *data, char **argv);
void	validate_input(t_c_data *data, char *line);
void	free_and_exit_checker(t_c_data *data);

#endif
