/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_algo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:26:26 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/15 23:26:10 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	verify_entry_in_a(t_nums num, t_push *stack, t_stack *B_next,
int limiter)
{
	int	a;

	a = -1;
	if (stack->count_element_a > 1)
	{
		while (++limiter <= 100000)
		{
			a = -1;
			while (++a < stack->count_element_a)
			{
				if (num.value > B_next->previous->num && num.value
					< B_next->num)
				{
					if (num.value - B_next->previous->num < limiter
						&& B_next->num - num.value < limiter)
						return (a);
				}
				B_next = B_next->next;
			}
		}
		return (find_greater(stack->a, 0, stack->count_element_a).position + 1);
	}
	return (0);
}

int	choose_side(int moves, int size)
{
	if (moves > size / 2)
		return (moves - size);
	else
		return (moves);
}

void	medium_push_swap(t_push *stack)
{
	t_nums	value;
	int		moves;

	if (!verify_ordination(stack, stack->a))
	{
		while (stack->count_element_a != 3)
			push_b(stack, stack->a);
		mini_push_swap(stack, stack->count_element_a);
		while (stack->count_element_b > 0)
		{
			value.position = 0;
			value.value = stack->b->num;
			moves = verify_entry_in_a(value, stack, stack->a, 0);
			moves = choose_side(moves, stack->count_element_a);
			move(moves, stack, &rotate_a, &reverse_a);
			push_a(stack, stack->b);
		}
		value = find_smaller(stack->a, 0, stack->count_element_a);
		moves = choose_side(value.position, stack->count_element_a);
		move(value.position, stack, &rotate_a, &reverse_a);
		medium_push_swap(stack);
	}
}
