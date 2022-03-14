/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <luizlcezario@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:11:12 by llima-ce          #+#    #+#             */
/*   Updated: 2022/03/14 18:08:30 by llima-ce         ###   ########.fr       */
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
	t_stack *initial;
	int	max;
	int size;
}	t_chunck;

typedef struct s_push{
	int		err;
	int		*original;
	t_stack	*A;
	t_stack	*B;
	t_nums minor_now;
	int		count_element_A;
	int		count_element_B;
	int		pivot;
}	t_push;

int push_swap(t_push *stack, int size, t_stack *now, t_bool rr);

int		init_stacks(t_push *stack, int argc, char **argv);
int		print_linked_list(t_stack *stack);
int		error_message(char *str);
t_stack	*new_stack_element(char **argv ,int i, int istop);
int		add_in_end_element(t_push *stack, t_stack *new, int i);
void	quickSort(int arr[], int low, int high);
int		verify_duplicates(t_push *stack, int argc);
void	split_chunk(t_push *stack);
int		finishing_swap(t_push *stack,t_stack *order, int low, int high);
void	move(int moves, t_push *stack, void (*r)(t_push *),
	void (*rr)(t_push *));
	
t_nums	find_smaller(t_stack *tmp, int low, int high);
t_nums	find_greater(t_stack *tmp, int low, int high);


// new

int		finishing_swap(t_push *stack, t_stack *order, int low, int high);
t_bool	verify_ordination(t_push *stack,t_stack *tmp);
int		find_pivot(t_stack *stack , int size);
void	mini_push_swap(t_push *stack, int size);
void	choose_direction(int moves, t_push *stack, int total, char type);
int		verify_chunks(t_push *stack, t_stack *now, int size);

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