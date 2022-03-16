/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:52:56 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/16 17:41:13 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_a(t_push *stack)
{
	if (stack->a != NULL)
	{
		stack->a->is_top = FALSE;
		stack->a = stack->a->next;
		stack->a->is_top = TRUE;
	}
}

void	rotate_b(t_push *stack)
{
	if (stack->b != NULL)
	{
		stack->b->is_top = FALSE;
		stack->b = stack->b->next;
		stack->b->is_top = TRUE;
	}
}

void	rotate_ab(t_push *stack)
{
	rotate_a(stack);
	rotate_b(stack);
}
