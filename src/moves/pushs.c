/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:07:06 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/15 21:23:28 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	empty_stack(t_push *stack, t_stack *tmp)
{
	if (tmp == stack->a)
	{
		stack->a = NULL;
		stack->b->previous->next = tmp;
		tmp->previous = stack->b->previous;
		stack->b->previous = tmp;
		tmp->next = stack->b;
		stack->b->is_top = FALSE;
		stack->b = tmp;
	}
	else
	{
		stack->b = NULL;
		stack->a->previous->next = tmp;
		tmp->previous = stack->a->previous;
		stack->a->previous = tmp;
		tmp->next = stack->a;
		stack->a->is_top = FALSE;
		stack->a = tmp;
	}
}

void	push_a(t_push *stack, t_stack *tmp)
{
	stack->count_element_a += 1;
	stack->count_element_b -= 1;
	ft_printf("pa\n");
	if (stack->b == stack->b->next)
		return (empty_stack(stack, tmp));
	stack->b->next->previous = stack->b->previous;
	stack->b->previous->next = stack->b->next;
	stack->b = stack->b->next;
	stack->b->is_top = TRUE;
	if (stack->a == NULL)
	{
		stack->a = tmp;
		tmp->next = stack->a;
		tmp->previous = stack->a;
		tmp->is_top = TRUE;
	}
	else
	{
		stack->a->previous->next = tmp;
		tmp->previous = stack->a->previous;
		stack->a->previous = tmp;
		tmp->next = stack->a;
		stack->a->is_top = FALSE;
		stack->a = tmp;
	}
}

void	push_b(t_push *stack, t_stack *tmp)
{
	stack->count_element_a -= 1;
	stack->count_element_b += 1;
	ft_printf("pb\n");
	if (stack->a == stack->a->next)
		return (empty_stack(stack, tmp));
	stack->a->next->previous = stack->a->previous;
	stack->a->previous->next = stack->a->next;
	stack->a = stack->a->next;
	stack->a->is_top = TRUE;
	if (stack->b == NULL)
	{
		stack->b = tmp;
		tmp->next = stack->b;
		tmp->previous = stack->b;
		tmp->is_top = TRUE;
	}
	else
	{
		stack->b->previous->next = tmp;
		tmp->previous = stack->b->previous;
		stack->b->previous = tmp;
		tmp->next = stack->b;
		stack->b->is_top = FALSE;
		stack->b = tmp;
	}
}
