/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finishing_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:34:08 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/11 23:44:45 by llima-ce         ###   ########.fr       */
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
		if (stack->minor_now.value < next->num && a < high - low + 1)
		{
			stack->minor_now.value = next->num;
			stack->minor_now.position = a;
		}
		if (stack->minor_now.value < tmp->num && a < low + 1)
		{
			stack->minor_now.value = tmp->num;
			stack->minor_now.position = a * -1;
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

int	finishing_swap(t_push *stack, t_stack *order, int low, int high)
{
	t_nums	moves_b;

	if (order == NULL || high == 0)
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
