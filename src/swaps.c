/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:42:47 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/14 20:58:26 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_push *stack)
{
	t_stack *tmp;

	tmp = stack->A;
	stack->A = stack->A->next;
	tmp->previus->next = stack->A;
	stack->A->previus = tmp->previus;
	tmp->next = stack->A->next;
	stack->A->next->previus = tmp;
	tmp->previus = stack->A;
	stack->A->next = tmp;
	tmp->is_top = FALSE;
	stack->A->is_top = TRUE;
	ft_printf("sa\n");
}

void	swap_b(t_push *stack)
{
	t_stack *tmp;

	tmp = stack->B;
	stack->B = stack->B->next;
	tmp->previus->next = stack->B;
	stack->B->previus = tmp->previus;
	tmp->next = stack->B->next;
	stack->B->next->previus = tmp;
	tmp->previus = stack->B;
	stack->B->next = tmp;
	tmp->is_top = FALSE;
	stack->B->is_top = TRUE;
	ft_printf("sb\n");
}

void	swap_ab(t_push *stack)
{
	t_stack *tmp;

	tmp = stack->A;
	stack->A = stack->A->next;
	tmp->previus->next = stack->A;
	stack->A->previus = tmp->previus;
	tmp->next = stack->A->next;
	stack->A->next->previus = tmp;
	tmp->previus = stack->A;
	stack->A->next = tmp;
	tmp->is_top = FALSE;
	stack->A->is_top = TRUE;
	tmp = stack->B;
	stack->B = stack->B->next;
	tmp->previus->next = stack->B;
	stack->B->previus = tmp->previus;
	tmp->next = stack->B->next;
	stack->B->next->previus = tmp;
	tmp->previus = stack->B;
	stack->B->next = tmp;
	tmp->is_top = FALSE;
	stack->B->is_top = TRUE;
	ft_printf("ss\n");
}