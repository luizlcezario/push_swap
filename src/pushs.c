/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz <luiz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:07:06 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/07 15:14:21 by luiz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	empty_stack(t_push *stack, t_stack *tmp)
{
	if (tmp == stack->A)
	{
		stack->A = NULL;
		stack->B->previous->next = tmp;
		tmp->previous = stack->B->previous;
		stack->B->previous = tmp;
		tmp->next = stack->B;
		stack->B->is_top = FALSE;
		stack->B = tmp;
	}
	else
	{
		stack->B = NULL;
		stack->A->previous->next = tmp;
		tmp->previous = stack->A->previous;
		stack->A->previous = tmp;
		tmp->next = stack->A;
		stack->A->is_top = FALSE;
		stack->A = tmp;
	}
}

void	push_a(t_push *stack, t_stack *tmp)
{
	if (stack->B == stack->B->next)
		return (empty_stack(stack, tmp));
	stack->B->next->previous = stack->B->previous;
	stack->B->previous->next = stack->B->next;
	stack->B = stack->B->next;
	stack->B->is_top = TRUE;
	if (stack->A == NULL)
	{
		stack->A = tmp;
		tmp->next = stack->A;
		tmp->previous = stack->A;
		tmp->is_top = TRUE;
	}
	else
	{
		stack->A->previous->next = tmp;
		tmp->previous = stack->A->previous;
		stack->A->previous = tmp;
		tmp->next = stack->A;
		stack->A->is_top = FALSE;
		stack->A = tmp;
	}
	stack->count_element_A += 1;
	stack->count_element_B -= 1;
	ft_printf("pa\n");
}

void	push_b(t_push *stack, t_stack *tmp)
{
	if (stack->A == stack->A->next)
		return (empty_stack(stack, tmp));
	stack->A->next->previous = stack->A->previous;
	stack->A->previous->next = stack->A->next;
	stack->A = stack->A->next;
	stack->A->is_top = TRUE;
	if (stack->B == NULL)
	{
		stack->B = tmp;
		tmp->next = stack->B;
		tmp->previous = stack->B;
		tmp->is_top = TRUE;
	}
	else
	{
		stack->B->previous->next = tmp;
		tmp->previous = stack->B->previous;
		stack->B->previous = tmp;
		tmp->next = stack->B;
		stack->B->is_top = FALSE;
		stack->B = tmp;
	}
	stack->count_element_A -= 1;
	stack->count_element_B += 1;
	ft_printf("pb\n");
}

