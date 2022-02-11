/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:25:41 by llima-ce          #+#    #+#             */
/*   Updated: 2022/02/11 16:26:26 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_linked_list(t_stack *stack)
{
	
	int i;

	i = 0;
	if	(stack != NULL)
	{	
		ft_printf("%d: %d\n", i, stack->num);
		stack = stack->next;
		while (stack->is_top == FALSE)
		{
			i++;
			ft_printf("%d: %d\n",i , stack->num);
			stack = stack->next;
		}
		stack = stack->next;
	}
	return(i);
}

void	init_nums(t_push *stack, t_stack *moving)
{
	stack->minor_end.position = 0;
	stack->minor_start.position = 0;
	stack->minor_start.value = moving->num;
	stack->minor_end.value = moving->num;
}

int	find_small(t_stack *tmp, int value)
{
	int		a;
	int		position;

	a = 0;
	position = 0;
	while (tmp->is_top == FALSE)
	{
		if (value > tmp->num)
		{
			value = tmp->num;
			position = a;
		}
		tmp = tmp->next;
		a++;
	}
	return (position);
}

int	find_greater(t_stack *tmp, int value)
{
	int		a;
	int		position;

	a = 0;
	position = 0;
	while (tmp->is_top == FALSE)
	{
		if (value > tmp->num)
		{
			value = tmp->num;
			position = a;
		}
		tmp = tmp->next;
		a++;
	}
	return (position);
}


void	move(int moves, t_push *stack, void (*r)(t_push *),void (*rr)(t_push *))
{
		while(moves != 0)
		{
			if (moves < 0)
			{
				rr(stack);
				moves++;
			}
			else
			{
				r(stack);
				moves--;
			}
		}
}