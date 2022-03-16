/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_algo_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:34:08 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/16 15:36:47 by llima-ce         ###   ########.fr       */
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

void	finishing_swap(t_push *stack, int high, t_bool first)
{
	t_nums	moves_g;
	t_nums	moves_s;

	if (stack->b == NULL || high == 0)
		return ;
	if (first == FALSE)
		stack->moves_count -= 1;
	stack->minor_now.position = 0;
	stack->minor_now.value = stack->b->num;
	moves_s = find_smaller_finish(stack, stack->b, high / 2, high);
	moves_g = find_greater_finish(stack, stack->b, high / 2, high);
	if (abs_x(moves_g.position) < abs_x(moves_s.position))
		stack->minor_now = moves_g;
	else
		stack->minor_now = moves_s;
	finishing(first, stack);
	return (finishing_swap(stack, high--,
			abs_x(moves_g.position) < abs_x(moves_s.position)));
}
