/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:40:22 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/16 15:48:38 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_bool	is_number(char *str)
{
	while (*str != 0)
	{
		if (*str != '-')
		{
			if (*str < '0' || *str > '9')
				return (FALSE);
		}
		str++;
	}
	return (TRUE);
}

int	init_links(int argc, t_push *stack, char **argv)
{
	int		i;
	t_stack	*new1;

	i = 0;
	while (++i < argc)
	{
		if (is_number(argv[i]) == TRUE)
		{
			stack->original[i - 1] = ft_new_atoi(argv[i], &stack->err);
			if (stack->err == 1)
				return (1);
			new1 = new_stack_element(argv, i, i);
			if (new1 == NULL)
				return (1);
			else
			{
				if (add_in_end_element(stack, new1, i - 1) != 0)
					return (1);
			}
			stack->count_element_a++;
		}
		else
			return (1);
	}
	return (0);
}

int	init_stacks(t_push *stack, int argc, char **argv)
{
	stack->b = NULL;
	stack->err = 0;
	stack->count_element_a = 0;
	stack->count_element_b = 0;
	stack->original = (int *)malloc(sizeof(int) * argc);
	if (init_links(argc, stack, argv) != 0)
		return (1);
	if (verify_duplicates(stack, argc) != 0)
		return (1);
	return (0);
}
