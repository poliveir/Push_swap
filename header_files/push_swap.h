/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 21:38:02 by poliveir          #+#    #+#             */
/*   Updated: 2021/07/15 14:02:11 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

int		fill_stack(int size, char **argv, t_list **stack_a);

/* Utilities */

int		all_digits(const char *s);

void	show_lists(t_list **stack_a, t_list **stack_b);

/* Sorting Commands */

/* Swap */

void	swap(t_list **stack);

void	sa(t_list **stack_a);

void	sb(t_list **stack_b);

void	ss(t_list **stack_a, t_list **stack_b);

/* Push */

void	push(t_list **stack_src, t_list **stack_dst);

void	pa(t_list **stack_a, t_list **stack_b);

void	pb(t_list **stack_a, t_list **stack_b);

/* Rotate */

void	rotate(t_list **stack);

void	ra(t_list **stack_a);

void	rb(t_list **stack_b);

void	rr(t_list **stack_a, t_list **stack_b);

/* Reverse_Rotate */

void	reverse_rotate(t_list **stack);

void	rra(t_list **stack_a);

void	rrb(t_list **stack_b);

void	rrr(t_list **stack_a, t_list **stack_b);

/* Sorting Operations */

int		sorted(t_list **stack);

int		sort_stack(t_list **stack_a, t_list **stack_b, int lst_size);

void	top_a(t_list **stack_a, int lst_size, int index);

void	top_b(t_list **stack_b, int lst_size, int index);

int		*min(t_list **stack);

int		*max(t_list **stack);

int		find_i(t_list **stack, void *content);

void	indexation(t_list **stack_a);

void	parts_to_b(t_list **a, t_list **b, int lst_size, int parts);

#endif
