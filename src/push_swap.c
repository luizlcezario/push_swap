/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:28:28 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/27 18:10:41 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



t_nums	verify_minor_in_chunk(t_stack *next, t_stack *previous, t_push *stack,
int a)
{
	while (++a <= 10 && a <= stack->count_element_A / 2)
	{
		if (stack->minor_start.value > next->num)
		{
			stack->minor_start.value = next->num;
			stack->minor_start.position = a;
		}
		if(stack->minor_end.value > previous->num)
		{
			stack->minor_end.value = previous->num;
			stack->minor_end.position = a;
		}
		next = next->next;
		previous = previous->previous;
	}
	if (stack->minor_end.position < stack->minor_start.position ||
		(stack->minor_end.position == stack->minor_start.position &&
		stack->minor_end.value < stack->minor_start.value ))
	{
		stack->minor_end.position *= -1;
		return (stack->minor_end);
	}
	else
		return (stack->minor_start);
}

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
			if (num.value > B_next->previous->num && stack->B->num <
				B_next->next->num)
			{
				if (num.value - B_next->previous->num < limiter)
					return (a);
				else if (B_next->next->num - num.value < limiter)
					return (a);
			}
			B_next = B_next->next;
		}
		if (limiter <= 10)
			verify_entry_in_b(num, stack, B_next, limiter + 1);
		else if (limiter <= 60)
			verify_entry_in_b(num, stack, B_next, limiter + 5);
		return (find_small_b(stack, stack->B->next));
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

int	push_swap(t_push *stack)
{
	t_stack	*tmp;
	t_nums	moves_a;
	int		moves_b;
	t_bool	together_moves;

	if (stack->A == NULL)
		return (0);
	print_linked_list(stack->B);
	tmp = stack->A;
	init_nums(stack);
	if (stack->count_element_A > 0)
	{
		moves_a = verify_minor_in_chunk(tmp->next, tmp->previous, stack, 0);
		moves_b = verify_entry_in_b(moves_a,stack, stack->B, 1);
		together_moves = verify_moves_to_push(moves_a.position, moves_b, stack);
		move_together(stack, moves_a.position, moves_b, together_moves);
		push_b(stack, stack->A);
	}
	return(push_swap(stack));
}
