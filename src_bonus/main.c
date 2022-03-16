/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:48:10 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/16 17:20:43 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_push	stack;

	if (argc < 2)
		return (0);
	else
	{
		if (init_stacks(&stack, argc, argv) != 0)
		{
			free_all(&stack);
			return (error());
		}
		if (checker(&stack))
		{
			printf("OK\n");
			free_all(&stack);
			return (0);
		}
		printf("KO\n");
		free_all(&stack);
		return (1);
	}
}
