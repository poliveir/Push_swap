/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:06:31 by poliveir          #+#    #+#             */
/*   Updated: 2021/07/15 14:06:41 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

/*
Find the index of a certain value
*/

int	find_i(t_list **stack, void *content)
{
	t_list	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp->next)
	{
		if (*(int *)temp->content == *(int *)content)
			return (i);
		i++;
		temp = temp->next;
	}
	return (i);
}

/*
Checks what is the best route to find the value under the index passed as argument
Best route means the route that requires less moves to get the value wanted to the top of the stack_a
*/

static int	find_best(t_list **stack_a, int lst_size, int index)
{
	t_list	*start;
	t_list	*end;
	t_list	*end_temp;
	int		start_index;

	start = *stack_a;
	end = *stack_a;
	start_index = 0;
	while (start->index > index && start)
	{
		start = start->next;
		start_index++;
	}
	end_temp = NULL;
	while (end)
	{
		if (end->index < index)
			end_temp = end;
		end = end->next;
	}
	if (start_index <= ((lst_size - 1) - find_i(stack_a, end_temp->content)))
		return (start_index);
	else
		return (find_i(stack_a, end_temp->content));
}

/*
Partition the stack_a into 4 quarters. Each quarter is equal to lst_size / 4.
Send 3/4 to b, with the minimum operations possible.
*/

void	parts_to_b(t_list **a, t_list **b, int lst_size, int parts)
{
	int	i;
	int	j;
	int	qtr;
	int	size;

	i = 0;
	qtr = lst_size / parts;
	size = lst_size;
	while (i < parts - 1)
	{
		j = 0;
		while (j < (lst_size / parts))
		{
			top_a(a, size, find_best(a, size, qtr));
			if (max(b) && (*(int *)(*a)->content > *max(b)
				|| *(int *)(*a)->content == *max(b) - 1))
				top_b(b, ft_lstsize(*b), find_i(b, max(b)));
			size--;
			pb(a, b);
			j++;
		}
		qtr += lst_size / parts;
		i++;
	}
}

/*
Resets the stack->index value to 0
*/

static void	reset_index(t_list **stack_a)
{
	t_list	*temp;

	temp = *stack_a;
	while (temp)
	{
		temp->index = 0;
		temp = temp->next;
	}
}

/*
Assigns the real index value to each node, the index of the final sorted list
*/

void	indexation(t_list **stack_a)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *stack_a;
	reset_index(stack_a);
	while (temp)
	{
		temp2 = *stack_a;
		while (temp2)
		{
			if (*(int *)temp->content > *(int *)temp2->content)
				temp->index++;
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}
