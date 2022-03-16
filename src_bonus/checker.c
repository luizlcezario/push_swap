/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:02:35 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/16 17:37:48 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	move(t_push *stack, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		swap_a(stack);
	else if (!ft_strncmp(str, "sb\n", 3))
		swap_b(stack);
	else if (!ft_strncmp(str, "ss\n", 3))
		swap_ab(stack);
	else if (!ft_strncmp(str, "pa\n", 3))
		push_a(stack, stack->b);
	else if (!ft_strncmp(str, "pb\n", 3))
		push_b(stack, stack->a);
	else if (!ft_strncmp(str, "ra\n", 3))
		rotate_a(stack);
	else if (!ft_strncmp(str, "rb\n", 3))
		rotate_b(stack);
	else if (!ft_strncmp(str, "rr\n", 3))
		rotate_ab(stack);
	else if (!ft_strncmp(str, "rra\n", 4))
		reverse_a(stack);
	else if (!ft_strncmp(str, "rrb\n", 4))
		reverse_b(stack);
	else if (!ft_strncmp(str, "rrr\n", 4))
		reverse_ab(stack);
	else
		return (1);
	return (0);
}

t_bool	checker(t_push *stack)
{
	char	*str;

	str = get_next_line(STDIN_FILENO);
	while (str != NULL)
	{
		if (move(stack, str) == 1)
		{
			free(str);
			stack->err = 1;
			return (FALSE);
		}
		free(str);
		str = get_next_line(STDIN_FILENO);
	}
	return (verify_ordination(stack, stack->a));
}
