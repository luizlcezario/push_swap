/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:28:28 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/14 18:31:04 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_bool	verify_moves_to_push(int moves_a, int moves_b, t_push *stack)
{
	if (moves_a == 0)
		return (0);
	else if (moves_a > 0)
	{
		if (moves_b - moves_a < stack->count_element_B - moves_b)
			return (TRUE);
		else 
			return (FALSE);
	}
	else
	{
		if (stack->count_element_B - moves_b < moves_a + moves_b)
			return (TRUE);
		else 
			return (FALSE);
	}
}

void	move_together(t_push *stack,int moves_a, int moves_b, t_bool together)
{
	if (together == TRUE && (moves_b != 0 && moves_a != 0))
	{
		moves_b--;
		if (moves_a > 0)
		{
			rotate_ab(stack);
			moves_a--;
		}
		else
		{
			reverse_ab(stack);
			moves_a++;
		}
		move_together(stack, moves_a, moves_b, together);
	}
	else
	{
	move(moves_a, stack, &rotate_a, &reverse_a);
	if (moves_b < stack->count_element_B / 2)
		move(moves_b, stack, &rotate_b, &reverse_b);
	else
		move(moves_b * -1, stack, &rotate_b, &reverse_b);
	}
}

int partition_chunks(t_push *stack, t_stack *changes, int a, int moves)
{
	if (stack->A == changes && a > 0)
	{
		if (changes->num <= stack->pivot)
		{
			push_b(stack, stack->A);
			a--;
		}
		else
		{

			rotate_a(stack);
			moves++;
		}
		moves = partition_chunks(stack, stack->A, a, moves);
	}
	else if (a > 0)
	{
		if (changes->num > stack->pivot)
		{
			push_a(stack, stack->B);
			a--;
		}
		else
		{
			moves++;
			rotate_b(stack);
		}
		moves = partition_chunks(stack, stack->B, a, moves);
	}
	return (moves);
}

int push_swap(t_push *stack, int size, t_stack *now, t_bool rr)
{
	int size_b;
	int a;

	if (verify_ordination(stack, stack->A) == FALSE)
	{
		stack->pivot = find_pivot(now, size);
		a = partition_chunks(stack, now, verify_chunks(stack, now, size), 0);
		size_b = stack->count_element_B;
		if (rr  == TRUE)
			move(a * - 1, stack, &rotate_a, &reverse_a);
		if (size_b <= 25)
		{
			finishing_swap(stack, stack->B, 0, stack->count_element_B);
			a = -1;
			while (++a < size_b)
				rotate_a(stack);
			a = -1;
			while (++a < size - size_b)
				push_b(stack, stack->A);
			a = -1;
			finishing_swap(stack, stack->B, 0, stack->count_element_B);
			while (++a < size - size_b)
				rotate_a(stack);
		}
		else
		{
			push_swap(stack, stack->count_element_B , stack->B, FALSE);
			push_swap(stack, size - size / 2, stack->A, TRUE);
		}
	}
	return (0);
}
