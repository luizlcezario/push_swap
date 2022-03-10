/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finishing_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz <luiz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:34:08 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/10 14:24:04 by luiz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



t_nums	find_greater_finish(t_push *stack, t_stack *tmp, int low, int high)
{
	int		a;
	t_stack	*next;

	a = -1;
	next = tmp;
	while (++a < high || a < low)
	{
		if (stack->minor_now.value < next->num && a < high)
		{
			stack->minor_now.value = next->num;
			stack->minor_now.position = a;
		}
		if (stack->minor_now.value < tmp->num && a < low)
		{
			stack->minor_now.value = tmp->num;
			stack->minor_now.position = a * -1;
		}
		next = next->next;
		tmp = tmp->previous;
	}
	return (stack->minor_now);
}

// t_bool	verify_moves_to_push_a(int moves_a, int moves_b)
// {
// 	if (moves_b == 0 || moves_a == 0)
// 		return (FALSE);
// 	else if (moves_b > 0 && moves_a > 0)
// 		return (TRUE);
// 	else
// 		return (FALSE);
// }

// int	verify_entry_in_a(t_nums num, t_push *stack, t_stack *next, int limiter)
// {
// 	int	a;

// 	a = -1;
// 	if (stack->count_element_A > 1)
// 	{
// 		while (++a < stack->count_element_A)
// 		{
// 			if ((num.value < next->num && num.value > next->next->num))
// 			{
// 				if (num.value - next->num <= limiter)
// 					return (a);
// 				else if (next->next->num - num.value <= limiter)
// 					return (a);
// 			}
// 			else if (((num.value > next->num && num.value < next->next->num )))
// 			{
// 				if (num.value - next->num <= limiter)
// 					return (a + 1);
// 				else if (next->next->num - num.value <= limiter)
// 					return (a + 1);
// 			}
// 			next = next->next;
// 		}
// 		if (limiter <= 10)
// 			return(verify_entry_in_a(num, stack, next, limiter + 1));
// 		else if (limiter <= 60)
// 			return(verify_entry_in_a(num, stack, next, limiter + 5));
// 		return (find_greater(stack->A->next, num.value));
// 	}
// 	return (0);
// }

// void	move_together_a(t_push *stack, int moves_b, int moves_a, t_bool together)
// {
// 	if (together == TRUE && (moves_a != 0 && moves_b != 0))
// 	{
// 		moves_a--;
// 		if (moves_b > 0)
// 		{
// 			rotate_ab(stack);
// 			moves_b--;
// 		}
// 		else
// 		{
// 			reverse_ab(stack);
// 			moves_b++;
// 		}
// 		move_together_a(stack, moves_b, moves_a, together);
// 	}
// 	else
// 	{
// 		move(moves_b, stack, &rotate_b, &reverse_b);
// 		move(moves_a, stack, &rotate_a, &reverse_a);
// 	}
// }

// int	verify_number_of_moves(int stack_max, int moves)
// {
// 	if (stack_max == 0)
// 		return (0);
// 	else if (moves == stack_max)
// 		return (1);
// 	else if (moves > stack_max / 2)
// 		return ((stack_max - moves )* -1);
// 	else
// 		return (moves);
// }

void	new_values(t_nums move, int *low, int *high)
{
	if (move.position != 0)
	{
		*low += move.position - 1;
		*high -= move.position;
	}
	else if (*low == 0 && *high == 1)
		*high -=1;
	else if (*high == 1)
		*low -= 1;
	else
		*high -=1;
}




int	finishing_swap(t_push *stack, t_stack *order, int low, int high)
{
	t_nums	moves_b;
	
	if (order == NULL || (low == 0 && high == 0))
		return (0);
	stack->minor_now.position = 0;
	stack->minor_now.value = order->num;
	moves_b = find_greater_finish(stack, order, low, high);
	new_values(moves_b, &low, &high);
	if(order == stack->B)
	{
		move(moves_b.position, stack, &rotate_b, &reverse_b);
		push_a(stack, stack->B);
		return(finishing_swap(stack, stack->B, low, high));
	}
	else
	{
		move(moves_b.position, stack, &rotate_a, &reverse_a);
		push_b(stack, stack->A);
		return(finishing_swap(stack, stack->A, low, high));
	}
}
