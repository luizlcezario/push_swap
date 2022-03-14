/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:25:41 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/14 13:52:37 by llima-ce         ###   ########.fr       */
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

t_nums	find_smaller(t_stack *tmp, int low, int high)
{
	int		a;
	t_nums	to_find;

	a = -1;
	while(++a < low)
		tmp = tmp->next;
	to_find.position = 0;
	to_find.value = tmp->num;
	while (a < high)
	{
		if (to_find.value > tmp->num)
		{
			to_find.value = tmp->num;
			to_find.position = a;
		}
		tmp = tmp->next;
		a++;
	}
	return (to_find);
}

t_nums	find_greater(t_stack *tmp, int low, int high)
{
	int		a;
	t_nums	to_find;

	a = -1;
	while(++a < low)
		tmp = tmp->next;
	to_find.position = 0;
	to_find.value = tmp->num;
	while (a < high)
	{
		if (to_find.value < tmp->num)
		{
			to_find.value = tmp->num;
			to_find.position = a;
		}
		tmp = tmp->next;
		a++;
	}
	return (to_find);
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

int	verify_chunks(t_push *stack, t_stack *now, int size)
{
	if (stack->B == now)
	{
		if(size % 2 == 1)
			return(size / 2 + 1);
	}
	return(size / 2);
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
	quickSort(tmp, 0, size - 1);
	return (tmp[size / 2 - 1]);
}