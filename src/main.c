/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:07:16 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/14 21:16:13 by llima-ce         ###   ########.fr       */
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
		push_swap(&stack);
		print_linked_list(stack.A);
		print_linked_list(stack.B);
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
