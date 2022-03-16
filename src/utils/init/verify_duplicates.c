/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_duplicates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:13:07 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/15 21:16:59 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	interpolation_search(int *arr, int lo, int hi, int x)
{
	int	pos;

	if (lo <= hi && x >= arr[lo] && x <= arr[hi])
	{
		pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
		if (arr[pos] == x)
			return (pos);
		if (arr[pos] < x)
			return (interpolation_search(arr, pos + 1, hi, x));
		if (arr[pos] > x)
			return (interpolation_search(arr, lo, pos - 1, x));
	}
	return (-1);
}

int	verify_duplicates(t_push *stack, int argc)
{
	int		i;

	i = -1;
	quick_sort(stack->original, 0, argc - 2);
	while (++i < argc - 1)
	{
		if (interpolation_search(stack->original, i + 1, argc - 2,
				stack->original[i]) != -1)
		{
			stack->err = 1;
			ft_printf("%d %d\n", i, stack->original[i]);
			return (1);
		}
	}
	return (0);
}
