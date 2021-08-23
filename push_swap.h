#include <stddef.h>

typedef struct s_node
{
	int	data;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	size_t	size;
}	t_stack;
