/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:07:16 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/15 21:43:26 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push	stack;

	if (argc > 2)
	{
		if (init_stacks(&stack, argc, argv) != 0)
			return (error_message("Error: invalid input"));
		if (verify_ordination(&stack, stack.a) == FALSE)
		{
			if (stack.count_element_a <= 10)
				medium_push_swap(&stack);
			else
				push_swap(&stack, stack.count_element_a, stack.a, FALSE);
		}
		free_all(&stack);
		return (0);
	}
	else
		return (0);
}
