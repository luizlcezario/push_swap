/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:40:22 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/14 20:48:51 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stacks(t_push *stack, int argc, char **argv)
{
	int		i;
	t_stack	*new;

	i = 0;
	stack->B = NULL;
	stack->err = 0;
	stack->original = (int *)malloc(sizeof(int) * argc);
	while (++i < argc)
	{
		stack->original[i - 1] = ft_new_atoi(argv[i], &stack->err);
		new = new_stack_element(argv, i, i - 1 == 0);
		if (new == NULL || stack->err == 1)
		{
			printf("teste1: %d\n", stack->err);
			return (1);
		}
		else
		{
			if (add_in_end_element(stack, new, i - 1) != 0)
			{
				printf("teste2: %d\n", stack->err );
				return (1);
			}
		}
	}
	if (verify_duplicates(stack, argc) != 0)
		return (1);
	return (0);
}