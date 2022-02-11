/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finishing_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:34:08 by llima-ce          #+#    #+#             */
/*   Updated: 2022/02/11 19:03:00 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_stack	*start_nums(t_analizy *nums, t_stack *B)
// {
// 	nums->small_next.position = 0;
// 	nums->small_next.value = B->num;
// 	nums->small_previous.position = 0;
// 	nums->small_previous.value = B->num;
// 	return (B->next);
// }

// void	finishing_swap(t_push *stack)
// {
// 	t_analizy	nums;
// 	t_stack		*tmp;
// 	int			a;

// 	tmp = start_nums(&nums, stack->B);
// 	a = 0;
// 	while (tmp->is_top == FALSE)
// 	{
// 		if (a < stack->count_element_B / 2 && tmp->num < nums.small_next.value)
// 		{
// 			nums.small_next.value = tmp->num;
// 			nums.small_next.position = a;
// 		}
// 		if (a >= stack->count_element_B / 2 && tmp->num <
// 			nums.small_previous.value)
// 		{
// 			nums.small_previous.value = tmp->num;
// 			nums.small_next.position = (stack->count_element_B - a) * -1;
// 		}
// 	}
// }

t_nums	verify_greater_in_b(t_stack *next, t_stack *previous, t_push *stack, int a)
{
	while (++a <= 10 && a <= stack->count_element_B / 2)
	{
		if (stack->minor_start.value < next->num)
		{
			stack->minor_start.value = next->num;
			stack->minor_start.position = a;
		}
		if (stack->minor_end.value < previous->num)
		{
			stack->minor_end.value = previous->num;
			stack->minor_end.position = a;
		}
		next = next->next;
		previous = previous->previous;
	}
	if (stack->minor_end.value > stack->minor_start.value)
	{
		stack->minor_end.position *= -1;
		return (stack->minor_end);
	}
	else
		return (stack->minor_start);
}

t_bool	verify_moves_to_push_a(int moves_a, int moves_b)
{
	if (moves_b == 0 || moves_a == 0)
		return (FALSE);
	else if (moves_b > 0 && moves_a > 0)
		return (TRUE);
	else
		return (FALSE);
}

int	verify_entry_in_a(t_nums num, t_push *stack, t_stack *next, int limiter)
{
	int	a;

	a = -1;
	if (stack->count_element_A > 1)
	{
		while (++a < stack->count_element_A)
		{
			if ((num.value < next->num && num.value > next->next->num))
			{
				if (num.value - next->num <= limiter)
					return (a);
				else if (next->next->num - num.value <= limiter)
					return (a);
			}
			else if (((num.value > next->num && num.value < next->next->num )))
			{
				if (num.value - next->num <= limiter)
					return (a + 1);
				else if (next->next->num - num.value <= limiter)
					return (a + 1);
			}
			next = next->next;
		}
		if (limiter <= 10)
			return(verify_entry_in_a(num, stack, next, limiter + 1));
		else if (limiter <= 60)
			return(verify_entry_in_a(num, stack, next, limiter + 5));
		return (find_greater(stack->A->next, num.value));
	}
	return (0);
}

void	move_together_a(t_push *stack, int moves_b, int moves_a, t_bool together)
{
	if (together == TRUE && (moves_a != 0 && moves_b != 0))
	{
		moves_a--;
		if (moves_b > 0)
		{
			rotate_ab(stack);
			moves_b--;
		}
		else
		{
			reverse_ab(stack);
			moves_b++;
		}
		move_together_a(stack, moves_b, moves_a, together);
	}
	else
	{
		move(moves_b, stack, &rotate_b, &reverse_b);
		move(moves_a, stack, &rotate_a, &reverse_a);
	}
}

int	verify_number_of_moves(int stack_max, int moves)
{
	if (stack_max == 0)
		return (0);
	else if (moves == stack_max)
		return (1);
	else if (moves > stack_max / 2)
		return ((stack_max - moves )* -1);
	else
		return (moves);
}


int	finishing_swap(t_push *stack)
{
	t_stack	*tmp;
	int		moves_a;
	t_nums	moves_b;
	t_bool	together_moves;

	if (stack->B == NULL)
		return (0);
	// print_linked_list(stack->A);
	tmp = stack->B;
	init_nums(stack, stack->B);
	if (stack->count_element_B > 0)
	{
		moves_b = verify_greater_in_b(tmp->next, tmp->previous, stack, 0);
		moves_a = verify_entry_in_a(moves_b, stack, stack->A, 1);
		moves_a = verify_number_of_moves(stack->count_element_A, moves_a);
		together_moves = verify_moves_to_push_a(moves_a, moves_b.position);
		move_together_a(stack, moves_b.position, moves_a, together_moves);
		push_a(stack, stack->B);
		move(moves_a * -1, stack, &rotate_a, &reverse_a);
	}
	return(finishing_swap(stack));
}
