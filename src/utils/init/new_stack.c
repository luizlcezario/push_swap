/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:11:18 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/15 21:23:23 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack_element(char **argv, int i, int istop)
{
	t_stack	*new;
	int		err;

	err = 0;
	new = (t_stack *)malloc(1 * sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->num = ft_new_atoi(argv[i], &err);
	if (err == 1)
		return (NULL);
	if (istop == 1)
		new->is_top = TRUE;
	else
		new->is_top = FALSE;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

int	add_in_end_element(t_push *stack, t_stack *new, int i)
{
	t_stack	*tmp;

	if (new == NULL)
		return (1);
	else if (i == 0)
		stack->a = new;
	else if (i == 1)
	{
		new->next = stack->a;
		new->previous = stack->a;
		stack->a->previous = new;
		stack->a->next = new;
	}
	else
	{
		tmp = stack->a->previous;
		tmp->next = new;
		new->previous = tmp;
		new->next = stack->a;
		stack->a->previous = new;
	}
	return (0);
}