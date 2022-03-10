/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:25:16 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/10 14:30:16 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	verify_ordenation(t_push *stack,t_stack *tmp)
{
	int	a;
	int	*new;

	a = -1;
	if (stack->count_element_B == 0)
	{
		new = malloc(stack->count_element_A * sizeof(int));
		while (++a < stack->count_element_A)
		{
			new[a] = tmp->num;
			tmp = tmp->next;
		}
		while (--a >= 0)
		{
			if (stack->original[a] != new[a])
				return(FALSE);
		}
		return (TRUE);
	}
	return (FALSE);
}