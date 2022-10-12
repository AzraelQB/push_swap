/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awooden <awooden@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:27:29 by awooden           #+#    #+#             */
/*   Updated: 2022/03/14 19:16:30 by awooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_elem(t_list **astack, int elem_pos, int stack_size, char st)
{
	if (elem_pos <= stack_size / 2)
	{
		while (elem_pos-- > 0)
		{
			if (st == 'a')
				exec_ra(astack);
			else
				exec_rb(astack);
		}
	}
	else
	{
		while (elem_pos++ < stack_size)
		{
			if (st == 'a')
				exec_rra(astack);
			else
				exec_rrb(astack);
		}		
	}
}

int	get_back_pos_b(t_list *astack, int stack_size)
{
	t_list	*cur;
	int		res;

	res = 1;
	cur = ft_lstlast(astack);
	while (cur->index < stack_size - 1)
	{
		res++;
		cur = astack;
		while (cur->next->next)
			cur = cur->next;
		free(cur->next);
		cur->next = NULL;
		cur = ft_lstlast(astack);
	}
	return (res);
}

int	get_elem_pos_b(t_list *astack, int stack_size)
{
	t_list	*cur;
	int		forw_pos;
	int		back_pos;

	forw_pos = 0;
	astack = ft_lstcopy(astack);
	cur = astack;
	while (cur->index < stack_size - 1)
	{
		forw_pos++;
		cur = cur->next;
	}
	back_pos = get_back_pos_b(astack, stack_size);
	ft_lstfree(&astack);
	if (forw_pos <= back_pos)
		return (forw_pos);
	return (stack_size - back_pos);
}

int	get_back_pos_a(t_list *astack, int freedom_ind)
{
	t_list	*cur;
	int		res;

	res = 1;
	cur = ft_lstlast(astack);
	while (cur->index > freedom_ind)
	{
		res++;
		cur = astack;
		while (cur->next->next)
			cur = cur->next;
		free(cur->next);
		cur->next = NULL;
		cur = ft_lstlast(astack);
	}
	return (res);
}

int	get_elem_pos_a(t_list *astack, int freedom_ind, int stack_size)
{
	t_list	*cur;
	int		forw_pos;
	int		back_pos;

	forw_pos = 0;
	astack = ft_lstcopy(astack);
	cur = astack;
	while (cur->index > freedom_ind)
	{
		forw_pos++;
		cur = cur->next;
	}
	back_pos = get_back_pos_a(astack, freedom_ind);
	ft_lstfree(&astack);
	if (forw_pos <= back_pos)
		return (forw_pos);
	return (stack_size - back_pos);
}
