/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finishing_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:34:08 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/14 21:40:41 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nums	find_greater_finish(t_push *stack, t_stack *tmp, int low, int high)
{
	int		a;
	t_stack	*next;

	a = -1;
	next = tmp;
	while (++a < high)
	{
		if (stack->minor_now.value < tmp->num && a < low + 1)
		{
			stack->minor_now.value = tmp->num;
			stack->minor_now.position = a * -1;
		}
		if (stack->minor_now.value < next->num && a < high - low + 1)
		{
			stack->minor_now.value = next->num;
			stack->minor_now.position = a;
		}
		next = next->next;
		tmp = tmp->previous;
	}
	return (stack->minor_now);
}


t_nums	find_smaller_finish(t_push *stack, t_stack *tmp, int low, int high)
{
	int		a;
	t_stack	*next;

	a = -1;
	next = tmp;
	while (++a < high)
	{
		if (stack->minor_now.value > tmp->num && a < low + 1)
		{
			stack->minor_now.value = tmp->num;
			stack->minor_now.position = a * -1;
		}
		if (stack->minor_now.value > next->num && a < high - low + 1)
		{
			stack->minor_now.value = next->num;
			stack->minor_now.position = a;
		}
		next = next->next;
		tmp = tmp->previous;
	}
	return (stack->minor_now);
}

void	new_values(t_nums move, int *low, int *high)
{
	if (move.position > 0)
		*low += move.position;
	else if (move.position < 0)
		*low += move.position;
	*high -= 1;
}

int	finishing_swap(t_push *stack, int low, int high, t_bool first)
{
	t_nums	moves_g;
	t_nums	moves_s;

	if (stack->B == NULL || high == 0)
		return (0);
	if (first == FALSE)
		stack->moves_count -= 1;
	stack->minor_now.position = 0;
	stack->minor_now.value = stack->B->num;
	moves_s = find_smaller_finish(stack, stack->B, low, high);
	moves_g = find_greater_finish(stack, stack->B, low, high);
	if (abs_x(moves_g.position) < abs_x(moves_s.position))
	{
		if (first == FALSE && moves_g.position > 0)
		{
			rotate_ab(stack);
			moves_g.position -= 1;
		}
		else if (first == FALSE)
			rotate_a(stack);
		new_values(moves_g, &low, &high);
		move(moves_g.position, stack, &rotate_b, &reverse_b);
		push_a(stack, stack->B);
		return(finishing_swap(stack, low, high , TRUE));
	}
	else
	{
		if (first == FALSE && moves_s.position > 0)
		{
			rotate_ab(stack);
			moves_s.position -= 1;
		}
		else if (first == FALSE)
			rotate_a(stack);
		new_values(moves_s, &low, &high);
		move(moves_s.position, stack, &rotate_b, &reverse_b);
		push_a(stack, stack->B);
		return(finishing_swap(stack, low, high , FALSE));
	}
}
