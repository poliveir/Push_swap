/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:10:25 by poliveir          #+#    #+#             */
/*   Updated: 2021/07/15 14:04:34 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

/*
Checks if the argument is a number. If not it echo -ns "ERROR" on stderr.
Only accepted formats are:
	nbr -> 123
	nbr -> -123
The number '0' should not have a '-' sign before it
and should not repeat itself: EXAMPLE -> ("00")
*/

static int	nbr_check(char *argv)
{
	if (*argv == '-')
	{
		argv++;
		if (*argv == '0' || *argv == '\0')
			return (0);
	}
	if (*argv == '0' && ft_isdigit(*(argv + 1)))
		return (0);
	if (all_digits(argv))
		return (1);
	return (0);
}

/*
Firstly, checks if the argument is a number, by calling nbr_check() function
and, then, checks if the argument belongs to the integer value range
*/

static int	int_check(char *argv)
{
	long	nbr;

	if (!nbr_check(argv))
		return (0);
	nbr = ft_atol(argv);
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (0);
	return (1);
}

/*
Checks if there are any duplicates in stack_a
*/

static int	dup_check(t_list *stack)
{
	t_list	*temp;
	t_list	*temp2;

	temp = stack;
	while (temp->next)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (*(int *)temp2->content == *(int *)temp->content)
				return (0);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (1);
}

/*
Checks all rules for a valid input:
- Must be a number;
- Must be in integer range;
After all is checked, fills stack_a with the value of the arguments of the stdin
and checks to see if there are any duplicate numbers on the stack
*/

int	fill_stack(int size, char **argv, t_list **stack)
{
	int		*nbr;

	while (size)
	{
		if (!int_check(*argv))
			return (0);
		nbr = (int *)malloc(sizeof(int));
		if (!nbr)
		{
			ft_lstclear(stack, free);
			return (0);
		}
		*nbr = ft_atoi(*argv++);
		ft_lstadd_back(stack, ft_lstnew(nbr));
		size--;
	}
	if (!dup_check(*stack))
	{
		ft_lstclear(stack, free);
		return (0);
	}
	return (1);
}
