/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:11:18 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/14 18:42:53 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack_element(char **argv, int i, t_bool istop)
{
	t_stack	*new;
	int err;

	err = 0;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->num = ft_new_atoi(argv[i], &err);
	if (err == 1)
		return (NULL);
	if(istop == TRUE)
		new->is_top = TRUE;
	else
		new->is_top = FALSE;
	new->next = NULL;
	new->previus = NULL;
	return (new);
}

int	add_in_end_element(t_push *stack, t_stack *new, int i)
{
	t_stack	*tmp;

	if (new == NULL)
		return (1);
	else if (i == 0)
		stack->A = new;
	else if (i == 1)
	{
		new->next = stack->A;
		new->previus = stack->A;
		stack->A->previus = new;
		stack->A->next = new;
	}
	else
	{
		tmp = stack->A->previus;
		tmp->next = new;
		new->previus = tmp;
		new->next = stack->A;
		stack->A->previus = new;
	}
	return(0);
}