/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:40:21 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/15 16:21:57 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bouncing(t_push *stack, int a, int b)
{
	if (a > 0)
	{
		if(stack->A->num > stack->A->next->num)
		{
			swap_a(stack);
			if (a > 1)
				rotate_a(stack);
		}
		else if (a > 0)
			rotate_a(stack);
		bouncing(stack, --a , b);
	}
	else if (b > 2)
	{
		reverse_a(stack);
		swap_a(stack);
		bouncing(stack, a , --b);
	}
}

static void	sort(t_push *stack, int low, int high)
{
	t_nums	smaller;
	
	if (high - low != 1)
	{
		smaller = find_smaller(stack->A, low, high);
		if(smaller.position == 0)
			rotate_a(stack);
		else
			bouncing(stack, smaller.position, smaller.position);
		sort(stack, low, --high);
	}
	
}

static void	normalize(t_push *stack, int low, int high)
{
	t_nums	greater;
	t_nums	smaller;

	greater = find_greater(stack->A, low, high);
	smaller = find_smaller(stack->A, low, high);
	if (greater.position == smaller.position - 1 && smaller.position == 0)
		return ;
	else if (greater.position != smaller.position - 1 && greater.position == 0)
	{
		swap_a(stack);
		normalize(stack, low, high);
	}
	else if (greater.position != 0)
	{
		choose_direction(greater.position, stack, stack->count_element_A, 'a');
		normalize(stack, low, high);
	}
	else
		rotate_a(stack);
}

void	mini_push_swap(t_push *stack, int size)
{
	if (verify_ordination(stack, stack->A) == FALSE)
	{
		if(size == stack->count_element_A)
			normalize(stack, 0, size);
		if (verify_ordination(stack, stack->A) == FALSE)
			sort(stack, 1, size - 1);
		else
			return ;
		mini_push_swap(stack, size);
	}
}