/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz <luiz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:25:41 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/07 16:35:28 by luiz             ###   ########.fr       */
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

int	find_pivot(t_stack *stack, int size)
{
	int	*tmp;
	int	a;

	tmp = malloc(size * sizeof(int));
	a = -1;
	while (++a < size)
	{
		tmp[a] = stack->num;
		stack = stack->next;
	}
	quickSort(tmp, 0, size);
	return (tmp[size / 2]);
}