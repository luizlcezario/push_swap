/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:52:56 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/16 17:31:47 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_push *stack)
{
	if (stack->a != NULL)
	{
		stack->a->is_top = FALSE;
		stack->a = stack->a->next;
		stack->a->is_top = TRUE;
		ft_printf("ra\n");
	}
}

void	rotate_b(t_push *stack)
{
	if (stack->b != NULL)
	{
		stack->b->is_top = FALSE;
		stack->b = stack->b->next;
		stack->b->is_top = TRUE;
		ft_printf("rb\n");
	}
}

void	rotate_ab(t_push *stack)
{
	stack->a->is_top = FALSE;
	stack->a = stack->a->next;
	stack->a->is_top = TRUE;
	stack->b->is_top = FALSE;
	stack->b = stack->b->next;
	stack->b->is_top = TRUE;
	ft_printf("rr\n");
}
