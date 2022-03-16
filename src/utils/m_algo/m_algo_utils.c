/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_algo_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 00:01:11 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/15 22:34:04 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	verify_mini_order(t_stack *stack, int size)
{
	while (--size > 0)
	{
		if (stack->num > stack->next->num)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}

static void	verify_case(t_push *stack, int low, int high)
{
	t_nums	greater;
	t_nums	smaller;

	greater = find_greater(stack->a, low, high);
	smaller = find_smaller(stack->a, low, high);
	if (greater.position == 0 && smaller.position == 2)
	{
		swap_a(stack);
		reverse_a(stack);
	}
	else if (smaller.position == 0 && greater.position == 1)
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if (smaller.position == 1 && greater.position == 2)
		swap_a(stack);
	else if (greater.position == 0 && smaller.position == 1)
		rotate_a(stack);
	else if (greater.position == 1 && smaller.position == 2)
		reverse_a(stack);
}

void	mini_push_swap(t_push *stack, int size)
{
	if (verify_mini_order(stack->a, size) == FALSE)
	{
		verify_case(stack, 0, size);
		mini_push_swap(stack, size);
	}
}
