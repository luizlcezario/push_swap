/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverses.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:53:15 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/27 17:49:02 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_a(t_push *stack)
{
	stack->A->is_top = FALSE;
	stack->A = stack->A->previous;
	stack->A->is_top = TRUE;
	ft_printf("rra\n");
}

void	reverse_b(t_push *stack)
{
	stack->B->is_top = FALSE;
	stack->B = stack->B->previous;
	stack->B->is_top = TRUE;
	ft_printf("rrb\n");
}

void	reverse_ab(t_push *stack)
{
	stack->A->is_top = FALSE;
	stack->A = stack->A->previous;
	stack->A->is_top = TRUE;
	stack->B->is_top = FALSE;
	stack->B = stack->B->previous;
	stack->B->is_top = TRUE;
	ft_printf("rrr\n");
}