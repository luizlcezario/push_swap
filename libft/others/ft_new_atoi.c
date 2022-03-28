/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:33:10 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/28 20:12:23 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int atoi_while(const char *str, int sign, int *num)
{
	if (*str >= '0' && *str <= '9')
	{
		if (*num > INT_MAX / 10 || (*num == INT_MAX / 10 && *str - '0' > 7))
		{
			if (sign == -1 && *str - '0' == 8)
				return (0);
			else
				return (1);
		}
		*num = 10 * *num + (*str - '0');
	}
	return (0);
}

static int ft_sign(const char *str, int *err)
{
	int sign;

	sign = 1;
	if (!str)
	{
		*err = 1;
		return (0);
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	return (sign);
}

int ft_new_atoi(const char *str, int *err)
{
	int sign;
	int num;

	sign = ft_sign(str, err);
	if (*str == '+' || *str == '-')
		str++;
	if (*err == 1)
		return (0);
	num = 0;
	while (ft_isdigit(*str))
	{
		if (*err == 1)
			return (0);
		*err = atoi_while(str, sign, &num);
		str++;
	}
	if (*str != 0)
	{
		*err = 1;
		return (0);
	}
	return (num * sign);
}
