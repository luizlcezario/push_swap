/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:07:06 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/27 17:40:45 by llima-ce         ###   ########.fr       */
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
	stack->count_element_A += 1;
	stack->count_element_B -= 1;
	ft_printf("pa\n");
	if (stack->A == stack->A->next)
		return (empty_stack(stack, tmp));
	stack->B->next->previous = stack->B->previous;
	stack->B->previous->next = stack->B->next;
	stack->B = tmp->next;
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
		tmp->next = stack->A;
		tmp->previous = stack->A->previous;
		stack->A->previous->next = tmp;
		stack->A->previous = tmp;
		stack->A->is_top = FALSE;
		stack->A = tmp;
	}
	stack->count_element_A += 1;
	stack->count_element_B -= 1;
}

void	push_b(t_push *stack, t_stack *tmp)
{
	stack->count_element_A -= 1;
	stack->count_element_B += 1;
	ft_printf("pb\n");
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
}

