/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:11:12 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/27 17:40:45 by llima-ce         ###   ########.fr       */
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

typedef struct s_push{
	int		err;
	int		*original;
	t_stack	*A;
	t_stack	*B;
	int		count_element_A;
	int		count_element_B;
	t_nums	minor_end;
	t_nums	minor_start;
}	t_push;

int		push_swap(t_push *stack);

int		init_stacks(t_push *stack, int argc, char **argv);
int		print_linked_list(t_stack *stack);
int		error_message(char *str);
t_stack	*new_stack_element(char **argv ,int i, int istop);
int		add_in_end_element(t_push *stack, t_stack *new, int i);
void	quickSort(int arr[], int low, int high);
int		verify_duplicates(t_push *stack, int argc);
void	split_chunk(t_push *stack);
void	init_nums(t_push *stack);
int		find_small_b(t_push *stack, t_stack *tmp);
void	finishing_swap(t_push *stack);
void	move(int moves, t_push *stack, void (*r)(t_push *),
	void (*rr)(t_push *));

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