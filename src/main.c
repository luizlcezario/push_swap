/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz <luiz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:07:16 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/07 16:44:44 by luiz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push stack;

	if (argc > 1)
	{
		if (init_stacks(&stack, argc, argv) != 0)
			return (error_message("Error: invalid input"));
		push_swap(&stack, stack.count_element_A, stack.A);
		// print_linked_list(stack.B);
		// print_linked_list(stack.A);
		// print_linked_list(stack.B);
		return (0);
	}
	else
		return (0);
}

//	b = ft_str("ra,rra|rra,ra|rb,rrb|rrb,rb|pb,pa|pa,pb|sa,pb,ra>ra,pb|");
//	b = ft_strcatxl(b, "sb,pa,rb>rb,pa|rrr,rb>ra|rrr,ra>rb|");
//	b = ft_strcatxl(b, "ra,sa,rb>rr,sa|rb,sb,ra>rr,sb|ra,rr*,rb|rb,rr*,ra|");
//	b = ft_strcatxl(b, "rra,rrr*,rrb|rrb,rrr*,rra|ra,pb,rra,pa>sa|");
//	b = ft_strcatxl(b, "rb,pa,rrb,pb>sb|sa,sb>ss|sb,sa>ss|");
//	b = ft_strcatxl(b, "sa,pb,sa,pb>ra,pb,pb,rra|sb,pa,sb,pa>rb,pa,pa,rrb|");
//	b = ft_strcatxl(b, "pb,ra,pa>sa,ra|pa,rb,pb>sb,rb|sa,ra,pb>pb,ra|");
//	b = ft_strcatxl(b, "sb,rb,pa>pa,rb");
