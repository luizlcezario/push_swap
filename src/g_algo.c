/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:28:28 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/15 22:17:19 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	partition_chunks_a(t_push *stack, t_stack *changes, int a,
int moves)
{
	if (a > 0)
	{
		if (changes->num <= stack->pivot)
		{
			push_b(stack, stack->a);
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
		while (++a < size - size_b)
			push_b(stack, stack->a);
		push_swap(stack, stack->count_element_b, stack->b, FALSE);
	}
}

void	push_swap(t_push *stack, int size, t_stack *now, t_bool rr)
{
	int	size_b;

	if (verify_ordination(stack, stack->a) == FALSE)
	{
		stack->moves_count = stack->count_element_b;
		size_b = stack->count_element_b;
		if (size <= 25)
			insertion(stack, size, size_b);
		else
			quick_swap(stack, size, now, rr);
	}
}
