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
	rrr
}	t_code;

typedef struct s_operation
{
	t_code	code;
	struct s_operation	*next;
}	t_operation;
