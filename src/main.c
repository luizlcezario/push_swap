/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:07:16 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/15 15:57:20 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push stack;

	if (argc > 2)
	{
		if (init_stacks(&stack, argc, argv) != 0)
			return (error_message("Error: invalid input"));
		if (verify_ordination(&stack, stack.A) == FALSE)
		{
			if (stack.count_element_A <= 10)
				mini_push_swap(&stack, stack.count_element_A);
			else
				push_swap(&stack, stack.count_element_A, stack.A, FALSE);
		}
		free_all(&stack);
		return (0);
	}
	else
		return (0);
}

