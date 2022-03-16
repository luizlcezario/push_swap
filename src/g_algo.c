/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_algo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:28:28 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/16 15:37:06 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	partition_chunks_a(t_push *stack, t_stack *changes, int a,
int moves)
{
	if (a > 0)
	{
		stack->pivot_2 = find_pivot(stack->b, stack->count_element_b);
		if (changes->num <= stack->pivot)
		{
			push_b(stack, stack->a);
			if (stack->b->num <= stack->pivot_2)
				rotate_b(stack);
			a--;
		}
		else
		{
			rotate_a(stack);
			moves++;
		}
		moves = partition_chunks(stack, stack->a, a, moves);
	}
	return (moves);
}

static int	partition_chunks_b(t_push *stack, t_stack *changes, int a,
int moves)
{
	if (a > 0)
	{
		if (changes->num > stack->pivot)
		{
			push_a(stack, stack->b);
			a--;
		}
		else
		{
			moves++;
			rotate_b(stack);
		}
		moves = partition_chunks(stack, stack->b, a, moves);
	}
	return (moves);
}

int	partition_chunks(t_push *stack, t_stack *changes, int a, int moves)
{
	if (changes == stack->a)
		return (partition_chunks_a(stack, changes, a, moves));
	else
		return (partition_chunks_b(stack, changes, a, moves));
}

void	quick_swap(t_push *stack, int size, t_stack *now, t_bool rr)
{
	int	a;
	int	size_b;

	stack->pivot = find_pivot(now, size);
	a = partition_chunks(stack, now, verify_chunks(stack, now, size), 0);
	if (rr == TRUE)
		move(a * -1, stack, &rotate_a, &reverse_a);
	size_b = stack->count_element_b;
	push_swap(stack, stack->count_element_b, stack->b, FALSE);
	if (size == stack->count_element_b + stack->count_element_a)
		push_swap(stack, size / 2, stack->a, TRUE);
	else
	{
		a = -1;
		stack->pivot_2 = find_pivot(stack->a, size - size_b);
		while (++a < size - size_b)
		{
			push_b(stack, stack->a);
			if (stack->b->num <= stack->pivot_2)
				rotate_b(stack);
		}
		push_swap(stack, stack->count_element_b, stack->b, FALSE);
	}
}

void	push_swap(t_push *stack, int size, t_stack *now, t_bool rr)
{
	if (verify_ordination(stack, stack->a) == FALSE)
	{
		if (size <= 25)
			insertion(stack);
		else
			quick_swap(stack, size, now, rr);
	}
}
