/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_algo_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:17:59 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/16 01:23:17 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion(t_push *stack, int size, int size_b)
{
	int	a;

	finishing_swap(stack, 0, stack->count_element_b, TRUE);
	while (--stack->moves_count >= 0)
		rotate_a(stack);
	a = -1;
	while (++a < size - size_b)
		push_b(stack, stack->a);
	stack->moves_count = stack->count_element_b;
	finishing_swap(stack, 0, stack->count_element_b, TRUE);
	while (--stack->moves_count >= 0)
		rotate_a(stack);
}

void	finishing(t_bool first, t_push *stack, int *low, int *high)
{
	if (first == FALSE && stack->minor_now.position > 0)
	{
		rotate_ab(stack);
		stack->minor_now.position -= 1;
	}
	else if (first == FALSE)
		rotate_a(stack);
	new_values(stack->minor_now, low, high);
	move(stack->minor_now.position, stack, &rotate_b, &reverse_b);
	push_a(stack, stack->b);
}

int	abs_x(int x)
{
	if (x < 0)
		return (x * -1);
	else
		return (x);
}
