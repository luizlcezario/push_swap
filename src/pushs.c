/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:07:06 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/14 19:17:06 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_push *stack)
{
	t_stack *tmp;

	tmp = stack->B;
	stack->B->next->previus = stack->B->previus;
	stack->B->previus->next = stack->B->next;
	stack->B = tmp->next;
	stack->B->is_top = TRUE;
	if (stack->A == NULL)
	{
		stack->A = tmp;
		tmp->next = stack->A;
		tmp->previus = stack->A;
	}
	else
	{
		tmp->next = stack->A;
		tmp->previus = stack->A->previus;
		stack->A->previus->next = tmp;
		stack->A->previus = tmp;
		stack->A->is_top = FALSE;
		stack->A = tmp;
	}
	ft_printf("pa\n");
}

void	push_b(t_push *stack)
{
	t_stack *tmp;

	tmp = stack->A;
	stack->A->next->previus = stack->A->previus;
	stack->A->previus->next = stack->A->next;
	stack->A = tmp->next;
	stack->A->is_top = TRUE;
	if (stack->B == NULL)
	{
		stack->B = tmp;
		tmp->next = stack->B;
		tmp->previus = stack->B;
	}
	else
	{
		tmp->next = stack->B;
		tmp->previus = stack->B->previus;
		stack->B->previus->next = tmp;
		stack->B->previus = tmp;
		stack->B->is_top = FALSE;
		stack->B = tmp;
	}
	ft_printf("pb\n");
}

