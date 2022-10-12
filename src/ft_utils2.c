/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awooden <awooden@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:27:25 by awooden           #+#    #+#             */
/*   Updated: 2022/03/14 20:17:49 by awooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (elem == NULL)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

int	ft_lstsize(t_list *lst)
{
	int		res;
	t_list	*tmp;

	res = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		res++;
		tmp = tmp->next;
	}
	return (res);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_lstfree(t_list **alist)
{
	t_list	*cur;

	if (!(*alist))
		return ;
	while ((*alist)->next)
	{
		cur = (*alist)->next;
		free((*alist));
		(*alist) = cur;
	}
	free(*alist);
}
