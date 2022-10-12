/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_sa_sb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awooden <awooden@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:27:14 by awooden           #+#    #+#             */
/*   Updated: 2022/03/14 16:32:43 by awooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_rra(t_list **a_stack)
{
	t_list	*tmp;

	if (a_stack == NULL || *a_stack == NULL || (*a_stack)->next == NULL)
		return ;
	tmp = *a_stack;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = *a_stack;
	*a_stack = tmp->next;
	tmp->next = NULL;
	write(1, "rra\n", 4);
}

void	exec_rrb(t_list **b_stack)
{
	t_list	*tmp;

	if (b_stack == NULL || *b_stack == NULL || (*b_stack)->next == NULL)
		return ;
	tmp = *b_stack;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = *b_stack;
	*b_stack = tmp->next;
	tmp->next = NULL;
	write(1, "rrb\n", 4);
}

void	exec_sa(t_list **a_stack)
{
	t_list	*tmp;

	if (a_stack == NULL || *a_stack == NULL || (*a_stack)->next == NULL)
		return ;
	tmp = *a_stack;
	(*a_stack) = (*a_stack)->next;
	tmp->next = (*a_stack)->next;
	(*a_stack)->next = tmp;
	write(1, "sa\n", 3);
}

void	exec_sb(t_list **b_stack)
{
	t_list	*tmp;

	if (b_stack == NULL || *b_stack == NULL || (*b_stack)->next == NULL)
		return ;
	tmp = *b_stack;
	(*b_stack) = (*b_stack)->next;
	tmp->next = (*b_stack)->next;
	(*b_stack)->next = tmp;
	write(1, "sb\n", 3);
}
