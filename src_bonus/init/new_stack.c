/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:11:18 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/16 15:48:53 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*new_stack_element(char **argv, int i, int istop)
{
	t_stack	*new1;
	int		err;

	err = 0;
	new1 = (t_stack *)malloc(1 * sizeof(t_stack));
	if (new1 == NULL)
		return (NULL);
	new1->num = ft_new_atoi(argv[i], &err);
	if (err == 1)
		return (NULL);
	if (istop == 1)
		new1->is_top = TRUE;
	else
		new1->is_top = FALSE;
	new1->next = NULL;
	new1->previous = NULL;
	return (new1);
}

int	add_in_end_element(t_push *stack, t_stack *new1, int i)
{
	t_stack	*tmp;

	if (new1 == NULL)
		return (1);
	else if (i == 0)
		stack->a = new1;
	else if (i == 1)
	{
		new1->next = stack->a;
		new1->previous = stack->a;
		stack->a->previous = new1;
		stack->a->next = new1;
	}
	else
	{
		tmp = stack->a->previous;
		tmp->next = new1;
		new1->previous = tmp;
		new1->next = stack->a;
		stack->a->previous = new1;
	}
	return (0);
}
