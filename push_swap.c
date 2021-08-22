/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/15 14:47:32 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/08/22 16:05:16 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/ft_printf.h"
#include "push_swap.h"

void	init_stack(t_stack **stack, char **argv)
{
	t_node	*new_node;


}

void	push_swap(int argc, char **argv)
{
	t_stack *stack_a;

	init_stack(stack_a, argv);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_printf("Not enough arguments");
	else
		push_swap(argc, argv);
}
