/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:20:03 by poliveir          #+#    #+#             */
/*   Updated: 2021/07/15 14:03:37 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_files/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	if (!fill_stack(argc - 1, argv + 1, &a))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (!sorted(&a))
		if (!sort_stack(&a, &b, argc - 1))
			ft_putstr_fd("Error\n", 2);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
