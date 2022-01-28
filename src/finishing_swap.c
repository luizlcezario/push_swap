/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finishing_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:34:08 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/27 17:40:45 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*start_nums(t_analizy *nums, t_stack *B)
{
	nums->small_next.position = 0;
	nums->small_next.value = B->num;
	nums->small_previous.position = 0;
	nums->small_previous.value = B->num;
	return (B->next);
}

void	finishing_swap(t_push *stack)
{
	t_analizy	nums;
	t_stack		*tmp;
	int			a;

	tmp = start_nums(&nums, stack->B);
	a = 0;
	while (tmp->is_top == FALSE)
	{
		if (a < stack->count_element_B / 2 && tmp->num < nums.small_next.value)
		{
			nums.small_next.value = tmp->num;
			nums.small_next.position = a;
		}
		if (a >= stack->count_element_B / 2 && tmp->num <
			nums.small_previous.value)
		{
			nums.small_previous.value = tmp->num;
			nums.small_next.position = (stack->count_element_B - a) * -1;
		}
	}
	
}