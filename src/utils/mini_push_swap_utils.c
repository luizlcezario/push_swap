/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_push_swap_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 00:01:11 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/12 00:01:27 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_direction(int moves, t_push *stack, int total, char type)
{
	if (type == 'A' || type == 'a')
	{
		if (moves > total / 2)
			move(moves - total, stack, &rotate_a, &reverse_a);
		else
			move(moves, stack, &rotate_a, &reverse_a);
	}
	if (type == 'B' || type == 'b')
	{
		if (moves > total / 2)
			move(moves - total, stack, &rotate_b, &reverse_b);
		else
			move(moves, stack, &rotate_b, &reverse_b);
	}
}
