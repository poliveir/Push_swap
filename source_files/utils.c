/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:11:07 by poliveir          #+#    #+#             */
/*   Updated: 2021/07/15 14:11:29 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

/*
Checks if the stack is sorted
*/

int	sorted(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	if (!temp)
		return (0);
	if (!temp->next)
		return (1);
	while (temp->next)
	{
		if (*(int *)temp->content > *(int *)temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

/*
Checks if a string is composed of only digits
*/

int	all_digits(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		if (!ft_isdigit(s[i++]))
			return (0);
	return (1);
}
