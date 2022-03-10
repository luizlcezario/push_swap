/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz <luiz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:28:28 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/09 17:04:01 by luiz             ###   ########.fr       */
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


int	verify_entry_in_b(t_nums num, t_push *stack, t_stack *B_next, int limiter)
{
	int	a;

	a = -1;
	if (stack->count_element_B > 1)
	{
		while (++a < stack->count_element_B)
		{
			if (num.value < B_next->num && num.value > B_next->next->num)
			{
				if (num.value - B_next->previous->num <= limiter)
					return (a);
				else if (B_next->next->num - num.value <= limiter)
					return (a);
			}
			B_next = B_next->next;
		}
		if (limiter <= 10)
			return(verify_entry_in_b(num, stack, B_next, limiter + 1));
		else if (limiter <= 60)
			return(verify_entry_in_b(num, stack, B_next, limiter + 5));
		return (find_small(stack->B->next, num.value));
	}
	return (0);
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

void partition_chunks(t_push *stack, t_stack *changes, int a)
{
	if (stack->A->num == changes->num && a > 0)
	{
		if (changes->num <= stack->pivot)
		{
			push_b(stack, changes);
			a--;
		}
		else
			rotate_a(stack);
		partition_chunks(stack, stack->A, a);
	}
	else if (a > 0)
	{
		if (changes->num >= stack->pivot)
		{
			push_a(stack, changes);
			a--;
		}
		else
			rotate_b(stack);
		partition_chunks(stack, stack->B, a);
	}
}

// int		find_greater(t_stack *stack, int num)
// {
// 	int greater;
// 	int moves;

// 	greater = stack->num;
// 	moves = -1;
// 	while(++moves > num)
// 	{
// 		if(greater <= stack->num)
// 			greater = stack->num;
// 		stack = stack->next;
// 	}
// 	if (moves > num / 2)
// 		return (moves - num);
// 	return (moves);
// }
void	swaps(t_push *stack, t_bool is_swap_a, t_bool is_swap_b)
{
	if(is_swap_a && is_swap_b)
		swap_ab(stack);
	else if (is_swap_a)
		swap_a(stack);
	else if (is_swap_b)
		swap_b(stack);
	rotate_ab(stack);
}

void	swaps_reverse(t_push *stack, t_bool is_swap_a, t_bool is_swap_b)
{
	if(is_swap_a && is_swap_b)
		swap_ab(stack);
	else if (is_swap_a)
		swap_a(stack);
	else if (is_swap_b)
		swap_b(stack);

}

void	is_to_swap(t_push *stack, t_stack *a, t_stack* b, t_bool reverse)
{
	t_bool is_swap_a;
	t_bool is_swap_b;

	is_swap_a = FALSE;
	is_swap_b = FALSE;
	if (a->num >a->next->num)
		is_swap_a = TRUE;
	if (b->num > b->next->num)
		is_swap_b = TRUE;
	if (reverse)
		swaps_reverse(stack, is_swap_a, is_swap_b);
	else
		swaps(stack, is_swap_a, is_swap_b);
}

void	insertion(t_push *stack, int size_a, t_bool reverse, t_bool odd)
{
	int a;

	a = -1;
	while (++a < size_a)
	{
		if (reverse)
			reverse_ab(stack);
		is_to_swap(stack, stack->A, stack->B, reverse);
	}
	if (odd)
	{
		if (stack->B->num > stack->B->next->num)
			swap_b(stack);
		rotate_b(stack);
	}
	insertion(stack, a, !reverse, odd);
}

int push_swap(t_push *stack, int size, t_stack *now)
{
	int size_b;
	int a;

	a = -1;
	size_b = size / 2;
	if (size % 2 == 1)
		size_b += 1;
	stack->pivot = find_pivot(now, size);
	if (a < size)
		partition_chunks(stack, now, size / 2);
	if (stack->count_element_B > 15)
		push_swap(stack, stack->count_element_B, stack->B);
	finishing_swap(stack, stack->B, 0, size_b);
	while (--size_b >= 0)
		rotate_a(stack);
	finishing_swap(stack, stack->A, 0, size / 2);
	
	return (0);
}
