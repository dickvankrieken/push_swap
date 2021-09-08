#include <stddef.h>

typedef struct s_node
{
	int	data;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	size_t	size;
}	t_stack;

int		arguments_are_digits(char **argv);
int		check_duplicates(t_stack *stack);
void	swap(t_stack *stack);
void	push(t_stack *from, t_stack *to);
