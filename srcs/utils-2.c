#include "../push_swap.h"

int	get_max_bit(int size)
{
	int	i;

	i = 0;
	while ((size >> i) > 0)
	{
		i++;
	}
	return (i - 1);
}
