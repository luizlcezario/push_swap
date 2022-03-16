/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:11:12 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/16 16:23:13 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../libft/libft.h"

typedef struct s_nums
{
	int		value;
	int		position;
}	t_nums;

typedef struct s_stack{
	int				num;
	t_bool			is_top;
	struct s_stack	*next;
	struct s_stack	*previous;
}		t_stack;

typedef struct s_push{
	int		err;
	int		*original;
	t_stack	*a;
	t_stack	*b;
	t_nums	minor_now;
	int		count_element_a;
	int		count_element_b;
}	t_push;

// init
t_stack	*new_stack_element(char **argv, int i, int istop);
int		add_in_end_element(t_push *stack, t_stack *new1, int i);
void	quick_sort(int arr[], int low, int high);
int		verify_duplicates(t_push *stack, int argc);
int		init_stacks(t_push *stack, int argc, char **argv);

// checker
t_bool	checker(t_push *stack);

// utils
t_bool	verify_ordination(t_push *stack, t_stack *tmp);
void	free_all(t_push *stack);
int		error(void);
// moves
void	push_b(t_push *stack, t_stack *tmp);
void	push_a(t_push *stack, t_stack *tmp);
void	rotate_a(t_push *stack);
void	rotate_b(t_push *stack);
void	rotate_ab(t_push *stack);
void	reverse_a(t_push *stack);
void	reverse_b(t_push *stack);
void	reverse_ab(t_push *stack);
void	swap_a(t_push *stack);
void	swap_b(t_push *stack);
void	swap_ab(t_push *stack);

#endif