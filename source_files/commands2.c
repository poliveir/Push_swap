/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:09:59 by poliveir          #+#    #+#             */
/*   Updated: 2021/07/15 14:04:06 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}
