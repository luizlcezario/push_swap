/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:42:47 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/26 15:49:52 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void swap_a(t_push *stack)
{
	t_stack *tmp;

	if (stack->a == NULL)
		return;
	stack->a->is_top = FALSE;
	stack->a->next->is_top = TRUE;
	stack->a->previous->next = stack->a->next;
	stack->a->next->previous = stack->a->previous;
	tmp = stack->a->next->next;
	stack->a->next->next = stack->a;
	stack->a->previous = stack->a->next;
	stack->a = stack->a->next;
	stack->a->next->next = tmp;
}

void swap_b(t_push *stack)
{
	t_stack *tmp;

	if (stack->b == NULL)
		return;
	stack->b->is_top = FALSE;
	stack->b->next->is_top = TRUE;
	stack->b->previous->next = stack->b->next;
	stack->b->next->previous = stack->b->previous;
	tmp = stack->b->next->next;
	stack->b->next->next = stack->b;
	stack->b->previous = stack->b->next;
	stack->b = stack->b->next;
	stack->b->next->next = tmp;
}

void swap_ab(t_push *stack)
{
	swap_a(stack);
	swap_b(stack);
}
