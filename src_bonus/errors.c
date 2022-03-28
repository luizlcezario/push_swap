/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:26:46 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/25 16:54:17 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int error(void)
{
	char *str;

	str = get_next_line(STDIN_FILENO);
	if (ft_strncmp(str, "Error", 5) == 0)
	{
		free(str);
		if (get_next_line(STDIN_FILENO) != NULL)
			ft_printf(
				"YOUR PROGRAM SHOW SOMENTHING ELSE AFTER THE ERROR MESSAGE\n");
		else
		{
			ft_printf("ERROR\n");
			return (0);
		}
	}
	else
		ft_printf("YOUR PROGRAM DOSEN'T SHOW THE ERROR MESSAGE!\n");
	return (1);
}

void free_all(t_push *stack)
{
	t_stack *tmp;

	while (--stack->count_element_b >= 0)
	{
		tmp = stack->b->next;
		free(stack->b);
		stack->b = tmp;
	}
	while (--stack->count_element_a >= 0)
	{
		tmp = stack->a->next;
		free(stack->a);
		stack->a = tmp;
	}
	free(stack->original);
}
