/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 21:54:13 by poliveir          #+#    #+#             */
/*   Updated: 2021/07/15 14:04:56 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

void	swap(t_list **stack)
{
	t_list	*node_1;
	t_list	*node_2;

	if (!(*stack) || !((*stack)->next))
		return ;
	node_1 = *stack;
	node_2 = node_1->next;
	node_1->next = node_2->next;
	node_2->next = node_1;
	*stack = node_2;
}

void	push(t_list **stack_src, t_list **stack_dst)
{
	t_list	*top;

	if (!(*stack_src))
		return ;
	top = *stack_src;
	*stack_src = (*stack_src)->next;
	top->next = NULL;
	ft_lstadd_front(stack_dst, top);
}

void	rotate(t_list **stack)
{
	t_list	*top;

	if (!(*stack) || !((*stack)->next))
		return ;
	top = *stack;
	*stack = top->next;
	top->next = NULL;
	ft_lstadd_back(stack, top);
}

void	reverse_rotate(t_list **stack)
{
	t_list	*bot;
	t_list	*temp;

	if (!(*stack) || !((*stack)->next))
		return ;
	temp = *stack;
	bot = *stack;
	bot = ft_lstlast(bot);
	while (temp->next->next)
		temp = temp->next;
	temp->next = NULL;
	ft_lstadd_front(stack, bot);
}
