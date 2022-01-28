/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:42:47 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/27 17:40:45 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_push *stack)
{
	t_stack *tmp;

	stack->A->previous->next = stack->A->next;
	stack->A->next->previous = stack->A->previous;
	if (stack->A->previous->previous == stack->A->next)
		stack->A->previous->previous = stack->A;
	tmp = stack->A->next->next;
	stack->A->next->next = stack->A;
	stack->A->previous = stack->A->next;
	stack->A = stack->A->next;
	stack->A->next->next = tmp;
	stack->A->is_top = TRUE;
	stack->A->next->is_top = FALSE;
	ft_printf("sa\n");
}

void	swap_b(t_push *stack)
{
	t_stack *tmp;

	stack->B->previous->next = stack->B->next;
	stack->B->next->previous = stack->B->previous;
	tmp = stack->B->next->next;
	stack->B->next->next = stack->B;
	stack->B->previous = stack->B->next;
	stack->B = stack->B->next;
	stack->B->next->next = tmp;
	stack->B->is_top = TRUE;
	stack->B->next->is_top = FALSE;
	ft_printf("sb\n");
}

void	swap_ab(t_push *stack)
{
	t_stack *tmp;

	stack->A->previous->next = stack->A->next;
	stack->A->next->previous = stack->A->previous;
	tmp = stack->A->next->next;
	stack->A->next->next = stack->A;
	stack->A->previous = stack->A->next;
	stack->A = stack->A->next;
	stack->A->next->next = tmp;
	stack->A->is_top = TRUE;
	stack->A->next->is_top = FALSE;
	stack->B->previous->next = stack->B->next;
	stack->B->next->previous = stack->B->previous;
	tmp = stack->B->next->next;
	stack->B->next->next = stack->B;
	stack->B->previous = stack->B->next;
	stack->B = stack->B->next;
	stack->B->next->next = tmp;
	stack->B->is_top = TRUE;
	stack->B->next->is_top = FALSE;
	ft_printf("ss\n");
}