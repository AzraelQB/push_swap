/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awooden <awooden@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:17:37 by awooden           #+#    #+#             */
/*   Updated: 2022/03/14 20:19:56 by awooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstcopy(t_list *alist)
{
	t_list	*res;
	t_list	*tmp;

	res = NULL;
	while (alist)
	{
		ft_lstadd_back(&res, ft_lstnew(alist->content));
		alist = alist->next;
	}
	tmp = res;
	while (tmp != NULL)
	{
		tmp->index = lst_indexate(res, tmp->content);
		tmp = tmp->next;
	}
	return (res);
}

int	ft_chars_sorted(char **argv)
{
	while (*(argv + 1))
	{
		if (ft_atoi(*argv) >= ft_atoi(*(argv + 1)))
			return (0);
		argv++;
	}
	return (1);
}
