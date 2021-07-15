/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:11:01 by poliveir          #+#    #+#             */
/*   Updated: 2021/07/15 14:06:19 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

/*
Find and return the minimum value of the stack
*/

int	*min(t_list **stack)
{
	t_list	*temp;
	int		*min_value;

	temp = *stack;
	min_value = (int *)temp->content;
	temp = temp->next;
	while (temp)
	{
		if (*min_value > *(int *)temp->content)
			min_value = (int *)temp->content;
		temp = temp->next;
	}
	return (min_value);
}

/*
Find and return the maximum value of the stack
*/

int	*max(t_list **stack)
{
	t_list	*temp;
	int		*max_value;

	if (!(*stack))
		return (NULL);
	temp = *stack;
	max_value = (int *)temp->content;
	temp = temp->next;
	while (temp)
	{
		if (*max_value < *(int *)temp->content)
			max_value = (int *)temp->content;
		temp = temp->next;
	}
	return (max_value);
}

/*
Get an element to the top of the stack A, by it's index
*/

void	top_a(t_list **stack_a, int lst_size, int index)
{
	while (index && (index < lst_size))
	{
		if (index <= lst_size / 2)
		{
			ra(stack_a);
			index--;
		}
		else
		{
			rra(stack_a);
			index++;
		}
	}
}

/*
Get an element to the top of the stack B, by it's index
*/

void	top_b(t_list **stack_b, int lst_size, int index)
{
	while (index && (index < lst_size))
	{
		if (index == 1)
		{
			sb(stack_b);
			return ;
		}
		if (index <= (lst_size / 2))
		{
			rb(stack_b);
			index--;
		}
		else
		{
			rrb(stack_b);
			index++;
		}
	}
}
