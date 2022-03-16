/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:11:12 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/15 22:44:46 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/libft.h"

typedef struct s_nums
{
	int		value;
	int		position;
}	t_nums;

typedef struct s_analizy
{
	t_nums	small_next;
	t_nums	small_previous;
}		t_analizy;

typedef struct s_stack{
	int				num;
	t_bool			is_top;
	struct s_stack	*next;
	struct s_stack	*previous;
}		t_stack;

typedef struct s_chunk{
	t_stack	*initial;
	int		max;
	int		size;
}		t_chunck;

typedef struct s_push{
	int		err;
	int		*original;
	t_stack	*a;
	t_stack	*b;
	t_nums	minor_now;
	int		count_element_a;
	int		count_element_b;
	int		pivot;
	int		moves_count;
}	t_push;

// init
t_stack	*new_stack_element(char **argv, int i, int istop);
int		add_in_end_element(t_push *stack, t_stack *new, int i);
void	quick_sort(int arr[], int low, int high);
int		verify_duplicates(t_push *stack, int argc);
int		init_stacks(t_push *stack, int argc, char **argv);

// algo G
void	push_swap(t_push *stack, int size, t_stack *now, t_bool rr);
void	move(int moves, t_push *stack, void (*r)(t_push *),
			void (*rr)(t_push *));
void	finishing_swap(t_push *stack, int low, int high, t_bool first);
int		find_pivot(t_stack *stack, int size);
int		error_message(char *str);
void	free_all(t_push *stack);
int		partition_chunks(t_push *stack, t_stack *changes, int a, int moves);
void	insertion(t_push *stack, int size, int size_b);
void	new_values(t_nums move, int *low, int *high);
void	finishing(t_bool first, t_push *stack, int *low, int *high);

// algo M
void	medium_push_swap(t_push *stack);
void	mini_push_swap(t_push *stack, int size);
t_bool	verify_mini_order(t_stack *stack, int size);
int		verify_chunks(t_push *stack, t_stack *now, int size);

// utils
t_nums	find_smaller(t_stack *tmp, int low, int high);
t_nums	find_greater(t_stack *tmp, int low, int high);
int		abs_x(int x);
t_bool	verify_ordination(t_push *stack, t_stack *tmp);

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