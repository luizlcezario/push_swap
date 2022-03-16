/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverses.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:53:15 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/15 21:23:28 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_a(t_push *stack)
{
	stack->a->is_top = FALSE;
	stack->a = stack->a->previous;
	stack->a->is_top = TRUE;
	ft_printf("rra\n");
}

void	reverse_b(t_push *stack)
{
	stack->b->is_top = FALSE;
	stack->b = stack->b->previous;
	stack->b->is_top = TRUE;
	ft_printf("rrb\n");
}

void	reverse_ab(t_push *stack)
{
	stack->a->is_top = FALSE;
	stack->a = stack->a->previous;
	stack->a->is_top = TRUE;
	stack->b->is_top = FALSE;
	stack->b = stack->b->previous;
	stack->b->is_top = TRUE;
	ft_printf("rrr\n");
}
