/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:07:16 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/16 17:15:10 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push	stack;

	if (argc > 1)
	{
		if (init_stacks(&stack, argc, argv) != 0)
		{
			free_all(&stack);
			exit (error_message("Error"));
		}
		if (verify_ordination(&stack, stack.a) == FALSE)
		{
			if (stack.count_element_a <= 10)
				medium_push_swap(&stack);
			else
				push_swap(&stack, stack.count_element_a, stack.a, FALSE);
		}
		free_all(&stack);
		exit (0);
	}
	else
		exit (0);
}
