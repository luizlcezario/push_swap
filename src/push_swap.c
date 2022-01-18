/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:28:28 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/14 21:14:45 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_linked_list(t_stack *stack)
{
	int i;

	i = 0;
	ft_printf("%d: %d\n", i, stack->num);
	stack = stack->next;
	while (stack->is_top == FALSE)
	{
		i++;
		ft_printf("%d: %d\n",i , stack->num);
		stack = stack->next;
	}
	stack = stack->next;
	return(i);
}

void	verify_b(t_push *stack, int a)
{
	if (stack->B != NULL && stack->B->num < stack->B->next->num)
	{
		rotate_ab(stack);
		a--;
	}
	else
	{
		rotate_a(stack);
		a--;
	}
	if(a > 0)
		verify_b(stack, a);
}

int	push_swap(t_push *stack)
{
	t_stack	*tmp;
	int	a;

	tmp = stack->A;
	a = 0;
	while (tmp->num < tmp->next->num)
	{
		tmp = tmp->next;
		if(tmp->next->is_top == TRUE)
			return (0);
		a++;
	}
	verify_b(stack, a);
	if (stack->A->num - stack->A->next->num == 1)
		swap_a(stack);
	else
		push_b(stack);
	return(push_swap(stack));
}
