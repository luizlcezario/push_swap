/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:11:12 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/14 20:28:24 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/libft.h"

typedef struct s_stack{
	int				num;
	t_bool			is_top;
	struct s_stack	*next;
	struct s_stack	*previus;
}		t_stack;

typedef struct s_push{
	int		err;
	int		*original;
	t_stack *A;
	t_stack *B;
}	t_push;

int		push_swap(t_push *stack);

int		init_stacks(t_push *stack, int argc, char **argv);
int		print_linked_list(t_stack *stack);
int		error_message(char *str);
t_stack	*new_stack_element(char **argv ,int i, t_bool istop);
int		add_in_end_element(t_push *stack, t_stack *new, int i);
void	quickSort(int arr[], int low, int high);
int		verify_duplicates(t_push *stack, int argc);

void	push_b(t_push *stack);
void	push_a(t_push *stack);
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