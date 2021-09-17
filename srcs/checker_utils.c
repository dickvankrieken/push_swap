#include "../push_swap.h"
#include "../checker.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"
#include "../get_next_line/get_next_line.h"

void	validate_line(char *line)
{
	if (ft_strncmp("OK", line, 2))
		ft_printf("SAME");
}

void	read_input(t_operation_list *operation_list)
{
	char *line;
	while (get_next_line(0, &line))
	{
		validate_line(line);
	}

}
