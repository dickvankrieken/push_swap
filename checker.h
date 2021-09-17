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

void	add_operation(int code, t_operation_list *operation_list);
void	read_input(t_operation_list *operation_list);
// void	validate_input(t_c_data *data, char *line);

#endif
