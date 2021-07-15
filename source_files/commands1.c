/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:09:43 by poliveir          #+#    #+#             */
/*   Updated: 2021/07/15 14:03:54 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

void	sa(t_list **stack_a)
{
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
