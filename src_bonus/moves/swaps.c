/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:42:47 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/28 17:58:58 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void swap_a(t_push *stack)
{
	t_stack *tmp;

	if (stack->a == NULL)
		return;
	tmp = stack->a->next->next;
	tmp->previous = stack->a;
	stack->a->previous->next = stack->a->next;
	stack->a->next->previous = stack->a->previous;
	tmp = stack->a->next;
	stack->a->next = tmp->next;
	tmp->next = stack->a;
	stack->a->previous = tmp;
	stack->a = tmp;
}

void swap_b(t_push *stack)
{
	t_stack *tmp;

	if (stack->b == NULL)
		return;
	tmp = stack->b->next->next;
	tmp->previous = stack->b;
	stack->b->previous->next = stack->b->next;
	stack->b->next->previous = stack->b->previous;
	tmp = stack->b->next;
	stack->b->next = tmp->next;
	tmp->next = stack->b;
	stack->b->previous = tmp;
	stack->b = tmp;
}

void swap_ab(t_push *stack)
{
	swap_a(stack);
	swap_b(stack);
}
