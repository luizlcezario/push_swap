/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverses.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:53:15 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/14 17:41:26 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_a(t_push *stack)
{
	stack->A->is_top = FALSE;
	stack->A = stack->A->previus;
	stack->A->is_top = TRUE;
	ft_printf("rra\n");
}

void	reverse_b(t_push *stack)
{
	stack->B->is_top = FALSE;
	stack->B = stack->B->previus;
	stack->B->is_top = TRUE;
	ft_printf("rrb\n");
}

void	reverse_ab(t_push *stack)
{
	stack->A->is_top = FALSE;
	stack->A = stack->A->previus;
	stack->A->is_top = TRUE;
	stack->B->is_top = FALSE;
	stack->B = stack->B->previus;
	stack->B->is_top = TRUE;
	ft_printf("rrr\n");
}