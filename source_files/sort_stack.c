/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:10:46 by poliveir          #+#    #+#             */
/*   Updated: 2021/07/18 13:32:12 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

static void	sort_stack_3(t_list **stack_a)
{
	if (*(int *)((*stack_a)->content) > *(int *)((*stack_a)->next->content))
	{
		if (*(int *)((*stack_a)->content) >
		*(int *)((*stack_a)->next->next->content))
		{
			ra(stack_a);
			if (*(int *)((*stack_a)->content) >
			 *(int *)((*stack_a)->next->content))
				sa(stack_a);
		}
		else
			sa(stack_a);
	}
	else
	{
		rra(stack_a);
		if (*(int *)((*stack_a)->content) > *(int *)((*stack_a)->next->content))
			sa(stack_a);
	}
}

static void	sort_stack_5(t_list **stack_a, t_list **stack_b, int lst_size)
{
	int		size;

	size = lst_size;
	while (lst_size > 3)
	{
		top_a(stack_a, lst_size, find_i(stack_a, min(stack_a)));
		if (sorted(stack_a))
		{
			if (lst_size == 4 && size == 5)
				pa(stack_a, stack_b);
			return ;
		}
		pb(stack_a, stack_b);
		lst_size--;
	}
	if (!sorted(stack_a))
		sort_stack_3(stack_a);
	while (size-- > 3)
		pa(stack_a, stack_b);
}

static void	sort_small_stack(t_list **stack_a, t_list **stack_b, int lst_size)
{
	int	size;

	size = lst_size;
	while (size > 5 && !sorted(stack_a))
	{
		top_a(stack_a, size, find_i(stack_a, min(stack_a)));
		pb(stack_a, stack_b);
		size--;
	}
	if (!sorted(stack_a))
		sort_stack_5(stack_a, stack_b, size);
	while (lst_size - size)
	{
		pa(stack_a, stack_b);
		size++;
	}
}

static void	sort_large_stack(t_list **stack_a, t_list **stack_b, int lst_size)
{
	int	parts;
	int	r;

	if (lst_size <= 100)
		parts = 5;
	else
		parts = 11;
	r = (lst_size / parts) / 2;
	parts_to_b(stack_a, stack_b, lst_size, parts);
	while (ft_lstsize(*stack_a) > 5 && !sorted(stack_a))
	{
		top_a(stack_a, ft_lstsize(*stack_a), find_i(stack_a, min(stack_a)));
		if (max(stack_b) && (*(int *)(*stack_a)->content > *max(stack_b) - r))
			top_b(stack_b, ft_lstsize(*stack_b), find_i(stack_b, max(stack_b)));
		pb(stack_a, stack_b);
	}
	if (!sorted(stack_a))
		sort_stack_5(stack_a, stack_b, ft_lstsize(*stack_a));
	while (*stack_b)
	{
		top_b(stack_b, ft_lstsize(*stack_b), find_i(stack_b, max(stack_b)));
		pa(stack_a, stack_b);
	}
}

int	sort_stack(t_list **stack_a, t_list **stack_b, int lst_size)
{
	if (lst_size == 2)
		sa(stack_a);
	else if (lst_size == 3)
		sort_stack_3(stack_a);
	else if (lst_size <= 5)
		sort_stack_5(stack_a, stack_b, lst_size);
	else if (lst_size <= 10)
		sort_small_stack(stack_a, stack_b, lst_size);
	else
	{
		indexation(stack_a);
		sort_large_stack(stack_a, stack_b, lst_size);
	}
	if (sorted(stack_a))
		return (1);
	return (0);
}
