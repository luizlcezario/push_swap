/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_duplicates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:13:07 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/16 15:48:49 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	binary_search(int *arr, int l, int r, int x)
{
	int	mid;

	if (r >= l)
	{
		mid = l + (r - l) / 2;
		if (arr[mid] == x)
			return (mid);
		if (arr[mid] > x)
			return (binary_search(arr, l, mid - 1, x));
		return (binary_search(arr, mid + 1, r, x));
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
		if (binary_search(stack->original, i + 1, argc - 1,
				stack->original[i]) != -1)
		{
			stack->err = 1;
			return (1);
		}
	}
	return (0);
}
