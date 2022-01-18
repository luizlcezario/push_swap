/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:52:56 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/14 17:41:37 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_push *stack)
{
	stack->A->is_top = FALSE;
	stack->A = stack->A->next;
	stack->A->is_top = TRUE;
	ft_printf("ra\n");
}

void	rotate_b(t_push *stack)
{
	stack->B->is_top = FALSE;
	stack->B = stack->B->next;
	stack->B->is_top = TRUE;
	ft_printf("rb\n");
}

void	rotate_ab(t_push *stack)
{
	stack->A->is_top = FALSE;
	stack->A = stack->A->next;
	stack->A->is_top = TRUE;
	stack->B->is_top = FALSE;
	stack->B = stack->B->next;
	stack->B->is_top = TRUE;
	ft_printf("rr\n");
}