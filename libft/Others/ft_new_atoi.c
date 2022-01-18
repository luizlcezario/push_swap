/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:33:10 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/14 14:36:53 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	atoi_while(const char *str, int sign, int *num)
{
	int i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9') 
	{

		if (*num > INT_MAX / 10
			|| (*num == INT_MAX / 10 
			&& str[i] - '0' > 7)) 
		{
			if (sign == 1)
			{

				return (i);
			}
			else
				return (INT_MIN);
		}
		*num = 10 * *num + (str[i++] - '0');
	}
	return (i);
}

int	ft_new_atoi(const char *str, int *err)
{
	int	sign;
	int	num;

	sign = 1;
	if(!str)
	{
		*err = 1;
		printf("teste4: %d\n", *err);
		return (0);
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	num = 0;
	if (ft_isdigit(*str))
		str += atoi_while(str, sign, &num);
	if (*str != 0)
	{
		*err = 1;
		return (0);
	}
	return (num * sign);
}