/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_ra_rb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awooden <awooden@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:45:20 by awooden           #+#    #+#             */
/*   Updated: 2022/03/14 16:27:56 by awooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_pb(t_list **a_stack, t_list **b_stack)
{
	t_list	*tmp;

	if (a_stack == NULL || *a_stack == NULL)
		return ;
	tmp = *a_stack;
	*a_stack = (*a_stack)->next;
	tmp->next = *b_stack;
	*b_stack = tmp;
	write(1, "pb\n", 3);
}

void	exec_pa(t_list **a_stack, t_list **b_stack)
{
	t_list	*tmp;

	if (b_stack == NULL || *b_stack == NULL)
		return ;
	tmp = *b_stack;
	*b_stack = (*b_stack)->next;
	tmp->next = *a_stack;
	*a_stack = tmp;
	write(1, "pa\n", 3);
}

void	exec_ra(t_list **a_stack)
{
	t_list	*tmp;

	if (a_stack == NULL || *a_stack == NULL || (*a_stack)->next == NULL)
		return ;
	tmp = *a_stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *a_stack;
	*a_stack = (*a_stack)->next;
	tmp->next->next = NULL;
	write(1, "ra\n", 3);
}

void	exec_rb(t_list **b_stack)
{
	t_list	*tmp;

	if (b_stack == NULL || *b_stack == NULL || (*b_stack)->next == NULL)
		return ;
	tmp = *b_stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *b_stack;
	*b_stack = (*b_stack)->next;
	tmp->next->next = NULL;
	write(1, "rb\n", 3);
}
