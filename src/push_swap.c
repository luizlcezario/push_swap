/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:28:28 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/12 00:05:24 by llima-ce         ###   ########.fr       */
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


// int	verify_entry_in_b(t_nums num, t_push *stack, t_stack *B_next, int limiter)
// {
// 	int	a;

// 	a = -1;
// 	if (stack->count_element_B > 1)
// 	{
// 		while (++a < stack->count_element_B)
// 		{
// 			if (num.value < B_next->num && num.value > B_next->next->num)
// 			{
// 				if (num.value - B_next->previous->num <= limiter)
// 					return (a);
// 				else if (B_next->next->num - num.value <= limiter)
// 					return (a);
// 			}
// 			B_next = B_next->next;
// 		}
// 		if (limiter <= 10)
// 			return(verify_entry_in_b(num, stack, B_next, limiter + 1));
// 		else if (limiter <= 60)
// 			return(verify_entry_in_b(num, stack, B_next, limiter + 5));
// 		return (find_smaller(stack->B->next, num.value, num.value));
// 	}
// 	return (0);
// }

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
	if (stack->A == changes && a > 0)
	{
		if (changes->num <= stack->pivot)
		{
			push_b(stack, stack->A);
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
			push_a(stack, stack->B);
			a--;
		}
		else
			rotate_b(stack);
		partition_chunks(stack, stack->B, a);
	}
}



int push_swap(t_push *stack, int size, t_stack *now)
{
	int size_b;
	int a;

	if (verify_ordination(stack, stack->A) == FALSE)
	{
		a = -1;
		size_b = size / 2 ;
		if (size % 2 == 1)
			size_b += 1;
		stack->pivot = find_pivot(now, size);
		partition_chunks(stack, now, verify_chunks(stack, now, size));
		if (size_b <= 10)
		{
			// print_linked_list(stack->B);
			// print_linked_list(stack->A);
			finishing_swap(stack, stack->B, 0, size_b);
			while (++a < size_b)
				rotate_a(stack);
			while (++a < size_b + size / 2 + 1)
				push_b(stack, stack->A);
			finishing_swap(stack, stack->B, 0, size / 2);
			a = -1;
			while (++a < size / 2)
				rotate_a(stack);
		}
		else
		{
			push_swap(stack, stack->count_element_B , stack->B);
			push_swap(stack, size_b + size / 2, stack->A);
		}
	}
	return (0);
}
