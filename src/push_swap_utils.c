/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:25:41 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/27 17:44:16 by llima-ce         ###   ########.fr       */
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

void	init_nums(t_push *stack)
{
	stack->minor_end.position = 0;
	stack->minor_start.position = 0;
	stack->minor_start.value = stack->A->num;
	stack->minor_end.value = stack->A->num;
}

int	find_small_b(t_push *stack, t_stack *tmp)
{
	t_nums	num;
	int		a;

	num.value = stack->B->num;
	a = 0;
	num.position = a;
	while (tmp->is_top == FALSE)
	{
		if (num.value > tmp->num)
		{
			num.value = tmp->num;
			num.position = a;
		}
		tmp = tmp->next;
		a++;
	}
	return (num.position + 1);
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