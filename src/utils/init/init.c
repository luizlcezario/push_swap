/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:40:22 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/15 22:34:26 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_links(int argc, t_push *stack, char **argv)
{
	int		i;
	t_stack	*new;

	i = 0;
	while (++i < argc)
	{
		stack->original[i - 1] = ft_new_atoi(argv[i], &stack->err);
		if (stack->err == 1)
			return (1);
		new = new_stack_element(argv, i, i);
		if (new == NULL)
			return (1);
		else
		{
			if (add_in_end_element(stack, new, i - 1) != 0)
				return (1);
		}
	}
	return (0);
}

int	init_stacks(t_push *stack, int argc, char **argv)
{
	stack->b = NULL;
	stack->err = 0;
	stack->count_element_a = argc - 1;
	stack->count_element_b = 0;
	stack->original = (int *)malloc(sizeof(int) * argc);
	if (init_links(argc, stack, argv) != 0)
		return (1);
	if (verify_duplicates(stack, argc) != 0)
		return (1);
	return (0);
}
