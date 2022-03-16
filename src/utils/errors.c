/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:26:46 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/15 21:23:23 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_message(char *str)
{
	ft_printf("%s\n", str);
	return (1);
}

void	free_all(t_push *stack)
{
	t_stack	*tmp;

	while (--stack->count_element_a >= 0)
	{
		tmp = stack->a->next;
		free(stack->a);
		stack->a = tmp;
	}
	free(stack->original);
}
