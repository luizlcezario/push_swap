/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:25:16 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/12 00:02:02 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	verify_ordination(t_push *stack,t_stack *tmp)
{
	int	a;

	a = -1;
	if (stack->count_element_B == 0)
	{
		while (++a < stack->count_element_A)
		{
			if (stack->original[a] != tmp->num)
				return(FALSE);
			tmp = tmp->next;
		}
		return (TRUE);
	}
	return (FALSE);
}